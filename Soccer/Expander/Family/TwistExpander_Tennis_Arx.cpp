#include "TwistExpander_Tennis_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_Tennis_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xF12F37AC4EA53895ULL + 0xDFE3253302387FD5ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xC2C0CBF14283590BULL + 0xAC7574F6FA18890EULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x9BB8A898C121FF07ULL + 0xADA356874C83AEBBULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xD4FB91CE669815E3ULL + 0x9EA75C662569C457ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xA62635CD89B5ACD3ULL + 0xF65F175EC35128C3ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xD45C3EF91F674303ULL + 0x82BB5A7C72596725ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xAB5272F6A6E89837ULL + 0xB6F5A92B05880179ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xF2E945390CC7CD5FULL + 0xE3844251DDAA4C9CULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xD958869F2E3DBD9FULL + 0xB00DE7233E151502ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xA22AD855498AAB51ULL + 0x9576B9ED466982B7ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xFEBC1062CBF2C217ULL + 0xC307D87A3D997CBBULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x82696EF27695ED55ULL + 0xECEDF1203A37766EULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x83A18E957CAE56E9ULL + 0xEE002A02BF773810ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xBE2E96078BA9C919ULL + 0xE12CC06F5F9CAB85ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xA8F51E4D4E131B9DULL + 0x8D0F768901F60127ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x9DA60A0C11B81199ULL + 0xE57620A2BAC791B9ULL);
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
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 687U)) & S_BLOCK1], 46U) ^ RotL64(pSnow[((aIndex + 5430U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 1598U)) & S_BLOCK1], 13U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 2436U)) & S_BLOCK1], 42U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 40U) ^ RotL64(aCross, 53U)) + (RotL64(aCarry, 11U) ^ RotL64(aPrevious, 23U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 30U)) + 7075016829833562104U;
            aOrbiterH = (aWandererA + RotL64(aIngress, 53U)) + 8783765886115517036U;
            aOrbiterI = ((aWandererK + RotL64(aScatter, 51U)) + RotL64(aCarry, 39U)) + 2996723892384565829U;
            aOrbiterB = ((aWandererH + RotL64(aCross, 35U)) + 9494134707342189476U) + aNonceWordI;
            aOrbiterK = (((aWandererD + RotL64(aPrevious, 60U)) + RotL64(aCarry, 3U)) + 5052642981395679904U) + aNonceWordL;
            aOrbiterA = ((aWandererE + RotL64(aIngress, 11U)) + RotL64(aCarry, 43U)) + 8766787055127962238U;
            aOrbiterF = (aWandererC + RotL64(aScatter, 39U)) + 4467211954388738079U;
            aOrbiterG = (aWandererB + RotL64(aCross, 47U)) + 8030255604633658608U;
            aOrbiterE = ((aWandererI + RotL64(aPrevious, 5U)) + 16962408063455702251U) + aOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = (aWandererJ + RotL64(aCross, 3U)) + 3768222186567699076U;
            aOrbiterD = (((aWandererG + RotL64(aScatter, 43U)) + 14930990410207899871U) + aOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordP;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 14179761938395502502U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 1879084742719898108U;
            aOrbiterI = RotL64((aOrbiterI * 16783034788172670121U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 5535012408925981515U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 12792553516710295939U;
            aOrbiterA = RotL64((aOrbiterA * 8577530993755159329U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 8979253163346099252U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 5559189896063990740U;
            aOrbiterJ = RotL64((aOrbiterJ * 8832485423727331621U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 13937564337299044079U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 2393376759689394948U;
            aOrbiterB = RotL64((aOrbiterB * 2352815657830413941U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 12647519563697356479U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 10946871249960389549U) ^ aOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6272580371881237173U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 13376798695582123147U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 10958115913599631271U;
            aOrbiterE = RotL64((aOrbiterE * 18233981473003345217U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 4283914227806672773U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 910842005516235816U;
            aOrbiterD = RotL64((aOrbiterD * 6722229871617873429U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 1509644316619370324U) + aNonceWordM;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 165987596716078174U) ^ aNonceWordN;
            aOrbiterH = RotL64((aOrbiterH * 13600064054240185123U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 12491315345199091186U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 5982431705686495125U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2547243804779022665U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 231183123382412440U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 2872632389683254396U;
            aOrbiterG = RotL64((aOrbiterG * 1972278820468847241U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 15259314110008210315U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 7075016829833562104U;
            aOrbiterC = RotL64((aOrbiterC * 8350093877370898869U), 27U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterJ, 29U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 43U));
            aIngress = aIngress + (RotL64(aOrbiterK, 34U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 51U));
            aIngress = aIngress + (RotL64(aOrbiterI, 19U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterH, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterC, 10U)) + aOrbiterB) + aWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 43U) + RotL64(aOrbiterK, 47U)) + aOrbiterH);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 29U) + aOrbiterD) + RotL64(aOrbiterA, 3U)) + aWandererUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 40U) + aOrbiterD) + RotL64(aOrbiterI, 41U)) + RotL64(aCarry, 53U)) + aNonceWordH);
            aWandererC = aWandererC ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterJ, 19U)) + aOrbiterE);
            aWandererG = aWandererG + ((RotL64(aIngress, 47U) + RotL64(aOrbiterF, 35U)) + aOrbiterE);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterG, 21U)) + aOrbiterI);
            aWandererI = aWandererI + (((RotL64(aScatter, 3U) + RotL64(aOrbiterD, 51U)) + aOrbiterJ) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 21U) + aOrbiterF) + RotL64(aOrbiterH, 37U));
            aWandererD = aWandererD + ((RotL64(aCross, 5U) + aOrbiterK) + RotL64(aOrbiterB, 13U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 34U) + aOrbiterH) + RotL64(aOrbiterA, 44U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + (RotL64(aWandererG, 58U) ^ aWandererJ);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 21U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + RotL64(aWandererB, 3U);
            aCarry = aCarry + RotL64(aIngress, 56U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordB);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8428U)) & S_BLOCK1], 5U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 6839U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(pSnow[((S_BLOCK1 - aIndex + 5596U)) & S_BLOCK1], 46U) ^ RotL64(aWorkLaneA[((aIndex + 7705U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCross, 11U)) ^ (RotL64(aCarry, 54U) + RotL64(aPrevious, 41U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererB + RotL64(aScatter, 48U)) + RotL64(aCarry, 37U)) + 11700815697312060726U;
            aOrbiterF = (aWandererI + RotL64(aCross, 37U)) + 11808423452327465441U;
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 57U)) + 8670503858631730886U) + aNonceWordA;
            aOrbiterA = ((aWandererD + RotL64(aIngress, 35U)) + 2400061067991988544U) + aOrbiterAssignSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterC = (((aWandererG + RotL64(aPrevious, 41U)) + RotL64(aCarry, 3U)) + 16163118178366229686U) + aOrbiterAssignSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterI = (aWandererF + RotL64(aCross, 23U)) + 3280178595904941068U;
            aOrbiterD = ((aWandererE + RotL64(aIngress, 13U)) + RotL64(aCarry, 19U)) + 3298683600817047727U;
            aOrbiterH = (aWandererJ + RotL64(aScatter, 11U)) + 16321624053445183574U;
            aOrbiterB = (aWandererA + RotL64(aCross, 19U)) + 6730229877611375225U;
            aOrbiterG = (aWandererH + RotL64(aPrevious, 29U)) + 10162830636713641322U;
            aOrbiterJ = (aWandererC + RotL64(aScatter, 46U)) + 15646771327759599256U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 14841751262270544102U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 9545541117228834895U) ^ aOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11529769874752969377U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 14676615635857599982U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 1231768638470558855U;
            aOrbiterF = RotL64((aOrbiterF * 2716808508509014677U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 1945905595345404833U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterI) ^ 1406171421638586846U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterC = RotL64((aOrbiterC * 4577864352425476233U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 1970292335806697198U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 12309719390375013297U;
            aOrbiterD = RotL64((aOrbiterD * 16540660957923687327U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 5352135521358954576U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 15465675376193501658U;
            aOrbiterB = RotL64((aOrbiterB * 16385761112921041387U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 2842123638916600369U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 3544764287036748668U) ^ aOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3360772950777850115U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 6038297172906492282U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 10249342332287140970U;
            aOrbiterA = RotL64((aOrbiterA * 16701083081566042277U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 1662076777040529446U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 1949705569959740274U;
            aOrbiterI = RotL64((aOrbiterI * 11340691546658994529U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 13934194245417822360U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 5720408806425535958U;
            aOrbiterH = RotL64((aOrbiterH * 15237561081637415383U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 2209251362417210658U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 4917447930929521699U;
            aOrbiterG = RotL64((aOrbiterG * 17489570156694692569U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 14817115766683623486U) + aOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 11700815697312060726U;
            aOrbiterJ = RotL64((aOrbiterJ * 16982411053956669181U), 41U);
            //
            aIngress = RotL64(aOrbiterG, 48U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterJ, 53U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterI, 3U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterK, 5U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterH, 27U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterF, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterJ, 43U)) + aOrbiterD);
            aWandererJ = aWandererJ + (((RotL64(aCross, 50U) + RotL64(aOrbiterH, 40U)) + aOrbiterC) + RotL64(aCarry, 3U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 57U) + aOrbiterA) + RotL64(aOrbiterE, 27U));
            aWandererK = aWandererK + ((RotL64(aIngress, 11U) + aOrbiterI) + RotL64(aOrbiterH, 51U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 41U) + aOrbiterB) + RotL64(aOrbiterK, 53U));
            aWandererA = aWandererA + (((RotL64(aScatter, 19U) + aOrbiterI) + RotL64(aOrbiterF, 13U)) + aNonceWordH);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 13U) + aOrbiterF) + RotL64(aOrbiterG, 46U));
            aWandererF = aWandererF + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterI, 3U)) + aOrbiterC) + RotL64(aCarry, 37U)) + aWandererUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterE, 35U)) + aOrbiterF);
            aWandererD = aWandererD + (((RotL64(aIngress, 52U) + RotL64(aOrbiterJ, 37U)) + aOrbiterI) + aNonceWordM);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 21U) + aOrbiterJ) + RotL64(aOrbiterK, 23U)) + aWandererUpdateSaltD[((aIndex + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 6U));
            aCarry = aCarry + (RotL64(aWandererB, 21U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererD);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + (RotL64(aWandererF, 53U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererA, 39U);
            aCarry = aCarry + RotL64(aIngress, 28U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordJ);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 13280U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13961U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 11933U)) & S_BLOCK1], 21U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 12507U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 22U) ^ RotL64(aCarry, 5U)) + (RotL64(aIngress, 41U) ^ RotL64(aCross, 57U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((aWandererG + RotL64(aScatter, 57U)) + 252059974543142812U) + aOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = (((aWandererE + RotL64(aIngress, 44U)) + 11690823093681457368U) + aOrbiterAssignSaltB[((aIndex + 4U)) & S_SALT1]) + aNonceWordO;
            aOrbiterF = ((aWandererI + RotL64(aCross, 13U)) + 13282189752890971123U) + aNonceWordB;
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 23U)) + RotL64(aCarry, 53U)) + 9507416294305708435U;
            aOrbiterC = (aWandererC + RotL64(aIngress, 47U)) + 14053038174390776539U;
            aOrbiterK = ((aWandererK + RotL64(aCross, 6U)) + RotL64(aCarry, 47U)) + 14605253312318725009U;
            aOrbiterE = (aWandererH + RotL64(aScatter, 11U)) + 18138286582677863671U;
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 53U)) + 8530091235978489988U;
            aOrbiterJ = (aWandererB + RotL64(aScatter, 37U)) + 14381731677571170073U;
            aOrbiterI = ((aWandererD + RotL64(aIngress, 3U)) + RotL64(aCarry, 43U)) + 13316413456378978456U;
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 51U)) + 3910529530149320706U) + aNonceWordJ;
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 6302070286831566901U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 12324134652758551396U;
            aOrbiterF = RotL64((aOrbiterF * 17136438281540250165U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 4773478557638475048U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 4031153435446078944U;
            aOrbiterK = RotL64((aOrbiterK * 3876928995240982769U), 21U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterG) + 3114794895962903899U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordE;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 3552936509969106796U;
            aOrbiterD = RotL64((aOrbiterD * 16823186892738820299U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 5828754613946145627U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 17985241114076114558U;
            aOrbiterC = RotL64((aOrbiterC * 1986669631395606833U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 11319331046368072261U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 6104267020171882160U;
            aOrbiterG = RotL64((aOrbiterG * 12525117969211576177U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 7662668379725735125U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 6583034411403600735U;
            aOrbiterI = RotL64((aOrbiterI * 262095656452193889U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 5569865728026310280U) + aOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = (((aOrbiterA ^ aOrbiterK) ^ 4176065898330374039U) ^ aOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterA = RotL64((aOrbiterA * 11305749530796963967U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 13677146592276526676U) + aOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 2734371113158117596U;
            aOrbiterB = RotL64((aOrbiterB * 13146444882662731975U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 14890607377967461739U) + aNonceWordN;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 3110674898918355049U;
            aOrbiterE = RotL64((aOrbiterE * 9637837600671200315U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 15329760212453783067U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 18214263442264013242U;
            aOrbiterJ = RotL64((aOrbiterJ * 9139354822936682953U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 6727267537859989206U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 252059974543142812U;
            aOrbiterH = RotL64((aOrbiterH * 9559128226993261041U), 19U);
            //
            aIngress = RotL64(aOrbiterJ, 21U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterK, 6U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterH, 29U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 47U));
            aIngress = aIngress + RotL64(aOrbiterG, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 35U) + aOrbiterI) + RotL64(aOrbiterE, 24U));
            aWandererH = aWandererH + (((RotL64(aScatter, 5U) + aOrbiterG) + RotL64(aOrbiterF, 39U)) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 44U) + RotL64(aOrbiterE, 53U)) + aOrbiterJ);
            aWandererK = aWandererK + (((RotL64(aPrevious, 13U) + aOrbiterC) + RotL64(aOrbiterD, 27U)) + aNonceWordA);
            aWandererC = aWandererC ^ ((((RotL64(aIngress, 41U) + aOrbiterB) + RotL64(aOrbiterK, 50U)) + aNonceWordH) + aWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 39U) + RotL64(aOrbiterG, 13U)) + aOrbiterE);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 11U) + aOrbiterA) + RotL64(aOrbiterB, 3U));
            aWandererJ = aWandererJ + ((((RotL64(aCross, 26U) + aOrbiterH) + RotL64(aOrbiterB, 37U)) + RotL64(aCarry, 43U)) + aNonceWordC);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 51U) + aOrbiterB) + RotL64(aOrbiterE, 19U)) + aWandererUpdateSaltA[((aIndex + 28U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 23U) + aOrbiterE) + RotL64(aOrbiterF, 57U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 3U) + aOrbiterF) + RotL64(aOrbiterC, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 34U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 21U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererE, 30U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordL);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 20346U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 18488U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21536U)) & S_BLOCK1], 37U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 16661U)) & S_BLOCK1], 22U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 19U) + RotL64(aCarry, 53U)) + (RotL64(aCross, 35U) ^ RotL64(aPrevious, 4U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = ((aWandererD + RotL64(aCross, 53U)) + 4476099022490972343U) + aNonceWordG;
            aOrbiterA = ((aWandererB + RotL64(aIngress, 6U)) + RotL64(aCarry, 47U)) + 16836423700375760429U;
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 37U)) + RotL64(aCarry, 21U)) + 8850577488928703557U;
            aOrbiterG = ((aWandererC + RotL64(aScatter, 39U)) + 7091631824560042743U) + aNonceWordC;
            aOrbiterK = ((aWandererJ + RotL64(aCross, 57U)) + RotL64(aCarry, 13U)) + 12560498899956759494U;
            aOrbiterI = (aWandererA + RotL64(aScatter, 35U)) + 7797973377112012161U;
            aOrbiterB = (aWandererG + RotL64(aIngress, 11U)) + 6173820673874805794U;
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 47U)) + 10805025132310245348U) + aOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = (aWandererF + RotL64(aCross, 43U)) + 7139216143268029968U;
            aOrbiterD = (((aWandererE + RotL64(aPrevious, 22U)) + 8241544862261635722U) + aOrbiterAssignSaltE[((aIndex + 22U)) & S_SALT1]) + aNonceWordD;
            aOrbiterH = (aWandererK + RotL64(aIngress, 41U)) + 4735527016563596150U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 5166171126690294033U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 11117641762075368393U) ^ aNonceWordE;
            aOrbiterJ = RotL64((aOrbiterJ * 4980156869201219393U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 6312932356458415421U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 1304139291184508668U;
            aOrbiterK = RotL64((aOrbiterK * 90744653170922319U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 10085025354842771067U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 16745854428789531080U) ^ aNonceWordN;
            aOrbiterI = RotL64((aOrbiterI * 1945983905747274355U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 2497187958708890337U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 16069701876646548995U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16606039730973709495U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 17242004368025978091U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 12334315722243232121U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16528598396696346719U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 8007042082518126895U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 5665686359038811484U) ^ aOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11289316305875751813U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 3913477186958600592U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 16918984318564170343U;
            aOrbiterD = RotL64((aOrbiterD * 5128293326494417281U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 10227611546502931418U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 7187623463085447228U;
            aOrbiterH = RotL64((aOrbiterH * 8479839369622163181U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 16655159122037336519U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 9844145011519243346U;
            aOrbiterE = RotL64((aOrbiterE * 16512883184116277583U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 8660130685326542506U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 16192687259641294851U;
            aOrbiterA = RotL64((aOrbiterA * 2882649237163668499U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 15208432734447317310U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 4476099022490972343U;
            aOrbiterG = RotL64((aOrbiterG * 7447168142776253041U), 29U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterK, 44U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 39U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 51U));
            aIngress = aIngress + (RotL64(aOrbiterB, 35U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 37U));
            aIngress = aIngress + RotL64(aOrbiterE, 42U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterI, 24U)) + aOrbiterB);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 53U) + aOrbiterH) + RotL64(aOrbiterJ, 5U));
            aWandererG = aWandererG + (((RotL64(aCross, 13U) + RotL64(aOrbiterH, 47U)) + aOrbiterK) + RotL64(aCarry, 41U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 6U) + aOrbiterE) + RotL64(aOrbiterI, 35U)) + aWandererUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterC, 13U)) + aOrbiterJ) + RotL64(aCarry, 53U)) + aNonceWordO);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 35U) + aOrbiterC) + RotL64(aOrbiterK, 19U)) + aWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 21U) + aOrbiterD) + RotL64(aOrbiterG, 53U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 41U) + aOrbiterK) + RotL64(aOrbiterD, 58U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 51U) + aOrbiterA) + RotL64(aOrbiterI, 3U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 46U) + aOrbiterD) + RotL64(aOrbiterB, 29U));
            aWandererC = aWandererC + ((RotL64(aScatter, 57U) + RotL64(aOrbiterJ, 37U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 51U));
            aCarry = aCarry + (RotL64(aWandererH, 39U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererA, 42U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + RotL64(aWandererI, 19U);
            aCarry = aCarry + RotL64(aIngress, 58U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordO);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 26591U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26262U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 23123U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25157U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 21U) + RotL64(aCarry, 39U)) ^ (RotL64(aPrevious, 6U) + RotL64(aCross, 51U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 53U)) + 14823268998003220191U;
            aOrbiterB = (aWandererF + RotL64(aScatter, 47U)) + 15295237288788213847U;
            aOrbiterG = ((aWandererD + RotL64(aCross, 57U)) + 16434853402001133899U) + aNonceWordE;
            aOrbiterE = (aWandererK + RotL64(aIngress, 6U)) + 7555911304407871631U;
            aOrbiterD = ((aWandererB + RotL64(aCross, 23U)) + 14977248264994834620U) + aNonceWordI;
            aOrbiterC = (((aWandererE + RotL64(aScatter, 43U)) + RotL64(aCarry, 57U)) + 9707764144919392380U) + aOrbiterAssignSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 19U)) + RotL64(aCarry, 5U)) + 1277304385464681529U;
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 35U)) + 3089786220465849395U) + aOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = ((aWandererH + RotL64(aCross, 29U)) + 3700503853358695085U) + aNonceWordM;
            aOrbiterH = ((aWandererG + RotL64(aIngress, 41U)) + RotL64(aCarry, 19U)) + 3240054112993517371U;
            aOrbiterK = (aWandererI + RotL64(aScatter, 12U)) + 16897532076915366859U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 18167359289798364307U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 8870819278575769863U;
            aOrbiterG = RotL64((aOrbiterG * 9334066154398059075U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 15363069206212330251U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 14858164441499725158U;
            aOrbiterC = RotL64((aOrbiterC * 14931933411393847915U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 5357144808788707522U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 2910681277417754860U;
            aOrbiterJ = RotL64((aOrbiterJ * 13170868582159347059U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 9824408699018165151U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 368370224788793300U;
            aOrbiterH = RotL64((aOrbiterH * 14358982366258729959U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 7095398304588825115U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 11418879758164313554U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5983520332639771791U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 2171599720681913272U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 17593730219647495033U) ^ aOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12926053208918563087U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 17755947635188715523U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 14565740605227022106U;
            aOrbiterF = RotL64((aOrbiterF * 15866418354612945335U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 14538017880915584414U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 6174566474851449123U;
            aOrbiterA = RotL64((aOrbiterA * 179569008593475683U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 3806438394748643441U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 13737114463856719285U;
            aOrbiterK = RotL64((aOrbiterK * 13439346068497710151U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 3698379331577470045U) + aNonceWordB;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 1097081284062708554U;
            aOrbiterB = RotL64((aOrbiterB * 3498627643013255777U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 215117138867597766U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 14823268998003220191U) ^ aOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12131828437975771377U), 13U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterI, 39U);
            aIngress = aIngress + (RotL64(aOrbiterK, 4U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 11U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 47U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 43U));
            aIngress = aIngress + RotL64(aOrbiterH, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterI, 18U)) + aOrbiterB);
            aWandererH = aWandererH + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterG, 13U)) + aOrbiterK) + RotL64(aCarry, 35U)) + aWandererUpdateSaltD[((aIndex + 10U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 5U) + aOrbiterB) + RotL64(aOrbiterD, 43U)) + aNonceWordC);
            aWandererC = aWandererC + (((RotL64(aPrevious, 44U) + RotL64(aOrbiterG, 41U)) + aOrbiterH) + aWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aCross, 27U) + aOrbiterJ) + RotL64(aOrbiterC, 53U)) + aNonceWordH);
            aWandererK = aWandererK + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterI, 37U)) + aOrbiterC);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterF, 21U)) + aOrbiterB) + aNonceWordN);
            aWandererG = aWandererG + ((RotL64(aIngress, 29U) + RotL64(aOrbiterD, 26U)) + aOrbiterA);
            aWandererA = aWandererA ^ ((RotL64(aCross, 14U) + aOrbiterK) + RotL64(aOrbiterA, 47U));
            aWandererE = aWandererE + (((RotL64(aIngress, 21U) + RotL64(aOrbiterE, 57U)) + aOrbiterJ) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterK, 29U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 30U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererD, 41U);
            aCarry = aCarry + RotL64(aIngress, 28U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordD);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 31644U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((aIndex + 30115U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31735U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((aIndex + 31083U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 21U) + RotL64(aCarry, 50U)) + (RotL64(aIngress, 37U) ^ RotL64(aCross, 3U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = ((aWandererH + RotL64(aScatter, 57U)) + RotL64(aCarry, 23U)) + 12669015908335980355U;
            aOrbiterC = (aWandererE + RotL64(aPrevious, 51U)) + 5438715179868613192U;
            aOrbiterI = ((aWandererD + RotL64(aCross, 43U)) + 13172104448184536460U) + aOrbiterAssignSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterE = (((aWandererG + RotL64(aIngress, 46U)) + RotL64(aCarry, 57U)) + 13421421503244744803U) + aOrbiterAssignSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = (aWandererI + RotL64(aCross, 13U)) + 13327113302994856582U;
            aOrbiterD = (aWandererC + RotL64(aScatter, 53U)) + 4671768205922454413U;
            aOrbiterH = (aWandererJ + RotL64(aIngress, 3U)) + 5355759962838579929U;
            aOrbiterF = (aWandererB + RotL64(aPrevious, 60U)) + 6691720614265406851U;
            aOrbiterK = (aWandererK + RotL64(aIngress, 35U)) + 7063906424700911378U;
            aOrbiterB = (((aWandererA + RotL64(aCross, 23U)) + RotL64(aCarry, 27U)) + 17328616394166672263U) + aNonceWordI;
            aOrbiterA = (aWandererF + RotL64(aPrevious, 11U)) + 1542940602574207068U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 7203866278803132454U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 993485696233139264U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11609009908810366447U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 15659679028507488331U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 18321361454094675842U;
            aOrbiterJ = RotL64((aOrbiterJ * 3966860765622641843U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 9633319822696783352U) + aNonceWordG;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 3496559332232402963U;
            aOrbiterD = RotL64((aOrbiterD * 7772060229838162977U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 1918349708324205526U) + aOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 7701088402761359134U;
            aOrbiterH = RotL64((aOrbiterH * 9649485438465644795U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 6006824348814439686U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 18088375375347012557U;
            aOrbiterF = RotL64((aOrbiterF * 12801082943086128385U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 12816533373478543584U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 17951880253818836433U;
            aOrbiterK = RotL64((aOrbiterK * 8935839101517220201U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 11311632024372748238U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 9891349164779752351U;
            aOrbiterB = RotL64((aOrbiterB * 11405973752233193209U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 711130292000437038U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 17818800917771709681U;
            aOrbiterA = RotL64((aOrbiterA * 10567029732245868263U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 10188714200240109442U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 9745615081760948652U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9321909462220134035U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 6508703788527163965U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 7536038073603467381U) ^ aNonceWordB;
            aOrbiterC = RotL64((aOrbiterC * 12015514242701199813U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 2793951597846756844U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 12669015908335980355U;
            aOrbiterE = RotL64((aOrbiterE * 7355285540199760689U), 27U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterC, 53U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 18U));
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterA, 35U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterH, 5U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterI, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterH, 27U)) + aOrbiterC) + aWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 19U) + aOrbiterK) + RotL64(aOrbiterH, 41U)) + RotL64(aCarry, 29U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterG, 6U)) + aOrbiterK);
            aWandererF = aWandererF + (((RotL64(aPrevious, 46U) + aOrbiterC) + RotL64(aOrbiterD, 53U)) + aNonceWordJ);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 29U) + aOrbiterH) + RotL64(aOrbiterF, 47U)) + aWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 37U) + aOrbiterF) + RotL64(aOrbiterG, 13U)) + RotL64(aCarry, 43U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 21U) + aOrbiterB) + RotL64(aOrbiterA, 21U)) + aNonceWordL);
            aWandererK = aWandererK + ((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterI, 43U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterE, 29U)) + aOrbiterD);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 57U) + aOrbiterA) + RotL64(aOrbiterG, 50U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 48U) + RotL64(aOrbiterG, 35U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererI, 12U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 5U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererG, 54U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererB, 51U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordD);
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

void TwistExpander_Tennis_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xA6382B7C4685B34BULL + 0xB08DA60CAB3A4D0BULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x8FF7F4C8F8C410E9ULL + 0xEBDA7C230F40D227ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xF24F6384590F00BBULL + 0xB581E18A4EE61397ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xEDF38E62CDF0D6E3ULL + 0x8E424CBB3A25034BULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xB74927A468CB7A55ULL + 0xEED1F346612C1B15ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xCB93473EC335DF6BULL + 0x999456FFE3D0C31CULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x85F2B14E272549E7ULL + 0x8097608CF661A654ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x81FC703084378C41ULL + 0x9DA82F4A9D32AEFAULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xBB19A691050799E1ULL + 0x9263496173C9EB98ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x9A21545E46E475B9ULL + 0xA7B2089792CE2C26ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xFD05289B89A02FCFULL + 0xF0039868408B50F5ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xA00426E1E6F84F93ULL + 0xF6BCDF31AAB94768ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xB02DD6135C179851ULL + 0xF1D6AECDC8AB3E27ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xBBDE1D390A7435E3ULL + 0xE6FDF07DFD224391ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x893902EEC9590F27ULL + 0x81B7B3F896D691BFULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xCB1A748092F04C95ULL + 0xF5E540F717BF6C0FULL);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 6946U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneC[((aIndex + 988U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 3998U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneA[((aIndex + 7761U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aIngress, 5U)) ^ (RotL64(aCross, 56U) ^ RotL64(aPrevious, 43U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (aWandererE + RotL64(aCross, 53U)) + 14624277139785904404U;
            aOrbiterD = (aWandererF + RotL64(aIngress, 47U)) + 6966977309498165611U;
            aOrbiterH = (((aWandererG + RotL64(aPrevious, 39U)) + RotL64(aCarry, 35U)) + 205536824352530761U) + aOrbiterAssignSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterK = (((aWandererD + RotL64(aScatter, 34U)) + RotL64(aCarry, 5U)) + 16629575265808255692U) + aNonceWordI;
            aOrbiterA = ((aWandererC + RotL64(aCross, 27U)) + 596881340147972746U) + aOrbiterAssignSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = (aWandererH + RotL64(aScatter, 5U)) + 11944412799107412650U;
            aOrbiterF = (aWandererK + RotL64(aPrevious, 13U)) + 4615021315668210206U;
            aOrbiterI = ((aWandererB + RotL64(aIngress, 58U)) + RotL64(aCarry, 57U)) + 8497630055977606216U;
            aOrbiterG = (aWandererI + RotL64(aCross, 19U)) + 11131601107309336885U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 5935883479805510099U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 15629346719765798174U) ^ aNonceWordK;
            aOrbiterH = RotL64((aOrbiterH * 8535523790685945275U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 5279128339113651273U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 16778365912440331821U;
            aOrbiterJ = RotL64((aOrbiterJ * 705421028266789241U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 16003052937645491524U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 6723226158737614764U;
            aOrbiterI = RotL64((aOrbiterI * 16690657664909260573U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 9785784358981219543U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 10055457337292292710U;
            aOrbiterG = RotL64((aOrbiterG * 17919129940751761111U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 11779163108592974175U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 1177999477942202687U;
            aOrbiterC = RotL64((aOrbiterC * 13475069421684114643U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 9190694445141492214U) + aNonceWordG;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 15605342360346353457U;
            aOrbiterK = RotL64((aOrbiterK * 14547769706392595647U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 14877565450677523492U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 1074095623308025684U;
            aOrbiterF = RotL64((aOrbiterF * 7884068939436891093U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 12803174154216941583U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 8813356463693637033U) ^ aOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4898237214617563167U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 6063909634038581414U) + aOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 15112191502834052566U;
            aOrbiterA = RotL64((aOrbiterA * 6780741782103553485U), 3U);
            //
            aIngress = RotL64(aOrbiterJ, 29U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterI, 48U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterD, 51U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 11U));
            aIngress = aIngress + RotL64(aOrbiterA, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 18U) + aOrbiterG) + RotL64(aOrbiterH, 34U));
            aWandererB = aWandererB + (((RotL64(aScatter, 23U) + RotL64(aOrbiterF, 5U)) + aOrbiterC) + aNonceWordO);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterI, 39U)) + aOrbiterJ);
            aWandererD = aWandererD + (((RotL64(aIngress, 47U) + RotL64(aOrbiterH, 13U)) + aOrbiterA) + aNonceWordJ);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterD, 43U)) + aOrbiterF) + aNonceWordN);
            aWandererG = aWandererG + ((((RotL64(aScatter, 29U) + RotL64(aOrbiterK, 47U)) + aOrbiterJ) + RotL64(aCarry, 5U)) + aWandererUpdateSaltE[((aIndex + 18U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 41U) + aOrbiterJ) + RotL64(aOrbiterF, 19U));
            aWandererH = aWandererH + ((((RotL64(aCross, 13U) + aOrbiterH) + RotL64(aOrbiterJ, 30U)) + RotL64(aCarry, 21U)) + aWandererUpdateSaltF[((aIndex + 8U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 36U) + aOrbiterC) + RotL64(aOrbiterG, 57U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 18U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 23U));
            aCarry = aCarry + RotL64(aWandererH, 53U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ aNonceWordI;
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 12102U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneD[((aIndex + 12420U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8214U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 11522U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 43U) + RotL64(aCross, 6U)) + (RotL64(aCarry, 27U) ^ RotL64(aIngress, 57U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (aWandererH + RotL64(aIngress, 36U)) + 9914837590440975587U;
            aOrbiterA = ((aWandererB + RotL64(aCross, 11U)) + RotL64(aCarry, 23U)) + 6706125076401958051U;
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 51U)) + 16570817772679258409U) + aOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = (aWandererG + RotL64(aScatter, 23U)) + 6843705658115186948U;
            aOrbiterC = ((((aWandererF + RotL64(aIngress, 3U)) + RotL64(aCarry, 47U)) + 16099930446791572351U) + aOrbiterAssignSaltC[((aIndex + 14U)) & S_SALT1]) + aNonceWordM;
            aOrbiterK = (aWandererA + RotL64(aCross, 19U)) + 5420550009556030459U;
            aOrbiterG = ((aWandererE + RotL64(aScatter, 57U)) + RotL64(aCarry, 57U)) + 5729549069420177477U;
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 29U)) + 15590601126188675834U;
            aOrbiterB = (aWandererC + RotL64(aScatter, 44U)) + 13044027390998620029U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 11068338135659636772U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 6584988841809544332U;
            aOrbiterE = RotL64((aOrbiterE * 1683336180438945439U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 8516813219883915404U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 10647314042912492785U) ^ aOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15559481057047148785U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 201691689889605304U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 15512161798401184003U;
            aOrbiterG = RotL64((aOrbiterG * 11473219183982564709U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 3883760518944464145U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 13861805129175491145U;
            aOrbiterI = RotL64((aOrbiterI * 17194438894492581181U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 12019138626550801486U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 13030350224959652248U;
            aOrbiterB = RotL64((aOrbiterB * 11724200983306280107U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 2643807255422544248U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 4127143302485631794U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5441038881111578487U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 14602951930809633069U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 4555737199162278494U;
            aOrbiterD = RotL64((aOrbiterD * 12415825635220991865U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 6343143902997169834U) + aOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 10404783711336491985U;
            aOrbiterK = RotL64((aOrbiterK * 6235474458879439079U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 7406959231434835393U) + aNonceWordH;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 6684368109277850196U;
            aOrbiterA = RotL64((aOrbiterA * 8760360417572331159U), 47U);
            //
            aIngress = RotL64(aOrbiterH, 35U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterE, 22U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterG, 53U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 19U));
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((((RotL64(aCross, 41U) + RotL64(aOrbiterH, 60U)) + aOrbiterC) + RotL64(aCarry, 13U)) + aNonceWordF) + aWandererUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 29U) + aOrbiterE) + RotL64(aOrbiterK, 13U)) + aWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterI, 27U)) + aOrbiterA) + RotL64(aCarry, 35U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 60U) + aOrbiterC) + RotL64(aOrbiterB, 23U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 47U) + aOrbiterC) + RotL64(aOrbiterD, 47U)) + aNonceWordC);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterD, 35U)) + aOrbiterE);
            aWandererF = aWandererF + ((RotL64(aCross, 3U) + RotL64(aOrbiterI, 52U)) + aOrbiterH);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterK, 43U)) + aOrbiterG);
            aWandererB = aWandererB + (((RotL64(aCross, 24U) + aOrbiterI) + RotL64(aOrbiterD, 5U)) + aNonceWordK);
            //
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 20U));
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererC);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + RotL64(aWandererA, 13U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ aNonceWordB;
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 21035U)) & S_BLOCK1], 52U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 18432U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18327U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((aIndex + 20160U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 58U) ^ RotL64(aIngress, 41U)) + (RotL64(aPrevious, 11U) + RotL64(aCarry, 23U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = ((aWandererG + RotL64(aCross, 60U)) + RotL64(aCarry, 27U)) + 380024772508948442U;
            aOrbiterH = ((aWandererK + RotL64(aIngress, 47U)) + 7649029098162567210U) + aNonceWordP;
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 5U)) + RotL64(aCarry, 57U)) + 5329304598870421851U;
            aOrbiterF = ((aWandererA + RotL64(aScatter, 23U)) + 12306118665045151326U) + aOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = (aWandererB + RotL64(aPrevious, 11U)) + 960751560457324256U;
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 29U)) + RotL64(aCarry, 37U)) + 3244070254386191876U;
            aOrbiterC = ((aWandererD + RotL64(aCross, 38U)) + 15733408571609521746U) + aOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = (aWandererC + RotL64(aScatter, 19U)) + 17623448932647018544U;
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 43U)) + 8787759896149035829U) + aNonceWordM;
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 14741681792348288162U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 8801731213568307302U;
            aOrbiterB = RotL64((aOrbiterB * 12127126999570616489U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 9872248187499779222U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 15407371518644528235U) ^ aOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1245102406469471673U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 4242060317152943062U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 9942784962409917541U;
            aOrbiterF = RotL64((aOrbiterF * 888649755587764533U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 7296348796484458631U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 15061417216070157797U;
            aOrbiterH = RotL64((aOrbiterH * 10349554676953256231U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 3233185810644297433U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 9241229457641024287U;
            aOrbiterK = RotL64((aOrbiterK * 2728237515724597517U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 8464051359381554575U) + aOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 3307872165699029375U;
            aOrbiterJ = RotL64((aOrbiterJ * 4859663401033023433U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 5482617843966711997U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 4442149210462943872U) ^ aNonceWordF;
            aOrbiterC = RotL64((aOrbiterC * 8979352218576515647U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 10591636597580147381U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 14925122230279312217U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15038171961638724013U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 9772367878232735350U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 15800661165607190092U;
            aOrbiterG = RotL64((aOrbiterG * 10493976952980533589U), 27U);
            //
            aIngress = RotL64(aOrbiterG, 26U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 3U));
            aIngress = aIngress + (RotL64(aOrbiterC, 35U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterD, 13U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterJ, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aScatter, 11U) + aOrbiterH) + RotL64(aOrbiterB, 29U)) + aNonceWordL);
            aWandererC = aWandererC ^ ((RotL64(aCross, 18U) + aOrbiterF) + RotL64(aOrbiterH, 46U));
            aWandererH = aWandererH + ((RotL64(aIngress, 5U) + RotL64(aOrbiterB, 11U)) + aOrbiterC);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 29U) + aOrbiterE) + RotL64(aOrbiterK, 37U)) + aNonceWordK);
            aWandererG = aWandererG + (((RotL64(aScatter, 43U) + RotL64(aOrbiterC, 19U)) + aOrbiterJ) + RotL64(aCarry, 29U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 47U) + aOrbiterK) + RotL64(aOrbiterF, 24U)) + aWandererUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 39U) + RotL64(aOrbiterJ, 53U)) + aOrbiterD) + aNonceWordE);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 51U) + aOrbiterG) + RotL64(aOrbiterC, 57U)) + aWandererUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 58U) + aOrbiterD) + RotL64(aOrbiterF, 41U)) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + (RotL64(aWandererA, 50U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererJ, 19U);
            aCarry = aCarry + RotL64(aIngress, 44U);
            aCarry = aCarry ^ aNonceWordJ;
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 30642U)) & S_BLOCK1], 46U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31017U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 31439U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 29533U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aIngress, 53U)) ^ (RotL64(aCross, 23U) + RotL64(aPrevious, 36U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererG + RotL64(aScatter, 34U)) + 8506388683755208267U;
            aOrbiterB = ((aWandererF + RotL64(aIngress, 39U)) + RotL64(aCarry, 57U)) + 2179323259055019735U;
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 5U)) + 3345902531140983016U) + aOrbiterAssignSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = (aWandererE + RotL64(aCross, 29U)) + 17456139311481306584U;
            aOrbiterC = ((aWandererK + RotL64(aIngress, 11U)) + 14587864088462311164U) + aNonceWordF;
            aOrbiterE = (aWandererI + RotL64(aScatter, 57U)) + 13178947246650647057U;
            aOrbiterD = (((aWandererB + RotL64(aCross, 51U)) + RotL64(aCarry, 13U)) + 12866578138946916962U) + aOrbiterAssignSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 21U)) + RotL64(aCarry, 41U)) + 13098524333655118173U;
            aOrbiterF = (aWandererH + RotL64(aScatter, 46U)) + 15451329483787541982U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 9494299579678389385U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterI) ^ 15581954810375490643U) ^ aOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterG = RotL64((aOrbiterG * 13670002280188424825U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 4487042505730624892U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 2774455928791636186U;
            aOrbiterC = RotL64((aOrbiterC * 15847933919136777451U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 12435319582397755819U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 10077180055177766823U;
            aOrbiterD = RotL64((aOrbiterD * 3924363471701748703U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 10391963896910956455U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 6149237416725301794U;
            aOrbiterI = RotL64((aOrbiterI * 10115917698918612823U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 15673402771629639978U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 14729117178956592426U;
            aOrbiterH = RotL64((aOrbiterH * 9070464269215820531U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 14492001279368870240U) + aOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 6278248084483259952U;
            aOrbiterE = RotL64((aOrbiterE * 16731228350971263873U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 15727518866499740411U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 8652631010810965473U) ^ aNonceWordN;
            aOrbiterJ = RotL64((aOrbiterJ * 9508484121620912715U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 13660890300188313775U) + aNonceWordH;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 14699253534935936300U) ^ aOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3978135617259934869U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 1621689916308271346U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 5651399428852950385U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12220143634120124133U), 43U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterE, 53U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 13U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterD, 40U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 3U));
            aIngress = aIngress + RotL64(aOrbiterC, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aIngress, 58U) + aOrbiterF) + RotL64(aOrbiterB, 22U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterC, 29U)) + aOrbiterH) + aNonceWordE);
            aWandererB = aWandererB + (((RotL64(aScatter, 35U) + RotL64(aOrbiterB, 51U)) + aOrbiterD) + RotL64(aCarry, 29U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterH, 47U)) + aOrbiterF);
            aWandererE = aWandererE + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterG, 11U)) + aOrbiterI) + aWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterH, 35U)) + aOrbiterI) + aWandererUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 54U) + aOrbiterG) + RotL64(aOrbiterB, 5U)) + RotL64(aCarry, 11U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 19U) + aOrbiterJ) + RotL64(aOrbiterD, 39U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 41U) + aOrbiterB) + RotL64(aOrbiterE, 18U)) + aNonceWordI);
            //
            aCarry = aCarry + (RotL64(aWandererH, 39U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 27U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererI, 50U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererK, 13U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ aNonceWordO;
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

void TwistExpander_Tennis_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x8E91BDFB3BF08E03ULL + 0xB746919B67D43F86ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xCFA43519508151EDULL + 0xB6890FA5369D0401ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x813E70D227A44587ULL + 0xF634452E015235C6ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x9BFC804ABF9FEB5FULL + 0xFFE86286AAB0F66EULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xA07904D50CF21EF5ULL + 0xE619EEE073A84869ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xCD2D86107C389DABULL + 0xCB60117E9A572212ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xF95798935DC688E1ULL + 0xFC1AEDFE96FC9F06ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xE8EF408A52B5381DULL + 0xAA827D246C27704AULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xC686C3C97F2A0DCFULL + 0xEB0A10F6347213EAULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xE0CA7CEC35911C37ULL + 0xA6F9ED172FFC9228ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xE371111FD749D871ULL + 0xFDFDB3CDFDBEE6FBULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xEE329782DED6E513ULL + 0xA0E7388C7C3EB2F1ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x83DBB7A50FC0431DULL + 0xC316657041D7BDEAULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xCFEE7DB65DA5570BULL + 0xD328936618585CE7ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x9A4024771BD7FDCBULL + 0x900901AA9B202BA1ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xE669702CB75F834FULL + 0xDC662E792AB2BED1ULL);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 3542U)) & S_BLOCK1], 24U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 962U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 5888U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneA[((aIndex + 5889U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 34U) ^ RotL64(aCross, 57U)) + (RotL64(aPrevious, 21U) ^ RotL64(aCarry, 5U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 29U)) + RotL64(aCarry, 27U)) + 2177539223979303669U;
            aOrbiterF = ((aWandererA + RotL64(aCross, 51U)) + RotL64(aCarry, 41U)) + 3962004686551521471U;
            aOrbiterB = ((aWandererB + RotL64(aScatter, 3U)) + 8457602312617147662U) + aOrbiterAssignSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterC = ((((aWandererG + RotL64(aIngress, 40U)) + RotL64(aCarry, 53U)) + 18011802451816510632U) + aOrbiterAssignSaltA[((aIndex + 26U)) & S_SALT1]) + aNonceWordB;
            aOrbiterK = (aWandererE + RotL64(aCross, 21U)) + 9046101759168876832U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 11135620637431969597U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 15913029940697999701U;
            aOrbiterB = RotL64((aOrbiterB * 646524659942693491U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 16304193109948135982U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 13208892298820080981U) ^ aOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15093751072618884859U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 4182377898949419225U) + aNonceWordP;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 13970137023071326151U;
            aOrbiterC = RotL64((aOrbiterC * 9075061559681739865U), 57U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterE) + 8402396284835248583U) + aOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1]) + aNonceWordK;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 8859190834060657829U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13552418608113716117U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 9760005337757990392U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 14108277760135744897U) ^ aOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4474681104256093885U), 11U);
            //
            aIngress = RotL64(aOrbiterF, 6U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + RotL64(aOrbiterE, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterK, 19U)) + aOrbiterE) + aNonceWordD);
            aWandererJ = aWandererJ + (((((RotL64(aCross, 27U) + aOrbiterK) + RotL64(aOrbiterB, 11U)) + RotL64(aCarry, 43U)) + aNonceWordM) + aWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 60U) + RotL64(aOrbiterE, 51U)) + aOrbiterC);
            aWandererB = aWandererB + (((((RotL64(aScatter, 19U) + RotL64(aOrbiterF, 27U)) + aOrbiterK) + RotL64(aCarry, 23U)) + aNonceWordI) + aWandererUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterB, 60U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 24U));
            aCarry = aCarry + RotL64(aWandererE, 43U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ aNonceWordG;
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 12100U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneD[((aIndex + 15838U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 9649U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneB[((aIndex + 15267U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 47U) + RotL64(aIngress, 19U)) ^ (RotL64(aPrevious, 35U) ^ RotL64(aCarry, 60U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (((aWandererH + RotL64(aScatter, 22U)) + RotL64(aCarry, 19U)) + 13854738573712660276U) + aOrbiterAssignSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = ((aWandererK + RotL64(aCross, 3U)) + RotL64(aCarry, 57U)) + 16835460633412286294U;
            aOrbiterB = ((((aWandererD + RotL64(aIngress, 43U)) + RotL64(aCarry, 37U)) + 6785859293758091931U) + aOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordF;
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 11U)) + 126317283127992659U) + aNonceWordC;
            aOrbiterE = (aWandererE + RotL64(aScatter, 53U)) + 7568963536291415413U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 12294016745653004819U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 18269588932920281147U) ^ aNonceWordO;
            aOrbiterB = RotL64((aOrbiterB * 9031152619272892317U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 5872406424994751026U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 7764434758831474129U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3772146788188420071U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 4804168969415573371U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 959601763507651280U;
            aOrbiterK = RotL64((aOrbiterK * 4647396592804833217U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 9257644462479293048U) + aOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 14332699366894494579U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8829304078930625541U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 10487012596470786004U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 612729229562321440U;
            aOrbiterD = RotL64((aOrbiterD * 11380387280507726003U), 5U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterI, 39U);
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterD, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aScatter, 51U) + aOrbiterI) + RotL64(aOrbiterD, 60U)) + aWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 37U) + aOrbiterI) + RotL64(aOrbiterK, 13U));
            aWandererI = aWandererI + (((RotL64(aCross, 23U) + aOrbiterB) + RotL64(aOrbiterE, 27U)) + RotL64(aCarry, 29U));
            aWandererE = aWandererE ^ ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterB, 5U)) + aOrbiterD) + aNonceWordH) + aWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 4U) + aOrbiterE) + RotL64(aOrbiterI, 41U)) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererH);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + RotL64(aWandererE, 29U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 24414U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((aIndex + 24095U)) & S_BLOCK1], 30U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 20386U)) & S_BLOCK1], 28U) ^ RotL64(aOperationLaneC[((aIndex + 20043U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 12U) + RotL64(aCross, 43U)) ^ (RotL64(aCarry, 57U) + RotL64(aPrevious, 29U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((((aWandererK + RotL64(aCross, 43U)) + RotL64(aCarry, 43U)) + 1898718075389870739U) + aOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1]) + aNonceWordA;
            aOrbiterA = (aWandererG + RotL64(aScatter, 13U)) + 5631794889237247403U;
            aOrbiterB = ((aWandererC + RotL64(aIngress, 24U)) + RotL64(aCarry, 29U)) + 18219714659484524607U;
            aOrbiterG = (((aWandererA + RotL64(aPrevious, 53U)) + RotL64(aCarry, 57U)) + 15419581386225732921U) + aOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = (aWandererD + RotL64(aIngress, 5U)) + 9125575431710198210U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 12205871520544965505U) + aOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 7617534300497343422U;
            aOrbiterB = RotL64((aOrbiterB * 10052675719887595625U), 5U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterD) + 18017579105368135814U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordL;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 10693882161946020042U;
            aOrbiterA = RotL64((aOrbiterA * 2326507900303932855U), 37U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 11669615701700895306U) + aOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 11045110212889232165U;
            aOrbiterD = RotL64((aOrbiterD * 5965171269273719849U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 18019107802806469913U) + aOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 12315940560472528716U) ^ aNonceWordD;
            aOrbiterG = RotL64((aOrbiterG * 4505122470351404065U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 4899009736070044310U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 17412253404253730364U;
            aOrbiterF = RotL64((aOrbiterF * 10791901166391946485U), 27U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterB, 13U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 53U));
            aIngress = aIngress + RotL64(aOrbiterD, 28U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aScatter, 21U) + aOrbiterD) + RotL64(aOrbiterG, 57U)) + aWandererUpdateSaltE[((aIndex + 26U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterA, 44U)) + aOrbiterB) + RotL64(aCarry, 41U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 56U) + RotL64(aOrbiterG, 21U)) + aOrbiterB) + aWandererUpdateSaltB[((aIndex + 20U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aIngress, 35U) + aOrbiterF) + RotL64(aOrbiterB, 35U)) + RotL64(aCarry, 53U)) + aNonceWordE);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterF, 5U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 21U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + RotL64(aWandererG, 11U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ aNonceWordE;
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 31835U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneB[((aIndex + 27114U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26675U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 26281U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 43U) ^ RotL64(aPrevious, 57U)) ^ (RotL64(aCross, 10U) + RotL64(aIngress, 27U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = ((((aWandererA + RotL64(aPrevious, 5U)) + RotL64(aCarry, 39U)) + 9446153639709651566U) + aOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordG;
            aOrbiterB = (((aWandererG + RotL64(aIngress, 28U)) + RotL64(aCarry, 53U)) + 10550762260670758167U) + aOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = ((aWandererE + RotL64(aCross, 13U)) + 7062634922142578383U) + aNonceWordM;
            aOrbiterK = (((aWandererF + RotL64(aScatter, 47U)) + RotL64(aCarry, 23U)) + 9178499097812764515U) + aNonceWordD;
            aOrbiterA = (aWandererD + RotL64(aCross, 39U)) + 6887103379773525538U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 6239750312052010257U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 17645022614523287959U;
            aOrbiterI = RotL64((aOrbiterI * 14448140327044053545U), 47U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterA) + 3639618183259408272U) + aOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1]) + aNonceWordB;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 3131737117548745095U;
            aOrbiterG = RotL64((aOrbiterG * 6585057380704940395U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 7253994382396406554U) + aOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 15217993711938379561U) ^ aNonceWordF;
            aOrbiterK = RotL64((aOrbiterK * 17853313384747259923U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 12594152227603630033U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 11250170200489647869U;
            aOrbiterB = RotL64((aOrbiterB * 546800378327864723U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 12936942656624279424U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 10990736056052106149U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7123916809953459187U), 21U);
            //
            aIngress = RotL64(aOrbiterB, 11U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterA, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aPrevious, 5U) + aOrbiterB) + RotL64(aOrbiterI, 47U)) + RotL64(aCarry, 51U)) + aNonceWordL);
            aWandererD = aWandererD ^ ((((RotL64(aScatter, 29U) + aOrbiterG) + RotL64(aOrbiterK, 19U)) + aNonceWordE) + aWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 58U) + aOrbiterK) + RotL64(aOrbiterA, 29U)) + RotL64(aCarry, 23U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 39U) + aOrbiterG) + RotL64(aOrbiterB, 37U)) + aNonceWordO);
            aWandererE = aWandererE + (((RotL64(aScatter, 21U) + RotL64(aOrbiterK, 4U)) + aOrbiterB) + aWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 41U));
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererD, 19U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ aNonceWordF;
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

void TwistExpander_Tennis_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x998A3BD1E5C61BD1ULL + 0xDE14991F2897318CULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x927B66D3EE97FBFFULL + 0xF72E814CF08374DBULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x9A6BB3F36F724DFDULL + 0xB8FDB10ABA96651CULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xFE41C4F66E0E7D71ULL + 0x966B7C46CE95B8CEULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xC9C15575909519E3ULL + 0xA0A448EA1B78DA06ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xD66BB24156223023ULL + 0xC1DEE40F52EE9ACEULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xC86DBF4A5F35D051ULL + 0xDCF7A6E5B1B24902ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xCCD2FBFD579BCA1FULL + 0xD52AC32749431A85ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xDC382A967F78D2A9ULL + 0xA2E078925B66F3E6ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x9852454073245E9FULL + 0xD0F7FBA8A6F97C4AULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xF163908D648138BFULL + 0xC9F8455649D6D7C3ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x993C7FFF6882C183ULL + 0xCE5058DE09071DD1ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x8FB6690C9B091F13ULL + 0xDE4C12BFA2C7D55DULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x969AD6E5A024664BULL + 0xD8CA456AED711F36ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xD617420F794755F1ULL + 0xEA3D3781EE996AB0ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xAFFD2C21AEA5796DULL + 0xFAE081A5BAB7F927ULL);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 5087U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 6062U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 3026U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneA[((aIndex + 5501U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCross, 10U)) ^ (RotL64(aPrevious, 53U) + RotL64(aCarry, 29U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((aWandererF + RotL64(aIngress, 3U)) + 6068543441070417854U) + aOrbiterAssignSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = ((aWandererG + RotL64(aPrevious, 53U)) + 2995980468193441856U) + aNonceWordM;
            aOrbiterK = (aWandererD + RotL64(aScatter, 14U)) + 18020277482171594003U;
            aOrbiterC = (((aWandererJ + RotL64(aCross, 35U)) + RotL64(aCarry, 13U)) + 4293807434721230702U) + aNonceWordA;
            aOrbiterD = ((aWandererB + RotL64(aIngress, 43U)) + RotL64(aCarry, 27U)) + 7980599111583893156U;
            aOrbiterJ = (((aWandererC + RotL64(aPrevious, 23U)) + 8593141111851052016U) + aOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordC;
            aOrbiterG = ((aWandererK + RotL64(aScatter, 29U)) + RotL64(aCarry, 43U)) + 5903487523900084325U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 15112035513447930209U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 9854037263057006439U;
            aOrbiterK = RotL64((aOrbiterK * 396276470208637283U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 16759760289688823193U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 12622628933030601390U;
            aOrbiterD = RotL64((aOrbiterD * 2151912984825538321U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 1264668857268123425U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 16302812053619101593U;
            aOrbiterJ = RotL64((aOrbiterJ * 18291400055836111547U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 16087995784896123610U) + aOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 7970269262800468363U;
            aOrbiterG = RotL64((aOrbiterG * 14924752223305807461U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 5331477046030959632U) + aNonceWordN;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 16534913204255550893U) ^ aOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1013433634373673565U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 11042821902537871209U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 8069677512345031660U) ^ aNonceWordI;
            aOrbiterC = RotL64((aOrbiterC * 13622218526054132397U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 5737130058129936372U) + aOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 1076627182956662997U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14342191224014199929U), 51U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterD, 60U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 5U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + RotL64(aOrbiterK, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 43U) + aOrbiterK) + RotL64(aOrbiterC, 11U));
            aWandererK = aWandererK + (((((RotL64(aScatter, 10U) + aOrbiterK) + RotL64(aOrbiterA, 47U)) + RotL64(aCarry, 37U)) + aNonceWordO) + aWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterG, 38U)) + aOrbiterA);
            aWandererB = aWandererB + ((RotL64(aCross, 29U) + RotL64(aOrbiterK, 3U)) + aOrbiterJ);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterI, 57U)) + aOrbiterD);
            aWandererF = aWandererF + (((((RotL64(aPrevious, 51U) + RotL64(aOrbiterG, 21U)) + aOrbiterI) + RotL64(aCarry, 11U)) + aNonceWordG) + aWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterI, 29U)) + aOrbiterA) + aNonceWordH);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 46U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererF, 13U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordC);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10765U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 10614U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 11202U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 12331U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 56U) + RotL64(aPrevious, 21U)) ^ (RotL64(aCarry, 5U) + RotL64(aIngress, 43U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (((aWandererD + RotL64(aCross, 58U)) + RotL64(aCarry, 53U)) + 9914837590440975587U) + aNonceWordD;
            aOrbiterA = (aWandererC + RotL64(aScatter, 27U)) + 6706125076401958051U;
            aOrbiterF = ((((aWandererF + RotL64(aIngress, 37U)) + RotL64(aCarry, 29U)) + 16570817772679258409U) + aOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordM;
            aOrbiterB = (aWandererJ + RotL64(aPrevious, 13U)) + 6843705658115186948U;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 47U)) + 16099930446791572351U) + aOrbiterAssignSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterC = (aWandererB + RotL64(aCross, 5U)) + 5420550009556030459U;
            aOrbiterH = (((aWandererG + RotL64(aScatter, 19U)) + RotL64(aCarry, 13U)) + 5729549069420177477U) + aNonceWordJ;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 15590601126188675834U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 13044027390998620029U;
            aOrbiterF = RotL64((aOrbiterF * 16845199115313444123U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 11068338135659636772U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 6584988841809544332U;
            aOrbiterJ = RotL64((aOrbiterJ * 1683336180438945439U), 5U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterC) + 8516813219883915404U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordN;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 10647314042912492785U;
            aOrbiterB = RotL64((aOrbiterB * 15559481057047148785U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 201691689889605304U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 15512161798401184003U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11473219183982564709U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 3883760518944464145U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 13861805129175491145U;
            aOrbiterK = RotL64((aOrbiterK * 17194438894492581181U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 12019138626550801486U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 13030350224959652248U) ^ aOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11724200983306280107U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 2643807255422544248U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 4127143302485631794U) ^ aNonceWordG;
            aOrbiterH = RotL64((aOrbiterH * 5441038881111578487U), 29U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterC, 23U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + (RotL64(aOrbiterH, 29U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterF, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((((RotL64(aPrevious, 11U) + RotL64(aOrbiterK, 18U)) + aOrbiterA) + RotL64(aCarry, 29U)) + aNonceWordA) + aWandererUpdateSaltA[((aIndex + 11U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 54U) + aOrbiterK) + RotL64(aOrbiterB, 57U)) + aNonceWordL);
            aWandererB = aWandererB + (((RotL64(aScatter, 35U) + RotL64(aOrbiterH, 41U)) + aOrbiterF) + aNonceWordB);
            aWandererC = aWandererC ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterH, 29U)) + aOrbiterK) + aWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 19U) + RotL64(aOrbiterA, 11U)) + aOrbiterJ);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterH, 35U)) + aOrbiterC);
            aWandererF = aWandererF + (((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterC, 47U)) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 58U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 41U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererC, 47U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ aNonceWordK;
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 21258U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 21202U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 21037U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneC[((aIndex + 17751U)) & S_BLOCK1], 44U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aPrevious, 39U)) ^ (RotL64(aCross, 24U) ^ RotL64(aIngress, 11U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererB + RotL64(aPrevious, 35U)) + 13333509828310369865U;
            aOrbiterH = ((aWandererA + RotL64(aScatter, 29U)) + 7645352517103840797U) + aOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 21U)) + 5310766306660062655U) + aOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = (aWandererG + RotL64(aCross, 11U)) + 5165635069832352932U;
            aOrbiterI = ((aWandererE + RotL64(aScatter, 47U)) + RotL64(aCarry, 57U)) + 15684141764734281849U;
            aOrbiterK = ((aWandererH + RotL64(aIngress, 3U)) + RotL64(aCarry, 5U)) + 3327963374225061738U;
            aOrbiterC = (((aWandererC + RotL64(aCross, 54U)) + RotL64(aCarry, 39U)) + 8625811794878848871U) + aNonceWordA;
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 7598657468430485291U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 2881171216276746485U) ^ aNonceWordH;
            aOrbiterG = RotL64((aOrbiterG * 3331350584102843605U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 10237691227222918101U) + aOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 6419254255884834497U;
            aOrbiterH = RotL64((aOrbiterH * 3816625473642865305U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 4238455444646479956U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 14936613353493061492U) ^ aOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3544216916806292273U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 15324699725208372627U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 9506640480601832011U;
            aOrbiterA = RotL64((aOrbiterA * 12819564111348390227U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 3709149613660215641U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 1724290199312754307U;
            aOrbiterI = RotL64((aOrbiterI * 12597580418257897965U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 13191172833570139194U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 3686087945377837886U;
            aOrbiterK = RotL64((aOrbiterK * 10883609557429936283U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 10418330386245397022U) + aOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 5383531313632347245U;
            aOrbiterC = RotL64((aOrbiterC * 2987755379396160073U), 13U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterC, 51U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 11U));
            aIngress = aIngress + (RotL64(aOrbiterK, 43U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterG, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aCross, 5U) + aOrbiterC) + RotL64(aOrbiterK, 51U)) + RotL64(aCarry, 39U)) + aWandererUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 20U) + aOrbiterK) + RotL64(aOrbiterI, 30U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterE, 37U)) + aOrbiterI);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterE, 11U)) + aOrbiterG);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 27U) + aOrbiterG) + RotL64(aOrbiterH, 19U)) + RotL64(aCarry, 11U)) + aNonceWordL);
            aWandererE = aWandererE ^ (((RotL64(aCross, 11U) + aOrbiterH) + RotL64(aOrbiterE, 57U)) + aWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 57U) + RotL64(aOrbiterK, 3U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererJ);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + (RotL64(aWandererG, 24U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 13U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordG);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 24759U)) & S_BLOCK1], 18U) ^ RotL64(aWorkLaneB[((aIndex + 27062U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25348U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 28996U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aIngress, 56U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 41U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 57U)) + 16651241552253078315U) + aOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 37U)) + RotL64(aCarry, 23U)) + 4558144676982478003U;
            aOrbiterF = (aWandererI + RotL64(aIngress, 21U)) + 8814884320080367550U;
            aOrbiterA = (((aWandererF + RotL64(aCross, 43U)) + RotL64(aCarry, 53U)) + 16011579668555672117U) + aNonceWordH;
            aOrbiterB = ((aWandererC + RotL64(aIngress, 5U)) + RotL64(aCarry, 35U)) + 4738918668759862438U;
            aOrbiterE = ((aWandererA + RotL64(aScatter, 12U)) + 12526083125540985108U) + aNonceWordL;
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 51U)) + 8048723561746000552U) + aOrbiterAssignSaltC[((aIndex + 22U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 1082218464034639039U) + aOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 8432043246965946816U;
            aOrbiterF = RotL64((aOrbiterF * 7801965585991025451U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 9982080524048636852U) + aNonceWordD;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 6720069955755215919U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1025046364205332059U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 1019035028070247757U) + aNonceWordK;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 7360619079463870467U) ^ aNonceWordF;
            aOrbiterJ = RotL64((aOrbiterJ * 6623074813047915863U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 10893918488381348474U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 1390297670907738019U;
            aOrbiterB = RotL64((aOrbiterB * 11909657437658597735U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 12512200589031203480U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 14741471280748399540U;
            aOrbiterC = RotL64((aOrbiterC * 3012135242889901095U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 8543897248359826770U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 8545972622733791272U;
            aOrbiterA = RotL64((aOrbiterA * 11793879362775346821U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 7049384618581928664U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 14730773807906925408U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10711566871536755073U), 27U);
            //
            aIngress = RotL64(aOrbiterB, 5U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterC, 37U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 27U));
            aIngress = aIngress + RotL64(aOrbiterJ, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 43U) + aOrbiterJ) + RotL64(aOrbiterC, 51U)) + RotL64(aCarry, 37U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterG, 41U)) + aOrbiterC);
            aWandererF = aWandererF + (((RotL64(aCross, 35U) + RotL64(aOrbiterA, 23U)) + aOrbiterF) + RotL64(aCarry, 21U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 13U) + aOrbiterG) + RotL64(aOrbiterE, 60U));
            aWandererD = aWandererD + ((((RotL64(aScatter, 19U) + aOrbiterC) + RotL64(aOrbiterE, 3U)) + aNonceWordE) + aWandererUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterG, 13U)) + aOrbiterB);
            aWandererA = aWandererA + (((RotL64(aCross, 54U) + aOrbiterE) + RotL64(aOrbiterA, 29U)) + aWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + (RotL64(aWandererA, 14U) ^ aWandererF);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + RotL64(aWandererD, 23U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ aNonceWordD;
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

void TwistExpander_Tennis_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xD226BECC7109E8DBULL + 0xDB17944FD755CCEEULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xBC636AFDC9B5CA97ULL + 0x87CA0CA9EF209FCBULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xC325D02E06E51795ULL + 0x9ABBDE8692E190AAULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xDFB3D324F0538BBFULL + 0xCB0675C7842446BFULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xB7F972F2E1E7F349ULL + 0xDD79CE968010F538ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x97F4E5188C2190F7ULL + 0xFAA8CDFB25606BBFULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x83ECDCF14B4FE8F1ULL + 0xDB7F8E7383699AD4ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xA435D06D6C294855ULL + 0xD5A290BB5F1C1014ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xCFCF2B22E685E485ULL + 0xE3A1BB1DC681AC31ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xD207AF779A2F00B3ULL + 0xD961D26A11FC32C2ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x9BE70D3F8F46217DULL + 0x946864C735B62AD4ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xF356718EEB1E5873ULL + 0x8D1993E0B2F4C0D0ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xC70F98EE1A0B9C43ULL + 0xD6025AAC835AADAEULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xF7041DFEF416372DULL + 0xE838FDCD98F537E6ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x8503346D6EF24751ULL + 0x87ED0A0930086D8EULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xEA952BA6C4591065ULL + 0xC6C69E327312EBBBULL);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 1412U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneC[((aIndex + 2548U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 182U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((aIndex + 3021U)) & S_BLOCK1], 40U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCarry, 26U)) + (RotL64(aPrevious, 43U) ^ RotL64(aCross, 5U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (aWandererC + RotL64(aScatter, 43U)) + 4773124477323378268U;
            aOrbiterG = (aWandererG + RotL64(aIngress, 20U)) + 16848723289435796005U;
            aOrbiterB = (((aWandererJ + RotL64(aCross, 5U)) + RotL64(aCarry, 5U)) + 13846642134917107058U) + aNonceWordP;
            aOrbiterC = (((aWandererH + RotL64(aPrevious, 29U)) + RotL64(aCarry, 21U)) + 6472057872482789939U) + aOrbiterAssignSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterE = ((((aWandererE + RotL64(aScatter, 57U)) + RotL64(aCarry, 39U)) + 2747019500690707226U) + aOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1]) + aNonceWordA;
            aOrbiterK = (aWandererD + RotL64(aCross, 37U)) + 9003965289739733880U;
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 13U)) + 3013390651936257377U) + aNonceWordK;
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 3331004709895625067U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 15355010435553517129U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8322759117004876831U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 7709870658004280052U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 13568728443963926564U;
            aOrbiterE = RotL64((aOrbiterE * 6736090830113688981U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 12409548853419307131U) + aOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 969183352023661537U) ^ aNonceWordF;
            aOrbiterK = RotL64((aOrbiterK * 5549220554838837145U), 53U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterK) + 15370309834426476775U) + aOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 3896803894396631184U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11018830202891911603U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 10848873633291935766U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 12885336509190543440U;
            aOrbiterA = RotL64((aOrbiterA * 1487357252619221365U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 8252290890093788010U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 9201553615601641350U;
            aOrbiterC = RotL64((aOrbiterC * 420321130559162915U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 14014209645503188472U) + aNonceWordO;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 4015071464301844550U;
            aOrbiterG = RotL64((aOrbiterG * 17444195018239904971U), 19U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterA, 11U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 19U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + RotL64(aOrbiterB, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aIngress, 10U) + aOrbiterH) + RotL64(aOrbiterG, 3U)) + RotL64(aCarry, 13U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterA, 35U)) + aOrbiterK);
            aWandererG = aWandererG + ((((RotL64(aCross, 29U) + RotL64(aOrbiterA, 47U)) + aOrbiterG) + RotL64(aCarry, 35U)) + aWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterE, 23U)) + aOrbiterG);
            aWandererD = aWandererD + (((RotL64(aCross, 57U) + RotL64(aOrbiterE, 41U)) + aOrbiterC) + aWandererUpdateSaltE[((aIndex + 16U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterG, 58U)) + aOrbiterK);
            aWandererF = aWandererF + (((RotL64(aScatter, 23U) + RotL64(aOrbiterB, 13U)) + aOrbiterA) + aNonceWordD);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererE);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + RotL64(aWandererF, 40U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordM);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 11054U)) & S_BLOCK1], 20U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 9301U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 8272U)) & S_BLOCK1], 22U) ^ RotL64(aWorkLaneB[((aIndex + 9038U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCross, 21U)) + (RotL64(aCarry, 4U) ^ RotL64(aPrevious, 41U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (((aWandererG + RotL64(aIngress, 29U)) + 15910560457440369082U) + aOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1]) + aNonceWordD;
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 41U)) + 17953072986407436888U) + aOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = (aWandererC + RotL64(aCross, 19U)) + 15446940721193538669U;
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 35U)) + RotL64(aCarry, 3U)) + 3020785262774422009U;
            aOrbiterI = (((aWandererE + RotL64(aCross, 57U)) + RotL64(aCarry, 35U)) + 7001288645424994404U) + aNonceWordJ;
            aOrbiterH = (aWandererA + RotL64(aPrevious, 51U)) + 13385250665458462689U;
            aOrbiterK = (((aWandererD + RotL64(aScatter, 4U)) + RotL64(aCarry, 47U)) + 4841895644623005949U) + aNonceWordL;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 13053476783239482065U) + aOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 641996979335975244U) ^ aNonceWordH;
            aOrbiterC = RotL64((aOrbiterC * 3697673197256549833U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 16211238020928688299U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 12715448751323279480U;
            aOrbiterB = RotL64((aOrbiterB * 2116880429675303291U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 17784406727699995290U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 16626339815786580778U;
            aOrbiterD = RotL64((aOrbiterD * 13940754474750138041U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 9035070625716345139U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 6085848172494001945U) ^ aNonceWordO;
            aOrbiterJ = RotL64((aOrbiterJ * 10405728912339646693U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 1177103851507561053U) + aOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 2281901691017816407U;
            aOrbiterI = RotL64((aOrbiterI * 3142197009403602497U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 9040984343694325070U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 13334258224023902365U;
            aOrbiterH = RotL64((aOrbiterH * 4782523727707164869U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 1079824790138592518U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 14024082692012948652U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3219489374333737903U), 13U);
            //
            aIngress = RotL64(aOrbiterD, 19U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterK, 56U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterI, 47U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterJ, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aCross, 54U) + RotL64(aOrbiterI, 37U)) + aOrbiterJ) + RotL64(aCarry, 43U)) + aWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterC, 57U)) + aOrbiterK);
            aWandererC = aWandererC + (((RotL64(aScatter, 29U) + RotL64(aOrbiterJ, 20U)) + aOrbiterD) + aWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterH, 3U)) + aOrbiterC) + aNonceWordP);
            aWandererA = aWandererA + ((RotL64(aCross, 35U) + RotL64(aOrbiterB, 27U)) + aOrbiterD);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 13U) + aOrbiterB) + RotL64(aOrbiterC, 13U));
            aWandererD = aWandererD + (((RotL64(aIngress, 19U) + aOrbiterD) + RotL64(aOrbiterC, 43U)) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 54U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererG, 29U);
            aCarry = aCarry + RotL64(aIngress, 50U);
            aCarry = aCarry ^ aNonceWordA;
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 21104U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneA[((aIndex + 18971U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 22832U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 21103U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 56U) ^ RotL64(aPrevious, 43U)) ^ (RotL64(aCarry, 27U) + RotL64(aIngress, 13U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (((aWandererD + RotL64(aCross, 3U)) + RotL64(aCarry, 37U)) + 3973833383430652211U) + aNonceWordL;
            aOrbiterC = (aWandererK + RotL64(aPrevious, 50U)) + 5760227042747169187U;
            aOrbiterA = (aWandererF + RotL64(aIngress, 11U)) + 4923009065139227286U;
            aOrbiterD = (aWandererJ + RotL64(aScatter, 57U)) + 1477807307009107590U;
            aOrbiterK = (((aWandererE + RotL64(aIngress, 43U)) + RotL64(aCarry, 21U)) + 5707194514329007301U) + aNonceWordF;
            aOrbiterJ = (((aWandererH + RotL64(aPrevious, 35U)) + RotL64(aCarry, 5U)) + 5340439728375269724U) + aOrbiterAssignSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = (((aWandererC + RotL64(aScatter, 29U)) + 17080457898946572387U) + aOrbiterAssignSaltF[((aIndex + 18U)) & S_SALT1]) + aNonceWordN;
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 281559150259472813U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 16160633048230910560U;
            aOrbiterA = RotL64((aOrbiterA * 16883442583309073785U), 29U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterG) + 9003989610509592121U) + aOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1]) + aNonceWordM;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 10579322462808454333U;
            aOrbiterC = RotL64((aOrbiterC * 100832431598087235U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 15059383289528723069U) + aNonceWordK;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 10417647757852880956U;
            aOrbiterG = RotL64((aOrbiterG * 1457919230286043137U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 14484665027393813330U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 12344463053485837974U;
            aOrbiterD = RotL64((aOrbiterD * 5762654194001525041U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 5826453246659297805U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 12547902286376986223U;
            aOrbiterK = RotL64((aOrbiterK * 2982850000322672789U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 9637855144278126174U) + aNonceWordP;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 2132744427444501938U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5911587798564836199U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 9248933938130311231U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 13274297928717090383U) ^ aOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2901398809555237563U), 41U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterK, 28U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 21U));
            aIngress = aIngress + (RotL64(aOrbiterA, 53U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterJ, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aCross, 11U) + RotL64(aOrbiterB, 41U)) + aOrbiterK);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterD, 60U)) + aOrbiterA) + aWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 60U) + aOrbiterA) + RotL64(aOrbiterB, 19U)) + RotL64(aCarry, 51U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterK, 13U)) + aOrbiterJ) + aNonceWordJ);
            aWandererE = aWandererE + ((((RotL64(aIngress, 23U) + RotL64(aOrbiterA, 27U)) + aOrbiterC) + RotL64(aCarry, 3U)) + aWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterG, 3U)) + aOrbiterD);
            aWandererC = aWandererC + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterA, 51U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererC, 54U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererE, 5U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererF, 29U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordO);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 25468U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneB[((aIndex + 30309U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29049U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 27032U)) & S_BLOCK1], 42U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 26U) + RotL64(aPrevious, 39U)) ^ (RotL64(aIngress, 51U) ^ RotL64(aCarry, 13U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = ((aWandererG + RotL64(aCross, 29U)) + RotL64(aCarry, 53U)) + 5173905450211892891U;
            aOrbiterG = (aWandererC + RotL64(aScatter, 47U)) + 3555542451908039957U;
            aOrbiterB = (aWandererJ + RotL64(aPrevious, 20U)) + 11559884700283861559U;
            aOrbiterA = (((aWandererD + RotL64(aIngress, 35U)) + 1352524329968738673U) + aOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordP;
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 11U)) + RotL64(aCarry, 13U)) + 8914206450420616349U;
            aOrbiterI = ((aWandererE + RotL64(aIngress, 3U)) + 2251523378498463946U) + aOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = ((aWandererI + RotL64(aScatter, 53U)) + RotL64(aCarry, 27U)) + 9541575923299247038U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 1239854507907214595U) + aOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 17698101462598498934U) ^ aOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2304948713665996433U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 12305566971683256060U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 13804545036303215569U;
            aOrbiterI = RotL64((aOrbiterI * 10359543704152744971U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 10239749097704329264U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 4212214906286320308U;
            aOrbiterG = RotL64((aOrbiterG * 3661436621615751071U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 12192418916967430783U) + aNonceWordL;
            aOrbiterF = (((aOrbiterF ^ aOrbiterB) ^ 4475514289326450361U) ^ aOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterF = RotL64((aOrbiterF * 17497164630368757887U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 17376102613298827459U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 18129393209955439341U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6404089025014118979U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 4014763724300253568U) + aNonceWordB;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 17325007199676828814U;
            aOrbiterA = RotL64((aOrbiterA * 1420888274815627083U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 15480474849292388685U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 14357924730184375449U;
            aOrbiterC = RotL64((aOrbiterC * 16723492259068034209U), 21U);
            //
            aIngress = RotL64(aOrbiterC, 3U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterJ, 43U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 19U));
            aIngress = aIngress + RotL64(aOrbiterI, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 35U) + aOrbiterI) + RotL64(aOrbiterA, 29U)) + aNonceWordO) + aWandererUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 60U) + RotL64(aOrbiterB, 13U)) + aOrbiterG);
            aWandererE = aWandererE + ((((RotL64(aCross, 3U) + RotL64(aOrbiterC, 20U)) + aOrbiterJ) + RotL64(aCarry, 5U)) + aWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterA, 35U)) + aOrbiterG);
            aWandererG = aWandererG + (((RotL64(aScatter, 19U) + aOrbiterF) + RotL64(aOrbiterB, 43U)) + RotL64(aCarry, 43U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterC, 53U)) + aOrbiterG) + aNonceWordH);
            aWandererI = aWandererI + (((RotL64(aIngress, 13U) + aOrbiterF) + RotL64(aOrbiterI, 3U)) + aNonceWordG);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + (RotL64(aWandererC, 6U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererE, 43U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordB);
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

void TwistExpander_Tennis_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x94F3D1201BC0959DULL + 0x8AFA5846F203F7C7ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xEF682A35523DB92DULL + 0x976D12C849A8ACB9ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xCA8317673F4CE52FULL + 0xD9EA4E17E46A0760ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xE9288F7D91E3A1ABULL + 0xC9118DF8E092CDFFULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xD40886BA44EC2CB3ULL + 0xC210B78E48B9CDB5ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x98B43633DF80C3E5ULL + 0xB1ABD29DA05244FFULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xDAAE024F91D7E8FFULL + 0xFB8850A23616DD79ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x874687A1EBFFFC91ULL + 0xEB53F490B88B91CDULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xA6881B000396CE2FULL + 0x8F5C04938BD046FFULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xA0690D535D6438C7ULL + 0xD67B686069C68A5CULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xEEA2ADA3C716DAEBULL + 0xCDF4C6D16016A683ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xA858D7DD5799B04BULL + 0x8F79CF8698F39129ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xF173DA4F7FCA54B9ULL + 0xA562E23758E72B0FULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x8AA64BAFC6328999ULL + 0x964CA8C1541CB32EULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xFE778EBFC9B93635ULL + 0x9ECD2126C8931A7AULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x8F5CAFB2641825B5ULL + 0xFBD6738105BB7184ULL);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 2575U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4932U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 6313U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneA[((aIndex + 1123U)) & S_BLOCK1], 34U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 47U) + RotL64(aIngress, 22U)) ^ (RotL64(aPrevious, 35U) + RotL64(aCarry, 3U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererD + RotL64(aScatter, 53U)) + RotL64(aCarry, 43U)) + 10812151398716051703U;
            aOrbiterE = (aWandererI + RotL64(aPrevious, 36U)) + 18202551453336003710U;
            aOrbiterA = ((((aWandererE + RotL64(aCross, 3U)) + RotL64(aCarry, 13U)) + 9434410809101973752U) + aOrbiterAssignSaltF[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordO;
            aOrbiterC = (aWandererH + RotL64(aIngress, 23U)) + 12955829998028534045U;
            aOrbiterK = (aWandererJ + RotL64(aPrevious, 21U)) + 12271740641929640181U;
            aOrbiterG = ((aWandererG + RotL64(aIngress, 26U)) + RotL64(aCarry, 5U)) + 14009351527014534752U;
            aOrbiterD = (((aWandererA + RotL64(aCross, 41U)) + 4316296955679133450U) + aOrbiterAssignSaltB[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterJ = (aWandererK + RotL64(aScatter, 13U)) + 16473324966997442872U;
            aOrbiterF = (aWandererB + RotL64(aPrevious, 11U)) + 15735123324965019802U;
            aOrbiterH = (aWandererF + RotL64(aCross, 57U)) + 17656375090484080236U;
            aOrbiterI = (aWandererC + RotL64(aIngress, 47U)) + 16066325053456055298U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 12908968778503516903U) + aNonceWordL;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 12761433987676836197U;
            aOrbiterA = RotL64((aOrbiterA * 1023329467480907925U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 12737513138040664509U) + aOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 14535795767570998392U;
            aOrbiterG = RotL64((aOrbiterG * 15560519667062222269U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 14370908061811284364U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 7001358781208669795U;
            aOrbiterB = RotL64((aOrbiterB * 11641248025734015835U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 7298578161120090849U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 10498302152357484629U) ^ aNonceWordP;
            aOrbiterC = RotL64((aOrbiterC * 13144110412179037175U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 11447343228638006767U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 18284143620422655675U;
            aOrbiterD = RotL64((aOrbiterD * 572862190073605651U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 5918253208127360199U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 3910541329178205943U;
            aOrbiterF = RotL64((aOrbiterF * 4550654545328228103U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 10357053096941367910U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 5610891501128498748U;
            aOrbiterI = RotL64((aOrbiterI * 8676370811772047449U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 9049881176058575811U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 6307599924966452216U;
            aOrbiterE = RotL64((aOrbiterE * 5551444450572055895U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 17109966783467892046U) + aNonceWordC;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 11563095828344462249U;
            aOrbiterK = RotL64((aOrbiterK * 15463753739272001875U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 3739147427725509014U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 5324449517615050698U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5926079615575226853U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 5706251076252597592U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 10812151398716051703U) ^ aOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5666491216813197045U), 51U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterB, 27U);
            aIngress = aIngress + (RotL64(aOrbiterG, 6U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterI, 37U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterK, 53U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + RotL64(aOrbiterH, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterJ, 40U)) + aOrbiterD) + aWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 21U) + aOrbiterH) + RotL64(aOrbiterG, 3U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 19U) + aOrbiterG) + RotL64(aOrbiterC, 43U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterA, 47U)) + aOrbiterJ) + aWandererUpdateSaltA[((aIndex + 10U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterE, 53U)) + aOrbiterH);
            aWandererK = aWandererK + ((((RotL64(aCross, 38U) + aOrbiterH) + RotL64(aOrbiterK, 23U)) + RotL64(aCarry, 53U)) + aNonceWordA);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 51U) + aOrbiterC) + RotL64(aOrbiterI, 60U)) + aNonceWordD);
            aWandererF = aWandererF + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterJ, 35U)) + aOrbiterB);
            aWandererC = aWandererC ^ ((RotL64(aCross, 13U) + aOrbiterB) + RotL64(aOrbiterH, 21U));
            aWandererH = aWandererH + (((RotL64(aIngress, 43U) + RotL64(aOrbiterA, 57U)) + aOrbiterD) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 40U) + RotL64(aOrbiterF, 51U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 20U));
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererE);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 37U));
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererG, 51U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererF, 26U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordF);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 8459U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 14838U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15265U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 11805U)) & S_BLOCK1], 34U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 43U) + RotL64(aCross, 5U)) ^ (RotL64(aCarry, 19U) + RotL64(aPrevious, 56U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (aWandererI + RotL64(aIngress, 60U)) + 10404808878585437255U;
            aOrbiterF = (aWandererC + RotL64(aCross, 35U)) + 10587858736301591439U;
            aOrbiterJ = (aWandererH + RotL64(aScatter, 19U)) + 1430530909801644435U;
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 47U)) + RotL64(aCarry, 29U)) + 9090938022430118902U;
            aOrbiterH = (aWandererD + RotL64(aIngress, 3U)) + 12936604311751121235U;
            aOrbiterD = (aWandererE + RotL64(aCross, 14U)) + 1000583006020232032U;
            aOrbiterK = (((aWandererJ + RotL64(aPrevious, 39U)) + 12352532088997042232U) + aOrbiterAssignSaltA[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordI;
            aOrbiterG = (((aWandererA + RotL64(aScatter, 29U)) + RotL64(aCarry, 19U)) + 16723410947058502564U) + aOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = ((aWandererF + RotL64(aIngress, 41U)) + 16614089235313154270U) + aNonceWordG;
            aOrbiterI = (((aWandererG + RotL64(aCross, 53U)) + RotL64(aCarry, 41U)) + 4245553025593349277U) + aNonceWordE;
            aOrbiterE = (aWandererB + RotL64(aScatter, 43U)) + 3353146318549477494U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 5935727336135635196U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 10312187090293319667U;
            aOrbiterJ = RotL64((aOrbiterJ * 1395964500396711899U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 12192843181244744484U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 2542570124502586365U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17222847847573534963U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 3315472769469002444U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 17512858811783071174U;
            aOrbiterH = RotL64((aOrbiterH * 9070400454074283765U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 16633218007427888082U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 2502077714838858460U;
            aOrbiterK = RotL64((aOrbiterK * 970762420815997725U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 14792910273226469214U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 15739513291150783151U;
            aOrbiterA = RotL64((aOrbiterA * 11896279674116906915U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 2192903544350345992U) + aOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 844428341223009295U;
            aOrbiterC = RotL64((aOrbiterC * 4768368713974002539U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 2998511458298901402U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 7790789639864783373U) ^ aNonceWordF;
            aOrbiterB = RotL64((aOrbiterB * 9173097618440495497U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 4540735375055164995U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 13700342877362633034U;
            aOrbiterD = RotL64((aOrbiterD * 14730797752841670505U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 16966725424259324323U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 5945539295893015935U;
            aOrbiterG = RotL64((aOrbiterG * 12226268057062268981U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 12560355243513521281U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 2104086086480258265U) ^ aOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17989755118752755577U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 4476697099257280568U) + aNonceWordN;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 10404808878585437255U;
            aOrbiterE = RotL64((aOrbiterE * 6245415417832089357U), 21U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterB, 13U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 37U));
            aIngress = aIngress + (RotL64(aOrbiterF, 35U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + (RotL64(aOrbiterK, 39U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterG, 18U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aIngress, 11U) + aOrbiterB) + RotL64(aOrbiterE, 11U)) + aNonceWordP);
            aWandererI = aWandererI + ((RotL64(aCross, 13U) + aOrbiterI) + RotL64(aOrbiterD, 44U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 38U) + aOrbiterF) + RotL64(aOrbiterA, 37U)) + aNonceWordJ);
            aWandererH = aWandererH + ((RotL64(aScatter, 35U) + aOrbiterK) + RotL64(aOrbiterB, 5U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 23U) + aOrbiterB) + RotL64(aOrbiterF, 23U)) + aWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 5U) + RotL64(aOrbiterF, 21U)) + aOrbiterJ) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterG, 19U)) + aOrbiterH);
            aWandererB = aWandererB + ((RotL64(aPrevious, 53U) + aOrbiterC) + RotL64(aOrbiterA, 58U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterE, 13U)) + aOrbiterH);
            aWandererG = aWandererG + (((RotL64(aIngress, 42U) + aOrbiterA) + RotL64(aOrbiterE, 41U)) + RotL64(aCarry, 13U));
            aWandererA = aWandererA ^ ((((RotL64(aCross, 27U) + RotL64(aOrbiterI, 29U)) + aOrbiterK) + aNonceWordA) + aWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 10U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 27U));
            aCarry = aCarry + (RotL64(aWandererF, 41U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 20U));
            aCarry = aCarry + RotL64(aWandererK, 37U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordH);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 19033U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneA[((aIndex + 21100U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 23320U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneC[((aIndex + 22060U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aIngress, 3U)) + (RotL64(aPrevious, 36U) + RotL64(aCross, 21U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererK + RotL64(aScatter, 13U)) + 12131317914288566437U) + aNonceWordK;
            aOrbiterI = (((aWandererJ + RotL64(aPrevious, 47U)) + RotL64(aCarry, 57U)) + 5672805657999385496U) + aOrbiterAssignSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = ((aWandererE + RotL64(aCross, 29U)) + RotL64(aCarry, 51U)) + 3581710244233124197U;
            aOrbiterF = (aWandererI + RotL64(aIngress, 11U)) + 15251296040538489436U;
            aOrbiterD = (aWandererB + RotL64(aScatter, 18U)) + 11295008604679904153U;
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 39U)) + 2230897493419504490U) + aNonceWordC;
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 51U)) + RotL64(aCarry, 21U)) + 7109600123297458999U;
            aOrbiterH = (aWandererD + RotL64(aCross, 3U)) + 13119156643107683803U;
            aOrbiterG = (aWandererH + RotL64(aScatter, 37U)) + 14755160867807355250U;
            aOrbiterC = ((aWandererC + RotL64(aCross, 41U)) + 16829363373287496832U) + aNonceWordN;
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 58U)) + 16981122946707720883U) + aOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 8806000776958603317U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 16810923047720876014U;
            aOrbiterA = RotL64((aOrbiterA * 17872735050219539145U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 8129657889554436328U) + aOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 8653100378491974463U;
            aOrbiterB = RotL64((aOrbiterB * 11395283153912468661U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 17048985838727432415U) + aNonceWordF;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 10892675550889823573U;
            aOrbiterI = RotL64((aOrbiterI * 976298937314081913U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 15960158965421254346U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 12290011578634850001U;
            aOrbiterD = RotL64((aOrbiterD * 9280475585104357745U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 16265047040311479093U) + aNonceWordM;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 10312956912303656248U;
            aOrbiterH = RotL64((aOrbiterH * 3012584393253845131U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 16706890352221352779U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 10630955894218491929U;
            aOrbiterC = RotL64((aOrbiterC * 12675937483456206355U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 4009352551041162434U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 3043810773683888556U;
            aOrbiterK = RotL64((aOrbiterK * 4328135390387997315U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 1398071019814944785U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 16689766557488135301U;
            aOrbiterF = RotL64((aOrbiterF * 8403881916549404871U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 15934647144489136524U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 13521276033614992223U) ^ aOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 18003640895553609933U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 4281211055727414100U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 11848150507497406421U;
            aOrbiterG = RotL64((aOrbiterG * 1107789990317433481U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 12022829841608199449U) + aOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 12131317914288566437U;
            aOrbiterE = RotL64((aOrbiterE * 13275753083882829973U), 43U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterF, 60U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 43U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 53U));
            aIngress = aIngress + (RotL64(aOrbiterG, 5U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterD, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterC, 47U)) + aOrbiterB);
            aWandererB = aWandererB + ((((RotL64(aIngress, 23U) + RotL64(aOrbiterH, 5U)) + aOrbiterF) + RotL64(aCarry, 13U)) + aWandererUpdateSaltE[((aIndex + 18U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aCross, 27U) + aOrbiterF) + RotL64(aOrbiterA, 50U)) + aNonceWordL);
            aWandererH = aWandererH + ((RotL64(aScatter, 6U) + aOrbiterH) + RotL64(aOrbiterB, 3U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterF, 27U)) + aOrbiterB);
            aWandererG = aWandererG + ((RotL64(aCross, 53U) + RotL64(aOrbiterA, 29U)) + aOrbiterD);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 35U) + aOrbiterJ) + RotL64(aOrbiterG, 58U));
            aWandererK = aWandererK + ((((RotL64(aPrevious, 43U) + RotL64(aOrbiterC, 19U)) + aOrbiterK) + RotL64(aCarry, 39U)) + aWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 48U) + aOrbiterH) + RotL64(aOrbiterE, 13U)) + aNonceWordG);
            aWandererI = aWandererI + ((RotL64(aScatter, 51U) + RotL64(aOrbiterC, 35U)) + aOrbiterG);
            aWandererC = aWandererC ^ ((RotL64(aCross, 29U) + aOrbiterI) + RotL64(aOrbiterF, 37U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 26U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 37U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + RotL64(aWandererA, 4U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordB);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 31344U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneB[((aIndex + 29240U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 31248U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 26694U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 19U) ^ RotL64(aCarry, 53U)) + (RotL64(aPrevious, 36U) + RotL64(aCross, 5U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererE + RotL64(aIngress, 52U)) + 13854738573712660276U;
            aOrbiterF = ((((aWandererF + RotL64(aCross, 47U)) + RotL64(aCarry, 5U)) + 16835460633412286294U) + aOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordO;
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 27U)) + RotL64(aCarry, 35U)) + 6785859293758091931U;
            aOrbiterG = ((aWandererD + RotL64(aScatter, 41U)) + RotL64(aCarry, 51U)) + 126317283127992659U;
            aOrbiterC = (aWandererI + RotL64(aIngress, 39U)) + 7568963536291415413U;
            aOrbiterB = ((aWandererG + RotL64(aCross, 11U)) + 12294016745653004819U) + aOrbiterAssignSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = (aWandererC + RotL64(aPrevious, 13U)) + 18269588932920281147U;
            aOrbiterA = (aWandererA + RotL64(aScatter, 29U)) + 5872406424994751026U;
            aOrbiterI = (aWandererB + RotL64(aCross, 35U)) + 7764434758831474129U;
            aOrbiterH = (aWandererJ + RotL64(aIngress, 6U)) + 4804168969415573371U;
            aOrbiterE = (aWandererH + RotL64(aPrevious, 37U)) + 959601763507651280U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 9257644462479293048U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 14332699366894494579U;
            aOrbiterD = RotL64((aOrbiterD * 8829304078930625541U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 10487012596470786004U) + aOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 612729229562321440U;
            aOrbiterC = RotL64((aOrbiterC * 11380387280507726003U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 7845523921295625315U) + aNonceWordF;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 12742115479740024747U) ^ aOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15578543510683986421U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 10294667720904610944U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 14369711143154904567U;
            aOrbiterK = RotL64((aOrbiterK * 13753005602288309379U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 10918344717497681894U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 18136794828308636957U;
            aOrbiterA = RotL64((aOrbiterA * 17899418637978002409U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 14378638206724886404U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 7077588188450008059U;
            aOrbiterI = RotL64((aOrbiterI * 485375960462924335U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 8941870012851971932U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 15242087859620352399U;
            aOrbiterH = RotL64((aOrbiterH * 4963002810455992839U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 10395280254030875387U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 6826595516076975980U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6198886240333178001U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 10407910809564430664U) + aOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 6368255889263255730U;
            aOrbiterJ = RotL64((aOrbiterJ * 3809496492809859731U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 6365669830464231626U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 596785214258266904U;
            aOrbiterF = RotL64((aOrbiterF * 6338109335634389561U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 4807438574488830717U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 13854738573712660276U;
            aOrbiterG = RotL64((aOrbiterG * 6954368463489446551U), 35U);
            //
            aIngress = RotL64(aOrbiterI, 51U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 54U));
            aIngress = aIngress + (RotL64(aOrbiterB, 43U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterE, 35U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 21U));
            aIngress = aIngress + RotL64(aOrbiterG, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aCross, 51U) + RotL64(aOrbiterC, 41U)) + aOrbiterE);
            aWandererH = aWandererH ^ ((((RotL64(aPrevious, 41U) + RotL64(aOrbiterC, 39U)) + aOrbiterB) + aNonceWordG) + aWandererUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 13U) + RotL64(aOrbiterA, 11U)) + aOrbiterF);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 5U) + aOrbiterF) + RotL64(aOrbiterI, 5U));
            aWandererD = aWandererD + ((((RotL64(aCross, 38U) + aOrbiterH) + RotL64(aOrbiterG, 27U)) + RotL64(aCarry, 3U)) + aWandererUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterH, 58U)) + aOrbiterI);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 43U) + RotL64(aOrbiterG, 51U)) + aOrbiterD) + RotL64(aCarry, 19U)) + aNonceWordI);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterI, 21U)) + aOrbiterB);
            aWandererB = aWandererB + (((RotL64(aCross, 11U) + aOrbiterJ) + RotL64(aOrbiterC, 35U)) + aNonceWordP);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 58U) + RotL64(aOrbiterE, 43U)) + aOrbiterD);
            aWandererF = aWandererF + ((RotL64(aScatter, 19U) + RotL64(aOrbiterK, 48U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 52U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 41U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 50U));
            aCarry = aCarry + RotL64(aWandererB, 27U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordK);
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

void TwistExpander_Tennis_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x878B228F479AFE77ULL + 0x8B919C8C4BE3DD93ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xA7EE771F146D2037ULL + 0xC1A29D2B25B96499ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xD7AE870D31ADD319ULL + 0xAA17F0EDE8A59E27ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xBD7B78533DAF76BDULL + 0xCBCA2627DD65B225ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x821D1006C0FEA02DULL + 0xAD3A6A397FB21114ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x86796F8F28CA09AFULL + 0xD87704B1AFD30257ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xE2879F91F306E1F7ULL + 0xC6DE2A265BEF0905ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xB0618E7EAEAF36C1ULL + 0x9B38D5C60309779DULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xFFD8D725D6933C35ULL + 0x84835CC5BC241D15ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xFC50CA986097BBC9ULL + 0xD2FCDC491F03970AULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xF3B985EEF9C070CFULL + 0xB5CFE34BA57D558AULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x991D08151061FA6DULL + 0x8C2CF03652FB5C79ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x89A689A626AB8D09ULL + 0xF258BD26BF671B97ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xD2F8DE9D70C91F89ULL + 0xE01545AD93165A00ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xD7AC5E1AD512FBB5ULL + 0xDB58A63D2B505384ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xB8DAB901DD8ED0DDULL + 0x9D1278E6D6F484E8ULL);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 4565U)) & S_BLOCK1], 36U) ^ RotL64(aOperationLaneC[((aIndex + 1603U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 3659U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 249U)) & S_BLOCK1], 50U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aPrevious, 57U)) + (RotL64(aCarry, 5U) ^ RotL64(aIngress, 44U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 19U)) + RotL64(aCarry, 29U)) + 6469584119078165548U;
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 43U)) + RotL64(aCarry, 39U)) + 14329756366517987910U;
            aOrbiterF = ((aWandererB + RotL64(aScatter, 58U)) + 12890831797059772123U) + aNonceWordN;
            aOrbiterD = (aWandererA + RotL64(aCross, 3U)) + 3164503807500018990U;
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 23U)) + 177531431387646836U;
            aOrbiterE = (aWandererK + RotL64(aIngress, 13U)) + 3167421392893561015U;
            aOrbiterH = (((aWandererD + RotL64(aCross, 47U)) + RotL64(aCarry, 3U)) + 2813174781844753460U) + aNonceWordA;
            aOrbiterI = ((aWandererF + RotL64(aScatter, 54U)) + 10953270419153249857U) + aOrbiterAssignSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 29U)) + 16911518309710356951U) + aOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 6616750447844893150U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 10276741398025985982U;
            aOrbiterF = RotL64((aOrbiterF * 6824712685896987133U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 6206043608461213208U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 12021552904553405793U;
            aOrbiterE = RotL64((aOrbiterE * 10023362889960174909U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 15283586234744144846U) + aOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 5923238786775948571U;
            aOrbiterI = RotL64((aOrbiterI * 8200882393521882651U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 11044014510971660078U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 9351141024085076044U;
            aOrbiterB = RotL64((aOrbiterB * 13316079344614432317U), 47U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterI) + 17703395981862992420U) + aOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1]) + aNonceWordD;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 10154548848376027087U;
            aOrbiterA = RotL64((aOrbiterA * 12324478347590509035U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 8836420852291617425U) + aOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 10193385413543886344U;
            aOrbiterD = RotL64((aOrbiterD * 824935982418585449U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 8248580084535685190U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 3910083671888152974U;
            aOrbiterH = RotL64((aOrbiterH * 17825311776715895927U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 12350341628569930642U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 2565977481575002842U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 18233446879833776677U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 9271041067874027417U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 14289254596554201861U) ^ aNonceWordF;
            aOrbiterG = RotL64((aOrbiterG * 7985522692852251413U), 27U);
            //
            aIngress = RotL64(aOrbiterH, 28U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 43U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + (RotL64(aOrbiterE, 35U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterI, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aIngress, 14U) + aOrbiterB) + RotL64(aOrbiterJ, 41U));
            aWandererA = aWandererA + (((RotL64(aScatter, 39U) + aOrbiterJ) + RotL64(aOrbiterI, 46U)) + RotL64(aCarry, 57U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterE, 37U)) + aOrbiterD) + aWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aCross, 29U) + RotL64(aOrbiterB, 19U)) + aOrbiterD);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 10U) + aOrbiterH) + RotL64(aOrbiterD, 51U));
            aWandererC = aWandererC + (((RotL64(aIngress, 23U) + aOrbiterG) + RotL64(aOrbiterJ, 27U)) + aNonceWordP);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterF, 6U)) + aOrbiterH) + aNonceWordM);
            aWandererD = aWandererD + ((((RotL64(aCross, 57U) + aOrbiterH) + RotL64(aOrbiterA, 13U)) + RotL64(aCarry, 35U)) + aWandererUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 5U) + aOrbiterA) + RotL64(aOrbiterF, 23U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + (RotL64(aWandererI, 41U) ^ aWandererF);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 10U));
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererG, 19U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordH);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 6495U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 9026U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 7080U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 10838U)) & S_BLOCK1], 50U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 13U) ^ RotL64(aIngress, 28U)) ^ (RotL64(aPrevious, 43U) + RotL64(aCross, 57U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (aWandererF + RotL64(aCross, 6U)) + 15045917390223766480U;
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 47U)) + RotL64(aCarry, 27U)) + 10763054007033668758U;
            aOrbiterH = ((aWandererD + RotL64(aScatter, 57U)) + RotL64(aCarry, 3U)) + 13190170142593666607U;
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 13U)) + RotL64(aCarry, 35U)) + 9657025731441167065U;
            aOrbiterI = (aWandererG + RotL64(aScatter, 23U)) + 11433367178975954211U;
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 43U)) + 17904920143996810366U) + aOrbiterAssignSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = (aWandererK + RotL64(aCross, 53U)) + 3244383020512113283U;
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 36U)) + 6538815775171139091U) + aNonceWordE;
            aOrbiterD = ((aWandererH + RotL64(aIngress, 29U)) + 7195368312757976343U) + aOrbiterAssignSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 18134430713910279374U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 6571776588427107976U;
            aOrbiterH = RotL64((aOrbiterH * 11916502085252589161U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 11830778129647517758U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 9793702760907767365U;
            aOrbiterI = RotL64((aOrbiterI * 4096246227968677179U), 23U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterI) + 2287235876793192036U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordK;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 8951959188326141794U;
            aOrbiterF = RotL64((aOrbiterF * 9968356718110753845U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 7583061790273240157U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 3571364625022806085U;
            aOrbiterE = RotL64((aOrbiterE * 6238360922735480669U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 13869345563551689212U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 277480328952975002U;
            aOrbiterD = RotL64((aOrbiterD * 1057564597096163085U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 4983735092494677578U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 9490022869381030928U) ^ aNonceWordA;
            aOrbiterC = RotL64((aOrbiterC * 12926352917961703123U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 7928039573014765566U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 6504190875809407084U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14648214826494826711U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 2787985600176307413U) + aNonceWordJ;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 16308785053443116826U;
            aOrbiterK = RotL64((aOrbiterK * 17867565986311256691U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 12788128335006767824U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 1187040019537798339U) ^ aOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10834905007658184183U), 47U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterB, 3U);
            aIngress = aIngress + (RotL64(aOrbiterK, 60U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterH, 11U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterJ, 39U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterD, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aCross, 14U) + RotL64(aOrbiterK, 23U)) + aOrbiterF);
            aWandererF = aWandererF + (((((RotL64(aScatter, 21U) + RotL64(aOrbiterK, 11U)) + aOrbiterD) + RotL64(aCarry, 51U)) + aNonceWordB) + aWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterJ, 56U)) + aOrbiterF);
            aWandererE = aWandererE + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterC, 5U)) + aOrbiterE) + RotL64(aCarry, 19U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 27U) + aOrbiterH) + RotL64(aOrbiterB, 47U));
            aWandererD = aWandererD + (((RotL64(aCross, 39U) + RotL64(aOrbiterH, 29U)) + aOrbiterC) + aWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterC, 38U)) + aOrbiterK);
            aWandererH = aWandererH + ((RotL64(aScatter, 60U) + RotL64(aOrbiterI, 51U)) + aOrbiterC);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterF, 19U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 41U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererE);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 51U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 18U));
            aCarry = aCarry + RotL64(aWandererD, 5U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordB);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 12299U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((aIndex + 14835U)) & S_BLOCK1], 30U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 11389U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneC[((aIndex + 16336U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 35U)) + (RotL64(aIngress, 52U) ^ RotL64(aCross, 5U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (aWandererB + RotL64(aCross, 43U)) + 9107326720193244489U;
            aOrbiterC = (aWandererC + RotL64(aScatter, 53U)) + 10868585484401664145U;
            aOrbiterD = ((aWandererG + RotL64(aIngress, 12U)) + 13637736741437846622U) + aOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = (((aWandererI + RotL64(aPrevious, 23U)) + RotL64(aCarry, 53U)) + 6130725216183918844U) + aNonceWordI;
            aOrbiterE = ((aWandererD + RotL64(aScatter, 47U)) + RotL64(aCarry, 37U)) + 2063834478521338187U;
            aOrbiterI = (((aWandererJ + RotL64(aIngress, 5U)) + RotL64(aCarry, 5U)) + 8564870627911949158U) + aNonceWordH;
            aOrbiterK = (aWandererH + RotL64(aCross, 39U)) + 6524015751064086390U;
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 34U)) + 9874937766875388236U) + aOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = ((aWandererE + RotL64(aCross, 29U)) + 14723718409522680894U) + aNonceWordB;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 13767059954741528279U) + aOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 6387608251033722169U;
            aOrbiterD = RotL64((aOrbiterD * 6601902195707980693U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 5391425980008431000U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 11524218415655093779U) ^ aOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12508457981779189389U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 155510463350385905U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 10554591788433641311U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5412084824127934293U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 8662160162966241542U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 5092555636369853727U;
            aOrbiterC = RotL64((aOrbiterC * 433807340167635499U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 7163345798448796101U) + aNonceWordD;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 695089002178413267U;
            aOrbiterE = RotL64((aOrbiterE * 17302689458565434475U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 5409173939213468972U) + aNonceWordM;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 15349690077393827541U;
            aOrbiterI = RotL64((aOrbiterI * 10984681254001609841U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 12376011890751302027U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 7809614158898158383U;
            aOrbiterK = RotL64((aOrbiterK * 13845113198736843629U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 13031938699536449576U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 3983178190194056516U;
            aOrbiterF = RotL64((aOrbiterF * 1341678482929213405U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 5567935037909671790U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 17137042627663349797U;
            aOrbiterG = RotL64((aOrbiterG * 13535586899620672373U), 53U);
            //
            aIngress = RotL64(aOrbiterI, 40U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 53U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 27U));
            aIngress = aIngress + (RotL64(aOrbiterF, 19U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterC, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aCross, 60U) + RotL64(aOrbiterF, 28U)) + aOrbiterD) + aNonceWordA);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterE, 3U)) + aOrbiterF);
            aWandererG = aWandererG + (((RotL64(aPrevious, 47U) + aOrbiterF) + RotL64(aOrbiterI, 47U)) + aWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterA, 43U)) + aOrbiterG);
            aWandererI = aWandererI + (((RotL64(aCross, 4U) + RotL64(aOrbiterD, 35U)) + aOrbiterC) + RotL64(aCarry, 53U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 39U) + aOrbiterC) + RotL64(aOrbiterA, 24U));
            aWandererC = aWandererC + ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterA, 57U)) + aOrbiterB) + aNonceWordJ) + aWandererUpdateSaltB[((aIndex + 26U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterG, 11U)) + aOrbiterK) + aNonceWordF);
            aWandererE = aWandererE + (((RotL64(aIngress, 27U) + RotL64(aOrbiterI, 51U)) + aOrbiterG) + RotL64(aCarry, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererH);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 10U));
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererD, 5U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ aNonceWordD;
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 19795U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20668U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17586U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 18747U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 35U) + RotL64(aPrevious, 51U)) ^ (RotL64(aCarry, 22U) + RotL64(aIngress, 5U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 26U)) + RotL64(aCarry, 3U)) + 13650869943246163567U;
            aOrbiterH = ((aWandererG + RotL64(aCross, 43U)) + 3435284932011770999U) + aNonceWordG;
            aOrbiterC = (aWandererJ + RotL64(aScatter, 37U)) + 12388155658186776579U;
            aOrbiterE = (aWandererA + RotL64(aIngress, 19U)) + 2374345913955712039U;
            aOrbiterJ = ((aWandererB + RotL64(aScatter, 53U)) + 6095094526980292156U) + aOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = ((aWandererD + RotL64(aIngress, 30U)) + RotL64(aCarry, 29U)) + 4965147025852444174U;
            aOrbiterI = (aWandererH + RotL64(aCross, 47U)) + 3261881216269075298U;
            aOrbiterG = (((aWandererK + RotL64(aPrevious, 3U)) + 4939780217097329222U) + aOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordP;
            aOrbiterD = (((aWandererC + RotL64(aScatter, 13U)) + RotL64(aCarry, 21U)) + 3019862009792676287U) + aNonceWordB;
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 901910626217143974U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 3647055146712366383U;
            aOrbiterC = RotL64((aOrbiterC * 1792602402476450009U), 47U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterC) + 7731765438957392967U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordI;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 13409819457393479741U;
            aOrbiterJ = RotL64((aOrbiterJ * 3345078200262410715U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 5415832109107794258U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 8876738832313114471U;
            aOrbiterI = RotL64((aOrbiterI * 1304277600444504135U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 17135570542519390359U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 2373193062766802082U;
            aOrbiterA = RotL64((aOrbiterA * 4213691513185791519U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 16318403285501718552U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 8456043288604687045U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10556964529144571683U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 10572534930284516528U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 14616251186735204677U;
            aOrbiterB = RotL64((aOrbiterB * 2048651204265459805U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 2837006243817205610U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 5315917323622194254U) ^ aOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4080522050089666599U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 12084676282761185907U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 7922080344175593788U;
            aOrbiterD = RotL64((aOrbiterD * 7603522302708937379U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 17620847289789547792U) + aOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 12140386059533463650U;
            aOrbiterH = RotL64((aOrbiterH * 1443266480620969535U), 3U);
            //
            aIngress = RotL64(aOrbiterC, 57U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterD, 50U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterI, 19U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 5U));
            aIngress = aIngress + RotL64(aOrbiterG, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 19U) + aOrbiterB) + RotL64(aOrbiterE, 43U));
            aWandererD = aWandererD + (((RotL64(aScatter, 43U) + aOrbiterB) + RotL64(aOrbiterI, 52U)) + RotL64(aCarry, 19U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 34U) + aOrbiterH) + RotL64(aOrbiterA, 35U));
            aWandererC = aWandererC + ((((RotL64(aCross, 27U) + aOrbiterE) + RotL64(aOrbiterD, 29U)) + RotL64(aCarry, 5U)) + aWandererUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 47U) + aOrbiterC) + RotL64(aOrbiterJ, 19U));
            aWandererK = aWandererK + ((RotL64(aCross, 57U) + aOrbiterA) + RotL64(aOrbiterE, 3U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterG, 58U)) + aOrbiterA);
            aWandererA = aWandererA + ((RotL64(aScatter, 52U) + aOrbiterB) + RotL64(aOrbiterG, 11U));
            aWandererF = aWandererF ^ ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterH, 23U)) + aOrbiterC) + aNonceWordO) + aWandererUpdateSaltE[((aIndex + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererA);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 46U));
            aCarry = aCarry + RotL64(aWandererF, 3U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ aNonceWordB;
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 25990U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25723U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26672U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((aIndex + 24290U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 3U) ^ RotL64(aCross, 52U)) + (RotL64(aCarry, 21U) + RotL64(aPrevious, 37U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (((aWandererI + RotL64(aCross, 51U)) + RotL64(aCarry, 5U)) + 1210605127156905516U) + aOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = (aWandererC + RotL64(aIngress, 14U)) + 11964595428173569519U;
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 19U)) + RotL64(aCarry, 39U)) + 16277319029916258482U;
            aOrbiterD = (aWandererE + RotL64(aScatter, 43U)) + 12369497463101824572U;
            aOrbiterH = (aWandererD + RotL64(aIngress, 57U)) + 6201248574067068202U;
            aOrbiterF = (aWandererK + RotL64(aPrevious, 35U)) + 1727477025667206661U;
            aOrbiterJ = ((aWandererB + RotL64(aCross, 39U)) + 1404510627789806851U) + aNonceWordF;
            aOrbiterG = ((((aWandererH + RotL64(aScatter, 47U)) + RotL64(aCarry, 51U)) + 6948213591282018925U) + aOrbiterAssignSaltA[((aIndex + 20U)) & S_SALT1]) + aNonceWordH;
            aOrbiterE = (aWandererG + RotL64(aPrevious, 10U)) + 6688865181284421478U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 3351130769402360855U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 12681032488906270823U;
            aOrbiterB = RotL64((aOrbiterB * 3680893896579741263U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 3591412591193726763U) + aNonceWordD;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 16153817571210878589U;
            aOrbiterF = RotL64((aOrbiterF * 4165137036092246349U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 3808228354421006630U) + aOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 1427373776207504205U) ^ aNonceWordM;
            aOrbiterG = RotL64((aOrbiterG * 4534374093769595531U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 1831554180932501132U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 1114853085120949215U;
            aOrbiterE = RotL64((aOrbiterE * 4264176108298812905U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 2080935638828366835U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 16104777999646489828U;
            aOrbiterC = RotL64((aOrbiterC * 15205199362011777473U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 9782806013673440791U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 3721620299829386454U;
            aOrbiterD = RotL64((aOrbiterD * 6286765834910272409U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 4013706412064296527U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 5751022780695158579U;
            aOrbiterJ = RotL64((aOrbiterJ * 13766736471646116397U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 17684546333240329338U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 1106947111128020920U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3158839453318658951U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 11564229705849500598U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 1585817314460274286U;
            aOrbiterH = RotL64((aOrbiterH * 12687162159791577431U), 57U);
            //
            aIngress = RotL64(aOrbiterK, 21U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 30U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 13U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 5U));
            aIngress = aIngress + RotL64(aOrbiterF, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterB, 11U)) + aOrbiterF);
            aWandererK = aWandererK + ((((RotL64(aCross, 30U) + RotL64(aOrbiterK, 26U)) + aOrbiterJ) + RotL64(aCarry, 43U)) + aNonceWordJ);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 13U) + aOrbiterG) + RotL64(aOrbiterC, 53U));
            aWandererF = aWandererF + ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterH, 39U)) + aOrbiterD) + aNonceWordB) + aWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterE, 43U)) + aOrbiterH) + aWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 26U) + RotL64(aOrbiterD, 21U)) + aOrbiterG) + RotL64(aCarry, 11U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 51U) + aOrbiterE) + RotL64(aOrbiterK, 3U));
            aWandererB = aWandererB + ((RotL64(aIngress, 41U) + aOrbiterC) + RotL64(aOrbiterB, 35U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterF, 48U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 34U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 37U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 41U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordB);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 31768U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28745U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32571U)) & S_BLOCK1], 46U) ^ RotL64(aWorkLaneB[((aIndex + 30538U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 13U) ^ RotL64(aPrevious, 57U)) + (RotL64(aIngress, 44U) + RotL64(aCross, 29U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererA + RotL64(aScatter, 11U)) + 9133751643283278896U;
            aOrbiterE = ((aWandererE + RotL64(aIngress, 43U)) + RotL64(aCarry, 29U)) + 8971581804375380408U;
            aOrbiterF = (aWandererF + RotL64(aCross, 18U)) + 12559650383714566592U;
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 29U)) + RotL64(aCarry, 5U)) + 15753206088872859163U;
            aOrbiterK = ((aWandererD + RotL64(aCross, 47U)) + RotL64(aCarry, 47U)) + 7640756270450762350U;
            aOrbiterA = (aWandererC + RotL64(aScatter, 51U)) + 7340073357551376125U;
            aOrbiterG = (((aWandererK + RotL64(aPrevious, 39U)) + 5270256573644196046U) + aOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordN;
            aOrbiterC = ((aWandererG + RotL64(aIngress, 60U)) + 3567367996479995928U) + aNonceWordG;
            aOrbiterB = ((aWandererH + RotL64(aCross, 23U)) + 11939634537492733738U) + aOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 7051817732424527120U) + aOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 1730487669951837941U;
            aOrbiterF = RotL64((aOrbiterF * 15191634337956285841U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 18009252467909454817U) + aOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 2361024272031696442U;
            aOrbiterK = RotL64((aOrbiterK * 15215151562500226027U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 15902755877642960397U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 12243517544704116184U;
            aOrbiterG = RotL64((aOrbiterG * 2576071074148141447U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 16846181962302186187U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 636121425116506681U;
            aOrbiterC = RotL64((aOrbiterC * 17075030673338779993U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 6887385655828217318U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 3705834550934775862U;
            aOrbiterB = RotL64((aOrbiterB * 11275428284929594435U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 11165142437077969438U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 6426659930331618269U;
            aOrbiterI = RotL64((aOrbiterI * 17170640810530893705U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 12629082390899315789U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 4277510580069574724U) ^ aNonceWordK;
            aOrbiterJ = RotL64((aOrbiterJ * 9829125163412708305U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 13814834144170469978U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 3698381854100295826U;
            aOrbiterA = RotL64((aOrbiterA * 5126359230872258015U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 11623170635983579937U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 7247413650388803796U;
            aOrbiterE = RotL64((aOrbiterE * 3403219499465560059U), 53U);
            //
            aIngress = RotL64(aOrbiterA, 19U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 48U));
            aIngress = aIngress + (RotL64(aOrbiterG, 35U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterE, 43U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterF, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterJ, 29U)) + aOrbiterF);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 56U) + RotL64(aOrbiterJ, 48U)) + aOrbiterK) + aNonceWordO);
            aWandererF = aWandererF + (((RotL64(aIngress, 47U) + aOrbiterG) + RotL64(aOrbiterE, 53U)) + RotL64(aCarry, 41U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterE, 5U)) + aOrbiterC) + aWandererUpdateSaltB[((aIndex + 4U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 51U) + aOrbiterB) + RotL64(aOrbiterA, 11U)) + RotL64(aCarry, 29U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 19U) + aOrbiterB) + RotL64(aOrbiterF, 37U));
            aWandererG = aWandererG + ((RotL64(aCross, 26U) + RotL64(aOrbiterI, 60U)) + aOrbiterB);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterK, 43U)) + aOrbiterI) + aWandererUpdateSaltF[((aIndex + 6U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aScatter, 11U) + aOrbiterF) + RotL64(aOrbiterE, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererE, 48U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererA, 57U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ aNonceWordB;
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

void TwistExpander_Tennis_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xB101C29ED18E38F3ULL + 0xBD2113280052B525ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xC500800249BA4D77ULL + 0xD1110820F7D62270ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xE8D29277566F2C03ULL + 0xF69368DC23FB409BULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x840FBE5CBE18D7DBULL + 0x9D2E0BB4FBF965F0ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xC41B8062A37F3081ULL + 0xB24BEB099335B14CULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xFBC1DB6FAE873EEDULL + 0xBC471BC008F08D7DULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x8F96FD72FE296E79ULL + 0xDB15D2F75E93EAFDULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xD5CA796732AEAE71ULL + 0xB517F07A5A4F72AFULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xA0EB6197E0DF80F5ULL + 0xB395C3D4684BB4E0ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xABA6440982128E87ULL + 0x97E29BBF4165BFA5ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xDC9583160A8911B1ULL + 0xADB183806B6430CDULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xEF8F91B52D5F016DULL + 0x848AA123B5300B46ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xD5AB24E29C593677ULL + 0xB54B6FFFF4BF66C8ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xD37F9A4A72134A3DULL + 0xD4B704886F87A81EULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xF5ECD0F37A4AD12DULL + 0xC9DA1DFEAE3F5598ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xC6527B0FB5D2A0C9ULL + 0x81C8526151999D94ULL);
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
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 4722U)) & S_BLOCK1], 10U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 3050U)) & W_KEY1], 37U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 721U)) & W_KEY1], 11U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 2842U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 40U) + RotL64(aCarry, 57U)) ^ (RotL64(aIngress, 5U) ^ RotL64(aCross, 27U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterA = (((aWandererE + RotL64(aScatter, 19U)) + RotL64(aCarry, 13U)) + 9888431329297626900U) + aNonceWordO;
            aOrbiterE = (((aWandererC + RotL64(aPrevious, 35U)) + RotL64(aCarry, 53U)) + 2937735167534624403U) + aNonceWordD;
            aOrbiterF = (aWandererA + RotL64(aCross, 5U)) + 17626022970343789617U;
            aOrbiterI = ((aWandererG + RotL64(aIngress, 57U)) + RotL64(aCarry, 41U)) + 5665660859333693743U;
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 41U)) + 1060537034632076669U) + aPhaseAOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = (aWandererF + RotL64(aScatter, 11U)) + 743777763907175800U;
            aOrbiterD = (((aWandererH + RotL64(aCross, 26U)) + 5744905970181808845U) + aPhaseAOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1]) + aNonceWordE;
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 3545351394494002180U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 4877547088414106007U;
            aOrbiterF = RotL64((aOrbiterF * 5416792889338547109U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 11669378338379598445U) + aNonceWordP;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 2961072441706158212U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2677988507090705371U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 13984945589234919765U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 1433097875470903205U;
            aOrbiterB = RotL64((aOrbiterB * 451996840039906781U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 716415411025451152U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 8542286150858297810U;
            aOrbiterD = RotL64((aOrbiterD * 9139015340823332449U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 12932391786479661299U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 14005503313299177013U;
            aOrbiterA = RotL64((aOrbiterA * 802663466907819743U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 9382792812676318046U) + aNonceWordC;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 5138554251079724724U;
            aOrbiterI = RotL64((aOrbiterI * 6386016499265056247U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 8522380066269546172U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 11825536408101906458U;
            aOrbiterE = RotL64((aOrbiterE * 17042837108792016849U), 19U);
            //
            aIngress = RotL64(aOrbiterC, 53U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 21U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 12U));
            aIngress = aIngress + RotL64(aOrbiterD, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aCross, 47U) + RotL64(aOrbiterD, 60U)) + aOrbiterA) + RotL64(aCarry, 23U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterC, 37U)) + aOrbiterE);
            aWandererF = aWandererF + ((RotL64(aScatter, 39U) + RotL64(aOrbiterF, 3U)) + aOrbiterI);
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 27U) + RotL64(aOrbiterB, 47U)) + aOrbiterF) + aNonceWordI) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aCross, 60U) + aOrbiterC) + RotL64(aOrbiterI, 23U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 13U) + aOrbiterF) + RotL64(aOrbiterD, 29U));
            aWandererE = aWandererE + ((((RotL64(aPrevious, 21U) + aOrbiterA) + RotL64(aOrbiterE, 13U)) + RotL64(aCarry, 53U)) + aPhaseAWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 30U) ^ aWandererC);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 13U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 53U));
            aCarry = aCarry + RotL64(aWandererF, 35U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordK);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10451U)) & S_BLOCK1], 4U) ^ RotL64(mSource[((aIndex + 7017U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 5968U)) & W_KEY1], 23U) ^ RotL64(aKeyRowReadB[((aIndex + 9383U)) & W_KEY1], 5U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 21U) ^ RotL64(aIngress, 51U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCarry, 36U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterE = ((aWandererH + RotL64(aCross, 29U)) + RotL64(aCarry, 53U)) + 14179205183062705133U;
            aOrbiterG = ((aWandererF + RotL64(aScatter, 3U)) + 210032324058740920U) + aPhaseAOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = (aWandererB + RotL64(aIngress, 23U)) + 7387115089142500152U;
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 60U)) + 17583362781238061430U;
            aOrbiterD = (((aWandererD + RotL64(aScatter, 47U)) + RotL64(aCarry, 3U)) + 4991442849150005943U) + aPhaseAOrbiterAssignSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterI = ((aWandererC + RotL64(aIngress, 13U)) + RotL64(aCarry, 27U)) + 2891376254689854555U;
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 35U)) + 10523274382407446239U) + aNonceWordL;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 3861893764676218667U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 3366674459852093746U;
            aOrbiterC = RotL64((aOrbiterC * 14005994095369483813U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 5898492634386601145U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 7047353571244768721U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2257518291062508467U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 14374108805453186316U) + aNonceWordI;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 8763667021501226510U;
            aOrbiterJ = RotL64((aOrbiterJ * 7694695426430267863U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 18261523829316379575U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 650477532238860965U;
            aOrbiterG = RotL64((aOrbiterG * 8291758490821819851U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 2162326554604894042U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 5776546692501825278U;
            aOrbiterD = RotL64((aOrbiterD * 14911545784585246537U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 3501863793638415049U) + aNonceWordJ;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 14853789267425352958U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10590325397179928739U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 15399673014671329743U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 12253428583438990426U;
            aOrbiterF = RotL64((aOrbiterF * 12052855472196447849U), 43U);
            //
            aIngress = RotL64(aOrbiterD, 5U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterE, 51U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterJ, 13U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterF, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterI, 13U)) + aOrbiterE) + RotL64(aCarry, 53U)) + aNonceWordO);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 19U) + aOrbiterI) + RotL64(aOrbiterD, 5U));
            aWandererF = aWandererF + (((((RotL64(aPrevious, 42U) + aOrbiterC) + RotL64(aOrbiterE, 46U)) + RotL64(aCarry, 37U)) + aNonceWordA) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 35U) + aOrbiterJ) + RotL64(aOrbiterD, 53U)) + aNonceWordP);
            aWandererA = aWandererA + (((RotL64(aScatter, 11U) + RotL64(aOrbiterF, 37U)) + aOrbiterC) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 27U) + aOrbiterE) + RotL64(aOrbiterJ, 21U));
            aWandererI = aWandererI + ((RotL64(aCross, 57U) + aOrbiterI) + RotL64(aOrbiterG, 29U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 42U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 21U));
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererC, 47U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordN);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 13349U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((aIndex + 12065U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15392U)) & W_KEY1], 50U) ^ RotL64(aKeyRowReadB[((aIndex + 13899U)) & W_KEY1], 35U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aPrevious, 53U)) ^ (RotL64(aCross, 19U) ^ RotL64(aIngress, 34U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 27U)) + RotL64(aCarry, 57U)) + 5576732410244514238U;
            aOrbiterG = (aWandererG + RotL64(aCross, 60U)) + 2833808925935929629U;
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 35U)) + RotL64(aCarry, 43U)) + 3670188682914544792U;
            aOrbiterC = (((aWandererI + RotL64(aPrevious, 13U)) + RotL64(aCarry, 13U)) + 15759072378887814995U) + aNonceWordG;
            aOrbiterI = ((aWandererB + RotL64(aScatter, 41U)) + 13934007231137439994U) + aPhaseAOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = (((aWandererE + RotL64(aCross, 53U)) + 11022225696007690512U) + aPhaseAOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1]) + aNonceWordB;
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 21U)) + 16989177104453635790U) + aNonceWordJ;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 9256930045263527091U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 17788596104417068290U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 675554110563253305U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 17044369456673337625U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 1310908395523250343U) ^ aNonceWordA;
            aOrbiterG = RotL64((aOrbiterG * 16305084373037705921U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 12067065689034065422U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 15130844248737512262U;
            aOrbiterK = RotL64((aOrbiterK * 9409499577465934107U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 14532689204495587494U) + aNonceWordF;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 8198147292120244178U;
            aOrbiterC = RotL64((aOrbiterC * 1418356389507740991U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 5485494458627163347U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 10830008207150307611U;
            aOrbiterI = RotL64((aOrbiterI * 6526039534042499457U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 17770065502486618029U) + aNonceWordM;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 6397859353395335459U;
            aOrbiterH = RotL64((aOrbiterH * 14286997752368893825U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 5128700697381508319U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 7103394110057060499U;
            aOrbiterE = RotL64((aOrbiterE * 5053680689949149633U), 51U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterG, 11U);
            aIngress = aIngress + (RotL64(aOrbiterC, 29U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterE, 42U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterI, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aPrevious, 27U) + aOrbiterI) + RotL64(aOrbiterK, 21U)) + aNonceWordL);
            aWandererG = aWandererG ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterJ, 27U)) + aOrbiterC) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 57U) + RotL64(aOrbiterC, 57U)) + aOrbiterI) + aNonceWordP);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 41U) + aOrbiterC) + RotL64(aOrbiterH, 37U)) + aPhaseAWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterG, 5U)) + aOrbiterE) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 50U) + aOrbiterH) + RotL64(aOrbiterE, 44U)) + aNonceWordC);
            aWandererH = aWandererH + (((RotL64(aScatter, 3U) + aOrbiterE) + RotL64(aOrbiterJ, 11U)) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 5U));
            aCarry = aCarry + (RotL64(aWandererI, 28U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 21U));
            aCarry = aCarry + RotL64(aWandererG, 11U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ aNonceWordO;
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 20403U)) & S_BLOCK1], 26U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19582U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21489U)) & S_BLOCK1], 27U) ^ RotL64(mSource[((aIndex + 16955U)) & S_BLOCK1], 40U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 35U) ^ RotL64(aCross, 5U)) + (RotL64(aCarry, 47U) + RotL64(aIngress, 18U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 13U)) + RotL64(aCarry, 3U)) + 3255291173184001106U;
            aOrbiterA = ((aWandererK + RotL64(aIngress, 37U)) + 15308468160116255528U) + aNonceWordJ;
            aOrbiterD = ((aWandererJ + RotL64(aCross, 57U)) + 18186972408589866656U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = (aWandererI + RotL64(aScatter, 4U)) + 4439324265978331914U;
            aOrbiterH = ((((aWandererC + RotL64(aCross, 43U)) + RotL64(aCarry, 19U)) + 13099263173016322486U) + aPhaseAOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1]) + aNonceWordD;
            aOrbiterE = (aWandererH + RotL64(aPrevious, 21U)) + 7041561081767500660U;
            aOrbiterG = (((aWandererA + RotL64(aIngress, 29U)) + RotL64(aCarry, 53U)) + 6196422612687812971U) + aNonceWordA;
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 7664260932541281413U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 17802347823020441056U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2220679459017369255U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 4253107484061190446U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 13799496534030645312U;
            aOrbiterE = RotL64((aOrbiterE * 9167675060053848207U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 14252892847595951926U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 5663527578664291422U;
            aOrbiterA = RotL64((aOrbiterA * 18314294235895182465U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 11148755959699137661U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 17036900929333594592U;
            aOrbiterH = RotL64((aOrbiterH * 16041243617369003291U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 2403828181385259549U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 17813580350434928194U;
            aOrbiterC = RotL64((aOrbiterC * 13666780980793857831U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 5623611126885414523U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 7293224381174846969U;
            aOrbiterK = RotL64((aOrbiterK * 7032561584670788117U), 29U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterE) + 10602620906929686163U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1]) + aNonceWordK;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 18015916257203385982U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10684090189688871993U), 35U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterH, 21U);
            aIngress = aIngress + (RotL64(aOrbiterG, 37U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 51U));
            aIngress = aIngress + RotL64(aOrbiterK, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aCross, 41U) + RotL64(aOrbiterH, 37U)) + aOrbiterG) + RotL64(aCarry, 43U));
            aWandererJ = aWandererJ ^ ((((RotL64(aIngress, 5U) + aOrbiterH) + RotL64(aOrbiterA, 11U)) + aNonceWordM) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 13U) + aOrbiterA) + RotL64(aOrbiterC, 53U)) + RotL64(aCarry, 21U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 27U) + aOrbiterA) + RotL64(aOrbiterK, 21U));
            aWandererC = aWandererC + ((RotL64(aCross, 21U) + aOrbiterE) + RotL64(aOrbiterH, 27U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 47U) + aOrbiterD) + RotL64(aOrbiterA, 60U)) + aNonceWordE);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 54U) + aOrbiterC) + RotL64(aOrbiterD, 5U)) + aNonceWordC) + aPhaseAWandererUpdateSaltE[((aIndex + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 52U));
            aCarry = aCarry + RotL64(aWandererF, 41U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordN);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 23531U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22288U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26720U)) & S_BLOCK1], 30U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25644U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 27U) + RotL64(aCarry, 54U)) ^ (RotL64(aCross, 11U) + RotL64(aIngress, 41U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterE = ((aWandererA + RotL64(aScatter, 60U)) + 7948891781097675369U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = ((aWandererJ + RotL64(aCross, 51U)) + 13928362874228230226U) + aNonceWordC;
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 3U)) + 10776180542602258926U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = (((aWandererG + RotL64(aIngress, 11U)) + RotL64(aCarry, 41U)) + 5735115172149470447U) + aNonceWordM;
            aOrbiterG = (((aWandererF + RotL64(aCross, 39U)) + RotL64(aCarry, 5U)) + 5353591822981766987U) + aNonceWordK;
            aOrbiterK = (aWandererK + RotL64(aPrevious, 23U)) + 562301708107268570U;
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 29U)) + RotL64(aCarry, 19U)) + 10467810247578364868U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 14541630141152308564U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 2350076897065139429U;
            aOrbiterB = RotL64((aOrbiterB * 12222554362482034393U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 17519109078651162228U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 6061035173339902910U;
            aOrbiterE = RotL64((aOrbiterE * 10021905773432907835U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 15654836633731000065U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 13723521735153718904U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14459516479283070563U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 2849680038315532197U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 17336102435576647923U;
            aOrbiterF = RotL64((aOrbiterF * 10984689101753586739U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 7671010488872356142U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 11485114338165600777U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4162584865462407791U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 8759060657343458985U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 11009137869375286581U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8741417343929809115U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 15792999392743144135U) + aNonceWordF;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 6180808423175992479U;
            aOrbiterJ = RotL64((aOrbiterJ * 13681230339693676907U), 13U);
            //
            aIngress = RotL64(aOrbiterF, 13U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 27U));
            aIngress = aIngress + RotL64(aOrbiterH, 50U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 57U) + aOrbiterG) + RotL64(aOrbiterH, 47U));
            aWandererK = aWandererK + ((((RotL64(aCross, 48U) + aOrbiterK) + RotL64(aOrbiterF, 53U)) + RotL64(aCarry, 51U)) + aNonceWordI);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 21U) + aOrbiterE) + RotL64(aOrbiterH, 37U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 5U) + aOrbiterJ) + RotL64(aOrbiterE, 21U)) + RotL64(aCarry, 23U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterE, 14U)) + aOrbiterB) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aIngress, 13U) + aOrbiterE) + RotL64(aOrbiterF, 29U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 39U) + aOrbiterK) + RotL64(aOrbiterB, 5U)) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererF);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 34U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ aNonceWordC;
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 29694U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30031U)) & S_BLOCK1], 50U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29394U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28224U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aIngress, 53U)) ^ (RotL64(aPrevious, 4U) + RotL64(aCarry, 41U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterC = ((aWandererB + RotL64(aCross, 3U)) + 6973892330986118220U) + aNonceWordD;
            aOrbiterF = (aWandererJ + RotL64(aPrevious, 53U)) + 9886813896272094864U;
            aOrbiterD = (((aWandererG + RotL64(aIngress, 13U)) + RotL64(aCarry, 27U)) + 10996306582517553173U) + aPhaseAOrbiterAssignSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterG = ((((aWandererH + RotL64(aScatter, 43U)) + RotL64(aCarry, 11U)) + 8490648283899856223U) + aPhaseAOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1]) + aNonceWordE;
            aOrbiterB = (((aWandererK + RotL64(aPrevious, 37U)) + RotL64(aCarry, 51U)) + 105141713530704655U) + aNonceWordP;
            aOrbiterK = (aWandererD + RotL64(aIngress, 29U)) + 3114337422810562588U;
            aOrbiterA = (aWandererA + RotL64(aCross, 22U)) + 980857684690886131U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 6562042345807072665U) + aNonceWordB;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 15665371138706353619U;
            aOrbiterD = RotL64((aOrbiterD * 8086237578564620623U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 18113013571374375028U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 17405346422601997299U;
            aOrbiterB = RotL64((aOrbiterB * 11162604605443005253U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 5130876096426182506U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 1813821672299154629U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15478100342425611875U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 15793814882743306728U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 13925299440495476399U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12049601510660117401U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 9924458846049579438U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 7810034662781768090U;
            aOrbiterC = RotL64((aOrbiterC * 10310594595026622513U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 12812586478656872854U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 5709576448057435237U;
            aOrbiterG = RotL64((aOrbiterG * 9101555233909853025U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 7839807649914541516U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 4717944526755429647U;
            aOrbiterF = RotL64((aOrbiterF * 8515229146471335721U), 29U);
            //
            aIngress = RotL64(aOrbiterA, 60U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 37U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + RotL64(aOrbiterF, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aIngress, 27U) + aOrbiterK) + RotL64(aOrbiterG, 41U)) + RotL64(aCarry, 53U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 19U) + aOrbiterD) + RotL64(aOrbiterA, 27U));
            aWandererK = aWandererK + ((((RotL64(aPrevious, 3U) + aOrbiterD) + RotL64(aOrbiterG, 5U)) + RotL64(aCarry, 37U)) + aNonceWordK);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 42U) + aOrbiterK) + RotL64(aOrbiterD, 11U)) + aPhaseAWandererUpdateSaltC[((aIndex + 4U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 51U) + RotL64(aOrbiterK, 21U)) + aOrbiterB) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 13U) + aOrbiterC) + RotL64(aOrbiterB, 60U));
            aWandererA = aWandererA + ((RotL64(aScatter, 57U) + aOrbiterK) + RotL64(aOrbiterF, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 37U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererB, 18U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererJ, 11U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ aNonceWordC;
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

void TwistExpander_Tennis_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xF6B400148243679DULL + 0x99717B4AD7377F82ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x89784B211B3E8B67ULL + 0xF409FA146F98B66BULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x86D7D50D2826B5ADULL + 0xB2A5B0212AC61573ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xEC9ED22FDAD6890DULL + 0x9FD9B4FC49C0BD96ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xF86466F890AAC3FFULL + 0xF8C6F6293055EC5DULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x8089C942E3B882F1ULL + 0x9755282CF2A3FBB4ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x98A2F428871ACD47ULL + 0x8F70673A1B0CB230ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xDC5E3F2966F66C99ULL + 0xC4897872E62D384AULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xD09AE49267702E87ULL + 0xC7AE00C203806515ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x89E4E384508808E1ULL + 0xB36D6ACA775FD8BEULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xF90B550C1E1A112DULL + 0xABDB39680CDFF6E8ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xE44E5CA2FE24CBF7ULL + 0xECB481478DA144CCULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xD94217F85EA2D885ULL + 0x962ABA1C8FD65FA8ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xAC6E2916468A3101ULL + 0xD73E5CDA469580ABULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xE8A7C4D800FC31FFULL + 0x93076F67D91F2BCDULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xE608950E74CEA247ULL + 0x913DCFE87623C370ULL);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 3712U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1364U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4944U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 846U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 56U) ^ RotL64(aCarry, 23U)) + (RotL64(aCross, 41U) ^ RotL64(aIngress, 5U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterD = ((aWandererB + RotL64(aIngress, 5U)) + RotL64(aCarry, 39U)) + 2783898056762489197U;
            aOrbiterF = (((aWandererI + RotL64(aScatter, 23U)) + RotL64(aCarry, 3U)) + 7177192902873343053U) + aNonceWordK;
            aOrbiterH = (aWandererE + RotL64(aPrevious, 34U)) + 12254703232691980774U;
            aOrbiterE = ((aWandererC + RotL64(aCross, 13U)) + 15446547245691219559U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = (((aWandererF + RotL64(aPrevious, 43U)) + RotL64(aCarry, 19U)) + 888475203006174856U) + aPhaseBOrbiterAssignSaltC[((aIndex + 8U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 3649183529366307877U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 4642631047518805167U) ^ aNonceWordL;
            aOrbiterH = RotL64((aOrbiterH * 14791564497487717167U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 6108329730724782250U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 8334054653023816636U;
            aOrbiterD = RotL64((aOrbiterD * 9352516059501924393U), 41U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterH) + 5891895375031474350U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordD;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 3176720746238477862U;
            aOrbiterE = RotL64((aOrbiterE * 1869961473768307911U), 5U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterD) + 6111038696865301675U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1]) + aNonceWordN;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 11914998302228682704U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11738924766359642853U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 17005063057791320948U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 18333780598768130670U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5416759844884107303U), 13U);
            //
            aIngress = RotL64(aOrbiterE, 3U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterB, 37U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterH, 22U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aCross, 23U) + RotL64(aOrbiterB, 11U)) + aOrbiterF) + RotL64(aCarry, 27U)) + aPhaseBWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 3U) + aOrbiterH) + RotL64(aOrbiterB, 44U));
            aWandererI = aWandererI + ((((RotL64(aPrevious, 34U) + aOrbiterF) + RotL64(aOrbiterE, 57U)) + RotL64(aCarry, 13U)) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 13U) + aOrbiterD) + RotL64(aOrbiterB, 35U)) + aNonceWordC);
            aWandererC = aWandererC + (((RotL64(aCross, 47U) + RotL64(aOrbiterD, 23U)) + aOrbiterH) + aNonceWordI);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererB, 11U);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10043U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((aIndex + 8183U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8094U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 10479U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aPrevious, 34U)) + (RotL64(aCross, 19U) ^ RotL64(aIngress, 5U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterA = ((aWandererA + RotL64(aIngress, 47U)) + RotL64(aCarry, 29U)) + 252059974543142812U;
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 23U)) + 11690823093681457368U) + aNonceWordL;
            aOrbiterC = ((((aWandererE + RotL64(aCross, 37U)) + RotL64(aCarry, 5U)) + 13282189752890971123U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordB;
            aOrbiterB = ((aWandererH + RotL64(aScatter, 57U)) + RotL64(aCarry, 53U)) + 9507416294305708435U;
            aOrbiterH = (((aWandererI + RotL64(aPrevious, 6U)) + 14053038174390776539U) + aPhaseBOrbiterAssignSaltA[((aIndex + 14U)) & S_SALT1]) + aNonceWordM;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 14605253312318725009U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 18138286582677863671U;
            aOrbiterC = RotL64((aOrbiterC * 10595905899691011321U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 8530091235978489988U) + aNonceWordN;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 14381731677571170073U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11675896999665768253U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 13316413456378978456U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 3910529530149320706U;
            aOrbiterA = RotL64((aOrbiterA * 16000139333493588429U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 6302070286831566901U) + aNonceWordJ;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 12324134652758551396U;
            aOrbiterF = RotL64((aOrbiterF * 17136438281540250165U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 4773478557638475048U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 4031153435446078944U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3876928995240982769U), 57U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterF, 27U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + RotL64(aOrbiterA, 54U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((((RotL64(aPrevious, 43U) + RotL64(aOrbiterF, 19U)) + aOrbiterB) + aNonceWordC) + aPhaseBWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 5U) + RotL64(aOrbiterC, 38U)) + aOrbiterH) + RotL64(aCarry, 39U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 57U) + aOrbiterA) + RotL64(aOrbiterF, 57U)) + aNonceWordG);
            aWandererE = aWandererE + ((((RotL64(aCross, 14U) + aOrbiterB) + RotL64(aOrbiterC, 5U)) + RotL64(aCarry, 19U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 35U) + aOrbiterA) + RotL64(aOrbiterB, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 60U) ^ aWandererI);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 5U));
            aCarry = aCarry + RotL64(aWandererA, 47U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordO);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 13681U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12783U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 13691U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneC[((aIndex + 14537U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 5U)) + (RotL64(aCross, 43U) + RotL64(aIngress, 24U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 3U)) + RotL64(aCarry, 39U)) + 18144572925667544139U;
            aOrbiterA = ((aWandererF + RotL64(aIngress, 29U)) + RotL64(aCarry, 23U)) + 5659758077574059728U;
            aOrbiterD = ((((aWandererI + RotL64(aCross, 40U)) + RotL64(aCarry, 53U)) + 6343330616999166392U) + aPhaseBOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1]) + aNonceWordK;
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 21U)) + 17754639838410839447U) + aPhaseBOrbiterAssignSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterE = (aWandererB + RotL64(aScatter, 13U)) + 9451843819849581729U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 7957854457197462212U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 1461994799722205010U;
            aOrbiterD = RotL64((aOrbiterD * 13431080873536691809U), 47U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterH) + 18002214276252170177U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordO;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 14689869073147027164U) ^ aNonceWordL;
            aOrbiterA = RotL64((aOrbiterA * 12242482963989582191U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 3978104368003440293U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 8512135845221335386U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10506667163729414667U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 1477533446382953439U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 2166717790929947990U) ^ aNonceWordJ;
            aOrbiterC = RotL64((aOrbiterC * 6538884492418324461U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 8082437060686606995U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 4363687722464700362U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7199165810993478887U), 5U);
            //
            aIngress = RotL64(aOrbiterD, 19U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 41U));
            aIngress = aIngress + RotL64(aOrbiterH, 30U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 20U) + aOrbiterC) + RotL64(aOrbiterE, 20U));
            aWandererF = aWandererF + (((((RotL64(aIngress, 5U) + RotL64(aOrbiterE, 51U)) + aOrbiterD) + RotL64(aCarry, 43U)) + aNonceWordH) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 35U) + aOrbiterD) + RotL64(aOrbiterC, 41U)) + aPhaseBWandererUpdateSaltF[((aIndex + 28U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 53U) + aOrbiterA) + RotL64(aOrbiterD, 3U)) + RotL64(aCarry, 3U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 43U) + aOrbiterC) + RotL64(aOrbiterH, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererF, 44U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ aNonceWordD;
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 16413U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneB[((aIndex + 18567U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20050U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19643U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 6U) ^ RotL64(aCross, 35U)) + (RotL64(aPrevious, 47U) ^ RotL64(aCarry, 21U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 4U)) + RotL64(aCarry, 21U)) + 1087148170018530502U;
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 29U)) + RotL64(aCarry, 37U)) + 15530846874509311414U;
            aOrbiterK = ((aWandererI + RotL64(aScatter, 47U)) + 16987358651515511212U) + aPhaseBOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = (((aWandererD + RotL64(aCross, 57U)) + RotL64(aCarry, 53U)) + 12504143181007924259U) + aNonceWordK;
            aOrbiterE = ((aWandererE + RotL64(aScatter, 21U)) + 393322117322732418U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 14325937299241887166U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 9395262907017475742U;
            aOrbiterK = RotL64((aOrbiterK * 3442643798173589117U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 13658510441418344769U) + aNonceWordM;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 6410754322737005336U) ^ aNonceWordE;
            aOrbiterF = RotL64((aOrbiterF * 6932217611373076391U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 9257290738538818434U) + aNonceWordG;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 7489828960857692286U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16519674788777989043U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 4118778591214588387U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 16619215231168796563U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14876884956536265157U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 11326283811003573430U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 1865401866017614604U;
            aOrbiterE = RotL64((aOrbiterE * 8378326058282460073U), 35U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterH, 27U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 41U));
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((((RotL64(aCross, 3U) + RotL64(aOrbiterG, 21U)) + aOrbiterE) + RotL64(aCarry, 3U)) + aNonceWordN) + aPhaseBWandererUpdateSaltA[((aIndex + 14U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 30U) + aOrbiterH) + RotL64(aOrbiterF, 56U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 13U) + aOrbiterG) + RotL64(aOrbiterK, 3U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterG, 41U)) + aOrbiterF);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 21U) + aOrbiterK) + RotL64(aOrbiterH, 13U)) + RotL64(aCarry, 43U)) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererI, 56U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ aNonceWordI;
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 27209U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25773U)) & S_BLOCK1], 34U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 23914U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneA[((aIndex + 22023U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 19U)) ^ (RotL64(aIngress, 54U) + RotL64(aCross, 35U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 39U)) + 4476099022490972343U) + aNonceWordB;
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 3U)) + RotL64(aCarry, 41U)) + 16836423700375760429U;
            aOrbiterK = (((aWandererK + RotL64(aCross, 48U)) + RotL64(aCarry, 13U)) + 8850577488928703557U) + aNonceWordH;
            aOrbiterF = ((((aWandererC + RotL64(aScatter, 27U)) + RotL64(aCarry, 57U)) + 7091631824560042743U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordO;
            aOrbiterH = ((aWandererH + RotL64(aCross, 57U)) + 12560498899956759494U) + aPhaseBOrbiterAssignSaltD[((aIndex + 16U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 7797973377112012161U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 6173820673874805794U) ^ aNonceWordC;
            aOrbiterK = RotL64((aOrbiterK * 15741300047917486527U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 10805025132310245348U) + aNonceWordJ;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 7139216143268029968U;
            aOrbiterH = RotL64((aOrbiterH * 8349754682635765573U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 8241544862261635722U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = (((aOrbiterB ^ aOrbiterF) ^ 4735527016563596150U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterB = RotL64((aOrbiterB * 6621354217673598381U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 5166171126690294033U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 11117641762075368393U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4980156869201219393U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 6312932356458415421U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 1304139291184508668U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 90744653170922319U), 27U);
            //
            aIngress = RotL64(aOrbiterJ, 51U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 28U));
            aIngress = aIngress + RotL64(aOrbiterB, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterH, 21U)) + aOrbiterB);
            aWandererH = aWandererH + (((((RotL64(aScatter, 21U) + aOrbiterJ) + RotL64(aOrbiterF, 13U)) + RotL64(aCarry, 53U)) + aNonceWordI) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 12U) + RotL64(aOrbiterK, 37U)) + aOrbiterF);
            aWandererF = aWandererF + (((((RotL64(aIngress, 3U) + aOrbiterK) + RotL64(aOrbiterH, 54U)) + RotL64(aCarry, 41U)) + aNonceWordG) + aPhaseBWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 37U) + aOrbiterJ) + RotL64(aOrbiterH, 3U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 37U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + RotL64(aWandererF, 47U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ aNonceWordJ;
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 27525U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneB[((aIndex + 28844U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 27967U)) & S_BLOCK1], 10U) ^ RotL64(aWorkLaneB[((aIndex + 31425U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 3U) + RotL64(aCarry, 50U)) ^ (RotL64(aCross, 21U) + RotL64(aIngress, 35U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 40U)) + RotL64(aCarry, 23U)) + 2177539223979303669U;
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 21U)) + RotL64(aCarry, 39U)) + 3962004686551521471U;
            aOrbiterG = ((aWandererA + RotL64(aScatter, 11U)) + 8457602312617147662U) + aPhaseBOrbiterAssignSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = ((aWandererD + RotL64(aIngress, 29U)) + RotL64(aCarry, 57U)) + 18011802451816510632U;
            aOrbiterF = (((aWandererG + RotL64(aPrevious, 51U)) + 9046101759168876832U) + aPhaseBOrbiterAssignSaltF[((aIndex + 11U)) & S_SALT1]) + aNonceWordO;
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 11135620637431969597U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 15913029940697999701U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 646524659942693491U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 16304193109948135982U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 13208892298820080981U;
            aOrbiterJ = RotL64((aOrbiterJ * 15093751072618884859U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 4182377898949419225U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 13970137023071326151U;
            aOrbiterH = RotL64((aOrbiterH * 9075061559681739865U), 3U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterF) + 8402396284835248583U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1]) + aNonceWordM;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 8859190834060657829U;
            aOrbiterB = RotL64((aOrbiterB * 13552418608113716117U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 9760005337757990392U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 14108277760135744897U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4474681104256093885U), 23U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterF, 57U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 18U));
            aIngress = aIngress + RotL64(aOrbiterG, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aPrevious, 14U) + aOrbiterG) + RotL64(aOrbiterB, 23U)) + RotL64(aCarry, 51U)) + aNonceWordG);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 53U) + aOrbiterB) + RotL64(aOrbiterJ, 54U)) + aNonceWordF);
            aWandererJ = aWandererJ + (((RotL64(aCross, 27U) + aOrbiterH) + RotL64(aOrbiterJ, 11U)) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 5U) + aOrbiterF) + RotL64(aOrbiterJ, 43U));
            aWandererD = aWandererD + ((((RotL64(aCross, 41U) + RotL64(aOrbiterH, 3U)) + aOrbiterF) + RotL64(aCarry, 19U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererD);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + RotL64(aWandererE, 46U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ aNonceWordI;
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

void TwistExpander_Tennis_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xBFCC538C478A1C05ULL + 0xEEDF79D9B11CE6E4ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x9DE0540FBBFE96AFULL + 0xCB52FCE9EA0A863AULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xDD00F4AB2BAF94D9ULL + 0xBF6FC82E0C330538ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xE08433BA49B0B67BULL + 0xEB9655792D1BB339ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xC31B0BBF4EA5F3B7ULL + 0xC52A84313A8F3267ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xA54283D9FA08325FULL + 0x9EFB3D8795B6FEC3ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xD7A09E21D80E7D95ULL + 0xCBF0844A59D94D01ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xC30719B2B1DAE925ULL + 0xA48E5A2B06FC35CAULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xDCBF159419FEB23BULL + 0xE0581D81DC9E319EULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xAF532E0A7031C0EDULL + 0xDA555E1384154800ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xF822600E60A577ABULL + 0x958FE405ABD3E8BDULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xE379FC7D57D92611ULL + 0xCC2D446ABF5296F7ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xBBCAA0A2EA13700BULL + 0xB8DEF4684D285DC8ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xA2E6436CAE6CE6D1ULL + 0xA3DA819E5E14ED49ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xCA40F6B6BB85FF8BULL + 0x972D1DC780479EF1ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x9E0003DA7B2679ABULL + 0xE4429E0FB624D7AEULL);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 5102U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 8122U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 6154U)) & S_BLOCK1], 40U) ^ RotL64(aOperationLaneA[((aIndex + 2129U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aIngress, 11U)) + (RotL64(aPrevious, 42U) ^ RotL64(aCarry, 57U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterA = (aWandererA + RotL64(aIngress, 35U)) + 16922357079016918108U;
            aOrbiterD = (aWandererH + RotL64(aScatter, 11U)) + 11771749797137599131U;
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 24U)) + 4635668433708036077U) + aNonceWordL;
            aOrbiterC = (aWandererG + RotL64(aCross, 3U)) + 15827952719230577008U;
            aOrbiterK = ((aWandererC + RotL64(aScatter, 53U)) + RotL64(aCarry, 57U)) + 1495675306110023086U;
            aOrbiterG = ((aWandererF + RotL64(aIngress, 29U)) + RotL64(aCarry, 23U)) + 7294835466949728365U;
            aOrbiterH = (((aWandererE + RotL64(aCross, 57U)) + RotL64(aCarry, 41U)) + 179122461212041978U) + aNonceWordC;
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 39U)) + 545981421632236251U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = (((aWandererB + RotL64(aCross, 18U)) + 15338259639814630535U) + aPhaseCOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1]) + aNonceWordM;
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 12924313840290895215U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 17846785921286020610U;
            aOrbiterB = RotL64((aOrbiterB * 18309347016029917133U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 5721472794107057875U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 16359630793856870319U;
            aOrbiterG = RotL64((aOrbiterG * 14186771515526698907U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 10614102110239037308U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 16421992251278236531U;
            aOrbiterF = RotL64((aOrbiterF * 2561232904676068089U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 8668149834861244963U) + aNonceWordI;
            aOrbiterI = (((aOrbiterI ^ aOrbiterD) ^ 12699331834360948734U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterI = RotL64((aOrbiterI * 2249360824172616357U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 4470693178142950471U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 526000656022724741U;
            aOrbiterA = RotL64((aOrbiterA * 16688501462334673493U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 6880246132270094141U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 7126466778855297013U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5692237926830293205U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 6436404501390442054U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 1213633065612242699U) ^ aNonceWordJ;
            aOrbiterH = RotL64((aOrbiterH * 17604454985534439259U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 8186529105901185854U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 10607460957358250935U;
            aOrbiterD = RotL64((aOrbiterD * 17172191011625677861U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 9743278964993305169U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 14007577681873418075U;
            aOrbiterK = RotL64((aOrbiterK * 4231122580398039133U), 51U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterI, 50U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 19U));
            aIngress = aIngress + (RotL64(aOrbiterA, 39U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aScatter, 19U) + RotL64(aOrbiterH, 34U)) + aOrbiterB);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 34U) + aOrbiterH) + RotL64(aOrbiterI, 11U)) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 51U) + aOrbiterK) + RotL64(aOrbiterF, 27U)) + RotL64(aCarry, 29U));
            aWandererF = aWandererF ^ ((((RotL64(aPrevious, 43U) + aOrbiterF) + RotL64(aOrbiterD, 41U)) + aNonceWordO) + aPhaseCWandererUpdateSaltE[((aIndex + 16U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 23U) + aOrbiterI) + RotL64(aOrbiterA, 51U)) + RotL64(aCarry, 37U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 60U) + aOrbiterI) + RotL64(aOrbiterC, 47U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterC, 3U)) + aOrbiterG);
            aWandererD = aWandererD ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterI, 58U)) + aOrbiterK) + aNonceWordE);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 5U) + RotL64(aOrbiterD, 21U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererA, 40U) ^ aWandererJ);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + RotL64(aWandererG, 3U);
            aCarry = aCarry + RotL64(aIngress, 24U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordH);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 14660U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneD[((aIndex + 13024U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 9129U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((aIndex + 8591U)) & S_BLOCK1], 50U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 37U) + RotL64(aCarry, 3U)) ^ (RotL64(aCross, 50U) + RotL64(aIngress, 19U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterH = (aWandererH + RotL64(aIngress, 52U)) + 15549114274303128055U;
            aOrbiterE = (((aWandererJ + RotL64(aCross, 47U)) + 16466750056388063241U) + aPhaseCOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1]) + aNonceWordM;
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 29U)) + RotL64(aCarry, 29U)) + 12209449840836787142U;
            aOrbiterG = ((aWandererG + RotL64(aScatter, 39U)) + 14551496099734294336U) + aNonceWordC;
            aOrbiterA = (aWandererA + RotL64(aPrevious, 43U)) + 6266576428679808622U;
            aOrbiterB = ((aWandererI + RotL64(aScatter, 3U)) + 16892841575635668152U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = ((aWandererD + RotL64(aCross, 18U)) + RotL64(aCarry, 3U)) + 7375966221423362125U;
            aOrbiterF = ((aWandererE + RotL64(aIngress, 11U)) + RotL64(aCarry, 37U)) + 11926105302821753530U;
            aOrbiterI = (aWandererF + RotL64(aPrevious, 23U)) + 16219253791550461124U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 7299056065319248160U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 15234001484933728439U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8182244796017018911U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 6615802589932632120U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 5481176858895819247U;
            aOrbiterA = RotL64((aOrbiterA * 3604590158551984877U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 17220507586542139380U) + aNonceWordB;
            aOrbiterC = (((aOrbiterC ^ aOrbiterB) ^ 14137921473739415340U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterC = RotL64((aOrbiterC * 10634645686035907603U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 16981960446540932787U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 10897565927079518588U;
            aOrbiterF = RotL64((aOrbiterF * 418843936329303571U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 2746889569299593263U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 4894117146736361379U;
            aOrbiterI = RotL64((aOrbiterI * 2656750612042673191U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 18294823016957137777U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 86828501068883383U;
            aOrbiterH = RotL64((aOrbiterH * 11432686669235402365U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 6322053762209547826U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 6754524552483363820U;
            aOrbiterG = RotL64((aOrbiterG * 1746163087826694641U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 7306452650619361017U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 12717201204443785828U;
            aOrbiterB = RotL64((aOrbiterB * 6121251603905574991U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 10422327053543898585U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 14786413282036348183U) ^ aNonceWordE;
            aOrbiterE = RotL64((aOrbiterE * 8713024293107068275U), 43U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 60U);
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterH, 19U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + RotL64(aOrbiterI, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aPrevious, 46U) + RotL64(aOrbiterB, 48U)) + aOrbiterI) + aNonceWordL) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterH, 41U)) + aOrbiterJ);
            aWandererD = aWandererD + ((((RotL64(aIngress, 57U) + aOrbiterA) + RotL64(aOrbiterF, 37U)) + RotL64(aCarry, 21U)) + aNonceWordA);
            aWandererF = aWandererF ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterJ, 29U)) + aOrbiterB) + aNonceWordP);
            aWandererG = aWandererG + ((RotL64(aScatter, 23U) + RotL64(aOrbiterE, 13U)) + aOrbiterI);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 19U) + aOrbiterC) + RotL64(aOrbiterJ, 24U));
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 14U) + aOrbiterC) + RotL64(aOrbiterE, 19U)) + RotL64(aCarry, 29U)) + aPhaseCWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 5U) + aOrbiterF) + RotL64(aOrbiterB, 57U));
            aWandererH = aWandererH + ((RotL64(aScatter, 27U) + RotL64(aOrbiterG, 53U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererF, 27U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererG, 52U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererJ, 35U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordI);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 19535U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((aIndex + 17551U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 22131U)) & S_BLOCK1], 50U) ^ RotL64(aOperationLaneC[((aIndex + 20018U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aIngress, 57U)) ^ (RotL64(aPrevious, 38U) + RotL64(aCross, 19U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterD = ((((aWandererC + RotL64(aPrevious, 13U)) + RotL64(aCarry, 19U)) + 5721224134332887360U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordD;
            aOrbiterG = (aWandererI + RotL64(aIngress, 57U)) + 6892749729775049095U;
            aOrbiterI = ((aWandererF + RotL64(aCross, 19U)) + RotL64(aCarry, 51U)) + 3884839462099556836U;
            aOrbiterF = (aWandererJ + RotL64(aScatter, 50U)) + 4365431706830216193U;
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 5U)) + 15501528746571578773U) + aNonceWordA;
            aOrbiterA = (aWandererB + RotL64(aScatter, 35U)) + 4505911326320650606U;
            aOrbiterC = ((aWandererE + RotL64(aCross, 43U)) + 1865129050927879580U) + aNonceWordJ;
            aOrbiterB = (((aWandererA + RotL64(aIngress, 39U)) + RotL64(aCarry, 11U)) + 2011737665969640369U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = (aWandererG + RotL64(aCross, 30U)) + 611672935827062688U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 663547038310431047U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 5468932264754299556U;
            aOrbiterI = RotL64((aOrbiterI * 11968657455484578525U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 17920294117231191705U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 486058453837528110U;
            aOrbiterD = RotL64((aOrbiterD * 8851102552244026737U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 2789178451938129313U) + aNonceWordB;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 420772587981211184U;
            aOrbiterF = RotL64((aOrbiterF * 17402987842294006667U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 16196774774442181825U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 16264169656793713547U;
            aOrbiterG = RotL64((aOrbiterG * 6900221986041638783U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 10207659833859860796U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 8593749091183323678U;
            aOrbiterK = RotL64((aOrbiterK * 10696776033512404927U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 7224922076047787384U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 15366267474865172373U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10134187073321814217U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 4235342515820080294U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 5239480080426950612U;
            aOrbiterC = RotL64((aOrbiterC * 12077621553561927079U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 10891752830598395582U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 7797358829694471108U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7621206775460997431U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 3755715857903753416U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 3172069024987421726U;
            aOrbiterH = RotL64((aOrbiterH * 16048490837178650865U), 27U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterC, 19U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 57U));
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 44U));
            aIngress = aIngress + RotL64(aOrbiterF, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aIngress, 5U) + aOrbiterA) + RotL64(aOrbiterC, 5U));
            aWandererB = aWandererB + (((RotL64(aCross, 11U) + aOrbiterG) + RotL64(aOrbiterA, 41U)) + RotL64(aCarry, 35U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 38U) + aOrbiterB) + RotL64(aOrbiterK, 46U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterB, 35U)) + aOrbiterC) + RotL64(aCarry, 57U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterI, 53U)) + aOrbiterH);
            aWandererG = aWandererG + (((RotL64(aCross, 27U) + aOrbiterF) + RotL64(aOrbiterD, 19U)) + aNonceWordO);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterI, 57U)) + aOrbiterC) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 34U) + RotL64(aOrbiterH, 13U)) + aOrbiterF) + aPhaseCWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterK, 30U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + (RotL64(aWandererG, 44U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererB, 53U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ aNonceWordH;
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 24598U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneB[((aIndex + 24645U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 31487U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 31224U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCross, 42U) + RotL64(aPrevious, 5U)) ^ (RotL64(aCarry, 21U) + RotL64(aIngress, 57U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterJ = (((aWandererG + RotL64(aScatter, 35U)) + 6068543441070417854U) + aPhaseCOrbiterAssignSaltC[((aIndex + 26U)) & S_SALT1]) + aNonceWordM;
            aOrbiterG = (((aWandererK + RotL64(aPrevious, 11U)) + 2995980468193441856U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordI;
            aOrbiterD = (aWandererA + RotL64(aCross, 43U)) + 18020277482171594003U;
            aOrbiterI = ((aWandererC + RotL64(aIngress, 19U)) + 4293807434721230702U) + aNonceWordJ;
            aOrbiterE = (aWandererJ + RotL64(aScatter, 4U)) + 7980599111583893156U;
            aOrbiterF = (aWandererE + RotL64(aIngress, 51U)) + 8593141111851052016U;
            aOrbiterA = ((aWandererB + RotL64(aCross, 39U)) + RotL64(aCarry, 11U)) + 5903487523900084325U;
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 23U)) + RotL64(aCarry, 47U)) + 15112035513447930209U;
            aOrbiterC = ((aWandererI + RotL64(aScatter, 60U)) + RotL64(aCarry, 29U)) + 9854037263057006439U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 16759760289688823193U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 12622628933030601390U;
            aOrbiterD = RotL64((aOrbiterD * 2151912984825538321U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 1264668857268123425U) + aNonceWordA;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 16302812053619101593U;
            aOrbiterE = RotL64((aOrbiterE * 18291400055836111547U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 16087995784896123610U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 7970269262800468363U;
            aOrbiterA = RotL64((aOrbiterA * 14924752223305807461U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 5331477046030959632U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 16534913204255550893U;
            aOrbiterJ = RotL64((aOrbiterJ * 1013433634373673565U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 11042821902537871209U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 8069677512345031660U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13622218526054132397U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 5737130058129936372U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 1076627182956662997U;
            aOrbiterF = RotL64((aOrbiterF * 14342191224014199929U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 13911061091801078190U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 15397603151098990373U;
            aOrbiterH = RotL64((aOrbiterH * 1802890451633592245U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 15137326716738637972U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 11248737008959896786U;
            aOrbiterC = RotL64((aOrbiterC * 90789374131547005U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 1847847987633923657U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 10560748778679145431U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2919333327817231099U), 23U);
            //
            aIngress = RotL64(aOrbiterA, 50U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterC, 35U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 11U));
            aIngress = aIngress + (RotL64(aOrbiterI, 41U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterG, 18U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aIngress, 5U) + aOrbiterF) + RotL64(aOrbiterH, 38U)) + RotL64(aCarry, 37U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 39U) + aOrbiterF) + RotL64(aOrbiterI, 47U));
            aWandererA = aWandererA + (((RotL64(aCross, 43U) + RotL64(aOrbiterD, 19U)) + aOrbiterI) + RotL64(aCarry, 27U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 34U) + aOrbiterD) + RotL64(aOrbiterJ, 57U)) + aNonceWordK);
            aWandererB = aWandererB + ((RotL64(aPrevious, 57U) + aOrbiterA) + RotL64(aOrbiterF, 3U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterC, 29U)) + aOrbiterJ) + aNonceWordP);
            aWandererD = aWandererD + (((RotL64(aScatter, 23U) + RotL64(aOrbiterI, 24U)) + aOrbiterG) + aPhaseCWandererUpdateSaltD[((aIndex + 12U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 52U) + RotL64(aOrbiterD, 11U)) + aOrbiterE) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterG, 43U)) + aOrbiterC) + aNonceWordH);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 26U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 37U));
            aCarry = aCarry + RotL64(aWandererB, 19U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ aNonceWordB;
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

void TwistExpander_Tennis_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x8B88D292AF21F227ULL + 0xD337C7ED68F68DD6ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xB07A58921EFE4E71ULL + 0x9729F688AFCBC71AULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xBB0835A0F437D865ULL + 0xA9B690932322BE55ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x81BE738ECBC3A70FULL + 0xC3148FF13E79397FULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xB1FB9AC9C86F5E77ULL + 0xA9804680C7ECE496ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xBDC1BF5F321AB901ULL + 0xA1BC2B853B397650ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x89BAED37C4F2E9EBULL + 0x9B75D36C1047BB44ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xA82CE6C5E6EBBC1BULL + 0xB4679EFD781D13E0ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xDA823B452D036DB1ULL + 0xA20B35A732583B58ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x9E22940A10711B65ULL + 0xE025A596601341B2ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xAD11598C4BD66901ULL + 0xD275D6BC55C4A0A4ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x93ABBB90CB56EE59ULL + 0xD93EF00107A22C9CULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x86BDE77A2A1353ABULL + 0xCA27F445667F3C0AULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xE0C35C6324D7C6BBULL + 0xB620B09A2360EE20ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x8C53F799774DD347ULL + 0xFC80B16BFEDD85C7ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xF7CAF11E83EBB6F7ULL + 0xAA476605186EE05DULL);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 5452U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 734U)) & S_BLOCK1], 42U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 741U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 3021U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 19U) + RotL64(aPrevious, 35U)) ^ (RotL64(aIngress, 4U) + RotL64(aCross, 53U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterH = (aWandererG + RotL64(aPrevious, 35U)) + 14499676118633326000U;
            aOrbiterG = (aWandererB + RotL64(aIngress, 43U)) + 17191273593018552288U;
            aOrbiterC = ((aWandererH + RotL64(aScatter, 39U)) + 4085176294948097737U) + aNonceWordD;
            aOrbiterK = (aWandererJ + RotL64(aCross, 6U)) + 11112671474158908186U;
            aOrbiterF = (((aWandererE + RotL64(aScatter, 41U)) + RotL64(aCarry, 27U)) + 8745787969012266485U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = (((aWandererK + RotL64(aPrevious, 23U)) + RotL64(aCarry, 41U)) + 18074049663777707948U) + aNonceWordG;
            aOrbiterI = (((aWandererI + RotL64(aCross, 3U)) + RotL64(aCarry, 5U)) + 2543758649719164688U) + aPhaseDOrbiterAssignSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = (aWandererA + RotL64(aIngress, 57U)) + 4659584749412700523U;
            aOrbiterA = (aWandererF + RotL64(aScatter, 19U)) + 974639159259871273U;
            aOrbiterE = (aWandererD + RotL64(aCross, 54U)) + 9211220687971081987U;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 47U)) + 8567024626862182714U) + aNonceWordF;
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 5803002132294840900U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 11968489432878148467U) ^ aNonceWordK;
            aOrbiterC = RotL64((aOrbiterC * 4501441062617123165U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 9470807228394903442U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 1692347973120388469U;
            aOrbiterB = RotL64((aOrbiterB * 17433393164156231575U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 16510815732690193145U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 755159406833096510U;
            aOrbiterH = RotL64((aOrbiterH * 14091736464659561165U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 1518824876475937620U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 701225390867330446U;
            aOrbiterK = RotL64((aOrbiterK * 12264618860580199927U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 8425976693733003889U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 7182176375442410367U;
            aOrbiterI = RotL64((aOrbiterI * 8860605703761731859U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 4546566785167467924U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 2593340999038753749U;
            aOrbiterA = RotL64((aOrbiterA * 10152461487764567563U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 9756331608356622299U) + aNonceWordI;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 5511625814747641978U;
            aOrbiterD = RotL64((aOrbiterD * 4806076157539829529U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 8694400787420160733U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 12648969491371382682U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5346585704222643759U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 15261238546696118531U) + aNonceWordL;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 14236129054778329471U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11789581469516267749U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 16251500056378064213U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 790320176607605195U;
            aOrbiterJ = RotL64((aOrbiterJ * 15706130623435648555U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 17114773669444878655U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 14499676118633326000U;
            aOrbiterE = RotL64((aOrbiterE * 8095707555083587081U), 47U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterF, 13U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 37U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 51U));
            aIngress = aIngress + (RotL64(aOrbiterK, 26U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterC, 3U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aIngress, 11U) + aOrbiterI) + RotL64(aOrbiterC, 18U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 35U) + aOrbiterB) + RotL64(aOrbiterF, 27U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 13U) + aOrbiterJ) + RotL64(aOrbiterD, 3U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 60U) + RotL64(aOrbiterH, 37U)) + aOrbiterB) + aNonceWordM);
            aWandererC = aWandererC + ((((RotL64(aIngress, 27U) + RotL64(aOrbiterD, 43U)) + aOrbiterH) + RotL64(aCarry, 3U)) + aPhaseDWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 51U) + aOrbiterK) + RotL64(aOrbiterJ, 11U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 19U) + aOrbiterJ) + RotL64(aOrbiterH, 39U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 58U) + RotL64(aOrbiterH, 13U)) + aOrbiterI);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 5U) + aOrbiterA) + RotL64(aOrbiterD, 57U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 37U) + aOrbiterG) + RotL64(aOrbiterF, 35U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 21U) + aOrbiterH) + RotL64(aOrbiterE, 54U)) + RotL64(aCarry, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 58U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererA, 37U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererC);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 21U));
            aCarry = aCarry + RotL64(aWandererK, 5U);
            aCarry = aCarry + RotL64(aIngress, 56U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordF);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 6531U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 8310U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 10868U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 10425U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 24U) ^ RotL64(aPrevious, 51U)) ^ (RotL64(aIngress, 3U) + RotL64(aCross, 37U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 51U)) + RotL64(aCarry, 57U)) + 12046647397183218524U;
            aOrbiterF = (aWandererJ + RotL64(aIngress, 60U)) + 2760779375026461991U;
            aOrbiterD = ((aWandererD + RotL64(aCross, 53U)) + 13735454443176855650U) + aNonceWordP;
            aOrbiterJ = (aWandererH + RotL64(aScatter, 27U)) + 4370377000586647724U;
            aOrbiterG = (((aWandererE + RotL64(aCross, 13U)) + RotL64(aCarry, 13U)) + 14566322384189969094U) + aNonceWordH;
            aOrbiterE = (aWandererG + RotL64(aScatter, 3U)) + 5056565959818422786U;
            aOrbiterH = ((aWandererC + RotL64(aIngress, 21U)) + RotL64(aCarry, 43U)) + 8795403810686579209U;
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 41U)) + 9625947666256011567U) + aPhaseDOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = (aWandererI + RotL64(aIngress, 57U)) + 1703669290934254701U;
            aOrbiterI = (aWandererA + RotL64(aScatter, 18U)) + 6664070663184147951U;
            aOrbiterA = ((aWandererF + RotL64(aCross, 11U)) + 2104148316797553431U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 1197910004222596145U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 9922977170060903197U) ^ aNonceWordI;
            aOrbiterD = RotL64((aOrbiterD * 13047828062605568603U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 2048376210852567829U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 12568990647075931409U;
            aOrbiterF = RotL64((aOrbiterF * 9860242601194210927U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 15026894775772902751U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 3439447160137900629U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1813754963043785165U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 6532671388552829796U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 17261098369835997661U;
            aOrbiterH = RotL64((aOrbiterH * 568292591215203521U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 3171300991007459947U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 5935563269327662024U;
            aOrbiterB = RotL64((aOrbiterB * 11271790283157765003U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 14290941734320455612U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 12371794745736518824U;
            aOrbiterK = RotL64((aOrbiterK * 12208762336145168647U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 8782840145467637373U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 4067525421190366741U;
            aOrbiterJ = RotL64((aOrbiterJ * 6671002797916227485U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 11854812920571789853U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 17564890418553131451U;
            aOrbiterE = RotL64((aOrbiterE * 16657184504366731805U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 6250004085193517531U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 2362659992682660827U;
            aOrbiterC = RotL64((aOrbiterC * 4365619310373869859U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 4597159873252831182U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 13197238269207675773U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 379653377172816575U), 23U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterD) + 8552479493772820372U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1]) + aNonceWordD;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 12046647397183218524U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17918033655125400323U), 51U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterD, 53U);
            aIngress = aIngress + (RotL64(aOrbiterK, 51U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterH, 41U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 23U));
            aIngress = aIngress + (RotL64(aOrbiterF, 19U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterC, 34U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aPrevious, 50U) + RotL64(aOrbiterC, 27U)) + aOrbiterF) + RotL64(aCarry, 11U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 5U) + aOrbiterI) + RotL64(aOrbiterA, 13U));
            aWandererF = aWandererF + ((RotL64(aScatter, 41U) + aOrbiterJ) + RotL64(aOrbiterI, 23U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterG, 29U)) + aOrbiterJ);
            aWandererG = aWandererG + ((RotL64(aScatter, 11U) + RotL64(aOrbiterF, 48U)) + aOrbiterK);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 23U) + aOrbiterC) + RotL64(aOrbiterD, 43U)) + aNonceWordA);
            aWandererI = aWandererI + ((RotL64(aCross, 52U) + aOrbiterH) + RotL64(aOrbiterA, 21U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 37U) + aOrbiterK) + RotL64(aOrbiterB, 51U));
            aWandererD = aWandererD + (((((RotL64(aCross, 13U) + RotL64(aOrbiterI, 11U)) + aOrbiterK) + RotL64(aCarry, 35U)) + aNonceWordO) + aPhaseDWandererUpdateSaltE[((aIndex + 10U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 35U) + aOrbiterJ) + RotL64(aOrbiterF, 57U));
            aWandererA = aWandererA + (((RotL64(aScatter, 21U) + aOrbiterF) + RotL64(aOrbiterE, 46U)) + aPhaseDWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 58U) ^ aWandererH);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + (RotL64(aWandererD, 60U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererB, 29U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordK);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 12892U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 15866U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 11297U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneC[((aIndex + 11450U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 44U)) + (RotL64(aCross, 27U) ^ RotL64(aIngress, 5U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 19U)) + 2786079456995203065U) + aNonceWordN;
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 38U)) + 7237256119153857253U) + aPhaseDOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = (aWandererF + RotL64(aScatter, 27U)) + 9310834010563647604U;
            aOrbiterI = (aWandererI + RotL64(aIngress, 21U)) + 17361734905706517877U;
            aOrbiterH = (((aWandererK + RotL64(aScatter, 41U)) + RotL64(aCarry, 5U)) + 15837111231884647451U) + aNonceWordG;
            aOrbiterA = ((aWandererH + RotL64(aIngress, 30U)) + RotL64(aCarry, 37U)) + 18065431964418026445U;
            aOrbiterD = (aWandererB + RotL64(aCross, 57U)) + 3029123922999952652U;
            aOrbiterG = (aWandererA + RotL64(aPrevious, 47U)) + 5166926595573507837U;
            aOrbiterF = (((aWandererG + RotL64(aCross, 5U)) + RotL64(aCarry, 57U)) + 1918425684273807598U) + aNonceWordE;
            aOrbiterC = ((aWandererD + RotL64(aScatter, 43U)) + 4724551751012661440U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterE = (aWandererC + RotL64(aPrevious, 11U)) + 1818014487579644390U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 6670090372241084216U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 8485757110007268693U;
            aOrbiterB = RotL64((aOrbiterB * 11876760095108618363U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 4928130251509514742U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 2528788422725346792U;
            aOrbiterA = RotL64((aOrbiterA * 1855982047967756661U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 2860387120895147503U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 12927802338151379368U;
            aOrbiterK = RotL64((aOrbiterK * 8876144125458603029U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 18029699867733207083U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 13361836994951253312U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5349767426256597073U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 11957294454794128079U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 3755417922063414648U;
            aOrbiterG = RotL64((aOrbiterG * 13896364063651241401U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 18001157153447913032U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 16214145724690286854U;
            aOrbiterC = RotL64((aOrbiterC * 5874139687703360515U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 3860958772090975562U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 12395621524459640173U;
            aOrbiterJ = RotL64((aOrbiterJ * 722817135977510161U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 3402035664910754484U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 2139099117325745602U;
            aOrbiterI = RotL64((aOrbiterI * 14008983756425796029U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 7769274487425053026U) + aNonceWordJ;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 6492669707749367728U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5149771861620757839U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 14963366447884375043U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 11398874662567519691U;
            aOrbiterF = RotL64((aOrbiterF * 8221521452475029835U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 7168445485232814860U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 2786079456995203065U;
            aOrbiterE = RotL64((aOrbiterE * 14258367164534307955U), 37U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterB, 37U);
            aIngress = aIngress + (RotL64(aOrbiterA, 34U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterK, 41U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 13U));
            aIngress = aIngress + RotL64(aOrbiterF, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aPrevious, 37U) + RotL64(aOrbiterD, 5U)) + aOrbiterI);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterH, 41U)) + aOrbiterI) + aNonceWordL);
            aWandererA = aWandererA + ((RotL64(aCross, 29U) + aOrbiterG) + RotL64(aOrbiterH, 46U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 12U) + RotL64(aOrbiterE, 35U)) + aOrbiterB);
            aWandererD = aWandererD + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterH, 39U)) + aOrbiterD);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 43U) + aOrbiterF) + RotL64(aOrbiterG, 51U));
            aWandererI = aWandererI + ((((RotL64(aCross, 35U) + RotL64(aOrbiterC, 57U)) + aOrbiterG) + RotL64(aCarry, 47U)) + aPhaseDWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterA, 29U)) + aOrbiterI);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterJ, 3U)) + aOrbiterF) + aNonceWordO);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 46U) + RotL64(aOrbiterE, 21U)) + aOrbiterK);
            aWandererB = aWandererB + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterK, 18U)) + aOrbiterH) + RotL64(aCarry, 57U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 37U));
            aCarry = aCarry + (RotL64(aWandererA, 26U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererJ);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 21U));
            aCarry = aCarry + RotL64(aWandererF, 34U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 19698U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 16751U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 20474U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneD[((aIndex + 21613U)) & S_BLOCK1], 28U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aIngress, 11U)) ^ (RotL64(aPrevious, 35U) + RotL64(aCarry, 58U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterB = (aWandererG + RotL64(aIngress, 11U)) + 15813325389431304548U;
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 48U)) + 2223874171125403602U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = (aWandererD + RotL64(aCross, 21U)) + 5510483568496824130U;
            aOrbiterE = (aWandererI + RotL64(aScatter, 29U)) + 15474152493495661876U;
            aOrbiterA = ((aWandererH + RotL64(aCross, 35U)) + RotL64(aCarry, 19U)) + 16846339705130829195U;
            aOrbiterF = ((aWandererF + RotL64(aScatter, 53U)) + RotL64(aCarry, 51U)) + 1289670576865739669U;
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 51U)) + 18017354919647006944U) + aPhaseDOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = ((aWandererB + RotL64(aIngress, 13U)) + 8539685539928984921U) + aNonceWordJ;
            aOrbiterJ = ((aWandererE + RotL64(aCross, 40U)) + 3333721400836704048U) + aNonceWordN;
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 37U)) + RotL64(aCarry, 57U)) + 2261560416623815491U;
            aOrbiterK = (aWandererC + RotL64(aIngress, 27U)) + 4377786131746816567U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 18047393176583722719U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 8184724021940434631U;
            aOrbiterI = RotL64((aOrbiterI * 9800116157750921119U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 10469895939183324807U) + aNonceWordM;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 14543391765109879223U;
            aOrbiterA = RotL64((aOrbiterA * 4817987697437667225U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 5757225781746158178U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 3539000495894022869U;
            aOrbiterF = RotL64((aOrbiterF * 1032298408884695925U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 11288971092707065923U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 2761384065186568294U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3323838837427471051U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 7120580145300417101U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 6977246291769372866U;
            aOrbiterD = RotL64((aOrbiterD * 15170353875184253779U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 17625434527765525937U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 3299714663631376190U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6532628892760776767U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 10331889953489885250U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 8550932256881727932U;
            aOrbiterH = RotL64((aOrbiterH * 13085531621192583719U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 11151195711186126257U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 2552002192824926483U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9754056316698523849U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 8038115194286715268U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 16594489591573505305U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1241387574663818247U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 13476964484361081681U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 2136330439951908303U;
            aOrbiterG = RotL64((aOrbiterG * 12728359054660550527U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 231990686776499700U) + aNonceWordA;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 15813325389431304548U;
            aOrbiterE = RotL64((aOrbiterE * 9155088985405261637U), 39U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterG, 43U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 23U));
            aIngress = aIngress + (RotL64(aOrbiterA, 35U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterF, 39U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 30U));
            aIngress = aIngress + RotL64(aOrbiterE, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterH, 60U)) + aOrbiterE);
            aWandererC = aWandererC + (((RotL64(aScatter, 5U) + aOrbiterA) + RotL64(aOrbiterH, 23U)) + aNonceWordD);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 24U) + RotL64(aOrbiterB, 41U)) + aOrbiterC);
            aWandererB = aWandererB + (((RotL64(aIngress, 11U) + aOrbiterF) + RotL64(aOrbiterH, 19U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 43U) + aOrbiterD) + RotL64(aOrbiterG, 39U));
            aWandererG = aWandererG + (((RotL64(aIngress, 27U) + aOrbiterD) + RotL64(aOrbiterA, 57U)) + RotL64(aCarry, 39U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterC, 21U)) + aOrbiterF);
            aWandererE = aWandererE + (((RotL64(aPrevious, 3U) + aOrbiterI) + RotL64(aOrbiterJ, 27U)) + RotL64(aCarry, 43U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterH, 5U)) + aOrbiterK);
            aWandererD = aWandererD + ((RotL64(aCross, 40U) + RotL64(aOrbiterI, 30U)) + aOrbiterD);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 35U) + aOrbiterK) + RotL64(aOrbiterB, 51U)) + aPhaseDWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 39U) ^ aWandererJ);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 60U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 5U));
            aCarry = aCarry + (RotL64(aWandererD, 21U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererC, 51U);
            aCarry = aCarry + RotL64(aIngress, 24U);
            aCarry = aCarry ^ aNonceWordC;
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 25976U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneA[((aIndex + 26945U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 26638U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 26499U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 13U) ^ RotL64(aCarry, 60U)) + (RotL64(aCross, 27U) ^ RotL64(aIngress, 47U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterI = ((aWandererA + RotL64(aIngress, 27U)) + 4739486756133131180U) + aNonceWordK;
            aOrbiterD = ((aWandererH + RotL64(aCross, 53U)) + 16089707555501328184U) + aNonceWordP;
            aOrbiterH = (aWandererK + RotL64(aScatter, 37U)) + 15310047330238536453U;
            aOrbiterG = (aWandererC + RotL64(aPrevious, 10U)) + 7901411596386834955U;
            aOrbiterB = (((aWandererJ + RotL64(aScatter, 43U)) + RotL64(aCarry, 27U)) + 4357555491060982163U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = ((aWandererG + RotL64(aIngress, 19U)) + RotL64(aCarry, 37U)) + 15667085602825720102U;
            aOrbiterJ = (aWandererF + RotL64(aCross, 47U)) + 8520635334382269253U;
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 41U)) + RotL64(aCarry, 53U)) + 1772509779231068315U;
            aOrbiterC = ((aWandererB + RotL64(aIngress, 51U)) + 15336170957886025677U) + aPhaseDOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = (aWandererE + RotL64(aScatter, 4U)) + 8628770833489469980U;
            aOrbiterE = (aWandererD + RotL64(aCross, 57U)) + 15469234024247246228U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 10796430900884288328U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 10660110397012853289U;
            aOrbiterH = RotL64((aOrbiterH * 9140007610912037461U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 11202284258711214794U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 17509491802893182994U;
            aOrbiterF = RotL64((aOrbiterF * 9329107599972703671U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 16212572740740103554U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 2190030203761579226U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3101886685668871045U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 12014337082293041909U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 3733531010807001506U;
            aOrbiterK = RotL64((aOrbiterK * 5797362244066062299U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 7100994963061975529U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 17837541162838600258U;
            aOrbiterI = RotL64((aOrbiterI * 8745987361678166553U), 35U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterK) + 3311518938023146951U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordF;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 7709505172646831553U;
            aOrbiterG = RotL64((aOrbiterG * 7121143171245765213U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 4979968094554018443U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 16822214821463034107U;
            aOrbiterJ = RotL64((aOrbiterJ * 8618262120451291765U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 8376124175020587079U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 11084586282092424876U;
            aOrbiterC = RotL64((aOrbiterC * 5835632742522563537U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 7816368455027681621U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 10893292019060642422U;
            aOrbiterE = RotL64((aOrbiterE * 3995821210667317677U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 13602875505184178486U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 5425735673005681983U;
            aOrbiterD = RotL64((aOrbiterD * 12667085597129312079U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 5995385043278810987U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 4739486756133131180U;
            aOrbiterB = RotL64((aOrbiterB * 15709273328685013399U), 5U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterH, 26U);
            aIngress = aIngress + (RotL64(aOrbiterA, 47U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 19U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 51U));
            aIngress = aIngress + (RotL64(aOrbiterK, 44U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterC, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aIngress, 13U) + aOrbiterD) + RotL64(aOrbiterI, 37U)) + RotL64(aCarry, 29U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 48U) + aOrbiterA) + RotL64(aOrbiterB, 47U)) + aNonceWordJ);
            aWandererA = aWandererA + ((RotL64(aScatter, 5U) + aOrbiterF) + RotL64(aOrbiterJ, 23U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterI, 3U)) + aOrbiterK);
            aWandererG = aWandererG + ((RotL64(aCross, 37U) + aOrbiterH) + RotL64(aOrbiterE, 14U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 39U) + aOrbiterJ) + RotL64(aOrbiterC, 29U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 11U) + RotL64(aOrbiterB, 51U)) + aOrbiterG) + aNonceWordG) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 57U) + aOrbiterD) + RotL64(aOrbiterE, 5U));
            aWandererC = aWandererC + ((RotL64(aCross, 3U) + aOrbiterK) + RotL64(aOrbiterE, 27U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterH, 19U)) + aOrbiterJ);
            aWandererD = aWandererD + ((((RotL64(aScatter, 18U) + aOrbiterJ) + RotL64(aOrbiterA, 12U)) + RotL64(aCarry, 21U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 6U));
            aCarry = aCarry + (RotL64(aWandererH, 39U) ^ aWandererK);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + (RotL64(aWandererI, 20U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererE, 57U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ aNonceWordD;
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 29788U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneB[((aIndex + 31662U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 28628U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31426U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 43U) + RotL64(aCross, 60U)) ^ (RotL64(aCarry, 11U) + RotL64(aIngress, 23U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterD = (aWandererK + RotL64(aScatter, 3U)) + 7948891781097675369U;
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 21U)) + 13928362874228230226U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = (((aWandererJ + RotL64(aIngress, 39U)) + RotL64(aCarry, 23U)) + 10776180542602258926U) + aNonceWordC;
            aOrbiterH = ((aWandererF + RotL64(aCross, 37U)) + RotL64(aCarry, 53U)) + 5735115172149470447U;
            aOrbiterB = (aWandererA + RotL64(aIngress, 34U)) + 5353591822981766987U;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 11U)) + 562301708107268570U) + aPhaseDOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = (aWandererI + RotL64(aScatter, 53U)) + 10467810247578364868U;
            aOrbiterE = (aWandererD + RotL64(aCross, 19U)) + 14541630141152308564U;
            aOrbiterJ = (aWandererG + RotL64(aIngress, 6U)) + 2350076897065139429U;
            aOrbiterF = (aWandererE + RotL64(aScatter, 41U)) + 17519109078651162228U;
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 51U)) + RotL64(aCarry, 37U)) + 6061035173339902910U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 15654836633731000065U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 13723521735153718904U;
            aOrbiterC = RotL64((aOrbiterC * 14459516479283070563U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 2849680038315532197U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 17336102435576647923U;
            aOrbiterB = RotL64((aOrbiterB * 10984689101753586739U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 7671010488872356142U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 11485114338165600777U) ^ aNonceWordA;
            aOrbiterG = RotL64((aOrbiterG * 4162584865462407791U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 8759060657343458985U) + aNonceWordP;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 11009137869375286581U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8741417343929809115U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 15792999392743144135U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 6180808423175992479U;
            aOrbiterE = RotL64((aOrbiterE * 13681230339693676907U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 361487389591183005U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 15292753806514404853U;
            aOrbiterJ = RotL64((aOrbiterJ * 17478232597253311153U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 14929153438443362045U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 7904556383593914086U;
            aOrbiterF = RotL64((aOrbiterF * 2484130486635511403U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 3793180909904286848U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 10391957637467171320U;
            aOrbiterI = RotL64((aOrbiterI * 505484041943467117U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 11648765065563798353U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 17601185776537566611U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4753179291885740011U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 2907499704986356444U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 17048858067202291241U;
            aOrbiterK = RotL64((aOrbiterK * 2607549567999666889U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 4340465159886930775U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 7948891781097675369U;
            aOrbiterH = RotL64((aOrbiterH * 12913104720552907335U), 3U);
            //
            aIngress = RotL64(aOrbiterB, 13U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 19U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 36U));
            aIngress = aIngress + (RotL64(aOrbiterK, 21U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterA, 47U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterG, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aCross, 57U) + RotL64(aOrbiterA, 6U)) + aOrbiterG) + aPhaseDWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterB, 21U)) + aOrbiterD);
            aWandererH = aWandererH + (((RotL64(aPrevious, 51U) + aOrbiterE) + RotL64(aOrbiterJ, 53U)) + RotL64(aCarry, 35U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 21U) + aOrbiterJ) + RotL64(aOrbiterH, 37U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 37U) + RotL64(aOrbiterD, 11U)) + aOrbiterK);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 6U) + aOrbiterH) + RotL64(aOrbiterE, 47U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aScatter, 29U) + RotL64(aOrbiterI, 43U)) + aOrbiterA);
            aWandererE = aWandererE ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterB, 3U)) + aOrbiterF);
            aWandererI = aWandererI + (((RotL64(aScatter, 35U) + aOrbiterI) + RotL64(aOrbiterC, 60U)) + aNonceWordL);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 44U) + aOrbiterC) + RotL64(aOrbiterB, 29U));
            aWandererF = aWandererF + (((RotL64(aCross, 39U) + aOrbiterI) + RotL64(aOrbiterH, 27U)) + RotL64(aCarry, 19U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 10U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererJ);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 37U));
            aCarry = aCarry + RotL64(aWandererB, 27U);
            aCarry = aCarry + RotL64(aIngress, 34U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordE);
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

void TwistExpander_Tennis_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x92C04D72C0D78997ULL + 0x8A0BB9958BFBA92CULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xCF4575CC08EE7F4BULL + 0xE82C47E0E30E4890ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xD33277FD15459D71ULL + 0xE73CD3A1B66C3FCCULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x8E35A118D1E0E9B3ULL + 0xB61A43669FD16BA4ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xBC109434AEEAD3C5ULL + 0xA6EA7F6AD961432FULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xE36518E555E045A1ULL + 0xAD24F94DFF956748ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xA08B3AEAA214D2D9ULL + 0x8E73C633D395E052ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xAF34A64495E78511ULL + 0xCCCDC19D6EA22665ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xB5D477CC00CD6C9FULL + 0xC8F8C96A8074619DULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xFD676BAB03C6443BULL + 0xD2A516D3D0E08FE9ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xA8E398D5C3391191ULL + 0xD7DBC6896302D610ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x9FA23AE6C338A88FULL + 0xA3401A4B36BC6532ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xCBA1479ADB626AD9ULL + 0xE35B2C878C75B135ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xACA88FA800197585ULL + 0xCE77625C4ECA130FULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xFAD0DDA46594B197ULL + 0xB4E1CC9A0AB65A59ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xABF6D43804471995ULL + 0xFB00B4029E04CE4CULL);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 2472U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 3946U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 2202U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 1571U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aIngress, 5U)) ^ (RotL64(aCross, 39U) + RotL64(aPrevious, 22U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 37U)) + 8975885703279267062U) + aPhaseEOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = ((aWandererE + RotL64(aScatter, 51U)) + RotL64(aCarry, 47U)) + 8664844915562660637U;
            aOrbiterF = (aWandererD + RotL64(aIngress, 18U)) + 12281774799736296726U;
            aOrbiterJ = (aWandererJ + RotL64(aCross, 27U)) + 15347461352311329726U;
            aOrbiterB = (((aWandererI + RotL64(aPrevious, 43U)) + 12967500561828907834U) + aPhaseEOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1]) + aNonceWordF;
            aOrbiterG = (aWandererK + RotL64(aScatter, 29U)) + 5002833859280402726U;
            aOrbiterE = (((aWandererC + RotL64(aCross, 41U)) + RotL64(aCarry, 29U)) + 11908257536954668983U) + aNonceWordN;
            aOrbiterC = (aWandererB + RotL64(aIngress, 23U)) + 17017174811949227162U;
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 47U)) + RotL64(aCarry, 41U)) + 16851323125613931180U;
            aOrbiterI = ((aWandererF + RotL64(aCross, 11U)) + 13469326957728686706U) + aNonceWordK;
            aOrbiterK = (aWandererH + RotL64(aIngress, 58U)) + 5228638551056105241U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 11945166198089308564U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 16268645041872996022U;
            aOrbiterF = RotL64((aOrbiterF * 5391448793718370911U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 14781204627695095701U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 5365325354838101092U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8017284997946310807U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 563147416025715953U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 14660867395395625851U;
            aOrbiterH = RotL64((aOrbiterH * 4769458126865307103U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 3168989056355712105U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 16179131669773665579U;
            aOrbiterJ = RotL64((aOrbiterJ * 5641461617066671723U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 4160220074225527179U) + aNonceWordH;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 8597134686962559111U;
            aOrbiterE = RotL64((aOrbiterE * 639572585431474015U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 16811551552456811661U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 5827323970423386301U;
            aOrbiterD = RotL64((aOrbiterD * 9328247349730652021U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 15583234353262170227U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 2950816254621717748U;
            aOrbiterK = RotL64((aOrbiterK * 1102417597476170143U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 4426165025104306337U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 11871220132164971152U;
            aOrbiterA = RotL64((aOrbiterA * 2366168050042802207U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 3832424136113939717U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 17673885217916768611U;
            aOrbiterB = RotL64((aOrbiterB * 10887063696370811871U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 3479289844909914390U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 9498461576098567546U;
            aOrbiterC = RotL64((aOrbiterC * 8734492074299676555U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 10645314291190544864U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 8975885703279267062U;
            aOrbiterI = RotL64((aOrbiterI * 16584086014947250551U), 51U);
            //
            aIngress = RotL64(aOrbiterF, 29U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterH, 51U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterB, 20U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 23U));
            aIngress = aIngress + RotL64(aOrbiterI, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 27U) + aOrbiterI) + RotL64(aOrbiterD, 19U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 60U) + aOrbiterA) + RotL64(aOrbiterB, 50U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterI, 27U)) + aOrbiterB) + aNonceWordC);
            aWandererA = aWandererA + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterB, 29U)) + aOrbiterJ) + RotL64(aCarry, 43U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 35U) + aOrbiterG) + RotL64(aOrbiterI, 11U));
            aWandererE = aWandererE + (((RotL64(aIngress, 41U) + RotL64(aOrbiterJ, 42U)) + aOrbiterE) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 47U) + aOrbiterF) + RotL64(aOrbiterK, 53U)) + aPhaseEWandererUpdateSaltD[((aIndex + 28U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 30U) + RotL64(aOrbiterB, 3U)) + aOrbiterH) + RotL64(aCarry, 37U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 21U) + aOrbiterK) + RotL64(aOrbiterH, 21U));
            aWandererG = aWandererG + (((RotL64(aScatter, 19U) + RotL64(aOrbiterC, 5U)) + aOrbiterF) + aNonceWordD);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterA, 47U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + (RotL64(aWandererK, 21U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 58U));
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererI, 43U);
            aCarry = aCarry + RotL64(aIngress, 18U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordH);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 7337U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneD[((aIndex + 9312U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 10912U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneB[((aIndex + 9234U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aIngress, 43U)) + (RotL64(aPrevious, 26U) + RotL64(aCross, 13U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterG = ((aWandererA + RotL64(aCross, 43U)) + RotL64(aCarry, 37U)) + 6069475454765660321U;
            aOrbiterH = ((aWandererH + RotL64(aScatter, 27U)) + 11483704742497268068U) + aNonceWordO;
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 47U)) + RotL64(aCarry, 43U)) + 11055697447388986418U;
            aOrbiterB = ((aWandererC + RotL64(aIngress, 50U)) + 10897095046039997004U) + aNonceWordJ;
            aOrbiterI = ((aWandererB + RotL64(aScatter, 37U)) + RotL64(aCarry, 57U)) + 4731637118230457840U;
            aOrbiterD = (aWandererI + RotL64(aPrevious, 35U)) + 13855839187084986751U;
            aOrbiterA = ((aWandererD + RotL64(aCross, 13U)) + 5328208115460188239U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = ((aWandererE + RotL64(aIngress, 21U)) + 12479538544291412985U) + aPhaseEOrbiterAssignSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 5U)) + 10740165998792608231U) + aNonceWordL;
            aOrbiterF = (aWandererF + RotL64(aScatter, 3U)) + 6492798157284955373U;
            aOrbiterK = (aWandererJ + RotL64(aIngress, 58U)) + 13056825957483891921U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 2068184064919194657U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 5656302738780746294U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16493021179127646345U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 11193756120230763294U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterB) ^ 17306750816837208999U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterH = RotL64((aOrbiterH * 7949360041241439741U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 12952818800389361804U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 15380412293642628312U;
            aOrbiterI = RotL64((aOrbiterI * 2914662289178925547U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 7706090204767242996U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 14598802276412649570U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4821408736292041399U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 17819762117328075515U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 6481384240915075101U;
            aOrbiterJ = RotL64((aOrbiterJ * 4836701121865783029U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 754936290510338717U) + aNonceWordH;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 15510875946573720154U;
            aOrbiterG = RotL64((aOrbiterG * 2994718968852184303U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 9245381722813944586U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 2629847912019726214U;
            aOrbiterB = RotL64((aOrbiterB * 6718795794951106961U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 3909987749797113773U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 9277056074757335265U;
            aOrbiterD = RotL64((aOrbiterD * 11580847505996697115U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 12577180954515966707U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 9144513680789115458U;
            aOrbiterC = RotL64((aOrbiterC * 8880777678193004979U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 1544232962956974411U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 2658275904714859636U;
            aOrbiterF = RotL64((aOrbiterF * 1926083316365175327U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 5733515391293514025U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 6069475454765660321U;
            aOrbiterK = RotL64((aOrbiterK * 9627476106108146391U), 13U);
            //
            aIngress = RotL64(aOrbiterJ, 23U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 43U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 37U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + (RotL64(aOrbiterI, 39U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterC, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 60U) + RotL64(aOrbiterF, 34U)) + aOrbiterA);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 3U) + aOrbiterA) + RotL64(aOrbiterC, 39U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 13U) + aOrbiterG) + RotL64(aOrbiterI, 51U)) + aPhaseEWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 57U) + RotL64(aOrbiterC, 27U)) + aOrbiterD) + aNonceWordD);
            aWandererG = aWandererG ^ ((RotL64(aCross, 20U) + aOrbiterF) + RotL64(aOrbiterK, 47U));
            aWandererE = aWandererE + (((((RotL64(aScatter, 53U) + aOrbiterH) + RotL64(aOrbiterG, 13U)) + RotL64(aCarry, 19U)) + aNonceWordM) + aPhaseEWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 27U) + aOrbiterE) + RotL64(aOrbiterA, 19U));
            aWandererK = aWandererK + ((RotL64(aIngress, 11U) + RotL64(aOrbiterG, 11U)) + aOrbiterF);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 41U) + aOrbiterI) + RotL64(aOrbiterB, 54U)) + aNonceWordC);
            aWandererD = aWandererD + (((RotL64(aCross, 35U) + aOrbiterC) + RotL64(aOrbiterG, 3U)) + RotL64(aCarry, 27U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterA, 41U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 26U));
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererF);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 53U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 60U));
            aCarry = aCarry + RotL64(aWandererC, 51U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordH);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 11671U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 13181U)) & S_BLOCK1], 42U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 15294U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 12168U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aIngress, 42U)) ^ (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 57U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterD = (aWandererD + RotL64(aCross, 57U)) + 252059974543142812U;
            aOrbiterI = (aWandererK + RotL64(aIngress, 22U)) + 11690823093681457368U;
            aOrbiterK = (aWandererA + RotL64(aPrevious, 5U)) + 13282189752890971123U;
            aOrbiterE = (aWandererJ + RotL64(aScatter, 3U)) + 9507416294305708435U;
            aOrbiterA = (((aWandererB + RotL64(aIngress, 13U)) + RotL64(aCarry, 3U)) + 14053038174390776539U) + aNonceWordB;
            aOrbiterG = ((aWandererF + RotL64(aScatter, 39U)) + RotL64(aCarry, 43U)) + 14605253312318725009U;
            aOrbiterB = (((aWandererI + RotL64(aCross, 24U)) + 18138286582677863671U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordF;
            aOrbiterH = ((aWandererH + RotL64(aPrevious, 27U)) + 8530091235978489988U) + aPhaseEOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = ((aWandererC + RotL64(aCross, 43U)) + RotL64(aCarry, 37U)) + 14381731677571170073U;
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 47U)) + 13316413456378978456U) + aNonceWordC;
            aOrbiterF = (aWandererG + RotL64(aIngress, 29U)) + 3910529530149320706U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 6302070286831566901U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 12324134652758551396U;
            aOrbiterK = RotL64((aOrbiterK * 17136438281540250165U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 4773478557638475048U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 4031153435446078944U;
            aOrbiterG = RotL64((aOrbiterG * 3876928995240982769U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 3114794895962903899U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 3552936509969106796U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16823186892738820299U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 5828754613946145627U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 17985241114076114558U;
            aOrbiterA = RotL64((aOrbiterA * 1986669631395606833U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 11319331046368072261U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 6104267020171882160U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12525117969211576177U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 7662668379725735125U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 6583034411403600735U;
            aOrbiterJ = RotL64((aOrbiterJ * 262095656452193889U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 5569865728026310280U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 4176065898330374039U;
            aOrbiterD = RotL64((aOrbiterD * 11305749530796963967U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 13677146592276526676U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 2734371113158117596U;
            aOrbiterE = RotL64((aOrbiterE * 13146444882662731975U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 14890607377967461739U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 3110674898918355049U;
            aOrbiterB = RotL64((aOrbiterB * 9637837600671200315U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 15329760212453783067U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 18214263442264013242U) ^ aNonceWordG;
            aOrbiterC = RotL64((aOrbiterC * 9139354822936682953U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 6727267537859989206U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 252059974543142812U;
            aOrbiterF = RotL64((aOrbiterF * 9559128226993261041U), 23U);
            //
            aIngress = RotL64(aOrbiterB, 13U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 51U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 41U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 23U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 4U));
            aIngress = aIngress + RotL64(aOrbiterK, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aIngress, 43U) + aOrbiterJ) + RotL64(aOrbiterB, 29U)) + aNonceWordD);
            aWandererE = aWandererE + (((RotL64(aPrevious, 13U) + aOrbiterI) + RotL64(aOrbiterG, 4U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 47U) + aOrbiterC) + RotL64(aOrbiterD, 47U));
            aWandererD = aWandererD + ((RotL64(aScatter, 35U) + aOrbiterK) + RotL64(aOrbiterE, 11U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterI, 53U)) + aOrbiterA);
            aWandererB = aWandererB + ((((RotL64(aCross, 58U) + RotL64(aOrbiterA, 56U)) + aOrbiterK) + RotL64(aCarry, 43U)) + aNonceWordA);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 11U) + aOrbiterF) + RotL64(aOrbiterK, 27U)) + aPhaseEWandererUpdateSaltB[((aIndex + 4U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 3U) + aOrbiterH) + RotL64(aOrbiterK, 39U)) + RotL64(aCarry, 37U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterJ, 21U)) + aOrbiterC);
            aWandererA = aWandererA + ((RotL64(aScatter, 40U) + aOrbiterI) + RotL64(aOrbiterC, 37U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 37U) + aOrbiterC) + RotL64(aOrbiterH, 51U)) + aNonceWordM);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 30U));
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererI, 21U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 37U));
            aCarry = aCarry + RotL64(aWandererF, 23U);
            aCarry = aCarry + RotL64(aIngress, 58U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordI);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 18740U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 20527U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 18160U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 19445U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aPrevious, 5U)) + (RotL64(aIngress, 19U) ^ RotL64(aCarry, 56U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 41U)) + RotL64(aCarry, 11U)) + 10726035965553989335U;
            aOrbiterE = (aWandererH + RotL64(aScatter, 6U)) + 967354339530195662U;
            aOrbiterH = (aWandererI + RotL64(aIngress, 43U)) + 10834593005478605624U;
            aOrbiterA = ((aWandererG + RotL64(aCross, 13U)) + 1012888282838656933U) + aNonceWordC;
            aOrbiterJ = (((aWandererA + RotL64(aIngress, 51U)) + RotL64(aCarry, 57U)) + 15283530351725183253U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = (aWandererD + RotL64(aPrevious, 21U)) + 11724495956731703750U;
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 53U)) + 4288330117317505776U) + aNonceWordP;
            aOrbiterG = (((aWandererC + RotL64(aCross, 60U)) + RotL64(aCarry, 37U)) + 10894778070022873473U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterK = (aWandererB + RotL64(aPrevious, 11U)) + 15563886747621617467U;
            aOrbiterF = ((aWandererE + RotL64(aIngress, 39U)) + 11182488628562891937U) + aNonceWordJ;
            aOrbiterB = (aWandererF + RotL64(aCross, 23U)) + 10420140066310588580U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 11775138062167543111U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 16545391898578161683U;
            aOrbiterH = RotL64((aOrbiterH * 14588306527161321535U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 1550144656312299266U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 14903504853138279883U;
            aOrbiterJ = RotL64((aOrbiterJ * 8003033561266164387U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 309935535526750396U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 13991265868040011411U;
            aOrbiterI = RotL64((aOrbiterI * 2887531132228588441U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 1755976294857114222U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 2259275858478396846U;
            aOrbiterC = RotL64((aOrbiterC * 7416165760067878161U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 4838175912944552936U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 12307900457200936013U;
            aOrbiterG = RotL64((aOrbiterG * 14719363144850838805U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 18025411832912225805U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 981375022769564523U;
            aOrbiterK = RotL64((aOrbiterK * 15869361544011831483U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 3174014054982742562U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 8119692378748963609U) ^ aNonceWordB;
            aOrbiterF = RotL64((aOrbiterF * 3072354179707448489U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 14502863160788675807U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 1207582534593709516U;
            aOrbiterB = RotL64((aOrbiterB * 3045412087535529357U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 5838011917777875072U) + aNonceWordO;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 434594114594643600U;
            aOrbiterD = RotL64((aOrbiterD * 1591023655239709931U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 15711060039063734443U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 8307150522686198490U;
            aOrbiterE = RotL64((aOrbiterE * 2082452039297764679U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 5805686529930815226U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 10726035965553989335U;
            aOrbiterA = RotL64((aOrbiterA * 5563221485243331689U), 19U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterJ, 13U);
            aIngress = aIngress + (RotL64(aOrbiterC, 43U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 21U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 60U));
            aIngress = aIngress + RotL64(aOrbiterD, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 37U) + aOrbiterF) + RotL64(aOrbiterA, 39U));
            aWandererG = aWandererG + ((RotL64(aIngress, 21U) + RotL64(aOrbiterD, 53U)) + aOrbiterJ);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterG, 23U)) + aOrbiterE);
            aWandererB = aWandererB + ((((RotL64(aCross, 54U) + aOrbiterI) + RotL64(aOrbiterB, 10U)) + RotL64(aCarry, 11U)) + aPhaseEWandererUpdateSaltD[((aIndex + 22U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterI, 37U)) + aOrbiterC);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterK, 27U)) + aOrbiterE) + RotL64(aCarry, 47U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 11U) + aOrbiterA) + RotL64(aOrbiterC, 57U));
            aWandererI = aWandererI + ((RotL64(aScatter, 39U) + RotL64(aOrbiterH, 13U)) + aOrbiterD);
            aWandererH = aWandererH ^ ((((RotL64(aPrevious, 50U) + RotL64(aOrbiterC, 3U)) + aOrbiterH) + aNonceWordM) + aPhaseEWandererUpdateSaltA[((aIndex + 11U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 3U) + aOrbiterA) + RotL64(aOrbiterE, 41U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 29U) + aOrbiterD) + RotL64(aOrbiterI, 44U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 51U));
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 46U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + RotL64(aWandererJ, 27U);
            aCarry = aCarry + RotL64(aIngress, 44U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordL);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 26797U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneA[((aIndex + 23458U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 23535U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24920U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 40U) + RotL64(aCarry, 53U)) + (RotL64(aPrevious, 21U) ^ RotL64(aCross, 3U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterA = (aWandererI + RotL64(aPrevious, 56U)) + 17225673071833726819U;
            aOrbiterD = ((aWandererC + RotL64(aScatter, 29U)) + RotL64(aCarry, 23U)) + 10301458382103627331U;
            aOrbiterF = (aWandererB + RotL64(aCross, 13U)) + 3960233050857362414U;
            aOrbiterH = (aWandererH + RotL64(aIngress, 27U)) + 17768665685046605837U;
            aOrbiterJ = (aWandererK + RotL64(aScatter, 10U)) + 14471018461213959767U;
            aOrbiterG = ((aWandererG + RotL64(aPrevious, 47U)) + RotL64(aCarry, 39U)) + 10730597892721340453U;
            aOrbiterI = ((aWandererD + RotL64(aCross, 53U)) + 14863394003122760542U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 37U)) + RotL64(aCarry, 43U)) + 9948587274816688296U;
            aOrbiterB = ((aWandererF + RotL64(aCross, 35U)) + 3573569431435100993U) + aNonceWordC;
            aOrbiterK = (aWandererA + RotL64(aIngress, 41U)) + 8153670675740450590U;
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 23U)) + 16438856577722561424U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 15765587867581925041U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 1082039522061775213U;
            aOrbiterF = RotL64((aOrbiterF * 17023740047246402641U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 4202521649260798876U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 15877659681260461141U;
            aOrbiterG = RotL64((aOrbiterG * 11369910758551088173U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 2551560426129646123U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 3005102326163906320U;
            aOrbiterC = RotL64((aOrbiterC * 4241583192662435107U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 1675501058857208089U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 12774812270956702043U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5488437008504905105U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 1044886020922563597U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 4857445127457225171U;
            aOrbiterA = RotL64((aOrbiterA * 13223560654459705259U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 11548725551787560962U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 2434677823189765161U;
            aOrbiterH = RotL64((aOrbiterH * 4283026044563670969U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 9606875320524736294U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = (((aOrbiterI ^ aOrbiterJ) ^ 13732615866277657704U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterI = RotL64((aOrbiterI * 3905528919281629775U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 13921743663803299567U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 13350829301153929899U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11858642286713079795U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 9473349030551400156U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 7446792050826434742U;
            aOrbiterE = RotL64((aOrbiterE * 6619682184124713031U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 17970527747978977453U) + aNonceWordJ;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 2326714817603921480U;
            aOrbiterD = RotL64((aOrbiterD * 14581676978186226887U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 7875511075130474136U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 17225673071833726819U;
            aOrbiterJ = RotL64((aOrbiterJ * 1196024136909896027U), 53U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterI, 51U);
            aIngress = aIngress + (RotL64(aOrbiterB, 14U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterG, 5U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 41U));
            aIngress = aIngress + RotL64(aOrbiterE, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aCross, 53U) + RotL64(aOrbiterB, 41U)) + aOrbiterF) + RotL64(aCarry, 51U));
            aWandererJ = aWandererJ ^ ((((RotL64(aScatter, 30U) + RotL64(aOrbiterG, 13U)) + aOrbiterH) + aNonceWordE) + aPhaseEWandererUpdateSaltC[((aIndex + 28U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterD, 3U)) + aOrbiterB) + aNonceWordO);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 23U) + aOrbiterJ) + RotL64(aOrbiterB, 53U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterJ, 51U)) + aOrbiterK);
            aWandererI = aWandererI ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterD, 22U)) + aOrbiterJ);
            aWandererE = aWandererE + (((RotL64(aScatter, 47U) + RotL64(aOrbiterJ, 27U)) + aOrbiterI) + aPhaseEWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 50U) + aOrbiterF) + RotL64(aOrbiterG, 29U));
            aWandererK = aWandererK + ((RotL64(aCross, 39U) + RotL64(aOrbiterG, 5U)) + aOrbiterC);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterE, 20U)) + aOrbiterG) + aNonceWordH);
            aWandererD = aWandererD + (((RotL64(aScatter, 11U) + RotL64(aOrbiterA, 37U)) + aOrbiterG) + RotL64(aCarry, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererJ, 44U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererI, 37U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererE);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + RotL64(aWandererK, 21U);
            aCarry = aCarry + RotL64(aIngress, 6U);
            aCarry = aCarry ^ aNonceWordH;
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 29394U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((aIndex + 29916U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 29621U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((aIndex + 29946U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 43U) ^ RotL64(aCarry, 11U)) + (RotL64(aIngress, 24U) ^ RotL64(aCross, 57U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterD = (aWandererD + RotL64(aPrevious, 23U)) + 12583180859826261500U;
            aOrbiterG = ((aWandererH + RotL64(aCross, 29U)) + RotL64(aCarry, 39U)) + 9067093488553721468U;
            aOrbiterE = ((aWandererG + RotL64(aScatter, 5U)) + RotL64(aCarry, 29U)) + 12173106198862881754U;
            aOrbiterB = (((aWandererE + RotL64(aIngress, 43U)) + RotL64(aCarry, 13U)) + 11333491014394592654U) + aNonceWordL;
            aOrbiterA = ((aWandererA + RotL64(aScatter, 54U)) + 3511883526940919554U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = ((aWandererK + RotL64(aCross, 39U)) + 7416810692106273044U) + aNonceWordI;
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 47U)) + 8341174972619784110U) + aNonceWordO;
            aOrbiterK = (aWandererJ + RotL64(aIngress, 51U)) + 2220852854836962979U;
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 37U)) + 8090781422229383825U;
            aOrbiterH = ((aWandererI + RotL64(aScatter, 18U)) + 2338801236599102223U) + aPhaseEOrbiterAssignSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = (aWandererC + RotL64(aIngress, 13U)) + 12484514711848308104U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 13684861340589131816U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 12796636819991873058U;
            aOrbiterE = RotL64((aOrbiterE * 5533508014234835669U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 7634198650894837690U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 10240326122201201762U;
            aOrbiterA = RotL64((aOrbiterA * 8758703497719125901U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 4162814763739453934U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 2766504649149048469U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16731843453895178671U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 11051393030148769655U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 17687055068651386665U) ^ aNonceWordA;
            aOrbiterF = RotL64((aOrbiterF * 1042927176246229537U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 3353615315436983420U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 5971640796220306310U;
            aOrbiterK = RotL64((aOrbiterK * 15804313508835034807U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 12299773092762384765U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 7435804907797063411U;
            aOrbiterJ = RotL64((aOrbiterJ * 9848139805288165965U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 8735783937125735699U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 11903126115475835615U;
            aOrbiterH = RotL64((aOrbiterH * 16942088822124940265U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 4427166023462475475U) + aNonceWordJ;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 6011733469446008137U;
            aOrbiterI = RotL64((aOrbiterI * 17298067225913923517U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 18341473946127677319U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 5423774915753911947U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14985099502923458523U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 2384393657884193014U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 2650593524388493958U;
            aOrbiterG = RotL64((aOrbiterG * 892985816665547945U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 15991261431384033176U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 12583180859826261500U;
            aOrbiterB = RotL64((aOrbiterB * 14394838775646875599U), 5U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterC, 57U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 34U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 51U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 53U));
            aIngress = aIngress + RotL64(aOrbiterJ, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aCross, 56U) + aOrbiterE) + RotL64(aOrbiterJ, 39U)) + aPhaseEWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterA, 3U)) + aOrbiterH) + aNonceWordE);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 19U) + aOrbiterG) + RotL64(aOrbiterC, 21U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 27U) + RotL64(aOrbiterF, 10U)) + aOrbiterD) + RotL64(aCarry, 35U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterE, 13U)) + aOrbiterB);
            aWandererD = aWandererD + ((RotL64(aCross, 13U) + RotL64(aOrbiterB, 41U)) + aOrbiterI);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 35U) + aOrbiterK) + RotL64(aOrbiterA, 57U)) + aNonceWordP);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 39U) + RotL64(aOrbiterF, 35U)) + aOrbiterJ) + RotL64(aCarry, 53U)) + aNonceWordM);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterA, 43U)) + aOrbiterI);
            aWandererC = aWandererC + ((RotL64(aIngress, 23U) + aOrbiterJ) + RotL64(aOrbiterK, 37U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 60U) + aOrbiterG) + RotL64(aOrbiterA, 28U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 48U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererI);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + RotL64(aWandererF, 30U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordD);
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

void TwistExpander_Tennis_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xBC3BF4DC996901E7ULL + 0xC0A0044548836217ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x947D50A49B91E20DULL + 0xBAF1A98399CEBC5DULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xF9CD4B7293D344F5ULL + 0xEC3BF8E9F0A96479ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x8F5CBB968BACDA87ULL + 0xD8CF5210247E878DULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xD4556CCDF681CF21ULL + 0x8AAC6257045CE505ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xDAC2EE7315430E95ULL + 0x94CBD5E69FB00AA4ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xF58B1DA16B456AD1ULL + 0xB8EBDE4D639E22FFULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xA1836B5E60B63CEFULL + 0xB795FCEEA326AA6AULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xF5E85BBE412417C3ULL + 0xECAEBC87DEFEA0DFULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xB52BEB6751C537E5ULL + 0xA8B8DB09CF934F9CULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xF214AF5C7F6DCF8BULL + 0xD38B367F673C7774ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x81BD3D56F0067ADDULL + 0x81519D3145BD6B32ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x8B1AE7C5073DAAEFULL + 0xD88A1FF1D942F50FULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xA8B133BC7351C56BULL + 0xEB10BDE0F9DAEE0CULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xD8FACC7259D770C9ULL + 0x8E9F75BD43FDEE4FULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x96255A1B34D36123ULL + 0xAC767530FB6DC772ULL);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 1898U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneC[((aIndex + 1469U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 4181U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneA[((aIndex + 2380U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCarry, 53U)) + (RotL64(aIngress, 11U) ^ RotL64(aCross, 38U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterB = ((((aWandererH + RotL64(aCross, 51U)) + RotL64(aCarry, 53U)) + 10038936806177516123U) + aPhaseFOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1]) + aNonceWordB;
            aOrbiterG = (aWandererC + RotL64(aPrevious, 18U)) + 1773168435195292638U;
            aOrbiterK = ((aWandererG + RotL64(aScatter, 23U)) + RotL64(aCarry, 47U)) + 10655711161526628072U;
            aOrbiterE = ((((aWandererB + RotL64(aIngress, 41U)) + RotL64(aCarry, 27U)) + 14422295664639740437U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordA;
            aOrbiterJ = (aWandererE + RotL64(aScatter, 13U)) + 4125228715513159576U;
            aOrbiterH = (aWandererI + RotL64(aCross, 11U)) + 3670449653158650845U;
            aOrbiterD = (aWandererA + RotL64(aPrevious, 57U)) + 17553727567180813057U;
            aOrbiterF = (aWandererF + RotL64(aIngress, 47U)) + 5111401772713882743U;
            aOrbiterA = ((aWandererD + RotL64(aScatter, 21U)) + 7688573124662314413U) + aNonceWordJ;
            aOrbiterC = (aWandererK + RotL64(aCross, 44U)) + 9438375825507814395U;
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 3U)) + 14177477039902118886U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 16329942595859623928U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 3990536794006836672U;
            aOrbiterK = RotL64((aOrbiterK * 579024714339065373U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 5072881436583180756U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 16789727877867289997U;
            aOrbiterH = RotL64((aOrbiterH * 8766246302636197905U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 17313956922306689438U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 11530878396329822041U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11356860047841383129U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 3612616532321160196U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 4172189825359187763U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12938945495299393177U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 8677279703778052804U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 1912172980909479362U;
            aOrbiterD = RotL64((aOrbiterD * 10053289257955474143U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 1460085850227494500U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 12116763868122868147U;
            aOrbiterA = RotL64((aOrbiterA * 6076945628020280957U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 17571840610366424432U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 15581362592611080868U;
            aOrbiterI = RotL64((aOrbiterI * 1129054058044872003U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 14434700039977611666U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 4534294602623329152U;
            aOrbiterG = RotL64((aOrbiterG * 5860911553425182045U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 865998255725903702U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 16407778704555344108U;
            aOrbiterJ = RotL64((aOrbiterJ * 15571344643129797977U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 1948990288894429805U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 18218556219056835250U;
            aOrbiterF = RotL64((aOrbiterF * 16574160087642377293U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 1309229265173143398U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 10038936806177516123U) ^ aNonceWordE;
            aOrbiterC = RotL64((aOrbiterC * 12954594462760207923U), 3U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterE, 29U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 39U));
            aIngress = aIngress + (RotL64(aOrbiterB, 13U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterG, 41U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterD, 53U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterK, 6U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 29U) + RotL64(aOrbiterD, 51U)) + aOrbiterA) + aPhaseFWandererUpdateSaltA[((aIndex + 22U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 5U) + aOrbiterF) + RotL64(aOrbiterK, 41U)) + aNonceWordP);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 22U) + aOrbiterH) + RotL64(aOrbiterB, 57U)) + RotL64(aCarry, 43U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 35U) + aOrbiterH) + RotL64(aOrbiterE, 37U));
            aWandererA = aWandererA + ((RotL64(aScatter, 19U) + aOrbiterA) + RotL64(aOrbiterJ, 43U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 46U)) + aOrbiterB);
            aWandererE = aWandererE + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterI, 39U)) + aOrbiterJ);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 24U) + RotL64(aOrbiterF, 27U)) + aOrbiterI);
            aWandererH = aWandererH + ((RotL64(aPrevious, 51U) + aOrbiterF) + RotL64(aOrbiterG, 35U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterC, 14U)) + aOrbiterA);
            aWandererC = aWandererC + (((RotL64(aIngress, 39U) + RotL64(aOrbiterF, 3U)) + aOrbiterD) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 37U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 26U));
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererK);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererI, 44U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordF);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8765U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 8302U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 7427U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((aIndex + 8354U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aPrevious, 11U)) + (RotL64(aCarry, 56U) ^ RotL64(aIngress, 37U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterB = (aWandererH + RotL64(aIngress, 37U)) + 18180797995100240808U;
            aOrbiterF = ((aWandererG + RotL64(aScatter, 18U)) + RotL64(aCarry, 35U)) + 6585906608223552885U;
            aOrbiterI = ((aWandererK + RotL64(aCross, 27U)) + 14088708930575939855U) + aPhaseFOrbiterAssignSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterG = (aWandererB + RotL64(aPrevious, 51U)) + 468974153311516044U;
            aOrbiterH = (((aWandererI + RotL64(aIngress, 11U)) + RotL64(aCarry, 23U)) + 12481951025619894110U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 57U)) + RotL64(aCarry, 51U)) + 17227987923860711763U;
            aOrbiterA = (aWandererE + RotL64(aScatter, 23U)) + 4373962756657477139U;
            aOrbiterC = ((aWandererD + RotL64(aCross, 5U)) + 2077576476565420951U) + aNonceWordK;
            aOrbiterE = (aWandererA + RotL64(aIngress, 60U)) + 17435011300234663764U;
            aOrbiterD = (aWandererJ + RotL64(aPrevious, 29U)) + 4118039398293246896U;
            aOrbiterK = (aWandererC + RotL64(aScatter, 53U)) + 13724716599855216683U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 12391461204689596339U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 9900605191533799627U) ^ aNonceWordM;
            aOrbiterI = RotL64((aOrbiterI * 13553565332531046301U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 972946858824366125U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 17247681919694541215U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2974639094630445643U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 15442851427306771601U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 7303586227288294037U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15406402525021428799U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 12650358753454105119U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 1483710933373510492U;
            aOrbiterA = RotL64((aOrbiterA * 6531763256577221891U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 18065810162229740788U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 11311677121338794007U;
            aOrbiterE = RotL64((aOrbiterE * 15116367961682119467U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 2355285311890287611U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 1287783821903407734U;
            aOrbiterB = RotL64((aOrbiterB * 8054011680932255985U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 9282654686791135654U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 15488608017745542551U;
            aOrbiterG = RotL64((aOrbiterG * 7858866274035085123U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 13296835576073421802U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 7127700236018338741U;
            aOrbiterJ = RotL64((aOrbiterJ * 11246173563106014149U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 1365928843264598789U) + aNonceWordL;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 7777790578813003657U;
            aOrbiterC = RotL64((aOrbiterC * 10121688100505628161U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 2104270617375082523U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 13363764449819651164U;
            aOrbiterD = RotL64((aOrbiterD * 2685452132715528975U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 2008038686059197988U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 18180797995100240808U) ^ aNonceWordB;
            aOrbiterK = RotL64((aOrbiterK * 8978998151475372047U), 13U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterC, 3U);
            aIngress = aIngress + (RotL64(aOrbiterH, 47U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 43U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterG, 10U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterA, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterJ, 53U)) + aOrbiterK) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 28U) + RotL64(aOrbiterI, 19U)) + aOrbiterH) + RotL64(aCarry, 11U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 11U) + aOrbiterI) + RotL64(aOrbiterK, 10U));
            aWandererB = aWandererB + (((RotL64(aCross, 51U) + aOrbiterE) + RotL64(aOrbiterF, 29U)) + RotL64(aCarry, 39U));
            aWandererA = aWandererA ^ ((((RotL64(aPrevious, 21U) + aOrbiterD) + RotL64(aOrbiterJ, 57U)) + aNonceWordC) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aIngress, 37U) + RotL64(aOrbiterA, 41U)) + aOrbiterE);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterB, 47U)) + aOrbiterF);
            aWandererF = aWandererF + (((RotL64(aCross, 43U) + RotL64(aOrbiterH, 34U)) + aOrbiterC) + aNonceWordE);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterK, 51U)) + aOrbiterG);
            aWandererC = aWandererC + ((RotL64(aCross, 40U) + RotL64(aOrbiterG, 23U)) + aOrbiterF);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterE, 21U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 26U));
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererC, 41U) ^ aWandererF);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 53U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 22U));
            aCarry = aCarry + RotL64(aWandererJ, 29U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordI);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 15109U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneA[((aIndex + 14691U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 15288U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneC[((aIndex + 12243U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 54U) + RotL64(aCarry, 21U)) + (RotL64(aCross, 3U) ^ RotL64(aIngress, 35U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 41U)) + 5721224134332887360U) + aNonceWordN;
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 60U)) + RotL64(aCarry, 37U)) + 6892749729775049095U;
            aOrbiterJ = ((aWandererI + RotL64(aCross, 3U)) + 3884839462099556836U) + aPhaseFOrbiterAssignSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterB = ((aWandererG + RotL64(aIngress, 21U)) + RotL64(aCarry, 23U)) + 4365431706830216193U;
            aOrbiterF = (aWandererC + RotL64(aPrevious, 35U)) + 15501528746571578773U;
            aOrbiterI = ((aWandererH + RotL64(aScatter, 29U)) + 4505911326320650606U) + aNonceWordG;
            aOrbiterC = ((aWandererD + RotL64(aCross, 19U)) + RotL64(aCarry, 43U)) + 1865129050927879580U;
            aOrbiterD = (aWandererB + RotL64(aIngress, 47U)) + 2011737665969640369U;
            aOrbiterG = (((aWandererK + RotL64(aPrevious, 37U)) + 611672935827062688U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordP;
            aOrbiterH = (aWandererA + RotL64(aIngress, 51U)) + 663547038310431047U;
            aOrbiterE = (aWandererE + RotL64(aScatter, 6U)) + 5468932264754299556U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 17920294117231191705U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 486058453837528110U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8851102552244026737U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 2789178451938129313U) + aNonceWordA;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 420772587981211184U;
            aOrbiterI = RotL64((aOrbiterI * 17402987842294006667U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 16196774774442181825U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 16264169656793713547U;
            aOrbiterA = RotL64((aOrbiterA * 6900221986041638783U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 10207659833859860796U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 8593749091183323678U;
            aOrbiterF = RotL64((aOrbiterF * 10696776033512404927U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 7224922076047787384U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 15366267474865172373U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10134187073321814217U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 4235342515820080294U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 5239480080426950612U;
            aOrbiterH = RotL64((aOrbiterH * 12077621553561927079U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 10891752830598395582U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 7797358829694471108U;
            aOrbiterK = RotL64((aOrbiterK * 7621206775460997431U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 3755715857903753416U) + aNonceWordO;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 3172069024987421726U;
            aOrbiterB = RotL64((aOrbiterB * 16048490837178650865U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 8623351347363497301U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 5895306804546658158U;
            aOrbiterC = RotL64((aOrbiterC * 1568542219600635919U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 5026075347235960113U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 3706258841140585921U;
            aOrbiterG = RotL64((aOrbiterG * 4911715089264902109U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 6753904207571971217U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 5721224134332887360U;
            aOrbiterE = RotL64((aOrbiterE * 4531182106796534951U), 43U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterG, 21U);
            aIngress = aIngress + (RotL64(aOrbiterA, 39U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 29U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 35U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + RotL64(aOrbiterI, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterH, 19U)) + aOrbiterD) + aNonceWordM);
            aWandererA = aWandererA + ((RotL64(aIngress, 11U) + aOrbiterB) + RotL64(aOrbiterA, 13U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterI, 57U)) + aOrbiterJ);
            aWandererI = aWandererI + (((RotL64(aPrevious, 24U) + RotL64(aOrbiterD, 47U)) + aOrbiterE) + RotL64(aCarry, 47U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 27U) + aOrbiterA) + RotL64(aOrbiterG, 44U)) + aNonceWordB);
            aWandererK = aWandererK + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterE, 41U)) + aOrbiterC) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterJ, 11U)) + aOrbiterE);
            aWandererC = aWandererC + ((RotL64(aIngress, 21U) + RotL64(aOrbiterI, 53U)) + aOrbiterD);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 30U) + RotL64(aOrbiterF, 28U)) + aOrbiterG);
            aWandererD = aWandererD + (((RotL64(aIngress, 51U) + aOrbiterK) + RotL64(aOrbiterF, 3U)) + RotL64(aCarry, 35U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 47U) + aOrbiterK) + RotL64(aOrbiterH, 51U)) + aPhaseFWandererUpdateSaltF[((aIndex + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 46U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 23U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 51U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererJ, 56U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordM);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 20567U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 18154U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21429U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((aIndex + 16607U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 18U) + RotL64(aPrevious, 37U)) ^ (RotL64(aIngress, 3U) + RotL64(aCarry, 51U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterK = ((aWandererI + RotL64(aIngress, 57U)) + RotL64(aCarry, 13U)) + 17912271996338180948U;
            aOrbiterB = ((aWandererA + RotL64(aCross, 12U)) + 13259276608841847058U) + aPhaseFOrbiterAssignSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 41U)) + RotL64(aCarry, 23U)) + 16225936008657276089U;
            aOrbiterE = ((aWandererC + RotL64(aScatter, 39U)) + 2243058962151834071U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 53U)) + 10637439274127347861U) + aNonceWordP;
            aOrbiterH = ((aWandererD + RotL64(aIngress, 27U)) + 15312219216405992627U) + aNonceWordL;
            aOrbiterJ = (aWandererG + RotL64(aScatter, 47U)) + 2393933972129878613U;
            aOrbiterA = (aWandererH + RotL64(aCross, 43U)) + 4327069337247976513U;
            aOrbiterD = (aWandererE + RotL64(aIngress, 21U)) + 8307656353434167837U;
            aOrbiterI = ((aWandererJ + RotL64(aCross, 4U)) + RotL64(aCarry, 51U)) + 17299145556933889336U;
            aOrbiterG = (aWandererK + RotL64(aPrevious, 29U)) + 14458100581172798164U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 6410095654927998067U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 6168964796264687686U) ^ aNonceWordM;
            aOrbiterC = RotL64((aOrbiterC * 16218071040190475953U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 3667999465041020730U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 16021552859323602007U;
            aOrbiterF = RotL64((aOrbiterF * 6427266472526362663U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 12941668202330045095U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 4222032891850449934U;
            aOrbiterH = RotL64((aOrbiterH * 17292856787431308097U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 1346342592002730785U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 16860611785008118820U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 384963420804756607U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 3193572711804730241U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 5866881282680588589U;
            aOrbiterA = RotL64((aOrbiterA * 9226331800853634597U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 17180332731328479126U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 10222097519535882241U;
            aOrbiterD = RotL64((aOrbiterD * 9422887302872778795U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 8863502179821584859U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 14872318155712512999U;
            aOrbiterI = RotL64((aOrbiterI * 11830641277356873233U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 16478790641892781150U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 8414944141232294781U;
            aOrbiterG = RotL64((aOrbiterG * 17443775794621154023U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 13204056527590476037U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 15084952142545813228U;
            aOrbiterK = RotL64((aOrbiterK * 17183888602469193015U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 13051035678904490854U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 17565188004293304987U;
            aOrbiterB = RotL64((aOrbiterB * 12785271107667631897U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 814245676602237400U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 17912271996338180948U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14557769257469623169U), 35U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterB, 5U);
            aIngress = aIngress + (RotL64(aOrbiterA, 53U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 51U));
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterJ, 35U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterD, 40U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aIngress, 3U) + RotL64(aOrbiterD, 57U)) + aOrbiterE) + RotL64(aCarry, 23U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 60U) + aOrbiterG) + RotL64(aOrbiterK, 29U));
            aWandererH = aWandererH + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterA, 4U)) + aOrbiterB) + RotL64(aCarry, 43U)) + aPhaseFWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 39U) + aOrbiterC) + RotL64(aOrbiterK, 23U));
            aWandererF = aWandererF + ((RotL64(aScatter, 37U) + RotL64(aOrbiterB, 51U)) + aOrbiterD);
            aWandererK = aWandererK ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterJ, 53U)) + aOrbiterE);
            aWandererD = aWandererD + ((RotL64(aIngress, 53U) + RotL64(aOrbiterK, 37U)) + aOrbiterF);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterG, 44U)) + aOrbiterJ);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 47U) + aOrbiterI) + RotL64(aOrbiterJ, 11U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 50U) + RotL64(aOrbiterG, 13U)) + aOrbiterI) + aNonceWordF);
            aWandererE = aWandererE + (((RotL64(aIngress, 43U) + aOrbiterG) + RotL64(aOrbiterH, 35U)) + aPhaseFWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 6U) ^ aWandererF);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + (RotL64(aWandererB, 37U) ^ aWandererD);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 21U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + RotL64(aWandererK, 3U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordE);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 24671U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26821U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 23629U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((aIndex + 22938U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 35U) + RotL64(aIngress, 3U)) + (RotL64(aCross, 21U) ^ RotL64(aPrevious, 52U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterC = (aWandererD + RotL64(aCross, 37U)) + 12669015908335980355U;
            aOrbiterH = (((aWandererJ + RotL64(aPrevious, 21U)) + RotL64(aCarry, 35U)) + 5438715179868613192U) + aNonceWordC;
            aOrbiterK = (((aWandererH + RotL64(aIngress, 52U)) + RotL64(aCarry, 5U)) + 13172104448184536460U) + aPhaseFOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = (aWandererA + RotL64(aScatter, 3U)) + 13421421503244744803U;
            aOrbiterE = (aWandererE + RotL64(aCross, 11U)) + 13327113302994856582U;
            aOrbiterD = (aWandererB + RotL64(aIngress, 27U)) + 4671768205922454413U;
            aOrbiterB = (((aWandererI + RotL64(aScatter, 39U)) + RotL64(aCarry, 39U)) + 5355759962838579929U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = (aWandererK + RotL64(aPrevious, 56U)) + 6691720614265406851U;
            aOrbiterI = (aWandererG + RotL64(aScatter, 13U)) + 7063906424700911378U;
            aOrbiterA = (aWandererC + RotL64(aIngress, 23U)) + 17328616394166672263U;
            aOrbiterJ = (aWandererF + RotL64(aCross, 35U)) + 1542940602574207068U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 7203866278803132454U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 993485696233139264U;
            aOrbiterK = RotL64((aOrbiterK * 11609009908810366447U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 15659679028507488331U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 18321361454094675842U;
            aOrbiterD = RotL64((aOrbiterD * 3966860765622641843U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 9633319822696783352U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 3496559332232402963U;
            aOrbiterG = RotL64((aOrbiterG * 7772060229838162977U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 1918349708324205526U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 7701088402761359134U) ^ aNonceWordI;
            aOrbiterA = RotL64((aOrbiterA * 9649485438465644795U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 6006824348814439686U) + aNonceWordE;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 18088375375347012557U;
            aOrbiterC = RotL64((aOrbiterC * 12801082943086128385U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 12816533373478543584U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 17951880253818836433U;
            aOrbiterF = RotL64((aOrbiterF * 8935839101517220201U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 11311632024372748238U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 9891349164779752351U) ^ aNonceWordN;
            aOrbiterB = RotL64((aOrbiterB * 11405973752233193209U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 711130292000437038U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 17818800917771709681U;
            aOrbiterI = RotL64((aOrbiterI * 10567029732245868263U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 10188714200240109442U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 9745615081760948652U;
            aOrbiterJ = RotL64((aOrbiterJ * 9321909462220134035U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 6508703788527163965U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 7536038073603467381U;
            aOrbiterH = RotL64((aOrbiterH * 12015514242701199813U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 2793951597846756844U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 12669015908335980355U;
            aOrbiterE = RotL64((aOrbiterE * 7355285540199760689U), 51U);
            //
            aIngress = RotL64(aOrbiterC, 14U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 23U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + (RotL64(aOrbiterH, 43U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 41U));
            aIngress = aIngress + RotL64(aOrbiterG, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 37U) + aOrbiterE) + RotL64(aOrbiterF, 5U));
            aWandererK = aWandererK + (((RotL64(aScatter, 27U) + RotL64(aOrbiterJ, 47U)) + aOrbiterK) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 42U) + aOrbiterD) + RotL64(aOrbiterK, 60U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 11U) + aOrbiterG) + RotL64(aOrbiterH, 29U)) + aNonceWordF);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 57U) + aOrbiterB) + RotL64(aOrbiterH, 27U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 29U) + aOrbiterE) + RotL64(aOrbiterB, 11U)) + RotL64(aCarry, 29U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 13U) + aOrbiterK) + RotL64(aOrbiterI, 23U));
            aWandererE = aWandererE + ((RotL64(aScatter, 22U) + RotL64(aOrbiterJ, 19U)) + aOrbiterF);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 39U) + aOrbiterC) + RotL64(aOrbiterI, 39U)) + aPhaseFWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aCross, 5U) + RotL64(aOrbiterG, 58U)) + aOrbiterJ) + RotL64(aCarry, 11U)) + aNonceWordL);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterA, 35U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererA, 60U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererI, 41U) ^ aWandererE);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + (RotL64(aWandererG, 21U) ^ aWandererF);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 46U));
            aCarry = aCarry + RotL64(aWandererJ, 23U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ aNonceWordN;
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 32142U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneB[((aIndex + 28918U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30704U)) & S_BLOCK1], 50U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30522U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCross, 35U)) + (RotL64(aCarry, 54U) ^ RotL64(aIngress, 19U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterH = (aWandererA + RotL64(aCross, 27U)) + 1888427424966603593U;
            aOrbiterG = (aWandererB + RotL64(aPrevious, 56U)) + 5436761445660415091U;
            aOrbiterB = ((aWandererD + RotL64(aIngress, 37U)) + 17322876217962143270U) + aPhaseFOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = ((aWandererK + RotL64(aScatter, 11U)) + RotL64(aCarry, 29U)) + 9728299982740564979U;
            aOrbiterD = ((aWandererC + RotL64(aCross, 3U)) + RotL64(aCarry, 53U)) + 301720335271716921U;
            aOrbiterK = ((aWandererF + RotL64(aScatter, 41U)) + 8069685428854814396U) + aNonceWordJ;
            aOrbiterC = (aWandererG + RotL64(aPrevious, 43U)) + 1973715500949100991U;
            aOrbiterE = ((aWandererH + RotL64(aIngress, 21U)) + RotL64(aCarry, 35U)) + 87666408799854155U;
            aOrbiterA = (aWandererJ + RotL64(aCross, 23U)) + 12195436904339035245U;
            aOrbiterF = (((aWandererE + RotL64(aIngress, 48U)) + 4578742069143400295U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordP;
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 35U)) + 7828776048774876484U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 17203146364542781833U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 16913369550858890466U;
            aOrbiterB = RotL64((aOrbiterB * 13534417587921978507U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 9632761514552265402U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 9106637671877341286U;
            aOrbiterD = RotL64((aOrbiterD * 9073709119482640391U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 15423680889126750876U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 6087310684583331882U;
            aOrbiterK = RotL64((aOrbiterK * 8964465129744898619U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 5420955876411796789U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 14166807419730848032U;
            aOrbiterC = RotL64((aOrbiterC * 442659738632823751U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 8118312450347026824U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 4253043584558403086U;
            aOrbiterE = RotL64((aOrbiterE * 5651748455190536467U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 8810774678371762700U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 12218479555589447835U;
            aOrbiterA = RotL64((aOrbiterA * 11026364205248516355U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 11389930523582876358U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 16334420553471379915U;
            aOrbiterF = RotL64((aOrbiterF * 13830132212033904777U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 18201289372553710279U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 7196540389657785361U;
            aOrbiterJ = RotL64((aOrbiterJ * 13058135202554889791U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 2601046573550065116U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 2243003381737071984U;
            aOrbiterH = RotL64((aOrbiterH * 10518763530499878945U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 6058992247656841580U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 10083863011670540073U;
            aOrbiterG = RotL64((aOrbiterG * 17908394295613117155U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 8505005026063156940U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = (((aOrbiterI ^ aOrbiterJ) ^ 1888427424966603593U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterI = RotL64((aOrbiterI * 18298382581929885653U), 43U);
            //
            aIngress = RotL64(aOrbiterF, 11U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 6U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 39U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 35U));
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterE, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aIngress, 5U) + aOrbiterG) + RotL64(aOrbiterA, 43U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterG, 19U)) + aOrbiterH) + aPhaseFWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aScatter, 13U) + RotL64(aOrbiterI, 35U)) + aOrbiterK) + RotL64(aCarry, 23U)) + aNonceWordE);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 35U) + aOrbiterD) + RotL64(aOrbiterH, 21U));
            aWandererC = aWandererC + ((RotL64(aScatter, 51U) + RotL64(aOrbiterB, 27U)) + aOrbiterJ);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterC, 50U)) + aOrbiterB) + aNonceWordL);
            aWandererF = aWandererF + ((((RotL64(aCross, 56U) + aOrbiterE) + RotL64(aOrbiterJ, 3U)) + RotL64(aCarry, 39U)) + aPhaseFWandererUpdateSaltD[((aIndex + 22U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 3U) + aOrbiterF) + RotL64(aOrbiterJ, 11U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterD, 29U)) + aOrbiterJ);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 41U) + aOrbiterA) + RotL64(aOrbiterB, 58U));
            aWandererG = aWandererG + ((RotL64(aCross, 48U) + RotL64(aOrbiterB, 13U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererA);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 30U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 39U));
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererH, 47U);
            aCarry = aCarry + RotL64(aIngress, 34U);
            aCarry = aCarry ^ aNonceWordA;
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

void TwistExpander_Tennis_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x97D84F0CF15C54C5ULL + 0x99D8BE604812C23BULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xB5294F43919AE745ULL + 0xA8B49E03744EA120ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xD63F8466E15A2D35ULL + 0x85CFAC8B9100C201ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x9B96AE7DC5A593C3ULL + 0xBE2F55FF9C93C8E1ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x8C3852B0E8366DE1ULL + 0xE5B3A4B803DE2BD7ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xA9A9542202D5C705ULL + 0x9DD3A5B7FBD53A10ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xC3ADA15E6357F1A9ULL + 0xDE65E2D53AA05E87ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xDD1718F003F1B041ULL + 0xE95C19B754E2DBECULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xFC0EDE09E874288BULL + 0xEC7015F804919307ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x8ED03D70F4A51F45ULL + 0xFAB966DFC13FF411ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xD0ABC8B81375CD89ULL + 0xBEB31D836A3A27ABULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xD7EA14B6F5E212B7ULL + 0x9F18F060C03A320EULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x9AE6879A464B806FULL + 0xFA3C1C04F3B83C89ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x9AFB3DE676F68B09ULL + 0x8A444D07E1620797ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x8ED03B52A330A763ULL + 0xFEF1CD51A0145724ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xEE4CAF30C2701033ULL + 0xEED0F8EDEEDF1AA4ULL);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 4978U)) & S_BLOCK1], 36U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 3092U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 3608U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((aIndex + 2060U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 35U) ^ RotL64(aPrevious, 13U)) + (RotL64(aCarry, 60U) ^ RotL64(aIngress, 47U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterG = ((aWandererI + RotL64(aIngress, 34U)) + 11521331427196538632U) + aNonceWordM;
            aOrbiterB = (aWandererK + RotL64(aPrevious, 21U)) + 16653824187682957632U;
            aOrbiterF = (aWandererE + RotL64(aCross, 41U)) + 11654676587350088289U;
            aOrbiterD = ((aWandererG + RotL64(aScatter, 53U)) + 8010313317412193584U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = (((aWandererD + RotL64(aPrevious, 23U)) + RotL64(aCarry, 53U)) + 1108775560502907471U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = (aWandererB + RotL64(aIngress, 43U)) + 243952321439823521U;
            aOrbiterH = (aWandererH + RotL64(aScatter, 3U)) + 2324945800401240403U;
            aOrbiterC = ((aWandererC + RotL64(aCross, 51U)) + RotL64(aCarry, 23U)) + 9257554497543369657U;
            aOrbiterK = (aWandererF + RotL64(aPrevious, 36U)) + 16701314607244592540U;
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 29U)) + RotL64(aCarry, 35U)) + 3900445848034341782U;
            aOrbiterA = ((aWandererJ + RotL64(aCross, 39U)) + 7652316487347103658U) + aNonceWordB;
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 14980368605272070578U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 2001165460948764796U;
            aOrbiterF = RotL64((aOrbiterF * 8110980921827107649U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 1911044015666991050U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 11366207111147818339U;
            aOrbiterI = RotL64((aOrbiterI * 17234439040652553865U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 16469329744002456607U) + aNonceWordL;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 8062793687044950815U;
            aOrbiterG = RotL64((aOrbiterG * 5856142259851144369U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 15364721421972807872U) + aNonceWordP;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 8979915611483540231U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10899377466171153383U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 7654234623563110457U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 1526832460342135008U;
            aOrbiterH = RotL64((aOrbiterH * 12766083052650723051U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 1596625448797520938U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 15723912914858523080U;
            aOrbiterK = RotL64((aOrbiterK * 6003857787643420337U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 7664226719746532168U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 13767298788411473401U;
            aOrbiterA = RotL64((aOrbiterA * 15663266144965532019U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 8371251860069346385U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 10143279934304029980U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12764966547132248131U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 10034920090729616747U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 14450253491131954914U;
            aOrbiterE = RotL64((aOrbiterE * 15877567779079226909U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 9450697155749555210U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 14051719612902917300U;
            aOrbiterC = RotL64((aOrbiterC * 7659810299163085295U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 659383614060726993U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 11521331427196538632U;
            aOrbiterJ = RotL64((aOrbiterJ * 1068009283450923005U), 43U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterC, 3U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 19U));
            aIngress = aIngress + (RotL64(aOrbiterA, 5U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterB, 44U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterE, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterB, 18U)) + aOrbiterK);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterC, 13U)) + aOrbiterF);
            aWandererA = aWandererA + ((((RotL64(aCross, 3U) + aOrbiterA) + RotL64(aOrbiterB, 5U)) + RotL64(aCarry, 3U)) + aNonceWordE);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterG, 41U)) + aOrbiterF);
            aWandererD = aWandererD + (((RotL64(aPrevious, 36U) + aOrbiterH) + RotL64(aOrbiterD, 30U)) + RotL64(aCarry, 37U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterA, 51U)) + aOrbiterG) + aPhaseFWandererUpdateSaltE[((aIndex + 18U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aCross, 27U) + RotL64(aOrbiterC, 39U)) + aOrbiterH);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 23U) + aOrbiterI) + RotL64(aOrbiterF, 3U));
            aWandererK = aWandererK + ((((RotL64(aCross, 47U) + aOrbiterJ) + RotL64(aOrbiterB, 57U)) + aNonceWordI) + aPhaseFWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 44U) + RotL64(aOrbiterA, 37U)) + aOrbiterC) + aNonceWordC);
            aWandererH = aWandererH + ((RotL64(aScatter, 53U) + aOrbiterD) + RotL64(aOrbiterE, 47U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 34U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 51U));
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 40U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererK, 11U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordI);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 8529U)) & S_BLOCK1], 22U) ^ RotL64(aWorkLaneD[((aIndex + 9340U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 6775U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 6353U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 54U) ^ RotL64(aIngress, 41U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCarry, 29U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterG = ((aWandererB + RotL64(aIngress, 37U)) + 13960289014350612206U) + aPhaseFOrbiterAssignSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = (aWandererC + RotL64(aPrevious, 19U)) + 3483331015269589730U;
            aOrbiterJ = (aWandererK + RotL64(aScatter, 23U)) + 6873299241002444518U;
            aOrbiterE = ((aWandererF + RotL64(aCross, 53U)) + RotL64(aCarry, 21U)) + 3562094007125534229U;
            aOrbiterA = (aWandererH + RotL64(aScatter, 44U)) + 11422367439932782705U;
            aOrbiterF = (((aWandererI + RotL64(aIngress, 21U)) + RotL64(aCarry, 41U)) + 532453428514259816U) + aNonceWordL;
            aOrbiterH = (aWandererJ + RotL64(aCross, 27U)) + 17810941465810193088U;
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 3U)) + RotL64(aCarry, 3U)) + 11869759058631106331U;
            aOrbiterB = ((aWandererD + RotL64(aCross, 51U)) + 8837581071876177566U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = ((aWandererA + RotL64(aScatter, 11U)) + 17185378327053837778U) + aNonceWordJ;
            aOrbiterI = (aWandererG + RotL64(aIngress, 42U)) + 7578253375676981500U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 17112646434432814442U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 14949096407295697881U;
            aOrbiterJ = RotL64((aOrbiterJ * 14770977858283051753U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 4259590620758467836U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 6534899413644542303U) ^ aNonceWordB;
            aOrbiterK = RotL64((aOrbiterK * 7987609419215568661U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 2637407498893694243U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 15819295597921425711U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5202015597375051399U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 6373559542002699718U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 11694562937392022505U;
            aOrbiterH = RotL64((aOrbiterH * 9311557972331218597U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 3308736483775453062U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 12749929710650475901U;
            aOrbiterB = RotL64((aOrbiterB * 248428400724560945U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 1569528215675579656U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 1044077933631689572U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6443796233912755143U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 8393422728124537471U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 2002732612516530754U;
            aOrbiterE = RotL64((aOrbiterE * 13702146823622364279U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 13469191942843147943U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 7633171368709520560U;
            aOrbiterF = RotL64((aOrbiterF * 9713514012478203047U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 4023206337737491091U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 15990323932023596968U;
            aOrbiterD = RotL64((aOrbiterD * 4816480271959713463U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 837005729394899591U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 9692088757104339973U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17971548293495807419U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 18039464962413134616U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 13960289014350612206U;
            aOrbiterI = RotL64((aOrbiterI * 931609478642506411U), 43U);
            //
            aIngress = RotL64(aOrbiterC, 56U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterD, 41U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterK, 47U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterA, 43U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 21U));
            aIngress = aIngress + RotL64(aOrbiterJ, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 56U) + RotL64(aOrbiterD, 29U)) + aOrbiterB);
            aWandererE = aWandererE + (((RotL64(aCross, 29U) + RotL64(aOrbiterD, 41U)) + aOrbiterK) + aNonceWordC);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 3U) + aOrbiterC) + RotL64(aOrbiterA, 24U));
            aWandererH = aWandererH + ((((RotL64(aScatter, 37U) + RotL64(aOrbiterF, 11U)) + aOrbiterC) + RotL64(aCarry, 13U)) + aNonceWordE);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterA, 3U)) + aOrbiterG) + aPhaseFWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aCross, 51U) + RotL64(aOrbiterG, 43U)) + aOrbiterJ);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 21U) + aOrbiterA) + RotL64(aOrbiterI, 60U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 47U) + aOrbiterC) + RotL64(aOrbiterE, 53U)) + RotL64(aCarry, 35U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 26U) + RotL64(aOrbiterA, 39U)) + aOrbiterD) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aIngress, 11U) + aOrbiterD) + RotL64(aOrbiterH, 5U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 39U) + RotL64(aOrbiterG, 37U)) + aOrbiterC) + aNonceWordD);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 18U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererB);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererA, 41U);
            aCarry = aCarry + RotL64(aIngress, 44U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordC);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 11413U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 15961U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 12224U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 16252U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 12U) ^ RotL64(aPrevious, 53U)) ^ (RotL64(aIngress, 39U) + RotL64(aCarry, 27U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterB = (aWandererK + RotL64(aPrevious, 23U)) + 8767379393098711499U;
            aOrbiterF = ((aWandererH + RotL64(aCross, 60U)) + 7168159491580816433U) + aNonceWordO;
            aOrbiterC = ((aWandererE + RotL64(aIngress, 19U)) + 9879279829061883406U) + aPhaseFOrbiterAssignSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = (aWandererF + RotL64(aScatter, 21U)) + 10537167136053399303U;
            aOrbiterD = (((aWandererG + RotL64(aPrevious, 35U)) + 2839070018069188936U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordH;
            aOrbiterI = (aWandererB + RotL64(aIngress, 43U)) + 13844278063968429732U;
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 11U)) + RotL64(aCarry, 13U)) + 11278946626186474646U;
            aOrbiterA = ((aWandererA + RotL64(aCross, 57U)) + RotL64(aCarry, 41U)) + 11798425216660557799U;
            aOrbiterK = (aWandererI + RotL64(aScatter, 14U)) + 7618446090703335192U;
            aOrbiterH = (aWandererJ + RotL64(aIngress, 39U)) + 695423597006983660U;
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 3U)) + RotL64(aCarry, 35U)) + 14344728202803488813U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 11656100506575697086U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 10384358779985773937U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 247494692039140973U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 17585001605131977341U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 9964478171465522911U;
            aOrbiterI = RotL64((aOrbiterI * 13484044854790175315U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 2710943171829692624U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 17809072853457153057U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16341884203303271365U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 12814092033910687774U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 1743186323268668740U;
            aOrbiterD = RotL64((aOrbiterD * 11150822630624332557U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 10750472346626754704U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 15925901217078035356U;
            aOrbiterA = RotL64((aOrbiterA * 9276504171291801637U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 2569102106359362359U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 8868261301410769739U;
            aOrbiterH = RotL64((aOrbiterH * 3662495603133918101U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 2143691008373582476U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 10606616796243205921U) ^ aNonceWordP;
            aOrbiterB = RotL64((aOrbiterB * 15794414817813485643U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 16258070651850746855U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 11720192793689633315U;
            aOrbiterE = RotL64((aOrbiterE * 14475623219460678021U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 8230871037292355675U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 16898650748046368353U;
            aOrbiterJ = RotL64((aOrbiterJ * 7368697435476300255U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 9071122174426904737U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 4506737259011736474U;
            aOrbiterK = RotL64((aOrbiterK * 11903039808814842447U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 4545409671845718259U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 8767379393098711499U) ^ aNonceWordE;
            aOrbiterG = RotL64((aOrbiterG * 1210632171306946669U), 53U);
            //
            aIngress = RotL64(aOrbiterD, 13U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterB, 41U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 19U));
            aIngress = aIngress + (RotL64(aOrbiterG, 28U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 39U));
            aIngress = aIngress + RotL64(aOrbiterI, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 58U) + RotL64(aOrbiterB, 57U)) + aOrbiterC);
            aWandererD = aWandererD + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterK, 28U)) + aOrbiterB) + RotL64(aCarry, 41U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 35U) + aOrbiterF) + RotL64(aOrbiterJ, 47U)) + aPhaseFWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 27U) + aOrbiterD) + RotL64(aOrbiterB, 21U)) + aNonceWordM);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 41U) + aOrbiterD) + RotL64(aOrbiterJ, 51U)) + aNonceWordB);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterB, 3U)) + aOrbiterH);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 20U) + aOrbiterD) + RotL64(aOrbiterG, 5U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aCross, 13U) + RotL64(aOrbiterG, 41U)) + aOrbiterE);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterA, 37U)) + aOrbiterI);
            aWandererF = aWandererF + (((RotL64(aScatter, 53U) + RotL64(aOrbiterA, 53U)) + aOrbiterH) + RotL64(aCarry, 47U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterF, 14U)) + aOrbiterE) + aNonceWordN);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 10U));
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 37U));
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererI, 5U);
            aCarry = aCarry + RotL64(aIngress, 48U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordH);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 18016U)) & S_BLOCK1], 24U) ^ RotL64(aOperationLaneB[((aIndex + 20188U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 19417U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 18055U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aPrevious, 57U)) + (RotL64(aCarry, 43U) ^ RotL64(aIngress, 6U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterA = (aWandererB + RotL64(aPrevious, 60U)) + 10915618884692072446U;
            aOrbiterE = (aWandererD + RotL64(aScatter, 43U)) + 12634922308499254909U;
            aOrbiterD = (aWandererK + RotL64(aIngress, 11U)) + 6533934734564499389U;
            aOrbiterF = ((aWandererJ + RotL64(aCross, 19U)) + 6744203303756105181U) + aNonceWordK;
            aOrbiterC = ((aWandererF + RotL64(aScatter, 3U)) + RotL64(aCarry, 35U)) + 13086782386652045658U;
            aOrbiterK = (aWandererA + RotL64(aIngress, 40U)) + 5693840533331397822U;
            aOrbiterJ = (aWandererI + RotL64(aCross, 47U)) + 1803663542535024611U;
            aOrbiterI = (((aWandererG + RotL64(aPrevious, 37U)) + RotL64(aCarry, 47U)) + 3597219300593287708U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = ((((aWandererC + RotL64(aIngress, 29U)) + RotL64(aCarry, 13U)) + 1429753448204448904U) + aPhaseFOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1]) + aNonceWordG;
            aOrbiterH = (aWandererE + RotL64(aCross, 21U)) + 17229017825587322715U;
            aOrbiterG = (aWandererH + RotL64(aScatter, 57U)) + 1137574712801062932U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 2401991077004083378U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 1332473247826139292U;
            aOrbiterD = RotL64((aOrbiterD * 15029831858261506447U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 11730946340796899885U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 15319163439700390962U;
            aOrbiterC = RotL64((aOrbiterC * 1349242001887975499U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 4744141870145159917U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 6067132201862688684U;
            aOrbiterK = RotL64((aOrbiterK * 6046100687757836027U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 14991509179286371800U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 4342608825699398682U;
            aOrbiterJ = RotL64((aOrbiterJ * 10240526103933275875U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 3727521409410742075U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 3302027219498304367U) ^ aNonceWordE;
            aOrbiterI = RotL64((aOrbiterI * 12153634588200479559U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 6039539483340398858U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 2902581519976937051U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2057584328877854239U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 12332784713738947242U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 13761272577223712786U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14930145045480030821U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 2947946397617043735U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 11107014023853644521U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15030903626191481831U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 6212403196992771516U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 16107261731677426470U;
            aOrbiterA = RotL64((aOrbiterA * 13764822942405295129U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 8414111492161335472U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 3625937496991123221U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1736741235159600739U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 5466667339391480293U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 10915618884692072446U;
            aOrbiterF = RotL64((aOrbiterF * 14719282928172086707U), 51U);
            //
            aIngress = RotL64(aOrbiterH, 3U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 51U));
            aIngress = aIngress + (RotL64(aOrbiterA, 37U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 11U));
            aIngress = aIngress + (RotL64(aOrbiterK, 21U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterB, 42U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterD, 28U)) + aOrbiterA);
            aWandererF = aWandererF + ((RotL64(aScatter, 51U) + RotL64(aOrbiterE, 51U)) + aOrbiterF);
            aWandererH = aWandererH ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterK, 21U)) + aOrbiterC);
            aWandererE = aWandererE + ((RotL64(aPrevious, 48U) + aOrbiterG) + RotL64(aOrbiterI, 43U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterI, 37U)) + aOrbiterB);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 39U) + RotL64(aOrbiterC, 47U)) + aOrbiterD) + RotL64(aCarry, 19U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 19U) + aOrbiterH) + RotL64(aOrbiterC, 23U));
            aWandererI = aWandererI + (((RotL64(aIngress, 21U) + aOrbiterE) + RotL64(aOrbiterC, 13U)) + RotL64(aCarry, 41U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 26U) + RotL64(aOrbiterE, 39U)) + aOrbiterA) + aNonceWordA);
            aWandererC = aWandererC + (((RotL64(aIngress, 53U) + aOrbiterB) + RotL64(aOrbiterD, 41U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 35U) + aOrbiterH) + RotL64(aOrbiterJ, 10U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererG);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 36U));
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererJ);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 13U));
            aCarry = aCarry + RotL64(aWandererK, 38U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordB);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 26800U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneA[((aIndex + 22751U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 26747U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 26658U)) & S_BLOCK1], 40U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 41U) ^ RotL64(aIngress, 11U)) + (RotL64(aPrevious, 53U) + RotL64(aCross, 26U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterC = (aWandererH + RotL64(aPrevious, 58U)) + 10812151398716051703U;
            aOrbiterB = (aWandererJ + RotL64(aScatter, 43U)) + 18202551453336003710U;
            aOrbiterG = ((aWandererA + RotL64(aCross, 39U)) + 9434410809101973752U) + aPhaseFOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = ((aWandererF + RotL64(aIngress, 29U)) + 12955829998028534045U) + aNonceWordI;
            aOrbiterH = (aWandererG + RotL64(aCross, 35U)) + 12271740641929640181U;
            aOrbiterI = (aWandererK + RotL64(aPrevious, 56U)) + 14009351527014534752U;
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 37U)) + RotL64(aCarry, 23U)) + 4316296955679133450U;
            aOrbiterA = ((aWandererI + RotL64(aIngress, 47U)) + RotL64(aCarry, 35U)) + 16473324966997442872U;
            aOrbiterE = (aWandererE + RotL64(aCross, 23U)) + 15735123324965019802U;
            aOrbiterF = (aWandererD + RotL64(aScatter, 41U)) + 17656375090484080236U;
            aOrbiterK = (((aWandererB + RotL64(aPrevious, 19U)) + RotL64(aCarry, 11U)) + 16066325053456055298U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 12908968778503516903U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 12761433987676836197U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1023329467480907925U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 12737513138040664509U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 14535795767570998392U;
            aOrbiterI = RotL64((aOrbiterI * 15560519667062222269U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 14370908061811284364U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 7001358781208669795U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11641248025734015835U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 7298578161120090849U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 10498302152357484629U;
            aOrbiterF = RotL64((aOrbiterF * 13144110412179037175U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 11447343228638006767U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 18284143620422655675U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 572862190073605651U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 5918253208127360199U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 3910541329178205943U) ^ aNonceWordJ;
            aOrbiterD = RotL64((aOrbiterD * 4550654545328228103U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 10357053096941367910U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 5610891501128498748U;
            aOrbiterJ = RotL64((aOrbiterJ * 8676370811772047449U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 9049881176058575811U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 6307599924966452216U;
            aOrbiterE = RotL64((aOrbiterE * 5551444450572055895U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 17109966783467892046U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 11563095828344462249U;
            aOrbiterK = RotL64((aOrbiterK * 15463753739272001875U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 3739147427725509014U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 5324449517615050698U;
            aOrbiterB = RotL64((aOrbiterB * 5926079615575226853U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 5706251076252597592U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 10812151398716051703U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5666491216813197045U), 41U);
            //
            aIngress = RotL64(aOrbiterK, 26U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 23U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 53U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 13U));
            aIngress = aIngress + (RotL64(aOrbiterA, 10U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterD, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aIngress, 30U) + aOrbiterJ) + RotL64(aOrbiterA, 35U)) + aNonceWordK);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 37U) + aOrbiterB) + RotL64(aOrbiterA, 21U));
            aWandererG = aWandererG + ((((RotL64(aScatter, 11U) + RotL64(aOrbiterE, 19U)) + aOrbiterB) + RotL64(aCarry, 27U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 51U) + aOrbiterH) + RotL64(aOrbiterB, 50U)) + aNonceWordB);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 18U) + aOrbiterI) + RotL64(aOrbiterE, 53U));
            aWandererH = aWandererH ^ ((((RotL64(aIngress, 21U) + RotL64(aOrbiterF, 29U)) + aOrbiterB) + aNonceWordG) + aPhaseFWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 47U) + RotL64(aOrbiterB, 11U)) + aOrbiterK) + RotL64(aCarry, 37U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterH, 48U)) + aOrbiterF);
            aWandererB = aWandererB + ((RotL64(aCross, 27U) + aOrbiterH) + RotL64(aOrbiterD, 13U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterC, 23U)) + aOrbiterH);
            aWandererD = aWandererD + ((RotL64(aIngress, 43U) + RotL64(aOrbiterC, 43U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 30U));
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + (RotL64(aWandererE, 53U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererI, 44U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererF, 21U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 29554U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneB[((aIndex + 32310U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30758U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneB[((aIndex + 31121U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 56U) + RotL64(aPrevious, 39U)) + (RotL64(aCarry, 11U) ^ RotL64(aIngress, 23U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterG = ((aWandererA + RotL64(aScatter, 6U)) + 3236820517816085022U) + aNonceWordH;
            aOrbiterE = ((aWandererE + RotL64(aCross, 43U)) + 741288875914097926U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = (aWandererD + RotL64(aIngress, 19U)) + 8417246926007729580U;
            aOrbiterC = ((aWandererG + RotL64(aPrevious, 21U)) + RotL64(aCarry, 3U)) + 9715717805774537170U;
            aOrbiterD = (aWandererH + RotL64(aIngress, 11U)) + 14360243844821619482U;
            aOrbiterK = ((aWandererJ + RotL64(aCross, 51U)) + RotL64(aCarry, 37U)) + 10760908100206775334U;
            aOrbiterH = (aWandererI + RotL64(aPrevious, 41U)) + 3434641779946167811U;
            aOrbiterF = ((aWandererC + RotL64(aScatter, 57U)) + 7885568822756234567U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = (aWandererK + RotL64(aPrevious, 26U)) + 3041563437672051294U;
            aOrbiterA = (((aWandererB + RotL64(aScatter, 37U)) + RotL64(aCarry, 21U)) + 15761355327564963516U) + aNonceWordD;
            aOrbiterB = (aWandererF + RotL64(aCross, 47U)) + 1158633562785937421U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 9338581575871970653U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 9172038894262857354U;
            aOrbiterJ = RotL64((aOrbiterJ * 3110871165285625807U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 14653924713599790081U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 3854497592598563309U;
            aOrbiterD = RotL64((aOrbiterD * 11737111068815795303U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 16286980180327600557U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 5092583772591249756U;
            aOrbiterK = RotL64((aOrbiterK * 13955105624639442903U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 4288397994175567333U) + aNonceWordA;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 15584236478994873104U;
            aOrbiterH = RotL64((aOrbiterH * 1860480595862755379U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 5557463939827483792U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 2659814275753280856U;
            aOrbiterF = RotL64((aOrbiterF * 17702430405693184643U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 6941807963525063449U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 2040598555191211307U;
            aOrbiterI = RotL64((aOrbiterI * 14750544987531722765U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 347572666231116258U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 779304821185302523U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14180254150318109855U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 10632524582873079742U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 9761308771280517212U;
            aOrbiterB = RotL64((aOrbiterB * 13926235411726048921U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 2097439707055737964U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 2813977930321463948U;
            aOrbiterG = RotL64((aOrbiterG * 14983538728730662603U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 6080592019313796689U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 5396623654821376409U;
            aOrbiterE = RotL64((aOrbiterE * 15478858835919398677U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 8460497459575045342U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 3236820517816085022U;
            aOrbiterC = RotL64((aOrbiterC * 5530411244458067093U), 11U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterC, 35U);
            aIngress = aIngress + (RotL64(aOrbiterK, 44U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterE, 39U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 23U));
            aIngress = aIngress + RotL64(aOrbiterJ, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aPrevious, 51U) + aOrbiterH) + RotL64(aOrbiterK, 30U)) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterF, 37U)) + aOrbiterG);
            aWandererG = aWandererG + ((RotL64(aScatter, 43U) + RotL64(aOrbiterA, 3U)) + aOrbiterD);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 41U) + aOrbiterF) + RotL64(aOrbiterJ, 19U));
            aWandererA = aWandererA + ((((RotL64(aScatter, 48U) + aOrbiterF) + RotL64(aOrbiterE, 51U)) + aNonceWordF) + aPhaseFWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterJ, 5U)) + aOrbiterH) + aNonceWordL);
            aWandererH = aWandererH + ((((RotL64(aCross, 29U) + aOrbiterG) + RotL64(aOrbiterB, 39U)) + RotL64(aCarry, 23U)) + aNonceWordE);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterA, 12U)) + aOrbiterH) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 58U) + aOrbiterE) + RotL64(aOrbiterI, 27U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterK, 23U)) + aOrbiterC);
            aWandererC = aWandererC + ((RotL64(aIngress, 21U) + RotL64(aOrbiterE, 41U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 42U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 51U));
            aCarry = aCarry + (RotL64(aWandererF, 23U) ^ aWandererA);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + RotL64(aWandererJ, 37U);
            aCarry = aCarry + RotL64(aIngress, 44U);
            aCarry = aCarry ^ aNonceWordI;
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

void TwistExpander_Tennis_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 3073U)) & S_BLOCK1], 57U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 7733U)) & W_KEY1], 12U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 6626U)) & W_KEY1], 12U) ^ RotL64(mSource[((aIndex + 7764U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 43U) ^ RotL64(aPrevious, 19U)) ^ (RotL64(aIngress, 56U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = (aWandererD + RotL64(aIngress, 35U)) + 2101601659597850213U;
            aOrbiterA = ((aWandererH + RotL64(aCross, 47U)) + 2759794072560720121U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 10U)) + 9443562552411269339U;
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 27U)) + 10801360546699857975U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = (aWandererA + RotL64(aPrevious, 23U)) + 8020716394829332019U;
            aOrbiterC = (aWandererG + RotL64(aIngress, 5U)) + 1021894212367773801U;
            aOrbiterD = ((aWandererB + RotL64(aScatter, 19U)) + RotL64(aCarry, 5U)) + 13346855534622490176U;
            aOrbiterB = ((aWandererF + RotL64(aCross, 42U)) + RotL64(aCarry, 57U)) + 16359309548462953836U;
            aOrbiterK = ((aWandererE + RotL64(aIngress, 57U)) + RotL64(aCarry, 23U)) + 12642446944680783519U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 8197424982767553380U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 14346334610901859094U;
            aOrbiterI = RotL64((aOrbiterI * 16982899923227935679U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 14171304260534233539U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 334531601308283605U;
            aOrbiterC = RotL64((aOrbiterC * 5012968232749075075U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 10707856298471572695U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 18364775750091914766U;
            aOrbiterB = RotL64((aOrbiterB * 15735143943129143265U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 8531394793118363836U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 15352876929406908882U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 475199047053777179U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 567682016232278157U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 2068146551757663119U;
            aOrbiterG = RotL64((aOrbiterG * 1557877740957797555U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 7776122587613256525U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 16430938890724272256U;
            aOrbiterJ = RotL64((aOrbiterJ * 4540270493783593257U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 11912000645055436094U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 16800749242578741498U;
            aOrbiterD = RotL64((aOrbiterD * 17804584625034241737U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 5909199180260499150U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 5751089915336865588U;
            aOrbiterA = RotL64((aOrbiterA * 15376689503142397927U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 3478216857728853008U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 18007567146937338241U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6620498877303917855U), 23U);
            //
            aIngress = RotL64(aOrbiterJ, 23U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterC, 56U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterK, 43U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterI, 39U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterH, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aScatter, 6U) + aOrbiterG) + RotL64(aOrbiterC, 3U)) + RotL64(aCarry, 39U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 43U) + aOrbiterD) + RotL64(aOrbiterK, 19U)) + aPhaseCWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterA, 43U)) + aOrbiterC);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterI, 11U)) + aOrbiterJ);
            aWandererF = aWandererF + ((RotL64(aScatter, 51U) + RotL64(aOrbiterD, 30U)) + aOrbiterJ);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 28U) + RotL64(aOrbiterD, 39U)) + aOrbiterG);
            aWandererE = aWandererE + (((RotL64(aIngress, 57U) + RotL64(aOrbiterK, 53U)) + aOrbiterI) + RotL64(aCarry, 21U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterA, 47U)) + aOrbiterB);
            aWandererD = aWandererD + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterA, 60U)) + aOrbiterH) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 37U));
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 18U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererB, 51U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 9375U)) & S_BLOCK1], 24U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 15768U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15272U)) & W_KEY1], 47U) ^ RotL64(aKeyRowReadB[((aIndex + 15167U)) & W_KEY1], 30U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 35U) + RotL64(aCarry, 60U)) + (RotL64(aPrevious, 47U) ^ RotL64(aCross, 13U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = ((aWandererE + RotL64(aScatter, 41U)) + 11700815697312060726U) + aPhaseCOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = (aWandererA + RotL64(aPrevious, 5U)) + 11808423452327465441U;
            aOrbiterK = ((aWandererC + RotL64(aIngress, 60U)) + RotL64(aCarry, 47U)) + 8670503858631730886U;
            aOrbiterE = (aWandererB + RotL64(aCross, 29U)) + 2400061067991988544U;
            aOrbiterB = (aWandererI + RotL64(aIngress, 35U)) + 16163118178366229686U;
            aOrbiterF = (aWandererJ + RotL64(aScatter, 51U)) + 3280178595904941068U;
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 13U)) + RotL64(aCarry, 29U)) + 3298683600817047727U;
            aOrbiterD = (((aWandererH + RotL64(aCross, 23U)) + RotL64(aCarry, 13U)) + 16321624053445183574U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = (aWandererF + RotL64(aScatter, 18U)) + 6730229877611375225U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 10162830636713641322U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 15646771327759599256U;
            aOrbiterK = RotL64((aOrbiterK * 15333053762177144775U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 14841751262270544102U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 9545541117228834895U;
            aOrbiterB = RotL64((aOrbiterB * 11529769874752969377U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 14676615635857599982U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 1231768638470558855U;
            aOrbiterC = RotL64((aOrbiterC * 2716808508509014677U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 1945905595345404833U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 1406171421638586846U;
            aOrbiterD = RotL64((aOrbiterD * 4577864352425476233U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 1970292335806697198U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 12309719390375013297U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16540660957923687327U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 5352135521358954576U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 15465675376193501658U;
            aOrbiterG = RotL64((aOrbiterG * 16385761112921041387U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 2842123638916600369U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 3544764287036748668U;
            aOrbiterE = RotL64((aOrbiterE * 3360772950777850115U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 6038297172906492282U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 10249342332287140970U;
            aOrbiterF = RotL64((aOrbiterF * 16701083081566042277U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 1662076777040529446U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 1949705569959740274U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11340691546658994529U), 57U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterE, 47U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 10U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 53U));
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterA, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aCross, 47U) + aOrbiterA) + RotL64(aOrbiterB, 18U)) + aPhaseCWandererUpdateSaltD[((aIndex + 18U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aIngress, 11U) + aOrbiterK) + RotL64(aOrbiterE, 41U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 51U) + aOrbiterF) + RotL64(aOrbiterD, 53U)) + aPhaseCWandererUpdateSaltC[((aIndex + 20U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 58U) + aOrbiterB) + RotL64(aOrbiterF, 29U)) + RotL64(aCarry, 51U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterF, 11U)) + aOrbiterK);
            aWandererF = aWandererF + (((RotL64(aIngress, 43U) + RotL64(aOrbiterF, 47U)) + aOrbiterG) + RotL64(aCarry, 13U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 21U) + aOrbiterC) + RotL64(aOrbiterA, 60U));
            aWandererB = aWandererB + ((RotL64(aCross, 26U) + aOrbiterI) + RotL64(aOrbiterA, 3U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterC, 23U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererF, 38U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + RotL64(aWandererI, 27U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22448U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneA[((aIndex + 17699U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 18246U)) & W_KEY1], 13U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 22156U)) & W_KEY1], 54U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 37U) ^ RotL64(aCarry, 6U)) + (RotL64(aCross, 53U) ^ RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = (aWandererF + RotL64(aScatter, 18U)) + 12849591986267890852U;
            aOrbiterD = (aWandererB + RotL64(aCross, 5U)) + 8232614804696815750U;
            aOrbiterI = (aWandererK + RotL64(aIngress, 29U)) + 12141567259210877281U;
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 39U)) + 2928641981037885644U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 35U)) + RotL64(aCarry, 11U)) + 980733350554783938U;
            aOrbiterE = (((aWandererI + RotL64(aIngress, 12U)) + RotL64(aCarry, 3U)) + 2683985177993350746U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = ((aWandererH + RotL64(aCross, 51U)) + RotL64(aCarry, 23U)) + 14532148403815527355U;
            aOrbiterH = (aWandererA + RotL64(aPrevious, 47U)) + 7736296629433884203U;
            aOrbiterC = (aWandererD + RotL64(aCross, 23U)) + 10428437770166310549U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 18327174144859461029U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 6810436935194432002U;
            aOrbiterI = RotL64((aOrbiterI * 2715987179577753597U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 12606153309690753435U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 17123256945895150555U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13469111258504672565U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 9057777759026189541U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 16478485918911194442U;
            aOrbiterF = RotL64((aOrbiterF * 11054247078884894131U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 18064460487552100483U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 11477276762421684083U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3886501230380184395U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 18318375441973295081U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 13849305985380030986U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12962140243967824959U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 10240409420338313641U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 18360586077779529086U;
            aOrbiterE = RotL64((aOrbiterE * 18196875422391501927U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 16801797158622424257U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 4950305991208513887U;
            aOrbiterA = RotL64((aOrbiterA * 4437082499761416951U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 15790878572843321918U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 9808781805065559728U;
            aOrbiterH = RotL64((aOrbiterH * 9394280083159162953U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 11974996650410830731U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 4955004489435232515U;
            aOrbiterC = RotL64((aOrbiterC * 13301966529515483085U), 47U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterI, 34U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 13U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 37U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 21U));
            aIngress = aIngress + RotL64(aOrbiterC, 56U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 11U) + aOrbiterD) + RotL64(aOrbiterA, 48U));
            aWandererH = aWandererH + ((RotL64(aScatter, 5U) + aOrbiterD) + RotL64(aOrbiterI, 23U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 27U) + aOrbiterA) + RotL64(aOrbiterH, 43U)) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 34U) + RotL64(aOrbiterD, 11U)) + aOrbiterE) + RotL64(aCarry, 11U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 41U) + aOrbiterG) + RotL64(aOrbiterF, 57U));
            aWandererI = aWandererI + ((RotL64(aIngress, 19U) + RotL64(aOrbiterA, 5U)) + aOrbiterC);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 53U) + aOrbiterE) + RotL64(aOrbiterA, 29U));
            aWandererJ = aWandererJ + ((((RotL64(aCross, 23U) + aOrbiterJ) + RotL64(aOrbiterG, 18U)) + RotL64(aCarry, 23U)) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 48U) + aOrbiterI) + RotL64(aOrbiterJ, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 24U));
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererH, 53U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 26239U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((aIndex + 26270U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25116U)) & S_BLOCK1], 51U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 28349U)) & S_BLOCK1], 24U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 24U) ^ RotL64(aIngress, 57U)) + (RotL64(aCross, 43U) + RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = ((aWandererI + RotL64(aScatter, 53U)) + RotL64(aCarry, 21U)) + 380024772508948442U;
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 37U)) + RotL64(aCarry, 35U)) + 7649029098162567210U;
            aOrbiterG = (aWandererF + RotL64(aIngress, 28U)) + 5329304598870421851U;
            aOrbiterB = (aWandererK + RotL64(aCross, 43U)) + 12306118665045151326U;
            aOrbiterJ = (aWandererE + RotL64(aIngress, 23U)) + 960751560457324256U;
            aOrbiterF = (aWandererB + RotL64(aPrevious, 47U)) + 3244070254386191876U;
            aOrbiterE = (aWandererJ + RotL64(aScatter, 5U)) + 15733408571609521746U;
            aOrbiterC = (((aWandererG + RotL64(aCross, 57U)) + RotL64(aCarry, 11U)) + 17623448932647018544U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 12U)) + 8787759896149035829U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 14741681792348288162U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 8801731213568307302U;
            aOrbiterG = RotL64((aOrbiterG * 12127126999570616489U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 9872248187499779222U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 15407371518644528235U;
            aOrbiterJ = RotL64((aOrbiterJ * 1245102406469471673U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 4242060317152943062U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 9942784962409917541U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 888649755587764533U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 7296348796484458631U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 15061417216070157797U;
            aOrbiterH = RotL64((aOrbiterH * 10349554676953256231U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 3233185810644297433U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 9241229457641024287U;
            aOrbiterB = RotL64((aOrbiterB * 2728237515724597517U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 8464051359381554575U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 3307872165699029375U;
            aOrbiterF = RotL64((aOrbiterF * 4859663401033023433U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 5482617843966711997U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 4442149210462943872U;
            aOrbiterC = RotL64((aOrbiterC * 8979352218576515647U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 10591636597580147381U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 14925122230279312217U;
            aOrbiterD = RotL64((aOrbiterD * 15038171961638724013U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 9772367878232735350U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 15800661165607190092U;
            aOrbiterI = RotL64((aOrbiterI * 10493976952980533589U), 23U);
            //
            aIngress = RotL64(aOrbiterI, 5U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 54U));
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterH, 39U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterJ, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aIngress, 43U) + RotL64(aOrbiterF, 6U)) + aOrbiterJ) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 34U) + RotL64(aOrbiterF, 29U)) + aOrbiterG);
            aWandererG = aWandererG + (((RotL64(aPrevious, 39U) + aOrbiterC) + RotL64(aOrbiterH, 41U)) + RotL64(aCarry, 41U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterD, 51U)) + aOrbiterI);
            aWandererD = aWandererD + ((RotL64(aIngress, 27U) + aOrbiterG) + RotL64(aOrbiterH, 57U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterE, 19U)) + aOrbiterH);
            aWandererA = aWandererA + ((RotL64(aScatter, 13U) + aOrbiterC) + RotL64(aOrbiterE, 23U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 47U) + aOrbiterD) + RotL64(aOrbiterE, 35U));
            aWandererE = aWandererE + ((((RotL64(aCross, 58U) + aOrbiterI) + RotL64(aOrbiterB, 12U)) + RotL64(aCarry, 51U)) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 6U) ^ aWandererI);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererB, 43U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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

void TwistExpander_Tennis_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 495U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3154U)) & S_BLOCK1], 34U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 1393U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 7439U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCross, 19U)) + (RotL64(aIngress, 54U) ^ RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 11U)) + RotL64(aCarry, 23U)) + 16189787374324972735U;
            aOrbiterE = (((aWandererH + RotL64(aIngress, 38U)) + RotL64(aCarry, 5U)) + 17563763730956242224U) + aPhaseDOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 51U)) + RotL64(aCarry, 51U)) + 10572803498593789385U;
            aOrbiterK = ((aWandererG + RotL64(aCross, 27U)) + 7713105232072974166U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = (aWandererJ + RotL64(aScatter, 19U)) + 10760839534772718139U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 13397069448391230253U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 4569255679998375682U;
            aOrbiterC = RotL64((aOrbiterC * 15163488708398248639U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 9888769350817876949U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 11351796060878856300U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13356749147334008399U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 18153775071965707204U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 1282846411145853435U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12294455920906257823U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 16457743979262460660U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 173493260775251032U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4935807229040883505U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 3927345926316409630U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 5158769729850853623U;
            aOrbiterG = RotL64((aOrbiterG * 2446452358663812945U), 37U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterG, 51U);
            aIngress = aIngress + (RotL64(aOrbiterC, 13U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterE, 40U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterK, 11U)) + aOrbiterJ) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 3U) + RotL64(aOrbiterG, 47U)) + aOrbiterE) + RotL64(aCarry, 39U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 19U) + aOrbiterC) + RotL64(aOrbiterJ, 39U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 38U) + aOrbiterG) + RotL64(aOrbiterJ, 29U)) + RotL64(aCarry, 21U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 11U) + aOrbiterC) + RotL64(aOrbiterG, 56U)) + aPhaseDWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 21U));
            aCarry = aCarry + RotL64(aWandererJ, 51U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 11743U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 9595U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 14799U)) & S_BLOCK1], 36U) ^ RotL64(aExpandLaneB[((aIndex + 9502U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aIngress, 22U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = (aWandererE + RotL64(aPrevious, 57U)) + 5173905450211892891U;
            aOrbiterC = (((aWandererJ + RotL64(aIngress, 38U)) + RotL64(aCarry, 53U)) + 3555542451908039957U) + aPhaseDOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = (((aWandererB + RotL64(aScatter, 3U)) + RotL64(aCarry, 5U)) + 11559884700283861559U) + aPhaseDOrbiterAssignSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = ((aWandererD + RotL64(aCross, 47U)) + RotL64(aCarry, 41U)) + 1352524329968738673U;
            aOrbiterK = (aWandererK + RotL64(aPrevious, 21U)) + 8914206450420616349U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 2251523378498463946U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 9541575923299247038U;
            aOrbiterB = RotL64((aOrbiterB * 1066487482799638689U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 1239854507907214595U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 17698101462598498934U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2304948713665996433U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 12305566971683256060U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 13804545036303215569U;
            aOrbiterH = RotL64((aOrbiterH * 10359543704152744971U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 10239749097704329264U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 4212214906286320308U;
            aOrbiterC = RotL64((aOrbiterC * 3661436621615751071U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 12192418916967430783U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 4475514289326450361U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17497164630368757887U), 37U);
            //
            aIngress = RotL64(aOrbiterG, 51U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterK, 13U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aScatter, 47U) + aOrbiterH) + RotL64(aOrbiterG, 12U)) + RotL64(aCarry, 23U)) + aPhaseDWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 38U) + RotL64(aOrbiterB, 21U)) + aOrbiterK);
            aWandererK = aWandererK + (((RotL64(aIngress, 11U) + RotL64(aOrbiterB, 3U)) + aOrbiterG) + RotL64(aCarry, 37U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 21U) + aOrbiterH) + RotL64(aOrbiterK, 39U));
            aWandererB = aWandererB + (((RotL64(aScatter, 29U) + RotL64(aOrbiterC, 47U)) + aOrbiterG) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererB, 13U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererJ, 4U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 18926U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 23870U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17156U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 17774U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 18U) ^ RotL64(aCross, 5U)) + (RotL64(aCarry, 39U) ^ RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = (aWandererA + RotL64(aScatter, 3U)) + 10805654776556844351U;
            aOrbiterB = ((aWandererG + RotL64(aCross, 26U)) + RotL64(aCarry, 5U)) + 582794182442795335U;
            aOrbiterF = ((aWandererE + RotL64(aIngress, 39U)) + RotL64(aCarry, 27U)) + 2858343650974681068U;
            aOrbiterA = (((aWandererB + RotL64(aPrevious, 11U)) + RotL64(aCarry, 41U)) + 8189584049022064284U) + aPhaseDOrbiterAssignSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = ((aWandererF + RotL64(aIngress, 57U)) + 1565100751996962893U) + aPhaseDOrbiterAssignSaltC[((aIndex + 14U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 8062028016947611891U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 8280504280578451745U;
            aOrbiterF = RotL64((aOrbiterF * 5212851648135050483U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 11326869194491655350U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 1671695656567777163U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7511554500524257921U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 2349843105293943452U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 13015545152052004254U;
            aOrbiterI = RotL64((aOrbiterI * 1316662811685429983U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 16703354404749291869U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 8713231044374305801U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9242480982197688625U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 11118401674497783533U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 14857556493734710364U;
            aOrbiterH = RotL64((aOrbiterH * 3452566050389715195U), 53U);
            //
            aIngress = RotL64(aOrbiterB, 23U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 11U));
            aIngress = aIngress + RotL64(aOrbiterA, 60U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aCross, 56U) + RotL64(aOrbiterA, 43U)) + aOrbiterH) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aIngress, 11U) + aOrbiterB) + RotL64(aOrbiterF, 34U)) + RotL64(aCarry, 11U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 19U) + aOrbiterI) + RotL64(aOrbiterB, 53U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 3U) + aOrbiterB) + RotL64(aOrbiterH, 21U)) + RotL64(aCarry, 37U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 43U) + aOrbiterA) + RotL64(aOrbiterF, 5U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 56U));
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererB, 39U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 25554U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneB[((aIndex + 32336U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 29503U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 29542U)) & S_BLOCK1], 42U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 51U) ^ RotL64(aPrevious, 38U)) ^ (RotL64(aIngress, 5U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = (aWandererC + RotL64(aCross, 53U)) + 77518479758428414U;
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 14U)) + 4832061802166300011U) + aPhaseDOrbiterAssignSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = (((aWandererH + RotL64(aIngress, 29U)) + RotL64(aCarry, 29U)) + 11695291171006574112U) + aPhaseDOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 3U)) + RotL64(aCarry, 43U)) + 7467412817843260094U;
            aOrbiterA = ((aWandererJ + RotL64(aCross, 37U)) + RotL64(aCarry, 57U)) + 17801484124471154757U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 5555455638503958639U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 5669470540733721606U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17219613748084498879U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 3042388456327784163U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 2236734925228156691U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10076582424701705531U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 14459720401528685450U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 4814967631216658856U;
            aOrbiterJ = RotL64((aOrbiterJ * 18288097536171386643U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 16950679344449075945U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 6262238639302011050U;
            aOrbiterB = RotL64((aOrbiterB * 9942659897425088183U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 3522256359074996724U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 12524717897707074242U;
            aOrbiterA = RotL64((aOrbiterA * 6787771338063891989U), 47U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterJ, 37U);
            aIngress = aIngress + (RotL64(aOrbiterA, 21U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterE, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aScatter, 39U) + aOrbiterA) + RotL64(aOrbiterJ, 5U)) + RotL64(aCarry, 19U)) + aPhaseDWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 30U) + aOrbiterD) + RotL64(aOrbiterB, 19U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 13U) + RotL64(aOrbiterE, 27U)) + aOrbiterJ) + aPhaseDWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterD, 50U)) + aOrbiterA);
            aWandererG = aWandererG + (((RotL64(aCross, 53U) + aOrbiterB) + RotL64(aOrbiterE, 39U)) + RotL64(aCarry, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 27U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererG, 56U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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

void TwistExpander_Tennis_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 5471U)) & S_BLOCK1], 44U) ^ RotL64(aOperationLaneC[((aIndex + 1857U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 2064U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneA[((aIndex + 3752U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 56U) + RotL64(aPrevious, 5U)) ^ (RotL64(aCarry, 43U) ^ RotL64(aIngress, 29U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = (aWandererK + RotL64(aPrevious, 58U)) + 13174219512651137892U;
            aOrbiterJ = (aWandererC + RotL64(aScatter, 41U)) + 2715455762789269341U;
            aOrbiterH = ((aWandererE + RotL64(aCross, 19U)) + RotL64(aCarry, 21U)) + 1338018183235594313U;
            aOrbiterC = (aWandererB + RotL64(aIngress, 13U)) + 16566866551729552930U;
            aOrbiterE = ((aWandererD + RotL64(aScatter, 29U)) + RotL64(aCarry, 3U)) + 6901845297307236726U;
            aOrbiterI = (((aWandererJ + RotL64(aPrevious, 47U)) + RotL64(aCarry, 47U)) + 2476078302049201718U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = ((aWandererI + RotL64(aIngress, 5U)) + 15531109473927052260U) + aPhaseEOrbiterAssignSaltC[((aIndex + 10U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 4087849380858572351U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 5167830630098599644U;
            aOrbiterH = RotL64((aOrbiterH * 1982835131228146099U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 7275995452428627217U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 14794340370010024117U;
            aOrbiterE = RotL64((aOrbiterE * 8779497557416568379U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 8509217403041662849U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 2321522025240806996U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 113568101672878697U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 5676672952755594051U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 2304681269233504384U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15731441084605554497U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 8383399721062437300U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 13181984036942227666U;
            aOrbiterD = RotL64((aOrbiterD * 1648761328771932069U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 13602604532551684210U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 12725687663616352843U;
            aOrbiterC = RotL64((aOrbiterC * 4684699861686199753U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 5831790822416009806U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 4535048543735457407U;
            aOrbiterJ = RotL64((aOrbiterJ * 12076777878870257053U), 35U);
            //
            aIngress = RotL64(aOrbiterJ, 29U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 5U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 11U));
            aIngress = aIngress + RotL64(aOrbiterC, 58U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterE, 53U)) + aOrbiterD);
            aWandererB = aWandererB + (((RotL64(aScatter, 39U) + aOrbiterJ) + RotL64(aOrbiterG, 41U)) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 60U) + RotL64(aOrbiterJ, 27U)) + aOrbiterD) + aPhaseEWandererUpdateSaltA[((aIndex + 4U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 19U) + aOrbiterG) + RotL64(aOrbiterD, 3U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterC, 47U)) + aOrbiterH);
            aWandererI = aWandererI + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterD, 34U)) + aOrbiterH) + RotL64(aCarry, 39U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 47U) + aOrbiterC) + RotL64(aOrbiterI, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererB, 18U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 14703U)) & S_BLOCK1], 52U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 14394U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 12522U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneB[((aIndex + 13057U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 19U) + RotL64(aIngress, 3U)) ^ (RotL64(aCarry, 34U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = ((aWandererB + RotL64(aIngress, 53U)) + RotL64(aCarry, 21U)) + 11700815697312060726U;
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 41U)) + RotL64(aCarry, 5U)) + 11808423452327465441U;
            aOrbiterG = ((aWandererD + RotL64(aCross, 34U)) + 8670503858631730886U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = ((aWandererI + RotL64(aScatter, 21U)) + 2400061067991988544U) + aPhaseEOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = (aWandererH + RotL64(aIngress, 13U)) + 16163118178366229686U;
            aOrbiterB = ((aWandererA + RotL64(aCross, 47U)) + RotL64(aCarry, 35U)) + 3280178595904941068U;
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 5U)) + 3298683600817047727U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 16321624053445183574U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 6730229877611375225U;
            aOrbiterG = RotL64((aOrbiterG * 2022290495153519279U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 10162830636713641322U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 15646771327759599256U;
            aOrbiterC = RotL64((aOrbiterC * 15333053762177144775U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 14841751262270544102U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 9545541117228834895U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11529769874752969377U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 14676615635857599982U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 1231768638470558855U;
            aOrbiterE = RotL64((aOrbiterE * 2716808508509014677U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 1945905595345404833U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 1406171421638586846U;
            aOrbiterK = RotL64((aOrbiterK * 4577864352425476233U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 1970292335806697198U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 12309719390375013297U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16540660957923687327U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 5352135521358954576U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 15465675376193501658U;
            aOrbiterH = RotL64((aOrbiterH * 16385761112921041387U), 19U);
            //
            aIngress = RotL64(aOrbiterK, 5U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 41U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 58U));
            aIngress = aIngress + RotL64(aOrbiterE, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 19U) + aOrbiterG) + RotL64(aOrbiterC, 23U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aPrevious, 57U) + aOrbiterK) + RotL64(aOrbiterE, 29U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 11U) + aOrbiterK) + RotL64(aOrbiterB, 47U)) + aPhaseEWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 48U) + aOrbiterG) + RotL64(aOrbiterH, 41U)) + RotL64(aCarry, 11U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterC, 13U)) + aOrbiterH);
            aWandererA = aWandererA + (((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterB, 56U)) + RotL64(aCarry, 57U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterK, 35U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 48U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererA, 39U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 19605U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((aIndex + 23898U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 23836U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 18500U)) & S_BLOCK1], 50U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aPrevious, 35U)) + (RotL64(aIngress, 51U) ^ RotL64(aCarry, 10U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = (aWandererF + RotL64(aIngress, 51U)) + 11480359716598965890U;
            aOrbiterB = (aWandererB + RotL64(aCross, 21U)) + 15431182525482873419U;
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 58U)) + RotL64(aCarry, 29U)) + 11360504974812776707U;
            aOrbiterA = ((aWandererD + RotL64(aScatter, 11U)) + 9292576416573382769U) + aPhaseEOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = (aWandererG + RotL64(aPrevious, 3U)) + 1549257414531028975U;
            aOrbiterH = (((aWandererA + RotL64(aCross, 35U)) + RotL64(aCarry, 57U)) + 5347769463033129317U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = ((aWandererK + RotL64(aIngress, 27U)) + RotL64(aCarry, 11U)) + 17019199177478377234U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 16558106007323125094U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 3976182233825939422U;
            aOrbiterE = RotL64((aOrbiterE * 4392162052317572289U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 2889047161195954395U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 2241831345026962605U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5757458560979927857U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 12850802412140579294U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 13541744735436450160U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 906089290000537439U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 2085863085516538212U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 2969034221711544086U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7768528124408400403U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 6482666944512391472U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 16969153556875844613U;
            aOrbiterD = RotL64((aOrbiterD * 9483462388353216219U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 5161314086757363678U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 7150282484670673211U;
            aOrbiterH = RotL64((aOrbiterH * 8522427002337918663U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 5465304381272305847U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 2344610773390354017U;
            aOrbiterC = RotL64((aOrbiterC * 17010258514288089191U), 5U);
            //
            aIngress = RotL64(aOrbiterC, 51U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterB, 41U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterD, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 13U) + aOrbiterE) + RotL64(aOrbiterB, 47U));
            aWandererA = aWandererA + (((RotL64(aIngress, 21U) + aOrbiterE) + RotL64(aOrbiterC, 35U)) + RotL64(aCarry, 11U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterC, 10U)) + aOrbiterH) + aPhaseEWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aScatter, 29U) + RotL64(aOrbiterK, 3U)) + aOrbiterB);
            aWandererK = aWandererK ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterD, 41U)) + aOrbiterC) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 39U) + aOrbiterC) + RotL64(aOrbiterB, 53U)) + RotL64(aCarry, 35U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 4U) + aOrbiterB) + RotL64(aOrbiterA, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 18U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererB, 51U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 29992U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneB[((aIndex + 28343U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26310U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneD[((aIndex + 29114U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 51U) + RotL64(aCarry, 6U)) ^ (RotL64(aIngress, 23U) ^ RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = ((aWandererF + RotL64(aCross, 13U)) + RotL64(aCarry, 53U)) + 9080426856729228705U;
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 43U)) + RotL64(aCarry, 37U)) + 7851218321653539276U;
            aOrbiterC = (aWandererD + RotL64(aIngress, 3U)) + 7023344692919298036U;
            aOrbiterH = (aWandererA + RotL64(aScatter, 29U)) + 9772846154227440734U;
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 35U)) + 12008298632429608431U) + aPhaseEOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = ((aWandererH + RotL64(aCross, 19U)) + 12201090455849562875U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = ((aWandererI + RotL64(aIngress, 58U)) + RotL64(aCarry, 19U)) + 9498721803411445471U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 351203764023093632U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 4966360430644539250U;
            aOrbiterC = RotL64((aOrbiterC * 10138518378274592739U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 9194167899071345693U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 4922477697284269116U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8444814161720407881U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 15742625291642356429U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 7528703106518431730U;
            aOrbiterD = RotL64((aOrbiterD * 11530049278751507567U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 15279053574704935317U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 2425839793660355555U;
            aOrbiterJ = RotL64((aOrbiterJ * 11486964816849830667U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 13209849392400008898U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 9041500097716231309U;
            aOrbiterB = RotL64((aOrbiterB * 340661035700748739U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 7885423750878814599U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 1992993999902904603U;
            aOrbiterH = RotL64((aOrbiterH * 1478629826632201617U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 6120758615019314102U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 8529621625846992066U;
            aOrbiterE = RotL64((aOrbiterE * 8485991471612862467U), 41U);
            //
            aIngress = RotL64(aOrbiterH, 21U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 57U));
            aIngress = aIngress + RotL64(aOrbiterE, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aCross, 47U) + aOrbiterJ) + RotL64(aOrbiterA, 37U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 37U) + RotL64(aOrbiterC, 11U)) + aOrbiterB);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 53U) + aOrbiterE) + RotL64(aOrbiterB, 4U));
            aWandererA = aWandererA + (((RotL64(aIngress, 27U) + RotL64(aOrbiterC, 27U)) + aOrbiterD) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 3U) + aOrbiterA) + RotL64(aOrbiterH, 57U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 21U) + aOrbiterH) + RotL64(aOrbiterC, 21U)) + RotL64(aCarry, 11U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 12U) + RotL64(aOrbiterC, 43U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererE, 14U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererI);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + RotL64(aWandererH, 5U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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

void TwistExpander_Tennis_Arx::Twist_D(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterG = 0;
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 8040U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 479U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2565U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneA[((aIndex + 3921U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aPrevious, 36U)) ^ (RotL64(aIngress, 11U) + RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = (aWandererG + RotL64(aCross, 57U)) + 6361545377408870615U;
            aOrbiterI = ((aWandererF + RotL64(aScatter, 4U)) + RotL64(aCarry, 41U)) + 2967245486744774933U;
            aOrbiterB = (((aWandererC + RotL64(aPrevious, 35U)) + RotL64(aCarry, 57U)) + 3836634268482850139U) + aPhaseFOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = ((aWandererB + RotL64(aIngress, 19U)) + RotL64(aCarry, 19U)) + 7691642115360086297U;
            aOrbiterG = ((aWandererJ + RotL64(aCross, 43U)) + 16479280384178279281U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 2901468732552539249U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 2600353867755647475U;
            aOrbiterB = RotL64((aOrbiterB * 1140827276372862433U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 5666596904781510956U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 16108791609267427553U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8904649663479834199U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 8389926875737312112U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 1689501721163024426U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6517194895779049139U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 11721701506949917719U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 3963842745030140473U;
            aOrbiterI = RotL64((aOrbiterI * 6692473494944919373U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 8510538243472109368U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 18281865214102080387U;
            aOrbiterG = RotL64((aOrbiterG * 1351546966368884609U), 41U);
            //
            aIngress = RotL64(aOrbiterJ, 19U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 43U));
            aIngress = aIngress + RotL64(aOrbiterB, 54U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 3U) + aOrbiterG) + RotL64(aOrbiterI, 23U));
            aWandererC = aWandererC + (((RotL64(aIngress, 12U) + RotL64(aOrbiterK, 3U)) + aOrbiterJ) + RotL64(aCarry, 53U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterJ, 40U)) + aOrbiterG) + aPhaseFWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aScatter, 21U) + RotL64(aOrbiterB, 13U)) + aOrbiterJ) + RotL64(aCarry, 27U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 43U) + aOrbiterG) + RotL64(aOrbiterB, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 4U) ^ aWandererG);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 16192U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 10677U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8948U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 11004U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 52U) + RotL64(aCarry, 37U)) + (RotL64(aCross, 19U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 52U)) + RotL64(aCarry, 19U)) + 4622023259121087483U;
            aOrbiterG = (((aWandererJ + RotL64(aIngress, 39U)) + RotL64(aCarry, 53U)) + 10253505250223501352U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = ((aWandererH + RotL64(aCross, 3U)) + RotL64(aCarry, 39U)) + 17133877904420462669U;
            aOrbiterB = (aWandererE + RotL64(aScatter, 27U)) + 6162827793741796700U;
            aOrbiterJ = ((aWandererG + RotL64(aCross, 13U)) + 9610986424765907615U) + aPhaseFOrbiterAssignSaltE[((aIndex + 4U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 11210747154264753754U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 16554205219580654546U;
            aOrbiterI = RotL64((aOrbiterI * 12754735039924859911U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 10352576357413766388U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 3651845783283479752U;
            aOrbiterJ = RotL64((aOrbiterJ * 1011289824180799641U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 18145542190463500476U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 5415609566767162857U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6474184559323816389U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 2033734872464201570U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 3507213117125813345U;
            aOrbiterG = RotL64((aOrbiterG * 5453058336688881113U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 8716253393049851856U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 695984869565941856U;
            aOrbiterB = RotL64((aOrbiterB * 8377921610764044735U), 3U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterG, 13U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 40U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterC, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aCross, 29U) + aOrbiterG) + RotL64(aOrbiterC, 60U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 57U) + aOrbiterI) + RotL64(aOrbiterB, 51U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 46U) + RotL64(aOrbiterG, 23U)) + aOrbiterB) + RotL64(aCarry, 51U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 19U) + aOrbiterB) + RotL64(aOrbiterC, 41U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aCross, 5U) + RotL64(aOrbiterJ, 13U)) + aOrbiterC) + RotL64(aCarry, 29U)) + aPhaseFWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 53U) ^ aWandererJ);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + RotL64(aWandererH, 3U);
            aCarry = aCarry + RotL64(aIngress, 28U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 19513U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((aIndex + 22660U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 20001U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 16745U)) & S_BLOCK1], 40U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 40U)) ^ (RotL64(aIngress, 23U) + RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = (aWandererD + RotL64(aCross, 43U)) + 5088525177670191619U;
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 11U)) + RotL64(aCarry, 43U)) + 9966456257813932112U;
            aOrbiterJ = (((aWandererK + RotL64(aScatter, 22U)) + RotL64(aCarry, 21U)) + 7707646574027146307U) + aPhaseFOrbiterAssignSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = (((aWandererB + RotL64(aIngress, 3U)) + RotL64(aCarry, 5U)) + 75480203757681173U) + aPhaseFOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = (aWandererH + RotL64(aCross, 35U)) + 384659134071835163U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 3158769775373307778U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 17360830943513941272U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9986023786908098621U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 5317278822721604586U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 1371427105215954781U;
            aOrbiterC = RotL64((aOrbiterC * 10956603063464438611U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 3162710551223553423U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 5332921933853550756U;
            aOrbiterI = RotL64((aOrbiterI * 11709546145149357887U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 10572462410297815854U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 10234389605554817892U;
            aOrbiterD = RotL64((aOrbiterD * 2130374833440291193U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 13421365517991380605U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 10186643614984034083U;
            aOrbiterG = RotL64((aOrbiterG * 8554471709467808453U), 27U);
            //
            aIngress = RotL64(aOrbiterI, 47U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterC, 34U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterD, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 57U) + aOrbiterC) + RotL64(aOrbiterJ, 43U));
            aWandererH = aWandererH + ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterD, 27U)) + aOrbiterJ) + RotL64(aCarry, 11U)) + aPhaseFWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aCross, 12U) + RotL64(aOrbiterI, 57U)) + aOrbiterD) + aPhaseFWandererUpdateSaltF[((aIndex + 14U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 37U) + RotL64(aOrbiterI, 19U)) + aOrbiterC) + RotL64(aCarry, 41U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterG, 6U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererD, 48U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererK, 57U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 31233U)) & S_BLOCK1], 18U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31078U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 30791U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 30076U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCross, 35U)) ^ (RotL64(aPrevious, 52U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = (aWandererG + RotL64(aIngress, 3U)) + 1087148170018530502U;
            aOrbiterC = ((aWandererB + RotL64(aCross, 39U)) + RotL64(aCarry, 3U)) + 15530846874509311414U;
            aOrbiterI = (aWandererC + RotL64(aScatter, 54U)) + 16987358651515511212U;
            aOrbiterK = (((aWandererA + RotL64(aPrevious, 29U)) + RotL64(aCarry, 19U)) + 12504143181007924259U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = (((aWandererK + RotL64(aScatter, 21U)) + RotL64(aCarry, 35U)) + 393322117322732418U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 14325937299241887166U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 9395262907017475742U;
            aOrbiterI = RotL64((aOrbiterI * 3442643798173589117U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 13658510441418344769U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 6410754322737005336U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6932217611373076391U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 9257290738538818434U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 7489828960857692286U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16519674788777989043U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 4118778591214588387U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 16619215231168796563U;
            aOrbiterC = RotL64((aOrbiterC * 14876884956536265157U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 11326283811003573430U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 1865401866017614604U;
            aOrbiterB = RotL64((aOrbiterB * 8378326058282460073U), 23U);
            //
            aIngress = RotL64(aOrbiterC, 3U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 24U));
            aIngress = aIngress + RotL64(aOrbiterK, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 11U) + aOrbiterK) + RotL64(aOrbiterG, 4U));
            aWandererC = aWandererC + (((RotL64(aIngress, 20U) + RotL64(aOrbiterC, 21U)) + aOrbiterG) + RotL64(aCarry, 47U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 37U) + aOrbiterK) + RotL64(aOrbiterI, 13U)) + aPhaseFWandererUpdateSaltE[((aIndex + 28U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aCross, 3U) + RotL64(aOrbiterK, 35U)) + aOrbiterB) + RotL64(aCarry, 11U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 47U) + aOrbiterI) + RotL64(aOrbiterC, 43U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererB, 5U);
            aCarry = aCarry + RotL64(aIngress, 48U);
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

void TwistExpander_Tennis_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 6574U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((aIndex + 2041U)) & S_BLOCK1], 34U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 4413U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 2937U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 19U) + RotL64(aCross, 34U)) ^ (RotL64(aIngress, 53U) + RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = (aWandererJ + RotL64(aIngress, 13U)) + 4622023259121087483U;
            aOrbiterH = (((aWandererF + RotL64(aPrevious, 29U)) + RotL64(aCarry, 35U)) + 10253505250223501352U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = (aWandererB + RotL64(aCross, 53U)) + 17133877904420462669U;
            aOrbiterC = (((aWandererH + RotL64(aScatter, 40U)) + RotL64(aCarry, 57U)) + 6162827793741796700U) + aPhaseGOrbiterAssignSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = ((aWandererK + RotL64(aIngress, 5U)) + RotL64(aCarry, 21U)) + 9610986424765907615U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 11210747154264753754U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 16554205219580654546U;
            aOrbiterD = RotL64((aOrbiterD * 12754735039924859911U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 10352576357413766388U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 3651845783283479752U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1011289824180799641U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 18145542190463500476U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 5415609566767162857U;
            aOrbiterC = RotL64((aOrbiterC * 6474184559323816389U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 2033734872464201570U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 3507213117125813345U;
            aOrbiterH = RotL64((aOrbiterH * 5453058336688881113U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 8716253393049851856U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 695984869565941856U;
            aOrbiterB = RotL64((aOrbiterB * 8377921610764044735U), 11U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterD, 19U);
            aIngress = aIngress + (RotL64(aOrbiterH, 29U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterI, 6U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aCross, 47U) + aOrbiterB) + RotL64(aOrbiterI, 19U)) + RotL64(aCarry, 29U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 11U) + aOrbiterC) + RotL64(aOrbiterH, 47U)) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 20U) + aOrbiterB) + RotL64(aOrbiterH, 29U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 57U) + aOrbiterB) + RotL64(aOrbiterD, 58U)) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 3U) + RotL64(aOrbiterI, 39U)) + aOrbiterD) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 60U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 21U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererK, 5U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 8461U)) & S_BLOCK1], 50U) ^ RotL64(aWorkLaneC[((aIndex + 10347U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 15443U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 9212U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCross, 6U)) ^ (RotL64(aCarry, 19U) + RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 51U)) + 1557680213571812384U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = (aWandererC + RotL64(aIngress, 29U)) + 7387349725778021121U;
            aOrbiterE = ((aWandererE + RotL64(aCross, 3U)) + RotL64(aCarry, 23U)) + 15379264067601586976U;
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 43U)) + RotL64(aCarry, 51U)) + 3730195724576043708U;
            aOrbiterH = (((aWandererG + RotL64(aIngress, 14U)) + RotL64(aCarry, 3U)) + 9637070085323827066U) + aPhaseGOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 1170865717363676184U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 2750833653175252030U;
            aOrbiterE = RotL64((aOrbiterE * 1937822982381882775U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 15118992811225568305U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 4974092922102988451U;
            aOrbiterH = RotL64((aOrbiterH * 10575977398702460975U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 10625719096296719514U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 855167122475471865U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7441090331293158773U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 11322911068958340262U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 4334591909425429835U;
            aOrbiterC = RotL64((aOrbiterC * 10059025861172038183U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 14263701737208936392U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 678723206735649084U;
            aOrbiterA = RotL64((aOrbiterA * 10823239851733632227U), 27U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterH, 38U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 23U));
            aIngress = aIngress + RotL64(aOrbiterC, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aScatter, 54U) + RotL64(aOrbiterE, 10U)) + aOrbiterA) + aPhaseGWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterI, 27U)) + aOrbiterC) + RotL64(aCarry, 37U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 29U) + aOrbiterA) + RotL64(aOrbiterC, 19U)) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 19U) + RotL64(aOrbiterH, 43U)) + aOrbiterE) + RotL64(aCarry, 51U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterH, 51U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 60U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + RotL64(aWandererC, 35U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 21873U)) & S_BLOCK1], 14U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 24498U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 18234U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((aIndex + 19212U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 19U) + RotL64(aCarry, 41U)) + (RotL64(aCross, 54U) ^ RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = (((aWandererD + RotL64(aCross, 11U)) + RotL64(aCarry, 21U)) + 12775735908960052604U) + aPhaseGOrbiterAssignSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = (aWandererA + RotL64(aScatter, 3U)) + 11791373812080296887U;
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 29U)) + RotL64(aCarry, 3U)) + 5537362877706057303U;
            aOrbiterI = (((aWandererG + RotL64(aIngress, 57U)) + RotL64(aCarry, 35U)) + 2023912048504189380U) + aPhaseGOrbiterAssignSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = (aWandererH + RotL64(aPrevious, 38U)) + 17668828109963766893U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 558908629933941224U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 1479633119685446888U;
            aOrbiterG = RotL64((aOrbiterG * 4447153373540811385U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 15460320397843364063U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 10059749397555469054U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8671817118586065469U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 9987633811929693924U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 10087337844580228269U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13817142288940843815U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 4446204415503364254U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 15106063243302192717U;
            aOrbiterI = RotL64((aOrbiterI * 13273756657334709803U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 9430197906134676162U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 1226048679997253363U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14247538885252664127U), 27U);
            //
            aIngress = RotL64(aOrbiterG, 29U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterC, 52U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aIngress, 20U) + RotL64(aOrbiterH, 13U)) + aOrbiterI) + RotL64(aCarry, 57U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterE, 41U)) + aOrbiterC);
            aWandererG = aWandererG + (((RotL64(aPrevious, 29U) + aOrbiterI) + RotL64(aOrbiterG, 53U)) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterI, 3U)) + aOrbiterC) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 57U) + aOrbiterH) + RotL64(aOrbiterG, 30U)) + RotL64(aCarry, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererA);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 4U));
            aCarry = aCarry + RotL64(aWandererH, 21U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 27573U)) & S_BLOCK1], 18U) ^ RotL64(aExpandLaneA[((aIndex + 28529U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31189U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 26009U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 41U) ^ RotL64(aIngress, 13U)) + (RotL64(aPrevious, 27U) + RotL64(aCross, 56U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = ((aWandererG + RotL64(aPrevious, 14U)) + RotL64(aCarry, 13U)) + 4739486756133131180U;
            aOrbiterF = (((aWandererK + RotL64(aScatter, 5U)) + RotL64(aCarry, 53U)) + 16089707555501328184U) + aPhaseGOrbiterAssignSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = ((aWandererD + RotL64(aIngress, 39U)) + RotL64(aCarry, 35U)) + 15310047330238536453U;
            aOrbiterC = ((aWandererA + RotL64(aCross, 47U)) + 7901411596386834955U) + aPhaseGOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = (aWandererF + RotL64(aIngress, 57U)) + 4357555491060982163U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 15667085602825720102U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 8520635334382269253U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7348648918661047791U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 1772509779231068315U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 15336170957886025677U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10996880551392077399U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 8628770833489469980U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 15469234024247246228U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8905266995119987947U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 10796430900884288328U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 10660110397012853289U;
            aOrbiterF = RotL64((aOrbiterF * 9140007610912037461U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 11202284258711214794U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 17509491802893182994U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9329107599972703671U), 11U);
            //
            aIngress = RotL64(aOrbiterG, 3U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 38U));
            aIngress = aIngress + RotL64(aOrbiterA, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterK, 13U)) + aOrbiterC) + RotL64(aCarry, 43U)) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 39U) + aOrbiterC) + RotL64(aOrbiterA, 23U)) + aPhaseGWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aCross, 23U) + aOrbiterF) + RotL64(aOrbiterG, 35U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 50U) + aOrbiterF) + RotL64(aOrbiterA, 4U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 13U) + aOrbiterC) + RotL64(aOrbiterG, 47U)) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererD, 21U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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

void TwistExpander_Tennis_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 556U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((aIndex + 3287U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8182U)) & S_BLOCK1], 42U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 2799U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 56U) + RotL64(aIngress, 29U)) ^ (RotL64(aPrevious, 41U) + RotL64(aCarry, 13U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = ((aWandererC + RotL64(aScatter, 39U)) + 16802219662864902427U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 5U)) + RotL64(aCarry, 39U)) + 14332033461409490629U;
            aOrbiterE = (((aWandererD + RotL64(aIngress, 60U)) + RotL64(aCarry, 11U)) + 8781794298640286845U) + aPhaseHOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = (aWandererE + RotL64(aCross, 51U)) + 8459933908074937264U;
            aOrbiterG = ((aWandererI + RotL64(aScatter, 21U)) + RotL64(aCarry, 23U)) + 1883580287986004426U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 17500258188004626118U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 7934811305150872870U;
            aOrbiterE = RotL64((aOrbiterE * 10039004285642030761U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 6380363892361098905U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 12623079132626676910U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12406671746344127399U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 10455208121949202703U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 8805532707916767629U;
            aOrbiterH = RotL64((aOrbiterH * 666082374369701881U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 9161544391400377699U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 3501434325829663268U;
            aOrbiterA = RotL64((aOrbiterA * 7933545151293799637U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 651783304096081996U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 441505031509930622U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8045355432310956143U), 37U);
            //
            aIngress = RotL64(aOrbiterE, 28U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterG, 39U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterA, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aCross, 21U) + RotL64(aOrbiterH, 47U)) + aOrbiterC);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterA, 19U)) + aOrbiterG) + aPhaseHWandererUpdateSaltF[((aIndex + 16U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterG, 37U)) + aOrbiterE) + RotL64(aCarry, 23U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterC, 6U)) + aOrbiterE);
            aWandererD = aWandererD + (((RotL64(aScatter, 34U) + RotL64(aOrbiterH, 57U)) + aOrbiterA) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 56U));
            aCarry = aCarry + RotL64(aWandererJ, 43U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 14290U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 11665U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 12853U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((aIndex + 11111U)) & S_BLOCK1], 44U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 24U) + RotL64(aCarry, 39U)) + (RotL64(aCross, 5U) ^ RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = (aWandererG + RotL64(aIngress, 11U)) + 8767379393098711499U;
            aOrbiterD = ((aWandererA + RotL64(aCross, 56U)) + RotL64(aCarry, 19U)) + 7168159491580816433U;
            aOrbiterE = ((aWandererD + RotL64(aScatter, 29U)) + RotL64(aCarry, 5U)) + 9879279829061883406U;
            aOrbiterG = (((aWandererJ + RotL64(aPrevious, 47U)) + RotL64(aCarry, 39U)) + 10537167136053399303U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = ((aWandererI + RotL64(aScatter, 21U)) + 2839070018069188936U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 13844278063968429732U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 11278946626186474646U;
            aOrbiterE = RotL64((aOrbiterE * 6601953972456332355U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 11798425216660557799U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 7618446090703335192U;
            aOrbiterK = RotL64((aOrbiterK * 7168757300685156779U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 695423597006983660U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 14344728202803488813U;
            aOrbiterH = RotL64((aOrbiterH * 5168825904902285909U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 11656100506575697086U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 10384358779985773937U;
            aOrbiterD = RotL64((aOrbiterD * 247494692039140973U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 17585001605131977341U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 9964478171465522911U;
            aOrbiterG = RotL64((aOrbiterG * 13484044854790175315U), 43U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterD, 46U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 13U));
            aIngress = aIngress + RotL64(aOrbiterG, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aIngress, 19U) + aOrbiterK) + RotL64(aOrbiterE, 35U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 29U) + aOrbiterE) + RotL64(aOrbiterG, 47U)) + RotL64(aCarry, 27U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterH, 21U)) + aOrbiterD);
            aWandererD = aWandererD + (((RotL64(aScatter, 3U) + aOrbiterE) + RotL64(aOrbiterH, 56U)) + RotL64(aCarry, 41U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 54U) + aOrbiterG) + RotL64(aOrbiterD, 5U)) + aPhaseHWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererA, 11U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 21344U)) & S_BLOCK1], 36U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 23872U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18824U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((aIndex + 23177U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aIngress, 19U)) + (RotL64(aPrevious, 35U) ^ RotL64(aCarry, 50U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = ((aWandererI + RotL64(aIngress, 23U)) + RotL64(aCarry, 41U)) + 9080426856729228705U;
            aOrbiterB = ((aWandererJ + RotL64(aCross, 56U)) + RotL64(aCarry, 23U)) + 7851218321653539276U;
            aOrbiterH = ((aWandererK + RotL64(aScatter, 39U)) + RotL64(aCarry, 11U)) + 7023344692919298036U;
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 47U)) + 9772846154227440734U) + aPhaseHOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = ((aWandererF + RotL64(aCross, 13U)) + 12008298632429608431U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 12201090455849562875U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 9498721803411445471U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6511810500788451775U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 351203764023093632U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 4966360430644539250U;
            aOrbiterB = RotL64((aOrbiterB * 10138518378274592739U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 9194167899071345693U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 4922477697284269116U;
            aOrbiterK = RotL64((aOrbiterK * 8444814161720407881U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 15742625291642356429U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 7528703106518431730U;
            aOrbiterA = RotL64((aOrbiterA * 11530049278751507567U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 15279053574704935317U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 2425839793660355555U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11486964816849830667U), 21U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterE, 13U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 41U));
            aIngress = aIngress + RotL64(aOrbiterB, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 57U) + aOrbiterH) + RotL64(aOrbiterB, 13U));
            aWandererB = aWandererB + (((RotL64(aIngress, 19U) + aOrbiterB) + RotL64(aOrbiterK, 58U)) + RotL64(aCarry, 53U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterH, 23U)) + aOrbiterA) + aPhaseHWandererUpdateSaltC[((aIndex + 16U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 11U) + RotL64(aOrbiterE, 35U)) + aOrbiterA) + RotL64(aCarry, 29U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 44U) + aOrbiterA) + RotL64(aOrbiterK, 47U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererK);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + RotL64(aWandererB, 42U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 28225U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((aIndex + 29258U)) & S_BLOCK1], 34U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28487U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 25894U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 56U) ^ RotL64(aCarry, 23U)) ^ (RotL64(aIngress, 11U) + RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 39U)) + RotL64(aCarry, 29U)) + 7960325128608297381U;
            aOrbiterG = (((aWandererE + RotL64(aCross, 3U)) + RotL64(aCarry, 53U)) + 12773836012104052042U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = (aWandererA + RotL64(aScatter, 56U)) + 3173972621347773016U;
            aOrbiterH = ((aWandererH + RotL64(aIngress, 27U)) + 3708401356314308171U) + aPhaseHOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 19U)) + RotL64(aCarry, 11U)) + 950774285720019449U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 4170092315705438265U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 17000449130864980747U;
            aOrbiterA = RotL64((aOrbiterA * 7710635557693533263U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 8793910540062893860U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 520277969543516469U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4150613128885828229U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 12762214857389827271U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 2932451184340207695U;
            aOrbiterH = RotL64((aOrbiterH * 7513337346940091655U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 11062179998786293839U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 7919119215271524178U;
            aOrbiterG = RotL64((aOrbiterG * 9053677007180081359U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 1774988449597115155U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 3799792889466518953U;
            aOrbiterI = RotL64((aOrbiterI * 17512791286490623455U), 5U);
            //
            aIngress = RotL64(aOrbiterA, 14U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterF, 43U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterI, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterA, 35U)) + aOrbiterH) + aPhaseHWandererUpdateSaltB[((aIndex + 20U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 21U) + aOrbiterH) + RotL64(aOrbiterI, 5U)) + RotL64(aCarry, 39U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterF, 13U)) + aOrbiterG) + aPhaseHWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 39U) + RotL64(aOrbiterG, 56U)) + aOrbiterA) + RotL64(aCarry, 53U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 48U) + RotL64(aOrbiterF, 47U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererJ);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + RotL64(aWandererI, 11U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
