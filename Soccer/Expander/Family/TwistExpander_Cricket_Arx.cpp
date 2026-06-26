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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xB708797101D310E5ULL + 0xAD33C7A67E927808ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xCC6335ECE0B3B1D9ULL + 0x9B48FB438F6712A9ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xD1B9A43D26C4E219ULL + 0xE13E07674FB57B89ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xEE413CB2B70F0EEDULL + 0xC46F6D3B34FAA027ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xA6A859F2210B85D5ULL + 0xAF85E1FC0D78A967ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xA4B0E45B6CA4C35FULL + 0xD63147355BEA0F17ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xEF917A635A6EFB4DULL + 0xD65DFB3ADF2CD0FAULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xAC5C46D1B0FD651FULL + 0xE2783D6EEA68B1DFULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xC2BB1FDFF95D7265ULL + 0xFADD136E7E3D76A5ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xFCF2B67DDCFC3035ULL + 0x9F45D4A6DF64A80AULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x8272BEC3E9BE085FULL + 0xC0358243B66730F0ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xF9574D08F231BCC3ULL + 0x8EEDA786C3CD8414ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xDF309E8D48FF4EB1ULL + 0x85C0157C0176EC94ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x9E27218E8287DF71ULL + 0xEA1BD61259519424ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xD4C76BE8ED0F898FULL + 0xDE5D25317FE51A6CULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xF4B0FE43D3188CDFULL + 0xA7202DD92399C4A1ULL);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 892U)) & S_BLOCK1], 11U) ^ RotL64(pSnow[((aIndex + 1816U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 2344U)) & S_BLOCK1], 21U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 1462U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 19U) ^ RotL64(aPrevious, 5U)) + (RotL64(aCarry, 35U) ^ RotL64(aIngress, 52U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (aWandererD + RotL64(aPrevious, 41U)) + 4259993311776766595U;
            aOrbiterI = (aWandererF + RotL64(aCross, 51U)) + 2857813330021126753U;
            aOrbiterK = ((aWandererG + RotL64(aIngress, 23U)) + RotL64(aCarry, 11U)) + 1345396841329442896U;
            aOrbiterJ = (aWandererI + RotL64(aScatter, 43U)) + 320992148982301024U;
            aOrbiterA = (aWandererC + RotL64(aIngress, 4U)) + 5619109532065293074U;
            aOrbiterD = ((((aWandererK + RotL64(aCross, 37U)) + RotL64(aCarry, 29U)) + 10380157329426706345U) + aOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1]) + aNonceWordL;
            aOrbiterC = (aWandererJ + RotL64(aPrevious, 35U)) + 12449831150625409695U;
            aOrbiterB = (((aWandererB + RotL64(aScatter, 19U)) + RotL64(aCarry, 19U)) + 7847096607042268396U) + aNonceWordI;
            aOrbiterG = (aWandererA + RotL64(aIngress, 39U)) + 11707184096803214678U;
            aOrbiterE = ((aWandererE + RotL64(aScatter, 57U)) + 9893643746186827088U) + aOrbiterAssignSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = ((aWandererH + RotL64(aCross, 48U)) + 333687403830908774U) + aNonceWordF;
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 13837360705077441580U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 4367119682175710689U;
            aOrbiterK = RotL64((aOrbiterK * 10295744669174603401U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 1193493435041306784U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 15062951612027370606U;
            aOrbiterD = RotL64((aOrbiterD * 2509383510565136549U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 16000173839235429105U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 15294482444605409961U;
            aOrbiterH = RotL64((aOrbiterH * 1031800997944302665U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 5720749055549773527U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 17248674962996093668U;
            aOrbiterJ = RotL64((aOrbiterJ * 15730637462755795591U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 16956840483882091059U) + aNonceWordE;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 9637715107943515594U;
            aOrbiterC = RotL64((aOrbiterC * 8878362378343603463U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 7147495779349862274U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 7508890985889484275U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17728368447504622035U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 4407738164617959366U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 17027017782352660454U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 417183060881259295U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 3174658601748235285U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 9779053567370714831U) ^ aNonceWordC;
            aOrbiterI = RotL64((aOrbiterI * 6383245776181968033U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 16256981360027888091U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 12778335633397105924U;
            aOrbiterA = RotL64((aOrbiterA * 10821225965811763659U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 13985909343937844583U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 14307218309393008729U;
            aOrbiterB = RotL64((aOrbiterB * 12053366452617039877U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 15549857305890093491U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 4259993311776766595U) ^ aNonceWordH;
            aOrbiterE = RotL64((aOrbiterE * 13703695714360435719U), 43U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterF, 37U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 13U));
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterB, 39U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 30U));
            aIngress = aIngress + RotL64(aOrbiterJ, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterH, 3U)) + aOrbiterD);
            aWandererK = aWandererK + ((RotL64(aScatter, 56U) + RotL64(aOrbiterG, 47U)) + aOrbiterC);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterD, 19U)) + aOrbiterF) + aWandererUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 39U) + RotL64(aOrbiterB, 37U)) + aOrbiterH) + RotL64(aCarry, 27U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 47U) + aOrbiterJ) + RotL64(aOrbiterC, 23U));
            aWandererC = aWandererC + (((RotL64(aScatter, 58U) + aOrbiterG) + RotL64(aOrbiterA, 50U)) + aNonceWordM);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterJ, 13U)) + aOrbiterD);
            aWandererA = aWandererA + ((RotL64(aIngress, 35U) + aOrbiterC) + RotL64(aOrbiterI, 29U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterG, 5U)) + aOrbiterK) + aWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 3U) + RotL64(aOrbiterD, 44U)) + aOrbiterE) + RotL64(aCarry, 5U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 13U) + aOrbiterE) + RotL64(aOrbiterC, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 23U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 48U));
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererB);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 41U));
            aCarry = aCarry + RotL64(aWandererD, 11U);
            aCarry = aCarry + RotL64(aIngress, 38U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordP);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 7123U)) & S_BLOCK1], 12U) ^ RotL64(mSource[((aIndex + 6757U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(pSnow[((S_BLOCK1 - aIndex + 7043U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneA[((aIndex + 10400U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 34U) ^ RotL64(aIngress, 21U)) ^ (RotL64(aPrevious, 51U) + RotL64(aCarry, 3U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 23U)) + 5295352595333316211U) + aOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = ((aWandererG + RotL64(aScatter, 39U)) + 2341795367042042605U) + aNonceWordC;
            aOrbiterG = ((aWandererC + RotL64(aCross, 43U)) + 10122175780504033663U) + aOrbiterAssignSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterB = (aWandererI + RotL64(aIngress, 27U)) + 10084612804696198554U;
            aOrbiterH = (aWandererF + RotL64(aCross, 10U)) + 16470424309851045971U;
            aOrbiterA = (aWandererH + RotL64(aIngress, 3U)) + 656016130975227994U;
            aOrbiterJ = (aWandererB + RotL64(aScatter, 41U)) + 15313268829659834317U;
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 37U)) + 3795220914993923394U) + aNonceWordN;
            aOrbiterI = ((aWandererJ + RotL64(aCross, 35U)) + RotL64(aCarry, 57U)) + 14044442220988813825U;
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 60U)) + RotL64(aCarry, 3U)) + 3804224626734584802U;
            aOrbiterK = ((aWandererA + RotL64(aIngress, 53U)) + RotL64(aCarry, 53U)) + 7980006306010255693U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 13746830564584711549U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 11852212099729274845U;
            aOrbiterG = RotL64((aOrbiterG * 2164880979318247855U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 9083223471018084847U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 13706723820703853346U;
            aOrbiterD = RotL64((aOrbiterD * 11361854103656219887U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 1713819986642275223U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 1382000168233902914U;
            aOrbiterH = RotL64((aOrbiterH * 3894160765130198157U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 4540474625764565485U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 1756168174375757220U;
            aOrbiterJ = RotL64((aOrbiterJ * 12739160208010092017U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 1409297070183609309U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 6082750101445444357U;
            aOrbiterI = RotL64((aOrbiterI * 17438740230251860935U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 1113239890859479202U) + aNonceWordD;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 10932192439503964363U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5915660289913324281U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 3732595033748508428U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 5117760372351117286U) ^ aNonceWordP;
            aOrbiterB = RotL64((aOrbiterB * 2671510075176315761U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 7399968659654088641U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 14835608167871904147U) ^ aOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8312521710415756159U), 29U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterF) + 7851355416751467648U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordG;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 262169565276199916U;
            aOrbiterE = RotL64((aOrbiterE * 11801419425408657509U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 1771847554312299305U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 15588805765521695222U;
            aOrbiterF = RotL64((aOrbiterF * 8541206691371972017U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 6162696602553964144U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 5295352595333316211U;
            aOrbiterK = RotL64((aOrbiterK * 8368226841948931873U), 37U);
            //
            aIngress = RotL64(aOrbiterD, 39U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterC, 60U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 11U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 27U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + RotL64(aOrbiterA, 24U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aIngress, 51U) + RotL64(aOrbiterJ, 22U)) + aOrbiterH);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 42U) + RotL64(aOrbiterD, 51U)) + aOrbiterI);
            aWandererG = aWandererG + ((((RotL64(aCross, 27U) + RotL64(aOrbiterG, 27U)) + aOrbiterK) + aNonceWordL) + aWandererUpdateSaltF[((aIndex + 8U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterK, 39U)) + aOrbiterI);
            aWandererC = aWandererC + ((RotL64(aIngress, 5U) + RotL64(aOrbiterB, 53U)) + aOrbiterG);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 23U) + aOrbiterB) + RotL64(aOrbiterK, 3U));
            aWandererB = aWandererB + (((RotL64(aCross, 39U) + RotL64(aOrbiterH, 20U)) + aOrbiterA) + aWandererUpdateSaltE[((aIndex + 16U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterJ, 41U)) + aOrbiterE);
            aWandererD = aWandererD + (((RotL64(aScatter, 30U) + aOrbiterD) + RotL64(aOrbiterC, 11U)) + RotL64(aCarry, 43U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterH, 29U)) + aOrbiterF) + aNonceWordE);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 13U) + RotL64(aOrbiterB, 43U)) + aOrbiterH) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 22U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + RotL64(aWandererE, 37U);
            aCarry = aCarry + RotL64(aIngress, 10U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordF);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 14373U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11205U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 12141U)) & S_BLOCK1], 60U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 13895U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aIngress, 19U)) ^ (RotL64(aPrevious, 6U) + RotL64(aCross, 39U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = ((aWandererH + RotL64(aScatter, 39U)) + RotL64(aCarry, 29U)) + 9751314027302668907U;
            aOrbiterJ = (aWandererD + RotL64(aPrevious, 24U)) + 12175450995523107056U;
            aOrbiterE = (aWandererA + RotL64(aCross, 29U)) + 17519694958730119552U;
            aOrbiterB = ((aWandererC + RotL64(aIngress, 47U)) + RotL64(aCarry, 51U)) + 9093525527925682263U;
            aOrbiterC = (aWandererB + RotL64(aCross, 35U)) + 3713831321786810138U;
            aOrbiterI = ((aWandererE + RotL64(aIngress, 11U)) + 10108355209191835040U) + aNonceWordJ;
            aOrbiterH = (((aWandererG + RotL64(aPrevious, 41U)) + RotL64(aCarry, 43U)) + 12956307447311314768U) + aOrbiterAssignSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = ((aWandererF + RotL64(aScatter, 5U)) + 1904298513945877359U) + aOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = (aWandererJ + RotL64(aIngress, 53U)) + 4658049993308574460U;
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 44U)) + 9826333658248851902U) + aNonceWordI;
            aOrbiterK = (aWandererK + RotL64(aCross, 27U)) + 12058666914724365134U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 2516574707110528099U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 13335308331049750235U;
            aOrbiterE = RotL64((aOrbiterE * 5880227828760598587U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 8230749255538495304U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 16536559486797811486U;
            aOrbiterI = RotL64((aOrbiterI * 7097036838156464969U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 12387639130570188998U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 8459259798142872020U;
            aOrbiterJ = RotL64((aOrbiterJ * 8001346480955847013U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 16083784052002800300U) + aNonceWordN;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 1957284290736468379U;
            aOrbiterC = RotL64((aOrbiterC * 5046501301740813065U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 7349538179311335863U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 16395170077006105258U;
            aOrbiterD = RotL64((aOrbiterD * 4230485452156662763U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 3317652065873784068U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 5517155804799120700U) ^ aOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9789270651974719183U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 5568525912112200094U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 9334250662962319598U;
            aOrbiterG = RotL64((aOrbiterG * 5034887614541768961U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 5641394627075994165U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 13524971148931512745U;
            aOrbiterB = RotL64((aOrbiterB * 3699457147759854357U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 15124425790244392471U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 7896294947517723306U) ^ aOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7526632360108129915U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 15241686066829586263U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 12099799118961857495U;
            aOrbiterA = RotL64((aOrbiterA * 10456171163074630861U), 37U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 17529688916595727188U) + aOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 9751314027302668907U;
            aOrbiterK = RotL64((aOrbiterK * 521888849578281715U), 47U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterF, 23U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 28U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 37U));
            aIngress = aIngress + (RotL64(aOrbiterC, 53U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterI, 35U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterH, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 29U) + aOrbiterC) + RotL64(aOrbiterG, 13U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 13U) + RotL64(aOrbiterB, 3U)) + aOrbiterG);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterE, 44U)) + aOrbiterD);
            aWandererF = aWandererF + (((RotL64(aCross, 43U) + aOrbiterJ) + RotL64(aOrbiterI, 23U)) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 3U) + aOrbiterH) + RotL64(aOrbiterK, 19U));
            aWandererE = aWandererE + (((RotL64(aScatter, 51U) + RotL64(aOrbiterI, 27U)) + aOrbiterA) + aNonceWordH);
            aWandererK = aWandererK ^ (((RotL64(aCross, 48U) + aOrbiterE) + RotL64(aOrbiterC, 38U)) + aNonceWordE);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 11U) + aOrbiterG) + RotL64(aOrbiterA, 47U)) + RotL64(aCarry, 13U)) + aWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterD, 5U)) + aOrbiterB) + aNonceWordA);
            aWandererD = aWandererD + ((RotL64(aPrevious, 21U) + aOrbiterH) + RotL64(aOrbiterC, 51U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 54U) + aOrbiterF) + RotL64(aOrbiterE, 11U)) + aWandererUpdateSaltD[((aIndex + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 21U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererF, 56U) ^ aWandererK);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 51U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 53U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + RotL64(aWandererE, 5U);
            aCarry = aCarry + RotL64(aIngress, 30U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordL);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 16753U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 16644U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18193U)) & S_BLOCK1], 53U) ^ RotL64(mSource[((aIndex + 16929U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 54U) ^ RotL64(aCross, 19U)) ^ (RotL64(aCarry, 5U) + RotL64(aPrevious, 37U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (aWandererJ + RotL64(aPrevious, 4U)) + 9654059367478508868U;
            aOrbiterA = ((aWandererK + RotL64(aScatter, 35U)) + RotL64(aCarry, 35U)) + 6473006635864677427U;
            aOrbiterE = ((aWandererE + RotL64(aIngress, 41U)) + 6944184481315853243U) + aOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = (aWandererI + RotL64(aCross, 29U)) + 4061496421939102306U;
            aOrbiterB = (aWandererF + RotL64(aPrevious, 27U)) + 15791809275719085463U;
            aOrbiterC = ((aWandererH + RotL64(aScatter, 23U)) + 14050798802646323055U) + aOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = (aWandererD + RotL64(aCross, 57U)) + 12072905924741758266U;
            aOrbiterF = ((aWandererC + RotL64(aIngress, 13U)) + RotL64(aCarry, 23U)) + 17639076509231343896U;
            aOrbiterI = (((aWandererA + RotL64(aCross, 11U)) + RotL64(aCarry, 53U)) + 12195388285571234715U) + aNonceWordB;
            aOrbiterJ = (aWandererG + RotL64(aPrevious, 53U)) + 4325404419499496529U;
            aOrbiterD = ((aWandererB + RotL64(aIngress, 48U)) + 5910567888204238382U) + aNonceWordO;
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 13092940059929942699U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 13381962590820308761U;
            aOrbiterE = RotL64((aOrbiterE * 6345904465930943295U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 15622862439323440527U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 14027151901132249793U;
            aOrbiterB = RotL64((aOrbiterB * 2273573821630510087U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 4584410023907605157U) + aOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 15763755180625487157U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6755736130607297639U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 17023059745666559199U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 5298529579288492971U;
            aOrbiterG = RotL64((aOrbiterG * 2483562793328357721U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 2870152867331654736U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 12017191100173748848U;
            aOrbiterF = RotL64((aOrbiterF * 9958191466506480519U), 37U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterG) + 15899529176182436062U) + aOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1]) + aNonceWordI;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 16482713846343388735U;
            aOrbiterI = RotL64((aOrbiterI * 719465695044265601U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 12943393531812774449U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 9881108254540483225U;
            aOrbiterJ = RotL64((aOrbiterJ * 8011108108007885059U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 3532054586199716750U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 7142230313294797435U;
            aOrbiterD = RotL64((aOrbiterD * 14154176174768868421U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 733958394016131587U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 2060800099014517137U;
            aOrbiterK = RotL64((aOrbiterK * 12988885554457108631U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 2278498033811574812U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 15342071118593803929U;
            aOrbiterA = RotL64((aOrbiterA * 7842196613533603835U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 12987212219357101955U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 9654059367478508868U;
            aOrbiterH = RotL64((aOrbiterH * 11796100167917742307U), 11U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterI, 29U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 19U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 43U));
            aIngress = aIngress + (RotL64(aOrbiterD, 35U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 41U));
            aIngress = aIngress + RotL64(aOrbiterB, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aIngress, 13U) + aOrbiterE) + RotL64(aOrbiterK, 5U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterH, 57U)) + aOrbiterE);
            aWandererF = aWandererF + ((((RotL64(aCross, 6U) + RotL64(aOrbiterJ, 27U)) + aOrbiterI) + RotL64(aCarry, 41U)) + aWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterD, 20U)) + aOrbiterA);
            aWandererC = aWandererC + (((RotL64(aCross, 47U) + RotL64(aOrbiterA, 47U)) + aOrbiterF) + aNonceWordE);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterK, 3U)) + aOrbiterI);
            aWandererK = aWandererK + (((RotL64(aPrevious, 60U) + RotL64(aOrbiterK, 35U)) + aOrbiterG) + RotL64(aCarry, 3U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 53U) + aOrbiterB) + RotL64(aOrbiterF, 13U));
            aWandererG = aWandererG + ((RotL64(aScatter, 39U) + RotL64(aOrbiterH, 39U)) + aOrbiterA);
            aWandererD = aWandererD ^ (((RotL64(aCross, 21U) + aOrbiterH) + RotL64(aOrbiterF, 44U)) + aWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 23U) + RotL64(aOrbiterH, 37U)) + aOrbiterC) + aNonceWordH);
            //
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererJ);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 46U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 51U));
            aCarry = aCarry + RotL64(aWandererF, 39U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22194U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneA[((aIndex + 22022U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24973U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((aIndex + 26685U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aIngress, 18U)) + (RotL64(aPrevious, 53U) ^ RotL64(aCross, 41U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = ((aWandererC + RotL64(aScatter, 39U)) + RotL64(aCarry, 35U)) + 2571116506511057880U;
            aOrbiterD = (aWandererJ + RotL64(aCross, 3U)) + 13112435411509707292U;
            aOrbiterJ = (((aWandererG + RotL64(aIngress, 53U)) + 10403251762787357256U) + aOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordL;
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 30U)) + RotL64(aCarry, 29U)) + 8461951095541400405U;
            aOrbiterK = ((aWandererI + RotL64(aCross, 43U)) + RotL64(aCarry, 41U)) + 9890793478557463815U;
            aOrbiterB = (aWandererD + RotL64(aPrevious, 11U)) + 3030229465991783707U;
            aOrbiterF = (aWandererF + RotL64(aIngress, 21U)) + 7273848154043719247U;
            aOrbiterA = (aWandererA + RotL64(aScatter, 13U)) + 10681774862516028276U;
            aOrbiterC = (((aWandererK + RotL64(aIngress, 51U)) + 7105082755586853104U) + aOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordH;
            aOrbiterI = (aWandererH + RotL64(aScatter, 19U)) + 6588579345319551129U;
            aOrbiterE = (aWandererE + RotL64(aPrevious, 34U)) + 14616333550242386092U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 15439666290229654921U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 3360304356760164799U) ^ aNonceWordC;
            aOrbiterJ = RotL64((aOrbiterJ * 5164191920584106237U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 14438730801970761889U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 14515616787452085729U;
            aOrbiterB = RotL64((aOrbiterB * 2041601927968559821U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 4167853822635132419U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 8950982233003320239U) ^ aOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 887144270884244907U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 12391327853728029953U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 7100871010552394421U;
            aOrbiterI = RotL64((aOrbiterI * 16552349374101955967U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 15381697462381887944U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 6801677551341079401U;
            aOrbiterG = RotL64((aOrbiterG * 13325954438427340703U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 947011315719204867U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 6356920162398333481U;
            aOrbiterH = RotL64((aOrbiterH * 5566721941682667419U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 8910262020598577378U) + aNonceWordB;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 8778455415977526457U;
            aOrbiterF = RotL64((aOrbiterF * 4092470497616637283U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 5585696961453127223U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 9670655481681494412U) ^ aOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7863197168965036383U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 10713004007087085729U) + aNonceWordA;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 4036355047492922339U;
            aOrbiterE = RotL64((aOrbiterE * 6923922258047667173U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 14580156873863533497U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 7049502932205025182U;
            aOrbiterD = RotL64((aOrbiterD * 8665428649262370727U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 12707521269341941677U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 2571116506511057880U;
            aOrbiterK = RotL64((aOrbiterK * 2388236789245943699U), 35U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterB, 27U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 5U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 11U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 60U));
            aIngress = aIngress + (RotL64(aOrbiterE, 37U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterF, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterF, 11U)) + aOrbiterJ) + aNonceWordM);
            aWandererG = aWandererG + (((RotL64(aCross, 48U) + RotL64(aOrbiterF, 46U)) + aOrbiterH) + RotL64(aCarry, 5U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterJ, 13U)) + aOrbiterI);
            aWandererD = aWandererD + (((((RotL64(aScatter, 39U) + aOrbiterE) + RotL64(aOrbiterG, 21U)) + RotL64(aCarry, 39U)) + aNonceWordG) + aWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterF, 29U)) + aOrbiterA) + aNonceWordK);
            aWandererA = aWandererA + ((RotL64(aPrevious, 28U) + RotL64(aOrbiterG, 5U)) + aOrbiterD);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 3U) + aOrbiterF) + RotL64(aOrbiterB, 48U));
            aWandererF = aWandererF + ((RotL64(aCross, 21U) + aOrbiterF) + RotL64(aOrbiterC, 57U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterJ, 51U)) + aOrbiterB);
            aWandererE = aWandererE + ((RotL64(aIngress, 57U) + RotL64(aOrbiterH, 27U)) + aOrbiterK);
            aWandererB = aWandererB ^ (((RotL64(aCross, 43U) + aOrbiterJ) + RotL64(aOrbiterE, 43U)) + aWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + (RotL64(aWandererE, 36U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererB);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + RotL64(aWandererI, 60U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordF);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 27426U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31642U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27378U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneB[((aIndex + 32229U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCross, 20U)) + (RotL64(aIngress, 5U) + RotL64(aCarry, 37U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (aWandererK + RotL64(aScatter, 47U)) + 6318740973868639425U;
            aOrbiterE = ((aWandererD + RotL64(aIngress, 27U)) + 5487840061430920881U) + aNonceWordH;
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 11U)) + 10258706763248072672U) + aOrbiterAssignSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = ((aWandererJ + RotL64(aCross, 40U)) + RotL64(aCarry, 39U)) + 18356875269730338208U;
            aOrbiterG = (aWandererH + RotL64(aScatter, 23U)) + 12883160282903147010U;
            aOrbiterB = (aWandererI + RotL64(aCross, 57U)) + 1010140474942697730U;
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 21U)) + 17733939421700898293U) + aNonceWordO;
            aOrbiterH = ((aWandererG + RotL64(aIngress, 5U)) + RotL64(aCarry, 13U)) + 13693055887924981201U;
            aOrbiterK = ((((aWandererF + RotL64(aPrevious, 37U)) + RotL64(aCarry, 23U)) + 14574732452793385269U) + aOrbiterAssignSaltE[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordG;
            aOrbiterF = (aWandererE + RotL64(aScatter, 3U)) + 10832873941223609012U;
            aOrbiterJ = (aWandererA + RotL64(aIngress, 14U)) + 8212600587135328040U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 5312744319781971178U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 6173741211706546923U;
            aOrbiterI = RotL64((aOrbiterI * 12854414066390848249U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 3693249147883790810U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 18365859989736602556U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3348463719324104997U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 10645056678337549771U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 1175668356822251045U;
            aOrbiterB = RotL64((aOrbiterB * 6579675292775345579U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 13556844570541823717U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 4790355739411849736U) ^ aOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4083544011788850307U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 14905575502272644116U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 17047244574558476634U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2356386971503880047U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 10161614295718414869U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 13413914082651612468U;
            aOrbiterK = RotL64((aOrbiterK * 16224039093981079491U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 6072693130156927774U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 4333656233793103787U;
            aOrbiterF = RotL64((aOrbiterF * 9374745547133955709U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 17209776289202130250U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 11752001118070361543U;
            aOrbiterJ = RotL64((aOrbiterJ * 4416523594812872339U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 15367365111105608277U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 8650687767097460704U;
            aOrbiterD = RotL64((aOrbiterD * 11430451559660578667U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 18074648514448405693U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 10857586858462237581U;
            aOrbiterE = RotL64((aOrbiterE * 3722891011080095849U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 17219932344278345591U) + aNonceWordK;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 6318740973868639425U;
            aOrbiterA = RotL64((aOrbiterA * 8846295038878812229U), 47U);
            //
            aIngress = RotL64(aOrbiterD, 20U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterK, 53U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 27U));
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterH, 60U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 47U) + aOrbiterD) + RotL64(aOrbiterB, 5U));
            aWandererA = aWandererA + (((RotL64(aScatter, 53U) + RotL64(aOrbiterK, 19U)) + aOrbiterH) + RotL64(aCarry, 51U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterI, 44U)) + aOrbiterG) + aNonceWordF);
            aWandererI = aWandererI + ((RotL64(aCross, 29U) + RotL64(aOrbiterG, 39U)) + aOrbiterK);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 11U) + aOrbiterE) + RotL64(aOrbiterC, 23U));
            aWandererD = aWandererD + ((RotL64(aCross, 50U) + RotL64(aOrbiterK, 29U)) + aOrbiterA);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 3U) + aOrbiterF) + RotL64(aOrbiterJ, 47U)) + aWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 39U) + RotL64(aOrbiterB, 41U)) + aOrbiterA) + RotL64(aCarry, 47U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 41U) + aOrbiterC) + RotL64(aOrbiterB, 11U)) + aWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 35U) + aOrbiterD) + RotL64(aOrbiterH, 50U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 24U) + aOrbiterJ) + RotL64(aOrbiterI, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererB);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + (RotL64(aWandererA, 54U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 21U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 41U));
            aCarry = aCarry + RotL64(aWandererE, 5U);
            aCarry = aCarry + RotL64(aIngress, 56U);
            aCarry = aCarry ^ aNonceWordK;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xF6372527E60194BDULL + 0xB28270153B293BF2ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xA95D50D2A6D74B65ULL + 0x892023CF8CCB03EAULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xDC3A2C4E5D33C4B7ULL + 0xFBB94F3A6D7ECBAEULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xE06A31FFB2B1094FULL + 0x981E9AD1F2A91E57ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xA11D2569B1801D5FULL + 0xE92B15EACFAA69D8ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xA2EA2969E2F0BF69ULL + 0xD24FD9159CE1FE32ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xB7578D440C75F0C7ULL + 0xB55D123A9B5F6778ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xFC49176AC8DD53B9ULL + 0x85995ED8807D458EULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xA3F9B0B1A57DE587ULL + 0xDA987A93B976ED1BULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x8F93587FD08A31FDULL + 0xB653CF1FC88CDB32ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xCC76B2269AE87931ULL + 0xE1746BBFC13140C5ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xF8C573452437245DULL + 0xEB5BD10A03694271ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xAF39C2A7EB75EA83ULL + 0xED6590319C3CC731ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xFE6073380365E4C7ULL + 0xD181B4D23BD8D0EDULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x8E7FD489E3DA0D97ULL + 0x8A3FDF1B70A0D149ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xCCDE7EFBE1EC1575ULL + 0xE782799AADD86B81ULL);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 123U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 6606U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 351U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 7029U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 38U)) + (RotL64(aCross, 21U) ^ RotL64(aIngress, 57U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (aWandererK + RotL64(aScatter, 13U)) + 13960289014350612206U;
            aOrbiterC = ((aWandererG + RotL64(aIngress, 43U)) + 3483331015269589730U) + aOrbiterAssignSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = (aWandererF + RotL64(aCross, 60U)) + 6873299241002444518U;
            aOrbiterG = (((aWandererB + RotL64(aPrevious, 27U)) + RotL64(aCarry, 37U)) + 3562094007125534229U) + aOrbiterAssignSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterK = (aWandererD + RotL64(aIngress, 5U)) + 11422367439932782705U;
            aOrbiterE = ((aWandererH + RotL64(aScatter, 47U)) + RotL64(aCarry, 5U)) + 532453428514259816U;
            aOrbiterH = (aWandererA + RotL64(aPrevious, 51U)) + 17810941465810193088U;
            aOrbiterB = ((aWandererE + RotL64(aCross, 39U)) + RotL64(aCarry, 29U)) + 11869759058631106331U;
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 34U)) + 8837581071876177566U) + aNonceWordD;
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 17185378327053837778U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 7578253375676981500U) ^ aOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13371647568758721729U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 17112646434432814442U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 14949096407295697881U;
            aOrbiterE = RotL64((aOrbiterE * 14770977858283051753U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 4259590620758467836U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 6534899413644542303U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7987609419215568661U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 2637407498893694243U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterC) ^ 15819295597921425711U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterJ = RotL64((aOrbiterJ * 5202015597375051399U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 6373559542002699718U) + aNonceWordI;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 11694562937392022505U;
            aOrbiterF = RotL64((aOrbiterF * 9311557972331218597U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 3308736483775453062U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 12749929710650475901U;
            aOrbiterG = RotL64((aOrbiterG * 248428400724560945U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 1569528215675579656U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 1044077933631689572U) ^ aNonceWordM;
            aOrbiterH = RotL64((aOrbiterH * 6443796233912755143U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 8393422728124537471U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 2002732612516530754U;
            aOrbiterC = RotL64((aOrbiterC * 13702146823622364279U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 13469191942843147943U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 7633171368709520560U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9713514012478203047U), 23U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterE, 43U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 11U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 38U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 57U));
            aIngress = aIngress + RotL64(aOrbiterC, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aScatter, 37U) + RotL64(aOrbiterC, 48U)) + aOrbiterE) + aNonceWordL);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterK, 19U)) + aOrbiterA);
            aWandererB = aWandererB + (((RotL64(aCross, 23U) + aOrbiterG) + RotL64(aOrbiterA, 39U)) + aNonceWordN);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 44U) + aOrbiterG) + RotL64(aOrbiterK, 13U));
            aWandererH = aWandererH + (((RotL64(aScatter, 57U) + aOrbiterE) + RotL64(aOrbiterF, 24U)) + RotL64(aCarry, 39U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 13U) + aOrbiterJ) + RotL64(aOrbiterG, 29U));
            aWandererA = aWandererA + ((((RotL64(aIngress, 19U) + aOrbiterB) + RotL64(aOrbiterF, 57U)) + RotL64(aCarry, 5U)) + aNonceWordO);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterB, 53U)) + aOrbiterE) + aWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 4U) + RotL64(aOrbiterF, 35U)) + aOrbiterH) + aWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 53U);
            aCarry = aCarry + RotL64(aIngress, 10U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordK);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 11076U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16214U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9712U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneB[((aIndex + 11028U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 56U) ^ RotL64(aCarry, 23U)) + (RotL64(aCross, 35U) ^ RotL64(aPrevious, 11U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (aWandererF + RotL64(aScatter, 23U)) + 6916817163240024692U;
            aOrbiterI = (aWandererH + RotL64(aPrevious, 47U)) + 14554930751292077817U;
            aOrbiterH = ((aWandererJ + RotL64(aCross, 57U)) + RotL64(aCarry, 51U)) + 1098305064484336101U;
            aOrbiterA = ((aWandererE + RotL64(aIngress, 40U)) + RotL64(aCarry, 39U)) + 12192821172420471527U;
            aOrbiterG = (((aWandererK + RotL64(aScatter, 3U)) + RotL64(aCarry, 29U)) + 2435134991707318845U) + aOrbiterAssignSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 19U)) + 1896745368738512624U) + aOrbiterAssignSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = (aWandererC + RotL64(aCross, 27U)) + 1114996424222923873U;
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 34U)) + 9839135798371512656U) + aNonceWordP;
            aOrbiterC = (aWandererI + RotL64(aPrevious, 51U)) + 8037967239603177043U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 15185468738487237432U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 4912098316394854543U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3072785550384399929U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 13142688607850380888U) + aOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 4507379759608945839U;
            aOrbiterG = RotL64((aOrbiterG * 2989332387754215967U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 7299006009652289342U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 5390655277207053627U;
            aOrbiterB = RotL64((aOrbiterB * 10973744708856143715U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 6744737023577785725U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 15539737698867067285U;
            aOrbiterJ = RotL64((aOrbiterJ * 4686092035261336911U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 13329866734681377952U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 13284937458969166257U) ^ aNonceWordF;
            aOrbiterC = RotL64((aOrbiterC * 3965985432462699445U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 8695002088915702168U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 3858059421620839286U;
            aOrbiterK = RotL64((aOrbiterK * 9559783727301092937U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 6609163873243179836U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 9416165620556710540U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 240385043740268229U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 1578449067529000433U) + aOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 14309000104419489303U) ^ aNonceWordB;
            aOrbiterE = RotL64((aOrbiterE * 7599078306153684729U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 15785180680737461320U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 10099222679918382021U) ^ aNonceWordD;
            aOrbiterI = RotL64((aOrbiterI * 2012232597046182581U), 23U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterJ, 13U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 27U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 5U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 56U));
            aIngress = aIngress + RotL64(aOrbiterH, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aCross, 46U) + aOrbiterB) + RotL64(aOrbiterH, 28U)) + RotL64(aCarry, 27U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 51U) + aOrbiterG) + RotL64(aOrbiterA, 53U));
            aWandererB = aWandererB + (((RotL64(aIngress, 37U) + RotL64(aOrbiterK, 13U)) + aOrbiterB) + aWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterI, 43U)) + aOrbiterG) + aWandererUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterB, 19U)) + aOrbiterA) + RotL64(aCarry, 19U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterA, 39U)) + aOrbiterC);
            aWandererC = aWandererC + ((RotL64(aIngress, 56U) + aOrbiterJ) + RotL64(aOrbiterA, 57U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 23U) + aOrbiterE) + RotL64(aOrbiterK, 47U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 19U) + RotL64(aOrbiterI, 24U)) + aOrbiterJ) + aNonceWordL);
            //
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 30U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererG, 43U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordC);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 21016U)) & S_BLOCK1], 26U) ^ RotL64(aOperationLaneA[((aIndex + 19759U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 21571U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((aIndex + 21759U)) & S_BLOCK1], 10U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 11U) ^ RotL64(aCross, 28U)) ^ (RotL64(aCarry, 43U) + RotL64(aPrevious, 57U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererF + RotL64(aCross, 40U)) + 9080426856729228705U) + aNonceWordL;
            aOrbiterB = ((aWandererK + RotL64(aIngress, 11U)) + RotL64(aCarry, 13U)) + 7851218321653539276U;
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 53U)) + RotL64(aCarry, 57U)) + 7023344692919298036U;
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 5U)) + 9772846154227440734U) + aOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = (((aWandererD + RotL64(aCross, 47U)) + RotL64(aCarry, 37U)) + 12008298632429608431U) + aOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = (aWandererA + RotL64(aPrevious, 23U)) + 12201090455849562875U;
            aOrbiterG = ((aWandererI + RotL64(aScatter, 29U)) + 9498721803411445471U) + aNonceWordD;
            aOrbiterD = (aWandererB + RotL64(aIngress, 60U)) + 351203764023093632U;
            aOrbiterH = (aWandererG + RotL64(aCross, 35U)) + 4966360430644539250U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 9194167899071345693U) + aNonceWordF;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 4922477697284269116U;
            aOrbiterF = RotL64((aOrbiterF * 8444814161720407881U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 15742625291642356429U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 7528703106518431730U) ^ aOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11530049278751507567U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 15279053574704935317U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 2425839793660355555U;
            aOrbiterC = RotL64((aOrbiterC * 11486964816849830667U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 13209849392400008898U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 9041500097716231309U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 340661035700748739U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 7885423750878814599U) + aOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 1992993999902904603U;
            aOrbiterJ = RotL64((aOrbiterJ * 1478629826632201617U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 6120758615019314102U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 8529621625846992066U;
            aOrbiterA = RotL64((aOrbiterA * 8485991471612862467U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 9125182130757385320U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 15691232622970220043U;
            aOrbiterG = RotL64((aOrbiterG * 16517916951054758147U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 11413090085435424697U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 11563151001080914939U;
            aOrbiterD = RotL64((aOrbiterD * 16828196274450408201U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 1778975369262558069U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 3232132443557192010U;
            aOrbiterH = RotL64((aOrbiterH * 17132823737792200981U), 35U);
            //
            aIngress = RotL64(aOrbiterH, 60U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + (RotL64(aOrbiterK, 53U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + RotL64(aOrbiterB, 6U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 24U) + RotL64(aOrbiterB, 21U)) + aOrbiterF) + aNonceWordH);
            aWandererG = aWandererG + (((RotL64(aScatter, 43U) + aOrbiterA) + RotL64(aOrbiterC, 34U)) + RotL64(aCarry, 27U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterA, 47U)) + aOrbiterB);
            aWandererI = aWandererI + ((RotL64(aIngress, 3U) + RotL64(aOrbiterG, 57U)) + aOrbiterH);
            aWandererA = aWandererA ^ ((RotL64(aCross, 19U) + aOrbiterB) + RotL64(aOrbiterG, 11U));
            aWandererD = aWandererD + ((((RotL64(aScatter, 29U) + RotL64(aOrbiterF, 51U)) + aOrbiterK) + aNonceWordN) + aWandererUpdateSaltB[((aIndex + 18U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 13U) + aOrbiterJ) + RotL64(aOrbiterC, 27U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 48U) + aOrbiterC) + RotL64(aOrbiterD, 3U)) + RotL64(aCarry, 3U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 37U) + aOrbiterD) + RotL64(aOrbiterJ, 40U)) + aWandererUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererI);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + RotL64(aWandererK, 6U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordH);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 31556U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneB[((aIndex + 29883U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 31230U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 32628U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 43U) + RotL64(aPrevious, 28U)) ^ (RotL64(aCross, 57U) + RotL64(aIngress, 13U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (((aWandererA + RotL64(aCross, 53U)) + RotL64(aCarry, 13U)) + 1457104756581596530U) + aOrbiterAssignSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterF = ((aWandererC + RotL64(aIngress, 35U)) + 6127240317844622874U) + aOrbiterAssignSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = (aWandererE + RotL64(aPrevious, 42U)) + 16492290056044189421U;
            aOrbiterK = ((aWandererH + RotL64(aScatter, 11U)) + RotL64(aCarry, 53U)) + 10963676850938416468U;
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 5U)) + 4872917367399752405U) + aNonceWordP;
            aOrbiterD = (aWandererI + RotL64(aScatter, 21U)) + 15218882377875616148U;
            aOrbiterG = (aWandererF + RotL64(aIngress, 46U)) + 5934166612122118251U;
            aOrbiterC = (aWandererD + RotL64(aCross, 27U)) + 14215280930872003003U;
            aOrbiterB = (((aWandererJ + RotL64(aIngress, 57U)) + RotL64(aCarry, 3U)) + 11428034799044600979U) + aNonceWordI;
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 5453003654321728726U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 14273775120265649389U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5139018128323795309U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 328723770018440271U) + aOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 13032190719588211088U;
            aOrbiterE = RotL64((aOrbiterE * 13363368478932798315U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 2386881543033598494U) + aOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 1649501123340887116U;
            aOrbiterG = RotL64((aOrbiterG * 11148976582360499033U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 16462401546754210583U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 1510579201823042227U;
            aOrbiterA = RotL64((aOrbiterA * 16287912400104043275U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 6889066000014251983U) + aNonceWordD;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 11324594596597724357U) ^ aNonceWordG;
            aOrbiterK = RotL64((aOrbiterK * 15344987814648586023U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 12237796033168436537U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterF) ^ 17306069670330000343U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterD = RotL64((aOrbiterD * 3167451351403385259U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 14197284538008811658U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 4754134852883071927U;
            aOrbiterC = RotL64((aOrbiterC * 3484427259538998699U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 17201907781639753736U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 8318419319239859855U;
            aOrbiterB = RotL64((aOrbiterB * 10320390501983802091U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 16012488623961565780U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 15583721012865354925U;
            aOrbiterF = RotL64((aOrbiterF * 10656414363201743961U), 37U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterC, 29U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 19U));
            aIngress = aIngress + (RotL64(aOrbiterA, 10U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 43U));
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aIngress, 39U) + aOrbiterK) + RotL64(aOrbiterA, 53U)) + aWandererUpdateSaltA[((aIndex + 11U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 14U) + aOrbiterF) + RotL64(aOrbiterD, 30U));
            aWandererE = aWandererE + ((((RotL64(aCross, 47U) + RotL64(aOrbiterC, 39U)) + aOrbiterE) + RotL64(aCarry, 37U)) + aNonceWordB);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 35U) + aOrbiterD) + RotL64(aOrbiterE, 47U));
            aWandererK = aWandererK + (((RotL64(aCross, 5U) + aOrbiterA) + RotL64(aOrbiterI, 43U)) + aNonceWordJ);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterG, 5U)) + aOrbiterB);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterB, 35U)) + aOrbiterE) + RotL64(aCarry, 57U)) + aWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 18U) + RotL64(aOrbiterA, 13U)) + aOrbiterD);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 29U) + RotL64(aOrbiterE, 20U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 14U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 39U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + RotL64(aWandererI, 29U);
            aCarry = aCarry + RotL64(aIngress, 44U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordK);
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
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0;
    std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xF0A196688DC2C9BBULL + 0xE6285FC5F427EA94ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xEF23E4DA577859AFULL + 0xB8BF1E2E0BF191B8ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xF4CE7E3D89B0A6AFULL + 0xA81685F544914A78ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x86A49DBD856BF5D3ULL + 0x8F5474277974FE98ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x955B4BBDE4059FEDULL + 0xBE9BE700BA825A61ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x919F9B99FDBA0CAFULL + 0xD1F097DE1C25704CULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x966B53D8666F48EFULL + 0xFD9E77769542C3A8ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xDEA7AB9BF830A849ULL + 0xEB637F3928C6AEB6ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xEA9C07E798A94051ULL + 0xA6F53EE69B527CAAULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xB7ABA1F02106FC6DULL + 0xD48DB5350E2B2B9EULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xA96FE81306B20AB1ULL + 0x8777BF190A95AB13ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x8DCE0CABDD993265ULL + 0xC22B760F4C8BFB67ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x95DE4731244D8691ULL + 0xAB9D02DE827206C1ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xAF9DBB30C353CEDBULL + 0xB5BEF401C9644A07ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xFA37C60C88AF9083ULL + 0x96EB667C533FB82EULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x93E80F278C4DF20BULL + 0x90D6AD7C1726C9EBULL);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 7478U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneC[((aIndex + 7181U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 7440U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneA[((aIndex + 3642U)) & S_BLOCK1], 40U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 24U) ^ RotL64(aIngress, 39U)) + (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 11U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((((aWandererB + RotL64(aPrevious, 51U)) + RotL64(aCarry, 53U)) + 17936518874386450467U) + aOrbiterAssignSaltC[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordK;
            aOrbiterC = ((aWandererD + RotL64(aIngress, 29U)) + RotL64(aCarry, 39U)) + 13722737841589910344U;
            aOrbiterE = (aWandererF + RotL64(aScatter, 39U)) + 11774969167948715796U;
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 10U)) + RotL64(aCarry, 3U)) + 3640101505680493777U;
            aOrbiterK = (((aWandererG + RotL64(aPrevious, 21U)) + 1369495382725650822U) + aOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1]) + aNonceWordP;
            //
            aOrbiterD = (((aOrbiterD + aOrbiterC) + 11827310354654653345U) + aOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1]) + aNonceWordO;
            aOrbiterE = (((aOrbiterE ^ aOrbiterD) ^ 186037671377175394U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterE = RotL64((aOrbiterE * 829791264853993897U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 11428829344234627340U) + aNonceWordF;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 2275016369870029068U) ^ aOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14936799202145280833U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 15471646673734798328U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 12172082573115640145U;
            aOrbiterJ = RotL64((aOrbiterJ * 9629417882787847753U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 6626736341348283154U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 12220614992483863623U;
            aOrbiterC = RotL64((aOrbiterC * 8137086205714097487U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 13157102324253760215U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 4143587482368093601U) ^ aOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5060677690991506895U), 27U);
            //
            aIngress = RotL64(aOrbiterC, 27U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterE, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 27U) + aOrbiterC) + RotL64(aOrbiterK, 60U)) + aWandererUpdateSaltF[((aIndex + 14U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 10U) + aOrbiterE) + RotL64(aOrbiterD, 29U)) + RotL64(aCarry, 51U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterJ, 41U)) + aOrbiterC) + aNonceWordA);
            aWandererF = aWandererF + ((((RotL64(aIngress, 19U) + RotL64(aOrbiterD, 51U)) + aOrbiterJ) + RotL64(aCarry, 19U)) + aWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterK, 11U)) + aOrbiterE) + aNonceWordD);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + RotL64(aWandererB, 23U);
            aCarry = aCarry + RotL64(aIngress, 36U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordP);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 11522U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 13930U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 15034U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 8442U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 27U) ^ RotL64(aIngress, 39U)) + (RotL64(aCross, 12U) ^ RotL64(aPrevious, 51U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (aWandererI + RotL64(aIngress, 29U)) + 5160910997561396461U;
            aOrbiterC = ((aWandererB + RotL64(aCross, 11U)) + RotL64(aCarry, 47U)) + 14920764751058512062U;
            aOrbiterF = (((aWandererF + RotL64(aScatter, 57U)) + RotL64(aCarry, 5U)) + 6080952401749660022U) + aOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = (((aWandererG + RotL64(aPrevious, 3U)) + RotL64(aCarry, 29U)) + 17667234330526298627U) + aNonceWordP;
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 20U)) + 760630072638686756U) + aOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 3504157162816997476U) + aNonceWordC;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 9489022223422585882U;
            aOrbiterF = RotL64((aOrbiterF * 2398110457196177747U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 1149898536879968964U) + aOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 10492284328940025310U;
            aOrbiterJ = RotL64((aOrbiterJ * 7893416766300156495U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 13213275606286399312U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 10557118912847180413U) ^ aOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10077877991284587845U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 15618980209023994776U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 5268600749854045564U;
            aOrbiterC = RotL64((aOrbiterC * 3849660559223919613U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 8011552687609649990U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 3148133096349525066U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5245156554959620007U), 53U);
            //
            aIngress = RotL64(aOrbiterF, 27U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 13U));
            aIngress = aIngress + RotL64(aOrbiterC, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aPrevious, 57U) + aOrbiterF) + RotL64(aOrbiterJ, 39U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 29U) + aOrbiterJ) + RotL64(aOrbiterK, 23U));
            aWandererI = aWandererI + ((((RotL64(aScatter, 47U) + aOrbiterC) + RotL64(aOrbiterK, 47U)) + RotL64(aCarry, 19U)) + aNonceWordD);
            aWandererC = aWandererC ^ (((RotL64(aCross, 14U) + aOrbiterC) + RotL64(aOrbiterE, 5U)) + aWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 5U) + aOrbiterE) + RotL64(aOrbiterK, 14U)) + RotL64(aCarry, 43U)) + aWandererUpdateSaltC[((aIndex + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererB, 56U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererI, 3U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordF);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 21128U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21958U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 22950U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 21116U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 51U) + RotL64(aIngress, 6U)) ^ (RotL64(aPrevious, 35U) + RotL64(aCarry, 19U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (((aWandererK + RotL64(aPrevious, 30U)) + RotL64(aCarry, 5U)) + 6521330037475130256U) + aOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = (aWandererH + RotL64(aCross, 19U)) + 12611880456055428940U;
            aOrbiterG = (((aWandererG + RotL64(aScatter, 39U)) + RotL64(aCarry, 35U)) + 12061611078130934708U) + aNonceWordC;
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 47U)) + RotL64(aCarry, 51U)) + 1558112410801116984U;
            aOrbiterF = (((aWandererE + RotL64(aPrevious, 11U)) + 10509115227850160786U) + aOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1]) + aNonceWordP;
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 4045915960688792066U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 1196541286513243082U;
            aOrbiterG = RotL64((aOrbiterG * 5454309408259753479U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 15564991032722373702U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 4897765238703641798U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9693901276712946763U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 12327429514907752733U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 6189189797708711636U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9017615866338877651U), 51U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterF) + 6374267075282018852U) + aOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1]) + aNonceWordF;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 1888758503831341439U;
            aOrbiterJ = RotL64((aOrbiterJ * 74387714918264257U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 14956857689299491800U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 14879361107223331957U;
            aOrbiterF = RotL64((aOrbiterF * 9166712966729591953U), 27U);
            //
            aIngress = RotL64(aOrbiterJ, 29U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 5U));
            aIngress = aIngress + RotL64(aOrbiterI, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterK, 19U)) + aOrbiterI) + aWandererUpdateSaltB[((aIndex + 14U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aScatter, 43U) + RotL64(aOrbiterG, 29U)) + aOrbiterK) + RotL64(aCarry, 11U)) + aNonceWordG);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterF, 11U)) + aOrbiterJ);
            aWandererG = aWandererG + ((((RotL64(aCross, 4U) + aOrbiterF) + RotL64(aOrbiterG, 53U)) + RotL64(aCarry, 57U)) + aWandererUpdateSaltA[((aIndex + 18U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterJ, 40U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererH, 60U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 5U));
            aCarry = aCarry + RotL64(aWandererG, 13U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordO);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 31359U)) & S_BLOCK1], 10U) ^ RotL64(aWorkLaneB[((aIndex + 31301U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27378U)) & S_BLOCK1], 24U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 32260U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 27U) ^ RotL64(aPrevious, 56U)) ^ (RotL64(aIngress, 13U) + RotL64(aCarry, 43U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (((aWandererJ + RotL64(aPrevious, 19U)) + RotL64(aCarry, 3U)) + 15920462086654025436U) + aOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = (((aWandererC + RotL64(aIngress, 34U)) + RotL64(aCarry, 47U)) + 487844076858004017U) + aOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = (aWandererB + RotL64(aCross, 43U)) + 14502883786442630566U;
            aOrbiterD = ((aWandererF + RotL64(aScatter, 11U)) + RotL64(aCarry, 21U)) + 3787107318658233674U;
            aOrbiterI = ((aWandererH + RotL64(aCross, 53U)) + 12548777544693755491U) + aNonceWordO;
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 4907309444075181683U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 18342396700266492072U) ^ aOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14842961036061482089U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 13503051997624242670U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 17845742460521374571U;
            aOrbiterK = RotL64((aOrbiterK * 1366356786138085155U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 8640887211877858169U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 5273913123709097537U;
            aOrbiterD = RotL64((aOrbiterD * 1661149444148461791U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 17756844173695563883U) + aNonceWordI;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 6713055830729302951U) ^ aOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2832836748513174311U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 5106468334224035972U) + aOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 10228769728713526172U;
            aOrbiterI = RotL64((aOrbiterI * 9760310686414358435U), 27U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterI, 13U);
            aIngress = aIngress + (RotL64(aOrbiterK, 52U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterB, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 23U) + aOrbiterK) + RotL64(aOrbiterI, 21U)) + aNonceWordG);
            aWandererC = aWandererC + ((((RotL64(aCross, 57U) + RotL64(aOrbiterD, 43U)) + aOrbiterI) + RotL64(aCarry, 35U)) + aWandererUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 4U) + RotL64(aOrbiterF, 11U)) + aOrbiterB) + aWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 43U) + aOrbiterD) + RotL64(aOrbiterF, 3U)) + RotL64(aCarry, 23U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterD, 54U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + RotL64(aWandererB, 47U);
            aCarry = aCarry + RotL64(aIngress, 20U);
            aCarry = aCarry ^ aNonceWordP;
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
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xBC3C30FC9F26762BULL + 0xAEDC531BD16E5B90ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x8C43632F976DA94DULL + 0xD5FA58554BB90352ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xE159DA03FDC3B369ULL + 0xBEE3E5627FF21531ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xB3B6E888DC91BC05ULL + 0xDE5AD04BBDCE89BCULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xC26287C9F64B57BFULL + 0xCB2B1E6AB31370F0ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x914DAB54C46AE631ULL + 0x901868E657C76CD1ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xAD6E86321005AB13ULL + 0xFC6891D82659ECCDULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xABC8FD1E3921CB27ULL + 0xC3000557B1B24718ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x9CFCD5F657FBE133ULL + 0xBB1B0F32CC422F1CULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x9D25828968558E5DULL + 0xE7A49713FCCA8051ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xC66779B9CDAE7A09ULL + 0xD996C1DEF7670A41ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xC82D6596C22BBB0FULL + 0xD00E57FE6FFDE250ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xC546D18B40908001ULL + 0xF0EFA8715E0416C5ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xAC86646904F64B8DULL + 0xC0B460C75BCA028EULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xB5DB3195833CD82DULL + 0x8B7D9F1732439579ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xAA13029C40505161ULL + 0x942CC401880CAC2BULL);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 783U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((aIndex + 761U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 170U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneA[((aIndex + 4350U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 10U) + RotL64(aPrevious, 27U)) + (RotL64(aCross, 43U) ^ RotL64(aIngress, 57U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (aWandererB + RotL64(aPrevious, 19U)) + 17019646486641172469U;
            aOrbiterG = ((aWandererF + RotL64(aIngress, 60U)) + RotL64(aCarry, 57U)) + 12276141179299971572U;
            aOrbiterC = (aWandererE + RotL64(aScatter, 11U)) + 3617241694029841555U;
            aOrbiterB = (aWandererD + RotL64(aCross, 35U)) + 6967963401259371737U;
            aOrbiterK = ((((aWandererA + RotL64(aScatter, 53U)) + RotL64(aCarry, 13U)) + 6340709284279891017U) + aOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterE = ((aWandererG + RotL64(aCross, 47U)) + 456065368903896482U) + aOrbiterAssignSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 27U)) + RotL64(aCarry, 27U)) + 17686765719908116203U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 1322045955429785736U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 5163772703302372887U) ^ aOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3193272189179082313U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 13268431135020363252U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 6538789950366849332U) ^ aOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5352960308459065837U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 10390344544314544893U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 5087084271300584267U) ^ aNonceWordK;
            aOrbiterE = RotL64((aOrbiterE * 15149302947570776165U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 13423071121590981727U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 18324443012024134729U;
            aOrbiterF = RotL64((aOrbiterF * 15814349432207734533U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 4129091815978464507U) + aOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 17024797553831962245U;
            aOrbiterH = RotL64((aOrbiterH * 3137753479364378175U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 6501545108779991661U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 11930037791867597447U) ^ aNonceWordF;
            aOrbiterB = RotL64((aOrbiterB * 4904739567549702851U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 4667298703308315851U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 6315980380900062127U;
            aOrbiterG = RotL64((aOrbiterG * 12080555704907924637U), 11U);
            //
            aIngress = RotL64(aOrbiterK, 29U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterC, 14U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 51U));
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aCross, 47U) + aOrbiterG) + RotL64(aOrbiterK, 41U)) + aNonceWordM) + aWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterE, 27U)) + aOrbiterH);
            aWandererF = aWandererF + (((RotL64(aScatter, 57U) + aOrbiterC) + RotL64(aOrbiterB, 11U)) + RotL64(aCarry, 3U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 4U) + aOrbiterH) + RotL64(aOrbiterC, 60U));
            aWandererI = aWandererI + ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterH, 5U)) + aOrbiterG) + RotL64(aCarry, 27U)) + aWandererUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterH, 53U)) + aOrbiterF);
            aWandererA = aWandererA + ((RotL64(aScatter, 37U) + aOrbiterC) + RotL64(aOrbiterE, 21U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + (RotL64(aWandererA, 53U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererI, 12U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererE, 19U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ aNonceWordA;
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 13437U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneD[((aIndex + 9239U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 11672U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 14133U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 56U) + RotL64(aPrevious, 27U)) + (RotL64(aCross, 43U) ^ RotL64(aIngress, 5U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererD + RotL64(aIngress, 3U)) + RotL64(aCarry, 5U)) + 1364174714924216027U;
            aOrbiterD = (aWandererA + RotL64(aPrevious, 53U)) + 13561796874229506613U;
            aOrbiterA = ((aWandererH + RotL64(aScatter, 19U)) + 11845572344206238305U) + aNonceWordO;
            aOrbiterG = (aWandererI + RotL64(aCross, 35U)) + 15762708240326773763U;
            aOrbiterC = (aWandererJ + RotL64(aIngress, 26U)) + 1157119665207900473U;
            aOrbiterF = (((aWandererC + RotL64(aCross, 41U)) + RotL64(aCarry, 57U)) + 6823546624372055260U) + aOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = ((((aWandererF + RotL64(aPrevious, 13U)) + RotL64(aCarry, 19U)) + 14465564210523945121U) + aOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordN;
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 10667464548080807531U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterB) ^ 13445737493224316575U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterA = RotL64((aOrbiterA * 12137295000900795711U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 3009837893785957665U) + aOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 2886920524111083752U;
            aOrbiterB = RotL64((aOrbiterB * 15308180928967762543U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 10886177449328249656U) + aOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 15067759884678100433U) ^ aNonceWordB;
            aOrbiterG = RotL64((aOrbiterG * 5724566815989860041U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 18307930462682331536U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 8791864377579255801U;
            aOrbiterD = RotL64((aOrbiterD * 9265158882471421767U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 805797468642992351U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 5743305867058244964U;
            aOrbiterC = RotL64((aOrbiterC * 16263000753351131717U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 17102025528234481273U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 1841579177327486899U) ^ aOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3841603385577825265U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 2189493507896508972U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 18209567010094914374U) ^ aNonceWordL;
            aOrbiterE = RotL64((aOrbiterE * 3737080408976852351U), 41U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterD, 21U);
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterF, 11U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterA, 3U)) + aOrbiterB) + aNonceWordH);
            aWandererF = aWandererF + ((((RotL64(aIngress, 35U) + RotL64(aOrbiterE, 58U)) + aOrbiterB) + RotL64(aCarry, 51U)) + aWandererUpdateSaltD[((aIndex + 28U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterF, 37U)) + aOrbiterE) + aWandererUpdateSaltF[((aIndex + 6U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 5U) + aOrbiterE) + RotL64(aOrbiterC, 21U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 21U) + aOrbiterD) + RotL64(aOrbiterC, 43U)) + aNonceWordJ);
            aWandererI = aWandererI + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterE, 29U)) + aOrbiterA) + RotL64(aCarry, 27U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 14U) + RotL64(aOrbiterG, 51U)) + aOrbiterA) + aNonceWordE);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererH);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 5U));
            aCarry = aCarry + RotL64(aWandererI, 24U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ aNonceWordF;
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 22962U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21428U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17295U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneC[((aIndex + 23427U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 52U) + RotL64(aPrevious, 3U)) ^ (RotL64(aIngress, 39U) ^ RotL64(aCarry, 23U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (((aWandererA + RotL64(aCross, 34U)) + RotL64(aCarry, 29U)) + 964165145848253292U) + aOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = (aWandererC + RotL64(aScatter, 21U)) + 10645976767204934746U;
            aOrbiterC = ((aWandererH + RotL64(aIngress, 51U)) + RotL64(aCarry, 5U)) + 8241612229349212650U;
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 27U)) + 4159196033256913347U) + aOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = (aWandererG + RotL64(aIngress, 3U)) + 7194795864620233507U;
            aOrbiterA = (aWandererF + RotL64(aCross, 41U)) + 7638928444536778384U;
            aOrbiterI = (((aWandererD + RotL64(aScatter, 11U)) + RotL64(aCarry, 57U)) + 11819105916503968109U) + aNonceWordO;
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 18052213302858186237U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 8663575313970041570U;
            aOrbiterC = RotL64((aOrbiterC * 14131073322476609161U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 16644136720439299786U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 16930316530442679864U;
            aOrbiterK = RotL64((aOrbiterK * 2650922074098320859U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 16251107616988250593U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 7171986193609401665U;
            aOrbiterB = RotL64((aOrbiterB * 3543709971414550087U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 17885046834432626644U) + aOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 7757069274715713557U;
            aOrbiterG = RotL64((aOrbiterG * 15766885299397923879U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 2212805322061155615U) + aOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = (((aOrbiterE ^ aOrbiterI) ^ 6368539134638838822U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterE = RotL64((aOrbiterE * 13383744883433594259U), 57U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterI) + 5264326094252925613U) + aOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1]) + aNonceWordA;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 6126345334815012938U;
            aOrbiterA = RotL64((aOrbiterA * 17180934809764905307U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 13826731214018407061U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 6621261811613643620U;
            aOrbiterI = RotL64((aOrbiterI * 2823596473596114171U), 35U);
            //
            aIngress = RotL64(aOrbiterA, 43U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 30U));
            aIngress = aIngress + RotL64(aOrbiterC, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterA, 37U)) + aOrbiterC) + aWandererUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 51U) + RotL64(aOrbiterK, 29U)) + aOrbiterC) + RotL64(aCarry, 47U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 43U) + aOrbiterG) + RotL64(aOrbiterC, 53U)) + aNonceWordE);
            aWandererG = aWandererG + (((RotL64(aScatter, 35U) + RotL64(aOrbiterB, 60U)) + aOrbiterE) + aNonceWordK);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 23U) + aOrbiterK) + RotL64(aOrbiterG, 21U));
            aWandererH = aWandererH + (((((RotL64(aScatter, 5U) + aOrbiterI) + RotL64(aOrbiterA, 3U)) + RotL64(aCarry, 13U)) + aNonceWordH) + aWandererUpdateSaltE[((aIndex + 4U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 58U) + aOrbiterB) + RotL64(aOrbiterK, 43U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 34U));
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererH, 3U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ aNonceWordG;
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 29299U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27614U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 28633U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 30725U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aIngress, 3U)) ^ (RotL64(aCarry, 36U) + RotL64(aPrevious, 53U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((aWandererI + RotL64(aIngress, 5U)) + RotL64(aCarry, 41U)) + 12046647397183218524U;
            aOrbiterE = ((aWandererK + RotL64(aScatter, 54U)) + 2760779375026461991U) + aOrbiterAssignSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = (((aWandererD + RotL64(aPrevious, 35U)) + RotL64(aCarry, 23U)) + 13735454443176855650U) + aNonceWordK;
            aOrbiterB = (aWandererF + RotL64(aCross, 29U)) + 4370377000586647724U;
            aOrbiterI = (aWandererG + RotL64(aIngress, 11U)) + 14566322384189969094U;
            aOrbiterJ = ((((aWandererA + RotL64(aScatter, 43U)) + RotL64(aCarry, 57U)) + 5056565959818422786U) + aOrbiterAssignSaltC[((aIndex + 14U)) & S_SALT1]) + aNonceWordH;
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 23U)) + 8795403810686579209U) + aNonceWordL;
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 9625947666256011567U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 1703669290934254701U;
            aOrbiterF = RotL64((aOrbiterF * 5763881345676123583U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 6664070663184147951U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 2104148316797553431U;
            aOrbiterJ = RotL64((aOrbiterJ * 12887842067180975983U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 1197910004222596145U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 9922977170060903197U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13047828062605568603U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 2048376210852567829U) + aNonceWordN;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 12568990647075931409U;
            aOrbiterI = RotL64((aOrbiterI * 9860242601194210927U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 15026894775772902751U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 3439447160137900629U) ^ aOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1813754963043785165U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 6532671388552829796U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 17261098369835997661U;
            aOrbiterB = RotL64((aOrbiterB * 568292591215203521U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 3171300991007459947U) + aOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 5935563269327662024U;
            aOrbiterK = RotL64((aOrbiterK * 11271790283157765003U), 21U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterF, 29U);
            aIngress = aIngress + (RotL64(aOrbiterB, 53U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 46U));
            aIngress = aIngress + RotL64(aOrbiterE, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterJ, 29U)) + aOrbiterK);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 41U) + RotL64(aOrbiterB, 23U)) + aOrbiterJ) + RotL64(aCarry, 23U)) + aNonceWordG);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterB, 54U)) + aOrbiterF);
            aWandererD = aWandererD + (((RotL64(aIngress, 11U) + aOrbiterE) + RotL64(aOrbiterF, 13U)) + aWandererUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 51U) + aOrbiterA) + RotL64(aOrbiterJ, 37U)) + aNonceWordM);
            aWandererG = aWandererG + (((RotL64(aCross, 5U) + RotL64(aOrbiterI, 47U)) + aOrbiterJ) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 34U) + RotL64(aOrbiterK, 5U)) + aOrbiterI) + aWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 42U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererG, 19U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordO);
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
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xED6C13FD62F45D1BULL + 0xE8FCBF1123BCE8F6ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xC3EE12C7B5700F4DULL + 0xF230AAA3C0B38858ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x83C103252E543C9BULL + 0xD1C81897E7F17B8BULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xD49CDC03894E934FULL + 0xF650205D1660D170ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xB8C50E72F2C7AC67ULL + 0x801FD42B0A476A7AULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x9B395A11749875B5ULL + 0x98BBC57E0E47BCB4ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x87F92B368DDD748FULL + 0xE89C6B937778EE72ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x9687CDF7341149C9ULL + 0xB423ED2A0C7D2581ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xA0160A04B12E113FULL + 0xE6E380B9EF55BB63ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xD03326A67995631FULL + 0xA8FB111AD2D86EA1ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xC68CC7ADB5F19241ULL + 0xE0958FF84BF5EBEFULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xB177CEE527281649ULL + 0x8DDE5374BB40F1E8ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xC5FC16BD98C8DFE1ULL + 0x8FD35DF4A9DB534CULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xD01457D042143E6FULL + 0xD428954CC5228645ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xF755F4CAEE1439F5ULL + 0xB528B9DF7CC58531ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xC7C233245F23A2EFULL + 0xE7AB5C686FDCF1B9ULL);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 3325U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneC[((aIndex + 3447U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 4571U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((aIndex + 2075U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 11U) + RotL64(aPrevious, 47U)) ^ (RotL64(aIngress, 29U) + RotL64(aCarry, 60U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (((aWandererD + RotL64(aCross, 5U)) + RotL64(aCarry, 47U)) + 2101601659597850213U) + aOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = (((aWandererF + RotL64(aScatter, 29U)) + 2759794072560720121U) + aOrbiterAssignSaltB[((aIndex + 20U)) & S_SALT1]) + aNonceWordI;
            aOrbiterJ = (((aWandererA + RotL64(aIngress, 46U)) + RotL64(aCarry, 11U)) + 9443562552411269339U) + aNonceWordE;
            aOrbiterD = (aWandererB + RotL64(aPrevious, 53U)) + 10801360546699857975U;
            aOrbiterB = (aWandererH + RotL64(aIngress, 21U)) + 8020716394829332019U;
            aOrbiterI = ((aWandererI + RotL64(aScatter, 37U)) + RotL64(aCarry, 35U)) + 1021894212367773801U;
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 11U)) + 13346855534622490176U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 16359309548462953836U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 12642446944680783519U;
            aOrbiterJ = RotL64((aOrbiterJ * 12197935153255283321U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 8197424982767553380U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 14346334610901859094U;
            aOrbiterB = RotL64((aOrbiterB * 16982899923227935679U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 14171304260534233539U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 334531601308283605U;
            aOrbiterI = RotL64((aOrbiterI * 5012968232749075075U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 10707856298471572695U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 18364775750091914766U) ^ aNonceWordJ;
            aOrbiterH = RotL64((aOrbiterH * 15735143943129143265U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 8531394793118363836U) + aOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 15352876929406908882U) ^ aOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 475199047053777179U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 567682016232278157U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 2068146551757663119U;
            aOrbiterD = RotL64((aOrbiterD * 1557877740957797555U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 7776122587613256525U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 16430938890724272256U) ^ aOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4540270493783593257U), 21U);
            //
            aIngress = RotL64(aOrbiterJ, 3U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 39U));
            aIngress = aIngress + (RotL64(aOrbiterC, 53U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterA, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aCross, 43U) + RotL64(aOrbiterB, 50U)) + aOrbiterD) + RotL64(aCarry, 57U)) + aWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 29U) + aOrbiterD) + RotL64(aOrbiterI, 13U)) + aWandererUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 13U) + aOrbiterH) + RotL64(aOrbiterD, 57U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterJ, 5U)) + aOrbiterI);
            aWandererD = aWandererD + (((RotL64(aCross, 51U) + RotL64(aOrbiterI, 43U)) + aOrbiterA) + aNonceWordH);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 4U) + RotL64(aOrbiterC, 29U)) + aOrbiterI);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterI, 21U)) + aOrbiterB) + RotL64(aCarry, 19U)) + aNonceWordP);
            //
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererH);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 58U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + RotL64(aWandererF, 39U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordA);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 10259U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 8677U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 11936U)) & S_BLOCK1], 44U) ^ RotL64(aWorkLaneB[((aIndex + 8774U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCross, 39U)) + (RotL64(aIngress, 54U) ^ RotL64(aCarry, 23U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (((aWandererH + RotL64(aCross, 21U)) + RotL64(aCarry, 57U)) + 10038936806177516123U) + aNonceWordO;
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 57U)) + RotL64(aCarry, 35U)) + 1773168435195292638U;
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 30U)) + 10655711161526628072U) + aNonceWordN;
            aOrbiterF = (aWandererD + RotL64(aScatter, 11U)) + 14422295664639740437U;
            aOrbiterE = ((aWandererC + RotL64(aCross, 5U)) + 4125228715513159576U) + aNonceWordD;
            aOrbiterI = ((aWandererF + RotL64(aIngress, 51U)) + 3670449653158650845U) + aOrbiterAssignSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterK = (((aWandererJ + RotL64(aScatter, 43U)) + RotL64(aCarry, 5U)) + 17553727567180813057U) + aOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 5111401772713882743U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 7688573124662314413U;
            aOrbiterJ = RotL64((aOrbiterJ * 10846442063022821393U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 9438375825507814395U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 14177477039902118886U;
            aOrbiterC = RotL64((aOrbiterC * 6467406626985022537U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 16329942595859623928U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 3990536794006836672U;
            aOrbiterF = RotL64((aOrbiterF * 579024714339065373U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 5072881436583180756U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 16789727877867289997U;
            aOrbiterH = RotL64((aOrbiterH * 8766246302636197905U), 35U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterJ) + 17313956922306689438U) + aOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1]) + aNonceWordM;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 11530878396329822041U;
            aOrbiterE = RotL64((aOrbiterE * 11356860047841383129U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 3612616532321160196U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = (((aOrbiterI ^ aOrbiterK) ^ 4172189825359187763U) ^ aOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterI = RotL64((aOrbiterI * 12938945495299393177U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 8677279703778052804U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 1912172980909479362U;
            aOrbiterK = RotL64((aOrbiterK * 10053289257955474143U), 57U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterE, 29U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 19U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + RotL64(aOrbiterH, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 39U) + aOrbiterK) + RotL64(aOrbiterE, 53U));
            aWandererD = aWandererD + (((RotL64(aIngress, 47U) + RotL64(aOrbiterE, 13U)) + aOrbiterH) + RotL64(aCarry, 35U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 5U) + aOrbiterE) + RotL64(aOrbiterI, 27U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterC, 37U)) + aOrbiterI) + RotL64(aCarry, 11U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 60U) + aOrbiterJ) + RotL64(aOrbiterI, 47U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterF, 6U)) + aOrbiterJ) + aWandererUpdateSaltE[((aIndex + 18U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((((RotL64(aCross, 53U) + aOrbiterK) + RotL64(aOrbiterJ, 19U)) + aNonceWordI) + aWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererD);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 42U));
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererK, 57U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordC);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 23879U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneA[((aIndex + 23268U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 24048U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneC[((aIndex + 17876U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 19U) ^ RotL64(aIngress, 36U)) ^ (RotL64(aCarry, 51U) + RotL64(aPrevious, 5U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = ((aWandererA + RotL64(aCross, 13U)) + 16160838483846078448U) + aOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 57U)) + RotL64(aCarry, 5U)) + 15404960896190227946U;
            aOrbiterI = (((aWandererF + RotL64(aPrevious, 35U)) + RotL64(aCarry, 43U)) + 16904160594024977199U) + aNonceWordH;
            aOrbiterA = ((aWandererE + RotL64(aScatter, 48U)) + 17790460246821031802U) + aOrbiterAssignSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = ((aWandererG + RotL64(aCross, 27U)) + RotL64(aCarry, 57U)) + 16395168254086971959U;
            aOrbiterH = (aWandererH + RotL64(aScatter, 5U)) + 7484373204039901786U;
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 19U)) + 18026814691322913510U) + aNonceWordA;
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 15244817793136966450U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 5795491730356335666U) ^ aNonceWordG;
            aOrbiterI = RotL64((aOrbiterI * 13253529465289332171U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 3163873518027801504U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 2690791759507349172U;
            aOrbiterF = RotL64((aOrbiterF * 16677948635136515083U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 17898067251167087906U) + aOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 8028010015006604239U;
            aOrbiterC = RotL64((aOrbiterC * 5601629670521300241U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 7304739457289910555U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 6476837815096530043U) ^ aNonceWordB;
            aOrbiterA = RotL64((aOrbiterA * 16380545138701113267U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 14242499233467960602U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 17305645693017634630U;
            aOrbiterB = RotL64((aOrbiterB * 14442976693206929569U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 9772864059444171908U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 7897200728282156408U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 816306719390807411U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 4890999319172950996U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 8165132649356094963U) ^ aOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17297706071263690189U), 13U);
            //
            aIngress = RotL64(aOrbiterI, 11U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 39U));
            aIngress = aIngress + RotL64(aOrbiterB, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aPrevious, 3U) + aOrbiterI) + RotL64(aOrbiterG, 5U)) + RotL64(aCarry, 13U)) + aNonceWordE);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterF, 13U)) + aOrbiterA);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 11U) + aOrbiterG) + RotL64(aOrbiterF, 47U)) + RotL64(aCarry, 43U)) + aWandererUpdateSaltD[((aIndex + 14U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aCross, 29U) + aOrbiterB) + RotL64(aOrbiterH, 57U)) + aWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 37U) + RotL64(aOrbiterC, 19U)) + aOrbiterA);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 60U) + RotL64(aOrbiterG, 29U)) + aOrbiterH);
            aWandererH = aWandererH + ((RotL64(aIngress, 23U) + aOrbiterG) + RotL64(aOrbiterB, 40U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 60U) ^ aWandererH);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererJ, 11U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ aNonceWordC;
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 30410U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29550U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31324U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneD[((aIndex + 25022U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 6U) + RotL64(aIngress, 57U)) ^ (RotL64(aPrevious, 43U) ^ RotL64(aCarry, 29U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((((aWandererI + RotL64(aIngress, 60U)) + RotL64(aCarry, 47U)) + 8685374557928800912U) + aOrbiterAssignSaltB[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordP;
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 43U)) + 3482312691892161229U) + aOrbiterAssignSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterB = (aWandererE + RotL64(aCross, 29U)) + 6948130297389161165U;
            aOrbiterE = (aWandererF + RotL64(aPrevious, 19U)) + 5506385663788942690U;
            aOrbiterD = ((aWandererB + RotL64(aScatter, 5U)) + RotL64(aCarry, 13U)) + 17859982009307397161U;
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 13U)) + RotL64(aCarry, 35U)) + 9178488809207094043U;
            aOrbiterF = (aWandererG + RotL64(aIngress, 35U)) + 1835479501226057169U;
            //
            aOrbiterI = (((aOrbiterI + aOrbiterA) + 5368101733632614939U) + aOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 9050459666576835422U;
            aOrbiterB = RotL64((aOrbiterB * 10351719549990259551U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 9042186993119635078U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterE) ^ 17528342580198295025U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterG = RotL64((aOrbiterG * 14316671546614386775U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 6495418332558436882U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 8834495762667327342U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10783141541937645995U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 4364314196965690905U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 6357485231062120459U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 289429584586504995U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 3321488322626415347U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 10817330671781848737U;
            aOrbiterI = RotL64((aOrbiterI * 15875919466358823335U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 17974092279281611763U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 2871472057292789157U;
            aOrbiterE = RotL64((aOrbiterE * 16104199340711015181U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 15187929795092006849U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 13482063681546475923U;
            aOrbiterF = RotL64((aOrbiterF * 14466266308157364963U), 41U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterF, 27U);
            aIngress = aIngress + (RotL64(aOrbiterG, 46U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 19U));
            aIngress = aIngress + RotL64(aOrbiterD, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((((RotL64(aIngress, 19U) + RotL64(aOrbiterF, 3U)) + aOrbiterA) + RotL64(aCarry, 51U)) + aNonceWordH) + aWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterD, 11U)) + aOrbiterG);
            aWandererF = aWandererF + ((((RotL64(aCross, 3U) + RotL64(aOrbiterE, 43U)) + aOrbiterA) + RotL64(aCarry, 5U)) + aNonceWordL);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 44U) + aOrbiterF) + RotL64(aOrbiterG, 50U));
            aWandererB = aWandererB + (((RotL64(aScatter, 27U) + aOrbiterI) + RotL64(aOrbiterA, 57U)) + aWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterB, 27U)) + aOrbiterE) + aNonceWordF);
            aWandererE = aWandererE + ((RotL64(aIngress, 57U) + aOrbiterD) + RotL64(aOrbiterE, 21U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 40U));
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererE, 13U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ aNonceWordI;
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
    [[maybe_unused]] std::uint8_t *aOperationLaneA = pWorkSpace->mOperationLaneA;
    [[maybe_unused]] std::uint8_t *aOperationLaneB = pWorkSpace->mOperationLaneB;
    [[maybe_unused]] std::uint8_t *aOperationLaneC = pWorkSpace->mOperationLaneC;
    [[maybe_unused]] std::uint8_t *aOperationLaneD = pWorkSpace->mOperationLaneD;
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xFFFFF718BD40D813ULL + 0xCE9C7DDC2285882FULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x91B9E8E4F0B29B2BULL + 0x8077791C752BCA9BULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xACCF79E6CD16B379ULL + 0x9F81A4E45072F4A8ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xDB2C91F6A5CFE66BULL + 0xCF656E7B5FEBEE1BULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xD6177E905D71C351ULL + 0xF1F2BA4719A9A271ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xC2F51CEB2C6F81FFULL + 0x8547C21ABF1F11EAULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xA44F2798248F26CDULL + 0xEF2337D9EE8B46EFULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xEE4763F2EAB539DFULL + 0xF60F2114E82EA4E0ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x817EB5C288E35187ULL + 0xF074E2F4DFC32273ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xD8553B84F970BF27ULL + 0xDEC25168955DFC66ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x82894A3886A6B8D3ULL + 0xE86B8A1B0EF4F169ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xC172FD6CD8BBD043ULL + 0xF3E5185859914170ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xF19718335A14886BULL + 0xE400EEA93EF3E003ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xF9C404E489D43B11ULL + 0x8C696800672EB2A6ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x8A641E6F6A217C43ULL + 0xF0293F4251252B57ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xB3F37D53488E1311ULL + 0xA4376AFB5597FA87ULL);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 7924U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneC[((aIndex + 4802U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 7288U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 5209U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 51U) ^ RotL64(aCarry, 37U)) ^ (RotL64(aCross, 21U) + RotL64(aPrevious, 6U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererA + RotL64(aIngress, 13U)) + 13204735390996728477U) + aOrbiterAssignSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 21U)) + RotL64(aCarry, 29U)) + 851171359595647173U;
            aOrbiterF = (aWandererK + RotL64(aScatter, 57U)) + 16745304202825290723U;
            aOrbiterH = ((aWandererE + RotL64(aCross, 5U)) + 562392736584913979U) + aOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 34U)) + 3244267012529053918U;
            aOrbiterG = ((aWandererF + RotL64(aScatter, 11U)) + RotL64(aCarry, 43U)) + 17282536111067869133U;
            aOrbiterC = ((aWandererD + RotL64(aIngress, 19U)) + 14851130066471729068U) + aNonceWordA;
            aOrbiterD = (aWandererH + RotL64(aCross, 3U)) + 5256130407952363129U;
            aOrbiterK = (aWandererG + RotL64(aScatter, 51U)) + 2904742485828362001U;
            aOrbiterI = (aWandererC + RotL64(aIngress, 43U)) + 3723346325449225387U;
            aOrbiterJ = ((aWandererI + RotL64(aCross, 26U)) + RotL64(aCarry, 51U)) + 5344621093694027341U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 12919263300833603026U) + aNonceWordD;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 17989801264160996071U;
            aOrbiterF = RotL64((aOrbiterF * 15468293047311883751U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 5022175042377172157U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 16684822380107847758U;
            aOrbiterG = RotL64((aOrbiterG * 2834049270263837537U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 2740326510600876682U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 13981423865219318820U;
            aOrbiterB = RotL64((aOrbiterB * 14593082145080056441U), 13U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterI) + 231945878229848395U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordF;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 14139797734944312580U;
            aOrbiterH = RotL64((aOrbiterH * 6492256080432266407U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 16704102101387552373U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 8506734780526852552U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4684566118627414659U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 2774630043988894695U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 12490034334296488127U;
            aOrbiterK = RotL64((aOrbiterK * 16765455396278233145U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 545238171291436006U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 1023872898002379590U;
            aOrbiterJ = RotL64((aOrbiterJ * 8626333831510136515U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 5065187021047872560U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 10391809965648089863U;
            aOrbiterE = RotL64((aOrbiterE * 10912471108849550469U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 5576919045471579002U) + aOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 9761904001375034639U;
            aOrbiterA = RotL64((aOrbiterA * 8612901811320541361U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 2001472279505185946U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 11576457012366242134U) ^ aNonceWordO;
            aOrbiterD = RotL64((aOrbiterD * 1070815118051466731U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 17713147845216099336U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 13204735390996728477U;
            aOrbiterI = RotL64((aOrbiterI * 10889281795183444943U), 41U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterK, 41U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 11U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 29U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 35U));
            aIngress = aIngress + (RotL64(aOrbiterA, 44U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterF, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterE, 35U)) + aOrbiterB);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 37U) + aOrbiterB) + RotL64(aOrbiterD, 26U));
            aWandererC = aWandererC + ((RotL64(aCross, 21U) + RotL64(aOrbiterG, 37U)) + aOrbiterA);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 43U) + aOrbiterJ) + RotL64(aOrbiterD, 43U)) + aWandererUpdateSaltC[((aIndex + 6U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 13U) + aOrbiterA) + RotL64(aOrbiterJ, 57U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterC, 20U)) + aOrbiterH);
            aWandererH = aWandererH + (((RotL64(aCross, 52U) + RotL64(aOrbiterH, 47U)) + aOrbiterI) + RotL64(aCarry, 37U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 35U) + aOrbiterD) + RotL64(aOrbiterA, 51U)) + aNonceWordH);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 41U) + aOrbiterC) + RotL64(aOrbiterF, 39U)) + RotL64(aCarry, 51U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterD, 3U)) + aOrbiterH);
            aWandererE = aWandererE + (((RotL64(aPrevious, 24U) + RotL64(aOrbiterK, 29U)) + aOrbiterC) + aWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 50U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 37U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 41U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + RotL64(aWandererA, 54U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordP);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 10024U)) & S_BLOCK1], 40U) ^ RotL64(aExpandLaneD[((aIndex + 10507U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 14151U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((aIndex + 15641U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 60U) ^ RotL64(aPrevious, 27U)) ^ (RotL64(aCross, 11U) + RotL64(aIngress, 47U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 41U)) + 16451272412693907816U) + aOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = (aWandererA + RotL64(aCross, 26U)) + 10099485419723255462U;
            aOrbiterH = (aWandererJ + RotL64(aScatter, 39U)) + 17668900099534923192U;
            aOrbiterB = (aWandererD + RotL64(aIngress, 13U)) + 5497093724143181753U;
            aOrbiterD = (aWandererF + RotL64(aScatter, 53U)) + 10354044773550071706U;
            aOrbiterJ = (((aWandererE + RotL64(aPrevious, 58U)) + RotL64(aCarry, 41U)) + 12728258851198019099U) + aOrbiterAssignSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = (((aWandererI + RotL64(aCross, 29U)) + RotL64(aCarry, 51U)) + 4144050505314242618U) + aNonceWordH;
            aOrbiterI = ((aWandererK + RotL64(aIngress, 21U)) + RotL64(aCarry, 47U)) + 14133805325480076530U;
            aOrbiterF = ((aWandererC + RotL64(aCross, 5U)) + 308863673210602899U) + aNonceWordP;
            aOrbiterA = (aWandererB + RotL64(aIngress, 23U)) + 11741180130160569753U;
            aOrbiterC = ((aWandererG + RotL64(aScatter, 19U)) + 12926863156769180448U) + aNonceWordN;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 211920854786494259U) + aOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 13234608842479411078U) ^ aNonceWordF;
            aOrbiterH = RotL64((aOrbiterH * 2556747209733759467U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 9164711974854618892U) + aNonceWordC;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 6667377062281954219U;
            aOrbiterK = RotL64((aOrbiterK * 2603737166987437649U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 4559040002406721850U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 1749875480850675109U;
            aOrbiterD = RotL64((aOrbiterD * 15822640067349481089U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 9555365165561936366U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 18289733999504213574U;
            aOrbiterG = RotL64((aOrbiterG * 14156217554673229429U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 8727162691639622461U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 291406782452963706U;
            aOrbiterF = RotL64((aOrbiterF * 8413500075082350243U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 8294911802626492257U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 15853578397277298548U) ^ aOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13256191781365357747U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 11535146194939658681U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 2177540476748375661U;
            aOrbiterB = RotL64((aOrbiterB * 15791341922007841029U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 2705306323728084136U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 17617871830709148043U;
            aOrbiterJ = RotL64((aOrbiterJ * 3449981219502809255U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 3699834746313613206U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 17952609181629473245U) ^ aNonceWordI;
            aOrbiterI = RotL64((aOrbiterI * 6103160209028988839U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 8016694658897707674U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 6971251395823324489U;
            aOrbiterA = RotL64((aOrbiterA * 13483776115929040277U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 17467528888050817915U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 16451272412693907816U;
            aOrbiterC = RotL64((aOrbiterC * 13689734638238895071U), 29U);
            //
            aIngress = RotL64(aOrbiterK, 21U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterA, 35U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 38U));
            aIngress = aIngress + (RotL64(aOrbiterD, 53U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 51U));
            aIngress = aIngress + RotL64(aOrbiterH, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aCross, 41U) + aOrbiterA) + RotL64(aOrbiterD, 29U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterE, 11U)) + aOrbiterK) + aWandererUpdateSaltE[((aIndex + 8U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 21U) + aOrbiterG) + RotL64(aOrbiterC, 26U)) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 58U) + RotL64(aOrbiterF, 51U)) + aOrbiterG);
            aWandererD = aWandererD + (((RotL64(aScatter, 51U) + aOrbiterB) + RotL64(aOrbiterD, 19U)) + RotL64(aCarry, 57U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 13U) + aOrbiterJ) + RotL64(aOrbiterK, 47U)) + aWandererUpdateSaltA[((aIndex + 14U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterH, 39U)) + aOrbiterB);
            aWandererE = aWandererE ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterJ, 57U)) + aOrbiterC) + aNonceWordD);
            aWandererG = aWandererG + ((RotL64(aScatter, 53U) + aOrbiterG) + RotL64(aOrbiterD, 21U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 46U) + aOrbiterG) + RotL64(aOrbiterH, 35U)) + aNonceWordM);
            aWandererJ = aWandererJ + (((RotL64(aCross, 27U) + RotL64(aOrbiterI, 6U)) + aOrbiterK) + aNonceWordE);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 34U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 51U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 37U));
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererA, 10U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererH, 57U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ aNonceWordM;
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 23631U)) & S_BLOCK1], 42U) ^ RotL64(aOperationLaneA[((aIndex + 23980U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17801U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneC[((aIndex + 21615U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aPrevious, 11U)) + (RotL64(aIngress, 35U) + RotL64(aCarry, 54U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererE + RotL64(aScatter, 23U)) + 3550722402315312207U;
            aOrbiterF = (aWandererD + RotL64(aCross, 41U)) + 16724184551669522754U;
            aOrbiterE = (aWandererK + RotL64(aPrevious, 30U)) + 981751330116773021U;
            aOrbiterC = (aWandererB + RotL64(aIngress, 47U)) + 7891159229704944868U;
            aOrbiterH = (aWandererA + RotL64(aPrevious, 35U)) + 13618396711464799841U;
            aOrbiterA = (aWandererI + RotL64(aScatter, 11U)) + 5969291018449003648U;
            aOrbiterD = ((((aWandererF + RotL64(aCross, 4U)) + RotL64(aCarry, 43U)) + 14595540413313640042U) + aOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1]) + aNonceWordM;
            aOrbiterK = (aWandererC + RotL64(aIngress, 27U)) + 3287990436916111762U;
            aOrbiterI = ((aWandererG + RotL64(aPrevious, 37U)) + RotL64(aCarry, 29U)) + 12534369400200483704U;
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 13U)) + RotL64(aCarry, 21U)) + 2277312067930392274U;
            aOrbiterG = ((aWandererH + RotL64(aIngress, 19U)) + 10026320559261334353U) + aOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 11258082063135659551U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 1445958517675746990U;
            aOrbiterE = RotL64((aOrbiterE * 10062265337488757971U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 1011298251290970844U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 6487834862470043744U) ^ aNonceWordD;
            aOrbiterA = RotL64((aOrbiterA * 15477913837027179675U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 9966279022928268335U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 10285993486057704393U;
            aOrbiterF = RotL64((aOrbiterF * 15965714363201157535U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 16005362468813966136U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 223843444699390781U;
            aOrbiterH = RotL64((aOrbiterH * 665392038954573081U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 18178876294968532775U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 12490136112181806806U;
            aOrbiterK = RotL64((aOrbiterK * 16380841616662993709U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 8775696166557913635U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 16464340319444310842U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 18111632334728200721U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 6296039992673546227U) + aOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 7152939277656436037U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15183918431501487319U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 14066791413416223271U) + aOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 5026743227399908016U;
            aOrbiterC = RotL64((aOrbiterC * 5891343232759075675U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 12923870516588764609U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 2509970166609982397U;
            aOrbiterD = RotL64((aOrbiterD * 10708677957633925007U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 15155802288437422950U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 15615656627428205711U;
            aOrbiterI = RotL64((aOrbiterI * 6199439196177598589U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 17233751123865498186U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 3550722402315312207U;
            aOrbiterG = RotL64((aOrbiterG * 2247546626523919155U), 27U);
            //
            aIngress = RotL64(aOrbiterI, 57U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterG, 27U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 13U));
            aIngress = aIngress + (RotL64(aOrbiterK, 39U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterF, 43U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterJ, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 13U) + aOrbiterH) + RotL64(aOrbiterK, 48U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 29U) + aOrbiterF) + RotL64(aOrbiterC, 13U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 20U) + RotL64(aOrbiterD, 27U)) + aOrbiterE);
            aWandererD = aWandererD + ((((RotL64(aScatter, 27U) + RotL64(aOrbiterI, 41U)) + aOrbiterG) + RotL64(aCarry, 27U)) + aWandererUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aCross, 37U) + aOrbiterJ) + RotL64(aOrbiterB, 43U)) + aWandererUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 41U) + RotL64(aOrbiterE, 5U)) + aOrbiterH) + aNonceWordL);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 53U) + aOrbiterF) + RotL64(aOrbiterA, 23U));
            aWandererH = aWandererH + ((((RotL64(aIngress, 10U) + aOrbiterD) + RotL64(aOrbiterH, 52U)) + RotL64(aCarry, 47U)) + aNonceWordK);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterC, 57U)) + aOrbiterA);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 35U) + RotL64(aOrbiterG, 39U)) + aOrbiterH);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterB, 21U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 38U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererK);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + RotL64(aWandererH, 46U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordP);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 31973U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29704U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 28886U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneD[((aIndex + 30258U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 19U) ^ RotL64(aIngress, 38U)) + (RotL64(aPrevious, 5U) + RotL64(aCross, 57U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (aWandererI + RotL64(aIngress, 57U)) + 785861751704720606U;
            aOrbiterG = (aWandererE + RotL64(aCross, 39U)) + 15968088718435606299U;
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 29U)) + RotL64(aCarry, 47U)) + 1393976526590347151U;
            aOrbiterE = ((aWandererH + RotL64(aScatter, 27U)) + 17240750947292745884U) + aOrbiterAssignSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterA = (aWandererC + RotL64(aIngress, 23U)) + 4921576136163183137U;
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 53U)) + 3334047873553153032U) + aNonceWordP;
            aOrbiterD = ((((aWandererD + RotL64(aScatter, 10U)) + RotL64(aCarry, 51U)) + 15086509978458408698U) + aOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordM;
            aOrbiterH = (aWandererG + RotL64(aCross, 19U)) + 892391205397581998U;
            aOrbiterJ = (((aWandererJ + RotL64(aIngress, 51U)) + RotL64(aCarry, 23U)) + 2965686403183767521U) + aNonceWordC;
            aOrbiterF = (aWandererK + RotL64(aCross, 5U)) + 14632215393655706170U;
            aOrbiterB = (aWandererF + RotL64(aScatter, 42U)) + 15740589515342377322U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 11131164813943086445U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 6988080581278900960U;
            aOrbiterK = RotL64((aOrbiterK * 6412189142344044255U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 16021254613117657178U) + aOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 6183615599897921154U) ^ aNonceWordL;
            aOrbiterA = RotL64((aOrbiterA * 9976411093264211033U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 12533992547026652747U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 3104325358982904219U;
            aOrbiterI = RotL64((aOrbiterI * 14977348108778147265U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 3878525937957474644U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 2120435259884368445U;
            aOrbiterD = RotL64((aOrbiterD * 15964718652193073177U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 14928658302694194856U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 9121310461310309348U) ^ aNonceWordK;
            aOrbiterH = RotL64((aOrbiterH * 17304439784647477491U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 3715693239100476493U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 7336577492932262490U) ^ aOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11074754160002665253U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 2312452827448455675U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 4322756069651934618U;
            aOrbiterF = RotL64((aOrbiterF * 6908893297397073539U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 4962079617577705818U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 5072727464750706525U;
            aOrbiterB = RotL64((aOrbiterB * 4947670001221089155U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 4553791875259778686U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 15823770920225774233U;
            aOrbiterC = RotL64((aOrbiterC * 409663191536830375U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 9468608484284459072U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 8658861660659699947U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2933359123761406353U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 14453429515273506170U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 785861751704720606U;
            aOrbiterE = RotL64((aOrbiterE * 3544627380583668815U), 5U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterB, 43U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 56U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 35U));
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterF, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aIngress, 35U) + aOrbiterH) + RotL64(aOrbiterK, 50U)) + aWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterE, 27U)) + aOrbiterF) + aWandererUpdateSaltC[((aIndex + 12U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 40U) + RotL64(aOrbiterJ, 39U)) + aOrbiterF) + RotL64(aCarry, 37U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterA, 35U)) + aOrbiterH);
            aWandererE = aWandererE + (((RotL64(aIngress, 37U) + RotL64(aOrbiterC, 53U)) + aOrbiterD) + aNonceWordH);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterG, 29U)) + aOrbiterC) + aNonceWordJ);
            aWandererH = aWandererH + ((RotL64(aScatter, 56U) + aOrbiterI) + RotL64(aOrbiterC, 6U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 27U) + aOrbiterF) + RotL64(aOrbiterB, 21U)) + aNonceWordG);
            aWandererK = aWandererK + (((RotL64(aIngress, 3U) + RotL64(aOrbiterI, 41U)) + aOrbiterG) + RotL64(aCarry, 23U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterK, 11U)) + aOrbiterA);
            aWandererG = aWandererG + ((RotL64(aScatter, 11U) + RotL64(aOrbiterD, 43U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 60U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 51U));
            aCarry = aCarry + (RotL64(aWandererK, 29U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererA, 44U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ aNonceWordF;
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
    [[maybe_unused]] std::uint8_t *aOperationLaneA = pWorkSpace->mOperationLaneA;
    [[maybe_unused]] std::uint8_t *aOperationLaneB = pWorkSpace->mOperationLaneB;
    [[maybe_unused]] std::uint8_t *aOperationLaneC = pWorkSpace->mOperationLaneC;
    [[maybe_unused]] std::uint8_t *aOperationLaneD = pWorkSpace->mOperationLaneD;
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xAB5C9E550F413E75ULL + 0xB9C3455BD73BA790ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x873F42E57DC449ADULL + 0xFD03C21DF6DD4E72ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x813E8879352543FDULL + 0xF8493F58E6D4AA6DULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xC28C7027AE2FCBD7ULL + 0xC313EA9B0184C85FULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xFC21C93F8F8B6D19ULL + 0xC7DD8AD67C233CC7ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x8B0F3AACDAD6AA4DULL + 0xA0B4519042195CB4ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xF206A0E8458EC74DULL + 0xEF77A274808BB0F9ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x8ECA655ACD2508ADULL + 0xBEC7ACCC60576236ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xB6F6A127FFE1C605ULL + 0xD43AF8E757917E4CULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x823CE413B84B8F97ULL + 0xE0697A4053F26CA4ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x8768CE5CAAE427AFULL + 0x90900EE66630B150ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xFC0E35028773D4ABULL + 0xB01C8B812D4AFCCCULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x8DA9625B79174AC1ULL + 0xD95086399A97A0BAULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xA05708D975B02997ULL + 0xDFC80595ACF3549DULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x853A7B4A58FD1961ULL + 0xA749F903F87C5F83ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xAD51DADAEC0FC471ULL + 0xC2058F70F1BBD6BBULL);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 2391U)) & S_BLOCK1], 20U) ^ RotL64(aOperationLaneC[((aIndex + 2970U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 2780U)) & S_BLOCK1], 12U) ^ RotL64(aOperationLaneA[((aIndex + 3028U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 26U) + RotL64(aPrevious, 51U)) + (RotL64(aIngress, 39U) ^ RotL64(aCarry, 5U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((aWandererG + RotL64(aCross, 34U)) + 11998579547770778580U) + aOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = (((aWandererF + RotL64(aPrevious, 3U)) + RotL64(aCarry, 35U)) + 8409465187298704610U) + aNonceWordO;
            aOrbiterD = (aWandererC + RotL64(aIngress, 27U)) + 3470222286110333500U;
            aOrbiterI = ((aWandererK + RotL64(aScatter, 47U)) + RotL64(aCarry, 21U)) + 5704486785203069994U;
            aOrbiterG = ((aWandererE + RotL64(aCross, 41U)) + RotL64(aCarry, 51U)) + 10334944660253279633U;
            aOrbiterF = (aWandererB + RotL64(aPrevious, 51U)) + 7626852700722567477U;
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 11U)) + 14631310754943209743U) + aNonceWordP;
            aOrbiterC = (aWandererA + RotL64(aScatter, 58U)) + 807160297237854120U;
            aOrbiterB = ((aWandererI + RotL64(aIngress, 19U)) + 5624154783624196107U) + aOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 4971444394698940423U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 6340057638461027062U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12027586111086798629U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 9003019862787819481U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 13632057463595873033U;
            aOrbiterF = RotL64((aOrbiterF * 12575202147280216765U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 12766104026871797746U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 4062118445824915939U;
            aOrbiterC = RotL64((aOrbiterC * 13130770039048080701U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 5258212525426469978U) + aNonceWordH;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 9956946981015983939U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8106382657040497669U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 10837606223056473999U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 13292864885504191134U;
            aOrbiterH = RotL64((aOrbiterH * 4445739587553669471U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 166087925900318658U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 6786842221885441388U;
            aOrbiterI = RotL64((aOrbiterI * 4411147600413147773U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 16888086378070246404U) + aNonceWordB;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 5240855484445974002U;
            aOrbiterK = RotL64((aOrbiterK * 402652898573422271U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 6874866669211571608U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 732890824978127460U) ^ aOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3776365957702257453U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 5541380495707308058U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 17947326584411475765U;
            aOrbiterG = RotL64((aOrbiterG * 10920952349981652899U), 23U);
            //
            aIngress = RotL64(aOrbiterB, 22U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterI, 19U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterE, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterK, 27U)) + aOrbiterC) + aNonceWordN);
            aWandererK = aWandererK + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterE, 57U)) + aOrbiterH) + RotL64(aCarry, 37U)) + aWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 6U) + RotL64(aOrbiterD, 35U)) + aOrbiterF);
            aWandererF = aWandererF + ((RotL64(aCross, 13U) + aOrbiterG) + RotL64(aOrbiterE, 40U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterI, 53U)) + aOrbiterB) + aNonceWordA);
            aWandererJ = aWandererJ + (((RotL64(aCross, 23U) + aOrbiterK) + RotL64(aOrbiterE, 23U)) + RotL64(aCarry, 3U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterH, 11U)) + aOrbiterC) + aWandererUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 18U) + aOrbiterI) + RotL64(aOrbiterG, 3U)) + aNonceWordE);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterD, 46U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererJ, 40U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererI);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 37U));
            aCarry = aCarry + RotL64(aWandererG, 3U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordF);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 7026U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneD[((aIndex + 10739U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 5720U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneB[((aIndex + 10587U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCarry, 10U)) ^ (RotL64(aPrevious, 39U) + RotL64(aCross, 27U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (((aWandererA + RotL64(aScatter, 35U)) + RotL64(aCarry, 3U)) + 11210042748013785976U) + aOrbiterAssignSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = (((aWandererF + RotL64(aPrevious, 47U)) + RotL64(aCarry, 35U)) + 4584747303233477454U) + aOrbiterAssignSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterE = ((aWandererB + RotL64(aCross, 5U)) + RotL64(aCarry, 21U)) + 8878765929792969517U;
            aOrbiterI = (aWandererD + RotL64(aIngress, 39U)) + 2172232330280041122U;
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 12U)) + 8378937026022264016U) + aNonceWordN;
            aOrbiterD = (aWandererG + RotL64(aScatter, 19U)) + 8683007464695824208U;
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 23U)) + 9564352997357118134U) + aNonceWordK;
            aOrbiterA = (aWandererC + RotL64(aCross, 27U)) + 11713878436769887528U;
            aOrbiterG = (aWandererH + RotL64(aIngress, 60U)) + 8052917623074021077U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 7720597162792145185U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 2602847785328475621U;
            aOrbiterE = RotL64((aOrbiterE * 14065077077207224525U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 17813669222300509724U) + aNonceWordI;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 8724263063156573013U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3632927017737834359U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 6882429835961613492U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 13213313479525717359U;
            aOrbiterC = RotL64((aOrbiterC * 2411431247725974895U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 2401526093648669573U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 3616448566579979749U;
            aOrbiterA = RotL64((aOrbiterA * 13323155103752121393U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 18268262471839710401U) + aNonceWordD;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 5116424918948694752U;
            aOrbiterG = RotL64((aOrbiterG * 7641143782996332069U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 11405305689555640431U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 12427591396711015574U) ^ aOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8112834135715541223U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 16960781161508084626U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 12382604781005282628U) ^ aNonceWordP;
            aOrbiterI = RotL64((aOrbiterI * 17196168631120103115U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 10054839091354729292U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 4167641616532985407U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 919291747187787625U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 14383737233143309039U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 16258779988369405932U;
            aOrbiterJ = RotL64((aOrbiterJ * 8348773195366160215U), 23U);
            //
            aIngress = RotL64(aOrbiterA, 51U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterG, 29U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterE, 44U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 11U));
            aIngress = aIngress + RotL64(aOrbiterH, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterE, 18U)) + aOrbiterC);
            aWandererF = aWandererF + ((((RotL64(aCross, 51U) + aOrbiterD) + RotL64(aOrbiterH, 53U)) + RotL64(aCarry, 47U)) + aNonceWordA);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 19U) + aOrbiterH) + RotL64(aOrbiterJ, 27U));
            aWandererC = aWandererC + ((((RotL64(aIngress, 30U) + aOrbiterK) + RotL64(aOrbiterI, 47U)) + aNonceWordH) + aWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 35U) + aOrbiterJ) + RotL64(aOrbiterC, 35U));
            aWandererB = aWandererB + ((((RotL64(aScatter, 13U) + RotL64(aOrbiterG, 13U)) + aOrbiterJ) + RotL64(aCarry, 21U)) + aWandererUpdateSaltB[((aIndex + 24U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterG, 39U)) + aOrbiterI);
            aWandererI = aWandererI + ((RotL64(aIngress, 44U) + aOrbiterI) + RotL64(aOrbiterA, 23U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterC, 60U)) + aOrbiterI) + aNonceWordM);
            //
            aCarry = aCarry + (RotL64(aWandererA, 37U) ^ aWandererF);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + (RotL64(aWandererC, 43U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererJ, 40U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ aNonceWordH;
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 13484U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15613U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 12215U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 16095U)) & S_BLOCK1], 34U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 11U) + RotL64(aPrevious, 24U)) + (RotL64(aCarry, 41U) ^ RotL64(aIngress, 57U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (aWandererD + RotL64(aScatter, 51U)) + 13583136155674166402U;
            aOrbiterI = ((aWandererA + RotL64(aCross, 28U)) + RotL64(aCarry, 27U)) + 12830472187484919497U;
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 39U)) + 18081197909484522509U) + aOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = (aWandererJ + RotL64(aIngress, 3U)) + 8680634051297891550U;
            aOrbiterE = ((aWandererB + RotL64(aScatter, 35U)) + RotL64(aCarry, 47U)) + 13939998767458656823U;
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 43U)) + 1795730579103692594U) + aNonceWordJ;
            aOrbiterA = (aWandererH + RotL64(aIngress, 18U)) + 17369751719734069999U;
            aOrbiterH = (((aWandererC + RotL64(aCross, 13U)) + 224769585901248068U) + aOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordF;
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 57U)) + RotL64(aCarry, 13U)) + 4133547085925268180U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 7022512056309567391U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 10319484359046945495U;
            aOrbiterC = RotL64((aOrbiterC * 3400140531307001933U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 10483878349412282069U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 6481381149199985736U;
            aOrbiterK = RotL64((aOrbiterK * 9701719367082506253U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 13721077228796934509U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 9704818014314175007U;
            aOrbiterD = RotL64((aOrbiterD * 760445624027740287U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 6253040047758584339U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 16890211690273641226U;
            aOrbiterI = RotL64((aOrbiterI * 5622534399866057841U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 6216227831265032436U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 2023609047004658739U;
            aOrbiterE = RotL64((aOrbiterE * 3252332895698310147U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 9201669637050388263U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterA) ^ 5106927540934338576U) ^ aOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterJ = RotL64((aOrbiterJ * 6368134569042291431U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 10080368957861445998U) + aOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 10784789383436485808U;
            aOrbiterA = RotL64((aOrbiterA * 3794918350254445939U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 15426339824951793026U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 17637144549368340331U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10971293914614704441U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 9941300382181962134U) + aNonceWordD;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 8118046374121322097U) ^ aNonceWordN;
            aOrbiterG = RotL64((aOrbiterG * 8481945819050983127U), 51U);
            //
            aIngress = RotL64(aOrbiterI, 20U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterJ, 43U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 27U));
            aIngress = aIngress + RotL64(aOrbiterH, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aPrevious, 57U) + aOrbiterA) + RotL64(aOrbiterG, 53U)) + RotL64(aCarry, 5U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 4U) + aOrbiterD) + RotL64(aOrbiterJ, 43U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 35U) + aOrbiterC) + RotL64(aOrbiterH, 19U)) + aWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 21U) + aOrbiterI) + RotL64(aOrbiterK, 14U));
            aWandererA = aWandererA + (((RotL64(aCross, 53U) + RotL64(aOrbiterD, 23U)) + aOrbiterE) + RotL64(aCarry, 47U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 28U) + aOrbiterI) + RotL64(aOrbiterC, 5U));
            aWandererB = aWandererB + (((RotL64(aIngress, 39U) + aOrbiterC) + RotL64(aOrbiterK, 47U)) + aNonceWordG);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 47U) + aOrbiterA) + RotL64(aOrbiterI, 37U)) + aNonceWordL);
            aWandererC = aWandererC + (((RotL64(aPrevious, 11U) + aOrbiterC) + RotL64(aOrbiterD, 10U)) + aWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererE);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 34U));
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + RotL64(aWandererB, 13U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordJ);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 17497U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneB[((aIndex + 18533U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18460U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 21489U)) & S_BLOCK1], 34U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aIngress, 12U)) ^ (RotL64(aCarry, 27U) ^ RotL64(aPrevious, 57U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (aWandererI + RotL64(aCross, 53U)) + 1297415699043177788U;
            aOrbiterK = (aWandererE + RotL64(aPrevious, 57U)) + 17583786534509260153U;
            aOrbiterI = (aWandererK + RotL64(aIngress, 28U)) + 643197858925708798U;
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 39U)) + 5062653766915694874U) + aOrbiterAssignSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterA = (aWandererC + RotL64(aIngress, 19U)) + 7034273638367180511U;
            aOrbiterD = ((aWandererA + RotL64(aCross, 5U)) + RotL64(aCarry, 21U)) + 2026909726972916996U;
            aOrbiterF = ((aWandererB + RotL64(aScatter, 47U)) + RotL64(aCarry, 13U)) + 2785690475553211646U;
            aOrbiterB = (((aWandererH + RotL64(aPrevious, 11U)) + RotL64(aCarry, 35U)) + 2910341716302991892U) + aOrbiterAssignSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterJ = ((aWandererG + RotL64(aIngress, 34U)) + 2834181605200829791U) + aNonceWordM;
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 13323052600571281928U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 10434901530315760460U;
            aOrbiterI = RotL64((aOrbiterI * 2042210188346767033U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 247903955625194782U) + aNonceWordO;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 5196515747387257163U) ^ aOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1799024689023272275U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 7196305682377987476U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 14777739876892587484U;
            aOrbiterF = RotL64((aOrbiterF * 95220583948241581U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 10609060796540136671U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 8386027207212484155U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4855610536246556893U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 729659744301903424U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 2350564261412606157U;
            aOrbiterC = RotL64((aOrbiterC * 16713856782349084977U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 16611987556673864177U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 1525195188708550503U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10045858602151004553U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 4654808490980989596U) + aNonceWordH;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 8189569777087686263U;
            aOrbiterB = RotL64((aOrbiterB * 17278657566389299577U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 10932857495004451792U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 1833880112534916813U;
            aOrbiterJ = RotL64((aOrbiterJ * 8004341577533825681U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 13100236350175516423U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 2773759534195186313U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3194954066097323161U), 53U);
            //
            aIngress = RotL64(aOrbiterF, 19U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterB, 39U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 6U));
            aIngress = aIngress + (RotL64(aOrbiterI, 47U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterA, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aCross, 47U) + RotL64(aOrbiterI, 23U)) + aOrbiterA) + RotL64(aCarry, 53U)) + aWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 37U) + aOrbiterB) + RotL64(aOrbiterA, 34U)) + aNonceWordI);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 23U) + aOrbiterG) + RotL64(aOrbiterK, 27U)) + RotL64(aCarry, 39U)) + aNonceWordB);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterA, 47U)) + aOrbiterJ);
            aWandererC = aWandererC + ((RotL64(aCross, 30U) + aOrbiterB) + RotL64(aOrbiterD, 43U));
            aWandererE = aWandererE ^ ((((RotL64(aPrevious, 43U) + RotL64(aOrbiterA, 51U)) + aOrbiterC) + aNonceWordN) + aWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 51U) + RotL64(aOrbiterJ, 39U)) + aOrbiterF);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 3U) + aOrbiterC) + RotL64(aOrbiterD, 13U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 12U) + RotL64(aOrbiterC, 4U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererA, 36U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererK);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + RotL64(aWandererC, 19U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ aNonceWordO;
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 25123U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((aIndex + 27282U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26478U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23000U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 4U) + RotL64(aPrevious, 53U)) ^ (RotL64(aIngress, 37U) + RotL64(aCarry, 23U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = ((aWandererA + RotL64(aCross, 47U)) + RotL64(aCarry, 21U)) + 17225673071833726819U;
            aOrbiterK = (aWandererD + RotL64(aIngress, 30U)) + 10301458382103627331U;
            aOrbiterB = ((aWandererB + RotL64(aScatter, 13U)) + RotL64(aCarry, 43U)) + 3960233050857362414U;
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 51U)) + 17768665685046605837U) + aOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = (aWandererI + RotL64(aIngress, 37U)) + 14471018461213959767U;
            aOrbiterJ = (aWandererK + RotL64(aCross, 60U)) + 10730597892721340453U;
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 5U)) + RotL64(aCarry, 13U)) + 14863394003122760542U;
            aOrbiterE = ((aWandererF + RotL64(aScatter, 19U)) + 9948587274816688296U) + aOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 43U)) + 3573569431435100993U) + aNonceWordG;
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 8153670675740450590U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 16438856577722561424U;
            aOrbiterB = RotL64((aOrbiterB * 4689247488336908827U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 15765587867581925041U) + aNonceWordM;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 1082039522061775213U;
            aOrbiterJ = RotL64((aOrbiterJ * 17023740047246402641U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 4202521649260798876U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 15877659681260461141U) ^ aOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11369910758551088173U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 2551560426129646123U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 3005102326163906320U;
            aOrbiterA = RotL64((aOrbiterA * 4241583192662435107U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 1675501058857208089U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 12774812270956702043U) ^ aOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5488437008504905105U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 1044886020922563597U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 4857445127457225171U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13223560654459705259U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 11548725551787560962U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 2434677823189765161U;
            aOrbiterD = RotL64((aOrbiterD * 4283026044563670969U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 9606875320524736294U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 13732615866277657704U;
            aOrbiterK = RotL64((aOrbiterK * 3905528919281629775U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 13921743663803299567U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 13350829301153929899U;
            aOrbiterI = RotL64((aOrbiterI * 11858642286713079795U), 3U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterF, 13U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 10U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 47U));
            aIngress = aIngress + (RotL64(aOrbiterG, 53U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterK, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterA, 29U)) + aOrbiterE) + RotL64(aCarry, 53U)) + aWandererUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 46U) + aOrbiterB) + RotL64(aOrbiterF, 21U));
            aWandererI = aWandererI + ((((RotL64(aCross, 41U) + RotL64(aOrbiterB, 60U)) + aOrbiterJ) + RotL64(aCarry, 19U)) + aNonceWordI);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterG, 47U)) + aOrbiterJ) + aNonceWordK);
            aWandererE = aWandererE + ((RotL64(aCross, 19U) + RotL64(aOrbiterG, 51U)) + aOrbiterI);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 56U) + RotL64(aOrbiterB, 41U)) + aOrbiterD) + aWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aPrevious, 13U) + RotL64(aOrbiterB, 11U)) + aOrbiterK);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 3U) + aOrbiterD) + RotL64(aOrbiterE, 3U)) + aNonceWordC);
            aWandererB = aWandererB + ((RotL64(aCross, 23U) + aOrbiterD) + RotL64(aOrbiterF, 56U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererB);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 5U));
            aCarry = aCarry + RotL64(aWandererF, 22U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ aNonceWordL;
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 28205U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28065U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27749U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((aIndex + 31072U)) & S_BLOCK1], 44U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 54U) ^ RotL64(aCarry, 5U)) + (RotL64(aIngress, 41U) + RotL64(aCross, 27U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 47U)) + 964165145848253292U) + aOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = (aWandererC + RotL64(aIngress, 19U)) + 10645976767204934746U;
            aOrbiterF = ((aWandererJ + RotL64(aCross, 14U)) + 8241612229349212650U) + aOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = (aWandererI + RotL64(aScatter, 23U)) + 4159196033256913347U;
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 51U)) + RotL64(aCarry, 5U)) + 7194795864620233507U;
            aOrbiterA = ((aWandererD + RotL64(aScatter, 5U)) + 7638928444536778384U) + aNonceWordC;
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 29U)) + RotL64(aCarry, 19U)) + 11819105916503968109U;
            aOrbiterE = ((aWandererK + RotL64(aCross, 58U)) + RotL64(aCarry, 53U)) + 18052213302858186237U;
            aOrbiterI = (aWandererH + RotL64(aScatter, 41U)) + 8663575313970041570U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 16644136720439299786U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 16930316530442679864U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2650922074098320859U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 16251107616988250593U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 7171986193609401665U) ^ aNonceWordF;
            aOrbiterD = RotL64((aOrbiterD * 3543709971414550087U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 17885046834432626644U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 7757069274715713557U;
            aOrbiterJ = RotL64((aOrbiterJ * 15766885299397923879U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 2212805322061155615U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 6368539134638838822U;
            aOrbiterE = RotL64((aOrbiterE * 13383744883433594259U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 5264326094252925613U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 6126345334815012938U;
            aOrbiterI = RotL64((aOrbiterI * 17180934809764905307U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 13826731214018407061U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 6621261811613643620U;
            aOrbiterC = RotL64((aOrbiterC * 2823596473596114171U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 5964406317285863781U) + aOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = (((aOrbiterH ^ aOrbiterJ) ^ 2167324450276308078U) ^ aOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterH = RotL64((aOrbiterH * 1098346374733634905U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 16740710162977859724U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 8236083581048717923U;
            aOrbiterA = RotL64((aOrbiterA * 4364887787000704039U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 13967473987446124012U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 5136051802217149813U;
            aOrbiterB = RotL64((aOrbiterB * 13997246005108872883U), 13U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterB, 43U);
            aIngress = aIngress + (RotL64(aOrbiterE, 39U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterA, 11U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 54U));
            aIngress = aIngress + RotL64(aOrbiterD, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aIngress, 39U) + aOrbiterH) + RotL64(aOrbiterA, 43U)) + aNonceWordE);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 4U) + aOrbiterD) + RotL64(aOrbiterA, 18U)) + RotL64(aCarry, 39U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterC, 57U)) + aOrbiterB);
            aWandererF = aWandererF + ((((RotL64(aCross, 11U) + aOrbiterD) + RotL64(aOrbiterH, 29U)) + RotL64(aCarry, 3U)) + aWandererUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 43U) + aOrbiterF) + RotL64(aOrbiterI, 13U)) + aNonceWordM);
            aWandererG = aWandererG + ((RotL64(aScatter, 29U) + RotL64(aOrbiterB, 23U)) + aOrbiterA);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterC, 39U)) + aOrbiterI);
            aWandererI = aWandererI + (((RotL64(aCross, 47U) + aOrbiterA) + RotL64(aOrbiterE, 4U)) + aWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 60U) + aOrbiterJ) + RotL64(aOrbiterE, 35U)) + aNonceWordA);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 12U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 41U));
            aCarry = aCarry + (RotL64(aWandererF, 53U) ^ aWandererK);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + RotL64(aWandererI, 23U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ aNonceWordI;
            aCarry = TwistMix64::DiffuseA(aCarry);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xF0B566B12BB7E1FFULL + 0xB63565386AA756CEULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xBC4B72A59C319A5FULL + 0xB368F7856D4232BEULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xA70302906220A77FULL + 0xB42FC27D9BAD1D48ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x8C033026D6E6A115ULL + 0xFBE1933A2A2473F9ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xFF1714E3E9C256A3ULL + 0xD660334A16FF3B33ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xB609C8041EC4997FULL + 0xC4D9710DE6A461A1ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xFB71F7E7753DADD1ULL + 0x946F32506EF0B79FULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xD7E2A63CD129F2E9ULL + 0xB0B8DA41C9B8B858ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xBCF3209B1D2A7FB9ULL + 0xD3E566836F09C000ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xCA1DE26D5B59230DULL + 0x8950DA633386AD9AULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xF6E3740BD29E237FULL + 0xE0260EF4A9B3348BULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xF54FD05C6076C919ULL + 0xBD585F62E28FA17BULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xC5386F525AC4454FULL + 0xAF9FF58DD24F6E49ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xF055FF6F954EE593ULL + 0xB964814FB03F618AULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xADC15130B8D9B1F3ULL + 0xF33C139E5C35A936ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xCE390BDC246B6251ULL + 0xC9864117983348D5ULL);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 4302U)) & S_BLOCK1], 27U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 30U)) & W_KEY1], 58U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 3761U)) & W_KEY1], 4U) ^ RotL64(mSource[((aIndex + 284U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 11U) ^ RotL64(aCarry, 54U)) + (RotL64(aCross, 37U) + RotL64(aIngress, 23U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterC = ((aWandererD + RotL64(aScatter, 21U)) + RotL64(aCarry, 35U)) + 8367680518550579791U;
            aOrbiterD = (((aWandererI + RotL64(aPrevious, 37U)) + RotL64(aCarry, 19U)) + 11491674725611181241U) + aPhaseAOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = (aWandererC + RotL64(aIngress, 53U)) + 16673861720782164214U;
            aOrbiterE = ((aWandererB + RotL64(aCross, 43U)) + RotL64(aCarry, 3U)) + 9786610124108350855U;
            aOrbiterF = (((aWandererJ + RotL64(aIngress, 30U)) + 5745080601557577637U) + aPhaseAOrbiterAssignSaltC[((aIndex + 28U)) & S_SALT1]) + aNonceWordI;
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 3U)) + 1959402215131684684U) + aNonceWordJ;
            aOrbiterG = (aWandererA + RotL64(aCross, 13U)) + 6121650036079196522U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 12016309761037342392U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 5986936646177049603U;
            aOrbiterA = RotL64((aOrbiterA * 3585650475703294895U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 1000367700904043468U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 17425288243569101032U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2174614006719048535U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 4856917474950325209U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 16312111093223166419U;
            aOrbiterJ = RotL64((aOrbiterJ * 11046477664487805241U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 456110002032422270U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 11393724374787795662U;
            aOrbiterG = RotL64((aOrbiterG * 1176984359123668389U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 8378176867715697176U) + aNonceWordD;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 8086186452345234815U;
            aOrbiterC = RotL64((aOrbiterC * 8450438271765985235U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 8470349167474173245U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 2528229938740192694U;
            aOrbiterE = RotL64((aOrbiterE * 8717790851266520943U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 13247168811545753141U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 8745293957516815264U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14270617180621072619U), 3U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterE, 11U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 35U));
            aIngress = aIngress + (RotL64(aOrbiterD, 27U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterG, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aCross, 11U) + RotL64(aOrbiterA, 27U)) + aOrbiterJ) + RotL64(aCarry, 29U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterD, 13U)) + aOrbiterF);
            aWandererD = aWandererD + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterG, 53U)) + aOrbiterE) + aPhaseAWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((((RotL64(aIngress, 29U) + aOrbiterG) + RotL64(aOrbiterD, 19U)) + aNonceWordE) + aPhaseAWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterJ, 47U)) + aOrbiterC) + aNonceWordA);
            aWandererA = aWandererA ^ (((RotL64(aCross, 4U) + RotL64(aOrbiterC, 38U)) + aOrbiterA) + aNonceWordF);
            aWandererI = aWandererI + (((RotL64(aIngress, 35U) + aOrbiterE) + RotL64(aOrbiterA, 5U)) + RotL64(aCarry, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 46U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererG);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 53U));
            aCarry = aCarry + RotL64(aWandererI, 19U);
            aCarry = aCarry + RotL64(aIngress, 14U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordA);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 6729U)) & S_BLOCK1], 38U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 6926U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 10741U)) & W_KEY1], 37U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 7945U)) & W_KEY1], 13U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 35U) ^ RotL64(aCross, 48U)) + (RotL64(aIngress, 23U) ^ RotL64(aCarry, 11U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterK = (((aWandererF + RotL64(aPrevious, 21U)) + RotL64(aCarry, 27U)) + 8101351470141807662U) + aPhaseAOrbiterAssignSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterG = ((aWandererK + RotL64(aIngress, 4U)) + 6965474099521076705U) + aNonceWordI;
            aOrbiterF = ((aWandererG + RotL64(aScatter, 37U)) + RotL64(aCarry, 53U)) + 6803828268885684784U;
            aOrbiterB = ((aWandererH + RotL64(aCross, 43U)) + 13454235922950972488U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 27U)) + 11678091885751244777U;
            aOrbiterA = (((aWandererE + RotL64(aCross, 57U)) + RotL64(aCarry, 5U)) + 5307134544628507141U) + aNonceWordA;
            aOrbiterD = ((aWandererI + RotL64(aIngress, 13U)) + 4873703518950429353U) + aNonceWordE;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 8542156221858586039U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 3993726182905296513U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11331376012938127609U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 12113047622035464386U) + aNonceWordB;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 1944244448665721151U;
            aOrbiterK = RotL64((aOrbiterK * 7010050836758762003U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 12914188029425467576U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 2486762763475327024U;
            aOrbiterB = RotL64((aOrbiterB * 12319769994433811617U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 14580191602982245481U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 12093414832400135066U;
            aOrbiterG = RotL64((aOrbiterG * 12720286833215690663U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 13623906997320021065U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 9977356009806428696U;
            aOrbiterE = RotL64((aOrbiterE * 2005536391712733499U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 3694954095397810851U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 11453812627797091638U;
            aOrbiterA = RotL64((aOrbiterA * 13730420725113907161U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 542311345544726351U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 3024285045990499484U;
            aOrbiterD = RotL64((aOrbiterD * 5153745952148205645U), 35U);
            //
            aIngress = RotL64(aOrbiterG, 21U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + (RotL64(aOrbiterE, 41U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterK, 34U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aCross, 29U) + RotL64(aOrbiterA, 54U)) + aOrbiterE) + RotL64(aCarry, 41U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterG, 35U)) + aOrbiterA) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aIngress, 57U) + aOrbiterK) + RotL64(aOrbiterB, 11U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 51U) + aOrbiterD) + RotL64(aOrbiterE, 27U)) + aNonceWordM);
            aWandererK = aWandererK + (((RotL64(aPrevious, 19U) + aOrbiterK) + RotL64(aOrbiterG, 19U)) + RotL64(aCarry, 3U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 42U) + aOrbiterD) + RotL64(aOrbiterF, 47U)) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 35U) + RotL64(aOrbiterK, 3U)) + aOrbiterA) + aNonceWordK);
            //
            aCarry = aCarry + (RotL64(aWandererF, 56U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererK);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + RotL64(aWandererE, 5U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordH);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 12187U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneA[((aIndex + 14245U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 13325U)) & W_KEY1], 20U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 11231U)) & W_KEY1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 21U) ^ RotL64(aCross, 39U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCarry, 6U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 13U)) + 5568146815535263910U) + aPhaseAOrbiterAssignSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = ((aWandererE + RotL64(aCross, 3U)) + RotL64(aCarry, 21U)) + 7736084960873834666U;
            aOrbiterC = (((aWandererF + RotL64(aScatter, 39U)) + RotL64(aCarry, 5U)) + 1336413621817562093U) + aNonceWordM;
            aOrbiterH = ((aWandererD + RotL64(aIngress, 19U)) + 5218462026934984692U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = (aWandererA + RotL64(aCross, 27U)) + 7048890985969555935U;
            aOrbiterG = (aWandererH + RotL64(aPrevious, 57U)) + 13415955213864702118U;
            aOrbiterI = ((aWandererC + RotL64(aIngress, 50U)) + RotL64(aCarry, 53U)) + 5657023257021528548U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 14338310943137497116U) + aNonceWordE;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 12305161641833950473U;
            aOrbiterC = RotL64((aOrbiterC * 11949964304435964395U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 14514226578370459131U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 12692904083266024340U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14800805065279908839U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 11012959130001327964U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 7106471380403489078U;
            aOrbiterB = RotL64((aOrbiterB * 515626559384817223U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 3718101961355280891U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 13364192077222322664U;
            aOrbiterH = RotL64((aOrbiterH * 1411328915372590283U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 6720867800318913440U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 14497243926965866546U;
            aOrbiterF = RotL64((aOrbiterF * 13595058589060114653U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 5789056168233262435U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 14438482587495779937U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10593535547917767263U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 313917798940179945U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 15241845511889502917U;
            aOrbiterI = RotL64((aOrbiterI * 16483477103771326107U), 11U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterB, 35U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 27U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 52U));
            aIngress = aIngress + RotL64(aOrbiterF, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aIngress, 41U) + aOrbiterC) + RotL64(aOrbiterA, 47U)) + RotL64(aCarry, 21U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterH, 23U)) + aOrbiterC) + aPhaseAWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 60U) + aOrbiterI) + RotL64(aOrbiterG, 30U)) + RotL64(aCarry, 47U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterA, 11U)) + aOrbiterB);
            aWandererD = aWandererD + (((RotL64(aCross, 51U) + aOrbiterH) + RotL64(aOrbiterG, 53U)) + aNonceWordO);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterG, 41U)) + aOrbiterC);
            aWandererF = aWandererF + (((RotL64(aIngress, 21U) + aOrbiterF) + RotL64(aOrbiterG, 5U)) + aPhaseAWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 34U));
            aCarry = aCarry + RotL64(aWandererC, 39U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordF);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 17959U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 18300U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19467U)) & S_BLOCK1], 51U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 19267U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 10U) ^ RotL64(aCarry, 27U)) + (RotL64(aIngress, 43U) ^ RotL64(aCross, 57U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterK = (((aWandererJ + RotL64(aPrevious, 35U)) + 1866656689936219099U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordE;
            aOrbiterC = (aWandererG + RotL64(aCross, 51U)) + 2312314528139448289U;
            aOrbiterB = ((aWandererI + RotL64(aIngress, 29U)) + RotL64(aCarry, 5U)) + 3554037526469185237U;
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 3U)) + RotL64(aCarry, 23U)) + 405707755060974111U;
            aOrbiterH = ((aWandererA + RotL64(aCross, 42U)) + RotL64(aCarry, 57U)) + 1862976326004007697U;
            aOrbiterD = (((aWandererC + RotL64(aScatter, 23U)) + 12992483065443288263U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordD;
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 11U)) + 3793854946371595197U) + aNonceWordF;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 4244007978867369382U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 10280867500312580308U;
            aOrbiterB = RotL64((aOrbiterB * 13729899124177931289U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 472563452959164242U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 12041770406895816553U;
            aOrbiterD = RotL64((aOrbiterD * 17811798500132002631U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 6118634015704900486U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 13637107920449233307U) ^ aNonceWordL;
            aOrbiterC = RotL64((aOrbiterC * 17712028184714868053U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 16673735670669318830U) + aNonceWordC;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 8602681273646630496U;
            aOrbiterH = RotL64((aOrbiterH * 6995213887710749241U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 7683264695930369476U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 9146674871199188218U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7403427067419261981U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 3012935612827493084U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterC) ^ 1259789268731661945U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterJ = RotL64((aOrbiterJ * 2372843620327050137U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 5623690455471160780U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 18355567776031865462U;
            aOrbiterE = RotL64((aOrbiterE * 9553862670107886679U), 5U);
            //
            aIngress = RotL64(aOrbiterJ, 5U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 60U));
            aIngress = aIngress + (RotL64(aOrbiterH, 41U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterK, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aScatter, 5U) + RotL64(aOrbiterD, 60U)) + aOrbiterH) + RotL64(aCarry, 21U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 23U) + aOrbiterE) + RotL64(aOrbiterC, 53U));
            aWandererJ = aWandererJ + (((((RotL64(aIngress, 47U) + RotL64(aOrbiterC, 27U)) + aOrbiterB) + RotL64(aCarry, 51U)) + aNonceWordB) + aPhaseAWandererUpdateSaltF[((aIndex + 28U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 34U) + aOrbiterD) + RotL64(aOrbiterK, 43U));
            aWandererG = aWandererG + ((RotL64(aScatter, 41U) + aOrbiterH) + RotL64(aOrbiterJ, 35U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterB, 21U)) + aOrbiterH) + aNonceWordH);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 53U) + RotL64(aOrbiterK, 5U)) + aOrbiterC) + aNonceWordG) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + (RotL64(aWandererA, 60U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererC, 43U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ aNonceWordD;
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 27027U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneA[((aIndex + 25839U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 22525U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25786U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 47U) ^ RotL64(aCross, 18U)) ^ (RotL64(aIngress, 5U) + RotL64(aCarry, 35U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterH = ((aWandererG + RotL64(aScatter, 53U)) + 12046647397183218524U) + aPhaseAOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = ((aWandererB + RotL64(aIngress, 5U)) + 2760779375026461991U) + aNonceWordH;
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 47U)) + 13735454443176855650U;
            aOrbiterG = (((aWandererE + RotL64(aCross, 21U)) + RotL64(aCarry, 19U)) + 4370377000586647724U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = (((aWandererD + RotL64(aScatter, 60U)) + RotL64(aCarry, 51U)) + 14566322384189969094U) + aNonceWordO;
            aOrbiterE = (((aWandererA + RotL64(aIngress, 39U)) + RotL64(aCarry, 3U)) + 5056565959818422786U) + aNonceWordN;
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 27U)) + 8795403810686579209U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 9625947666256011567U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 1703669290934254701U;
            aOrbiterA = RotL64((aOrbiterA * 5763881345676123583U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 6664070663184147951U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 2104148316797553431U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12887842067180975983U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 1197910004222596145U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 9922977170060903197U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13047828062605568603U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 2048376210852567829U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 12568990647075931409U;
            aOrbiterD = RotL64((aOrbiterD * 9860242601194210927U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 15026894775772902751U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 3439447160137900629U) ^ aNonceWordL;
            aOrbiterI = RotL64((aOrbiterI * 1813754963043785165U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 6532671388552829796U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 17261098369835997661U;
            aOrbiterE = RotL64((aOrbiterE * 568292591215203521U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 3171300991007459947U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 5935563269327662024U;
            aOrbiterJ = RotL64((aOrbiterJ * 11271790283157765003U), 23U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterG, 11U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 23U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 35U));
            aIngress = aIngress + RotL64(aOrbiterA, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 4U) + RotL64(aOrbiterD, 60U)) + aOrbiterE);
            aWandererJ = aWandererJ + (((RotL64(aCross, 11U) + aOrbiterD) + RotL64(aOrbiterG, 53U)) + RotL64(aCarry, 57U));
            aWandererB = aWandererB ^ ((((RotL64(aScatter, 35U) + RotL64(aOrbiterJ, 41U)) + aOrbiterI) + aNonceWordE) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 27U) + RotL64(aOrbiterA, 3U)) + aOrbiterE) + aPhaseAWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 21U) + aOrbiterI) + RotL64(aOrbiterG, 23U));
            aWandererG = aWandererG + ((((RotL64(aScatter, 57U) + aOrbiterH) + RotL64(aOrbiterG, 13U)) + RotL64(aCarry, 37U)) + aNonceWordM);
            aWandererE = aWandererE ^ ((RotL64(aCross, 41U) + aOrbiterA) + RotL64(aOrbiterH, 35U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 48U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 21U));
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererI, 53U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 30147U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((aIndex + 32130U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28626U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28755U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 43U) + RotL64(aCarry, 5U)) + (RotL64(aPrevious, 24U) ^ RotL64(aCross, 57U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 35U)) + 9654059367478508868U) + aNonceWordG;
            aOrbiterB = (aWandererB + RotL64(aCross, 13U)) + 6473006635864677427U;
            aOrbiterD = (((aWandererJ + RotL64(aIngress, 41U)) + RotL64(aCarry, 19U)) + 6944184481315853243U) + aPhaseAOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = (((aWandererF + RotL64(aScatter, 51U)) + RotL64(aCarry, 3U)) + 4061496421939102306U) + aPhaseAOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = ((aWandererG + RotL64(aCross, 29U)) + 15791809275719085463U) + aNonceWordH;
            aOrbiterG = ((aWandererI + RotL64(aScatter, 3U)) + 14050798802646323055U) + aNonceWordB;
            aOrbiterI = ((aWandererD + RotL64(aPrevious, 60U)) + RotL64(aCarry, 43U)) + 12072905924741758266U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 17639076509231343896U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 12195388285571234715U;
            aOrbiterD = RotL64((aOrbiterD * 4317060502521195769U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 4325404419499496529U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 5910567888204238382U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11503787177122206937U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 13092940059929942699U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 13381962590820308761U;
            aOrbiterG = RotL64((aOrbiterG * 6345904465930943295U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 15622862439323440527U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 14027151901132249793U;
            aOrbiterI = RotL64((aOrbiterI * 2273573821630510087U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 4584410023907605157U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 15763755180625487157U;
            aOrbiterE = RotL64((aOrbiterE * 6755736130607297639U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 17023059745666559199U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = (((aOrbiterA ^ aOrbiterG) ^ 5298529579288492971U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterA = RotL64((aOrbiterA * 2483562793328357721U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 2870152867331654736U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 12017191100173748848U) ^ aNonceWordD;
            aOrbiterB = RotL64((aOrbiterB * 9958191466506480519U), 47U);
            //
            aIngress = RotL64(aOrbiterE, 3U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + (RotL64(aOrbiterA, 47U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterC, 20U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((((RotL64(aScatter, 57U) + RotL64(aOrbiterD, 29U)) + aOrbiterG) + aNonceWordC) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 23U) + aOrbiterB) + RotL64(aOrbiterI, 12U)) + RotL64(aCarry, 51U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterC, 3U)) + aOrbiterB) + aNonceWordO);
            aWandererE = aWandererE + ((((RotL64(aCross, 35U) + RotL64(aOrbiterG, 35U)) + aOrbiterA) + RotL64(aCarry, 5U)) + aNonceWordE);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 12U) + aOrbiterB) + RotL64(aOrbiterG, 53U)) + aPhaseAWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aCross, 29U) + RotL64(aOrbiterG, 23U)) + aOrbiterE);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterG, 41U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 48U));
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererD, 53U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ aNonceWordH;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xE4660EAB31429F6FULL + 0x87D51F31432C0905ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xE4B23E4B9E498F45ULL + 0x8D5B1F38B182291EULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x930820E338424AEFULL + 0x976B338351046CEFULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xB03D4DE35ABB430FULL + 0xDD96D74AF11BC78CULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xD0543C2853F46F19ULL + 0xC87121C7C0E4D3D7ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xDC99928B8B39A327ULL + 0xBA9BE3A5C6D64F66ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xC541B70DB9E773CFULL + 0xB074CCDE6BC3F70CULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x92FEFD6A02AB499DULL + 0xE4B24EC4A0BD6B6FULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xF948D1849BF871B1ULL + 0xDC4AB6C4D94F8DACULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xBB2443C4FF2E2143ULL + 0xA68FC278EE7BEF34ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x9276240931522903ULL + 0x8880E72882D92FFCULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xC39EAF4D276405B7ULL + 0xCDA7DBFAD5CAF559ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xF0EA5AA171AECD67ULL + 0xEBDAFC96669C72CCULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xE924EE4D9F6CD579ULL + 0xACFAC0BECB5E3713ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xDC07EF5356528B5BULL + 0x97F19887FD7CDF3DULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xB22F543F2FFFE58BULL + 0xFA027283914CA548ULL);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 1610U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2162U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 1173U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 3092U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 36U) ^ RotL64(aCross, 23U)) + (RotL64(aIngress, 5U) + RotL64(aCarry, 57U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterK = ((((aWandererB + RotL64(aScatter, 57U)) + RotL64(aCarry, 57U)) + 3199575576585871314U) + aPhaseBOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1]) + aNonceWordE;
            aOrbiterE = (aWandererF + RotL64(aIngress, 3U)) + 2533378188975571824U;
            aOrbiterC = ((aWandererI + RotL64(aCross, 29U)) + 6819782112558312658U) + aPhaseBOrbiterAssignSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 40U)) + RotL64(aCarry, 39U)) + 12690060987724798497U;
            aOrbiterA = ((aWandererE + RotL64(aIngress, 11U)) + RotL64(aCarry, 19U)) + 7088375139715629606U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 17785618677423695666U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 1714999280296491277U;
            aOrbiterC = RotL64((aOrbiterC * 7675674437417383741U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 17611338506932491624U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 6475727359297421201U;
            aOrbiterK = RotL64((aOrbiterK * 15133348244242438069U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 2347744591204119530U) + aNonceWordC;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 2739317903351401068U;
            aOrbiterB = RotL64((aOrbiterB * 15435029315209475631U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 8663535261373274338U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterE = (((aOrbiterE ^ aOrbiterA) ^ 8205245127823536479U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterE = RotL64((aOrbiterE * 13857005110466856439U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 8916510616749754516U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 3944805940148512932U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 18082271583211389701U), 23U);
            //
            aIngress = RotL64(aOrbiterE, 46U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + RotL64(aOrbiterK, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aPrevious, 38U) + aOrbiterE) + RotL64(aOrbiterB, 37U)) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterK, 29U)) + aOrbiterC) + aPhaseBWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aIngress, 21U) + aOrbiterA) + RotL64(aOrbiterC, 3U)) + RotL64(aCarry, 27U)) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 47U) + aOrbiterK) + RotL64(aOrbiterB, 54U)) + aNonceWordF);
            aWandererF = aWandererF + (((RotL64(aIngress, 13U) + RotL64(aOrbiterK, 13U)) + aOrbiterA) + aNonceWordN);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + (RotL64(aWandererI, 60U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 11U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordF);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9453U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneD[((aIndex + 8122U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 6637U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 9473U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 56U) ^ RotL64(aIngress, 5U)) + (RotL64(aCarry, 39U) ^ RotL64(aPrevious, 27U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterJ = ((aWandererA + RotL64(aCross, 13U)) + RotL64(aCarry, 41U)) + 1457104756581596530U;
            aOrbiterK = (((aWandererH + RotL64(aIngress, 29U)) + RotL64(aCarry, 3U)) + 6127240317844622874U) + aNonceWordJ;
            aOrbiterB = ((aWandererC + RotL64(aScatter, 3U)) + 16492290056044189421U) + aPhaseBOrbiterAssignSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterH = (((aWandererI + RotL64(aPrevious, 21U)) + RotL64(aCarry, 23U)) + 10963676850938416468U) + aPhaseBOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = (aWandererB + RotL64(aScatter, 58U)) + 4872917367399752405U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 15218882377875616148U) + aNonceWordN;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 5934166612122118251U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10365045124180379919U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 14215280930872003003U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 11428034799044600979U;
            aOrbiterF = RotL64((aOrbiterF * 12162528943733976177U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 5453003654321728726U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 14273775120265649389U;
            aOrbiterJ = RotL64((aOrbiterJ * 5139018128323795309U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 328723770018440271U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 13032190719588211088U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13363368478932798315U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 2386881543033598494U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 1649501123340887116U;
            aOrbiterH = RotL64((aOrbiterH * 11148976582360499033U), 21U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterJ, 58U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + RotL64(aOrbiterB, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aCross, 57U) + aOrbiterF) + RotL64(aOrbiterJ, 43U)) + RotL64(aCarry, 27U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 47U) + aOrbiterK) + RotL64(aOrbiterH, 23U));
            aWandererB = aWandererB + (((((RotL64(aIngress, 11U) + RotL64(aOrbiterF, 3U)) + aOrbiterB) + RotL64(aCarry, 11U)) + aNonceWordH) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 20U) + RotL64(aOrbiterF, 35U)) + aOrbiterK) + aNonceWordI);
            aWandererH = aWandererH + (((RotL64(aCross, 29U) + RotL64(aOrbiterK, 54U)) + aOrbiterJ) + aPhaseBWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 44U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererI, 3U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ aNonceWordI;
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 12892U)) & S_BLOCK1], 6U) ^ RotL64(aWorkLaneA[((aIndex + 14063U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 11935U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15727U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aIngress, 5U)) + (RotL64(aCross, 34U) + RotL64(aPrevious, 21U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterE = ((aWandererI + RotL64(aCross, 21U)) + 12669015908335980355U) + aPhaseBOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = ((aWandererG + RotL64(aIngress, 35U)) + RotL64(aCarry, 11U)) + 5438715179868613192U;
            aOrbiterA = (((aWandererE + RotL64(aPrevious, 13U)) + RotL64(aCarry, 57U)) + 13172104448184536460U) + aNonceWordB;
            aOrbiterC = (((aWandererF + RotL64(aScatter, 47U)) + RotL64(aCarry, 41U)) + 13421421503244744803U) + aPhaseBOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = (aWandererH + RotL64(aPrevious, 4U)) + 13327113302994856582U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 4671768205922454413U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 5355759962838579929U;
            aOrbiterA = RotL64((aOrbiterA * 15080379163499722187U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 6691720614265406851U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterC) ^ 7063906424700911378U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterJ = RotL64((aOrbiterJ * 17091734375516280675U), 5U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterC) + 17328616394166672263U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordN;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 1542940602574207068U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8981679306319627975U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 7203866278803132454U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 993485696233139264U;
            aOrbiterC = RotL64((aOrbiterC * 11609009908810366447U), 13U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterA) + 15659679028507488331U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1]) + aNonceWordM;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 18321361454094675842U;
            aOrbiterF = RotL64((aOrbiterF * 3966860765622641843U), 43U);
            //
            aIngress = RotL64(aOrbiterJ, 57U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 35U));
            aIngress = aIngress + RotL64(aOrbiterF, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aCross, 48U) + RotL64(aOrbiterC, 21U)) + aOrbiterE) + RotL64(aCarry, 39U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterF, 57U)) + aOrbiterA);
            aWandererF = aWandererF + (((RotL64(aIngress, 19U) + RotL64(aOrbiterE, 47U)) + aOrbiterJ) + aNonceWordG);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterA, 39U)) + aOrbiterJ) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aScatter, 57U) + aOrbiterC) + RotL64(aOrbiterF, 12U)) + RotL64(aCarry, 11U)) + aNonceWordE);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 21U));
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererE, 13U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordL);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 16996U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneB[((aIndex + 21478U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18123U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 21476U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 6U) ^ RotL64(aPrevious, 57U)) ^ (RotL64(aCross, 23U) + RotL64(aIngress, 35U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterA = ((aWandererA + RotL64(aCross, 14U)) + RotL64(aCarry, 19U)) + 15549114274303128055U;
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 47U)) + RotL64(aCarry, 5U)) + 16466750056388063241U;
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 37U)) + 12209449840836787142U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = ((((aWandererI + RotL64(aPrevious, 3U)) + RotL64(aCarry, 41U)) + 14551496099734294336U) + aPhaseBOrbiterAssignSaltE[((aIndex + 28U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterF = (aWandererK + RotL64(aIngress, 29U)) + 6266576428679808622U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 16892841575635668152U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 7375966221423362125U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15338878556107177587U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 11926105302821753530U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 16219253791550461124U) ^ aNonceWordH;
            aOrbiterA = RotL64((aOrbiterA * 2117550758226173419U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 7299056065319248160U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 15234001484933728439U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8182244796017018911U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 6615802589932632120U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 5481176858895819247U;
            aOrbiterJ = RotL64((aOrbiterJ * 3604590158551984877U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 17220507586542139380U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 14137921473739415340U;
            aOrbiterF = RotL64((aOrbiterF * 10634645686035907603U), 19U);
            //
            aIngress = RotL64(aOrbiterJ, 47U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 37U));
            aIngress = aIngress + RotL64(aOrbiterG, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterA, 5U)) + aOrbiterJ) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aCross, 3U) + RotL64(aOrbiterF, 13U)) + aOrbiterB) + RotL64(aCarry, 51U)) + aNonceWordN);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 56U) + RotL64(aOrbiterG, 60U)) + aOrbiterJ) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 29U) + aOrbiterB) + RotL64(aOrbiterA, 43U)) + RotL64(aCarry, 29U)) + aNonceWordK);
            aWandererK = aWandererK ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterF, 21U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererK, 47U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ aNonceWordD;
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 26295U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneA[((aIndex + 24239U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24074U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((aIndex + 26480U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 35U) + RotL64(aCarry, 51U)) + (RotL64(aCross, 4U) ^ RotL64(aPrevious, 19U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterF = (aWandererH + RotL64(aPrevious, 3U)) + 2974056819475622600U;
            aOrbiterG = (((aWandererJ + RotL64(aScatter, 24U)) + RotL64(aCarry, 51U)) + 7345051759236356098U) + aNonceWordB;
            aOrbiterD = (aWandererE + RotL64(aIngress, 57U)) + 12738468816846628882U;
            aOrbiterI = (((aWandererA + RotL64(aCross, 11U)) + RotL64(aCarry, 27U)) + 7694520596043297922U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = (((aWandererG + RotL64(aIngress, 47U)) + RotL64(aCarry, 3U)) + 5530753590015084774U) + aPhaseBOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1];
            //
            aOrbiterF = (((aOrbiterF + aOrbiterG) + 3776309161718383105U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1]) + aNonceWordK;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 784780304358106404U;
            aOrbiterD = RotL64((aOrbiterD * 1503119308251871519U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 8999942326995036509U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 5194986506064092779U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15070787038006135963U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 7920040007459652762U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 11311997270710107937U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6227571709361790209U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 5365231114813547251U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 8630110234623825263U;
            aOrbiterG = RotL64((aOrbiterG * 2735881715888325759U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 2358235238039571072U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 18059414891616491807U;
            aOrbiterI = RotL64((aOrbiterI * 17150786106857185467U), 39U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterI, 41U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 54U));
            aIngress = aIngress + RotL64(aOrbiterD, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterA, 29U)) + aOrbiterG);
            aWandererJ = aWandererJ + (((((RotL64(aScatter, 47U) + aOrbiterD) + RotL64(aOrbiterA, 19U)) + RotL64(aCarry, 53U)) + aNonceWordE) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterF, 6U)) + aOrbiterA) + aPhaseBWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aIngress, 19U) + RotL64(aOrbiterG, 47U)) + aOrbiterF) + RotL64(aCarry, 5U)) + aNonceWordO);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 58U) + aOrbiterD) + RotL64(aOrbiterI, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererE);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + RotL64(aWandererA, 38U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ aNonceWordK;
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 30027U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32732U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 28596U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((aIndex + 29312U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 21U) ^ RotL64(aCarry, 37U)) + (RotL64(aCross, 4U) ^ RotL64(aIngress, 51U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterF = ((aWandererK + RotL64(aCross, 29U)) + RotL64(aCarry, 35U)) + 15036852811491820366U;
            aOrbiterB = ((aWandererH + RotL64(aIngress, 21U)) + RotL64(aCarry, 21U)) + 305637140752898475U;
            aOrbiterI = (((aWandererB + RotL64(aPrevious, 42U)) + RotL64(aCarry, 3U)) + 11948631574496129610U) + aNonceWordB;
            aOrbiterH = ((aWandererA + RotL64(aScatter, 5U)) + 5321623592482991426U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = (((aWandererC + RotL64(aPrevious, 53U)) + 4075270159062690728U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordE;
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 15111580500356908928U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 7244150695504160363U;
            aOrbiterI = RotL64((aOrbiterI * 2445733898697939969U), 57U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterF) + 5131563519577488862U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1]) + aNonceWordN;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 5881954992088651371U;
            aOrbiterB = RotL64((aOrbiterB * 2424421828597294607U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 12780935808751507998U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 12599159643925470226U;
            aOrbiterF = RotL64((aOrbiterF * 17690046932587062701U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 9466589929741834066U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 6093158735705189789U) ^ aNonceWordM;
            aOrbiterH = RotL64((aOrbiterH * 7453778295800853653U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 17461243886150519249U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterB) ^ 15456408913739900718U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterE = RotL64((aOrbiterE * 16093292401746174671U), 27U);
            //
            aIngress = RotL64(aOrbiterH, 39U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 19U));
            aIngress = aIngress + RotL64(aOrbiterE, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aIngress, 29U) + aOrbiterB) + RotL64(aOrbiterH, 51U)) + RotL64(aCarry, 35U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterI, 3U)) + aOrbiterH) + aNonceWordI);
            aWandererK = aWandererK + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterF, 29U)) + aOrbiterE) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterB, 13U)) + aOrbiterE);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 58U) + aOrbiterF) + RotL64(aOrbiterI, 40U)) + RotL64(aCarry, 53U)) + aPhaseBWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 30U));
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererA, 21U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ aNonceWordM;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x9290E5C6B4B65081ULL + 0xB6E4749D4220C74CULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x8251C34269B5492FULL + 0xFDA346960C4163EAULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xE504CD7D6A807555ULL + 0x856F5A596775122DULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xA509D154B474825BULL + 0xEC61444BB0C0075AULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x9F9BEA74A81F34FDULL + 0xADF882ED3E0DFBFEULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xE31E0238E904E8B1ULL + 0xB9E76C05E228DB0FULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x96B3FC814D67E6E3ULL + 0xD2CFD21476FE741CULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xBDC2CD6BCD291243ULL + 0xBA1A09743FD76E9DULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x9788711E29A035E1ULL + 0xDE183D0279050CD7ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x99E507465DB7481DULL + 0xD9B1C1437DA775B9ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xE18DE856C62C9651ULL + 0xAF7F2BAA74F89DC2ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xB2D3C8D76C29F57DULL + 0xF5E00816BC8125AFULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xD42583FF7C4454B5ULL + 0xAEBB2C5C8B237AE1ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xC0409863F09551A5ULL + 0xA10FDABDDA3A0300ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xADE54E2FE326B971ULL + 0xD0BBD29559BF13B3ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x9D853F07463B535DULL + 0x85337D3035BFE266ULL);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 7698U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 7111U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 3621U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneA[((aIndex + 6839U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 24U) ^ RotL64(aCross, 43U)) + (RotL64(aCarry, 5U) ^ RotL64(aIngress, 57U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterA = ((aWandererA + RotL64(aIngress, 58U)) + RotL64(aCarry, 11U)) + 11521331427196538632U;
            aOrbiterC = (aWandererF + RotL64(aScatter, 23U)) + 16653824187682957632U;
            aOrbiterE = (aWandererK + RotL64(aCross, 41U)) + 11654676587350088289U;
            aOrbiterB = (aWandererC + RotL64(aPrevious, 37U)) + 8010313317412193584U;
            aOrbiterJ = (aWandererB + RotL64(aScatter, 29U)) + 1108775560502907471U;
            aOrbiterH = ((aWandererI + RotL64(aIngress, 3U)) + 243952321439823521U) + aPhaseCOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = (aWandererJ + RotL64(aCross, 54U)) + 2324945800401240403U;
            aOrbiterF = (((aWandererD + RotL64(aPrevious, 47U)) + RotL64(aCarry, 3U)) + 9257554497543369657U) + aPhaseCOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = (((aWandererE + RotL64(aScatter, 19U)) + RotL64(aCarry, 41U)) + 16701314607244592540U) + aNonceWordG;
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 3900445848034341782U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 7652316487347103658U;
            aOrbiterE = RotL64((aOrbiterE * 11480123491361589799U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 14980368605272070578U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 2001165460948764796U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8110980921827107649U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 1911044015666991050U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 11366207111147818339U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17234439040652553865U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 16469329744002456607U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 8062793687044950815U;
            aOrbiterG = RotL64((aOrbiterG * 5856142259851144369U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 15364721421972807872U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 8979915611483540231U;
            aOrbiterA = RotL64((aOrbiterA * 10899377466171153383U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 7654234623563110457U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 1526832460342135008U;
            aOrbiterB = RotL64((aOrbiterB * 12766083052650723051U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 1596625448797520938U) + aNonceWordA;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 15723912914858523080U;
            aOrbiterD = RotL64((aOrbiterD * 6003857787643420337U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 7664226719746532168U) + aNonceWordC;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 13767298788411473401U;
            aOrbiterC = RotL64((aOrbiterC * 15663266144965532019U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 8371251860069346385U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 10143279934304029980U;
            aOrbiterJ = RotL64((aOrbiterJ * 12764966547132248131U), 11U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterF, 3U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 29U));
            aIngress = aIngress + (RotL64(aOrbiterC, 26U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterH, 47U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterG, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aIngress, 18U) + RotL64(aOrbiterB, 30U)) + aOrbiterJ);
            aWandererB = aWandererB + (((RotL64(aScatter, 57U) + RotL64(aOrbiterG, 23U)) + aOrbiterE) + RotL64(aCarry, 21U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 53U) + aOrbiterD) + RotL64(aOrbiterC, 5U)) + aPhaseCWandererUpdateSaltC[((aIndex + 8U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterA, 53U)) + aOrbiterJ);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterH, 39U)) + aOrbiterC) + aPhaseCWandererUpdateSaltA[((aIndex + 18U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 3U) + RotL64(aOrbiterA, 10U)) + aOrbiterH) + aNonceWordF);
            aWandererK = aWandererK ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterE, 47U)) + aOrbiterH) + aNonceWordO);
            aWandererC = aWandererC + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterF, 19U)) + aOrbiterJ) + RotL64(aCarry, 57U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 14U) + aOrbiterC) + RotL64(aOrbiterG, 35U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (RotL64(aWandererD, 42U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererE, 13U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ aNonceWordC;
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9382U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneD[((aIndex + 9881U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 8655U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneB[((aIndex + 13828U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 4U) + RotL64(aCarry, 23U)) ^ (RotL64(aPrevious, 53U) + RotL64(aCross, 35U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 35U)) + 1866656689936219099U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterK = (aWandererD + RotL64(aScatter, 6U)) + 2312314528139448289U;
            aOrbiterA = (aWandererH + RotL64(aIngress, 57U)) + 3554037526469185237U;
            aOrbiterH = (((aWandererE + RotL64(aCross, 11U)) + RotL64(aCarry, 43U)) + 405707755060974111U) + aNonceWordJ;
            aOrbiterB = ((aWandererB + RotL64(aScatter, 39U)) + RotL64(aCarry, 53U)) + 1862976326004007697U;
            aOrbiterJ = ((aWandererA + RotL64(aCross, 46U)) + 12992483065443288263U) + aPhaseCOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 23U)) + 3793854946371595197U) + aNonceWordC;
            aOrbiterI = (aWandererJ + RotL64(aIngress, 51U)) + 4244007978867369382U;
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 29U)) + RotL64(aCarry, 5U)) + 10280867500312580308U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 472563452959164242U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 12041770406895816553U;
            aOrbiterA = RotL64((aOrbiterA * 17811798500132002631U), 11U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterA) + 6118634015704900486U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordD;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 13637107920449233307U;
            aOrbiterB = RotL64((aOrbiterB * 17712028184714868053U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 16673735670669318830U) + aNonceWordL;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 8602681273646630496U;
            aOrbiterF = RotL64((aOrbiterF * 6995213887710749241U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 7683264695930369476U) + aNonceWordH;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 9146674871199188218U;
            aOrbiterI = RotL64((aOrbiterI * 7403427067419261981U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 3012935612827493084U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 1259789268731661945U;
            aOrbiterD = RotL64((aOrbiterD * 2372843620327050137U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 5623690455471160780U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 18355567776031865462U;
            aOrbiterE = RotL64((aOrbiterE * 9553862670107886679U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 7705134893833304792U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 4435192506444773834U;
            aOrbiterH = RotL64((aOrbiterH * 5249651218395299501U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 6204683785806409075U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 17886971535016484255U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6047216474762933535U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 4430578901091376829U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 607557685798141547U;
            aOrbiterK = RotL64((aOrbiterK * 12342665567201483107U), 19U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterK, 23U);
            aIngress = aIngress + (RotL64(aOrbiterF, 11U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 50U));
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterE, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aCross, 57U) + aOrbiterK) + RotL64(aOrbiterF, 47U)) + RotL64(aCarry, 19U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 52U) + aOrbiterB) + RotL64(aOrbiterI, 3U)) + aNonceWordA);
            aWandererE = aWandererE + (((RotL64(aPrevious, 23U) + aOrbiterE) + RotL64(aOrbiterJ, 22U)) + aPhaseCWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterD, 43U)) + aOrbiterH);
            aWandererC = aWandererC + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterK, 13U)) + aOrbiterD);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 18U) + aOrbiterK) + RotL64(aOrbiterB, 51U)) + aNonceWordO);
            aWandererF = aWandererF + (((RotL64(aIngress, 35U) + aOrbiterK) + RotL64(aOrbiterH, 37U)) + aPhaseCWandererUpdateSaltB[((aIndex + 4U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 41U) + aOrbiterI) + RotL64(aOrbiterA, 29U));
            aWandererG = aWandererG + (((RotL64(aScatter, 29U) + aOrbiterJ) + RotL64(aOrbiterF, 58U)) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 28U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererH);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + RotL64(aWandererE, 14U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordB);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 20385U)) & S_BLOCK1], 14U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16532U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 17009U)) & S_BLOCK1], 54U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 17900U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCarry, 52U)) ^ (RotL64(aCross, 19U) ^ RotL64(aIngress, 37U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterD = (((aWandererA + RotL64(aCross, 3U)) + 3236820517816085022U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterF = (((aWandererI + RotL64(aIngress, 39U)) + RotL64(aCarry, 3U)) + 741288875914097926U) + aPhaseCOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = (aWandererK + RotL64(aPrevious, 10U)) + 8417246926007729580U;
            aOrbiterE = ((aWandererC + RotL64(aScatter, 43U)) + RotL64(aCarry, 19U)) + 9715717805774537170U;
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 35U)) + RotL64(aCarry, 35U)) + 14360243844821619482U;
            aOrbiterA = (aWandererG + RotL64(aIngress, 23U)) + 10760908100206775334U;
            aOrbiterB = ((aWandererH + RotL64(aCross, 51U)) + 3434641779946167811U) + aNonceWordP;
            aOrbiterK = (aWandererF + RotL64(aScatter, 14U)) + 7885568822756234567U;
            aOrbiterI = (aWandererE + RotL64(aCross, 19U)) + 3041563437672051294U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 15761355327564963516U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 1158633562785937421U;
            aOrbiterH = RotL64((aOrbiterH * 15511324886867188235U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 9338581575871970653U) + aNonceWordO;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 9172038894262857354U;
            aOrbiterD = RotL64((aOrbiterD * 3110871165285625807U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 14653924713599790081U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterF) ^ 3854497592598563309U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterE = RotL64((aOrbiterE * 11737111068815795303U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 16286980180327600557U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 5092583772591249756U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13955105624639442903U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 4288397994175567333U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 15584236478994873104U;
            aOrbiterJ = RotL64((aOrbiterJ * 1860480595862755379U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 5557463939827483792U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterB) ^ 2659814275753280856U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterA = RotL64((aOrbiterA * 17702430405693184643U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 6941807963525063449U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 2040598555191211307U;
            aOrbiterB = RotL64((aOrbiterB * 14750544987531722765U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 347572666231116258U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 779304821185302523U;
            aOrbiterK = RotL64((aOrbiterK * 14180254150318109855U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 10632524582873079742U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 9761308771280517212U;
            aOrbiterI = RotL64((aOrbiterI * 13926235411726048921U), 29U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterH, 13U);
            aIngress = aIngress + (RotL64(aOrbiterI, 36U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 21U));
            aIngress = aIngress + (RotL64(aOrbiterK, 39U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterB, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterH, 20U)) + aOrbiterD);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterK, 39U)) + aOrbiterA);
            aWandererI = aWandererI + ((RotL64(aScatter, 36U) + RotL64(aOrbiterE, 57U)) + aOrbiterD);
            aWandererH = aWandererH ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterE, 27U)) + aOrbiterJ);
            aWandererG = aWandererG + ((((RotL64(aIngress, 11U) + aOrbiterJ) + RotL64(aOrbiterF, 52U)) + RotL64(aCarry, 47U)) + aNonceWordM);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterE, 35U)) + aOrbiterK) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 43U) + aOrbiterI) + RotL64(aOrbiterA, 47U)) + RotL64(aCarry, 57U)) + aPhaseCWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterJ, 5U)) + aOrbiterK);
            aWandererA = aWandererA + ((RotL64(aPrevious, 4U) + RotL64(aOrbiterK, 11U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererE, 54U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 43U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 21U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererK, 47U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordG);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 25528U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30196U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 31795U)) & S_BLOCK1], 48U) ^ RotL64(aOperationLaneD[((aIndex + 26392U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 47U) + RotL64(aCarry, 60U)) + (RotL64(aPrevious, 11U) ^ RotL64(aCross, 27U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 19U)) + RotL64(aCarry, 53U)) + 9023059520606551446U;
            aOrbiterG = (aWandererG + RotL64(aCross, 40U)) + 662441755115638133U;
            aOrbiterD = ((aWandererI + RotL64(aIngress, 47U)) + 16957253361196144712U) + aPhaseCOrbiterAssignSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = ((aWandererB + RotL64(aScatter, 23U)) + RotL64(aCarry, 29U)) + 7840955025765308605U;
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 29U)) + 346855809270395799U) + aNonceWordO;
            aOrbiterA = (aWandererF + RotL64(aIngress, 51U)) + 16099139781586668343U;
            aOrbiterH = ((aWandererA + RotL64(aScatter, 6U)) + 3706457327118322098U) + aNonceWordD;
            aOrbiterB = ((aWandererD + RotL64(aCross, 35U)) + RotL64(aCarry, 21U)) + 12166825885547622870U;
            aOrbiterE = ((aWandererK + RotL64(aScatter, 57U)) + 7792658665720344200U) + aPhaseCOrbiterAssignSaltD[((aIndex + 20U)) & S_SALT1];
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 7128477606152986326U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 11116533962780290084U;
            aOrbiterD = RotL64((aOrbiterD * 11993485572912492297U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 10443889548568288532U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 4402387036946561017U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9032964741841833277U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 13002706161178447654U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 13929727277530310708U;
            aOrbiterH = RotL64((aOrbiterH * 7005639090871200285U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 10949073760696935106U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 15405923432006783533U;
            aOrbiterJ = RotL64((aOrbiterJ * 17989565878445202495U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 18096057968822208905U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 3032155040484574973U;
            aOrbiterI = RotL64((aOrbiterI * 448597307502544605U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 17462076466907467134U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 15471015427013701406U;
            aOrbiterA = RotL64((aOrbiterA * 6113474000571976139U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 3549031751266594344U) + aNonceWordA;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 14243218483842508113U;
            aOrbiterB = RotL64((aOrbiterB * 9041601306479302047U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 5803147589312920032U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 5549470512227427855U;
            aOrbiterE = RotL64((aOrbiterE * 12592362489263862879U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 10076661824293832189U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 3196799148974716550U;
            aOrbiterG = RotL64((aOrbiterG * 8183276968961467775U), 39U);
            //
            aIngress = RotL64(aOrbiterD, 53U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 60U));
            aIngress = aIngress + (RotL64(aOrbiterG, 41U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 5U));
            aIngress = aIngress + RotL64(aOrbiterJ, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aScatter, 57U) + RotL64(aOrbiterJ, 41U)) + aOrbiterB);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 41U) + aOrbiterE) + RotL64(aOrbiterB, 22U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterJ, 37U)) + aOrbiterI) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 51U) + RotL64(aOrbiterJ, 27U)) + aOrbiterA) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aIngress, 36U) + RotL64(aOrbiterH, 13U)) + aOrbiterB) + RotL64(aCarry, 41U)) + aNonceWordM);
            aWandererK = aWandererK ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterB, 48U)) + aOrbiterF);
            aWandererD = aWandererD + ((RotL64(aPrevious, 11U) + aOrbiterA) + RotL64(aOrbiterD, 53U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterF, 57U)) + aOrbiterI);
            aWandererF = aWandererF + (((RotL64(aIngress, 6U) + aOrbiterG) + RotL64(aOrbiterE, 3U)) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 22U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + RotL64(aWandererE, 53U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ aNonceWordH;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xBBEA38EC21C1612FULL + 0x8D87FD885D6B878FULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xB372C052B628122BULL + 0xB45C894E0BE15883ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xA6FADA80E67A30E3ULL + 0xE87B7A1806E9ACC6ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xB816FB16E984DB83ULL + 0xEE094766AD089B16ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x8566A00E5490383DULL + 0x9447FC168986A239ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xDE75366F59F06033ULL + 0xDD4FC9B008F253DAULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xB3962786E2985F0BULL + 0xF1A668473C46F46EULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xE985587184F4C525ULL + 0xEE54BE9585475568ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xFF8C2215BE4A67B3ULL + 0xBED1826B76686E62ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xEC98867DECC98FB1ULL + 0xC6F79CE51DCD3CF0ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xE6C3B78F37B1B31FULL + 0xBE142B64FCC82F18ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x8BB2C06D248ADE8DULL + 0xA7472D81BAD56B1AULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x809C1EF9AF592FC3ULL + 0xE4F022EE95EB73A4ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xC60CC56F045AA52BULL + 0x87F5D87821D2DE3BULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xF770F7A1817262ADULL + 0xDA60429585968577ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xF013C4099143C3FDULL + 0x8D2667741102F89CULL);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 471U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4059U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2517U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneA[((aIndex + 1452U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 51U) + RotL64(aIngress, 20U)) ^ (RotL64(aPrevious, 5U) ^ RotL64(aCross, 35U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterH = ((aWandererC + RotL64(aScatter, 13U)) + RotL64(aCarry, 23U)) + 8375305456876489425U;
            aOrbiterK = (((aWandererK + RotL64(aPrevious, 37U)) + RotL64(aCarry, 13U)) + 16193562952772453047U) + aNonceWordN;
            aOrbiterI = ((aWandererI + RotL64(aCross, 18U)) + 18088652458594816223U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = (aWandererD + RotL64(aIngress, 51U)) + 767344788620249944U;
            aOrbiterB = (aWandererH + RotL64(aCross, 35U)) + 7705194930396368752U;
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 57U)) + 3829736891311272834U) + aNonceWordO;
            aOrbiterD = (aWandererB + RotL64(aScatter, 22U)) + 9881681671347640061U;
            aOrbiterC = (aWandererE + RotL64(aPrevious, 53U)) + 1721196560190164264U;
            aOrbiterF = (aWandererF + RotL64(aScatter, 39U)) + 3002652618388454213U;
            aOrbiterE = ((aWandererA + RotL64(aIngress, 41U)) + RotL64(aCarry, 5U)) + 9811621464004005202U;
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 5U)) + 5652598941069986530U) + aPhaseDOrbiterAssignSaltC[((aIndex + 20U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 6250499348327316328U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 16025054277615264530U;
            aOrbiterI = RotL64((aOrbiterI * 16446892258704281903U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 13800298546867243172U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 12256104592865905782U;
            aOrbiterA = RotL64((aOrbiterA * 16983140179497142713U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 17817225416918329229U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 17738671327352776217U;
            aOrbiterH = RotL64((aOrbiterH * 393488251327705063U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 6816031224188400541U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 16989563985059237014U;
            aOrbiterG = RotL64((aOrbiterG * 8677884225771717797U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 16891524847268207549U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 1833508573940405571U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9709196587703979539U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 12729999421507068973U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 6839758643521968957U;
            aOrbiterF = RotL64((aOrbiterF * 16350557395881283975U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 8524167125469267428U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 14741523560290472617U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4367850822282205897U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 10983798459868424892U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 5649250846622078964U;
            aOrbiterK = RotL64((aOrbiterK * 7149612714806023987U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 8587302028325090061U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 17457129226030333666U) ^ aNonceWordM;
            aOrbiterB = RotL64((aOrbiterB * 18107356450566915215U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 15600113588474915690U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 6595247491374683783U;
            aOrbiterC = RotL64((aOrbiterC * 1432432381540098765U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 13246325856585534283U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 8375305456876489425U;
            aOrbiterE = RotL64((aOrbiterE * 8331406038795786099U), 11U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterE, 35U);
            aIngress = aIngress + (RotL64(aOrbiterF, 53U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 14U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 19U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 51U));
            aIngress = aIngress + RotL64(aOrbiterC, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aIngress, 37U) + aOrbiterI) + RotL64(aOrbiterF, 53U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 39U) + aOrbiterC) + RotL64(aOrbiterH, 39U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 27U) + aOrbiterE) + RotL64(aOrbiterA, 57U)) + RotL64(aCarry, 21U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 57U) + aOrbiterH) + RotL64(aOrbiterD, 13U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterH, 6U)) + aOrbiterI);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 50U) + RotL64(aOrbiterK, 37U)) + aOrbiterC);
            aWandererD = aWandererD + (((RotL64(aCross, 41U) + aOrbiterG) + RotL64(aOrbiterA, 19U)) + aPhaseDWandererUpdateSaltC[((aIndex + 4U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterB, 41U)) + aOrbiterF);
            aWandererE = aWandererE + ((((RotL64(aCross, 29U) + aOrbiterC) + RotL64(aOrbiterA, 3U)) + RotL64(aCarry, 51U)) + aNonceWordC);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 4U) + aOrbiterJ) + RotL64(aOrbiterG, 34U));
            aWandererF = aWandererF + ((RotL64(aScatter, 23U) + RotL64(aOrbiterK, 21U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererE, 37U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 24U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererG, 21U) ^ aWandererB);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererC, 18U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordJ);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 7096U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 10532U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8181U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 9704U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aPrevious, 41U)) ^ (RotL64(aCross, 53U) + RotL64(aIngress, 26U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterA = (aWandererJ + RotL64(aCross, 43U)) + 17225673071833726819U;
            aOrbiterH = (aWandererI + RotL64(aPrevious, 23U)) + 10301458382103627331U;
            aOrbiterF = (aWandererD + RotL64(aScatter, 40U)) + 3960233050857362414U;
            aOrbiterJ = (((aWandererC + RotL64(aIngress, 47U)) + 17768665685046605837U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordO;
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 3U)) + RotL64(aCarry, 35U)) + 14471018461213959767U;
            aOrbiterK = (aWandererH + RotL64(aIngress, 19U)) + 10730597892721340453U;
            aOrbiterB = ((aWandererF + RotL64(aScatter, 27U)) + 14863394003122760542U) + aPhaseDOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = (aWandererB + RotL64(aCross, 35U)) + 9948587274816688296U;
            aOrbiterD = ((aWandererK + RotL64(aScatter, 57U)) + RotL64(aCarry, 13U)) + 3573569431435100993U;
            aOrbiterC = (aWandererG + RotL64(aCross, 5U)) + 8153670675740450590U;
            aOrbiterG = ((aWandererA + RotL64(aIngress, 60U)) + RotL64(aCarry, 51U)) + 16438856577722561424U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 15765587867581925041U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 1082039522061775213U;
            aOrbiterF = RotL64((aOrbiterF * 17023740047246402641U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 4202521649260798876U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = (((aOrbiterH ^ aOrbiterJ) ^ 15877659681260461141U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterH = RotL64((aOrbiterH * 11369910758551088173U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 2551560426129646123U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 3005102326163906320U) ^ aNonceWordE;
            aOrbiterE = RotL64((aOrbiterE * 4241583192662435107U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 1675501058857208089U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 12774812270956702043U;
            aOrbiterB = RotL64((aOrbiterB * 5488437008504905105U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 1044886020922563597U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 4857445127457225171U;
            aOrbiterD = RotL64((aOrbiterD * 13223560654459705259U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 11548725551787560962U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 2434677823189765161U;
            aOrbiterA = RotL64((aOrbiterA * 4283026044563670969U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 9606875320524736294U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 13732615866277657704U;
            aOrbiterJ = RotL64((aOrbiterJ * 3905528919281629775U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 13921743663803299567U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 13350829301153929899U;
            aOrbiterK = RotL64((aOrbiterK * 11858642286713079795U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 9473349030551400156U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 7446792050826434742U;
            aOrbiterI = RotL64((aOrbiterI * 6619682184124713031U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 17970527747978977453U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 2326714817603921480U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14581676978186226887U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 7875511075130474136U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 17225673071833726819U;
            aOrbiterG = RotL64((aOrbiterG * 1196024136909896027U), 21U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterB, 51U);
            aIngress = aIngress + (RotL64(aOrbiterI, 27U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 39U));
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterG, 6U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterH, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aCross, 11U) + aOrbiterD) + RotL64(aOrbiterI, 41U));
            aWandererF = aWandererF + (((RotL64(aScatter, 28U) + RotL64(aOrbiterG, 11U)) + aOrbiterC) + RotL64(aCarry, 41U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 43U) + aOrbiterG) + RotL64(aOrbiterE, 38U));
            aWandererE = aWandererE + ((RotL64(aIngress, 51U) + RotL64(aOrbiterH, 51U)) + aOrbiterE);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 39U) + aOrbiterC) + RotL64(aOrbiterK, 43U));
            aWandererH = aWandererH + (((RotL64(aIngress, 53U) + RotL64(aOrbiterJ, 53U)) + aOrbiterG) + RotL64(aCarry, 27U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 57U) + aOrbiterE) + RotL64(aOrbiterB, 35U));
            aWandererD = aWandererD + ((RotL64(aCross, 47U) + aOrbiterF) + RotL64(aOrbiterD, 58U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterJ, 27U)) + aOrbiterA) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 37U) + aOrbiterB) + RotL64(aOrbiterK, 3U)) + aPhaseDWandererUpdateSaltD[((aIndex + 8U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 30U) + aOrbiterI) + RotL64(aOrbiterA, 5U)) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 24U));
            aCarry = aCarry + (RotL64(aWandererF, 37U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererK, 41U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererG, 21U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererE, 26U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererH, 11U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ aNonceWordB;
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 15656U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 14103U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 12046U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 13114U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 21U) ^ RotL64(aIngress, 36U)) ^ (RotL64(aCarry, 5U) + RotL64(aPrevious, 51U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterD = ((aWandererH + RotL64(aIngress, 23U)) + RotL64(aCarry, 13U)) + 13915875634607599122U;
            aOrbiterB = ((aWandererI + RotL64(aCross, 56U)) + 1695770381382411673U) + aPhaseDOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = (aWandererB + RotL64(aScatter, 3U)) + 3709105579778295511U;
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 19U)) + 7673376335333251804U) + aNonceWordN;
            aOrbiterG = (aWandererJ + RotL64(aIngress, 35U)) + 8814147709738503518U;
            aOrbiterJ = (aWandererE + RotL64(aScatter, 37U)) + 13451412605350381172U;
            aOrbiterA = (aWandererF + RotL64(aPrevious, 43U)) + 6447870234069609538U;
            aOrbiterK = (((aWandererC + RotL64(aCross, 13U)) + RotL64(aCarry, 29U)) + 13419487997946496825U) + aNonceWordG;
            aOrbiterE = ((((aWandererA + RotL64(aScatter, 39U)) + RotL64(aCarry, 19U)) + 5478309847615220345U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordL;
            aOrbiterI = (aWandererK + RotL64(aPrevious, 30U)) + 3635184969215610049U;
            aOrbiterC = (aWandererG + RotL64(aCross, 5U)) + 12527903812035294828U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 1684685110885338814U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 12860354576326835090U;
            aOrbiterF = RotL64((aOrbiterF * 12743745087733307255U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 9081823570147481835U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 14369321778210049109U) ^ aNonceWordF;
            aOrbiterJ = RotL64((aOrbiterJ * 17865953349448767035U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 11518132079084873250U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 11893535026126957389U;
            aOrbiterB = RotL64((aOrbiterB * 15751374986135615095U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 7084079180579206226U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 2999676609847603277U;
            aOrbiterG = RotL64((aOrbiterG * 14602698397511266403U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 17683445810614029153U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 11576460512964896969U;
            aOrbiterK = RotL64((aOrbiterK * 5243651036457051155U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 13429800604736567949U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 14661785761747367546U) ^ aNonceWordD;
            aOrbiterI = RotL64((aOrbiterI * 4765843989277333421U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 12837164345582888950U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 6222666313184669392U;
            aOrbiterD = RotL64((aOrbiterD * 17402483466567712319U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 5358647039491079457U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 12459911673401497180U;
            aOrbiterH = RotL64((aOrbiterH * 13605465035256188065U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 3333017644772803587U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 15501587702102554928U;
            aOrbiterA = RotL64((aOrbiterA * 4921693371641768339U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 8492287653837766613U) + aNonceWordC;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 3432736785678875404U;
            aOrbiterE = RotL64((aOrbiterE * 7326419883291516513U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 2841486107704281869U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 13915875634607599122U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 707861617246345083U), 19U);
            //
            aIngress = RotL64(aOrbiterC, 47U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 29U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 51U));
            aIngress = aIngress + (RotL64(aOrbiterI, 19U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterD, 10U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterG, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aCross, 21U) + aOrbiterG) + RotL64(aOrbiterA, 35U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterC, 10U)) + aOrbiterE);
            aWandererK = aWandererK + (((RotL64(aPrevious, 28U) + RotL64(aOrbiterJ, 13U)) + aOrbiterE) + RotL64(aCarry, 5U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterB, 37U)) + aOrbiterI);
            aWandererC = aWandererC + ((((RotL64(aCross, 13U) + RotL64(aOrbiterJ, 3U)) + aOrbiterI) + RotL64(aCarry, 47U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 37U) + RotL64(aOrbiterD, 39U)) + aOrbiterG) + aNonceWordJ);
            aWandererH = aWandererH + (((RotL64(aScatter, 26U) + RotL64(aOrbiterJ, 57U)) + aOrbiterH) + aNonceWordP);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterC, 43U)) + aOrbiterF) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aIngress, 39U) + aOrbiterC) + RotL64(aOrbiterI, 41U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 41U) + aOrbiterJ) + RotL64(aOrbiterK, 23U));
            aWandererB = aWandererB + ((RotL64(aCross, 43U) + RotL64(aOrbiterE, 30U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 18U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 51U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + RotL64(aWandererF, 37U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordG);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 18350U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 19209U)) & S_BLOCK1], 10U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 18749U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17337U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 36U) ^ RotL64(aIngress, 11U)) ^ (RotL64(aPrevious, 51U) + RotL64(aCarry, 23U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterC = ((aWandererB + RotL64(aCross, 4U)) + 15036852811491820366U) + aNonceWordF;
            aOrbiterI = (aWandererH + RotL64(aIngress, 39U)) + 305637140752898475U;
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 11U)) + RotL64(aCarry, 39U)) + 11948631574496129610U;
            aOrbiterA = (aWandererF + RotL64(aPrevious, 19U)) + 5321623592482991426U;
            aOrbiterF = (aWandererG + RotL64(aScatter, 44U)) + 4075270159062690728U;
            aOrbiterD = (aWandererA + RotL64(aCross, 57U)) + 15111580500356908928U;
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 27U)) + 7244150695504160363U) + aNonceWordA;
            aOrbiterB = ((aWandererC + RotL64(aIngress, 47U)) + RotL64(aCarry, 23U)) + 5131563519577488862U;
            aOrbiterH = (aWandererE + RotL64(aCross, 23U)) + 5881954992088651371U;
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 41U)) + 12780935808751507998U) + aPhaseDOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = (((aWandererD + RotL64(aPrevious, 29U)) + RotL64(aCarry, 47U)) + 12599159643925470226U) + aPhaseDOrbiterAssignSaltA[((aIndex + 10U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 9466589929741834066U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 6093158735705189789U;
            aOrbiterG = RotL64((aOrbiterG * 7453778295800853653U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 17461243886150519249U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterI) ^ 15456408913739900718U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterF = RotL64((aOrbiterF * 16093292401746174671U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 11260643903290392780U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 7870342756041882616U;
            aOrbiterD = RotL64((aOrbiterD * 2431528656086173419U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 134484990005888936U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 10626896209992890407U;
            aOrbiterE = RotL64((aOrbiterE * 12034131076645285597U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 14031164129515132292U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 1771835705730244212U;
            aOrbiterB = RotL64((aOrbiterB * 186981668443596623U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 16395472745067254664U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 1455944290845294254U;
            aOrbiterH = RotL64((aOrbiterH * 6757824754363319079U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 17866422769075350837U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 10226884082632410805U;
            aOrbiterJ = RotL64((aOrbiterJ * 206035536985843815U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 14474587247775371703U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 8501763445324525303U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5298694643596784007U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 222650368553738561U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 3901452368735982094U;
            aOrbiterC = RotL64((aOrbiterC * 18347115513126660483U), 13U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterK) + 3063093906728331146U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1]) + aNonceWordN;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 9026710562384443411U;
            aOrbiterI = RotL64((aOrbiterI * 8411243802199203035U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 11282041925238364080U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 15036852811491820366U) ^ aNonceWordO;
            aOrbiterA = RotL64((aOrbiterA * 18185121326941087841U), 47U);
            //
            aIngress = RotL64(aOrbiterD, 23U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 3U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 41U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 37U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 44U));
            aIngress = aIngress + RotL64(aOrbiterH, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 5U) + aOrbiterA) + RotL64(aOrbiterB, 43U)) + aNonceWordB);
            aWandererH = aWandererH + ((RotL64(aScatter, 29U) + RotL64(aOrbiterK, 3U)) + aOrbiterD);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 34U) + RotL64(aOrbiterF, 29U)) + aOrbiterJ);
            aWandererJ = aWandererJ + ((RotL64(aCross, 51U) + aOrbiterJ) + RotL64(aOrbiterA, 36U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 41U) + aOrbiterC) + RotL64(aOrbiterK, 57U));
            aWandererC = aWandererC + (((RotL64(aIngress, 13U) + aOrbiterF) + RotL64(aOrbiterI, 21U)) + RotL64(aCarry, 5U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 27U) + aOrbiterD) + RotL64(aOrbiterF, 41U));
            aWandererE = aWandererE + ((RotL64(aScatter, 43U) + aOrbiterD) + RotL64(aOrbiterH, 6U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 22U) + aOrbiterE) + RotL64(aOrbiterC, 13U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterE, 53U)) + aOrbiterG) + RotL64(aCarry, 35U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterG, 47U)) + aOrbiterJ) + aPhaseDWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + (RotL64(aWandererA, 37U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererH, 28U) ^ aWandererB);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + (RotL64(aWandererG, 21U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererD, 11U);
            aCarry = aCarry + RotL64(aIngress, 44U);
            aCarry = aCarry ^ aNonceWordP;
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 23826U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22902U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 24881U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 22086U)) & S_BLOCK1], 50U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aPrevious, 40U)) ^ (RotL64(aCross, 23U) + RotL64(aIngress, 57U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterK = ((aWandererD + RotL64(aCross, 54U)) + RotL64(aCarry, 11U)) + 7893287783892523139U;
            aOrbiterF = (aWandererK + RotL64(aScatter, 11U)) + 10257331997383491153U;
            aOrbiterH = ((aWandererE + RotL64(aIngress, 57U)) + RotL64(aCarry, 57U)) + 14562226733652231753U;
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 43U)) + RotL64(aCarry, 41U)) + 14320342577110737851U;
            aOrbiterC = (aWandererF + RotL64(aIngress, 27U)) + 9816717579822880756U;
            aOrbiterA = (aWandererA + RotL64(aScatter, 29U)) + 9558926960095881953U;
            aOrbiterD = (aWandererB + RotL64(aCross, 41U)) + 9230371862654338324U;
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 50U)) + 6414274291252913420U) + aNonceWordF;
            aOrbiterG = ((aWandererI + RotL64(aCross, 13U)) + 13868546184398350849U) + aPhaseDOrbiterAssignSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterI = ((aWandererG + RotL64(aScatter, 23U)) + 16940736952569949038U) + aPhaseDOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 35U)) + 2866957764814864371U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 7916721976073979724U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 1602444214978842275U;
            aOrbiterH = RotL64((aOrbiterH * 11072503711308122385U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 9529061385251008037U) + aNonceWordM;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 8402775110887376588U;
            aOrbiterA = RotL64((aOrbiterA * 13980225144628227381U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 15003592180290390713U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 14195681406520825751U;
            aOrbiterB = RotL64((aOrbiterB * 11455000833788877217U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 3263577002367714202U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 12019422062655581928U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5002313835338447799U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 8508638054582582917U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 6536618106353552880U;
            aOrbiterK = RotL64((aOrbiterK * 6233964121117511885U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 9654542989321430868U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 7019594782797863244U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1234877854354279981U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 8256061220727519919U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 9232754129467036130U) ^ aNonceWordG;
            aOrbiterD = RotL64((aOrbiterD * 17556001874302369781U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 5608829951337740378U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 12632120498473345701U;
            aOrbiterG = RotL64((aOrbiterG * 6994794653605831925U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 17313364434369677697U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 10147405701828074385U;
            aOrbiterJ = RotL64((aOrbiterJ * 11544579984323623009U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 16853703086012867980U) + aNonceWordD;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 3591438641820423822U;
            aOrbiterF = RotL64((aOrbiterF * 3570430739475340845U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 13974806289212867511U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 7893287783892523139U;
            aOrbiterC = RotL64((aOrbiterC * 6648351608953339723U), 35U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterF, 13U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 34U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 11U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 3U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 53U));
            aIngress = aIngress + RotL64(aOrbiterA, 50U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterD, 13U)) + aOrbiterH);
            aWandererA = aWandererA + ((((RotL64(aScatter, 41U) + RotL64(aOrbiterG, 56U)) + aOrbiterC) + RotL64(aCarry, 35U)) + aPhaseDWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 6U) + RotL64(aOrbiterA, 29U)) + aOrbiterF);
            aWandererB = aWandererB + ((RotL64(aIngress, 21U) + aOrbiterH) + RotL64(aOrbiterJ, 37U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterD, 21U)) + aOrbiterI) + aNonceWordJ);
            aWandererG = aWandererG + (((RotL64(aIngress, 35U) + RotL64(aOrbiterE, 53U)) + aOrbiterB) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterD, 42U)) + aOrbiterC);
            aWandererI = aWandererI + (((RotL64(aCross, 51U) + aOrbiterD) + RotL64(aOrbiterB, 23U)) + RotL64(aCarry, 5U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 60U) + aOrbiterG) + RotL64(aOrbiterK, 35U));
            aWandererH = aWandererH + ((RotL64(aIngress, 57U) + RotL64(aOrbiterG, 51U)) + aOrbiterF);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterD, 27U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + (RotL64(aWandererI, 54U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + (RotL64(aWandererK, 37U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererA, 58U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordN);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 27354U)) & S_BLOCK1], 20U) ^ RotL64(aWorkLaneB[((aIndex + 27334U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27566U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28413U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 54U) ^ RotL64(aCarry, 39U)) + (RotL64(aPrevious, 21U) ^ RotL64(aCross, 5U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterB = ((aWandererE + RotL64(aScatter, 56U)) + 5573188770530340913U) + aNonceWordJ;
            aOrbiterI = (((aWandererD + RotL64(aPrevious, 21U)) + RotL64(aCarry, 13U)) + 1431772230889897111U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = (aWandererG + RotL64(aIngress, 51U)) + 4809192776429682319U;
            aOrbiterF = (aWandererJ + RotL64(aCross, 35U)) + 5576603692574369341U;
            aOrbiterC = (((aWandererH + RotL64(aIngress, 29U)) + RotL64(aCarry, 51U)) + 2720143226007220386U) + aNonceWordG;
            aOrbiterH = (aWandererK + RotL64(aScatter, 47U)) + 17220328778565331629U;
            aOrbiterE = ((aWandererF + RotL64(aCross, 23U)) + 9629485808442089423U) + aPhaseDOrbiterAssignSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = (aWandererA + RotL64(aPrevious, 12U)) + 1136998437010390983U;
            aOrbiterD = ((aWandererC + RotL64(aScatter, 19U)) + RotL64(aCarry, 3U)) + 11893390497814523841U;
            aOrbiterA = (aWandererB + RotL64(aCross, 3U)) + 1764986431917532370U;
            aOrbiterJ = (aWandererI + RotL64(aIngress, 53U)) + 1741014798007010376U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 12221368453236547044U) + aNonceWordN;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 7694538641172350430U;
            aOrbiterG = RotL64((aOrbiterG * 8439120733670016501U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 17472344518811560603U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 3308740700728172984U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15290400462887712083U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 9535358833412446771U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 11192312491731312451U;
            aOrbiterH = RotL64((aOrbiterH * 17405609148475445743U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 14850451970047190039U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 11932493299452443256U;
            aOrbiterE = RotL64((aOrbiterE * 7964808728820467795U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 5972619895614731870U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 17174497535809891690U;
            aOrbiterK = RotL64((aOrbiterK * 15471084511364572533U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 17412894714378898351U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 14675615208706549810U;
            aOrbiterD = RotL64((aOrbiterD * 7864845089606499769U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 16116792108013658523U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 9702262005960966336U;
            aOrbiterA = RotL64((aOrbiterA * 970452849653781703U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 17337264966818542841U) + aNonceWordI;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 7004462033775827275U;
            aOrbiterJ = RotL64((aOrbiterJ * 11943575980344402681U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 17499850384482055438U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 1839357713256560566U) ^ aNonceWordE;
            aOrbiterB = RotL64((aOrbiterB * 12943750650487416281U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 8144238113917577524U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 888195876227325908U;
            aOrbiterI = RotL64((aOrbiterI * 7941506708630993709U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 5081763359501717653U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 5573188770530340913U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9699901099898698965U), 13U);
            //
            aIngress = RotL64(aOrbiterG, 50U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 13U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + RotL64(aOrbiterB, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aCross, 13U) + RotL64(aOrbiterF, 34U)) + aOrbiterI);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 21U) + aOrbiterD) + RotL64(aOrbiterB, 3U));
            aWandererI = aWandererI + (((RotL64(aIngress, 60U) + aOrbiterG) + RotL64(aOrbiterE, 29U)) + RotL64(aCarry, 57U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterB, 23U)) + aOrbiterH) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 47U) + aOrbiterD) + RotL64(aOrbiterK, 41U)) + aNonceWordF);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterA, 5U)) + aOrbiterF) + aPhaseDWandererUpdateSaltE[((aIndex + 16U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aCross, 35U) + RotL64(aOrbiterJ, 21U)) + aOrbiterA);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 43U) + aOrbiterE) + RotL64(aOrbiterF, 39U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 19U) + RotL64(aOrbiterG, 57U)) + aOrbiterC) + aNonceWordH);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 51U) + aOrbiterA) + RotL64(aOrbiterC, 18U));
            aWandererG = aWandererG + (((RotL64(aScatter, 54U) + RotL64(aOrbiterG, 37U)) + aOrbiterD) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererH);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 5U));
            aCarry = aCarry + (RotL64(aWandererA, 46U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererC, 39U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordB);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xB15A013340A0ED6DULL + 0xE7501AD58C40AA24ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x8952ED1C388AA535ULL + 0xC9255740027B728BULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x89B4CF6A8F1A8EF7ULL + 0x9921B1CD66424647ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xBDA15EA59A7D14B9ULL + 0xB493B088DF021C39ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x8B76CEDA9AB23CA5ULL + 0xFFCBDF8800184BCAULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xBF2A873700DC09A7ULL + 0xA1E12F6B0868FAB2ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xD3965821AD7E369BULL + 0x85447EE5A3A124AEULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xDC9F47BC7C983601ULL + 0xB3622816A990CEA0ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xA909B3A649232D6DULL + 0x922741F111B179E4ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x90552A440D166D4FULL + 0xE357A494A58FAEC8ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xA2A29FC6251D54E9ULL + 0x9FD4E38A64E2DA89ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xD8D35BB4780D06E5ULL + 0xD9087876E27407F5ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xAC0A2CEBF3DD70D9ULL + 0xAD47C6DD18BE125FULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x870D1C7C9365328BULL + 0x9D02068DA8B628ECULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xE8D4FDD45FEF0239ULL + 0xC06DD236B3CB4C30ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x87498607570E834DULL + 0x90B6D2E7AED5DFFFULL);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 2034U)) & S_BLOCK1], 46U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 2683U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 5103U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 4177U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 22U) + RotL64(aPrevious, 53U)) ^ (RotL64(aIngress, 37U) + RotL64(aCarry, 3U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterF = ((aWandererH + RotL64(aScatter, 41U)) + 18180797995100240808U) + aNonceWordH;
            aOrbiterB = (aWandererK + RotL64(aPrevious, 37U)) + 6585906608223552885U;
            aOrbiterC = (aWandererE + RotL64(aCross, 29U)) + 14088708930575939855U;
            aOrbiterJ = (aWandererA + RotL64(aIngress, 11U)) + 468974153311516044U;
            aOrbiterG = ((aWandererD + RotL64(aScatter, 5U)) + 12481951025619894110U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterA = ((aWandererF + RotL64(aCross, 50U)) + RotL64(aCarry, 27U)) + 17227987923860711763U;
            aOrbiterI = (aWandererB + RotL64(aIngress, 43U)) + 4373962756657477139U;
            aOrbiterD = (aWandererG + RotL64(aPrevious, 53U)) + 2077576476565420951U;
            aOrbiterE = (aWandererI + RotL64(aCross, 47U)) + 17435011300234663764U;
            aOrbiterK = ((((aWandererJ + RotL64(aScatter, 18U)) + RotL64(aCarry, 13U)) + 4118039398293246896U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordK;
            aOrbiterH = (((aWandererC + RotL64(aPrevious, 57U)) + RotL64(aCarry, 23U)) + 13724716599855216683U) + aNonceWordD;
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 12391461204689596339U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterF) ^ 9900605191533799627U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterC = RotL64((aOrbiterC * 13553565332531046301U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 972946858824366125U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 17247681919694541215U;
            aOrbiterA = RotL64((aOrbiterA * 2974639094630445643U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 15442851427306771601U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 7303586227288294037U;
            aOrbiterF = RotL64((aOrbiterF * 15406402525021428799U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 12650358753454105119U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 1483710933373510492U;
            aOrbiterJ = RotL64((aOrbiterJ * 6531763256577221891U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 18065810162229740788U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 11311677121338794007U;
            aOrbiterI = RotL64((aOrbiterI * 15116367961682119467U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 2355285311890287611U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 1287783821903407734U;
            aOrbiterE = RotL64((aOrbiterE * 8054011680932255985U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 9282654686791135654U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 15488608017745542551U;
            aOrbiterH = RotL64((aOrbiterH * 7858866274035085123U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 13296835576073421802U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 7127700236018338741U;
            aOrbiterB = RotL64((aOrbiterB * 11246173563106014149U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 1365928843264598789U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 7777790578813003657U;
            aOrbiterG = RotL64((aOrbiterG * 10121688100505628161U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 2104270617375082523U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 13363764449819651164U;
            aOrbiterD = RotL64((aOrbiterD * 2685452132715528975U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 2008038686059197988U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 18180797995100240808U;
            aOrbiterK = RotL64((aOrbiterK * 8978998151475372047U), 53U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterF, 26U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 41U));
            aIngress = aIngress + (RotL64(aOrbiterD, 29U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 53U));
            aIngress = aIngress + RotL64(aOrbiterH, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aPrevious, 46U) + RotL64(aOrbiterG, 23U)) + aOrbiterH) + aNonceWordF);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 29U) + aOrbiterJ) + RotL64(aOrbiterC, 21U));
            aWandererF = aWandererF + ((((RotL64(aScatter, 51U) + aOrbiterI) + RotL64(aOrbiterE, 26U)) + aNonceWordP) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 5U) + aOrbiterI) + RotL64(aOrbiterK, 13U));
            aWandererE = aWandererE + ((RotL64(aScatter, 39U) + aOrbiterE) + RotL64(aOrbiterH, 51U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterA, 43U)) + aOrbiterD) + aNonceWordE);
            aWandererI = aWandererI + ((RotL64(aCross, 13U) + RotL64(aOrbiterA, 47U)) + aOrbiterF);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterH, 11U)) + aOrbiterB) + aPhaseEWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 58U) + aOrbiterJ) + RotL64(aOrbiterH, 37U)) + RotL64(aCarry, 37U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 11U) + aOrbiterA) + RotL64(aOrbiterB, 6U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 21U) + aOrbiterI) + RotL64(aOrbiterB, 35U)) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 20U));
            aCarry = aCarry + (RotL64(aWandererG, 39U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererK);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 37U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 41U));
            aCarry = aCarry + RotL64(aWandererH, 46U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ aNonceWordB;
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 6587U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneD[((aIndex + 8964U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 10286U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 8306U)) & S_BLOCK1], 46U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 21U) ^ RotL64(aPrevious, 36U)) + (RotL64(aCarry, 51U) ^ RotL64(aIngress, 5U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterC = (aWandererA + RotL64(aPrevious, 21U)) + 16462052553719977502U;
            aOrbiterH = ((aWandererB + RotL64(aScatter, 30U)) + 12337064059566619581U) + aNonceWordE;
            aOrbiterE = (aWandererH + RotL64(aIngress, 11U)) + 15801005007094515447U;
            aOrbiterF = (aWandererK + RotL64(aCross, 51U)) + 8228706742665081656U;
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 35U)) + RotL64(aCarry, 23U)) + 11006723027845190869U;
            aOrbiterI = (aWandererD + RotL64(aCross, 57U)) + 18173765337829177450U;
            aOrbiterJ = (((aWandererI + RotL64(aPrevious, 27U)) + RotL64(aCarry, 57U)) + 530215083653542558U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = (aWandererE + RotL64(aIngress, 37U)) + 6608611827035564511U;
            aOrbiterD = ((aWandererF + RotL64(aCross, 13U)) + RotL64(aCarry, 11U)) + 2246051826221626809U;
            aOrbiterB = (aWandererC + RotL64(aPrevious, 42U)) + 5228575308895381421U;
            aOrbiterA = ((aWandererG + RotL64(aScatter, 23U)) + 10999213210689606857U) + aPhaseEOrbiterAssignSaltF[((aIndex + 10U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 3773371037240485696U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 8887985779436152504U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 698713082830739677U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 11150566414723818350U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 8336366151003049546U;
            aOrbiterH = RotL64((aOrbiterH * 9033771197242493699U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 13233968794237090787U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 8172558473508478819U;
            aOrbiterK = RotL64((aOrbiterK * 17837070423649268435U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 133564480283347997U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 15104810248883567064U;
            aOrbiterJ = RotL64((aOrbiterJ * 706802420642303533U), 51U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterC) + 9138629520201127075U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1]) + aNonceWordL;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 13993086066341664080U;
            aOrbiterD = RotL64((aOrbiterD * 4875046427147105077U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 6547273508580516932U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 9838727018769865759U;
            aOrbiterC = RotL64((aOrbiterC * 11395273371936839815U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 11685694999526122626U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 8945983172566303116U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17791527981004597623U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 17606249889617356327U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 9296903152000480008U;
            aOrbiterI = RotL64((aOrbiterI * 18066622289408024413U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 14248192861977167583U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 5467843420970464193U;
            aOrbiterG = RotL64((aOrbiterG * 10121398470914323221U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 17072313558131700643U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 7932446176598954438U) ^ aNonceWordG;
            aOrbiterB = RotL64((aOrbiterB * 11684711939539349335U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 15377107166135929052U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 16462052553719977502U;
            aOrbiterA = RotL64((aOrbiterA * 9057188521274832217U), 21U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterC, 35U);
            aIngress = aIngress + (RotL64(aOrbiterH, 53U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 44U));
            aIngress = aIngress + (RotL64(aOrbiterI, 5U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + RotL64(aOrbiterA, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterA, 57U)) + aNonceWordN);
            aWandererH = aWandererH + (((RotL64(aScatter, 53U) + RotL64(aOrbiterI, 14U)) + aOrbiterG) + RotL64(aCarry, 19U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 28U) + aOrbiterG) + RotL64(aOrbiterH, 29U));
            aWandererE = aWandererE + (((RotL64(aCross, 13U) + RotL64(aOrbiterA, 19U)) + aOrbiterF) + RotL64(aCarry, 51U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterH, 41U)) + aOrbiterE);
            aWandererC = aWandererC + (((RotL64(aCross, 51U) + aOrbiterC) + RotL64(aOrbiterF, 43U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 10U) + RotL64(aOrbiterD, 27U)) + aOrbiterJ);
            aWandererB = aWandererB + ((RotL64(aIngress, 47U) + RotL64(aOrbiterB, 21U)) + aOrbiterF);
            aWandererI = aWandererI ^ ((RotL64(aCross, 19U) + aOrbiterD) + RotL64(aOrbiterI, 3U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 37U) + aOrbiterK) + RotL64(aOrbiterI, 39U)) + aNonceWordK) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 57U) + aOrbiterH) + RotL64(aOrbiterK, 60U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 60U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 21U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererJ, 44U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ aNonceWordC;
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 11286U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 11658U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 15734U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneC[((aIndex + 12377U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 37U) ^ RotL64(aIngress, 53U)) + (RotL64(aCross, 5U) + RotL64(aPrevious, 18U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterB = (aWandererA + RotL64(aCross, 56U)) + 13350544654542863236U;
            aOrbiterK = ((aWandererB + RotL64(aScatter, 3U)) + 12364346790125404372U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 27U)) + RotL64(aCarry, 13U)) + 9738750172849512764U;
            aOrbiterG = (((aWandererJ + RotL64(aIngress, 21U)) + RotL64(aCarry, 51U)) + 3781373837635491421U) + aNonceWordG;
            aOrbiterA = (aWandererD + RotL64(aCross, 29U)) + 16635020317512702337U;
            aOrbiterI = (aWandererF + RotL64(aScatter, 35U)) + 5383653921676231276U;
            aOrbiterE = ((aWandererH + RotL64(aIngress, 39U)) + 10181959815492056493U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = (aWandererC + RotL64(aPrevious, 43U)) + 10005510924273927017U;
            aOrbiterD = ((aWandererK + RotL64(aScatter, 11U)) + RotL64(aCarry, 43U)) + 9524687662265740565U;
            aOrbiterF = (aWandererG + RotL64(aPrevious, 5U)) + 4259138552009771014U;
            aOrbiterH = (aWandererE + RotL64(aIngress, 48U)) + 8973051213213726023U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 17602611840127337490U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 8218984546932905269U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17504305273683304231U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 18102186122213487888U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 2629927500298092976U;
            aOrbiterI = RotL64((aOrbiterI * 6983280164448292723U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 2491581597835795234U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 9506602492971620955U;
            aOrbiterK = RotL64((aOrbiterK * 9559829640915637163U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 13422942713680612924U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 15037354693234876601U;
            aOrbiterA = RotL64((aOrbiterA * 12692376075738621447U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 12896066842192894694U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 2202952306291905855U;
            aOrbiterC = RotL64((aOrbiterC * 6779368532763429997U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 12160313482450599313U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 10812986281270407756U;
            aOrbiterF = RotL64((aOrbiterF * 7786608700746771809U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 12474638293190144525U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 5882870951276225224U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15532427302173572457U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 3782896138051179209U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 10965680631059882311U;
            aOrbiterG = RotL64((aOrbiterG * 14060923998307082385U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 15650420683333746952U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 4110674660963676864U;
            aOrbiterE = RotL64((aOrbiterE * 11724979274890265275U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 694817156953099464U) + aNonceWordP;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 4402927404825116007U;
            aOrbiterD = RotL64((aOrbiterD * 579586789292520113U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 6849178151532923489U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 13350544654542863236U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2416097748778941523U), 39U);
            //
            aIngress = RotL64(aOrbiterF, 37U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 23U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 19U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 4U));
            aIngress = aIngress + RotL64(aOrbiterD, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aScatter, 48U) + aOrbiterC) + RotL64(aOrbiterA, 51U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterK, 22U)) + aOrbiterD);
            aWandererC = aWandererC + (((RotL64(aCross, 3U) + aOrbiterF) + RotL64(aOrbiterK, 19U)) + RotL64(aCarry, 27U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 23U) + aOrbiterC) + RotL64(aOrbiterI, 29U));
            aWandererK = aWandererK + ((RotL64(aCross, 27U) + aOrbiterD) + RotL64(aOrbiterB, 3U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 60U) + RotL64(aOrbiterK, 39U)) + aOrbiterG) + aPhaseEWandererUpdateSaltE[((aIndex + 4U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 11U) + aOrbiterJ) + RotL64(aOrbiterE, 12U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterF, 43U)) + aOrbiterH);
            aWandererA = aWandererA + ((RotL64(aCross, 57U) + RotL64(aOrbiterE, 37U)) + aOrbiterD);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterE, 35U)) + aOrbiterI);
            aWandererI = aWandererI + ((((RotL64(aIngress, 29U) + RotL64(aOrbiterJ, 47U)) + aOrbiterH) + RotL64(aCarry, 39U)) + aNonceWordO);
            //
            aCarry = aCarry + (RotL64(aWandererF, 54U) ^ aWandererA);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + (RotL64(aWandererI, 37U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererK);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + RotL64(aWandererE, 46U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordL);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 16904U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 18336U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 19426U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneD[((aIndex + 18700U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 13U) + RotL64(aCarry, 60U)) + (RotL64(aCross, 29U) ^ RotL64(aIngress, 43U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterA = (((aWandererF + RotL64(aScatter, 51U)) + RotL64(aCarry, 51U)) + 14179205183062705133U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = ((aWandererI + RotL64(aIngress, 22U)) + 210032324058740920U) + aNonceWordA;
            aOrbiterE = (aWandererA + RotL64(aCross, 57U)) + 7387115089142500152U;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 35U)) + 17583362781238061430U) + aNonceWordK;
            aOrbiterD = ((aWandererC + RotL64(aCross, 37U)) + RotL64(aCarry, 21U)) + 4991442849150005943U;
            aOrbiterC = (aWandererD + RotL64(aIngress, 39U)) + 2891376254689854555U;
            aOrbiterG = (aWandererH + RotL64(aScatter, 29U)) + 10523274382407446239U;
            aOrbiterH = (aWandererB + RotL64(aPrevious, 11U)) + 3861893764676218667U;
            aOrbiterI = (aWandererG + RotL64(aScatter, 41U)) + 3366674459852093746U;
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 14U)) + 5898492634386601145U) + aNonceWordC;
            aOrbiterJ = (((aWandererK + RotL64(aIngress, 43U)) + RotL64(aCarry, 37U)) + 7047353571244768721U) + aPhaseEOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 14374108805453186316U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 8763667021501226510U;
            aOrbiterE = RotL64((aOrbiterE * 7694695426430267863U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 18261523829316379575U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 650477532238860965U;
            aOrbiterD = RotL64((aOrbiterD * 8291758490821819851U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 2162326554604894042U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 5776546692501825278U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14911545784585246537U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 3501863793638415049U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 14853789267425352958U;
            aOrbiterG = RotL64((aOrbiterG * 10590325397179928739U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 15399673014671329743U) + aNonceWordH;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 12253428583438990426U;
            aOrbiterH = RotL64((aOrbiterH * 12052855472196447849U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 13202953937621953839U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 7547616636832698398U;
            aOrbiterI = RotL64((aOrbiterI * 9533399972562428073U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 15709801946594868318U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 12458677982746610971U;
            aOrbiterB = RotL64((aOrbiterB * 6662570874316418993U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 6957370791367530127U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 10511379961344950861U;
            aOrbiterJ = RotL64((aOrbiterJ * 15551333099264031337U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 16489828646914719181U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 6827290294344770680U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6408864925398536651U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 3308531598034561099U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 10336568208337990458U;
            aOrbiterF = RotL64((aOrbiterF * 5606941634846696657U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 14116471880098183908U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 14179205183062705133U;
            aOrbiterK = RotL64((aOrbiterK * 8824119255416045191U), 51U);
            //
            aIngress = RotL64(aOrbiterI, 34U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 23U));
            aIngress = aIngress + (RotL64(aOrbiterA, 13U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterB, 5U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterJ, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aScatter, 19U) + aOrbiterG) + RotL64(aOrbiterJ, 57U)) + aNonceWordL) + aPhaseEWandererUpdateSaltC[((aIndex + 10U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 4U) + RotL64(aOrbiterE, 27U)) + aOrbiterH);
            aWandererH = aWandererH + ((RotL64(aCross, 37U) + RotL64(aOrbiterB, 24U)) + aOrbiterF);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterD, 35U)) + aOrbiterF) + aPhaseEWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 21U) + RotL64(aOrbiterG, 3U)) + aOrbiterC) + RotL64(aCarry, 35U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 23U) + aOrbiterI) + RotL64(aOrbiterC, 19U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 47U) + aOrbiterE) + RotL64(aOrbiterK, 38U)) + aNonceWordE);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterA, 47U)) + aOrbiterD);
            aWandererI = aWandererI + ((RotL64(aCross, 35U) + RotL64(aOrbiterE, 53U)) + aOrbiterG);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterJ, 5U)) + aOrbiterD);
            aWandererK = aWandererK + (((RotL64(aPrevious, 14U) + RotL64(aOrbiterA, 21U)) + aOrbiterC) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 54U));
            aCarry = aCarry + (RotL64(aWandererE, 37U) ^ aWandererI);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + (RotL64(aWandererG, 51U) ^ aWandererJ);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 48U));
            aCarry = aCarry + RotL64(aWandererF, 57U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordJ);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 21895U)) & S_BLOCK1], 18U) ^ RotL64(aOperationLaneA[((aIndex + 24392U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 23679U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25850U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aPrevious, 51U)) + (RotL64(aIngress, 4U) ^ RotL64(aCross, 21U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterB = (aWandererG + RotL64(aScatter, 11U)) + 12131317914288566437U;
            aOrbiterD = (aWandererF + RotL64(aCross, 21U)) + 5672805657999385496U;
            aOrbiterF = (aWandererJ + RotL64(aPrevious, 27U)) + 3581710244233124197U;
            aOrbiterE = (aWandererD + RotL64(aIngress, 60U)) + 15251296040538489436U;
            aOrbiterK = (((aWandererC + RotL64(aPrevious, 37U)) + RotL64(aCarry, 23U)) + 11295008604679904153U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = (aWandererH + RotL64(aIngress, 23U)) + 2230897493419504490U;
            aOrbiterJ = (((aWandererE + RotL64(aScatter, 57U)) + RotL64(aCarry, 11U)) + 7109600123297458999U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = (aWandererB + RotL64(aCross, 3U)) + 13119156643107683803U;
            aOrbiterC = ((aWandererA + RotL64(aScatter, 43U)) + 14755160867807355250U) + aNonceWordB;
            aOrbiterH = ((aWandererK + RotL64(aIngress, 54U)) + RotL64(aCarry, 29U)) + 16829363373287496832U;
            aOrbiterG = (aWandererI + RotL64(aPrevious, 19U)) + 16981122946707720883U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 8806000776958603317U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 16810923047720876014U;
            aOrbiterF = RotL64((aOrbiterF * 17872735050219539145U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 8129657889554436328U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 8653100378491974463U;
            aOrbiterI = RotL64((aOrbiterI * 11395283153912468661U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 17048985838727432415U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 10892675550889823573U;
            aOrbiterA = RotL64((aOrbiterA * 976298937314081913U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 15960158965421254346U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 12290011578634850001U;
            aOrbiterH = RotL64((aOrbiterH * 9280475585104357745U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 16265047040311479093U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 10312956912303656248U;
            aOrbiterB = RotL64((aOrbiterB * 3012584393253845131U), 11U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterH) + 16706890352221352779U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordG;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 10630955894218491929U) ^ aNonceWordN;
            aOrbiterE = RotL64((aOrbiterE * 12675937483456206355U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 4009352551041162434U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 3043810773683888556U;
            aOrbiterJ = RotL64((aOrbiterJ * 4328135390387997315U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 1398071019814944785U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 16689766557488135301U;
            aOrbiterC = RotL64((aOrbiterC * 8403881916549404871U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 15934647144489136524U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 13521276033614992223U) ^ aNonceWordH;
            aOrbiterG = RotL64((aOrbiterG * 18003640895553609933U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 4281211055727414100U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 11848150507497406421U;
            aOrbiterD = RotL64((aOrbiterD * 1107789990317433481U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 12022829841608199449U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 12131317914288566437U;
            aOrbiterK = RotL64((aOrbiterK * 13275753083882829973U), 13U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterK, 12U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 23U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterI, 51U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 35U));
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterF, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterJ, 60U)) + aOrbiterI) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aScatter, 41U) + aOrbiterD) + RotL64(aOrbiterH, 3U)) + RotL64(aCarry, 51U)) + aNonceWordO);
            aWandererA = aWandererA ^ (((RotL64(aCross, 5U) + aOrbiterK) + RotL64(aOrbiterA, 35U)) + aNonceWordI);
            aWandererI = aWandererI + ((RotL64(aIngress, 46U) + aOrbiterB) + RotL64(aOrbiterC, 11U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterE, 28U)) + aOrbiterF);
            aWandererC = aWandererC + ((RotL64(aScatter, 23U) + aOrbiterA) + RotL64(aOrbiterD, 21U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterH, 57U)) + aOrbiterG) + aNonceWordJ);
            aWandererK = aWandererK + (((RotL64(aIngress, 39U) + RotL64(aOrbiterC, 37U)) + aOrbiterG) + RotL64(aCarry, 11U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 34U) + RotL64(aOrbiterI, 41U)) + aOrbiterC) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 37U) + aOrbiterC) + RotL64(aOrbiterA, 23U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterG, 39U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 30U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 21U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 51U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + RotL64(aWandererI, 11U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ aNonceWordD;
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 31058U)) & S_BLOCK1], 52U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28730U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 28171U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30775U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 50U)) ^ (RotL64(aIngress, 19U) + RotL64(aCross, 35U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterH = (((aWandererJ + RotL64(aCross, 22U)) + RotL64(aCarry, 13U)) + 14823268998003220191U) + aNonceWordP;
            aOrbiterA = (((aWandererG + RotL64(aPrevious, 39U)) + RotL64(aCarry, 35U)) + 15295237288788213847U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterF = (aWandererC + RotL64(aScatter, 53U)) + 16434853402001133899U;
            aOrbiterB = (aWandererI + RotL64(aIngress, 37U)) + 7555911304407871631U;
            aOrbiterD = (aWandererH + RotL64(aScatter, 60U)) + 14977248264994834620U;
            aOrbiterI = (aWandererA + RotL64(aPrevious, 43U)) + 9707764144919392380U;
            aOrbiterE = (aWandererE + RotL64(aCross, 5U)) + 1277304385464681529U;
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 41U)) + RotL64(aCarry, 43U)) + 3089786220465849395U;
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 35U)) + 3700503853358695085U) + aNonceWordA;
            aOrbiterG = (aWandererK + RotL64(aCross, 13U)) + 3240054112993517371U;
            aOrbiterK = ((aWandererB + RotL64(aIngress, 29U)) + 16897532076915366859U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 18167359289798364307U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 8870819278575769863U;
            aOrbiterF = RotL64((aOrbiterF * 9334066154398059075U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 15363069206212330251U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 14858164441499725158U;
            aOrbiterD = RotL64((aOrbiterD * 14931933411393847915U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 5357144808788707522U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 2910681277417754860U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13170868582159347059U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 9824408699018165151U) + aNonceWordL;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 368370224788793300U;
            aOrbiterE = RotL64((aOrbiterE * 14358982366258729959U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 7095398304588825115U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 11418879758164313554U) ^ aNonceWordG;
            aOrbiterJ = RotL64((aOrbiterJ * 5983520332639771791U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 2171599720681913272U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 17593730219647495033U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12926053208918563087U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 17755947635188715523U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 14565740605227022106U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15866418354612945335U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 14538017880915584414U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 6174566474851449123U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 179569008593475683U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 3806438394748643441U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 13737114463856719285U;
            aOrbiterH = RotL64((aOrbiterH * 13439346068497710151U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 3698379331577470045U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 1097081284062708554U;
            aOrbiterA = RotL64((aOrbiterA * 3498627643013255777U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 215117138867597766U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 14823268998003220191U) ^ aNonceWordO;
            aOrbiterB = RotL64((aOrbiterB * 12131828437975771377U), 35U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterC, 13U);
            aIngress = aIngress + (RotL64(aOrbiterG, 41U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 44U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 35U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 5U));
            aIngress = aIngress + RotL64(aOrbiterK, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 41U) + aOrbiterE) + RotL64(aOrbiterC, 39U)) + aNonceWordH);
            aWandererD = aWandererD + ((RotL64(aIngress, 39U) + aOrbiterD) + RotL64(aOrbiterH, 57U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterI, 36U)) + aOrbiterE);
            aWandererK = aWandererK + (((RotL64(aCross, 11U) + aOrbiterG) + RotL64(aOrbiterC, 29U)) + RotL64(aCarry, 29U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 36U) + RotL64(aOrbiterH, 19U)) + aOrbiterK) + aPhaseEWandererUpdateSaltE[((aIndex + 22U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 27U) + aOrbiterF) + RotL64(aOrbiterH, 13U)) + aPhaseEWandererUpdateSaltF[((aIndex + 18U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterE, 47U)) + aOrbiterG);
            aWandererG = aWandererG + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterE, 23U)) + aOrbiterF) + RotL64(aCarry, 37U)) + aNonceWordI);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterA, 6U)) + aOrbiterI);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 21U) + aOrbiterI) + RotL64(aOrbiterB, 51U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 34U) + RotL64(aOrbiterA, 53U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererF, 42U) ^ aWandererA);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + (RotL64(aWandererI, 37U) ^ aWandererH);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 23U));
            aCarry = aCarry + RotL64(aWandererC, 14U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ aNonceWordB;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x92E5C6BEC450C63DULL + 0xA966E51D24CA9D82ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xB03BBD5D4883A431ULL + 0x98FCF11AE64A9B05ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xEAC18F1E1ECD81BBULL + 0xB712E18EEB993931ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xCC2010CCF8C4CB57ULL + 0x8D3A15FAF4BD6AF3ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xC5D87B0DE6EC1C6DULL + 0xCAE622DD59E770B6ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xEDE17EA268235389ULL + 0xF0ECC069EFCB859BULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xD1A3BD5BCF03F745ULL + 0xF2CA447073FEDA2CULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xC073CEC0B47D7EB7ULL + 0xA094890127D9DB4BULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x91109B9DE66AA02BULL + 0xD938A00E4AF39330ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x9E3C1475A0012647ULL + 0xDB9D624C5AEA5666ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xDD59CCCBE8C52B05ULL + 0x979847B887F17A6BULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xB774AD1DC1E42D65ULL + 0xDA94163580F97425ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xC7DC6D9EEC5DD8ABULL + 0xF8DBC30C34DD1CB9ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xC61C2003442E7981ULL + 0xCBBDFF595420B372ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xDF63AD895887DB5FULL + 0xEA7E80CDD6F146A4ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x9C3434B6CC86618BULL + 0x86346A319D7B1388ULL);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 827U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 13U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 5419U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 4828U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 21U) ^ RotL64(aCarry, 6U)) ^ (RotL64(aCross, 57U) + RotL64(aPrevious, 39U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 21U)) + 4848316479321533394U;
            aOrbiterF = (aWandererI + RotL64(aIngress, 29U)) + 6919360256662636195U;
            aOrbiterG = ((aWandererA + RotL64(aCross, 6U)) + 9897013582181108544U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = (aWandererB + RotL64(aScatter, 3U)) + 7319353809896158678U;
            aOrbiterI = (aWandererC + RotL64(aCross, 11U)) + 2848175435514849859U;
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 57U)) + RotL64(aCarry, 11U)) + 6967780718720437934U;
            aOrbiterC = (aWandererH + RotL64(aScatter, 14U)) + 10143884766603388136U;
            aOrbiterB = ((((aWandererG + RotL64(aIngress, 27U)) + RotL64(aCarry, 5U)) + 8675965006150972051U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordN;
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 35U)) + RotL64(aCarry, 43U)) + 16350117755560994281U;
            aOrbiterD = (aWandererK + RotL64(aCross, 19U)) + 17976597517118423760U;
            aOrbiterE = (aWandererF + RotL64(aPrevious, 53U)) + 1399631141355370237U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 3590613762034716792U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 5134624314245932157U;
            aOrbiterG = RotL64((aOrbiterG * 13077589037975283371U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 10082236952942943654U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 4015535035905433450U;
            aOrbiterA = RotL64((aOrbiterA * 4961808568701908559U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 611474103801573800U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterC) ^ 5786708483794098001U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterH = RotL64((aOrbiterH * 7694007039340089267U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 5201943497363274455U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 9282160506938328489U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5368182164239021367U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 4932320527498940158U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 11576526341731392916U;
            aOrbiterC = RotL64((aOrbiterC * 1712051774729439363U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 10790691517638887125U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 16280649213607464422U;
            aOrbiterJ = RotL64((aOrbiterJ * 10756733801499471873U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 9553716940667712810U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 11827518270964003341U) ^ aNonceWordL;
            aOrbiterE = RotL64((aOrbiterE * 1322489827908132831U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 16777463701235809321U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 3375489084588454149U;
            aOrbiterF = RotL64((aOrbiterF * 3335010977457647307U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 8129898095524287632U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 14496406641486541929U;
            aOrbiterI = RotL64((aOrbiterI * 10077246205532940301U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 17968163292907132345U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 2431407778543471402U;
            aOrbiterB = RotL64((aOrbiterB * 407105842057624537U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 18330313613898211889U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 4848316479321533394U;
            aOrbiterD = RotL64((aOrbiterD * 3462735144109152811U), 29U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterH, 53U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 10U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 51U));
            aIngress = aIngress + (RotL64(aOrbiterG, 41U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + RotL64(aOrbiterJ, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterH, 3U)) + aOrbiterC) + RotL64(aCarry, 35U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 58U) + aOrbiterE) + RotL64(aOrbiterA, 50U));
            aWandererC = aWandererC + ((RotL64(aScatter, 41U) + RotL64(aOrbiterB, 47U)) + aOrbiterA);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 37U) + aOrbiterG) + RotL64(aOrbiterH, 23U));
            aWandererA = aWandererA + ((((RotL64(aScatter, 27U) + RotL64(aOrbiterD, 27U)) + aOrbiterC) + aNonceWordD) + aPhaseFWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterK, 13U)) + aOrbiterJ);
            aWandererI = aWandererI + (((RotL64(aCross, 46U) + RotL64(aOrbiterH, 52U)) + aOrbiterI) + RotL64(aCarry, 11U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 21U) + aOrbiterF) + RotL64(aOrbiterI, 11U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 35U) + aOrbiterJ) + RotL64(aOrbiterI, 29U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterB, 37U)) + aOrbiterF);
            aWandererB = aWandererB + ((((RotL64(aIngress, 13U) + RotL64(aOrbiterG, 19U)) + aOrbiterJ) + aNonceWordE) + aPhaseFWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 60U));
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererJ);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 41U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererF, 27U);
            aCarry = aCarry + RotL64(aIngress, 48U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordF);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10560U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 6241U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 8826U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 8128U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 10U) + RotL64(aPrevious, 57U)) ^ (RotL64(aCross, 27U) + RotL64(aIngress, 41U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 29U)) + 2672739400294801233U) + aNonceWordF;
            aOrbiterF = (((aWandererD + RotL64(aScatter, 26U)) + RotL64(aCarry, 29U)) + 8475624545015101850U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterI = ((aWandererB + RotL64(aIngress, 11U)) + RotL64(aCarry, 51U)) + 1252755112289831257U;
            aOrbiterD = (aWandererK + RotL64(aCross, 13U)) + 7938039507649183387U;
            aOrbiterK = (aWandererH + RotL64(aIngress, 43U)) + 8167413146948861022U;
            aOrbiterG = (aWandererG + RotL64(aScatter, 3U)) + 17712313989694374353U;
            aOrbiterA = (aWandererE + RotL64(aPrevious, 50U)) + 7637042279892596975U;
            aOrbiterJ = ((aWandererA + RotL64(aCross, 39U)) + 15770412950033467341U) + aNonceWordL;
            aOrbiterE = (aWandererC + RotL64(aIngress, 35U)) + 3951812021898608685U;
            aOrbiterB = (aWandererI + RotL64(aScatter, 37U)) + 8656983621098246507U;
            aOrbiterC = (((aWandererF + RotL64(aCross, 57U)) + RotL64(aCarry, 19U)) + 17943342344730687317U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 3087677463651608668U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 16493240011924342788U;
            aOrbiterI = RotL64((aOrbiterI * 16898479041530771871U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 7750923317452683057U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 2185924841611106546U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 708072658250726381U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 14676868738946722416U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 6849098251696302393U;
            aOrbiterK = RotL64((aOrbiterK * 2599806275837778069U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 17817755047153606419U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 9900465270314068757U;
            aOrbiterA = RotL64((aOrbiterA * 9267925873983176685U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 11380000891112113701U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 15930503831156546113U) ^ aNonceWordB;
            aOrbiterE = RotL64((aOrbiterE * 14450535035065393845U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 5439183530402949780U) + aNonceWordN;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 3731802052051181843U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7739775058947333169U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 14432344583247783600U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 16192098795467501636U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6285466374319549047U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 1523272672673940290U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 7462092373525113574U;
            aOrbiterG = RotL64((aOrbiterG * 15067751170235540679U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 4612539457663050732U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 7959404391235752875U;
            aOrbiterJ = RotL64((aOrbiterJ * 137834571274065007U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 11853468935131763944U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 3575434598998149168U) ^ aNonceWordJ;
            aOrbiterB = RotL64((aOrbiterB * 16971321675425065041U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 6135993440654291404U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 2672739400294801233U;
            aOrbiterC = RotL64((aOrbiterC * 12891757276825641567U), 29U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterH, 19U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 39U));
            aIngress = aIngress + (RotL64(aOrbiterC, 47U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterB, 53U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterD, 30U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterF, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterD, 28U)) + aOrbiterF);
            aWandererI = aWandererI + (((RotL64(aIngress, 21U) + aOrbiterG) + RotL64(aOrbiterC, 57U)) + RotL64(aCarry, 5U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 57U) + aOrbiterH) + RotL64(aOrbiterJ, 5U));
            aWandererG = aWandererG + (((RotL64(aCross, 12U) + RotL64(aOrbiterG, 19U)) + aOrbiterI) + RotL64(aCarry, 13U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterC, 3U)) + aOrbiterE);
            aWandererK = aWandererK + ((RotL64(aCross, 51U) + RotL64(aOrbiterE, 11U)) + aOrbiterF);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterG, 53U)) + aOrbiterB) + aNonceWordP);
            aWandererF = aWandererF + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterD, 51U)) + aOrbiterI) + aPhaseFWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 39U) + aOrbiterH) + RotL64(aOrbiterK, 26U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 44U) + RotL64(aOrbiterJ, 35U)) + aOrbiterG);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 3U) + aOrbiterA) + RotL64(aOrbiterD, 13U)) + aNonceWordE);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 21U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 58U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 37U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + RotL64(aWandererF, 10U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ aNonceWordI;
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 12135U)) & S_BLOCK1], 22U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11986U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 14350U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneC[((aIndex + 13291U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 37U) ^ RotL64(aIngress, 21U)) + (RotL64(aPrevious, 50U) + RotL64(aCarry, 5U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterG = (aWandererJ + RotL64(aCross, 6U)) + 13650869943246163567U;
            aOrbiterB = ((aWandererI + RotL64(aScatter, 29U)) + 3435284932011770999U) + aPhaseFOrbiterAssignSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterI = (aWandererB + RotL64(aIngress, 51U)) + 12388155658186776579U;
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 35U)) + RotL64(aCarry, 5U)) + 2374345913955712039U;
            aOrbiterH = ((aWandererG + RotL64(aCross, 57U)) + RotL64(aCarry, 39U)) + 6095094526980292156U;
            aOrbiterC = ((aWandererD + RotL64(aIngress, 3U)) + 4965147025852444174U) + aNonceWordC;
            aOrbiterJ = (aWandererC + RotL64(aScatter, 13U)) + 3261881216269075298U;
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 40U)) + 4939780217097329222U) + aPhaseFOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = ((aWandererH + RotL64(aCross, 53U)) + 3019862009792676287U) + aNonceWordN;
            aOrbiterE = (aWandererE + RotL64(aScatter, 23U)) + 901910626217143974U;
            aOrbiterA = ((aWandererK + RotL64(aIngress, 47U)) + RotL64(aCarry, 13U)) + 3647055146712366383U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 7731765438957392967U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 13409819457393479741U;
            aOrbiterI = RotL64((aOrbiterI * 3345078200262410715U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 5415832109107794258U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 8876738832313114471U;
            aOrbiterC = RotL64((aOrbiterC * 1304277600444504135U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 17135570542519390359U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 2373193062766802082U;
            aOrbiterB = RotL64((aOrbiterB * 4213691513185791519U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 16318403285501718552U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 8456043288604687045U;
            aOrbiterH = RotL64((aOrbiterH * 10556964529144571683U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 10572534930284516528U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterA) ^ 14616251186735204677U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterD = RotL64((aOrbiterD * 2048651204265459805U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 2837006243817205610U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 5315917323622194254U;
            aOrbiterE = RotL64((aOrbiterE * 4080522050089666599U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 12084676282761185907U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 7922080344175593788U;
            aOrbiterG = RotL64((aOrbiterG * 7603522302708937379U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 17620847289789547792U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 12140386059533463650U;
            aOrbiterF = RotL64((aOrbiterF * 1443266480620969535U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 4006608081473218762U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 3152507055132739011U;
            aOrbiterJ = RotL64((aOrbiterJ * 11929522909695002321U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 10845720206369283181U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 16572752872386133133U;
            aOrbiterK = RotL64((aOrbiterK * 2891952650448087211U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 15544908026178481075U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 13650869943246163567U;
            aOrbiterA = RotL64((aOrbiterA * 1275090431127426217U), 11U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterI, 21U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 53U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 19U));
            aIngress = aIngress + (RotL64(aOrbiterC, 13U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterF, 28U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aPrevious, 35U) + aOrbiterC) + RotL64(aOrbiterJ, 35U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterA, 11U)) + aOrbiterG);
            aWandererF = aWandererF + ((RotL64(aIngress, 13U) + aOrbiterH) + RotL64(aOrbiterG, 21U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterB, 23U)) + aOrbiterF) + aNonceWordA);
            aWandererI = aWandererI + ((RotL64(aCross, 26U) + aOrbiterG) + RotL64(aOrbiterB, 27U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 5U) + aOrbiterJ) + RotL64(aOrbiterD, 46U));
            aWandererE = aWandererE + ((RotL64(aIngress, 39U) + aOrbiterK) + RotL64(aOrbiterJ, 37U));
            aWandererD = aWandererD ^ ((((RotL64(aScatter, 43U) + aOrbiterE) + RotL64(aOrbiterA, 39U)) + aNonceWordB) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aIngress, 46U) + RotL64(aOrbiterJ, 51U)) + aOrbiterI) + RotL64(aCarry, 21U)) + aPhaseFWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterC, 3U)) + aOrbiterD) + aNonceWordD);
            aWandererB = aWandererB + (((RotL64(aPrevious, 53U) + aOrbiterK) + RotL64(aOrbiterE, 30U)) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (RotL64(aWandererI, 21U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 4U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 53U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + RotL64(aWandererE, 23U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordN);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 17747U)) & S_BLOCK1], 50U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19150U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21729U)) & S_BLOCK1], 30U) ^ RotL64(aOperationLaneD[((aIndex + 17239U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 20U)) ^ (RotL64(aIngress, 35U) + RotL64(aCross, 53U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 23U)) + RotL64(aCarry, 19U)) + 1557680213571812384U;
            aOrbiterF = (aWandererA + RotL64(aScatter, 34U)) + 7387349725778021121U;
            aOrbiterC = (aWandererG + RotL64(aIngress, 51U)) + 15379264067601586976U;
            aOrbiterE = (aWandererD + RotL64(aCross, 37U)) + 3730195724576043708U;
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 5U)) + 9637070085323827066U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = ((aWandererI + RotL64(aScatter, 57U)) + RotL64(aCarry, 39U)) + 1170865717363676184U;
            aOrbiterK = (aWandererK + RotL64(aCross, 11U)) + 2750833653175252030U;
            aOrbiterD = (aWandererF + RotL64(aIngress, 27U)) + 15118992811225568305U;
            aOrbiterG = ((aWandererJ + RotL64(aCross, 13U)) + RotL64(aCarry, 5U)) + 4974092922102988451U;
            aOrbiterB = ((aWandererH + RotL64(aIngress, 54U)) + 10625719096296719514U) + aPhaseFOrbiterAssignSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 21U)) + 855167122475471865U) + aNonceWordM;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 11322911068958340262U) + aNonceWordH;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 4334591909425429835U;
            aOrbiterC = RotL64((aOrbiterC * 10059025861172038183U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 14263701737208936392U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 678723206735649084U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10823239851733632227U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 15652053114252065230U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 1705225940224061401U;
            aOrbiterA = RotL64((aOrbiterA * 3626023093533713579U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 6826394665732900206U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 11902946775066981141U;
            aOrbiterK = RotL64((aOrbiterK * 18300629262162694137U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 9802212958998591310U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 14001358545610206524U;
            aOrbiterD = RotL64((aOrbiterD * 13172645840788327099U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 4299184726135884309U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 7288757011999872416U;
            aOrbiterG = RotL64((aOrbiterG * 16806027820468277393U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 233801262480580205U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 14208660347238680268U) ^ aNonceWordB;
            aOrbiterB = RotL64((aOrbiterB * 6299693448313154603U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 9217797359740446104U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 18165073197136050838U;
            aOrbiterJ = RotL64((aOrbiterJ * 11677479094709512887U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 9101905235436427482U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 2884224555227870272U;
            aOrbiterI = RotL64((aOrbiterI * 12085235281782370391U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 13118509728421714433U) + aNonceWordD;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 1385390888603164704U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6927424835779289199U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 9621084561183039538U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 1557680213571812384U;
            aOrbiterE = RotL64((aOrbiterE * 3202327770291862207U), 3U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterD, 19U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 39U));
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterF, 34U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 27U));
            aIngress = aIngress + RotL64(aOrbiterA, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 46U) + aOrbiterJ) + RotL64(aOrbiterK, 41U));
            aWandererD = aWandererD + ((RotL64(aIngress, 39U) + RotL64(aOrbiterG, 23U)) + aOrbiterE);
            aWandererG = aWandererG ^ ((RotL64(aCross, 51U) + aOrbiterF) + RotL64(aOrbiterB, 37U));
            aWandererA = aWandererA + (((RotL64(aScatter, 43U) + RotL64(aOrbiterG, 54U)) + aOrbiterI) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterA, 29U)) + aOrbiterI);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 19U) + RotL64(aOrbiterE, 39U)) + aOrbiterD);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterI, 19U)) + aOrbiterH);
            aWandererI = aWandererI + ((((RotL64(aCross, 54U) + RotL64(aOrbiterF, 11U)) + aOrbiterI) + RotL64(aCarry, 3U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterA, 35U)) + aOrbiterF);
            aWandererK = aWandererK + (((RotL64(aScatter, 27U) + RotL64(aOrbiterC, 52U)) + aOrbiterB) + RotL64(aCarry, 29U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterJ, 21U)) + aOrbiterE) + aNonceWordA);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 30U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 21U));
            aCarry = aCarry + RotL64(aWandererD, 53U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = aCarry ^ aNonceWordH;
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 25147U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27189U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25181U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((aIndex + 22942U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCarry, 27U)) + (RotL64(aCross, 39U) ^ RotL64(aPrevious, 14U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterH = ((aWandererC + RotL64(aIngress, 39U)) + 4384716820085860551U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = (aWandererK + RotL64(aPrevious, 5U)) + 9715780315942116888U;
            aOrbiterI = (aWandererF + RotL64(aCross, 18U)) + 15963520052789178632U;
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 11U)) + RotL64(aCarry, 29U)) + 14346700690686392938U;
            aOrbiterJ = ((aWandererG + RotL64(aCross, 41U)) + RotL64(aCarry, 37U)) + 6005518012489966643U;
            aOrbiterD = (aWandererE + RotL64(aScatter, 3U)) + 2506732930310252119U;
            aOrbiterC = (aWandererD + RotL64(aIngress, 37U)) + 16782163084851775826U;
            aOrbiterG = (aWandererI + RotL64(aPrevious, 51U)) + 823673076571076303U;
            aOrbiterE = (((aWandererA + RotL64(aIngress, 30U)) + RotL64(aCarry, 53U)) + 1634084509064077736U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = ((aWandererB + RotL64(aCross, 47U)) + 1288134975466877686U) + aNonceWordK;
            aOrbiterK = (aWandererH + RotL64(aPrevious, 57U)) + 2998220403162908444U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 220430672180734911U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 10223923547068528867U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12577370238343872139U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 11696469696177647608U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 6545430420379636963U;
            aOrbiterD = RotL64((aOrbiterD * 8387163146257553773U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 79691451831797107U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 8971444023498649419U;
            aOrbiterG = RotL64((aOrbiterG * 7148919880477390009U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 5624403902454498793U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 9468064161002030997U;
            aOrbiterA = RotL64((aOrbiterA * 8243560528100864595U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 4619361544913629805U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 12682446273369750704U;
            aOrbiterH = RotL64((aOrbiterH * 10879074713156075641U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 8728730962617599223U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 9099675924074253030U;
            aOrbiterB = RotL64((aOrbiterB * 5525644236954497523U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 3298303921318288541U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 5953276499411658358U;
            aOrbiterC = RotL64((aOrbiterC * 10565471305001292693U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 6725769507592688539U) + aNonceWordB;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 1057277456510215817U;
            aOrbiterE = RotL64((aOrbiterE * 8269412198279297075U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 11317925732206917722U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 17814749417006079067U;
            aOrbiterK = RotL64((aOrbiterK * 4369209051015735925U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 9258362135343403308U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 4873837345446960113U;
            aOrbiterF = RotL64((aOrbiterF * 14223381466269503273U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 7863380865835889675U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 4384716820085860551U;
            aOrbiterJ = RotL64((aOrbiterJ * 2003891033298374621U), 19U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterB, 47U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 51U));
            aIngress = aIngress + (RotL64(aOrbiterD, 24U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 5U));
            aIngress = aIngress + (RotL64(aOrbiterE, 11U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterH, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterH, 51U)) + aOrbiterD);
            aWandererG = aWandererG + (((RotL64(aScatter, 40U) + aOrbiterI) + RotL64(aOrbiterJ, 42U)) + RotL64(aCarry, 29U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 47U) + aOrbiterJ) + RotL64(aOrbiterG, 47U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 57U) + RotL64(aOrbiterI, 37U)) + aOrbiterH) + RotL64(aCarry, 39U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterE, 57U)) + aOrbiterC);
            aWandererF = aWandererF + (((RotL64(aPrevious, 51U) + aOrbiterB) + RotL64(aOrbiterF, 39U)) + aNonceWordA);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 13U) + aOrbiterE) + RotL64(aOrbiterI, 19U));
            aWandererI = aWandererI + (((RotL64(aIngress, 53U) + aOrbiterG) + RotL64(aOrbiterD, 6U)) + aPhaseFWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 60U) + aOrbiterB) + RotL64(aOrbiterD, 13U));
            aWandererK = aWandererK + (((RotL64(aIngress, 3U) + RotL64(aOrbiterK, 21U)) + aOrbiterE) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterA, 27U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + (RotL64(aWandererK, 6U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererC, 27U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 53U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererE, 39U);
            aCarry = aCarry + RotL64(aIngress, 34U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordB);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 29905U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneB[((aIndex + 27790U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27743U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32366U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 35U) ^ RotL64(aCarry, 23U)) + (RotL64(aCross, 10U) + RotL64(aIngress, 53U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterH = (aWandererG + RotL64(aCross, 3U)) + 12980104182836602177U;
            aOrbiterJ = (((aWandererJ + RotL64(aIngress, 5U)) + RotL64(aCarry, 19U)) + 3172622203188863995U) + aNonceWordF;
            aOrbiterI = (aWandererE + RotL64(aScatter, 35U)) + 1170974132219980203U;
            aOrbiterB = (aWandererD + RotL64(aPrevious, 39U)) + 6035201940965047490U;
            aOrbiterG = ((aWandererK + RotL64(aScatter, 37U)) + 18033907118424996722U) + aNonceWordO;
            aOrbiterD = (((aWandererF + RotL64(aPrevious, 27U)) + RotL64(aCarry, 43U)) + 14604813424800580304U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = (aWandererB + RotL64(aIngress, 20U)) + 13720232492851066035U;
            aOrbiterF = ((aWandererI + RotL64(aCross, 29U)) + 3902659710585257448U) + aNonceWordL;
            aOrbiterC = (aWandererA + RotL64(aScatter, 11U)) + 8331560652661619868U;
            aOrbiterK = ((aWandererC + RotL64(aCross, 23U)) + RotL64(aCarry, 27U)) + 4485014147538689794U;
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 18U)) + 168202636924512424U) + aPhaseFOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 16227825670092707848U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 4792781933944671365U;
            aOrbiterI = RotL64((aOrbiterI * 15859849676231455283U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 12636865372722601282U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 18198291399585556632U;
            aOrbiterG = RotL64((aOrbiterG * 18155803890313399795U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 3650053185419807206U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 5897288963905408776U;
            aOrbiterD = RotL64((aOrbiterD * 3706949366974086151U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 9922308113622901726U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 13352279749091561510U;
            aOrbiterE = RotL64((aOrbiterE * 4025213180483632557U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 14969461950939646117U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 10231661776135056651U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11284575051455238501U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 10621934544068320859U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 6029116920305246887U;
            aOrbiterC = RotL64((aOrbiterC * 6087523725059376905U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 12887482425168671195U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 8351351557123783853U;
            aOrbiterK = RotL64((aOrbiterK * 3839381627914762245U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 5405938210926464973U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 385145802287899406U) ^ aNonceWordN;
            aOrbiterA = RotL64((aOrbiterA * 8330751480464271445U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 7907749190875916461U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 5138733192253468642U;
            aOrbiterH = RotL64((aOrbiterH * 17028325976353263843U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 14382272868178763187U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 14354777100157531233U;
            aOrbiterJ = RotL64((aOrbiterJ * 7095764230272037767U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 4390647647193363824U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 12980104182836602177U;
            aOrbiterB = RotL64((aOrbiterB * 11124472075872147333U), 27U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterA, 21U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 11U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 37U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 26U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 51U));
            aIngress = aIngress + RotL64(aOrbiterK, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aPrevious, 14U) + aOrbiterH) + RotL64(aOrbiterA, 37U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterE, 41U)) + aOrbiterC) + aPhaseFWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 51U) + RotL64(aOrbiterD, 47U)) + aOrbiterC) + RotL64(aCarry, 13U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterG, 13U)) + aOrbiterJ);
            aWandererH = aWandererH + ((RotL64(aCross, 5U) + aOrbiterK) + RotL64(aOrbiterI, 39U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterC, 54U)) + aOrbiterF);
            aWandererC = aWandererC + ((RotL64(aScatter, 29U) + aOrbiterE) + RotL64(aOrbiterJ, 21U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 21U) + aOrbiterB) + RotL64(aOrbiterF, 29U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterJ, 11U)) + aOrbiterF);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 46U) + aOrbiterC) + RotL64(aOrbiterH, 19U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 37U) + RotL64(aOrbiterH, 34U)) + aOrbiterI) + RotL64(aCarry, 53U)) + aNonceWordC);
            //
            aCarry = aCarry + (RotL64(aWandererD, 38U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + (RotL64(aWandererI, 53U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 34U));
            aCarry = aCarry + RotL64(aWandererK, 47U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordO);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xDFA6DEEAD41E7235ULL + 0xAFA6D8D9AFF046DAULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xBCCF69F521E3CFDFULL + 0xD29C64381B09A6EEULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xD13BA7F67512628BULL + 0xC34662240C56F62AULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xCF08826B43DAFA01ULL + 0xAF52F028708B0A41ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xD1362BF02657DA07ULL + 0xE035EF1A3CF4568BULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xE8D535FD8BFC5819ULL + 0xC30B828A241F6E7EULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xF713BEB0C5404C6BULL + 0xA6BEC0778CCB5394ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xF8F837AEDFC9F167ULL + 0xEBAF9D0755B6115FULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xC8A531FA1FD58365ULL + 0xCF43631C91E5AC35ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xCAB9088EF366D979ULL + 0x8C95827F85AFC1A5ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xFA66B8FA20407161ULL + 0xAAA448C5C0A03FF9ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xB027BF6249375711ULL + 0xAC88BE7B614521B3ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xBAC5CD4450392805ULL + 0xC76479B81475E788ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xBEDF84389247ED35ULL + 0x88D7C1B12DD8F290ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xBC4F9BC3BEAD59C1ULL + 0xA7499361CB2DE927ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xE20EEE2C42489199ULL + 0xE20FFEB3576117A2ULL);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 5055U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneC[((aIndex + 158U)) & S_BLOCK1], 36U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 1160U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 4603U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 43U) + RotL64(aIngress, 19U)) + (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 6U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterG = ((aWandererC + RotL64(aIngress, 35U)) + RotL64(aCarry, 35U)) + 5295352595333316211U;
            aOrbiterE = (aWandererG + RotL64(aScatter, 29U)) + 2341795367042042605U;
            aOrbiterA = (aWandererF + RotL64(aPrevious, 44U)) + 10122175780504033663U;
            aOrbiterD = ((aWandererA + RotL64(aCross, 39U)) + 10084612804696198554U) + aPhaseFOrbiterAssignSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterH = (((aWandererB + RotL64(aScatter, 3U)) + 16470424309851045971U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordO;
            aOrbiterB = (aWandererI + RotL64(aIngress, 53U)) + 656016130975227994U;
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 14U)) + 15313268829659834317U;
            aOrbiterK = ((aWandererE + RotL64(aCross, 23U)) + RotL64(aCarry, 3U)) + 3795220914993923394U;
            aOrbiterC = (aWandererD + RotL64(aScatter, 51U)) + 14044442220988813825U;
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 11U)) + RotL64(aCarry, 47U)) + 3804224626734584802U;
            aOrbiterF = (aWandererJ + RotL64(aCross, 27U)) + 7980006306010255693U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 13746830564584711549U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 11852212099729274845U) ^ aNonceWordN;
            aOrbiterA = RotL64((aOrbiterA * 2164880979318247855U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 9083223471018084847U) + aNonceWordH;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 13706723820703853346U;
            aOrbiterB = RotL64((aOrbiterB * 11361854103656219887U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 1713819986642275223U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 1382000168233902914U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3894160765130198157U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 4540474625764565485U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 1756168174375757220U;
            aOrbiterD = RotL64((aOrbiterD * 12739160208010092017U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 1409297070183609309U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 6082750101445444357U) ^ aNonceWordB;
            aOrbiterJ = RotL64((aOrbiterJ * 17438740230251860935U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 1113239890859479202U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 10932192439503964363U;
            aOrbiterC = RotL64((aOrbiterC * 5915660289913324281U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 3732595033748508428U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 5117760372351117286U;
            aOrbiterF = RotL64((aOrbiterF * 2671510075176315761U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 7399968659654088641U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 14835608167871904147U;
            aOrbiterE = RotL64((aOrbiterE * 8312521710415756159U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 7851355416751467648U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 262169565276199916U;
            aOrbiterH = RotL64((aOrbiterH * 11801419425408657509U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 1771847554312299305U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 15588805765521695222U;
            aOrbiterK = RotL64((aOrbiterK * 8541206691371972017U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 6162696602553964144U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 5295352595333316211U;
            aOrbiterI = RotL64((aOrbiterI * 8368226841948931873U), 57U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterG, 35U);
            aIngress = aIngress + (RotL64(aOrbiterI, 11U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 60U));
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + RotL64(aOrbiterK, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 56U) + aOrbiterB) + RotL64(aOrbiterH, 53U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterA, 43U)) + aOrbiterK);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterK, 27U)) + aOrbiterB);
            aWandererB = aWandererB + ((((RotL64(aScatter, 13U) + aOrbiterD) + RotL64(aOrbiterK, 50U)) + RotL64(aCarry, 35U)) + aNonceWordK);
            aWandererK = aWandererK ^ ((RotL64(aCross, 39U) + aOrbiterI) + RotL64(aOrbiterB, 35U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterE, 47U)) + aOrbiterC) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 41U) + aOrbiterG) + RotL64(aOrbiterC, 19U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 19U) + aOrbiterK) + RotL64(aOrbiterG, 29U)) + RotL64(aCarry, 53U)) + aPhaseFWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 24U) + aOrbiterJ) + RotL64(aOrbiterC, 10U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 53U) + aOrbiterF) + RotL64(aOrbiterK, 13U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterJ, 5U)) + aOrbiterD) + aNonceWordA);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 58U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererC, 27U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ aNonceWordD;
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 6452U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 6328U)) & S_BLOCK1], 50U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 8694U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 7817U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 38U) + RotL64(aPrevious, 23U)) ^ (RotL64(aIngress, 11U) ^ RotL64(aCross, 51U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterH = (aWandererH + RotL64(aPrevious, 37U)) + 6342299552323486695U;
            aOrbiterC = ((aWandererG + RotL64(aCross, 57U)) + 12692748514781367538U) + aNonceWordE;
            aOrbiterD = (((aWandererJ + RotL64(aIngress, 3U)) + 8202639945493229155U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordI;
            aOrbiterK = (((aWandererC + RotL64(aScatter, 14U)) + RotL64(aCarry, 37U)) + 4439975701793231639U) + aNonceWordK;
            aOrbiterF = (aWandererK + RotL64(aPrevious, 35U)) + 16774235182859553759U;
            aOrbiterB = (aWandererA + RotL64(aIngress, 27U)) + 8764155413335405667U;
            aOrbiterE = (aWandererE + RotL64(aScatter, 11U)) + 7167848811974967685U;
            aOrbiterJ = ((aWandererB + RotL64(aCross, 5U)) + RotL64(aCarry, 13U)) + 16768278912125334220U;
            aOrbiterG = (((aWandererI + RotL64(aPrevious, 18U)) + RotL64(aCarry, 43U)) + 9090838954826296201U) + aPhaseFOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = (aWandererF + RotL64(aIngress, 39U)) + 7644075729758006298U;
            aOrbiterA = (aWandererD + RotL64(aScatter, 51U)) + 17326182797908071215U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 16158809721888137555U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 8029938783858263694U;
            aOrbiterD = RotL64((aOrbiterD * 12628072435324195483U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 8716553521415553404U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 7012599977009208840U) ^ aNonceWordM;
            aOrbiterC = RotL64((aOrbiterC * 8775355876188948851U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 13250558696578541499U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 13705957059101025396U;
            aOrbiterF = RotL64((aOrbiterF * 16889495686487056367U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 2796775206291902461U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 13741676263512390669U;
            aOrbiterE = RotL64((aOrbiterE * 10455782033465595947U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 1691908360612389252U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 4114939415206031540U;
            aOrbiterG = RotL64((aOrbiterG * 2797401802892718297U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 2374911514440738727U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 12377616933668803091U;
            aOrbiterH = RotL64((aOrbiterH * 2505164835116651215U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 681094033415259645U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 13841322124900463362U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4210414203856902329U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 18082983557580381338U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 15731122225678626778U;
            aOrbiterB = RotL64((aOrbiterB * 7785999919955613789U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 2084336993254383330U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 3600882019682875370U;
            aOrbiterJ = RotL64((aOrbiterJ * 2977569829649654329U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 11436602278656592334U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 5775886971784627864U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6765942246225582787U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 17120308925134658794U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 6342299552323486695U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5788669985396507227U), 29U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterK, 51U);
            aIngress = aIngress + (RotL64(aOrbiterG, 58U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterC, 43U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterA, 29U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 41U));
            aIngress = aIngress + RotL64(aOrbiterJ, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterK, 51U)) + aOrbiterH);
            aWandererB = aWandererB + (((RotL64(aIngress, 37U) + aOrbiterA) + RotL64(aOrbiterF, 11U)) + aPhaseFWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 34U) + aOrbiterB) + RotL64(aOrbiterG, 53U)) + aNonceWordC);
            aWandererA = aWandererA + ((RotL64(aScatter, 23U) + RotL64(aOrbiterK, 58U)) + aOrbiterD);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 41U) + aOrbiterG) + RotL64(aOrbiterE, 27U));
            aWandererH = aWandererH + ((((RotL64(aScatter, 51U) + aOrbiterK) + RotL64(aOrbiterA, 3U)) + RotL64(aCarry, 57U)) + aNonceWordB);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterH, 39U)) + aOrbiterI);
            aWandererE = aWandererE + ((RotL64(aCross, 27U) + RotL64(aOrbiterK, 21U)) + aOrbiterC);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterF, 56U)) + aOrbiterE);
            aWandererD = aWandererD + ((((RotL64(aCross, 39U) + aOrbiterA) + RotL64(aOrbiterG, 19U)) + RotL64(aCarry, 37U)) + aPhaseFWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 60U) + aOrbiterJ) + RotL64(aOrbiterF, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 12U) ^ aWandererK);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 51U));
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererE, 5U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererG, 54U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ aNonceWordH;
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 11722U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneA[((aIndex + 14483U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 13154U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 13186U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 35U) ^ RotL64(aCarry, 19U)) + (RotL64(aPrevious, 54U) + RotL64(aCross, 3U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterD = (((aWandererA + RotL64(aIngress, 47U)) + 13880995121909552664U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordE;
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 23U)) + 14534942818069300546U;
            aOrbiterA = (aWandererG + RotL64(aScatter, 37U)) + 17745973100886007133U;
            aOrbiterI = (aWandererD + RotL64(aCross, 18U)) + 2249805580771946872U;
            aOrbiterG = ((aWandererC + RotL64(aScatter, 21U)) + 4460116116396439410U) + aNonceWordD;
            aOrbiterE = ((aWandererH + RotL64(aIngress, 41U)) + 3378683994078106878U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = (aWandererJ + RotL64(aPrevious, 29U)) + 3992996501048809123U;
            aOrbiterK = (aWandererK + RotL64(aCross, 3U)) + 12057768808864451929U;
            aOrbiterB = ((aWandererI + RotL64(aIngress, 35U)) + RotL64(aCarry, 23U)) + 4115362079047921130U;
            aOrbiterF = ((aWandererE + RotL64(aScatter, 14U)) + RotL64(aCarry, 19U)) + 15297384955502206698U;
            aOrbiterH = ((aWandererB + RotL64(aCross, 51U)) + RotL64(aCarry, 11U)) + 17623548383481905636U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 3559213898000162417U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 12311605719074507335U;
            aOrbiterA = RotL64((aOrbiterA * 3982199462062847697U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 14807313864347885885U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 11222085523291581822U;
            aOrbiterE = RotL64((aOrbiterE * 12580941911587215653U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 916681229436292462U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 2441350114032314686U;
            aOrbiterJ = RotL64((aOrbiterJ * 7336079498999018067U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 7361470539894653271U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 12153585147213579808U;
            aOrbiterG = RotL64((aOrbiterG * 3040327545467672961U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 13566300726101613579U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 14875254144748509128U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13699179902908972403U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 9268158535644002904U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 14144295981814993491U;
            aOrbiterF = RotL64((aOrbiterF * 12739937231684038161U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 13861225650900541642U) + aNonceWordC;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 12620513474052058164U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 18141974182442267181U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 14163773386433257965U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 5725700029399455855U;
            aOrbiterI = RotL64((aOrbiterI * 10446930901088908809U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 16644838246877860102U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 6611825438224873117U;
            aOrbiterC = RotL64((aOrbiterC * 5336239588054125897U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 9408958265247071226U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 16980073477599191801U;
            aOrbiterB = RotL64((aOrbiterB * 7985839560318985205U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 6513029242607881518U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 13880995121909552664U;
            aOrbiterH = RotL64((aOrbiterH * 17463079726765044639U), 23U);
            //
            aIngress = RotL64(aOrbiterC, 54U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 19U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 35U));
            aIngress = aIngress + (RotL64(aOrbiterB, 14U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterG, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterB, 56U)) + aOrbiterD);
            aWandererD = aWandererD + ((RotL64(aIngress, 6U) + RotL64(aOrbiterH, 27U)) + aOrbiterK);
            aWandererA = aWandererA ^ ((RotL64(aCross, 47U) + aOrbiterG) + RotL64(aOrbiterA, 29U));
            aWandererB = aWandererB + ((((RotL64(aPrevious, 39U) + aOrbiterK) + RotL64(aOrbiterI, 3U)) + RotL64(aCarry, 3U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterJ, 51U)) + aOrbiterG) + aNonceWordJ);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 37U) + RotL64(aOrbiterE, 47U)) + aOrbiterD);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 10U) + aOrbiterJ) + RotL64(aOrbiterI, 5U)) + aPhaseFWandererUpdateSaltC[((aIndex + 6U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 27U) + aOrbiterF) + RotL64(aOrbiterC, 23U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 53U) + aOrbiterC) + RotL64(aOrbiterI, 36U));
            aWandererG = aWandererG + (((RotL64(aIngress, 29U) + aOrbiterG) + RotL64(aOrbiterD, 11U)) + RotL64(aCarry, 21U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterC, 19U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 14U));
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 21U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 43U));
            aCarry = aCarry + RotL64(aWandererE, 23U);
            aCarry = aCarry + RotL64(aIngress, 58U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordE);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 17534U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneB[((aIndex + 18350U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 17432U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 21179U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 56U) + RotL64(aCarry, 5U)) + (RotL64(aCross, 27U) ^ RotL64(aIngress, 43U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 11U)) + RotL64(aCarry, 35U)) + 6469584119078165548U;
            aOrbiterA = ((aWandererI + RotL64(aCross, 3U)) + 14329756366517987910U) + aPhaseFOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = ((aWandererA + RotL64(aIngress, 54U)) + 12890831797059772123U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = (aWandererH + RotL64(aScatter, 5U)) + 3164503807500018990U;
            aOrbiterJ = ((aWandererK + RotL64(aIngress, 51U)) + RotL64(aCarry, 41U)) + 177531431387646836U;
            aOrbiterK = (aWandererE + RotL64(aCross, 57U)) + 3167421392893561015U;
            aOrbiterE = ((aWandererB + RotL64(aScatter, 29U)) + RotL64(aCarry, 19U)) + 2813174781844753460U;
            aOrbiterI = (aWandererD + RotL64(aPrevious, 27U)) + 10953270419153249857U;
            aOrbiterB = (aWandererJ + RotL64(aCross, 14U)) + 16911518309710356951U;
            aOrbiterG = (aWandererC + RotL64(aScatter, 47U)) + 6616750447844893150U;
            aOrbiterH = ((aWandererF + RotL64(aIngress, 21U)) + 10276741398025985982U) + aNonceWordJ;
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 6206043608461213208U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 12021552904553405793U;
            aOrbiterD = RotL64((aOrbiterD * 10023362889960174909U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 15283586234744144846U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 5923238786775948571U;
            aOrbiterJ = RotL64((aOrbiterJ * 8200882393521882651U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 11044014510971660078U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 9351141024085076044U;
            aOrbiterK = RotL64((aOrbiterK * 13316079344614432317U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 17703395981862992420U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 10154548848376027087U;
            aOrbiterE = RotL64((aOrbiterE * 12324478347590509035U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 8836420852291617425U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 10193385413543886344U;
            aOrbiterI = RotL64((aOrbiterI * 824935982418585449U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 8248580084535685190U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 3910083671888152974U;
            aOrbiterB = RotL64((aOrbiterB * 17825311776715895927U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 12350341628569930642U) + aNonceWordH;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 2565977481575002842U;
            aOrbiterG = RotL64((aOrbiterG * 18233446879833776677U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 9271041067874027417U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 14289254596554201861U;
            aOrbiterH = RotL64((aOrbiterH * 7985522692852251413U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 5981802134118235214U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 14047813418129636856U;
            aOrbiterF = RotL64((aOrbiterF * 15961435325216504877U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 11808443842149398212U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 11380858372643695792U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 100198424024622179U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 10385375464069162356U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 6469584119078165548U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5263876933019848989U), 35U);
            //
            aIngress = RotL64(aOrbiterE, 19U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 40U));
            aIngress = aIngress + (RotL64(aOrbiterB, 53U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 5U));
            aIngress = aIngress + RotL64(aOrbiterC, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aCross, 51U) + RotL64(aOrbiterF, 21U)) + aOrbiterD) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterG, 47U)) + aOrbiterK) + RotL64(aCarry, 39U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 38U) + RotL64(aOrbiterA, 51U)) + aOrbiterB) + aNonceWordA);
            aWandererC = aWandererC + ((RotL64(aScatter, 3U) + aOrbiterF) + RotL64(aOrbiterA, 3U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 41U) + aOrbiterK) + RotL64(aOrbiterJ, 44U));
            aWandererK = aWandererK + (((RotL64(aScatter, 21U) + RotL64(aOrbiterI, 27U)) + aOrbiterH) + RotL64(aCarry, 23U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterF, 39U)) + aOrbiterK);
            aWandererE = aWandererE + (((RotL64(aIngress, 29U) + aOrbiterI) + RotL64(aOrbiterE, 53U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterG, 5U)) + aOrbiterH);
            aWandererD = aWandererD + ((RotL64(aIngress, 27U) + RotL64(aOrbiterF, 10U)) + aOrbiterH);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterI, 35U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 58U));
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 37U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 6U));
            aCarry = aCarry + RotL64(aWandererG, 35U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ aNonceWordH;
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22604U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneA[((aIndex + 25315U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 23716U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25464U)) & S_BLOCK1], 36U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 19U)) + (RotL64(aCross, 35U) ^ RotL64(aIngress, 54U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 26U)) + RotL64(aCarry, 5U)) + 9888431329297626900U;
            aOrbiterH = ((aWandererB + RotL64(aIngress, 37U)) + RotL64(aCarry, 39U)) + 2937735167534624403U;
            aOrbiterD = ((aWandererF + RotL64(aScatter, 43U)) + 17626022970343789617U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterJ = (aWandererD + RotL64(aCross, 51U)) + 5665660859333693743U;
            aOrbiterE = (aWandererG + RotL64(aPrevious, 23U)) + 1060537034632076669U;
            aOrbiterI = (aWandererH + RotL64(aIngress, 21U)) + 743777763907175800U;
            aOrbiterB = (aWandererI + RotL64(aCross, 13U)) + 5744905970181808845U;
            aOrbiterK = (aWandererJ + RotL64(aScatter, 46U)) + 3545351394494002180U;
            aOrbiterF = ((((aWandererA + RotL64(aCross, 5U)) + RotL64(aCarry, 47U)) + 4877547088414106007U) + aPhaseFOrbiterAssignSaltB[((aIndex + 10U)) & S_SALT1]) + aNonceWordP;
            aOrbiterA = (aWandererC + RotL64(aIngress, 41U)) + 11669378338379598445U;
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 11U)) + 2961072441706158212U) + aNonceWordL;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 13984945589234919765U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 1433097875470903205U;
            aOrbiterD = RotL64((aOrbiterD * 451996840039906781U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 716415411025451152U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 8542286150858297810U;
            aOrbiterI = RotL64((aOrbiterI * 9139015340823332449U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 12932391786479661299U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 14005503313299177013U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 802663466907819743U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 9382792812676318046U) + aNonceWordC;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 5138554251079724724U;
            aOrbiterA = RotL64((aOrbiterA * 6386016499265056247U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 8522380066269546172U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 11825536408101906458U;
            aOrbiterG = RotL64((aOrbiterG * 17042837108792016849U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 15504062350899452495U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 1219010998820336744U;
            aOrbiterJ = RotL64((aOrbiterJ * 10650635772711590803U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 6442717843380349632U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 1047843426279085117U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4074561571072878005U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 10611039527108679173U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 5092816736177358221U;
            aOrbiterF = RotL64((aOrbiterF * 14342779343820140833U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 12327496881352988530U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 6405703847824845457U) ^ aNonceWordK;
            aOrbiterC = RotL64((aOrbiterC * 12094143526751620113U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 8906613392335197542U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 5962698890029858689U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9136193803330500489U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 2610083915800734277U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 9888431329297626900U;
            aOrbiterE = RotL64((aOrbiterE * 3794133356691218671U), 19U);
            //
            aIngress = RotL64(aOrbiterE, 37U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterD, 51U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterI, 46U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 19U));
            aIngress = aIngress + (RotL64(aOrbiterG, 53U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterJ, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aCross, 39U) + aOrbiterK) + RotL64(aOrbiterJ, 24U)) + aNonceWordM);
            aWandererA = aWandererA + ((RotL64(aScatter, 30U) + aOrbiterI) + RotL64(aOrbiterB, 29U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 19U) + aOrbiterF) + RotL64(aOrbiterH, 51U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 37U) + aOrbiterK) + RotL64(aOrbiterB, 57U)) + RotL64(aCarry, 19U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 27U) + aOrbiterE) + RotL64(aOrbiterB, 41U));
            aWandererE = aWandererE + ((RotL64(aCross, 11U) + aOrbiterH) + RotL64(aOrbiterK, 18U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 47U) + aOrbiterC) + RotL64(aOrbiterG, 37U)) + aNonceWordA);
            aWandererH = aWandererH + (((RotL64(aScatter, 4U) + RotL64(aOrbiterC, 53U)) + aOrbiterK) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((((RotL64(aCross, 51U) + aOrbiterG) + RotL64(aOrbiterD, 27U)) + aNonceWordH) + aPhaseFWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 41U) + RotL64(aOrbiterD, 11U)) + aOrbiterA) + RotL64(aCarry, 51U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 23U) + aOrbiterD) + RotL64(aOrbiterJ, 43U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 53U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 20U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererF, 24U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordG);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 30654U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneB[((aIndex + 32316U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31482U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32588U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aIngress, 41U)) + (RotL64(aCross, 57U) ^ RotL64(aPrevious, 28U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterK = (aWandererD + RotL64(aPrevious, 56U)) + 1297415699043177788U;
            aOrbiterD = ((aWandererJ + RotL64(aIngress, 47U)) + 17583786534509260153U) + aNonceWordN;
            aOrbiterE = (((aWandererG + RotL64(aScatter, 5U)) + RotL64(aCarry, 13U)) + 643197858925708798U) + aPhaseFOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = (aWandererB + RotL64(aCross, 11U)) + 5062653766915694874U;
            aOrbiterG = (aWandererA + RotL64(aPrevious, 58U)) + 7034273638367180511U;
            aOrbiterB = (aWandererH + RotL64(aScatter, 27U)) + 2026909726972916996U;
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 51U)) + 2785690475553211646U) + aNonceWordF;
            aOrbiterI = ((aWandererI + RotL64(aCross, 21U)) + RotL64(aCarry, 27U)) + 2910341716302991892U;
            aOrbiterA = ((aWandererK + RotL64(aIngress, 41U)) + 2834181605200829791U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterC = (aWandererC + RotL64(aCross, 43U)) + 13323052600571281928U;
            aOrbiterH = (((aWandererE + RotL64(aPrevious, 39U)) + RotL64(aCarry, 47U)) + 10434901530315760460U) + aNonceWordE;
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 247903955625194782U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 5196515747387257163U;
            aOrbiterE = RotL64((aOrbiterE * 1799024689023272275U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 7196305682377987476U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 14777739876892587484U;
            aOrbiterG = RotL64((aOrbiterG * 95220583948241581U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 10609060796540136671U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 8386027207212484155U;
            aOrbiterB = RotL64((aOrbiterB * 4855610536246556893U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 729659744301903424U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 2350564261412606157U;
            aOrbiterJ = RotL64((aOrbiterJ * 16713856782349084977U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 16611987556673864177U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 1525195188708550503U;
            aOrbiterI = RotL64((aOrbiterI * 10045858602151004553U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 4654808490980989596U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 8189569777087686263U;
            aOrbiterA = RotL64((aOrbiterA * 17278657566389299577U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 10932857495004451792U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 1833880112534916813U;
            aOrbiterC = RotL64((aOrbiterC * 8004341577533825681U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 13100236350175516423U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = (((aOrbiterH ^ aOrbiterI) ^ 2773759534195186313U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterH = RotL64((aOrbiterH * 3194954066097323161U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 13963126688973399221U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 1464529855671190406U;
            aOrbiterK = RotL64((aOrbiterK * 6129954747502059213U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 9489842625026216815U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 17806120432918490594U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 349307975773661379U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 13833297268854563081U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 1297415699043177788U;
            aOrbiterF = RotL64((aOrbiterF * 4818542043777342249U), 19U);
            //
            aIngress = RotL64(aOrbiterC, 23U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 27U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 11U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 51U));
            aIngress = aIngress + (RotL64(aOrbiterA, 42U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterI, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aScatter, 51U) + aOrbiterC) + RotL64(aOrbiterD, 29U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 18U) + RotL64(aOrbiterE, 37U)) + aOrbiterH);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterI, 50U)) + aOrbiterD);
            aWandererF = aWandererF + ((RotL64(aCross, 11U) + aOrbiterI) + RotL64(aOrbiterE, 43U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 47U) + aOrbiterA) + RotL64(aOrbiterB, 23U));
            aWandererI = aWandererI + (((RotL64(aIngress, 26U) + RotL64(aOrbiterC, 3U)) + aOrbiterF) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ ((((RotL64(aCross, 53U) + aOrbiterD) + RotL64(aOrbiterK, 13U)) + aNonceWordI) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 23U) + RotL64(aOrbiterE, 41U)) + aOrbiterJ) + aNonceWordM);
            aWandererD = aWandererD ^ ((RotL64(aCross, 35U) + aOrbiterG) + RotL64(aOrbiterC, 54U));
            aWandererA = aWandererA + ((((RotL64(aScatter, 39U) + aOrbiterA) + RotL64(aOrbiterC, 39U)) + RotL64(aCarry, 29U)) + aNonceWordB);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterE, 21U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + (RotL64(aWandererH, 20U) ^ aWandererC);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 53U));
            aCarry = aCarry + (RotL64(aWandererI, 5U) ^ aWandererA);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + RotL64(aWandererB, 48U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ aNonceWordN;
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
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 2456U)) & S_BLOCK1], 30U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 2416U)) & W_KEY1], 3U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 303U)) & W_KEY1], 11U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 8152U)) & S_BLOCK1], 46U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 21U) ^ RotL64(aIngress, 3U)) + (RotL64(aPrevious, 35U) ^ RotL64(aCross, 50U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = (aWandererI + RotL64(aPrevious, 11U)) + 12136097566601676613U;
            aOrbiterA = (aWandererH + RotL64(aScatter, 37U)) + 7969431322248040056U;
            aOrbiterG = ((aWandererC + RotL64(aCross, 23U)) + RotL64(aCarry, 53U)) + 10530676021510553889U;
            aOrbiterC = (((aWandererJ + RotL64(aIngress, 47U)) + RotL64(aCarry, 37U)) + 8740777303075445264U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterK = (aWandererD + RotL64(aPrevious, 4U)) + 13249434169895564739U;
            aOrbiterJ = (aWandererA + RotL64(aCross, 19U)) + 15529577005925628472U;
            aOrbiterI = ((aWandererE + RotL64(aIngress, 51U)) + 344627093687331562U) + aPhaseCOrbiterAssignSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterF = ((aWandererK + RotL64(aScatter, 27U)) + RotL64(aCarry, 11U)) + 8824277416519988893U;
            aOrbiterD = (aWandererF + RotL64(aIngress, 42U)) + 5636276438449709875U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 2079413361031851552U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 7807998179168655561U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 961456853699784753U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 13589392896232029112U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 10733011474804473996U;
            aOrbiterJ = RotL64((aOrbiterJ * 361749145931578805U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 15934162328347805968U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 7573511217796245232U;
            aOrbiterF = RotL64((aOrbiterF * 10694563909931636155U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 4828475187337891975U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 13284974329890393113U;
            aOrbiterD = RotL64((aOrbiterD * 10831075817642374287U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 13173869918669643112U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 15841507674783398167U;
            aOrbiterE = RotL64((aOrbiterE * 15632933198136963277U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 14168272451055700516U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 11134471485501999898U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8019507184494591705U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 2611858916687822610U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 17863271539727513641U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4987884722174985677U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 8874401993454249066U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 5131480593493950665U;
            aOrbiterA = RotL64((aOrbiterA * 8585874663602346121U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 9366563022381918996U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 7890729519928340296U;
            aOrbiterK = RotL64((aOrbiterK * 11428572374057899517U), 3U);
            //
            aIngress = RotL64(aOrbiterI, 47U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterA, 11U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterG, 43U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterD, 60U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterJ, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aPrevious, 46U) + aOrbiterF) + RotL64(aOrbiterE, 34U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterJ, 19U)) + aOrbiterA);
            aWandererK = aWandererK + ((RotL64(aIngress, 23U) + RotL64(aOrbiterG, 53U)) + aOrbiterI);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterG, 47U)) + aOrbiterC);
            aWandererE = aWandererE + ((((RotL64(aCross, 18U) + aOrbiterE) + RotL64(aOrbiterD, 58U)) + RotL64(aCarry, 5U)) + aPhaseCWandererUpdateSaltF[((aIndex + 4U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 41U) + aOrbiterE) + RotL64(aOrbiterK, 11U));
            aWandererF = aWandererF + (((RotL64(aIngress, 5U) + RotL64(aOrbiterJ, 3U)) + aOrbiterI) + RotL64(aCarry, 37U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 51U) + aOrbiterE) + RotL64(aOrbiterI, 43U)) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 13U) + aOrbiterK) + RotL64(aOrbiterG, 27U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 41U));
            aCarry = aCarry + (RotL64(aWandererJ, 37U) ^ aWandererF);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 18U));
            aCarry = aCarry + (RotL64(aWandererC, 21U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererI, 51U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 10340U)) & S_BLOCK1], 21U) ^ RotL64(mSource[((aIndex + 13411U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 11583U)) & W_KEY1], 48U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 9181U)) & W_KEY1], 13U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 27U) + RotL64(aCarry, 56U)) ^ (RotL64(aCross, 11U) + RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = (aWandererC + RotL64(aIngress, 6U)) + 18144572925667544139U;
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 35U)) + RotL64(aCarry, 51U)) + 5659758077574059728U;
            aOrbiterI = (((aWandererK + RotL64(aCross, 29U)) + RotL64(aCarry, 35U)) + 6343330616999166392U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = (aWandererE + RotL64(aScatter, 53U)) + 17754639838410839447U;
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 47U)) + 9451843819849581729U) + aPhaseCOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 23U)) + RotL64(aCarry, 5U)) + 7957854457197462212U;
            aOrbiterH = (aWandererH + RotL64(aCross, 41U)) + 1461994799722205010U;
            aOrbiterD = (aWandererB + RotL64(aScatter, 10U)) + 18002214276252170177U;
            aOrbiterB = (aWandererD + RotL64(aCross, 19U)) + 14689869073147027164U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 3978104368003440293U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 8512135845221335386U;
            aOrbiterI = RotL64((aOrbiterI * 10506667163729414667U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 1477533446382953439U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 2166717790929947990U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6538884492418324461U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 8082437060686606995U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 4363687722464700362U;
            aOrbiterH = RotL64((aOrbiterH * 7199165810993478887U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 15782763348014924206U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 8572509150015960728U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3340528604891897779U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 12248271773316742521U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 9602078627638561949U;
            aOrbiterB = RotL64((aOrbiterB * 1860631869877427405U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 17244849374768558859U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 1030743048280579012U;
            aOrbiterJ = RotL64((aOrbiterJ * 10858949914285817051U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 17722342363541914280U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 15667504059789880034U;
            aOrbiterC = RotL64((aOrbiterC * 15872269872168533709U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 12645332941998550794U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 9938135244509986497U;
            aOrbiterE = RotL64((aOrbiterE * 16548185968987392957U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 4024609904162105979U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 6732064218696157303U;
            aOrbiterG = RotL64((aOrbiterG * 3815409766145891393U), 5U);
            //
            aIngress = RotL64(aOrbiterB, 35U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 19U));
            aIngress = aIngress + RotL64(aOrbiterA, 44U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aCross, 57U) + RotL64(aOrbiterG, 41U)) + aOrbiterB);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 14U) + RotL64(aOrbiterI, 53U)) + aOrbiterC) + aPhaseCWandererUpdateSaltB[((aIndex + 16U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 19U) + RotL64(aOrbiterA, 60U)) + aOrbiterE) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterD, 23U)) + aOrbiterH);
            aWandererK = aWandererK + (((RotL64(aIngress, 47U) + aOrbiterA) + RotL64(aOrbiterG, 35U)) + RotL64(aCarry, 57U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterH, 47U)) + aOrbiterJ);
            aWandererB = aWandererB + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterG, 4U)) + aOrbiterC);
            aWandererE = aWandererE ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterJ, 29U)) + aOrbiterD);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 28U) + RotL64(aOrbiterB, 19U)) + aOrbiterH) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + (RotL64(aWandererK, 37U) ^ aWandererH);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererA, 48U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 23033U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 21087U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 17790U)) & W_KEY1], 6U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 23898U)) & W_KEY1], 19U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aIngress, 19U)) + (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 54U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 35U)) + RotL64(aCarry, 43U)) + 8506388683755208267U;
            aOrbiterH = ((aWandererB + RotL64(aCross, 30U)) + RotL64(aCarry, 13U)) + 2179323259055019735U;
            aOrbiterK = (aWandererF + RotL64(aPrevious, 41U)) + 3345902531140983016U;
            aOrbiterD = ((aWandererD + RotL64(aIngress, 13U)) + 17456139311481306584U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = (aWandererC + RotL64(aCross, 5U)) + 14587864088462311164U;
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 51U)) + 13178947246650647057U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = ((aWandererK + RotL64(aIngress, 47U)) + RotL64(aCarry, 27U)) + 12866578138946916962U;
            aOrbiterE = (aWandererG + RotL64(aScatter, 56U)) + 13098524333655118173U;
            aOrbiterF = (aWandererI + RotL64(aCross, 21U)) + 15451329483787541982U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 9494299579678389385U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 15581954810375490643U;
            aOrbiterK = RotL64((aOrbiterK * 13670002280188424825U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 4487042505730624892U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 2774455928791636186U;
            aOrbiterG = RotL64((aOrbiterG * 15847933919136777451U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 12435319582397755819U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 10077180055177766823U;
            aOrbiterD = RotL64((aOrbiterD * 3924363471701748703U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 10391963896910956455U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 6149237416725301794U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10115917698918612823U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 15673402771629639978U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 14729117178956592426U;
            aOrbiterB = RotL64((aOrbiterB * 9070464269215820531U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 14492001279368870240U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 6278248084483259952U;
            aOrbiterC = RotL64((aOrbiterC * 16731228350971263873U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 15727518866499740411U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 8652631010810965473U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9508484121620912715U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 13660890300188313775U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 14699253534935936300U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3978135617259934869U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 1621689916308271346U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 5651399428852950385U;
            aOrbiterF = RotL64((aOrbiterF * 12220143634120124133U), 43U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterH, 51U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 46U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 21U));
            aIngress = aIngress + (RotL64(aOrbiterF, 35U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterA, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aCross, 41U) + aOrbiterA) + RotL64(aOrbiterC, 11U)) + RotL64(aCarry, 13U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterF, 43U)) + aOrbiterC);
            aWandererF = aWandererF + (((RotL64(aIngress, 46U) + RotL64(aOrbiterB, 34U)) + aOrbiterC) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterH, 23U)) + aOrbiterC) + aPhaseCWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aScatter, 57U) + RotL64(aOrbiterG, 5U)) + aOrbiterK);
            aWandererG = aWandererG ^ ((RotL64(aCross, 29U) + aOrbiterG) + RotL64(aOrbiterF, 27U));
            aWandererD = aWandererD + (((RotL64(aIngress, 14U) + RotL64(aOrbiterE, 47U)) + aOrbiterA) + RotL64(aCarry, 27U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 19U) + aOrbiterF) + RotL64(aOrbiterD, 54U));
            aWandererI = aWandererI + ((RotL64(aIngress, 51U) + aOrbiterH) + RotL64(aOrbiterG, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererH);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 34U));
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererC, 23U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 26483U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneB[((aIndex + 28463U)) & S_BLOCK1], 10U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30955U)) & S_BLOCK1], 21U) ^ RotL64(mSource[((aIndex + 30304U)) & S_BLOCK1], 10U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aIngress, 21U)) + (RotL64(aCarry, 36U) ^ RotL64(aPrevious, 51U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = (aWandererB + RotL64(aCross, 5U)) + 8101351470141807662U;
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 34U)) + 6965474099521076705U;
            aOrbiterG = (aWandererJ + RotL64(aScatter, 21U)) + 6803828268885684784U;
            aOrbiterC = ((aWandererD + RotL64(aIngress, 11U)) + RotL64(aCarry, 21U)) + 13454235922950972488U;
            aOrbiterK = (((aWandererA + RotL64(aScatter, 51U)) + RotL64(aCarry, 29U)) + 11678091885751244777U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = (aWandererH + RotL64(aCross, 57U)) + 5307134544628507141U;
            aOrbiterI = (aWandererI + RotL64(aIngress, 26U)) + 4873703518950429353U;
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 39U)) + RotL64(aCarry, 47U)) + 8542156221858586039U;
            aOrbiterB = ((aWandererE + RotL64(aIngress, 47U)) + 3993726182905296513U) + aPhaseCOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 12113047622035464386U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 1944244448665721151U;
            aOrbiterG = RotL64((aOrbiterG * 7010050836758762003U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 12914188029425467576U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 2486762763475327024U;
            aOrbiterK = RotL64((aOrbiterK * 12319769994433811617U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 14580191602982245481U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 12093414832400135066U;
            aOrbiterI = RotL64((aOrbiterI * 12720286833215690663U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 13623906997320021065U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 9977356009806428696U;
            aOrbiterE = RotL64((aOrbiterE * 2005536391712733499U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 3694954095397810851U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 11453812627797091638U;
            aOrbiterC = RotL64((aOrbiterC * 13730420725113907161U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 542311345544726351U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 3024285045990499484U;
            aOrbiterD = RotL64((aOrbiterD * 5153745952148205645U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 15397664082460849530U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 10716856680110815056U;
            aOrbiterH = RotL64((aOrbiterH * 13947203772929252823U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 833342121331428547U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 1111339940097269219U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17991642769781175473U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 9312963978841402871U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 8225496710723213204U;
            aOrbiterJ = RotL64((aOrbiterJ * 894499195498817065U), 35U);
            //
            aIngress = RotL64(aOrbiterI, 35U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 26U));
            aIngress = aIngress + (RotL64(aOrbiterC, 43U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterG, 39U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterJ, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 4U) + RotL64(aOrbiterC, 23U)) + aOrbiterJ);
            aWandererG = aWandererG + (((RotL64(aCross, 47U) + aOrbiterG) + RotL64(aOrbiterJ, 18U)) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 57U) + aOrbiterC) + RotL64(aOrbiterB, 47U));
            aWandererA = aWandererA + (((RotL64(aIngress, 11U) + RotL64(aOrbiterG, 29U)) + aOrbiterE) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterH, 43U)) + aOrbiterE);
            aWandererC = aWandererC + (((RotL64(aIngress, 39U) + RotL64(aOrbiterK, 35U)) + aOrbiterG) + RotL64(aCarry, 11U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 19U) + aOrbiterC) + RotL64(aOrbiterD, 60U));
            aWandererD = aWandererD + (((RotL64(aScatter, 43U) + RotL64(aOrbiterH, 53U)) + aOrbiterG) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 52U) + RotL64(aOrbiterI, 5U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + (RotL64(aWandererH, 6U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererI, 51U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 8188U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1281U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 6082U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 7148U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 29U) ^ RotL64(aIngress, 57U)) + (RotL64(aCross, 5U) + RotL64(aPrevious, 44U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = ((aWandererG + RotL64(aScatter, 47U)) + 12027839670755583592U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = (aWandererC + RotL64(aPrevious, 21U)) + 15380130703509859843U;
            aOrbiterA = (((aWandererD + RotL64(aCross, 3U)) + RotL64(aCarry, 41U)) + 4590907433867798074U) + aPhaseDOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = ((aWandererI + RotL64(aIngress, 11U)) + RotL64(aCarry, 53U)) + 1754574023602519724U;
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 56U)) + RotL64(aCarry, 11U)) + 9832756659564903767U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 5035088494491470403U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 14199170923323644638U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4518257134117207121U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 8325619421264440438U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 969534320779067977U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17767548306355264705U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 270575869402913847U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 13344806516599578910U;
            aOrbiterC = RotL64((aOrbiterC * 10193544126281901579U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 15143147951139409101U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 14425582489214169238U;
            aOrbiterG = RotL64((aOrbiterG * 16893787086337916355U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 13951127523239064584U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 14177925225918293579U;
            aOrbiterE = RotL64((aOrbiterE * 13079514031864998485U), 3U);
            //
            aIngress = RotL64(aOrbiterG, 29U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterD, 53U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterC, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aPrevious, 37U) + aOrbiterD) + RotL64(aOrbiterE, 27U)) + RotL64(aCarry, 35U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 5U) + aOrbiterC) + RotL64(aOrbiterD, 19U));
            aWandererK = aWandererK + (((RotL64(aCross, 54U) + aOrbiterG) + RotL64(aOrbiterC, 35U)) + RotL64(aCarry, 51U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 13U) + aOrbiterC) + RotL64(aOrbiterA, 5U)) + aPhaseDWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 23U) + RotL64(aOrbiterA, 52U)) + aOrbiterE) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererK);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + RotL64(aWandererC, 19U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 10979U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 12556U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 14489U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneB[((aIndex + 15464U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 6U) + RotL64(aCross, 57U)) ^ (RotL64(aPrevious, 19U) + RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 57U)) + RotL64(aCarry, 51U)) + 2617613537256538553U;
            aOrbiterA = (((aWandererA + RotL64(aCross, 47U)) + RotL64(aCarry, 5U)) + 16642868916835132715U) + aPhaseDOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = (aWandererJ + RotL64(aScatter, 34U)) + 10860291124337073254U;
            aOrbiterH = ((aWandererC + RotL64(aIngress, 11U)) + RotL64(aCarry, 21U)) + 6432511273906902472U;
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 23U)) + 7505375005848241910U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 11086616004678821329U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 3298830587569881951U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4304047944073454489U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 9775143140064220979U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 4147601326580823120U;
            aOrbiterJ = RotL64((aOrbiterJ * 13462244678782260871U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 12245920269898100415U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 8391940489176734499U;
            aOrbiterB = RotL64((aOrbiterB * 9119606167674098007U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 17876893379544668477U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 18301882058180370541U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16680384667098921309U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 6869225862715140102U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 15404118372589259800U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5766851935950389915U), 53U);
            //
            aIngress = RotL64(aOrbiterA, 57U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + RotL64(aOrbiterH, 38U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterB, 37U)) + aOrbiterH) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 40U) + RotL64(aOrbiterH, 19U)) + aOrbiterC);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 53U) + aOrbiterB) + RotL64(aOrbiterJ, 48U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 29U) + aOrbiterA) + RotL64(aOrbiterB, 3U)) + aPhaseDWandererUpdateSaltF[((aIndex + 16U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aIngress, 19U) + RotL64(aOrbiterC, 27U)) + aOrbiterB) + RotL64(aCarry, 43U)) + aPhaseDWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 54U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 41U));
            aCarry = aCarry + RotL64(aWandererA, 3U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 17467U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((aIndex + 23811U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 24416U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneC[((aIndex + 19334U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCarry, 27U)) + (RotL64(aPrevious, 14U) + RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = (aWandererC + RotL64(aCross, 57U)) + 439898681482066326U;
            aOrbiterE = (((aWandererH + RotL64(aScatter, 21U)) + RotL64(aCarry, 29U)) + 17362083676671776094U) + aPhaseDOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = (((aWandererE + RotL64(aIngress, 3U)) + RotL64(aCarry, 47U)) + 6418499837265155024U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 37U)) + RotL64(aCarry, 11U)) + 17262244253027454972U;
            aOrbiterK = (aWandererG + RotL64(aScatter, 12U)) + 2382066162993139503U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 14345808395587174135U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 7534743166385552851U;
            aOrbiterJ = RotL64((aOrbiterJ * 9475127126941982125U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 16994453324688523966U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 7079553728544045092U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10104892188895367489U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 3562822704508440641U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 13990892681975857821U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8352929306654078795U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 1796728922368577238U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 6605161260520067178U;
            aOrbiterG = RotL64((aOrbiterG * 8147537646591674091U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 13994083795942328918U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 6144523182899107711U;
            aOrbiterK = RotL64((aOrbiterK * 4153879991344611283U), 19U);
            //
            aIngress = RotL64(aOrbiterE, 29U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 19U));
            aIngress = aIngress + RotL64(aOrbiterG, 58U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aIngress, 13U) + RotL64(aOrbiterG, 58U)) + aOrbiterK) + RotL64(aCarry, 41U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 39U) + aOrbiterE) + RotL64(aOrbiterJ, 3U));
            aWandererH = aWandererH + ((((RotL64(aScatter, 30U) + aOrbiterG) + RotL64(aOrbiterA, 21U)) + RotL64(aCarry, 57U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterA, 47U)) + aOrbiterE);
            aWandererF = aWandererF + (((RotL64(aScatter, 5U) + aOrbiterJ) + RotL64(aOrbiterK, 13U)) + aPhaseDWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 11U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 25759U)) & S_BLOCK1], 22U) ^ RotL64(aOperationLaneB[((aIndex + 27535U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 31503U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((aIndex + 24945U)) & S_BLOCK1], 50U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCarry, 35U)) ^ (RotL64(aPrevious, 48U) + RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = ((aWandererK + RotL64(aCross, 11U)) + 13296600294247799698U) + aPhaseDOrbiterAssignSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = ((aWandererE + RotL64(aScatter, 3U)) + RotL64(aCarry, 11U)) + 5818503518080877515U;
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 41U)) + RotL64(aCarry, 53U)) + 6735784238734173597U;
            aOrbiterH = ((aWandererG + RotL64(aIngress, 57U)) + RotL64(aCarry, 39U)) + 7368398209488856201U;
            aOrbiterD = ((aWandererF + RotL64(aCross, 22U)) + 961734029066455638U) + aPhaseDOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 797011946660892011U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 12841876018396622350U;
            aOrbiterK = RotL64((aOrbiterK * 14056540056414153277U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 16213253970483895623U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 15186950557113470375U;
            aOrbiterF = RotL64((aOrbiterF * 4647470430467908107U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 5117930310827477341U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 12265429373166094162U;
            aOrbiterH = RotL64((aOrbiterH * 1522823535151532249U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 13920531346698601568U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 14695405206998211456U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13950964363414164279U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 7851960904825938443U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 9501511171732550190U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5614164120361489613U), 5U);
            //
            aIngress = RotL64(aOrbiterH, 37U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterA, 24U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterK, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aPrevious, 43U) + aOrbiterH) + RotL64(aOrbiterK, 53U)) + RotL64(aCarry, 43U)) + aPhaseDWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 56U) + aOrbiterF) + RotL64(aOrbiterH, 35U));
            aWandererF = aWandererF + (((RotL64(aCross, 3U) + RotL64(aOrbiterD, 27U)) + aOrbiterF) + RotL64(aCarry, 57U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterA, 18U)) + aOrbiterF) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aCross, 35U) + RotL64(aOrbiterA, 5U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererK);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 58U));
            aCarry = aCarry + RotL64(aWandererF, 47U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 1430U)) & S_BLOCK1], 46U) ^ RotL64(aOperationLaneC[((aIndex + 3728U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 835U)) & S_BLOCK1], 42U) ^ RotL64(aOperationLaneA[((aIndex + 1240U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 11U) + RotL64(aCarry, 27U)) ^ (RotL64(aIngress, 56U) ^ RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = (((aWandererK + RotL64(aScatter, 19U)) + RotL64(aCarry, 57U)) + 10915618884692072446U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterC = ((aWandererI + RotL64(aIngress, 51U)) + RotL64(aCarry, 27U)) + 12634922308499254909U;
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 57U)) + 6533934734564499389U) + aPhaseEOrbiterAssignSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = (aWandererE + RotL64(aCross, 27U)) + 6744203303756105181U;
            aOrbiterJ = (aWandererA + RotL64(aIngress, 40U)) + 13086782386652045658U;
            aOrbiterF = (aWandererF + RotL64(aCross, 13U)) + 5693840533331397822U;
            aOrbiterI = ((aWandererD + RotL64(aPrevious, 5U)) + RotL64(aCarry, 41U)) + 1803663542535024611U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 3597219300593287708U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 1429753448204448904U;
            aOrbiterH = RotL64((aOrbiterH * 10927459251773273143U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 17229017825587322715U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 1137574712801062932U;
            aOrbiterJ = RotL64((aOrbiterJ * 3645832160939819415U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 2401991077004083378U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 1332473247826139292U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15029831858261506447U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 11730946340796899885U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 15319163439700390962U;
            aOrbiterI = RotL64((aOrbiterI * 1349242001887975499U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 4744141870145159917U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 6067132201862688684U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6046100687757836027U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 14991509179286371800U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 4342608825699398682U;
            aOrbiterE = RotL64((aOrbiterE * 10240526103933275875U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 3727521409410742075U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 3302027219498304367U;
            aOrbiterC = RotL64((aOrbiterC * 12153634588200479559U), 3U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterF, 43U);
            aIngress = aIngress + (RotL64(aOrbiterC, 13U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterJ, 37U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterI, 56U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterF, 47U)) + aOrbiterE);
            aWandererC = aWandererC + ((RotL64(aCross, 39U) + aOrbiterC) + RotL64(aOrbiterF, 3U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 47U) + aOrbiterH) + RotL64(aOrbiterB, 29U));
            aWandererI = aWandererI + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterI, 11U)) + aOrbiterB) + RotL64(aCarry, 29U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterJ, 54U)) + aOrbiterE);
            aWandererK = aWandererK + (((RotL64(aScatter, 19U) + aOrbiterF) + RotL64(aOrbiterB, 23U)) + RotL64(aCarry, 43U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 56U) + aOrbiterH) + RotL64(aOrbiterI, 39U)) + aPhaseEWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 43U));
            aCarry = aCarry + (RotL64(aWandererF, 18U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererC, 37U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererK, 3U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9750U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneD[((aIndex + 12219U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 14844U)) & S_BLOCK1], 42U) ^ RotL64(aOperationLaneB[((aIndex + 12504U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 21U) + RotL64(aCarry, 40U)) + (RotL64(aCross, 53U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 60U)) + RotL64(aCarry, 35U)) + 6163290588946759209U;
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 11U)) + 7342672468560105447U) + aPhaseEOrbiterAssignSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = (aWandererA + RotL64(aCross, 29U)) + 11574563167017282321U;
            aOrbiterG = (aWandererI + RotL64(aScatter, 35U)) + 2254820206194758964U;
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 51U)) + RotL64(aCarry, 23U)) + 1469783447473099498U;
            aOrbiterF = (((aWandererF + RotL64(aCross, 3U)) + RotL64(aCarry, 11U)) + 14174828900676165088U) + aPhaseEOrbiterAssignSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterH = (aWandererD + RotL64(aScatter, 23U)) + 16277954291890598132U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 14845750668693136766U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 150099699692047766U;
            aOrbiterA = RotL64((aOrbiterA * 7644895634421086357U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 1200784917165131703U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 9469982764806754302U;
            aOrbiterE = RotL64((aOrbiterE * 17851969334511301943U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 10956702761701710182U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 7915506894975487807U;
            aOrbiterG = RotL64((aOrbiterG * 8874108311712727983U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 17335794183733623213U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 557028996286989506U;
            aOrbiterI = RotL64((aOrbiterI * 3993359298602424281U), 37U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 1597385667771002414U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 4376417959915162639U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4626236858205178149U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 549770198518993876U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 756554555648070919U;
            aOrbiterF = RotL64((aOrbiterF * 16272320259614325355U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 7298557532533152193U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 3336802611342112013U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14679103452120080499U), 21U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterK, 51U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 5U));
            aIngress = aIngress + (RotL64(aOrbiterF, 27U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterA, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterI, 29U)) + aOrbiterG) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 23U) + RotL64(aOrbiterH, 22U)) + aOrbiterK) + RotL64(aCarry, 27U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 5U) + aOrbiterI) + RotL64(aOrbiterF, 57U));
            aWandererC = aWandererC + ((RotL64(aScatter, 57U) + aOrbiterA) + RotL64(aOrbiterH, 47U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 44U) + aOrbiterG) + RotL64(aOrbiterA, 35U));
            aWandererG = aWandererG + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterE, 41U)) + aOrbiterF) + RotL64(aCarry, 53U)) + aPhaseEWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 37U) + aOrbiterH) + RotL64(aOrbiterE, 5U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 56U));
            aCarry = aCarry + RotL64(aWandererG, 29U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 21891U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneA[((aIndex + 17275U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 21745U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneC[((aIndex + 18555U)) & S_BLOCK1], 42U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aIngress, 23U)) ^ (RotL64(aCarry, 51U) ^ RotL64(aPrevious, 38U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = (aWandererE + RotL64(aPrevious, 35U)) + 16519040829220310189U;
            aOrbiterK = ((aWandererI + RotL64(aCross, 27U)) + 6888002778416941825U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = ((aWandererA + RotL64(aScatter, 19U)) + RotL64(aCarry, 47U)) + 1310832187746534025U;
            aOrbiterH = ((aWandererC + RotL64(aIngress, 51U)) + 5890888009051281674U) + aPhaseEOrbiterAssignSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = (aWandererD + RotL64(aScatter, 58U)) + 5143864838362464857U;
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 41U)) + RotL64(aCarry, 5U)) + 15591534069452660003U;
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 11U)) + RotL64(aCarry, 21U)) + 1466867671765325096U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 13931443680107902488U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 15400747367673245552U;
            aOrbiterB = RotL64((aOrbiterB * 7011651369456453127U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 2836975369734495759U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 2370720358274970117U;
            aOrbiterK = RotL64((aOrbiterK * 4615571902817575375U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 3470677184188006133U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 7175584278499266723U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10067096593682482345U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 6095078817776863055U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 2176637999243513070U;
            aOrbiterH = RotL64((aOrbiterH * 12215701810843975501U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 5580391239754903129U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 15196125567953871184U;
            aOrbiterI = RotL64((aOrbiterI * 12686361960729564519U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 12787014151503209931U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 1523153207064063495U;
            aOrbiterE = RotL64((aOrbiterE * 3113907543551927561U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 12973289026485937829U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 9087439766232078173U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5817029335999350327U), 23U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterB, 58U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 37U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 51U));
            aIngress = aIngress + RotL64(aOrbiterK, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterI, 30U)) + aOrbiterA);
            aWandererH = aWandererH + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterA, 13U)) + aOrbiterK) + aPhaseEWandererUpdateSaltB[((aIndex + 4U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterJ, 39U)) + aOrbiterE);
            aWandererA = aWandererA + ((((RotL64(aIngress, 20U) + aOrbiterH) + RotL64(aOrbiterE, 57U)) + RotL64(aCarry, 27U)) + aPhaseEWandererUpdateSaltA[((aIndex + 24U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 5U) + aOrbiterA) + RotL64(aOrbiterH, 47U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 43U) + aOrbiterK) + RotL64(aOrbiterH, 19U)) + RotL64(aCarry, 39U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterB, 3U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 38U));
            aCarry = aCarry + (RotL64(aWandererE, 5U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererD, 53U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 28026U)) & S_BLOCK1], 20U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28488U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 30049U)) & S_BLOCK1], 34U) ^ RotL64(aOperationLaneD[((aIndex + 27940U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 11U) ^ RotL64(aCross, 36U)) + (RotL64(aIngress, 57U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = (aWandererH + RotL64(aPrevious, 29U)) + 7960325128608297381U;
            aOrbiterA = (aWandererA + RotL64(aCross, 23U)) + 12773836012104052042U;
            aOrbiterI = (((aWandererD + RotL64(aScatter, 57U)) + RotL64(aCarry, 35U)) + 3173972621347773016U) + aPhaseEOrbiterAssignSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterB = ((aWandererC + RotL64(aIngress, 51U)) + RotL64(aCarry, 21U)) + 3708401356314308171U;
            aOrbiterJ = (((aWandererF + RotL64(aCross, 36U)) + RotL64(aCarry, 51U)) + 950774285720019449U) + aPhaseEOrbiterAssignSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterD = (aWandererJ + RotL64(aPrevious, 3U)) + 4170092315705438265U;
            aOrbiterF = (aWandererE + RotL64(aScatter, 43U)) + 17000449130864980747U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 8793910540062893860U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 520277969543516469U;
            aOrbiterI = RotL64((aOrbiterI * 4150613128885828229U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 12762214857389827271U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 2932451184340207695U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7513337346940091655U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 11062179998786293839U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 7919119215271524178U;
            aOrbiterA = RotL64((aOrbiterA * 9053677007180081359U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 1774988449597115155U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 3799792889466518953U;
            aOrbiterJ = RotL64((aOrbiterJ * 17512791286490623455U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 1815062051307896589U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 15260373951371654483U;
            aOrbiterG = RotL64((aOrbiterG * 2208604434669491625U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 12867546628945676853U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 7772820973895846946U;
            aOrbiterB = RotL64((aOrbiterB * 7581704643538761985U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 14213957831821966834U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 16561105721170419454U;
            aOrbiterF = RotL64((aOrbiterF * 2540533987337175367U), 23U);
            //
            aIngress = RotL64(aOrbiterB, 14U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 39U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 23U));
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aCross, 35U) + aOrbiterG) + RotL64(aOrbiterD, 39U)) + RotL64(aCarry, 23U)) + aPhaseEWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 53U) + aOrbiterI) + RotL64(aOrbiterJ, 10U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 23U) + aOrbiterG) + RotL64(aOrbiterF, 57U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterJ, 21U)) + aOrbiterB);
            aWandererE = aWandererE + (((RotL64(aScatter, 10U) + RotL64(aOrbiterA, 29U)) + aOrbiterF) + RotL64(aCarry, 37U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterA, 3U)) + aOrbiterI);
            aWandererD = aWandererD + (((RotL64(aIngress, 3U) + aOrbiterG) + RotL64(aOrbiterA, 47U)) + aPhaseEWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 18U));
            aCarry = aCarry + (RotL64(aWandererE, 53U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererF, 13U);
            aCarry = aCarry + RotL64(aIngress, 46U);
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

void TwistExpander_Cricket_Arx::Twist_D(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0;
    std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0;
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 2075U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7089U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4686U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 2447U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCross, 27U)) + (RotL64(aCarry, 57U) + RotL64(aPrevious, 10U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = (aWandererK + RotL64(aScatter, 48U)) + 6342299552323486695U;
            aOrbiterK = (((aWandererG + RotL64(aIngress, 19U)) + RotL64(aCarry, 57U)) + 12692748514781367538U) + aPhaseFOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = (((aWandererH + RotL64(aPrevious, 3U)) + RotL64(aCarry, 5U)) + 8202639945493229155U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = ((aWandererA + RotL64(aCross, 39U)) + RotL64(aCarry, 43U)) + 4439975701793231639U;
            aOrbiterB = (aWandererJ + RotL64(aScatter, 11U)) + 16774235182859553759U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 8764155413335405667U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 7167848811974967685U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1052856924757654735U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 16768278912125334220U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 9090838954826296201U;
            aOrbiterE = RotL64((aOrbiterE * 5459329624017272077U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 7644075729758006298U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 17326182797908071215U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2408330168749256075U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 16158809721888137555U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 8029938783858263694U;
            aOrbiterK = RotL64((aOrbiterK * 12628072435324195483U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 8716553521415553404U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 7012599977009208840U;
            aOrbiterB = RotL64((aOrbiterB * 8775355876188948851U), 57U);
            //
            aIngress = RotL64(aOrbiterI, 23U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterE, 46U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 38U) + RotL64(aOrbiterE, 53U)) + aOrbiterB);
            aWandererG = aWandererG + ((((RotL64(aCross, 3U) + RotL64(aOrbiterF, 28U)) + aOrbiterK) + RotL64(aCarry, 29U)) + aPhaseFWandererUpdateSaltA[((aIndex + 18U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterK, 13U)) + aOrbiterB);
            aWandererH = aWandererH + (((RotL64(aPrevious, 47U) + aOrbiterB) + RotL64(aOrbiterI, 3U)) + RotL64(aCarry, 41U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterI, 41U)) + aOrbiterE) + aPhaseFWandererUpdateSaltE[((aIndex + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererA);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 44U));
            aCarry = aCarry + RotL64(aWandererK, 11U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 14423U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneD[((aIndex + 9886U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 13997U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 15208U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 34U) + RotL64(aCross, 21U)) + (RotL64(aIngress, 5U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = (((aWandererE + RotL64(aScatter, 47U)) + RotL64(aCarry, 37U)) + 13053031069776604052U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = (((aWandererI + RotL64(aPrevious, 3U)) + RotL64(aCarry, 23U)) + 1331396630251085122U) + aPhaseFOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = ((aWandererH + RotL64(aIngress, 37U)) + RotL64(aCarry, 5U)) + 15879286043343942393U;
            aOrbiterK = (aWandererB + RotL64(aCross, 13U)) + 13590365633321406830U;
            aOrbiterB = (aWandererC + RotL64(aScatter, 22U)) + 14569235423040242618U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 11397370636618371560U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 3455933494593971847U;
            aOrbiterF = RotL64((aOrbiterF * 13051161161405358793U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 1307153376443784593U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 10688618762584786871U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9503823896874842411U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 17746248451153600096U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 8512568600755410158U;
            aOrbiterH = RotL64((aOrbiterH * 16648320170768234063U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 8950230550112591092U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 17790968369472845496U;
            aOrbiterE = RotL64((aOrbiterE * 5104988920132008913U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 12583323865381967534U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 11243927099685293887U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12867003042486433971U), 39U);
            //
            aIngress = RotL64(aOrbiterF, 47U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + RotL64(aOrbiterH, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aScatter, 35U) + RotL64(aOrbiterE, 29U)) + aOrbiterH) + RotL64(aCarry, 23U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 21U) + aOrbiterK) + RotL64(aOrbiterF, 43U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterB, 51U)) + aOrbiterF) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 56U) + aOrbiterK) + RotL64(aOrbiterE, 20U));
            aWandererB = aWandererB + ((((RotL64(aPrevious, 47U) + aOrbiterK) + RotL64(aOrbiterH, 3U)) + RotL64(aCarry, 51U)) + aPhaseFWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererB, 5U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 24510U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneA[((aIndex + 16688U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19264U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneC[((aIndex + 20827U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 43U) ^ RotL64(aCross, 27U)) + (RotL64(aCarry, 57U) + RotL64(aPrevious, 10U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = ((aWandererJ + RotL64(aCross, 54U)) + RotL64(aCarry, 39U)) + 6521330037475130256U;
            aOrbiterH = ((aWandererC + RotL64(aIngress, 39U)) + RotL64(aCarry, 19U)) + 12611880456055428940U;
            aOrbiterG = (aWandererG + RotL64(aScatter, 29U)) + 12061611078130934708U;
            aOrbiterJ = (((aWandererB + RotL64(aPrevious, 11U)) + RotL64(aCarry, 5U)) + 1558112410801116984U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = ((aWandererK + RotL64(aScatter, 21U)) + 10509115227850160786U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 4045915960688792066U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 1196541286513243082U;
            aOrbiterG = RotL64((aOrbiterG * 5454309408259753479U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 15564991032722373702U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 4897765238703641798U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9693901276712946763U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 12327429514907752733U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 6189189797708711636U;
            aOrbiterK = RotL64((aOrbiterK * 9017615866338877651U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 6374267075282018852U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 1888758503831341439U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 74387714918264257U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 14956857689299491800U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 14879361107223331957U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9166712966729591953U), 35U);
            //
            aIngress = RotL64(aOrbiterH, 39U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 57U));
            aIngress = aIngress + RotL64(aOrbiterG, 14U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aPrevious, 29U) + aOrbiterG) + RotL64(aOrbiterH, 4U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterI, 37U)) + aOrbiterJ);
            aWandererB = aWandererB + ((((RotL64(aScatter, 51U) + aOrbiterJ) + RotL64(aOrbiterG, 53U)) + RotL64(aCarry, 51U)) + aPhaseFWandererUpdateSaltC[((aIndex + 18U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterK, 13U)) + aOrbiterH);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 14U) + RotL64(aOrbiterK, 27U)) + aOrbiterJ) + RotL64(aCarry, 5U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 60U) ^ aWandererC);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + RotL64(aWandererJ, 19U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 31351U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneB[((aIndex + 31970U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 31107U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneD[((aIndex + 32065U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 51U) + RotL64(aCarry, 37U)) + (RotL64(aCross, 20U) ^ RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 19U)) + 3199575576585871314U) + aPhaseFOrbiterAssignSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 57U)) + RotL64(aCarry, 57U)) + 2533378188975571824U;
            aOrbiterC = (((aWandererD + RotL64(aScatter, 47U)) + RotL64(aCarry, 5U)) + 6819782112558312658U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = ((aWandererA + RotL64(aCross, 29U)) + RotL64(aCarry, 41U)) + 12690060987724798497U;
            aOrbiterK = (aWandererJ + RotL64(aIngress, 4U)) + 7088375139715629606U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 17785618677423695666U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 1714999280296491277U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7675674437417383741U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 17611338506932491624U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 6475727359297421201U;
            aOrbiterJ = RotL64((aOrbiterJ * 15133348244242438069U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 2347744591204119530U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 2739317903351401068U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15435029315209475631U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 8663535261373274338U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 8205245127823536479U;
            aOrbiterB = RotL64((aOrbiterB * 13857005110466856439U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 8916510616749754516U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 3944805940148512932U;
            aOrbiterK = RotL64((aOrbiterK * 18082271583211389701U), 27U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterC, 19U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + RotL64(aOrbiterJ, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 11U) + aOrbiterB) + RotL64(aOrbiterC, 52U)) + aPhaseFWandererUpdateSaltE[((aIndex + 12U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 19U) + aOrbiterB) + RotL64(aOrbiterJ, 21U)) + RotL64(aCarry, 29U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterG, 37U)) + aOrbiterJ);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 43U) + aOrbiterG) + RotL64(aOrbiterK, 13U)) + RotL64(aCarry, 43U)) + aPhaseFWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 60U) + RotL64(aOrbiterC, 29U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 60U));
            aCarry = aCarry + RotL64(aWandererH, 39U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 4395U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 7637U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 4038U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 2646U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 41U) + RotL64(aIngress, 24U)) ^ (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = ((aWandererB + RotL64(aCross, 54U)) + RotL64(aCarry, 35U)) + 12131317914288566437U;
            aOrbiterF = (((aWandererA + RotL64(aIngress, 3U)) + RotL64(aCarry, 47U)) + 5672805657999385496U) + aPhaseGOrbiterAssignSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 37U)) + RotL64(aCarry, 23U)) + 3581710244233124197U;
            aOrbiterB = (aWandererG + RotL64(aScatter, 21U)) + 15251296040538489436U;
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 13U)) + 11295008604679904153U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 2230897493419504490U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 7109600123297458999U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8267799351136506307U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 13119156643107683803U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 14755160867807355250U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10007087518844899239U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 16829363373287496832U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 16981122946707720883U;
            aOrbiterB = RotL64((aOrbiterB * 5394974422201576627U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 8806000776958603317U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 16810923047720876014U;
            aOrbiterF = RotL64((aOrbiterF * 17872735050219539145U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 8129657889554436328U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 8653100378491974463U;
            aOrbiterE = RotL64((aOrbiterE * 11395283153912468661U), 5U);
            //
            aIngress = RotL64(aOrbiterE, 19U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterB, 47U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 56U) + RotL64(aOrbiterB, 29U)) + aOrbiterD);
            aWandererG = aWandererG + ((((RotL64(aIngress, 13U) + aOrbiterD) + RotL64(aOrbiterE, 47U)) + RotL64(aCarry, 39U)) + aPhaseGWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 27U) + aOrbiterE) + RotL64(aOrbiterG, 20U));
            aWandererC = aWandererC + ((((RotL64(aScatter, 43U) + RotL64(aOrbiterF, 39U)) + aOrbiterB) + RotL64(aCarry, 23U)) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterF, 57U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererG, 14U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererB, 43U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 12588U)) & S_BLOCK1], 50U) ^ RotL64(aWorkLaneC[((aIndex + 12202U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 14034U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneA[((aIndex + 10274U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aIngress, 47U)) ^ (RotL64(aPrevious, 60U) ^ RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = (((aWandererB + RotL64(aCross, 56U)) + RotL64(aCarry, 57U)) + 701291026547470433U) + aPhaseGOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = (aWandererG + RotL64(aIngress, 5U)) + 17283292650462111643U;
            aOrbiterD = (aWandererA + RotL64(aScatter, 13U)) + 9969124091931303406U;
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 21U)) + RotL64(aCarry, 39U)) + 889176772718046988U;
            aOrbiterJ = (((aWandererH + RotL64(aScatter, 41U)) + RotL64(aCarry, 19U)) + 6054541844643748084U) + aPhaseGOrbiterAssignSaltC[((aIndex + 24U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 14703226235143028132U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 7977975878522921062U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9030855800028448469U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 16894322614172266274U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 12160451749345900570U;
            aOrbiterJ = RotL64((aOrbiterJ * 18055355572903901749U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 10870847008043897470U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 8159920947172520247U;
            aOrbiterG = RotL64((aOrbiterG * 4833194641611011805U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 2440099120969517932U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 2428396147731468007U;
            aOrbiterC = RotL64((aOrbiterC * 9363073341539598441U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 2213226274394673479U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 7079731443427765333U;
            aOrbiterH = RotL64((aOrbiterH * 16918930776877030559U), 19U);
            //
            aIngress = RotL64(aOrbiterC, 57U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterD, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aScatter, 23U) + aOrbiterJ) + RotL64(aOrbiterD, 57U)) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 57U) + aOrbiterJ) + RotL64(aOrbiterG, 3U));
            aWandererF = aWandererF + ((((RotL64(aCross, 47U) + RotL64(aOrbiterH, 41U)) + aOrbiterG) + RotL64(aCarry, 53U)) + aPhaseGWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 34U) + RotL64(aOrbiterH, 28U)) + aOrbiterD);
            aWandererA = aWandererA + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterC, 19U)) + aOrbiterG) + aPhaseGWandererUpdateSaltA[((aIndex + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererF, 35U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 16596U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneD[((aIndex + 21466U)) & S_BLOCK1], 50U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 19622U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneB[((aIndex + 20074U)) & S_BLOCK1], 50U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 21U) + RotL64(aIngress, 41U)) ^ (RotL64(aCross, 56U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = (aWandererK + RotL64(aIngress, 3U)) + 17668251151213543491U;
            aOrbiterC = ((aWandererG + RotL64(aPrevious, 37U)) + RotL64(aCarry, 3U)) + 16101602509895104517U;
            aOrbiterB = (((aWandererJ + RotL64(aScatter, 24U)) + RotL64(aCarry, 29U)) + 9083915270773304935U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = (aWandererC + RotL64(aCross, 13U)) + 12810720730318214811U;
            aOrbiterH = (((aWandererI + RotL64(aIngress, 47U)) + RotL64(aCarry, 43U)) + 18113428002071925621U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 1582208899354109878U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 4180688104819188154U;
            aOrbiterB = RotL64((aOrbiterB * 3391785441902730815U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 8954598189262820611U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 15360094153175355879U;
            aOrbiterC = RotL64((aOrbiterC * 8177798855402983685U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 8383954114668216260U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 15626783326234049197U;
            aOrbiterD = RotL64((aOrbiterD * 15058420415480073793U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 10609978564404958066U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 17656516608997517984U;
            aOrbiterG = RotL64((aOrbiterG * 4590620354119899777U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 760077259110786536U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 3597338735888033063U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6548831472863517621U), 51U);
            //
            aIngress = RotL64(aOrbiterG, 29U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterC, 18U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aScatter, 37U) + RotL64(aOrbiterB, 39U)) + aOrbiterG) + RotL64(aCarry, 29U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterD, 11U)) + aOrbiterG);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterC, 3U)) + aOrbiterB) + RotL64(aCarry, 11U)) + aPhaseGWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 6U) + RotL64(aOrbiterH, 51U)) + aOrbiterG);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterB, 24U)) + aOrbiterH) + aPhaseGWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererC, 43U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 29285U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((aIndex + 27035U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 24792U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneC[((aIndex + 28109U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCross, 57U)) + (RotL64(aIngress, 36U) + RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = (aWandererC + RotL64(aPrevious, 3U)) + 9630214189402543339U;
            aOrbiterG = ((aWandererI + RotL64(aIngress, 13U)) + RotL64(aCarry, 5U)) + 4072576573737526819U;
            aOrbiterB = (((aWandererA + RotL64(aCross, 39U)) + RotL64(aCarry, 37U)) + 15994787452709618869U) + aPhaseGOrbiterAssignSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = (((aWandererG + RotL64(aScatter, 56U)) + RotL64(aCarry, 53U)) + 6403240137132259482U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = (aWandererH + RotL64(aPrevious, 21U)) + 10229266900170507720U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 5025294577989748989U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 16696461238217956883U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15993828976234917577U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 9878318855341719119U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 16086635438116177346U;
            aOrbiterC = RotL64((aOrbiterC * 5585682357395705671U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 12295437783084203730U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 7681150419912842402U;
            aOrbiterK = RotL64((aOrbiterK * 7289497379725191451U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 2639104034287637448U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 12298170009332243573U;
            aOrbiterG = RotL64((aOrbiterG * 9397919591171238575U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 3485932317267669626U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 16569551670038752475U;
            aOrbiterE = RotL64((aOrbiterE * 8139802826402217631U), 11U);
            //
            aIngress = RotL64(aOrbiterC, 5U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterG, 21U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterK, 36U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 50U) + RotL64(aOrbiterB, 29U)) + aOrbiterK) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 13U) + aOrbiterG) + RotL64(aOrbiterC, 41U)) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 3U) + aOrbiterE) + RotL64(aOrbiterK, 13U));
            aWandererG = aWandererG + (((RotL64(aCross, 23U) + RotL64(aOrbiterG, 3U)) + aOrbiterB) + RotL64(aCarry, 51U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 37U) + RotL64(aOrbiterE, 56U)) + aOrbiterC) + aPhaseGWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (RotL64(aWandererG, 60U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 27U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 7650U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((aIndex + 2298U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1757U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 7376U)) & S_BLOCK1], 44U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCarry, 19U)) + (RotL64(aPrevious, 4U) + RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = (aWandererD + RotL64(aIngress, 29U)) + 12775735908960052604U;
            aOrbiterK = (((aWandererJ + RotL64(aCross, 3U)) + RotL64(aCarry, 19U)) + 11791373812080296887U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = ((aWandererB + RotL64(aScatter, 18U)) + RotL64(aCarry, 57U)) + 5537362877706057303U;
            aOrbiterF = (((aWandererA + RotL64(aPrevious, 57U)) + RotL64(aCarry, 35U)) + 2023912048504189380U) + aPhaseHOrbiterAssignSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterI = (aWandererI + RotL64(aIngress, 39U)) + 17668828109963766893U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 558908629933941224U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 1479633119685446888U;
            aOrbiterG = RotL64((aOrbiterG * 4447153373540811385U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 15460320397843364063U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 10059749397555469054U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8671817118586065469U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 9987633811929693924U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 10087337844580228269U;
            aOrbiterF = RotL64((aOrbiterF * 13817142288940843815U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 4446204415503364254U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 15106063243302192717U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13273756657334709803U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 9430197906134676162U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 1226048679997253363U;
            aOrbiterI = RotL64((aOrbiterI * 14247538885252664127U), 3U);
            //
            aIngress = RotL64(aOrbiterG, 14U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterI, 43U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterF, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aCross, 51U) + aOrbiterD) + RotL64(aOrbiterI, 41U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 23U) + aOrbiterF) + RotL64(aOrbiterK, 13U)) + aPhaseHWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 60U) + RotL64(aOrbiterD, 4U)) + aOrbiterG) + RotL64(aCarry, 53U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 11U) + aOrbiterF) + RotL64(aOrbiterD, 29U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 43U) + aOrbiterG) + RotL64(aOrbiterI, 21U)) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererD, 3U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 10002U)) & S_BLOCK1], 44U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15496U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 13454U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 9594U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 38U) ^ RotL64(aIngress, 51U)) ^ (RotL64(aPrevious, 19U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = (((aWandererI + RotL64(aCross, 43U)) + RotL64(aCarry, 37U)) + 15813325389431304548U) + aPhaseHOrbiterAssignSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 56U)) + 2223874171125403602U) + aPhaseHOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = ((aWandererA + RotL64(aIngress, 3U)) + RotL64(aCarry, 19U)) + 5510483568496824130U;
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 29U)) + RotL64(aCarry, 3U)) + 15474152493495661876U;
            aOrbiterC = (aWandererC + RotL64(aIngress, 13U)) + 16846339705130829195U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 1289670576865739669U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 18017354919647006944U;
            aOrbiterB = RotL64((aOrbiterB * 13103155460891498469U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 8539685539928984921U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 3333721400836704048U;
            aOrbiterC = RotL64((aOrbiterC * 3745286323481400085U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 2261560416623815491U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 4377786131746816567U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9164777834392621157U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 18047393176583722719U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 8184724021940434631U;
            aOrbiterJ = RotL64((aOrbiterJ * 9800116157750921119U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 10469895939183324807U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 14543391765109879223U;
            aOrbiterD = RotL64((aOrbiterD * 4817987697437667225U), 53U);
            //
            aIngress = RotL64(aOrbiterK, 35U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + RotL64(aOrbiterD, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aScatter, 13U) + aOrbiterK) + RotL64(aOrbiterC, 29U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterC, 57U)) + aOrbiterB) + RotL64(aCarry, 51U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 51U) + RotL64(aOrbiterJ, 3U)) + aOrbiterK) + aPhaseHWandererUpdateSaltD[((aIndex + 6U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aIngress, 41U) + RotL64(aOrbiterJ, 40U)) + aOrbiterD) + RotL64(aCarry, 13U)) + aPhaseHWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 30U) + aOrbiterD) + RotL64(aOrbiterK, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 12U) ^ aWandererF);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + RotL64(aWandererC, 57U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 20822U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneD[((aIndex + 18297U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22546U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 22392U)) & S_BLOCK1], 50U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 47U) ^ RotL64(aIngress, 35U)) ^ (RotL64(aCross, 60U) + RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = ((aWandererG + RotL64(aScatter, 47U)) + RotL64(aCarry, 39U)) + 5573188770530340913U;
            aOrbiterG = ((aWandererE + RotL64(aIngress, 21U)) + 1431772230889897111U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = (((aWandererC + RotL64(aPrevious, 60U)) + RotL64(aCarry, 19U)) + 4809192776429682319U) + aPhaseHOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = ((aWandererF + RotL64(aCross, 37U)) + RotL64(aCarry, 3U)) + 5576603692574369341U;
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 13U)) + 2720143226007220386U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 17220328778565331629U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 9629485808442089423U;
            aOrbiterF = RotL64((aOrbiterF * 18349580416082045015U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 1136998437010390983U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 11893390497814523841U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5329621622743089531U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 1764986431917532370U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 1741014798007010376U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13414914086049500731U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 12221368453236547044U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 7694538641172350430U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8439120733670016501U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 17472344518811560603U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 3308740700728172984U;
            aOrbiterJ = RotL64((aOrbiterJ * 15290400462887712083U), 19U);
            //
            aIngress = RotL64(aOrbiterJ, 23U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 46U));
            aIngress = aIngress + RotL64(aOrbiterA, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterE, 5U)) + aOrbiterJ) + RotL64(aCarry, 27U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 56U) + aOrbiterJ) + RotL64(aOrbiterF, 41U)) + aPhaseHWandererUpdateSaltF[((aIndex + 10U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aScatter, 43U) + RotL64(aOrbiterF, 54U)) + aOrbiterG);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 23U) + aOrbiterG) + RotL64(aOrbiterA, 13U)) + aPhaseHWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 35U) + RotL64(aOrbiterG, 29U)) + aOrbiterJ) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + RotL64(aWandererE, 29U);
            aCarry = aCarry + RotL64(aIngress, 18U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 29700U)) & S_BLOCK1], 36U) ^ RotL64(aWorkLaneA[((aIndex + 26350U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27693U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 26777U)) & S_BLOCK1], 10U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 21U) + RotL64(aCross, 37U)) ^ (RotL64(aCarry, 6U) ^ RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = (((aWandererE + RotL64(aScatter, 29U)) + RotL64(aCarry, 19U)) + 14823268998003220191U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = (aWandererG + RotL64(aIngress, 39U)) + 15295237288788213847U;
            aOrbiterF = ((aWandererJ + RotL64(aCross, 5U)) + RotL64(aCarry, 3U)) + 16434853402001133899U;
            aOrbiterI = (((aWandererC + RotL64(aPrevious, 48U)) + RotL64(aCarry, 53U)) + 7555911304407871631U) + aPhaseHOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = (aWandererD + RotL64(aIngress, 21U)) + 14977248264994834620U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 9707764144919392380U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 1277304385464681529U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2864691650462053463U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 3089786220465849395U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 3700503853358695085U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2079089949442685421U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 3240054112993517371U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 16897532076915366859U;
            aOrbiterI = RotL64((aOrbiterI * 4120874717534309035U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 18167359289798364307U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 8870819278575769863U;
            aOrbiterH = RotL64((aOrbiterH * 9334066154398059075U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 15363069206212330251U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 14858164441499725158U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14931933411393847915U), 57U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterB, 57U);
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterF, 30U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aScatter, 5U) + RotL64(aOrbiterI, 13U)) + aOrbiterF);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterI, 47U)) + aOrbiterA) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 27U) + RotL64(aOrbiterH, 37U)) + aOrbiterF) + RotL64(aCarry, 53U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 48U) + aOrbiterA) + RotL64(aOrbiterH, 4U)) + aPhaseHWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 13U) + aOrbiterI) + RotL64(aOrbiterB, 21U)) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererG);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + RotL64(aWandererC, 5U);
            aCarry = aCarry + RotL64(aIngress, 22U);
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
