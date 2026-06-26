#include "TwistExpander_Golf_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_Golf_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xCFE4BE80B7AA1E07ULL + 0x87679481B3C2F71CULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x8C098DF1EB020AF9ULL + 0x9CD65F630158AF8FULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xBE2E2C563919CB19ULL + 0x940ADECD7222A731ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xC2104C23908E0EB9ULL + 0xDACF2C735D31F999ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xB9D43F7FD871B1D9ULL + 0xC8B49C871C4A17A4ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xE9745713F07159BDULL + 0xE35C69BBBB11A258ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xA578CD4703FEFCC3ULL + 0xC3AE32A8CEEB2B38ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xCD0F958CC84434A7ULL + 0xE3E0E7B127C34E67ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xE62B3B2DEC04601DULL + 0x9DB65ACD858F6FBBULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x8AA300DF5C3C33AFULL + 0xFB3703742CA68565ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xCF78F218A32F6791ULL + 0x8A081D01B73421A0ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xB4B4C9FC556DF1FBULL + 0xE03160BAB113697AULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xED62E8F2C5145F51ULL + 0x84F03AB749FDA5EDULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x99A8879F516FCBBBULL + 0xEC3C7CFF211E7C4EULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xCA72D0F41AB72723ULL + 0xA99B0702B2907DC1ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xA48F82DCC117EAB3ULL + 0xF8A7F628CDADE214ULL);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 5327U)) & S_BLOCK1], 29U) ^ RotL64(pSnow[((aIndex + 1401U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 511U)) & S_BLOCK1], 36U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 3388U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 41U)) + (RotL64(aCross, 29U) + RotL64(aIngress, 56U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererK + RotL64(aIngress, 60U)) + 13714409587461539863U;
            aOrbiterG = (aWandererG + RotL64(aCross, 13U)) + 14101156723903265839U;
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 35U)) + 7063754562895369001U) + aOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = (aWandererC + RotL64(aScatter, 57U)) + 12320578575245519386U;
            aOrbiterB = (((aWandererA + RotL64(aPrevious, 21U)) + RotL64(aCarry, 27U)) + 11744826789631008424U) + aNonceWordJ;
            aOrbiterH = (aWandererE + RotL64(aIngress, 39U)) + 8744816505096675597U;
            aOrbiterE = ((aWandererF + RotL64(aCross, 23U)) + RotL64(aCarry, 41U)) + 10405435520084528645U;
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 47U)) + RotL64(aCarry, 35U)) + 1463157688070683543U;
            aOrbiterJ = (aWandererB + RotL64(aIngress, 53U)) + 12379603577919617703U;
            aOrbiterK = (aWandererH + RotL64(aPrevious, 3U)) + 1343439118031348146U;
            aOrbiterC = (((aWandererD + RotL64(aCross, 50U)) + 16118850268070235540U) + aOrbiterAssignSaltE[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordL;
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 14116264435819277136U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 5251698273012432109U;
            aOrbiterF = RotL64((aOrbiterF * 1495818611622063967U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 14806408656041403829U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 11569345414052398227U;
            aOrbiterH = RotL64((aOrbiterH * 9913158908301414861U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 17063874769147888574U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterE) ^ 9927420478679581917U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterI = RotL64((aOrbiterI * 9042782809534196563U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 2550285599827162167U) + aOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 17801534123304996448U;
            aOrbiterD = RotL64((aOrbiterD * 2160836889363614721U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 6456685241021762041U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 17064208177372969289U;
            aOrbiterE = RotL64((aOrbiterE * 13726627607233302493U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 18279938244131982650U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 8211002229712129419U;
            aOrbiterJ = RotL64((aOrbiterJ * 12931373380977640645U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 12795832560781931767U) + aOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 286378504074349650U) ^ aNonceWordO;
            aOrbiterC = RotL64((aOrbiterC * 85453101173293509U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 5835304250436889513U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 12704972686724379659U;
            aOrbiterG = RotL64((aOrbiterG * 1198789639656336053U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 12555700587254295099U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 6740149669657971715U;
            aOrbiterB = RotL64((aOrbiterB * 9376048577305482691U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 1541392147096889431U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 16891341703173286949U;
            aOrbiterA = RotL64((aOrbiterA * 697452963711223355U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 8811637585092392653U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 13714409587461539863U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2578939920876994763U), 13U);
            //
            aIngress = RotL64(aOrbiterD, 24U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 37U));
            aIngress = aIngress + (RotL64(aOrbiterI, 39U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 5U));
            aIngress = aIngress + RotL64(aOrbiterE, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aCross, 3U) + RotL64(aOrbiterE, 5U)) + aOrbiterC);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterK, 35U)) + aOrbiterJ);
            aWandererD = aWandererD + ((RotL64(aScatter, 47U) + RotL64(aOrbiterC, 51U)) + aOrbiterB);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 34U) + aOrbiterC) + RotL64(aOrbiterD, 11U)) + aWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aIngress, 37U) + aOrbiterJ) + RotL64(aOrbiterC, 56U)) + RotL64(aCarry, 57U)) + aNonceWordD);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterE, 43U)) + aOrbiterA);
            aWandererB = aWandererB + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterF, 37U)) + aOrbiterA) + RotL64(aCarry, 43U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 23U) + aOrbiterI) + RotL64(aOrbiterB, 39U));
            aWandererC = aWandererC + (((RotL64(aScatter, 27U) + RotL64(aOrbiterF, 47U)) + aOrbiterH) + aWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 13U) + aOrbiterI) + RotL64(aOrbiterE, 13U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 6U) + RotL64(aOrbiterG, 22U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererG, 18U) ^ aWandererF);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 21U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + RotL64(aWandererH, 48U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordL);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8758U)) & S_BLOCK1], 47U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 8964U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(pSnow[((S_BLOCK1 - aIndex + 8211U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneA[((aIndex + 5811U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 56U) + RotL64(aPrevious, 39U)) ^ (RotL64(aCross, 23U) + RotL64(aIngress, 11U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (((aWandererG + RotL64(aCross, 48U)) + 14624277139785904404U) + aOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterF = (aWandererA + RotL64(aPrevious, 19U)) + 6966977309498165611U;
            aOrbiterB = ((aWandererH + RotL64(aIngress, 21U)) + RotL64(aCarry, 35U)) + 205536824352530761U;
            aOrbiterJ = (aWandererJ + RotL64(aScatter, 57U)) + 16629575265808255692U;
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 5U)) + 596881340147972746U) + aOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = ((aWandererB + RotL64(aCross, 43U)) + RotL64(aCarry, 27U)) + 11944412799107412650U;
            aOrbiterG = (aWandererD + RotL64(aScatter, 41U)) + 4615021315668210206U;
            aOrbiterK = ((aWandererC + RotL64(aIngress, 50U)) + 8497630055977606216U) + aNonceWordB;
            aOrbiterH = (aWandererK + RotL64(aScatter, 27U)) + 11131601107309336885U;
            aOrbiterD = (((aWandererF + RotL64(aPrevious, 29U)) + RotL64(aCarry, 41U)) + 5935883479805510099U) + aNonceWordG;
            aOrbiterI = (aWandererE + RotL64(aIngress, 11U)) + 15629346719765798174U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 5279128339113651273U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 16778365912440331821U;
            aOrbiterB = RotL64((aOrbiterB * 705421028266789241U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 16003052937645491524U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 6723226158737614764U;
            aOrbiterF = RotL64((aOrbiterF * 16690657664909260573U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 9785784358981219543U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 10055457337292292710U) ^ aOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17919129940751761111U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 11779163108592974175U) + aNonceWordF;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 1177999477942202687U;
            aOrbiterG = RotL64((aOrbiterG * 13475069421684114643U), 13U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterE) + 9190694445141492214U) + aOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1]) + aNonceWordK;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 15605342360346353457U;
            aOrbiterH = RotL64((aOrbiterH * 14547769706392595647U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 14877565450677523492U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 1074095623308025684U;
            aOrbiterE = RotL64((aOrbiterE * 7884068939436891093U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 12803174154216941583U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 8813356463693637033U;
            aOrbiterJ = RotL64((aOrbiterJ * 4898237214617563167U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 6063909634038581414U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 15112191502834052566U;
            aOrbiterA = RotL64((aOrbiterA * 6780741782103553485U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 13926459034757240311U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 4324555954703597591U;
            aOrbiterK = RotL64((aOrbiterK * 18068922072149745351U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 7183063131331255506U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 18072787091203847052U;
            aOrbiterD = RotL64((aOrbiterD * 12530396154012878153U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 10143386327707219710U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 14624277139785904404U;
            aOrbiterI = RotL64((aOrbiterI * 12100828883424264587U), 35U);
            //
            aIngress = RotL64(aOrbiterG, 39U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 21U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 37U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 6U));
            aIngress = aIngress + RotL64(aOrbiterC, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aScatter, 39U) + RotL64(aOrbiterG, 43U)) + aOrbiterC);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 27U) + aOrbiterB) + RotL64(aOrbiterI, 19U)) + aWandererUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 60U) + RotL64(aOrbiterG, 53U)) + aOrbiterH) + RotL64(aCarry, 35U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterJ, 34U)) + aOrbiterB);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 43U) + RotL64(aOrbiterD, 57U)) + aOrbiterG);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterA, 23U)) + aOrbiterF);
            aWandererI = aWandererI + (((RotL64(aCross, 23U) + aOrbiterF) + RotL64(aOrbiterH, 39U)) + RotL64(aCarry, 43U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 18U) + aOrbiterE) + RotL64(aOrbiterK, 51U)) + aWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 35U) + aOrbiterB) + RotL64(aOrbiterC, 47U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 3U) + aOrbiterD) + RotL64(aOrbiterH, 37U)) + aNonceWordC);
            aWandererG = aWandererG + ((RotL64(aCross, 41U) + aOrbiterC) + RotL64(aOrbiterE, 60U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + (RotL64(aWandererJ, 18U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 27U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererK, 51U);
            aCarry = aCarry + RotL64(aIngress, 30U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordE);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 11015U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((aIndex + 13267U)) & S_BLOCK1], 26U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 15646U)) & S_BLOCK1], 41U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 12500U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aPrevious, 52U)) + (RotL64(aIngress, 5U) ^ RotL64(aCarry, 23U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererB + RotL64(aIngress, 37U)) + 826930775230515406U;
            aOrbiterC = (aWandererE + RotL64(aScatter, 50U)) + 5137814617363250861U;
            aOrbiterH = (((aWandererF + RotL64(aPrevious, 47U)) + RotL64(aCarry, 51U)) + 14761561947426681616U) + aOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = (aWandererC + RotL64(aCross, 11U)) + 12773023438753662590U;
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 13U)) + 7331345852207096322U) + aNonceWordO;
            aOrbiterE = ((aWandererA + RotL64(aIngress, 39U)) + 3899381212671247460U) + aNonceWordG;
            aOrbiterG = (aWandererJ + RotL64(aCross, 5U)) + 10072004147620068599U;
            aOrbiterK = ((aWandererK + RotL64(aScatter, 21U)) + RotL64(aCarry, 39U)) + 3424585039401897560U;
            aOrbiterD = ((aWandererI + RotL64(aCross, 23U)) + RotL64(aCarry, 23U)) + 8246760141625966321U;
            aOrbiterB = (aWandererG + RotL64(aIngress, 35U)) + 3655992860610853290U;
            aOrbiterI = (((aWandererH + RotL64(aScatter, 54U)) + 11154618022505863898U) + aOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordE;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 15629361991059709973U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 10842068502278489664U;
            aOrbiterH = RotL64((aOrbiterH * 17223002513104960799U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 5571312349016336686U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 589313823745748879U;
            aOrbiterE = RotL64((aOrbiterE * 1356685926549786027U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 13633457935771935260U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 12684602052812183096U;
            aOrbiterC = RotL64((aOrbiterC * 4689206269919806711U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 5711307583717354204U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 7181854170553728211U;
            aOrbiterF = RotL64((aOrbiterF * 9835601115561325911U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 1884620014396115821U) + aNonceWordB;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 1471516373272364262U;
            aOrbiterK = RotL64((aOrbiterK * 5126319375714848029U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 742739371092077733U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 8075893317715227838U;
            aOrbiterB = RotL64((aOrbiterB * 11208274111743259795U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 8179547722249281263U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 15305282712174742323U) ^ aOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7951986906055462929U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 1430543231751281079U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 14585341768267283387U;
            aOrbiterA = RotL64((aOrbiterA * 313213844964269133U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 8123889986027932297U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 2081696191347150910U) ^ aOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4869653441012615053U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 10166788886199265936U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 15927074835525735601U;
            aOrbiterD = RotL64((aOrbiterD * 6747650218540675523U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 6997764816848988590U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 826930775230515406U;
            aOrbiterI = RotL64((aOrbiterI * 9943232461538279601U), 53U);
            //
            aIngress = RotL64(aOrbiterD, 39U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 10U));
            aIngress = aIngress + (RotL64(aOrbiterI, 23U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 53U));
            aIngress = aIngress + RotL64(aOrbiterA, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aIngress, 43U) + aOrbiterF) + RotL64(aOrbiterJ, 29U));
            aWandererF = aWandererF + ((RotL64(aScatter, 23U) + aOrbiterF) + RotL64(aOrbiterK, 21U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 39U) + aOrbiterD) + RotL64(aOrbiterK, 56U)) + aWandererUpdateSaltC[((aIndex + 14U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 29U) + RotL64(aOrbiterE, 53U)) + aOrbiterD) + RotL64(aCarry, 29U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterA, 35U)) + aOrbiterH) + aNonceWordI);
            aWandererD = aWandererD + ((RotL64(aIngress, 37U) + aOrbiterJ) + RotL64(aOrbiterE, 27U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 4U) + aOrbiterC) + RotL64(aOrbiterG, 11U)) + aNonceWordC);
            aWandererC = aWandererC + (((RotL64(aCross, 53U) + RotL64(aOrbiterI, 39U)) + aOrbiterF) + aNonceWordF);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 41U) + aOrbiterK) + RotL64(aOrbiterA, 13U)) + aWandererUpdateSaltD[((aIndex + 26U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 19U) + RotL64(aOrbiterB, 24U)) + aOrbiterH) + RotL64(aCarry, 57U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 26U) + aOrbiterC) + RotL64(aOrbiterB, 43U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 26U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 37U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 39U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 21U));
            aCarry = aCarry + RotL64(aWandererJ, 47U);
            aCarry = aCarry + RotL64(aIngress, 34U);
            aCarry = aCarry ^ aNonceWordF;
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 17587U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17526U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21774U)) & S_BLOCK1], 53U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 18020U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 38U) ^ RotL64(aIngress, 11U)) + (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 51U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (aWandererB + RotL64(aPrevious, 41U)) + 17225673071833726819U;
            aOrbiterB = ((aWandererA + RotL64(aScatter, 46U)) + RotL64(aCarry, 27U)) + 10301458382103627331U;
            aOrbiterE = (aWandererC + RotL64(aIngress, 29U)) + 3960233050857362414U;
            aOrbiterI = (aWandererD + RotL64(aCross, 53U)) + 17768665685046605837U;
            aOrbiterG = (aWandererK + RotL64(aIngress, 43U)) + 14471018461213959767U;
            aOrbiterJ = ((aWandererF + RotL64(aCross, 19U)) + RotL64(aCarry, 13U)) + 10730597892721340453U;
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 60U)) + 14863394003122760542U) + aOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = ((aWandererE + RotL64(aScatter, 23U)) + 9948587274816688296U) + aOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = ((aWandererG + RotL64(aCross, 5U)) + 3573569431435100993U) + aNonceWordJ;
            aOrbiterA = ((aWandererI + RotL64(aIngress, 27U)) + 8153670675740450590U) + aNonceWordN;
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 37U)) + RotL64(aCarry, 23U)) + 16438856577722561424U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 15765587867581925041U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 1082039522061775213U;
            aOrbiterE = RotL64((aOrbiterE * 17023740047246402641U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 4202521649260798876U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 15877659681260461141U;
            aOrbiterG = RotL64((aOrbiterG * 11369910758551088173U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 2551560426129646123U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 3005102326163906320U;
            aOrbiterJ = RotL64((aOrbiterJ * 4241583192662435107U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 1675501058857208089U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 12774812270956702043U;
            aOrbiterH = RotL64((aOrbiterH * 5488437008504905105U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 1044886020922563597U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 4857445127457225171U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13223560654459705259U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 11548725551787560962U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 2434677823189765161U;
            aOrbiterK = RotL64((aOrbiterK * 4283026044563670969U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 9606875320524736294U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 13732615866277657704U) ^ aOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3905528919281629775U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 13921743663803299567U) + aOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 13350829301153929899U) ^ aNonceWordB;
            aOrbiterF = RotL64((aOrbiterF * 11858642286713079795U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 9473349030551400156U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 7446792050826434742U;
            aOrbiterC = RotL64((aOrbiterC * 6619682184124713031U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 17970527747978977453U) + aOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 2326714817603921480U;
            aOrbiterB = RotL64((aOrbiterB * 14581676978186226887U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 7875511075130474136U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 17225673071833726819U;
            aOrbiterI = RotL64((aOrbiterI * 1196024136909896027U), 23U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterD, 3U);
            aIngress = aIngress + (RotL64(aOrbiterE, 37U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterC, 60U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 11U));
            aIngress = aIngress + RotL64(aOrbiterB, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterK, 41U)) + aOrbiterE);
            aWandererC = aWandererC ^ (((RotL64(aCross, 19U) + aOrbiterC) + RotL64(aOrbiterB, 47U)) + aWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 5U) + aOrbiterG) + RotL64(aOrbiterA, 23U)) + RotL64(aCarry, 43U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 40U) + aOrbiterK) + RotL64(aOrbiterG, 11U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterG, 50U)) + aOrbiterB);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 13U) + aOrbiterI) + RotL64(aOrbiterF, 53U)) + aWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 51U) + RotL64(aOrbiterH, 5U)) + aOrbiterI) + RotL64(aCarry, 5U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterG, 13U)) + aOrbiterJ) + aNonceWordM);
            aWandererA = aWandererA + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterF, 21U)) + aOrbiterD) + aNonceWordI);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 28U) + aOrbiterD) + RotL64(aOrbiterC, 18U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 21U) + aOrbiterH) + RotL64(aOrbiterF, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 60U) ^ aWandererB);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + (RotL64(aWandererE, 53U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererA, 13U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererJ, 36U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererG, 19U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ aNonceWordE;
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 27246U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23634U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25365U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25956U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 6U) + RotL64(aIngress, 37U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCross, 21U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererA + RotL64(aScatter, 19U)) + 77518479758428414U) + aOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = (aWandererG + RotL64(aIngress, 52U)) + 4832061802166300011U;
            aOrbiterG = (aWandererH + RotL64(aCross, 35U)) + 11695291171006574112U;
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 27U)) + RotL64(aCarry, 27U)) + 7467412817843260094U;
            aOrbiterK = ((aWandererI + RotL64(aIngress, 11U)) + 17801484124471154757U) + aNonceWordK;
            aOrbiterI = ((aWandererJ + RotL64(aCross, 44U)) + RotL64(aCarry, 19U)) + 5555455638503958639U;
            aOrbiterE = (aWandererK + RotL64(aPrevious, 39U)) + 5669470540733721606U;
            aOrbiterF = (aWandererF + RotL64(aScatter, 47U)) + 3042388456327784163U;
            aOrbiterA = ((aWandererE + RotL64(aCross, 23U)) + 2236734925228156691U) + aNonceWordN;
            aOrbiterD = (aWandererC + RotL64(aPrevious, 21U)) + 14459720401528685450U;
            aOrbiterH = (((aWandererD + RotL64(aIngress, 13U)) + RotL64(aCarry, 5U)) + 4814967631216658856U) + aOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 16950679344449075945U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 6262238639302011050U;
            aOrbiterG = RotL64((aOrbiterG * 9942659897425088183U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 3522256359074996724U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 12524717897707074242U;
            aOrbiterI = RotL64((aOrbiterI * 6787771338063891989U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 13891759914865623828U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 11910250571469028666U;
            aOrbiterF = RotL64((aOrbiterF * 12311343917878428995U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 2240189915640314069U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 5365912986308810837U;
            aOrbiterD = RotL64((aOrbiterD * 15133972552032469957U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 9323732721344489753U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 13087326560957916553U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14659491687401151733U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 16398238057564892809U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterC) ^ 11517870519285159224U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterJ = RotL64((aOrbiterJ * 1501848878469712681U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 7758285512254776734U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 17475149091906684720U;
            aOrbiterE = RotL64((aOrbiterE * 6015816725428299273U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 2051631493975035243U) + aOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 11684740065349595315U;
            aOrbiterA = RotL64((aOrbiterA * 10918975496337269197U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 10575473798991451167U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 8267005776169272822U;
            aOrbiterH = RotL64((aOrbiterH * 13166868678285963961U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 6249698995716039231U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 13808085811784323978U;
            aOrbiterC = RotL64((aOrbiterC * 3897731011582061983U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 2739364646624876985U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 77518479758428414U;
            aOrbiterK = RotL64((aOrbiterK * 6977724811175035551U), 27U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterI, 23U);
            aIngress = aIngress + (RotL64(aOrbiterF, 41U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 46U));
            aIngress = aIngress + (RotL64(aOrbiterD, 27U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 21U));
            aIngress = aIngress + RotL64(aOrbiterK, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 5U) + aOrbiterI) + RotL64(aOrbiterJ, 13U));
            aWandererE = aWandererE + ((RotL64(aCross, 58U) + RotL64(aOrbiterI, 35U)) + aOrbiterC);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterJ, 27U)) + aOrbiterK) + aNonceWordB);
            aWandererI = aWandererI + ((RotL64(aIngress, 41U) + aOrbiterG) + RotL64(aOrbiterK, 48U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterC, 19U)) + aOrbiterH);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 56U) + aOrbiterF) + RotL64(aOrbiterA, 21U)) + RotL64(aCarry, 3U)) + aWandererUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 23U) + aOrbiterF) + RotL64(aOrbiterK, 3U));
            aWandererK = aWandererK + (((RotL64(aIngress, 19U) + RotL64(aOrbiterK, 39U)) + aOrbiterB) + aNonceWordC);
            aWandererH = aWandererH ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterB, 5U)) + aOrbiterI) + aWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 35U) + RotL64(aOrbiterK, 29U)) + aOrbiterE) + RotL64(aCarry, 41U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 43U) + aOrbiterD) + RotL64(aOrbiterG, 60U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 21U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 6U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + (RotL64(aWandererC, 37U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererE, 53U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordM);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 31094U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31816U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28413U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30508U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 43U) ^ RotL64(aIngress, 57U)) + (RotL64(aCarry, 10U) + RotL64(aPrevious, 27U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (aWandererA + RotL64(aIngress, 60U)) + 3550722402315312207U;
            aOrbiterF = (aWandererF + RotL64(aCross, 35U)) + 16724184551669522754U;
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 21U)) + 981751330116773021U) + aOrbiterAssignSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterK = (aWandererB + RotL64(aScatter, 47U)) + 7891159229704944868U;
            aOrbiterJ = (aWandererH + RotL64(aPrevious, 27U)) + 13618396711464799841U;
            aOrbiterA = (((aWandererG + RotL64(aScatter, 41U)) + RotL64(aCarry, 3U)) + 5969291018449003648U) + aOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = (((aWandererC + RotL64(aCross, 39U)) + RotL64(aCarry, 47U)) + 14595540413313640042U) + aNonceWordE;
            aOrbiterI = ((aWandererD + RotL64(aIngress, 3U)) + RotL64(aCarry, 23U)) + 3287990436916111762U;
            aOrbiterG = (aWandererK + RotL64(aPrevious, 11U)) + 12534369400200483704U;
            aOrbiterB = (aWandererJ + RotL64(aCross, 6U)) + 2277312067930392274U;
            aOrbiterD = (aWandererI + RotL64(aScatter, 37U)) + 10026320559261334353U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 11258082063135659551U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 1445958517675746990U;
            aOrbiterH = RotL64((aOrbiterH * 10062265337488757971U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 1011298251290970844U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 6487834862470043744U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15477913837027179675U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 9966279022928268335U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 10285993486057704393U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15965714363201157535U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 16005362468813966136U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 223843444699390781U;
            aOrbiterE = RotL64((aOrbiterE * 665392038954573081U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 18178876294968532775U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 12490136112181806806U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16380841616662993709U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 8775696166557913635U) + aNonceWordC;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 16464340319444310842U;
            aOrbiterG = RotL64((aOrbiterG * 18111632334728200721U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 6296039992673546227U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 7152939277656436037U;
            aOrbiterB = RotL64((aOrbiterB * 15183918431501487319U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 14066791413416223271U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 5026743227399908016U;
            aOrbiterD = RotL64((aOrbiterD * 5891343232759075675U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 12923870516588764609U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 2509970166609982397U;
            aOrbiterC = RotL64((aOrbiterC * 10708677957633925007U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 15155802288437422950U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 15615656627428205711U;
            aOrbiterF = RotL64((aOrbiterF * 6199439196177598589U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 17233751123865498186U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 3550722402315312207U;
            aOrbiterK = RotL64((aOrbiterK * 2247546626523919155U), 35U);
            //
            aIngress = RotL64(aOrbiterE, 29U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterG, 46U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 11U));
            aIngress = aIngress + (RotL64(aOrbiterK, 51U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterJ, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aScatter, 53U) + RotL64(aOrbiterI, 44U)) + aOrbiterG) + RotL64(aCarry, 29U)) + aWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 3U) + aOrbiterH) + RotL64(aOrbiterD, 53U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterB, 39U)) + aOrbiterG);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 60U) + RotL64(aOrbiterK, 5U)) + aOrbiterE);
            aWandererB = aWandererB + ((((RotL64(aCross, 41U) + aOrbiterF) + RotL64(aOrbiterJ, 3U)) + RotL64(aCarry, 19U)) + aWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterH, 23U)) + aOrbiterG) + aNonceWordN);
            aWandererA = aWandererA + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterG, 57U)) + aOrbiterJ);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 37U) + RotL64(aOrbiterJ, 47U)) + aOrbiterI) + aNonceWordA);
            aWandererK = aWandererK + ((RotL64(aCross, 23U) + RotL64(aOrbiterG, 21U)) + aOrbiterA);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 50U) + RotL64(aOrbiterK, 19U)) + aOrbiterH);
            aWandererE = aWandererE + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterF, 34U)) + aOrbiterC) + aNonceWordI);
            //
            aCarry = aCarry + (RotL64(aWandererI, 28U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererA, 21U) ^ aWandererC);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + (RotL64(aWandererH, 6U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererF, 3U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordP);
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

void TwistExpander_Golf_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xD1AB7C272FFA2811ULL + 0xAED8362DE0858D08ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xD280C78200FC3953ULL + 0x807F04F7C6EEC0A0ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xE2B3F4BC512FEBA5ULL + 0xA5E786C1C003143FULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xDE08B433E54892CDULL + 0x97ECC80F49A1FBEAULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xA7E80156A38B08F1ULL + 0xADD36A8BD29C1C08ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xF594CE71F860619DULL + 0x9DAC24135E6CB086ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xCFCE4C58B89B3C13ULL + 0xF92AD6D66FFB4208ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xEEA54D18FC01346FULL + 0xA1100F805B3F18E9ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xD9E3D67FA25388BBULL + 0xD37B5652DD756AF8ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xD49FD62EA8C60489ULL + 0xA92E4262FC7F87CDULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xCD8F2A029F303511ULL + 0xF0514EC688575270ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x8ECD9F878F74A509ULL + 0xFFF767CB694E29FAULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xFA425080F32D64D3ULL + 0xBE7DBCA301907F73ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x94FFAFF218104779ULL + 0x84B726CB6A62ECBEULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xF27D4458E9305109ULL + 0xA292FD90ACAA6EF5ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xFB0FD7E78E4734B7ULL + 0xCF065E0A4D1A15E0ULL);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 7338U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7955U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 1163U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 7271U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 21U) + RotL64(aCross, 40U)) + (RotL64(aIngress, 3U) ^ RotL64(aCarry, 53U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = ((aWandererI + RotL64(aIngress, 54U)) + RotL64(aCarry, 53U)) + 2101601659597850213U;
            aOrbiterK = ((aWandererE + RotL64(aScatter, 11U)) + RotL64(aCarry, 39U)) + 2759794072560720121U;
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 41U)) + 9443562552411269339U) + aNonceWordE;
            aOrbiterF = (aWandererJ + RotL64(aCross, 3U)) + 10801360546699857975U;
            aOrbiterC = (((aWandererA + RotL64(aPrevious, 58U)) + RotL64(aCarry, 27U)) + 8020716394829332019U) + aNonceWordM;
            aOrbiterI = ((aWandererD + RotL64(aIngress, 27U)) + 1021894212367773801U) + aOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = (aWandererB + RotL64(aCross, 35U)) + 13346855534622490176U;
            aOrbiterA = (aWandererC + RotL64(aScatter, 19U)) + 16359309548462953836U;
            aOrbiterB = ((aWandererK + RotL64(aCross, 23U)) + 12642446944680783519U) + aOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 8197424982767553380U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 14346334610901859094U;
            aOrbiterH = RotL64((aOrbiterH * 16982899923227935679U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 14171304260534233539U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 334531601308283605U;
            aOrbiterI = RotL64((aOrbiterI * 5012968232749075075U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 10707856298471572695U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 18364775750091914766U;
            aOrbiterA = RotL64((aOrbiterA * 15735143943129143265U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 8531394793118363836U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 15352876929406908882U;
            aOrbiterB = RotL64((aOrbiterB * 475199047053777179U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 567682016232278157U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 2068146551757663119U;
            aOrbiterG = RotL64((aOrbiterG * 1557877740957797555U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 7776122587613256525U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 16430938890724272256U;
            aOrbiterF = RotL64((aOrbiterF * 4540270493783593257U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 11912000645055436094U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 16800749242578741498U;
            aOrbiterJ = RotL64((aOrbiterJ * 17804584625034241737U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 5909199180260499150U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterA) ^ 5751089915336865588U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterK = RotL64((aOrbiterK * 15376689503142397927U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 3478216857728853008U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 18007567146937338241U) ^ aOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6620498877303917855U), 37U);
            //
            aIngress = RotL64(aOrbiterH, 18U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterI, 47U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterC, 35U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 51U));
            aIngress = aIngress + RotL64(aOrbiterF, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aCross, 60U) + aOrbiterK) + RotL64(aOrbiterI, 35U)) + aNonceWordP) + aWandererUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((((RotL64(aScatter, 3U) + aOrbiterJ) + RotL64(aOrbiterB, 18U)) + aNonceWordJ) + aWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aIngress, 53U) + aOrbiterK) + RotL64(aOrbiterJ, 57U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterA, 27U)) + aOrbiterI) + aNonceWordF);
            aWandererD = aWandererD + ((RotL64(aCross, 11U) + aOrbiterH) + RotL64(aOrbiterC, 51U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterG, 12U));
            aWandererC = aWandererC + (((RotL64(aIngress, 47U) + RotL64(aOrbiterF, 23U)) + aOrbiterH) + RotL64(aCarry, 41U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 39U) + aOrbiterF) + RotL64(aOrbiterI, 43U));
            aWandererI = aWandererI + (((RotL64(aScatter, 34U) + RotL64(aOrbiterC, 47U)) + aOrbiterB) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 51U));
            aCarry = aCarry + (RotL64(aWandererI, 48U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererF, 23U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordH);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 11632U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((aIndex + 10566U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 10687U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 11604U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 11U) + RotL64(aIngress, 29U)) + (RotL64(aCarry, 44U) ^ RotL64(aPrevious, 57U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 27U)) + RotL64(aCarry, 3U)) + 6361545377408870615U;
            aOrbiterC = (((aWandererI + RotL64(aCross, 34U)) + 2967245486744774933U) + aOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1]) + aNonceWordC;
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 51U)) + 3836634268482850139U) + aNonceWordJ;
            aOrbiterI = ((aWandererE + RotL64(aIngress, 13U)) + RotL64(aCarry, 53U)) + 7691642115360086297U;
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 47U)) + 16479280384178279281U) + aNonceWordG;
            aOrbiterA = (aWandererH + RotL64(aIngress, 58U)) + 2901468732552539249U;
            aOrbiterK = ((aWandererB + RotL64(aCross, 19U)) + RotL64(aCarry, 29U)) + 2600353867755647475U;
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 23U)) + 5666596904781510956U) + aOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = (aWandererA + RotL64(aScatter, 3U)) + 16108791609267427553U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 8389926875737312112U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 1689501721163024426U) ^ aOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6517194895779049139U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 11721701506949917719U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 3963842745030140473U) ^ aNonceWordL;
            aOrbiterE = RotL64((aOrbiterE * 6692473494944919373U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 8510538243472109368U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 18281865214102080387U;
            aOrbiterK = RotL64((aOrbiterK * 1351546966368884609U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 2259725140963665123U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 11652011949557979650U) ^ aNonceWordA;
            aOrbiterD = RotL64((aOrbiterD * 11260100762113295037U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 1116085424226174473U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 4725260319270802912U;
            aOrbiterF = RotL64((aOrbiterF * 4697109059565450269U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 7348945429843437036U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 1249234309180653260U;
            aOrbiterB = RotL64((aOrbiterB * 3136745255820405881U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 12463505532573389603U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 2304125977906510386U;
            aOrbiterI = RotL64((aOrbiterI * 9960816714791454421U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 2178037443783425551U) + aOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 11712110130079307683U;
            aOrbiterA = RotL64((aOrbiterA * 9797864956200779505U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 10703510612147312252U) + aOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = (((aOrbiterC ^ aOrbiterF) ^ 18155460326242413483U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterC = RotL64((aOrbiterC * 6903953708987478723U), 5U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterF, 41U);
            aIngress = aIngress + (RotL64(aOrbiterA, 10U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + (RotL64(aOrbiterK, 27U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterI, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 57U) + aOrbiterJ) + RotL64(aOrbiterA, 4U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 48U) + RotL64(aOrbiterJ, 13U)) + aOrbiterF);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterJ, 53U)) + aOrbiterI);
            aWandererD = aWandererD + ((RotL64(aScatter, 53U) + aOrbiterA) + RotL64(aOrbiterD, 37U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterI, 48U)) + aOrbiterD);
            aWandererH = aWandererH + (((RotL64(aIngress, 19U) + aOrbiterA) + RotL64(aOrbiterK, 29U)) + RotL64(aCarry, 43U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterD, 57U)) + aOrbiterB);
            aWandererF = aWandererF + (((((RotL64(aScatter, 44U) + RotL64(aOrbiterC, 19U)) + aOrbiterK) + RotL64(aCarry, 29U)) + aNonceWordE) + aWandererUpdateSaltA[((aIndex + 4U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((((RotL64(aIngress, 23U) + aOrbiterI) + RotL64(aOrbiterE, 43U)) + aNonceWordN) + aWandererUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 14U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererB, 23U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ aNonceWordI;
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 20693U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneA[((aIndex + 24268U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 21460U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 20815U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aPrevious, 52U)) + (RotL64(aCarry, 35U) + RotL64(aIngress, 3U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 60U)) + 6342299552323486695U) + aOrbiterAssignSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = (((aWandererK + RotL64(aCross, 47U)) + 12692748514781367538U) + aOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1]) + aNonceWordM;
            aOrbiterC = (aWandererG + RotL64(aScatter, 27U)) + 8202639945493229155U;
            aOrbiterK = (aWandererH + RotL64(aIngress, 43U)) + 4439975701793231639U;
            aOrbiterF = ((aWandererB + RotL64(aScatter, 39U)) + RotL64(aCarry, 3U)) + 16774235182859553759U;
            aOrbiterE = (aWandererA + RotL64(aIngress, 23U)) + 8764155413335405667U;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 19U)) + RotL64(aCarry, 43U)) + 7167848811974967685U;
            aOrbiterB = ((aWandererF + RotL64(aCross, 4U)) + RotL64(aCarry, 11U)) + 16768278912125334220U;
            aOrbiterI = (aWandererJ + RotL64(aScatter, 11U)) + 9090838954826296201U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 7644075729758006298U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 17326182797908071215U;
            aOrbiterC = RotL64((aOrbiterC * 2408330168749256075U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 16158809721888137555U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 8029938783858263694U;
            aOrbiterH = RotL64((aOrbiterH * 12628072435324195483U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 8716553521415553404U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 7012599977009208840U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8775355876188948851U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 13250558696578541499U) + aOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 13705957059101025396U) ^ aNonceWordL;
            aOrbiterA = RotL64((aOrbiterA * 16889495686487056367U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 2796775206291902461U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 13741676263512390669U;
            aOrbiterF = RotL64((aOrbiterF * 10455782033465595947U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 1691908360612389252U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 4114939415206031540U;
            aOrbiterE = RotL64((aOrbiterE * 2797401802892718297U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 2374911514440738727U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 12377616933668803091U;
            aOrbiterG = RotL64((aOrbiterG * 2505164835116651215U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 681094033415259645U) + aNonceWordO;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 13841322124900463362U;
            aOrbiterB = RotL64((aOrbiterB * 4210414203856902329U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 18082983557580381338U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 15731122225678626778U;
            aOrbiterI = RotL64((aOrbiterI * 7785999919955613789U), 47U);
            //
            aIngress = RotL64(aOrbiterF, 36U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 13U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 39U));
            aIngress = aIngress + RotL64(aOrbiterH, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 24U) + RotL64(aOrbiterC, 35U)) + aOrbiterI);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 5U) + aOrbiterC) + RotL64(aOrbiterH, 29U)) + aNonceWordP) + aWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterF, 46U)) + aOrbiterE);
            aWandererI = aWandererI + (((RotL64(aScatter, 57U) + aOrbiterB) + RotL64(aOrbiterE, 13U)) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterK, 39U)) + aOrbiterA);
            aWandererK = aWandererK + (((RotL64(aIngress, 43U) + aOrbiterF) + RotL64(aOrbiterG, 53U)) + RotL64(aCarry, 5U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 47U) + aOrbiterF) + RotL64(aOrbiterA, 6U)) + aNonceWordC);
            aWandererB = aWandererB + (((RotL64(aScatter, 35U) + aOrbiterB) + RotL64(aOrbiterH, 57U)) + aWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 18U) + RotL64(aOrbiterC, 21U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererK);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 60U));
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererH, 47U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordC);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 26548U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 26151U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 29794U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneD[((aIndex + 31164U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aIngress, 53U)) ^ (RotL64(aCarry, 38U) + RotL64(aPrevious, 19U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((aWandererK + RotL64(aCross, 11U)) + RotL64(aCarry, 51U)) + 5568146815535263910U;
            aOrbiterF = (((aWandererD + RotL64(aScatter, 19U)) + RotL64(aCarry, 41U)) + 7736084960873834666U) + aOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = (aWandererA + RotL64(aIngress, 5U)) + 1336413621817562093U;
            aOrbiterH = (((aWandererB + RotL64(aPrevious, 50U)) + RotL64(aCarry, 27U)) + 5218462026934984692U) + aNonceWordM;
            aOrbiterI = (((aWandererF + RotL64(aCross, 37U)) + 7048890985969555935U) + aOrbiterAssignSaltF[((aIndex + 11U)) & S_SALT1]) + aNonceWordD;
            aOrbiterC = (aWandererI + RotL64(aIngress, 27U)) + 13415955213864702118U;
            aOrbiterA = (aWandererC + RotL64(aScatter, 57U)) + 5657023257021528548U;
            aOrbiterB = (aWandererH + RotL64(aPrevious, 23U)) + 14338310943137497116U;
            aOrbiterE = (aWandererG + RotL64(aScatter, 46U)) + 12305161641833950473U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 14514226578370459131U) + aOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 12692904083266024340U;
            aOrbiterG = RotL64((aOrbiterG * 14800805065279908839U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 11012959130001327964U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 7106471380403489078U;
            aOrbiterI = RotL64((aOrbiterI * 515626559384817223U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 3718101961355280891U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 13364192077222322664U;
            aOrbiterA = RotL64((aOrbiterA * 1411328915372590283U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 6720867800318913440U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 14497243926965866546U) ^ aOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13595058589060114653U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 5789056168233262435U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 14438482587495779937U;
            aOrbiterH = RotL64((aOrbiterH * 10593535547917767263U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 313917798940179945U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 15241845511889502917U) ^ aNonceWordN;
            aOrbiterC = RotL64((aOrbiterC * 16483477103771326107U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 3591957424821693032U) + aNonceWordO;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 1559050939014453558U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17933346117866604725U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 15340590914441451383U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 5538037287390050110U;
            aOrbiterE = RotL64((aOrbiterE * 4082576643144951473U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 4151270491894969214U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 263593701314144898U;
            aOrbiterF = RotL64((aOrbiterF * 10372046955804512457U), 35U);
            //
            aIngress = RotL64(aOrbiterD, 48U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterB, 5U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterA, 13U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterI, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aPrevious, 6U) + RotL64(aOrbiterA, 10U)) + aOrbiterI) + aNonceWordE);
            aWandererG = aWandererG ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterG, 47U)) + aOrbiterB) + aWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 47U) + RotL64(aOrbiterE, 37U)) + aOrbiterB);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 19U) + aOrbiterD) + RotL64(aOrbiterF, 51U));
            aWandererC = aWandererC + (((RotL64(aCross, 29U) + RotL64(aOrbiterA, 3U)) + aOrbiterB) + RotL64(aCarry, 41U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 53U) + aOrbiterF) + RotL64(aOrbiterA, 43U)) + aWandererUpdateSaltD[((aIndex + 6U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 39U) + aOrbiterD) + RotL64(aOrbiterB, 18U)) + aNonceWordB);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 58U) + aOrbiterH) + RotL64(aOrbiterC, 57U));
            aWandererA = aWandererA + (((RotL64(aIngress, 11U) + aOrbiterC) + RotL64(aOrbiterD, 23U)) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererI);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 54U));
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererK, 51U);
            aCarry = aCarry + RotL64(aIngress, 18U);
            aCarry = aCarry ^ aNonceWordE;
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

void TwistExpander_Golf_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterJ = 0;
    std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xBFCAEBDCEDBDF323ULL + 0xEFAA11380FF7680CULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xEE05106DF484A177ULL + 0x8A2314F08908E0A5ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x92FE87EBAED800E1ULL + 0x9CD931AAFE1D35ADULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x9638E948EBB48E6BULL + 0x890AEB6101847034ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x9B0F7E952F48954FULL + 0xC904A232FB143AC2ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xE232DBD846CD5CE7ULL + 0xCF1505BE1A4E2FDAULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xB8B30D5048018539ULL + 0xCFEF02A6AADA2775ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xB76C6E15CAB372ADULL + 0xBF93123141925F7FULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x81B8DD1ACAED6D19ULL + 0xD3F321AC5502E9D0ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x86F2A3EEC6BD854DULL + 0xE39CF1E56214D910ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xBFDD970069250411ULL + 0xAE14AACE6EE9B519ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xECE6A962CBD1AE85ULL + 0xFFF6752A38F914F7ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xB034E73D401524E1ULL + 0xF3E516220F95D47AULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xD8E54EBBCA4DD6B1ULL + 0xDACFFE4ED30F1A5EULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xE1009F26D3519053ULL + 0xBAE8F7736E88C745ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xE8DBD8062296E455ULL + 0x8855D96D015CE401ULL);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 7193U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneC[((aIndex + 3573U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 6856U)) & S_BLOCK1], 10U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 4412U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 11U) ^ RotL64(aPrevious, 39U)) + (RotL64(aIngress, 52U) ^ RotL64(aCross, 23U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((((aWandererB + RotL64(aScatter, 36U)) + RotL64(aCarry, 19U)) + 2558105147674438050U) + aOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordP;
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 57U)) + 15856662514774702561U) + aOrbiterAssignSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = ((aWandererK + RotL64(aIngress, 21U)) + RotL64(aCarry, 41U)) + 13346869226246584582U;
            aOrbiterJ = ((aWandererF + RotL64(aCross, 47U)) + RotL64(aCarry, 57U)) + 7632111846116243973U;
            aOrbiterB = (aWandererI + RotL64(aScatter, 11U)) + 2102101361626976279U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 5605968705067851563U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 6842483186584326681U;
            aOrbiterH = RotL64((aOrbiterH * 11344798544990575365U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 5559797213819425064U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 12422313931331576759U) ^ aOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7399849122565913401U), 11U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterH) + 2751024420047872601U) + aOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1]) + aNonceWordD;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 11031320239359798610U) ^ aOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8607639453141148025U), 27U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterK) + 14366375309473793217U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordC;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 11971479429768505316U;
            aOrbiterE = RotL64((aOrbiterE * 10063001532313098203U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 3947595951884469542U) + aNonceWordJ;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 17882767922372770896U;
            aOrbiterB = RotL64((aOrbiterB * 3361906348965810211U), 3U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterE, 29U);
            aIngress = aIngress + (RotL64(aOrbiterK, 19U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 35U) + aOrbiterK) + RotL64(aOrbiterJ, 39U));
            aWandererK = aWandererK + ((((RotL64(aPrevious, 5U) + aOrbiterB) + RotL64(aOrbiterE, 29U)) + RotL64(aCarry, 5U)) + aWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 51U) + aOrbiterB) + RotL64(aOrbiterH, 57U));
            aWandererB = aWandererB + ((((RotL64(aIngress, 21U) + RotL64(aOrbiterJ, 48U)) + aOrbiterE) + RotL64(aCarry, 29U)) + aNonceWordK);
            aWandererF = aWandererF ^ ((((RotL64(aScatter, 60U) + RotL64(aOrbiterH, 5U)) + aOrbiterE) + aNonceWordF) + aWandererUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererK);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 37U));
            aCarry = aCarry + RotL64(aWandererF, 13U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ aNonceWordH;
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 13775U)) & S_BLOCK1], 12U) ^ RotL64(aOperationLaneD[((aIndex + 11141U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 15660U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 13463U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 4U) ^ RotL64(aCarry, 39U)) + (RotL64(aIngress, 53U) ^ RotL64(aCross, 23U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((aWandererK + RotL64(aCross, 11U)) + RotL64(aCarry, 23U)) + 6361545377408870615U;
            aOrbiterF = ((aWandererH + RotL64(aIngress, 21U)) + RotL64(aCarry, 51U)) + 2967245486744774933U;
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 3U)) + 3836634268482850139U) + aOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = (((aWandererF + RotL64(aScatter, 57U)) + RotL64(aCarry, 35U)) + 7691642115360086297U) + aNonceWordC;
            aOrbiterJ = (((aWandererE + RotL64(aCross, 46U)) + 16479280384178279281U) + aOrbiterAssignSaltB[((aIndex + 27U)) & S_SALT1]) + aNonceWordN;
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 2901468732552539249U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 2600353867755647475U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1140827276372862433U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 5666596904781510956U) + aOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 16108791609267427553U;
            aOrbiterJ = RotL64((aOrbiterJ * 8904649663479834199U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 8389926875737312112U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 1689501721163024426U;
            aOrbiterD = RotL64((aOrbiterD * 6517194895779049139U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 11721701506949917719U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 3963842745030140473U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6692473494944919373U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 8510538243472109368U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterJ) ^ 18281865214102080387U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterG = RotL64((aOrbiterG * 1351546966368884609U), 57U);
            //
            aIngress = RotL64(aOrbiterF, 4U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + RotL64(aOrbiterE, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aCross, 60U) + aOrbiterG) + RotL64(aOrbiterE, 5U)) + RotL64(aCarry, 43U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 13U) + aOrbiterF) + RotL64(aOrbiterG, 58U)) + aWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aScatter, 37U) + RotL64(aOrbiterD, 21U)) + aOrbiterF);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 47U) + aOrbiterE) + RotL64(aOrbiterJ, 29U));
            aWandererE = aWandererE + (((((RotL64(aScatter, 21U) + aOrbiterG) + RotL64(aOrbiterD, 43U)) + RotL64(aCarry, 5U)) + aNonceWordL) + aWandererUpdateSaltD[((aIndex + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererE, 21U);
            aCarry = aCarry + RotL64(aIngress, 34U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordD);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 17743U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22656U)) & S_BLOCK1], 10U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 17853U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 23328U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 13U) + RotL64(aIngress, 27U)) + (RotL64(aCross, 53U) ^ RotL64(aPrevious, 40U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((aWandererC + RotL64(aScatter, 57U)) + RotL64(aCarry, 39U)) + 7075016829833562104U;
            aOrbiterK = (((aWandererF + RotL64(aCross, 21U)) + RotL64(aCarry, 3U)) + 8783765886115517036U) + aOrbiterAssignSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 13U)) + RotL64(aCarry, 23U)) + 2996723892384565829U;
            aOrbiterH = (((aWandererK + RotL64(aIngress, 44U)) + 9494134707342189476U) + aOrbiterAssignSaltC[((aIndex + 8U)) & S_SALT1]) + aNonceWordP;
            aOrbiterA = (aWandererH + RotL64(aPrevious, 5U)) + 5052642981395679904U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 8766787055127962238U) + aOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 4467211954388738079U;
            aOrbiterB = RotL64((aOrbiterB * 8599295330343804047U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 8030255604633658608U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 16962408063455702251U) ^ aNonceWordG;
            aOrbiterK = RotL64((aOrbiterK * 11171737929747471631U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 3768222186567699076U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 14930990410207899871U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10930005786146268241U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 14179761938395502502U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 1879084742719898108U) ^ aNonceWordF;
            aOrbiterH = RotL64((aOrbiterH * 16783034788172670121U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 5535012408925981515U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = (((aOrbiterA ^ aOrbiterK) ^ 12792553516710295939U) ^ aOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterA = RotL64((aOrbiterA * 8577530993755159329U), 39U);
            //
            aIngress = RotL64(aOrbiterH, 21U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterA, 11U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterB, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aIngress, 29U) + aOrbiterA) + RotL64(aOrbiterH, 19U)) + aWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aScatter, 48U) + aOrbiterH) + RotL64(aOrbiterB, 11U)) + RotL64(aCarry, 37U)) + aNonceWordH);
            aWandererK = aWandererK ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterK, 47U)) + aOrbiterB) + aNonceWordK);
            aWandererA = aWandererA + (((((RotL64(aPrevious, 21U) + aOrbiterA) + RotL64(aOrbiterB, 37U)) + RotL64(aCarry, 23U)) + aNonceWordL) + aWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 3U) + aOrbiterK) + RotL64(aOrbiterF, 58U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 6U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererA, 57U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordM);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 27367U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((aIndex + 29068U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 29553U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((aIndex + 31186U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aPrevious, 23U)) ^ (RotL64(aCross, 57U) ^ RotL64(aIngress, 10U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((((aWandererF + RotL64(aIngress, 10U)) + RotL64(aCarry, 43U)) + 4980738603982643969U) + aOrbiterAssignSaltD[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordC;
            aOrbiterB = (((aWandererK + RotL64(aScatter, 37U)) + RotL64(aCarry, 19U)) + 17660278413018470020U) + aNonceWordP;
            aOrbiterF = ((aWandererA + RotL64(aCross, 51U)) + RotL64(aCarry, 57U)) + 17598114429859543466U;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 27U)) + 10993929335279994739U) + aOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = (aWandererG + RotL64(aCross, 19U)) + 17967203122976322481U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 1872290205549034384U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 16607778671782810797U;
            aOrbiterF = RotL64((aOrbiterF * 340054507611349681U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 4895226930754394376U) + aOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = (((aOrbiterK ^ aOrbiterD) ^ 14960359005982301383U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterK = RotL64((aOrbiterK * 8546231310054433721U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 9921642352377700630U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 893281964367208693U) ^ aOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2345509157333444217U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 8232519988397858732U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 4433022122758913407U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 834240393225479419U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 12689609831247168353U) + aNonceWordD;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 404535388957472176U;
            aOrbiterG = RotL64((aOrbiterG * 14534020545479806593U), 57U);
            //
            aIngress = RotL64(aOrbiterK, 18U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterF, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aCross, 19U) + RotL64(aOrbiterG, 29U)) + aOrbiterK) + RotL64(aCarry, 39U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 10U) + aOrbiterD) + RotL64(aOrbiterG, 47U));
            aWandererA = aWandererA + (((RotL64(aScatter, 47U) + RotL64(aOrbiterK, 57U)) + aOrbiterD) + aWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterF, 11U)) + aOrbiterB) + aNonceWordM);
            aWandererG = aWandererG + (((((RotL64(aScatter, 57U) + aOrbiterF) + RotL64(aOrbiterD, 20U)) + RotL64(aCarry, 13U)) + aNonceWordF) + aWandererUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 58U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + RotL64(aWandererA, 27U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordN);
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

void TwistExpander_Golf_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xCC3AB597A29BC591ULL + 0xC69F4B1B1290B719ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x93F5F55619F2B8DFULL + 0xDB6D17BD87FC9E00ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xC17D9516E6FE82B7ULL + 0xF4B0A0038F1557F6ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xB0DCFDD761888069ULL + 0x9D60F41AB0922AD2ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xA7507F5AA7DB4201ULL + 0x9E454152B5F60A12ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xD7E843E942F99051ULL + 0xDD458C2A754F6A98ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x823DBD262D8E8CA5ULL + 0xE69A78830B8BEDF8ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xC75F529606DB0B81ULL + 0xE93810E95140266CULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xCBC60716FFC77411ULL + 0xBA6456E02A0144E2ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xB0F3E4B95DFF74F7ULL + 0xB87972A354221EAFULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xD96E22596C9C22C7ULL + 0xB8BEF8DF1538C1FBULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xBBA71C9EDE591C87ULL + 0xFBDC89EB7BD6CDE6ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x82A7B32C66855F2DULL + 0xE49B0B2CF88A7609ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x823C55A7D1394059ULL + 0x8F250395A8EC48F2ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xAE1F767E5346F805ULL + 0xA87D42D3BE5EC40AULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x804D0D9881966299ULL + 0x8FCC436B0F8E2A9BULL);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 4700U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneC[((aIndex + 2545U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 560U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 3956U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aPrevious, 53U)) ^ (RotL64(aIngress, 4U) ^ RotL64(aCarry, 21U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (aWandererC + RotL64(aScatter, 23U)) + 1457104756581596530U;
            aOrbiterJ = (aWandererB + RotL64(aCross, 29U)) + 6127240317844622874U;
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 3U)) + 16492290056044189421U) + aOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = ((aWandererE + RotL64(aIngress, 11U)) + RotL64(aCarry, 3U)) + 10963676850938416468U;
            aOrbiterH = ((aWandererG + RotL64(aScatter, 35U)) + 4872917367399752405U) + aNonceWordA;
            aOrbiterE = (((aWandererI + RotL64(aPrevious, 57U)) + RotL64(aCarry, 27U)) + 15218882377875616148U) + aOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = (((aWandererA + RotL64(aCross, 42U)) + RotL64(aCarry, 39U)) + 5934166612122118251U) + aNonceWordF;
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 14215280930872003003U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 11428034799044600979U;
            aOrbiterC = RotL64((aOrbiterC * 12162528943733976177U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 5453003654321728726U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 14273775120265649389U;
            aOrbiterH = RotL64((aOrbiterH * 5139018128323795309U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 328723770018440271U) + aNonceWordM;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 13032190719588211088U;
            aOrbiterE = RotL64((aOrbiterE * 13363368478932798315U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 2386881543033598494U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 1649501123340887116U) ^ aOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11148976582360499033U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 16462401546754210583U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 1510579201823042227U;
            aOrbiterD = RotL64((aOrbiterD * 16287912400104043275U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 6889066000014251983U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 11324594596597724357U) ^ aOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15344987814648586023U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 12237796033168436537U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 17306069670330000343U;
            aOrbiterJ = RotL64((aOrbiterJ * 3167451351403385259U), 35U);
            //
            aIngress = RotL64(aOrbiterE, 41U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterC, 51U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterH, 21U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterI, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aIngress, 54U) + RotL64(aOrbiterA, 41U)) + aOrbiterC) + RotL64(aCarry, 47U)) + aWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterI, 35U)) + aOrbiterA) + aNonceWordL);
            aWandererC = aWandererC + (((RotL64(aScatter, 47U) + aOrbiterJ) + RotL64(aOrbiterH, 3U)) + RotL64(aCarry, 35U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 35U) + aOrbiterD) + RotL64(aOrbiterE, 47U));
            aWandererE = aWandererE + (((RotL64(aIngress, 19U) + aOrbiterE) + RotL64(aOrbiterA, 13U)) + aNonceWordO);
            aWandererG = aWandererG ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterE, 22U)) + aOrbiterC);
            aWandererD = aWandererD + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterJ, 53U)) + aOrbiterI) + aWandererUpdateSaltE[((aIndex + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 34U));
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererC);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 53U));
            aCarry = aCarry + RotL64(aWandererA, 43U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ aNonceWordD;
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9983U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 12214U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 11213U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 12467U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 27U) + RotL64(aCarry, 52U)) + (RotL64(aCross, 13U) ^ RotL64(aIngress, 39U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererK + RotL64(aCross, 38U)) + RotL64(aCarry, 21U)) + 17074147006464019918U;
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 5U)) + RotL64(aCarry, 5U)) + 10559516626129419928U;
            aOrbiterH = (((aWandererB + RotL64(aIngress, 29U)) + 13280363679503946221U) + aOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordI;
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 53U)) + 17657115422132457413U) + aNonceWordK;
            aOrbiterJ = ((aWandererG + RotL64(aCross, 13U)) + 13325837013304973008U) + aOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = (aWandererF + RotL64(aIngress, 47U)) + 3059707750486106037U;
            aOrbiterG = ((aWandererD + RotL64(aScatter, 19U)) + RotL64(aCarry, 57U)) + 4529045702503050852U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 10726578475550904292U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 14832537837996659885U;
            aOrbiterH = RotL64((aOrbiterH * 808060368961520519U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 220094417441809246U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 15343130035105342194U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7984652435043810845U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 16592263353426409884U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 15649290906447931918U) ^ aOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8405875177836650731U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 11437410545843708269U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 5859769136073011444U;
            aOrbiterF = RotL64((aOrbiterF * 1065016088086441107U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 15188064100307340341U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 4367466521843260049U;
            aOrbiterJ = RotL64((aOrbiterJ * 15916715854192820923U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 8482617283860566845U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 2585745804937342972U;
            aOrbiterE = RotL64((aOrbiterE * 8267269625632139809U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 1687641344403425541U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 13667916445979421400U) ^ aNonceWordB;
            aOrbiterG = RotL64((aOrbiterG * 8191322670355590027U), 11U);
            //
            aIngress = RotL64(aOrbiterJ, 39U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 53U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 13U));
            aIngress = aIngress + RotL64(aOrbiterF, 46U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 48U) + RotL64(aOrbiterK, 3U)) + aOrbiterE) + aNonceWordF);
            aWandererC = aWandererC + ((RotL64(aCross, 3U) + aOrbiterD) + RotL64(aOrbiterF, 29U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterD, 18U)) + aOrbiterJ) + aNonceWordE);
            aWandererB = aWandererB + ((((RotL64(aScatter, 29U) + aOrbiterH) + RotL64(aOrbiterD, 47U)) + RotL64(aCarry, 29U)) + aWandererUpdateSaltD[((aIndex + 28U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 23U) + aOrbiterE) + RotL64(aOrbiterJ, 41U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 57U) + aOrbiterH) + RotL64(aOrbiterK, 57U)) + RotL64(aCarry, 41U)) + aWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterG, 11U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 12U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererC);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 51U));
            aCarry = aCarry + RotL64(aWandererD, 29U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordI);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 22167U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18981U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 21776U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 19415U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 56U) + RotL64(aCarry, 27U)) ^ (RotL64(aPrevious, 13U) + RotL64(aCross, 43U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 43U)) + 13880995121909552664U;
            aOrbiterE = (aWandererG + RotL64(aIngress, 60U)) + 14534942818069300546U;
            aOrbiterI = ((((aWandererK + RotL64(aCross, 37U)) + RotL64(aCarry, 11U)) + 17745973100886007133U) + aOrbiterAssignSaltD[((aIndex + 26U)) & S_SALT1]) + aNonceWordD;
            aOrbiterB = (((aWandererB + RotL64(aScatter, 27U)) + RotL64(aCarry, 39U)) + 2249805580771946872U) + aNonceWordE;
            aOrbiterD = (((aWandererE + RotL64(aPrevious, 53U)) + RotL64(aCarry, 27U)) + 4460116116396439410U) + aOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = (aWandererD + RotL64(aCross, 21U)) + 3378683994078106878U;
            aOrbiterK = (aWandererI + RotL64(aIngress, 13U)) + 3992996501048809123U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 12057768808864451929U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 4115362079047921130U;
            aOrbiterI = RotL64((aOrbiterI * 12263015903331031345U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 15297384955502206698U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 17623548383481905636U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7487278217901483685U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 3559213898000162417U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 12311605719074507335U) ^ aNonceWordK;
            aOrbiterG = RotL64((aOrbiterG * 3982199462062847697U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 14807313864347885885U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 11222085523291581822U;
            aOrbiterB = RotL64((aOrbiterB * 12580941911587215653U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 916681229436292462U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 2441350114032314686U;
            aOrbiterD = RotL64((aOrbiterD * 7336079498999018067U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 7361470539894653271U) + aOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 12153585147213579808U;
            aOrbiterH = RotL64((aOrbiterH * 3040327545467672961U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 13566300726101613579U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 14875254144748509128U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13699179902908972403U), 11U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterG, 51U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 13U));
            aIngress = aIngress + (RotL64(aOrbiterD, 21U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterB, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterK, 3U)) + aOrbiterH) + aWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 43U) + RotL64(aOrbiterK, 43U)) + aOrbiterI) + RotL64(aCarry, 29U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 51U) + aOrbiterB) + RotL64(aOrbiterE, 58U));
            aWandererD = aWandererD + (((RotL64(aScatter, 21U) + aOrbiterE) + RotL64(aOrbiterK, 29U)) + RotL64(aCarry, 43U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 4U) + RotL64(aOrbiterB, 13U)) + aOrbiterG) + aWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 27U) + aOrbiterD) + RotL64(aOrbiterG, 23U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterI, 51U)) + aOrbiterB) + aNonceWordC);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 58U));
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererD);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + RotL64(aWandererI, 11U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordP);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 30638U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27869U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 29991U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((aIndex + 26271U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 21U) + RotL64(aCarry, 34U)) ^ (RotL64(aCross, 3U) + RotL64(aIngress, 47U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (aWandererK + RotL64(aScatter, 53U)) + 8506388683755208267U;
            aOrbiterE = (((aWandererI + RotL64(aPrevious, 37U)) + RotL64(aCarry, 43U)) + 2179323259055019735U) + aOrbiterAssignSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = ((aWandererE + RotL64(aCross, 20U)) + 3345902531140983016U) + aNonceWordP;
            aOrbiterH = (((aWandererF + RotL64(aIngress, 47U)) + RotL64(aCarry, 5U)) + 17456139311481306584U) + aOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = (aWandererH + RotL64(aPrevious, 29U)) + 14587864088462311164U;
            aOrbiterB = (((aWandererD + RotL64(aCross, 3U)) + RotL64(aCarry, 23U)) + 13178947246650647057U) + aNonceWordD;
            aOrbiterA = (aWandererA + RotL64(aScatter, 13U)) + 12866578138946916962U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 13098524333655118173U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 15451329483787541982U) ^ aNonceWordE;
            aOrbiterI = RotL64((aOrbiterI * 13580376920467431451U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 9494299579678389385U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 15581954810375490643U;
            aOrbiterB = RotL64((aOrbiterB * 13670002280188424825U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 4487042505730624892U) + aOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 2774455928791636186U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15847933919136777451U), 23U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterH) + 12435319582397755819U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordB;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 10077180055177766823U;
            aOrbiterJ = RotL64((aOrbiterJ * 3924363471701748703U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 10391963896910956455U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterB) ^ 6149237416725301794U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterC = RotL64((aOrbiterC * 10115917698918612823U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 15673402771629639978U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 14729117178956592426U;
            aOrbiterH = RotL64((aOrbiterH * 9070464269215820531U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 14492001279368870240U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 6278248084483259952U;
            aOrbiterA = RotL64((aOrbiterA * 16731228350971263873U), 13U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterE, 29U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterH, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((((RotL64(aCross, 6U) + RotL64(aOrbiterC, 29U)) + aOrbiterB) + aNonceWordC) + aWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aIngress, 37U) + RotL64(aOrbiterC, 57U)) + aOrbiterE) + RotL64(aCarry, 11U)) + aNonceWordK);
            aWandererD = aWandererD ^ ((((RotL64(aScatter, 57U) + RotL64(aOrbiterI, 47U)) + aOrbiterE) + aNonceWordM) + aWandererUpdateSaltB[((aIndex + 22U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterI, 5U)) + aOrbiterJ) + RotL64(aCarry, 41U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 27U) + aOrbiterI) + RotL64(aOrbiterH, 19U));
            aWandererH = aWandererH + ((RotL64(aCross, 13U) + aOrbiterH) + RotL64(aOrbiterE, 12U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterE, 39U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + (RotL64(aWandererK, 40U) ^ aWandererF);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 27U));
            aCarry = aCarry + RotL64(aWandererI, 3U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ aNonceWordE;
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

void TwistExpander_Golf_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterE = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xF69074C482845A1BULL + 0xA3C86FF13EA8E6A5ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xA8809B5B38F1B1EDULL + 0xAF9F161729A8F9DDULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xB9458EA05F20A1BBULL + 0x8E7EE62ED70C83CCULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xEAF51DFBEB635BB9ULL + 0xCB802C59E7BD6942ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xB825B35937788FE5ULL + 0xA6527E60FA6297A9ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xF976EBD6B5B82D75ULL + 0xC461527526ACCE39ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xBB980A1E70C21ED1ULL + 0xC8875F9A9A1CE31DULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xA90DE5FBE8B8E2FBULL + 0x9E25785A2A4E2472ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xA1993AFACA329FDFULL + 0x95566E3D3020FB18ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xE8D667F52519CCA3ULL + 0xA3477EF59E5E204CULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xFCCD0987A35EE569ULL + 0x8228775A61FF1C70ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xE2E6FBA2233FC5DDULL + 0xA8E784C5A8C6F81CULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xE1F0DE1256F350C5ULL + 0xBE0AF83451F590E7ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xB308D27E4D28A9CBULL + 0xFE714A262C0EBD03ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xCE7DC4C638D95B11ULL + 0xF669F72728CC076DULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xB3891B1C5AA0F765ULL + 0xB970249AC26FF7C1ULL);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 2004U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneC[((aIndex + 5645U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 7587U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 1867U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aPrevious, 19U)) ^ (RotL64(aIngress, 44U) + RotL64(aCross, 57U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (((aWandererK + RotL64(aIngress, 57U)) + RotL64(aCarry, 5U)) + 4384716820085860551U) + aOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 29U)) + 9715780315942116888U) + aOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = ((aWandererG + RotL64(aCross, 13U)) + 15963520052789178632U) + aNonceWordE;
            aOrbiterG = ((aWandererA + RotL64(aScatter, 51U)) + RotL64(aCarry, 35U)) + 14346700690686392938U;
            aOrbiterC = (aWandererJ + RotL64(aCross, 44U)) + 6005518012489966643U;
            aOrbiterI = (aWandererI + RotL64(aScatter, 5U)) + 2506732930310252119U;
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 21U)) + RotL64(aCarry, 57U)) + 16782163084851775826U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 823673076571076303U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 1634084509064077736U) ^ aOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1128407326773234517U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 1288134975466877686U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 2998220403162908444U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4321412662318298283U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 220430672180734911U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 10223923547068528867U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12577370238343872139U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 11696469696177647608U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 6545430420379636963U;
            aOrbiterE = RotL64((aOrbiterE * 8387163146257553773U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 79691451831797107U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 8971444023498649419U) ^ aNonceWordP;
            aOrbiterK = RotL64((aOrbiterK * 7148919880477390009U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 5624403902454498793U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 9468064161002030997U;
            aOrbiterG = RotL64((aOrbiterG * 8243560528100864595U), 57U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterG) + 4619361544913629805U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordN;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 12682446273369750704U;
            aOrbiterB = RotL64((aOrbiterB * 10879074713156075641U), 27U);
            //
            aIngress = RotL64(aOrbiterE, 27U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterC, 12U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterK, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterB, 29U)) + aOrbiterC) + aNonceWordG);
            aWandererI = aWandererI ^ ((((RotL64(aCross, 26U) + aOrbiterE) + RotL64(aOrbiterC, 19U)) + aNonceWordI) + aWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 19U) + aOrbiterK) + RotL64(aOrbiterF, 43U)) + aNonceWordB);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 53U) + aOrbiterB) + RotL64(aOrbiterI, 35U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 13U) + RotL64(aOrbiterK, 51U)) + aOrbiterE) + RotL64(aCarry, 53U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 5U) + aOrbiterE) + RotL64(aOrbiterG, 60U));
            aWandererG = aWandererG + ((((RotL64(aCross, 41U) + aOrbiterF) + RotL64(aOrbiterG, 13U)) + RotL64(aCarry, 37U)) + aWandererUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 10U) ^ aWandererJ);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + RotL64(aWandererA, 27U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordH);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 8323U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneD[((aIndex + 12889U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 10899U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 10912U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aPrevious, 14U)) ^ (RotL64(aCarry, 29U) + RotL64(aIngress, 41U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (((aWandererD + RotL64(aCross, 21U)) + RotL64(aCarry, 39U)) + 11210042748013785976U) + aOrbiterAssignSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterI = ((aWandererF + RotL64(aScatter, 13U)) + 4584747303233477454U) + aNonceWordG;
            aOrbiterF = ((aWandererC + RotL64(aIngress, 37U)) + RotL64(aCarry, 57U)) + 8878765929792969517U;
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 57U)) + RotL64(aCarry, 19U)) + 2172232330280041122U;
            aOrbiterK = ((aWandererE + RotL64(aCross, 3U)) + 8378937026022264016U) + aNonceWordD;
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 50U)) + 8683007464695824208U) + aOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = (aWandererI + RotL64(aIngress, 29U)) + 9564352997357118134U;
            //
            aOrbiterB = (((aOrbiterB + aOrbiterI) + 11713878436769887528U) + aOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1]) + aNonceWordK;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 8052917623074021077U;
            aOrbiterF = RotL64((aOrbiterF * 7450115139081623477U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 7720597162792145185U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 2602847785328475621U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14065077077207224525U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 17813669222300509724U) + aOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 8724263063156573013U;
            aOrbiterH = RotL64((aOrbiterH * 3632927017737834359U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 6882429835961613492U) + aNonceWordF;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 13213313479525717359U;
            aOrbiterI = RotL64((aOrbiterI * 2411431247725974895U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 2401526093648669573U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 3616448566579979749U;
            aOrbiterK = RotL64((aOrbiterK * 13323155103752121393U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 18268262471839710401U) + aOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 5116424918948694752U;
            aOrbiterJ = RotL64((aOrbiterJ * 7641143782996332069U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 11405305689555640431U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 12427591396711015574U;
            aOrbiterG = RotL64((aOrbiterG * 8112834135715541223U), 29U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterF, 41U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 48U));
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterJ, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aIngress, 27U) + aOrbiterH) + RotL64(aOrbiterB, 3U));
            aWandererD = aWandererD + (((((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 51U)) + aOrbiterH) + RotL64(aCarry, 23U)) + aNonceWordP) + aWandererUpdateSaltE[((aIndex + 22U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 21U) + aOrbiterJ) + RotL64(aOrbiterG, 43U));
            aWandererF = aWandererF + (((RotL64(aScatter, 41U) + RotL64(aOrbiterB, 21U)) + aOrbiterG) + RotL64(aCarry, 43U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 14U) + RotL64(aOrbiterJ, 37U)) + aOrbiterI);
            aWandererG = aWandererG + (((RotL64(aCross, 35U) + RotL64(aOrbiterF, 57U)) + aOrbiterJ) + aWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 47U) + aOrbiterK) + RotL64(aOrbiterI, 28U)) + aNonceWordE);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 12U) ^ aWandererG);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererI, 51U);
            aCarry = aCarry + RotL64(aIngress, 34U);
            aCarry = aCarry ^ aNonceWordN;
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 20223U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 21536U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 21567U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 21761U)) & S_BLOCK1], 34U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCarry, 37U)) + (RotL64(aPrevious, 22U) ^ RotL64(aCross, 53U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererA + RotL64(aScatter, 39U)) + 16183871922837164759U;
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 53U)) + RotL64(aCarry, 21U)) + 7002058258090219055U;
            aOrbiterA = (aWandererI + RotL64(aIngress, 13U)) + 5650868611888303705U;
            aOrbiterB = (aWandererH + RotL64(aCross, 5U)) + 11899839660943876690U;
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 21U)) + 15349649504488111111U) + aNonceWordK;
            aOrbiterJ = ((((aWandererD + RotL64(aCross, 60U)) + RotL64(aCarry, 53U)) + 14060149569086744970U) + aOrbiterAssignSaltB[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordH;
            aOrbiterI = (((aWandererJ + RotL64(aIngress, 47U)) + RotL64(aCarry, 39U)) + 12920917574225030112U) + aOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 2831994965175330135U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 18312543585028439192U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11618182708195744321U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 11657562205118394239U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 10850792819281246052U;
            aOrbiterH = RotL64((aOrbiterH * 10663100544207879337U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 17810371216216125323U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 7963413941144223128U;
            aOrbiterE = RotL64((aOrbiterE * 534217972450595401U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 5498715358793875584U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 9256727548911651373U) ^ aNonceWordO;
            aOrbiterB = RotL64((aOrbiterB * 10498848323914000989U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 17246360111302191699U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 18309978718113983369U;
            aOrbiterG = RotL64((aOrbiterG * 18267472694666221077U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 3100998994319502921U) + aOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 8129301860291235970U;
            aOrbiterJ = RotL64((aOrbiterJ * 17847033539279176187U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 1889641029473279114U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 16538494307002917945U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8081488217920885783U), 5U);
            //
            aIngress = RotL64(aOrbiterH, 29U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 11U));
            aIngress = aIngress + RotL64(aOrbiterJ, 20U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 29U) + aOrbiterI) + RotL64(aOrbiterH, 21U));
            aWandererK = aWandererK + (((RotL64(aCross, 57U) + RotL64(aOrbiterB, 51U)) + aOrbiterH) + RotL64(aCarry, 41U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterB, 58U)) + aOrbiterJ) + aWandererUpdateSaltD[((aIndex + 24U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aScatter, 11U) + RotL64(aOrbiterA, 5U)) + aOrbiterI) + aNonceWordD) + aWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 5U) + aOrbiterA) + RotL64(aOrbiterJ, 27U)) + aNonceWordP);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 23U) + aOrbiterJ) + RotL64(aOrbiterG, 13U)) + RotL64(aCarry, 23U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 50U) + RotL64(aOrbiterA, 39U)) + aOrbiterE) + aNonceWordM);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 41U));
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererH);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + RotL64(aWandererB, 48U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordJ);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 28010U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((aIndex + 29164U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29557U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneD[((aIndex + 31137U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 39U) + RotL64(aCross, 51U)) ^ (RotL64(aPrevious, 3U) + RotL64(aCarry, 18U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererA + RotL64(aCross, 28U)) + 5173905450211892891U) + aNonceWordM;
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 21U)) + 3555542451908039957U) + aOrbiterAssignSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterE = (((aWandererC + RotL64(aScatter, 11U)) + RotL64(aCarry, 53U)) + 11559884700283861559U) + aNonceWordA;
            aOrbiterK = (aWandererK + RotL64(aIngress, 57U)) + 1352524329968738673U;
            aOrbiterJ = ((aWandererG + RotL64(aCross, 41U)) + RotL64(aCarry, 41U)) + 8914206450420616349U;
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 3U)) + 2251523378498463946U) + aOrbiterAssignSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterG = ((aWandererD + RotL64(aIngress, 51U)) + RotL64(aCarry, 21U)) + 9541575923299247038U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 1239854507907214595U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 17698101462598498934U;
            aOrbiterE = RotL64((aOrbiterE * 2304948713665996433U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 12305566971683256060U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 13804545036303215569U;
            aOrbiterF = RotL64((aOrbiterF * 10359543704152744971U), 47U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterI) + 10239749097704329264U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordI;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 4212214906286320308U) ^ aOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3661436621615751071U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 12192418916967430783U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 4475514289326450361U;
            aOrbiterJ = RotL64((aOrbiterJ * 17497164630368757887U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 17376102613298827459U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 18129393209955439341U) ^ aOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6404089025014118979U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 4014763724300253568U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 17325007199676828814U) ^ aNonceWordP;
            aOrbiterK = RotL64((aOrbiterK * 1420888274815627083U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 15480474849292388685U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 14357924730184375449U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16723492259068034209U), 23U);
            //
            aIngress = RotL64(aOrbiterG, 53U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 4U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 13U));
            aIngress = aIngress + RotL64(aOrbiterF, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 21U) + aOrbiterG) + RotL64(aOrbiterI, 35U)) + aWandererUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 51U) + aOrbiterJ) + RotL64(aOrbiterB, 11U)) + RotL64(aCarry, 5U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterK, 43U)) + aOrbiterF);
            aWandererG = aWandererG + (((((RotL64(aIngress, 58U) + aOrbiterK) + RotL64(aOrbiterJ, 21U)) + RotL64(aCarry, 21U)) + aNonceWordL) + aWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterF, 51U)) + aOrbiterG);
            aWandererA = aWandererA + ((RotL64(aScatter, 39U) + aOrbiterI) + RotL64(aOrbiterB, 5U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterJ, 28U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 22U));
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererH);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + RotL64(aWandererG, 27U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordI);
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

void TwistExpander_Golf_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xA134244614B4FBDFULL + 0xB6277666FE414D31ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x82478FBEC8A80F8FULL + 0xD1E06FF6E14256A5ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x93824BF4703B0B85ULL + 0x95ED894DCBC61202ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xD59D6F8EC985A6FFULL + 0xE84D173AE5C253F7ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xDA38DAE50056001FULL + 0x80D7FB732501CCE4ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xF3BB032C3D081873ULL + 0xF3D0B10184316362ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xE874FFB789F58FF9ULL + 0xC61F9E464966489BULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xAA338C33A88672F7ULL + 0xFF3AC8B53B38E9E3ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xB0FCC02FE9A0935FULL + 0xCB8CB6CCA6E4FB41ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xDE25983A5E242469ULL + 0xB01C11908A1F7795ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xC3FD59ED0E058AB1ULL + 0xC03817982081AA8EULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xBE43C6F55388EFDFULL + 0xAD51625E3A815E0CULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xCEFF4D0D0BA5CD45ULL + 0xFE1728EEBF4557C2ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xF1859E1A13123549ULL + 0xFE21A8C700D6243AULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xC4605B6F45936A5DULL + 0xFA3EBC02575CCBDBULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xAF40495BEA1E0DDBULL + 0xE53FA0E9F7D5BA61ULL);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 3389U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5966U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 7108U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneA[((aIndex + 1877U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 41U) ^ RotL64(aIngress, 19U)) + (RotL64(aCross, 6U) ^ RotL64(aPrevious, 57U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (aWandererH + RotL64(aPrevious, 37U)) + 11177787645248006236U;
            aOrbiterJ = (aWandererA + RotL64(aIngress, 22U)) + 3808340254579817169U;
            aOrbiterC = ((aWandererJ + RotL64(aCross, 11U)) + RotL64(aCarry, 3U)) + 828030667598518279U;
            aOrbiterB = ((aWandererB + RotL64(aScatter, 47U)) + RotL64(aCarry, 13U)) + 16177835921238398371U;
            aOrbiterF = ((aWandererE + RotL64(aIngress, 29U)) + RotL64(aCarry, 27U)) + 5518747735458708741U;
            aOrbiterE = (aWandererK + RotL64(aCross, 34U)) + 17346319082399995165U;
            aOrbiterI = (aWandererD + RotL64(aPrevious, 19U)) + 6397156921893030937U;
            aOrbiterH = (aWandererF + RotL64(aScatter, 57U)) + 15559381654710713582U;
            aOrbiterG = (((aWandererI + RotL64(aPrevious, 27U)) + 940404446491415088U) + aOrbiterAssignSaltA[((aIndex + 18U)) & S_SALT1]) + aNonceWordP;
            aOrbiterA = ((aWandererG + RotL64(aScatter, 41U)) + 8047166032048732645U) + aNonceWordI;
            aOrbiterK = ((aWandererC + RotL64(aCross, 43U)) + 4688468645859470491U) + aOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 3710878044770337260U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 116343189456629220U;
            aOrbiterC = RotL64((aOrbiterC * 5637725064169289339U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 883908030159391659U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 18058691521694880482U;
            aOrbiterE = RotL64((aOrbiterE * 3132200449123497619U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 17521015077103586117U) + aNonceWordC;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 3668332225435714918U) ^ aNonceWordM;
            aOrbiterD = RotL64((aOrbiterD * 12658899101297839881U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 12229480388278883300U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 16206524049491531816U;
            aOrbiterB = RotL64((aOrbiterB * 11122340196620859805U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 5743265849441077466U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 2812293020719282236U;
            aOrbiterI = RotL64((aOrbiterI * 8903956475200417109U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 13718364781538837074U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 861529717259766236U;
            aOrbiterG = RotL64((aOrbiterG * 17019744777211266685U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 4862687502126693872U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 7722024283321020761U;
            aOrbiterK = RotL64((aOrbiterK * 18086944039541060829U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 8205803118233399853U) + aOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterH) ^ 15130160926615050422U) ^ aOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterJ = RotL64((aOrbiterJ * 1454552751453996765U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 667469191899263617U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 18048970185163843471U;
            aOrbiterF = RotL64((aOrbiterF * 1800698970568737425U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 508102841337488721U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 3803840516662727630U;
            aOrbiterH = RotL64((aOrbiterH * 8477778555284121637U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 17055028117762299436U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 11177787645248006236U;
            aOrbiterA = RotL64((aOrbiterA * 12457019014051206805U), 13U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterH, 13U);
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 19U));
            aIngress = aIngress + (RotL64(aOrbiterA, 50U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterI, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aScatter, 47U) + aOrbiterA) + RotL64(aOrbiterD, 43U)) + RotL64(aCarry, 51U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 37U) + aOrbiterK) + RotL64(aOrbiterF, 34U)) + aNonceWordO);
            aWandererC = aWandererC + (((RotL64(aIngress, 51U) + RotL64(aOrbiterG, 51U)) + aOrbiterA) + aNonceWordF);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 53U) + aOrbiterG) + RotL64(aOrbiterJ, 13U)) + aWandererUpdateSaltF[((aIndex + 12U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aScatter, 29U) + aOrbiterG) + RotL64(aOrbiterF, 21U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 56U) + aOrbiterI) + RotL64(aOrbiterA, 39U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterG, 54U)) + aOrbiterB) + RotL64(aCarry, 13U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterF, 57U)) + aOrbiterH) + aWandererUpdateSaltD[((aIndex + 8U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aCross, 21U) + RotL64(aOrbiterB, 19U)) + aOrbiterF);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 44U) + aOrbiterC) + RotL64(aOrbiterG, 41U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 13U) + RotL64(aOrbiterE, 29U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererG, 51U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererI, 58U) ^ aWandererK);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + (RotL64(aWandererF, 37U) ^ aWandererJ);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + RotL64(aWandererB, 12U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordL);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 12688U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 14334U)) & S_BLOCK1], 10U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 10470U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 10315U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aIngress, 24U)) + (RotL64(aPrevious, 37U) + RotL64(aCross, 3U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 37U)) + 7632760812370906911U) + aNonceWordH;
            aOrbiterA = ((aWandererF + RotL64(aCross, 24U)) + RotL64(aCarry, 27U)) + 6007174525479723089U;
            aOrbiterF = (aWandererK + RotL64(aIngress, 19U)) + 3362829642521821048U;
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 29U)) + 18009548556107978286U) + aOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = (aWandererD + RotL64(aCross, 47U)) + 17880909432272697327U;
            aOrbiterB = (aWandererC + RotL64(aIngress, 51U)) + 15961567935420752568U;
            aOrbiterK = (aWandererA + RotL64(aPrevious, 21U)) + 10136559064656837921U;
            aOrbiterG = ((aWandererI + RotL64(aScatter, 44U)) + RotL64(aCarry, 43U)) + 17622019364405410277U;
            aOrbiterC = (((aWandererG + RotL64(aIngress, 11U)) + RotL64(aCarry, 37U)) + 6927494824421416306U) + aOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = ((aWandererB + RotL64(aScatter, 35U)) + 7125170407794874847U) + aNonceWordM;
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 3U)) + 12342273503071032250U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 14997696377476124836U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 14874498694181230698U;
            aOrbiterF = RotL64((aOrbiterF * 4026127545746010937U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 2549397729130885686U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 4217995818662767955U;
            aOrbiterA = RotL64((aOrbiterA * 5525525344485251063U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 4706089044415442525U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 17983900172670031015U) ^ aOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 541552737180932879U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 1904937798143929988U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 10620877287033139483U;
            aOrbiterK = RotL64((aOrbiterK * 16711012562024287213U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 15681091173163181525U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 2655543246639000084U) ^ aOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16686375598149755947U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 2647895110857289213U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 5581609212017175954U) ^ aNonceWordC;
            aOrbiterD = RotL64((aOrbiterD * 15330263616699031311U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 13609076329627787987U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 6244266279516622070U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12488345779236971095U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 5289624364508923581U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 16351476803965903112U;
            aOrbiterB = RotL64((aOrbiterB * 9012522724650442597U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 2731198704224650506U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 4177455951984414332U;
            aOrbiterG = RotL64((aOrbiterG * 2567165277406175517U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 3031687737578718714U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 4866790771642413883U;
            aOrbiterE = RotL64((aOrbiterE * 1139524449666360541U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 12903299652398385014U) + aOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 7632760812370906911U;
            aOrbiterI = RotL64((aOrbiterI * 7924544687662448385U), 53U);
            //
            aIngress = RotL64(aOrbiterI, 30U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 35U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + (RotL64(aOrbiterB, 6U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterC, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aIngress, 60U) + aOrbiterH) + RotL64(aOrbiterE, 5U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 39U) + aOrbiterI) + RotL64(aOrbiterE, 3U));
            aWandererI = aWandererI + (((RotL64(aScatter, 27U) + aOrbiterH) + RotL64(aOrbiterA, 35U)) + RotL64(aCarry, 21U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 11U) + aOrbiterC) + RotL64(aOrbiterF, 21U));
            aWandererB = aWandererB + ((RotL64(aCross, 19U) + aOrbiterB) + RotL64(aOrbiterF, 47U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterG, 27U)) + aOrbiterA);
            aWandererA = aWandererA + ((RotL64(aScatter, 36U) + RotL64(aOrbiterC, 18U)) + aOrbiterI);
            aWandererD = aWandererD ^ ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterG, 43U)) + aOrbiterK) + aNonceWordJ) + aWandererUpdateSaltA[((aIndex + 20U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 57U) + RotL64(aOrbiterG, 23U)) + aOrbiterJ) + RotL64(aCarry, 51U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 23U) + aOrbiterF) + RotL64(aOrbiterD, 53U)) + aWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 3U) + aOrbiterI) + RotL64(aOrbiterB, 30U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 42U) ^ aWandererK);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 37U));
            aCarry = aCarry + RotL64(aWandererI, 19U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordF);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 24265U)) & S_BLOCK1], 30U) ^ RotL64(aOperationLaneA[((aIndex + 23600U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 20230U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 19082U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 35U) + RotL64(aIngress, 47U)) ^ (RotL64(aPrevious, 18U) ^ RotL64(aCross, 5U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((aWandererE + RotL64(aIngress, 21U)) + 12980104182836602177U) + aNonceWordN;
            aOrbiterK = ((((aWandererH + RotL64(aPrevious, 11U)) + RotL64(aCarry, 57U)) + 3172622203188863995U) + aOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordL;
            aOrbiterF = (aWandererI + RotL64(aCross, 35U)) + 1170974132219980203U;
            aOrbiterI = ((aWandererK + RotL64(aScatter, 26U)) + RotL64(aCarry, 47U)) + 6035201940965047490U;
            aOrbiterG = (aWandererA + RotL64(aIngress, 41U)) + 18033907118424996722U;
            aOrbiterJ = (aWandererG + RotL64(aCross, 13U)) + 14604813424800580304U;
            aOrbiterC = (aWandererC + RotL64(aPrevious, 51U)) + 13720232492851066035U;
            aOrbiterA = (((aWandererD + RotL64(aScatter, 47U)) + 3902659710585257448U) + aOrbiterAssignSaltE[((aIndex + 22U)) & S_SALT1]) + aNonceWordC;
            aOrbiterD = (aWandererB + RotL64(aIngress, 44U)) + 8331560652661619868U;
            aOrbiterB = ((aWandererF + RotL64(aCross, 29U)) + RotL64(aCarry, 41U)) + 4485014147538689794U;
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 3U)) + 168202636924512424U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 16227825670092707848U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 4792781933944671365U;
            aOrbiterF = RotL64((aOrbiterF * 15859849676231455283U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 12636865372722601282U) + aOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 18198291399585556632U;
            aOrbiterJ = RotL64((aOrbiterJ * 18155803890313399795U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 3650053185419807206U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 5897288963905408776U) ^ aOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3706949366974086151U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 9922308113622901726U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 13352279749091561510U;
            aOrbiterG = RotL64((aOrbiterG * 4025213180483632557U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 14969461950939646117U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 10231661776135056651U) ^ aNonceWordH;
            aOrbiterA = RotL64((aOrbiterA * 11284575051455238501U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 10621934544068320859U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 6029116920305246887U;
            aOrbiterB = RotL64((aOrbiterB * 6087523725059376905U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 12887482425168671195U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 8351351557123783853U;
            aOrbiterH = RotL64((aOrbiterH * 3839381627914762245U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 5405938210926464973U) + aOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 385145802287899406U;
            aOrbiterI = RotL64((aOrbiterI * 8330751480464271445U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 7907749190875916461U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 5138733192253468642U;
            aOrbiterC = RotL64((aOrbiterC * 17028325976353263843U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 14382272868178763187U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 14354777100157531233U;
            aOrbiterD = RotL64((aOrbiterD * 7095764230272037767U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 4390647647193363824U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 12980104182836602177U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11124472075872147333U), 11U);
            //
            aIngress = RotL64(aOrbiterB, 26U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 13U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 21U));
            aIngress = aIngress + RotL64(aOrbiterD, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 5U) + aOrbiterE) + RotL64(aOrbiterG, 57U));
            aWandererK = aWandererK + (((RotL64(aScatter, 47U) + aOrbiterI) + RotL64(aOrbiterE, 41U)) + RotL64(aCarry, 35U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterB, 47U)) + aOrbiterK);
            aWandererE = aWandererE + ((RotL64(aCross, 40U) + RotL64(aOrbiterF, 60U)) + aOrbiterH);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterA, 21U)) + aOrbiterB);
            aWandererI = aWandererI + (((RotL64(aCross, 43U) + aOrbiterC) + RotL64(aOrbiterD, 43U)) + RotL64(aCarry, 19U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterG, 39U)) + aOrbiterF) + aWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aScatter, 51U) + aOrbiterC) + RotL64(aOrbiterB, 23U)) + aNonceWordD) + aWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 37U) + aOrbiterA) + RotL64(aOrbiterJ, 14U)) + aNonceWordK);
            aWandererG = aWandererG + ((RotL64(aIngress, 11U) + aOrbiterJ) + RotL64(aOrbiterH, 27U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 20U) + aOrbiterG) + RotL64(aOrbiterI, 5U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 41U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 22U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 51U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + RotL64(aWandererF, 37U);
            aCarry = aCarry + RotL64(aIngress, 48U);
            aCarry = aCarry ^ aNonceWordO;
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 31893U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29079U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 28312U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneD[((aIndex + 27873U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 19U) + RotL64(aCarry, 39U)) + (RotL64(aPrevious, 51U) ^ RotL64(aCross, 6U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (aWandererE + RotL64(aIngress, 41U)) + 18191288703716505885U;
            aOrbiterC = (aWandererC + RotL64(aCross, 13U)) + 9824014524910417136U;
            aOrbiterH = (((aWandererF + RotL64(aScatter, 57U)) + RotL64(aCarry, 5U)) + 11953012029254917548U) + aOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = (aWandererA + RotL64(aPrevious, 34U)) + 6297568011027199089U;
            aOrbiterJ = ((aWandererG + RotL64(aIngress, 3U)) + RotL64(aCarry, 23U)) + 2576999400457367975U;
            aOrbiterB = (aWandererK + RotL64(aPrevious, 29U)) + 13176139160575558254U;
            aOrbiterG = (aWandererB + RotL64(aScatter, 51U)) + 9978408174563621810U;
            aOrbiterD = (((aWandererH + RotL64(aCross, 43U)) + RotL64(aCarry, 53U)) + 16765834875061607142U) + aOrbiterAssignSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = (aWandererI + RotL64(aPrevious, 47U)) + 16534507305459121344U;
            aOrbiterA = (aWandererJ + RotL64(aIngress, 36U)) + 3114710944346151807U;
            aOrbiterE = ((aWandererD + RotL64(aCross, 27U)) + 10240517868726718592U) + aNonceWordH;
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 10721450637990777883U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 16689590768796583952U;
            aOrbiterH = RotL64((aOrbiterH * 3046344179729901637U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 2427422768928450209U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 13495584061816457831U;
            aOrbiterJ = RotL64((aOrbiterJ * 6670984773768885119U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 7058636403765106682U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 9897341853944713767U;
            aOrbiterB = RotL64((aOrbiterB * 14286816859999869231U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 17749559755733386064U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 12515645083926326659U;
            aOrbiterG = RotL64((aOrbiterG * 6582878478865838245U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 2625692458813609962U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 10596240255026143019U;
            aOrbiterD = RotL64((aOrbiterD * 11605800195771080135U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 12374290338067865540U) + aNonceWordJ;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 1507386663796330249U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1210241080424446087U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 9288099549484146726U) + aOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 15159312464747000702U;
            aOrbiterA = RotL64((aOrbiterA * 500055502081347757U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 14998608679505446229U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 17625038109437732009U;
            aOrbiterE = RotL64((aOrbiterE * 14785862243019841689U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 10543192232885637211U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 10330547522729618042U;
            aOrbiterK = RotL64((aOrbiterK * 7635903835474874057U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 5753298214283941201U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 15943436872588208065U;
            aOrbiterC = RotL64((aOrbiterC * 17704547766822075741U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 5757218926946874970U) + aOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 18191288703716505885U;
            aOrbiterI = RotL64((aOrbiterI * 2644970408001409575U), 23U);
            //
            aIngress = RotL64(aOrbiterC, 13U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 39U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 21U));
            aIngress = aIngress + (RotL64(aOrbiterI, 44U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 27U));
            aIngress = aIngress + RotL64(aOrbiterJ, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aIngress, 43U) + aOrbiterB) + RotL64(aOrbiterK, 19U));
            aWandererC = aWandererC ^ ((((RotL64(aPrevious, 50U) + RotL64(aOrbiterG, 47U)) + aOrbiterI) + aNonceWordF) + aWandererUpdateSaltF[((aIndex + 26U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 47U) + RotL64(aOrbiterH, 27U)) + aOrbiterF) + aNonceWordM);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 35U) + aOrbiterA) + RotL64(aOrbiterB, 5U)) + aWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 27U) + aOrbiterD) + RotL64(aOrbiterC, 35U)) + RotL64(aCarry, 35U)) + aNonceWordP);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 19U) + aOrbiterB) + RotL64(aOrbiterJ, 41U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 23U) + RotL64(aOrbiterE, 54U)) + aOrbiterG) + RotL64(aCarry, 23U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterH, 57U)) + aOrbiterI);
            aWandererI = aWandererI + ((RotL64(aCross, 56U) + aOrbiterA) + RotL64(aOrbiterE, 51U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterJ, 39U)) + aOrbiterC);
            aWandererK = aWandererK + ((RotL64(aIngress, 3U) + RotL64(aOrbiterK, 14U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 56U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + (RotL64(aWandererB, 13U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 18U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererJ, 51U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordM);
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

void TwistExpander_Golf_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x9FE69472B27C0C0DULL + 0xC24A29C95B871A37ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xC74D1EB93C8B906FULL + 0xCE80AE66653F096FULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xE0A4B49DF814163DULL + 0x893F7286CD2756A7ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xB1ACD5D9058F4917ULL + 0xBA0A106E9BC37425ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xB28A25CE6B4CCCD7ULL + 0xAE3171BE66B7AB76ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xFCF866E28343B105ULL + 0xDD30E33DC62B4E44ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xBC7891B8EAAD0E39ULL + 0xA341206C1A2DE055ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xB159F4B5C67F8055ULL + 0xC1EC74EEE4070931ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xB83E35D4D1789471ULL + 0xBF41614759A59692ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xF578EB2BBD21796BULL + 0xABE44A4F693CBC34ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xC49CA6E3C8C91A25ULL + 0xB4ADBE08F71A30D3ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xEB7B371CF0DC6A67ULL + 0xE9256FD96A85D792ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xD02B986A43DCD4E7ULL + 0xDC06BC254DC9B36DULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xA203CC63F923DB4FULL + 0x9427D78C6F50D81DULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x9FAFFC040B05F75FULL + 0xFFBE6829BB1BFD9BULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xD5DDBC2B664981D5ULL + 0xB40F550B81E8C827ULL);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 4097U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 193U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 2808U)) & S_BLOCK1], 26U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 45U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCross, 5U)) ^ (RotL64(aCarry, 40U) + RotL64(aIngress, 19U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((aWandererB + RotL64(aIngress, 57U)) + 15045917390223766480U) + aNonceWordM;
            aOrbiterI = ((aWandererD + RotL64(aPrevious, 41U)) + 10763054007033668758U) + aNonceWordH;
            aOrbiterJ = ((aWandererI + RotL64(aCross, 48U)) + RotL64(aCarry, 27U)) + 13190170142593666607U;
            aOrbiterA = (aWandererA + RotL64(aScatter, 53U)) + 9657025731441167065U;
            aOrbiterG = ((aWandererF + RotL64(aIngress, 27U)) + RotL64(aCarry, 11U)) + 11433367178975954211U;
            aOrbiterF = (((aWandererC + RotL64(aCross, 3U)) + 17904920143996810366U) + aOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordD;
            aOrbiterC = (aWandererK + RotL64(aPrevious, 21U)) + 3244383020512113283U;
            aOrbiterH = (((aWandererG + RotL64(aScatter, 35U)) + RotL64(aCarry, 39U)) + 6538815775171139091U) + aOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = (aWandererE + RotL64(aPrevious, 10U)) + 7195368312757976343U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 18134430713910279374U) + aOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 6571776588427107976U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11916502085252589161U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 11830778129647517758U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 9793702760907767365U) ^ aNonceWordJ;
            aOrbiterF = RotL64((aOrbiterF * 4096246227968677179U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 2287235876793192036U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 8951959188326141794U;
            aOrbiterH = RotL64((aOrbiterH * 9968356718110753845U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 7583061790273240157U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 3571364625022806085U;
            aOrbiterB = RotL64((aOrbiterB * 6238360922735480669U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 13869345563551689212U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 277480328952975002U) ^ aNonceWordG;
            aOrbiterD = RotL64((aOrbiterD * 1057564597096163085U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 4983735092494677578U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 9490022869381030928U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12926352917961703123U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 7928039573014765566U) + aNonceWordP;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 6504190875809407084U;
            aOrbiterC = RotL64((aOrbiterC * 14648214826494826711U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 2787985600176307413U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 16308785053443116826U;
            aOrbiterI = RotL64((aOrbiterI * 17867565986311256691U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 12788128335006767824U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 1187040019537798339U;
            aOrbiterG = RotL64((aOrbiterG * 10834905007658184183U), 27U);
            //
            aIngress = RotL64(aOrbiterB, 35U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterA, 30U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterC, 21U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterF, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aScatter, 38U) + aOrbiterB) + RotL64(aOrbiterA, 27U)) + aWandererUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aCross, 51U) + aOrbiterC) + RotL64(aOrbiterH, 18U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterA, 41U)) + aOrbiterC);
            aWandererI = aWandererI + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterG, 57U)) + aOrbiterB);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 43U) + aOrbiterF) + RotL64(aOrbiterI, 37U)) + aNonceWordK);
            aWandererE = aWandererE + (((RotL64(aPrevious, 11U) + aOrbiterD) + RotL64(aOrbiterJ, 3U)) + RotL64(aCarry, 21U));
            aWandererK = aWandererK ^ ((((RotL64(aIngress, 4U) + aOrbiterB) + RotL64(aOrbiterD, 11U)) + aNonceWordB) + aWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 23U) + RotL64(aOrbiterC, 52U)) + aOrbiterD) + RotL64(aCarry, 39U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 19U) + aOrbiterC) + RotL64(aOrbiterF, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 41U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererA, 18U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererK, 37U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererC, 23U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ aNonceWordC;
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 5934U)) & S_BLOCK1], 52U) ^ RotL64(aOperationLaneD[((aIndex + 6152U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 9876U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneB[((aIndex + 6956U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 11U) + RotL64(aPrevious, 43U)) + (RotL64(aIngress, 60U) ^ RotL64(aCross, 27U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = ((aWandererK + RotL64(aIngress, 13U)) + 3105313968748067810U) + aOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = (((aWandererD + RotL64(aPrevious, 19U)) + 9977249451119627064U) + aOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1]) + aNonceWordN;
            aOrbiterF = (aWandererF + RotL64(aCross, 6U)) + 17941392803495349366U;
            aOrbiterA = ((aWandererB + RotL64(aScatter, 43U)) + RotL64(aCarry, 13U)) + 4279533326705471133U;
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 29U)) + RotL64(aCarry, 21U)) + 13983828966811580039U;
            aOrbiterB = (aWandererJ + RotL64(aIngress, 57U)) + 3983490984234810378U;
            aOrbiterH = (((aWandererC + RotL64(aCross, 23U)) + RotL64(aCarry, 41U)) + 308786542215259956U) + aNonceWordL;
            aOrbiterG = (aWandererA + RotL64(aScatter, 52U)) + 8443607695364427037U;
            aOrbiterD = (aWandererI + RotL64(aIngress, 47U)) + 14939626441464340668U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 9350693577306121110U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 1717071159396961752U;
            aOrbiterF = RotL64((aOrbiterF * 11062480662625054525U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 15911765265202100610U) + aOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 14898546272333182767U;
            aOrbiterK = RotL64((aOrbiterK * 2674900543810733067U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 3560903518513465868U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 5367062725726860234U;
            aOrbiterH = RotL64((aOrbiterH * 8521908836601319553U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 15233321480618877327U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 9288449812290126074U;
            aOrbiterG = RotL64((aOrbiterG * 6815298520404038519U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 5504840529511585676U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 6825598386801620046U;
            aOrbiterD = RotL64((aOrbiterD * 11666542445846250077U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 6433024450721339470U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 97934156644929458U;
            aOrbiterE = RotL64((aOrbiterE * 8630530773006923215U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 3260053604798744515U) + aOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 16539416623243059076U) ^ aNonceWordC;
            aOrbiterA = RotL64((aOrbiterA * 12199577351166064503U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 9814290051339038920U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 13280156404507444041U;
            aOrbiterB = RotL64((aOrbiterB * 15269010043398910061U), 47U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterB) + 11853942590993546833U) + aOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1]) + aNonceWordF;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 13207869904312989977U) ^ aNonceWordJ;
            aOrbiterI = RotL64((aOrbiterI * 15503461937625795969U), 5U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterF, 60U);
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterH, 47U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 13U));
            aIngress = aIngress + RotL64(aOrbiterB, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aScatter, 56U) + aOrbiterD) + RotL64(aOrbiterA, 24U)) + aWandererUpdateSaltB[((aIndex + 6U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterK, 19U)) + aOrbiterD);
            aWandererC = aWandererC ^ (((RotL64(aCross, 51U) + aOrbiterB) + RotL64(aOrbiterE, 57U)) + aNonceWordM);
            aWandererE = aWandererE + ((((RotL64(aIngress, 19U) + aOrbiterE) + RotL64(aOrbiterF, 13U)) + RotL64(aCarry, 51U)) + aWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterH, 29U)) + aOrbiterI);
            aWandererD = aWandererD + ((((RotL64(aScatter, 41U) + RotL64(aOrbiterF, 53U)) + aOrbiterG) + RotL64(aCarry, 29U)) + aNonceWordI);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 3U) + aOrbiterI) + RotL64(aOrbiterG, 35U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 46U) + RotL64(aOrbiterH, 47U)) + aOrbiterD);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 37U) + aOrbiterD) + RotL64(aOrbiterB, 40U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 27U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + (RotL64(aWandererD, 54U) ^ aWandererE);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 5U));
            aCarry = aCarry + RotL64(aWandererI, 41U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ aNonceWordO;
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 13301U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((aIndex + 12781U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 14170U)) & S_BLOCK1], 10U) ^ RotL64(aOperationLaneC[((aIndex + 16175U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCross, 5U)) + (RotL64(aCarry, 41U) ^ RotL64(aPrevious, 18U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (aWandererK + RotL64(aIngress, 29U)) + 15904465836916519864U;
            aOrbiterG = (aWandererH + RotL64(aScatter, 43U)) + 17725629806317789307U;
            aOrbiterJ = (((aWandererC + RotL64(aCross, 18U)) + RotL64(aCarry, 11U)) + 13794170125914914828U) + aNonceWordK;
            aOrbiterE = (((aWandererG + RotL64(aPrevious, 47U)) + RotL64(aCarry, 53U)) + 2149055907476874332U) + aOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = (aWandererJ + RotL64(aCross, 11U)) + 5342047776745074649U;
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 3U)) + 8268148484060546838U) + aNonceWordL;
            aOrbiterH = ((aWandererB + RotL64(aScatter, 23U)) + RotL64(aCarry, 35U)) + 10821151364028563719U;
            aOrbiterB = ((aWandererD + RotL64(aIngress, 39U)) + 4294213820894407378U) + aOrbiterAssignSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterI = ((aWandererI + RotL64(aCross, 34U)) + 10884726101307943090U) + aNonceWordF;
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 16432210042202444824U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 15196602644336228055U;
            aOrbiterJ = RotL64((aOrbiterJ * 12680438355124070237U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 14117787670220328165U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 219833877949480215U;
            aOrbiterC = RotL64((aOrbiterC * 10736293047771972173U), 35U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterK) + 3326396981881473962U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordP;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 14918513066311426279U;
            aOrbiterE = RotL64((aOrbiterE * 14269763278564574663U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 11795234681370163206U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 3068267285352664813U;
            aOrbiterG = RotL64((aOrbiterG * 15746255933920904619U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 245233356957999496U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 709926406353796673U;
            aOrbiterD = RotL64((aOrbiterD * 13627039596842073595U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 5378105439430271038U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 10114555061122044430U;
            aOrbiterK = RotL64((aOrbiterK * 5351295043424885549U), 47U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterJ) + 13233010815716769713U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordA;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 8231291294833548389U;
            aOrbiterH = RotL64((aOrbiterH * 10840516135212753869U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 7160760224172419829U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 14767926435411546785U;
            aOrbiterB = RotL64((aOrbiterB * 1643485739468851073U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 4464245330038080103U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 15778166658285494712U) ^ aNonceWordG;
            aOrbiterI = RotL64((aOrbiterI * 13980891936095282989U), 23U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterG, 47U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 51U));
            aIngress = aIngress + (RotL64(aOrbiterB, 27U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterK, 30U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aScatter, 23U) + aOrbiterD) + RotL64(aOrbiterK, 56U)) + aWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 60U) + RotL64(aOrbiterC, 47U)) + aOrbiterB);
            aWandererC = aWandererC + (((RotL64(aCross, 43U) + RotL64(aOrbiterG, 21U)) + aOrbiterK) + aNonceWordB);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterJ, 29U)) + aOrbiterG);
            aWandererK = aWandererK + (((RotL64(aScatter, 19U) + RotL64(aOrbiterK, 43U)) + aOrbiterI) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 11U) + aOrbiterD) + RotL64(aOrbiterE, 11U));
            aWandererH = aWandererH + (((RotL64(aIngress, 48U) + RotL64(aOrbiterD, 51U)) + aOrbiterH) + RotL64(aCarry, 57U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterI, 34U)) + aOrbiterB) + aWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 27U) + RotL64(aOrbiterC, 5U)) + aOrbiterE) + aNonceWordJ);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 40U));
            aCarry = aCarry + (RotL64(aWandererB, 37U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + RotL64(aWandererI, 53U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ aNonceWordC;
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 20061U)) & S_BLOCK1], 22U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19334U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20995U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 17346U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 60U) ^ RotL64(aIngress, 39U)) + (RotL64(aCross, 27U) ^ RotL64(aPrevious, 11U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (((aWandererK + RotL64(aScatter, 11U)) + RotL64(aCarry, 3U)) + 1866656689936219099U) + aNonceWordA;
            aOrbiterI = ((aWandererI + RotL64(aIngress, 35U)) + RotL64(aCarry, 37U)) + 2312314528139448289U;
            aOrbiterE = (aWandererG + RotL64(aPrevious, 18U)) + 3554037526469185237U;
            aOrbiterB = (aWandererA + RotL64(aCross, 41U)) + 405707755060974111U;
            aOrbiterG = (aWandererH + RotL64(aPrevious, 51U)) + 1862976326004007697U;
            aOrbiterH = ((aWandererF + RotL64(aScatter, 27U)) + 12992483065443288263U) + aOrbiterAssignSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 47U)) + 3793854946371595197U) + aNonceWordP;
            aOrbiterA = ((aWandererE + RotL64(aCross, 60U)) + 4244007978867369382U) + aOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = (((aWandererB + RotL64(aPrevious, 23U)) + RotL64(aCarry, 13U)) + 10280867500312580308U) + aNonceWordH;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 472563452959164242U) + aOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 12041770406895816553U) ^ aNonceWordK;
            aOrbiterE = RotL64((aOrbiterE * 17811798500132002631U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 6118634015704900486U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 13637107920449233307U;
            aOrbiterG = RotL64((aOrbiterG * 17712028184714868053U), 37U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterG) + 16673735670669318830U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordN;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 8602681273646630496U;
            aOrbiterJ = RotL64((aOrbiterJ * 6995213887710749241U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 7683264695930369476U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 9146674871199188218U) ^ aOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7403427067419261981U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 3012935612827493084U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 1259789268731661945U;
            aOrbiterB = RotL64((aOrbiterB * 2372843620327050137U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 5623690455471160780U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 18355567776031865462U) ^ aOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9553862670107886679U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 7705134893833304792U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 4435192506444773834U;
            aOrbiterA = RotL64((aOrbiterA * 5249651218395299501U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 6204683785806409075U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 17886971535016484255U;
            aOrbiterK = RotL64((aOrbiterK * 6047216474762933535U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 4430578901091376829U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 607557685798141547U) ^ aNonceWordO;
            aOrbiterI = RotL64((aOrbiterI * 12342665567201483107U), 3U);
            //
            aIngress = RotL64(aOrbiterE, 37U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 21U));
            aIngress = aIngress + (RotL64(aOrbiterK, 34U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterB, 41U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterI, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aCross, 46U) + RotL64(aOrbiterB, 3U)) + aOrbiterE) + RotL64(aCarry, 53U)) + aNonceWordE);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 37U) + aOrbiterH) + RotL64(aOrbiterB, 57U)) + aWandererUpdateSaltD[((aIndex + 8U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 41U) + RotL64(aOrbiterI, 52U)) + aOrbiterJ);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 5U) + aOrbiterE) + RotL64(aOrbiterA, 39U)) + aNonceWordB);
            aWandererH = aWandererH + (((RotL64(aIngress, 53U) + aOrbiterI) + RotL64(aOrbiterB, 47U)) + aNonceWordL);
            aWandererF = aWandererF ^ ((RotL64(aCross, 58U) + RotL64(aOrbiterJ, 27U)) + aOrbiterK);
            aWandererK = aWandererK + ((((RotL64(aScatter, 23U) + RotL64(aOrbiterD, 23U)) + aOrbiterH) + RotL64(aCarry, 5U)) + aWandererUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 13U) + aOrbiterH) + RotL64(aOrbiterE, 19U));
            aWandererI = aWandererI + ((RotL64(aIngress, 29U) + RotL64(aOrbiterK, 10U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererK, 22U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + RotL64(aWandererG, 57U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ aNonceWordH;
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 23335U)) & S_BLOCK1], 36U) ^ RotL64(aExpandLaneA[((aIndex + 22055U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25588U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23310U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 41U) + RotL64(aPrevious, 27U)) + (RotL64(aCarry, 11U) ^ RotL64(aIngress, 60U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (((aWandererE + RotL64(aIngress, 29U)) + 4068921616130916949U) + aOrbiterAssignSaltB[((aIndex + 20U)) & S_SALT1]) + aNonceWordL;
            aOrbiterD = (((aWandererG + RotL64(aScatter, 34U)) + RotL64(aCarry, 37U)) + 12077715273915151726U) + aOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = (aWandererH + RotL64(aPrevious, 23U)) + 16047546802670596833U;
            aOrbiterG = (aWandererJ + RotL64(aCross, 57U)) + 9690277462716999763U;
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 11U)) + RotL64(aCarry, 13U)) + 14484814700447992628U;
            aOrbiterA = (((aWandererC + RotL64(aPrevious, 3U)) + RotL64(aCarry, 21U)) + 17089267243053958210U) + aNonceWordO;
            aOrbiterK = (aWandererK + RotL64(aCross, 42U)) + 9138746214446211147U;
            aOrbiterC = ((aWandererB + RotL64(aScatter, 53U)) + 10181001536979097045U) + aNonceWordP;
            aOrbiterE = (aWandererA + RotL64(aIngress, 19U)) + 6657458969093373191U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 7515983477876590988U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 3039935555863947600U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12511160550780270119U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 16209389224740851136U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 725253312098083182U) ^ aOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17535989492095522597U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 13307041115748941383U) + aOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 7159572004825238263U;
            aOrbiterC = RotL64((aOrbiterC * 4855009895002398449U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 12027236743251643820U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 8717826175991286553U;
            aOrbiterE = RotL64((aOrbiterE * 1175614802543098451U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 4769096034227659937U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 11201226563992939616U;
            aOrbiterH = RotL64((aOrbiterH * 15595355978388159931U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 17295978531215563256U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 11850923890626719833U;
            aOrbiterG = RotL64((aOrbiterG * 3854851059897397075U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 14139441565288097706U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 988684899382304485U) ^ aOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11929090869999700891U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 6159251276942253175U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 4849529993914550651U;
            aOrbiterD = RotL64((aOrbiterD * 18240712676783671317U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 6679745455842119497U) + aNonceWordA;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 15838404437552215214U) ^ aNonceWordC;
            aOrbiterJ = RotL64((aOrbiterJ * 17357853511591350887U), 41U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterA, 57U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 19U));
            aIngress = aIngress + (RotL64(aOrbiterC, 42U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 53U));
            aIngress = aIngress + RotL64(aOrbiterK, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aIngress, 3U) + RotL64(aOrbiterD, 13U)) + aOrbiterC);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 10U) + aOrbiterK) + RotL64(aOrbiterE, 57U)) + aNonceWordJ);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterC, 47U)) + aOrbiterE) + RotL64(aCarry, 27U)) + aWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterD, 34U)) + aOrbiterH) + aNonceWordK);
            aWandererK = aWandererK + (((RotL64(aIngress, 27U) + RotL64(aOrbiterJ, 51U)) + aOrbiterC) + aNonceWordM);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 23U) + aOrbiterA) + RotL64(aOrbiterH, 39U));
            aWandererG = aWandererG + (((RotL64(aScatter, 14U) + aOrbiterJ) + RotL64(aOrbiterG, 29U)) + aWandererUpdateSaltB[((aIndex + 10U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 51U) + aOrbiterH) + RotL64(aOrbiterJ, 4U));
            aWandererE = aWandererE + (((RotL64(aScatter, 43U) + RotL64(aOrbiterF, 21U)) + aOrbiterJ) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererC, 26U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererK, 39U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererA, 57U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordH);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 29894U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((aIndex + 29051U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30673U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27787U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 51U) + RotL64(aIngress, 5U)) ^ (RotL64(aPrevious, 24U) ^ RotL64(aCross, 37U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((aWandererK + RotL64(aScatter, 30U)) + RotL64(aCarry, 19U)) + 2915859148137000694U;
            aOrbiterC = (aWandererE + RotL64(aPrevious, 57U)) + 210680583721444425U;
            aOrbiterK = ((aWandererB + RotL64(aIngress, 51U)) + RotL64(aCarry, 53U)) + 6668118118775650387U;
            aOrbiterB = (aWandererF + RotL64(aCross, 13U)) + 15794200818099010989U;
            aOrbiterJ = (aWandererJ + RotL64(aPrevious, 21U)) + 6565076707062828369U;
            aOrbiterE = ((aWandererC + RotL64(aCross, 39U)) + RotL64(aCarry, 37U)) + 16323164497808856719U;
            aOrbiterD = (((aWandererH + RotL64(aIngress, 26U)) + 7965435318816716560U) + aOrbiterAssignSaltF[((aIndex + 16U)) & S_SALT1]) + aNonceWordD;
            aOrbiterG = ((aWandererG + RotL64(aScatter, 35U)) + 7390281030573369017U) + aNonceWordH;
            aOrbiterI = ((aWandererI + RotL64(aIngress, 47U)) + 2269738866911824875U) + aOrbiterAssignSaltC[((aIndex + 26U)) & S_SALT1];
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 9664014216039993873U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 18284857398028357633U;
            aOrbiterK = RotL64((aOrbiterK * 8402008251343393737U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 367667619795303009U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 7935945060956274197U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5481786693511955209U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 16683666162337789540U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 10655658270998102390U;
            aOrbiterD = RotL64((aOrbiterD * 15231596813382239841U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 8307037916581540297U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 3247742749860703524U) ^ aNonceWordJ;
            aOrbiterG = RotL64((aOrbiterG * 15052136713218656641U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 10446792483683818139U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 16374602929344972364U;
            aOrbiterI = RotL64((aOrbiterI * 12599903932725787599U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 2411334498322777183U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 1093701164116833765U) ^ aOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13129220206835381729U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 17018480952982840635U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 17348395690080029814U;
            aOrbiterB = RotL64((aOrbiterB * 6212591395713433257U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 16111252311283623152U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 12776492920397785951U;
            aOrbiterE = RotL64((aOrbiterE * 6136009241593081821U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 12214538600808144816U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 10043377462096783363U;
            aOrbiterC = RotL64((aOrbiterC * 14639467375095185877U), 3U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterD, 51U);
            aIngress = aIngress + (RotL64(aOrbiterK, 27U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterC, 42U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 5U));
            aIngress = aIngress + RotL64(aOrbiterJ, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aCross, 47U) + aOrbiterG) + RotL64(aOrbiterJ, 19U)) + RotL64(aCarry, 39U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 57U) + aOrbiterJ) + RotL64(aOrbiterE, 13U)) + aWandererUpdateSaltF[((aIndex + 20U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 29U) + aOrbiterB) + RotL64(aOrbiterK, 44U)) + aNonceWordP);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 42U) + aOrbiterD) + RotL64(aOrbiterC, 23U)) + aNonceWordI);
            aWandererJ = aWandererJ + ((RotL64(aCross, 51U) + RotL64(aOrbiterE, 29U)) + aOrbiterB);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 35U) + aOrbiterJ) + RotL64(aOrbiterB, 3U));
            aWandererK = aWandererK + ((RotL64(aIngress, 19U) + RotL64(aOrbiterC, 56U)) + aOrbiterK);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 3U) + aOrbiterI) + RotL64(aOrbiterE, 39U));
            aWandererF = aWandererF + ((((RotL64(aPrevious, 24U) + aOrbiterF) + RotL64(aOrbiterK, 35U)) + RotL64(aCarry, 47U)) + aWandererUpdateSaltA[((aIndex + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 53U));
            aCarry = aCarry + (RotL64(aWandererK, 58U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererC, 19U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ aNonceWordH;
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

void TwistExpander_Golf_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x8AE4B6598C6EB511ULL + 0xA8A009C76954C5FBULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xACA0AA870957DA43ULL + 0xE5E547A92ECE1F75ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xC4E72B13EE3FF03BULL + 0xBA17D36F159D3A30ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xAF9637A6C6376431ULL + 0xBCEFE49613FC1857ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xB94F353A0457ACBBULL + 0xC40A6F5A48ABF2A8ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xE91D1359DB7277C3ULL + 0xD0B11F850156A4A0ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xD975AF4974E3950FULL + 0xFAC0FF0B40575129ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xA3C256538FA95DEDULL + 0xA8AEEB75A21C13ACULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xF0C05F1AC846AC5BULL + 0xB1F7D7D4153DB607ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xAB6D59B5679A1A4BULL + 0x8C90E95BCD0E34ABULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x8343C21445A695DDULL + 0xD3F978CAA2E57342ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xE2C00C56E79E2F89ULL + 0xB1FB9E800379B067ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xF6EFECBE73F693B1ULL + 0xCFEB8DAE3F732FE1ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x853158B11CB348DFULL + 0xF77858490A7EEB1FULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x863AF6CCE0E57A2DULL + 0xE3B0A5C9385CA2FEULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xEBD8773AE5FF6F41ULL + 0xC4CAEB3FEDE3AC50ULL);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 1721U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 1511U)) & W_KEY1], 19U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 4714U)) & W_KEY1], 3U) ^ RotL64(mSource[((aIndex + 1935U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 21U) ^ RotL64(aPrevious, 53U)) ^ (RotL64(aIngress, 35U) + RotL64(aCarry, 6U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterE = (aWandererB + RotL64(aScatter, 13U)) + 4773124477323378268U;
            aOrbiterB = (((aWandererK + RotL64(aIngress, 57U)) + RotL64(aCarry, 5U)) + 16848723289435796005U) + aPhaseAOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = ((aWandererA + RotL64(aCross, 35U)) + 13846642134917107058U) + aNonceWordJ;
            aOrbiterD = (((aWandererC + RotL64(aPrevious, 21U)) + RotL64(aCarry, 51U)) + 6472057872482789939U) + aNonceWordB;
            aOrbiterG = ((aWandererE + RotL64(aCross, 5U)) + RotL64(aCarry, 35U)) + 2747019500690707226U;
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 51U)) + 9003965289739733880U) + aPhaseAOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 42U)) + 3013390651936257377U) + aNonceWordF;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 3331004709895625067U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterC = (((aOrbiterC ^ aOrbiterE) ^ 15355010435553517129U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterC = RotL64((aOrbiterC * 8322759117004876831U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 7709870658004280052U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 13568728443963926564U) ^ aNonceWordC;
            aOrbiterG = RotL64((aOrbiterG * 6736090830113688981U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 12409548853419307131U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 969183352023661537U;
            aOrbiterI = RotL64((aOrbiterI * 5549220554838837145U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 15370309834426476775U) + aNonceWordE;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 3896803894396631184U;
            aOrbiterK = RotL64((aOrbiterK * 11018830202891911603U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 10848873633291935766U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 12885336509190543440U;
            aOrbiterE = RotL64((aOrbiterE * 1487357252619221365U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 8252290890093788010U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 9201553615601641350U;
            aOrbiterD = RotL64((aOrbiterD * 420321130559162915U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 14014209645503188472U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 4015071464301844550U;
            aOrbiterB = RotL64((aOrbiterB * 17444195018239904971U), 37U);
            //
            aIngress = RotL64(aOrbiterK, 57U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 27U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 51U));
            aIngress = aIngress + RotL64(aOrbiterE, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aPrevious, 11U) + aOrbiterE) + RotL64(aOrbiterC, 57U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterE, 27U)) + aOrbiterB) + aNonceWordL);
            aWandererE = aWandererE + ((((RotL64(aIngress, 37U) + aOrbiterK) + RotL64(aOrbiterD, 18U)) + RotL64(aCarry, 43U)) + aPhaseAWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterD, 3U)) + aOrbiterG) + aPhaseAWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 47U) + aOrbiterC) + RotL64(aOrbiterI, 11U)) + RotL64(aCarry, 11U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterG, 43U)) + aOrbiterK) + aNonceWordA);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 18U) + RotL64(aOrbiterE, 35U)) + aOrbiterG) + aNonceWordP);
            //
            aCarry = aCarry + (RotL64(aWandererE, 58U) ^ aWandererJ);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 53U));
            aCarry = aCarry + (RotL64(aWandererB, 37U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererI, 5U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordC);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8095U)) & S_BLOCK1], 11U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 10751U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 6511U)) & W_KEY1], 19U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 9326U)) & W_KEY1], 27U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 10U) + RotL64(aPrevious, 39U)) ^ (RotL64(aCarry, 27U) ^ RotL64(aIngress, 57U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterF = ((aWandererF + RotL64(aCross, 13U)) + 3917730204724097072U) + aNonceWordE;
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 19U)) + RotL64(aCarry, 35U)) + 1874642340716212824U;
            aOrbiterB = ((aWandererI + RotL64(aIngress, 39U)) + RotL64(aCarry, 3U)) + 6900165757434854160U;
            aOrbiterI = ((aWandererE + RotL64(aScatter, 47U)) + 12750946097023807161U) + aPhaseAOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = (aWandererK + RotL64(aIngress, 30U)) + 6563216048479513594U;
            aOrbiterG = (((aWandererC + RotL64(aScatter, 5U)) + RotL64(aCarry, 53U)) + 14960240191349450795U) + aNonceWordI;
            aOrbiterA = (((aWandererA + RotL64(aCross, 57U)) + 16306180275951788289U) + aPhaseAOrbiterAssignSaltC[((aIndex + 18U)) & S_SALT1]) + aNonceWordP;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 6502066618271045547U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 6219852857850888738U;
            aOrbiterB = RotL64((aOrbiterB * 10892297250334325283U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 2272931312452845850U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 3028929882263199463U;
            aOrbiterF = RotL64((aOrbiterF * 11005324285856805069U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 6067393030073568112U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 10094809900437037258U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 18095564940730322769U), 11U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterA) + 5962414178157074575U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordA;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 15755563045799129417U;
            aOrbiterJ = RotL64((aOrbiterJ * 3692603590609922031U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 6321455513889880590U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 1197435601998121700U;
            aOrbiterE = RotL64((aOrbiterE * 17693996266260557625U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 12496949381666299968U) + aNonceWordL;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 6357070235648527030U;
            aOrbiterG = RotL64((aOrbiterG * 2931486644220862433U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 8423760160877540210U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 8090246492554850768U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2949407491181921633U), 57U);
            //
            aIngress = RotL64(aOrbiterA, 57U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 19U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 51U));
            aIngress = aIngress + RotL64(aOrbiterG, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 3U) + aOrbiterG) + RotL64(aOrbiterJ, 5U)) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterF, 13U)) + aOrbiterB) + aNonceWordC);
            aWandererA = aWandererA + ((RotL64(aCross, 21U) + RotL64(aOrbiterI, 41U)) + aOrbiterB);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 60U) + aOrbiterE) + RotL64(aOrbiterA, 21U));
            aWandererF = aWandererF + (((RotL64(aCross, 29U) + aOrbiterF) + RotL64(aOrbiterJ, 47U)) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 11U) + aOrbiterF) + RotL64(aOrbiterA, 54U));
            aWandererB = aWandererB + ((((RotL64(aPrevious, 51U) + RotL64(aOrbiterI, 29U)) + aOrbiterF) + RotL64(aCarry, 35U)) + aPhaseAWandererUpdateSaltD[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 18U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererK, 23U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordN);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 16215U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15587U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 14368U)) & W_KEY1], 57U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 14554U)) & W_KEY1], 21U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCarry, 24U)) + (RotL64(aCross, 41U) ^ RotL64(aIngress, 53U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterG = ((aWandererF + RotL64(aIngress, 3U)) + RotL64(aCarry, 19U)) + 9107326720193244489U;
            aOrbiterC = ((aWandererH + RotL64(aScatter, 51U)) + 10868585484401664145U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = (aWandererA + RotL64(aCross, 27U)) + 13637736741437846622U;
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 35U)) + RotL64(aCarry, 5U)) + 6130725216183918844U;
            aOrbiterB = (((aWandererI + RotL64(aScatter, 60U)) + RotL64(aCarry, 51U)) + 2063834478521338187U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = ((aWandererK + RotL64(aCross, 43U)) + 8564870627911949158U) + aNonceWordG;
            aOrbiterI = (aWandererC + RotL64(aIngress, 21U)) + 6524015751064086390U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 9874937766875388236U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 14723718409522680894U;
            aOrbiterK = RotL64((aOrbiterK * 17379140128833323431U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 13767059954741528279U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 6387608251033722169U;
            aOrbiterC = RotL64((aOrbiterC * 6601902195707980693U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 5391425980008431000U) + aNonceWordM;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 11524218415655093779U;
            aOrbiterG = RotL64((aOrbiterG * 12508457981779189389U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 155510463350385905U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 10554591788433641311U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5412084824127934293U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 8662160162966241542U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 5092555636369853727U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 433807340167635499U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 7163345798448796101U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 695089002178413267U;
            aOrbiterH = RotL64((aOrbiterH * 17302689458565434475U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 5409173939213468972U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 15349690077393827541U;
            aOrbiterI = RotL64((aOrbiterI * 10984681254001609841U), 51U);
            //
            aIngress = RotL64(aOrbiterA, 47U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterH, 27U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + RotL64(aOrbiterK, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aIngress, 37U) + RotL64(aOrbiterA, 3U)) + aOrbiterC) + aNonceWordE);
            aWandererF = aWandererF ^ ((((RotL64(aPrevious, 11U) + aOrbiterK) + RotL64(aOrbiterI, 30U)) + aNonceWordC) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 43U) + RotL64(aOrbiterK, 47U)) + aOrbiterA) + RotL64(aCarry, 19U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 19U) + aOrbiterB) + RotL64(aOrbiterG, 53U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 54U) + aOrbiterC) + RotL64(aOrbiterG, 19U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterH, 41U)) + aOrbiterK);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterK, 13U)) + aOrbiterC) + RotL64(aCarry, 43U)) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 41U) ^ aWandererK);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 26U));
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererA, 51U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ aNonceWordE;
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 16950U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((aIndex + 16858U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20736U)) & S_BLOCK1], 27U) ^ RotL64(mSource[((aIndex + 18912U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aPrevious, 60U)) ^ (RotL64(aIngress, 13U) + RotL64(aCarry, 27U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 35U)) + 5480870806135400132U) + aNonceWordN;
            aOrbiterF = (((aWandererJ + RotL64(aCross, 58U)) + RotL64(aCarry, 13U)) + 8034874599430768743U) + aNonceWordP;
            aOrbiterB = ((aWandererK + RotL64(aIngress, 5U)) + 4006919843736863767U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 27U)) + RotL64(aCarry, 27U)) + 2988069748674633718U;
            aOrbiterC = (((aWandererB + RotL64(aPrevious, 19U)) + RotL64(aCarry, 51U)) + 12347295651973135786U) + aNonceWordL;
            aOrbiterK = ((aWandererD + RotL64(aScatter, 43U)) + 14152683894431568192U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = (aWandererG + RotL64(aIngress, 51U)) + 15765143815254196598U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 10473067082331244233U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = (((aOrbiterB ^ aOrbiterH) ^ 1089466925383677249U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterB = RotL64((aOrbiterB * 17334888609179149753U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 13215039929873682230U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 3957997712247961479U;
            aOrbiterK = RotL64((aOrbiterK * 7631186240013784703U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 10023907397941685546U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 14593012591254614353U;
            aOrbiterF = RotL64((aOrbiterF * 17111300092082154687U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 13353797968154036726U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 9259966668512102858U;
            aOrbiterC = RotL64((aOrbiterC * 8326732574268308221U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 10757861831070349321U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 10530223113483866178U;
            aOrbiterH = RotL64((aOrbiterH * 11269177745265396583U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 7554320926405521865U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 6978052067277966996U;
            aOrbiterJ = RotL64((aOrbiterJ * 18020134738536217801U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 1053695861967171420U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 15980734683539854451U;
            aOrbiterI = RotL64((aOrbiterI * 3208466640010555357U), 53U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterB, 41U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 20U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 29U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterC, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aCross, 21U) + aOrbiterC) + RotL64(aOrbiterF, 11U)) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 42U) + aOrbiterI) + RotL64(aOrbiterH, 29U)) + aPhaseAWandererUpdateSaltB[((aIndex + 6U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 27U) + aOrbiterK) + RotL64(aOrbiterI, 3U)) + aNonceWordC);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterB, 43U)) + aOrbiterF);
            aWandererG = aWandererG + (((RotL64(aPrevious, 5U) + aOrbiterC) + RotL64(aOrbiterJ, 21U)) + RotL64(aCarry, 43U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterJ, 35U)) + aOrbiterB);
            aWandererJ = aWandererJ + (((RotL64(aCross, 13U) + RotL64(aOrbiterK, 56U)) + aOrbiterH) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 34U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererB, 53U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererG, 11U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordA);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 25887U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneA[((aIndex + 26346U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24136U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((aIndex + 24631U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 35U) ^ RotL64(aPrevious, 50U)) + (RotL64(aCross, 21U) + RotL64(aIngress, 3U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterH = ((aWandererD + RotL64(aIngress, 41U)) + RotL64(aCarry, 43U)) + 16651241552253078315U;
            aOrbiterE = (aWandererI + RotL64(aScatter, 19U)) + 4558144676982478003U;
            aOrbiterF = (aWandererJ + RotL64(aPrevious, 57U)) + 8814884320080367550U;
            aOrbiterC = (((aWandererC + RotL64(aCross, 51U)) + RotL64(aCarry, 19U)) + 16011579668555672117U) + aPhaseAOrbiterAssignSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterA = ((aWandererE + RotL64(aScatter, 12U)) + RotL64(aCarry, 57U)) + 4738918668759862438U;
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 5U)) + 12526083125540985108U) + aPhaseAOrbiterAssignSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = ((aWandererA + RotL64(aIngress, 35U)) + 8048723561746000552U) + aNonceWordG;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 1082218464034639039U) + aNonceWordI;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 8432043246965946816U;
            aOrbiterF = RotL64((aOrbiterF * 7801965585991025451U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 9982080524048636852U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 6720069955755215919U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1025046364205332059U), 57U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterG) + 1019035028070247757U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1]) + aNonceWordA;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 7360619079463870467U;
            aOrbiterC = RotL64((aOrbiterC * 6623074813047915863U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 10893918488381348474U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 1390297670907738019U;
            aOrbiterE = RotL64((aOrbiterE * 11909657437658597735U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 12512200589031203480U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 14741471280748399540U;
            aOrbiterA = RotL64((aOrbiterA * 3012135242889901095U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 8543897248359826770U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 8545972622733791272U;
            aOrbiterG = RotL64((aOrbiterG * 11793879362775346821U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 7049384618581928664U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 14730773807906925408U;
            aOrbiterB = RotL64((aOrbiterB * 10711566871536755073U), 35U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterE, 3U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 27U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 14U));
            aIngress = aIngress + RotL64(aOrbiterG, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 5U) + aOrbiterE) + RotL64(aOrbiterC, 5U));
            aWandererA = aWandererA + ((((RotL64(aPrevious, 51U) + aOrbiterA) + RotL64(aOrbiterC, 11U)) + RotL64(aCarry, 43U)) + aNonceWordN);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 13U) + aOrbiterC) + RotL64(aOrbiterH, 37U)) + aNonceWordP);
            aWandererC = aWandererC + (((RotL64(aCross, 43U) + RotL64(aOrbiterC, 27U)) + aOrbiterF) + RotL64(aCarry, 57U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 37U) + aOrbiterF) + RotL64(aOrbiterG, 19U)) + aPhaseAWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 23U) + RotL64(aOrbiterE, 57U)) + aOrbiterG);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 58U) + aOrbiterG) + RotL64(aOrbiterB, 50U)) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererD);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 4U));
            aCarry = aCarry + RotL64(aWandererJ, 19U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordO);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 32251U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27840U)) & S_BLOCK1], 36U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28653U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneB[((aIndex + 28193U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 3U) + RotL64(aIngress, 51U)) ^ (RotL64(aCarry, 19U) + RotL64(aPrevious, 36U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterE = ((aWandererJ + RotL64(aCross, 13U)) + RotL64(aCarry, 3U)) + 17225673071833726819U;
            aOrbiterF = (aWandererH + RotL64(aPrevious, 27U)) + 10301458382103627331U;
            aOrbiterA = (aWandererI + RotL64(aIngress, 35U)) + 3960233050857362414U;
            aOrbiterG = (((aWandererK + RotL64(aScatter, 41U)) + RotL64(aCarry, 35U)) + 17768665685046605837U) + aPhaseAOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = ((aWandererD + RotL64(aIngress, 21U)) + RotL64(aCarry, 53U)) + 14471018461213959767U;
            aOrbiterH = ((aWandererA + RotL64(aScatter, 47U)) + 10730597892721340453U) + aPhaseAOrbiterAssignSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 60U)) + 14863394003122760542U) + aNonceWordM;
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 9948587274816688296U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 3573569431435100993U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2303922230056523077U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 8153670675740450590U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 16438856577722561424U;
            aOrbiterK = RotL64((aOrbiterK * 4689247488336908827U), 29U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterK) + 15765587867581925041U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordI;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 1082039522061775213U;
            aOrbiterH = RotL64((aOrbiterH * 17023740047246402641U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 4202521649260798876U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 15877659681260461141U;
            aOrbiterD = RotL64((aOrbiterD * 11369910758551088173U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 2551560426129646123U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 3005102326163906320U;
            aOrbiterE = RotL64((aOrbiterE * 4241583192662435107U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 1675501058857208089U) + aNonceWordG;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 12774812270956702043U;
            aOrbiterG = RotL64((aOrbiterG * 5488437008504905105U), 35U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterG) + 1044886020922563597U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1]) + aNonceWordA;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 4857445127457225171U;
            aOrbiterF = RotL64((aOrbiterF * 13223560654459705259U), 13U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterF, 3U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 58U));
            aIngress = aIngress + (RotL64(aOrbiterG, 37U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterH, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterF, 19U)) + aOrbiterD) + aNonceWordE);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 5U) + RotL64(aOrbiterG, 43U)) + aOrbiterD) + RotL64(aCarry, 3U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterG, 29U)) + aOrbiterA);
            aWandererI = aWandererI + ((((RotL64(aCross, 47U) + aOrbiterH) + RotL64(aOrbiterK, 57U)) + aNonceWordH) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((((RotL64(aIngress, 41U) + RotL64(aOrbiterK, 13U)) + aOrbiterE) + aNonceWordB) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 58U) + RotL64(aOrbiterK, 37U)) + aOrbiterD) + RotL64(aCarry, 27U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterD, 6U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 34U));
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererI, 39U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordC);
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

void TwistExpander_Golf_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x869B5CA2AB10219DULL + 0xA00350B909465984ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x80F4754D45B389CDULL + 0xC2B291A592CFC3ECULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xB26C8B308932F46FULL + 0xB3C8994EFD857EE9ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xCC353ED09281C06BULL + 0x88C33F23B5FE6406ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xF9BBF2F5E6459FE7ULL + 0xCC20AFF87E52AFA8ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xBBDF1A419840CDB3ULL + 0x92505BF3FF4C0378ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xA74684BD2154D0ABULL + 0xE44C23DF9AF30CD5ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xB1ABE61959456447ULL + 0x941D318E0BC92410ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xDBFAE297086157DBULL + 0xD6B9F4821AD2FF90ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xF6AE5F7696FFF8B5ULL + 0xEE3D838F039ADA8BULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xF388089ECBC8BC77ULL + 0xEBB43A24DA7C11DAULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xA37939AFD4466DDBULL + 0xF20953A05C1501F9ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x846A4EAB6D4A9941ULL + 0xDD5037D5214C9F74ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x98B8E8A5F7633A91ULL + 0xC4ED7BE5C887ED17ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x87B19E77C74B1FD5ULL + 0xAF4D3A9B57CC0C84ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xD4347BDCB988A417ULL + 0x9D5E732B6B95048CULL);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 1766U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((aIndex + 3734U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2479U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneA[((aIndex + 1081U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 54U) + RotL64(aIngress, 5U)) ^ (RotL64(aPrevious, 21U) ^ RotL64(aCross, 37U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterE = (aWandererJ + RotL64(aScatter, 27U)) + 11521331427196538632U;
            aOrbiterB = (((aWandererE + RotL64(aIngress, 19U)) + RotL64(aCarry, 5U)) + 16653824187682957632U) + aPhaseBOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = ((aWandererK + RotL64(aCross, 43U)) + RotL64(aCarry, 37U)) + 11654676587350088289U;
            aOrbiterH = (aWandererH + RotL64(aPrevious, 5U)) + 8010313317412193584U;
            aOrbiterJ = ((((aWandererG + RotL64(aScatter, 52U)) + RotL64(aCarry, 53U)) + 1108775560502907471U) + aPhaseBOrbiterAssignSaltC[((aIndex + 12U)) & S_SALT1]) + aNonceWordI;
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 243952321439823521U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterE) ^ 2324945800401240403U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterA = RotL64((aOrbiterA * 9471328582043504473U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 9257554497543369657U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 16701314607244592540U;
            aOrbiterE = RotL64((aOrbiterE * 8790054741039817107U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 3900445848034341782U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 7652316487347103658U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11480123491361589799U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 14980368605272070578U) + aNonceWordN;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 2001165460948764796U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8110980921827107649U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 1911044015666991050U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 11366207111147818339U;
            aOrbiterJ = RotL64((aOrbiterJ * 17234439040652553865U), 23U);
            //
            aIngress = RotL64(aOrbiterJ, 19U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 29U));
            aIngress = aIngress + RotL64(aOrbiterE, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((((RotL64(aCross, 43U) + RotL64(aOrbiterE, 57U)) + aOrbiterJ) + RotL64(aCarry, 35U)) + aNonceWordA) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 12U) + RotL64(aOrbiterB, 3U)) + aOrbiterH) + aNonceWordG);
            aWandererG = aWandererG + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterA, 19U)) + aOrbiterE) + RotL64(aCarry, 11U));
            aWandererK = aWandererK ^ ((((RotL64(aScatter, 3U) + aOrbiterB) + RotL64(aOrbiterJ, 11U)) + aNonceWordH) + aPhaseBWandererUpdateSaltB[((aIndex + 20U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 35U) + aOrbiterE) + RotL64(aOrbiterH, 40U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + RotL64(aWandererK, 43U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 6979U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneD[((aIndex + 7972U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 10191U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((aIndex + 7993U)) & S_BLOCK1], 22U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 35U) + RotL64(aCarry, 6U)) ^ (RotL64(aCross, 51U) + RotL64(aIngress, 21U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterI = (((aWandererD + RotL64(aPrevious, 19U)) + RotL64(aCarry, 23U)) + 7896237440058555694U) + aNonceWordE;
            aOrbiterC = (((aWandererC + RotL64(aCross, 3U)) + RotL64(aCarry, 11U)) + 11870529476037558635U) + aNonceWordN;
            aOrbiterH = (((aWandererF + RotL64(aIngress, 47U)) + 9158983227801569448U) + aPhaseBOrbiterAssignSaltE[((aIndex + 28U)) & S_SALT1]) + aNonceWordC;
            aOrbiterD = (aWandererG + RotL64(aScatter, 38U)) + 4710172270996950329U;
            aOrbiterF = (((aWandererA + RotL64(aIngress, 57U)) + RotL64(aCarry, 37U)) + 14634482800356647630U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 8822207952170610891U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 13755891414028982553U;
            aOrbiterH = RotL64((aOrbiterH * 5173750624716006485U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 4555293067488040719U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 2816805148093762081U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16838149138341713943U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 2122631477965135190U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 4592922416380416071U) ^ aNonceWordH;
            aOrbiterI = RotL64((aOrbiterI * 11644507904538573165U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 7102471666524164715U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 17274623547879474204U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5443572270546181789U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 938587316977094680U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 18258015823797023523U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6068819567674605919U), 43U);
            //
            aIngress = RotL64(aOrbiterH, 43U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterI, 3U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((((RotL64(aCross, 26U) + aOrbiterC) + RotL64(aOrbiterI, 52U)) + RotL64(aCarry, 3U)) + aNonceWordL) + aPhaseBWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 41U) + aOrbiterF) + RotL64(aOrbiterH, 11U));
            aWandererG = aWandererG + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterC, 43U)) + aOrbiterD) + RotL64(aCarry, 27U)) + aPhaseBWandererUpdateSaltC[((aIndex + 22U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterH, 3U)) + aOrbiterD) + aNonceWordK);
            aWandererA = aWandererA + ((RotL64(aIngress, 53U) + RotL64(aOrbiterI, 27U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 30U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 41U));
            aCarry = aCarry + RotL64(aWandererA, 21U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ aNonceWordD;
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 16339U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((aIndex + 16310U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 12673U)) & S_BLOCK1], 18U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 12104U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 41U) + RotL64(aPrevious, 60U)) ^ (RotL64(aIngress, 23U) ^ RotL64(aCross, 11U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterB = (((aWandererE + RotL64(aPrevious, 41U)) + RotL64(aCarry, 53U)) + 13714409587461539863U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 3U)) + RotL64(aCarry, 35U)) + 14101156723903265839U;
            aOrbiterA = (aWandererD + RotL64(aScatter, 11U)) + 7063754562895369001U;
            aOrbiterF = (((aWandererK + RotL64(aCross, 23U)) + RotL64(aCarry, 5U)) + 12320578575245519386U) + aNonceWordN;
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 54U)) + 11744826789631008424U) + aPhaseBOrbiterAssignSaltB[((aIndex + 27U)) & S_SALT1];
            //
            aOrbiterB = (((aOrbiterB + aOrbiterH) + 8744816505096675597U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordB;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 10405435520084528645U;
            aOrbiterA = RotL64((aOrbiterA * 13279521344071568023U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 1463157688070683543U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 12379603577919617703U;
            aOrbiterH = RotL64((aOrbiterH * 14858901470015109311U), 53U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterF) + 1343439118031348146U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordF;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 16118850268070235540U) ^ aNonceWordM;
            aOrbiterB = RotL64((aOrbiterB * 11184386483735388257U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 14116264435819277136U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 5251698273012432109U;
            aOrbiterF = RotL64((aOrbiterF * 1495818611622063967U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 14806408656041403829U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 11569345414052398227U;
            aOrbiterJ = RotL64((aOrbiterJ * 9913158908301414861U), 39U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterF, 57U);
            aIngress = aIngress + (RotL64(aOrbiterH, 27U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterJ, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aIngress, 46U) + RotL64(aOrbiterB, 13U)) + aOrbiterF) + aNonceWordH);
            aWandererJ = aWandererJ + (((((RotL64(aPrevious, 29U) + aOrbiterF) + RotL64(aOrbiterA, 5U)) + RotL64(aCarry, 13U)) + aNonceWordL) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 13U) + aOrbiterH) + RotL64(aOrbiterA, 29U));
            aWandererK = aWandererK + ((((RotL64(aCross, 21U) + aOrbiterF) + RotL64(aOrbiterJ, 47U)) + RotL64(aCarry, 39U)) + aNonceWordG);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 37U) + aOrbiterJ) + RotL64(aOrbiterA, 58U)) + aPhaseBWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + RotL64(aWandererC, 11U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordN);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 18578U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21404U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19621U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19392U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aIngress, 38U)) ^ (RotL64(aPrevious, 53U) ^ RotL64(aCross, 3U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterF = (((aWandererB + RotL64(aIngress, 58U)) + RotL64(aCarry, 43U)) + 5573188770530340913U) + aPhaseBOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = (((aWandererI + RotL64(aCross, 47U)) + RotL64(aCarry, 23U)) + 1431772230889897111U) + aNonceWordH;
            aOrbiterC = ((aWandererK + RotL64(aScatter, 13U)) + 4809192776429682319U) + aNonceWordC;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 37U)) + RotL64(aCarry, 57U)) + 5576603692574369341U;
            aOrbiterE = ((aWandererA + RotL64(aIngress, 5U)) + 2720143226007220386U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            //
            aOrbiterF = (((aOrbiterF + aOrbiterA) + 17220328778565331629U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1]) + aNonceWordA;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 9629485808442089423U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 18349580416082045015U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 1136998437010390983U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 11893390497814523841U;
            aOrbiterF = RotL64((aOrbiterF * 5329621622743089531U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 1764986431917532370U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 1741014798007010376U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13414914086049500731U), 13U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterF) + 12221368453236547044U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordD;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 7694538641172350430U;
            aOrbiterA = RotL64((aOrbiterA * 8439120733670016501U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 17472344518811560603U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 3308740700728172984U;
            aOrbiterE = RotL64((aOrbiterE * 15290400462887712083U), 57U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterK, 54U);
            aIngress = aIngress + (RotL64(aOrbiterF, 41U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterE, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterK, 11U)) + aOrbiterF);
            aWandererI = aWandererI + ((((RotL64(aScatter, 11U) + aOrbiterC) + RotL64(aOrbiterK, 40U)) + RotL64(aCarry, 27U)) + aPhaseBWandererUpdateSaltD[((aIndex + 6U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aCross, 47U) + aOrbiterA) + RotL64(aOrbiterF, 3U)) + aNonceWordN);
            aWandererB = aWandererB + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterK, 53U)) + aOrbiterE) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 38U) + RotL64(aOrbiterC, 19U)) + aOrbiterA) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 40U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererJ, 29U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordG);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 27019U)) & S_BLOCK1], 12U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 23936U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24015U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23434U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 51U) + RotL64(aIngress, 23U)) ^ (RotL64(aCarry, 6U) ^ RotL64(aPrevious, 39U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterI = (((aWandererI + RotL64(aScatter, 19U)) + 15652862298542575895U) + aPhaseBOrbiterAssignSaltA[((aIndex + 24U)) & S_SALT1]) + aNonceWordE;
            aOrbiterH = (aWandererJ + RotL64(aIngress, 27U)) + 16925323928418184554U;
            aOrbiterG = (((aWandererB + RotL64(aCross, 37U)) + RotL64(aCarry, 41U)) + 4413861484961668394U) + aNonceWordK;
            aOrbiterE = ((((aWandererK + RotL64(aPrevious, 46U)) + RotL64(aCarry, 27U)) + 2215946422098155969U) + aPhaseBOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1]) + aNonceWordM;
            aOrbiterA = ((aWandererA + RotL64(aIngress, 5U)) + RotL64(aCarry, 57U)) + 14975185533513111110U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 9711613814905834552U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = (((aOrbiterG ^ aOrbiterI) ^ 13154957291850149471U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterG = RotL64((aOrbiterG * 17049677190793844477U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 5058313016418534840U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 15011423472941211620U;
            aOrbiterA = RotL64((aOrbiterA * 6125316151731105673U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 2030053257469580168U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 150530795186791193U;
            aOrbiterI = RotL64((aOrbiterI * 11106050063717096073U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 10878237472104183427U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 11724672539469573109U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16158741837357985395U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 9589700906445846956U) + aNonceWordH;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 1367381624958248949U;
            aOrbiterE = RotL64((aOrbiterE * 8459515089081211977U), 5U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterH, 21U);
            aIngress = aIngress + (RotL64(aOrbiterE, 46U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterA, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aIngress, 37U) + aOrbiterI) + RotL64(aOrbiterH, 5U));
            aWandererB = aWandererB + ((((RotL64(aScatter, 5U) + RotL64(aOrbiterG, 30U)) + aOrbiterA) + RotL64(aCarry, 3U)) + aNonceWordA);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 27U) + aOrbiterA) + RotL64(aOrbiterI, 43U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 48U) + aOrbiterE) + RotL64(aOrbiterG, 53U)) + RotL64(aCarry, 39U)) + aNonceWordF);
            aWandererK = aWandererK ^ ((((RotL64(aIngress, 57U) + RotL64(aOrbiterH, 21U)) + aOrbiterA) + aNonceWordD) + aPhaseBWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererJ, 21U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererK, 13U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ aNonceWordF;
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 31182U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28108U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 28145U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31614U)) & S_BLOCK1], 44U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 27U) ^ RotL64(aIngress, 52U)) ^ (RotL64(aPrevious, 3U) + RotL64(aCross, 39U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterG = ((aWandererD + RotL64(aCross, 39U)) + RotL64(aCarry, 57U)) + 8020711767807230555U;
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 57U)) + RotL64(aCarry, 43U)) + 15368693777246341570U;
            aOrbiterE = (((aWandererJ + RotL64(aScatter, 5U)) + RotL64(aCarry, 23U)) + 5117523734225562401U) + aPhaseBOrbiterAssignSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterJ = (((aWandererI + RotL64(aIngress, 14U)) + 13155269151097507808U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordF;
            aOrbiterD = ((aWandererK + RotL64(aScatter, 23U)) + 9879303753623578272U) + aNonceWordC;
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 1165799257173794826U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 930641942062732091U) ^ aNonceWordH;
            aOrbiterE = RotL64((aOrbiterE * 17151944851548731159U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 11330571332221123153U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 2862963158282518899U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13782195862525974199U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 6019186399361476659U) + aNonceWordK;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 1924419843785161958U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9485557122500346869U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 12618629043591380461U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 9334176504266512405U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 18239109235362925739U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 16829692481030013551U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 5604784396927022709U) ^ aNonceWordA;
            aOrbiterD = RotL64((aOrbiterD * 2833893610883508353U), 5U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterG, 13U);
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterE, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aCross, 3U) + RotL64(aOrbiterE, 11U)) + aOrbiterG) + RotL64(aCarry, 13U));
            aWandererD = aWandererD ^ ((((RotL64(aPrevious, 19U) + aOrbiterJ) + RotL64(aOrbiterI, 26U)) + aNonceWordE) + aPhaseBWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aIngress, 11U) + aOrbiterI) + RotL64(aOrbiterG, 3U)) + RotL64(aCarry, 47U)) + aPhaseBWandererUpdateSaltF[((aIndex + 6U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 28U) + aOrbiterD) + RotL64(aOrbiterI, 53U)) + aNonceWordB);
            aWandererB = aWandererB + ((RotL64(aIngress, 53U) + aOrbiterE) + RotL64(aOrbiterJ, 39U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 48U));
            aCarry = aCarry + (RotL64(aWandererI, 11U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererK, 57U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordN);
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

void TwistExpander_Golf_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xFE609E37EAC2705BULL + 0xFE76FC8A041A7391ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xFFAF4A3106C6D503ULL + 0x8A0D5A7D6EE3A770ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xCFD25161F5207DA9ULL + 0xBE115DF06C41DA7DULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xB91C1222AF4EEFF9ULL + 0xE39081BA848317CCULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xEB823E0E808F0D43ULL + 0xF28848FA6F7D3F8FULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xC856815FC853822BULL + 0xD798E359A2530DA5ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xF4161C2F2DAE46BFULL + 0x9845F05A485CAFF8ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xD65DE333FD45253FULL + 0xA6E1BB2810757074ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x802F08BA6D6BECD1ULL + 0x849CC4698CED566CULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x980950D826C5968BULL + 0xDBF11A3B17D2FEBAULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xCF4728AEF4F6980DULL + 0xF1BC1DD062971315ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xF6B7E61DB59D00A9ULL + 0xCE16E8E70AEB382EULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xD61839CC92819E83ULL + 0x9220644193826A99ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x94A162A27CC6CE5FULL + 0xF1F787A6ACB3DCF5ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xABB4458B65D1CF5FULL + 0x99C011CF84EC0472ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xC494219ACFDEE93DULL + 0xE9A68AEA0971E3EFULL);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 218U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneC[((aIndex + 7417U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 1569U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 1205U)) & S_BLOCK1], 22U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCarry, 5U)) + (RotL64(aCross, 18U) ^ RotL64(aPrevious, 41U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 58U)) + RotL64(aCarry, 41U)) + 13296600294247799698U;
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 41U)) + RotL64(aCarry, 27U)) + 5818503518080877515U;
            aOrbiterD = (aWandererC + RotL64(aScatter, 5U)) + 6735784238734173597U;
            aOrbiterA = ((aWandererI + RotL64(aCross, 47U)) + 7368398209488856201U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = (aWandererG + RotL64(aIngress, 51U)) + 961734029066455638U;
            aOrbiterE = (aWandererK + RotL64(aPrevious, 37U)) + 797011946660892011U;
            aOrbiterJ = ((aWandererB + RotL64(aCross, 29U)) + 12841876018396622350U) + aNonceWordO;
            aOrbiterG = (((aWandererA + RotL64(aScatter, 13U)) + RotL64(aCarry, 11U)) + 16213253970483895623U) + aPhaseCOrbiterAssignSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = (aWandererD + RotL64(aIngress, 18U)) + 15186950557113470375U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 5117930310827477341U) + aNonceWordC;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 12265429373166094162U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1522823535151532249U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 13920531346698601568U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 14695405206998211456U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13950964363414164279U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 7851960904825938443U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 9501511171732550190U;
            aOrbiterG = RotL64((aOrbiterG * 5614164120361489613U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 5663365182245722077U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 9607860124321315555U;
            aOrbiterB = RotL64((aOrbiterB * 3461820361914280601U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 18171052650586819280U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 3442698321538580861U;
            aOrbiterF = RotL64((aOrbiterF * 6317525514963824829U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 1491052813469258970U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 3956599824067616133U;
            aOrbiterA = RotL64((aOrbiterA * 2928600779267623085U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 10963841237346073453U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 2303020125591252534U;
            aOrbiterJ = RotL64((aOrbiterJ * 9969099842343321981U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 14503856057958162356U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 11147548150090597694U;
            aOrbiterH = RotL64((aOrbiterH * 11856382308792700441U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 9191681438318311481U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 13556072770381999852U;
            aOrbiterK = RotL64((aOrbiterK * 18316231099054203683U), 57U);
            //
            aIngress = RotL64(aOrbiterH, 39U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterD, 13U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterA, 21U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 52U));
            aIngress = aIngress + RotL64(aOrbiterJ, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 3U) + aOrbiterF) + RotL64(aOrbiterG, 30U));
            aWandererG = aWandererG + (((RotL64(aCross, 19U) + aOrbiterD) + RotL64(aOrbiterJ, 43U)) + aNonceWordE);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 38U) + RotL64(aOrbiterJ, 11U)) + aOrbiterB) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterF, 39U)) + aOrbiterJ) + RotL64(aCarry, 39U)) + aNonceWordI);
            aWandererF = aWandererF ^ ((RotL64(aCross, 43U) + aOrbiterA) + RotL64(aOrbiterB, 60U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterE, 19U)) + aOrbiterD);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 60U) + aOrbiterD) + RotL64(aOrbiterK, 47U)) + aNonceWordA);
            aWandererB = aWandererB + (((RotL64(aScatter, 11U) + RotL64(aOrbiterG, 23U)) + aOrbiterK) + RotL64(aCarry, 13U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 51U) + aOrbiterE) + RotL64(aOrbiterH, 51U)) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + (RotL64(aWandererF, 53U) ^ aWandererC);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 50U));
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererB, 57U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordH);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 13832U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneD[((aIndex + 14510U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 9813U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 13780U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 54U) + RotL64(aCarry, 41U)) ^ (RotL64(aPrevious, 19U) ^ RotL64(aCross, 5U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterB = (aWandererH + RotL64(aScatter, 14U)) + 4773124477323378268U;
            aOrbiterD = (aWandererB + RotL64(aCross, 19U)) + 16848723289435796005U;
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 27U)) + 13846642134917107058U) + aNonceWordG;
            aOrbiterC = (aWandererG + RotL64(aIngress, 23U)) + 6472057872482789939U;
            aOrbiterJ = (aWandererJ + RotL64(aCross, 37U)) + 2747019500690707226U;
            aOrbiterE = ((aWandererF + RotL64(aScatter, 58U)) + RotL64(aCarry, 19U)) + 9003965289739733880U;
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 41U)) + 3013390651936257377U) + aPhaseCOrbiterAssignSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = ((aWandererE + RotL64(aIngress, 47U)) + RotL64(aCarry, 39U)) + 3331004709895625067U;
            aOrbiterA = ((((aWandererA + RotL64(aPrevious, 53U)) + RotL64(aCarry, 29U)) + 15355010435553517129U) + aPhaseCOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1]) + aNonceWordH;
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 7709870658004280052U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 13568728443963926564U;
            aOrbiterH = RotL64((aOrbiterH * 6736090830113688981U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 12409548853419307131U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 969183352023661537U;
            aOrbiterJ = RotL64((aOrbiterJ * 5549220554838837145U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 15370309834426476775U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 3896803894396631184U;
            aOrbiterI = RotL64((aOrbiterI * 11018830202891911603U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 10848873633291935766U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 12885336509190543440U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1487357252619221365U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 8252290890093788010U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 9201553615601641350U;
            aOrbiterA = RotL64((aOrbiterA * 420321130559162915U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 14014209645503188472U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterJ) ^ 4015071464301844550U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterB = RotL64((aOrbiterB * 17444195018239904971U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 16173085647514027347U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 16916627014974363360U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7699587344277490953U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 1591680303404522110U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 16499606051269327916U;
            aOrbiterE = RotL64((aOrbiterE * 814405848002794813U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 6932673635509444619U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 8745681160108707944U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14565255558668084787U), 43U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterE, 3U);
            aIngress = aIngress + (RotL64(aOrbiterC, 47U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 11U));
            aIngress = aIngress + (RotL64(aOrbiterB, 22U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterD, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 13U) + aOrbiterC) + RotL64(aOrbiterJ, 35U));
            aWandererC = aWandererC + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterE, 58U)) + aOrbiterI) + RotL64(aCarry, 21U)) + aNonceWordF);
            aWandererH = aWandererH ^ (((RotL64(aCross, 50U) + RotL64(aOrbiterA, 19U)) + aOrbiterD) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 19U) + RotL64(aOrbiterD, 27U)) + aOrbiterJ);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterH, 47U)) + aOrbiterC) + aPhaseCWandererUpdateSaltF[((aIndex + 16U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterF, 23U)) + aOrbiterC);
            aWandererG = aWandererG ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterB, 10U)) + aOrbiterF);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 23U) + RotL64(aOrbiterI, 41U)) + aOrbiterA) + RotL64(aCarry, 37U)) + aNonceWordE);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 6U) + RotL64(aOrbiterH, 51U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + (RotL64(aWandererC, 30U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 41U));
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererF, 19U);
            aCarry = aCarry + RotL64(aIngress, 38U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordO);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 23146U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((aIndex + 16397U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 22505U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneC[((aIndex + 20872U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 54U) ^ RotL64(aIngress, 3U)) + (RotL64(aPrevious, 37U) ^ RotL64(aCross, 21U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 4U)) + RotL64(aCarry, 35U)) + 6361545377408870615U;
            aOrbiterF = (aWandererJ + RotL64(aScatter, 13U)) + 2967245486744774933U;
            aOrbiterG = ((aWandererH + RotL64(aCross, 23U)) + 3836634268482850139U) + aNonceWordJ;
            aOrbiterK = (aWandererC + RotL64(aIngress, 29U)) + 7691642115360086297U;
            aOrbiterA = ((aWandererB + RotL64(aScatter, 46U)) + RotL64(aCarry, 21U)) + 16479280384178279281U;
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 53U)) + 2901468732552539249U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterB = (aWandererK + RotL64(aCross, 57U)) + 2600353867755647475U;
            aOrbiterC = ((aWandererG + RotL64(aIngress, 35U)) + RotL64(aCarry, 5U)) + 5666596904781510956U;
            aOrbiterD = ((aWandererE + RotL64(aScatter, 41U)) + 16108791609267427553U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 8389926875737312112U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 1689501721163024426U;
            aOrbiterG = RotL64((aOrbiterG * 6517194895779049139U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 11721701506949917719U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 3963842745030140473U;
            aOrbiterI = RotL64((aOrbiterI * 6692473494944919373U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 8510538243472109368U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 18281865214102080387U;
            aOrbiterK = RotL64((aOrbiterK * 1351546966368884609U), 27U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterB) + 2259725140963665123U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordF;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 11652011949557979650U) ^ aNonceWordP;
            aOrbiterF = RotL64((aOrbiterF * 11260100762113295037U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 1116085424226174473U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 4725260319270802912U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4697109059565450269U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 7348945429843437036U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 1249234309180653260U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3136745255820405881U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 12463505532573389603U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 2304125977906510386U;
            aOrbiterB = RotL64((aOrbiterB * 9960816714791454421U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 2178037443783425551U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 11712110130079307683U;
            aOrbiterC = RotL64((aOrbiterC * 9797864956200779505U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 10703510612147312252U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 18155460326242413483U;
            aOrbiterD = RotL64((aOrbiterD * 6903953708987478723U), 51U);
            //
            aIngress = RotL64(aOrbiterA, 56U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 47U));
            aIngress = aIngress + (RotL64(aOrbiterI, 11U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + RotL64(aOrbiterK, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 37U) + RotL64(aOrbiterE, 12U)) + aOrbiterF);
            aWandererH = aWandererH ^ ((RotL64(aCross, 56U) + aOrbiterI) + RotL64(aOrbiterC, 29U));
            aWandererF = aWandererF + (((RotL64(aScatter, 41U) + aOrbiterG) + RotL64(aOrbiterF, 47U)) + RotL64(aCarry, 11U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterE, 57U)) + aOrbiterB);
            aWandererA = aWandererA + (((RotL64(aScatter, 19U) + aOrbiterD) + RotL64(aOrbiterB, 23U)) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 46U) + RotL64(aOrbiterK, 5U)) + aOrbiterI);
            aWandererK = aWandererK + (((RotL64(aCross, 3U) + aOrbiterA) + RotL64(aOrbiterI, 52U)) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 51U) + aOrbiterD) + RotL64(aOrbiterI, 43U)) + aNonceWordE);
            aWandererB = aWandererB + (((RotL64(aCross, 29U) + RotL64(aOrbiterF, 39U)) + aOrbiterK) + aPhaseCWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererC, 21U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 60U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererB, 35U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ aNonceWordE;
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 31960U)) & S_BLOCK1], 38U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25154U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26462U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneD[((aIndex + 32465U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aPrevious, 51U)) ^ (RotL64(aIngress, 14U) + RotL64(aCross, 27U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 47U)) + 16519040829220310189U) + aNonceWordC;
            aOrbiterD = (aWandererJ + RotL64(aIngress, 53U)) + 6888002778416941825U;
            aOrbiterC = ((aWandererC + RotL64(aScatter, 60U)) + 1310832187746534025U) + aNonceWordL;
            aOrbiterI = ((aWandererE + RotL64(aCross, 27U)) + RotL64(aCarry, 57U)) + 5890888009051281674U;
            aOrbiterA = (((aWandererI + RotL64(aPrevious, 13U)) + RotL64(aCarry, 41U)) + 5143864838362464857U) + aNonceWordJ;
            aOrbiterG = ((aWandererG + RotL64(aIngress, 3U)) + 15591534069452660003U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = (aWandererA + RotL64(aCross, 42U)) + 1466867671765325096U;
            aOrbiterK = ((aWandererK + RotL64(aScatter, 35U)) + RotL64(aCarry, 27U)) + 13931443680107902488U;
            aOrbiterH = ((aWandererB + RotL64(aCross, 21U)) + 15400747367673245552U) + aPhaseCOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 2836975369734495759U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 2370720358274970117U;
            aOrbiterC = RotL64((aOrbiterC * 4615571902817575375U), 19U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterC) + 3470677184188006133U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordA;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 7175584278499266723U;
            aOrbiterA = RotL64((aOrbiterA * 10067096593682482345U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 6095078817776863055U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 2176637999243513070U;
            aOrbiterE = RotL64((aOrbiterE * 12215701810843975501U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 5580391239754903129U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 15196125567953871184U;
            aOrbiterJ = RotL64((aOrbiterJ * 12686361960729564519U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 12787014151503209931U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 1523153207064063495U;
            aOrbiterI = RotL64((aOrbiterI * 3113907543551927561U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 12973289026485937829U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 9087439766232078173U;
            aOrbiterG = RotL64((aOrbiterG * 5817029335999350327U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 16318022893068674015U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 11089160685103562409U;
            aOrbiterK = RotL64((aOrbiterK * 17087834321385147603U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 8680037953925067235U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterA) ^ 3112588943274158119U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterH = RotL64((aOrbiterH * 9214011370307670371U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 16749015684369649821U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 9419550535891334966U) ^ aNonceWordH;
            aOrbiterD = RotL64((aOrbiterD * 5421312787569114811U), 27U);
            //
            aIngress = RotL64(aOrbiterK, 47U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterI, 5U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterC, 26U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterD, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterC, 39U)) + aOrbiterA) + aNonceWordD);
            aWandererA = aWandererA + ((((RotL64(aScatter, 22U) + RotL64(aOrbiterC, 47U)) + aOrbiterK) + RotL64(aCarry, 19U)) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 37U) + aOrbiterD) + RotL64(aOrbiterH, 35U));
            aWandererI = aWandererI + ((((RotL64(aIngress, 13U) + aOrbiterE) + RotL64(aOrbiterA, 52U)) + aNonceWordO) + aPhaseCWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 47U) + aOrbiterA) + RotL64(aOrbiterK, 43U));
            aWandererC = aWandererC + ((RotL64(aCross, 51U) + RotL64(aOrbiterG, 3U)) + aOrbiterI);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 6U) + aOrbiterG) + RotL64(aOrbiterC, 19U));
            aWandererG = aWandererG + ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterE, 14U)) + aOrbiterH) + RotL64(aCarry, 3U)) + aNonceWordN);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 43U) + aOrbiterE) + RotL64(aOrbiterJ, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererK);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 29U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 42U));
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererB, 57U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ aNonceWordI;
            aCarry = TwistMix64::DiffuseB(aCarry);
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

void TwistExpander_Golf_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xCA74CEA8C1B516E3ULL + 0xDF310BEB4675D0C5ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x8DE59B936BCA82A1ULL + 0x963B7234F70A943BULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xAC6245C7C81E45B9ULL + 0x9B59324035B2DF17ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xFA4022EB8970BDCFULL + 0x9A07D64C02F41771ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x81E2E8B7BC55A595ULL + 0xB869ECE6FB5E0C90ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xC858307C4FD75EFFULL + 0x8E45564B5517ACE7ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xF8A4854A31ABE0E7ULL + 0xE8E55E67306FAE96ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xF5FD9C135329974DULL + 0xA590472B48A70A2EULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xB277DD386FBF440BULL + 0xD9A9D26F52C39A63ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xDD505AED9E245B35ULL + 0xCC1EB9FF9BDE6ABCULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xF47134D0664F2561ULL + 0x94837D7893B60FF8ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xBF399A345B959FA1ULL + 0x9E873268D327E704ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xBB0CC853B0051B6FULL + 0xF15BAEB49AE24528ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x9651B2AC5C9C07C7ULL + 0xCDA4D4250BC199A9ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x9A5FFE4F5FADD36BULL + 0xF7CA31FE9DCEA9D7ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xF89E2479D2213FAFULL + 0xFFC6B63A2B4B734BULL);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 1953U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneC[((aIndex + 1258U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 88U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 5054U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 29U) ^ RotL64(aCarry, 43U)) ^ (RotL64(aPrevious, 56U) + RotL64(aCross, 13U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterK = (((aWandererH + RotL64(aIngress, 12U)) + RotL64(aCarry, 37U)) + 6467297102954816305U) + aNonceWordP;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 39U)) + RotL64(aCarry, 13U)) + 7921154109831114952U;
            aOrbiterJ = (aWandererI + RotL64(aCross, 29U)) + 5701131763215638919U;
            aOrbiterE = (aWandererG + RotL64(aScatter, 19U)) + 10022999076719002684U;
            aOrbiterF = (aWandererD + RotL64(aCross, 47U)) + 4367135243038982316U;
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 53U)) + 14445846824810383592U) + aPhaseDOrbiterAssignSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterI = ((aWandererA + RotL64(aScatter, 26U)) + 7683697954545773253U) + aNonceWordH;
            aOrbiterG = (aWandererK + RotL64(aIngress, 35U)) + 17517006750428030899U;
            aOrbiterC = (aWandererJ + RotL64(aScatter, 5U)) + 2052484792684025476U;
            aOrbiterH = (((aWandererB + RotL64(aCross, 3U)) + RotL64(aCarry, 3U)) + 6279463052085808926U) + aPhaseDOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = (aWandererF + RotL64(aIngress, 51U)) + 679280153651813684U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 2939516520188460569U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 1960616434964712325U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15145998415466343039U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 12273819390719947361U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 5685033154709449397U) ^ aNonceWordE;
            aOrbiterB = RotL64((aOrbiterB * 9845666295874714959U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 9314494172199500653U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 15757631834636427621U;
            aOrbiterK = RotL64((aOrbiterK * 15483543888965744529U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 10878078046389399574U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 3583495913766365232U;
            aOrbiterE = RotL64((aOrbiterE * 2913540984990155225U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 7385544065754622301U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterA) ^ 16839599460207922881U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterI = RotL64((aOrbiterI * 240651605910592561U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 13038163804940349251U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 2587538594933924000U;
            aOrbiterC = RotL64((aOrbiterC * 3091149760401278671U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 13109518583364738004U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 2447689055742474261U;
            aOrbiterA = RotL64((aOrbiterA * 12100180201235703193U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 5752044906692668618U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 6637725371036522120U;
            aOrbiterD = RotL64((aOrbiterD * 6021986525167161115U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 16549229877442298618U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 12825651879441561108U;
            aOrbiterF = RotL64((aOrbiterF * 9079931351967033993U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 16088338999978085987U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 12584648360998154782U;
            aOrbiterG = RotL64((aOrbiterG * 2109996837220975261U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 7526256599938771686U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 6467297102954816305U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9289442676936248653U), 29U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterH, 35U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 24U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 27U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 41U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterK, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aCross, 57U) + RotL64(aOrbiterH, 23U)) + aOrbiterB) + aNonceWordK);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 30U) + aOrbiterK) + RotL64(aOrbiterG, 6U)) + aPhaseDWandererUpdateSaltF[((aIndex + 12U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 5U) + aOrbiterK) + RotL64(aOrbiterI, 51U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterF, 57U)) + aOrbiterK);
            aWandererA = aWandererA + ((RotL64(aScatter, 3U) + aOrbiterH) + RotL64(aOrbiterI, 35U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 37U) + aOrbiterD) + RotL64(aOrbiterK, 27U));
            aWandererK = aWandererK + (((((RotL64(aPrevious, 35U) + RotL64(aOrbiterC, 47U)) + aOrbiterI) + RotL64(aCarry, 39U)) + aNonceWordG) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 53U) + aOrbiterI) + RotL64(aOrbiterE, 44U)) + aNonceWordM);
            aWandererI = aWandererI + ((RotL64(aIngress, 51U) + RotL64(aOrbiterJ, 29U)) + aOrbiterA);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterK, 3U)) + aOrbiterB);
            aWandererD = aWandererD + (((RotL64(aCross, 28U) + aOrbiterJ) + RotL64(aOrbiterC, 19U)) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 41U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererF, 18U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererJ, 53U);
            aCarry = aCarry + RotL64(aIngress, 30U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordM);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 8667U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneD[((aIndex + 5829U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9055U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 7251U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aPrevious, 23U)) ^ (RotL64(aIngress, 36U) + RotL64(aCross, 5U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterD = (aWandererI + RotL64(aScatter, 11U)) + 14157904117287696136U;
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 23U)) + 7369512677371640676U) + aNonceWordB;
            aOrbiterG = ((aWandererJ + RotL64(aCross, 37U)) + RotL64(aCarry, 19U)) + 8411250745902073798U;
            aOrbiterF = (aWandererH + RotL64(aIngress, 35U)) + 5002041814539710275U;
            aOrbiterI = (aWandererE + RotL64(aPrevious, 50U)) + 9538041410816283124U;
            aOrbiterK = ((aWandererG + RotL64(aScatter, 39U)) + RotL64(aCarry, 47U)) + 5210700103927513061U;
            aOrbiterA = ((aWandererK + RotL64(aIngress, 21U)) + 7600709399101287982U) + aPhaseDOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = ((aWandererF + RotL64(aCross, 47U)) + 2366369466696580499U) + aNonceWordL;
            aOrbiterH = (aWandererC + RotL64(aPrevious, 56U)) + 5544575244203019109U;
            aOrbiterJ = (((aWandererA + RotL64(aIngress, 41U)) + RotL64(aCarry, 27U)) + 8710073749110329779U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = ((aWandererB + RotL64(aScatter, 13U)) + 15998211310115361630U) + aNonceWordC;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 15354357553877376422U) + aNonceWordM;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 10657523549259276169U;
            aOrbiterG = RotL64((aOrbiterG * 13695239532898311073U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 10405750198355464768U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 3465819693133515142U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14678343718277562799U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 16724189641701408630U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 3484340153620198872U;
            aOrbiterI = RotL64((aOrbiterI * 17247547677520703125U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 7420442404884871126U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 11138445997256757636U;
            aOrbiterA = RotL64((aOrbiterA * 11167543379937571127U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 1428191560884663125U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 16950093140800653985U;
            aOrbiterH = RotL64((aOrbiterH * 4423012306984814805U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 17288299075036481960U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 13793597915359681028U;
            aOrbiterD = RotL64((aOrbiterD * 9639204979982125757U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 5017972942710079726U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 12409957957614320964U;
            aOrbiterF = RotL64((aOrbiterF * 10273295741911545745U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 12487994181992095174U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 1573393166996612118U;
            aOrbiterK = RotL64((aOrbiterK * 13364311829104520751U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 13227642825780350128U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 7961292096150889569U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16627209081334341289U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 10312485102088913337U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 3177620041478410950U;
            aOrbiterJ = RotL64((aOrbiterJ * 15918551366833593853U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 2599092792737616563U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 14157904117287696136U;
            aOrbiterE = RotL64((aOrbiterE * 14883446269291639813U), 23U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterK, 28U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 47U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 5U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 13U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 21U));
            aIngress = aIngress + RotL64(aOrbiterI, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterH, 39U)) + aOrbiterK);
            aWandererE = aWandererE + (((RotL64(aCross, 56U) + RotL64(aOrbiterH, 14U)) + aOrbiterC) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 51U) + aOrbiterE) + RotL64(aOrbiterI, 37U));
            aWandererH = aWandererH + (((RotL64(aIngress, 53U) + RotL64(aOrbiterA, 53U)) + aOrbiterF) + RotL64(aCarry, 5U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterI, 23U)) + aOrbiterJ) + aPhaseDWandererUpdateSaltD[((aIndex + 12U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 27U) + RotL64(aOrbiterC, 30U)) + aOrbiterI) + aNonceWordJ);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 13U) + aOrbiterI) + RotL64(aOrbiterB, 21U));
            aWandererF = aWandererF + (((RotL64(aCross, 3U) + RotL64(aOrbiterK, 51U)) + aOrbiterC) + aNonceWordO);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterE, 35U)) + aOrbiterG);
            aWandererA = aWandererA + (((RotL64(aCross, 10U) + RotL64(aOrbiterJ, 57U)) + aOrbiterF) + RotL64(aCarry, 27U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 21U) + aOrbiterE) + RotL64(aOrbiterD, 43U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 42U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 39U));
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 48U));
            aCarry = aCarry + RotL64(aWandererF, 21U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ aNonceWordF;
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 13919U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 16264U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 14699U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 12716U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCross, 27U)) + (RotL64(aCarry, 39U) ^ RotL64(aIngress, 14U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterC = (aWandererJ + RotL64(aCross, 27U)) + 16183871922837164759U;
            aOrbiterI = (aWandererA + RotL64(aScatter, 5U)) + 7002058258090219055U;
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 23U)) + 5650868611888303705U) + aPhaseDOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = ((aWandererD + RotL64(aIngress, 47U)) + 11899839660943876690U) + aNonceWordB;
            aOrbiterE = ((aWandererF + RotL64(aCross, 11U)) + RotL64(aCarry, 39U)) + 15349649504488111111U;
            aOrbiterG = (aWandererE + RotL64(aScatter, 20U)) + 14060149569086744970U;
            aOrbiterB = ((aWandererI + RotL64(aIngress, 51U)) + 12920917574225030112U) + aPhaseDOrbiterAssignSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 13U)) + RotL64(aCarry, 29U)) + 2831994965175330135U;
            aOrbiterJ = ((aWandererG + RotL64(aIngress, 39U)) + RotL64(aCarry, 47U)) + 18312543585028439192U;
            aOrbiterH = (aWandererC + RotL64(aScatter, 58U)) + 11657562205118394239U;
            aOrbiterD = ((aWandererK + RotL64(aCross, 3U)) + 10850792819281246052U) + aNonceWordO;
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 17810371216216125323U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 7963413941144223128U;
            aOrbiterF = RotL64((aOrbiterF * 534217972450595401U), 51U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterE) + 5498715358793875584U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordC;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 9256727548911651373U;
            aOrbiterG = RotL64((aOrbiterG * 10498848323914000989U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 17246360111302191699U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 18309978718113983369U;
            aOrbiterI = RotL64((aOrbiterI * 18267472694666221077U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 3100998994319502921U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 8129301860291235970U;
            aOrbiterE = RotL64((aOrbiterE * 17847033539279176187U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 1889641029473279114U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 16538494307002917945U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8081488217920885783U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 5432230549146849322U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 2634437941396090817U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7612999214758935211U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 16940172599174185058U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 13151669140593952203U;
            aOrbiterC = RotL64((aOrbiterC * 16225319638131723487U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 3995064294869931681U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 913081077665768816U;
            aOrbiterA = RotL64((aOrbiterA * 9299514648768060453U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 2469001696075411481U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 2167390955194185443U;
            aOrbiterB = RotL64((aOrbiterB * 11805065572289005223U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 1574066406534010796U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 8736976961589874013U;
            aOrbiterJ = RotL64((aOrbiterJ * 5980070607180321955U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 4233621443153132083U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 16183871922837164759U;
            aOrbiterD = RotL64((aOrbiterD * 4030569514959370895U), 57U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterE, 48U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 21U));
            aIngress = aIngress + (RotL64(aOrbiterH, 5U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 3U));
            aIngress = aIngress + (RotL64(aOrbiterK, 39U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterJ, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aIngress, 37U) + RotL64(aOrbiterH, 11U)) + aOrbiterI) + RotL64(aCarry, 53U)) + aNonceWordI);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 13U) + aOrbiterK) + RotL64(aOrbiterB, 27U));
            aWandererD = aWandererD + (((RotL64(aCross, 60U) + aOrbiterJ) + RotL64(aOrbiterD, 56U)) + aNonceWordA);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 53U) + aOrbiterH) + RotL64(aOrbiterC, 35U));
            aWandererA = aWandererA + (((RotL64(aIngress, 27U) + aOrbiterF) + RotL64(aOrbiterG, 43U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 51U) + aOrbiterD) + RotL64(aOrbiterF, 29U));
            aWandererF = aWandererF + (((RotL64(aCross, 5U) + aOrbiterB) + RotL64(aOrbiterD, 41U)) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 56U) + RotL64(aOrbiterJ, 39U)) + aOrbiterB);
            aWandererI = aWandererI + (((RotL64(aCross, 23U) + RotL64(aOrbiterE, 19U)) + aOrbiterD) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterI, 58U)) + aOrbiterA) + aNonceWordD);
            aWandererG = aWandererG + ((RotL64(aPrevious, 11U) + aOrbiterA) + RotL64(aOrbiterC, 37U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 40U));
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererF);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 50U));
            aCarry = aCarry + RotL64(aWandererE, 57U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ aNonceWordF;
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 16550U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 20472U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 19000U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneD[((aIndex + 20202U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 14U) + RotL64(aIngress, 39U)) ^ (RotL64(aCarry, 27U) ^ RotL64(aPrevious, 51U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterC = ((aWandererG + RotL64(aPrevious, 47U)) + 11700815697312060726U) + aPhaseDOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = ((aWandererD + RotL64(aIngress, 30U)) + 11808423452327465441U) + aNonceWordG;
            aOrbiterJ = (aWandererB + RotL64(aCross, 43U)) + 8670503858631730886U;
            aOrbiterK = (aWandererF + RotL64(aScatter, 5U)) + 2400061067991988544U;
            aOrbiterA = ((aWandererK + RotL64(aCross, 39U)) + 16163118178366229686U) + aNonceWordJ;
            aOrbiterI = ((aWandererE + RotL64(aIngress, 13U)) + 3280178595904941068U) + aNonceWordH;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 23U)) + RotL64(aCarry, 19U)) + 3298683600817047727U;
            aOrbiterB = ((aWandererI + RotL64(aScatter, 52U)) + RotL64(aCarry, 41U)) + 16321624053445183574U;
            aOrbiterF = (aWandererH + RotL64(aCross, 57U)) + 6730229877611375225U;
            aOrbiterG = (aWandererA + RotL64(aScatter, 11U)) + 10162830636713641322U;
            aOrbiterE = (((aWandererJ + RotL64(aIngress, 19U)) + RotL64(aCarry, 47U)) + 15646771327759599256U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 14841751262270544102U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 9545541117228834895U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11529769874752969377U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 14676615635857599982U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 1231768638470558855U;
            aOrbiterA = RotL64((aOrbiterA * 2716808508509014677U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 1945905595345404833U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 1406171421638586846U;
            aOrbiterI = RotL64((aOrbiterI * 4577864352425476233U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 1970292335806697198U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 12309719390375013297U;
            aOrbiterD = RotL64((aOrbiterD * 16540660957923687327U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 5352135521358954576U) + aNonceWordI;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 15465675376193501658U;
            aOrbiterB = RotL64((aOrbiterB * 16385761112921041387U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 2842123638916600369U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 3544764287036748668U) ^ aNonceWordC;
            aOrbiterF = RotL64((aOrbiterF * 3360772950777850115U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 6038297172906492282U) + aNonceWordB;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 10249342332287140970U;
            aOrbiterG = RotL64((aOrbiterG * 16701083081566042277U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 1662076777040529446U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 1949705569959740274U;
            aOrbiterE = RotL64((aOrbiterE * 11340691546658994529U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 13934194245417822360U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 5720408806425535958U;
            aOrbiterC = RotL64((aOrbiterC * 15237561081637415383U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 2209251362417210658U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 4917447930929521699U;
            aOrbiterH = RotL64((aOrbiterH * 17489570156694692569U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 14817115766683623486U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 11700815697312060726U;
            aOrbiterK = RotL64((aOrbiterK * 16982411053956669181U), 35U);
            //
            aIngress = RotL64(aOrbiterD, 43U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterC, 23U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 28U));
            aIngress = aIngress + (RotL64(aOrbiterE, 51U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterF, 21U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterH, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterE, 23U)) + aOrbiterI);
            aWandererK = aWandererK + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterB, 41U)) + aOrbiterD);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterJ, 4U)) + aOrbiterE);
            aWandererB = aWandererB + ((((RotL64(aCross, 48U) + aOrbiterH) + RotL64(aOrbiterI, 57U)) + aNonceWordL) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterB, 51U)) + aOrbiterF) + aNonceWordA);
            aWandererF = aWandererF + (((RotL64(aCross, 35U) + RotL64(aOrbiterK, 29U)) + aOrbiterF) + RotL64(aCarry, 27U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterH, 37U)) + aOrbiterA);
            aWandererE = aWandererE + ((((RotL64(aScatter, 11U) + aOrbiterG) + RotL64(aOrbiterA, 53U)) + RotL64(aCarry, 39U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 54U) + aOrbiterF) + RotL64(aOrbiterC, 19U));
            aWandererH = aWandererH + ((RotL64(aIngress, 27U) + aOrbiterF) + RotL64(aOrbiterH, 12U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 13U) + aOrbiterI) + RotL64(aOrbiterD, 47U)) + aNonceWordO);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererA);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 18U));
            aCarry = aCarry + (RotL64(aWandererG, 51U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererE, 41U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererD, 47U);
            aCarry = aCarry + RotL64(aIngress, 36U);
            aCarry = aCarry ^ aNonceWordD;
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 23796U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24074U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 23617U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25361U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aPrevious, 27U)) + (RotL64(aCarry, 12U) + RotL64(aIngress, 53U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterG = (aWandererI + RotL64(aPrevious, 39U)) + 13174219512651137892U;
            aOrbiterF = ((aWandererA + RotL64(aIngress, 43U)) + RotL64(aCarry, 11U)) + 2715455762789269341U;
            aOrbiterE = (aWandererK + RotL64(aCross, 28U)) + 1338018183235594313U;
            aOrbiterI = ((aWandererB + RotL64(aScatter, 3U)) + 16566866551729552930U) + aPhaseDOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 57U)) + RotL64(aCarry, 5U)) + 6901845297307236726U;
            aOrbiterJ = (aWandererF + RotL64(aIngress, 21U)) + 2476078302049201718U;
            aOrbiterD = (aWandererC + RotL64(aScatter, 23U)) + 15531109473927052260U;
            aOrbiterK = ((aWandererJ + RotL64(aCross, 30U)) + RotL64(aCarry, 27U)) + 4087849380858572351U;
            aOrbiterH = ((aWandererD + RotL64(aIngress, 53U)) + 5167830630098599644U) + aNonceWordH;
            aOrbiterB = (aWandererH + RotL64(aPrevious, 47U)) + 7275995452428627217U;
            aOrbiterC = (((aWandererG + RotL64(aScatter, 19U)) + 14794340370010024117U) + aPhaseDOrbiterAssignSaltF[((aIndex + 10U)) & S_SALT1]) + aNonceWordP;
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 8509217403041662849U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 2321522025240806996U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 113568101672878697U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 5676672952755594051U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 2304681269233504384U;
            aOrbiterJ = RotL64((aOrbiterJ * 15731441084605554497U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 8383399721062437300U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 13181984036942227666U;
            aOrbiterK = RotL64((aOrbiterK * 1648761328771932069U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 13602604532551684210U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 12725687663616352843U;
            aOrbiterB = RotL64((aOrbiterB * 4684699861686199753U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 5831790822416009806U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 4535048543735457407U;
            aOrbiterG = RotL64((aOrbiterG * 12076777878870257053U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 10617608605149381858U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 5244225377862618630U;
            aOrbiterI = RotL64((aOrbiterI * 15307177251167023999U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 18229989093139888456U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 9728120630096192811U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16052574428163231023U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 1312233443099767304U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 8043115602160128619U;
            aOrbiterH = RotL64((aOrbiterH * 9365756845731616963U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 4679339316686216023U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 211799535650113758U;
            aOrbiterC = RotL64((aOrbiterC * 1478368466990144107U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 13307123762743628190U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterK) ^ 7093673238704478497U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterF = RotL64((aOrbiterF * 13273906568866802561U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 16396459072175632290U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 13174219512651137892U;
            aOrbiterA = RotL64((aOrbiterA * 7581008806810219369U), 29U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterD, 53U);
            aIngress = aIngress + (RotL64(aOrbiterC, 44U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 41U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 11U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 39U));
            aIngress = aIngress + RotL64(aOrbiterA, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 12U) + aOrbiterJ) + RotL64(aOrbiterG, 23U)) + aNonceWordG);
            aWandererF = aWandererF + (((RotL64(aScatter, 35U) + aOrbiterB) + RotL64(aOrbiterE, 6U)) + RotL64(aCarry, 39U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterD, 47U)) + aOrbiterA);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 21U) + aOrbiterA) + RotL64(aOrbiterK, 53U)) + RotL64(aCarry, 51U)) + aNonceWordD);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 41U) + aOrbiterJ) + RotL64(aOrbiterH, 19U));
            aWandererK = aWandererK + (((RotL64(aCross, 39U) + RotL64(aOrbiterE, 37U)) + aOrbiterG) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterI, 27U)) + aOrbiterK);
            aWandererI = aWandererI + ((RotL64(aScatter, 56U) + aOrbiterE) + RotL64(aOrbiterD, 29U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterB, 51U)) + aOrbiterF) + aPhaseDWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 47U) + aOrbiterH) + RotL64(aOrbiterC, 57U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterF, 4U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererB, 50U) ^ aWandererK);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 56U));
            aCarry = aCarry + RotL64(aWandererE, 43U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ aNonceWordG;
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 27369U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((aIndex + 29845U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 32641U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneB[((aIndex + 28541U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aIngress, 21U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCross, 36U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 51U)) + RotL64(aCarry, 57U)) + 14008824488073394623U;
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 53U)) + 13317978415866411468U) + aNonceWordO;
            aOrbiterC = ((aWandererH + RotL64(aCross, 43U)) + 13209180141897453900U) + aPhaseDOrbiterAssignSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = (aWandererB + RotL64(aIngress, 10U)) + 11870521586865233578U;
            aOrbiterI = ((aWandererD + RotL64(aScatter, 19U)) + 8052156380448047385U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = (aWandererA + RotL64(aPrevious, 23U)) + 12158131176743680605U;
            aOrbiterA = ((aWandererC + RotL64(aCross, 21U)) + RotL64(aCarry, 29U)) + 14674467487607719347U;
            aOrbiterH = (aWandererG + RotL64(aIngress, 41U)) + 18055496790566231147U;
            aOrbiterG = (((aWandererE + RotL64(aPrevious, 30U)) + RotL64(aCarry, 11U)) + 3838105585041578784U) + aNonceWordE;
            aOrbiterD = (aWandererF + RotL64(aCross, 47U)) + 2839568255183054418U;
            aOrbiterB = (aWandererI + RotL64(aIngress, 13U)) + 11933612922864258179U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 6289849094151630580U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 2640344350528492271U;
            aOrbiterC = RotL64((aOrbiterC * 16197726750829369365U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 16306175266267657791U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 3339898380394883600U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7105436590182982373U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 15017076663742800002U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 8973064296077602496U;
            aOrbiterE = RotL64((aOrbiterE * 9309462227233615761U), 21U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterI) + 17580319233338139859U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1]) + aNonceWordD;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 14063208878807603874U;
            aOrbiterA = RotL64((aOrbiterA * 16601475239075164585U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 13326130855721009942U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 12843186026737544416U;
            aOrbiterH = RotL64((aOrbiterH * 4975848122837321619U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 14102887715772847499U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 14495942314329085733U;
            aOrbiterG = RotL64((aOrbiterG * 4236795312917583565U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 11564857125101669667U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 17435970784822000464U;
            aOrbiterD = RotL64((aOrbiterD * 1472691848852381173U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 16561390130356833062U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 9952805588514363872U;
            aOrbiterB = RotL64((aOrbiterB * 3720874990001086597U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 8246822023509690545U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 305480212301772662U;
            aOrbiterK = RotL64((aOrbiterK * 4295787267516476485U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 11729872285756639125U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 9669174142543613799U;
            aOrbiterJ = RotL64((aOrbiterJ * 9443240779947114779U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 7653344907616923293U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 14008824488073394623U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8362849599309360823U), 29U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterI, 53U);
            aIngress = aIngress + (RotL64(aOrbiterG, 21U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterC, 24U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 43U));
            aIngress = aIngress + (RotL64(aOrbiterA, 41U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterB, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterJ, 23U)) + aOrbiterA);
            aWandererE = aWandererE + (((RotL64(aScatter, 39U) + RotL64(aOrbiterK, 29U)) + aOrbiterI) + RotL64(aCarry, 41U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterA, 60U)) + aOrbiterE);
            aWandererA = aWandererA + ((RotL64(aCross, 41U) + aOrbiterB) + RotL64(aOrbiterI, 39U));
            aWandererG = aWandererG ^ ((((RotL64(aIngress, 43U) + RotL64(aOrbiterH, 47U)) + aOrbiterB) + aNonceWordC) + aPhaseDWandererUpdateSaltE[((aIndex + 28U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aScatter, 35U) + RotL64(aOrbiterJ, 43U)) + aOrbiterG);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 50U) + aOrbiterB) + RotL64(aOrbiterC, 21U));
            aWandererH = aWandererH + ((((RotL64(aCross, 37U) + RotL64(aOrbiterD, 51U)) + aOrbiterG) + RotL64(aCarry, 19U)) + aNonceWordA);
            aWandererJ = aWandererJ ^ ((((RotL64(aIngress, 19U) + RotL64(aOrbiterE, 13U)) + aOrbiterF) + aNonceWordM) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 23U) + RotL64(aOrbiterJ, 11U)) + aOrbiterD);
            aWandererF = aWandererF ^ ((RotL64(aCross, 12U) + RotL64(aOrbiterD, 6U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 58U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 41U) ^ aWandererI);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + (RotL64(aWandererA, 37U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererE, 60U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererK, 11U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordJ);
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

void TwistExpander_Golf_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xD80FA6DA728D1E73ULL + 0xD755DBE94697CD7EULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xE1DB60CE8D330A6BULL + 0xB79E0DF58AA504B9ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xD43B94714C90BD79ULL + 0xD0BCC3E72CF50485ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xCC14E32D063DAFB3ULL + 0xB6FBD6AABB826AE2ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xF01DAF6E4F866093ULL + 0xB06A816EDA01BBB9ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xFA4115D8F615B323ULL + 0xEC54FEE121A1A836ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xB181C9FE50AC2CDBULL + 0xAAE314AD534FE48BULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x91BE153A6C203309ULL + 0xDF7DE852B1215772ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x9B84021E479336AFULL + 0xADA7ED6A05E09537ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xCC9BA24C14AF7EA7ULL + 0xD9211B685770991FULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xDABD2FBBEADB67ADULL + 0xB3E7825253C46E1AULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xE11AA52E65979ECDULL + 0x96B2F57E0B013DDAULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x85D539DF826389E9ULL + 0xEB5BC8526944FEACULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x819B74A3F34C116DULL + 0xED32EF0D58046CA6ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xA31273AB3CACFEB5ULL + 0xE285986630363374ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x8CAF3638A6AD1F1DULL + 0xA451B0AC98DF9E26ULL);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 2272U)) & S_BLOCK1], 10U) ^ RotL64(aWorkLaneC[((aIndex + 5312U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 4010U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneA[((aIndex + 2518U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 29U) ^ RotL64(aCross, 14U)) ^ (RotL64(aIngress, 57U) + RotL64(aCarry, 41U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterA = (aWandererF + RotL64(aIngress, 39U)) + 1210605127156905516U;
            aOrbiterE = ((aWandererC + RotL64(aCross, 29U)) + 11964595428173569519U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = (aWandererG + RotL64(aScatter, 34U)) + 16277319029916258482U;
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 11U)) + 12369497463101824572U) + aNonceWordC;
            aOrbiterC = (aWandererH + RotL64(aScatter, 21U)) + 6201248574067068202U;
            aOrbiterH = (aWandererK + RotL64(aCross, 5U)) + 1727477025667206661U;
            aOrbiterB = (((aWandererI + RotL64(aIngress, 54U)) + RotL64(aCarry, 41U)) + 1404510627789806851U) + aPhaseEOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 57U)) + RotL64(aCarry, 35U)) + 6948213591282018925U;
            aOrbiterG = ((aWandererD + RotL64(aCross, 51U)) + RotL64(aCarry, 53U)) + 6688865181284421478U;
            aOrbiterJ = (aWandererA + RotL64(aScatter, 43U)) + 3351130769402360855U;
            aOrbiterF = (aWandererJ + RotL64(aPrevious, 19U)) + 12681032488906270823U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 3591412591193726763U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 16153817571210878589U;
            aOrbiterI = RotL64((aOrbiterI * 4165137036092246349U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 3808228354421006630U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 1427373776207504205U;
            aOrbiterH = RotL64((aOrbiterH * 4534374093769595531U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 1831554180932501132U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 1114853085120949215U;
            aOrbiterA = RotL64((aOrbiterA * 4264176108298812905U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 2080935638828366835U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 16104777999646489828U;
            aOrbiterD = RotL64((aOrbiterD * 15205199362011777473U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 9782806013673440791U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 3721620299829386454U;
            aOrbiterB = RotL64((aOrbiterB * 6286765834910272409U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 4013706412064296527U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 5751022780695158579U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13766736471646116397U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 17684546333240329338U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 1106947111128020920U;
            aOrbiterF = RotL64((aOrbiterF * 3158839453318658951U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 11564229705849500598U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 1585817314460274286U;
            aOrbiterE = RotL64((aOrbiterE * 12687162159791577431U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 13549147977354138518U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 5148731385622182707U;
            aOrbiterC = RotL64((aOrbiterC * 11016443961557395981U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 17048442399822433365U) + aNonceWordO;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 13772472534194030098U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13155895389652826889U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 9982971300679888388U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 1210605127156905516U) ^ aNonceWordD;
            aOrbiterJ = RotL64((aOrbiterJ * 9183351854400012949U), 41U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterJ, 21U);
            aIngress = aIngress + (RotL64(aOrbiterD, 53U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 34U));
            aIngress = aIngress + (RotL64(aOrbiterF, 41U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterA, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aIngress, 41U) + aOrbiterI) + RotL64(aOrbiterB, 34U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 23U) + aOrbiterC) + RotL64(aOrbiterH, 47U)) + aNonceWordK);
            aWandererH = aWandererH + (((((RotL64(aPrevious, 43U) + RotL64(aOrbiterC, 13U)) + aOrbiterE) + RotL64(aCarry, 41U)) + aNonceWordJ) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterJ, 11U)) + aOrbiterA);
            aWandererD = aWandererD + ((RotL64(aCross, 38U) + aOrbiterJ) + RotL64(aOrbiterG, 21U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 53U) + aOrbiterK) + RotL64(aOrbiterI, 39U)) + aNonceWordP);
            aWandererF = aWandererF + ((RotL64(aScatter, 11U) + aOrbiterI) + RotL64(aOrbiterF, 19U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 47U) + aOrbiterB) + RotL64(aOrbiterE, 57U));
            aWandererE = aWandererE + (((RotL64(aCross, 13U) + RotL64(aOrbiterA, 5U)) + aOrbiterC) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 30U) + RotL64(aOrbiterI, 27U)) + aOrbiterG);
            aWandererG = aWandererG + (((RotL64(aIngress, 19U) + aOrbiterH) + RotL64(aOrbiterD, 42U)) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 54U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 51U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + RotL64(aWandererD, 46U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordI);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 5613U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneD[((aIndex + 6768U)) & S_BLOCK1], 42U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 9883U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 7341U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 52U) + RotL64(aCross, 35U)) ^ (RotL64(aIngress, 11U) + RotL64(aCarry, 23U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 43U)) + RotL64(aCarry, 53U)) + 3612110001869385068U;
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 3U)) + 16340824141280225936U) + aNonceWordI;
            aOrbiterI = (aWandererF + RotL64(aIngress, 18U)) + 15222338965130765231U;
            aOrbiterH = (aWandererE + RotL64(aCross, 29U)) + 6649270508107155041U;
            aOrbiterC = (aWandererD + RotL64(aScatter, 51U)) + 768217258655426384U;
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 39U)) + 4481855259658861851U;
            aOrbiterB = (aWandererK + RotL64(aIngress, 48U)) + 18318041934562434016U;
            aOrbiterE = (((aWandererG + RotL64(aCross, 13U)) + 4212457153804401807U) + aPhaseEOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1]) + aNonceWordC;
            aOrbiterF = ((aWandererB + RotL64(aIngress, 53U)) + RotL64(aCarry, 57U)) + 16143621095636987628U;
            aOrbiterG = (((aWandererA + RotL64(aCross, 27U)) + RotL64(aCarry, 43U)) + 2095664232866642086U) + aPhaseEOrbiterAssignSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = (aWandererC + RotL64(aScatter, 11U)) + 4339527736737366572U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 13679353177869884790U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 11582168502846418236U;
            aOrbiterI = RotL64((aOrbiterI * 135539430034462861U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 10451330452898542191U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 12951448817640617841U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4141870904192742091U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 15389161934419370747U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 4754886272708253014U) ^ aNonceWordN;
            aOrbiterC = RotL64((aOrbiterC * 16638243718191281597U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 11746389873929280688U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 12042680172517298768U;
            aOrbiterB = RotL64((aOrbiterB * 3814780289755857543U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 2648103752465009244U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 451594673632597973U;
            aOrbiterF = RotL64((aOrbiterF * 8496763663271072425U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 5696534794094099710U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 14609435045257077395U;
            aOrbiterK = RotL64((aOrbiterK * 14658408563237468407U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 11599395126850950133U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 12699598504604446664U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14313494063098111823U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 9398465148537154745U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 12139736860648011256U;
            aOrbiterA = RotL64((aOrbiterA * 15257503229375247987U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 5390816291244486383U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 2797988892316486895U;
            aOrbiterE = RotL64((aOrbiterE * 14668138881285892065U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 18356290434261054712U) + aNonceWordF;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 16582824574485822826U;
            aOrbiterG = RotL64((aOrbiterG * 7207935384746719969U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 9858803484150150915U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 3612110001869385068U;
            aOrbiterD = RotL64((aOrbiterD * 2862887443435821143U), 13U);
            //
            aIngress = RotL64(aOrbiterI, 27U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 50U));
            aIngress = aIngress + (RotL64(aOrbiterG, 43U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterC, 21U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterK, 39U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterF, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterK, 6U)) + aOrbiterG);
            aWandererC = aWandererC + (((RotL64(aIngress, 57U) + aOrbiterF) + RotL64(aOrbiterA, 47U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 53U) + aOrbiterF) + RotL64(aOrbiterG, 35U));
            aWandererF = aWandererF + (((RotL64(aCross, 37U) + RotL64(aOrbiterC, 27U)) + aOrbiterB) + RotL64(aCarry, 39U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 60U) + aOrbiterD) + RotL64(aOrbiterH, 37U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 51U) + aOrbiterC) + RotL64(aOrbiterI, 43U)) + RotL64(aCarry, 43U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterE, 11U)) + aOrbiterJ);
            aWandererI = aWandererI + (((RotL64(aCross, 21U) + RotL64(aOrbiterA, 23U)) + aOrbiterC) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 14U) + aOrbiterC) + RotL64(aOrbiterD, 3U));
            aWandererD = aWandererD + (((RotL64(aCross, 29U) + aOrbiterE) + RotL64(aOrbiterA, 41U)) + aNonceWordA);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 11U) + aOrbiterC) + RotL64(aOrbiterK, 50U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 60U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 21U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 5U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 13U));
            aCarry = aCarry + RotL64(aWandererB, 41U);
            aCarry = aCarry + RotL64(aIngress, 50U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordA);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 12720U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 14177U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 14189U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 11368U)) & S_BLOCK1], 24U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCross, 6U)) ^ (RotL64(aPrevious, 41U) + RotL64(aCarry, 27U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 5U)) + 5041131702736607991U) + aPhaseEOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = ((aWandererD + RotL64(aScatter, 14U)) + RotL64(aCarry, 39U)) + 9295010428212681446U;
            aOrbiterH = ((aWandererK + RotL64(aCross, 29U)) + RotL64(aCarry, 21U)) + 6235875895358766017U;
            aOrbiterE = (aWandererH + RotL64(aIngress, 11U)) + 2622227802531866918U;
            aOrbiterA = (aWandererF + RotL64(aScatter, 47U)) + 3888894734834524972U;
            aOrbiterK = ((aWandererG + RotL64(aCross, 27U)) + 241682012014701753U) + aNonceWordD;
            aOrbiterI = ((aWandererB + RotL64(aIngress, 23U)) + 15758000422451568079U) + aNonceWordP;
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 53U)) + RotL64(aCarry, 47U)) + 2061944548396976912U;
            aOrbiterF = (((aWandererJ + RotL64(aIngress, 19U)) + 8177144990755754531U) + aPhaseEOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1]) + aNonceWordA;
            aOrbiterJ = (aWandererE + RotL64(aPrevious, 41U)) + 554978075608818497U;
            aOrbiterG = (aWandererA + RotL64(aScatter, 34U)) + 250408260560714933U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 8700027645880997552U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 10026130047465480902U;
            aOrbiterH = RotL64((aOrbiterH * 12417270861933696623U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 9785843014096326696U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 9998582683258411251U;
            aOrbiterK = RotL64((aOrbiterK * 7197956237569462269U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 13817734599383455151U) + aNonceWordF;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 6647207154174092691U) ^ aNonceWordE;
            aOrbiterD = RotL64((aOrbiterD * 1578528131687283531U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 4957715980509035719U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 4994885315786213197U;
            aOrbiterA = RotL64((aOrbiterA * 5676683798126497011U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 5072908311783966503U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 5535039946192891515U;
            aOrbiterC = RotL64((aOrbiterC * 2989412783482309753U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 6594577050344146271U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 8750154123258714856U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6942158167127532003U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 3514769314840874873U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 8626045200273524281U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4315441782689789689U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 8524870284841706517U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 1841819423572964209U;
            aOrbiterE = RotL64((aOrbiterE * 9802481758007234681U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 12668382464510772517U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 6330331402801670515U;
            aOrbiterI = RotL64((aOrbiterI * 9096920618612750935U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 10346986196055766087U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 10932918162471200996U;
            aOrbiterF = RotL64((aOrbiterF * 6863632877625141567U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 6264557195446069146U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 5041131702736607991U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4978591546106895045U), 27U);
            //
            aIngress = RotL64(aOrbiterC, 41U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterG, 18U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 21U));
            aIngress = aIngress + (RotL64(aOrbiterK, 27U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 39U));
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 27U) + aOrbiterJ) + RotL64(aOrbiterF, 27U));
            aWandererD = aWandererD + (((RotL64(aScatter, 23U) + RotL64(aOrbiterB, 57U)) + aOrbiterA) + aNonceWordK);
            aWandererE = aWandererE ^ ((RotL64(aCross, 5U) + aOrbiterG) + RotL64(aOrbiterF, 38U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterD, 51U)) + aOrbiterB);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 13U) + aOrbiterC) + RotL64(aOrbiterG, 3U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aCross, 43U) + aOrbiterH) + RotL64(aOrbiterE, 47U)) + RotL64(aCarry, 29U)) + aPhaseEWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 30U) + RotL64(aOrbiterJ, 53U)) + aOrbiterC) + aNonceWordJ);
            aWandererH = aWandererH + ((RotL64(aIngress, 51U) + RotL64(aOrbiterK, 36U)) + aOrbiterB);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 57U) + aOrbiterI) + RotL64(aOrbiterH, 21U)) + aNonceWordM);
            aWandererF = aWandererF + (((RotL64(aScatter, 3U) + aOrbiterH) + RotL64(aOrbiterB, 11U)) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 60U) + aOrbiterA) + RotL64(aOrbiterI, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererH);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 50U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + RotL64(aWandererD, 60U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordN);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 19012U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneB[((aIndex + 19773U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 20515U)) & S_BLOCK1], 20U) ^ RotL64(aWorkLaneD[((aIndex + 16741U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCarry, 41U)) + (RotL64(aCross, 29U) ^ RotL64(aIngress, 10U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 5U)) + 5576732410244514238U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = ((aWandererB + RotL64(aIngress, 60U)) + 2833808925935929629U) + aNonceWordI;
            aOrbiterG = ((aWandererH + RotL64(aScatter, 27U)) + 3670188682914544792U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterE = ((aWandererA + RotL64(aCross, 43U)) + RotL64(aCarry, 39U)) + 15759072378887814995U;
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 3U)) + RotL64(aCarry, 19U)) + 13934007231137439994U;
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 35U)) + RotL64(aCarry, 13U)) + 11022225696007690512U;
            aOrbiterK = (aWandererE + RotL64(aIngress, 22U)) + 16989177104453635790U;
            aOrbiterH = ((aWandererI + RotL64(aCross, 37U)) + 9256930045263527091U) + aNonceWordD;
            aOrbiterC = (aWandererC + RotL64(aIngress, 51U)) + 17788596104417068290U;
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 41U)) + 17044369456673337625U;
            aOrbiterF = (aWandererF + RotL64(aScatter, 11U)) + 1310908395523250343U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 12067065689034065422U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 15130844248737512262U;
            aOrbiterG = RotL64((aOrbiterG * 9409499577465934107U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 14532689204495587494U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 8198147292120244178U;
            aOrbiterD = RotL64((aOrbiterD * 1418356389507740991U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 5485494458627163347U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 10830008207150307611U) ^ aNonceWordK;
            aOrbiterB = RotL64((aOrbiterB * 6526039534042499457U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 17770065502486618029U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 6397859353395335459U) ^ aNonceWordE;
            aOrbiterK = RotL64((aOrbiterK * 14286997752368893825U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 5128700697381508319U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 7103394110057060499U;
            aOrbiterH = RotL64((aOrbiterH * 5053680689949149633U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 16024401282261796979U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 12818445221897253410U;
            aOrbiterC = RotL64((aOrbiterC * 11450004517784155405U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 13386978409145916350U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterK) ^ 16740821954556699503U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterJ = RotL64((aOrbiterJ * 5376430209628515105U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 313978038530994953U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 1355733685461795345U;
            aOrbiterF = RotL64((aOrbiterF * 15955927322082619735U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 12590581077253956064U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 2298195367575496005U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17512801361187006363U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 11847450675712272468U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 5914296379577670282U;
            aOrbiterI = RotL64((aOrbiterI * 14574813500616811367U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 16901317262621287065U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 5576732410244514238U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4514943876091531567U), 5U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterB, 13U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 35U));
            aIngress = aIngress + (RotL64(aOrbiterD, 39U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 26U));
            aIngress = aIngress + RotL64(aOrbiterE, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 43U) + aOrbiterC) + RotL64(aOrbiterH, 47U)) + aPhaseEWandererUpdateSaltE[((aIndex + 26U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aScatter, 21U) + aOrbiterF) + RotL64(aOrbiterE, 43U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 4U) + aOrbiterI) + RotL64(aOrbiterB, 37U));
            aWandererC = aWandererC + (((RotL64(aIngress, 19U) + RotL64(aOrbiterG, 23U)) + aOrbiterJ) + aNonceWordO);
            aWandererK = aWandererK ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterF, 3U)) + aOrbiterG);
            aWandererA = aWandererA + ((RotL64(aIngress, 35U) + aOrbiterD) + RotL64(aOrbiterF, 39U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 39U) + aOrbiterB) + RotL64(aOrbiterJ, 20U));
            aWandererF = aWandererF + ((((RotL64(aScatter, 23U) + RotL64(aOrbiterA, 53U)) + aOrbiterI) + RotL64(aCarry, 39U)) + aPhaseEWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 11U) + aOrbiterG) + RotL64(aOrbiterA, 41U));
            aWandererH = aWandererH + (((RotL64(aCross, 53U) + aOrbiterH) + RotL64(aOrbiterK, 13U)) + RotL64(aCarry, 43U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 56U) + RotL64(aOrbiterK, 58U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + (RotL64(aWandererK, 41U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererB, 24U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererI);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + RotL64(aWandererE, 37U);
            aCarry = aCarry + RotL64(aIngress, 30U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordF);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 25962U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneA[((aIndex + 27236U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 23160U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25726U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCarry, 11U)) + (RotL64(aPrevious, 24U) ^ RotL64(aCross, 39U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterG = ((aWandererC + RotL64(aIngress, 19U)) + 2225397913940961213U) + aPhaseEOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = ((aWandererH + RotL64(aScatter, 27U)) + 8342544893601343643U) + aNonceWordG;
            aOrbiterD = ((aWandererI + RotL64(aCross, 29U)) + RotL64(aCarry, 35U)) + 162922186381417187U;
            aOrbiterI = (aWandererD + RotL64(aPrevious, 51U)) + 11660218373710972210U;
            aOrbiterA = ((aWandererB + RotL64(aIngress, 57U)) + 14909034764605802354U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = ((aWandererG + RotL64(aCross, 3U)) + 16776955237009701511U) + aNonceWordH;
            aOrbiterJ = (aWandererK + RotL64(aScatter, 6U)) + 5834487809188925253U;
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 53U)) + 1498492772767040320U) + aNonceWordN;
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 13U)) + RotL64(aCarry, 23U)) + 4161765458781579617U;
            aOrbiterB = (aWandererE + RotL64(aPrevious, 23U)) + 10511923076962447765U;
            aOrbiterK = ((aWandererA + RotL64(aIngress, 38U)) + RotL64(aCarry, 29U)) + 8575954471692620021U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 6536325446331340573U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 1790628986900286346U;
            aOrbiterD = RotL64((aOrbiterD * 5262997114200816715U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 2623814807619278590U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 11676970995834706612U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10057461115132434901U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 13836786354224256591U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 6293096163612129260U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8977954126326217153U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 4271144764978661248U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 15938494256992560202U;
            aOrbiterB = RotL64((aOrbiterB * 10004841288382726739U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 11038155227307702976U) + aNonceWordO;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 12408749795071243930U;
            aOrbiterG = RotL64((aOrbiterG * 5527720475032868855U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 1673665849053496882U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 12866353361497103629U;
            aOrbiterI = RotL64((aOrbiterI * 6041125499398924871U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 10673935802381580966U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 8946776538955520352U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12293084177712710021U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 16294935203370452805U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 4697759331563852212U;
            aOrbiterC = RotL64((aOrbiterC * 14407806317275373043U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 17633118874112283386U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 89602424202721105U;
            aOrbiterK = RotL64((aOrbiterK * 1010654844008668685U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 4019154066191316616U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 15029609435149173243U) ^ aNonceWordJ;
            aOrbiterE = RotL64((aOrbiterE * 3522168783248806167U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 11765990698273078458U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 2225397913940961213U;
            aOrbiterA = RotL64((aOrbiterA * 8471538922288466221U), 37U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterA, 40U);
            aIngress = aIngress + (RotL64(aOrbiterG, 47U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 51U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 27U));
            aIngress = aIngress + (RotL64(aOrbiterF, 57U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterD, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterJ, 23U)) + aOrbiterI) + aNonceWordI);
            aWandererI = aWandererI + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterK, 37U)) + aOrbiterD) + aNonceWordP);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterF, 53U)) + aOrbiterB);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 43U) + RotL64(aOrbiterB, 39U)) + aOrbiterD) + RotL64(aCarry, 51U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 48U) + aOrbiterG) + RotL64(aOrbiterH, 43U));
            aWandererG = aWandererG + ((RotL64(aIngress, 3U) + RotL64(aOrbiterA, 60U)) + aOrbiterI);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 35U) + aOrbiterE) + RotL64(aOrbiterA, 35U));
            aWandererB = aWandererB + ((((RotL64(aCross, 39U) + RotL64(aOrbiterH, 5U)) + aOrbiterD) + RotL64(aCarry, 41U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 21U) + aOrbiterA) + RotL64(aOrbiterB, 47U));
            aWandererA = aWandererA + ((RotL64(aScatter, 28U) + RotL64(aOrbiterC, 41U)) + aOrbiterD);
            aWandererC = aWandererC ^ ((((RotL64(aCross, 5U) + aOrbiterG) + RotL64(aOrbiterC, 50U)) + aNonceWordA) + aPhaseEWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 50U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 37U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererG, 57U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordD);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 27903U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((aIndex + 31919U)) & S_BLOCK1], 30U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 28416U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneB[((aIndex + 28764U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 6U) ^ RotL64(aCross, 57U)) + (RotL64(aIngress, 37U) ^ RotL64(aCarry, 23U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterK = ((aWandererA + RotL64(aCross, 47U)) + RotL64(aCarry, 27U)) + 4384716820085860551U;
            aOrbiterA = (aWandererG + RotL64(aIngress, 23U)) + 9715780315942116888U;
            aOrbiterI = (((aWandererH + RotL64(aScatter, 19U)) + RotL64(aCarry, 47U)) + 15963520052789178632U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = (((aWandererK + RotL64(aPrevious, 60U)) + RotL64(aCarry, 51U)) + 14346700690686392938U) + aNonceWordK;
            aOrbiterC = (aWandererF + RotL64(aIngress, 21U)) + 6005518012489966643U;
            aOrbiterH = (aWandererJ + RotL64(aScatter, 51U)) + 2506732930310252119U;
            aOrbiterB = ((aWandererE + RotL64(aCross, 5U)) + 16782163084851775826U) + aNonceWordO;
            aOrbiterG = (aWandererB + RotL64(aPrevious, 10U)) + 823673076571076303U;
            aOrbiterF = (aWandererI + RotL64(aIngress, 53U)) + 1634084509064077736U;
            aOrbiterD = ((aWandererC + RotL64(aScatter, 43U)) + 1288134975466877686U) + aNonceWordE;
            aOrbiterE = ((aWandererD + RotL64(aCross, 3U)) + 2998220403162908444U) + aPhaseEOrbiterAssignSaltE[((aIndex + 12U)) & S_SALT1];
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 220430672180734911U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 10223923547068528867U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12577370238343872139U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 11696469696177647608U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 6545430420379636963U;
            aOrbiterC = RotL64((aOrbiterC * 8387163146257553773U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 79691451831797107U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 8971444023498649419U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7148919880477390009U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 5624403902454498793U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 9468064161002030997U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8243560528100864595U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 4619361544913629805U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 12682446273369750704U;
            aOrbiterG = RotL64((aOrbiterG * 10879074713156075641U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 8728730962617599223U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 9099675924074253030U;
            aOrbiterF = RotL64((aOrbiterF * 5525644236954497523U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 3298303921318288541U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 5953276499411658358U;
            aOrbiterD = RotL64((aOrbiterD * 10565471305001292693U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 6725769507592688539U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 1057277456510215817U;
            aOrbiterE = RotL64((aOrbiterE * 8269412198279297075U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 11317925732206917722U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 17814749417006079067U;
            aOrbiterK = RotL64((aOrbiterK * 4369209051015735925U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 9258362135343403308U) + aNonceWordA;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 4873837345446960113U;
            aOrbiterA = RotL64((aOrbiterA * 14223381466269503273U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 7863380865835889675U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 4384716820085860551U;
            aOrbiterJ = RotL64((aOrbiterJ * 2003891033298374621U), 13U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterK, 57U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 21U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 19U));
            aIngress = aIngress + (RotL64(aOrbiterI, 10U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterJ, 13U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterE, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aCross, 35U) + RotL64(aOrbiterG, 41U)) + aOrbiterF);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterB, 43U)) + aOrbiterH) + aNonceWordP);
            aWandererD = aWandererD + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterC, 29U)) + aOrbiterI) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 24U) + RotL64(aOrbiterC, 3U)) + aOrbiterH);
            aWandererG = aWandererG + (((RotL64(aCross, 5U) + RotL64(aOrbiterF, 37U)) + aOrbiterH) + aPhaseEWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 21U) + aOrbiterB) + RotL64(aOrbiterD, 18U));
            aWandererK = aWandererK + ((RotL64(aIngress, 47U) + aOrbiterK) + RotL64(aOrbiterF, 57U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterB, 23U)) + aOrbiterA);
            aWandererH = aWandererH + (((RotL64(aScatter, 13U) + RotL64(aOrbiterE, 39U)) + aOrbiterH) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 44U) + RotL64(aOrbiterD, 26U)) + aOrbiterH);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 53U) + RotL64(aOrbiterJ, 11U)) + aOrbiterB) + aNonceWordN) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererA);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 50U));
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererJ);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + RotL64(aWandererK, 60U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordA);
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

void TwistExpander_Golf_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xFA9345A0A681CAB1ULL + 0xEA1F4C75FC33B018ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xABB982997089B70FULL + 0xDE17CEBC9CE6B783ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x80D51F1E6071D375ULL + 0x9833CA35AAE4E84CULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xEB224C71F781BE97ULL + 0xC173546F82F1FD03ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xD6AA0625F2B0939FULL + 0xEA3F82BE55AB53BAULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xC6DC9833E4E60BF7ULL + 0xF3A917FF3AA10F93ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xB3B15A02B2F965B7ULL + 0xE35064D77EEE314AULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xADDEB14A1C84C6D1ULL + 0xE9BD5FD59AF85F96ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xDEF7B0CFFB761577ULL + 0xDA622BD760E039D5ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x8B9E5EA26F364477ULL + 0x852076AEB74C9200ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xAD468A23807B3E83ULL + 0x9C256BE1471816F2ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x894E6C39D2FB0ED1ULL + 0xCD477813D1FBF14BULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xC84EFB8542293635ULL + 0xB0B0788D378FECA5ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xB8F71D6EAEE7ECF1ULL + 0xBE39CC15ABBBF59AULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xC82013A9A9648441ULL + 0xA8C67141CC662AB4ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xE72B9090BAD817D5ULL + 0xC5F6FC5DB253593AULL);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 234U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 3124U)) & S_BLOCK1], 50U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 366U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneA[((aIndex + 2010U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 11U) + RotL64(aCross, 23U)) + (RotL64(aPrevious, 43U) ^ RotL64(aCarry, 60U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterJ = (aWandererG + RotL64(aIngress, 10U)) + 5576732410244514238U;
            aOrbiterB = (((aWandererK + RotL64(aCross, 37U)) + RotL64(aCarry, 23U)) + 2833808925935929629U) + aPhaseFOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 5U)) + 3670188682914544792U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterA = (aWandererE + RotL64(aScatter, 51U)) + 15759072378887814995U;
            aOrbiterG = ((aWandererD + RotL64(aIngress, 57U)) + RotL64(aCarry, 19U)) + 13934007231137439994U;
            aOrbiterC = (aWandererC + RotL64(aCross, 21U)) + 11022225696007690512U;
            aOrbiterF = (((aWandererF + RotL64(aPrevious, 27U)) + RotL64(aCarry, 27U)) + 16989177104453635790U) + aNonceWordK;
            aOrbiterI = ((aWandererA + RotL64(aScatter, 39U)) + 9256930045263527091U) + aNonceWordN;
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 53U)) + 17788596104417068290U) + aNonceWordL;
            aOrbiterD = (aWandererI + RotL64(aScatter, 42U)) + 17044369456673337625U;
            aOrbiterH = (aWandererB + RotL64(aPrevious, 47U)) + 1310908395523250343U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 12067065689034065422U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 15130844248737512262U;
            aOrbiterE = RotL64((aOrbiterE * 9409499577465934107U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 14532689204495587494U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 8198147292120244178U;
            aOrbiterC = RotL64((aOrbiterC * 1418356389507740991U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 5485494458627163347U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 10830008207150307611U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6526039534042499457U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 17770065502486618029U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 6397859353395335459U;
            aOrbiterA = RotL64((aOrbiterA * 14286997752368893825U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 5128700697381508319U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 7103394110057060499U;
            aOrbiterF = RotL64((aOrbiterF * 5053680689949149633U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 16024401282261796979U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 12818445221897253410U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11450004517784155405U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 13386978409145916350U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 16740821954556699503U;
            aOrbiterH = RotL64((aOrbiterH * 5376430209628515105U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 313978038530994953U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 1355733685461795345U;
            aOrbiterB = RotL64((aOrbiterB * 15955927322082619735U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 12590581077253956064U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 2298195367575496005U;
            aOrbiterG = RotL64((aOrbiterG * 17512801361187006363U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 11847450675712272468U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 5914296379577670282U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14574813500616811367U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 16901317262621287065U) + aNonceWordI;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 5576732410244514238U;
            aOrbiterD = RotL64((aOrbiterD * 4514943876091531567U), 29U);
            //
            aIngress = RotL64(aOrbiterD, 43U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterJ, 41U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 18U));
            aIngress = aIngress + (RotL64(aOrbiterH, 37U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterI, 23U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterC, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterF, 5U)) + aOrbiterD) + aNonceWordB);
            aWandererA = aWandererA + ((RotL64(aScatter, 23U) + RotL64(aOrbiterI, 35U)) + aOrbiterF);
            aWandererH = aWandererH ^ ((RotL64(aCross, 44U) + aOrbiterD) + RotL64(aOrbiterC, 37U));
            aWandererD = aWandererD + ((RotL64(aIngress, 11U) + aOrbiterJ) + RotL64(aOrbiterE, 3U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 3U) + aOrbiterD) + RotL64(aOrbiterK, 40U));
            aWandererB = aWandererB + ((((RotL64(aScatter, 41U) + RotL64(aOrbiterB, 23U)) + aOrbiterG) + RotL64(aCarry, 3U)) + aNonceWordE);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 34U) + RotL64(aOrbiterE, 13U)) + aOrbiterC);
            aWandererK = aWandererK + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterK, 51U)) + aOrbiterH) + RotL64(aCarry, 43U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 13U) + aOrbiterB) + RotL64(aOrbiterF, 27U));
            aWandererC = aWandererC + ((((RotL64(aPrevious, 37U) + aOrbiterA) + RotL64(aOrbiterD, 46U)) + aNonceWordJ) + aPhaseFWandererUpdateSaltD[((aIndex + 15U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterJ, 57U)) + aOrbiterK) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 46U) ^ aWandererH);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 51U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 37U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + RotL64(aWandererA, 34U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordM);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 7167U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneD[((aIndex + 5585U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 5726U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneB[((aIndex + 8682U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 27U) ^ RotL64(aIngress, 39U)) ^ (RotL64(aCross, 13U) + RotL64(aPrevious, 58U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterA = ((aWandererG + RotL64(aCross, 24U)) + RotL64(aCarry, 3U)) + 9041099828460168106U;
            aOrbiterI = ((aWandererH + RotL64(aIngress, 13U)) + 12883711604096848454U) + aNonceWordI;
            aOrbiterH = (aWandererI + RotL64(aPrevious, 5U)) + 17420968786226443079U;
            aOrbiterF = ((aWandererC + RotL64(aScatter, 3U)) + 3448213891716125104U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterK = (aWandererA + RotL64(aCross, 47U)) + 11866455977445336560U;
            aOrbiterD = (((aWandererF + RotL64(aIngress, 19U)) + RotL64(aCarry, 51U)) + 4119356835384495905U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = (aWandererK + RotL64(aScatter, 11U)) + 2186212599698637068U;
            aOrbiterE = (aWandererE + RotL64(aPrevious, 27U)) + 6506144898969301620U;
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 37U)) + RotL64(aCarry, 13U)) + 12556800923644051626U;
            aOrbiterG = (aWandererB + RotL64(aPrevious, 34U)) + 4075551535185182945U;
            aOrbiterJ = ((aWandererD + RotL64(aCross, 53U)) + 17877694808492008749U) + aNonceWordC;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 5553428900598223316U) + aNonceWordO;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 14362304852277160675U;
            aOrbiterH = RotL64((aOrbiterH * 11415103199856419303U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 9174200302876075831U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 16110739511917638547U;
            aOrbiterI = RotL64((aOrbiterI * 7004356839428657949U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 10189881974519849402U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 2128076632642616677U;
            aOrbiterK = RotL64((aOrbiterK * 8860453653433114929U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 18133523799074400083U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 9916472958834153766U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3454601168808001733U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 10274457562795569227U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterG) ^ 14134814273275356425U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterC = RotL64((aOrbiterC * 15912501063665343159U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 6394306369514735480U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 4825761192736485643U;
            aOrbiterA = RotL64((aOrbiterA * 12534544147331805643U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 5672807934779206275U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 3881953574159390421U;
            aOrbiterF = RotL64((aOrbiterF * 7448770570912161095U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 12012232712634303203U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 14176392925893052596U;
            aOrbiterD = RotL64((aOrbiterD * 11288668529893084583U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 307148402076391033U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 15380446373458263079U;
            aOrbiterE = RotL64((aOrbiterE * 15228462337097647933U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 4654312690816676129U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 10818029316701301859U;
            aOrbiterG = RotL64((aOrbiterG * 16245734506125913215U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 7340370713289840635U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 9041099828460168106U;
            aOrbiterJ = RotL64((aOrbiterJ * 1807356802142268373U), 53U);
            //
            aIngress = RotL64(aOrbiterG, 6U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterH, 51U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterB, 19U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterI, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aScatter, 27U) + RotL64(aOrbiterA, 50U)) + aOrbiterG);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 51U) + aOrbiterB) + RotL64(aOrbiterE, 11U));
            aWandererA = aWandererA + (((RotL64(aCross, 57U) + aOrbiterF) + RotL64(aOrbiterK, 3U)) + RotL64(aCarry, 37U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 47U) + aOrbiterA) + RotL64(aOrbiterI, 29U)) + aNonceWordG);
            aWandererD = aWandererD + ((((RotL64(aIngress, 29U) + aOrbiterC) + RotL64(aOrbiterI, 13U)) + RotL64(aCarry, 21U)) + aPhaseFWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 4U) + aOrbiterJ) + RotL64(aOrbiterD, 47U)) + aNonceWordP);
            aWandererK = aWandererK + (((RotL64(aScatter, 11U) + RotL64(aOrbiterE, 52U)) + aOrbiterI) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterH, 37U)) + aOrbiterA);
            aWandererI = aWandererI + (((RotL64(aScatter, 21U) + aOrbiterI) + RotL64(aOrbiterG, 27U)) + aNonceWordJ);
            aWandererF = aWandererF ^ ((RotL64(aCross, 54U) + RotL64(aOrbiterH, 5U)) + aOrbiterK);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 39U) + aOrbiterB) + RotL64(aOrbiterD, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 50U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 34U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererH, 39U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordM);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 16308U)) & S_BLOCK1], 22U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15292U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 11182U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneC[((aIndex + 14022U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 54U) + RotL64(aCarry, 5U)) + (RotL64(aIngress, 35U) ^ RotL64(aCross, 21U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterK = (aWandererH + RotL64(aPrevious, 51U)) + 12775735908960052604U;
            aOrbiterG = (aWandererJ + RotL64(aCross, 41U)) + 11791373812080296887U;
            aOrbiterF = (aWandererI + RotL64(aScatter, 43U)) + 5537362877706057303U;
            aOrbiterB = (aWandererD + RotL64(aIngress, 34U)) + 2023912048504189380U;
            aOrbiterA = (((aWandererK + RotL64(aScatter, 37U)) + RotL64(aCarry, 27U)) + 17668828109963766893U) + aNonceWordA;
            aOrbiterH = (((aWandererF + RotL64(aIngress, 3U)) + RotL64(aCarry, 47U)) + 558908629933941224U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = (aWandererC + RotL64(aCross, 19U)) + 1479633119685446888U;
            aOrbiterC = ((((aWandererA + RotL64(aPrevious, 23U)) + RotL64(aCarry, 39U)) + 15460320397843364063U) + aPhaseFOrbiterAssignSaltF[((aIndex + 4U)) & S_SALT1]) + aNonceWordG;
            aOrbiterI = (aWandererB + RotL64(aCross, 39U)) + 10059749397555469054U;
            aOrbiterJ = (aWandererE + RotL64(aScatter, 48U)) + 9987633811929693924U;
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 13U)) + 10087337844580228269U) + aNonceWordD;
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 4446204415503364254U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 15106063243302192717U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13273756657334709803U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 9430197906134676162U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 1226048679997253363U;
            aOrbiterH = RotL64((aOrbiterH * 14247538885252664127U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 10611580584157624739U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 3137391249289641509U;
            aOrbiterG = RotL64((aOrbiterG * 5462682413239873181U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 9327201928815412810U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 7890659377013147073U;
            aOrbiterA = RotL64((aOrbiterA * 13827717178378062047U), 11U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterK) + 10675114832750356941U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordO;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 8804440385852327267U;
            aOrbiterC = RotL64((aOrbiterC * 8520671775587260601U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 12871947817782057116U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 11015991745792051390U;
            aOrbiterJ = RotL64((aOrbiterJ * 17152451500505815031U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 6320437975845673731U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 702457937087191287U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17491257114676739589U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 16629064896250312921U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 6054107387816339103U;
            aOrbiterB = RotL64((aOrbiterB * 6983767878966747219U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 13274874838094190290U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 12211422735294360321U;
            aOrbiterD = RotL64((aOrbiterD * 5113738196151089817U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 15338616110718583619U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 1475787183754511373U;
            aOrbiterI = RotL64((aOrbiterI * 10904607643785840003U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 15486810401396777742U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 12775735908960052604U;
            aOrbiterE = RotL64((aOrbiterE * 7478156942468930207U), 21U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterC, 27U);
            aIngress = aIngress + (RotL64(aOrbiterA, 18U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 5U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 37U));
            aIngress = aIngress + RotL64(aOrbiterK, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aCross, 23U) + aOrbiterH) + RotL64(aOrbiterF, 53U)) + aPhaseFWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aScatter, 53U) + RotL64(aOrbiterI, 47U)) + aOrbiterE);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterD, 5U)) + aOrbiterB);
            aWandererE = aWandererE + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterG, 3U)) + aOrbiterK);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 60U) + aOrbiterE) + RotL64(aOrbiterF, 34U)) + aNonceWordK);
            aWandererB = aWandererB + (((RotL64(aScatter, 37U) + aOrbiterE) + RotL64(aOrbiterC, 39U)) + RotL64(aCarry, 5U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 5U) + aOrbiterD) + RotL64(aOrbiterE, 29U)) + aNonceWordC);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 27U) + aOrbiterB) + RotL64(aOrbiterK, 13U)) + aNonceWordH) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 3U) + aOrbiterA) + RotL64(aOrbiterD, 11U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterI, 42U)) + aOrbiterA) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 34U) + RotL64(aOrbiterD, 37U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererK, 10U) ^ aWandererH);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + (RotL64(aWandererF, 41U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererJ);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + RotL64(aWandererD, 21U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordI);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 20214U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20603U)) & S_BLOCK1], 44U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18037U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 17019U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 3U) ^ RotL64(aCarry, 41U)) + (RotL64(aCross, 24U) ^ RotL64(aPrevious, 53U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterG = (aWandererK + RotL64(aPrevious, 21U)) + 9023059520606551446U;
            aOrbiterC = ((aWandererC + RotL64(aCross, 39U)) + RotL64(aCarry, 47U)) + 662441755115638133U;
            aOrbiterB = ((aWandererF + RotL64(aIngress, 43U)) + RotL64(aCarry, 5U)) + 16957253361196144712U;
            aOrbiterH = ((((aWandererG + RotL64(aScatter, 37U)) + RotL64(aCarry, 37U)) + 7840955025765308605U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordM;
            aOrbiterI = ((aWandererA + RotL64(aCross, 23U)) + 346855809270395799U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = (aWandererE + RotL64(aPrevious, 3U)) + 16099139781586668343U;
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 52U)) + 3706457327118322098U;
            aOrbiterK = (aWandererH + RotL64(aScatter, 57U)) + 12166825885547622870U;
            aOrbiterE = ((aWandererB + RotL64(aIngress, 19U)) + 7792658665720344200U) + aNonceWordC;
            aOrbiterF = (aWandererI + RotL64(aCross, 27U)) + 7128477606152986326U;
            aOrbiterD = (aWandererD + RotL64(aScatter, 12U)) + 11116533962780290084U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 10443889548568288532U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 4402387036946561017U;
            aOrbiterB = RotL64((aOrbiterB * 9032964741841833277U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 13002706161178447654U) + aNonceWordG;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 13929727277530310708U;
            aOrbiterI = RotL64((aOrbiterI * 7005639090871200285U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 10949073760696935106U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 15405923432006783533U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17989565878445202495U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 18096057968822208905U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 3032155040484574973U;
            aOrbiterJ = RotL64((aOrbiterJ * 448597307502544605U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 17462076466907467134U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 15471015427013701406U;
            aOrbiterK = RotL64((aOrbiterK * 6113474000571976139U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 3549031751266594344U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 14243218483842508113U;
            aOrbiterE = RotL64((aOrbiterE * 9041601306479302047U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 5803147589312920032U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 5549470512227427855U;
            aOrbiterF = RotL64((aOrbiterF * 12592362489263862879U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 10076661824293832189U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 3196799148974716550U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8183276968961467775U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 5245559903456662243U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 5907555542861339984U;
            aOrbiterG = RotL64((aOrbiterG * 10224549416454347583U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 12670710096595941569U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 655047039452620836U;
            aOrbiterC = RotL64((aOrbiterC * 9717552134857988153U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 2654837870443908572U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 9023059520606551446U;
            aOrbiterH = RotL64((aOrbiterH * 170905364378771841U), 37U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterJ, 35U);
            aIngress = aIngress + (RotL64(aOrbiterB, 18U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterI, 27U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterF, 10U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 44U) + RotL64(aOrbiterE, 41U)) + aOrbiterB);
            aWandererF = aWandererF + ((RotL64(aIngress, 51U) + aOrbiterI) + RotL64(aOrbiterC, 27U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 5U) + aOrbiterF) + RotL64(aOrbiterD, 51U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aScatter, 19U) + RotL64(aOrbiterC, 5U)) + aOrbiterF) + RotL64(aCarry, 5U)) + aNonceWordA);
            aWandererK = aWandererK ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterJ, 10U)) + aOrbiterH) + aNonceWordJ);
            aWandererC = aWandererC + ((RotL64(aScatter, 56U) + aOrbiterH) + RotL64(aOrbiterF, 35U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterK, 21U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 35U) + aOrbiterK) + RotL64(aOrbiterB, 13U)) + aNonceWordN);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterF, 24U)) + aOrbiterA);
            aWandererH = aWandererH + (((RotL64(aIngress, 27U) + aOrbiterG) + RotL64(aOrbiterC, 39U)) + RotL64(aCarry, 47U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterI, 47U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 20U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + (RotL64(aWandererE, 37U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererG, 27U);
            aCarry = aCarry + RotL64(aIngress, 58U);
            aCarry = aCarry ^ aNonceWordE;
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 26791U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneA[((aIndex + 26264U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 23974U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((aIndex + 24516U)) & S_BLOCK1], 42U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 11U) + RotL64(aPrevious, 53U)) ^ (RotL64(aCarry, 40U) ^ RotL64(aIngress, 27U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterB = ((aWandererF + RotL64(aScatter, 35U)) + 5906639480605353429U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = (aWandererE + RotL64(aCross, 24U)) + 5293518570213287605U;
            aOrbiterE = (((aWandererH + RotL64(aPrevious, 29U)) + RotL64(aCarry, 53U)) + 15383185501428521377U) + aNonceWordL;
            aOrbiterG = ((aWandererD + RotL64(aIngress, 3U)) + RotL64(aCarry, 13U)) + 15364072512743978902U;
            aOrbiterH = (aWandererG + RotL64(aScatter, 19U)) + 4525473357144014271U;
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 13U)) + 10400911938125603074U) + aNonceWordJ;
            aOrbiterF = (aWandererI + RotL64(aPrevious, 11U)) + 16417506293824627550U;
            aOrbiterK = ((aWandererA + RotL64(aCross, 54U)) + RotL64(aCarry, 43U)) + 2419329331753341815U;
            aOrbiterD = ((aWandererK + RotL64(aIngress, 41U)) + 14929222427923332069U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterC = (aWandererB + RotL64(aCross, 47U)) + 16771573504983922586U;
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 27U)) + 1863466450051787622U) + aNonceWordH;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 12895350137096692415U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 3700979086526298327U;
            aOrbiterE = RotL64((aOrbiterE * 10279730254867618193U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 1977099106211282426U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 6144698304096915742U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5039822990560519609U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 3858895556659724975U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 1283646340363435327U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11622421841377018069U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 6240532051889108891U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 757364889381634634U;
            aOrbiterC = RotL64((aOrbiterC * 943852137901972945U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 5272945693977418174U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 6850528198786172283U;
            aOrbiterB = RotL64((aOrbiterB * 1966383079897679953U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 14431587733859573714U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 16124590257870999553U;
            aOrbiterG = RotL64((aOrbiterG * 7755796211433191143U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 14912695018110241411U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 11098623474413346520U;
            aOrbiterF = RotL64((aOrbiterF * 15167688959990872051U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 3484847683376368686U) + aNonceWordN;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 2295388097292719800U;
            aOrbiterD = RotL64((aOrbiterD * 1240808318176106909U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 923199510066894111U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 311875852510926196U) ^ aNonceWordD;
            aOrbiterI = RotL64((aOrbiterI * 9797881750305289335U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 3543141837224843684U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 12889943043568922084U;
            aOrbiterA = RotL64((aOrbiterA * 8682278766727990427U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 6105656539077757510U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 5906639480605353429U;
            aOrbiterH = RotL64((aOrbiterH * 9555916235293954383U), 21U);
            //
            aIngress = RotL64(aOrbiterE, 44U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 11U));
            aIngress = aIngress + (RotL64(aOrbiterH, 47U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 53U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 37U));
            aIngress = aIngress + RotL64(aOrbiterA, 58U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aScatter, 13U) + RotL64(aOrbiterI, 35U)) + aOrbiterA) + RotL64(aCarry, 5U)) + aNonceWordC);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterC, 47U)) + aOrbiterD);
            aWandererC = aWandererC + ((RotL64(aIngress, 27U) + RotL64(aOrbiterK, 39U)) + aOrbiterI);
            aWandererF = aWandererF ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterD, 44U)) + aOrbiterH) + aNonceWordI);
            aWandererH = aWandererH + ((((RotL64(aIngress, 4U) + aOrbiterE) + RotL64(aOrbiterF, 19U)) + RotL64(aCarry, 51U)) + aNonceWordF);
            aWandererD = aWandererD ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterA, 13U)) + aOrbiterK);
            aWandererI = aWandererI + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterE, 41U)) + aOrbiterJ);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterD, 11U)) + aOrbiterK);
            aWandererB = aWandererB + (((RotL64(aPrevious, 23U) + aOrbiterK) + RotL64(aOrbiterG, 30U)) + aPhaseFWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 51U) + RotL64(aOrbiterB, 23U)) + aOrbiterD) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 6U) + aOrbiterC) + RotL64(aOrbiterF, 27U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + (RotL64(aWandererI, 39U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 20U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererA, 3U);
            aCarry = aCarry + RotL64(aIngress, 18U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordF);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 30325U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27942U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32059U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27456U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aIngress, 28U)) ^ (RotL64(aCarry, 41U) + RotL64(aPrevious, 11U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterD = (aWandererD + RotL64(aCross, 38U)) + 13296600294247799698U;
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 13U)) + 5818503518080877515U) + aNonceWordG;
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 21U)) + 6735784238734173597U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = ((aWandererK + RotL64(aIngress, 35U)) + 7368398209488856201U) + aNonceWordF;
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 19U)) + RotL64(aCarry, 37U)) + 961734029066455638U;
            aOrbiterC = (aWandererG + RotL64(aCross, 60U)) + 797011946660892011U;
            aOrbiterB = ((aWandererC + RotL64(aIngress, 29U)) + RotL64(aCarry, 11U)) + 12841876018396622350U;
            aOrbiterF = (((aWandererB + RotL64(aScatter, 27U)) + RotL64(aCarry, 43U)) + 16213253970483895623U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = (aWandererA + RotL64(aPrevious, 23U)) + 15186950557113470375U;
            aOrbiterA = (aWandererE + RotL64(aScatter, 43U)) + 5117930310827477341U;
            aOrbiterK = (aWandererH + RotL64(aCross, 57U)) + 12265429373166094162U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 13920531346698601568U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 14695405206998211456U;
            aOrbiterE = RotL64((aOrbiterE * 13950964363414164279U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 7851960904825938443U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 9501511171732550190U;
            aOrbiterG = RotL64((aOrbiterG * 5614164120361489613U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 5663365182245722077U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 9607860124321315555U;
            aOrbiterC = RotL64((aOrbiterC * 3461820361914280601U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 18171052650586819280U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 3442698321538580861U;
            aOrbiterB = RotL64((aOrbiterB * 6317525514963824829U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 1491052813469258970U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 3956599824067616133U;
            aOrbiterF = RotL64((aOrbiterF * 2928600779267623085U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 10963841237346073453U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 2303020125591252534U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9969099842343321981U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 14503856057958162356U) + aNonceWordH;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 11147548150090597694U;
            aOrbiterA = RotL64((aOrbiterA * 11856382308792700441U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 9191681438318311481U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 13556072770381999852U;
            aOrbiterK = RotL64((aOrbiterK * 18316231099054203683U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 10103207278550444685U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 10415809965217261104U;
            aOrbiterD = RotL64((aOrbiterD * 16562732599511350217U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 17435033201864058457U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 5540494424887364682U;
            aOrbiterJ = RotL64((aOrbiterJ * 18230910315317249045U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 18020151683897013854U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 13296600294247799698U;
            aOrbiterH = RotL64((aOrbiterH * 10000194329456668845U), 13U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterD, 23U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + (RotL64(aOrbiterG, 60U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterE, 39U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 43U));
            aIngress = aIngress + RotL64(aOrbiterF, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterG, 23U)) + aOrbiterA);
            aWandererK = aWandererK + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterD, 41U)) + aOrbiterK) + aPhaseFWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 35U) + aOrbiterI) + RotL64(aOrbiterH, 28U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 43U)) + aOrbiterB) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 30U) + RotL64(aOrbiterB, 51U)) + aOrbiterC);
            aWandererG = aWandererG + (((RotL64(aPrevious, 23U) + aOrbiterA) + RotL64(aOrbiterI, 57U)) + RotL64(aCarry, 29U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 37U) + aOrbiterK) + RotL64(aOrbiterB, 19U));
            aWandererB = aWandererB + (((RotL64(aIngress, 27U) + aOrbiterE) + RotL64(aOrbiterH, 37U)) + RotL64(aCarry, 19U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 56U) + RotL64(aOrbiterF, 13U)) + aOrbiterJ);
            aWandererC = aWandererC + (((RotL64(aIngress, 13U) + RotL64(aOrbiterH, 60U)) + aOrbiterA) + aNonceWordC);
            aWandererD = aWandererD ^ ((RotL64(aCross, 11U) + aOrbiterK) + RotL64(aOrbiterF, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 10U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 21U));
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererA);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 37U));
            aCarry = aCarry + RotL64(aWandererH, 43U);
            aCarry = aCarry + RotL64(aIngress, 14U);
            aCarry = aCarry ^ aNonceWordJ;
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

void TwistExpander_Golf_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x81F70D1EBEDD3E57ULL + 0xFD9A918FD483773FULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xEFD65432FF56E115ULL + 0xCFF4AAAFF3824C90ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xDFB6E846E0D901D3ULL + 0x8234FE12DF4378E8ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xF7A7001AB800DC0DULL + 0xAAC4D77474EC6D07ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xF8CC5D0A4EF3F39BULL + 0xC809AC667684ADCEULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xC77E9EE56C21F19DULL + 0xACEE1854DD7211D5ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xFEE8A3350B2E1F71ULL + 0x8C0356E7CA9B0387ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xDA5CE705B7BA4ECDULL + 0xB2268E06BBE71E61ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xAD31220C7BD7D00BULL + 0xF5FCBB0ED928E30CULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xCCB69D6156330585ULL + 0x9453A0A5AA0AC494ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xEDA14A2E7B9D14F9ULL + 0xE0DED27D610319E6ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xFC105EE09E87BC89ULL + 0x8030BABF3018A245ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xF72E924F1F9C3341ULL + 0xD3761E17723F9839ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xE8166321152C92EFULL + 0xF652BA5C1A5FBC95ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xD6355CB67C7F14A1ULL + 0xAE483092CC3F2668ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xDC51E80CE04410D1ULL + 0xAE0FA471CD5E652DULL);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 4698U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 5065U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 1328U)) & S_BLOCK1], 40U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 1758U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aIngress, 35U)) ^ (RotL64(aCarry, 57U) + RotL64(aPrevious, 18U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterD = (aWandererD + RotL64(aPrevious, 19U)) + 826930775230515406U;
            aOrbiterK = (aWandererE + RotL64(aCross, 47U)) + 5137814617363250861U;
            aOrbiterG = ((aWandererF + RotL64(aIngress, 51U)) + 14761561947426681616U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = (aWandererB + RotL64(aScatter, 6U)) + 12773023438753662590U;
            aOrbiterJ = (aWandererK + RotL64(aIngress, 43U)) + 7331345852207096322U;
            aOrbiterE = ((aWandererC + RotL64(aCross, 27U)) + RotL64(aCarry, 5U)) + 3899381212671247460U;
            aOrbiterH = (aWandererG + RotL64(aPrevious, 35U)) + 10072004147620068599U;
            aOrbiterA = ((((aWandererI + RotL64(aScatter, 11U)) + RotL64(aCarry, 57U)) + 3424585039401897560U) + aPhaseFOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1]) + aNonceWordO;
            aOrbiterF = (aWandererJ + RotL64(aCross, 39U)) + 8246760141625966321U;
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 37U)) + RotL64(aCarry, 37U)) + 3655992860610853290U;
            aOrbiterC = (aWandererH + RotL64(aIngress, 56U)) + 11154618022505863898U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 15629361991059709973U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 10842068502278489664U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17223002513104960799U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 5571312349016336686U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 589313823745748879U) ^ aNonceWordG;
            aOrbiterE = RotL64((aOrbiterE * 1356685926549786027U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 13633457935771935260U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 12684602052812183096U;
            aOrbiterD = RotL64((aOrbiterD * 4689206269919806711U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 5711307583717354204U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 7181854170553728211U;
            aOrbiterI = RotL64((aOrbiterI * 9835601115561325911U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 1884620014396115821U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 1471516373272364262U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5126319375714848029U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 742739371092077733U) + aNonceWordP;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 8075893317715227838U;
            aOrbiterF = RotL64((aOrbiterF * 11208274111743259795U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 8179547722249281263U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 15305282712174742323U;
            aOrbiterC = RotL64((aOrbiterC * 7951986906055462929U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 1430543231751281079U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 14585341768267283387U) ^ aNonceWordE;
            aOrbiterK = RotL64((aOrbiterK * 313213844964269133U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 8123889986027932297U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 2081696191347150910U;
            aOrbiterJ = RotL64((aOrbiterJ * 4869653441012615053U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 10166788886199265936U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 15927074835525735601U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6747650218540675523U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 6997764816848988590U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 826930775230515406U;
            aOrbiterB = RotL64((aOrbiterB * 9943232461538279601U), 39U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterD, 21U);
            aIngress = aIngress + (RotL64(aOrbiterH, 56U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterK, 27U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 11U));
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterF, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aCross, 23U) + aOrbiterK) + RotL64(aOrbiterB, 19U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 53U) + RotL64(aOrbiterC, 23U)) + aOrbiterG) + RotL64(aCarry, 3U)) + aNonceWordF);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 27U) + aOrbiterD) + RotL64(aOrbiterB, 56U)) + aNonceWordN);
            aWandererG = aWandererG + (((RotL64(aIngress, 29U) + aOrbiterK) + RotL64(aOrbiterE, 3U)) + RotL64(aCarry, 29U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 4U) + RotL64(aOrbiterD, 29U)) + aOrbiterJ) + aNonceWordC);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 13U) + aOrbiterJ) + RotL64(aOrbiterI, 37U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterA, 47U));
            aWandererI = aWandererI + (((RotL64(aCross, 47U) + RotL64(aOrbiterF, 51U)) + aOrbiterK) + aPhaseFWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 51U) + aOrbiterG) + RotL64(aOrbiterD, 43U));
            aWandererH = aWandererH + ((RotL64(aCross, 6U) + RotL64(aOrbiterD, 10U)) + aOrbiterH);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterA, 39U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererJ, 54U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererC, 5U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordD);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 5471U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 8760U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 9012U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 7838U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aIngress, 57U)) + (RotL64(aPrevious, 37U) ^ RotL64(aCarry, 10U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterD = (aWandererB + RotL64(aPrevious, 29U)) + 9107326720193244489U;
            aOrbiterI = ((aWandererA + RotL64(aCross, 27U)) + RotL64(aCarry, 13U)) + 10868585484401664145U;
            aOrbiterG = ((aWandererF + RotL64(aScatter, 58U)) + 13637736741437846622U) + aNonceWordG;
            aOrbiterE = ((aWandererK + RotL64(aIngress, 53U)) + 6130725216183918844U) + aNonceWordP;
            aOrbiterC = (aWandererE + RotL64(aCross, 5U)) + 2063834478521338187U;
            aOrbiterA = (((aWandererD + RotL64(aScatter, 37U)) + RotL64(aCarry, 35U)) + 8564870627911949158U) + aPhaseFOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = ((aWandererG + RotL64(aIngress, 47U)) + RotL64(aCarry, 53U)) + 6524015751064086390U;
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 19U)) + 9874937766875388236U;
            aOrbiterH = ((aWandererH + RotL64(aIngress, 60U)) + 14723718409522680894U) + aPhaseFOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = (aWandererJ + RotL64(aPrevious, 3U)) + 13767059954741528279U;
            aOrbiterB = ((aWandererI + RotL64(aCross, 13U)) + 6387608251033722169U) + aNonceWordF;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 5391425980008431000U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 11524218415655093779U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12508457981779189389U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 155510463350385905U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 10554591788433641311U;
            aOrbiterI = RotL64((aOrbiterI * 5412084824127934293U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 8662160162966241542U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 5092555636369853727U;
            aOrbiterC = RotL64((aOrbiterC * 433807340167635499U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 7163345798448796101U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 695089002178413267U;
            aOrbiterK = RotL64((aOrbiterK * 17302689458565434475U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 5409173939213468972U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 15349690077393827541U;
            aOrbiterH = RotL64((aOrbiterH * 10984681254001609841U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 12376011890751302027U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 7809614158898158383U;
            aOrbiterD = RotL64((aOrbiterD * 13845113198736843629U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 13031938699536449576U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 3983178190194056516U) ^ aNonceWordN;
            aOrbiterE = RotL64((aOrbiterE * 1341678482929213405U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 5567935037909671790U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 17137042627663349797U;
            aOrbiterA = RotL64((aOrbiterA * 13535586899620672373U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 8726085717433137208U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 13154097637429217548U;
            aOrbiterJ = RotL64((aOrbiterJ * 5523758597936082363U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 4030516340575723215U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 7121696965917254968U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13569584361980228493U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 12079991626282752674U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 9107326720193244489U;
            aOrbiterB = RotL64((aOrbiterB * 7225937408665051799U), 47U);
            //
            aIngress = RotL64(aOrbiterJ, 27U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 37U));
            aIngress = aIngress + (RotL64(aOrbiterF, 39U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterE, 46U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterC, 51U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterH, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterB, 41U)) + aOrbiterD);
            aWandererH = aWandererH + ((RotL64(aIngress, 41U) + aOrbiterI) + RotL64(aOrbiterJ, 46U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterC, 53U)) + aOrbiterE);
            aWandererB = aWandererB + ((RotL64(aCross, 10U) + aOrbiterB) + RotL64(aOrbiterH, 11U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterH, 43U)) + aOrbiterF);
            aWandererD = aWandererD + ((((RotL64(aCross, 3U) + aOrbiterA) + RotL64(aOrbiterG, 56U)) + RotL64(aCarry, 43U)) + aNonceWordC);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 39U) + RotL64(aOrbiterE, 35U)) + aOrbiterK) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aPrevious, 26U) + aOrbiterJ) + RotL64(aOrbiterD, 5U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 53U) + aOrbiterG) + RotL64(aOrbiterD, 23U)) + aPhaseFWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 23U) + aOrbiterC) + RotL64(aOrbiterG, 21U)) + RotL64(aCarry, 39U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 29U) + aOrbiterI) + RotL64(aOrbiterA, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 46U) ^ aWandererD);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + (RotL64(aWandererH, 41U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererI, 36U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordD);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 14159U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneA[((aIndex + 11321U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 13814U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 15302U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aPrevious, 23U)) + (RotL64(aIngress, 56U) ^ RotL64(aCarry, 11U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterA = (aWandererE + RotL64(aPrevious, 5U)) + 4622023259121087483U;
            aOrbiterJ = (((aWandererI + RotL64(aIngress, 11U)) + RotL64(aCarry, 39U)) + 10253505250223501352U) + aPhaseFOrbiterAssignSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterI = (((aWandererJ + RotL64(aScatter, 27U)) + RotL64(aCarry, 3U)) + 17133877904420462669U) + aNonceWordF;
            aOrbiterH = ((aWandererK + RotL64(aCross, 35U)) + 6162827793741796700U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = (aWandererA + RotL64(aScatter, 37U)) + 9610986424765907615U;
            aOrbiterG = (aWandererD + RotL64(aIngress, 54U)) + 11210747154264753754U;
            aOrbiterK = (aWandererH + RotL64(aCross, 51U)) + 16554205219580654546U;
            aOrbiterC = (aWandererB + RotL64(aPrevious, 41U)) + 10352576357413766388U;
            aOrbiterB = ((aWandererG + RotL64(aScatter, 57U)) + 3651845783283479752U) + aNonceWordL;
            aOrbiterD = (aWandererC + RotL64(aPrevious, 46U)) + 18145542190463500476U;
            aOrbiterF = ((aWandererF + RotL64(aCross, 3U)) + RotL64(aCarry, 29U)) + 5415609566767162857U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 2033734872464201570U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 3507213117125813345U;
            aOrbiterI = RotL64((aOrbiterI * 5453058336688881113U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 8716253393049851856U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 695984869565941856U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8377921610764044735U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 7661578828878284931U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 906654265099155956U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8117625377607536949U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 6050049984731254612U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 17882717590338190821U) ^ aNonceWordO;
            aOrbiterE = RotL64((aOrbiterE * 10807367411402733215U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 4996521991532815957U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 4246460672800604436U;
            aOrbiterC = RotL64((aOrbiterC * 12047466401960824903U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 8700148116452518842U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 10039050281847466206U;
            aOrbiterD = RotL64((aOrbiterD * 11884791271239660157U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 4513844680425845372U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 3037563127442815153U) ^ aNonceWordB;
            aOrbiterA = RotL64((aOrbiterA * 18363509277992292407U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 1005237931570968724U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 1373258132025712065U;
            aOrbiterH = RotL64((aOrbiterH * 10458020799382532395U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 12759144329395682277U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 5139371668116336931U;
            aOrbiterK = RotL64((aOrbiterK * 10761543179345026943U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 3211005174890625715U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 18045286961878287418U;
            aOrbiterB = RotL64((aOrbiterB * 4536094526540761611U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 4454078771279674978U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 4622023259121087483U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8991756794989027019U), 35U);
            //
            aIngress = RotL64(aOrbiterF, 58U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 5U));
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 53U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 23U));
            aIngress = aIngress + RotL64(aOrbiterD, 34U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aIngress, 37U) + aOrbiterE) + RotL64(aOrbiterI, 3U)) + aNonceWordD);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterC, 43U)) + aOrbiterK);
            aWandererH = aWandererH + ((RotL64(aPrevious, 44U) + aOrbiterC) + RotL64(aOrbiterE, 50U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterI, 47U)) + aOrbiterF) + aPhaseFWandererUpdateSaltE[((aIndex + 26U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 11U) + aOrbiterJ) + RotL64(aOrbiterB, 57U)) + RotL64(aCarry, 23U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterA, 23U)) + aOrbiterD) + aNonceWordE);
            aWandererC = aWandererC + (((RotL64(aCross, 35U) + RotL64(aOrbiterF, 39U)) + aOrbiterA) + aPhaseFWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 13U) + aOrbiterC) + RotL64(aOrbiterD, 52U));
            aWandererD = aWandererD + (((RotL64(aScatter, 5U) + RotL64(aOrbiterJ, 11U)) + aOrbiterG) + aNonceWordI);
            aWandererE = aWandererE ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterA, 19U)) + aOrbiterJ);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 26U) + aOrbiterF) + RotL64(aOrbiterH, 37U)) + RotL64(aCarry, 47U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 21U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 60U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererI, 52U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ aNonceWordJ;
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 17938U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 20463U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 18079U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 17979U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 6U) + RotL64(aPrevious, 53U)) ^ (RotL64(aIngress, 39U) ^ RotL64(aCarry, 23U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterD = (((aWandererG + RotL64(aCross, 5U)) + RotL64(aCarry, 37U)) + 2225397913940961213U) + aNonceWordJ;
            aOrbiterF = ((aWandererA + RotL64(aIngress, 51U)) + 8342544893601343643U) + aNonceWordD;
            aOrbiterE = (aWandererI + RotL64(aPrevious, 37U)) + 162922186381417187U;
            aOrbiterI = (aWandererH + RotL64(aScatter, 53U)) + 11660218373710972210U;
            aOrbiterG = ((aWandererC + RotL64(aIngress, 43U)) + RotL64(aCarry, 43U)) + 14909034764605802354U;
            aOrbiterB = (aWandererF + RotL64(aCross, 30U)) + 16776955237009701511U;
            aOrbiterA = ((aWandererK + RotL64(aScatter, 35U)) + RotL64(aCarry, 23U)) + 5834487809188925253U;
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 39U)) + 1498492772767040320U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterC = (aWandererD + RotL64(aIngress, 21U)) + 4161765458781579617U;
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 57U)) + 10511923076962447765U;
            aOrbiterJ = ((aWandererB + RotL64(aCross, 48U)) + 8575954471692620021U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 6536325446331340573U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 1790628986900286346U;
            aOrbiterE = RotL64((aOrbiterE * 5262997114200816715U), 37U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 2623814807619278590U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 11676970995834706612U;
            aOrbiterG = RotL64((aOrbiterG * 10057461115132434901U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 13836786354224256591U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 6293096163612129260U;
            aOrbiterB = RotL64((aOrbiterB * 8977954126326217153U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 4271144764978661248U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 15938494256992560202U;
            aOrbiterA = RotL64((aOrbiterA * 10004841288382726739U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 11038155227307702976U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 12408749795071243930U;
            aOrbiterK = RotL64((aOrbiterK * 5527720475032868855U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 1673665849053496882U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 12866353361497103629U;
            aOrbiterC = RotL64((aOrbiterC * 6041125499398924871U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 10673935802381580966U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 8946776538955520352U;
            aOrbiterH = RotL64((aOrbiterH * 12293084177712710021U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 16294935203370452805U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 4697759331563852212U;
            aOrbiterJ = RotL64((aOrbiterJ * 14407806317275373043U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 17633118874112283386U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 89602424202721105U;
            aOrbiterD = RotL64((aOrbiterD * 1010654844008668685U), 5U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterJ) + 4019154066191316616U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordB;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 15029609435149173243U;
            aOrbiterF = RotL64((aOrbiterF * 3522168783248806167U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 11765990698273078458U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 2225397913940961213U;
            aOrbiterI = RotL64((aOrbiterI * 8471538922288466221U), 21U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterH, 4U);
            aIngress = aIngress + (RotL64(aOrbiterF, 21U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 39U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 23U));
            aIngress = aIngress + RotL64(aOrbiterJ, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aCross, 40U) + aOrbiterK) + RotL64(aOrbiterC, 23U)) + RotL64(aCarry, 13U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterK, 28U)) + aOrbiterF) + aPhaseFWandererUpdateSaltB[((aIndex + 26U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aIngress, 27U) + RotL64(aOrbiterB, 51U)) + aOrbiterF);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterG, 41U)) + aOrbiterK);
            aWandererA = aWandererA + (((RotL64(aScatter, 29U) + aOrbiterH) + RotL64(aOrbiterG, 37U)) + RotL64(aCarry, 29U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 13U) + aOrbiterG) + RotL64(aOrbiterE, 19U));
            aWandererH = aWandererH + (((RotL64(aCross, 37U) + aOrbiterJ) + RotL64(aOrbiterE, 21U)) + aNonceWordI);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 24U) + RotL64(aOrbiterD, 39U)) + aOrbiterE);
            aWandererD = aWandererD + ((RotL64(aIngress, 21U) + RotL64(aOrbiterB, 35U)) + aOrbiterA);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 53U) + aOrbiterE) + RotL64(aOrbiterK, 3U));
            aWandererC = aWandererC + ((RotL64(aCross, 47U) + aOrbiterC) + RotL64(aOrbiterI, 14U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 50U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 21U));
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererH);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + RotL64(aWandererK, 44U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordG);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 25811U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneA[((aIndex + 22938U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 23587U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneA[((aIndex + 26082U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 41U) ^ RotL64(aIngress, 6U)) ^ (RotL64(aCross, 19U) + RotL64(aPrevious, 57U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterI = (aWandererA + RotL64(aPrevious, 35U)) + 17668251151213543491U;
            aOrbiterJ = (((aWandererI + RotL64(aScatter, 12U)) + RotL64(aCarry, 21U)) + 16101602509895104517U) + aPhaseFOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = (aWandererE + RotL64(aIngress, 47U)) + 9083915270773304935U;
            aOrbiterD = (aWandererF + RotL64(aCross, 21U)) + 12810720730318214811U;
            aOrbiterF = (aWandererG + RotL64(aScatter, 41U)) + 18113428002071925621U;
            aOrbiterH = ((aWandererD + RotL64(aCross, 43U)) + 1582208899354109878U) + aPhaseFOrbiterAssignSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = (aWandererJ + RotL64(aIngress, 5U)) + 4180688104819188154U;
            aOrbiterE = (aWandererH + RotL64(aPrevious, 58U)) + 8954598189262820611U;
            aOrbiterG = ((aWandererB + RotL64(aIngress, 51U)) + 15360094153175355879U) + aNonceWordJ;
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 3U)) + RotL64(aCarry, 57U)) + 8383954114668216260U;
            aOrbiterK = ((aWandererC + RotL64(aCross, 37U)) + RotL64(aCarry, 39U)) + 15626783326234049197U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 10609978564404958066U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 17656516608997517984U;
            aOrbiterB = RotL64((aOrbiterB * 4590620354119899777U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 760077259110786536U) + aNonceWordI;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 3597338735888033063U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6548831472863517621U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 4431777844935985157U) + aNonceWordL;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 10710423172154671296U;
            aOrbiterE = RotL64((aOrbiterE * 16267496318491473315U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 10240882795242085185U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 7826053487019825891U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15053729937684375907U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 9418883403715727353U) + aNonceWordG;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 11507423614799075545U;
            aOrbiterI = RotL64((aOrbiterI * 16189463984557044693U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 11545217316421066655U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 617921402135485341U;
            aOrbiterD = RotL64((aOrbiterD * 8182920764965471653U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 14456933220749921009U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 7990243583564535387U;
            aOrbiterA = RotL64((aOrbiterA * 5994900368027985469U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 14023633125757654751U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 11319146808574958827U;
            aOrbiterG = RotL64((aOrbiterG * 13676159969338309307U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 14161653180846538446U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 17993503892528842342U;
            aOrbiterK = RotL64((aOrbiterK * 12184170842617942651U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 10449311783872638478U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 17210495321003036773U;
            aOrbiterJ = RotL64((aOrbiterJ * 17591257107603354151U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 14586515403314763393U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 17668251151213543491U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9367185933291003363U), 39U);
            //
            aIngress = RotL64(aOrbiterH, 60U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterF, 43U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 53U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 41U));
            aIngress = aIngress + RotL64(aOrbiterG, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterG, 51U)) + aOrbiterH) + aNonceWordE) + aPhaseFWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 43U) + aOrbiterH) + RotL64(aOrbiterJ, 5U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 60U) + aOrbiterK) + RotL64(aOrbiterI, 22U));
            aWandererA = aWandererA + (((RotL64(aCross, 35U) + aOrbiterJ) + RotL64(aOrbiterF, 37U)) + RotL64(aCarry, 43U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterE, 47U)) + aOrbiterD);
            aWandererC = aWandererC + (((RotL64(aScatter, 41U) + RotL64(aOrbiterC, 29U)) + aOrbiterG) + RotL64(aCarry, 5U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterB, 41U)) + aOrbiterG);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 29U) + RotL64(aOrbiterJ, 11U)) + aOrbiterD);
            aWandererF = aWandererF ^ ((((RotL64(aScatter, 10U) + RotL64(aOrbiterJ, 14U)) + aOrbiterI) + aNonceWordK) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aCross, 51U) + RotL64(aOrbiterA, 39U)) + aOrbiterH);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 23U) + aOrbiterJ) + RotL64(aOrbiterK, 27U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 60U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererI);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + (RotL64(aWandererG, 14U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererJ, 41U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordF);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 29391U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29061U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32287U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneB[((aIndex + 30482U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 48U) ^ RotL64(aCross, 5U)) + (RotL64(aPrevious, 35U) ^ RotL64(aCarry, 21U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterA = ((aWandererB + RotL64(aScatter, 23U)) + 16802219662864902427U) + aNonceWordK;
            aOrbiterF = (((aWandererA + RotL64(aCross, 51U)) + RotL64(aCarry, 51U)) + 14332033461409490629U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = (aWandererI + RotL64(aIngress, 26U)) + 8781794298640286845U;
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 43U)) + RotL64(aCarry, 11U)) + 8459933908074937264U;
            aOrbiterD = (aWandererJ + RotL64(aIngress, 19U)) + 1883580287986004426U;
            aOrbiterJ = (aWandererH + RotL64(aPrevious, 39U)) + 17500258188004626118U;
            aOrbiterK = (aWandererK + RotL64(aScatter, 29U)) + 7934811305150872870U;
            aOrbiterE = (aWandererE + RotL64(aCross, 10U)) + 6380363892361098905U;
            aOrbiterC = ((aWandererF + RotL64(aScatter, 3U)) + 12623079132626676910U) + aNonceWordC;
            aOrbiterI = ((aWandererD + RotL64(aIngress, 35U)) + RotL64(aCarry, 37U)) + 10455208121949202703U;
            aOrbiterB = ((aWandererC + RotL64(aCross, 21U)) + 8805532707916767629U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 9161544391400377699U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 3501434325829663268U;
            aOrbiterG = RotL64((aOrbiterG * 7933545151293799637U), 27U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterH) + 651783304096081996U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1]) + aNonceWordD;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 441505031509930622U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8045355432310956143U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 1771159983581326424U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 15227946417377695989U;
            aOrbiterJ = RotL64((aOrbiterJ * 1563141188972797601U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 4153717524193279095U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 4404521756523902829U;
            aOrbiterK = RotL64((aOrbiterK * 1410342912973206203U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 6231945075461813285U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 3864780227164426690U;
            aOrbiterE = RotL64((aOrbiterE * 18031353247480673617U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 1509699687948576558U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 17316114302489411191U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15490661284980281585U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 2250572827340157410U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 6403966113144372915U;
            aOrbiterI = RotL64((aOrbiterI * 726441947009132383U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 2329903609147403156U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 2486330017319455238U;
            aOrbiterB = RotL64((aOrbiterB * 17427461345935191757U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 9333421733051210144U) + aNonceWordI;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 14779925626161889533U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9120486933147706541U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 4343688173541745311U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 12686722305368397686U;
            aOrbiterF = RotL64((aOrbiterF * 17484250022537912537U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 3745163111502795473U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 16802219662864902427U;
            aOrbiterH = RotL64((aOrbiterH * 4343730534036919417U), 3U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterH, 35U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 37U));
            aIngress = aIngress + (RotL64(aOrbiterI, 51U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterB, 44U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterD, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 27U) + aOrbiterE) + RotL64(aOrbiterF, 21U));
            aWandererF = aWandererF + ((RotL64(aIngress, 23U) + aOrbiterC) + RotL64(aOrbiterD, 50U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterI, 5U)) + aOrbiterC);
            aWandererI = aWandererI + ((RotL64(aScatter, 11U) + RotL64(aOrbiterK, 35U)) + aOrbiterA);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterC, 41U)) + aOrbiterE);
            aWandererA = aWandererA + (((RotL64(aIngress, 44U) + RotL64(aOrbiterH, 43U)) + aOrbiterJ) + RotL64(aCarry, 35U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 29U) + aOrbiterF) + RotL64(aOrbiterJ, 37U));
            aWandererH = aWandererH + (((RotL64(aScatter, 21U) + RotL64(aOrbiterI, 46U)) + aOrbiterB) + aPhaseFWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 19U) + aOrbiterA) + RotL64(aOrbiterJ, 39U));
            aWandererC = aWandererC + (((RotL64(aScatter, 5U) + aOrbiterB) + RotL64(aOrbiterA, 53U)) + RotL64(aCarry, 57U));
            aWandererK = aWandererK ^ ((((RotL64(aCross, 34U) + aOrbiterG) + RotL64(aOrbiterB, 27U)) + aNonceWordA) + aPhaseFWandererUpdateSaltE[((aIndex + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererA);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 30U));
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 41U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererB, 22U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordN);
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

void TwistExpander_Golf_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 418U)) & S_BLOCK1], 47U) ^ RotL64(aKeyRowReadA[((aIndex + 4408U)) & W_KEY1], 38U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 478U)) & W_KEY1], 20U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 3866U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCross, 53U)) + (RotL64(aCarry, 4U) + RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = ((aWandererG + RotL64(aIngress, 47U)) + 2168513956284366370U) + aPhaseCOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = (aWandererD + RotL64(aPrevious, 19U)) + 10290361969974613111U;
            aOrbiterB = ((aWandererH + RotL64(aScatter, 27U)) + RotL64(aCarry, 51U)) + 15673836275828498050U;
            aOrbiterH = (aWandererF + RotL64(aCross, 23U)) + 16600540024145812236U;
            aOrbiterG = (aWandererI + RotL64(aScatter, 14U)) + 9428052101528111892U;
            aOrbiterK = ((aWandererJ + RotL64(aCross, 41U)) + RotL64(aCarry, 39U)) + 12763657928312763377U;
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 35U)) + RotL64(aCarry, 27U)) + 10751286982008662485U;
            aOrbiterE = (aWandererA + RotL64(aIngress, 53U)) + 1708230173038057979U;
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 60U)) + 4011389705422783816U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 11704428328093077714U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 2055336619674699284U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6374289210096410907U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 1870865272102705804U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 3574214263751923179U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13132083406834413563U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 984611970726966186U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 15207945449947643672U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9539470161576639981U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 4181398506373973169U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 15222345431506025949U;
            aOrbiterJ = RotL64((aOrbiterJ * 6925143692628659467U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 15023513452326240962U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 14965669361708810699U;
            aOrbiterI = RotL64((aOrbiterI * 587008860996713147U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 7985755518735406360U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 225592097619240187U;
            aOrbiterH = RotL64((aOrbiterH * 2313509354133400439U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 3659537916566939383U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 17043668033610689611U;
            aOrbiterF = RotL64((aOrbiterF * 10797634709118100773U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 10217321522161675848U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 8013663869536146842U;
            aOrbiterA = RotL64((aOrbiterA * 2293233079384777175U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 13762445330867496042U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 2692400019659269106U;
            aOrbiterG = RotL64((aOrbiterG * 167704184292219399U), 43U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterH, 51U);
            aIngress = aIngress + (RotL64(aOrbiterA, 35U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 20U));
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aScatter, 23U) + aOrbiterA) + RotL64(aOrbiterF, 19U));
            aWandererD = aWandererD + ((RotL64(aIngress, 51U) + RotL64(aOrbiterG, 23U)) + aOrbiterI);
            aWandererA = aWandererA ^ ((RotL64(aCross, 14U) + aOrbiterA) + RotL64(aOrbiterG, 42U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterJ, 27U)) + aOrbiterF);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterH, 37U)) + aOrbiterB);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 43U) + RotL64(aOrbiterE, 13U)) + aOrbiterF) + RotL64(aCarry, 19U)) + aPhaseCWandererUpdateSaltA[((aIndex + 26U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterI, 46U)) + aOrbiterB);
            aWandererF = aWandererF + (((RotL64(aCross, 29U) + RotL64(aOrbiterK, 3U)) + aOrbiterB) + RotL64(aCarry, 53U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 38U) + RotL64(aOrbiterK, 57U)) + aOrbiterF) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + (RotL64(aWandererI, 10U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererA, 27U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 10097U)) & S_BLOCK1], 60U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 13638U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 14378U)) & W_KEY1], 39U) ^ RotL64(aKeyRowReadB[((aIndex + 13230U)) & W_KEY1], 50U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCross, 51U)) + (RotL64(aPrevious, 27U) ^ RotL64(aCarry, 14U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = (aWandererE + RotL64(aScatter, 14U)) + 9023059520606551446U;
            aOrbiterC = (aWandererG + RotL64(aCross, 41U)) + 662441755115638133U;
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 37U)) + RotL64(aCarry, 11U)) + 16957253361196144712U;
            aOrbiterD = ((aWandererD + RotL64(aIngress, 3U)) + 7840955025765308605U) + aPhaseCOrbiterAssignSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterB = (aWandererC + RotL64(aPrevious, 27U)) + 346855809270395799U;
            aOrbiterH = (aWandererA + RotL64(aScatter, 19U)) + 16099139781586668343U;
            aOrbiterE = (aWandererI + RotL64(aCross, 56U)) + 3706457327118322098U;
            aOrbiterJ = (((aWandererH + RotL64(aIngress, 51U)) + RotL64(aCarry, 35U)) + 12166825885547622870U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = ((aWandererJ + RotL64(aCross, 47U)) + RotL64(aCarry, 21U)) + 7792658665720344200U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 7128477606152986326U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 11116533962780290084U;
            aOrbiterI = RotL64((aOrbiterI * 11993485572912492297U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 10443889548568288532U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 4402387036946561017U;
            aOrbiterB = RotL64((aOrbiterB * 9032964741841833277U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 13002706161178447654U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 13929727277530310708U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7005639090871200285U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 10949073760696935106U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 15405923432006783533U;
            aOrbiterJ = RotL64((aOrbiterJ * 17989565878445202495U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 18096057968822208905U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 3032155040484574973U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 448597307502544605U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 17462076466907467134U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 15471015427013701406U;
            aOrbiterK = RotL64((aOrbiterK * 6113474000571976139U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 3549031751266594344U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 14243218483842508113U;
            aOrbiterD = RotL64((aOrbiterD * 9041601306479302047U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 5803147589312920032U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 5549470512227427855U;
            aOrbiterH = RotL64((aOrbiterH * 12592362489263862879U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 10076661824293832189U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 3196799148974716550U;
            aOrbiterC = RotL64((aOrbiterC * 8183276968961467775U), 39U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterD, 10U);
            aIngress = aIngress + (RotL64(aOrbiterE, 35U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterG, 27U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterC, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aScatter, 22U) + aOrbiterH) + RotL64(aOrbiterB, 5U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 41U) + aOrbiterG) + RotL64(aOrbiterC, 52U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterH, 43U)) + aOrbiterI) + RotL64(aCarry, 19U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterI, 23U)) + aOrbiterD) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 27U) + aOrbiterG) + RotL64(aOrbiterI, 39U)) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 11U) + aOrbiterG) + RotL64(aOrbiterD, 60U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 47U) + aOrbiterE) + RotL64(aOrbiterG, 47U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 6U) + RotL64(aOrbiterB, 19U)) + aOrbiterK) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aPrevious, 57U) + aOrbiterB) + RotL64(aOrbiterJ, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 44U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererK, 37U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22978U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneA[((aIndex + 17718U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 16457U)) & W_KEY1], 5U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 20037U)) & W_KEY1], 56U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 51U) ^ RotL64(aCarry, 23U)) ^ (RotL64(aPrevious, 35U) + RotL64(aCross, 4U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = (aWandererF + RotL64(aCross, 43U)) + 15652862298542575895U;
            aOrbiterH = (aWandererH + RotL64(aScatter, 39U)) + 16925323928418184554U;
            aOrbiterC = (aWandererA + RotL64(aIngress, 53U)) + 4413861484961668394U;
            aOrbiterI = (aWandererI + RotL64(aPrevious, 12U)) + 2215946422098155969U;
            aOrbiterK = ((aWandererG + RotL64(aCross, 21U)) + RotL64(aCarry, 23U)) + 14975185533513111110U;
            aOrbiterG = (((aWandererD + RotL64(aIngress, 47U)) + RotL64(aCarry, 57U)) + 9711613814905834552U) + aPhaseCOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = (aWandererB + RotL64(aPrevious, 5U)) + 13154957291850149471U;
            aOrbiterE = ((aWandererC + RotL64(aScatter, 57U)) + 5058313016418534840U) + aPhaseCOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 26U)) + RotL64(aCarry, 39U)) + 15011423472941211620U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 2030053257469580168U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 150530795186791193U;
            aOrbiterC = RotL64((aOrbiterC * 11106050063717096073U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 10878237472104183427U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 11724672539469573109U;
            aOrbiterD = RotL64((aOrbiterD * 16158741837357985395U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 9589700906445846956U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 1367381624958248949U;
            aOrbiterI = RotL64((aOrbiterI * 8459515089081211977U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 12003215666757518106U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 11232479330848006729U;
            aOrbiterH = RotL64((aOrbiterH * 10993290955464593033U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 13013910456628561621U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 6092509838924105265U;
            aOrbiterK = RotL64((aOrbiterK * 805601154718006061U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 11999225836250312801U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 14421271973875748413U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9529010940887430157U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 15536288285741825272U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 2071793889925436679U;
            aOrbiterB = RotL64((aOrbiterB * 1526376970151714589U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 5622386476463436967U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 16147972771639168516U;
            aOrbiterE = RotL64((aOrbiterE * 11826916832825159095U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 4519892856053952290U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 12059500374938843538U;
            aOrbiterA = RotL64((aOrbiterA * 14987533625537956299U), 19U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterE, 35U);
            aIngress = aIngress + (RotL64(aOrbiterI, 18U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterA, 39U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterC, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterI, 57U)) + aOrbiterD);
            aWandererF = aWandererF + ((RotL64(aIngress, 48U) + RotL64(aOrbiterI, 34U)) + aOrbiterC);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterI, 5U)) + aOrbiterE);
            aWandererE = aWandererE + (((RotL64(aCross, 19U) + aOrbiterK) + RotL64(aOrbiterI, 53U)) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterB, 27U)) + aOrbiterC);
            aWandererG = aWandererG + (((RotL64(aPrevious, 13U) + aOrbiterB) + RotL64(aOrbiterG, 46U)) + RotL64(aCarry, 13U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 5U) + aOrbiterK) + RotL64(aOrbiterG, 23U)) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 28U) + aOrbiterD) + RotL64(aOrbiterH, 11U)) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 53U) + aOrbiterD) + RotL64(aOrbiterA, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererI);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 46U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + RotL64(aWandererC, 5U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 24619U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneB[((aIndex + 28521U)) & S_BLOCK1], 26U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31880U)) & S_BLOCK1], 46U) ^ RotL64(mSource[((aIndex + 31272U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 18U) ^ RotL64(aIngress, 41U)) + (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = (aWandererF + RotL64(aScatter, 19U)) + 2617613537256538553U;
            aOrbiterE = (((aWandererI + RotL64(aPrevious, 5U)) + RotL64(aCarry, 53U)) + 16642868916835132715U) + aPhaseCOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = (aWandererB + RotL64(aIngress, 24U)) + 10860291124337073254U;
            aOrbiterF = ((aWandererC + RotL64(aCross, 51U)) + RotL64(aCarry, 5U)) + 6432511273906902472U;
            aOrbiterC = ((aWandererA + RotL64(aScatter, 13U)) + RotL64(aCarry, 27U)) + 7505375005848241910U;
            aOrbiterJ = (aWandererJ + RotL64(aPrevious, 43U)) + 11086616004678821329U;
            aOrbiterI = (aWandererE + RotL64(aIngress, 57U)) + 3298830587569881951U;
            aOrbiterK = ((aWandererG + RotL64(aCross, 28U)) + 9775143140064220979U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = (aWandererK + RotL64(aScatter, 37U)) + 4147601326580823120U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 12245920269898100415U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 8391940489176734499U;
            aOrbiterD = RotL64((aOrbiterD * 9119606167674098007U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 17876893379544668477U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 18301882058180370541U;
            aOrbiterC = RotL64((aOrbiterC * 16680384667098921309U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 6869225862715140102U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 15404118372589259800U;
            aOrbiterI = RotL64((aOrbiterI * 5766851935950389915U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 17757381020518233814U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 17677969146092374455U;
            aOrbiterH = RotL64((aOrbiterH * 3469432916562405063U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 15783378556632870114U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 5792858258663697864U;
            aOrbiterF = RotL64((aOrbiterF * 12008981883482080427U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 11737803388202260296U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 16001927091970715330U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3062030309852922061U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 1749586939123286632U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 6169421068855905938U;
            aOrbiterK = RotL64((aOrbiterK * 12374789910763348695U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 10073586820719728062U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 17744171227198661555U;
            aOrbiterG = RotL64((aOrbiterG * 10658375268803957647U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 1149819647337612792U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 7725598665625892006U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15097586655234391559U), 39U);
            //
            aIngress = RotL64(aOrbiterI, 4U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + (RotL64(aOrbiterF, 37U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 51U));
            aIngress = aIngress + RotL64(aOrbiterE, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterI, 4U)) + aOrbiterE);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 18U) + aOrbiterE) + RotL64(aOrbiterJ, 27U)) + RotL64(aCarry, 53U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterD, 51U)) + aOrbiterC) + aPhaseCWandererUpdateSaltA[((aIndex + 20U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aCross, 5U) + RotL64(aOrbiterK, 23U)) + aOrbiterH);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 23U) + aOrbiterG) + RotL64(aOrbiterC, 39U)) + aPhaseCWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 53U) + aOrbiterJ) + RotL64(aOrbiterD, 19U)) + RotL64(aCarry, 23U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterC, 47U)) + aOrbiterJ);
            aWandererF = aWandererF + ((RotL64(aScatter, 11U) + aOrbiterF) + RotL64(aOrbiterJ, 12U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterK, 57U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererA, 41U);
            aCarry = aCarry + RotL64(aIngress, 26U);
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

void TwistExpander_Golf_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 4592U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4872U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 6455U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 1009U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 18U) + RotL64(aPrevious, 53U)) + (RotL64(aCarry, 5U) ^ RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = (((aWandererC + RotL64(aIngress, 3U)) + RotL64(aCarry, 35U)) + 12980104182836602177U) + aPhaseDOrbiterAssignSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterC = ((aWandererA + RotL64(aCross, 11U)) + RotL64(aCarry, 19U)) + 3172622203188863995U;
            aOrbiterF = (((aWandererH + RotL64(aPrevious, 35U)) + RotL64(aCarry, 57U)) + 1170974132219980203U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = (aWandererD + RotL64(aScatter, 43U)) + 6035201940965047490U;
            aOrbiterD = (aWandererE + RotL64(aIngress, 22U)) + 18033907118424996722U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 14604813424800580304U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 13720232492851066035U;
            aOrbiterF = RotL64((aOrbiterF * 8927246214721284759U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 3902659710585257448U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 8331560652661619868U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11418103770615560205U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 4485014147538689794U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 168202636924512424U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13711020666131492091U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 16227825670092707848U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 4792781933944671365U;
            aOrbiterC = RotL64((aOrbiterC * 15859849676231455283U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 12636865372722601282U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 18198291399585556632U;
            aOrbiterD = RotL64((aOrbiterD * 18155803890313399795U), 13U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterA, 60U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + RotL64(aOrbiterK, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aPrevious, 5U) + aOrbiterA) + RotL64(aOrbiterD, 39U)) + RotL64(aCarry, 27U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 13U) + aOrbiterK) + RotL64(aOrbiterA, 52U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterC, 13U)) + aOrbiterK) + RotL64(aCarry, 13U)) + aPhaseDWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 28U) + aOrbiterD) + RotL64(aOrbiterC, 5U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterA, 23U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 37U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererD, 47U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 15639U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 13567U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 11509U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 11195U)) & S_BLOCK1], 46U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 38U) ^ RotL64(aCarry, 11U)) + (RotL64(aCross, 53U) + RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = (aWandererD + RotL64(aIngress, 27U)) + 2672739400294801233U;
            aOrbiterK = ((aWandererF + RotL64(aScatter, 11U)) + RotL64(aCarry, 23U)) + 8475624545015101850U;
            aOrbiterB = (((aWandererE + RotL64(aPrevious, 47U)) + RotL64(aCarry, 41U)) + 1252755112289831257U) + aPhaseDOrbiterAssignSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = ((aWandererB + RotL64(aCross, 3U)) + 7938039507649183387U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 56U)) + RotL64(aCarry, 53U)) + 8167413146948861022U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 17712313989694374353U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 7637042279892596975U;
            aOrbiterB = RotL64((aOrbiterB * 13056020836704050293U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 15770412950033467341U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 3951812021898608685U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6623127125223204737U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 8656983621098246507U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 17943342344730687317U;
            aOrbiterH = RotL64((aOrbiterH * 16495519451034883813U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 3087677463651608668U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 16493240011924342788U;
            aOrbiterK = RotL64((aOrbiterK * 16898479041530771871U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 7750923317452683057U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 2185924841611106546U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 708072658250726381U), 13U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterH, 3U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 50U));
            aIngress = aIngress + RotL64(aOrbiterJ, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aCross, 51U) + aOrbiterH) + RotL64(aOrbiterJ, 10U)) + RotL64(aCarry, 5U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterJ, 53U)) + aOrbiterB) + aPhaseDWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 13U) + RotL64(aOrbiterK, 35U)) + aOrbiterA) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 4U) + RotL64(aOrbiterA, 19U)) + aOrbiterH);
            aWandererD = aWandererD + ((RotL64(aCross, 37U) + RotL64(aOrbiterK, 43U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 29U));
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererE, 21U);
            aCarry = aCarry + RotL64(aIngress, 40U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 21940U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneA[((aIndex + 16804U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17613U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 20875U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 3U) + RotL64(aCarry, 39U)) ^ (RotL64(aCross, 54U) ^ RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = (((aWandererI + RotL64(aScatter, 21U)) + RotL64(aCarry, 47U)) + 5576732410244514238U) + aPhaseDOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = (aWandererB + RotL64(aIngress, 60U)) + 2833808925935929629U;
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 37U)) + RotL64(aCarry, 11U)) + 3670188682914544792U;
            aOrbiterB = (((aWandererA + RotL64(aCross, 29U)) + RotL64(aCarry, 23U)) + 15759072378887814995U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = (aWandererH + RotL64(aIngress, 13U)) + 13934007231137439994U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 11022225696007690512U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 16989177104453635790U;
            aOrbiterI = RotL64((aOrbiterI * 14156758251105809453U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 9256930045263527091U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 17788596104417068290U;
            aOrbiterH = RotL64((aOrbiterH * 675554110563253305U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 17044369456673337625U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 1310908395523250343U;
            aOrbiterC = RotL64((aOrbiterC * 16305084373037705921U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 12067065689034065422U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 15130844248737512262U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9409499577465934107U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 14532689204495587494U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 8198147292120244178U;
            aOrbiterF = RotL64((aOrbiterF * 1418356389507740991U), 5U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterI, 27U);
            aIngress = aIngress + (RotL64(aOrbiterH, 53U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aIngress, 19U) + aOrbiterI) + RotL64(aOrbiterB, 35U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 47U) + aOrbiterI) + RotL64(aOrbiterH, 48U));
            aWandererI = aWandererI + (((RotL64(aCross, 57U) + RotL64(aOrbiterF, 57U)) + aOrbiterI) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 28U) + aOrbiterF) + RotL64(aOrbiterB, 11U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aIngress, 37U) + aOrbiterC) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 19U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererI, 38U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 30210U)) & S_BLOCK1], 48U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31030U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 26244U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 28304U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCarry, 4U)) + (RotL64(aIngress, 39U) ^ RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = (aWandererA + RotL64(aPrevious, 5U)) + 2915859148137000694U;
            aOrbiterA = ((aWandererI + RotL64(aIngress, 41U)) + 210680583721444425U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = (((aWandererD + RotL64(aScatter, 18U)) + RotL64(aCarry, 53U)) + 6668118118775650387U) + aPhaseDOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = ((aWandererG + RotL64(aCross, 53U)) + RotL64(aCarry, 23U)) + 15794200818099010989U;
            aOrbiterB = ((aWandererB + RotL64(aIngress, 29U)) + RotL64(aCarry, 5U)) + 6565076707062828369U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 16323164497808856719U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 7965435318816716560U;
            aOrbiterD = RotL64((aOrbiterD * 5984608704943623687U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 7390281030573369017U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 2269738866911824875U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1198697877998135567U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 9664014216039993873U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 18284857398028357633U;
            aOrbiterJ = RotL64((aOrbiterJ * 8402008251343393737U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 367667619795303009U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 7935945060956274197U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5481786693511955209U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 16683666162337789540U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 10655658270998102390U;
            aOrbiterB = RotL64((aOrbiterB * 15231596813382239841U), 27U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterD, 47U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 27U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterJ, 28U)) + aOrbiterD) + aPhaseDWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 51U) + aOrbiterJ) + RotL64(aOrbiterB, 5U)) + RotL64(aCarry, 39U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterI, 13U)) + aOrbiterJ);
            aWandererB = aWandererB + (((RotL64(aScatter, 28U) + aOrbiterD) + RotL64(aOrbiterA, 51U)) + RotL64(aCarry, 3U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 43U) + aOrbiterJ) + RotL64(aOrbiterA, 39U)) + aPhaseDWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 21U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererA, 13U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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

void TwistExpander_Golf_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 992U)) & S_BLOCK1], 42U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 7372U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 2601U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 2046U)) & S_BLOCK1], 10U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aPrevious, 57U)) ^ (RotL64(aIngress, 41U) ^ RotL64(aCarry, 22U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = (aWandererD + RotL64(aPrevious, 11U)) + 1888427424966603593U;
            aOrbiterF = (aWandererF + RotL64(aCross, 22U)) + 5436761445660415091U;
            aOrbiterK = (((aWandererI + RotL64(aIngress, 5U)) + RotL64(aCarry, 41U)) + 17322876217962143270U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = ((aWandererH + RotL64(aScatter, 47U)) + RotL64(aCarry, 11U)) + 9728299982740564979U;
            aOrbiterB = ((aWandererJ + RotL64(aCross, 39U)) + RotL64(aCarry, 57U)) + 301720335271716921U;
            aOrbiterG = (aWandererG + RotL64(aPrevious, 29U)) + 8069685428854814396U;
            aOrbiterD = ((aWandererA + RotL64(aScatter, 53U)) + 1973715500949100991U) + aPhaseEOrbiterAssignSaltF[((aIndex + 12U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 87666408799854155U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 12195436904339035245U;
            aOrbiterK = RotL64((aOrbiterK * 15427739165893738105U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 4578742069143400295U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 7828776048774876484U;
            aOrbiterB = RotL64((aOrbiterB * 4047964518501081039U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 17203146364542781833U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 16913369550858890466U;
            aOrbiterG = RotL64((aOrbiterG * 13534417587921978507U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 9632761514552265402U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 9106637671877341286U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9073709119482640391U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 15423680889126750876U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 6087310684583331882U;
            aOrbiterE = RotL64((aOrbiterE * 8964465129744898619U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 5420955876411796789U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 14166807419730848032U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 442659738632823751U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 8118312450347026824U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 4253043584558403086U;
            aOrbiterF = RotL64((aOrbiterF * 5651748455190536467U), 57U);
            //
            aIngress = RotL64(aOrbiterE, 11U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterG, 29U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterB, 53U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterK, 36U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterG, 51U)) + aOrbiterI);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 35U) + aOrbiterB) + RotL64(aOrbiterF, 21U)) + RotL64(aCarry, 3U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 53U) + aOrbiterE) + RotL64(aOrbiterB, 37U));
            aWandererA = aWandererA + (((RotL64(aCross, 28U) + aOrbiterB) + RotL64(aOrbiterI, 43U)) + RotL64(aCarry, 21U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterB, 13U)) + aOrbiterD);
            aWandererF = aWandererF + (((RotL64(aCross, 5U) + RotL64(aOrbiterI, 5U)) + aOrbiterK) + aPhaseEWandererUpdateSaltA[((aIndex + 10U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 47U) + aOrbiterD) + RotL64(aOrbiterF, 28U)) + aPhaseEWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + (RotL64(aWandererA, 10U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 37U));
            aCarry = aCarry + RotL64(aWandererH, 27U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 12326U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 14681U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 8888U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneB[((aIndex + 10010U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 11U) ^ RotL64(aCross, 38U)) ^ (RotL64(aIngress, 23U) + RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = ((aWandererC + RotL64(aScatter, 53U)) + RotL64(aCarry, 3U)) + 16016931609704150191U;
            aOrbiterH = (aWandererJ + RotL64(aCross, 29U)) + 14511433515861302636U;
            aOrbiterD = ((aWandererK + RotL64(aIngress, 3U)) + RotL64(aCarry, 43U)) + 11691237442613269593U;
            aOrbiterB = (((aWandererD + RotL64(aPrevious, 41U)) + RotL64(aCarry, 27U)) + 16383220587320484649U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = ((aWandererG + RotL64(aCross, 13U)) + 14293015313458219868U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = (aWandererA + RotL64(aIngress, 60U)) + 4407695248205526670U;
            aOrbiterC = (aWandererH + RotL64(aScatter, 35U)) + 1158323195324398372U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 6577683409653864555U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 171080079472863843U;
            aOrbiterD = RotL64((aOrbiterD * 3063978974927752653U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 5766333425872228205U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 16173508656917582960U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12187968015372936695U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 11781450063402219202U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 13033139686637576694U;
            aOrbiterB = RotL64((aOrbiterB * 4331137994135472025U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 4006310759400926020U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 13156817947481574467U;
            aOrbiterH = RotL64((aOrbiterH * 563189239835001483U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 12791290558893516411U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 989729955679243234U;
            aOrbiterK = RotL64((aOrbiterK * 8757228712495095017U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 838379839663022790U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 2830743864262313606U;
            aOrbiterJ = RotL64((aOrbiterJ * 10173947177104802797U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 2146646527331684652U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 4629168181742174906U;
            aOrbiterC = RotL64((aOrbiterC * 9046124907945045131U), 35U);
            //
            aIngress = RotL64(aOrbiterI, 3U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterK, 11U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterC, 28U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aIngress, 27U) + RotL64(aOrbiterC, 3U)) + aOrbiterJ);
            aWandererD = aWandererD ^ ((RotL64(aCross, 44U) + RotL64(aOrbiterK, 29U)) + aOrbiterB);
            aWandererG = aWandererG + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterB, 41U)) + aOrbiterH) + aPhaseEWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 53U) + aOrbiterD) + RotL64(aOrbiterB, 35U)) + aPhaseEWandererUpdateSaltB[((aIndex + 16U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 35U) + RotL64(aOrbiterJ, 21U)) + aOrbiterK) + RotL64(aCarry, 29U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 11U) + aOrbiterC) + RotL64(aOrbiterK, 57U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 19U) + RotL64(aOrbiterJ, 48U)) + aOrbiterI) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererK);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 4U));
            aCarry = aCarry + RotL64(aWandererA, 53U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 19959U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneA[((aIndex + 19749U)) & S_BLOCK1], 42U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 22539U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 23816U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 24U) + RotL64(aIngress, 39U)) + (RotL64(aCarry, 3U) ^ RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = ((aWandererA + RotL64(aIngress, 19U)) + RotL64(aCarry, 53U)) + 16462052553719977502U;
            aOrbiterA = (((aWandererB + RotL64(aCross, 57U)) + RotL64(aCarry, 13U)) + 12337064059566619581U) + aPhaseEOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = (aWandererD + RotL64(aScatter, 37U)) + 15801005007094515447U;
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 51U)) + 8228706742665081656U) + aPhaseEOrbiterAssignSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = (aWandererI + RotL64(aIngress, 13U)) + 11006723027845190869U;
            aOrbiterG = (aWandererF + RotL64(aPrevious, 43U)) + 18173765337829177450U;
            aOrbiterC = ((aWandererE + RotL64(aScatter, 6U)) + RotL64(aCarry, 39U)) + 530215083653542558U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 6608611827035564511U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 2246051826221626809U;
            aOrbiterD = RotL64((aOrbiterD * 6333352641495253539U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 5228575308895381421U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 10999213210689606857U;
            aOrbiterA = RotL64((aOrbiterA * 5467601259546342925U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 3773371037240485696U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 8887985779436152504U;
            aOrbiterK = RotL64((aOrbiterK * 698713082830739677U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 11150566414723818350U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 8336366151003049546U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9033771197242493699U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 13233968794237090787U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 8172558473508478819U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17837070423649268435U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 133564480283347997U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 15104810248883567064U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 706802420642303533U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 9138629520201127075U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 13993086066341664080U;
            aOrbiterC = RotL64((aOrbiterC * 4875046427147105077U), 57U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterI, 13U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 23U));
            aIngress = aIngress + (RotL64(aOrbiterK, 29U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterJ, 48U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 29U) + aOrbiterC) + RotL64(aOrbiterA, 29U));
            aWandererB = aWandererB + ((((RotL64(aScatter, 53U) + RotL64(aOrbiterI, 19U)) + aOrbiterG) + RotL64(aCarry, 51U)) + aPhaseEWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterD, 47U)) + aOrbiterI);
            aWandererI = aWandererI + (((RotL64(aCross, 21U) + RotL64(aOrbiterD, 12U)) + aOrbiterG) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterK, 5U)) + aOrbiterJ);
            aWandererF = aWandererF + (((RotL64(aPrevious, 60U) + RotL64(aOrbiterK, 39U)) + aOrbiterA) + aPhaseEWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterI, 57U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 48U));
            aCarry = aCarry + RotL64(aWandererI, 27U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 31639U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27051U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 32741U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneD[((aIndex + 32687U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 5U)) ^ (RotL64(aIngress, 37U) + RotL64(aCross, 50U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = (((aWandererK + RotL64(aScatter, 23U)) + RotL64(aCarry, 39U)) + 13924571355038625040U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = ((aWandererG + RotL64(aIngress, 41U)) + RotL64(aCarry, 53U)) + 16328300979357156658U;
            aOrbiterG = (aWandererE + RotL64(aCross, 35U)) + 3947771961206012461U;
            aOrbiterA = (aWandererH + RotL64(aPrevious, 56U)) + 15428284250569311285U;
            aOrbiterC = (aWandererC + RotL64(aIngress, 3U)) + 5777369485254032486U;
            aOrbiterE = (aWandererI + RotL64(aPrevious, 29U)) + 16813320300717644673U;
            aOrbiterJ = (((aWandererJ + RotL64(aCross, 11U)) + RotL64(aCarry, 13U)) + 16689933050200758251U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 1856422419049390708U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 18214498743831925517U;
            aOrbiterG = RotL64((aOrbiterG * 10744120577560529379U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 18278550878494094923U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 797712062039591797U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7212998747080137625U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 15854849439012341347U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 996882939768167773U;
            aOrbiterH = RotL64((aOrbiterH * 14936703950807908575U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 3005829974130671692U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 8793495343509953906U;
            aOrbiterC = RotL64((aOrbiterC * 14065479348374612031U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 7710453029930631112U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 9511995836117707047U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7250766204781428201U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 670902975693341744U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 9045820304668279777U;
            aOrbiterA = RotL64((aOrbiterA * 18373074917532639027U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 12417212387607119470U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 12816983560669985622U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8406003970221889847U), 27U);
            //
            aIngress = RotL64(aOrbiterH, 35U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterC, 27U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 53U));
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 53U) + aOrbiterD) + RotL64(aOrbiterG, 35U));
            aWandererG = aWandererG + ((RotL64(aIngress, 35U) + RotL64(aOrbiterG, 21U)) + aOrbiterH);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 29U) + aOrbiterC) + RotL64(aOrbiterJ, 44U)) + aPhaseEWandererUpdateSaltE[((aIndex + 24U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterC, 51U)) + aOrbiterH) + RotL64(aCarry, 23U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 42U) + RotL64(aOrbiterE, 3U)) + aOrbiterA);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 3U) + aOrbiterJ) + RotL64(aOrbiterD, 11U)) + RotL64(aCarry, 41U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterJ, 57U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 60U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 21U));
            aCarry = aCarry + RotL64(aWandererH, 47U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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

void TwistExpander_Golf_Arx::Twist_D(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 2944U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneC[((aIndex + 4546U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 5124U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((aIndex + 7080U)) & S_BLOCK1], 34U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 3U) + RotL64(aCross, 53U)) ^ (RotL64(aCarry, 28U) + RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = (((aWandererB + RotL64(aScatter, 50U)) + RotL64(aCarry, 19U)) + 77518479758428414U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = ((aWandererA + RotL64(aCross, 3U)) + 4832061802166300011U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = ((aWandererC + RotL64(aIngress, 19U)) + RotL64(aCarry, 47U)) + 11695291171006574112U;
            aOrbiterH = (aWandererK + RotL64(aPrevious, 27U)) + 7467412817843260094U;
            aOrbiterJ = ((aWandererD + RotL64(aCross, 39U)) + RotL64(aCarry, 3U)) + 17801484124471154757U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 5555455638503958639U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 5669470540733721606U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17219613748084498879U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 3042388456327784163U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 2236734925228156691U;
            aOrbiterG = RotL64((aOrbiterG * 10076582424701705531U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 14459720401528685450U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 4814967631216658856U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 18288097536171386643U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 16950679344449075945U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 6262238639302011050U;
            aOrbiterA = RotL64((aOrbiterA * 9942659897425088183U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 3522256359074996724U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 12524717897707074242U;
            aOrbiterJ = RotL64((aOrbiterJ * 6787771338063891989U), 47U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterA, 51U);
            aIngress = aIngress + (RotL64(aOrbiterF, 41U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 30U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterG, 57U)) + aOrbiterJ);
            aWandererB = aWandererB + (((RotL64(aPrevious, 11U) + aOrbiterJ) + RotL64(aOrbiterF, 40U)) + RotL64(aCarry, 57U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterH, 19U)) + aOrbiterA) + aPhaseFWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 40U) + aOrbiterA) + RotL64(aOrbiterJ, 29U)) + RotL64(aCarry, 23U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 57U) + aOrbiterF) + RotL64(aOrbiterG, 3U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 53U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + RotL64(aWandererK, 43U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9201U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 13704U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 12572U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 9320U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 44U) + RotL64(aPrevious, 57U)) ^ (RotL64(aCross, 11U) + RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = (aWandererK + RotL64(aIngress, 57U)) + 11998579547770778580U;
            aOrbiterG = (((aWandererJ + RotL64(aCross, 11U)) + RotL64(aCarry, 53U)) + 8409465187298704610U) + aPhaseFOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = (((aWandererD + RotL64(aScatter, 26U)) + RotL64(aCarry, 41U)) + 3470222286110333500U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 39U)) + RotL64(aCarry, 27U)) + 5704486785203069994U;
            aOrbiterJ = (aWandererF + RotL64(aIngress, 3U)) + 10334944660253279633U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 7626852700722567477U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 14631310754943209743U;
            aOrbiterH = RotL64((aOrbiterH * 1958866541508493967U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 807160297237854120U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 5624154783624196107U;
            aOrbiterJ = RotL64((aOrbiterJ * 2404066593958052159U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 4971444394698940423U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 6340057638461027062U;
            aOrbiterC = RotL64((aOrbiterC * 12027586111086798629U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 9003019862787819481U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 13632057463595873033U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12575202147280216765U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 12766104026871797746U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 4062118445824915939U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13130770039048080701U), 19U);
            //
            aIngress = RotL64(aOrbiterG, 37U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterJ, 47U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterH, 6U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aPrevious, 43U) + aOrbiterH) + RotL64(aOrbiterJ, 3U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 57U) + aOrbiterJ) + RotL64(aOrbiterC, 35U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 12U) + RotL64(aOrbiterH, 47U)) + aOrbiterB) + RotL64(aCarry, 23U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 21U) + aOrbiterG) + RotL64(aOrbiterB, 12U));
            aWandererD = aWandererD + (((RotL64(aScatter, 29U) + RotL64(aOrbiterG, 27U)) + aOrbiterC) + RotL64(aCarry, 41U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 13U));
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererK, 23U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 16736U)) & S_BLOCK1], 44U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22490U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16823U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 22129U)) & S_BLOCK1], 22U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 43U) + RotL64(aCarry, 24U)) ^ (RotL64(aCross, 11U) + RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = (((aWandererJ + RotL64(aScatter, 39U)) + RotL64(aCarry, 3U)) + 898812731947995389U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 21U)) + 8677347622525527167U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = (aWandererI + RotL64(aIngress, 57U)) + 770321564027567654U;
            aOrbiterJ = ((aWandererA + RotL64(aCross, 30U)) + RotL64(aCarry, 51U)) + 11020474858081526395U;
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 3U)) + RotL64(aCarry, 39U)) + 17289793580414993470U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 10111912559295118444U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 8083622125544542011U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3610772128071340341U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 7149858558922988240U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 5919683821379905699U;
            aOrbiterI = RotL64((aOrbiterI * 16705119888884231567U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 6860902846079238714U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 15083517836867542075U;
            aOrbiterD = RotL64((aOrbiterD * 4686657139237578325U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 14852868368708376381U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 9860233289028878323U;
            aOrbiterJ = RotL64((aOrbiterJ * 13418143547952204667U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 772406119079116272U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 7971141501337627589U;
            aOrbiterF = RotL64((aOrbiterF * 10168120622976358617U), 53U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterJ, 3U);
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterF, 28U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterD, 43U)) + aOrbiterJ) + RotL64(aCarry, 19U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 50U) + aOrbiterE) + RotL64(aOrbiterI, 51U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 41U) + aOrbiterF) + RotL64(aOrbiterJ, 13U)) + RotL64(aCarry, 5U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterD, 4U)) + aOrbiterI) + aPhaseFWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aCross, 5U) + RotL64(aOrbiterE, 23U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererA, 35U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 31231U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32482U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 31164U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneD[((aIndex + 27770U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 29U) + RotL64(aCarry, 57U)) ^ (RotL64(aPrevious, 11U) + RotL64(aCross, 42U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = (((aWandererE + RotL64(aCross, 27U)) + RotL64(aCarry, 35U)) + 14499676118633326000U) + aPhaseFOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = (((aWandererH + RotL64(aScatter, 36U)) + RotL64(aCarry, 51U)) + 17191273593018552288U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 5U)) + RotL64(aCarry, 5U)) + 4085176294948097737U;
            aOrbiterF = (aWandererK + RotL64(aIngress, 19U)) + 11112671474158908186U;
            aOrbiterA = (aWandererF + RotL64(aScatter, 57U)) + 8745787969012266485U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 18074049663777707948U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 2543758649719164688U;
            aOrbiterB = RotL64((aOrbiterB * 7153845562786344373U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 4659584749412700523U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 974639159259871273U;
            aOrbiterK = RotL64((aOrbiterK * 17918719351847605523U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 9211220687971081987U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 8567024626862182714U;
            aOrbiterF = RotL64((aOrbiterF * 7755874089832496393U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 5803002132294840900U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 11968489432878148467U;
            aOrbiterI = RotL64((aOrbiterI * 4501441062617123165U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 9470807228394903442U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 1692347973120388469U;
            aOrbiterA = RotL64((aOrbiterA * 17433393164156231575U), 23U);
            //
            aIngress = RotL64(aOrbiterA, 35U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aScatter, 11U) + aOrbiterI) + RotL64(aOrbiterK, 11U)) + aPhaseFWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterF, 27U)) + aOrbiterB);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 30U) + aOrbiterB) + RotL64(aOrbiterI, 50U)) + RotL64(aCarry, 51U)) + aPhaseFWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 3U) + aOrbiterA) + RotL64(aOrbiterF, 41U));
            aWandererF = aWandererF + (((RotL64(aScatter, 41U) + RotL64(aOrbiterK, 3U)) + aOrbiterF) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererF);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + RotL64(aWandererE, 27U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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

void TwistExpander_Golf_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterJ = 0;
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 7233U)) & S_BLOCK1], 26U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 897U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 7524U)) & S_BLOCK1], 18U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 2675U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aIngress, 21U)) + (RotL64(aPrevious, 6U) ^ RotL64(aCross, 43U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = (aWandererF + RotL64(aScatter, 41U)) + 7960325128608297381U;
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 53U)) + RotL64(aCarry, 19U)) + 12773836012104052042U;
            aOrbiterH = (((aWandererD + RotL64(aIngress, 27U)) + RotL64(aCarry, 47U)) + 3173972621347773016U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = ((aWandererI + RotL64(aCross, 3U)) + RotL64(aCarry, 35U)) + 3708401356314308171U;
            aOrbiterC = ((aWandererC + RotL64(aScatter, 18U)) + 950774285720019449U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 4170092315705438265U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 17000449130864980747U;
            aOrbiterH = RotL64((aOrbiterH * 7710635557693533263U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 8793910540062893860U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 520277969543516469U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4150613128885828229U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 12762214857389827271U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 2932451184340207695U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7513337346940091655U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 11062179998786293839U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 7919119215271524178U;
            aOrbiterJ = RotL64((aOrbiterJ * 9053677007180081359U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 1774988449597115155U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 3799792889466518953U;
            aOrbiterC = RotL64((aOrbiterC * 17512791286490623455U), 57U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterH, 53U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 13U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterF, 42U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aIngress, 13U) + aOrbiterB) + RotL64(aOrbiterF, 13U)) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 21U) + RotL64(aOrbiterB, 3U)) + aOrbiterJ) + RotL64(aCarry, 43U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 3U) + aOrbiterC) + RotL64(aOrbiterH, 53U)) + aPhaseGWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterC, 28U)) + aOrbiterF) + RotL64(aCarry, 19U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 52U) + aOrbiterB) + RotL64(aOrbiterC, 37U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 11U));
            aCarry = aCarry + RotL64(aWandererC, 3U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 12138U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 9959U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 15713U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 10477U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aPrevious, 23U)) + (RotL64(aIngress, 10U) ^ RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = (((aWandererJ + RotL64(aIngress, 13U)) + RotL64(aCarry, 57U)) + 10038936806177516123U) + aPhaseGOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = (aWandererB + RotL64(aCross, 29U)) + 1773168435195292638U;
            aOrbiterG = (((aWandererH + RotL64(aScatter, 57U)) + RotL64(aCarry, 35U)) + 10655711161526628072U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = (aWandererG + RotL64(aPrevious, 37U)) + 14422295664639740437U;
            aOrbiterD = ((aWandererA + RotL64(aCross, 4U)) + RotL64(aCarry, 21U)) + 4125228715513159576U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 3670449653158650845U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 17553727567180813057U;
            aOrbiterG = RotL64((aOrbiterG * 11814335762020146785U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 5111401772713882743U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 7688573124662314413U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10846442063022821393U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 9438375825507814395U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 14177477039902118886U;
            aOrbiterA = RotL64((aOrbiterA * 6467406626985022537U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 16329942595859623928U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 3990536794006836672U;
            aOrbiterH = RotL64((aOrbiterH * 579024714339065373U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 5072881436583180756U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 16789727877867289997U;
            aOrbiterJ = RotL64((aOrbiterJ * 8766246302636197905U), 39U);
            //
            aIngress = RotL64(aOrbiterA, 56U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterH, 5U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterD, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterA, 58U)) + aOrbiterH);
            aWandererA = aWandererA + ((((RotL64(aIngress, 3U) + aOrbiterG) + RotL64(aOrbiterD, 35U)) + RotL64(aCarry, 29U)) + aPhaseGWandererUpdateSaltC[((aIndex + 22U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 52U) + aOrbiterD) + RotL64(aOrbiterA, 19U)) + aPhaseGWandererUpdateSaltB[((aIndex + 10U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 11U) + aOrbiterJ) + RotL64(aOrbiterG, 47U)) + RotL64(aCarry, 41U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterJ, 3U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + RotL64(aWandererG, 19U);
            aCarry = aCarry + RotL64(aIngress, 28U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 22914U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 21648U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 20553U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 19050U)) & S_BLOCK1], 36U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 38U) + RotL64(aCross, 53U)) ^ (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = (aWandererD + RotL64(aIngress, 53U)) + 12849591986267890852U;
            aOrbiterC = ((aWandererJ + RotL64(aCross, 35U)) + RotL64(aCarry, 37U)) + 8232614804696815750U;
            aOrbiterB = (((aWandererH + RotL64(aPrevious, 6U)) + RotL64(aCarry, 3U)) + 12141567259210877281U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = (((aWandererE + RotL64(aScatter, 23U)) + RotL64(aCarry, 53U)) + 2928641981037885644U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = (aWandererA + RotL64(aCross, 43U)) + 980733350554783938U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 2683985177993350746U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 14532148403815527355U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15985362037094864225U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 7736296629433884203U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 10428437770166310549U;
            aOrbiterC = RotL64((aOrbiterC * 326634742742373401U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 18327174144859461029U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 6810436935194432002U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2715987179577753597U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 12606153309690753435U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 17123256945895150555U;
            aOrbiterH = RotL64((aOrbiterH * 13469111258504672565U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 9057777759026189541U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 16478485918911194442U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11054247078884894131U), 3U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterB, 27U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 3U));
            aIngress = aIngress + RotL64(aOrbiterG, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aIngress, 29U) + RotL64(aOrbiterB, 11U)) + aOrbiterC) + RotL64(aCarry, 43U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 18U) + RotL64(aOrbiterF, 19U)) + aOrbiterH) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 41U) + aOrbiterC) + RotL64(aOrbiterF, 35U)) + RotL64(aCarry, 27U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterB, 56U)) + aOrbiterG) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aIngress, 5U) + RotL64(aOrbiterG, 27U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererH, 19U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 29785U)) & S_BLOCK1], 40U) ^ RotL64(aExpandLaneA[((aIndex + 25854U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28696U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 31283U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 41U) ^ RotL64(aPrevious, 28U)) + (RotL64(aCross, 11U) ^ RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = ((aWandererG + RotL64(aCross, 5U)) + RotL64(aCarry, 41U)) + 2168513956284366370U;
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 19U)) + 10290361969974613111U) + aPhaseGOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 27U)) + RotL64(aCarry, 13U)) + 15673836275828498050U;
            aOrbiterH = (((aWandererI + RotL64(aScatter, 48U)) + RotL64(aCarry, 29U)) + 16600540024145812236U) + aPhaseGOrbiterAssignSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterB = (aWandererH + RotL64(aIngress, 39U)) + 9428052101528111892U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 12763657928312763377U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 10751286982008662485U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6169084301655877217U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 1708230173038057979U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 4011389705422783816U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11692237130784795961U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 11704428328093077714U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 2055336619674699284U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6374289210096410907U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 1870865272102705804U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 3574214263751923179U;
            aOrbiterK = RotL64((aOrbiterK * 13132083406834413563U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 984611970726966186U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 15207945449947643672U;
            aOrbiterB = RotL64((aOrbiterB * 9539470161576639981U), 39U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterD, 23U);
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterB, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aCross, 60U) + aOrbiterH) + RotL64(aOrbiterJ, 11U)) + RotL64(aCarry, 27U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 43U) + aOrbiterB) + RotL64(aOrbiterD, 30U)) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterD, 3U)) + aOrbiterK) + aPhaseGWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 21U) + aOrbiterJ) + RotL64(aOrbiterK, 41U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 13U) + aOrbiterH) + RotL64(aOrbiterD, 53U)) + RotL64(aCarry, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererG);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + RotL64(aWandererJ, 19U);
            aCarry = aCarry + RotL64(aIngress, 6U);
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

void TwistExpander_Golf_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 7460U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4232U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 341U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 5763U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aIngress, 40U)) + (RotL64(aPrevious, 3U) ^ RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = ((aWandererC + RotL64(aScatter, 60U)) + RotL64(aCarry, 57U)) + 16016931609704150191U;
            aOrbiterB = (((aWandererH + RotL64(aPrevious, 39U)) + RotL64(aCarry, 39U)) + 14511433515861302636U) + aPhaseHOrbiterAssignSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = (((aWandererG + RotL64(aIngress, 13U)) + RotL64(aCarry, 19U)) + 11691237442613269593U) + aPhaseHOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = (aWandererJ + RotL64(aCross, 21U)) + 16383220587320484649U;
            aOrbiterC = (aWandererE + RotL64(aIngress, 47U)) + 14293015313458219868U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 4407695248205526670U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 1158323195324398372U;
            aOrbiterK = RotL64((aOrbiterK * 7489061637031434357U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 6577683409653864555U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 171080079472863843U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3063978974927752653U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 5766333425872228205U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 16173508656917582960U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12187968015372936695U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 11781450063402219202U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 13033139686637576694U;
            aOrbiterB = RotL64((aOrbiterB * 4331137994135472025U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 4006310759400926020U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 13156817947481574467U;
            aOrbiterC = RotL64((aOrbiterC * 563189239835001483U), 19U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterB, 41U);
            aIngress = aIngress + (RotL64(aOrbiterC, 19U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterG, 54U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterG, 13U)) + aOrbiterA);
            aWandererC = aWandererC + ((((RotL64(aIngress, 14U) + RotL64(aOrbiterK, 3U)) + aOrbiterC) + RotL64(aCarry, 43U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterK, 21U)) + aOrbiterA) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 39U) + RotL64(aOrbiterB, 43U)) + aOrbiterG) + RotL64(aCarry, 19U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterA, 30U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererG, 39U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererJ, 3U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 15154U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((aIndex + 12942U)) & S_BLOCK1], 50U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 13057U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneA[((aIndex + 13972U)) & S_BLOCK1], 50U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 34U) ^ RotL64(aCross, 47U)) ^ (RotL64(aPrevious, 21U) + RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = ((aWandererD + RotL64(aIngress, 47U)) + RotL64(aCarry, 27U)) + 3621877681473089725U;
            aOrbiterK = (((aWandererG + RotL64(aPrevious, 27U)) + RotL64(aCarry, 47U)) + 4451752751536414717U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = (aWandererE + RotL64(aScatter, 57U)) + 11371625415377772117U;
            aOrbiterH = ((aWandererA + RotL64(aCross, 12U)) + RotL64(aCarry, 13U)) + 6046792758881150619U;
            aOrbiterE = ((aWandererK + RotL64(aIngress, 37U)) + 8213166120394461682U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 4343156661140422645U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 11105271483234947905U;
            aOrbiterG = RotL64((aOrbiterG * 853531080115819287U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 348904609985341372U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 12924652822526858767U;
            aOrbiterE = RotL64((aOrbiterE * 2801892489296408735U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 7461211697358520287U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 16551553555297890558U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16432952324635746293U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 11908056404140782995U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 9147367258259948715U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10777628928376261667U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 8876461054692728610U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 10546855952702525404U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10071104785895309677U), 37U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterH, 23U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 38U));
            aIngress = aIngress + RotL64(aOrbiterK, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aCross, 14U) + RotL64(aOrbiterE, 13U)) + aOrbiterG) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 3U) + aOrbiterF) + RotL64(aOrbiterK, 5U)) + RotL64(aCarry, 41U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 43U) + aOrbiterH) + RotL64(aOrbiterG, 53U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 29U) + RotL64(aOrbiterH, 40U)) + aOrbiterK) + RotL64(aCarry, 13U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 53U) + aOrbiterG) + RotL64(aOrbiterK, 21U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererA, 30U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 17433U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneD[((aIndex + 21329U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17932U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 16951U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 19U) + RotL64(aIngress, 54U)) ^ (RotL64(aCross, 3U) ^ RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = (((aWandererJ + RotL64(aCross, 19U)) + RotL64(aCarry, 53U)) + 13278949403988203974U) + aPhaseHOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = (aWandererI + RotL64(aIngress, 29U)) + 9213599924054673756U;
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 46U)) + 1255746482932381798U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 57U)) + RotL64(aCarry, 41U)) + 11575321997144516122U;
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 5U)) + RotL64(aCarry, 5U)) + 15881587525529432437U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 9846195809864862707U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 12319815691858217670U;
            aOrbiterK = RotL64((aOrbiterK * 14271546305640811091U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 16322617427294439587U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 16332130810525887437U;
            aOrbiterE = RotL64((aOrbiterE * 7588076439690559343U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 4920951156015336794U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 16767126455124552329U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4440352337076842603U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 12553595911087945223U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 1437522202135436142U;
            aOrbiterJ = RotL64((aOrbiterJ * 2001992794165550905U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 12313100454852227143U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 2761983020631055729U;
            aOrbiterD = RotL64((aOrbiterD * 3874839760378039509U), 51U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterJ, 6U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + RotL64(aOrbiterD, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 26U) + RotL64(aOrbiterA, 30U)) + aOrbiterJ) + RotL64(aCarry, 27U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterJ, 11U)) + aOrbiterK);
            aWandererG = aWandererG + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterD, 39U)) + aOrbiterK) + RotL64(aCarry, 53U)) + aPhaseHWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 41U) + aOrbiterA) + RotL64(aOrbiterE, 19U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 11U) + aOrbiterJ) + RotL64(aOrbiterD, 53U)) + aPhaseHWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 5U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + RotL64(aWandererJ, 58U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 30094U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((aIndex + 32586U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28143U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneC[((aIndex + 31355U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aPrevious, 29U)) ^ (RotL64(aIngress, 10U) + RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = ((aWandererK + RotL64(aScatter, 29U)) + RotL64(aCarry, 3U)) + 15045917390223766480U;
            aOrbiterH = (aWandererE + RotL64(aPrevious, 13U)) + 10763054007033668758U;
            aOrbiterE = (((aWandererH + RotL64(aCross, 39U)) + RotL64(aCarry, 23U)) + 13190170142593666607U) + aPhaseHOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = (((aWandererJ + RotL64(aIngress, 21U)) + RotL64(aCarry, 35U)) + 9657025731441167065U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = (aWandererF + RotL64(aPrevious, 52U)) + 11433367178975954211U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 17904920143996810366U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 3244383020512113283U;
            aOrbiterE = RotL64((aOrbiterE * 552521443123433353U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 6538815775171139091U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 7195368312757976343U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10515679176134176565U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 18134430713910279374U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 6571776588427107976U;
            aOrbiterD = RotL64((aOrbiterD * 11916502085252589161U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 11830778129647517758U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 9793702760907767365U;
            aOrbiterH = RotL64((aOrbiterH * 4096246227968677179U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 2287235876793192036U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 8951959188326141794U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9968356718110753845U), 37U);
            //
            aIngress = RotL64(aOrbiterD, 29U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 56U));
            aIngress = aIngress + RotL64(aOrbiterI, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aScatter, 38U) + aOrbiterD) + RotL64(aOrbiterF, 23U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 11U) + aOrbiterE) + RotL64(aOrbiterH, 3U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 29U) + aOrbiterD) + RotL64(aOrbiterE, 39U)) + RotL64(aCarry, 53U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 53U) + aOrbiterI) + RotL64(aOrbiterD, 47U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 3U) + RotL64(aOrbiterH, 14U)) + aOrbiterD) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererH, 56U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
