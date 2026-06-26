#include "TwistExpander_Bowling_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_Bowling_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x8D3BB82FABD6FB97ULL + 0x98C3DF09CCEB5339ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x81724B5F504E1BA9ULL + 0xE2AB029E72712D43ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xB15F83B91BA27785ULL + 0xC18C303DEB6A7161ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xE94879AB53E182B7ULL + 0xD030D89E8B7EDAEBULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xA9A98A3B4E9FDA3DULL + 0x8EDA2B5329FDFB85ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xD4B577F71E38092FULL + 0xCB1C012B5F6A87C7ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x9E924749C1E07815ULL + 0x8679FA2934D22C24ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xD2CEC941FFA47601ULL + 0xF9F4FE88E35F1BBBULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xF4BC25970AE8E0B3ULL + 0x98C8D5207E19FC75ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xCEB1AFC988682371ULL + 0xF66F6135F51A5243ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xD68804EE9BFD7CF1ULL + 0xB052CCFE039FE562ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xFDB93146C847F1CDULL + 0xB3290FE0B1170EC5ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xEF69A92C90C68031ULL + 0xEF232E5385E66306ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xC6F4B7ACB9B8C2FBULL + 0x823BDF0D56E1CD75ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xC8B74116F5436F01ULL + 0xE0868D552ADA09FFULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xDB0A52549ECBFB55ULL + 0xA1FE5BB5462723CEULL);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 5262U)) & S_BLOCK1], 11U) ^ RotL64(pSnow[((aIndex + 4274U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 3223U)) & S_BLOCK1], 3U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 4713U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 3U) + RotL64(aCross, 22U)) + (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 51U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((aWandererK + RotL64(aIngress, 23U)) + 3248574644570178787U) + aNonceWordP;
            aOrbiterA = (((aWandererJ + RotL64(aPrevious, 60U)) + RotL64(aCarry, 29U)) + 4506961512959200024U) + aOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = (aWandererE + RotL64(aCross, 29U)) + 8423739774540738590U;
            aOrbiterE = ((aWandererF + RotL64(aScatter, 47U)) + RotL64(aCarry, 37U)) + 6593975869641735337U;
            aOrbiterJ = ((aWandererB + RotL64(aCross, 3U)) + 16441716090557369103U) + aNonceWordD;
            aOrbiterI = ((aWandererC + RotL64(aIngress, 35U)) + RotL64(aCarry, 43U)) + 7936601450453207914U;
            aOrbiterC = (aWandererA + RotL64(aPrevious, 41U)) + 13333752583560167065U;
            aOrbiterG = (aWandererG + RotL64(aScatter, 38U)) + 8013703284795432973U;
            aOrbiterH = ((aWandererI + RotL64(aCross, 13U)) + 2349852779887439236U) + aOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = (aWandererD + RotL64(aIngress, 27U)) + 5318539364763284138U;
            aOrbiterD = (aWandererH + RotL64(aScatter, 53U)) + 11450957608502944376U;
            //
            aOrbiterF = (((aOrbiterF + aOrbiterA) + 9058992558327552687U) + aOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1]) + aNonceWordK;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 632095686920230926U;
            aOrbiterK = RotL64((aOrbiterK * 12460364388358520799U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 14734218428913777098U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 16344357661370784442U;
            aOrbiterI = RotL64((aOrbiterI * 15049472842002138369U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 2981145363531184308U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 14176472085175714494U;
            aOrbiterF = RotL64((aOrbiterF * 2584623327412130939U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 11198457590069700889U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 952584436750426828U) ^ aOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1165713888651280355U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 4311591763498985972U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 16194341833989936369U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9997934560195932575U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 7560794022401107431U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 10683789740265711603U;
            aOrbiterH = RotL64((aOrbiterH * 15637823045351977883U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 11614366395125937178U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 10750771385100564416U;
            aOrbiterD = RotL64((aOrbiterD * 4987921274272444283U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 2934697034132204529U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 4646873794658020363U;
            aOrbiterA = RotL64((aOrbiterA * 10555456865641580175U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 7913681837683568905U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 17603563535330106340U) ^ aNonceWordG;
            aOrbiterJ = RotL64((aOrbiterJ * 17882943067522319671U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 15375641415139193079U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 17059712718085411887U;
            aOrbiterG = RotL64((aOrbiterG * 13722089235751208215U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 14022558453716067200U) + aNonceWordC;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 3248574644570178787U;
            aOrbiterB = RotL64((aOrbiterB * 15249135451439374621U), 5U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterF, 3U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 24U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 39U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 29U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 11U));
            aIngress = aIngress + RotL64(aOrbiterD, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterA, 27U)) + aOrbiterI);
            aWandererK = aWandererK ^ (((RotL64(aCross, 51U) + RotL64(aOrbiterG, 13U)) + aOrbiterA) + aWandererUpdateSaltB[((aIndex + 10U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 19U) + aOrbiterG) + RotL64(aOrbiterK, 36U)) + RotL64(aCarry, 27U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterH, 3U)) + aOrbiterE);
            aWandererA = aWandererA + ((RotL64(aCross, 53U) + RotL64(aOrbiterK, 39U)) + aOrbiterD);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 23U) + aOrbiterG) + RotL64(aOrbiterC, 19U)) + aWandererUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aScatter, 12U) + RotL64(aOrbiterF, 11U)) + aOrbiterG);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 47U) + aOrbiterE) + RotL64(aOrbiterD, 57U));
            aWandererF = aWandererF + (((RotL64(aCross, 27U) + RotL64(aOrbiterH, 23U)) + aOrbiterB) + aNonceWordM);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterB, 51U)) + aOrbiterK);
            aWandererE = aWandererE + (((RotL64(aPrevious, 30U) + aOrbiterH) + RotL64(aOrbiterJ, 30U)) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 41U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererD);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 36U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + RotL64(aWandererE, 29U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ aNonceWordO;
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 6205U)) & S_BLOCK1], 53U) ^ RotL64(mSource[((aIndex + 9831U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(pSnow[((S_BLOCK1 - aIndex + 5537U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 6718U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 26U) ^ RotL64(aCarry, 57U)) + (RotL64(aCross, 13U) ^ RotL64(aIngress, 41U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (((aWandererH + RotL64(aIngress, 43U)) + RotL64(aCarry, 5U)) + 9133751643283278896U) + aNonceWordK;
            aOrbiterI = (aWandererB + RotL64(aScatter, 13U)) + 8971581804375380408U;
            aOrbiterJ = (aWandererI + RotL64(aCross, 4U)) + 12559650383714566592U;
            aOrbiterC = (aWandererD + RotL64(aPrevious, 27U)) + 15753206088872859163U;
            aOrbiterA = (aWandererG + RotL64(aIngress, 37U)) + 7640756270450762350U;
            aOrbiterF = ((aWandererA + RotL64(aCross, 39U)) + RotL64(aCarry, 11U)) + 7340073357551376125U;
            aOrbiterG = (aWandererF + RotL64(aScatter, 47U)) + 5270256573644196046U;
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 51U)) + 3567367996479995928U) + aOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = (aWandererK + RotL64(aScatter, 54U)) + 11939634537492733738U;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 21U)) + RotL64(aCarry, 51U)) + 7051817732424527120U;
            aOrbiterE = ((aWandererE + RotL64(aIngress, 23U)) + 1730487669951837941U) + aOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1];
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 18009252467909454817U) + aOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 2361024272031696442U;
            aOrbiterJ = RotL64((aOrbiterJ * 15215151562500226027U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 15902755877642960397U) + aOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 12243517544704116184U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2576071074148141447U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 16846181962302186187U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 636121425116506681U;
            aOrbiterA = RotL64((aOrbiterA * 17075030673338779993U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 6887385655828217318U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 3705834550934775862U;
            aOrbiterG = RotL64((aOrbiterG * 11275428284929594435U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 11165142437077969438U) + aNonceWordG;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 6426659930331618269U) ^ aNonceWordF;
            aOrbiterB = RotL64((aOrbiterB * 17170640810530893705U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 12629082390899315789U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 4277510580069574724U;
            aOrbiterD = RotL64((aOrbiterD * 9829125163412708305U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 13814834144170469978U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 3698381854100295826U;
            aOrbiterC = RotL64((aOrbiterC * 5126359230872258015U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 11623170635983579937U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 7247413650388803796U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3403219499465560059U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 3129755194359521145U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 4081016725582134919U;
            aOrbiterH = RotL64((aOrbiterH * 11564414998539605389U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 15878346077922215753U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 2974440187796944059U;
            aOrbiterK = RotL64((aOrbiterK * 783253926537018373U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 3922344163443096356U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 9133751643283278896U;
            aOrbiterE = RotL64((aOrbiterE * 16887991698415418429U), 53U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterB, 21U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 50U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 35U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 43U));
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterI, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aIngress, 19U) + aOrbiterJ) + RotL64(aOrbiterF, 46U)) + RotL64(aCarry, 11U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 12U) + RotL64(aOrbiterA, 35U)) + aOrbiterC);
            aWandererK = aWandererK + (((RotL64(aCross, 3U) + RotL64(aOrbiterH, 19U)) + aOrbiterF) + RotL64(aCarry, 57U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterB, 5U)) + aOrbiterE) + aWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 21U) + aOrbiterA) + RotL64(aOrbiterH, 39U)) + aNonceWordB);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 57U) + aOrbiterJ) + RotL64(aOrbiterG, 37U));
            aWandererC = aWandererC + ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterF, 11U)) + aOrbiterK) + aNonceWordD) + aWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 47U) + aOrbiterI) + RotL64(aOrbiterJ, 23U)) + aNonceWordO);
            aWandererE = aWandererE + ((RotL64(aPrevious, 39U) + aOrbiterF) + RotL64(aOrbiterB, 52U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 60U) + aOrbiterH) + RotL64(aOrbiterD, 41U));
            aWandererF = aWandererF + ((RotL64(aCross, 5U) + aOrbiterI) + RotL64(aOrbiterD, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 60U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 5U) ^ aWandererC);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + (RotL64(aWandererJ, 18U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererA, 29U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ aNonceWordN;
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 12987U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((aIndex + 12514U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 16056U)) & S_BLOCK1], 3U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 12412U)) & S_BLOCK1], 36U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCarry, 60U)) + (RotL64(aCross, 11U) ^ RotL64(aPrevious, 27U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererA + RotL64(aScatter, 47U)) + 6342299552323486695U;
            aOrbiterC = (aWandererH + RotL64(aPrevious, 60U)) + 12692748514781367538U;
            aOrbiterK = ((aWandererK + RotL64(aCross, 41U)) + 8202639945493229155U) + aOrbiterAssignSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = (aWandererG + RotL64(aIngress, 23U)) + 4439975701793231639U;
            aOrbiterB = ((aWandererB + RotL64(aScatter, 27U)) + RotL64(aCarry, 23U)) + 16774235182859553759U;
            aOrbiterF = (aWandererE + RotL64(aPrevious, 57U)) + 8764155413335405667U;
            aOrbiterG = ((aWandererI + RotL64(aCross, 44U)) + RotL64(aCarry, 29U)) + 7167848811974967685U;
            aOrbiterD = (((aWandererF + RotL64(aIngress, 19U)) + RotL64(aCarry, 5U)) + 16768278912125334220U) + aNonceWordJ;
            aOrbiterE = ((aWandererD + RotL64(aCross, 39U)) + 9090838954826296201U) + aOrbiterAssignSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterA = (aWandererJ + RotL64(aIngress, 51U)) + 7644075729758006298U;
            aOrbiterI = (aWandererC + RotL64(aPrevious, 21U)) + 17326182797908071215U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 16158809721888137555U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 8029938783858263694U;
            aOrbiterK = RotL64((aOrbiterK * 12628072435324195483U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 8716553521415553404U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 7012599977009208840U;
            aOrbiterF = RotL64((aOrbiterF * 8775355876188948851U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 13250558696578541499U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 13705957059101025396U;
            aOrbiterC = RotL64((aOrbiterC * 16889495686487056367U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 2796775206291902461U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 13741676263512390669U;
            aOrbiterB = RotL64((aOrbiterB * 10455782033465595947U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 1691908360612389252U) + aNonceWordI;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 4114939415206031540U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2797401802892718297U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 2374911514440738727U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 12377616933668803091U;
            aOrbiterA = RotL64((aOrbiterA * 2505164835116651215U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 681094033415259645U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 13841322124900463362U;
            aOrbiterJ = RotL64((aOrbiterJ * 4210414203856902329U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 18082983557580381338U) + aNonceWordL;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 15731122225678626778U;
            aOrbiterH = RotL64((aOrbiterH * 7785999919955613789U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 2084336993254383330U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 3600882019682875370U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2977569829649654329U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 11436602278656592334U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 5775886971784627864U;
            aOrbiterE = RotL64((aOrbiterE * 6765942246225582787U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 17120308925134658794U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 6342299552323486695U) ^ aOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5788669985396507227U), 21U);
            //
            aIngress = RotL64(aOrbiterJ, 50U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterG, 53U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 19U));
            aIngress = aIngress + (RotL64(aOrbiterE, 39U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterD, 23U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterA, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 13U) + aOrbiterK) + RotL64(aOrbiterD, 58U));
            aWandererK = aWandererK + ((((RotL64(aPrevious, 39U) + aOrbiterH) + RotL64(aOrbiterF, 53U)) + RotL64(aCarry, 37U)) + aNonceWordG);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 22U) + RotL64(aOrbiterE, 39U)) + aOrbiterA);
            aWandererF = aWandererF + (((RotL64(aCross, 41U) + RotL64(aOrbiterJ, 41U)) + aOrbiterE) + aWandererUpdateSaltA[((aIndex + 6U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 43U) + aOrbiterH) + RotL64(aOrbiterI, 29U)) + aNonceWordB);
            aWandererE = aWandererE + ((RotL64(aCross, 51U) + aOrbiterJ) + RotL64(aOrbiterK, 23U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 27U) + aOrbiterI) + RotL64(aOrbiterJ, 19U)) + aNonceWordE);
            aWandererA = aWandererA + (((RotL64(aScatter, 10U) + aOrbiterC) + RotL64(aOrbiterI, 21U)) + RotL64(aCarry, 27U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 37U) + aOrbiterG) + RotL64(aOrbiterB, 34U)) + aWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterI, 51U)) + aOrbiterA);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 53U) + aOrbiterG) + RotL64(aOrbiterE, 43U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 34U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 29U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + (RotL64(aWandererG, 48U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererK, 57U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ aNonceWordB;
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 16989U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneB[((aIndex + 18046U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21401U)) & S_BLOCK1], 19U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 18373U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCross, 56U)) ^ (RotL64(aCarry, 27U) + RotL64(aIngress, 5U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (((aWandererE + RotL64(aCross, 3U)) + RotL64(aCarry, 39U)) + 16200278595895089008U) + aNonceWordH;
            aOrbiterI = (aWandererA + RotL64(aIngress, 27U)) + 1029614154810465897U;
            aOrbiterK = (aWandererG + RotL64(aPrevious, 41U)) + 7129562468705441295U;
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 29U)) + RotL64(aCarry, 29U)) + 14388903902433951274U;
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 53U)) + 1013568949315967455U) + aOrbiterAssignSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterF = (aWandererI + RotL64(aScatter, 38U)) + 3128823373497815651U;
            aOrbiterD = (aWandererK + RotL64(aCross, 47U)) + 14525694606889470589U;
            aOrbiterE = ((aWandererC + RotL64(aIngress, 57U)) + 14443983602196782887U) + aOrbiterAssignSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 51U)) + RotL64(aCarry, 11U)) + 12244220415328641190U;
            aOrbiterH = ((aWandererF + RotL64(aIngress, 10U)) + 10477159225338766614U) + aNonceWordO;
            aOrbiterC = (aWandererH + RotL64(aCross, 19U)) + 2842870123078131566U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 8621138818955849917U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 5038396344400303181U;
            aOrbiterK = RotL64((aOrbiterK * 14636756322207385447U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 2768613802894372496U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 2027754864051410015U;
            aOrbiterB = RotL64((aOrbiterB * 2461322540050569287U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 2848088309172056399U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 15017458513904884651U) ^ aNonceWordP;
            aOrbiterF = RotL64((aOrbiterF * 9926904679902843055U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 9079797279596336139U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 15424866642305110811U;
            aOrbiterD = RotL64((aOrbiterD * 12912331089970158845U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 13751764050290602740U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 7694557131324740282U;
            aOrbiterE = RotL64((aOrbiterE * 14980807690491467023U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 3508673897305667669U) + aOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 3600868397311393233U;
            aOrbiterG = RotL64((aOrbiterG * 5165032044164139165U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 1222655844979128996U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 2257342337168905875U) ^ aOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6198995971182272119U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 6290990717563682725U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 15308494772443447109U;
            aOrbiterC = RotL64((aOrbiterC * 1925593111157842325U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 4065385272074155855U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 17216369169581934516U;
            aOrbiterJ = RotL64((aOrbiterJ * 16172589962950781777U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 15683161334290612079U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 4197626901960576264U;
            aOrbiterI = RotL64((aOrbiterI * 2822547214684481747U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 4400047838649306704U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 16200278595895089008U;
            aOrbiterA = RotL64((aOrbiterA * 6603195071605635697U), 23U);
            //
            aIngress = RotL64(aOrbiterK, 47U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 58U));
            aIngress = aIngress + (RotL64(aOrbiterA, 11U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 19U));
            aIngress = aIngress + RotL64(aOrbiterB, 54U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((((RotL64(aScatter, 39U) + aOrbiterH) + RotL64(aOrbiterC, 35U)) + aNonceWordK) + aWandererUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 18U) + aOrbiterG) + RotL64(aOrbiterE, 60U)) + RotL64(aCarry, 11U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 21U) + aOrbiterF) + RotL64(aOrbiterA, 57U));
            aWandererA = aWandererA + ((RotL64(aIngress, 53U) + aOrbiterH) + RotL64(aOrbiterD, 13U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 23U) + aOrbiterK) + RotL64(aOrbiterJ, 27U));
            aWandererB = aWandererB + ((RotL64(aScatter, 43U) + RotL64(aOrbiterG, 48U)) + aOrbiterF);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterB, 43U)) + aOrbiterH);
            aWandererD = aWandererD + ((RotL64(aCross, 13U) + aOrbiterH) + RotL64(aOrbiterK, 21U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterJ, 29U)) + aOrbiterE);
            aWandererF = aWandererF + ((((RotL64(aIngress, 57U) + aOrbiterB) + RotL64(aOrbiterJ, 11U)) + RotL64(aCarry, 43U)) + aWandererUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 34U) + RotL64(aOrbiterF, 51U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 14U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 41U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + RotL64(aWandererF, 26U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ aNonceWordO;
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 23874U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((aIndex + 25988U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24721U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneA[((aIndex + 24868U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCross, 39U)) + (RotL64(aIngress, 54U) ^ RotL64(aCarry, 3U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (((aWandererJ + RotL64(aIngress, 47U)) + RotL64(aCarry, 39U)) + 6973892330986118220U) + aOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 39U)) + 9886813896272094864U;
            aOrbiterD = ((aWandererC + RotL64(aScatter, 57U)) + RotL64(aCarry, 27U)) + 10996306582517553173U;
            aOrbiterG = ((aWandererE + RotL64(aCross, 53U)) + 8490648283899856223U) + aNonceWordH;
            aOrbiterI = (aWandererG + RotL64(aPrevious, 5U)) + 105141713530704655U;
            aOrbiterF = (aWandererF + RotL64(aScatter, 20U)) + 3114337422810562588U;
            aOrbiterB = (aWandererD + RotL64(aCross, 41U)) + 980857684690886131U;
            aOrbiterA = (aWandererI + RotL64(aIngress, 35U)) + 6562042345807072665U;
            aOrbiterE = (((aWandererH + RotL64(aCross, 27U)) + RotL64(aCarry, 19U)) + 15665371138706353619U) + aOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = (aWandererB + RotL64(aScatter, 10U)) + 18113013571374375028U;
            aOrbiterH = (aWandererA + RotL64(aIngress, 13U)) + 17405346422601997299U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 5130876096426182506U) + aOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 1813821672299154629U;
            aOrbiterD = RotL64((aOrbiterD * 15478100342425611875U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 15793814882743306728U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 13925299440495476399U;
            aOrbiterF = RotL64((aOrbiterF * 12049601510660117401U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 9924458846049579438U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 7810034662781768090U;
            aOrbiterA = RotL64((aOrbiterA * 10310594595026622513U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 12812586478656872854U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 5709576448057435237U;
            aOrbiterK = RotL64((aOrbiterK * 9101555233909853025U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 7839807649914541516U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 4717944526755429647U;
            aOrbiterC = RotL64((aOrbiterC * 8515229146471335721U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 3933911971504256022U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 4814079680865379831U) ^ aNonceWordP;
            aOrbiterG = RotL64((aOrbiterG * 15100740696230557391U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 18352577312212175569U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 9670612998448920742U) ^ aOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5743579439303300553U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 72737302703035726U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 10032869372369626210U;
            aOrbiterE = RotL64((aOrbiterE * 7449905669249993731U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 2669999453643982386U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 2016129534922291383U;
            aOrbiterH = RotL64((aOrbiterH * 11730911201750754301U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 5108689262300895422U) + aOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 3753457479225942895U;
            aOrbiterJ = RotL64((aOrbiterJ * 11503304711866175497U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 859776381005289485U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 6973892330986118220U) ^ aOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12337041087475258221U), 21U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterG, 26U);
            aIngress = aIngress + (RotL64(aOrbiterF, 39U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterB, 53U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + (RotL64(aOrbiterK, 58U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterI, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aIngress, 23U) + aOrbiterK) + RotL64(aOrbiterJ, 53U)) + aNonceWordL);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 36U) + aOrbiterK) + RotL64(aOrbiterI, 39U)) + aWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aCross, 21U) + aOrbiterE) + RotL64(aOrbiterF, 3U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterH, 35U)) + aOrbiterK);
            aWandererG = aWandererG + (((RotL64(aIngress, 13U) + aOrbiterD) + RotL64(aOrbiterG, 47U)) + RotL64(aCarry, 39U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 47U) + aOrbiterF) + RotL64(aOrbiterA, 19U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 44U) + RotL64(aOrbiterK, 12U)) + aOrbiterA) + aWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterJ, 41U)) + aOrbiterF);
            aWandererH = aWandererH + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterJ, 57U)) + aOrbiterG) + RotL64(aCarry, 51U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterI, 51U)) + aOrbiterC);
            aWandererE = aWandererE + (((RotL64(aIngress, 19U) + aOrbiterI) + RotL64(aOrbiterB, 30U)) + aNonceWordO);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 12U));
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 21U) ^ aWandererA);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 46U));
            aCarry = aCarry + RotL64(aWandererC, 53U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ aNonceWordN;
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 29650U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneB[((aIndex + 31853U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32013U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((aIndex + 28995U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 35U) + RotL64(aCross, 4U)) + (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 21U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (aWandererG + RotL64(aPrevious, 3U)) + 12615321415808640429U;
            aOrbiterG = ((aWandererD + RotL64(aCross, 60U)) + RotL64(aCarry, 37U)) + 15712784676459931207U;
            aOrbiterE = (aWandererI + RotL64(aScatter, 13U)) + 11013335427004930046U;
            aOrbiterI = (aWandererF + RotL64(aIngress, 21U)) + 8298733856304768806U;
            aOrbiterC = ((aWandererK + RotL64(aCross, 53U)) + 6207732959150824216U) + aOrbiterAssignSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = ((aWandererH + RotL64(aIngress, 11U)) + RotL64(aCarry, 19U)) + 9769864876127544038U;
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 57U)) + 10782181918651152563U) + aOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = ((aWandererA + RotL64(aScatter, 41U)) + RotL64(aCarry, 5U)) + 5790454015845620939U;
            aOrbiterF = (aWandererB + RotL64(aCross, 29U)) + 15606578025386733803U;
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 51U)) + 5522352539991175304U) + aNonceWordM;
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 26U)) + 5993355818572869649U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 10864534396947622047U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 12090053126235913528U;
            aOrbiterE = RotL64((aOrbiterE * 7250801471645972261U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 14191181677234981396U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 2258570108233924592U) ^ aOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8307541155393855209U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 8448114811381534603U) + aNonceWordD;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 2702389315763499817U;
            aOrbiterH = RotL64((aOrbiterH * 6710443836432274393U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 17202184076718780200U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 150549910056015002U;
            aOrbiterK = RotL64((aOrbiterK * 195034681254956335U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 4910512055808124967U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 4783477997418403079U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 861977492146512865U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 13842899106208709771U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 7930112618036681468U;
            aOrbiterF = RotL64((aOrbiterF * 8609551859830858419U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 8790107242863198659U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 6882768826643279144U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13745521454063360763U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 12136498871759890015U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 8120456314755584336U;
            aOrbiterJ = RotL64((aOrbiterJ * 1830725195528043575U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 14425711740351183016U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 15907406009196323049U;
            aOrbiterB = RotL64((aOrbiterB * 8599371693260686839U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 4878521420367891861U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 1184672056055028939U;
            aOrbiterG = RotL64((aOrbiterG * 5963961755367831967U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 10126736568567000180U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 12615321415808640429U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11663715449073755137U), 35U);
            //
            aIngress = RotL64(aOrbiterF, 3U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterB, 48U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterG, 43U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 35U));
            aIngress = aIngress + RotL64(aOrbiterK, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aScatter, 39U) + RotL64(aOrbiterB, 47U)) + aOrbiterC);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterA, 41U)) + aOrbiterH) + aWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aPrevious, 26U) + aOrbiterJ) + RotL64(aOrbiterC, 11U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterA, 30U)) + aOrbiterI) + aNonceWordJ);
            aWandererF = aWandererF + (((RotL64(aIngress, 57U) + RotL64(aOrbiterK, 19U)) + aOrbiterJ) + aNonceWordI);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterK, 51U)) + aOrbiterF);
            aWandererB = aWandererB + (((RotL64(aCross, 41U) + RotL64(aOrbiterF, 23U)) + aOrbiterB) + aWandererUpdateSaltA[((aIndex + 16U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterC, 13U)) + aOrbiterE);
            aWandererI = aWandererI + ((((RotL64(aCross, 44U) + aOrbiterD) + RotL64(aOrbiterC, 39U)) + RotL64(aCarry, 13U)) + aNonceWordC);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 51U) + aOrbiterA) + RotL64(aOrbiterC, 58U));
            aWandererG = aWandererG + (((RotL64(aIngress, 3U) + aOrbiterG) + RotL64(aOrbiterD, 35U)) + RotL64(aCarry, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererD, 51U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 30U));
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererF, 13U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = aCarry ^ aNonceWordF;
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

void TwistExpander_Bowling_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xDA7BFF087F7B43C3ULL + 0xE98251F2BB6F3B77ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xFE58EC5364F1E09DULL + 0x8ED2E272EC25BB23ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x8D317B4461DA22B5ULL + 0xFC04F67832B8B08AULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xDB5AA3D19814113FULL + 0xBB75B18DCEEC7B8FULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xDB7A449CEC62038BULL + 0x85DD12E4242DD3B8ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x90DEF58E77B7B08BULL + 0xCB608189188A5480ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xAD05C91223EDEE79ULL + 0x94FAFE9503A15FF8ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x96AD5601F175D14DULL + 0x8FB131021962C19EULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xC8122359476E0925ULL + 0xF19F6B409C065097ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xCC410C433F549EB5ULL + 0xAF1F1043A58E1CD6ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x835675CD3698EC9BULL + 0xF61D58083F45D586ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xD000111AA1B27C6DULL + 0xB47C9F0915F2E1E4ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xF79A3D5C794F2651ULL + 0xAAF6E347D60350E8ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xF9B0BEC7A43A9E09ULL + 0xE13AE6897E743231ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xC7A73DF7B033931DULL + 0x93F4A22080710ABEULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xB1B2D4AE981856B7ULL + 0xFAF4C496DC378E58ULL);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 4772U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1167U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2708U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneA[((aIndex + 8043U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 39U)) + (RotL64(aIngress, 51U) + RotL64(aCross, 26U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (((aWandererG + RotL64(aCross, 19U)) + RotL64(aCarry, 51U)) + 12849591986267890852U) + aNonceWordN;
            aOrbiterE = (aWandererC + RotL64(aIngress, 39U)) + 8232614804696815750U;
            aOrbiterJ = (((aWandererK + RotL64(aPrevious, 51U)) + RotL64(aCarry, 3U)) + 12141567259210877281U) + aNonceWordI;
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 6U)) + 2928641981037885644U) + aOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = (aWandererF + RotL64(aCross, 29U)) + 980733350554783938U;
            aOrbiterK = (aWandererE + RotL64(aScatter, 13U)) + 2683985177993350746U;
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 43U)) + 14532148403815527355U) + aOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = (aWandererA + RotL64(aIngress, 35U)) + 7736296629433884203U;
            aOrbiterG = (((aWandererI + RotL64(aScatter, 24U)) + RotL64(aCarry, 35U)) + 10428437770166310549U) + aNonceWordJ;
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 18327174144859461029U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 6810436935194432002U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2715987179577753597U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 12606153309690753435U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 17123256945895150555U) ^ aNonceWordB;
            aOrbiterK = RotL64((aOrbiterK * 13469111258504672565U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 9057777759026189541U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 16478485918911194442U;
            aOrbiterB = RotL64((aOrbiterB * 11054247078884894131U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 18064460487552100483U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 11477276762421684083U;
            aOrbiterG = RotL64((aOrbiterG * 3886501230380184395U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 18318375441973295081U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 13849305985380030986U;
            aOrbiterH = RotL64((aOrbiterH * 12962140243967824959U), 3U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterG) + 10240409420338313641U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordE;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 18360586077779529086U;
            aOrbiterI = RotL64((aOrbiterI * 18196875422391501927U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 16801797158622424257U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 4950305991208513887U;
            aOrbiterA = RotL64((aOrbiterA * 4437082499761416951U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 15790878572843321918U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 9808781805065559728U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9394280083159162953U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 11974996650410830731U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 4955004489435232515U;
            aOrbiterF = RotL64((aOrbiterF * 13301966529515483085U), 57U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterG, 18U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 23U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 41U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterF, 29U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterE, 34U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aScatter, 11U) + aOrbiterK) + RotL64(aOrbiterB, 48U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterJ, 23U)) + aOrbiterH) + aWandererUpdateSaltD[((aIndex + 16U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aPrevious, 30U) + RotL64(aOrbiterF, 35U)) + aOrbiterG);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterB, 53U)) + aOrbiterF);
            aWandererE = aWandererE + ((RotL64(aScatter, 35U) + RotL64(aOrbiterK, 11U)) + aOrbiterE);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 41U) + aOrbiterI) + RotL64(aOrbiterA, 19U)) + aWandererUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 47U) + aOrbiterJ) + RotL64(aOrbiterK, 44U)) + RotL64(aCarry, 47U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 5U) + aOrbiterE) + RotL64(aOrbiterB, 39U)) + aNonceWordA);
            aWandererG = aWandererG + (((RotL64(aIngress, 22U) + RotL64(aOrbiterI, 29U)) + aOrbiterF) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 48U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 13U));
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererE, 27U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordD);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 16265U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 13833U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 10827U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 11891U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 51U) + RotL64(aCarry, 11U)) + (RotL64(aCross, 39U) ^ RotL64(aIngress, 24U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererA + RotL64(aPrevious, 19U)) + 18087125778766689269U;
            aOrbiterC = ((aWandererF + RotL64(aCross, 5U)) + 13710545066503235196U) + aOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = (((aWandererC + RotL64(aIngress, 35U)) + RotL64(aCarry, 27U)) + 1701939704736254645U) + aOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = ((aWandererH + RotL64(aScatter, 47U)) + 8064093611384019909U) + aNonceWordF;
            aOrbiterH = (aWandererB + RotL64(aIngress, 24U)) + 16623332751533885431U;
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 57U)) + RotL64(aCarry, 51U)) + 15590129153794910109U;
            aOrbiterK = ((aWandererI + RotL64(aCross, 53U)) + RotL64(aCarry, 13U)) + 7413312683079107383U;
            aOrbiterJ = (aWandererJ + RotL64(aScatter, 29U)) + 4186064478651458810U;
            aOrbiterF = (aWandererD + RotL64(aPrevious, 42U)) + 5501191643940735954U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 11064645242200570835U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 13825922087298055833U;
            aOrbiterD = RotL64((aOrbiterD * 7529317892716108867U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 5944980709887369970U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 8181136916070569646U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 395183021205661827U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 15442336949157292482U) + aOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 11580554435240641337U;
            aOrbiterK = RotL64((aOrbiterK * 6654637892858767739U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 11240018128174598322U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 2027565596050777471U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 18048186560314431815U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 16425887196883725233U) + aOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 16828683527588834095U;
            aOrbiterF = RotL64((aOrbiterF * 17746289103235902485U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 9923829146479008804U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 6669171007279929454U;
            aOrbiterI = RotL64((aOrbiterI * 681823450939955099U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 3902430046523165149U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 6739998149289590041U;
            aOrbiterG = RotL64((aOrbiterG * 2675037435528416821U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 16014401255534234075U) + aNonceWordI;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 14741857638680634564U;
            aOrbiterA = RotL64((aOrbiterA * 8723611021403369393U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 5064807861673260054U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 968747317273200299U;
            aOrbiterC = RotL64((aOrbiterC * 14122304002722582329U), 53U);
            //
            aIngress = RotL64(aOrbiterJ, 44U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 41U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 19U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 51U));
            aIngress = aIngress + RotL64(aOrbiterF, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aCross, 41U) + aOrbiterF) + RotL64(aOrbiterD, 19U)) + aNonceWordO);
            aWandererC = aWandererC + ((RotL64(aIngress, 22U) + RotL64(aOrbiterH, 53U)) + aOrbiterF);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterJ, 6U)) + aOrbiterG);
            aWandererI = aWandererI + ((RotL64(aScatter, 37U) + RotL64(aOrbiterI, 43U)) + aOrbiterJ);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 51U) + aOrbiterJ) + RotL64(aOrbiterH, 29U));
            aWandererF = aWandererF + (((RotL64(aScatter, 58U) + aOrbiterA) + RotL64(aOrbiterJ, 23U)) + RotL64(aCarry, 37U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 35U)) + aOrbiterG);
            aWandererA = aWandererA + ((((RotL64(aCross, 13U) + RotL64(aOrbiterK, 60U)) + aOrbiterF) + RotL64(aCarry, 51U)) + aWandererUpdateSaltE[((aIndex + 26U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 47U) + aOrbiterG) + RotL64(aOrbiterC, 47U)) + aWandererUpdateSaltC[((aIndex + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererI);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 41U));
            aCarry = aCarry + RotL64(aWandererB, 27U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordI);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 23076U)) & S_BLOCK1], 18U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 20394U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 20038U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneC[((aIndex + 16744U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aPrevious, 22U)) + (RotL64(aIngress, 37U) ^ RotL64(aCross, 5U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((aWandererF + RotL64(aCross, 47U)) + 18319689184146942855U) + aNonceWordK;
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 56U)) + RotL64(aCarry, 51U)) + 8041304130090501019U;
            aOrbiterD = (aWandererB + RotL64(aScatter, 13U)) + 11347064191990897738U;
            aOrbiterB = (aWandererK + RotL64(aIngress, 43U)) + 15242243470024447468U;
            aOrbiterA = (((aWandererG + RotL64(aPrevious, 5U)) + 10619749107163611105U) + aOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordP;
            aOrbiterE = ((aWandererE + RotL64(aScatter, 51U)) + RotL64(aCarry, 37U)) + 14795614276221947128U;
            aOrbiterI = (((aWandererI + RotL64(aCross, 38U)) + 1578095288886372393U) + aOrbiterAssignSaltB[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordD;
            aOrbiterH = ((aWandererA + RotL64(aIngress, 27U)) + RotL64(aCarry, 29U)) + 13593906305770501684U;
            aOrbiterC = (aWandererC + RotL64(aPrevious, 21U)) + 8919815528334599172U;
            //
            aOrbiterF = (((aOrbiterF + aOrbiterG) + 17425548324720065145U) + aOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1]) + aNonceWordF;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 11125018338392347335U) ^ aNonceWordJ;
            aOrbiterD = RotL64((aOrbiterD * 4377887040461528587U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 3779189180734244399U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 10958224663276134041U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6206963519509783781U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 4317305352561612995U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 4891139433808505355U;
            aOrbiterB = RotL64((aOrbiterB * 11507024985663120317U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 5166074784835930965U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 10080890270621589202U;
            aOrbiterG = RotL64((aOrbiterG * 13170894418184288695U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 4501071771615514619U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 6486573807774431753U;
            aOrbiterA = RotL64((aOrbiterA * 324029625116648669U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 15714881857668975753U) + aOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 3506619392820235900U;
            aOrbiterE = RotL64((aOrbiterE * 5707033870161224499U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 5295711072762443783U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 11192836530396570648U;
            aOrbiterI = RotL64((aOrbiterI * 4361810118382207039U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 7993389678399774574U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 12551394763541226695U;
            aOrbiterH = RotL64((aOrbiterH * 11903486656172026403U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 11553674370322129668U) + aNonceWordC;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 4459881583199320245U;
            aOrbiterC = RotL64((aOrbiterC * 2805857426321555685U), 23U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterD, 3U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 37U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 54U));
            aIngress = aIngress + (RotL64(aOrbiterI, 11U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterA, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aIngress, 47U) + aOrbiterC) + RotL64(aOrbiterB, 12U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 14U) + aOrbiterE) + RotL64(aOrbiterG, 5U)) + aWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterG, 23U)) + aOrbiterF) + RotL64(aCarry, 47U)) + aNonceWordH);
            aWandererC = aWandererC ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterB, 27U)) + aOrbiterA);
            aWandererB = aWandererB + (((RotL64(aIngress, 23U) + aOrbiterC) + RotL64(aOrbiterE, 60U)) + RotL64(aCarry, 11U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 5U) + aOrbiterD) + RotL64(aOrbiterF, 51U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 41U) + aOrbiterA) + RotL64(aOrbiterI, 39U));
            aWandererG = aWandererG ^ ((((RotL64(aScatter, 10U) + aOrbiterI) + RotL64(aOrbiterE, 35U)) + aNonceWordE) + aWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aIngress, 53U) + aOrbiterH) + RotL64(aOrbiterC, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 52U) ^ aWandererG);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererA);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + RotL64(aWandererC, 57U);
            aCarry = aCarry + RotL64(aIngress, 10U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordM);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 28274U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneB[((aIndex + 26191U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25527U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((aIndex + 26580U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCarry, 13U)) ^ (RotL64(aCross, 28U) ^ RotL64(aPrevious, 57U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererE + RotL64(aPrevious, 19U)) + 4848316479321533394U;
            aOrbiterC = ((aWandererF + RotL64(aCross, 47U)) + 6919360256662636195U) + aNonceWordG;
            aOrbiterB = ((aWandererB + RotL64(aScatter, 23U)) + RotL64(aCarry, 21U)) + 9897013582181108544U;
            aOrbiterF = (aWandererJ + RotL64(aIngress, 42U)) + 7319353809896158678U;
            aOrbiterD = (((aWandererC + RotL64(aPrevious, 5U)) + RotL64(aCarry, 41U)) + 2848175435514849859U) + aOrbiterAssignSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterE = (aWandererG + RotL64(aIngress, 37U)) + 6967780718720437934U;
            aOrbiterA = (aWandererA + RotL64(aCross, 51U)) + 10143884766603388136U;
            aOrbiterH = (aWandererI + RotL64(aScatter, 11U)) + 8675965006150972051U;
            aOrbiterJ = ((((aWandererK + RotL64(aIngress, 60U)) + RotL64(aCarry, 11U)) + 16350117755560994281U) + aOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1]) + aNonceWordE;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 17976597517118423760U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 1399631141355370237U;
            aOrbiterB = RotL64((aOrbiterB * 16537788276543236833U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 3590613762034716792U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 5134624314245932157U;
            aOrbiterD = RotL64((aOrbiterD * 13077589037975283371U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 10082236952942943654U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 4015535035905433450U;
            aOrbiterA = RotL64((aOrbiterA * 4961808568701908559U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 611474103801573800U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 5786708483794098001U;
            aOrbiterI = RotL64((aOrbiterI * 7694007039340089267U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 5201943497363274455U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 9282160506938328489U;
            aOrbiterF = RotL64((aOrbiterF * 5368182164239021367U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 4932320527498940158U) + aOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 11576526341731392916U;
            aOrbiterE = RotL64((aOrbiterE * 1712051774729439363U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 10790691517638887125U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 16280649213607464422U) ^ aOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10756733801499471873U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 9553716940667712810U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 11827518270964003341U;
            aOrbiterJ = RotL64((aOrbiterJ * 1322489827908132831U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 16777463701235809321U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 3375489084588454149U) ^ aNonceWordF;
            aOrbiterC = RotL64((aOrbiterC * 3335010977457647307U), 41U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterE, 21U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 54U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 13U));
            aIngress = aIngress + RotL64(aOrbiterC, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aIngress, 47U) + aOrbiterI) + RotL64(aOrbiterB, 58U)) + aNonceWordH);
            aWandererA = aWandererA ^ ((RotL64(aCross, 19U) + aOrbiterH) + RotL64(aOrbiterD, 19U));
            aWandererG = aWandererG + (((RotL64(aScatter, 60U) + RotL64(aOrbiterJ, 5U)) + aOrbiterC) + aWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterE, 41U)) + aOrbiterA) + aWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 51U) + aOrbiterJ) + RotL64(aOrbiterA, 47U)) + aNonceWordN);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 39U) + aOrbiterJ) + RotL64(aOrbiterD, 24U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 56U) + aOrbiterI) + RotL64(aOrbiterC, 51U)) + RotL64(aCarry, 53U)) + aNonceWordA);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 29U) + aOrbiterD) + RotL64(aOrbiterA, 37U));
            aWandererE = aWandererE + (((RotL64(aCross, 13U) + aOrbiterF) + RotL64(aOrbiterI, 13U)) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 60U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 5U));
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 23U));
            aCarry = aCarry + RotL64(aWandererA, 19U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordH);
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

void TwistExpander_Bowling_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xBC32BC342C6FBD65ULL + 0xE549D62580D8AECDULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x8CA03B542C9B8AF5ULL + 0x934B3CFC96E200D1ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x845AE0499EC2BBE7ULL + 0x836290794D907362ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xEC85A3A00515BF9DULL + 0x92A33FD6F5C53F73ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xFEC48C48FCD9D827ULL + 0xA3F342905FF8322DULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xAE642B32BBED78EBULL + 0xE70C1638E68A0E8BULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xC0747CBE1F501407ULL + 0xD6BC73B15211B1CEULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xD45D40F32449E827ULL + 0xDF508800F91EB5DDULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xB6CE78626CA9A00BULL + 0x9C7A825FD1E86FDFULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x82942B0039C12EE1ULL + 0xCDD299378B8387EBULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xF042EB368C3E04F1ULL + 0xA26BE4DC6D9A1F6CULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xACF3F9FEDC5FB5EFULL + 0xBF2C149621878DDEULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xA04DD1AFF8C28223ULL + 0xB47E753370D63192ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xD8FB617012ACF427ULL + 0xD0287DEBBF8A994AULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xDE6D6A9958AE73EBULL + 0x8FE66D60375D7D6EULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xA32D0E935EB6B471ULL + 0x99EE3BB805622BAAULL);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 6594U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 3004U)) & S_BLOCK1], 44U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 113U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneA[((aIndex + 1111U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 19U) + RotL64(aIngress, 6U)) ^ (RotL64(aCross, 35U) ^ RotL64(aPrevious, 47U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (((aWandererF + RotL64(aPrevious, 53U)) + RotL64(aCarry, 51U)) + 13442819395490639310U) + aNonceWordP;
            aOrbiterH = ((aWandererI + RotL64(aScatter, 29U)) + RotL64(aCarry, 39U)) + 8187292523194120936U;
            aOrbiterD = (aWandererA + RotL64(aIngress, 5U)) + 11469697159823131388U;
            aOrbiterG = ((aWandererK + RotL64(aCross, 38U)) + 13414083692375929653U) + aOrbiterAssignSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterE = ((((aWandererG + RotL64(aIngress, 21U)) + RotL64(aCarry, 3U)) + 11404010733687907517U) + aOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordG;
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 6783212827186218247U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 8561131439340372614U) ^ aOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7426867125542470683U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 6252609642004429113U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 12804867444200448952U;
            aOrbiterI = RotL64((aOrbiterI * 3114688959081972615U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 2739648749603690781U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 14808861217017399752U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 373911885694012101U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 17588866502571268888U) + aNonceWordH;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 5882260142735642980U) ^ aOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7688252946143263869U), 47U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterG) + 15493099088132862949U) + aOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1]) + aNonceWordK;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 5175647411532429582U;
            aOrbiterE = RotL64((aOrbiterE * 15226544495598541883U), 37U);
            //
            aIngress = RotL64(aOrbiterG, 29U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterH, 19U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterD, 40U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterG, 13U)) + aOrbiterI);
            aWandererG = aWandererG + (((RotL64(aCross, 3U) + aOrbiterD) + RotL64(aOrbiterI, 48U)) + RotL64(aCarry, 29U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterE, 21U)) + aOrbiterI) + aWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererI = aWandererI + (((((RotL64(aIngress, 26U) + RotL64(aOrbiterH, 57U)) + aOrbiterE) + RotL64(aCarry, 47U)) + aNonceWordB) + aWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterE, 39U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererK, 21U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererA, 58U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordP);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 15350U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 10616U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 15149U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 14777U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 34U) ^ RotL64(aCarry, 3U)) + (RotL64(aPrevious, 19U) ^ RotL64(aCross, 53U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (((aWandererE + RotL64(aIngress, 19U)) + RotL64(aCarry, 19U)) + 15549114274303128055U) + aOrbiterAssignSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = ((aWandererD + RotL64(aCross, 44U)) + 16466750056388063241U) + aNonceWordP;
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 53U)) + RotL64(aCarry, 5U)) + 12209449840836787142U;
            aOrbiterH = ((aWandererA + RotL64(aScatter, 5U)) + RotL64(aCarry, 35U)) + 14551496099734294336U;
            aOrbiterF = ((aWandererB + RotL64(aIngress, 29U)) + 6266576428679808622U) + aOrbiterAssignSaltA[((aIndex + 22U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 16892841575635668152U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 7375966221423362125U;
            aOrbiterD = RotL64((aOrbiterD * 15338878556107177587U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 11926105302821753530U) + aOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 16219253791550461124U;
            aOrbiterF = RotL64((aOrbiterF * 2117550758226173419U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 7299056065319248160U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 15234001484933728439U) ^ aNonceWordD;
            aOrbiterB = RotL64((aOrbiterB * 8182244796017018911U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 6615802589932632120U) + aOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 5481176858895819247U;
            aOrbiterK = RotL64((aOrbiterK * 3604590158551984877U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 17220507586542139380U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 14137921473739415340U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10634645686035907603U), 35U);
            //
            aIngress = RotL64(aOrbiterK, 6U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 19U));
            aIngress = aIngress + RotL64(aOrbiterB, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((((RotL64(aScatter, 56U) + RotL64(aOrbiterD, 37U)) + aOrbiterF) + RotL64(aCarry, 21U)) + aNonceWordE) + aWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterB, 5U)) + aOrbiterK);
            aWandererB = aWandererB + (((RotL64(aCross, 41U) + RotL64(aOrbiterH, 57U)) + aOrbiterK) + aNonceWordL);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterB, 24U)) + aOrbiterF) + aWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aCross, 11U) + aOrbiterK) + RotL64(aOrbiterF, 13U)) + RotL64(aCarry, 53U)) + aNonceWordN);
            //
            aCarry = aCarry + (RotL64(aWandererB, 53U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererD, 29U);
            aCarry = aCarry + RotL64(aIngress, 44U);
            aCarry = aCarry ^ aNonceWordF;
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 19626U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((aIndex + 21734U)) & S_BLOCK1], 30U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 21695U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 19470U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aPrevious, 38U)) ^ (RotL64(aIngress, 5U) ^ RotL64(aCarry, 23U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 29U)) + RotL64(aCarry, 37U)) + 9630214189402543339U;
            aOrbiterB = (((aWandererA + RotL64(aScatter, 57U)) + RotL64(aCarry, 11U)) + 4072576573737526819U) + aOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = (((aWandererI + RotL64(aCross, 37U)) + RotL64(aCarry, 51U)) + 15994787452709618869U) + aOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 3U)) + 6403240137132259482U) + aNonceWordB;
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 46U)) + 10229266900170507720U) + aNonceWordO;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 5025294577989748989U) + aNonceWordM;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 16696461238217956883U;
            aOrbiterI = RotL64((aOrbiterI * 15993828976234917577U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 9878318855341719119U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 16086635438116177346U) ^ aOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5585682357395705671U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 12295437783084203730U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = (((aOrbiterE ^ aOrbiterF) ^ 7681150419912842402U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterE = RotL64((aOrbiterE * 7289497379725191451U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 2639104034287637448U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 12298170009332243573U) ^ aNonceWordA;
            aOrbiterA = RotL64((aOrbiterA * 9397919591171238575U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 3485932317267669626U) + aOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 16569551670038752475U;
            aOrbiterF = RotL64((aOrbiterF * 8139802826402217631U), 57U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterB, 12U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + RotL64(aOrbiterE, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aPrevious, 4U) + aOrbiterB) + RotL64(aOrbiterE, 47U)) + aNonceWordH);
            aWandererA = aWandererA ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterI, 13U)) + aOrbiterA);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 21U) + aOrbiterI) + RotL64(aOrbiterF, 60U)) + RotL64(aCarry, 11U)) + aWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 43U) + aOrbiterB) + RotL64(aOrbiterI, 35U)) + aWandererUpdateSaltE[((aIndex + 8U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 35U) + RotL64(aOrbiterA, 27U)) + aOrbiterF) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 46U) ^ aWandererA);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ aNonceWordG;
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 32455U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27155U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 29263U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneD[((aIndex + 24929U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 41U) ^ RotL64(aIngress, 53U)) + (RotL64(aPrevious, 27U) ^ RotL64(aCross, 10U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (aWandererH + RotL64(aScatter, 41U)) + 9023059520606551446U;
            aOrbiterF = (((aWandererE + RotL64(aCross, 27U)) + RotL64(aCarry, 47U)) + 662441755115638133U) + aOrbiterAssignSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = ((((aWandererG + RotL64(aPrevious, 56U)) + RotL64(aCarry, 11U)) + 16957253361196144712U) + aOrbiterAssignSaltB[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordB;
            aOrbiterE = ((aWandererF + RotL64(aIngress, 5U)) + RotL64(aCarry, 29U)) + 7840955025765308605U;
            aOrbiterJ = (aWandererC + RotL64(aScatter, 13U)) + 346855809270395799U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 16099139781586668343U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 3706457327118322098U;
            aOrbiterB = RotL64((aOrbiterB * 7810030620470889591U), 3U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterJ) + 12166825885547622870U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordP;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 7792658665720344200U) ^ aOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16305542632794270697U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 7128477606152986326U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 11116533962780290084U;
            aOrbiterE = RotL64((aOrbiterE * 11993485572912492297U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 10443889548568288532U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 4402387036946561017U;
            aOrbiterF = RotL64((aOrbiterF * 9032964741841833277U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 13002706161178447654U) + aOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 13929727277530310708U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7005639090871200285U), 51U);
            //
            aIngress = RotL64(aOrbiterJ, 57U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterF, 37U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterB, 10U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterF, 19U)) + aOrbiterH) + RotL64(aCarry, 43U)) + aWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterE, 27U)) + aOrbiterB) + aWandererUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aScatter, 22U) + aOrbiterF) + RotL64(aOrbiterB, 5U)) + RotL64(aCarry, 23U)) + aNonceWordH);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterE, 48U)) + aOrbiterJ) + aNonceWordE);
            aWandererF = aWandererF + (((RotL64(aIngress, 47U) + aOrbiterE) + RotL64(aOrbiterH, 37U)) + aNonceWordN);
            //
            aCarry = aCarry + (RotL64(aWandererC, 58U) ^ aWandererG);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 37U));
            aCarry = aCarry + RotL64(aWandererE, 3U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordB);
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

void TwistExpander_Bowling_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xFB5D6F4A8734D3FBULL + 0xEF8BB96E05AA25DBULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xAFFAFA03B8BBCE23ULL + 0x89E82F0EA31997FBULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x81B2EB996B3214F1ULL + 0xB169178AE4EFFE76ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xB689709FA7D457E3ULL + 0xCAF93B6D5330F7CFULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xC42F70F276D82BF3ULL + 0xC31BBB887D1313EDULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xBF3753B8A8D9A92FULL + 0xC26AF8650710CD31ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xCD25ED9718C7C987ULL + 0xC37550E3C2EF0A21ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x9BCC4A9508AFB7A5ULL + 0xA1B3D29FBDE2B324ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xB2AFCE90C1F24691ULL + 0xF4EEA8B11BFBB80EULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x8B444A3F69FCEE21ULL + 0xF5D2E428BD87600AULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xA5AB9C7EADC1CE05ULL + 0xCE88E5EBB9A23748ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xECEB847C9BF46A51ULL + 0xD664A0F45597E331ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xDD04929123A2658FULL + 0x971C04EFB3529C91ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xDF9C05AF7B1FF0D9ULL + 0x945C92313CC4D000ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xE90CD07033233EABULL + 0x861267B0E0DEC9F9ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xD0739D56570C3361ULL + 0xA972A6D186561C2AULL);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 4765U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneC[((aIndex + 4491U)) & S_BLOCK1], 36U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 5492U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 3297U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 19U) ^ RotL64(aPrevious, 50U)) ^ (RotL64(aIngress, 3U) + RotL64(aCarry, 37U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (aWandererB + RotL64(aPrevious, 43U)) + 7722279280863371124U;
            aOrbiterC = (aWandererC + RotL64(aScatter, 19U)) + 11584220561732385598U;
            aOrbiterA = ((((aWandererD + RotL64(aCross, 11U)) + RotL64(aCarry, 13U)) + 7834679350105534657U) + aOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 3U)) + RotL64(aCarry, 51U)) + 11347994382444180879U;
            aOrbiterK = (((aWandererF + RotL64(aScatter, 27U)) + 9449903188047063431U) + aOrbiterAssignSaltB[((aIndex + 10U)) & S_SALT1]) + aNonceWordO;
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 58U)) + RotL64(aCarry, 35U)) + 6516243976652795170U;
            aOrbiterI = (aWandererH + RotL64(aCross, 35U)) + 8420815253991184777U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 9081386852515170937U) + aNonceWordG;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 14375955191735286867U;
            aOrbiterA = RotL64((aOrbiterA * 2772840314542262283U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 880757589768436072U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 3349856625725164229U;
            aOrbiterK = RotL64((aOrbiterK * 681514212582331781U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 7826309957607577207U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 8057435761214313635U) ^ aOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4718430712767038607U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 9565237500443303103U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 15893066735310588501U;
            aOrbiterI = RotL64((aOrbiterI * 8457633439171452397U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 3276844534476430842U) + aOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 6828644383891274120U;
            aOrbiterD = RotL64((aOrbiterD * 979580351653410157U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 2815676923011504251U) + aNonceWordF;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 5030251870850928417U;
            aOrbiterJ = RotL64((aOrbiterJ * 7075653570570819253U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 13464083008377887034U) + aOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 8994560761846897590U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9892839554658865143U), 57U);
            //
            aIngress = RotL64(aOrbiterJ, 43U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterI, 19U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 11U));
            aIngress = aIngress + RotL64(aOrbiterK, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aIngress, 28U) + RotL64(aOrbiterI, 43U)) + aOrbiterC) + RotL64(aCarry, 35U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 57U) + aOrbiterJ) + RotL64(aOrbiterB, 35U)) + aWandererUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aScatter, 19U) + RotL64(aOrbiterA, 29U)) + aOrbiterI) + RotL64(aCarry, 13U)) + aWandererUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterC, 57U)) + aOrbiterB) + aNonceWordN);
            aWandererI = aWandererI + ((RotL64(aPrevious, 47U) + aOrbiterJ) + RotL64(aOrbiterK, 12U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterD, 51U)) + aOrbiterA);
            aWandererC = aWandererC + ((RotL64(aScatter, 3U) + aOrbiterB) + RotL64(aOrbiterA, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 10U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ aNonceWordH;
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 15345U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 9965U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 12706U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneB[((aIndex + 16305U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 51U) + RotL64(aCarry, 37U)) ^ (RotL64(aCross, 3U) + RotL64(aPrevious, 20U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererB + RotL64(aScatter, 13U)) + 15383045568644941552U;
            aOrbiterF = ((((aWandererG + RotL64(aCross, 19U)) + RotL64(aCarry, 21U)) + 17452811657750910067U) + aOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1]) + aNonceWordD;
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 39U)) + 15660117718455155603U) + aOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = (aWandererI + RotL64(aIngress, 60U)) + 10396441207743665753U;
            aOrbiterJ = (aWandererH + RotL64(aCross, 51U)) + 3708971058200841442U;
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 29U)) + RotL64(aCarry, 3U)) + 7000673057768598750U;
            aOrbiterG = ((aWandererF + RotL64(aIngress, 5U)) + RotL64(aCarry, 41U)) + 9886354469011131596U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 16018065329058043467U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 5024756166109352320U;
            aOrbiterC = RotL64((aOrbiterC * 11660932185479046483U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 6587818720728886652U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 3652672354944162319U;
            aOrbiterI = RotL64((aOrbiterI * 10807121230791716109U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 6307315649915348048U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 16405347331742979258U;
            aOrbiterE = RotL64((aOrbiterE * 7183142442906743699U), 11U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterG) + 5427299664054601957U) + aOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1]) + aNonceWordG;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 4983381733483185898U;
            aOrbiterF = RotL64((aOrbiterF * 14646556236306407673U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 10182995521328377487U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 8694282877540593550U) ^ aOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14614602561910403893U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 4085927978153269932U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 6176195962815240877U;
            aOrbiterH = RotL64((aOrbiterH * 16792916528959579875U), 57U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterE) + 6966742100601433005U) + aOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1]) + aNonceWordF;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 9920952446921247521U;
            aOrbiterG = RotL64((aOrbiterG * 1879821050131820933U), 35U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterG, 3U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + (RotL64(aOrbiterH, 46U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterC, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aPrevious, 23U) + aOrbiterG) + RotL64(aOrbiterC, 57U)) + RotL64(aCarry, 29U)) + aWandererUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 57U) + aOrbiterF) + RotL64(aOrbiterJ, 13U)) + aNonceWordB);
            aWandererH = aWandererH + (((RotL64(aCross, 3U) + RotL64(aOrbiterI, 23U)) + aOrbiterG) + RotL64(aCarry, 43U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterJ, 48U)) + aOrbiterH);
            aWandererD = aWandererD + (((RotL64(aIngress, 51U) + aOrbiterG) + RotL64(aOrbiterH, 39U)) + aWandererUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 11U) + aOrbiterE) + RotL64(aOrbiterJ, 29U));
            aWandererG = aWandererG + ((RotL64(aScatter, 44U) + RotL64(aOrbiterE, 3U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 34U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 27U));
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ aNonceWordH;
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 22188U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22940U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 21278U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 18574U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aPrevious, 40U)) + (RotL64(aCarry, 21U) ^ RotL64(aIngress, 57U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = ((aWandererA + RotL64(aCross, 27U)) + RotL64(aCarry, 47U)) + 13278949403988203974U;
            aOrbiterJ = (((aWandererF + RotL64(aScatter, 39U)) + 9213599924054673756U) + aOrbiterAssignSaltA[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordE;
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 48U)) + RotL64(aCarry, 35U)) + 1255746482932381798U;
            aOrbiterG = (aWandererK + RotL64(aIngress, 19U)) + 11575321997144516122U;
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 11U)) + 15881587525529432437U) + aOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = ((aWandererC + RotL64(aIngress, 57U)) + RotL64(aCarry, 11U)) + 9846195809864862707U;
            aOrbiterD = (aWandererI + RotL64(aPrevious, 5U)) + 12319815691858217670U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 16322617427294439587U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 16332130810525887437U;
            aOrbiterK = RotL64((aOrbiterK * 7588076439690559343U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 4920951156015336794U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 16767126455124552329U;
            aOrbiterJ = RotL64((aOrbiterJ * 4440352337076842603U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 12553595911087945223U) + aNonceWordF;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 1437522202135436142U;
            aOrbiterE = RotL64((aOrbiterE * 2001992794165550905U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 12313100454852227143U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 2761983020631055729U;
            aOrbiterG = RotL64((aOrbiterG * 3874839760378039509U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 17635303588421554367U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 788212489507463763U) ^ aOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 17896475584538528059U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 5192552894670654434U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 6784748488807738811U;
            aOrbiterF = RotL64((aOrbiterF * 8077237651953896479U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 16113417046719114943U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 1096874945215225916U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17308604412622879833U), 19U);
            //
            aIngress = RotL64(aOrbiterF, 19U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + (RotL64(aOrbiterE, 51U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aScatter, 51U) + RotL64(aOrbiterH, 41U)) + aOrbiterE) + RotL64(aCarry, 5U)) + aWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((((RotL64(aCross, 11U) + RotL64(aOrbiterD, 3U)) + aOrbiterH) + aNonceWordP) + aWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 58U) + RotL64(aOrbiterF, 21U)) + aOrbiterH) + RotL64(aCarry, 47U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterF, 13U)) + aOrbiterG);
            aWandererC = aWandererC + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterK, 34U)) + aOrbiterE);
            aWandererK = aWandererK ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterD, 47U)) + aOrbiterF) + aNonceWordG);
            aWandererA = aWandererA + (((RotL64(aScatter, 27U) + aOrbiterE) + RotL64(aOrbiterJ, 53U)) + aNonceWordH);
            //
            aCarry = aCarry + (RotL64(aWandererI, 12U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererE);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 27U));
            aCarry = aCarry + RotL64(aWandererK, 35U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordK);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 28324U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28565U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24753U)) & S_BLOCK1], 40U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 25574U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 19U) + RotL64(aPrevious, 51U)) ^ (RotL64(aIngress, 5U) ^ RotL64(aCarry, 34U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((aWandererD + RotL64(aIngress, 3U)) + RotL64(aCarry, 5U)) + 14499676118633326000U;
            aOrbiterB = ((aWandererH + RotL64(aScatter, 57U)) + 17191273593018552288U) + aNonceWordF;
            aOrbiterA = ((aWandererE + RotL64(aCross, 41U)) + 4085176294948097737U) + aOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 13U)) + RotL64(aCarry, 37U)) + 11112671474158908186U;
            aOrbiterG = (((aWandererC + RotL64(aScatter, 35U)) + RotL64(aCarry, 23U)) + 8745787969012266485U) + aOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 50U)) + 18074049663777707948U) + aNonceWordD;
            aOrbiterD = (aWandererG + RotL64(aIngress, 21U)) + 2543758649719164688U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 4659584749412700523U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 974639159259871273U;
            aOrbiterA = RotL64((aOrbiterA * 17918719351847605523U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 9211220687971081987U) + aNonceWordJ;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 8567024626862182714U;
            aOrbiterF = RotL64((aOrbiterF * 7755874089832496393U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 5803002132294840900U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 11968489432878148467U;
            aOrbiterB = RotL64((aOrbiterB * 4501441062617123165U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 9470807228394903442U) + aOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 1692347973120388469U) ^ aOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17433393164156231575U), 57U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterD) + 16510815732690193145U) + aOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1]) + aNonceWordH;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 755159406833096510U;
            aOrbiterH = RotL64((aOrbiterH * 14091736464659561165U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 1518824876475937620U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 701225390867330446U;
            aOrbiterJ = RotL64((aOrbiterJ * 12264618860580199927U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 8425976693733003889U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 7182176375442410367U;
            aOrbiterD = RotL64((aOrbiterD * 8860605703761731859U), 41U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterD, 19U);
            aIngress = aIngress + (RotL64(aOrbiterA, 35U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterB, 51U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterF, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aCross, 51U) + aOrbiterJ) + RotL64(aOrbiterB, 53U)) + RotL64(aCarry, 11U)) + aNonceWordG);
            aWandererE = aWandererE ^ ((((RotL64(aIngress, 35U) + aOrbiterG) + RotL64(aOrbiterF, 12U)) + aNonceWordM) + aWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 21U) + RotL64(aOrbiterH, 47U)) + aOrbiterD) + RotL64(aCarry, 57U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterB, 37U)) + aOrbiterA);
            aWandererH = aWandererH + (((RotL64(aScatter, 43U) + aOrbiterJ) + RotL64(aOrbiterF, 27U)) + aWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 14U) + RotL64(aOrbiterG, 21U)) + aOrbiterJ);
            aWandererD = aWandererD + ((RotL64(aPrevious, 3U) + aOrbiterD) + RotL64(aOrbiterB, 3U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererF);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 53U));
            aCarry = aCarry + RotL64(aWandererC, 34U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ aNonceWordO;
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

void TwistExpander_Bowling_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xD0F2C09580F9DCB1ULL + 0xC32C13A8415EB765ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xFBF6D1EF2148A551ULL + 0xEAD4625198E35DC0ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xAA1932570C1AF933ULL + 0x82FE4523E3F4A25DULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x895760318974FCA3ULL + 0xA3631AD0FDD93653ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x92673BE3A41D52C9ULL + 0x8A0305EFD5E52832ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xF7F15478879E9A79ULL + 0x89238FF298B3279EULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x9F552FE92C696DB7ULL + 0xF8B143A17A6BE55FULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xE0D24C72A9DDAC2DULL + 0x9CCF252944C3267DULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xE415869E4BD1515BULL + 0x8B20F5ACFA32939DULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xB0FE581126D02D2DULL + 0xC4B31F50FAEF796CULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xA1E9E6F1DF0FDF21ULL + 0x8D5B232BF7FA97ECULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xB52311B70FA0E859ULL + 0xD5427AF053DABF91ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x84F6A7586E6306ADULL + 0xA88E17E91F87B2CBULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x870D6F9C96ABE561ULL + 0xEBB5624071971D72ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xD503F8936A93D4DFULL + 0x895EAA38122F2F32ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xECB17B5F36F969C5ULL + 0xC4FDFBC661D7C335ULL);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 753U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 4519U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 4668U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((aIndex + 2530U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aPrevious, 42U)) ^ (RotL64(aIngress, 29U) + RotL64(aCarry, 13U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((aWandererI + RotL64(aCross, 43U)) + 2101601659597850213U) + aNonceWordI;
            aOrbiterK = (((aWandererK + RotL64(aPrevious, 5U)) + RotL64(aCarry, 53U)) + 2759794072560720121U) + aOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = ((aWandererG + RotL64(aIngress, 51U)) + RotL64(aCarry, 5U)) + 9443562552411269339U;
            aOrbiterG = ((aWandererE + RotL64(aScatter, 18U)) + 10801360546699857975U) + aOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = ((aWandererB + RotL64(aCross, 11U)) + RotL64(aCarry, 29U)) + 8020716394829332019U;
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 37U)) + 1021894212367773801U) + aNonceWordK;
            aOrbiterF = ((aWandererH + RotL64(aScatter, 27U)) + 13346855534622490176U) + aNonceWordO;
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 16359309548462953836U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 12642446944680783519U;
            aOrbiterH = RotL64((aOrbiterH * 12197935153255283321U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 8197424982767553380U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 14346334610901859094U;
            aOrbiterE = RotL64((aOrbiterE * 16982899923227935679U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 14171304260534233539U) + aNonceWordL;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 334531601308283605U) ^ aOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5012968232749075075U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 10707856298471572695U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 18364775750091914766U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15735143943129143265U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 8531394793118363836U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 15352876929406908882U;
            aOrbiterD = RotL64((aOrbiterD * 475199047053777179U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 567682016232278157U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 2068146551757663119U) ^ aOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1557877740957797555U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 7776122587613256525U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 16430938890724272256U) ^ aOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4540270493783593257U), 5U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterG, 57U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 19U));
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterD, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((((RotL64(aIngress, 11U) + aOrbiterH) + RotL64(aOrbiterG, 3U)) + RotL64(aCarry, 41U)) + aNonceWordD) + aWandererUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterA, 41U)) + aOrbiterD);
            aWandererI = aWandererI + (((RotL64(aScatter, 35U) + RotL64(aOrbiterG, 47U)) + aOrbiterA) + aNonceWordB);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 47U) + aOrbiterF) + RotL64(aOrbiterG, 53U));
            aWandererH = aWandererH + ((((RotL64(aScatter, 54U) + RotL64(aOrbiterE, 29U)) + aOrbiterK) + RotL64(aCarry, 5U)) + aNonceWordG);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 41U) + aOrbiterH) + RotL64(aOrbiterF, 18U)) + aWandererUpdateSaltC[((aIndex + 14U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aCross, 5U) + aOrbiterA) + RotL64(aOrbiterK, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 14U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererE, 53U) ^ aWandererK);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 41U));
            aCarry = aCarry + RotL64(aWandererB, 3U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordC);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 8823U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneD[((aIndex + 13022U)) & S_BLOCK1], 34U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 15696U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 12777U)) & S_BLOCK1], 40U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 3U) + RotL64(aCarry, 23U)) + (RotL64(aPrevious, 52U) ^ RotL64(aCross, 35U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererK + RotL64(aScatter, 11U)) + 11274974230580265396U;
            aOrbiterF = ((aWandererB + RotL64(aCross, 60U)) + RotL64(aCarry, 5U)) + 16658438747342741547U;
            aOrbiterC = (aWandererE + RotL64(aIngress, 47U)) + 16612986966106053844U;
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 3U)) + 9329502236843231290U) + aOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = ((aWandererF + RotL64(aScatter, 29U)) + RotL64(aCarry, 39U)) + 14088261356708344656U;
            aOrbiterB = ((aWandererI + RotL64(aCross, 53U)) + 13692608802007789581U) + aOrbiterAssignSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterA = (((aWandererA + RotL64(aIngress, 35U)) + RotL64(aCarry, 27U)) + 6824473946645682398U) + aNonceWordL;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 2072915876348570040U) + aNonceWordG;
            aOrbiterC = (((aOrbiterC ^ aOrbiterJ) ^ 7420507753044460759U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterC = RotL64((aOrbiterC * 13239288539564571257U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 4677557318688502593U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 15081678577055628459U;
            aOrbiterJ = RotL64((aOrbiterJ * 16659305295251177155U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 7026792817486507482U) + aOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 14871665922943969918U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 694073180313083145U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 6807734532159292872U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 17882797335141303280U;
            aOrbiterF = RotL64((aOrbiterF * 15439872930381050291U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 9233542707022629190U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 1205501586581350876U;
            aOrbiterK = RotL64((aOrbiterK * 2596053290311090589U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 10878718669747466677U) + aNonceWordJ;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 8066049063548639241U;
            aOrbiterB = RotL64((aOrbiterB * 3031382633089381605U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 861295180226875235U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 9134969787937288583U;
            aOrbiterA = RotL64((aOrbiterA * 7565008208670843555U), 43U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterF, 29U);
            aIngress = aIngress + (RotL64(aOrbiterK, 19U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterJ, 53U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterH, 60U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aPrevious, 40U) + RotL64(aOrbiterF, 29U)) + aOrbiterB) + RotL64(aCarry, 21U)) + aWandererUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterJ, 5U)) + aOrbiterH);
            aWandererA = aWandererA + (((RotL64(aIngress, 57U) + aOrbiterK) + RotL64(aOrbiterH, 11U)) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 21U) + aOrbiterF) + RotL64(aOrbiterH, 41U));
            aWandererE = aWandererE + ((RotL64(aCross, 13U) + RotL64(aOrbiterC, 35U)) + aOrbiterJ);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 3U) + aOrbiterA) + RotL64(aOrbiterJ, 21U)) + aNonceWordE);
            aWandererB = aWandererB + (((RotL64(aIngress, 51U) + aOrbiterC) + RotL64(aOrbiterB, 50U)) + aWandererUpdateSaltB[((aIndex + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 27U) ^ aWandererF);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 58U));
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererI, 41U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordO);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 16488U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 17579U)) & S_BLOCK1], 42U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 20644U)) & S_BLOCK1], 30U) ^ RotL64(aWorkLaneC[((aIndex + 19185U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 27U) + RotL64(aIngress, 11U)) ^ (RotL64(aCarry, 54U) + RotL64(aPrevious, 41U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (((aWandererB + RotL64(aCross, 53U)) + RotL64(aCarry, 57U)) + 13687218104610230596U) + aNonceWordG;
            aOrbiterB = (aWandererD + RotL64(aPrevious, 19U)) + 6841550124960692709U;
            aOrbiterJ = (((aWandererI + RotL64(aIngress, 39U)) + RotL64(aCarry, 27U)) + 17418968668458764131U) + aOrbiterAssignSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 28U)) + RotL64(aCarry, 43U)) + 8303537912696948204U;
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 11U)) + 12376614417285936537U) + aNonceWordM;
            aOrbiterD = (aWandererF + RotL64(aCross, 3U)) + 14215749063579232654U;
            aOrbiterF = ((aWandererH + RotL64(aIngress, 47U)) + 4111736931433665347U) + aOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 11250375934571631522U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 5367367837773331275U;
            aOrbiterJ = RotL64((aOrbiterJ * 7262723007545807179U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 15514089192382674434U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 1475991716685034960U;
            aOrbiterB = RotL64((aOrbiterB * 17720681295551650891U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 5531622777788629748U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 8363822215908303335U) ^ aNonceWordK;
            aOrbiterI = RotL64((aOrbiterI * 17850203366840994883U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 3741256932685720414U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 11634667238062155772U) ^ aOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15925089729784547403U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 18180546911210417155U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 5123234656838556335U;
            aOrbiterC = RotL64((aOrbiterC * 15362857462853398025U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 11215734271189250284U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 16863747802158398092U) ^ aOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1828035970246160023U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 9859050606636646323U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 9331300036643654675U;
            aOrbiterF = RotL64((aOrbiterF * 2502263410556166281U), 29U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterI, 23U);
            aIngress = aIngress + (RotL64(aOrbiterF, 41U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterK, 4U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterB, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aCross, 35U) + RotL64(aOrbiterF, 47U)) + aOrbiterB) + RotL64(aCarry, 51U)) + aWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 41U) + aOrbiterD) + RotL64(aOrbiterJ, 21U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 29U) + RotL64(aOrbiterJ, 27U)) + aOrbiterB) + RotL64(aCarry, 19U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterD, 41U)) + aOrbiterK) + aNonceWordE);
            aWandererF = aWandererF + (((RotL64(aPrevious, 48U) + RotL64(aOrbiterI, 60U)) + aOrbiterB) + aWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 19U) + aOrbiterF) + RotL64(aOrbiterC, 35U));
            aWandererD = aWandererD + (((RotL64(aCross, 11U) + aOrbiterF) + RotL64(aOrbiterJ, 11U)) + aNonceWordJ);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 40U) ^ aWandererD);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererH, 23U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordH);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 28926U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28203U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25526U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 31491U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 3U) ^ RotL64(aPrevious, 50U)) + (RotL64(aCross, 21U) + RotL64(aIngress, 35U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (aWandererA + RotL64(aPrevious, 57U)) + 12669015908335980355U;
            aOrbiterH = ((aWandererD + RotL64(aCross, 27U)) + RotL64(aCarry, 57U)) + 5438715179868613192U;
            aOrbiterA = ((aWandererG + RotL64(aIngress, 43U)) + RotL64(aCarry, 21U)) + 13172104448184536460U;
            aOrbiterD = ((aWandererH + RotL64(aScatter, 36U)) + 13421421503244744803U) + aOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = ((aWandererJ + RotL64(aCross, 21U)) + 13327113302994856582U) + aNonceWordA;
            aOrbiterJ = (((aWandererF + RotL64(aPrevious, 11U)) + RotL64(aCarry, 43U)) + 4671768205922454413U) + aOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = ((aWandererB + RotL64(aScatter, 51U)) + 5355759962838579929U) + aNonceWordM;
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 6691720614265406851U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 7063906424700911378U;
            aOrbiterA = RotL64((aOrbiterA * 17091734375516280675U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 17328616394166672263U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 1542940602574207068U) ^ aOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8981679306319627975U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 7203866278803132454U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 993485696233139264U;
            aOrbiterH = RotL64((aOrbiterH * 11609009908810366447U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 15659679028507488331U) + aNonceWordK;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 18321361454094675842U;
            aOrbiterI = RotL64((aOrbiterI * 3966860765622641843U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 9633319822696783352U) + aOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 3496559332232402963U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7772060229838162977U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 1918349708324205526U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 7701088402761359134U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9649485438465644795U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 6006824348814439686U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 18088375375347012557U;
            aOrbiterC = RotL64((aOrbiterC * 12801082943086128385U), 19U);
            //
            aIngress = RotL64(aOrbiterJ, 21U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterI, 27U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + RotL64(aOrbiterG, 38U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aCross, 23U) + aOrbiterI) + RotL64(aOrbiterJ, 3U)) + RotL64(aCarry, 21U)) + aWandererUpdateSaltC[((aIndex + 16U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterH, 27U)) + aOrbiterI);
            aWandererH = aWandererH + (((RotL64(aScatter, 47U) + aOrbiterH) + RotL64(aOrbiterD, 41U)) + RotL64(aCarry, 39U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterJ, 21U)) + aOrbiterG);
            aWandererG = aWandererG + ((((RotL64(aCross, 56U) + aOrbiterG) + RotL64(aOrbiterC, 50U)) + aNonceWordE) + aWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterC, 13U)) + aOrbiterJ);
            aWandererA = aWandererA + ((RotL64(aScatter, 41U) + RotL64(aOrbiterI, 35U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 40U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + RotL64(aWandererF, 29U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ aNonceWordC;
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

void TwistExpander_Bowling_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xEC6019424B355647ULL + 0xB4C652DF8DFFF1BFULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xF0C0E5A60EECA42FULL + 0xCECF1936714BEFAEULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xA89467EEE514FA01ULL + 0xAE43E3DFAAF5C7A3ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x8C7B29AAB0CB427DULL + 0x8E2C2DEC1C77CDCDULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xBCC9E9C346058F9BULL + 0x89D5E5FDF50F34B6ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xF2CC06C286336E8BULL + 0xF5A6B4B76F37054AULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xBFB62806AB03B6D5ULL + 0xC08AF09CE647B8EFULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xFCE029EEE54D2687ULL + 0xA481DE1CA7116594ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x98F6974012D586E7ULL + 0x942C777022025C20ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xE368174EA8DD4D0FULL + 0xC37BB7B2AB7B1325ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xA4A3083DD108F6D3ULL + 0xED5B3D572AB15007ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xA0714316E36E9CDDULL + 0xBE1A1823223F19E8ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xB6609B832BC49445ULL + 0x9208911E131FDA3AULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xA0C66BFF76C3A483ULL + 0xEE5C75A36C781A75ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xF40F5CE4B11EA4DBULL + 0xA63BD268B197F80BULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xF36AB8F3092EFB49ULL + 0xA30C4871595E840DULL);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 7687U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneC[((aIndex + 2477U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 823U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 2707U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aIngress, 42U)) + (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 19U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 57U)) + 3684295017013759987U;
            aOrbiterA = (aWandererJ + RotL64(aCross, 48U)) + 6740408842457292881U;
            aOrbiterK = (aWandererA + RotL64(aScatter, 23U)) + 4563975890702399441U;
            aOrbiterD = (((aWandererG + RotL64(aIngress, 43U)) + RotL64(aCarry, 37U)) + 797804144825287940U) + aNonceWordO;
            aOrbiterI = (((aWandererH + RotL64(aPrevious, 27U)) + 2763779540450101303U) + aOrbiterAssignSaltA[((aIndex + 28U)) & S_SALT1]) + aNonceWordB;
            aOrbiterH = (aWandererF + RotL64(aIngress, 13U)) + 13211846164102089685U;
            aOrbiterB = ((aWandererE + RotL64(aScatter, 51U)) + RotL64(aCarry, 3U)) + 15214578447281401982U;
            aOrbiterC = (((aWandererD + RotL64(aCross, 11U)) + RotL64(aCarry, 47U)) + 13745208628754232427U) + aOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = (aWandererC + RotL64(aIngress, 30U)) + 17358621225969190747U;
            aOrbiterE = (aWandererB + RotL64(aCross, 41U)) + 779739369960480023U;
            aOrbiterG = (aWandererI + RotL64(aScatter, 3U)) + 4370963533701407813U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 6061333005507739975U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 3589705340762734456U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16499293983611196967U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 10607697666369230567U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 9356757995305239271U;
            aOrbiterH = RotL64((aOrbiterH * 10945513661439954731U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 10093033335903048138U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 11037328061699834100U;
            aOrbiterJ = RotL64((aOrbiterJ * 11189760551792389605U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 558431161176115540U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 17795680919453449358U;
            aOrbiterD = RotL64((aOrbiterD * 3910117359996283803U), 11U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterK) + 6096779391116214109U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordD;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 17594243286880690775U) ^ aNonceWordF;
            aOrbiterB = RotL64((aOrbiterB * 12655610181937429915U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 15414704802398002423U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 18040588240488602196U;
            aOrbiterF = RotL64((aOrbiterF * 16344249573086571225U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 14636298592697156931U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 9677305688594936561U;
            aOrbiterG = RotL64((aOrbiterG * 8354776999961642997U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 16408025751875050713U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 10018342878801454965U;
            aOrbiterA = RotL64((aOrbiterA * 10349132962708124117U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 1841090936357114866U) + aNonceWordK;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 16142637455878447020U;
            aOrbiterI = RotL64((aOrbiterI * 10565394571714418033U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 4089676582910615502U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 8749600984499831109U;
            aOrbiterC = RotL64((aOrbiterC * 3421055105090316521U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 11408932421005107097U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 3684295017013759987U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7037953759624065417U), 57U);
            //
            aIngress = RotL64(aOrbiterK, 53U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterC, 39U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 20U));
            aIngress = aIngress + (RotL64(aOrbiterG, 37U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterA, 51U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterH, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterA, 11U)) + aOrbiterB);
            aWandererG = aWandererG + ((RotL64(aScatter, 19U) + RotL64(aOrbiterC, 50U)) + aOrbiterA);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterK, 13U)) + aOrbiterF);
            aWandererF = aWandererF + (((RotL64(aCross, 11U) + aOrbiterD) + RotL64(aOrbiterC, 39U)) + aNonceWordE);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 47U) + aOrbiterI) + RotL64(aOrbiterJ, 19U)) + aWandererUpdateSaltB[((aIndex + 22U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 51U) + RotL64(aOrbiterH, 43U)) + aOrbiterE) + RotL64(aCarry, 29U)) + aWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 26U) + aOrbiterK) + RotL64(aOrbiterG, 29U));
            aWandererH = aWandererH + (((RotL64(aCross, 23U) + aOrbiterJ) + RotL64(aOrbiterF, 27U)) + aNonceWordM);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterE, 53U)) + aOrbiterF);
            aWandererI = aWandererI + (((RotL64(aCross, 35U) + RotL64(aOrbiterG, 5U)) + aOrbiterA) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 14U) + aOrbiterF) + RotL64(aOrbiterG, 58U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 60U));
            aCarry = aCarry + (RotL64(aWandererI, 53U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererA, 26U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererK, 5U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ aNonceWordH;
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 8705U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 11749U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15626U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 15910U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 27U) ^ RotL64(aCross, 41U)) + (RotL64(aIngress, 56U) ^ RotL64(aCarry, 11U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (aWandererH + RotL64(aIngress, 46U)) + 9751314027302668907U;
            aOrbiterF = (aWandererC + RotL64(aPrevious, 27U)) + 12175450995523107056U;
            aOrbiterG = (aWandererK + RotL64(aScatter, 37U)) + 17519694958730119552U;
            aOrbiterD = (((aWandererB + RotL64(aCross, 29U)) + RotL64(aCarry, 13U)) + 9093525527925682263U) + aOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = (((aWandererI + RotL64(aPrevious, 35U)) + RotL64(aCarry, 47U)) + 3713831321786810138U) + aNonceWordN;
            aOrbiterE = (aWandererD + RotL64(aIngress, 53U)) + 10108355209191835040U;
            aOrbiterH = (aWandererA + RotL64(aScatter, 41U)) + 12956307447311314768U;
            aOrbiterA = ((aWandererJ + RotL64(aCross, 11U)) + 1904298513945877359U) + aOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = (aWandererG + RotL64(aScatter, 51U)) + 4658049993308574460U;
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 44U)) + RotL64(aCarry, 51U)) + 9826333658248851902U;
            aOrbiterB = (aWandererF + RotL64(aCross, 3U)) + 12058666914724365134U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 2516574707110528099U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 13335308331049750235U) ^ aOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5880227828760598587U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 8230749255538495304U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 16536559486797811486U;
            aOrbiterF = RotL64((aOrbiterF * 7097036838156464969U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 12387639130570188998U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 8459259798142872020U;
            aOrbiterK = RotL64((aOrbiterK * 8001346480955847013U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 16083784052002800300U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 1957284290736468379U;
            aOrbiterH = RotL64((aOrbiterH * 5046501301740813065U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 7349538179311335863U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 16395170077006105258U) ^ aOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4230485452156662763U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 3317652065873784068U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 5517155804799120700U;
            aOrbiterC = RotL64((aOrbiterC * 9789270651974719183U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 5568525912112200094U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 9334250662962319598U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5034887614541768961U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 5641394627075994165U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 13524971148931512745U;
            aOrbiterE = RotL64((aOrbiterE * 3699457147759854357U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 15124425790244392471U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 7896294947517723306U;
            aOrbiterA = RotL64((aOrbiterA * 7526632360108129915U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 15241686066829586263U) + aNonceWordG;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 12099799118961857495U;
            aOrbiterJ = RotL64((aOrbiterJ * 10456171163074630861U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 17529688916595727188U) + aNonceWordA;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 9751314027302668907U;
            aOrbiterB = RotL64((aOrbiterB * 521888849578281715U), 41U);
            //
            aIngress = RotL64(aOrbiterK, 57U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterH, 5U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterB, 54U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 35U));
            aIngress = aIngress + RotL64(aOrbiterD, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterE, 13U)) + aOrbiterH);
            aWandererF = aWandererF + (((RotL64(aIngress, 51U) + RotL64(aOrbiterF, 29U)) + aOrbiterD) + aWandererUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 19U) + aOrbiterG) + RotL64(aOrbiterC, 53U)) + aNonceWordJ);
            aWandererH = aWandererH + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterD, 27U)) + aOrbiterH) + aWandererUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 26U) + RotL64(aOrbiterJ, 40U)) + aOrbiterH);
            aWandererD = aWandererD + ((RotL64(aCross, 11U) + aOrbiterB) + RotL64(aOrbiterH, 5U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 5U) + aOrbiterD) + RotL64(aOrbiterK, 57U));
            aWandererA = aWandererA + ((((RotL64(aPrevious, 3U) + aOrbiterF) + RotL64(aOrbiterA, 19U)) + RotL64(aCarry, 37U)) + aNonceWordI);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 41U) + aOrbiterA) + RotL64(aOrbiterG, 37U));
            aWandererE = aWandererE + ((((RotL64(aScatter, 56U) + RotL64(aOrbiterB, 43U)) + aOrbiterC) + RotL64(aCarry, 23U)) + aNonceWordP);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterG, 46U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererA, 37U) ^ aWandererH);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 48U));
            aCarry = aCarry + (RotL64(aWandererF, 53U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererB, 41U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererE, 50U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordA);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 17523U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 20056U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 23413U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneC[((aIndex + 19340U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCross, 38U)) + (RotL64(aCarry, 5U) + RotL64(aIngress, 53U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (aWandererI + RotL64(aScatter, 5U)) + 15904465836916519864U;
            aOrbiterG = (aWandererC + RotL64(aCross, 50U)) + 17725629806317789307U;
            aOrbiterI = (aWandererJ + RotL64(aIngress, 53U)) + 13794170125914914828U;
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 13U)) + RotL64(aCarry, 37U)) + 2149055907476874332U;
            aOrbiterK = ((aWandererD + RotL64(aIngress, 3U)) + RotL64(aCarry, 19U)) + 5342047776745074649U;
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 23U)) + 8268148484060546838U) + aOrbiterAssignSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = (aWandererF + RotL64(aScatter, 43U)) + 10821151364028563719U;
            aOrbiterB = ((aWandererK + RotL64(aCross, 41U)) + 4294213820894407378U) + aNonceWordJ;
            aOrbiterE = (aWandererA + RotL64(aScatter, 27U)) + 10884726101307943090U;
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 18U)) + 16432210042202444824U;
            aOrbiterA = (((aWandererH + RotL64(aCross, 29U)) + RotL64(aCarry, 27U)) + 15196602644336228055U) + aOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 14117787670220328165U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 219833877949480215U) ^ aOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10736293047771972173U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 3326396981881473962U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 14918513066311426279U) ^ aNonceWordC;
            aOrbiterF = RotL64((aOrbiterF * 14269763278564574663U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 11795234681370163206U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 3068267285352664813U;
            aOrbiterG = RotL64((aOrbiterG * 15746255933920904619U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 245233356957999496U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 709926406353796673U;
            aOrbiterK = RotL64((aOrbiterK * 13627039596842073595U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 5378105439430271038U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 10114555061122044430U;
            aOrbiterB = RotL64((aOrbiterB * 5351295043424885549U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 13233010815716769713U) + aNonceWordN;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 8231291294833548389U;
            aOrbiterJ = RotL64((aOrbiterJ * 10840516135212753869U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 7160760224172419829U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 14767926435411546785U;
            aOrbiterD = RotL64((aOrbiterD * 1643485739468851073U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 4464245330038080103U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 15778166658285494712U;
            aOrbiterH = RotL64((aOrbiterH * 13980891936095282989U), 51U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterA) + 2426340576450960905U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordB;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 6030631392508241438U;
            aOrbiterC = RotL64((aOrbiterC * 13921288910299408423U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 15990180955119402476U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 8707879851984546959U;
            aOrbiterE = RotL64((aOrbiterE * 13794027045755532979U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 11665969506971636052U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 15904465836916519864U;
            aOrbiterA = RotL64((aOrbiterA * 17042355185093585101U), 3U);
            //
            aIngress = RotL64(aOrbiterK, 39U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterE, 36U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 11U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 5U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterA, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterH, 13U)) + aOrbiterI) + aWandererUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 5U) + aOrbiterA) + RotL64(aOrbiterC, 43U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterG, 26U)) + aOrbiterC) + aNonceWordG);
            aWandererD = aWandererD + ((RotL64(aCross, 11U) + aOrbiterB) + RotL64(aOrbiterE, 39U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 46U) + RotL64(aOrbiterK, 41U)) + aOrbiterB) + aNonceWordE);
            aWandererB = aWandererB + (((RotL64(aIngress, 3U) + aOrbiterK) + RotL64(aOrbiterD, 23U)) + RotL64(aCarry, 13U));
            aWandererC = aWandererC ^ ((((RotL64(aCross, 23U) + RotL64(aOrbiterF, 21U)) + aOrbiterH) + aNonceWordF) + aWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterG, 34U)) + aOrbiterE) + RotL64(aCarry, 51U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterK, 3U)) + aOrbiterH);
            aWandererK = aWandererK + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterK, 53U)) + aOrbiterA);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 38U) + aOrbiterJ) + RotL64(aOrbiterF, 37U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 20U));
            aCarry = aCarry + (RotL64(aWandererE, 41U) ^ aWandererH);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 37U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererD, 18U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordD);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 32095U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31247U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 26727U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneD[((aIndex + 25881U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCarry, 35U)) + (RotL64(aIngress, 57U) ^ RotL64(aCross, 20U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 27U)) + 12426357877879529292U) + aNonceWordM;
            aOrbiterF = (aWandererD + RotL64(aIngress, 29U)) + 12604900366173639176U;
            aOrbiterI = ((aWandererF + RotL64(aCross, 19U)) + 13511119007338929401U) + aNonceWordH;
            aOrbiterC = (aWandererH + RotL64(aScatter, 24U)) + 9878720081166788060U;
            aOrbiterG = ((aWandererG + RotL64(aIngress, 41U)) + RotL64(aCarry, 29U)) + 15463195409806395076U;
            aOrbiterE = ((aWandererE + RotL64(aCross, 37U)) + RotL64(aCarry, 21U)) + 6407922778852833423U;
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 13U)) + RotL64(aCarry, 43U)) + 7690427254160734016U;
            aOrbiterK = ((aWandererK + RotL64(aScatter, 22U)) + 18030974031722143619U) + aOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = (aWandererC + RotL64(aIngress, 57U)) + 17983938038322737041U;
            aOrbiterA = (((aWandererB + RotL64(aPrevious, 51U)) + 16605512170117753884U) + aOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1]) + aNonceWordN;
            aOrbiterB = (aWandererJ + RotL64(aCross, 3U)) + 681802273302348322U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 15550312921312083819U) + aOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 17824154101711884508U;
            aOrbiterI = RotL64((aOrbiterI * 7358612830654795357U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 1939207786756735430U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 3132864634777826569U;
            aOrbiterG = RotL64((aOrbiterG * 13606281919426730325U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 12822929773923954849U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 16576106045887115660U;
            aOrbiterE = RotL64((aOrbiterE * 16370914370769903051U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 2398825881649235260U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 13700821892926092479U;
            aOrbiterJ = RotL64((aOrbiterJ * 10830623703416956043U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 2439833784883391606U) + aOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 15870638514107637833U;
            aOrbiterK = RotL64((aOrbiterK * 3797380922767479287U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 9165457123134229670U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterE) ^ 8736642509192659417U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterD = RotL64((aOrbiterD * 16219277537523484065U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 9232719746484835693U) + aNonceWordB;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 7826680628853322541U;
            aOrbiterA = RotL64((aOrbiterA * 12578050118133526187U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 14323652326982518782U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 2254524512851399313U;
            aOrbiterB = RotL64((aOrbiterB * 4119339547645451149U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 14459632243829356472U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 8591197056749497716U;
            aOrbiterH = RotL64((aOrbiterH * 13053836520694721881U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 17220196418897000411U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 7186579019945992185U;
            aOrbiterF = RotL64((aOrbiterF * 12406048515179065691U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 7554005180895698880U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 12426357877879529292U;
            aOrbiterC = RotL64((aOrbiterC * 5090046967147694465U), 21U);
            //
            aIngress = RotL64(aOrbiterK, 51U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 42U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 53U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 39U));
            aIngress = aIngress + (RotL64(aOrbiterB, 47U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterI, 60U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aPrevious, 30U) + aOrbiterG) + RotL64(aOrbiterE, 51U));
            aWandererB = aWandererB ^ ((((RotL64(aCross, 39U) + RotL64(aOrbiterK, 11U)) + aOrbiterI) + aNonceWordF) + aWandererUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 19U) + RotL64(aOrbiterH, 30U)) + aOrbiterF) + RotL64(aCarry, 5U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 41U) + aOrbiterC) + RotL64(aOrbiterA, 27U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterA, 3U)) + aOrbiterJ) + RotL64(aCarry, 19U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 5U) + aOrbiterB) + RotL64(aOrbiterH, 53U)) + aWandererUpdateSaltF[((aIndex + 6U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 37U) + RotL64(aOrbiterB, 48U)) + aOrbiterK);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 44U) + RotL64(aOrbiterK, 43U)) + aOrbiterD);
            aWandererC = aWandererC + ((RotL64(aPrevious, 57U) + aOrbiterA) + RotL64(aOrbiterG, 19U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterF, 57U)) + aOrbiterJ);
            aWandererH = aWandererH + ((RotL64(aIngress, 23U) + RotL64(aOrbiterI, 37U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 26U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + RotL64(aWandererK, 39U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ aNonceWordC;
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

void TwistExpander_Bowling_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xD0B87FDC14C69799ULL + 0xDC3F7C30328FFD43ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xCB5DA28767A2F30DULL + 0x98E59066FDE488C8ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xE976E6B085D0661DULL + 0xAFEC6880335E821CULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xD2ECFD103050F83DULL + 0xD5A7BB0761521BBBULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xA9146A5E914ABBB7ULL + 0xEFF86B87ABF14DC2ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xE760FC3349C6A4C5ULL + 0xDDB5088D5ADD31FFULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xA309F7D1B5C8416BULL + 0xCBCE5928F44FB652ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xA0985A3855AE2DF9ULL + 0xA64A781943DC6728ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xF9D99C63588192A7ULL + 0xE2AD5216B04F177AULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x81FF67017FE31655ULL + 0xF911DA13C2219741ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x9FD7566CC2E3E29BULL + 0x8A1853F9427C371BULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xCF0E6FF3243F0583ULL + 0xC67ADE315D5FA3CBULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x92F4C4AC1B57FC27ULL + 0xF02CDB0C9A3A05FFULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xBD40635BADF8CB9BULL + 0xFCA7F80E7F38BE47ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xC1E09DA674DF0A29ULL + 0x8C38F51635CFAC83ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x8D1EF07A140EC981ULL + 0xC9EDB676030C4046ULL);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 4325U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneC[((aIndex + 3801U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 2080U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 2945U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 58U) + RotL64(aIngress, 29U)) ^ (RotL64(aCarry, 43U) ^ RotL64(aPrevious, 13U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (((aWandererE + RotL64(aCross, 23U)) + RotL64(aCarry, 21U)) + 18087125778766689269U) + aOrbiterAssignSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterD = (((aWandererK + RotL64(aScatter, 34U)) + RotL64(aCarry, 5U)) + 13710545066503235196U) + aNonceWordN;
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 3U)) + 1701939704736254645U) + aNonceWordK;
            aOrbiterH = ((aWandererC + RotL64(aIngress, 13U)) + 8064093611384019909U) + aNonceWordM;
            aOrbiterJ = (aWandererD + RotL64(aPrevious, 19U)) + 16623332751533885431U;
            aOrbiterI = (aWandererA + RotL64(aScatter, 51U)) + 15590129153794910109U;
            aOrbiterK = (aWandererJ + RotL64(aIngress, 29U)) + 7413312683079107383U;
            aOrbiterG = ((aWandererG + RotL64(aCross, 47U)) + 4186064478651458810U) + aOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = ((aWandererB + RotL64(aIngress, 56U)) + RotL64(aCarry, 35U)) + 5501191643940735954U;
            //
            aOrbiterE = (((aOrbiterE + aOrbiterD) + 11064645242200570835U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordI;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 13825922087298055833U;
            aOrbiterF = RotL64((aOrbiterF * 7529317892716108867U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 5944980709887369970U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 8181136916070569646U;
            aOrbiterI = RotL64((aOrbiterI * 395183021205661827U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 15442336949157292482U) + aNonceWordL;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 11580554435240641337U) ^ aNonceWordJ;
            aOrbiterG = RotL64((aOrbiterG * 6654637892858767739U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 11240018128174598322U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 2027565596050777471U;
            aOrbiterC = RotL64((aOrbiterC * 18048186560314431815U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 16425887196883725233U) + aOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 16828683527588834095U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17746289103235902485U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 9923829146479008804U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 6669171007279929454U;
            aOrbiterH = RotL64((aOrbiterH * 681823450939955099U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 3902430046523165149U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 6739998149289590041U;
            aOrbiterK = RotL64((aOrbiterK * 2675037435528416821U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 16014401255534234075U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 14741857638680634564U;
            aOrbiterD = RotL64((aOrbiterD * 8723611021403369393U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 5064807861673260054U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 968747317273200299U;
            aOrbiterJ = RotL64((aOrbiterJ * 14122304002722582329U), 47U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterK, 48U);
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterC, 11U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 35U));
            aIngress = aIngress + RotL64(aOrbiterJ, 28U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aPrevious, 48U) + RotL64(aOrbiterE, 27U)) + aOrbiterG) + RotL64(aCarry, 21U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterK, 19U)) + aOrbiterD);
            aWandererG = aWandererG + ((RotL64(aCross, 53U) + aOrbiterI) + RotL64(aOrbiterE, 10U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 29U) + aOrbiterJ) + RotL64(aOrbiterG, 57U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 18U) + RotL64(aOrbiterC, 35U)) + aOrbiterH);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 37U) + RotL64(aOrbiterJ, 5U)) + aOrbiterH) + aNonceWordH);
            aWandererB = aWandererB + (((RotL64(aCross, 3U) + aOrbiterC) + RotL64(aOrbiterK, 39U)) + aNonceWordF);
            aWandererD = aWandererD ^ ((((RotL64(aScatter, 23U) + RotL64(aOrbiterF, 50U)) + aOrbiterE) + aNonceWordD) + aWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aIngress, 11U) + RotL64(aOrbiterK, 43U)) + aOrbiterI) + RotL64(aCarry, 43U)) + aWandererUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 30U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererJ);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + RotL64(aWandererD, 27U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ aNonceWordD;
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 7257U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 7798U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 8877U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneB[((aIndex + 10260U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 54U) + RotL64(aCarry, 3U)) + (RotL64(aCross, 19U) ^ RotL64(aIngress, 37U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (((aWandererB + RotL64(aPrevious, 3U)) + RotL64(aCarry, 37U)) + 5295352595333316211U) + aNonceWordI;
            aOrbiterH = ((aWandererF + RotL64(aScatter, 27U)) + RotL64(aCarry, 11U)) + 2341795367042042605U;
            aOrbiterE = (aWandererJ + RotL64(aIngress, 43U)) + 10122175780504033663U;
            aOrbiterA = ((aWandererH + RotL64(aCross, 38U)) + 10084612804696198554U) + aOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = (((aWandererI + RotL64(aScatter, 11U)) + 16470424309851045971U) + aOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordD;
            aOrbiterF = (aWandererA + RotL64(aPrevious, 47U)) + 656016130975227994U;
            aOrbiterI = ((aWandererC + RotL64(aCross, 53U)) + RotL64(aCarry, 23U)) + 15313268829659834317U;
            aOrbiterC = (aWandererG + RotL64(aIngress, 19U)) + 3795220914993923394U;
            aOrbiterB = (aWandererK + RotL64(aPrevious, 34U)) + 14044442220988813825U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 3804224626734584802U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 7980006306010255693U;
            aOrbiterE = RotL64((aOrbiterE * 13958505239726088561U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 13746830564584711549U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 11852212099729274845U;
            aOrbiterG = RotL64((aOrbiterG * 2164880979318247855U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 9083223471018084847U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 13706723820703853346U;
            aOrbiterI = RotL64((aOrbiterI * 11361854103656219887U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 1713819986642275223U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 1382000168233902914U) ^ aOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3894160765130198157U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 4540474625764565485U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 1756168174375757220U;
            aOrbiterB = RotL64((aOrbiterB * 12739160208010092017U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 1409297070183609309U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterG) ^ 6082750101445444357U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterK = RotL64((aOrbiterK * 17438740230251860935U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 1113239890859479202U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 10932192439503964363U;
            aOrbiterA = RotL64((aOrbiterA * 5915660289913324281U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 3732595033748508428U) + aOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 5117760372351117286U) ^ aNonceWordP;
            aOrbiterF = RotL64((aOrbiterF * 2671510075176315761U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 7399968659654088641U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 14835608167871904147U;
            aOrbiterH = RotL64((aOrbiterH * 8312521710415756159U), 3U);
            //
            aIngress = RotL64(aOrbiterB, 13U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterF, 39U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 10U));
            aIngress = aIngress + (RotL64(aOrbiterA, 19U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterG, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aScatter, 41U) + RotL64(aOrbiterK, 44U)) + aOrbiterE) + RotL64(aCarry, 3U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterK, 11U)) + aOrbiterH);
            aWandererI = aWandererI + ((((RotL64(aCross, 20U) + aOrbiterE) + RotL64(aOrbiterF, 23U)) + RotL64(aCarry, 57U)) + aWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterG, 5U)) + aOrbiterK);
            aWandererG = aWandererG + ((RotL64(aScatter, 35U) + RotL64(aOrbiterG, 57U)) + aOrbiterF);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterC, 34U)) + aOrbiterI);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterC, 19U)) + aOrbiterH) + aNonceWordH) + aWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 27U) + aOrbiterG) + RotL64(aOrbiterA, 27U));
            aWandererA = aWandererA + ((RotL64(aCross, 46U) + RotL64(aOrbiterF, 39U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 6U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 51U));
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererB);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + RotL64(aWandererF, 54U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordJ);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 13389U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15446U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 12563U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 10954U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 27U) ^ RotL64(aCarry, 56U)) + (RotL64(aCross, 13U) ^ RotL64(aIngress, 39U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (aWandererC + RotL64(aIngress, 42U)) + 13053031069776604052U;
            aOrbiterF = ((aWandererG + RotL64(aScatter, 47U)) + 1331396630251085122U) + aOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 23U)) + 15879286043343942393U) + aOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = ((aWandererB + RotL64(aCross, 3U)) + 13590365633321406830U) + aNonceWordE;
            aOrbiterE = ((aWandererA + RotL64(aScatter, 11U)) + 14569235423040242618U) + aNonceWordO;
            aOrbiterD = ((aWandererI + RotL64(aIngress, 53U)) + RotL64(aCarry, 13U)) + 11397370636618371560U;
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 58U)) + 3455933494593971847U;
            aOrbiterH = ((aWandererH + RotL64(aCross, 19U)) + RotL64(aCarry, 3U)) + 1307153376443784593U;
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 37U)) + RotL64(aCarry, 43U)) + 10688618762584786871U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 17746248451153600096U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 8512568600755410158U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16648320170768234063U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 8950230550112591092U) + aOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 17790968369472845496U;
            aOrbiterC = RotL64((aOrbiterC * 5104988920132008913U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 12583323865381967534U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 11243927099685293887U;
            aOrbiterI = RotL64((aOrbiterI * 12867003042486433971U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 9690268715525781389U) + aNonceWordM;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 7466066217365074653U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17565696765505320889U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 3673528673209875118U) + aOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 14079103852360952255U;
            aOrbiterE = RotL64((aOrbiterE * 17449228863409999629U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 6747836856132250630U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 5027692924422297153U;
            aOrbiterD = RotL64((aOrbiterD * 2492421273167124437U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 11370341866003395776U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 14013204893442579282U;
            aOrbiterJ = RotL64((aOrbiterJ * 6602239957997240785U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 3436953430697936790U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 6399073534839993637U;
            aOrbiterH = RotL64((aOrbiterH * 14186050072610021241U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 7054057507823631422U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 5752085719673338095U;
            aOrbiterK = RotL64((aOrbiterK * 13252660162476029593U), 21U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterH, 30U);
            aIngress = aIngress + (RotL64(aOrbiterA, 27U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterC, 19U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterE, 39U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterK, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aScatter, 51U) + aOrbiterC) + RotL64(aOrbiterA, 53U)) + aWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 29U) + RotL64(aOrbiterC, 3U)) + aOrbiterF) + aNonceWordL);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 58U) + aOrbiterF) + RotL64(aOrbiterD, 26U)) + aNonceWordP);
            aWandererH = aWandererH + (((RotL64(aPrevious, 23U) + aOrbiterJ) + RotL64(aOrbiterE, 47U)) + RotL64(aCarry, 3U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterH, 43U)) + aOrbiterA);
            aWandererD = aWandererD + (((RotL64(aScatter, 13U) + RotL64(aOrbiterK, 37U)) + aOrbiterI) + aWandererUpdateSaltB[((aIndex + 26U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterI, 57U)) + aOrbiterA);
            aWandererC = aWandererC + (((RotL64(aCross, 4U) + RotL64(aOrbiterK, 19U)) + aOrbiterC) + RotL64(aCarry, 21U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 39U) + aOrbiterE) + RotL64(aOrbiterC, 12U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererC);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 54U));
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererH, 11U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordK);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 19908U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((aIndex + 18402U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20838U)) & S_BLOCK1], 44U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 21563U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 3U) + RotL64(aCross, 53U)) + (RotL64(aIngress, 18U) ^ RotL64(aCarry, 35U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (aWandererI + RotL64(aPrevious, 5U)) + 2168513956284366370U;
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 52U)) + 10290361969974613111U) + aOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = (((aWandererC + RotL64(aCross, 23U)) + RotL64(aCarry, 11U)) + 15673836275828498050U) + aNonceWordJ;
            aOrbiterD = (((aWandererG + RotL64(aIngress, 19U)) + RotL64(aCarry, 29U)) + 16600540024145812236U) + aNonceWordB;
            aOrbiterF = (aWandererF + RotL64(aPrevious, 41U)) + 9428052101528111892U;
            aOrbiterC = ((aWandererE + RotL64(aScatter, 37U)) + RotL64(aCarry, 57U)) + 12763657928312763377U;
            aOrbiterA = (aWandererJ + RotL64(aIngress, 29U)) + 10751286982008662485U;
            aOrbiterE = ((aWandererD + RotL64(aCross, 60U)) + 1708230173038057979U) + aOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = ((aWandererH + RotL64(aScatter, 47U)) + 4011389705422783816U) + aNonceWordK;
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 11704428328093077714U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 2055336619674699284U;
            aOrbiterK = RotL64((aOrbiterK * 6374289210096410907U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 1870865272102705804U) + aNonceWordG;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 3574214263751923179U;
            aOrbiterF = RotL64((aOrbiterF * 13132083406834413563U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 984611970726966186U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 15207945449947643672U) ^ aOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9539470161576639981U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 4181398506373973169U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 15222345431506025949U;
            aOrbiterB = RotL64((aOrbiterB * 6925143692628659467U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 15023513452326240962U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 14965669361708810699U;
            aOrbiterD = RotL64((aOrbiterD * 587008860996713147U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 7985755518735406360U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 225592097619240187U;
            aOrbiterC = RotL64((aOrbiterC * 2313509354133400439U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 3659537916566939383U) + aOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 17043668033610689611U;
            aOrbiterE = RotL64((aOrbiterE * 10797634709118100773U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 10217321522161675848U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 8013663869536146842U;
            aOrbiterI = RotL64((aOrbiterI * 2293233079384777175U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 13762445330867496042U) + aNonceWordH;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 2692400019659269106U;
            aOrbiterJ = RotL64((aOrbiterJ * 167704184292219399U), 19U);
            //
            aIngress = RotL64(aOrbiterJ, 50U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 53U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 43U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 13U));
            aIngress = aIngress + RotL64(aOrbiterA, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aScatter, 35U) + aOrbiterB) + RotL64(aOrbiterJ, 4U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterK, 39U)) + aOrbiterD);
            aWandererF = aWandererF + ((RotL64(aPrevious, 54U) + RotL64(aOrbiterI, 23U)) + aOrbiterD);
            aWandererI = aWandererI ^ ((RotL64(aCross, 47U) + aOrbiterE) + RotL64(aOrbiterA, 43U));
            aWandererK = aWandererK + ((RotL64(aIngress, 27U) + RotL64(aOrbiterD, 11U)) + aOrbiterB);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterF, 18U)) + aOrbiterK) + aNonceWordC);
            aWandererJ = aWandererJ + (((((RotL64(aCross, 5U) + aOrbiterC) + RotL64(aOrbiterE, 53U)) + RotL64(aCarry, 43U)) + aNonceWordL) + aWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 58U) + aOrbiterK) + RotL64(aOrbiterC, 35U));
            aWandererE = aWandererE + ((((RotL64(aIngress, 13U) + RotL64(aOrbiterF, 29U)) + aOrbiterC) + RotL64(aCarry, 19U)) + aWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 43U));
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 24U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererF, 35U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordE);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 24158U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneA[((aIndex + 25559U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24371U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25120U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 51U) + RotL64(aPrevious, 39U)) + (RotL64(aCross, 10U) ^ RotL64(aIngress, 23U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererA + RotL64(aScatter, 35U)) + 1708250618750199233U) + aOrbiterAssignSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterJ = (aWandererG + RotL64(aCross, 43U)) + 12009147777553691142U;
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 57U)) + 8393982703399156592U) + aNonceWordE;
            aOrbiterE = (aWandererK + RotL64(aIngress, 39U)) + 3247327098356831221U;
            aOrbiterA = (((aWandererH + RotL64(aCross, 22U)) + RotL64(aCarry, 41U)) + 3403590155376353737U) + aOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = (((aWandererB + RotL64(aScatter, 53U)) + RotL64(aCarry, 29U)) + 18197244558104735044U) + aNonceWordM;
            aOrbiterF = (aWandererI + RotL64(aIngress, 29U)) + 3096253642040701606U;
            aOrbiterK = (aWandererJ + RotL64(aPrevious, 5U)) + 8012692688785412179U;
            aOrbiterG = (((aWandererD + RotL64(aIngress, 12U)) + RotL64(aCarry, 13U)) + 17531946907545680745U) + aNonceWordD;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 17687695944270225817U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 16147773866007628769U;
            aOrbiterB = RotL64((aOrbiterB * 16926442582711557877U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 18244641303026196497U) + aNonceWordG;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 8839160526348897457U;
            aOrbiterC = RotL64((aOrbiterC * 14268021129087663397U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 10599266240854068246U) + aNonceWordL;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 2056723540756216155U;
            aOrbiterK = RotL64((aOrbiterK * 13311591601230386375U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 4629354220460621284U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 9505955649473204942U;
            aOrbiterG = RotL64((aOrbiterG * 17775391885312236187U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 17078153810088721310U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 9470436761716263000U;
            aOrbiterI = RotL64((aOrbiterI * 5431855497250357229U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 3305863413630104742U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 14377172434239576161U;
            aOrbiterE = RotL64((aOrbiterE * 6880176890091033423U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 415687827894226513U) + aNonceWordP;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 16975319836893760993U) ^ aOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6597144958013976445U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 12707054129431596074U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 8974182792497231239U;
            aOrbiterJ = RotL64((aOrbiterJ * 7874658957269462717U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 10826131924322955095U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 4168545139712703154U;
            aOrbiterA = RotL64((aOrbiterA * 10305904857550051705U), 57U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterJ, 41U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 11U));
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterI, 51U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterF, 46U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aIngress, 35U) + aOrbiterI) + RotL64(aOrbiterB, 35U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 10U) + RotL64(aOrbiterA, 47U)) + aOrbiterB);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 5U) + RotL64(aOrbiterC, 30U)) + aOrbiterI) + RotL64(aCarry, 13U)) + aNonceWordI);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterE, 41U)) + aOrbiterI) + aWandererUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aIngress, 53U) + RotL64(aOrbiterG, 3U)) + aOrbiterA);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterF, 51U));
            aWandererH = aWandererH + ((((RotL64(aScatter, 21U) + RotL64(aOrbiterB, 26U)) + aOrbiterE) + RotL64(aCarry, 3U)) + aNonceWordJ);
            aWandererC = aWandererC ^ (((RotL64(aCross, 26U) + aOrbiterF) + RotL64(aOrbiterK, 57U)) + aWandererUpdateSaltD[((aIndex + 10U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aScatter, 47U) + RotL64(aOrbiterJ, 11U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 26U));
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererG, 3U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ aNonceWordG;
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 27516U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28499U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29196U)) & S_BLOCK1], 52U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32009U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 35U) ^ RotL64(aIngress, 51U)) + (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 4U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererJ + RotL64(aIngress, 29U)) + 4848316479321533394U;
            aOrbiterF = (((aWandererD + RotL64(aScatter, 5U)) + 6919360256662636195U) + aOrbiterAssignSaltB[((aIndex + 24U)) & S_SALT1]) + aNonceWordE;
            aOrbiterJ = ((aWandererC + RotL64(aCross, 47U)) + RotL64(aCarry, 23U)) + 9897013582181108544U;
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 24U)) + RotL64(aCarry, 41U)) + 7319353809896158678U;
            aOrbiterC = (aWandererF + RotL64(aCross, 11U)) + 2848175435514849859U;
            aOrbiterE = (aWandererB + RotL64(aPrevious, 39U)) + 6967780718720437934U;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 51U)) + 10143884766603388136U) + aNonceWordG;
            aOrbiterH = ((aWandererH + RotL64(aScatter, 35U)) + RotL64(aCarry, 57U)) + 8675965006150972051U;
            aOrbiterG = (((aWandererE + RotL64(aPrevious, 18U)) + 16350117755560994281U) + aOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1]) + aNonceWordH;
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 17976597517118423760U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 1399631141355370237U;
            aOrbiterJ = RotL64((aOrbiterJ * 16537788276543236833U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 3590613762034716792U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 5134624314245932157U;
            aOrbiterC = RotL64((aOrbiterC * 13077589037975283371U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 10082236952942943654U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 4015535035905433450U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4961808568701908559U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 611474103801573800U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 5786708483794098001U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7694007039340089267U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 5201943497363274455U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 9282160506938328489U;
            aOrbiterG = RotL64((aOrbiterG * 5368182164239021367U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 4932320527498940158U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 11576526341731392916U;
            aOrbiterI = RotL64((aOrbiterI * 1712051774729439363U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 10790691517638887125U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 16280649213607464422U) ^ aNonceWordB;
            aOrbiterB = RotL64((aOrbiterB * 10756733801499471873U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 9553716940667712810U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 11827518270964003341U;
            aOrbiterE = RotL64((aOrbiterE * 1322489827908132831U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 16777463701235809321U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 3375489084588454149U;
            aOrbiterF = RotL64((aOrbiterF * 3335010977457647307U), 35U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterJ, 34U);
            aIngress = aIngress + (RotL64(aOrbiterB, 41U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 51U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 27U));
            aIngress = aIngress + RotL64(aOrbiterF, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aIngress, 30U) + RotL64(aOrbiterF, 23U)) + aOrbiterK);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterC, 19U)) + aOrbiterB) + aWandererUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aCross, 5U) + aOrbiterH) + RotL64(aOrbiterJ, 6U)) + RotL64(aCarry, 57U)) + aWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterF, 37U)) + aOrbiterJ);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 23U) + RotL64(aOrbiterC, 53U)) + aOrbiterJ) + RotL64(aCarry, 43U)) + aNonceWordP);
            aWandererF = aWandererF ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterF, 11U)) + aOrbiterH);
            aWandererB = aWandererB + ((RotL64(aIngress, 52U) + RotL64(aOrbiterI, 27U)) + aOrbiterK);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterF, 48U)) + aOrbiterG) + aNonceWordN);
            aWandererH = aWandererH + ((RotL64(aIngress, 37U) + RotL64(aOrbiterE, 41U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 10U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (RotL64(aWandererB, 13U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererK, 53U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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

void TwistExpander_Bowling_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xB463D6DAEC756BB9ULL + 0xAF43E7CD6986AC7BULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xEBE66B4B29116983ULL + 0x8FB7AB8E9FAEFCE8ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xA93AE5AE86D1C225ULL + 0x8FAD0A87498E9B05ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xDCD8AAD39BF953F7ULL + 0xEBCF3E60A3FABCC3ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x9ABE8C1AFBB28039ULL + 0x856058AF39A0E3EAULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xFBD216F7441A9C43ULL + 0x96F6AC85CEE09DD9ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xBCF42EAEA1F15975ULL + 0x8E0EAE2ABCB4E246ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x857B7261BD55B291ULL + 0xB9185B34D0FA5443ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x973D42B03C6F1967ULL + 0xF4997253F9FC5603ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x8750CFEF205F5B61ULL + 0xD82D898E6A246BD2ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xF29C2DF066B3400BULL + 0xE5FC6E35F546F81FULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xCFBFAA203C84EBBFULL + 0xCB68276F95AD2256ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xF3CAC4732EDE0175ULL + 0xDA75C8CDD74CD86AULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x91C0CE167A25AF91ULL + 0xF0D416551B9D7219ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xC3BA775266E09F93ULL + 0xE77C30583DB938E6ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xAE56B945EF63EDC1ULL + 0xCE7D6F9D0EA829CBULL);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 1596U)) & S_BLOCK1], 36U) ^ RotL64(aKeyRowReadA[((aIndex + 5426U)) & W_KEY1], 27U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 5277U)) & W_KEY1], 3U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 4187U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aIngress, 5U)) + (RotL64(aPrevious, 24U) + RotL64(aCross, 51U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterC = (aWandererE + RotL64(aPrevious, 29U)) + 11450949896247900941U;
            aOrbiterK = (((aWandererD + RotL64(aIngress, 41U)) + RotL64(aCarry, 3U)) + 3905542253538116335U) + aPhaseAOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = (((aWandererG + RotL64(aCross, 13U)) + RotL64(aCarry, 23U)) + 9529740545977785305U) + aNonceWordO;
            aOrbiterB = (aWandererB + RotL64(aScatter, 35U)) + 1856876631533143492U;
            aOrbiterE = (((aWandererK + RotL64(aPrevious, 5U)) + RotL64(aCarry, 39U)) + 84253466320181686U) + aPhaseAOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = ((aWandererH + RotL64(aScatter, 20U)) + 12577480918745432444U) + aNonceWordN;
            aOrbiterJ = ((aWandererA + RotL64(aCross, 51U)) + 5625703170397704029U) + aNonceWordM;
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 694608607323629282U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 3993981243536262204U;
            aOrbiterH = RotL64((aOrbiterH * 2502835860198146381U), 35U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterH) + 4119215953484892051U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordE;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 8785040118556157146U;
            aOrbiterE = RotL64((aOrbiterE * 17113521266125471625U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 16234403619456882890U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 10398727475672860610U;
            aOrbiterA = RotL64((aOrbiterA * 5086871400049644715U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 18327987141759096769U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 2645964788056875452U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8778681366114628045U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 2859452497983106129U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 7196557924940881076U;
            aOrbiterC = RotL64((aOrbiterC * 14415389907490256711U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 930127943984174668U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 15673596916054795749U;
            aOrbiterB = RotL64((aOrbiterB * 7505660488733199479U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 16673140529110941163U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterJ) ^ 2258448294877833760U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterK = RotL64((aOrbiterK * 1821550319748977445U), 19U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterB, 3U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 27U));
            aIngress = aIngress + (RotL64(aOrbiterA, 34U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterH, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aIngress, 12U) + aOrbiterH) + RotL64(aOrbiterB, 13U)) + aPhaseAWandererUpdateSaltE[((aIndex + 6U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aScatter, 5U) + RotL64(aOrbiterE, 21U)) + aOrbiterK) + RotL64(aCarry, 53U)) + aPhaseAWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 57U) + aOrbiterJ) + RotL64(aOrbiterK, 5U)) + aNonceWordK);
            aWandererD = aWandererD + (((RotL64(aPrevious, 23U) + aOrbiterA) + RotL64(aOrbiterB, 51U)) + RotL64(aCarry, 41U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterC, 57U)) + aOrbiterK);
            aWandererG = aWandererG + ((RotL64(aIngress, 29U) + aOrbiterE) + RotL64(aOrbiterC, 38U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 37U) + aOrbiterK) + RotL64(aOrbiterA, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererK);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + (RotL64(aWandererH, 34U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererE, 53U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordF);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9056U)) & S_BLOCK1], 13U) ^ RotL64(mSource[((aIndex + 6335U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 10368U)) & W_KEY1], 51U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 7271U)) & W_KEY1], 39U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 6U) ^ RotL64(aIngress, 35U)) + (RotL64(aCross, 23U) ^ RotL64(aPrevious, 53U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 57U)) + 8793908991006073956U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = (aWandererF + RotL64(aCross, 43U)) + 2932916283348441943U;
            aOrbiterA = ((aWandererD + RotL64(aScatter, 27U)) + RotL64(aCarry, 23U)) + 11069042087940968262U;
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 13U)) + 14369628676782894441U) + aNonceWordG;
            aOrbiterI = (((aWandererK + RotL64(aCross, 35U)) + RotL64(aCarry, 11U)) + 8602903272780978282U) + aNonceWordF;
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 6U)) + 3827036107178568820U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = ((aWandererH + RotL64(aIngress, 21U)) + RotL64(aCarry, 51U)) + 8905245209036772489U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 13331387530760017893U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 9880107580289737823U) ^ aNonceWordE;
            aOrbiterA = RotL64((aOrbiterA * 10302652857542703753U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 10199619040626900278U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 2466307560891374281U) ^ aNonceWordC;
            aOrbiterG = RotL64((aOrbiterG * 6295342978834217571U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 13973403407981259448U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 2851460278409385243U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11226902976321781743U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 10365453393815690776U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 2382382358987358791U;
            aOrbiterF = RotL64((aOrbiterF * 481563628980705781U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 5058198848163792422U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 10500434740387593487U;
            aOrbiterI = RotL64((aOrbiterI * 5946747708776079787U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 11289798395177667084U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 14327152153231286666U;
            aOrbiterJ = RotL64((aOrbiterJ * 18155778059595245561U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 8065137263811956313U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 3865153574847924816U;
            aOrbiterC = RotL64((aOrbiterC * 9495741102667755161U), 21U);
            //
            aIngress = RotL64(aOrbiterG, 58U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterI, 51U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 37U));
            aIngress = aIngress + RotL64(aOrbiterJ, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterI, 5U)) + aOrbiterF);
            aWandererB = aWandererB + (((RotL64(aScatter, 35U) + aOrbiterH) + RotL64(aOrbiterA, 11U)) + aPhaseAWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 5U) + aOrbiterC) + RotL64(aOrbiterJ, 28U));
            aWandererH = aWandererH + ((((RotL64(aPrevious, 44U) + aOrbiterJ) + RotL64(aOrbiterF, 51U)) + RotL64(aCarry, 43U)) + aNonceWordD);
            aWandererK = aWandererK ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterG, 57U)) + aOrbiterH) + aPhaseAWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 13U) + RotL64(aOrbiterG, 43U)) + aOrbiterF) + RotL64(aCarry, 21U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterH, 37U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererD, 50U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordG);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 13979U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14325U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 13549U)) & W_KEY1], 4U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 11403U)) & W_KEY1], 27U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCross, 20U)) ^ (RotL64(aIngress, 39U) ^ RotL64(aCarry, 5U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterF = (aWandererD + RotL64(aIngress, 39U)) + 5573188770530340913U;
            aOrbiterA = ((aWandererC + RotL64(aScatter, 11U)) + 1431772230889897111U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 47U)) + RotL64(aCarry, 53U)) + 4809192776429682319U;
            aOrbiterC = (((aWandererG + RotL64(aCross, 20U)) + RotL64(aCarry, 39U)) + 5576603692574369341U) + aNonceWordA;
            aOrbiterK = ((aWandererH + RotL64(aIngress, 3U)) + RotL64(aCarry, 23U)) + 2720143226007220386U;
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 57U)) + 17220328778565331629U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterJ = (aWandererB + RotL64(aScatter, 27U)) + 9629485808442089423U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 1136998437010390983U) + aNonceWordM;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 11893390497814523841U;
            aOrbiterE = RotL64((aOrbiterE * 5329621622743089531U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 1764986431917532370U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 1741014798007010376U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13414914086049500731U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 12221368453236547044U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 7694538641172350430U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8439120733670016501U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 17472344518811560603U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 3308740700728172984U;
            aOrbiterC = RotL64((aOrbiterC * 15290400462887712083U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 9535358833412446771U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 11192312491731312451U;
            aOrbiterK = RotL64((aOrbiterK * 17405609148475445743U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 14850451970047190039U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 11932493299452443256U;
            aOrbiterD = RotL64((aOrbiterD * 7964808728820467795U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 5972619895614731870U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 17174497535809891690U;
            aOrbiterJ = RotL64((aOrbiterJ * 15471084511364572533U), 13U);
            //
            aIngress = RotL64(aOrbiterE, 27U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterJ, 37U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 3U));
            aIngress = aIngress + RotL64(aOrbiterF, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aPrevious, 11U) + aOrbiterE) + RotL64(aOrbiterC, 39U)) + RotL64(aCarry, 53U)) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterC, 47U)) + aOrbiterD);
            aWandererB = aWandererB + ((((RotL64(aIngress, 4U) + aOrbiterF) + RotL64(aOrbiterA, 3U)) + RotL64(aCarry, 3U)) + aNonceWordP);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterA, 20U)) + aOrbiterJ);
            aWandererG = aWandererG + (((RotL64(aCross, 47U) + RotL64(aOrbiterD, 53U)) + aOrbiterJ) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterF, 13U)) + aOrbiterK);
            aWandererF = aWandererF + ((RotL64(aScatter, 29U) + aOrbiterA) + RotL64(aOrbiterE, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererH);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + (RotL64(aWandererK, 18U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererC, 3U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ aNonceWordM;
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 19460U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20043U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19890U)) & S_BLOCK1], 52U) ^ RotL64(mSource[((aIndex + 19792U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 40U) + RotL64(aPrevious, 5U)) ^ (RotL64(aCarry, 53U) + RotL64(aIngress, 19U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 30U)) + 4773124477323378268U) + aNonceWordM;
            aOrbiterK = ((aWandererC + RotL64(aScatter, 19U)) + 16848723289435796005U) + aPhaseAOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = ((aWandererG + RotL64(aIngress, 3U)) + RotL64(aCarry, 29U)) + 13846642134917107058U;
            aOrbiterF = (aWandererH + RotL64(aCross, 47U)) + 6472057872482789939U;
            aOrbiterJ = (((aWandererA + RotL64(aPrevious, 11U)) + RotL64(aCarry, 43U)) + 2747019500690707226U) + aNonceWordF;
            aOrbiterA = ((aWandererK + RotL64(aIngress, 41U)) + 9003965289739733880U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = ((aWandererE + RotL64(aScatter, 57U)) + RotL64(aCarry, 3U)) + 3013390651936257377U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 3331004709895625067U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterC = (((aOrbiterC ^ aOrbiterG) ^ 15355010435553517129U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterC = RotL64((aOrbiterC * 8322759117004876831U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 7709870658004280052U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 13568728443963926564U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6736090830113688981U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 12409548853419307131U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 969183352023661537U) ^ aNonceWordG;
            aOrbiterK = RotL64((aOrbiterK * 5549220554838837145U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 15370309834426476775U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 3896803894396631184U;
            aOrbiterJ = RotL64((aOrbiterJ * 11018830202891911603U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 10848873633291935766U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 12885336509190543440U;
            aOrbiterG = RotL64((aOrbiterG * 1487357252619221365U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 8252290890093788010U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 9201553615601641350U;
            aOrbiterF = RotL64((aOrbiterF * 420321130559162915U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 14014209645503188472U) + aNonceWordN;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 4015071464301844550U;
            aOrbiterI = RotL64((aOrbiterI * 17444195018239904971U), 13U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterG, 3U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 27U));
            aIngress = aIngress + RotL64(aOrbiterI, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aCross, 60U) + aOrbiterA) + RotL64(aOrbiterJ, 13U)) + RotL64(aCarry, 5U)) + aNonceWordA);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 21U) + aOrbiterC) + RotL64(aOrbiterF, 27U));
            aWandererA = aWandererA + (((RotL64(aScatter, 51U) + RotL64(aOrbiterI, 35U)) + aOrbiterK) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((((RotL64(aIngress, 43U) + RotL64(aOrbiterA, 19U)) + aOrbiterI) + aNonceWordK) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 35U) + RotL64(aOrbiterA, 3U)) + aOrbiterG);
            aWandererK = aWandererK ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterA, 56U)) + aOrbiterF) + aNonceWordH);
            aWandererC = aWandererC + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterG, 47U)) + aOrbiterC) + RotL64(aCarry, 37U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 60U));
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererG, 11U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ aNonceWordF;
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22762U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24041U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24795U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneA[((aIndex + 24355U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aPrevious, 43U)) + (RotL64(aIngress, 12U) ^ RotL64(aCarry, 27U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterH = (((aWandererF + RotL64(aIngress, 13U)) + 3684295017013759987U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordL;
            aOrbiterI = (aWandererI + RotL64(aScatter, 35U)) + 6740408842457292881U;
            aOrbiterB = (((aWandererE + RotL64(aCross, 5U)) + RotL64(aCarry, 3U)) + 4563975890702399441U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 41U)) + RotL64(aCarry, 51U)) + 797804144825287940U;
            aOrbiterF = (aWandererK + RotL64(aScatter, 60U)) + 2763779540450101303U;
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 51U)) + RotL64(aCarry, 29U)) + 13211846164102089685U;
            aOrbiterA = (aWandererB + RotL64(aCross, 19U)) + 15214578447281401982U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 13745208628754232427U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 17358621225969190747U) ^ aNonceWordJ;
            aOrbiterB = RotL64((aOrbiterB * 5325024317338823061U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 779739369960480023U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 4370963533701407813U;
            aOrbiterH = RotL64((aOrbiterH * 3123135216876641039U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 6061333005507739975U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 3589705340762734456U) ^ aNonceWordE;
            aOrbiterD = RotL64((aOrbiterD * 16499293983611196967U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 10607697666369230567U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 9356757995305239271U;
            aOrbiterI = RotL64((aOrbiterI * 10945513661439954731U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 10093033335903048138U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 11037328061699834100U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11189760551792389605U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 558431161176115540U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 17795680919453449358U;
            aOrbiterE = RotL64((aOrbiterE * 3910117359996283803U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 6096779391116214109U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 17594243286880690775U;
            aOrbiterA = RotL64((aOrbiterA * 12655610181937429915U), 5U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterE, 11U);
            aIngress = aIngress + (RotL64(aOrbiterA, 43U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterD, 51U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterB, 18U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterB, 35U)) + aOrbiterD);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 4U) + RotL64(aOrbiterE, 14U)) + aOrbiterI) + RotL64(aCarry, 21U)) + aNonceWordM);
            aWandererF = aWandererF ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterE, 57U)) + aOrbiterA) + aNonceWordK);
            aWandererK = aWandererK + (((RotL64(aIngress, 29U) + aOrbiterF) + RotL64(aOrbiterA, 27U)) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterB, 5U)) + aOrbiterH) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 19U) + aOrbiterA) + RotL64(aOrbiterB, 41U)) + aNonceWordB);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterE, 47U)) + aOrbiterB) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 40U));
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererE, 19U);
            aCarry = aCarry + RotL64(aIngress, 44U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordC);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 27471U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneB[((aIndex + 27597U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30843U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneB[((aIndex + 30066U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 54U) + RotL64(aPrevious, 41U)) ^ (RotL64(aIngress, 3U) ^ RotL64(aCross, 21U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterI = ((aWandererB + RotL64(aCross, 37U)) + RotL64(aCarry, 53U)) + 3236820517816085022U;
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 19U)) + 741288875914097926U) + aPhaseAOrbiterAssignSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterC = (((aWandererI + RotL64(aScatter, 11U)) + RotL64(aCarry, 23U)) + 8417246926007729580U) + aNonceWordF;
            aOrbiterH = (aWandererA + RotL64(aIngress, 53U)) + 9715717805774537170U;
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 29U)) + RotL64(aCarry, 41U)) + 14360243844821619482U;
            aOrbiterG = (aWandererJ + RotL64(aIngress, 43U)) + 10760908100206775334U;
            aOrbiterD = (((aWandererE + RotL64(aCross, 4U)) + 3434641779946167811U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordG;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 7885568822756234567U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 3041563437672051294U;
            aOrbiterC = RotL64((aOrbiterC * 11440300917533482297U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 15761355327564963516U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 1158633562785937421U) ^ aNonceWordH;
            aOrbiterJ = RotL64((aOrbiterJ * 15511324886867188235U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 9338581575871970653U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 9172038894262857354U;
            aOrbiterG = RotL64((aOrbiterG * 3110871165285625807U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 14653924713599790081U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 3854497592598563309U;
            aOrbiterD = RotL64((aOrbiterD * 11737111068815795303U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 16286980180327600557U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 5092583772591249756U;
            aOrbiterI = RotL64((aOrbiterI * 13955105624639442903U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 4288397994175567333U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 15584236478994873104U;
            aOrbiterH = RotL64((aOrbiterH * 1860480595862755379U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 5557463939827483792U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 2659814275753280856U;
            aOrbiterE = RotL64((aOrbiterE * 17702430405693184643U), 29U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterH, 21U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 29U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 5U));
            aIngress = aIngress + RotL64(aOrbiterE, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 21U) + aOrbiterD) + RotL64(aOrbiterE, 13U));
            aWandererA = aWandererA + ((((RotL64(aScatter, 43U) + aOrbiterI) + RotL64(aOrbiterE, 60U)) + RotL64(aCarry, 29U)) + aNonceWordO);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 23U)) + aOrbiterC);
            aWandererI = aWandererI + (((((RotL64(aIngress, 10U) + aOrbiterG) + RotL64(aOrbiterC, 3U)) + RotL64(aCarry, 13U)) + aNonceWordD) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 51U) + aOrbiterD) + RotL64(aOrbiterJ, 35U)) + aNonceWordP);
            aWandererE = aWandererE + (((RotL64(aIngress, 29U) + aOrbiterG) + RotL64(aOrbiterH, 41U)) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 35U) + aOrbiterD) + RotL64(aOrbiterC, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererG);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + (RotL64(aWandererE, 14U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererB, 57U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ aNonceWordN;
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

void TwistExpander_Bowling_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xF3EC7131FF6B8E27ULL + 0x95CBA4B47A5A486DULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xAF1FDF703AFED259ULL + 0x96FB86E5596A21CCULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xE9BAAD9133F7DCC7ULL + 0x91A69531023DC7B5ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x8E70672B6B13FD29ULL + 0xCF536A2BA86958F0ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xF7342A85C970BE9FULL + 0x851D642896848922ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xB12B51426A4B926BULL + 0xAE33BFB2A42921B1ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xB299EF15B12F2FABULL + 0x9BF040BFDB882DE6ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x9145F6E9A3DF6C37ULL + 0xE08464963C3D96B7ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xCD0E98F08D2CBAC9ULL + 0xD6FDA733DE32F427ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xCBE39F60663D5BB7ULL + 0x82EFBCD3E6873C40ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xA4224A26C0F2C77BULL + 0xA8A82996FF75D877ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xF2D2CBA960CA33EDULL + 0xC14BF5E17798F07DULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xD3FD763ADA1D713BULL + 0xC9DAE089AFFBA47BULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xE6386E2518D29011ULL + 0xC8A43C3D9AACF577ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xD809907964BA8D89ULL + 0xA4D59AAB7D452932ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xCEDA43235D872615ULL + 0x958E11A9B537EEE9ULL);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 3300U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1969U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 988U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 2654U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 50U) + RotL64(aPrevious, 35U)) + (RotL64(aCarry, 19U) ^ RotL64(aIngress, 5U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterK = ((aWandererC + RotL64(aScatter, 5U)) + RotL64(aCarry, 35U)) + 1042610313571524121U;
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 39U)) + 3505725321008825582U) + aNonceWordE;
            aOrbiterD = ((aWandererK + RotL64(aIngress, 50U)) + RotL64(aCarry, 5U)) + 12584654563843782991U;
            aOrbiterA = ((aWandererA + RotL64(aCross, 29U)) + 6645399144515770935U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = ((((aWandererD + RotL64(aPrevious, 21U)) + RotL64(aCarry, 23U)) + 3608978423753715584U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordF;
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 8089198857670370983U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 15207251813516399879U;
            aOrbiterD = RotL64((aOrbiterD * 7596841660069752069U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 9579268660105824516U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 16055044469473802812U;
            aOrbiterK = RotL64((aOrbiterK * 2269649280637188723U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 583811872609805949U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 7027491967970873942U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12686754713465826139U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 18256061823189677508U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = (((aOrbiterH ^ aOrbiterF) ^ 12708429127816136937U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterH = RotL64((aOrbiterH * 12593886633108075321U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 12169216645156306078U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 12694325407567795065U;
            aOrbiterF = RotL64((aOrbiterF * 3711789483877261899U), 3U);
            //
            aIngress = RotL64(aOrbiterA, 27U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterH, 47U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((((RotL64(aPrevious, 43U) + RotL64(aOrbiterD, 37U)) + aOrbiterK) + RotL64(aCarry, 5U)) + aNonceWordN) + aPhaseBWandererUpdateSaltC[((aIndex + 28U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 57U) + aOrbiterF) + RotL64(aOrbiterK, 47U));
            aWandererA = aWandererA + (((RotL64(aCross, 21U) + RotL64(aOrbiterH, 26U)) + aOrbiterF) + RotL64(aCarry, 41U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 4U) + RotL64(aOrbiterA, 57U)) + aOrbiterH);
            aWandererK = aWandererK + (((RotL64(aIngress, 29U) + RotL64(aOrbiterD, 3U)) + aOrbiterF) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + RotL64(aWandererK, 30U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ aNonceWordM;
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10749U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneD[((aIndex + 10206U)) & S_BLOCK1], 36U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5782U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 10737U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 21U) ^ RotL64(aIngress, 39U)) + (RotL64(aPrevious, 4U) + RotL64(aCross, 53U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterF = (aWandererD + RotL64(aCross, 58U)) + 13714409587461539863U;
            aOrbiterA = (((aWandererC + RotL64(aPrevious, 29U)) + RotL64(aCarry, 41U)) + 14101156723903265839U) + aNonceWordJ;
            aOrbiterI = ((aWandererI + RotL64(aScatter, 39U)) + RotL64(aCarry, 57U)) + 7063754562895369001U;
            aOrbiterK = ((((aWandererG + RotL64(aIngress, 21U)) + RotL64(aCarry, 13U)) + 12320578575245519386U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordB;
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 47U)) + 11744826789631008424U) + aPhaseBOrbiterAssignSaltB[((aIndex + 4U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 8744816505096675597U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 10405435520084528645U;
            aOrbiterI = RotL64((aOrbiterI * 13279521344071568023U), 57U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterK) + 1463157688070683543U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1]) + aNonceWordG;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 12379603577919617703U;
            aOrbiterJ = RotL64((aOrbiterJ * 14858901470015109311U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 1343439118031348146U) + aNonceWordO;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 16118850268070235540U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11184386483735388257U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 14116264435819277136U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 5251698273012432109U;
            aOrbiterA = RotL64((aOrbiterA * 1495818611622063967U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 14806408656041403829U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 11569345414052398227U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9913158908301414861U), 3U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterI, 57U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 35U));
            aIngress = aIngress + RotL64(aOrbiterJ, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterA, 3U)) + aOrbiterF) + RotL64(aCarry, 41U)) + aNonceWordE);
            aWandererD = aWandererD ^ (((RotL64(aCross, 30U) + aOrbiterF) + RotL64(aOrbiterJ, 58U)) + aNonceWordN);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 21U) + RotL64(aOrbiterI, 21U)) + aOrbiterJ) + RotL64(aCarry, 29U)) + aNonceWordI);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterK, 35U)) + aOrbiterI) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 43U) + aOrbiterK) + RotL64(aOrbiterF, 47U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 54U));
            aCarry = aCarry + (RotL64(aWandererG, 41U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererD, 3U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordG);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 15689U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((aIndex + 11758U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 12771U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneC[((aIndex + 15746U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aPrevious, 39U)) + (RotL64(aIngress, 6U) ^ RotL64(aCarry, 51U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterD = ((((aWandererI + RotL64(aCross, 3U)) + RotL64(aCarry, 23U)) + 3917730204724097072U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordH;
            aOrbiterE = ((aWandererH + RotL64(aIngress, 53U)) + RotL64(aCarry, 5U)) + 1874642340716212824U;
            aOrbiterA = ((aWandererA + RotL64(aScatter, 24U)) + 6900165757434854160U) + aNonceWordN;
            aOrbiterB = ((((aWandererK + RotL64(aPrevious, 39U)) + RotL64(aCarry, 53U)) + 12750946097023807161U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordD;
            aOrbiterI = (aWandererC + RotL64(aCross, 13U)) + 6563216048479513594U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 14960240191349450795U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 16306180275951788289U) ^ aNonceWordI;
            aOrbiterA = RotL64((aOrbiterA * 12077366095522790283U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 6502066618271045547U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 6219852857850888738U;
            aOrbiterE = RotL64((aOrbiterE * 10892297250334325283U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 2272931312452845850U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 3028929882263199463U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11005324285856805069U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 6067393030073568112U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 10094809900437037258U;
            aOrbiterB = RotL64((aOrbiterB * 18095564940730322769U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 5962414178157074575U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 15755563045799129417U;
            aOrbiterI = RotL64((aOrbiterI * 3692603590609922031U), 37U);
            //
            aIngress = RotL64(aOrbiterB, 5U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterE, 46U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 57U) + aOrbiterE) + RotL64(aOrbiterD, 57U));
            aWandererC = aWandererC + (((RotL64(aIngress, 3U) + aOrbiterA) + RotL64(aOrbiterI, 14U)) + RotL64(aCarry, 21U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 35U) + aOrbiterB) + RotL64(aOrbiterA, 39U)) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererI = aWandererI + (((((RotL64(aCross, 12U) + RotL64(aOrbiterB, 29U)) + aOrbiterD) + RotL64(aCarry, 57U)) + aNonceWordM) + aPhaseBWandererUpdateSaltB[((aIndex + 22U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 21U) + aOrbiterB) + RotL64(aOrbiterI, 47U)) + aNonceWordE);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 21U));
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererA, 39U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ aNonceWordJ;
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 20086U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneB[((aIndex + 18253U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18073U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 21443U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 3U) + RotL64(aCarry, 19U)) ^ (RotL64(aIngress, 54U) + RotL64(aCross, 41U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterJ = (((aWandererG + RotL64(aIngress, 37U)) + RotL64(aCarry, 27U)) + 3561491146322798260U) + aNonceWordA;
            aOrbiterB = (aWandererB + RotL64(aPrevious, 46U)) + 7075025056181885339U;
            aOrbiterC = (((aWandererE + RotL64(aCross, 29U)) + RotL64(aCarry, 5U)) + 9230910887904171613U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = (((aWandererI + RotL64(aScatter, 19U)) + RotL64(aCarry, 41U)) + 4119781172609908917U) + aNonceWordC;
            aOrbiterE = (((aWandererF + RotL64(aCross, 57U)) + 17155609083870983149U) + aPhaseBOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1]) + aNonceWordN;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 2423018561430181695U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 12957280305617615744U;
            aOrbiterC = RotL64((aOrbiterC * 17696410107705645631U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 2461704174772065813U) + aNonceWordK;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 7907123257849391997U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9416171962847312179U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 7257868138318960007U) + aNonceWordH;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 16425903703085702285U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7996935869077231999U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 2990822664594079467U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 5654819006718953817U;
            aOrbiterB = RotL64((aOrbiterB * 4465096036756887801U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 12183676471235678779U) + aNonceWordJ;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 15026286960542123922U;
            aOrbiterE = RotL64((aOrbiterE * 17199049329995315279U), 19U);
            //
            aIngress = RotL64(aOrbiterJ, 37U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterE, 27U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterB, 50U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aScatter, 40U) + RotL64(aOrbiterC, 21U)) + aOrbiterB) + aNonceWordO);
            aWandererE = aWandererE + ((((RotL64(aIngress, 53U) + aOrbiterE) + RotL64(aOrbiterI, 51U)) + RotL64(aCarry, 5U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 27U) + aOrbiterC) + RotL64(aOrbiterI, 13U)) + aNonceWordG);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterJ, 4U)) + aOrbiterE) + RotL64(aCarry, 41U)) + aNonceWordE);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 13U) + aOrbiterB) + RotL64(aOrbiterJ, 29U)) + aPhaseBWandererUpdateSaltE[((aIndex + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 21U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererG, 53U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 5U);
            aCarry = aCarry + RotL64(aIngress, 44U);
            aCarry = aCarry ^ aNonceWordA;
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 21968U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 26722U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27267U)) & S_BLOCK1], 40U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23964U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 42U) + RotL64(aPrevious, 29U)) + (RotL64(aIngress, 57U) ^ RotL64(aCross, 5U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 3U)) + 13880995121909552664U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 47U)) + 14534942818069300546U) + aPhaseBOrbiterAssignSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = ((aWandererI + RotL64(aCross, 13U)) + RotL64(aCarry, 57U)) + 17745973100886007133U;
            aOrbiterG = ((aWandererE + RotL64(aScatter, 57U)) + RotL64(aCarry, 35U)) + 2249805580771946872U;
            aOrbiterF = (((aWandererH + RotL64(aIngress, 34U)) + RotL64(aCarry, 21U)) + 4460116116396439410U) + aNonceWordP;
            //
            aOrbiterK = (((aOrbiterK + aOrbiterH) + 3378683994078106878U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1]) + aNonceWordO;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 3992996501048809123U;
            aOrbiterB = RotL64((aOrbiterB * 13273544260537223797U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 12057768808864451929U) + aNonceWordA;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 4115362079047921130U;
            aOrbiterF = RotL64((aOrbiterF * 12263015903331031345U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 15297384955502206698U) + aNonceWordB;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 17623548383481905636U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7487278217901483685U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 3559213898000162417U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 12311605719074507335U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3982199462062847697U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 14807313864347885885U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 11222085523291581822U;
            aOrbiterG = RotL64((aOrbiterG * 12580941911587215653U), 57U);
            //
            aIngress = RotL64(aOrbiterH, 23U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterF, 54U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterB, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aPrevious, 6U) + RotL64(aOrbiterH, 21U)) + aOrbiterG);
            aWandererF = aWandererF ^ (((RotL64(aCross, 21U) + aOrbiterG) + RotL64(aOrbiterB, 53U)) + aNonceWordM);
            aWandererI = aWandererI + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterF, 29U)) + aOrbiterH) + RotL64(aCarry, 23U)) + aNonceWordK);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterF, 12U)) + aOrbiterK) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 53U) + aOrbiterB) + RotL64(aOrbiterF, 3U)) + RotL64(aCarry, 51U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 56U));
            aCarry = aCarry + (RotL64(aWandererF, 23U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererJ, 3U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ aNonceWordC;
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 28521U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneB[((aIndex + 31127U)) & S_BLOCK1], 36U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 30222U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28706U)) & S_BLOCK1], 10U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCross, 5U)) + (RotL64(aCarry, 30U) ^ RotL64(aPrevious, 43U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterC = ((((aWandererK + RotL64(aScatter, 44U)) + RotL64(aCarry, 57U)) + 16016931609704150191U) + aPhaseBOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1]) + aNonceWordK;
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 13U)) + 14511433515861302636U) + aPhaseBOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = (aWandererC + RotL64(aIngress, 53U)) + 11691237442613269593U;
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 5U)) + RotL64(aCarry, 27U)) + 16383220587320484649U;
            aOrbiterH = (((aWandererF + RotL64(aCross, 35U)) + RotL64(aCarry, 13U)) + 14293015313458219868U) + aNonceWordL;
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 4407695248205526670U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 1158323195324398372U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7489061637031434357U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 6577683409653864555U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 171080079472863843U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3063978974927752653U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 5766333425872228205U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 16173508656917582960U;
            aOrbiterC = RotL64((aOrbiterC * 12187968015372936695U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 11781450063402219202U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 13033139686637576694U) ^ aNonceWordN;
            aOrbiterD = RotL64((aOrbiterD * 4331137994135472025U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 4006310759400926020U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 13156817947481574467U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 563189239835001483U), 3U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterD, 35U);
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 46U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterC, 27U)) + aOrbiterH) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererF = aWandererF + (((((RotL64(aPrevious, 41U) + aOrbiterK) + RotL64(aOrbiterD, 5U)) + RotL64(aCarry, 11U)) + aNonceWordD) + aPhaseBWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 5U) + aOrbiterJ) + RotL64(aOrbiterH, 47U)) + aNonceWordA);
            aWandererK = aWandererK + (((RotL64(aScatter, 27U) + aOrbiterK) + RotL64(aOrbiterC, 37U)) + RotL64(aCarry, 39U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 52U) + RotL64(aOrbiterD, 14U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 21U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 39U));
            aCarry = aCarry + RotL64(aWandererH, 30U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ aNonceWordB;
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

void TwistExpander_Bowling_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xDCCC47FB2AFDC3C7ULL + 0xDAD7AE6845206C1EULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xD7DF2DFE08208401ULL + 0x947327F838EE4FDEULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xF249F57FAF8176D9ULL + 0xE2EF71BEB63FE4BBULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xAAC63520A3BCCC31ULL + 0xE0F55A029CC97CB9ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x8BB12A6FAF003587ULL + 0xFDBA06227AF63E11ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x92A3BF1FDB07659FULL + 0xDAB1E2B8991CA8E0ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xCB1305E4EBB34C5BULL + 0xEA05868DB611FCECULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xBB7482F826C4D15FULL + 0x8F995D5B34ABCAF4ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xE044FE5AC8FE13B1ULL + 0x84A33E06DBC30F06ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xF128EB5438C5353DULL + 0xC52D9DCB77603CDDULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xAC7E4267305DA0CFULL + 0x909657CBBCF13A69ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xC2686FC30B1B0C93ULL + 0xC94602AEC1E5669DULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xABB8922472E60245ULL + 0x8D380904B49B0461ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xAA14E6A214D57095ULL + 0xC045CFD53ED77D2FULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xECAE6F0E3298FAF7ULL + 0xCA2F645D5D4797FBULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xB282DADB65664587ULL + 0xAD5133A65BFD25F4ULL);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 5303U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 8032U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 4363U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 2835U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCross, 51U) + RotL64(aIngress, 38U)) ^ (RotL64(aCarry, 3U) + RotL64(aPrevious, 23U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterF = (aWandererE + RotL64(aCross, 57U)) + 2330952702412094686U;
            aOrbiterE = (aWandererI + RotL64(aPrevious, 46U)) + 7820188225935060799U;
            aOrbiterJ = (aWandererK + RotL64(aScatter, 3U)) + 9347644591709839145U;
            aOrbiterK = ((aWandererG + RotL64(aIngress, 37U)) + 2288624878446846870U) + aNonceWordC;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 13U)) + RotL64(aCarry, 57U)) + 9358977729492824128U;
            aOrbiterB = (aWandererF + RotL64(aCross, 27U)) + 1858511275052455039U;
            aOrbiterG = (((aWandererJ + RotL64(aIngress, 19U)) + RotL64(aCarry, 41U)) + 13715478509322292552U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = ((aWandererH + RotL64(aScatter, 52U)) + RotL64(aCarry, 23U)) + 16413396625604260455U;
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 41U)) + 17714322215518432705U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 16188315436202861122U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 5564445841368207813U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14125834616162835983U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 13717068949900594673U) + aNonceWordA;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 14143659432287313765U;
            aOrbiterB = RotL64((aOrbiterB * 17281441046722262917U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 5729546141908425670U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 4297827922736712074U;
            aOrbiterI = RotL64((aOrbiterI * 13631630436759768885U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 829520109395163673U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 11547160328525174295U;
            aOrbiterA = RotL64((aOrbiterA * 4759690159673049775U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 2907177944512117206U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 11100346409065275671U;
            aOrbiterF = RotL64((aOrbiterF * 17927994356809011637U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 1344592529249949068U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 6470438516791143572U;
            aOrbiterK = RotL64((aOrbiterK * 13339390828725370475U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 5217751823741520847U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 5371275223586938039U;
            aOrbiterG = RotL64((aOrbiterG * 12318403075523724125U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 14218103150268532919U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 1367628876596800571U;
            aOrbiterE = RotL64((aOrbiterE * 13777531272321533137U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 2372041991018455610U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 9870744274890595581U) ^ aNonceWordD;
            aOrbiterD = RotL64((aOrbiterD * 12093443117747395585U), 51U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterB, 51U);
            aIngress = aIngress + (RotL64(aOrbiterE, 43U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterI, 40U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterF, 37U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterK, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterG, 13U)) + aOrbiterA);
            aWandererE = aWandererE + (((RotL64(aIngress, 60U) + RotL64(aOrbiterB, 52U)) + aOrbiterJ) + aNonceWordI);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterG, 57U)) + aOrbiterB);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 47U) + aOrbiterK) + RotL64(aOrbiterJ, 23U)) + RotL64(aCarry, 23U)) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterJ, 3U)) + aOrbiterD);
            aWandererC = aWandererC + ((RotL64(aCross, 29U) + RotL64(aOrbiterF, 40U)) + aOrbiterI);
            aWandererG = aWandererG ^ ((((RotL64(aPrevious, 51U) + RotL64(aOrbiterB, 29U)) + aOrbiterF) + aNonceWordP) + aPhaseCWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 24U) + RotL64(aOrbiterA, 19U)) + aOrbiterE) + RotL64(aCarry, 11U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 5U) + aOrbiterG) + RotL64(aOrbiterK, 47U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 21U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 5U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 38U));
            aCarry = aCarry + RotL64(aWandererH, 43U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordO);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 14946U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 15583U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 12876U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 12258U)) & S_BLOCK1], 36U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 11U)) + (RotL64(aIngress, 23U) ^ RotL64(aCross, 58U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 30U)) + RotL64(aCarry, 13U)) + 16189787374324972735U;
            aOrbiterB = (((aWandererJ + RotL64(aScatter, 19U)) + RotL64(aCarry, 39U)) + 17563763730956242224U) + aPhaseCOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = (((aWandererK + RotL64(aCross, 43U)) + 10572803498593789385U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordA;
            aOrbiterI = (aWandererH + RotL64(aIngress, 37U)) + 7713105232072974166U;
            aOrbiterK = (aWandererC + RotL64(aScatter, 13U)) + 10760839534772718139U;
            aOrbiterC = (aWandererB + RotL64(aPrevious, 60U)) + 13397069448391230253U;
            aOrbiterE = (aWandererI + RotL64(aIngress, 23U)) + 4569255679998375682U;
            aOrbiterD = ((aWandererE + RotL64(aCross, 51U)) + RotL64(aCarry, 21U)) + 9888769350817876949U;
            aOrbiterJ = (aWandererD + RotL64(aIngress, 47U)) + 11351796060878856300U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 18153775071965707204U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 1282846411145853435U;
            aOrbiterH = RotL64((aOrbiterH * 12294455920906257823U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 16457743979262460660U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 173493260775251032U;
            aOrbiterK = RotL64((aOrbiterK * 4935807229040883505U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 3927345926316409630U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 5158769729850853623U;
            aOrbiterE = RotL64((aOrbiterE * 2446452358663812945U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 12331351600010165154U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 3940794200348684050U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13248997263062075043U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 11248514843822945425U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 1391497323278226522U;
            aOrbiterJ = RotL64((aOrbiterJ * 8376841806072565005U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 13265623528678787307U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 2802033745265647317U;
            aOrbiterA = RotL64((aOrbiterA * 3437626962562016147U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 6938444301018051844U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 1086544666755559028U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16039728388882079889U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 16156443117365816536U) + aNonceWordO;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 3619942859562697142U;
            aOrbiterC = RotL64((aOrbiterC * 7589346043159112151U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 17681848914912743292U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 8848238631758130416U;
            aOrbiterB = RotL64((aOrbiterB * 810402256099500607U), 43U);
            //
            aIngress = RotL64(aOrbiterK, 56U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterD, 53U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 19U));
            aIngress = aIngress + RotL64(aOrbiterJ, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterD, 27U)) + aOrbiterH);
            aWandererH = aWandererH + ((RotL64(aPrevious, 24U) + RotL64(aOrbiterH, 11U)) + aOrbiterA);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterK, 52U)) + aOrbiterC) + aPhaseCWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 51U) + aOrbiterC) + RotL64(aOrbiterH, 35U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 19U) + aOrbiterJ) + RotL64(aOrbiterI, 5U));
            aWandererK = aWandererK + (((RotL64(aScatter, 29U) + RotL64(aOrbiterI, 57U)) + aOrbiterE) + RotL64(aCarry, 41U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterB, 48U)) + aOrbiterD) + aPhaseCWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aIngress, 56U) + aOrbiterC) + RotL64(aOrbiterD, 19U)) + RotL64(aCarry, 11U)) + aNonceWordG);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterK, 41U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 10U) ^ aWandererD);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 53U));
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererH, 19U);
            aCarry = aCarry + RotL64(aIngress, 58U);
            aCarry = aCarry ^ aNonceWordC;
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 23356U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((aIndex + 16482U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 23085U)) & S_BLOCK1], 6U) ^ RotL64(aOperationLaneC[((aIndex + 22339U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCross, 27U) ^ RotL64(aPrevious, 41U)) + (RotL64(aIngress, 6U) ^ RotL64(aCarry, 53U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterI = (aWandererC + RotL64(aCross, 19U)) + 13296600294247799698U;
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 52U)) + RotL64(aCarry, 13U)) + 5818503518080877515U;
            aOrbiterA = (((aWandererI + RotL64(aIngress, 57U)) + RotL64(aCarry, 43U)) + 6735784238734173597U) + aNonceWordM;
            aOrbiterJ = (aWandererJ + RotL64(aScatter, 23U)) + 7368398209488856201U;
            aOrbiterB = ((aWandererA + RotL64(aIngress, 29U)) + 961734029066455638U) + aNonceWordK;
            aOrbiterH = (aWandererH + RotL64(aCross, 5U)) + 797011946660892011U;
            aOrbiterG = (aWandererD + RotL64(aPrevious, 39U)) + 12841876018396622350U;
            aOrbiterE = (((aWandererF + RotL64(aScatter, 35U)) + RotL64(aCarry, 29U)) + 16213253970483895623U) + aPhaseCOrbiterAssignSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = ((aWandererE + RotL64(aCross, 14U)) + 15186950557113470375U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 5117930310827477341U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 12265429373166094162U;
            aOrbiterA = RotL64((aOrbiterA * 1522823535151532249U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 13920531346698601568U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 14695405206998211456U;
            aOrbiterI = RotL64((aOrbiterI * 13950964363414164279U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 7851960904825938443U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 9501511171732550190U;
            aOrbiterJ = RotL64((aOrbiterJ * 5614164120361489613U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 5663365182245722077U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 9607860124321315555U;
            aOrbiterD = RotL64((aOrbiterD * 3461820361914280601U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 18171052650586819280U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 3442698321538580861U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6317525514963824829U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 1491052813469258970U) + aNonceWordO;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 3956599824067616133U;
            aOrbiterH = RotL64((aOrbiterH * 2928600779267623085U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 10963841237346073453U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 2303020125591252534U;
            aOrbiterG = RotL64((aOrbiterG * 9969099842343321981U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 14503856057958162356U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 11147548150090597694U;
            aOrbiterE = RotL64((aOrbiterE * 11856382308792700441U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 9191681438318311481U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 13556072770381999852U;
            aOrbiterK = RotL64((aOrbiterK * 18316231099054203683U), 39U);
            //
            aIngress = RotL64(aOrbiterJ, 60U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 39U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 11U));
            aIngress = aIngress + (RotL64(aOrbiterG, 29U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterH, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aScatter, 21U) + aOrbiterB) + RotL64(aOrbiterI, 19U)) + aNonceWordA);
            aWandererI = aWandererI + (((RotL64(aPrevious, 60U) + aOrbiterB) + RotL64(aOrbiterD, 58U)) + RotL64(aCarry, 29U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterH, 35U)) + aOrbiterK);
            aWandererA = aWandererA + ((((RotL64(aIngress, 29U) + aOrbiterJ) + RotL64(aOrbiterI, 47U)) + RotL64(aCarry, 19U)) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 35U) + aOrbiterA) + RotL64(aOrbiterK, 53U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterG, 43U)) + aOrbiterD);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 56U) + aOrbiterH) + RotL64(aOrbiterD, 13U));
            aWandererC = aWandererC + (((RotL64(aScatter, 11U) + RotL64(aOrbiterE, 29U)) + aOrbiterK) + aPhaseCWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 51U) + aOrbiterJ) + RotL64(aOrbiterD, 4U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererC, 53U) ^ aWandererF);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 41U));
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererA, 35U);
            aCarry = aCarry + RotL64(aIngress, 58U);
            aCarry = aCarry ^ aNonceWordF;
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 30805U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneB[((aIndex + 32432U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 29810U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 31772U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCarry, 14U)) ^ (RotL64(aCross, 29U) + RotL64(aPrevious, 57U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterF = ((aWandererE + RotL64(aIngress, 10U)) + RotL64(aCarry, 43U)) + 2101601659597850213U;
            aOrbiterA = (aWandererJ + RotL64(aScatter, 35U)) + 2759794072560720121U;
            aOrbiterG = ((aWandererB + RotL64(aCross, 23U)) + RotL64(aCarry, 3U)) + 9443562552411269339U;
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 57U)) + 10801360546699857975U) + aNonceWordA;
            aOrbiterH = (aWandererA + RotL64(aCross, 4U)) + 8020716394829332019U;
            aOrbiterC = (((aWandererH + RotL64(aScatter, 43U)) + 1021894212367773801U) + aPhaseCOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1]) + aNonceWordF;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 39U)) + RotL64(aCarry, 13U)) + 13346855534622490176U;
            aOrbiterB = ((aWandererD + RotL64(aIngress, 29U)) + 16359309548462953836U) + aNonceWordB;
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 47U)) + 12642446944680783519U) + aPhaseCOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 8197424982767553380U) + aNonceWordD;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 14346334610901859094U;
            aOrbiterG = RotL64((aOrbiterG * 16982899923227935679U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 14171304260534233539U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 334531601308283605U;
            aOrbiterH = RotL64((aOrbiterH * 5012968232749075075U), 43U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterH) + 10707856298471572695U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1]) + aNonceWordN;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 18364775750091914766U;
            aOrbiterD = RotL64((aOrbiterD * 15735143943129143265U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 8531394793118363836U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 15352876929406908882U;
            aOrbiterF = RotL64((aOrbiterF * 475199047053777179U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 567682016232278157U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 2068146551757663119U;
            aOrbiterK = RotL64((aOrbiterK * 1557877740957797555U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 7776122587613256525U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 16430938890724272256U;
            aOrbiterC = RotL64((aOrbiterC * 4540270493783593257U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 11912000645055436094U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 16800749242578741498U;
            aOrbiterB = RotL64((aOrbiterB * 17804584625034241737U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 5909199180260499150U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 5751089915336865588U;
            aOrbiterI = RotL64((aOrbiterI * 15376689503142397927U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 3478216857728853008U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 18007567146937338241U;
            aOrbiterA = RotL64((aOrbiterA * 6620498877303917855U), 47U);
            //
            aIngress = RotL64(aOrbiterG, 42U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterF, 57U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterI, 47U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterB, 19U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterD, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 3U)) + aOrbiterG);
            aWandererE = aWandererE + (((RotL64(aPrevious, 23U) + aOrbiterC) + RotL64(aOrbiterA, 38U)) + RotL64(aCarry, 13U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 57U) + aOrbiterD) + RotL64(aOrbiterI, 23U));
            aWandererH = aWandererH + (((RotL64(aCross, 50U) + aOrbiterC) + RotL64(aOrbiterH, 19U)) + aNonceWordM);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 37U) + aOrbiterC) + RotL64(aOrbiterB, 27U)) + aPhaseCWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 13U) + aOrbiterF) + RotL64(aOrbiterK, 13U)) + aNonceWordO);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 19U) + aOrbiterB) + RotL64(aOrbiterD, 43U)) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 27U) + aOrbiterD) + RotL64(aOrbiterH, 58U)) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 46U) + RotL64(aOrbiterF, 53U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 60U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererB, 21U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererE, 43U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ aNonceWordC;
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

void TwistExpander_Bowling_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xD34390F8B6568AABULL + 0x93862734FCA2435AULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xA9DFB3144A705F5DULL + 0xDA8A35976B58080AULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xB2C2BB7B9A31BFC7ULL + 0xFAAF16671B5B73BAULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xC21AC3DE4D351FB7ULL + 0x8AFAA2E0D13FC01DULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xFCE471927C84265BULL + 0x869810D9247D1561ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xD59C9877EBDA47ADULL + 0xD304A7731692638AULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xCEE0276D7FC09C0BULL + 0x820CED96E80F2BBBULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xCC763234A3CAE8C1ULL + 0x9291BD357A136FECULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x96D5323CA169907BULL + 0xBB87CF548D6598CFULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x89C04DAD0E0F177FULL + 0x97639FCE0CA3351DULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xFA89B4C94897A66FULL + 0x9766D23E1466B87AULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x8A2C1EC11BE517BBULL + 0xB87B7055406B4A58ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xD5B13F5A843B3A75ULL + 0x9A2091292A9FC3B0ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xBC769A583235D071ULL + 0xF9C826EC80233A4CULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xFDB3D58C6D42DF0BULL + 0xA2E7D1659CB34066ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xD83ECF6A03E7161BULL + 0xE48EF027A21D9EE1ULL);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 1148U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2375U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4178U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 625U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aPrevious, 37U)) ^ (RotL64(aIngress, 6U) ^ RotL64(aCross, 19U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterE = (aWandererI + RotL64(aScatter, 41U)) + 3970829908171131502U;
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 51U)) + 7040283759419531991U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterD = (aWandererA + RotL64(aCross, 48U)) + 11856292169397052901U;
            aOrbiterB = (aWandererE + RotL64(aIngress, 43U)) + 819598588791819022U;
            aOrbiterA = ((aWandererG + RotL64(aCross, 13U)) + RotL64(aCarry, 57U)) + 2176451710970866848U;
            aOrbiterK = (aWandererC + RotL64(aPrevious, 53U)) + 6454704928613390494U;
            aOrbiterG = ((aWandererK + RotL64(aIngress, 56U)) + RotL64(aCarry, 47U)) + 11792122387218053841U;
            aOrbiterJ = (((aWandererB + RotL64(aScatter, 29U)) + RotL64(aCarry, 37U)) + 9254780213489752211U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 5U)) + 16591812589999846482U) + aNonceWordH;
            aOrbiterH = ((aWandererD + RotL64(aScatter, 11U)) + 1471246223935074832U) + aNonceWordK;
            aOrbiterI = ((aWandererH + RotL64(aCross, 37U)) + 1424843083106386453U) + aNonceWordN;
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 1856469958050891629U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 6331743690452052712U;
            aOrbiterD = RotL64((aOrbiterD * 15327924647897459645U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 10351075711345476487U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 9518585245330480185U;
            aOrbiterK = RotL64((aOrbiterK * 3792179827396760391U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 17787514620244712033U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 14182328067398162557U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 18107337388659070197U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 12798088948801072444U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 9563215159275202323U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7058145016617349141U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 9904919772580498232U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 16579777394992143043U;
            aOrbiterG = RotL64((aOrbiterG * 10516761340320196661U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 6344049286854588503U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 3531503618941046788U;
            aOrbiterF = RotL64((aOrbiterF * 10855385899703024105U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 11334308840132700377U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 11093833870078787770U;
            aOrbiterI = RotL64((aOrbiterI * 16105889714648555755U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 3831491136025364271U) + aNonceWordM;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 12505259454860591372U;
            aOrbiterC = RotL64((aOrbiterC * 6135450888433504093U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 2210290810330253363U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 10786160915224323113U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 799075068398619501U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 7791474921127653867U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 1046454625851499863U;
            aOrbiterJ = RotL64((aOrbiterJ * 18040454167287729591U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 14636813124839719351U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 3970829908171131502U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2737568880005765517U), 27U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterD, 50U);
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 39U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + (RotL64(aOrbiterE, 11U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterG, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aIngress, 60U) + aOrbiterK) + RotL64(aOrbiterH, 34U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterF, 47U)) + aOrbiterB);
            aWandererB = aWandererB + ((((RotL64(aScatter, 35U) + aOrbiterF) + RotL64(aOrbiterG, 57U)) + aNonceWordF) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterK, 13U)) + aOrbiterB);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterC, 37U)) + aOrbiterE) + RotL64(aCarry, 57U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterD, 41U)) + aOrbiterG);
            aWandererD = aWandererD + (((RotL64(aScatter, 43U) + aOrbiterK) + RotL64(aOrbiterJ, 53U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterJ, 21U)) + aOrbiterA);
            aWandererH = aWandererH + ((RotL64(aPrevious, 12U) + RotL64(aOrbiterD, 6U)) + aOrbiterF);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 53U) + aOrbiterI) + RotL64(aOrbiterG, 43U));
            aWandererA = aWandererA + (((RotL64(aIngress, 51U) + aOrbiterE) + RotL64(aOrbiterJ, 27U)) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 18U) ^ aWandererJ);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 21U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererA);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + RotL64(aWandererE, 44U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordM);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 8908U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 5683U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9080U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 9810U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aPrevious, 11U)) + (RotL64(aCarry, 53U) ^ RotL64(aIngress, 26U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterH = ((aWandererH + RotL64(aScatter, 27U)) + 7270044678408187242U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = (aWandererI + RotL64(aIngress, 23U)) + 10192278965379756766U;
            aOrbiterE = (aWandererA + RotL64(aCross, 36U)) + 17568666746676060748U;
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 57U)) + 14312927531124963037U) + aNonceWordI;
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 29U)) + RotL64(aCarry, 41U)) + 9825825726152087706U;
            aOrbiterD = ((aWandererC + RotL64(aScatter, 11U)) + 9696778570255265896U) + aPhaseDOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = (aWandererF + RotL64(aCross, 47U)) + 17657841352013417228U;
            aOrbiterG = (aWandererG + RotL64(aPrevious, 39U)) + 16207815085909628439U;
            aOrbiterJ = (aWandererE + RotL64(aIngress, 3U)) + 1752979206374514227U;
            aOrbiterB = ((aWandererD + RotL64(aScatter, 50U)) + RotL64(aCarry, 21U)) + 10456310689643905854U;
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 41U)) + RotL64(aCarry, 3U)) + 16127830548663742550U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 2940917376003930842U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 7353596864777649953U;
            aOrbiterE = RotL64((aOrbiterE * 7499468723171042005U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 12725092740446150705U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 5791296650856037010U;
            aOrbiterF = RotL64((aOrbiterF * 760379251950502133U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 1200130368046206150U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 16689604428598558547U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13815324235939996623U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 14359561591103730856U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 3975025843599045263U;
            aOrbiterK = RotL64((aOrbiterK * 5025047888533298617U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 14017901732955607601U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 10431526786489555196U;
            aOrbiterJ = RotL64((aOrbiterJ * 10181915874476132407U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 7320527073559849223U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 15333411223710709907U;
            aOrbiterH = RotL64((aOrbiterH * 3488684905528068775U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 14302474063321663801U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 2104154521019935187U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12944382959742278055U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 5167600586916325228U) + aNonceWordM;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 4566823109447208716U;
            aOrbiterD = RotL64((aOrbiterD * 9997799807454267443U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 12475580453805083495U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 15461491763911887974U;
            aOrbiterG = RotL64((aOrbiterG * 13548865386159287481U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 11000532703581114393U) + aNonceWordN;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 7815822789941347770U;
            aOrbiterB = RotL64((aOrbiterB * 1476638214324946775U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 2166336159928211562U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 7270044678408187242U;
            aOrbiterA = RotL64((aOrbiterA * 10648564933168714815U), 19U);
            //
            aIngress = RotL64(aOrbiterC, 57U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + (RotL64(aOrbiterK, 48U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterF, 19U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterE, 37U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterI, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aPrevious, 29U) + aOrbiterK) + RotL64(aOrbiterC, 21U)) + aPhaseDWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 56U) + RotL64(aOrbiterD, 58U)) + aOrbiterF);
            aWandererD = aWandererD + (((RotL64(aScatter, 5U) + RotL64(aOrbiterC, 29U)) + aOrbiterF) + RotL64(aCarry, 47U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterH, 47U)) + aOrbiterF);
            aWandererH = aWandererH + ((RotL64(aScatter, 37U) + aOrbiterE) + RotL64(aOrbiterF, 19U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 39U) + aOrbiterH) + RotL64(aOrbiterJ, 5U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 21U) + aOrbiterB) + RotL64(aOrbiterA, 11U)) + RotL64(aCarry, 23U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterJ, 60U)) + aOrbiterE);
            aWandererC = aWandererC + ((RotL64(aCross, 47U) + aOrbiterB) + RotL64(aOrbiterH, 43U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 13U) + aOrbiterH) + RotL64(aOrbiterI, 27U)) + aPhaseDWandererUpdateSaltB[((aIndex + 22U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 44U) + RotL64(aOrbiterD, 35U)) + aOrbiterG) + aNonceWordJ);
            //
            aCarry = aCarry + (RotL64(aWandererC, 36U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererD);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + (RotL64(aWandererG, 41U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererH, 54U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordN);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 15235U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 14766U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 14196U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 14525U)) & S_BLOCK1], 42U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 6U) ^ RotL64(aIngress, 57U)) + (RotL64(aCross, 23U) ^ RotL64(aPrevious, 37U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterA = (aWandererE + RotL64(aScatter, 5U)) + 12980104182836602177U;
            aOrbiterK = (aWandererF + RotL64(aIngress, 60U)) + 3172622203188863995U;
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 41U)) + 1170974132219980203U) + aNonceWordJ;
            aOrbiterE = (aWandererH + RotL64(aCross, 47U)) + 6035201940965047490U;
            aOrbiterB = (((aWandererB + RotL64(aIngress, 11U)) + RotL64(aCarry, 47U)) + 18033907118424996722U) + aNonceWordM;
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 43U)) + 14604813424800580304U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = ((aWandererK + RotL64(aCross, 3U)) + 13720232492851066035U) + aNonceWordK;
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 37U)) + RotL64(aCarry, 37U)) + 3902659710585257448U;
            aOrbiterF = ((aWandererD + RotL64(aCross, 21U)) + RotL64(aCarry, 21U)) + 8331560652661619868U;
            aOrbiterG = ((aWandererG + RotL64(aScatter, 50U)) + 4485014147538689794U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = (aWandererA + RotL64(aIngress, 23U)) + 168202636924512424U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 16227825670092707848U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 4792781933944671365U;
            aOrbiterC = RotL64((aOrbiterC * 15859849676231455283U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 12636865372722601282U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 18198291399585556632U;
            aOrbiterH = RotL64((aOrbiterH * 18155803890313399795U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 3650053185419807206U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 5897288963905408776U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3706949366974086151U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 9922308113622901726U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 13352279749091561510U;
            aOrbiterB = RotL64((aOrbiterB * 4025213180483632557U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 14969461950939646117U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 10231661776135056651U;
            aOrbiterI = RotL64((aOrbiterI * 11284575051455238501U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 10621934544068320859U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 6029116920305246887U;
            aOrbiterG = RotL64((aOrbiterG * 6087523725059376905U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 12887482425168671195U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 8351351557123783853U;
            aOrbiterA = RotL64((aOrbiterA * 3839381627914762245U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 5405938210926464973U) + aNonceWordF;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 385145802287899406U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8330751480464271445U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 7907749190875916461U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 5138733192253468642U;
            aOrbiterD = RotL64((aOrbiterD * 17028325976353263843U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 14382272868178763187U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 14354777100157531233U;
            aOrbiterF = RotL64((aOrbiterF * 7095764230272037767U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 4390647647193363824U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 12980104182836602177U;
            aOrbiterJ = RotL64((aOrbiterJ * 11124472075872147333U), 41U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterJ, 35U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 53U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 38U));
            aIngress = aIngress + (RotL64(aOrbiterK, 11U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterA, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aCross, 41U) + RotL64(aOrbiterH, 41U)) + aOrbiterF);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 6U) + RotL64(aOrbiterF, 37U)) + aOrbiterB);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterA, 46U)) + aOrbiterE);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 21U) + aOrbiterK) + RotL64(aOrbiterE, 43U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 3U) + aOrbiterD) + RotL64(aOrbiterK, 39U)) + RotL64(aCarry, 19U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 51U) + aOrbiterG) + RotL64(aOrbiterC, 3U)) + aNonceWordE);
            aWandererB = aWandererB + ((RotL64(aScatter, 47U) + aOrbiterJ) + RotL64(aOrbiterD, 58U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 13U) + aOrbiterI) + RotL64(aOrbiterD, 29U));
            aWandererK = aWandererK + ((((RotL64(aCross, 60U) + RotL64(aOrbiterA, 51U)) + aOrbiterH) + RotL64(aCarry, 41U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 23U) + aOrbiterB) + RotL64(aOrbiterA, 19U)) + aPhaseDWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterD, 21U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 39U));
            aCarry = aCarry + (RotL64(aWandererD, 44U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererI, 35U);
            aCarry = aCarry + RotL64(aIngress, 42U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordN);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 17230U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 18723U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 21539U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneD[((aIndex + 20207U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aIngress, 5U)) ^ (RotL64(aPrevious, 29U) + RotL64(aCross, 42U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterA = (aWandererI + RotL64(aPrevious, 43U)) + 12692813903177772178U;
            aOrbiterK = ((aWandererC + RotL64(aCross, 48U)) + 7112496446691277899U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = ((aWandererJ + RotL64(aIngress, 3U)) + RotL64(aCarry, 3U)) + 2112247138290568813U;
            aOrbiterE = (aWandererF + RotL64(aScatter, 53U)) + 3699421080882855947U;
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 13U)) + RotL64(aCarry, 13U)) + 13761832028354380922U;
            aOrbiterC = (aWandererK + RotL64(aCross, 11U)) + 9243822514887600214U;
            aOrbiterH = ((aWandererH + RotL64(aScatter, 5U)) + RotL64(aCarry, 21U)) + 6863833516853046129U;
            aOrbiterJ = (aWandererD + RotL64(aIngress, 57U)) + 8863897995943098018U;
            aOrbiterF = (aWandererE + RotL64(aScatter, 60U)) + 13346785686701467520U;
            aOrbiterB = (((aWandererG + RotL64(aPrevious, 51U)) + 15309543066305531619U) + aPhaseDOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1]) + aNonceWordH;
            aOrbiterG = (aWandererB + RotL64(aIngress, 39U)) + 17515530938817919111U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 760493237816424254U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 7282586354117620860U;
            aOrbiterD = RotL64((aOrbiterD * 2327153408185290635U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 4129706068526969105U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 7020175432730888755U;
            aOrbiterI = RotL64((aOrbiterI * 10095158356907592239U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 9102258982216515596U) + aNonceWordE;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 10822031305361453690U;
            aOrbiterC = RotL64((aOrbiterC * 2036205056490578491U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 12571477440964330246U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 8436347026653095199U;
            aOrbiterH = RotL64((aOrbiterH * 17930734781213681573U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 14214789872073941940U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 12915911919403385001U) ^ aNonceWordO;
            aOrbiterJ = RotL64((aOrbiterJ * 13161681603528031511U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 15443240166233851298U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 7311369180113240915U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13339195007946889423U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 12976516224995960015U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 7823308381434556721U;
            aOrbiterB = RotL64((aOrbiterB * 502385172763861451U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 4829417661664149137U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 16306394751966719700U;
            aOrbiterG = RotL64((aOrbiterG * 5294376579588592157U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 16769868341852572677U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 7107433163189177642U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5279050651595743649U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 11896784111967113871U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 389626690429371003U;
            aOrbiterK = RotL64((aOrbiterK * 10665914532159182181U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 8226849597052979358U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 12692813903177772178U;
            aOrbiterE = RotL64((aOrbiterE * 17909062471564422847U), 3U);
            //
            aIngress = RotL64(aOrbiterA, 53U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterG, 37U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterJ, 5U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 39U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + RotL64(aOrbiterK, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aScatter, 5U) + aOrbiterG) + RotL64(aOrbiterA, 56U)) + aPhaseDWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 18U) + RotL64(aOrbiterF, 51U)) + aOrbiterA);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 43U) + aOrbiterD) + RotL64(aOrbiterA, 27U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterK, 35U)) + aOrbiterF) + aNonceWordI);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterB, 5U)) + aOrbiterC) + aNonceWordL);
            aWandererE = aWandererE + ((((RotL64(aIngress, 35U) + aOrbiterH) + RotL64(aOrbiterB, 37U)) + RotL64(aCarry, 23U)) + aNonceWordB);
            aWandererI = aWandererI ^ ((RotL64(aCross, 3U) + aOrbiterA) + RotL64(aOrbiterI, 43U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 27U) + aOrbiterK) + RotL64(aOrbiterH, 41U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 60U) + aOrbiterD) + RotL64(aOrbiterJ, 23U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterC, 58U)) + aOrbiterG) + RotL64(aCarry, 35U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 37U) + aOrbiterE) + RotL64(aOrbiterC, 29U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererB, 5U) ^ aWandererH);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + (RotL64(aWandererG, 24U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererC, 57U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ aNonceWordF;
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 25951U)) & S_BLOCK1], 14U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24663U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 26015U)) & S_BLOCK1], 52U) ^ RotL64(aOperationLaneA[((aIndex + 25431U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 50U) + RotL64(aCross, 19U)) + (RotL64(aIngress, 37U) ^ RotL64(aCarry, 5U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterF = (aWandererB + RotL64(aCross, 38U)) + 1087148170018530502U;
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 5U)) + RotL64(aCarry, 3U)) + 15530846874509311414U;
            aOrbiterK = (aWandererD + RotL64(aScatter, 3U)) + 16987358651515511212U;
            aOrbiterA = ((aWandererK + RotL64(aIngress, 29U)) + 12504143181007924259U) + aNonceWordH;
            aOrbiterC = (aWandererG + RotL64(aScatter, 23U)) + 393322117322732418U;
            aOrbiterG = ((aWandererC + RotL64(aCross, 41U)) + RotL64(aCarry, 29U)) + 14325937299241887166U;
            aOrbiterH = ((aWandererF + RotL64(aIngress, 43U)) + 9395262907017475742U) + aPhaseDOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = (aWandererE + RotL64(aPrevious, 47U)) + 13658510441418344769U;
            aOrbiterI = ((aWandererA + RotL64(aCross, 13U)) + 6410754322737005336U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = (((aWandererJ + RotL64(aIngress, 51U)) + RotL64(aCarry, 21U)) + 9257290738538818434U) + aNonceWordC;
            aOrbiterD = (aWandererH + RotL64(aScatter, 10U)) + 7489828960857692286U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 4118778591214588387U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 16619215231168796563U;
            aOrbiterK = RotL64((aOrbiterK * 14876884956536265157U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 11326283811003573430U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 1865401866017614604U;
            aOrbiterG = RotL64((aOrbiterG * 8378326058282460073U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 670150121105733604U) + aNonceWordP;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 1499331510641068749U;
            aOrbiterB = RotL64((aOrbiterB * 16623742535540383107U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 1116410848560838532U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 2696841341036281779U;
            aOrbiterE = RotL64((aOrbiterE * 9598953298074904869U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 5487352391229549881U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 12008243050943342979U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9087261224804582459U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 552859665927882960U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 8426942688524814473U;
            aOrbiterA = RotL64((aOrbiterA * 10916963622695549105U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 1613287981244830815U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 15592897923468694288U;
            aOrbiterH = RotL64((aOrbiterH * 6600750586743893303U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 7629853970631002676U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 13778028957247561272U) ^ aNonceWordK;
            aOrbiterI = RotL64((aOrbiterI * 4063798788229605659U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 2932956928094332652U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 14855524972646900872U;
            aOrbiterD = RotL64((aOrbiterD * 9546042275547649745U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 11071597794692793784U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 6327727700942234552U;
            aOrbiterJ = RotL64((aOrbiterJ * 15301120263944789797U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 5147576281502110428U) + aNonceWordJ;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 1087148170018530502U;
            aOrbiterC = RotL64((aOrbiterC * 18045084130531645749U), 47U);
            //
            aIngress = RotL64(aOrbiterG, 4U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterI, 53U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterF, 51U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 14U));
            aIngress = aIngress + RotL64(aOrbiterD, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterH, 52U)) + aOrbiterE) + aNonceWordM);
            aWandererI = aWandererI + (((RotL64(aIngress, 53U) + aOrbiterB) + RotL64(aOrbiterD, 19U)) + RotL64(aCarry, 37U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterF, 57U)) + aOrbiterE);
            aWandererG = aWandererG + ((RotL64(aCross, 35U) + RotL64(aOrbiterK, 35U)) + aOrbiterE);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 14U) + aOrbiterE) + RotL64(aOrbiterB, 26U));
            aWandererK = aWandererK + (((RotL64(aScatter, 57U) + RotL64(aOrbiterK, 41U)) + aOrbiterA) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 37U) + RotL64(aOrbiterD, 13U)) + aOrbiterI) + aPhaseDWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aCross, 51U) + RotL64(aOrbiterI, 37U)) + aOrbiterF) + RotL64(aCarry, 51U)) + aNonceWordL);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 21U) + aOrbiterJ) + RotL64(aOrbiterE, 39U));
            aWandererB = aWandererB + ((RotL64(aIngress, 11U) + RotL64(aOrbiterF, 47U)) + aOrbiterC);
            aWandererC = aWandererC ^ (((RotL64(aCross, 46U) + RotL64(aOrbiterF, 23U)) + aOrbiterG) + aNonceWordD);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 41U));
            aCarry = aCarry + (RotL64(aWandererH, 44U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererB, 13U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererF, 27U) ^ aWandererI);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + RotL64(aWandererK, 47U);
            aCarry = aCarry + RotL64(aIngress, 22U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordB);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 29835U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27462U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 28757U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((aIndex + 30580U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 27U) + RotL64(aPrevious, 39U)) ^ (RotL64(aIngress, 54U) ^ RotL64(aCarry, 5U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterE = (aWandererK + RotL64(aIngress, 4U)) + 9751314027302668907U;
            aOrbiterJ = ((aWandererE + RotL64(aCross, 35U)) + 12175450995523107056U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = (((aWandererH + RotL64(aPrevious, 29U)) + RotL64(aCarry, 13U)) + 17519694958730119552U) + aNonceWordK;
            aOrbiterK = (aWandererJ + RotL64(aScatter, 23U)) + 9093525527925682263U;
            aOrbiterG = ((aWandererA + RotL64(aIngress, 21U)) + RotL64(aCarry, 27U)) + 3713831321786810138U;
            aOrbiterF = (aWandererF + RotL64(aPrevious, 37U)) + 10108355209191835040U;
            aOrbiterB = (aWandererC + RotL64(aScatter, 43U)) + 12956307447311314768U;
            aOrbiterI = ((aWandererD + RotL64(aCross, 41U)) + 1904298513945877359U) + aNonceWordC;
            aOrbiterA = (aWandererI + RotL64(aScatter, 19U)) + 4658049993308574460U;
            aOrbiterH = (((aWandererB + RotL64(aCross, 57U)) + RotL64(aCarry, 47U)) + 9826333658248851902U) + aPhaseDOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = (aWandererG + RotL64(aIngress, 6U)) + 12058666914724365134U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 2516574707110528099U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 13335308331049750235U;
            aOrbiterC = RotL64((aOrbiterC * 5880227828760598587U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 8230749255538495304U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 16536559486797811486U;
            aOrbiterG = RotL64((aOrbiterG * 7097036838156464969U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 12387639130570188998U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 8459259798142872020U;
            aOrbiterF = RotL64((aOrbiterF * 8001346480955847013U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 16083784052002800300U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 1957284290736468379U;
            aOrbiterB = RotL64((aOrbiterB * 5046501301740813065U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 7349538179311335863U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 16395170077006105258U;
            aOrbiterI = RotL64((aOrbiterI * 4230485452156662763U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 3317652065873784068U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 5517155804799120700U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9789270651974719183U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 5568525912112200094U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 9334250662962319598U;
            aOrbiterH = RotL64((aOrbiterH * 5034887614541768961U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 5641394627075994165U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 13524971148931512745U;
            aOrbiterD = RotL64((aOrbiterD * 3699457147759854357U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 15124425790244392471U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 7896294947517723306U;
            aOrbiterE = RotL64((aOrbiterE * 7526632360108129915U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 15241686066829586263U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 12099799118961857495U) ^ aNonceWordP;
            aOrbiterJ = RotL64((aOrbiterJ * 10456171163074630861U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 17529688916595727188U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 9751314027302668907U;
            aOrbiterK = RotL64((aOrbiterK * 521888849578281715U), 23U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterD, 29U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 43U));
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterB, 21U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 26U));
            aIngress = aIngress + RotL64(aOrbiterG, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterH, 44U)) + aOrbiterB) + aPhaseDWandererUpdateSaltC[((aIndex + 6U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 23U) + aOrbiterG) + RotL64(aOrbiterJ, 57U)) + RotL64(aCarry, 29U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 6U) + aOrbiterB) + RotL64(aOrbiterC, 41U));
            aWandererA = aWandererA + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterJ, 39U)) + aOrbiterF) + RotL64(aCarry, 19U)) + aNonceWordB);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterE, 21U)) + aOrbiterC) + aPhaseDWandererUpdateSaltA[((aIndex + 11U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 39U) + aOrbiterB) + RotL64(aOrbiterA, 29U)) + aNonceWordJ);
            aWandererE = aWandererE ^ ((RotL64(aCross, 13U) + aOrbiterJ) + RotL64(aOrbiterK, 53U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterG, 47U)) + aOrbiterD);
            aWandererC = aWandererC ^ ((RotL64(aCross, 29U) + aOrbiterK) + RotL64(aOrbiterF, 18U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 11U) + RotL64(aOrbiterB, 11U)) + aOrbiterF);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 54U) + RotL64(aOrbiterI, 23U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 44U));
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererC);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 24U));
            aCarry = aCarry + RotL64(aWandererI, 11U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordM);
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

void TwistExpander_Bowling_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x9C295F29781877E3ULL + 0x84F457DF0C5CD9ACULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xC11F39A84F7E150FULL + 0x8F891B086F121F35ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xCA32E3D437EF8BEBULL + 0x8B7F622F672EB70EULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xDE9CFD79A19ED4D7ULL + 0xEBC543022F1116A3ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xF464D75BE4E1507FULL + 0xCD1859873D63A627ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xE5FA21259C4BC959ULL + 0x91A8E14664FD1E01ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xD351CAAD6891909FULL + 0x8AC4838B851D3F55ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x931328FE6706A6B5ULL + 0xD68EA7719BFA6DB9ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xF82F0BD2DACAA251ULL + 0xDDF612A5F797BF17ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xC87CAC07A36A78F5ULL + 0xAEAAB0F3D65C4EC2ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xAD7EFDB12F182113ULL + 0xD2823E1F79B149EFULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xBEDED5CF4331BDB1ULL + 0xC6E472701566948BULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xCC5C8BE0C0A4AD83ULL + 0xD44AD0E668CB466EULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xC099FA5128D564ABULL + 0xC3EBC25D349E2DC3ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xCB8306B501C07419ULL + 0x90EDA3911C2750CBULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x9D33EB85AD2FAA81ULL + 0xC2E9F8601226BB2FULL);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 5038U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 4936U)) & S_BLOCK1], 26U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 5107U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 4259U)) & S_BLOCK1], 34U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 19U) ^ RotL64(aPrevious, 3U)) ^ (RotL64(aCross, 47U) + RotL64(aIngress, 34U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterE = (aWandererK + RotL64(aCross, 57U)) + 12615321415808640429U;
            aOrbiterI = (aWandererD + RotL64(aIngress, 51U)) + 15712784676459931207U;
            aOrbiterJ = (aWandererE + RotL64(aPrevious, 40U)) + 11013335427004930046U;
            aOrbiterG = ((aWandererA + RotL64(aScatter, 29U)) + 8298733856304768806U) + aNonceWordB;
            aOrbiterF = (((aWandererG + RotL64(aPrevious, 21U)) + RotL64(aCarry, 37U)) + 6207732959150824216U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = ((aWandererJ + RotL64(aCross, 13U)) + 9769864876127544038U) + aNonceWordH;
            aOrbiterC = ((aWandererF + RotL64(aScatter, 53U)) + RotL64(aCarry, 43U)) + 10782181918651152563U;
            aOrbiterB = ((aWandererH + RotL64(aIngress, 11U)) + RotL64(aCarry, 57U)) + 5790454015845620939U;
            aOrbiterH = (aWandererC + RotL64(aScatter, 18U)) + 15606578025386733803U;
            aOrbiterK = (aWandererI + RotL64(aIngress, 47U)) + 5522352539991175304U;
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 35U)) + 5993355818572869649U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 10864534396947622047U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 12090053126235913528U;
            aOrbiterJ = RotL64((aOrbiterJ * 7250801471645972261U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 14191181677234981396U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 2258570108233924592U;
            aOrbiterD = RotL64((aOrbiterD * 8307541155393855209U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 8448114811381534603U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 2702389315763499817U;
            aOrbiterE = RotL64((aOrbiterE * 6710443836432274393U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 17202184076718780200U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 150549910056015002U;
            aOrbiterG = RotL64((aOrbiterG * 195034681254956335U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 4910512055808124967U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 4783477997418403079U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 861977492146512865U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 13842899106208709771U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 7930112618036681468U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8609551859830858419U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 8790107242863198659U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 6882768826643279144U) ^ aNonceWordO;
            aOrbiterA = RotL64((aOrbiterA * 13745521454063360763U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 12136498871759890015U) + aNonceWordL;
            aOrbiterI = (((aOrbiterI ^ aOrbiterB) ^ 8120456314755584336U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterI = RotL64((aOrbiterI * 1830725195528043575U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 14425711740351183016U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 15907406009196323049U;
            aOrbiterF = RotL64((aOrbiterF * 8599371693260686839U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 4878521420367891861U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 1184672056055028939U;
            aOrbiterB = RotL64((aOrbiterB * 5963961755367831967U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 10126736568567000180U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 12615321415808640429U;
            aOrbiterK = RotL64((aOrbiterK * 11663715449073755137U), 51U);
            //
            aIngress = RotL64(aOrbiterC, 3U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterB, 5U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterK, 54U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 51U));
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterE, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aPrevious, 48U) + aOrbiterH) + RotL64(aOrbiterE, 39U)) + RotL64(aCarry, 35U)) + aPhaseEWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterE, 23U)) + aOrbiterK);
            aWandererF = aWandererF + ((RotL64(aScatter, 19U) + RotL64(aOrbiterC, 28U)) + aOrbiterH);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterF, 43U)) + aOrbiterD);
            aWandererG = aWandererG + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterI, 41U)) + aOrbiterE);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 57U) + aOrbiterF) + RotL64(aOrbiterA, 3U));
            aWandererI = aWandererI + ((RotL64(aIngress, 46U) + RotL64(aOrbiterA, 37U)) + aOrbiterJ);
            aWandererH = aWandererH ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterK, 14U)) + aOrbiterG) + aPhaseEWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 43U) + RotL64(aOrbiterB, 21U)) + aOrbiterF) + RotL64(aCarry, 21U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 27U) + aOrbiterI) + RotL64(aOrbiterB, 51U)) + aNonceWordA);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterF, 19U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererG, 10U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererJ);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererC, 56U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ aNonceWordG;
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 9975U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneD[((aIndex + 9410U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 7111U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 6050U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 27U) + RotL64(aCarry, 41U)) ^ (RotL64(aCross, 5U) ^ RotL64(aIngress, 56U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterE = (aWandererC + RotL64(aPrevious, 22U)) + 11410829607777684449U;
            aOrbiterD = (aWandererA + RotL64(aCross, 51U)) + 7502698839700975347U;
            aOrbiterC = ((aWandererD + RotL64(aScatter, 39U)) + 13267685058252106173U) + aNonceWordP;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 43U)) + 238242706996630625U) + aPhaseEOrbiterAssignSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 35U)) + RotL64(aCarry, 37U)) + 8184695499511454281U;
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 48U)) + 12767823220461985403U) + aNonceWordM;
            aOrbiterH = ((aWandererF + RotL64(aIngress, 3U)) + RotL64(aCarry, 57U)) + 12293198423143850330U;
            aOrbiterA = ((aWandererG + RotL64(aCross, 5U)) + 11149495229952495939U) + aPhaseEOrbiterAssignSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = (aWandererH + RotL64(aIngress, 19U)) + 7556992689338382800U;
            aOrbiterI = ((aWandererB + RotL64(aCross, 53U)) + RotL64(aCarry, 41U)) + 3431338808774134649U;
            aOrbiterB = (aWandererI + RotL64(aPrevious, 29U)) + 16863099140844995099U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 17872458049880677604U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 16760153457252546974U;
            aOrbiterC = RotL64((aOrbiterC * 11225037229069712805U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 3115544493537438408U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 4359882942759752958U;
            aOrbiterD = RotL64((aOrbiterD * 561477566995575801U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 13387113067202396536U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 12955690074544490161U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12449941770827974511U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 15614054443728226807U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 1939441328066616114U;
            aOrbiterH = RotL64((aOrbiterH * 4484917074808974359U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 4599016263007782537U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 9962305629016158048U;
            aOrbiterJ = RotL64((aOrbiterJ * 1496184427500037279U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 8428467674122750557U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterB) ^ 3938884087806393439U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterE = RotL64((aOrbiterE * 12810531094050481761U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 6018636830758044658U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 1510372000641305416U;
            aOrbiterK = RotL64((aOrbiterK * 9002834928626918247U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 17592782466215337843U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 8119921507606870360U;
            aOrbiterF = RotL64((aOrbiterF * 1299795061644535485U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 8753237702359236964U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 12389957327067768090U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4586786761936601607U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 17791633199762408683U) + aNonceWordB;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 11606494383812053915U;
            aOrbiterI = RotL64((aOrbiterI * 13041480602055778521U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 4418614662439151979U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 11410829607777684449U;
            aOrbiterB = RotL64((aOrbiterB * 3342270212301058781U), 23U);
            //
            aIngress = RotL64(aOrbiterB, 29U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterC, 5U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterK, 23U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 20U));
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterJ, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 24U) + RotL64(aOrbiterD, 21U)) + aOrbiterJ);
            aWandererG = aWandererG + (((RotL64(aScatter, 47U) + aOrbiterE) + RotL64(aOrbiterB, 53U)) + RotL64(aCarry, 19U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterG, 10U)) + aOrbiterH);
            aWandererB = aWandererB + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterA, 13U)) + aOrbiterF) + aNonceWordI);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterH, 39U)) + aOrbiterA);
            aWandererA = aWandererA + ((RotL64(aPrevious, 5U) + aOrbiterF) + RotL64(aOrbiterB, 29U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 60U) + RotL64(aOrbiterK, 51U)) + aOrbiterE);
            aWandererE = aWandererE + ((((RotL64(aCross, 37U) + RotL64(aOrbiterA, 58U)) + aOrbiterD) + RotL64(aCarry, 47U)) + aNonceWordC);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 51U) + aOrbiterH) + RotL64(aOrbiterK, 35U)) + aPhaseEWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aScatter, 53U) + RotL64(aOrbiterJ, 37U)) + aOrbiterC) + aNonceWordD) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterI, 5U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererH, 12U) ^ aWandererA);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 53U));
            aCarry = aCarry + (RotL64(aWandererI, 39U) ^ aWandererE);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 58U));
            aCarry = aCarry + RotL64(aWandererB, 51U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ aNonceWordL;
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 14564U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneA[((aIndex + 12397U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 15296U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 11300U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aIngress, 56U)) + (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 23U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterE = ((aWandererC + RotL64(aCross, 11U)) + 6069475454765660321U) + aNonceWordP;
            aOrbiterH = (aWandererK + RotL64(aIngress, 38U)) + 11483704742497268068U;
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 57U)) + RotL64(aCarry, 19U)) + 11055697447388986418U;
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 21U)) + RotL64(aCarry, 53U)) + 10897095046039997004U;
            aOrbiterB = ((aWandererF + RotL64(aCross, 29U)) + 4731637118230457840U) + aNonceWordB;
            aOrbiterG = (aWandererB + RotL64(aIngress, 6U)) + 13855839187084986751U;
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 41U)) + 5328208115460188239U) + aPhaseEOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterC = (aWandererE + RotL64(aPrevious, 3U)) + 12479538544291412985U;
            aOrbiterD = (((aWandererI + RotL64(aCross, 47U)) + RotL64(aCarry, 27U)) + 10740165998792608231U) + aPhaseEOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = (aWandererH + RotL64(aScatter, 53U)) + 6492798157284955373U;
            aOrbiterK = (aWandererA + RotL64(aIngress, 43U)) + 13056825957483891921U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 2068184064919194657U) + aNonceWordG;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 5656302738780746294U) ^ aNonceWordO;
            aOrbiterF = RotL64((aOrbiterF * 16493021179127646345U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 11193756120230763294U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 17306750816837208999U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7949360041241439741U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 12952818800389361804U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 15380412293642628312U;
            aOrbiterH = RotL64((aOrbiterH * 2914662289178925547U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 7706090204767242996U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 14598802276412649570U;
            aOrbiterB = RotL64((aOrbiterB * 4821408736292041399U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 17819762117328075515U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 6481384240915075101U;
            aOrbiterC = RotL64((aOrbiterC * 4836701121865783029U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 754936290510338717U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 15510875946573720154U;
            aOrbiterI = RotL64((aOrbiterI * 2994718968852184303U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 9245381722813944586U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 2629847912019726214U;
            aOrbiterE = RotL64((aOrbiterE * 6718795794951106961U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 3909987749797113773U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 9277056074757335265U;
            aOrbiterA = RotL64((aOrbiterA * 11580847505996697115U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 12577180954515966707U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 9144513680789115458U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8880777678193004979U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 1544232962956974411U) + aNonceWordE;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 2658275904714859636U;
            aOrbiterD = RotL64((aOrbiterD * 1926083316365175327U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 5733515391293514025U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 6069475454765660321U;
            aOrbiterK = RotL64((aOrbiterK * 9627476106108146391U), 51U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterH, 3U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 23U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 44U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 53U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + RotL64(aOrbiterI, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aPrevious, 35U) + aOrbiterH) + RotL64(aOrbiterG, 40U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 44U) + RotL64(aOrbiterF, 51U)) + aOrbiterJ);
            aWandererB = aWandererB + (((RotL64(aScatter, 41U) + aOrbiterE) + RotL64(aOrbiterD, 27U)) + aNonceWordD);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterD, 23U)) + aOrbiterC);
            aWandererD = aWandererD + (((RotL64(aScatter, 5U) + aOrbiterI) + RotL64(aOrbiterC, 3U)) + RotL64(aCarry, 39U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterB, 14U)) + aOrbiterD) + aPhaseEWandererUpdateSaltE[((aIndex + 14U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 52U) + aOrbiterA) + RotL64(aOrbiterK, 11U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 11U) + aOrbiterC) + RotL64(aOrbiterA, 37U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 21U) + aOrbiterH) + RotL64(aOrbiterB, 5U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 3U) + aOrbiterF) + RotL64(aOrbiterE, 43U));
            aWandererK = aWandererK + (((RotL64(aCross, 37U) + RotL64(aOrbiterF, 47U)) + aOrbiterI) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 11U));
            aCarry = aCarry + (RotL64(aWandererG, 18U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererJ, 37U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 51U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + RotL64(aWandererI, 58U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ aNonceWordC;
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 18784U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 17304U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 18174U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 18086U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 51U) + RotL64(aCross, 4U)) + (RotL64(aCarry, 27U) ^ RotL64(aPrevious, 39U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterK = (aWandererE + RotL64(aCross, 41U)) + 12775735908960052604U;
            aOrbiterI = (aWandererB + RotL64(aIngress, 43U)) + 11791373812080296887U;
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 5U)) + 5537362877706057303U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = (((aWandererF + RotL64(aScatter, 21U)) + RotL64(aCarry, 27U)) + 2023912048504189380U) + aNonceWordM;
            aOrbiterE = (aWandererI + RotL64(aIngress, 12U)) + 17668828109963766893U;
            aOrbiterJ = (aWandererC + RotL64(aScatter, 47U)) + 558908629933941224U;
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 29U)) + 1479633119685446888U) + aNonceWordC;
            aOrbiterC = (((aWandererD + RotL64(aCross, 53U)) + 15460320397843364063U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordP;
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 39U)) + RotL64(aCarry, 21U)) + 10059749397555469054U;
            aOrbiterG = (aWandererA + RotL64(aCross, 60U)) + 9987633811929693924U;
            aOrbiterF = ((aWandererK + RotL64(aIngress, 37U)) + RotL64(aCarry, 57U)) + 10087337844580228269U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 4446204415503364254U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 15106063243302192717U;
            aOrbiterA = RotL64((aOrbiterA * 13273756657334709803U), 39U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterH) + 9430197906134676162U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1]) + aNonceWordO;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 1226048679997253363U;
            aOrbiterE = RotL64((aOrbiterE * 14247538885252664127U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 10611580584157624739U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 3137391249289641509U;
            aOrbiterJ = RotL64((aOrbiterJ * 5462682413239873181U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 9327201928815412810U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 7890659377013147073U;
            aOrbiterB = RotL64((aOrbiterB * 13827717178378062047U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 10675114832750356941U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 8804440385852327267U;
            aOrbiterC = RotL64((aOrbiterC * 8520671775587260601U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 12871947817782057116U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 11015991745792051390U;
            aOrbiterD = RotL64((aOrbiterD * 17152451500505815031U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 6320437975845673731U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 702457937087191287U;
            aOrbiterG = RotL64((aOrbiterG * 17491257114676739589U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 16629064896250312921U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 6054107387816339103U;
            aOrbiterF = RotL64((aOrbiterF * 6983767878966747219U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 13274874838094190290U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 12211422735294360321U;
            aOrbiterK = RotL64((aOrbiterK * 5113738196151089817U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 15338616110718583619U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 1475787183754511373U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10904607643785840003U), 35U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterK) + 15486810401396777742U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1]) + aNonceWordD;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 12775735908960052604U;
            aOrbiterH = RotL64((aOrbiterH * 7478156942468930207U), 37U);
            //
            aIngress = RotL64(aOrbiterD, 21U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + (RotL64(aOrbiterH, 54U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + (RotL64(aOrbiterE, 23U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterA, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aIngress, 23U) + aOrbiterC) + RotL64(aOrbiterE, 43U)) + aPhaseEWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aCross, 58U) + aOrbiterF) + RotL64(aOrbiterE, 39U)) + aPhaseEWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 5U) + RotL64(aOrbiterG, 57U)) + aOrbiterH) + aNonceWordG);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterK, 41U)) + aOrbiterC);
            aWandererK = aWandererK + ((RotL64(aCross, 19U) + RotL64(aOrbiterE, 23U)) + aOrbiterA);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 44U) + RotL64(aOrbiterB, 52U)) + aOrbiterC);
            aWandererC = aWandererC + ((((RotL64(aScatter, 27U) + aOrbiterA) + RotL64(aOrbiterF, 35U)) + RotL64(aCarry, 57U)) + aNonceWordI);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 13U) + aOrbiterD) + RotL64(aOrbiterI, 29U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 39U) + aOrbiterC) + RotL64(aOrbiterD, 3U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 51U) + aOrbiterA) + RotL64(aOrbiterH, 6U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterJ, 13U)) + aOrbiterK) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 50U) ^ aWandererE);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererH, 27U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererI, 46U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ aNonceWordN;
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 23936U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25748U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 22485U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25586U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 27U) + RotL64(aPrevious, 42U)) ^ (RotL64(aCross, 57U) ^ RotL64(aIngress, 5U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterB = (((aWandererK + RotL64(aPrevious, 27U)) + RotL64(aCarry, 41U)) + 11521331427196538632U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = (aWandererB + RotL64(aScatter, 35U)) + 16653824187682957632U;
            aOrbiterF = (aWandererF + RotL64(aCross, 52U)) + 11654676587350088289U;
            aOrbiterK = ((aWandererH + RotL64(aIngress, 43U)) + 8010313317412193584U) + aPhaseEOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = ((aWandererE + RotL64(aCross, 39U)) + 1108775560502907471U) + aNonceWordD;
            aOrbiterI = ((aWandererG + RotL64(aIngress, 21U)) + 243952321439823521U) + aNonceWordG;
            aOrbiterH = ((aWandererI + RotL64(aScatter, 24U)) + RotL64(aCarry, 35U)) + 2324945800401240403U;
            aOrbiterJ = (aWandererA + RotL64(aPrevious, 41U)) + 9257554497543369657U;
            aOrbiterA = (aWandererD + RotL64(aIngress, 47U)) + 16701314607244592540U;
            aOrbiterG = (aWandererC + RotL64(aScatter, 29U)) + 3900445848034341782U;
            aOrbiterE = ((aWandererJ + RotL64(aCross, 11U)) + RotL64(aCarry, 57U)) + 7652316487347103658U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 14980368605272070578U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 2001165460948764796U;
            aOrbiterF = RotL64((aOrbiterF * 8110980921827107649U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 1911044015666991050U) + aNonceWordI;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 11366207111147818339U;
            aOrbiterI = RotL64((aOrbiterI * 17234439040652553865U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 16469329744002456607U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 8062793687044950815U;
            aOrbiterJ = RotL64((aOrbiterJ * 5856142259851144369U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 15364721421972807872U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 8979915611483540231U;
            aOrbiterG = RotL64((aOrbiterG * 10899377466171153383U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 7654234623563110457U) + aNonceWordE;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 1526832460342135008U;
            aOrbiterB = RotL64((aOrbiterB * 12766083052650723051U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 1596625448797520938U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 15723912914858523080U;
            aOrbiterK = RotL64((aOrbiterK * 6003857787643420337U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 7664226719746532168U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 13767298788411473401U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15663266144965532019U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 8371251860069346385U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 10143279934304029980U;
            aOrbiterA = RotL64((aOrbiterA * 12764966547132248131U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 10034920090729616747U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 14450253491131954914U;
            aOrbiterE = RotL64((aOrbiterE * 15877567779079226909U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 9450697155749555210U) + aNonceWordN;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 14051719612902917300U;
            aOrbiterC = RotL64((aOrbiterC * 7659810299163085295U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 659383614060726993U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 11521331427196538632U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1068009283450923005U), 47U);
            //
            aIngress = RotL64(aOrbiterI, 50U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterD, 53U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 3U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 5U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + RotL64(aOrbiterC, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 13U) + aOrbiterC) + RotL64(aOrbiterG, 41U));
            aWandererK = aWandererK + ((RotL64(aCross, 37U) + RotL64(aOrbiterI, 13U)) + aOrbiterJ);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 23U) + aOrbiterB) + RotL64(aOrbiterD, 48U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterI, 51U)) + aOrbiterA);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 3U) + aOrbiterI) + RotL64(aOrbiterH, 27U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aCross, 58U) + aOrbiterC) + RotL64(aOrbiterA, 3U)) + aNonceWordC) + aPhaseEWandererUpdateSaltB[((aIndex + 18U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 35U) + aOrbiterF) + RotL64(aOrbiterD, 44U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 39U) + aOrbiterJ) + RotL64(aOrbiterE, 53U)) + RotL64(aCarry, 11U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 19U) + aOrbiterI) + RotL64(aOrbiterK, 57U));
            aWandererC = aWandererC + (((RotL64(aScatter, 26U) + aOrbiterD) + RotL64(aOrbiterJ, 29U)) + RotL64(aCarry, 35U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 41U) + aOrbiterK) + RotL64(aOrbiterH, 11U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 11U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 51U));
            aCarry = aCarry + (RotL64(aWandererJ, 44U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 53U));
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererC, 5U);
            aCarry = aCarry + RotL64(aIngress, 36U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordA);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 28232U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27599U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 31029U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28693U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 5U)) ^ (RotL64(aCross, 42U) + RotL64(aIngress, 21U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterC = (aWandererJ + RotL64(aCross, 40U)) + 4179952823252098240U;
            aOrbiterH = (aWandererF + RotL64(aPrevious, 23U)) + 3745613452332101749U;
            aOrbiterA = ((aWandererI + RotL64(aScatter, 51U)) + 2955689793395307176U) + aNonceWordK;
            aOrbiterD = ((aWandererD + RotL64(aIngress, 3U)) + RotL64(aCarry, 3U)) + 5639060180251322019U;
            aOrbiterI = ((aWandererK + RotL64(aCross, 21U)) + RotL64(aCarry, 37U)) + 7901969163853586463U;
            aOrbiterE = (aWandererG + RotL64(aIngress, 35U)) + 2242166787816318119U;
            aOrbiterB = (aWandererC + RotL64(aScatter, 57U)) + 5239936443960750064U;
            aOrbiterG = (((aWandererB + RotL64(aPrevious, 5U)) + 13939136954732185558U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordA;
            aOrbiterK = (aWandererA + RotL64(aCross, 54U)) + 17058884136712717463U;
            aOrbiterF = ((aWandererE + RotL64(aScatter, 29U)) + 18148618660054585941U) + aPhaseEOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = ((aWandererH + RotL64(aPrevious, 11U)) + RotL64(aCarry, 13U)) + 7022023484530327814U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 7722084537340095637U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 11764151879690934182U;
            aOrbiterA = RotL64((aOrbiterA * 12264384877711365655U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 16412785901758144708U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 9666718667728274824U;
            aOrbiterI = RotL64((aOrbiterI * 10865799822751771795U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 4307127540152109364U) + aNonceWordL;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 2457646804702647606U;
            aOrbiterE = RotL64((aOrbiterE * 6340030928007058595U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 3179394870088602208U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 504977947273774249U;
            aOrbiterB = RotL64((aOrbiterB * 16190282058883481551U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 16182729401018310837U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 7110817020445860609U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13371352088428584087U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 12960656706837391973U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 7103806893724395904U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14365984439655979791U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 1248300178080633527U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 7195473175424961337U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4633558992739305045U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 13007951568242991449U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 10296811247653636372U;
            aOrbiterJ = RotL64((aOrbiterJ * 16469682651380549395U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 13922797949001028335U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 16773545425463040155U;
            aOrbiterC = RotL64((aOrbiterC * 10639282630227832397U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 2888887140296117803U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 10279517418046269817U;
            aOrbiterH = RotL64((aOrbiterH * 8600355360339461535U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 17303373436784809093U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 4179952823252098240U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3675754609699406437U), 39U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterC, 11U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 60U));
            aIngress = aIngress + (RotL64(aOrbiterK, 19U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + RotL64(aOrbiterH, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aScatter, 50U) + aOrbiterI) + RotL64(aOrbiterH, 51U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 27U) + aOrbiterK) + RotL64(aOrbiterD, 3U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 11U) + aOrbiterC) + RotL64(aOrbiterB, 44U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 5U) + aOrbiterC) + RotL64(aOrbiterI, 13U)) + aNonceWordF);
            aWandererI = aWandererI + ((RotL64(aIngress, 46U) + RotL64(aOrbiterK, 27U)) + aOrbiterG);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterJ, 41U)) + aOrbiterI);
            aWandererG = aWandererG + (((RotL64(aCross, 21U) + aOrbiterA) + RotL64(aOrbiterC, 23U)) + RotL64(aCarry, 5U));
            aWandererF = aWandererF ^ ((((RotL64(aPrevious, 41U) + aOrbiterI) + RotL64(aOrbiterG, 47U)) + aNonceWordE) + aPhaseEWandererUpdateSaltE[((aIndex + 10U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aIngress, 43U) + aOrbiterE) + RotL64(aOrbiterB, 5U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterF, 35U)) + aOrbiterB) + aPhaseEWandererUpdateSaltD[((aIndex + 24U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterC, 18U)) + RotL64(aCarry, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 36U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 11U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererA, 39U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordN);
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

void TwistExpander_Bowling_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xA0301A8DB81317E5ULL + 0x845A37401D73D1E5ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xA69CE69B51625B0BULL + 0xBDB4ACA6266BDF92ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xDE67406502ED34ABULL + 0xF03BA02D7AD66DA8ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xD31BB8FF8835A8DDULL + 0xCD157F021C49FFFAULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x8AF310A6AB5AE62DULL + 0xC7D7915901295B06ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x82F52A081B61D2EFULL + 0xE7C536E00C9D603EULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xD4B51D71CA1B5073ULL + 0xE7AE1FF63B03708BULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xFEA31785D90DF8D7ULL + 0x944D28A2E3D939E4ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xAB2CE8153E67B577ULL + 0xAF01B06B627922DCULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xC78F753E9E2DD9A3ULL + 0xC54A92590C14E788ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xE165F904A6C58193ULL + 0xDD095B7FE6EB3B68ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xD4644D1DBDB57683ULL + 0xA8DD4BD6B2E58EBBULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xFCE5F22448AA4087ULL + 0x8ABFC30263E19F91ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xEAA614AA98E6A6CFULL + 0x83AAF45E4C448E3BULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x8126E6CFE03AF5CFULL + 0x94682DB27E69F7BDULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xA78738E8A9C35645ULL + 0xE65CF57064641B5DULL);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 1618U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneC[((aIndex + 3924U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 3049U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneA[((aIndex + 4461U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 4U) + RotL64(aCross, 51U)) ^ (RotL64(aPrevious, 21U) + RotL64(aCarry, 39U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = (aWandererA + RotL64(aScatter, 35U)) + 13854738573712660276U;
            aOrbiterA = (aWandererD + RotL64(aIngress, 57U)) + 16835460633412286294U;
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 21U)) + RotL64(aCarry, 39U)) + 6785859293758091931U;
            aOrbiterC = (aWandererI + RotL64(aCross, 13U)) + 126317283127992659U;
            aOrbiterK = (aWandererG + RotL64(aScatter, 37U)) + 7568963536291415413U;
            aOrbiterI = (aWandererC + RotL64(aPrevious, 29U)) + 12294016745653004819U;
            aOrbiterD = (aWandererK + RotL64(aCross, 52U)) + 18269588932920281147U;
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 11U)) + 5872406424994751026U) + aNonceWordO;
            aOrbiterF = (((aWandererB + RotL64(aScatter, 3U)) + RotL64(aCarry, 35U)) + 7764434758831474129U) + aPhaseFOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = (((aWandererE + RotL64(aCross, 39U)) + RotL64(aCarry, 23U)) + 4804168969415573371U) + aPhaseFOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = (aWandererJ + RotL64(aIngress, 50U)) + 959601763507651280U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 9257644462479293048U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 14332699366894494579U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8829304078930625541U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 10487012596470786004U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 612729229562321440U;
            aOrbiterI = RotL64((aOrbiterI * 11380387280507726003U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 7845523921295625315U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 12742115479740024747U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15578543510683986421U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 10294667720904610944U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 14369711143154904567U;
            aOrbiterC = RotL64((aOrbiterC * 13753005602288309379U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 10918344717497681894U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 18136794828308636957U;
            aOrbiterD = RotL64((aOrbiterD * 17899418637978002409U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 14378638206724886404U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 7077588188450008059U;
            aOrbiterF = RotL64((aOrbiterF * 485375960462924335U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 8941870012851971932U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 15242087859620352399U;
            aOrbiterH = RotL64((aOrbiterH * 4963002810455992839U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 10395280254030875387U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 6826595516076975980U) ^ aNonceWordP;
            aOrbiterA = RotL64((aOrbiterA * 6198886240333178001U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 10407910809564430664U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 6368255889263255730U) ^ aNonceWordL;
            aOrbiterK = RotL64((aOrbiterK * 3809496492809859731U), 19U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterF) + 6365669830464231626U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1]) + aNonceWordK;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 596785214258266904U;
            aOrbiterJ = RotL64((aOrbiterJ * 6338109335634389561U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 4807438574488830717U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 13854738573712660276U;
            aOrbiterG = RotL64((aOrbiterG * 6954368463489446551U), 47U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterC, 12U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 27U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 39U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterD, 21U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 37U));
            aIngress = aIngress + RotL64(aOrbiterH, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 57U)) + aOrbiterA) + aNonceWordA);
            aWandererH = aWandererH ^ ((((RotL64(aScatter, 13U) + RotL64(aOrbiterK, 3U)) + aOrbiterC) + aNonceWordN) + aPhaseFWandererUpdateSaltB[((aIndex + 12U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 40U) + aOrbiterG) + RotL64(aOrbiterA, 29U)) + RotL64(aCarry, 5U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterD, 48U)) + aOrbiterF);
            aWandererE = aWandererE + (((RotL64(aScatter, 19U) + RotL64(aOrbiterE, 21U)) + aOrbiterJ) + RotL64(aCarry, 19U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 11U) + aOrbiterD) + RotL64(aOrbiterH, 23U));
            aWandererA = aWandererA + (((RotL64(aIngress, 22U) + aOrbiterC) + RotL64(aOrbiterB, 37U)) + aNonceWordC);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterE, 27U)) + aOrbiterF);
            aWandererD = aWandererD + ((RotL64(aCross, 47U) + RotL64(aOrbiterK, 35U)) + aOrbiterA);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 37U) + aOrbiterC) + RotL64(aOrbiterH, 50U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterA, 11U)) + aOrbiterD) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 30U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 51U));
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererA);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererH, 56U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ aNonceWordB;
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 7461U)) & S_BLOCK1], 26U) ^ RotL64(aOperationLaneD[((aIndex + 8908U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 9727U)) & S_BLOCK1], 30U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 10767U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aPrevious, 51U)) ^ (RotL64(aIngress, 22U) ^ RotL64(aCarry, 35U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterK = (((aWandererE + RotL64(aPrevious, 19U)) + 18302975933754610273U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordF;
            aOrbiterJ = (aWandererI + RotL64(aCross, 35U)) + 16736972646771456082U;
            aOrbiterI = (aWandererB + RotL64(aIngress, 27U)) + 17389406266488137442U;
            aOrbiterC = (aWandererF + RotL64(aScatter, 23U)) + 5252511566486165539U;
            aOrbiterD = ((aWandererG + RotL64(aCross, 11U)) + 5730715427422747640U) + aNonceWordD;
            aOrbiterG = ((aWandererH + RotL64(aScatter, 14U)) + 6412695646456045825U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 57U)) + RotL64(aCarry, 23U)) + 9539701605708994494U;
            aOrbiterE = (aWandererD + RotL64(aIngress, 39U)) + 18355107116412945722U;
            aOrbiterB = ((aWandererC + RotL64(aCross, 21U)) + RotL64(aCarry, 5U)) + 11735742491750132942U;
            aOrbiterA = ((aWandererK + RotL64(aIngress, 50U)) + RotL64(aCarry, 37U)) + 12363819388562658842U;
            aOrbiterF = (aWandererA + RotL64(aScatter, 29U)) + 5861430292304371543U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 15027487084595017708U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 7012850020745791926U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15952928839355613939U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 11904871669287886120U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 11199760114477343208U;
            aOrbiterJ = RotL64((aOrbiterJ * 7156374911847525867U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 3856004502263742700U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 3705931243173921893U;
            aOrbiterD = RotL64((aOrbiterD * 10334871178498711485U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 12305785390539209389U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 18057980996551978823U;
            aOrbiterH = RotL64((aOrbiterH * 4850564181113470859U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 3229431819292153014U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 2994716629242460094U;
            aOrbiterB = RotL64((aOrbiterB * 1029427328395257917U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 9796307843453735512U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 2957260393651252432U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7261055869794739609U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 4060469664218866340U) + aNonceWordO;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 17462081697889685330U;
            aOrbiterC = RotL64((aOrbiterC * 7712009170974461225U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 13638660073917821172U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 15202349592659062565U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4514326257446024301U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 12071949111168967041U) + aNonceWordN;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 11930843273199806728U;
            aOrbiterE = RotL64((aOrbiterE * 16229663295689525137U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 11294220104731500296U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 440743185210586759U;
            aOrbiterA = RotL64((aOrbiterA * 14810195235168807229U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 8514240764798061804U) + aNonceWordP;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 18302975933754610273U;
            aOrbiterF = RotL64((aOrbiterF * 1972439346780950873U), 53U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterD, 21U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 27U));
            aIngress = aIngress + (RotL64(aOrbiterH, 51U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 6U));
            aIngress = aIngress + RotL64(aOrbiterF, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterF, 11U)) + RotL64(aCarry, 21U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterF, 23U)) + aOrbiterB);
            aWandererH = aWandererH + ((RotL64(aIngress, 5U) + aOrbiterA) + RotL64(aOrbiterG, 56U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 43U) + aOrbiterI) + RotL64(aOrbiterC, 19U));
            aWandererE = aWandererE + ((RotL64(aScatter, 29U) + RotL64(aOrbiterI, 43U)) + aOrbiterD);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 37U) + RotL64(aOrbiterK, 47U)) + aOrbiterA) + aNonceWordG);
            aWandererC = aWandererC + ((RotL64(aPrevious, 54U) + RotL64(aOrbiterA, 37U)) + aOrbiterB);
            aWandererF = aWandererF ^ ((RotL64(aCross, 41U) + aOrbiterC) + RotL64(aOrbiterJ, 5U));
            aWandererA = aWandererA + (((((RotL64(aScatter, 11U) + aOrbiterF) + RotL64(aOrbiterC, 13U)) + RotL64(aCarry, 3U)) + aNonceWordI) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterH, 60U)) + aOrbiterF);
            aWandererD = aWandererD + ((((RotL64(aCross, 24U) + RotL64(aOrbiterE, 39U)) + aOrbiterC) + aNonceWordB) + aPhaseFWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 56U));
            aCarry = aCarry + (RotL64(aWandererI, 11U) ^ aWandererK);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + (RotL64(aWandererJ, 24U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererG, 43U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordI);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 14383U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12206U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 14401U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 13140U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 21U) + RotL64(aPrevious, 40U)) + (RotL64(aIngress, 57U) ^ RotL64(aCross, 5U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterD = (aWandererG + RotL64(aIngress, 34U)) + 16451272412693907816U;
            aOrbiterH = ((aWandererD + RotL64(aCross, 43U)) + RotL64(aCarry, 29U)) + 10099485419723255462U;
            aOrbiterC = (aWandererB + RotL64(aScatter, 23U)) + 17668900099534923192U;
            aOrbiterF = (aWandererH + RotL64(aPrevious, 21U)) + 5497093724143181753U;
            aOrbiterB = (aWandererE + RotL64(aCross, 47U)) + 10354044773550071706U;
            aOrbiterA = (aWandererC + RotL64(aIngress, 29U)) + 12728258851198019099U;
            aOrbiterK = (aWandererJ + RotL64(aPrevious, 19U)) + 4144050505314242618U;
            aOrbiterJ = ((((aWandererA + RotL64(aScatter, 13U)) + RotL64(aCarry, 5U)) + 14133805325480076530U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordH;
            aOrbiterE = (aWandererK + RotL64(aPrevious, 10U)) + 308863673210602899U;
            aOrbiterG = ((aWandererI + RotL64(aIngress, 53U)) + RotL64(aCarry, 53U)) + 11741180130160569753U;
            aOrbiterI = ((aWandererF + RotL64(aScatter, 5U)) + 12926863156769180448U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 211920854786494259U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 13234608842479411078U) ^ aNonceWordB;
            aOrbiterC = RotL64((aOrbiterC * 2556747209733759467U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 9164711974854618892U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 6667377062281954219U;
            aOrbiterA = RotL64((aOrbiterA * 2603737166987437649U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 4559040002406721850U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 1749875480850675109U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15822640067349481089U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 9555365165561936366U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 18289733999504213574U;
            aOrbiterB = RotL64((aOrbiterB * 14156217554673229429U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 8727162691639622461U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 291406782452963706U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8413500075082350243U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 8294911802626492257U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 15853578397277298548U;
            aOrbiterG = RotL64((aOrbiterG * 13256191781365357747U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 11535146194939658681U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 2177540476748375661U;
            aOrbiterD = RotL64((aOrbiterD * 15791341922007841029U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 2705306323728084136U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 17617871830709148043U;
            aOrbiterF = RotL64((aOrbiterF * 3449981219502809255U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 3699834746313613206U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 17952609181629473245U;
            aOrbiterK = RotL64((aOrbiterK * 6103160209028988839U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 8016694658897707674U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 6971251395823324489U;
            aOrbiterE = RotL64((aOrbiterE * 13483776115929040277U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 17467528888050817915U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 16451272412693907816U;
            aOrbiterI = RotL64((aOrbiterI * 13689734638238895071U), 21U);
            //
            aIngress = RotL64(aOrbiterG, 34U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 29U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 19U));
            aIngress = aIngress + (RotL64(aOrbiterI, 27U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 11U));
            aIngress = aIngress + RotL64(aOrbiterC, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aCross, 19U) + RotL64(aOrbiterG, 13U)) + aOrbiterI);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 43U) + aOrbiterH) + RotL64(aOrbiterA, 52U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 5U) + aOrbiterJ) + RotL64(aOrbiterB, 39U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 40U) + RotL64(aOrbiterE, 35U)) + aOrbiterH);
            aWandererH = aWandererH + (((RotL64(aCross, 37U) + aOrbiterC) + RotL64(aOrbiterI, 5U)) + RotL64(aCarry, 13U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 23U) + aOrbiterA) + RotL64(aOrbiterD, 21U));
            aWandererB = aWandererB + ((RotL64(aScatter, 51U) + aOrbiterK) + RotL64(aOrbiterC, 41U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterF, 57U)) + aOrbiterD) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 47U) + aOrbiterJ) + RotL64(aOrbiterF, 27U)) + aNonceWordA);
            aWandererK = aWandererK ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterK, 24U)) + aOrbiterI) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 28U) + RotL64(aOrbiterH, 29U)) + aOrbiterK) + RotL64(aCarry, 35U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 6U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererB);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 39U));
            aCarry = aCarry + RotL64(aWandererK, 23U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = aCarry ^ aNonceWordJ;
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 19928U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((aIndex + 20843U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18174U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 19346U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 3U) ^ RotL64(aIngress, 23U)) ^ (RotL64(aPrevious, 40U) + RotL64(aCarry, 53U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterC = ((aWandererE + RotL64(aIngress, 4U)) + RotL64(aCarry, 41U)) + 11698283336767769359U;
            aOrbiterG = (aWandererI + RotL64(aScatter, 41U)) + 13297826354831483872U;
            aOrbiterB = (((aWandererK + RotL64(aPrevious, 37U)) + RotL64(aCarry, 47U)) + 15254999058287530795U) + aNonceWordB;
            aOrbiterF = (aWandererF + RotL64(aCross, 39U)) + 17474166585085346567U;
            aOrbiterK = (aWandererJ + RotL64(aIngress, 47U)) + 15684783498452840289U;
            aOrbiterE = (aWandererG + RotL64(aPrevious, 21U)) + 5061229733465216486U;
            aOrbiterH = (aWandererC + RotL64(aCross, 57U)) + 15370981279168377944U;
            aOrbiterD = ((aWandererB + RotL64(aScatter, 53U)) + RotL64(aCarry, 19U)) + 17966672773619554092U;
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 29U)) + 14685092893994491068U) + aPhaseFOrbiterAssignSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = ((aWandererD + RotL64(aCross, 18U)) + 12798804186209406389U) + aNonceWordI;
            aOrbiterJ = (((aWandererH + RotL64(aIngress, 27U)) + 2848444181474221574U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordD;
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 8551142075919636146U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 8833198159158950723U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7650289040764974737U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 7351473160893666232U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 14204899612487622222U;
            aOrbiterK = RotL64((aOrbiterK * 6317485031956448029U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 7008985178526543258U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 13576796403863120356U;
            aOrbiterE = RotL64((aOrbiterE * 13745839827679114077U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 5769784656937900699U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 14075925808204936705U;
            aOrbiterH = RotL64((aOrbiterH * 5844894088757604713U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 17818667502858010896U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 16016922065572683130U;
            aOrbiterD = RotL64((aOrbiterD * 7525645833898085373U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 1582458237855075977U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 10830440354527138227U;
            aOrbiterI = RotL64((aOrbiterI * 10499386926982228251U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 10653964151654643772U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 11218475491129483859U;
            aOrbiterA = RotL64((aOrbiterA * 3338108067044357141U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 9863649760189649255U) + aNonceWordJ;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 13790281439048354358U;
            aOrbiterJ = RotL64((aOrbiterJ * 4682098083538482849U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 14846954923718136337U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 522207783972623813U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14299798934454852811U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 426829715716262697U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 7482977730216354509U;
            aOrbiterG = RotL64((aOrbiterG * 6317437989422015173U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 10736099808538972990U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 11698283336767769359U;
            aOrbiterF = RotL64((aOrbiterF * 17230175904095995929U), 19U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterH, 11U);
            aIngress = aIngress + (RotL64(aOrbiterB, 5U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterJ, 23U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterI, 35U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 56U));
            aIngress = aIngress + RotL64(aOrbiterC, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aScatter, 37U) + RotL64(aOrbiterG, 6U)) + aOrbiterJ);
            aWandererF = aWandererF ^ (((RotL64(aCross, 57U) + aOrbiterC) + RotL64(aOrbiterK, 13U)) + aNonceWordN);
            aWandererI = aWandererI + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterE, 3U)) + aOrbiterI);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterF, 47U)) + aOrbiterI);
            aWandererJ = aWandererJ + (((RotL64(aCross, 5U) + RotL64(aOrbiterC, 27U)) + aOrbiterG) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterC, 29U)) + aOrbiterI) + aNonceWordM);
            aWandererE = aWandererE + ((((RotL64(aScatter, 26U) + aOrbiterA) + RotL64(aOrbiterF, 43U)) + RotL64(aCarry, 3U)) + aNonceWordO);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 21U) + aOrbiterK) + RotL64(aOrbiterD, 53U));
            aWandererD = aWandererD + (((RotL64(aIngress, 53U) + aOrbiterK) + RotL64(aOrbiterB, 40U)) + RotL64(aCarry, 11U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 29U) + aOrbiterG) + RotL64(aOrbiterH, 23U)) + aPhaseFWandererUpdateSaltF[((aIndex + 14U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aCross, 24U) + RotL64(aOrbiterE, 51U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 10U));
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 37U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererI);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 41U));
            aCarry = aCarry + RotL64(aWandererD, 28U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ aNonceWordL;
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 21956U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneA[((aIndex + 22302U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26911U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((aIndex + 24541U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 22U) + RotL64(aIngress, 41U)) ^ (RotL64(aPrevious, 53U) + RotL64(aCarry, 5U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterC = (((aWandererC + RotL64(aScatter, 47U)) + RotL64(aCarry, 19U)) + 6467297102954816305U) + aPhaseFOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 41U)) + 7921154109831114952U) + aNonceWordE;
            aOrbiterJ = (aWandererK + RotL64(aIngress, 60U)) + 5701131763215638919U;
            aOrbiterI = ((aWandererD + RotL64(aCross, 57U)) + 10022999076719002684U) + aNonceWordI;
            aOrbiterH = (aWandererA + RotL64(aPrevious, 53U)) + 4367135243038982316U;
            aOrbiterG = (aWandererJ + RotL64(aIngress, 27U)) + 14445846824810383592U;
            aOrbiterE = ((aWandererG + RotL64(aCross, 51U)) + RotL64(aCarry, 35U)) + 7683697954545773253U;
            aOrbiterF = ((aWandererH + RotL64(aScatter, 19U)) + 17517006750428030899U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = (aWandererB + RotL64(aCross, 30U)) + 2052484792684025476U;
            aOrbiterA = (aWandererE + RotL64(aScatter, 43U)) + 6279463052085808926U;
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 13U)) + RotL64(aCarry, 53U)) + 679280153651813684U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 2939516520188460569U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 1960616434964712325U;
            aOrbiterJ = RotL64((aOrbiterJ * 15145998415466343039U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 12273819390719947361U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 5685033154709449397U;
            aOrbiterG = RotL64((aOrbiterG * 9845666295874714959U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 9314494172199500653U) + aNonceWordP;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 15757631834636427621U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15483543888965744529U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 10878078046389399574U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 3583495913766365232U;
            aOrbiterA = RotL64((aOrbiterA * 2913540984990155225U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 7385544065754622301U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 16839599460207922881U;
            aOrbiterC = RotL64((aOrbiterC * 240651605910592561U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 13038163804940349251U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 2587538594933924000U;
            aOrbiterI = RotL64((aOrbiterI * 3091149760401278671U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 13109518583364738004U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 2447689055742474261U;
            aOrbiterE = RotL64((aOrbiterE * 12100180201235703193U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 5752044906692668618U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 6637725371036522120U;
            aOrbiterK = RotL64((aOrbiterK * 6021986525167161115U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 16549229877442298618U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 12825651879441561108U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9079931351967033993U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 16088338999978085987U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 12584648360998154782U;
            aOrbiterB = RotL64((aOrbiterB * 2109996837220975261U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 7526256599938771686U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 6467297102954816305U;
            aOrbiterH = RotL64((aOrbiterH * 9289442676936248653U), 21U);
            //
            aIngress = RotL64(aOrbiterD, 52U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 13U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 43U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 47U));
            aIngress = aIngress + (RotL64(aOrbiterK, 5U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aCross, 57U) + aOrbiterE) + RotL64(aOrbiterJ, 58U)) + RotL64(aCarry, 5U)) + aNonceWordN);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 60U) + aOrbiterG) + RotL64(aOrbiterK, 51U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 35U) + aOrbiterH) + RotL64(aOrbiterF, 3U)) + RotL64(aCarry, 43U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterF, 43U)) + aOrbiterD);
            aWandererC = aWandererC + (((RotL64(aCross, 41U) + RotL64(aOrbiterB, 23U)) + aOrbiterD) + aNonceWordJ);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterK, 21U)) + aOrbiterJ);
            aWandererH = aWandererH + ((RotL64(aPrevious, 48U) + aOrbiterA) + RotL64(aOrbiterD, 35U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterE, 5U)) + aOrbiterA);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterA, 29U)) + aOrbiterC) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((((RotL64(aCross, 29U) + aOrbiterI) + RotL64(aOrbiterE, 38U)) + aNonceWordA) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aIngress, 19U) + aOrbiterB) + RotL64(aOrbiterE, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererJ);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 24U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererC, 12U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ aNonceWordF;
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 30050U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneB[((aIndex + 32484U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29677U)) & S_BLOCK1], 6U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32631U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 13U) ^ RotL64(aPrevious, 56U)) + (RotL64(aCross, 41U) ^ RotL64(aIngress, 27U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterK = (aWandererA + RotL64(aIngress, 29U)) + 12311607308490066301U;
            aOrbiterJ = (((aWandererE + RotL64(aCross, 51U)) + 13100864684740679846U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordC;
            aOrbiterB = (aWandererJ + RotL64(aScatter, 54U)) + 13697304189274329704U;
            aOrbiterH = (aWandererF + RotL64(aPrevious, 37U)) + 9047976902871216732U;
            aOrbiterI = (((aWandererH + RotL64(aIngress, 47U)) + RotL64(aCarry, 5U)) + 2147897579538537888U) + aNonceWordF;
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 43U)) + 2072444829390996142U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = ((aWandererC + RotL64(aScatter, 3U)) + RotL64(aCarry, 19U)) + 2129307836981020908U;
            aOrbiterG = (aWandererI + RotL64(aCross, 35U)) + 10663145333751112064U;
            aOrbiterD = (aWandererG + RotL64(aPrevious, 5U)) + 15019844390503785459U;
            aOrbiterA = ((aWandererK + RotL64(aCross, 24U)) + RotL64(aCarry, 41U)) + 5460865577557928142U;
            aOrbiterF = ((aWandererD + RotL64(aScatter, 57U)) + 15806522559993224197U) + aNonceWordB;
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 6361113778657833389U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 8306013884615042570U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8234258702656728667U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 4038420580499706912U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 11908091484457158973U;
            aOrbiterI = RotL64((aOrbiterI * 3964111175645156719U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 11133912466611921250U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 2469227904206936928U;
            aOrbiterE = RotL64((aOrbiterE * 2704438771198001599U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 13234017916788297295U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 9061117693840451988U;
            aOrbiterC = RotL64((aOrbiterC * 3637440416741459419U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 12013423690843812324U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 14371779015144617412U;
            aOrbiterG = RotL64((aOrbiterG * 3359568073302062667U), 35U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterC) + 10044883414565441442U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordE;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 14334898081890462218U;
            aOrbiterD = RotL64((aOrbiterD * 4878939077928220019U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 13788962593988366125U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 8377887372059713516U;
            aOrbiterA = RotL64((aOrbiterA * 1925913354197206851U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 4584439257847749371U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 13335592911357756498U;
            aOrbiterF = RotL64((aOrbiterF * 6515028218115896375U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 11166747459333977215U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 2368465601636093120U;
            aOrbiterK = RotL64((aOrbiterK * 1929974840976648333U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 4538402006569031063U) + aNonceWordJ;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 3397601475441212067U;
            aOrbiterJ = RotL64((aOrbiterJ * 12043369327112500565U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 4804403185062062524U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 12311607308490066301U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10281231071618984185U), 29U);
            //
            aIngress = RotL64(aOrbiterA, 54U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 5U));
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 39U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 29U));
            aIngress = aIngress + RotL64(aOrbiterC, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterH, 58U)) + aOrbiterE);
            aWandererE = aWandererE + (((RotL64(aPrevious, 39U) + aOrbiterD) + RotL64(aOrbiterC, 11U)) + RotL64(aCarry, 35U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterK, 3U)) + aOrbiterB) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 18U) + RotL64(aOrbiterG, 39U)) + aOrbiterB);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 43U) + aOrbiterI) + RotL64(aOrbiterD, 13U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 47U) + aOrbiterK) + RotL64(aOrbiterI, 29U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 53U) + aOrbiterI) + RotL64(aOrbiterA, 43U)) + aNonceWordK);
            aWandererG = aWandererG + (((RotL64(aScatter, 60U) + aOrbiterF) + RotL64(aOrbiterK, 24U)) + RotL64(aCarry, 21U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 5U) + aOrbiterC) + RotL64(aOrbiterJ, 5U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterK, 37U)) + aOrbiterC);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 37U) + aOrbiterC) + RotL64(aOrbiterE, 19U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 26U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + (RotL64(aWandererH, 41U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererD, 6U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererE, 57U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ aNonceWordJ;
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

void TwistExpander_Bowling_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xCF5C43B812912B11ULL + 0x97F6B588F988076DULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xAB14AEB4DB1B0B09ULL + 0x9922BB00D5701EC4ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x84180F44A8D83E8DULL + 0x9AEBB43D5318EB24ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x9B375D7AD04AF743ULL + 0xDC6D3FAB0F5C2C08ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xB615F8CB803959E9ULL + 0x8F3FE95EBFEA9BA9ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x89F06BFEA0DBE443ULL + 0xCEDF48B9C5385CC4ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x9769CA0A80F59939ULL + 0xFE7549DCAF52B0FBULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xD43EFCDA83E6C213ULL + 0xBC6243E7F6D71C55ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x9080E1C0D84DB24FULL + 0xE5179171CF0544DBULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xC917C37BB2C52493ULL + 0x8DC18010F854CEEEULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xE096B2F332E1D60DULL + 0xCEB41506CA20C88DULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xEFDF816D5A07FF69ULL + 0xCE72D8116228AED8ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xBBDEAE074D52483DULL + 0xEB553A420C3ED369ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xBC774BEB3BE1B7FFULL + 0xDCEE3484D8254237ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x8E4373EDCEAF5CCFULL + 0xCB0961486D889FEAULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xD5DD2B9A7B0118D1ULL + 0x84EF4B8BAD11AA0EULL);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 368U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 4229U)) & S_BLOCK1], 42U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 4667U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((aIndex + 3777U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 54U) + RotL64(aPrevious, 41U)) ^ (RotL64(aCarry, 3U) + RotL64(aIngress, 19U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterC = (aWandererE + RotL64(aCross, 11U)) + 1888427424966603593U;
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 44U)) + RotL64(aCarry, 13U)) + 5436761445660415091U;
            aOrbiterE = (aWandererJ + RotL64(aScatter, 53U)) + 17322876217962143270U;
            aOrbiterD = ((aWandererA + RotL64(aIngress, 23U)) + 9728299982740564979U) + aPhaseFOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = (aWandererH + RotL64(aScatter, 27U)) + 301720335271716921U;
            aOrbiterI = ((aWandererD + RotL64(aPrevious, 29U)) + 8069685428854814396U) + aNonceWordP;
            aOrbiterB = (aWandererG + RotL64(aCross, 35U)) + 1973715500949100991U;
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 13U)) + 87666408799854155U) + aNonceWordB;
            aOrbiterA = ((aWandererC + RotL64(aScatter, 18U)) + RotL64(aCarry, 35U)) + 12195436904339035245U;
            aOrbiterH = (aWandererI + RotL64(aCross, 21U)) + 4578742069143400295U;
            aOrbiterG = (((aWandererK + RotL64(aIngress, 39U)) + RotL64(aCarry, 23U)) + 7828776048774876484U) + aPhaseFOrbiterAssignSaltD[((aIndex + 22U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 17203146364542781833U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 16913369550858890466U;
            aOrbiterE = RotL64((aOrbiterE * 13534417587921978507U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 9632761514552265402U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 9106637671877341286U;
            aOrbiterI = RotL64((aOrbiterI * 9073709119482640391U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 15423680889126750876U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 6087310684583331882U;
            aOrbiterC = RotL64((aOrbiterC * 8964465129744898619U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 5420955876411796789U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 14166807419730848032U;
            aOrbiterD = RotL64((aOrbiterD * 442659738632823751U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 8118312450347026824U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 4253043584558403086U;
            aOrbiterB = RotL64((aOrbiterB * 5651748455190536467U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 8810774678371762700U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 12218479555589447835U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11026364205248516355U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 11389930523582876358U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 16334420553471379915U) ^ aNonceWordE;
            aOrbiterG = RotL64((aOrbiterG * 13830132212033904777U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 18201289372553710279U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 7196540389657785361U;
            aOrbiterK = RotL64((aOrbiterK * 13058135202554889791U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 2601046573550065116U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 2243003381737071984U;
            aOrbiterF = RotL64((aOrbiterF * 10518763530499878945U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 6058992247656841580U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 10083863011670540073U) ^ aNonceWordM;
            aOrbiterJ = RotL64((aOrbiterJ * 17908394295613117155U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 8505005026063156940U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 1888427424966603593U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 18298382581929885653U), 3U);
            //
            aIngress = RotL64(aOrbiterD, 57U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 37U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 53U));
            aIngress = aIngress + (RotL64(aOrbiterA, 60U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterI, 41U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterG, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aCross, 41U) + RotL64(aOrbiterF, 42U)) + aOrbiterG);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 26U) + aOrbiterH) + RotL64(aOrbiterA, 47U));
            aWandererD = aWandererD + ((RotL64(aIngress, 11U) + aOrbiterG) + RotL64(aOrbiterD, 57U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 13U) + aOrbiterG) + RotL64(aOrbiterI, 29U));
            aWandererG = aWandererG + ((RotL64(aIngress, 47U) + aOrbiterE) + RotL64(aOrbiterG, 37U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 22U) + RotL64(aOrbiterE, 3U)) + aOrbiterB) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aCross, 51U) + RotL64(aOrbiterK, 5U)) + aOrbiterF) + RotL64(aCarry, 41U)) + aNonceWordF);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 29U) + aOrbiterB) + RotL64(aOrbiterA, 27U)) + aPhaseFWandererUpdateSaltE[((aIndex + 26U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 39U) + aOrbiterD) + RotL64(aOrbiterH, 40U)) + RotL64(aCarry, 3U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterE, 51U)) + aOrbiterC);
            aWandererF = aWandererF + ((RotL64(aCross, 53U) + RotL64(aOrbiterI, 11U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 52U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordM);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 5515U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneD[((aIndex + 7409U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 6063U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((aIndex + 6227U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 58U) ^ RotL64(aPrevious, 13U)) + (RotL64(aCross, 29U) ^ RotL64(aIngress, 41U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterK = (aWandererF + RotL64(aCross, 19U)) + 1297415699043177788U;
            aOrbiterE = (aWandererB + RotL64(aIngress, 11U)) + 17583786534509260153U;
            aOrbiterB = (aWandererJ + RotL64(aPrevious, 57U)) + 643197858925708798U;
            aOrbiterI = (aWandererC + RotL64(aScatter, 39U)) + 5062653766915694874U;
            aOrbiterG = (((aWandererK + RotL64(aIngress, 24U)) + RotL64(aCarry, 13U)) + 7034273638367180511U) + aNonceWordA;
            aOrbiterA = (((aWandererA + RotL64(aCross, 3U)) + 2026909726972916996U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordB;
            aOrbiterJ = (aWandererH + RotL64(aScatter, 5U)) + 2785690475553211646U;
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 47U)) + RotL64(aCarry, 5U)) + 2910341716302991892U;
            aOrbiterC = (aWandererG + RotL64(aCross, 13U)) + 2834181605200829791U;
            aOrbiterD = ((aWandererI + RotL64(aScatter, 21U)) + RotL64(aCarry, 43U)) + 13323052600571281928U;
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 60U)) + 10434901530315760460U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 247903955625194782U) + aNonceWordO;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 5196515747387257163U;
            aOrbiterB = RotL64((aOrbiterB * 1799024689023272275U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 7196305682377987476U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 14777739876892587484U) ^ aNonceWordM;
            aOrbiterE = RotL64((aOrbiterE * 95220583948241581U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 10609060796540136671U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 8386027207212484155U;
            aOrbiterG = RotL64((aOrbiterG * 4855610536246556893U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 729659744301903424U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 2350564261412606157U;
            aOrbiterJ = RotL64((aOrbiterJ * 16713856782349084977U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 16611987556673864177U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 1525195188708550503U;
            aOrbiterC = RotL64((aOrbiterC * 10045858602151004553U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 4654808490980989596U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 8189569777087686263U;
            aOrbiterK = RotL64((aOrbiterK * 17278657566389299577U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 10932857495004451792U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 1833880112534916813U;
            aOrbiterI = RotL64((aOrbiterI * 8004341577533825681U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 13100236350175516423U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 2773759534195186313U;
            aOrbiterA = RotL64((aOrbiterA * 3194954066097323161U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 13963126688973399221U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 1464529855671190406U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6129954747502059213U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 9489842625026216815U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 17806120432918490594U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 349307975773661379U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 13833297268854563081U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 1297415699043177788U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4818542043777342249U), 35U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterE, 60U);
            aIngress = aIngress + (RotL64(aOrbiterB, 47U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 19U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 57U));
            aIngress = aIngress + (RotL64(aOrbiterF, 13U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterG, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aIngress, 54U) + RotL64(aOrbiterC, 35U)) + aOrbiterH) + aNonceWordJ);
            aWandererD = aWandererD + ((RotL64(aCross, 57U) + RotL64(aOrbiterI, 11U)) + aOrbiterG);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterA, 39U)) + aOrbiterC);
            aWandererF = aWandererF + (((RotL64(aScatter, 11U) + aOrbiterC) + RotL64(aOrbiterJ, 37U)) + RotL64(aCarry, 57U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 27U) + aOrbiterF) + RotL64(aOrbiterB, 28U));
            aWandererE = aWandererE + (((RotL64(aCross, 41U) + RotL64(aOrbiterB, 13U)) + aOrbiterA) + aNonceWordC);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 52U) + aOrbiterD) + RotL64(aOrbiterF, 3U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 13U) + RotL64(aOrbiterJ, 47U)) + aOrbiterA);
            aWandererB = aWandererB ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterI, 53U)) + aOrbiterB);
            aWandererJ = aWandererJ + (((((RotL64(aIngress, 5U) + aOrbiterK) + RotL64(aOrbiterE, 26U)) + RotL64(aCarry, 27U)) + aNonceWordK) + aPhaseFWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 23U) + aOrbiterK) + RotL64(aOrbiterD, 23U)) + aPhaseFWandererUpdateSaltD[((aIndex + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 30U));
            aCarry = aCarry + (RotL64(aWandererA, 21U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererK);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + (RotL64(aWandererG, 26U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererJ, 37U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordG);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 14283U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneA[((aIndex + 11491U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 15778U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneC[((aIndex + 12724U)) & S_BLOCK1], 50U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aIngress, 27U)) + (RotL64(aCross, 12U) + RotL64(aPrevious, 51U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterG = ((aWandererA + RotL64(aScatter, 47U)) + 14157904117287696136U) + aPhaseFOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 50U)) + 7369512677371640676U;
            aOrbiterK = ((((aWandererK + RotL64(aCross, 13U)) + RotL64(aCarry, 35U)) + 8411250745902073798U) + aPhaseFOrbiterAssignSaltA[((aIndex + 26U)) & S_SALT1]) + aNonceWordC;
            aOrbiterE = (aWandererC + RotL64(aIngress, 21U)) + 5002041814539710275U;
            aOrbiterF = (aWandererH + RotL64(aScatter, 29U)) + 9538041410816283124U;
            aOrbiterD = (aWandererE + RotL64(aPrevious, 23U)) + 5210700103927513061U;
            aOrbiterA = (aWandererJ + RotL64(aIngress, 3U)) + 7600709399101287982U;
            aOrbiterC = (aWandererB + RotL64(aCross, 11U)) + 2366369466696580499U;
            aOrbiterI = (aWandererG + RotL64(aIngress, 27U)) + 5544575244203019109U;
            aOrbiterB = (((aWandererF + RotL64(aScatter, 37U)) + RotL64(aCarry, 21U)) + 8710073749110329779U) + aNonceWordP;
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 34U)) + RotL64(aCarry, 53U)) + 15998211310115361630U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 15354357553877376422U) + aNonceWordG;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 10657523549259276169U;
            aOrbiterK = RotL64((aOrbiterK * 13695239532898311073U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 10405750198355464768U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 3465819693133515142U;
            aOrbiterD = RotL64((aOrbiterD * 14678343718277562799U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 16724189641701408630U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 3484340153620198872U) ^ aNonceWordA;
            aOrbiterJ = RotL64((aOrbiterJ * 17247547677520703125U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 7420442404884871126U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 11138445997256757636U;
            aOrbiterF = RotL64((aOrbiterF * 11167543379937571127U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 1428191560884663125U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 16950093140800653985U;
            aOrbiterC = RotL64((aOrbiterC * 4423012306984814805U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 17288299075036481960U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 13793597915359681028U;
            aOrbiterB = RotL64((aOrbiterB * 9639204979982125757U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 5017972942710079726U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 12409957957614320964U;
            aOrbiterG = RotL64((aOrbiterG * 10273295741911545745U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 12487994181992095174U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 1573393166996612118U;
            aOrbiterE = RotL64((aOrbiterE * 13364311829104520751U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 13227642825780350128U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 7961292096150889569U;
            aOrbiterA = RotL64((aOrbiterA * 16627209081334341289U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 10312485102088913337U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 3177620041478410950U;
            aOrbiterI = RotL64((aOrbiterI * 15918551366833593853U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 2599092792737616563U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 14157904117287696136U;
            aOrbiterH = RotL64((aOrbiterH * 14883446269291639813U), 47U);
            //
            aIngress = RotL64(aOrbiterK, 53U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterA, 19U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterD, 26U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 47U));
            aIngress = aIngress + (RotL64(aOrbiterH, 51U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterE, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 50U) + aOrbiterK) + RotL64(aOrbiterA, 19U));
            aWandererB = aWandererB + ((RotL64(aIngress, 35U) + RotL64(aOrbiterF, 13U)) + aOrbiterG);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 21U) + aOrbiterH) + RotL64(aOrbiterF, 28U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 29U) + aOrbiterH) + RotL64(aOrbiterE, 23U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 47U) + aOrbiterJ) + RotL64(aOrbiterI, 39U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 57U) + RotL64(aOrbiterI, 3U)) + aOrbiterB) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterD, 60U)) + aOrbiterE) + aPhaseFWandererUpdateSaltB[((aIndex + 20U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aScatter, 19U) + aOrbiterE) + RotL64(aOrbiterC, 41U)) + RotL64(aCarry, 53U)) + aNonceWordB);
            aWandererF = aWandererF ^ (((RotL64(aCross, 52U) + aOrbiterA) + RotL64(aOrbiterB, 53U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aIngress, 23U) + RotL64(aOrbiterK, 37U)) + aOrbiterD);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 11U) + aOrbiterI) + RotL64(aOrbiterF, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 38U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererF);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererI);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + RotL64(aWandererH, 24U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordE);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 21647U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneB[((aIndex + 19946U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 21376U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 18606U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCarry, 41U)) + (RotL64(aCross, 3U) ^ RotL64(aPrevious, 24U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterD = (aWandererD + RotL64(aPrevious, 37U)) + 10404808878585437255U;
            aOrbiterE = (aWandererK + RotL64(aCross, 14U)) + 10587858736301591439U;
            aOrbiterB = (aWandererC + RotL64(aIngress, 35U)) + 1430530909801644435U;
            aOrbiterI = (aWandererI + RotL64(aScatter, 41U)) + 9090938022430118902U;
            aOrbiterC = (((aWandererB + RotL64(aPrevious, 23U)) + 12936604311751121235U) + aPhaseFOrbiterAssignSaltB[((aIndex + 6U)) & S_SALT1]) + aNonceWordI;
            aOrbiterF = ((aWandererA + RotL64(aIngress, 5U)) + RotL64(aCarry, 47U)) + 1000583006020232032U;
            aOrbiterH = ((aWandererF + RotL64(aCross, 57U)) + RotL64(aCarry, 21U)) + 12352532088997042232U;
            aOrbiterA = ((aWandererG + RotL64(aScatter, 11U)) + 16723410947058502564U) + aPhaseFOrbiterAssignSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 43U)) + RotL64(aCarry, 13U)) + 16614089235313154270U;
            aOrbiterG = (aWandererH + RotL64(aIngress, 26U)) + 4245553025593349277U;
            aOrbiterJ = (aWandererE + RotL64(aScatter, 51U)) + 3353146318549477494U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 5935727336135635196U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 10312187090293319667U;
            aOrbiterB = RotL64((aOrbiterB * 1395964500396711899U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 12192843181244744484U) + aNonceWordO;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 2542570124502586365U;
            aOrbiterC = RotL64((aOrbiterC * 17222847847573534963U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 3315472769469002444U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 17512858811783071174U;
            aOrbiterF = RotL64((aOrbiterF * 9070400454074283765U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 16633218007427888082U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 2502077714838858460U;
            aOrbiterH = RotL64((aOrbiterH * 970762420815997725U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 14792910273226469214U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 15739513291150783151U;
            aOrbiterA = RotL64((aOrbiterA * 11896279674116906915U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 2192903544350345992U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 844428341223009295U;
            aOrbiterK = RotL64((aOrbiterK * 4768368713974002539U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 2998511458298901402U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 7790789639864783373U;
            aOrbiterG = RotL64((aOrbiterG * 9173097618440495497U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 4540735375055164995U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 13700342877362633034U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14730797752841670505U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 16966725424259324323U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 5945539295893015935U) ^ aNonceWordL;
            aOrbiterD = RotL64((aOrbiterD * 12226268057062268981U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 12560355243513521281U) + aNonceWordB;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 2104086086480258265U;
            aOrbiterE = RotL64((aOrbiterE * 17989755118752755577U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 4476697099257280568U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 10404808878585437255U;
            aOrbiterI = RotL64((aOrbiterI * 6245415417832089357U), 53U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 23U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 19U));
            aIngress = aIngress + (RotL64(aOrbiterH, 56U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterF, 11U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterE, 47U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterD, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aIngress, 51U) + RotL64(aOrbiterA, 41U)) + aOrbiterE) + RotL64(aCarry, 53U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 35U) + aOrbiterK) + RotL64(aOrbiterI, 13U));
            aWandererK = aWandererK + ((RotL64(aCross, 23U) + aOrbiterF) + RotL64(aOrbiterK, 50U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 18U) + RotL64(aOrbiterJ, 39U)) + aOrbiterC) + aNonceWordN);
            aWandererE = aWandererE + (((RotL64(aScatter, 43U) + RotL64(aOrbiterD, 21U)) + aOrbiterC) + RotL64(aCarry, 5U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 3U) + aOrbiterF) + RotL64(aOrbiterE, 37U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aCross, 5U) + aOrbiterH) + RotL64(aOrbiterG, 43U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 29U) + aOrbiterF) + RotL64(aOrbiterG, 57U)) + aNonceWordP);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 41U) + aOrbiterH) + RotL64(aOrbiterD, 10U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 26U) + aOrbiterI) + RotL64(aOrbiterB, 53U)) + aPhaseFWandererUpdateSaltE[((aIndex + 26U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aCross, 11U) + aOrbiterH) + RotL64(aOrbiterI, 3U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + (RotL64(aWandererK, 58U) ^ aWandererE);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 11U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + RotL64(aWandererJ, 6U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ aNonceWordI;
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 23903U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneA[((aIndex + 25599U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 22085U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneA[((aIndex + 23767U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 11U) ^ RotL64(aIngress, 50U)) + (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 35U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterI = (aWandererE + RotL64(aScatter, 27U)) + 3973833383430652211U;
            aOrbiterE = (aWandererK + RotL64(aPrevious, 3U)) + 5760227042747169187U;
            aOrbiterJ = ((aWandererG + RotL64(aIngress, 56U)) + RotL64(aCarry, 53U)) + 4923009065139227286U;
            aOrbiterA = ((aWandererJ + RotL64(aCross, 37U)) + RotL64(aCarry, 3U)) + 1477807307009107590U;
            aOrbiterF = ((aWandererA + RotL64(aScatter, 11U)) + 5707194514329007301U) + aPhaseFOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = (aWandererB + RotL64(aCross, 41U)) + 5340439728375269724U;
            aOrbiterC = ((aWandererD + RotL64(aIngress, 47U)) + 17080457898946572387U) + aNonceWordJ;
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 51U)) + RotL64(aCarry, 47U)) + 281559150259472813U;
            aOrbiterK = ((aWandererH + RotL64(aCross, 44U)) + 16160633048230910560U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = (aWandererI + RotL64(aPrevious, 35U)) + 9003989610509592121U;
            aOrbiterD = (aWandererF + RotL64(aIngress, 53U)) + 10579322462808454333U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 15059383289528723069U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 10417647757852880956U) ^ aNonceWordA;
            aOrbiterJ = RotL64((aOrbiterJ * 1457919230286043137U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 14484665027393813330U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 12344463053485837974U;
            aOrbiterB = RotL64((aOrbiterB * 5762654194001525041U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 5826453246659297805U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 12547902286376986223U;
            aOrbiterH = RotL64((aOrbiterH * 2982850000322672789U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 9637855144278126174U) + aNonceWordM;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 2132744427444501938U;
            aOrbiterG = RotL64((aOrbiterG * 5911587798564836199U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 9248933938130311231U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 13274297928717090383U;
            aOrbiterI = RotL64((aOrbiterI * 2901398809555237563U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 3690262236918560930U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 3626005326410800344U;
            aOrbiterA = RotL64((aOrbiterA * 13030443356669355355U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 10801089744186148218U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 5446653082176311031U;
            aOrbiterC = RotL64((aOrbiterC * 4594267575901248321U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 3205541585889107366U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 4532327942368884436U;
            aOrbiterK = RotL64((aOrbiterK * 16287094987689326229U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 9755333481079721632U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 722154154363571049U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11002432494248958957U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 8071668483354405205U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 8770466248803121315U) ^ aNonceWordF;
            aOrbiterE = RotL64((aOrbiterE * 12780438190628717807U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 1999251593502332271U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 3973833383430652211U;
            aOrbiterF = RotL64((aOrbiterF * 5325244982474631559U), 19U);
            //
            aIngress = RotL64(aOrbiterB, 3U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 11U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 43U));
            aIngress = aIngress + (RotL64(aOrbiterK, 23U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 14U));
            aIngress = aIngress + RotL64(aOrbiterH, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 19U) + aOrbiterA) + RotL64(aOrbiterH, 23U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 52U) + aOrbiterH) + RotL64(aOrbiterD, 53U)) + RotL64(aCarry, 27U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterB, 19U)) + aOrbiterI) + aNonceWordB);
            aWandererH = aWandererH + ((RotL64(aCross, 3U) + RotL64(aOrbiterJ, 35U)) + aOrbiterI);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 41U) + aOrbiterJ) + RotL64(aOrbiterK, 46U));
            aWandererF = aWandererF + ((RotL64(aScatter, 29U) + aOrbiterK) + RotL64(aOrbiterC, 39U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 43U) + aOrbiterG) + RotL64(aOrbiterH, 21U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 11U) + aOrbiterF) + RotL64(aOrbiterC, 5U)) + RotL64(aCarry, 43U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 50U) + aOrbiterF) + RotL64(aOrbiterE, 44U)) + aPhaseFWandererUpdateSaltD[((aIndex + 4U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 57U) + RotL64(aOrbiterE, 51U)) + aOrbiterI) + aNonceWordD);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 27U) + aOrbiterD) + RotL64(aOrbiterA, 3U)) + aPhaseFWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererJ);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 48U));
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererD);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 21U));
            aCarry = aCarry + RotL64(aWandererA, 46U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 28835U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((aIndex + 31829U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28857U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29148U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 42U) + RotL64(aCarry, 29U)) + (RotL64(aIngress, 57U) ^ RotL64(aCross, 13U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterH = ((aWandererF + RotL64(aCross, 13U)) + 4384716820085860551U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterK = (aWandererI + RotL64(aPrevious, 23U)) + 9715780315942116888U;
            aOrbiterD = ((aWandererA + RotL64(aScatter, 44U)) + RotL64(aCarry, 23U)) + 15963520052789178632U;
            aOrbiterB = ((aWandererJ + RotL64(aIngress, 21U)) + 14346700690686392938U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = ((aWandererH + RotL64(aCross, 5U)) + 6005518012489966643U) + aNonceWordN;
            aOrbiterE = ((aWandererE + RotL64(aIngress, 11U)) + RotL64(aCarry, 5U)) + 2506732930310252119U;
            aOrbiterA = (aWandererC + RotL64(aPrevious, 35U)) + 16782163084851775826U;
            aOrbiterJ = (aWandererB + RotL64(aScatter, 51U)) + 823673076571076303U;
            aOrbiterG = ((aWandererG + RotL64(aCross, 37U)) + RotL64(aCarry, 53U)) + 1634084509064077736U;
            aOrbiterF = ((aWandererD + RotL64(aScatter, 56U)) + 1288134975466877686U) + aNonceWordG;
            aOrbiterC = ((aWandererK + RotL64(aIngress, 39U)) + 2998220403162908444U) + aNonceWordK;
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 220430672180734911U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 10223923547068528867U;
            aOrbiterD = RotL64((aOrbiterD * 12577370238343872139U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 11696469696177647608U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 6545430420379636963U;
            aOrbiterI = RotL64((aOrbiterI * 8387163146257553773U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 79691451831797107U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 8971444023498649419U;
            aOrbiterE = RotL64((aOrbiterE * 7148919880477390009U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 5624403902454498793U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 9468064161002030997U;
            aOrbiterA = RotL64((aOrbiterA * 8243560528100864595U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 4619361544913629805U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 12682446273369750704U) ^ aNonceWordB;
            aOrbiterJ = RotL64((aOrbiterJ * 10879074713156075641U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 8728730962617599223U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 9099675924074253030U;
            aOrbiterG = RotL64((aOrbiterG * 5525644236954497523U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 3298303921318288541U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 5953276499411658358U;
            aOrbiterF = RotL64((aOrbiterF * 10565471305001292693U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 6725769507592688539U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 1057277456510215817U;
            aOrbiterC = RotL64((aOrbiterC * 8269412198279297075U), 19U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterF) + 11317925732206917722U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordA;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 17814749417006079067U;
            aOrbiterH = RotL64((aOrbiterH * 4369209051015735925U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 9258362135343403308U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 4873837345446960113U) ^ aNonceWordC;
            aOrbiterK = RotL64((aOrbiterK * 14223381466269503273U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 7863380865835889675U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 4384716820085860551U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2003891033298374621U), 51U);
            //
            aIngress = RotL64(aOrbiterK, 19U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 41U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 53U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 26U));
            aIngress = aIngress + (RotL64(aOrbiterB, 5U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterF, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aScatter, 47U) + RotL64(aOrbiterE, 19U)) + aOrbiterH) + aNonceWordO);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 21U) + aOrbiterI) + RotL64(aOrbiterD, 37U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterA, 23U)) + aOrbiterB);
            aWandererI = aWandererI ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterF, 13U)) + aOrbiterE);
            aWandererD = aWandererD + ((RotL64(aScatter, 29U) + aOrbiterB) + RotL64(aOrbiterK, 4U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 54U) + aOrbiterI) + RotL64(aOrbiterF, 41U));
            aWandererG = aWandererG + (((RotL64(aIngress, 43U) + aOrbiterH) + RotL64(aOrbiterJ, 43U)) + RotL64(aCarry, 57U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 13U) + aOrbiterC) + RotL64(aOrbiterB, 27U));
            aWandererB = aWandererB + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterD, 29U)) + aOrbiterC) + aNonceWordP) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 34U) + RotL64(aOrbiterG, 60U)) + aOrbiterA);
            aWandererJ = aWandererJ + (((RotL64(aCross, 19U) + RotL64(aOrbiterB, 21U)) + aOrbiterJ) + RotL64(aCarry, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 27U) ^ aWandererK);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 39U));
            aCarry = aCarry + (RotL64(aWandererD, 10U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererJ, 37U);
            aCarry = aCarry + RotL64(aIngress, 6U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordI);
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

void TwistExpander_Bowling_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 3192U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 5498U)) & W_KEY1], 24U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 4439U)) & W_KEY1], 54U) ^ RotL64(mSource[((aIndex + 1987U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 6U) + RotL64(aPrevious, 39U)) ^ (RotL64(aIngress, 21U) + RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = (aWandererB + RotL64(aScatter, 58U)) + 2974056819475622600U;
            aOrbiterA = ((aWandererK + RotL64(aCross, 23U)) + RotL64(aCarry, 3U)) + 7345051759236356098U;
            aOrbiterJ = (aWandererA + RotL64(aPrevious, 37U)) + 12738468816846628882U;
            aOrbiterI = (aWandererF + RotL64(aIngress, 13U)) + 7694520596043297922U;
            aOrbiterD = ((aWandererI + RotL64(aScatter, 53U)) + 5530753590015084774U) + aPhaseCOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = (aWandererC + RotL64(aCross, 5U)) + 3776309161718383105U;
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 19U)) + 784780304358106404U) + aPhaseCOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = ((aWandererJ + RotL64(aIngress, 42U)) + RotL64(aCarry, 35U)) + 8999942326995036509U;
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 47U)) + RotL64(aCarry, 27U)) + 5194986506064092779U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 7920040007459652762U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 11311997270710107937U;
            aOrbiterJ = RotL64((aOrbiterJ * 6227571709361790209U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 5365231114813547251U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 8630110234623825263U;
            aOrbiterF = RotL64((aOrbiterF * 2735881715888325759U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 2358235238039571072U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 18059414891616491807U;
            aOrbiterB = RotL64((aOrbiterB * 17150786106857185467U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 14526050556461782864U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 6937282036603272474U;
            aOrbiterE = RotL64((aOrbiterE * 14954512365270028029U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 10105832250694931310U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 3884223553012098137U;
            aOrbiterC = RotL64((aOrbiterC * 16340956813003906195U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 10385284339549648087U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 1257633893341505930U;
            aOrbiterI = RotL64((aOrbiterI * 2669950791270500977U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 5528890519572824318U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 15664241747527713256U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16670884497088220497U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 14264122979415331887U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 17985061405540198036U;
            aOrbiterA = RotL64((aOrbiterA * 2729487440173395133U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 1663986734997903415U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 3706166884286400587U;
            aOrbiterD = RotL64((aOrbiterD * 10549736618301955745U), 21U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterF, 41U);
            aIngress = aIngress + (RotL64(aOrbiterC, 21U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterJ, 14U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + RotL64(aOrbiterK, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aIngress, 28U) + RotL64(aOrbiterK, 47U)) + aOrbiterJ) + aPhaseCWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 51U) + aOrbiterB) + RotL64(aOrbiterK, 13U)) + RotL64(aCarry, 37U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterK, 60U)) + aOrbiterI);
            aWandererC = aWandererC + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterF, 41U)) + aOrbiterA) + RotL64(aCarry, 57U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 18U) + aOrbiterI) + RotL64(aOrbiterD, 51U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 47U) + aOrbiterD) + RotL64(aOrbiterE, 23U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 35U) + aOrbiterC) + RotL64(aOrbiterF, 35U));
            aWandererB = aWandererB + ((RotL64(aIngress, 43U) + aOrbiterC) + RotL64(aOrbiterE, 28U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 39U) + aOrbiterF) + RotL64(aOrbiterI, 19U)) + aPhaseCWandererUpdateSaltF[((aIndex + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 18U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererI, 50U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 13759U)) & S_BLOCK1], 37U) ^ RotL64(mSource[((aIndex + 16361U)) & S_BLOCK1], 26U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15178U)) & W_KEY1], 20U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 11396U)) & W_KEY1], 39U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 51U) + RotL64(aCross, 4U)) ^ (RotL64(aPrevious, 21U) + RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = ((aWandererF + RotL64(aScatter, 23U)) + RotL64(aCarry, 41U)) + 17225673071833726819U;
            aOrbiterA = (aWandererA + RotL64(aPrevious, 51U)) + 10301458382103627331U;
            aOrbiterI = ((aWandererG + RotL64(aCross, 46U)) + 3960233050857362414U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = ((aWandererB + RotL64(aIngress, 19U)) + RotL64(aCarry, 29U)) + 17768665685046605837U;
            aOrbiterB = (aWandererI + RotL64(aPrevious, 37U)) + 14471018461213959767U;
            aOrbiterC = (aWandererD + RotL64(aIngress, 29U)) + 10730597892721340453U;
            aOrbiterK = (aWandererE + RotL64(aCross, 57U)) + 14863394003122760542U;
            aOrbiterF = (aWandererK + RotL64(aScatter, 12U)) + 9948587274816688296U;
            aOrbiterE = (((aWandererH + RotL64(aPrevious, 5U)) + RotL64(aCarry, 11U)) + 3573569431435100993U) + aPhaseCOrbiterAssignSaltB[((aIndex + 6U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 8153670675740450590U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 16438856577722561424U;
            aOrbiterI = RotL64((aOrbiterI * 4689247488336908827U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 15765587867581925041U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 1082039522061775213U;
            aOrbiterB = RotL64((aOrbiterB * 17023740047246402641U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 4202521649260798876U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 15877659681260461141U;
            aOrbiterK = RotL64((aOrbiterK * 11369910758551088173U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 2551560426129646123U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 3005102326163906320U;
            aOrbiterF = RotL64((aOrbiterF * 4241583192662435107U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 1675501058857208089U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 12774812270956702043U;
            aOrbiterE = RotL64((aOrbiterE * 5488437008504905105U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 1044886020922563597U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 4857445127457225171U;
            aOrbiterH = RotL64((aOrbiterH * 13223560654459705259U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 11548725551787560962U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 2434677823189765161U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4283026044563670969U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 9606875320524736294U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 13732615866277657704U;
            aOrbiterC = RotL64((aOrbiterC * 3905528919281629775U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 13921743663803299567U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 13350829301153929899U;
            aOrbiterA = RotL64((aOrbiterA * 11858642286713079795U), 23U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterI, 42U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 39U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 35U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 21U));
            aIngress = aIngress + RotL64(aOrbiterC, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 19U) + aOrbiterF) + RotL64(aOrbiterC, 23U));
            aWandererD = aWandererD + ((RotL64(aScatter, 60U) + aOrbiterE) + RotL64(aOrbiterA, 35U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterI, 5U)) + aOrbiterH);
            aWandererF = aWandererF + (((RotL64(aCross, 51U) + aOrbiterK) + RotL64(aOrbiterI, 19U)) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 37U) + aOrbiterF) + RotL64(aOrbiterG, 56U));
            aWandererI = aWandererI + ((((RotL64(aCross, 56U) + aOrbiterK) + RotL64(aOrbiterF, 27U)) + RotL64(aCarry, 53U)) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterG, 13U)) + aOrbiterB);
            aWandererB = aWandererB + (((RotL64(aScatter, 11U) + RotL64(aOrbiterK, 51U)) + aOrbiterC) + RotL64(aCarry, 13U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 5U) + aOrbiterI) + RotL64(aOrbiterE, 40U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererK, 60U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererA, 35U);
            aCarry = aCarry + RotL64(aIngress, 6U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 16859U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((aIndex + 17088U)) & S_BLOCK1], 26U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 22760U)) & W_KEY1], 24U) ^ RotL64(aKeyRowReadB[((aIndex + 18052U)) & W_KEY1], 11U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 18U) + RotL64(aCross, 35U)) ^ (RotL64(aIngress, 53U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = ((aWandererB + RotL64(aScatter, 35U)) + RotL64(aCarry, 47U)) + 9446153639709651566U;
            aOrbiterH = ((aWandererC + RotL64(aIngress, 47U)) + 10550762260670758167U) + aPhaseCOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = (aWandererH + RotL64(aPrevious, 58U)) + 7062634922142578383U;
            aOrbiterF = (aWandererJ + RotL64(aCross, 19U)) + 9178499097812764515U;
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 13U)) + RotL64(aCarry, 11U)) + 6887103379773525538U;
            aOrbiterG = (aWandererE + RotL64(aCross, 43U)) + 6239750312052010257U;
            aOrbiterB = (aWandererK + RotL64(aScatter, 30U)) + 17645022614523287959U;
            aOrbiterA = (((aWandererF + RotL64(aIngress, 51U)) + RotL64(aCarry, 3U)) + 3639618183259408272U) + aPhaseCOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = (aWandererI + RotL64(aScatter, 3U)) + 3131737117548745095U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 7253994382396406554U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 15217993711938379561U;
            aOrbiterE = RotL64((aOrbiterE * 17853313384747259923U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 12594152227603630033U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 11250170200489647869U;
            aOrbiterK = RotL64((aOrbiterK * 546800378327864723U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 12936942656624279424U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 10990736056052106149U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7123916809953459187U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 12787293075893090465U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 17154990205620778151U;
            aOrbiterH = RotL64((aOrbiterH * 10031369940028159521U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 1270827262969060301U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 17337623431665013136U;
            aOrbiterD = RotL64((aOrbiterD * 1517262088236356107U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 830330490987911853U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 6828309232554560547U;
            aOrbiterG = RotL64((aOrbiterG * 9742464176986145819U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 11470087853413986203U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 10470148870747884420U;
            aOrbiterB = RotL64((aOrbiterB * 6766079738799967443U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 18315536891901859637U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 12264670822285914271U;
            aOrbiterA = RotL64((aOrbiterA * 5841574505408674119U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 10931842095884524879U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 11134871340959676257U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11714837622285605745U), 13U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterK, 13U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 27U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 54U));
            aIngress = aIngress + RotL64(aOrbiterF, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterC, 3U)) + aOrbiterA) + aPhaseCWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 29U) + RotL64(aOrbiterF, 56U)) + aOrbiterH);
            aWandererG = aWandererG ^ ((RotL64(aCross, 47U) + aOrbiterA) + RotL64(aOrbiterB, 51U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterC, 41U)) + aOrbiterF) + RotL64(aCarry, 11U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 6U) + RotL64(aOrbiterG, 27U)) + aOrbiterD);
            aWandererC = aWandererC + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterG, 35U)) + aOrbiterC) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 19U) + aOrbiterF) + RotL64(aOrbiterG, 19U));
            aWandererB = aWandererB + (((RotL64(aScatter, 37U) + aOrbiterE) + RotL64(aOrbiterC, 47U)) + RotL64(aCarry, 29U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 52U) + RotL64(aOrbiterK, 12U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + (RotL64(aWandererG, 54U) ^ aWandererK);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + RotL64(aWandererF, 11U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 24929U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 24802U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27374U)) & S_BLOCK1], 48U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 25628U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCarry, 54U)) ^ (RotL64(aCross, 37U) ^ RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = ((aWandererD + RotL64(aCross, 29U)) + 16462052553719977502U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = ((aWandererA + RotL64(aIngress, 10U)) + RotL64(aCarry, 5U)) + 12337064059566619581U;
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 21U)) + RotL64(aCarry, 53U)) + 15801005007094515447U;
            aOrbiterF = ((aWandererG + RotL64(aScatter, 51U)) + RotL64(aCarry, 13U)) + 8228706742665081656U;
            aOrbiterH = (aWandererH + RotL64(aPrevious, 37U)) + 11006723027845190869U;
            aOrbiterA = (aWandererF + RotL64(aScatter, 47U)) + 18173765337829177450U;
            aOrbiterJ = ((aWandererI + RotL64(aCross, 42U)) + 530215083653542558U) + aPhaseCOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = (aWandererJ + RotL64(aIngress, 5U)) + 6608611827035564511U;
            aOrbiterD = (aWandererB + RotL64(aCross, 57U)) + 2246051826221626809U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 5228575308895381421U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 10999213210689606857U;
            aOrbiterI = RotL64((aOrbiterI * 5467601259546342925U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 3773371037240485696U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 8887985779436152504U;
            aOrbiterH = RotL64((aOrbiterH * 698713082830739677U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 11150566414723818350U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 8336366151003049546U;
            aOrbiterJ = RotL64((aOrbiterJ * 9033771197242493699U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 13233968794237090787U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 8172558473508478819U;
            aOrbiterG = RotL64((aOrbiterG * 17837070423649268435U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 133564480283347997U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 15104810248883567064U;
            aOrbiterF = RotL64((aOrbiterF * 706802420642303533U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 9138629520201127075U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 13993086066341664080U;
            aOrbiterA = RotL64((aOrbiterA * 4875046427147105077U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 6547273508580516932U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 9838727018769865759U;
            aOrbiterE = RotL64((aOrbiterE * 11395273371936839815U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 11685694999526122626U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 8945983172566303116U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17791527981004597623U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 17606249889617356327U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 9296903152000480008U;
            aOrbiterK = RotL64((aOrbiterK * 18066622289408024413U), 43U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterA, 43U);
            aIngress = aIngress + (RotL64(aOrbiterI, 26U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 21U));
            aIngress = aIngress + RotL64(aOrbiterE, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aCross, 24U) + aOrbiterF) + RotL64(aOrbiterH, 41U)) + aPhaseCWandererUpdateSaltC[((aIndex + 14U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 53U) + aOrbiterF) + RotL64(aOrbiterK, 56U)) + RotL64(aCarry, 21U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterD, 27U)) + aOrbiterJ);
            aWandererI = aWandererI + ((RotL64(aIngress, 43U) + RotL64(aOrbiterJ, 23U)) + aOrbiterE);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterG, 35U)) + aOrbiterJ);
            aWandererF = aWandererF + (((RotL64(aIngress, 28U) + RotL64(aOrbiterD, 6U)) + aOrbiterF) + RotL64(aCarry, 57U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterI, 11U)) + aOrbiterE) + aPhaseCWandererUpdateSaltF[((aIndex + 16U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aPrevious, 3U) + aOrbiterI) + RotL64(aOrbiterA, 51U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 35U) + aOrbiterF) + RotL64(aOrbiterG, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererI, 10U) ^ aWandererH);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 5U));
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererJ, 41U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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

void TwistExpander_Bowling_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0;
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 1273U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneC[((aIndex + 616U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 6703U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 8163U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 27U) + RotL64(aCross, 57U)) ^ (RotL64(aCarry, 6U) + RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = ((aWandererC + RotL64(aScatter, 23U)) + RotL64(aCarry, 41U)) + 5480870806135400132U;
            aOrbiterD = (((aWandererH + RotL64(aPrevious, 14U)) + RotL64(aCarry, 27U)) + 8034874599430768743U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 37U)) + 4006919843736863767U;
            aOrbiterE = ((aWandererG + RotL64(aCross, 51U)) + RotL64(aCarry, 3U)) + 2988069748674633718U;
            aOrbiterA = ((aWandererK + RotL64(aIngress, 5U)) + 12347295651973135786U) + aPhaseDOrbiterAssignSaltA[((aIndex + 27U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 14152683894431568192U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 15765143815254196598U;
            aOrbiterJ = RotL64((aOrbiterJ * 8948877544291035189U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 10473067082331244233U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 1089466925383677249U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17334888609179149753U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 13215039929873682230U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 3957997712247961479U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7631186240013784703U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 10023907397941685546U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 14593012591254614353U;
            aOrbiterD = RotL64((aOrbiterD * 17111300092082154687U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 13353797968154036726U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 9259966668512102858U;
            aOrbiterA = RotL64((aOrbiterA * 8326732574268308221U), 43U);
            //
            aIngress = RotL64(aOrbiterA, 13U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterE, 23U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterI, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterE, 57U)) + aOrbiterD) + aPhaseDWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterA, 12U)) + aOrbiterJ) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 37U) + aOrbiterE) + RotL64(aOrbiterI, 23U)) + RotL64(aCarry, 29U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 54U) + RotL64(aOrbiterD, 3U)) + aOrbiterA);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 19U) + RotL64(aOrbiterI, 35U)) + aOrbiterA) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 10U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + RotL64(aWandererG, 29U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 13144U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 9366U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 14545U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((aIndex + 10112U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 43U) + RotL64(aCarry, 57U)) + (RotL64(aCross, 30U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = (aWandererF + RotL64(aPrevious, 48U)) + 6654158889644956636U;
            aOrbiterC = (((aWandererH + RotL64(aScatter, 39U)) + RotL64(aCarry, 23U)) + 9045779659363991870U) + aPhaseDOrbiterAssignSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterB = (aWandererD + RotL64(aIngress, 23U)) + 3888897662136993491U;
            aOrbiterK = ((aWandererG + RotL64(aCross, 13U)) + RotL64(aCarry, 53U)) + 6882016842864459345U;
            aOrbiterE = (((aWandererI + RotL64(aPrevious, 57U)) + RotL64(aCarry, 39U)) + 15601891715956172291U) + aPhaseDOrbiterAssignSaltC[((aIndex + 6U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 5176811598629335350U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 12519945150889074325U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8721098129033306427U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 4552583214397603278U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 14225482701804864688U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8526052833180466359U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 5485298070606280363U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 11237713257388094289U;
            aOrbiterG = RotL64((aOrbiterG * 11032429223099413011U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 14340345895626142788U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 16275167270553643347U;
            aOrbiterC = RotL64((aOrbiterC * 7308578867128951199U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 14041860597556520250U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 1436068974197066343U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3938460345031496843U), 35U);
            //
            aIngress = RotL64(aOrbiterE, 47U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 6U));
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterK, 51U)) + aOrbiterC) + RotL64(aCarry, 23U)) + aPhaseDWandererUpdateSaltA[((aIndex + 18U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 21U) + aOrbiterE) + RotL64(aOrbiterB, 13U));
            aWandererF = aWandererF + (((RotL64(aCross, 13U) + aOrbiterG) + RotL64(aOrbiterE, 5U)) + RotL64(aCarry, 57U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 56U) + RotL64(aOrbiterG, 41U)) + aOrbiterK) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aIngress, 43U) + aOrbiterC) + RotL64(aOrbiterG, 26U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererG, 37U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 21174U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 20939U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18207U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 20694U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 41U) + RotL64(aPrevious, 13U)) ^ (RotL64(aIngress, 27U) ^ RotL64(aCross, 58U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = ((aWandererA + RotL64(aScatter, 19U)) + RotL64(aCarry, 53U)) + 2177539223979303669U;
            aOrbiterD = ((aWandererK + RotL64(aIngress, 5U)) + 3962004686551521471U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = ((aWandererG + RotL64(aCross, 57U)) + 8457602312617147662U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 43U)) + RotL64(aCarry, 3U)) + 18011802451816510632U;
            aOrbiterG = ((aWandererC + RotL64(aIngress, 28U)) + RotL64(aCarry, 21U)) + 9046101759168876832U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 11135620637431969597U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 15913029940697999701U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 646524659942693491U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 16304193109948135982U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 13208892298820080981U;
            aOrbiterD = RotL64((aOrbiterD * 15093751072618884859U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 4182377898949419225U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 13970137023071326151U;
            aOrbiterA = RotL64((aOrbiterA * 9075061559681739865U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 8402396284835248583U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 8859190834060657829U;
            aOrbiterK = RotL64((aOrbiterK * 13552418608113716117U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 9760005337757990392U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 14108277760135744897U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4474681104256093885U), 21U);
            //
            aIngress = RotL64(aOrbiterI, 56U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + RotL64(aOrbiterG, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aCross, 35U) + aOrbiterK) + RotL64(aOrbiterG, 5U)) + RotL64(aCarry, 39U)) + aPhaseDWandererUpdateSaltF[((aIndex + 4U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 11U) + aOrbiterK) + RotL64(aOrbiterA, 29U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 51U) + RotL64(aOrbiterG, 52U)) + aOrbiterI) + RotL64(aCarry, 13U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterD, 21U)) + aOrbiterA) + aPhaseDWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aCross, 26U) + aOrbiterG) + RotL64(aOrbiterA, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 26U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererC, 53U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 26710U)) & S_BLOCK1], 54U) ^ RotL64(aOperationLaneB[((aIndex + 30141U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 26065U)) & S_BLOCK1], 40U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 29882U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 11U)) ^ (RotL64(aIngress, 28U) + RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = ((aWandererI + RotL64(aCross, 43U)) + 10404808878585437255U) + aPhaseDOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = ((aWandererF + RotL64(aIngress, 5U)) + RotL64(aCarry, 57U)) + 10587858736301591439U;
            aOrbiterC = ((aWandererB + RotL64(aScatter, 18U)) + RotL64(aCarry, 37U)) + 1430530909801644435U;
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 29U)) + 9090938022430118902U) + aPhaseDOrbiterAssignSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = ((aWandererD + RotL64(aCross, 51U)) + RotL64(aCarry, 21U)) + 12936604311751121235U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 1000583006020232032U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 12352532088997042232U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 494418029883239087U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 16723410947058502564U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 16614089235313154270U;
            aOrbiterB = RotL64((aOrbiterB * 11530998303573027827U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 4245553025593349277U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 3353146318549477494U;
            aOrbiterE = RotL64((aOrbiterE * 14246377408238318091U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 5935727336135635196U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 10312187090293319667U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1395964500396711899U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 12192843181244744484U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 2542570124502586365U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17222847847573534963U), 57U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterC, 51U);
            aIngress = aIngress + (RotL64(aOrbiterI, 40U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterE, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterC, 29U)) + aOrbiterI);
            aWandererA = aWandererA + (((RotL64(aIngress, 3U) + RotL64(aOrbiterI, 11U)) + aOrbiterB) + RotL64(aCarry, 39U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterJ, 3U)) + aOrbiterB);
            aWandererI = aWandererI + ((((RotL64(aScatter, 41U) + aOrbiterE) + RotL64(aOrbiterB, 41U)) + RotL64(aCarry, 27U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 58U) + RotL64(aOrbiterE, 54U)) + aOrbiterC) + aPhaseDWandererUpdateSaltE[((aIndex + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + (RotL64(aWandererB, 60U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererA, 29U);
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

void TwistExpander_Bowling_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 7153U)) & S_BLOCK1], 6U) ^ RotL64(aOperationLaneC[((aIndex + 51U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 6099U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 13U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 11U) ^ RotL64(aCarry, 39U)) ^ (RotL64(aCross, 52U) + RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = ((aWandererG + RotL64(aCross, 29U)) + RotL64(aCarry, 13U)) + 6318740973868639425U;
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 23U)) + 5487840061430920881U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = (aWandererK + RotL64(aScatter, 48U)) + 10258706763248072672U;
            aOrbiterD = ((aWandererE + RotL64(aIngress, 5U)) + RotL64(aCarry, 51U)) + 18356875269730338208U;
            aOrbiterH = ((aWandererB + RotL64(aScatter, 11U)) + RotL64(aCarry, 35U)) + 12883160282903147010U;
            aOrbiterI = ((aWandererC + RotL64(aCross, 57U)) + 1010140474942697730U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = (aWandererA + RotL64(aIngress, 39U)) + 17733939421700898293U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 13693055887924981201U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 14574732452793385269U;
            aOrbiterG = RotL64((aOrbiterG * 9373765929885750185U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 10832873941223609012U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 8212600587135328040U;
            aOrbiterH = RotL64((aOrbiterH * 5334613996794796145U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 5312744319781971178U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 6173741211706546923U;
            aOrbiterI = RotL64((aOrbiterI * 12854414066390848249U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 3693249147883790810U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 18365859989736602556U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3348463719324104997U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 10645056678337549771U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 1175668356822251045U;
            aOrbiterA = RotL64((aOrbiterA * 6579675292775345579U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 13556844570541823717U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 4790355739411849736U;
            aOrbiterD = RotL64((aOrbiterD * 4083544011788850307U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 14905575502272644116U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 17047244574558476634U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2356386971503880047U), 35U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterH, 21U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 58U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 13U));
            aIngress = aIngress + RotL64(aOrbiterA, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 5U) + aOrbiterG) + RotL64(aOrbiterA, 19U));
            aWandererI = aWandererI + (((RotL64(aIngress, 47U) + RotL64(aOrbiterD, 29U)) + aOrbiterF) + aPhaseEWandererUpdateSaltE[((aIndex + 28U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterD, 47U)) + aOrbiterH);
            aWandererC = aWandererC + (((RotL64(aCross, 20U) + RotL64(aOrbiterG, 5U)) + aOrbiterD) + RotL64(aCarry, 29U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 41U) + aOrbiterF) + RotL64(aOrbiterB, 39U)) + aPhaseEWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 13U) + aOrbiterA) + RotL64(aOrbiterI, 57U)) + RotL64(aCarry, 5U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterH, 12U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 14U));
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererG, 43U);
            aCarry = aCarry + RotL64(aIngress, 34U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 11285U)) & S_BLOCK1], 50U) ^ RotL64(aOperationLaneD[((aIndex + 11265U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 14120U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 12265U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 51U) + RotL64(aCarry, 39U)) ^ (RotL64(aCross, 5U) + RotL64(aIngress, 18U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 41U)) + 10805654776556844351U) + aPhaseEOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 23U)) + RotL64(aCarry, 11U)) + 582794182442795335U;
            aOrbiterF = (aWandererK + RotL64(aCross, 11U)) + 2858343650974681068U;
            aOrbiterA = ((aWandererI + RotL64(aIngress, 51U)) + RotL64(aCarry, 39U)) + 8189584049022064284U;
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 4U)) + 1565100751996962893U) + aPhaseEOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = ((aWandererE + RotL64(aScatter, 57U)) + RotL64(aCarry, 27U)) + 8062028016947611891U;
            aOrbiterG = (aWandererC + RotL64(aCross, 29U)) + 8280504280578451745U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 11326869194491655350U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 1671695656567777163U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7511554500524257921U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 2349843105293943452U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 13015545152052004254U;
            aOrbiterJ = RotL64((aOrbiterJ * 1316662811685429983U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 16703354404749291869U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 8713231044374305801U;
            aOrbiterA = RotL64((aOrbiterA * 9242480982197688625U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 11118401674497783533U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 14857556493734710364U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3452566050389715195U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 12953419670951660965U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 12666121730825089017U;
            aOrbiterE = RotL64((aOrbiterE * 14049925256934142519U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 11075249639473053423U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 9374217688244187867U;
            aOrbiterK = RotL64((aOrbiterK * 5261156325627117877U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 17608340953291367867U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 13159437499327086340U;
            aOrbiterG = RotL64((aOrbiterG * 4882100944453534805U), 37U);
            //
            aIngress = RotL64(aOrbiterJ, 57U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 51U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 14U));
            aIngress = aIngress + RotL64(aOrbiterA, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 29U) + aOrbiterG) + RotL64(aOrbiterF, 51U));
            aWandererG = aWandererG + (((RotL64(aIngress, 12U) + aOrbiterE) + RotL64(aOrbiterD, 36U)) + RotL64(aCarry, 47U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 21U) + aOrbiterK) + RotL64(aOrbiterG, 19U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 5U) + aOrbiterA) + RotL64(aOrbiterF, 29U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterK, 5U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 43U) + RotL64(aOrbiterE, 11U)) + aOrbiterK) + RotL64(aCarry, 29U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 35U) + aOrbiterJ) + RotL64(aOrbiterF, 43U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 42U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 53U));
            aCarry = aCarry + RotL64(aWandererE, 23U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 24292U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16556U)) & S_BLOCK1], 44U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 18453U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneC[((aIndex + 17456U)) & S_BLOCK1], 36U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aIngress, 23U)) ^ (RotL64(aPrevious, 4U) + RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = (aWandererJ + RotL64(aIngress, 13U)) + 3970829908171131502U;
            aOrbiterE = (aWandererH + RotL64(aPrevious, 21U)) + 7040283759419531991U;
            aOrbiterA = ((aWandererI + RotL64(aScatter, 5U)) + 11856292169397052901U) + aPhaseEOrbiterAssignSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterG = ((aWandererD + RotL64(aCross, 35U)) + RotL64(aCarry, 3U)) + 819598588791819022U;
            aOrbiterF = (aWandererB + RotL64(aScatter, 51U)) + 2176451710970866848U;
            aOrbiterH = (((aWandererF + RotL64(aIngress, 42U)) + RotL64(aCarry, 47U)) + 6454704928613390494U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 27U)) + RotL64(aCarry, 27U)) + 11792122387218053841U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 9254780213489752211U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 16591812589999846482U;
            aOrbiterA = RotL64((aOrbiterA * 5425771603523423167U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 1471246223935074832U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 1424843083106386453U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15020536982657410783U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 1856469958050891629U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 6331743690452052712U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15327924647897459645U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 10351075711345476487U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 9518585245330480185U;
            aOrbiterG = RotL64((aOrbiterG * 3792179827396760391U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 17787514620244712033U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 14182328067398162557U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 18107337388659070197U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 12798088948801072444U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 9563215159275202323U;
            aOrbiterH = RotL64((aOrbiterH * 7058145016617349141U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 9904919772580498232U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 16579777394992143043U;
            aOrbiterI = RotL64((aOrbiterI * 10516761340320196661U), 3U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterI, 19U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 51U));
            aIngress = aIngress + (RotL64(aOrbiterH, 29U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterK, 12U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterG, 60U)) + aOrbiterK);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 57U) + aOrbiterG) + RotL64(aOrbiterH, 3U)) + RotL64(aCarry, 3U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 27U) + aOrbiterI) + RotL64(aOrbiterH, 27U));
            aWandererH = aWandererH + ((RotL64(aIngress, 19U) + aOrbiterF) + RotL64(aOrbiterH, 21U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 43U) + aOrbiterK) + RotL64(aOrbiterE, 53U));
            aWandererE = aWandererE + ((((RotL64(aScatter, 51U) + aOrbiterG) + RotL64(aOrbiterF, 11U)) + RotL64(aCarry, 43U)) + aPhaseEWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 36U) + RotL64(aOrbiterG, 35U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 20U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 51U));
            aCarry = aCarry + RotL64(aWandererF, 5U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 30582U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28347U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 28311U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 30715U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aIngress, 41U)) + (RotL64(aPrevious, 58U) ^ RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 23U)) + RotL64(aCarry, 3U)) + 3248574644570178787U;
            aOrbiterC = (aWandererG + RotL64(aCross, 51U)) + 4506961512959200024U;
            aOrbiterK = (((aWandererB + RotL64(aPrevious, 43U)) + RotL64(aCarry, 41U)) + 8423739774540738590U) + aPhaseEOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = ((aWandererE + RotL64(aScatter, 11U)) + RotL64(aCarry, 19U)) + 6593975869641735337U;
            aOrbiterG = (aWandererF + RotL64(aPrevious, 58U)) + 16441716090557369103U;
            aOrbiterE = (aWandererK + RotL64(aCross, 29U)) + 7936601450453207914U;
            aOrbiterD = ((aWandererD + RotL64(aIngress, 3U)) + 13333752583560167065U) + aPhaseEOrbiterAssignSaltD[((aIndex + 14U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 8013703284795432973U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 2349852779887439236U;
            aOrbiterK = RotL64((aOrbiterK * 2422888500648100783U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 5318539364763284138U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 11450957608502944376U;
            aOrbiterE = RotL64((aOrbiterE * 1957880366707810635U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 9058992558327552687U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 632095686920230926U;
            aOrbiterC = RotL64((aOrbiterC * 12460364388358520799U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 14734218428913777098U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 16344357661370784442U;
            aOrbiterG = RotL64((aOrbiterG * 15049472842002138369U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 2981145363531184308U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 14176472085175714494U;
            aOrbiterH = RotL64((aOrbiterH * 2584623327412130939U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 11198457590069700889U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 952584436750426828U;
            aOrbiterF = RotL64((aOrbiterF * 1165713888651280355U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 4311591763498985972U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 16194341833989936369U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9997934560195932575U), 51U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterE, 19U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 5U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 35U));
            aIngress = aIngress + RotL64(aOrbiterD, 12U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aCross, 14U) + aOrbiterG) + RotL64(aOrbiterF, 43U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 53U) + aOrbiterE) + RotL64(aOrbiterD, 50U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 39U) + aOrbiterD) + RotL64(aOrbiterG, 3U)) + RotL64(aCarry, 41U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterK, 19U)) + aOrbiterF) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aIngress, 47U) + RotL64(aOrbiterF, 29U)) + aOrbiterE);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterC, 11U)) + aOrbiterD) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 21U) + aOrbiterK) + RotL64(aOrbiterH, 35U)) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 50U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererJ, 11U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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

void TwistExpander_Bowling_Arx::Twist_D(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 6971U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneC[((aIndex + 6562U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 1834U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 1700U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 51U) ^ RotL64(aCross, 4U)) ^ (RotL64(aCarry, 37U) + RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = ((aWandererA + RotL64(aIngress, 29U)) + 12632404972795375757U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = (aWandererF + RotL64(aScatter, 51U)) + 5351879979055988456U;
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 21U)) + RotL64(aCarry, 37U)) + 3597737727467443413U;
            aOrbiterF = ((aWandererK + RotL64(aCross, 39U)) + RotL64(aCarry, 51U)) + 2830846754917852318U;
            aOrbiterJ = (((aWandererD + RotL64(aIngress, 4U)) + RotL64(aCarry, 3U)) + 17311925960294518018U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 2083584640523695383U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 15049343611387010158U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5567816356477420399U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 6443050378205811147U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 6021965178697344070U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6054064448935006741U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 5080289878758029976U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 576927745306972983U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16008958833683246115U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 4728489691382690859U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 6184355840165758855U;
            aOrbiterE = RotL64((aOrbiterE * 1515043910404156423U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 11220539885798595450U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 11091438724966718214U;
            aOrbiterJ = RotL64((aOrbiterJ * 8225347114759391961U), 23U);
            //
            aIngress = RotL64(aOrbiterF, 57U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterE, 23U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 42U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterE, 35U)) + aOrbiterF);
            aWandererJ = aWandererJ + (((RotL64(aCross, 13U) + aOrbiterJ) + RotL64(aOrbiterH, 3U)) + RotL64(aCarry, 5U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 29U) + aOrbiterA) + RotL64(aOrbiterH, 46U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aScatter, 38U) + aOrbiterE) + RotL64(aOrbiterJ, 27U)) + RotL64(aCarry, 57U)) + aPhaseFWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterJ, 19U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 60U));
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererJ, 47U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 11328U)) & S_BLOCK1], 42U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 15503U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 13148U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 10789U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 35U) + RotL64(aIngress, 6U)) ^ (RotL64(aCarry, 21U) + RotL64(aPrevious, 47U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = ((aWandererI + RotL64(aIngress, 11U)) + RotL64(aCarry, 53U)) + 4980738603982643969U;
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 19U)) + RotL64(aCarry, 39U)) + 17660278413018470020U;
            aOrbiterI = ((aWandererK + RotL64(aScatter, 29U)) + 17598114429859543466U) + aPhaseFOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = (((aWandererD + RotL64(aCross, 44U)) + RotL64(aCarry, 23U)) + 10993929335279994739U) + aPhaseFOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = (aWandererF + RotL64(aPrevious, 3U)) + 17967203122976322481U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 1872290205549034384U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 16607778671782810797U;
            aOrbiterI = RotL64((aOrbiterI * 340054507611349681U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 4895226930754394376U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 14960359005982301383U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8546231310054433721U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 9921642352377700630U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 893281964367208693U;
            aOrbiterA = RotL64((aOrbiterA * 2345509157333444217U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 8232519988397858732U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 4433022122758913407U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 834240393225479419U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 12689609831247168353U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 404535388957472176U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14534020545479806593U), 5U);
            //
            aIngress = RotL64(aOrbiterC, 3U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 51U));
            aIngress = aIngress + RotL64(aOrbiterI, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 3U)) + aOrbiterC);
            aWandererK = aWandererK + (((RotL64(aCross, 30U) + aOrbiterI) + RotL64(aOrbiterH, 11U)) + RotL64(aCarry, 27U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 11U) + aOrbiterH) + RotL64(aOrbiterG, 44U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 57U) + aOrbiterA) + RotL64(aOrbiterC, 21U)) + RotL64(aCarry, 47U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 39U) + RotL64(aOrbiterA, 57U)) + aOrbiterH) + aPhaseFWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 24U));
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererI, 35U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 20999U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19686U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17463U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 16951U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 19U) ^ RotL64(aCross, 53U)) + (RotL64(aIngress, 3U) + RotL64(aCarry, 40U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 39U)) + 14008824488073394623U) + aPhaseFOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = (aWandererE + RotL64(aScatter, 5U)) + 13317978415866411468U;
            aOrbiterB = (((aWandererF + RotL64(aCross, 27U)) + RotL64(aCarry, 3U)) + 13209180141897453900U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = ((aWandererC + RotL64(aIngress, 48U)) + RotL64(aCarry, 23U)) + 11870521586865233578U;
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 13U)) + RotL64(aCarry, 43U)) + 8052156380448047385U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 12158131176743680605U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 14674467487607719347U;
            aOrbiterB = RotL64((aOrbiterB * 18372548574199176503U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 18055496790566231147U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 3838105585041578784U;
            aOrbiterD = RotL64((aOrbiterD * 1075709247574580091U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 2839568255183054418U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 11933612922864258179U;
            aOrbiterI = RotL64((aOrbiterI * 7571964469321160347U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 6289849094151630580U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 2640344350528492271U;
            aOrbiterE = RotL64((aOrbiterE * 16197726750829369365U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 16306175266267657791U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 3339898380394883600U;
            aOrbiterJ = RotL64((aOrbiterJ * 7105436590182982373U), 57U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterD, 29U);
            aIngress = aIngress + (RotL64(aOrbiterI, 19U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aCross, 57U) + aOrbiterE) + RotL64(aOrbiterB, 11U)) + RotL64(aCarry, 13U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterB, 26U)) + aOrbiterD);
            aWandererA = aWandererA + (((RotL64(aPrevious, 5U) + aOrbiterD) + RotL64(aOrbiterI, 3U)) + RotL64(aCarry, 47U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterB, 35U)) + aOrbiterJ);
            aWandererE = aWandererE + (((RotL64(aCross, 34U) + RotL64(aOrbiterJ, 51U)) + aOrbiterE) + aPhaseFWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + RotL64(aWandererC, 18U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 28966U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneB[((aIndex + 25930U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 28783U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 32519U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 27U) + RotL64(aCross, 5U)) ^ (RotL64(aCarry, 53U) + RotL64(aIngress, 40U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = (((aWandererD + RotL64(aPrevious, 5U)) + RotL64(aCarry, 19U)) + 10404808878585437255U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = (aWandererA + RotL64(aCross, 39U)) + 10587858736301591439U;
            aOrbiterH = (aWandererF + RotL64(aScatter, 21U)) + 1430530909801644435U;
            aOrbiterK = (((aWandererH + RotL64(aIngress, 58U)) + RotL64(aCarry, 3U)) + 9090938022430118902U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterC = ((aWandererE + RotL64(aScatter, 29U)) + RotL64(aCarry, 53U)) + 12936604311751121235U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 1000583006020232032U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 12352532088997042232U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 494418029883239087U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 16723410947058502564U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 16614089235313154270U;
            aOrbiterG = RotL64((aOrbiterG * 11530998303573027827U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 4245553025593349277U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 3353146318549477494U;
            aOrbiterK = RotL64((aOrbiterK * 14246377408238318091U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 5935727336135635196U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 10312187090293319667U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1395964500396711899U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 12192843181244744484U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 2542570124502586365U;
            aOrbiterC = RotL64((aOrbiterC * 17222847847573534963U), 53U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterJ, 11U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 35U));
            aIngress = aIngress + RotL64(aOrbiterC, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 51U) + aOrbiterK) + RotL64(aOrbiterC, 51U));
            aWandererA = aWandererA + ((((RotL64(aScatter, 29U) + RotL64(aOrbiterG, 22U)) + aOrbiterC) + RotL64(aCarry, 47U)) + aPhaseFWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 4U) + RotL64(aOrbiterH, 13U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 39U) + aOrbiterG) + RotL64(aOrbiterK, 5U)) + RotL64(aCarry, 5U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterH, 35U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + RotL64(aWandererA, 3U);
            aCarry = aCarry + RotL64(aIngress, 58U);
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

void TwistExpander_Bowling_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 7926U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 1294U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 1260U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneD[((aIndex + 7936U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCross, 42U)) ^ (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = ((aWandererD + RotL64(aScatter, 6U)) + RotL64(aCarry, 53U)) + 15813325389431304548U;
            aOrbiterG = (((aWandererG + RotL64(aIngress, 47U)) + RotL64(aCarry, 37U)) + 2223874171125403602U) + aPhaseGOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = (aWandererA + RotL64(aCross, 37U)) + 5510483568496824130U;
            aOrbiterD = (((aWandererE + RotL64(aPrevious, 57U)) + RotL64(aCarry, 5U)) + 15474152493495661876U) + aPhaseGOrbiterAssignSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterJ = (aWandererF + RotL64(aScatter, 19U)) + 16846339705130829195U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 1289670576865739669U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 18017354919647006944U;
            aOrbiterA = RotL64((aOrbiterA * 13103155460891498469U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 8539685539928984921U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 3333721400836704048U;
            aOrbiterH = RotL64((aOrbiterH * 3745286323481400085U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 2261560416623815491U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 4377786131746816567U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9164777834392621157U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 18047393176583722719U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 8184724021940434631U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9800116157750921119U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 10469895939183324807U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 14543391765109879223U;
            aOrbiterJ = RotL64((aOrbiterJ * 4817987697437667225U), 43U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterG, 40U);
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aIngress, 39U) + RotL64(aOrbiterG, 46U)) + aOrbiterD) + RotL64(aCarry, 41U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 28U) + RotL64(aOrbiterA, 11U)) + aOrbiterH);
            aWandererD = aWandererD + (((RotL64(aPrevious, 13U) + aOrbiterJ) + RotL64(aOrbiterG, 37U)) + RotL64(aCarry, 3U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterH, 21U)) + aOrbiterD) + aPhaseGWandererUpdateSaltA[((aIndex + 4U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 3U) + aOrbiterJ) + RotL64(aOrbiterA, 57U)) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 37U));
            aCarry = aCarry + RotL64(aWandererA, 11U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 10221U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneC[((aIndex + 8312U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 14410U)) & S_BLOCK1], 36U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 9530U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 37U) ^ RotL64(aIngress, 53U)) + (RotL64(aCarry, 20U) ^ RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 19U)) + RotL64(aCarry, 57U)) + 8367680518550579791U;
            aOrbiterK = (aWandererE + RotL64(aIngress, 3U)) + 11491674725611181241U;
            aOrbiterC = (((aWandererJ + RotL64(aScatter, 27U)) + RotL64(aCarry, 39U)) + 16673861720782164214U) + aPhaseGOrbiterAssignSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterD = ((aWandererF + RotL64(aCross, 57U)) + 9786610124108350855U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = ((aWandererH + RotL64(aIngress, 40U)) + RotL64(aCarry, 13U)) + 5745080601557577637U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 1959402215131684684U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 6121650036079196522U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13375345606276198671U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 12016309761037342392U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 5986936646177049603U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3585650475703294895U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 1000367700904043468U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 17425288243569101032U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2174614006719048535U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 4856917474950325209U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 16312111093223166419U;
            aOrbiterK = RotL64((aOrbiterK * 11046477664487805241U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 456110002032422270U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 11393724374787795662U;
            aOrbiterD = RotL64((aOrbiterD * 1176984359123668389U), 13U);
            //
            aIngress = RotL64(aOrbiterC, 47U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 26U));
            aIngress = aIngress + RotL64(aOrbiterD, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aCross, 29U) + aOrbiterD) + RotL64(aOrbiterK, 37U)) + RotL64(aCarry, 11U)) + aPhaseGWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 40U) + aOrbiterB) + RotL64(aOrbiterA, 27U));
            aWandererH = aWandererH + (((RotL64(aIngress, 11U) + RotL64(aOrbiterC, 3U)) + aOrbiterB) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterA, 57U)) + aOrbiterK);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterB, 12U)) + aOrbiterK) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + (RotL64(aWandererF, 48U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererH, 35U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 21668U)) & S_BLOCK1], 36U) ^ RotL64(aWorkLaneD[((aIndex + 22774U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22335U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneB[((aIndex + 19686U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aIngress, 37U)) ^ (RotL64(aCarry, 4U) + RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 11U)) + RotL64(aCarry, 5U)) + 9471546960258473684U;
            aOrbiterG = ((aWandererF + RotL64(aIngress, 3U)) + 18050235435948942244U) + aPhaseGOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = ((aWandererJ + RotL64(aCross, 40U)) + RotL64(aCarry, 41U)) + 3005107102671544641U;
            aOrbiterH = (aWandererA + RotL64(aScatter, 57U)) + 17898396434573801850U;
            aOrbiterF = (((aWandererE + RotL64(aIngress, 27U)) + RotL64(aCarry, 27U)) + 15071602525497771648U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 5780119462702672108U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 13301326224151025687U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2868878978993219351U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 18129323022260575961U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 1199228670638790709U;
            aOrbiterG = RotL64((aOrbiterG * 1780426336211781025U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 1839199978088021020U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 4999517042246790165U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4585813675677234577U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 8788607633376516299U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 15143903839930468749U;
            aOrbiterH = RotL64((aOrbiterH * 12735914889325422675U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 16674732686428431869U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 15908873150953195581U;
            aOrbiterF = RotL64((aOrbiterF * 18049755517524334107U), 11U);
            //
            aIngress = RotL64(aOrbiterB, 57U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + RotL64(aOrbiterH, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aScatter, 23U) + aOrbiterG) + RotL64(aOrbiterB, 47U)) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aIngress, 57U) + aOrbiterH) + RotL64(aOrbiterB, 39U)) + RotL64(aCarry, 57U)) + aPhaseGWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterH, 57U)) + aOrbiterF);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterC, 23U)) + aOrbiterG) + RotL64(aCarry, 43U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 48U) + RotL64(aOrbiterC, 4U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + RotL64(aWandererJ, 37U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 29276U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30549U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25116U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneC[((aIndex + 26331U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 51U) ^ RotL64(aCross, 19U)) + (RotL64(aCarry, 4U) + RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 35U)) + 4179952823252098240U) + aPhaseGOrbiterAssignSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = ((aWandererG + RotL64(aIngress, 24U)) + RotL64(aCarry, 13U)) + 3745613452332101749U;
            aOrbiterG = (aWandererH + RotL64(aCross, 51U)) + 2955689793395307176U;
            aOrbiterI = ((aWandererE + RotL64(aScatter, 13U)) + RotL64(aCarry, 51U)) + 5639060180251322019U;
            aOrbiterD = (((aWandererJ + RotL64(aCross, 3U)) + RotL64(aCarry, 39U)) + 7901969163853586463U) + aPhaseGOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 2242166787816318119U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 5239936443960750064U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2752853245379816327U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 13939136954732185558U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 17058884136712717463U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7222348891215482977U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 18148618660054585941U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 7022023484530327814U;
            aOrbiterI = RotL64((aOrbiterI * 650100011311048589U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 7722084537340095637U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 11764151879690934182U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12264384877711365655U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 16412785901758144708U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 9666718667728274824U;
            aOrbiterD = RotL64((aOrbiterD * 10865799822751771795U), 29U);
            //
            aIngress = RotL64(aOrbiterI, 5U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + RotL64(aOrbiterE, 30U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aScatter, 19U) + aOrbiterI) + RotL64(aOrbiterD, 13U)) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 11U) + aOrbiterG) + RotL64(aOrbiterE, 57U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterK, 29U)) + aOrbiterD) + RotL64(aCarry, 19U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 58U) + aOrbiterG) + RotL64(aOrbiterI, 37U));
            aWandererG = aWandererG + ((((RotL64(aCross, 37U) + aOrbiterK) + RotL64(aOrbiterE, 4U)) + RotL64(aCarry, 3U)) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererJ, 3U);
            aCarry = aCarry + RotL64(aIngress, 38U);
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

void TwistExpander_Bowling_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 5445U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4961U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3065U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 6483U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCarry, 14U)) + (RotL64(aPrevious, 27U) ^ RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = (((aWandererD + RotL64(aScatter, 5U)) + RotL64(aCarry, 39U)) + 5131645209694953015U) + aPhaseHOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 13U)) + RotL64(aCarry, 13U)) + 12070391048835379854U;
            aOrbiterA = ((aWandererC + RotL64(aIngress, 43U)) + RotL64(aCarry, 51U)) + 2604295836242338724U;
            aOrbiterH = ((aWandererI + RotL64(aCross, 60U)) + 14042039029284001596U) + aPhaseHOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = (aWandererE + RotL64(aIngress, 51U)) + 8914654543854559327U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 2185619407969359869U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 5187406295103352574U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10497064008152537837U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 8022832481290871217U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 8783061916740573472U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3309891377744201773U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 10711028365596196301U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 13387065038269133571U;
            aOrbiterH = RotL64((aOrbiterH * 12444578026365205255U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 11187001318931801582U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 14191473173276034019U;
            aOrbiterE = RotL64((aOrbiterE * 2491253922434756431U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 16207761776716426435U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 9677408414452078760U;
            aOrbiterG = RotL64((aOrbiterG * 5487303383095129949U), 21U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterE, 13U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + RotL64(aOrbiterA, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aScatter, 29U) + aOrbiterH) + RotL64(aOrbiterJ, 5U)) + RotL64(aCarry, 43U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 5U) + aOrbiterE) + RotL64(aOrbiterH, 13U));
            aWandererD = aWandererD + (((RotL64(aIngress, 21U) + aOrbiterA) + RotL64(aOrbiterJ, 43U)) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 42U) + RotL64(aOrbiterG, 24U)) + aOrbiterA) + aPhaseHWandererUpdateSaltC[((aIndex + 10U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 13U) + aOrbiterG) + RotL64(aOrbiterE, 35U)) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 37U));
            aCarry = aCarry + RotL64(aWandererC, 47U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 8765U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((aIndex + 13046U)) & S_BLOCK1], 26U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 10585U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15132U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 11U) + RotL64(aPrevious, 35U)) + (RotL64(aCross, 23U) ^ RotL64(aIngress, 60U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = (((aWandererJ + RotL64(aCross, 50U)) + RotL64(aCarry, 21U)) + 4848316479321533394U) + aPhaseHOrbiterAssignSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 39U)) + RotL64(aCarry, 39U)) + 6919360256662636195U;
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 13U)) + 9897013582181108544U) + aPhaseHOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = ((aWandererE + RotL64(aScatter, 5U)) + RotL64(aCarry, 53U)) + 7319353809896158678U;
            aOrbiterF = (aWandererK + RotL64(aPrevious, 29U)) + 2848175435514849859U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 6967780718720437934U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 10143884766603388136U;
            aOrbiterJ = RotL64((aOrbiterJ * 17346772745745835895U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 8675965006150972051U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 16350117755560994281U;
            aOrbiterF = RotL64((aOrbiterF * 15072308930382994425U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 17976597517118423760U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 1399631141355370237U;
            aOrbiterH = RotL64((aOrbiterH * 16537788276543236833U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 3590613762034716792U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 5134624314245932157U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13077589037975283371U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 10082236952942943654U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 4015535035905433450U;
            aOrbiterK = RotL64((aOrbiterK * 4961808568701908559U), 39U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterI, 11U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 60U));
            aIngress = aIngress + RotL64(aOrbiterF, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 11U) + aOrbiterI) + RotL64(aOrbiterH, 57U));
            aWandererH = aWandererH + (((RotL64(aIngress, 19U) + aOrbiterK) + RotL64(aOrbiterJ, 5U)) + RotL64(aCarry, 27U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 47U) + aOrbiterJ) + RotL64(aOrbiterF, 37U));
            aWandererE = aWandererE + ((((RotL64(aScatter, 39U) + RotL64(aOrbiterF, 14U)) + aOrbiterH) + RotL64(aCarry, 39U)) + aPhaseHWandererUpdateSaltA[((aIndex + 6U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 30U) + aOrbiterJ) + RotL64(aOrbiterI, 23U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 5U));
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererH, 60U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 20933U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneD[((aIndex + 20289U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23457U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20810U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 22U) + RotL64(aPrevious, 57U)) ^ (RotL64(aIngress, 37U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = (((aWandererD + RotL64(aScatter, 30U)) + RotL64(aCarry, 23U)) + 8375305456876489425U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = (aWandererH + RotL64(aIngress, 21U)) + 16193562952772453047U;
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 41U)) + 18088652458594816223U;
            aOrbiterF = (((aWandererK + RotL64(aCross, 13U)) + RotL64(aCarry, 37U)) + 767344788620249944U) + aPhaseHOrbiterAssignSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterB = ((aWandererG + RotL64(aIngress, 53U)) + RotL64(aCarry, 57U)) + 7705194930396368752U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 3829736891311272834U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 9881681671347640061U;
            aOrbiterJ = RotL64((aOrbiterJ * 14380245087931793021U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 1721196560190164264U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 3002652618388454213U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15289749311593032657U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 9811621464004005202U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 5652598941069986530U;
            aOrbiterH = RotL64((aOrbiterH * 4797973356708091621U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 6250499348327316328U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 16025054277615264530U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16446892258704281903U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 13800298546867243172U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 12256104592865905782U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16983140179497142713U), 27U);
            //
            aIngress = RotL64(aOrbiterB, 37U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aIngress, 29U) + aOrbiterH) + RotL64(aOrbiterF, 40U));
            aWandererF = aWandererF + ((((RotL64(aPrevious, 4U) + RotL64(aOrbiterB, 3U)) + aOrbiterF) + RotL64(aCarry, 41U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterI, 23U)) + aOrbiterJ);
            aWandererK = aWandererK + ((((RotL64(aScatter, 21U) + aOrbiterI) + RotL64(aOrbiterH, 13U)) + RotL64(aCarry, 27U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 39U) + aOrbiterB) + RotL64(aOrbiterJ, 51U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + RotL64(aWandererF, 51U);
            aCarry = aCarry + RotL64(aIngress, 6U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 32711U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((aIndex + 31108U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32066U)) & S_BLOCK1], 40U) ^ RotL64(aWorkLaneC[((aIndex + 32442U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 6U) ^ RotL64(aCarry, 53U)) ^ (RotL64(aCross, 23U) + RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = ((aWandererE + RotL64(aCross, 3U)) + 10726035965553989335U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = (((aWandererG + RotL64(aScatter, 13U)) + RotL64(aCarry, 21U)) + 967354339530195662U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 21U)) + RotL64(aCarry, 39U)) + 10834593005478605624U;
            aOrbiterI = ((aWandererF + RotL64(aIngress, 57U)) + RotL64(aCarry, 3U)) + 1012888282838656933U;
            aOrbiterK = (aWandererK + RotL64(aCross, 34U)) + 15283530351725183253U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 11724495956731703750U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 4288330117317505776U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2738997410474076757U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 10894778070022873473U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 15563886747621617467U;
            aOrbiterH = RotL64((aOrbiterH * 17884709931569040065U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 11182488628562891937U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 10420140066310588580U;
            aOrbiterI = RotL64((aOrbiterI * 13898299782819948719U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 11775138062167543111U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 16545391898578161683U;
            aOrbiterJ = RotL64((aOrbiterJ * 14588306527161321535U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 1550144656312299266U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 14903504853138279883U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8003033561266164387U), 13U);
            //
            aIngress = RotL64(aOrbiterD, 37U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterI, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aScatter, 27U) + aOrbiterK) + RotL64(aOrbiterI, 29U)) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aIngress, 19U) + RotL64(aOrbiterD, 47U)) + aOrbiterJ) + RotL64(aCarry, 43U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterI, 37U)) + aOrbiterD);
            aWandererE = aWandererE + (((RotL64(aCross, 39U) + aOrbiterH) + RotL64(aOrbiterI, 20U)) + RotL64(aCarry, 23U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 10U) + aOrbiterK) + RotL64(aOrbiterD, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererK, 21U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererF, 13U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
