#include "TwistExpander_Soccer_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_Soccer_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xCF5188B655E702B3ULL + 0xCC4F70EF84CCF136ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xF8DA755A7E2FD70DULL + 0x88E2927AECCC9D7FULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x8F3C013CE7D15F45ULL + 0xEB530F572F05581BULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x91E88613E52E36F7ULL + 0xA495AF6B7AF7F47DULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x9DE2ECF4F8484CD9ULL + 0xCB3988DAF995A404ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x9CB87929F21C918BULL + 0xF39016A4A43B7B3FULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xCD42A2751719F299ULL + 0xF7FD7791FC8056F0ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xA357C1C12E8FE383ULL + 0xB50256F54F8C20A9ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x9A62DC86569FBA79ULL + 0xC7B74E4E3EAF39ACULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xEF6AAAD8DDB2368FULL + 0x8A5C6A9C92776928ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xA62544224C442C49ULL + 0xB0026F4F3E5640C4ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x9B91EE82FC8000EBULL + 0xDC62B69F09395605ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xCB2F34FD249ECCBBULL + 0xE27A4FEE8F334EA9ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xD0651C46E5CBEC79ULL + 0xADC75E897BDC9BA3ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xBF27827B13F52DFBULL + 0xC960811A21B44B40ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xB00CA3940DE8338BULL + 0xAE0C061BD28A8145ULL);
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
            aIngress = RotL64(mSource[((aIndex + 4319U)) & S_BLOCK1], 48U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 4055U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 524U)) & S_BLOCK1], 39U) ^ RotL64(mSource[((aIndex + 1427U)) & S_BLOCK1], 30U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aIngress, 5U)) ^ (RotL64(aCarry, 56U) ^ RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterF = (((aWandererI + RotL64(aPrevious, 58U)) + RotL64(aCarry, 39U)) + 9888431329297626900U) + aNonceWordE;
            aOrbiterG = (((aWandererJ + RotL64(aIngress, 39U)) + RotL64(aCarry, 53U)) + 2937735167534624403U) + aOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = (((aWandererB + RotL64(aCross, 41U)) + RotL64(aCarry, 21U)) + 17626022970343789617U) + aOrbiterAssignSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterH = (aWandererK + RotL64(aScatter, 3U)) + 5665660859333693743U;
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 10U)) + 1060537034632076669U) + aNonceWordO;
            aOrbiterB = (aWandererD + RotL64(aPrevious, 37U)) + 743777763907175800U;
            aOrbiterA = (aWandererG + RotL64(aScatter, 23U)) + 5744905970181808845U;
            aOrbiterC = (aWandererF + RotL64(aCross, 53U)) + 3545351394494002180U;
            aOrbiterI = (aWandererE + RotL64(aIngress, 51U)) + 4877547088414106007U;
            aOrbiterE = (aWandererH + RotL64(aCross, 47U)) + 11669378338379598445U;
            aOrbiterD = (aWandererC + RotL64(aScatter, 29U)) + 2961072441706158212U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 13984945589234919765U) + aNonceWordA;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 1433097875470903205U) ^ aOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 451996840039906781U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 716415411025451152U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 8542286150858297810U;
            aOrbiterJ = RotL64((aOrbiterJ * 9139015340823332449U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 12932391786479661299U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 14005503313299177013U) ^ aNonceWordI;
            aOrbiterC = RotL64((aOrbiterC * 802663466907819743U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 9382792812676318046U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 5138554251079724724U;
            aOrbiterF = RotL64((aOrbiterF * 6386016499265056247U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 8522380066269546172U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 11825536408101906458U;
            aOrbiterB = RotL64((aOrbiterB * 17042837108792016849U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 15504062350899452495U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 1219010998820336744U;
            aOrbiterG = RotL64((aOrbiterG * 10650635772711590803U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 6442717843380349632U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 1047843426279085117U;
            aOrbiterH = RotL64((aOrbiterH * 4074561571072878005U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 10611039527108679173U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 5092816736177358221U;
            aOrbiterA = RotL64((aOrbiterA * 14342779343820140833U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 12327496881352988530U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 6405703847824845457U) ^ aOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12094143526751620113U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 8906613392335197542U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 5962698890029858689U) ^ aNonceWordN;
            aOrbiterI = RotL64((aOrbiterI * 9136193803330500489U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 2610083915800734277U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 9888431329297626900U;
            aOrbiterE = RotL64((aOrbiterE * 3794133356691218671U), 5U);
            //
            aIngress = RotL64(aOrbiterG, 56U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 41U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 35U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 53U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 39U));
            aIngress = aIngress + RotL64(aOrbiterD, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 51U) + RotL64(aOrbiterC, 27U)) + aOrbiterJ) + aWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 57U) + aOrbiterG) + RotL64(aOrbiterC, 29U)) + aNonceWordK);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterE, 11U)) + aOrbiterC) + aNonceWordL);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 53U) + RotL64(aOrbiterG, 21U)) + aOrbiterF) + RotL64(aCarry, 47U)) + aWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 6U) + aOrbiterB) + RotL64(aOrbiterJ, 53U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterB, 24U)) + aOrbiterD) + aNonceWordB);
            aWandererE = aWandererE ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterG, 41U)) + aOrbiterI);
            aWandererF = aWandererF + (((RotL64(aIngress, 37U) + aOrbiterJ) + RotL64(aOrbiterK, 57U)) + RotL64(aCarry, 5U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 13U) + aOrbiterK) + RotL64(aOrbiterF, 13U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 29U) + aOrbiterA) + RotL64(aOrbiterJ, 35U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 60U) + aOrbiterH) + RotL64(aOrbiterG, 4U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + (RotL64(aWandererK, 60U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererD, 35U);
            aCarry = aCarry + RotL64(aIngress, 6U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 10579U)) & S_BLOCK1], 11U) ^ RotL64(mSource[((aIndex + 6406U)) & S_BLOCK1], 26U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 6336U)) & S_BLOCK1], 23U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 7983U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCross, 27U)) + (RotL64(aCarry, 6U) ^ RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterK = ((aWandererB + RotL64(aScatter, 44U)) + RotL64(aCarry, 19U)) + 13915875634607599122U;
            aOrbiterJ = (aWandererA + RotL64(aIngress, 19U)) + 1695770381382411673U;
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 23U)) + 3709105579778295511U) + aNonceWordI;
            aOrbiterI = (aWandererG + RotL64(aCross, 39U)) + 7673376335333251804U;
            aOrbiterE = (((aWandererE + RotL64(aPrevious, 13U)) + RotL64(aCarry, 29U)) + 8814147709738503518U) + aOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = (aWandererK + RotL64(aCross, 56U)) + 13451412605350381172U;
            aOrbiterC = (((aWandererJ + RotL64(aIngress, 21U)) + 6447870234069609538U) + aOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordF;
            aOrbiterA = (aWandererC + RotL64(aScatter, 3U)) + 13419487997946496825U;
            aOrbiterB = ((aWandererD + RotL64(aCross, 51U)) + RotL64(aCarry, 13U)) + 5478309847615220345U;
            aOrbiterG = (aWandererF + RotL64(aScatter, 29U)) + 3635184969215610049U;
            aOrbiterH = (aWandererI + RotL64(aPrevious, 5U)) + 12527903812035294828U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 1684685110885338814U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 12860354576326835090U;
            aOrbiterF = RotL64((aOrbiterF * 12743745087733307255U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 9081823570147481835U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 14369321778210049109U;
            aOrbiterD = RotL64((aOrbiterD * 17865953349448767035U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 11518132079084873250U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 11893535026126957389U) ^ aOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15751374986135615095U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 7084079180579206226U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 2999676609847603277U;
            aOrbiterB = RotL64((aOrbiterB * 14602698397511266403U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 17683445810614029153U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 11576460512964896969U;
            aOrbiterE = RotL64((aOrbiterE * 5243651036457051155U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 13429800604736567949U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 14661785761747367546U) ^ aNonceWordP;
            aOrbiterK = RotL64((aOrbiterK * 4765843989277333421U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 12837164345582888950U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 6222666313184669392U;
            aOrbiterH = RotL64((aOrbiterH * 17402483466567712319U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 5358647039491079457U) + aOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 12459911673401497180U;
            aOrbiterG = RotL64((aOrbiterG * 13605465035256188065U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 3333017644772803587U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 15501587702102554928U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4921693371641768339U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 8492287653837766613U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 3432736785678875404U;
            aOrbiterI = RotL64((aOrbiterI * 7326419883291516513U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 2841486107704281869U) + aNonceWordJ;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 13915875634607599122U;
            aOrbiterA = RotL64((aOrbiterA * 707861617246345083U), 53U);
            //
            aIngress = RotL64(aOrbiterF, 60U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterJ, 13U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + (RotL64(aOrbiterG, 21U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 53U));
            aIngress = aIngress + RotL64(aOrbiterI, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 5U) + aOrbiterE) + RotL64(aOrbiterI, 34U));
            aWandererF = aWandererF + (((RotL64(aScatter, 14U) + RotL64(aOrbiterI, 5U)) + aOrbiterF) + aWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 19U) + aOrbiterE) + RotL64(aOrbiterK, 43U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 53U) + aOrbiterE) + RotL64(aOrbiterC, 39U)) + RotL64(aCarry, 23U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 35U) + aOrbiterF) + RotL64(aOrbiterG, 24U)) + aWandererUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 47U) + aOrbiterA) + RotL64(aOrbiterB, 53U)) + aNonceWordH);
            aWandererE = aWandererE ^ ((RotL64(aCross, 26U) + RotL64(aOrbiterH, 11U)) + aOrbiterA);
            aWandererC = aWandererC + ((((RotL64(aIngress, 11U) + aOrbiterJ) + RotL64(aOrbiterG, 51U)) + RotL64(aCarry, 3U)) + aNonceWordM);
            aWandererB = aWandererB ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterH, 21U)) + aOrbiterE) + aNonceWordG);
            aWandererA = aWandererA + ((RotL64(aScatter, 37U) + RotL64(aOrbiterH, 41U)) + aOrbiterK);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterE, 13U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 48U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 37U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 41U));
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 60U));
            aCarry = aCarry + RotL64(aWandererD, 21U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 15098U)) & S_BLOCK1], 39U) ^ RotL64(mSource[((aIndex + 10984U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 12334U)) & S_BLOCK1], 50U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13032U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCarry, 4U) + RotL64(aPrevious, 47U)) + (RotL64(aIngress, 35U) ^ RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterB = (aWandererA + RotL64(aPrevious, 47U)) + 16189787374324972735U;
            aOrbiterK = ((aWandererD + RotL64(aCross, 12U)) + RotL64(aCarry, 29U)) + 17563763730956242224U;
            aOrbiterG = ((aWandererC + RotL64(aIngress, 35U)) + 10572803498593789385U) + aNonceWordH;
            aOrbiterC = (aWandererE + RotL64(aScatter, 57U)) + 7713105232072974166U;
            aOrbiterA = (aWandererI + RotL64(aPrevious, 3U)) + 10760839534772718139U;
            aOrbiterI = ((aWandererB + RotL64(aCross, 5U)) + 13397069448391230253U) + aNonceWordD;
            aOrbiterH = ((aWandererH + RotL64(aIngress, 53U)) + RotL64(aCarry, 3U)) + 4569255679998375682U;
            aOrbiterE = ((((aWandererF + RotL64(aScatter, 51U)) + RotL64(aCarry, 39U)) + 9888769350817876949U) + aOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordC;
            aOrbiterF = (aWandererG + RotL64(aCross, 41U)) + 11351796060878856300U;
            aOrbiterD = (aWandererJ + RotL64(aPrevious, 26U)) + 18153775071965707204U;
            aOrbiterJ = ((aWandererK + RotL64(aIngress, 43U)) + 1282846411145853435U) + aOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 16457743979262460660U) + aNonceWordG;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 173493260775251032U;
            aOrbiterG = RotL64((aOrbiterG * 4935807229040883505U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 3927345926316409630U) + aOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 5158769729850853623U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2446452358663812945U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 12331351600010165154U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 3940794200348684050U;
            aOrbiterC = RotL64((aOrbiterC * 13248997263062075043U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 11248514843822945425U) + aOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 1391497323278226522U;
            aOrbiterF = RotL64((aOrbiterF * 8376841806072565005U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 13265623528678787307U) + aNonceWordP;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 2802033745265647317U;
            aOrbiterA = RotL64((aOrbiterA * 3437626962562016147U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 6938444301018051844U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 1086544666755559028U;
            aOrbiterJ = RotL64((aOrbiterJ * 16039728388882079889U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 16156443117365816536U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 3619942859562697142U;
            aOrbiterE = RotL64((aOrbiterE * 7589346043159112151U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 17681848914912743292U) + aOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 8848238631758130416U;
            aOrbiterH = RotL64((aOrbiterH * 810402256099500607U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 6019192027793541890U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 16917288363166352778U;
            aOrbiterK = RotL64((aOrbiterK * 17673667086593738207U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 5598218150530046752U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 17285995539011279010U;
            aOrbiterB = RotL64((aOrbiterB * 15621233176885995065U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 12380627610747299268U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 16189787374324972735U;
            aOrbiterD = RotL64((aOrbiterD * 2144714828503219209U), 43U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterC, 11U);
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 13U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 23U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 5U));
            aIngress = aIngress + RotL64(aOrbiterA, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 53U) + aOrbiterJ) + RotL64(aOrbiterH, 37U)) + aWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterA, 35U)) + aOrbiterB) + aNonceWordI);
            aWandererC = aWandererC + (((RotL64(aIngress, 5U) + RotL64(aOrbiterJ, 4U)) + aOrbiterG) + aNonceWordF);
            aWandererF = aWandererF ^ (((RotL64(aCross, 58U) + aOrbiterI) + RotL64(aOrbiterH, 57U)) + aWandererUpdateSaltB[((aIndex + 12U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 23U) + aOrbiterE) + RotL64(aOrbiterC, 11U)) + RotL64(aCarry, 3U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 51U) + aOrbiterA) + RotL64(aOrbiterK, 41U));
            aWandererH = aWandererH + ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterD, 29U)) + aOrbiterF) + RotL64(aCarry, 41U)) + aNonceWordK);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 13U) + aOrbiterA) + RotL64(aOrbiterE, 19U)) + aNonceWordA);
            aWandererE = aWandererE + ((RotL64(aPrevious, 35U) + aOrbiterC) + RotL64(aOrbiterB, 27U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterE, 54U)) + aOrbiterF);
            aWandererK = aWandererK + ((RotL64(aIngress, 56U) + RotL64(aOrbiterG, 13U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererK, 48U) ^ aWandererB);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererD);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererE, 53U);
            aCarry = aCarry + RotL64(aIngress, 26U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 18996U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18378U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 17651U)) & S_BLOCK1], 4U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 20600U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 20030U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aPrevious, 19U) + RotL64(aCross, 42U)) ^ (RotL64(aCarry, 57U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterG = (aWandererF + RotL64(aCross, 43U)) + 12136097566601676613U;
            aOrbiterJ = (aWandererH + RotL64(aScatter, 27U)) + 7969431322248040056U;
            aOrbiterC = (aWandererG + RotL64(aIngress, 21U)) + 10530676021510553889U;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 3U)) + RotL64(aCarry, 57U)) + 8740777303075445264U;
            aOrbiterF = (((aWandererI + RotL64(aScatter, 6U)) + RotL64(aCarry, 19U)) + 13249434169895564739U) + aNonceWordG;
            aOrbiterK = (aWandererA + RotL64(aPrevious, 35U)) + 15529577005925628472U;
            aOrbiterB = (((aWandererE + RotL64(aCross, 23U)) + RotL64(aCarry, 13U)) + 344627093687331562U) + aOrbiterAssignSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 39U)) + 8824277416519988893U) + aOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = (aWandererD + RotL64(aScatter, 52U)) + 5636276438449709875U;
            aOrbiterA = ((aWandererB + RotL64(aCross, 37U)) + 2079413361031851552U) + aNonceWordA;
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 29U)) + 7807998179168655561U) + aNonceWordP;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 13589392896232029112U) + aNonceWordD;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 10733011474804473996U) ^ aOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 361749145931578805U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 15934162328347805968U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 7573511217796245232U) ^ aNonceWordM;
            aOrbiterJ = RotL64((aOrbiterJ * 10694563909931636155U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 4828475187337891975U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 13284974329890393113U;
            aOrbiterB = RotL64((aOrbiterB * 10831075817642374287U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 13173869918669643112U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 15841507674783398167U;
            aOrbiterG = RotL64((aOrbiterG * 15632933198136963277U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 14168272451055700516U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 11134471485501999898U;
            aOrbiterI = RotL64((aOrbiterI * 8019507184494591705U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 2611858916687822610U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 17863271539727513641U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4987884722174985677U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 8874401993454249066U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 5131480593493950665U) ^ aOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8585874663602346121U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 9366563022381918996U) + aNonceWordI;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 7890729519928340296U;
            aOrbiterH = RotL64((aOrbiterH * 11428572374057899517U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 131774386529223292U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 4108356674478240148U;
            aOrbiterE = RotL64((aOrbiterE * 2492753294539081613U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 7651738365157869789U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 2745458108574051004U;
            aOrbiterD = RotL64((aOrbiterD * 2175955806036373729U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 10492013124307434604U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 12136097566601676613U) ^ aNonceWordK;
            aOrbiterF = RotL64((aOrbiterF * 13128652803485742119U), 13U);
            //
            aIngress = RotL64(aOrbiterC, 13U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 5U));
            aIngress = aIngress + (RotL64(aOrbiterA, 53U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 24U));
            aIngress = aIngress + (RotL64(aOrbiterG, 35U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterJ, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aIngress, 43U) + RotL64(aOrbiterF, 53U)) + aOrbiterG) + RotL64(aCarry, 3U)) + aWandererUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 29U) + aOrbiterE) + RotL64(aOrbiterC, 41U)) + aWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aPrevious, 38U) + RotL64(aOrbiterH, 43U)) + aOrbiterK);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 27U) + aOrbiterE) + RotL64(aOrbiterF, 60U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterA, 39U)) + aOrbiterB) + aNonceWordH);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterC, 51U)) + aOrbiterF);
            aWandererF = aWandererF + ((((RotL64(aCross, 56U) + aOrbiterB) + RotL64(aOrbiterI, 57U)) + RotL64(aCarry, 57U)) + aNonceWordL);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterA, 5U)) + aOrbiterJ);
            aWandererI = aWandererI + (((RotL64(aCross, 35U) + RotL64(aOrbiterG, 13U)) + aOrbiterJ) + aNonceWordJ);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 41U) + aOrbiterB) + RotL64(aOrbiterD, 28U)) + aNonceWordN);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 11U) + aOrbiterH) + RotL64(aOrbiterE, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + (RotL64(aWandererC, 52U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + RotL64(aWandererH, 57U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 22398U)) & S_BLOCK1], 11U) ^ RotL64(mSource[((aIndex + 25484U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(pSnow[((aIndex + 25587U)) & S_BLOCK1], 50U) ^ RotL64(aWorkLaneA[((aIndex + 25668U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 21929U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneB[((aIndex + 27142U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCarry, 3U) ^ RotL64(aIngress, 53U)) + (RotL64(aPrevious, 40U) ^ RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterJ = ((((aWandererH + RotL64(aPrevious, 3U)) + RotL64(aCarry, 37U)) + 9855743441035905047U) + aOrbiterAssignSaltE[((aIndex + 7U)) & S_SALT1]) + aNonceWordD;
            aOrbiterB = ((aWandererC + RotL64(aIngress, 60U)) + RotL64(aCarry, 43U)) + 8426286937143990276U;
            aOrbiterF = (aWandererD + RotL64(aScatter, 23U)) + 7146752367170267002U;
            aOrbiterE = ((aWandererF + RotL64(aCross, 27U)) + 12947210066678101726U) + aNonceWordJ;
            aOrbiterA = ((aWandererI + RotL64(aIngress, 21U)) + 15902163559925328965U) + aOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = (aWandererK + RotL64(aPrevious, 35U)) + 8506649889346449469U;
            aOrbiterH = ((aWandererA + RotL64(aScatter, 48U)) + RotL64(aCarry, 5U)) + 8226286036430263052U;
            aOrbiterK = (aWandererE + RotL64(aCross, 29U)) + 2703047093452420216U;
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 43U)) + 6769351326360139560U;
            aOrbiterD = (aWandererG + RotL64(aCross, 53U)) + 9857025533281333281U;
            aOrbiterG = (aWandererB + RotL64(aIngress, 39U)) + 238297452132277585U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 7203572312072908931U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 12497027346166575632U;
            aOrbiterF = RotL64((aOrbiterF * 1703586436725662307U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 473851890609048879U) + aNonceWordP;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 1664484956453886047U;
            aOrbiterC = RotL64((aOrbiterC * 8566500756326590209U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 4635095143004754116U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 17695676150967345793U;
            aOrbiterJ = RotL64((aOrbiterJ * 5780416541584439301U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 15628965269863402796U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 9190117464399730235U;
            aOrbiterI = RotL64((aOrbiterI * 5586437438425999715U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 17835918238346011086U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 4398005402429282682U;
            aOrbiterA = RotL64((aOrbiterA * 14828737209913317463U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 10902589938246551273U) + aNonceWordB;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 15124274429081385923U;
            aOrbiterG = RotL64((aOrbiterG * 13524180348258805367U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 8747233520702236018U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 5445611443463112371U;
            aOrbiterD = RotL64((aOrbiterD * 10294109295823410447U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 16296005217836151910U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 6468336224317602364U) ^ aOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7369779919748367133U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 3827976387089403774U) + aOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 7773383658122100111U;
            aOrbiterE = RotL64((aOrbiterE * 9784711300597525161U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 18273794621528918389U) + aNonceWordI;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 8401424792700263455U;
            aOrbiterB = RotL64((aOrbiterB * 13003420427441089595U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 11402828934846813949U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 9855743441035905047U;
            aOrbiterH = RotL64((aOrbiterH * 7339549576423555273U), 3U);
            //
            aIngress = RotL64(aOrbiterD, 28U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterI, 51U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 41U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 39U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 21U));
            aIngress = aIngress + RotL64(aOrbiterA, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aCross, 6U) + aOrbiterK) + RotL64(aOrbiterD, 19U)) + aWandererUpdateSaltF[((aIndex + 14U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterF, 56U)) + aOrbiterE) + RotL64(aCarry, 51U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 11U) + aOrbiterB) + RotL64(aOrbiterJ, 3U));
            aWandererF = aWandererF + ((RotL64(aScatter, 35U) + aOrbiterA) + RotL64(aOrbiterJ, 5U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 21U) + aOrbiterC) + RotL64(aOrbiterI, 47U));
            aWandererD = aWandererD + (((RotL64(aScatter, 19U) + RotL64(aOrbiterI, 43U)) + aOrbiterH) + RotL64(aCarry, 11U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 37U) + aOrbiterA) + RotL64(aOrbiterK, 39U)) + aNonceWordK);
            aWandererC = aWandererC + (((RotL64(aIngress, 47U) + RotL64(aOrbiterF, 54U)) + aOrbiterG) + aNonceWordA);
            aWandererJ = aWandererJ ^ ((((RotL64(aPrevious, 30U) + aOrbiterG) + RotL64(aOrbiterA, 21U)) + aNonceWordL) + aWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 3U) + RotL64(aOrbiterK, 37U)) + aOrbiterB);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 41U) + aOrbiterI) + RotL64(aOrbiterF, 41U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 14U));
            aCarry = aCarry + (RotL64(aWandererD, 21U) ^ aWandererB);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererJ);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + RotL64(aWandererG, 5U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 31601U)) & S_BLOCK1], 5U) ^ RotL64(pSnow[((aIndex + 30005U)) & S_BLOCK1], 40U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 29316U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 28845U)) & S_BLOCK1], 29U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 32597U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 30861U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aPrevious, 54U) + RotL64(aCarry, 37U)) + (RotL64(aIngress, 21U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterH = (((aWandererB + RotL64(aIngress, 36U)) + RotL64(aCarry, 27U)) + 8367680518550579791U) + aOrbiterAssignSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterG = (aWandererE + RotL64(aCross, 11U)) + 11491674725611181241U;
            aOrbiterI = ((aWandererH + RotL64(aScatter, 57U)) + RotL64(aCarry, 39U)) + 16673861720782164214U;
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 27U)) + RotL64(aCarry, 5U)) + 9786610124108350855U;
            aOrbiterF = (aWandererC + RotL64(aScatter, 19U)) + 5745080601557577637U;
            aOrbiterK = ((aWandererF + RotL64(aIngress, 41U)) + 1959402215131684684U) + aNonceWordK;
            aOrbiterD = (aWandererJ + RotL64(aPrevious, 3U)) + 6121650036079196522U;
            aOrbiterC = (((aWandererG + RotL64(aCross, 60U)) + 12016309761037342392U) + aOrbiterAssignSaltB[((aIndex + 16U)) & S_SALT1]) + aNonceWordG;
            aOrbiterE = (aWandererD + RotL64(aIngress, 13U)) + 5986936646177049603U;
            aOrbiterJ = (aWandererK + RotL64(aCross, 23U)) + 1000367700904043468U;
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 51U)) + 17425288243569101032U) + aNonceWordN;
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 4856917474950325209U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 16312111093223166419U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11046477664487805241U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 456110002032422270U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 11393724374787795662U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1176984359123668389U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 8378176867715697176U) + aNonceWordH;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 8086186452345234815U) ^ aNonceWordC;
            aOrbiterC = RotL64((aOrbiterC * 8450438271765985235U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 8470349167474173245U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 2528229938740192694U;
            aOrbiterJ = RotL64((aOrbiterJ * 8717790851266520943U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 13247168811545753141U) + aNonceWordA;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 8745293957516815264U;
            aOrbiterD = RotL64((aOrbiterD * 14270617180621072619U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 6165915500564961987U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 12015407798844173213U;
            aOrbiterG = RotL64((aOrbiterG * 3913451986559154153U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 545006684939922156U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 16366753936267185001U;
            aOrbiterE = RotL64((aOrbiterE * 6495185976430013201U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 3097605623436091728U) + aOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 15950167830259022926U;
            aOrbiterA = RotL64((aOrbiterA * 4415538963984293323U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 8356327899232213426U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 10183421678251169945U;
            aOrbiterK = RotL64((aOrbiterK * 9474380650337109299U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 16327340177970834683U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 7086901180933495535U) ^ aNonceWordO;
            aOrbiterF = RotL64((aOrbiterF * 1276521829484494857U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 13421211370092080006U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 8367680518550579791U;
            aOrbiterB = RotL64((aOrbiterB * 12256662446176946163U), 47U);
            //
            aIngress = RotL64(aOrbiterK, 21U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 5U));
            aIngress = aIngress + (RotL64(aOrbiterG, 41U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterE, 24U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterI, 3U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterH, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aScatter, 35U) + RotL64(aOrbiterA, 11U)) + aOrbiterD) + RotL64(aCarry, 43U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterD, 13U)) + aOrbiterK) + aNonceWordE);
            aWandererD = aWandererD + (((RotL64(aIngress, 41U) + RotL64(aOrbiterG, 29U)) + aOrbiterB) + aWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterF, 40U)) + aOrbiterI) + aNonceWordF);
            aWandererK = aWandererK + (((RotL64(aCross, 11U) + aOrbiterA) + RotL64(aOrbiterJ, 47U)) + aWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 56U) + aOrbiterI) + RotL64(aOrbiterH, 3U)) + aNonceWordJ);
            aWandererC = aWandererC + ((RotL64(aScatter, 5U) + RotL64(aOrbiterK, 19U)) + aOrbiterE);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterF, 37U)) + aOrbiterB);
            aWandererI = aWandererI + (((RotL64(aCross, 37U) + aOrbiterA) + RotL64(aOrbiterH, 53U)) + RotL64(aCarry, 11U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 58U) + RotL64(aOrbiterH, 60U)) + aOrbiterC);
            aWandererE = aWandererE + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterE, 57U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 46U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 37U));
            aCarry = aCarry + (RotL64(aWandererB, 29U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererE, 39U);
            aCarry = aCarry + RotL64(aIngress, 14U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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

void TwistExpander_Soccer_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xFECF7185559F9F85ULL + 0xB249715FC014D08FULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xDAF399DB7561F6C5ULL + 0x87E5854103D9E2CCULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xE4F73905A2A780FBULL + 0x82A651ADD096D704ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xB91A1DD1DBD7F8B3ULL + 0xCC964A21AB281A9AULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x951A84FFAD78AB49ULL + 0xCB7117C12C791B32ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xC25A026A819F867FULL + 0x84662FD68895BF10ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xE0EFED193304C9A7ULL + 0xE34A0B350A06A89FULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xE4054086AB589FE5ULL + 0xBCC05D4A5ED367CBULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xE14A95B447970B03ULL + 0xEF5CDDD2E2E7B0ABULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xD627BDC93D54744BULL + 0xE87189E7DE691EBCULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x8799ACFB9563D459ULL + 0xA70A214EC4E63C69ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xDEC0375F349B3E19ULL + 0xBE4A725D5678D130ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xD33E76791D9211EBULL + 0xFAA3128701B0B68BULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xCD50CC6AFBD37F61ULL + 0xD464F8DB188AE1D7ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xA10A8DCD92BE4AEBULL + 0xC79B17E041ACF266ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xAC53AC97A97F648FULL + 0xAC502AD1F7CA018BULL);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 4865U)) & S_BLOCK1], 53U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 3492U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 2347U)) & S_BLOCK1], 35U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 4478U)) & S_BLOCK1], 10U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 6U) ^ RotL64(aPrevious, 19U)) + (RotL64(aIngress, 37U) ^ RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 18U)) + 8988572360732005217U) + aOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = ((aWandererB + RotL64(aScatter, 41U)) + 17889613225105985335U) + aNonceWordE;
            aOrbiterA = (((aWandererK + RotL64(aIngress, 53U)) + RotL64(aCarry, 47U)) + 15563478320513948626U) + aNonceWordB;
            aOrbiterG = (aWandererD + RotL64(aCross, 23U)) + 3441351228410524816U;
            aOrbiterC = (aWandererF + RotL64(aScatter, 57U)) + 4425592689451435346U;
            aOrbiterI = ((((aWandererI + RotL64(aPrevious, 28U)) + RotL64(aCarry, 29U)) + 12733160231627305928U) + aOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordH;
            aOrbiterJ = (aWandererH + RotL64(aCross, 3U)) + 3574152157304607854U;
            aOrbiterK = (aWandererJ + RotL64(aIngress, 11U)) + 15167631896729808783U;
            aOrbiterE = ((aWandererE + RotL64(aScatter, 35U)) + RotL64(aCarry, 13U)) + 15822667973915417055U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 17181685481076577637U) + aNonceWordM;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 9979204751408873468U;
            aOrbiterA = RotL64((aOrbiterA * 8244434774754786565U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 1334240485667164762U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 9190066751460137016U) ^ aOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14585141844653660363U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 15465215829109246336U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 2305208282453624419U;
            aOrbiterB = RotL64((aOrbiterB * 10257861974108363283U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 16951510027310993926U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 11117938943423526901U;
            aOrbiterG = RotL64((aOrbiterG * 7805486716716924787U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 12461379120662979432U) + aNonceWordP;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 11719697049048823897U;
            aOrbiterJ = RotL64((aOrbiterJ * 14880996802304818757U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 6843357278142933570U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 12727898578324702374U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9786435451654365097U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 18127999660067652233U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 11754709060558683082U;
            aOrbiterI = RotL64((aOrbiterI * 12798744012150745847U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 16940151146420516184U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 12924950783056761895U;
            aOrbiterK = RotL64((aOrbiterK * 8898170377271926745U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 14829713915929878471U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 840466047621042565U;
            aOrbiterE = RotL64((aOrbiterE * 10748511630509529489U), 47U);
            //
            aIngress = RotL64(aOrbiterI, 30U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 35U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 43U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 53U));
            aIngress = aIngress + RotL64(aOrbiterG, 24U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aCross, 39U) + RotL64(aOrbiterG, 39U)) + aOrbiterH) + aNonceWordL) + aWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 26U) + RotL64(aOrbiterK, 22U)) + aOrbiterA);
            aWandererF = aWandererF + (((RotL64(aIngress, 13U) + aOrbiterB) + RotL64(aOrbiterJ, 57U)) + aNonceWordJ);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 43U) + aOrbiterJ) + RotL64(aOrbiterK, 27U)) + aNonceWordN);
            aWandererI = aWandererI + ((((RotL64(aCross, 3U) + RotL64(aOrbiterG, 43U)) + aOrbiterK) + RotL64(aCarry, 57U)) + aNonceWordA);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 34U) + aOrbiterE) + RotL64(aOrbiterH, 35U));
            aWandererA = aWandererA + ((RotL64(aScatter, 47U) + aOrbiterC) + RotL64(aOrbiterE, 13U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 19U) + aOrbiterI) + RotL64(aOrbiterC, 53U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterI, 6U)) + aOrbiterG) + RotL64(aCarry, 35U)) + aWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererA);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 44U));
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererB, 35U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 8386U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneB[((aIndex + 14065U)) & S_BLOCK1], 38U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 10577U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 16088U)) & S_BLOCK1], 19U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 16090U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aIngress, 19U) ^ RotL64(aCross, 5U)) ^ (RotL64(aCarry, 44U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterB = ((aWandererB + RotL64(aCross, 19U)) + 6381335981879993247U) + aOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = ((aWandererK + RotL64(aScatter, 34U)) + 15595429101600023172U) + aNonceWordP;
            aOrbiterE = (aWandererH + RotL64(aIngress, 29U)) + 5449234297249826461U;
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 51U)) + RotL64(aCarry, 35U)) + 11213734849329731168U;
            aOrbiterJ = (aWandererI + RotL64(aScatter, 43U)) + 16438473952464514248U;
            aOrbiterK = (((aWandererG + RotL64(aCross, 57U)) + RotL64(aCarry, 43U)) + 7357872882115186976U) + aNonceWordF;
            aOrbiterC = (aWandererD + RotL64(aPrevious, 38U)) + 394402075160738643U;
            aOrbiterA = ((aWandererC + RotL64(aIngress, 13U)) + RotL64(aCarry, 27U)) + 11112941985410283532U;
            aOrbiterH = ((aWandererA + RotL64(aCross, 47U)) + 14955125011182736212U) + aOrbiterAssignSaltF[((aIndex + 26U)) & S_SALT1];
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 14770727009821304070U) + aNonceWordI;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 11286366598129204910U;
            aOrbiterE = RotL64((aOrbiterE * 15884310771003021989U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 7358400908565425780U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 15635109923749114761U;
            aOrbiterJ = RotL64((aOrbiterJ * 12415152149408700329U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 13826842523738623579U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 1072811298828325231U) ^ aOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9662800288646215083U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 4017334196009350776U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 8812213572751410831U) ^ aOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12744171921566782795U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 6723457786170634403U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 9785583533999417673U) ^ aOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7776915427605471097U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 10265132640322153964U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 8435670887514808087U;
            aOrbiterH = RotL64((aOrbiterH * 2706263045620662131U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 4303823386961718326U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 4214384238167491037U) ^ aNonceWordB;
            aOrbiterB = RotL64((aOrbiterB * 8490707334221154005U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 8740835037840799136U) + aNonceWordD;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 5988815405391206280U;
            aOrbiterI = RotL64((aOrbiterI * 17838555472135715929U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 15539461383052981747U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 3743772525784217714U;
            aOrbiterA = RotL64((aOrbiterA * 6352086797545969187U), 27U);
            //
            aIngress = RotL64(aOrbiterA, 37U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterJ, 48U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 19U));
            aIngress = aIngress + (RotL64(aOrbiterK, 27U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterB, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((((RotL64(aScatter, 60U) + RotL64(aOrbiterA, 23U)) + aOrbiterJ) + aNonceWordE) + aWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aPrevious, 23U) + aOrbiterC) + RotL64(aOrbiterB, 3U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 51U) + aOrbiterJ) + RotL64(aOrbiterC, 11U)) + aNonceWordM);
            aWandererC = aWandererC + (((RotL64(aCross, 13U) + aOrbiterC) + RotL64(aOrbiterH, 30U)) + aWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 5U) + aOrbiterE) + RotL64(aOrbiterJ, 53U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 30U) + RotL64(aOrbiterH, 41U)) + aOrbiterI) + RotL64(aCarry, 51U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 47U) + aOrbiterI) + RotL64(aOrbiterD, 19U)) + aNonceWordH);
            aWandererB = aWandererB + ((((RotL64(aCross, 35U) + aOrbiterA) + RotL64(aOrbiterH, 48U)) + RotL64(aCarry, 3U)) + aNonceWordA);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterJ, 57U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 14U));
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererA);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + RotL64(aWandererF, 11U);
            aCarry = aCarry + RotL64(aIngress, 20U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 21347U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneD[((aIndex + 19877U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 17012U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 19859U)) & S_BLOCK1], 60U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 19276U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 21039U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCross, 37U) + RotL64(aIngress, 51U)) ^ (RotL64(aCarry, 10U) ^ RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterH = (((aWandererF + RotL64(aPrevious, 51U)) + RotL64(aCarry, 21U)) + 966899917801652720U) + aOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = (aWandererI + RotL64(aCross, 6U)) + 10996327672320748649U;
            aOrbiterI = ((aWandererC + RotL64(aScatter, 21U)) + 4188171566846621107U) + aNonceWordA;
            aOrbiterD = ((aWandererK + RotL64(aIngress, 27U)) + RotL64(aCarry, 5U)) + 5886209243097387959U;
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 37U)) + RotL64(aCarry, 47U)) + 14940428957136728111U;
            aOrbiterJ = (aWandererH + RotL64(aPrevious, 47U)) + 179187285531914832U;
            aOrbiterF = ((aWandererE + RotL64(aCross, 11U)) + 6685351948936817752U) + aOrbiterAssignSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = (aWandererG + RotL64(aIngress, 43U)) + 1894506461704029700U;
            aOrbiterB = ((aWandererB + RotL64(aCross, 60U)) + 4182760368636977082U) + aNonceWordO;
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 12523318028514940790U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 5059306166973366892U;
            aOrbiterI = RotL64((aOrbiterI * 2857409765717296483U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 5890872367917643851U) + aNonceWordJ;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 17747338389865221534U;
            aOrbiterJ = RotL64((aOrbiterJ * 5306740664798049267U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 13906227834259884100U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 7152105382899756368U) ^ aOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6772157117358310485U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 17868101884759619240U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterJ) ^ 11758843266314148347U) ^ aOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterE = RotL64((aOrbiterE * 5919135169337501485U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 13950566197090324859U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 17278105609930477854U;
            aOrbiterF = RotL64((aOrbiterF * 11431842718945107359U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 9556785965646738355U) + aNonceWordI;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 841298436857932987U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15077843186688841797U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 1951515285492133830U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 15775839819330588437U;
            aOrbiterB = RotL64((aOrbiterB * 7902654031401620995U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 5585458468816495436U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 17258586689032223623U) ^ aNonceWordG;
            aOrbiterH = RotL64((aOrbiterH * 1652050227399194271U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 5254132659445988836U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 15440741734777060925U;
            aOrbiterG = RotL64((aOrbiterG * 17445581079035134067U), 43U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterK, 42U);
            aIngress = aIngress + (RotL64(aOrbiterH, 39U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 27U));
            aIngress = aIngress + (RotL64(aOrbiterI, 51U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterG, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((((RotL64(aIngress, 23U) + RotL64(aOrbiterF, 24U)) + aOrbiterD) + RotL64(aCarry, 35U)) + aNonceWordP) + aWandererUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 41U) + aOrbiterJ) + RotL64(aOrbiterD, 3U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 19U) + aOrbiterE) + RotL64(aOrbiterG, 57U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 48U) + aOrbiterH) + RotL64(aOrbiterK, 53U)) + aWandererUpdateSaltA[((aIndex + 10U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterI, 13U)) + aOrbiterH) + RotL64(aCarry, 23U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterJ, 19U)) + aOrbiterE);
            aWandererK = aWandererK + (((RotL64(aScatter, 13U) + aOrbiterB) + RotL64(aOrbiterJ, 48U)) + aNonceWordB);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 30U) + RotL64(aOrbiterE, 35U)) + aOrbiterI) + aNonceWordM);
            aWandererE = aWandererE + (((RotL64(aCross, 37U) + RotL64(aOrbiterJ, 39U)) + aOrbiterH) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 6U));
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererF);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + RotL64(aWandererJ, 53U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 27071U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneC[((aIndex + 29443U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 29502U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28570U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 32279U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 25254U)) & S_BLOCK1], 18U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 18U) + RotL64(aPrevious, 51U)) ^ (RotL64(aCross, 35U) ^ RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterJ = (((aWandererD + RotL64(aCross, 22U)) + RotL64(aCarry, 35U)) + 13442819395490639310U) + aNonceWordK;
            aOrbiterB = ((aWandererI + RotL64(aScatter, 39U)) + RotL64(aCarry, 3U)) + 8187292523194120936U;
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 43U)) + 11469697159823131388U) + aNonceWordF;
            aOrbiterC = (((aWandererF + RotL64(aIngress, 57U)) + RotL64(aCarry, 19U)) + 13414083692375929653U) + aOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = ((aWandererJ + RotL64(aCross, 5U)) + 11404010733687907517U) + aNonceWordH;
            aOrbiterE = ((aWandererH + RotL64(aIngress, 51U)) + 6783212827186218247U) + aNonceWordA;
            aOrbiterI = (aWandererG + RotL64(aScatter, 10U)) + 8561131439340372614U;
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 47U)) + 6252609642004429113U) + aOrbiterAssignSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = (aWandererC + RotL64(aCross, 27U)) + 12804867444200448952U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 2739648749603690781U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 14808861217017399752U) ^ aNonceWordC;
            aOrbiterA = RotL64((aOrbiterA * 373911885694012101U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 17588866502571268888U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 5882260142735642980U;
            aOrbiterF = RotL64((aOrbiterF * 7688252946143263869U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 15493099088132862949U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 5175647411532429582U;
            aOrbiterI = RotL64((aOrbiterI * 15226544495598541883U), 29U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterF) + 14279707376173642767U) + aOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1]) + aNonceWordP;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 6826363572161275158U;
            aOrbiterD = RotL64((aOrbiterD * 5263708315440161809U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 13267185753040999992U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 9980987858092888720U;
            aOrbiterB = RotL64((aOrbiterB * 13210290848800728635U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 3582972937645514549U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 10140409019562890804U;
            aOrbiterE = RotL64((aOrbiterE * 6944490201647678479U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 6160444117287330557U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 16344602960561293113U;
            aOrbiterH = RotL64((aOrbiterH * 2319964919335633293U), 23U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterJ) + 3497141036108337171U) + aOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1]) + aNonceWordB;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 91269118352540308U;
            aOrbiterC = RotL64((aOrbiterC * 5160060720189045505U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 12739932748793144857U) + aNonceWordI;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 12820180915064791197U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5843849637411948699U), 53U);
            //
            aIngress = RotL64(aOrbiterF, 43U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 39U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 47U));
            aIngress = aIngress + RotL64(aOrbiterI, 50U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 19U) + aOrbiterJ) + RotL64(aOrbiterC, 30U)) + aWandererUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aIngress, 23U) + RotL64(aOrbiterD, 43U)) + aOrbiterE);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 57U) + aOrbiterF) + RotL64(aOrbiterI, 13U));
            aWandererH = aWandererH + (((RotL64(aScatter, 12U) + RotL64(aOrbiterE, 5U)) + aOrbiterF) + aWandererUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterA, 47U)) + aOrbiterE) + aNonceWordD);
            aWandererG = aWandererG + (((RotL64(aIngress, 41U) + aOrbiterD) + RotL64(aOrbiterJ, 20U)) + RotL64(aCarry, 13U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 53U) + aOrbiterB) + RotL64(aOrbiterH, 35U)) + aNonceWordN);
            aWandererD = aWandererD + (((RotL64(aCross, 30U) + RotL64(aOrbiterC, 51U)) + aOrbiterH) + RotL64(aCarry, 37U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 5U) + aOrbiterB) + RotL64(aOrbiterI, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 60U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + (RotL64(aWandererD, 37U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererH, 23U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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

void TwistExpander_Soccer_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xC72155B4626810E9ULL + 0xD1A560FEDDF67083ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xEAA4835128AE9457ULL + 0xEDA3A6A5A8D011D0ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xCF69E6816DDC78B3ULL + 0xC39135BDFDB618B7ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xC5EC7D1778CAE463ULL + 0xD83E254E99AF4E7BULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x92FB618A73B6B659ULL + 0x8A308EAE991D5EBCULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xCF7565E379FA52F5ULL + 0xAE3F5CE9773B2033ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xE6900526011FC711ULL + 0x9DB6F707EFD7CACEULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xB92DB4B2CD855E75ULL + 0xD4EF672D65EF8276ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xF302580C1B6DCEB9ULL + 0xCDBE8CBDDE55E64DULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x88ABA2EA890629FBULL + 0xBC69CED062F5A4CDULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x81C55F7E01BA8B61ULL + 0xCF5CE7D43BA779BAULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xA9C79386089E7417ULL + 0xB93A8827E7DE5086ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x854D0F42317978E5ULL + 0xF3444D926E821A39ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xC75ADA7B21F28A9BULL + 0x9AF6ABFA1E5BC2E9ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x9BB62BCF1B88E39BULL + 0xC21B4D064B7538BFULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xFFBCCE1C0CECB9E1ULL + 0xAC30FB117F26F29FULL);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 5252U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneB[((aIndex + 669U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 862U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 2831U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 554U)) & S_BLOCK1], 38U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aPrevious, 24U)) ^ (RotL64(aCarry, 53U) + RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterF = ((aWandererC + RotL64(aScatter, 3U)) + 12131317914288566437U) + aNonceWordB;
            aOrbiterK = (aWandererD + RotL64(aPrevious, 51U)) + 5672805657999385496U;
            aOrbiterJ = ((((aWandererI + RotL64(aIngress, 13U)) + RotL64(aCarry, 23U)) + 3581710244233124197U) + aOrbiterAssignSaltF[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordG;
            aOrbiterI = ((aWandererJ + RotL64(aCross, 42U)) + RotL64(aCarry, 37U)) + 15251296040538489436U;
            aOrbiterD = ((((aWandererH + RotL64(aScatter, 23U)) + RotL64(aCarry, 5U)) + 11295008604679904153U) + aOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordM;
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 2230897493419504490U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 7109600123297458999U;
            aOrbiterJ = RotL64((aOrbiterJ * 8267799351136506307U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 13119156643107683803U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterK) ^ 14755160867807355250U) ^ aOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterI = RotL64((aOrbiterI * 10007087518844899239U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 16829363373287496832U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterJ) ^ 16981122946707720883U) ^ aOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterD = RotL64((aOrbiterD * 5394974422201576627U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 8806000776958603317U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 16810923047720876014U;
            aOrbiterF = RotL64((aOrbiterF * 17872735050219539145U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 8129657889554436328U) + aOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 8653100378491974463U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11395283153912468661U), 43U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterK, 3U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + RotL64(aOrbiterI, 26U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((((RotL64(aPrevious, 46U) + RotL64(aOrbiterD, 46U)) + aOrbiterJ) + RotL64(aCarry, 27U)) + aNonceWordI) + aWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 5U) + aOrbiterF) + RotL64(aOrbiterD, 37U)) + aNonceWordF);
            aWandererD = aWandererD + (((((RotL64(aIngress, 27U) + RotL64(aOrbiterD, 11U)) + aOrbiterK) + RotL64(aCarry, 47U)) + aNonceWordO) + aWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterI, 57U)) + aOrbiterF) + aNonceWordP);
            aWandererI = aWandererI + ((RotL64(aIngress, 13U) + aOrbiterI) + RotL64(aOrbiterK, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererC);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + RotL64(aWandererI, 35U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 16135U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneC[((aIndex + 9997U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 15041U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 10508U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 14286U)) & S_BLOCK1], 24U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 15980U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aPrevious, 4U) ^ RotL64(aCross, 53U)) + (RotL64(aCarry, 19U) ^ RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterK = (((aWandererB + RotL64(aIngress, 51U)) + 1866656689936219099U) + aOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1]) + aNonceWordM;
            aOrbiterH = ((aWandererK + RotL64(aCross, 43U)) + 2312314528139448289U) + aNonceWordC;
            aOrbiterE = (((aWandererJ + RotL64(aScatter, 5U)) + RotL64(aCarry, 39U)) + 3554037526469185237U) + aNonceWordA;
            aOrbiterB = (((aWandererI + RotL64(aPrevious, 60U)) + RotL64(aCarry, 21U)) + 405707755060974111U) + aNonceWordG;
            aOrbiterJ = (((aWandererG + RotL64(aIngress, 13U)) + RotL64(aCarry, 53U)) + 1862976326004007697U) + aOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1];
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 12992483065443288263U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 3793854946371595197U;
            aOrbiterE = RotL64((aOrbiterE * 1819119223110966487U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 4244007978867369382U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterE) ^ 10280867500312580308U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterH = RotL64((aOrbiterH * 13729899124177931289U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 472563452959164242U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterJ) ^ 12041770406895816553U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterK = RotL64((aOrbiterK * 17811798500132002631U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 6118634015704900486U) + aNonceWordH;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 13637107920449233307U;
            aOrbiterB = RotL64((aOrbiterB * 17712028184714868053U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 16673735670669318830U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 8602681273646630496U) ^ aOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6995213887710749241U), 11U);
            //
            aIngress = RotL64(aOrbiterE, 53U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterB, 28U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterJ, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aCross, 14U) + RotL64(aOrbiterJ, 12U)) + aOrbiterB) + RotL64(aCarry, 43U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 27U) + aOrbiterJ) + RotL64(aOrbiterH, 3U));
            aWandererI = aWandererI + ((((RotL64(aScatter, 3U) + aOrbiterE) + RotL64(aOrbiterB, 43U)) + RotL64(aCarry, 29U)) + aNonceWordE);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 35U) + aOrbiterJ) + RotL64(aOrbiterE, 29U)) + aWandererUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 47U) + aOrbiterK) + RotL64(aOrbiterB, 51U)) + aNonceWordJ) + aWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererK);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 29U));
            aCarry = aCarry + RotL64(aWandererJ, 13U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 21496U)) & S_BLOCK1], 50U) ^ RotL64(aOperationLaneD[((aIndex + 23527U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 21921U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20184U)) & S_BLOCK1], 38U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 23048U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aOperationLaneC[((aIndex + 22972U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 5U)) + (RotL64(aIngress, 19U) + RotL64(aCross, 38U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterG = (((aWandererE + RotL64(aScatter, 56U)) + RotL64(aCarry, 51U)) + 5721224134332887360U) + aNonceWordI;
            aOrbiterJ = ((((aWandererF + RotL64(aIngress, 21U)) + RotL64(aCarry, 11U)) + 6892749729775049095U) + aOrbiterAssignSaltB[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordP;
            aOrbiterD = (((aWandererI + RotL64(aPrevious, 43U)) + RotL64(aCarry, 37U)) + 3884839462099556836U) + aNonceWordM;
            aOrbiterI = (aWandererC + RotL64(aCross, 3U)) + 4365431706830216193U;
            aOrbiterF = ((aWandererK + RotL64(aIngress, 29U)) + 15501528746571578773U) + aOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 4505911326320650606U) + aOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 1865129050927879580U;
            aOrbiterD = RotL64((aOrbiterD * 9198152644404068721U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 2011737665969640369U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterI) ^ 611672935827062688U) ^ aOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterJ = RotL64((aOrbiterJ * 12873671551304596619U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 663547038310431047U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 5468932264754299556U;
            aOrbiterF = RotL64((aOrbiterF * 11968657455484578525U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 17920294117231191705U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 486058453837528110U;
            aOrbiterI = RotL64((aOrbiterI * 8851102552244026737U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 2789178451938129313U) + aNonceWordO;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 420772587981211184U;
            aOrbiterG = RotL64((aOrbiterG * 17402987842294006667U), 29U);
            //
            aIngress = RotL64(aOrbiterF, 28U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterI, 13U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterD, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((((RotL64(aCross, 21U) + aOrbiterG) + RotL64(aOrbiterF, 39U)) + RotL64(aCarry, 51U)) + aNonceWordB) + aWandererUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 43U) + aOrbiterF) + RotL64(aOrbiterI, 18U)) + aWandererUpdateSaltE[((aIndex + 16U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 6U) + RotL64(aOrbiterF, 5U)) + aOrbiterD) + RotL64(aCarry, 35U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 35U) + aOrbiterG) + RotL64(aOrbiterJ, 47U)) + aNonceWordE);
            aWandererE = aWandererE + ((RotL64(aCross, 53U) + aOrbiterJ) + RotL64(aOrbiterD, 57U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 51U));
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererE, 3U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 29020U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneA[((aIndex + 30617U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 29330U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28161U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 29916U)) & S_BLOCK1], 29U));
            aCross ^= (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 26350U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 29056U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aIngress, 60U) + RotL64(aCarry, 13U)) ^ (RotL64(aCross, 47U) + RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterB = (((aWandererF + RotL64(aCross, 13U)) + RotL64(aCarry, 29U)) + 13296600294247799698U) + aNonceWordF;
            aOrbiterI = ((aWandererI + RotL64(aIngress, 47U)) + 5818503518080877515U) + aNonceWordE;
            aOrbiterD = (((aWandererK + RotL64(aScatter, 35U)) + RotL64(aCarry, 51U)) + 6735784238734173597U) + aNonceWordN;
            aOrbiterJ = (((aWandererH + RotL64(aPrevious, 4U)) + 7368398209488856201U) + aOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1]) + aNonceWordP;
            aOrbiterA = (((aWandererD + RotL64(aIngress, 21U)) + RotL64(aCarry, 3U)) + 961734029066455638U) + aOrbiterAssignSaltA[((aIndex + 18U)) & S_SALT1];
            //
            aOrbiterB = (((aOrbiterB + aOrbiterI) + 797011946660892011U) + aOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1]) + aNonceWordA;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 12841876018396622350U) ^ aOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14056540056414153277U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 16213253970483895623U) + aNonceWordM;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 15186950557113470375U;
            aOrbiterA = RotL64((aOrbiterA * 4647470430467908107U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 5117930310827477341U) + aNonceWordK;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 12265429373166094162U;
            aOrbiterJ = RotL64((aOrbiterJ * 1522823535151532249U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 13920531346698601568U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 14695405206998211456U;
            aOrbiterB = RotL64((aOrbiterB * 13950964363414164279U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 7851960904825938443U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterA) ^ 9501511171732550190U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterI = RotL64((aOrbiterI * 5614164120361489613U), 57U);
            //
            aIngress = RotL64(aOrbiterI, 43U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterD, 53U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterB, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aIngress, 37U) + RotL64(aOrbiterB, 12U)) + aOrbiterA) + aNonceWordH);
            aWandererH = aWandererH + (((RotL64(aCross, 57U) + RotL64(aOrbiterI, 57U)) + aOrbiterB) + RotL64(aCarry, 51U));
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 19U) + aOrbiterJ) + RotL64(aOrbiterB, 3U)) + aNonceWordL) + aWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 4U) + RotL64(aOrbiterD, 23U)) + aOrbiterJ) + RotL64(aCarry, 35U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 47U) + aOrbiterI) + RotL64(aOrbiterD, 41U)) + aWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererD, 3U);
            aCarry = aCarry + RotL64(aIngress, 54U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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

void TwistExpander_Soccer_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xF3C41114123DAC67ULL + 0xF6E76432FC026853ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xE36966D295EB57A1ULL + 0x904E6B9B7CB51194ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x87EA567A670843FBULL + 0x800C488CCE06ED96ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xC2CED972BDB163A5ULL + 0xB163A43844504037ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x8995FECE195BB185ULL + 0x95A88C907FFF6EA4ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xF9591CE3205443C5ULL + 0x8115EC2C5127AB98ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xEF988787394964E3ULL + 0x9817286332AF69C6ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xC1E3D6DE08071013ULL + 0xC56AE77CF829DCB0ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xAD47D917AD48B12FULL + 0xB13F72EF31910863ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xF0DB4043129AAC4BULL + 0xC45238E6799BE035ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xDF0A6183C6EA2741ULL + 0xDB35C47207A913DEULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xB83C9E7B78A0EF0DULL + 0xE66A2B733CEB2882ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xCFAC7E9DFCBA000FULL + 0xE923B998E80ECA6AULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xF426AF2BEEB12041ULL + 0xFB696E9828B730F0ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xB64DF8E8FC97FDEFULL + 0xE369312D5E30CFF2ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xE9486C14A0A897C3ULL + 0xAD521CA8BF7F7C82ULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aOperationLaneD, aExpandLaneC, aExpandLaneD, aFireLaneA, aWorkLaneA, aFireLaneB, aFireLaneD, aWorkLaneB, aOperationLaneA, aOperationLaneC, aWorkLaneC, aOperationLaneB, aFireLaneC
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // kdf_a_loop_d loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aOperationLaneD
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aOperationLaneD forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aFireLaneA
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aFireLaneA backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 5993U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneB[((aIndex + 6403U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aOperationLaneD[((aIndex + 406U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2719U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 805U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 7937U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 38U)) ^ (RotL64(aIngress, 23U) + RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterB = (((aWandererC + RotL64(aCross, 13U)) + RotL64(aCarry, 53U)) + 9630214189402543339U) + aNonceWordD;
            aOrbiterF = ((aWandererH + RotL64(aScatter, 41U)) + 4072576573737526819U) + aNonceWordJ;
            aOrbiterH = (aWandererG + RotL64(aPrevious, 52U)) + 15994787452709618869U;
            aOrbiterJ = (((aWandererA + RotL64(aIngress, 35U)) + RotL64(aCarry, 11U)) + 6403240137132259482U) + aNonceWordG;
            aOrbiterK = ((aWandererK + RotL64(aCross, 21U)) + 10229266900170507720U) + aOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = (((aWandererD + RotL64(aScatter, 5U)) + RotL64(aCarry, 35U)) + 5025294577989748989U) + aOrbiterAssignSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 27U)) + 16696461238217956883U) + aNonceWordF;
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 9878318855341719119U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 16086635438116177346U;
            aOrbiterH = RotL64((aOrbiterH * 5585682357395705671U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 12295437783084203730U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 7681150419912842402U;
            aOrbiterB = RotL64((aOrbiterB * 7289497379725191451U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 2639104034287637448U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 12298170009332243573U;
            aOrbiterE = RotL64((aOrbiterE * 9397919591171238575U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 3485932317267669626U) + aNonceWordO;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 16569551670038752475U;
            aOrbiterJ = RotL64((aOrbiterJ * 8139802826402217631U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 4448490103784103954U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 14510534073046885941U) ^ aOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7777192047386438305U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 4286195398675733451U) + aNonceWordH;
            aOrbiterF = (((aOrbiterF ^ aOrbiterK) ^ 15790355933840266463U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterF = RotL64((aOrbiterF * 13342257823027075501U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 6362891510370156055U) + aOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 15121822034579983174U;
            aOrbiterK = RotL64((aOrbiterK * 7268045994574844937U), 35U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterE, 41U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + (RotL64(aOrbiterH, 30U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterJ, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterF, 51U)) + aOrbiterJ) + RotL64(aCarry, 51U)) + aNonceWordB);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 6U) + aOrbiterE) + RotL64(aOrbiterH, 13U)) + aNonceWordM);
            aWandererA = aWandererA + ((((RotL64(aCross, 51U) + RotL64(aOrbiterF, 3U)) + aOrbiterI) + RotL64(aCarry, 39U)) + aNonceWordC);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 19U) + aOrbiterB) + RotL64(aOrbiterJ, 60U));
            aWandererG = aWandererG + (((RotL64(aIngress, 29U) + aOrbiterF) + RotL64(aOrbiterB, 43U)) + aWandererUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterK, 21U)) + aOrbiterE) + aWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 13U) + aOrbiterE) + RotL64(aOrbiterJ, 27U)) + aNonceWordK);
            //
            aCarry = aCarry + (RotL64(aWandererD, 18U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 41U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererJ, 13U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 2
        // ingress from: aWorkLaneA, aExpandLaneC, aFireLaneB
        // ingress directions: aWorkLaneA forward forced, aExpandLaneC forward forced, aFireLaneB forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD, aFireLaneD
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward forced, aFireLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 12862U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneC[((aIndex + 16151U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 12201U)) & S_BLOCK1], 24U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 11124U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 10310U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 12071U)) & S_BLOCK1], 54U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCross, 13U) + RotL64(aIngress, 41U)) ^ (RotL64(aCarry, 29U) + RotL64(aPrevious, 60U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 51U)) + 4752759164691497960U) + aOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = ((aWandererH + RotL64(aCross, 21U)) + 12088872623537639782U) + aNonceWordF;
            aOrbiterI = ((aWandererI + RotL64(aScatter, 5U)) + RotL64(aCarry, 53U)) + 3734943577379734227U;
            aOrbiterE = (((aWandererK + RotL64(aIngress, 13U)) + RotL64(aCarry, 11U)) + 8854778183012444234U) + aOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = ((aWandererB + RotL64(aScatter, 42U)) + 16948373492893967275U) + aNonceWordO;
            aOrbiterF = (aWandererA + RotL64(aIngress, 29U)) + 7962415690046184385U;
            aOrbiterA = (((aWandererF + RotL64(aPrevious, 35U)) + RotL64(aCarry, 23U)) + 1872682375669714454U) + aNonceWordI;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 7776801806943853566U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 16665439117257230732U;
            aOrbiterI = RotL64((aOrbiterI * 6866375628213114965U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 11088186766134265676U) + aNonceWordE;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 10850237991780969350U) ^ aOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7547414856143095121U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 6464817712131305812U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 244557182884209844U) ^ aOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2394270354887582889U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 13261563971157415841U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 2323811103717827362U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11483723582415081925U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 12338803568475493422U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 2811342930111104982U;
            aOrbiterE = RotL64((aOrbiterE * 5020981755203607757U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 5554497011738996057U) + aOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 12712169745460598698U;
            aOrbiterG = RotL64((aOrbiterG * 1985586486150377769U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 17415058661427002973U) + aNonceWordP;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 9430421222715343818U) ^ aNonceWordJ;
            aOrbiterJ = RotL64((aOrbiterJ * 10321140659099470811U), 37U);
            //
            aIngress = RotL64(aOrbiterG, 13U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterC, 28U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 51U));
            aIngress = aIngress + RotL64(aOrbiterJ, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aScatter, 51U) + RotL64(aOrbiterE, 3U)) + aOrbiterI) + RotL64(aCarry, 47U)) + aNonceWordK);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 43U) + aOrbiterA) + RotL64(aOrbiterJ, 29U));
            aWandererH = aWandererH + ((((RotL64(aIngress, 20U) + aOrbiterE) + RotL64(aOrbiterA, 41U)) + aNonceWordB) + aWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 37U) + aOrbiterG) + RotL64(aOrbiterJ, 50U));
            aWandererI = aWandererI + (((RotL64(aIngress, 13U) + RotL64(aOrbiterI, 35U)) + aOrbiterJ) + RotL64(aCarry, 19U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterC, 57U)) + aOrbiterF) + aWandererUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 29U) + aOrbiterI) + RotL64(aOrbiterF, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererK, 34U) ^ aWandererI);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 13U));
            aCarry = aCarry + RotL64(aWandererA, 3U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 3
        // ingress from: aWorkLaneB, aExpandLaneD, aOperationLaneA
        // ingress directions: aWorkLaneB forward forced, aExpandLaneD forward forced, aOperationLaneA forward/backward random
        // cross from: aWorkLaneA, aExpandLaneB, aOperationLaneC
        // cross directions: aWorkLaneA backward forced, aExpandLaneB backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 17393U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneD[((aIndex + 19052U)) & S_BLOCK1], 60U));
            aIngress ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 21125U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20570U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 19937U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 19273U)) & S_BLOCK1], 54U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCarry, 38U)) ^ (RotL64(aIngress, 11U) + RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterH = (aWandererA + RotL64(aCross, 35U)) + 4634399531433127141U;
            aOrbiterK = (aWandererF + RotL64(aPrevious, 60U)) + 16961792729406903200U;
            aOrbiterF = ((aWandererH + RotL64(aScatter, 3U)) + 4105280732301137738U) + aNonceWordD;
            aOrbiterD = (((aWandererG + RotL64(aIngress, 29U)) + 15692013501147331191U) + aOrbiterAssignSaltD[((aIndex + 8U)) & S_SALT1]) + aNonceWordO;
            aOrbiterJ = ((aWandererK + RotL64(aCross, 11U)) + RotL64(aCarry, 3U)) + 1252216715968780587U;
            aOrbiterA = (((aWandererB + RotL64(aPrevious, 53U)) + RotL64(aCarry, 29U)) + 7958289043012473752U) + aOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 21U)) + RotL64(aCarry, 51U)) + 6611577301818896615U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 8506226754305949140U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 3648813120449403353U) ^ aNonceWordG;
            aOrbiterF = RotL64((aOrbiterF * 9521367946879238849U), 5U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterJ) + 5195245426245535735U) + aOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1]) + aNonceWordE;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 542948051600803051U;
            aOrbiterH = RotL64((aOrbiterH * 4631106308856448475U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 11974253551208964789U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 10596463592332655367U) ^ aOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10941161258815714641U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 12015129484061440159U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 8254944355710109060U;
            aOrbiterB = RotL64((aOrbiterB * 3233697992479357615U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 2754858806943915419U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 5007802002906662779U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15613733948331639723U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 6262190752136523216U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 10528977986487821428U) ^ aNonceWordL;
            aOrbiterK = RotL64((aOrbiterK * 1184258264034585525U), 11U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterB) + 8511097226098211854U) + aOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1]) + aNonceWordI;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 12091864735686692582U;
            aOrbiterA = RotL64((aOrbiterA * 6128140528141411237U), 19U);
            //
            aIngress = RotL64(aOrbiterF, 35U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterJ, 11U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterA, 43U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterK, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aScatter, 5U) + aOrbiterF) + RotL64(aOrbiterA, 57U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 19U) + aOrbiterD) + RotL64(aOrbiterA, 11U)) + RotL64(aCarry, 53U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 60U) + aOrbiterJ) + RotL64(aOrbiterA, 19U)) + aNonceWordC);
            aWandererB = aWandererB + (((((RotL64(aPrevious, 27U) + RotL64(aOrbiterJ, 35U)) + aOrbiterD) + RotL64(aCarry, 27U)) + aNonceWordK) + aWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 53U) + aOrbiterK) + RotL64(aOrbiterB, 29U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 13U) + RotL64(aOrbiterA, 44U)) + aOrbiterB);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 43U) + aOrbiterJ) + RotL64(aOrbiterH, 5U)) + aWandererUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 39U));
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererA, 34U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 4
        // ingress from: aWorkLaneC, aWorkLaneA, aOperationLaneB
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aOperationLaneB forward/backward random
        // cross from: aWorkLaneB, aExpandLaneC, aFireLaneC
        // cross directions: aWorkLaneB backward forced, aExpandLaneC backward forced, aFireLaneC backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 30767U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneA[((aIndex + 27111U)) & S_BLOCK1], 14U));
            aIngress ^= RotL64(aOperationLaneB[((aIndex + 26936U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30289U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 29555U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 25560U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCarry, 51U) + RotL64(aPrevious, 5U)) ^ (RotL64(aIngress, 21U) ^ RotL64(aCross, 38U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterK = ((aWandererG + RotL64(aIngress, 57U)) + RotL64(aCarry, 23U)) + 5131645209694953015U;
            aOrbiterC = ((aWandererK + RotL64(aCross, 43U)) + RotL64(aCarry, 5U)) + 12070391048835379854U;
            aOrbiterH = (aWandererD + RotL64(aScatter, 5U)) + 2604295836242338724U;
            aOrbiterE = ((((aWandererC + RotL64(aPrevious, 37U)) + RotL64(aCarry, 37U)) + 14042039029284001596U) + aOrbiterAssignSaltE[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordO;
            aOrbiterA = (((aWandererE + RotL64(aScatter, 19U)) + 8914654543854559327U) + aOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordK;
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 11U)) + 2185619407969359869U) + aNonceWordP;
            aOrbiterF = ((aWandererA + RotL64(aCross, 26U)) + 5187406295103352574U) + aNonceWordL;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 8022832481290871217U) + aNonceWordC;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 8783061916740573472U) ^ aOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3309891377744201773U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 10711028365596196301U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 13387065038269133571U) ^ aNonceWordM;
            aOrbiterA = RotL64((aOrbiterA * 12444578026365205255U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 11187001318931801582U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 14191473173276034019U;
            aOrbiterK = RotL64((aOrbiterK * 2491253922434756431U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 16207761776716426435U) + aNonceWordJ;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 9677408414452078760U;
            aOrbiterG = RotL64((aOrbiterG * 5487303383095129949U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 17812460332794370649U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 7736423148554132028U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15588733747232852555U), 27U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterG) + 17293203944059014763U) + aOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1]) + aNonceWordD;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 13487243633338010243U;
            aOrbiterF = RotL64((aOrbiterF * 9468688858740539095U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 15979293016815060755U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 17645215484691359547U;
            aOrbiterE = RotL64((aOrbiterE * 1449450767288733995U), 43U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterG, 51U);
            aIngress = aIngress + (RotL64(aOrbiterC, 30U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + RotL64(aOrbiterH, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((((RotL64(aScatter, 51U) + RotL64(aOrbiterC, 37U)) + aOrbiterH) + aNonceWordA) + aWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 29U) + aOrbiterG) + RotL64(aOrbiterF, 27U)) + RotL64(aCarry, 51U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 38U) + RotL64(aOrbiterK, 5U)) + aOrbiterC);
            aWandererD = aWandererD + ((((RotL64(aCross, 23U) + aOrbiterE) + RotL64(aOrbiterA, 13U)) + RotL64(aCarry, 19U)) + aWandererUpdateSaltC[((aIndex + 4U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 11U) + aOrbiterG) + RotL64(aOrbiterA, 21U)) + aNonceWordI);
            aWandererE = aWandererE + (((RotL64(aCross, 5U) + RotL64(aOrbiterG, 60U)) + aOrbiterH) + aNonceWordF);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 57U) + aOrbiterE) + RotL64(aOrbiterH, 43U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 12U));
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererI, 23U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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

void TwistExpander_Soccer_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterE = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xD5DF5BF31563CA25ULL + 0x8376EFCF4C423403ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xF87D2928861788FDULL + 0xB8D13B61BCB55763ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xB458B9466F3F72BFULL + 0xA7CD7D8207DE7DC4ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x8EE789F0E837C657ULL + 0xAE52E176210A577BULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xEE6D78FFF4B23CBDULL + 0xA68CA1E02330A585ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xAFA25F88883EA027ULL + 0xAD5932A5DBD4BBCCULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xA7A8154EF83D3869ULL + 0xEED60CF6DC93F3C2ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xDB075AE499828FE7ULL + 0xA644553A5DBDFDBEULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x811A54C08E386AB5ULL + 0xEA4E301319103834ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x97638CA2759318AFULL + 0xEEED2EA6FF0113D5ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x9E6FC47456F19FD5ULL + 0xCBBABFFB6AB7782FULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xA6F25EF3E2D7F817ULL + 0x9D6337AAC0FDFDF2ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xC64C20DC8CC6012FULL + 0xF901BF4408F761B0ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xDD229C0EB0BC847BULL + 0xC069C70E14C04F6FULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xC6CB166D8DC04641ULL + 0xE0C8BC199F89B645ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xB971086DEBB4BE4DULL + 0xDF92A890E5B1E21FULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aOperationLaneD, aWorkLaneC, aWorkLaneD, aOperationLaneB, aExpandLaneA, aFireLaneD, aFireLaneA, aExpandLaneB, aFireLaneC, aOperationLaneC, aExpandLaneC, aOperationLaneA, aFireLaneB
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 3018U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneB[((aIndex + 2110U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 4472U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 5543U)) & S_BLOCK1], 34U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 7184U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 4858U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCross, 6U)) + (RotL64(aPrevious, 43U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterC = (((aWandererE + RotL64(aCross, 21U)) + 3255291173184001106U) + aOrbiterAssignSaltF[((aIndex + 11U)) & S_SALT1]) + aNonceWordP;
            aOrbiterG = ((aWandererI + RotL64(aIngress, 6U)) + 15308468160116255528U) + aNonceWordD;
            aOrbiterI = (aWandererF + RotL64(aPrevious, 35U)) + 18186972408589866656U;
            aOrbiterF = (aWandererD + RotL64(aScatter, 53U)) + 4439324265978331914U;
            aOrbiterH = ((aWandererB + RotL64(aCross, 13U)) + RotL64(aCarry, 13U)) + 13099263173016322486U;
            aOrbiterA = (((aWandererJ + RotL64(aPrevious, 43U)) + RotL64(aCarry, 37U)) + 7041561081767500660U) + aOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = ((aWandererG + RotL64(aIngress, 27U)) + RotL64(aCarry, 51U)) + 6196422612687812971U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 7664260932541281413U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 17802347823020441056U) ^ aOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2220679459017369255U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 4253107484061190446U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 13799496534030645312U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9167675060053848207U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 14252892847595951926U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 5663527578664291422U;
            aOrbiterF = RotL64((aOrbiterF * 18314294235895182465U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 11148755959699137661U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 17036900929333594592U) ^ aOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16041243617369003291U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 2403828181385259549U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 17813580350434928194U;
            aOrbiterA = RotL64((aOrbiterA * 13666780980793857831U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 5623611126885414523U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 7293224381174846969U;
            aOrbiterG = RotL64((aOrbiterG * 7032561584670788117U), 5U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterF) + 10602620906929686163U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordO;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 18015916257203385982U) ^ aNonceWordK;
            aOrbiterE = RotL64((aOrbiterE * 10684090189688871993U), 11U);
            //
            aIngress = RotL64(aOrbiterF, 23U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 47U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 13U));
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aCross, 13U) + aOrbiterE) + RotL64(aOrbiterC, 29U)) + RotL64(aCarry, 57U)) + aNonceWordB);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 47U) + aOrbiterG) + RotL64(aOrbiterC, 21U));
            aWandererI = aWandererI + (((RotL64(aScatter, 23U) + RotL64(aOrbiterH, 54U)) + aOrbiterF) + RotL64(aCarry, 5U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterA, 3U)) + aOrbiterH);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 53U) + aOrbiterC) + RotL64(aOrbiterA, 11U)) + aNonceWordA) + aWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((((RotL64(aScatter, 3U) + RotL64(aOrbiterH, 35U)) + aOrbiterI) + aNonceWordF) + aWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aIngress, 60U) + RotL64(aOrbiterA, 43U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererF, 24U) ^ aWandererG);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + RotL64(aWandererD, 37U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aFireLaneD
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aFireLaneD forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aFireLaneA
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aFireLaneA backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 14509U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneC[((aIndex + 14933U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 12964U)) & S_BLOCK1], 60U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 10128U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 8520U)) & S_BLOCK1], 20U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 8546U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCarry, 41U) + RotL64(aIngress, 53U)) ^ (RotL64(aCross, 6U) + RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterA = ((aWandererK + RotL64(aScatter, 27U)) + 11177787645248006236U) + aNonceWordB;
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 35U)) + RotL64(aCarry, 35U)) + 3808340254579817169U;
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 14U)) + 828030667598518279U) + aNonceWordJ;
            aOrbiterI = (((aWandererI + RotL64(aCross, 41U)) + RotL64(aCarry, 53U)) + 16177835921238398371U) + aOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = ((aWandererG + RotL64(aPrevious, 21U)) + 5518747735458708741U) + aNonceWordC;
            aOrbiterB = (((aWandererB + RotL64(aScatter, 51U)) + RotL64(aCarry, 3U)) + 17346319082399995165U) + aNonceWordM;
            aOrbiterK = ((aWandererC + RotL64(aCross, 5U)) + 6397156921893030937U) + aOrbiterAssignSaltC[((aIndex + 18U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 15559381654710713582U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 940404446491415088U;
            aOrbiterF = RotL64((aOrbiterF * 16401260971303026881U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 8047166032048732645U) + aNonceWordF;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 4688468645859470491U;
            aOrbiterC = RotL64((aOrbiterC * 14383536431614496369U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 3710878044770337260U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 116343189456629220U) ^ aOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5637725064169289339U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 883908030159391659U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 18058691521694880482U;
            aOrbiterJ = RotL64((aOrbiterJ * 3132200449123497619U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 17521015077103586117U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 3668332225435714918U;
            aOrbiterK = RotL64((aOrbiterK * 12658899101297839881U), 53U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterI) + 12229480388278883300U) + aOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1]) + aNonceWordG;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 16206524049491531816U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11122340196620859805U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 5743265849441077466U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 2812293020719282236U) ^ aOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8903956475200417109U), 41U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterJ, 50U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 23U));
            aIngress = aIngress + (RotL64(aOrbiterF, 57U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterC, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterI, 29U)) + aOrbiterC) + aWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterB, 47U)) + aOrbiterF);
            aWandererD = aWandererD ^ ((((RotL64(aScatter, 5U) + RotL64(aOrbiterK, 40U)) + aOrbiterC) + aNonceWordE) + aWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 37U) + RotL64(aOrbiterA, 5U)) + aOrbiterJ) + RotL64(aCarry, 37U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterJ, 53U)) + aOrbiterB);
            aWandererK = aWandererK + (((RotL64(aScatter, 19U) + RotL64(aOrbiterK, 11U)) + aOrbiterI) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 44U) + aOrbiterC) + RotL64(aOrbiterJ, 21U)) + aNonceWordH);
            //
            aCarry = aCarry + (RotL64(aWandererD, 34U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererG, 21U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererK, 47U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 3
        // ingress from: aExpandLaneB, aWorkLaneD, aFireLaneC
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneA, aWorkLaneB, aOperationLaneC
        // cross directions: aExpandLaneA backward forced, aWorkLaneB backward forced, aOperationLaneC backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 20960U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneD[((aIndex + 22452U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 19607U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 17959U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21469U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aOperationLaneC[((aIndex + 23108U)) & S_BLOCK1], 6U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aPrevious, 27U)) + (RotL64(aIngress, 12U) + RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterA = (aWandererC + RotL64(aIngress, 3U)) + 12380376990224645149U;
            aOrbiterE = (((aWandererG + RotL64(aCross, 21U)) + RotL64(aCarry, 41U)) + 18296928500297384014U) + aNonceWordE;
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 11U)) + 3550626816361145100U) + aOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 47U)) + 2667792936946706027U) + aOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = (((aWandererA + RotL64(aIngress, 27U)) + RotL64(aCarry, 57U)) + 12020969779370926953U) + aNonceWordA;
            aOrbiterJ = (aWandererE + RotL64(aScatter, 40U)) + 737340727886903447U;
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 53U)) + RotL64(aCarry, 11U)) + 1681797651799760502U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 2956186342689489064U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 1876852870402977177U) ^ aNonceWordO;
            aOrbiterK = RotL64((aOrbiterK * 8875540081346621757U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 6433205819353555071U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 9065076854974222998U;
            aOrbiterG = RotL64((aOrbiterG * 5459675878087242021U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 3254410578766789992U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 2005081975473815576U;
            aOrbiterE = RotL64((aOrbiterE * 9947701153722014085U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 15992999234834560419U) + aNonceWordN;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 3458344156815120948U;
            aOrbiterA = RotL64((aOrbiterA * 1668460113964608051U), 51U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterG) + 17069783053664877727U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordL;
            aOrbiterC = (((aOrbiterC ^ aOrbiterF) ^ 1260234710193913099U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterC = RotL64((aOrbiterC * 4561226779897414381U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 3825186451876061335U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 2905344294992827535U;
            aOrbiterJ = RotL64((aOrbiterJ * 2469896090698580795U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 18141402347899180617U) + aOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 8760129857609925066U;
            aOrbiterF = RotL64((aOrbiterF * 2507999156108123047U), 11U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterF, 34U);
            aIngress = aIngress + (RotL64(aOrbiterC, 47U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterJ, 53U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterK, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aCross, 48U) + RotL64(aOrbiterK, 21U)) + aOrbiterG) + aWandererUpdateSaltE[((aIndex + 10U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterF, 43U)) + RotL64(aCarry, 41U));
            aWandererJ = aWandererJ ^ ((((RotL64(aIngress, 41U) + aOrbiterC) + RotL64(aOrbiterJ, 13U)) + aNonceWordP) + aWandererUpdateSaltD[((aIndex + 26U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 5U) + RotL64(aOrbiterE, 57U)) + aOrbiterK) + RotL64(aCarry, 27U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterA, 27U)) + aOrbiterE);
            aWandererE = aWandererE + (((RotL64(aScatter, 35U) + aOrbiterG) + RotL64(aOrbiterC, 3U)) + aNonceWordB);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 11U) + aOrbiterJ) + RotL64(aOrbiterE, 36U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 48U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererE);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + RotL64(aWandererH, 53U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aOperationLaneA
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aOperationLaneA forward/backward random
        // cross from: aExpandLaneB, aWorkLaneC, aFireLaneB
        // cross directions: aExpandLaneB backward forced, aWorkLaneC backward forced, aFireLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 28832U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneA[((aIndex + 26112U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 30007U)) & S_BLOCK1], 58U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30246U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 26060U)) & S_BLOCK1], 26U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 26549U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCarry, 21U) + RotL64(aPrevious, 56U)) + (RotL64(aCross, 5U) ^ RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 35U)) + 12690502671561165478U) + aNonceWordN;
            aOrbiterJ = (aWandererC + RotL64(aScatter, 21U)) + 17519943923428102801U;
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 43U)) + 10705515807975331385U) + aOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = ((aWandererK + RotL64(aCross, 5U)) + RotL64(aCarry, 19U)) + 16586447272278538179U;
            aOrbiterE = (((aWandererG + RotL64(aPrevious, 60U)) + RotL64(aCarry, 3U)) + 8006560996840971798U) + aOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = ((aWandererF + RotL64(aCross, 53U)) + 12928600185788857701U) + aNonceWordD;
            aOrbiterH = ((aWandererB + RotL64(aScatter, 13U)) + RotL64(aCarry, 51U)) + 14240723153798267172U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 8636219177994872072U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 7586790235186467512U) ^ aNonceWordH;
            aOrbiterK = RotL64((aOrbiterK * 15052686382507614169U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 1103807034179512424U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 7547526530239498693U;
            aOrbiterE = RotL64((aOrbiterE * 3360295583636013509U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 8380239679344786397U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 5690809173787433519U;
            aOrbiterJ = RotL64((aOrbiterJ * 5354724308093372953U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 8390902801141804609U) + aOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 3507306189192059486U;
            aOrbiterA = RotL64((aOrbiterA * 18336280496510253103U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 6190745292098482871U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 8065418693975056902U;
            aOrbiterC = RotL64((aOrbiterC * 6414621418430102589U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 12111755051718111803U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 7605877769709909297U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17525248694315944599U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 5969794501112646237U) + aOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 5127559299360591476U) ^ aNonceWordO;
            aOrbiterH = RotL64((aOrbiterH * 4521563633438853069U), 21U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterB, 58U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 35U));
            aIngress = aIngress + (RotL64(aOrbiterA, 21U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterC, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aPrevious, 21U) + aOrbiterJ) + RotL64(aOrbiterB, 13U)) + RotL64(aCarry, 29U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 47U) + aOrbiterB) + RotL64(aOrbiterE, 38U)) + aWandererUpdateSaltF[((aIndex + 18U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 60U) + aOrbiterC) + RotL64(aOrbiterH, 47U)) + aNonceWordJ);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 53U) + aOrbiterA) + RotL64(aOrbiterH, 53U)) + aNonceWordP);
            aWandererB = aWandererB + (((((RotL64(aCross, 27U) + RotL64(aOrbiterH, 19U)) + aOrbiterE) + RotL64(aCarry, 53U)) + aNonceWordF) + aWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 39U) + aOrbiterC) + RotL64(aOrbiterK, 29U));
            aWandererK = aWandererK + ((RotL64(aIngress, 11U) + RotL64(aOrbiterE, 3U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 56U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererD, 3U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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

void TwistExpander_Soccer_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xD7AA85D0BC0CB1DFULL + 0x806C2A99721003F2ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xE2DD9982F7698997ULL + 0xE1C80C9193334BA6ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xFC92FA788B85ACD3ULL + 0xDDEA191A1E2C1E0FULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xA29D29FC1C1F0283ULL + 0xFE3514E90A5E38BAULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xA1338FADA1A68EB7ULL + 0x9A9D97E65AB51C11ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xC81887CA2BD3186FULL + 0x8EDDEEF3A2782BB0ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x9D2FFCB16C5130B7ULL + 0xE032907DE0393308ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xFF020841A2F75FC9ULL + 0xEAFD86FCB456ACCEULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xFF12A864C857E905ULL + 0xE2EE90F64124F688ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x803ABAB840801697ULL + 0xDEF481C28863AA85ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xD82EB76B6494FD41ULL + 0x9931EA4ECFE42B7DULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xFB194D787A2EEAA3ULL + 0xE040E66C2DAEE2E6ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xFD97D514995983DBULL + 0xA8CF118231097F79ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xB99A70FD8BFB9C03ULL + 0xDDDFD40D7A842896ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x9C273B91DE609331ULL + 0xB1A280841B45F04FULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xD8328DECABEF3F83ULL + 0xE68BF1551D07ED88ULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aWorkLaneC, aExpandLaneC, aExpandLaneD, aFireLaneB, aOperationLaneA, aFireLaneA, aWorkLaneA, aOperationLaneB, aWorkLaneB, aFireLaneC, aOperationLaneC, aWorkLaneD, aFireLaneD
        // write to: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // kdf_b_loop_b loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aWorkLaneC
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aWorkLaneC forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aFireLaneB
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aFireLaneB backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 5013U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneB[((aIndex + 7266U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 7877U)) & S_BLOCK1], 4U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2429U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 12U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 3658U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 11U) ^ RotL64(aCross, 53U)) + (RotL64(aCarry, 26U) ^ RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterA = (aWandererE + RotL64(aCross, 27U)) + 12426357877879529292U;
            aOrbiterK = ((aWandererG + RotL64(aScatter, 39U)) + 12604900366173639176U) + aOrbiterAssignSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterB = ((aWandererK + RotL64(aIngress, 6U)) + RotL64(aCarry, 13U)) + 13511119007338929401U;
            aOrbiterC = (aWandererD + RotL64(aPrevious, 11U)) + 9878720081166788060U;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 19U)) + 15463195409806395076U) + aNonceWordE;
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 29U)) + 6407922778852833423U) + aNonceWordG;
            aOrbiterE = (aWandererF + RotL64(aCross, 37U)) + 7690427254160734016U;
            aOrbiterD = ((aWandererB + RotL64(aScatter, 54U)) + 18030974031722143619U) + aNonceWordK;
            aOrbiterI = (((aWandererA + RotL64(aPrevious, 23U)) + RotL64(aCarry, 27U)) + 17983938038322737041U) + aOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = ((aWandererC + RotL64(aCross, 43U)) + RotL64(aCarry, 3U)) + 16605512170117753884U;
            aOrbiterG = ((aWandererH + RotL64(aIngress, 13U)) + 681802273302348322U) + aNonceWordF;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 15550312921312083819U) + aNonceWordN;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 17824154101711884508U;
            aOrbiterB = RotL64((aOrbiterB * 7358612830654795357U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 1939207786756735430U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 3132864634777826569U;
            aOrbiterA = RotL64((aOrbiterA * 13606281919426730325U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 12822929773923954849U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 16576106045887115660U;
            aOrbiterD = RotL64((aOrbiterD * 16370914370769903051U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 2398825881649235260U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 13700821892926092479U;
            aOrbiterH = RotL64((aOrbiterH * 10830623703416956043U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 2439833784883391606U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 15870638514107637833U;
            aOrbiterI = RotL64((aOrbiterI * 3797380922767479287U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 9165457123134229670U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 8736642509192659417U) ^ aOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16219277537523484065U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 9232719746484835693U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 7826680628853322541U;
            aOrbiterG = RotL64((aOrbiterG * 12578050118133526187U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 14323652326982518782U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 2254524512851399313U;
            aOrbiterJ = RotL64((aOrbiterJ * 4119339547645451149U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 14459632243829356472U) + aNonceWordJ;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 8591197056749497716U) ^ aOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13053836520694721881U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 17220196418897000411U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterG) ^ 7186579019945992185U) ^ aOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterE = RotL64((aOrbiterE * 12406048515179065691U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 7554005180895698880U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 12426357877879529292U) ^ aNonceWordC;
            aOrbiterK = RotL64((aOrbiterK * 5090046967147694465U), 23U);
            //
            aIngress = RotL64(aOrbiterD, 34U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 3U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 41U));
            aIngress = aIngress + (RotL64(aOrbiterB, 47U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 37U));
            aIngress = aIngress + RotL64(aOrbiterG, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aIngress, 24U) + RotL64(aOrbiterH, 29U)) + aOrbiterF);
            aWandererD = aWandererD + (((RotL64(aCross, 41U) + RotL64(aOrbiterD, 36U)) + aOrbiterK) + aNonceWordP);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 39U) + aOrbiterG) + RotL64(aOrbiterA, 43U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 43U) + aOrbiterA) + RotL64(aOrbiterB, 13U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterE, 27U)) + aOrbiterD);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 11U) + RotL64(aOrbiterH, 58U)) + aOrbiterE) + RotL64(aCarry, 51U)) + aNonceWordB);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 47U) + aOrbiterH) + RotL64(aOrbiterI, 11U)) + aWandererUpdateSaltF[((aIndex + 20U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 29U) + aOrbiterF) + RotL64(aOrbiterC, 41U)) + RotL64(aCarry, 27U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterI, 39U)) + aOrbiterG);
            aWandererB = aWandererB + (((RotL64(aCross, 13U) + RotL64(aOrbiterA, 47U)) + aOrbiterJ) + aNonceWordA);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 34U) + aOrbiterC) + RotL64(aOrbiterI, 23U)) + aWandererUpdateSaltB[((aIndex + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 53U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 21U) ^ aWandererJ);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 51U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 10U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + RotL64(aWandererG, 13U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 2
        // ingress from: aOperationLaneA, aExpandLaneC, aFireLaneA
        // ingress directions: aOperationLaneA forward forced, aExpandLaneC forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD, aWorkLaneA
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward forced, aWorkLaneA backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 14081U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneC[((aIndex + 13051U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 11943U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 13027U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 13101U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11461U)) & S_BLOCK1], 10U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 52U) ^ RotL64(aCarry, 19U)) ^ (RotL64(aPrevious, 39U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterG = (aWandererE + RotL64(aCross, 13U)) + 12583180859826261500U;
            aOrbiterJ = (((aWandererB + RotL64(aScatter, 51U)) + RotL64(aCarry, 51U)) + 9067093488553721468U) + aNonceWordM;
            aOrbiterF = ((aWandererH + RotL64(aIngress, 42U)) + 12173106198862881754U) + aNonceWordN;
            aOrbiterK = (aWandererD + RotL64(aPrevious, 53U)) + 11333491014394592654U;
            aOrbiterA = (aWandererF + RotL64(aScatter, 57U)) + 3511883526940919554U;
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 35U)) + 7416810692106273044U) + aOrbiterAssignSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 5U)) + RotL64(aCarry, 39U)) + 8341174972619784110U;
            aOrbiterI = ((aWandererA + RotL64(aCross, 11U)) + RotL64(aCarry, 19U)) + 2220852854836962979U;
            aOrbiterB = (aWandererK + RotL64(aIngress, 24U)) + 8090781422229383825U;
            aOrbiterE = ((aWandererC + RotL64(aCross, 37U)) + 2338801236599102223U) + aOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = (aWandererG + RotL64(aPrevious, 39U)) + 12484514711848308104U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 13684861340589131816U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 12796636819991873058U;
            aOrbiterF = RotL64((aOrbiterF * 5533508014234835669U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 7634198650894837690U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 10240326122201201762U;
            aOrbiterD = RotL64((aOrbiterD * 8758703497719125901U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 4162814763739453934U) + aOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 2766504649149048469U;
            aOrbiterJ = RotL64((aOrbiterJ * 16731843453895178671U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 11051393030148769655U) + aNonceWordG;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 17687055068651386665U;
            aOrbiterB = RotL64((aOrbiterB * 1042927176246229537U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 3353615315436983420U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 5971640796220306310U;
            aOrbiterK = RotL64((aOrbiterK * 15804313508835034807U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 12299773092762384765U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 7435804907797063411U;
            aOrbiterC = RotL64((aOrbiterC * 9848139805288165965U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 8735783937125735699U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 11903126115475835615U) ^ aNonceWordO;
            aOrbiterH = RotL64((aOrbiterH * 16942088822124940265U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 4427166023462475475U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 6011733469446008137U) ^ aOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17298067225913923517U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 18341473946127677319U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 5423774915753911947U;
            aOrbiterA = RotL64((aOrbiterA * 14985099502923458523U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 2384393657884193014U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 2650593524388493958U;
            aOrbiterI = RotL64((aOrbiterI * 892985816665547945U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 15991261431384033176U) + aOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 12583180859826261500U;
            aOrbiterE = RotL64((aOrbiterE * 14394838775646875599U), 11U);
            //
            aIngress = RotL64(aOrbiterB, 39U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterG, 47U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterD, 44U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 41U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + RotL64(aOrbiterK, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aCross, 57U) + RotL64(aOrbiterH, 29U)) + aOrbiterF);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 41U) + aOrbiterA) + RotL64(aOrbiterD, 35U)) + aNonceWordJ);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 6U) + aOrbiterI) + RotL64(aOrbiterH, 11U)) + RotL64(aCarry, 51U)) + aWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 37U) + aOrbiterC) + RotL64(aOrbiterE, 53U));
            aWandererI = aWandererI + (((RotL64(aCross, 13U) + aOrbiterG) + RotL64(aOrbiterI, 43U)) + aNonceWordL);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 27U) + aOrbiterD) + RotL64(aOrbiterB, 40U));
            aWandererG = aWandererG + ((RotL64(aScatter, 3U) + RotL64(aOrbiterI, 19U)) + aOrbiterK);
            aWandererC = aWandererC ^ ((((RotL64(aPrevious, 19U) + aOrbiterC) + RotL64(aOrbiterD, 47U)) + aNonceWordI) + aWandererUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 21U) + aOrbiterA) + RotL64(aOrbiterG, 23U)) + RotL64(aCarry, 21U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 44U) + aOrbiterG) + RotL64(aOrbiterJ, 13U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 39U) + aOrbiterJ) + RotL64(aOrbiterC, 60U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 20U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererB, 13U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 3
        // ingress from: aOperationLaneB, aExpandLaneD, aWorkLaneB
        // ingress directions: aOperationLaneB forward forced, aExpandLaneD forward forced, aWorkLaneB forward/backward random
        // cross from: aOperationLaneA, aExpandLaneB, aFireLaneC
        // cross directions: aOperationLaneA backward forced, aExpandLaneB backward forced, aFireLaneC backward/forward random
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 17319U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((aIndex + 19249U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 18296U)) & S_BLOCK1], 22U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 22168U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 20212U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 18325U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCross, 11U)) ^ (RotL64(aCarry, 39U) + RotL64(aPrevious, 52U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterF = ((aWandererG + RotL64(aScatter, 57U)) + RotL64(aCarry, 29U)) + 18087125778766689269U;
            aOrbiterC = (((aWandererA + RotL64(aPrevious, 23U)) + RotL64(aCarry, 43U)) + 13710545066503235196U) + aNonceWordC;
            aOrbiterH = (((aWandererK + RotL64(aCross, 53U)) + RotL64(aCarry, 35U)) + 1701939704736254645U) + aNonceWordA;
            aOrbiterA = (aWandererE + RotL64(aIngress, 13U)) + 8064093611384019909U;
            aOrbiterE = ((aWandererD + RotL64(aScatter, 30U)) + 16623332751533885431U) + aOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = (aWandererC + RotL64(aIngress, 39U)) + 15590129153794910109U;
            aOrbiterG = (aWandererB + RotL64(aCross, 11U)) + 7413312683079107383U;
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 35U)) + 4186064478651458810U) + aNonceWordH;
            aOrbiterJ = (aWandererF + RotL64(aCross, 46U)) + 5501191643940735954U;
            aOrbiterB = (aWandererJ + RotL64(aScatter, 19U)) + 11064645242200570835U;
            aOrbiterD = ((aWandererI + RotL64(aIngress, 5U)) + 13825922087298055833U) + aOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 5944980709887369970U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 8181136916070569646U;
            aOrbiterH = RotL64((aOrbiterH * 395183021205661827U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 15442336949157292482U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 11580554435240641337U;
            aOrbiterE = RotL64((aOrbiterE * 6654637892858767739U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 11240018128174598322U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 2027565596050777471U;
            aOrbiterG = RotL64((aOrbiterG * 18048186560314431815U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 16425887196883725233U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 16828683527588834095U;
            aOrbiterJ = RotL64((aOrbiterJ * 17746289103235902485U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 9923829146479008804U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 6669171007279929454U) ^ aOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 681823450939955099U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 3902430046523165149U) + aNonceWordO;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 6739998149289590041U) ^ aOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2675037435528416821U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 16014401255534234075U) + aNonceWordK;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 14741857638680634564U) ^ aNonceWordF;
            aOrbiterK = RotL64((aOrbiterK * 8723611021403369393U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 5064807861673260054U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 968747317273200299U;
            aOrbiterC = RotL64((aOrbiterC * 14122304002722582329U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 5282686212362051427U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterB) ^ 6902253563196129760U) ^ aOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterF = RotL64((aOrbiterF * 7682808024658992049U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 4995580401402368332U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 14949762584793646470U;
            aOrbiterI = RotL64((aOrbiterI * 3539183342072953803U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 2378815735788107402U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 18087125778766689269U;
            aOrbiterD = RotL64((aOrbiterD * 16799380528404446281U), 39U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterJ, 60U);
            aIngress = aIngress + (RotL64(aOrbiterA, 41U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterF, 53U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterI, 13U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 5U));
            aIngress = aIngress + RotL64(aOrbiterB, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aIngress, 47U) + RotL64(aOrbiterE, 3U)) + aOrbiterC) + RotL64(aCarry, 37U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 20U) + RotL64(aOrbiterD, 19U)) + aOrbiterA);
            aWandererH = aWandererH + (((RotL64(aCross, 51U) + aOrbiterA) + RotL64(aOrbiterJ, 6U)) + aWandererUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterI, 29U)) + aOrbiterC);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 11U) + RotL64(aOrbiterK, 13U)) + aOrbiterJ) + aNonceWordB) + aWandererUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 22U) + RotL64(aOrbiterE, 11U)) + aOrbiterF) + aNonceWordE);
            aWandererA = aWandererA + ((RotL64(aScatter, 35U) + RotL64(aOrbiterK, 51U)) + aOrbiterH);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 29U) + aOrbiterA) + RotL64(aOrbiterC, 26U));
            aWandererI = aWandererI + (((RotL64(aCross, 39U) + RotL64(aOrbiterK, 41U)) + aOrbiterG) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterB, 23U)) + aOrbiterG);
            aWandererD = aWandererD + ((RotL64(aScatter, 5U) + RotL64(aOrbiterF, 37U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererD, 12U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 21U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 10U));
            aCarry = aCarry + RotL64(aWandererG, 53U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 26494U)) & S_BLOCK1], 46U) ^ RotL64(aOperationLaneA[((aIndex + 27988U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aWorkLaneD[((aIndex + 32196U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31149U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 24917U)) & S_BLOCK1], 44U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 26545U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCross, 5U)) ^ (RotL64(aCarry, 35U) ^ RotL64(aIngress, 52U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterD = (aWandererA + RotL64(aScatter, 23U)) + 11410829607777684449U;
            aOrbiterG = (aWandererH + RotL64(aIngress, 4U)) + 7502698839700975347U;
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 27U)) + 13267685058252106173U;
            aOrbiterA = ((aWandererK + RotL64(aCross, 51U)) + RotL64(aCarry, 53U)) + 238242706996630625U;
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 29U)) + 8184695499511454281U) + aNonceWordH;
            aOrbiterI = (aWandererI + RotL64(aCross, 47U)) + 12767823220461985403U;
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 37U)) + RotL64(aCarry, 27U)) + 12293198423143850330U;
            aOrbiterB = (((aWandererD + RotL64(aIngress, 43U)) + RotL64(aCarry, 47U)) + 11149495229952495939U) + aNonceWordF;
            aOrbiterK = ((aWandererF + RotL64(aScatter, 19U)) + 7556992689338382800U) + aOrbiterAssignSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = (aWandererB + RotL64(aIngress, 21U)) + 3431338808774134649U;
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 40U)) + 16863099140844995099U) + aOrbiterAssignSaltE[((aIndex + 22U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 17872458049880677604U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterD) ^ 16760153457252546974U) ^ aOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterJ = RotL64((aOrbiterJ * 11225037229069712805U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 3115544493537438408U) + aNonceWordG;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 4359882942759752958U;
            aOrbiterF = RotL64((aOrbiterF * 561477566995575801U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 13387113067202396536U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 12955690074544490161U;
            aOrbiterD = RotL64((aOrbiterD * 12449941770827974511U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 15614054443728226807U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 1939441328066616114U;
            aOrbiterI = RotL64((aOrbiterI * 4484917074808974359U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 4599016263007782537U) + aOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 9962305629016158048U;
            aOrbiterG = RotL64((aOrbiterG * 1496184427500037279U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 8428467674122750557U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 3938884087806393439U) ^ aOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12810531094050481761U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 6018636830758044658U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 1510372000641305416U;
            aOrbiterC = RotL64((aOrbiterC * 9002834928626918247U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 17592782466215337843U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 8119921507606870360U;
            aOrbiterE = RotL64((aOrbiterE * 1299795061644535485U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 8753237702359236964U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 12389957327067768090U;
            aOrbiterA = RotL64((aOrbiterA * 4586786761936601607U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 17791633199762408683U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 11606494383812053915U) ^ aOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13041480602055778521U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 4418614662439151979U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 11410829607777684449U;
            aOrbiterH = RotL64((aOrbiterH * 3342270212301058781U), 47U);
            //
            aIngress = RotL64(aOrbiterB, 60U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterH, 53U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 5U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 13U));
            aIngress = aIngress + RotL64(aOrbiterD, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aIngress, 38U) + RotL64(aOrbiterC, 10U)) + aOrbiterI) + RotL64(aCarry, 27U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterK, 13U)) + aOrbiterB);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterK, 51U)) + aOrbiterF);
            aWandererG = aWandererG ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterG, 23U)) + aOrbiterC);
            aWandererF = aWandererF + (((RotL64(aScatter, 11U) + RotL64(aOrbiterI, 57U)) + aOrbiterH) + aWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 13U) + aOrbiterJ) + RotL64(aOrbiterF, 3U)) + aNonceWordJ);
            aWandererA = aWandererA + (((RotL64(aIngress, 43U) + RotL64(aOrbiterE, 44U)) + aOrbiterD) + aNonceWordI);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterE, 19U)) + aOrbiterJ) + aWandererUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 51U) + aOrbiterG) + RotL64(aOrbiterD, 5U)) + RotL64(aCarry, 43U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterB, 21U)) + aOrbiterH) + aNonceWordA);
            aWandererD = aWandererD + (((RotL64(aPrevious, 58U) + RotL64(aOrbiterB, 53U)) + aOrbiterA) + aNonceWordO);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 38U));
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 23U));
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererA, 29U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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

void TwistExpander_Soccer_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xDC573FB4967AB1D5ULL + 0xFE719C1805726396ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xBC91D1D21076C68DULL + 0xD00824189EFE5E95ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xD74BEB4AD2B94D51ULL + 0x8B11225631148496ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x9C372DD9160C5BDBULL + 0xC4F595316BDBA125ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xABAE255AC68AD6A7ULL + 0x8021858B4BCEABA7ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xE9035D22E599CB93ULL + 0xDA559BBF6ACF1946ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xF7994B5F3A99E131ULL + 0xA39EA90D1142E217ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xF3F2F22D3050AAB7ULL + 0xFEB23F2E24D06E93ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xAFE5AD08FF07C16FULL + 0xD7AC53C3EDE53046ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x8217C5A4B24F45CDULL + 0xA4FD0EA1E6A19E44ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x8A1AA49948E7591FULL + 0xF76E36D3145BDF00ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xEF9F4995EC2476FFULL + 0xAB726140806E2FFBULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xC6B3E24FDFBDC57DULL + 0xE1D00ACE3C733E5AULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xF04596C760A41F37ULL + 0xE5533392C55B73A8ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xF629CE5CA270CA33ULL + 0xE69800BCEDD0422AULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xE078D36D14118753ULL + 0xAE31E920F1E828F6ULL);
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
        // read from: aOperationLaneA, aOperationLaneB, aWorkLaneC, aOperationLaneC, aOperationLaneD, aFireLaneC, aExpandLaneA, aFireLaneD, aWorkLaneB, aExpandLaneB, aFireLaneA, aWorkLaneD, aExpandLaneC, aFireLaneB, aWorkLaneA
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aWorkLaneC
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aWorkLaneC forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aFireLaneC
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aFireLaneC backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 7012U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneB[((aIndex + 571U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 1276U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 6601U)) & S_BLOCK1], 22U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 6232U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 4905U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aPrevious, 51U)) + (RotL64(aCross, 19U) ^ RotL64(aIngress, 6U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterA = (((aWandererA + RotL64(aCross, 10U)) + 4848316479321533394U) + aOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordN;
            aOrbiterK = (aWandererJ + RotL64(aIngress, 47U)) + 6919360256662636195U;
            aOrbiterE = (aWandererK + RotL64(aPrevious, 23U)) + 9897013582181108544U;
            aOrbiterF = ((aWandererF + RotL64(aScatter, 41U)) + RotL64(aCarry, 35U)) + 7319353809896158678U;
            aOrbiterJ = (((aWandererD + RotL64(aIngress, 34U)) + 2848175435514849859U) + aOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1]) + aNonceWordE;
            aOrbiterG = (aWandererC + RotL64(aScatter, 19U)) + 6967780718720437934U;
            aOrbiterC = ((aWandererI + RotL64(aCross, 5U)) + RotL64(aCarry, 5U)) + 10143884766603388136U;
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 57U)) + RotL64(aCarry, 47U)) + 8675965006150972051U;
            aOrbiterI = (aWandererE + RotL64(aScatter, 27U)) + 16350117755560994281U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 17976597517118423760U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 1399631141355370237U) ^ aNonceWordM;
            aOrbiterE = RotL64((aOrbiterE * 16537788276543236833U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 3590613762034716792U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 5134624314245932157U;
            aOrbiterK = RotL64((aOrbiterK * 13077589037975283371U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 10082236952942943654U) + aOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 4015535035905433450U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4961808568701908559U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 611474103801573800U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 5786708483794098001U;
            aOrbiterB = RotL64((aOrbiterB * 7694007039340089267U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 5201943497363274455U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 9282160506938328489U) ^ aOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5368182164239021367U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 4932320527498940158U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 11576526341731392916U;
            aOrbiterJ = RotL64((aOrbiterJ * 1712051774729439363U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 10790691517638887125U) + aNonceWordA;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 16280649213607464422U;
            aOrbiterF = RotL64((aOrbiterF * 10756733801499471873U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 9553716940667712810U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 11827518270964003341U;
            aOrbiterG = RotL64((aOrbiterG * 1322489827908132831U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 16777463701235809321U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 3375489084588454149U) ^ aOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3335010977457647307U), 27U);
            //
            aIngress = RotL64(aOrbiterB, 23U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + (RotL64(aOrbiterG, 38U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 53U));
            aIngress = aIngress + RotL64(aOrbiterK, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aCross, 3U) + aOrbiterJ) + RotL64(aOrbiterF, 57U)) + aNonceWordF);
            aWandererA = aWandererA + ((RotL64(aIngress, 18U) + RotL64(aOrbiterC, 53U)) + aOrbiterK);
            aWandererE = aWandererE ^ ((((RotL64(aScatter, 57U) + aOrbiterB) + RotL64(aOrbiterC, 18U)) + aNonceWordC) + aWandererUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 23U) + aOrbiterG) + RotL64(aOrbiterJ, 47U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterK, 35U)) + aOrbiterG) + aWandererUpdateSaltB[((aIndex + 18U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 51U) + RotL64(aOrbiterF, 5U)) + aOrbiterK) + RotL64(aCarry, 23U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 14U) + RotL64(aOrbiterE, 24U)) + aOrbiterG);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterJ, 13U)) + aOrbiterA) + RotL64(aCarry, 13U)) + aNonceWordD);
            aWandererC = aWandererC ^ (((RotL64(aCross, 43U) + aOrbiterK) + RotL64(aOrbiterI, 29U)) + aNonceWordJ);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 50U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 21U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + RotL64(aWandererA, 5U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 2
        // ingress from: aExpandLaneA, aOperationLaneC, aFireLaneD
        // ingress directions: aExpandLaneA forward forced, aOperationLaneC forward forced, aFireLaneD forward/backward random
        // cross from: aOperationLaneA, aOperationLaneD, aWorkLaneB
        // cross directions: aOperationLaneA backward forced, aOperationLaneD backward forced, aWorkLaneB backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 9251U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneC[((aIndex + 15513U)) & S_BLOCK1], 48U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 14210U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 8234U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 14915U)) & S_BLOCK1], 38U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 10067U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCarry, 3U) + RotL64(aPrevious, 54U)) ^ (RotL64(aIngress, 39U) ^ RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterI = (aWandererH + RotL64(aIngress, 37U)) + 1708250618750199233U;
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 46U)) + 12009147777553691142U) + aNonceWordG;
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 53U)) + RotL64(aCarry, 3U)) + 8393982703399156592U;
            aOrbiterK = (((aWandererK + RotL64(aCross, 57U)) + RotL64(aCarry, 37U)) + 3247327098356831221U) + aOrbiterAssignSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 41U)) + 3403590155376353737U) + aNonceWordE;
            aOrbiterH = (aWandererD + RotL64(aIngress, 27U)) + 18197244558104735044U;
            aOrbiterB = ((aWandererB + RotL64(aCross, 13U)) + 3096253642040701606U) + aOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = ((aWandererF + RotL64(aScatter, 5U)) + RotL64(aCarry, 13U)) + 8012692688785412179U;
            aOrbiterG = (aWandererI + RotL64(aPrevious, 20U)) + 17531946907545680745U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 17687695944270225817U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 16147773866007628769U;
            aOrbiterJ = RotL64((aOrbiterJ * 16926442582711557877U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 18244641303026196497U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 8839160526348897457U;
            aOrbiterH = RotL64((aOrbiterH * 14268021129087663397U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 10599266240854068246U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 2056723540756216155U;
            aOrbiterA = RotL64((aOrbiterA * 13311591601230386375U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 4629354220460621284U) + aOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 9505955649473204942U;
            aOrbiterB = RotL64((aOrbiterB * 17775391885312236187U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 17078153810088721310U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 9470436761716263000U;
            aOrbiterK = RotL64((aOrbiterK * 5431855497250357229U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 3305863413630104742U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 14377172434239576161U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6880176890091033423U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 415687827894226513U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 16975319836893760993U;
            aOrbiterG = RotL64((aOrbiterG * 6597144958013976445U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 12707054129431596074U) + aNonceWordL;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 8974182792497231239U) ^ aOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7874658957269462717U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 10826131924322955095U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 4168545139712703154U) ^ aNonceWordF;
            aOrbiterF = RotL64((aOrbiterF * 10305904857550051705U), 13U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterJ, 5U);
            aIngress = aIngress + (RotL64(aOrbiterB, 37U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 21U));
            aIngress = aIngress + RotL64(aOrbiterG, 14U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aScatter, 35U) + aOrbiterG) + RotL64(aOrbiterF, 35U));
            aWandererD = aWandererD ^ ((((RotL64(aIngress, 12U) + aOrbiterJ) + RotL64(aOrbiterH, 6U)) + aNonceWordM) + aWandererUpdateSaltE[((aIndex + 28U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 39U) + aOrbiterB) + RotL64(aOrbiterC, 43U)) + RotL64(aCarry, 51U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterK, 39U)) + aOrbiterH) + aNonceWordI);
            aWandererI = aWandererI + ((RotL64(aIngress, 57U) + aOrbiterB) + RotL64(aOrbiterG, 11U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 5U) + aOrbiterA) + RotL64(aOrbiterB, 21U)) + aNonceWordJ);
            aWandererA = aWandererA + (((RotL64(aCross, 44U) + aOrbiterK) + RotL64(aOrbiterC, 28U)) + RotL64(aCarry, 39U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 21U) + aOrbiterI) + RotL64(aOrbiterA, 53U)) + aNonceWordA);
            aWandererC = aWandererC + (((RotL64(aIngress, 51U) + RotL64(aOrbiterA, 57U)) + aOrbiterG) + aWandererUpdateSaltD[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 14U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererF);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + (RotL64(aWandererD, 37U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererK, 40U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 3
        // ingress from: aExpandLaneB, aOperationLaneD, aFireLaneA
        // ingress directions: aExpandLaneB forward forced, aOperationLaneD forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneA, aOperationLaneB, aWorkLaneD
        // cross directions: aExpandLaneA backward forced, aOperationLaneB backward forced, aWorkLaneD backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 19464U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneD[((aIndex + 21480U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 18116U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23255U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 17101U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 16935U)) & S_BLOCK1], 46U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aPrevious, 11U) + RotL64(aCarry, 57U)) ^ (RotL64(aCross, 30U) ^ RotL64(aIngress, 43U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterD = ((aWandererA + RotL64(aCross, 18U)) + RotL64(aCarry, 53U)) + 13915875634607599122U;
            aOrbiterH = ((aWandererE + RotL64(aScatter, 47U)) + RotL64(aCarry, 39U)) + 1695770381382411673U;
            aOrbiterI = (aWandererC + RotL64(aIngress, 3U)) + 3709105579778295511U;
            aOrbiterE = ((((aWandererK + RotL64(aPrevious, 23U)) + RotL64(aCarry, 13U)) + 7673376335333251804U) + aOrbiterAssignSaltC[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordN;
            aOrbiterJ = (aWandererF + RotL64(aScatter, 30U)) + 8814147709738503518U;
            aOrbiterB = (aWandererJ + RotL64(aIngress, 11U)) + 13451412605350381172U;
            aOrbiterA = (aWandererB + RotL64(aPrevious, 51U)) + 6447870234069609538U;
            aOrbiterK = ((aWandererD + RotL64(aCross, 57U)) + 13419487997946496825U) + aNonceWordB;
            aOrbiterG = ((aWandererG + RotL64(aPrevious, 37U)) + 5478309847615220345U) + aOrbiterAssignSaltA[((aIndex + 8U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 3635184969215610049U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 12527903812035294828U) ^ aOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12540800512035534967U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 1684685110885338814U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 12860354576326835090U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12743745087733307255U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 9081823570147481835U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 14369321778210049109U;
            aOrbiterA = RotL64((aOrbiterA * 17865953349448767035U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 11518132079084873250U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 11893535026126957389U) ^ aNonceWordE;
            aOrbiterH = RotL64((aOrbiterH * 15751374986135615095U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 7084079180579206226U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 2999676609847603277U;
            aOrbiterE = RotL64((aOrbiterE * 14602698397511266403U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 17683445810614029153U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 11576460512964896969U;
            aOrbiterG = RotL64((aOrbiterG * 5243651036457051155U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 13429800604736567949U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 14661785761747367546U) ^ aNonceWordM;
            aOrbiterK = RotL64((aOrbiterK * 4765843989277333421U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 12837164345582888950U) + aNonceWordK;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 6222666313184669392U;
            aOrbiterD = RotL64((aOrbiterD * 17402483466567712319U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 5358647039491079457U) + aNonceWordC;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 12459911673401497180U;
            aOrbiterB = RotL64((aOrbiterB * 13605465035256188065U), 39U);
            //
            aIngress = RotL64(aOrbiterA, 39U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 5U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 52U));
            aIngress = aIngress + (RotL64(aOrbiterH, 27U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterG, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aScatter, 34U) + aOrbiterH) + RotL64(aOrbiterA, 19U));
            aWandererA = aWandererA + ((RotL64(aCross, 13U) + aOrbiterB) + RotL64(aOrbiterG, 52U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterE, 27U)) + aOrbiterI);
            aWandererC = aWandererC + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterH, 41U)) + aOrbiterG) + RotL64(aCarry, 27U));
            aWandererJ = aWandererJ ^ ((((RotL64(aCross, 27U) + RotL64(aOrbiterI, 35U)) + aOrbiterD) + aNonceWordH) + aWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aIngress, 60U) + RotL64(aOrbiterJ, 11U)) + aOrbiterB) + aNonceWordP) + aWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterH, 57U)) + aOrbiterK);
            aWandererG = aWandererG + ((((RotL64(aScatter, 43U) + RotL64(aOrbiterJ, 47U)) + aOrbiterK) + RotL64(aCarry, 19U)) + aNonceWordD);
            aWandererK = aWandererK ^ ((RotL64(aCross, 47U) + aOrbiterB) + RotL64(aOrbiterE, 6U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 58U));
            aCarry = aCarry + (RotL64(aWandererE, 41U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 5U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + RotL64(aWandererF, 47U);
            aCarry = aCarry + RotL64(aIngress, 14U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aFireLaneB
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aFireLaneB forward/backward random
        // cross from: aExpandLaneB, aOperationLaneC, aWorkLaneA
        // cross directions: aExpandLaneB backward forced, aOperationLaneC backward forced, aWorkLaneA backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 27406U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((aIndex + 30698U)) & S_BLOCK1], 38U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 32053U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29190U)) & S_BLOCK1], 34U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 28622U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 30726U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCarry, 19U) ^ RotL64(aIngress, 34U)) + (RotL64(aCross, 53U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterB = (((aWandererE + RotL64(aCross, 57U)) + 898812731947995389U) + aOrbiterAssignSaltB[((aIndex + 27U)) & S_SALT1]) + aNonceWordE;
            aOrbiterE = ((aWandererK + RotL64(aIngress, 47U)) + 8677347622525527167U) + aNonceWordF;
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 28U)) + RotL64(aCarry, 11U)) + 770321564027567654U;
            aOrbiterG = (aWandererD + RotL64(aScatter, 13U)) + 11020474858081526395U;
            aOrbiterH = (aWandererJ + RotL64(aIngress, 3U)) + 17289793580414993470U;
            aOrbiterC = ((aWandererG + RotL64(aScatter, 37U)) + RotL64(aCarry, 57U)) + 10111912559295118444U;
            aOrbiterD = ((aWandererC + RotL64(aCross, 51U)) + RotL64(aCarry, 37U)) + 8083622125544542011U;
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 23U)) + 7149858558922988240U) + aOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = (aWandererB + RotL64(aCross, 18U)) + 5919683821379905699U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 6860902846079238714U) + aNonceWordI;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 15083517836867542075U) ^ aOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4686657139237578325U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 14852868368708376381U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 9860233289028878323U;
            aOrbiterH = RotL64((aOrbiterH * 13418143547952204667U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 772406119079116272U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 7971141501337627589U;
            aOrbiterG = RotL64((aOrbiterG * 10168120622976358617U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 8478568022896691911U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 4027604850785607101U;
            aOrbiterF = RotL64((aOrbiterF * 4826627523578901467U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 17199331557841535430U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 7515957656979776361U;
            aOrbiterJ = RotL64((aOrbiterJ * 5468950152869656599U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 17138249294921502391U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 16236812863923234668U;
            aOrbiterB = RotL64((aOrbiterB * 2925542836624164807U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 16941524155859123682U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 11240343728857342866U) ^ aOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7281012444214294659U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 15163914964139858328U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 6673576554415729652U;
            aOrbiterE = RotL64((aOrbiterE * 1558880328574736975U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 5399050402101642989U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 11806006719060024615U) ^ aNonceWordK;
            aOrbiterD = RotL64((aOrbiterD * 15782156615926092159U), 3U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterC, 60U);
            aIngress = aIngress + (RotL64(aOrbiterK, 11U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterF, 29U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterD, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aScatter, 51U) + aOrbiterJ) + RotL64(aOrbiterF, 29U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterK, 13U)) + aOrbiterF);
            aWandererI = aWandererI + ((((RotL64(aCross, 5U) + aOrbiterB) + RotL64(aOrbiterH, 51U)) + aNonceWordH) + aWandererUpdateSaltB[((aIndex + 24U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 42U) + RotL64(aOrbiterG, 42U)) + aOrbiterF);
            aWandererC = aWandererC + ((RotL64(aPrevious, 47U) + aOrbiterC) + RotL64(aOrbiterJ, 47U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 29U) + aOrbiterH) + RotL64(aOrbiterJ, 3U)) + aNonceWordO);
            aWandererE = aWandererE + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterD, 37U)) + aOrbiterH) + RotL64(aCarry, 57U)) + aWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 34U) + RotL64(aOrbiterK, 56U)) + aOrbiterC);
            aWandererK = aWandererK + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterK, 23U)) + aOrbiterE) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererJ);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (RotL64(aWandererG, 54U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererD, 51U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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

void TwistExpander_Soccer_Arx::KDF_B_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xCDB388CD2E0BD28DULL + 0xAD28E9EFBB26F95EULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xCC9937051A01E3D5ULL + 0xD60590302336DA66ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xCCEB24E1E94B698BULL + 0x8F0956DB2280BEFDULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xBB313DE1E1792D57ULL + 0x9FF5C8E04E432487ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x8C7AD987A052939DULL + 0xF1264A3320BC124EULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x879DA64DC75E29E1ULL + 0x867681905E510A25ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xD423EB2785C933E5ULL + 0xC41B99990649CC60ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xE2241AD8DFEEF55BULL + 0xD33FFBFE1A80263BULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xB77E5B4A9942DDF5ULL + 0xE725E0FB17B4B7DBULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xB0DC87BEBD91E103ULL + 0xDEF19717ADD0DE6CULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xA3B725D91285409FULL + 0xFC395086ED146672ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x8E8A55CE35FA6B49ULL + 0xC2A155CD7B141D5FULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xDF5D98CDF591568DULL + 0xC46A06A5BD756AB0ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xB0537DBD8811F92DULL + 0xEE005E8703EE1661ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xE238C2F745405C69ULL + 0xF069D22141534DC8ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xC8945C4C06A5FF4DULL + 0xD654DFD624A17CCBULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aOperationLaneD, aWorkLaneC, aWorkLaneD, aFireLaneC, aExpandLaneA, aOperationLaneA, aFireLaneD, aExpandLaneB, aOperationLaneC, aOperationLaneB, aExpandLaneC, aFireLaneA, aFireLaneB
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_d loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aOperationLaneD
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aOperationLaneD forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aFireLaneC
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aFireLaneC backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 64U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneB[((aIndex + 6091U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aOperationLaneD[((aIndex + 4850U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 3585U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 5993U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 4264U)) & S_BLOCK1], 34U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCarry, 27U)) + (RotL64(aPrevious, 6U) + RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterK = ((aWandererA + RotL64(aPrevious, 13U)) + RotL64(aCarry, 57U)) + 16424657151168221875U;
            aOrbiterF = ((aWandererD + RotL64(aScatter, 5U)) + RotL64(aCarry, 21U)) + 17150123681886380361U;
            aOrbiterI = ((aWandererB + RotL64(aCross, 28U)) + 16041993588694572757U) + aOrbiterAssignSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = ((aWandererH + RotL64(aIngress, 53U)) + 9871185846434828537U) + aNonceWordE;
            aOrbiterH = ((aWandererC + RotL64(aCross, 39U)) + 11227236398354430757U) + aNonceWordL;
            aOrbiterC = ((aWandererF + RotL64(aIngress, 19U)) + RotL64(aCarry, 5U)) + 5399325217402192631U;
            aOrbiterD = (((aWandererE + RotL64(aPrevious, 47U)) + 9248828789282890454U) + aOrbiterAssignSaltE[((aIndex + 10U)) & S_SALT1]) + aNonceWordP;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 9041370494203701062U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 14944424084524970764U) ^ aNonceWordJ;
            aOrbiterI = RotL64((aOrbiterI * 10283363059424655079U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 5481938174456671041U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 14783648629543752715U;
            aOrbiterH = RotL64((aOrbiterH * 7260164783191886395U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 12355573914530445723U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 9863991559011968318U;
            aOrbiterF = RotL64((aOrbiterF * 8495251211794343179U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 16149688605937250965U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 106041828692026825U) ^ aOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12199934305374582599U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 8076098639554567792U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 11155119311895580013U;
            aOrbiterB = RotL64((aOrbiterB * 1495180896564818647U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 6847612160595917702U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 16094377920388017367U;
            aOrbiterD = RotL64((aOrbiterD * 4875801863643206333U), 27U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterK) + 13584719866672696684U) + aOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1]) + aNonceWordD;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 13446209321646234607U;
            aOrbiterC = RotL64((aOrbiterC * 9945349065094781529U), 21U);
            //
            aIngress = RotL64(aOrbiterH, 3U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 47U));
            aIngress = aIngress + (RotL64(aOrbiterK, 12U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterC, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aIngress, 19U) + aOrbiterK) + RotL64(aOrbiterB, 3U)) + aNonceWordB);
            aWandererC = aWandererC + (((RotL64(aScatter, 29U) + RotL64(aOrbiterI, 53U)) + aOrbiterC) + RotL64(aCarry, 29U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterH, 11U)) + aOrbiterC) + aNonceWordK);
            aWandererE = aWandererE + (((((RotL64(aPrevious, 5U) + aOrbiterK) + RotL64(aOrbiterD, 43U)) + RotL64(aCarry, 51U)) + aNonceWordN) + aWandererUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 54U) + RotL64(aOrbiterC, 26U)) + aOrbiterD);
            aWandererD = aWandererD + (((RotL64(aIngress, 35U) + aOrbiterH) + RotL64(aOrbiterF, 19U)) + aNonceWordF);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterI, 35U)) + aOrbiterD) + aWandererUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 46U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererD, 51U);
            aCarry = aCarry + RotL64(aIngress, 30U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aOperationLaneA
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aOperationLaneA forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aFireLaneD
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 12033U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneC[((aIndex + 8865U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 13696U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15356U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 13761U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 13767U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aIngress, 35U) + RotL64(aCarry, 23U)) ^ (RotL64(aPrevious, 10U) ^ RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterI = ((((aWandererI + RotL64(aIngress, 47U)) + RotL64(aCarry, 51U)) + 9446153639709651566U) + aOrbiterAssignSaltF[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordK;
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 21U)) + RotL64(aCarry, 11U)) + 10550762260670758167U;
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 11U)) + 7062634922142578383U) + aOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = ((aWandererD + RotL64(aCross, 3U)) + RotL64(aCarry, 29U)) + 9178499097812764515U;
            aOrbiterE = (aWandererB + RotL64(aPrevious, 35U)) + 6887103379773525538U;
            aOrbiterD = ((aWandererG + RotL64(aCross, 41U)) + 6239750312052010257U) + aNonceWordA;
            aOrbiterA = ((aWandererC + RotL64(aScatter, 56U)) + 17645022614523287959U) + aNonceWordP;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 3639618183259408272U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 3131737117548745095U;
            aOrbiterJ = RotL64((aOrbiterJ * 6585057380704940395U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 7253994382396406554U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 15217993711938379561U;
            aOrbiterE = RotL64((aOrbiterE * 17853313384747259923U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 12594152227603630033U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 11250170200489647869U) ^ aOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 546800378327864723U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 12936942656624279424U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 10990736056052106149U;
            aOrbiterG = RotL64((aOrbiterG * 7123916809953459187U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 12787293075893090465U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 17154990205620778151U) ^ aNonceWordC;
            aOrbiterD = RotL64((aOrbiterD * 10031369940028159521U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 1270827262969060301U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterG) ^ 17337623431665013136U) ^ aOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterI = RotL64((aOrbiterI * 1517262088236356107U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 830330490987911853U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 6828309232554560547U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9742464176986145819U), 41U);
            //
            aIngress = RotL64(aOrbiterI, 29U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 35U));
            aIngress = aIngress + (RotL64(aOrbiterA, 53U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterD, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterJ, 21U)) + aOrbiterG) + aWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererG = aWandererG + (((((RotL64(aPrevious, 19U) + aOrbiterA) + RotL64(aOrbiterI, 57U)) + RotL64(aCarry, 11U)) + aNonceWordO) + aWandererUpdateSaltE[((aIndex + 26U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterC, 14U)) + aOrbiterI) + aNonceWordD);
            aWandererD = aWandererD + (((RotL64(aScatter, 54U) + RotL64(aOrbiterE, 3U)) + aOrbiterD) + RotL64(aCarry, 39U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 43U) + aOrbiterJ) + RotL64(aOrbiterA, 43U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterD, 37U)) + aNonceWordE);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterC, 27U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 46U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererB, 29U);
            aCarry = aCarry + RotL64(aIngress, 50U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 3
        // ingress from: aExpandLaneB, aWorkLaneD, aOperationLaneC
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aOperationLaneC forward/backward random
        // cross from: aExpandLaneA, aWorkLaneB, aOperationLaneB
        // cross directions: aExpandLaneA backward forced, aWorkLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 22459U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneD[((aIndex + 17820U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 19786U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22113U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21173U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 18061U)) & S_BLOCK1], 34U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCross, 43U) ^ RotL64(aIngress, 14U)) + (RotL64(aPrevious, 29U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterK = (((aWandererC + RotL64(aIngress, 3U)) + RotL64(aCarry, 57U)) + 6521330037475130256U) + aNonceWordN;
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 37U)) + RotL64(aCarry, 23U)) + 12611880456055428940U;
            aOrbiterC = ((aWandererG + RotL64(aCross, 27U)) + 12061611078130934708U) + aOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = (((aWandererJ + RotL64(aScatter, 47U)) + RotL64(aCarry, 35U)) + 1558112410801116984U) + aNonceWordF;
            aOrbiterI = ((aWandererI + RotL64(aCross, 54U)) + 10509115227850160786U) + aNonceWordA;
            aOrbiterG = (aWandererF + RotL64(aPrevious, 21U)) + 4045915960688792066U;
            aOrbiterH = ((aWandererK + RotL64(aScatter, 13U)) + 1196541286513243082U) + aOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 15564991032722373702U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 4897765238703641798U) ^ aNonceWordL;
            aOrbiterC = RotL64((aOrbiterC * 9693901276712946763U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 12327429514907752733U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 6189189797708711636U;
            aOrbiterD = RotL64((aOrbiterD * 9017615866338877651U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 6374267075282018852U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 1888758503831341439U) ^ aOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 74387714918264257U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 14956857689299491800U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 14879361107223331957U;
            aOrbiterE = RotL64((aOrbiterE * 9166712966729591953U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 16086885494838105042U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 8069724185844303923U;
            aOrbiterI = RotL64((aOrbiterI * 8878470736758734353U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 10854345917959911439U) + aNonceWordM;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 7078313614360332089U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9864025732292844871U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 15083669236062255011U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 594879695916679116U;
            aOrbiterG = RotL64((aOrbiterG * 9852515479152735283U), 43U);
            //
            aIngress = RotL64(aOrbiterD, 35U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 48U));
            aIngress = aIngress + RotL64(aOrbiterE, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aCross, 35U) + aOrbiterI) + RotL64(aOrbiterH, 37U)) + RotL64(aCarry, 11U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 60U) + RotL64(aOrbiterK, 43U)) + aOrbiterE) + aNonceWordO);
            aWandererK = aWandererK + (((RotL64(aPrevious, 53U) + aOrbiterC) + RotL64(aOrbiterD, 60U)) + aNonceWordJ);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterG, 19U)) + aOrbiterD) + aNonceWordD);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterG, 11U)) + aOrbiterC) + RotL64(aCarry, 29U)) + aWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterC, 53U)) + aOrbiterH) + aNonceWordH);
            aWandererJ = aWandererJ + (((RotL64(aCross, 13U) + aOrbiterE) + RotL64(aOrbiterD, 27U)) + aWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 42U));
            aCarry = aCarry + (RotL64(aWandererK, 37U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + RotL64(aWandererC, 3U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aFireLaneA
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneB, aWorkLaneC, aFireLaneB
        // cross directions: aExpandLaneB backward forced, aWorkLaneC backward forced, aFireLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 27356U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((aIndex + 28846U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 25912U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26343U)) & S_BLOCK1], 6U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 24815U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 27046U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aPrevious, 23U)) + (RotL64(aIngress, 38U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 11U)) + 12046647397183218524U) + aOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = (aWandererD + RotL64(aPrevious, 29U)) + 2760779375026461991U;
            aOrbiterB = ((((aWandererI + RotL64(aCross, 5U)) + RotL64(aCarry, 37U)) + 13735454443176855650U) + aOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1]) + aNonceWordP;
            aOrbiterE = ((aWandererC + RotL64(aScatter, 20U)) + RotL64(aCarry, 51U)) + 4370377000586647724U;
            aOrbiterK = ((aWandererG + RotL64(aIngress, 43U)) + RotL64(aCarry, 11U)) + 14566322384189969094U;
            aOrbiterI = ((aWandererE + RotL64(aScatter, 37U)) + 5056565959818422786U) + aNonceWordO;
            aOrbiterG = (aWandererA + RotL64(aPrevious, 53U)) + 8795403810686579209U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 9625947666256011567U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 1703669290934254701U) ^ aOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5763881345676123583U), 5U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterK) + 6664070663184147951U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordD;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 2104148316797553431U;
            aOrbiterI = RotL64((aOrbiterI * 12887842067180975983U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 1197910004222596145U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 9922977170060903197U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13047828062605568603U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 2048376210852567829U) + aNonceWordH;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 12568990647075931409U) ^ aNonceWordB;
            aOrbiterK = RotL64((aOrbiterK * 9860242601194210927U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 15026894775772902751U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 3439447160137900629U;
            aOrbiterH = RotL64((aOrbiterH * 1813754963043785165U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 6532671388552829796U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 17261098369835997661U;
            aOrbiterG = RotL64((aOrbiterG * 568292591215203521U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 3171300991007459947U) + aNonceWordG;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 5935563269327662024U;
            aOrbiterJ = RotL64((aOrbiterJ * 11271790283157765003U), 29U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterG, 47U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 35U));
            aIngress = aIngress + (RotL64(aOrbiterH, 41U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterI, 28U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aIngress, 53U) + aOrbiterG) + RotL64(aOrbiterE, 3U)) + aNonceWordC);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 13U) + aOrbiterK) + RotL64(aOrbiterI, 57U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterB, 34U)) + aOrbiterK);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 60U) + RotL64(aOrbiterI, 51U)) + aOrbiterJ) + aNonceWordK);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 47U) + aOrbiterB) + RotL64(aOrbiterH, 43U)) + RotL64(aCarry, 27U)) + aWandererUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 37U) + aOrbiterE) + RotL64(aOrbiterH, 19U));
            aWandererA = aWandererA + (((((RotL64(aCross, 27U) + RotL64(aOrbiterJ, 27U)) + aOrbiterH) + RotL64(aCarry, 39U)) + aNonceWordL) + aWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 10U));
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererI, 23U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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

void TwistExpander_Soccer_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA;
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
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltC;
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
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltC;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xD49E10959A9CB9BDULL + 0xD5A1AA1DEB9A2F35ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x98B6304D3B098C37ULL + 0xD0B714F8848FC592ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x93FCF1C7F16E93DFULL + 0xFADBC700A86489ABULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xAEE6D439FC6DD2D5ULL + 0xC2CE026FED4DB86AULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xDD53B7F80CA4701BULL + 0xAAF39CF1E2642B4DULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xC8A57E88AB12D515ULL + 0xD1A69B6510623A86ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xB83E5DE10EACF7F9ULL + 0xCDF41F13C406BF03ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xCCED8435B6956F8BULL + 0xEE3A0EA7458C800DULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xB4A46BA95B83F0DDULL + 0xE25B9483095BA511ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xF6A82CF7E34CE065ULL + 0xB2385C3773BD39A2ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xDFFF9AE8B6C6CEB3ULL + 0x89D98745E135FCC0ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xA344E0717EEB6837ULL + 0x858B28088BE7256DULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xCD5A4C503E9856C3ULL + 0xB72A0EDF0B5F0E5FULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xF728B7DF0E9CD377ULL + 0xF2309476F4140761ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x90204349CE7992E1ULL + 0xB8961DD7256123E8ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xA96085FA1F3931AFULL + 0xD39B1CC2D39BE61BULL);
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 394U)) & W_KEY1], 3U) ^ RotL64(aKeyRowReadB[((aIndex + 99U)) & W_KEY1], 35U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 441U)) & W_KEY1], 35U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 892U)) & S_BLOCK1], 22U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 43U)) ^ (RotL64(aIngress, 23U) + RotL64(aCross, 56U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterB = ((((aWandererG + RotL64(aCross, 27U)) + RotL64(aCarry, 23U)) + 4970414922752555648U) + aPhaseEOrbiterAssignSaltA[((aIndex + 18U)) & S_SALT1]) + aNonceWordG;
            aOrbiterE = ((aWandererB + RotL64(aScatter, 21U)) + 9462756592787669327U) + aNonceWordL;
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 41U)) + 3948790686662213095U) + aNonceWordP;
            aOrbiterF = (aWandererJ + RotL64(aIngress, 3U)) + 14542857212241578311U;
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 13U)) + 3387479009827029547U) + aNonceWordH;
            aOrbiterI = ((aWandererD + RotL64(aIngress, 35U)) + RotL64(aCarry, 5U)) + 1411421370057797877U;
            aOrbiterD = (((aWandererI + RotL64(aScatter, 48U)) + RotL64(aCarry, 57U)) + 16894451466895681236U) + aPhaseEOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1];
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 12727136462290223542U) + aNonceWordF;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 4625389198191960525U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5726474430977810191U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 3471881403786164913U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 6433115856048534831U;
            aOrbiterG = RotL64((aOrbiterG * 9363233870194144053U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 9825592965466157982U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 1553125767261293088U;
            aOrbiterB = RotL64((aOrbiterB * 411535191177308781U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 9951616357109647617U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 11231080382787286889U) ^ aNonceWordA;
            aOrbiterF = RotL64((aOrbiterF * 14024961994986659187U), 13U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterG) + 13419663264017317947U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordN;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 4835055642466215566U;
            aOrbiterI = RotL64((aOrbiterI * 17898065852351759171U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 14558747666410946768U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 13120938960926874504U;
            aOrbiterE = RotL64((aOrbiterE * 5681766019285559739U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 11910501376797343986U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 15074100100781785300U;
            aOrbiterD = RotL64((aOrbiterD * 228976960937473851U), 35U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterB, 57U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 27U));
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterD, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aIngress, 29U) + aOrbiterG) + RotL64(aOrbiterK, 35U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterD, 29U)) + aOrbiterI);
            aWandererF = aWandererF + (((RotL64(aPrevious, 37U) + aOrbiterK) + RotL64(aOrbiterD, 13U)) + aNonceWordO);
            aWandererD = aWandererD ^ (((RotL64(aCross, 19U) + aOrbiterF) + RotL64(aOrbiterI, 21U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererB = aWandererB + (((((RotL64(aIngress, 13U) + RotL64(aOrbiterI, 50U)) + aOrbiterE) + RotL64(aCarry, 51U)) + aNonceWordI) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 56U) + RotL64(aOrbiterB, 41U)) + aOrbiterE);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 43U) + RotL64(aOrbiterF, 5U)) + aOrbiterB) + RotL64(aCarry, 5U)) + aNonceWordJ);
            //
            aCarry = aCarry + (RotL64(aWandererG, 51U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererE, 6U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererF, 23U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 5159U)) & S_BLOCK1], 39U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 2939U)) & W_KEY1], 58U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 4149U)) & W_KEY1], 3U) ^ RotL64(mSource[((aIndex + 3107U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aPrevious, 57U)) + (RotL64(aIngress, 6U) ^ RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterE = (((aWandererE + RotL64(aCross, 21U)) + RotL64(aCarry, 39U)) + 3621877681473089725U) + aNonceWordC;
            aOrbiterF = ((aWandererG + RotL64(aScatter, 53U)) + 4451752751536414717U) + aPhaseEOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = (((aWandererC + RotL64(aIngress, 43U)) + RotL64(aCarry, 3U)) + 11371625415377772117U) + aNonceWordP;
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 36U)) + RotL64(aCarry, 19U)) + 6046792758881150619U;
            aOrbiterH = (((aWandererA + RotL64(aScatter, 29U)) + 8213166120394461682U) + aPhaseEOrbiterAssignSaltC[((aIndex + 8U)) & S_SALT1]) + aNonceWordA;
            aOrbiterG = ((aWandererH + RotL64(aCross, 13U)) + 4343156661140422645U) + aNonceWordF;
            aOrbiterB = (aWandererI + RotL64(aIngress, 3U)) + 11105271483234947905U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 348904609985341372U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 12924652822526858767U;
            aOrbiterC = RotL64((aOrbiterC * 2801892489296408735U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 7461211697358520287U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 16551553555297890558U) ^ aNonceWordE;
            aOrbiterH = RotL64((aOrbiterH * 16432952324635746293U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 11908056404140782995U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 9147367258259948715U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10777628928376261667U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 8876461054692728610U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 10546855952702525404U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10071104785895309677U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 4748636139110443794U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterC) ^ 783046909529525098U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterB = RotL64((aOrbiterB * 8969157702460927215U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 16683965945838696665U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 12385412690177109575U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10795062772707143187U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 8210546822184469023U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 13146493623236979963U;
            aOrbiterA = RotL64((aOrbiterA * 13199947810161148155U), 29U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterF, 27U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 51U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 11U));
            aIngress = aIngress + RotL64(aOrbiterH, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterE, 51U)) + aOrbiterB);
            aWandererA = aWandererA + (((RotL64(aScatter, 53U) + aOrbiterE) + RotL64(aOrbiterC, 57U)) + aNonceWordB);
            aWandererC = aWandererC ^ (((RotL64(aCross, 5U) + aOrbiterG) + RotL64(aOrbiterA, 42U)) + aNonceWordK);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 27U) + aOrbiterE) + RotL64(aOrbiterH, 23U)) + RotL64(aCarry, 41U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterA, 13U)) + aOrbiterE) + aNonceWordM);
            aWandererE = aWandererE + (((RotL64(aCross, 19U) + aOrbiterA) + RotL64(aOrbiterF, 5U)) + RotL64(aCarry, 13U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 38U) + RotL64(aOrbiterF, 35U)) + aOrbiterH) + aPhaseEWandererUpdateSaltD[((aIndex + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 34U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 27U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + RotL64(aWandererE, 23U);
            aCarry = aCarry + RotL64(aIngress, 14U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 6476U)) & S_BLOCK1], 37U) ^ RotL64(aKeyRowReadB[((aIndex + 7967U)) & W_KEY1], 57U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 6161U)) & W_KEY1], 38U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 6865U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 6835U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aPrevious, 39U)) ^ (RotL64(aIngress, 5U) ^ RotL64(aCross, 22U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterJ = (((aWandererH + RotL64(aPrevious, 37U)) + RotL64(aCarry, 43U)) + 6469584119078165548U) + aNonceWordJ;
            aOrbiterC = (((aWandererJ + RotL64(aCross, 47U)) + 14329756366517987910U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordK;
            aOrbiterB = ((aWandererF + RotL64(aScatter, 29U)) + RotL64(aCarry, 57U)) + 12890831797059772123U;
            aOrbiterI = ((aWandererG + RotL64(aIngress, 5U)) + RotL64(aCarry, 29U)) + 3164503807500018990U;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 18U)) + 177531431387646836U) + aNonceWordC;
            aOrbiterD = (aWandererD + RotL64(aIngress, 11U)) + 3167421392893561015U;
            aOrbiterF = (((aWandererK + RotL64(aCross, 57U)) + 2813174781844753460U) + aPhaseEOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1]) + aNonceWordB;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 10953270419153249857U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 16911518309710356951U) ^ aNonceWordF;
            aOrbiterB = RotL64((aOrbiterB * 13162785997686570445U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 6616750447844893150U) + aNonceWordN;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 10276741398025985982U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6824712685896987133U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 6206043608461213208U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 12021552904553405793U;
            aOrbiterI = RotL64((aOrbiterI * 10023362889960174909U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 15283586234744144846U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 5923238786775948571U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8200882393521882651U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 11044014510971660078U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 9351141024085076044U;
            aOrbiterG = RotL64((aOrbiterG * 13316079344614432317U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 17703395981862992420U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 10154548848376027087U) ^ aNonceWordO;
            aOrbiterF = RotL64((aOrbiterF * 12324478347590509035U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 8836420852291617425U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 10193385413543886344U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 824935982418585449U), 29U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 27U);
            aIngress = aIngress + (RotL64(aOrbiterD, 21U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterG, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterI, 43U)) + aOrbiterB);
            aWandererH = aWandererH + ((((RotL64(aCross, 35U) + aOrbiterD) + RotL64(aOrbiterF, 27U)) + RotL64(aCarry, 23U)) + aNonceWordP);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 13U) + aOrbiterI) + RotL64(aOrbiterG, 13U));
            aWandererK = aWandererK + (((((RotL64(aPrevious, 19U) + aOrbiterJ) + RotL64(aOrbiterF, 37U)) + RotL64(aCarry, 53U)) + aNonceWordA) + aPhaseEWandererUpdateSaltE[((aIndex + 24U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 5U) + aOrbiterG) + RotL64(aOrbiterF, 51U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 42U) + RotL64(aOrbiterC, 21U)) + aOrbiterJ);
            aWandererD = aWandererD ^ ((((RotL64(aIngress, 29U) + aOrbiterG) + RotL64(aOrbiterJ, 58U)) + aNonceWordM) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 30U) ^ aWandererD);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + RotL64(aWandererC, 13U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 9607U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadB[((aIndex + 10449U)) & W_KEY1], 41U));
            aIngress ^= (RotL64(mSource[((aIndex + 9873U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 10670U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 10268U)) & W_KEY1], 36U) ^ RotL64(aWorkLaneB[((aIndex + 9789U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aIngress, 53U)) ^ (RotL64(aCarry, 26U) + RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterD = (aWandererK + RotL64(aIngress, 5U)) + 17019646486641172469U;
            aOrbiterB = (((aWandererA + RotL64(aPrevious, 14U)) + 12276141179299971572U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordO;
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 23U)) + 3617241694029841555U) + aNonceWordG;
            aOrbiterC = ((aWandererJ + RotL64(aCross, 35U)) + RotL64(aCarry, 47U)) + 6967963401259371737U;
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 29U)) + RotL64(aCarry, 35U)) + 6340709284279891017U;
            aOrbiterH = ((((aWandererC + RotL64(aScatter, 47U)) + RotL64(aCarry, 19U)) + 456065368903896482U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordK;
            aOrbiterG = (aWandererG + RotL64(aIngress, 53U)) + 17686765719908116203U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 1322045955429785736U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 5163772703302372887U;
            aOrbiterJ = RotL64((aOrbiterJ * 3193272189179082313U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 13268431135020363252U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterC) ^ 6538789950366849332U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterD = RotL64((aOrbiterD * 5352960308459065837U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 10390344544314544893U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 5087084271300584267U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15149302947570776165U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 13423071121590981727U) + aNonceWordL;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 18324443012024134729U) ^ aNonceWordM;
            aOrbiterB = RotL64((aOrbiterB * 15814349432207734533U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 4129091815978464507U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 17024797553831962245U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3137753479364378175U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 6501545108779991661U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 11930037791867597447U) ^ aNonceWordD;
            aOrbiterH = RotL64((aOrbiterH * 4904739567549702851U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 4667298703308315851U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 6315980380900062127U;
            aOrbiterG = RotL64((aOrbiterG * 12080555704907924637U), 19U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterB, 21U);
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 46U));
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aPrevious, 57U) + aOrbiterB) + RotL64(aOrbiterH, 21U)) + RotL64(aCarry, 35U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterA, 38U)) + aOrbiterB) + aNonceWordC);
            aWandererG = aWandererG + ((((RotL64(aScatter, 47U) + RotL64(aOrbiterJ, 3U)) + aOrbiterB) + aNonceWordA) + aPhaseFWandererUpdateSaltB[((aIndex + 4U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 12U) + RotL64(aOrbiterC, 57U)) + aOrbiterH);
            aWandererK = aWandererK + (((RotL64(aCross, 41U) + aOrbiterH) + RotL64(aOrbiterJ, 51U)) + RotL64(aCarry, 47U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterC, 13U)) + aOrbiterD) + aNonceWordJ);
            aWandererA = aWandererA + (((RotL64(aScatter, 23U) + aOrbiterG) + RotL64(aOrbiterH, 27U)) + aPhaseFWandererUpdateSaltC[((aIndex + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 27U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 41U));
            aCarry = aCarry + RotL64(aWandererJ, 60U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = (RotL64(aWorkLaneD[((aIndex + 13340U)) & S_BLOCK1], 27U) ^ RotL64(aKeyRowReadA[((aIndex + 12836U)) & W_KEY1], 19U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 13420U)) & W_KEY1], 36U) ^ RotL64(mSource[((aIndex + 12352U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 12966U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 10936U)) & S_BLOCK1], 52U) ^ RotL64(aWorkLaneC[((aIndex + 12772U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aPrevious, 43U) ^ RotL64(aCross, 27U)) ^ (RotL64(aCarry, 60U) + RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 60U)) + RotL64(aCarry, 41U)) + 2783898056762489197U;
            aOrbiterA = ((((aWandererJ + RotL64(aScatter, 41U)) + RotL64(aCarry, 21U)) + 7177192902873343053U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordD;
            aOrbiterH = ((aWandererG + RotL64(aCross, 53U)) + 12254703232691980774U) + aNonceWordO;
            aOrbiterK = (((aWandererA + RotL64(aIngress, 23U)) + 15446547245691219559U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordI;
            aOrbiterD = (aWandererE + RotL64(aPrevious, 11U)) + 888475203006174856U;
            aOrbiterF = (aWandererC + RotL64(aIngress, 47U)) + 3649183529366307877U;
            aOrbiterC = ((aWandererB + RotL64(aCross, 5U)) + RotL64(aCarry, 5U)) + 4642631047518805167U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 6108329730724782250U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 8334054653023816636U;
            aOrbiterH = RotL64((aOrbiterH * 9352516059501924393U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 5891895375031474350U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 3176720746238477862U;
            aOrbiterA = RotL64((aOrbiterA * 1869961473768307911U), 35U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterK) + 6111038696865301675U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordN;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 11914998302228682704U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11738924766359642853U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 17005063057791320948U) + aNonceWordJ;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 18333780598768130670U) ^ aNonceWordC;
            aOrbiterF = RotL64((aOrbiterF * 5416759844884107303U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 2056115016443263153U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 10245512728872962677U;
            aOrbiterD = RotL64((aOrbiterD * 707106795383284903U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 4810366069422162351U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 3051442983125942469U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13558537578054436423U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 9285068547223654308U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 13067251130180968842U;
            aOrbiterK = RotL64((aOrbiterK * 7000687697769766605U), 47U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterF, 3U);
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterK, 51U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterC, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aIngress, 19U) + aOrbiterF) + RotL64(aOrbiterA, 43U)) + aNonceWordH);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 37U) + aOrbiterJ) + RotL64(aOrbiterD, 6U)) + RotL64(aCarry, 57U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 5U) + aOrbiterH) + RotL64(aOrbiterF, 37U)) + aPhaseFWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aCross, 26U) + RotL64(aOrbiterD, 13U)) + aOrbiterK) + RotL64(aCarry, 19U)) + aNonceWordM);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 13U) + aOrbiterF) + RotL64(aOrbiterK, 19U)) + aNonceWordF);
            aWandererE = aWandererE + ((RotL64(aCross, 47U) + aOrbiterC) + RotL64(aOrbiterK, 29U));
            aWandererC = aWandererC ^ ((((RotL64(aPrevious, 53U) + RotL64(aOrbiterC, 57U)) + aOrbiterA) + aNonceWordK) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererA, 12U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererC, 3U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 15031U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 15329U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 16281U)) & W_KEY1], 5U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 13937U)) & W_KEY1], 13U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 15739U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 16031U)) & S_BLOCK1], 56U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 14418U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 37U) + RotL64(aCarry, 20U)) + (RotL64(aIngress, 5U) ^ RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterA = (((aWandererK + RotL64(aIngress, 53U)) + 5480870806135400132U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordM;
            aOrbiterE = ((aWandererJ + RotL64(aCross, 19U)) + 8034874599430768743U) + aNonceWordG;
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 37U)) + RotL64(aCarry, 47U)) + 4006919843736863767U;
            aOrbiterJ = (((aWandererH + RotL64(aScatter, 29U)) + 2988069748674633718U) + aPhaseFOrbiterAssignSaltE[((aIndex + 26U)) & S_SALT1]) + aNonceWordH;
            aOrbiterG = (((aWandererE + RotL64(aIngress, 3U)) + RotL64(aCarry, 13U)) + 12347295651973135786U) + aNonceWordC;
            aOrbiterH = ((aWandererD + RotL64(aScatter, 60U)) + RotL64(aCarry, 35U)) + 14152683894431568192U;
            aOrbiterB = (aWandererC + RotL64(aCross, 11U)) + 15765143815254196598U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 10473067082331244233U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 1089466925383677249U) ^ aNonceWordL;
            aOrbiterD = RotL64((aOrbiterD * 17334888609179149753U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 13215039929873682230U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 3957997712247961479U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7631186240013784703U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 10023907397941685546U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 14593012591254614353U;
            aOrbiterJ = RotL64((aOrbiterJ * 17111300092082154687U), 47U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterH) + 13353797968154036726U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1]) + aNonceWordF;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 9259966668512102858U;
            aOrbiterE = RotL64((aOrbiterE * 8326732574268308221U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 10757861831070349321U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 10530223113483866178U) ^ aNonceWordB;
            aOrbiterA = RotL64((aOrbiterA * 11269177745265396583U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 7554320926405521865U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 6978052067277966996U;
            aOrbiterB = RotL64((aOrbiterB * 18020134738536217801U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 1053695861967171420U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 15980734683539854451U;
            aOrbiterH = RotL64((aOrbiterH * 3208466640010555357U), 5U);
            //
            aIngress = RotL64(aOrbiterA, 35U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 23U));
            aIngress = aIngress + RotL64(aOrbiterD, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aCross, 58U) + aOrbiterJ) + RotL64(aOrbiterH, 18U)) + aNonceWordN);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 41U) + aOrbiterJ) + RotL64(aOrbiterA, 47U)) + aPhaseFWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterB, 3U)) + aOrbiterJ) + RotL64(aCarry, 35U));
            aWandererE = aWandererE ^ ((((RotL64(aScatter, 35U) + aOrbiterD) + RotL64(aOrbiterH, 11U)) + aNonceWordI) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 27U) + RotL64(aOrbiterA, 41U)) + aOrbiterG) + aNonceWordK);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 3U) + aOrbiterG) + RotL64(aOrbiterE, 29U)) + aNonceWordD);
            aWandererC = aWandererC + (((RotL64(aIngress, 11U) + RotL64(aOrbiterB, 53U)) + aOrbiterH) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 23U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererE, 18U) ^ aWandererJ);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + RotL64(aWandererD, 29U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 18412U)) & S_BLOCK1], 47U) ^ RotL64(aKeyRowReadA[((aIndex + 16488U)) & W_KEY1], 3U));
            aIngress ^= (RotL64(mSource[((aIndex + 16443U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneA[((aIndex + 17136U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 18580U)) & W_KEY1], 53U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 16785U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 18429U)) & S_BLOCK1], 20U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 50U) ^ RotL64(aPrevious, 23U)) ^ (RotL64(aIngress, 37U) + RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterA = (((aWandererB + RotL64(aPrevious, 51U)) + RotL64(aCarry, 19U)) + 7825479804710770560U) + aNonceWordL;
            aOrbiterB = (((aWandererD + RotL64(aScatter, 3U)) + RotL64(aCarry, 5U)) + 5298124167101358123U) + aNonceWordM;
            aOrbiterC = ((aWandererE + RotL64(aIngress, 42U)) + 17774541024369233726U) + aNonceWordO;
            aOrbiterK = (((aWandererA + RotL64(aCross, 13U)) + RotL64(aCarry, 51U)) + 7679371833537454082U) + aNonceWordH;
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 57U)) + 5385914900748772224U;
            aOrbiterD = ((aWandererH + RotL64(aCross, 29U)) + 3879781930908486531U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = ((aWandererF + RotL64(aScatter, 23U)) + 659110346638873236U) + aPhaseGOrbiterAssignSaltA[((aIndex + 4U)) & S_SALT1];
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 10749021728538539749U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 3631252455767429457U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8552825360915119613U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 2271978810960685021U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 5963558780692551176U;
            aOrbiterH = RotL64((aOrbiterH * 4772055335210781149U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 974909966119198104U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 9296998242911152296U;
            aOrbiterA = RotL64((aOrbiterA * 2613629915877957661U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 2245318466901521959U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 13391076374843288568U;
            aOrbiterK = RotL64((aOrbiterK * 18094558036982107419U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 6184487746594236737U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 1563385912137291418U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4805455299959232321U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 1744840092006498629U) + aNonceWordB;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 2100927276837188416U;
            aOrbiterG = RotL64((aOrbiterG * 3541788262067077997U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 9998911862807246338U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 12239948725635220096U) ^ aNonceWordE;
            aOrbiterB = RotL64((aOrbiterB * 7098620484129489129U), 19U);
            //
            aIngress = RotL64(aOrbiterC, 57U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 39U));
            aIngress = aIngress + (RotL64(aOrbiterG, 30U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterB, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aIngress, 57U) + aOrbiterA) + RotL64(aOrbiterK, 29U)) + aPhaseGWandererUpdateSaltB[((aIndex + 10U)) & S_SALT1]);
            aWandererH = aWandererH + (((((RotL64(aScatter, 13U) + RotL64(aOrbiterC, 57U)) + aOrbiterG) + RotL64(aCarry, 21U)) + aNonceWordA) + aPhaseGWandererUpdateSaltF[((aIndex + 6U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterK, 37U)) + aOrbiterH) + aNonceWordJ);
            aWandererJ = aWandererJ + (((RotL64(aCross, 5U) + aOrbiterD) + RotL64(aOrbiterH, 47U)) + RotL64(aCarry, 43U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterH, 13U)) + aOrbiterG) + aNonceWordD);
            aWandererD = aWandererD + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterC, 20U)) + aOrbiterA);
            aWandererE = aWandererE ^ (((RotL64(aCross, 44U) + aOrbiterK) + RotL64(aOrbiterB, 3U)) + aNonceWordF);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 19U));
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 48U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererF, 53U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 21409U)) & S_BLOCK1], 53U) ^ RotL64(mSource[((aIndex + 21313U)) & S_BLOCK1], 21U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 20502U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19609U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 19351U)) & W_KEY1], 5U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 20522U)) & W_KEY1], 29U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 21787U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19695U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 56U) ^ RotL64(aPrevious, 27U)) + (RotL64(aCross, 39U) + RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterI = ((aWandererK + RotL64(aIngress, 60U)) + RotL64(aCarry, 37U)) + 2672739400294801233U;
            aOrbiterJ = (((aWandererC + RotL64(aCross, 35U)) + RotL64(aCarry, 13U)) + 8475624545015101850U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = (aWandererA + RotL64(aScatter, 27U)) + 1252755112289831257U;
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 51U)) + RotL64(aCarry, 51U)) + 7938039507649183387U;
            aOrbiterE = ((aWandererI + RotL64(aCross, 19U)) + 8167413146948861022U) + aNonceWordE;
            aOrbiterB = ((aWandererD + RotL64(aIngress, 41U)) + 17712313989694374353U) + aPhaseGOrbiterAssignSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 3U)) + 7637042279892596975U) + aNonceWordB;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 15770412950033467341U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = (((aOrbiterD ^ aOrbiterI) ^ 3951812021898608685U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterD = RotL64((aOrbiterD * 6623127125223204737U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 8656983621098246507U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 17943342344730687317U;
            aOrbiterE = RotL64((aOrbiterE * 16495519451034883813U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 3087677463651608668U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 16493240011924342788U;
            aOrbiterI = RotL64((aOrbiterI * 16898479041530771871U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 7750923317452683057U) + aNonceWordP;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 2185924841611106546U;
            aOrbiterC = RotL64((aOrbiterC * 708072658250726381U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 14676868738946722416U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 6849098251696302393U;
            aOrbiterB = RotL64((aOrbiterB * 2599806275837778069U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 17817755047153606419U) + aNonceWordM;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 9900465270314068757U) ^ aNonceWordA;
            aOrbiterK = RotL64((aOrbiterK * 9267925873983176685U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 11380000891112113701U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 15930503831156546113U;
            aOrbiterJ = RotL64((aOrbiterJ * 14450535035065393845U), 11U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterE, 19U);
            aIngress = aIngress + (RotL64(aOrbiterB, 11U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterI, 3U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterC, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aIngress, 29U) + RotL64(aOrbiterJ, 21U)) + aOrbiterI) + aNonceWordG) + aPhaseGWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterB, 51U)) + aOrbiterK) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 53U) + aOrbiterK) + RotL64(aOrbiterI, 29U)) + aNonceWordH);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 35U) + aOrbiterE) + RotL64(aOrbiterI, 42U)) + aNonceWordN);
            aWandererC = aWandererC + ((((RotL64(aCross, 41U) + aOrbiterC) + RotL64(aOrbiterB, 57U)) + RotL64(aCarry, 21U)) + aNonceWordF);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 22U) + RotL64(aOrbiterJ, 35U)) + aOrbiterK);
            aWandererA = aWandererA + (((RotL64(aIngress, 13U) + aOrbiterI) + RotL64(aOrbiterD, 5U)) + RotL64(aCarry, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 51U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererK, 22U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererA, 13U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 22681U)) & S_BLOCK1], 57U) ^ RotL64(aKeyRowReadA[((aIndex + 24127U)) & W_KEY1], 29U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 24543U)) & W_KEY1], 39U) ^ RotL64(aFireLaneC[((aIndex + 24014U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 24107U)) & S_BLOCK1], 23U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 24010U)) & S_BLOCK1], 13U));
            aCross ^= (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 23275U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 22828U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCross, 35U) + RotL64(aIngress, 53U)) ^ (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 22U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterG = ((aWandererB + RotL64(aIngress, 51U)) + 3650233661228036955U) + aNonceWordP;
            aOrbiterI = (aWandererE + RotL64(aCross, 3U)) + 11607036400067735729U;
            aOrbiterJ = (((aWandererK + RotL64(aScatter, 42U)) + RotL64(aCarry, 23U)) + 3899614406903883035U) + aPhaseGOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = (((aWandererH + RotL64(aPrevious, 35U)) + RotL64(aCarry, 51U)) + 8159156925629965143U) + aPhaseGOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = (aWandererJ + RotL64(aIngress, 23U)) + 7148903913967261270U;
            aOrbiterC = (aWandererC + RotL64(aPrevious, 13U)) + 9161665622287517848U;
            aOrbiterH = (((aWandererI + RotL64(aCross, 57U)) + RotL64(aCarry, 39U)) + 2981535013474059469U) + aNonceWordH;
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 15812469008200319549U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 14687469489893270300U) ^ aNonceWordN;
            aOrbiterJ = RotL64((aOrbiterJ * 14142363399696670451U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 6025209349511417063U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 12964750392311112676U;
            aOrbiterC = RotL64((aOrbiterC * 12955480283032701843U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 6572355895765394340U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 3542300121890027981U;
            aOrbiterD = RotL64((aOrbiterD * 11201491178181273935U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 6477175684045398359U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 1081388388827929314U;
            aOrbiterH = RotL64((aOrbiterH * 8752188637514143529U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 13754328481584620771U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 3684673342659575917U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6139923312873039143U), 51U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterG) + 6542045150319909445U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1]) + aNonceWordD;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 5352102692424060388U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7385758355501860261U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 9110100774657340354U) + aNonceWordK;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 2813273684436269057U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10468759062594022273U), 39U);
            //
            aIngress = RotL64(aOrbiterB, 13U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterG, 29U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterJ, 5U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterI, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aScatter, 11U) + RotL64(aOrbiterB, 29U)) + aOrbiterI);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterC, 47U)) + aOrbiterG) + aNonceWordL);
            aWandererI = aWandererI + ((((RotL64(aIngress, 27U) + aOrbiterI) + RotL64(aOrbiterJ, 13U)) + RotL64(aCarry, 27U)) + aNonceWordG);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 5U) + aOrbiterG) + RotL64(aOrbiterH, 20U));
            aWandererB = aWandererB + ((RotL64(aIngress, 39U) + RotL64(aOrbiterD, 41U)) + aOrbiterH);
            aWandererK = aWandererK ^ ((((RotL64(aScatter, 51U) + RotL64(aOrbiterD, 53U)) + aOrbiterB) + aNonceWordA) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererC = aWandererC + (((((RotL64(aPrevious, 20U) + RotL64(aOrbiterG, 3U)) + aOrbiterJ) + RotL64(aCarry, 11U)) + aNonceWordO) + aPhaseGWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + (RotL64(aWandererI, 40U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererB, 35U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 26589U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadA[((aIndex + 25913U)) & W_KEY1], 53U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 25826U)) & S_BLOCK1], 21U) ^ RotL64(aFireLaneB[((aIndex + 25151U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 25965U)) & W_KEY1], 57U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 26197U)) & S_BLOCK1], 47U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 24722U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 26663U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 3U) ^ RotL64(aCarry, 52U)) + (RotL64(aPrevious, 19U) ^ RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterC = ((aWandererK + RotL64(aCross, 60U)) + RotL64(aCarry, 53U)) + 15904465836916519864U;
            aOrbiterA = (((aWandererI + RotL64(aScatter, 51U)) + RotL64(aCarry, 37U)) + 17725629806317789307U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = (aWandererH + RotL64(aIngress, 19U)) + 13794170125914914828U;
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 27U)) + RotL64(aCarry, 23U)) + 2149055907476874332U;
            aOrbiterG = (aWandererE + RotL64(aIngress, 43U)) + 5342047776745074649U;
            aOrbiterE = ((aWandererG + RotL64(aScatter, 35U)) + 8268148484060546838U) + aNonceWordC;
            aOrbiterK = (((aWandererB + RotL64(aPrevious, 3U)) + 10821151364028563719U) + aPhaseHOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1]) + aNonceWordF;
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 4294213820894407378U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 10884726101307943090U;
            aOrbiterB = RotL64((aOrbiterB * 1116128870387229159U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 16432210042202444824U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = (((aOrbiterG ^ aOrbiterB) ^ 15196602644336228055U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterG = RotL64((aOrbiterG * 12680438355124070237U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 14117787670220328165U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 219833877949480215U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10736293047771972173U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 3326396981881473962U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 14918513066311426279U) ^ aNonceWordB;
            aOrbiterE = RotL64((aOrbiterE * 14269763278564574663U), 35U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterE) + 11795234681370163206U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordK;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 3068267285352664813U;
            aOrbiterK = RotL64((aOrbiterK * 15746255933920904619U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 245233356957999496U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 709926406353796673U;
            aOrbiterA = RotL64((aOrbiterA * 13627039596842073595U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 5378105439430271038U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 10114555061122044430U;
            aOrbiterC = RotL64((aOrbiterC * 5351295043424885549U), 53U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterA, 41U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 5U));
            aIngress = aIngress + (RotL64(aOrbiterG, 23U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterK, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aIngress, 12U) + RotL64(aOrbiterJ, 60U)) + aOrbiterK) + aNonceWordG);
            aWandererE = aWandererE + (((((RotL64(aCross, 57U) + aOrbiterA) + RotL64(aOrbiterC, 51U)) + RotL64(aCarry, 11U)) + aNonceWordL) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 51U) + aOrbiterG) + RotL64(aOrbiterE, 43U)) + aNonceWordE);
            aWandererG = aWandererG + ((((RotL64(aScatter, 41U) + RotL64(aOrbiterJ, 13U)) + aOrbiterA) + RotL64(aCarry, 41U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 19U) + aOrbiterE) + RotL64(aOrbiterK, 37U));
            aWandererI = aWandererI + ((RotL64(aCross, 35U) + aOrbiterB) + RotL64(aOrbiterA, 5U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 29U) + aOrbiterJ) + RotL64(aOrbiterE, 23U)) + aNonceWordN);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 37U));
            aCarry = aCarry + (RotL64(aWandererC, 10U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 21U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 29995U)) & S_BLOCK1], 35U) ^ RotL64(aFireLaneD[((aIndex + 28467U)) & S_BLOCK1], 43U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 28490U)) & W_KEY1], 27U) ^ RotL64(aFireLaneC[((aIndex + 28243U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 28937U)) & W_KEY1], 41U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 27447U)) & S_BLOCK1], 21U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27772U)) & S_BLOCK1], 53U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 28724U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 11U) ^ RotL64(aIngress, 52U)) + (RotL64(aPrevious, 23U) ^ RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterG = (aWandererG + RotL64(aIngress, 54U)) + 12311607308490066301U;
            aOrbiterC = ((aWandererF + RotL64(aCross, 47U)) + 13100864684740679846U) + aNonceWordH;
            aOrbiterK = ((((aWandererH + RotL64(aPrevious, 29U)) + RotL64(aCarry, 5U)) + 13697304189274329704U) + aPhaseHOrbiterAssignSaltF[((aIndex + 8U)) & S_SALT1]) + aNonceWordB;
            aOrbiterE = (((aWandererA + RotL64(aScatter, 21U)) + RotL64(aCarry, 37U)) + 9047976902871216732U) + aPhaseHOrbiterAssignSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterF = (aWandererB + RotL64(aPrevious, 37U)) + 2147897579538537888U;
            aOrbiterB = (aWandererE + RotL64(aCross, 5U)) + 2072444829390996142U;
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 11U)) + RotL64(aCarry, 23U)) + 2129307836981020908U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 10663145333751112064U) + aNonceWordF;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 15019844390503785459U;
            aOrbiterK = RotL64((aOrbiterK * 7442321463110790449U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 5460865577557928142U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 15806522559993224197U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8722932687972240099U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 6361113778657833389U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 8306013884615042570U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8234258702656728667U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 4038420580499706912U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 11908091484457158973U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3964111175645156719U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 11133912466611921250U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 2469227904206936928U;
            aOrbiterG = RotL64((aOrbiterG * 2704438771198001599U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 13234017916788297295U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 9061117693840451988U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3637440416741459419U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 12013423690843812324U) + aNonceWordA;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 14371779015144617412U;
            aOrbiterB = RotL64((aOrbiterB * 3359568073302062667U), 53U);
            //
            aIngress = RotL64(aOrbiterC, 39U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + (RotL64(aOrbiterB, 5U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterK, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((((RotL64(aScatter, 29U) + aOrbiterJ) + RotL64(aOrbiterE, 3U)) + aNonceWordM) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterC, 60U)) + aOrbiterG);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 36U) + RotL64(aOrbiterB, 47U)) + aOrbiterF) + aNonceWordJ);
            aWandererF = aWandererF + (((RotL64(aCross, 47U) + aOrbiterK) + RotL64(aOrbiterB, 23U)) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 3U) + aOrbiterE) + RotL64(aOrbiterF, 41U)) + aPhaseHWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aScatter, 53U) + RotL64(aOrbiterJ, 29U)) + aOrbiterG) + RotL64(aCarry, 51U)) + aNonceWordK);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterK, 35U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererJ);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 52U));
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererF, 57U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 31285U)) & S_BLOCK1], 43U) ^ RotL64(aKeyRowReadA[((aIndex + 30480U)) & W_KEY1], 14U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 31294U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30624U)) & S_BLOCK1], 29U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31511U)) & S_BLOCK1], 19U) ^ RotL64(aKeyRowReadB[((aIndex + 31323U)) & W_KEY1], 50U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 3U) ^ RotL64(aIngress, 52U)) ^ (RotL64(aPrevious, 21U) + RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterH = ((aWandererG + RotL64(aIngress, 5U)) + RotL64(aCarry, 57U)) + 11998579547770778580U;
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 27U)) + RotL64(aCarry, 5U)) + 8409465187298704610U;
            aOrbiterE = ((((aWandererI + RotL64(aScatter, 57U)) + RotL64(aCarry, 21U)) + 3470222286110333500U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordL;
            aOrbiterD = (aWandererB + RotL64(aCross, 41U)) + 5704486785203069994U;
            aOrbiterI = (aWandererC + RotL64(aIngress, 35U)) + 10334944660253279633U;
            aOrbiterA = (((aWandererH + RotL64(aPrevious, 18U)) + 7626852700722567477U) + aPhaseHOrbiterAssignSaltC[((aIndex + 4U)) & S_SALT1]) + aNonceWordM;
            aOrbiterF = (aWandererK + RotL64(aCross, 51U)) + 14631310754943209743U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 807160297237854120U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 5624154783624196107U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2404066593958052159U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 4971444394698940423U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 6340057638461027062U;
            aOrbiterI = RotL64((aOrbiterI * 12027586111086798629U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 9003019862787819481U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 13632057463595873033U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12575202147280216765U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 12766104026871797746U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 4062118445824915939U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13130770039048080701U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 5258212525426469978U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 9956946981015983939U) ^ aNonceWordC;
            aOrbiterD = RotL64((aOrbiterD * 8106382657040497669U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 10837606223056473999U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 13292864885504191134U) ^ aNonceWordJ;
            aOrbiterH = RotL64((aOrbiterH * 4445739587553669471U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 166087925900318658U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 6786842221885441388U;
            aOrbiterK = RotL64((aOrbiterK * 4411147600413147773U), 37U);
            //
            aIngress = RotL64(aOrbiterH, 43U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterI, 53U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterF, 13U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterD, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((((RotL64(aPrevious, 29U) + aOrbiterI) + RotL64(aOrbiterA, 29U)) + aNonceWordF) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 3U) + aOrbiterK) + RotL64(aOrbiterD, 19U)) + RotL64(aCarry, 13U));
            aWandererD = aWandererD ^ ((((RotL64(aCross, 57U) + aOrbiterK) + RotL64(aOrbiterH, 53U)) + aNonceWordB) + aPhaseHWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 13U) + aOrbiterI) + RotL64(aOrbiterF, 41U)) + aNonceWordE);
            aWandererK = aWandererK ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterA, 47U)) + aOrbiterD);
            aWandererI = aWandererI + ((((RotL64(aScatter, 50U) + RotL64(aOrbiterE, 60U)) + aOrbiterH) + RotL64(aCarry, 37U)) + aNonceWordO);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 23U) + aOrbiterD) + RotL64(aOrbiterE, 35U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + (RotL64(aWandererI, 53U) ^ aWandererD);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 48U));
            aCarry = aCarry + RotL64(aWandererH, 19U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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

void TwistExpander_Soccer_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x9585EC1ADE9F2021ULL + 0xA4D9C9A03DCD05A0ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xCB54F6DE7D374AF7ULL + 0x81359F4E97FAE16EULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xA152C8BCE1D016A3ULL + 0xA9A7ADB1C3E30200ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xB8DF6C8A020B6C1BULL + 0xEE390B0CCAB516A4ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x984E97964692209BULL + 0xA4C2801179E38A39ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xA39B4A55D644D243ULL + 0xD0AB3FC689EBF103ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xE8EA8E929158E18BULL + 0xC892CEC6F7BF2002ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x93F1070D60245DE5ULL + 0xB7FED1BD5DA07F3EULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xBE721F90B24AE6EBULL + 0x90ABD0711179DFD2ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xC57A89C89930DB35ULL + 0x95A698CD8AB3440DULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xCC94B761EFFFB4C7ULL + 0xADF931D70B4F0EF7ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xC6AFE882516E1BB1ULL + 0xB8003F616CA56CBDULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xFA612F593C1795A5ULL + 0xD3DE446E1A31D2D6ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x9F28248504E0E8ABULL + 0xCEC4AD5F34473F3EULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xAAA3ADF799DE9A3BULL + 0x93C17BF151DCE952ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x9570A272869A6573ULL + 0x9DDAB121F505D639ULL);
    // GSeedRunSeed_B seed_loop_a (start)
    {
        // GSeedRunSeed_B seed_loop_a lane group
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneA, aExpandLaneC, aExpandLaneD, aInvestLaneA, aFireLaneD, aInvestLaneB, aFireLaneB, aOperationLaneA, aFireLaneC, aOperationLaneB, aOperationLaneC
        // write to: aInvestLaneA, aInvestLaneB, aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // seed_loop_a loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneA
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 880U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneB[((aIndex + 2007U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 2858U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4981U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((aIndex + 1762U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aIngress, 35U) + RotL64(aCarry, 3U)) ^ (RotL64(aPrevious, 48U) ^ RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterJ = (((aWandererJ + RotL64(aCross, 23U)) + 1142447269198373880U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordI;
            aOrbiterB = (((aWandererI + RotL64(aPrevious, 14U)) + RotL64(aCarry, 13U)) + 10581460640040336191U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = (((aWandererF + RotL64(aIngress, 35U)) + RotL64(aCarry, 51U)) + 14703062773878202900U) + aNonceWordG;
            aOrbiterE = (((aWandererG + RotL64(aScatter, 51U)) + RotL64(aCarry, 39U)) + 15737525756286914746U) + aNonceWordB;
            aOrbiterG = ((aWandererH + RotL64(aCross, 5U)) + 16178774478273186999U) + aNonceWordK;
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterB) + 2514897053906809160U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordN;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 13702496607592508464U) ^ aNonceWordC;
            aOrbiterI = RotL64((aOrbiterI * 16540143680974064057U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 18030885275418337965U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 5241783876161655984U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10970981186787227937U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 2807052676283587925U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 8022804576763271327U;
            aOrbiterE = RotL64((aOrbiterE * 11727096043219370577U), 5U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterI) + 15597099852232205860U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1]) + aNonceWordM;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 1538435607932096400U;
            aOrbiterG = RotL64((aOrbiterG * 7900752511710516981U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 11147868774413615365U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 9325213746830411568U;
            aOrbiterJ = RotL64((aOrbiterJ * 561819005818948769U), 37U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterJ, 5U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 47U));
            aIngress = aIngress + RotL64(aOrbiterI, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((((RotL64(aIngress, 37U) + RotL64(aOrbiterG, 21U)) + aOrbiterJ) + RotL64(aCarry, 23U)) + aNonceWordD) + aPhaseAWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterB, 11U)) + aOrbiterI) + aNonceWordJ);
            aWandererI = aWandererI + ((((RotL64(aScatter, 60U) + RotL64(aOrbiterB, 52U)) + aOrbiterE) + RotL64(aCarry, 39U)) + aNonceWordO);
            aWandererG = aWandererG ^ ((((RotL64(aCross, 29U) + RotL64(aOrbiterB, 43U)) + aOrbiterG) + aNonceWordP) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 19U) + RotL64(aOrbiterG, 29U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 13U));
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aInvestLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 2
        // ingress from: aInvestLaneA, aExpandLaneC, aFireLaneD
        // ingress directions: aInvestLaneA forward forced, aExpandLaneC forward forced, aFireLaneD forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneA[((aIndex + 10161U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((aIndex + 7971U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 10083U)) & S_BLOCK1], 12U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 7645U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 10881U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aIngress, 51U) ^ RotL64(aCarry, 38U)) + (RotL64(aCross, 21U) + RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterD = (((aWandererA + RotL64(aPrevious, 3U)) + RotL64(aCarry, 29U)) + 13714409587461539863U) + aNonceWordL;
            aOrbiterG = (aWandererK + RotL64(aIngress, 14U)) + 14101156723903265839U;
            aOrbiterC = ((aWandererD + RotL64(aCross, 29U)) + 7063754562895369001U) + aNonceWordJ;
            aOrbiterJ = (((aWandererG + RotL64(aScatter, 57U)) + RotL64(aCarry, 47U)) + 12320578575245519386U) + aPhaseAOrbiterAssignSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = (((aWandererI + RotL64(aCross, 37U)) + RotL64(aCarry, 13U)) + 11744826789631008424U) + aPhaseAOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 8744816505096675597U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 10405435520084528645U;
            aOrbiterC = RotL64((aOrbiterC * 13279521344071568023U), 39U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterJ) + 1463157688070683543U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1]) + aNonceWordO;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 12379603577919617703U) ^ aNonceWordA;
            aOrbiterA = RotL64((aOrbiterA * 14858901470015109311U), 13U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterA) + 1343439118031348146U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordD;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 16118850268070235540U;
            aOrbiterG = RotL64((aOrbiterG * 11184386483735388257U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 14116264435819277136U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterA) ^ 5251698273012432109U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterJ = RotL64((aOrbiterJ * 1495818611622063967U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 14806408656041403829U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 11569345414052398227U;
            aOrbiterD = RotL64((aOrbiterD * 9913158908301414861U), 21U);
            //
            aIngress = RotL64(aOrbiterG, 39U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 13U));
            aIngress = aIngress + RotL64(aOrbiterD, 24U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aIngress, 21U) + RotL64(aOrbiterJ, 29U)) + aOrbiterG);
            aWandererA = aWandererA ^ ((((RotL64(aPrevious, 35U) + aOrbiterD) + RotL64(aOrbiterG, 39U)) + aNonceWordE) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aScatter, 48U) + RotL64(aOrbiterA, 19U)) + aOrbiterD) + RotL64(aCarry, 11U)) + aNonceWordH);
            aWandererD = aWandererD ^ ((((RotL64(aCross, 11U) + aOrbiterA) + RotL64(aOrbiterC, 52U)) + aNonceWordM) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 3U) + aOrbiterJ) + RotL64(aOrbiterA, 11U)) + RotL64(aCarry, 47U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 53U));
            aCarry = aCarry + (RotL64(aWandererI, 34U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererA, 43U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aInvestLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_a loop 3
        // ingress from: aInvestLaneB, aExpandLaneD, aFireLaneB
        // ingress directions: aInvestLaneB forward forced, aExpandLaneD forward forced, aFireLaneB forward/backward random
        // cross from: aInvestLaneA, aExpandLaneB, aExpandLaneA
        // cross directions: aInvestLaneA backward forced, aExpandLaneB backward forced, aExpandLaneA backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneB[((aIndex + 12497U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneD[((aIndex + 12214U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 12327U)) & S_BLOCK1], 12U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 11042U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 11090U)) & S_BLOCK1], 10U));
            aCross ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 13427U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 24U) + RotL64(aPrevious, 11U)) ^ (RotL64(aIngress, 39U) + RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterJ = ((((aWandererC + RotL64(aPrevious, 41U)) + RotL64(aCarry, 41U)) + 18302975933754610273U) + aPhaseAOrbiterAssignSaltC[((aIndex + 8U)) & S_SALT1]) + aNonceWordH;
            aOrbiterB = (((aWandererE + RotL64(aCross, 11U)) + RotL64(aCarry, 53U)) + 16736972646771456082U) + aNonceWordP;
            aOrbiterI = ((aWandererD + RotL64(aIngress, 57U)) + 17389406266488137442U) + aNonceWordB;
            aOrbiterA = (((aWandererB + RotL64(aScatter, 3U)) + RotL64(aCarry, 5U)) + 5252511566486165539U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterE = ((aWandererJ + RotL64(aCross, 28U)) + 5730715427422747640U) + aNonceWordK;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 6412695646456045825U) + aNonceWordM;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 9539701605708994494U) ^ aNonceWordE;
            aOrbiterI = RotL64((aOrbiterI * 6511935168278632407U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 18355107116412945722U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 11735742491750132942U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 18129835093627763685U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 12363819388562658842U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 5861430292304371543U;
            aOrbiterJ = RotL64((aOrbiterJ * 12989055611235382695U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 15027487084595017708U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 7012850020745791926U;
            aOrbiterE = RotL64((aOrbiterE * 15952928839355613939U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 11904871669287886120U) + aNonceWordL;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 11199760114477343208U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7156374911847525867U), 53U);
            //
            aIngress = RotL64(aOrbiterI, 47U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 36U));
            aIngress = aIngress + RotL64(aOrbiterB, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterA, 47U)) + aOrbiterE) + RotL64(aCarry, 53U)) + aNonceWordC);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 57U) + aOrbiterE) + RotL64(aOrbiterI, 13U)) + aPhaseAWandererUpdateSaltF[((aIndex + 28U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 4U) + RotL64(aOrbiterI, 4U)) + aOrbiterB) + aNonceWordI);
            aWandererE = aWandererE ^ ((((RotL64(aCross, 27U) + RotL64(aOrbiterA, 35U)) + aOrbiterJ) + aNonceWordJ) + aPhaseAWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aIngress, 43U) + RotL64(aOrbiterJ, 27U)) + aOrbiterE) + RotL64(aCarry, 5U)) + aNonceWordA);
            //
            aCarry = aCarry + (RotL64(aWandererE, 60U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + RotL64(aWandererC, 19U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 4
        // ingress from: aOperationLaneA, aInvestLaneA, aFireLaneC
        // ingress directions: aOperationLaneA forward forced, aInvestLaneA forward forced, aFireLaneC forward/backward random
        // cross from: aInvestLaneB, aExpandLaneD, aExpandLaneC
        // cross directions: aInvestLaneB backward forced, aExpandLaneD backward forced, aExpandLaneC backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 21440U)) & S_BLOCK1], 44U) ^ RotL64(aInvestLaneA[((aIndex + 19950U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 19625U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 21751U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17195U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 19822U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 60U) ^ RotL64(aCross, 47U)) + (RotL64(aCarry, 11U) ^ RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterF = ((aWandererD + RotL64(aScatter, 47U)) + 3561491146322798260U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = (((aWandererH + RotL64(aPrevious, 58U)) + RotL64(aCarry, 47U)) + 7075025056181885339U) + aNonceWordH;
            aOrbiterB = (((aWandererB + RotL64(aCross, 3U)) + RotL64(aCarry, 35U)) + 9230910887904171613U) + aNonceWordK;
            aOrbiterH = (((aWandererF + RotL64(aIngress, 27U)) + RotL64(aCarry, 19U)) + 4119781172609908917U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 35U)) + 17155609083870983149U) + aNonceWordD;
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 2423018561430181695U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 12957280305617615744U) ^ aNonceWordL;
            aOrbiterB = RotL64((aOrbiterB * 17696410107705645631U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 2461704174772065813U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 7907123257849391997U;
            aOrbiterK = RotL64((aOrbiterK * 9416171962847312179U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 7257868138318960007U) + aNonceWordP;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 16425903703085702285U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7996935869077231999U), 29U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterH) + 2990822664594079467U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordE;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 5654819006718953817U) ^ aNonceWordM;
            aOrbiterF = RotL64((aOrbiterF * 4465096036756887801U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 12183676471235678779U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 15026286960542123922U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17199049329995315279U), 3U);
            //
            aIngress = RotL64(aOrbiterF, 47U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterJ, 20U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterH, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 27U) + aOrbiterJ) + RotL64(aOrbiterH, 3U));
            aWandererH = aWandererH + (((((RotL64(aScatter, 40U) + RotL64(aOrbiterH, 27U)) + aOrbiterF) + RotL64(aCarry, 21U)) + aNonceWordB) + aPhaseAWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterK, 46U)) + aOrbiterF) + aNonceWordG);
            aWandererF = aWandererF + (((((RotL64(aIngress, 5U) + aOrbiterB) + RotL64(aOrbiterF, 13U)) + RotL64(aCarry, 47U)) + aNonceWordN) + aPhaseAWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 51U) + aOrbiterJ) + RotL64(aOrbiterB, 57U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + (RotL64(aWandererF, 42U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererI, 3U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 22332U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((aIndex + 24699U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 26549U)) & S_BLOCK1], 38U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 24568U)) & S_BLOCK1], 39U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 24622U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 22245U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 19U) + RotL64(aIngress, 53U)) + (RotL64(aCarry, 4U) ^ RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterK = (((aWandererG + RotL64(aPrevious, 52U)) + RotL64(aCarry, 51U)) + 13880995121909552664U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = (((aWandererF + RotL64(aIngress, 27U)) + RotL64(aCarry, 19U)) + 14534942818069300546U) + aNonceWordB;
            aOrbiterI = (((aWandererJ + RotL64(aScatter, 37U)) + 17745973100886007133U) + aPhaseAOrbiterAssignSaltF[((aIndex + 20U)) & S_SALT1]) + aNonceWordF;
            aOrbiterC = (((aWandererA + RotL64(aCross, 11U)) + RotL64(aCarry, 37U)) + 2249805580771946872U) + aNonceWordG;
            aOrbiterD = (aWandererC + RotL64(aScatter, 19U)) + 4460116116396439410U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 3378683994078106878U) + aNonceWordL;
            aOrbiterI = (((aOrbiterI ^ aOrbiterK) ^ 3992996501048809123U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterI = RotL64((aOrbiterI * 13273544260537223797U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 12057768808864451929U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 4115362079047921130U;
            aOrbiterD = RotL64((aOrbiterD * 12263015903331031345U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 15297384955502206698U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 17623548383481905636U;
            aOrbiterC = RotL64((aOrbiterC * 7487278217901483685U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 3559213898000162417U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 12311605719074507335U;
            aOrbiterK = RotL64((aOrbiterK * 3982199462062847697U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 14807313864347885885U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 11222085523291581822U;
            aOrbiterG = RotL64((aOrbiterG * 12580941911587215653U), 57U);
            //
            aIngress = RotL64(aOrbiterI, 11U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 35U));
            aIngress = aIngress + RotL64(aOrbiterC, 58U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((((RotL64(aCross, 57U) + RotL64(aOrbiterC, 19U)) + aOrbiterK) + aNonceWordC) + aPhaseAWandererUpdateSaltE[((aIndex + 24U)) & S_SALT1]);
            aWandererF = aWandererF + (((((RotL64(aIngress, 21U) + RotL64(aOrbiterK, 5U)) + aOrbiterG) + RotL64(aCarry, 23U)) + aNonceWordA) + aPhaseAWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 6U) + aOrbiterG) + RotL64(aOrbiterD, 53U)) + aNonceWordI);
            aWandererC = aWandererC + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterK, 27U)) + aOrbiterD) + RotL64(aCarry, 5U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 29U) + aOrbiterI) + RotL64(aOrbiterD, 38U)) + aNonceWordJ);
            //
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererA);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + RotL64(aWandererG, 30U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 31946U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneA[((aIndex + 27824U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29714U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31325U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 31599U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 29232U)) & S_BLOCK1], 18U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 27U) ^ RotL64(aCross, 5U)) + (RotL64(aCarry, 40U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterK = ((aWandererH + RotL64(aIngress, 18U)) + 12311607308490066301U) + aNonceWordG;
            aOrbiterD = ((aWandererC + RotL64(aCross, 27U)) + 13100864684740679846U) + aNonceWordJ;
            aOrbiterI = (((aWandererD + RotL64(aScatter, 35U)) + RotL64(aCarry, 51U)) + 13697304189274329704U) + aNonceWordH;
            aOrbiterH = ((((aWandererK + RotL64(aPrevious, 51U)) + RotL64(aCarry, 11U)) + 9047976902871216732U) + aPhaseAOrbiterAssignSaltC[((aIndex + 28U)) & S_SALT1]) + aNonceWordN;
            aOrbiterA = (((aWandererI + RotL64(aCross, 43U)) + RotL64(aCarry, 39U)) + 2147897579538537888U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 2072444829390996142U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 2129307836981020908U;
            aOrbiterI = RotL64((aOrbiterI * 8065769537670939667U), 19U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterI) + 10663145333751112064U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1]) + aNonceWordB;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 15019844390503785459U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7442321463110790449U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 5460865577557928142U) + aNonceWordM;
            aOrbiterA = (((aOrbiterA ^ aOrbiterI) ^ 15806522559993224197U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterA = RotL64((aOrbiterA * 8722932687972240099U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 6361113778657833389U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 8306013884615042570U;
            aOrbiterK = RotL64((aOrbiterK * 8234258702656728667U), 41U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterK) + 4038420580499706912U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1]) + aNonceWordE;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 11908091484457158973U;
            aOrbiterD = RotL64((aOrbiterD * 3964111175645156719U), 3U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterH, 39U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + RotL64(aOrbiterI, 52U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterK, 19U)) + aOrbiterI) + aNonceWordO);
            aWandererH = aWandererH + ((((RotL64(aIngress, 26U) + aOrbiterK) + RotL64(aOrbiterH, 11U)) + RotL64(aCarry, 21U)) + aNonceWordC);
            aWandererI = aWandererI ^ (((RotL64(aCross, 53U) + aOrbiterH) + RotL64(aOrbiterA, 27U)) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aScatter, 5U) + aOrbiterA) + RotL64(aOrbiterD, 43U)) + RotL64(aCarry, 37U)) + aNonceWordA);
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterH, 56U)) + aOrbiterD) + aNonceWordP) + aPhaseAWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererH, 3U);
            aCarry = aCarry + RotL64(aIngress, 30U);
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

void TwistExpander_Soccer_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xB9B760294905BAABULL + 0xDD5EEDD9AA60BEFEULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xEEE429C88108A217ULL + 0xACE7B0825B4B319CULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x8E98EC402783DEE5ULL + 0x8125BE2F0FB1248CULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xD53A7D0D73F534B3ULL + 0x8B78C46B667ABED6ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xF66BBAF1084464DDULL + 0xB3907EB9FAEB10B3ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xAEC616D100D09E2BULL + 0xA8A97BBE395D742AULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xC3514F211F481035ULL + 0xDFEFDDE7BC0802A5ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xB211102AA05E6BBBULL + 0x810782D6D986BB8EULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xA5D04F3580A5D98BULL + 0xE0793862DE9586C6ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xD0275CE2E38948EDULL + 0xD60A8B483784972BULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x8AA23562302164F9ULL + 0x8E22947B31887511ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xCA296C2B73A1EFBBULL + 0xE647B3FBA75E3AA8ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xA5E7418EBC9D0A4DULL + 0xB448C67CCF741516ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xF1EAC25F2F6C2211ULL + 0x94F1F6FA0AD323B3ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xC0F968E3C1A7BB7DULL + 0xEACDC4039E0D8AB5ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xCD3EE6DC3152608BULL + 0x9455A99329312ECDULL);
    // GSeedRunSeed_C seed_loop_b (start)
    {
        // GSeedRunSeed_C seed_loop_b lane group
        // read from: aOperationLaneA, aOperationLaneB, aExpandLaneD, aOperationLaneC, aOperationLaneD, aExpandLaneB, aInvestLaneC, aExpandLaneA, aFireLaneC, aInvestLaneD, aFireLaneA, aWorkLaneA, aFireLaneB, aWorkLaneB, aFireLaneD, aWorkLaneC, aExpandLaneC
        // write to: aInvestLaneC, aInvestLaneD, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // seed_loop_b loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aExpandLaneD
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aExpandLaneD forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aExpandLaneB
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aExpandLaneB backward/forward random
        // write to: aInvestLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 1579U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((aIndex + 4803U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 3711U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 3652U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 1168U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aExpandLaneB[((aIndex + 4955U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aIngress, 3U) ^ RotL64(aCross, 53U)) ^ (RotL64(aPrevious, 19U) + RotL64(aCarry, 38U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterF = ((aWandererB + RotL64(aCross, 43U)) + RotL64(aCarry, 13U)) + 11698283336767769359U;
            aOrbiterG = (aWandererG + RotL64(aPrevious, 3U)) + 13297826354831483872U;
            aOrbiterH = (((aWandererI + RotL64(aScatter, 21U)) + RotL64(aCarry, 51U)) + 15254999058287530795U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = (((aWandererF + RotL64(aIngress, 56U)) + RotL64(aCarry, 21U)) + 17474166585085346567U) + aNonceWordN;
            aOrbiterD = (aWandererC + RotL64(aScatter, 47U)) + 15684783498452840289U;
            aOrbiterJ = (aWandererH + RotL64(aPrevious, 13U)) + 5061229733465216486U;
            aOrbiterK = (((aWandererE + RotL64(aIngress, 39U)) + 15370981279168377944U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordD;
            aOrbiterI = (aWandererK + RotL64(aCross, 27U)) + 17966672773619554092U;
            aOrbiterC = (aWandererD + RotL64(aScatter, 52U)) + 14685092893994491068U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 12798804186209406389U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 2848444181474221574U;
            aOrbiterH = RotL64((aOrbiterH * 13730480364920876877U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 8551142075919636146U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 8833198159158950723U;
            aOrbiterD = RotL64((aOrbiterD * 7650289040764974737U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 7351473160893666232U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterJ) ^ 14204899612487622222U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterK = RotL64((aOrbiterK * 6317485031956448029U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 7008985178526543258U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 13576796403863120356U) ^ aNonceWordC;
            aOrbiterJ = RotL64((aOrbiterJ * 13745839827679114077U), 19U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterI) + 5769784656937900699U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1]) + aNonceWordK;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 14075925808204936705U;
            aOrbiterF = RotL64((aOrbiterF * 5844894088757604713U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 17818667502858010896U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 16016922065572683130U;
            aOrbiterG = RotL64((aOrbiterG * 7525645833898085373U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 1582458237855075977U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 10830440354527138227U;
            aOrbiterE = RotL64((aOrbiterE * 10499386926982228251U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 10653964151654643772U) + aNonceWordO;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 11218475491129483859U;
            aOrbiterI = RotL64((aOrbiterI * 3338108067044357141U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 9863649760189649255U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 13790281439048354358U;
            aOrbiterC = RotL64((aOrbiterC * 4682098083538482849U), 35U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterJ, 27U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 50U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 19U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 43U));
            aIngress = aIngress + RotL64(aOrbiterI, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterE, 14U)) + aOrbiterD);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 47U) + aOrbiterG) + RotL64(aOrbiterF, 43U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 29U) + aOrbiterK) + RotL64(aOrbiterG, 39U)) + RotL64(aCarry, 35U)) + aNonceWordF);
            aWandererI = aWandererI ^ (((RotL64(aCross, 3U) + aOrbiterI) + RotL64(aOrbiterK, 47U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 22U) + aOrbiterH) + RotL64(aOrbiterC, 53U));
            aWandererF = aWandererF ^ ((((RotL64(aCross, 39U) + aOrbiterG) + RotL64(aOrbiterJ, 27U)) + aNonceWordA) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aIngress, 13U) + aOrbiterH) + RotL64(aOrbiterJ, 57U)) + RotL64(aCarry, 53U)) + aNonceWordI);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 43U) + aOrbiterE) + RotL64(aOrbiterI, 19U)) + aNonceWordB);
            aWandererG = aWandererG + ((RotL64(aIngress, 18U) + RotL64(aOrbiterH, 6U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererI);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 6U));
            aCarry = aCarry + (RotL64(aWandererB, 13U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererG, 19U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aInvestLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 2
        // ingress from: aInvestLaneC, aOperationLaneC, aOperationLaneD, aExpandLaneA
        // ingress directions: aInvestLaneC forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aExpandLaneA forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aFireLaneC
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aFireLaneC backward/forward random
        // write to: aInvestLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneC[((aIndex + 6593U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneC[((aIndex + 5591U)) & S_BLOCK1], 58U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 8094U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 7473U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 6028U)) & S_BLOCK1], 34U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 8134U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 6755U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aPrevious, 6U) ^ RotL64(aCarry, 41U)) ^ (RotL64(aIngress, 27U) + RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterI = ((aWandererB + RotL64(aCross, 29U)) + 12669015908335980355U) + aPhaseBOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = (aWandererH + RotL64(aPrevious, 5U)) + 5438715179868613192U;
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 58U)) + 13172104448184536460U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = (aWandererE + RotL64(aScatter, 13U)) + 13421421503244744803U;
            aOrbiterB = (aWandererA + RotL64(aIngress, 51U)) + 13327113302994856582U;
            aOrbiterC = (((aWandererD + RotL64(aScatter, 35U)) + RotL64(aCarry, 57U)) + 4671768205922454413U) + aNonceWordB;
            aOrbiterA = (((aWandererK + RotL64(aPrevious, 19U)) + RotL64(aCarry, 43U)) + 5355759962838579929U) + aNonceWordA;
            aOrbiterE = ((aWandererG + RotL64(aCross, 47U)) + RotL64(aCarry, 29U)) + 6691720614265406851U;
            aOrbiterD = (aWandererC + RotL64(aPrevious, 40U)) + 7063906424700911378U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 17328616394166672263U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 1542940602574207068U;
            aOrbiterF = RotL64((aOrbiterF * 8981679306319627975U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 7203866278803132454U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 993485696233139264U;
            aOrbiterC = RotL64((aOrbiterC * 11609009908810366447U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 15659679028507488331U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 18321361454094675842U;
            aOrbiterJ = RotL64((aOrbiterJ * 3966860765622641843U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 9633319822696783352U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 3496559332232402963U;
            aOrbiterI = RotL64((aOrbiterI * 7772060229838162977U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 1918349708324205526U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 7701088402761359134U;
            aOrbiterD = RotL64((aOrbiterD * 9649485438465644795U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 6006824348814439686U) + aNonceWordE;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 18088375375347012557U;
            aOrbiterG = RotL64((aOrbiterG * 12801082943086128385U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 12816533373478543584U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 17951880253818836433U;
            aOrbiterA = RotL64((aOrbiterA * 8935839101517220201U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 11311632024372748238U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 9891349164779752351U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11405973752233193209U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 711130292000437038U) + aNonceWordD;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 17818800917771709681U;
            aOrbiterE = RotL64((aOrbiterE * 10567029732245868263U), 23U);
            //
            aIngress = RotL64(aOrbiterB, 57U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterI, 13U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterG, 46U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterA, 5U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterC, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aPrevious, 43U) + aOrbiterE) + RotL64(aOrbiterC, 53U)) + RotL64(aCarry, 27U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 51U) + aOrbiterD) + RotL64(aOrbiterA, 11U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 47U) + aOrbiterF) + RotL64(aOrbiterI, 23U)) + RotL64(aCarry, 41U)) + aNonceWordP);
            aWandererD = aWandererD ^ ((RotL64(aCross, 11U) + aOrbiterG) + RotL64(aOrbiterI, 37U));
            aWandererB = aWandererB + ((((RotL64(aScatter, 60U) + aOrbiterJ) + RotL64(aOrbiterG, 48U)) + aNonceWordN) + aPhaseBWandererUpdateSaltB[((aIndex + 6U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterF, 43U)) + aOrbiterA) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 21U) + RotL64(aOrbiterE, 27U)) + aOrbiterB) + aNonceWordC);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterD, 3U)) + aOrbiterI);
            aWandererJ = aWandererJ + (((RotL64(aCross, 28U) + RotL64(aOrbiterG, 18U)) + aOrbiterB) + aNonceWordM);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 60U));
            aCarry = aCarry + (RotL64(aWandererH, 21U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererJ);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + RotL64(aWandererC, 14U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aInvestLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_b loop 3
        // ingress from: aInvestLaneD, aOperationLaneA, aFireLaneA
        // ingress directions: aInvestLaneD forward forced, aOperationLaneA forward forced, aFireLaneA forward/backward random
        // cross from: aInvestLaneC, aOperationLaneC
        // cross directions: aInvestLaneC backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneD[((aIndex + 13275U)) & S_BLOCK1], 22U) ^ RotL64(aOperationLaneA[((aIndex + 11876U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 15087U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 13871U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 12532U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aPrevious, 19U) + RotL64(aCarry, 54U)) ^ (RotL64(aCross, 3U) + RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterB = (aWandererG + RotL64(aScatter, 28U)) + 6069475454765660321U;
            aOrbiterI = (aWandererI + RotL64(aIngress, 5U)) + 11483704742497268068U;
            aOrbiterG = (((aWandererD + RotL64(aCross, 43U)) + RotL64(aCarry, 23U)) + 11055697447388986418U) + aNonceWordJ;
            aOrbiterD = (aWandererH + RotL64(aPrevious, 35U)) + 10897095046039997004U;
            aOrbiterH = (((aWandererE + RotL64(aScatter, 39U)) + RotL64(aCarry, 13U)) + 4731637118230457840U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = (aWandererB + RotL64(aIngress, 56U)) + 13855839187084986751U;
            aOrbiterE = ((aWandererF + RotL64(aCross, 11U)) + 5328208115460188239U) + aNonceWordI;
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 51U)) + 12479538544291412985U;
            aOrbiterK = (((aWandererJ + RotL64(aIngress, 21U)) + RotL64(aCarry, 47U)) + 10740165998792608231U) + aPhaseBOrbiterAssignSaltE[((aIndex + 14U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 6492798157284955373U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 13056825957483891921U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14882112110627751751U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 2068184064919194657U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 5656302738780746294U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16493021179127646345U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 11193756120230763294U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 17306750816837208999U;
            aOrbiterD = RotL64((aOrbiterD * 7949360041241439741U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 12952818800389361804U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 15380412293642628312U) ^ aNonceWordG;
            aOrbiterB = RotL64((aOrbiterB * 2914662289178925547U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 7706090204767242996U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 14598802276412649570U;
            aOrbiterJ = RotL64((aOrbiterJ * 4821408736292041399U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 17819762117328075515U) + aNonceWordA;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 6481384240915075101U;
            aOrbiterH = RotL64((aOrbiterH * 4836701121865783029U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 754936290510338717U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 15510875946573720154U;
            aOrbiterK = RotL64((aOrbiterK * 2994718968852184303U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 9245381722813944586U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 2629847912019726214U;
            aOrbiterE = RotL64((aOrbiterE * 6718795794951106961U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 3909987749797113773U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 9277056074757335265U;
            aOrbiterC = RotL64((aOrbiterC * 11580847505996697115U), 43U);
            //
            aIngress = RotL64(aOrbiterI, 11U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterE, 51U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 26U));
            aIngress = aIngress + RotL64(aOrbiterG, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aIngress, 23U) + RotL64(aOrbiterB, 36U)) + aOrbiterE) + aPhaseBWandererUpdateSaltE[((aIndex + 12U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aCross, 51U) + RotL64(aOrbiterK, 43U)) + aOrbiterE) + aNonceWordN);
            aWandererF = aWandererF + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterK, 19U)) + aOrbiterH) + RotL64(aCarry, 11U)) + aNonceWordM);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 58U) + RotL64(aOrbiterB, 13U)) + aOrbiterK);
            aWandererG = aWandererG + ((RotL64(aScatter, 13U) + RotL64(aOrbiterH, 23U)) + aOrbiterD);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 39U) + aOrbiterJ) + RotL64(aOrbiterG, 51U)) + aNonceWordK);
            aWandererE = aWandererE + (((RotL64(aPrevious, 43U) + aOrbiterC) + RotL64(aOrbiterE, 57U)) + RotL64(aCarry, 23U));
            aWandererC = aWandererC ^ ((((RotL64(aIngress, 6U) + aOrbiterI) + RotL64(aOrbiterC, 28U)) + aNonceWordC) + aPhaseBWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterD, 5U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 21U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (RotL64(aWandererC, 10U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 39U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererE, 57U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 18605U)) & S_BLOCK1], 51U) ^ RotL64(aInvestLaneC[((aIndex + 17018U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 18737U)) & S_BLOCK1], 34U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 19674U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 19744U)) & S_BLOCK1], 10U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aPrevious, 19U) + RotL64(aCross, 35U)) ^ (RotL64(aIngress, 5U) ^ RotL64(aCarry, 48U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterK = (((aWandererI + RotL64(aIngress, 39U)) + RotL64(aCarry, 53U)) + 13854738573712660276U) + aPhaseBOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 11U)) + 16835460633412286294U) + aNonceWordF;
            aOrbiterD = (aWandererF + RotL64(aCross, 52U)) + 6785859293758091931U;
            aOrbiterJ = (((aWandererB + RotL64(aScatter, 29U)) + RotL64(aCarry, 23U)) + 126317283127992659U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = (aWandererJ + RotL64(aCross, 43U)) + 7568963536291415413U;
            aOrbiterH = ((aWandererA + RotL64(aScatter, 5U)) + 12294016745653004819U) + aNonceWordH;
            aOrbiterG = ((aWandererD + RotL64(aIngress, 35U)) + 18269588932920281147U) + aNonceWordG;
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 23U)) + RotL64(aCarry, 37U)) + 5872406424994751026U;
            aOrbiterB = (aWandererE + RotL64(aCross, 56U)) + 7764434758831474129U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 4804168969415573371U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 959601763507651280U;
            aOrbiterD = RotL64((aOrbiterD * 4647396592804833217U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 9257644462479293048U) + aNonceWordM;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 14332699366894494579U;
            aOrbiterK = RotL64((aOrbiterK * 8829304078930625541U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 10487012596470786004U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 612729229562321440U;
            aOrbiterC = RotL64((aOrbiterC * 11380387280507726003U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 7845523921295625315U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 12742115479740024747U;
            aOrbiterA = RotL64((aOrbiterA * 15578543510683986421U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 10294667720904610944U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 14369711143154904567U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13753005602288309379U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 10918344717497681894U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 18136794828308636957U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 17899418637978002409U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 14378638206724886404U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 7077588188450008059U;
            aOrbiterF = RotL64((aOrbiterF * 485375960462924335U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 8941870012851971932U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 15242087859620352399U;
            aOrbiterJ = RotL64((aOrbiterJ * 4963002810455992839U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 10395280254030875387U) + aNonceWordI;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 6826595516076975980U;
            aOrbiterG = RotL64((aOrbiterG * 6198886240333178001U), 13U);
            //
            aIngress = RotL64(aOrbiterC, 51U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + (RotL64(aOrbiterG, 43U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterA, 20U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 56U) + RotL64(aOrbiterH, 13U)) + aOrbiterC) + aNonceWordE);
            aWandererI = aWandererI + ((RotL64(aCross, 37U) + aOrbiterJ) + RotL64(aOrbiterD, 53U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 51U) + aOrbiterH) + RotL64(aOrbiterJ, 57U)) + aNonceWordB);
            aWandererF = aWandererF + (((RotL64(aIngress, 43U) + aOrbiterG) + RotL64(aOrbiterK, 18U)) + aNonceWordK);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterA, 47U)) + aOrbiterB);
            aWandererA = aWandererA + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterJ, 27U)) + aOrbiterA) + RotL64(aCarry, 29U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterH, 23U)) + aOrbiterG) + aPhaseBWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            aWandererG = aWandererG + (((((RotL64(aIngress, 18U) + RotL64(aOrbiterJ, 5U)) + aOrbiterF) + RotL64(aCarry, 5U)) + aNonceWordC) + aPhaseBWandererUpdateSaltA[((aIndex + 26U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 47U) + aOrbiterB) + RotL64(aOrbiterG, 38U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererD);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + (RotL64(aWandererF, 60U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererI, 29U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_b loop 5
        // ingress from: aWorkLaneB, aInvestLaneD, aFireLaneD
        // ingress directions: aWorkLaneB forward forced, aInvestLaneD forward forced, aFireLaneD forward/backward random
        // cross from: aWorkLaneA, aInvestLaneC
        // cross directions: aWorkLaneA backward forced, aInvestLaneC backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 25282U)) & S_BLOCK1], 35U) ^ RotL64(aInvestLaneD[((aIndex + 25306U)) & S_BLOCK1], 58U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 22257U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24676U)) & S_BLOCK1], 3U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 26920U)) & S_BLOCK1], 18U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCarry, 3U)) ^ (RotL64(aCross, 26U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterG = ((aWandererI + RotL64(aScatter, 34U)) + RotL64(aCarry, 53U)) + 6916817163240024692U;
            aOrbiterF = (aWandererK + RotL64(aPrevious, 13U)) + 14554930751292077817U;
            aOrbiterB = ((aWandererH + RotL64(aIngress, 43U)) + RotL64(aCarry, 3U)) + 1098305064484336101U;
            aOrbiterD = ((aWandererJ + RotL64(aCross, 51U)) + RotL64(aCarry, 11U)) + 12192821172420471527U;
            aOrbiterK = ((aWandererF + RotL64(aScatter, 29U)) + 2435134991707318845U) + aNonceWordF;
            aOrbiterE = ((aWandererB + RotL64(aIngress, 60U)) + 1896745368738512624U) + aNonceWordO;
            aOrbiterI = ((aWandererE + RotL64(aCross, 5U)) + 1114996424222923873U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = (aWandererC + RotL64(aPrevious, 47U)) + 9839135798371512656U;
            aOrbiterH = ((aWandererD + RotL64(aScatter, 19U)) + 8037967239603177043U) + aPhaseBOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 15185468738487237432U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 4912098316394854543U;
            aOrbiterB = RotL64((aOrbiterB * 3072785550384399929U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 13142688607850380888U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterB) ^ 4507379759608945839U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterK = RotL64((aOrbiterK * 2989332387754215967U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 7299006009652289342U) + aNonceWordB;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 5390655277207053627U;
            aOrbiterI = RotL64((aOrbiterI * 10973744708856143715U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 6744737023577785725U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 15539737698867067285U;
            aOrbiterE = RotL64((aOrbiterE * 4686092035261336911U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 13329866734681377952U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 13284937458969166257U;
            aOrbiterH = RotL64((aOrbiterH * 3965985432462699445U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 8695002088915702168U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 3858059421620839286U;
            aOrbiterA = RotL64((aOrbiterA * 9559783727301092937U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 6609163873243179836U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 9416165620556710540U;
            aOrbiterG = RotL64((aOrbiterG * 240385043740268229U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 1578449067529000433U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterF) ^ 14309000104419489303U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterD = RotL64((aOrbiterD * 7599078306153684729U), 43U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterK) + 15785180680737461320U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1]) + aNonceWordM;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 10099222679918382021U;
            aOrbiterF = RotL64((aOrbiterF * 2012232597046182581U), 51U);
            //
            aIngress = RotL64(aOrbiterE, 47U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterF, 50U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterA, 13U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 5U));
            aIngress = aIngress + RotL64(aOrbiterG, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 48U) + aOrbiterE) + RotL64(aOrbiterB, 13U));
            aWandererE = aWandererE + (((RotL64(aIngress, 29U) + RotL64(aOrbiterB, 54U)) + aOrbiterD) + aNonceWordH);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterG, 39U)) + aOrbiterB);
            aWandererF = aWandererF + ((((RotL64(aCross, 23U) + RotL64(aOrbiterF, 19U)) + aOrbiterA) + RotL64(aCarry, 39U)) + aNonceWordD);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 35U) + aOrbiterG) + RotL64(aOrbiterA, 23U)) + aNonceWordK);
            aWandererH = aWandererH + ((RotL64(aCross, 3U) + aOrbiterH) + RotL64(aOrbiterK, 27U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 39U) + aOrbiterE) + RotL64(aOrbiterF, 43U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 19U) + aOrbiterI) + RotL64(aOrbiterD, 58U)) + RotL64(aCarry, 29U)) + aNonceWordI);
            aWandererB = aWandererB ^ (((RotL64(aCross, 12U) + aOrbiterK) + RotL64(aOrbiterE, 3U)) + aPhaseBWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 12U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + RotL64(aWandererC, 47U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 6
        // ingress from: aWorkLaneC, aWorkLaneA, aExpandLaneC
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aExpandLaneC forward/backward random
        // cross from: aWorkLaneB, aOperationLaneB
        // cross directions: aWorkLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 28787U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((aIndex + 31173U)) & S_BLOCK1], 60U));
            aIngress ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 27547U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30445U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneB[((aIndex + 29634U)) & S_BLOCK1], 18U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aPrevious, 37U) ^ RotL64(aCarry, 51U)) ^ (RotL64(aCross, 10U) + RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterD = (aWandererD + RotL64(aIngress, 56U)) + 6381335981879993247U;
            aOrbiterF = ((((aWandererB + RotL64(aPrevious, 47U)) + RotL64(aCarry, 3U)) + 15595429101600023172U) + aPhaseBOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterK = (aWandererE + RotL64(aScatter, 35U)) + 5449234297249826461U;
            aOrbiterB = (aWandererK + RotL64(aCross, 27U)) + 11213734849329731168U;
            aOrbiterH = (aWandererG + RotL64(aPrevious, 5U)) + 16438473952464514248U;
            aOrbiterG = ((aWandererC + RotL64(aCross, 39U)) + 7357872882115186976U) + aNonceWordF;
            aOrbiterE = (((aWandererH + RotL64(aIngress, 23U)) + RotL64(aCarry, 23U)) + 394402075160738643U) + aNonceWordP;
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 43U)) + 11112941985410283532U) + aPhaseBOrbiterAssignSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = (((aWandererJ + RotL64(aCross, 10U)) + RotL64(aCarry, 41U)) + 14955125011182736212U) + aNonceWordB;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 14770727009821304070U) + aNonceWordI;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 11286366598129204910U;
            aOrbiterK = RotL64((aOrbiterK * 15884310771003021989U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 7358400908565425780U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 15635109923749114761U;
            aOrbiterG = RotL64((aOrbiterG * 12415152149408700329U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 13826842523738623579U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 1072811298828325231U;
            aOrbiterE = RotL64((aOrbiterE * 9662800288646215083U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 4017334196009350776U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 8812213572751410831U) ^ aNonceWordC;
            aOrbiterD = RotL64((aOrbiterD * 12744171921566782795U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 6723457786170634403U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 9785583533999417673U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7776915427605471097U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 10265132640322153964U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 8435670887514808087U;
            aOrbiterC = RotL64((aOrbiterC * 2706263045620662131U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 4303823386961718326U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 4214384238167491037U) ^ aNonceWordE;
            aOrbiterF = RotL64((aOrbiterF * 8490707334221154005U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 8740835037840799136U) + aNonceWordH;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 5988815405391206280U;
            aOrbiterH = RotL64((aOrbiterH * 17838555472135715929U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 15539461383052981747U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 3743772525784217714U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6352086797545969187U), 39U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterJ, 10U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 19U));
            aIngress = aIngress + (RotL64(aOrbiterC, 47U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterG, 51U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterB, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aScatter, 34U) + RotL64(aOrbiterB, 3U)) + aOrbiterH);
            aWandererG = aWandererG ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterK, 56U)) + aOrbiterE);
            aWandererK = aWandererK + (((RotL64(aPrevious, 27U) + aOrbiterH) + RotL64(aOrbiterJ, 47U)) + aNonceWordD);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterJ, 19U)) + aOrbiterG);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 18U) + RotL64(aOrbiterD, 11U)) + aOrbiterF) + RotL64(aCarry, 43U)) + aNonceWordO);
            aWandererE = aWandererE ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterK, 23U)) + aOrbiterF);
            aWandererF = aWandererF + ((RotL64(aScatter, 47U) + aOrbiterK) + RotL64(aOrbiterB, 34U));
            aWandererJ = aWandererJ ^ ((((RotL64(aIngress, 57U) + RotL64(aOrbiterE, 43U)) + aOrbiterF) + aNonceWordN) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aCross, 53U) + aOrbiterC) + RotL64(aOrbiterF, 27U)) + RotL64(aCarry, 29U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 6U));
            aCarry = aCarry + RotL64(aWandererE, 23U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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

void TwistExpander_Soccer_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xC1284B6FAA1F1E85ULL + 0xA4E5808CA208F019ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xD842E83A591247E3ULL + 0xF1355EB44CC23EAAULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x92225141EB01A13FULL + 0xDCE84C167CC86020ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xBDB693D3F5397DFBULL + 0xF66FFBBC750C6AFCULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xF0E312DE38E796FBULL + 0xDE0968CD051A6A78ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xDEEECEF9CADC21BBULL + 0xB501F24E045012CCULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xEED93769AD04CFF1ULL + 0xFF5B38A8FEEB8E60ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x8ED4093755F02B31ULL + 0xD76F29B21DBB474BULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xAB3C36A61B5CA035ULL + 0x8EE07B6AB99A43D7ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xA8D34B7D1A93E5ADULL + 0x8E4EF4FBAE2D5F60ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xA861560E595618CFULL + 0xE8169EA77D3BD7D6ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xF19D283D8A8D0A63ULL + 0xA7F49114F682EA34ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x8918249FD37A9DD7ULL + 0xEA84ACAAD7921BF1ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xE763B69316874F77ULL + 0xDBCF8F3B44F7F3C5ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xA47003516B3AB4BBULL + 0xEAC536CF8239D423ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x9A326503A10E67F1ULL + 0xB2CB143A279C782CULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 3380U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneB[((aIndex + 4941U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 3515U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5191U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 3830U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 1737U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCross, 27U)) + (RotL64(aCarry, 6U) ^ RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterI = (((aWandererA + RotL64(aPrevious, 39U)) + 14157904117287696136U) + aPhaseDOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1]) + aNonceWordM;
            aOrbiterA = (((aWandererD + RotL64(aScatter, 23U)) + RotL64(aCarry, 19U)) + 7369512677371640676U) + aNonceWordB;
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 13U)) + 8411250745902073798U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = ((aWandererE + RotL64(aCross, 3U)) + RotL64(aCarry, 3U)) + 5002041814539710275U;
            aOrbiterE = (aWandererJ + RotL64(aScatter, 51U)) + 9538041410816283124U;
            aOrbiterC = ((aWandererK + RotL64(aCross, 57U)) + 5210700103927513061U) + aNonceWordE;
            aOrbiterH = (((aWandererH + RotL64(aIngress, 30U)) + RotL64(aCarry, 39U)) + 7600709399101287982U) + aNonceWordD;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 2366369466696580499U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 5544575244203019109U;
            aOrbiterJ = RotL64((aOrbiterJ * 16231219246786333057U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 8710073749110329779U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 15998211310115361630U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15275657696897688955U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 15354357553877376422U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 10657523549259276169U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13695239532898311073U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 10405750198355464768U) + aNonceWordK;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 3465819693133515142U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14678343718277562799U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 16724189641701408630U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 3484340153620198872U) ^ aNonceWordG;
            aOrbiterF = RotL64((aOrbiterF * 17247547677520703125U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 7420442404884871126U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 11138445997256757636U;
            aOrbiterE = RotL64((aOrbiterE * 11167543379937571127U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 1428191560884663125U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 16950093140800653985U;
            aOrbiterI = RotL64((aOrbiterI * 4423012306984814805U), 27U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterA, 41U);
            aIngress = aIngress + (RotL64(aOrbiterE, 47U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 60U));
            aIngress = aIngress + RotL64(aOrbiterF, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((((RotL64(aIngress, 3U) + aOrbiterF) + RotL64(aOrbiterC, 35U)) + aNonceWordI) + aPhaseDWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererK = aWandererK + (((((RotL64(aPrevious, 27U) + RotL64(aOrbiterJ, 5U)) + aOrbiterE) + RotL64(aCarry, 11U)) + aNonceWordF) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterA, 41U)) + aOrbiterH);
            aWandererF = aWandererF + ((RotL64(aCross, 19U) + aOrbiterC) + RotL64(aOrbiterE, 13U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterF, 19U)) + aOrbiterI) + aNonceWordO);
            aWandererE = aWandererE + ((((RotL64(aCross, 10U) + RotL64(aOrbiterC, 26U)) + aOrbiterI) + RotL64(aCarry, 27U)) + aNonceWordA);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterI, 51U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererK, 44U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererA);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + RotL64(aWandererJ, 11U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 6869U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneC[((aIndex + 7327U)) & S_BLOCK1], 29U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 9573U)) & S_BLOCK1], 43U) ^ RotL64(aInvestLaneC[((aIndex + 5934U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 9132U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 5574U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 7323U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aPrevious, 10U) + RotL64(aCross, 53U)) + (RotL64(aIngress, 29U) ^ RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterB = ((((aWandererK + RotL64(aCross, 47U)) + RotL64(aCarry, 35U)) + 18087125778766689269U) + aPhaseDOrbiterAssignSaltA[((aIndex + 8U)) & S_SALT1]) + aNonceWordG;
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 56U)) + 13710545066503235196U) + aNonceWordE;
            aOrbiterA = (((aWandererG + RotL64(aScatter, 3U)) + RotL64(aCarry, 53U)) + 1701939704736254645U) + aNonceWordI;
            aOrbiterK = ((aWandererB + RotL64(aIngress, 19U)) + RotL64(aCarry, 23U)) + 8064093611384019909U;
            aOrbiterD = (aWandererI + RotL64(aCross, 29U)) + 16623332751533885431U;
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 11U)) + 15590129153794910109U) + aPhaseDOrbiterAssignSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = (aWandererD + RotL64(aIngress, 37U)) + 7413312683079107383U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 4186064478651458810U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 5501191643940735954U;
            aOrbiterA = RotL64((aOrbiterA * 14254804649177125269U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 11064645242200570835U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 13825922087298055833U;
            aOrbiterD = RotL64((aOrbiterD * 7529317892716108867U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 5944980709887369970U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterJ) ^ 8181136916070569646U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterK = RotL64((aOrbiterK * 395183021205661827U), 43U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterB) + 15442336949157292482U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordD;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 11580554435240641337U;
            aOrbiterG = RotL64((aOrbiterG * 6654637892858767739U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 11240018128174598322U) + aNonceWordN;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 2027565596050777471U;
            aOrbiterE = RotL64((aOrbiterE * 18048186560314431815U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 16425887196883725233U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 16828683527588834095U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17746289103235902485U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 9923829146479008804U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 6669171007279929454U;
            aOrbiterJ = RotL64((aOrbiterJ * 681823450939955099U), 57U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterG, 3U);
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + RotL64(aOrbiterE, 30U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterD, 47U)) + aOrbiterE);
            aWandererK = aWandererK + (((RotL64(aIngress, 11U) + aOrbiterA) + RotL64(aOrbiterG, 11U)) + RotL64(aCarry, 23U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 43U) + aOrbiterD) + RotL64(aOrbiterB, 23U)) + aNonceWordB);
            aWandererD = aWandererD + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterK, 54U)) + aOrbiterJ) + RotL64(aCarry, 53U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 3U) + aOrbiterK) + RotL64(aOrbiterB, 29U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 20U) + RotL64(aOrbiterD, 5U)) + aOrbiterG) + aPhaseDWandererUpdateSaltC[((aIndex + 6U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 29U) + aOrbiterB) + RotL64(aOrbiterA, 39U)) + aNonceWordK);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererG);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 44U));
            aCarry = aCarry + RotL64(aWandererK, 37U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 16192U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneA[((aIndex + 11353U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 14797U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 14779U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneC[((aIndex + 11321U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCross, 42U)) ^ (RotL64(aCarry, 11U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterG = ((aWandererC + RotL64(aScatter, 29U)) + 1042610313571524121U) + aNonceWordD;
            aOrbiterI = ((aWandererH + RotL64(aCross, 58U)) + 3505725321008825582U) + aNonceWordC;
            aOrbiterD = ((aWandererD + RotL64(aIngress, 41U)) + RotL64(aCarry, 53U)) + 12584654563843782991U;
            aOrbiterA = (((aWandererG + RotL64(aPrevious, 23U)) + RotL64(aCarry, 23U)) + 6645399144515770935U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = ((aWandererI + RotL64(aScatter, 13U)) + 3608978423753715584U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = ((aWandererE + RotL64(aCross, 5U)) + RotL64(aCarry, 39U)) + 8089198857670370983U;
            aOrbiterK = (aWandererF + RotL64(aIngress, 51U)) + 15207251813516399879U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 9579268660105824516U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 16055044469473802812U) ^ aNonceWordN;
            aOrbiterD = RotL64((aOrbiterD * 2269649280637188723U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 583811872609805949U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 7027491967970873942U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12686754713465826139U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 18256061823189677508U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 12708429127816136937U;
            aOrbiterK = RotL64((aOrbiterK * 12593886633108075321U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 12169216645156306078U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 12694325407567795065U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3711789483877261899U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 16109994660203297503U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 4234704064165718913U;
            aOrbiterE = RotL64((aOrbiterE * 730085881474787681U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 14119541943554602878U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 8777769004811352951U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2556957257736134223U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 15642663488392549609U) + aNonceWordO;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 11594468530833278624U;
            aOrbiterI = RotL64((aOrbiterI * 6639306656361601143U), 3U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterC, 57U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 21U));
            aIngress = aIngress + RotL64(aOrbiterA, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((((RotL64(aPrevious, 53U) + RotL64(aOrbiterD, 19U)) + aOrbiterG) + RotL64(aCarry, 21U)) + aNonceWordI) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 34U) + aOrbiterI) + RotL64(aOrbiterE, 3U));
            aWandererG = aWandererG + ((((RotL64(aScatter, 47U) + RotL64(aOrbiterA, 54U)) + aOrbiterI) + RotL64(aCarry, 53U)) + aNonceWordA);
            aWandererH = aWandererH ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterK, 41U)) + aOrbiterE) + aPhaseDWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterG, 35U)) + aOrbiterI) + aNonceWordG);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterA, 29U)) + aOrbiterD);
            aWandererI = aWandererI + (((RotL64(aCross, 13U) + aOrbiterK) + RotL64(aOrbiterC, 11U)) + aNonceWordJ);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 37U));
            aCarry = aCarry + (RotL64(aWandererF, 10U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererG, 57U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 17442U)) & S_BLOCK1], 41U) ^ RotL64(aSnowLaneA[((aIndex + 20687U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 18623U)) & S_BLOCK1], 50U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 19927U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneD[((aIndex + 19739U)) & S_BLOCK1], 20U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 37U)) ^ (RotL64(aCross, 3U) + RotL64(aIngress, 54U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterF = (aWandererH + RotL64(aIngress, 58U)) + 17470880031634374199U;
            aOrbiterA = (((aWandererG + RotL64(aPrevious, 13U)) + 757565846006937746U) + aPhaseDOrbiterAssignSaltB[((aIndex + 20U)) & S_SALT1]) + aNonceWordC;
            aOrbiterC = ((aWandererD + RotL64(aScatter, 3U)) + 9419282475801345674U) + aNonceWordD;
            aOrbiterJ = ((aWandererA + RotL64(aCross, 27U)) + RotL64(aCarry, 41U)) + 2014248014107898196U;
            aOrbiterD = (aWandererC + RotL64(aPrevious, 41U)) + 15113928519446490441U;
            aOrbiterB = (((aWandererB + RotL64(aScatter, 35U)) + RotL64(aCarry, 11U)) + 7346126964886259935U) + aNonceWordA;
            aOrbiterI = ((((aWandererE + RotL64(aIngress, 19U)) + RotL64(aCarry, 27U)) + 5594123113093162359U) + aPhaseDOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1]) + aNonceWordE;
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 5659237263369402005U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 11565709683423969703U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16731289017588574671U), 51U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterJ) + 16782863743534856287U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordL;
            aOrbiterD = (((aOrbiterD ^ aOrbiterC) ^ 13499100900072115907U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterD = RotL64((aOrbiterD * 5567729598873214433U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 11414447651044205242U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 7545993795121430538U;
            aOrbiterB = RotL64((aOrbiterB * 10758488381206257261U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 11778229237616454988U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 2544793391976514665U) ^ aNonceWordM;
            aOrbiterA = RotL64((aOrbiterA * 4021060413798523299U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 9972156716619459164U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 17651030383827445664U;
            aOrbiterF = RotL64((aOrbiterF * 6742914240706775487U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 17439147296849134543U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 10021926927948343656U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 18139540407315440909U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 9309867875882669289U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 14951424455944346337U;
            aOrbiterJ = RotL64((aOrbiterJ * 10569523948169951309U), 11U);
            //
            aIngress = RotL64(aOrbiterB, 47U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 35U));
            aIngress = aIngress + RotL64(aOrbiterI, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aIngress, 60U) + aOrbiterJ) + RotL64(aOrbiterC, 5U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterC, 21U)) + aOrbiterD) + aNonceWordG);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 37U) + aOrbiterF) + RotL64(aOrbiterI, 47U)) + RotL64(aCarry, 11U)) + aNonceWordJ);
            aWandererA = aWandererA ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterC, 29U)) + aOrbiterF);
            aWandererH = aWandererH + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterB, 35U)) + aOrbiterD) + aNonceWordF);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 21U) + aOrbiterA) + RotL64(aOrbiterI, 11U));
            aWandererG = aWandererG + (((((RotL64(aCross, 11U) + RotL64(aOrbiterC, 58U)) + aOrbiterA) + RotL64(aCarry, 29U)) + aNonceWordH) + aPhaseDWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererA, 18U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererB, 13U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 22162U)) & S_BLOCK1], 13U) ^ RotL64(aSnowLaneB[((aIndex + 23970U)) & S_BLOCK1], 52U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 22247U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 22134U)) & S_BLOCK1], 41U) ^ RotL64(aSnowLaneA[((aIndex + 22268U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aIngress, 39U)) + (RotL64(aPrevious, 51U) ^ RotL64(aCarry, 6U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterF = ((aWandererH + RotL64(aIngress, 35U)) + RotL64(aCarry, 3U)) + 4739486756133131180U;
            aOrbiterH = (aWandererB + RotL64(aCross, 56U)) + 16089707555501328184U;
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 5U)) + RotL64(aCarry, 47U)) + 15310047330238536453U;
            aOrbiterC = (aWandererE + RotL64(aScatter, 19U)) + 7901411596386834955U;
            aOrbiterG = (((aWandererD + RotL64(aPrevious, 27U)) + 4357555491060982163U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterJ = ((((aWandererG + RotL64(aCross, 47U)) + RotL64(aCarry, 19U)) + 15667085602825720102U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordA;
            aOrbiterD = (aWandererJ + RotL64(aScatter, 11U)) + 8520635334382269253U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 1772509779231068315U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 15336170957886025677U;
            aOrbiterE = RotL64((aOrbiterE * 10996880551392077399U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 8628770833489469980U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 15469234024247246228U;
            aOrbiterG = RotL64((aOrbiterG * 8905266995119987947U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 10796430900884288328U) + aNonceWordO;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 10660110397012853289U;
            aOrbiterF = RotL64((aOrbiterF * 9140007610912037461U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 11202284258711214794U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterE) ^ 17509491802893182994U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterD = RotL64((aOrbiterD * 9329107599972703671U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 16212572740740103554U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 2190030203761579226U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3101886685668871045U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 12014337082293041909U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 3733531010807001506U;
            aOrbiterH = RotL64((aOrbiterH * 5797362244066062299U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 7100994963061975529U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 17837541162838600258U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8745987361678166553U), 21U);
            //
            aIngress = RotL64(aOrbiterJ, 10U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterE, 23U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 41U));
            aIngress = aIngress + RotL64(aOrbiterG, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 27U) + aOrbiterH) + RotL64(aOrbiterC, 41U));
            aWandererF = aWandererF + (((((RotL64(aCross, 11U) + aOrbiterD) + RotL64(aOrbiterE, 60U)) + RotL64(aCarry, 27U)) + aNonceWordE) + aPhaseDWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 60U) + aOrbiterF) + RotL64(aOrbiterE, 29U));
            aWandererE = aWandererE + (((RotL64(aIngress, 21U) + RotL64(aOrbiterH, 13U)) + aOrbiterJ) + aNonceWordC);
            aWandererH = aWandererH ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterF, 21U)) + aOrbiterH);
            aWandererB = aWandererB + (((((RotL64(aIngress, 3U) + RotL64(aOrbiterJ, 35U)) + aOrbiterC) + RotL64(aCarry, 3U)) + aNonceWordH) + aPhaseDWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 53U) + aOrbiterG) + RotL64(aOrbiterJ, 51U)) + aNonceWordK);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + (RotL64(aWandererB, 36U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 11U));
            aCarry = aCarry + RotL64(aWandererE, 53U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 31631U)) & S_BLOCK1], 37U) ^ RotL64(aInvestLaneA[((aIndex + 31266U)) & S_BLOCK1], 52U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 29839U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 29736U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((aIndex + 27515U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 3U) + RotL64(aIngress, 52U)) + (RotL64(aCross, 39U) ^ RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterB = ((aWandererD + RotL64(aCross, 11U)) + 964165145848253292U) + aNonceWordH;
            aOrbiterH = ((((aWandererH + RotL64(aIngress, 57U)) + RotL64(aCarry, 57U)) + 10645976767204934746U) + aPhaseDOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1]) + aNonceWordN;
            aOrbiterC = ((aWandererA + RotL64(aScatter, 51U)) + RotL64(aCarry, 5U)) + 8241612229349212650U;
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 35U)) + 4159196033256913347U;
            aOrbiterD = (((aWandererJ + RotL64(aCross, 41U)) + RotL64(aCarry, 29U)) + 7194795864620233507U) + aNonceWordA;
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 26U)) + 7638928444536778384U) + aNonceWordK;
            aOrbiterA = ((aWandererG + RotL64(aIngress, 3U)) + 11819105916503968109U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 18052213302858186237U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 8663575313970041570U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14131073322476609161U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 16644136720439299786U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 16930316530442679864U;
            aOrbiterH = RotL64((aOrbiterH * 2650922074098320859U), 37U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterE) + 16251107616988250593U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordG;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 7171986193609401665U) ^ aNonceWordI;
            aOrbiterA = RotL64((aOrbiterA * 3543709971414550087U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 17885046834432626644U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 7757069274715713557U;
            aOrbiterD = RotL64((aOrbiterD * 15766885299397923879U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 2212805322061155615U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 6368539134638838822U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13383744883433594259U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 5264326094252925613U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 6126345334815012938U;
            aOrbiterE = RotL64((aOrbiterE * 17180934809764905307U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 13826731214018407061U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 6621261811613643620U;
            aOrbiterJ = RotL64((aOrbiterJ * 2823596473596114171U), 11U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterE, 29U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 35U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 13U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterD, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aCross, 11U) + aOrbiterA) + RotL64(aOrbiterD, 35U)) + aPhaseDWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 43U) + RotL64(aOrbiterB, 28U)) + aOrbiterE) + RotL64(aCarry, 37U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterD, 5U)) + aOrbiterE) + aNonceWordJ);
            aWandererA = aWandererA + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterH, 53U)) + aOrbiterA) + RotL64(aCarry, 23U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 5U) + aOrbiterC) + RotL64(aOrbiterD, 19U)) + aNonceWordC);
            aWandererC = aWandererC + (((RotL64(aPrevious, 36U) + RotL64(aOrbiterE, 13U)) + aOrbiterA) + aPhaseDWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterJ, 47U)) + aOrbiterC) + aNonceWordP);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + (RotL64(aWandererC, 27U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 38U));
            aCarry = aCarry + RotL64(aWandererG, 11U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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

void TwistExpander_Soccer_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xB45807666F0E98C5ULL + 0xC60D1E260D959FD6ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xEA6247A4B1337995ULL + 0x942EDF4A8322E2DDULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x9F755A318577D2B3ULL + 0xC06A3D71B8E7AF8BULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xBD5A60EC2348BD45ULL + 0xFDDBB720AD24E396ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xCBC9D4A529449755ULL + 0xD9561487E325616BULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xED06D3238DCA8079ULL + 0x9740B0A08B4C30B5ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x9A67150C358F6537ULL + 0xCEC2F598A0D8742CULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xB67F0B10C86BC945ULL + 0xC3ECE69B7A453A37ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xBA02F64024A76C3DULL + 0xC0725B38B44036D1ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xD388BB657616E0A1ULL + 0x858C47306EE3AB00ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xCF1967B2486A30BFULL + 0xBE1D644FE0D8F60BULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xC13897D11B03FC3DULL + 0xD1FFA1CDFEEBCFDEULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xAD05FA31209D5027ULL + 0xDF878204131B5129ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xA6AA04E5F81621B9ULL + 0x9D4E3FE9ABC47CABULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x9A8CEAE227C1B2ADULL + 0xDE9FDAEAED1F1E53ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x850300E0B490B2A9ULL + 0xFDAB28A6B6F1041AULL);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 262U)) & S_BLOCK1], 35U) ^ RotL64(aInvestLaneB[((aIndex + 2803U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 774U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 3033U)) & S_BLOCK1], 43U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 4949U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 1303U)) & S_BLOCK1], 30U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCarry, 19U)) + (RotL64(aPrevious, 53U) ^ RotL64(aCross, 36U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterF = (aWandererJ + RotL64(aScatter, 23U)) + 11177787645248006236U;
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 29U)) + 3808340254579817169U) + aPhaseEOrbiterAssignSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterD = ((aWandererG + RotL64(aIngress, 58U)) + 828030667598518279U) + aNonceWordD;
            aOrbiterJ = (aWandererH + RotL64(aCross, 21U)) + 16177835921238398371U;
            aOrbiterA = (aWandererB + RotL64(aIngress, 5U)) + 5518747735458708741U;
            aOrbiterI = (aWandererD + RotL64(aScatter, 41U)) + 17346319082399995165U;
            aOrbiterK = ((aWandererF + RotL64(aCross, 46U)) + RotL64(aCarry, 57U)) + 6397156921893030937U;
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 53U)) + 15559381654710713582U) + aNonceWordB;
            aOrbiterG = (((aWandererE + RotL64(aIngress, 3U)) + RotL64(aCarry, 51U)) + 940404446491415088U) + aNonceWordK;
            aOrbiterB = (aWandererA + RotL64(aPrevious, 39U)) + 8047166032048732645U;
            aOrbiterC = (((aWandererI + RotL64(aScatter, 19U)) + RotL64(aCarry, 23U)) + 4688468645859470491U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 3710878044770337260U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 116343189456629220U;
            aOrbiterD = RotL64((aOrbiterD * 5637725064169289339U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 883908030159391659U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 18058691521694880482U;
            aOrbiterA = RotL64((aOrbiterA * 3132200449123497619U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 17521015077103586117U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 3668332225435714918U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12658899101297839881U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 12229480388278883300U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 16206524049491531816U;
            aOrbiterG = RotL64((aOrbiterG * 11122340196620859805U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 5743265849441077466U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 2812293020719282236U;
            aOrbiterH = RotL64((aOrbiterH * 8903956475200417109U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 13718364781538837074U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 861529717259766236U;
            aOrbiterJ = RotL64((aOrbiterJ * 17019744777211266685U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 4862687502126693872U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 7722024283321020761U;
            aOrbiterC = RotL64((aOrbiterC * 18086944039541060829U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 8205803118233399853U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 15130160926615050422U;
            aOrbiterF = RotL64((aOrbiterF * 1454552751453996765U), 57U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterA) + 667469191899263617U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1]) + aNonceWordN;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 18048970185163843471U) ^ aNonceWordO;
            aOrbiterB = RotL64((aOrbiterB * 1800698970568737425U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 508102841337488721U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 3803840516662727630U;
            aOrbiterK = RotL64((aOrbiterK * 8477778555284121637U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 17055028117762299436U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 11177787645248006236U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12457019014051206805U), 23U);
            //
            aIngress = RotL64(aOrbiterA, 51U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 43U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 12U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 35U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 41U));
            aIngress = aIngress + RotL64(aOrbiterK, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 3U) + aOrbiterD) + RotL64(aOrbiterE, 14U));
            aWandererK = aWandererK + (((RotL64(aIngress, 35U) + RotL64(aOrbiterI, 29U)) + aOrbiterD) + RotL64(aCarry, 5U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterH, 3U)) + aOrbiterF) + aPhaseEWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aScatter, 41U) + aOrbiterG) + RotL64(aOrbiterB, 11U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 47U) + aOrbiterH) + RotL64(aOrbiterC, 5U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 18U) + RotL64(aOrbiterG, 23U)) + aOrbiterJ) + RotL64(aCarry, 11U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 27U) + aOrbiterJ) + RotL64(aOrbiterD, 53U)) + aNonceWordE);
            aWandererD = aWandererD + ((RotL64(aScatter, 39U) + aOrbiterA) + RotL64(aOrbiterD, 19U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 43U) + aOrbiterI) + RotL64(aOrbiterG, 21U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 6U) + RotL64(aOrbiterB, 60U)) + aOrbiterK) + aNonceWordI);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterC, 57U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + (RotL64(aWandererF, 34U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererA, 18U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aFireLaneA[((aIndex + 7792U)) & S_BLOCK1], 5U) ^ RotL64(aInvestLaneC[((aIndex + 6398U)) & S_BLOCK1], 48U));
            aIngress ^= (RotL64(aInvestLaneD[((aIndex + 8266U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 5977U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 7831U)) & S_BLOCK1], 3U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 8494U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 6869U)) & S_BLOCK1], 22U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aPrevious, 23U)) ^ (RotL64(aIngress, 11U) + RotL64(aCarry, 40U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterE = ((aWandererB + RotL64(aIngress, 40U)) + 15813325389431304548U) + aNonceWordA;
            aOrbiterK = ((aWandererI + RotL64(aCross, 53U)) + 2223874171125403602U) + aNonceWordL;
            aOrbiterI = ((aWandererD + RotL64(aPrevious, 27U)) + RotL64(aCarry, 39U)) + 5510483568496824130U;
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 57U)) + 15474152493495661876U) + aPhaseEOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = (aWandererH + RotL64(aPrevious, 21U)) + 16846339705130829195U;
            aOrbiterH = (aWandererA + RotL64(aScatter, 13U)) + 1289670576865739669U;
            aOrbiterD = (aWandererK + RotL64(aIngress, 37U)) + 18017354919647006944U;
            aOrbiterB = (((aWandererC + RotL64(aCross, 11U)) + RotL64(aCarry, 43U)) + 8539685539928984921U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = ((aWandererG + RotL64(aScatter, 5U)) + 3333721400836704048U) + aNonceWordJ;
            aOrbiterA = (((aWandererF + RotL64(aIngress, 30U)) + RotL64(aCarry, 47U)) + 2261560416623815491U) + aNonceWordC;
            aOrbiterG = (aWandererJ + RotL64(aCross, 51U)) + 4377786131746816567U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 18047393176583722719U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 8184724021940434631U;
            aOrbiterI = RotL64((aOrbiterI * 9800116157750921119U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 10469895939183324807U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 14543391765109879223U;
            aOrbiterC = RotL64((aOrbiterC * 4817987697437667225U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 5757225781746158178U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterH) ^ 3539000495894022869U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterD = RotL64((aOrbiterD * 1032298408884695925U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 11288971092707065923U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 2761384065186568294U;
            aOrbiterF = RotL64((aOrbiterF * 3323838837427471051U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 7120580145300417101U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 6977246291769372866U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15170353875184253779U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 17625434527765525937U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 3299714663631376190U;
            aOrbiterK = RotL64((aOrbiterK * 6532628892760776767U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 10331889953489885250U) + aNonceWordO;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 8550932256881727932U;
            aOrbiterE = RotL64((aOrbiterE * 13085531621192583719U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 11151195711186126257U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 2552002192824926483U;
            aOrbiterA = RotL64((aOrbiterA * 9754056316698523849U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 8038115194286715268U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 16594489591573505305U;
            aOrbiterG = RotL64((aOrbiterG * 1241387574663818247U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 13476964484361081681U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 2136330439951908303U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12728359054660550527U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 231990686776499700U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 15813325389431304548U;
            aOrbiterB = RotL64((aOrbiterB * 9155088985405261637U), 41U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterK, 24U);
            aIngress = aIngress + (RotL64(aOrbiterA, 43U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 5U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 27U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 19U));
            aIngress = aIngress + RotL64(aOrbiterB, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterD, 53U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 43U) + RotL64(aOrbiterJ, 34U)) + aOrbiterG);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 4U) + RotL64(aOrbiterH, 37U)) + aOrbiterD) + aNonceWordP);
            aWandererE = aWandererE + (((RotL64(aCross, 19U) + RotL64(aOrbiterK, 13U)) + aOrbiterI) + aNonceWordH);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterK, 21U)) + aOrbiterG);
            aWandererK = aWandererK + (((RotL64(aPrevious, 53U) + aOrbiterC) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 29U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 11U) + aOrbiterH) + RotL64(aOrbiterF, 51U)) + aPhaseEWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 51U) + aOrbiterG) + RotL64(aOrbiterH, 29U)) + aNonceWordB);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 39U) + RotL64(aOrbiterA, 11U)) + aOrbiterK) + aNonceWordI);
            aWandererF = aWandererF + (((RotL64(aIngress, 29U) + aOrbiterE) + RotL64(aOrbiterG, 6U)) + RotL64(aCarry, 13U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 14U) + RotL64(aOrbiterK, 57U)) + aOrbiterH) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 46U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererK);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererI, 50U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 11202U)) & S_BLOCK1], 35U) ^ RotL64(aInvestLaneA[((aIndex + 13499U)) & S_BLOCK1], 18U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 13620U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 16082U)) & S_BLOCK1], 58U) ^ RotL64(aInvestLaneC[((aIndex + 12065U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 6U) ^ RotL64(aCross, 39U)) + (RotL64(aIngress, 27U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 37U)) + 9435962834163239322U;
            aOrbiterA = (aWandererC + RotL64(aIngress, 23U)) + 10524704356081318973U;
            aOrbiterJ = ((aWandererH + RotL64(aCross, 39U)) + 7403401305665208680U) + aNonceWordE;
            aOrbiterF = (((aWandererD + RotL64(aScatter, 41U)) + RotL64(aCarry, 47U)) + 7525414805023556493U) + aNonceWordC;
            aOrbiterE = ((aWandererA + RotL64(aIngress, 58U)) + 1116686470029070951U) + aPhaseEOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = (aWandererK + RotL64(aScatter, 27U)) + 13257612299137802420U;
            aOrbiterC = ((aWandererE + RotL64(aCross, 11U)) + 9181543003986598283U) + aPhaseEOrbiterAssignSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = (((aWandererF + RotL64(aPrevious, 19U)) + RotL64(aCarry, 3U)) + 9739384852307501107U) + aNonceWordB;
            aOrbiterB = (aWandererI + RotL64(aCross, 14U)) + 11308402900229016057U;
            aOrbiterD = ((aWandererB + RotL64(aIngress, 47U)) + RotL64(aCarry, 57U)) + 14935167593705272337U;
            aOrbiterH = ((aWandererG + RotL64(aScatter, 3U)) + 7171824007631943535U) + aNonceWordP;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 8068411284829563567U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 12350207458513447578U;
            aOrbiterJ = RotL64((aOrbiterJ * 813973258659041895U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 17039236343991574134U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 18291683592714999632U) ^ aNonceWordN;
            aOrbiterE = RotL64((aOrbiterE * 7771718817924840713U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 6239616841884430968U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 10604527977569876774U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6972820410084939637U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 1707724300671717658U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 3802268808625297647U;
            aOrbiterK = RotL64((aOrbiterK * 11296811630387191563U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 9423064323799920219U) + aNonceWordJ;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 242153923313096551U;
            aOrbiterB = RotL64((aOrbiterB * 12117679073775630197U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 945801070951928277U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 13094814302414492064U;
            aOrbiterC = RotL64((aOrbiterC * 14638176479878969775U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 7572219725951040117U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 16494986983782503428U;
            aOrbiterD = RotL64((aOrbiterD * 2739189408707408171U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 10949497978229234856U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 11219643352002119905U;
            aOrbiterH = RotL64((aOrbiterH * 16900635614259262873U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 14245670385849499678U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = (((aOrbiterG ^ aOrbiterI) ^ 13771155918235018585U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterG = RotL64((aOrbiterG * 14121731385133220921U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 15722734439532828816U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 11032710342174118366U;
            aOrbiterI = RotL64((aOrbiterI * 16096465375397981585U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 2071496769185495150U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 9435962834163239322U;
            aOrbiterA = RotL64((aOrbiterA * 10640995428633266765U), 11U);
            //
            aIngress = RotL64(aOrbiterG, 42U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterF, 29U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 35U));
            aIngress = aIngress + RotL64(aOrbiterJ, 58U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterC, 21U)) + aOrbiterE) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aCross, 35U) + RotL64(aOrbiterC, 39U)) + aOrbiterA);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterA, 48U)) + aOrbiterH);
            aWandererK = aWandererK + ((RotL64(aScatter, 54U) + RotL64(aOrbiterD, 51U)) + aOrbiterF);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterI, 43U));
            aWandererA = aWandererA + (((RotL64(aIngress, 13U) + aOrbiterK) + RotL64(aOrbiterB, 3U)) + aNonceWordI);
            aWandererD = aWandererD ^ ((((RotL64(aCross, 43U) + RotL64(aOrbiterE, 41U)) + aOrbiterH) + aNonceWordH) + aPhaseEWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 20U) + RotL64(aOrbiterG, 19U)) + aOrbiterI) + RotL64(aCarry, 29U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 39U) + aOrbiterI) + RotL64(aOrbiterJ, 34U));
            aWandererB = aWandererB + (((RotL64(aCross, 37U) + RotL64(aOrbiterK, 11U)) + aOrbiterD) + RotL64(aCarry, 19U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterB, 27U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + (RotL64(aWandererI, 18U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererK);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + RotL64(aWandererJ, 41U);
            aCarry = aCarry + RotL64(aIngress, 20U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 21308U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneA[((aIndex + 19045U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aWorkLaneD[((aIndex + 18682U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 16393U)) & S_BLOCK1], 3U) ^ RotL64(aInvestLaneD[((aIndex + 17044U)) & S_BLOCK1], 20U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aIngress, 3U)) + (RotL64(aPrevious, 41U) ^ RotL64(aCross, 24U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterC = ((aWandererD + RotL64(aScatter, 53U)) + 16160838483846078448U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 34U)) + 15404960896190227946U) + aNonceWordH;
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 23U)) + 16904160594024977199U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterG = ((aWandererF + RotL64(aCross, 57U)) + 17790460246821031802U) + aNonceWordJ;
            aOrbiterA = ((aWandererA + RotL64(aScatter, 19U)) + RotL64(aCarry, 51U)) + 16395168254086971959U;
            aOrbiterJ = ((aWandererH + RotL64(aPrevious, 51U)) + RotL64(aCarry, 19U)) + 7484373204039901786U;
            aOrbiterB = (aWandererI + RotL64(aIngress, 3U)) + 18026814691322913510U;
            aOrbiterE = ((aWandererG + RotL64(aCross, 47U)) + RotL64(aCarry, 43U)) + 15244817793136966450U;
            aOrbiterK = (aWandererC + RotL64(aPrevious, 21U)) + 5795491730356335666U;
            aOrbiterF = (aWandererB + RotL64(aScatter, 26U)) + 3163873518027801504U;
            aOrbiterI = (aWandererK + RotL64(aIngress, 39U)) + 2690791759507349172U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 17898067251167087906U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 8028010015006604239U;
            aOrbiterH = RotL64((aOrbiterH * 5601629670521300241U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 7304739457289910555U) + aNonceWordE;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 6476837815096530043U;
            aOrbiterJ = RotL64((aOrbiterJ * 16380545138701113267U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 14242499233467960602U) + aNonceWordC;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 17305645693017634630U;
            aOrbiterE = RotL64((aOrbiterE * 14442976693206929569U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 9772864059444171908U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 7897200728282156408U;
            aOrbiterB = RotL64((aOrbiterB * 816306719390807411U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 4890999319172950996U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 8165132649356094963U;
            aOrbiterA = RotL64((aOrbiterA * 17297706071263690189U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 9342923520083533265U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 7213639583505088067U;
            aOrbiterI = RotL64((aOrbiterI * 1349251979649428909U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 4079475132684197272U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 3350998022472827283U;
            aOrbiterG = RotL64((aOrbiterG * 948841791460066265U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 2479140576609216238U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 7703147534931674972U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11419116495223970801U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 9050277787914448469U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 13295888852307317371U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3027097172772140975U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 15380254190549884741U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 17653690414528791774U) ^ aNonceWordB;
            aOrbiterF = RotL64((aOrbiterF * 15923958179714368315U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 6825072759468337036U) + aNonceWordF;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 16160838483846078448U;
            aOrbiterC = RotL64((aOrbiterC * 11690325563580492415U), 11U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterJ, 34U);
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterB, 11U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 27U));
            aIngress = aIngress + (RotL64(aOrbiterC, 36U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterD, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aIngress, 6U) + aOrbiterH) + RotL64(aOrbiterA, 53U)) + RotL64(aCarry, 47U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 51U) + aOrbiterJ) + RotL64(aOrbiterF, 23U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 37U) + aOrbiterJ) + RotL64(aOrbiterK, 47U)) + aNonceWordA);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterI, 13U)) + aOrbiterA);
            aWandererH = aWandererH + (((RotL64(aCross, 28U) + aOrbiterK) + RotL64(aOrbiterC, 20U)) + RotL64(aCarry, 39U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterG, 41U)) + aOrbiterD) + aPhaseEWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aIngress, 41U) + RotL64(aOrbiterE, 51U)) + aOrbiterG);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 39U) + aOrbiterB) + RotL64(aOrbiterF, 29U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterD, 39U)) + aOrbiterC);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 3U) + aOrbiterK) + RotL64(aOrbiterD, 18U)) + aNonceWordO);
            aWandererD = aWandererD + (((RotL64(aCross, 57U) + RotL64(aOrbiterI, 43U)) + aOrbiterK) + aPhaseEWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 21U));
            aCarry = aCarry + (RotL64(aWandererB, 46U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 53U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererG);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + RotL64(aWandererE, 43U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 23124U)) & S_BLOCK1], 47U) ^ RotL64(aFireLaneB[((aIndex + 25015U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 22491U)) & S_BLOCK1], 26U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 21980U)) & S_BLOCK1], 53U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 27118U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aInvestLaneA[((aIndex + 25908U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aIngress, 41U) ^ RotL64(aCross, 12U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterB = (aWandererA + RotL64(aScatter, 29U)) + 7270044678408187242U;
            aOrbiterC = (((aWandererB + RotL64(aIngress, 19U)) + 10192278965379756766U) + aPhaseEOrbiterAssignSaltA[((aIndex + 27U)) & S_SALT1]) + aNonceWordO;
            aOrbiterD = ((aWandererD + RotL64(aCross, 52U)) + 17568666746676060748U) + aNonceWordK;
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 43U)) + 14312927531124963037U) + aNonceWordI;
            aOrbiterI = (aWandererK + RotL64(aIngress, 3U)) + 9825825726152087706U;
            aOrbiterA = (aWandererG + RotL64(aScatter, 27U)) + 9696778570255265896U;
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 39U)) + RotL64(aCarry, 5U)) + 17657841352013417228U;
            aOrbiterE = ((aWandererJ + RotL64(aCross, 41U)) + RotL64(aCarry, 43U)) + 16207815085909628439U;
            aOrbiterH = ((((aWandererC + RotL64(aScatter, 5U)) + RotL64(aCarry, 51U)) + 1752979206374514227U) + aPhaseEOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1]) + aNonceWordH;
            aOrbiterJ = (aWandererE + RotL64(aPrevious, 24U)) + 10456310689643905854U;
            aOrbiterK = (aWandererF + RotL64(aIngress, 47U)) + 16127830548663742550U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 2940917376003930842U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 7353596864777649953U) ^ aNonceWordL;
            aOrbiterD = RotL64((aOrbiterD * 7499468723171042005U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 12725092740446150705U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 5791296650856037010U;
            aOrbiterA = RotL64((aOrbiterA * 760379251950502133U), 5U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterD) + 1200130368046206150U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1]) + aNonceWordF;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 16689604428598558547U;
            aOrbiterE = RotL64((aOrbiterE * 13815324235939996623U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 14359561591103730856U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 3975025843599045263U;
            aOrbiterH = RotL64((aOrbiterH * 5025047888533298617U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 14017901732955607601U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 10431526786489555196U;
            aOrbiterJ = RotL64((aOrbiterJ * 10181915874476132407U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 7320527073559849223U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 15333411223710709907U;
            aOrbiterB = RotL64((aOrbiterB * 3488684905528068775U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 14302474063321663801U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 2104154521019935187U;
            aOrbiterG = RotL64((aOrbiterG * 12944382959742278055U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 5167600586916325228U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 4566823109447208716U;
            aOrbiterK = RotL64((aOrbiterK * 9997799807454267443U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 12475580453805083495U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 15461491763911887974U;
            aOrbiterC = RotL64((aOrbiterC * 13548865386159287481U), 47U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterK) + 11000532703581114393U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordE;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 7815822789941347770U;
            aOrbiterI = RotL64((aOrbiterI * 1476638214324946775U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 2166336159928211562U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 7270044678408187242U;
            aOrbiterF = RotL64((aOrbiterF * 10648564933168714815U), 19U);
            //
            aIngress = RotL64(aOrbiterJ, 51U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 23U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 54U));
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterA, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aPrevious, 3U) + aOrbiterI) + RotL64(aOrbiterD, 44U)) + RotL64(aCarry, 57U)) + aNonceWordJ);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 18U) + aOrbiterI) + RotL64(aOrbiterC, 23U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 5U) + RotL64(aOrbiterE, 21U)) + aOrbiterA);
            aWandererE = aWandererE ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterF, 5U)) + aOrbiterH);
            aWandererC = aWandererC + ((((RotL64(aIngress, 27U) + RotL64(aOrbiterH, 3U)) + aOrbiterG) + RotL64(aCarry, 51U)) + aPhaseEWandererUpdateSaltF[((aIndex + 4U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterE, 52U)) + aOrbiterH) + aPhaseEWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterJ, 47U)) + aOrbiterB);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 35U) + aOrbiterI) + RotL64(aOrbiterJ, 37U)) + aNonceWordC);
            aWandererK = aWandererK + ((RotL64(aCross, 48U) + aOrbiterF) + RotL64(aOrbiterA, 13U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 23U) + aOrbiterK) + RotL64(aOrbiterB, 11U));
            aWandererA = aWandererA + ((RotL64(aScatter, 53U) + RotL64(aOrbiterE, 35U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + (RotL64(aWandererC, 18U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererI);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + RotL64(aWandererF, 26U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 32485U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneA[((aIndex + 27691U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 27457U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28371U)) & S_BLOCK1], 6U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 30020U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCross, 21U) + RotL64(aIngress, 3U)) + (RotL64(aCarry, 36U) ^ RotL64(aPrevious, 51U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterC = ((((aWandererA + RotL64(aIngress, 5U)) + RotL64(aCarry, 23U)) + 1087148170018530502U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordG;
            aOrbiterI = ((aWandererC + RotL64(aScatter, 27U)) + 15530846874509311414U) + aNonceWordI;
            aOrbiterE = (aWandererG + RotL64(aPrevious, 37U)) + 16987358651515511212U;
            aOrbiterB = (aWandererB + RotL64(aCross, 21U)) + 12504143181007924259U;
            aOrbiterJ = (aWandererF + RotL64(aScatter, 50U)) + 393322117322732418U;
            aOrbiterA = (aWandererI + RotL64(aIngress, 43U)) + 14325937299241887166U;
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 39U)) + RotL64(aCarry, 51U)) + 9395262907017475742U;
            aOrbiterG = ((aWandererH + RotL64(aCross, 11U)) + 13658510441418344769U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = (aWandererJ + RotL64(aPrevious, 53U)) + 6410754322737005336U;
            aOrbiterF = (aWandererD + RotL64(aIngress, 24U)) + 9257290738538818434U;
            aOrbiterK = ((aWandererE + RotL64(aScatter, 35U)) + RotL64(aCarry, 39U)) + 7489828960857692286U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 4118778591214588387U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 16619215231168796563U;
            aOrbiterE = RotL64((aOrbiterE * 14876884956536265157U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 11326283811003573430U) + aNonceWordL;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 1865401866017614604U;
            aOrbiterI = RotL64((aOrbiterI * 8378326058282460073U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 670150121105733604U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 1499331510641068749U;
            aOrbiterG = RotL64((aOrbiterG * 16623742535540383107U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 1116410848560838532U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 2696841341036281779U;
            aOrbiterJ = RotL64((aOrbiterJ * 9598953298074904869U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 5487352391229549881U) + aNonceWordH;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 12008243050943342979U;
            aOrbiterD = RotL64((aOrbiterD * 9087261224804582459U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 552859665927882960U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 8426942688524814473U;
            aOrbiterH = RotL64((aOrbiterH * 10916963622695549105U), 37U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterB) + 1613287981244830815U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1]) + aNonceWordB;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 15592897923468694288U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6600750586743893303U), 29U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterC) + 7629853970631002676U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1]) + aNonceWordK;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 13778028957247561272U;
            aOrbiterK = RotL64((aOrbiterK * 4063798788229605659U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 2932956928094332652U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 14855524972646900872U;
            aOrbiterF = RotL64((aOrbiterF * 9546042275547649745U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 11071597794692793784U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 6327727700942234552U;
            aOrbiterA = RotL64((aOrbiterA * 15301120263944789797U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 5147576281502110428U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 1087148170018530502U;
            aOrbiterB = RotL64((aOrbiterB * 18045084130531645749U), 13U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterA, 47U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 18U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 51U));
            aIngress = aIngress + (RotL64(aOrbiterG, 37U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterD, 41U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterC, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aCross, 24U) + aOrbiterI) + RotL64(aOrbiterA, 54U)) + aNonceWordN);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 39U) + aOrbiterK) + RotL64(aOrbiterE, 13U)) + RotL64(aCarry, 35U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 13U) + aOrbiterK) + RotL64(aOrbiterJ, 23U)) + aPhaseEWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 37U) + RotL64(aOrbiterC, 5U)) + aOrbiterA) + RotL64(aCarry, 13U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterA, 57U)) + aOrbiterF);
            aWandererH = aWandererH + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterB, 39U)) + aOrbiterK);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 19U) + aOrbiterF) + RotL64(aOrbiterB, 48U));
            aWandererC = aWandererC + (((RotL64(aCross, 21U) + RotL64(aOrbiterG, 11U)) + aOrbiterE) + aNonceWordA);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterH, 35U)) + aOrbiterJ) + aNonceWordM);
            aWandererD = aWandererD + (((RotL64(aCross, 58U) + RotL64(aOrbiterG, 43U)) + aOrbiterA) + aPhaseEWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 43U) + aOrbiterD) + RotL64(aOrbiterG, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererB, 18U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + RotL64(aWandererE, 56U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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

void TwistExpander_Soccer_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x975D0F60A958F079ULL + 0xBA35CA7CA039551EULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x8ABF030A545D909FULL + 0xEA5DACF7B60F6C06ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x9D3458FA797F2D45ULL + 0xC44BBEC491D440D4ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xD2CC3138174E20BFULL + 0xFEC26BDA8F48E9B5ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xF0A847737735E799ULL + 0xBBCCB32366074F00ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xD814776D55F65ED5ULL + 0xA4000426B3AAB12DULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x912F7B1F563BB20FULL + 0x8BBB732388D2499DULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xF000370275A5D62FULL + 0xA9CA71C49844B2D9ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xB8844A981DFE46FBULL + 0xB8E87FA8914A97E4ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xDF0C198DC8264255ULL + 0xD5ABE99E77939363ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xE5354DF22636F533ULL + 0xA9813FF6DC09B309ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x8800F3E7938EC433ULL + 0xDF1538A154E3EF8AULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x9E5820B0343C16D9ULL + 0x905F00A06516265EULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xBE8F0F9D630105B5ULL + 0x8411970D1B3A6CADULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xF5EC8CB71F6283D9ULL + 0xC455F47749A2690AULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xADB29B8E10F2BA8FULL + 0xEEBD5A630FDB96EBULL);
    // GSeedRunSeed_F seed_loop_f (start)
    {
        // GSeedRunSeed_F seed_loop_f lane group
        // read from: aOperationLaneA, aOperationLaneB, aWorkLaneC, aOperationLaneC, aOperationLaneD, aSnowLaneB, aSnowLaneC, aSnowLaneA, aInvestLaneB, aSnowLaneD, aInvestLaneA, aExpandLaneA, aWorkLaneD, aExpandLaneB, aInvestLaneD, aExpandLaneC, aInvestLaneC
        // write to: aSnowLaneC, aSnowLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_f loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aWorkLaneC
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aWorkLaneC forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aSnowLaneB
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aSnowLaneB backward/forward random
        // write to: aSnowLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 818U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((aIndex + 1305U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 1159U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 526U)) & S_BLOCK1], 20U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 4319U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aSnowLaneB[((aIndex + 3191U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aIngress, 35U) + RotL64(aCarry, 23U)) + (RotL64(aCross, 56U) ^ RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterF = (aWandererD + RotL64(aScatter, 57U)) + 3248574644570178787U;
            aOrbiterE = ((aWandererB + RotL64(aCross, 47U)) + 4506961512959200024U) + aNonceWordG;
            aOrbiterC = ((aWandererI + RotL64(aIngress, 14U)) + 8423739774540738590U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 5U)) + 6593975869641735337U;
            aOrbiterI = (aWandererA + RotL64(aScatter, 53U)) + 16441716090557369103U;
            aOrbiterB = (((aWandererF + RotL64(aPrevious, 39U)) + RotL64(aCarry, 11U)) + 7936601450453207914U) + aNonceWordL;
            aOrbiterA = ((aWandererG + RotL64(aIngress, 27U)) + RotL64(aCarry, 21U)) + 13333752583560167065U;
            aOrbiterH = (((aWandererE + RotL64(aCross, 34U)) + RotL64(aCarry, 41U)) + 8013703284795432973U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 23U)) + 2349852779887439236U) + aNonceWordC;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 5318539364763284138U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 11450957608502944376U) ^ aNonceWordB;
            aOrbiterC = RotL64((aOrbiterC * 1957880366707810635U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 9058992558327552687U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 632095686920230926U;
            aOrbiterE = RotL64((aOrbiterE * 12460364388358520799U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 14734218428913777098U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 16344357661370784442U;
            aOrbiterI = RotL64((aOrbiterI * 15049472842002138369U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 2981145363531184308U) + aNonceWordK;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 14176472085175714494U;
            aOrbiterH = RotL64((aOrbiterH * 2584623327412130939U), 53U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterJ) + 11198457590069700889U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1]) + aNonceWordA;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 952584436750426828U;
            aOrbiterF = RotL64((aOrbiterF * 1165713888651280355U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 4311591763498985972U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 16194341833989936369U;
            aOrbiterA = RotL64((aOrbiterA * 9997934560195932575U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 7560794022401107431U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 10683789740265711603U;
            aOrbiterK = RotL64((aOrbiterK * 15637823045351977883U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 11614366395125937178U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 10750771385100564416U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4987921274272444283U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 2934697034132204529U) + aNonceWordH;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 4646873794658020363U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10555456865641580175U), 19U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterK, 6U);
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterH, 23U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterI, 11U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterE, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aScatter, 39U) + RotL64(aOrbiterI, 48U)) + aOrbiterC);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 13U) + aOrbiterH) + RotL64(aOrbiterE, 13U));
            aWandererB = aWandererB + ((((RotL64(aCross, 18U) + RotL64(aOrbiterB, 53U)) + aOrbiterC) + aNonceWordF) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterF, 23U)) + aOrbiterC);
            aWandererG = aWandererG + ((((RotL64(aCross, 29U) + RotL64(aOrbiterJ, 57U)) + aOrbiterH) + RotL64(aCarry, 43U)) + aNonceWordP);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 57U) + aOrbiterJ) + RotL64(aOrbiterB, 41U));
            aWandererK = aWandererK + ((RotL64(aIngress, 44U) + aOrbiterK) + RotL64(aOrbiterA, 4U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 53U) + aOrbiterH) + RotL64(aOrbiterF, 29U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 3U) + RotL64(aOrbiterI, 37U)) + aOrbiterA) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererA);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 44U));
            aCarry = aCarry + RotL64(aWandererI, 11U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aSnowLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 2
        // ingress from: aSnowLaneC, aOperationLaneC, aOperationLaneD, aSnowLaneA
        // ingress directions: aSnowLaneC forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aSnowLaneA forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aInvestLaneB
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aInvestLaneB backward/forward random
        // write to: aSnowLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneC[((aIndex + 8434U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneC[((aIndex + 5811U)) & S_BLOCK1], 27U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 7649U)) & S_BLOCK1], 41U) ^ RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 6984U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 9572U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 7410U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 9154U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aPrevious, 39U)) ^ (RotL64(aIngress, 27U) + RotL64(aCarry, 54U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterC = ((aWandererD + RotL64(aScatter, 35U)) + RotL64(aCarry, 5U)) + 9023059520606551446U;
            aOrbiterE = ((aWandererA + RotL64(aCross, 47U)) + 662441755115638133U) + aNonceWordI;
            aOrbiterG = ((aWandererK + RotL64(aIngress, 28U)) + RotL64(aCarry, 23U)) + 16957253361196144712U;
            aOrbiterF = (((aWandererB + RotL64(aPrevious, 39U)) + 7840955025765308605U) + aPhaseFOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1]) + aNonceWordB;
            aOrbiterJ = (aWandererF + RotL64(aCross, 23U)) + 346855809270395799U;
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 43U)) + 16099139781586668343U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = (aWandererI + RotL64(aScatter, 19U)) + 3706457327118322098U;
            aOrbiterI = ((aWandererC + RotL64(aIngress, 14U)) + 12166825885547622870U) + aNonceWordE;
            aOrbiterH = (((aWandererH + RotL64(aCross, 51U)) + RotL64(aCarry, 57U)) + 7792658665720344200U) + aNonceWordK;
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 7128477606152986326U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 11116533962780290084U) ^ aNonceWordF;
            aOrbiterG = RotL64((aOrbiterG * 11993485572912492297U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 10443889548568288532U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 4402387036946561017U;
            aOrbiterC = RotL64((aOrbiterC * 9032964741841833277U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 13002706161178447654U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 13929727277530310708U;
            aOrbiterD = RotL64((aOrbiterD * 7005639090871200285U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 10949073760696935106U) + aNonceWordC;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 15405923432006783533U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17989565878445202495U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 18096057968822208905U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = (((aOrbiterE ^ aOrbiterJ) ^ 3032155040484574973U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterE = RotL64((aOrbiterE * 448597307502544605U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 17462076466907467134U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 15471015427013701406U;
            aOrbiterJ = RotL64((aOrbiterJ * 6113474000571976139U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 3549031751266594344U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 14243218483842508113U) ^ aNonceWordD;
            aOrbiterI = RotL64((aOrbiterI * 9041601306479302047U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 5803147589312920032U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 5549470512227427855U;
            aOrbiterF = RotL64((aOrbiterF * 12592362489263862879U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 10076661824293832189U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 3196799148974716550U;
            aOrbiterH = RotL64((aOrbiterH * 8183276968961467775U), 27U);
            //
            aIngress = RotL64(aOrbiterJ, 43U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 24U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 19U));
            aIngress = aIngress + (RotL64(aOrbiterK, 5U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterC, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterH, 43U)) + aOrbiterI);
            aWandererA = aWandererA + ((((RotL64(aIngress, 13U) + RotL64(aOrbiterD, 39U)) + aOrbiterH) + RotL64(aCarry, 5U)) + aNonceWordP);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 6U) + RotL64(aOrbiterF, 14U)) + aOrbiterC);
            aWandererF = aWandererF + (((RotL64(aScatter, 27U) + aOrbiterE) + RotL64(aOrbiterC, 3U)) + RotL64(aCarry, 51U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterD, 35U)) + aOrbiterE);
            aWandererB = aWandererB + ((RotL64(aPrevious, 53U) + aOrbiterC) + RotL64(aOrbiterK, 21U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 21U) + aOrbiterG) + RotL64(aOrbiterK, 29U)) + aPhaseFWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterG, 10U)) + aOrbiterI) + aNonceWordN) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 38U) + aOrbiterJ) + RotL64(aOrbiterK, 51U)) + aNonceWordM);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + (RotL64(aWandererK, 60U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererD, 27U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aSnowLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_f loop 3
        // ingress from: aSnowLaneD, aOperationLaneA, aInvestLaneA
        // ingress directions: aSnowLaneD forward forced, aOperationLaneA forward forced, aInvestLaneA forward/backward random
        // cross from: aSnowLaneC, aOperationLaneC
        // cross directions: aSnowLaneC backward forced, aOperationLaneC backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneD[((aIndex + 15073U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneA[((aIndex + 15739U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 13571U)) & S_BLOCK1], 54U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 12726U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneC[((aIndex + 11054U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 37U) + RotL64(aPrevious, 53U)) ^ (RotL64(aCross, 18U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterA = ((aWandererC + RotL64(aCross, 10U)) + 12136097566601676613U) + aNonceWordP;
            aOrbiterC = ((aWandererH + RotL64(aIngress, 57U)) + RotL64(aCarry, 5U)) + 7969431322248040056U;
            aOrbiterF = (aWandererB + RotL64(aPrevious, 47U)) + 10530676021510553889U;
            aOrbiterG = (aWandererK + RotL64(aScatter, 39U)) + 8740777303075445264U;
            aOrbiterH = (((aWandererD + RotL64(aCross, 30U)) + RotL64(aCarry, 51U)) + 13249434169895564739U) + aPhaseFOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = ((aWandererF + RotL64(aScatter, 43U)) + 15529577005925628472U) + aPhaseFOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 5U)) + 344627093687331562U) + aNonceWordJ;
            aOrbiterJ = (aWandererE + RotL64(aPrevious, 35U)) + 8824277416519988893U;
            aOrbiterD = ((aWandererI + RotL64(aScatter, 21U)) + RotL64(aCarry, 21U)) + 5636276438449709875U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 2079413361031851552U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterA) ^ 7807998179168655561U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterF = RotL64((aOrbiterF * 961456853699784753U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 13589392896232029112U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 10733011474804473996U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 361749145931578805U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 15934162328347805968U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 7573511217796245232U;
            aOrbiterG = RotL64((aOrbiterG * 10694563909931636155U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 4828475187337891975U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 13284974329890393113U;
            aOrbiterD = RotL64((aOrbiterD * 10831075817642374287U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 13173869918669643112U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 15841507674783398167U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15632933198136963277U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 14168272451055700516U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 11134471485501999898U;
            aOrbiterJ = RotL64((aOrbiterJ * 8019507184494591705U), 13U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterF) + 2611858916687822610U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordO;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 17863271539727513641U) ^ aNonceWordE;
            aOrbiterK = RotL64((aOrbiterK * 4987884722174985677U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 8874401993454249066U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 5131480593493950665U;
            aOrbiterC = RotL64((aOrbiterC * 8585874663602346121U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 9366563022381918996U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 7890729519928340296U;
            aOrbiterA = RotL64((aOrbiterA * 11428572374057899517U), 47U);
            //
            aIngress = RotL64(aOrbiterE, 38U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 3U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 21U));
            aIngress = aIngress + (RotL64(aOrbiterG, 35U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterJ, 60U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterJ, 43U)) + aOrbiterH) + aNonceWordK);
            aWandererB = aWandererB + (((RotL64(aPrevious, 3U) + aOrbiterK) + RotL64(aOrbiterG, 47U)) + RotL64(aCarry, 29U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 52U) + RotL64(aOrbiterE, 29U)) + aOrbiterD);
            aWandererD = aWandererD + ((((RotL64(aScatter, 19U) + aOrbiterJ) + RotL64(aOrbiterF, 24U)) + RotL64(aCarry, 41U)) + aNonceWordI);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 23U) + aOrbiterH) + RotL64(aOrbiterA, 37U)) + aPhaseFWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 43U) + RotL64(aOrbiterG, 57U)) + aOrbiterC) + aNonceWordL);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 29U) + aOrbiterF) + RotL64(aOrbiterC, 11U));
            aWandererE = aWandererE + ((RotL64(aCross, 37U) + RotL64(aOrbiterA, 6U)) + aOrbiterC);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 58U) + aOrbiterJ) + RotL64(aOrbiterD, 53U)) + aPhaseFWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 10U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + RotL64(aWandererI, 37U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 4
        // ingress from: aExpandLaneA, aSnowLaneC, aWorkLaneD
        // ingress directions: aExpandLaneA forward forced, aSnowLaneC forward forced, aWorkLaneD forward/backward random
        // cross from: aSnowLaneD, aOperationLaneD
        // cross directions: aSnowLaneD backward forced, aOperationLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 18011U)) & S_BLOCK1], 46U) ^ RotL64(aSnowLaneC[((aIndex + 16776U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 19210U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 18724U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneD[((aIndex + 18991U)) & S_BLOCK1], 34U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aPrevious, 12U) ^ RotL64(aCross, 39U)) + (RotL64(aCarry, 53U) + RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterB = (((aWandererI + RotL64(aPrevious, 58U)) + 5721224134332887360U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordP;
            aOrbiterI = ((aWandererG + RotL64(aScatter, 29U)) + RotL64(aCarry, 39U)) + 6892749729775049095U;
            aOrbiterF = ((aWandererA + RotL64(aCross, 13U)) + RotL64(aCarry, 11U)) + 3884839462099556836U;
            aOrbiterG = ((aWandererC + RotL64(aIngress, 39U)) + 4365431706830216193U) + aPhaseFOrbiterAssignSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 22U)) + 15501528746571578773U) + aNonceWordN;
            aOrbiterD = ((aWandererJ + RotL64(aIngress, 47U)) + RotL64(aCarry, 23U)) + 4505911326320650606U;
            aOrbiterE = (aWandererH + RotL64(aScatter, 3U)) + 1865129050927879580U;
            aOrbiterK = (aWandererF + RotL64(aCross, 35U)) + 2011737665969640369U;
            aOrbiterC = (aWandererE + RotL64(aPrevious, 53U)) + 611672935827062688U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 663547038310431047U) + aNonceWordF;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 5468932264754299556U;
            aOrbiterF = RotL64((aOrbiterF * 11968657455484578525U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 17920294117231191705U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 486058453837528110U) ^ aNonceWordJ;
            aOrbiterD = RotL64((aOrbiterD * 8851102552244026737U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 2789178451938129313U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 420772587981211184U;
            aOrbiterE = RotL64((aOrbiterE * 17402987842294006667U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 16196774774442181825U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 16264169656793713547U;
            aOrbiterB = RotL64((aOrbiterB * 6900221986041638783U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 10207659833859860796U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 8593749091183323678U) ^ aNonceWordG;
            aOrbiterI = RotL64((aOrbiterI * 10696776033512404927U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 7224922076047787384U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 15366267474865172373U;
            aOrbiterC = RotL64((aOrbiterC * 10134187073321814217U), 11U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterE) + 4235342515820080294U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1]) + aNonceWordM;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 5239480080426950612U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12077621553561927079U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 10891752830598395582U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 7797358829694471108U;
            aOrbiterJ = RotL64((aOrbiterJ * 7621206775460997431U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 3755715857903753416U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 3172069024987421726U;
            aOrbiterG = RotL64((aOrbiterG * 16048490837178650865U), 57U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterF, 53U);
            aIngress = aIngress + (RotL64(aOrbiterI, 4U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 43U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 11U));
            aIngress = aIngress + RotL64(aOrbiterD, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterF, 3U)) + aOrbiterJ);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 18U) + aOrbiterD) + RotL64(aOrbiterG, 58U)) + aNonceWordD);
            aWandererD = aWandererD + ((((RotL64(aIngress, 39U) + RotL64(aOrbiterC, 41U)) + aOrbiterB) + RotL64(aCarry, 23U)) + aNonceWordO);
            aWandererG = aWandererG ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterE, 29U)) + aOrbiterF) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 5U) + RotL64(aOrbiterK, 37U)) + aOrbiterJ);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 23U) + aOrbiterC) + RotL64(aOrbiterI, 21U)) + aNonceWordI);
            aWandererI = aWandererI + (((RotL64(aCross, 30U) + aOrbiterD) + RotL64(aOrbiterI, 11U)) + aNonceWordC);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterI, 47U)) + aOrbiterK) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 47U) + aOrbiterD) + RotL64(aOrbiterB, 54U)) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererH);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + (RotL64(aWandererI, 41U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererF, 38U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_f loop 5
        // ingress from: aExpandLaneB, aSnowLaneD, aInvestLaneD
        // ingress directions: aExpandLaneB forward forced, aSnowLaneD forward forced, aInvestLaneD forward/backward random
        // cross from: aExpandLaneA, aSnowLaneC
        // cross directions: aExpandLaneA backward forced, aSnowLaneC backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 22132U)) & S_BLOCK1], 36U) ^ RotL64(aSnowLaneD[((aIndex + 23678U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 23588U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26087U)) & S_BLOCK1], 53U) ^ RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 27077U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCarry, 20U)) ^ (RotL64(aIngress, 53U) + RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterF = (((aWandererB + RotL64(aCross, 53U)) + RotL64(aCarry, 29U)) + 4384716820085860551U) + aPhaseFOrbiterAssignSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterC = ((aWandererK + RotL64(aScatter, 42U)) + RotL64(aCarry, 19U)) + 9715780315942116888U;
            aOrbiterI = (aWandererC + RotL64(aPrevious, 27U)) + 15963520052789178632U;
            aOrbiterA = (((aWandererH + RotL64(aIngress, 23U)) + RotL64(aCarry, 37U)) + 14346700690686392938U) + aNonceWordF;
            aOrbiterD = (((aWandererJ + RotL64(aCross, 19U)) + 6005518012489966643U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordC;
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 35U)) + 2506732930310252119U) + aNonceWordD;
            aOrbiterH = ((aWandererI + RotL64(aScatter, 57U)) + 16782163084851775826U) + aNonceWordH;
            aOrbiterE = (aWandererD + RotL64(aIngress, 12U)) + 823673076571076303U;
            aOrbiterK = (aWandererA + RotL64(aPrevious, 47U)) + 1634084509064077736U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 1288134975466877686U) + aNonceWordK;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 2998220403162908444U;
            aOrbiterI = RotL64((aOrbiterI * 4321412662318298283U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 220430672180734911U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 10223923547068528867U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12577370238343872139U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 11696469696177647608U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 6545430420379636963U;
            aOrbiterH = RotL64((aOrbiterH * 8387163146257553773U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 79691451831797107U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 8971444023498649419U;
            aOrbiterK = RotL64((aOrbiterK * 7148919880477390009U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 5624403902454498793U) + aNonceWordM;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 9468064161002030997U;
            aOrbiterF = RotL64((aOrbiterF * 8243560528100864595U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 4619361544913629805U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 12682446273369750704U;
            aOrbiterD = RotL64((aOrbiterD * 10879074713156075641U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 8728730962617599223U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 9099675924074253030U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5525644236954497523U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 3298303921318288541U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 5953276499411658358U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10565471305001292693U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 6725769507592688539U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 1057277456510215817U;
            aOrbiterE = RotL64((aOrbiterE * 8269412198279297075U), 47U);
            //
            aIngress = RotL64(aOrbiterA, 13U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + (RotL64(aOrbiterD, 41U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 51U));
            aIngress = aIngress + RotL64(aOrbiterE, 34U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aPrevious, 50U) + RotL64(aOrbiterB, 22U)) + aOrbiterK);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterK, 47U)) + aOrbiterH);
            aWandererC = aWandererC + (((RotL64(aScatter, 3U) + RotL64(aOrbiterA, 29U)) + aOrbiterE) + aNonceWordG);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 23U) + aOrbiterD) + RotL64(aOrbiterB, 13U));
            aWandererB = aWandererB + ((((RotL64(aScatter, 57U) + aOrbiterB) + RotL64(aOrbiterA, 56U)) + RotL64(aCarry, 3U)) + aNonceWordL);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 18U) + RotL64(aOrbiterE, 5U)) + aOrbiterF);
            aWandererD = aWandererD + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterI, 51U)) + aOrbiterF);
            aWandererI = aWandererI ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterE, 41U)) + aOrbiterI) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterB, 37U)) + aOrbiterC) + RotL64(aCarry, 37U)) + aPhaseFWandererUpdateSaltE[((aIndex + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 6U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererG, 39U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 6
        // ingress from: aExpandLaneC, aExpandLaneA, aInvestLaneC
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aInvestLaneC forward/backward random
        // cross from: aExpandLaneB, aOperationLaneB
        // cross directions: aExpandLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 27317U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneA[((aIndex + 27811U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 31391U)) & S_BLOCK1], 22U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28933U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30973U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aPrevious, 35U) ^ RotL64(aCarry, 47U)) ^ (RotL64(aCross, 18U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterI = (((aWandererF + RotL64(aCross, 18U)) + 8101351470141807662U) + aPhaseFOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1]) + aNonceWordN;
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 39U)) + RotL64(aCarry, 37U)) + 6965474099521076705U;
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 53U)) + 6803828268885684784U) + aPhaseFOrbiterAssignSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 47U)) + RotL64(aCarry, 29U)) + 13454235922950972488U;
            aOrbiterB = (aWandererE + RotL64(aPrevious, 6U)) + 11678091885751244777U;
            aOrbiterC = (aWandererG + RotL64(aScatter, 43U)) + 5307134544628507141U;
            aOrbiterH = ((aWandererC + RotL64(aIngress, 57U)) + 4873703518950429353U) + aNonceWordO;
            aOrbiterK = (((aWandererH + RotL64(aCross, 11U)) + RotL64(aCarry, 47U)) + 8542156221858586039U) + aNonceWordG;
            aOrbiterF = (aWandererK + RotL64(aPrevious, 27U)) + 3993726182905296513U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 12113047622035464386U) + aNonceWordD;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 1944244448665721151U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7010050836758762003U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 12914188029425467576U) + aNonceWordB;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 2486762763475327024U;
            aOrbiterB = RotL64((aOrbiterB * 12319769994433811617U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 14580191602982245481U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 12093414832400135066U;
            aOrbiterH = RotL64((aOrbiterH * 12720286833215690663U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 13623906997320021065U) + aNonceWordE;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 9977356009806428696U;
            aOrbiterC = RotL64((aOrbiterC * 2005536391712733499U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 3694954095397810851U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 11453812627797091638U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13730420725113907161U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 542311345544726351U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 3024285045990499484U) ^ aNonceWordP;
            aOrbiterF = RotL64((aOrbiterF * 5153745952148205645U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 15397664082460849530U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 10716856680110815056U;
            aOrbiterJ = RotL64((aOrbiterJ * 13947203772929252823U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 833342121331428547U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 1111339940097269219U;
            aOrbiterD = RotL64((aOrbiterD * 17991642769781175473U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 9312963978841402871U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 8225496710723213204U;
            aOrbiterI = RotL64((aOrbiterI * 894499195498817065U), 13U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterF, 14U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 21U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 43U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + RotL64(aOrbiterI, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 29U) + aOrbiterK) + RotL64(aOrbiterI, 29U));
            aWandererF = aWandererF + ((RotL64(aScatter, 60U) + RotL64(aOrbiterF, 35U)) + aOrbiterG);
            aWandererC = aWandererC ^ ((RotL64(aCross, 3U) + aOrbiterJ) + RotL64(aOrbiterI, 23U));
            aWandererG = aWandererG + ((((RotL64(aIngress, 13U) + aOrbiterH) + RotL64(aOrbiterI, 51U)) + RotL64(aCarry, 53U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 43U) + aOrbiterC) + RotL64(aOrbiterH, 42U));
            aWandererE = aWandererE + (((RotL64(aIngress, 19U) + aOrbiterG) + RotL64(aOrbiterD, 57U)) + aNonceWordM);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 39U) + aOrbiterF) + RotL64(aOrbiterJ, 19U)) + aNonceWordL);
            aWandererK = aWandererK + ((((RotL64(aScatter, 23U) + RotL64(aOrbiterB, 47U)) + aOrbiterC) + RotL64(aCarry, 27U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 48U) + aOrbiterK) + RotL64(aOrbiterD, 6U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 50U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 27U));
            aCarry = aCarry + RotL64(aWandererG, 3U);
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

void TwistExpander_Soccer_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xA0DE0753C63CE1C3ULL + 0xA4D71E48D545051FULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xABA27B34ABCC121FULL + 0xDFA80C3B6A5E0C53ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x8995461D03B48B6FULL + 0xB6B187551BC851F6ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xF52E50FEF8A65017ULL + 0xC7AAB8C1CA88ABB3ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xFE30DA9010AA1C7DULL + 0xAB5A7213127FCA42ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x8D9D7DC6957F7451ULL + 0x9363972FC04A639FULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xD63EE1BD741D7387ULL + 0xEA83BDE6A17EAD73ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xDACB182F054C48BFULL + 0xC1B132CE3EF0B0C9ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xD5653111502296E5ULL + 0x8FC5593F0058FA27ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x90909CCDE64CFED3ULL + 0xABAC40202ADADAFBULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x84DE0A00E2597E41ULL + 0x996E37C48F2027BAULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x894EEA079FD97419ULL + 0xBED8628716E28568ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x86CA790752CEDB9FULL + 0x8F50A4E5B9B1BBE4ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xA6E5EF4F06775337ULL + 0x839E99E7CD116B5FULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x995429165A14D629ULL + 0xC99D25D616BADA46ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xA12DCE6D89E19EC7ULL + 0xDB6A3CAA2B4F0EB4ULL);
    // GSeedRunSeed_G seed_loop_h (start)
    {
        // GSeedRunSeed_G seed_loop_h lane group
        // read from: aSnowLaneA, aSnowLaneB, aFireLaneD, aSnowLaneC, aSnowLaneD, aFireLaneB, aWorkLaneA, aInvestLaneC, aInvestLaneB, aWorkLaneB, aInvestLaneD, aExpandLaneA, aFireLaneC, aExpandLaneB, aInvestLaneA, aExpandLaneC, aFireLaneA
        // write to: aWorkLaneA, aWorkLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_h loop 1
        // ingress from: aSnowLaneA, aSnowLaneB, aFireLaneD
        // ingress directions: aSnowLaneA forward forced, aSnowLaneB forward forced, aFireLaneD forward/backward random
        // cross from: aSnowLaneC, aSnowLaneD, aFireLaneB
        // cross directions: aSnowLaneC backward forced, aSnowLaneD backward forced, aFireLaneB backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 3143U)) & S_BLOCK1], 39U) ^ RotL64(aSnowLaneB[((aIndex + 1293U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 3406U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 2134U)) & S_BLOCK1], 41U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 4513U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 4575U)) & S_BLOCK1], 28U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 22U) ^ RotL64(aIngress, 39U)) ^ (RotL64(aPrevious, 3U) + RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterA = ((aWandererD + RotL64(aScatter, 60U)) + 9654059367478508868U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = ((aWandererA + RotL64(aIngress, 13U)) + 6473006635864677427U) + aNonceWordE;
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 19U)) + RotL64(aCarry, 3U)) + 6944184481315853243U;
            aOrbiterI = ((aWandererC + RotL64(aCross, 37U)) + RotL64(aCarry, 53U)) + 4061496421939102306U;
            aOrbiterE = ((aWandererK + RotL64(aScatter, 3U)) + RotL64(aCarry, 37U)) + 15791809275719085463U;
            aOrbiterC = ((aWandererG + RotL64(aPrevious, 47U)) + 14050798802646323055U) + aPhaseHOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = ((aWandererF + RotL64(aCross, 29U)) + 12072905924741758266U) + aNonceWordJ;
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 17639076509231343896U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 12195388285571234715U) ^ aNonceWordB;
            aOrbiterH = RotL64((aOrbiterH * 4317060502521195769U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 4325404419499496529U) + aNonceWordN;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 5910567888204238382U) ^ aNonceWordF;
            aOrbiterE = RotL64((aOrbiterE * 11503787177122206937U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 13092940059929942699U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 13381962590820308761U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6345904465930943295U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 15622862439323440527U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 14027151901132249793U;
            aOrbiterI = RotL64((aOrbiterI * 2273573821630510087U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 4584410023907605157U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 15763755180625487157U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6755736130607297639U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 17023059745666559199U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterC) ^ 5298529579288492971U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterG = RotL64((aOrbiterG * 2483562793328357721U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 2870152867331654736U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 12017191100173748848U;
            aOrbiterC = RotL64((aOrbiterC * 9958191466506480519U), 29U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterA, 11U);
            aIngress = aIngress + (RotL64(aOrbiterC, 58U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterH, 27U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterI, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aCross, 27U) + RotL64(aOrbiterI, 3U)) + aOrbiterE);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 58U) + RotL64(aOrbiterA, 19U)) + aOrbiterE) + aNonceWordM);
            aWandererC = aWandererC + ((((RotL64(aIngress, 39U) + RotL64(aOrbiterH, 11U)) + aOrbiterB) + RotL64(aCarry, 21U)) + aNonceWordG);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 51U) + aOrbiterC) + RotL64(aOrbiterH, 47U)) + aNonceWordK);
            aWandererD = aWandererD + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterC, 27U)) + aOrbiterE) + aPhaseHWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 3U) + aOrbiterB) + RotL64(aOrbiterG, 54U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 13U) + RotL64(aOrbiterG, 39U)) + aOrbiterA) + RotL64(aCarry, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 50U) ^ aWandererK);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 23U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + RotL64(aWandererC, 41U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 2
        // ingress from: aWorkLaneA, aSnowLaneC, aSnowLaneD, aInvestLaneC
        // ingress directions: aWorkLaneA forward forced, aSnowLaneC forward forced, aSnowLaneD forward forced, aInvestLaneC forward/backward random
        // cross from: aSnowLaneA, aSnowLaneB, aInvestLaneB
        // cross directions: aSnowLaneA backward forced, aSnowLaneB backward forced, aInvestLaneB backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 10196U)) & S_BLOCK1], 27U) ^ RotL64(aSnowLaneC[((aIndex + 7030U)) & S_BLOCK1], 58U));
            aIngress ^= (RotL64(aSnowLaneD[((aIndex + 10623U)) & S_BLOCK1], 19U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 6072U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 9868U)) & S_BLOCK1], 11U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 5560U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 9803U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCross, 23U)) + (RotL64(aIngress, 36U) + RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterI = (aWandererH + RotL64(aCross, 13U)) + 16802219662864902427U;
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 3U)) + 14332033461409490629U) + aNonceWordC;
            aOrbiterJ = (aWandererJ + RotL64(aScatter, 19U)) + 8781794298640286845U;
            aOrbiterD = (aWandererI + RotL64(aIngress, 47U)) + 8459933908074937264U;
            aOrbiterH = ((((aWandererD + RotL64(aCross, 27U)) + RotL64(aCarry, 23U)) + 1883580287986004426U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordN;
            aOrbiterE = ((aWandererK + RotL64(aIngress, 37U)) + RotL64(aCarry, 47U)) + 17500258188004626118U;
            aOrbiterK = (((aWandererE + RotL64(aScatter, 54U)) + RotL64(aCarry, 5U)) + 7934811305150872870U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 6380363892361098905U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 12623079132626676910U;
            aOrbiterJ = RotL64((aOrbiterJ * 12406671746344127399U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 10455208121949202703U) + aNonceWordH;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 8805532707916767629U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 666082374369701881U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 9161544391400377699U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 3501434325829663268U) ^ aNonceWordF;
            aOrbiterD = RotL64((aOrbiterD * 7933545151293799637U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 651783304096081996U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 441505031509930622U) ^ aNonceWordG;
            aOrbiterB = RotL64((aOrbiterB * 8045355432310956143U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 1771159983581326424U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 15227946417377695989U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1563141188972797601U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 4153717524193279095U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 4404521756523902829U;
            aOrbiterK = RotL64((aOrbiterK * 1410342912973206203U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 6231945075461813285U) + aNonceWordI;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 3864780227164426690U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 18031353247480673617U), 23U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterK, 3U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 58U));
            aIngress = aIngress + (RotL64(aOrbiterH, 43U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterJ, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aPrevious, 27U) + aOrbiterB) + RotL64(aOrbiterE, 57U)) + aPhaseHWandererUpdateSaltB[((aIndex + 22U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 48U) + RotL64(aOrbiterI, 27U)) + aOrbiterJ) + aNonceWordO);
            aWandererF = aWandererF + (((((RotL64(aIngress, 21U) + aOrbiterH) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 53U)) + aNonceWordA) + aPhaseHWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterI, 50U)) + aOrbiterB);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterE, 35U)) + aOrbiterK);
            aWandererI = aWandererI ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterI, 21U)) + aOrbiterE);
            aWandererH = aWandererH + (((RotL64(aScatter, 35U) + aOrbiterH) + RotL64(aOrbiterD, 41U)) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 56U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererD);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 27U));
            aCarry = aCarry + RotL64(aWandererH, 23U);
            aCarry = aCarry + RotL64(aIngress, 10U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_h loop 3
        // ingress from: aWorkLaneB, aSnowLaneA, aInvestLaneD
        // ingress directions: aWorkLaneB forward forced, aSnowLaneA forward forced, aInvestLaneD forward/backward random
        // cross from: aWorkLaneA, aSnowLaneC
        // cross directions: aWorkLaneA backward forced, aSnowLaneC backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 12584U)) & S_BLOCK1], 13U) ^ RotL64(aSnowLaneA[((aIndex + 13321U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 14543U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16060U)) & S_BLOCK1], 47U) ^ RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 12884U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 19U) + RotL64(aPrevious, 51U)) ^ (RotL64(aIngress, 4U) + RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterF = ((aWandererC + RotL64(aCross, 21U)) + RotL64(aCarry, 5U)) + 8402620908307642697U;
            aOrbiterB = ((aWandererB + RotL64(aScatter, 3U)) + RotL64(aCarry, 37U)) + 11347672014525086047U;
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 57U)) + 2816462912503401876U) + aNonceWordE;
            aOrbiterI = (((aWandererF + RotL64(aIngress, 36U)) + RotL64(aCarry, 19U)) + 6940159795470696093U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = (aWandererI + RotL64(aPrevious, 29U)) + 9134692490095883851U;
            aOrbiterK = (((aWandererK + RotL64(aCross, 51U)) + 4999455497008026526U) + aPhaseHOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1]) + aNonceWordG;
            aOrbiterG = (aWandererG + RotL64(aScatter, 13U)) + 5992451460350651332U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 3417087346651371924U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 3612773820086198270U;
            aOrbiterH = RotL64((aOrbiterH * 5519856345435871169U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 463398077083428570U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 11249391303705089012U;
            aOrbiterC = RotL64((aOrbiterC * 7106735772303292983U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 17027535139825739501U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 568131384979596481U) ^ aNonceWordH;
            aOrbiterK = RotL64((aOrbiterK * 5683451044852895957U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 4793712537158004047U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 10415170179135963622U;
            aOrbiterG = RotL64((aOrbiterG * 13729564030210361415U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 2391473979460065630U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 4240058362680064261U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12375884373396400889U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 9963957011090031698U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 3325305624067445525U;
            aOrbiterB = RotL64((aOrbiterB * 3128542681461806309U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 2094945647665114693U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 10703615640774042674U) ^ aNonceWordK;
            aOrbiterI = RotL64((aOrbiterI * 12641986098450423751U), 39U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterG, 47U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 53U));
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterB, 10U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aCross, 57U) + aOrbiterI) + RotL64(aOrbiterH, 6U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterB, 51U)) + aOrbiterI) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 20U) + aOrbiterK) + RotL64(aOrbiterC, 19U)) + aNonceWordC) + aPhaseHWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterG, 13U)) + aOrbiterI) + aNonceWordN);
            aWandererI = aWandererI + (((RotL64(aCross, 27U) + aOrbiterG) + RotL64(aOrbiterK, 43U)) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 43U) + aOrbiterG) + RotL64(aOrbiterF, 29U));
            aWandererK = aWandererK + ((((RotL64(aPrevious, 35U) + aOrbiterF) + RotL64(aOrbiterB, 37U)) + RotL64(aCarry, 39U)) + aNonceWordI);
            //
            aCarry = aCarry + (RotL64(aWandererF, 56U) ^ aWandererG);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + RotL64(aWandererI, 35U);
            aCarry = aCarry + RotL64(aIngress, 24U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 17081U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((aIndex + 20589U)) & S_BLOCK1], 36U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 21669U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20355U)) & S_BLOCK1], 50U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 20586U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aIngress, 56U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 43U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterH = ((aWandererA + RotL64(aCross, 47U)) + RotL64(aCarry, 19U)) + 12029393034357490020U;
            aOrbiterI = ((aWandererG + RotL64(aPrevious, 11U)) + 4526754731580694987U) + aNonceWordP;
            aOrbiterC = (aWandererB + RotL64(aIngress, 4U)) + 17060419646421271853U;
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 35U)) + 4128488893837059683U) + aPhaseHOrbiterAssignSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = (((aWandererJ + RotL64(aPrevious, 57U)) + RotL64(aCarry, 57U)) + 12706894827547160110U) + aPhaseHOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = (((aWandererC + RotL64(aIngress, 41U)) + RotL64(aCarry, 39U)) + 12506324593645825056U) + aNonceWordK;
            aOrbiterA = ((aWandererI + RotL64(aScatter, 21U)) + 12581344490649250025U) + aNonceWordL;
            //
            aOrbiterH = (((aOrbiterH + aOrbiterI) + 14357032418199130132U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordH;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 15341977701796331249U;
            aOrbiterC = RotL64((aOrbiterC * 6332369248718076031U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 7086602307544733241U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 12398300065276832486U;
            aOrbiterH = RotL64((aOrbiterH * 18157408831225635333U), 57U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterA) + 2499745046076601988U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordE;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 7249361592814001829U;
            aOrbiterJ = RotL64((aOrbiterJ * 14597139848072319685U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 3254456186337366437U) + aNonceWordO;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 3472973415969046680U) ^ aNonceWordM;
            aOrbiterI = RotL64((aOrbiterI * 14583566953969168353U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 7905718972111691591U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 15941413652144021522U;
            aOrbiterF = RotL64((aOrbiterF * 3473779492962783565U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 10583964125960308762U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 13659925272340853715U;
            aOrbiterE = RotL64((aOrbiterE * 16708294803316630743U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 9487054537489454887U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 13287757570441887517U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17351439045329892107U), 13U);
            //
            aIngress = RotL64(aOrbiterE, 35U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + RotL64(aOrbiterC, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aIngress, 27U) + RotL64(aOrbiterI, 41U)) + aOrbiterE) + aNonceWordN);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 43U) + aOrbiterF) + RotL64(aOrbiterJ, 23U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterI, 29U)) + aOrbiterF) + RotL64(aCarry, 37U));
            aWandererA = aWandererA ^ ((((RotL64(aScatter, 37U) + RotL64(aOrbiterC, 13U)) + aOrbiterI) + aNonceWordI) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 5U) + RotL64(aOrbiterA, 3U)) + aOrbiterE) + RotL64(aCarry, 19U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterJ, 48U)) + aOrbiterC);
            aWandererH = aWandererH + ((((RotL64(aCross, 20U) + aOrbiterI) + RotL64(aOrbiterH, 57U)) + aNonceWordA) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 39U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 50U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + RotL64(aWandererC, 23U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_h loop 5
        // ingress from: aExpandLaneB, aWorkLaneB, aInvestLaneA
        // ingress directions: aExpandLaneB forward forced, aWorkLaneB forward forced, aInvestLaneA forward/backward random
        // cross from: aExpandLaneA, aWorkLaneA
        // cross directions: aExpandLaneA backward forced, aWorkLaneA backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 22153U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((aIndex + 24447U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 24492U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23278U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23271U)) & S_BLOCK1], 26U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCross, 11U)) ^ (RotL64(aIngress, 56U) + RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterH = (((aWandererG + RotL64(aCross, 57U)) + RotL64(aCarry, 21U)) + 3199575576585871314U) + aNonceWordP;
            aOrbiterC = (aWandererJ + RotL64(aScatter, 3U)) + 2533378188975571824U;
            aOrbiterI = (aWandererK + RotL64(aIngress, 21U)) + 6819782112558312658U;
            aOrbiterB = (((aWandererC + RotL64(aPrevious, 27U)) + RotL64(aCarry, 5U)) + 12690060987724798497U) + aNonceWordL;
            aOrbiterG = ((aWandererB + RotL64(aScatter, 35U)) + 7088375139715629606U) + aPhaseHOrbiterAssignSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = ((aWandererA + RotL64(aPrevious, 12U)) + 17785618677423695666U) + aNonceWordA;
            aOrbiterE = ((((aWandererI + RotL64(aIngress, 47U)) + RotL64(aCarry, 37U)) + 1714999280296491277U) + aPhaseHOrbiterAssignSaltD[((aIndex + 12U)) & S_SALT1]) + aNonceWordE;
            //
            aOrbiterH = (((aOrbiterH + aOrbiterC) + 17611338506932491624U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1]) + aNonceWordM;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 6475727359297421201U;
            aOrbiterI = RotL64((aOrbiterI * 15133348244242438069U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 2347744591204119530U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 2739317903351401068U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15435029315209475631U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 8663535261373274338U) + aNonceWordD;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 8205245127823536479U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13857005110466856439U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 8916510616749754516U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 3944805940148512932U;
            aOrbiterE = RotL64((aOrbiterE * 18082271583211389701U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 14094751253118853302U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 14094299829196076311U;
            aOrbiterK = RotL64((aOrbiterK * 6370012560657108493U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 3940673811518673802U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 3015106523254484839U;
            aOrbiterC = RotL64((aOrbiterC * 9655401190755573379U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 15404103131982599922U) + aNonceWordB;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 1828655763233900875U) ^ aNonceWordK;
            aOrbiterG = RotL64((aOrbiterG * 13024358077740310049U), 3U);
            //
            aIngress = RotL64(aOrbiterB, 11U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterH, 5U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterK, 19U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterG, 50U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aScatter, 37U) + RotL64(aOrbiterI, 11U)) + aOrbiterE) + RotL64(aCarry, 21U)) + aNonceWordN);
            aWandererG = aWandererG ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterC, 60U)) + aOrbiterH) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aIngress, 60U) + RotL64(aOrbiterK, 19U)) + aOrbiterG) + aNonceWordO) + aPhaseHWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 51U) + aOrbiterI) + RotL64(aOrbiterB, 5U));
            aWandererI = aWandererI + ((RotL64(aScatter, 13U) + RotL64(aOrbiterH, 35U)) + aOrbiterI);
            aWandererK = aWandererK ^ (((RotL64(aCross, 23U) + aOrbiterK) + RotL64(aOrbiterI, 27U)) + aNonceWordF);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 29U) + RotL64(aOrbiterG, 41U)) + aOrbiterB) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererI, 5U) ^ aWandererK);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 40U));
            aCarry = aCarry + RotL64(aWandererC, 27U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 28133U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneA[((aIndex + 29069U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 30597U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28823U)) & S_BLOCK1], 47U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 27855U)) & S_BLOCK1], 12U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 19U) ^ RotL64(aPrevious, 3U)) + (RotL64(aCross, 53U) + RotL64(aIngress, 38U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterA = (aWandererJ + RotL64(aCross, 3U)) + 5960680319644404115U;
            aOrbiterB = (((aWandererD + RotL64(aScatter, 57U)) + RotL64(aCarry, 35U)) + 16050752633567034185U) + aNonceWordE;
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 29U)) + 8447503223226854741U) + aPhaseHOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = (((aWandererH + RotL64(aIngress, 39U)) + RotL64(aCarry, 23U)) + 14176813813397917591U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = ((aWandererE + RotL64(aCross, 12U)) + 10534915376130006644U) + aNonceWordL;
            aOrbiterF = (aWandererA + RotL64(aIngress, 23U)) + 6866224454375302514U;
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 47U)) + RotL64(aCarry, 3U)) + 16506374165041008396U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 7167814023968794098U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 13870852197416596664U;
            aOrbiterG = RotL64((aOrbiterG * 17015971222069856463U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 18064038854848993105U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 9869630811507771691U;
            aOrbiterH = RotL64((aOrbiterH * 13723164383800461387U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 863613100452759380U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 16597969741225436529U) ^ aNonceWordA;
            aOrbiterF = RotL64((aOrbiterF * 2680793528887208903U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 6575347108051310653U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 17062262265485019063U;
            aOrbiterA = RotL64((aOrbiterA * 7601045488473620019U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 7193399224636409133U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 14146747818810433849U) ^ aNonceWordF;
            aOrbiterB = RotL64((aOrbiterB * 5273185769989530041U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 9441449106442431427U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 4303295336545399503U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8829695296836242587U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 12604760768543193458U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 15779327512379787715U;
            aOrbiterK = RotL64((aOrbiterK * 14000905201441272597U), 13U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterK, 13U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 27U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 35U));
            aIngress = aIngress + RotL64(aOrbiterC, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aCross, 36U) + aOrbiterG) + RotL64(aOrbiterF, 57U)) + RotL64(aCarry, 13U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterB, 39U)) + aOrbiterA) + aNonceWordH);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 47U) + aOrbiterG) + RotL64(aOrbiterK, 13U)) + RotL64(aCarry, 41U));
            aWandererE = aWandererE ^ ((((RotL64(aIngress, 19U) + aOrbiterC) + RotL64(aOrbiterK, 19U)) + aNonceWordM) + aPhaseHWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aCross, 29U) + aOrbiterC) + RotL64(aOrbiterH, 46U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 11U) + aOrbiterB) + RotL64(aOrbiterH, 27U));
            aWandererK = aWandererK + ((((RotL64(aPrevious, 5U) + aOrbiterA) + RotL64(aOrbiterC, 5U)) + aNonceWordC) + aPhaseHWandererUpdateSaltA[((aIndex + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 53U));
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 58U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererA, 21U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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

void TwistExpander_Soccer_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltC;
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 464U)) & W_KEY1], 22U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 143U)) & W_KEY1], 5U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 1612U)) & W_KEY1], 34U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 2110U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 6U) ^ RotL64(aIngress, 35U)) + (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = (aWandererG + RotL64(aCross, 12U)) + 6973892330986118220U;
            aOrbiterB = ((aWandererA + RotL64(aIngress, 57U)) + RotL64(aCarry, 21U)) + 9886813896272094864U;
            aOrbiterE = (aWandererD + RotL64(aPrevious, 39U)) + 10996306582517553173U;
            aOrbiterD = (((aWandererK + RotL64(aScatter, 19U)) + RotL64(aCarry, 11U)) + 8490648283899856223U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = (aWandererJ + RotL64(aPrevious, 3U)) + 105141713530704655U;
            aOrbiterH = (((aWandererB + RotL64(aCross, 53U)) + RotL64(aCarry, 43U)) + 3114337422810562588U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = (aWandererE + RotL64(aIngress, 35U)) + 980857684690886131U;
            aOrbiterJ = (aWandererC + RotL64(aScatter, 47U)) + 6562042345807072665U;
            aOrbiterK = (aWandererH + RotL64(aCross, 28U)) + 15665371138706353619U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 18113013571374375028U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 17405346422601997299U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11162604605443005253U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 5130876096426182506U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 1813821672299154629U;
            aOrbiterF = RotL64((aOrbiterF * 15478100342425611875U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 15793814882743306728U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 13925299440495476399U;
            aOrbiterI = RotL64((aOrbiterI * 12049601510660117401U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 9924458846049579438U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 7810034662781768090U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10310594595026622513U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 12812586478656872854U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 5709576448057435237U;
            aOrbiterB = RotL64((aOrbiterB * 9101555233909853025U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 7839807649914541516U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 4717944526755429647U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8515229146471335721U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 3933911971504256022U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 4814079680865379831U;
            aOrbiterK = RotL64((aOrbiterK * 15100740696230557391U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 18352577312212175569U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 9670612998448920742U;
            aOrbiterH = RotL64((aOrbiterH * 5743579439303300553U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 72737302703035726U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 10032869372369626210U;
            aOrbiterD = RotL64((aOrbiterD * 7449905669249993731U), 27U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterG, 19U);
            aIngress = aIngress + (RotL64(aOrbiterK, 47U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 13U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 38U));
            aIngress = aIngress + RotL64(aOrbiterE, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterG, 10U)) + aOrbiterI);
            aWandererG = aWandererG + (((RotL64(aIngress, 29U) + RotL64(aOrbiterG, 23U)) + aOrbiterH) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 11U) + aOrbiterK) + RotL64(aOrbiterJ, 57U));
            aWandererE = aWandererE + (((RotL64(aScatter, 34U) + RotL64(aOrbiterD, 19U)) + aOrbiterE) + RotL64(aCarry, 39U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterJ, 6U)) + aOrbiterB);
            aWandererB = aWandererB + (((RotL64(aPrevious, 57U) + aOrbiterI) + RotL64(aOrbiterD, 37U)) + RotL64(aCarry, 47U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 47U) + aOrbiterK) + RotL64(aOrbiterB, 43U));
            aWandererD = aWandererD + (((RotL64(aCross, 20U) + aOrbiterH) + RotL64(aOrbiterF, 51U)) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 3U) + aOrbiterG) + RotL64(aOrbiterF, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererA);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 24U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 19U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + RotL64(aWandererB, 27U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 4740U)) & S_BLOCK1], 37U) ^ RotL64(aKeyRowReadA[((aIndex + 4491U)) & W_KEY1], 28U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 2926U)) & W_KEY1], 58U) ^ RotL64(mSource[((aIndex + 5453U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 5U)) + (RotL64(aCross, 18U) + RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = ((aWandererH + RotL64(aCross, 51U)) + RotL64(aCarry, 27U)) + 1297415699043177788U;
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 11U)) + RotL64(aCarry, 39U)) + 17583786534509260153U;
            aOrbiterK = (aWandererD + RotL64(aPrevious, 21U)) + 643197858925708798U;
            aOrbiterF = ((aWandererG + RotL64(aScatter, 28U)) + RotL64(aCarry, 47U)) + 5062653766915694874U;
            aOrbiterD = (aWandererB + RotL64(aCross, 3U)) + 7034273638367180511U;
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 39U)) + 2026909726972916996U) + aPhaseAOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = (aWandererE + RotL64(aScatter, 35U)) + 2785690475553211646U;
            aOrbiterH = (aWandererJ + RotL64(aIngress, 57U)) + 2910341716302991892U;
            aOrbiterI = ((aWandererF + RotL64(aCross, 44U)) + 2834181605200829791U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 13323052600571281928U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 10434901530315760460U;
            aOrbiterK = RotL64((aOrbiterK * 2042210188346767033U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 247903955625194782U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 5196515747387257163U;
            aOrbiterD = RotL64((aOrbiterD * 1799024689023272275U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 7196305682377987476U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 14777739876892587484U;
            aOrbiterA = RotL64((aOrbiterA * 95220583948241581U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 10609060796540136671U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 8386027207212484155U;
            aOrbiterG = RotL64((aOrbiterG * 4855610536246556893U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 729659744301903424U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 2350564261412606157U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16713856782349084977U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 16611987556673864177U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 1525195188708550503U;
            aOrbiterB = RotL64((aOrbiterB * 10045858602151004553U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 4654808490980989596U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 8189569777087686263U;
            aOrbiterF = RotL64((aOrbiterF * 17278657566389299577U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 10932857495004451792U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 1833880112534916813U;
            aOrbiterI = RotL64((aOrbiterI * 8004341577533825681U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 13100236350175516423U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 2773759534195186313U;
            aOrbiterJ = RotL64((aOrbiterJ * 3194954066097323161U), 13U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterK, 5U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 54U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 23U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 39U));
            aIngress = aIngress + RotL64(aOrbiterI, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aIngress, 24U) + aOrbiterD) + RotL64(aOrbiterK, 44U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 53U) + aOrbiterK) + RotL64(aOrbiterI, 29U));
            aWandererA = aWandererA + (((RotL64(aScatter, 35U) + RotL64(aOrbiterB, 19U)) + aOrbiterH) + RotL64(aCarry, 37U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 29U) + aOrbiterJ) + RotL64(aOrbiterB, 3U));
            aWandererF = aWandererF + (((RotL64(aIngress, 57U) + RotL64(aOrbiterJ, 57U)) + aOrbiterA) + RotL64(aCarry, 23U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 3U) + aOrbiterA) + RotL64(aOrbiterD, 39U));
            aWandererG = aWandererG + ((RotL64(aCross, 18U) + RotL64(aOrbiterG, 13U)) + aOrbiterI);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 47U) + aOrbiterG) + RotL64(aOrbiterK, 23U)) + aPhaseAWandererUpdateSaltC[((aIndex + 10U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 43U) + RotL64(aOrbiterF, 34U)) + aOrbiterJ) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 42U) ^ aWandererJ);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + (RotL64(aWandererB, 5U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererD, 39U);
            aCarry = aCarry + RotL64(aIngress, 14U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 5649U)) & S_BLOCK1], 43U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 6727U)) & W_KEY1], 12U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 7733U)) & W_KEY1], 60U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 6943U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 6278U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 43U) ^ RotL64(aCarry, 57U)) ^ (RotL64(aPrevious, 23U) + RotL64(aCross, 10U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = ((aWandererG + RotL64(aIngress, 27U)) + 13333509828310369865U) + aPhaseAOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = ((aWandererD + RotL64(aCross, 39U)) + RotL64(aCarry, 21U)) + 7645352517103840797U;
            aOrbiterD = (aWandererK + RotL64(aScatter, 52U)) + 5310766306660062655U;
            aOrbiterH = (((aWandererI + RotL64(aPrevious, 43U)) + RotL64(aCarry, 41U)) + 5165635069832352932U) + aPhaseAOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = ((aWandererH + RotL64(aScatter, 47U)) + RotL64(aCarry, 13U)) + 15684141764734281849U;
            aOrbiterB = (aWandererC + RotL64(aPrevious, 57U)) + 3327963374225061738U;
            aOrbiterF = (aWandererJ + RotL64(aIngress, 14U)) + 8625811794878848871U;
            aOrbiterE = (aWandererE + RotL64(aCross, 3U)) + 7598657468430485291U;
            aOrbiterA = (aWandererB + RotL64(aScatter, 23U)) + 2881171216276746485U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 10237691227222918101U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 6419254255884834497U;
            aOrbiterD = RotL64((aOrbiterD * 3816625473642865305U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 4238455444646479956U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 14936613353493061492U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3544216916806292273U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 15324699725208372627U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 9506640480601832011U;
            aOrbiterF = RotL64((aOrbiterF * 12819564111348390227U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 3709149613660215641U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 1724290199312754307U;
            aOrbiterH = RotL64((aOrbiterH * 12597580418257897965U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 13191172833570139194U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 3686087945377837886U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10883609557429936283U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 10418330386245397022U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 5383531313632347245U;
            aOrbiterC = RotL64((aOrbiterC * 2987755379396160073U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 7414716553072652212U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 11301761123966206201U;
            aOrbiterK = RotL64((aOrbiterK * 1546727321088592187U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 8570229732236388847U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 8773754460060264773U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3251360788932563495U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 13636929800504199371U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 5486599841558573720U;
            aOrbiterI = RotL64((aOrbiterI * 2867914211589815153U), 47U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterH, 56U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + (RotL64(aOrbiterC, 13U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterK, 39U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterF, 26U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterK, 24U)) + aOrbiterI);
            aWandererE = aWandererE + (((RotL64(aIngress, 22U) + aOrbiterB) + RotL64(aOrbiterF, 57U)) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 51U) + aOrbiterA) + RotL64(aOrbiterI, 35U));
            aWandererK = aWandererK + (((RotL64(aScatter, 47U) + RotL64(aOrbiterF, 39U)) + aOrbiterD) + RotL64(aCarry, 41U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 43U) + aOrbiterA) + RotL64(aOrbiterH, 5U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 57U) + aOrbiterE) + RotL64(aOrbiterC, 28U)) + RotL64(aCarry, 29U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterC, 43U)) + aOrbiterF);
            aWandererH = aWandererH + (((RotL64(aCross, 36U) + RotL64(aOrbiterB, 53U)) + aOrbiterK) + aPhaseAWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 11U) + aOrbiterD) + RotL64(aOrbiterH, 13U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 58U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererG, 13U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 8244U)) & S_BLOCK1], 5U) ^ RotL64(aKeyRowReadB[((aIndex + 10833U)) & W_KEY1], 20U));
            aIngress ^= (RotL64(mSource[((aIndex + 10533U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((aIndex + 8924U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 8572U)) & W_KEY1], 19U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 8480U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aPrevious, 6U)) + (RotL64(aCarry, 21U) ^ RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = ((aWandererA + RotL64(aIngress, 47U)) + 479672811032092393U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = ((aWandererC + RotL64(aCross, 19U)) + RotL64(aCarry, 21U)) + 18061121631394564425U;
            aOrbiterD = (aWandererI + RotL64(aScatter, 28U)) + 14237400452740566065U;
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 43U)) + RotL64(aCarry, 5U)) + 6723123812257706134U;
            aOrbiterB = (aWandererJ + RotL64(aCross, 13U)) + 4247997188026499248U;
            aOrbiterA = ((aWandererE + RotL64(aIngress, 5U)) + RotL64(aCarry, 13U)) + 1939107415066134869U;
            aOrbiterC = (aWandererF + RotL64(aPrevious, 57U)) + 3912640123546395979U;
            aOrbiterF = (aWandererD + RotL64(aScatter, 39U)) + 8295478436553964298U;
            aOrbiterK = ((aWandererB + RotL64(aIngress, 24U)) + 3218960600711526885U) + aPhaseBOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 5874096203353388890U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 10294536533673023358U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15561710414949058923U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 11268561953904130747U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 16693201256788898423U;
            aOrbiterE = RotL64((aOrbiterE * 16291987237693567209U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 7550969634681894654U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 9501647424602245869U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11265865222096866605U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 8881869255994319423U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 16770136406906800016U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1782039587385512923U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 16185384746435761363U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 13841034186650721627U;
            aOrbiterA = RotL64((aOrbiterA * 12000155593277035447U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 15229062695864608309U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 3576122704615303733U;
            aOrbiterG = RotL64((aOrbiterG * 2433987493885779279U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 13898167174453181224U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 12878032061609524049U;
            aOrbiterJ = RotL64((aOrbiterJ * 18104665741338251495U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 12719156051299028649U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 8640980843376950769U;
            aOrbiterK = RotL64((aOrbiterK * 10242616778390983333U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 12133332160916004365U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 8743563985229104484U;
            aOrbiterB = RotL64((aOrbiterB * 4575129690615054691U), 5U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterD, 5U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 37U));
            aIngress = aIngress + (RotL64(aOrbiterE, 48U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 53U));
            aIngress = aIngress + RotL64(aOrbiterF, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 43U) + aOrbiterJ) + RotL64(aOrbiterC, 41U));
            aWandererF = aWandererF + (((RotL64(aCross, 6U) + aOrbiterF) + RotL64(aOrbiterC, 48U)) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 51U) + aOrbiterK) + RotL64(aOrbiterF, 29U));
            aWandererK = aWandererK + (((RotL64(aIngress, 47U) + RotL64(aOrbiterC, 19U)) + aOrbiterD) + RotL64(aCarry, 39U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterE, 11U)) + aOrbiterJ);
            aWandererA = aWandererA + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterF, 37U)) + aOrbiterD) + RotL64(aCarry, 27U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterG, 53U)) + aOrbiterA);
            aWandererJ = aWandererJ + (((RotL64(aCross, 58U) + RotL64(aOrbiterD, 24U)) + aOrbiterG) + aPhaseBWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterB, 57U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererK, 28U) ^ aWandererF);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 51U));
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 12633U)) & S_BLOCK1], 39U) ^ RotL64(aKeyRowReadA[((aIndex + 13356U)) & W_KEY1], 4U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 12676U)) & W_KEY1], 51U) ^ RotL64(mSource[((aIndex + 11382U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 13050U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11326U)) & S_BLOCK1], 57U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 12544U)) & S_BLOCK1], 20U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 10U) ^ RotL64(aCarry, 23U)) + (RotL64(aCross, 51U) + RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = ((aWandererD + RotL64(aScatter, 57U)) + RotL64(aCarry, 21U)) + 2101601659597850213U;
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 47U)) + 2759794072560720121U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = (aWandererA + RotL64(aIngress, 34U)) + 9443562552411269339U;
            aOrbiterB = ((aWandererF + RotL64(aCross, 53U)) + RotL64(aCarry, 39U)) + 10801360546699857975U;
            aOrbiterK = (aWandererC + RotL64(aIngress, 43U)) + 8020716394829332019U;
            aOrbiterG = (aWandererJ + RotL64(aCross, 13U)) + 1021894212367773801U;
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 26U)) + RotL64(aCarry, 13U)) + 13346855534622490176U;
            aOrbiterI = ((aWandererI + RotL64(aScatter, 39U)) + 16359309548462953836U) + aPhaseBOrbiterAssignSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 3U)) + 12642446944680783519U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 8197424982767553380U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 14346334610901859094U;
            aOrbiterA = RotL64((aOrbiterA * 16982899923227935679U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 14171304260534233539U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 334531601308283605U;
            aOrbiterK = RotL64((aOrbiterK * 5012968232749075075U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 10707856298471572695U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 18364775750091914766U;
            aOrbiterB = RotL64((aOrbiterB * 15735143943129143265U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 8531394793118363836U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 15352876929406908882U;
            aOrbiterE = RotL64((aOrbiterE * 475199047053777179U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 567682016232278157U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 2068146551757663119U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1557877740957797555U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 7776122587613256525U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 16430938890724272256U;
            aOrbiterI = RotL64((aOrbiterI * 4540270493783593257U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 11912000645055436094U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 16800749242578741498U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17804584625034241737U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 5909199180260499150U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 5751089915336865588U;
            aOrbiterH = RotL64((aOrbiterH * 15376689503142397927U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 3478216857728853008U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 18007567146937338241U;
            aOrbiterJ = RotL64((aOrbiterJ * 6620498877303917855U), 53U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterC, 11U);
            aIngress = aIngress + (RotL64(aOrbiterK, 39U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterB, 54U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterG, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aCross, 44U) + RotL64(aOrbiterI, 60U)) + aOrbiterH) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 19U) + RotL64(aOrbiterK, 47U)) + aOrbiterI) + RotL64(aCarry, 21U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterA, 43U)) + aOrbiterK);
            aWandererB = aWandererB + ((RotL64(aScatter, 11U) + RotL64(aOrbiterB, 19U)) + aOrbiterC);
            aWandererI = aWandererI ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterC, 29U)) + aOrbiterA);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 39U) + RotL64(aOrbiterJ, 52U)) + aOrbiterB) + RotL64(aCarry, 13U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 29U) + aOrbiterA) + RotL64(aOrbiterG, 23U));
            aWandererE = aWandererE + ((RotL64(aIngress, 35U) + RotL64(aOrbiterB, 11U)) + aOrbiterI);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterB, 37U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 50U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererF, 39U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 13914U)) & S_BLOCK1], 29U) ^ RotL64(aInvestLaneA[((aIndex + 15128U)) & S_BLOCK1], 42U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15678U)) & W_KEY1], 23U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 14754U)) & W_KEY1], 13U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 15070U)) & S_BLOCK1], 46U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 16224U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 15230U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCross, 35U)) + (RotL64(aCarry, 54U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 18U)) + RotL64(aCarry, 19U)) + 15045917390223766480U;
            aOrbiterH = ((aWandererH + RotL64(aScatter, 11U)) + 10763054007033668758U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterC = (aWandererJ + RotL64(aIngress, 47U)) + 13190170142593666607U;
            aOrbiterJ = (aWandererG + RotL64(aCross, 57U)) + 9657025731441167065U;
            aOrbiterD = (aWandererE + RotL64(aIngress, 43U)) + 11433367178975954211U;
            aOrbiterG = ((aWandererA + RotL64(aCross, 6U)) + 17904920143996810366U) + aPhaseBOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = (aWandererC + RotL64(aPrevious, 51U)) + 3244383020512113283U;
            aOrbiterK = ((aWandererI + RotL64(aScatter, 37U)) + RotL64(aCarry, 37U)) + 6538815775171139091U;
            aOrbiterI = ((aWandererB + RotL64(aIngress, 29U)) + RotL64(aCarry, 51U)) + 7195368312757976343U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 18134430713910279374U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 6571776588427107976U;
            aOrbiterC = RotL64((aOrbiterC * 11916502085252589161U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 11830778129647517758U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 9793702760907767365U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4096246227968677179U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 2287235876793192036U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 8951959188326141794U;
            aOrbiterG = RotL64((aOrbiterG * 9968356718110753845U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 7583061790273240157U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 3571364625022806085U;
            aOrbiterE = RotL64((aOrbiterE * 6238360922735480669U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 13869345563551689212U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 277480328952975002U;
            aOrbiterK = RotL64((aOrbiterK * 1057564597096163085U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 4983735092494677578U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 9490022869381030928U;
            aOrbiterH = RotL64((aOrbiterH * 12926352917961703123U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 7928039573014765566U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 6504190875809407084U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14648214826494826711U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 2787985600176307413U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 16308785053443116826U;
            aOrbiterF = RotL64((aOrbiterF * 17867565986311256691U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 12788128335006767824U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 1187040019537798339U;
            aOrbiterI = RotL64((aOrbiterI * 10834905007658184183U), 13U);
            //
            aIngress = RotL64(aOrbiterE, 26U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterK, 13U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 35U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + RotL64(aOrbiterC, 38U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aIngress, 12U) + RotL64(aOrbiterG, 39U)) + aOrbiterC) + RotL64(aCarry, 43U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterJ, 29U)) + aOrbiterK) + aPhaseBWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 5U) + aOrbiterD) + RotL64(aOrbiterJ, 4U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterH, 21U)) + aOrbiterD) + aPhaseBWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 53U) + RotL64(aOrbiterF, 57U)) + aOrbiterH) + RotL64(aCarry, 29U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterE, 35U)) + aOrbiterC);
            aWandererI = aWandererI + ((RotL64(aIngress, 43U) + RotL64(aOrbiterE, 10U)) + aOrbiterG);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 24U) + aOrbiterF) + RotL64(aOrbiterJ, 47U));
            aWandererC = aWandererC + ((RotL64(aCross, 39U) + aOrbiterI) + RotL64(aOrbiterJ, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 38U) ^ aWandererC);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 21U));
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererG, 5U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 17155U)) & S_BLOCK1], 36U) ^ RotL64(aKeyRowReadA[((aIndex + 18150U)) & W_KEY1], 47U));
            aIngress ^= (RotL64(mSource[((aIndex + 17813U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18464U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 17015U)) & W_KEY1], 58U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 16649U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 17267U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 41U) + RotL64(aPrevious, 23U)) + (RotL64(aCross, 57U) ^ RotL64(aIngress, 6U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = (aWandererB + RotL64(aScatter, 51U)) + 9133751643283278896U;
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 12U)) + RotL64(aCarry, 47U)) + 8971581804375380408U;
            aOrbiterF = ((aWandererD + RotL64(aIngress, 37U)) + RotL64(aCarry, 21U)) + 12559650383714566592U;
            aOrbiterE = (aWandererG + RotL64(aCross, 29U)) + 15753206088872859163U;
            aOrbiterA = ((aWandererI + RotL64(aScatter, 41U)) + 7640756270450762350U) + aPhaseCOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = ((aWandererJ + RotL64(aCross, 56U)) + 7340073357551376125U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = (aWandererH + RotL64(aPrevious, 23U)) + 5270256573644196046U;
            aOrbiterH = (aWandererA + RotL64(aIngress, 47U)) + 3567367996479995928U;
            aOrbiterJ = ((aWandererF + RotL64(aCross, 19U)) + RotL64(aCarry, 37U)) + 11939634537492733738U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 7051817732424527120U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 1730487669951837941U;
            aOrbiterF = RotL64((aOrbiterF * 15191634337956285841U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 18009252467909454817U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 2361024272031696442U;
            aOrbiterA = RotL64((aOrbiterA * 15215151562500226027U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 15902755877642960397U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 12243517544704116184U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2576071074148141447U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 16846181962302186187U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 636121425116506681U;
            aOrbiterH = RotL64((aOrbiterH * 17075030673338779993U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 6887385655828217318U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 3705834550934775862U;
            aOrbiterB = RotL64((aOrbiterB * 11275428284929594435U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 11165142437077969438U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 6426659930331618269U;
            aOrbiterE = RotL64((aOrbiterE * 17170640810530893705U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 12629082390899315789U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 4277510580069574724U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9829125163412708305U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 13814834144170469978U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 3698381854100295826U;
            aOrbiterK = RotL64((aOrbiterK * 5126359230872258015U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 11623170635983579937U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 7247413650388803796U;
            aOrbiterJ = RotL64((aOrbiterJ * 3403219499465560059U), 57U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterG, 39U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 21U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 51U));
            aIngress = aIngress + (RotL64(aOrbiterE, 24U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aIngress, 47U) + aOrbiterA) + RotL64(aOrbiterG, 19U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterJ, 3U)) + aOrbiterK) + aPhaseCWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 30U) + RotL64(aOrbiterC, 10U)) + aOrbiterK) + RotL64(aCarry, 3U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterC, 23U)) + aOrbiterJ);
            aWandererH = aWandererH + (((RotL64(aPrevious, 35U) + aOrbiterF) + RotL64(aOrbiterA, 39U)) + RotL64(aCarry, 29U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 13U) + aOrbiterH) + RotL64(aOrbiterJ, 47U));
            aWandererC = aWandererC + ((RotL64(aIngress, 39U) + RotL64(aOrbiterE, 51U)) + aOrbiterA);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterG, 27U)) + aOrbiterF);
            aWandererI = aWandererI + (((RotL64(aPrevious, 56U) + RotL64(aOrbiterB, 56U)) + aOrbiterC) + aPhaseCWandererUpdateSaltC[((aIndex + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 54U));
            aCarry = aCarry + (RotL64(aWandererD, 51U) ^ aWandererC);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + RotL64(aWandererG, 19U);
            aCarry = aCarry + RotL64(aIngress, 40U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 21755U)) & S_BLOCK1], 3U) ^ RotL64(mSource[((aIndex + 20737U)) & S_BLOCK1], 47U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 20917U)) & S_BLOCK1], 36U) ^ RotL64(aWorkLaneA[((aIndex + 20149U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 20561U)) & W_KEY1], 6U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 20530U)) & W_KEY1], 21U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 21702U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((aIndex + 19528U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 35U) ^ RotL64(aCarry, 6U)) + (RotL64(aIngress, 21U) ^ RotL64(aCross, 47U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = ((aWandererI + RotL64(aScatter, 54U)) + RotL64(aCarry, 51U)) + 12980104182836602177U;
            aOrbiterD = ((aWandererJ + RotL64(aIngress, 11U)) + 3172622203188863995U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = (aWandererE + RotL64(aCross, 29U)) + 1170974132219980203U;
            aOrbiterG = (aWandererB + RotL64(aPrevious, 47U)) + 6035201940965047490U;
            aOrbiterB = (aWandererD + RotL64(aScatter, 23U)) + 18033907118424996722U;
            aOrbiterK = (aWandererA + RotL64(aCross, 43U)) + 14604813424800580304U;
            aOrbiterE = (aWandererC + RotL64(aPrevious, 19U)) + 13720232492851066035U;
            aOrbiterF = ((aWandererF + RotL64(aIngress, 5U)) + RotL64(aCarry, 41U)) + 3902659710585257448U;
            aOrbiterH = (((aWandererG + RotL64(aPrevious, 60U)) + RotL64(aCarry, 19U)) + 8331560652661619868U) + aPhaseCOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 4485014147538689794U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 168202636924512424U;
            aOrbiterJ = RotL64((aOrbiterJ * 13711020666131492091U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 16227825670092707848U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 4792781933944671365U;
            aOrbiterB = RotL64((aOrbiterB * 15859849676231455283U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 12636865372722601282U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 18198291399585556632U;
            aOrbiterE = RotL64((aOrbiterE * 18155803890313399795U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 3650053185419807206U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 5897288963905408776U;
            aOrbiterD = RotL64((aOrbiterD * 3706949366974086151U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 9922308113622901726U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 13352279749091561510U;
            aOrbiterG = RotL64((aOrbiterG * 4025213180483632557U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 14969461950939646117U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 10231661776135056651U;
            aOrbiterA = RotL64((aOrbiterA * 11284575051455238501U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 10621934544068320859U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 6029116920305246887U;
            aOrbiterH = RotL64((aOrbiterH * 6087523725059376905U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 12887482425168671195U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 8351351557123783853U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3839381627914762245U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 5405938210926464973U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 385145802287899406U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8330751480464271445U), 11U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterH, 35U);
            aIngress = aIngress + (RotL64(aOrbiterB, 6U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 53U));
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterK, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 35U) + aOrbiterA) + RotL64(aOrbiterD, 13U));
            aWandererE = aWandererE + ((RotL64(aScatter, 24U) + aOrbiterF) + RotL64(aOrbiterH, 51U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterG, 35U)) + aOrbiterD);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 39U) + aOrbiterE) + RotL64(aOrbiterJ, 3U)) + RotL64(aCarry, 57U)) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterA, 60U)) + aOrbiterJ);
            aWandererB = aWandererB + ((((RotL64(aScatter, 43U) + aOrbiterB) + RotL64(aOrbiterE, 47U)) + RotL64(aCarry, 23U)) + aPhaseCWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterD, 41U)) + aOrbiterH);
            aWandererC = aWandererC + ((RotL64(aCross, 57U) + RotL64(aOrbiterK, 29U)) + aOrbiterB);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 18U) + aOrbiterH) + RotL64(aOrbiterK, 18U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 54U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererC, 43U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 39U));
            aCarry = aCarry + RotL64(aWandererI, 35U);
            aCarry = aCarry + RotL64(aIngress, 28U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 21882U)) & S_BLOCK1], 57U) ^ RotL64(aKeyRowReadA[((aIndex + 24379U)) & W_KEY1], 47U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 21899U)) & W_KEY1], 10U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 24132U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 22303U)) & S_BLOCK1], 51U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 22519U)) & S_BLOCK1], 12U));
            aCross ^= (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 23995U)) & S_BLOCK1], 27U) ^ RotL64(aInvestLaneB[((aIndex + 23814U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 41U) + RotL64(aCross, 5U)) ^ (RotL64(aCarry, 53U) + RotL64(aIngress, 26U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 28U)) + 9023059520606551446U) + aPhaseCOrbiterAssignSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = (aWandererA + RotL64(aCross, 11U)) + 662441755115638133U;
            aOrbiterG = (aWandererF + RotL64(aIngress, 19U)) + 16957253361196144712U;
            aOrbiterB = ((aWandererI + RotL64(aScatter, 39U)) + RotL64(aCarry, 21U)) + 7840955025765308605U;
            aOrbiterA = (aWandererC + RotL64(aPrevious, 58U)) + 346855809270395799U;
            aOrbiterI = ((aWandererD + RotL64(aIngress, 53U)) + RotL64(aCarry, 51U)) + 16099139781586668343U;
            aOrbiterC = (((aWandererG + RotL64(aCross, 3U)) + RotL64(aCarry, 3U)) + 3706457327118322098U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = (aWandererB + RotL64(aScatter, 23U)) + 12166825885547622870U;
            aOrbiterH = (aWandererE + RotL64(aIngress, 43U)) + 7792658665720344200U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 7128477606152986326U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 11116533962780290084U;
            aOrbiterG = RotL64((aOrbiterG * 11993485572912492297U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 10443889548568288532U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 4402387036946561017U;
            aOrbiterA = RotL64((aOrbiterA * 9032964741841833277U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 13002706161178447654U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 13929727277530310708U;
            aOrbiterF = RotL64((aOrbiterF * 7005639090871200285U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 10949073760696935106U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 15405923432006783533U;
            aOrbiterC = RotL64((aOrbiterC * 17989565878445202495U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 18096057968822208905U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 3032155040484574973U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 448597307502544605U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 17462076466907467134U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 15471015427013701406U;
            aOrbiterI = RotL64((aOrbiterI * 6113474000571976139U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 3549031751266594344U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 14243218483842508113U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9041601306479302047U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 5803147589312920032U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 5549470512227427855U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12592362489263862879U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 10076661824293832189U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 3196799148974716550U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8183276968961467775U), 13U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterH, 27U);
            aIngress = aIngress + (RotL64(aOrbiterK, 23U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 37U));
            aIngress = aIngress + (RotL64(aOrbiterC, 51U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterG, 12U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 13U) + aOrbiterB) + RotL64(aOrbiterD, 35U));
            aWandererF = aWandererF + (((RotL64(aScatter, 52U) + RotL64(aOrbiterB, 27U)) + aOrbiterA) + RotL64(aCarry, 23U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterG, 57U)) + aOrbiterD);
            aWandererD = aWandererD + ((RotL64(aCross, 27U) + aOrbiterH) + RotL64(aOrbiterF, 14U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterK, 41U)) + aOrbiterB) + aPhaseCWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 41U) + RotL64(aOrbiterF, 21U)) + aOrbiterC) + RotL64(aCarry, 13U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 60U) + RotL64(aOrbiterF, 5U)) + aOrbiterK);
            aWandererG = aWandererG + (((RotL64(aIngress, 47U) + aOrbiterI) + RotL64(aOrbiterA, 10U)) + aPhaseCWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterD, 47U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + (RotL64(aWandererB, 24U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererG);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 21U));
            aCarry = aCarry + RotL64(aWandererA, 47U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 25954U)) & S_BLOCK1], 5U) ^ RotL64(aKeyRowReadA[((aIndex + 26629U)) & W_KEY1], 54U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 27092U)) & S_BLOCK1], 27U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 26903U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 26225U)) & W_KEY1], 60U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 25528U)) & S_BLOCK1], 35U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 24806U)) & S_BLOCK1], 21U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 26348U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 18U) + RotL64(aPrevious, 5U)) ^ (RotL64(aIngress, 53U) + RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = (aWandererB + RotL64(aScatter, 3U)) + 6024062041314952357U;
            aOrbiterA = (aWandererI + RotL64(aPrevious, 51U)) + 18340757093658015585U;
            aOrbiterD = ((aWandererG + RotL64(aIngress, 13U)) + RotL64(aCarry, 43U)) + 11911120493880346751U;
            aOrbiterG = (aWandererA + RotL64(aCross, 56U)) + 17428074353884654439U;
            aOrbiterI = (aWandererF + RotL64(aIngress, 23U)) + 12790849760814795936U;
            aOrbiterK = (aWandererH + RotL64(aCross, 29U)) + 12633397052172117800U;
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 41U)) + 11946150433665237945U) + aPhaseDOrbiterAssignSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 36U)) + RotL64(aCarry, 11U)) + 16842157900909419285U;
            aOrbiterB = (((aWandererE + RotL64(aScatter, 19U)) + RotL64(aCarry, 57U)) + 14186235783224155962U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 13284904542579767591U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 11609181965078844357U;
            aOrbiterD = RotL64((aOrbiterD * 5455780554452453513U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 9628562297095374984U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 7850281529011259759U;
            aOrbiterI = RotL64((aOrbiterI * 17611485102925470357U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 257458718073794527U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 10693404545773519306U;
            aOrbiterJ = RotL64((aOrbiterJ * 14821443722828498323U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 3430519236533871460U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 6183054506953198055U;
            aOrbiterF = RotL64((aOrbiterF * 6121082743789970911U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 2905610989884221654U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 4472163910775333862U;
            aOrbiterK = RotL64((aOrbiterK * 7770678426310856745U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 16870142883133769663U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 1403692060594816451U;
            aOrbiterB = RotL64((aOrbiterB * 9740854430251597879U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 16904169913507057108U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 4773518591580333357U;
            aOrbiterA = RotL64((aOrbiterA * 5306070307776061267U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 6528141733853494275U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 11254806909313951442U;
            aOrbiterE = RotL64((aOrbiterE * 6316669786405548827U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 6857506858448143407U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 2855763534355983644U;
            aOrbiterG = RotL64((aOrbiterG * 16881334940165182415U), 53U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterA, 11U);
            aIngress = aIngress + (RotL64(aOrbiterD, 52U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterF, 3U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterB, 43U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterK, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aCross, 24U) + RotL64(aOrbiterA, 23U)) + aOrbiterD) + RotL64(aCarry, 11U)) + aPhaseDWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterI, 41U)) + aOrbiterG);
            aWandererF = aWandererF + ((RotL64(aIngress, 3U) + aOrbiterK) + RotL64(aOrbiterF, 47U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 19U) + aOrbiterG) + RotL64(aOrbiterA, 5U));
            aWandererH = aWandererH + ((((RotL64(aIngress, 39U) + aOrbiterB) + RotL64(aOrbiterG, 56U)) + RotL64(aCarry, 19U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 43U) + aOrbiterA) + RotL64(aOrbiterK, 27U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 56U) + aOrbiterF) + RotL64(aOrbiterD, 37U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterE, 13U)) + aOrbiterJ);
            aWandererB = aWandererB + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterE, 60U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 54U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererC);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 21U));
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 29173U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneD[((aIndex + 28934U)) & S_BLOCK1], 51U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 28111U)) & W_KEY1], 18U) ^ RotL64(aFireLaneC[((aIndex + 29530U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 29827U)) & W_KEY1], 42U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 29429U)) & S_BLOCK1], 13U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30015U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneB[((aIndex + 27390U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 27U)) + (RotL64(aCross, 53U) + RotL64(aIngress, 4U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = ((aWandererF + RotL64(aScatter, 58U)) + RotL64(aCarry, 3U)) + 9220392006207660113U;
            aOrbiterI = (aWandererB + RotL64(aIngress, 11U)) + 11305018553489132882U;
            aOrbiterK = (aWandererG + RotL64(aCross, 5U)) + 5860373868073513684U;
            aOrbiterD = (aWandererJ + RotL64(aPrevious, 23U)) + 12319586170883987589U;
            aOrbiterB = (aWandererH + RotL64(aScatter, 43U)) + 14072333614354649021U;
            aOrbiterE = ((aWandererA + RotL64(aCross, 39U)) + RotL64(aCarry, 57U)) + 9332158529453194608U;
            aOrbiterH = (((aWandererC + RotL64(aIngress, 35U)) + RotL64(aCarry, 29U)) + 3860569321145958686U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 50U)) + 8119005668901240093U) + aPhaseDOrbiterAssignSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterF = (aWandererI + RotL64(aScatter, 29U)) + 13918259792880333239U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 6938856216758228704U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 3960905839118710604U;
            aOrbiterK = RotL64((aOrbiterK * 16203746868670689793U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 6043879193734253929U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 15691425268831319195U;
            aOrbiterE = RotL64((aOrbiterE * 7189195135654636271U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 14912209933584715274U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 16180183395910618923U;
            aOrbiterJ = RotL64((aOrbiterJ * 3942858974766467849U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 4966642362507707776U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 6962226782462822861U;
            aOrbiterD = RotL64((aOrbiterD * 3647802407741095419U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 12409120845092026295U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 2302946450253872465U;
            aOrbiterF = RotL64((aOrbiterF * 7099576330777297911U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 16118304388937163838U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 15968419034359049422U;
            aOrbiterB = RotL64((aOrbiterB * 11736207775827080165U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 17098982091525008231U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 10298979200690822062U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12620028874653521945U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 552826643694256437U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 11786560990790695378U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11190309640069208311U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 13730399230389329793U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 17614226859252305432U;
            aOrbiterH = RotL64((aOrbiterH * 2640019643570222977U), 47U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterK, 46U);
            aIngress = aIngress + (RotL64(aOrbiterH, 21U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 53U));
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterB, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aIngress, 6U) + RotL64(aOrbiterD, 46U)) + aOrbiterF) + RotL64(aCarry, 57U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 57U) + aOrbiterK) + RotL64(aOrbiterD, 19U));
            aWandererI = aWandererI + (((RotL64(aCross, 23U) + RotL64(aOrbiterH, 39U)) + aOrbiterK) + RotL64(aCarry, 37U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 39U) + aOrbiterI) + RotL64(aOrbiterB, 29U));
            aWandererF = aWandererF + ((RotL64(aIngress, 35U) + aOrbiterA) + RotL64(aOrbiterK, 3U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterD, 57U)) + aOrbiterA);
            aWandererG = aWandererG + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterI, 14U)) + aOrbiterH) + aPhaseDWandererUpdateSaltB[((aIndex + 18U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 10U) + RotL64(aOrbiterH, 53U)) + aOrbiterJ);
            aWandererC = aWandererC + (((RotL64(aIngress, 29U) + aOrbiterE) + RotL64(aOrbiterI, 23U)) + aPhaseDWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererI);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + RotL64(aWandererB, 60U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 31806U)) & S_BLOCK1], 42U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 32054U)) & W_KEY1], 29U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 32576U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32710U)) & S_BLOCK1], 19U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32199U)) & S_BLOCK1], 35U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 32168U)) & W_KEY1], 11U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 24U) ^ RotL64(aCross, 5U)) ^ (RotL64(aCarry, 51U) + RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = (aWandererE + RotL64(aCross, 57U)) + 9914837590440975587U;
            aOrbiterG = ((aWandererG + RotL64(aIngress, 23U)) + RotL64(aCarry, 23U)) + 6706125076401958051U;
            aOrbiterK = (aWandererD + RotL64(aScatter, 44U)) + 16570817772679258409U;
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 5U)) + RotL64(aCarry, 11U)) + 6843705658115186948U;
            aOrbiterD = (aWandererJ + RotL64(aIngress, 19U)) + 16099930446791572351U;
            aOrbiterH = (((aWandererA + RotL64(aScatter, 13U)) + RotL64(aCarry, 53U)) + 5420550009556030459U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = (aWandererI + RotL64(aCross, 27U)) + 5729549069420177477U;
            aOrbiterI = (aWandererH + RotL64(aPrevious, 51U)) + 15590601126188675834U;
            aOrbiterE = ((aWandererC + RotL64(aCross, 34U)) + 13044027390998620029U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 11068338135659636772U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 6584988841809544332U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1683336180438945439U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 8516813219883915404U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 10647314042912492785U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15559481057047148785U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 201691689889605304U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 15512161798401184003U;
            aOrbiterJ = RotL64((aOrbiterJ * 11473219183982564709U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 3883760518944464145U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 13861805129175491145U;
            aOrbiterG = RotL64((aOrbiterG * 17194438894492581181U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 12019138626550801486U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 13030350224959652248U;
            aOrbiterE = RotL64((aOrbiterE * 11724200983306280107U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 2643807255422544248U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 4127143302485631794U;
            aOrbiterF = RotL64((aOrbiterF * 5441038881111578487U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 14602951930809633069U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 4555737199162278494U;
            aOrbiterD = RotL64((aOrbiterD * 12415825635220991865U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 6343143902997169834U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 10404783711336491985U;
            aOrbiterI = RotL64((aOrbiterI * 6235474458879439079U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 7406959231434835393U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 6684368109277850196U;
            aOrbiterB = RotL64((aOrbiterB * 8760360417572331159U), 53U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterB, 10U);
            aIngress = aIngress + (RotL64(aOrbiterF, 29U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 13U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 37U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterK, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 23U) + aOrbiterH) + RotL64(aOrbiterG, 29U));
            aWandererD = aWandererD + (((RotL64(aCross, 3U) + RotL64(aOrbiterF, 57U)) + aOrbiterI) + RotL64(aCarry, 11U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 58U) + RotL64(aOrbiterK, 24U)) + aOrbiterB);
            aWandererH = aWandererH + (((RotL64(aPrevious, 11U) + aOrbiterK) + RotL64(aOrbiterI, 19U)) + RotL64(aCarry, 27U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterD, 41U)) + aOrbiterH);
            aWandererG = aWandererG + ((RotL64(aCross, 19U) + RotL64(aOrbiterJ, 35U)) + aOrbiterF);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterD, 47U)) + aOrbiterB);
            aWandererA = aWandererA + (((RotL64(aScatter, 53U) + aOrbiterI) + RotL64(aOrbiterJ, 53U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aCross, 48U) + aOrbiterE) + RotL64(aOrbiterI, 6U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 41U));
            aCarry = aCarry + (RotL64(aWandererJ, 18U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererA, 23U);
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

void TwistExpander_Soccer_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneD, aExpandLaneC, aExpandLaneD, aInvestLaneC, aFireLaneA, aInvestLaneD, aFireLaneC, aOperationLaneA, aFireLaneB, aOperationLaneB, aOperationLaneC
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 4377U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneB[((aIndex + 2898U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 1202U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 944U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneD[((aIndex + 1860U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 27U) ^ RotL64(aIngress, 39U)) + (RotL64(aPrevious, 12U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = (((aWandererC + RotL64(aIngress, 21U)) + RotL64(aCarry, 23U)) + 16183871922837164759U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 47U)) + RotL64(aCarry, 41U)) + 7002058258090219055U;
            aOrbiterF = ((aWandererH + RotL64(aCross, 34U)) + 5650868611888303705U) + aPhaseEOrbiterAssignSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = (aWandererG + RotL64(aScatter, 27U)) + 11899839660943876690U;
            aOrbiterI = (aWandererJ + RotL64(aIngress, 5U)) + 15349649504488111111U;
            aOrbiterH = ((aWandererK + RotL64(aCross, 13U)) + RotL64(aCarry, 57U)) + 14060149569086744970U;
            aOrbiterA = (aWandererA + RotL64(aScatter, 57U)) + 12920917574225030112U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 2831994965175330135U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 18312543585028439192U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11618182708195744321U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 11657562205118394239U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 10850792819281246052U;
            aOrbiterB = RotL64((aOrbiterB * 10663100544207879337U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 17810371216216125323U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 7963413941144223128U;
            aOrbiterH = RotL64((aOrbiterH * 534217972450595401U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 5498715358793875584U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 9256727548911651373U;
            aOrbiterD = RotL64((aOrbiterD * 10498848323914000989U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 17246360111302191699U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 18309978718113983369U;
            aOrbiterI = RotL64((aOrbiterI * 18267472694666221077U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 3100998994319502921U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 8129301860291235970U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17847033539279176187U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 1889641029473279114U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 16538494307002917945U;
            aOrbiterC = RotL64((aOrbiterC * 8081488217920885783U), 29U);
            //
            aIngress = RotL64(aOrbiterC, 21U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterF, 27U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 35U));
            aIngress = aIngress + RotL64(aOrbiterH, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 58U) + RotL64(aOrbiterF, 19U)) + aOrbiterI) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 41U) + aOrbiterB) + RotL64(aOrbiterA, 13U)) + RotL64(aCarry, 39U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 47U) + aOrbiterC) + RotL64(aOrbiterB, 57U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 13U) + RotL64(aOrbiterI, 47U)) + aOrbiterA) + RotL64(aCarry, 23U)) + aPhaseEWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 27U) + aOrbiterD) + RotL64(aOrbiterH, 26U));
            aWandererA = aWandererA + ((RotL64(aCross, 35U) + aOrbiterD) + RotL64(aOrbiterF, 39U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 21U) + aOrbiterH) + RotL64(aOrbiterI, 5U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + (RotL64(aWandererJ, 42U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 29U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aInvestLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_b loop 2
        // ingress from: aInvestLaneC, aExpandLaneC, aFireLaneA
        // ingress directions: aInvestLaneC forward forced, aExpandLaneC forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneC[((aIndex + 9893U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneC[((aIndex + 8451U)) & S_BLOCK1], 48U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 5464U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 6162U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneD[((aIndex + 8419U)) & S_BLOCK1], 22U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aPrevious, 53U)) + (RotL64(aCross, 11U) + RotL64(aIngress, 26U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 13U)) + RotL64(aCarry, 29U)) + 2101601659597850213U;
            aOrbiterE = (aWandererD + RotL64(aScatter, 29U)) + 2759794072560720121U;
            aOrbiterJ = (((aWandererA + RotL64(aCross, 3U)) + RotL64(aCarry, 11U)) + 9443562552411269339U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 41U)) + RotL64(aCarry, 47U)) + 10801360546699857975U;
            aOrbiterG = ((aWandererC + RotL64(aScatter, 47U)) + 8020716394829332019U) + aPhaseEOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = (aWandererB + RotL64(aCross, 22U)) + 1021894212367773801U;
            aOrbiterC = (aWandererH + RotL64(aIngress, 57U)) + 13346855534622490176U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 16359309548462953836U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 12642446944680783519U;
            aOrbiterJ = RotL64((aOrbiterJ * 12197935153255283321U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 8197424982767553380U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 14346334610901859094U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16982899923227935679U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 14171304260534233539U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 334531601308283605U;
            aOrbiterA = RotL64((aOrbiterA * 5012968232749075075U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 10707856298471572695U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 18364775750091914766U;
            aOrbiterC = RotL64((aOrbiterC * 15735143943129143265U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 8531394793118363836U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 15352876929406908882U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 475199047053777179U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 567682016232278157U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 2068146551757663119U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1557877740957797555U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 7776122587613256525U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 16430938890724272256U;
            aOrbiterK = RotL64((aOrbiterK * 4540270493783593257U), 19U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterH, 11U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 41U));
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterA, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aScatter, 27U) + RotL64(aOrbiterE, 51U)) + aOrbiterG) + RotL64(aCarry, 11U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 5U) + aOrbiterA) + RotL64(aOrbiterH, 3U));
            aWandererD = aWandererD + (((RotL64(aIngress, 53U) + aOrbiterA) + RotL64(aOrbiterC, 57U)) + RotL64(aCarry, 23U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 12U) + RotL64(aOrbiterE, 11U)) + aOrbiterC);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 41U) + RotL64(aOrbiterJ, 38U)) + aOrbiterA) + aPhaseEWandererUpdateSaltA[((aIndex + 12U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterE, 23U)) + aOrbiterK);
            aWandererA = aWandererA + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterK, 29U)) + aOrbiterG) + aPhaseEWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 24U));
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererE, 37U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererD, 51U);
            aCarry = aCarry + RotL64(aIngress, 58U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aInvestLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_b loop 3
        // ingress from: aInvestLaneD, aExpandLaneD, aFireLaneC
        // ingress directions: aInvestLaneD forward forced, aExpandLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aInvestLaneC, aExpandLaneB, aExpandLaneA
        // cross directions: aInvestLaneC backward forced, aExpandLaneB backward forced, aExpandLaneA backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneD[((aIndex + 12092U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneD[((aIndex + 14697U)) & S_BLOCK1], 48U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 14730U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 13652U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 14221U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aExpandLaneA[((aIndex + 12102U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCarry, 51U)) ^ (RotL64(aPrevious, 18U) ^ RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = (aWandererD + RotL64(aCross, 47U)) + 12535417189990029950U;
            aOrbiterG = ((aWandererG + RotL64(aScatter, 35U)) + 6204401443676390273U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = ((aWandererK + RotL64(aIngress, 21U)) + RotL64(aCarry, 23U)) + 869613505613154672U;
            aOrbiterF = (aWandererH + RotL64(aPrevious, 12U)) + 15053590879563855802U;
            aOrbiterE = (((aWandererE + RotL64(aCross, 3U)) + RotL64(aCarry, 11U)) + 13338989605204591428U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 41U)) + RotL64(aCarry, 47U)) + 18306470022403825392U;
            aOrbiterD = (aWandererJ + RotL64(aScatter, 57U)) + 1150696349434090218U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 13549541786420596437U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 14302878430259588461U;
            aOrbiterJ = RotL64((aOrbiterJ * 16813606782134305513U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 4660437084477165225U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 1653628537860912069U;
            aOrbiterG = RotL64((aOrbiterG * 2624835201155303123U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 5594199757006711631U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 11008472193138708891U;
            aOrbiterE = RotL64((aOrbiterE * 13645764762027798301U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 3668516817279364310U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 128159531749679984U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4523246859249826987U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 6378674346113979108U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 11438762460659123362U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2733309638158283953U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 10624263004446482910U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 12546839706919241411U;
            aOrbiterA = RotL64((aOrbiterA * 11468326687628079347U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 8466639576503293921U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 5828694979857951504U;
            aOrbiterF = RotL64((aOrbiterF * 7835487310289634515U), 47U);
            //
            aIngress = RotL64(aOrbiterI, 43U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterE, 11U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 20U));
            aIngress = aIngress + RotL64(aOrbiterJ, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aScatter, 3U) + RotL64(aOrbiterA, 3U)) + aOrbiterD) + RotL64(aCarry, 21U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 27U) + aOrbiterI) + RotL64(aOrbiterJ, 29U));
            aWandererG = aWandererG + ((((RotL64(aCross, 41U) + RotL64(aOrbiterE, 41U)) + aOrbiterJ) + RotL64(aCarry, 57U)) + aPhaseEWandererUpdateSaltE[((aIndex + 22U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 21U) + aOrbiterJ) + RotL64(aOrbiterG, 22U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 35U) + RotL64(aOrbiterJ, 53U)) + aOrbiterA) + aPhaseEWandererUpdateSaltD[((aIndex + 14U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 58U) + RotL64(aOrbiterD, 11U)) + aOrbiterF);
            aWandererH = aWandererH + ((RotL64(aIngress, 11U) + aOrbiterG) + RotL64(aOrbiterE, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 22U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + RotL64(aWandererK, 53U);
            aCarry = aCarry + RotL64(aIngress, 42U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 20870U)) & S_BLOCK1], 4U) ^ RotL64(aInvestLaneC[((aIndex + 18309U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 16764U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 19822U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19650U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 18327U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aPrevious, 57U)) ^ (RotL64(aCarry, 21U) ^ RotL64(aIngress, 36U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = ((aWandererG + RotL64(aIngress, 12U)) + RotL64(aCarry, 27U)) + 18144572925667544139U;
            aOrbiterC = ((aWandererB + RotL64(aScatter, 57U)) + RotL64(aCarry, 51U)) + 5659758077574059728U;
            aOrbiterB = ((aWandererF + RotL64(aCross, 43U)) + RotL64(aCarry, 39U)) + 6343330616999166392U;
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 29U)) + 17754639838410839447U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = (aWandererJ + RotL64(aScatter, 23U)) + 9451843819849581729U;
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 3U)) + 7957854457197462212U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = (aWandererC + RotL64(aIngress, 37U)) + 1461994799722205010U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 18002214276252170177U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 14689869073147027164U;
            aOrbiterB = RotL64((aOrbiterB * 12242482963989582191U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 3978104368003440293U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 8512135845221335386U;
            aOrbiterK = RotL64((aOrbiterK * 10506667163729414667U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 1477533446382953439U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 2166717790929947990U;
            aOrbiterF = RotL64((aOrbiterF * 6538884492418324461U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 8082437060686606995U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 4363687722464700362U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7199165810993478887U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 15782763348014924206U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 8572509150015960728U;
            aOrbiterE = RotL64((aOrbiterE * 3340528604891897779U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 12248271773316742521U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 9602078627638561949U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1860631869877427405U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 17244849374768558859U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 1030743048280579012U;
            aOrbiterC = RotL64((aOrbiterC * 10858949914285817051U), 57U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterD, 53U);
            aIngress = aIngress + (RotL64(aOrbiterE, 26U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 35U));
            aIngress = aIngress + RotL64(aOrbiterA, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aScatter, 43U) + aOrbiterD) + RotL64(aOrbiterK, 21U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterK, 51U)) + aOrbiterA);
            aWandererF = aWandererF + ((((RotL64(aCross, 22U) + RotL64(aOrbiterD, 35U)) + aOrbiterF) + RotL64(aCarry, 5U)) + aPhaseEWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 35U) + aOrbiterE) + RotL64(aOrbiterD, 3U));
            aWandererK = aWandererK + (((RotL64(aIngress, 13U) + RotL64(aOrbiterC, 27U)) + aOrbiterA) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterA, 14U)) + aOrbiterD);
            aWandererG = aWandererG + (((RotL64(aScatter, 5U) + RotL64(aOrbiterB, 57U)) + aOrbiterA) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 34U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + RotL64(aWandererJ, 3U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 26934U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneA[((aIndex + 24167U)) & S_BLOCK1], 44U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 24166U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 27070U)) & S_BLOCK1], 27U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 25192U)) & S_BLOCK1], 46U));
            aCross ^= RotL64(aInvestLaneD[((aIndex + 22507U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 20U) ^ RotL64(aCarry, 51U)) + (RotL64(aCross, 3U) ^ RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = (aWandererC + RotL64(aCross, 41U)) + 12426357877879529292U;
            aOrbiterE = ((aWandererB + RotL64(aScatter, 47U)) + RotL64(aCarry, 5U)) + 12604900366173639176U;
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 60U)) + RotL64(aCarry, 43U)) + 13511119007338929401U;
            aOrbiterH = ((aWandererE + RotL64(aIngress, 13U)) + 9878720081166788060U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = (aWandererG + RotL64(aCross, 3U)) + 15463195409806395076U;
            aOrbiterG = ((aWandererK + RotL64(aScatter, 27U)) + 6407922778852833423U) + aPhaseEOrbiterAssignSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 53U)) + RotL64(aCarry, 19U)) + 7690427254160734016U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 18030974031722143619U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 17983938038322737041U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12479365337221685413U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 16605512170117753884U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 681802273302348322U;
            aOrbiterK = RotL64((aOrbiterK * 14608920184802647123U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 15550312921312083819U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 17824154101711884508U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7358612830654795357U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 1939207786756735430U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 3132864634777826569U;
            aOrbiterH = RotL64((aOrbiterH * 13606281919426730325U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 12822929773923954849U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 16576106045887115660U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16370914370769903051U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 2398825881649235260U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 13700821892926092479U;
            aOrbiterG = RotL64((aOrbiterG * 10830623703416956043U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 2439833784883391606U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 15870638514107637833U;
            aOrbiterJ = RotL64((aOrbiterJ * 3797380922767479287U), 57U);
            //
            aIngress = RotL64(aOrbiterH, 51U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterE, 27U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 5U));
            aIngress = aIngress + RotL64(aOrbiterJ, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 11U) + aOrbiterG) + RotL64(aOrbiterJ, 5U));
            aWandererB = aWandererB + ((((RotL64(aPrevious, 23U) + aOrbiterF) + RotL64(aOrbiterH, 44U)) + RotL64(aCarry, 5U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 43U) + aOrbiterB) + RotL64(aOrbiterE, 13U));
            aWandererE = aWandererE + (((RotL64(aCross, 3U) + RotL64(aOrbiterK, 19U)) + aOrbiterF) + RotL64(aCarry, 47U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 56U) + aOrbiterH) + RotL64(aOrbiterB, 27U));
            aWandererF = aWandererF + (((RotL64(aCross, 29U) + aOrbiterF) + RotL64(aOrbiterB, 51U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 35U) + aOrbiterG) + RotL64(aOrbiterE, 35U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 22U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + RotL64(aWandererJ, 39U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 29917U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneA[((aIndex + 30592U)) & S_BLOCK1], 60U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 32014U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29940U)) & S_BLOCK1], 12U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 29819U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 27712U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aIngress, 39U)) + (RotL64(aPrevious, 26U) + RotL64(aCarry, 13U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = (aWandererD + RotL64(aCross, 5U)) + 4848316479321533394U;
            aOrbiterE = (aWandererC + RotL64(aPrevious, 21U)) + 6919360256662636195U;
            aOrbiterK = (((aWandererK + RotL64(aIngress, 13U)) + RotL64(aCarry, 53U)) + 9897013582181108544U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = (aWandererG + RotL64(aScatter, 38U)) + 7319353809896158678U;
            aOrbiterB = (((aWandererE + RotL64(aCross, 53U)) + RotL64(aCarry, 27U)) + 2848175435514849859U) + aPhaseEOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = ((aWandererH + RotL64(aScatter, 47U)) + RotL64(aCarry, 41U)) + 6967780718720437934U;
            aOrbiterA = (aWandererF + RotL64(aPrevious, 27U)) + 10143884766603388136U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 8675965006150972051U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 16350117755560994281U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15072308930382994425U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 17976597517118423760U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 1399631141355370237U;
            aOrbiterB = RotL64((aOrbiterB * 16537788276543236833U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 3590613762034716792U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 5134624314245932157U;
            aOrbiterE = RotL64((aOrbiterE * 13077589037975283371U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 10082236952942943654U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 4015535035905433450U;
            aOrbiterI = RotL64((aOrbiterI * 4961808568701908559U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 611474103801573800U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 5786708483794098001U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7694007039340089267U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 5201943497363274455U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 9282160506938328489U;
            aOrbiterG = RotL64((aOrbiterG * 5368182164239021367U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 4932320527498940158U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 11576526341731392916U;
            aOrbiterA = RotL64((aOrbiterA * 1712051774729439363U), 5U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterK, 35U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 5U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + RotL64(aOrbiterH, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 29U) + aOrbiterB) + RotL64(aOrbiterA, 11U));
            aWandererD = aWandererD + ((((RotL64(aPrevious, 43U) + RotL64(aOrbiterI, 41U)) + aOrbiterE) + RotL64(aCarry, 41U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterE, 3U)) + aOrbiterH);
            aWandererF = aWandererF + (((RotL64(aScatter, 60U) + aOrbiterG) + RotL64(aOrbiterA, 19U)) + RotL64(aCarry, 57U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterK, 52U)) + aOrbiterI);
            aWandererE = aWandererE + (((RotL64(aIngress, 23U) + aOrbiterA) + RotL64(aOrbiterE, 27U)) + aPhaseEWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 51U) + aOrbiterA) + RotL64(aOrbiterK, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 52U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererF, 23U) ^ aWandererC);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + RotL64(aWandererK, 13U);
            aCarry = aCarry + RotL64(aIngress, 42U);
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

void TwistExpander_Soccer_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
        // read from: aOperationLaneA, aOperationLaneB, aInvestLaneC, aOperationLaneC, aOperationLaneD, aInvestLaneD, aSnowLaneA, aExpandLaneD, aInvestLaneB, aSnowLaneB, aExpandLaneB, aWorkLaneA, aExpandLaneA, aWorkLaneB, aExpandLaneC, aWorkLaneC, aInvestLaneA
        // write to: aSnowLaneA, aSnowLaneB, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // twist_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aInvestLaneC
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aInvestLaneC forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aInvestLaneD
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aInvestLaneD backward/forward random
        // write to: aSnowLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 4042U)) & S_BLOCK1], 24U) ^ RotL64(aOperationLaneB[((aIndex + 1632U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aInvestLaneC[((aIndex + 3205U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4338U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 1438U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 2843U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 42U) + RotL64(aPrevious, 57U)) ^ (RotL64(aCarry, 23U) ^ RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = (aWandererF + RotL64(aScatter, 18U)) + 2783898056762489197U;
            aOrbiterA = ((aWandererC + RotL64(aIngress, 23U)) + 7177192902873343053U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = (aWandererK + RotL64(aPrevious, 43U)) + 12254703232691980774U;
            aOrbiterE = ((aWandererJ + RotL64(aCross, 51U)) + RotL64(aCarry, 41U)) + 15446547245691219559U;
            aOrbiterH = (aWandererG + RotL64(aPrevious, 21U)) + 888475203006174856U;
            aOrbiterJ = (((aWandererI + RotL64(aIngress, 14U)) + RotL64(aCarry, 27U)) + 3649183529366307877U) + aPhaseFOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = (aWandererD + RotL64(aCross, 3U)) + 4642631047518805167U;
            aOrbiterD = (aWandererH + RotL64(aScatter, 29U)) + 6108329730724782250U;
            aOrbiterI = (aWandererE + RotL64(aPrevious, 35U)) + 8334054653023816636U;
            aOrbiterB = (aWandererB + RotL64(aCross, 47U)) + 5891895375031474350U;
            aOrbiterK = ((aWandererA + RotL64(aScatter, 5U)) + RotL64(aCarry, 3U)) + 3176720746238477862U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 6111038696865301675U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 11914998302228682704U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11738924766359642853U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 17005063057791320948U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 18333780598768130670U;
            aOrbiterJ = RotL64((aOrbiterJ * 5416759844884107303U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 2056115016443263153U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 10245512728872962677U;
            aOrbiterD = RotL64((aOrbiterD * 707106795383284903U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 4810366069422162351U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 3051442983125942469U;
            aOrbiterA = RotL64((aOrbiterA * 13558537578054436423U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 9285068547223654308U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 13067251130180968842U;
            aOrbiterG = RotL64((aOrbiterG * 7000687697769766605U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 3203670242792002165U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 1770881716916463461U;
            aOrbiterB = RotL64((aOrbiterB * 13870229847371882171U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 16286823712870537410U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 13067191141829694202U;
            aOrbiterH = RotL64((aOrbiterH * 15629974528467350445U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 3414576315085336932U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 8979691827341555245U;
            aOrbiterI = RotL64((aOrbiterI * 15971594804040295757U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 11370607523115189596U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 1346943598249651668U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4994794423314630209U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 2441719135451272926U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 3347272129827184676U;
            aOrbiterE = RotL64((aOrbiterE * 10434510775894776597U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 1116857329130532047U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 2783898056762489197U;
            aOrbiterK = RotL64((aOrbiterK * 9504855173533274401U), 21U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterF, 21U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 56U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 39U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 3U));
            aIngress = aIngress + (RotL64(aOrbiterK, 19U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterD, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterI, 47U)) + aOrbiterH);
            aWandererC = aWandererC + (((RotL64(aPrevious, 51U) + aOrbiterA) + RotL64(aOrbiterG, 27U)) + RotL64(aCarry, 3U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 53U) + aOrbiterH) + RotL64(aOrbiterD, 12U));
            aWandererG = aWandererG + ((RotL64(aCross, 27U) + aOrbiterE) + RotL64(aOrbiterC, 23U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 36U) + aOrbiterF) + RotL64(aOrbiterE, 53U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 51U)) + aOrbiterB);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterK, 29U)) + aOrbiterE) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aCross, 29U) + RotL64(aOrbiterG, 39U)) + aOrbiterF);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 44U) + RotL64(aOrbiterJ, 43U)) + aOrbiterF) + aPhaseFWandererUpdateSaltC[((aIndex + 12U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 19U) + RotL64(aOrbiterA, 3U)) + aOrbiterH) + RotL64(aCarry, 21U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 41U) + aOrbiterC) + RotL64(aOrbiterF, 10U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 37U));
            aCarry = aCarry + (RotL64(aWandererD, 18U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererI, 20U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aSnowLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 2
        // ingress from: aSnowLaneA, aOperationLaneC, aOperationLaneD, aExpandLaneD
        // ingress directions: aSnowLaneA forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aExpandLaneD forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aInvestLaneB
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aInvestLaneB backward/forward random
        // write to: aSnowLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 6741U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneC[((aIndex + 7021U)) & S_BLOCK1], 40U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 10892U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneD[((aIndex + 9080U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 8639U)) & S_BLOCK1], 38U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 6927U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 10594U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 19U) + RotL64(aIngress, 3U)) ^ (RotL64(aCarry, 52U) + RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = (aWandererI + RotL64(aCross, 51U)) + 12027839670755583592U;
            aOrbiterC = ((aWandererA + RotL64(aScatter, 14U)) + 15380130703509859843U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = (aWandererF + RotL64(aIngress, 43U)) + 4590907433867798074U;
            aOrbiterD = (aWandererJ + RotL64(aPrevious, 21U)) + 1754574023602519724U;
            aOrbiterB = ((aWandererH + RotL64(aIngress, 29U)) + 9832756659564903767U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = (aWandererK + RotL64(aScatter, 39U)) + 5035088494491470403U;
            aOrbiterA = ((aWandererB + RotL64(aCross, 19U)) + RotL64(aCarry, 51U)) + 14199170923323644638U;
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 3U)) + RotL64(aCarry, 43U)) + 8325619421264440438U;
            aOrbiterE = (aWandererC + RotL64(aCross, 54U)) + 969534320779067977U;
            aOrbiterG = (aWandererG + RotL64(aScatter, 23U)) + 270575869402913847U;
            aOrbiterI = ((aWandererD + RotL64(aIngress, 41U)) + RotL64(aCarry, 3U)) + 13344806516599578910U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 15143147951139409101U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 14425582489214169238U;
            aOrbiterK = RotL64((aOrbiterK * 16893787086337916355U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 13951127523239064584U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 14177925225918293579U;
            aOrbiterJ = RotL64((aOrbiterJ * 13079514031864998485U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 8258920744278218901U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 7408161179397242453U;
            aOrbiterB = RotL64((aOrbiterB * 975737128100519169U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 8581481606764773468U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 10078416198417433133U;
            aOrbiterH = RotL64((aOrbiterH * 1102721083915858247U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 18299772198826189580U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 18304668908084397946U;
            aOrbiterG = RotL64((aOrbiterG * 10589455451200578687U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 16729632621573817223U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 13362300981585573239U;
            aOrbiterF = RotL64((aOrbiterF * 9824473895535518785U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 8629682832849915380U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 6852852009091469641U;
            aOrbiterE = RotL64((aOrbiterE * 11912646687050011915U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 7433098156961745198U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 10931806208899417308U;
            aOrbiterA = RotL64((aOrbiterA * 14699197041038067483U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 629604718211675247U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 1487372736719237118U;
            aOrbiterI = RotL64((aOrbiterI * 705192821277928909U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 3567439893461603384U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 11143068753134694333U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15529326960229305389U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 14242098279913980463U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 12027839670755583592U;
            aOrbiterD = RotL64((aOrbiterD * 6630014752150544153U), 57U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterB, 47U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 14U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 5U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 39U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + RotL64(aOrbiterE, 26U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aScatter, 21U) + aOrbiterK) + RotL64(aOrbiterF, 38U));
            aWandererC = aWandererC + ((RotL64(aCross, 47U) + aOrbiterJ) + RotL64(aOrbiterE, 5U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 14U) + aOrbiterI) + RotL64(aOrbiterG, 35U));
            aWandererF = aWandererF + (((RotL64(aIngress, 5U) + aOrbiterB) + RotL64(aOrbiterJ, 43U)) + RotL64(aCarry, 13U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 41U) + aOrbiterA) + RotL64(aOrbiterB, 23U));
            aWandererD = aWandererD + ((RotL64(aIngress, 37U) + RotL64(aOrbiterE, 53U)) + aOrbiterH);
            aWandererK = aWandererK ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterJ, 11U)) + aOrbiterC);
            aWandererE = aWandererE + (((RotL64(aScatter, 53U) + RotL64(aOrbiterH, 60U)) + aOrbiterJ) + RotL64(aCarry, 23U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 43U) + aOrbiterC) + RotL64(aOrbiterI, 3U)) + aPhaseFWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterD, 13U)) + aOrbiterG) + aPhaseFWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterF, 21U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererC, 40U) ^ aWandererI);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 54U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 14311U)) & S_BLOCK1], 54U) ^ RotL64(aOperationLaneA[((aIndex + 13604U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 13553U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 11130U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 14547U)) & S_BLOCK1], 48U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 11U) ^ RotL64(aIngress, 57U)) + (RotL64(aCarry, 42U) ^ RotL64(aPrevious, 29U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = (aWandererA + RotL64(aIngress, 22U)) + 12131317914288566437U;
            aOrbiterB = (aWandererE + RotL64(aPrevious, 29U)) + 5672805657999385496U;
            aOrbiterA = (aWandererJ + RotL64(aScatter, 53U)) + 3581710244233124197U;
            aOrbiterI = (aWandererG + RotL64(aCross, 51U)) + 15251296040538489436U;
            aOrbiterK = (aWandererB + RotL64(aPrevious, 57U)) + 11295008604679904153U;
            aOrbiterC = ((aWandererK + RotL64(aIngress, 27U)) + 2230897493419504490U) + aPhaseFOrbiterAssignSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = (aWandererD + RotL64(aCross, 37U)) + 7109600123297458999U;
            aOrbiterE = (((aWandererC + RotL64(aScatter, 19U)) + RotL64(aCarry, 5U)) + 13119156643107683803U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aCross, 12U)) + RotL64(aCarry, 23U)) + 14755160867807355250U;
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 3U)) + RotL64(aCarry, 41U)) + 16829363373287496832U;
            aOrbiterH = (aWandererI + RotL64(aIngress, 5U)) + 16981122946707720883U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 8806000776958603317U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 16810923047720876014U;
            aOrbiterA = RotL64((aOrbiterA * 17872735050219539145U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 8129657889554436328U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 8653100378491974463U;
            aOrbiterB = RotL64((aOrbiterB * 11395283153912468661U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 17048985838727432415U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 10892675550889823573U;
            aOrbiterG = RotL64((aOrbiterG * 976298937314081913U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 15960158965421254346U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 12290011578634850001U;
            aOrbiterK = RotL64((aOrbiterK * 9280475585104357745U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 16265047040311479093U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 10312956912303656248U;
            aOrbiterF = RotL64((aOrbiterF * 3012584393253845131U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 16706890352221352779U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 10630955894218491929U;
            aOrbiterE = RotL64((aOrbiterE * 12675937483456206355U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 4009352551041162434U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 3043810773683888556U;
            aOrbiterH = RotL64((aOrbiterH * 4328135390387997315U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 1398071019814944785U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 16689766557488135301U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8403881916549404871U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 15934647144489136524U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 13521276033614992223U;
            aOrbiterC = RotL64((aOrbiterC * 18003640895553609933U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 4281211055727414100U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 11848150507497406421U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1107789990317433481U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 12022829841608199449U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 12131317914288566437U;
            aOrbiterI = RotL64((aOrbiterI * 13275753083882829973U), 57U);
            //
            aIngress = RotL64(aOrbiterD, 54U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterJ, 37U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 23U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 35U));
            aIngress = aIngress + (RotL64(aOrbiterG, 5U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterI, 41U)) + aOrbiterE);
            aWandererI = aWandererI + (((RotL64(aScatter, 11U) + RotL64(aOrbiterD, 38U)) + aOrbiterH) + RotL64(aCarry, 13U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 39U) + aOrbiterB) + RotL64(aOrbiterJ, 27U));
            aWandererB = aWandererB + (((RotL64(aIngress, 37U) + RotL64(aOrbiterF, 43U)) + aOrbiterG) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterH, 35U)) + aOrbiterB);
            aWandererF = aWandererF + (((RotL64(aScatter, 24U) + aOrbiterD) + RotL64(aOrbiterC, 19U)) + aPhaseFWandererUpdateSaltF[((aIndex + 26U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterD, 21U)) + aOrbiterK);
            aWandererH = aWandererH + (((RotL64(aIngress, 3U) + aOrbiterE) + RotL64(aOrbiterK, 29U)) + RotL64(aCarry, 47U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 43U) + aOrbiterG) + RotL64(aOrbiterH, 53U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 56U) + RotL64(aOrbiterA, 48U)) + aOrbiterK);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterG, 23U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererE, 34U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 10U));
            aCarry = aCarry + RotL64(aWandererH, 27U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 4
        // ingress from: aWorkLaneA, aSnowLaneA, aExpandLaneA
        // ingress directions: aWorkLaneA forward forced, aSnowLaneA forward forced, aExpandLaneA forward/backward random
        // cross from: aSnowLaneB, aOperationLaneD
        // cross directions: aSnowLaneB backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 16852U)) & S_BLOCK1], 41U) ^ RotL64(aSnowLaneA[((aIndex + 21156U)) & S_BLOCK1], 12U));
            aIngress ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 16699U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 18333U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 16736U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 35U) + RotL64(aIngress, 50U)) + (RotL64(aPrevious, 23U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = (((aWandererG + RotL64(aScatter, 29U)) + RotL64(aCarry, 35U)) + 13442819395490639310U) + aPhaseFOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = (aWandererF + RotL64(aIngress, 27U)) + 8187292523194120936U;
            aOrbiterH = (aWandererH + RotL64(aPrevious, 23U)) + 11469697159823131388U;
            aOrbiterG = (aWandererD + RotL64(aCross, 6U)) + 13414083692375929653U;
            aOrbiterD = (aWandererC + RotL64(aPrevious, 51U)) + 11404010733687907517U;
            aOrbiterB = (aWandererA + RotL64(aScatter, 41U)) + 6783212827186218247U;
            aOrbiterK = ((aWandererI + RotL64(aIngress, 13U)) + 8561131439340372614U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = ((aWandererK + RotL64(aCross, 57U)) + RotL64(aCarry, 19U)) + 6252609642004429113U;
            aOrbiterI = (aWandererB + RotL64(aScatter, 47U)) + 12804867444200448952U;
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 44U)) + RotL64(aCarry, 47U)) + 2739648749603690781U;
            aOrbiterE = (aWandererE + RotL64(aPrevious, 39U)) + 14808861217017399752U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 17588866502571268888U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 5882260142735642980U;
            aOrbiterH = RotL64((aOrbiterH * 7688252946143263869U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 15493099088132862949U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 5175647411532429582U;
            aOrbiterB = RotL64((aOrbiterB * 15226544495598541883U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 14279707376173642767U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 6826363572161275158U;
            aOrbiterD = RotL64((aOrbiterD * 5263708315440161809U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 13267185753040999992U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 9980987858092888720U;
            aOrbiterA = RotL64((aOrbiterA * 13210290848800728635U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 3582972937645514549U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 10140409019562890804U;
            aOrbiterC = RotL64((aOrbiterC * 6944490201647678479U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 6160444117287330557U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 16344602960561293113U;
            aOrbiterK = RotL64((aOrbiterK * 2319964919335633293U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 3497141036108337171U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 91269118352540308U;
            aOrbiterJ = RotL64((aOrbiterJ * 5160060720189045505U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 12739932748793144857U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 12820180915064791197U;
            aOrbiterE = RotL64((aOrbiterE * 5843849637411948699U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 17572075652083359962U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 10684041099654982701U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7121293375756263771U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 10739534650885677354U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 9731206787727954809U;
            aOrbiterG = RotL64((aOrbiterG * 3730875775588585547U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 9655432616347117764U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 13442819395490639310U;
            aOrbiterF = RotL64((aOrbiterF * 3650859301708619119U), 27U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterH, 11U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 51U));
            aIngress = aIngress + (RotL64(aOrbiterA, 40U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterE, 27U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 19U));
            aIngress = aIngress + RotL64(aOrbiterK, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterB, 19U)) + aOrbiterE);
            aWandererB = aWandererB + ((RotL64(aPrevious, 34U) + RotL64(aOrbiterE, 11U)) + aOrbiterD);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 3U) + aOrbiterB) + RotL64(aOrbiterC, 36U));
            aWandererD = aWandererD + (((RotL64(aScatter, 23U) + RotL64(aOrbiterH, 43U)) + aOrbiterJ) + RotL64(aCarry, 37U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 21U) + aOrbiterG) + RotL64(aOrbiterH, 3U)) + aPhaseFWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 53U) + aOrbiterE) + RotL64(aOrbiterA, 13U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 51U) + aOrbiterK) + RotL64(aOrbiterB, 21U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterG, 57U)) + aOrbiterF);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 38U) + aOrbiterI) + RotL64(aOrbiterD, 40U));
            aWandererI = aWandererI + (((RotL64(aCross, 13U) + RotL64(aOrbiterI, 53U)) + aOrbiterF) + RotL64(aCarry, 57U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 57U) + aOrbiterG) + RotL64(aOrbiterI, 51U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + (RotL64(aWandererI, 34U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererD);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 37U));
            aCarry = aCarry + (RotL64(aWandererF, 27U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererJ, 41U);
            aCarry = aCarry + RotL64(aIngress, 20U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_c loop 5
        // ingress from: aWorkLaneB, aSnowLaneB, aExpandLaneC
        // ingress directions: aWorkLaneB forward forced, aSnowLaneB forward forced, aExpandLaneC forward/backward random
        // cross from: aWorkLaneA, aSnowLaneA
        // cross directions: aWorkLaneA backward forced, aSnowLaneA backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 24624U)) & S_BLOCK1], 13U) ^ RotL64(aSnowLaneB[((aIndex + 25739U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 25812U)) & S_BLOCK1], 52U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22975U)) & S_BLOCK1], 47U) ^ RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 26159U)) & S_BLOCK1], 20U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCross, 26U)) + (RotL64(aIngress, 5U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 47U)) + RotL64(aCarry, 47U)) + 4622023259121087483U;
            aOrbiterC = (aWandererD + RotL64(aPrevious, 19U)) + 10253505250223501352U;
            aOrbiterA = (aWandererC + RotL64(aScatter, 27U)) + 17133877904420462669U;
            aOrbiterE = ((aWandererA + RotL64(aCross, 3U)) + RotL64(aCarry, 13U)) + 6162827793741796700U;
            aOrbiterJ = (aWandererF + RotL64(aIngress, 11U)) + 9610986424765907615U;
            aOrbiterK = (aWandererI + RotL64(aPrevious, 23U)) + 11210747154264753754U;
            aOrbiterG = ((aWandererH + RotL64(aScatter, 54U)) + RotL64(aCarry, 19U)) + 16554205219580654546U;
            aOrbiterB = (aWandererK + RotL64(aCross, 35U)) + 10352576357413766388U;
            aOrbiterH = ((aWandererG + RotL64(aScatter, 37U)) + 3651845783283479752U) + aPhaseFOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = (aWandererB + RotL64(aIngress, 21U)) + 18145542190463500476U;
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 14U)) + 5415609566767162857U) + aPhaseFOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 2033734872464201570U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 3507213117125813345U;
            aOrbiterA = RotL64((aOrbiterA * 5453058336688881113U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 8716253393049851856U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 695984869565941856U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8377921610764044735U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 7661578828878284931U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 906654265099155956U;
            aOrbiterG = RotL64((aOrbiterG * 8117625377607536949U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 6050049984731254612U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 17882717590338190821U;
            aOrbiterH = RotL64((aOrbiterH * 10807367411402733215U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 4996521991532815957U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 4246460672800604436U;
            aOrbiterI = RotL64((aOrbiterI * 12047466401960824903U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 8700148116452518842U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 10039050281847466206U;
            aOrbiterC = RotL64((aOrbiterC * 11884791271239660157U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 4513844680425845372U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 3037563127442815153U;
            aOrbiterB = RotL64((aOrbiterB * 18363509277992292407U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 1005237931570968724U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 1373258132025712065U;
            aOrbiterK = RotL64((aOrbiterK * 10458020799382532395U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 12759144329395682277U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 5139371668116336931U;
            aOrbiterE = RotL64((aOrbiterE * 10761543179345026943U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 3211005174890625715U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 18045286961878287418U;
            aOrbiterF = RotL64((aOrbiterF * 4536094526540761611U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 4454078771279674978U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 4622023259121087483U;
            aOrbiterD = RotL64((aOrbiterD * 8991756794989027019U), 35U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterJ, 35U);
            aIngress = aIngress + (RotL64(aOrbiterB, 41U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterH, 23U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 53U));
            aIngress = aIngress + (RotL64(aOrbiterK, 14U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterC, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterD, 48U)) + aOrbiterH);
            aWandererE = aWandererE + (((RotL64(aScatter, 53U) + RotL64(aOrbiterA, 5U)) + aOrbiterH) + RotL64(aCarry, 35U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 40U) + aOrbiterJ) + RotL64(aOrbiterE, 43U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterF, 39U)) + aOrbiterE) + aPhaseFWandererUpdateSaltB[((aIndex + 4U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterA, 37U)) + aOrbiterD) + aPhaseFWandererUpdateSaltA[((aIndex + 6U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterK, 23U)) + aOrbiterC);
            aWandererC = aWandererC ^ ((RotL64(aCross, 23U) + aOrbiterC) + RotL64(aOrbiterI, 35U));
            aWandererB = aWandererB + ((RotL64(aIngress, 47U) + aOrbiterB) + RotL64(aOrbiterE, 53U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 6U) + RotL64(aOrbiterI, 30U)) + aOrbiterG);
            aWandererD = aWandererD + (((RotL64(aCross, 57U) + RotL64(aOrbiterH, 57U)) + aOrbiterJ) + RotL64(aCarry, 3U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterI, 13U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererG, 30U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererA, 21U) ^ aWandererJ);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 51U));
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererI);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 42U));
            aCarry = aCarry + RotL64(aWandererB, 37U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 6
        // ingress from: aWorkLaneC, aWorkLaneA, aInvestLaneA
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aInvestLaneA forward/backward random
        // cross from: aWorkLaneB, aOperationLaneB
        // cross directions: aWorkLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 29548U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((aIndex + 29657U)) & S_BLOCK1], 4U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 30999U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32478U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneB[((aIndex + 31109U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 48U) + RotL64(aPrevious, 23U)) ^ (RotL64(aIngress, 5U) ^ RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = (aWandererI + RotL64(aIngress, 35U)) + 16651241552253078315U;
            aOrbiterE = (aWandererH + RotL64(aPrevious, 47U)) + 4558144676982478003U;
            aOrbiterK = ((aWandererD + RotL64(aCross, 5U)) + 8814884320080367550U) + aPhaseFOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = (aWandererF + RotL64(aScatter, 26U)) + 16011579668555672117U;
            aOrbiterF = ((aWandererC + RotL64(aCross, 51U)) + RotL64(aCarry, 23U)) + 4738918668759862438U;
            aOrbiterD = ((aWandererE + RotL64(aScatter, 21U)) + RotL64(aCarry, 5U)) + 12526083125540985108U;
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 3U)) + 8048723561746000552U) + aPhaseFOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = (aWandererK + RotL64(aIngress, 14U)) + 1082218464034639039U;
            aOrbiterG = (aWandererA + RotL64(aScatter, 11U)) + 8432043246965946816U;
            aOrbiterA = ((aWandererG + RotL64(aIngress, 29U)) + RotL64(aCarry, 51U)) + 9982080524048636852U;
            aOrbiterI = (aWandererJ + RotL64(aCross, 19U)) + 6720069955755215919U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 1019035028070247757U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 7360619079463870467U;
            aOrbiterK = RotL64((aOrbiterK * 6623074813047915863U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 10893918488381348474U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 1390297670907738019U;
            aOrbiterF = RotL64((aOrbiterF * 11909657437658597735U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 12512200589031203480U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 14741471280748399540U;
            aOrbiterB = RotL64((aOrbiterB * 3012135242889901095U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 8543897248359826770U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 8545972622733791272U;
            aOrbiterJ = RotL64((aOrbiterJ * 11793879362775346821U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 7049384618581928664U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 14730773807906925408U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10711566871536755073U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 11480717275652449986U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 1135397594974536859U;
            aOrbiterG = RotL64((aOrbiterG * 6347492892938856497U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 6897207625849516702U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 10920630712550287148U;
            aOrbiterH = RotL64((aOrbiterH * 4140705091806993359U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 1094056478999931332U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 6784487144549717207U;
            aOrbiterA = RotL64((aOrbiterA * 6295177724167067891U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 2224992798329560875U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 11486442570446223696U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5680065455032616591U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 14681556190496625711U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 1809388635055225841U;
            aOrbiterI = RotL64((aOrbiterI * 3449474313001177557U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 4480846057441948619U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 16651241552253078315U;
            aOrbiterE = RotL64((aOrbiterE * 10628778876898064085U), 13U);
            //
            aIngress = RotL64(aOrbiterB, 37U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 14U));
            aIngress = aIngress + (RotL64(aOrbiterC, 23U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 51U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + RotL64(aOrbiterF, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aIngress, 41U) + RotL64(aOrbiterB, 47U)) + aOrbiterA);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterK, 39U)) + aOrbiterF);
            aWandererH = aWandererH + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterI, 10U)) + aOrbiterC) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 39U) + aOrbiterC) + RotL64(aOrbiterF, 37U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 24U) + RotL64(aOrbiterA, 23U)) + aOrbiterK);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterI, 3U)) + aOrbiterG);
            aWandererG = aWandererG + (((RotL64(aCross, 35U) + RotL64(aOrbiterE, 57U)) + aOrbiterJ) + RotL64(aCarry, 47U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 11U) + aOrbiterE) + RotL64(aOrbiterD, 53U));
            aWandererK = aWandererK + ((RotL64(aCross, 4U) + RotL64(aOrbiterJ, 30U)) + aOrbiterI);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterH, 41U)) + aOrbiterD);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 37U) + aOrbiterH) + RotL64(aOrbiterJ, 35U)) + RotL64(aCarry, 19U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 6U));
            aCarry = aCarry + (RotL64(aWandererD, 21U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererB, 52U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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

void TwistExpander_Soccer_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
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
        // ingress from: aWorkLaneA, aWorkLaneB, aInvestLaneA
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aInvestLaneA forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aOperationLaneA
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aOperationLaneA backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 6390U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((aIndex + 3900U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 5670U)) & S_BLOCK1], 42U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 3702U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 5367U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aOperationLaneA[((aIndex + 3064U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 3U) + RotL64(aCarry, 18U)) ^ (RotL64(aIngress, 51U) ^ RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = ((aWandererE + RotL64(aIngress, 21U)) + RotL64(aCarry, 5U)) + 14179205183062705133U;
            aOrbiterA = (((aWandererF + RotL64(aPrevious, 12U)) + RotL64(aCarry, 23U)) + 210032324058740920U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = (aWandererA + RotL64(aCross, 57U)) + 7387115089142500152U;
            aOrbiterE = (((aWandererD + RotL64(aScatter, 37U)) + RotL64(aCarry, 41U)) + 17583362781238061430U) + aPhaseGOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = (aWandererK + RotL64(aCross, 47U)) + 4991442849150005943U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 2891376254689854555U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 10523274382407446239U;
            aOrbiterB = RotL64((aOrbiterB * 17443994099359920915U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 3861893764676218667U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 3366674459852093746U;
            aOrbiterA = RotL64((aOrbiterA * 14005994095369483813U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 5898492634386601145U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 7047353571244768721U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2257518291062508467U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 14374108805453186316U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 8763667021501226510U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7694695426430267863U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 18261523829316379575U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 650477532238860965U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8291758490821819851U), 19U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterH, 37U);
            aIngress = aIngress + (RotL64(aOrbiterE, 11U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterA, 58U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aIngress, 11U) + aOrbiterE) + RotL64(aOrbiterH, 47U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 47U) + aOrbiterC) + RotL64(aOrbiterA, 39U));
            aWandererK = aWandererK + (((RotL64(aCross, 27U) + aOrbiterE) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 43U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 58U) + aOrbiterH) + RotL64(aOrbiterB, 57U)) + aPhaseGWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aIngress, 3U) + aOrbiterA) + RotL64(aOrbiterE, 30U)) + RotL64(aCarry, 3U)) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererF);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 52U));
            aCarry = aCarry + RotL64(aWandererE, 35U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 13697U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneC[((aIndex + 9143U)) & S_BLOCK1], 14U));
            aIngress ^= RotL64(aInvestLaneB[((aIndex + 13224U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12779U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 15998U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 11494U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 58U) ^ RotL64(aIngress, 35U)) ^ (RotL64(aCarry, 23U) + RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = (((aWandererK + RotL64(aIngress, 13U)) + RotL64(aCarry, 53U)) + 7893287783892523139U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 21U)) + RotL64(aCarry, 3U)) + 10257331997383491153U;
            aOrbiterK = (((aWandererA + RotL64(aScatter, 39U)) + RotL64(aCarry, 21U)) + 14562226733652231753U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterC = (aWandererB + RotL64(aCross, 29U)) + 14320342577110737851U;
            aOrbiterJ = (aWandererJ + RotL64(aPrevious, 56U)) + 9816717579822880756U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 9558926960095881953U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 9230371862654338324U;
            aOrbiterK = RotL64((aOrbiterK * 8842712825810461561U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 6414274291252913420U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 13868546184398350849U;
            aOrbiterJ = RotL64((aOrbiterJ * 1547986864837497409U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 16940736952569949038U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 2866957764814864371U;
            aOrbiterA = RotL64((aOrbiterA * 3554702178644797003U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 7916721976073979724U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 1602444214978842275U;
            aOrbiterF = RotL64((aOrbiterF * 11072503711308122385U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 9529061385251008037U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 8402775110887376588U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13980225144628227381U), 5U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterJ, 37U);
            aIngress = aIngress + (RotL64(aOrbiterF, 19U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterA, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterC, 37U)) + aOrbiterK);
            aWandererB = aWandererB + (((RotL64(aScatter, 57U) + RotL64(aOrbiterA, 5U)) + aOrbiterJ) + RotL64(aCarry, 11U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 20U) + aOrbiterF) + RotL64(aOrbiterA, 46U)) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 43U) + RotL64(aOrbiterF, 29U)) + aOrbiterC) + RotL64(aCarry, 53U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterK, 19U)) + aOrbiterF) + aPhaseGWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 58U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + RotL64(aWandererJ, 47U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 18321U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneD[((aIndex + 18907U)) & S_BLOCK1], 60U));
            aIngress ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 20254U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22868U)) & S_BLOCK1], 34U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21438U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 24065U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCarry, 29U)) ^ (RotL64(aCross, 58U) ^ RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 58U)) + RotL64(aCarry, 5U)) + 2672739400294801233U;
            aOrbiterF = (aWandererI + RotL64(aCross, 19U)) + 8475624545015101850U;
            aOrbiterC = (((aWandererJ + RotL64(aScatter, 29U)) + RotL64(aCarry, 19U)) + 1252755112289831257U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterD = ((aWandererK + RotL64(aIngress, 43U)) + RotL64(aCarry, 43U)) + 7938039507649183387U;
            aOrbiterA = ((aWandererG + RotL64(aScatter, 11U)) + 8167413146948861022U) + aPhaseGOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1];
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 17712313989694374353U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 7637042279892596975U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13056020836704050293U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 15770412950033467341U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 3951812021898608685U;
            aOrbiterE = RotL64((aOrbiterE * 6623127125223204737U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 8656983621098246507U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 17943342344730687317U;
            aOrbiterF = RotL64((aOrbiterF * 16495519451034883813U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 3087677463651608668U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 16493240011924342788U;
            aOrbiterD = RotL64((aOrbiterD * 16898479041530771871U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 7750923317452683057U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 2185924841611106546U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 708072658250726381U), 3U);
            //
            aIngress = RotL64(aOrbiterF, 54U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterA, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 39U) + aOrbiterA) + RotL64(aOrbiterE, 27U));
            aWandererI = aWandererI + (((RotL64(aCross, 13U) + RotL64(aOrbiterC, 13U)) + aOrbiterF) + RotL64(aCarry, 57U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 47U) + aOrbiterA) + RotL64(aOrbiterD, 58U)) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterD, 43U)) + aOrbiterC) + RotL64(aCarry, 13U)) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 56U) + aOrbiterD) + RotL64(aOrbiterE, 35U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 22U));
            aCarry = aCarry + RotL64(aWandererI, 5U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 31769U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneA[((aIndex + 29583U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 30933U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28795U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 28337U)) & S_BLOCK1], 4U));
            aCross ^= RotL64(aOperationLaneD[((aIndex + 29273U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCross, 41U)) + (RotL64(aIngress, 21U) + RotL64(aCarry, 56U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = (((aWandererB + RotL64(aScatter, 29U)) + RotL64(aCarry, 35U)) + 7948891781097675369U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = ((aWandererE + RotL64(aCross, 38U)) + RotL64(aCarry, 47U)) + 13928362874228230226U;
            aOrbiterI = (((aWandererC + RotL64(aIngress, 21U)) + RotL64(aCarry, 21U)) + 10776180542602258926U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = (aWandererH + RotL64(aPrevious, 47U)) + 5735115172149470447U;
            aOrbiterD = (aWandererD + RotL64(aCross, 13U)) + 5353591822981766987U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 562301708107268570U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 10467810247578364868U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10449089554007059823U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 14541630141152308564U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 2350076897065139429U;
            aOrbiterK = RotL64((aOrbiterK * 12222554362482034393U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 17519109078651162228U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 6061035173339902910U;
            aOrbiterB = RotL64((aOrbiterB * 10021905773432907835U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 15654836633731000065U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 13723521735153718904U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14459516479283070563U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 2849680038315532197U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 17336102435576647923U;
            aOrbiterD = RotL64((aOrbiterD * 10984689101753586739U), 29U);
            //
            aIngress = RotL64(aOrbiterK, 39U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aCross, 24U) + aOrbiterB) + RotL64(aOrbiterA, 51U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterI, 19U)) + aOrbiterB);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 43U) + RotL64(aOrbiterA, 40U)) + aOrbiterD) + RotL64(aCarry, 27U)) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterA, 29U)) + aOrbiterK) + aPhaseGWandererUpdateSaltD[((aIndex + 18U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 11U) + aOrbiterK) + RotL64(aOrbiterI, 3U)) + RotL64(aCarry, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererH);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 22U));
            aCarry = aCarry + RotL64(aWandererE, 13U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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

void TwistExpander_Soccer_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
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
        // ingress from: aExpandLaneA, aExpandLaneB, aInvestLaneA
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aInvestLaneA forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aOperationLaneA
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aOperationLaneA backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 1113U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneB[((aIndex + 6305U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 6532U)) & S_BLOCK1], 38U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7973U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 5417U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aOperationLaneA[((aIndex + 1288U)) & S_BLOCK1], 38U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 11U) + RotL64(aCross, 23U)) ^ (RotL64(aCarry, 36U) ^ RotL64(aPrevious, 51U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = (aWandererB + RotL64(aIngress, 5U)) + 6163290588946759209U;
            aOrbiterJ = (((aWandererF + RotL64(aPrevious, 48U)) + RotL64(aCarry, 23U)) + 7342672468560105447U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterC = ((aWandererK + RotL64(aScatter, 57U)) + RotL64(aCarry, 39U)) + 11574563167017282321U;
            aOrbiterB = ((aWandererH + RotL64(aCross, 37U)) + 2254820206194758964U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterI = ((aWandererI + RotL64(aIngress, 27U)) + RotL64(aCarry, 3U)) + 1469783447473099498U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 14174828900676165088U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 16277954291890598132U;
            aOrbiterC = RotL64((aOrbiterC * 4608888834164373691U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 14845750668693136766U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 150099699692047766U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7644895634421086357U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 1200784917165131703U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 9469982764806754302U;
            aOrbiterI = RotL64((aOrbiterI * 17851969334511301943U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 10956702761701710182U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 7915506894975487807U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8874108311712727983U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 17335794183733623213U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 557028996286989506U;
            aOrbiterB = RotL64((aOrbiterB * 3993359298602424281U), 37U);
            //
            aIngress = RotL64(aOrbiterD, 57U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 24U));
            aIngress = aIngress + RotL64(aOrbiterJ, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aPrevious, 43U) + aOrbiterJ) + RotL64(aOrbiterB, 57U)) + RotL64(aCarry, 29U)) + aPhaseHWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterI, 29U)) + aOrbiterJ);
            aWandererF = aWandererF + ((RotL64(aIngress, 29U) + RotL64(aOrbiterB, 47U)) + aOrbiterD);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 54U) + RotL64(aOrbiterC, 20U)) + aOrbiterB);
            aWandererH = aWandererH + ((((RotL64(aIngress, 21U) + RotL64(aOrbiterC, 5U)) + aOrbiterI) + RotL64(aCarry, 3U)) + aPhaseHWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + RotL64(aWandererK, 23U);
            aCarry = aCarry + RotL64(aIngress, 14U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 10436U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneC[((aIndex + 14099U)) & S_BLOCK1], 58U));
            aIngress ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 10144U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 14615U)) & S_BLOCK1], 36U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 12132U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 10821U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 51U) ^ RotL64(aPrevious, 23U)) + (RotL64(aIngress, 4U) + RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 48U)) + RotL64(aCarry, 37U)) + 10038936806177516123U;
            aOrbiterH = ((aWandererA + RotL64(aCross, 5U)) + RotL64(aCarry, 19U)) + 1773168435195292638U;
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 13U)) + 10655711161526628072U) + aPhaseHOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 57U)) + RotL64(aCarry, 57U)) + 14422295664639740437U;
            aOrbiterC = ((aWandererD + RotL64(aCross, 27U)) + 4125228715513159576U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 3670449653158650845U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 17553727567180813057U;
            aOrbiterJ = RotL64((aOrbiterJ * 11814335762020146785U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 5111401772713882743U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 7688573124662314413U;
            aOrbiterC = RotL64((aOrbiterC * 10846442063022821393U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 9438375825507814395U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 14177477039902118886U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6467406626985022537U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 16329942595859623928U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 3990536794006836672U;
            aOrbiterA = RotL64((aOrbiterA * 579024714339065373U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 5072881436583180756U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 16789727877867289997U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8766246302636197905U), 51U);
            //
            aIngress = RotL64(aOrbiterH, 60U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 37U));
            aIngress = aIngress + RotL64(aOrbiterJ, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aIngress, 57U) + aOrbiterH) + RotL64(aOrbiterE, 6U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterE, 43U)) + aOrbiterJ);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 29U) + aOrbiterA) + RotL64(aOrbiterE, 53U)) + RotL64(aCarry, 53U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 3U) + aOrbiterC) + RotL64(aOrbiterJ, 21U)) + aPhaseHWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 18U) + RotL64(aOrbiterJ, 35U)) + aOrbiterA) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 60U));
            aCarry = aCarry + RotL64(aWandererA, 39U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 18193U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneD[((aIndex + 22206U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 17091U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18007U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 19978U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 22508U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 35U) ^ RotL64(aCarry, 51U)) ^ (RotL64(aPrevious, 19U) + RotL64(aCross, 4U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = (aWandererK + RotL64(aCross, 29U)) + 8020711767807230555U;
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 21U)) + RotL64(aCarry, 3U)) + 15368693777246341570U;
            aOrbiterA = ((aWandererB + RotL64(aIngress, 13U)) + RotL64(aCarry, 51U)) + 5117523734225562401U;
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 37U)) + 13155269151097507808U) + aPhaseHOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = (((aWandererI + RotL64(aCross, 56U)) + RotL64(aCarry, 29U)) + 9879303753623578272U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 1165799257173794826U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 930641942062732091U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17151944851548731159U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 11330571332221123153U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 2862963158282518899U;
            aOrbiterD = RotL64((aOrbiterD * 13782195862525974199U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 6019186399361476659U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 1924419843785161958U;
            aOrbiterF = RotL64((aOrbiterF * 9485557122500346869U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 12618629043591380461U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 9334176504266512405U;
            aOrbiterB = RotL64((aOrbiterB * 18239109235362925739U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 16829692481030013551U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 5604784396927022709U;
            aOrbiterJ = RotL64((aOrbiterJ * 2833893610883508353U), 27U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterF, 57U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 37U));
            aIngress = aIngress + RotL64(aOrbiterD, 4U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aScatter, 21U) + aOrbiterA) + RotL64(aOrbiterJ, 28U)) + aPhaseHWandererUpdateSaltD[((aIndex + 18U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 40U) + aOrbiterD) + RotL64(aOrbiterB, 51U)) + RotL64(aCarry, 37U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 57U) + aOrbiterF) + RotL64(aOrbiterB, 11U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 29U) + RotL64(aOrbiterD, 3U)) + aOrbiterA) + RotL64(aCarry, 5U)) + aPhaseHWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterA, 43U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererB, 13U);
            aCarry = aCarry + RotL64(aIngress, 54U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 32311U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneA[((aIndex + 27020U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aInvestLaneD[((aIndex + 31635U)) & S_BLOCK1], 38U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28586U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 25026U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 31147U)) & S_BLOCK1], 28U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 12U) ^ RotL64(aCross, 51U)) ^ (RotL64(aPrevious, 27U) + RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = ((aWandererD + RotL64(aIngress, 53U)) + RotL64(aCarry, 57U)) + 9751314027302668907U;
            aOrbiterB = (aWandererF + RotL64(aScatter, 11U)) + 12175450995523107056U;
            aOrbiterC = (((aWandererK + RotL64(aPrevious, 35U)) + RotL64(aCarry, 35U)) + 17519694958730119552U) + aPhaseHOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = (aWandererI + RotL64(aCross, 44U)) + 9093525527925682263U;
            aOrbiterJ = (((aWandererE + RotL64(aScatter, 23U)) + RotL64(aCarry, 23U)) + 3713831321786810138U) + aPhaseHOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1];
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 10108355209191835040U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 12956307447311314768U;
            aOrbiterC = RotL64((aOrbiterC * 9198936928658626667U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 1904298513945877359U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 4658049993308574460U;
            aOrbiterB = RotL64((aOrbiterB * 10482422152074338611U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 9826333658248851902U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 12058666914724365134U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 964233873188373939U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 2516574707110528099U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 13335308331049750235U;
            aOrbiterK = RotL64((aOrbiterK * 5880227828760598587U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 8230749255538495304U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 16536559486797811486U;
            aOrbiterA = RotL64((aOrbiterA * 7097036838156464969U), 13U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterK, 6U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 19U));
            aIngress = aIngress + RotL64(aOrbiterC, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 47U) + aOrbiterJ) + RotL64(aOrbiterC, 48U));
            aWandererE = aWandererE + (((RotL64(aIngress, 10U) + RotL64(aOrbiterA, 21U)) + aOrbiterK) + RotL64(aCarry, 51U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterA, 3U)) + aOrbiterB);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 57U) + aOrbiterK) + RotL64(aOrbiterJ, 35U)) + RotL64(aCarry, 37U)) + aPhaseHWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 37U) + RotL64(aOrbiterC, 11U)) + aOrbiterB) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 36U));
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 13U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
