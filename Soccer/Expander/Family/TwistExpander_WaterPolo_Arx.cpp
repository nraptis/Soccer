#include "TwistExpander_WaterPolo_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_WaterPolo_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xDEACC6289012C917ULL + 0xC42625A1C3BD38C4ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xA533D9116E8F03DBULL + 0xECC3B67663178954ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xC087B73983102C9BULL + 0x9D5D88FD4DB8D4F0ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xA5B91700B10D2F01ULL + 0xE48A49415C96318AULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xFE3D860E0CA5CDC5ULL + 0xC29BB47B45A804FCULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xAABBA6553D07DABBULL + 0xC374269B00328C4EULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xBC887ABE20B5C9DDULL + 0x8EBA94B54466248CULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x8EE962EFB95EB755ULL + 0xE60CF88B0577BFC0ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xFD328037F283A0EBULL + 0xF99B009FD789E707ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xF95637C9A6DF4A23ULL + 0xEA46D242F5308711ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xE225CE8B429C1563ULL + 0xB9D562CA3FADFAF6ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x9048FFFC071BCB15ULL + 0xFC3A2FDC56390666ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xF65097D309C85173ULL + 0xBD6204F061931A6BULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x9BE6C73B2E9DCF7DULL + 0x82D8BC52C1E6D766ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xB7D4198915156047ULL + 0xB8914F800E902BC1ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xA72AAE584AD33291ULL + 0x9607B6C1A0A9D14BULL);
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
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 1256U)) & S_BLOCK1], 51U) ^ RotL64(pSnow[((aIndex + 3046U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 284U)) & S_BLOCK1], 44U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 996U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aPrevious, 51U)) ^ (RotL64(aIngress, 18U) + RotL64(aCross, 39U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererD + RotL64(aIngress, 51U)) + 77518479758428414U;
            aOrbiterE = ((((aWandererK + RotL64(aCross, 5U)) + RotL64(aCarry, 43U)) + 4832061802166300011U) + aOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1]) + aNonceWordB;
            aOrbiterD = (aWandererG + RotL64(aScatter, 41U)) + 11695291171006574112U;
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 27U)) + 7467412817843260094U) + aOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = ((aWandererH + RotL64(aScatter, 54U)) + 17801484124471154757U) + aNonceWordL;
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 3U)) + 5555455638503958639U) + aNonceWordO;
            aOrbiterA = (aWandererE + RotL64(aIngress, 47U)) + 5669470540733721606U;
            aOrbiterI = (aWandererA + RotL64(aCross, 19U)) + 3042388456327784163U;
            aOrbiterF = (aWandererI + RotL64(aIngress, 11U)) + 2236734925228156691U;
            aOrbiterG = ((aWandererF + RotL64(aScatter, 36U)) + RotL64(aCarry, 11U)) + 14459720401528685450U;
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 13U)) + RotL64(aCarry, 27U)) + 4814967631216658856U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 16950679344449075945U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 6262238639302011050U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9942659897425088183U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 3522256359074996724U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 12524717897707074242U;
            aOrbiterH = RotL64((aOrbiterH * 6787771338063891989U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 13891759914865623828U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 11910250571469028666U;
            aOrbiterJ = RotL64((aOrbiterJ * 12311343917878428995U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 2240189915640314069U) + aNonceWordF;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 5365912986308810837U;
            aOrbiterC = RotL64((aOrbiterC * 15133972552032469957U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 9323732721344489753U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 13087326560957916553U;
            aOrbiterA = RotL64((aOrbiterA * 14659491687401151733U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 16398238057564892809U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 11517870519285159224U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1501848878469712681U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 7758285512254776734U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 17475149091906684720U) ^ aNonceWordP;
            aOrbiterK = RotL64((aOrbiterK * 6015816725428299273U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 2051631493975035243U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 11684740065349595315U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10918975496337269197U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 10575473798991451167U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 8267005776169272822U;
            aOrbiterB = RotL64((aOrbiterB * 13166868678285963961U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 6249698995716039231U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 13808085811784323978U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3897731011582061983U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 2739364646624876985U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 77518479758428414U;
            aOrbiterG = RotL64((aOrbiterG * 6977724811175035551U), 11U);
            //
            aIngress = RotL64(aOrbiterK, 19U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterE, 26U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterJ, 53U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 51U));
            aIngress = aIngress + (RotL64(aOrbiterC, 43U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterA, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aCross, 29U) + RotL64(aOrbiterD, 3U)) + aOrbiterG) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterD, 11U)) + aOrbiterK) + aWandererUpdateSaltD[((aIndex + 15U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 56U) + RotL64(aOrbiterE, 39U)) + aOrbiterB);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 23U) + aOrbiterA) + RotL64(aOrbiterC, 5U));
            aWandererB = aWandererB + (((RotL64(aIngress, 19U) + aOrbiterB) + RotL64(aOrbiterH, 14U)) + aNonceWordK);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterH, 41U)) + aOrbiterE);
            aWandererH = aWandererH + ((RotL64(aCross, 26U) + RotL64(aOrbiterJ, 21U)) + aOrbiterH);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterF, 53U)) + aOrbiterG);
            aWandererK = aWandererK + (((RotL64(aScatter, 41U) + aOrbiterC) + RotL64(aOrbiterI, 29U)) + RotL64(aCarry, 11U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterE, 51U)) + aOrbiterG) + aNonceWordM);
            aWandererI = aWandererI + (((RotL64(aPrevious, 5U) + aOrbiterH) + RotL64(aOrbiterC, 60U)) + aWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererG);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + (RotL64(aWandererE, 46U) ^ aWandererK);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + RotL64(aWandererC, 5U);
            aCarry = aCarry + RotL64(aIngress, 24U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordB);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 6056U)) & S_BLOCK1], 27U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 9730U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(pSnow[((S_BLOCK1 - aIndex + 7355U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 5776U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 21U) + RotL64(aPrevious, 4U)) ^ (RotL64(aIngress, 47U) ^ RotL64(aCarry, 35U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (((aWandererB + RotL64(aPrevious, 23U)) + RotL64(aCarry, 41U)) + 13960289014350612206U) + aOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = ((aWandererD + RotL64(aIngress, 27U)) + 3483331015269589730U) + aNonceWordN;
            aOrbiterK = (aWandererC + RotL64(aScatter, 53U)) + 6873299241002444518U;
            aOrbiterC = (aWandererJ + RotL64(aCross, 5U)) + 3562094007125534229U;
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 60U)) + 11422367439932782705U) + aOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = (aWandererH + RotL64(aIngress, 41U)) + 532453428514259816U;
            aOrbiterJ = (aWandererI + RotL64(aScatter, 43U)) + 17810941465810193088U;
            aOrbiterA = (((aWandererE + RotL64(aCross, 51U)) + RotL64(aCarry, 29U)) + 11869759058631106331U) + aNonceWordM;
            aOrbiterH = ((aWandererA + RotL64(aIngress, 19U)) + RotL64(aCarry, 53U)) + 8837581071876177566U;
            aOrbiterI = (aWandererG + RotL64(aCross, 37U)) + 17185378327053837778U;
            aOrbiterF = (aWandererK + RotL64(aPrevious, 30U)) + 7578253375676981500U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 17112646434432814442U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 14949096407295697881U;
            aOrbiterK = RotL64((aOrbiterK * 14770977858283051753U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 4259590620758467836U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 6534899413644542303U;
            aOrbiterG = RotL64((aOrbiterG * 7987609419215568661U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 2637407498893694243U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 15819295597921425711U;
            aOrbiterD = RotL64((aOrbiterD * 5202015597375051399U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 6373559542002699718U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 11694562937392022505U) ^ aNonceWordP;
            aOrbiterJ = RotL64((aOrbiterJ * 9311557972331218597U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 3308736483775453062U) + aNonceWordE;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 12749929710650475901U;
            aOrbiterH = RotL64((aOrbiterH * 248428400724560945U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 1569528215675579656U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 1044077933631689572U;
            aOrbiterE = RotL64((aOrbiterE * 6443796233912755143U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 8393422728124537471U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 2002732612516530754U;
            aOrbiterC = RotL64((aOrbiterC * 13702146823622364279U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 13469191942843147943U) + aNonceWordH;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 7633171368709520560U;
            aOrbiterB = RotL64((aOrbiterB * 9713514012478203047U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 4023206337737491091U) + aOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 15990323932023596968U;
            aOrbiterA = RotL64((aOrbiterA * 4816480271959713463U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 837005729394899591U) + aOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 9692088757104339973U) ^ aOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17971548293495807419U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 18039464962413134616U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 13960289014350612206U;
            aOrbiterF = RotL64((aOrbiterF * 931609478642506411U), 53U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterE, 51U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 10U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 13U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 37U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + RotL64(aOrbiterI, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterJ, 27U)) + aOrbiterB) + aNonceWordJ);
            aWandererC = aWandererC ^ (((RotL64(aCross, 23U) + aOrbiterD) + RotL64(aOrbiterA, 51U)) + aNonceWordC);
            aWandererI = aWandererI + (((RotL64(aScatter, 5U) + RotL64(aOrbiterG, 41U)) + aOrbiterK) + aWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 52U) + RotL64(aOrbiterA, 13U)) + aOrbiterH);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 19U) + aOrbiterB) + RotL64(aOrbiterD, 44U)) + RotL64(aCarry, 27U)) + aWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 57U) + aOrbiterF) + RotL64(aOrbiterD, 37U));
            aWandererG = aWandererG + (((RotL64(aCross, 47U) + aOrbiterF) + RotL64(aOrbiterC, 21U)) + RotL64(aCarry, 43U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterD, 19U)) + aOrbiterG);
            aWandererB = aWandererB + ((RotL64(aScatter, 43U) + aOrbiterI) + RotL64(aOrbiterE, 60U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 21U) + aOrbiterE) + RotL64(aOrbiterG, 23U));
            aWandererK = aWandererK + ((RotL64(aCross, 54U) + RotL64(aOrbiterB, 35U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 48U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + (RotL64(aWandererH, 53U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererE, 5U) ^ aWandererA);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 58U));
            aCarry = aCarry + RotL64(aWandererK, 23U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordD);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 14708U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12493U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 16327U)) & S_BLOCK1], 46U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 12457U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 60U) + RotL64(aCarry, 11U)) ^ (RotL64(aCross, 27U) + RotL64(aPrevious, 39U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererK + RotL64(aScatter, 29U)) + 7825479804710770560U;
            aOrbiterJ = (((aWandererI + RotL64(aIngress, 46U)) + RotL64(aCarry, 3U)) + 5298124167101358123U) + aOrbiterAssignSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = ((aWandererF + RotL64(aCross, 51U)) + 17774541024369233726U) + aNonceWordH;
            aOrbiterK = (aWandererA + RotL64(aPrevious, 35U)) + 7679371833537454082U;
            aOrbiterE = (aWandererB + RotL64(aCross, 11U)) + 5385914900748772224U;
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 48U)) + 3879781930908486531U) + aOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = (aWandererJ + RotL64(aIngress, 13U)) + 659110346638873236U;
            aOrbiterB = ((aWandererC + RotL64(aScatter, 27U)) + 10749021728538539749U) + aNonceWordD;
            aOrbiterF = ((aWandererD + RotL64(aCross, 57U)) + RotL64(aCarry, 19U)) + 3631252455767429457U;
            aOrbiterH = ((aWandererH + RotL64(aPrevious, 39U)) + RotL64(aCarry, 57U)) + 2271978810960685021U;
            aOrbiterC = ((aWandererG + RotL64(aIngress, 53U)) + 5963558780692551176U) + aNonceWordE;
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 974909966119198104U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 9296998242911152296U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2613629915877957661U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 2245318466901521959U) + aOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 13391076374843288568U;
            aOrbiterG = RotL64((aOrbiterG * 18094558036982107419U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 6184487746594236737U) + aNonceWordO;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 1563385912137291418U;
            aOrbiterJ = RotL64((aOrbiterJ * 4805455299959232321U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 1744840092006498629U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 2100927276837188416U;
            aOrbiterE = RotL64((aOrbiterE * 3541788262067077997U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 9998911862807246338U) + aNonceWordK;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 12239948725635220096U;
            aOrbiterB = RotL64((aOrbiterB * 7098620484129489129U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 3307447094994950246U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 12746613971448298932U;
            aOrbiterH = RotL64((aOrbiterH * 9463975886346934681U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 11577488293733790649U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 191108997585598809U;
            aOrbiterI = RotL64((aOrbiterI * 9574978681405356871U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 18096145693841273722U) + aNonceWordJ;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 10026281133603934071U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17261343107314203471U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 2346682418062064668U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 2996178204018644206U;
            aOrbiterD = RotL64((aOrbiterD * 2552965800703390909U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 15085425896818988223U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 1589593231782852588U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1535556765195388675U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 17170695588248383518U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 7825479804710770560U;
            aOrbiterC = RotL64((aOrbiterC * 7434218282170150533U), 43U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterK, 18U);
            aIngress = aIngress + (RotL64(aOrbiterC, 3U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterE, 21U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 11U));
            aIngress = aIngress + (RotL64(aOrbiterA, 37U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterG, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aCross, 3U) + aOrbiterF) + RotL64(aOrbiterB, 44U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterK, 11U)) + aOrbiterD);
            aWandererK = aWandererK + (((RotL64(aScatter, 27U) + aOrbiterJ) + RotL64(aOrbiterI, 41U)) + RotL64(aCarry, 27U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterB, 5U)) + aOrbiterA) + aWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererC = aWandererC + (((((RotL64(aPrevious, 47U) + aOrbiterA) + RotL64(aOrbiterE, 37U)) + RotL64(aCarry, 13U)) + aNonceWordF) + aWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 6U) + RotL64(aOrbiterA, 34U)) + aOrbiterD);
            aWandererF = aWandererF + ((RotL64(aCross, 29U) + aOrbiterJ) + RotL64(aOrbiterH, 19U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 35U) + aOrbiterB) + RotL64(aOrbiterD, 27U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterF, 53U)) + aNonceWordI);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 14U) + aOrbiterI) + RotL64(aOrbiterH, 29U)) + aNonceWordM);
            aWandererB = aWandererB + ((RotL64(aCross, 53U) + aOrbiterG) + RotL64(aOrbiterD, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 43U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererJ, 18U) ^ aWandererK);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 5U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + RotL64(aWandererF, 34U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordL);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 18006U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((aIndex + 21238U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19670U)) & S_BLOCK1], 12U) ^ RotL64(mSource[((aIndex + 18994U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aIngress, 23U)) + (RotL64(aCarry, 4U) ^ RotL64(aPrevious, 39U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererD + RotL64(aPrevious, 57U)) + 4751694786009671052U;
            aOrbiterA = ((aWandererA + RotL64(aScatter, 5U)) + RotL64(aCarry, 51U)) + 16362725160370844224U;
            aOrbiterC = (aWandererG + RotL64(aIngress, 26U)) + 6360885380915941057U;
            aOrbiterB = (aWandererC + RotL64(aCross, 37U)) + 5154536007972297036U;
            aOrbiterJ = (aWandererB + RotL64(aScatter, 21U)) + 9362540581874808253U;
            aOrbiterH = (aWandererI + RotL64(aIngress, 3U)) + 13902493871525612934U;
            aOrbiterE = (((aWandererE + RotL64(aCross, 19U)) + 10208452885367546542U) + aOrbiterAssignSaltF[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordH;
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 23U)) + 3117030377279160998U) + aOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = (aWandererJ + RotL64(aScatter, 11U)) + 17286247690414027870U;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 42U)) + RotL64(aCarry, 37U)) + 3930314320040949141U;
            aOrbiterF = ((aWandererH + RotL64(aCross, 51U)) + RotL64(aCarry, 11U)) + 7289525252391668404U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 3434167955466809185U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 17852573095128575663U;
            aOrbiterC = RotL64((aOrbiterC * 1485660158767033425U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 6137259687928853253U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 13992510605237574698U;
            aOrbiterJ = RotL64((aOrbiterJ * 15346263295995333395U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 6470556523400123474U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 4333255670390099293U;
            aOrbiterH = RotL64((aOrbiterH * 11089933812030082647U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 7700424876430257995U) + aOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 16920736951239453071U;
            aOrbiterE = RotL64((aOrbiterE * 8920407493132380497U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 1635071690430295730U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 9966700845966398620U;
            aOrbiterD = RotL64((aOrbiterD * 17210048121896546867U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 9833458070123027075U) + aOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 1990346556486746432U;
            aOrbiterG = RotL64((aOrbiterG * 8704943923474148699U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 13339523466436517327U) + aNonceWordK;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 5018264760406215603U;
            aOrbiterK = RotL64((aOrbiterK * 2769197961801783627U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 123427497520755346U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 4535841104215792886U;
            aOrbiterF = RotL64((aOrbiterF * 1417676310539177131U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 3525925567359163763U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 3273741481392187986U;
            aOrbiterI = RotL64((aOrbiterI * 16116160744647235811U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 6230742908784102407U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 7578784912496239362U;
            aOrbiterA = RotL64((aOrbiterA * 2614448818452560369U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 14669810330213234082U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 4751694786009671052U) ^ aNonceWordG;
            aOrbiterB = RotL64((aOrbiterB * 9583151676882991817U), 5U);
            //
            aIngress = RotL64(aOrbiterC, 41U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterA, 29U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterB, 38U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 35U));
            aIngress = aIngress + RotL64(aOrbiterK, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 57U) + aOrbiterE) + RotL64(aOrbiterA, 21U));
            aWandererB = aWandererB + (((RotL64(aCross, 37U) + RotL64(aOrbiterI, 23U)) + aOrbiterF) + RotL64(aCarry, 29U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 21U) + aOrbiterH) + RotL64(aOrbiterF, 18U)) + aWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aIngress, 19U) + RotL64(aOrbiterD, 47U)) + aOrbiterB);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 47U) + aOrbiterA) + RotL64(aOrbiterB, 41U)) + aNonceWordE);
            aWandererH = aWandererH + ((RotL64(aIngress, 28U) + RotL64(aOrbiterD, 57U)) + aOrbiterA);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 39U) + aOrbiterB) + RotL64(aOrbiterK, 43U));
            aWandererA = aWandererA + ((RotL64(aCross, 53U) + RotL64(aOrbiterH, 53U)) + aOrbiterG);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterG, 39U)) + aOrbiterC);
            aWandererF = aWandererF + (((RotL64(aIngress, 43U) + aOrbiterF) + RotL64(aOrbiterC, 3U)) + RotL64(aCarry, 13U));
            aWandererC = aWandererC ^ ((((RotL64(aCross, 6U) + RotL64(aOrbiterJ, 36U)) + aOrbiterA) + aNonceWordA) + aWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 20U) ^ aWandererE);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 37U));
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererF);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + RotL64(aWandererJ, 52U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordF);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 27112U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22063U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 23086U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((aIndex + 24708U)) & S_BLOCK1], 22U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 44U) ^ RotL64(aPrevious, 21U)) + (RotL64(aIngress, 5U) ^ RotL64(aCross, 57U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (aWandererE + RotL64(aPrevious, 35U)) + 3248574644570178787U;
            aOrbiterA = ((aWandererC + RotL64(aIngress, 41U)) + 4506961512959200024U) + aOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = ((aWandererD + RotL64(aScatter, 43U)) + RotL64(aCarry, 39U)) + 8423739774540738590U;
            aOrbiterG = (aWandererA + RotL64(aCross, 53U)) + 6593975869641735337U;
            aOrbiterK = (aWandererH + RotL64(aIngress, 5U)) + 16441716090557369103U;
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 12U)) + 7936601450453207914U) + aNonceWordE;
            aOrbiterI = (aWandererI + RotL64(aScatter, 23U)) + 13333752583560167065U;
            aOrbiterE = (((aWandererF + RotL64(aCross, 57U)) + RotL64(aCarry, 11U)) + 8013703284795432973U) + aNonceWordF;
            aOrbiterH = ((aWandererK + RotL64(aIngress, 37U)) + 2349852779887439236U) + aNonceWordM;
            aOrbiterJ = (((aWandererG + RotL64(aPrevious, 60U)) + RotL64(aCarry, 3U)) + 5318539364763284138U) + aOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = (aWandererJ + RotL64(aScatter, 27U)) + 11450957608502944376U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 9058992558327552687U) + aOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 632095686920230926U;
            aOrbiterB = RotL64((aOrbiterB * 12460364388358520799U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 14734218428913777098U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 16344357661370784442U;
            aOrbiterD = RotL64((aOrbiterD * 15049472842002138369U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 2981145363531184308U) + aNonceWordB;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 14176472085175714494U;
            aOrbiterE = RotL64((aOrbiterE * 2584623327412130939U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 11198457590069700889U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 952584436750426828U) ^ aOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1165713888651280355U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 4311591763498985972U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 16194341833989936369U) ^ aOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9997934560195932575U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 7560794022401107431U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 10683789740265711603U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15637823045351977883U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 11614366395125937178U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 10750771385100564416U;
            aOrbiterI = RotL64((aOrbiterI * 4987921274272444283U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 2934697034132204529U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 4646873794658020363U;
            aOrbiterH = RotL64((aOrbiterH * 10555456865641580175U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 7913681837683568905U) + aNonceWordC;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 17603563535330106340U;
            aOrbiterC = RotL64((aOrbiterC * 17882943067522319671U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 15375641415139193079U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 17059712718085411887U;
            aOrbiterA = RotL64((aOrbiterA * 13722089235751208215U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 14022558453716067200U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 3248574644570178787U;
            aOrbiterK = RotL64((aOrbiterK * 15249135451439374621U), 5U);
            //
            aIngress = RotL64(aOrbiterK, 47U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 34U));
            aIngress = aIngress + (RotL64(aOrbiterI, 41U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 29U));
            aIngress = aIngress + RotL64(aOrbiterF, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aIngress, 10U) + RotL64(aOrbiterG, 41U)) + aOrbiterF);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterC, 53U)) + aOrbiterJ);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 57U) + aOrbiterF) + RotL64(aOrbiterC, 39U)) + RotL64(aCarry, 47U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 43U) + aOrbiterA) + RotL64(aOrbiterH, 46U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterE, 21U)) + aOrbiterI);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 51U) + aOrbiterF) + RotL64(aOrbiterA, 27U));
            aWandererK = aWandererK + (((RotL64(aScatter, 19U) + RotL64(aOrbiterA, 43U)) + aOrbiterI) + aWandererUpdateSaltB[((aIndex + 10U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 38U) + RotL64(aOrbiterB, 29U)) + aOrbiterF) + aNonceWordP);
            aWandererF = aWandererF + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterA, 5U)) + aOrbiterD);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 21U) + aOrbiterE) + RotL64(aOrbiterH, 11U)) + aWandererUpdateSaltA[((aIndex + 22U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 13U) + aOrbiterI) + RotL64(aOrbiterK, 36U)) + RotL64(aCarry, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererI);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 37U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 50U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 41U));
            aCarry = aCarry + RotL64(aWandererD, 3U);
            aCarry = aCarry + RotL64(aIngress, 30U);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 32556U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28753U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31249U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28396U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 28U) ^ RotL64(aCarry, 53U)) + (RotL64(aIngress, 13U) ^ RotL64(aCross, 41U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (aWandererB + RotL64(aPrevious, 58U)) + 5510690816044082200U;
            aOrbiterK = ((aWandererA + RotL64(aIngress, 11U)) + RotL64(aCarry, 27U)) + 15967820875033940530U;
            aOrbiterI = (aWandererF + RotL64(aCross, 41U)) + 539348720848176221U;
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 5U)) + 15779318183635560817U) + aOrbiterAssignSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = (aWandererK + RotL64(aIngress, 47U)) + 14511058534424187469U;
            aOrbiterA = (aWandererC + RotL64(aPrevious, 53U)) + 5811130556873428391U;
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 21U)) + 1085928476499444025U) + aNonceWordC;
            aOrbiterC = ((aWandererH + RotL64(aCross, 23U)) + RotL64(aCarry, 21U)) + 6973335316600768130U;
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 39U)) + RotL64(aCarry, 41U)) + 10747243745475009744U;
            aOrbiterB = (aWandererD + RotL64(aCross, 51U)) + 1072260008981349754U;
            aOrbiterH = ((aWandererE + RotL64(aScatter, 18U)) + 2018772405352495753U) + aOrbiterAssignSaltA[((aIndex + 26U)) & S_SALT1];
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 1092091597048996547U) + aNonceWordP;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 15103140149542167197U;
            aOrbiterI = RotL64((aOrbiterI * 621856991658027989U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 13194619321108681542U) + aNonceWordI;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 16749188603268621850U;
            aOrbiterG = RotL64((aOrbiterG * 9575408950550922039U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 7427959503086895166U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 9895804051379551393U;
            aOrbiterA = RotL64((aOrbiterA * 2701997336201570715U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 4526020800679774259U) + aNonceWordD;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 4484850928870048176U;
            aOrbiterE = RotL64((aOrbiterE * 17556987520625677313U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 1837404844299040155U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 15213208978489570694U;
            aOrbiterC = RotL64((aOrbiterC * 7062740584650274133U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 9615231781751396800U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 15872192167825648096U) ^ aOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2900526493682580729U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 12530672039655918903U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 10617836782870315804U;
            aOrbiterB = RotL64((aOrbiterB * 9716778004909794973U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 550750725406860977U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 3498554352021622907U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9846933294851238495U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 4059346317776216057U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 14161853870874499023U;
            aOrbiterF = RotL64((aOrbiterF * 8601560894939097781U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 4088411647683253905U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 9321241420172776158U) ^ aOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4167888281125330225U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 8527337525861632945U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 5510690816044082200U;
            aOrbiterJ = RotL64((aOrbiterJ * 12464836001483233379U), 3U);
            //
            aIngress = RotL64(aOrbiterD, 57U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 37U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 23U));
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterH, 51U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterJ, 12U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 5U) + aOrbiterK) + RotL64(aOrbiterF, 57U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterC, 19U)) + aOrbiterJ);
            aWandererI = aWandererI ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterF, 21U)) + aOrbiterI) + aNonceWordG);
            aWandererC = aWandererC + (((RotL64(aIngress, 13U) + aOrbiterJ) + RotL64(aOrbiterI, 52U)) + aWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 42U) + aOrbiterA) + RotL64(aOrbiterK, 39U)) + aNonceWordH);
            aWandererH = aWandererH + (((RotL64(aScatter, 39U) + RotL64(aOrbiterA, 35U)) + aOrbiterH) + RotL64(aCarry, 41U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 37U) + aOrbiterH) + RotL64(aOrbiterC, 11U)) + aWandererUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 57U) + RotL64(aOrbiterD, 13U)) + aOrbiterK) + RotL64(aCarry, 51U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 19U) + aOrbiterD) + RotL64(aOrbiterE, 23U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 34U) + RotL64(aOrbiterB, 5U)) + aOrbiterG);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterH, 46U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 34U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 37U));
            aCarry = aCarry + (RotL64(aWandererG, 53U) ^ aWandererE);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + (RotL64(aWandererF, 46U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererD, 19U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ aNonceWordC;
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

void TwistExpander_WaterPolo_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xBE32DB07708B23A3ULL + 0x94607EE0A88A308AULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xA2CA7751968E05A3ULL + 0xFCB06352A79202B1ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x8BC27C69FE59CEEDULL + 0xD6D3ACFCF273FFF5ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xB7F6DD4829FA1E4BULL + 0xA89CEE32C55D4974ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xC18C517DE6C4475DULL + 0xF8B6A221D8E4EA65ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xC78429904C94897BULL + 0x9E3BCB28C8FA6863ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x9CC7A9DF683EED07ULL + 0x81D05F72B4B77FB1ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xDA31CC108889CDE1ULL + 0x87B7139D93ACAFF2ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xB6F1DEC0B0B1B47FULL + 0x87A9456508E0E97AULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xD87BBBA85F554C73ULL + 0xA800717889BE2AA5ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xB9AEADB06F37AB8DULL + 0x9355D980924EE24AULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x9BB5C5153BA5EEA5ULL + 0xBB574ADBA4EB8EA4ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x816577A6590F29FFULL + 0xE9E4F2BA47B7355AULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xF802C61C95D3814BULL + 0x81C6AB03F2C98088ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xF62A3D3AE50FB499ULL + 0x897374A3C590A690ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xEDC417CC779F2505ULL + 0xC3F48FF5E0F97CA5ULL);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 5864U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4043U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 3008U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 4992U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCross, 4U)) + (RotL64(aIngress, 37U) + RotL64(aCarry, 19U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = ((((aWandererE + RotL64(aPrevious, 6U)) + RotL64(aCarry, 29U)) + 4634399531433127141U) + aOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1]) + aNonceWordO;
            aOrbiterA = (aWandererC + RotL64(aScatter, 39U)) + 16961792729406903200U;
            aOrbiterI = (aWandererF + RotL64(aIngress, 53U)) + 4105280732301137738U;
            aOrbiterB = (aWandererA + RotL64(aCross, 35U)) + 15692013501147331191U;
            aOrbiterH = (((aWandererK + RotL64(aScatter, 10U)) + RotL64(aCarry, 41U)) + 1252216715968780587U) + aNonceWordJ;
            aOrbiterG = (aWandererG + RotL64(aPrevious, 23U)) + 7958289043012473752U;
            aOrbiterF = ((aWandererD + RotL64(aIngress, 27U)) + RotL64(aCarry, 19U)) + 6611577301818896615U;
            aOrbiterE = (((aWandererH + RotL64(aCross, 19U)) + 8506226754305949140U) + aOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1]) + aNonceWordI;
            aOrbiterC = (aWandererJ + RotL64(aScatter, 57U)) + 3648813120449403353U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 5195245426245535735U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 542948051600803051U;
            aOrbiterI = RotL64((aOrbiterI * 4631106308856448475U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 11974253551208964789U) + aOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 10596463592332655367U) ^ aNonceWordH;
            aOrbiterG = RotL64((aOrbiterG * 10941161258815714641U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 12015129484061440159U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 8254944355710109060U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3233697992479357615U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 2754858806943915419U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 5007802002906662779U;
            aOrbiterC = RotL64((aOrbiterC * 15613733948331639723U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 6262190752136523216U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 10528977986487821428U;
            aOrbiterJ = RotL64((aOrbiterJ * 1184258264034585525U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 8511097226098211854U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 12091864735686692582U;
            aOrbiterB = RotL64((aOrbiterB * 6128140528141411237U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 4970966265236842566U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 10728884018459718341U;
            aOrbiterF = RotL64((aOrbiterF * 18205183219769602827U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 13760057185629905360U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 6590269178744829056U;
            aOrbiterA = RotL64((aOrbiterA * 14482684769712170123U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 765826377665103262U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 9364759196106579706U;
            aOrbiterH = RotL64((aOrbiterH * 10315111163659289329U), 53U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterF, 27U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 36U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 19U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 39U));
            aIngress = aIngress + RotL64(aOrbiterB, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterG, 60U)) + aOrbiterF);
            aWandererG = aWandererG + (((RotL64(aIngress, 35U) + RotL64(aOrbiterB, 13U)) + aOrbiterH) + RotL64(aCarry, 27U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 39U) + RotL64(aOrbiterA, 23U)) + aOrbiterH) + aWandererUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 14U) + aOrbiterJ) + RotL64(aOrbiterF, 47U)) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 29U) + aOrbiterA) + RotL64(aOrbiterC, 56U)) + aWandererUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aScatter, 19U) + RotL64(aOrbiterI, 5U)) + aOrbiterH);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterC, 51U)) + aOrbiterH);
            aWandererK = aWandererK + (((RotL64(aCross, 57U) + aOrbiterJ) + RotL64(aOrbiterG, 43U)) + aNonceWordE);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 48U) + RotL64(aOrbiterH, 39U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + (RotL64(aWandererK, 41U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererJ, 30U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 53U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererA, 35U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ aNonceWordI;
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 10805U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 12215U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9789U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneB[((aIndex + 8670U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCross, 5U)) ^ (RotL64(aIngress, 37U) + RotL64(aCarry, 22U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (((aWandererD + RotL64(aPrevious, 12U)) + RotL64(aCarry, 27U)) + 8866844335448071821U) + aNonceWordC;
            aOrbiterH = ((aWandererF + RotL64(aCross, 19U)) + 15159698739856430085U) + aNonceWordN;
            aOrbiterI = (aWandererG + RotL64(aIngress, 5U)) + 9582805772989594633U;
            aOrbiterD = ((aWandererI + RotL64(aScatter, 53U)) + RotL64(aCarry, 3U)) + 1438538239931588373U;
            aOrbiterB = ((aWandererB + RotL64(aIngress, 39U)) + 10862044156620436139U) + aOrbiterAssignSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = (aWandererA + RotL64(aScatter, 57U)) + 13682173320058164615U;
            aOrbiterG = (aWandererH + RotL64(aCross, 29U)) + 8351013291045977592U;
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 24U)) + 15777857431516633916U;
            aOrbiterK = (((aWandererC + RotL64(aIngress, 47U)) + RotL64(aCarry, 19U)) + 16178966745333885377U) + aOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 9031889187993001617U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 6308472367425865347U;
            aOrbiterI = RotL64((aOrbiterI * 17118710301967158153U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 642109145903321046U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 9186268569255318035U;
            aOrbiterB = RotL64((aOrbiterB * 10714674348507516749U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 6091345356803675860U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 13218507921880873749U;
            aOrbiterG = RotL64((aOrbiterG * 15415157927185637717U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 4266652275234474616U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 4391422098164506195U) ^ aOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17634679403195085867U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 5160682323243635577U) + aNonceWordL;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 10351728852161347404U) ^ aNonceWordJ;
            aOrbiterK = RotL64((aOrbiterK * 11105410036471745951U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 3950932176454814023U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 9536466386833427441U;
            aOrbiterC = RotL64((aOrbiterC * 18064984243491293435U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 9927425919978776529U) + aOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 6819384090527481081U;
            aOrbiterD = RotL64((aOrbiterD * 18032965969184368561U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 1646274931424218507U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 16166524473976135097U) ^ aOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11672192658072663849U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 11252501968059485262U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 16847854447987609067U;
            aOrbiterH = RotL64((aOrbiterH * 6326299154627028295U), 13U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterF, 5U);
            aIngress = aIngress + (RotL64(aOrbiterK, 19U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterH, 53U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 26U));
            aIngress = aIngress + RotL64(aOrbiterC, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aCross, 5U) + aOrbiterG) + RotL64(aOrbiterI, 57U)) + RotL64(aCarry, 13U)) + aWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 44U) + RotL64(aOrbiterB, 43U)) + aOrbiterH) + aNonceWordP);
            aWandererB = aWandererB + (((RotL64(aScatter, 51U) + aOrbiterG) + RotL64(aOrbiterD, 23U)) + aNonceWordE);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterB, 38U)) + aOrbiterF);
            aWandererI = aWandererI + (((RotL64(aScatter, 11U) + aOrbiterK) + RotL64(aOrbiterG, 5U)) + RotL64(aCarry, 51U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 34U) + RotL64(aOrbiterG, 19U)) + aOrbiterJ);
            aWandererD = aWandererD + ((RotL64(aCross, 29U) + aOrbiterB) + RotL64(aOrbiterK, 29U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterD, 12U)) + aOrbiterH);
            aWandererG = aWandererG + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterG, 51U)) + aOrbiterC) + aNonceWordO) + aWandererUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 48U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 23U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + RotL64(aWandererB, 51U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordI);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 20138U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneA[((aIndex + 17255U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16931U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((aIndex + 22806U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 37U) + RotL64(aIngress, 19U)) ^ (RotL64(aPrevious, 52U) ^ RotL64(aCross, 5U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererF + RotL64(aPrevious, 23U)) + 3917730204724097072U;
            aOrbiterD = (((aWandererD + RotL64(aScatter, 3U)) + RotL64(aCarry, 51U)) + 1874642340716212824U) + aOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = (aWandererA + RotL64(aCross, 34U)) + 6900165757434854160U;
            aOrbiterK = (aWandererJ + RotL64(aIngress, 57U)) + 12750946097023807161U;
            aOrbiterG = (aWandererC + RotL64(aCross, 13U)) + 6563216048479513594U;
            aOrbiterJ = (aWandererH + RotL64(aScatter, 41U)) + 14960240191349450795U;
            aOrbiterC = ((aWandererI + RotL64(aIngress, 19U)) + RotL64(aCarry, 11U)) + 16306180275951788289U;
            aOrbiterF = (((aWandererB + RotL64(aPrevious, 47U)) + RotL64(aCarry, 43U)) + 6502066618271045547U) + aNonceWordP;
            aOrbiterB = ((aWandererE + RotL64(aIngress, 30U)) + 6219852857850888738U) + aOrbiterAssignSaltB[((aIndex + 16U)) & S_SALT1];
            //
            aOrbiterE = (((aOrbiterE + aOrbiterD) + 2272931312452845850U) + aOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1]) + aNonceWordG;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 3028929882263199463U;
            aOrbiterA = RotL64((aOrbiterA * 11005324285856805069U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 6067393030073568112U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 10094809900437037258U;
            aOrbiterE = RotL64((aOrbiterE * 18095564940730322769U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 5962414178157074575U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 15755563045799129417U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3692603590609922031U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 6321455513889880590U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 1197435601998121700U) ^ aNonceWordA;
            aOrbiterD = RotL64((aOrbiterD * 17693996266260557625U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 12496949381666299968U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 6357070235648527030U;
            aOrbiterG = RotL64((aOrbiterG * 2931486644220862433U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 8423760160877540210U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 8090246492554850768U;
            aOrbiterJ = RotL64((aOrbiterJ * 2949407491181921633U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 11436635942985063755U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 17086363141014359856U;
            aOrbiterC = RotL64((aOrbiterC * 10504127577318206801U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 10734017887545474935U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 375515325165740779U;
            aOrbiterF = RotL64((aOrbiterF * 9980486695448151709U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 5217148491945389821U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 14696058217023530058U;
            aOrbiterB = RotL64((aOrbiterB * 11026674782236654799U), 5U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterF, 29U);
            aIngress = aIngress + (RotL64(aOrbiterG, 58U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterK, 51U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterD, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterA, 30U)) + aOrbiterD) + aNonceWordD);
            aWandererB = aWandererB + ((RotL64(aPrevious, 5U) + aOrbiterF) + RotL64(aOrbiterJ, 13U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 35U) + aOrbiterD) + RotL64(aOrbiterE, 21U));
            aWandererA = aWandererA + ((((RotL64(aIngress, 54U) + aOrbiterK) + RotL64(aOrbiterD, 47U)) + RotL64(aCarry, 13U)) + aWandererUpdateSaltE[((aIndex + 14U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterC, 51U)) + aOrbiterJ);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 19U) + RotL64(aOrbiterJ, 60U)) + aOrbiterG) + aNonceWordN);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 27U) + aOrbiterK) + RotL64(aOrbiterF, 37U)) + aNonceWordM);
            aWandererD = aWandererD + (((RotL64(aCross, 39U) + RotL64(aOrbiterA, 41U)) + aOrbiterB) + RotL64(aCarry, 41U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 60U) + aOrbiterG) + RotL64(aOrbiterK, 3U)) + aWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + (RotL64(aWandererF, 60U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + (RotL64(aWandererI, 39U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererJ, 13U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ aNonceWordE;
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 25948U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29671U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 29635U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneD[((aIndex + 29866U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCross, 35U)) + (RotL64(aPrevious, 51U) + RotL64(aCarry, 4U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (aWandererI + RotL64(aPrevious, 5U)) + 12849591986267890852U;
            aOrbiterE = ((aWandererA + RotL64(aIngress, 34U)) + RotL64(aCarry, 39U)) + 8232614804696815750U;
            aOrbiterG = ((aWandererG + RotL64(aCross, 43U)) + RotL64(aCarry, 5U)) + 12141567259210877281U;
            aOrbiterH = ((aWandererC + RotL64(aScatter, 47U)) + RotL64(aCarry, 13U)) + 2928641981037885644U;
            aOrbiterK = (aWandererB + RotL64(aCross, 39U)) + 980733350554783938U;
            aOrbiterD = (((aWandererE + RotL64(aIngress, 19U)) + 2683985177993350746U) + aOrbiterAssignSaltD[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordI;
            aOrbiterB = (aWandererF + RotL64(aPrevious, 13U)) + 14532148403815527355U;
            aOrbiterI = (aWandererH + RotL64(aScatter, 51U)) + 7736296629433884203U;
            aOrbiterJ = (((aWandererK + RotL64(aIngress, 60U)) + 10428437770166310549U) + aOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1]) + aNonceWordH;
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 18327174144859461029U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 6810436935194432002U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2715987179577753597U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 12606153309690753435U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 17123256945895150555U;
            aOrbiterK = RotL64((aOrbiterK * 13469111258504672565U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 9057777759026189541U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 16478485918911194442U;
            aOrbiterB = RotL64((aOrbiterB * 11054247078884894131U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 18064460487552100483U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 11477276762421684083U;
            aOrbiterA = RotL64((aOrbiterA * 3886501230380184395U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 18318375441973295081U) + aOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 13849305985380030986U;
            aOrbiterH = RotL64((aOrbiterH * 12962140243967824959U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 10240409420338313641U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 18360586077779529086U;
            aOrbiterD = RotL64((aOrbiterD * 18196875422391501927U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 16801797158622424257U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 4950305991208513887U;
            aOrbiterI = RotL64((aOrbiterI * 4437082499761416951U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 15790878572843321918U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 9808781805065559728U;
            aOrbiterJ = RotL64((aOrbiterJ * 9394280083159162953U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 11974996650410830731U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 4955004489435232515U) ^ aNonceWordL;
            aOrbiterE = RotL64((aOrbiterE * 13301966529515483085U), 27U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterE, 5U);
            aIngress = aIngress + (RotL64(aOrbiterG, 54U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterK, 47U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 44U) + aOrbiterJ) + RotL64(aOrbiterE, 39U));
            aWandererK = aWandererK + (((RotL64(aIngress, 51U) + RotL64(aOrbiterG, 47U)) + aOrbiterI) + RotL64(aCarry, 51U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterE, 35U)) + aOrbiterD) + aNonceWordM);
            aWandererB = aWandererB + (((RotL64(aPrevious, 23U) + aOrbiterD) + RotL64(aOrbiterG, 43U)) + aWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 29U) + aOrbiterB) + RotL64(aOrbiterA, 12U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterI, 29U)) + aOrbiterK);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 5U) + aOrbiterJ) + RotL64(aOrbiterA, 53U)) + aWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 14U) + RotL64(aOrbiterD, 57U)) + aOrbiterB) + RotL64(aCarry, 43U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterA, 22U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererH, 6U) ^ aWandererA);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + RotL64(aWandererC, 57U);
            aCarry = aCarry + RotL64(aIngress, 30U);
            aCarry = aCarry ^ aNonceWordA;
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

void TwistExpander_WaterPolo_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x861491959339D8D9ULL + 0xFAD9D86D9791F7CCULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xA2115F5B79E17EABULL + 0xDF1E6012AB3F98F3ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xF679396DE1421819ULL + 0x8E6C0A39762656D3ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xDE341A704C0A8001ULL + 0xA6EF38C0D04C8B90ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xAD5A4186127611A7ULL + 0xF8061DA72274EA13ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xA3F8B892FC2803FDULL + 0xAF10F98599DD79C1ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xF267DF966AE06B39ULL + 0xC4404CEF76ABEF29ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xAD57E77222E0857FULL + 0xC187B5EAC9BC5E70ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xB1E0A431630D6E23ULL + 0xA7DED6A0329B89F5ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xFA49B1D38BF02BEFULL + 0xF3493EF427EB8D1FULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xFB2E3BC2138B61D5ULL + 0xE3E278F5F89206BEULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xE9F7174BFE481BD5ULL + 0x882B198519B15DCFULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xC909CBF8F59C0ADBULL + 0x87BF3A7D3A2A759FULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xC92C2B675DD7B6EBULL + 0x936605D4CFFE180CULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xABB90A7C7D291045ULL + 0xAF528FBE2B203720ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xCD20659178963059ULL + 0xD42342C2343AFF58ULL);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 4232U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneC[((aIndex + 497U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 3761U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 5399U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aIngress, 23U)) + (RotL64(aCarry, 57U) + RotL64(aPrevious, 40U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 26U)) + 4751694786009671052U) + aNonceWordG;
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 3U)) + RotL64(aCarry, 21U)) + 16362725160370844224U;
            aOrbiterF = ((((aWandererE + RotL64(aCross, 53U)) + RotL64(aCarry, 3U)) + 6360885380915941057U) + aOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1]) + aNonceWordN;
            aOrbiterD = (((aWandererD + RotL64(aScatter, 43U)) + RotL64(aCarry, 39U)) + 5154536007972297036U) + aOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = (aWandererF + RotL64(aPrevious, 13U)) + 9362540581874808253U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 13902493871525612934U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 10208452885367546542U) ^ aOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12067703239567933105U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 3117030377279160998U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 17286247690414027870U) ^ aNonceWordP;
            aOrbiterK = RotL64((aOrbiterK * 4896931759653832095U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 3930314320040949141U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 7289525252391668404U;
            aOrbiterD = RotL64((aOrbiterD * 15452162299105112187U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 3434167955466809185U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterE) ^ 17852573095128575663U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterJ = RotL64((aOrbiterJ * 1485660158767033425U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 6137259687928853253U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 13992510605237574698U;
            aOrbiterE = RotL64((aOrbiterE * 15346263295995333395U), 13U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterJ, 57U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + RotL64(aOrbiterD, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aCross, 11U) + aOrbiterK) + RotL64(aOrbiterF, 13U)) + RotL64(aCarry, 41U));
            aWandererB = aWandererB ^ ((((RotL64(aPrevious, 44U) + RotL64(aOrbiterE, 39U)) + aOrbiterJ) + aNonceWordF) + aWandererUpdateSaltC[((aIndex + 24U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 27U) + aOrbiterE) + RotL64(aOrbiterF, 60U)) + RotL64(aCarry, 13U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterJ, 51U)) + aOrbiterD) + aWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aIngress, 57U) + RotL64(aOrbiterK, 27U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + RotL64(aWandererD, 47U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ aNonceWordE;
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 15310U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 9017U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 10283U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 14803U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 24U) ^ RotL64(aCross, 43U)) + (RotL64(aCarry, 57U) ^ RotL64(aIngress, 5U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererE + RotL64(aCross, 19U)) + RotL64(aCarry, 5U)) + 1142447269198373880U;
            aOrbiterD = (((aWandererG + RotL64(aIngress, 27U)) + 10581460640040336191U) + aOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordC;
            aOrbiterC = (((aWandererH + RotL64(aPrevious, 10U)) + RotL64(aCarry, 57U)) + 14703062773878202900U) + aOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = ((aWandererD + RotL64(aScatter, 51U)) + RotL64(aCarry, 41U)) + 15737525756286914746U;
            aOrbiterF = (aWandererA + RotL64(aCross, 35U)) + 16178774478273186999U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 2514897053906809160U) + aNonceWordA;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 13702496607592508464U;
            aOrbiterC = RotL64((aOrbiterC * 16540143680974064057U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 18030885275418337965U) + aOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 5241783876161655984U;
            aOrbiterF = RotL64((aOrbiterF * 10970981186787227937U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 2807052676283587925U) + aOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 8022804576763271327U) ^ aNonceWordJ;
            aOrbiterB = RotL64((aOrbiterB * 11727096043219370577U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 15597099852232205860U) + aOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 1538435607932096400U;
            aOrbiterD = RotL64((aOrbiterD * 7900752511710516981U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 11147868774413615365U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterF) ^ 9325213746830411568U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterA = RotL64((aOrbiterA * 561819005818948769U), 27U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterD, 35U);
            aIngress = aIngress + (RotL64(aOrbiterB, 5U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterA, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aIngress, 19U) + RotL64(aOrbiterA, 29U)) + aOrbiterC) + aNonceWordE) + aWandererUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((((RotL64(aCross, 29U) + aOrbiterB) + RotL64(aOrbiterA, 3U)) + aNonceWordD) + aWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 53U) + RotL64(aOrbiterB, 57U)) + aOrbiterD) + RotL64(aCarry, 3U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterF, 47U)) + aOrbiterC) + aNonceWordI);
            aWandererD = aWandererD + (((RotL64(aIngress, 44U) + aOrbiterF) + RotL64(aOrbiterB, 38U)) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 40U));
            aCarry = aCarry + RotL64(aWandererD, 21U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ aNonceWordA;
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 19150U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22782U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 22749U)) & S_BLOCK1], 30U) ^ RotL64(aOperationLaneC[((aIndex + 17602U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 11U) + RotL64(aCarry, 60U)) ^ (RotL64(aIngress, 47U) + RotL64(aCross, 35U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererK + RotL64(aIngress, 27U)) + RotL64(aCarry, 21U)) + 10881271196314989997U;
            aOrbiterG = ((aWandererE + RotL64(aScatter, 3U)) + 6406461249988567558U) + aOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = (((aWandererJ + RotL64(aCross, 35U)) + RotL64(aCarry, 37U)) + 17255067918280095959U) + aOrbiterAssignSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = ((aWandererH + RotL64(aPrevious, 57U)) + RotL64(aCarry, 53U)) + 16690850682497718411U;
            aOrbiterD = ((aWandererA + RotL64(aScatter, 18U)) + 5576201059361086866U) + aNonceWordO;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 11991259685693687554U) + aNonceWordB;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 14652535244217836909U) ^ aOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 18283959577075524171U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 1701789037170782122U) + aNonceWordA;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 953429054903473833U;
            aOrbiterG = RotL64((aOrbiterG * 13482379459700651427U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 12064513610469714211U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 7993881398822002424U;
            aOrbiterI = RotL64((aOrbiterI * 11572884842788918377U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 14421313768013320050U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 11112386845630998889U;
            aOrbiterH = RotL64((aOrbiterH * 11771526352030371669U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 17069630896535699015U) + aOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 3308240081138623373U) ^ aOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10449509484417835159U), 37U);
            //
            aIngress = RotL64(aOrbiterI, 56U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterB, 41U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterH, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((((RotL64(aIngress, 41U) + aOrbiterG) + RotL64(aOrbiterI, 43U)) + aNonceWordC) + aWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aCross, 19U) + aOrbiterD) + RotL64(aOrbiterH, 51U)) + RotL64(aCarry, 43U)) + aNonceWordL);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterD, 60U)) + aOrbiterB) + aWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aScatter, 30U) + aOrbiterB) + RotL64(aOrbiterH, 11U)) + RotL64(aCarry, 3U)) + aNonceWordH);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterH, 21U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererJ, 35U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ aNonceWordC;
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 26469U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneB[((aIndex + 28210U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27090U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 27877U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 27U) + RotL64(aCarry, 57U)) ^ (RotL64(aIngress, 41U) ^ RotL64(aCross, 12U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((aWandererF + RotL64(aScatter, 14U)) + 5697928251815176134U) + aNonceWordO;
            aOrbiterK = ((((aWandererH + RotL64(aPrevious, 43U)) + RotL64(aCarry, 57U)) + 337587740689259575U) + aOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1]) + aNonceWordP;
            aOrbiterG = ((aWandererG + RotL64(aIngress, 3U)) + RotL64(aCarry, 23U)) + 4927686903263973950U;
            aOrbiterJ = ((aWandererA + RotL64(aCross, 57U)) + RotL64(aCarry, 37U)) + 3742409032569801033U;
            aOrbiterI = (((aWandererI + RotL64(aScatter, 29U)) + 1608092659172197650U) + aOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1]) + aNonceWordB;
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 15848744267145717509U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 15300174177963339253U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5771922862677667319U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 14162868453323648628U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 12020167069983729869U;
            aOrbiterD = RotL64((aOrbiterD * 2071080217680099017U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 16259538291658723956U) + aOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 8516686212464112245U) ^ aNonceWordH;
            aOrbiterJ = RotL64((aOrbiterJ * 4731296903548893627U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 3722184575520553132U) + aNonceWordE;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 5663609293306386784U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14364218128780764749U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 15265344442454471986U) + aNonceWordF;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 3050323350098829515U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5890624677162388135U), 3U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterI, 26U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 13U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterD, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 27U) + aOrbiterJ) + RotL64(aOrbiterG, 3U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterK, 57U)) + aOrbiterD) + RotL64(aCarry, 29U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 47U) + aOrbiterG) + RotL64(aOrbiterK, 13U)) + aWandererUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aIngress, 5U) + aOrbiterD) + RotL64(aOrbiterI, 21U)) + RotL64(aCarry, 41U)) + aNonceWordC);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 56U) + RotL64(aOrbiterG, 38U)) + aOrbiterD) + aWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 13U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 21U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererF, 58U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordD);
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

void TwistExpander_WaterPolo_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xFF69B26570657773ULL + 0xFE3C17E95F363456ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xABA74C864FA691DDULL + 0x81A5FC9B2A2176CFULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xB5F3FC8429043B2DULL + 0x875CE3C1994595FDULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xF6EACC2DEE649FF7ULL + 0xD9DBCEF66A6C9C80ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x990B2DAF6947A215ULL + 0xFCBF6D2A3E60FFFAULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xF307534E28B579BDULL + 0xE0CBDBE0EB693244ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xF21FA6EEEEDEF3B7ULL + 0xE33BB87150A2DEF6ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xD3C5414512CE5045ULL + 0xE3A07B0F82F052A6ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xA72A01D57F10AF29ULL + 0xA90AA7C127107D81ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x9130FDD07F8387BDULL + 0x8959140D137F5342ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x83DD2CA44ABAE86BULL + 0x912ADA61E7B7670EULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xB96C701117AAE12DULL + 0x8F15905E5F4B2A16ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xECF4533254B62213ULL + 0xD2C36B499157A766ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xA40A23835CE66FA5ULL + 0xBD09E06BA502BEB3ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x815DDE4CA9F3AD45ULL + 0xC9329B24A199B438ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x96D9E8D1E873C9C9ULL + 0xB9D5CE8D1C90B369ULL);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 733U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((aIndex + 5297U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 5137U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 3450U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 27U) ^ RotL64(aIngress, 14U)) ^ (RotL64(aCross, 57U) + RotL64(aPrevious, 39U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((((aWandererI + RotL64(aPrevious, 35U)) + RotL64(aCarry, 53U)) + 4622023259121087483U) + aOrbiterAssignSaltA[((aIndex + 15U)) & S_SALT1]) + aNonceWordM;
            aOrbiterF = (((aWandererK + RotL64(aIngress, 5U)) + RotL64(aCarry, 39U)) + 10253505250223501352U) + aNonceWordH;
            aOrbiterK = (aWandererG + RotL64(aScatter, 13U)) + 17133877904420462669U;
            aOrbiterD = (aWandererD + RotL64(aCross, 41U)) + 6162827793741796700U;
            aOrbiterC = ((aWandererF + RotL64(aScatter, 19U)) + 9610986424765907615U) + aOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = (aWandererE + RotL64(aIngress, 26U)) + 11210747154264753754U;
            aOrbiterH = ((aWandererJ + RotL64(aCross, 53U)) + RotL64(aCarry, 11U)) + 16554205219580654546U;
            //
            aOrbiterA = (((aOrbiterA + aOrbiterF) + 10352576357413766388U) + aOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1]) + aNonceWordP;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 3651845783283479752U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1011289824180799641U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 18145542190463500476U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 5415609566767162857U;
            aOrbiterC = RotL64((aOrbiterC * 6474184559323816389U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 2033734872464201570U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterF) ^ 3507213117125813345U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterB = RotL64((aOrbiterB * 5453058336688881113U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 8716253393049851856U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 695984869565941856U;
            aOrbiterH = RotL64((aOrbiterH * 8377921610764044735U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 7661578828878284931U) + aNonceWordO;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 906654265099155956U;
            aOrbiterA = RotL64((aOrbiterA * 8117625377607536949U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 6050049984731254612U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 17882717590338190821U;
            aOrbiterD = RotL64((aOrbiterD * 10807367411402733215U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 4996521991532815957U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 4246460672800604436U;
            aOrbiterF = RotL64((aOrbiterF * 12047466401960824903U), 3U);
            //
            aIngress = RotL64(aOrbiterD, 30U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 53U));
            aIngress = aIngress + (RotL64(aOrbiterC, 41U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterF, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aIngress, 5U) + RotL64(aOrbiterC, 41U)) + aOrbiterF) + aWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterB, 47U)) + aOrbiterD);
            aWandererF = aWandererF + ((RotL64(aCross, 19U) + aOrbiterK) + RotL64(aOrbiterH, 29U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 12U) + aOrbiterF) + RotL64(aOrbiterB, 19U)) + aNonceWordL);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 43U) + aOrbiterC) + RotL64(aOrbiterH, 58U)) + RotL64(aCarry, 13U)) + aNonceWordE);
            aWandererK = aWandererK ^ ((RotL64(aCross, 57U) + aOrbiterH) + RotL64(aOrbiterF, 35U));
            aWandererD = aWandererD + (((((RotL64(aScatter, 29U) + aOrbiterA) + RotL64(aOrbiterH, 5U)) + RotL64(aCarry, 43U)) + aNonceWordF) + aWandererUpdateSaltD[((aIndex + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererK);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 48U));
            aCarry = aCarry + RotL64(aWandererG, 53U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordC);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 13784U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 15903U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 10338U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneB[((aIndex + 9947U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 3U) + RotL64(aIngress, 23U)) ^ (RotL64(aPrevious, 53U) + RotL64(aCross, 38U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((aWandererC + RotL64(aIngress, 21U)) + 17912271996338180948U) + aOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = (aWandererK + RotL64(aCross, 27U)) + 13259276608841847058U;
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 10U)) + RotL64(aCarry, 13U)) + 16225936008657276089U;
            aOrbiterB = (((aWandererH + RotL64(aScatter, 57U)) + 2243058962151834071U) + aOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordK;
            aOrbiterA = ((aWandererB + RotL64(aIngress, 51U)) + RotL64(aCarry, 43U)) + 10637439274127347861U;
            aOrbiterK = (aWandererD + RotL64(aCross, 3U)) + 15312219216405992627U;
            aOrbiterG = ((aWandererG + RotL64(aScatter, 37U)) + RotL64(aCarry, 29U)) + 2393933972129878613U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 4327069337247976513U) + aNonceWordD;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 8307656353434167837U;
            aOrbiterE = RotL64((aOrbiterE * 11386588389133096705U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 17299145556933889336U) + aOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 14458100581172798164U) ^ aOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16543734663677070509U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 6410095654927998067U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 6168964796264687686U;
            aOrbiterB = RotL64((aOrbiterB * 16218071040190475953U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 3667999465041020730U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 16021552859323602007U;
            aOrbiterH = RotL64((aOrbiterH * 6427266472526362663U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 12941668202330045095U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 4222032891850449934U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17292856787431308097U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 1346342592002730785U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 16860611785008118820U;
            aOrbiterK = RotL64((aOrbiterK * 384963420804756607U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 3193572711804730241U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 5866881282680588589U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9226331800853634597U), 23U);
            //
            aIngress = RotL64(aOrbiterH, 47U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterG, 60U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterK, 19U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterB, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 47U) + aOrbiterA) + RotL64(aOrbiterG, 11U));
            aWandererC = aWandererC + ((RotL64(aCross, 3U) + RotL64(aOrbiterH, 3U)) + aOrbiterA);
            aWandererH = aWandererH ^ ((((RotL64(aScatter, 39U) + RotL64(aOrbiterE, 35U)) + aOrbiterD) + aNonceWordL) + aWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterB, 41U)) + aOrbiterH) + RotL64(aCarry, 53U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 11U) + aOrbiterK) + RotL64(aOrbiterA, 19U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 29U) + aOrbiterB) + RotL64(aOrbiterE, 60U)) + RotL64(aCarry, 5U)) + aWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 60U) + aOrbiterD) + RotL64(aOrbiterB, 29U)) + aNonceWordF);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + (RotL64(aWandererJ, 20U) ^ aWandererC);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 41U));
            aCarry = aCarry + RotL64(aWandererK, 37U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordB);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 21557U)) & S_BLOCK1], 52U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20749U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19840U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 16466U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 44U) + RotL64(aCross, 5U)) ^ (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 21U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererC + RotL64(aIngress, 29U)) + 4739486756133131180U) + aOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = ((aWandererA + RotL64(aScatter, 5U)) + 16089707555501328184U) + aNonceWordE;
            aOrbiterE = (aWandererH + RotL64(aCross, 47U)) + 15310047330238536453U;
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 18U)) + RotL64(aCarry, 5U)) + 7901411596386834955U;
            aOrbiterB = (aWandererK + RotL64(aIngress, 53U)) + 4357555491060982163U;
            aOrbiterF = (((aWandererE + RotL64(aScatter, 41U)) + RotL64(aCarry, 51U)) + 15667085602825720102U) + aOrbiterAssignSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = ((aWandererI + RotL64(aCross, 11U)) + RotL64(aCarry, 35U)) + 8520635334382269253U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 1772509779231068315U) + aOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 15336170957886025677U) ^ aOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10996880551392077399U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 8628770833489469980U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 15469234024247246228U;
            aOrbiterC = RotL64((aOrbiterC * 8905266995119987947U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 10796430900884288328U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 10660110397012853289U;
            aOrbiterK = RotL64((aOrbiterK * 9140007610912037461U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 11202284258711214794U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 17509491802893182994U;
            aOrbiterG = RotL64((aOrbiterG * 9329107599972703671U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 16212572740740103554U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterJ) ^ 2190030203761579226U) ^ aOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterB = RotL64((aOrbiterB * 3101886685668871045U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 12014337082293041909U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 3733531010807001506U) ^ aOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5797362244066062299U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 7100994963061975529U) + aNonceWordG;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 17837541162838600258U;
            aOrbiterJ = RotL64((aOrbiterJ * 8745987361678166553U), 29U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterE, 11U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 21U));
            aIngress = aIngress + RotL64(aOrbiterK, 44U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aScatter, 60U) + RotL64(aOrbiterK, 47U)) + aOrbiterE) + aNonceWordK) + aWandererUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 35U) + aOrbiterC) + RotL64(aOrbiterG, 29U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterG, 57U)) + aOrbiterK) + RotL64(aCarry, 19U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterJ, 5U)) + aOrbiterC);
            aWandererK = aWandererK + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterJ, 37U)) + aOrbiterF);
            aWandererI = aWandererI ^ ((((RotL64(aScatter, 3U) + aOrbiterB) + RotL64(aOrbiterF, 23U)) + aNonceWordH) + aWandererUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aCross, 41U) + aOrbiterF) + RotL64(aOrbiterG, 12U)) + RotL64(aCarry, 35U)) + aNonceWordA);
            //
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 58U));
            aCarry = aCarry + RotL64(aWandererJ, 47U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordB);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 27887U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29655U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 32125U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 28904U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 34U) + RotL64(aCarry, 3U)) ^ (RotL64(aIngress, 47U) ^ RotL64(aCross, 21U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (aWandererG + RotL64(aIngress, 57U)) + 17081642665820489793U;
            aOrbiterA = (((aWandererI + RotL64(aPrevious, 35U)) + RotL64(aCarry, 47U)) + 14468854040067229623U) + aOrbiterAssignSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterK = (((aWandererC + RotL64(aCross, 3U)) + RotL64(aCarry, 3U)) + 2249450222593057429U) + aNonceWordN;
            aOrbiterJ = (aWandererJ + RotL64(aScatter, 47U)) + 14964389079511378664U;
            aOrbiterE = (((aWandererE + RotL64(aPrevious, 13U)) + 17003491054252360650U) + aOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordM;
            aOrbiterB = (aWandererB + RotL64(aScatter, 26U)) + 12710882240582032588U;
            aOrbiterC = (((aWandererD + RotL64(aIngress, 41U)) + RotL64(aCarry, 23U)) + 9887078182156755359U) + aNonceWordG;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 7665284531810584704U) + aNonceWordO;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 7304284015511876717U;
            aOrbiterK = RotL64((aOrbiterK * 6193179739025093929U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 5517927023543751734U) + aOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 17704756310857362759U;
            aOrbiterB = RotL64((aOrbiterB * 15826832172923213591U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 11347400363019508578U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 11696395232760991243U;
            aOrbiterA = RotL64((aOrbiterA * 9725231749679442003U), 19U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterJ) + 10875780291242873583U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordL;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 7808740614343437672U;
            aOrbiterE = RotL64((aOrbiterE * 8889516201913716283U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 3145390996141902032U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 16080636485642732615U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7445756373012217305U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 3929263288176983844U) + aNonceWordK;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 18210228766683996806U;
            aOrbiterJ = RotL64((aOrbiterJ * 13178080076505449091U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 13948962323541421431U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 3037683309790156893U;
            aOrbiterC = RotL64((aOrbiterC * 13406672352222636739U), 51U);
            //
            aIngress = RotL64(aOrbiterC, 29U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterB, 37U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterA, 5U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterE, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aScatter, 34U) + RotL64(aOrbiterE, 37U)) + aOrbiterK) + aWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 23U) + aOrbiterA) + RotL64(aOrbiterH, 19U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 11U) + aOrbiterK) + RotL64(aOrbiterJ, 5U));
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterE, 60U)) + aOrbiterJ) + RotL64(aCarry, 29U)) + aWandererUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterB, 47U)) + aOrbiterC);
            aWandererD = aWandererD + ((((RotL64(aScatter, 47U) + aOrbiterH) + RotL64(aOrbiterC, 13U)) + RotL64(aCarry, 41U)) + aNonceWordD);
            aWandererI = aWandererI ^ ((RotL64(aCross, 53U) + aOrbiterA) + RotL64(aOrbiterC, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 54U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererC);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 41U));
            aCarry = aCarry + RotL64(aWandererE, 21U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ aNonceWordC;
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

void TwistExpander_WaterPolo_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xD24A61355D83A7A9ULL + 0xA0DF9D567F198ADAULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xB37A992CADF37A07ULL + 0xB9E5C3DD5BADA7EDULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x9075A11FA25E7563ULL + 0x9A18074666B35B04ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xE07EF6B60588F2CDULL + 0xB4BDFCE6F268C14FULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xA587577FA29AEB51ULL + 0xBB619672E603367CULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x9187F44E09F3FF1BULL + 0xD8B9D55545AC4C7DULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xD1F9DD31B740B651ULL + 0xA0AD1EA15152CE0AULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x910E2513B1D85B15ULL + 0xD28F9E7243543CA7ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xF036146D613648F1ULL + 0x9BA59ADEAC6AAAB4ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x8C797BDCFBFB26ADULL + 0xEC3A07AF60433788ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xA5FB77C0276F6383ULL + 0x90E5D9F556D9544BULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x9EED3EDD0BA034F9ULL + 0xB7577C6243D94BAAULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xBAD64407FF5887EDULL + 0x8D079D69019FD1C1ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xF740409E5DCF8B67ULL + 0xBFF16B8AC7015335ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x8CACC7F3036546F1ULL + 0xE4E50A3277500298ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x970273B63F6B8ECBULL + 0xF81B93B188E5BC17ULL);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 906U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneC[((aIndex + 8055U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 1600U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 5920U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 51U) ^ RotL64(aPrevious, 4U)) + (RotL64(aCross, 19U) ^ RotL64(aIngress, 35U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((aWandererH + RotL64(aIngress, 53U)) + RotL64(aCarry, 29U)) + 10812151398716051703U;
            aOrbiterG = ((aWandererB + RotL64(aScatter, 13U)) + 18202551453336003710U) + aNonceWordM;
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 21U)) + 9434410809101973752U) + aNonceWordP;
            aOrbiterH = (aWandererC + RotL64(aCross, 28U)) + 12955829998028534045U;
            aOrbiterF = ((aWandererD + RotL64(aScatter, 39U)) + RotL64(aCarry, 13U)) + 12271740641929640181U;
            aOrbiterJ = ((((aWandererE + RotL64(aPrevious, 47U)) + RotL64(aCarry, 57U)) + 14009351527014534752U) + aOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1]) + aNonceWordA;
            aOrbiterI = ((aWandererG + RotL64(aCross, 5U)) + 4316296955679133450U) + aOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 16473324966997442872U) + aNonceWordI;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 15735123324965019802U) ^ aNonceWordB;
            aOrbiterA = RotL64((aOrbiterA * 5624078184997601019U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 17656375090484080236U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 16066325053456055298U;
            aOrbiterF = RotL64((aOrbiterF * 17912970706985130327U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 12908968778503516903U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 12761433987676836197U;
            aOrbiterJ = RotL64((aOrbiterJ * 1023329467480907925U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 12737513138040664509U) + aNonceWordC;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 14535795767570998392U;
            aOrbiterI = RotL64((aOrbiterI * 15560519667062222269U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 14370908061811284364U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 7001358781208669795U) ^ aOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11641248025734015835U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 7298578161120090849U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 10498302152357484629U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13144110412179037175U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 11447343228638006767U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 18284143620422655675U) ^ aOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 572862190073605651U), 13U);
            //
            aIngress = RotL64(aOrbiterA, 53U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 5U));
            aIngress = aIngress + (RotL64(aOrbiterG, 60U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterI, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aCross, 35U) + RotL64(aOrbiterD, 37U)) + aOrbiterA) + RotL64(aCarry, 23U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterF, 57U)) + aOrbiterD) + aNonceWordH);
            aWandererD = aWandererD + ((RotL64(aPrevious, 19U) + aOrbiterJ) + RotL64(aOrbiterD, 13U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterJ, 29U)) + aOrbiterG) + aWandererUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aScatter, 13U) + aOrbiterH) + RotL64(aOrbiterI, 3U)) + RotL64(aCarry, 41U)) + aWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterG, 51U)) + aOrbiterD);
            aWandererG = aWandererG + ((RotL64(aIngress, 54U) + aOrbiterI) + RotL64(aOrbiterG, 20U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + (RotL64(aWandererE, 52U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererG, 21U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordF);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 12790U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 8340U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 15145U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 10707U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 54U) ^ RotL64(aIngress, 5U)) + (RotL64(aCarry, 21U) ^ RotL64(aPrevious, 41U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((aWandererE + RotL64(aScatter, 13U)) + 17074147006464019918U) + aNonceWordM;
            aOrbiterF = (((aWandererH + RotL64(aCross, 35U)) + RotL64(aCarry, 13U)) + 10559516626129419928U) + aOrbiterAssignSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = (aWandererG + RotL64(aPrevious, 23U)) + 13280363679503946221U;
            aOrbiterD = (((aWandererA + RotL64(aIngress, 57U)) + RotL64(aCarry, 37U)) + 17657115422132457413U) + aNonceWordE;
            aOrbiterC = (aWandererJ + RotL64(aScatter, 6U)) + 13325837013304973008U;
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 41U)) + RotL64(aCarry, 53U)) + 3059707750486106037U;
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 29U)) + 4529045702503050852U) + aOrbiterAssignSaltC[((aIndex + 10U)) & S_SALT1];
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 10726578475550904292U) + aNonceWordD;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 14832537837996659885U;
            aOrbiterB = RotL64((aOrbiterB * 808060368961520519U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 220094417441809246U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 15343130035105342194U) ^ aNonceWordP;
            aOrbiterA = RotL64((aOrbiterA * 7984652435043810845U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 16592263353426409884U) + aOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 15649290906447931918U) ^ aNonceWordB;
            aOrbiterD = RotL64((aOrbiterD * 8405875177836650731U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 11437410545843708269U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 5859769136073011444U;
            aOrbiterF = RotL64((aOrbiterF * 1065016088086441107U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 15188064100307340341U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 4367466521843260049U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15916715854192820923U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 8482617283860566845U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 2585745804937342972U;
            aOrbiterK = RotL64((aOrbiterK * 8267269625632139809U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 1687641344403425541U) + aOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 13667916445979421400U;
            aOrbiterJ = RotL64((aOrbiterJ * 8191322670355590027U), 37U);
            //
            aIngress = RotL64(aOrbiterA, 5U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterK, 39U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterC, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aIngress, 51U) + aOrbiterC) + RotL64(aOrbiterK, 3U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterA, 37U)) + aOrbiterD);
            aWandererB = aWandererB + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterC, 47U)) + aOrbiterD) + RotL64(aCarry, 5U)) + aNonceWordL);
            aWandererE = aWandererE ^ ((RotL64(aCross, 11U) + aOrbiterJ) + RotL64(aOrbiterK, 19U));
            aWandererA = aWandererA + (((((RotL64(aIngress, 44U) + RotL64(aOrbiterB, 29U)) + aOrbiterA) + RotL64(aCarry, 39U)) + aNonceWordJ) + aWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((((RotL64(aScatter, 21U) + aOrbiterA) + RotL64(aOrbiterK, 58U)) + aNonceWordG) + aWandererUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 3U) + aOrbiterF) + RotL64(aOrbiterC, 11U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 6U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 51U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + RotL64(aWandererI, 41U);
            aCarry = aCarry + RotL64(aIngress, 36U);
            aCarry = aCarry ^ aNonceWordJ;
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 17934U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23547U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 24215U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneC[((aIndex + 21300U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 37U) + RotL64(aPrevious, 3U)) ^ (RotL64(aIngress, 50U) + RotL64(aCarry, 21U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 37U)) + RotL64(aCarry, 57U)) + 3248574644570178787U;
            aOrbiterD = ((aWandererC + RotL64(aScatter, 58U)) + RotL64(aCarry, 19U)) + 4506961512959200024U;
            aOrbiterC = (aWandererI + RotL64(aCross, 21U)) + 8423739774540738590U;
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 47U)) + 6593975869641735337U) + aNonceWordL;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 27U)) + 16441716090557369103U) + aOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = ((aWandererG + RotL64(aScatter, 11U)) + 7936601450453207914U) + aOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = ((aWandererE + RotL64(aCross, 3U)) + RotL64(aCarry, 5U)) + 13333752583560167065U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 8013703284795432973U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 2349852779887439236U;
            aOrbiterC = RotL64((aOrbiterC * 2422888500648100783U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 5318539364763284138U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 11450957608502944376U) ^ aNonceWordN;
            aOrbiterD = RotL64((aOrbiterD * 1957880366707810635U), 11U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterJ) + 9058992558327552687U) + aOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1]) + aNonceWordI;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 632095686920230926U;
            aOrbiterF = RotL64((aOrbiterF * 12460364388358520799U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 14734218428913777098U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 16344357661370784442U) ^ aOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15049472842002138369U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 2981145363531184308U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 14176472085175714494U;
            aOrbiterK = RotL64((aOrbiterK * 2584623327412130939U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 11198457590069700889U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 952584436750426828U) ^ aOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1165713888651280355U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 4311591763498985972U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 16194341833989936369U;
            aOrbiterA = RotL64((aOrbiterA * 9997934560195932575U), 53U);
            //
            aIngress = RotL64(aOrbiterF, 3U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 41U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 35U));
            aIngress = aIngress + RotL64(aOrbiterK, 56U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterK, 54U)) + aOrbiterA);
            aWandererC = aWandererC + (((RotL64(aPrevious, 3U) + aOrbiterK) + RotL64(aOrbiterI, 39U)) + aNonceWordG);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterF, 11U)) + aOrbiterD);
            aWandererA = aWandererA + ((((RotL64(aScatter, 44U) + aOrbiterJ) + RotL64(aOrbiterK, 47U)) + RotL64(aCarry, 13U)) + aWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterI, 27U)) + aOrbiterC) + aWandererUpdateSaltA[((aIndex + 28U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterJ, 19U)) + aOrbiterF) + RotL64(aCarry, 47U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterD, 3U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + (RotL64(aWandererA, 56U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererE, 51U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordB);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 26546U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31120U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31907U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneD[((aIndex + 28576U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 13U) + RotL64(aCarry, 27U)) ^ (RotL64(aCross, 39U) ^ RotL64(aPrevious, 56U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (((aWandererA + RotL64(aCross, 14U)) + RotL64(aCarry, 3U)) + 15910560457440369082U) + aOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = (((aWandererD + RotL64(aPrevious, 41U)) + RotL64(aCarry, 47U)) + 17953072986407436888U) + aOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = (aWandererH + RotL64(aScatter, 29U)) + 15446940721193538669U;
            aOrbiterE = ((aWandererF + RotL64(aIngress, 53U)) + RotL64(aCarry, 27U)) + 3020785262774422009U;
            aOrbiterB = ((aWandererB + RotL64(aCross, 23U)) + 7001288645424994404U) + aNonceWordI;
            aOrbiterK = (aWandererG + RotL64(aPrevious, 3U)) + 13385250665458462689U;
            aOrbiterF = (aWandererC + RotL64(aScatter, 47U)) + 4841895644623005949U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 13053476783239482065U) + aNonceWordO;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 641996979335975244U;
            aOrbiterI = RotL64((aOrbiterI * 3697673197256549833U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 16211238020928688299U) + aOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 12715448751323279480U) ^ aNonceWordJ;
            aOrbiterK = RotL64((aOrbiterK * 2116880429675303291U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 17784406727699995290U) + aNonceWordK;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 16626339815786580778U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13940754474750138041U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 9035070625716345139U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 6085848172494001945U;
            aOrbiterB = RotL64((aOrbiterB * 10405728912339646693U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 1177103851507561053U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 2281901691017816407U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3142197009403602497U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 9040984343694325070U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 13334258224023902365U;
            aOrbiterE = RotL64((aOrbiterE * 4782523727707164869U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 1079824790138592518U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 14024082692012948652U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3219489374333737903U), 3U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterB, 43U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 19U));
            aIngress = aIngress + (RotL64(aOrbiterK, 6U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterA, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aScatter, 19U) + RotL64(aOrbiterJ, 3U)) + aOrbiterA) + aNonceWordC);
            aWandererF = aWandererF ^ ((((RotL64(aCross, 37U) + aOrbiterI) + RotL64(aOrbiterB, 22U)) + aNonceWordD) + aWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aPrevious, 57U) + aOrbiterF) + RotL64(aOrbiterJ, 29U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterK, 35U)) + aOrbiterE);
            aWandererG = aWandererG + ((((RotL64(aScatter, 46U) + aOrbiterI) + RotL64(aOrbiterE, 57U)) + RotL64(aCarry, 39U)) + aWandererUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterF, 47U)) + aOrbiterB) + aNonceWordN);
            aWandererC = aWandererC + (((RotL64(aCross, 27U) + aOrbiterE) + RotL64(aOrbiterA, 11U)) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 51U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 40U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + RotL64(aWandererC, 35U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordC);
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

void TwistExpander_WaterPolo_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xCCA9B8050F87F3EBULL + 0xF6D92AF40876530AULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xE8AF9FB774F609C9ULL + 0xCDFB18BF46DE9A37ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xEDF3F52EFA514143ULL + 0xD3A6D0EBFE4B13D1ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xFA3A5B91F85FF46FULL + 0xF074161A7056CDB2ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xC65F8FE7668F6531ULL + 0x847C864B71025313ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xDB1137A8295C25A1ULL + 0xF8578A05153BFF2CULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xBDADCDA0B7BB8C7BULL + 0xF2B5C97729D06239ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x9C7624FAFB70A041ULL + 0xAD1F5DB6ABAB0502ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x98F3DA729B819E1FULL + 0xBDDD4889001F3B7AULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xB9CB6339A9DC3235ULL + 0xDA06DBCC0A040F2EULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xCB39E281BAA6145BULL + 0x99B7902B4B552983ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xABBA716D52921B6DULL + 0xB3C52233236D1080ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x8A32A17FCD27FC71ULL + 0xE44774C84C39BAAEULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xB8557F4DED38E6EDULL + 0xC87D9D2219E6549DULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x84C878602A8DEE8BULL + 0xACAC6BE3D4EB799EULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x81CA58D3744CE0FDULL + 0x9132F296BAA98025ULL);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 6340U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2528U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2821U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 4333U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 50U) ^ RotL64(aCarry, 23U)) ^ (RotL64(aIngress, 37U) + RotL64(aCross, 3U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((aWandererB + RotL64(aScatter, 47U)) + 9133751643283278896U) + aOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = (aWandererA + RotL64(aPrevious, 24U)) + 8971581804375380408U;
            aOrbiterA = ((aWandererJ + RotL64(aCross, 57U)) + 12559650383714566592U) + aOrbiterAssignSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterG = (aWandererI + RotL64(aIngress, 21U)) + 15753206088872859163U;
            aOrbiterC = (aWandererE + RotL64(aCross, 27U)) + 7640756270450762350U;
            aOrbiterI = (aWandererD + RotL64(aPrevious, 19U)) + 7340073357551376125U;
            aOrbiterD = (aWandererK + RotL64(aIngress, 10U)) + 5270256573644196046U;
            aOrbiterK = ((aWandererH + RotL64(aScatter, 53U)) + RotL64(aCarry, 5U)) + 3567367996479995928U;
            aOrbiterB = (((aWandererC + RotL64(aCross, 43U)) + RotL64(aCarry, 35U)) + 11939634537492733738U) + aNonceWordM;
            aOrbiterE = (aWandererF + RotL64(aScatter, 29U)) + 7051817732424527120U;
            aOrbiterF = ((aWandererG + RotL64(aIngress, 35U)) + RotL64(aCarry, 57U)) + 1730487669951837941U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 18009252467909454817U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 2361024272031696442U;
            aOrbiterA = RotL64((aOrbiterA * 15215151562500226027U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 15902755877642960397U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 12243517544704116184U;
            aOrbiterI = RotL64((aOrbiterI * 2576071074148141447U), 37U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterK) + 16846181962302186187U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordE;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 636121425116506681U;
            aOrbiterH = RotL64((aOrbiterH * 17075030673338779993U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 6887385655828217318U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 3705834550934775862U;
            aOrbiterG = RotL64((aOrbiterG * 11275428284929594435U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 11165142437077969438U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 6426659930331618269U) ^ aOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17170640810530893705U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 12629082390899315789U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 4277510580069574724U;
            aOrbiterB = RotL64((aOrbiterB * 9829125163412708305U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 13814834144170469978U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 3698381854100295826U;
            aOrbiterF = RotL64((aOrbiterF * 5126359230872258015U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 11623170635983579937U) + aNonceWordI;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 7247413650388803796U;
            aOrbiterJ = RotL64((aOrbiterJ * 3403219499465560059U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 3129755194359521145U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 4081016725582134919U;
            aOrbiterC = RotL64((aOrbiterC * 11564414998539605389U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 15878346077922215753U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 2974440187796944059U;
            aOrbiterK = RotL64((aOrbiterK * 783253926537018373U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 3922344163443096356U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 9133751643283278896U;
            aOrbiterE = RotL64((aOrbiterE * 16887991698415418429U), 21U);
            //
            aIngress = RotL64(aOrbiterB, 47U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterA, 11U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterG, 29U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterE, 54U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 39U));
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aPrevious, 39U) + aOrbiterK) + RotL64(aOrbiterH, 39U)) + aNonceWordN);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 3U) + aOrbiterJ) + RotL64(aOrbiterD, 58U)) + aNonceWordJ);
            aWandererE = aWandererE + (((RotL64(aIngress, 35U) + RotL64(aOrbiterA, 5U)) + aOrbiterH) + aWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 47U) + aOrbiterC) + RotL64(aOrbiterG, 47U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 14U) + RotL64(aOrbiterA, 27U)) + aOrbiterB) + RotL64(aCarry, 47U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 27U) + aOrbiterI) + RotL64(aOrbiterF, 21U)) + aWandererUpdateSaltA[((aIndex + 20U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 57U) + RotL64(aOrbiterK, 35U)) + aOrbiterC);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterF, 3U)) + aOrbiterD) + aNonceWordL);
            aWandererA = aWandererA + ((RotL64(aCross, 37U) + aOrbiterK) + RotL64(aOrbiterF, 23U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterJ, 18U)) + aOrbiterF);
            aWandererI = aWandererI + (((RotL64(aScatter, 60U) + RotL64(aOrbiterA, 11U)) + aOrbiterE) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (RotL64(aWandererK, 50U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + RotL64(aWandererG, 13U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordK);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 8222U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneD[((aIndex + 14732U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 11890U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 13791U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 51U) ^ RotL64(aCarry, 21U)) ^ (RotL64(aPrevious, 39U) + RotL64(aCross, 6U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (((aWandererA + RotL64(aIngress, 46U)) + RotL64(aCarry, 13U)) + 16802219662864902427U) + aNonceWordA;
            aOrbiterD = (aWandererB + RotL64(aScatter, 57U)) + 14332033461409490629U;
            aOrbiterA = (aWandererG + RotL64(aCross, 41U)) + 8781794298640286845U;
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 19U)) + 8459933908074937264U) + aOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = ((aWandererH + RotL64(aScatter, 5U)) + 1883580287986004426U) + aOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = (aWandererI + RotL64(aIngress, 11U)) + 17500258188004626118U;
            aOrbiterJ = (aWandererF + RotL64(aCross, 51U)) + 7934811305150872870U;
            aOrbiterE = (aWandererC + RotL64(aPrevious, 21U)) + 6380363892361098905U;
            aOrbiterC = ((aWandererD + RotL64(aScatter, 27U)) + RotL64(aCarry, 37U)) + 12623079132626676910U;
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 24U)) + RotL64(aCarry, 53U)) + 10455208121949202703U;
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 35U)) + 8805532707916767629U) + aNonceWordH;
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 9161544391400377699U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 3501434325829663268U) ^ aNonceWordM;
            aOrbiterA = RotL64((aOrbiterA * 7933545151293799637U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 651783304096081996U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 441505031509930622U) ^ aNonceWordG;
            aOrbiterD = RotL64((aOrbiterD * 8045355432310956143U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 1771159983581326424U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 15227946417377695989U;
            aOrbiterI = RotL64((aOrbiterI * 1563141188972797601U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 4153717524193279095U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 4404521756523902829U;
            aOrbiterJ = RotL64((aOrbiterJ * 1410342912973206203U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 6231945075461813285U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 3864780227164426690U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 18031353247480673617U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 1509699687948576558U) + aOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 17316114302489411191U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15490661284980281585U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 2250572827340157410U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 6403966113144372915U;
            aOrbiterG = RotL64((aOrbiterG * 726441947009132383U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 2329903609147403156U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 2486330017319455238U;
            aOrbiterB = RotL64((aOrbiterB * 17427461345935191757U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 9333421733051210144U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 14779925626161889533U;
            aOrbiterE = RotL64((aOrbiterE * 9120486933147706541U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 4343688173541745311U) + aOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 12686722305368397686U;
            aOrbiterH = RotL64((aOrbiterH * 17484250022537912537U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 3745163111502795473U) + aNonceWordB;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 16802219662864902427U;
            aOrbiterK = RotL64((aOrbiterK * 4343730534036919417U), 3U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterH, 23U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 21U));
            aIngress = aIngress + (RotL64(aOrbiterG, 27U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 5U));
            aIngress = aIngress + RotL64(aOrbiterE, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 27U) + aOrbiterB) + RotL64(aOrbiterD, 19U));
            aWandererA = aWandererA + ((((RotL64(aIngress, 21U) + RotL64(aOrbiterJ, 43U)) + aOrbiterK) + aNonceWordC) + aWandererUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 37U) + aOrbiterB) + RotL64(aOrbiterI, 54U)) + aNonceWordN);
            aWandererH = aWandererH + ((RotL64(aPrevious, 10U) + RotL64(aOrbiterC, 13U)) + aOrbiterE);
            aWandererI = aWandererI ^ ((RotL64(aCross, 43U) + aOrbiterH) + RotL64(aOrbiterC, 11U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 3U) + aOrbiterD) + RotL64(aOrbiterF, 27U)) + RotL64(aCarry, 37U)) + aNonceWordP);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 19U) + aOrbiterH) + RotL64(aOrbiterG, 47U));
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 34U) + aOrbiterA) + RotL64(aOrbiterJ, 35U)) + RotL64(aCarry, 5U)) + aWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterI, 39U)) + aOrbiterK);
            aWandererC = aWandererC + ((RotL64(aPrevious, 51U) + aOrbiterI) + RotL64(aOrbiterD, 30U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterJ, 41U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 43U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 18U));
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererB);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + RotL64(aWandererC, 30U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordA);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 22598U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 20986U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 21697U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((aIndex + 20180U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aIngress, 57U)) ^ (RotL64(aCarry, 10U) ^ RotL64(aPrevious, 23U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (aWandererH + RotL64(aIngress, 28U)) + 18255347001097480328U;
            aOrbiterC = ((aWandererG + RotL64(aScatter, 41U)) + 13679246790311505735U) + aOrbiterAssignSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 47U)) + RotL64(aCarry, 13U)) + 10565839529765027116U;
            aOrbiterI = ((aWandererI + RotL64(aCross, 3U)) + RotL64(aCarry, 57U)) + 14327172566224769901U;
            aOrbiterG = ((aWandererK + RotL64(aIngress, 57U)) + 16239024612038195174U) + aNonceWordE;
            aOrbiterK = (aWandererB + RotL64(aPrevious, 13U)) + 13800012174212131890U;
            aOrbiterA = ((aWandererC + RotL64(aScatter, 51U)) + RotL64(aCarry, 41U)) + 13900288860157577583U;
            aOrbiterD = (aWandererF + RotL64(aCross, 26U)) + 4144386119777112740U;
            aOrbiterH = ((aWandererD + RotL64(aScatter, 23U)) + 3154558262670631372U) + aOrbiterAssignSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = (aWandererJ + RotL64(aIngress, 11U)) + 7456728543137614001U;
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 21U)) + 11709519851158935384U) + aNonceWordB;
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 15607438907832240304U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 9276575329661725624U;
            aOrbiterJ = RotL64((aOrbiterJ * 8879744070762412745U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 6459435969129449226U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterI) ^ 6442382118416542275U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterK = RotL64((aOrbiterK * 2921027306686588233U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 12117432107282150865U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 6831279293184793243U;
            aOrbiterC = RotL64((aOrbiterC * 2435360641135249073U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 9520022957804572889U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 8322178689474588679U;
            aOrbiterG = RotL64((aOrbiterG * 1627707191467537115U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 4162401591586869316U) + aOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 8994015844714895961U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15421910378057951895U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 10038095909727959633U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 17756404450592957616U;
            aOrbiterE = RotL64((aOrbiterE * 14255952184627347295U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 3379089265413427719U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 11341713098678108441U;
            aOrbiterF = RotL64((aOrbiterF * 2500587373161411961U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 4030296130743454165U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 6332387792111212064U;
            aOrbiterI = RotL64((aOrbiterI * 16490982218150897861U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 14893209417387662133U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 9265457389326311687U;
            aOrbiterA = RotL64((aOrbiterA * 9778404505547862689U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 13496086915199406901U) + aNonceWordN;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 14576555328710787951U;
            aOrbiterH = RotL64((aOrbiterH * 13155395071667672943U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 11482324648071976743U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 18255347001097480328U) ^ aOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10918514878283385643U), 47U);
            //
            aIngress = RotL64(aOrbiterE, 57U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 47U));
            aIngress = aIngress + (RotL64(aOrbiterD, 43U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 35U));
            aIngress = aIngress + (RotL64(aOrbiterK, 19U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterC, 28U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 47U) + aOrbiterJ) + RotL64(aOrbiterK, 10U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 21U) + aOrbiterA) + RotL64(aOrbiterH, 19U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 60U) + aOrbiterB) + RotL64(aOrbiterE, 3U));
            aWandererE = aWandererE + (((RotL64(aIngress, 39U) + aOrbiterA) + RotL64(aOrbiterG, 47U)) + aNonceWordC);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 23U) + aOrbiterF) + RotL64(aOrbiterI, 43U));
            aWandererA = aWandererA + ((((RotL64(aScatter, 43U) + aOrbiterE) + RotL64(aOrbiterK, 29U)) + RotL64(aCarry, 57U)) + aWandererUpdateSaltE[((aIndex + 28U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterI, 51U)) + aOrbiterG);
            aWandererD = aWandererD + (((RotL64(aIngress, 53U) + aOrbiterC) + RotL64(aOrbiterH, 23U)) + aNonceWordA);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterB, 38U)) + aOrbiterG);
            aWandererI = aWandererI + ((((RotL64(aCross, 14U) + RotL64(aOrbiterI, 21U)) + aOrbiterD) + RotL64(aCarry, 23U)) + aNonceWordJ);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 19U) + aOrbiterE) + RotL64(aOrbiterJ, 35U)) + aWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 43U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 6U));
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 51U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + RotL64(aWandererK, 18U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ aNonceWordN;
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 26195U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneB[((aIndex + 25978U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 31533U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((aIndex + 32060U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aIngress, 20U)) ^ (RotL64(aCross, 57U) + RotL64(aPrevious, 37U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (aWandererG + RotL64(aCross, 44U)) + 2974056819475622600U;
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 13U)) + 7345051759236356098U;
            aOrbiterG = ((aWandererD + RotL64(aIngress, 21U)) + RotL64(aCarry, 37U)) + 12738468816846628882U;
            aOrbiterH = ((aWandererF + RotL64(aScatter, 41U)) + 7694520596043297922U) + aNonceWordA;
            aOrbiterJ = ((((aWandererE + RotL64(aPrevious, 29U)) + RotL64(aCarry, 27U)) + 5530753590015084774U) + aOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1]) + aNonceWordL;
            aOrbiterA = (aWandererC + RotL64(aScatter, 53U)) + 3776309161718383105U;
            aOrbiterF = (aWandererI + RotL64(aCross, 3U)) + 784780304358106404U;
            aOrbiterC = (aWandererA + RotL64(aIngress, 60U)) + 8999942326995036509U;
            aOrbiterB = ((aWandererH + RotL64(aScatter, 37U)) + RotL64(aCarry, 51U)) + 5194986506064092779U;
            aOrbiterE = (aWandererB + RotL64(aPrevious, 5U)) + 7920040007459652762U;
            aOrbiterD = ((aWandererK + RotL64(aIngress, 11U)) + 11311997270710107937U) + aOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 5365231114813547251U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 8630110234623825263U;
            aOrbiterG = RotL64((aOrbiterG * 2735881715888325759U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 2358235238039571072U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 18059414891616491807U;
            aOrbiterJ = RotL64((aOrbiterJ * 17150786106857185467U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 14526050556461782864U) + aNonceWordG;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 6937282036603272474U;
            aOrbiterA = RotL64((aOrbiterA * 14954512365270028029U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 10105832250694931310U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 3884223553012098137U;
            aOrbiterF = RotL64((aOrbiterF * 16340956813003906195U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 10385284339549648087U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 1257633893341505930U;
            aOrbiterC = RotL64((aOrbiterC * 2669950791270500977U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 5528890519572824318U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 15664241747527713256U;
            aOrbiterB = RotL64((aOrbiterB * 16670884497088220497U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 14264122979415331887U) + aOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 17985061405540198036U) ^ aNonceWordH;
            aOrbiterE = RotL64((aOrbiterE * 2729487440173395133U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 1663986734997903415U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 3706166884286400587U;
            aOrbiterD = RotL64((aOrbiterD * 10549736618301955745U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 12736963182099961466U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 95411267612114381U;
            aOrbiterK = RotL64((aOrbiterK * 8011937916302325057U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 4966620136499917388U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 8478316876240452401U;
            aOrbiterI = RotL64((aOrbiterI * 13297718919105366563U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 11123814701411614557U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 2974056819475622600U;
            aOrbiterH = RotL64((aOrbiterH * 5913569942407618997U), 23U);
            //
            aIngress = RotL64(aOrbiterI, 5U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterJ, 27U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + (RotL64(aOrbiterE, 43U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterF, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aIngress, 19U) + aOrbiterB) + RotL64(aOrbiterK, 29U)) + RotL64(aCarry, 43U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 51U) + aOrbiterE) + RotL64(aOrbiterI, 27U)) + aNonceWordE);
            aWandererI = aWandererI + ((RotL64(aPrevious, 60U) + RotL64(aOrbiterD, 43U)) + aOrbiterF);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 39U) + aOrbiterG) + RotL64(aOrbiterJ, 48U));
            aWandererH = aWandererH + ((RotL64(aIngress, 3U) + RotL64(aOrbiterB, 53U)) + aOrbiterA);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterH, 23U)) + aOrbiterB) + aNonceWordJ);
            aWandererG = aWandererG + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterJ, 35U)) + aOrbiterE);
            aWandererC = aWandererC ^ ((RotL64(aCross, 5U) + aOrbiterK) + RotL64(aOrbiterG, 5U));
            aWandererB = aWandererB + ((((RotL64(aPrevious, 58U) + RotL64(aOrbiterK, 37U)) + aOrbiterC) + RotL64(aCarry, 5U)) + aNonceWordB);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 35U) + aOrbiterF) + RotL64(aOrbiterK, 39U)) + aWandererUpdateSaltA[((aIndex + 11U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 21U) + aOrbiterE) + RotL64(aOrbiterH, 10U)) + aWandererUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 14U));
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererB);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + (RotL64(aWandererA, 53U) ^ aWandererE);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + RotL64(aWandererI, 5U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ aNonceWordI;
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

void TwistExpander_WaterPolo_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xC6CFD45A551283ABULL + 0xF96B559A8F21F35EULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xECBF5E5DF5ADD693ULL + 0xE024E5B73ADF8C28ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xD9FD6A7F387FA5A5ULL + 0xCAB1E254014FD29AULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xB2A9B020A91A9915ULL + 0xA3723DA68A026943ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x99A7E01686B71439ULL + 0xA537D78D214912EDULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x964FCD8E1EA28159ULL + 0xDE60A5D17A6886FCULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xF94F96DE5EE65623ULL + 0xA30B0E8F545C95F2ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xD16D9D93B8479673ULL + 0xFE86E9CA9539208DULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xEDC4B8681C407475ULL + 0x9D7E4D305B3ECA9CULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x8123F0E40317745DULL + 0xDC2C7723CDEEC204ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xA7D5D88CCD47BDF5ULL + 0xBD453A34B7F10DAEULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xDEE71C6F3105CCC3ULL + 0x9A4D09108D11C36AULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xD8C1135398186695ULL + 0x8D9C89F5A96F613FULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xEC127C168F1CA809ULL + 0xA4A55765FB9BA246ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xC9920ACBDAEFDEF5ULL + 0xC289B443DE2D5341ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x869E1DD997BD8423ULL + 0xD5690621F4D56373ULL);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 859U)) & S_BLOCK1], 40U) ^ RotL64(aOperationLaneC[((aIndex + 5100U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 2689U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 3514U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 27U)) ^ (RotL64(aIngress, 41U) + RotL64(aCross, 12U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (((aWandererA + RotL64(aPrevious, 27U)) + RotL64(aCarry, 53U)) + 6243113109470883144U) + aNonceWordA;
            aOrbiterG = ((aWandererE + RotL64(aCross, 23U)) + RotL64(aCarry, 5U)) + 3891552123999605832U;
            aOrbiterK = (aWandererH + RotL64(aScatter, 57U)) + 8758797898587019128U;
            aOrbiterD = (((aWandererC + RotL64(aIngress, 14U)) + 1005891374086408851U) + aOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordG;
            aOrbiterC = (((aWandererB + RotL64(aScatter, 47U)) + RotL64(aCarry, 29U)) + 3713426782180050764U) + aOrbiterAssignSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = (aWandererG + RotL64(aIngress, 41U)) + 18358143862391573534U;
            aOrbiterH = (aWandererJ + RotL64(aCross, 3U)) + 17504394029693712404U;
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 37U)) + 5312729289027417014U;
            aOrbiterF = (aWandererF + RotL64(aIngress, 10U)) + 2560873623431186029U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 16309322822806704211U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 10195513918020652600U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14569219741824123715U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 2552116263258744287U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 7732784879810980089U) ^ aOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15041929399477790999U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 16499127570665381507U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 10890036715535519036U;
            aOrbiterJ = RotL64((aOrbiterJ * 9065115450010475187U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 16288944603478791554U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 14542766121469312846U;
            aOrbiterF = RotL64((aOrbiterF * 8435383464425875209U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 5973595239494084696U) + aOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 1820492719977197097U;
            aOrbiterI = RotL64((aOrbiterI * 16164917159141304405U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 10489529555776381736U) + aNonceWordO;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 6392552206958240484U;
            aOrbiterD = RotL64((aOrbiterD * 11761477994533503307U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 10163241948999404556U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 16054678853554707148U;
            aOrbiterH = RotL64((aOrbiterH * 10570418210789350091U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 3606021702108590330U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 16920568417324295852U;
            aOrbiterG = RotL64((aOrbiterG * 5222656554577625385U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 13889995689147406315U) + aOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 7908387312354285092U;
            aOrbiterC = RotL64((aOrbiterC * 7995682580514280949U), 39U);
            //
            aIngress = RotL64(aOrbiterI, 51U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterK, 43U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 24U));
            aIngress = aIngress + RotL64(aOrbiterF, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterI, 23U)) + aOrbiterK);
            aWandererB = aWandererB + (((RotL64(aScatter, 57U) + aOrbiterI) + RotL64(aOrbiterG, 39U)) + RotL64(aCarry, 21U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 37U) + aOrbiterK) + RotL64(aOrbiterA, 50U));
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 23U) + RotL64(aOrbiterF, 35U)) + aOrbiterG) + aNonceWordM) + aWandererUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 52U) + aOrbiterD) + RotL64(aOrbiterC, 11U));
            aWandererE = aWandererE + (((RotL64(aScatter, 41U) + RotL64(aOrbiterJ, 5U)) + aOrbiterH) + aNonceWordC);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterJ, 46U)) + aOrbiterD);
            aWandererG = aWandererG + (((((RotL64(aIngress, 19U) + RotL64(aOrbiterD, 27U)) + aOrbiterF) + RotL64(aCarry, 57U)) + aNonceWordK) + aWandererUpdateSaltC[((aIndex + 16U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 12U) + aOrbiterJ) + RotL64(aOrbiterG, 19U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 41U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 21U));
            aCarry = aCarry + (RotL64(aWandererH, 44U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererA, 27U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ aNonceWordF;
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10387U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 7693U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 8388U)) & S_BLOCK1], 50U) ^ RotL64(aOperationLaneB[((aIndex + 9433U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aPrevious, 38U)) + (RotL64(aCarry, 3U) ^ RotL64(aIngress, 19U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = ((aWandererF + RotL64(aCross, 58U)) + RotL64(aCarry, 51U)) + 17264605017518259932U;
            aOrbiterB = (aWandererK + RotL64(aScatter, 23U)) + 15209184354580778643U;
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 5U)) + 3299527965014731384U) + aNonceWordK;
            aOrbiterF = (((aWandererJ + RotL64(aIngress, 47U)) + RotL64(aCarry, 29U)) + 16293096431816127821U) + aNonceWordJ;
            aOrbiterH = (aWandererH + RotL64(aCross, 29U)) + 11031983436878828337U;
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 52U)) + 9188018632448236358U) + aNonceWordL;
            aOrbiterI = ((aWandererI + RotL64(aScatter, 41U)) + RotL64(aCarry, 39U)) + 13420816400363406556U;
            aOrbiterD = ((aWandererB + RotL64(aIngress, 11U)) + 2485063384097917101U) + aOrbiterAssignSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = ((aWandererA + RotL64(aCross, 37U)) + 3089135816938128264U) + aOrbiterAssignSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 10730544971770435788U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 10431767565618874806U;
            aOrbiterG = RotL64((aOrbiterG * 4723078464590561545U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 14883796491656899074U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 13465877783538483706U;
            aOrbiterH = RotL64((aOrbiterH * 14311686051108108503U), 39U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterH) + 13322163435314643713U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordE;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 3307316600284371955U;
            aOrbiterI = RotL64((aOrbiterI * 12337846092069506365U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 4950101626975919939U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 2596253994220103666U;
            aOrbiterD = RotL64((aOrbiterD * 7181706961838582889U), 19U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterD) + 17961706029559914243U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordC;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 10321902557977495175U;
            aOrbiterA = RotL64((aOrbiterA * 16189559888625084711U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 18146616411403012772U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 8414050129421955787U;
            aOrbiterC = RotL64((aOrbiterC * 14879448948196182863U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 11739172334166341121U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 7936637782633487291U;
            aOrbiterF = RotL64((aOrbiterF * 14940929920543800413U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 3160044627483874242U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 16816384076887379704U) ^ aOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5052772186568301951U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 8101560104988710226U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 8851416379738817624U;
            aOrbiterB = RotL64((aOrbiterB * 16767420038937389027U), 47U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterA, 34U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 41U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 37U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 47U));
            aIngress = aIngress + RotL64(aOrbiterD, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterB, 5U)) + aOrbiterH);
            aWandererD = aWandererD + (((RotL64(aCross, 54U) + RotL64(aOrbiterD, 47U)) + aOrbiterG) + aNonceWordI);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterF, 10U)) + aOrbiterH);
            aWandererK = aWandererK + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterD, 21U)) + aOrbiterI);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterE, 27U)) + aOrbiterG);
            aWandererF = aWandererF + (((RotL64(aIngress, 18U) + aOrbiterA) + RotL64(aOrbiterG, 35U)) + RotL64(aCarry, 11U));
            aWandererA = aWandererA ^ ((((RotL64(aCross, 23U) + aOrbiterE) + RotL64(aOrbiterI, 43U)) + aNonceWordP) + aWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 43U) + RotL64(aOrbiterE, 60U)) + aOrbiterC) + RotL64(aCarry, 47U)) + aNonceWordH);
            aWandererE = aWandererE ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterF, 53U)) + aOrbiterB) + aWandererUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 6U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererJ);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + RotL64(aWandererH, 23U);
            aCarry = aCarry + RotL64(aIngress, 34U);
            aCarry = aCarry ^ aNonceWordL;
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 15152U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16322U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 12440U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 14083U)) & S_BLOCK1], 50U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 37U) + RotL64(aCross, 18U)) ^ (RotL64(aIngress, 5U) + RotL64(aCarry, 57U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = ((((aWandererD + RotL64(aCross, 43U)) + RotL64(aCarry, 27U)) + 9080426856729228705U) + aOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1]) + aNonceWordG;
            aOrbiterI = ((aWandererH + RotL64(aScatter, 19U)) + 7851218321653539276U) + aNonceWordF;
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 60U)) + RotL64(aCarry, 47U)) + 7023344692919298036U;
            aOrbiterB = ((aWandererG + RotL64(aIngress, 53U)) + RotL64(aCarry, 19U)) + 9772846154227440734U;
            aOrbiterF = (aWandererB + RotL64(aCross, 5U)) + 12008298632429608431U;
            aOrbiterH = (((aWandererJ + RotL64(aIngress, 35U)) + 12201090455849562875U) + aOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1]) + aNonceWordN;
            aOrbiterD = (aWandererE + RotL64(aScatter, 26U)) + 9498721803411445471U;
            aOrbiterE = (aWandererK + RotL64(aPrevious, 47U)) + 351203764023093632U;
            aOrbiterG = (aWandererF + RotL64(aScatter, 11U)) + 4966360430644539250U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 9194167899071345693U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 4922477697284269116U;
            aOrbiterJ = RotL64((aOrbiterJ * 8444814161720407881U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 15742625291642356429U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 7528703106518431730U;
            aOrbiterC = RotL64((aOrbiterC * 11530049278751507567U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 15279053574704935317U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 2425839793660355555U;
            aOrbiterB = RotL64((aOrbiterB * 11486964816849830667U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 13209849392400008898U) + aNonceWordA;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 9041500097716231309U;
            aOrbiterI = RotL64((aOrbiterI * 340661035700748739U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 7885423750878814599U) + aOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 1992993999902904603U;
            aOrbiterF = RotL64((aOrbiterF * 1478629826632201617U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 6120758615019314102U) + aOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 8529621625846992066U) ^ aOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8485991471612862467U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 9125182130757385320U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 15691232622970220043U;
            aOrbiterD = RotL64((aOrbiterD * 16517916951054758147U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 11413090085435424697U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 11563151001080914939U;
            aOrbiterE = RotL64((aOrbiterE * 16828196274450408201U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 1778975369262558069U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 3232132443557192010U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17132823737792200981U), 5U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterE, 19U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 23U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 14U));
            aIngress = aIngress + RotL64(aOrbiterC, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterH, 42U)) + aOrbiterG);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 22U) + RotL64(aOrbiterG, 23U)) + aOrbiterJ) + aNonceWordK);
            aWandererH = aWandererH + (((RotL64(aCross, 11U) + aOrbiterD) + RotL64(aOrbiterF, 57U)) + aWandererUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterF, 37U)) + aOrbiterB);
            aWandererG = aWandererG + (((RotL64(aCross, 57U) + aOrbiterD) + RotL64(aOrbiterI, 29U)) + RotL64(aCarry, 35U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterF, 13U)) + aOrbiterI);
            aWandererF = aWandererF + (((RotL64(aScatter, 35U) + RotL64(aOrbiterC, 46U)) + aOrbiterF) + aWandererUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 6U) + aOrbiterC) + RotL64(aOrbiterG, 53U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 41U) + aOrbiterF) + RotL64(aOrbiterE, 3U)) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 50U));
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererD, 23U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ aNonceWordJ;
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 20237U)) & S_BLOCK1], 6U) ^ RotL64(aWorkLaneB[((aIndex + 17062U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21185U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 16619U)) & S_BLOCK1], 24U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCarry, 20U)) ^ (RotL64(aIngress, 51U) + RotL64(aCross, 3U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (aWandererA + RotL64(aScatter, 51U)) + 2558105147674438050U;
            aOrbiterE = (aWandererC + RotL64(aPrevious, 35U)) + 15856662514774702561U;
            aOrbiterF = ((aWandererJ + RotL64(aCross, 28U)) + 13346869226246584582U) + aOrbiterAssignSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = (aWandererE + RotL64(aIngress, 57U)) + 7632111846116243973U;
            aOrbiterJ = ((aWandererB + RotL64(aCross, 23U)) + RotL64(aCarry, 19U)) + 2102101361626976279U;
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 47U)) + RotL64(aCarry, 43U)) + 5605968705067851563U;
            aOrbiterC = ((((aWandererF + RotL64(aScatter, 43U)) + RotL64(aCarry, 27U)) + 6842483186584326681U) + aOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordH;
            aOrbiterG = (aWandererI + RotL64(aIngress, 13U)) + 5559797213819425064U;
            aOrbiterH = (aWandererK + RotL64(aCross, 18U)) + 12422313931331576759U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 2751024420047872601U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 11031320239359798610U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8607639453141148025U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 14366375309473793217U) + aNonceWordM;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 11971479429768505316U;
            aOrbiterJ = RotL64((aOrbiterJ * 10063001532313098203U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 3947595951884469542U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 17882767922372770896U;
            aOrbiterC = RotL64((aOrbiterC * 3361906348965810211U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 513871456983509223U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 5951677013597794294U) ^ aOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8508629569649935293U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 437626309049021931U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 466674061172005705U) ^ aNonceWordN;
            aOrbiterI = RotL64((aOrbiterI * 1310502572084891157U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 12362602809233133718U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 10525852878882195702U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17755022180514914325U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 17927000184308583095U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 566723721423470052U;
            aOrbiterG = RotL64((aOrbiterG * 17710534355278632573U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 9504585484034413577U) + aOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 4614306037721859929U;
            aOrbiterH = RotL64((aOrbiterH * 170807293799483539U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 1463218357720031588U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 4036696102163560633U;
            aOrbiterE = RotL64((aOrbiterE * 15389914226155130065U), 23U);
            //
            aIngress = RotL64(aOrbiterC, 43U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 30U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 53U));
            aIngress = aIngress + (RotL64(aOrbiterI, 5U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterG, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterF, 35U)) + aOrbiterJ) + aNonceWordP);
            aWandererE = aWandererE + (((RotL64(aIngress, 19U) + RotL64(aOrbiterE, 14U)) + aOrbiterI) + aWandererUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 30U) + RotL64(aOrbiterC, 53U)) + aOrbiterK) + aNonceWordI);
            aWandererB = aWandererB + ((RotL64(aPrevious, 41U) + aOrbiterB) + RotL64(aOrbiterH, 43U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterI, 57U)) + aOrbiterJ) + aWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterG, 47U)) + aOrbiterC) + RotL64(aCarry, 47U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 10U) + RotL64(aOrbiterE, 3U)) + aOrbiterC);
            aWandererG = aWandererG + (((RotL64(aIngress, 23U) + aOrbiterJ) + RotL64(aOrbiterH, 21U)) + RotL64(aCarry, 21U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 51U) + aOrbiterG) + RotL64(aOrbiterF, 26U)) + aNonceWordD);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 24U));
            aCarry = aCarry + (RotL64(aWandererE, 21U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 51U));
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererJ, 40U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordP);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 23594U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneA[((aIndex + 25807U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27066U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25781U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 35U) + RotL64(aCross, 50U)) ^ (RotL64(aIngress, 21U) ^ RotL64(aCarry, 3U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 43U)) + 5510690816044082200U) + aOrbiterAssignSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = (aWandererI + RotL64(aIngress, 24U)) + 15967820875033940530U;
            aOrbiterI = ((aWandererK + RotL64(aScatter, 47U)) + 539348720848176221U) + aNonceWordB;
            aOrbiterA = (((aWandererA + RotL64(aCross, 39U)) + RotL64(aCarry, 53U)) + 15779318183635560817U) + aNonceWordA;
            aOrbiterD = (aWandererG + RotL64(aScatter, 3U)) + 14511058534424187469U;
            aOrbiterJ = ((aWandererD + RotL64(aCross, 28U)) + 5811130556873428391U) + aOrbiterAssignSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = (((aWandererC + RotL64(aIngress, 19U)) + RotL64(aCarry, 11U)) + 1085928476499444025U) + aNonceWordI;
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 57U)) + RotL64(aCarry, 29U)) + 6973335316600768130U;
            aOrbiterB = (aWandererE + RotL64(aScatter, 53U)) + 10747243745475009744U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 1072260008981349754U) + aOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 2018772405352495753U) ^ aOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10840562112080574241U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 1092091597048996547U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 15103140149542167197U;
            aOrbiterJ = RotL64((aOrbiterJ * 621856991658027989U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 13194619321108681542U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 16749188603268621850U;
            aOrbiterF = RotL64((aOrbiterF * 9575408950550922039U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 7427959503086895166U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 9895804051379551393U;
            aOrbiterB = RotL64((aOrbiterB * 2701997336201570715U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 4526020800679774259U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 4484850928870048176U;
            aOrbiterH = RotL64((aOrbiterH * 17556987520625677313U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 1837404844299040155U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 15213208978489570694U;
            aOrbiterA = RotL64((aOrbiterA * 7062740584650274133U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 9615231781751396800U) + aNonceWordN;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 15872192167825648096U;
            aOrbiterK = RotL64((aOrbiterK * 2900526493682580729U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 12530672039655918903U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 10617836782870315804U;
            aOrbiterE = RotL64((aOrbiterE * 9716778004909794973U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 550750725406860977U) + aOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = (((aOrbiterD ^ aOrbiterB) ^ 3498554352021622907U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterD = RotL64((aOrbiterD * 9846933294851238495U), 47U);
            //
            aIngress = RotL64(aOrbiterB, 21U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 51U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 42U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 11U));
            aIngress = aIngress + RotL64(aOrbiterE, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 37U) + aOrbiterB) + RotL64(aOrbiterF, 39U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 30U) + RotL64(aOrbiterJ, 35U)) + aOrbiterB) + RotL64(aCarry, 35U)) + aWandererUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 57U) + aOrbiterE) + RotL64(aOrbiterB, 51U)) + aNonceWordC);
            aWandererA = aWandererA + ((RotL64(aCross, 5U) + aOrbiterA) + RotL64(aOrbiterD, 10U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 11U) + aOrbiterK) + RotL64(aOrbiterI, 23U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterH, 27U)) + aOrbiterI) + aWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 42U) + aOrbiterK) + RotL64(aOrbiterA, 19U)) + aNonceWordO);
            aWandererF = aWandererF + (((RotL64(aCross, 19U) + aOrbiterJ) + RotL64(aOrbiterA, 5U)) + RotL64(aCarry, 47U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 47U) + aOrbiterI) + RotL64(aOrbiterA, 14U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 52U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererF, 41U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererE, 57U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordM);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 30207U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29347U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30269U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28647U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 28U) ^ RotL64(aCarry, 43U)) ^ (RotL64(aCross, 5U) + RotL64(aPrevious, 57U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 23U)) + 10726035965553989335U) + aNonceWordI;
            aOrbiterG = (aWandererF + RotL64(aCross, 43U)) + 967354339530195662U;
            aOrbiterI = ((aWandererC + RotL64(aScatter, 47U)) + RotL64(aCarry, 21U)) + 10834593005478605624U;
            aOrbiterJ = (aWandererI + RotL64(aIngress, 53U)) + 1012888282838656933U;
            aOrbiterH = (aWandererH + RotL64(aScatter, 34U)) + 15283530351725183253U;
            aOrbiterC = (((aWandererG + RotL64(aPrevious, 11U)) + RotL64(aCarry, 5U)) + 11724495956731703750U) + aNonceWordB;
            aOrbiterA = (aWandererK + RotL64(aIngress, 3U)) + 4288330117317505776U;
            aOrbiterF = (((aWandererB + RotL64(aCross, 39U)) + RotL64(aCarry, 51U)) + 10894778070022873473U) + aOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = ((aWandererE + RotL64(aIngress, 58U)) + 15563886747621617467U) + aOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 11182488628562891937U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 10420140066310588580U;
            aOrbiterI = RotL64((aOrbiterI * 13898299782819948719U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 11775138062167543111U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 16545391898578161683U) ^ aOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14588306527161321535U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 1550144656312299266U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 14903504853138279883U) ^ aOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8003033561266164387U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 309935535526750396U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 13991265868040011411U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2887531132228588441U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 1755976294857114222U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 2259275858478396846U;
            aOrbiterK = RotL64((aOrbiterK * 7416165760067878161U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 4838175912944552936U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 12307900457200936013U;
            aOrbiterB = RotL64((aOrbiterB * 14719363144850838805U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 18025411832912225805U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 981375022769564523U;
            aOrbiterJ = RotL64((aOrbiterJ * 15869361544011831483U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 3174014054982742562U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterF) ^ 8119692378748963609U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterC = RotL64((aOrbiterC * 3072354179707448489U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 14502863160788675807U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 1207582534593709516U;
            aOrbiterG = RotL64((aOrbiterG * 3045412087535529357U), 47U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterG, 29U);
            aIngress = aIngress + (RotL64(aOrbiterK, 47U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 60U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 13U));
            aIngress = aIngress + RotL64(aOrbiterI, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 34U) + RotL64(aOrbiterA, 19U)) + aOrbiterG);
            aWandererG = aWandererG + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterF, 41U)) + aOrbiterJ);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 39U) + aOrbiterI) + RotL64(aOrbiterK, 47U)) + aWandererUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 47U) + aOrbiterC) + RotL64(aOrbiterH, 24U)) + RotL64(aCarry, 57U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 23U) + aOrbiterI) + RotL64(aOrbiterB, 11U));
            aWandererA = aWandererA + ((RotL64(aScatter, 6U) + aOrbiterC) + RotL64(aOrbiterJ, 53U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterG, 37U)) + aOrbiterB) + aWandererUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aIngress, 29U) + RotL64(aOrbiterJ, 29U)) + aOrbiterH) + RotL64(aCarry, 5U)) + aNonceWordP);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 53U) + aOrbiterG) + RotL64(aOrbiterK, 4U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 20U));
            aCarry = aCarry + (RotL64(aWandererH, 27U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererC, 43U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordF);
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

void TwistExpander_WaterPolo_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x9BC5CB0488EEA9CFULL + 0xD21579D007FB5671ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xDBF54A0F304FE0A7ULL + 0xCB0CCFDF19729BDFULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xFE9E5929CB362E45ULL + 0xA4CD01893F59CAE6ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xB82DE5A160093C21ULL + 0xB7E5A2D575BAA946ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xE7310ADF4E978143ULL + 0x850C73267CF09FA9ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xB52000C950A2321DULL + 0xF192DE33234E5790ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xAF0666A1E22003FFULL + 0xF80EE4DD4D04F452ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xAEE2BCEE084200EDULL + 0xAD47E4BD95894148ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xC9A846382B6236A7ULL + 0x9B22E30A4F225DD8ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xEF49E6BA5650A475ULL + 0xCB4A6651D954D058ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xBFC185BC67A3B52DULL + 0x85A96EA4624FCC8DULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xCFC1116DEF069D2FULL + 0xF88DC026CB5B5747ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xE35E360E84B4EF39ULL + 0xF203BDC2E63E06E6ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xD80C40D29C1C1B07ULL + 0x830F42173DBBDE9DULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xCE7538E363E70C45ULL + 0xD8A9CBB0E508E843ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xFD8EBC957FB83FA3ULL + 0x93D8BC2C3816D7F4ULL);
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
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 2615U)) & S_BLOCK1], 47U) ^ RotL64(aKeyRowReadA[((aIndex + 2434U)) & W_KEY1], 29U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 3463U)) & W_KEY1], 19U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 3894U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 56U) + RotL64(aCarry, 41U)) + (RotL64(aPrevious, 27U) ^ RotL64(aCross, 5U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterI = ((aWandererB + RotL64(aIngress, 23U)) + RotL64(aCarry, 41U)) + 7948891781097675369U;
            aOrbiterH = (((aWandererD + RotL64(aScatter, 35U)) + 13928362874228230226U) + aPhaseAOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1]) + aNonceWordD;
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 11U)) + 10776180542602258926U) + aPhaseAOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = ((aWandererE + RotL64(aCross, 29U)) + RotL64(aCarry, 57U)) + 5735115172149470447U;
            aOrbiterD = ((aWandererC + RotL64(aScatter, 3U)) + RotL64(aCarry, 11U)) + 5353591822981766987U;
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 60U)) + 562301708107268570U) + aNonceWordL;
            aOrbiterJ = (aWandererI + RotL64(aIngress, 51U)) + 10467810247578364868U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 14541630141152308564U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 2350076897065139429U;
            aOrbiterF = RotL64((aOrbiterF * 12222554362482034393U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 17519109078651162228U) + aNonceWordH;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 6061035173339902910U;
            aOrbiterD = RotL64((aOrbiterD * 10021905773432907835U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 15654836633731000065U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 13723521735153718904U;
            aOrbiterC = RotL64((aOrbiterC * 14459516479283070563U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 2849680038315532197U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterF) ^ 17336102435576647923U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterJ = RotL64((aOrbiterJ * 10984689101753586739U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 7671010488872356142U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 11485114338165600777U;
            aOrbiterI = RotL64((aOrbiterI * 4162584865462407791U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 8759060657343458985U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 11009137869375286581U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8741417343929809115U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 15792999392743144135U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 6180808423175992479U) ^ aNonceWordC;
            aOrbiterH = RotL64((aOrbiterH * 13681230339693676907U), 3U);
            //
            aIngress = RotL64(aOrbiterJ, 11U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + (RotL64(aOrbiterD, 23U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterG, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 60U) + aOrbiterI) + RotL64(aOrbiterF, 19U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterH, 43U)) + aOrbiterC) + RotL64(aCarry, 11U));
            aWandererI = aWandererI ^ ((((RotL64(aScatter, 53U) + aOrbiterG) + RotL64(aOrbiterJ, 3U)) + aNonceWordG) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 37U) + RotL64(aOrbiterC, 54U)) + aOrbiterI) + RotL64(aCarry, 35U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 43U) + aOrbiterF) + RotL64(aOrbiterG, 37U));
            aWandererC = aWandererC + ((RotL64(aIngress, 23U) + aOrbiterD) + RotL64(aOrbiterI, 11U));
            aWandererF = aWandererF ^ ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterF, 29U)) + aOrbiterC) + aNonceWordM) + aPhaseAWandererUpdateSaltA[((aIndex + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 53U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 29U));
            aCarry = aCarry + RotL64(aWandererI, 58U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordE);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 6934U)) & S_BLOCK1], 10U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 8398U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 6010U)) & W_KEY1], 13U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 6656U)) & W_KEY1], 60U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 51U) + RotL64(aIngress, 4U)) ^ (RotL64(aPrevious, 35U) + RotL64(aCross, 23U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterI = (aWandererB + RotL64(aScatter, 57U)) + 15549114274303128055U;
            aOrbiterH = (aWandererE + RotL64(aIngress, 3U)) + 16466750056388063241U;
            aOrbiterJ = (aWandererD + RotL64(aCross, 51U)) + 12209449840836787142U;
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 34U)) + RotL64(aCarry, 11U)) + 14551496099734294336U;
            aOrbiterC = ((aWandererC + RotL64(aIngress, 27U)) + RotL64(aCarry, 53U)) + 6266576428679808622U;
            aOrbiterK = (((aWandererI + RotL64(aScatter, 21U)) + 16892841575635668152U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordF;
            aOrbiterF = (((aWandererK + RotL64(aCross, 13U)) + RotL64(aCarry, 35U)) + 7375966221423362125U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 11926105302821753530U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 16219253791550461124U;
            aOrbiterJ = RotL64((aOrbiterJ * 2117550758226173419U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 7299056065319248160U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 15234001484933728439U;
            aOrbiterI = RotL64((aOrbiterI * 8182244796017018911U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 6615802589932632120U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 5481176858895819247U;
            aOrbiterG = RotL64((aOrbiterG * 3604590158551984877U), 29U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterF) + 17220507586542139380U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1]) + aNonceWordC;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 14137921473739415340U;
            aOrbiterH = RotL64((aOrbiterH * 10634645686035907603U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 16981960446540932787U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 10897565927079518588U;
            aOrbiterC = RotL64((aOrbiterC * 418843936329303571U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 2746889569299593263U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 4894117146736361379U;
            aOrbiterK = RotL64((aOrbiterK * 2656750612042673191U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 18294823016957137777U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterJ) ^ 86828501068883383U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterF = RotL64((aOrbiterF * 11432686669235402365U), 21U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterJ, 11U);
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterH, 43U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterF, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 5U) + RotL64(aOrbiterI, 51U)) + aOrbiterK) + RotL64(aCarry, 43U)) + aNonceWordI);
            aWandererE = aWandererE ^ ((RotL64(aCross, 51U) + aOrbiterH) + RotL64(aOrbiterK, 41U));
            aWandererK = aWandererK + (((RotL64(aIngress, 28U) + RotL64(aOrbiterI, 23U)) + aOrbiterH) + aNonceWordJ);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 13U) + aOrbiterJ) + RotL64(aOrbiterG, 29U)) + aNonceWordD);
            aWandererI = aWandererI + (((RotL64(aScatter, 43U) + RotL64(aOrbiterI, 14U)) + aOrbiterG) + aPhaseAWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 19U) + aOrbiterC) + RotL64(aOrbiterH, 35U));
            aWandererC = aWandererC + ((((RotL64(aCross, 57U) + RotL64(aOrbiterK, 3U)) + aOrbiterF) + RotL64(aCarry, 29U)) + aPhaseAWandererUpdateSaltC[((aIndex + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 58U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 37U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + RotL64(aWandererI, 13U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordF);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 15392U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((aIndex + 13784U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 12484U)) & W_KEY1], 54U) ^ RotL64(aKeyRowReadB[((aIndex + 14733U)) & W_KEY1], 19U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCross, 29U)) + (RotL64(aCarry, 43U) + RotL64(aIngress, 10U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterC = ((((aWandererG + RotL64(aCross, 35U)) + RotL64(aCarry, 11U)) + 17264605017518259932U) + aPhaseAOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1]) + aNonceWordH;
            aOrbiterI = (aWandererJ + RotL64(aIngress, 13U)) + 15209184354580778643U;
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 5U)) + RotL64(aCarry, 23U)) + 3299527965014731384U;
            aOrbiterH = ((aWandererH + RotL64(aScatter, 29U)) + RotL64(aCarry, 35U)) + 16293096431816127821U;
            aOrbiterA = (aWandererF + RotL64(aIngress, 51U)) + 11031983436878828337U;
            aOrbiterK = ((aWandererI + RotL64(aScatter, 44U)) + 9188018632448236358U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 19U)) + 13420816400363406556U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 2485063384097917101U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 3089135816938128264U;
            aOrbiterF = RotL64((aOrbiterF * 8813152992957361153U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 10730544971770435788U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 10431767565618874806U;
            aOrbiterI = RotL64((aOrbiterI * 4723078464590561545U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 14883796491656899074U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 13465877783538483706U;
            aOrbiterC = RotL64((aOrbiterC * 14311686051108108503U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 13322163435314643713U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 3307316600284371955U;
            aOrbiterH = RotL64((aOrbiterH * 12337846092069506365U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 4950101626975919939U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 2596253994220103666U;
            aOrbiterA = RotL64((aOrbiterA * 7181706961838582889U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 17961706029559914243U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 10321902557977495175U;
            aOrbiterK = RotL64((aOrbiterK * 16189559888625084711U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 18146616411403012772U) + aNonceWordD;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 8414050129421955787U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14879448948196182863U), 51U);
            //
            aIngress = RotL64(aOrbiterK, 5U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 56U));
            aIngress = aIngress + RotL64(aOrbiterI, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aIngress, 11U) + aOrbiterJ) + RotL64(aOrbiterF, 19U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterI, 27U)) + aOrbiterJ) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aCross, 29U) + RotL64(aOrbiterK, 3U)) + aOrbiterA) + RotL64(aCarry, 27U)) + aNonceWordG);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 19U) + aOrbiterI) + RotL64(aOrbiterC, 48U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 39U) + aOrbiterK) + RotL64(aOrbiterJ, 11U)) + aNonceWordF);
            aWandererD = aWandererD ^ (((RotL64(aCross, 51U) + RotL64(aOrbiterH, 57U)) + aOrbiterF) + aPhaseAWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 60U) + aOrbiterK) + RotL64(aOrbiterF, 37U)) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 22U) ^ aWandererJ);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 41U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + RotL64(aWandererG, 3U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordD);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 19930U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20641U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20971U)) & S_BLOCK1], 53U) ^ RotL64(mSource[((aIndex + 17700U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 54U) + RotL64(aCross, 5U)) + (RotL64(aIngress, 41U) ^ RotL64(aCarry, 23U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 27U)) + 10812151398716051703U;
            aOrbiterB = (((aWandererE + RotL64(aScatter, 51U)) + RotL64(aCarry, 3U)) + 18202551453336003710U) + aNonceWordD;
            aOrbiterI = ((((aWandererI + RotL64(aIngress, 58U)) + RotL64(aCarry, 35U)) + 9434410809101973752U) + aPhaseAOrbiterAssignSaltE[((aIndex + 25U)) & S_SALT1]) + aNonceWordP;
            aOrbiterD = (((aWandererA + RotL64(aCross, 11U)) + RotL64(aCarry, 21U)) + 12955829998028534045U) + aNonceWordL;
            aOrbiterK = (aWandererK + RotL64(aPrevious, 3U)) + 12271740641929640181U;
            aOrbiterG = (aWandererC + RotL64(aScatter, 21U)) + 14009351527014534752U;
            aOrbiterC = ((aWandererH + RotL64(aIngress, 39U)) + 4316296955679133450U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 16473324966997442872U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 15735123324965019802U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5624078184997601019U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 17656375090484080236U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 16066325053456055298U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17912970706985130327U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 12908968778503516903U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 12761433987676836197U;
            aOrbiterB = RotL64((aOrbiterB * 1023329467480907925U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 12737513138040664509U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 14535795767570998392U;
            aOrbiterK = RotL64((aOrbiterK * 15560519667062222269U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 14370908061811284364U) + aNonceWordN;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterG) ^ 7001358781208669795U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterJ = RotL64((aOrbiterJ * 11641248025734015835U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 7298578161120090849U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 10498302152357484629U;
            aOrbiterD = RotL64((aOrbiterD * 13144110412179037175U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 11447343228638006767U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 18284143620422655675U;
            aOrbiterC = RotL64((aOrbiterC * 572862190073605651U), 51U);
            //
            aIngress = RotL64(aOrbiterG, 47U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterD, 56U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 37U));
            aIngress = aIngress + RotL64(aOrbiterI, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 41U) + aOrbiterK) + RotL64(aOrbiterB, 51U));
            aWandererK = aWandererK + (((RotL64(aIngress, 35U) + RotL64(aOrbiterI, 58U)) + aOrbiterB) + RotL64(aCarry, 27U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterK, 29U)) + aOrbiterI) + aPhaseAWandererUpdateSaltF[((aIndex + 22U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 53U) + aOrbiterD) + RotL64(aOrbiterB, 3U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 3U) + aOrbiterI) + RotL64(aOrbiterJ, 23U)) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterC, 13U)) + aOrbiterJ) + RotL64(aCarry, 47U)) + aNonceWordH);
            aWandererI = aWandererI ^ (((RotL64(aCross, 10U) + aOrbiterK) + RotL64(aOrbiterG, 43U)) + aNonceWordE);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 10U));
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererA, 35U);
            aCarry = aCarry + RotL64(aIngress, 14U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordL);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 24780U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26876U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 22209U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25634U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 24U)) + (RotL64(aIngress, 39U) + RotL64(aCross, 5U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterF = ((aWandererD + RotL64(aScatter, 14U)) + 13481227414590594621U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterJ = ((aWandererF + RotL64(aCross, 47U)) + RotL64(aCarry, 27U)) + 17425964381118918026U;
            aOrbiterC = ((aWandererH + RotL64(aIngress, 35U)) + 4792004356135956581U) + aNonceWordG;
            aOrbiterG = (((aWandererG + RotL64(aPrevious, 57U)) + RotL64(aCarry, 51U)) + 11926849936000639098U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = ((aWandererB + RotL64(aScatter, 5U)) + 990697329347742142U) + aNonceWordF;
            aOrbiterD = ((aWandererA + RotL64(aIngress, 23U)) + RotL64(aCarry, 39U)) + 9307721505373076588U;
            aOrbiterH = ((aWandererJ + RotL64(aCross, 29U)) + 17605732738841908719U) + aNonceWordP;
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 13110764518634187439U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 17970109897810645911U;
            aOrbiterC = RotL64((aOrbiterC * 10395095143998920213U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 10273133817644703654U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 11239046688920468137U;
            aOrbiterF = RotL64((aOrbiterF * 5197802934333553327U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 8355821483275763145U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 15522151127786049345U;
            aOrbiterG = RotL64((aOrbiterG * 4844278537850520413U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 5381663179722418112U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 9551368011768104906U;
            aOrbiterJ = RotL64((aOrbiterJ * 14202470972121732997U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 16264476585232221270U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 7721417776432288282U) ^ aNonceWordA;
            aOrbiterI = RotL64((aOrbiterI * 10267770327791051869U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 339418090653475277U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 3247926250495935511U;
            aOrbiterD = RotL64((aOrbiterD * 16824669543765729097U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 3390560045236418590U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 3894024951542543635U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10599637790900418767U), 11U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterG, 51U);
            aIngress = aIngress + (RotL64(aOrbiterC, 4U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 37U));
            aIngress = aIngress + RotL64(aOrbiterD, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aScatter, 27U) + aOrbiterJ) + RotL64(aOrbiterH, 11U)) + RotL64(aCarry, 41U)) + aNonceWordC);
            aWandererB = aWandererB ^ (((RotL64(aCross, 41U) + aOrbiterH) + RotL64(aOrbiterF, 27U)) + aNonceWordK);
            aWandererD = aWandererD + ((RotL64(aPrevious, 50U) + aOrbiterH) + RotL64(aOrbiterI, 34U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 11U) + aOrbiterH) + RotL64(aOrbiterD, 43U)) + aPhaseAWandererUpdateSaltC[((aIndex + 16U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterG, 19U)) + aOrbiterI) + RotL64(aCarry, 53U)) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 21U) + aOrbiterG) + RotL64(aOrbiterC, 57U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 57U) + RotL64(aOrbiterF, 3U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererA);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 11U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + RotL64(aWandererB, 30U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ aNonceWordN;
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 32584U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29571U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28931U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30182U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 35U) ^ RotL64(aPrevious, 11U)) + (RotL64(aCarry, 48U) + RotL64(aIngress, 23U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterH = ((((aWandererC + RotL64(aScatter, 47U)) + RotL64(aCarry, 57U)) + 964165145848253292U) + aPhaseAOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1]) + aNonceWordM;
            aOrbiterA = ((aWandererB + RotL64(aIngress, 35U)) + RotL64(aCarry, 19U)) + 10645976767204934746U;
            aOrbiterG = (aWandererE + RotL64(aCross, 56U)) + 8241612229349212650U;
            aOrbiterK = (aWandererI + RotL64(aPrevious, 3U)) + 4159196033256913347U;
            aOrbiterD = (((aWandererJ + RotL64(aCross, 23U)) + RotL64(aCarry, 5U)) + 7194795864620233507U) + aPhaseAOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = (aWandererD + RotL64(aIngress, 11U)) + 7638928444536778384U;
            aOrbiterE = (aWandererG + RotL64(aScatter, 29U)) + 11819105916503968109U;
            //
            aOrbiterH = (((aOrbiterH + aOrbiterA) + 18052213302858186237U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordD;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 8663575313970041570U;
            aOrbiterG = RotL64((aOrbiterG * 14131073322476609161U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 16644136720439299786U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 16930316530442679864U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2650922074098320859U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 16251107616988250593U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 7171986193609401665U;
            aOrbiterB = RotL64((aOrbiterB * 3543709971414550087U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 17885046834432626644U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 7757069274715713557U;
            aOrbiterE = RotL64((aOrbiterE * 15766885299397923879U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 2212805322061155615U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 6368539134638838822U;
            aOrbiterH = RotL64((aOrbiterH * 13383744883433594259U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 5264326094252925613U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 6126345334815012938U;
            aOrbiterK = RotL64((aOrbiterK * 17180934809764905307U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 13826731214018407061U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 6621261811613643620U;
            aOrbiterA = RotL64((aOrbiterA * 2823596473596114171U), 27U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterE, 13U);
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 27U));
            aIngress = aIngress + RotL64(aOrbiterD, 20U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aIngress, 51U) + RotL64(aOrbiterG, 53U)) + aOrbiterK);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 13U) + aOrbiterG) + RotL64(aOrbiterE, 29U));
            aWandererG = aWandererG + (((RotL64(aCross, 57U) + RotL64(aOrbiterK, 47U)) + aOrbiterD) + RotL64(aCarry, 41U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 4U) + aOrbiterH) + RotL64(aOrbiterD, 21U)) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 37U) + aOrbiterA) + RotL64(aOrbiterD, 35U)) + RotL64(aCarry, 5U));
            aWandererD = aWandererD ^ ((((RotL64(aPrevious, 23U) + RotL64(aOrbiterB, 41U)) + aOrbiterG) + aNonceWordC) + aPhaseAWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aCross, 43U) + aOrbiterK) + RotL64(aOrbiterE, 12U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 29U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + RotL64(aWandererI, 22U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordG);
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

void TwistExpander_WaterPolo_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterE = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xA37B705ED53F0AEFULL + 0xEAA90F7B33C98C1CULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x8AAC0E0419F2F617ULL + 0xECB2713D103BFBA4ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xD5A265AD09B30BBFULL + 0xC730552A0CD95154ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x8A057693B3D28317ULL + 0xF028F38490747583ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x9F731F4AD3A5D0C7ULL + 0xECEA2A3F425A2AE2ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xE71AE43C7DDE211BULL + 0xE1D7BDCA6C30C8A4ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xE4068F17FC996F0BULL + 0xA93AA764EB6819E3ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x8BA2CF20A7136B81ULL + 0xD38B7AAD0B285187ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xD780EBF7B796DDBDULL + 0xA79E95F79467FAF6ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x8653538E05FC9BFFULL + 0xB345080C8A8D2C38ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xF562FA91A6BE3A93ULL + 0xFBFA60767C724692ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x9586B14340FEFEC9ULL + 0x977DEA0A048FC14CULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xDE9CF30F82F9B0DFULL + 0xEAE905F8435155B7ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xE06D86F8BDB276F7ULL + 0xCAFD47F2FC67E394ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xB3ED43274DF7D165ULL + 0xA4A82831365E7125ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xACA894186E898531ULL + 0xAE7B45838065FE8DULL);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 5288U)) & S_BLOCK1], 44U) ^ RotL64(aExpandLaneC[((aIndex + 1521U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 1095U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((aIndex + 124U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 27U) + RotL64(aCross, 41U)) ^ (RotL64(aCarry, 6U) ^ RotL64(aIngress, 53U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterC = ((aWandererI + RotL64(aIngress, 13U)) + 2168513956284366370U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = (((aWandererC + RotL64(aPrevious, 50U)) + RotL64(aCarry, 35U)) + 10290361969974613111U) + aNonceWordH;
            aOrbiterG = ((((aWandererA + RotL64(aScatter, 21U)) + RotL64(aCarry, 19U)) + 15673836275828498050U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordL;
            aOrbiterE = (aWandererD + RotL64(aCross, 37U)) + 16600540024145812236U;
            aOrbiterI = (((aWandererJ + RotL64(aIngress, 3U)) + RotL64(aCarry, 3U)) + 9428052101528111892U) + aNonceWordP;
            //
            aOrbiterC = (((aOrbiterC + aOrbiterJ) + 12763657928312763377U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordB;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 10751286982008662485U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6169084301655877217U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 1708230173038057979U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 4011389705422783816U;
            aOrbiterC = RotL64((aOrbiterC * 11692237130784795961U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 11704428328093077714U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 2055336619674699284U;
            aOrbiterE = RotL64((aOrbiterE * 6374289210096410907U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 1870865272102705804U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 3574214263751923179U;
            aOrbiterJ = RotL64((aOrbiterJ * 13132083406834413563U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 984611970726966186U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 15207945449947643672U;
            aOrbiterI = RotL64((aOrbiterI * 9539470161576639981U), 37U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterE, 13U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 40U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterC, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aCross, 24U) + aOrbiterG) + RotL64(aOrbiterI, 57U)) + RotL64(aCarry, 23U));
            aWandererJ = aWandererJ ^ ((((RotL64(aPrevious, 3U) + aOrbiterC) + RotL64(aOrbiterE, 20U)) + aNonceWordK) + aPhaseBWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aScatter, 13U) + RotL64(aOrbiterG, 11U)) + aOrbiterC);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterI, 35U)) + aOrbiterJ) + aNonceWordG);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterG, 43U)) + aOrbiterE) + RotL64(aCarry, 39U)) + aPhaseBWandererUpdateSaltE[((aIndex + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 56U));
            aCarry = aCarry + RotL64(aWandererJ, 47U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ aNonceWordM;
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10835U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 8844U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9865U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneB[((aIndex + 9467U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 35U) + RotL64(aPrevious, 3U)) ^ (RotL64(aIngress, 54U) ^ RotL64(aCross, 23U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterG = (((aWandererD + RotL64(aPrevious, 26U)) + RotL64(aCarry, 47U)) + 14214886793361825363U) + aNonceWordI;
            aOrbiterF = ((aWandererF + RotL64(aCross, 5U)) + 17267959031078766320U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterJ = (((aWandererK + RotL64(aScatter, 13U)) + RotL64(aCarry, 29U)) + 16436067429484887644U) + aNonceWordN;
            aOrbiterB = ((aWandererH + RotL64(aIngress, 51U)) + 9885951769332633820U) + aPhaseBOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = ((aWandererE + RotL64(aCross, 35U)) + RotL64(aCarry, 13U)) + 12971711341813893304U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 199970353398450154U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 1237341696444162094U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2850125642665515751U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 7991128854417613360U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 14809029847149045833U) ^ aNonceWordH;
            aOrbiterA = RotL64((aOrbiterA * 5940857360838299105U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 2559509556915775947U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 14336829730147834160U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15103242520064900873U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 8853631886733610440U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 13346159398673246914U;
            aOrbiterF = RotL64((aOrbiterF * 13660497151446983393U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 12121095718571872976U) + aNonceWordK;
            aOrbiterB = (((aOrbiterB ^ aOrbiterA) ^ 16239781125815589804U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterB = RotL64((aOrbiterB * 5157009090454962231U), 13U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterG, 19U);
            aIngress = aIngress + (RotL64(aOrbiterB, 39U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterA, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aScatter, 24U) + aOrbiterF) + RotL64(aOrbiterG, 11U)) + RotL64(aCarry, 19U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterB, 46U)) + aOrbiterF);
            aWandererD = aWandererD + ((((RotL64(aCross, 3U) + RotL64(aOrbiterJ, 57U)) + aOrbiterA) + aNonceWordP) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterF, 35U)) + aOrbiterJ) + aPhaseBWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 11U) + aOrbiterG) + RotL64(aOrbiterA, 21U)) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererF, 58U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordI);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 15746U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11850U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 14778U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneC[((aIndex + 16072U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 40U) ^ RotL64(aPrevious, 23U)) + (RotL64(aIngress, 11U) + RotL64(aCross, 53U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterH = (((aWandererJ + RotL64(aPrevious, 57U)) + RotL64(aCarry, 39U)) + 9446153639709651566U) + aNonceWordK;
            aOrbiterG = ((((aWandererI + RotL64(aCross, 3U)) + RotL64(aCarry, 51U)) + 10550762260670758167U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordN;
            aOrbiterA = (aWandererC + RotL64(aIngress, 43U)) + 7062634922142578383U;
            aOrbiterC = (((aWandererD + RotL64(aScatter, 34U)) + RotL64(aCarry, 27U)) + 9178499097812764515U) + aNonceWordI;
            aOrbiterI = ((aWandererE + RotL64(aIngress, 23U)) + 6887103379773525538U) + aPhaseBOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 6239750312052010257U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 17645022614523287959U;
            aOrbiterA = RotL64((aOrbiterA * 14448140327044053545U), 35U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterH) + 3639618183259408272U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 3131737117548745095U;
            aOrbiterG = RotL64((aOrbiterG * 6585057380704940395U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 7253994382396406554U) + aNonceWordC;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 15217993711938379561U;
            aOrbiterH = RotL64((aOrbiterH * 17853313384747259923U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 12594152227603630033U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 11250170200489647869U) ^ aNonceWordH;
            aOrbiterC = RotL64((aOrbiterC * 546800378327864723U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 12936942656624279424U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 10990736056052106149U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7123916809953459187U), 27U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterC, 37U);
            aIngress = aIngress + (RotL64(aOrbiterA, 13U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterH, 58U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aCross, 48U) + RotL64(aOrbiterI, 3U)) + aOrbiterA) + RotL64(aCarry, 53U));
            aWandererE = aWandererE ^ ((((RotL64(aPrevious, 57U) + aOrbiterA) + RotL64(aOrbiterC, 38U)) + aNonceWordF) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 27U) + RotL64(aOrbiterH, 47U)) + aOrbiterG) + RotL64(aCarry, 19U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 3U) + aOrbiterC) + RotL64(aOrbiterH, 19U)) + aPhaseBWandererUpdateSaltB[((aIndex + 22U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aScatter, 13U) + RotL64(aOrbiterC, 29U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + RotL64(aWandererJ, 39U);
            aCarry = aCarry + RotL64(aIngress, 14U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordO);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 21680U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21054U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20126U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16781U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCarry, 37U)) ^ (RotL64(aCross, 23U) + RotL64(aPrevious, 10U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 43U)) + RotL64(aCarry, 29U)) + 12980104182836602177U;
            aOrbiterE = ((((aWandererG + RotL64(aIngress, 5U)) + RotL64(aCarry, 11U)) + 3172622203188863995U) + aPhaseBOrbiterAssignSaltD[((aIndex + 6U)) & S_SALT1]) + aNonceWordH;
            aOrbiterH = ((aWandererE + RotL64(aScatter, 29U)) + 1170974132219980203U) + aNonceWordG;
            aOrbiterB = (((aWandererA + RotL64(aCross, 13U)) + RotL64(aCarry, 43U)) + 6035201940965047490U) + aNonceWordF;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 58U)) + 18033907118424996722U) + aPhaseBOrbiterAssignSaltB[((aIndex + 16U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 14604813424800580304U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 13720232492851066035U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8927246214721284759U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 3902659710585257448U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 8331560652661619868U;
            aOrbiterG = RotL64((aOrbiterG * 11418103770615560205U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 4485014147538689794U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 168202636924512424U;
            aOrbiterB = RotL64((aOrbiterB * 13711020666131492091U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 16227825670092707848U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 4792781933944671365U;
            aOrbiterE = RotL64((aOrbiterE * 15859849676231455283U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 12636865372722601282U) + aNonceWordA;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 18198291399585556632U;
            aOrbiterF = RotL64((aOrbiterF * 18155803890313399795U), 39U);
            //
            aIngress = RotL64(aOrbiterE, 30U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterG, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 60U) + aOrbiterH) + RotL64(aOrbiterE, 5U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterG, 37U)) + aOrbiterE) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterG, 51U)) + aPhaseBWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            aWandererA = aWandererA + (((((RotL64(aCross, 47U) + aOrbiterB) + RotL64(aOrbiterF, 29U)) + RotL64(aCarry, 39U)) + aNonceWordB) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterF, 18U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 58U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererI, 37U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ aNonceWordH;
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 24692U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneA[((aIndex + 25069U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24177U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((aIndex + 23176U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 19U) + RotL64(aCarry, 51U)) ^ (RotL64(aCross, 38U) ^ RotL64(aIngress, 5U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterJ = ((((aWandererD + RotL64(aPrevious, 56U)) + RotL64(aCarry, 3U)) + 8020711767807230555U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordG;
            aOrbiterA = (((aWandererC + RotL64(aCross, 35U)) + RotL64(aCarry, 51U)) + 15368693777246341570U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = ((aWandererI + RotL64(aIngress, 21U)) + RotL64(aCarry, 37U)) + 5117523734225562401U;
            aOrbiterG = ((aWandererG + RotL64(aScatter, 43U)) + 13155269151097507808U) + aNonceWordD;
            aOrbiterC = (aWandererF + RotL64(aCross, 3U)) + 9879303753623578272U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 1165799257173794826U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 930641942062732091U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 17151944851548731159U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 11330571332221123153U) + aNonceWordP;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 2862963158282518899U;
            aOrbiterC = RotL64((aOrbiterC * 13782195862525974199U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 6019186399361476659U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 1924419843785161958U;
            aOrbiterJ = RotL64((aOrbiterJ * 9485557122500346869U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 12618629043591380461U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 9334176504266512405U;
            aOrbiterA = RotL64((aOrbiterA * 18239109235362925739U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 16829692481030013551U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 5604784396927022709U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2833893610883508353U), 3U);
            //
            aIngress = RotL64(aOrbiterG, 22U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 37U));
            aIngress = aIngress + RotL64(aOrbiterJ, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((((RotL64(aCross, 47U) + aOrbiterJ) + RotL64(aOrbiterA, 39U)) + RotL64(aCarry, 47U)) + aNonceWordJ) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 38U) + aOrbiterC) + RotL64(aOrbiterJ, 21U)) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 21U) + aOrbiterC) + RotL64(aOrbiterA, 58U)) + RotL64(aCarry, 11U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 5U) + aOrbiterH) + RotL64(aOrbiterG, 3U));
            aWandererF = aWandererF + ((RotL64(aIngress, 13U) + RotL64(aOrbiterC, 11U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererI, 19U);
            aCarry = aCarry + RotL64(aIngress, 48U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordA);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 30015U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneB[((aIndex + 30488U)) & S_BLOCK1], 44U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 31700U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28537U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 52U) ^ RotL64(aCarry, 35U)) ^ (RotL64(aCross, 23U) + RotL64(aPrevious, 3U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterB = (aWandererK + RotL64(aPrevious, 43U)) + 5576732410244514238U;
            aOrbiterE = ((((aWandererF + RotL64(aIngress, 13U)) + RotL64(aCarry, 39U)) + 2833808925935929629U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordH;
            aOrbiterH = (aWandererJ + RotL64(aCross, 24U)) + 3670188682914544792U;
            aOrbiterI = (((aWandererH + RotL64(aScatter, 53U)) + RotL64(aCarry, 53U)) + 15759072378887814995U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 5U)) + RotL64(aCarry, 5U)) + 13934007231137439994U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 11022225696007690512U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 16989177104453635790U;
            aOrbiterH = RotL64((aOrbiterH * 14156758251105809453U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 9256930045263527091U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 17788596104417068290U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 675554110563253305U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 17044369456673337625U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterK) ^ 1310908395523250343U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterB = RotL64((aOrbiterB * 16305084373037705921U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 12067065689034065422U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 15130844248737512262U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9409499577465934107U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 14532689204495587494U) + aNonceWordB;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 8198147292120244178U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1418356389507740991U), 39U);
            //
            aIngress = RotL64(aOrbiterE, 3U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 37U));
            aIngress = aIngress + RotL64(aOrbiterH, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 26U) + RotL64(aOrbiterK, 47U)) + aOrbiterB);
            aWandererF = aWandererF + (((((RotL64(aIngress, 13U) + RotL64(aOrbiterE, 58U)) + aOrbiterK) + RotL64(aCarry, 19U)) + aNonceWordI) + aPhaseBWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterB, 5U)) + aOrbiterH);
            aWandererK = aWandererK + ((((RotL64(aScatter, 43U) + aOrbiterE) + RotL64(aOrbiterB, 35U)) + RotL64(aCarry, 47U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterI, 13U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererF, 36U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererH, 3U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ aNonceWordP;
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

void TwistExpander_WaterPolo_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xC975E46B043C92EDULL + 0xD7EFC18F36BD5F9FULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x98FA6EB02A03AFA1ULL + 0x944D72C297199F8AULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xEEA5F2F655964D11ULL + 0xFF429D6AC76E9C28ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xCBB9682CD9CFFD01ULL + 0x91FF10F6F7109E3FULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xB513E691CF876351ULL + 0xC88E67642B53BB53ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xAE73072A55F3F163ULL + 0xE906D98AAD550488ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xCF9EF2D875AF8731ULL + 0xE4218266A93E0AE0ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xD594E40410EDE201ULL + 0x87EEA655DD1C6E60ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xD5E484CAF9DDD9EBULL + 0xEF03E74429F2906FULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xC430F0C69E2E0C9BULL + 0xDE8542A5B6C9A255ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x80858B5255C6E15DULL + 0x810FBDA2F109836BULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xBE8B334ABAC66879ULL + 0xB6C088C6219AD9B6ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xC8B17E860C9C764FULL + 0xEED953938375B3B4ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xCB4A694AEF764307ULL + 0x895F251568AE979DULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xA4A4B949D1B3C3FBULL + 0xACB9946806E9B427ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xCB2E6F17FD5C3A5BULL + 0xF71E8405443DE1CEULL);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 7815U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneC[((aIndex + 5947U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 5152U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 7469U)) & S_BLOCK1], 28U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 44U) + RotL64(aIngress, 27U)) + (RotL64(aPrevious, 57U) ^ RotL64(aCross, 13U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterD = ((aWandererJ + RotL64(aCross, 52U)) + 15813325389431304548U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = ((aWandererK + RotL64(aIngress, 57U)) + 2223874171125403602U) + aNonceWordI;
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 11U)) + RotL64(aCarry, 19U)) + 5510483568496824130U;
            aOrbiterB = ((aWandererG + RotL64(aScatter, 43U)) + RotL64(aCarry, 37U)) + 15474152493495661876U;
            aOrbiterK = (aWandererD + RotL64(aCross, 18U)) + 16846339705130829195U;
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 5U)) + 1289670576865739669U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = ((aWandererE + RotL64(aIngress, 37U)) + RotL64(aCarry, 53U)) + 18017354919647006944U;
            aOrbiterI = ((aWandererI + RotL64(aScatter, 27U)) + 8539685539928984921U) + aNonceWordH;
            aOrbiterC = ((aWandererA + RotL64(aIngress, 23U)) + 3333721400836704048U) + aNonceWordM;
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 2261560416623815491U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 4377786131746816567U;
            aOrbiterG = RotL64((aOrbiterG * 9164777834392621157U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 18047393176583722719U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 8184724021940434631U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9800116157750921119U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 10469895939183324807U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 14543391765109879223U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4817987697437667225U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 5757225781746158178U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 3539000495894022869U) ^ aNonceWordP;
            aOrbiterC = RotL64((aOrbiterC * 1032298408884695925U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 11288971092707065923U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 2761384065186568294U;
            aOrbiterD = RotL64((aOrbiterD * 3323838837427471051U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 7120580145300417101U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 6977246291769372866U;
            aOrbiterB = RotL64((aOrbiterB * 15170353875184253779U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 17625434527765525937U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 3299714663631376190U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6532628892760776767U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 10331889953489885250U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 8550932256881727932U;
            aOrbiterE = RotL64((aOrbiterE * 13085531621192583719U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 11151195711186126257U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 2552002192824926483U;
            aOrbiterK = RotL64((aOrbiterK * 9754056316698523849U), 51U);
            //
            aIngress = RotL64(aOrbiterK, 57U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterI, 18U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterA, 47U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterE, 43U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterB, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aScatter, 50U) + aOrbiterA) + RotL64(aOrbiterE, 19U)) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 43U) + aOrbiterI) + RotL64(aOrbiterD, 5U)) + aNonceWordL) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterC, 23U)) + aOrbiterE);
            aWandererK = aWandererK + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterA, 28U)) + aOrbiterD) + RotL64(aCarry, 19U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 39U) + aOrbiterE) + RotL64(aOrbiterK, 43U));
            aWandererA = aWandererA + ((((RotL64(aIngress, 54U) + RotL64(aOrbiterG, 11U)) + aOrbiterA) + RotL64(aCarry, 57U)) + aNonceWordB);
            aWandererB = aWandererB ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterE, 53U)) + aOrbiterH);
            aWandererE = aWandererE + ((RotL64(aPrevious, 3U) + aOrbiterB) + RotL64(aOrbiterA, 37U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterD, 48U)) + aOrbiterG) + aNonceWordF);
            //
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 53U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 56U));
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererD, 27U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ aNonceWordG;
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 11542U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneD[((aIndex + 12726U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 9417U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 13885U)) & S_BLOCK1], 46U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 19U) ^ RotL64(aIngress, 35U)) ^ (RotL64(aPrevious, 50U) + RotL64(aCross, 3U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterF = (aWandererG + RotL64(aScatter, 14U)) + 11450949896247900941U;
            aOrbiterD = (((aWandererA + RotL64(aIngress, 43U)) + RotL64(aCarry, 57U)) + 3905542253538116335U) + aNonceWordH;
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 5U)) + RotL64(aCarry, 37U)) + 9529740545977785305U;
            aOrbiterK = (aWandererK + RotL64(aCross, 53U)) + 1856876631533143492U;
            aOrbiterJ = (((aWandererC + RotL64(aPrevious, 47U)) + 84253466320181686U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterC = (aWandererJ + RotL64(aCross, 27U)) + 12577480918745432444U;
            aOrbiterB = (aWandererH + RotL64(aIngress, 57U)) + 5625703170397704029U;
            aOrbiterA = ((aWandererI + RotL64(aScatter, 37U)) + RotL64(aCarry, 19U)) + 694608607323629282U;
            aOrbiterE = ((aWandererD + RotL64(aCross, 20U)) + 3993981243536262204U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 4119215953484892051U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 8785040118556157146U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17113521266125471625U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 16234403619456882890U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 10398727475672860610U;
            aOrbiterJ = RotL64((aOrbiterJ * 5086871400049644715U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 18327987141759096769U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 2645964788056875452U;
            aOrbiterB = RotL64((aOrbiterB * 8778681366114628045U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 2859452497983106129U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 7196557924940881076U;
            aOrbiterA = RotL64((aOrbiterA * 14415389907490256711U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 930127943984174668U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 15673596916054795749U;
            aOrbiterE = RotL64((aOrbiterE * 7505660488733199479U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 16673140529110941163U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 2258448294877833760U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1821550319748977445U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 6870209259643931219U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 12749790107942194104U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4871407285968611725U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 17131374134617173866U) + aNonceWordI;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 6426448390733751612U;
            aOrbiterC = RotL64((aOrbiterC * 12490559588384058417U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 15592826434339731146U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 14182944418026376183U;
            aOrbiterD = RotL64((aOrbiterD * 7218860482893476233U), 5U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterA, 23U);
            aIngress = aIngress + (RotL64(aOrbiterG, 48U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 51U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 35U));
            aIngress = aIngress + RotL64(aOrbiterF, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aIngress, 19U) + RotL64(aOrbiterF, 26U)) + aOrbiterB) + aNonceWordG) + aPhaseCWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 6U) + RotL64(aOrbiterE, 13U)) + aOrbiterG);
            aWandererB = aWandererB + ((RotL64(aScatter, 53U) + aOrbiterD) + RotL64(aOrbiterF, 35U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 23U) + aOrbiterE) + RotL64(aOrbiterK, 47U)) + aNonceWordD);
            aWandererK = aWandererK + (((RotL64(aScatter, 43U) + aOrbiterC) + RotL64(aOrbiterG, 41U)) + RotL64(aCarry, 39U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterE, 51U)) + aOrbiterJ);
            aWandererH = aWandererH + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterD, 4U)) + aOrbiterB) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 14U) + aOrbiterG) + RotL64(aOrbiterA, 57U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 37U) + RotL64(aOrbiterA, 21U)) + aOrbiterF) + aNonceWordA) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 19U));
            aCarry = aCarry + (RotL64(aWandererD, 60U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererB, 51U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordB);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 19644U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21939U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 21478U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 23865U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 39U) + RotL64(aCarry, 19U)) ^ (RotL64(aPrevious, 54U) + RotL64(aCross, 3U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterJ = (aWandererD + RotL64(aCross, 43U)) + 6069475454765660321U;
            aOrbiterI = ((aWandererC + RotL64(aScatter, 22U)) + RotL64(aCarry, 53U)) + 11483704742497268068U;
            aOrbiterA = (((aWandererJ + RotL64(aPrevious, 39U)) + RotL64(aCarry, 11U)) + 11055697447388986418U) + aNonceWordO;
            aOrbiterE = ((aWandererE + RotL64(aIngress, 47U)) + RotL64(aCarry, 3U)) + 10897095046039997004U;
            aOrbiterB = ((aWandererG + RotL64(aCross, 35U)) + 4731637118230457840U) + aNonceWordL;
            aOrbiterC = (aWandererB + RotL64(aScatter, 57U)) + 13855839187084986751U;
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 12U)) + 5328208115460188239U) + aPhaseCOrbiterAssignSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = (aWandererH + RotL64(aIngress, 51U)) + 12479538544291412985U;
            aOrbiterF = ((aWandererA + RotL64(aCross, 3U)) + 10740165998792608231U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 6492798157284955373U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 13056825957483891921U;
            aOrbiterA = RotL64((aOrbiterA * 14882112110627751751U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 2068184064919194657U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 5656302738780746294U;
            aOrbiterJ = RotL64((aOrbiterJ * 16493021179127646345U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 11193756120230763294U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 17306750816837208999U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7949360041241439741U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 12952818800389361804U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 15380412293642628312U) ^ aNonceWordC;
            aOrbiterI = RotL64((aOrbiterI * 2914662289178925547U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 7706090204767242996U) + aNonceWordN;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 14598802276412649570U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4821408736292041399U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 17819762117328075515U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 6481384240915075101U;
            aOrbiterC = RotL64((aOrbiterC * 4836701121865783029U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 754936290510338717U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 15510875946573720154U;
            aOrbiterH = RotL64((aOrbiterH * 2994718968852184303U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 9245381722813944586U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 2629847912019726214U;
            aOrbiterD = RotL64((aOrbiterD * 6718795794951106961U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 3909987749797113773U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 9277056074757335265U;
            aOrbiterF = RotL64((aOrbiterF * 11580847505996697115U), 19U);
            //
            aIngress = RotL64(aOrbiterE, 34U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 47U));
            aIngress = aIngress + (RotL64(aOrbiterA, 13U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterI, 27U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterC, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aPrevious, 51U) + aOrbiterE) + RotL64(aOrbiterA, 60U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterJ, 23U)) + aOrbiterE) + aNonceWordA);
            aWandererC = aWandererC + (((RotL64(aIngress, 35U) + aOrbiterC) + RotL64(aOrbiterD, 19U)) + RotL64(aCarry, 23U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 4U) + aOrbiterD) + RotL64(aOrbiterJ, 47U)) + aPhaseCWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 21U) + RotL64(aOrbiterI, 6U)) + aOrbiterJ) + RotL64(aCarry, 51U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterF, 51U)) + aOrbiterH);
            aWandererA = aWandererA + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterA, 11U)) + aOrbiterJ);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterB, 35U)) + aOrbiterH);
            aWandererG = aWandererG + (((RotL64(aPrevious, 12U) + RotL64(aOrbiterI, 41U)) + aOrbiterH) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 38U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererC, 41U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererG, 51U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ aNonceWordG;
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 26892U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32171U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 30366U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 24637U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 51U) + RotL64(aCross, 13U)) ^ (RotL64(aCarry, 26U) + RotL64(aIngress, 39U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterA = ((aWandererE + RotL64(aCross, 3U)) + RotL64(aCarry, 27U)) + 4259993311776766595U;
            aOrbiterI = (((aWandererG + RotL64(aPrevious, 30U)) + RotL64(aCarry, 47U)) + 2857813330021126753U) + aNonceWordM;
            aOrbiterB = ((aWandererK + RotL64(aScatter, 43U)) + RotL64(aCarry, 57U)) + 1345396841329442896U;
            aOrbiterF = (aWandererA + RotL64(aIngress, 51U)) + 320992148982301024U;
            aOrbiterC = (aWandererD + RotL64(aScatter, 47U)) + 5619109532065293074U;
            aOrbiterD = (((aWandererF + RotL64(aCross, 37U)) + 10380157329426706345U) + aPhaseCOrbiterAssignSaltD[((aIndex + 14U)) & S_SALT1]) + aNonceWordG;
            aOrbiterH = (aWandererC + RotL64(aIngress, 21U)) + 12449831150625409695U;
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 57U)) + 7847096607042268396U;
            aOrbiterG = ((aWandererI + RotL64(aIngress, 12U)) + 11707184096803214678U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 9893643746186827088U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 333687403830908774U) ^ aNonceWordK;
            aOrbiterB = RotL64((aOrbiterB * 17911256836121454271U), 37U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 13837360705077441580U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 4367119682175710689U;
            aOrbiterC = RotL64((aOrbiterC * 10295744669174603401U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 1193493435041306784U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 15062951612027370606U;
            aOrbiterH = RotL64((aOrbiterH * 2509383510565136549U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 16000173839235429105U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 15294482444605409961U;
            aOrbiterA = RotL64((aOrbiterA * 1031800997944302665U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 5720749055549773527U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 17248674962996093668U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15730637462755795591U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 16956840483882091059U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterI) ^ 9637715107943515594U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterD = RotL64((aOrbiterD * 8878362378343603463U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 7147495779349862274U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 7508890985889484275U;
            aOrbiterJ = RotL64((aOrbiterJ * 17728368447504622035U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 4407738164617959366U) + aNonceWordD;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 17027017782352660454U;
            aOrbiterG = RotL64((aOrbiterG * 417183060881259295U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 3174658601748235285U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 9779053567370714831U;
            aOrbiterI = RotL64((aOrbiterI * 6383245776181968033U), 27U);
            //
            aIngress = RotL64(aOrbiterG, 19U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 34U));
            aIngress = aIngress + (RotL64(aOrbiterF, 29U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + RotL64(aOrbiterD, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aIngress, 19U) + aOrbiterD) + RotL64(aOrbiterF, 34U)) + aNonceWordH);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 52U) + RotL64(aOrbiterB, 5U)) + aOrbiterF);
            aWandererE = aWandererE + ((RotL64(aCross, 23U) + RotL64(aOrbiterA, 57U)) + aOrbiterD);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 39U) + aOrbiterH) + RotL64(aOrbiterG, 51U)) + aPhaseCWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aScatter, 27U) + aOrbiterC) + RotL64(aOrbiterJ, 27U)) + RotL64(aCarry, 29U)) + aNonceWordJ);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterA, 11U)) + aOrbiterJ);
            aWandererK = aWandererK + (((RotL64(aIngress, 47U) + aOrbiterI) + RotL64(aOrbiterG, 38U)) + aNonceWordF);
            aWandererI = aWandererI ^ ((RotL64(aCross, 58U) + RotL64(aOrbiterD, 43U)) + aOrbiterC);
            aWandererG = aWandererG + ((((RotL64(aIngress, 35U) + aOrbiterI) + RotL64(aOrbiterA, 21U)) + RotL64(aCarry, 19U)) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + RotL64(aWandererK, 6U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordD);
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

void TwistExpander_WaterPolo_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xE6F94E891795B013ULL + 0xFA1F67D3C59388C8ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x91DABCF9402E6FE9ULL + 0xAAB21CC0F6D38308ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xF73389C720566ADBULL + 0x9117A3370C04F3EBULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xE740905F41C257CBULL + 0xB07266943C84820BULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xAFB95CFDE139D883ULL + 0xDBE99EC83980352BULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x8BD60C7379603A65ULL + 0xE947EBA11B1F739CULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x8272A6C9370A2EF9ULL + 0xF5BE53D798B7FB62ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xF08C02B94D8D82D7ULL + 0xAB0D85C42AD0AC15ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x8D1859F7CC53CCE5ULL + 0xC79B9CCC6068CFAEULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xB96604DB3B3A0413ULL + 0xE4E65B5AE8C963CCULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xA29ECE51AD9ED0C5ULL + 0xE7DACE42B56A9C89ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x86F824B42D6A98C9ULL + 0xF9943ECA152FA58AULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xCA91285C638CE793ULL + 0xC5708D1668FA45DDULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x9E6CB7359B9859A9ULL + 0xBF3C1AA7F95A7520ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xEF495A9EE9D5D883ULL + 0xA0404DAB5D3A8B3AULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xE7BE4939C184187DULL + 0x86A7AAC71009EDF1ULL);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 596U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneC[((aIndex + 5399U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 1571U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneA[((aIndex + 1195U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 28U) + RotL64(aCross, 53U)) + (RotL64(aCarry, 41U) ^ RotL64(aIngress, 5U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterF = (aWandererB + RotL64(aCross, 27U)) + 7722279280863371124U;
            aOrbiterC = (aWandererK + RotL64(aScatter, 11U)) + 11584220561732385598U;
            aOrbiterJ = (((aWandererC + RotL64(aPrevious, 5U)) + RotL64(aCarry, 3U)) + 7834679350105534657U) + aNonceWordD;
            aOrbiterI = ((aWandererF + RotL64(aIngress, 19U)) + RotL64(aCarry, 47U)) + 11347994382444180879U;
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 56U)) + 9449903188047063431U) + aNonceWordF;
            aOrbiterD = (aWandererD + RotL64(aCross, 3U)) + 6516243976652795170U;
            aOrbiterK = (aWandererA + RotL64(aIngress, 43U)) + 8420815253991184777U;
            aOrbiterH = (aWandererG + RotL64(aScatter, 47U)) + 9081386852515170937U;
            aOrbiterB = (aWandererE + RotL64(aPrevious, 58U)) + 14375955191735286867U;
            aOrbiterG = (((aWandererJ + RotL64(aCross, 39U)) + RotL64(aCarry, 13U)) + 880757589768436072U) + aPhaseDOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = ((aWandererI + RotL64(aScatter, 13U)) + 3349856625725164229U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 7826309957607577207U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 8057435761214313635U) ^ aNonceWordP;
            aOrbiterJ = RotL64((aOrbiterJ * 4718430712767038607U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 9565237500443303103U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 15893066735310588501U;
            aOrbiterD = RotL64((aOrbiterD * 8457633439171452397U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 3276844534476430842U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 6828644383891274120U;
            aOrbiterF = RotL64((aOrbiterF * 979580351653410157U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 2815676923011504251U) + aNonceWordM;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 5030251870850928417U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7075653570570819253U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 13464083008377887034U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 8994560761846897590U;
            aOrbiterK = RotL64((aOrbiterK * 9892839554658865143U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 8398813387154468736U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 8136429428340910892U;
            aOrbiterB = RotL64((aOrbiterB * 3348811490733577295U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 418587250696862341U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 4111667833838312094U;
            aOrbiterA = RotL64((aOrbiterA * 860949442143849147U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 6075478294190926371U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 2208124955874142264U;
            aOrbiterC = RotL64((aOrbiterC * 15741988616251072075U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 4726538724576443010U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 6524078248882840425U;
            aOrbiterE = RotL64((aOrbiterE * 9784875566721689069U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 14521003220464811621U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 16916247868211621303U;
            aOrbiterH = RotL64((aOrbiterH * 1911638054294853877U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 18207293125461843123U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 7722279280863371124U;
            aOrbiterG = RotL64((aOrbiterG * 14303108475807941791U), 53U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterE, 3U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 6U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterD, 27U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 35U));
            aIngress = aIngress + (RotL64(aOrbiterI, 23U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterG, 18U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aScatter, 56U) + aOrbiterH) + RotL64(aOrbiterI, 5U)) + RotL64(aCarry, 37U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterE, 51U)) + aOrbiterA);
            aWandererE = aWandererE + ((RotL64(aPrevious, 37U) + aOrbiterC) + RotL64(aOrbiterE, 14U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterI, 43U)) + aOrbiterJ);
            aWandererI = aWandererI + ((((RotL64(aCross, 41U) + RotL64(aOrbiterK, 35U)) + aOrbiterJ) + RotL64(aCarry, 47U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 47U) + aOrbiterF) + RotL64(aOrbiterG, 37U)) + aNonceWordH);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 18U) + aOrbiterE) + RotL64(aOrbiterD, 57U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterA, 27U)) + aOrbiterB);
            aWandererF = aWandererF + (((RotL64(aScatter, 43U) + aOrbiterB) + RotL64(aOrbiterE, 11U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 5U) + aOrbiterI) + RotL64(aOrbiterE, 3U));
            aWandererC = aWandererC + ((RotL64(aIngress, 21U) + aOrbiterG) + RotL64(aOrbiterE, 30U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (RotL64(aWandererD, 37U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererH, 22U) ^ aWandererB);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + RotL64(aWandererC, 57U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 7039U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 8414U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 6330U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 10193U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCross, 19U)) + (RotL64(aPrevious, 41U) + RotL64(aCarry, 6U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterC = (aWandererH + RotL64(aCross, 19U)) + 12311607308490066301U;
            aOrbiterD = (aWandererD + RotL64(aScatter, 43U)) + 13100864684740679846U;
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 14U)) + 13697304189274329704U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = (aWandererB + RotL64(aIngress, 41U)) + 9047976902871216732U;
            aOrbiterG = (aWandererI + RotL64(aCross, 5U)) + 2147897579538537888U;
            aOrbiterF = (aWandererK + RotL64(aScatter, 23U)) + 2072444829390996142U;
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 51U)) + RotL64(aCarry, 29U)) + 2129307836981020908U;
            aOrbiterB = (((aWandererE + RotL64(aPrevious, 37U)) + RotL64(aCarry, 13U)) + 10663145333751112064U) + aNonceWordM;
            aOrbiterJ = (((aWandererF + RotL64(aScatter, 35U)) + RotL64(aCarry, 39U)) + 15019844390503785459U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = ((aWandererC + RotL64(aIngress, 29U)) + 5460865577557928142U) + aNonceWordG;
            aOrbiterK = (aWandererG + RotL64(aCross, 58U)) + 15806522559993224197U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 6361113778657833389U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 8306013884615042570U;
            aOrbiterA = RotL64((aOrbiterA * 8234258702656728667U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 4038420580499706912U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 11908091484457158973U;
            aOrbiterD = RotL64((aOrbiterD * 3964111175645156719U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 11133912466611921250U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 2469227904206936928U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2704438771198001599U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 13234017916788297295U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 9061117693840451988U;
            aOrbiterE = RotL64((aOrbiterE * 3637440416741459419U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 12013423690843812324U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 14371779015144617412U) ^ aNonceWordP;
            aOrbiterJ = RotL64((aOrbiterJ * 3359568073302062667U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 10044883414565441442U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 14334898081890462218U;
            aOrbiterC = RotL64((aOrbiterC * 4878939077928220019U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 13788962593988366125U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 8377887372059713516U;
            aOrbiterH = RotL64((aOrbiterH * 1925913354197206851U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 4584439257847749371U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 13335592911357756498U;
            aOrbiterF = RotL64((aOrbiterF * 6515028218115896375U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 11166747459333977215U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 2368465601636093120U;
            aOrbiterB = RotL64((aOrbiterB * 1929974840976648333U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 4538402006569031063U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 3397601475441212067U;
            aOrbiterI = RotL64((aOrbiterI * 12043369327112500565U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 4804403185062062524U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 12311607308490066301U;
            aOrbiterK = RotL64((aOrbiterK * 10281231071618984185U), 13U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterC, 41U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 53U));
            aIngress = aIngress + (RotL64(aOrbiterE, 38U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterB, 27U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterG, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 11U) + aOrbiterJ) + RotL64(aOrbiterA, 47U));
            aWandererC = aWandererC + (((RotL64(aIngress, 37U) + aOrbiterF) + RotL64(aOrbiterD, 51U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 60U) + RotL64(aOrbiterA, 6U)) + aOrbiterE);
            aWandererB = aWandererB + ((((RotL64(aCross, 57U) + aOrbiterH) + RotL64(aOrbiterB, 53U)) + aNonceWordK) + aPhaseDWandererUpdateSaltA[((aIndex + 26U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 5U) + aOrbiterE) + RotL64(aOrbiterI, 21U));
            aWandererH = aWandererH + (((RotL64(aIngress, 39U) + aOrbiterB) + RotL64(aOrbiterG, 3U)) + RotL64(aCarry, 3U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 18U) + aOrbiterF) + RotL64(aOrbiterI, 19U));
            aWandererD = aWandererD + (((RotL64(aCross, 35U) + aOrbiterK) + RotL64(aOrbiterF, 34U)) + RotL64(aCarry, 53U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 3U) + aOrbiterK) + RotL64(aOrbiterH, 43U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 23U) + aOrbiterG) + RotL64(aOrbiterC, 37U)) + aNonceWordI);
            aWandererI = aWandererI ^ ((RotL64(aCross, 43U) + aOrbiterC) + RotL64(aOrbiterD, 13U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 50U));
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererD);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 39U));
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererK, 54U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordN);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 12635U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneA[((aIndex + 11136U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 12256U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneC[((aIndex + 14743U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aPrevious, 40U)) ^ (RotL64(aIngress, 21U) ^ RotL64(aCarry, 5U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterH = ((aWandererE + RotL64(aCross, 4U)) + RotL64(aCarry, 35U)) + 12262991801139086177U;
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 21U)) + 7963038771924890197U) + aNonceWordC;
            aOrbiterD = (aWandererI + RotL64(aScatter, 51U)) + 15540520327933568896U;
            aOrbiterE = ((aWandererA + RotL64(aIngress, 13U)) + RotL64(aCarry, 47U)) + 8745565892055020722U;
            aOrbiterC = ((aWandererG + RotL64(aPrevious, 43U)) + 16619329199683755286U) + aPhaseDOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = (aWandererK + RotL64(aScatter, 35U)) + 10865705026433867260U;
            aOrbiterG = (aWandererB + RotL64(aIngress, 41U)) + 2743368697984518059U;
            aOrbiterI = (aWandererH + RotL64(aCross, 11U)) + 5556006271515473135U;
            aOrbiterK = (((aWandererC + RotL64(aScatter, 19U)) + RotL64(aCarry, 57U)) + 5355833281353498588U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = (aWandererJ + RotL64(aIngress, 46U)) + 8313616108963479829U;
            aOrbiterB = (aWandererF + RotL64(aCross, 29U)) + 16657121016801866434U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 16532226425013000833U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 5800465874932467232U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5966395771690704577U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 17882948163883121328U) + aNonceWordI;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 15029375310296563175U;
            aOrbiterJ = RotL64((aOrbiterJ * 17021415832288477713U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 10170682648007918739U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 11829089574189398773U;
            aOrbiterF = RotL64((aOrbiterF * 15755874363488568849U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 1746524867389196322U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 10217423427886742775U;
            aOrbiterC = RotL64((aOrbiterC * 9166162099575333519U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 1338457710729082656U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 1319981417675542556U;
            aOrbiterI = RotL64((aOrbiterI * 9518448254565489715U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 3985281993069194761U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 7281264481139915593U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13498446162967276739U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 17394503335338855566U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 1430703546991948227U;
            aOrbiterH = RotL64((aOrbiterH * 1623206122475721175U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 472559435062214929U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 8065899137826178995U) ^ aNonceWordF;
            aOrbiterE = RotL64((aOrbiterE * 13287499768933229539U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 3377996409668333322U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 10456089146891981998U;
            aOrbiterG = RotL64((aOrbiterG * 12037044781049717633U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 5246784368779537905U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 8518987022368391332U) ^ aNonceWordM;
            aOrbiterK = RotL64((aOrbiterK * 4046763804695058779U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 7791883487780325967U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 12262991801139086177U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3409890579914160747U), 53U);
            //
            aIngress = RotL64(aOrbiterE, 13U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 39U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + (RotL64(aOrbiterC, 23U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 19U));
            aIngress = aIngress + RotL64(aOrbiterF, 48U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((((RotL64(aScatter, 39U) + aOrbiterB) + RotL64(aOrbiterC, 6U)) + aNonceWordL) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aCross, 60U) + aOrbiterE) + RotL64(aOrbiterJ, 47U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 19U) + aOrbiterC) + RotL64(aOrbiterG, 11U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 27U) + aOrbiterJ) + RotL64(aOrbiterA, 21U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterA, 3U)) + aOrbiterI);
            aWandererB = aWandererB + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterH, 40U)) + aOrbiterK) + aNonceWordO);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterJ, 51U)) + aOrbiterF);
            aWandererI = aWandererI + ((((RotL64(aScatter, 30U) + RotL64(aOrbiterH, 37U)) + aOrbiterA) + RotL64(aCarry, 51U)) + aPhaseDWandererUpdateSaltF[((aIndex + 24U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterG, 23U)) + aOrbiterD);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterG, 29U)) + aOrbiterI) + RotL64(aCarry, 23U)) + aNonceWordA);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 57U) + aOrbiterF) + RotL64(aOrbiterH, 35U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 50U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 41U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 21U));
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererJ);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 52U));
            aCarry = aCarry + RotL64(aWandererH, 35U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ aNonceWordN;
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 18281U)) & S_BLOCK1], 20U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 20445U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 19106U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17823U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 37U) ^ RotL64(aCarry, 19U)) + (RotL64(aCross, 6U) ^ RotL64(aPrevious, 57U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterK = ((aWandererI + RotL64(aScatter, 11U)) + 9914837590440975587U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = (((aWandererA + RotL64(aPrevious, 35U)) + RotL64(aCarry, 43U)) + 6706125076401958051U) + aPhaseDOrbiterAssignSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterD = (aWandererB + RotL64(aIngress, 21U)) + 16570817772679258409U;
            aOrbiterJ = (aWandererC + RotL64(aCross, 19U)) + 6843705658115186948U;
            aOrbiterE = (((aWandererG + RotL64(aIngress, 47U)) + RotL64(aCarry, 37U)) + 16099930446791572351U) + aNonceWordD;
            aOrbiterI = (aWandererF + RotL64(aScatter, 58U)) + 5420550009556030459U;
            aOrbiterG = (aWandererD + RotL64(aPrevious, 3U)) + 5729549069420177477U;
            aOrbiterA = (aWandererJ + RotL64(aCross, 5U)) + 15590601126188675834U;
            aOrbiterB = ((aWandererE + RotL64(aScatter, 13U)) + RotL64(aCarry, 21U)) + 13044027390998620029U;
            aOrbiterF = (aWandererK + RotL64(aIngress, 50U)) + 11068338135659636772U;
            aOrbiterC = (aWandererH + RotL64(aPrevious, 37U)) + 6584988841809544332U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 8516813219883915404U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterK) ^ 10647314042912492785U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterD = RotL64((aOrbiterD * 15559481057047148785U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 201691689889605304U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 15512161798401184003U;
            aOrbiterE = RotL64((aOrbiterE * 11473219183982564709U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 3883760518944464145U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 13861805129175491145U;
            aOrbiterI = RotL64((aOrbiterI * 17194438894492581181U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 12019138626550801486U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 13030350224959652248U;
            aOrbiterG = RotL64((aOrbiterG * 11724200983306280107U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 2643807255422544248U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 4127143302485631794U;
            aOrbiterA = RotL64((aOrbiterA * 5441038881111578487U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 14602951930809633069U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 4555737199162278494U;
            aOrbiterB = RotL64((aOrbiterB * 12415825635220991865U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 6343143902997169834U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 10404783711336491985U;
            aOrbiterF = RotL64((aOrbiterF * 6235474458879439079U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 7406959231434835393U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 6684368109277850196U;
            aOrbiterC = RotL64((aOrbiterC * 8760360417572331159U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 4835889355927954728U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 7917682889852676712U;
            aOrbiterK = RotL64((aOrbiterK * 9045350756570117327U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 10268055422944417055U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 5563744562922937643U;
            aOrbiterH = RotL64((aOrbiterH * 12442484191329795173U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 17244672945880141679U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 9914837590440975587U;
            aOrbiterJ = RotL64((aOrbiterJ * 12269340309792850489U), 13U);
            //
            aIngress = RotL64(aOrbiterG, 47U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterF, 10U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterA, 5U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterD, 13U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterH, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 50U) + aOrbiterG) + RotL64(aOrbiterF, 53U));
            aWandererA = aWandererA + (((RotL64(aCross, 3U) + RotL64(aOrbiterK, 23U)) + aOrbiterE) + RotL64(aCarry, 29U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterI, 56U)) + aOrbiterJ);
            aWandererD = aWandererD + ((RotL64(aScatter, 37U) + aOrbiterH) + RotL64(aOrbiterG, 11U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 53U) + aOrbiterA) + RotL64(aOrbiterC, 3U));
            aWandererB = aWandererB + ((RotL64(aIngress, 13U) + RotL64(aOrbiterI, 35U)) + aOrbiterB);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 27U) + aOrbiterE) + RotL64(aOrbiterF, 5U)) + aPhaseDWandererUpdateSaltB[((aIndex + 10U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 11U) + aOrbiterE) + RotL64(aOrbiterD, 39U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 18U) + aOrbiterJ) + RotL64(aOrbiterB, 21U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterA, 41U)) + aOrbiterG) + RotL64(aCarry, 21U)) + aNonceWordF);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterA, 48U)) + aOrbiterJ) + aNonceWordN);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 4U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 30U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererK, 53U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ aNonceWordL;
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 25713U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((aIndex + 24435U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 23752U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneA[((aIndex + 26052U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 19U) ^ RotL64(aPrevious, 37U)) + (RotL64(aIngress, 51U) ^ RotL64(aCarry, 4U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterD = (aWandererH + RotL64(aPrevious, 37U)) + 4634399531433127141U;
            aOrbiterB = (aWandererI + RotL64(aIngress, 14U)) + 16961792729406903200U;
            aOrbiterC = ((aWandererA + RotL64(aCross, 51U)) + RotL64(aCarry, 13U)) + 4105280732301137738U;
            aOrbiterE = ((aWandererC + RotL64(aScatter, 27U)) + 15692013501147331191U) + aNonceWordE;
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 53U)) + RotL64(aCarry, 27U)) + 1252216715968780587U;
            aOrbiterI = ((aWandererJ + RotL64(aCross, 47U)) + 7958289043012473752U) + aPhaseDOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = (aWandererK + RotL64(aScatter, 19U)) + 6611577301818896615U;
            aOrbiterA = (((aWandererF + RotL64(aIngress, 57U)) + RotL64(aCarry, 19U)) + 8506226754305949140U) + aPhaseDOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = (aWandererG + RotL64(aPrevious, 23U)) + 3648813120449403353U;
            aOrbiterG = (aWandererB + RotL64(aIngress, 12U)) + 5195245426245535735U;
            aOrbiterJ = (aWandererE + RotL64(aScatter, 43U)) + 542948051600803051U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 11974253551208964789U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 10596463592332655367U;
            aOrbiterC = RotL64((aOrbiterC * 10941161258815714641U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 12015129484061440159U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 8254944355710109060U;
            aOrbiterI = RotL64((aOrbiterI * 3233697992479357615U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 2754858806943915419U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterF) ^ 5007802002906662779U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterA = RotL64((aOrbiterA * 15613733948331639723U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 6262190752136523216U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 10528977986487821428U;
            aOrbiterG = RotL64((aOrbiterG * 1184258264034585525U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 8511097226098211854U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 12091864735686692582U) ^ aNonceWordL;
            aOrbiterD = RotL64((aOrbiterD * 6128140528141411237U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 4970966265236842566U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 10728884018459718341U;
            aOrbiterE = RotL64((aOrbiterE * 18205183219769602827U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 13760057185629905360U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 6590269178744829056U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14482684769712170123U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 765826377665103262U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 9364759196106579706U;
            aOrbiterK = RotL64((aOrbiterK * 10315111163659289329U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 4629303338428087146U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 15107221579712215172U;
            aOrbiterJ = RotL64((aOrbiterJ * 14410837138199304663U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 9407987092859067074U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 13589362515507116096U;
            aOrbiterB = RotL64((aOrbiterB * 4544198075069052713U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 2236921538387014026U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 4634399531433127141U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13132011613143486575U), 5U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterJ, 5U);
            aIngress = aIngress + (RotL64(aOrbiterA, 23U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 54U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 13U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + RotL64(aOrbiterC, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterA, 46U)) + aOrbiterF);
            aWandererH = aWandererH + ((RotL64(aIngress, 13U) + aOrbiterH) + RotL64(aOrbiterC, 29U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterG, 11U)) + aOrbiterB);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 34U) + RotL64(aOrbiterH, 53U)) + aOrbiterB) + RotL64(aCarry, 57U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((((RotL64(aCross, 57U) + aOrbiterH) + RotL64(aOrbiterG, 3U)) + aNonceWordN) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 43U) + RotL64(aOrbiterE, 35U)) + aOrbiterI) + RotL64(aCarry, 27U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterF, 51U)) + aOrbiterC) + aNonceWordO);
            aWandererK = aWandererK + ((RotL64(aIngress, 53U) + aOrbiterF) + RotL64(aOrbiterK, 43U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 38U) + aOrbiterD) + RotL64(aOrbiterJ, 37U));
            aWandererA = aWandererA + (((RotL64(aIngress, 47U) + RotL64(aOrbiterB, 22U)) + aOrbiterI) + aNonceWordD);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 51U) + aOrbiterE) + RotL64(aOrbiterD, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 54U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererD);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 37U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 21U));
            aCarry = aCarry + RotL64(aWandererC, 50U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ aNonceWordA;
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 30100U)) & S_BLOCK1], 50U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30237U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 30417U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((aIndex + 30739U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aPrevious, 6U)) + (RotL64(aIngress, 39U) ^ RotL64(aCross, 57U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterF = (aWandererD + RotL64(aScatter, 27U)) + 8685374557928800912U;
            aOrbiterH = (aWandererE + RotL64(aIngress, 24U)) + 3482312691892161229U;
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 3U)) + 6948130297389161165U) + aPhaseDOrbiterAssignSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = (aWandererJ + RotL64(aCross, 29U)) + 5506385663788942690U;
            aOrbiterB = (aWandererH + RotL64(aPrevious, 41U)) + 17859982009307397161U;
            aOrbiterG = ((aWandererG + RotL64(aScatter, 37U)) + RotL64(aCarry, 23U)) + 9178488809207094043U;
            aOrbiterD = ((aWandererA + RotL64(aIngress, 53U)) + RotL64(aCarry, 41U)) + 1835479501226057169U;
            aOrbiterI = (((aWandererI + RotL64(aCross, 47U)) + 5368101733632614939U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordN;
            aOrbiterJ = (aWandererB + RotL64(aIngress, 39U)) + 9050459666576835422U;
            aOrbiterC = (aWandererK + RotL64(aScatter, 5U)) + 9042186993119635078U;
            aOrbiterA = ((aWandererC + RotL64(aCross, 10U)) + RotL64(aCarry, 3U)) + 17528342580198295025U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 6495418332558436882U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 8834495762667327342U;
            aOrbiterE = RotL64((aOrbiterE * 10783141541937645995U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 4364314196965690905U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 6357485231062120459U;
            aOrbiterB = RotL64((aOrbiterB * 289429584586504995U), 21U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterE) + 3321488322626415347U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordK;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 10817330671781848737U;
            aOrbiterG = RotL64((aOrbiterG * 15875919466358823335U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 17974092279281611763U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 2871472057292789157U;
            aOrbiterD = RotL64((aOrbiterD * 16104199340711015181U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 15187929795092006849U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 13482063681546475923U;
            aOrbiterI = RotL64((aOrbiterI * 14466266308157364963U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 6232152545071397380U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 17488906002621373262U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4719340606442742577U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 12444819880507588549U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 13808941689757772497U;
            aOrbiterC = RotL64((aOrbiterC * 6541360905282412317U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 8049361354387692374U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 7137831335606542401U;
            aOrbiterA = RotL64((aOrbiterA * 11022231291507235007U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 7230759462019420058U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 3923744511976096944U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9953869624243563101U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 15967667946023263856U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 8677583624693910669U;
            aOrbiterH = RotL64((aOrbiterH * 10737731876339973717U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 1604347321263511013U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 8685374557928800912U;
            aOrbiterK = RotL64((aOrbiterK * 14103365695918844461U), 5U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterI, 43U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 19U));
            aIngress = aIngress + (RotL64(aOrbiterD, 52U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 29U));
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterE, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterB, 50U)) + aOrbiterI) + aNonceWordI);
            aWandererG = aWandererG + ((RotL64(aScatter, 53U) + RotL64(aOrbiterI, 3U)) + aOrbiterJ);
            aWandererB = aWandererB ^ ((RotL64(aCross, 27U) + aOrbiterK) + RotL64(aOrbiterG, 23U));
            aWandererD = aWandererD + ((RotL64(aIngress, 38U) + RotL64(aOrbiterI, 5U)) + aOrbiterF);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 21U) + aOrbiterH) + RotL64(aOrbiterC, 41U)) + aNonceWordJ);
            aWandererH = aWandererH + (((RotL64(aIngress, 41U) + aOrbiterD) + RotL64(aOrbiterK, 60U)) + RotL64(aCarry, 23U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 57U) + aOrbiterC) + RotL64(aOrbiterB, 35U));
            aWandererI = aWandererI + (((RotL64(aScatter, 47U) + RotL64(aOrbiterJ, 39U)) + aOrbiterK) + RotL64(aCarry, 11U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 44U) + RotL64(aOrbiterA, 27U)) + aOrbiterG);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 3U) + aOrbiterB) + RotL64(aOrbiterE, 29U)) + aPhaseDWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 19U) + aOrbiterK) + RotL64(aOrbiterE, 53U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 21U));
            aCarry = aCarry + (RotL64(aWandererK, 52U) ^ aWandererH);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 43U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 37U));
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererC, 57U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ aNonceWordF;
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

void TwistExpander_WaterPolo_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x9EBA1DB270A797BDULL + 0x8C2F24304BC16664ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xBB6917854E1B419FULL + 0xBCEA7D4C7E15053CULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xF28E81707E7F5A63ULL + 0x9D46D21416323392ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xD7760CC67287677FULL + 0xF6A0424E7F89C3FDULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xF349BCCA9F159597ULL + 0xA943B1E450983244ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xDFF27D5D860B0F51ULL + 0xCCE9880178DC0414ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xE76C4562DE46FF4DULL + 0xDBBD1B28AD8C148FULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x97D142742734846FULL + 0xEAEB5AE3C48E0965ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xE2DA9C97523265DBULL + 0x8D08646655732E7DULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xB9025A5E84BD3EE5ULL + 0x81CAC73A2752551AULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x87ABEBC93134C285ULL + 0x8B7F48019D6EE90AULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xC8B45D4473FCECB7ULL + 0xB4F51802E2945FA7ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x9BF62583E9FD67FFULL + 0x82C5F4E69165FFEAULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xD127AFF47CB4204BULL + 0xC2FF19EDBE3F1516ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x928481EAD4E7558DULL + 0xF1A5353B8AEB0705ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xADAC4C62991E661DULL + 0xA15408E0449D2A7AULL);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 4682U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneC[((aIndex + 1913U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 4069U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((aIndex + 2670U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 3U) + RotL64(aPrevious, 18U)) + (RotL64(aIngress, 35U) ^ RotL64(aCross, 47U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 47U)) + 1888427424966603593U) + aPhaseEOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = ((aWandererB + RotL64(aIngress, 29U)) + RotL64(aCarry, 53U)) + 5436761445660415091U;
            aOrbiterB = (aWandererG + RotL64(aCross, 60U)) + 17322876217962143270U;
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 23U)) + RotL64(aCarry, 19U)) + 9728299982740564979U;
            aOrbiterG = (aWandererA + RotL64(aCross, 5U)) + 301720335271716921U;
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 3U)) + 8069685428854814396U) + aPhaseEOrbiterAssignSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = (aWandererF + RotL64(aIngress, 44U)) + 1973715500949100991U;
            aOrbiterD = ((aWandererI + RotL64(aScatter, 41U)) + RotL64(aCarry, 43U)) + 87666408799854155U;
            aOrbiterA = ((aWandererH + RotL64(aIngress, 35U)) + 12195436904339035245U) + aNonceWordH;
            aOrbiterF = ((aWandererD + RotL64(aScatter, 37U)) + 4578742069143400295U) + aNonceWordJ;
            aOrbiterJ = ((aWandererE + RotL64(aCross, 53U)) + 7828776048774876484U) + aNonceWordB;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 17203146364542781833U) + aNonceWordC;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 16913369550858890466U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13534417587921978507U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 9632761514552265402U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 9106637671877341286U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9073709119482640391U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 15423680889126750876U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 6087310684583331882U;
            aOrbiterE = RotL64((aOrbiterE * 8964465129744898619U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 5420955876411796789U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 14166807419730848032U) ^ aNonceWordP;
            aOrbiterH = RotL64((aOrbiterH * 442659738632823751U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 8118312450347026824U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 4253043584558403086U;
            aOrbiterK = RotL64((aOrbiterK * 5651748455190536467U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 8810774678371762700U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 12218479555589447835U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11026364205248516355U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 11389930523582876358U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 16334420553471379915U;
            aOrbiterJ = RotL64((aOrbiterJ * 13830132212033904777U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 18201289372553710279U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 7196540389657785361U;
            aOrbiterC = RotL64((aOrbiterC * 13058135202554889791U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 2601046573550065116U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 2243003381737071984U;
            aOrbiterG = RotL64((aOrbiterG * 10518763530499878945U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 6058992247656841580U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 10083863011670540073U) ^ aNonceWordM;
            aOrbiterD = RotL64((aOrbiterD * 17908394295613117155U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 8505005026063156940U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 1888427424966603593U;
            aOrbiterF = RotL64((aOrbiterF * 18298382581929885653U), 13U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterF, 13U);
            aIngress = aIngress + (RotL64(aOrbiterH, 53U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 43U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 4U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 39U));
            aIngress = aIngress + RotL64(aOrbiterJ, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 20U) + RotL64(aOrbiterC, 35U)) + aOrbiterD);
            aWandererA = aWandererA + ((RotL64(aCross, 11U) + RotL64(aOrbiterH, 21U)) + aOrbiterK);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterI, 18U)) + aOrbiterJ);
            aWandererH = aWandererH + ((RotL64(aPrevious, 5U) + aOrbiterK) + RotL64(aOrbiterJ, 3U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 60U) + aOrbiterJ) + RotL64(aOrbiterA, 47U));
            aWandererF = aWandererF + (((RotL64(aScatter, 27U) + RotL64(aOrbiterF, 23U)) + aOrbiterB) + RotL64(aCarry, 11U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 23U) + aOrbiterJ) + RotL64(aOrbiterE, 53U)) + aNonceWordK);
            aWandererI = aWandererI + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterI, 50U)) + aOrbiterD) + RotL64(aCarry, 47U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 13U) + aOrbiterE) + RotL64(aOrbiterC, 57U));
            aWandererB = aWandererB + (((RotL64(aScatter, 53U) + RotL64(aOrbiterG, 41U)) + aOrbiterE) + aPhaseEWandererUpdateSaltA[((aIndex + 14U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 29U) + aOrbiterB) + RotL64(aOrbiterK, 39U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 6U));
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererI);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 41U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + (RotL64(aWandererG, 44U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererJ, 47U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 6177U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 7871U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 6788U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 10454U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 6U) + RotL64(aCarry, 19U)) + (RotL64(aCross, 47U) ^ RotL64(aPrevious, 35U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterI = ((aWandererF + RotL64(aCross, 53U)) + RotL64(aCarry, 29U)) + 2177539223979303669U;
            aOrbiterH = (aWandererA + RotL64(aScatter, 3U)) + 3962004686551521471U;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 39U)) + 8457602312617147662U) + aPhaseEOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 5U)) + RotL64(aCarry, 5U)) + 18011802451816510632U;
            aOrbiterA = (aWandererI + RotL64(aCross, 60U)) + 9046101759168876832U;
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 47U)) + 11135620637431969597U) + aNonceWordC;
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 23U)) + RotL64(aCarry, 21U)) + 15913029940697999701U;
            aOrbiterE = (aWandererE + RotL64(aIngress, 13U)) + 16304193109948135982U;
            aOrbiterC = (aWandererD + RotL64(aCross, 43U)) + 13208892298820080981U;
            aOrbiterF = ((aWandererC + RotL64(aScatter, 57U)) + 4182377898949419225U) + aPhaseEOrbiterAssignSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterD = ((aWandererG + RotL64(aIngress, 36U)) + 13970137023071326151U) + aNonceWordN;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 8402396284835248583U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 8859190834060657829U;
            aOrbiterK = RotL64((aOrbiterK * 13552418608113716117U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 9760005337757990392U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 14108277760135744897U;
            aOrbiterH = RotL64((aOrbiterH * 4474681104256093885U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 12226316121949012350U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 3456392186754113960U) ^ aNonceWordK;
            aOrbiterA = RotL64((aOrbiterA * 8704729827929941215U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 5004087958637038973U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 7176881295123125567U;
            aOrbiterJ = RotL64((aOrbiterJ * 15272157962928021009U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 10889800478505074438U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 13728832441482547824U;
            aOrbiterC = RotL64((aOrbiterC * 17588477761978646139U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 17345665880706866772U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 301139993853297566U;
            aOrbiterI = RotL64((aOrbiterI * 5812445396758354505U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 2061389844760610160U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 13631862266139238355U;
            aOrbiterG = RotL64((aOrbiterG * 143613352104722701U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 10767186080827509622U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 4893486019456886013U;
            aOrbiterB = RotL64((aOrbiterB * 5194746459545610901U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 11264795916303477037U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterA) ^ 16013652139405432608U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterE = RotL64((aOrbiterE * 14924257021089920495U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 5209743554932653849U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 13160179712987277456U) ^ aNonceWordE;
            aOrbiterF = RotL64((aOrbiterF * 5003755912040281427U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 12440615920191945386U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 2177539223979303669U;
            aOrbiterD = RotL64((aOrbiterD * 3565122523239344029U), 35U);
            //
            aIngress = RotL64(aOrbiterE, 47U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterC, 5U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterK, 28U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 21U));
            aIngress = aIngress + (RotL64(aOrbiterD, 37U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aCross, 10U) + RotL64(aOrbiterB, 24U)) + aOrbiterF) + RotL64(aCarry, 11U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 29U) + aOrbiterK) + RotL64(aOrbiterG, 19U)) + aPhaseEWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 39U) + aOrbiterA) + RotL64(aOrbiterK, 3U)) + aNonceWordI);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterD, 11U)) + aOrbiterJ);
            aWandererB = aWandererB + (((RotL64(aScatter, 3U) + aOrbiterI) + RotL64(aOrbiterG, 35U)) + RotL64(aCarry, 35U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 35U) + aOrbiterJ) + RotL64(aOrbiterG, 41U)) + aNonceWordF);
            aWandererG = aWandererG + ((RotL64(aCross, 43U) + aOrbiterA) + RotL64(aOrbiterJ, 43U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 50U) + aOrbiterI) + RotL64(aOrbiterH, 39U));
            aWandererD = aWandererD + (((RotL64(aCross, 5U) + aOrbiterC) + RotL64(aOrbiterF, 53U)) + aPhaseEWandererUpdateSaltF[((aIndex + 26U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterB, 5U)) + aOrbiterE);
            aWandererI = aWandererI + ((RotL64(aIngress, 37U) + RotL64(aOrbiterE, 46U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 30U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 37U));
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererA);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + RotL64(aWandererG, 14U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 14731U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneA[((aIndex + 12090U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 14845U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 16299U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCross, 56U)) + (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 43U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterB = (aWandererK + RotL64(aScatter, 30U)) + 12206125048349568300U;
            aOrbiterA = ((aWandererB + RotL64(aIngress, 23U)) + 5843520589343188818U) + aPhaseEOrbiterAssignSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = (aWandererD + RotL64(aCross, 19U)) + 12195046124287121687U;
            aOrbiterD = (aWandererG + RotL64(aPrevious, 21U)) + 16769779119214020640U;
            aOrbiterF = (((aWandererC + RotL64(aScatter, 27U)) + RotL64(aCarry, 21U)) + 5257603646260695833U) + aNonceWordP;
            aOrbiterC = ((aWandererI + RotL64(aIngress, 39U)) + RotL64(aCarry, 53U)) + 8523523946234886745U;
            aOrbiterG = (aWandererE + RotL64(aPrevious, 57U)) + 7316024684200084096U;
            aOrbiterH = ((aWandererF + RotL64(aCross, 11U)) + 11996978575084115207U) + aPhaseEOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 3U)) + 15491711479085513628U;
            aOrbiterI = (aWandererA + RotL64(aCross, 60U)) + 6036648530996821484U;
            aOrbiterE = (((aWandererH + RotL64(aPrevious, 51U)) + RotL64(aCarry, 13U)) + 926323222234121863U) + aNonceWordI;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 2700323841295743492U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 5852273765810284935U;
            aOrbiterK = RotL64((aOrbiterK * 16665696735016345215U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 11697397483133538067U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 17777142964957007194U;
            aOrbiterC = RotL64((aOrbiterC * 6338967222543284999U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 10892176201151170298U) + aNonceWordA;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 11759700374509499684U;
            aOrbiterA = RotL64((aOrbiterA * 14247697264744736081U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 11343756773329590643U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 15785048929757652350U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17208103574389502597U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 7508839228498497238U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 13088508510402094665U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15730279447009669103U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 16259236641717377699U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 11228995722951003980U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4870092259515181323U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 13775851561528617086U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 3023564646900497080U;
            aOrbiterB = RotL64((aOrbiterB * 9936548213275464131U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 154952467284609583U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 14239675888632174461U;
            aOrbiterD = RotL64((aOrbiterD * 1370550680736926425U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 168749514558708557U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 5070416708211422927U;
            aOrbiterG = RotL64((aOrbiterG * 13631900152346927703U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 1961290602001581341U) + aNonceWordB;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 12235345489656113478U;
            aOrbiterJ = RotL64((aOrbiterJ * 14403534235273302211U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 2295581049708176078U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 12206125048349568300U;
            aOrbiterE = RotL64((aOrbiterE * 6008868846674396181U), 57U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterF, 47U);
            aIngress = aIngress + (RotL64(aOrbiterD, 53U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterI, 51U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 34U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + RotL64(aOrbiterA, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aScatter, 11U) + aOrbiterJ) + RotL64(aOrbiterF, 11U)) + RotL64(aCarry, 37U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterJ, 53U)) + aOrbiterA);
            aWandererE = aWandererE + ((RotL64(aIngress, 52U) + aOrbiterK) + RotL64(aOrbiterB, 27U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 41U) + aOrbiterI) + RotL64(aOrbiterE, 60U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aCross, 57U) + aOrbiterA) + RotL64(aOrbiterD, 41U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterK, 21U)) + aOrbiterI);
            aWandererD = aWandererD + (((RotL64(aIngress, 13U) + aOrbiterH) + RotL64(aOrbiterD, 43U)) + RotL64(aCarry, 41U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 48U) + aOrbiterC) + RotL64(aOrbiterD, 57U)) + aNonceWordO);
            aWandererK = aWandererK + ((RotL64(aScatter, 21U) + aOrbiterJ) + RotL64(aOrbiterG, 35U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterJ, 19U)) + aOrbiterH);
            aWandererB = aWandererB + (((RotL64(aCross, 35U) + RotL64(aOrbiterI, 4U)) + aOrbiterG) + aPhaseEWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 36U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 21U));
            aCarry = aCarry + RotL64(aWandererB, 11U);
            aCarry = aCarry + RotL64(aIngress, 28U);
            aCarry = aCarry ^ aNonceWordD;
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 17811U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 16503U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 19122U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneD[((aIndex + 21466U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 3U) ^ RotL64(aIngress, 41U)) + (RotL64(aCross, 21U) ^ RotL64(aPrevious, 54U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterG = (aWandererK + RotL64(aCross, 27U)) + 7960325128608297381U;
            aOrbiterI = ((aWandererH + RotL64(aScatter, 21U)) + 12773836012104052042U) + aNonceWordP;
            aOrbiterK = (aWandererA + RotL64(aIngress, 60U)) + 3173972621347773016U;
            aOrbiterE = (aWandererE + RotL64(aPrevious, 29U)) + 3708401356314308171U;
            aOrbiterH = ((aWandererF + RotL64(aIngress, 57U)) + 950774285720019449U) + aNonceWordL;
            aOrbiterB = (((aWandererB + RotL64(aScatter, 13U)) + RotL64(aCarry, 51U)) + 4170092315705438265U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = ((aWandererD + RotL64(aCross, 42U)) + 17000449130864980747U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 35U)) + RotL64(aCarry, 23U)) + 8793910540062893860U;
            aOrbiterD = (aWandererG + RotL64(aCross, 39U)) + 520277969543516469U;
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 51U)) + 12762214857389827271U) + aNonceWordA;
            aOrbiterC = ((aWandererI + RotL64(aIngress, 47U)) + RotL64(aCarry, 41U)) + 2932451184340207695U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 11062179998786293839U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 7919119215271524178U;
            aOrbiterK = RotL64((aOrbiterK * 9053677007180081359U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 1774988449597115155U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 3799792889466518953U;
            aOrbiterH = RotL64((aOrbiterH * 17512791286490623455U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 1815062051307896589U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 15260373951371654483U;
            aOrbiterB = RotL64((aOrbiterB * 2208604434669491625U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 12867546628945676853U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 7772820973895846946U;
            aOrbiterF = RotL64((aOrbiterF * 7581704643538761985U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 14213957831821966834U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 16561105721170419454U;
            aOrbiterJ = RotL64((aOrbiterJ * 2540533987337175367U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 16556502948339949526U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 9706742922075498974U;
            aOrbiterD = RotL64((aOrbiterD * 8527361328901355457U), 37U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 13455756934917486016U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 9107769876332723454U) ^ aNonceWordC;
            aOrbiterA = RotL64((aOrbiterA * 1722386100852683783U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 15793099079168487016U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 7968278803691283365U;
            aOrbiterC = RotL64((aOrbiterC * 11644765391940099387U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 15068302421261745111U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 11373111908765197862U;
            aOrbiterG = RotL64((aOrbiterG * 17756438368103196771U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 6362100123286229887U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 528778333872160609U;
            aOrbiterI = RotL64((aOrbiterI * 17377710146983314215U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 6116442644744391285U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 7960325128608297381U;
            aOrbiterE = RotL64((aOrbiterE * 17826511435509927061U), 23U);
            //
            aIngress = RotL64(aOrbiterJ, 30U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 35U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 41U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 14U));
            aIngress = aIngress + RotL64(aOrbiterD, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aIngress, 56U) + RotL64(aOrbiterJ, 35U)) + aOrbiterF);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 11U) + aOrbiterA) + RotL64(aOrbiterE, 5U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aCross, 37U) + aOrbiterB) + RotL64(aOrbiterC, 41U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 27U) + aOrbiterJ) + RotL64(aOrbiterK, 18U));
            aWandererK = aWandererK + (((RotL64(aIngress, 29U) + aOrbiterD) + RotL64(aOrbiterE, 29U)) + RotL64(aCarry, 5U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterG, 37U)) + aOrbiterF) + aNonceWordF);
            aWandererD = aWandererD + (((RotL64(aScatter, 39U) + aOrbiterC) + RotL64(aOrbiterG, 21U)) + RotL64(aCarry, 13U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 47U) + aOrbiterH) + RotL64(aOrbiterG, 57U)) + aNonceWordK);
            aWandererE = aWandererE + (((RotL64(aScatter, 14U) + RotL64(aOrbiterD, 48U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltE[((aIndex + 12U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterI, 23U)) + aOrbiterF);
            aWandererI = aWandererI + (((RotL64(aPrevious, 5U) + aOrbiterA) + RotL64(aOrbiterK, 13U)) + aNonceWordE);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 18U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererB);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 51U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 60U));
            aCarry = aCarry + RotL64(aWandererF, 13U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordJ);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 26214U)) & S_BLOCK1], 22U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 24790U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26644U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneA[((aIndex + 21877U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCarry, 24U)) ^ (RotL64(aIngress, 11U) + RotL64(aCross, 39U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterB = (((aWandererA + RotL64(aCross, 41U)) + RotL64(aCarry, 37U)) + 12809562813316740345U) + aNonceWordO;
            aOrbiterJ = (aWandererG + RotL64(aScatter, 35U)) + 17084212535326321199U;
            aOrbiterK = (((aWandererF + RotL64(aIngress, 21U)) + RotL64(aCarry, 41U)) + 16074921689983846769U) + aNonceWordK;
            aOrbiterG = (aWandererH + RotL64(aPrevious, 50U)) + 14027986153007120145U;
            aOrbiterC = (((aWandererE + RotL64(aScatter, 39U)) + RotL64(aCarry, 29U)) + 7633455951809250227U) + aPhaseEOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = (aWandererK + RotL64(aIngress, 47U)) + 340989348513370174U;
            aOrbiterH = (aWandererB + RotL64(aPrevious, 27U)) + 5307820377645020116U;
            aOrbiterD = ((aWandererJ + RotL64(aCross, 57U)) + 5605285015771527274U) + aNonceWordE;
            aOrbiterA = (aWandererD + RotL64(aIngress, 60U)) + 5293500434746182790U;
            aOrbiterE = (aWandererI + RotL64(aScatter, 19U)) + 7263156475892261811U;
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 13U)) + 10672879570907433005U) + aPhaseEOrbiterAssignSaltE[((aIndex + 7U)) & S_SALT1];
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 16659226780900986107U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 9774892622769850665U) ^ aNonceWordC;
            aOrbiterK = RotL64((aOrbiterK * 7487477727543183211U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 10728057184108279042U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 5032485856947407217U;
            aOrbiterI = RotL64((aOrbiterI * 16651577903809154285U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 14642241075374862345U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 8386481273395203518U;
            aOrbiterD = RotL64((aOrbiterD * 11649977733867003445U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 2874153265304098104U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 11519900149177261000U;
            aOrbiterE = RotL64((aOrbiterE * 2010158758971864505U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 8885690878540115768U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 4482143389870987714U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7105332459437434281U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 17469068567801886615U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 5121422018622394837U;
            aOrbiterG = RotL64((aOrbiterG * 14823827133212643467U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 3130788210672745618U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 6139244627510113216U;
            aOrbiterH = RotL64((aOrbiterH * 2640754184921507389U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 10488511756324474710U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 1760223670304953696U;
            aOrbiterA = RotL64((aOrbiterA * 4007062295003769311U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 2232708414171096783U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 17497492434939621063U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9850565931511937725U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 8199114561613022892U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 15432482434863050835U;
            aOrbiterJ = RotL64((aOrbiterJ * 14271143436318169871U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 14991531324947777062U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 12809562813316740345U;
            aOrbiterC = RotL64((aOrbiterC * 4487021480964944879U), 13U);
            //
            aIngress = RotL64(aOrbiterG, 29U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterF, 6U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 41U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 13U));
            aIngress = aIngress + RotL64(aOrbiterH, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aCross, 6U) + RotL64(aOrbiterB, 44U)) + aOrbiterA) + RotL64(aCarry, 19U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterJ, 47U)) + aOrbiterG) + aNonceWordI);
            aWandererH = aWandererH + ((RotL64(aScatter, 41U) + aOrbiterF) + RotL64(aOrbiterI, 23U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 13U) + aOrbiterB) + RotL64(aOrbiterK, 37U)) + aNonceWordB);
            aWandererF = aWandererF + (((RotL64(aScatter, 43U) + aOrbiterI) + RotL64(aOrbiterJ, 57U)) + aPhaseEWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterE, 29U)) + aOrbiterB);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 35U) + RotL64(aOrbiterK, 51U)) + aOrbiterF) + RotL64(aCarry, 57U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterH, 11U)) + aOrbiterI);
            aWandererI = aWandererI + ((RotL64(aScatter, 53U) + RotL64(aOrbiterB, 53U)) + aOrbiterI);
            aWandererK = aWandererK ^ ((RotL64(aCross, 26U) + RotL64(aOrbiterC, 14U)) + aOrbiterD);
            aWandererB = aWandererB + (((RotL64(aIngress, 3U) + RotL64(aOrbiterI, 21U)) + aOrbiterD) + aNonceWordG);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 48U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererK);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + RotL64(aWandererD, 37U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordN);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 27885U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29959U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 31625U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneB[((aIndex + 28201U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 35U) ^ RotL64(aCross, 23U)) + (RotL64(aCarry, 50U) ^ RotL64(aPrevious, 5U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterC = (aWandererA + RotL64(aCross, 41U)) + 4980738603982643969U;
            aOrbiterF = ((aWandererH + RotL64(aScatter, 47U)) + RotL64(aCarry, 47U)) + 17660278413018470020U;
            aOrbiterB = ((aWandererD + RotL64(aIngress, 39U)) + 17598114429859543466U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 30U)) + RotL64(aCarry, 41U)) + 10993929335279994739U;
            aOrbiterH = (aWandererB + RotL64(aScatter, 37U)) + 17967203122976322481U;
            aOrbiterA = (aWandererE + RotL64(aIngress, 11U)) + 1872290205549034384U;
            aOrbiterE = ((aWandererJ + RotL64(aCross, 21U)) + 16607778671782810797U) + aPhaseEOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = (aWandererI + RotL64(aPrevious, 56U)) + 4895226930754394376U;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 13U)) + RotL64(aCarry, 3U)) + 14960359005982301383U;
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 19U)) + 9921642352377700630U) + aNonceWordH;
            aOrbiterG = (aWandererF + RotL64(aCross, 23U)) + 893281964367208693U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 8232519988397858732U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 4433022122758913407U;
            aOrbiterB = RotL64((aOrbiterB * 834240393225479419U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 12689609831247168353U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 404535388957472176U;
            aOrbiterH = RotL64((aOrbiterH * 14534020545479806593U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 3349108201964013155U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 4386449511297371730U;
            aOrbiterA = RotL64((aOrbiterA * 9596273264321140229U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 14314587717949070586U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 10923886625271054985U;
            aOrbiterE = RotL64((aOrbiterE * 7838969002623486809U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 17634909585329833520U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 2021301459918350372U;
            aOrbiterI = RotL64((aOrbiterI * 1388242915918642741U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 5219599112498224367U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 10641339455385046206U;
            aOrbiterK = RotL64((aOrbiterK * 1022283727595400719U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 5003342156562330058U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 10951027475628404336U;
            aOrbiterD = RotL64((aOrbiterD * 17836928292555158461U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 13040991872592235460U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 11149099984302782267U;
            aOrbiterG = RotL64((aOrbiterG * 4248667283139686251U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 2202253777854402763U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 16679038924474862612U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2624443661523083597U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 1959650241410955571U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 8415989510614674816U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16340289102832732519U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 2344501711730399821U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterG) ^ 4980738603982643969U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterJ = RotL64((aOrbiterJ * 6419275275477478723U), 51U);
            //
            aIngress = RotL64(aOrbiterC, 41U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 21U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 27U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 24U));
            aIngress = aIngress + RotL64(aOrbiterD, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterE, 44U)) + aOrbiterB);
            aWandererI = aWandererI ^ ((((RotL64(aIngress, 27U) + aOrbiterI) + RotL64(aOrbiterG, 13U)) + aNonceWordJ) + aPhaseEWandererUpdateSaltC[((aIndex + 26U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aCross, 11U) + RotL64(aOrbiterJ, 3U)) + aOrbiterK) + RotL64(aCarry, 23U)) + aPhaseEWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 60U) + aOrbiterK) + RotL64(aOrbiterI, 23U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterA, 37U)) + aOrbiterH);
            aWandererD = aWandererD ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterG, 29U)) + aOrbiterJ);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 53U) + aOrbiterJ) + RotL64(aOrbiterA, 53U)) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 57U) + aOrbiterI) + RotL64(aOrbiterC, 42U)) + aNonceWordP);
            aWandererK = aWandererK + ((RotL64(aCross, 13U) + RotL64(aOrbiterK, 11U)) + aOrbiterD);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 51U) + aOrbiterH) + RotL64(aOrbiterF, 47U)) + aNonceWordL);
            aWandererA = aWandererA + ((RotL64(aIngress, 20U) + RotL64(aOrbiterA, 5U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 36U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererD);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererJ, 41U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ aNonceWordM;
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

void TwistExpander_WaterPolo_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xC4AD642DB9A3389FULL + 0xB1E7E620326708B0ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xE329CB53DC625031ULL + 0xD9C346EBAC344807ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xD6F850467CA2F6F9ULL + 0xF6680D34A38BDDB6ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xF20D1B21A2A1FCBBULL + 0xB31CBF6A60AD6D4DULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xBF2638E48F8A18F7ULL + 0xC10822ADA118898CULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xA668089087AC08A3ULL + 0xBD67104885B18984ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x9104D72A8C6DDF87ULL + 0xB5732C08A4EF6851ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xF27004EBCFDA8291ULL + 0x88CAC8CBCFC24D69ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xBE99E257BF3DE335ULL + 0xCA1B9846B0E20275ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x9C4D6FB872042897ULL + 0xAC9AFB31C1B6A2E4ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x967E35C61F24223DULL + 0xF04348DA477E4D62ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xA43EFD60D98E9CFDULL + 0xDD82AF52DA4E874AULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xE357915CF9328CD5ULL + 0xDC45904D47FE3200ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xE8EF0076820CEDBDULL + 0x9FF1112C2A0D4897ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xEA25B0CA35657AA7ULL + 0xB315E7A2E9D582DAULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x846F1CA63080A07FULL + 0xF71DB82A4027ED5DULL);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 4413U)) & S_BLOCK1], 30U) ^ RotL64(aOperationLaneC[((aIndex + 1943U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 4612U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 5299U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCarry, 37U)) ^ (RotL64(aCross, 11U) ^ RotL64(aIngress, 56U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterA = (aWandererG + RotL64(aScatter, 41U)) + 785861751704720606U;
            aOrbiterB = (aWandererA + RotL64(aCross, 53U)) + 15968088718435606299U;
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 3U)) + 1393976526590347151U) + aPhaseFOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = (aWandererC + RotL64(aIngress, 6U)) + 17240750947292745884U;
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 23U)) + RotL64(aCarry, 23U)) + 4921576136163183137U;
            aOrbiterF = (((aWandererB + RotL64(aCross, 35U)) + RotL64(aCarry, 27U)) + 3334047873553153032U) + aNonceWordL;
            aOrbiterJ = (aWandererF + RotL64(aScatter, 29U)) + 15086509978458408698U;
            aOrbiterI = (((aWandererH + RotL64(aIngress, 27U)) + RotL64(aCarry, 5U)) + 892391205397581998U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = (aWandererD + RotL64(aPrevious, 47U)) + 2965686403183767521U;
            aOrbiterH = (aWandererI + RotL64(aCross, 19U)) + 14632215393655706170U;
            aOrbiterK = (aWandererE + RotL64(aScatter, 38U)) + 15740589515342377322U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 11131164813943086445U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 6988080581278900960U;
            aOrbiterD = RotL64((aOrbiterD * 6412189142344044255U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 16021254613117657178U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 6183615599897921154U;
            aOrbiterF = RotL64((aOrbiterF * 9976411093264211033U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 12533992547026652747U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 3104325358982904219U) ^ aNonceWordB;
            aOrbiterA = RotL64((aOrbiterA * 14977348108778147265U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 3878525937957474644U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 2120435259884368445U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15964718652193073177U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 14928658302694194856U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 9121310461310309348U;
            aOrbiterJ = RotL64((aOrbiterJ * 17304439784647477491U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 3715693239100476493U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 7336577492932262490U;
            aOrbiterG = RotL64((aOrbiterG * 11074754160002665253U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 2312452827448455675U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 4322756069651934618U;
            aOrbiterK = RotL64((aOrbiterK * 6908893297397073539U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 4962079617577705818U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 5072727464750706525U;
            aOrbiterB = RotL64((aOrbiterB * 4947670001221089155U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 4553791875259778686U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 15823770920225774233U;
            aOrbiterE = RotL64((aOrbiterE * 409663191536830375U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 9468608484284459072U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 8658861660659699947U;
            aOrbiterI = RotL64((aOrbiterI * 2933359123761406353U), 37U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 14453429515273506170U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 785861751704720606U;
            aOrbiterH = RotL64((aOrbiterH * 3544627380583668815U), 21U);
            //
            aIngress = RotL64(aOrbiterD, 48U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 51U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 27U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 13U));
            aIngress = aIngress + RotL64(aOrbiterK, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aScatter, 30U) + aOrbiterF) + RotL64(aOrbiterE, 43U));
            aWandererA = aWandererA + (((RotL64(aIngress, 11U) + aOrbiterH) + RotL64(aOrbiterC, 27U)) + aNonceWordI);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 57U) + aOrbiterI) + RotL64(aOrbiterB, 5U));
            aWandererB = aWandererB + ((RotL64(aCross, 47U) + RotL64(aOrbiterK, 48U)) + aOrbiterD);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterJ, 39U)) + aOrbiterG) + aNonceWordK);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 43U) + aOrbiterI) + RotL64(aOrbiterC, 37U)) + RotL64(aCarry, 3U)) + aPhaseFWandererUpdateSaltA[((aIndex + 26U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 38U) + RotL64(aOrbiterC, 3U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 51U) + aOrbiterD) + RotL64(aOrbiterG, 13U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterF, 24U)) + aOrbiterD);
            aWandererD = aWandererD + (((RotL64(aScatter, 35U) + RotL64(aOrbiterC, 51U)) + aOrbiterG) + RotL64(aCarry, 43U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterE, 21U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererE, 10U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererJ);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 18U));
            aCarry = aCarry + RotL64(aWandererB, 13U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ aNonceWordC;
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8439U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 6915U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 8120U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneB[((aIndex + 6278U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 26U) + RotL64(aPrevious, 41U)) + (RotL64(aCarry, 53U) ^ RotL64(aIngress, 11U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterF = (aWandererJ + RotL64(aScatter, 53U)) + 14214886793361825363U;
            aOrbiterA = (aWandererF + RotL64(aPrevious, 27U)) + 17267959031078766320U;
            aOrbiterC = (((aWandererC + RotL64(aIngress, 56U)) + RotL64(aCarry, 29U)) + 16436067429484887644U) + aNonceWordH;
            aOrbiterK = ((aWandererE + RotL64(aCross, 43U)) + 9885951769332633820U) + aPhaseFOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = (((aWandererB + RotL64(aPrevious, 19U)) + RotL64(aCarry, 19U)) + 12971711341813893304U) + aNonceWordD;
            aOrbiterJ = (aWandererG + RotL64(aCross, 35U)) + 199970353398450154U;
            aOrbiterD = ((aWandererA + RotL64(aScatter, 29U)) + 1237341696444162094U) + aPhaseFOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = (aWandererI + RotL64(aIngress, 3U)) + 7991128854417613360U;
            aOrbiterI = (aWandererK + RotL64(aScatter, 51U)) + 14809029847149045833U;
            aOrbiterG = ((aWandererH + RotL64(aCross, 47U)) + RotL64(aCarry, 23U)) + 2559509556915775947U;
            aOrbiterE = (aWandererD + RotL64(aPrevious, 12U)) + 14336829730147834160U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 8853631886733610440U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 13346159398673246914U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13660497151446983393U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 12121095718571872976U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 16239781125815589804U;
            aOrbiterA = RotL64((aOrbiterA * 5157009090454962231U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 9051377033794324106U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 13805815136723461780U;
            aOrbiterH = RotL64((aOrbiterH * 571129481747181357U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 14849157800322754413U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 18116651528452542634U;
            aOrbiterD = RotL64((aOrbiterD * 3638480428016835537U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 4105057226952948599U) + aNonceWordI;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 5911714320560994391U;
            aOrbiterI = RotL64((aOrbiterI * 1796514171654961389U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 4439149331729987587U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 10278532228230163632U;
            aOrbiterF = RotL64((aOrbiterF * 17428224919864716517U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 2342456582668741750U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 2360578572554664800U;
            aOrbiterK = RotL64((aOrbiterK * 1108428466956691925U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 12132934875391401246U) + aNonceWordF;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 17213278726790245812U;
            aOrbiterJ = RotL64((aOrbiterJ * 11904899990681410419U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 7994340481560109811U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 13735851271080138255U;
            aOrbiterB = RotL64((aOrbiterB * 12387076892129731557U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 6682417543888875268U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 15642799286975840550U;
            aOrbiterG = RotL64((aOrbiterG * 7861250716882028053U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 9839299346094784067U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 14214886793361825363U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2103132743364916037U), 5U);
            //
            aIngress = RotL64(aOrbiterC, 48U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterH, 23U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 27U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + (RotL64(aOrbiterK, 10U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterF, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aIngress, 30U) + RotL64(aOrbiterB, 10U)) + aOrbiterH) + RotL64(aCarry, 21U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterC, 5U)) + aOrbiterH);
            aWandererI = aWandererI + ((RotL64(aScatter, 5U) + RotL64(aOrbiterE, 27U)) + aOrbiterF);
            aWandererB = aWandererB ^ (((RotL64(aCross, 51U) + aOrbiterF) + RotL64(aOrbiterA, 21U)) + aNonceWordP);
            aWandererH = aWandererH + ((RotL64(aIngress, 57U) + aOrbiterH) + RotL64(aOrbiterG, 35U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 11U) + aOrbiterH) + RotL64(aOrbiterE, 47U)) + aPhaseFWandererUpdateSaltB[((aIndex + 28U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 41U) + aOrbiterI) + RotL64(aOrbiterF, 3U)) + RotL64(aCarry, 51U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterD, 29U)) + aOrbiterE);
            aWandererA = aWandererA + ((RotL64(aScatter, 47U) + RotL64(aOrbiterJ, 13U)) + aOrbiterD);
            aWandererD = aWandererD ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterK, 56U)) + aOrbiterC) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 44U) + RotL64(aOrbiterB, 41U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 44U) ^ aWandererH);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 51U));
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererC);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererD, 14U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 12790U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((aIndex + 14055U)) & S_BLOCK1], 30U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 15720U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 14971U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 41U) + RotL64(aCarry, 6U)) + (RotL64(aCross, 27U) ^ RotL64(aIngress, 53U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterH = (aWandererE + RotL64(aPrevious, 37U)) + 964165145848253292U;
            aOrbiterG = (aWandererD + RotL64(aCross, 57U)) + 10645976767204934746U;
            aOrbiterD = ((aWandererB + RotL64(aScatter, 53U)) + RotL64(aCarry, 37U)) + 8241612229349212650U;
            aOrbiterC = ((aWandererF + RotL64(aIngress, 43U)) + RotL64(aCarry, 29U)) + 4159196033256913347U;
            aOrbiterE = ((aWandererA + RotL64(aScatter, 18U)) + 7194795864620233507U) + aNonceWordJ;
            aOrbiterI = (aWandererC + RotL64(aPrevious, 21U)) + 7638928444536778384U;
            aOrbiterK = ((aWandererJ + RotL64(aCross, 5U)) + RotL64(aCarry, 41U)) + 11819105916503968109U;
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 35U)) + 18052213302858186237U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = (((aWandererH + RotL64(aPrevious, 3U)) + 8663575313970041570U) + aPhaseFOrbiterAssignSaltE[((aIndex + 22U)) & S_SALT1]) + aNonceWordP;
            aOrbiterB = (aWandererG + RotL64(aIngress, 41U)) + 16644136720439299786U;
            aOrbiterF = (aWandererK + RotL64(aScatter, 24U)) + 16930316530442679864U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 16251107616988250593U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 7171986193609401665U;
            aOrbiterD = RotL64((aOrbiterD * 3543709971414550087U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 17885046834432626644U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 7757069274715713557U;
            aOrbiterI = RotL64((aOrbiterI * 15766885299397923879U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 2212805322061155615U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 6368539134638838822U) ^ aNonceWordB;
            aOrbiterG = RotL64((aOrbiterG * 13383744883433594259U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 5264326094252925613U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 6126345334815012938U;
            aOrbiterE = RotL64((aOrbiterE * 17180934809764905307U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 13826731214018407061U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 6621261811613643620U) ^ aNonceWordM;
            aOrbiterJ = RotL64((aOrbiterJ * 2823596473596114171U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 5964406317285863781U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 2167324450276308078U;
            aOrbiterB = RotL64((aOrbiterB * 1098346374733634905U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 16740710162977859724U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 8236083581048717923U;
            aOrbiterH = RotL64((aOrbiterH * 4364887787000704039U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 13967473987446124012U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 5136051802217149813U;
            aOrbiterC = RotL64((aOrbiterC * 13997246005108872883U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 5842999397215390366U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 8621394946580065499U;
            aOrbiterK = RotL64((aOrbiterK * 11658023035736362355U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 18086875424872976900U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 7429246355923896047U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5077079237334961761U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 18123753993386959014U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterB) ^ 964165145848253292U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterF = RotL64((aOrbiterF * 3178072569980307307U), 27U);
            //
            aIngress = RotL64(aOrbiterD, 30U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterC, 21U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterA, 51U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + RotL64(aOrbiterF, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aPrevious, 30U) + RotL64(aOrbiterF, 23U)) + aOrbiterK) + RotL64(aCarry, 41U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 13U) + aOrbiterH) + RotL64(aOrbiterA, 50U));
            aWandererK = aWandererK + ((RotL64(aIngress, 19U) + RotL64(aOrbiterE, 3U)) + aOrbiterJ);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 21U) + aOrbiterE) + RotL64(aOrbiterD, 39U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aIngress, 35U) + aOrbiterH) + RotL64(aOrbiterI, 13U)) + RotL64(aCarry, 21U)) + aNonceWordN);
            aWandererE = aWandererE ^ ((RotL64(aCross, 53U) + aOrbiterA) + RotL64(aOrbiterK, 56U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterB, 43U)) + aOrbiterG) + aNonceWordH);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 51U) + aOrbiterC) + RotL64(aOrbiterH, 11U));
            aWandererG = aWandererG + ((RotL64(aCross, 5U) + RotL64(aOrbiterK, 53U)) + aOrbiterI);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterB, 41U)) + aOrbiterK);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 58U) + aOrbiterD) + RotL64(aOrbiterK, 47U)) + aNonceWordD) + aPhaseFWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererK);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 46U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 37U));
            aCarry = aCarry + (RotL64(aWandererE, 5U) ^ aWandererI);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + RotL64(aWandererG, 21U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordB);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 17449U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20808U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19010U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 17921U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 21U) + RotL64(aCarry, 5U)) + (RotL64(aPrevious, 57U) ^ RotL64(aCross, 36U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterF = ((aWandererG + RotL64(aCross, 3U)) + RotL64(aCarry, 41U)) + 6916817163240024692U;
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 34U)) + 14554930751292077817U) + aPhaseFOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = ((aWandererA + RotL64(aIngress, 21U)) + 1098305064484336101U) + aPhaseFOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = ((aWandererC + RotL64(aScatter, 47U)) + RotL64(aCarry, 47U)) + 12192821172420471527U;
            aOrbiterH = (aWandererD + RotL64(aPrevious, 41U)) + 2435134991707318845U;
            aOrbiterK = (aWandererI + RotL64(aScatter, 54U)) + 1896745368738512624U;
            aOrbiterC = (aWandererK + RotL64(aCross, 13U)) + 1114996424222923873U;
            aOrbiterD = (aWandererE + RotL64(aIngress, 39U)) + 9839135798371512656U;
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 5U)) + 8037967239603177043U) + aNonceWordI;
            aOrbiterE = ((aWandererH + RotL64(aIngress, 11U)) + RotL64(aCarry, 11U)) + 15185468738487237432U;
            aOrbiterB = (aWandererJ + RotL64(aScatter, 29U)) + 4912098316394854543U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 13142688607850380888U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 4507379759608945839U;
            aOrbiterA = RotL64((aOrbiterA * 2989332387754215967U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 7299006009652289342U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 5390655277207053627U;
            aOrbiterH = RotL64((aOrbiterH * 10973744708856143715U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 6744737023577785725U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 15539737698867067285U;
            aOrbiterK = RotL64((aOrbiterK * 4686092035261336911U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 13329866734681377952U) + aNonceWordM;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 13284937458969166257U;
            aOrbiterC = RotL64((aOrbiterC * 3965985432462699445U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 8695002088915702168U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 3858059421620839286U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9559783727301092937U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 6609163873243179836U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 9416165620556710540U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 240385043740268229U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 1578449067529000433U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 14309000104419489303U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7599078306153684729U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 15785180680737461320U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 10099222679918382021U;
            aOrbiterB = RotL64((aOrbiterB * 2012232597046182581U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 10666287769220108179U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 13648647399222807034U;
            aOrbiterF = RotL64((aOrbiterF * 10772381733103127201U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 9292207828896796810U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterE) ^ 9155130791347443553U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterG = RotL64((aOrbiterG * 16838229790655977057U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 11334395119119245556U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 6916817163240024692U;
            aOrbiterI = RotL64((aOrbiterI * 9640906826978028183U), 27U);
            //
            aIngress = RotL64(aOrbiterE, 51U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 5U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 56U));
            aIngress = aIngress + RotL64(aOrbiterI, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aCross, 57U) + RotL64(aOrbiterA, 43U)) + aOrbiterD) + aPhaseFWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 39U) + RotL64(aOrbiterI, 35U)) + aOrbiterG) + aNonceWordP);
            aWandererK = aWandererK + ((RotL64(aPrevious, 6U) + RotL64(aOrbiterB, 13U)) + aOrbiterE);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 53U) + aOrbiterK) + RotL64(aOrbiterJ, 60U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 29U) + aOrbiterI) + RotL64(aOrbiterE, 47U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 13U) + aOrbiterF) + RotL64(aOrbiterJ, 57U));
            aWandererE = aWandererE + (((RotL64(aIngress, 27U) + aOrbiterK) + RotL64(aOrbiterB, 29U)) + RotL64(aCarry, 57U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterG, 53U)) + aOrbiterF);
            aWandererF = aWandererF + ((RotL64(aIngress, 47U) + aOrbiterK) + RotL64(aOrbiterH, 18U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 36U) + RotL64(aOrbiterC, 39U)) + aOrbiterG) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterE, 51U)) + aOrbiterA) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 50U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererD);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 21U));
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererA, 4U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordD);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22495U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23858U)) & S_BLOCK1], 36U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25144U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26134U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 51U) ^ RotL64(aPrevious, 34U)) + (RotL64(aIngress, 3U) + RotL64(aCarry, 21U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterF = (aWandererE + RotL64(aScatter, 39U)) + 6163290588946759209U;
            aOrbiterG = (aWandererD + RotL64(aIngress, 3U)) + 7342672468560105447U;
            aOrbiterA = (aWandererJ + RotL64(aCross, 21U)) + 11574563167017282321U;
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 13U)) + 2254820206194758964U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = ((aWandererA + RotL64(aIngress, 43U)) + 1469783447473099498U) + aNonceWordM;
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 56U)) + 14174828900676165088U;
            aOrbiterD = (((aWandererH + RotL64(aCross, 53U)) + RotL64(aCarry, 47U)) + 16277954291890598132U) + aNonceWordE;
            aOrbiterK = ((((aWandererC + RotL64(aScatter, 19U)) + RotL64(aCarry, 41U)) + 14845750668693136766U) + aPhaseFOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1]) + aNonceWordC;
            aOrbiterH = (aWandererG + RotL64(aCross, 29U)) + 150099699692047766U;
            aOrbiterI = (aWandererF + RotL64(aPrevious, 11U)) + 1200784917165131703U;
            aOrbiterC = ((aWandererK + RotL64(aIngress, 58U)) + RotL64(aCarry, 23U)) + 9469982764806754302U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 10956702761701710182U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 7915506894975487807U;
            aOrbiterA = RotL64((aOrbiterA * 8874108311712727983U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 17335794183733623213U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 557028996286989506U) ^ aNonceWordL;
            aOrbiterJ = RotL64((aOrbiterJ * 3993359298602424281U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 1597385667771002414U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 4376417959915162639U;
            aOrbiterK = RotL64((aOrbiterK * 4626236858205178149U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 549770198518993876U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 756554555648070919U;
            aOrbiterI = RotL64((aOrbiterI * 16272320259614325355U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 7298557532533152193U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 3336802611342112013U;
            aOrbiterF = RotL64((aOrbiterF * 14679103452120080499U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 2314938232094714365U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 12215066333571149153U;
            aOrbiterE = RotL64((aOrbiterE * 10747052773052630601U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 7762752719356805046U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 6519429915769040078U;
            aOrbiterD = RotL64((aOrbiterD * 15548676502167938513U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 7556691736109752918U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 13731245903412646404U;
            aOrbiterH = RotL64((aOrbiterH * 15581965016668635409U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 5910925625723735162U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 16037704866415841869U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11628217027073824759U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 12605882248192797360U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 9579778913978981884U;
            aOrbiterG = RotL64((aOrbiterG * 5372577227818787957U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 6063171520266734946U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 6163290588946759209U;
            aOrbiterB = RotL64((aOrbiterB * 291843698316138251U), 27U);
            //
            aIngress = RotL64(aOrbiterC, 44U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 51U));
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 29U));
            aIngress = aIngress + (RotL64(aOrbiterH, 19U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterJ, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aIngress, 41U) + aOrbiterJ) + RotL64(aOrbiterK, 3U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 5U) + aOrbiterG) + RotL64(aOrbiterH, 51U)) + RotL64(aCarry, 27U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 57U) + aOrbiterE) + RotL64(aOrbiterK, 28U));
            aWandererF = aWandererF + ((((RotL64(aScatter, 53U) + RotL64(aOrbiterK, 47U)) + aOrbiterD) + RotL64(aCarry, 43U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 38U) + aOrbiterF) + RotL64(aOrbiterE, 21U)) + aNonceWordI);
            aWandererE = aWandererE + ((RotL64(aIngress, 27U) + RotL64(aOrbiterC, 57U)) + aOrbiterK);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 21U) + aOrbiterH) + RotL64(aOrbiterD, 39U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 47U) + aOrbiterG) + RotL64(aOrbiterC, 19U)) + aPhaseFWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 43U) + aOrbiterC) + RotL64(aOrbiterI, 24U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 3U) + aOrbiterB) + RotL64(aOrbiterI, 5U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 30U) + aOrbiterJ) + RotL64(aOrbiterA, 37U)) + aNonceWordN);
            //
            aCarry = aCarry + (RotL64(aWandererK, 21U) ^ aWandererJ);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + (RotL64(aWandererE, 48U) ^ aWandererH);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 41U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + RotL64(aWandererC, 53U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ aNonceWordF;
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 31165U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneB[((aIndex + 29649U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32204U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32365U)) & S_BLOCK1], 24U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aPrevious, 3U)) + (RotL64(aIngress, 34U) ^ RotL64(aCross, 19U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterG = ((aWandererG + RotL64(aScatter, 19U)) + 12632404972795375757U) + aNonceWordF;
            aOrbiterI = (aWandererF + RotL64(aCross, 34U)) + 5351879979055988456U;
            aOrbiterB = (((aWandererD + RotL64(aPrevious, 29U)) + RotL64(aCarry, 53U)) + 3597737727467443413U) + aNonceWordI;
            aOrbiterA = (aWandererJ + RotL64(aIngress, 13U)) + 2830846754917852318U;
            aOrbiterC = (aWandererH + RotL64(aCross, 11U)) + 17311925960294518018U;
            aOrbiterD = (aWandererK + RotL64(aScatter, 21U)) + 2083584640523695383U;
            aOrbiterH = ((aWandererC + RotL64(aIngress, 23U)) + RotL64(aCarry, 57U)) + 15049343611387010158U;
            aOrbiterK = (aWandererI + RotL64(aPrevious, 5U)) + 6443050378205811147U;
            aOrbiterF = (((aWandererB + RotL64(aCross, 51U)) + RotL64(aCarry, 3U)) + 6021965178697344070U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 60U)) + 5080289878758029976U) + aPhaseFOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = (aWandererE + RotL64(aScatter, 41U)) + 576927745306972983U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 4728489691382690859U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 6184355840165758855U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1515043910404156423U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 11220539885798595450U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 11091438724966718214U;
            aOrbiterC = RotL64((aOrbiterC * 8225347114759391961U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 17184210490020062419U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 2150997767099116408U;
            aOrbiterD = RotL64((aOrbiterD * 8058553821648892499U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 7021953562676903717U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 17159676348343312834U;
            aOrbiterH = RotL64((aOrbiterH * 13877284519668483549U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 10367891770525239784U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 11922478487264201233U;
            aOrbiterK = RotL64((aOrbiterK * 9195137452661956029U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 17815162358981720634U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 9582631251085100284U;
            aOrbiterF = RotL64((aOrbiterF * 11838992994130850483U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 872593750259572264U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 17832330100262167302U;
            aOrbiterE = RotL64((aOrbiterE * 1114416841510028467U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 16601139856969287418U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 14931287111691324985U) ^ aNonceWordO;
            aOrbiterJ = RotL64((aOrbiterJ * 16757174577841001179U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 11413072442039115924U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 15253605470589905889U;
            aOrbiterG = RotL64((aOrbiterG * 10832817442285245673U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 3653487723581514107U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 14891378240114471865U;
            aOrbiterI = RotL64((aOrbiterI * 1386594204573386051U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 15659724464711852035U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 12632404972795375757U;
            aOrbiterA = RotL64((aOrbiterA * 2407347385127296647U), 3U);
            //
            aIngress = RotL64(aOrbiterG, 3U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 35U));
            aIngress = aIngress + (RotL64(aOrbiterK, 21U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterB, 19U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 30U));
            aIngress = aIngress + RotL64(aOrbiterH, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterB, 51U)) + aOrbiterC);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 60U) + RotL64(aOrbiterK, 11U)) + aOrbiterA) + RotL64(aCarry, 3U)) + aNonceWordK);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 5U) + aOrbiterB) + RotL64(aOrbiterG, 41U));
            aWandererG = aWandererG + ((RotL64(aScatter, 39U) + aOrbiterC) + RotL64(aOrbiterK, 30U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterB, 19U)) + aOrbiterH);
            aWandererF = aWandererF + ((RotL64(aPrevious, 11U) + aOrbiterE) + RotL64(aOrbiterC, 35U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 14U) + RotL64(aOrbiterA, 43U)) + aOrbiterF) + aPhaseFWandererUpdateSaltD[((aIndex + 18U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 35U) + RotL64(aOrbiterB, 37U)) + aOrbiterE) + RotL64(aCarry, 53U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 23U) + aOrbiterJ) + RotL64(aOrbiterA, 22U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterE, 57U)) + aOrbiterD) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 53U) + aOrbiterI) + RotL64(aOrbiterH, 39U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 48U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 21U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererH, 56U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordC);
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

void TwistExpander_WaterPolo_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x84D8BDFCC3F20F71ULL + 0xA578A5AA7DF1DB92ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xC0623F15681A9F2BULL + 0xD57584D82BAF5BF9ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xFF921426D7C12181ULL + 0x99DDDA1BA901D692ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x8AC9D7905583EFD7ULL + 0x91157C208652242FULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xF0EC8F284D34F591ULL + 0xE329C2E0A35063BBULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xBD4195B457A2729FULL + 0x8C5104E7A05572F3ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xFE0016EC820CF883ULL + 0xA39BA50D994D9813ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xE0F9431077CF3199ULL + 0xB90F6651190D1520ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xF590B41EAD8DF297ULL + 0xDADBC85D1615C704ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xB580D060CD722899ULL + 0xB64839B1A262624CULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xC0C6AD579606BB7FULL + 0xB5E0F78AE62F518AULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x96AA6B331FF7289DULL + 0xA81D1DEB0965E3BBULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xDA506BFAF94A2293ULL + 0xFC88901D81926DF2ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xDF5E5EE47B4E0CE3ULL + 0xE9766C846FC5C1F8ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xD19F25F499145423ULL + 0x83DD41905ED06007ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xA546D8548CDFB8ABULL + 0xC748D798B533FE9DULL);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 5067U)) & S_BLOCK1], 6U) ^ RotL64(aWorkLaneC[((aIndex + 4032U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 3208U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((aIndex + 5035U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 6U) ^ RotL64(aIngress, 41U)) ^ (RotL64(aCross, 27U) + RotL64(aPrevious, 53U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterF = (aWandererG + RotL64(aScatter, 18U)) + 13960289014350612206U;
            aOrbiterK = ((aWandererB + RotL64(aIngress, 37U)) + 3483331015269589730U) + aNonceWordE;
            aOrbiterI = ((aWandererI + RotL64(aCross, 13U)) + RotL64(aCarry, 41U)) + 6873299241002444518U;
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 43U)) + 3562094007125534229U) + aPhaseFOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = (aWandererA + RotL64(aCross, 23U)) + 11422367439932782705U;
            aOrbiterH = (((aWandererC + RotL64(aScatter, 53U)) + RotL64(aCarry, 51U)) + 532453428514259816U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = (aWandererJ + RotL64(aPrevious, 35U)) + 17810941465810193088U;
            aOrbiterD = (aWandererE + RotL64(aIngress, 41U)) + 11869759058631106331U;
            aOrbiterE = (aWandererK + RotL64(aCross, 50U)) + 8837581071876177566U;
            aOrbiterA = ((aWandererD + RotL64(aIngress, 29U)) + RotL64(aCarry, 13U)) + 17185378327053837778U;
            aOrbiterC = (aWandererH + RotL64(aPrevious, 11U)) + 7578253375676981500U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 17112646434432814442U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 14949096407295697881U;
            aOrbiterI = RotL64((aOrbiterI * 14770977858283051753U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 4259590620758467836U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 6534899413644542303U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7987609419215568661U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 2637407498893694243U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 15819295597921425711U;
            aOrbiterF = RotL64((aOrbiterF * 5202015597375051399U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 6373559542002699718U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 11694562937392022505U) ^ aNonceWordK;
            aOrbiterB = RotL64((aOrbiterB * 9311557972331218597U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 3308736483775453062U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 12749929710650475901U;
            aOrbiterJ = RotL64((aOrbiterJ * 248428400724560945U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 1569528215675579656U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 1044077933631689572U) ^ aNonceWordC;
            aOrbiterE = RotL64((aOrbiterE * 6443796233912755143U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 8393422728124537471U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 2002732612516530754U;
            aOrbiterC = RotL64((aOrbiterC * 13702146823622364279U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 13469191942843147943U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 7633171368709520560U;
            aOrbiterK = RotL64((aOrbiterK * 9713514012478203047U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 4023206337737491091U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 15990323932023596968U;
            aOrbiterG = RotL64((aOrbiterG * 4816480271959713463U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 837005729394899591U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 9692088757104339973U;
            aOrbiterD = RotL64((aOrbiterD * 17971548293495807419U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 18039464962413134616U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 13960289014350612206U) ^ aNonceWordJ;
            aOrbiterA = RotL64((aOrbiterA * 931609478642506411U), 51U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterE, 5U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 3U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 14U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterA, 11U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterG, 35U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterB, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterA, 21U)) + aOrbiterJ);
            aWandererE = aWandererE + (((RotL64(aPrevious, 14U) + RotL64(aOrbiterF, 11U)) + aOrbiterI) + aPhaseFWandererUpdateSaltA[((aIndex + 26U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 21U) + aOrbiterB) + RotL64(aOrbiterD, 3U));
            aWandererF = aWandererF + ((RotL64(aCross, 41U) + aOrbiterJ) + RotL64(aOrbiterI, 23U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterE, 46U)) + aOrbiterK);
            aWandererB = aWandererB + (((RotL64(aCross, 57U) + RotL64(aOrbiterA, 53U)) + aOrbiterK) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 39U) + aOrbiterE) + RotL64(aOrbiterC, 5U));
            aWandererC = aWandererC + ((((RotL64(aScatter, 29U) + aOrbiterH) + RotL64(aOrbiterD, 39U)) + RotL64(aCarry, 39U)) + aNonceWordA);
            aWandererD = aWandererD ^ ((RotL64(aCross, 36U) + aOrbiterH) + RotL64(aOrbiterF, 35U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 47U) + aOrbiterC) + RotL64(aOrbiterJ, 28U)) + RotL64(aCarry, 11U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 19U) + aOrbiterA) + RotL64(aOrbiterG, 57U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 21U));
            aCarry = aCarry + (RotL64(aWandererH, 53U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererE, 58U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererC, 5U);
            aCarry = aCarry + RotL64(aIngress, 46U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordP);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 7938U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneD[((aIndex + 10407U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 8935U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((aIndex + 9178U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 40U) + RotL64(aCarry, 27U)) ^ (RotL64(aCross, 5U) ^ RotL64(aIngress, 53U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = (aWandererC + RotL64(aCross, 11U)) + 9774364261626083532U;
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 6U)) + RotL64(aCarry, 13U)) + 18059001521926116420U;
            aOrbiterD = (aWandererF + RotL64(aIngress, 19U)) + 10615626210406381148U;
            aOrbiterH = (aWandererD + RotL64(aPrevious, 35U)) + 10536484278007898620U;
            aOrbiterJ = (aWandererA + RotL64(aIngress, 27U)) + 13320663045139972700U;
            aOrbiterI = (aWandererE + RotL64(aScatter, 51U)) + 17127001787268166583U;
            aOrbiterB = (aWandererB + RotL64(aCross, 56U)) + 16742574590844166551U;
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 29U)) + 8347719720758228053U) + aPhaseFOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = (aWandererI + RotL64(aCross, 21U)) + 13502468705946051986U;
            aOrbiterG = ((((aWandererK + RotL64(aIngress, 53U)) + RotL64(aCarry, 53U)) + 3512687886188904904U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordG;
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 47U)) + RotL64(aCarry, 3U)) + 495660316165795934U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 5092722552034477356U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 15641128019608284015U;
            aOrbiterD = RotL64((aOrbiterD * 3621036395703527059U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 15421873776811085458U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 17978775513204574125U;
            aOrbiterF = RotL64((aOrbiterF * 18359600395119440183U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 16617179197537669849U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 1931805387534012528U;
            aOrbiterJ = RotL64((aOrbiterJ * 3400139345857733775U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 9544923119559308431U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 12930999400470173353U;
            aOrbiterB = RotL64((aOrbiterB * 16791006919271490005U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 13673733276226249890U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 2032263473309124738U;
            aOrbiterC = RotL64((aOrbiterC * 3088728329261360607U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 14868502349358414206U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 10116495537187552321U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1380512121796709469U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 5341113995358179244U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 8415417980279705731U;
            aOrbiterH = RotL64((aOrbiterH * 8521501372683793821U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 2462819265072352463U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 7657062767608441931U;
            aOrbiterI = RotL64((aOrbiterI * 15554638801273540163U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 8153420530633265789U) + aNonceWordC;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 10990681417675210534U;
            aOrbiterK = RotL64((aOrbiterK * 1928509513380702895U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 17035995983178569271U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 2806563871848226777U;
            aOrbiterG = RotL64((aOrbiterG * 4137935663733587867U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 6570698907081812011U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 9774364261626083532U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1766375419340392741U), 51U);
            //
            aIngress = RotL64(aOrbiterD, 35U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 46U));
            aIngress = aIngress + (RotL64(aOrbiterG, 37U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterF, 13U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterC, 23U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterB, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 14U) + aOrbiterK) + RotL64(aOrbiterF, 27U));
            aWandererB = aWandererB + ((((RotL64(aIngress, 19U) + RotL64(aOrbiterE, 38U)) + aOrbiterJ) + RotL64(aCarry, 21U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 21U) + aOrbiterI) + RotL64(aOrbiterD, 5U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterG, 47U)) + aOrbiterA) + aNonceWordE);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 53U) + aOrbiterJ) + RotL64(aOrbiterB, 11U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 3U) + aOrbiterH) + RotL64(aOrbiterJ, 19U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 51U) + aOrbiterG) + RotL64(aOrbiterB, 43U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 27U) + aOrbiterK) + RotL64(aOrbiterB, 29U)) + RotL64(aCarry, 43U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 29U) + aOrbiterC) + RotL64(aOrbiterI, 51U));
            aWandererC = aWandererC + ((RotL64(aIngress, 46U) + aOrbiterB) + RotL64(aOrbiterC, 35U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 11U) + aOrbiterD) + RotL64(aOrbiterB, 14U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 60U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + (RotL64(aWandererJ, 56U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererG, 41U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordC);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 13312U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneA[((aIndex + 14660U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 15739U)) & S_BLOCK1], 46U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 13134U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCross, 36U)) ^ (RotL64(aCarry, 21U) + RotL64(aIngress, 5U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterG = (aWandererK + RotL64(aScatter, 23U)) + 8685374557928800912U;
            aOrbiterD = ((aWandererB + RotL64(aIngress, 34U)) + 3482312691892161229U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 41U)) + RotL64(aCarry, 35U)) + 6948130297389161165U;
            aOrbiterJ = ((aWandererD + RotL64(aCross, 11U)) + 5506385663788942690U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = ((aWandererI + RotL64(aScatter, 19U)) + RotL64(aCarry, 53U)) + 17859982009307397161U;
            aOrbiterA = ((aWandererH + RotL64(aCross, 44U)) + RotL64(aCarry, 23U)) + 9178488809207094043U;
            aOrbiterC = (aWandererE + RotL64(aIngress, 57U)) + 1835479501226057169U;
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 47U)) + 5368101733632614939U) + aNonceWordJ;
            aOrbiterI = (aWandererJ + RotL64(aIngress, 5U)) + 9050459666576835422U;
            aOrbiterE = ((aWandererF + RotL64(aCross, 13U)) + 9042186993119635078U) + aNonceWordE;
            aOrbiterF = ((aWandererC + RotL64(aScatter, 21U)) + 17528342580198295025U) + aNonceWordP;
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 6495418332558436882U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 8834495762667327342U) ^ aNonceWordF;
            aOrbiterH = RotL64((aOrbiterH * 10783141541937645995U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 4364314196965690905U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 6357485231062120459U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 289429584586504995U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 3321488322626415347U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 10817330671781848737U;
            aOrbiterD = RotL64((aOrbiterD * 15875919466358823335U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 17974092279281611763U) + aNonceWordD;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 2871472057292789157U;
            aOrbiterB = RotL64((aOrbiterB * 16104199340711015181U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 15187929795092006849U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 13482063681546475923U;
            aOrbiterK = RotL64((aOrbiterK * 14466266308157364963U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 6232152545071397380U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 17488906002621373262U;
            aOrbiterE = RotL64((aOrbiterE * 4719340606442742577U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 12444819880507588549U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 13808941689757772497U;
            aOrbiterG = RotL64((aOrbiterG * 6541360905282412317U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 8049361354387692374U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 7137831335606542401U;
            aOrbiterJ = RotL64((aOrbiterJ * 11022231291507235007U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 7230759462019420058U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 3923744511976096944U;
            aOrbiterC = RotL64((aOrbiterC * 9953869624243563101U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 15967667946023263856U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 8677583624693910669U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10737731876339973717U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 1604347321263511013U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 8685374557928800912U;
            aOrbiterF = RotL64((aOrbiterF * 14103365695918844461U), 37U);
            //
            aIngress = RotL64(aOrbiterE, 11U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterA, 47U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 24U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 39U));
            aIngress = aIngress + (RotL64(aOrbiterB, 53U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterF, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aScatter, 41U) + aOrbiterK) + RotL64(aOrbiterB, 38U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 57U) + aOrbiterB) + RotL64(aOrbiterF, 43U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 43U) + aOrbiterE) + RotL64(aOrbiterA, 11U)) + RotL64(aCarry, 39U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterJ, 5U)) + aOrbiterC);
            aWandererC = aWandererC + (((RotL64(aScatter, 53U) + RotL64(aOrbiterH, 27U)) + aOrbiterG) + RotL64(aCarry, 11U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterI, 35U)) + aOrbiterG) + aNonceWordM);
            aWandererK = aWandererK + (((RotL64(aPrevious, 39U) + aOrbiterA) + RotL64(aOrbiterD, 21U)) + aNonceWordO);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterB, 13U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 29U) + RotL64(aOrbiterK, 53U)) + aOrbiterI);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 36U) + aOrbiterK) + RotL64(aOrbiterE, 56U));
            aWandererF = aWandererF + (((RotL64(aCross, 27U) + aOrbiterE) + RotL64(aOrbiterF, 3U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 41U) ^ aWandererK);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 5U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 54U));
            aCarry = aCarry + (RotL64(aWandererC, 43U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererD, 51U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordE);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 19111U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 21135U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 20058U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneD[((aIndex + 17013U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 36U) + RotL64(aCarry, 19U)) ^ (RotL64(aCross, 5U) + RotL64(aIngress, 57U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterG = (((aWandererE + RotL64(aIngress, 43U)) + RotL64(aCarry, 57U)) + 701291026547470433U) + aNonceWordC;
            aOrbiterE = (aWandererF + RotL64(aPrevious, 34U)) + 17283292650462111643U;
            aOrbiterH = (aWandererI + RotL64(aScatter, 5U)) + 9969124091931303406U;
            aOrbiterD = ((aWandererD + RotL64(aCross, 11U)) + 889176772718046988U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = (aWandererH + RotL64(aScatter, 37U)) + 6054541844643748084U;
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 39U)) + 14703226235143028132U;
            aOrbiterA = ((aWandererK + RotL64(aCross, 52U)) + RotL64(aCarry, 37U)) + 7977975878522921062U;
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 23U)) + 16894322614172266274U) + aNonceWordO;
            aOrbiterC = ((aWandererG + RotL64(aPrevious, 27U)) + RotL64(aCarry, 19U)) + 12160451749345900570U;
            aOrbiterI = ((aWandererA + RotL64(aCross, 57U)) + 10870847008043897470U) + aPhaseFOrbiterAssignSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = (aWandererC + RotL64(aScatter, 41U)) + 8159920947172520247U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 2440099120969517932U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 2428396147731468007U;
            aOrbiterH = RotL64((aOrbiterH * 9363073341539598441U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 2213226274394673479U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 7079731443427765333U;
            aOrbiterK = RotL64((aOrbiterK * 16918930776877030559U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 958896789550478970U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 10788682955708075458U;
            aOrbiterJ = RotL64((aOrbiterJ * 913321215613559729U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 2003386579317564870U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 8419686358774204999U) ^ aNonceWordH;
            aOrbiterA = RotL64((aOrbiterA * 6547052526438697621U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 6989167615157578904U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 17636634003643824148U;
            aOrbiterF = RotL64((aOrbiterF * 11038576417283732937U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 13824962118933907859U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 9543912892587859646U;
            aOrbiterC = RotL64((aOrbiterC * 14736710162285997415U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 15729878041027706114U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 9542137475454825463U;
            aOrbiterI = RotL64((aOrbiterI * 11420547128115090491U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 5327302277575009955U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 2707383132257428583U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6120763309390182129U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 9008601903853562620U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 11050463189491777908U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9178386878636430553U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 14683684132116778056U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 5390271065690907120U;
            aOrbiterE = RotL64((aOrbiterE * 17903005409098232619U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 5183407290520277451U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 701291026547470433U;
            aOrbiterD = RotL64((aOrbiterD * 16329261100139524239U), 43U);
            //
            aIngress = RotL64(aOrbiterK, 34U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterG, 39U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 57U));
            aIngress = aIngress + (RotL64(aOrbiterA, 41U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 43U));
            aIngress = aIngress + RotL64(aOrbiterF, 48U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterC, 11U)) + aOrbiterF);
            aWandererB = aWandererB + (((RotL64(aIngress, 43U) + aOrbiterJ) + RotL64(aOrbiterA, 53U)) + RotL64(aCarry, 3U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 56U) + aOrbiterA) + RotL64(aOrbiterI, 14U));
            aWandererK = aWandererK + ((RotL64(aCross, 27U) + aOrbiterG) + RotL64(aOrbiterC, 37U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterD, 5U)) + aOrbiterB) + aNonceWordF);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 5U) + aOrbiterB) + RotL64(aOrbiterK, 19U)) + RotL64(aCarry, 37U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterI, 47U)) + aOrbiterJ);
            aWandererF = aWandererF + ((RotL64(aCross, 29U) + RotL64(aOrbiterA, 24U)) + aOrbiterH);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 54U) + aOrbiterK) + RotL64(aOrbiterG, 57U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 13U) + RotL64(aOrbiterE, 39U)) + aOrbiterA) + aPhaseFWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterJ, 27U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererC, 4U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererH);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (RotL64(aWandererG, 20U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererE, 57U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordO);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22544U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneA[((aIndex + 23718U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 26768U)) & S_BLOCK1], 28U) ^ RotL64(aOperationLaneA[((aIndex + 27203U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 18U) ^ RotL64(aIngress, 41U)) + (RotL64(aCarry, 57U) + RotL64(aPrevious, 5U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterB = ((aWandererH + RotL64(aIngress, 39U)) + RotL64(aCarry, 47U)) + 2571116506511057880U;
            aOrbiterC = (aWandererA + RotL64(aCross, 3U)) + 13112435411509707292U;
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 21U)) + 10403251762787357256U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = (aWandererE + RotL64(aScatter, 37U)) + 8461951095541400405U;
            aOrbiterF = ((aWandererJ + RotL64(aCross, 26U)) + RotL64(aCarry, 21U)) + 9890793478557463815U;
            aOrbiterH = (aWandererG + RotL64(aPrevious, 19U)) + 3030229465991783707U;
            aOrbiterD = ((aWandererC + RotL64(aIngress, 23U)) + 7273848154043719247U) + aNonceWordP;
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 51U)) + 10681774862516028276U) + aNonceWordL;
            aOrbiterK = (aWandererD + RotL64(aIngress, 47U)) + 7105082755586853104U;
            aOrbiterA = (((aWandererI + RotL64(aPrevious, 41U)) + RotL64(aCarry, 37U)) + 6588579345319551129U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = (aWandererF + RotL64(aScatter, 60U)) + 14616333550242386092U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 15439666290229654921U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 3360304356760164799U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5164191920584106237U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 14438730801970761889U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 14515616787452085729U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2041601927968559821U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 4167853822635132419U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 8950982233003320239U;
            aOrbiterJ = RotL64((aOrbiterJ * 887144270884244907U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 12391327853728029953U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 7100871010552394421U;
            aOrbiterA = RotL64((aOrbiterA * 16552349374101955967U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 15381697462381887944U) + aNonceWordN;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 6801677551341079401U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13325954438427340703U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 947011315719204867U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 6356920162398333481U;
            aOrbiterG = RotL64((aOrbiterG * 5566721941682667419U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 8910262020598577378U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 8778455415977526457U;
            aOrbiterD = RotL64((aOrbiterD * 4092470497616637283U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 5585696961453127223U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 9670655481681494412U;
            aOrbiterK = RotL64((aOrbiterK * 7863197168965036383U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 10713004007087085729U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 4036355047492922339U;
            aOrbiterI = RotL64((aOrbiterI * 6923922258047667173U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 14580156873863533497U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 7049502932205025182U;
            aOrbiterC = RotL64((aOrbiterC * 8665428649262370727U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 12707521269341941677U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 2571116506511057880U;
            aOrbiterF = RotL64((aOrbiterF * 2388236789245943699U), 5U);
            //
            aIngress = RotL64(aOrbiterG, 10U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 35U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 5U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterC, 29U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + RotL64(aOrbiterB, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterJ, 37U)) + aOrbiterA);
            aWandererG = aWandererG + ((RotL64(aPrevious, 57U) + aOrbiterH) + RotL64(aOrbiterK, 46U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterF, 13U)) + aOrbiterC);
            aWandererA = aWandererA + (((RotL64(aScatter, 6U) + aOrbiterJ) + RotL64(aOrbiterH, 57U)) + RotL64(aCarry, 3U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 23U) + aOrbiterK) + RotL64(aOrbiterE, 3U)) + aNonceWordF);
            aWandererF = aWandererF + ((RotL64(aCross, 47U) + RotL64(aOrbiterI, 43U)) + aOrbiterG);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 19U) + aOrbiterG) + RotL64(aOrbiterB, 27U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterD, 23U)) + aPhaseFWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 27U) + aOrbiterB) + RotL64(aOrbiterK, 19U)) + aNonceWordI);
            aWandererI = aWandererI + (((RotL64(aPrevious, 14U) + RotL64(aOrbiterE, 11U)) + aOrbiterG) + RotL64(aCarry, 11U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 11U) + aOrbiterF) + RotL64(aOrbiterE, 40U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 60U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererI, 37U) ^ aWandererK);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 12U));
            aCarry = aCarry + RotL64(aWandererC, 57U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ aNonceWordK;
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 28364U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((aIndex + 29473U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31415U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneB[((aIndex + 32525U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 54U) + RotL64(aCarry, 3U)) ^ (RotL64(aCross, 19U) + RotL64(aIngress, 41U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterA = (aWandererB + RotL64(aPrevious, 21U)) + 479672811032092393U;
            aOrbiterI = ((aWandererG + RotL64(aIngress, 48U)) + RotL64(aCarry, 53U)) + 18061121631394564425U;
            aOrbiterF = ((aWandererK + RotL64(aCross, 43U)) + 14237400452740566065U) + aNonceWordF;
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 41U)) + 6723123812257706134U) + aPhaseFOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = (aWandererD + RotL64(aIngress, 51U)) + 4247997188026499248U;
            aOrbiterE = ((aWandererE + RotL64(aCross, 27U)) + RotL64(aCarry, 37U)) + 1939107415066134869U;
            aOrbiterC = (aWandererH + RotL64(aPrevious, 29U)) + 3912640123546395979U;
            aOrbiterD = (((aWandererF + RotL64(aScatter, 56U)) + RotL64(aCarry, 5U)) + 8295478436553964298U) + aPhaseFOrbiterAssignSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterK = (aWandererA + RotL64(aIngress, 5U)) + 3218960600711526885U;
            aOrbiterH = (aWandererC + RotL64(aCross, 13U)) + 5874096203353388890U;
            aOrbiterB = (aWandererJ + RotL64(aPrevious, 23U)) + 10294536533673023358U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 11268561953904130747U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 16693201256788898423U) ^ aNonceWordC;
            aOrbiterF = RotL64((aOrbiterF * 16291987237693567209U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 7550969634681894654U) + aNonceWordI;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 9501647424602245869U;
            aOrbiterG = RotL64((aOrbiterG * 11265865222096866605U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 8881869255994319423U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 16770136406906800016U;
            aOrbiterE = RotL64((aOrbiterE * 1782039587385512923U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 16185384746435761363U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 13841034186650721627U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12000155593277035447U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 15229062695864608309U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 3576122704615303733U;
            aOrbiterD = RotL64((aOrbiterD * 2433987493885779279U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 13898167174453181224U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 12878032061609524049U;
            aOrbiterK = RotL64((aOrbiterK * 18104665741338251495U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 12719156051299028649U) + aNonceWordK;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 8640980843376950769U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10242616778390983333U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 12133332160916004365U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 8743563985229104484U;
            aOrbiterB = RotL64((aOrbiterB * 4575129690615054691U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 7362223873479167793U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 4230720394788635807U;
            aOrbiterA = RotL64((aOrbiterA * 3658720603716856293U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 5095842824285329272U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 7483469517256234638U;
            aOrbiterI = RotL64((aOrbiterI * 9782114499878763883U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 17426017004856399653U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 479672811032092393U;
            aOrbiterJ = RotL64((aOrbiterJ * 14921028515589317919U), 51U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterJ, 13U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 37U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 23U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 35U));
            aIngress = aIngress + (RotL64(aOrbiterB, 26U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterF, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aScatter, 39U) + RotL64(aOrbiterE, 26U)) + aOrbiterB) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 51U) + aOrbiterI) + RotL64(aOrbiterA, 11U));
            aWandererB = aWandererB + ((((RotL64(aPrevious, 18U) + RotL64(aOrbiterH, 5U)) + aOrbiterK) + RotL64(aCarry, 3U)) + aPhaseFWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterC, 13U)) + aOrbiterE);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 37U) + RotL64(aOrbiterG, 19U)) + aOrbiterD);
            aWandererI = aWandererI ^ ((RotL64(aCross, 27U) + aOrbiterJ) + RotL64(aOrbiterC, 29U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 47U) + aOrbiterF) + RotL64(aOrbiterA, 37U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 53U) + aOrbiterB) + RotL64(aOrbiterC, 23U)) + aNonceWordA);
            aWandererK = aWandererK + (((RotL64(aCross, 3U) + RotL64(aOrbiterA, 34U)) + aOrbiterD) + RotL64(aCarry, 27U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 57U) + aOrbiterG) + RotL64(aOrbiterA, 43U)) + aNonceWordM);
            aWandererD = aWandererD + (((RotL64(aPrevious, 12U) + aOrbiterJ) + RotL64(aOrbiterK, 21U)) + aNonceWordD);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 44U));
            aCarry = aCarry + (RotL64(aWandererB, 13U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererC, 23U);
            aCarry = aCarry + RotL64(aIngress, 46U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordI);
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

void TwistExpander_WaterPolo_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 5772U)) & S_BLOCK1], 22U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 465U)) & W_KEY1], 57U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 6121U)) & W_KEY1], 6U) ^ RotL64(mSource[((aIndex + 1851U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 58U)) + (RotL64(aIngress, 11U) + RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = (aWandererD + RotL64(aPrevious, 12U)) + 4848316479321533394U;
            aOrbiterD = (((aWandererG + RotL64(aIngress, 5U)) + RotL64(aCarry, 19U)) + 6919360256662636195U) + aPhaseCOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = (aWandererH + RotL64(aScatter, 53U)) + 9897013582181108544U;
            aOrbiterE = (aWandererJ + RotL64(aCross, 47U)) + 7319353809896158678U;
            aOrbiterH = (aWandererA + RotL64(aIngress, 20U)) + 2848175435514849859U;
            aOrbiterA = (aWandererI + RotL64(aPrevious, 37U)) + 6967780718720437934U;
            aOrbiterF = ((aWandererB + RotL64(aCross, 29U)) + RotL64(aCarry, 51U)) + 10143884766603388136U;
            aOrbiterI = ((aWandererK + RotL64(aScatter, 57U)) + RotL64(aCarry, 35U)) + 8675965006150972051U;
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 41U)) + 16350117755560994281U) + aPhaseCOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 17976597517118423760U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 1399631141355370237U;
            aOrbiterC = RotL64((aOrbiterC * 16537788276543236833U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 3590613762034716792U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 5134624314245932157U;
            aOrbiterA = RotL64((aOrbiterA * 13077589037975283371U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 10082236952942943654U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 4015535035905433450U;
            aOrbiterI = RotL64((aOrbiterI * 4961808568701908559U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 611474103801573800U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 5786708483794098001U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7694007039340089267U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 5201943497363274455U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 9282160506938328489U;
            aOrbiterK = RotL64((aOrbiterK * 5368182164239021367U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 4932320527498940158U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 11576526341731392916U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1712051774729439363U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 10790691517638887125U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 16280649213607464422U;
            aOrbiterF = RotL64((aOrbiterF * 10756733801499471873U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 9553716940667712810U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 11827518270964003341U;
            aOrbiterD = RotL64((aOrbiterD * 1322489827908132831U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 16777463701235809321U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 3375489084588454149U;
            aOrbiterH = RotL64((aOrbiterH * 3335010977457647307U), 5U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterI, 6U);
            aIngress = aIngress + (RotL64(aOrbiterH, 51U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterJ, 43U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterE, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 56U) + RotL64(aOrbiterC, 36U)) + aOrbiterJ);
            aWandererA = aWandererA + (((RotL64(aCross, 39U) + RotL64(aOrbiterH, 51U)) + aOrbiterE) + RotL64(aCarry, 41U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 19U) + aOrbiterI) + RotL64(aOrbiterA, 47U));
            aWandererH = aWandererH + ((RotL64(aIngress, 3U) + RotL64(aOrbiterC, 29U)) + aOrbiterE);
            aWandererD = aWandererD ^ ((RotL64(aCross, 27U) + aOrbiterI) + RotL64(aOrbiterK, 12U));
            aWandererG = aWandererG + ((((RotL64(aScatter, 60U) + aOrbiterF) + RotL64(aOrbiterK, 57U)) + RotL64(aCarry, 11U)) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterD, 5U)) + aOrbiterK);
            aWandererB = aWandererB + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterJ, 19U)) + aOrbiterF) + aPhaseCWandererUpdateSaltB[((aIndex + 4U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 13U) + aOrbiterA) + RotL64(aOrbiterK, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 60U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererI);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 19U));
            aCarry = aCarry + RotL64(aWandererK, 29U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 13759U)) & S_BLOCK1], 57U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 10718U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15119U)) & W_KEY1], 23U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 14096U)) & W_KEY1], 38U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 51U) + RotL64(aPrevious, 21U)) ^ (RotL64(aIngress, 4U) ^ RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = (aWandererJ + RotL64(aIngress, 11U)) + 4259993311776766595U;
            aOrbiterA = (aWandererC + RotL64(aPrevious, 54U)) + 2857813330021126753U;
            aOrbiterB = ((aWandererB + RotL64(aScatter, 3U)) + 1345396841329442896U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = ((aWandererK + RotL64(aCross, 27U)) + 320992148982301024U) + aPhaseCOrbiterAssignSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterJ = (aWandererH + RotL64(aPrevious, 35U)) + 5619109532065293074U;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 60U)) + RotL64(aCarry, 11U)) + 10380157329426706345U;
            aOrbiterK = (aWandererE + RotL64(aCross, 23U)) + 12449831150625409695U;
            aOrbiterG = ((aWandererA + RotL64(aScatter, 19U)) + RotL64(aCarry, 47U)) + 7847096607042268396U;
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 43U)) + RotL64(aCarry, 3U)) + 11707184096803214678U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 9893643746186827088U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 333687403830908774U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17911256836121454271U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 13837360705077441580U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 4367119682175710689U;
            aOrbiterJ = RotL64((aOrbiterJ * 10295744669174603401U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 1193493435041306784U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 15062951612027370606U;
            aOrbiterK = RotL64((aOrbiterK * 2509383510565136549U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 16000173839235429105U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 15294482444605409961U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1031800997944302665U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 5720749055549773527U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 17248674962996093668U;
            aOrbiterE = RotL64((aOrbiterE * 15730637462755795591U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 16956840483882091059U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 9637715107943515594U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8878362378343603463U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 7147495779349862274U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 7508890985889484275U;
            aOrbiterH = RotL64((aOrbiterH * 17728368447504622035U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 4407738164617959366U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 17027017782352660454U;
            aOrbiterF = RotL64((aOrbiterF * 417183060881259295U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 3174658601748235285U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 9779053567370714831U;
            aOrbiterA = RotL64((aOrbiterA * 6383245776181968033U), 47U);
            //
            aIngress = RotL64(aOrbiterE, 3U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 41U));
            aIngress = aIngress + (RotL64(aOrbiterA, 18U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterF, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterB, 30U)) + aOrbiterH);
            aWandererE = aWandererE + (((RotL64(aScatter, 43U) + RotL64(aOrbiterA, 11U)) + aOrbiterH) + RotL64(aCarry, 35U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 12U) + aOrbiterB) + RotL64(aOrbiterG, 19U));
            aWandererG = aWandererG + (((RotL64(aIngress, 53U) + aOrbiterE) + RotL64(aOrbiterJ, 47U)) + RotL64(aCarry, 27U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterK, 52U)) + aOrbiterF);
            aWandererB = aWandererB + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterG, 5U)) + aOrbiterC) + aPhaseCWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 60U) + aOrbiterE) + RotL64(aOrbiterB, 39U)) + aPhaseCWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aIngress, 29U) + aOrbiterK) + RotL64(aOrbiterG, 23U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterK, 43U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 41U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 38U));
            aCarry = aCarry + RotL64(aWandererC, 57U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 19607U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneA[((aIndex + 17388U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 22204U)) & W_KEY1], 5U) ^ RotL64(aKeyRowReadB[((aIndex + 20099U)) & W_KEY1], 20U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 6U) ^ RotL64(aCross, 57U)) ^ (RotL64(aIngress, 35U) + RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = (aWandererB + RotL64(aCross, 57U)) + 16451272412693907816U;
            aOrbiterD = ((aWandererF + RotL64(aScatter, 47U)) + 10099485419723255462U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = (aWandererA + RotL64(aIngress, 41U)) + 17668900099534923192U;
            aOrbiterA = (aWandererK + RotL64(aPrevious, 30U)) + 5497093724143181753U;
            aOrbiterJ = ((aWandererD + RotL64(aCross, 53U)) + RotL64(aCarry, 53U)) + 10354044773550071706U;
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 5U)) + 12728258851198019099U) + aPhaseCOrbiterAssignSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterH = ((aWandererE + RotL64(aIngress, 37U)) + RotL64(aCarry, 29U)) + 4144050505314242618U;
            aOrbiterC = ((aWandererI + RotL64(aScatter, 12U)) + RotL64(aCarry, 21U)) + 14133805325480076530U;
            aOrbiterG = (aWandererH + RotL64(aIngress, 23U)) + 308863673210602899U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 11741180130160569753U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 12926863156769180448U;
            aOrbiterK = RotL64((aOrbiterK * 9726030996091054939U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 211920854786494259U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 13234608842479411078U;
            aOrbiterE = RotL64((aOrbiterE * 2556747209733759467U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 9164711974854618892U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 6667377062281954219U;
            aOrbiterA = RotL64((aOrbiterA * 2603737166987437649U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 4559040002406721850U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 1749875480850675109U;
            aOrbiterD = RotL64((aOrbiterD * 15822640067349481089U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 9555365165561936366U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 18289733999504213574U;
            aOrbiterJ = RotL64((aOrbiterJ * 14156217554673229429U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 8727162691639622461U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 291406782452963706U;
            aOrbiterB = RotL64((aOrbiterB * 8413500075082350243U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 8294911802626492257U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 15853578397277298548U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13256191781365357747U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 11535146194939658681U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 2177540476748375661U;
            aOrbiterC = RotL64((aOrbiterC * 15791341922007841029U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 2705306323728084136U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 17617871830709148043U;
            aOrbiterG = RotL64((aOrbiterG * 3449981219502809255U), 19U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterE, 5U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 23U));
            aIngress = aIngress + (RotL64(aOrbiterH, 19U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterC, 10U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterK, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterH, 58U)) + aOrbiterC);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterJ, 43U)) + aOrbiterA);
            aWandererE = aWandererE + (((RotL64(aScatter, 60U) + aOrbiterJ) + RotL64(aOrbiterB, 39U)) + RotL64(aCarry, 21U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterH, 23U)) + aOrbiterK);
            aWandererF = aWandererF + (((RotL64(aScatter, 47U) + aOrbiterD) + RotL64(aOrbiterJ, 35U)) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 43U) + aOrbiterC) + RotL64(aOrbiterG, 47U));
            aWandererA = aWandererA + ((RotL64(aCross, 29U) + RotL64(aOrbiterE, 19U)) + aOrbiterA);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterD, 14U)) + aOrbiterB);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 12U) + aOrbiterJ) + RotL64(aOrbiterH, 53U)) + RotL64(aCarry, 37U)) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 53U));
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 38U));
            aCarry = aCarry + RotL64(aWandererA, 29U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 31493U)) & S_BLOCK1], 18U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 24599U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27196U)) & S_BLOCK1], 44U) ^ RotL64(mSource[((aIndex + 26465U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 41U) ^ RotL64(aIngress, 57U)) + (RotL64(aCross, 14U) + RotL64(aPrevious, 29U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 39U)) + 16424657151168221875U) + aPhaseCOrbiterAssignSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterF = (aWandererE + RotL64(aCross, 29U)) + 17150123681886380361U;
            aOrbiterG = (aWandererK + RotL64(aIngress, 14U)) + 16041993588694572757U;
            aOrbiterI = (aWandererD + RotL64(aScatter, 53U)) + 9871185846434828537U;
            aOrbiterB = ((aWandererH + RotL64(aIngress, 35U)) + RotL64(aCarry, 11U)) + 11227236398354430757U;
            aOrbiterE = ((aWandererG + RotL64(aCross, 43U)) + RotL64(aCarry, 57U)) + 5399325217402192631U;
            aOrbiterA = (((aWandererA + RotL64(aPrevious, 3U)) + RotL64(aCarry, 37U)) + 9248828789282890454U) + aPhaseCOrbiterAssignSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = (aWandererI + RotL64(aScatter, 23U)) + 9041370494203701062U;
            aOrbiterH = (aWandererF + RotL64(aPrevious, 18U)) + 14944424084524970764U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 5481938174456671041U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 14783648629543752715U;
            aOrbiterG = RotL64((aOrbiterG * 7260164783191886395U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 12355573914530445723U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 9863991559011968318U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8495251211794343179U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 16149688605937250965U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 106041828692026825U;
            aOrbiterA = RotL64((aOrbiterA * 12199934305374582599U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 8076098639554567792U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 11155119311895580013U;
            aOrbiterJ = RotL64((aOrbiterJ * 1495180896564818647U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 6847612160595917702U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 16094377920388017367U;
            aOrbiterI = RotL64((aOrbiterI * 4875801863643206333U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 13584719866672696684U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 13446209321646234607U;
            aOrbiterE = RotL64((aOrbiterE * 9945349065094781529U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 15829806645369560988U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 12573767256739062550U;
            aOrbiterK = RotL64((aOrbiterK * 5649504278826069077U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 3850030870300393809U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 11857593987748189858U;
            aOrbiterH = RotL64((aOrbiterH * 15942863910931814193U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 5505918410521728373U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 12949653497121247860U;
            aOrbiterF = RotL64((aOrbiterF * 90944913639560027U), 43U);
            //
            aIngress = RotL64(aOrbiterB, 23U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 42U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 39U));
            aIngress = aIngress + (RotL64(aOrbiterA, 35U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterK, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterB, 47U)) + aOrbiterI);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 51U) + aOrbiterJ) + RotL64(aOrbiterK, 51U));
            aWandererA = aWandererA + ((RotL64(aCross, 11U) + RotL64(aOrbiterB, 3U)) + aOrbiterH);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 24U) + RotL64(aOrbiterK, 22U)) + aOrbiterB) + aPhaseCWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 39U) + aOrbiterF) + RotL64(aOrbiterG, 13U)) + RotL64(aCarry, 35U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterH, 57U)) + aOrbiterA) + aPhaseCWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 35U) + aOrbiterE) + RotL64(aOrbiterA, 41U)) + RotL64(aCarry, 11U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 43U) + aOrbiterF) + RotL64(aOrbiterI, 27U));
            aWandererK = aWandererK + ((RotL64(aCross, 4U) + RotL64(aOrbiterE, 36U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + (RotL64(aWandererG, 60U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + RotL64(aWandererI, 3U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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

void TwistExpander_WaterPolo_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 3272U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7867U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4241U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneA[((aIndex + 3241U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aIngress, 5U)) + (RotL64(aPrevious, 21U) ^ RotL64(aCarry, 38U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = (((aWandererB + RotL64(aIngress, 51U)) + RotL64(aCarry, 11U)) + 15920462086654025436U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = (aWandererJ + RotL64(aPrevious, 42U)) + 487844076858004017U;
            aOrbiterE = ((aWandererE + RotL64(aScatter, 29U)) + RotL64(aCarry, 23U)) + 14502883786442630566U;
            aOrbiterB = ((aWandererK + RotL64(aCross, 11U)) + RotL64(aCarry, 47U)) + 3787107318658233674U;
            aOrbiterI = ((aWandererG + RotL64(aPrevious, 3U)) + 12548777544693755491U) + aPhaseDOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 4907309444075181683U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 18342396700266492072U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14842961036061482089U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 13503051997624242670U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 17845742460521374571U;
            aOrbiterH = RotL64((aOrbiterH * 1366356786138085155U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 8640887211877858169U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 5273913123709097537U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1661149444148461791U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 17756844173695563883U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 6713055830729302951U;
            aOrbiterJ = RotL64((aOrbiterJ * 2832836748513174311U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 5106468334224035972U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 10228769728713526172U;
            aOrbiterI = RotL64((aOrbiterI * 9760310686414358435U), 5U);
            //
            aIngress = RotL64(aOrbiterE, 27U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 47U));
            aIngress = aIngress + RotL64(aOrbiterI, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterI, 35U)) + aOrbiterJ);
            aWandererK = aWandererK + ((((RotL64(aScatter, 57U) + aOrbiterJ) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 37U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 19U) + aOrbiterE) + RotL64(aOrbiterH, 57U));
            aWandererG = aWandererG + (((RotL64(aIngress, 3U) + aOrbiterH) + RotL64(aOrbiterB, 21U)) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 40U) + aOrbiterE) + RotL64(aOrbiterI, 48U)) + aPhaseDWandererUpdateSaltF[((aIndex + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 37U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererE, 50U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererG, 29U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 13198U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 12754U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 14943U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneB[((aIndex + 12527U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 37U) + RotL64(aPrevious, 4U)) ^ (RotL64(aCarry, 51U) + RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = (((aWandererI + RotL64(aCross, 11U)) + RotL64(aCarry, 27U)) + 1457104756581596530U) + aPhaseDOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = (aWandererG + RotL64(aIngress, 35U)) + 6127240317844622874U;
            aOrbiterJ = (aWandererE + RotL64(aScatter, 23U)) + 16492290056044189421U;
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 56U)) + RotL64(aCarry, 11U)) + 10963676850938416468U;
            aOrbiterB = (((aWandererH + RotL64(aScatter, 43U)) + RotL64(aCarry, 51U)) + 4872917367399752405U) + aPhaseDOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 15218882377875616148U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 5934166612122118251U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10365045124180379919U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 14215280930872003003U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 11428034799044600979U;
            aOrbiterB = RotL64((aOrbiterB * 12162528943733976177U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 5453003654321728726U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 14273775120265649389U;
            aOrbiterC = RotL64((aOrbiterC * 5139018128323795309U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 328723770018440271U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 13032190719588211088U;
            aOrbiterF = RotL64((aOrbiterF * 13363368478932798315U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 2386881543033598494U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 1649501123340887116U;
            aOrbiterE = RotL64((aOrbiterE * 11148976582360499033U), 43U);
            //
            aIngress = RotL64(aOrbiterJ, 53U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterC, 3U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterE, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aScatter, 3U) + aOrbiterB) + RotL64(aOrbiterJ, 22U));
            aWandererE = aWandererE + (((RotL64(aCross, 57U) + aOrbiterC) + RotL64(aOrbiterF, 13U)) + RotL64(aCarry, 47U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 14U) + RotL64(aOrbiterJ, 53U)) + aOrbiterE) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterC, 43U)) + aOrbiterB) + RotL64(aCarry, 23U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 39U) + aOrbiterC) + RotL64(aOrbiterE, 35U)) + aPhaseDWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + (RotL64(aWandererH, 39U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererA, 47U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 21408U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 18376U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18896U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneC[((aIndex + 22294U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 38U) ^ RotL64(aCarry, 21U)) + (RotL64(aCross, 5U) + RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = (aWandererI + RotL64(aPrevious, 60U)) + 11039986441331892533U;
            aOrbiterC = (((aWandererB + RotL64(aCross, 11U)) + RotL64(aCarry, 19U)) + 6256024955965426119U) + aPhaseDOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = (((aWandererC + RotL64(aScatter, 35U)) + RotL64(aCarry, 3U)) + 9857443189988995666U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterK = ((aWandererA + RotL64(aIngress, 51U)) + RotL64(aCarry, 37U)) + 11900944813380998208U;
            aOrbiterI = (aWandererD + RotL64(aPrevious, 19U)) + 8422577734978875541U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 3100835100713928724U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 11871553509810206993U;
            aOrbiterH = RotL64((aOrbiterH * 15501681886909921677U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 17614749493763417027U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 3638372131856199916U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 480683274898147025U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 6582275259281025770U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 17016882418498941958U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4269869255230867823U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 1747214688658984715U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 9356088987044015278U;
            aOrbiterK = RotL64((aOrbiterK * 16221733545319753695U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 4056238112133473456U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 16013150119949532998U;
            aOrbiterI = RotL64((aOrbiterI * 12913648646318115315U), 21U);
            //
            aIngress = RotL64(aOrbiterK, 47U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 19U));
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aCross, 5U) + aOrbiterH) + RotL64(aOrbiterC, 27U)) + RotL64(aCarry, 51U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 13U) + aOrbiterD) + RotL64(aOrbiterC, 3U));
            aWandererC = aWandererC + ((RotL64(aIngress, 47U) + RotL64(aOrbiterI, 58U)) + aOrbiterK);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 26U) + RotL64(aOrbiterI, 19U)) + aOrbiterH) + aPhaseDWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 37U) + aOrbiterH) + RotL64(aOrbiterK, 11U)) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererI, 5U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererD, 23U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 31355U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28013U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 26974U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 25108U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 19U) ^ RotL64(aIngress, 3U)) + (RotL64(aCross, 35U) ^ RotL64(aPrevious, 48U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = (((aWandererB + RotL64(aCross, 19U)) + RotL64(aCarry, 3U)) + 12027839670755583592U) + aPhaseDOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = (((aWandererJ + RotL64(aIngress, 41U)) + RotL64(aCarry, 21U)) + 15380130703509859843U) + aPhaseDOrbiterAssignSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterC = (aWandererK + RotL64(aScatter, 27U)) + 4590907433867798074U;
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 58U)) + RotL64(aCarry, 43U)) + 1754574023602519724U;
            aOrbiterI = (aWandererE + RotL64(aScatter, 3U)) + 9832756659564903767U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 5035088494491470403U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 14199170923323644638U;
            aOrbiterC = RotL64((aOrbiterC * 4518257134117207121U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 8325619421264440438U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 969534320779067977U;
            aOrbiterE = RotL64((aOrbiterE * 17767548306355264705U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 270575869402913847U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 13344806516599578910U;
            aOrbiterK = RotL64((aOrbiterK * 10193544126281901579U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 15143147951139409101U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 14425582489214169238U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16893787086337916355U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 13951127523239064584U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 14177925225918293579U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13079514031864998485U), 57U);
            //
            aIngress = RotL64(aOrbiterE, 26U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + RotL64(aOrbiterK, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aCross, 37U) + RotL64(aOrbiterB, 21U)) + aOrbiterC) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 18U) + aOrbiterI) + RotL64(aOrbiterK, 11U));
            aWandererB = aWandererB + ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterE, 37U)) + aOrbiterK) + RotL64(aCarry, 23U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 29U) + aOrbiterB) + RotL64(aOrbiterE, 54U));
            aWandererK = aWandererK + (((RotL64(aCross, 3U) + RotL64(aOrbiterK, 29U)) + aOrbiterC) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 21U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererE, 5U);
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

void TwistExpander_WaterPolo_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 6582U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 8103U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 951U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneA[((aIndex + 894U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 11U) ^ RotL64(aIngress, 23U)) + (RotL64(aPrevious, 35U) + RotL64(aCarry, 50U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = (aWandererC + RotL64(aScatter, 37U)) + 3917730204724097072U;
            aOrbiterJ = (((aWandererA + RotL64(aPrevious, 21U)) + RotL64(aCarry, 47U)) + 1874642340716212824U) + aPhaseEOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = ((aWandererF + RotL64(aIngress, 47U)) + RotL64(aCarry, 23U)) + 6900165757434854160U;
            aOrbiterC = ((aWandererE + RotL64(aCross, 29U)) + RotL64(aCarry, 35U)) + 12750946097023807161U;
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 54U)) + 6563216048479513594U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterE = (aWandererH + RotL64(aScatter, 11U)) + 14960240191349450795U;
            aOrbiterA = (aWandererG + RotL64(aCross, 5U)) + 16306180275951788289U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 6502066618271045547U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 6219852857850888738U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10892297250334325283U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 2272931312452845850U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 3028929882263199463U;
            aOrbiterF = RotL64((aOrbiterF * 11005324285856805069U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 6067393030073568112U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 10094809900437037258U;
            aOrbiterE = RotL64((aOrbiterE * 18095564940730322769U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 5962414178157074575U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 15755563045799129417U;
            aOrbiterA = RotL64((aOrbiterA * 3692603590609922031U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 6321455513889880590U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 1197435601998121700U;
            aOrbiterI = RotL64((aOrbiterI * 17693996266260557625U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 12496949381666299968U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 6357070235648527030U;
            aOrbiterC = RotL64((aOrbiterC * 2931486644220862433U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 8423760160877540210U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 8090246492554850768U;
            aOrbiterJ = RotL64((aOrbiterJ * 2949407491181921633U), 19U);
            //
            aIngress = RotL64(aOrbiterC, 34U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 11U));
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterI, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aCross, 21U) + aOrbiterA) + RotL64(aOrbiterC, 35U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 14U) + RotL64(aOrbiterD, 29U)) + aOrbiterA) + aPhaseEWandererUpdateSaltF[((aIndex + 22U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 5U) + aOrbiterC) + RotL64(aOrbiterD, 57U)) + RotL64(aCarry, 21U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterI, 3U)) + aOrbiterJ);
            aWandererG = aWandererG + ((RotL64(aScatter, 27U) + RotL64(aOrbiterI, 48U)) + aOrbiterF);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 53U) + aOrbiterC) + RotL64(aOrbiterE, 11U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterE, 23U)) + aOrbiterI) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererH);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererB, 14U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9818U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 14952U)) & S_BLOCK1], 44U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 12988U)) & S_BLOCK1], 6U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 10063U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 3U) ^ RotL64(aCarry, 21U)) ^ (RotL64(aCross, 50U) + RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = (((aWandererJ + RotL64(aScatter, 23U)) + RotL64(aCarry, 11U)) + 4739486756133131180U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = (aWandererE + RotL64(aIngress, 47U)) + 16089707555501328184U;
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 41U)) + RotL64(aCarry, 43U)) + 15310047330238536453U;
            aOrbiterH = ((aWandererK + RotL64(aCross, 5U)) + RotL64(aCarry, 23U)) + 7901411596386834955U;
            aOrbiterB = (aWandererA + RotL64(aIngress, 35U)) + 4357555491060982163U;
            aOrbiterC = ((aWandererF + RotL64(aScatter, 29U)) + 15667085602825720102U) + aPhaseEOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = (aWandererG + RotL64(aPrevious, 60U)) + 8520635334382269253U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 1772509779231068315U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 15336170957886025677U;
            aOrbiterA = RotL64((aOrbiterA * 10996880551392077399U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 8628770833489469980U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 15469234024247246228U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8905266995119987947U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 10796430900884288328U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 10660110397012853289U;
            aOrbiterH = RotL64((aOrbiterH * 9140007610912037461U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 11202284258711214794U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 17509491802893182994U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9329107599972703671U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 16212572740740103554U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 2190030203761579226U;
            aOrbiterB = RotL64((aOrbiterB * 3101886685668871045U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 12014337082293041909U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 3733531010807001506U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5797362244066062299U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 7100994963061975529U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 17837541162838600258U;
            aOrbiterI = RotL64((aOrbiterI * 8745987361678166553U), 51U);
            //
            aIngress = RotL64(aOrbiterC, 27U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterA, 19U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterH, 60U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterI, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aIngress, 43U) + aOrbiterA) + RotL64(aOrbiterI, 3U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 10U) + aOrbiterC) + RotL64(aOrbiterJ, 47U)) + aPhaseEWandererUpdateSaltB[((aIndex + 12U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aScatter, 3U) + aOrbiterI) + RotL64(aOrbiterB, 11U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 29U) + aOrbiterA) + RotL64(aOrbiterH, 53U)) + aPhaseEWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 35U) + RotL64(aOrbiterB, 29U)) + aOrbiterF) + RotL64(aCarry, 23U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 51U) + aOrbiterJ) + RotL64(aOrbiterI, 20U));
            aWandererA = aWandererA + (((RotL64(aIngress, 21U) + RotL64(aOrbiterC, 41U)) + aOrbiterI) + RotL64(aCarry, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 12U) ^ aWandererA);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + RotL64(aWandererE, 19U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 23321U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21986U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 17429U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 23665U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 35U) + RotL64(aCross, 57U)) ^ (RotL64(aCarry, 6U) + RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = (aWandererH + RotL64(aIngress, 19U)) + 10915618884692072446U;
            aOrbiterD = ((aWandererA + RotL64(aScatter, 27U)) + RotL64(aCarry, 5U)) + 12634922308499254909U;
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 57U)) + RotL64(aCarry, 57U)) + 6533934734564499389U;
            aOrbiterB = (((aWandererE + RotL64(aCross, 5U)) + RotL64(aCarry, 43U)) + 6744203303756105181U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 51U)) + 13086782386652045658U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = (aWandererF + RotL64(aPrevious, 35U)) + 5693840533331397822U;
            aOrbiterK = (aWandererC + RotL64(aCross, 12U)) + 1803663542535024611U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 3597219300593287708U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 1429753448204448904U;
            aOrbiterA = RotL64((aOrbiterA * 10927459251773273143U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 17229017825587322715U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 1137574712801062932U;
            aOrbiterD = RotL64((aOrbiterD * 3645832160939819415U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 2401991077004083378U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 1332473247826139292U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15029831858261506447U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 11730946340796899885U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 15319163439700390962U;
            aOrbiterB = RotL64((aOrbiterB * 1349242001887975499U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 4744141870145159917U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 6067132201862688684U;
            aOrbiterJ = RotL64((aOrbiterJ * 6046100687757836027U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 14991509179286371800U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 4342608825699398682U;
            aOrbiterH = RotL64((aOrbiterH * 10240526103933275875U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 3727521409410742075U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 3302027219498304367U;
            aOrbiterK = RotL64((aOrbiterK * 12153634588200479559U), 5U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterD, 51U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 11U));
            aIngress = aIngress + (RotL64(aOrbiterB, 35U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterC, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aCross, 11U) + aOrbiterK) + RotL64(aOrbiterA, 3U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 3U) + aOrbiterK) + RotL64(aOrbiterH, 47U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 60U) + aOrbiterA) + RotL64(aOrbiterC, 57U)) + aPhaseEWandererUpdateSaltD[((aIndex + 6U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 47U) + aOrbiterJ) + RotL64(aOrbiterC, 35U)) + RotL64(aCarry, 35U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterB, 11U)) + aOrbiterH);
            aWandererH = aWandererH + (((RotL64(aCross, 53U) + RotL64(aOrbiterK, 41U)) + aOrbiterD) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 29U) + aOrbiterJ) + RotL64(aOrbiterK, 28U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 4U) ^ aWandererF);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 37U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + RotL64(aWandererB, 29U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 27187U)) & S_BLOCK1], 50U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27446U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 31219U)) & S_BLOCK1], 48U) ^ RotL64(aOperationLaneD[((aIndex + 31784U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aIngress, 24U)) + (RotL64(aCarry, 43U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = (((aWandererE + RotL64(aPrevious, 41U)) + RotL64(aCarry, 11U)) + 16160838483846078448U) + aPhaseEOrbiterAssignSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterC = (aWandererG + RotL64(aCross, 47U)) + 15404960896190227946U;
            aOrbiterB = ((aWandererC + RotL64(aIngress, 28U)) + RotL64(aCarry, 27U)) + 16904160594024977199U;
            aOrbiterA = (aWandererI + RotL64(aScatter, 35U)) + 17790460246821031802U;
            aOrbiterF = (((aWandererJ + RotL64(aCross, 19U)) + RotL64(aCarry, 43U)) + 16395168254086971959U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = (aWandererD + RotL64(aIngress, 11U)) + 7484373204039901786U;
            aOrbiterH = (aWandererB + RotL64(aScatter, 3U)) + 18026814691322913510U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 15244817793136966450U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 5795491730356335666U;
            aOrbiterB = RotL64((aOrbiterB * 13253529465289332171U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 3163873518027801504U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 2690791759507349172U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16677948635136515083U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 17898067251167087906U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 8028010015006604239U;
            aOrbiterC = RotL64((aOrbiterC * 5601629670521300241U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 7304739457289910555U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 6476837815096530043U;
            aOrbiterF = RotL64((aOrbiterF * 16380545138701113267U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 14242499233467960602U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 17305645693017634630U;
            aOrbiterD = RotL64((aOrbiterD * 14442976693206929569U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 9772864059444171908U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 7897200728282156408U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 816306719390807411U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 4890999319172950996U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 8165132649356094963U;
            aOrbiterH = RotL64((aOrbiterH * 17297706071263690189U), 43U);
            //
            aIngress = RotL64(aOrbiterA, 13U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterB, 43U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterH, 28U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterD, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterK, 60U)) + aOrbiterA);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterC, 21U)) + aOrbiterH) + RotL64(aCarry, 41U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterD, 47U)) + aOrbiterC) + aPhaseEWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 51U) + aOrbiterF) + RotL64(aOrbiterH, 29U)) + RotL64(aCarry, 5U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 20U) + RotL64(aOrbiterA, 3U)) + aOrbiterC);
            aWandererG = aWandererG + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterA, 53U)) + aOrbiterF);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 13U) + aOrbiterC) + RotL64(aOrbiterB, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 52U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 23U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 5U));
            aCarry = aCarry + RotL64(aWandererD, 11U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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

void TwistExpander_WaterPolo_Arx::Twist_D(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 7896U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2760U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 134U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneA[((aIndex + 6614U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 60U) ^ RotL64(aCross, 41U)) ^ (RotL64(aCarry, 27U) + RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = (aWandererK + RotL64(aScatter, 35U)) + 4476099022490972343U;
            aOrbiterG = ((aWandererG + RotL64(aCross, 43U)) + RotL64(aCarry, 3U)) + 16836423700375760429U;
            aOrbiterK = (((aWandererF + RotL64(aIngress, 56U)) + RotL64(aCarry, 47U)) + 8850577488928703557U) + aPhaseFOrbiterAssignSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = (((aWandererE + RotL64(aPrevious, 21U)) + RotL64(aCarry, 23U)) + 7091631824560042743U) + aPhaseFOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = (aWandererC + RotL64(aCross, 5U)) + 12560498899956759494U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 7797973377112012161U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 6173820673874805794U;
            aOrbiterK = RotL64((aOrbiterK * 15741300047917486527U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 10805025132310245348U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 7139216143268029968U;
            aOrbiterH = RotL64((aOrbiterH * 8349754682635765573U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 8241544862261635722U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 4735527016563596150U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6621354217673598381U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 5166171126690294033U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 11117641762075368393U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4980156869201219393U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 6312932356458415421U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 1304139291184508668U;
            aOrbiterF = RotL64((aOrbiterF * 90744653170922319U), 11U);
            //
            aIngress = RotL64(aOrbiterK, 4U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterF, 53U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterH, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aPrevious, 47U) + aOrbiterK) + RotL64(aOrbiterF, 43U)) + RotL64(aCarry, 11U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterH, 5U)) + aOrbiterD) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 3U) + aOrbiterG) + RotL64(aOrbiterD, 13U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 28U) + RotL64(aOrbiterF, 23U)) + aOrbiterH) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 11U) + RotL64(aOrbiterG, 56U)) + aOrbiterF) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererE, 5U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8645U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneD[((aIndex + 11493U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 13793U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneB[((aIndex + 9907U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCross, 35U)) + (RotL64(aPrevious, 4U) ^ RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = (((aWandererA + RotL64(aIngress, 5U)) + RotL64(aCarry, 57U)) + 5568146815535263910U) + aPhaseFOrbiterAssignSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = ((aWandererB + RotL64(aScatter, 19U)) + RotL64(aCarry, 43U)) + 7736084960873834666U;
            aOrbiterE = (((aWandererK + RotL64(aCross, 60U)) + RotL64(aCarry, 21U)) + 1336413621817562093U) + aPhaseFOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = (aWandererD + RotL64(aPrevious, 41U)) + 5218462026934984692U;
            aOrbiterC = (aWandererH + RotL64(aScatter, 29U)) + 7048890985969555935U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 13415955213864702118U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 5657023257021528548U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5200798937081797819U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 14338310943137497116U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 12305161641833950473U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11949964304435964395U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 14514226578370459131U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 12692904083266024340U;
            aOrbiterD = RotL64((aOrbiterD * 14800805065279908839U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 11012959130001327964U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 7106471380403489078U;
            aOrbiterH = RotL64((aOrbiterH * 515626559384817223U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 3718101961355280891U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 13364192077222322664U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1411328915372590283U), 5U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterI, 51U);
            aIngress = aIngress + (RotL64(aOrbiterH, 29U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterE, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterC, 14U)) + aOrbiterD) + RotL64(aCarry, 35U)) + aPhaseFWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterD, 3U)) + aOrbiterH) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterE, 41U)) + aOrbiterC) + RotL64(aCarry, 3U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 48U) + RotL64(aOrbiterI, 27U)) + aOrbiterE);
            aWandererA = aWandererA + ((RotL64(aPrevious, 57U) + aOrbiterH) + RotL64(aOrbiterI, 51U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 21U));
            aCarry = aCarry + RotL64(aWandererB, 29U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 17079U)) & S_BLOCK1], 52U) ^ RotL64(aWorkLaneA[((aIndex + 22879U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19675U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneC[((aIndex + 22148U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 19U) + RotL64(aPrevious, 43U)) ^ (RotL64(aCarry, 56U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 5U)) + 4384716820085860551U) + aPhaseFOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = (((aWandererJ + RotL64(aCross, 22U)) + RotL64(aCarry, 19U)) + 9715780315942116888U) + aPhaseFOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 57U)) + RotL64(aCarry, 47U)) + 15963520052789178632U;
            aOrbiterE = (aWandererF + RotL64(aIngress, 35U)) + 14346700690686392938U;
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 47U)) + RotL64(aCarry, 5U)) + 6005518012489966643U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 2506732930310252119U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 16782163084851775826U;
            aOrbiterJ = RotL64((aOrbiterJ * 1527050617428162663U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 823673076571076303U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 1634084509064077736U;
            aOrbiterD = RotL64((aOrbiterD * 1128407326773234517U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 1288134975466877686U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 2998220403162908444U;
            aOrbiterF = RotL64((aOrbiterF * 4321412662318298283U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 220430672180734911U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 10223923547068528867U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12577370238343872139U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 11696469696177647608U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 6545430420379636963U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8387163146257553773U), 13U);
            //
            aIngress = RotL64(aOrbiterF, 13U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterE, 26U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterB, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aScatter, 57U) + aOrbiterB) + RotL64(aOrbiterJ, 37U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 57U)) + aOrbiterE) + RotL64(aCarry, 19U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 20U) + RotL64(aOrbiterJ, 5U)) + aOrbiterD);
            aWandererC = aWandererC + (((RotL64(aCross, 43U) + RotL64(aOrbiterE, 22U)) + aOrbiterJ) + RotL64(aCarry, 57U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 35U) + aOrbiterB) + RotL64(aOrbiterE, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererF, 57U);
            aCarry = aCarry + RotL64(aIngress, 22U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 32125U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29082U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 30389U)) & S_BLOCK1], 18U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 28746U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 10U) + RotL64(aIngress, 53U)) ^ (RotL64(aCarry, 29U) + RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = (((aWandererG + RotL64(aPrevious, 52U)) + RotL64(aCarry, 23U)) + 12809562813316740345U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = (aWandererF + RotL64(aCross, 3U)) + 17084212535326321199U;
            aOrbiterG = ((aWandererC + RotL64(aScatter, 29U)) + RotL64(aCarry, 5U)) + 16074921689983846769U;
            aOrbiterB = ((aWandererJ + RotL64(aIngress, 19U)) + RotL64(aCarry, 51U)) + 14027986153007120145U;
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 11U)) + 7633455951809250227U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 340989348513370174U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 5307820377645020116U;
            aOrbiterG = RotL64((aOrbiterG * 8402492604131262157U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 5605285015771527274U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 5293500434746182790U;
            aOrbiterE = RotL64((aOrbiterE * 17674669610895537063U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 7263156475892261811U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 10672879570907433005U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2506338667179450741U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 16659226780900986107U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 9774892622769850665U;
            aOrbiterD = RotL64((aOrbiterD * 7487477727543183211U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 10728057184108279042U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 5032485856947407217U;
            aOrbiterH = RotL64((aOrbiterH * 16651577903809154285U), 19U);
            //
            aIngress = RotL64(aOrbiterG, 51U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterB, 14U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterD, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aIngress, 35U) + aOrbiterE) + RotL64(aOrbiterD, 39U)) + RotL64(aCarry, 29U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterE, 3U)) + aOrbiterB);
            aWandererG = aWandererG + ((RotL64(aCross, 13U) + RotL64(aOrbiterG, 54U)) + aOrbiterB);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 26U) + RotL64(aOrbiterE, 11U)) + aOrbiterH) + aPhaseFWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterD, 19U)) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 48U));
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererJ, 39U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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

void TwistExpander_WaterPolo_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterI = 0;
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 6550U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneB[((aIndex + 652U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 4704U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 2203U)) & S_BLOCK1], 40U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCarry, 57U)) ^ (RotL64(aPrevious, 43U) + RotL64(aCross, 26U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = (((aWandererG + RotL64(aIngress, 20U)) + RotL64(aCarry, 29U)) + 9220392006207660113U) + aPhaseGOrbiterAssignSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterJ = (aWandererH + RotL64(aPrevious, 5U)) + 11305018553489132882U;
            aOrbiterI = (((aWandererI + RotL64(aCross, 47U)) + RotL64(aCarry, 11U)) + 5860373868073513684U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = ((aWandererB + RotL64(aScatter, 35U)) + RotL64(aCarry, 53U)) + 12319586170883987589U;
            aOrbiterA = (aWandererA + RotL64(aPrevious, 57U)) + 14072333614354649021U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 9332158529453194608U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 3860569321145958686U;
            aOrbiterI = RotL64((aOrbiterI * 907977527866467591U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 8119005668901240093U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 13918259792880333239U;
            aOrbiterB = RotL64((aOrbiterB * 5441062406822088853U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 6938856216758228704U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 3960905839118710604U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16203746868670689793U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 6043879193734253929U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 15691425268831319195U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7189195135654636271U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 14912209933584715274U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 16180183395910618923U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3942858974766467849U), 19U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterA, 47U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 37U));
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterK, 5U)) + aOrbiterJ);
            aWandererI = aWandererI + ((((RotL64(aIngress, 13U) + RotL64(aOrbiterB, 35U)) + aOrbiterI) + RotL64(aCarry, 27U)) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 28U) + aOrbiterJ) + RotL64(aOrbiterA, 47U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterK, 13U)) + aOrbiterB) + RotL64(aCarry, 39U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 5U) + aOrbiterI) + RotL64(aOrbiterK, 26U)) + aPhaseGWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + (RotL64(aWandererB, 53U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererG, 43U);
            aCarry = aCarry + RotL64(aIngress, 14U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 9825U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneC[((aIndex + 9748U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 14215U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((aIndex + 9437U)) & S_BLOCK1], 46U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 11U) ^ RotL64(aCross, 50U)) + (RotL64(aIngress, 37U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 11U)) + RotL64(aCarry, 11U)) + 17074147006464019918U;
            aOrbiterA = ((aWandererK + RotL64(aIngress, 43U)) + RotL64(aCarry, 27U)) + 10559516626129419928U;
            aOrbiterE = ((aWandererA + RotL64(aCross, 57U)) + 13280363679503946221U) + aPhaseGOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = (((aWandererE + RotL64(aScatter, 3U)) + RotL64(aCarry, 39U)) + 17657115422132457413U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = (aWandererG + RotL64(aCross, 22U)) + 13325837013304973008U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 3059707750486106037U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 4529045702503050852U;
            aOrbiterE = RotL64((aOrbiterE * 12889277842182219673U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 10726578475550904292U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 14832537837996659885U;
            aOrbiterD = RotL64((aOrbiterD * 808060368961520519U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 220094417441809246U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 15343130035105342194U;
            aOrbiterG = RotL64((aOrbiterG * 7984652435043810845U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 16592263353426409884U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 15649290906447931918U;
            aOrbiterA = RotL64((aOrbiterA * 8405875177836650731U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 11437410545843708269U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 5859769136073011444U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1065016088086441107U), 19U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterE, 11U);
            aIngress = aIngress + (RotL64(aOrbiterD, 23U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterG, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aCross, 47U) + aOrbiterD) + RotL64(aOrbiterE, 30U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 28U) + aOrbiterK) + RotL64(aOrbiterE, 47U)) + aPhaseGWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 57U) + RotL64(aOrbiterG, 21U)) + aOrbiterK) + RotL64(aCarry, 47U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 5U) + aOrbiterG) + RotL64(aOrbiterA, 57U));
            aWandererA = aWandererA + ((((RotL64(aCross, 19U) + RotL64(aOrbiterG, 5U)) + aOrbiterD) + RotL64(aCarry, 23U)) + aPhaseGWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + RotL64(aWandererD, 3U);
            aCarry = aCarry + RotL64(aIngress, 50U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 23281U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneD[((aIndex + 20303U)) & S_BLOCK1], 42U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 20190U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((aIndex + 21073U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCarry, 11U)) ^ (RotL64(aCross, 26U) + RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = (((aWandererD + RotL64(aPrevious, 37U)) + RotL64(aCarry, 51U)) + 13174219512651137892U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = (aWandererB + RotL64(aIngress, 29U)) + 2715455762789269341U;
            aOrbiterC = (aWandererE + RotL64(aScatter, 56U)) + 1338018183235594313U;
            aOrbiterK = (((aWandererC + RotL64(aCross, 5U)) + RotL64(aCarry, 3U)) + 16566866551729552930U) + aPhaseGOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = ((aWandererH + RotL64(aScatter, 13U)) + RotL64(aCarry, 29U)) + 6901845297307236726U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 2476078302049201718U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 15531109473927052260U;
            aOrbiterC = RotL64((aOrbiterC * 1078804000420970559U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 4087849380858572351U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 5167830630098599644U;
            aOrbiterJ = RotL64((aOrbiterJ * 1982835131228146099U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 7275995452428627217U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 14794340370010024117U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8779497557416568379U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 8509217403041662849U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 2321522025240806996U;
            aOrbiterK = RotL64((aOrbiterK * 113568101672878697U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 5676672952755594051U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 2304681269233504384U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15731441084605554497U), 23U);
            //
            aIngress = RotL64(aOrbiterC, 19U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + RotL64(aOrbiterD, 30U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aPrevious, 47U) + aOrbiterK) + RotL64(aOrbiterC, 48U)) + RotL64(aCarry, 35U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterD, 5U)) + aOrbiterJ) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 39U) + aOrbiterK) + RotL64(aOrbiterI, 29U)) + RotL64(aCarry, 57U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterK, 37U)) + aOrbiterD) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aScatter, 30U) + aOrbiterK) + RotL64(aOrbiterJ, 21U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + RotL64(aWandererB, 13U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 27551U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneA[((aIndex + 26204U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27058U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneC[((aIndex + 25717U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 51U) + RotL64(aIngress, 4U)) ^ (RotL64(aPrevious, 27U) ^ RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = (((aWandererA + RotL64(aScatter, 19U)) + RotL64(aCarry, 43U)) + 6243113109470883144U) + aPhaseGOrbiterAssignSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterI = (aWandererF + RotL64(aPrevious, 11U)) + 3891552123999605832U;
            aOrbiterB = (aWandererD + RotL64(aIngress, 58U)) + 8758797898587019128U;
            aOrbiterF = (((aWandererE + RotL64(aCross, 47U)) + RotL64(aCarry, 57U)) + 1005891374086408851U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 37U)) + RotL64(aCarry, 23U)) + 3713426782180050764U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 18358143862391573534U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 17504394029693712404U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3391716204095092531U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 5312729289027417014U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 2560873623431186029U;
            aOrbiterD = RotL64((aOrbiterD * 16843728573219210173U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 16309322822806704211U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 10195513918020652600U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14569219741824123715U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 2552116263258744287U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 7732784879810980089U;
            aOrbiterI = RotL64((aOrbiterI * 15041929399477790999U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 16499127570665381507U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 10890036715535519036U;
            aOrbiterA = RotL64((aOrbiterA * 9065115450010475187U), 29U);
            //
            aIngress = RotL64(aOrbiterF, 57U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 4U));
            aIngress = aIngress + RotL64(aOrbiterA, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aScatter, 56U) + aOrbiterD) + RotL64(aOrbiterA, 53U)) + RotL64(aCarry, 21U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 47U) + aOrbiterA) + RotL64(aOrbiterF, 13U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 37U)) + aOrbiterB);
            aWandererA = aWandererA ^ (((RotL64(aCross, 19U) + aOrbiterI) + RotL64(aOrbiterD, 24U)) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 27U) + aOrbiterB) + RotL64(aOrbiterF, 3U)) + RotL64(aCarry, 51U)) + aPhaseGWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 58U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererD, 19U);
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

void TwistExpander_WaterPolo_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 1986U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneB[((aIndex + 6549U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4311U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 1728U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 12U) ^ RotL64(aIngress, 39U)) ^ (RotL64(aCross, 57U) + RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = ((aWandererF + RotL64(aIngress, 3U)) + RotL64(aCarry, 47U)) + 16651241552253078315U;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 13U)) + RotL64(aCarry, 23U)) + 4558144676982478003U;
            aOrbiterI = ((aWandererC + RotL64(aScatter, 26U)) + 8814884320080367550U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = ((aWandererH + RotL64(aCross, 39U)) + RotL64(aCarry, 5U)) + 16011579668555672117U;
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 51U)) + 4738918668759862438U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 12526083125540985108U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 8048723561746000552U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11914807994597963481U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 1082218464034639039U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 8432043246965946816U;
            aOrbiterH = RotL64((aOrbiterH * 7801965585991025451U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 9982080524048636852U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 6720069955755215919U;
            aOrbiterD = RotL64((aOrbiterD * 1025046364205332059U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 1019035028070247757U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 7360619079463870467U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6623074813047915863U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 10893918488381348474U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 1390297670907738019U;
            aOrbiterJ = RotL64((aOrbiterJ * 11909657437658597735U), 21U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterK, 53U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 13U));
            aIngress = aIngress + RotL64(aOrbiterD, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aCross, 42U) + aOrbiterH) + RotL64(aOrbiterI, 50U)) + RotL64(aCarry, 29U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 19U) + aOrbiterD) + RotL64(aOrbiterK, 19U)) + aPhaseHWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 29U) + RotL64(aOrbiterH, 3U)) + aOrbiterJ);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterI, 39U)) + aOrbiterJ);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 51U) + aOrbiterD) + RotL64(aOrbiterH, 29U)) + RotL64(aCarry, 3U)) + aPhaseHWandererUpdateSaltE[((aIndex + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 53U) ^ aWandererF);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + RotL64(aWandererC, 39U);
            aCarry = aCarry + RotL64(aIngress, 30U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 8629U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneC[((aIndex + 8410U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 8525U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 9872U)) & S_BLOCK1], 34U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCarry, 41U)) + (RotL64(aCross, 11U) ^ RotL64(aPrevious, 26U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = (((aWandererC + RotL64(aPrevious, 11U)) + RotL64(aCarry, 19U)) + 15904465836916519864U) + aPhaseHOrbiterAssignSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterE = ((aWandererD + RotL64(aIngress, 3U)) + RotL64(aCarry, 3U)) + 17725629806317789307U;
            aOrbiterK = (((aWandererH + RotL64(aCross, 44U)) + RotL64(aCarry, 35U)) + 13794170125914914828U) + aPhaseHOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = (aWandererB + RotL64(aScatter, 53U)) + 2149055907476874332U;
            aOrbiterG = (aWandererE + RotL64(aCross, 35U)) + 5342047776745074649U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 8268148484060546838U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 10821151364028563719U;
            aOrbiterK = RotL64((aOrbiterK * 13626634259250509711U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 4294213820894407378U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 10884726101307943090U;
            aOrbiterG = RotL64((aOrbiterG * 1116128870387229159U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 16432210042202444824U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 15196602644336228055U;
            aOrbiterD = RotL64((aOrbiterD * 12680438355124070237U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 14117787670220328165U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 219833877949480215U;
            aOrbiterE = RotL64((aOrbiterE * 10736293047771972173U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 3326396981881473962U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 14918513066311426279U;
            aOrbiterC = RotL64((aOrbiterC * 14269763278564574663U), 27U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterG, 19U);
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterK, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 22U) + aOrbiterG) + RotL64(aOrbiterD, 21U));
            aWandererC = aWandererC + (((RotL64(aScatter, 43U) + RotL64(aOrbiterD, 29U)) + aOrbiterC) + RotL64(aCarry, 11U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterE, 13U)) + aOrbiterD) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aIngress, 35U) + RotL64(aOrbiterE, 56U)) + aOrbiterC) + RotL64(aCarry, 35U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterC, 43U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererH, 21U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 6U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererB, 29U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 16776U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19569U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22230U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((aIndex + 22660U)) & S_BLOCK1], 22U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 51U) ^ RotL64(aCarry, 23U)) + (RotL64(aPrevious, 10U) + RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = ((aWandererA + RotL64(aScatter, 57U)) + RotL64(aCarry, 53U)) + 10915618884692072446U;
            aOrbiterB = (aWandererD + RotL64(aCross, 3U)) + 12634922308499254909U;
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 43U)) + RotL64(aCarry, 39U)) + 6533934734564499389U;
            aOrbiterK = (((aWandererJ + RotL64(aIngress, 21U)) + RotL64(aCarry, 21U)) + 6744203303756105181U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = ((aWandererH + RotL64(aPrevious, 12U)) + 13086782386652045658U) + aPhaseHOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 5693840533331397822U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 1803663542535024611U;
            aOrbiterI = RotL64((aOrbiterI * 8511046986156781857U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 3597219300593287708U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 1429753448204448904U;
            aOrbiterB = RotL64((aOrbiterB * 10927459251773273143U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 17229017825587322715U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 1137574712801062932U;
            aOrbiterG = RotL64((aOrbiterG * 3645832160939819415U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 2401991077004083378U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 1332473247826139292U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15029831858261506447U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 11730946340796899885U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 15319163439700390962U;
            aOrbiterH = RotL64((aOrbiterH * 1349242001887975499U), 3U);
            //
            aIngress = RotL64(aOrbiterG, 37U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterH, 14U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterB, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aCross, 57U) + aOrbiterK) + RotL64(aOrbiterH, 51U)) + RotL64(aCarry, 47U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterI, 13U)) + aOrbiterK) + aPhaseHWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 29U) + aOrbiterB) + RotL64(aOrbiterI, 23U)) + RotL64(aCarry, 3U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 20U) + RotL64(aOrbiterG, 60U)) + aOrbiterB);
            aWandererA = aWandererA + ((RotL64(aCross, 47U) + aOrbiterG) + RotL64(aOrbiterK, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererA);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 48U));
            aCarry = aCarry + RotL64(aWandererH, 37U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 31447U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneA[((aIndex + 32619U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30927U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 31176U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCross, 21U)) + (RotL64(aIngress, 36U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = (((aWandererB + RotL64(aCross, 27U)) + RotL64(aCarry, 3U)) + 14499676118633326000U) + aPhaseHOrbiterAssignSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterB = ((aWandererG + RotL64(aIngress, 35U)) + RotL64(aCarry, 23U)) + 17191273593018552288U;
            aOrbiterJ = (aWandererK + RotL64(aScatter, 53U)) + 4085176294948097737U;
            aOrbiterA = (((aWandererC + RotL64(aPrevious, 3U)) + RotL64(aCarry, 35U)) + 11112671474158908186U) + aPhaseHOrbiterAssignSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = (aWandererF + RotL64(aScatter, 44U)) + 8745787969012266485U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 18074049663777707948U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 2543758649719164688U;
            aOrbiterJ = RotL64((aOrbiterJ * 7153845562786344373U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 4659584749412700523U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 974639159259871273U;
            aOrbiterD = RotL64((aOrbiterD * 17918719351847605523U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 9211220687971081987U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 8567024626862182714U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7755874089832496393U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 5803002132294840900U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 11968489432878148467U;
            aOrbiterB = RotL64((aOrbiterB * 4501441062617123165U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 9470807228394903442U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 1692347973120388469U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17433393164156231575U), 5U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 47U);
            aIngress = aIngress + (RotL64(aOrbiterA, 37U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterC, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 44U) + RotL64(aOrbiterC, 47U)) + aOrbiterD);
            aWandererF = aWandererF + (((RotL64(aCross, 5U) + aOrbiterA) + RotL64(aOrbiterJ, 57U)) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 21U) + aOrbiterC) + RotL64(aOrbiterA, 28U));
            aWandererG = aWandererG + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterB, 11U)) + aOrbiterJ) + RotL64(aCarry, 39U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 35U) + aOrbiterB) + RotL64(aOrbiterD, 3U)) + aPhaseHWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + RotL64(aWandererG, 18U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
