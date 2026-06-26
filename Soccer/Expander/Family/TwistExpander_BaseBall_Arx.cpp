#include "TwistExpander_BaseBall_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_BaseBall_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xD4E4F760C4A6902BULL + 0xF2537A29EAE2C5F1ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xFE77CB3CC8D8E34BULL + 0xA5B1E80DA7FA3C6CULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xB532370C3A8CCFBDULL + 0xA69037AAACC86192ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xFA1BE5D151E29D77ULL + 0x8009988F58599329ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xE4BD05C8621B3EE7ULL + 0x92A5847716B4AE3BULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xAEB761277B42322FULL + 0x82A63040EE23AAB2ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xCF437B24E1C1362BULL + 0xA562EFA73FCAC23DULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xBA9F88214D38AA99ULL + 0xD49D99B84A1EAC50ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xC21894FFEB04E58BULL + 0xA689343DA69194C1ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xBDC32A996CB2CAF5ULL + 0xA9FADE3C87D211ACULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xEB9F703C4AB173ABULL + 0xDB2FB7AA5EEFF02AULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x8EA83AFFBC6D7C55ULL + 0x8BB7FB3FBD56A25AULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xB4CFEF91458FB3FFULL + 0xCF00BFCCDD9D043AULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xD79118A5915ABC23ULL + 0x8264FC845328E220ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x94F4CF7D827B5903ULL + 0xFDE665F97E246084ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xEFD5BDBF979A8BF3ULL + 0xD2B3BE0AA91CC9E1ULL);
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
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 5284U)) & S_BLOCK1], 5U) ^ RotL64(pSnow[((aIndex + 204U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 374U)) & S_BLOCK1], 3U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 2713U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 11U) + RotL64(aIngress, 29U)) + (RotL64(aPrevious, 43U) ^ RotL64(aCross, 56U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererH + RotL64(aScatter, 19U)) + 18255347001097480328U;
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 36U)) + 13679246790311505735U) + aOrbiterAssignSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = ((aWandererC + RotL64(aCross, 3U)) + RotL64(aCarry, 51U)) + 10565839529765027116U;
            aOrbiterH = (aWandererB + RotL64(aIngress, 21U)) + 14327172566224769901U;
            aOrbiterC = (aWandererI + RotL64(aCross, 53U)) + 16239024612038195174U;
            aOrbiterA = (((aWandererG + RotL64(aIngress, 38U)) + RotL64(aCarry, 23U)) + 13800012174212131890U) + aNonceWordN;
            aOrbiterJ = (aWandererD + RotL64(aPrevious, 13U)) + 13900288860157577583U;
            aOrbiterD = ((aWandererA + RotL64(aScatter, 47U)) + 4144386119777112740U) + aNonceWordK;
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 27U)) + 3154558262670631372U) + aOrbiterAssignSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterB = ((aWandererF + RotL64(aScatter, 51U)) + RotL64(aCarry, 43U)) + 7456728543137614001U;
            aOrbiterG = (aWandererJ + RotL64(aIngress, 43U)) + 11709519851158935384U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 15607438907832240304U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 9276575329661725624U;
            aOrbiterK = RotL64((aOrbiterK * 8879744070762412745U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 6459435969129449226U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 6442382118416542275U;
            aOrbiterA = RotL64((aOrbiterA * 2921027306686588233U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 12117432107282150865U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 6831279293184793243U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2435360641135249073U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 9520022957804572889U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 8322178689474588679U) ^ aOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1627707191467537115U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 4162401591586869316U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 8994015844714895961U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15421910378057951895U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 10038095909727959633U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 17756404450592957616U;
            aOrbiterE = RotL64((aOrbiterE * 14255952184627347295U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 3379089265413427719U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 11341713098678108441U;
            aOrbiterG = RotL64((aOrbiterG * 2500587373161411961U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 4030296130743454165U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 6332387792111212064U;
            aOrbiterF = RotL64((aOrbiterF * 16490982218150897861U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 14893209417387662133U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 9265457389326311687U) ^ aNonceWordC;
            aOrbiterC = RotL64((aOrbiterC * 9778404505547862689U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 13496086915199406901U) + aNonceWordD;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 14576555328710787951U;
            aOrbiterD = RotL64((aOrbiterD * 13155395071667672943U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 11482324648071976743U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 18255347001097480328U;
            aOrbiterB = RotL64((aOrbiterB * 10918514878283385643U), 5U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterC, 53U);
            aIngress = aIngress + (RotL64(aOrbiterF, 51U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterE, 4U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 19U));
            aIngress = aIngress + RotL64(aOrbiterD, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aPrevious, 21U) + aOrbiterB) + RotL64(aOrbiterI, 6U)) + aWandererUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterH, 35U)) + aOrbiterD);
            aWandererC = aWandererC + (((RotL64(aScatter, 50U) + RotL64(aOrbiterG, 27U)) + aOrbiterE) + aWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 47U) + aOrbiterC) + RotL64(aOrbiterB, 47U));
            aWandererH = aWandererH + (((RotL64(aCross, 41U) + aOrbiterA) + RotL64(aOrbiterB, 19U)) + aNonceWordE);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 43U) + aOrbiterB) + RotL64(aOrbiterK, 60U));
            aWandererD = aWandererD + ((RotL64(aScatter, 37U) + aOrbiterD) + RotL64(aOrbiterK, 39U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 27U) + aOrbiterK) + RotL64(aOrbiterA, 13U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 13U) + aOrbiterH) + RotL64(aOrbiterE, 51U)) + RotL64(aCarry, 27U)) + aNonceWordG);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 10U) + RotL64(aOrbiterD, 29U)) + aOrbiterJ);
            aWandererE = aWandererE + (((RotL64(aPrevious, 57U) + aOrbiterF) + RotL64(aOrbiterA, 41U)) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 46U) ^ aWandererB);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 19U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 40U));
            aCarry = aCarry + RotL64(aWandererF, 51U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordF);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10855U)) & S_BLOCK1], 18U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 8942U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(pSnow[((S_BLOCK1 - aIndex + 10734U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((aIndex + 8772U)) & S_BLOCK1], 44U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aPrevious, 13U)) ^ (RotL64(aIngress, 27U) + RotL64(aCross, 42U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 43U)) + 2101601659597850213U) + aNonceWordA;
            aOrbiterB = (aWandererA + RotL64(aCross, 41U)) + 2759794072560720121U;
            aOrbiterH = (aWandererJ + RotL64(aIngress, 29U)) + 9443562552411269339U;
            aOrbiterI = (((aWandererK + RotL64(aScatter, 51U)) + RotL64(aCarry, 29U)) + 10801360546699857975U) + aOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = (aWandererG + RotL64(aIngress, 26U)) + 8020716394829332019U;
            aOrbiterK = (aWandererI + RotL64(aScatter, 57U)) + 1021894212367773801U;
            aOrbiterF = (aWandererC + RotL64(aPrevious, 23U)) + 13346855534622490176U;
            aOrbiterJ = (((aWandererH + RotL64(aCross, 11U)) + RotL64(aCarry, 51U)) + 16359309548462953836U) + aNonceWordF;
            aOrbiterE = ((aWandererE + RotL64(aScatter, 6U)) + 12642446944680783519U) + aOrbiterAssignSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterG = ((aWandererF + RotL64(aIngress, 53U)) + 8197424982767553380U) + aNonceWordB;
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 39U)) + RotL64(aCarry, 11U)) + 14346334610901859094U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 14171304260534233539U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 334531601308283605U;
            aOrbiterH = RotL64((aOrbiterH * 5012968232749075075U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 10707856298471572695U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 18364775750091914766U;
            aOrbiterB = RotL64((aOrbiterB * 15735143943129143265U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 8531394793118363836U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 15352876929406908882U;
            aOrbiterD = RotL64((aOrbiterD * 475199047053777179U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 567682016232278157U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 2068146551757663119U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1557877740957797555U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 7776122587613256525U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 16430938890724272256U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4540270493783593257U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 11912000645055436094U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 16800749242578741498U;
            aOrbiterA = RotL64((aOrbiterA * 17804584625034241737U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 5909199180260499150U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 5751089915336865588U;
            aOrbiterI = RotL64((aOrbiterI * 15376689503142397927U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 3478216857728853008U) + aNonceWordG;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 18007567146937338241U) ^ aNonceWordO;
            aOrbiterK = RotL64((aOrbiterK * 6620498877303917855U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 17454259424163653490U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 6276120962018305311U;
            aOrbiterJ = RotL64((aOrbiterJ * 7560618224285018801U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 3839336239901666431U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 6230149015045237670U) ^ aNonceWordK;
            aOrbiterG = RotL64((aOrbiterG * 1838983748994340883U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 17552095486612766544U) + aOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 2101601659597850213U;
            aOrbiterC = RotL64((aOrbiterC * 2915330118061857271U), 29U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterK, 53U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 39U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 37U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 34U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 19U));
            aIngress = aIngress + RotL64(aOrbiterC, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aScatter, 43U) + RotL64(aOrbiterG, 26U)) + aOrbiterA) + RotL64(aCarry, 5U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterE, 3U)) + aOrbiterK);
            aWandererJ = aWandererJ + (((RotL64(aCross, 53U) + aOrbiterC) + RotL64(aOrbiterH, 13U)) + aNonceWordN);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 60U) + RotL64(aOrbiterA, 57U)) + aOrbiterD) + aWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 39U) + aOrbiterK) + RotL64(aOrbiterB, 29U)) + aWandererUpdateSaltC[((aIndex + 8U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 57U) + aOrbiterI) + RotL64(aOrbiterA, 5U));
            aWandererD = aWandererD + ((RotL64(aScatter, 51U) + RotL64(aOrbiterI, 40U)) + aOrbiterC);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 11U) + aOrbiterE) + RotL64(aOrbiterF, 43U));
            aWandererH = aWandererH + ((RotL64(aCross, 41U) + RotL64(aOrbiterK, 11U)) + aOrbiterD);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 34U) + RotL64(aOrbiterD, 51U)) + aOrbiterJ);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterB, 37U)) + aOrbiterH) + RotL64(aCarry, 13U)) + aNonceWordC);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 14U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererI, 5U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererG, 3U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ aNonceWordE;
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 14612U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((aIndex + 11458U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 15559U)) & S_BLOCK1], 29U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 15218U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 37U) ^ RotL64(aCross, 18U)) + (RotL64(aCarry, 5U) ^ RotL64(aIngress, 57U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (((aWandererG + RotL64(aIngress, 19U)) + 1952750591494698524U) + aOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordG;
            aOrbiterA = ((aWandererH + RotL64(aCross, 13U)) + RotL64(aCarry, 37U)) + 4488270851303332830U;
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 11U)) + 2738763375328927635U) + aOrbiterAssignSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = (aWandererD + RotL64(aScatter, 21U)) + 6728843649480454340U;
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 5U)) + RotL64(aCarry, 13U)) + 10490717875258865358U;
            aOrbiterC = (aWandererI + RotL64(aCross, 34U)) + 1429288737812910205U;
            aOrbiterI = (aWandererE + RotL64(aScatter, 41U)) + 2761375016998907636U;
            aOrbiterG = (aWandererK + RotL64(aIngress, 39U)) + 1088988605204499835U;
            aOrbiterK = ((aWandererA + RotL64(aCross, 57U)) + 6829840407300289709U) + aNonceWordC;
            aOrbiterD = (aWandererC + RotL64(aPrevious, 24U)) + 9267240337867690471U;
            aOrbiterE = (((aWandererJ + RotL64(aIngress, 51U)) + RotL64(aCarry, 51U)) + 8120113021183975703U) + aNonceWordD;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 1340980511302566784U) + aOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 11874452169979878835U) ^ aOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8638486178860092537U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 1872314794140971426U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 6013952618696225751U;
            aOrbiterC = RotL64((aOrbiterC * 7994863587373565715U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 3644011378086236002U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 8501867691997891731U;
            aOrbiterA = RotL64((aOrbiterA * 7115282675461711509U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 2493546555198066143U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 5179240189571799179U;
            aOrbiterB = RotL64((aOrbiterB * 1267579130962756135U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 11273348247858394197U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 4577476419423118925U;
            aOrbiterG = RotL64((aOrbiterG * 8427261005061162673U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 6201955123046621919U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 3930651302557530185U;
            aOrbiterD = RotL64((aOrbiterD * 1563512534463027965U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 7571426325227856019U) + aNonceWordM;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 11098508505512361002U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9229352429618815089U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 6154830144380484305U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 4282054616147137364U;
            aOrbiterH = RotL64((aOrbiterH * 14984813139796280171U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 14818120999774989697U) + aNonceWordE;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 12174471855744785761U;
            aOrbiterI = RotL64((aOrbiterI * 3061488029278974095U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 3117297607579915182U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 2979217539186455309U;
            aOrbiterK = RotL64((aOrbiterK * 12235308335184626143U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 824986728082249286U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 1952750591494698524U;
            aOrbiterE = RotL64((aOrbiterE * 10162288961171400541U), 13U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterE, 53U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 60U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 3U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 51U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 35U));
            aIngress = aIngress + RotL64(aOrbiterA, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 11U) + aOrbiterJ) + RotL64(aOrbiterC, 18U));
            aWandererB = aWandererB + ((RotL64(aScatter, 21U) + RotL64(aOrbiterI, 51U)) + aOrbiterG);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterD, 43U)) + aOrbiterA);
            aWandererI = aWandererI + (((RotL64(aCross, 19U) + RotL64(aOrbiterI, 21U)) + aOrbiterC) + RotL64(aCarry, 35U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 4U) + RotL64(aOrbiterE, 3U)) + aOrbiterF);
            aWandererC = aWandererC + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterF, 57U)) + aOrbiterD) + aNonceWordP);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 39U) + aOrbiterH) + RotL64(aOrbiterI, 29U));
            aWandererE = aWandererE + (((RotL64(aCross, 37U) + aOrbiterB) + RotL64(aOrbiterE, 39U)) + aWandererUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterC, 13U)) + aOrbiterD);
            aWandererH = aWandererH + (((RotL64(aIngress, 60U) + aOrbiterB) + RotL64(aOrbiterF, 60U)) + RotL64(aCarry, 57U));
            aWandererG = aWandererG ^ ((((RotL64(aCross, 51U) + RotL64(aOrbiterJ, 27U)) + aOrbiterK) + aNonceWordN) + aWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererI);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + (RotL64(aWandererG, 54U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 13U));
            aCarry = aCarry + RotL64(aWandererK, 41U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordM);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 19288U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20882U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17412U)) & S_BLOCK1], 19U) ^ RotL64(mSource[((aIndex + 19177U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 19U) + RotL64(aCross, 39U)) ^ (RotL64(aCarry, 56U) + RotL64(aPrevious, 5U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = ((aWandererI + RotL64(aCross, 53U)) + RotL64(aCarry, 11U)) + 3973833383430652211U;
            aOrbiterH = ((aWandererC + RotL64(aScatter, 5U)) + RotL64(aCarry, 27U)) + 5760227042747169187U;
            aOrbiterD = (aWandererB + RotL64(aPrevious, 37U)) + 4923009065139227286U;
            aOrbiterG = (aWandererF + RotL64(aIngress, 47U)) + 1477807307009107590U;
            aOrbiterI = (aWandererA + RotL64(aScatter, 30U)) + 5707194514329007301U;
            aOrbiterK = (aWandererK + RotL64(aPrevious, 19U)) + 5340439728375269724U;
            aOrbiterF = ((aWandererD + RotL64(aCross, 51U)) + 17080457898946572387U) + aOrbiterAssignSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = (((aWandererG + RotL64(aIngress, 21U)) + RotL64(aCarry, 35U)) + 281559150259472813U) + aNonceWordF;
            aOrbiterA = (aWandererE + RotL64(aPrevious, 35U)) + 16160633048230910560U;
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 43U)) + 9003989610509592121U) + aOrbiterAssignSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = (aWandererH + RotL64(aCross, 26U)) + 10579322462808454333U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 15059383289528723069U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 10417647757852880956U;
            aOrbiterD = RotL64((aOrbiterD * 1457919230286043137U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 14484665027393813330U) + aOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 12344463053485837974U;
            aOrbiterI = RotL64((aOrbiterI * 5762654194001525041U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 5826453246659297805U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 12547902286376986223U;
            aOrbiterK = RotL64((aOrbiterK * 2982850000322672789U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 9637855144278126174U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 2132744427444501938U;
            aOrbiterF = RotL64((aOrbiterF * 5911587798564836199U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 9248933938130311231U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 13274297928717090383U;
            aOrbiterE = RotL64((aOrbiterE * 2901398809555237563U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 3690262236918560930U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 3626005326410800344U;
            aOrbiterA = RotL64((aOrbiterA * 13030443356669355355U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 10801089744186148218U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 5446653082176311031U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4594267575901248321U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 3205541585889107366U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 4532327942368884436U;
            aOrbiterB = RotL64((aOrbiterB * 16287094987689326229U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 9755333481079721632U) + aNonceWordN;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 722154154363571049U;
            aOrbiterJ = RotL64((aOrbiterJ * 11002432494248958957U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 8071668483354405205U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 8770466248803121315U;
            aOrbiterH = RotL64((aOrbiterH * 12780438190628717807U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 1999251593502332271U) + aNonceWordJ;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 3973833383430652211U;
            aOrbiterG = RotL64((aOrbiterG * 5325244982474631559U), 11U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterG, 27U);
            aIngress = aIngress + (RotL64(aOrbiterA, 41U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterJ, 43U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 60U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 39U));
            aIngress = aIngress + RotL64(aOrbiterE, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aCross, 57U) + aOrbiterD) + RotL64(aOrbiterE, 36U)) + RotL64(aCarry, 23U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 44U) + aOrbiterH) + RotL64(aOrbiterF, 11U));
            aWandererI = aWandererI + (((RotL64(aIngress, 29U) + aOrbiterD) + RotL64(aOrbiterC, 5U)) + aWandererUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 41U) + aOrbiterF) + RotL64(aOrbiterD, 27U)) + aNonceWordO);
            aWandererB = aWandererB + (((RotL64(aIngress, 11U) + RotL64(aOrbiterF, 57U)) + aOrbiterK) + aWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 26U) + RotL64(aOrbiterG, 51U)) + aOrbiterF);
            aWandererA = aWandererA + ((RotL64(aScatter, 3U) + aOrbiterE) + RotL64(aOrbiterI, 41U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 35U) + aOrbiterA) + RotL64(aOrbiterI, 43U)) + aNonceWordH);
            aWandererC = aWandererC + (((RotL64(aCross, 23U) + RotL64(aOrbiterD, 20U)) + aOrbiterB) + aNonceWordI);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 5U) + aOrbiterE) + RotL64(aOrbiterJ, 39U));
            aWandererK = aWandererK + (((RotL64(aScatter, 51U) + RotL64(aOrbiterB, 23U)) + aOrbiterK) + RotL64(aCarry, 57U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + (RotL64(aWandererF, 21U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 12U));
            aCarry = aCarry + (RotL64(aWandererA, 37U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 39U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererG, 3U);
            aCarry = aCarry + RotL64(aIngress, 56U);
            aCarry = aCarry ^ aNonceWordK;
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 23247U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22109U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 23434U)) & S_BLOCK1], 52U) ^ RotL64(aWorkLaneA[((aIndex + 26131U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 6U) ^ RotL64(aIngress, 57U)) ^ (RotL64(aPrevious, 29U) + RotL64(aCross, 43U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (aWandererE + RotL64(aCross, 23U)) + 18144572925667544139U;
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 39U)) + 5659758077574059728U) + aNonceWordJ;
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 41U)) + RotL64(aCarry, 53U)) + 6343330616999166392U;
            aOrbiterD = ((aWandererK + RotL64(aIngress, 35U)) + 17754639838410839447U) + aOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = (aWandererB + RotL64(aPrevious, 18U)) + 9451843819849581729U;
            aOrbiterC = ((aWandererH + RotL64(aCross, 53U)) + RotL64(aCarry, 39U)) + 7957854457197462212U;
            aOrbiterH = (aWandererC + RotL64(aScatter, 43U)) + 1461994799722205010U;
            aOrbiterB = ((aWandererF + RotL64(aIngress, 47U)) + 18002214276252170177U) + aOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = (aWandererA + RotL64(aCross, 5U)) + 14689869073147027164U;
            aOrbiterE = (aWandererD + RotL64(aScatter, 58U)) + 3978104368003440293U;
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 27U)) + RotL64(aCarry, 21U)) + 8512135845221335386U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 1477533446382953439U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 2166717790929947990U) ^ aOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6538884492418324461U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 8082437060686606995U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 4363687722464700362U;
            aOrbiterC = RotL64((aOrbiterC * 7199165810993478887U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 15782763348014924206U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 8572509150015960728U;
            aOrbiterB = RotL64((aOrbiterB * 3340528604891897779U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 12248271773316742521U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 9602078627638561949U;
            aOrbiterE = RotL64((aOrbiterE * 1860631869877427405U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 17244849374768558859U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterJ) ^ 1030743048280579012U) ^ aOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterF = RotL64((aOrbiterF * 10858949914285817051U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 17722342363541914280U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 15667504059789880034U;
            aOrbiterD = RotL64((aOrbiterD * 15872269872168533709U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 12645332941998550794U) + aOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 9938135244509986497U;
            aOrbiterH = RotL64((aOrbiterH * 16548185968987392957U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 4024609904162105979U) + aOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 6732064218696157303U;
            aOrbiterI = RotL64((aOrbiterI * 3815409766145891393U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 14314117137220703583U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 15244765904057473814U;
            aOrbiterJ = RotL64((aOrbiterJ * 4034571710808047959U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 17441241682018169245U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 11958974379114644873U;
            aOrbiterG = RotL64((aOrbiterG * 11315689206845170303U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 8310839846793796473U) + aNonceWordH;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 18144572925667544139U) ^ aNonceWordF;
            aOrbiterA = RotL64((aOrbiterA * 11668203295511168011U), 43U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterI, 60U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 39U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterG, 43U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 35U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 23U));
            aIngress = aIngress + RotL64(aOrbiterE, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aPrevious, 30U) + RotL64(aOrbiterD, 11U)) + aOrbiterK) + aNonceWordA);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterK, 29U)) + aOrbiterJ);
            aWandererC = aWandererC + (((RotL64(aCross, 51U) + RotL64(aOrbiterA, 39U)) + aOrbiterH) + RotL64(aCarry, 53U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterB, 46U)) + aOrbiterI);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 37U) + RotL64(aOrbiterA, 53U)) + aOrbiterI) + RotL64(aCarry, 27U)) + aWandererUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 19U) + aOrbiterF) + RotL64(aOrbiterK, 57U)) + aWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 11U) + aOrbiterF) + RotL64(aOrbiterI, 13U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 43U) + aOrbiterJ) + RotL64(aOrbiterE, 3U));
            aWandererB = aWandererB + (((RotL64(aScatter, 13U) + RotL64(aOrbiterF, 41U)) + aOrbiterG) + aNonceWordG);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterF, 22U)) + aOrbiterC) + aNonceWordI);
            aWandererI = aWandererI + ((RotL64(aCross, 46U) + aOrbiterH) + RotL64(aOrbiterB, 27U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 20U));
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererA);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + (RotL64(aWandererK, 6U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererD, 43U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ aNonceWordG;
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 28843U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneB[((aIndex + 27698U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27747U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27755U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 43U) + RotL64(aCross, 11U)) ^ (RotL64(aCarry, 56U) ^ RotL64(aPrevious, 29U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (aWandererK + RotL64(aIngress, 35U)) + 15726877954695761686U;
            aOrbiterC = (aWandererA + RotL64(aPrevious, 28U)) + 14187652171881943587U;
            aOrbiterH = ((aWandererC + RotL64(aCross, 19U)) + 8420423151313882782U) + aOrbiterAssignSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = (aWandererJ + RotL64(aScatter, 53U)) + 14942322692433259283U;
            aOrbiterB = (aWandererE + RotL64(aPrevious, 37U)) + 7272331475919796255U;
            aOrbiterF = (aWandererI + RotL64(aCross, 24U)) + 154504365041805840U;
            aOrbiterA = (aWandererH + RotL64(aScatter, 57U)) + 17475491222554948786U;
            aOrbiterG = (((aWandererG + RotL64(aIngress, 51U)) + RotL64(aCarry, 21U)) + 5759181483165339605U) + aOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 13U)) + 5993060214499322845U) + aNonceWordD;
            aOrbiterD = ((aWandererF + RotL64(aCross, 39U)) + RotL64(aCarry, 51U)) + 10901786237875941844U;
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 43U)) + RotL64(aCarry, 41U)) + 17135786595614068473U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 5208202073886811165U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 6821452921018900631U;
            aOrbiterH = RotL64((aOrbiterH * 13119330055184115669U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 13348064837402206969U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 8967943922403445136U;
            aOrbiterB = RotL64((aOrbiterB * 300168481725373093U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 8130283784171430891U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 6351113882502502876U;
            aOrbiterF = RotL64((aOrbiterF * 15960622823993072903U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 6894708729226455769U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 12065058511247133944U;
            aOrbiterA = RotL64((aOrbiterA * 5432601727436935831U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 17138279326229372741U) + aOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 12987698199066890628U;
            aOrbiterG = RotL64((aOrbiterG * 12665716655177320977U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 13688833537574196675U) + aOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 4211971980434000618U;
            aOrbiterJ = RotL64((aOrbiterJ * 1374411763361518851U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 10376917117582537592U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 4807742522197923516U;
            aOrbiterD = RotL64((aOrbiterD * 15257251453302090961U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 18038296468177121243U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 6879666349379745258U;
            aOrbiterI = RotL64((aOrbiterI * 15819475269715810555U), 39U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterD) + 5193656664432659624U) + aOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1]) + aNonceWordE;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 680899397323387963U;
            aOrbiterK = RotL64((aOrbiterK * 9857476056194621321U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 1851929589073547860U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 13093101559415170218U;
            aOrbiterC = RotL64((aOrbiterC * 13950928576652143737U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 13695333301427028607U) + aOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 15726877954695761686U;
            aOrbiterE = RotL64((aOrbiterE * 960063676226172027U), 35U);
            //
            aIngress = RotL64(aOrbiterH, 51U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterC, 21U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterK, 23U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterJ, 38U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterB, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 39U) + aOrbiterA) + RotL64(aOrbiterD, 39U));
            aWandererH = aWandererH + (((RotL64(aCross, 41U) + RotL64(aOrbiterA, 51U)) + aOrbiterH) + aWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 53U) + aOrbiterD) + RotL64(aOrbiterH, 53U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 44U) + aOrbiterB) + RotL64(aOrbiterC, 6U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterD, 57U)) + aOrbiterE);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterE, 21U)) + aOrbiterI) + RotL64(aCarry, 11U)) + aNonceWordC);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 3U) + aOrbiterG) + RotL64(aOrbiterJ, 29U)) + aWandererUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aPrevious, 11U) + aOrbiterH) + RotL64(aOrbiterG, 10U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterK, 27U)) + aOrbiterH) + aNonceWordO);
            aWandererA = aWandererA + ((((RotL64(aCross, 51U) + aOrbiterE) + RotL64(aOrbiterF, 47U)) + RotL64(aCarry, 43U)) + aNonceWordL);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 18U) + aOrbiterG) + RotL64(aOrbiterC, 43U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 22U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 39U));
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererD, 6U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererI, 29U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ aNonceWordA;
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

void TwistExpander_BaseBall_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xD33238250F2ABDE3ULL + 0xF5D701453A4F437CULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x80BF07BB2A686E6FULL + 0x8D7BBB6CA42CCF8CULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xF883BF1E2A644F13ULL + 0xF3EF2B607709F4D6ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xDAB4045476A7DC61ULL + 0x97CE60B077A68305ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xFF55FCEC03322299ULL + 0xC60E810D19EE8C61ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xF52941BC90D1FF39ULL + 0xEABC1AAE632F622BULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xA03C3905F0F30511ULL + 0xBC3E955CD02D437EULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xBE2D9841BB35350BULL + 0xC57528DF93D5A0A0ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x93F3E555C72B85BBULL + 0xA559BEB318FACDF6ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x8174577934839F07ULL + 0xCB71A58146D34296ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xE55485BAEF1FCB55ULL + 0xA0A5720607BC091FULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x80C2A0B414AEAC65ULL + 0x9CC5D20DF5B332E5ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xA49295108F928577ULL + 0xEF86A7E0B0D7EB32ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xDE9C280D2A87A3C5ULL + 0xFC08835CFA258DD3ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xA5AD8F4B06F948B7ULL + 0xB6528E25155F2898ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xFA5AF3E7BB3222F5ULL + 0xF00A803505DA1FD9ULL);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 1787U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((aIndex + 6113U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 7678U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneA[((aIndex + 4384U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aIngress, 5U)) + (RotL64(aCross, 53U) ^ RotL64(aPrevious, 24U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = ((aWandererG + RotL64(aCross, 51U)) + 5906639480605353429U) + aNonceWordN;
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 43U)) + 5293518570213287605U) + aOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = ((aWandererE + RotL64(aScatter, 35U)) + 15383185501428521377U) + aNonceWordL;
            aOrbiterI = (aWandererD + RotL64(aIngress, 39U)) + 15364072512743978902U;
            aOrbiterG = ((aWandererF + RotL64(aScatter, 28U)) + RotL64(aCarry, 51U)) + 4525473357144014271U;
            aOrbiterF = (aWandererI + RotL64(aCross, 5U)) + 10400911938125603074U;
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 11U)) + RotL64(aCarry, 29U)) + 16417506293824627550U;
            aOrbiterH = (aWandererH + RotL64(aIngress, 23U)) + 2419329331753341815U;
            aOrbiterA = ((((aWandererB + RotL64(aCross, 18U)) + RotL64(aCarry, 37U)) + 14929222427923332069U) + aOrbiterAssignSaltE[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordK;
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 16771573504983922586U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 1863466450051787622U) ^ aNonceWordF;
            aOrbiterE = RotL64((aOrbiterE * 2585626547126027053U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 12895350137096692415U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 3700979086526298327U;
            aOrbiterF = RotL64((aOrbiterF * 10279730254867618193U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 1977099106211282426U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 6144698304096915742U;
            aOrbiterH = RotL64((aOrbiterH * 5039822990560519609U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 3858895556659724975U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 1283646340363435327U;
            aOrbiterA = RotL64((aOrbiterA * 11622421841377018069U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 6240532051889108891U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 757364889381634634U;
            aOrbiterC = RotL64((aOrbiterC * 943852137901972945U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 5272945693977418174U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 6850528198786172283U) ^ aOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1966383079897679953U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 14431587733859573714U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 16124590257870999553U;
            aOrbiterD = RotL64((aOrbiterD * 7755796211433191143U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 14912695018110241411U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 11098623474413346520U;
            aOrbiterB = RotL64((aOrbiterB * 15167688959990872051U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 3484847683376368686U) + aOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 2295388097292719800U;
            aOrbiterG = RotL64((aOrbiterG * 1240808318176106909U), 47U);
            //
            aIngress = RotL64(aOrbiterG, 13U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterB, 43U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterI, 27U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterA, 22U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterD, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 37U) + aOrbiterC) + RotL64(aOrbiterA, 11U));
            aWandererA = aWandererA + (((RotL64(aIngress, 6U) + aOrbiterA) + RotL64(aOrbiterE, 53U)) + aWandererUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterE, 35U)) + aOrbiterF) + aNonceWordM);
            aWandererF = aWandererF + (((RotL64(aScatter, 29U) + RotL64(aOrbiterB, 18U)) + aOrbiterD) + aNonceWordG);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterD, 39U)) + aOrbiterA);
            aWandererH = aWandererH + (((RotL64(aScatter, 11U) + RotL64(aOrbiterH, 3U)) + aOrbiterB) + RotL64(aCarry, 47U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 43U) + aOrbiterH) + RotL64(aOrbiterI, 47U)) + aNonceWordH);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 58U) + RotL64(aOrbiterG, 22U)) + aOrbiterH) + RotL64(aCarry, 13U)) + aWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterG, 29U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererG, 39U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererF);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + RotL64(aWandererB, 30U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ aNonceWordN;
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 15401U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 13672U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 11044U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 9820U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 22U) + RotL64(aCarry, 39U)) + (RotL64(aIngress, 5U) ^ RotL64(aCross, 57U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (aWandererJ + RotL64(aPrevious, 34U)) + 13924571355038625040U;
            aOrbiterD = ((aWandererH + RotL64(aCross, 3U)) + RotL64(aCarry, 35U)) + 16328300979357156658U;
            aOrbiterA = ((aWandererE + RotL64(aScatter, 51U)) + 3947771961206012461U) + aNonceWordO;
            aOrbiterB = (aWandererC + RotL64(aIngress, 19U)) + 15428284250569311285U;
            aOrbiterJ = (aWandererI + RotL64(aCross, 41U)) + 5777369485254032486U;
            aOrbiterG = ((aWandererF + RotL64(aIngress, 47U)) + 16813320300717644673U) + aOrbiterAssignSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterE = (((aWandererB + RotL64(aScatter, 13U)) + RotL64(aCarry, 47U)) + 16689933050200758251U) + aOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = (aWandererA + RotL64(aPrevious, 27U)) + 1856422419049390708U;
            aOrbiterI = ((aWandererG + RotL64(aIngress, 56U)) + RotL64(aCarry, 23U)) + 18214498743831925517U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 18278550878494094923U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 797712062039591797U;
            aOrbiterA = RotL64((aOrbiterA * 7212998747080137625U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 15854849439012341347U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 996882939768167773U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14936703950807908575U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 3005829974130671692U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 8793495343509953906U;
            aOrbiterE = RotL64((aOrbiterE * 14065479348374612031U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 7710453029930631112U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 9511995836117707047U) ^ aNonceWordH;
            aOrbiterK = RotL64((aOrbiterK * 7250766204781428201U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 670902975693341744U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 9045820304668279777U;
            aOrbiterI = RotL64((aOrbiterI * 18373074917532639027U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 12417212387607119470U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 12816983560669985622U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8406003970221889847U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 17245432086377688540U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 6806521945548502014U) ^ aNonceWordK;
            aOrbiterB = RotL64((aOrbiterB * 11335859481858640857U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 8947500746292365294U) + aNonceWordG;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 4468060468522895852U;
            aOrbiterG = RotL64((aOrbiterG * 7022481284816599797U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 9892975931958803992U) + aOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 3042599331526937836U;
            aOrbiterD = RotL64((aOrbiterD * 3308512896171443645U), 11U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterB, 50U);
            aIngress = aIngress + (RotL64(aOrbiterE, 41U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterI, 11U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterG, 35U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterD, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterJ, 51U)) + aOrbiterD) + aNonceWordM);
            aWandererB = aWandererB + (((RotL64(aScatter, 23U) + RotL64(aOrbiterK, 24U)) + aOrbiterG) + aNonceWordI);
            aWandererF = aWandererF ^ ((RotL64(aCross, 37U) + aOrbiterB) + RotL64(aOrbiterE, 41U));
            aWandererI = aWandererI + (((RotL64(aIngress, 60U) + RotL64(aOrbiterA, 19U)) + aOrbiterC) + aWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 47U) + aOrbiterK) + RotL64(aOrbiterC, 5U));
            aWandererH = aWandererH + ((((RotL64(aScatter, 51U) + aOrbiterE) + RotL64(aOrbiterI, 35U)) + RotL64(aCarry, 57U)) + aWandererUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 5U) + aOrbiterJ) + RotL64(aOrbiterG, 11U));
            aWandererC = aWandererC + ((((RotL64(aIngress, 42U) + aOrbiterD) + RotL64(aOrbiterI, 28U)) + RotL64(aCarry, 27U)) + aNonceWordN);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterK, 47U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 22U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererB, 13U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordD);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 19672U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneA[((aIndex + 24286U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19117U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneC[((aIndex + 21675U)) & S_BLOCK1], 42U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 47U) + RotL64(aPrevious, 35U)) + (RotL64(aCarry, 23U) ^ RotL64(aIngress, 10U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (aWandererB + RotL64(aCross, 43U)) + 15726877954695761686U;
            aOrbiterE = (aWandererF + RotL64(aIngress, 12U)) + 14187652171881943587U;
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 39U)) + RotL64(aCarry, 57U)) + 8420423151313882782U;
            aOrbiterK = ((aWandererK + RotL64(aScatter, 5U)) + 14942322692433259283U) + aOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = (aWandererJ + RotL64(aPrevious, 47U)) + 7272331475919796255U;
            aOrbiterH = ((aWandererI + RotL64(aScatter, 57U)) + RotL64(aCarry, 3U)) + 154504365041805840U;
            aOrbiterD = (((aWandererC + RotL64(aIngress, 20U)) + RotL64(aCarry, 43U)) + 17475491222554948786U) + aNonceWordE;
            aOrbiterJ = ((aWandererA + RotL64(aCross, 27U)) + 5759181483165339605U) + aOrbiterAssignSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = (aWandererD + RotL64(aIngress, 35U)) + 5993060214499322845U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 10901786237875941844U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterG) ^ 17135786595614068473U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterF = RotL64((aOrbiterF * 15923538730142047043U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 5208202073886811165U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 6821452921018900631U;
            aOrbiterG = RotL64((aOrbiterG * 13119330055184115669U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 13348064837402206969U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 8967943922403445136U;
            aOrbiterK = RotL64((aOrbiterK * 300168481725373093U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 8130283784171430891U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 6351113882502502876U) ^ aOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15960622823993072903U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 6894708729226455769U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 12065058511247133944U) ^ aNonceWordN;
            aOrbiterC = RotL64((aOrbiterC * 5432601727436935831U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 17138279326229372741U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 12987698199066890628U;
            aOrbiterH = RotL64((aOrbiterH * 12665716655177320977U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 13688833537574196675U) + aNonceWordK;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 4211971980434000618U;
            aOrbiterD = RotL64((aOrbiterD * 1374411763361518851U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 10376917117582537592U) + aOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 4807742522197923516U;
            aOrbiterJ = RotL64((aOrbiterJ * 15257251453302090961U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 18038296468177121243U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 6879666349379745258U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15819475269715810555U), 41U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterJ, 60U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 19U));
            aIngress = aIngress + (RotL64(aOrbiterD, 5U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + RotL64(aOrbiterK, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aIngress, 35U) + aOrbiterC) + RotL64(aOrbiterE, 53U)) + aNonceWordM);
            aWandererG = aWandererG ^ (((RotL64(aCross, 39U) + aOrbiterG) + RotL64(aOrbiterE, 11U)) + aWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 60U) + RotL64(aOrbiterK, 47U)) + aOrbiterF) + RotL64(aCarry, 13U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterE, 36U)) + aOrbiterK);
            aWandererB = aWandererB + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterD, 43U)) + aOrbiterA);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 47U) + aOrbiterG) + RotL64(aOrbiterF, 3U)) + aNonceWordG);
            aWandererK = aWandererK + ((((RotL64(aCross, 43U) + RotL64(aOrbiterA, 29U)) + aOrbiterK) + aNonceWordD) + aWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 10U) + RotL64(aOrbiterJ, 60U)) + aOrbiterH);
            aWandererA = aWandererA + (((RotL64(aIngress, 23U) + RotL64(aOrbiterJ, 21U)) + aOrbiterG) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererA);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererI, 46U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ aNonceWordH;
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 32721U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28586U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 28379U)) & S_BLOCK1], 42U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 26375U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 60U) + RotL64(aCross, 13U)) ^ (RotL64(aIngress, 27U) ^ RotL64(aCarry, 39U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (((aWandererK + RotL64(aPrevious, 34U)) + RotL64(aCarry, 19U)) + 4739486756133131180U) + aNonceWordD;
            aOrbiterG = ((aWandererI + RotL64(aScatter, 57U)) + 16089707555501328184U) + aOrbiterAssignSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = (aWandererD + RotL64(aIngress, 13U)) + 15310047330238536453U;
            aOrbiterK = (aWandererH + RotL64(aCross, 27U)) + 7901411596386834955U;
            aOrbiterI = (((aWandererC + RotL64(aIngress, 23U)) + RotL64(aCarry, 39U)) + 4357555491060982163U) + aNonceWordN;
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 41U)) + RotL64(aCarry, 3U)) + 15667085602825720102U;
            aOrbiterA = (aWandererB + RotL64(aCross, 52U)) + 8520635334382269253U;
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 47U)) + 1772509779231068315U) + aOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = (aWandererG + RotL64(aScatter, 19U)) + 15336170957886025677U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 8628770833489469980U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 15469234024247246228U;
            aOrbiterB = RotL64((aOrbiterB * 8905266995119987947U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 10796430900884288328U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 10660110397012853289U) ^ aOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9140007610912037461U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 11202284258711214794U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 17509491802893182994U;
            aOrbiterA = RotL64((aOrbiterA * 9329107599972703671U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 16212572740740103554U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 2190030203761579226U;
            aOrbiterD = RotL64((aOrbiterD * 3101886685668871045U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 12014337082293041909U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 3733531010807001506U;
            aOrbiterK = RotL64((aOrbiterK * 5797362244066062299U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 7100994963061975529U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 17837541162838600258U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8745987361678166553U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 3311518938023146951U) + aNonceWordM;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 7709505172646831553U;
            aOrbiterH = RotL64((aOrbiterH * 7121143171245765213U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 4979968094554018443U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 16822214821463034107U;
            aOrbiterJ = RotL64((aOrbiterJ * 8618262120451291765U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 8376124175020587079U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 11084586282092424876U) ^ aOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5835632742522563537U), 19U);
            //
            aIngress = RotL64(aOrbiterA, 18U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 47U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 21U));
            aIngress = aIngress + (RotL64(aOrbiterG, 43U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterK, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aIngress, 18U) + aOrbiterD) + RotL64(aOrbiterA, 46U));
            aWandererG = aWandererG + ((RotL64(aScatter, 57U) + RotL64(aOrbiterI, 53U)) + aOrbiterC);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 11U) + aOrbiterB) + RotL64(aOrbiterI, 37U));
            aWandererI = aWandererI + ((RotL64(aCross, 3U) + RotL64(aOrbiterK, 41U)) + aOrbiterC);
            aWandererB = aWandererB ^ ((((RotL64(aPrevious, 53U) + aOrbiterJ) + RotL64(aOrbiterA, 21U)) + aNonceWordK) + aWandererUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 47U) + aOrbiterG) + RotL64(aOrbiterJ, 27U)) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ ((((RotL64(aCross, 34U) + RotL64(aOrbiterH, 4U)) + aOrbiterJ) + aNonceWordJ) + aWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 27U) + RotL64(aOrbiterJ, 11U)) + aOrbiterK) + RotL64(aCarry, 11U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterD, 57U)) + aOrbiterH) + aNonceWordP);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + (RotL64(aWandererG, 38U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererI, 21U) ^ aWandererH);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 29U));
            aCarry = aCarry + RotL64(aWandererB, 3U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordE);
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

void TwistExpander_BaseBall_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xF96ED3DD5EC476C7ULL + 0x89DB363F7591DC4CULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xE9C1731F8ADC256FULL + 0xA5F9ABFE38AE0F40ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xD2D0E13FE50756D3ULL + 0xF8AC5FF01133C269ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x8FA13BAF80CAC503ULL + 0x892F83DB242BE3B6ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x92A69A1164330147ULL + 0xEFD7ED440F6F36FFULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x911F58313E94A679ULL + 0xCC06C82CCE948025ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xAC557EF3BE7DBBB1ULL + 0xAD71279617268E8BULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xE88594433FCAFF6DULL + 0xDFF22D057342AB26ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x96B4A8A6562CA82FULL + 0xEE6DAD510E083976ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x9579D3ED25BC1055ULL + 0xCC8343EB53F3FBAAULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xFEE3E41D859B1B61ULL + 0xDD4F04D8E5703D86ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x958769DAE7F080D5ULL + 0xD037DE9FEF89F675ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xDBE4B33D03154C33ULL + 0xB68021D93F672AC4ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xCA7CC2518793542BULL + 0xB11459B799F48DB2ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xF51774C3BFC0F177ULL + 0xF5322D3C5721D39FULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xFE7A46B2063FE46DULL + 0xF9A075EF21E7437FULL);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 243U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 7986U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 5141U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 2559U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 11U) ^ RotL64(aCross, 54U)) ^ (RotL64(aIngress, 29U) + RotL64(aCarry, 41U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 47U)) + RotL64(aCarry, 5U)) + 13714409587461539863U;
            aOrbiterA = (((aWandererA + RotL64(aIngress, 19U)) + 14101156723903265839U) + aOrbiterAssignSaltF[((aIndex + 10U)) & S_SALT1]) + aNonceWordD;
            aOrbiterE = (((aWandererD + RotL64(aPrevious, 35U)) + RotL64(aCarry, 41U)) + 7063754562895369001U) + aOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = ((aWandererH + RotL64(aCross, 56U)) + RotL64(aCarry, 57U)) + 12320578575245519386U;
            aOrbiterD = ((aWandererF + RotL64(aScatter, 11U)) + 11744826789631008424U) + aNonceWordE;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 8744816505096675597U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 10405435520084528645U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13279521344071568023U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 1463157688070683543U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 12379603577919617703U;
            aOrbiterJ = RotL64((aOrbiterJ * 14858901470015109311U), 41U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterE) + 1343439118031348146U) + aOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1]) + aNonceWordH;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 16118850268070235540U) ^ aNonceWordG;
            aOrbiterF = RotL64((aOrbiterF * 11184386483735388257U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 14116264435819277136U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 5251698273012432109U;
            aOrbiterA = RotL64((aOrbiterA * 1495818611622063967U), 29U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterF) + 14806408656041403829U) + aOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1]) + aNonceWordI;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 11569345414052398227U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9913158908301414861U), 3U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterE, 23U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 13U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterF, 54U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 39U) + aOrbiterF) + RotL64(aOrbiterA, 13U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterJ, 46U)) + aOrbiterD) + RotL64(aCarry, 21U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 10U) + aOrbiterD) + RotL64(aOrbiterE, 5U)) + aWandererUpdateSaltD[((aIndex + 15U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterE, 21U)) + aOrbiterJ) + RotL64(aCarry, 43U)) + aWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 47U) + aOrbiterA) + RotL64(aOrbiterD, 57U)) + aNonceWordB);
            //
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererA);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + RotL64(aWandererH, 39U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordJ);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 16027U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 8541U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 12766U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 15264U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 56U) + RotL64(aCross, 5U)) ^ (RotL64(aPrevious, 43U) ^ RotL64(aCarry, 29U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 29U)) + 15316464782468770057U) + aOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = (((aWandererC + RotL64(aIngress, 19U)) + RotL64(aCarry, 43U)) + 6642872057476351588U) + aNonceWordA;
            aOrbiterK = (((aWandererD + RotL64(aPrevious, 5U)) + 660732654689529192U) + aOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1]) + aNonceWordF;
            aOrbiterJ = ((aWandererF + RotL64(aCross, 44U)) + RotL64(aCarry, 3U)) + 7235418086884000655U;
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 57U)) + RotL64(aCarry, 27U)) + 14784518476694580493U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 12222433977933449375U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 8573001207708329927U) ^ aNonceWordK;
            aOrbiterK = RotL64((aOrbiterK * 17771120145431297541U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 16035256260815013172U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 15767726974121910203U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 719060452537759331U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 17712217935322939971U) + aOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 13488963456923357159U;
            aOrbiterB = RotL64((aOrbiterB * 16785285630840310405U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 10222949131965611079U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 1495561412321657209U) ^ aOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9706305581868526265U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 16156530750584361434U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 7773792489045606309U) ^ aNonceWordO;
            aOrbiterJ = RotL64((aOrbiterJ * 10730624207715601393U), 3U);
            //
            aIngress = RotL64(aOrbiterJ, 3U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 23U));
            aIngress = aIngress + RotL64(aOrbiterH, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aScatter, 23U) + aOrbiterG) + RotL64(aOrbiterJ, 57U)) + aWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 6U) + aOrbiterJ) + RotL64(aOrbiterK, 35U)) + RotL64(aCarry, 5U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 35U) + aOrbiterK) + RotL64(aOrbiterH, 47U));
            aWandererA = aWandererA + ((((RotL64(aIngress, 47U) + aOrbiterB) + RotL64(aOrbiterH, 23U)) + RotL64(aCarry, 47U)) + aNonceWordH);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 57U) + aOrbiterB) + RotL64(aOrbiterG, 14U)) + aWandererUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererC, 43U);
            aCarry = aCarry + RotL64(aIngress, 52U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordJ);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 23263U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22250U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 20047U)) & S_BLOCK1], 44U) ^ RotL64(aOperationLaneC[((aIndex + 22921U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 20U) + RotL64(aCarry, 53U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCross, 35U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = ((aWandererG + RotL64(aIngress, 27U)) + 4848316479321533394U) + aOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = (((aWandererJ + RotL64(aPrevious, 35U)) + RotL64(aCarry, 51U)) + 6919360256662636195U) + aNonceWordA;
            aOrbiterA = ((aWandererH + RotL64(aScatter, 46U)) + RotL64(aCarry, 37U)) + 9897013582181108544U;
            aOrbiterF = (((aWandererA + RotL64(aCross, 19U)) + RotL64(aCarry, 23U)) + 7319353809896158678U) + aNonceWordO;
            aOrbiterH = ((aWandererK + RotL64(aIngress, 57U)) + 2848175435514849859U) + aOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 6967780718720437934U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 10143884766603388136U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17346772745745835895U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 8675965006150972051U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterF) ^ 16350117755560994281U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterG = RotL64((aOrbiterG * 15072308930382994425U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 17976597517118423760U) + aNonceWordI;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 1399631141355370237U;
            aOrbiterE = RotL64((aOrbiterE * 16537788276543236833U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 3590613762034716792U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 5134624314245932157U) ^ aOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13077589037975283371U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 10082236952942943654U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 4015535035905433450U;
            aOrbiterH = RotL64((aOrbiterH * 4961808568701908559U), 43U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterE, 3U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 53U));
            aIngress = aIngress + RotL64(aOrbiterG, 14U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((((RotL64(aScatter, 13U) + RotL64(aOrbiterF, 13U)) + aOrbiterH) + aNonceWordP) + aWandererUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 35U) + RotL64(aOrbiterE, 21U)) + aOrbiterG) + RotL64(aCarry, 29U)) + aWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 58U) + aOrbiterF) + RotL64(aOrbiterA, 35U));
            aWandererK = aWandererK + ((((RotL64(aCross, 47U) + aOrbiterF) + RotL64(aOrbiterE, 56U)) + RotL64(aCarry, 13U)) + aNonceWordD);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 21U) + aOrbiterE) + RotL64(aOrbiterA, 3U)) + aNonceWordL);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + RotL64(aWandererH, 42U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordB);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 28220U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28471U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24659U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneD[((aIndex + 27898U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 11U) ^ RotL64(aCarry, 39U)) + (RotL64(aIngress, 27U) ^ RotL64(aCross, 54U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 27U)) + RotL64(aCarry, 47U)) + 7825479804710770560U;
            aOrbiterC = (((aWandererB + RotL64(aIngress, 19U)) + 5298124167101358123U) + aOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1]) + aNonceWordH;
            aOrbiterE = (((aWandererE + RotL64(aCross, 11U)) + 17774541024369233726U) + aOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordA;
            aOrbiterD = (((aWandererJ + RotL64(aPrevious, 58U)) + RotL64(aCarry, 27U)) + 7679371833537454082U) + aNonceWordF;
            aOrbiterH = ((aWandererF + RotL64(aIngress, 35U)) + RotL64(aCarry, 11U)) + 5385914900748772224U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 3879781930908486531U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 659110346638873236U) ^ aNonceWordE;
            aOrbiterE = RotL64((aOrbiterE * 17439162088869824407U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 10749021728538539749U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 3631252455767429457U) ^ aOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8552825360915119613U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 2271978810960685021U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 5963558780692551176U;
            aOrbiterD = RotL64((aOrbiterD * 4772055335210781149U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 974909966119198104U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 9296998242911152296U) ^ aOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2613629915877957661U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 2245318466901521959U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterE) ^ 13391076374843288568U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterH = RotL64((aOrbiterH * 18094558036982107419U), 19U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterD, 19U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 29U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterC, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterJ, 51U)) + aOrbiterD) + aNonceWordP);
            aWandererF = aWandererF + (((RotL64(aPrevious, 50U) + RotL64(aOrbiterE, 19U)) + aOrbiterC) + RotL64(aCarry, 41U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterH, 35U)) + aOrbiterJ) + aWandererUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aIngress, 29U) + aOrbiterC) + RotL64(aOrbiterJ, 60U)) + RotL64(aCarry, 3U)) + aWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterC, 27U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 5U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 37U));
            aCarry = aCarry + RotL64(aWandererJ, 46U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordO);
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

void TwistExpander_BaseBall_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xC2430C1CF3023D3DULL + 0x8E821422E17C9CBDULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x9A773FCC5E69650FULL + 0xDFB049E588A70DA7ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x99FF5171198A9365ULL + 0xA883E3F4F5DBCAD8ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x9A2C69453EB6E821ULL + 0xF33D10BD809AADF9ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x935C5C4759DFD2C3ULL + 0xAF000C557D026390ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xD1787983B2A20C5BULL + 0xF80D8D22DBE8F993ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x9194AA6CA3F2A039ULL + 0xED22C655EBD7E4B9ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xF685FED1F1FE35F9ULL + 0x9A601FBD5755E673ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xC459B74C8874A607ULL + 0xC6D8AB89E720B764ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xD70471DD97EC02CDULL + 0xDE6D49F55A7D8D8EULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xF048CEDDC024934DULL + 0xF85D585B34F931FEULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x8681F56C1BF8087DULL + 0x9A64B6A83CA3DD81ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x8085AF4217033475ULL + 0xC56390E275F17596ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xD4DBB5B7F9096E07ULL + 0x9FA923551D213924ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xB14D7219F4561469ULL + 0xC095CC4768FABADCULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xAA04383DFB895F01ULL + 0xB17C24233A2A2BDDULL);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 3884U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4914U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 6869U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((aIndex + 2929U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aPrevious, 24U)) ^ (RotL64(aIngress, 37U) + RotL64(aCross, 5U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (((aWandererI + RotL64(aPrevious, 57U)) + RotL64(aCarry, 23U)) + 17936518874386450467U) + aOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = (((aWandererF + RotL64(aCross, 10U)) + RotL64(aCarry, 41U)) + 13722737841589910344U) + aOrbiterAssignSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = ((aWandererB + RotL64(aScatter, 43U)) + 11774969167948715796U) + aNonceWordO;
            aOrbiterA = (((aWandererG + RotL64(aIngress, 29U)) + RotL64(aCarry, 53U)) + 3640101505680493777U) + aNonceWordF;
            aOrbiterG = ((aWandererA + RotL64(aCross, 51U)) + 1369495382725650822U) + aNonceWordI;
            aOrbiterH = (aWandererK + RotL64(aIngress, 21U)) + 11827310354654653345U;
            aOrbiterJ = (aWandererC + RotL64(aScatter, 3U)) + 186037671377175394U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 11428829344234627340U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterB) ^ 2275016369870029068U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterE = RotL64((aOrbiterE * 14936799202145280833U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 15471646673734798328U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 12172082573115640145U) ^ aOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9629417882787847753U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 6626736341348283154U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 12220614992483863623U) ^ aOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8137086205714097487U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 13157102324253760215U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 4143587482368093601U;
            aOrbiterJ = RotL64((aOrbiterJ * 5060677690991506895U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 11007575246013796426U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 11721585930088637162U;
            aOrbiterB = RotL64((aOrbiterB * 15009627907125738519U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 5720789204450196217U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 3094696226821431648U;
            aOrbiterA = RotL64((aOrbiterA * 4412033981712165541U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 14675830108100986773U) + aOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 9444071495289719645U;
            aOrbiterK = RotL64((aOrbiterK * 10983136361953366557U), 23U);
            //
            aIngress = RotL64(aOrbiterG, 57U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 36U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 19U));
            aIngress = aIngress + RotL64(aOrbiterK, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((((RotL64(aScatter, 29U) + aOrbiterJ) + RotL64(aOrbiterK, 19U)) + aNonceWordK) + aWandererUpdateSaltC[((aIndex + 12U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aIngress, 57U) + RotL64(aOrbiterG, 51U)) + aOrbiterA);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 43U) + aOrbiterB) + RotL64(aOrbiterH, 57U)) + aNonceWordA);
            aWandererA = aWandererA + (((RotL64(aCross, 19U) + RotL64(aOrbiterH, 5U)) + aOrbiterK) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 12U) + RotL64(aOrbiterE, 27U)) + aOrbiterB) + aWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 51U) + aOrbiterE) + RotL64(aOrbiterH, 34U)) + RotL64(aCarry, 21U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 35U) + aOrbiterE) + RotL64(aOrbiterA, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererB);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 50U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + RotL64(aWandererF, 13U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordA);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 11955U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 11295U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9890U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 14888U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 51U) + RotL64(aIngress, 10U)) ^ (RotL64(aPrevious, 23U) + RotL64(aCarry, 37U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = ((aWandererD + RotL64(aIngress, 37U)) + 6069475454765660321U) + aNonceWordB;
            aOrbiterA = ((aWandererE + RotL64(aCross, 27U)) + 11483704742497268068U) + aNonceWordA;
            aOrbiterF = ((aWandererC + RotL64(aScatter, 58U)) + RotL64(aCarry, 11U)) + 11055697447388986418U;
            aOrbiterK = (((aWandererB + RotL64(aPrevious, 19U)) + RotL64(aCarry, 35U)) + 10897095046039997004U) + aOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = ((aWandererJ + RotL64(aCross, 5U)) + 4731637118230457840U) + aOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = ((aWandererK + RotL64(aScatter, 47U)) + 13855839187084986751U) + aNonceWordH;
            aOrbiterE = ((aWandererF + RotL64(aIngress, 11U)) + RotL64(aCarry, 47U)) + 5328208115460188239U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 12479538544291412985U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 10740165998792608231U;
            aOrbiterF = RotL64((aOrbiterF * 14046827922294477379U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 6492798157284955373U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 13056825957483891921U;
            aOrbiterG = RotL64((aOrbiterG * 14882112110627751751U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 2068184064919194657U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 5656302738780746294U;
            aOrbiterK = RotL64((aOrbiterK * 16493021179127646345U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 11193756120230763294U) + aOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 17306750816837208999U;
            aOrbiterA = RotL64((aOrbiterA * 7949360041241439741U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 12952818800389361804U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 15380412293642628312U;
            aOrbiterH = RotL64((aOrbiterH * 2914662289178925547U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 7706090204767242996U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 14598802276412649570U) ^ aNonceWordI;
            aOrbiterD = RotL64((aOrbiterD * 4821408736292041399U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 17819762117328075515U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 6481384240915075101U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4836701121865783029U), 27U);
            //
            aIngress = RotL64(aOrbiterG, 35U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterE, 12U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterK, 19U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterH, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 14U) + aOrbiterH) + RotL64(aOrbiterE, 39U));
            aWandererC = aWandererC + ((((RotL64(aCross, 3U) + aOrbiterD) + RotL64(aOrbiterA, 29U)) + RotL64(aCarry, 21U)) + aWandererUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 21U) + aOrbiterE) + RotL64(aOrbiterD, 47U)) + aNonceWordC);
            aWandererF = aWandererF + ((RotL64(aScatter, 29U) + aOrbiterE) + RotL64(aOrbiterF, 14U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 35U) + aOrbiterG) + RotL64(aOrbiterF, 3U));
            aWandererD = aWandererD + (((RotL64(aScatter, 53U) + aOrbiterG) + RotL64(aOrbiterE, 23U)) + RotL64(aCarry, 53U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterK, 57U)) + aOrbiterG) + aWandererUpdateSaltF[((aIndex + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 20U));
            aCarry = aCarry + (RotL64(aWandererC, 37U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererK, 3U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ aNonceWordL;
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 21563U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneA[((aIndex + 19481U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17450U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneC[((aIndex + 16699U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 20U) ^ RotL64(aCross, 5U)) + (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 37U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (((aWandererE + RotL64(aCross, 47U)) + RotL64(aCarry, 5U)) + 15726877954695761686U) + aNonceWordJ;
            aOrbiterH = (aWandererK + RotL64(aPrevious, 27U)) + 14187652171881943587U;
            aOrbiterD = (aWandererF + RotL64(aScatter, 41U)) + 8420423151313882782U;
            aOrbiterI = ((aWandererH + RotL64(aIngress, 4U)) + 14942322692433259283U) + aNonceWordG;
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 21U)) + 7272331475919796255U) + aOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = (((aWandererJ + RotL64(aScatter, 35U)) + RotL64(aCarry, 21U)) + 154504365041805840U) + aOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = (((aWandererD + RotL64(aIngress, 13U)) + RotL64(aCarry, 51U)) + 17475491222554948786U) + aNonceWordC;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 5759181483165339605U) + aOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 5993060214499322845U;
            aOrbiterD = RotL64((aOrbiterD * 10799489831896153301U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 10901786237875941844U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 17135786595614068473U;
            aOrbiterH = RotL64((aOrbiterH * 15923538730142047043U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 5208202073886811165U) + aNonceWordA;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 6821452921018900631U;
            aOrbiterC = RotL64((aOrbiterC * 13119330055184115669U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 13348064837402206969U) + aOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 8967943922403445136U;
            aOrbiterI = RotL64((aOrbiterI * 300168481725373093U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 8130283784171430891U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 6351113882502502876U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15960622823993072903U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 6894708729226455769U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 12065058511247133944U;
            aOrbiterF = RotL64((aOrbiterF * 5432601727436935831U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 17138279326229372741U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 12987698199066890628U;
            aOrbiterE = RotL64((aOrbiterE * 12665716655177320977U), 29U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterH, 57U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 21U));
            aIngress = aIngress + (RotL64(aOrbiterC, 11U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 19U) + aOrbiterC) + RotL64(aOrbiterD, 35U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 47U) + RotL64(aOrbiterF, 3U)) + aOrbiterI) + RotL64(aCarry, 57U)) + aWandererUpdateSaltB[((aIndex + 10U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterH, 41U)) + aOrbiterD);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 3U) + aOrbiterH) + RotL64(aOrbiterI, 58U)) + RotL64(aCarry, 11U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterG, 51U)) + aOrbiterC);
            aWandererI = aWandererI + ((((RotL64(aIngress, 56U) + RotL64(aOrbiterH, 29U)) + aOrbiterC) + aNonceWordN) + aWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 39U) + RotL64(aOrbiterD, 11U)) + aOrbiterE) + aNonceWordF);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererE);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 21U));
            aCarry = aCarry + (RotL64(aWandererI, 42U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererH, 51U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordH);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 27723U)) & S_BLOCK1], 18U) ^ RotL64(aWorkLaneB[((aIndex + 29530U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 28014U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 28274U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aIngress, 22U)) ^ (RotL64(aCross, 43U) + RotL64(aPrevious, 57U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererF + RotL64(aIngress, 41U)) + 7790166497945719700U;
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 51U)) + 7136208896846119188U) + aOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = (aWandererI + RotL64(aScatter, 19U)) + 12123156943355100886U;
            aOrbiterE = (((aWandererD + RotL64(aCross, 5U)) + RotL64(aCarry, 51U)) + 5095546037880875199U) + aNonceWordD;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 35U)) + RotL64(aCarry, 39U)) + 17642705393916765992U;
            aOrbiterG = ((aWandererJ + RotL64(aCross, 29U)) + 9918479837334416990U) + aOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = (((aWandererA + RotL64(aScatter, 58U)) + RotL64(aCarry, 13U)) + 4890009823843176466U) + aNonceWordM;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 17652590786213674124U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 870002527644696135U) ^ aOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 915408393979165539U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 12545429703552643682U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterE) ^ 5310272867406182581U) ^ aOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterG = RotL64((aOrbiterG * 10420003334833925011U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 3264719049050179440U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 1967241238180278937U;
            aOrbiterB = RotL64((aOrbiterB * 13004319774269457957U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 773883832927040736U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 12766817190261232485U;
            aOrbiterK = RotL64((aOrbiterK * 7448864556802318431U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 260069382395598265U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 15462103891287350123U) ^ aOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5029268763635635753U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 4072032867513289827U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 17153061419083897076U;
            aOrbiterE = RotL64((aOrbiterE * 11934532169271718913U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 6207264270332656966U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 18048064697837314947U;
            aOrbiterA = RotL64((aOrbiterA * 13632594619404208489U), 27U);
            //
            aIngress = RotL64(aOrbiterJ, 13U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 20U));
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterE, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aCross, 60U) + aOrbiterF) + RotL64(aOrbiterJ, 3U)) + RotL64(aCarry, 19U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterE, 58U)) + aOrbiterB);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterB, 29U)) + aOrbiterF) + RotL64(aCarry, 35U)) + aWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterA, 35U)) + aOrbiterB);
            aWandererF = aWandererF + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterG, 13U)) + aOrbiterA) + aNonceWordI);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterA, 47U)) + aOrbiterJ) + aWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 21U) + aOrbiterA) + RotL64(aOrbiterK, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 26U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererA);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + RotL64(aWandererB, 21U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordA);
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

void TwistExpander_BaseBall_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xF288639AC3CEE61DULL + 0x883E8C3764A27505ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x87D8B3788CE281D7ULL + 0xCD2502B38D34F5A8ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xEC75499FF320B53BULL + 0xCA15605B92C19693ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xF06EBCF8BF199707ULL + 0xCC8CF7862BC7EB9DULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xC8EAF69F2C975933ULL + 0xE079D41D43097CC9ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xB72111C77D2C1169ULL + 0xE0B0438C163089B2ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x82FFBCC3D39C9887ULL + 0xD727E6C0B4418039ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xE335C19D4CBD7713ULL + 0xBC942BD2E5CD782BULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xDED0F21986D91FEBULL + 0x90042BDA396EE318ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xE6EA867E9C6D900FULL + 0x9B8A0BABE3E6C1CCULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xDB680223DC121925ULL + 0x8290D9873F1593FAULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xF4617A5DEEF248FDULL + 0x9281F1AC8A52325FULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xC2AD86967AC40BE7ULL + 0x95C6665BD324A783ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x8F67BEE84EAF96A3ULL + 0xA041E7B4CE74F298ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xBC2A7923FFF07ED3ULL + 0x80D372745E93C317ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xFB954D68ED850397ULL + 0x8CB80BAE5F1E4FA9ULL);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 2984U)) & S_BLOCK1], 38U) ^ RotL64(aWorkLaneC[((aIndex + 5486U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 3782U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((aIndex + 7639U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aIngress, 52U)) ^ (RotL64(aCarry, 27U) + RotL64(aPrevious, 13U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererI + RotL64(aIngress, 11U)) + 9023059520606551446U;
            aOrbiterE = (((aWandererE + RotL64(aCross, 3U)) + RotL64(aCarry, 5U)) + 662441755115638133U) + aOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = ((aWandererA + RotL64(aScatter, 47U)) + RotL64(aCarry, 37U)) + 16957253361196144712U;
            aOrbiterH = (aWandererG + RotL64(aPrevious, 41U)) + 7840955025765308605U;
            aOrbiterI = ((aWandererD + RotL64(aIngress, 60U)) + RotL64(aCarry, 57U)) + 346855809270395799U;
            aOrbiterG = ((aWandererH + RotL64(aCross, 29U)) + 16099139781586668343U) + aOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 35U)) + 3706457327118322098U) + aNonceWordN;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 12166825885547622870U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 7792658665720344200U) ^ aOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16305542632794270697U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 7128477606152986326U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 11116533962780290084U;
            aOrbiterI = RotL64((aOrbiterI * 11993485572912492297U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 10443889548568288532U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 4402387036946561017U;
            aOrbiterG = RotL64((aOrbiterG * 9032964741841833277U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 13002706161178447654U) + aOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 13929727277530310708U;
            aOrbiterF = RotL64((aOrbiterF * 7005639090871200285U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 10949073760696935106U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 15405923432006783533U;
            aOrbiterJ = RotL64((aOrbiterJ * 17989565878445202495U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 18096057968822208905U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 3032155040484574973U;
            aOrbiterH = RotL64((aOrbiterH * 448597307502544605U), 5U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterH) + 17462076466907467134U) + aOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 15471015427013701406U) ^ aOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6113474000571976139U), 27U);
            //
            aIngress = RotL64(aOrbiterE, 47U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterI, 22U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 11U));
            aIngress = aIngress + RotL64(aOrbiterB, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 5U) + aOrbiterG) + RotL64(aOrbiterJ, 29U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 11U) + RotL64(aOrbiterF, 57U)) + aOrbiterB) + RotL64(aCarry, 19U)) + aWandererUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 21U) + aOrbiterH) + RotL64(aOrbiterF, 41U));
            aWandererA = aWandererA + (((RotL64(aScatter, 37U) + RotL64(aOrbiterG, 19U)) + aOrbiterH) + RotL64(aCarry, 35U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 60U) + RotL64(aOrbiterI, 13U)) + aOrbiterJ) + aWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 43U) + aOrbiterE) + RotL64(aOrbiterG, 50U)) + aNonceWordP);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterB, 5U)) + aOrbiterG) + aNonceWordE);
            //
            aCarry = aCarry + (RotL64(aWandererH, 30U) ^ aWandererG);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 53U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 21U));
            aCarry = aCarry + RotL64(aWandererA, 13U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordC);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 14365U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneD[((aIndex + 11365U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 15413U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneB[((aIndex + 16331U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 47U) ^ RotL64(aIngress, 34U)) + (RotL64(aCross, 19U) + RotL64(aPrevious, 5U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (aWandererJ + RotL64(aIngress, 23U)) + 12692813903177772178U;
            aOrbiterH = (((aWandererA + RotL64(aCross, 39U)) + 7112496446691277899U) + aOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1]) + aNonceWordB;
            aOrbiterC = (aWandererC + RotL64(aScatter, 5U)) + 2112247138290568813U;
            aOrbiterB = (((aWandererF + RotL64(aPrevious, 29U)) + RotL64(aCarry, 27U)) + 3699421080882855947U) + aOrbiterAssignSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterK = (((aWandererE + RotL64(aCross, 11U)) + RotL64(aCarry, 57U)) + 13761832028354380922U) + aNonceWordK;
            aOrbiterI = ((aWandererH + RotL64(aIngress, 56U)) + 9243822514887600214U) + aNonceWordD;
            aOrbiterD = ((aWandererG + RotL64(aScatter, 47U)) + RotL64(aCarry, 11U)) + 6863833516853046129U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 8863897995943098018U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 13346785686701467520U) ^ aNonceWordC;
            aOrbiterC = RotL64((aOrbiterC * 18074843497158380703U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 15309543066305531619U) + aOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 17515530938817919111U;
            aOrbiterF = RotL64((aOrbiterF * 16625193986319048245U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 760493237816424254U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 7282586354117620860U;
            aOrbiterB = RotL64((aOrbiterB * 2327153408185290635U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 4129706068526969105U) + aOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 7020175432730888755U) ^ aNonceWordM;
            aOrbiterH = RotL64((aOrbiterH * 10095158356907592239U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 9102258982216515596U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 10822031305361453690U;
            aOrbiterK = RotL64((aOrbiterK * 2036205056490578491U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 12571477440964330246U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 8436347026653095199U;
            aOrbiterI = RotL64((aOrbiterI * 17930734781213681573U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 14214789872073941940U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 12915911919403385001U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13161681603528031511U), 35U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterH, 41U);
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterF, 51U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterI, 58U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aScatter, 30U) + aOrbiterK) + RotL64(aOrbiterB, 5U)) + aWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterD, 53U)) + aOrbiterI);
            aWandererG = aWandererG + (((RotL64(aIngress, 11U) + aOrbiterD) + RotL64(aOrbiterF, 21U)) + RotL64(aCarry, 5U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterC, 60U)) + aOrbiterD);
            aWandererH = aWandererH + (((RotL64(aIngress, 41U) + aOrbiterB) + RotL64(aOrbiterC, 43U)) + aWandererUpdateSaltC[((aIndex + 22U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterK, 37U)) + aOrbiterI);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 21U) + RotL64(aOrbiterH, 27U)) + aOrbiterI) + RotL64(aCarry, 35U)) + aNonceWordI);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 28U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererG, 51U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererA, 57U);
            aCarry = aCarry + RotL64(aIngress, 22U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordF);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 21755U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneA[((aIndex + 21827U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 20347U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneC[((aIndex + 18615U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 19U) ^ RotL64(aIngress, 40U)) + (RotL64(aCross, 5U) + RotL64(aPrevious, 53U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (((aWandererC + RotL64(aPrevious, 57U)) + RotL64(aCarry, 37U)) + 8866844335448071821U) + aNonceWordE;
            aOrbiterD = (aWandererH + RotL64(aIngress, 22U)) + 15159698739856430085U;
            aOrbiterC = (aWandererI + RotL64(aScatter, 13U)) + 9582805772989594633U;
            aOrbiterE = (aWandererK + RotL64(aCross, 43U)) + 1438538239931588373U;
            aOrbiterG = ((aWandererD + RotL64(aIngress, 29U)) + 10862044156620436139U) + aOrbiterAssignSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = ((((aWandererE + RotL64(aScatter, 5U)) + RotL64(aCarry, 51U)) + 13682173320058164615U) + aOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordD;
            aOrbiterA = (((aWandererJ + RotL64(aCross, 37U)) + RotL64(aCarry, 21U)) + 8351013291045977592U) + aNonceWordB;
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 15777857431516633916U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 16178966745333885377U;
            aOrbiterC = RotL64((aOrbiterC * 7545129923202147703U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 9031889187993001617U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 6308472367425865347U) ^ aOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17118710301967158153U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 642109145903321046U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 9186268569255318035U) ^ aOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10714674348507516749U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 6091345356803675860U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 13218507921880873749U;
            aOrbiterE = RotL64((aOrbiterE * 15415157927185637717U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 4266652275234474616U) + aOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 4391422098164506195U;
            aOrbiterG = RotL64((aOrbiterG * 17634679403195085867U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 5160682323243635577U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 10351728852161347404U;
            aOrbiterH = RotL64((aOrbiterH * 11105410036471745951U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 3950932176454814023U) + aNonceWordN;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 9536466386833427441U;
            aOrbiterA = RotL64((aOrbiterA * 18064984243491293435U), 35U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterE, 29U);
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 3U));
            aIngress = aIngress + RotL64(aOrbiterC, 20U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aScatter, 57U) + aOrbiterA) + RotL64(aOrbiterH, 10U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 29U) + aOrbiterI) + RotL64(aOrbiterC, 3U));
            aWandererI = aWandererI + (((((RotL64(aPrevious, 51U) + RotL64(aOrbiterG, 51U)) + aOrbiterE) + RotL64(aCarry, 27U)) + aNonceWordJ) + aWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 21U) + aOrbiterG) + RotL64(aOrbiterI, 19U));
            aWandererD = aWandererD + (((RotL64(aScatter, 35U) + aOrbiterD) + RotL64(aOrbiterE, 43U)) + aWandererUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aCross, 12U) + RotL64(aOrbiterH, 29U)) + aOrbiterC) + aNonceWordA);
            aWandererH = aWandererH + (((RotL64(aIngress, 5U) + RotL64(aOrbiterD, 37U)) + aOrbiterC) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 60U) ^ aWandererJ);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + RotL64(aWandererH, 23U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordC);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 32010U)) & S_BLOCK1], 44U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 24609U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28515U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 27250U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 19U) ^ RotL64(aCarry, 56U)) + (RotL64(aPrevious, 5U) + RotL64(aCross, 35U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererI + RotL64(aIngress, 27U)) + RotL64(aCarry, 3U)) + 6469584119078165548U;
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 35U)) + 14329756366517987910U;
            aOrbiterH = (aWandererJ + RotL64(aCross, 4U)) + 12890831797059772123U;
            aOrbiterG = (aWandererH + RotL64(aScatter, 57U)) + 3164503807500018990U;
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 51U)) + RotL64(aCarry, 21U)) + 177531431387646836U;
            aOrbiterC = (((aWandererK + RotL64(aCross, 13U)) + 3167421392893561015U) + aOrbiterAssignSaltD[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterD = (((aWandererB + RotL64(aScatter, 21U)) + RotL64(aCarry, 37U)) + 2813174781844753460U) + aOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1];
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 10953270419153249857U) + aOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 16911518309710356951U;
            aOrbiterH = RotL64((aOrbiterH * 13162785997686570445U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 6616750447844893150U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 10276741398025985982U;
            aOrbiterC = RotL64((aOrbiterC * 6824712685896987133U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 6206043608461213208U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 12021552904553405793U) ^ aOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10023362889960174909U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 15283586234744144846U) + aNonceWordE;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 5923238786775948571U) ^ aNonceWordM;
            aOrbiterI = RotL64((aOrbiterI * 8200882393521882651U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 11044014510971660078U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 9351141024085076044U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13316079344614432317U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 17703395981862992420U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 10154548848376027087U;
            aOrbiterG = RotL64((aOrbiterG * 12324478347590509035U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 8836420852291617425U) + aNonceWordC;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 10193385413543886344U) ^ aOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 824935982418585449U), 35U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterC, 47U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 11U));
            aIngress = aIngress + (RotL64(aOrbiterK, 19U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterG, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aScatter, 43U) + RotL64(aOrbiterK, 11U)) + aOrbiterJ) + RotL64(aCarry, 37U)) + aWandererUpdateSaltA[((aIndex + 14U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterK, 3U)) + aOrbiterD) + aWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 27U) + aOrbiterC) + RotL64(aOrbiterG, 57U)) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 11U) + aOrbiterK) + RotL64(aOrbiterH, 51U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 34U) + RotL64(aOrbiterI, 36U)) + aOrbiterJ) + aNonceWordI);
            aWandererF = aWandererF ^ ((RotL64(aCross, 57U) + aOrbiterG) + RotL64(aOrbiterJ, 27U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 51U) + RotL64(aOrbiterJ, 43U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 18U));
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererB);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 53U));
            aCarry = aCarry + RotL64(aWandererH, 29U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordL);
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

void TwistExpander_BaseBall_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x86884916555B4BBFULL + 0x8F64DB8C51AF1600ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xB3BF19DFE5F50D4FULL + 0x9FB32FBE441D3845ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xAEDDA34C219E9B17ULL + 0xC8F5838207D522B9ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xB5A335F54AD8AA37ULL + 0x8349AF6EA0A9A821ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xA0E1AD9C8D6C1F89ULL + 0xD982F0DDBE624CA9ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xF1B542822ADFD92BULL + 0xD0243A84924D9B89ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xCDB48FE11C62F139ULL + 0x9974353EB76972FBULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xE5543801B4115AF9ULL + 0xA093CBFF4111D92EULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x807B033437C6FB77ULL + 0x874D6170AA12C14FULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xF9725740BB1132CDULL + 0xC0452921032C3F7EULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xCCE71A8A72EC3839ULL + 0xB99C1AA2A85C015AULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xF278AC4B9054AB97ULL + 0x871E56B458FEF36EULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xCDD18CAC19F45423ULL + 0xD642786D4705712CULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xF2FE5731ABD440A9ULL + 0xC094C73563016661ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xD85F5CF1476F9509ULL + 0xBEC0E1AE0F773B63ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xEAACA30D8ED82753ULL + 0xB24103683C5CFE17ULL);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 1350U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 13U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 7936U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((aIndex + 6779U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 60U) + RotL64(aIngress, 11U)) ^ (RotL64(aCross, 27U) + RotL64(aPrevious, 41U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (aWandererI + RotL64(aPrevious, 19U)) + 8375305456876489425U;
            aOrbiterH = (aWandererK + RotL64(aIngress, 51U)) + 16193562952772453047U;
            aOrbiterG = (aWandererF + RotL64(aCross, 37U)) + 18088652458594816223U;
            aOrbiterI = (((aWandererJ + RotL64(aScatter, 23U)) + RotL64(aCarry, 11U)) + 767344788620249944U) + aOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = ((aWandererB + RotL64(aCross, 13U)) + 7705194930396368752U) + aNonceWordI;
            aOrbiterC = (aWandererG + RotL64(aIngress, 34U)) + 3829736891311272834U;
            aOrbiterD = ((aWandererE + RotL64(aScatter, 21U)) + 9881681671347640061U) + aOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 47U)) + RotL64(aCarry, 21U)) + 1721196560190164264U;
            aOrbiterE = (aWandererD + RotL64(aIngress, 41U)) + 3002652618388454213U;
            aOrbiterJ = ((aWandererC + RotL64(aCross, 30U)) + RotL64(aCarry, 43U)) + 9811621464004005202U;
            aOrbiterK = (aWandererH + RotL64(aPrevious, 3U)) + 5652598941069986530U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 6250499348327316328U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 16025054277615264530U;
            aOrbiterG = RotL64((aOrbiterG * 16446892258704281903U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 13800298546867243172U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 12256104592865905782U;
            aOrbiterC = RotL64((aOrbiterC * 16983140179497142713U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 17817225416918329229U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 17738671327352776217U;
            aOrbiterB = RotL64((aOrbiterB * 393488251327705063U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 6816031224188400541U) + aNonceWordE;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 16989563985059237014U;
            aOrbiterI = RotL64((aOrbiterI * 8677884225771717797U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 16891524847268207549U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 1833508573940405571U;
            aOrbiterD = RotL64((aOrbiterD * 9709196587703979539U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 12729999421507068973U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 6839758643521968957U;
            aOrbiterE = RotL64((aOrbiterE * 16350557395881283975U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 8524167125469267428U) + aNonceWordH;
            aOrbiterK = (((aOrbiterK ^ aOrbiterA) ^ 14741523560290472617U) ^ aOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterK = RotL64((aOrbiterK * 4367850822282205897U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 10983798459868424892U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 5649250846622078964U;
            aOrbiterH = RotL64((aOrbiterH * 7149612714806023987U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 8587302028325090061U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 17457129226030333666U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 18107356450566915215U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 15600113588474915690U) + aOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 6595247491374683783U;
            aOrbiterF = RotL64((aOrbiterF * 1432432381540098765U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 13246325856585534283U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 8375305456876489425U;
            aOrbiterJ = RotL64((aOrbiterJ * 8331406038795786099U), 5U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterE, 27U);
            aIngress = aIngress + (RotL64(aOrbiterF, 38U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 21U));
            aIngress = aIngress + (RotL64(aOrbiterK, 53U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterI, 23U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterD, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterF, 6U)) + aOrbiterK);
            aWandererB = aWandererB + ((RotL64(aPrevious, 58U) + aOrbiterE) + RotL64(aOrbiterI, 11U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterC, 35U)) + aOrbiterJ);
            aWandererD = aWandererD + ((RotL64(aCross, 51U) + aOrbiterJ) + RotL64(aOrbiterA, 13U));
            aWandererH = aWandererH ^ ((((RotL64(aIngress, 47U) + RotL64(aOrbiterH, 43U)) + aOrbiterF) + aNonceWordK) + aWandererUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererF = aWandererF + (((((RotL64(aCross, 6U) + aOrbiterD) + RotL64(aOrbiterH, 21U)) + RotL64(aCarry, 41U)) + aNonceWordN) + aWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 41U) + aOrbiterE) + RotL64(aOrbiterA, 51U));
            aWandererK = aWandererK + ((RotL64(aScatter, 23U) + RotL64(aOrbiterI, 53U)) + aOrbiterF);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 37U) + aOrbiterB) + RotL64(aOrbiterJ, 47U)) + aNonceWordO);
            aWandererI = aWandererI + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterG, 57U)) + aOrbiterC) + RotL64(aCarry, 35U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 3U) + aOrbiterB) + RotL64(aOrbiterF, 26U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 54U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererK, 29U) ^ aWandererD);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + RotL64(aWandererG, 23U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ aNonceWordB;
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 15843U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneD[((aIndex + 9263U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 10102U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneB[((aIndex + 10857U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 53U)) + (RotL64(aCross, 40U) ^ RotL64(aIngress, 3U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (((aWandererG + RotL64(aScatter, 30U)) + RotL64(aCarry, 27U)) + 3917730204724097072U) + aOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = (aWandererH + RotL64(aIngress, 23U)) + 1874642340716212824U;
            aOrbiterC = ((aWandererI + RotL64(aCross, 19U)) + RotL64(aCarry, 11U)) + 6900165757434854160U;
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 3U)) + RotL64(aCarry, 47U)) + 12750946097023807161U;
            aOrbiterA = (aWandererC + RotL64(aIngress, 43U)) + 6563216048479513594U;
            aOrbiterG = (aWandererF + RotL64(aCross, 47U)) + 14960240191349450795U;
            aOrbiterJ = (aWandererA + RotL64(aScatter, 54U)) + 16306180275951788289U;
            aOrbiterH = (aWandererK + RotL64(aPrevious, 35U)) + 6502066618271045547U;
            aOrbiterB = (aWandererD + RotL64(aIngress, 51U)) + 6219852857850888738U;
            aOrbiterF = ((aWandererE + RotL64(aScatter, 27U)) + 2272931312452845850U) + aNonceWordI;
            aOrbiterK = (((aWandererJ + RotL64(aCross, 11U)) + 3028929882263199463U) + aOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordF;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 6067393030073568112U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 10094809900437037258U;
            aOrbiterC = RotL64((aOrbiterC * 18095564940730322769U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 5962414178157074575U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 15755563045799129417U;
            aOrbiterD = RotL64((aOrbiterD * 3692603590609922031U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 6321455513889880590U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 1197435601998121700U;
            aOrbiterA = RotL64((aOrbiterA * 17693996266260557625U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 12496949381666299968U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 6357070235648527030U;
            aOrbiterJ = RotL64((aOrbiterJ * 2931486644220862433U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 8423760160877540210U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 8090246492554850768U;
            aOrbiterB = RotL64((aOrbiterB * 2949407491181921633U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 11436635942985063755U) + aOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 17086363141014359856U) ^ aOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10504127577318206801U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 10734017887545474935U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 375515325165740779U;
            aOrbiterI = RotL64((aOrbiterI * 9980486695448151709U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 5217148491945389821U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 14696058217023530058U;
            aOrbiterG = RotL64((aOrbiterG * 11026674782236654799U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 11869055287836412650U) + aNonceWordH;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 16951500118659983436U;
            aOrbiterH = RotL64((aOrbiterH * 4304372681583055077U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 7866300390953569803U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 18017335943787362993U;
            aOrbiterF = RotL64((aOrbiterF * 15683049583437004889U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 2477944286851267725U) + aOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 3917730204724097072U;
            aOrbiterK = RotL64((aOrbiterK * 6617615984203047419U), 29U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterK, 57U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 19U));
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterE, 39U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterC, 60U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterG, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aCross, 46U) + RotL64(aOrbiterJ, 36U)) + aOrbiterH) + aWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aIngress, 5U) + RotL64(aOrbiterG, 11U)) + aOrbiterA) + RotL64(aCarry, 29U)) + aNonceWordG);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 27U) + aOrbiterJ) + RotL64(aOrbiterB, 47U));
            aWandererF = aWandererF + ((RotL64(aScatter, 57U) + RotL64(aOrbiterG, 27U)) + aOrbiterJ);
            aWandererC = aWandererC ^ (((RotL64(aCross, 43U) + aOrbiterG) + RotL64(aOrbiterK, 21U)) + aWandererUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 41U) + aOrbiterH) + RotL64(aOrbiterI, 5U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 52U) + aOrbiterF) + RotL64(aOrbiterG, 13U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 56U)) + aOrbiterF) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterA, 51U)) + aOrbiterD);
            aWandererB = aWandererB + (((RotL64(aScatter, 19U) + aOrbiterD) + RotL64(aOrbiterE, 19U)) + aNonceWordA);
            aWandererE = aWandererE ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterE, 29U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererC, 56U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererI);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + RotL64(aWandererK, 58U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ aNonceWordK;
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 24351U)) & S_BLOCK1], 38U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 22092U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 22688U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((aIndex + 23730U)) & S_BLOCK1], 34U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 35U) + RotL64(aCarry, 3U)) ^ (RotL64(aIngress, 20U) + RotL64(aCross, 53U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((aWandererD + RotL64(aIngress, 11U)) + RotL64(aCarry, 13U)) + 5960680319644404115U;
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 51U)) + 16050752633567034185U;
            aOrbiterI = ((aWandererA + RotL64(aScatter, 29U)) + 8447503223226854741U) + aOrbiterAssignSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterJ = (aWandererB + RotL64(aCross, 35U)) + 14176813813397917591U;
            aOrbiterC = (aWandererF + RotL64(aPrevious, 46U)) + 10534915376130006644U;
            aOrbiterF = ((((aWandererH + RotL64(aScatter, 37U)) + RotL64(aCarry, 57U)) + 6866224454375302514U) + aOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1]) + aNonceWordA;
            aOrbiterD = ((aWandererC + RotL64(aIngress, 53U)) + 16506374165041008396U) + aNonceWordL;
            aOrbiterG = ((aWandererK + RotL64(aCross, 19U)) + RotL64(aCarry, 27U)) + 7167814023968794098U;
            aOrbiterH = (aWandererE + RotL64(aIngress, 3U)) + 13870852197416596664U;
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 22U)) + 18064038854848993105U) + aNonceWordH;
            aOrbiterK = (aWandererG + RotL64(aCross, 43U)) + 9869630811507771691U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 863613100452759380U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 16597969741225436529U;
            aOrbiterI = RotL64((aOrbiterI * 2680793528887208903U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 6575347108051310653U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 17062262265485019063U) ^ aOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7601045488473620019U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 7193399224636409133U) + aNonceWordN;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 14146747818810433849U;
            aOrbiterE = RotL64((aOrbiterE * 5273185769989530041U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 9441449106442431427U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 4303295336545399503U) ^ aNonceWordG;
            aOrbiterC = RotL64((aOrbiterC * 8829695296836242587U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 12604760768543193458U) + aNonceWordC;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 15779327512379787715U;
            aOrbiterG = RotL64((aOrbiterG * 14000905201441272597U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 15553000781122708728U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 17162740616060079717U;
            aOrbiterB = RotL64((aOrbiterB * 9458662233556750239U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 1032374679817715156U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 16413393156165548232U;
            aOrbiterA = RotL64((aOrbiterA * 549659738811935015U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 14056855000013992045U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 7399202019042538829U;
            aOrbiterJ = RotL64((aOrbiterJ * 6103508549612077695U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 2218389473339103389U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 4679497280975967770U;
            aOrbiterD = RotL64((aOrbiterD * 9228353578259815023U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 7620538119914173747U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 3118355627808424159U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12481319980496032783U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 16787092219237931175U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 5960680319644404115U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10727217147056112401U), 11U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterE, 46U);
            aIngress = aIngress + (RotL64(aOrbiterK, 37U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 21U));
            aIngress = aIngress + (RotL64(aOrbiterA, 29U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterB, 27U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterH, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterD, 28U)) + aOrbiterG);
            aWandererB = aWandererB + ((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 39U)) + aOrbiterH);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 35U) + aOrbiterJ) + RotL64(aOrbiterE, 37U)) + aWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aScatter, 21U) + RotL64(aOrbiterI, 43U)) + aOrbiterG) + RotL64(aCarry, 37U)) + aNonceWordM);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterB, 47U)) + aOrbiterK);
            aWandererD = aWandererD + ((RotL64(aScatter, 48U) + aOrbiterJ) + RotL64(aOrbiterC, 41U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 53U) + aOrbiterE) + RotL64(aOrbiterF, 10U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterB, 5U)) + aOrbiterA) + aWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 29U) + aOrbiterB) + RotL64(aOrbiterH, 53U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterH, 3U)) + aOrbiterG) + RotL64(aCarry, 53U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 26U) + aOrbiterF) + RotL64(aOrbiterA, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 14U) ^ aWandererK);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 37U));
            aCarry = aCarry + RotL64(aWandererA, 56U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ aNonceWordP;
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 29330U)) & S_BLOCK1], 24U) ^ RotL64(aOperationLaneB[((aIndex + 32108U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 29478U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 30257U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 6U) + RotL64(aCarry, 27U)) + (RotL64(aCross, 57U) ^ RotL64(aPrevious, 41U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (aWandererA + RotL64(aPrevious, 48U)) + 12849591986267890852U;
            aOrbiterB = (aWandererK + RotL64(aIngress, 57U)) + 8232614804696815750U;
            aOrbiterA = (aWandererF + RotL64(aScatter, 27U)) + 12141567259210877281U;
            aOrbiterH = (aWandererI + RotL64(aCross, 35U)) + 2928641981037885644U;
            aOrbiterJ = (aWandererE + RotL64(aScatter, 11U)) + 980733350554783938U;
            aOrbiterE = (aWandererG + RotL64(aIngress, 19U)) + 2683985177993350746U;
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 54U)) + RotL64(aCarry, 57U)) + 14532148403815527355U;
            aOrbiterI = ((aWandererD + RotL64(aCross, 13U)) + RotL64(aCarry, 35U)) + 7736296629433884203U;
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 21U)) + RotL64(aCarry, 39U)) + 10428437770166310549U;
            aOrbiterD = (((aWandererB + RotL64(aCross, 23U)) + 18327174144859461029U) + aOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordN;
            aOrbiterG = ((aWandererH + RotL64(aScatter, 43U)) + 6810436935194432002U) + aOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 12606153309690753435U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 17123256945895150555U;
            aOrbiterA = RotL64((aOrbiterA * 13469111258504672565U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 9057777759026189541U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 16478485918911194442U;
            aOrbiterJ = RotL64((aOrbiterJ * 11054247078884894131U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 18064460487552100483U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 11477276762421684083U;
            aOrbiterE = RotL64((aOrbiterE * 3886501230380184395U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 18318375441973295081U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 13849305985380030986U;
            aOrbiterK = RotL64((aOrbiterK * 12962140243967824959U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 10240409420338313641U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 18360586077779529086U;
            aOrbiterI = RotL64((aOrbiterI * 18196875422391501927U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 16801797158622424257U) + aOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 4950305991208513887U;
            aOrbiterC = RotL64((aOrbiterC * 4437082499761416951U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 15790878572843321918U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 9808781805065559728U;
            aOrbiterD = RotL64((aOrbiterD * 9394280083159162953U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 11974996650410830731U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 4955004489435232515U;
            aOrbiterG = RotL64((aOrbiterG * 13301966529515483085U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 1187569634223338864U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 5351017164244226367U;
            aOrbiterF = RotL64((aOrbiterF * 14735674576470803699U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 9587142385246940125U) + aNonceWordD;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 16253850371962732943U;
            aOrbiterB = RotL64((aOrbiterB * 3408021872390904463U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 14990060157351237661U) + aOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 12849591986267890852U;
            aOrbiterH = RotL64((aOrbiterH * 2158106726261981983U), 23U);
            //
            aIngress = RotL64(aOrbiterE, 3U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterK, 21U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 35U));
            aIngress = aIngress + (RotL64(aOrbiterB, 30U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterI, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aCross, 39U) + aOrbiterF) + RotL64(aOrbiterE, 51U));
            aWandererG = aWandererG ^ ((((RotL64(aIngress, 22U) + RotL64(aOrbiterD, 26U)) + aOrbiterG) + aNonceWordL) + aWandererUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterK, 41U)) + aOrbiterI) + RotL64(aCarry, 3U)) + aWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterB, 3U)) + aOrbiterG);
            aWandererI = aWandererI + (((RotL64(aIngress, 51U) + aOrbiterG) + RotL64(aOrbiterI, 37U)) + RotL64(aCarry, 47U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 53U) + aOrbiterC) + RotL64(aOrbiterI, 18U));
            aWandererD = aWandererD + ((RotL64(aScatter, 28U) + aOrbiterI) + RotL64(aOrbiterA, 23U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterF, 5U)) + aOrbiterK);
            aWandererC = aWandererC + ((RotL64(aScatter, 19U) + aOrbiterF) + RotL64(aOrbiterC, 53U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterD, 57U)) + aOrbiterH);
            aWandererB = aWandererB + ((RotL64(aIngress, 3U) + aOrbiterJ) + RotL64(aOrbiterE, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererF, 27U) ^ aWandererI);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 54U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererH, 5U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ aNonceWordD;
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

void TwistExpander_BaseBall_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xA6BFD1606C997AD5ULL + 0x91ED5A43891A30B5ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x9D0B294FA1BE83B7ULL + 0xB8354879E0B02CA8ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xFE2B04232DA36AA1ULL + 0xF24E042089D2C043ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xDC7E9758F6682991ULL + 0xC46F8AEF8D36113AULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xEF281907090CF767ULL + 0xB353ADAD0268374CULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xD264A5665D99407DULL + 0x8607F51B7F3E3936ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xF9CCC8FF5945F40DULL + 0xFDF19A209538A5FCULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x85518C64450C4023ULL + 0x8C2F0EE18D38EA81ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xBC885ED1A3D9E2EDULL + 0xE00600EFD0589280ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xC2CB531C71D56D59ULL + 0xCD4FE3D4D76CA0FCULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xE704A430A6226CEFULL + 0xA0B28D6BE21597DDULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x8FFDE1D7E3EFEEE9ULL + 0xA0DC7A29BC83EA46ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xFFA41F22F2B5F377ULL + 0xACF844CAB83F52C9ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xBBDAD244787A23E9ULL + 0xA134EF3D33704EC3ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xFC6E465B514345AFULL + 0xE106A4F1C2AB27A4ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xC203A5694F23D8C1ULL + 0xBE0B49AB748DF7CAULL);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 4542U)) & S_BLOCK1], 30U) ^ RotL64(aOperationLaneC[((aIndex + 5420U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 4449U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneA[((aIndex + 2892U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 39U) + RotL64(aCarry, 23U)) + (RotL64(aCross, 6U) ^ RotL64(aPrevious, 51U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererJ + RotL64(aScatter, 23U)) + 15652862298542575895U;
            aOrbiterJ = (aWandererD + RotL64(aCross, 19U)) + 16925323928418184554U;
            aOrbiterC = (aWandererG + RotL64(aIngress, 13U)) + 4413861484961668394U;
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 46U)) + 2215946422098155969U) + aNonceWordK;
            aOrbiterD = (aWandererC + RotL64(aScatter, 5U)) + 14975185533513111110U;
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 27U)) + RotL64(aCarry, 3U)) + 9711613814905834552U;
            aOrbiterH = ((((aWandererF + RotL64(aIngress, 41U)) + RotL64(aCarry, 13U)) + 13154957291850149471U) + aOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1]) + aNonceWordF;
            aOrbiterI = ((((aWandererI + RotL64(aCross, 37U)) + RotL64(aCarry, 27U)) + 5058313016418534840U) + aOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordI;
            aOrbiterG = (aWandererB + RotL64(aPrevious, 52U)) + 15011423472941211620U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 2030053257469580168U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 150530795186791193U;
            aOrbiterC = RotL64((aOrbiterC * 11106050063717096073U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 10878237472104183427U) + aOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 11724672539469573109U) ^ aOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16158741837357985395U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 9589700906445846956U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 1367381624958248949U;
            aOrbiterI = RotL64((aOrbiterI * 8459515089081211977U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 12003215666757518106U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 11232479330848006729U;
            aOrbiterG = RotL64((aOrbiterG * 10993290955464593033U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 13013910456628561621U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 6092509838924105265U) ^ aNonceWordB;
            aOrbiterE = RotL64((aOrbiterE * 805601154718006061U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 11999225836250312801U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterC) ^ 14421271973875748413U) ^ aOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterA = RotL64((aOrbiterA * 9529010940887430157U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 15536288285741825272U) + aOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 2071793889925436679U;
            aOrbiterH = RotL64((aOrbiterH * 1526376970151714589U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 5622386476463436967U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 16147972771639168516U;
            aOrbiterJ = RotL64((aOrbiterJ * 11826916832825159095U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 4519892856053952290U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 12059500374938843538U) ^ aNonceWordG;
            aOrbiterD = RotL64((aOrbiterD * 14987533625537956299U), 47U);
            //
            aIngress = RotL64(aOrbiterK, 58U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterH, 27U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 41U));
            aIngress = aIngress + (RotL64(aOrbiterA, 35U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterI, 14U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aPrevious, 28U) + aOrbiterH) + RotL64(aOrbiterJ, 13U)) + aWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 51U) + aOrbiterG) + RotL64(aOrbiterJ, 43U));
            aWandererC = aWandererC + (((RotL64(aCross, 43U) + aOrbiterC) + RotL64(aOrbiterH, 57U)) + RotL64(aCarry, 21U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterJ, 34U)) + aOrbiterD) + aNonceWordO);
            aWandererH = aWandererH + (((RotL64(aScatter, 47U) + RotL64(aOrbiterG, 19U)) + aOrbiterD) + aNonceWordD);
            aWandererB = aWandererB ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterH, 47U)) + aOrbiterI) + aNonceWordJ);
            aWandererK = aWandererK + (((RotL64(aIngress, 5U) + aOrbiterH) + RotL64(aOrbiterA, 27U)) + aWandererUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 20U) + aOrbiterE) + RotL64(aOrbiterG, 3U));
            aWandererD = aWandererD + (((RotL64(aScatter, 57U) + RotL64(aOrbiterH, 38U)) + aOrbiterK) + RotL64(aCarry, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + (RotL64(aWandererB, 24U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererK, 13U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordP);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 5745U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 5470U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 8234U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneB[((aIndex + 9919U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 27U) ^ RotL64(aCarry, 60U)) ^ (RotL64(aPrevious, 11U) + RotL64(aCross, 39U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (aWandererI + RotL64(aIngress, 3U)) + 8767379393098711499U;
            aOrbiterI = ((aWandererD + RotL64(aCross, 57U)) + RotL64(aCarry, 43U)) + 7168159491580816433U;
            aOrbiterB = (aWandererG + RotL64(aPrevious, 30U)) + 9879279829061883406U;
            aOrbiterE = (((aWandererF + RotL64(aScatter, 51U)) + RotL64(aCarry, 57U)) + 10537167136053399303U) + aOrbiterAssignSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = ((aWandererB + RotL64(aIngress, 21U)) + 2839070018069188936U) + aNonceWordN;
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 41U)) + RotL64(aCarry, 27U)) + 13844278063968429732U;
            aOrbiterJ = (aWandererH + RotL64(aScatter, 47U)) + 11278946626186474646U;
            aOrbiterG = ((aWandererE + RotL64(aCross, 12U)) + 11798425216660557799U) + aNonceWordG;
            aOrbiterD = ((aWandererA + RotL64(aIngress, 35U)) + 7618446090703335192U) + aOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 695423597006983660U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 14344728202803488813U;
            aOrbiterB = RotL64((aOrbiterB * 5168825904902285909U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 11656100506575697086U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 10384358779985773937U) ^ aNonceWordI;
            aOrbiterH = RotL64((aOrbiterH * 247494692039140973U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 17585001605131977341U) + aOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 9964478171465522911U;
            aOrbiterJ = RotL64((aOrbiterJ * 13484044854790175315U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 2710943171829692624U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 17809072853457153057U;
            aOrbiterG = RotL64((aOrbiterG * 16341884203303271365U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 12814092033910687774U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 1743186323268668740U;
            aOrbiterD = RotL64((aOrbiterD * 11150822630624332557U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 10750472346626754704U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 15925901217078035356U;
            aOrbiterF = RotL64((aOrbiterF * 9276504171291801637U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 2569102106359362359U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 8868261301410769739U;
            aOrbiterE = RotL64((aOrbiterE * 3662495603133918101U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 2143691008373582476U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 10606616796243205921U;
            aOrbiterA = RotL64((aOrbiterA * 15794414817813485643U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 16258070651850746855U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 11720192793689633315U) ^ aOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14475623219460678021U), 13U);
            //
            aIngress = RotL64(aOrbiterE, 43U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterJ, 27U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterG, 11U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterD, 30U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterF, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aCross, 23U) + aOrbiterB) + RotL64(aOrbiterJ, 19U)) + aNonceWordB);
            aWandererD = aWandererD + ((((RotL64(aScatter, 51U) + aOrbiterF) + RotL64(aOrbiterA, 14U)) + RotL64(aCarry, 37U)) + aWandererUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 46U) + aOrbiterE) + RotL64(aOrbiterI, 47U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 41U) + aOrbiterG) + RotL64(aOrbiterE, 57U)) + RotL64(aCarry, 51U));
            aWandererG = aWandererG ^ ((((RotL64(aScatter, 19U) + aOrbiterF) + RotL64(aOrbiterJ, 23U)) + aNonceWordJ) + aWandererUpdateSaltB[((aIndex + 10U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 37U) + RotL64(aOrbiterD, 35U)) + aOrbiterA);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 57U) + aOrbiterG) + RotL64(aOrbiterH, 51U));
            aWandererA = aWandererA + (((RotL64(aCross, 12U) + aOrbiterA) + RotL64(aOrbiterH, 43U)) + aNonceWordL);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 3U) + aOrbiterB) + RotL64(aOrbiterA, 28U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererK);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 60U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordH);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 16241U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((aIndex + 15650U)) & S_BLOCK1], 10U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 14181U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 15829U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 34U) + RotL64(aCarry, 19U)) + (RotL64(aPrevious, 57U) ^ RotL64(aCross, 5U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (((aWandererJ + RotL64(aScatter, 28U)) + RotL64(aCarry, 11U)) + 4476099022490972343U) + aNonceWordF;
            aOrbiterB = (aWandererE + RotL64(aIngress, 57U)) + 16836423700375760429U;
            aOrbiterF = (aWandererG + RotL64(aPrevious, 35U)) + 8850577488928703557U;
            aOrbiterH = (aWandererC + RotL64(aCross, 39U)) + 7091631824560042743U;
            aOrbiterI = ((aWandererD + RotL64(aPrevious, 18U)) + RotL64(aCarry, 47U)) + 12560498899956759494U;
            aOrbiterG = ((aWandererK + RotL64(aScatter, 5U)) + 7797973377112012161U) + aNonceWordK;
            aOrbiterA = (((aWandererB + RotL64(aIngress, 13U)) + 6173820673874805794U) + aOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1]) + aNonceWordP;
            aOrbiterE = ((aWandererH + RotL64(aCross, 47U)) + RotL64(aCarry, 27U)) + 10805025132310245348U;
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 53U)) + 7139216143268029968U) + aOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 8241544862261635722U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 4735527016563596150U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6621354217673598381U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 5166171126690294033U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 11117641762075368393U) ^ aOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4980156869201219393U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 6312932356458415421U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 1304139291184508668U;
            aOrbiterH = RotL64((aOrbiterH * 90744653170922319U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 10085025354842771067U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 16745854428789531080U;
            aOrbiterB = RotL64((aOrbiterB * 1945983905747274355U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 2497187958708890337U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 16069701876646548995U;
            aOrbiterI = RotL64((aOrbiterI * 16606039730973709495U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 17242004368025978091U) + aNonceWordL;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 12334315722243232121U;
            aOrbiterG = RotL64((aOrbiterG * 16528598396696346719U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 8007042082518126895U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterE) ^ 5665686359038811484U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterA = RotL64((aOrbiterA * 11289316305875751813U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 3913477186958600592U) + aNonceWordN;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 16918984318564170343U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5128293326494417281U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 10227611546502931418U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 7187623463085447228U;
            aOrbiterJ = RotL64((aOrbiterJ * 8479839369622163181U), 51U);
            //
            aIngress = RotL64(aOrbiterA, 58U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 5U));
            aIngress = aIngress + (RotL64(aOrbiterG, 35U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterJ, 11U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterH, 26U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 10U) + aOrbiterH) + RotL64(aOrbiterB, 35U));
            aWandererG = aWandererG + (((RotL64(aIngress, 3U) + RotL64(aOrbiterB, 27U)) + aOrbiterA) + RotL64(aCarry, 3U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 19U) + aOrbiterE) + RotL64(aOrbiterK, 4U)) + aNonceWordO);
            aWandererK = aWandererK + (((RotL64(aScatter, 53U) + RotL64(aOrbiterE, 39U)) + aOrbiterJ) + RotL64(aCarry, 41U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 47U) + aOrbiterE) + RotL64(aOrbiterG, 23U));
            aWandererH = aWandererH + ((RotL64(aScatter, 58U) + RotL64(aOrbiterG, 51U)) + aOrbiterJ);
            aWandererB = aWandererB ^ ((((RotL64(aPrevious, 41U) + RotL64(aOrbiterI, 19U)) + aOrbiterH) + aNonceWordM) + aWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 35U) + aOrbiterK) + RotL64(aOrbiterF, 46U)) + aWandererUpdateSaltF[((aIndex + 10U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterH, 11U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 41U));
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + (RotL64(aWandererE, 10U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererB, 23U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ aNonceWordH;
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 20879U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 18982U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20512U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 19150U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 3U) ^ RotL64(aIngress, 22U)) + (RotL64(aCarry, 35U) + RotL64(aPrevious, 47U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererB + RotL64(aCross, 39U)) + 13499155707765393469U;
            aOrbiterB = (aWandererE + RotL64(aPrevious, 48U)) + 3740324981823726185U;
            aOrbiterC = (aWandererK + RotL64(aScatter, 35U)) + 5470765363949735652U;
            aOrbiterK = ((aWandererC + RotL64(aIngress, 21U)) + RotL64(aCarry, 35U)) + 3446436171274452326U;
            aOrbiterI = ((((aWandererG + RotL64(aScatter, 57U)) + RotL64(aCarry, 43U)) + 1778929412631211933U) + aOrbiterAssignSaltA[((aIndex + 14U)) & S_SALT1]) + aNonceWordD;
            aOrbiterA = (((aWandererD + RotL64(aPrevious, 5U)) + 14666308799855220954U) + aOrbiterAssignSaltF[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordI;
            aOrbiterD = (aWandererF + RotL64(aIngress, 27U)) + 4548410236791175055U;
            aOrbiterE = (aWandererI + RotL64(aCross, 10U)) + 5829739767694190372U;
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 43U)) + RotL64(aCarry, 21U)) + 14319231414903675748U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 1513851750246111405U) + aNonceWordO;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 1685620217748986019U;
            aOrbiterC = RotL64((aOrbiterC * 9286548037413609445U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 16284162182006054402U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 6271539598462003309U;
            aOrbiterI = RotL64((aOrbiterI * 13923286694131331137U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 12669312437565969473U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 11894755313393001665U;
            aOrbiterD = RotL64((aOrbiterD * 12556759675372354075U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 6315983824634946566U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 17106616474222892782U) ^ aOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 167205520766791073U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 13350266700180455548U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 4608846311203767162U;
            aOrbiterK = RotL64((aOrbiterK * 2504857468837437365U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 14195866746143604365U) + aNonceWordH;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 7917977448256795054U;
            aOrbiterA = RotL64((aOrbiterA * 5927771378657284557U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 10707336923305131629U) + aOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 17122696159336995392U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13953518568670659191U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 5182322763573586116U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 6503754948502556246U;
            aOrbiterG = RotL64((aOrbiterG * 14749002194140663519U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 14907832047832987341U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 6258064448676621346U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4407960312705621487U), 51U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterE, 43U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 51U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 24U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 19U));
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterJ, 3U)) + aOrbiterK);
            aWandererC = aWandererC + ((((RotL64(aIngress, 5U) + aOrbiterB) + RotL64(aOrbiterC, 51U)) + RotL64(aCarry, 57U)) + aWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 23U) + aOrbiterE) + RotL64(aOrbiterA, 18U));
            aWandererI = aWandererI + ((RotL64(aScatter, 12U) + RotL64(aOrbiterB, 47U)) + aOrbiterJ);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterE, 27U)) + aOrbiterG) + aWandererUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 19U) + RotL64(aOrbiterC, 35U)) + aOrbiterE);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterA, 23U)) + aOrbiterD) + aNonceWordB);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 34U) + aOrbiterE) + RotL64(aOrbiterI, 10U)) + RotL64(aCarry, 13U)) + aNonceWordA);
            aWandererB = aWandererB ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterJ, 57U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 34U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 37U));
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererG, 5U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = aCarry ^ aNonceWordE;
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22560U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneA[((aIndex + 23336U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26893U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26758U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCarry, 12U)) ^ (RotL64(aCross, 27U) ^ RotL64(aPrevious, 41U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (aWandererC + RotL64(aScatter, 43U)) + 1708250618750199233U;
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 60U)) + RotL64(aCarry, 47U)) + 12009147777553691142U;
            aOrbiterE = (((aWandererF + RotL64(aCross, 37U)) + RotL64(aCarry, 19U)) + 8393982703399156592U) + aNonceWordO;
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 29U)) + RotL64(aCarry, 39U)) + 3247327098356831221U;
            aOrbiterD = (aWandererG + RotL64(aPrevious, 21U)) + 3403590155376353737U;
            aOrbiterI = (((aWandererH + RotL64(aIngress, 3U)) + 18197244558104735044U) + aOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1]) + aNonceWordK;
            aOrbiterB = (aWandererE + RotL64(aScatter, 47U)) + 3096253642040701606U;
            aOrbiterK = (aWandererI + RotL64(aCross, 51U)) + 8012692688785412179U;
            aOrbiterH = ((aWandererB + RotL64(aScatter, 10U)) + 17531946907545680745U) + aOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 17687695944270225817U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 16147773866007628769U;
            aOrbiterE = RotL64((aOrbiterE * 16926442582711557877U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 18244641303026196497U) + aNonceWordE;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 8839160526348897457U;
            aOrbiterI = RotL64((aOrbiterI * 14268021129087663397U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 10599266240854068246U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 2056723540756216155U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13311591601230386375U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 4629354220460621284U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 9505955649473204942U;
            aOrbiterH = RotL64((aOrbiterH * 17775391885312236187U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 17078153810088721310U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 9470436761716263000U) ^ aNonceWordN;
            aOrbiterC = RotL64((aOrbiterC * 5431855497250357229U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 3305863413630104742U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 14377172434239576161U) ^ aOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6880176890091033423U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 415687827894226513U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 16975319836893760993U;
            aOrbiterB = RotL64((aOrbiterB * 6597144958013976445U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 12707054129431596074U) + aOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 8974182792497231239U;
            aOrbiterF = RotL64((aOrbiterF * 7874658957269462717U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 10826131924322955095U) + aOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 4168545139712703154U;
            aOrbiterD = RotL64((aOrbiterD * 10305904857550051705U), 47U);
            //
            aIngress = RotL64(aOrbiterD, 11U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 5U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 50U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterK, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((((RotL64(aCross, 4U) + RotL64(aOrbiterJ, 51U)) + aOrbiterB) + RotL64(aCarry, 51U)) + aNonceWordH) + aWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterK, 57U)) + aOrbiterF);
            aWandererB = aWandererB + ((RotL64(aIngress, 35U) + aOrbiterC) + RotL64(aOrbiterD, 18U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 57U) + aOrbiterE) + RotL64(aOrbiterB, 23U));
            aWandererH = aWandererH + (((RotL64(aIngress, 29U) + aOrbiterE) + RotL64(aOrbiterI, 35U)) + aNonceWordF);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 39U) + aOrbiterH) + RotL64(aOrbiterI, 47U));
            aWandererE = aWandererE + ((RotL64(aCross, 51U) + RotL64(aOrbiterE, 5U)) + aOrbiterJ);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterD, 28U)) + aOrbiterK);
            aWandererI = aWandererI + ((((RotL64(aScatter, 24U) + RotL64(aOrbiterF, 11U)) + aOrbiterE) + RotL64(aCarry, 23U)) + aWandererUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + (RotL64(aWandererH, 20U) ^ aWandererB);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 51U));
            aCarry = aCarry + RotL64(aWandererJ, 27U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ aNonceWordC;
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 28755U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28193U)) & S_BLOCK1], 34U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30807U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((aIndex + 31970U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 3U) ^ RotL64(aPrevious, 54U)) ^ (RotL64(aCarry, 35U) + RotL64(aIngress, 19U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = ((aWandererD + RotL64(aCross, 11U)) + RotL64(aCarry, 47U)) + 12809562813316740345U;
            aOrbiterK = (aWandererC + RotL64(aScatter, 5U)) + 17084212535326321199U;
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 39U)) + RotL64(aCarry, 23U)) + 16074921689983846769U;
            aOrbiterD = (aWandererI + RotL64(aIngress, 19U)) + 14027986153007120145U;
            aOrbiterI = (aWandererJ + RotL64(aCross, 30U)) + 7633455951809250227U;
            aOrbiterB = ((aWandererE + RotL64(aScatter, 35U)) + 340989348513370174U) + aNonceWordB;
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 53U)) + 5307820377645020116U) + aOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = ((aWandererG + RotL64(aIngress, 47U)) + 5605285015771527274U) + aNonceWordO;
            aOrbiterC = (((aWandererB + RotL64(aScatter, 58U)) + RotL64(aCarry, 11U)) + 5293500434746182790U) + aOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 7263156475892261811U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 10672879570907433005U;
            aOrbiterJ = RotL64((aOrbiterJ * 2506338667179450741U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 16659226780900986107U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 9774892622769850665U;
            aOrbiterI = RotL64((aOrbiterI * 7487477727543183211U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 10728057184108279042U) + aOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 5032485856947407217U) ^ aNonceWordJ;
            aOrbiterA = RotL64((aOrbiterA * 16651577903809154285U), 19U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterA) + 14642241075374862345U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordD;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 8386481273395203518U;
            aOrbiterF = RotL64((aOrbiterF * 11649977733867003445U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 2874153265304098104U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 11519900149177261000U;
            aOrbiterC = RotL64((aOrbiterC * 2010158758971864505U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 8885690878540115768U) + aOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 4482143389870987714U;
            aOrbiterG = RotL64((aOrbiterG * 7105332459437434281U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 17469068567801886615U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 5121422018622394837U;
            aOrbiterD = RotL64((aOrbiterD * 14823827133212643467U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 3130788210672745618U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 6139244627510113216U;
            aOrbiterB = RotL64((aOrbiterB * 2640754184921507389U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 10488511756324474710U) + aNonceWordC;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 1760223670304953696U;
            aOrbiterK = RotL64((aOrbiterK * 4007062295003769311U), 53U);
            //
            aIngress = RotL64(aOrbiterF, 42U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterI, 19U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 27U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterD, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 14U) + RotL64(aOrbiterK, 41U)) + aOrbiterF);
            aWandererD = aWandererD + (((((RotL64(aCross, 29U) + aOrbiterK) + RotL64(aOrbiterB, 58U)) + RotL64(aCarry, 41U)) + aNonceWordI) + aWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 5U) + aOrbiterJ) + RotL64(aOrbiterD, 47U));
            aWandererK = aWandererK + (((RotL64(aScatter, 35U) + RotL64(aOrbiterF, 27U)) + aOrbiterJ) + RotL64(aCarry, 11U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 51U) + aOrbiterB) + RotL64(aOrbiterD, 23U)) + aNonceWordF);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 39U) + RotL64(aOrbiterD, 5U)) + aOrbiterG);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 43U) + aOrbiterD) + RotL64(aOrbiterC, 34U));
            aWandererG = aWandererG + ((((RotL64(aScatter, 47U) + RotL64(aOrbiterB, 13U)) + aOrbiterA) + aNonceWordN) + aWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 58U) + RotL64(aOrbiterI, 53U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 30U));
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 11U));
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererJ, 27U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ aNonceWordA;
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

void TwistExpander_BaseBall_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xD7E11B2EB8FAA8BDULL + 0xCF0E629800A4B0B8ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x96160EFEE22C9B4BULL + 0xF8A517CFF680CBEEULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xEBCF8CCAAE2B528BULL + 0xA720912C6BB874CDULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xA738416B4687953FULL + 0x8D4D76D240EDF54DULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x9C42FDA132BD3C97ULL + 0x92DDC7E7F758EDDCULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xE6CD1775A21898E1ULL + 0xDA965645FD95C686ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xACBCEA583A4E6C49ULL + 0xDDAF7A3A8F96CC5CULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xC444D520D9E811B7ULL + 0x8DB7752BB270B2F6ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xBEBA70C0F410691FULL + 0xFADD8A3C6BC3BDB2ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xFAB79D6E482AAEDBULL + 0xC3E84F8E670B40D4ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xC175A3D46E97B96FULL + 0xC76BB7BD1F2077BDULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xBBC84948DEC8E21BULL + 0xAE4E295C7D0464C6ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xB1D835BBEEB1CE83ULL + 0xC4AF7E65961761B4ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xCADB73CC697C36AFULL + 0xF08336E13A2161EDULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xF7E0F476A424BEB5ULL + 0x800012B3888943B2ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xD7B04632AF13C91BULL + 0x9F12F39980587006ULL);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 3476U)) & S_BLOCK1], 35U) ^ RotL64(aKeyRowReadA[((aIndex + 877U)) & W_KEY1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 3428U)) & W_KEY1], 13U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 2817U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 19U) ^ RotL64(aPrevious, 52U)) ^ (RotL64(aCarry, 3U) + RotL64(aIngress, 35U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterK = (aWandererA + RotL64(aIngress, 43U)) + 17074147006464019918U;
            aOrbiterD = (aWandererB + RotL64(aPrevious, 14U)) + 10559516626129419928U;
            aOrbiterE = ((aWandererD + RotL64(aCross, 57U)) + 13280363679503946221U) + aNonceWordO;
            aOrbiterI = (((aWandererI + RotL64(aScatter, 51U)) + RotL64(aCarry, 11U)) + 17657115422132457413U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = ((aWandererF + RotL64(aCross, 5U)) + RotL64(aCarry, 27U)) + 13325837013304973008U;
            aOrbiterB = (((aWandererG + RotL64(aScatter, 37U)) + 3059707750486106037U) + aPhaseAOrbiterAssignSaltE[((aIndex + 22U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterC = (((aWandererJ + RotL64(aIngress, 29U)) + RotL64(aCarry, 57U)) + 4529045702503050852U) + aNonceWordA;
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 10726578475550904292U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 14832537837996659885U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 808060368961520519U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 220094417441809246U) + aNonceWordP;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 15343130035105342194U;
            aOrbiterH = RotL64((aOrbiterH * 7984652435043810845U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 16592263353426409884U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 15649290906447931918U;
            aOrbiterB = RotL64((aOrbiterB * 8405875177836650731U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 11437410545843708269U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 5859769136073011444U) ^ aNonceWordB;
            aOrbiterC = RotL64((aOrbiterC * 1065016088086441107U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 15188064100307340341U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 4367466521843260049U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15916715854192820923U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 8482617283860566845U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 2585745804937342972U;
            aOrbiterI = RotL64((aOrbiterI * 8267269625632139809U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 1687641344403425541U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 13667916445979421400U;
            aOrbiterD = RotL64((aOrbiterD * 8191322670355590027U), 3U);
            //
            aIngress = RotL64(aOrbiterC, 53U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterD, 21U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 34U));
            aIngress = aIngress + RotL64(aOrbiterE, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 51U) + aOrbiterC) + RotL64(aOrbiterE, 41U));
            aWandererB = aWandererB + ((((RotL64(aCross, 4U) + aOrbiterE) + RotL64(aOrbiterK, 57U)) + RotL64(aCarry, 51U)) + aPhaseAWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 21U) + aOrbiterI) + RotL64(aOrbiterB, 5U)) + aNonceWordD) + aPhaseAWandererUpdateSaltE[((aIndex + 6U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterH, 19U)) + aOrbiterD) + RotL64(aCarry, 19U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 41U) + aOrbiterH) + RotL64(aOrbiterC, 27U)) + aNonceWordG);
            aWandererI = aWandererI + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterD, 51U)) + aOrbiterB);
            aWandererF = aWandererF ^ ((RotL64(aCross, 13U) + aOrbiterI) + RotL64(aOrbiterC, 12U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererI);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 28U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + RotL64(aWandererJ, 37U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ aNonceWordD;
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8294U)) & S_BLOCK1], 51U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 7588U)) & S_BLOCK1], 30U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 10434U)) & W_KEY1], 47U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 8861U)) & W_KEY1], 13U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 26U) + RotL64(aCross, 57U)) ^ (RotL64(aCarry, 39U) + RotL64(aIngress, 5U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterH = (((aWandererF + RotL64(aScatter, 5U)) + 7270044678408187242U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordD;
            aOrbiterI = (((aWandererA + RotL64(aIngress, 51U)) + RotL64(aCarry, 5U)) + 10192278965379756766U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = (aWandererG + RotL64(aCross, 41U)) + 17568666746676060748U;
            aOrbiterB = (((aWandererC + RotL64(aPrevious, 23U)) + RotL64(aCarry, 37U)) + 14312927531124963037U) + aNonceWordN;
            aOrbiterF = ((aWandererI + RotL64(aScatter, 13U)) + RotL64(aCarry, 21U)) + 9825825726152087706U;
            aOrbiterD = (aWandererD + RotL64(aIngress, 35U)) + 9696778570255265896U;
            aOrbiterE = (aWandererJ + RotL64(aCross, 60U)) + 17657841352013417228U;
            //
            aOrbiterH = (((aOrbiterH + aOrbiterI) + 16207815085909628439U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordE;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 1752979206374514227U;
            aOrbiterA = RotL64((aOrbiterA * 14182667540650694199U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 10456310689643905854U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 16127830548663742550U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4355938404839045417U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 2940917376003930842U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 7353596864777649953U;
            aOrbiterB = RotL64((aOrbiterB * 7499468723171042005U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 12725092740446150705U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 5791296650856037010U;
            aOrbiterI = RotL64((aOrbiterI * 760379251950502133U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 1200130368046206150U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 16689604428598558547U;
            aOrbiterF = RotL64((aOrbiterF * 13815324235939996623U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 14359561591103730856U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 3975025843599045263U;
            aOrbiterD = RotL64((aOrbiterD * 5025047888533298617U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 14017901732955607601U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 10431526786489555196U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10181915874476132407U), 27U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterI, 35U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 43U));
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterB, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 4U) + RotL64(aOrbiterH, 5U)) + aOrbiterB);
            aWandererJ = aWandererJ + (((RotL64(aCross, 57U) + RotL64(aOrbiterI, 51U)) + aOrbiterH) + aPhaseAWandererUpdateSaltC[((aIndex + 28U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 51U) + aOrbiterD) + RotL64(aOrbiterH, 18U)) + aNonceWordO);
            aWandererG = aWandererG + ((((RotL64(aScatter, 43U) + RotL64(aOrbiterE, 27U)) + aOrbiterA) + RotL64(aCarry, 5U)) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 37U) + aOrbiterA) + RotL64(aOrbiterH, 57U));
            aWandererD = aWandererD + (((RotL64(aCross, 11U) + RotL64(aOrbiterD, 43U)) + aOrbiterA) + RotL64(aCarry, 19U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 27U) + aOrbiterD) + RotL64(aOrbiterF, 35U)) + aNonceWordI);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + (RotL64(aWandererF, 60U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererC, 39U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ aNonceWordO;
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 13886U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13565U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 11732U)) & W_KEY1], 47U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 11288U)) & W_KEY1], 21U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 36U) + RotL64(aIngress, 53U)) ^ (RotL64(aCarry, 3U) + RotL64(aPrevious, 19U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterC = (((aWandererJ + RotL64(aScatter, 35U)) + 11210042748013785976U) + aPhaseAOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1]) + aNonceWordM;
            aOrbiterE = ((aWandererD + RotL64(aIngress, 57U)) + RotL64(aCarry, 37U)) + 4584747303233477454U;
            aOrbiterG = ((aWandererH + RotL64(aCross, 51U)) + RotL64(aCarry, 23U)) + 8878765929792969517U;
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 27U)) + RotL64(aCarry, 51U)) + 2172232330280041122U;
            aOrbiterA = (((aWandererA + RotL64(aScatter, 41U)) + 8378937026022264016U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordN;
            aOrbiterI = (aWandererB + RotL64(aIngress, 21U)) + 8683007464695824208U;
            aOrbiterJ = (aWandererE + RotL64(aPrevious, 10U)) + 9564352997357118134U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 11713878436769887528U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 8052917623074021077U;
            aOrbiterG = RotL64((aOrbiterG * 7450115139081623477U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 7720597162792145185U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 2602847785328475621U;
            aOrbiterE = RotL64((aOrbiterE * 14065077077207224525U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 17813669222300509724U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 8724263063156573013U;
            aOrbiterC = RotL64((aOrbiterC * 3632927017737834359U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 6882429835961613492U) + aNonceWordF;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 13213313479525717359U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2411431247725974895U), 37U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterI) + 2401526093648669573U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1]) + aNonceWordD;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 3616448566579979749U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13323155103752121393U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 18268262471839710401U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 5116424918948694752U;
            aOrbiterI = RotL64((aOrbiterI * 7641143782996332069U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 11405305689555640431U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 12427591396711015574U;
            aOrbiterJ = RotL64((aOrbiterJ * 8112834135715541223U), 47U);
            //
            aIngress = RotL64(aOrbiterA, 11U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 47U));
            aIngress = aIngress + (RotL64(aOrbiterK, 21U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterI, 34U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aCross, 5U) + RotL64(aOrbiterE, 5U)) + aOrbiterC) + RotL64(aCarry, 3U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterG, 13U)) + aOrbiterI);
            aWandererH = aWandererH + ((((RotL64(aIngress, 13U) + aOrbiterK) + RotL64(aOrbiterI, 38U)) + RotL64(aCarry, 23U)) + aPhaseAWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterC, 47U)) + aOrbiterG);
            aWandererK = aWandererK + ((RotL64(aPrevious, 37U) + aOrbiterG) + RotL64(aOrbiterJ, 19U));
            aWandererD = aWandererD ^ ((((RotL64(aCross, 50U) + RotL64(aOrbiterE, 53U)) + aOrbiterJ) + aNonceWordJ) + aPhaseAWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 57U) + RotL64(aOrbiterA, 29U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 5U));
            aCarry = aCarry + (RotL64(aWandererK, 56U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererD, 47U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordC);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 21507U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((aIndex + 17905U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17982U)) & S_BLOCK1], 39U) ^ RotL64(mSource[((aIndex + 19201U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 13U) ^ RotL64(aIngress, 43U)) + (RotL64(aCross, 58U) + RotL64(aPrevious, 27U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 3U)) + RotL64(aCarry, 29U)) + 10726035965553989335U;
            aOrbiterA = ((aWandererB + RotL64(aCross, 57U)) + RotL64(aCarry, 43U)) + 967354339530195662U;
            aOrbiterF = ((aWandererI + RotL64(aScatter, 37U)) + 10834593005478605624U) + aPhaseAOrbiterAssignSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = ((aWandererG + RotL64(aIngress, 50U)) + 1012888282838656933U) + aNonceWordH;
            aOrbiterG = ((aWandererA + RotL64(aCross, 43U)) + 15283530351725183253U) + aPhaseAOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = ((aWandererF + RotL64(aScatter, 29U)) + RotL64(aCarry, 57U)) + 11724495956731703750U;
            aOrbiterI = ((aWandererC + RotL64(aIngress, 19U)) + 4288330117317505776U) + aNonceWordM;
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 10894778070022873473U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 15563886747621617467U;
            aOrbiterF = RotL64((aOrbiterF * 17884709931569040065U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 11182488628562891937U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 10420140066310588580U) ^ aNonceWordL;
            aOrbiterC = RotL64((aOrbiterC * 13898299782819948719U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 11775138062167543111U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 16545391898578161683U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14588306527161321535U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 1550144656312299266U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 14903504853138279883U;
            aOrbiterG = RotL64((aOrbiterG * 8003033561266164387U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 309935535526750396U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 13991265868040011411U;
            aOrbiterB = RotL64((aOrbiterB * 2887531132228588441U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 1755976294857114222U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 2259275858478396846U;
            aOrbiterH = RotL64((aOrbiterH * 7416165760067878161U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 4838175912944552936U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 12307900457200936013U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14719363144850838805U), 19U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterC, 51U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 41U));
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterG, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 19U) + aOrbiterA) + RotL64(aOrbiterG, 57U));
            aWandererI = aWandererI + (((RotL64(aIngress, 42U) + aOrbiterH) + RotL64(aOrbiterC, 51U)) + RotL64(aCarry, 3U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 13U) + aOrbiterI) + RotL64(aOrbiterB, 43U)) + aPhaseAWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 5U) + aOrbiterH) + RotL64(aOrbiterF, 13U)) + RotL64(aCarry, 37U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterH, 3U)) + aOrbiterA);
            aWandererA = aWandererA + ((RotL64(aIngress, 35U) + aOrbiterG) + RotL64(aOrbiterI, 19U));
            aWandererB = aWandererB ^ ((((RotL64(aPrevious, 53U) + RotL64(aOrbiterA, 36U)) + aOrbiterI) + aNonceWordB) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 56U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + RotL64(aWandererC, 23U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordJ);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 24069U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26174U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25766U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneA[((aIndex + 22791U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 6U) + RotL64(aCarry, 53U)) + (RotL64(aCross, 29U) ^ RotL64(aPrevious, 41U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 5U)) + 5576732410244514238U) + aNonceWordC;
            aOrbiterE = (aWandererE + RotL64(aCross, 14U)) + 2833808925935929629U;
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 43U)) + 3670188682914544792U) + aPhaseAOrbiterAssignSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = (((aWandererJ + RotL64(aScatter, 29U)) + RotL64(aCarry, 13U)) + 15759072378887814995U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 21U)) + RotL64(aCarry, 39U)) + 13934007231137439994U;
            aOrbiterG = (aWandererI + RotL64(aIngress, 35U)) + 11022225696007690512U;
            aOrbiterC = (((aWandererC + RotL64(aCross, 51U)) + RotL64(aCarry, 53U)) + 16989177104453635790U) + aNonceWordB;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 9256930045263527091U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 17788596104417068290U;
            aOrbiterH = RotL64((aOrbiterH * 675554110563253305U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 17044369456673337625U) + aNonceWordI;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 1310908395523250343U) ^ aNonceWordO;
            aOrbiterJ = RotL64((aOrbiterJ * 16305084373037705921U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 12067065689034065422U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 15130844248737512262U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9409499577465934107U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 14532689204495587494U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 8198147292120244178U;
            aOrbiterE = RotL64((aOrbiterE * 1418356389507740991U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 5485494458627163347U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 10830008207150307611U;
            aOrbiterA = RotL64((aOrbiterA * 6526039534042499457U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 17770065502486618029U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 6397859353395335459U;
            aOrbiterG = RotL64((aOrbiterG * 14286997752368893825U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 5128700697381508319U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 7103394110057060499U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5053680689949149633U), 29U);
            //
            aIngress = RotL64(aOrbiterK, 60U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterC, 35U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 13U));
            aIngress = aIngress + RotL64(aOrbiterG, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 13U) + aOrbiterC) + RotL64(aOrbiterG, 58U)) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aScatter, 35U) + aOrbiterE) + RotL64(aOrbiterG, 41U)) + RotL64(aCarry, 39U)) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 41U) + aOrbiterA) + RotL64(aOrbiterG, 35U));
            aWandererC = aWandererC + (((RotL64(aIngress, 53U) + aOrbiterE) + RotL64(aOrbiterJ, 21U)) + RotL64(aCarry, 27U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterJ, 27U)) + aOrbiterK) + aNonceWordF);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 3U) + aOrbiterC) + RotL64(aOrbiterH, 51U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 60U) + aOrbiterJ) + RotL64(aOrbiterH, 13U)) + aNonceWordG);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 42U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + (RotL64(aWandererC, 21U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererJ, 47U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordC);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 31680U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28578U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31065U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29707U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCarry, 4U)) + (RotL64(aPrevious, 53U) ^ RotL64(aCross, 19U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterH = (aWandererB + RotL64(aScatter, 5U)) + 4751694786009671052U;
            aOrbiterC = (((aWandererF + RotL64(aCross, 12U)) + RotL64(aCarry, 13U)) + 16362725160370844224U) + aNonceWordP;
            aOrbiterJ = (aWandererC + RotL64(aIngress, 29U)) + 6360885380915941057U;
            aOrbiterB = (((aWandererH + RotL64(aPrevious, 53U)) + RotL64(aCarry, 39U)) + 5154536007972297036U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = ((aWandererG + RotL64(aIngress, 23U)) + RotL64(aCarry, 27U)) + 9362540581874808253U;
            aOrbiterG = ((aWandererI + RotL64(aScatter, 35U)) + 13902493871525612934U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = (aWandererA + RotL64(aCross, 41U)) + 10208452885367546542U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 3117030377279160998U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 17286247690414027870U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4896931759653832095U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 3930314320040949141U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 7289525252391668404U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15452162299105112187U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 3434167955466809185U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 17852573095128575663U;
            aOrbiterG = RotL64((aOrbiterG * 1485660158767033425U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 6137259687928853253U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 13992510605237574698U) ^ aNonceWordE;
            aOrbiterD = RotL64((aOrbiterD * 15346263295995333395U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 6470556523400123474U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 4333255670390099293U;
            aOrbiterH = RotL64((aOrbiterH * 11089933812030082647U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 7700424876430257995U) + aNonceWordB;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 16920736951239453071U;
            aOrbiterB = RotL64((aOrbiterB * 8920407493132380497U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 1635071690430295730U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 9966700845966398620U;
            aOrbiterC = RotL64((aOrbiterC * 17210048121896546867U), 21U);
            //
            aIngress = RotL64(aOrbiterK, 11U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterB, 48U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterC, 41U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterD, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aIngress, 5U) + aOrbiterK) + RotL64(aOrbiterH, 47U)) + RotL64(aCarry, 11U)) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterH, 35U)) + aOrbiterG);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 51U) + aOrbiterG) + RotL64(aOrbiterC, 53U)) + aNonceWordI) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 18U) + RotL64(aOrbiterB, 10U)) + aOrbiterJ);
            aWandererA = aWandererA + (((RotL64(aScatter, 41U) + RotL64(aOrbiterD, 3U)) + aOrbiterC) + RotL64(aCarry, 29U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterB, 27U)) + aOrbiterK);
            aWandererI = aWandererI + (((RotL64(aCross, 27U) + RotL64(aOrbiterK, 41U)) + aOrbiterC) + aNonceWordD);
            //
            aCarry = aCarry + (RotL64(aWandererF, 56U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererB);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 27U));
            aCarry = aCarry + RotL64(aWandererI, 11U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ aNonceWordK;
            aCarry = TwistMix64::DiffuseB(aCarry);
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

void TwistExpander_BaseBall_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xFAB5C390E34BCAE7ULL + 0xF96D44E8448CB28CULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x8EE718E6C384CF3DULL + 0xBD830FFF7AE536EBULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x9CBAD0C5D40BFAF7ULL + 0x98017FB0CA9EE13CULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xE5F30E0A731C6027ULL + 0x847DF2D836916507ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x87FBBE2FCB3A413BULL + 0x88D6ACBA82F8E191ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xD69424DA820767C3ULL + 0x935E52283102887FULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xF78CBA18B6310B77ULL + 0xD5749D7C280132C3ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xD361295D039DA6D3ULL + 0xDF4E259CDE2C58D3ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xE1A7A8F9FD64FAA9ULL + 0x9911653EB82D5926ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xB7FD7E6F8414193FULL + 0xC583B89FBFEB1D0EULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xCC80C0A10CCBE7F1ULL + 0x845992043C3EEA4FULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xFD343559F5644ECDULL + 0xC11C09FFEB3CA1C9ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xDCB22EC3BBB92057ULL + 0xF661F3E6A3664C90ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xCED0E999B93009A1ULL + 0xF9A919BA45CB4584ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xA17E1833B14A21CDULL + 0x93AF622F9E3CD814ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xA4BA8BB206126029ULL + 0xD7F39EF0991FDC17ULL);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 1188U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneC[((aIndex + 3483U)) & S_BLOCK1], 34U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 3567U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((aIndex + 395U)) & S_BLOCK1], 24U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 19U) + RotL64(aCross, 57U)) + (RotL64(aCarry, 6U) ^ RotL64(aPrevious, 37U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterD = ((aWandererD + RotL64(aIngress, 43U)) + 3612110001869385068U) + aNonceWordE;
            aOrbiterI = ((((aWandererA + RotL64(aPrevious, 56U)) + RotL64(aCarry, 5U)) + 16340824141280225936U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordL;
            aOrbiterJ = (aWandererH + RotL64(aScatter, 35U)) + 15222338965130765231U;
            aOrbiterK = (((aWandererI + RotL64(aCross, 19U)) + RotL64(aCarry, 41U)) + 6649270508107155041U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = (((aWandererC + RotL64(aIngress, 3U)) + RotL64(aCarry, 21U)) + 768217258655426384U) + aNonceWordN;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 4481855259658861851U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 18318041934562434016U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14913761339765234979U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 4212457153804401807U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 16143621095636987628U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6576072860505961427U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 2095664232866642086U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 4339527736737366572U;
            aOrbiterK = RotL64((aOrbiterK * 17503569508822244125U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 13679353177869884790U) + aNonceWordG;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 11582168502846418236U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 135539430034462861U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 10451330452898542191U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 12951448817640617841U;
            aOrbiterF = RotL64((aOrbiterF * 4141870904192742091U), 53U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterK, 23U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 3U));
            aIngress = aIngress + RotL64(aOrbiterJ, 50U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterK, 43U)) + aOrbiterD);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 3U) + aOrbiterI) + RotL64(aOrbiterF, 53U)) + RotL64(aCarry, 13U)) + aPhaseBWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterF, 30U)) + aOrbiterD) + aNonceWordM);
            aWandererH = aWandererH + (((RotL64(aCross, 42U) + aOrbiterF) + RotL64(aOrbiterJ, 3U)) + RotL64(aCarry, 37U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 11U) + aOrbiterF) + RotL64(aOrbiterK, 11U)) + aPhaseBWandererUpdateSaltC[((aIndex + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + RotL64(aWandererC, 43U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ aNonceWordG;
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 6304U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 7937U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 6419U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneB[((aIndex + 8050U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 11U) ^ RotL64(aIngress, 43U)) ^ (RotL64(aPrevious, 29U) + RotL64(aCarry, 56U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterH = (((aWandererJ + RotL64(aIngress, 24U)) + RotL64(aCarry, 43U)) + 15045917390223766480U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = ((aWandererD + RotL64(aCross, 51U)) + 10763054007033668758U) + aNonceWordJ;
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 43U)) + RotL64(aCarry, 5U)) + 13190170142593666607U;
            aOrbiterG = ((aWandererE + RotL64(aScatter, 11U)) + RotL64(aCarry, 19U)) + 9657025731441167065U;
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 35U)) + 11433367178975954211U) + aPhaseBOrbiterAssignSaltF[((aIndex + 28U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 17904920143996810366U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 3244383020512113283U;
            aOrbiterE = RotL64((aOrbiterE * 552521443123433353U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 6538815775171139091U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 7195368312757976343U) ^ aNonceWordM;
            aOrbiterB = RotL64((aOrbiterB * 10515679176134176565U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 18134430713910279374U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 6571776588427107976U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11916502085252589161U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 11830778129647517758U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 9793702760907767365U;
            aOrbiterA = RotL64((aOrbiterA * 4096246227968677179U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 2287235876793192036U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 8951959188326141794U;
            aOrbiterG = RotL64((aOrbiterG * 9968356718110753845U), 35U);
            //
            aIngress = RotL64(aOrbiterG, 26U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 5U));
            aIngress = aIngress + RotL64(aOrbiterH, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterE, 3U)) + aOrbiterG) + RotL64(aCarry, 43U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterH, 11U)) + aOrbiterG) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererE = aWandererE + (((((RotL64(aIngress, 13U) + RotL64(aOrbiterB, 19U)) + aOrbiterE) + RotL64(aCarry, 27U)) + aNonceWordA) + aPhaseBWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterA, 39U)) + aOrbiterH);
            aWandererD = aWandererD + ((RotL64(aCross, 60U) + RotL64(aOrbiterE, 58U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererE, 21U) ^ aWandererJ);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 60U));
            aCarry = aCarry + RotL64(aWandererH, 35U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ aNonceWordB;
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 12619U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13823U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 12983U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 14441U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aPrevious, 11U)) + (RotL64(aCarry, 56U) ^ RotL64(aIngress, 27U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterG = ((((aWandererF + RotL64(aScatter, 13U)) + RotL64(aCarry, 5U)) + 10915618884692072446U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordF;
            aOrbiterA = ((aWandererI + RotL64(aCross, 4U)) + RotL64(aCarry, 43U)) + 12634922308499254909U;
            aOrbiterI = (((aWandererJ + RotL64(aPrevious, 35U)) + RotL64(aCarry, 21U)) + 6533934734564499389U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = (aWandererE + RotL64(aIngress, 43U)) + 6744203303756105181U;
            aOrbiterF = (aWandererC + RotL64(aScatter, 53U)) + 13086782386652045658U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 5693840533331397822U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 1803663542535024611U;
            aOrbiterI = RotL64((aOrbiterI * 8511046986156781857U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 3597219300593287708U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 1429753448204448904U;
            aOrbiterA = RotL64((aOrbiterA * 10927459251773273143U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 17229017825587322715U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 1137574712801062932U;
            aOrbiterG = RotL64((aOrbiterG * 3645832160939819415U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 2401991077004083378U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 1332473247826139292U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15029831858261506447U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 11730946340796899885U) + aNonceWordP;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 15319163439700390962U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1349242001887975499U), 37U);
            //
            aIngress = RotL64(aOrbiterG, 23U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 39U));
            aIngress = aIngress + RotL64(aOrbiterA, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aScatter, 27U) + aOrbiterI) + RotL64(aOrbiterA, 23U)) + RotL64(aCarry, 19U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 50U) + aOrbiterI) + RotL64(aOrbiterF, 53U)) + aPhaseBWandererUpdateSaltE[((aIndex + 14U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aIngress, 41U) + aOrbiterE) + RotL64(aOrbiterG, 42U)) + RotL64(aCarry, 39U)) + aNonceWordI);
            aWandererC = aWandererC ^ ((((RotL64(aCross, 5U) + RotL64(aOrbiterE, 5U)) + aOrbiterI) + aNonceWordD) + aPhaseBWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 19U) + aOrbiterG) + RotL64(aOrbiterA, 13U)) + aNonceWordJ);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 48U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + RotL64(aWandererE, 3U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ aNonceWordI;
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 19598U)) & S_BLOCK1], 34U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21738U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21122U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 20472U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 38U) + RotL64(aCross, 53U)) ^ (RotL64(aCarry, 19U) ^ RotL64(aIngress, 5U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterA = (((aWandererC + RotL64(aCross, 50U)) + RotL64(aCarry, 57U)) + 12311607308490066301U) + aNonceWordD;
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 13U)) + 13100864684740679846U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterK = ((aWandererA + RotL64(aScatter, 29U)) + RotL64(aCarry, 19U)) + 13697304189274329704U;
            aOrbiterG = ((aWandererB + RotL64(aIngress, 39U)) + RotL64(aCarry, 41U)) + 9047976902871216732U;
            aOrbiterB = ((aWandererF + RotL64(aScatter, 21U)) + 2147897579538537888U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 2072444829390996142U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterA) ^ 2129307836981020908U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterK = RotL64((aOrbiterK * 8065769537670939667U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 10663145333751112064U) + aNonceWordL;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 15019844390503785459U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7442321463110790449U), 29U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterK) + 5460865577557928142U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1]) + aNonceWordB;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 15806522559993224197U;
            aOrbiterG = RotL64((aOrbiterG * 8722932687972240099U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 6361113778657833389U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 8306013884615042570U;
            aOrbiterC = RotL64((aOrbiterC * 8234258702656728667U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 4038420580499706912U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 11908091484457158973U;
            aOrbiterB = RotL64((aOrbiterB * 3964111175645156719U), 53U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterC, 46U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 57U));
            aIngress = aIngress + RotL64(aOrbiterG, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((((RotL64(aIngress, 27U) + RotL64(aOrbiterG, 46U)) + aOrbiterA) + aNonceWordE) + aPhaseBWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererC = aWandererC + (((((RotL64(aCross, 53U) + RotL64(aOrbiterA, 11U)) + aOrbiterC) + RotL64(aCarry, 27U)) + aNonceWordP) + aPhaseBWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 35U) + aOrbiterB) + RotL64(aOrbiterG, 35U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 10U) + RotL64(aOrbiterK, 27U)) + aOrbiterG) + RotL64(aCarry, 57U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterB, 3U)) + aOrbiterA) + aNonceWordN);
            //
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererA);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + RotL64(aWandererF, 19U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ aNonceWordH;
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 23269U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneA[((aIndex + 24667U)) & S_BLOCK1], 42U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 22097U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24581U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aIngress, 11U)) + (RotL64(aCross, 37U) ^ RotL64(aPrevious, 50U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterJ = (((aWandererA + RotL64(aScatter, 21U)) + RotL64(aCarry, 21U)) + 17711946802293254150U) + aNonceWordO;
            aOrbiterC = ((aWandererH + RotL64(aCross, 3U)) + 16652362590489569378U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = (((aWandererJ + RotL64(aIngress, 13U)) + RotL64(aCarry, 5U)) + 6972810344198183097U) + aNonceWordE;
            aOrbiterD = (((aWandererG + RotL64(aPrevious, 47U)) + RotL64(aCarry, 51U)) + 13117100889782940546U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterE = (aWandererK + RotL64(aScatter, 38U)) + 13199305696782626591U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 992156184392760945U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 13791265442074543880U) ^ aNonceWordJ;
            aOrbiterA = RotL64((aOrbiterA * 1263919538622722673U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 17057087245252294859U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 13444195995883541046U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13067044288608808777U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 6723678233676059420U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 7913379431208430475U;
            aOrbiterJ = RotL64((aOrbiterJ * 2295062944289127123U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 4481887195529300665U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 11892724101424384078U;
            aOrbiterC = RotL64((aOrbiterC * 3468639499716604111U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 7700902083270424194U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 1888001433557140271U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8975562955027025349U), 43U);
            //
            aIngress = RotL64(aOrbiterD, 36U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterJ, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((((RotL64(aPrevious, 60U) + RotL64(aOrbiterJ, 13U)) + aOrbiterC) + aNonceWordK) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 27U) + RotL64(aOrbiterJ, 37U)) + aOrbiterE) + RotL64(aCarry, 41U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterD, 3U)) + aOrbiterA);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 19U) + RotL64(aOrbiterC, 26U)) + aOrbiterE) + RotL64(aCarry, 19U)) + aNonceWordA);
            aWandererK = aWandererK ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterC, 51U)) + aOrbiterD) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 24U));
            aCarry = aCarry + RotL64(aWandererK, 3U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordN);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 28625U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneB[((aIndex + 29277U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 29024U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28293U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 51U) ^ RotL64(aPrevious, 24U)) ^ (RotL64(aIngress, 37U) + RotL64(aCross, 3U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterF = (aWandererF + RotL64(aIngress, 47U)) + 6733949564325516029U;
            aOrbiterA = (((aWandererE + RotL64(aScatter, 10U)) + RotL64(aCarry, 27U)) + 7304098437143918796U) + aPhaseBOrbiterAssignSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 57U)) + 3923949518391777800U;
            aOrbiterJ = ((aWandererC + RotL64(aCross, 39U)) + RotL64(aCarry, 3U)) + 14243591003388927124U;
            aOrbiterD = ((((aWandererB + RotL64(aPrevious, 21U)) + RotL64(aCarry, 51U)) + 18329498724605410406U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordH;
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 13118172167747037249U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 5272025143849174212U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9935990954321437743U), 35U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterF) + 16075917179214318424U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1]) + aNonceWordK;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 15263590648674658399U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9918239923411740337U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 13730046728289525921U) + aNonceWordG;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 7703141464499623408U;
            aOrbiterF = RotL64((aOrbiterF * 5886009900621521987U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 1382279753822135359U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 2973369221699098292U;
            aOrbiterJ = RotL64((aOrbiterJ * 7440242040663550631U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 11578274119583013219U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 3419411247737896674U;
            aOrbiterD = RotL64((aOrbiterD * 17814942652262802991U), 43U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterA, 5U);
            aIngress = aIngress + (RotL64(aOrbiterI, 56U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterF, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterA, 57U)) + aOrbiterD);
            aWandererF = aWandererF + ((((RotL64(aScatter, 21U) + aOrbiterA) + RotL64(aOrbiterJ, 20U)) + RotL64(aCarry, 23U)) + aNonceWordL);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 54U) + RotL64(aOrbiterI, 3U)) + aOrbiterF);
            aWandererE = aWandererE + (((((RotL64(aCross, 29U) + RotL64(aOrbiterI, 35U)) + aOrbiterJ) + RotL64(aCarry, 35U)) + aNonceWordP) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterJ, 47U)) + aOrbiterD) + aNonceWordE) + aPhaseBWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 38U));
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererC, 51U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ aNonceWordK;
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

void TwistExpander_BaseBall_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x8F8AAC4C7E8A5B89ULL + 0xC05B5CF7F4BB7BD7ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xD4083050EDEE7DE1ULL + 0x9BFB596EEFF62DE4ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xC9D850B3B540A915ULL + 0xB1541870637FD880ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x9DB444E70D00175DULL + 0xAF6AE22DD23E2FFEULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xC9C722A320DA8595ULL + 0xC78701B0FEC9DC31ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xA589129832FA8271ULL + 0xA4D5C3023C257693ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xD9D9BCB4568F13DDULL + 0xCC2A3AF47E56E4B6ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xCBD0B5D0098D5A85ULL + 0xC3595A70FC3B55D0ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x92F27A607AB56FBFULL + 0xF20015E20A447A3DULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xE8B0F2D1D5706D9FULL + 0xDA51C1D2A7BCDFF4ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xFDB117B6241548C3ULL + 0x88AC2E7ECD393EB9ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xD88A1978647D2ABBULL + 0xE04214917502B7E5ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xEFA8F0441287D1EBULL + 0xC8F63C1BA09D1E6EULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xD94CAF4F6FBF79B5ULL + 0xC718F0EFD803C834ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xF220CE31574BF609ULL + 0x9D192D401959066DULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xA19812DE8E4A2875ULL + 0xF9FBCD5F62165243ULL);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 2212U)) & S_BLOCK1], 38U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 7793U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 4006U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 2008U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 3U) ^ RotL64(aCross, 35U)) ^ (RotL64(aPrevious, 53U) + RotL64(aCarry, 20U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterI = (aWandererF + RotL64(aIngress, 39U)) + 11177787645248006236U;
            aOrbiterH = (aWandererK + RotL64(aPrevious, 4U)) + 3808340254579817169U;
            aOrbiterJ = (aWandererB + RotL64(aScatter, 53U)) + 828030667598518279U;
            aOrbiterG = (aWandererC + RotL64(aCross, 47U)) + 16177835921238398371U;
            aOrbiterC = ((aWandererG + RotL64(aScatter, 35U)) + 5518747735458708741U) + aNonceWordM;
            aOrbiterA = (aWandererD + RotL64(aPrevious, 20U)) + 17346319082399995165U;
            aOrbiterE = (((aWandererJ + RotL64(aCross, 27U)) + RotL64(aCarry, 5U)) + 6397156921893030937U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = ((aWandererH + RotL64(aIngress, 43U)) + RotL64(aCarry, 39U)) + 15559381654710713582U;
            aOrbiterB = (((aWandererI + RotL64(aScatter, 11U)) + RotL64(aCarry, 13U)) + 940404446491415088U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 8047166032048732645U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 4688468645859470491U;
            aOrbiterJ = RotL64((aOrbiterJ * 14383536431614496369U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 3710878044770337260U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 116343189456629220U;
            aOrbiterA = RotL64((aOrbiterA * 5637725064169289339U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 883908030159391659U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 18058691521694880482U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3132200449123497619U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 17521015077103586117U) + aNonceWordL;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 3668332225435714918U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12658899101297839881U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 12229480388278883300U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 16206524049491531816U;
            aOrbiterI = RotL64((aOrbiterI * 11122340196620859805U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 5743265849441077466U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterJ) ^ 2812293020719282236U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterG = RotL64((aOrbiterG * 8903956475200417109U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 13718364781538837074U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 861529717259766236U;
            aOrbiterE = RotL64((aOrbiterE * 17019744777211266685U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 4862687502126693872U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 7722024283321020761U) ^ aNonceWordG;
            aOrbiterH = RotL64((aOrbiterH * 18086944039541060829U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 8205803118233399853U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 15130160926615050422U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1454552751453996765U), 13U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterE, 43U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 52U));
            aIngress = aIngress + (RotL64(aOrbiterF, 11U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterH, 23U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterG, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterA, 5U)) + aOrbiterH);
            aWandererC = aWandererC + (((RotL64(aScatter, 14U) + RotL64(aOrbiterI, 42U)) + aOrbiterC) + RotL64(aCarry, 57U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 43U) + aOrbiterB) + RotL64(aOrbiterH, 11U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 47U) + aOrbiterJ) + RotL64(aOrbiterA, 23U)) + aNonceWordD);
            aWandererI = aWandererI ^ (((RotL64(aCross, 53U) + aOrbiterG) + RotL64(aOrbiterE, 47U)) + aPhaseCWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 36U) + aOrbiterI) + RotL64(aOrbiterA, 28U)) + RotL64(aCarry, 43U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 5U) + aOrbiterJ) + RotL64(aOrbiterB, 51U));
            aWandererD = aWandererD + (((RotL64(aIngress, 19U) + RotL64(aOrbiterA, 57U)) + aOrbiterE) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterE, 35U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 39U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 18U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererH, 47U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordN);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10742U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneD[((aIndex + 14101U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 11453U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneB[((aIndex + 11736U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 4U) ^ RotL64(aCarry, 21U)) + (RotL64(aCross, 51U) + RotL64(aIngress, 39U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 19U)) + 13296600294247799698U) + aNonceWordO;
            aOrbiterK = ((aWandererD + RotL64(aScatter, 24U)) + 5818503518080877515U) + aPhaseCOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = ((aWandererG + RotL64(aCross, 47U)) + RotL64(aCarry, 57U)) + 6735784238734173597U;
            aOrbiterD = ((aWandererF + RotL64(aIngress, 29U)) + 7368398209488856201U) + aNonceWordK;
            aOrbiterG = (((aWandererJ + RotL64(aScatter, 51U)) + RotL64(aCarry, 39U)) + 961734029066455638U) + aNonceWordJ;
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 43U)) + RotL64(aCarry, 5U)) + 797011946660892011U;
            aOrbiterI = (aWandererH + RotL64(aIngress, 12U)) + 12841876018396622350U;
            aOrbiterJ = (aWandererA + RotL64(aCross, 37U)) + 16213253970483895623U;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 57U)) + 15186950557113470375U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 5117930310827477341U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 12265429373166094162U;
            aOrbiterE = RotL64((aOrbiterE * 1522823535151532249U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 13920531346698601568U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 14695405206998211456U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13950964363414164279U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 7851960904825938443U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 9501511171732550190U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5614164120361489613U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 5663365182245722077U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 9607860124321315555U;
            aOrbiterJ = RotL64((aOrbiterJ * 3461820361914280601U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 18171052650586819280U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 3442698321538580861U) ^ aNonceWordI;
            aOrbiterF = RotL64((aOrbiterF * 6317525514963824829U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 1491052813469258970U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 3956599824067616133U;
            aOrbiterH = RotL64((aOrbiterH * 2928600779267623085U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 10963841237346073453U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 2303020125591252534U;
            aOrbiterD = RotL64((aOrbiterD * 9969099842343321981U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 14503856057958162356U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 11147548150090597694U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11856382308792700441U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 9191681438318311481U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 13556072770381999852U;
            aOrbiterK = RotL64((aOrbiterK * 18316231099054203683U), 39U);
            //
            aIngress = RotL64(aOrbiterI, 58U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterH, 47U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 53U));
            aIngress = aIngress + (RotL64(aOrbiterE, 27U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterB, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 53U) + aOrbiterH) + RotL64(aOrbiterG, 22U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 27U) + RotL64(aOrbiterJ, 3U)) + aOrbiterG);
            aWandererB = aWandererB ^ (((RotL64(aCross, 57U) + aOrbiterK) + RotL64(aOrbiterI, 43U)) + aPhaseCWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 14U) + aOrbiterG) + RotL64(aOrbiterB, 11U)) + RotL64(aCarry, 27U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 5U) + aOrbiterD) + RotL64(aOrbiterF, 57U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 41U) + aOrbiterG) + RotL64(aOrbiterK, 26U)) + aNonceWordE);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterJ, 51U)) + aOrbiterH) + aNonceWordH);
            aWandererI = aWandererI + (((RotL64(aCross, 23U) + RotL64(aOrbiterE, 47U)) + aOrbiterF) + RotL64(aCarry, 35U));
            aWandererG = aWandererG ^ ((((RotL64(aIngress, 10U) + aOrbiterI) + RotL64(aOrbiterD, 39U)) + aNonceWordM) + aPhaseCWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererD);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + RotL64(aWandererH, 24U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordB);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 19547U)) & S_BLOCK1], 38U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16454U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 20223U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneC[((aIndex + 21720U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aPrevious, 57U)) + (RotL64(aCarry, 12U) ^ RotL64(aIngress, 27U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterA = ((aWandererC + RotL64(aScatter, 11U)) + 16802219662864902427U) + aNonceWordH;
            aOrbiterB = ((aWandererJ + RotL64(aIngress, 28U)) + RotL64(aCarry, 23U)) + 14332033461409490629U;
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 39U)) + RotL64(aCarry, 43U)) + 8781794298640286845U;
            aOrbiterG = (((aWandererF + RotL64(aCross, 19U)) + RotL64(aCarry, 57U)) + 8459933908074937264U) + aNonceWordC;
            aOrbiterE = (aWandererI + RotL64(aPrevious, 5U)) + 1883580287986004426U;
            aOrbiterF = (aWandererH + RotL64(aCross, 52U)) + 17500258188004626118U;
            aOrbiterH = ((aWandererG + RotL64(aScatter, 23U)) + 7934811305150872870U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = (((aWandererK + RotL64(aIngress, 47U)) + 6380363892361098905U) + aPhaseCOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1]) + aNonceWordM;
            aOrbiterJ = (aWandererE + RotL64(aCross, 57U)) + 12623079132626676910U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 10455208121949202703U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 8805532707916767629U;
            aOrbiterI = RotL64((aOrbiterI * 666082374369701881U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 9161544391400377699U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 3501434325829663268U;
            aOrbiterA = RotL64((aOrbiterA * 7933545151293799637U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 651783304096081996U) + aNonceWordK;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 441505031509930622U) ^ aNonceWordD;
            aOrbiterG = RotL64((aOrbiterG * 8045355432310956143U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 1771159983581326424U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 15227946417377695989U;
            aOrbiterB = RotL64((aOrbiterB * 1563141188972797601U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 4153717524193279095U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 4404521756523902829U;
            aOrbiterE = RotL64((aOrbiterE * 1410342912973206203U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 6231945075461813285U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 3864780227164426690U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 18031353247480673617U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 1509699687948576558U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 17316114302489411191U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15490661284980281585U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 2250572827340157410U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 6403966113144372915U;
            aOrbiterK = RotL64((aOrbiterK * 726441947009132383U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 2329903609147403156U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 2486330017319455238U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17427461345935191757U), 43U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterF, 56U);
            aIngress = aIngress + (RotL64(aOrbiterA, 23U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 41U));
            aIngress = aIngress + (RotL64(aOrbiterG, 53U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterH, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterK, 5U)) + aOrbiterH);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 44U) + RotL64(aOrbiterK, 60U)) + aOrbiterE);
            aWandererH = aWandererH + (((RotL64(aCross, 13U) + aOrbiterA) + RotL64(aOrbiterI, 27U)) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterF, 47U)) + aOrbiterK) + aPhaseCWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aScatter, 57U) + aOrbiterG) + RotL64(aOrbiterK, 43U)) + RotL64(aCarry, 19U)) + aNonceWordI);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterB, 21U)) + aOrbiterH);
            aWandererJ = aWandererJ + ((RotL64(aCross, 5U) + RotL64(aOrbiterJ, 14U)) + aOrbiterK);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterG, 35U)) + aOrbiterI) + aNonceWordP);
            aWandererI = aWandererI + ((((RotL64(aCross, 40U) + RotL64(aOrbiterI, 51U)) + aOrbiterH) + RotL64(aCarry, 57U)) + aNonceWordN);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 24U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 41U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 37U));
            aCarry = aCarry + RotL64(aWandererH, 57U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ aNonceWordL;
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 27441U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneB[((aIndex + 32394U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 29720U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneD[((aIndex + 28704U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 39U) + RotL64(aCross, 11U)) ^ (RotL64(aPrevious, 56U) + RotL64(aCarry, 27U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterD = (aWandererH + RotL64(aPrevious, 30U)) + 3448371607470865612U;
            aOrbiterI = (aWandererJ + RotL64(aIngress, 19U)) + 3743742913651580573U;
            aOrbiterJ = (((aWandererF + RotL64(aScatter, 13U)) + 13069491287948807280U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordE;
            aOrbiterB = (((aWandererE + RotL64(aCross, 23U)) + 16872779275586545632U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordN;
            aOrbiterH = ((aWandererB + RotL64(aScatter, 43U)) + RotL64(aCarry, 27U)) + 17945792656755062795U;
            aOrbiterE = (aWandererC + RotL64(aIngress, 6U)) + 18199747196793731853U;
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 57U)) + RotL64(aCarry, 13U)) + 15953311878379809513U;
            aOrbiterC = ((aWandererI + RotL64(aCross, 35U)) + RotL64(aCarry, 41U)) + 941268763494588338U;
            aOrbiterK = (aWandererK + RotL64(aScatter, 47U)) + 10090221530365796809U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 8335698093307607001U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 6147498804734306100U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6904444049941211327U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 5980246079567570090U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 4152167624425912978U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10019421651535123573U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 14990418790239735916U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 3418668387496597219U;
            aOrbiterG = RotL64((aOrbiterG * 12814077238529863119U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 4206650904177199425U) + aNonceWordP;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 3905470780938996069U;
            aOrbiterD = RotL64((aOrbiterD * 16030122739273137005U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 9968672788233080924U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 602258075661864866U;
            aOrbiterB = RotL64((aOrbiterB * 2615726693066300065U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 17751667243048041383U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 2414054413585296027U) ^ aNonceWordJ;
            aOrbiterE = RotL64((aOrbiterE * 1049512574773201893U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 6523322402744047752U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 6729901917767398779U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8039939871405367139U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 11460169185076814539U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 7559640379553110573U;
            aOrbiterK = RotL64((aOrbiterK * 9864654321914036135U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 17271150091827475028U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 3541809324556914646U;
            aOrbiterI = RotL64((aOrbiterI * 12655168871428868639U), 39U);
            //
            aIngress = RotL64(aOrbiterG, 23U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterD, 51U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterJ, 11U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 60U));
            aIngress = aIngress + RotL64(aOrbiterK, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterG, 56U)) + aOrbiterE);
            aWandererE = aWandererE + (((RotL64(aPrevious, 52U) + aOrbiterJ) + RotL64(aOrbiterB, 43U)) + RotL64(aCarry, 47U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 11U) + aOrbiterI) + RotL64(aOrbiterG, 35U)) + aNonceWordK);
            aWandererC = aWandererC + ((((RotL64(aScatter, 29U) + aOrbiterG) + RotL64(aOrbiterD, 51U)) + RotL64(aCarry, 23U)) + aNonceWordA);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 19U) + aOrbiterE) + RotL64(aOrbiterD, 11U)) + aNonceWordB);
            aWandererA = aWandererA + (((RotL64(aCross, 35U) + aOrbiterJ) + RotL64(aOrbiterH, 47U)) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 44U) + aOrbiterI) + RotL64(aOrbiterB, 4U)) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterD, 19U)) + aOrbiterK);
            aWandererK = aWandererK ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterC, 23U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 44U));
            aCarry = aCarry + (RotL64(aWandererI, 5U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererJ, 37U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererF, 29U);
            aCarry = aCarry + RotL64(aIngress, 54U);
            aCarry = aCarry ^ aNonceWordP;
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

void TwistExpander_BaseBall_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xECFCEE4A6D3B68EDULL + 0xB792EE0B0F71CE7AULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x959D2CDF1CBF91F7ULL + 0xCB6CB43DFBC348E5ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xEAE4034556391BBDULL + 0x9AD41A64B6C86C72ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x8A6DFFF481EA61FFULL + 0x8B977117EB96A246ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xF89F2499B7C71A3FULL + 0xD002DD073868DEE4ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xD89DF431D4FB1DADULL + 0xCEA19B74B3E78A1EULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xF30145EF19D0D947ULL + 0x9997E90CE4EEAFC2ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xA7822ECF99C4C3C7ULL + 0x97069C42BC56E192ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x94B2C0E4C467388BULL + 0xD338402F5E2AA8A5ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xB57838D6CAACBF2FULL + 0xD515E62063268E3FULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xFFF95A876CB99945ULL + 0xACD43EC4F9F2F637ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x8D74537F4A5F9EB3ULL + 0x89E38BB48A9AF21CULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xA1139006AD89476BULL + 0xAF0CCC4F8D72D5C4ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xA621C1A3266D78F3ULL + 0xA0793EB0876B032DULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xF93F449841687D33ULL + 0xF5C917804F9007AFULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xE6F21FD257034015ULL + 0x9EB8AF7591536A69ULL);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 5162U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneC[((aIndex + 3667U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 107U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 756U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 27U) + RotL64(aIngress, 43U)) ^ (RotL64(aPrevious, 56U) ^ RotL64(aCross, 11U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterF = (aWandererI + RotL64(aPrevious, 5U)) + 15904465836916519864U;
            aOrbiterA = (((aWandererF + RotL64(aIngress, 43U)) + 17725629806317789307U) + aPhaseDOrbiterAssignSaltE[((aIndex + 6U)) & S_SALT1]) + aNonceWordM;
            aOrbiterD = (aWandererJ + RotL64(aScatter, 23U)) + 13794170125914914828U;
            aOrbiterK = ((aWandererB + RotL64(aCross, 35U)) + 2149055907476874332U) + aPhaseDOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = ((aWandererD + RotL64(aScatter, 54U)) + RotL64(aCarry, 53U)) + 5342047776745074649U;
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 19U)) + RotL64(aCarry, 5U)) + 8268148484060546838U;
            aOrbiterI = (aWandererC + RotL64(aCross, 27U)) + 10821151364028563719U;
            aOrbiterB = ((aWandererA + RotL64(aIngress, 57U)) + 4294213820894407378U) + aNonceWordC;
            aOrbiterH = ((aWandererE + RotL64(aCross, 51U)) + RotL64(aCarry, 39U)) + 10884726101307943090U;
            aOrbiterC = (aWandererH + RotL64(aPrevious, 3U)) + 16432210042202444824U;
            aOrbiterJ = (aWandererK + RotL64(aScatter, 46U)) + 15196602644336228055U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 14117787670220328165U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 219833877949480215U;
            aOrbiterD = RotL64((aOrbiterD * 10736293047771972173U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 3326396981881473962U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 14918513066311426279U) ^ aNonceWordG;
            aOrbiterE = RotL64((aOrbiterE * 14269763278564574663U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 11795234681370163206U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 3068267285352664813U;
            aOrbiterF = RotL64((aOrbiterF * 15746255933920904619U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 245233356957999496U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 709926406353796673U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13627039596842073595U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 5378105439430271038U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 10114555061122044430U;
            aOrbiterI = RotL64((aOrbiterI * 5351295043424885549U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 13233010815716769713U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 8231291294833548389U;
            aOrbiterH = RotL64((aOrbiterH * 10840516135212753869U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 7160760224172419829U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 14767926435411546785U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1643485739468851073U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 4464245330038080103U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 15778166658285494712U;
            aOrbiterA = RotL64((aOrbiterA * 13980891936095282989U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 2426340576450960905U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 6030631392508241438U;
            aOrbiterG = RotL64((aOrbiterG * 13921288910299408423U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 15990180955119402476U) + aNonceWordN;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 8707879851984546959U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13794027045755532979U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 11665969506971636052U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 15904465836916519864U;
            aOrbiterC = RotL64((aOrbiterC * 17042355185093585101U), 51U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterC, 13U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 35U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 56U));
            aIngress = aIngress + (RotL64(aOrbiterH, 43U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + RotL64(aOrbiterE, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aIngress, 39U) + aOrbiterI) + RotL64(aOrbiterD, 51U)) + aPhaseDWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 37U) + aOrbiterJ) + RotL64(aOrbiterG, 53U));
            aWandererA = aWandererA + (((RotL64(aScatter, 41U) + aOrbiterA) + RotL64(aOrbiterF, 57U)) + RotL64(aCarry, 51U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterA, 10U)) + aOrbiterC);
            aWandererK = aWandererK + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterG, 21U)) + aOrbiterK);
            aWandererF = aWandererF ^ ((RotL64(aCross, 57U) + aOrbiterE) + RotL64(aOrbiterB, 41U));
            aWandererC = aWandererC + ((RotL64(aIngress, 12U) + aOrbiterA) + RotL64(aOrbiterJ, 39U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 19U) + aOrbiterK) + RotL64(aOrbiterB, 24U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 47U) + RotL64(aOrbiterH, 27U)) + aOrbiterD) + RotL64(aCarry, 3U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterB, 47U)) + aOrbiterI) + aPhaseDWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 24U) + aOrbiterJ) + RotL64(aOrbiterH, 5U)) + aNonceWordI);
            //
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 41U) ^ aWandererK);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 24U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 37U));
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererH, 13U);
            aCarry = aCarry + RotL64(aIngress, 20U);
            aCarry = aCarry ^ aNonceWordN;
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 5879U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 5605U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 6615U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneB[((aIndex + 8699U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 29U) + RotL64(aCarry, 57U)) + (RotL64(aCross, 42U) ^ RotL64(aPrevious, 13U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterF = (aWandererG + RotL64(aCross, 11U)) + 6163290588946759209U;
            aOrbiterI = (aWandererC + RotL64(aIngress, 51U)) + 7342672468560105447U;
            aOrbiterH = (((aWandererI + RotL64(aScatter, 29U)) + RotL64(aCarry, 19U)) + 11574563167017282321U) + aPhaseDOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = (aWandererB + RotL64(aPrevious, 19U)) + 2254820206194758964U;
            aOrbiterD = ((aWandererA + RotL64(aCross, 43U)) + RotL64(aCarry, 37U)) + 1469783447473099498U;
            aOrbiterB = (aWandererK + RotL64(aPrevious, 3U)) + 14174828900676165088U;
            aOrbiterK = ((aWandererD + RotL64(aIngress, 22U)) + 16277954291890598132U) + aNonceWordO;
            aOrbiterC = (aWandererE + RotL64(aScatter, 37U)) + 14845750668693136766U;
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 39U)) + 150099699692047766U) + aNonceWordK;
            aOrbiterA = (aWandererJ + RotL64(aScatter, 53U)) + 1200784917165131703U;
            aOrbiterG = (((aWandererH + RotL64(aPrevious, 24U)) + RotL64(aCarry, 41U)) + 9469982764806754302U) + aPhaseDOrbiterAssignSaltD[((aIndex + 20U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 10956702761701710182U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 7915506894975487807U;
            aOrbiterH = RotL64((aOrbiterH * 8874108311712727983U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 17335794183733623213U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 557028996286989506U;
            aOrbiterI = RotL64((aOrbiterI * 3993359298602424281U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 1597385667771002414U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 4376417959915162639U;
            aOrbiterD = RotL64((aOrbiterD * 4626236858205178149U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 549770198518993876U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 756554555648070919U;
            aOrbiterK = RotL64((aOrbiterK * 16272320259614325355U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 7298557532533152193U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 3336802611342112013U;
            aOrbiterJ = RotL64((aOrbiterJ * 14679103452120080499U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 2314938232094714365U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 12215066333571149153U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10747052773052630601U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 7762752719356805046U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 6519429915769040078U;
            aOrbiterE = RotL64((aOrbiterE * 15548676502167938513U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 7556691736109752918U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 13731245903412646404U;
            aOrbiterB = RotL64((aOrbiterB * 15581965016668635409U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 5910925625723735162U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 16037704866415841869U;
            aOrbiterC = RotL64((aOrbiterC * 11628217027073824759U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 12605882248192797360U) + aNonceWordP;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 9579778913978981884U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5372577227818787957U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 6063171520266734946U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 6163290588946759209U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 291843698316138251U), 13U);
            //
            aIngress = RotL64(aOrbiterG, 19U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterA, 10U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 27U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 21U));
            aIngress = aIngress + (RotL64(aOrbiterD, 51U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterI, 56U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterE, 23U)) + aOrbiterD);
            aWandererK = aWandererK + ((RotL64(aScatter, 47U) + RotL64(aOrbiterH, 13U)) + aOrbiterK);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterE, 47U)) + aOrbiterC);
            aWandererD = aWandererD + ((RotL64(aCross, 40U) + aOrbiterA) + RotL64(aOrbiterI, 41U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 53U) + aOrbiterG) + RotL64(aOrbiterH, 19U));
            aWandererE = aWandererE + (((RotL64(aScatter, 23U) + aOrbiterB) + RotL64(aOrbiterI, 56U)) + RotL64(aCarry, 51U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 3U) + aOrbiterG) + RotL64(aOrbiterK, 11U));
            aWandererF = aWandererF + (((RotL64(aCross, 51U) + aOrbiterA) + RotL64(aOrbiterJ, 53U)) + aNonceWordE);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 37U) + RotL64(aOrbiterI, 39U)) + aOrbiterJ) + aPhaseDWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 14U) + aOrbiterG) + RotL64(aOrbiterD, 60U)) + RotL64(aCarry, 39U)) + aNonceWordJ);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 5U) + aOrbiterF) + RotL64(aOrbiterH, 27U)) + aPhaseDWandererUpdateSaltD[((aIndex + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 24U) ^ aWandererI);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 51U));
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererB, 27U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordI);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 11425U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 15104U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 11581U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneC[((aIndex + 13960U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 37U) + RotL64(aCross, 10U)) + (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 53U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterI = (((aWandererD + RotL64(aCross, 4U)) + 12615321415808640429U) + aPhaseDOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1]) + aNonceWordK;
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 27U)) + 15712784676459931207U;
            aOrbiterG = (aWandererB + RotL64(aScatter, 51U)) + 11013335427004930046U;
            aOrbiterK = (aWandererA + RotL64(aIngress, 41U)) + 8298733856304768806U;
            aOrbiterD = ((aWandererF + RotL64(aCross, 23U)) + RotL64(aCarry, 43U)) + 6207732959150824216U;
            aOrbiterB = ((aWandererK + RotL64(aIngress, 53U)) + RotL64(aCarry, 29U)) + 9769864876127544038U;
            aOrbiterF = ((aWandererH + RotL64(aScatter, 11U)) + 10782181918651152563U) + aNonceWordL;
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 58U)) + 5790454015845620939U) + aNonceWordN;
            aOrbiterA = ((aWandererE + RotL64(aScatter, 21U)) + RotL64(aCarry, 37U)) + 15606578025386733803U;
            aOrbiterE = ((aWandererG + RotL64(aCross, 43U)) + 5522352539991175304U) + aPhaseDOrbiterAssignSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterJ = (aWandererI + RotL64(aIngress, 37U)) + 5993355818572869649U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 10864534396947622047U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 12090053126235913528U;
            aOrbiterG = RotL64((aOrbiterG * 7250801471645972261U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 14191181677234981396U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 2258570108233924592U;
            aOrbiterB = RotL64((aOrbiterB * 8307541155393855209U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 8448114811381534603U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 2702389315763499817U;
            aOrbiterH = RotL64((aOrbiterH * 6710443836432274393U), 13U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterE) + 17202184076718780200U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 150549910056015002U) ^ aNonceWordM;
            aOrbiterD = RotL64((aOrbiterD * 195034681254956335U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 4910512055808124967U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterJ) ^ 4783477997418403079U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterC = RotL64((aOrbiterC * 861977492146512865U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 13842899106208709771U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 7930112618036681468U;
            aOrbiterE = RotL64((aOrbiterE * 8609551859830858419U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 8790107242863198659U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 6882768826643279144U;
            aOrbiterI = RotL64((aOrbiterI * 13745521454063360763U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 12136498871759890015U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 8120456314755584336U;
            aOrbiterK = RotL64((aOrbiterK * 1830725195528043575U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 14425711740351183016U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 15907406009196323049U;
            aOrbiterF = RotL64((aOrbiterF * 8599371693260686839U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 4878521420367891861U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 1184672056055028939U;
            aOrbiterA = RotL64((aOrbiterA * 5963961755367831967U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 10126736568567000180U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 12615321415808640429U;
            aOrbiterJ = RotL64((aOrbiterJ * 11663715449073755137U), 43U);
            //
            aIngress = RotL64(aOrbiterG, 35U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterH, 46U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 29U));
            aIngress = aIngress + (RotL64(aOrbiterD, 37U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 43U));
            aIngress = aIngress + RotL64(aOrbiterB, 50U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aScatter, 60U) + aOrbiterC) + RotL64(aOrbiterD, 47U)) + aNonceWordA);
            aWandererA = aWandererA + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterB, 11U)) + aOrbiterG);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterJ, 13U)) + aOrbiterI);
            aWandererJ = aWandererJ + ((RotL64(aCross, 27U) + RotL64(aOrbiterI, 57U)) + aOrbiterH);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterF, 40U)) + aOrbiterJ);
            aWandererK = aWandererK + (((RotL64(aIngress, 21U) + aOrbiterA) + RotL64(aOrbiterJ, 21U)) + RotL64(aCarry, 23U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 46U) + RotL64(aOrbiterH, 3U)) + aOrbiterF);
            aWandererF = aWandererF + ((((RotL64(aScatter, 29U) + RotL64(aOrbiterE, 43U)) + aOrbiterA) + RotL64(aCarry, 29U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterF, 37U)) + aOrbiterK);
            aWandererC = aWandererC + (((RotL64(aPrevious, 39U) + aOrbiterC) + RotL64(aOrbiterG, 50U)) + aPhaseDWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 51U) + aOrbiterG) + RotL64(aOrbiterJ, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererD, 52U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererH);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 21U));
            aCarry = aCarry + RotL64(aWandererI, 14U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ aNonceWordB;
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 18481U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 19348U)) & S_BLOCK1], 44U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 20270U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((aIndex + 20011U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 11U) + RotL64(aCross, 23U)) ^ (RotL64(aCarry, 60U) ^ RotL64(aIngress, 37U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterK = ((aWandererD + RotL64(aIngress, 26U)) + RotL64(aCarry, 13U)) + 15045917390223766480U;
            aOrbiterG = (aWandererB + RotL64(aScatter, 41U)) + 10763054007033668758U;
            aOrbiterI = ((aWandererH + RotL64(aCross, 43U)) + RotL64(aCarry, 53U)) + 13190170142593666607U;
            aOrbiterB = (aWandererE + RotL64(aPrevious, 23U)) + 9657025731441167065U;
            aOrbiterD = ((aWandererK + RotL64(aIngress, 47U)) + 11433367178975954211U) + aPhaseDOrbiterAssignSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = (aWandererG + RotL64(aPrevious, 51U)) + 17904920143996810366U;
            aOrbiterJ = (aWandererI + RotL64(aCross, 39U)) + 3244383020512113283U;
            aOrbiterE = (aWandererJ + RotL64(aScatter, 5U)) + 6538815775171139091U;
            aOrbiterF = (((aWandererF + RotL64(aCross, 53U)) + 7195368312757976343U) + aPhaseDOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1]) + aNonceWordO;
            aOrbiterC = (aWandererA + RotL64(aIngress, 11U)) + 18134430713910279374U;
            aOrbiterA = (((aWandererC + RotL64(aPrevious, 14U)) + RotL64(aCarry, 35U)) + 6571776588427107976U) + aNonceWordK;
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 11830778129647517758U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 9793702760907767365U;
            aOrbiterI = RotL64((aOrbiterI * 4096246227968677179U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 2287235876793192036U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 8951959188326141794U;
            aOrbiterD = RotL64((aOrbiterD * 9968356718110753845U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 7583061790273240157U) + aNonceWordL;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 3571364625022806085U;
            aOrbiterH = RotL64((aOrbiterH * 6238360922735480669U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 13869345563551689212U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 277480328952975002U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1057564597096163085U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 4983735092494677578U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 9490022869381030928U;
            aOrbiterE = RotL64((aOrbiterE * 12926352917961703123U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 7928039573014765566U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 6504190875809407084U;
            aOrbiterF = RotL64((aOrbiterF * 14648214826494826711U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 2787985600176307413U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 16308785053443116826U;
            aOrbiterC = RotL64((aOrbiterC * 17867565986311256691U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 12788128335006767824U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 1187040019537798339U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10834905007658184183U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 10771230162770496645U) + aNonceWordG;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 6542421559654716320U;
            aOrbiterK = RotL64((aOrbiterK * 16829492790597069373U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 702458690970201679U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 2806140783487813070U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7415398198842270381U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 950611302199732036U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 15045917390223766480U;
            aOrbiterB = RotL64((aOrbiterB * 9358017420417979347U), 39U);
            //
            aIngress = RotL64(aOrbiterB, 3U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 47U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 19U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterF, 42U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterC, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aPrevious, 53U) + aOrbiterI) + RotL64(aOrbiterF, 21U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 26U) + RotL64(aOrbiterK, 37U)) + aOrbiterE);
            aWandererG = aWandererG + (((RotL64(aCross, 37U) + aOrbiterK) + RotL64(aOrbiterJ, 24U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterG, 27U)) + aOrbiterB);
            aWandererA = aWandererA + (((RotL64(aScatter, 47U) + RotL64(aOrbiterF, 29U)) + aOrbiterD) + aNonceWordJ);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterH, 19U)) + aOrbiterA);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterK, 3U)) + aOrbiterH) + RotL64(aCarry, 23U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 14U) + aOrbiterC) + RotL64(aOrbiterG, 48U));
            aWandererF = aWandererF + ((RotL64(aIngress, 19U) + aOrbiterC) + RotL64(aOrbiterH, 57U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterB, 35U)) + aOrbiterF);
            aWandererK = aWandererK + ((((RotL64(aCross, 23U) + aOrbiterE) + RotL64(aOrbiterD, 5U)) + RotL64(aCarry, 39U)) + aNonceWordE);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 42U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 51U));
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererI, 37U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + RotL64(aWandererA, 54U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ aNonceWordH;
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 22668U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 23785U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 26698U)) & S_BLOCK1], 36U) ^ RotL64(aOperationLaneA[((aIndex + 23694U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCarry, 5U)) + (RotL64(aCross, 37U) + RotL64(aPrevious, 20U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterF = (aWandererE + RotL64(aPrevious, 11U)) + 6771552164800695068U;
            aOrbiterH = ((aWandererA + RotL64(aScatter, 13U)) + 12131763371571322040U) + aNonceWordM;
            aOrbiterG = ((aWandererB + RotL64(aCross, 29U)) + 3326182381395522013U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = (aWandererH + RotL64(aIngress, 20U)) + 12288775097697156383U;
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 5U)) + 5195948373449796741U) + aNonceWordO;
            aOrbiterD = (aWandererG + RotL64(aIngress, 41U)) + 14404044002250137144U;
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 51U)) + RotL64(aCarry, 27U)) + 11142382920035825426U;
            aOrbiterC = ((aWandererI + RotL64(aScatter, 26U)) + RotL64(aCarry, 43U)) + 2967149520256475485U;
            aOrbiterK = (aWandererK + RotL64(aPrevious, 23U)) + 1470907369577818097U;
            aOrbiterE = ((aWandererF + RotL64(aIngress, 3U)) + RotL64(aCarry, 53U)) + 9231668148004163910U;
            aOrbiterB = (((aWandererD + RotL64(aScatter, 43U)) + 13078929163913892386U) + aPhaseDOrbiterAssignSaltF[((aIndex + 14U)) & S_SALT1]) + aNonceWordJ;
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 9485274692075657877U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 12216951187543631673U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6571066246507310805U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 6933334652581744234U) + aNonceWordN;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 17260276102423580920U;
            aOrbiterD = RotL64((aOrbiterD * 7796879893790990605U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 387767848169714392U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 8597538259308082638U;
            aOrbiterC = RotL64((aOrbiterC * 4888054690557707241U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 7996708724489146033U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 15357384191688149939U;
            aOrbiterE = RotL64((aOrbiterE * 9827691726832491373U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 17739222908739454637U) + aNonceWordD;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 1614322333281471170U;
            aOrbiterF = RotL64((aOrbiterF * 7063116837752240891U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 4531604274893197209U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 3453280714992341288U;
            aOrbiterI = RotL64((aOrbiterI * 8390029711127907805U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 116623650872661533U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 6565636510115095988U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9691897067492501177U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 10303258439817808058U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 10917642773040237611U;
            aOrbiterK = RotL64((aOrbiterK * 10232856828372963363U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 2087058228468680821U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 3691125545393861889U;
            aOrbiterB = RotL64((aOrbiterB * 1768745056298937903U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 9240209357066002219U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 7645250700232422804U;
            aOrbiterH = RotL64((aOrbiterH * 6762116797395687607U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 9859862257084218280U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 6771552164800695068U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11063630807191661109U), 21U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 21U);
            aIngress = aIngress + (RotL64(aOrbiterF, 41U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterE, 51U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterI, 54U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 39U));
            aIngress = aIngress + RotL64(aOrbiterA, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 58U) + aOrbiterI) + RotL64(aOrbiterB, 39U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 43U) + RotL64(aOrbiterF, 23U)) + aOrbiterK) + RotL64(aCarry, 5U)) + aPhaseDWandererUpdateSaltB[((aIndex + 16U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 39U) + aOrbiterG) + RotL64(aOrbiterD, 53U));
            aWandererF = aWandererF + (((RotL64(aCross, 41U) + RotL64(aOrbiterG, 60U)) + aOrbiterF) + RotL64(aCarry, 47U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 56U) + RotL64(aOrbiterE, 51U)) + aOrbiterF);
            aWandererA = aWandererA + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterH, 3U)) + aOrbiterI);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterA, 41U)) + aOrbiterI);
            aWandererB = aWandererB + (((RotL64(aCross, 47U) + RotL64(aOrbiterJ, 5U)) + aOrbiterH) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 3U) + aOrbiterB) + RotL64(aOrbiterK, 14U)) + aNonceWordK);
            aWandererE = aWandererE + ((RotL64(aIngress, 13U) + aOrbiterC) + RotL64(aOrbiterA, 35U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterE, 47U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 30U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (RotL64(aWandererB, 5U) ^ aWandererF);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 20U));
            aCarry = aCarry + RotL64(aWandererC, 43U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordC);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 28347U)) & S_BLOCK1], 20U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28229U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 32497U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32088U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 29U) ^ RotL64(aPrevious, 43U)) ^ (RotL64(aCarry, 10U) + RotL64(aIngress, 57U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 23U)) + RotL64(aCarry, 29U)) + 7825479804710770560U;
            aOrbiterK = ((aWandererI + RotL64(aCross, 51U)) + 5298124167101358123U) + aPhaseDOrbiterAssignSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = (aWandererA + RotL64(aScatter, 5U)) + 17774541024369233726U;
            aOrbiterD = (aWandererC + RotL64(aPrevious, 37U)) + 7679371833537454082U;
            aOrbiterG = ((aWandererK + RotL64(aCross, 53U)) + RotL64(aCarry, 3U)) + 5385914900748772224U;
            aOrbiterH = (aWandererH + RotL64(aIngress, 42U)) + 3879781930908486531U;
            aOrbiterF = ((aWandererE + RotL64(aScatter, 3U)) + 659110346638873236U) + aNonceWordP;
            aOrbiterE = (aWandererG + RotL64(aPrevious, 11U)) + 10749021728538539749U;
            aOrbiterB = (aWandererB + RotL64(aCross, 21U)) + 3631252455767429457U;
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 29U)) + 2271978810960685021U) + aPhaseDOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 44U)) + RotL64(aCarry, 39U)) + 5963558780692551176U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 974909966119198104U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 9296998242911152296U;
            aOrbiterI = RotL64((aOrbiterI * 2613629915877957661U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 2245318466901521959U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 13391076374843288568U;
            aOrbiterG = RotL64((aOrbiterG * 18094558036982107419U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 6184487746594236737U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 1563385912137291418U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4805455299959232321U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 1744840092006498629U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 2100927276837188416U;
            aOrbiterF = RotL64((aOrbiterF * 3541788262067077997U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 9998911862807246338U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 12239948725635220096U;
            aOrbiterE = RotL64((aOrbiterE * 7098620484129489129U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 3307447094994950246U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 12746613971448298932U;
            aOrbiterB = RotL64((aOrbiterB * 9463975886346934681U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 11577488293733790649U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 191108997585598809U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9574978681405356871U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 18096145693841273722U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 10026281133603934071U;
            aOrbiterJ = RotL64((aOrbiterJ * 17261343107314203471U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 2346682418062064668U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 2996178204018644206U;
            aOrbiterA = RotL64((aOrbiterA * 2552965800703390909U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 15085425896818988223U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 1589593231782852588U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1535556765195388675U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 17170695588248383518U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 7825479804710770560U) ^ aNonceWordC;
            aOrbiterD = RotL64((aOrbiterD * 7434218282170150533U), 53U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterE, 27U);
            aIngress = aIngress + (RotL64(aOrbiterI, 3U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 38U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 13U));
            aIngress = aIngress + (RotL64(aOrbiterC, 29U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aScatter, 3U) + aOrbiterB) + RotL64(aOrbiterI, 54U)) + aNonceWordD);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterJ, 29U)) + aOrbiterG) + aPhaseDWandererUpdateSaltC[((aIndex + 12U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 22U) + RotL64(aOrbiterD, 27U)) + aOrbiterJ) + aNonceWordB);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterI, 51U)) + aOrbiterG);
            aWandererA = aWandererA + ((RotL64(aScatter, 51U) + aOrbiterK) + RotL64(aOrbiterA, 13U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterE, 35U)) + aOrbiterJ);
            aWandererK = aWandererK + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterD, 19U)) + aOrbiterK) + aPhaseDWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 5U) + aOrbiterB) + RotL64(aOrbiterK, 4U));
            aWandererD = aWandererD + (((RotL64(aCross, 39U) + RotL64(aOrbiterC, 47U)) + aOrbiterB) + RotL64(aCarry, 35U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 20U) + aOrbiterG) + RotL64(aOrbiterH, 23U)) + aNonceWordH);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 13U) + aOrbiterH) + RotL64(aOrbiterF, 39U)) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 39U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererH, 14U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererE, 21U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 37U));
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererD, 60U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordL);
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

void TwistExpander_BaseBall_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x8CF22CBB092FE8EFULL + 0xC8D5FEE7F75F1708ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x9D2835BE97B73A67ULL + 0x8A381B19BB64DA84ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x84A43AE0CE64E0CDULL + 0xB30D0FCB6C63947AULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xEDDB648729429A2FULL + 0xA61E57AFADE41A7FULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x80F309B455DCA247ULL + 0xE9E6032D5710566CULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xAA5F4580383854A5ULL + 0x8933F2A30A0F4B90ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xD2A597FBA826E275ULL + 0x83AF70A53C7CDA9DULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x80C25687BA12B593ULL + 0xC4ED441BD972E893ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xD0F0E8C88AA9C8B9ULL + 0x9FD42795C349000FULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xD49D32FEE6655B67ULL + 0xEB02D7DDB265AECEULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xF1162D8EFC26E59BULL + 0xFA5977B394B92792ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xE8D404547785690FULL + 0xDF7C32CBD74E8F74ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xA225803B5BAC0E8FULL + 0xAE1062E0C6DF39EFULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x9706753F7F0277C7ULL + 0x84D6BA0345E7CC3EULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xC723AC4A87900215ULL + 0xF8432BCAC518DEECULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xD424D3C86682F679ULL + 0xA7C611D9B5D3C361ULL);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 3758U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneC[((aIndex + 2742U)) & S_BLOCK1], 50U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 4114U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 4809U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 41U) + RotL64(aCarry, 53U)) ^ (RotL64(aCross, 23U) ^ RotL64(aIngress, 6U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterI = (aWandererC + RotL64(aIngress, 43U)) + 6771552164800695068U;
            aOrbiterH = (((aWandererG + RotL64(aCross, 3U)) + RotL64(aCarry, 41U)) + 12131763371571322040U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 53U)) + RotL64(aCarry, 47U)) + 3326182381395522013U;
            aOrbiterE = ((aWandererE + RotL64(aScatter, 29U)) + 12288775097697156383U) + aNonceWordO;
            aOrbiterD = ((aWandererD + RotL64(aIngress, 56U)) + 5195948373449796741U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = ((aWandererB + RotL64(aCross, 23U)) + 14404044002250137144U) + aNonceWordA;
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 35U)) + 11142382920035825426U) + aNonceWordB;
            aOrbiterG = (aWandererA + RotL64(aScatter, 27U)) + 2967149520256475485U;
            aOrbiterC = (aWandererF + RotL64(aCross, 46U)) + 1470907369577818097U;
            aOrbiterK = (aWandererJ + RotL64(aScatter, 5U)) + 9231668148004163910U;
            aOrbiterJ = ((aWandererK + RotL64(aIngress, 51U)) + RotL64(aCarry, 53U)) + 13078929163913892386U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 9485274692075657877U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 12216951187543631673U;
            aOrbiterB = RotL64((aOrbiterB * 6571066246507310805U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 6933334652581744234U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 17260276102423580920U) ^ aNonceWordD;
            aOrbiterF = RotL64((aOrbiterF * 7796879893790990605U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 387767848169714392U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 8597538259308082638U) ^ aNonceWordP;
            aOrbiterI = RotL64((aOrbiterI * 4888054690557707241U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 7996708724489146033U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 15357384191688149939U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9827691726832491373U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 17739222908739454637U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 1614322333281471170U;
            aOrbiterA = RotL64((aOrbiterA * 7063116837752240891U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 4531604274893197209U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 3453280714992341288U;
            aOrbiterC = RotL64((aOrbiterC * 8390029711127907805U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 116623650872661533U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 6565636510115095988U;
            aOrbiterJ = RotL64((aOrbiterJ * 9691897067492501177U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 10303258439817808058U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 10917642773040237611U;
            aOrbiterH = RotL64((aOrbiterH * 10232856828372963363U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 2087058228468680821U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 3691125545393861889U;
            aOrbiterD = RotL64((aOrbiterD * 1768745056298937903U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 9240209357066002219U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 7645250700232422804U) ^ aNonceWordE;
            aOrbiterG = RotL64((aOrbiterG * 6762116797395687607U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 9859862257084218280U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 6771552164800695068U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11063630807191661109U), 13U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterK, 41U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 39U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 14U));
            aIngress = aIngress + (RotL64(aOrbiterA, 27U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterH, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aScatter, 53U) + aOrbiterD) + RotL64(aOrbiterE, 48U)) + RotL64(aCarry, 39U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 48U) + RotL64(aOrbiterK, 21U)) + aOrbiterB) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 43U) + aOrbiterG) + RotL64(aOrbiterH, 11U)) + RotL64(aCarry, 47U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterH, 41U)) + aOrbiterD);
            aWandererA = aWandererA + ((RotL64(aIngress, 57U) + aOrbiterK) + RotL64(aOrbiterA, 53U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 3U) + aOrbiterJ) + RotL64(aOrbiterA, 6U)) + aNonceWordF);
            aWandererD = aWandererD + (((RotL64(aCross, 11U) + aOrbiterH) + RotL64(aOrbiterI, 37U)) + aNonceWordL);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterC, 27U)) + aOrbiterK);
            aWandererB = aWandererB + ((RotL64(aScatter, 46U) + aOrbiterH) + RotL64(aOrbiterK, 35U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterD, 43U)) + aOrbiterF) + aPhaseEWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aIngress, 51U) + RotL64(aOrbiterK, 29U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 48U));
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererI);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 5U));
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererB, 50U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ aNonceWordN;
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 5984U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneD[((aIndex + 9737U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 8303U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneB[((aIndex + 9496U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCross, 19U)) + (RotL64(aCarry, 36U) + RotL64(aIngress, 5U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterJ = (aWandererE + RotL64(aPrevious, 57U)) + 252059974543142812U;
            aOrbiterC = ((aWandererA + RotL64(aScatter, 27U)) + RotL64(aCarry, 21U)) + 11690823093681457368U;
            aOrbiterB = (aWandererB + RotL64(aCross, 48U)) + 13282189752890971123U;
            aOrbiterG = (aWandererJ + RotL64(aIngress, 53U)) + 9507416294305708435U;
            aOrbiterI = (aWandererH + RotL64(aCross, 13U)) + 14053038174390776539U;
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 5U)) + 14605253312318725009U) + aNonceWordB;
            aOrbiterD = ((aWandererG + RotL64(aIngress, 19U)) + 18138286582677863671U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = (aWandererI + RotL64(aScatter, 37U)) + 8530091235978489988U;
            aOrbiterE = (((aWandererC + RotL64(aPrevious, 43U)) + RotL64(aCarry, 11U)) + 14381731677571170073U) + aNonceWordC;
            aOrbiterH = ((aWandererD + RotL64(aCross, 51U)) + 13316413456378978456U) + aPhaseEOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aIngress, 34U)) + RotL64(aCarry, 3U)) + 3910529530149320706U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 6302070286831566901U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 12324134652758551396U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17136438281540250165U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 4773478557638475048U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 4031153435446078944U;
            aOrbiterC = RotL64((aOrbiterC * 3876928995240982769U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 3114794895962903899U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 3552936509969106796U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16823186892738820299U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 5828754613946145627U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 17985241114076114558U;
            aOrbiterD = RotL64((aOrbiterD * 1986669631395606833U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 11319331046368072261U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 6104267020171882160U;
            aOrbiterE = RotL64((aOrbiterE * 12525117969211576177U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 7662668379725735125U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 6583034411403600735U;
            aOrbiterJ = RotL64((aOrbiterJ * 262095656452193889U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 5569865728026310280U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 4176065898330374039U;
            aOrbiterG = RotL64((aOrbiterG * 11305749530796963967U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 13677146592276526676U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 2734371113158117596U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13146444882662731975U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 14890607377967461739U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 3110674898918355049U) ^ aNonceWordI;
            aOrbiterA = RotL64((aOrbiterA * 9637837600671200315U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 15329760212453783067U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 18214263442264013242U) ^ aNonceWordO;
            aOrbiterH = RotL64((aOrbiterH * 9139354822936682953U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 6727267537859989206U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 252059974543142812U;
            aOrbiterF = RotL64((aOrbiterF * 9559128226993261041U), 35U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 57U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 11U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 47U));
            aIngress = aIngress + (RotL64(aOrbiterD, 43U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterI, 4U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterE, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterE, 60U)) + aOrbiterF) + aNonceWordN);
            aWandererK = aWandererK + ((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 29U)) + aOrbiterB);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterA, 5U)) + aOrbiterB) + aNonceWordG);
            aWandererD = aWandererD + (((RotL64(aCross, 42U) + RotL64(aOrbiterC, 11U)) + aOrbiterE) + aNonceWordD);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterI, 21U)) + aOrbiterJ);
            aWandererG = aWandererG + (((RotL64(aCross, 39U) + aOrbiterD) + RotL64(aOrbiterA, 37U)) + RotL64(aCarry, 19U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 35U) + aOrbiterI) + RotL64(aOrbiterG, 51U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 37U) + aOrbiterI) + RotL64(aOrbiterK, 18U)) + RotL64(aCarry, 11U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterJ, 43U)) + aOrbiterH);
            aWandererJ = aWandererJ + ((RotL64(aCross, 30U) + aOrbiterI) + RotL64(aOrbiterB, 3U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterI, 53U)) + aOrbiterH) + aPhaseEWandererUpdateSaltA[((aIndex + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 34U) ^ aWandererC);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + (RotL64(aWandererI, 21U) ^ aWandererJ);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 11U));
            aCarry = aCarry + RotL64(aWandererK, 37U);
            aCarry = aCarry + RotL64(aIngress, 24U);
            aCarry = aCarry ^ aNonceWordA;
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 15350U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneA[((aIndex + 15946U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 12691U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneC[((aIndex + 13520U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 6U) ^ RotL64(aCross, 53U)) ^ (RotL64(aIngress, 19U) + RotL64(aCarry, 37U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterC = (aWandererJ + RotL64(aPrevious, 58U)) + 3970829908171131502U;
            aOrbiterJ = (aWandererC + RotL64(aIngress, 27U)) + 7040283759419531991U;
            aOrbiterI = ((aWandererG + RotL64(aScatter, 11U)) + RotL64(aCarry, 41U)) + 11856292169397052901U;
            aOrbiterF = ((aWandererE + RotL64(aCross, 37U)) + RotL64(aCarry, 3U)) + 819598588791819022U;
            aOrbiterB = (aWandererF + RotL64(aIngress, 51U)) + 2176451710970866848U;
            aOrbiterE = (aWandererK + RotL64(aPrevious, 39U)) + 6454704928613390494U;
            aOrbiterD = (aWandererB + RotL64(aScatter, 23U)) + 11792122387218053841U;
            aOrbiterA = ((aWandererA + RotL64(aCross, 21U)) + 9254780213489752211U) + aNonceWordK;
            aOrbiterH = ((aWandererH + RotL64(aScatter, 41U)) + 16591812589999846482U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = (((aWandererD + RotL64(aPrevious, 54U)) + 1471246223935074832U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordO;
            aOrbiterK = ((aWandererI + RotL64(aIngress, 43U)) + RotL64(aCarry, 23U)) + 1424843083106386453U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 1856469958050891629U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 6331743690452052712U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15327924647897459645U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 10351075711345476487U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 9518585245330480185U;
            aOrbiterE = RotL64((aOrbiterE * 3792179827396760391U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 17787514620244712033U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 14182328067398162557U;
            aOrbiterJ = RotL64((aOrbiterJ * 18107337388659070197U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 12798088948801072444U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 9563215159275202323U;
            aOrbiterB = RotL64((aOrbiterB * 7058145016617349141U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 9904919772580498232U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 16579777394992143043U;
            aOrbiterA = RotL64((aOrbiterA * 10516761340320196661U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 6344049286854588503U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 3531503618941046788U;
            aOrbiterG = RotL64((aOrbiterG * 10855385899703024105U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 11334308840132700377U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 11093833870078787770U;
            aOrbiterC = RotL64((aOrbiterC * 16105889714648555755U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 3831491136025364271U) + aNonceWordA;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 12505259454860591372U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6135450888433504093U), 37U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterK) + 2210290810330253363U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordB;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 10786160915224323113U;
            aOrbiterD = RotL64((aOrbiterD * 799075068398619501U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 7791474921127653867U) + aNonceWordH;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 1046454625851499863U;
            aOrbiterH = RotL64((aOrbiterH * 18040454167287729591U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 14636813124839719351U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 3970829908171131502U;
            aOrbiterK = RotL64((aOrbiterK * 2737568880005765517U), 51U);
            //
            aIngress = RotL64(aOrbiterA, 19U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterC, 60U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 39U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterF, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aIngress, 41U) + aOrbiterH) + RotL64(aOrbiterD, 43U)) + aNonceWordJ);
            aWandererB = aWandererB ^ ((RotL64(aCross, 53U) + aOrbiterC) + RotL64(aOrbiterH, 6U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterG, 47U)) + aOrbiterJ) + aNonceWordD);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 58U) + RotL64(aOrbiterJ, 11U)) + aOrbiterE);
            aWandererA = aWandererA + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterI, 35U)) + aOrbiterK) + RotL64(aCarry, 41U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterA, 41U)) + aOrbiterF);
            aWandererH = aWandererH + ((((RotL64(aScatter, 27U) + RotL64(aOrbiterK, 3U)) + aOrbiterD) + RotL64(aCarry, 53U)) + aPhaseEWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 30U) + aOrbiterJ) + RotL64(aOrbiterC, 39U));
            aWandererI = aWandererI + ((RotL64(aScatter, 5U) + RotL64(aOrbiterG, 14U)) + aOrbiterE);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 47U) + aOrbiterI) + RotL64(aOrbiterB, 51U));
            aWandererE = aWandererE + (((RotL64(aCross, 23U) + aOrbiterA) + RotL64(aOrbiterK, 53U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 18U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererG, 41U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererI);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 21U));
            aCarry = aCarry + RotL64(aWandererD, 35U);
            aCarry = aCarry + RotL64(aIngress, 28U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordP);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 18140U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneB[((aIndex + 16798U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 19122U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneD[((aIndex + 20418U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 11U) ^ RotL64(aIngress, 37U)) ^ (RotL64(aPrevious, 51U) + RotL64(aCarry, 24U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterC = ((aWandererC + RotL64(aCross, 52U)) + RotL64(aCarry, 43U)) + 11450949896247900941U;
            aOrbiterK = (((aWandererH + RotL64(aIngress, 47U)) + RotL64(aCarry, 23U)) + 3905542253538116335U) + aPhaseEOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = ((aWandererE + RotL64(aScatter, 13U)) + 9529740545977785305U) + aNonceWordJ;
            aOrbiterB = (aWandererB + RotL64(aPrevious, 37U)) + 1856876631533143492U;
            aOrbiterA = (aWandererD + RotL64(aScatter, 29U)) + 84253466320181686U;
            aOrbiterI = (aWandererJ + RotL64(aCross, 3U)) + 12577480918745432444U;
            aOrbiterH = (((aWandererF + RotL64(aPrevious, 43U)) + 5625703170397704029U) + aPhaseEOrbiterAssignSaltF[((aIndex + 28U)) & S_SALT1]) + aNonceWordM;
            aOrbiterG = (aWandererK + RotL64(aIngress, 5U)) + 694608607323629282U;
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 10U)) + RotL64(aCarry, 39U)) + 3993981243536262204U;
            aOrbiterE = (aWandererA + RotL64(aScatter, 35U)) + 4119215953484892051U;
            aOrbiterJ = (aWandererI + RotL64(aIngress, 39U)) + 8785040118556157146U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 16234403619456882890U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 10398727475672860610U;
            aOrbiterD = RotL64((aOrbiterD * 5086871400049644715U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 18327987141759096769U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 2645964788056875452U;
            aOrbiterA = RotL64((aOrbiterA * 8778681366114628045U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 2859452497983106129U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 7196557924940881076U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14415389907490256711U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 930127943984174668U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 15673596916054795749U;
            aOrbiterH = RotL64((aOrbiterH * 7505660488733199479U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 16673140529110941163U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 2258448294877833760U;
            aOrbiterG = RotL64((aOrbiterG * 1821550319748977445U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 6870209259643931219U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 12749790107942194104U;
            aOrbiterF = RotL64((aOrbiterF * 4871407285968611725U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 17131374134617173866U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 6426448390733751612U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12490559588384058417U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 15592826434339731146U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 14182944418026376183U;
            aOrbiterJ = RotL64((aOrbiterJ * 7218860482893476233U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 17447476498234456596U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 972861017466618022U;
            aOrbiterC = RotL64((aOrbiterC * 9610670431280153921U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 13185309156950240549U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 14442284480744008537U;
            aOrbiterK = RotL64((aOrbiterK * 2907844852105175837U), 21U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterC) + 7816745313858811117U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordE;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 11450949896247900941U;
            aOrbiterB = RotL64((aOrbiterB * 18317765298694454463U), 39U);
            //
            aIngress = RotL64(aOrbiterK, 51U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterD, 40U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 27U));
            aIngress = aIngress + (RotL64(aOrbiterE, 11U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterF, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aIngress, 30U) + aOrbiterK) + RotL64(aOrbiterC, 48U)) + aNonceWordA) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterE, 43U)) + aOrbiterF);
            aWandererD = aWandererD + (((RotL64(aScatter, 51U) + RotL64(aOrbiterE, 19U)) + aOrbiterI) + RotL64(aCarry, 29U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterH, 37U)) + aOrbiterJ);
            aWandererK = aWandererK + (((RotL64(aIngress, 41U) + RotL64(aOrbiterD, 3U)) + aOrbiterE) + RotL64(aCarry, 41U));
            aWandererB = aWandererB ^ ((((RotL64(aCross, 35U) + aOrbiterH) + RotL64(aOrbiterB, 5U)) + aNonceWordD) + aPhaseEWandererUpdateSaltD[((aIndex + 4U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aScatter, 23U) + RotL64(aOrbiterI, 35U)) + aOrbiterA);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 18U) + RotL64(aOrbiterB, 50U)) + aOrbiterG);
            aWandererE = aWandererE + ((RotL64(aCross, 27U) + RotL64(aOrbiterB, 53U)) + aOrbiterJ);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 11U) + aOrbiterB) + RotL64(aOrbiterI, 11U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 37U) + RotL64(aOrbiterE, 29U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererI, 30U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererE, 53U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererG);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 21U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 58U));
            aCarry = aCarry + RotL64(aWandererC, 5U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ aNonceWordF;
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 23131U)) & S_BLOCK1], 6U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25337U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 24589U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22178U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 35U) ^ RotL64(aIngress, 5U)) ^ (RotL64(aCross, 53U) + RotL64(aPrevious, 20U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterI = (aWandererK + RotL64(aScatter, 3U)) + 9914837590440975587U;
            aOrbiterK = ((aWandererF + RotL64(aCross, 41U)) + 6706125076401958051U) + aNonceWordL;
            aOrbiterA = (aWandererE + RotL64(aIngress, 29U)) + 16570817772679258409U;
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 43U)) + RotL64(aCarry, 41U)) + 6843705658115186948U;
            aOrbiterD = (aWandererD + RotL64(aCross, 22U)) + 16099930446791572351U;
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 47U)) + 5420550009556030459U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 57U)) + 5729549069420177477U) + aNonceWordC;
            aOrbiterF = ((aWandererG + RotL64(aIngress, 27U)) + RotL64(aCarry, 21U)) + 15590601126188675834U;
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 14U)) + 13044027390998620029U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = ((aWandererH + RotL64(aCross, 37U)) + RotL64(aCarry, 3U)) + 11068338135659636772U;
            aOrbiterE = (aWandererB + RotL64(aScatter, 35U)) + 6584988841809544332U;
            //
            aOrbiterI = (((aOrbiterI + aOrbiterK) + 8516813219883915404U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordE;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 10647314042912492785U;
            aOrbiterA = RotL64((aOrbiterA * 15559481057047148785U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 201691689889605304U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 15512161798401184003U;
            aOrbiterJ = RotL64((aOrbiterJ * 11473219183982564709U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 3883760518944464145U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 13861805129175491145U;
            aOrbiterF = RotL64((aOrbiterF * 17194438894492581181U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 12019138626550801486U) + aNonceWordN;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 13030350224959652248U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11724200983306280107U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 2643807255422544248U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 4127143302485631794U;
            aOrbiterI = RotL64((aOrbiterI * 5441038881111578487U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 14602951930809633069U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 4555737199162278494U;
            aOrbiterH = RotL64((aOrbiterH * 12415825635220991865U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 6343143902997169834U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 10404783711336491985U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6235474458879439079U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 7406959231434835393U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 6684368109277850196U;
            aOrbiterC = RotL64((aOrbiterC * 8760360417572331159U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 4835889355927954728U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 7917682889852676712U;
            aOrbiterE = RotL64((aOrbiterE * 9045350756570117327U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 10268055422944417055U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 5563744562922937643U;
            aOrbiterK = RotL64((aOrbiterK * 12442484191329795173U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 17244672945880141679U) + aNonceWordP;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 9914837590440975587U;
            aOrbiterD = RotL64((aOrbiterD * 12269340309792850489U), 47U);
            //
            aIngress = RotL64(aOrbiterA, 21U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 47U));
            aIngress = aIngress + (RotL64(aOrbiterC, 51U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 23U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 54U));
            aIngress = aIngress + RotL64(aOrbiterE, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterK, 5U)) + aOrbiterG);
            aWandererI = aWandererI + (((RotL64(aIngress, 27U) + RotL64(aOrbiterF, 58U)) + aOrbiterB) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 42U) + aOrbiterA) + RotL64(aOrbiterC, 21U)) + aNonceWordJ);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 53U) + RotL64(aOrbiterH, 51U)) + aOrbiterG) + RotL64(aCarry, 43U)) + aPhaseEWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 37U) + aOrbiterI) + RotL64(aOrbiterB, 29U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterF, 39U)) + aOrbiterC) + aNonceWordB);
            aWandererA = aWandererA ^ ((RotL64(aCross, 30U) + RotL64(aOrbiterH, 27U)) + aOrbiterA);
            aWandererH = aWandererH + (((RotL64(aIngress, 21U) + RotL64(aOrbiterI, 41U)) + aOrbiterJ) + RotL64(aCarry, 5U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterD, 53U)) + aOrbiterC) + aNonceWordI);
            aWandererC = aWandererC + ((RotL64(aIngress, 57U) + aOrbiterK) + RotL64(aOrbiterJ, 24U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 35U) + aOrbiterK) + RotL64(aOrbiterE, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererA);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 11U));
            aCarry = aCarry + (RotL64(aWandererB, 18U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 37U));
            aCarry = aCarry + (RotL64(aWandererI, 53U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererC, 29U);
            aCarry = aCarry + RotL64(aIngress, 50U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordO);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 32500U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31031U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 27790U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27625U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCarry, 21U)) ^ (RotL64(aCross, 52U) + RotL64(aPrevious, 35U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterI = (aWandererC + RotL64(aIngress, 11U)) + 15316464782468770057U;
            aOrbiterB = ((aWandererG + RotL64(aCross, 23U)) + 6642872057476351588U) + aNonceWordI;
            aOrbiterG = (aWandererF + RotL64(aPrevious, 51U)) + 660732654689529192U;
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 39U)) + 7235418086884000655U) + aNonceWordP;
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 34U)) + RotL64(aCarry, 47U)) + 14784518476694580493U;
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 27U)) + 12222433977933449375U) + aPhaseEOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = ((aWandererE + RotL64(aCross, 29U)) + RotL64(aCarry, 57U)) + 8573001207708329927U;
            aOrbiterH = (aWandererH + RotL64(aScatter, 3U)) + 16035256260815013172U;
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 53U)) + 15767726974121910203U) + aPhaseEOrbiterAssignSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = (aWandererI + RotL64(aCross, 41U)) + 17712217935322939971U;
            aOrbiterD = ((aWandererD + RotL64(aScatter, 58U)) + RotL64(aCarry, 19U)) + 13488963456923357159U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 10222949131965611079U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterI) ^ 1495561412321657209U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterG = RotL64((aOrbiterG * 9706305581868526265U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 16156530750584361434U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 7773792489045606309U;
            aOrbiterE = RotL64((aOrbiterE * 10730624207715601393U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 11544578291333360613U) + aNonceWordE;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 3665587867634242865U;
            aOrbiterF = RotL64((aOrbiterF * 4840528190844842595U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 15248434984650998090U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 15487979645426567581U;
            aOrbiterA = RotL64((aOrbiterA * 10868107809356766183U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 6972347795052712690U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 16074994810010431338U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1262655238856775853U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 16851139687900415292U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 14630026837021552812U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9577900853521254603U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 14236330619137368169U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 17778707026111136216U;
            aOrbiterK = RotL64((aOrbiterK * 16239561893843454747U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 9390961969105999083U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 1174881758316573228U;
            aOrbiterD = RotL64((aOrbiterD * 6602061268277529311U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 3025148570039849574U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 2813499258480831171U;
            aOrbiterI = RotL64((aOrbiterI * 12272555492688861861U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 15397952138592662354U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 10394648143430175275U;
            aOrbiterB = RotL64((aOrbiterB * 18195627209519212303U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 3043205345760158739U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 15316464782468770057U;
            aOrbiterJ = RotL64((aOrbiterJ * 8162506622688910545U), 47U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterD, 37U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 30U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 23U));
            aIngress = aIngress + (RotL64(aOrbiterK, 5U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterF, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aPrevious, 5U) + aOrbiterH) + RotL64(aOrbiterG, 43U)) + RotL64(aCarry, 35U)) + aNonceWordB);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterC, 41U)) + aOrbiterJ);
            aWandererB = aWandererB + (((RotL64(aIngress, 39U) + aOrbiterG) + RotL64(aOrbiterI, 11U)) + aNonceWordF);
            aWandererF = aWandererF ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterK, 26U)) + aOrbiterB);
            aWandererD = aWandererD + ((((RotL64(aScatter, 14U) + RotL64(aOrbiterF, 29U)) + aOrbiterE) + RotL64(aCarry, 11U)) + aNonceWordM);
            aWandererC = aWandererC ^ (((RotL64(aCross, 53U) + aOrbiterC) + RotL64(aOrbiterA, 57U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 11U) + RotL64(aOrbiterH, 35U)) + aOrbiterB);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 35U) + aOrbiterD) + RotL64(aOrbiterE, 46U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 50U) + RotL64(aOrbiterG, 19U)) + aOrbiterA) + aPhaseEWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 41U) + aOrbiterD) + RotL64(aOrbiterK, 39U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterD, 21U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererF, 38U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = aCarry ^ aNonceWordJ;
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

void TwistExpander_BaseBall_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xAED167C0A0050DFDULL + 0xCA69A0AD679F6654ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xC37EB51E1C3A1DA7ULL + 0xB4A28ED93CB27544ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xC2D81C9DD065ADEFULL + 0x8E620A5D4BE08D18ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xE60D51E0DD8DAC51ULL + 0xB6A04F8C4EBE5A9DULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xCFD748EB41A81B3FULL + 0xF49443F0FC471F64ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xDDA49E17E38435EBULL + 0xD033AACBD5784732ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xCACD8BADA817E9F5ULL + 0xB2EA5C3139EF9199ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xCF71D49F9FD5F603ULL + 0x846C840BEF3DB985ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x9B8A24256000D5EFULL + 0xBC3C51E5AD5B9E5CULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xCEF149EF9FCC44E3ULL + 0xD8E5AD6CFE7A2538ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xF1CD792FF0341AD9ULL + 0x84330BCD060C89BDULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xF1FEF1B0E87399C1ULL + 0x8131EB43346C6131ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xEDBF07B6E18796CBULL + 0x8BFFE04230275B42ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xC7F5FAAFA7410ED5ULL + 0xF4F0AB540B055B58ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x976D01E8081EF40BULL + 0xF8A8BCC01C3F80B7ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x9C9418132189FF25ULL + 0xCA881C9BC5C51B4AULL);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 3140U)) & S_BLOCK1], 18U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4913U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 4387U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 386U)) & S_BLOCK1], 28U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aPrevious, 3U)) ^ (RotL64(aIngress, 38U) ^ RotL64(aCross, 19U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 43U)) + RotL64(aCarry, 39U)) + 8367680518550579791U;
            aOrbiterH = (aWandererC + RotL64(aIngress, 3U)) + 11491674725611181241U;
            aOrbiterC = ((aWandererE + RotL64(aScatter, 6U)) + 16673861720782164214U) + aNonceWordI;
            aOrbiterF = ((aWandererH + RotL64(aCross, 51U)) + 9786610124108350855U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = (aWandererK + RotL64(aPrevious, 13U)) + 5745080601557577637U;
            aOrbiterA = (aWandererI + RotL64(aScatter, 47U)) + 1959402215131684684U;
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 37U)) + RotL64(aCarry, 43U)) + 6121650036079196522U;
            aOrbiterK = (aWandererA + RotL64(aCross, 11U)) + 12016309761037342392U;
            aOrbiterJ = (aWandererG + RotL64(aScatter, 26U)) + 5986936646177049603U;
            aOrbiterD = ((aWandererD + RotL64(aCross, 57U)) + RotL64(aCarry, 57U)) + 1000367700904043468U;
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 29U)) + 17425288243569101032U) + aPhaseFOrbiterAssignSaltE[((aIndex + 4U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 4856917474950325209U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 16312111093223166419U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11046477664487805241U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 456110002032422270U) + aNonceWordL;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 11393724374787795662U;
            aOrbiterA = RotL64((aOrbiterA * 1176984359123668389U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 8378176867715697176U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 8086186452345234815U;
            aOrbiterB = RotL64((aOrbiterB * 8450438271765985235U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 8470349167474173245U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 2528229938740192694U;
            aOrbiterF = RotL64((aOrbiterF * 8717790851266520943U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 13247168811545753141U) + aNonceWordB;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 8745293957516815264U;
            aOrbiterE = RotL64((aOrbiterE * 14270617180621072619U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 6165915500564961987U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 12015407798844173213U;
            aOrbiterJ = RotL64((aOrbiterJ * 3913451986559154153U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 545006684939922156U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 16366753936267185001U;
            aOrbiterI = RotL64((aOrbiterI * 6495185976430013201U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 3097605623436091728U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 15950167830259022926U;
            aOrbiterH = RotL64((aOrbiterH * 4415538963984293323U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 8356327899232213426U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 10183421678251169945U;
            aOrbiterG = RotL64((aOrbiterG * 9474380650337109299U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 16327340177970834683U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 7086901180933495535U;
            aOrbiterK = RotL64((aOrbiterK * 1276521829484494857U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 13421211370092080006U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 8367680518550579791U;
            aOrbiterD = RotL64((aOrbiterD * 12256662446176946163U), 27U);
            //
            aIngress = RotL64(aOrbiterG, 41U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterJ, 21U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 47U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 60U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + RotL64(aOrbiterI, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((((RotL64(aPrevious, 43U) + RotL64(aOrbiterI, 53U)) + aOrbiterB) + aNonceWordD) + aPhaseFWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aCross, 46U) + aOrbiterA) + RotL64(aOrbiterC, 28U)) + RotL64(aCarry, 11U)) + aNonceWordC);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterJ, 43U)) + aOrbiterG);
            aWandererC = aWandererC + (((RotL64(aIngress, 21U) + RotL64(aOrbiterE, 23U)) + aOrbiterB) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterA, 51U)) + aOrbiterK) + aPhaseFWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 27U) + RotL64(aOrbiterF, 47U)) + aOrbiterA) + aNonceWordA);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 48U) + aOrbiterH) + RotL64(aOrbiterA, 41U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterE, 13U)) + aOrbiterJ);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 51U) + aOrbiterD) + RotL64(aOrbiterE, 19U));
            aWandererF = aWandererF + ((RotL64(aScatter, 13U) + aOrbiterJ) + RotL64(aOrbiterH, 30U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterA, 35U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 51U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 6U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + (RotL64(aWandererI, 53U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererF, 11U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordE);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 5917U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneD[((aIndex + 9162U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 9955U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneB[((aIndex + 5686U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 6U) ^ RotL64(aPrevious, 21U)) + (RotL64(aIngress, 53U) + RotL64(aCarry, 41U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterF = (aWandererB + RotL64(aPrevious, 39U)) + 5131645209694953015U;
            aOrbiterK = (aWandererC + RotL64(aIngress, 41U)) + 12070391048835379854U;
            aOrbiterE = ((aWandererJ + RotL64(aCross, 26U)) + RotL64(aCarry, 41U)) + 2604295836242338724U;
            aOrbiterB = (aWandererE + RotL64(aScatter, 29U)) + 14042039029284001596U;
            aOrbiterG = (aWandererA + RotL64(aCross, 5U)) + 8914654543854559327U;
            aOrbiterA = (((aWandererI + RotL64(aPrevious, 3U)) + RotL64(aCarry, 47U)) + 2185619407969359869U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = (aWandererH + RotL64(aIngress, 43U)) + 5187406295103352574U;
            aOrbiterC = ((aWandererD + RotL64(aScatter, 51U)) + 8022832481290871217U) + aNonceWordN;
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 37U)) + 8783061916740573472U) + aNonceWordM;
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 57U)) + 10711028365596196301U) + aPhaseFOrbiterAssignSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = (((aWandererK + RotL64(aScatter, 18U)) + RotL64(aCarry, 21U)) + 13387065038269133571U) + aNonceWordD;
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 11187001318931801582U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 14191473173276034019U;
            aOrbiterE = RotL64((aOrbiterE * 2491253922434756431U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 16207761776716426435U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 9677408414452078760U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5487303383095129949U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 17812460332794370649U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 7736423148554132028U;
            aOrbiterG = RotL64((aOrbiterG * 15588733747232852555U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 17293203944059014763U) + aNonceWordI;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 13487243633338010243U;
            aOrbiterI = RotL64((aOrbiterI * 9468688858740539095U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 15979293016815060755U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 17645215484691359547U;
            aOrbiterJ = RotL64((aOrbiterJ * 1449450767288733995U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 11635961468586927692U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 10530136578329059784U;
            aOrbiterF = RotL64((aOrbiterF * 8785021493374398437U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 4900370530116992731U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 15952900504821599445U;
            aOrbiterB = RotL64((aOrbiterB * 5413316082800365261U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 9938000151832814778U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 14170277411106520726U;
            aOrbiterA = RotL64((aOrbiterA * 5058343552974910737U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 14091010427448547620U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 13658560822164111421U;
            aOrbiterC = RotL64((aOrbiterC * 9523184040517290629U), 35U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterD) + 13954269172267844623U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1]) + aNonceWordB;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 3921811946419945868U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6839440867046147039U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 14296483810577739898U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 5131645209694953015U;
            aOrbiterD = RotL64((aOrbiterD * 10190969526209064367U), 51U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterG, 50U);
            aIngress = aIngress + (RotL64(aOrbiterH, 37U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 11U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 21U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 60U));
            aIngress = aIngress + RotL64(aOrbiterF, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterA, 23U)) + aOrbiterC);
            aWandererI = aWandererI + (((RotL64(aIngress, 41U) + aOrbiterG) + RotL64(aOrbiterC, 47U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterE, 51U)) + aOrbiterA) + aNonceWordC);
            aWandererC = aWandererC + (((RotL64(aScatter, 21U) + RotL64(aOrbiterH, 3U)) + aOrbiterK) + RotL64(aCarry, 57U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 12U) + aOrbiterF) + RotL64(aOrbiterJ, 26U)) + aNonceWordJ);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 3U) + aOrbiterH) + RotL64(aOrbiterD, 5U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 39U) + aOrbiterF) + RotL64(aOrbiterD, 37U));
            aWandererH = aWandererH + ((((RotL64(aIngress, 43U) + aOrbiterI) + RotL64(aOrbiterB, 57U)) + RotL64(aCarry, 35U)) + aPhaseFWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 29U) + aOrbiterB) + RotL64(aOrbiterH, 20U)) + aNonceWordF);
            aWandererK = aWandererK + ((RotL64(aIngress, 53U) + RotL64(aOrbiterC, 11U)) + aOrbiterB);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 14U) + RotL64(aOrbiterB, 43U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererK, 50U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererD);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + RotL64(aWandererE, 3U);
            aCarry = aCarry + RotL64(aIngress, 22U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordB);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 15474U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((aIndex + 15881U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 13217U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 16313U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCarry, 40U)) ^ (RotL64(aPrevious, 13U) ^ RotL64(aCross, 27U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterC = (aWandererA + RotL64(aCross, 27U)) + 5568146815535263910U;
            aOrbiterA = (aWandererD + RotL64(aScatter, 37U)) + 7736084960873834666U;
            aOrbiterI = (aWandererH + RotL64(aIngress, 29U)) + 1336413621817562093U;
            aOrbiterD = (aWandererF + RotL64(aPrevious, 18U)) + 5218462026934984692U;
            aOrbiterH = ((aWandererG + RotL64(aScatter, 41U)) + RotL64(aCarry, 43U)) + 7048890985969555935U;
            aOrbiterF = (((aWandererK + RotL64(aCross, 23U)) + RotL64(aCarry, 39U)) + 13415955213864702118U) + aNonceWordD;
            aOrbiterB = (aWandererE + RotL64(aIngress, 11U)) + 5657023257021528548U;
            aOrbiterE = (aWandererC + RotL64(aPrevious, 47U)) + 14338310943137497116U;
            aOrbiterK = ((aWandererI + RotL64(aScatter, 6U)) + 12305161641833950473U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 43U)) + 14514226578370459131U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 3U)) + RotL64(aCarry, 13U)) + 12692904083266024340U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 11012959130001327964U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 7106471380403489078U;
            aOrbiterI = RotL64((aOrbiterI * 515626559384817223U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 3718101961355280891U) + aNonceWordG;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 13364192077222322664U;
            aOrbiterF = RotL64((aOrbiterF * 1411328915372590283U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 6720867800318913440U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 14497243926965866546U;
            aOrbiterA = RotL64((aOrbiterA * 13595058589060114653U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 5789056168233262435U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 14438482587495779937U;
            aOrbiterH = RotL64((aOrbiterH * 10593535547917767263U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 313917798940179945U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 15241845511889502917U;
            aOrbiterE = RotL64((aOrbiterE * 16483477103771326107U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 3591957424821693032U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 1559050939014453558U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17933346117866604725U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 15340590914441451383U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 5538037287390050110U;
            aOrbiterC = RotL64((aOrbiterC * 4082576643144951473U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 4151270491894969214U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 263593701314144898U;
            aOrbiterD = RotL64((aOrbiterD * 10372046955804512457U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 9025145270653080646U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 6867950904094870056U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9975247022340627751U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 3183454301841252109U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 3054904157641290615U;
            aOrbiterK = RotL64((aOrbiterK * 4092317552439599475U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 1768555574434776135U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 5568146815535263910U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12466957001078663927U), 57U);
            //
            aIngress = RotL64(aOrbiterH, 39U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 22U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 53U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 27U));
            aIngress = aIngress + RotL64(aOrbiterK, 58U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aScatter, 56U) + RotL64(aOrbiterK, 47U)) + aOrbiterE) + RotL64(aCarry, 21U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterF, 12U)) + aOrbiterI) + aNonceWordP);
            aWandererG = aWandererG + (((RotL64(aCross, 5U) + aOrbiterE) + RotL64(aOrbiterI, 51U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 51U) + aOrbiterB) + RotL64(aOrbiterE, 29U));
            aWandererD = aWandererD + ((RotL64(aCross, 19U) + RotL64(aOrbiterF, 27U)) + aOrbiterD);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterC, 53U)) + aOrbiterD) + aNonceWordI);
            aWandererH = aWandererH + ((RotL64(aPrevious, 35U) + aOrbiterI) + RotL64(aOrbiterG, 41U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 37U) + aOrbiterJ) + RotL64(aOrbiterE, 19U));
            aWandererB = aWandererB + ((((RotL64(aIngress, 44U) + aOrbiterD) + RotL64(aOrbiterA, 3U)) + RotL64(aCarry, 43U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterA, 21U)) + aOrbiterH);
            aWandererA = aWandererA + ((RotL64(aScatter, 11U) + RotL64(aOrbiterA, 6U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 36U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 41U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererB, 3U);
            aCarry = aCarry + RotL64(aIngress, 54U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordN);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 18920U)) & S_BLOCK1], 18U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20042U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21101U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 20409U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aPrevious, 41U)) ^ (RotL64(aCross, 22U) + RotL64(aIngress, 53U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterF = (aWandererF + RotL64(aScatter, 51U)) + 12583180859826261500U;
            aOrbiterH = (((aWandererB + RotL64(aCross, 41U)) + RotL64(aCarry, 23U)) + 9067093488553721468U) + aNonceWordH;
            aOrbiterG = (aWandererH + RotL64(aIngress, 53U)) + 12173106198862881754U;
            aOrbiterJ = (aWandererE + RotL64(aPrevious, 13U)) + 11333491014394592654U;
            aOrbiterK = (aWandererG + RotL64(aScatter, 26U)) + 3511883526940919554U;
            aOrbiterA = ((aWandererD + RotL64(aCross, 39U)) + 7416810692106273044U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 57U)) + 8341174972619784110U;
            aOrbiterI = (aWandererC + RotL64(aIngress, 23U)) + 2220852854836962979U;
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 5U)) + RotL64(aCarry, 13U)) + 8090781422229383825U;
            aOrbiterB = (((aWandererA + RotL64(aIngress, 29U)) + RotL64(aCarry, 47U)) + 2338801236599102223U) + aNonceWordJ;
            aOrbiterD = ((aWandererI + RotL64(aScatter, 20U)) + 12484514711848308104U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 13684861340589131816U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 12796636819991873058U) ^ aNonceWordC;
            aOrbiterG = RotL64((aOrbiterG * 5533508014234835669U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 7634198650894837690U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 10240326122201201762U;
            aOrbiterK = RotL64((aOrbiterK * 8758703497719125901U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 4162814763739453934U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 2766504649149048469U;
            aOrbiterA = RotL64((aOrbiterA * 16731843453895178671U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 11051393030148769655U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 17687055068651386665U;
            aOrbiterE = RotL64((aOrbiterE * 1042927176246229537U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 3353615315436983420U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 5971640796220306310U;
            aOrbiterI = RotL64((aOrbiterI * 15804313508835034807U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 12299773092762384765U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 7435804907797063411U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9848139805288165965U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 8735783937125735699U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 11903126115475835615U;
            aOrbiterB = RotL64((aOrbiterB * 16942088822124940265U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 4427166023462475475U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 6011733469446008137U;
            aOrbiterD = RotL64((aOrbiterD * 17298067225913923517U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 18341473946127677319U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 5423774915753911947U;
            aOrbiterF = RotL64((aOrbiterF * 14985099502923458523U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 2384393657884193014U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 2650593524388493958U;
            aOrbiterH = RotL64((aOrbiterH * 892985816665547945U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 15991261431384033176U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 12583180859826261500U;
            aOrbiterJ = RotL64((aOrbiterJ * 14394838775646875599U), 23U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterE, 47U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 27U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 29U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + (RotL64(aOrbiterG, 50U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterH, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aPrevious, 13U) + aOrbiterE) + RotL64(aOrbiterF, 42U)) + RotL64(aCarry, 47U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 54U) + aOrbiterG) + RotL64(aOrbiterI, 11U));
            aWandererI = aWandererI + (((RotL64(aCross, 3U) + RotL64(aOrbiterJ, 29U)) + aOrbiterB) + RotL64(aCarry, 35U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 35U) + aOrbiterG) + RotL64(aOrbiterE, 13U)) + aNonceWordF);
            aWandererA = aWandererA + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterC, 60U)) + aOrbiterA) + aNonceWordB);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterK, 37U)) + aOrbiterH) + aPhaseFWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aCross, 11U) + aOrbiterK) + RotL64(aOrbiterI, 19U));
            aWandererF = aWandererF ^ ((((RotL64(aScatter, 27U) + RotL64(aOrbiterK, 23U)) + aOrbiterD) + aNonceWordD) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 57U) + aOrbiterA) + RotL64(aOrbiterF, 27U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterE, 57U)) + aOrbiterB);
            aWandererC = aWandererC + ((RotL64(aPrevious, 44U) + aOrbiterK) + RotL64(aOrbiterA, 21U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererI, 18U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererD);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 51U));
            aCarry = aCarry + RotL64(aWandererJ, 41U);
            aCarry = aCarry + RotL64(aIngress, 58U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordJ);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 23679U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneA[((aIndex + 23374U)) & S_BLOCK1], 26U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 23658U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneA[((aIndex + 26106U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 60U) ^ RotL64(aPrevious, 19U)) + (RotL64(aCross, 35U) ^ RotL64(aIngress, 47U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterH = ((aWandererI + RotL64(aIngress, 39U)) + 6024062041314952357U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = (aWandererH + RotL64(aScatter, 50U)) + 18340757093658015585U;
            aOrbiterE = ((aWandererA + RotL64(aCross, 19U)) + RotL64(aCarry, 47U)) + 11911120493880346751U;
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 27U)) + RotL64(aCarry, 19U)) + 17428074353884654439U;
            aOrbiterK = ((aWandererF + RotL64(aScatter, 21U)) + 12790849760814795936U) + aNonceWordM;
            aOrbiterD = (aWandererD + RotL64(aPrevious, 37U)) + 12633397052172117800U;
            aOrbiterA = (aWandererE + RotL64(aIngress, 47U)) + 11946150433665237945U;
            aOrbiterJ = (aWandererK + RotL64(aCross, 13U)) + 16842157900909419285U;
            aOrbiterC = (aWandererG + RotL64(aPrevious, 60U)) + 14186235783224155962U;
            aOrbiterB = ((aWandererJ + RotL64(aCross, 43U)) + 13284904542579767591U) + aPhaseFOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = ((aWandererC + RotL64(aIngress, 5U)) + RotL64(aCarry, 29U)) + 11609181965078844357U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 9628562297095374984U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 7850281529011259759U;
            aOrbiterE = RotL64((aOrbiterE * 17611485102925470357U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 257458718073794527U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 10693404545773519306U) ^ aNonceWordP;
            aOrbiterD = RotL64((aOrbiterD * 14821443722828498323U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 3430519236533871460U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 6183054506953198055U;
            aOrbiterJ = RotL64((aOrbiterJ * 6121082743789970911U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 2905610989884221654U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 4472163910775333862U;
            aOrbiterB = RotL64((aOrbiterB * 7770678426310856745U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 16870142883133769663U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 1403692060594816451U;
            aOrbiterH = RotL64((aOrbiterH * 9740854430251597879U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 16904169913507057108U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 4773518591580333357U;
            aOrbiterI = RotL64((aOrbiterI * 5306070307776061267U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 6528141733853494275U) + aNonceWordK;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 11254806909313951442U;
            aOrbiterA = RotL64((aOrbiterA * 6316669786405548827U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 6857506858448143407U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 2855763534355983644U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16881334940165182415U), 23U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterA) + 12328391751024624740U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordA;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 16475072086109949522U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15218626930666825883U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 15505670341076785424U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 6972128419331939330U;
            aOrbiterF = RotL64((aOrbiterF * 12206069109180246067U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 7151546362283646210U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 6024062041314952357U;
            aOrbiterK = RotL64((aOrbiterK * 10243806128059850493U), 5U);
            //
            aIngress = RotL64(aOrbiterH, 58U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 53U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 43U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 27U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 56U));
            aIngress = aIngress + RotL64(aOrbiterF, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aIngress, 21U) + RotL64(aOrbiterK, 43U)) + aOrbiterH) + RotL64(aCarry, 53U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterF, 11U)) + aOrbiterG) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 48U) + RotL64(aOrbiterE, 21U)) + aOrbiterD) + RotL64(aCarry, 43U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterB, 56U)) + aOrbiterF);
            aWandererA = aWandererA + (((RotL64(aCross, 43U) + aOrbiterH) + RotL64(aOrbiterE, 53U)) + aNonceWordO);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterA, 47U)) + aOrbiterB);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterC, 39U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 57U) + aOrbiterH) + RotL64(aOrbiterB, 60U));
            aWandererG = aWandererG + ((RotL64(aCross, 29U) + aOrbiterF) + RotL64(aOrbiterC, 27U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 54U) + aOrbiterH) + RotL64(aOrbiterI, 41U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterI, 51U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 12U));
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererE);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererK);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + RotL64(aWandererF, 48U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordH);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 28443U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneB[((aIndex + 28368U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31835U)) & S_BLOCK1], 30U) ^ RotL64(aWorkLaneB[((aIndex + 30470U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 11U) + RotL64(aCarry, 39U)) ^ (RotL64(aPrevious, 27U) ^ RotL64(aCross, 54U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterA = (((aWandererG + RotL64(aPrevious, 27U)) + RotL64(aCarry, 37U)) + 15910560457440369082U) + aNonceWordN;
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 24U)) + RotL64(aCarry, 11U)) + 17953072986407436888U;
            aOrbiterH = (aWandererK + RotL64(aCross, 41U)) + 15446940721193538669U;
            aOrbiterD = (((aWandererH + RotL64(aScatter, 37U)) + RotL64(aCarry, 3U)) + 3020785262774422009U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = ((aWandererE + RotL64(aIngress, 3U)) + 7001288645424994404U) + aPhaseFOrbiterAssignSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = (aWandererA + RotL64(aScatter, 34U)) + 13385250665458462689U;
            aOrbiterF = (aWandererF + RotL64(aCross, 39U)) + 4841895644623005949U;
            aOrbiterC = (aWandererJ + RotL64(aPrevious, 19U)) + 13053476783239482065U;
            aOrbiterG = (aWandererC + RotL64(aCross, 43U)) + 641996979335975244U;
            aOrbiterK = (aWandererI + RotL64(aPrevious, 5U)) + 16211238020928688299U;
            aOrbiterE = (aWandererD + RotL64(aScatter, 53U)) + 12715448751323279480U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 17784406727699995290U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 16626339815786580778U;
            aOrbiterH = RotL64((aOrbiterH * 13940754474750138041U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 9035070625716345139U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 6085848172494001945U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10405728912339646693U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 1177103851507561053U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 2281901691017816407U;
            aOrbiterI = RotL64((aOrbiterI * 3142197009403602497U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 9040984343694325070U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 13334258224023902365U;
            aOrbiterF = RotL64((aOrbiterF * 4782523727707164869U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 1079824790138592518U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 14024082692012948652U;
            aOrbiterC = RotL64((aOrbiterC * 3219489374333737903U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 2966776524421278970U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 5510281854029308547U;
            aOrbiterG = RotL64((aOrbiterG * 9275402927591867297U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 7126632329316720048U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 1476827035602733472U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2217671289726794033U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 6470212302133184965U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 4172257438373147415U;
            aOrbiterE = RotL64((aOrbiterE * 4449314239630366533U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 11445212164224402184U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 1779825157413363285U) ^ aNonceWordB;
            aOrbiterA = RotL64((aOrbiterA * 15393425495668107155U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 7561888690947559866U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 14440989817038856852U) ^ aNonceWordC;
            aOrbiterJ = RotL64((aOrbiterJ * 5799807036762859679U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 10618807050937260814U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 15910560457440369082U;
            aOrbiterD = RotL64((aOrbiterD * 10902491688248464465U), 39U);
            //
            aIngress = RotL64(aOrbiterJ, 57U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 52U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 11U));
            aIngress = aIngress + (RotL64(aOrbiterA, 21U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 23U));
            aIngress = aIngress + RotL64(aOrbiterB, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterD, 40U)) + aOrbiterK) + aNonceWordK);
            aWandererJ = aWandererJ + ((RotL64(aCross, 29U) + aOrbiterE) + RotL64(aOrbiterD, 27U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 4U) + RotL64(aOrbiterF, 19U)) + aOrbiterH);
            aWandererE = aWandererE + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterD, 37U)) + aOrbiterC) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterA, 53U)) + aOrbiterE) + aNonceWordF);
            aWandererD = aWandererD + (((RotL64(aPrevious, 35U) + aOrbiterG) + RotL64(aOrbiterJ, 44U)) + RotL64(aCarry, 27U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 47U) + aOrbiterB) + RotL64(aOrbiterH, 47U));
            aWandererH = aWandererH + (((RotL64(aIngress, 60U) + aOrbiterG) + RotL64(aOrbiterD, 57U)) + aNonceWordJ);
            aWandererI = aWandererI ^ (((RotL64(aCross, 39U) + aOrbiterA) + RotL64(aOrbiterH, 51U)) + aPhaseFWandererUpdateSaltF[((aIndex + 24U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 57U) + aOrbiterK) + RotL64(aOrbiterI, 35U)) + RotL64(aCarry, 39U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 19U) + aOrbiterF) + RotL64(aOrbiterA, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 37U) ^ aWandererK);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 54U));
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererI);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + RotL64(aWandererH, 57U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ aNonceWordP;
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

void TwistExpander_BaseBall_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x8349CC4076D4291FULL + 0xDAE6B616F385C694ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xBFDEBD5A56F1275DULL + 0xCC86990C0BD5EB10ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x814181796B4FA775ULL + 0xD41097DD0032A15DULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xA76D7953CC998A7FULL + 0xFDF07CD69148707BULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xD9FB8F39A7DB0EB5ULL + 0x8F8B4A138FD9918CULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xF08BC589895E1E33ULL + 0xC25CFD83743D1E3DULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x818B0EA6BA34B5F7ULL + 0xE631C5B7F2B9C928ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xD349AE43BAECE7ABULL + 0xCB6006D870C0EB3EULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xD8F3D65174A47BBFULL + 0xC6FC07C4B1F4D30DULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xD91DF566ACA2D80BULL + 0xDDE7D9EEB4767996ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xFCE2D51829EB6A77ULL + 0xBC66E684272F16D8ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x806EA7E00AF3EE09ULL + 0xC0AAEAE644EBFE77ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xA6DB8DD152B0FADFULL + 0xA4320F2576B4E5EBULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x9EB81285201601ADULL + 0xCB084EF261117414ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x92ADD18839832F17ULL + 0xC26D0D53B0D36F8BULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xF10CD42ABF8934EBULL + 0xCE806FFD9354AB97ULL);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 1589U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneC[((aIndex + 3496U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 4250U)) & S_BLOCK1], 18U) ^ RotL64(aWorkLaneA[((aIndex + 4897U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 29U) ^ RotL64(aPrevious, 4U)) + (RotL64(aIngress, 53U) + RotL64(aCross, 41U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 50U)) + 10336802574069791273U) + aPhaseFOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = (((aWandererD + RotL64(aPrevious, 53U)) + RotL64(aCarry, 47U)) + 169025388197058936U) + aNonceWordC;
            aOrbiterH = (aWandererF + RotL64(aScatter, 3U)) + 6541354188379168846U;
            aOrbiterA = (aWandererA + RotL64(aCross, 37U)) + 16223920526599306104U;
            aOrbiterG = ((aWandererG + RotL64(aScatter, 21U)) + RotL64(aCarry, 57U)) + 12756613707692514808U;
            aOrbiterC = ((((aWandererE + RotL64(aCross, 47U)) + RotL64(aCarry, 43U)) + 5082475548176484035U) + aPhaseFOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1]) + aNonceWordL;
            aOrbiterD = (aWandererH + RotL64(aIngress, 11U)) + 4907435526952698526U;
            aOrbiterE = (aWandererK + RotL64(aPrevious, 56U)) + 14236627073831834337U;
            aOrbiterF = ((aWandererC + RotL64(aCross, 39U)) + 11502511046130497584U) + aNonceWordG;
            aOrbiterK = (aWandererB + RotL64(aPrevious, 41U)) + 3679044835550219497U;
            aOrbiterJ = (aWandererI + RotL64(aIngress, 23U)) + 11254838916686736746U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 10582608424233200966U) + aNonceWordE;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 10449735026385340313U;
            aOrbiterH = RotL64((aOrbiterH * 7363770199734997411U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 4628253464169957835U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 17664454668473204465U;
            aOrbiterC = RotL64((aOrbiterC * 4234720298731378527U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 3798386391743884889U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 1379331161819246587U;
            aOrbiterI = RotL64((aOrbiterI * 13086160171095077295U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 9816600392407327227U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 16781971616348376878U;
            aOrbiterA = RotL64((aOrbiterA * 12503867584828289879U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 4807797577690520554U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 2492057261148595922U;
            aOrbiterD = RotL64((aOrbiterD * 9453302540675483005U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 7909676419643119585U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 256053568910383007U;
            aOrbiterF = RotL64((aOrbiterF * 11965085163352053161U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 16179914439220412472U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 3968867762761955845U) ^ aNonceWordK;
            aOrbiterJ = RotL64((aOrbiterJ * 7473632378251893139U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 7474832923901283742U) + aNonceWordH;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 4736994731050735779U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9839654409121414047U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 596484364660389193U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 13822222274464306169U;
            aOrbiterG = RotL64((aOrbiterG * 1723502278319885511U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 16307920280681985443U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 3505106171801702915U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8479675421552861243U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 4987142580981135150U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 10336802574069791273U;
            aOrbiterK = RotL64((aOrbiterK * 2670706512498539705U), 5U);
            //
            aIngress = RotL64(aOrbiterD, 37U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 26U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterF, 51U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 29U));
            aIngress = aIngress + RotL64(aOrbiterE, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 56U) + RotL64(aOrbiterJ, 13U)) + aOrbiterH);
            aWandererF = aWandererF + ((((RotL64(aCross, 27U) + aOrbiterJ) + RotL64(aOrbiterI, 34U)) + RotL64(aCarry, 37U)) + aNonceWordI);
            aWandererD = aWandererD ^ ((((RotL64(aIngress, 37U) + RotL64(aOrbiterC, 5U)) + aOrbiterH) + aNonceWordP) + aPhaseFWandererUpdateSaltA[((aIndex + 16U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 35U) + RotL64(aOrbiterB, 11U)) + aOrbiterF) + RotL64(aCarry, 5U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterD, 47U)) + aOrbiterI) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterA, 39U)) + aOrbiterE);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 29U) + aOrbiterG) + RotL64(aOrbiterJ, 19U));
            aWandererC = aWandererC + ((RotL64(aIngress, 21U) + aOrbiterE) + RotL64(aOrbiterB, 41U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterI, 58U)) + aOrbiterK);
            aWandererB = aWandererB + ((RotL64(aCross, 39U) + aOrbiterA) + RotL64(aOrbiterF, 23U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 44U) + RotL64(aOrbiterD, 37U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererA);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 54U));
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererH, 51U);
            aCarry = aCarry + RotL64(aIngress, 42U);
            aCarry = aCarry ^ aNonceWordO;
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 6940U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneD[((aIndex + 5902U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 9958U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneB[((aIndex + 6529U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCarry, 10U)) + (RotL64(aPrevious, 23U) ^ RotL64(aCross, 41U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = (aWandererC + RotL64(aScatter, 11U)) + 12980104182836602177U;
            aOrbiterK = (aWandererH + RotL64(aPrevious, 19U)) + 3172622203188863995U;
            aOrbiterA = (aWandererK + RotL64(aCross, 27U)) + 1170974132219980203U;
            aOrbiterC = (aWandererG + RotL64(aIngress, 37U)) + 6035201940965047490U;
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 5U)) + 18033907118424996722U) + aNonceWordP;
            aOrbiterD = (aWandererD + RotL64(aScatter, 54U)) + 14604813424800580304U;
            aOrbiterI = ((aWandererI + RotL64(aCross, 23U)) + RotL64(aCarry, 3U)) + 13720232492851066035U;
            aOrbiterF = (((aWandererE + RotL64(aIngress, 39U)) + RotL64(aCarry, 39U)) + 3902659710585257448U) + aPhaseFOrbiterAssignSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterH = ((aWandererA + RotL64(aScatter, 3U)) + 8331560652661619868U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 30U)) + RotL64(aCarry, 51U)) + 4485014147538689794U;
            aOrbiterJ = (aWandererB + RotL64(aCross, 35U)) + 168202636924512424U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 16227825670092707848U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 4792781933944671365U) ^ aNonceWordM;
            aOrbiterA = RotL64((aOrbiterA * 15859849676231455283U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 12636865372722601282U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 18198291399585556632U;
            aOrbiterK = RotL64((aOrbiterK * 18155803890313399795U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 3650053185419807206U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 5897288963905408776U;
            aOrbiterG = RotL64((aOrbiterG * 3706949366974086151U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 9922308113622901726U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 13352279749091561510U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4025213180483632557U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 14969461950939646117U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 10231661776135056651U;
            aOrbiterH = RotL64((aOrbiterH * 11284575051455238501U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 10621934544068320859U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 6029116920305246887U;
            aOrbiterE = RotL64((aOrbiterE * 6087523725059376905U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 12887482425168671195U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 8351351557123783853U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3839381627914762245U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 5405938210926464973U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 385145802287899406U;
            aOrbiterD = RotL64((aOrbiterD * 8330751480464271445U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 7907749190875916461U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 5138733192253468642U;
            aOrbiterF = RotL64((aOrbiterF * 17028325976353263843U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 14382272868178763187U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 14354777100157531233U;
            aOrbiterB = RotL64((aOrbiterB * 7095764230272037767U), 13U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterA) + 4390647647193363824U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1]) + aNonceWordI;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 12980104182836602177U) ^ aNonceWordE;
            aOrbiterJ = RotL64((aOrbiterJ * 11124472075872147333U), 57U);
            //
            aIngress = RotL64(aOrbiterC, 13U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 34U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 27U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 21U));
            aIngress = aIngress + RotL64(aOrbiterD, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterA, 34U)) + aOrbiterE);
            aWandererJ = aWandererJ + ((RotL64(aCross, 48U) + RotL64(aOrbiterJ, 27U)) + aOrbiterD);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterH, 23U)) + aOrbiterD) + aNonceWordN);
            aWandererD = aWandererD + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterD, 5U)) + aOrbiterF) + RotL64(aCarry, 29U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 53U) + aOrbiterK) + RotL64(aOrbiterC, 11U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 13U) + aOrbiterJ) + RotL64(aOrbiterA, 43U)) + aNonceWordL);
            aWandererC = aWandererC ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterB, 50U)) + aOrbiterI);
            aWandererF = aWandererF + ((((RotL64(aIngress, 24U) + aOrbiterG) + RotL64(aOrbiterB, 37U)) + RotL64(aCarry, 19U)) + aPhaseFWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterD, 41U)) + aOrbiterI);
            aWandererI = aWandererI + (((RotL64(aPrevious, 43U) + aOrbiterK) + RotL64(aOrbiterA, 47U)) + aPhaseFWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterC, 57U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererD, 14U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererI, 53U) ^ aWandererF);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 41U));
            aCarry = aCarry + (RotL64(aWandererH, 27U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererA, 37U);
            aCarry = aCarry + RotL64(aIngress, 20U);
            aCarry = aCarry ^ aNonceWordL;
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 12195U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 13527U)) & S_BLOCK1], 50U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 14420U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneC[((aIndex + 12923U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 11U) ^ RotL64(aCross, 23U)) ^ (RotL64(aCarry, 38U) + RotL64(aPrevious, 53U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 51U)) + 1898718075389870739U) + aPhaseFOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = (aWandererE + RotL64(aPrevious, 27U)) + 5631794889237247403U;
            aOrbiterG = (aWandererH + RotL64(aCross, 24U)) + 18219714659484524607U;
            aOrbiterF = ((aWandererF + RotL64(aScatter, 57U)) + 15419581386225732921U) + aNonceWordK;
            aOrbiterC = (aWandererK + RotL64(aCross, 35U)) + 9125575431710198210U;
            aOrbiterK = (aWandererI + RotL64(aIngress, 13U)) + 12205871520544965505U;
            aOrbiterD = (aWandererD + RotL64(aPrevious, 43U)) + 7617534300497343422U;
            aOrbiterH = ((aWandererG + RotL64(aScatter, 10U)) + RotL64(aCarry, 39U)) + 18017579105368135814U;
            aOrbiterE = (((aWandererB + RotL64(aPrevious, 29U)) + RotL64(aCarry, 3U)) + 10693882161946020042U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = (aWandererJ + RotL64(aScatter, 19U)) + 11669615701700895306U;
            aOrbiterI = ((aWandererC + RotL64(aCross, 41U)) + RotL64(aCarry, 21U)) + 11045110212889232165U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 18019107802806469913U) + aNonceWordN;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 12315940560472528716U;
            aOrbiterG = RotL64((aOrbiterG * 4505122470351404065U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 4899009736070044310U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 17412253404253730364U;
            aOrbiterK = RotL64((aOrbiterK * 10791901166391946485U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 4826286251927854181U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 4523455921321845084U;
            aOrbiterA = RotL64((aOrbiterA * 14534103906736598099U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 4132514462154182215U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 7164745605985109269U;
            aOrbiterC = RotL64((aOrbiterC * 14107325508977225261U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 6297434295807635654U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 8813887638672996646U;
            aOrbiterH = RotL64((aOrbiterH * 17495632530773158201U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 11086381278955626084U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 5660733992573928887U;
            aOrbiterB = RotL64((aOrbiterB * 11248164458720777889U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 14851044686208609882U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 12707776386060264479U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4470919091467313071U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 11508023384209716657U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 11752973809740920034U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10212754472298834769U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 16746821150860017820U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 9659421716296641396U;
            aOrbiterD = RotL64((aOrbiterD * 7530071874978553673U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 3192309064305104593U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 11409078048681398061U;
            aOrbiterE = RotL64((aOrbiterE * 14991409124701807765U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 315359495275427324U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 1898718075389870739U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13126661894614781343U), 23U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterG, 51U);
            aIngress = aIngress + (RotL64(aOrbiterD, 10U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 5U));
            aIngress = aIngress + (RotL64(aOrbiterB, 35U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 41U));
            aIngress = aIngress + RotL64(aOrbiterH, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aScatter, 3U) + aOrbiterD) + RotL64(aOrbiterI, 24U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 47U) + aOrbiterI) + RotL64(aOrbiterE, 35U));
            aWandererE = aWandererE + ((RotL64(aCross, 27U) + RotL64(aOrbiterB, 51U)) + aOrbiterD);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 12U) + RotL64(aOrbiterH, 39U)) + aOrbiterC);
            aWandererA = aWandererA + (((RotL64(aScatter, 29U) + RotL64(aOrbiterF, 27U)) + aOrbiterA) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((((RotL64(aCross, 19U) + aOrbiterB) + RotL64(aOrbiterJ, 5U)) + aNonceWordD) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterA, 3U)) + aOrbiterD) + RotL64(aCarry, 53U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterC, 19U)) + aOrbiterG);
            aWandererB = aWandererB + (((RotL64(aCross, 39U) + aOrbiterA) + RotL64(aOrbiterK, 47U)) + RotL64(aCarry, 23U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterB, 14U)) + aOrbiterG);
            aWandererF = aWandererF + ((RotL64(aScatter, 60U) + aOrbiterI) + RotL64(aOrbiterA, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 41U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererD, 44U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 5U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererK, 37U);
            aCarry = aCarry + RotL64(aIngress, 56U);
            aCarry = aCarry ^ aNonceWordI;
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 16866U)) & S_BLOCK1], 28U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 18278U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 17960U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneD[((aIndex + 21454U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 54U) + RotL64(aIngress, 41U)) ^ (RotL64(aPrevious, 27U) ^ RotL64(aCarry, 5U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = (((aWandererB + RotL64(aPrevious, 60U)) + 18255347001097480328U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordA;
            aOrbiterI = (aWandererK + RotL64(aIngress, 43U)) + 13679246790311505735U;
            aOrbiterB = (aWandererG + RotL64(aCross, 23U)) + 10565839529765027116U;
            aOrbiterH = ((aWandererH + RotL64(aScatter, 41U)) + 14327172566224769901U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = (aWandererE + RotL64(aCross, 37U)) + 16239024612038195174U;
            aOrbiterC = (aWandererA + RotL64(aPrevious, 27U)) + 13800012174212131890U;
            aOrbiterG = (((aWandererI + RotL64(aScatter, 47U)) + RotL64(aCarry, 43U)) + 13900288860157577583U) + aNonceWordG;
            aOrbiterK = ((aWandererF + RotL64(aIngress, 10U)) + RotL64(aCarry, 53U)) + 4144386119777112740U;
            aOrbiterD = ((aWandererJ + RotL64(aCross, 39U)) + RotL64(aCarry, 11U)) + 3154558262670631372U;
            aOrbiterJ = (aWandererD + RotL64(aIngress, 53U)) + 7456728543137614001U;
            aOrbiterA = (aWandererC + RotL64(aPrevious, 5U)) + 11709519851158935384U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 15607438907832240304U) + aNonceWordN;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 9276575329661725624U;
            aOrbiterB = RotL64((aOrbiterB * 8879744070762412745U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 6459435969129449226U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 6442382118416542275U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2921027306686588233U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 12117432107282150865U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 6831279293184793243U;
            aOrbiterC = RotL64((aOrbiterC * 2435360641135249073U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 9520022957804572889U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 8322178689474588679U) ^ aNonceWordP;
            aOrbiterG = RotL64((aOrbiterG * 1627707191467537115U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 4162401591586869316U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 8994015844714895961U;
            aOrbiterK = RotL64((aOrbiterK * 15421910378057951895U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 10038095909727959633U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 17756404450592957616U;
            aOrbiterD = RotL64((aOrbiterD * 14255952184627347295U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 3379089265413427719U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 11341713098678108441U;
            aOrbiterJ = RotL64((aOrbiterJ * 2500587373161411961U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 4030296130743454165U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 6332387792111212064U;
            aOrbiterA = RotL64((aOrbiterA * 16490982218150897861U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 14893209417387662133U) + aNonceWordC;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 9265457389326311687U;
            aOrbiterE = RotL64((aOrbiterE * 9778404505547862689U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 13496086915199406901U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 14576555328710787951U;
            aOrbiterI = RotL64((aOrbiterI * 13155395071667672943U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 11482324648071976743U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 18255347001097480328U;
            aOrbiterH = RotL64((aOrbiterH * 10918514878283385643U), 57U);
            //
            aIngress = RotL64(aOrbiterI, 52U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterK, 37U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 5U));
            aIngress = aIngress + RotL64(aOrbiterB, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterG, 23U)) + aOrbiterH);
            aWandererC = aWandererC + (((RotL64(aIngress, 21U) + aOrbiterK) + RotL64(aOrbiterE, 12U)) + RotL64(aCarry, 21U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 35U) + aOrbiterH) + RotL64(aOrbiterC, 53U));
            aWandererI = aWandererI + (((RotL64(aCross, 18U) + aOrbiterF) + RotL64(aOrbiterE, 3U)) + aPhaseFWandererUpdateSaltB[((aIndex + 22U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterJ, 27U)) + aOrbiterA) + aNonceWordF);
            aWandererB = aWandererB + (((RotL64(aPrevious, 39U) + aOrbiterH) + RotL64(aOrbiterI, 37U)) + RotL64(aCarry, 37U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 47U) + aOrbiterJ) + RotL64(aOrbiterI, 5U));
            aWandererE = aWandererE + ((RotL64(aIngress, 50U) + aOrbiterD) + RotL64(aOrbiterI, 41U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterA, 19U)) + aOrbiterE) + aPhaseFWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 23U) + RotL64(aOrbiterG, 56U)) + aOrbiterB);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterF, 51U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 38U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + RotL64(aWandererI, 41U);
            aCarry = aCarry + RotL64(aIngress, 10U);
            aCarry = aCarry ^ aNonceWordB;
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22009U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23174U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 25157U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 24374U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCross, 42U)) + (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 23U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterI = ((aWandererC + RotL64(aCross, 60U)) + RotL64(aCarry, 51U)) + 8767379393098711499U;
            aOrbiterK = (((aWandererH + RotL64(aIngress, 43U)) + RotL64(aCarry, 23U)) + 7168159491580816433U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterE = ((aWandererB + RotL64(aScatter, 29U)) + RotL64(aCarry, 3U)) + 9879279829061883406U;
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 21U)) + 10537167136053399303U) + aNonceWordN;
            aOrbiterF = (aWandererD + RotL64(aScatter, 50U)) + 2839070018069188936U;
            aOrbiterB = (aWandererG + RotL64(aIngress, 27U)) + 13844278063968429732U;
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 53U)) + 11278946626186474646U) + aPhaseFOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = (aWandererJ + RotL64(aCross, 5U)) + 11798425216660557799U;
            aOrbiterA = (aWandererI + RotL64(aPrevious, 13U)) + 7618446090703335192U;
            aOrbiterH = (aWandererF + RotL64(aIngress, 23U)) + 695423597006983660U;
            aOrbiterD = (aWandererK + RotL64(aScatter, 57U)) + 14344728202803488813U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 11656100506575697086U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 10384358779985773937U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 247494692039140973U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 17585001605131977341U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 9964478171465522911U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13484044854790175315U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 2710943171829692624U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 17809072853457153057U;
            aOrbiterC = RotL64((aOrbiterC * 16341884203303271365U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 12814092033910687774U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 1743186323268668740U;
            aOrbiterH = RotL64((aOrbiterH * 11150822630624332557U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 10750472346626754704U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 15925901217078035356U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9276504171291801637U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 2569102106359362359U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 8868261301410769739U;
            aOrbiterJ = RotL64((aOrbiterJ * 3662495603133918101U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 2143691008373582476U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterF) ^ 10606616796243205921U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterG = RotL64((aOrbiterG * 15794414817813485643U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 16258070651850746855U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 11720192793689633315U;
            aOrbiterA = RotL64((aOrbiterA * 14475623219460678021U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 8230871037292355675U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 16898650748046368353U;
            aOrbiterD = RotL64((aOrbiterD * 7368697435476300255U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 9071122174426904737U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 4506737259011736474U;
            aOrbiterK = RotL64((aOrbiterK * 11903039808814842447U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 4545409671845718259U) + aNonceWordB;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 8767379393098711499U;
            aOrbiterF = RotL64((aOrbiterF * 1210632171306946669U), 13U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterG, 23U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 27U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 19U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 39U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 11U));
            aIngress = aIngress + RotL64(aOrbiterK, 30U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterD, 27U)) + aOrbiterC);
            aWandererF = aWandererF + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterA, 37U)) + aOrbiterB) + RotL64(aCarry, 37U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 58U) + RotL64(aOrbiterJ, 43U)) + aOrbiterE);
            aWandererD = aWandererD + ((RotL64(aCross, 37U) + RotL64(aOrbiterF, 34U)) + aOrbiterE);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterA, 29U)) + aOrbiterG) + aNonceWordF);
            aWandererB = aWandererB + ((((RotL64(aIngress, 13U) + aOrbiterA) + RotL64(aOrbiterH, 19U)) + RotL64(aCarry, 11U)) + aPhaseFWandererUpdateSaltD[((aIndex + 20U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterJ, 3U)) + aOrbiterF) + aNonceWordD);
            aWandererG = aWandererG + ((((RotL64(aCross, 41U) + RotL64(aOrbiterD, 5U)) + aOrbiterI) + aNonceWordJ) + aPhaseFWandererUpdateSaltE[((aIndex + 10U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 23U) + aOrbiterK) + RotL64(aOrbiterF, 39U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 29U) + RotL64(aOrbiterF, 23U)) + aOrbiterG);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 48U) + RotL64(aOrbiterE, 52U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 30U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + RotL64(aWandererI, 37U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordH);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 28140U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31024U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31293U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32187U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 60U) + RotL64(aCross, 47U)) + (RotL64(aPrevious, 35U) ^ RotL64(aCarry, 11U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterJ = (aWandererA + RotL64(aScatter, 47U)) + 1393781663398437180U;
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 21U)) + RotL64(aCarry, 51U)) + 17414594746688585273U;
            aOrbiterI = ((aWandererI + RotL64(aCross, 36U)) + 2823888497053071250U) + aNonceWordE;
            aOrbiterA = (((aWandererK + RotL64(aIngress, 29U)) + RotL64(aCarry, 29U)) + 17032631958617884859U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = (aWandererF + RotL64(aScatter, 19U)) + 15222697630461125019U;
            aOrbiterD = ((aWandererE + RotL64(aIngress, 23U)) + 15737414920751551780U) + aNonceWordC;
            aOrbiterH = (aWandererC + RotL64(aCross, 53U)) + 1357196111055783001U;
            aOrbiterB = (aWandererB + RotL64(aPrevious, 41U)) + 5315122321649251691U;
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 5U)) + 7893744655508595974U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = (aWandererH + RotL64(aPrevious, 51U)) + 16721939414324611738U;
            aOrbiterG = ((aWandererD + RotL64(aCross, 14U)) + RotL64(aCarry, 39U)) + 3444375866323610848U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 1825716513674511632U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 15582066843912467318U;
            aOrbiterI = RotL64((aOrbiterI * 12765146555943757373U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 15673590949193923915U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 13887365046280406413U;
            aOrbiterC = RotL64((aOrbiterC * 3169061375011420121U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 12730414371734709356U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 4819112390640821927U;
            aOrbiterD = RotL64((aOrbiterD * 8782547948627685451U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 3089925954422937464U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 7180179304678622530U;
            aOrbiterH = RotL64((aOrbiterH * 16118051565147747413U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 17030269962085008657U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 6675917351883004046U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14134335325316949687U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 12572022803491077491U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 2801421744689267375U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 315045745990934023U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 4335148696780313055U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 12526298573395110141U) ^ aNonceWordN;
            aOrbiterK = RotL64((aOrbiterK * 11276803410698178607U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 6984239833558496091U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 12195433952105336808U;
            aOrbiterG = RotL64((aOrbiterG * 8642600547427664495U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 6392683095502982341U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 18047201953488013325U;
            aOrbiterJ = RotL64((aOrbiterJ * 16151795290455603489U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 15433458942878109208U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 1700365768743794306U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16151638348775286903U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 10951473638533187729U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 1393781663398437180U;
            aOrbiterA = RotL64((aOrbiterA * 2661447713922232789U), 29U);
            //
            aIngress = RotL64(aOrbiterG, 4U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterB, 47U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterK, 39U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterE, 21U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 60U));
            aIngress = aIngress + RotL64(aOrbiterD, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aScatter, 19U) + RotL64(aOrbiterC, 14U)) + aOrbiterJ) + RotL64(aCarry, 51U)) + aNonceWordD);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 54U) + RotL64(aOrbiterH, 3U)) + aOrbiterK);
            aWandererG = aWandererG + (((RotL64(aCross, 11U) + RotL64(aOrbiterF, 21U)) + aOrbiterC) + aNonceWordI);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 41U) + aOrbiterH) + RotL64(aOrbiterB, 29U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 37U) + aOrbiterI) + RotL64(aOrbiterB, 39U)) + aPhaseFWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 13U) + aOrbiterF) + RotL64(aOrbiterA, 35U));
            aWandererK = aWandererK + ((RotL64(aScatter, 5U) + RotL64(aOrbiterG, 11U)) + aOrbiterH);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterK, 19U)) + aOrbiterC);
            aWandererI = aWandererI + (((RotL64(aPrevious, 3U) + aOrbiterD) + RotL64(aOrbiterA, 23U)) + RotL64(aCarry, 35U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 30U) + RotL64(aOrbiterA, 44U)) + aOrbiterB);
            aWandererB = aWandererB + ((RotL64(aScatter, 47U) + RotL64(aOrbiterE, 47U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 50U));
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererD);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + RotL64(aWandererE, 19U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ aNonceWordP;
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

void TwistExpander_BaseBall_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 7683U)) & S_BLOCK1], 56U) ^ RotL64(aKeyRowReadA[((aIndex + 8062U)) & W_KEY1], 47U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 5886U)) & W_KEY1], 39U) ^ RotL64(mSource[((aIndex + 5396U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aPrevious, 35U)) + (RotL64(aCarry, 6U) ^ RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = (aWandererG + RotL64(aIngress, 12U)) + 9080426856729228705U;
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 37U)) + RotL64(aCarry, 29U)) + 7851218321653539276U;
            aOrbiterC = (aWandererB + RotL64(aScatter, 29U)) + 7023344692919298036U;
            aOrbiterG = ((aWandererA + RotL64(aCross, 47U)) + 9772846154227440734U) + aPhaseCOrbiterAssignSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = (aWandererJ + RotL64(aPrevious, 5U)) + 12008298632429608431U;
            aOrbiterJ = (((aWandererI + RotL64(aIngress, 21U)) + RotL64(aCarry, 53U)) + 12201090455849562875U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterH = (aWandererC + RotL64(aScatter, 53U)) + 9498721803411445471U;
            aOrbiterB = ((aWandererF + RotL64(aCross, 42U)) + RotL64(aCarry, 21U)) + 351203764023093632U;
            aOrbiterI = (aWandererK + RotL64(aScatter, 57U)) + 4966360430644539250U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 9194167899071345693U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 4922477697284269116U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8444814161720407881U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 15742625291642356429U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 7528703106518431730U;
            aOrbiterJ = RotL64((aOrbiterJ * 11530049278751507567U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 15279053574704935317U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 2425839793660355555U;
            aOrbiterB = RotL64((aOrbiterB * 11486964816849830667U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 13209849392400008898U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 9041500097716231309U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 340661035700748739U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 7885423750878814599U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 1992993999902904603U;
            aOrbiterF = RotL64((aOrbiterF * 1478629826632201617U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 6120758615019314102U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 8529621625846992066U;
            aOrbiterG = RotL64((aOrbiterG * 8485991471612862467U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 9125182130757385320U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 15691232622970220043U;
            aOrbiterH = RotL64((aOrbiterH * 16517916951054758147U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 11413090085435424697U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 11563151001080914939U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16828196274450408201U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 1778975369262558069U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 3232132443557192010U;
            aOrbiterD = RotL64((aOrbiterD * 17132823737792200981U), 47U);
            //
            aIngress = RotL64(aOrbiterJ, 39U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 21U));
            aIngress = aIngress + (RotL64(aOrbiterI, 51U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterG, 24U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterH, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 57U) + aOrbiterI) + RotL64(aOrbiterF, 42U));
            aWandererC = aWandererC + (((RotL64(aScatter, 34U) + aOrbiterJ) + RotL64(aOrbiterC, 11U)) + RotL64(aCarry, 53U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterJ, 23U)) + aOrbiterG) + aPhaseCWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aCross, 47U) + RotL64(aOrbiterK, 27U)) + aOrbiterH);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 41U) + aOrbiterC) + RotL64(aOrbiterF, 19U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 53U) + aOrbiterB) + RotL64(aOrbiterF, 3U)) + RotL64(aCarry, 35U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 30U) + aOrbiterJ) + RotL64(aOrbiterH, 35U)) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 13U) + aOrbiterB) + RotL64(aOrbiterD, 51U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterD, 60U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + (RotL64(aWandererK, 36U) ^ aWandererJ);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 21U));
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererI, 13U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 12203U)) & S_BLOCK1], 56U) ^ RotL64(mSource[((aIndex + 10222U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 11888U)) & W_KEY1], 57U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 11703U)) & W_KEY1], 38U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCarry, 39U)) + (RotL64(aCross, 10U) ^ RotL64(aPrevious, 51U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = (aWandererE + RotL64(aScatter, 29U)) + 7948891781097675369U;
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 57U)) + RotL64(aCarry, 11U)) + 13928362874228230226U;
            aOrbiterH = ((aWandererH + RotL64(aCross, 10U)) + 10776180542602258926U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterB = ((aWandererI + RotL64(aIngress, 23U)) + 5735115172149470447U) + aPhaseCOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = (aWandererG + RotL64(aScatter, 19U)) + 5353591822981766987U;
            aOrbiterF = (aWandererD + RotL64(aPrevious, 43U)) + 562301708107268570U;
            aOrbiterD = (aWandererC + RotL64(aIngress, 3U)) + 10467810247578364868U;
            aOrbiterK = ((aWandererK + RotL64(aCross, 37U)) + RotL64(aCarry, 19U)) + 14541630141152308564U;
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 14U)) + RotL64(aCarry, 37U)) + 2350076897065139429U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 17519109078651162228U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 6061035173339902910U;
            aOrbiterH = RotL64((aOrbiterH * 10021905773432907835U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 15654836633731000065U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 13723521735153718904U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14459516479283070563U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 2849680038315532197U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 17336102435576647923U;
            aOrbiterD = RotL64((aOrbiterD * 10984689101753586739U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 7671010488872356142U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 11485114338165600777U;
            aOrbiterK = RotL64((aOrbiterK * 4162584865462407791U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 8759060657343458985U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 11009137869375286581U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8741417343929809115U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 15792999392743144135U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 6180808423175992479U;
            aOrbiterI = RotL64((aOrbiterI * 13681230339693676907U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 361487389591183005U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 15292753806514404853U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17478232597253311153U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 14929153438443362045U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 7904556383593914086U;
            aOrbiterF = RotL64((aOrbiterF * 2484130486635511403U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 3793180909904286848U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 10391957637467171320U;
            aOrbiterE = RotL64((aOrbiterE * 505484041943467117U), 5U);
            //
            aIngress = RotL64(aOrbiterI, 29U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 53U));
            aIngress = aIngress + (RotL64(aOrbiterH, 60U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 39U));
            aIngress = aIngress + RotL64(aOrbiterE, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aScatter, 6U) + RotL64(aOrbiterK, 23U)) + aOrbiterI);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterB, 44U)) + aOrbiterH);
            aWandererE = aWandererE + ((RotL64(aCross, 19U) + aOrbiterG) + RotL64(aOrbiterF, 5U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 53U) + aOrbiterK) + RotL64(aOrbiterG, 27U));
            aWandererF = aWandererF + ((((RotL64(aScatter, 29U) + RotL64(aOrbiterA, 13U)) + aOrbiterG) + RotL64(aCarry, 41U)) + aPhaseCWandererUpdateSaltF[((aIndex + 20U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 13U) + aOrbiterD) + RotL64(aOrbiterE, 35U));
            aWandererK = aWandererK + ((RotL64(aCross, 43U) + RotL64(aOrbiterB, 53U)) + aOrbiterG);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 39U) + aOrbiterH) + RotL64(aOrbiterI, 48U)) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 58U) + aOrbiterE) + RotL64(aOrbiterB, 39U)) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererJ);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 54U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + RotL64(aWandererE, 19U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22501U)) & S_BLOCK1], 36U) ^ RotL64(aExpandLaneA[((aIndex + 23303U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 18827U)) & W_KEY1], 57U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 18165U)) & W_KEY1], 20U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 35U) + RotL64(aCarry, 48U)) ^ (RotL64(aPrevious, 5U) ^ RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = (aWandererA + RotL64(aScatter, 47U)) + 15045917390223766480U;
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 57U)) + 10763054007033668758U) + aPhaseCOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = ((aWandererK + RotL64(aCross, 34U)) + 13190170142593666607U) + aPhaseCOrbiterAssignSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 39U)) + 9657025731441167065U;
            aOrbiterH = ((aWandererB + RotL64(aScatter, 5U)) + RotL64(aCarry, 27U)) + 11433367178975954211U;
            aOrbiterG = ((aWandererF + RotL64(aIngress, 13U)) + RotL64(aCarry, 39U)) + 17904920143996810366U;
            aOrbiterF = (aWandererD + RotL64(aCross, 23U)) + 3244383020512113283U;
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 28U)) + RotL64(aCarry, 5U)) + 6538815775171139091U;
            aOrbiterB = (aWandererC + RotL64(aCross, 53U)) + 7195368312757976343U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 18134430713910279374U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 6571776588427107976U;
            aOrbiterK = RotL64((aOrbiterK * 11916502085252589161U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 11830778129647517758U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 9793702760907767365U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4096246227968677179U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 2287235876793192036U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 8951959188326141794U;
            aOrbiterJ = RotL64((aOrbiterJ * 9968356718110753845U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 7583061790273240157U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 3571364625022806085U;
            aOrbiterE = RotL64((aOrbiterE * 6238360922735480669U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 13869345563551689212U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 277480328952975002U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1057564597096163085U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 4983735092494677578U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 9490022869381030928U;
            aOrbiterG = RotL64((aOrbiterG * 12926352917961703123U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 7928039573014765566U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 6504190875809407084U;
            aOrbiterF = RotL64((aOrbiterF * 14648214826494826711U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 2787985600176307413U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 16308785053443116826U;
            aOrbiterI = RotL64((aOrbiterI * 17867565986311256691U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 12788128335006767824U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 1187040019537798339U;
            aOrbiterB = RotL64((aOrbiterB * 10834905007658184183U), 43U);
            //
            aIngress = RotL64(aOrbiterK, 3U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterI, 12U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 29U));
            aIngress = aIngress + RotL64(aOrbiterE, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aScatter, 19U) + aOrbiterJ) + RotL64(aOrbiterK, 52U)) + RotL64(aCarry, 53U)) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 43U) + aOrbiterB) + RotL64(aOrbiterJ, 43U)) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 12U) + RotL64(aOrbiterE, 19U)) + aOrbiterG);
            aWandererI = aWandererI ^ ((RotL64(aCross, 53U) + aOrbiterK) + RotL64(aOrbiterF, 5U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 27U) + aOrbiterD) + RotL64(aOrbiterE, 29U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 37U) + aOrbiterH) + RotL64(aOrbiterJ, 23U));
            aWandererK = aWandererK + (((RotL64(aCross, 57U) + RotL64(aOrbiterI, 35U)) + aOrbiterH) + RotL64(aCarry, 35U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 47U) + aOrbiterI) + RotL64(aOrbiterB, 57U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 4U) + RotL64(aOrbiterE, 10U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 41U));
            aCarry = aCarry + (RotL64(aWandererI, 6U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + RotL64(aWandererC, 23U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 28750U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneB[((aIndex + 27616U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27362U)) & S_BLOCK1], 30U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 28147U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aIngress, 37U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCross, 24U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 47U)) + 15549114274303128055U) + aPhaseCOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = ((aWandererI + RotL64(aCross, 21U)) + RotL64(aCarry, 37U)) + 16466750056388063241U;
            aOrbiterG = (aWandererD + RotL64(aScatter, 3U)) + 12209449840836787142U;
            aOrbiterH = ((aWandererC + RotL64(aIngress, 11U)) + RotL64(aCarry, 53U)) + 14551496099734294336U;
            aOrbiterB = (aWandererB + RotL64(aScatter, 60U)) + 6266576428679808622U;
            aOrbiterI = ((aWandererG + RotL64(aCross, 27U)) + 16892841575635668152U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = (aWandererF + RotL64(aPrevious, 35U)) + 7375966221423362125U;
            aOrbiterJ = (aWandererE + RotL64(aIngress, 43U)) + 11926105302821753530U;
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 54U)) + RotL64(aCarry, 23U)) + 16219253791550461124U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 7299056065319248160U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 15234001484933728439U;
            aOrbiterG = RotL64((aOrbiterG * 8182244796017018911U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 6615802589932632120U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 5481176858895819247U;
            aOrbiterB = RotL64((aOrbiterB * 3604590158551984877U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 17220507586542139380U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 14137921473739415340U;
            aOrbiterA = RotL64((aOrbiterA * 10634645686035907603U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 16981960446540932787U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 10897565927079518588U;
            aOrbiterD = RotL64((aOrbiterD * 418843936329303571U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 2746889569299593263U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 4894117146736361379U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2656750612042673191U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 18294823016957137777U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 86828501068883383U;
            aOrbiterI = RotL64((aOrbiterI * 11432686669235402365U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 6322053762209547826U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 6754524552483363820U;
            aOrbiterJ = RotL64((aOrbiterJ * 1746163087826694641U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 7306452650619361017U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 12717201204443785828U;
            aOrbiterE = RotL64((aOrbiterE * 6121251603905574991U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 10422327053543898585U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 14786413282036348183U;
            aOrbiterC = RotL64((aOrbiterC * 8713024293107068275U), 57U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterE, 60U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 47U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 23U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 37U));
            aIngress = aIngress + RotL64(aOrbiterC, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterB, 18U)) + aOrbiterJ);
            aWandererB = aWandererB ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterA, 57U)) + aOrbiterJ);
            aWandererH = aWandererH + ((RotL64(aIngress, 13U) + RotL64(aOrbiterG, 13U)) + aOrbiterB);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterI, 41U)) + aOrbiterD);
            aWandererF = aWandererF + ((((RotL64(aCross, 35U) + RotL64(aOrbiterC, 3U)) + aOrbiterH) + RotL64(aCarry, 29U)) + aPhaseCWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 43U) + aOrbiterC) + RotL64(aOrbiterA, 37U));
            aWandererD = aWandererD + ((RotL64(aScatter, 39U) + aOrbiterA) + RotL64(aOrbiterE, 47U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterI, 27U)) + aOrbiterG) + aPhaseCWandererUpdateSaltD[((aIndex + 19U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 48U) + aOrbiterD) + RotL64(aOrbiterJ, 22U)) + RotL64(aCarry, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererI);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 50U));
            aCarry = aCarry + RotL64(aWandererB, 53U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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

void TwistExpander_BaseBall_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0;
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 450U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneC[((aIndex + 3250U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 7265U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 4766U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCarry, 44U)) ^ (RotL64(aCross, 57U) + RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = (aWandererF + RotL64(aPrevious, 21U)) + 12692813903177772178U;
            aOrbiterB = ((aWandererD + RotL64(aCross, 5U)) + RotL64(aCarry, 11U)) + 7112496446691277899U;
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 54U)) + 2112247138290568813U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = (((aWandererE + RotL64(aScatter, 29U)) + RotL64(aCarry, 57U)) + 3699421080882855947U) + aPhaseDOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = ((aWandererC + RotL64(aIngress, 41U)) + RotL64(aCarry, 29U)) + 13761832028354380922U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 9243822514887600214U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 6863833516853046129U;
            aOrbiterC = RotL64((aOrbiterC * 775478131159266165U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 8863897995943098018U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 13346785686701467520U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 18074843497158380703U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 15309543066305531619U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 17515530938817919111U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16625193986319048245U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 760493237816424254U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 7282586354117620860U;
            aOrbiterB = RotL64((aOrbiterB * 2327153408185290635U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 4129706068526969105U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 7020175432730888755U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10095158356907592239U), 21U);
            //
            aIngress = RotL64(aOrbiterH, 5U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterF, 29U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterB, 52U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aScatter, 47U) + aOrbiterK) + RotL64(aOrbiterF, 13U)) + RotL64(aCarry, 13U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 58U) + aOrbiterH) + RotL64(aOrbiterC, 37U));
            aWandererF = aWandererF + (((RotL64(aCross, 13U) + aOrbiterB) + RotL64(aOrbiterK, 21U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterB, 3U)) + aOrbiterH);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 37U) + aOrbiterF) + RotL64(aOrbiterH, 48U)) + RotL64(aCarry, 43U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + (RotL64(aWandererF, 37U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererC, 11U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 13725U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneD[((aIndex + 9494U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 11236U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneB[((aIndex + 14345U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCarry, 43U)) ^ (RotL64(aCross, 27U) ^ RotL64(aPrevious, 12U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = (aWandererF + RotL64(aScatter, 37U)) + 14179205183062705133U;
            aOrbiterK = (((aWandererJ + RotL64(aIngress, 12U)) + RotL64(aCarry, 29U)) + 210032324058740920U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = (((aWandererD + RotL64(aCross, 21U)) + RotL64(aCarry, 41U)) + 7387115089142500152U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterC = (aWandererC + RotL64(aPrevious, 53U)) + 17583362781238061430U;
            aOrbiterA = ((aWandererI + RotL64(aScatter, 3U)) + RotL64(aCarry, 11U)) + 4991442849150005943U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 2891376254689854555U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 10523274382407446239U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17443994099359920915U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 3861893764676218667U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 3366674459852093746U;
            aOrbiterA = RotL64((aOrbiterA * 14005994095369483813U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 5898492634386601145U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 7047353571244768721U;
            aOrbiterF = RotL64((aOrbiterF * 2257518291062508467U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 14374108805453186316U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 8763667021501226510U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7694695426430267863U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 18261523829316379575U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 650477532238860965U;
            aOrbiterC = RotL64((aOrbiterC * 8291758490821819851U), 39U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterJ, 3U);
            aIngress = aIngress + (RotL64(aOrbiterA, 29U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterK, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aScatter, 11U) + aOrbiterF) + RotL64(aOrbiterK, 24U));
            aWandererF = aWandererF + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterA, 37U)) + aOrbiterJ) + RotL64(aCarry, 13U)) + aPhaseDWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 19U) + aOrbiterA) + RotL64(aOrbiterF, 5U));
            aWandererC = aWandererC + ((((RotL64(aCross, 57U) + aOrbiterF) + RotL64(aOrbiterC, 57U)) + RotL64(aCarry, 51U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 46U) + RotL64(aOrbiterK, 13U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 39U));
            aCarry = aCarry + (RotL64(aWandererI, 28U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererD, 47U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 23628U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((aIndex + 23151U)) & S_BLOCK1], 10U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18523U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 17088U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 39U)) + (RotL64(aCross, 18U) + RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = (aWandererI + RotL64(aScatter, 41U)) + 3236820517816085022U;
            aOrbiterK = (((aWandererH + RotL64(aIngress, 23U)) + RotL64(aCarry, 29U)) + 741288875914097926U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = (((aWandererC + RotL64(aCross, 13U)) + RotL64(aCarry, 5U)) + 8417246926007729580U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = ((aWandererG + RotL64(aPrevious, 58U)) + RotL64(aCarry, 57U)) + 9715717805774537170U;
            aOrbiterB = (aWandererJ + RotL64(aScatter, 5U)) + 14360243844821619482U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 10760908100206775334U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 3434641779946167811U;
            aOrbiterH = RotL64((aOrbiterH * 3305698324169010803U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 7885568822756234567U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 3041563437672051294U;
            aOrbiterK = RotL64((aOrbiterK * 11440300917533482297U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 15761355327564963516U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 1158633562785937421U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15511324886867188235U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 9338581575871970653U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 9172038894262857354U;
            aOrbiterC = RotL64((aOrbiterC * 3110871165285625807U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 14653924713599790081U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 3854497592598563309U;
            aOrbiterB = RotL64((aOrbiterB * 11737111068815795303U), 57U);
            //
            aIngress = RotL64(aOrbiterK, 47U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 11U));
            aIngress = aIngress + RotL64(aOrbiterC, 58U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterC, 21U)) + aOrbiterE);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 27U) + RotL64(aOrbiterC, 13U)) + aOrbiterH) + RotL64(aCarry, 19U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterE, 3U)) + aOrbiterK) + aPhaseDWandererUpdateSaltA[((aIndex + 18U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 56U) + RotL64(aOrbiterB, 58U)) + aOrbiterH) + RotL64(aCarry, 47U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 11U) + aOrbiterC) + RotL64(aOrbiterB, 41U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 41U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + RotL64(aWandererC, 58U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 30217U)) & S_BLOCK1], 54U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29557U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 32264U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((aIndex + 29078U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aIngress, 4U)) ^ (RotL64(aPrevious, 21U) ^ RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = (aWandererB + RotL64(aCross, 3U)) + 14624277139785904404U;
            aOrbiterI = (((aWandererG + RotL64(aPrevious, 47U)) + RotL64(aCarry, 27U)) + 6966977309498165611U) + aPhaseDOrbiterAssignSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = ((aWandererK + RotL64(aScatter, 23U)) + RotL64(aCarry, 13U)) + 205536824352530761U;
            aOrbiterJ = (((aWandererI + RotL64(aIngress, 56U)) + RotL64(aCarry, 57U)) + 16629575265808255692U) + aPhaseDOrbiterAssignSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = (aWandererE + RotL64(aCross, 39U)) + 596881340147972746U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 11944412799107412650U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 4615021315668210206U;
            aOrbiterF = RotL64((aOrbiterF * 6459084105396631625U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 8497630055977606216U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 11131601107309336885U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 18028349768453554935U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 5935883479805510099U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 15629346719765798174U;
            aOrbiterJ = RotL64((aOrbiterJ * 8535523790685945275U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 5279128339113651273U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 16778365912440331821U;
            aOrbiterI = RotL64((aOrbiterI * 705421028266789241U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 16003052937645491524U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 6723226158737614764U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16690657664909260573U), 19U);
            //
            aIngress = RotL64(aOrbiterJ, 27U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterI, 13U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterC, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aIngress, 30U) + aOrbiterF) + RotL64(aOrbiterI, 13U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 19U) + aOrbiterJ) + RotL64(aOrbiterH, 53U)) + RotL64(aCarry, 35U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 41U) + aOrbiterJ) + RotL64(aOrbiterF, 41U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterC, 3U)) + aOrbiterH) + RotL64(aCarry, 21U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 3U) + aOrbiterJ) + RotL64(aOrbiterC, 28U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererK);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + RotL64(aWandererB, 43U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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

void TwistExpander_BaseBall_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 4098U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 7871U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 5859U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 3994U)) & S_BLOCK1], 36U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 35U) + RotL64(aCarry, 5U)) + (RotL64(aCross, 21U) ^ RotL64(aIngress, 52U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = ((aWandererG + RotL64(aScatter, 57U)) + RotL64(aCarry, 47U)) + 12029393034357490020U;
            aOrbiterH = (aWandererI + RotL64(aCross, 43U)) + 4526754731580694987U;
            aOrbiterC = (aWandererD + RotL64(aPrevious, 37U)) + 17060419646421271853U;
            aOrbiterA = (aWandererK + RotL64(aIngress, 26U)) + 4128488893837059683U;
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 19U)) + 12706894827547160110U) + aPhaseEOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = (((aWandererC + RotL64(aCross, 51U)) + RotL64(aCarry, 13U)) + 12506324593645825056U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterE = ((aWandererH + RotL64(aIngress, 13U)) + RotL64(aCarry, 29U)) + 12581344490649250025U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 14357032418199130132U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 15341977701796331249U;
            aOrbiterC = RotL64((aOrbiterC * 6332369248718076031U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 7086602307544733241U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 12398300065276832486U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 18157408831225635333U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 2499745046076601988U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 7249361592814001829U;
            aOrbiterJ = RotL64((aOrbiterJ * 14597139848072319685U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 3254456186337366437U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 3472973415969046680U;
            aOrbiterE = RotL64((aOrbiterE * 14583566953969168353U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 7905718972111691591U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 15941413652144021522U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3473779492962783565U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 10583964125960308762U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 13659925272340853715U;
            aOrbiterA = RotL64((aOrbiterA * 16708294803316630743U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 9487054537489454887U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 13287757570441887517U;
            aOrbiterH = RotL64((aOrbiterH * 17351439045329892107U), 3U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterK, 5U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 27U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 35U));
            aIngress = aIngress + RotL64(aOrbiterC, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterC, 21U)) + aOrbiterI);
            aWandererD = aWandererD + (((RotL64(aCross, 5U) + aOrbiterK) + RotL64(aOrbiterH, 51U)) + RotL64(aCarry, 35U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 60U) + RotL64(aOrbiterE, 60U)) + aOrbiterA);
            aWandererK = aWandererK + (((RotL64(aPrevious, 27U) + aOrbiterE) + RotL64(aOrbiterI, 27U)) + RotL64(aCarry, 47U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 11U) + aOrbiterE) + RotL64(aOrbiterH, 5U)) + aPhaseEWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 47U) + RotL64(aOrbiterH, 41U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterJ, 11U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 44U));
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererC, 57U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8469U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneD[((aIndex + 9288U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 13593U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneB[((aIndex + 11708U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCarry, 48U)) ^ (RotL64(aCross, 35U) + RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = ((aWandererE + RotL64(aCross, 47U)) + RotL64(aCarry, 41U)) + 7651355040951791298U;
            aOrbiterF = (((aWandererD + RotL64(aScatter, 20U)) + RotL64(aCarry, 21U)) + 13988210277931659312U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 35U)) + 9846849412579537783U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 57U)) + RotL64(aCarry, 3U)) + 12746719939495876158U;
            aOrbiterG = (aWandererF + RotL64(aCross, 29U)) + 11498066185182895284U;
            aOrbiterE = (aWandererA + RotL64(aScatter, 11U)) + 11101058955193080232U;
            aOrbiterH = (aWandererK + RotL64(aPrevious, 3U)) + 15513734459555672046U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 15711108675349394643U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 4771231759949468556U;
            aOrbiterA = RotL64((aOrbiterA * 9806191054594333615U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 11449258010811305256U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 17036938391509986723U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7411466953205347639U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 6999245666776654250U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 2106819066263369528U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13005885810757743129U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 12716183358903477216U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 16752724547046059889U;
            aOrbiterF = RotL64((aOrbiterF * 11475905692393034141U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 17623077680983093163U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 6726003022297274986U;
            aOrbiterG = RotL64((aOrbiterG * 14709385877103232653U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 2842410225096524740U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 9235178377537910514U;
            aOrbiterE = RotL64((aOrbiterE * 11813751114775673845U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 2619888019860844610U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 6295481948199619613U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15429161806953951205U), 21U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterG, 35U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + (RotL64(aOrbiterE, 23U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterH, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aCross, 12U) + aOrbiterC) + RotL64(aOrbiterF, 11U)) + RotL64(aCarry, 11U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 57U) + aOrbiterG) + RotL64(aOrbiterH, 29U));
            aWandererK = aWandererK + (((RotL64(aIngress, 41U) + RotL64(aOrbiterG, 5U)) + aOrbiterK) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 47U) + aOrbiterC) + RotL64(aOrbiterA, 57U));
            aWandererD = aWandererD + ((((RotL64(aIngress, 21U) + aOrbiterG) + RotL64(aOrbiterE, 21U)) + RotL64(aCarry, 39U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 5U) + aOrbiterC) + RotL64(aOrbiterE, 37U));
            aWandererC = aWandererC + ((RotL64(aCross, 29U) + aOrbiterK) + RotL64(aOrbiterA, 44U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 44U));
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererJ, 11U);
            aCarry = aCarry + RotL64(aIngress, 40U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 23430U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((aIndex + 18388U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 21282U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneC[((aIndex + 23560U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCross, 41U)) ^ (RotL64(aCarry, 26U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = ((aWandererJ + RotL64(aCross, 13U)) + RotL64(aCarry, 51U)) + 12632404972795375757U;
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 47U)) + RotL64(aCarry, 39U)) + 5351879979055988456U;
            aOrbiterC = (aWandererA + RotL64(aScatter, 39U)) + 3597737727467443413U;
            aOrbiterH = (((aWandererG + RotL64(aIngress, 3U)) + RotL64(aCarry, 13U)) + 2830846754917852318U) + aPhaseEOrbiterAssignSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterD = (aWandererD + RotL64(aPrevious, 53U)) + 17311925960294518018U;
            aOrbiterE = (aWandererE + RotL64(aIngress, 30U)) + 2083584640523695383U;
            aOrbiterK = ((aWandererI + RotL64(aScatter, 23U)) + 15049343611387010158U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 6443050378205811147U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 6021965178697344070U;
            aOrbiterC = RotL64((aOrbiterC * 6054064448935006741U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 5080289878758029976U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 576927745306972983U;
            aOrbiterI = RotL64((aOrbiterI * 16008958833683246115U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 4728489691382690859U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 6184355840165758855U;
            aOrbiterF = RotL64((aOrbiterF * 1515043910404156423U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 11220539885798595450U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 11091438724966718214U;
            aOrbiterH = RotL64((aOrbiterH * 8225347114759391961U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 17184210490020062419U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 2150997767099116408U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8058553821648892499U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 7021953562676903717U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 17159676348343312834U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13877284519668483549U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 10367891770525239784U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 11922478487264201233U;
            aOrbiterK = RotL64((aOrbiterK * 9195137452661956029U), 13U);
            //
            aIngress = RotL64(aOrbiterK, 43U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterH, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterD, 11U)) + aOrbiterH) + aPhaseEWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterD, 19U)) + aOrbiterE) + RotL64(aCarry, 51U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterE, 51U)) + aOrbiterH);
            aWandererI = aWandererI + ((RotL64(aScatter, 4U) + aOrbiterC) + RotL64(aOrbiterE, 57U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 41U) + aOrbiterF) + RotL64(aOrbiterD, 35U));
            aWandererE = aWandererE + (((RotL64(aIngress, 23U) + RotL64(aOrbiterD, 29U)) + aOrbiterK) + RotL64(aCarry, 11U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterI, 42U)) + aOrbiterK) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererI);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 42U));
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererA, 5U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 28235U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneB[((aIndex + 31451U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 30394U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 25335U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aPrevious, 13U)) + (RotL64(aIngress, 27U) ^ RotL64(aCarry, 56U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 11U)) + RotL64(aCarry, 5U)) + 16802219662864902427U;
            aOrbiterE = (((aWandererA + RotL64(aPrevious, 3U)) + RotL64(aCarry, 51U)) + 14332033461409490629U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = ((aWandererK + RotL64(aCross, 57U)) + RotL64(aCarry, 23U)) + 8781794298640286845U;
            aOrbiterF = (aWandererG + RotL64(aIngress, 51U)) + 8459933908074937264U;
            aOrbiterC = (aWandererB + RotL64(aCross, 35U)) + 1883580287986004426U;
            aOrbiterG = (aWandererJ + RotL64(aIngress, 28U)) + 17500258188004626118U;
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 43U)) + 7934811305150872870U) + aPhaseEOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1];
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 6380363892361098905U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 12623079132626676910U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12406671746344127399U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 10455208121949202703U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 8805532707916767629U;
            aOrbiterG = RotL64((aOrbiterG * 666082374369701881U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 9161544391400377699U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 3501434325829663268U;
            aOrbiterE = RotL64((aOrbiterE * 7933545151293799637U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 651783304096081996U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 441505031509930622U;
            aOrbiterC = RotL64((aOrbiterC * 8045355432310956143U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 1771159983581326424U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 15227946417377695989U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1563141188972797601U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 4153717524193279095U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 4404521756523902829U;
            aOrbiterF = RotL64((aOrbiterF * 1410342912973206203U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 6231945075461813285U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 3864780227164426690U;
            aOrbiterD = RotL64((aOrbiterD * 18031353247480673617U), 35U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterD, 11U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 37U));
            aIngress = aIngress + RotL64(aOrbiterH, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aIngress, 51U) + aOrbiterJ) + RotL64(aOrbiterE, 43U)) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 27U) + aOrbiterC) + RotL64(aOrbiterH, 53U));
            aWandererG = aWandererG + (((RotL64(aCross, 3U) + RotL64(aOrbiterF, 37U)) + aOrbiterC) + aPhaseEWandererUpdateSaltB[((aIndex + 20U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 10U) + aOrbiterH) + RotL64(aOrbiterJ, 30U));
            aWandererB = aWandererB + ((((RotL64(aPrevious, 41U) + RotL64(aOrbiterD, 21U)) + aOrbiterJ) + RotL64(aCarry, 47U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 57U) + aOrbiterH) + RotL64(aOrbiterE, 11U));
            aWandererF = aWandererF + ((RotL64(aCross, 19U) + RotL64(aOrbiterJ, 3U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererG, 42U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererJ, 27U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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

void TwistExpander_BaseBall_Arx::Twist_D(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 4055U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2641U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 1173U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((aIndex + 6989U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 50U) ^ RotL64(aCross, 37U)) + (RotL64(aCarry, 11U) ^ RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = (((aWandererK + RotL64(aCross, 53U)) + RotL64(aCarry, 51U)) + 11480359716598965890U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 28U)) + 15431182525482873419U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterK = ((aWandererF + RotL64(aIngress, 37U)) + RotL64(aCarry, 5U)) + 11360504974812776707U;
            aOrbiterG = ((aWandererH + RotL64(aScatter, 13U)) + RotL64(aCarry, 19U)) + 9292576416573382769U;
            aOrbiterA = (aWandererD + RotL64(aPrevious, 3U)) + 1549257414531028975U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 5347769463033129317U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 17019199177478377234U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4336112198640602307U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 16558106007323125094U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 3976182233825939422U;
            aOrbiterD = RotL64((aOrbiterD * 4392162052317572289U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 2889047161195954395U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 2241831345026962605U;
            aOrbiterG = RotL64((aOrbiterG * 5757458560979927857U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 12850802412140579294U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 13541744735436450160U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 906089290000537439U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 2085863085516538212U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 2969034221711544086U;
            aOrbiterA = RotL64((aOrbiterA * 7768528124408400403U), 19U);
            //
            aIngress = RotL64(aOrbiterD, 37U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterA, 27U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterK, 4U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aCross, 54U) + RotL64(aOrbiterA, 30U)) + aOrbiterH) + RotL64(aCarry, 37U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterK, 3U)) + aOrbiterD);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 35U) + aOrbiterD) + RotL64(aOrbiterA, 13U)) + RotL64(aCarry, 13U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 5U) + aOrbiterD) + RotL64(aOrbiterG, 41U)) + aPhaseFWandererUpdateSaltE[((aIndex + 8U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterG, 21U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 52U));
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererF, 35U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 12410U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 12496U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9915U)) & S_BLOCK1], 44U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 10877U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aIngress, 13U)) ^ (RotL64(aPrevious, 26U) + RotL64(aCarry, 43U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = ((aWandererB + RotL64(aScatter, 52U)) + RotL64(aCarry, 43U)) + 18302975933754610273U;
            aOrbiterG = (((aWandererF + RotL64(aCross, 21U)) + RotL64(aCarry, 13U)) + 16736972646771456082U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = (aWandererC + RotL64(aIngress, 43U)) + 17389406266488137442U;
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 3U)) + RotL64(aCarry, 27U)) + 5252511566486165539U;
            aOrbiterB = ((aWandererA + RotL64(aScatter, 13U)) + 5730715427422747640U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 6412695646456045825U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 9539701605708994494U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6511935168278632407U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 18355107116412945722U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 11735742491750132942U;
            aOrbiterB = RotL64((aOrbiterB * 18129835093627763685U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 12363819388562658842U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 5861430292304371543U;
            aOrbiterA = RotL64((aOrbiterA * 12989055611235382695U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 15027487084595017708U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 7012850020745791926U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15952928839355613939U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 11904871669287886120U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 11199760114477343208U;
            aOrbiterH = RotL64((aOrbiterH * 7156374911847525867U), 21U);
            //
            aIngress = RotL64(aOrbiterA, 51U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 41U));
            aIngress = aIngress + RotL64(aOrbiterB, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aCross, 58U) + aOrbiterG) + RotL64(aOrbiterA, 57U)) + aPhaseFWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 5U) + aOrbiterA) + RotL64(aOrbiterB, 41U)) + RotL64(aCarry, 21U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 47U) + aOrbiterB) + RotL64(aOrbiterF, 22U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 13U) + RotL64(aOrbiterH, 13U)) + aOrbiterA) + RotL64(aCarry, 37U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 27U) + aOrbiterF) + RotL64(aOrbiterH, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererD, 50U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 24013U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((aIndex + 22453U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 23187U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 23095U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 27U) + RotL64(aIngress, 12U)) ^ (RotL64(aCarry, 51U) + RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = (((aWandererC + RotL64(aPrevious, 3U)) + RotL64(aCarry, 57U)) + 18087125778766689269U) + aPhaseFOrbiterAssignSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = (aWandererK + RotL64(aIngress, 48U)) + 13710545066503235196U;
            aOrbiterB = ((aWandererH + RotL64(aCross, 23U)) + RotL64(aCarry, 27U)) + 1701939704736254645U;
            aOrbiterI = (((aWandererE + RotL64(aScatter, 57U)) + RotL64(aCarry, 39U)) + 8064093611384019909U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = (aWandererG + RotL64(aIngress, 13U)) + 16623332751533885431U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 15590129153794910109U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 7413312683079107383U;
            aOrbiterB = RotL64((aOrbiterB * 9496176571314516005U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 4186064478651458810U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 5501191643940735954U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14254804649177125269U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 11064645242200570835U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 13825922087298055833U;
            aOrbiterJ = RotL64((aOrbiterJ * 7529317892716108867U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 5944980709887369970U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 8181136916070569646U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 395183021205661827U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 15442336949157292482U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 11580554435240641337U;
            aOrbiterE = RotL64((aOrbiterE * 6654637892858767739U), 13U);
            //
            aIngress = RotL64(aOrbiterB, 27U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 51U));
            aIngress = aIngress + RotL64(aOrbiterE, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 3U) + aOrbiterK) + RotL64(aOrbiterB, 4U)) + aPhaseFWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 43U) + aOrbiterK) + RotL64(aOrbiterJ, 35U)) + RotL64(aCarry, 43U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 22U) + aOrbiterB) + RotL64(aOrbiterE, 13U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 57U) + aOrbiterI) + RotL64(aOrbiterB, 27U)) + RotL64(aCarry, 13U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 11U) + aOrbiterI) + RotL64(aOrbiterE, 43U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 60U));
            aCarry = aCarry + RotL64(aWandererK, 35U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 30614U)) & S_BLOCK1], 10U) ^ RotL64(aWorkLaneB[((aIndex + 24717U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 32689U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneD[((aIndex + 31468U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 27U) + RotL64(aCarry, 43U)) ^ (RotL64(aIngress, 11U) ^ RotL64(aCross, 60U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 39U)) + 9041099828460168106U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterG = (aWandererD + RotL64(aIngress, 57U)) + 12883711604096848454U;
            aOrbiterE = ((aWandererI + RotL64(aCross, 26U)) + RotL64(aCarry, 13U)) + 17420968786226443079U;
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 3U)) + RotL64(aCarry, 41U)) + 3448213891716125104U;
            aOrbiterF = (((aWandererE + RotL64(aIngress, 11U)) + RotL64(aCarry, 57U)) + 11866455977445336560U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 4119356835384495905U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 2186212599698637068U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6756888950976735707U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 6506144898969301620U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 12556800923644051626U;
            aOrbiterJ = RotL64((aOrbiterJ * 15961043406612913121U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 4075551535185182945U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 17877694808492008749U;
            aOrbiterC = RotL64((aOrbiterC * 901315308379887473U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 5553428900598223316U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 14362304852277160675U;
            aOrbiterG = RotL64((aOrbiterG * 11415103199856419303U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 9174200302876075831U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 16110739511917638547U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7004356839428657949U), 23U);
            //
            aIngress = RotL64(aOrbiterG, 29U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 41U));
            aIngress = aIngress + RotL64(aOrbiterE, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aScatter, 35U) + RotL64(aOrbiterJ, 29U)) + aOrbiterF) + RotL64(aCarry, 43U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterJ, 5U)) + aOrbiterG);
            aWandererE = aWandererE + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterJ, 39U)) + aOrbiterC) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 56U) + aOrbiterG) + RotL64(aOrbiterE, 19U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 13U) + RotL64(aOrbiterF, 56U)) + aOrbiterG) + aPhaseFWandererUpdateSaltE[((aIndex + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + (RotL64(aWandererI, 5U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererG, 47U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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

void TwistExpander_BaseBall_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 4933U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 4021U)) & S_BLOCK1], 44U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 607U)) & S_BLOCK1], 26U) ^ RotL64(aWorkLaneD[((aIndex + 7739U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCarry, 53U)) ^ (RotL64(aCross, 37U) + RotL64(aPrevious, 6U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = (aWandererA + RotL64(aIngress, 19U)) + 6243113109470883144U;
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 40U)) + RotL64(aCarry, 57U)) + 3891552123999605832U;
            aOrbiterG = (((aWandererG + RotL64(aCross, 53U)) + RotL64(aCarry, 37U)) + 8758797898587019128U) + aPhaseGOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = (aWandererC + RotL64(aScatter, 27U)) + 1005891374086408851U;
            aOrbiterE = (((aWandererE + RotL64(aIngress, 5U)) + RotL64(aCarry, 21U)) + 3713426782180050764U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 18358143862391573534U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 17504394029693712404U;
            aOrbiterG = RotL64((aOrbiterG * 3391716204095092531U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 5312729289027417014U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 2560873623431186029U;
            aOrbiterK = RotL64((aOrbiterK * 16843728573219210173U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 16309322822806704211U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 10195513918020652600U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14569219741824123715U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 2552116263258744287U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 7732784879810980089U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15041929399477790999U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 16499127570665381507U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 10890036715535519036U;
            aOrbiterE = RotL64((aOrbiterE * 9065115450010475187U), 19U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterB, 5U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 19U));
            aIngress = aIngress + RotL64(aOrbiterD, 58U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterD, 38U)) + aOrbiterE);
            aWandererG = aWandererG + ((((RotL64(aCross, 13U) + RotL64(aOrbiterK, 5U)) + aOrbiterG) + RotL64(aCarry, 47U)) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 39U) + aOrbiterE) + RotL64(aOrbiterG, 19U));
            aWandererC = aWandererC + ((((RotL64(aIngress, 3U) + aOrbiterB) + RotL64(aOrbiterD, 29U)) + RotL64(aCarry, 35U)) + aPhaseGWandererUpdateSaltB[((aIndex + 22U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 50U) + RotL64(aOrbiterK, 47U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 52U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererC, 23U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 11386U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 10547U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 8221U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 11727U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 21U) + RotL64(aIngress, 6U)) ^ (RotL64(aCross, 53U) + RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = (((aWandererI + RotL64(aCross, 43U)) + RotL64(aCarry, 51U)) + 7722279280863371124U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 29U)) + RotL64(aCarry, 39U)) + 11584220561732385598U;
            aOrbiterK = (aWandererE + RotL64(aIngress, 11U)) + 7834679350105534657U;
            aOrbiterD = (((aWandererG + RotL64(aScatter, 60U)) + RotL64(aCarry, 13U)) + 11347994382444180879U) + aPhaseGOrbiterAssignSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterA = (aWandererA + RotL64(aPrevious, 21U)) + 9449903188047063431U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 6516243976652795170U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 8420815253991184777U;
            aOrbiterK = RotL64((aOrbiterK * 1358649408967265415U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 9081386852515170937U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 14375955191735286867U;
            aOrbiterA = RotL64((aOrbiterA * 2772840314542262283U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 880757589768436072U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 3349856625725164229U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 681514212582331781U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 7826309957607577207U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 8057435761214313635U;
            aOrbiterH = RotL64((aOrbiterH * 4718430712767038607U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 9565237500443303103U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 15893066735310588501U;
            aOrbiterD = RotL64((aOrbiterD * 8457633439171452397U), 41U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterK, 57U);
            aIngress = aIngress + (RotL64(aOrbiterD, 5U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterF, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aIngress, 3U) + aOrbiterK) + RotL64(aOrbiterD, 21U)) + RotL64(aCarry, 13U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 12U) + RotL64(aOrbiterA, 3U)) + aOrbiterK);
            aWandererF = aWandererF + ((((RotL64(aCross, 39U) + RotL64(aOrbiterF, 52U)) + aOrbiterA) + RotL64(aCarry, 37U)) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 29U) + aOrbiterH) + RotL64(aOrbiterD, 35U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 47U) + aOrbiterH) + RotL64(aOrbiterF, 11U)) + aPhaseGWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 48U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererE, 27U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 20862U)) & S_BLOCK1], 34U) ^ RotL64(aWorkLaneD[((aIndex + 22854U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23292U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneB[((aIndex + 24206U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 53U)) + (RotL64(aCross, 18U) ^ RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = ((aWandererG + RotL64(aIngress, 57U)) + RotL64(aCarry, 27U)) + 11210042748013785976U;
            aOrbiterJ = ((aWandererK + RotL64(aCross, 3U)) + 4584747303233477454U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = (((aWandererE + RotL64(aScatter, 43U)) + RotL64(aCarry, 53U)) + 8878765929792969517U) + aPhaseGOrbiterAssignSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 35U)) + 2172232330280041122U;
            aOrbiterF = ((aWandererA + RotL64(aCross, 18U)) + RotL64(aCarry, 41U)) + 8378937026022264016U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 8683007464695824208U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 9564352997357118134U;
            aOrbiterB = RotL64((aOrbiterB * 17869948990449143305U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 11713878436769887528U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 8052917623074021077U;
            aOrbiterJ = RotL64((aOrbiterJ * 7450115139081623477U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 7720597162792145185U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 2602847785328475621U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14065077077207224525U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 17813669222300509724U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 8724263063156573013U;
            aOrbiterI = RotL64((aOrbiterI * 3632927017737834359U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 6882429835961613492U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 13213313479525717359U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2411431247725974895U), 53U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterB, 39U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + RotL64(aOrbiterF, 28U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aIngress, 23U) + RotL64(aOrbiterF, 11U)) + aOrbiterI) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 50U) + aOrbiterJ) + RotL64(aOrbiterB, 37U)) + aPhaseGWandererUpdateSaltA[((aIndex + 20U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 37U) + aOrbiterJ) + RotL64(aOrbiterE, 52U)) + RotL64(aCarry, 27U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 11U) + aOrbiterF) + RotL64(aOrbiterB, 27U));
            aWandererA = aWandererA + (((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 19U)) + aOrbiterE) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererA);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + RotL64(aWandererJ, 4U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 27875U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29688U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25637U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 28983U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aPrevious, 19U)) ^ (RotL64(aCarry, 51U) ^ RotL64(aIngress, 36U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = (aWandererK + RotL64(aScatter, 10U)) + 18319689184146942855U;
            aOrbiterI = (((aWandererG + RotL64(aCross, 39U)) + RotL64(aCarry, 53U)) + 8041304130090501019U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = ((aWandererC + RotL64(aIngress, 19U)) + RotL64(aCarry, 19U)) + 11347064191990897738U;
            aOrbiterD = (aWandererD + RotL64(aPrevious, 27U)) + 15242243470024447468U;
            aOrbiterJ = (((aWandererF + RotL64(aScatter, 47U)) + RotL64(aCarry, 3U)) + 10619749107163611105U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 14795614276221947128U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 1578095288886372393U;
            aOrbiterF = RotL64((aOrbiterF * 9953192041564147241U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 13593906305770501684U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 8919815528334599172U;
            aOrbiterH = RotL64((aOrbiterH * 2033810402808238127U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 17425548324720065145U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 11125018338392347335U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4377887040461528587U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 3779189180734244399U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 10958224663276134041U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6206963519509783781U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 4317305352561612995U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 4891139433808505355U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11507024985663120317U), 57U);
            //
            aIngress = RotL64(aOrbiterJ, 38U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterF, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aIngress, 40U) + aOrbiterF) + RotL64(aOrbiterI, 53U)) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 53U) + aOrbiterJ) + RotL64(aOrbiterD, 14U));
            aWandererC = aWandererC + ((((RotL64(aCross, 27U) + aOrbiterF) + RotL64(aOrbiterD, 3U)) + RotL64(aCarry, 5U)) + aPhaseGWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 5U) + aOrbiterD) + RotL64(aOrbiterH, 39U));
            aWandererG = aWandererG + (((RotL64(aIngress, 13U) + RotL64(aOrbiterH, 27U)) + aOrbiterJ) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 13U));
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 57U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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

void TwistExpander_BaseBall_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 4130U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneB[((aIndex + 3747U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4486U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 65U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCross, 51U)) + (RotL64(aIngress, 6U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = (((aWandererK + RotL64(aCross, 21U)) + RotL64(aCarry, 53U)) + 14823268998003220191U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = (aWandererD + RotL64(aScatter, 52U)) + 15295237288788213847U;
            aOrbiterJ = ((aWandererH + RotL64(aPrevious, 11U)) + 16434853402001133899U) + aPhaseHOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = ((aWandererC + RotL64(aIngress, 29U)) + RotL64(aCarry, 35U)) + 7555911304407871631U;
            aOrbiterE = ((aWandererG + RotL64(aScatter, 37U)) + RotL64(aCarry, 13U)) + 14977248264994834620U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 9707764144919392380U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 1277304385464681529U;
            aOrbiterJ = RotL64((aOrbiterJ * 2864691650462053463U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 3089786220465849395U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 3700503853358695085U;
            aOrbiterI = RotL64((aOrbiterI * 2079089949442685421U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 3240054112993517371U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 16897532076915366859U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4120874717534309035U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 18167359289798364307U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 8870819278575769863U;
            aOrbiterH = RotL64((aOrbiterH * 9334066154398059075U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 15363069206212330251U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 14858164441499725158U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14931933411393847915U), 3U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterJ, 40U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 53U));
            aIngress = aIngress + RotL64(aOrbiterE, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aScatter, 29U) + RotL64(aOrbiterI, 11U)) + aOrbiterF) + RotL64(aCarry, 13U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterE, 27U)) + aOrbiterH) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 5U) + aOrbiterJ) + RotL64(aOrbiterE, 53U)) + RotL64(aCarry, 35U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 60U) + aOrbiterH) + RotL64(aOrbiterF, 19U));
            aWandererK = aWandererK + (((RotL64(aScatter, 21U) + RotL64(aOrbiterI, 38U)) + aOrbiterJ) + aPhaseHWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererC);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 21U));
            aCarry = aCarry + RotL64(aWandererD, 43U);
            aCarry = aCarry + RotL64(aIngress, 34U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 12574U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 10785U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 8688U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12522U)) & S_BLOCK1], 46U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCarry, 40U)) + (RotL64(aPrevious, 11U) ^ RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 5U)) + 3650233661228036955U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 18U)) + RotL64(aCarry, 57U)) + 11607036400067735729U;
            aOrbiterE = ((aWandererD + RotL64(aCross, 57U)) + RotL64(aCarry, 5U)) + 3899614406903883035U;
            aOrbiterH = ((aWandererE + RotL64(aScatter, 37U)) + RotL64(aCarry, 21U)) + 8159156925629965143U;
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 29U)) + 7148903913967261270U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 9161665622287517848U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 2981535013474059469U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4434815231517266013U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 15812469008200319549U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 14687469489893270300U;
            aOrbiterK = RotL64((aOrbiterK * 14142363399696670451U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 6025209349511417063U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 12964750392311112676U;
            aOrbiterG = RotL64((aOrbiterG * 12955480283032701843U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 6572355895765394340U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 3542300121890027981U;
            aOrbiterI = RotL64((aOrbiterI * 11201491178181273935U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 6477175684045398359U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 1081388388827929314U;
            aOrbiterH = RotL64((aOrbiterH * 8752188637514143529U), 3U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterE, 29U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 19U));
            aIngress = aIngress + RotL64(aOrbiterH, 56U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterE, 38U)) + aOrbiterK);
            aWandererH = aWandererH + ((((RotL64(aCross, 27U) + aOrbiterH) + RotL64(aOrbiterI, 57U)) + RotL64(aCarry, 37U)) + aPhaseHWandererUpdateSaltC[((aIndex + 18U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterI, 13U)) + aOrbiterG);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 37U) + RotL64(aOrbiterH, 27U)) + aOrbiterG) + RotL64(aCarry, 51U)) + aPhaseHWandererUpdateSaltF[((aIndex + 20U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 48U) + aOrbiterK) + RotL64(aOrbiterG, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 58U) ^ aWandererD);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + RotL64(aWandererE, 13U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 18709U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneD[((aIndex + 20636U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20011U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((aIndex + 21237U)) & S_BLOCK1], 44U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 57U)) + (RotL64(aCross, 44U) + RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = (aWandererA + RotL64(aScatter, 5U)) + 15726877954695761686U;
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 39U)) + 14187652171881943587U) + aPhaseHOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = ((aWandererK + RotL64(aIngress, 28U)) + RotL64(aCarry, 21U)) + 8420423151313882782U;
            aOrbiterH = (((aWandererE + RotL64(aCross, 13U)) + RotL64(aCarry, 57U)) + 14942322692433259283U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 47U)) + RotL64(aCarry, 39U)) + 7272331475919796255U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 154504365041805840U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 17475491222554948786U;
            aOrbiterK = RotL64((aOrbiterK * 2095330528612694779U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 5759181483165339605U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 5993060214499322845U;
            aOrbiterC = RotL64((aOrbiterC * 10799489831896153301U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 10901786237875941844U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 17135786595614068473U;
            aOrbiterD = RotL64((aOrbiterD * 15923538730142047043U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 5208202073886811165U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 6821452921018900631U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13119330055184115669U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 13348064837402206969U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 8967943922403445136U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 300168481725373093U), 11U);
            //
            aIngress = RotL64(aOrbiterF, 23U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 35U));
            aIngress = aIngress + RotL64(aOrbiterC, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aCross, 3U) + RotL64(aOrbiterC, 43U)) + aOrbiterK) + RotL64(aCarry, 51U)) + aPhaseHWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterD, 19U)) + aOrbiterH);
            aWandererK = aWandererK + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterF, 56U)) + aOrbiterK) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 58U) + aOrbiterD) + RotL64(aOrbiterC, 5U));
            aWandererE = aWandererE + (((RotL64(aScatter, 21U) + RotL64(aOrbiterH, 29U)) + aOrbiterF) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 37U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererA, 48U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 11U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 27681U)) & S_BLOCK1], 18U) ^ RotL64(aWorkLaneA[((aIndex + 30428U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25650U)) & S_BLOCK1], 44U) ^ RotL64(aWorkLaneC[((aIndex + 31565U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aPrevious, 43U)) ^ (RotL64(aCarry, 26U) + RotL64(aIngress, 13U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = ((aWandererC + RotL64(aCross, 51U)) + 11698283336767769359U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 5U)) + RotL64(aCarry, 47U)) + 13297826354831483872U;
            aOrbiterJ = (((aWandererI + RotL64(aScatter, 27U)) + RotL64(aCarry, 5U)) + 15254999058287530795U) + aPhaseHOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = ((aWandererG + RotL64(aIngress, 36U)) + RotL64(aCarry, 29U)) + 17474166585085346567U;
            aOrbiterC = (aWandererF + RotL64(aScatter, 19U)) + 15684783498452840289U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 5061229733465216486U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 15370981279168377944U;
            aOrbiterJ = RotL64((aOrbiterJ * 15893028157665379361U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 17966672773619554092U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 14685092893994491068U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1627758964162892429U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 12798804186209406389U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 2848444181474221574U;
            aOrbiterH = RotL64((aOrbiterH * 13730480364920876877U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 8551142075919636146U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 8833198159158950723U;
            aOrbiterA = RotL64((aOrbiterA * 7650289040764974737U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 7351473160893666232U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 14204899612487622222U;
            aOrbiterC = RotL64((aOrbiterC * 6317485031956448029U), 47U);
            //
            aIngress = RotL64(aOrbiterA, 3U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 14U));
            aIngress = aIngress + RotL64(aOrbiterJ, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aIngress, 37U) + RotL64(aOrbiterK, 58U)) + aOrbiterC) + RotL64(aCarry, 23U)) + aPhaseHWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 19U) + aOrbiterC) + RotL64(aOrbiterH, 39U));
            aWandererF = aWandererF + (((RotL64(aScatter, 28U) + RotL64(aOrbiterH, 23U)) + aOrbiterJ) + RotL64(aCarry, 51U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 47U) + aOrbiterA) + RotL64(aOrbiterK, 3U));
            aWandererG = aWandererG + (((RotL64(aIngress, 57U) + RotL64(aOrbiterC, 11U)) + aOrbiterJ) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 48U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 21U));
            aCarry = aCarry + RotL64(aWandererI, 39U);
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
