#include "TwistExpander_Bowling_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_Bowling_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     std::uint8_t *pSource,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x864855843881DA8BULL + 0xDA953B6357DC571AULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x8A0D55105612587FULL + 0x80DABBB57ACCD1D1ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xA981A25D307F3A87ULL + 0xFB9669F67DA40DDFULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xEB2731D9E3B3E8C1ULL + 0xA0705DE9A75E026CULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x826C7B32ADCF5583ULL + 0xDC0D3CC2F7F9C9F7ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xCD5CC3FF63D892CFULL + 0x9FB4446A5C3F47BEULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x93B39AD258DEDAEFULL + 0xD0C3732C41B7F852ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xD1AB8DE43C9206B9ULL + 0x8EC6E0E7117A9C9DULL);
    std::uint64_t aDomainWordIngress = pConstants->mIngress;
    std::uint64_t aDomainWordScatter = pConstants->mScatter;
    std::uint64_t aDomainWordCross = pConstants->mCross;
    [[maybe_unused]] std::uint8_t *mSource = pSource;
    [[maybe_unused]] std::uint8_t *mSnow = pSnow;
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
        // read from: mSource, mSnow, aWorkLaneA, aWorkLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC
        // write to: aWorkLaneA, aWorkLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_a_loop_a loop 1
        // read from: mSource, mSnow
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 13U) ^ RotL64(aNonceWordD, 5U)) ^ RotL64(aNonceWordA, 46U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 4277U)) & S_BLOCK1], 37U) ^ RotL64(mSnow[((aIndex + 2050U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 3U) ^ RotL64(aNonceWordH, 11U));
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 5278U)) & S_BLOCK1], 35U) ^ RotL64(mSnow[((S_BLOCK1 - aIndex + 4199U)) & S_BLOCK1], 50U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 60U) + RotL64(aCross, 43U)) + (RotL64(aCarry, 27U) ^ RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererI + RotL64(aPrevious, 41U)) + 13915875634607599122U;
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 54U)) + 1695770381382411673U) + aOrbiterAssignSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = ((aWandererG + RotL64(aIngress, 11U)) + RotL64(aCarry, 35U)) + 3709105579778295511U;
            aOrbiterI = ((aWandererE + RotL64(aCross, 35U)) + 7673376335333251804U) + RotL64(aNonceWordA, 19U);
            aOrbiterD = (aWandererD + RotL64(aIngress, 57U)) + 8814147709738503518U;
            aOrbiterB = (((aWandererC + RotL64(aCross, 39U)) + RotL64(aCarry, 11U)) + 13451412605350381172U) + RotL64(aNonceWordE, 41U);
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 29U)) + 6447870234069609538U) + aOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = (aWandererA + RotL64(aScatter, 6U)) + 13419487997946496825U;
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 27U)) + RotL64(aCarry, 23U)) + 5478309847615220345U;
            aOrbiterF = (aWandererB + RotL64(aIngress, 23U)) + 3635184969215610049U;
            aOrbiterA = (aWandererJ + RotL64(aCross, 13U)) + 12527903812035294828U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 1684685110885338814U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 12860354576326835090U;
            aOrbiterC = RotL64((aOrbiterC * 12743745087733307255U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 9081823570147481835U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 14369321778210049109U;
            aOrbiterB = RotL64((aOrbiterB * 17865953349448767035U), 57U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterK) + 11518132079084873250U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1]) + RotL64(aNonceWordB, 4U);
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 11893535026126957389U) ^ aOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15751374986135615095U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 7084079180579206226U) + RotL64(aNonceWordH, 11U);
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 2999676609847603277U;
            aOrbiterI = RotL64((aOrbiterI * 14602698397511266403U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 17683445810614029153U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 11576460512964896969U;
            aOrbiterH = RotL64((aOrbiterH * 5243651036457051155U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 13429800604736567949U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 14661785761747367546U;
            aOrbiterG = RotL64((aOrbiterG * 4765843989277333421U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 12837164345582888950U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 6222666313184669392U;
            aOrbiterA = RotL64((aOrbiterA * 17402483466567712319U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 5358647039491079457U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 12459911673401497180U;
            aOrbiterJ = RotL64((aOrbiterJ * 13605465035256188065U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 3333017644772803587U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 15501587702102554928U;
            aOrbiterD = RotL64((aOrbiterD * 4921693371641768339U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 8492287653837766613U) + aOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 3432736785678875404U;
            aOrbiterK = RotL64((aOrbiterK * 7326419883291516513U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 2841486107704281869U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 13915875634607599122U;
            aOrbiterF = RotL64((aOrbiterF * 707861617246345083U), 23U);
            //
            aIngress = RotL64(aOrbiterI, 41U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 43U));
            aIngress = aIngress + (RotL64(aOrbiterH, 34U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterJ, 29U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + RotL64(aOrbiterK, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aScatter, 43U) + aOrbiterC) + RotL64(aOrbiterF, 39U)) + RotL64(aNonceWordD, 55U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 11U)) + aOrbiterD);
            aWandererH = aWandererH + (((RotL64(aIngress, 54U) + RotL64(aOrbiterE, 20U)) + aOrbiterH) + RotL64(aCarry, 19U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 41U) + aOrbiterF) + RotL64(aOrbiterG, 27U));
            aWandererK = aWandererK + (((RotL64(aScatter, 51U) + aOrbiterI) + RotL64(aOrbiterB, 13U)) + aWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterF, 51U)) + aOrbiterI) + RotL64(aNonceWordF, 35U));
            aWandererG = aWandererG + ((RotL64(aCross, 23U) + aOrbiterG) + RotL64(aOrbiterA, 43U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 5U) + aOrbiterB) + RotL64(aOrbiterC, 3U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 35U) + aOrbiterK) + RotL64(aOrbiterJ, 24U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 29U) + aOrbiterE) + RotL64(aOrbiterD, 35U));
            aWandererB = aWandererB + ((((RotL64(aCross, 58U) + aOrbiterC) + RotL64(aOrbiterK, 29U)) + RotL64(aCarry, 11U)) + aWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 42U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererI);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 37U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererC, 47U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_a loop 2
        // read from: mSource, mSnow, aWorkLaneA
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 30U) ^ RotL64(aNonceWordB, 43U)) ^ RotL64(aNonceWordA, 51U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 7245U)) & S_BLOCK1], 19U) ^ RotL64(mSnow[((aIndex + 10796U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 5U) ^ RotL64(aNonceWordD, 37U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 9028U)) & S_BLOCK1], 13U) ^ RotL64(mSource[((aIndex + 7056U)) & S_BLOCK1], 28U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aIngress, 57U)) ^ (RotL64(aPrevious, 21U) ^ RotL64(aCross, 34U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererK + RotL64(aScatter, 60U)) + RotL64(aCarry, 3U)) + 6243113109470883144U;
            aOrbiterG = ((aWandererG + RotL64(aPrevious, 39U)) + 3891552123999605832U) + RotL64(aNonceWordF, 47U);
            aOrbiterE = (aWandererJ + RotL64(aCross, 51U)) + 8758797898587019128U;
            aOrbiterC = ((aWandererC + RotL64(aIngress, 53U)) + 1005891374086408851U) + RotL64(aNonceWordE, 57U);
            aOrbiterH = (aWandererF + RotL64(aCross, 5U)) + 3713426782180050764U;
            aOrbiterA = (aWandererA + RotL64(aScatter, 23U)) + 18358143862391573534U;
            aOrbiterF = (((aWandererH + RotL64(aIngress, 11U)) + RotL64(aCarry, 39U)) + 17504394029693712404U) + aOrbiterAssignSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 57U)) + RotL64(aCarry, 19U)) + 5312729289027417014U;
            aOrbiterB = (aWandererE + RotL64(aIngress, 35U)) + 2560873623431186029U;
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 14U)) + 16309322822806704211U) + aOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = (aWandererI + RotL64(aCross, 19U)) + 10195513918020652600U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 2552116263258744287U) + RotL64(aNonceWordG, 28U);
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 7732784879810980089U;
            aOrbiterE = RotL64((aOrbiterE * 15041929399477790999U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 16499127570665381507U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 10890036715535519036U) ^ aOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9065115450010475187U), 19U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterF) + 16288944603478791554U) + aOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1]) + RotL64(aNonceWordA, 55U);
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 14542766121469312846U;
            aOrbiterH = RotL64((aOrbiterH * 8435383464425875209U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 5973595239494084696U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 1820492719977197097U;
            aOrbiterF = RotL64((aOrbiterF * 16164917159141304405U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 10489529555776381736U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 6392552206958240484U;
            aOrbiterB = RotL64((aOrbiterB * 11761477994533503307U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 10163241948999404556U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 16054678853554707148U;
            aOrbiterK = RotL64((aOrbiterK * 10570418210789350091U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 3606021702108590330U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 16920568417324295852U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5222656554577625385U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 13889995689147406315U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 7908387312354285092U;
            aOrbiterA = RotL64((aOrbiterA * 7995682580514280949U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 14161911472715334589U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 12386100977925313406U;
            aOrbiterJ = RotL64((aOrbiterJ * 17136336570895231639U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 14408470657696841139U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 7466281699619513012U;
            aOrbiterD = RotL64((aOrbiterD * 2706710684289882025U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 11125044052260579351U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 6243113109470883144U;
            aOrbiterI = RotL64((aOrbiterI * 17390954549755941181U), 37U);
            //
            aIngress = RotL64(aOrbiterK, 27U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterJ, 48U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterC, 23U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 53U));
            aIngress = aIngress + RotL64(aOrbiterA, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 52U) + aOrbiterD) + RotL64(aOrbiterK, 53U));
            aWandererH = aWandererH + ((((RotL64(aPrevious, 47U) + aOrbiterK) + RotL64(aOrbiterG, 21U)) + RotL64(aCarry, 53U)) + aWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterA, 37U)) + aOrbiterI);
            aWandererC = aWandererC + ((RotL64(aCross, 11U) + aOrbiterG) + RotL64(aOrbiterD, 48U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 23U) + aOrbiterE) + RotL64(aOrbiterG, 43U)) + aWandererUpdateSaltC[((aIndex + 20U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterH, 27U)) + aOrbiterD);
            aWandererF = aWandererF ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterI, 51U)) + aOrbiterF);
            aWandererK = aWandererK + ((RotL64(aScatter, 58U) + RotL64(aOrbiterK, 35U)) + aOrbiterI);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 39U) + aOrbiterF) + RotL64(aOrbiterC, 30U)) + RotL64(aNonceWordC, 3U));
            aWandererD = aWandererD + ((((RotL64(aCross, 41U) + RotL64(aOrbiterJ, 13U)) + aOrbiterC) + RotL64(aCarry, 27U)) + RotL64(aNonceWordH, 29U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterK, 23U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + (RotL64(aWandererE, 50U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererB, 29U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + RotL64(aWandererJ, 6U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_a loop 3
        // read from: mSource, mSnow, aWorkLaneA, aWorkLaneB
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceWordG, 41U) ^ RotL64(aNonceWordA, 21U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 13428U)) & S_BLOCK1], 13U) ^ RotL64(mSnow[((aIndex + 12656U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 43U) ^ RotL64(aNonceWordD, 24U)) ^ RotL64(aNonceWordH, 3U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13773U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((aIndex + 11460U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 29U) ^ RotL64(aPrevious, 13U)) + (RotL64(aIngress, 60U) ^ RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererG + RotL64(aIngress, 11U)) + 1708250618750199233U;
            aOrbiterD = ((aWandererA + RotL64(aScatter, 43U)) + 12009147777553691142U) + RotL64(aNonceWordF, 37U);
            aOrbiterJ = (aWandererB + RotL64(aCross, 14U)) + 8393982703399156592U;
            aOrbiterC = (aWandererC + RotL64(aPrevious, 19U)) + 3247327098356831221U;
            aOrbiterA = (aWandererF + RotL64(aIngress, 47U)) + 3403590155376353737U;
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 41U)) + RotL64(aCarry, 5U)) + 18197244558104735044U;
            aOrbiterK = (aWandererJ + RotL64(aScatter, 37U)) + 3096253642040701606U;
            aOrbiterB = (aWandererH + RotL64(aCross, 60U)) + 8012692688785412179U;
            aOrbiterI = ((((aWandererD + RotL64(aScatter, 5U)) + RotL64(aCarry, 47U)) + 17531946907545680745U) + aOrbiterAssignSaltB[(((31U - aIndex) + 12U)) & S_SALT1]) + RotL64(aNonceWordE, 31U);
            aOrbiterG = (((aWandererK + RotL64(aIngress, 51U)) + RotL64(aCarry, 39U)) + 17687695944270225817U) + aOrbiterAssignSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterF = (aWandererE + RotL64(aCross, 21U)) + 16147773866007628769U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 18244641303026196497U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 8839160526348897457U;
            aOrbiterJ = RotL64((aOrbiterJ * 14268021129087663397U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 10599266240854068246U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 2056723540756216155U) ^ aOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13311591601230386375U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 4629354220460621284U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 9505955649473204942U) ^ RotL64(aNonceWordB, 47U);
            aOrbiterD = RotL64((aOrbiterD * 17775391885312236187U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 17078153810088721310U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 9470436761716263000U;
            aOrbiterA = RotL64((aOrbiterA * 5431855497250357229U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 3305863413630104742U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 14377172434239576161U;
            aOrbiterB = RotL64((aOrbiterB * 6880176890091033423U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 415687827894226513U) + aOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 16975319836893760993U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6597144958013976445U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 12707054129431596074U) + aOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 8974182792497231239U;
            aOrbiterE = RotL64((aOrbiterE * 7874658957269462717U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 10826131924322955095U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 4168545139712703154U;
            aOrbiterC = RotL64((aOrbiterC * 10305904857550051705U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 4539070253658625193U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 3737870219498561326U;
            aOrbiterK = RotL64((aOrbiterK * 13130847633918921393U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 11563084648810555040U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 7410695535361901473U) ^ RotL64(aNonceWordC, 19U);
            aOrbiterI = RotL64((aOrbiterI * 7540855656023807389U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 6687453696858775037U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 1708250618750199233U;
            aOrbiterF = RotL64((aOrbiterF * 13104250803527718135U), 3U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterH, 27U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 53U));
            aIngress = aIngress + (RotL64(aOrbiterF, 42U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterG, 19U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterK, 39U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterB, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aScatter, 22U) + aOrbiterG) + RotL64(aOrbiterJ, 29U)) + RotL64(aNonceWordA, 14U)) + aWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 51U) + aOrbiterA) + RotL64(aOrbiterE, 27U)) + RotL64(aNonceWordH, 53U));
            aWandererC = aWandererC + ((RotL64(aIngress, 43U) + aOrbiterH) + RotL64(aOrbiterB, 22U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 3U) + aOrbiterD) + RotL64(aOrbiterC, 53U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 27U) + aOrbiterC) + RotL64(aOrbiterK, 35U)) + RotL64(aCarry, 5U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterI, 11U)) + aOrbiterF);
            aWandererG = aWandererG + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterE, 3U)) + aOrbiterH);
            aWandererB = aWandererB ^ ((RotL64(aCross, 18U) + RotL64(aOrbiterF, 57U)) + aOrbiterG);
            aWandererE = aWandererE + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterA, 13U)) + aOrbiterK) + RotL64(aCarry, 51U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 13U) + aOrbiterB) + RotL64(aOrbiterI, 43U)) + aWandererUpdateSaltE[((aIndex + 14U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aScatter, 29U) + RotL64(aOrbiterB, 50U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 18U) ^ aWandererK);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 43U));
            aCarry = aCarry + RotL64(aWandererC, 58U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_a loop 4
        // read from: mSnow, aWorkLaneA, aWorkLaneB, aExpandLaneA
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceWordD, 5U) ^ RotL64(aNonceWordE, 57U));
            aIngress = aIngress ^ (RotL64(mSnow[((aIndex + 18823U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18678U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 13U) ^ RotL64(aNonceWordH, 52U)) ^ RotL64(aNonceWordG, 21U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17282U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneA[((aIndex + 21634U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 41U) ^ RotL64(aIngress, 5U)) + (RotL64(aCross, 54U) ^ RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (aWandererI + RotL64(aScatter, 21U)) + 1888427424966603593U;
            aOrbiterB = (aWandererA + RotL64(aCross, 3U)) + 5436761445660415091U;
            aOrbiterK = (aWandererJ + RotL64(aIngress, 37U)) + 17322876217962143270U;
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 23U)) + RotL64(aCarry, 11U)) + 9728299982740564979U;
            aOrbiterD = ((aWandererC + RotL64(aScatter, 44U)) + 301720335271716921U) + aOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = (aWandererB + RotL64(aIngress, 19U)) + 8069685428854814396U;
            aOrbiterG = (aWandererD + RotL64(aCross, 51U)) + 1973715500949100991U;
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 47U)) + 87666408799854155U) + RotL64(aNonceWordD, 35U);
            aOrbiterA = (aWandererE + RotL64(aCross, 13U)) + 12195436904339035245U;
            aOrbiterI = (((aWandererK + RotL64(aScatter, 11U)) + RotL64(aCarry, 19U)) + 4578742069143400295U) + aOrbiterAssignSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterH = (((aWandererF + RotL64(aIngress, 28U)) + RotL64(aCarry, 43U)) + 7828776048774876484U) + RotL64(aNonceWordC, 9U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 17203146364542781833U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 16913369550858890466U;
            aOrbiterK = RotL64((aOrbiterK * 13534417587921978507U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 9632761514552265402U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 9106637671877341286U;
            aOrbiterD = RotL64((aOrbiterD * 9073709119482640391U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 15423680889126750876U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 6087310684583331882U;
            aOrbiterE = RotL64((aOrbiterE * 8964465129744898619U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 5420955876411796789U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 14166807419730848032U;
            aOrbiterG = RotL64((aOrbiterG * 442659738632823751U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 8118312450347026824U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 4253043584558403086U;
            aOrbiterJ = RotL64((aOrbiterJ * 5651748455190536467U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 8810774678371762700U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 12218479555589447835U;
            aOrbiterA = RotL64((aOrbiterA * 11026364205248516355U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 11389930523582876358U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 16334420553471379915U) ^ aOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13830132212033904777U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 18201289372553710279U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 7196540389657785361U;
            aOrbiterH = RotL64((aOrbiterH * 13058135202554889791U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 2601046573550065116U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 2243003381737071984U) ^ RotL64(aNonceWordF, 59U);
            aOrbiterF = RotL64((aOrbiterF * 10518763530499878945U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 6058992247656841580U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 10083863011670540073U;
            aOrbiterB = RotL64((aOrbiterB * 17908394295613117155U), 43U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterF) + 8505005026063156940U) + aOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1]) + RotL64(aNonceWordB, 55U);
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 1888427424966603593U;
            aOrbiterC = RotL64((aOrbiterC * 18298382581929885653U), 27U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterD, 21U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 36U));
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 43U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 53U));
            aIngress = aIngress + RotL64(aOrbiterG, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aScatter, 41U) + aOrbiterA) + RotL64(aOrbiterI, 24U)) + RotL64(aNonceWordE, 31U));
            aWandererB = aWandererB + ((RotL64(aCross, 26U) + aOrbiterK) + RotL64(aOrbiterH, 43U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 51U) + aOrbiterC) + RotL64(aOrbiterJ, 29U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 47U) + aOrbiterG) + RotL64(aOrbiterF, 39U)) + RotL64(aNonceWordG, 14U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 11U) + aOrbiterF) + RotL64(aOrbiterA, 19U));
            aWandererD = aWandererD + (((RotL64(aScatter, 39U) + RotL64(aOrbiterE, 47U)) + aOrbiterB) + RotL64(aCarry, 53U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterH, 21U)) + aOrbiterE) + aWandererUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 57U) + aOrbiterB) + RotL64(aOrbiterI, 35U)) + RotL64(aCarry, 3U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 5U) + aOrbiterC) + RotL64(aOrbiterK, 54U));
            aWandererG = aWandererG + (((RotL64(aScatter, 35U) + RotL64(aOrbiterD, 11U)) + aOrbiterK) + aWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 18U) + aOrbiterJ) + RotL64(aOrbiterG, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererB, 44U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererK);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + RotL64(aWandererC, 23U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_a loop 5
        // read from: aWorkLaneA, aWorkLaneB, aExpandLaneA, aExpandLaneB
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceWordA, 46U) ^ RotL64(aNonceWordH, 19U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 25979U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 23047U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 13U) ^ RotL64(aNonceWordC, 54U)) ^ RotL64(aNonceWordE, 3U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27010U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26734U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 35U) + RotL64(aPrevious, 47U)) ^ (RotL64(aCross, 23U) ^ RotL64(aIngress, 4U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((aWandererE + RotL64(aScatter, 6U)) + 3448371607470865612U) + RotL64(aNonceWordD, 3U);
            aOrbiterB = ((aWandererG + RotL64(aCross, 57U)) + 3743742913651580573U) + RotL64(aNonceWordB, 34U);
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 53U)) + RotL64(aCarry, 53U)) + 13069491287948807280U;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 11U)) + 16872779275586545632U) + aOrbiterAssignSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 41U)) + 17945792656755062795U;
            aOrbiterI = (aWandererA + RotL64(aCross, 48U)) + 18199747196793731853U;
            aOrbiterF = (((aWandererB + RotL64(aScatter, 3U)) + RotL64(aCarry, 27U)) + 15953311878379809513U) + aOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 21U)) + RotL64(aCarry, 19U)) + 941268763494588338U;
            aOrbiterC = (aWandererD + RotL64(aScatter, 27U)) + 10090221530365796809U;
            aOrbiterA = (aWandererH + RotL64(aIngress, 23U)) + 8335698093307607001U;
            aOrbiterE = (aWandererI + RotL64(aCross, 51U)) + 6147498804734306100U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 5980246079567570090U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 4152167624425912978U;
            aOrbiterG = RotL64((aOrbiterG * 10019421651535123573U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 14990418790239735916U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 3418668387496597219U) ^ aOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12814077238529863119U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 4206650904177199425U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 3905470780938996069U;
            aOrbiterH = RotL64((aOrbiterH * 16030122739273137005U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 9968672788233080924U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 602258075661864866U;
            aOrbiterA = RotL64((aOrbiterA * 2615726693066300065U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 17751667243048041383U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 2414054413585296027U;
            aOrbiterD = RotL64((aOrbiterD * 1049512574773201893U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 6523322402744047752U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 6729901917767398779U;
            aOrbiterK = RotL64((aOrbiterK * 8039939871405367139U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 11460169185076814539U) + RotL64(aNonceWordE, 19U);
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 7559640379553110573U) ^ aOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9864654321914036135U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 17271150091827475028U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 3541809324556914646U;
            aOrbiterC = RotL64((aOrbiterC * 12655168871428868639U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 10332471447306597185U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 12580133010006951091U) ^ RotL64(aNonceWordF, 49U);
            aOrbiterE = RotL64((aOrbiterE * 1159183486084705865U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 17333553613777910945U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 14179392055698682109U;
            aOrbiterB = RotL64((aOrbiterB * 17675559451285279251U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 3996830751779338356U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 3448371607470865612U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5375529914102609947U), 35U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterG, 5U);
            aIngress = aIngress + (RotL64(aOrbiterF, 26U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterK, 19U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterA, 43U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + RotL64(aOrbiterH, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aIngress, 57U) + aOrbiterF) + RotL64(aOrbiterJ, 37U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterK, 35U)) + aOrbiterH) + RotL64(aNonceWordC, 29U));
            aWandererH = aWandererH + ((RotL64(aCross, 39U) + aOrbiterJ) + RotL64(aOrbiterA, 13U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 54U) + RotL64(aOrbiterB, 57U)) + aOrbiterC);
            aWandererC = aWandererC + ((((RotL64(aCross, 3U) + aOrbiterC) + RotL64(aOrbiterE, 60U)) + RotL64(aCarry, 43U)) + aWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 41U) + aOrbiterE) + RotL64(aOrbiterB, 43U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 51U) + aOrbiterI) + RotL64(aOrbiterD, 47U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 19U) + aOrbiterF) + RotL64(aOrbiterG, 21U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 11U) + aOrbiterE) + RotL64(aOrbiterG, 29U)) + RotL64(aCarry, 19U)) + aWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 13U) + aOrbiterK) + RotL64(aOrbiterE, 26U)) + RotL64(aNonceWordG, 61U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 6U) + RotL64(aOrbiterD, 23U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 58U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererJ);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 41U));
            aCarry = aCarry + RotL64(aWandererC, 28U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_a loop 6
        // read from: aWorkLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 3U) ^ RotL64(aNonceWordA, 37U)) ^ RotL64(aNonceWordG, 20U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 30477U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneA[((aIndex + 28947U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 27U) ^ RotL64(aNonceWordE, 39U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32308U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneC[((aIndex + 31469U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 43U) ^ RotL64(aCarry, 57U)) ^ (RotL64(aCross, 5U) + RotL64(aIngress, 18U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (aWandererH + RotL64(aCross, 22U)) + 8020711767807230555U;
            aOrbiterI = (aWandererI + RotL64(aScatter, 51U)) + 15368693777246341570U;
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 5U)) + RotL64(aCarry, 5U)) + 5117523734225562401U;
            aOrbiterE = (aWandererA + RotL64(aPrevious, 13U)) + 13155269151097507808U;
            aOrbiterC = (((aWandererC + RotL64(aCross, 38U)) + RotL64(aCarry, 41U)) + 9879303753623578272U) + aOrbiterAssignSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 47U)) + RotL64(aCarry, 23U)) + 1165799257173794826U;
            aOrbiterG = ((aWandererB + RotL64(aScatter, 57U)) + 930641942062732091U) + RotL64(aNonceWordE, 29U);
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 29U)) + 11330571332221123153U) + RotL64(aNonceWordB, 4U);
            aOrbiterH = (aWandererF + RotL64(aPrevious, 53U)) + 2862963158282518899U;
            aOrbiterD = ((aWandererK + RotL64(aIngress, 41U)) + 6019186399361476659U) + aOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = (aWandererG + RotL64(aScatter, 27U)) + 1924419843785161958U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 12618629043591380461U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 9334176504266512405U) ^ RotL64(aNonceWordA, 15U);
            aOrbiterK = RotL64((aOrbiterK * 18239109235362925739U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 16829692481030013551U) + aOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 5604784396927022709U;
            aOrbiterC = RotL64((aOrbiterC * 2833893610883508353U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 16124030106598549644U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 16571659812830230677U;
            aOrbiterF = RotL64((aOrbiterF * 4668250364992383549U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 15171089673591843703U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 2826755560293849328U;
            aOrbiterG = RotL64((aOrbiterG * 9397017963457655287U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 9976785768283589291U) + RotL64(aNonceWordF, 5U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 11845100564714691809U;
            aOrbiterJ = RotL64((aOrbiterJ * 4935139932585319251U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 7318560453127859950U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 3039196878830506712U;
            aOrbiterH = RotL64((aOrbiterH * 3140508261330698717U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 8850992055588337843U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 4219373528176869146U;
            aOrbiterD = RotL64((aOrbiterD * 1310964742529956743U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 1341474458715938799U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 15937557372891732898U;
            aOrbiterA = RotL64((aOrbiterA * 11437307017920192915U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 7512741986101399499U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 4304636545688233645U) ^ aOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1948671766238131953U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 11460886069492094055U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 2019818350627642126U;
            aOrbiterI = RotL64((aOrbiterI * 9802784763505584769U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 3190374588085859096U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 8020711767807230555U;
            aOrbiterE = RotL64((aOrbiterE * 12055760672321414929U), 41U);
            //
            aIngress = RotL64(aOrbiterC, 43U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 53U));
            aIngress = aIngress + (RotL64(aOrbiterG, 22U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterJ, 39U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterF, 29U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterD, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterK, 13U)) + aOrbiterE) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterA, 21U)) + aOrbiterD);
            aWandererG = aWandererG + ((RotL64(aIngress, 5U) + aOrbiterE) + RotL64(aOrbiterF, 5U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterE, 27U)) + aOrbiterJ);
            aWandererD = aWandererD + ((((RotL64(aIngress, 26U) + RotL64(aOrbiterF, 39U)) + aOrbiterH) + RotL64(aNonceWordH, 25U)) + aWandererUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 43U) + aOrbiterH) + RotL64(aOrbiterG, 52U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 51U) + aOrbiterI) + RotL64(aOrbiterJ, 3U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterF, 29U)) + aOrbiterC) + aWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aIngress, 46U) + aOrbiterC) + RotL64(aOrbiterA, 11U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 13U) + aOrbiterF) + RotL64(aOrbiterB, 50U));
            aWandererE = aWandererE + ((((RotL64(aCross, 53U) + RotL64(aOrbiterA, 35U)) + aOrbiterB) + RotL64(aCarry, 3U)) + RotL64(aNonceWordD, 43U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + (RotL64(aWandererI, 39U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 58U) ^ aWandererH);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 37U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + RotL64(aWandererA, 53U);
            aCarry = aCarry + RotL64(aIngress, 24U);
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

void TwistExpander_Bowling_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xD93BAC8DD52E5873ULL + 0xBAC31EB91A0DD19DULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xE6CD961351CEF6B5ULL + 0x8EE4A80B17323E18ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x90D9AB3B1145FD87ULL + 0xEF285C77B324AFF5ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xDEC76324C065F6BBULL + 0xFFE38AE333282598ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x82C4760298FA425BULL + 0xB58EE7FC1F03F659ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xD98DFE33FCCF6FBBULL + 0xB4722A843CBF7B7DULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x82E9D6007C192457ULL + 0xB2054430B1A26B79ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xD3B7E1EBED9D68FBULL + 0xF9CE293D7178991BULL);
    std::uint64_t aDomainWordIngress = pConstants->mIngress;
    std::uint64_t aDomainWordScatter = pConstants->mScatter;
    std::uint64_t aDomainWordCross = pConstants->mCross;
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 27U) ^ RotL64(aNonceWordG, 53U)) ^ RotL64(aNonceWordF, 44U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 4218U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneC[((aIndex + 1347U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 48U) ^ RotL64(aNonceWordA, 3U)) ^ RotL64(aNonceWordH, 27U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 3479U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((aIndex + 1827U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 24U) + RotL64(aPrevious, 39U)) ^ (RotL64(aCarry, 5U) + RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((aWandererC + RotL64(aIngress, 39U)) + RotL64(aCarry, 27U)) + 16016931609704150191U;
            aOrbiterE = ((aWandererI + RotL64(aScatter, 3U)) + RotL64(aCarry, 5U)) + 14511433515861302636U;
            aOrbiterF = (aWandererB + RotL64(aPrevious, 47U)) + 11691237442613269593U;
            aOrbiterB = (aWandererJ + RotL64(aCross, 14U)) + 16383220587320484649U;
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 29U)) + 14293015313458219868U) + aOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = (((aWandererA + RotL64(aCross, 51U)) + RotL64(aCarry, 57U)) + 4407695248205526670U) + aOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = ((aWandererK + RotL64(aScatter, 35U)) + 1158323195324398372U) + RotL64(aNonceWordF, 39U);
            aOrbiterD = (aWandererE + RotL64(aPrevious, 43U)) + 6577683409653864555U;
            aOrbiterK = ((aWandererF + RotL64(aIngress, 22U)) + 171080079472863843U) + RotL64(aNonceWordG, 45U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 5766333425872228205U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 16173508656917582960U) ^ RotL64(aNonceWordC, 41U);
            aOrbiterF = RotL64((aOrbiterF * 12187968015372936695U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 11781450063402219202U) + aOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 13033139686637576694U;
            aOrbiterG = RotL64((aOrbiterG * 4331137994135472025U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 4006310759400926020U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 13156817947481574467U;
            aOrbiterD = RotL64((aOrbiterD * 563189239835001483U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 12791290558893516411U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterE) ^ 989729955679243234U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]) ^ RotL64(aNonceWordB, 34U);
            aOrbiterK = RotL64((aOrbiterK * 8757228712495095017U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 838379839663022790U) + aOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 2830743864262313606U;
            aOrbiterH = RotL64((aOrbiterH * 10173947177104802797U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 2146646527331684652U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 4629168181742174906U;
            aOrbiterB = RotL64((aOrbiterB * 9046124907945045131U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 1150129989168501777U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 619659995945229440U;
            aOrbiterC = RotL64((aOrbiterC * 13734821008174603409U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 8120315647582116952U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 13754584116324996165U;
            aOrbiterE = RotL64((aOrbiterE * 12295486140772079747U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 6084566798869999580U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 5731665119233722504U;
            aOrbiterJ = RotL64((aOrbiterJ * 5921510209025133639U), 21U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterD, 41U);
            aIngress = aIngress + (RotL64(aOrbiterE, 58U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterB, 5U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterC, 47U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterJ, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aIngress, 12U) + aOrbiterE) + RotL64(aOrbiterH, 39U)) + aWandererUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterG, 5U)) + aOrbiterD);
            aWandererJ = aWandererJ + (((RotL64(aCross, 47U) + RotL64(aOrbiterC, 57U)) + aOrbiterE) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterB, 48U)) + aOrbiterG) + RotL64(aNonceWordA, 61U));
            aWandererD = aWandererD + (((RotL64(aCross, 51U) + aOrbiterJ) + RotL64(aOrbiterK, 21U)) + aWandererUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 34U) + RotL64(aOrbiterJ, 43U)) + aOrbiterF);
            aWandererA = aWandererA + (((RotL64(aIngress, 41U) + aOrbiterH) + RotL64(aOrbiterF, 53U)) + RotL64(aCarry, 29U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 27U) + aOrbiterF) + RotL64(aOrbiterB, 27U)) + RotL64(aNonceWordD, 27U));
            aWandererK = aWandererK + ((RotL64(aIngress, 23U) + aOrbiterF) + RotL64(aOrbiterC, 34U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 30U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 21U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererK, 5U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 5U) ^ RotL64(aNonceWordC, 19U)) ^ RotL64(aNonceWordH, 47U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 10472U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneD[((aIndex + 11657U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 57U) ^ RotL64(aNonceWordF, 19U)) ^ RotL64(aNonceWordD, 3U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 16068U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneB[((aIndex + 14140U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 3U) + RotL64(aCarry, 23U)) + (RotL64(aCross, 50U) ^ RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = ((aWandererD + RotL64(aCross, 44U)) + RotL64(aCarry, 11U)) + 13442819395490639310U;
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 27U)) + RotL64(aCarry, 27U)) + 8187292523194120936U;
            aOrbiterH = (((aWandererC + RotL64(aScatter, 39U)) + RotL64(aCarry, 35U)) + 11469697159823131388U) + RotL64(aNonceWordH, 9U);
            aOrbiterD = (aWandererJ + RotL64(aIngress, 11U)) + 13414083692375929653U;
            aOrbiterI = (aWandererF + RotL64(aScatter, 35U)) + 11404010733687907517U;
            aOrbiterC = ((aWandererG + RotL64(aCross, 19U)) + 6783212827186218247U) + aOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = (aWandererB + RotL64(aIngress, 53U)) + 8561131439340372614U;
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 3U)) + 6252609642004429113U) + aOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = ((aWandererA + RotL64(aScatter, 58U)) + 12804867444200448952U) + RotL64(aNonceWordD, 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 2739648749603690781U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 14808861217017399752U;
            aOrbiterH = RotL64((aOrbiterH * 373911885694012101U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 17588866502571268888U) + aOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = (((aOrbiterI ^ aOrbiterD) ^ 5882260142735642980U) ^ aOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1]) ^ RotL64(aNonceWordF, 54U);
            aOrbiterI = RotL64((aOrbiterI * 7688252946143263869U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 15493099088132862949U) + aOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 5175647411532429582U) ^ aOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15226544495598541883U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 14279707376173642767U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 6826363572161275158U;
            aOrbiterK = RotL64((aOrbiterK * 5263708315440161809U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 13267185753040999992U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 9980987858092888720U;
            aOrbiterF = RotL64((aOrbiterF * 13210290848800728635U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 3582972937645514549U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 10140409019562890804U) ^ RotL64(aNonceWordG, 31U);
            aOrbiterG = RotL64((aOrbiterG * 6944490201647678479U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 6160444117287330557U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 16344602960561293113U;
            aOrbiterD = RotL64((aOrbiterD * 2319964919335633293U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 3497141036108337171U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 91269118352540308U;
            aOrbiterC = RotL64((aOrbiterC * 5160060720189045505U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 12739932748793144857U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 12820180915064791197U;
            aOrbiterA = RotL64((aOrbiterA * 5843849637411948699U), 13U);
            //
            aIngress = RotL64(aOrbiterK, 13U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 51U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 60U));
            aIngress = aIngress + (RotL64(aOrbiterC, 19U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterD, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterI, 5U)) + aOrbiterA);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 30U) + RotL64(aOrbiterK, 14U)) + aOrbiterB) + RotL64(aCarry, 51U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterD, 57U)) + aOrbiterI) + RotL64(aNonceWordA, 39U));
            aWandererD = aWandererD + ((RotL64(aCross, 47U) + aOrbiterA) + RotL64(aOrbiterG, 19U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterF, 41U)) + aOrbiterB) + aWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 51U) + aOrbiterC) + RotL64(aOrbiterG, 35U)) + RotL64(aCarry, 27U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 19U) + aOrbiterF) + RotL64(aOrbiterH, 53U)) + RotL64(aNonceWordC, 17U));
            aWandererC = aWandererC + (((RotL64(aIngress, 3U) + RotL64(aOrbiterH, 48U)) + aOrbiterB) + aWandererUpdateSaltA[((aIndex + 20U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 12U) + RotL64(aOrbiterI, 23U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 54U));
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererB, 47U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 21U) ^ RotL64(aNonceWordE, 57U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 16826U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 21845U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 13U) ^ RotL64(aNonceWordH, 41U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19356U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 22515U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 13U) + RotL64(aCross, 43U)) ^ (RotL64(aPrevious, 28U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (aWandererC + RotL64(aCross, 3U)) + 439898681482066326U;
            aOrbiterH = (((aWandererG + RotL64(aIngress, 28U)) + RotL64(aCarry, 13U)) + 17362083676671776094U) + aOrbiterAssignSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterG = ((aWandererF + RotL64(aScatter, 53U)) + 6418499837265155024U) + RotL64(aNonceWordG, 40U);
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 47U)) + 17262244253027454972U) + aOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = ((aWandererA + RotL64(aCross, 23U)) + RotL64(aCarry, 51U)) + 2382066162993139503U;
            aOrbiterD = (aWandererH + RotL64(aIngress, 57U)) + 14345808395587174135U;
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 14U)) + RotL64(aCarry, 39U)) + 7534743166385552851U;
            aOrbiterK = (aWandererK + RotL64(aScatter, 37U)) + 16994453324688523966U;
            aOrbiterI = ((aWandererJ + RotL64(aCross, 43U)) + 7079553728544045092U) + RotL64(aNonceWordB, 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 3562822704508440641U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 13990892681975857821U) ^ RotL64(aNonceWordD, 17U);
            aOrbiterG = RotL64((aOrbiterG * 8352929306654078795U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 1796728922368577238U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 6605161260520067178U;
            aOrbiterF = RotL64((aOrbiterF * 8147537646591674091U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 13994083795942328918U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 6144523182899107711U;
            aOrbiterC = RotL64((aOrbiterC * 4153879991344611283U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 12247462325297436642U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 1065809332002012789U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5496601177032953251U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 10147919864511540753U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 17138553441127273354U) ^ aOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5773875596275267871U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 2653924016109573974U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 6254416952351699582U) ^ RotL64(aNonceWordC, 51U);
            aOrbiterD = RotL64((aOrbiterD * 12756861659704947257U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 813046408080197079U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 9624466135414123483U;
            aOrbiterJ = RotL64((aOrbiterJ * 6960320253124395015U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 972586705850825744U) + aOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 155283774901960223U;
            aOrbiterK = RotL64((aOrbiterK * 9928051687724257041U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 18200100644751360406U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 1168426822045686004U;
            aOrbiterI = RotL64((aOrbiterI * 5867027156069481313U), 13U);
            //
            aIngress = RotL64(aOrbiterD, 23U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 47U));
            aIngress = aIngress + (RotL64(aOrbiterG, 53U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 20U));
            aIngress = aIngress + RotL64(aOrbiterF, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterH, 18U)) + aOrbiterG) + RotL64(aNonceWordF, 61U)) + aWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 36U) + aOrbiterI) + RotL64(aOrbiterJ, 47U)) + RotL64(aCarry, 13U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 43U) + aOrbiterB) + RotL64(aOrbiterC, 13U));
            aWandererB = aWandererB + ((RotL64(aCross, 13U) + aOrbiterD) + RotL64(aOrbiterJ, 23U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 51U) + aOrbiterC) + RotL64(aOrbiterG, 43U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 47U) + aOrbiterB) + RotL64(aOrbiterK, 4U)) + RotL64(aCarry, 27U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 23U) + aOrbiterG) + RotL64(aOrbiterF, 35U));
            aWandererA = aWandererA + (((RotL64(aIngress, 56U) + RotL64(aOrbiterK, 53U)) + aOrbiterC) + aWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterJ, 57U)) + aOrbiterG) + RotL64(aNonceWordA, 25U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + (RotL64(aWandererG, 53U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + RotL64(aWandererE, 6U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 29U) ^ RotL64(aNonceWordA, 48U)) ^ RotL64(aNonceWordD, 57U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 25936U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneB[((aIndex + 27865U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 13U) ^ RotL64(aNonceWordF, 58U)) ^ RotL64(aNonceWordG, 35U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 28280U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneD[((aIndex + 31550U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aIngress, 23U)) ^ (RotL64(aPrevious, 53U) ^ RotL64(aCross, 10U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (((aWandererJ + RotL64(aPrevious, 47U)) + RotL64(aCarry, 51U)) + 11450949896247900941U) + RotL64(aNonceWordD, 39U);
            aOrbiterK = (aWandererF + RotL64(aCross, 18U)) + 3905542253538116335U;
            aOrbiterG = (aWandererB + RotL64(aScatter, 53U)) + 9529740545977785305U;
            aOrbiterC = ((aWandererE + RotL64(aIngress, 5U)) + 1856876631533143492U) + aOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = ((aWandererK + RotL64(aCross, 13U)) + 84253466320181686U) + aOrbiterAssignSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = ((aWandererA + RotL64(aIngress, 23U)) + RotL64(aCarry, 23U)) + 12577480918745432444U;
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 57U)) + 5625703170397704029U) + RotL64(aNonceWordC, 21U);
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 41U)) + RotL64(aCarry, 3U)) + 694608607323629282U;
            aOrbiterF = (aWandererH + RotL64(aIngress, 34U)) + 3993981243536262204U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 4119215953484892051U) + aOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 8785040118556157146U;
            aOrbiterG = RotL64((aOrbiterG * 17113521266125471625U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 16234403619456882890U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 10398727475672860610U;
            aOrbiterH = RotL64((aOrbiterH * 5086871400049644715U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 18327987141759096769U) + RotL64(aNonceWordG, 29U);
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 2645964788056875452U;
            aOrbiterB = RotL64((aOrbiterB * 8778681366114628045U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 2859452497983106129U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 7196557924940881076U) ^ RotL64(aNonceWordE, 20U);
            aOrbiterI = RotL64((aOrbiterI * 14415389907490256711U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 930127943984174668U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 15673596916054795749U) ^ aOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7505660488733199479U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 16673140529110941163U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 2258448294877833760U;
            aOrbiterD = RotL64((aOrbiterD * 1821550319748977445U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 6870209259643931219U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 12749790107942194104U;
            aOrbiterJ = RotL64((aOrbiterJ * 4871407285968611725U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 17131374134617173866U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 6426448390733751612U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12490559588384058417U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 15592826434339731146U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 14182944418026376183U;
            aOrbiterK = RotL64((aOrbiterK * 7218860482893476233U), 35U);
            //
            aIngress = RotL64(aOrbiterJ, 27U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 10U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 53U));
            aIngress = aIngress + RotL64(aOrbiterH, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aScatter, 18U) + RotL64(aOrbiterF, 21U)) + aOrbiterJ) + RotL64(aNonceWordA, 61U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 57U) + aOrbiterF) + RotL64(aOrbiterB, 47U)) + RotL64(aNonceWordB, 25U));
            aWandererA = aWandererA + ((((RotL64(aCross, 35U) + RotL64(aOrbiterI, 29U)) + aOrbiterD) + RotL64(aCarry, 27U)) + aWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 43U) + aOrbiterK) + RotL64(aOrbiterD, 56U));
            aWandererK = aWandererK + ((RotL64(aScatter, 47U) + RotL64(aOrbiterJ, 35U)) + aOrbiterI);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterH, 51U)) + aOrbiterJ);
            aWandererD = aWandererD + (((RotL64(aPrevious, 51U) + aOrbiterG) + RotL64(aOrbiterD, 39U)) + RotL64(aCarry, 47U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 13U) + aOrbiterC) + RotL64(aOrbiterH, 11U)) + aWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 22U) + RotL64(aOrbiterJ, 6U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererD, 18U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + RotL64(aWandererB, 21U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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

void TwistExpander_Bowling_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterE = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x848B023087BC5C63ULL + 0xC71CA917E6BCC77DULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x9CBC5C33AFFED209ULL + 0xEF0A0524DFB0A83FULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xDBD5238A765A8D07ULL + 0xEFDE7CCC4B595932ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xE00358BAA5AA9B11ULL + 0xEFF95B2DAD2468DBULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xD593600F293D7429ULL + 0xD5F164E2BB04AEE9ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xBF29CA70CDB9B709ULL + 0x80B84BD3327A42E7ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xDBB4C5BB3E45A5A7ULL + 0xC16F660528593986ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xB7843A980B10C6A9ULL + 0xA232BD6BFE396095ULL);
    std::uint64_t aDomainWordIngress = pConstants->mIngress;
    std::uint64_t aDomainWordScatter = pConstants->mScatter;
    std::uint64_t aDomainWordCross = pConstants->mCross;
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 46U) ^ RotL64(aNonceWordH, 5U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 1613U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneC[((aIndex + 281U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 19U) ^ RotL64(aNonceWordD, 5U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 5363U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((aIndex + 6573U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 19U) ^ RotL64(aIngress, 51U)) + (RotL64(aCross, 38U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (((aWandererJ + RotL64(aScatter, 13U)) + RotL64(aCarry, 51U)) + 1042610313571524121U) + aOrbiterAssignSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = ((((aWandererF + RotL64(aIngress, 4U)) + RotL64(aCarry, 19U)) + 3505725321008825582U) + aOrbiterAssignSaltD[(((31U - aIndex) + 22U)) & S_SALT1]) + RotL64(aNonceWordC, 49U);
            aOrbiterC = (aWandererH + RotL64(aPrevious, 29U)) + 12584654563843782991U;
            aOrbiterG = ((aWandererD + RotL64(aCross, 41U)) + 6645399144515770935U) + RotL64(aNonceWordB, 12U);
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 53U)) + RotL64(aCarry, 5U)) + 3608978423753715584U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 8089198857670370983U) + RotL64(aNonceWordG, 3U);
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 15207251813516399879U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7596841660069752069U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 9579268660105824516U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 16055044469473802812U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2269649280637188723U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 583811872609805949U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 7027491967970873942U) ^ RotL64(aNonceWordH, 43U);
            aOrbiterG = RotL64((aOrbiterG * 12686754713465826139U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 18256061823189677508U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 12708429127816136937U) ^ aOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12593886633108075321U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 12169216645156306078U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 12694325407567795065U;
            aOrbiterE = RotL64((aOrbiterE * 3711789483877261899U), 57U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterC, 5U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 58U));
            aIngress = aIngress + RotL64(aOrbiterJ, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((((RotL64(aScatter, 3U) + RotL64(aOrbiterJ, 20U)) + aOrbiterE) + RotL64(aCarry, 37U)) + RotL64(aNonceWordA, 37U)) + aWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 53U) + aOrbiterJ) + RotL64(aOrbiterG, 43U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 20U) + aOrbiterF) + RotL64(aOrbiterE, 11U)) + RotL64(aCarry, 19U));
            aWandererF = aWandererF ^ ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterJ, 51U)) + aOrbiterC) + RotL64(aNonceWordF, 39U)) + aWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 41U) + aOrbiterJ) + RotL64(aOrbiterF, 29U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + (RotL64(aWandererJ, 4U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererF, 29U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 29U) ^ RotL64(aNonceWordD, 21U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 15521U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneD[((aIndex + 10700U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 4U) ^ RotL64(aNonceWordC, 35U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 8832U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneB[((aIndex + 13851U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 28U) ^ RotL64(aIngress, 11U)) + (RotL64(aPrevious, 41U) + RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((((aWandererG + RotL64(aScatter, 21U)) + RotL64(aCarry, 57U)) + 13880995121909552664U) + aOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1]) + RotL64(aNonceWordE, 29U);
            aOrbiterC = ((aWandererH + RotL64(aCross, 57U)) + 14534942818069300546U) + aOrbiterAssignSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 11U)) + RotL64(aCarry, 5U)) + 17745973100886007133U;
            aOrbiterI = ((aWandererC + RotL64(aIngress, 3U)) + RotL64(aCarry, 37U)) + 2249805580771946872U;
            aOrbiterF = ((aWandererK + RotL64(aScatter, 34U)) + 4460116116396439410U) + RotL64(aNonceWordG, 45U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 3378683994078106878U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 3992996501048809123U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13273544260537223797U), 47U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterI) + 12057768808864451929U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]) + RotL64(aNonceWordB, 60U);
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 4115362079047921130U;
            aOrbiterF = RotL64((aOrbiterF * 12263015903331031345U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 15297384955502206698U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 17623548383481905636U;
            aOrbiterB = RotL64((aOrbiterB * 7487278217901483685U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 3559213898000162417U) + aOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 12311605719074507335U;
            aOrbiterC = RotL64((aOrbiterC * 3982199462062847697U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 14807313864347885885U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 11222085523291581822U) ^ RotL64(aNonceWordC, 39U);
            aOrbiterI = RotL64((aOrbiterI * 12580941911587215653U), 57U);
            //
            aIngress = RotL64(aOrbiterF, 19U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + RotL64(aOrbiterC, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterH, 29U)) + aOrbiterF) + aWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererD = aWandererD + (((((RotL64(aPrevious, 57U) + RotL64(aOrbiterC, 11U)) + aOrbiterB) + RotL64(aCarry, 57U)) + RotL64(aNonceWordH, 13U)) + aWandererUpdateSaltD[((aIndex + 18U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 24U) + aOrbiterF) + RotL64(aOrbiterB, 47U));
            aWandererH = aWandererH + ((((RotL64(aCross, 43U) + aOrbiterI) + RotL64(aOrbiterC, 19U)) + RotL64(aCarry, 27U)) + RotL64(aNonceWordF, 49U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterI, 58U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererG);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + RotL64(aWandererC, 4U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 24U) ^ RotL64(aNonceWordA, 11U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 22423U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20902U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 4U) ^ RotL64(aNonceWordC, 13U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 16459U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneC[((aIndex + 24369U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 3U) ^ RotL64(aCarry, 27U)) + (RotL64(aPrevious, 39U) + RotL64(aCross, 52U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 29U)) + 13915875634607599122U) + RotL64(aNonceWordE, 57U);
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 5U)) + RotL64(aCarry, 51U)) + 1695770381382411673U;
            aOrbiterK = ((((aWandererI + RotL64(aCross, 43U)) + RotL64(aCarry, 35U)) + 3709105579778295511U) + aOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1]) + RotL64(aNonceWordC, 31U);
            aOrbiterA = ((aWandererE + RotL64(aIngress, 51U)) + 7673376335333251804U) + aOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = ((aWandererH + RotL64(aScatter, 18U)) + RotL64(aCarry, 21U)) + 8814147709738503518U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 13451412605350381172U) + aOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 6447870234069609538U) ^ RotL64(aNonceWordG, 50U);
            aOrbiterK = RotL64((aOrbiterK * 4016219229618539433U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 13419487997946496825U) + aOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 5478309847615220345U;
            aOrbiterE = RotL64((aOrbiterE * 12953043149543448765U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 3635184969215610049U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 12527903812035294828U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12540800512035534967U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 1684685110885338814U) + aOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 12860354576326835090U;
            aOrbiterA = RotL64((aOrbiterA * 12743745087733307255U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 9081823570147481835U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 14369321778210049109U) ^ RotL64(aNonceWordB, 23U);
            aOrbiterF = RotL64((aOrbiterF * 17865953349448767035U), 23U);
            //
            aIngress = RotL64(aOrbiterA, 13U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 50U));
            aIngress = aIngress + RotL64(aOrbiterF, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterA, 11U)) + aOrbiterF);
            aWandererJ = aWandererJ + (((((RotL64(aScatter, 57U) + aOrbiterE) + RotL64(aOrbiterG, 19U)) + RotL64(aCarry, 39U)) + RotL64(aNonceWordD, 9U)) + aWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 48U) + RotL64(aOrbiterF, 29U)) + aOrbiterK);
            aWandererH = aWandererH + (((RotL64(aCross, 39U) + RotL64(aOrbiterG, 41U)) + aOrbiterA) + RotL64(aCarry, 57U));
            aWandererF = aWandererF ^ ((((RotL64(aIngress, 11U) + RotL64(aOrbiterK, 60U)) + aOrbiterG) + RotL64(aNonceWordH, 27U)) + aWandererUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 52U) ^ aWandererE);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + RotL64(aWandererH, 35U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 4U) ^ RotL64(aNonceWordD, 23U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 24949U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25729U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 51U) ^ RotL64(aNonceWordH, 29U)) ^ RotL64(aNonceWordF, 10U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 31842U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneD[((aIndex + 31926U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 24U) + RotL64(aCross, 53U)) ^ (RotL64(aIngress, 5U) + RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (((aWandererB + RotL64(aCross, 5U)) + RotL64(aCarry, 35U)) + 10038936806177516123U) + aOrbiterAssignSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterH = ((aWandererF + RotL64(aScatter, 28U)) + 1773168435195292638U) + RotL64(aNonceWordF, 56U);
            aOrbiterC = ((aWandererC + RotL64(aIngress, 41U)) + RotL64(aCarry, 53U)) + 10655711161526628072U;
            aOrbiterJ = (((aWandererD + RotL64(aPrevious, 57U)) + 14422295664639740437U) + aOrbiterAssignSaltD[((aIndex + 24U)) & S_SALT1]) + RotL64(aNonceWordH, 25U);
            aOrbiterA = ((aWandererI + RotL64(aScatter, 13U)) + RotL64(aCarry, 5U)) + 4125228715513159576U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 3670449653158650845U) + aOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 17553727567180813057U;
            aOrbiterC = RotL64((aOrbiterC * 11814335762020146785U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 5111401772713882743U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 7688573124662314413U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10846442063022821393U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 9438375825507814395U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 14177477039902118886U;
            aOrbiterJ = RotL64((aOrbiterJ * 6467406626985022537U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 16329942595859623928U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 3990536794006836672U) ^ RotL64(aNonceWordA, 21U);
            aOrbiterH = RotL64((aOrbiterH * 579024714339065373U), 13U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterJ) + 5072881436583180756U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]) + RotL64(aNonceWordD, 27U);
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 16789727877867289997U;
            aOrbiterA = RotL64((aOrbiterA * 8766246302636197905U), 57U);
            //
            aIngress = RotL64(aOrbiterF, 3U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 13U));
            aIngress = aIngress + RotL64(aOrbiterA, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aPrevious, 21U) + aOrbiterH) + RotL64(aOrbiterF, 51U)) + RotL64(aCarry, 23U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterH, 41U)) + aOrbiterC);
            aWandererC = aWandererC + ((((RotL64(aScatter, 30U) + RotL64(aOrbiterC, 11U)) + aOrbiterJ) + RotL64(aCarry, 39U)) + aWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((((RotL64(aCross, 41U) + aOrbiterA) + RotL64(aOrbiterF, 24U)) + RotL64(aNonceWordG, 17U)) + aWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 11U) + aOrbiterJ) + RotL64(aOrbiterF, 3U)) + RotL64(aNonceWordE, 23U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 37U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 58U));
            aCarry = aCarry + RotL64(aWandererF, 47U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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

void TwistExpander_Bowling_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xD0EA2B7EEF2B616DULL + 0xC7F7371E3359832DULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xF8D96B2485B58B5BULL + 0xCDC653EF9A3E5188ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xB7B1EED8519F9F05ULL + 0xC9A21089BB48DE7AULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x8103059A87906281ULL + 0x88415E9677447EC2ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x90A272945884E1C5ULL + 0xD3FF818FF2EF6B7BULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xEE25595324E45487ULL + 0xB6A36EF3F6F35213ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xDCC1FABE6100BCF3ULL + 0xAE81CD9E03A8BB52ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xF0B8B94DC68A3201ULL + 0x8EB033E873D05C3AULL);
    std::uint64_t aDomainWordIngress = pConstants->mIngress;
    std::uint64_t aDomainWordScatter = pConstants->mScatter;
    std::uint64_t aDomainWordCross = pConstants->mCross;
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 24U) ^ RotL64(aNonceWordD, 43U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 4641U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5646U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 27U) ^ RotL64(aNonceWordA, 19U)) ^ RotL64(aNonceWordG, 38U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 7668U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((aIndex + 4135U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 51U) + RotL64(aCross, 5U)) + (RotL64(aCarry, 39U) ^ RotL64(aPrevious, 18U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 22U)) + RotL64(aCarry, 37U)) + 7075016829833562104U;
            aOrbiterF = (aWandererF + RotL64(aScatter, 57U)) + 8783765886115517036U;
            aOrbiterK = ((((aWandererC + RotL64(aCross, 11U)) + RotL64(aCarry, 13U)) + 2996723892384565829U) + aOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1]) + RotL64(aNonceWordG, 9U);
            aOrbiterD = (aWandererD + RotL64(aPrevious, 51U)) + 9494134707342189476U;
            aOrbiterC = ((aWandererA + RotL64(aScatter, 35U)) + 5052642981395679904U) + aOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = (aWandererI + RotL64(aCross, 5U)) + 8766787055127962238U;
            aOrbiterB = (((aWandererB + RotL64(aPrevious, 43U)) + RotL64(aCarry, 53U)) + 4467211954388738079U) + RotL64(aNonceWordE, 7U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 8030255604633658608U) + RotL64(aNonceWordF, 3U);
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 16962408063455702251U;
            aOrbiterK = RotL64((aOrbiterK * 11171737929747471631U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 3768222186567699076U) + aOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 14930990410207899871U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10930005786146268241U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 14179761938395502502U) + RotL64(aNonceWordA, 57U);
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 1879084742719898108U;
            aOrbiterA = RotL64((aOrbiterA * 16783034788172670121U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 5535012408925981515U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 12792553516710295939U;
            aOrbiterB = RotL64((aOrbiterB * 8577530993755159329U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 8979253163346099252U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 5559189896063990740U;
            aOrbiterI = RotL64((aOrbiterI * 8832485423727331621U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 13937564337299044079U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 2393376759689394948U) ^ aOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2352815657830413941U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 12647519563697356479U) + aOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 10946871249960389549U;
            aOrbiterF = RotL64((aOrbiterF * 6272580371881237173U), 29U);
            //
            aIngress = RotL64(aOrbiterD, 47U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterK, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aScatter, 11U) + aOrbiterC) + RotL64(aOrbiterD, 3U)) + RotL64(aNonceWordC, 18U));
            aWandererD = aWandererD + (((RotL64(aCross, 43U) + aOrbiterC) + RotL64(aOrbiterF, 41U)) + RotL64(aCarry, 53U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterB, 60U)) + aOrbiterF);
            aWandererC = aWandererC + (((((RotL64(aPrevious, 3U) + RotL64(aOrbiterF, 35U)) + aOrbiterA) + RotL64(aCarry, 39U)) + RotL64(aNonceWordB, 29U)) + aWandererUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 19U) + aOrbiterI) + RotL64(aOrbiterK, 29U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 35U) + aOrbiterI) + RotL64(aOrbiterC, 19U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 50U) + RotL64(aOrbiterA, 47U)) + aOrbiterK) + aWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 46U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererB, 11U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 35U) ^ RotL64(aNonceWordC, 54U)) ^ RotL64(aNonceWordG, 3U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9000U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 12623U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 3U) ^ RotL64(aNonceWordB, 38U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 10364U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 9462U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aPrevious, 34U)) ^ (RotL64(aCross, 21U) + RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererD + RotL64(aPrevious, 3U)) + 10812151398716051703U;
            aOrbiterB = (((aWandererK + RotL64(aCross, 57U)) + RotL64(aCarry, 29U)) + 18202551453336003710U) + aOrbiterAssignSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = (aWandererC + RotL64(aIngress, 21U)) + 9434410809101973752U;
            aOrbiterD = ((aWandererF + RotL64(aScatter, 34U)) + 12955829998028534045U) + RotL64(aNonceWordE, 47U);
            aOrbiterG = ((aWandererA + RotL64(aIngress, 27U)) + RotL64(aCarry, 57U)) + 12271740641929640181U;
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 11U)) + 14009351527014534752U) + aOrbiterAssignSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterF = (((aWandererG + RotL64(aScatter, 51U)) + RotL64(aCarry, 13U)) + 4316296955679133450U) + RotL64(aNonceWordC, 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 16473324966997442872U) + aOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 15735123324965019802U;
            aOrbiterC = RotL64((aOrbiterC * 5624078184997601019U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 17656375090484080236U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 16066325053456055298U;
            aOrbiterJ = RotL64((aOrbiterJ * 17912970706985130327U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 12908968778503516903U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 12761433987676836197U;
            aOrbiterD = RotL64((aOrbiterD * 1023329467480907925U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 12737513138040664509U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 14535795767570998392U) ^ RotL64(aNonceWordH, 22U);
            aOrbiterB = RotL64((aOrbiterB * 15560519667062222269U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 14370908061811284364U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 7001358781208669795U;
            aOrbiterG = RotL64((aOrbiterG * 11641248025734015835U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 7298578161120090849U) + aOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 10498302152357484629U) ^ RotL64(aNonceWordB, 25U);
            aOrbiterK = RotL64((aOrbiterK * 13144110412179037175U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 11447343228638006767U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 18284143620422655675U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 572862190073605651U), 47U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterJ, 51U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 11U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + RotL64(aOrbiterC, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aScatter, 51U) + aOrbiterD) + RotL64(aOrbiterG, 57U)) + aWandererUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterJ, 35U)) + aOrbiterB);
            aWandererC = aWandererC + (((RotL64(aPrevious, 23U) + aOrbiterJ) + RotL64(aOrbiterK, 47U)) + RotL64(aCarry, 3U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 10U) + RotL64(aOrbiterC, 27U)) + aOrbiterK) + RotL64(aNonceWordA, 57U));
            aWandererF = aWandererF + ((((RotL64(aScatter, 29U) + RotL64(aOrbiterD, 14U)) + aOrbiterJ) + RotL64(aCarry, 47U)) + RotL64(aNonceWordF, 3U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterJ, 3U)) + aOrbiterF);
            aWandererA = aWandererA + (((RotL64(aIngress, 3U) + RotL64(aOrbiterC, 21U)) + aOrbiterJ) + aWandererUpdateSaltD[((aIndex + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 28U));
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererG, 37U);
            aCarry = aCarry + RotL64(aIngress, 46U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 3U) ^ RotL64(aNonceWordE, 18U)) ^ RotL64(aNonceWordA, 39U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 17147U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((aIndex + 16668U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 13U) ^ RotL64(aNonceWordB, 34U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17192U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 24224U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 26U) ^ RotL64(aCarry, 3U)) + (RotL64(aPrevious, 53U) ^ RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (((aWandererC + RotL64(aIngress, 47U)) + RotL64(aCarry, 53U)) + 7632760812370906911U) + aOrbiterAssignSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 13U)) + RotL64(aCarry, 5U)) + 6007174525479723089U;
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 37U)) + 3362829642521821048U) + RotL64(aNonceWordA, 15U);
            aOrbiterK = (aWandererD + RotL64(aCross, 29U)) + 18009548556107978286U;
            aOrbiterE = (aWandererH + RotL64(aScatter, 5U)) + 17880909432272697327U;
            aOrbiterB = (aWandererB + RotL64(aIngress, 54U)) + 15961567935420752568U;
            aOrbiterI = ((((aWandererG + RotL64(aPrevious, 23U)) + RotL64(aCarry, 39U)) + 10136559064656837921U) + aOrbiterAssignSaltB[(((31U - aIndex) + 26U)) & S_SALT1]) + RotL64(aNonceWordC, 25U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 17622019364405410277U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 6927494824421416306U;
            aOrbiterJ = RotL64((aOrbiterJ * 2686290883767829973U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 7125170407794874847U) + aOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 12342273503071032250U;
            aOrbiterD = RotL64((aOrbiterD * 867417849555857179U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 14997696377476124836U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 14874498694181230698U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4026127545746010937U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 2549397729130885686U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 4217995818662767955U) ^ RotL64(aNonceWordD, 37U);
            aOrbiterK = RotL64((aOrbiterK * 5525525344485251063U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 4706089044415442525U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 17983900172670031015U;
            aOrbiterE = RotL64((aOrbiterE * 541552737180932879U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 1904937798143929988U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 10620877287033139483U) ^ RotL64(aNonceWordG, 53U);
            aOrbiterB = RotL64((aOrbiterB * 16711012562024287213U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 15681091173163181525U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 2655543246639000084U) ^ aOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16686375598149755947U), 57U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterK, 3U);
            aIngress = aIngress + (RotL64(aOrbiterI, 51U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterD, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aIngress, 57U) + aOrbiterI) + RotL64(aOrbiterJ, 29U)) + RotL64(aCarry, 51U)) + RotL64(aNonceWordH, 41U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 50U) + RotL64(aOrbiterD, 43U)) + aOrbiterA);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 5U) + aOrbiterK) + RotL64(aOrbiterJ, 57U)) + RotL64(aCarry, 23U)) + aWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterE, 13U)) + aOrbiterK);
            aWandererE = aWandererE + ((RotL64(aPrevious, 41U) + aOrbiterB) + RotL64(aOrbiterI, 23U));
            aWandererD = aWandererD ^ ((((RotL64(aCross, 19U) + RotL64(aOrbiterD, 37U)) + aOrbiterK) + RotL64(aNonceWordF, 24U)) + aWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aScatter, 13U) + aOrbiterJ) + RotL64(aOrbiterA, 6U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 21U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 38U));
            aCarry = aCarry + RotL64(aWandererG, 51U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 19U) ^ RotL64(aNonceWordC, 48U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 28012U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26865U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 29U) ^ RotL64(aNonceWordA, 12U)) ^ RotL64(aNonceWordG, 39U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27107U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 32372U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 60U) + RotL64(aCross, 43U)) ^ (RotL64(aCarry, 11U) + RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((((aWandererE + RotL64(aIngress, 37U)) + RotL64(aCarry, 39U)) + 16016931609704150191U) + aOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1]) + RotL64(aNonceWordC, 59U);
            aOrbiterD = (aWandererJ + RotL64(aPrevious, 57U)) + 14511433515861302636U;
            aOrbiterB = (((aWandererF + RotL64(aCross, 21U)) + RotL64(aCarry, 5U)) + 11691237442613269593U) + RotL64(aNonceWordG, 3U);
            aOrbiterA = (aWandererA + RotL64(aScatter, 29U)) + 16383220587320484649U;
            aOrbiterH = ((aWandererH + RotL64(aCross, 10U)) + 14293015313458219868U) + aOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = ((aWandererK + RotL64(aScatter, 51U)) + RotL64(aCarry, 57U)) + 4407695248205526670U;
            aOrbiterK = (aWandererG + RotL64(aPrevious, 43U)) + 1158323195324398372U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 6577683409653864555U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 171080079472863843U;
            aOrbiterB = RotL64((aOrbiterB * 3063978974927752653U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 5766333425872228205U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 16173508656917582960U;
            aOrbiterI = RotL64((aOrbiterI * 12187968015372936695U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 11781450063402219202U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 13033139686637576694U;
            aOrbiterD = RotL64((aOrbiterD * 4331137994135472025U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 4006310759400926020U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 13156817947481574467U;
            aOrbiterH = RotL64((aOrbiterH * 563189239835001483U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 12791290558893516411U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 989729955679243234U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8757228712495095017U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 838379839663022790U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 2830743864262313606U;
            aOrbiterA = RotL64((aOrbiterA * 10173947177104802797U), 21U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterI) + 2146646527331684652U) + aOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1]) + RotL64(aNonceWordF, 21U);
            aOrbiterK = (((aOrbiterK ^ aOrbiterH) ^ 4629168181742174906U) ^ aOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1]) ^ RotL64(aNonceWordH, 42U);
            aOrbiterK = RotL64((aOrbiterK * 9046124907945045131U), 57U);
            //
            aIngress = RotL64(aOrbiterD, 3U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 57U));
            aIngress = aIngress + (RotL64(aOrbiterB, 51U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterI, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aScatter, 29U) + RotL64(aOrbiterD, 37U)) + aOrbiterH) + RotL64(aNonceWordE, 19U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 35U) + aOrbiterF) + RotL64(aOrbiterB, 29U)) + RotL64(aNonceWordD, 39U));
            aWandererF = aWandererF + ((RotL64(aCross, 19U) + aOrbiterA) + RotL64(aOrbiterD, 50U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 48U) + aOrbiterD) + RotL64(aOrbiterB, 11U)) + aWandererUpdateSaltE[((aIndex + 12U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 11U) + RotL64(aOrbiterF, 3U)) + aOrbiterK) + RotL64(aCarry, 5U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterI, 21U)) + aOrbiterH) + aWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterF, 43U)) + aOrbiterD) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererF, 4U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererA, 23U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xBF008BF2BF004957ULL + 0xA88CE0F690E46CD5ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xAB27DFB4D72BD42BULL + 0x815CB5734FA0E2CFULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xE5C076587FD6273FULL + 0xEA23A077487AFF89ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xA14AF1C8C921E565ULL + 0x97A46978142393C7ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xDE8C314FE202BFA3ULL + 0xE086C00AC9F148B7ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x84D7BDD3590CC277ULL + 0xC361AEB6B12603DBULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xDEB4BAB78FA47623ULL + 0xB80E4EBDC5C4B763ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xA39B9FB3BC34E2E7ULL + 0x9D456639498A32A2ULL);
    std::uint64_t aDomainWordIngress = pConstants->mIngress;
    std::uint64_t aDomainWordScatter = pConstants->mScatter;
    std::uint64_t aDomainWordCross = pConstants->mCross;
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 13U) ^ RotL64(aNonceWordE, 57U)) ^ RotL64(aNonceWordG, 23U));
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 2623U)) & S_BLOCK1], 36U) ^ RotL64(aWorkLaneC[((aIndex + 3750U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 57U) ^ RotL64(aNonceWordB, 21U)) ^ RotL64(aNonceWordH, 13U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 3451U)) & S_BLOCK1], 44U) ^ RotL64(aWorkLaneA[((aIndex + 4964U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 35U) ^ RotL64(aIngress, 23U)) ^ (RotL64(aCross, 47U) + RotL64(aPrevious, 10U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((aWandererK + RotL64(aScatter, 19U)) + 2571116506511057880U) + aOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = (((aWandererE + RotL64(aPrevious, 51U)) + RotL64(aCarry, 53U)) + 13112435411509707292U) + RotL64(aNonceWordB, 45U);
            aOrbiterH = ((((aWandererI + RotL64(aIngress, 43U)) + RotL64(aCarry, 41U)) + 10403251762787357256U) + aOrbiterAssignSaltA[(((31U - aIndex) + 12U)) & S_SALT1]) + RotL64(aNonceWordD, 3U);
            aOrbiterC = (aWandererC + RotL64(aCross, 11U)) + 8461951095541400405U;
            aOrbiterI = (aWandererD + RotL64(aPrevious, 58U)) + 9890793478557463815U;
            aOrbiterD = (aWandererB + RotL64(aScatter, 35U)) + 3030229465991783707U;
            aOrbiterK = ((aWandererA + RotL64(aCross, 3U)) + RotL64(aCarry, 13U)) + 7273848154043719247U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 10681774862516028276U) + RotL64(aNonceWordC, 9U);
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 7105082755586853104U;
            aOrbiterH = RotL64((aOrbiterH * 12217705329504230357U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 6588579345319551129U) + RotL64(aNonceWordA, 59U);
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 14616333550242386092U;
            aOrbiterI = RotL64((aOrbiterI * 2934574715879306337U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 15439666290229654921U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 3360304356760164799U;
            aOrbiterD = RotL64((aOrbiterD * 5164191920584106237U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 14438730801970761889U) + aOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 14515616787452085729U;
            aOrbiterK = RotL64((aOrbiterK * 2041601927968559821U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 4167853822635132419U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 8950982233003320239U) ^ aOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 887144270884244907U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 12391327853728029953U) + aOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 7100871010552394421U;
            aOrbiterC = RotL64((aOrbiterC * 16552349374101955967U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 15381697462381887944U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 6801677551341079401U;
            aOrbiterJ = RotL64((aOrbiterJ * 13325954438427340703U), 19U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterI, 13U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 41U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 35U));
            aIngress = aIngress + RotL64(aOrbiterK, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aCross, 21U) + aOrbiterC) + RotL64(aOrbiterH, 23U)) + aWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterD, 51U)) + aOrbiterC);
            aWandererB = aWandererB + (((RotL64(aIngress, 27U) + RotL64(aOrbiterJ, 12U)) + aOrbiterD) + RotL64(aCarry, 19U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterK, 35U)) + aOrbiterF) + RotL64(aNonceWordF, 17U));
            aWandererI = aWandererI + (((RotL64(aIngress, 50U) + aOrbiterF) + RotL64(aOrbiterD, 57U)) + aWandererUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 3U) + aOrbiterF) + RotL64(aOrbiterI, 3U));
            aWandererA = aWandererA + ((((RotL64(aCross, 41U) + RotL64(aOrbiterH, 43U)) + aOrbiterD) + RotL64(aCarry, 39U)) + RotL64(aNonceWordE, 42U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 34U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererD, 21U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 29U) ^ RotL64(aNonceWordB, 53U)) ^ RotL64(aNonceWordG, 43U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 13245U)) & S_BLOCK1], 6U) ^ RotL64(aWorkLaneD[((aIndex + 9714U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 41U) ^ RotL64(aNonceWordA, 5U)) ^ RotL64(aNonceWordH, 23U));
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 10856U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 9062U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 27U) + RotL64(aCarry, 56U)) ^ (RotL64(aCross, 11U) ^ RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = ((aWandererG + RotL64(aCross, 3U)) + 17912271996338180948U) + aOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = ((aWandererH + RotL64(aPrevious, 51U)) + RotL64(aCarry, 57U)) + 13259276608841847058U;
            aOrbiterI = ((aWandererD + RotL64(aScatter, 43U)) + 16225936008657276089U) + aOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = ((aWandererC + RotL64(aIngress, 57U)) + RotL64(aCarry, 5U)) + 2243058962151834071U;
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 12U)) + 10637439274127347861U) + RotL64(aNonceWordA, 45U);
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 35U)) + 15312219216405992627U) + RotL64(aNonceWordG, 59U);
            aOrbiterC = ((aWandererF + RotL64(aCross, 27U)) + RotL64(aCarry, 39U)) + 2393933972129878613U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 4327069337247976513U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 8307656353434167837U;
            aOrbiterI = RotL64((aOrbiterI * 11386588389133096705U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 17299145556933889336U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 14458100581172798164U;
            aOrbiterG = RotL64((aOrbiterG * 16543734663677070509U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 6410095654927998067U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 6168964796264687686U;
            aOrbiterD = RotL64((aOrbiterD * 16218071040190475953U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 3667999465041020730U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 16021552859323602007U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6427266472526362663U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 12941668202330045095U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 4222032891850449934U) ^ RotL64(aNonceWordH, 35U);
            aOrbiterF = RotL64((aOrbiterF * 17292856787431308097U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 1346342592002730785U) + aOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 16860611785008118820U;
            aOrbiterE = RotL64((aOrbiterE * 384963420804756607U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 3193572711804730241U) + RotL64(aNonceWordC, 12U);
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 5866881282680588589U;
            aOrbiterC = RotL64((aOrbiterC * 9226331800853634597U), 53U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterE, 5U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 37U));
            aIngress = aIngress + (RotL64(aOrbiterG, 29U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterH, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterH, 3U)) + RotL64(aNonceWordF, 21U));
            aWandererE = aWandererE + ((((RotL64(aScatter, 57U) + aOrbiterF) + RotL64(aOrbiterC, 29U)) + RotL64(aCarry, 5U)) + aWandererUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((((RotL64(aCross, 22U) + RotL64(aOrbiterE, 37U)) + aOrbiterH) + RotL64(aNonceWordE, 53U)) + aWandererUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 41U) + aOrbiterE) + RotL64(aOrbiterI, 52U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterD, 13U)) + aOrbiterI);
            aWandererG = aWandererG + (((RotL64(aIngress, 47U) + aOrbiterC) + RotL64(aOrbiterI, 23U)) + RotL64(aCarry, 27U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 29U) + aOrbiterD) + RotL64(aOrbiterG, 43U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 41U));
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 19U));
            aCarry = aCarry + RotL64(aWandererC, 12U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 13U) ^ RotL64(aNonceWordA, 37U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 17075U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneA[((aIndex + 24033U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 19U) ^ RotL64(aNonceWordE, 57U));
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 23407U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 16848U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aIngress, 19U)) + (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 36U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((aWandererC + RotL64(aScatter, 43U)) + 10336802574069791273U) + RotL64(aNonceWordE, 59U);
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 21U)) + 169025388197058936U) + aOrbiterAssignSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = (aWandererI + RotL64(aIngress, 56U)) + 6541354188379168846U;
            aOrbiterD = (aWandererH + RotL64(aCross, 3U)) + 16223920526599306104U;
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 27U)) + RotL64(aCarry, 19U)) + 12756613707692514808U;
            aOrbiterI = ((aWandererG + RotL64(aCross, 37U)) + RotL64(aCarry, 5U)) + 5082475548176484035U;
            aOrbiterF = ((((aWandererK + RotL64(aScatter, 13U)) + RotL64(aCarry, 41U)) + 4907435526952698526U) + aOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1]) + RotL64(aNonceWordB, 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 14236627073831834337U) + RotL64(aNonceWordD, 53U);
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 11502511046130497584U;
            aOrbiterB = RotL64((aOrbiterB * 3460330807286625917U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 3679044835550219497U) + aOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = (((aOrbiterK ^ aOrbiterD) ^ 11254838916686736746U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]) ^ RotL64(aNonceWordC, 58U);
            aOrbiterK = RotL64((aOrbiterK * 8631695922983532915U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 10582608424233200966U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 10449735026385340313U;
            aOrbiterA = RotL64((aOrbiterA * 7363770199734997411U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 4628253464169957835U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 17664454668473204465U) ^ aOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4234720298731378527U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 3798386391743884889U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 1379331161819246587U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13086160171095077295U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 9816600392407327227U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 16781971616348376878U;
            aOrbiterI = RotL64((aOrbiterI * 12503867584828289879U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 4807797577690520554U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 2492057261148595922U;
            aOrbiterF = RotL64((aOrbiterF * 9453302540675483005U), 21U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterI, 5U);
            aIngress = aIngress + (RotL64(aOrbiterB, 19U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterK, 48U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterA, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 21U) + aOrbiterA) + RotL64(aOrbiterK, 6U));
            aWandererI = aWandererI + ((((RotL64(aPrevious, 44U) + RotL64(aOrbiterA, 21U)) + aOrbiterD) + RotL64(aCarry, 27U)) + aWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterD, 37U)) + aOrbiterG);
            aWandererC = aWandererC + ((((RotL64(aIngress, 27U) + RotL64(aOrbiterF, 29U)) + aOrbiterG) + RotL64(aCarry, 43U)) + RotL64(aNonceWordG, 57U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 37U) + aOrbiterB) + RotL64(aOrbiterI, 13U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 57U) + aOrbiterA) + RotL64(aOrbiterG, 57U)) + RotL64(aNonceWordF, 15U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterF, 43U)) + aOrbiterI) + aWandererUpdateSaltD[((aIndex + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 24U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererI, 41U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 3U) ^ RotL64(aNonceWordA, 23U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 31071U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((aIndex + 27174U)) & S_BLOCK1], 44U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 11U) ^ RotL64(aNonceWordH, 35U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30772U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 25346U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 54U) + RotL64(aIngress, 41U)) ^ (RotL64(aPrevious, 3U) ^ RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererE + RotL64(aCross, 21U)) + RotL64(aCarry, 27U)) + 12122689833405846292U;
            aOrbiterF = (((aWandererK + RotL64(aPrevious, 29U)) + RotL64(aCarry, 5U)) + 9640400270962766788U) + RotL64(aNonceWordB, 38U);
            aOrbiterK = ((aWandererB + RotL64(aIngress, 14U)) + 9141937998266739071U) + RotL64(aNonceWordD, 25U);
            aOrbiterE = (((aWandererD + RotL64(aScatter, 43U)) + RotL64(aCarry, 57U)) + 12899395770434090537U) + aOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 51U)) + 13457918115408031842U;
            aOrbiterA = ((aWandererA + RotL64(aScatter, 37U)) + 15134784483576000943U) + aOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = (aWandererI + RotL64(aCross, 3U)) + 12540961268790055438U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 6306886773092764230U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 13573343491337243121U;
            aOrbiterK = RotL64((aOrbiterK * 15893457012357368707U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 8545588657348974413U) + RotL64(aNonceWordA, 49U);
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 10891410570357275120U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5399310978367842841U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 2877137119767060151U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 9178097682386595144U) ^ RotL64(aNonceWordG, 43U);
            aOrbiterF = RotL64((aOrbiterF * 3524486002084427513U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 15528007881855616978U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 11368419529245281435U;
            aOrbiterJ = RotL64((aOrbiterJ * 12433207037378339309U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 5932738914934356645U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 5551842263864055419U) ^ aOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16093776759971522681U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 3824433359595690603U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 17184628855571662441U;
            aOrbiterE = RotL64((aOrbiterE * 691208053136187317U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 8724462245014132623U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 7481349499528092352U;
            aOrbiterB = RotL64((aOrbiterB * 8212182934509617583U), 3U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterE, 11U);
            aIngress = aIngress + (RotL64(aOrbiterB, 5U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 51U));
            aIngress = aIngress + RotL64(aOrbiterI, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aScatter, 23U) + aOrbiterE) + RotL64(aOrbiterJ, 53U)) + RotL64(aCarry, 43U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 53U) + aOrbiterA) + RotL64(aOrbiterI, 3U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 41U) + aOrbiterA) + RotL64(aOrbiterJ, 29U)) + RotL64(aCarry, 19U));
            aWandererF = aWandererF ^ ((((RotL64(aCross, 3U) + RotL64(aOrbiterB, 18U)) + aOrbiterA) + RotL64(aNonceWordF, 39U)) + aWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aIngress, 35U) + aOrbiterE) + RotL64(aOrbiterK, 35U)) + RotL64(aNonceWordE, 47U)) + aWandererUpdateSaltB[((aIndex + 4U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterI, 47U)) + aOrbiterF);
            aWandererB = aWandererB + ((RotL64(aPrevious, 10U) + aOrbiterK) + RotL64(aOrbiterF, 41U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererF, 6U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererI, 47U);
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

void TwistExpander_Bowling_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xD159A60F133CD84BULL + 0xAAB6F0200C0A289DULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x80C8F3C85CDD6929ULL + 0x82D384B074ABB3FEULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xAEBB28586F97C05FULL + 0x8FC0A37B265A2F3CULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xBECB8A29B0A925BFULL + 0xC5DAE594F79408E3ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xB3E6CA8E1971F999ULL + 0xB30082C34356F9B3ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xC3E01F0CCD3283B3ULL + 0xEA38BBEE8B577D64ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x98289C1889C79A25ULL + 0xF00A308AD5026D08ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x8B8F5EA5E7224B15ULL + 0xF60D517D85157156ULL);
    std::uint64_t aDomainWordIngress = pConstants->mIngress;
    std::uint64_t aDomainWordScatter = pConstants->mScatter;
    std::uint64_t aDomainWordCross = pConstants->mCross;
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 30U) ^ RotL64(aNonceWordF, 11U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 7764U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((aIndex + 6154U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 11U) ^ RotL64(aNonceWordB, 60U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 1757U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 131U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 54U) + RotL64(aIngress, 23U)) + (RotL64(aCarry, 41U) ^ RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererF + RotL64(aIngress, 37U)) + 11521331427196538632U;
            aOrbiterF = (aWandererB + RotL64(aPrevious, 39U)) + 16653824187682957632U;
            aOrbiterB = (aWandererA + RotL64(aScatter, 6U)) + 11654676587350088289U;
            aOrbiterH = ((((aWandererJ + RotL64(aCross, 57U)) + RotL64(aCarry, 19U)) + 8010313317412193584U) + aOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1]) + RotL64(aNonceWordH, 27U);
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 35U)) + 1108775560502907471U) + RotL64(aNonceWordG, 54U);
            aOrbiterD = (aWandererG + RotL64(aIngress, 27U)) + 243952321439823521U;
            aOrbiterJ = (aWandererI + RotL64(aCross, 43U)) + 2324945800401240403U;
            aOrbiterG = (aWandererE + RotL64(aScatter, 54U)) + 9257554497543369657U;
            aOrbiterA = (((aWandererH + RotL64(aPrevious, 13U)) + RotL64(aCarry, 11U)) + 16701314607244592540U) + aOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = (aWandererD + RotL64(aIngress, 3U)) + 3900445848034341782U;
            aOrbiterE = ((aWandererK + RotL64(aScatter, 19U)) + RotL64(aCarry, 53U)) + 7652316487347103658U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 14980368605272070578U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 2001165460948764796U;
            aOrbiterB = RotL64((aOrbiterB * 8110980921827107649U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 1911044015666991050U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 11366207111147818339U;
            aOrbiterD = RotL64((aOrbiterD * 17234439040652553865U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 16469329744002456607U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 8062793687044950815U;
            aOrbiterI = RotL64((aOrbiterI * 5856142259851144369U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 15364721421972807872U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 8979915611483540231U;
            aOrbiterH = RotL64((aOrbiterH * 10899377466171153383U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 7654234623563110457U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 1526832460342135008U) ^ RotL64(aNonceWordD, 43U);
            aOrbiterJ = RotL64((aOrbiterJ * 12766083052650723051U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 1596625448797520938U) + RotL64(aNonceWordF, 35U);
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 15723912914858523080U;
            aOrbiterA = RotL64((aOrbiterA * 6003857787643420337U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 7664226719746532168U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 13767298788411473401U;
            aOrbiterE = RotL64((aOrbiterE * 15663266144965532019U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 8371251860069346385U) + aOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 10143279934304029980U;
            aOrbiterF = RotL64((aOrbiterF * 12764966547132248131U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 10034920090729616747U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 14450253491131954914U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15877567779079226909U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 9450697155749555210U) + aOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 14051719612902917300U;
            aOrbiterG = RotL64((aOrbiterG * 7659810299163085295U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 659383614060726993U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 11521331427196538632U;
            aOrbiterK = RotL64((aOrbiterK * 1068009283450923005U), 41U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterJ, 24U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 47U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 11U));
            aIngress = aIngress + (RotL64(aOrbiterD, 13U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterE, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 27U) + aOrbiterH) + RotL64(aOrbiterD, 3U));
            aWandererE = aWandererE + ((RotL64(aCross, 57U) + RotL64(aOrbiterE, 23U)) + aOrbiterA);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterB, 51U)) + aOrbiterI);
            aWandererF = aWandererF + ((((RotL64(aScatter, 53U) + RotL64(aOrbiterH, 53U)) + aOrbiterK) + RotL64(aNonceWordB, 3U)) + aWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterF, 5U)) + aOrbiterD);
            aWandererG = aWandererG + ((RotL64(aScatter, 22U) + aOrbiterF) + RotL64(aOrbiterG, 41U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 35U) + aOrbiterK) + RotL64(aOrbiterB, 26U));
            aWandererA = aWandererA + (((RotL64(aIngress, 3U) + RotL64(aOrbiterC, 57U)) + aOrbiterH) + RotL64(aCarry, 47U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterB, 43U)) + aOrbiterE) + RotL64(aNonceWordE, 19U));
            aWandererI = aWandererI + ((((RotL64(aScatter, 13U) + RotL64(aOrbiterI, 21U)) + aOrbiterA) + RotL64(aCarry, 5U)) + aWandererUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 10U) + RotL64(aOrbiterF, 10U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 42U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 37U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 5U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 53U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 12U));
            aCarry = aCarry + RotL64(aWandererK, 23U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 23U) ^ RotL64(aNonceWordB, 12U)) ^ RotL64(aNonceWordF, 57U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 10071U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((aIndex + 14158U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 38U) ^ RotL64(aNonceWordE, 47U)) ^ RotL64(aNonceWordH, 3U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 10142U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 10864U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aIngress, 48U)) + (RotL64(aCarry, 21U) ^ RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 54U)) + 11700815697312060726U) + aOrbiterAssignSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = (aWandererH + RotL64(aIngress, 19U)) + 11808423452327465441U;
            aOrbiterJ = (aWandererG + RotL64(aCross, 27U)) + 8670503858631730886U;
            aOrbiterC = (aWandererI + RotL64(aScatter, 21U)) + 2400061067991988544U;
            aOrbiterH = ((aWandererD + RotL64(aCross, 51U)) + 16163118178366229686U) + RotL64(aNonceWordG, 23U);
            aOrbiterI = ((aWandererK + RotL64(aScatter, 23U)) + RotL64(aCarry, 3U)) + 3280178595904941068U;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 6U)) + RotL64(aCarry, 47U)) + 3298683600817047727U;
            aOrbiterB = ((aWandererB + RotL64(aIngress, 35U)) + RotL64(aCarry, 51U)) + 16321624053445183574U;
            aOrbiterF = ((aWandererE + RotL64(aScatter, 57U)) + 6730229877611375225U) + aOrbiterAssignSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterD = ((aWandererA + RotL64(aCross, 13U)) + 10162830636713641322U) + RotL64(aNonceWordC, 17U);
            aOrbiterA = (aWandererF + RotL64(aIngress, 43U)) + 15646771327759599256U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 14841751262270544102U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 9545541117228834895U;
            aOrbiterJ = RotL64((aOrbiterJ * 11529769874752969377U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 14676615635857599982U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 1231768638470558855U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2716808508509014677U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 1945905595345404833U) + aOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 1406171421638586846U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4577864352425476233U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 1970292335806697198U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 12309719390375013297U;
            aOrbiterK = RotL64((aOrbiterK * 16540660957923687327U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 5352135521358954576U) + RotL64(aNonceWordD, 43U);
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 15465675376193501658U;
            aOrbiterF = RotL64((aOrbiterF * 16385761112921041387U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 2842123638916600369U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 3544764287036748668U;
            aOrbiterE = RotL64((aOrbiterE * 3360772950777850115U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 6038297172906492282U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 10249342332287140970U;
            aOrbiterC = RotL64((aOrbiterC * 16701083081566042277U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 1662076777040529446U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 1949705569959740274U;
            aOrbiterI = RotL64((aOrbiterI * 11340691546658994529U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 13934194245417822360U) + aOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 5720408806425535958U;
            aOrbiterB = RotL64((aOrbiterB * 15237561081637415383U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 2209251362417210658U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 4917447930929521699U;
            aOrbiterD = RotL64((aOrbiterD * 17489570156694692569U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 14817115766683623486U) + RotL64(aNonceWordA, 31U);
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 11700815697312060726U;
            aOrbiterA = RotL64((aOrbiterA * 16982411053956669181U), 57U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterG, 27U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 19U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 43U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 38U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterD, 29U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterE, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 5U) + aOrbiterG) + RotL64(aOrbiterD, 27U));
            aWandererC = aWandererC + ((RotL64(aIngress, 13U) + RotL64(aOrbiterK, 43U)) + aOrbiterA);
            aWandererD = aWandererD ^ ((((RotL64(aScatter, 11U) + aOrbiterE) + RotL64(aOrbiterD, 39U)) + RotL64(aNonceWordB, 52U)) + aWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 21U) + aOrbiterH) + RotL64(aOrbiterD, 18U)) + RotL64(aCarry, 5U)) + aWandererUpdateSaltF[((aIndex + 10U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 58U) + RotL64(aOrbiterG, 21U)) + aOrbiterB);
            aWandererG = aWandererG + ((RotL64(aPrevious, 35U) + aOrbiterI) + RotL64(aOrbiterJ, 5U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterA, 41U)) + aOrbiterC);
            aWandererA = aWandererA + ((((RotL64(aIngress, 19U) + aOrbiterH) + RotL64(aOrbiterA, 23U)) + RotL64(aCarry, 21U)) + RotL64(aNonceWordE, 3U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 38U) + aOrbiterC) + RotL64(aOrbiterB, 13U));
            aWandererB = aWandererB + ((RotL64(aIngress, 23U) + aOrbiterG) + RotL64(aOrbiterJ, 48U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterD, 37U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererC, 38U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererA, 53U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererI, 21U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererD, 57U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 30U) ^ RotL64(aNonceWordB, 57U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 22147U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 16564U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 3U) ^ RotL64(aNonceWordG, 54U)) ^ RotL64(aNonceWordA, 43U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18491U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 23006U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 43U) + RotL64(aCross, 5U)) ^ (RotL64(aIngress, 29U) ^ RotL64(aCarry, 56U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = ((aWandererK + RotL64(aIngress, 3U)) + RotL64(aCarry, 53U)) + 12131317914288566437U;
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 35U)) + RotL64(aCarry, 19U)) + 5672805657999385496U;
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 44U)) + RotL64(aCarry, 23U)) + 3581710244233124197U;
            aOrbiterC = (aWandererB + RotL64(aCross, 5U)) + 15251296040538489436U;
            aOrbiterA = (aWandererA + RotL64(aPrevious, 11U)) + 11295008604679904153U;
            aOrbiterK = ((aWandererG + RotL64(aScatter, 19U)) + 2230897493419504490U) + RotL64(aNonceWordC, 7U);
            aOrbiterF = (aWandererC + RotL64(aCross, 38U)) + 7109600123297458999U;
            aOrbiterD = (aWandererH + RotL64(aIngress, 41U)) + 13119156643107683803U;
            aOrbiterE = ((aWandererF + RotL64(aScatter, 57U)) + 14755160867807355250U) + aOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 27U)) + 16829363373287496832U) + aOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = ((aWandererI + RotL64(aCross, 47U)) + 16981122946707720883U) + RotL64(aNonceWordD, 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 8806000776958603317U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 16810923047720876014U) ^ RotL64(aNonceWordB, 55U);
            aOrbiterH = RotL64((aOrbiterH * 17872735050219539145U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 8129657889554436328U) + aOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 8653100378491974463U;
            aOrbiterK = RotL64((aOrbiterK * 11395283153912468661U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 17048985838727432415U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 10892675550889823573U;
            aOrbiterB = RotL64((aOrbiterB * 976298937314081913U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 15960158965421254346U) + aOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 12290011578634850001U;
            aOrbiterA = RotL64((aOrbiterA * 9280475585104357745U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 16265047040311479093U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterI) ^ 10312956912303656248U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]) ^ RotL64(aNonceWordE, 49U);
            aOrbiterD = RotL64((aOrbiterD * 3012584393253845131U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 16706890352221352779U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 10630955894218491929U;
            aOrbiterJ = RotL64((aOrbiterJ * 12675937483456206355U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 4009352551041162434U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 3043810773683888556U;
            aOrbiterG = RotL64((aOrbiterG * 4328135390387997315U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 1398071019814944785U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 16689766557488135301U;
            aOrbiterC = RotL64((aOrbiterC * 8403881916549404871U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 15934647144489136524U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 13521276033614992223U;
            aOrbiterF = RotL64((aOrbiterF * 18003640895553609933U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 4281211055727414100U) + aOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 11848150507497406421U;
            aOrbiterE = RotL64((aOrbiterE * 1107789990317433481U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 12022829841608199449U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 12131317914288566437U;
            aOrbiterI = RotL64((aOrbiterI * 13275753083882829973U), 29U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterB, 57U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 35U));
            aIngress = aIngress + (RotL64(aOrbiterE, 11U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterC, 40U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterK, 29U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterD, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aScatter, 37U) + aOrbiterG) + RotL64(aOrbiterI, 21U));
            aWandererA = aWandererA + ((RotL64(aCross, 12U) + aOrbiterC) + RotL64(aOrbiterD, 50U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 57U) + aOrbiterK) + RotL64(aOrbiterH, 23U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 3U) + aOrbiterK) + RotL64(aOrbiterJ, 39U)) + RotL64(aCarry, 39U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterH, 27U)) + aOrbiterA);
            aWandererH = aWandererH + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterA, 19U)) + aOrbiterD);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 26U) + aOrbiterB) + RotL64(aOrbiterA, 56U));
            aWandererD = aWandererD + (((RotL64(aCross, 23U) + aOrbiterK) + RotL64(aOrbiterE, 13U)) + aWandererUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((((RotL64(aIngress, 43U) + RotL64(aOrbiterB, 47U)) + aOrbiterG) + RotL64(aNonceWordA, 10U)) + aWandererUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aCross, 19U) + aOrbiterF) + RotL64(aOrbiterK, 5U)) + RotL64(aCarry, 35U)) + RotL64(aNonceWordH, 21U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterK, 35U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 10U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 53U));
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 60U));
            aCarry = aCarry + RotL64(aWandererF, 13U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 21U) ^ RotL64(aNonceWordG, 51U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 26244U)) & S_BLOCK1], 30U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32264U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 34U) ^ RotL64(aNonceWordH, 11U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 30147U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 29839U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 3U) ^ RotL64(aIngress, 47U)) + (RotL64(aCarry, 34U) + RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 11U)) + 9133751643283278896U) + RotL64(aNonceWordG, 39U);
            aOrbiterG = (((aWandererA + RotL64(aScatter, 5U)) + 8971581804375380408U) + aOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1]) + RotL64(aNonceWordE, 50U);
            aOrbiterI = (aWandererH + RotL64(aCross, 53U)) + 12559650383714566592U;
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 3U)) + RotL64(aCarry, 29U)) + 15753206088872859163U;
            aOrbiterH = ((aWandererI + RotL64(aCross, 26U)) + 7640756270450762350U) + aOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = ((aWandererK + RotL64(aScatter, 19U)) + RotL64(aCarry, 3U)) + 7340073357551376125U;
            aOrbiterA = (aWandererD + RotL64(aPrevious, 51U)) + 5270256573644196046U;
            aOrbiterE = (aWandererJ + RotL64(aIngress, 47U)) + 3567367996479995928U;
            aOrbiterB = (aWandererE + RotL64(aCross, 57U)) + 11939634537492733738U;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 36U)) + RotL64(aCarry, 11U)) + 7051817732424527120U;
            aOrbiterC = (aWandererG + RotL64(aIngress, 29U)) + 1730487669951837941U;
            //
            aOrbiterK = (((aOrbiterK + aOrbiterG) + 18009252467909454817U) + aOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1]) + RotL64(aNonceWordF, 53U);
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 2361024272031696442U;
            aOrbiterI = RotL64((aOrbiterI * 15215151562500226027U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 15902755877642960397U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 12243517544704116184U;
            aOrbiterH = RotL64((aOrbiterH * 2576071074148141447U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 16846181962302186187U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 636121425116506681U;
            aOrbiterF = RotL64((aOrbiterF * 17075030673338779993U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 6887385655828217318U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 3705834550934775862U) ^ RotL64(aNonceWordC, 21U);
            aOrbiterA = RotL64((aOrbiterA * 11275428284929594435U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 11165142437077969438U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 6426659930331618269U;
            aOrbiterE = RotL64((aOrbiterE * 17170640810530893705U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 12629082390899315789U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 4277510580069574724U;
            aOrbiterB = RotL64((aOrbiterB * 9829125163412708305U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 13814834144170469978U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 3698381854100295826U;
            aOrbiterD = RotL64((aOrbiterD * 5126359230872258015U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 11623170635983579937U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 7247413650388803796U;
            aOrbiterC = RotL64((aOrbiterC * 3403219499465560059U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 3129755194359521145U) + aOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 4081016725582134919U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11564414998539605389U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 15878346077922215753U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 2974440187796944059U;
            aOrbiterG = RotL64((aOrbiterG * 783253926537018373U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 3922344163443096356U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 9133751643283278896U;
            aOrbiterJ = RotL64((aOrbiterJ * 16887991698415418429U), 37U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterI, 43U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 50U));
            aIngress = aIngress + (RotL64(aOrbiterA, 35U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 37U));
            aIngress = aIngress + (RotL64(aOrbiterD, 41U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterC, 6U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 56U) + RotL64(aOrbiterK, 13U)) + aOrbiterE);
            aWandererI = aWandererI + (((RotL64(aScatter, 37U) + aOrbiterD) + RotL64(aOrbiterF, 29U)) + aWandererUpdateSaltC[((aIndex + 22U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterK, 43U)) + aOrbiterI);
            aWandererF = aWandererF + (((RotL64(aIngress, 39U) + aOrbiterC) + RotL64(aOrbiterH, 11U)) + RotL64(aCarry, 13U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 19U) + aOrbiterJ) + RotL64(aOrbiterB, 3U)) + RotL64(aNonceWordB, 37U));
            aWandererK = aWandererK + (((RotL64(aScatter, 27U) + aOrbiterF) + RotL64(aOrbiterH, 58U)) + RotL64(aCarry, 57U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 51U) + aOrbiterH) + RotL64(aOrbiterD, 37U));
            aWandererA = aWandererA + ((RotL64(aIngress, 21U) + aOrbiterG) + RotL64(aOrbiterA, 53U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 35U) + aOrbiterA) + RotL64(aOrbiterJ, 39U)) + aWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 4U) + aOrbiterJ) + RotL64(aOrbiterI, 24U)) + RotL64(aNonceWordD, 13U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterB, 5U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 51U));
            aCarry = aCarry + (RotL64(aWandererE, 18U) ^ aWandererJ);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 53U));
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererF, 23U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xCB19A567EF405429ULL + 0xF5B2C8805EDD2B91ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xAD19D2E718524F79ULL + 0xBDFEAFDFC1BC6448ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xBA10CD201D0DA785ULL + 0xBF58593F5E8989C7ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x92EBD05A558ECA51ULL + 0xB1E8E88F31781EECULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xD801EAECA72E0EBDULL + 0xFAEB51793AB100C9ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xB8DA28A331526A7BULL + 0xD887223747E944E3ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xFDC9E79A1F6206AFULL + 0xD8ECA018F29CBDF9ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xBBE518BAFC26F81BULL + 0xB8236554A05BC87EULL);
    std::uint64_t aDomainWordIngress = pConstants->mIngress;
    std::uint64_t aDomainWordScatter = pConstants->mScatter;
    std::uint64_t aDomainWordCross = pConstants->mCross;
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 43U) ^ RotL64(aNonceWordG, 27U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 5089U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneC[((aIndex + 1452U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 37U) ^ RotL64(aNonceWordB, 11U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 216U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 4080U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 50U) ^ RotL64(aIngress, 37U)) + (RotL64(aPrevious, 19U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 30U)) + RotL64(aCarry, 37U)) + 2558105147674438050U;
            aOrbiterA = ((aWandererE + RotL64(aCross, 35U)) + RotL64(aCarry, 47U)) + 15856662514774702561U;
            aOrbiterE = ((aWandererK + RotL64(aIngress, 47U)) + 13346869226246584582U) + RotL64(aNonceWordE, 55U);
            aOrbiterI = ((aWandererH + RotL64(aScatter, 39U)) + RotL64(aCarry, 29U)) + 7632111846116243973U;
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 5U)) + 2102101361626976279U) + aOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = ((aWandererF + RotL64(aScatter, 20U)) + 5605968705067851563U) + RotL64(aNonceWordF, 61U);
            aOrbiterD = ((aWandererA + RotL64(aCross, 51U)) + 6842483186584326681U) + aOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = (aWandererC + RotL64(aPrevious, 43U)) + 5559797213819425064U;
            aOrbiterB = (aWandererD + RotL64(aCross, 13U)) + 12422313931331576759U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 2751024420047872601U) + RotL64(aNonceWordC, 3U);
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 11031320239359798610U) ^ aOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8607639453141148025U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 14366375309473793217U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 11971479429768505316U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10063001532313098203U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 3947595951884469542U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 17882767922372770896U;
            aOrbiterF = RotL64((aOrbiterF * 3361906348965810211U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 513871456983509223U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterA) ^ 5951677013597794294U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]) ^ RotL64(aNonceWordG, 37U);
            aOrbiterB = RotL64((aOrbiterB * 8508629569649935293U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 437626309049021931U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 466674061172005705U;
            aOrbiterC = RotL64((aOrbiterC * 1310502572084891157U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 12362602809233133718U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 10525852878882195702U;
            aOrbiterI = RotL64((aOrbiterI * 17755022180514914325U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 17927000184308583095U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 566723721423470052U;
            aOrbiterD = RotL64((aOrbiterD * 17710534355278632573U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 9504585484034413577U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 4614306037721859929U;
            aOrbiterA = RotL64((aOrbiterA * 170807293799483539U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 1463218357720031588U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 4036696102163560633U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15389914226155130065U), 47U);
            //
            aIngress = RotL64(aOrbiterC, 14U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 51U));
            aIngress = aIngress + (RotL64(aOrbiterG, 19U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterF, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterK, 19U)) + aOrbiterE);
            aWandererK = aWandererK + ((RotL64(aCross, 34U) + RotL64(aOrbiterG, 3U)) + aOrbiterC);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 43U) + aOrbiterK) + RotL64(aOrbiterF, 43U));
            aWandererA = aWandererA + (((RotL64(aIngress, 29U) + aOrbiterD) + RotL64(aOrbiterB, 34U)) + RotL64(aCarry, 3U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 39U) + aOrbiterF) + RotL64(aOrbiterI, 47U));
            aWandererB = aWandererB + (((RotL64(aCross, 53U) + RotL64(aOrbiterB, 29U)) + aOrbiterA) + aWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterD, 51U)) + aOrbiterE);
            aWandererE = aWandererE + (((((RotL64(aPrevious, 18U) + aOrbiterA) + RotL64(aOrbiterF, 60U)) + RotL64(aCarry, 35U)) + RotL64(aNonceWordB, 25U)) + aWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 23U) + aOrbiterF) + RotL64(aOrbiterG, 23U)) + RotL64(aNonceWordA, 60U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 4U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 41U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererH, 27U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 30U) ^ RotL64(aNonceWordA, 3U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9700U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneD[((aIndex + 6907U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 43U) ^ RotL64(aNonceWordB, 14U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 6335U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 8632U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCarry, 21U)) + (RotL64(aPrevious, 51U) + RotL64(aCross, 36U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (((aWandererI + RotL64(aScatter, 48U)) + RotL64(aCarry, 13U)) + 16462052553719977502U) + aOrbiterAssignSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = ((aWandererA + RotL64(aCross, 5U)) + 12337064059566619581U) + RotL64(aNonceWordG, 27U);
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 53U)) + RotL64(aCarry, 5U)) + 15801005007094515447U;
            aOrbiterK = (aWandererH + RotL64(aIngress, 43U)) + 8228706742665081656U;
            aOrbiterF = (aWandererG + RotL64(aPrevious, 35U)) + 11006723027845190869U;
            aOrbiterE = ((aWandererB + RotL64(aScatter, 23U)) + 18173765337829177450U) + aOrbiterAssignSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterI = ((aWandererC + RotL64(aIngress, 13U)) + 530215083653542558U) + RotL64(aNonceWordH, 35U);
            aOrbiterB = ((aWandererD + RotL64(aCross, 29U)) + RotL64(aCarry, 21U)) + 6608611827035564511U;
            aOrbiterH = (aWandererE + RotL64(aIngress, 18U)) + 2246051826221626809U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 5228575308895381421U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 10999213210689606857U) ^ aOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5467601259546342925U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 3773371037240485696U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 8887985779436152504U;
            aOrbiterF = RotL64((aOrbiterF * 698713082830739677U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 11150566414723818350U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 8336366151003049546U) ^ RotL64(aNonceWordD, 9U);
            aOrbiterI = RotL64((aOrbiterI * 9033771197242493699U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 13233968794237090787U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 8172558473508478819U;
            aOrbiterB = RotL64((aOrbiterB * 17837070423649268435U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 133564480283347997U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 15104810248883567064U;
            aOrbiterH = RotL64((aOrbiterH * 706802420642303533U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 9138629520201127075U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 13993086066341664080U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4875046427147105077U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 6547273508580516932U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 9838727018769865759U) ^ RotL64(aNonceWordE, 7U);
            aOrbiterK = RotL64((aOrbiterK * 11395273371936839815U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 11685694999526122626U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 8945983172566303116U;
            aOrbiterE = RotL64((aOrbiterE * 17791527981004597623U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 17606249889617356327U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 9296903152000480008U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 18066622289408024413U), 57U);
            //
            aIngress = RotL64(aOrbiterF, 3U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 47U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 22U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 13U));
            aIngress = aIngress + RotL64(aOrbiterI, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 13U) + aOrbiterK) + RotL64(aOrbiterC, 39U));
            aWandererE = aWandererE + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterK, 28U)) + aOrbiterB) + RotL64(aNonceWordA, 52U)) + aWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterE, 57U)) + aOrbiterI);
            aWandererA = aWandererA + ((RotL64(aCross, 18U) + RotL64(aOrbiterI, 35U)) + aOrbiterB);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 23U) + aOrbiterB) + RotL64(aOrbiterF, 5U)) + RotL64(aNonceWordB, 43U));
            aWandererH = aWandererH + (((RotL64(aCross, 29U) + RotL64(aOrbiterE, 52U)) + aOrbiterH) + RotL64(aCarry, 35U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterC, 11U)) + aOrbiterI);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterG, 21U)) + aOrbiterJ) + RotL64(aCarry, 23U)) + aWandererUpdateSaltD[((aIndex + 8U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 40U) + RotL64(aOrbiterH, 43U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + (RotL64(aWandererI, 12U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererD, 53U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 43U) ^ RotL64(aNonceWordH, 35U)) ^ RotL64(aNonceWordE, 57U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 13141U)) & S_BLOCK1], 26U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14356U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 51U) ^ RotL64(aNonceWordC, 3U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 11345U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 12818U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 14U) + RotL64(aCarry, 57U)) ^ (RotL64(aCross, 27U) + RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (aWandererG + RotL64(aIngress, 35U)) + 4773124477323378268U;
            aOrbiterH = ((aWandererC + RotL64(aCross, 19U)) + RotL64(aCarry, 51U)) + 16848723289435796005U;
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 11U)) + 13846642134917107058U;
            aOrbiterA = (aWandererE + RotL64(aScatter, 39U)) + 6472057872482789939U;
            aOrbiterG = (aWandererD + RotL64(aCross, 52U)) + 2747019500690707226U;
            aOrbiterB = ((aWandererI + RotL64(aIngress, 47U)) + RotL64(aCarry, 5U)) + 9003965289739733880U;
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 43U)) + 3013390651936257377U;
            aOrbiterE = ((((aWandererA + RotL64(aScatter, 5U)) + RotL64(aCarry, 13U)) + 3331004709895625067U) + aOrbiterAssignSaltD[((aIndex + 10U)) & S_SALT1]) + RotL64(aNonceWordB, 45U);
            aOrbiterD = (((aWandererF + RotL64(aPrevious, 56U)) + 15355010435553517129U) + aOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1]) + RotL64(aNonceWordG, 59U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 7709870658004280052U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 13568728443963926564U;
            aOrbiterI = RotL64((aOrbiterI * 6736090830113688981U), 23U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterG) + 12409548853419307131U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]) + RotL64(aNonceWordD, 18U);
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 969183352023661537U;
            aOrbiterC = RotL64((aOrbiterC * 5549220554838837145U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 15370309834426476775U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 3896803894396631184U) ^ RotL64(aNonceWordA, 15U);
            aOrbiterA = RotL64((aOrbiterA * 11018830202891911603U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 10848873633291935766U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 12885336509190543440U;
            aOrbiterH = RotL64((aOrbiterH * 1487357252619221365U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 8252290890093788010U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 9201553615601641350U;
            aOrbiterG = RotL64((aOrbiterG * 420321130559162915U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 14014209645503188472U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 4015071464301844550U) ^ aOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17444195018239904971U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 16173085647514027347U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 16916627014974363360U;
            aOrbiterJ = RotL64((aOrbiterJ * 7699587344277490953U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 1591680303404522110U) + aOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 16499606051269327916U;
            aOrbiterE = RotL64((aOrbiterE * 814405848002794813U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 6932673635509444619U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 8745681160108707944U;
            aOrbiterD = RotL64((aOrbiterD * 14565255558668084787U), 57U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterH, 18U);
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 51U));
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterB, 54U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 47U) + aOrbiterH) + RotL64(aOrbiterI, 58U)) + RotL64(aCarry, 43U)) + RotL64(aNonceWordH, 55U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 58U) + RotL64(aOrbiterI, 41U)) + aOrbiterA) + aWandererUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterC, 47U)) + aOrbiterD);
            aWandererG = aWandererG ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterD, 37U)) + aOrbiterA);
            aWandererD = aWandererD + ((((RotL64(aIngress, 51U) + RotL64(aOrbiterH, 19U)) + aOrbiterG) + RotL64(aCarry, 57U)) + aWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 38U) + RotL64(aOrbiterJ, 5U)) + aOrbiterD);
            aWandererE = aWandererE + ((RotL64(aScatter, 3U) + RotL64(aOrbiterJ, 14U)) + aOrbiterG);
            aWandererB = aWandererB ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterD, 29U)) + aOrbiterB);
            aWandererI = aWandererI + (((RotL64(aScatter, 11U) + aOrbiterG) + RotL64(aOrbiterE, 53U)) + RotL64(aNonceWordF, 37U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererD, 41U) ^ aWandererB);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + RotL64(aWandererE, 10U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordE, 3U) ^ RotL64(aNonceWordC, 36U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 16616U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((aIndex + 21662U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 5U) ^ RotL64(aNonceWordD, 20U)) ^ RotL64(aNonceWordG, 51U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17446U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 21071U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 52U) ^ RotL64(aCross, 23U)) ^ (RotL64(aCarry, 39U) + RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererA + RotL64(aIngress, 5U)) + 16189787374324972735U;
            aOrbiterG = (aWandererI + RotL64(aScatter, 12U)) + 17563763730956242224U;
            aOrbiterE = (aWandererJ + RotL64(aCross, 23U)) + 10572803498593789385U;
            aOrbiterK = (aWandererC + RotL64(aPrevious, 53U)) + 7713105232072974166U;
            aOrbiterH = ((aWandererG + RotL64(aCross, 47U)) + RotL64(aCarry, 41U)) + 10760839534772718139U;
            aOrbiterC = ((((aWandererK + RotL64(aScatter, 57U)) + RotL64(aCarry, 11U)) + 13397069448391230253U) + aOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1]) + RotL64(aNonceWordG, 7U);
            aOrbiterA = ((((aWandererB + RotL64(aIngress, 29U)) + RotL64(aCarry, 3U)) + 4569255679998375682U) + aOrbiterAssignSaltB[((aIndex + 6U)) & S_SALT1]) + RotL64(aNonceWordA, 51U);
            aOrbiterD = (aWandererF + RotL64(aPrevious, 37U)) + 9888769350817876949U;
            aOrbiterB = (aWandererE + RotL64(aCross, 42U)) + 11351796060878856300U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 18153775071965707204U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 1282846411145853435U;
            aOrbiterE = RotL64((aOrbiterE * 12294455920906257823U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 16457743979262460660U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 173493260775251032U;
            aOrbiterH = RotL64((aOrbiterH * 4935807229040883505U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 3927345926316409630U) + RotL64(aNonceWordB, 14U);
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 5158769729850853623U;
            aOrbiterA = RotL64((aOrbiterA * 2446452358663812945U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 12331351600010165154U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 3940794200348684050U;
            aOrbiterJ = RotL64((aOrbiterJ * 13248997263062075043U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 11248514843822945425U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 1391497323278226522U;
            aOrbiterK = RotL64((aOrbiterK * 8376841806072565005U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 13265623528678787307U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 2802033745265647317U;
            aOrbiterC = RotL64((aOrbiterC * 3437626962562016147U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 6938444301018051844U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 1086544666755559028U;
            aOrbiterD = RotL64((aOrbiterD * 16039728388882079889U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 16156443117365816536U) + aOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 3619942859562697142U;
            aOrbiterB = RotL64((aOrbiterB * 7589346043159112151U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 17681848914912743292U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterA) ^ 8848238631758130416U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]) ^ RotL64(aNonceWordD, 41U);
            aOrbiterG = RotL64((aOrbiterG * 810402256099500607U), 35U);
            //
            aIngress = RotL64(aOrbiterC, 53U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterG, 47U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterB, 19U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 35U));
            aIngress = aIngress + RotL64(aOrbiterE, 40U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterH, 19U)) + aOrbiterC) + RotL64(aNonceWordF, 17U));
            aWandererE = aWandererE + (((RotL64(aScatter, 3U) + aOrbiterJ) + RotL64(aOrbiterK, 47U)) + RotL64(aCarry, 3U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 56U) + RotL64(aOrbiterJ, 35U)) + aOrbiterD);
            aWandererI = aWandererI + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterD, 13U)) + aOrbiterH);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterA, 28U)) + aOrbiterD);
            aWandererA = aWandererA + ((RotL64(aScatter, 43U) + RotL64(aOrbiterJ, 39U)) + aOrbiterB);
            aWandererK = aWandererK ^ (((RotL64(aCross, 12U) + aOrbiterB) + RotL64(aOrbiterA, 5U)) + aWandererUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererC = aWandererC + (((((RotL64(aPrevious, 27U) + aOrbiterJ) + RotL64(aOrbiterG, 53U)) + RotL64(aCarry, 13U)) + RotL64(aNonceWordH, 13U)) + aWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 47U) + aOrbiterE) + RotL64(aOrbiterG, 58U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererI);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 34U));
            aCarry = aCarry + (RotL64(aWandererB, 13U) ^ aWandererF);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + RotL64(aWandererK, 27U);
            aCarry = aCarry + RotL64(aIngress, 54U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 3U) ^ RotL64(aNonceWordD, 43U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 23122U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneA[((aIndex + 26566U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 57U) ^ RotL64(aNonceWordC, 37U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 22032U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24065U)) & S_BLOCK1], 10U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 3U) ^ RotL64(aCross, 21U)) + (RotL64(aCarry, 35U) ^ RotL64(aIngress, 54U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = ((((aWandererI + RotL64(aIngress, 27U)) + RotL64(aCarry, 21U)) + 6521330037475130256U) + aOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1]) + RotL64(aNonceWordH, 5U);
            aOrbiterG = (((aWandererH + RotL64(aScatter, 39U)) + RotL64(aCarry, 3U)) + 12611880456055428940U) + aOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = ((aWandererB + RotL64(aCross, 60U)) + RotL64(aCarry, 47U)) + 12061611078130934708U;
            aOrbiterA = (aWandererC + RotL64(aPrevious, 47U)) + 1558112410801116984U;
            aOrbiterJ = ((aWandererK + RotL64(aIngress, 53U)) + 10509115227850160786U) + RotL64(aNonceWordD, 41U);
            aOrbiterK = (aWandererE + RotL64(aCross, 11U)) + 4045915960688792066U;
            aOrbiterH = (aWandererJ + RotL64(aScatter, 4U)) + 1196541286513243082U;
            aOrbiterD = (aWandererA + RotL64(aPrevious, 43U)) + 15564991032722373702U;
            aOrbiterI = (aWandererD + RotL64(aCross, 23U)) + 4897765238703641798U;
            //
            aOrbiterC = (((aOrbiterC + aOrbiterG) + 12327429514907752733U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]) + RotL64(aNonceWordG, 9U);
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 6189189797708711636U;
            aOrbiterF = RotL64((aOrbiterF * 9017615866338877651U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 6374267075282018852U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 1888758503831341439U;
            aOrbiterK = RotL64((aOrbiterK * 74387714918264257U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 14956857689299491800U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 14879361107223331957U;
            aOrbiterD = RotL64((aOrbiterD * 9166712966729591953U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 16086885494838105042U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 8069724185844303923U;
            aOrbiterI = RotL64((aOrbiterI * 8878470736758734353U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 10854345917959911439U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 7078313614360332089U;
            aOrbiterC = RotL64((aOrbiterC * 9864025732292844871U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 15083669236062255011U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 594879695916679116U;
            aOrbiterA = RotL64((aOrbiterA * 9852515479152735283U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 6721466068234534523U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 475816724162626782U) ^ aOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4799725182757588407U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 4341655358154605899U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 15477254302340298586U;
            aOrbiterG = RotL64((aOrbiterG * 13961520225881974201U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 10179091913200895775U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterI) ^ 6310490897546909571U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]) ^ RotL64(aNonceWordF, 27U);
            aOrbiterJ = RotL64((aOrbiterJ * 15080621088825477613U), 23U);
            //
            aIngress = RotL64(aOrbiterF, 35U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 13U));
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterA, 29U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterJ, 50U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterD, 58U)) + aOrbiterG);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterH, 3U)) + aOrbiterF);
            aWandererE = aWandererE + ((((RotL64(aScatter, 58U) + aOrbiterF) + RotL64(aOrbiterK, 39U)) + RotL64(aNonceWordB, 14U)) + aWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterF, 29U)) + aOrbiterA) + aWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 35U) + aOrbiterG) + RotL64(aOrbiterJ, 35U)) + RotL64(aCarry, 11U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 27U) + aOrbiterJ) + RotL64(aOrbiterI, 51U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 19U) + aOrbiterI) + RotL64(aOrbiterK, 47U)) + RotL64(aCarry, 53U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 52U) + aOrbiterK) + RotL64(aOrbiterG, 12U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 47U) + aOrbiterC) + RotL64(aOrbiterJ, 21U)) + RotL64(aNonceWordC, 55U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 44U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererH, 41U) ^ aWandererB);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + RotL64(aWandererI, 19U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 13U) ^ RotL64(aNonceWordB, 53U)) ^ RotL64(aNonceWordE, 44U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 29549U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29074U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 47U) ^ RotL64(aNonceWordD, 3U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29944U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((aIndex + 29186U)) & S_BLOCK1], 34U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 51U) + RotL64(aIngress, 20U)) ^ (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererG + RotL64(aCross, 57U)) + 17081642665820489793U) + RotL64(aNonceWordH, 45U);
            aOrbiterD = ((aWandererI + RotL64(aScatter, 35U)) + 14468854040067229623U) + aOrbiterAssignSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = (aWandererD + RotL64(aIngress, 18U)) + 2249450222593057429U;
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 13U)) + 14964389079511378664U) + aOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = ((aWandererA + RotL64(aScatter, 47U)) + RotL64(aCarry, 13U)) + 17003491054252360650U;
            aOrbiterG = ((aWandererK + RotL64(aCross, 5U)) + RotL64(aCarry, 41U)) + 12710882240582032588U;
            aOrbiterK = ((aWandererE + RotL64(aIngress, 22U)) + RotL64(aCarry, 27U)) + 9887078182156755359U;
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 51U)) + 7665284531810584704U) + RotL64(aNonceWordA, 59U);
            aOrbiterE = (aWandererJ + RotL64(aIngress, 43U)) + 7304284015511876717U;
            //
            aOrbiterI = (((aOrbiterI + aOrbiterD) + 5517927023543751734U) + aOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1]) + RotL64(aNonceWordC, 47U);
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 17704756310857362759U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15826832172923213591U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 11347400363019508578U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 11696395232760991243U;
            aOrbiterB = RotL64((aOrbiterB * 9725231749679442003U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 10875780291242873583U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 7808740614343437672U;
            aOrbiterK = RotL64((aOrbiterK * 8889516201913716283U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 3145390996141902032U) + RotL64(aNonceWordG, 22U);
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 16080636485642732615U;
            aOrbiterA = RotL64((aOrbiterA * 7445756373012217305U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 3929263288176983844U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 18210228766683996806U;
            aOrbiterE = RotL64((aOrbiterE * 13178080076505449091U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 13948962323541421431U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 3037683309790156893U;
            aOrbiterI = RotL64((aOrbiterI * 13406672352222636739U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 17827265198532699474U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 7270895262023504864U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13467417362477308167U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 6431243064980879185U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 6680205390976259885U) ^ aOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10421386694108590789U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 15910655919164357152U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 8046213498216027383U;
            aOrbiterD = RotL64((aOrbiterD * 18061867495824063553U), 13U);
            //
            aIngress = RotL64(aOrbiterG, 39U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + (RotL64(aOrbiterA, 43U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 6U));
            aIngress = aIngress + RotL64(aOrbiterK, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterI, 56U)) + aOrbiterB);
            aWandererI = aWandererI + ((RotL64(aPrevious, 43U) + aOrbiterK) + RotL64(aOrbiterD, 3U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 48U) + aOrbiterB) + RotL64(aOrbiterJ, 51U));
            aWandererK = aWandererK + (((((RotL64(aScatter, 35U) + RotL64(aOrbiterA, 21U)) + aOrbiterG) + RotL64(aCarry, 35U)) + RotL64(aNonceWordE, 61U)) + aWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterC, 47U)) + aOrbiterA);
            aWandererE = aWandererE + (((RotL64(aScatter, 39U) + RotL64(aOrbiterC, 60U)) + aOrbiterK) + aWandererUpdateSaltE[((aIndex + 18U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 22U) + aOrbiterA) + RotL64(aOrbiterD, 27U));
            aWandererB = aWandererB + ((((RotL64(aIngress, 29U) + RotL64(aOrbiterE, 43U)) + aOrbiterB) + RotL64(aCarry, 27U)) + RotL64(aNonceWordB, 13U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 57U) + aOrbiterJ) + RotL64(aOrbiterE, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 18U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 29U) ^ aWandererF);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + RotL64(aWandererB, 23U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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

void TwistExpander_Bowling_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x9AA4AA3ECAFF229DULL + 0xF6500A80D7EA2A32ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xEB9D62BA34E18AB1ULL + 0x952A48418BEB903AULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xFAA5A6A4D11F8E9DULL + 0xE26A5DC6636C1D21ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xDFE24873DF17AFDBULL + 0x8B02A05FCF8AFE0AULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xDADC9CE4416EFD57ULL + 0x80DA682E0166E24BULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xFC42EE5D0AFDB913ULL + 0x8EDA7310F587326CULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xA0EC0A89D12358E9ULL + 0xB0505A23273F12F8ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xAB0AFF05435E3BD9ULL + 0xAE4D93FE81C1F1CCULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 51U) ^ RotL64(aNonceWordD, 5U)) ^ RotL64(aNonceWordF, 18U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 2776U)) & S_BLOCK1], 29U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 9U)) & W_KEY1], 39U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 27U) ^ RotL64(aNonceWordH, 13U)) ^ RotL64(aNonceWordA, 46U));
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 461U)) & W_KEY1], 37U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 483U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aPrevious, 5U)) ^ (RotL64(aCarry, 36U) ^ RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterI = ((((aWandererD + RotL64(aIngress, 29U)) + RotL64(aCarry, 43U)) + 9023059520606551446U) + aPhaseAOrbiterAssignSaltF[((aIndex + 28U)) & S_SALT1]) + RotL64(aNonceWordF, 3U);
            aOrbiterK = (aWandererF + RotL64(aPrevious, 3U)) + 662441755115638133U;
            aOrbiterE = ((aWandererA + RotL64(aScatter, 57U)) + 16957253361196144712U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = (((aWandererB + RotL64(aCross, 41U)) + RotL64(aCarry, 57U)) + 7840955025765308605U) + RotL64(aNonceWordD, 45U);
            aOrbiterF = ((aWandererG + RotL64(aScatter, 50U)) + RotL64(aCarry, 29U)) + 346855809270395799U;
            aOrbiterC = (aWandererI + RotL64(aPrevious, 35U)) + 16099139781586668343U;
            aOrbiterD = (aWandererC + RotL64(aCross, 19U)) + 3706457327118322098U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 12166825885547622870U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 7792658665720344200U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16305542632794270697U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 7128477606152986326U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 11116533962780290084U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11993485572912492297U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 10443889548568288532U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 4402387036946561017U) ^ RotL64(aNonceWordE, 49U);
            aOrbiterC = RotL64((aOrbiterC * 9032964741841833277U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 13002706161178447654U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 13929727277530310708U;
            aOrbiterD = RotL64((aOrbiterD * 7005639090871200285U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 10949073760696935106U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 15405923432006783533U) ^ RotL64(aNonceWordC, 38U);
            aOrbiterI = RotL64((aOrbiterI * 17989565878445202495U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 18096057968822208905U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 3032155040484574973U;
            aOrbiterH = RotL64((aOrbiterH * 448597307502544605U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 17462076466907467134U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 15471015427013701406U;
            aOrbiterK = RotL64((aOrbiterK * 6113474000571976139U), 57U);
            //
            aIngress = RotL64(aOrbiterF, 47U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterI, 11U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 53U));
            aIngress = aIngress + RotL64(aOrbiterK, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterF, 43U)) + aOrbiterK) + RotL64(aNonceWordH, 59U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 57U) + aOrbiterI) + RotL64(aOrbiterD, 51U));
            aWandererG = aWandererG + (((RotL64(aIngress, 41U) + RotL64(aOrbiterF, 58U)) + aOrbiterI) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 26U) + RotL64(aOrbiterD, 3U)) + aOrbiterH);
            aWandererI = aWandererI + (((RotL64(aCross, 19U) + RotL64(aOrbiterD, 35U)) + aOrbiterK) + RotL64(aCarry, 53U));
            aWandererB = aWandererB ^ ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterH, 29U)) + aOrbiterC) + RotL64(aNonceWordB, 53U)) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 13U) + RotL64(aOrbiterE, 23U)) + aOrbiterH) + aPhaseAWandererUpdateSaltD[((aIndex + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererF);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 41U));
            aCarry = aCarry + RotL64(aWandererB, 10U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 56U) ^ RotL64(aNonceWordG, 39U)) ^ RotL64(aNonceWordF, 21U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9940U)) & S_BLOCK1], 29U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 8615U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 21U) ^ RotL64(aNonceWordE, 11U)) ^ RotL64(aNonceWordH, 34U));
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 8579U)) & W_KEY1], 51U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 6933U)) & W_KEY1], 3U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 29U) ^ RotL64(aCarry, 57U)) + (RotL64(aIngress, 41U) + RotL64(aCross, 10U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterE = (aWandererG + RotL64(aScatter, 41U)) + 1557680213571812384U;
            aOrbiterH = (aWandererJ + RotL64(aCross, 35U)) + 7387349725778021121U;
            aOrbiterC = ((((aWandererF + RotL64(aIngress, 12U)) + RotL64(aCarry, 13U)) + 15379264067601586976U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1]) + RotL64(aNonceWordE, 26U);
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 27U)) + 3730195724576043708U) + RotL64(aNonceWordB, 17U);
            aOrbiterK = (((aWandererE + RotL64(aCross, 53U)) + RotL64(aCarry, 53U)) + 9637070085323827066U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = (aWandererB + RotL64(aPrevious, 5U)) + 1170865717363676184U;
            aOrbiterF = ((aWandererH + RotL64(aScatter, 21U)) + RotL64(aCarry, 41U)) + 2750833653175252030U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 15118992811225568305U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 4974092922102988451U) ^ RotL64(aNonceWordD, 29U);
            aOrbiterC = RotL64((aOrbiterC * 10575977398702460975U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 10625719096296719514U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 855167122475471865U;
            aOrbiterE = RotL64((aOrbiterE * 7441090331293158773U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 11322911068958340262U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 4334591909425429835U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10059025861172038183U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 14263701737208936392U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 678723206735649084U;
            aOrbiterH = RotL64((aOrbiterH * 10823239851733632227U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 15652053114252065230U) + RotL64(aNonceWordG, 35U);
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 1705225940224061401U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3626023093533713579U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 6826394665732900206U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 11902946775066981141U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 18300629262162694137U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 9802212958998591310U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 14001358545610206524U;
            aOrbiterF = RotL64((aOrbiterF * 13172645840788327099U), 51U);
            //
            aIngress = RotL64(aOrbiterF, 35U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 29U));
            aIngress = aIngress + RotL64(aOrbiterH, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aIngress, 37U) + RotL64(aOrbiterG, 60U)) + aOrbiterK) + RotL64(aNonceWordC, 45U));
            aWandererB = aWandererB + (((((RotL64(aCross, 51U) + aOrbiterC) + RotL64(aOrbiterB, 5U)) + RotL64(aCarry, 39U)) + RotL64(aNonceWordA, 37U)) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 43U) + aOrbiterC) + RotL64(aOrbiterE, 21U));
            aWandererE = aWandererE + ((((RotL64(aPrevious, 27U) + aOrbiterG) + RotL64(aOrbiterH, 47U)) + RotL64(aCarry, 53U)) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterE, 53U)) + aOrbiterF);
            aWandererH = aWandererH + ((RotL64(aScatter, 4U) + aOrbiterE) + RotL64(aOrbiterG, 27U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 13U) + aOrbiterK) + RotL64(aOrbiterB, 41U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 60U));
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererG);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + RotL64(aWandererF, 47U);
            aCarry = aCarry + RotL64(aIngress, 56U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordA, 27U) ^ RotL64(aNonceWordG, 5U)) ^ RotL64(aNonceWordB, 37U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 11851U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12239U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 39U) ^ RotL64(aNonceWordF, 3U));
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 12409U)) & W_KEY1], 58U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 11376U)) & W_KEY1], 23U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 10U) + RotL64(aPrevious, 41U)) + (RotL64(aCross, 29U) ^ RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterA = (aWandererG + RotL64(aCross, 27U)) + 13854738573712660276U;
            aOrbiterC = (((aWandererJ + RotL64(aIngress, 41U)) + RotL64(aCarry, 43U)) + 16835460633412286294U) + aPhaseAOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = (((aWandererC + RotL64(aScatter, 5U)) + RotL64(aCarry, 57U)) + 6785859293758091931U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterD = (aWandererD + RotL64(aPrevious, 60U)) + 126317283127992659U;
            aOrbiterG = ((aWandererH + RotL64(aIngress, 11U)) + 7568963536291415413U) + RotL64(aNonceWordH, 16U);
            aOrbiterE = (((aWandererE + RotL64(aCross, 35U)) + RotL64(aCarry, 27U)) + 12294016745653004819U) + RotL64(aNonceWordA, 27U);
            aOrbiterI = (aWandererB + RotL64(aPrevious, 47U)) + 18269588932920281147U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 5872406424994751026U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 7764434758831474129U;
            aOrbiterK = RotL64((aOrbiterK * 3772146788188420071U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 4804168969415573371U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 959601763507651280U) ^ RotL64(aNonceWordF, 21U);
            aOrbiterC = RotL64((aOrbiterC * 4647396592804833217U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 9257644462479293048U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 14332699366894494579U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8829304078930625541U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 10487012596470786004U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 612729229562321440U;
            aOrbiterD = RotL64((aOrbiterD * 11380387280507726003U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 7845523921295625315U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = (((aOrbiterG ^ aOrbiterI) ^ 12742115479740024747U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1]) ^ RotL64(aNonceWordB, 19U);
            aOrbiterG = RotL64((aOrbiterG * 15578543510683986421U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 10294667720904610944U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 14369711143154904567U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13753005602288309379U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 10918344717497681894U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 18136794828308636957U;
            aOrbiterI = RotL64((aOrbiterI * 17899418637978002409U), 43U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterG, 35U);
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterA, 21U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterC, 58U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterK, 27U)) + aOrbiterD);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 11U) + RotL64(aOrbiterD, 6U)) + aOrbiterA) + RotL64(aCarry, 35U)) + RotL64(aNonceWordE, 13U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 37U) + RotL64(aOrbiterC, 13U)) + aOrbiterI) + aPhaseAWandererUpdateSaltE[((aIndex + 28U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 23U) + aOrbiterI) + RotL64(aOrbiterK, 21U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterE, 35U)) + aOrbiterD) + RotL64(aNonceWordD, 53U));
            aWandererB = aWandererB + ((((RotL64(aScatter, 30U) + aOrbiterG) + RotL64(aOrbiterI, 51U)) + RotL64(aCarry, 21U)) + aPhaseAWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 41U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 42U));
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererC, 27U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 47U) ^ RotL64(aNonceWordG, 39U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 20685U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20142U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 21U) ^ RotL64(aNonceWordF, 5U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19656U)) & S_BLOCK1], 37U) ^ RotL64(mSource[((aIndex + 19205U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 40U) + RotL64(aCarry, 5U)) ^ (RotL64(aIngress, 21U) + RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 57U)) + 5721224134332887360U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = ((aWandererK + RotL64(aScatter, 47U)) + RotL64(aCarry, 23U)) + 6892749729775049095U;
            aOrbiterF = (aWandererD + RotL64(aCross, 28U)) + 3884839462099556836U;
            aOrbiterA = (aWandererC + RotL64(aIngress, 11U)) + 4365431706830216193U;
            aOrbiterE = (((aWandererE + RotL64(aPrevious, 41U)) + RotL64(aCarry, 41U)) + 15501528746571578773U) + RotL64(aNonceWordF, 5U);
            aOrbiterI = (((aWandererH + RotL64(aCross, 19U)) + RotL64(aCarry, 57U)) + 4505911326320650606U) + aPhaseAOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = ((aWandererG + RotL64(aIngress, 3U)) + 1865129050927879580U) + RotL64(aNonceWordH, 55U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 2011737665969640369U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 611672935827062688U;
            aOrbiterF = RotL64((aOrbiterF * 12873671551304596619U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 663547038310431047U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 5468932264754299556U;
            aOrbiterI = RotL64((aOrbiterI * 11968657455484578525U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 17920294117231191705U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 486058453837528110U;
            aOrbiterH = RotL64((aOrbiterH * 8851102552244026737U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 2789178451938129313U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 420772587981211184U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17402987842294006667U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 16196774774442181825U) + RotL64(aNonceWordE, 9U);
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 16264169656793713547U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6900221986041638783U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 10207659833859860796U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 8593749091183323678U) ^ RotL64(aNonceWordD, 39U);
            aOrbiterA = RotL64((aOrbiterA * 10696776033512404927U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 7224922076047787384U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 15366267474865172373U;
            aOrbiterJ = RotL64((aOrbiterJ * 10134187073321814217U), 43U);
            //
            aIngress = RotL64(aOrbiterF, 48U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 5U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 29U));
            aIngress = aIngress + RotL64(aOrbiterI, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aIngress, 35U) + RotL64(aOrbiterD, 23U)) + aOrbiterJ) + RotL64(aCarry, 11U)) + RotL64(aNonceWordB, 22U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 47U) + aOrbiterA) + RotL64(aOrbiterH, 43U)) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aCross, 11U) + aOrbiterD) + RotL64(aOrbiterH, 37U)) + RotL64(aCarry, 57U)) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterF, 60U)) + aOrbiterE) + RotL64(aNonceWordC, 29U));
            aWandererC = aWandererC + ((RotL64(aCross, 4U) + RotL64(aOrbiterF, 29U)) + aOrbiterD);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterH, 3U)) + aOrbiterJ);
            aWandererD = aWandererD + ((RotL64(aPrevious, 41U) + aOrbiterJ) + RotL64(aOrbiterI, 11U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + (RotL64(aWandererD, 56U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererA, 35U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 11U) ^ RotL64(aNonceWordE, 30U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 25808U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22762U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 13U) ^ RotL64(aNonceWordG, 5U)) ^ RotL64(aNonceWordF, 37U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25642U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21998U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 43U) + RotL64(aCross, 11U)) ^ (RotL64(aPrevious, 26U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterH = (((aWandererE + RotL64(aCross, 47U)) + RotL64(aCarry, 53U)) + 2330952702412094686U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = (aWandererC + RotL64(aIngress, 5U)) + 7820188225935060799U;
            aOrbiterB = (aWandererG + RotL64(aPrevious, 11U)) + 9347644591709839145U;
            aOrbiterF = (aWandererA + RotL64(aScatter, 18U)) + 2288624878446846870U;
            aOrbiterG = ((aWandererK + RotL64(aCross, 35U)) + 9358977729492824128U) + RotL64(aNonceWordG, 21U);
            aOrbiterI = (((aWandererF + RotL64(aIngress, 41U)) + RotL64(aCarry, 3U)) + 1858511275052455039U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = (((aWandererD + RotL64(aPrevious, 27U)) + RotL64(aCarry, 29U)) + 13715478509322292552U) + RotL64(aNonceWordE, 12U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 16413396625604260455U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterH) ^ 17714322215518432705U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]) ^ RotL64(aNonceWordH, 23U);
            aOrbiterB = RotL64((aOrbiterB * 1904184102419934333U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 16188315436202861122U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 5564445841368207813U;
            aOrbiterH = RotL64((aOrbiterH * 14125834616162835983U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 13717068949900594673U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 14143659432287313765U;
            aOrbiterF = RotL64((aOrbiterF * 17281441046722262917U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 5729546141908425670U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 4297827922736712074U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13631630436759768885U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 829520109395163673U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 11547160328525174295U;
            aOrbiterG = RotL64((aOrbiterG * 4759690159673049775U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 2907177944512117206U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 11100346409065275671U) ^ RotL64(aNonceWordD, 13U);
            aOrbiterI = RotL64((aOrbiterI * 17927994356809011637U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 1344592529249949068U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 6470438516791143572U;
            aOrbiterC = RotL64((aOrbiterC * 13339390828725370475U), 3U);
            //
            aIngress = RotL64(aOrbiterF, 41U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 51U));
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterH, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((((RotL64(aIngress, 57U) + aOrbiterG) + RotL64(aOrbiterD, 43U)) + RotL64(aCarry, 53U)) + RotL64(aNonceWordA, 47U)) + aPhaseAWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterI, 51U)) + aOrbiterG);
            aWandererF = aWandererF + ((RotL64(aPrevious, 19U) + aOrbiterH) + RotL64(aOrbiterC, 35U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterB, 21U)) + aOrbiterC);
            aWandererA = aWandererA + (((RotL64(aPrevious, 26U) + RotL64(aOrbiterF, 13U)) + aOrbiterD) + RotL64(aCarry, 27U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 35U) + aOrbiterB) + RotL64(aOrbiterF, 29U)) + aPhaseAWandererUpdateSaltB[((aIndex + 10U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 43U) + aOrbiterI) + RotL64(aOrbiterB, 60U)) + RotL64(aNonceWordB, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererG);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + (RotL64(aWandererC, 6U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererF, 47U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 27U) ^ RotL64(aNonceWordA, 37U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 30213U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28570U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 13U) ^ RotL64(aNonceWordG, 48U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28867U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneB[((aIndex + 32194U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 37U) ^ RotL64(aIngress, 23U)) + (RotL64(aCross, 10U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterC = (((aWandererI + RotL64(aScatter, 21U)) + 10404808878585437255U) + aPhaseAOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1]) + RotL64(aNonceWordF, 40U);
            aOrbiterD = ((aWandererA + RotL64(aCross, 41U)) + RotL64(aCarry, 23U)) + 10587858736301591439U;
            aOrbiterH = (((aWandererC + RotL64(aPrevious, 29U)) + RotL64(aCarry, 47U)) + 1430530909801644435U) + aPhaseAOrbiterAssignSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = (((aWandererG + RotL64(aIngress, 5U)) + RotL64(aCarry, 5U)) + 9090938022430118902U) + RotL64(aNonceWordE, 29U);
            aOrbiterI = (aWandererJ + RotL64(aScatter, 11U)) + 12936604311751121235U;
            aOrbiterA = (aWandererE + RotL64(aCross, 56U)) + 1000583006020232032U;
            aOrbiterB = (aWandererD + RotL64(aPrevious, 35U)) + 12352532088997042232U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 16723410947058502564U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 16614089235313154270U) ^ RotL64(aNonceWordA, 19U);
            aOrbiterH = RotL64((aOrbiterH * 11530998303573027827U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 4245553025593349277U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 3353146318549477494U;
            aOrbiterI = RotL64((aOrbiterI * 14246377408238318091U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 5935727336135635196U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 10312187090293319667U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1395964500396711899U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 12192843181244744484U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 2542570124502586365U;
            aOrbiterB = RotL64((aOrbiterB * 17222847847573534963U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 3315472769469002444U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 17512858811783071174U) ^ RotL64(aNonceWordC, 53U);
            aOrbiterC = RotL64((aOrbiterC * 9070400454074283765U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 16633218007427888082U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 2502077714838858460U;
            aOrbiterE = RotL64((aOrbiterE * 970762420815997725U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 14792910273226469214U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 15739513291150783151U;
            aOrbiterD = RotL64((aOrbiterD * 11896279674116906915U), 21U);
            //
            aIngress = RotL64(aOrbiterH, 58U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterB, 35U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterC, 11U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterI, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 41U) + aOrbiterA) + RotL64(aOrbiterE, 13U)) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererD = aWandererD + (((((RotL64(aIngress, 35U) + RotL64(aOrbiterI, 21U)) + aOrbiterC) + RotL64(aCarry, 3U)) + RotL64(aNonceWordG, 23U)) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterB, 29U)) + aOrbiterH) + RotL64(aNonceWordD, 37U));
            aWandererA = aWandererA + (((RotL64(aScatter, 29U) + RotL64(aOrbiterH, 5U)) + aOrbiterA) + RotL64(aCarry, 47U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 13U) + aOrbiterC) + RotL64(aOrbiterH, 47U));
            aWandererC = aWandererC + ((RotL64(aIngress, 48U) + RotL64(aOrbiterA, 35U)) + aOrbiterD);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterD, 58U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererI, 60U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererA, 11U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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

void TwistExpander_Bowling_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xDEE1A2DBA9EF5075ULL + 0xB350C406A49D4A77ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xB78510CE2CA958E3ULL + 0xAE03B73E69058166ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xB212CC888C32D9EFULL + 0x899482B4DA21D2F1ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xDD0AF185A3776D89ULL + 0xED96D757C83A1748ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xD06E25C57ABA481BULL + 0x8561504F6F48269AULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xF255F0C379A1E50BULL + 0xD4DDD7C87231F86CULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xA7E52C3CAC0A9E5DULL + 0xDE2A906CC74E13A4ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xD50B893C8D889847ULL + 0xADC0E302262366EAULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 43U) ^ RotL64(aNonceWordA, 53U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 2153U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((aIndex + 3680U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 19U) ^ RotL64(aNonceWordD, 5U)) ^ RotL64(aNonceWordE, 43U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4728U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneA[((aIndex + 4125U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 36U) ^ RotL64(aIngress, 57U)) + (RotL64(aCarry, 21U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterG = (((aWandererI + RotL64(aPrevious, 12U)) + 3970829908171131502U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1]) + RotL64(aNonceWordA, 31U);
            aOrbiterF = ((aWandererH + RotL64(aCross, 51U)) + 7040283759419531991U) + RotL64(aNonceWordD, 59U);
            aOrbiterK = (((aWandererA + RotL64(aIngress, 39U)) + RotL64(aCarry, 35U)) + 11856292169397052901U) + aPhaseBOrbiterAssignSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterC = ((aWandererG + RotL64(aScatter, 3U)) + RotL64(aCarry, 51U)) + 819598588791819022U;
            aOrbiterJ = ((aWandererC + RotL64(aCross, 23U)) + RotL64(aCarry, 3U)) + 2176451710970866848U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 6454704928613390494U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 11792122387218053841U;
            aOrbiterK = RotL64((aOrbiterK * 17994898985794518565U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 9254780213489752211U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 16591812589999846482U;
            aOrbiterG = RotL64((aOrbiterG * 5425771603523423167U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 1471246223935074832U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 1424843083106386453U) ^ RotL64(aNonceWordB, 49U);
            aOrbiterC = RotL64((aOrbiterC * 15020536982657410783U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 1856469958050891629U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 6331743690452052712U;
            aOrbiterF = RotL64((aOrbiterF * 15327924647897459645U), 41U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterC) + 10351075711345476487U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1]) + RotL64(aNonceWordF, 23U);
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 9518585245330480185U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3792179827396760391U), 51U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterJ, 34U);
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aCross, 4U) + RotL64(aOrbiterG, 11U)) + aOrbiterC) + RotL64(aNonceWordH, 20U));
            aWandererG = aWandererG + (((((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterF, 57U)) + RotL64(aCarry, 3U)) + RotL64(aNonceWordG, 25U)) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterJ, 3U)) + aOrbiterF);
            aWandererI = aWandererI + (((RotL64(aIngress, 29U) + aOrbiterJ) + RotL64(aOrbiterK, 39U)) + RotL64(aCarry, 35U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 21U) + aOrbiterG) + RotL64(aOrbiterK, 20U)) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererH);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + RotL64(aWandererC, 3U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 5U) ^ RotL64(aNonceWordH, 27U)) ^ RotL64(aNonceWordC, 53U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10176U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 9531U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 19U) ^ RotL64(aNonceWordD, 56U)) ^ RotL64(aNonceWordA, 37U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7311U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((aIndex + 6547U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 41U) + RotL64(aPrevious, 11U)) ^ (RotL64(aCross, 26U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterJ = (((aWandererH + RotL64(aScatter, 37U)) + RotL64(aCarry, 23U)) + 7948891781097675369U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = ((aWandererI + RotL64(aCross, 53U)) + RotL64(aCarry, 11U)) + 13928362874228230226U;
            aOrbiterE = (((aWandererC + RotL64(aPrevious, 29U)) + 10776180542602258926U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 8U)) & S_SALT1]) + RotL64(aNonceWordF, 59U);
            aOrbiterF = (((aWandererF + RotL64(aIngress, 21U)) + RotL64(aCarry, 35U)) + 5735115172149470447U) + RotL64(aNonceWordG, 5U);
            aOrbiterG = (aWandererG + RotL64(aCross, 6U)) + 5353591822981766987U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 562301708107268570U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 10467810247578364868U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10449089554007059823U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 14541630141152308564U) + RotL64(aNonceWordH, 21U);
            aOrbiterG = (((aOrbiterG ^ aOrbiterI) ^ 2350076897065139429U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1]) ^ RotL64(aNonceWordE, 9U);
            aOrbiterG = RotL64((aOrbiterG * 12222554362482034393U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 17519109078651162228U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 6061035173339902910U;
            aOrbiterJ = RotL64((aOrbiterJ * 10021905773432907835U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 15654836633731000065U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 13723521735153718904U;
            aOrbiterI = RotL64((aOrbiterI * 14459516479283070563U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 2849680038315532197U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 17336102435576647923U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10984689101753586739U), 21U);
            //
            aIngress = RotL64(aOrbiterF, 13U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 57U));
            aIngress = aIngress + RotL64(aOrbiterE, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((((RotL64(aCross, 3U) + aOrbiterE) + RotL64(aOrbiterG, 3U)) + RotL64(aNonceWordB, 6U)) + aPhaseBWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterI, 12U)) + aOrbiterF) + RotL64(aCarry, 29U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 11U) + aOrbiterJ) + RotL64(aOrbiterF, 27U));
            aWandererI = aWandererI + ((((RotL64(aIngress, 53U) + RotL64(aOrbiterJ, 51U)) + aOrbiterI) + RotL64(aCarry, 13U)) + RotL64(aNonceWordC, 27U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 38U) + RotL64(aOrbiterF, 37U)) + aOrbiterE) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererG, 11U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 13U) ^ RotL64(aNonceWordA, 47U)) ^ RotL64(aNonceWordE, 29U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 15516U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13271U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 5U) ^ RotL64(aNonceWordG, 28U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 15116U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15628U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCross, 39U)) ^ (RotL64(aCarry, 18U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterC = ((aWandererC + RotL64(aCross, 3U)) + 7896237440058555694U) + RotL64(aNonceWordD, 51U);
            aOrbiterB = ((aWandererH + RotL64(aScatter, 38U)) + RotL64(aCarry, 47U)) + 11870529476037558635U;
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 11U)) + RotL64(aCarry, 3U)) + 9158983227801569448U;
            aOrbiterA = (((aWandererG + RotL64(aPrevious, 29U)) + RotL64(aCarry, 23U)) + 4710172270996950329U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = (((aWandererD + RotL64(aCross, 51U)) + 14634482800356647630U) + aPhaseBOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1]) + RotL64(aNonceWordB, 55U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 8822207952170610891U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 13755891414028982553U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5173750624716006485U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 4555293067488040719U) + RotL64(aNonceWordH, 35U);
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 2816805148093762081U;
            aOrbiterB = RotL64((aOrbiterB * 16838149138341713943U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 2122631477965135190U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 4592922416380416071U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11644507904538573165U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 7102471666524164715U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 17274623547879474204U;
            aOrbiterA = RotL64((aOrbiterA * 5443572270546181789U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 938587316977094680U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 18258015823797023523U) ^ RotL64(aNonceWordE, 5U);
            aOrbiterJ = RotL64((aOrbiterJ * 6068819567674605919U), 3U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterK, 35U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 24U));
            aIngress = aIngress + RotL64(aOrbiterC, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((((RotL64(aPrevious, 37U) + aOrbiterC) + RotL64(aOrbiterB, 27U)) + RotL64(aCarry, 37U)) + RotL64(aNonceWordF, 18U)) + aPhaseBWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 57U) + aOrbiterK) + RotL64(aOrbiterJ, 11U)) + RotL64(aNonceWordC, 19U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 3U) + aOrbiterA) + RotL64(aOrbiterC, 50U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 48U) + RotL64(aOrbiterC, 19U)) + aOrbiterK) + aPhaseBWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 23U) + RotL64(aOrbiterB, 37U)) + aOrbiterK) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 56U));
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererH, 19U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 27U) ^ RotL64(aNonceWordH, 14U)) ^ RotL64(aNonceWordD, 39U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 19217U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((aIndex + 17535U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 27U) ^ RotL64(aNonceWordB, 3U)) ^ RotL64(aNonceWordC, 43U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16651U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneD[((aIndex + 20659U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 29U) + RotL64(aIngress, 41U)) ^ (RotL64(aCross, 56U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterH = ((((aWandererC + RotL64(aScatter, 57U)) + RotL64(aCarry, 29U)) + 6024062041314952357U) + aPhaseBOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1]) + RotL64(aNonceWordE, 37U);
            aOrbiterI = (aWandererE + RotL64(aIngress, 35U)) + 18340757093658015585U;
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 11U)) + RotL64(aCarry, 57U)) + 11911120493880346751U;
            aOrbiterB = (((aWandererF + RotL64(aCross, 48U)) + RotL64(aCarry, 43U)) + 17428074353884654439U) + RotL64(aNonceWordF, 29U);
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 23U)) + 12790849760814795936U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 12633397052172117800U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 11946150433665237945U) ^ RotL64(aNonceWordC, 53U);
            aOrbiterK = RotL64((aOrbiterK * 10324089534873171291U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 16842157900909419285U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 14186235783224155962U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10521157787073684417U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 13284904542579767591U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 11609181965078844357U;
            aOrbiterB = RotL64((aOrbiterB * 5455780554452453513U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 9628562297095374984U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 7850281529011259759U;
            aOrbiterI = RotL64((aOrbiterI * 17611485102925470357U), 5U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterB) + 257458718073794527U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]) + RotL64(aNonceWordD, 12U);
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 10693404545773519306U;
            aOrbiterG = RotL64((aOrbiterG * 14821443722828498323U), 37U);
            //
            aIngress = RotL64(aOrbiterH, 47U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 37U));
            aIngress = aIngress + RotL64(aOrbiterI, 24U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aIngress, 11U) + RotL64(aOrbiterG, 28U)) + aOrbiterB);
            aWandererG = aWandererG ^ ((((RotL64(aPrevious, 56U) + RotL64(aOrbiterG, 11U)) + aOrbiterH) + RotL64(aNonceWordG, 57U)) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aCross, 47U) + aOrbiterK) + RotL64(aOrbiterI, 53U)) + RotL64(aCarry, 51U)) + aPhaseBWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 39U) + aOrbiterK) + RotL64(aOrbiterB, 19U));
            aWandererC = aWandererC + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterB, 37U)) + aOrbiterH) + RotL64(aCarry, 3U)) + RotL64(aNonceWordA, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 29U));
            aCarry = aCarry + RotL64(aWandererF, 39U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 18U) ^ RotL64(aNonceWordD, 29U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 26378U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 26171U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 23U) ^ RotL64(aNonceWordE, 13U)) ^ RotL64(aNonceWordC, 53U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 22605U)) & S_BLOCK1], 34U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25575U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 54U) ^ RotL64(aCross, 5U)) ^ (RotL64(aCarry, 23U) + RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterD = ((aWandererD + RotL64(aIngress, 39U)) + 8367680518550579791U) + RotL64(aNonceWordD, 15U);
            aOrbiterK = ((aWandererA + RotL64(aPrevious, 29U)) + 11491674725611181241U) + aPhaseBOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = (((aWandererB + RotL64(aScatter, 21U)) + RotL64(aCarry, 51U)) + 16673861720782164214U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = (((aWandererG + RotL64(aCross, 56U)) + RotL64(aCarry, 5U)) + 9786610124108350855U) + RotL64(aNonceWordA, 3U);
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 13U)) + RotL64(aCarry, 29U)) + 5745080601557577637U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 1959402215131684684U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 6121650036079196522U;
            aOrbiterG = RotL64((aOrbiterG * 13375345606276198671U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 12016309761037342392U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 5986936646177049603U;
            aOrbiterJ = RotL64((aOrbiterJ * 3585650475703294895U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 1000367700904043468U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 17425288243569101032U;
            aOrbiterD = RotL64((aOrbiterD * 2174614006719048535U), 5U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterJ) + 4856917474950325209U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]) + RotL64(aNonceWordE, 49U);
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 16312111093223166419U;
            aOrbiterK = RotL64((aOrbiterK * 11046477664487805241U), 47U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterD) + 456110002032422270U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1]) + RotL64(aNonceWordH, 21U);
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 11393724374787795662U;
            aOrbiterE = RotL64((aOrbiterE * 1176984359123668389U), 39U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterJ, 48U);
            aIngress = aIngress + (RotL64(aOrbiterK, 37U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterD, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aPrevious, 11U) + aOrbiterJ) + RotL64(aOrbiterD, 43U)) + RotL64(aNonceWordB, 40U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterJ, 35U)) + aOrbiterK) + aPhaseBWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 56U) + RotL64(aOrbiterK, 51U)) + aOrbiterE) + RotL64(aCarry, 39U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterJ, 23U)) + aOrbiterG) + RotL64(aNonceWordG, 41U));
            aWandererF = aWandererF + ((((RotL64(aPrevious, 27U) + aOrbiterG) + RotL64(aOrbiterE, 12U)) + RotL64(aCarry, 23U)) + aPhaseBWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererA, 57U);
            aCarry = aCarry + RotL64(aIngress, 44U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 13U) ^ RotL64(aNonceWordA, 5U)) ^ RotL64(aNonceWordG, 57U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 31456U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30232U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 5U) ^ RotL64(aNonceWordC, 13U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 31911U)) & S_BLOCK1], 36U) ^ RotL64(aWorkLaneB[((aIndex + 27677U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 19U) ^ RotL64(aCross, 5U)) + (RotL64(aCarry, 56U) ^ RotL64(aIngress, 43U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterJ = ((aWandererK + RotL64(aCross, 19U)) + RotL64(aCarry, 35U)) + 10805654776556844351U;
            aOrbiterD = ((aWandererC + RotL64(aScatter, 37U)) + 582794182442795335U) + aPhaseBOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = (((aWandererI + RotL64(aIngress, 11U)) + RotL64(aCarry, 47U)) + 2858343650974681068U) + RotL64(aNonceWordD, 38U);
            aOrbiterC = ((((aWandererG + RotL64(aPrevious, 27U)) + RotL64(aCarry, 19U)) + 8189584049022064284U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 18U)) & S_SALT1]) + RotL64(aNonceWordA, 41U);
            aOrbiterF = (aWandererD + RotL64(aIngress, 58U)) + 1565100751996962893U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 8062028016947611891U) + RotL64(aNonceWordE, 39U);
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 8280504280578451745U;
            aOrbiterI = RotL64((aOrbiterI * 5212851648135050483U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 11326869194491655350U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 1671695656567777163U;
            aOrbiterD = RotL64((aOrbiterD * 7511554500524257921U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 2349843105293943452U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 13015545152052004254U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1316662811685429983U), 39U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterF) + 16703354404749291869U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1]) + RotL64(aNonceWordF, 59U);
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 8713231044374305801U;
            aOrbiterC = RotL64((aOrbiterC * 9242480982197688625U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 11118401674497783533U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 14857556493734710364U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3452566050389715195U), 13U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterC, 19U);
            aIngress = aIngress + (RotL64(aOrbiterF, 35U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterJ, 58U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 23U) + aOrbiterI) + RotL64(aOrbiterJ, 48U));
            aWandererG = aWandererG + ((((RotL64(aCross, 3U) + aOrbiterD) + RotL64(aOrbiterC, 21U)) + RotL64(aCarry, 53U)) + RotL64(aNonceWordH, 5U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 14U) + RotL64(aOrbiterC, 57U)) + aOrbiterI);
            aWandererK = aWandererK + (((((RotL64(aIngress, 53U) + aOrbiterI) + RotL64(aOrbiterF, 13U)) + RotL64(aCarry, 11U)) + RotL64(aNonceWordB, 37U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 41U) + aOrbiterD) + RotL64(aOrbiterF, 39U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 21U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererI, 5U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererG, 51U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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

void TwistExpander_Bowling_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x9AFF96CDD112A7F5ULL + 0x81E101ECC2CB309EULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x94FDC3AB3CD6CCE9ULL + 0xA7ECD54691EE7D92ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xFEC02EC01216B609ULL + 0xC338D5CD2F275470ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xF2695F33005BC279ULL + 0xAA9A67717E2FBE52ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xC84F04F9EB02B455ULL + 0xC0023505ED4B54C1ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xB31E290B92285547ULL + 0x9BF62B95F70A4378ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xE5355953EDBBD475ULL + 0xCBE7E5471E8C3EFEULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xAE2F8A2A93C3A475ULL + 0xA6B75364F89B815DULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 35U) ^ RotL64(aNonceWordE, 47U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 1480U)) & S_BLOCK1], 26U) ^ RotL64(aOperationLaneC[((aIndex + 4491U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 19U) ^ RotL64(aNonceWordD, 27U)) ^ RotL64(aNonceWordA, 6U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 914U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneA[((aIndex + 2477U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 6U) ^ RotL64(aIngress, 39U)) ^ (RotL64(aPrevious, 19U) + RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 14U)) + 6163290588946759209U) + RotL64(aNonceWordB, 21U);
            aOrbiterD = (aWandererA + RotL64(aIngress, 19U)) + 7342672468560105447U;
            aOrbiterC = (((aWandererE + RotL64(aScatter, 3U)) + 11574563167017282321U) + aPhaseCOrbiterAssignSaltF[((aIndex + 18U)) & S_SALT1]) + RotL64(aNonceWordF, 5U);
            aOrbiterA = ((aWandererD + RotL64(aCross, 43U)) + 2254820206194758964U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterG = (aWandererB + RotL64(aPrevious, 35U)) + 1469783447473099498U;
            aOrbiterI = ((aWandererC + RotL64(aIngress, 56U)) + RotL64(aCarry, 53U)) + 14174828900676165088U;
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 23U)) + RotL64(aCarry, 29U)) + 16277954291890598132U;
            aOrbiterB = ((aWandererI + RotL64(aCross, 29U)) + RotL64(aCarry, 3U)) + 14845750668693136766U;
            aOrbiterE = (aWandererG + RotL64(aPrevious, 39U)) + 150099699692047766U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 1200784917165131703U) + RotL64(aNonceWordD, 36U);
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 9469982764806754302U) ^ RotL64(aNonceWordH, 31U);
            aOrbiterC = RotL64((aOrbiterC * 17851969334511301943U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 10956702761701710182U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 7915506894975487807U;
            aOrbiterI = RotL64((aOrbiterI * 8874108311712727983U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 17335794183733623213U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 557028996286989506U;
            aOrbiterB = RotL64((aOrbiterB * 3993359298602424281U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 1597385667771002414U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 4376417959915162639U;
            aOrbiterE = RotL64((aOrbiterE * 4626236858205178149U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 549770198518993876U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 756554555648070919U;
            aOrbiterH = RotL64((aOrbiterH * 16272320259614325355U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 7298557532533152193U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 3336802611342112013U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14679103452120080499U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 2314938232094714365U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 12215066333571149153U;
            aOrbiterJ = RotL64((aOrbiterJ * 10747052773052630601U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 7762752719356805046U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 6519429915769040078U;
            aOrbiterD = RotL64((aOrbiterD * 15548676502167938513U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 7556691736109752918U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 13731245903412646404U;
            aOrbiterG = RotL64((aOrbiterG * 15581965016668635409U), 19U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterI, 3U);
            aIngress = aIngress + (RotL64(aOrbiterD, 40U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 11U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 43U));
            aIngress = aIngress + RotL64(aOrbiterH, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 30U) + aOrbiterD) + RotL64(aOrbiterG, 58U));
            aWandererI = aWandererI + ((((RotL64(aIngress, 23U) + aOrbiterA) + RotL64(aOrbiterG, 5U)) + RotL64(aCarry, 5U)) + RotL64(aNonceWordE, 35U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 35U) + aOrbiterB) + RotL64(aOrbiterA, 41U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterA, 27U)) + aOrbiterJ) + RotL64(aCarry, 29U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterI, 21U)) + aOrbiterJ);
            aWandererG = aWandererG + (((RotL64(aPrevious, 47U) + aOrbiterJ) + RotL64(aOrbiterE, 47U)) + RotL64(aNonceWordC, 19U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterH, 35U)) + aOrbiterE) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 57U) + aOrbiterH) + RotL64(aOrbiterB, 10U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 12U) + RotL64(aOrbiterC, 51U)) + aOrbiterE) + aPhaseCWandererUpdateSaltD[((aIndex + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + (RotL64(aWandererG, 30U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererK, 47U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 39U) ^ RotL64(aNonceWordG, 53U)) ^ RotL64(aNonceWordA, 3U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 14469U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 8223U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 44U) ^ RotL64(aNonceWordB, 3U)) ^ RotL64(aNonceWordF, 35U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 12189U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 8684U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCross, 37U) ^ RotL64(aPrevious, 21U)) + (RotL64(aIngress, 56U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterK = (((aWandererC + RotL64(aCross, 23U)) + RotL64(aCarry, 57U)) + 16189787374324972735U) + RotL64(aNonceWordE, 41U);
            aOrbiterC = ((aWandererA + RotL64(aScatter, 6U)) + 17563763730956242224U) + RotL64(aNonceWordF, 9U);
            aOrbiterB = (aWandererJ + RotL64(aPrevious, 57U)) + 10572803498593789385U;
            aOrbiterG = (((aWandererG + RotL64(aIngress, 35U)) + RotL64(aCarry, 41U)) + 7713105232072974166U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = (aWandererB + RotL64(aCross, 19U)) + 10760839534772718139U;
            aOrbiterI = (((aWandererI + RotL64(aPrevious, 48U)) + RotL64(aCarry, 23U)) + 13397069448391230253U) + aPhaseCOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = (aWandererK + RotL64(aIngress, 43U)) + 4569255679998375682U;
            aOrbiterF = (aWandererE + RotL64(aScatter, 11U)) + 9888769350817876949U;
            aOrbiterD = (aWandererD + RotL64(aCross, 53U)) + 11351796060878856300U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 18153775071965707204U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 1282846411145853435U;
            aOrbiterB = RotL64((aOrbiterB * 12294455920906257823U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 16457743979262460660U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 173493260775251032U;
            aOrbiterE = RotL64((aOrbiterE * 4935807229040883505U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 3927345926316409630U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 5158769729850853623U;
            aOrbiterJ = RotL64((aOrbiterJ * 2446452358663812945U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 12331351600010165154U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 3940794200348684050U;
            aOrbiterF = RotL64((aOrbiterF * 13248997263062075043U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 11248514843822945425U) + RotL64(aNonceWordH, 23U);
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 1391497323278226522U) ^ RotL64(aNonceWordD, 17U);
            aOrbiterD = RotL64((aOrbiterD * 8376841806072565005U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 13265623528678787307U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 2802033745265647317U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3437626962562016147U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 6938444301018051844U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 1086544666755559028U;
            aOrbiterG = RotL64((aOrbiterG * 16039728388882079889U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 16156443117365816536U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 3619942859562697142U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7589346043159112151U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 17681848914912743292U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 8848238631758130416U;
            aOrbiterC = RotL64((aOrbiterC * 810402256099500607U), 13U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterE, 53U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 30U));
            aIngress = aIngress + (RotL64(aOrbiterC, 27U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterI, 11U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterK, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aCross, 26U) + aOrbiterI) + RotL64(aOrbiterK, 12U)) + RotL64(aCarry, 11U)) + aPhaseCWandererUpdateSaltC[((aIndex + 20U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 5U) + aOrbiterD) + RotL64(aOrbiterE, 19U));
            aWandererE = aWandererE + ((RotL64(aIngress, 47U) + RotL64(aOrbiterC, 43U)) + aOrbiterJ);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 19U) + aOrbiterJ) + RotL64(aOrbiterB, 5U));
            aWandererG = aWandererG + ((RotL64(aCross, 43U) + RotL64(aOrbiterG, 51U)) + aOrbiterF);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterI, 39U)) + aOrbiterF) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aIngress, 51U) + RotL64(aOrbiterF, 26U)) + aOrbiterK) + RotL64(aCarry, 21U)) + RotL64(aNonceWordG, 37U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 39U) + aOrbiterJ) + RotL64(aOrbiterD, 35U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 60U) + RotL64(aOrbiterB, 57U)) + aOrbiterK) + RotL64(aNonceWordC, 30U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 52U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererI, 21U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 57U) ^ RotL64(aNonceWordB, 44U)) ^ RotL64(aNonceWordF, 21U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 22302U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((aIndex + 22673U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 30U) ^ RotL64(aNonceWordA, 21U)) ^ RotL64(aNonceWordH, 39U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 16551U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneC[((aIndex + 24076U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 29U) ^ RotL64(aCarry, 44U)) + (RotL64(aIngress, 5U) + RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterA = ((aWandererI + RotL64(aScatter, 39U)) + 2672739400294801233U) + aPhaseCOrbiterAssignSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 34U)) + RotL64(aCarry, 39U)) + 8475624545015101850U;
            aOrbiterF = (aWandererK + RotL64(aCross, 21U)) + 1252755112289831257U;
            aOrbiterB = ((aWandererA + RotL64(aIngress, 3U)) + RotL64(aCarry, 21U)) + 7938039507649183387U;
            aOrbiterC = ((aWandererE + RotL64(aCross, 11U)) + RotL64(aCarry, 57U)) + 8167413146948861022U;
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 51U)) + 17712313989694374353U) + RotL64(aNonceWordF, 17U);
            aOrbiterK = (aWandererF + RotL64(aIngress, 57U)) + 7637042279892596975U;
            aOrbiterG = (((aWandererB + RotL64(aScatter, 28U)) + 15770412950033467341U) + aPhaseCOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1]) + RotL64(aNonceWordA, 19U);
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 47U)) + 3951812021898608685U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 8656983621098246507U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 17943342344730687317U;
            aOrbiterF = RotL64((aOrbiterF * 16495519451034883813U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 3087677463651608668U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 16493240011924342788U;
            aOrbiterA = RotL64((aOrbiterA * 16898479041530771871U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 7750923317452683057U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 2185924841611106546U;
            aOrbiterB = RotL64((aOrbiterB * 708072658250726381U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 14676868738946722416U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 6849098251696302393U;
            aOrbiterE = RotL64((aOrbiterE * 2599806275837778069U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 17817755047153606419U) + RotL64(aNonceWordE, 25U);
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 9900465270314068757U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9267925873983176685U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 11380000891112113701U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 15930503831156546113U) ^ RotL64(aNonceWordG, 56U);
            aOrbiterJ = RotL64((aOrbiterJ * 14450535035065393845U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 5439183530402949780U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 3731802052051181843U;
            aOrbiterK = RotL64((aOrbiterK * 7739775058947333169U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 14432344583247783600U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 16192098795467501636U;
            aOrbiterG = RotL64((aOrbiterG * 6285466374319549047U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 1523272672673940290U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 7462092373525113574U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15067751170235540679U), 39U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterK, 18U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 37U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + RotL64(aOrbiterA, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aIngress, 19U) + aOrbiterJ) + RotL64(aOrbiterK, 37U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterI, 28U)) + aOrbiterK);
            aWandererI = aWandererI + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterB, 23U)) + aOrbiterI) + RotL64(aCarry, 21U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 48U) + RotL64(aOrbiterB, 41U)) + aOrbiterF);
            aWandererE = aWandererE + (((RotL64(aScatter, 11U) + RotL64(aOrbiterA, 5U)) + aOrbiterE) + RotL64(aCarry, 47U));
            aWandererJ = aWandererJ ^ ((((RotL64(aCross, 57U) + RotL64(aOrbiterG, 57U)) + aOrbiterC) + RotL64(aNonceWordC, 45U)) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 23U) + aOrbiterF) + RotL64(aOrbiterG, 47U)) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 6U) + aOrbiterI) + RotL64(aOrbiterA, 12U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 27U) + aOrbiterF) + RotL64(aOrbiterA, 19U)) + RotL64(aNonceWordD, 51U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 41U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 54U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + RotL64(aWandererB, 23U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 58U) ^ RotL64(aNonceWordG, 43U)) ^ RotL64(aNonceWordC, 11U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 30129U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27629U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 40U) ^ RotL64(aNonceWordD, 19U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 32701U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 26596U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 38U) + RotL64(aPrevious, 23U)) ^ (RotL64(aCross, 57U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterJ = ((aWandererB + RotL64(aCross, 29U)) + RotL64(aCarry, 27U)) + 7722279280863371124U;
            aOrbiterG = (aWandererA + RotL64(aIngress, 21U)) + 11584220561732385598U;
            aOrbiterK = (aWandererJ + RotL64(aPrevious, 51U)) + 7834679350105534657U;
            aOrbiterI = ((aWandererE + RotL64(aScatter, 41U)) + 11347994382444180879U) + RotL64(aNonceWordB, 43U);
            aOrbiterE = (aWandererF + RotL64(aCross, 34U)) + 9449903188047063431U;
            aOrbiterD = (((aWandererC + RotL64(aPrevious, 13U)) + 6516243976652795170U) + aPhaseCOrbiterAssignSaltF[((aIndex + 18U)) & S_SALT1]) + RotL64(aNonceWordF, 50U);
            aOrbiterC = (aWandererG + RotL64(aScatter, 57U)) + 8420815253991184777U;
            aOrbiterH = (((aWandererH + RotL64(aIngress, 5U)) + RotL64(aCarry, 35U)) + 9081386852515170937U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 46U)) + RotL64(aCarry, 43U)) + 14375955191735286867U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 880757589768436072U) + RotL64(aNonceWordD, 29U);
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 3349856625725164229U;
            aOrbiterK = RotL64((aOrbiterK * 681514212582331781U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 7826309957607577207U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 8057435761214313635U;
            aOrbiterE = RotL64((aOrbiterE * 4718430712767038607U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 9565237500443303103U) + RotL64(aNonceWordE, 31U);
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 15893066735310588501U;
            aOrbiterC = RotL64((aOrbiterC * 8457633439171452397U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 3276844534476430842U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 6828644383891274120U;
            aOrbiterJ = RotL64((aOrbiterJ * 979580351653410157U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 2815676923011504251U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 5030251870850928417U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7075653570570819253U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 13464083008377887034U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 8994560761846897590U;
            aOrbiterD = RotL64((aOrbiterD * 9892839554658865143U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 8398813387154468736U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 8136429428340910892U;
            aOrbiterH = RotL64((aOrbiterH * 3348811490733577295U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 418587250696862341U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 4111667833838312094U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 860949442143849147U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 6075478294190926371U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 2208124955874142264U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15741988616251072075U), 51U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterE, 26U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 5U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 43U));
            aIngress = aIngress + RotL64(aOrbiterD, 38U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aIngress, 10U) + aOrbiterG) + RotL64(aOrbiterD, 57U)) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 27U) + aOrbiterE) + RotL64(aOrbiterC, 35U)) + aPhaseCWandererUpdateSaltA[((aIndex + 11U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterK, 18U)) + aOrbiterD);
            aWandererG = aWandererG + (((RotL64(aScatter, 51U) + RotL64(aOrbiterH, 3U)) + aOrbiterE) + RotL64(aCarry, 23U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 19U) + aOrbiterC) + RotL64(aOrbiterD, 23U));
            aWandererC = aWandererC + (((RotL64(aCross, 47U) + RotL64(aOrbiterB, 27U)) + aOrbiterH) + RotL64(aCarry, 13U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 34U) + RotL64(aOrbiterB, 43U)) + aOrbiterC) + RotL64(aNonceWordH, 55U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 57U) + aOrbiterG) + RotL64(aOrbiterI, 48U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterJ, 53U)) + aOrbiterI) + RotL64(aNonceWordA, 45U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 51U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + (RotL64(aWandererA, 30U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererH, 35U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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

void TwistExpander_Bowling_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x8BC9E51FD3D2BC57ULL + 0xD5C86823B3CE499FULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xE7815679CBA3D055ULL + 0x9FAD32595FDD35F7ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x95D126CD52E9F76DULL + 0x9B684DD5406DEAB0ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xD40B6C5F5219D583ULL + 0x8775CA88383D0B80ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xAED18A3CCE29FC65ULL + 0x8EB9945A6DA404B0ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xFCE02504FD041A31ULL + 0xF0AC5F304F594AC2ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xF257513350B6230FULL + 0xE661F578A7B9D6CAULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xF8F9B1A9477E6A93ULL + 0xB21F713B26CC0555ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordE, 36U) ^ RotL64(aNonceWordC, 19U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 1411U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneC[((aIndex + 3837U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 21U) ^ RotL64(aNonceWordF, 5U)) ^ RotL64(aNonceWordA, 47U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 59U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneA[((aIndex + 4964U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 22U) + RotL64(aIngress, 35U)) ^ (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterF = ((aWandererK + RotL64(aIngress, 47U)) + RotL64(aCarry, 19U)) + 2330952702412094686U;
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 51U)) + 7820188225935060799U) + aPhaseDOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = ((aWandererG + RotL64(aScatter, 60U)) + 9347644591709839145U) + RotL64(aNonceWordH, 13U);
            aOrbiterC = (aWandererE + RotL64(aCross, 21U)) + 2288624878446846870U;
            aOrbiterB = (aWandererD + RotL64(aPrevious, 53U)) + 9358977729492824128U;
            aOrbiterI = (aWandererH + RotL64(aCross, 19U)) + 1858511275052455039U;
            aOrbiterK = (aWandererA + RotL64(aScatter, 37U)) + 13715478509322292552U;
            aOrbiterH = (aWandererB + RotL64(aIngress, 5U)) + 16413396625604260455U;
            aOrbiterE = (((aWandererI + RotL64(aCross, 11U)) + RotL64(aCarry, 23U)) + 17714322215518432705U) + RotL64(aNonceWordB, 18U);
            aOrbiterD = (aWandererC + RotL64(aIngress, 57U)) + 16188315436202861122U;
            aOrbiterJ = (((aWandererJ + RotL64(aPrevious, 24U)) + RotL64(aCarry, 43U)) + 5564445841368207813U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 13717068949900594673U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 14143659432287313765U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17281441046722262917U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 5729546141908425670U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 4297827922736712074U;
            aOrbiterI = RotL64((aOrbiterI * 13631630436759768885U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 829520109395163673U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 11547160328525174295U) ^ RotL64(aNonceWordG, 39U);
            aOrbiterF = RotL64((aOrbiterF * 4759690159673049775U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 2907177944512117206U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 11100346409065275671U;
            aOrbiterC = RotL64((aOrbiterC * 17927994356809011637U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 1344592529249949068U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 6470438516791143572U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13339390828725370475U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 5217751823741520847U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 5371275223586938039U;
            aOrbiterE = RotL64((aOrbiterE * 12318403075523724125U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 14218103150268532919U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 1367628876596800571U;
            aOrbiterJ = RotL64((aOrbiterJ * 13777531272321533137U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 2372041991018455610U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 9870744274890595581U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12093443117747395585U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 15531376915156611594U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 11166549148968363252U;
            aOrbiterB = RotL64((aOrbiterB * 10024372567841218915U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 8555942275137258839U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 3304132937209624841U) ^ RotL64(aNonceWordC, 53U);
            aOrbiterH = RotL64((aOrbiterH * 7965093976633155809U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 14825330575158830172U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 2330952702412094686U;
            aOrbiterD = RotL64((aOrbiterD * 9146641978165131495U), 5U);
            //
            aIngress = RotL64(aOrbiterI, 53U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 60U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 35U));
            aIngress = aIngress + (RotL64(aOrbiterB, 41U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterH, 29U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterF, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 5U) + aOrbiterI) + RotL64(aOrbiterB, 29U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 39U) + aOrbiterA) + RotL64(aOrbiterK, 19U)) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 50U) + RotL64(aOrbiterG, 13U)) + aOrbiterB);
            aWandererB = aWandererB + (((RotL64(aCross, 3U) + aOrbiterA) + RotL64(aOrbiterD, 21U)) + RotL64(aNonceWordD, 59U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 37U) + aOrbiterE) + RotL64(aOrbiterK, 58U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 35U) + aOrbiterF) + RotL64(aOrbiterB, 3U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 24U) + aOrbiterH) + RotL64(aOrbiterA, 37U)) + RotL64(aNonceWordE, 51U));
            aWandererK = aWandererK + (((RotL64(aCross, 13U) + RotL64(aOrbiterJ, 51U)) + aOrbiterA) + RotL64(aCarry, 51U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterF, 34U)) + aOrbiterE);
            aWandererD = aWandererD + ((RotL64(aIngress, 43U) + aOrbiterF) + RotL64(aOrbiterD, 23U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 53U) + aOrbiterC) + RotL64(aOrbiterD, 11U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (RotL64(aWandererK, 18U) ^ aWandererH);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererA, 60U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 3U) ^ RotL64(aNonceWordF, 39U)) ^ RotL64(aNonceWordB, 57U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 6344U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 5545U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 5U) ^ RotL64(aNonceWordC, 23U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9022U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((aIndex + 5638U)) & S_BLOCK1], 46U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 3U) + RotL64(aIngress, 36U)) ^ (RotL64(aPrevious, 51U) ^ RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterD = (aWandererJ + RotL64(aIngress, 41U)) + 10881271196314989997U;
            aOrbiterG = (aWandererD + RotL64(aPrevious, 21U)) + 6406461249988567558U;
            aOrbiterF = ((aWandererB + RotL64(aScatter, 35U)) + 17255067918280095959U) + aPhaseDOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = ((aWandererE + RotL64(aCross, 47U)) + RotL64(aCarry, 23U)) + 16690850682497718411U;
            aOrbiterH = ((aWandererI + RotL64(aIngress, 56U)) + RotL64(aCarry, 39U)) + 5576201059361086866U;
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 37U)) + RotL64(aCarry, 29U)) + 11991259685693687554U;
            aOrbiterC = ((aWandererF + RotL64(aCross, 13U)) + 14652535244217836909U) + RotL64(aNonceWordC, 52U);
            aOrbiterJ = (aWandererK + RotL64(aScatter, 29U)) + 1701789037170782122U;
            aOrbiterE = ((aWandererH + RotL64(aIngress, 23U)) + 953429054903473833U) + RotL64(aNonceWordG, 47U);
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 43U)) + 12064513610469714211U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = (aWandererC + RotL64(aScatter, 54U)) + 7993881398822002424U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 14421313768013320050U) + RotL64(aNonceWordA, 5U);
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 11112386845630998889U;
            aOrbiterF = RotL64((aOrbiterF * 11771526352030371669U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 17069630896535699015U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 3308240081138623373U;
            aOrbiterG = RotL64((aOrbiterG * 10449509484417835159U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 17615529807112933619U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 11782807146851563541U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12992075832343669221U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 14401645829607611983U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 6736397344219993532U;
            aOrbiterC = RotL64((aOrbiterC * 1667287547938175641U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 6446974060524700550U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 7840991992443308254U;
            aOrbiterE = RotL64((aOrbiterE * 6891023544882740107U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 10362169906019794305U) + RotL64(aNonceWordE, 35U);
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 4503700997923168911U;
            aOrbiterD = RotL64((aOrbiterD * 15066164494038852559U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 13492041134973259041U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 14337899277551397976U;
            aOrbiterK = RotL64((aOrbiterK * 5966740718899290915U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 13693100781608180748U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 16177545026405910052U;
            aOrbiterB = RotL64((aOrbiterB * 6019231448444020563U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 9641191118119415680U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 735491776764667034U;
            aOrbiterJ = RotL64((aOrbiterJ * 11305930862759869997U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 2225714710491247284U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 16906789796765378455U;
            aOrbiterA = RotL64((aOrbiterA * 4341667316266234469U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 9451961177946601088U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 10881271196314989997U;
            aOrbiterI = RotL64((aOrbiterI * 10929686721061541543U), 27U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterC, 57U);
            aIngress = aIngress + (RotL64(aOrbiterB, 52U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 39U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 29U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterG, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 60U) + RotL64(aOrbiterG, 40U)) + aOrbiterB);
            aWandererI = aWandererI + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterD, 57U)) + aOrbiterJ);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 37U) + aOrbiterI) + RotL64(aOrbiterA, 23U));
            aWandererA = aWandererA + ((RotL64(aCross, 57U) + aOrbiterE) + RotL64(aOrbiterC, 37U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 3U) + aOrbiterG) + RotL64(aOrbiterE, 47U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterC, 43U)) + aOrbiterF) + RotL64(aCarry, 53U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterJ, 3U)) + aOrbiterF) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 48U) + aOrbiterJ) + RotL64(aOrbiterK, 13U)) + RotL64(aCarry, 3U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterK, 21U)) + aOrbiterH) + RotL64(aNonceWordH, 57U));
            aWandererH = aWandererH + (((RotL64(aScatter, 11U) + RotL64(aOrbiterK, 60U)) + aOrbiterD) + RotL64(aNonceWordF, 29U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterB, 51U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererG, 48U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 14U));
            aCarry = aCarry + RotL64(aWandererF, 37U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 29U) ^ RotL64(aNonceWordB, 5U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 14385U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneA[((aIndex + 15905U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 34U) ^ RotL64(aNonceWordH, 19U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16215U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneC[((aIndex + 14361U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aPrevious, 41U)) ^ (RotL64(aCross, 5U) ^ RotL64(aIngress, 54U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterC = (aWandererE + RotL64(aScatter, 35U)) + 9435962834163239322U;
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 51U)) + 10524704356081318973U) + RotL64(aNonceWordF, 5U);
            aOrbiterK = (((aWandererB + RotL64(aCross, 21U)) + RotL64(aCarry, 11U)) + 7403401305665208680U) + aPhaseDOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = (aWandererG + RotL64(aIngress, 37U)) + 7525414805023556493U;
            aOrbiterA = (aWandererK + RotL64(aCross, 41U)) + 1116686470029070951U;
            aOrbiterG = ((aWandererD + RotL64(aScatter, 3U)) + RotL64(aCarry, 51U)) + 13257612299137802420U;
            aOrbiterH = (aWandererA + RotL64(aPrevious, 48U)) + 9181543003986598283U;
            aOrbiterB = (((aWandererI + RotL64(aIngress, 19U)) + RotL64(aCarry, 21U)) + 9739384852307501107U) + RotL64(aNonceWordE, 40U);
            aOrbiterE = (aWandererJ + RotL64(aCross, 23U)) + 11308402900229016057U;
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 29U)) + 14935167593705272337U;
            aOrbiterI = ((aWandererH + RotL64(aScatter, 56U)) + 7171824007631943535U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 8068411284829563567U) + RotL64(aNonceWordD, 23U);
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 12350207458513447578U;
            aOrbiterK = RotL64((aOrbiterK * 813973258659041895U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 17039236343991574134U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 18291683592714999632U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7771718817924840713U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 6239616841884430968U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 10604527977569876774U;
            aOrbiterF = RotL64((aOrbiterF * 6972820410084939637U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 1707724300671717658U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 3802268808625297647U) ^ RotL64(aNonceWordG, 11U);
            aOrbiterA = RotL64((aOrbiterA * 11296811630387191563U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 9423064323799920219U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 242153923313096551U;
            aOrbiterB = RotL64((aOrbiterB * 12117679073775630197U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 945801070951928277U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 13094814302414492064U;
            aOrbiterJ = RotL64((aOrbiterJ * 14638176479878969775U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 7572219725951040117U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 16494986983782503428U;
            aOrbiterC = RotL64((aOrbiterC * 2739189408707408171U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 10949497978229234856U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 11219643352002119905U;
            aOrbiterD = RotL64((aOrbiterD * 16900635614259262873U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 14245670385849499678U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 13771155918235018585U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14121731385133220921U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 15722734439532828816U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 11032710342174118366U;
            aOrbiterE = RotL64((aOrbiterE * 16096465375397981585U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 2071496769185495150U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 9435962834163239322U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10640995428633266765U), 29U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterJ, 42U);
            aIngress = aIngress + (RotL64(aOrbiterD, 37U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterF, 13U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 11U));
            aIngress = aIngress + RotL64(aOrbiterC, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aPrevious, 56U) + aOrbiterE) + RotL64(aOrbiterI, 42U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterK, 39U)) + aOrbiterB) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 53U) + aOrbiterB) + RotL64(aOrbiterG, 11U)) + RotL64(aCarry, 41U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterK, 57U)) + aOrbiterH);
            aWandererE = aWandererE + ((RotL64(aPrevious, 60U) + aOrbiterH) + RotL64(aOrbiterD, 23U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 41U) + aOrbiterC) + RotL64(aOrbiterJ, 51U));
            aWandererH = aWandererH + ((RotL64(aIngress, 37U) + RotL64(aOrbiterE, 37U)) + aOrbiterJ);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterI, 48U)) + aOrbiterF);
            aWandererI = aWandererI + (((RotL64(aIngress, 11U) + aOrbiterD) + RotL64(aOrbiterK, 21U)) + RotL64(aNonceWordB, 15U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 23U) + aOrbiterH) + RotL64(aOrbiterA, 29U)) + RotL64(aNonceWordC, 49U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterI, 27U)) + aOrbiterJ) + RotL64(aCarry, 13U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 37U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 41U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 56U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererJ, 5U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 23U) ^ RotL64(aNonceWordE, 6U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 19371U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneB[((aIndex + 18991U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 57U) ^ RotL64(aNonceWordB, 6U)) ^ RotL64(aNonceWordD, 35U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 16837U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16744U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 3U) ^ RotL64(aCarry, 51U)) + (RotL64(aPrevious, 20U) + RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 29U)) + RotL64(aCarry, 43U)) + 14823268998003220191U;
            aOrbiterD = ((aWandererB + RotL64(aCross, 3U)) + 15295237288788213847U) + RotL64(aNonceWordB, 50U);
            aOrbiterB = ((aWandererF + RotL64(aScatter, 6U)) + 16434853402001133899U) + RotL64(aNonceWordG, 49U);
            aOrbiterH = (aWandererD + RotL64(aIngress, 43U)) + 7555911304407871631U;
            aOrbiterC = ((aWandererI + RotL64(aScatter, 41U)) + RotL64(aCarry, 37U)) + 14977248264994834620U;
            aOrbiterJ = ((aWandererH + RotL64(aCross, 13U)) + RotL64(aCarry, 11U)) + 9707764144919392380U;
            aOrbiterE = ((aWandererG + RotL64(aIngress, 35U)) + 1277304385464681529U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = (aWandererK + RotL64(aPrevious, 53U)) + 3089786220465849395U;
            aOrbiterF = (aWandererA + RotL64(aScatter, 39U)) + 3700503853358695085U;
            aOrbiterG = (aWandererC + RotL64(aIngress, 20U)) + 3240054112993517371U;
            aOrbiterA = ((aWandererE + RotL64(aCross, 57U)) + 16897532076915366859U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 18167359289798364307U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 8870819278575769863U;
            aOrbiterB = RotL64((aOrbiterB * 9334066154398059075U), 53U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterH) + 15363069206212330251U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1]) + RotL64(aNonceWordH, 27U);
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 14858164441499725158U;
            aOrbiterC = RotL64((aOrbiterC * 14931933411393847915U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 5357144808788707522U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 2910681277417754860U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13170868582159347059U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 9824408699018165151U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 368370224788793300U;
            aOrbiterE = RotL64((aOrbiterE * 14358982366258729959U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 7095398304588825115U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 11418879758164313554U;
            aOrbiterK = RotL64((aOrbiterK * 5983520332639771791U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 2171599720681913272U) + RotL64(aNonceWordF, 59U);
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 17593730219647495033U;
            aOrbiterF = RotL64((aOrbiterF * 12926053208918563087U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 17755947635188715523U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 14565740605227022106U;
            aOrbiterG = RotL64((aOrbiterG * 15866418354612945335U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 14538017880915584414U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 6174566474851449123U;
            aOrbiterA = RotL64((aOrbiterA * 179569008593475683U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 3806438394748643441U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 13737114463856719285U;
            aOrbiterI = RotL64((aOrbiterI * 13439346068497710151U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 3698379331577470045U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 1097081284062708554U;
            aOrbiterD = RotL64((aOrbiterD * 3498627643013255777U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 215117138867597766U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 14823268998003220191U;
            aOrbiterH = RotL64((aOrbiterH * 12131828437975771377U), 51U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterJ, 20U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 27U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 11U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 37U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 53U));
            aIngress = aIngress + RotL64(aOrbiterF, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aCross, 19U) + RotL64(aOrbiterC, 60U)) + aOrbiterG) + RotL64(aNonceWordE, 51U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterG, 21U)) + aOrbiterF);
            aWandererC = aWandererC + ((((RotL64(aIngress, 51U) + aOrbiterH) + RotL64(aOrbiterK, 35U)) + RotL64(aCarry, 19U)) + aPhaseDWandererUpdateSaltF[((aIndex + 28U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterE, 13U)) + aOrbiterI);
            aWandererI = aWandererI + (((RotL64(aScatter, 30U) + RotL64(aOrbiterD, 23U)) + aOrbiterJ) + aPhaseDWandererUpdateSaltA[((aIndex + 20U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 53U) + aOrbiterI) + RotL64(aOrbiterC, 39U));
            aWandererD = aWandererD + (((RotL64(aCross, 27U) + RotL64(aOrbiterD, 51U)) + aOrbiterA) + RotL64(aCarry, 5U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 37U) + aOrbiterB) + RotL64(aOrbiterH, 29U));
            aWandererK = aWandererK + ((RotL64(aIngress, 23U) + RotL64(aOrbiterA, 27U)) + aOrbiterH);
            aWandererE = aWandererE ^ ((RotL64(aCross, 58U) + RotL64(aOrbiterD, 53U)) + aOrbiterC);
            aWandererB = aWandererB + (((RotL64(aScatter, 5U) + aOrbiterC) + RotL64(aOrbiterK, 4U)) + RotL64(aNonceWordC, 5U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 4U));
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererI);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + (RotL64(aWandererB, 18U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererD, 35U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 13U) ^ RotL64(aNonceWordD, 4U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 24156U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneA[((aIndex + 26576U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 54U) ^ RotL64(aNonceWordE, 13U)) ^ RotL64(aNonceWordH, 43U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 23769U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 26579U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 48U) + RotL64(aPrevious, 35U)) + (RotL64(aCross, 11U) ^ RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterH = ((aWandererJ + RotL64(aCross, 30U)) + RotL64(aCarry, 41U)) + 1087148170018530502U;
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 39U)) + RotL64(aCarry, 11U)) + 15530846874509311414U;
            aOrbiterI = (aWandererF + RotL64(aIngress, 3U)) + 16987358651515511212U;
            aOrbiterA = ((aWandererI + RotL64(aScatter, 11U)) + 12504143181007924259U) + RotL64(aNonceWordA, 9U);
            aOrbiterG = (aWandererG + RotL64(aPrevious, 43U)) + 393322117322732418U;
            aOrbiterF = ((aWandererK + RotL64(aCross, 5U)) + 14325937299241887166U) + aPhaseDOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterK = ((aWandererA + RotL64(aIngress, 41U)) + RotL64(aCarry, 5U)) + 9395262907017475742U;
            aOrbiterB = (aWandererH + RotL64(aScatter, 19U)) + 13658510441418344769U;
            aOrbiterE = (aWandererE + RotL64(aPrevious, 60U)) + 6410754322737005336U;
            aOrbiterD = (((aWandererB + RotL64(aScatter, 23U)) + 9257290738538818434U) + aPhaseDOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1]) + RotL64(aNonceWordG, 55U);
            aOrbiterJ = (aWandererD + RotL64(aIngress, 47U)) + 7489828960857692286U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 4118778591214588387U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 16619215231168796563U;
            aOrbiterI = RotL64((aOrbiterI * 14876884956536265157U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 11326283811003573430U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 1865401866017614604U;
            aOrbiterF = RotL64((aOrbiterF * 8378326058282460073U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 670150121105733604U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 1499331510641068749U;
            aOrbiterB = RotL64((aOrbiterB * 16623742535540383107U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 1116410848560838532U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 2696841341036281779U;
            aOrbiterD = RotL64((aOrbiterD * 9598953298074904869U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 5487352391229549881U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 12008243050943342979U;
            aOrbiterH = RotL64((aOrbiterH * 9087261224804582459U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 552859665927882960U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 8426942688524814473U;
            aOrbiterA = RotL64((aOrbiterA * 10916963622695549105U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 1613287981244830815U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 15592897923468694288U;
            aOrbiterK = RotL64((aOrbiterK * 6600750586743893303U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 7629853970631002676U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 13778028957247561272U) ^ RotL64(aNonceWordF, 59U);
            aOrbiterE = RotL64((aOrbiterE * 4063798788229605659U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 2932956928094332652U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 14855524972646900872U;
            aOrbiterJ = RotL64((aOrbiterJ * 9546042275547649745U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 11071597794692793784U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 6327727700942234552U) ^ RotL64(aNonceWordC, 17U);
            aOrbiterC = RotL64((aOrbiterC * 15301120263944789797U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 5147576281502110428U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 1087148170018530502U;
            aOrbiterG = RotL64((aOrbiterG * 18045084130531645749U), 21U);
            //
            aIngress = RotL64(aOrbiterJ, 26U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 11U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 41U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 43U));
            aIngress = aIngress + RotL64(aOrbiterA, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aScatter, 36U) + aOrbiterG) + RotL64(aOrbiterA, 53U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 57U) + aOrbiterJ) + RotL64(aOrbiterE, 60U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterI, 51U)) + aOrbiterH) + RotL64(aCarry, 53U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterI, 41U)) + aOrbiterF);
            aWandererI = aWandererI + (((RotL64(aIngress, 29U) + RotL64(aOrbiterB, 27U)) + aOrbiterF) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 53U) + aOrbiterK) + RotL64(aOrbiterA, 43U));
            aWandererD = aWandererD + (((RotL64(aScatter, 21U) + aOrbiterC) + RotL64(aOrbiterK, 57U)) + RotL64(aCarry, 37U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterE, 11U)) + aOrbiterK) + aPhaseDWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 26U) + RotL64(aOrbiterD, 47U)) + aOrbiterI) + RotL64(aNonceWordE, 58U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterE, 39U)) + aOrbiterF) + RotL64(aNonceWordH, 11U));
            aWandererF = aWandererF + ((RotL64(aCross, 43U) + aOrbiterG) + RotL64(aOrbiterE, 24U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 44U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 39U) ^ aWandererE);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 50U));
            aCarry = aCarry + RotL64(aWandererG, 3U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 23U) ^ RotL64(aNonceWordB, 34U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 27563U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27865U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 14U) ^ RotL64(aNonceWordA, 51U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 31679U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31144U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 60U) ^ RotL64(aPrevious, 35U)) ^ (RotL64(aIngress, 47U) + RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterH = (aWandererC + RotL64(aScatter, 56U)) + 2168513956284366370U;
            aOrbiterE = (((aWandererF + RotL64(aPrevious, 43U)) + RotL64(aCarry, 27U)) + 10290361969974613111U) + RotL64(aNonceWordE, 55U);
            aOrbiterD = (aWandererJ + RotL64(aCross, 51U)) + 15673836275828498050U;
            aOrbiterC = (aWandererE + RotL64(aIngress, 35U)) + 16600540024145812236U;
            aOrbiterI = ((aWandererK + RotL64(aCross, 53U)) + RotL64(aCarry, 35U)) + 9428052101528111892U;
            aOrbiterK = (((aWandererA + RotL64(aPrevious, 37U)) + 12763657928312763377U) + aPhaseDOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1]) + RotL64(aNonceWordH, 47U);
            aOrbiterB = ((aWandererI + RotL64(aScatter, 5U)) + 10751286982008662485U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = ((aWandererH + RotL64(aIngress, 27U)) + RotL64(aCarry, 57U)) + 1708230173038057979U;
            aOrbiterF = (aWandererG + RotL64(aCross, 13U)) + 4011389705422783816U;
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 23U)) + 11704428328093077714U;
            aOrbiterA = (aWandererD + RotL64(aIngress, 60U)) + 2055336619674699284U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 1870865272102705804U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 3574214263751923179U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13132083406834413563U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 984611970726966186U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 15207945449947643672U;
            aOrbiterI = RotL64((aOrbiterI * 9539470161576639981U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 4181398506373973169U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 15222345431506025949U;
            aOrbiterK = RotL64((aOrbiterK * 6925143692628659467U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 15023513452326240962U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 14965669361708810699U) ^ RotL64(aNonceWordD, 9U);
            aOrbiterB = RotL64((aOrbiterB * 587008860996713147U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 7985755518735406360U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 225592097619240187U;
            aOrbiterG = RotL64((aOrbiterG * 2313509354133400439U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 3659537916566939383U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 17043668033610689611U;
            aOrbiterF = RotL64((aOrbiterF * 10797634709118100773U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 10217321522161675848U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 8013663869536146842U;
            aOrbiterJ = RotL64((aOrbiterJ * 2293233079384777175U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 13762445330867496042U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 2692400019659269106U;
            aOrbiterA = RotL64((aOrbiterA * 167704184292219399U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 18232551682424867647U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 14785847596876239854U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4569180925037758487U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 5910282247522389536U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 16556038638738871204U;
            aOrbiterE = RotL64((aOrbiterE * 18356922295088260901U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 141620663839815754U) + RotL64(aNonceWordC, 51U);
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 2168513956284366370U;
            aOrbiterC = RotL64((aOrbiterC * 8605382725635471683U), 57U);
            //
            aIngress = RotL64(aOrbiterD, 60U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 27U));
            aIngress = aIngress + (RotL64(aOrbiterC, 11U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterA, 21U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterI, 19U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterJ, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aPrevious, 4U) + RotL64(aOrbiterC, 36U)) + aOrbiterK) + RotL64(aCarry, 35U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 39U) + aOrbiterH) + RotL64(aOrbiterK, 41U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 21U) + aOrbiterB) + RotL64(aOrbiterC, 19U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterI, 43U)) + aOrbiterF);
            aWandererK = aWandererK + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterB, 29U)) + aOrbiterD);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 35U) + aOrbiterH) + RotL64(aOrbiterG, 3U));
            aWandererH = aWandererH + ((RotL64(aIngress, 29U) + RotL64(aOrbiterA, 12U)) + aOrbiterD);
            aWandererF = aWandererF ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterI, 27U)) + aOrbiterG) + RotL64(aNonceWordG, 18U));
            aWandererE = aWandererE + ((((RotL64(aPrevious, 23U) + RotL64(aOrbiterA, 53U)) + aOrbiterJ) + RotL64(aNonceWordB, 19U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 54U) + aOrbiterK) + RotL64(aOrbiterJ, 47U));
            aWandererD = aWandererD + ((((RotL64(aScatter, 19U) + aOrbiterC) + RotL64(aOrbiterE, 57U)) + RotL64(aCarry, 13U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 21U));
            aCarry = aCarry + (RotL64(aWandererG, 10U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererD, 41U);
            aCarry = aCarry + RotL64(aIngress, 48U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xE5C032B5F75D8A91ULL + 0xE7E7D4313E5CCAF5ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x9AA985BFF572DF43ULL + 0xF61E49BCADD684C3ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x804E57DB2487B797ULL + 0x967FE954037D8701ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xF68243DCC573715DULL + 0xE114DA62A43D1AC6ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xF1E8AEB1DDDE67EFULL + 0xE6348D42A6D4D473ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xF0B2C348DCC6845FULL + 0x9F400212C0D9D47EULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xD101B9131DB76B67ULL + 0xB1D031B118219A35ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x976797F6332017AFULL + 0xFC531FD8545C3CD9ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 56U) ^ RotL64(aNonceWordE, 37U));
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 862U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 973U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 37U) ^ RotL64(aNonceWordF, 50U)) ^ RotL64(aNonceWordD, 11U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 3547U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 5133U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 37U) + RotL64(aCarry, 5U)) ^ (RotL64(aIngress, 22U) ^ RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterF = ((((aWandererK + RotL64(aPrevious, 27U)) + RotL64(aCarry, 19U)) + 14214886793361825363U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 22U)) & S_SALT1]) + RotL64(aNonceWordC, 43U);
            aOrbiterK = ((aWandererA + RotL64(aCross, 51U)) + 17267959031078766320U) + RotL64(aNonceWordE, 3U);
            aOrbiterH = (aWandererC + RotL64(aScatter, 18U)) + 16436067429484887644U;
            aOrbiterB = (aWandererF + RotL64(aIngress, 39U)) + 9885951769332633820U;
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 35U)) + RotL64(aCarry, 29U)) + 12971711341813893304U;
            aOrbiterD = (aWandererD + RotL64(aPrevious, 11U)) + 199970353398450154U;
            aOrbiterG = (aWandererB + RotL64(aIngress, 20U)) + 1237341696444162094U;
            aOrbiterC = (aWandererG + RotL64(aScatter, 57U)) + 7991128854417613360U;
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 23U)) + 14809029847149045833U) + aPhaseEOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = (aWandererH + RotL64(aCross, 29U)) + 2559509556915775947U;
            aOrbiterE = ((aWandererI + RotL64(aIngress, 13U)) + RotL64(aCarry, 3U)) + 14336829730147834160U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 8853631886733610440U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 13346159398673246914U;
            aOrbiterH = RotL64((aOrbiterH * 13660497151446983393U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 12121095718571872976U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 16239781125815589804U) ^ RotL64(aNonceWordH, 53U);
            aOrbiterD = RotL64((aOrbiterD * 5157009090454962231U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 9051377033794324106U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 13805815136723461780U;
            aOrbiterF = RotL64((aOrbiterF * 571129481747181357U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 14849157800322754413U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 18116651528452542634U;
            aOrbiterB = RotL64((aOrbiterB * 3638480428016835537U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 4105057226952948599U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 5911714320560994391U;
            aOrbiterG = RotL64((aOrbiterG * 1796514171654961389U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 4439149331729987587U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 10278532228230163632U;
            aOrbiterI = RotL64((aOrbiterI * 17428224919864716517U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 2342456582668741750U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 2360578572554664800U;
            aOrbiterE = RotL64((aOrbiterE * 1108428466956691925U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 12132934875391401246U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 17213278726790245812U) ^ RotL64(aNonceWordB, 47U);
            aOrbiterK = RotL64((aOrbiterK * 11904899990681410419U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 7994340481560109811U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 13735851271080138255U;
            aOrbiterJ = RotL64((aOrbiterJ * 12387076892129731557U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 6682417543888875268U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 15642799286975840550U;
            aOrbiterC = RotL64((aOrbiterC * 7861250716882028053U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 9839299346094784067U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 14214886793361825363U;
            aOrbiterA = RotL64((aOrbiterA * 2103132743364916037U), 47U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterE, 26U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 35U));
            aIngress = aIngress + (RotL64(aOrbiterA, 19U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterI, 41U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 11U));
            aIngress = aIngress + RotL64(aOrbiterG, 28U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aIngress, 13U) + aOrbiterD) + RotL64(aOrbiterC, 36U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 28U) + aOrbiterK) + RotL64(aOrbiterF, 53U));
            aWandererG = aWandererG + ((RotL64(aCross, 3U) + RotL64(aOrbiterC, 11U)) + aOrbiterK);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterJ, 27U)) + aOrbiterA);
            aWandererD = aWandererD + (((RotL64(aScatter, 23U) + aOrbiterI) + RotL64(aOrbiterB, 21U)) + RotL64(aCarry, 47U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterG, 3U)) + aOrbiterB);
            aWandererK = aWandererK + ((((RotL64(aIngress, 57U) + aOrbiterH) + RotL64(aOrbiterI, 41U)) + RotL64(aNonceWordA, 12U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterA, 58U)) + aOrbiterH);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterA, 19U)) + aOrbiterG) + RotL64(aCarry, 51U)) + RotL64(aNonceWordG, 27U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterK, 43U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aCross, 26U) + aOrbiterE) + RotL64(aOrbiterJ, 13U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 60U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 13U));
            aCarry = aCarry + (RotL64(aWandererC, 27U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererF, 21U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererG, 30U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 43U) ^ RotL64(aNonceWordH, 54U)) ^ RotL64(aNonceWordD, 11U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 7056U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneD[((aIndex + 9617U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 19U) ^ RotL64(aNonceWordF, 47U));
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 7331U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 8915U)) & S_BLOCK1], 28U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 44U) + RotL64(aCarry, 57U)) ^ (RotL64(aCross, 27U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterJ = (aWandererB + RotL64(aCross, 39U)) + 9446153639709651566U;
            aOrbiterK = (aWandererK + RotL64(aScatter, 18U)) + 10550762260670758167U;
            aOrbiterF = ((aWandererE + RotL64(aIngress, 47U)) + 7062634922142578383U) + RotL64(aNonceWordH, 9U);
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 11U)) + 9178499097812764515U) + aPhaseEOrbiterAssignSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterC = (aWandererC + RotL64(aIngress, 13U)) + 6887103379773525538U;
            aOrbiterA = (((aWandererA + RotL64(aCross, 3U)) + RotL64(aCarry, 57U)) + 6239750312052010257U) + RotL64(aNonceWordE, 58U);
            aOrbiterB = ((aWandererD + RotL64(aScatter, 51U)) + RotL64(aCarry, 35U)) + 17645022614523287959U;
            aOrbiterG = (((aWandererH + RotL64(aPrevious, 34U)) + RotL64(aCarry, 23U)) + 3639618183259408272U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = (aWandererJ + RotL64(aCross, 43U)) + 3131737117548745095U;
            aOrbiterI = (aWandererF + RotL64(aIngress, 29U)) + 7253994382396406554U;
            aOrbiterH = (aWandererG + RotL64(aScatter, 23U)) + 15217993711938379561U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 12594152227603630033U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 11250170200489647869U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 546800378327864723U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 12936942656624279424U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 10990736056052106149U;
            aOrbiterK = RotL64((aOrbiterK * 7123916809953459187U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 12787293075893090465U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 17154990205620778151U) ^ RotL64(aNonceWordA, 43U);
            aOrbiterC = RotL64((aOrbiterC * 10031369940028159521U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 1270827262969060301U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 17337623431665013136U;
            aOrbiterB = RotL64((aOrbiterB * 1517262088236356107U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 830330490987911853U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 6828309232554560547U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9742464176986145819U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 11470087853413986203U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 10470148870747884420U;
            aOrbiterJ = RotL64((aOrbiterJ * 6766079738799967443U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 18315536891901859637U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 12264670822285914271U;
            aOrbiterD = RotL64((aOrbiterD * 5841574505408674119U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 10931842095884524879U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 11134871340959676257U;
            aOrbiterA = RotL64((aOrbiterA * 11714837622285605745U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 11484168476761306078U) + RotL64(aNonceWordG, 57U);
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 5964766416973454097U;
            aOrbiterG = RotL64((aOrbiterG * 14721123403032510803U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 10646362765367117994U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 8994267196877016381U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17386417559346134797U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 16797547458402042464U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 9446153639709651566U;
            aOrbiterH = RotL64((aOrbiterH * 567585472220695323U), 11U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterJ, 35U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 53U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 38U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 41U));
            aIngress = aIngress + (RotL64(aOrbiterG, 19U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterD, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aCross, 27U) + RotL64(aOrbiterK, 57U)) + aOrbiterF);
            aWandererE = aWandererE ^ ((((RotL64(aPrevious, 39U) + aOrbiterK) + RotL64(aOrbiterE, 6U)) + RotL64(aNonceWordD, 11U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aIngress, 11U) + RotL64(aOrbiterI, 27U)) + aOrbiterH);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 6U) + RotL64(aOrbiterJ, 11U)) + aOrbiterI) + aPhaseEWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 29U) + aOrbiterH) + RotL64(aOrbiterF, 39U)) + RotL64(aCarry, 35U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterB, 13U)) + aOrbiterE);
            aWandererJ = aWandererJ + (((RotL64(aCross, 41U) + RotL64(aOrbiterG, 60U)) + aOrbiterD) + RotL64(aCarry, 39U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 53U) + aOrbiterC) + RotL64(aOrbiterK, 37U));
            aWandererF = aWandererF + ((RotL64(aCross, 13U) + RotL64(aOrbiterB, 23U)) + aOrbiterD);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 46U) + RotL64(aOrbiterI, 3U)) + aOrbiterK);
            aWandererB = aWandererB + (((RotL64(aIngress, 23U) + RotL64(aOrbiterC, 41U)) + aOrbiterA) + RotL64(aNonceWordC, 21U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 46U));
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererF);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 41U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 53U));
            aCarry = aCarry + (RotL64(aWandererA, 30U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererE, 19U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 21U) ^ RotL64(aNonceWordD, 13U)) ^ RotL64(aNonceWordA, 47U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 13838U)) & S_BLOCK1], 36U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 11374U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 57U) ^ RotL64(aNonceWordE, 43U)) ^ RotL64(aNonceWordH, 13U));
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 13584U)) & S_BLOCK1], 34U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 14785U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 27U) ^ RotL64(aIngress, 39U)) ^ (RotL64(aCarry, 11U) + RotL64(aPrevious, 60U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterK = (aWandererG + RotL64(aPrevious, 39U)) + 9654059367478508868U;
            aOrbiterD = (aWandererF + RotL64(aIngress, 57U)) + 6473006635864677427U;
            aOrbiterG = (aWandererK + RotL64(aCross, 23U)) + 6944184481315853243U;
            aOrbiterF = ((aWandererE + RotL64(aScatter, 13U)) + 4061496421939102306U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = ((aWandererC + RotL64(aCross, 28U)) + RotL64(aCarry, 43U)) + 15791809275719085463U;
            aOrbiterI = (((aWandererH + RotL64(aIngress, 47U)) + 14050798802646323055U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1]) + RotL64(aNonceWordH, 57U);
            aOrbiterH = ((aWandererI + RotL64(aScatter, 11U)) + RotL64(aCarry, 11U)) + 12072905924741758266U;
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 3U)) + 17639076509231343896U) + RotL64(aNonceWordE, 53U);
            aOrbiterB = ((aWandererJ + RotL64(aIngress, 35U)) + RotL64(aCarry, 29U)) + 12195388285571234715U;
            aOrbiterC = (aWandererA + RotL64(aScatter, 60U)) + 4325404419499496529U;
            aOrbiterA = (aWandererB + RotL64(aCross, 51U)) + 5910567888204238382U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 13092940059929942699U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 13381962590820308761U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6345904465930943295U), 13U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterJ) + 15622862439323440527U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1]) + RotL64(aNonceWordF, 39U);
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 14027151901132249793U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2273573821630510087U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 4584410023907605157U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 15763755180625487157U;
            aOrbiterD = RotL64((aOrbiterD * 6755736130607297639U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 17023059745666559199U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 5298529579288492971U;
            aOrbiterJ = RotL64((aOrbiterJ * 2483562793328357721U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 2870152867331654736U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 12017191100173748848U;
            aOrbiterE = RotL64((aOrbiterE * 9958191466506480519U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 15899529176182436062U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 16482713846343388735U;
            aOrbiterC = RotL64((aOrbiterC * 719465695044265601U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 12943393531812774449U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 9881108254540483225U;
            aOrbiterK = RotL64((aOrbiterK * 8011108108007885059U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 3532054586199716750U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 7142230313294797435U;
            aOrbiterF = RotL64((aOrbiterF * 14154176174768868421U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 733958394016131587U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 2060800099014517137U;
            aOrbiterH = RotL64((aOrbiterH * 12988885554457108631U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 2278498033811574812U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 15342071118593803929U;
            aOrbiterB = RotL64((aOrbiterB * 7842196613533603835U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 12987212219357101955U) + RotL64(aNonceWordG, 23U);
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 9654059367478508868U;
            aOrbiterA = RotL64((aOrbiterA * 11796100167917742307U), 3U);
            //
            aIngress = RotL64(aOrbiterH, 35U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 29U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 51U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 19U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 37U));
            aIngress = aIngress + RotL64(aOrbiterC, 42U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aCross, 53U) + aOrbiterC) + RotL64(aOrbiterG, 30U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 27U) + aOrbiterG) + RotL64(aOrbiterF, 41U)) + RotL64(aNonceWordA, 9U));
            aWandererI = aWandererI + ((RotL64(aIngress, 43U) + aOrbiterK) + RotL64(aOrbiterG, 57U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterB, 53U)) + aOrbiterJ);
            aWandererD = aWandererD + (((RotL64(aScatter, 21U) + RotL64(aOrbiterD, 13U)) + aOrbiterI) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 48U) + RotL64(aOrbiterH, 48U)) + aOrbiterD) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 23U) + aOrbiterA) + RotL64(aOrbiterE, 19U)) + RotL64(aCarry, 3U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 39U) + aOrbiterD) + RotL64(aOrbiterK, 43U));
            aWandererH = aWandererH + ((RotL64(aIngress, 41U) + RotL64(aOrbiterG, 37U)) + aOrbiterI);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterJ, 39U)) + aOrbiterD);
            aWandererA = aWandererA + ((((RotL64(aScatter, 18U) + aOrbiterB) + RotL64(aOrbiterE, 3U)) + RotL64(aCarry, 57U)) + RotL64(aNonceWordC, 42U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 4U));
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererD);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 41U));
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererF, 30U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 57U) ^ RotL64(aNonceWordD, 3U)) ^ RotL64(aNonceWordG, 34U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 18132U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 21689U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 35U) ^ RotL64(aNonceWordE, 5U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 17337U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 17710U)) & S_BLOCK1], 24U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aPrevious, 11U)) + (RotL64(aIngress, 36U) ^ RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 21U)) + RotL64(aCarry, 19U)) + 6243113109470883144U;
            aOrbiterG = (aWandererA + RotL64(aCross, 41U)) + 3891552123999605832U;
            aOrbiterC = (((aWandererG + RotL64(aIngress, 27U)) + RotL64(aCarry, 41U)) + 8758797898587019128U) + RotL64(aNonceWordA, 61U);
            aOrbiterE = (aWandererD + RotL64(aScatter, 47U)) + 1005891374086408851U;
            aOrbiterB = ((aWandererB + RotL64(aIngress, 39U)) + 3713426782180050764U) + aPhaseEOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = (aWandererE + RotL64(aScatter, 58U)) + 18358143862391573534U;
            aOrbiterI = ((aWandererI + RotL64(aCross, 53U)) + RotL64(aCarry, 35U)) + 17504394029693712404U;
            aOrbiterH = (aWandererF + RotL64(aPrevious, 19U)) + 5312729289027417014U;
            aOrbiterD = (aWandererH + RotL64(aIngress, 3U)) + 2560873623431186029U;
            aOrbiterA = (((aWandererC + RotL64(aScatter, 37U)) + 16309322822806704211U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 4U)) & S_SALT1]) + RotL64(aNonceWordD, 19U);
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 12U)) + 10195513918020652600U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 2552116263258744287U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 7732784879810980089U;
            aOrbiterC = RotL64((aOrbiterC * 15041929399477790999U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 16499127570665381507U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 10890036715535519036U;
            aOrbiterB = RotL64((aOrbiterB * 9065115450010475187U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 16288944603478791554U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 14542766121469312846U;
            aOrbiterF = RotL64((aOrbiterF * 8435383464425875209U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 5973595239494084696U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 1820492719977197097U;
            aOrbiterI = RotL64((aOrbiterI * 16164917159141304405U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 10489529555776381736U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 6392552206958240484U;
            aOrbiterH = RotL64((aOrbiterH * 11761477994533503307U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 10163241948999404556U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 16054678853554707148U;
            aOrbiterD = RotL64((aOrbiterD * 10570418210789350091U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 3606021702108590330U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 16920568417324295852U;
            aOrbiterA = RotL64((aOrbiterA * 5222656554577625385U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 13889995689147406315U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 7908387312354285092U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7995682580514280949U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 14161911472715334589U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 12386100977925313406U) ^ RotL64(aNonceWordC, 29U);
            aOrbiterK = RotL64((aOrbiterK * 17136336570895231639U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 14408470657696841139U) + RotL64(aNonceWordB, 37U);
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 7466281699619513012U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2706710684289882025U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 11125044052260579351U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 6243113109470883144U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17390954549755941181U), 51U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterI, 3U);
            aIngress = aIngress + (RotL64(aOrbiterB, 12U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterG, 53U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 43U));
            aIngress = aIngress + (RotL64(aOrbiterA, 19U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterC, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aIngress, 19U) + aOrbiterH) + RotL64(aOrbiterB, 5U));
            aWandererI = aWandererI + (((RotL64(aScatter, 29U) + RotL64(aOrbiterH, 41U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 10U) + aOrbiterG) + RotL64(aOrbiterI, 51U));
            aWandererA = aWandererA + ((RotL64(aCross, 23U) + RotL64(aOrbiterH, 23U)) + aOrbiterE);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 57U) + aOrbiterC) + RotL64(aOrbiterH, 56U));
            aWandererF = aWandererF + ((((RotL64(aPrevious, 39U) + aOrbiterD) + RotL64(aOrbiterH, 47U)) + RotL64(aCarry, 37U)) + RotL64(aNonceWordG, 58U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterA, 53U)) + aOrbiterC);
            aWandererD = aWandererD + (((((RotL64(aCross, 5U) + RotL64(aOrbiterH, 37U)) + aOrbiterK) + RotL64(aCarry, 53U)) + RotL64(aNonceWordH, 31U)) + aPhaseEWandererUpdateSaltA[((aIndex + 18U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterC, 43U)) + aOrbiterJ);
            aWandererE = aWandererE + ((RotL64(aIngress, 53U) + RotL64(aOrbiterA, 27U)) + aOrbiterF);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 44U) + aOrbiterE) + RotL64(aOrbiterI, 30U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 56U));
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererI);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererD);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + RotL64(aWandererC, 18U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 19U) ^ RotL64(aNonceWordA, 44U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 25821U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 23991U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 11U) ^ RotL64(aNonceWordC, 3U)) ^ RotL64(aNonceWordF, 57U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 24111U)) & S_BLOCK1], 40U) ^ RotL64(aExpandLaneA[((aIndex + 26682U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 51U) ^ RotL64(aCarry, 18U)) + (RotL64(aIngress, 3U) + RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterC = ((aWandererB + RotL64(aScatter, 3U)) + RotL64(aCarry, 35U)) + 826930775230515406U;
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 6U)) + 5137814617363250861U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = (((aWandererD + RotL64(aCross, 23U)) + RotL64(aCarry, 5U)) + 14761561947426681616U) + RotL64(aNonceWordG, 9U);
            aOrbiterH = (aWandererK + RotL64(aIngress, 19U)) + 12773023438753662590U;
            aOrbiterJ = ((aWandererH + RotL64(aPrevious, 27U)) + 7331345852207096322U) + RotL64(aNonceWordC, 61U);
            aOrbiterB = (aWandererF + RotL64(aScatter, 21U)) + 3899381212671247460U;
            aOrbiterF = (aWandererA + RotL64(aCross, 34U)) + 10072004147620068599U;
            aOrbiterD = ((aWandererG + RotL64(aIngress, 13U)) + 3424585039401897560U) + aPhaseEOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 47U)) + RotL64(aCarry, 39U)) + 8246760141625966321U;
            aOrbiterA = (aWandererC + RotL64(aScatter, 29U)) + 3655992860610853290U;
            aOrbiterG = (aWandererE + RotL64(aIngress, 43U)) + 11154618022505863898U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 15629361991059709973U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 10842068502278489664U;
            aOrbiterE = RotL64((aOrbiterE * 17223002513104960799U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 5571312349016336686U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 589313823745748879U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1356685926549786027U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 13633457935771935260U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 12684602052812183096U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4689206269919806711U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 5711307583717354204U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 7181854170553728211U;
            aOrbiterA = RotL64((aOrbiterA * 9835601115561325911U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 1884620014396115821U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 1471516373272364262U;
            aOrbiterC = RotL64((aOrbiterC * 5126319375714848029U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 742739371092077733U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 8075893317715227838U;
            aOrbiterH = RotL64((aOrbiterH * 11208274111743259795U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 8179547722249281263U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterJ) ^ 15305282712174742323U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1]) ^ RotL64(aNonceWordD, 43U);
            aOrbiterF = RotL64((aOrbiterF * 7951986906055462929U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 1430543231751281079U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 14585341768267283387U;
            aOrbiterK = RotL64((aOrbiterK * 313213844964269133U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 8123889986027932297U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 2081696191347150910U) ^ RotL64(aNonceWordA, 13U);
            aOrbiterG = RotL64((aOrbiterG * 4869653441012615053U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 10166788886199265936U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 15927074835525735601U;
            aOrbiterI = RotL64((aOrbiterI * 6747650218540675523U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 6997764816848988590U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 826930775230515406U;
            aOrbiterJ = RotL64((aOrbiterJ * 9943232461538279601U), 19U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterK, 35U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 18U));
            aIngress = aIngress + (RotL64(aOrbiterE, 43U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterG, 37U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterB, 47U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterI, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 11U)) + aOrbiterG);
            aWandererF = aWandererF + ((RotL64(aScatter, 57U) + aOrbiterE) + RotL64(aOrbiterK, 51U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 18U) + aOrbiterF) + RotL64(aOrbiterH, 26U));
            aWandererI = aWandererI + (((RotL64(aIngress, 41U) + aOrbiterE) + RotL64(aOrbiterJ, 35U)) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 27U) + aOrbiterJ) + RotL64(aOrbiterA, 39U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 35U) + aOrbiterH) + RotL64(aOrbiterG, 3U)) + RotL64(aCarry, 57U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterH, 5U)) + aOrbiterE);
            aWandererH = aWandererH + ((RotL64(aScatter, 48U) + aOrbiterC) + RotL64(aOrbiterB, 37U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterH, 57U)) + aOrbiterB) + RotL64(aNonceWordB, 21U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 23U) + aOrbiterD) + RotL64(aOrbiterJ, 54U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((((RotL64(aIngress, 53U) + aOrbiterE) + RotL64(aOrbiterC, 23U)) + RotL64(aNonceWordH, 36U)) + aPhaseEWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 56U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 41U));
            aCarry = aCarry + (RotL64(aWandererD, 26U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererG, 23U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 3U) ^ RotL64(aNonceWordD, 29U)) ^ RotL64(aNonceWordA, 39U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 28565U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneB[((aIndex + 29549U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 57U) ^ RotL64(aNonceWordB, 35U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 28647U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneB[((aIndex + 28314U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 54U) ^ RotL64(aCarry, 41U)) ^ (RotL64(aPrevious, 23U) + RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterI = (aWandererF + RotL64(aScatter, 50U)) + 9471546960258473684U;
            aOrbiterG = ((aWandererE + RotL64(aCross, 13U)) + 18050235435948942244U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = (((aWandererC + RotL64(aPrevious, 21U)) + RotL64(aCarry, 11U)) + 3005107102671544641U) + RotL64(aNonceWordE, 41U);
            aOrbiterH = (aWandererD + RotL64(aIngress, 5U)) + 17898396434573801850U;
            aOrbiterK = ((aWandererA + RotL64(aPrevious, 35U)) + 15071602525497771648U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = (aWandererH + RotL64(aIngress, 53U)) + 5780119462702672108U;
            aOrbiterF = (aWandererI + RotL64(aScatter, 3U)) + 13301326224151025687U;
            aOrbiterB = (((aWandererB + RotL64(aCross, 37U)) + RotL64(aCarry, 21U)) + 18129323022260575961U) + RotL64(aNonceWordD, 9U);
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 30U)) + 1199228670638790709U;
            aOrbiterC = (aWandererG + RotL64(aScatter, 39U)) + 1839199978088021020U;
            aOrbiterA = ((aWandererK + RotL64(aIngress, 41U)) + RotL64(aCarry, 43U)) + 4999517042246790165U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 8788607633376516299U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 15143903839930468749U;
            aOrbiterD = RotL64((aOrbiterD * 12735914889325422675U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 16674732686428431869U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 15908873150953195581U;
            aOrbiterK = RotL64((aOrbiterK * 18049755517524334107U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 11204775359756474667U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 2525984309543939465U;
            aOrbiterJ = RotL64((aOrbiterJ * 3988529812023791571U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 4566345170476825512U) + RotL64(aNonceWordB, 3U);
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 14876612901557406267U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9047956948845135339U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 14926290877038883931U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 12710203178186614846U;
            aOrbiterB = RotL64((aOrbiterB * 14841163494801662515U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 7315094513967387996U) + RotL64(aNonceWordC, 59U);
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 11050116830482816766U;
            aOrbiterE = RotL64((aOrbiterE * 3702999495721152019U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 4505368486032503953U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 17905748055257551092U;
            aOrbiterC = RotL64((aOrbiterC * 14775870175093453197U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 5728886950801376350U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 17998141690182325170U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16008599930125391379U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 4325978018819134558U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 13526905108565989379U;
            aOrbiterI = RotL64((aOrbiterI * 14121321495714166291U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 10597169665474269506U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 7500801022830471869U;
            aOrbiterG = RotL64((aOrbiterG * 3702717219742363777U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 17063616328548689935U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 9471546960258473684U;
            aOrbiterH = RotL64((aOrbiterH * 3029748230803396737U), 43U);
            //
            aIngress = RotL64(aOrbiterK, 35U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 48U));
            aIngress = aIngress + (RotL64(aOrbiterB, 5U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 19U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 37U));
            aIngress = aIngress + RotL64(aOrbiterJ, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aCross, 39U) + RotL64(aOrbiterE, 37U)) + aOrbiterD) + RotL64(aCarry, 11U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterH, 21U)) + aOrbiterB);
            aWandererK = aWandererK + ((((RotL64(aIngress, 23U) + aOrbiterA) + RotL64(aOrbiterF, 60U)) + RotL64(aCarry, 29U)) + RotL64(aNonceWordH, 12U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 36U) + RotL64(aOrbiterC, 51U)) + aOrbiterG);
            aWandererD = aWandererD + ((RotL64(aCross, 13U) + RotL64(aOrbiterJ, 23U)) + aOrbiterI);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterE, 39U)) + aOrbiterI);
            aWandererE = aWandererE + ((RotL64(aScatter, 53U) + aOrbiterC) + RotL64(aOrbiterD, 11U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 30U) + aOrbiterH) + RotL64(aOrbiterE, 27U));
            aWandererG = aWandererG + ((RotL64(aCross, 5U) + aOrbiterG) + RotL64(aOrbiterK, 48U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterA, 57U)) + aOrbiterI) + aPhaseEWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterC, 3U)) + aOrbiterK) + RotL64(aNonceWordG, 47U)) + aPhaseEWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 34U));
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererI);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + RotL64(aWandererF, 39U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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

void TwistExpander_Bowling_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x9EDA466A930983E7ULL + 0xCBC437A1F3D11511ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xCC9AFF26C25C6657ULL + 0xE3F1D49C6AFDE12BULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xD4CFADC57BDC5073ULL + 0xDE07987A4A19C2C9ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xA523EDDAE8FB711FULL + 0xB37D00D7BD4A16CAULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xE89F5743B3011F25ULL + 0xE022BA7DAF033DDCULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xC8B4F616F98F1267ULL + 0xCCF5883D74DDF117ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x8ABF88AD16805F45ULL + 0xE7710A8112F70FA6ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xD8EE8EEF097F1DE3ULL + 0xC5B5A6E49910EA1AULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 3U) ^ RotL64(aNonceWordE, 53U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 5017U)) & S_BLOCK1], 12U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4600U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 44U) ^ RotL64(aNonceWordH, 53U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 1796U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneA[((aIndex + 3951U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 21U) ^ RotL64(aIngress, 43U)) + (RotL64(aPrevious, 57U) + RotL64(aCross, 6U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 57U)) + RotL64(aCarry, 19U)) + 11410829607777684449U;
            aOrbiterK = (aWandererB + RotL64(aIngress, 22U)) + 7502698839700975347U;
            aOrbiterG = ((aWandererE + RotL64(aCross, 11U)) + 13267685058252106173U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = (aWandererC + RotL64(aScatter, 35U)) + 238242706996630625U;
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 51U)) + 8184695499511454281U) + aPhaseFOrbiterAssignSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = ((aWandererJ + RotL64(aCross, 39U)) + 12767823220461985403U) + RotL64(aNonceWordA, 43U);
            aOrbiterD = (aWandererH + RotL64(aPrevious, 19U)) + 12293198423143850330U;
            aOrbiterB = (((aWandererD + RotL64(aScatter, 29U)) + RotL64(aCarry, 37U)) + 11149495229952495939U) + RotL64(aNonceWordG, 3U);
            aOrbiterC = (aWandererI + RotL64(aCross, 37U)) + 7556992689338382800U;
            aOrbiterH = ((aWandererA + RotL64(aIngress, 27U)) + RotL64(aCarry, 43U)) + 3431338808774134649U;
            aOrbiterA = (aWandererG + RotL64(aScatter, 4U)) + 16863099140844995099U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 17872458049880677604U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 16760153457252546974U;
            aOrbiterG = RotL64((aOrbiterG * 11225037229069712805U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 3115544493537438408U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 4359882942759752958U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 561477566995575801U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 13387113067202396536U) + RotL64(aNonceWordH, 12U);
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 12955690074544490161U;
            aOrbiterF = RotL64((aOrbiterF * 12449941770827974511U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 15614054443728226807U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 1939441328066616114U;
            aOrbiterE = RotL64((aOrbiterE * 4484917074808974359U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 4599016263007782537U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 9962305629016158048U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1496184427500037279U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 8428467674122750557U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 3938884087806393439U;
            aOrbiterC = RotL64((aOrbiterC * 12810531094050481761U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 6018636830758044658U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 1510372000641305416U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9002834928626918247U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 17592782466215337843U) + RotL64(aNonceWordD, 39U);
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 8119921507606870360U;
            aOrbiterK = RotL64((aOrbiterK * 1299795061644535485U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 8753237702359236964U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 12389957327067768090U;
            aOrbiterJ = RotL64((aOrbiterJ * 4586786761936601607U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 17791633199762408683U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 11606494383812053915U;
            aOrbiterB = RotL64((aOrbiterB * 13041480602055778521U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 4418614662439151979U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 11410829607777684449U;
            aOrbiterH = RotL64((aOrbiterH * 3342270212301058781U), 43U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterB, 26U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 39U));
            aIngress = aIngress + (RotL64(aOrbiterA, 11U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 53U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 34U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterF, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aIngress, 43U) + RotL64(aOrbiterD, 19U)) + aOrbiterK);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 53U) + aOrbiterG) + RotL64(aOrbiterC, 6U));
            aWandererB = aWandererB + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterA, 37U)) + aOrbiterG) + RotL64(aCarry, 47U)) + RotL64(aNonceWordF, 11U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 3U) + aOrbiterF) + RotL64(aOrbiterD, 57U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 6U) + aOrbiterD) + RotL64(aOrbiterA, 3U)) + RotL64(aNonceWordC, 17U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterH, 27U)) + aOrbiterF);
            aWandererE = aWandererE + ((RotL64(aIngress, 29U) + RotL64(aOrbiterI, 23U)) + aOrbiterB);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterI, 13U)) + aOrbiterJ);
            aWandererI = aWandererI + (((RotL64(aCross, 35U) + RotL64(aOrbiterE, 43U)) + aOrbiterD) + RotL64(aCarry, 41U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 10U) + aOrbiterG) + RotL64(aOrbiterF, 47U));
            aWandererK = aWandererK + (((RotL64(aIngress, 41U) + aOrbiterB) + RotL64(aOrbiterF, 60U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 54U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 37U));
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererJ, 28U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 43U) ^ RotL64(aNonceWordD, 30U)) ^ RotL64(aNonceWordH, 3U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 6196U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneD[((aIndex + 9301U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 41U) ^ RotL64(aNonceWordG, 53U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 9143U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 7305U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCross, 53U)) + (RotL64(aIngress, 39U) + RotL64(aCarry, 26U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterB = (aWandererK + RotL64(aCross, 19U)) + 11274974230580265396U;
            aOrbiterC = (aWandererA + RotL64(aIngress, 13U)) + 16658438747342741547U;
            aOrbiterK = ((aWandererF + RotL64(aScatter, 29U)) + RotL64(aCarry, 23U)) + 16612986966106053844U;
            aOrbiterI = (aWandererD + RotL64(aPrevious, 23U)) + 9329502236843231290U;
            aOrbiterE = ((aWandererC + RotL64(aScatter, 35U)) + 14088261356708344656U) + aPhaseFOrbiterAssignSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = (((aWandererB + RotL64(aCross, 46U)) + RotL64(aCarry, 41U)) + 13692608802007789581U) + RotL64(aNonceWordG, 55U);
            aOrbiterD = ((aWandererG + RotL64(aIngress, 53U)) + 6824473946645682398U) + RotL64(aNonceWordH, 49U);
            aOrbiterA = (aWandererH + RotL64(aPrevious, 5U)) + 2072915876348570040U;
            aOrbiterF = (aWandererJ + RotL64(aCross, 37U)) + 7420507753044460759U;
            aOrbiterJ = (((aWandererE + RotL64(aPrevious, 21U)) + RotL64(aCarry, 35U)) + 4677557318688502593U) + aPhaseFOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = (aWandererI + RotL64(aIngress, 60U)) + 15081678577055628459U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 7026792817486507482U) + RotL64(aNonceWordF, 6U);
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 14871665922943969918U;
            aOrbiterK = RotL64((aOrbiterK * 694073180313083145U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 6807734532159292872U) + RotL64(aNonceWordB, 45U);
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 17882797335141303280U;
            aOrbiterC = RotL64((aOrbiterC * 15439872930381050291U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 9233542707022629190U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 1205501586581350876U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2596053290311090589U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 10878718669747466677U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 8066049063548639241U;
            aOrbiterD = RotL64((aOrbiterD * 3031382633089381605U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 861295180226875235U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 9134969787937288583U;
            aOrbiterF = RotL64((aOrbiterF * 7565008208670843555U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 6726642007159809594U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 8061661744643240470U;
            aOrbiterB = RotL64((aOrbiterB * 6703498926835391813U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 13541412083111962884U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 8617442758729315637U;
            aOrbiterI = RotL64((aOrbiterI * 15471862889276160953U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 16884403561131293362U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 9490680911678221233U;
            aOrbiterG = RotL64((aOrbiterG * 15988763830018001033U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 10486145044311386738U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 10200001044821063684U;
            aOrbiterA = RotL64((aOrbiterA * 16149790736141571017U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 6997073594007878034U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 13585783612009989767U;
            aOrbiterJ = RotL64((aOrbiterJ * 11425303157774550449U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 3847846040256340653U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 11274974230580265396U;
            aOrbiterH = RotL64((aOrbiterH * 13970270689108369205U), 37U);
            //
            aIngress = RotL64(aOrbiterE, 58U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 41U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 39U));
            aIngress = aIngress + (RotL64(aOrbiterH, 18U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterC, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aScatter, 37U) + RotL64(aOrbiterF, 21U)) + aOrbiterG);
            aWandererA = aWandererA ^ ((RotL64(aCross, 41U) + aOrbiterA) + RotL64(aOrbiterG, 53U));
            aWandererD = aWandererD + (((((RotL64(aPrevious, 26U) + RotL64(aOrbiterH, 37U)) + aOrbiterJ) + RotL64(aCarry, 21U)) + RotL64(aNonceWordA, 17U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterJ, 14U)) + aOrbiterE);
            aWandererC = aWandererC + (((RotL64(aPrevious, 13U) + aOrbiterE) + RotL64(aOrbiterI, 5U)) + RotL64(aNonceWordE, 61U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 3U) + aOrbiterK) + RotL64(aOrbiterE, 41U));
            aWandererK = aWandererK + (((RotL64(aIngress, 21U) + RotL64(aOrbiterK, 3U)) + aOrbiterG) + RotL64(aCarry, 43U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterB, 50U)) + aOrbiterH);
            aWandererI = aWandererI + ((RotL64(aPrevious, 23U) + aOrbiterC) + RotL64(aOrbiterF, 23U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 46U) + aOrbiterC) + RotL64(aOrbiterA, 57U)) + aPhaseFWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 29U) + RotL64(aOrbiterD, 47U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererC, 60U) ^ aWandererJ);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererK, 41U) ^ aWandererI);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 13U));
            aCarry = aCarry + RotL64(aWandererB, 11U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordA, 51U) ^ RotL64(aNonceWordC, 13U)) ^ RotL64(aNonceWordF, 5U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 11082U)) & S_BLOCK1], 26U) ^ RotL64(aWorkLaneA[((aIndex + 13779U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 29U) ^ RotL64(aNonceWordD, 38U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 13095U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 11616U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 37U) ^ RotL64(aPrevious, 3U)) ^ (RotL64(aIngress, 52U) + RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterD = ((aWandererH + RotL64(aScatter, 13U)) + 13204735390996728477U) + RotL64(aNonceWordB, 45U);
            aOrbiterF = (aWandererI + RotL64(aCross, 41U)) + 851171359595647173U;
            aOrbiterJ = ((aWandererG + RotL64(aIngress, 53U)) + 16745304202825290723U) + RotL64(aNonceWordC, 43U);
            aOrbiterA = (aWandererE + RotL64(aPrevious, 43U)) + 562392736584913979U;
            aOrbiterH = ((aWandererA + RotL64(aCross, 51U)) + RotL64(aCarry, 51U)) + 3244267012529053918U;
            aOrbiterI = (aWandererK + RotL64(aScatter, 30U)) + 17282536111067869133U;
            aOrbiterG = (aWandererD + RotL64(aIngress, 27U)) + 14851130066471729068U;
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 35U)) + RotL64(aCarry, 39U)) + 5256130407952363129U;
            aOrbiterK = ((aWandererF + RotL64(aIngress, 39U)) + 2904742485828362001U) + aPhaseFOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 6U)) + 3723346325449225387U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = ((aWandererB + RotL64(aScatter, 19U)) + RotL64(aCarry, 47U)) + 5344621093694027341U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 12919263300833603026U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 17989801264160996071U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15468293047311883751U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 5022175042377172157U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 16684822380107847758U;
            aOrbiterI = RotL64((aOrbiterI * 2834049270263837537U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 2740326510600876682U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 13981423865219318820U;
            aOrbiterF = RotL64((aOrbiterF * 14593082145080056441U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 231945878229848395U) + RotL64(aNonceWordH, 25U);
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 14139797734944312580U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6492256080432266407U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 16704102101387552373U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 8506734780526852552U;
            aOrbiterE = RotL64((aOrbiterE * 4684566118627414659U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 2774630043988894695U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 12490034334296488127U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16765455396278233145U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 545238171291436006U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 1023872898002379590U;
            aOrbiterD = RotL64((aOrbiterD * 8626333831510136515U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 5065187021047872560U) + RotL64(aNonceWordE, 20U);
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 10391809965648089863U;
            aOrbiterA = RotL64((aOrbiterA * 10912471108849550469U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 5576919045471579002U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 9761904001375034639U;
            aOrbiterG = RotL64((aOrbiterG * 8612901811320541361U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 2001472279505185946U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 11576457012366242134U;
            aOrbiterK = RotL64((aOrbiterK * 1070815118051466731U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 17713147845216099336U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 13204735390996728477U;
            aOrbiterB = RotL64((aOrbiterB * 10889281795183444943U), 27U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterG, 39U);
            aIngress = aIngress + (RotL64(aOrbiterC, 26U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 21U));
            aIngress = aIngress + (RotL64(aOrbiterI, 41U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterK, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aScatter, 51U) + aOrbiterG) + RotL64(aOrbiterA, 57U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 35U) + aOrbiterJ) + RotL64(aOrbiterH, 47U));
            aWandererA = aWandererA + ((((RotL64(aIngress, 46U) + aOrbiterA) + RotL64(aOrbiterE, 53U)) + RotL64(aCarry, 41U)) + RotL64(aNonceWordG, 27U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 19U) + aOrbiterA) + RotL64(aOrbiterJ, 24U)) + RotL64(aNonceWordF, 49U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterH, 41U)) + aOrbiterF);
            aWandererD = aWandererD ^ (((RotL64(aCross, 41U) + aOrbiterI) + RotL64(aOrbiterC, 51U)) + aPhaseFWandererUpdateSaltC[((aIndex + 16U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aScatter, 13U) + RotL64(aOrbiterA, 3U)) + aOrbiterD) + RotL64(aCarry, 57U)) + aPhaseFWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 57U) + aOrbiterH) + RotL64(aOrbiterK, 37U));
            aWandererK = aWandererK + ((RotL64(aScatter, 43U) + aOrbiterI) + RotL64(aOrbiterJ, 20U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 30U) + aOrbiterA) + RotL64(aOrbiterB, 5U));
            aWandererH = aWandererH + ((RotL64(aIngress, 21U) + RotL64(aOrbiterC, 29U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 46U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + (RotL64(aWandererB, 44U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererE, 3U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 53U) ^ RotL64(aNonceWordC, 3U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 21267U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19145U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 37U) ^ RotL64(aNonceWordG, 24U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20876U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 18938U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 26U) ^ RotL64(aIngress, 51U)) + (RotL64(aCross, 11U) + RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterD = (aWandererK + RotL64(aScatter, 19U)) + 4622023259121087483U;
            aOrbiterC = (aWandererA + RotL64(aIngress, 36U)) + 10253505250223501352U;
            aOrbiterE = (((aWandererC + RotL64(aCross, 57U)) + RotL64(aCarry, 43U)) + 17133877904420462669U) + aPhaseFOrbiterAssignSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterB = (aWandererB + RotL64(aPrevious, 5U)) + 6162827793741796700U;
            aOrbiterG = (aWandererE + RotL64(aCross, 43U)) + 9610986424765907615U;
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 29U)) + RotL64(aCarry, 3U)) + 11210747154264753754U;
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 3U)) + RotL64(aCarry, 23U)) + 16554205219580654546U;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 54U)) + 10352576357413766388U) + RotL64(aNonceWordD, 13U);
            aOrbiterI = (aWandererH + RotL64(aCross, 39U)) + 3651845783283479752U;
            aOrbiterH = (aWandererF + RotL64(aIngress, 51U)) + 18145542190463500476U;
            aOrbiterK = (((aWandererJ + RotL64(aScatter, 21U)) + 5415609566767162857U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1]) + RotL64(aNonceWordE, 22U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 2033734872464201570U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 3507213117125813345U) ^ RotL64(aNonceWordA, 3U);
            aOrbiterE = RotL64((aOrbiterE * 5453058336688881113U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 8716253393049851856U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 695984869565941856U;
            aOrbiterG = RotL64((aOrbiterG * 8377921610764044735U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 7661578828878284931U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 906654265099155956U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8117625377607536949U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 6050049984731254612U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 17882717590338190821U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10807367411402733215U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 4996521991532815957U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 4246460672800604436U;
            aOrbiterF = RotL64((aOrbiterF * 12047466401960824903U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 8700148116452518842U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 10039050281847466206U;
            aOrbiterI = RotL64((aOrbiterI * 11884791271239660157U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 4513844680425845372U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 3037563127442815153U;
            aOrbiterH = RotL64((aOrbiterH * 18363509277992292407U), 37U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 1005237931570968724U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 1373258132025712065U;
            aOrbiterK = RotL64((aOrbiterK * 10458020799382532395U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 12759144329395682277U) + RotL64(aNonceWordC, 25U);
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 5139371668116336931U;
            aOrbiterD = RotL64((aOrbiterD * 10761543179345026943U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 3211005174890625715U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 18045286961878287418U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4536094526540761611U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 4454078771279674978U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 4622023259121087483U;
            aOrbiterB = RotL64((aOrbiterB * 8991756794989027019U), 39U);
            //
            aIngress = RotL64(aOrbiterC, 19U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 37U));
            aIngress = aIngress + (RotL64(aOrbiterD, 29U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterE, 53U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 6U));
            aIngress = aIngress + RotL64(aOrbiterF, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aCross, 39U) + RotL64(aOrbiterF, 19U)) + aOrbiterG);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 21U) + aOrbiterA) + RotL64(aOrbiterB, 21U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 35U) + RotL64(aOrbiterD, 13U)) + aOrbiterK) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterA, 60U)) + aOrbiterC) + RotL64(aNonceWordB, 29U));
            aWandererE = aWandererE + (((RotL64(aScatter, 28U) + RotL64(aOrbiterA, 51U)) + aOrbiterD) + RotL64(aCarry, 11U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterK, 37U)) + aOrbiterH);
            aWandererG = aWandererG + (((RotL64(aCross, 5U) + RotL64(aOrbiterF, 41U)) + aOrbiterJ) + RotL64(aCarry, 5U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterE, 11U)) + aOrbiterJ);
            aWandererF = aWandererF + ((RotL64(aCross, 41U) + RotL64(aOrbiterI, 3U)) + aOrbiterG);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 44U) + RotL64(aOrbiterC, 27U)) + aOrbiterJ) + RotL64(aNonceWordF, 31U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 47U) + aOrbiterC) + RotL64(aOrbiterG, 58U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 10U));
            aCarry = aCarry + (RotL64(aWandererA, 21U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 27U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + RotL64(aWandererF, 60U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 57U) ^ RotL64(aNonceWordC, 29U)) ^ RotL64(aNonceWordE, 12U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 23266U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24840U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 52U) ^ RotL64(aNonceWordH, 41U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 22181U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 23867U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aPrevious, 41U)) ^ (RotL64(aCarry, 29U) + RotL64(aIngress, 6U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterC = (aWandererK + RotL64(aPrevious, 27U)) + 9041099828460168106U;
            aOrbiterE = (aWandererF + RotL64(aIngress, 57U)) + 12883711604096848454U;
            aOrbiterF = ((aWandererC + RotL64(aScatter, 35U)) + 17420968786226443079U) + RotL64(aNonceWordE, 9U);
            aOrbiterG = (aWandererI + RotL64(aCross, 29U)) + 3448213891716125104U;
            aOrbiterB = (((aWandererH + RotL64(aPrevious, 48U)) + 11866455977445336560U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1]) + RotL64(aNonceWordF, 3U);
            aOrbiterK = (aWandererG + RotL64(aCross, 43U)) + 4119356835384495905U;
            aOrbiterD = (aWandererE + RotL64(aIngress, 41U)) + 2186212599698637068U;
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 11U)) + RotL64(aCarry, 53U)) + 6506144898969301620U;
            aOrbiterH = ((aWandererA + RotL64(aCross, 5U)) + RotL64(aCarry, 57U)) + 12556800923644051626U;
            aOrbiterA = (aWandererJ + RotL64(aIngress, 18U)) + 4075551535185182945U;
            aOrbiterI = (((aWandererB + RotL64(aPrevious, 37U)) + RotL64(aCarry, 21U)) + 17877694808492008749U) + aPhaseFOrbiterAssignSaltA[((aIndex + 14U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 5553428900598223316U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 14362304852277160675U;
            aOrbiterF = RotL64((aOrbiterF * 11415103199856419303U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 9174200302876075831U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 16110739511917638547U;
            aOrbiterK = RotL64((aOrbiterK * 7004356839428657949U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 10189881974519849402U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 2128076632642616677U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8860453653433114929U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 18133523799074400083U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 9916472958834153766U;
            aOrbiterA = RotL64((aOrbiterA * 3454601168808001733U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 10274457562795569227U) + RotL64(aNonceWordB, 43U);
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 14134814273275356425U;
            aOrbiterC = RotL64((aOrbiterC * 15912501063665343159U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 6394306369514735480U) + RotL64(aNonceWordA, 49U);
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 4825761192736485643U;
            aOrbiterG = RotL64((aOrbiterG * 12534544147331805643U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 5672807934779206275U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 3881953574159390421U;
            aOrbiterD = RotL64((aOrbiterD * 7448770570912161095U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 12012232712634303203U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 14176392925893052596U;
            aOrbiterH = RotL64((aOrbiterH * 11288668529893084583U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 307148402076391033U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 15380446373458263079U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15228462337097647933U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 4654312690816676129U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 10818029316701301859U;
            aOrbiterE = RotL64((aOrbiterE * 16245734506125913215U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 7340370713289840635U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 9041099828460168106U;
            aOrbiterB = RotL64((aOrbiterB * 1807356802142268373U), 21U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterD, 21U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 13U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 5U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterG, 26U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aPrevious, 30U) + RotL64(aOrbiterD, 60U)) + aOrbiterK);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterG, 51U)) + aOrbiterJ) + RotL64(aNonceWordD, 47U));
            aWandererG = aWandererG + ((RotL64(aCross, 57U) + RotL64(aOrbiterE, 19U)) + aOrbiterC);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterA, 39U)) + aOrbiterE);
            aWandererH = aWandererH + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterE, 27U)) + aOrbiterD) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 4U) + aOrbiterH) + RotL64(aOrbiterI, 29U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 51U) + aOrbiterH) + RotL64(aOrbiterD, 11U)) + RotL64(aCarry, 11U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 13U) + aOrbiterF) + RotL64(aOrbiterH, 35U));
            aWandererD = aWandererD + ((RotL64(aCross, 23U) + RotL64(aOrbiterJ, 37U)) + aOrbiterK);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 27U) + aOrbiterD) + RotL64(aOrbiterB, 22U));
            aWandererC = aWandererC + (((((RotL64(aPrevious, 21U) + RotL64(aOrbiterH, 47U)) + aOrbiterJ) + RotL64(aCarry, 43U)) + RotL64(aNonceWordG, 56U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 34U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererF, 37U) ^ aWandererA);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + RotL64(aWandererE, 39U);
            aCarry = aCarry + RotL64(aIngress, 42U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 14U) ^ RotL64(aNonceWordE, 3U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 28836U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31957U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 11U) ^ RotL64(aNonceWordB, 19U)) ^ RotL64(aNonceWordF, 60U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30933U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28699U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aIngress, 27U)) ^ (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 12U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = (((aWandererG + RotL64(aScatter, 35U)) + RotL64(aCarry, 35U)) + 10881271196314989997U) + aPhaseFOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = (aWandererD + RotL64(aPrevious, 21U)) + 6406461249988567558U;
            aOrbiterC = ((aWandererE + RotL64(aIngress, 13U)) + RotL64(aCarry, 51U)) + 17255067918280095959U;
            aOrbiterJ = (aWandererB + RotL64(aCross, 3U)) + 16690850682497718411U;
            aOrbiterG = (aWandererA + RotL64(aScatter, 26U)) + 5576201059361086866U;
            aOrbiterB = ((aWandererH + RotL64(aCross, 51U)) + RotL64(aCarry, 3U)) + 11991259685693687554U;
            aOrbiterA = (((aWandererI + RotL64(aPrevious, 39U)) + 14652535244217836909U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1]) + RotL64(aNonceWordD, 37U);
            aOrbiterF = (aWandererC + RotL64(aIngress, 53U)) + 1701789037170782122U;
            aOrbiterI = (aWandererK + RotL64(aPrevious, 56U)) + 953429054903473833U;
            aOrbiterK = (aWandererJ + RotL64(aScatter, 47U)) + 12064513610469714211U;
            aOrbiterD = ((aWandererF + RotL64(aIngress, 19U)) + 7993881398822002424U) + RotL64(aNonceWordH, 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 14421313768013320050U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 11112386845630998889U;
            aOrbiterC = RotL64((aOrbiterC * 11771526352030371669U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 17069630896535699015U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 3308240081138623373U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10449509484417835159U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 17615529807112933619U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 11782807146851563541U;
            aOrbiterB = RotL64((aOrbiterB * 12992075832343669221U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 14401645829607611983U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 6736397344219993532U;
            aOrbiterA = RotL64((aOrbiterA * 1667287547938175641U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 6446974060524700550U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 7840991992443308254U;
            aOrbiterF = RotL64((aOrbiterF * 6891023544882740107U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 10362169906019794305U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 4503700997923168911U;
            aOrbiterI = RotL64((aOrbiterI * 15066164494038852559U), 43U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterF) + 13492041134973259041U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1]) + RotL64(aNonceWordB, 61U);
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 14337899277551397976U;
            aOrbiterK = RotL64((aOrbiterK * 5966740718899290915U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 13693100781608180748U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 16177545026405910052U;
            aOrbiterD = RotL64((aOrbiterD * 6019231448444020563U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 9641191118119415680U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 735491776764667034U;
            aOrbiterE = RotL64((aOrbiterE * 11305930862759869997U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 2225714710491247284U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 16906789796765378455U) ^ RotL64(aNonceWordA, 8U);
            aOrbiterH = RotL64((aOrbiterH * 4341667316266234469U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 9451961177946601088U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 10881271196314989997U;
            aOrbiterJ = RotL64((aOrbiterJ * 10929686721061541543U), 37U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterC, 41U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 13U));
            aIngress = aIngress + (RotL64(aOrbiterB, 47U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterA, 37U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterK, 34U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 23U) + aOrbiterI) + RotL64(aOrbiterF, 3U)) + aPhaseFWandererUpdateSaltA[((aIndex + 18U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 47U) + aOrbiterA) + RotL64(aOrbiterE, 23U)) + RotL64(aCarry, 43U)) + aPhaseFWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterJ, 60U)) + aOrbiterF);
            aWandererI = aWandererI + (((RotL64(aIngress, 35U) + aOrbiterD) + RotL64(aOrbiterA, 35U)) + RotL64(aNonceWordE, 39U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 29U) + aOrbiterF) + RotL64(aOrbiterA, 41U));
            aWandererD = aWandererD + ((RotL64(aScatter, 37U) + RotL64(aOrbiterG, 19U)) + aOrbiterC);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 54U) + RotL64(aOrbiterB, 11U)) + aOrbiterK);
            aWandererG = aWandererG + ((RotL64(aIngress, 13U) + aOrbiterH) + RotL64(aOrbiterG, 48U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 43U) + aOrbiterD) + RotL64(aOrbiterE, 27U));
            aWandererK = aWandererK + ((((RotL64(aCross, 5U) + aOrbiterA) + RotL64(aOrbiterC, 21U)) + RotL64(aCarry, 21U)) + RotL64(aNonceWordC, 53U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 57U) + aOrbiterB) + RotL64(aOrbiterE, 5U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 46U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 41U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 37U));
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererH, 12U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererK, 5U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xDFC374B8C8C100B9ULL + 0x8A09E2EA322D1626ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xC3D6B461E5BC6F07ULL + 0x9F7D217CC5AE070BULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xCC5A43AB01EC9BFDULL + 0xFFA274ACC0C5AB6CULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xF6415115FCF13BC7ULL + 0xFD83EC970EBF7716ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xD571A10690BCA8BBULL + 0x9ACAD5040497410EULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x92C487A9ED1776DFULL + 0xB13F3D00A44881AFULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xBE0458BD39E0074FULL + 0x898D94C6BEC569DDULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xEFCF0E7C0888C267ULL + 0xD9C1E5CBBA14D424ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 3U) ^ RotL64(aNonceWordD, 57U)) ^ RotL64(aNonceWordG, 39U));
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 1739U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 1745U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 57U) ^ RotL64(aNonceWordB, 19U)) ^ RotL64(aNonceWordF, 29U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 1560U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 704U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 41U) + RotL64(aPrevious, 11U)) ^ (RotL64(aIngress, 24U) + RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterH = (aWandererI + RotL64(aCross, 6U)) + 13481227414590594621U;
            aOrbiterD = ((((aWandererD + RotL64(aScatter, 39U)) + RotL64(aCarry, 11U)) + 17425964381118918026U) + aPhaseFOrbiterAssignSaltC[((aIndex + 8U)) & S_SALT1]) + RotL64(aNonceWordB, 43U);
            aOrbiterC = ((aWandererA + RotL64(aIngress, 53U)) + 4792004356135956581U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 21U)) + RotL64(aCarry, 43U)) + 11926849936000639098U;
            aOrbiterA = ((aWandererB + RotL64(aCross, 35U)) + RotL64(aCarry, 3U)) + 990697329347742142U;
            aOrbiterK = (aWandererH + RotL64(aPrevious, 51U)) + 9307721505373076588U;
            aOrbiterE = (aWandererJ + RotL64(aIngress, 12U)) + 17605732738841908719U;
            aOrbiterF = (aWandererF + RotL64(aScatter, 43U)) + 13110764518634187439U;
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 57U)) + 17970109897810645911U) + RotL64(aNonceWordG, 21U);
            aOrbiterB = (aWandererK + RotL64(aCross, 19U)) + 10273133817644703654U;
            aOrbiterG = (aWandererC + RotL64(aIngress, 27U)) + 11239046688920468137U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 8355821483275763145U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 15522151127786049345U;
            aOrbiterC = RotL64((aOrbiterC * 4844278537850520413U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 5381663179722418112U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 9551368011768104906U;
            aOrbiterK = RotL64((aOrbiterK * 14202470972121732997U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 16264476585232221270U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 7721417776432288282U) ^ RotL64(aNonceWordC, 27U);
            aOrbiterH = RotL64((aOrbiterH * 10267770327791051869U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 339418090653475277U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 3247926250495935511U) ^ RotL64(aNonceWordE, 15U);
            aOrbiterJ = RotL64((aOrbiterJ * 16824669543765729097U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 3390560045236418590U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 3894024951542543635U;
            aOrbiterE = RotL64((aOrbiterE * 10599637790900418767U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 3878539166189668154U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 5617705593218220843U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 82771190372750823U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 12320861089148474544U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 14943790251625519550U;
            aOrbiterG = RotL64((aOrbiterG * 13758322022902008313U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 18119213517612562775U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 1413193144229486646U;
            aOrbiterD = RotL64((aOrbiterD * 14562375280658115687U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 14810150213456844196U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 8468712395797520201U;
            aOrbiterA = RotL64((aOrbiterA * 8167911669632436949U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 13501570100536254566U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 15409772061478100850U;
            aOrbiterF = RotL64((aOrbiterF * 955182899606655851U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 8621805947309982779U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 13481227414590594621U;
            aOrbiterB = RotL64((aOrbiterB * 9591362493722704105U), 11U);
            //
            aIngress = RotL64(aOrbiterG, 29U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 41U));
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 60U));
            aIngress = aIngress + RotL64(aOrbiterI, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterH, 35U)) + aOrbiterK) + RotL64(aNonceWordH, 29U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 19U) + aOrbiterA) + RotL64(aOrbiterG, 53U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 53U) + aOrbiterC) + RotL64(aOrbiterB, 51U));
            aWandererI = aWandererI + (((RotL64(aCross, 23U) + RotL64(aOrbiterK, 19U)) + aOrbiterB) + RotL64(aCarry, 13U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterG, 43U)) + aOrbiterI);
            aWandererF = aWandererF + ((RotL64(aPrevious, 26U) + aOrbiterJ) + RotL64(aOrbiterE, 22U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 37U) + aOrbiterD) + RotL64(aOrbiterE, 3U));
            aWandererC = aWandererC + (((RotL64(aScatter, 3U) + RotL64(aOrbiterH, 41U)) + aOrbiterE) + aPhaseFWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 51U) + aOrbiterD) + RotL64(aOrbiterB, 27U)) + RotL64(aNonceWordD, 24U));
            aWandererK = aWandererK + (((RotL64(aScatter, 43U) + aOrbiterF) + RotL64(aOrbiterD, 10U)) + RotL64(aCarry, 57U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 60U) + aOrbiterI) + RotL64(aOrbiterD, 13U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 58U));
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 39U));
            aCarry = aCarry + (RotL64(aWandererF, 53U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererI, 37U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 53U) ^ RotL64(aNonceWordH, 39U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 10803U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneD[((aIndex + 6101U)) & S_BLOCK1], 30U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 10U) ^ RotL64(aNonceWordB, 51U));
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 5670U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 8485U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 21U) ^ RotL64(aIngress, 5U)) ^ (RotL64(aCarry, 57U) + RotL64(aPrevious, 36U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterF = ((((aWandererH + RotL64(aIngress, 39U)) + RotL64(aCarry, 35U)) + 479672811032092393U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1]) + RotL64(aNonceWordC, 45U);
            aOrbiterC = (aWandererI + RotL64(aPrevious, 60U)) + 18061121631394564425U;
            aOrbiterA = ((aWandererG + RotL64(aScatter, 23U)) + RotL64(aCarry, 19U)) + 14237400452740566065U;
            aOrbiterJ = (aWandererD + RotL64(aCross, 37U)) + 6723123812257706134U;
            aOrbiterD = (aWandererA + RotL64(aPrevious, 13U)) + 4247997188026499248U;
            aOrbiterI = (aWandererE + RotL64(aScatter, 30U)) + 1939107415066134869U;
            aOrbiterG = ((aWandererB + RotL64(aCross, 53U)) + RotL64(aCarry, 5U)) + 3912640123546395979U;
            aOrbiterE = (aWandererC + RotL64(aIngress, 5U)) + 8295478436553964298U;
            aOrbiterH = ((aWandererF + RotL64(aCross, 19U)) + 3218960600711526885U) + aPhaseFOrbiterAssignSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 43U)) + 5874096203353388890U) + RotL64(aNonceWordA, 59U);
            aOrbiterK = (aWandererK + RotL64(aIngress, 47U)) + 10294536533673023358U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 11268561953904130747U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 16693201256788898423U;
            aOrbiterA = RotL64((aOrbiterA * 16291987237693567209U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 7550969634681894654U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 9501647424602245869U;
            aOrbiterC = RotL64((aOrbiterC * 11265865222096866605U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 8881869255994319423U) + RotL64(aNonceWordD, 11U);
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 16770136406906800016U;
            aOrbiterD = RotL64((aOrbiterD * 1782039587385512923U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 16185384746435761363U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 13841034186650721627U;
            aOrbiterG = RotL64((aOrbiterG * 12000155593277035447U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 15229062695864608309U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 3576122704615303733U;
            aOrbiterH = RotL64((aOrbiterH * 2433987493885779279U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 13898167174453181224U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 12878032061609524049U;
            aOrbiterF = RotL64((aOrbiterF * 18104665741338251495U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 12719156051299028649U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 8640980843376950769U;
            aOrbiterJ = RotL64((aOrbiterJ * 10242616778390983333U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 12133332160916004365U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 8743563985229104484U;
            aOrbiterI = RotL64((aOrbiterI * 4575129690615054691U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 7362223873479167793U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 4230720394788635807U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3658720603716856293U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 5095842824285329272U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 7483469517256234638U;
            aOrbiterB = RotL64((aOrbiterB * 9782114499878763883U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 17426017004856399653U) + RotL64(aNonceWordE, 46U);
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 479672811032092393U;
            aOrbiterK = RotL64((aOrbiterK * 14921028515589317919U), 13U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterH, 12U);
            aIngress = aIngress + (RotL64(aOrbiterC, 39U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 27U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 23U));
            aIngress = aIngress + RotL64(aOrbiterJ, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aCross, 6U) + aOrbiterB) + RotL64(aOrbiterI, 14U)) + RotL64(aNonceWordG, 43U));
            aWandererD = aWandererD + (((RotL64(aScatter, 21U) + aOrbiterA) + RotL64(aOrbiterF, 3U)) + RotL64(aCarry, 27U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 13U) + aOrbiterE) + RotL64(aOrbiterJ, 57U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterK, 35U)) + aOrbiterJ) + RotL64(aCarry, 51U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterA, 5U)) + aOrbiterK);
            aWandererF = aWandererF + ((RotL64(aPrevious, 41U) + aOrbiterJ) + RotL64(aOrbiterC, 27U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterH, 51U)) + aOrbiterE);
            aWandererA = aWandererA + (((RotL64(aScatter, 23U) + RotL64(aOrbiterB, 53U)) + aOrbiterC) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 19U) + aOrbiterJ) + RotL64(aOrbiterD, 19U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterF, 37U)) + aOrbiterE) + RotL64(aNonceWordB, 31U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 39U) + aOrbiterG) + RotL64(aOrbiterE, 48U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 34U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererI);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 21U));
            aCarry = aCarry + RotL64(aWandererK, 41U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 56U) ^ RotL64(aNonceWordD, 11U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 15206U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 14887U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 11U) ^ RotL64(aNonceWordB, 23U)) ^ RotL64(aNonceWordG, 35U));
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 15928U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneC[((aIndex + 13308U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 6U)) ^ (RotL64(aCross, 41U) + RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterH = (aWandererI + RotL64(aIngress, 28U)) + 11998579547770778580U;
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 37U)) + 8409465187298704610U) + RotL64(aNonceWordC, 28U);
            aOrbiterC = (aWandererF + RotL64(aScatter, 43U)) + 3470222286110333500U;
            aOrbiterA = ((aWandererE + RotL64(aCross, 21U)) + 5704486785203069994U) + RotL64(aNonceWordA, 49U);
            aOrbiterI = (((aWandererA + RotL64(aScatter, 57U)) + RotL64(aCarry, 5U)) + 10334944660253279633U) + aPhaseFOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = (aWandererG + RotL64(aCross, 11U)) + 7626852700722567477U;
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 51U)) + 14631310754943209743U) + aPhaseFOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = (aWandererJ + RotL64(aIngress, 35U)) + 807160297237854120U;
            aOrbiterF = ((aWandererC + RotL64(aCross, 13U)) + RotL64(aCarry, 11U)) + 5624154783624196107U;
            aOrbiterD = ((aWandererK + RotL64(aIngress, 18U)) + RotL64(aCarry, 21U)) + 4971444394698940423U;
            aOrbiterJ = (aWandererH + RotL64(aPrevious, 53U)) + 6340057638461027062U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 9003019862787819481U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 13632057463595873033U;
            aOrbiterC = RotL64((aOrbiterC * 12575202147280216765U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 12766104026871797746U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 4062118445824915939U) ^ RotL64(aNonceWordG, 55U);
            aOrbiterB = RotL64((aOrbiterB * 13130770039048080701U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 5258212525426469978U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 9956946981015983939U;
            aOrbiterG = RotL64((aOrbiterG * 8106382657040497669U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 10837606223056473999U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 13292864885504191134U;
            aOrbiterI = RotL64((aOrbiterI * 4445739587553669471U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 166087925900318658U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 6786842221885441388U;
            aOrbiterK = RotL64((aOrbiterK * 4411147600413147773U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 16888086378070246404U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 5240855484445974002U;
            aOrbiterD = RotL64((aOrbiterD * 402652898573422271U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 6874866669211571608U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 732890824978127460U;
            aOrbiterH = RotL64((aOrbiterH * 3776365957702257453U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 5541380495707308058U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 17947326584411475765U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10920952349981652899U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 15060679340045767910U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 1675974028461383576U) ^ RotL64(aNonceWordH, 27U);
            aOrbiterE = RotL64((aOrbiterE * 15127962310365242819U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 226889112033170368U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 4290719734244011388U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6453598182035414143U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 7712233480730639084U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 11998579547770778580U;
            aOrbiterJ = RotL64((aOrbiterJ * 11599893373156816375U), 53U);
            //
            aIngress = RotL64(aOrbiterK, 28U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 23U));
            aIngress = aIngress + (RotL64(aOrbiterH, 51U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterB, 21U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterG, 35U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterA, 56U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aPrevious, 29U) + aOrbiterE) + RotL64(aOrbiterK, 51U)) + RotL64(aCarry, 41U)) + RotL64(aNonceWordE, 43U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterG, 46U)) + aOrbiterE) + aPhaseFWandererUpdateSaltC[((aIndex + 28U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 14U) + RotL64(aOrbiterC, 43U)) + aOrbiterD);
            aWandererI = aWandererI ^ ((RotL64(aCross, 43U) + aOrbiterI) + RotL64(aOrbiterH, 37U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 39U) + aOrbiterD) + RotL64(aOrbiterF, 41U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 21U) + aOrbiterH) + RotL64(aOrbiterG, 29U));
            aWandererE = aWandererE + (((RotL64(aIngress, 53U) + aOrbiterB) + RotL64(aOrbiterC, 54U)) + RotL64(aCarry, 5U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 41U) + aOrbiterA) + RotL64(aOrbiterK, 23U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aIngress, 47U) + aOrbiterD) + RotL64(aOrbiterH, 57U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 51U) + RotL64(aOrbiterD, 39U)) + aOrbiterG) + RotL64(aNonceWordB, 9U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 36U) + aOrbiterJ) + RotL64(aOrbiterG, 27U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererH, 26U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererK);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + RotL64(aWandererB, 21U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 30U) ^ RotL64(aNonceWordD, 41U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 21767U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneB[((aIndex + 16746U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 19U) ^ RotL64(aNonceWordE, 3U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 21772U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneD[((aIndex + 21321U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCross, 43U)) ^ (RotL64(aCarry, 57U) + RotL64(aPrevious, 20U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterJ = (aWandererI + RotL64(aCross, 37U)) + 7948891781097675369U;
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 12U)) + RotL64(aCarry, 57U)) + 13928362874228230226U;
            aOrbiterA = (aWandererG + RotL64(aIngress, 41U)) + 10776180542602258926U;
            aOrbiterB = (aWandererF + RotL64(aScatter, 5U)) + 5735115172149470447U;
            aOrbiterG = (aWandererH + RotL64(aCross, 21U)) + 5353591822981766987U;
            aOrbiterI = (aWandererC + RotL64(aScatter, 43U)) + 562301708107268570U;
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 39U)) + 10467810247578364868U) + aPhaseFOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = ((aWandererK + RotL64(aIngress, 60U)) + 14541630141152308564U) + RotL64(aNonceWordF, 29U);
            aOrbiterF = ((aWandererD + RotL64(aCross, 29U)) + RotL64(aCarry, 37U)) + 2350076897065139429U;
            aOrbiterD = ((aWandererA + RotL64(aScatter, 19U)) + 17519109078651162228U) + aPhaseFOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = (((aWandererJ + RotL64(aIngress, 27U)) + RotL64(aCarry, 43U)) + 6061035173339902910U) + RotL64(aNonceWordG, 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 15654836633731000065U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 13723521735153718904U;
            aOrbiterA = RotL64((aOrbiterA * 14459516479283070563U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 2849680038315532197U) + RotL64(aNonceWordB, 24U);
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 17336102435576647923U;
            aOrbiterG = RotL64((aOrbiterG * 10984689101753586739U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 7671010488872356142U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 11485114338165600777U;
            aOrbiterI = RotL64((aOrbiterI * 4162584865462407791U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 8759060657343458985U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 11009137869375286581U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8741417343929809115U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 15792999392743144135U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 6180808423175992479U;
            aOrbiterK = RotL64((aOrbiterK * 13681230339693676907U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 361487389591183005U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 15292753806514404853U;
            aOrbiterF = RotL64((aOrbiterF * 17478232597253311153U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 14929153438443362045U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 7904556383593914086U;
            aOrbiterD = RotL64((aOrbiterD * 2484130486635511403U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 3793180909904286848U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 10391957637467171320U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 505484041943467117U), 37U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 11648765065563798353U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 17601185776537566611U;
            aOrbiterJ = RotL64((aOrbiterJ * 4753179291885740011U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 2907499704986356444U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 17048858067202291241U) ^ RotL64(aNonceWordH, 25U);
            aOrbiterE = RotL64((aOrbiterE * 2607549567999666889U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 4340465159886930775U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 7948891781097675369U;
            aOrbiterB = RotL64((aOrbiterB * 12913104720552907335U), 29U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterA, 56U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 3U));
            aIngress = aIngress + (RotL64(aOrbiterH, 29U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterF, 51U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterC, 5U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterI, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 58U) + RotL64(aOrbiterC, 13U)) + aOrbiterJ);
            aWandererG = aWandererG + ((((RotL64(aIngress, 43U) + RotL64(aOrbiterB, 27U)) + aOrbiterE) + RotL64(aNonceWordA, 19U)) + aPhaseFWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 21U) + aOrbiterD) + RotL64(aOrbiterH, 3U));
            aWandererC = aWandererC + (((RotL64(aScatter, 19U) + RotL64(aOrbiterC, 29U)) + aOrbiterI) + RotL64(aNonceWordD, 5U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 13U) + aOrbiterG) + RotL64(aOrbiterI, 23U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 47U) + aOrbiterC) + RotL64(aOrbiterD, 5U)) + RotL64(aCarry, 11U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterB, 44U)) + aOrbiterF) + aPhaseFWandererUpdateSaltD[((aIndex + 15U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 11U) + aOrbiterF) + RotL64(aOrbiterK, 35U)) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 37U) + aOrbiterJ) + RotL64(aOrbiterA, 47U));
            aWandererE = aWandererE + ((RotL64(aCross, 39U) + RotL64(aOrbiterD, 51U)) + aOrbiterA);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 34U) + aOrbiterG) + RotL64(aOrbiterE, 54U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 6U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (RotL64(aWandererH, 39U) ^ aWandererI);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + RotL64(aWandererF, 23U);
            aCarry = aCarry + RotL64(aIngress, 14U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 35U) ^ RotL64(aNonceWordG, 43U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 23765U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24096U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 3U) ^ RotL64(aNonceWordB, 58U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 24275U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 26709U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 43U) ^ RotL64(aIngress, 57U)) + (RotL64(aPrevious, 5U) + RotL64(aCross, 28U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterK = (aWandererH + RotL64(aPrevious, 37U)) + 13442819395490639310U;
            aOrbiterF = (aWandererE + RotL64(aIngress, 13U)) + 8187292523194120936U;
            aOrbiterA = (aWandererG + RotL64(aScatter, 21U)) + 11469697159823131388U;
            aOrbiterI = ((aWandererA + RotL64(aCross, 24U)) + 13414083692375929653U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = ((((aWandererJ + RotL64(aScatter, 41U)) + RotL64(aCarry, 57U)) + 11404010733687907517U) + aPhaseFOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1]) + RotL64(aNonceWordD, 57U);
            aOrbiterD = ((aWandererK + RotL64(aIngress, 57U)) + RotL64(aCarry, 3U)) + 6783212827186218247U;
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 5U)) + 8561131439340372614U;
            aOrbiterB = ((aWandererD + RotL64(aCross, 19U)) + RotL64(aCarry, 27U)) + 6252609642004429113U;
            aOrbiterC = (aWandererI + RotL64(aPrevious, 3U)) + 12804867444200448952U;
            aOrbiterE = (aWandererB + RotL64(aIngress, 10U)) + 2739648749603690781U;
            aOrbiterH = ((aWandererF + RotL64(aScatter, 27U)) + 14808861217017399752U) + RotL64(aNonceWordH, 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 17588866502571268888U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 5882260142735642980U;
            aOrbiterA = RotL64((aOrbiterA * 7688252946143263869U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 15493099088132862949U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 5175647411532429582U;
            aOrbiterD = RotL64((aOrbiterD * 15226544495598541883U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 14279707376173642767U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 6826363572161275158U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5263708315440161809U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 13267185753040999992U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 9980987858092888720U;
            aOrbiterE = RotL64((aOrbiterE * 13210290848800728635U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 3582972937645514549U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 10140409019562890804U) ^ RotL64(aNonceWordC, 41U);
            aOrbiterK = RotL64((aOrbiterK * 6944490201647678479U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 6160444117287330557U) + RotL64(aNonceWordE, 35U);
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 16344602960561293113U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2319964919335633293U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 3497141036108337171U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 91269118352540308U;
            aOrbiterJ = RotL64((aOrbiterJ * 5160060720189045505U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 12739932748793144857U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 12820180915064791197U;
            aOrbiterC = RotL64((aOrbiterC * 5843849637411948699U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 17572075652083359962U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 10684041099654982701U;
            aOrbiterH = RotL64((aOrbiterH * 7121293375756263771U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 10739534650885677354U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 9731206787727954809U;
            aOrbiterF = RotL64((aOrbiterF * 3730875775588585547U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 9655432616347117764U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 13442819395490639310U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3650859301708619119U), 29U);
            //
            aIngress = RotL64(aOrbiterH, 50U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 13U));
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 5U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 48U));
            aIngress = aIngress + RotL64(aOrbiterD, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aIngress, 34U) + aOrbiterA) + RotL64(aOrbiterJ, 47U)) + RotL64(aCarry, 47U)) + aPhaseFWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterB, 24U)) + aOrbiterF) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 39U) + RotL64(aOrbiterE, 43U)) + aOrbiterK) + RotL64(aCarry, 53U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 41U) + aOrbiterJ) + RotL64(aOrbiterB, 5U)) + RotL64(aNonceWordA, 14U));
            aWandererC = aWandererC + ((RotL64(aScatter, 11U) + RotL64(aOrbiterF, 37U)) + aOrbiterC);
            aWandererF = aWandererF ^ ((RotL64(aCross, 3U) + aOrbiterA) + RotL64(aOrbiterD, 39U));
            aWandererA = aWandererA + ((RotL64(aIngress, 21U) + RotL64(aOrbiterK, 12U)) + aOrbiterC);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterJ, 41U)) + aOrbiterF);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 14U) + aOrbiterH) + RotL64(aOrbiterI, 21U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterG, 51U)) + aOrbiterE) + RotL64(aNonceWordG, 55U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 57U) + aOrbiterI) + RotL64(aOrbiterG, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 44U) ^ aWandererJ);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 21U));
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererB);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 14U));
            aCarry = aCarry + RotL64(aWandererF, 23U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 11U) ^ RotL64(aNonceWordB, 56U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 32383U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneB[((aIndex + 27356U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 11U) ^ RotL64(aNonceWordA, 37U)) ^ RotL64(aNonceWordE, 29U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30123U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneB[((aIndex + 29386U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCross, 37U)) + (RotL64(aCarry, 6U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterC = ((aWandererD + RotL64(aScatter, 57U)) + RotL64(aCarry, 19U)) + 8767379393098711499U;
            aOrbiterJ = ((aWandererE + RotL64(aCross, 27U)) + 7168159491580816433U) + aPhaseFOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = (aWandererA + RotL64(aPrevious, 34U)) + 9879279829061883406U;
            aOrbiterB = (aWandererC + RotL64(aIngress, 11U)) + 10537167136053399303U;
            aOrbiterK = (aWandererB + RotL64(aScatter, 23U)) + 2839070018069188936U;
            aOrbiterE = (aWandererG + RotL64(aCross, 21U)) + 13844278063968429732U;
            aOrbiterH = (aWandererK + RotL64(aPrevious, 29U)) + 11278946626186474646U;
            aOrbiterG = (((aWandererH + RotL64(aIngress, 5U)) + RotL64(aCarry, 37U)) + 11798425216660557799U) + RotL64(aNonceWordC, 61U);
            aOrbiterD = (aWandererI + RotL64(aScatter, 37U)) + 7618446090703335192U;
            aOrbiterF = ((aWandererF + RotL64(aIngress, 60U)) + 695423597006983660U) + RotL64(aNonceWordF, 15U);
            aOrbiterI = (((aWandererJ + RotL64(aPrevious, 3U)) + RotL64(aCarry, 27U)) + 14344728202803488813U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 11656100506575697086U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 10384358779985773937U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 247494692039140973U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 17585001605131977341U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 9964478171465522911U;
            aOrbiterK = RotL64((aOrbiterK * 13484044854790175315U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 2710943171829692624U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 17809072853457153057U;
            aOrbiterE = RotL64((aOrbiterE * 16341884203303271365U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 12814092033910687774U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 1743186323268668740U;
            aOrbiterH = RotL64((aOrbiterH * 11150822630624332557U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 10750472346626754704U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 15925901217078035356U;
            aOrbiterG = RotL64((aOrbiterG * 9276504171291801637U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 2569102106359362359U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 8868261301410769739U;
            aOrbiterD = RotL64((aOrbiterD * 3662495603133918101U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 2143691008373582476U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 10606616796243205921U;
            aOrbiterF = RotL64((aOrbiterF * 15794414817813485643U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 16258070651850746855U) + RotL64(aNonceWordA, 27U);
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 11720192793689633315U;
            aOrbiterI = RotL64((aOrbiterI * 14475623219460678021U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 8230871037292355675U) + RotL64(aNonceWordH, 9U);
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 16898650748046368353U;
            aOrbiterC = RotL64((aOrbiterC * 7368697435476300255U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 9071122174426904737U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 4506737259011736474U;
            aOrbiterJ = RotL64((aOrbiterJ * 11903039808814842447U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 4545409671845718259U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 8767379393098711499U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1210632171306946669U), 19U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterC, 5U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 13U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 37U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 60U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + RotL64(aOrbiterH, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterC, 11U)) + aOrbiterK);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 52U) + aOrbiterF) + RotL64(aOrbiterI, 41U)) + RotL64(aCarry, 3U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterH, 53U)) + aOrbiterF);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 21U) + RotL64(aOrbiterF, 37U)) + aOrbiterK) + RotL64(aCarry, 11U)) + RotL64(aNonceWordD, 3U));
            aWandererK = aWandererK ^ ((((RotL64(aIngress, 19U) + aOrbiterE) + RotL64(aOrbiterD, 34U)) + RotL64(aNonceWordG, 34U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 29U) + RotL64(aOrbiterA, 51U)) + aOrbiterI);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 56U) + RotL64(aOrbiterB, 13U)) + aOrbiterE);
            aWandererG = aWandererG + ((RotL64(aScatter, 35U) + aOrbiterJ) + RotL64(aOrbiterE, 57U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 39U) + aOrbiterC) + RotL64(aOrbiterA, 21U));
            aWandererD = aWandererD + ((RotL64(aCross, 13U) + RotL64(aOrbiterJ, 47U)) + aOrbiterG);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterD, 4U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererI, 48U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + RotL64(aWandererK, 46U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 2558U)) & S_BLOCK1], 30U) ^ RotL64(aKeyRowReadA[((aIndex + 4439U)) & W_KEY1], 51U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 2265U)) & W_KEY1], 4U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 372U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 24U) ^ RotL64(aCarry, 11U)) + (RotL64(aCross, 57U) + RotL64(aIngress, 43U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = ((aWandererH + RotL64(aScatter, 30U)) + 2915859148137000694U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = ((aWandererF + RotL64(aCross, 39U)) + RotL64(aCarry, 47U)) + 210680583721444425U;
            aOrbiterE = ((aWandererE + RotL64(aIngress, 53U)) + RotL64(aCarry, 19U)) + 6668118118775650387U;
            aOrbiterC = (aWandererB + RotL64(aPrevious, 47U)) + 15794200818099010989U;
            aOrbiterH = (aWandererK + RotL64(aIngress, 22U)) + 6565076707062828369U;
            aOrbiterJ = (((aWandererJ + RotL64(aScatter, 57U)) + RotL64(aCarry, 5U)) + 16323164497808856719U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = (aWandererD + RotL64(aPrevious, 3U)) + 7965435318816716560U;
            aOrbiterK = (aWandererA + RotL64(aCross, 35U)) + 7390281030573369017U;
            aOrbiterF = (aWandererG + RotL64(aPrevious, 11U)) + 2269738866911824875U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 9664014216039993873U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 18284857398028357633U;
            aOrbiterE = RotL64((aOrbiterE * 8402008251343393737U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 367667619795303009U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 7935945060956274197U;
            aOrbiterJ = RotL64((aOrbiterJ * 5481786693511955209U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 16683666162337789540U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 10655658270998102390U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15231596813382239841U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 8307037916581540297U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 3247742749860703524U;
            aOrbiterF = RotL64((aOrbiterF * 15052136713218656641U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 10446792483683818139U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 16374602929344972364U;
            aOrbiterA = RotL64((aOrbiterA * 12599903932725787599U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 2411334498322777183U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 1093701164116833765U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13129220206835381729U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 17018480952982840635U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 17348395690080029814U;
            aOrbiterD = RotL64((aOrbiterD * 6212591395713433257U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 16111252311283623152U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 12776492920397785951U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6136009241593081821U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 12214538600808144816U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 10043377462096783363U;
            aOrbiterH = RotL64((aOrbiterH * 14639467375095185877U), 23U);
            //
            aIngress = RotL64(aOrbiterD, 3U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterJ, 24U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterH, 11U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterG, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aPrevious, 5U) + aOrbiterG) + RotL64(aOrbiterJ, 29U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 27U) + aOrbiterH) + RotL64(aOrbiterK, 5U));
            aWandererE = aWandererE + (((RotL64(aIngress, 19U) + aOrbiterF) + RotL64(aOrbiterE, 38U)) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 36U) + RotL64(aOrbiterF, 47U)) + aOrbiterH);
            aWandererH = aWandererH + ((RotL64(aIngress, 23U) + aOrbiterA) + RotL64(aOrbiterF, 21U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 13U) + aOrbiterF) + RotL64(aOrbiterD, 43U)) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 47U) + RotL64(aOrbiterF, 11U)) + aOrbiterC) + RotL64(aCarry, 29U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 41U) + aOrbiterD) + RotL64(aOrbiterG, 58U));
            aWandererA = aWandererA + (((RotL64(aCross, 60U) + aOrbiterJ) + RotL64(aOrbiterE, 51U)) + aPhaseCWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererG, 14U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererF);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + RotL64(aWandererE, 53U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 10010U)) & S_BLOCK1], 40U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 14395U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 9695U)) & W_KEY1], 14U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 9261U)) & W_KEY1], 41U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 36U) + RotL64(aPrevious, 3U)) + (RotL64(aCross, 19U) ^ RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = (aWandererG + RotL64(aScatter, 57U)) + 3561491146322798260U;
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 46U)) + 7075025056181885339U) + aPhaseCOrbiterAssignSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = (aWandererD + RotL64(aCross, 5U)) + 9230910887904171613U;
            aOrbiterB = ((aWandererK + RotL64(aIngress, 53U)) + RotL64(aCarry, 51U)) + 4119781172609908917U;
            aOrbiterH = (aWandererI + RotL64(aScatter, 23U)) + 17155609083870983149U;
            aOrbiterD = (aWandererF + RotL64(aIngress, 13U)) + 2423018561430181695U;
            aOrbiterC = (aWandererE + RotL64(aCross, 19U)) + 12957280305617615744U;
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 28U)) + RotL64(aCarry, 19U)) + 2461704174772065813U;
            aOrbiterE = (((aWandererA + RotL64(aCross, 37U)) + RotL64(aCarry, 35U)) + 7907123257849391997U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 7257868138318960007U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 16425903703085702285U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7996935869077231999U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 2990822664594079467U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 5654819006718953817U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4465096036756887801U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 12183676471235678779U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 15026286960542123922U;
            aOrbiterC = RotL64((aOrbiterC * 17199049329995315279U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 12169080607071830522U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 2906296852254787499U;
            aOrbiterJ = RotL64((aOrbiterJ * 6754514406846040163U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 3029858695410344584U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 14406410317495954566U;
            aOrbiterE = RotL64((aOrbiterE * 9663780721657983421U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 11048818178401163861U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 13622063920319445043U;
            aOrbiterF = RotL64((aOrbiterF * 2516025554421589857U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 2642646089141233277U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 12761571777929273548U;
            aOrbiterB = RotL64((aOrbiterB * 5518252696078700127U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 7753802695131502382U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 8510425459525030222U;
            aOrbiterD = RotL64((aOrbiterD * 12412361423636026483U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 13522645164493316722U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 1437430302489702713U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14019316635365783545U), 29U);
            //
            aIngress = RotL64(aOrbiterB, 23U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 57U));
            aIngress = aIngress + (RotL64(aOrbiterF, 60U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 37U));
            aIngress = aIngress + RotL64(aOrbiterH, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 23U) + aOrbiterJ) + RotL64(aOrbiterA, 43U)) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 35U) + RotL64(aOrbiterF, 56U)) + aOrbiterA);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 27U) + aOrbiterF) + RotL64(aOrbiterD, 47U));
            aWandererD = aWandererD + ((RotL64(aCross, 6U) + RotL64(aOrbiterB, 21U)) + aOrbiterE);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterC, 35U)) + aOrbiterJ);
            aWandererF = aWandererF + (((RotL64(aIngress, 47U) + aOrbiterH) + RotL64(aOrbiterJ, 39U)) + RotL64(aCarry, 21U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterG, 51U)) + aOrbiterF);
            aWandererG = aWandererG + ((((RotL64(aCross, 18U) + aOrbiterD) + RotL64(aOrbiterE, 6U)) + RotL64(aCarry, 5U)) + aPhaseCWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterH, 11U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 40U));
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererA, 43U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22492U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneA[((aIndex + 19729U)) & S_BLOCK1], 30U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 17482U)) & W_KEY1], 5U) ^ RotL64(aKeyRowReadB[((aIndex + 22059U)) & W_KEY1], 44U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 56U) + RotL64(aCross, 43U)) ^ (RotL64(aIngress, 29U) ^ RotL64(aCarry, 13U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 46U)) + RotL64(aCarry, 13U)) + 898812731947995389U;
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 23U)) + 8677347622525527167U;
            aOrbiterD = (aWandererB + RotL64(aCross, 39U)) + 770321564027567654U;
            aOrbiterF = (((aWandererI + RotL64(aScatter, 35U)) + RotL64(aCarry, 41U)) + 11020474858081526395U) + aPhaseCOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = (aWandererD + RotL64(aIngress, 11U)) + 17289793580414993470U;
            aOrbiterK = (aWandererH + RotL64(aCross, 27U)) + 10111912559295118444U;
            aOrbiterC = ((aWandererG + RotL64(aPrevious, 60U)) + 8083622125544542011U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = (aWandererA + RotL64(aScatter, 3U)) + 7149858558922988240U;
            aOrbiterG = ((aWandererE + RotL64(aIngress, 51U)) + RotL64(aCarry, 3U)) + 5919683821379905699U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 6860902846079238714U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 15083517836867542075U;
            aOrbiterD = RotL64((aOrbiterD * 4686657139237578325U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 14852868368708376381U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 9860233289028878323U;
            aOrbiterA = RotL64((aOrbiterA * 13418143547952204667U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 772406119079116272U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 7971141501337627589U;
            aOrbiterF = RotL64((aOrbiterF * 10168120622976358617U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 8478568022896691911U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 4027604850785607101U;
            aOrbiterJ = RotL64((aOrbiterJ * 4826627523578901467U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 17199331557841535430U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 7515957656979776361U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5468950152869656599U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 17138249294921502391U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 16236812863923234668U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2925542836624164807U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 16941524155859123682U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 11240343728857342866U;
            aOrbiterC = RotL64((aOrbiterC * 7281012444214294659U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 15163914964139858328U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 6673576554415729652U;
            aOrbiterI = RotL64((aOrbiterI * 1558880328574736975U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 5399050402101642989U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 11806006719060024615U;
            aOrbiterG = RotL64((aOrbiterG * 15782156615926092159U), 3U);
            //
            aIngress = RotL64(aOrbiterD, 35U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterC, 19U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterF, 41U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterI, 38U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterG, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aScatter, 52U) + aOrbiterA) + RotL64(aOrbiterB, 23U)) + aPhaseCWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 29U) + RotL64(aOrbiterK, 19U)) + aOrbiterI) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterF, 43U)) + aOrbiterJ);
            aWandererI = aWandererI + ((RotL64(aCross, 35U) + RotL64(aOrbiterC, 47U)) + aOrbiterI);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 11U) + aOrbiterA) + RotL64(aOrbiterJ, 10U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterD, 29U)) + aOrbiterI) + RotL64(aCarry, 5U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 57U) + aOrbiterC) + RotL64(aOrbiterG, 39U));
            aWandererK = aWandererK + (((RotL64(aCross, 42U) + aOrbiterB) + RotL64(aOrbiterF, 3U)) + RotL64(aCarry, 41U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 23U) + aOrbiterA) + RotL64(aOrbiterG, 52U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererA);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 10U));
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererJ, 57U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 31912U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28451U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25704U)) & S_BLOCK1], 14U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 26761U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aPrevious, 3U)) + (RotL64(aIngress, 24U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = (aWandererC + RotL64(aScatter, 43U)) + 3612110001869385068U;
            aOrbiterJ = (((aWandererF + RotL64(aCross, 37U)) + RotL64(aCarry, 35U)) + 16340824141280225936U) + aPhaseCOrbiterAssignSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = ((aWandererB + RotL64(aIngress, 56U)) + RotL64(aCarry, 3U)) + 15222338965130765231U;
            aOrbiterH = (aWandererK + RotL64(aPrevious, 47U)) + 6649270508107155041U;
            aOrbiterG = ((aWandererH + RotL64(aScatter, 51U)) + RotL64(aCarry, 43U)) + 768217258655426384U;
            aOrbiterC = (aWandererJ + RotL64(aIngress, 29U)) + 4481855259658861851U;
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 6U)) + 18318041934562434016U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = (aWandererA + RotL64(aCross, 13U)) + 4212457153804401807U;
            aOrbiterD = (aWandererE + RotL64(aScatter, 23U)) + 16143621095636987628U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 2095664232866642086U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 4339527736737366572U;
            aOrbiterK = RotL64((aOrbiterK * 17503569508822244125U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 13679353177869884790U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 11582168502846418236U;
            aOrbiterG = RotL64((aOrbiterG * 135539430034462861U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 10451330452898542191U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 12951448817640617841U;
            aOrbiterE = RotL64((aOrbiterE * 4141870904192742091U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 15389161934419370747U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 4754886272708253014U;
            aOrbiterI = RotL64((aOrbiterI * 16638243718191281597U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 11746389873929280688U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 12042680172517298768U;
            aOrbiterH = RotL64((aOrbiterH * 3814780289755857543U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 2648103752465009244U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 451594673632597973U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8496763663271072425U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 5696534794094099710U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 14609435045257077395U;
            aOrbiterF = RotL64((aOrbiterF * 14658408563237468407U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 11599395126850950133U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 12699598504604446664U;
            aOrbiterD = RotL64((aOrbiterD * 14313494063098111823U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 9398465148537154745U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 12139736860648011256U;
            aOrbiterJ = RotL64((aOrbiterJ * 15257503229375247987U), 57U);
            //
            aIngress = RotL64(aOrbiterH, 18U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterJ, 29U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 39U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 53U));
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 51U) + aOrbiterF) + RotL64(aOrbiterK, 29U)) + aPhaseCWandererUpdateSaltD[((aIndex + 18U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 5U) + RotL64(aOrbiterK, 36U)) + aOrbiterC) + aPhaseCWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 24U) + RotL64(aOrbiterD, 51U)) + aOrbiterE);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 47U) + aOrbiterG) + RotL64(aOrbiterC, 19U)) + RotL64(aCarry, 23U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 43U) + aOrbiterH) + RotL64(aOrbiterG, 3U));
            aWandererH = aWandererH + ((RotL64(aScatter, 11U) + aOrbiterC) + RotL64(aOrbiterI, 23U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 35U) + aOrbiterI) + RotL64(aOrbiterJ, 47U));
            aWandererK = aWandererK + (((RotL64(aCross, 28U) + RotL64(aOrbiterG, 60U)) + aOrbiterD) + RotL64(aCarry, 3U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterF, 13U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererK, 34U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererA, 57U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterJ = 0;
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 311U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneC[((aIndex + 7823U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4694U)) & S_BLOCK1], 40U) ^ RotL64(aExpandLaneA[((aIndex + 6227U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 58U) ^ RotL64(aIngress, 27U)) + (RotL64(aPrevious, 11U) + RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 21U)) + RotL64(aCarry, 57U)) + 5510690816044082200U;
            aOrbiterH = (((aWandererE + RotL64(aCross, 38U)) + RotL64(aCarry, 43U)) + 15967820875033940530U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = ((aWandererH + RotL64(aScatter, 53U)) + RotL64(aCarry, 13U)) + 539348720848176221U;
            aOrbiterJ = (aWandererG + RotL64(aIngress, 5U)) + 15779318183635560817U;
            aOrbiterK = ((aWandererK + RotL64(aCross, 13U)) + 14511058534424187469U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 5811130556873428391U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 1085928476499444025U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13965845678632598921U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 6973335316600768130U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 10747243745475009744U;
            aOrbiterG = RotL64((aOrbiterG * 17322489216048017061U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 1072260008981349754U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 2018772405352495753U;
            aOrbiterJ = RotL64((aOrbiterJ * 10840562112080574241U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 1092091597048996547U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 15103140149542167197U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 621856991658027989U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 13194619321108681542U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 16749188603268621850U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9575408950550922039U), 13U);
            //
            aIngress = RotL64(aOrbiterG, 23U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterJ, 35U)) + aOrbiterG) + RotL64(aCarry, 13U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 21U) + aOrbiterH) + RotL64(aOrbiterJ, 51U)) + aPhaseDWandererUpdateSaltF[((aIndex + 14U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 56U) + aOrbiterB) + RotL64(aOrbiterJ, 43U)) + RotL64(aCarry, 27U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 3U) + aOrbiterB) + RotL64(aOrbiterK, 23U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterB, 6U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 37U));
            aCarry = aCarry + RotL64(aWandererH, 29U);
            aCarry = aCarry + RotL64(aIngress, 48U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 10929U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 9043U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 13548U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneB[((aIndex + 11279U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 37U) ^ RotL64(aCross, 23U)) + (RotL64(aCarry, 51U) + RotL64(aPrevious, 4U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = ((aWandererJ + RotL64(aCross, 23U)) + RotL64(aCarry, 19U)) + 10726035965553989335U;
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 4U)) + 967354339530195662U) + aPhaseDOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = (aWandererF + RotL64(aIngress, 13U)) + 10834593005478605624U;
            aOrbiterH = ((aWandererE + RotL64(aScatter, 37U)) + RotL64(aCarry, 57U)) + 1012888282838656933U;
            aOrbiterG = (((aWandererI + RotL64(aIngress, 53U)) + RotL64(aCarry, 37U)) + 15283530351725183253U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 11724495956731703750U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 4288330117317505776U;
            aOrbiterF = RotL64((aOrbiterF * 2738997410474076757U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 10894778070022873473U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 15563886747621617467U;
            aOrbiterG = RotL64((aOrbiterG * 17884709931569040065U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 11182488628562891937U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 10420140066310588580U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13898299782819948719U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 11775138062167543111U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 16545391898578161683U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14588306527161321535U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 1550144656312299266U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 14903504853138279883U;
            aOrbiterH = RotL64((aOrbiterH * 8003033561266164387U), 3U);
            //
            aIngress = RotL64(aOrbiterD, 57U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterG, 5U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterA, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aIngress, 35U) + RotL64(aOrbiterD, 3U)) + aOrbiterA);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 3U) + aOrbiterF) + RotL64(aOrbiterH, 35U)) + aPhaseDWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 57U) + aOrbiterF) + RotL64(aOrbiterG, 56U)) + RotL64(aCarry, 19U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterA, 11U)) + aOrbiterH) + aPhaseDWandererUpdateSaltE[((aIndex + 26U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 20U) + aOrbiterA) + RotL64(aOrbiterG, 47U)) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + (RotL64(aWandererA, 14U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 22221U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 20349U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18190U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 20428U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 37U) ^ RotL64(aPrevious, 50U)) ^ (RotL64(aIngress, 5U) + RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = (aWandererK + RotL64(aIngress, 3U)) + 5171470532667965920U;
            aOrbiterK = ((aWandererH + RotL64(aCross, 18U)) + RotL64(aCarry, 23U)) + 750549462358682403U;
            aOrbiterB = ((aWandererF + RotL64(aScatter, 51U)) + 3325689257577120525U) + aPhaseDOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = (((aWandererJ + RotL64(aPrevious, 27U)) + RotL64(aCarry, 5U)) + 18031575461559790826U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = ((aWandererA + RotL64(aScatter, 41U)) + RotL64(aCarry, 41U)) + 13874739537012288677U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 4250029868785016865U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 8211158803112611161U;
            aOrbiterB = RotL64((aOrbiterB * 9205801383408193959U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 1083939790236786027U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 3446525462376962464U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13603702473750888213U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 6973817815000417325U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 15230876489676945543U;
            aOrbiterH = RotL64((aOrbiterH * 7737039082964537651U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 9359727659738755880U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 8775170107816327654U;
            aOrbiterA = RotL64((aOrbiterA * 6910680458261008653U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 11958941755525038545U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 16966819714283167348U;
            aOrbiterC = RotL64((aOrbiterC * 16363457661846050749U), 11U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterC, 39U);
            aIngress = aIngress + (RotL64(aOrbiterB, 23U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterA, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aIngress, 3U) + aOrbiterB) + RotL64(aOrbiterC, 39U)) + RotL64(aCarry, 51U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 11U) + aOrbiterB) + RotL64(aOrbiterK, 4U)) + aPhaseDWandererUpdateSaltA[((aIndex + 6U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 21U) + RotL64(aOrbiterA, 23U)) + aOrbiterB) + RotL64(aCarry, 11U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 50U) + aOrbiterA) + RotL64(aOrbiterH, 13U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 41U) + aOrbiterH) + RotL64(aOrbiterK, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 38U) ^ aWandererA);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + RotL64(aWandererJ, 53U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 32024U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29828U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 24791U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 27877U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 29U) + RotL64(aIngress, 41U)) ^ (RotL64(aCarry, 58U) ^ RotL64(aPrevious, 13U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = (((aWandererJ + RotL64(aPrevious, 4U)) + RotL64(aCarry, 27U)) + 12262991801139086177U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = (aWandererF + RotL64(aIngress, 27U)) + 7963038771924890197U;
            aOrbiterD = ((aWandererH + RotL64(aScatter, 35U)) + RotL64(aCarry, 5U)) + 15540520327933568896U;
            aOrbiterJ = ((aWandererI + RotL64(aCross, 13U)) + RotL64(aCarry, 53U)) + 8745565892055020722U;
            aOrbiterK = ((aWandererB + RotL64(aIngress, 53U)) + 16619329199683755286U) + aPhaseDOrbiterAssignSaltB[((aIndex + 16U)) & S_SALT1];
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 10865705026433867260U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 2743368697984518059U;
            aOrbiterD = RotL64((aOrbiterD * 2989232417816919375U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 5556006271515473135U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 5355833281353498588U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4190140212757841511U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 8313616108963479829U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 16657121016801866434U;
            aOrbiterJ = RotL64((aOrbiterJ * 331533349428472477U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 16532226425013000833U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 5800465874932467232U;
            aOrbiterG = RotL64((aOrbiterG * 5966395771690704577U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 17882948163883121328U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 15029375310296563175U;
            aOrbiterK = RotL64((aOrbiterK * 17021415832288477713U), 21U);
            //
            aIngress = RotL64(aOrbiterK, 39U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 53U));
            aIngress = aIngress + RotL64(aOrbiterJ, 14U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterJ, 5U)) + aOrbiterK);
            aWandererH = aWandererH + (((RotL64(aIngress, 29U) + aOrbiterG) + RotL64(aOrbiterD, 47U)) + RotL64(aCarry, 5U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterF, 13U)) + aOrbiterK) + aPhaseDWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aScatter, 3U) + aOrbiterJ) + RotL64(aOrbiterD, 39U)) + RotL64(aCarry, 51U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 54U) + aOrbiterK) + RotL64(aOrbiterD, 58U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererI, 12U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 7686U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 8089U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 6398U)) & S_BLOCK1], 48U) ^ RotL64(aOperationLaneA[((aIndex + 1554U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 19U) + RotL64(aCarry, 4U)) + (RotL64(aCross, 53U) ^ RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = (aWandererK + RotL64(aCross, 51U)) + 11177787645248006236U;
            aOrbiterH = ((aWandererI + RotL64(aIngress, 5U)) + RotL64(aCarry, 57U)) + 3808340254579817169U;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 37U)) + RotL64(aCarry, 39U)) + 828030667598518279U;
            aOrbiterB = ((aWandererH + RotL64(aScatter, 29U)) + 16177835921238398371U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = (aWandererD + RotL64(aCross, 14U)) + 5518747735458708741U;
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 57U)) + 17346319082399995165U;
            aOrbiterA = (((aWandererG + RotL64(aScatter, 23U)) + RotL64(aCarry, 11U)) + 6397156921893030937U) + aPhaseEOrbiterAssignSaltD[((aIndex + 24U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 15559381654710713582U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 940404446491415088U;
            aOrbiterG = RotL64((aOrbiterG * 16401260971303026881U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 8047166032048732645U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 4688468645859470491U;
            aOrbiterK = RotL64((aOrbiterK * 14383536431614496369U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 3710878044770337260U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 116343189456629220U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5637725064169289339U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 883908030159391659U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 18058691521694880482U;
            aOrbiterA = RotL64((aOrbiterA * 3132200449123497619U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 17521015077103586117U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 3668332225435714918U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12658899101297839881U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 12229480388278883300U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 16206524049491531816U;
            aOrbiterB = RotL64((aOrbiterB * 11122340196620859805U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 5743265849441077466U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 2812293020719282236U;
            aOrbiterH = RotL64((aOrbiterH * 8903956475200417109U), 37U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterA, 13U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 53U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 43U));
            aIngress = aIngress + RotL64(aOrbiterJ, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterA, 35U)) + aOrbiterH) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aPrevious, 27U) + aOrbiterG) + RotL64(aOrbiterD, 53U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterK, 27U)) + aOrbiterB);
            aWandererD = aWandererD + (((RotL64(aScatter, 58U) + aOrbiterB) + RotL64(aOrbiterJ, 3U)) + RotL64(aCarry, 41U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterA, 46U)) + aOrbiterG);
            aWandererG = aWandererG + ((((RotL64(aCross, 51U) + aOrbiterD) + RotL64(aOrbiterH, 19U)) + RotL64(aCarry, 3U)) + aPhaseEWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 11U) + aOrbiterH) + RotL64(aOrbiterK, 13U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 10U));
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererD, 19U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 14164U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 10302U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 10719U)) & S_BLOCK1], 52U) ^ RotL64(aOperationLaneB[((aIndex + 8422U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 26U) ^ RotL64(aCarry, 11U)) + (RotL64(aCross, 57U) + RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = (aWandererC + RotL64(aScatter, 58U)) + 2168513956284366370U;
            aOrbiterF = ((aWandererK + RotL64(aCross, 11U)) + RotL64(aCarry, 41U)) + 10290361969974613111U;
            aOrbiterK = ((aWandererH + RotL64(aIngress, 37U)) + 15673836275828498050U) + aPhaseEOrbiterAssignSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = (aWandererE + RotL64(aPrevious, 19U)) + 16600540024145812236U;
            aOrbiterE = ((aWandererI + RotL64(aIngress, 43U)) + RotL64(aCarry, 27U)) + 9428052101528111892U;
            aOrbiterJ = (((aWandererG + RotL64(aScatter, 27U)) + RotL64(aCarry, 11U)) + 12763657928312763377U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = (aWandererB + RotL64(aCross, 3U)) + 10751286982008662485U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 1708230173038057979U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 4011389705422783816U;
            aOrbiterK = RotL64((aOrbiterK * 11692237130784795961U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 11704428328093077714U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 2055336619674699284U;
            aOrbiterB = RotL64((aOrbiterB * 6374289210096410907U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 1870865272102705804U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 3574214263751923179U;
            aOrbiterA = RotL64((aOrbiterA * 13132083406834413563U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 984611970726966186U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 15207945449947643672U;
            aOrbiterF = RotL64((aOrbiterF * 9539470161576639981U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 4181398506373973169U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 15222345431506025949U;
            aOrbiterE = RotL64((aOrbiterE * 6925143692628659467U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 15023513452326240962U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 14965669361708810699U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 587008860996713147U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 7985755518735406360U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 225592097619240187U;
            aOrbiterI = RotL64((aOrbiterI * 2313509354133400439U), 11U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterJ, 19U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 11U));
            aIngress = aIngress + RotL64(aOrbiterB, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 43U) + aOrbiterB) + RotL64(aOrbiterI, 57U));
            aWandererC = aWandererC + (((RotL64(aScatter, 57U) + RotL64(aOrbiterK, 27U)) + aOrbiterJ) + RotL64(aCarry, 3U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 18U) + aOrbiterE) + RotL64(aOrbiterF, 43U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 37U) + aOrbiterE) + RotL64(aOrbiterI, 50U)) + RotL64(aCarry, 27U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterK, 3U)) + aOrbiterA);
            aWandererI = aWandererI + (((RotL64(aScatter, 5U) + RotL64(aOrbiterE, 21U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aCross, 11U) + aOrbiterJ) + RotL64(aOrbiterI, 37U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererG, 53U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererC, 48U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 23273U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneA[((aIndex + 24513U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 23727U)) & S_BLOCK1], 46U) ^ RotL64(aOperationLaneC[((aIndex + 19594U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 60U) + RotL64(aPrevious, 23U)) + (RotL64(aIngress, 11U) ^ RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = (((aWandererB + RotL64(aCross, 27U)) + RotL64(aCarry, 3U)) + 12029393034357490020U) + aPhaseEOrbiterAssignSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = (aWandererG + RotL64(aIngress, 21U)) + 4526754731580694987U;
            aOrbiterA = ((aWandererH + RotL64(aScatter, 36U)) + RotL64(aCarry, 39U)) + 17060419646421271853U;
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 11U)) + RotL64(aCarry, 19U)) + 4128488893837059683U;
            aOrbiterI = (aWandererD + RotL64(aScatter, 5U)) + 12706894827547160110U;
            aOrbiterD = (aWandererA + RotL64(aPrevious, 57U)) + 12506324593645825056U;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 51U)) + 12581344490649250025U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 14357032418199130132U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 15341977701796331249U;
            aOrbiterA = RotL64((aOrbiterA * 6332369248718076031U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 7086602307544733241U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 12398300065276832486U;
            aOrbiterB = RotL64((aOrbiterB * 18157408831225635333U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 2499745046076601988U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 7249361592814001829U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14597139848072319685U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 3254456186337366437U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 3472973415969046680U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14583566953969168353U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 7905718972111691591U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 15941413652144021522U;
            aOrbiterI = RotL64((aOrbiterI * 3473779492962783565U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 10583964125960308762U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 13659925272340853715U;
            aOrbiterD = RotL64((aOrbiterD * 16708294803316630743U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 9487054537489454887U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 13287757570441887517U;
            aOrbiterK = RotL64((aOrbiterK * 17351439045329892107U), 3U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterA, 54U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 5U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 35U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterD, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 53U) + aOrbiterA) + RotL64(aOrbiterJ, 13U));
            aWandererK = aWandererK + (((RotL64(aCross, 5U) + aOrbiterK) + RotL64(aOrbiterB, 42U)) + RotL64(aCarry, 13U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterJ, 53U)) + aOrbiterB) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 60U) + RotL64(aOrbiterC, 19U)) + aOrbiterI);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterJ, 3U)) + aOrbiterC) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 19U) + RotL64(aOrbiterI, 27U)) + aOrbiterK) + RotL64(aCarry, 57U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterA, 35U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererB, 13U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererC, 4U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 26145U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((aIndex + 27947U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 30058U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 28936U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCross, 28U)) + (RotL64(aCarry, 43U) ^ RotL64(aIngress, 13U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = (aWandererJ + RotL64(aScatter, 27U)) + 12669015908335980355U;
            aOrbiterG = ((aWandererD + RotL64(aIngress, 60U)) + RotL64(aCarry, 3U)) + 5438715179868613192U;
            aOrbiterB = (((aWandererE + RotL64(aPrevious, 47U)) + RotL64(aCarry, 35U)) + 13172104448184536460U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = (aWandererC + RotL64(aCross, 41U)) + 13421421503244744803U;
            aOrbiterI = (aWandererH + RotL64(aIngress, 19U)) + 13327113302994856582U;
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 5U)) + 4671768205922454413U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterE = ((aWandererI + RotL64(aScatter, 13U)) + RotL64(aCarry, 51U)) + 5355759962838579929U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 6691720614265406851U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 7063906424700911378U;
            aOrbiterB = RotL64((aOrbiterB * 17091734375516280675U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 17328616394166672263U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 1542940602574207068U;
            aOrbiterH = RotL64((aOrbiterH * 8981679306319627975U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 7203866278803132454U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 993485696233139264U;
            aOrbiterG = RotL64((aOrbiterG * 11609009908810366447U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 15659679028507488331U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 18321361454094675842U;
            aOrbiterI = RotL64((aOrbiterI * 3966860765622641843U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 9633319822696783352U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 3496559332232402963U;
            aOrbiterF = RotL64((aOrbiterF * 7772060229838162977U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 1918349708324205526U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 7701088402761359134U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9649485438465644795U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 6006824348814439686U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 18088375375347012557U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12801082943086128385U), 19U);
            //
            aIngress = RotL64(aOrbiterB, 46U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterG, 21U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterK, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 35U) + aOrbiterI) + RotL64(aOrbiterE, 11U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 60U) + aOrbiterH) + RotL64(aOrbiterK, 29U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterG, 47U)) + aOrbiterF) + aPhaseEWandererUpdateSaltD[((aIndex + 20U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterH, 18U)) + aOrbiterF) + RotL64(aCarry, 13U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 5U) + aOrbiterB) + RotL64(aOrbiterK, 53U));
            aWandererB = aWandererB + ((((RotL64(aCross, 29U) + RotL64(aOrbiterG, 3U)) + aOrbiterI) + RotL64(aCarry, 57U)) + aPhaseEWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterE, 35U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererD);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (RotL64(aWandererB, 53U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererC, 34U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 3758U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4923U)) & S_BLOCK1], 42U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 1267U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 855U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aPrevious, 57U)) + (RotL64(aCarry, 36U) + RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = ((aWandererI + RotL64(aIngress, 57U)) + RotL64(aCarry, 5U)) + 8793908991006073956U;
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 3U)) + 2932916283348441943U) + aPhaseFOrbiterAssignSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = (((aWandererK + RotL64(aPrevious, 35U)) + RotL64(aCarry, 51U)) + 11069042087940968262U) + aPhaseFOrbiterAssignSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = ((aWandererE + RotL64(aCross, 11U)) + RotL64(aCarry, 21U)) + 14369628676782894441U;
            aOrbiterA = (aWandererG + RotL64(aScatter, 22U)) + 8602903272780978282U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 3827036107178568820U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 8905245209036772489U;
            aOrbiterI = RotL64((aOrbiterI * 5744017326197157667U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 13331387530760017893U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 9880107580289737823U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10302652857542703753U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 10199619040626900278U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 2466307560891374281U;
            aOrbiterH = RotL64((aOrbiterH * 6295342978834217571U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 13973403407981259448U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 2851460278409385243U;
            aOrbiterK = RotL64((aOrbiterK * 11226902976321781743U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 10365453393815690776U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 2382382358987358791U;
            aOrbiterA = RotL64((aOrbiterA * 481563628980705781U), 3U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterH, 23U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + RotL64(aOrbiterD, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aIngress, 35U) + aOrbiterA) + RotL64(aOrbiterK, 29U)) + RotL64(aCarry, 53U)) + aPhaseFWandererUpdateSaltC[((aIndex + 20U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 57U) + aOrbiterD) + RotL64(aOrbiterA, 3U));
            aWandererI = aWandererI + ((((RotL64(aScatter, 23U) + RotL64(aOrbiterI, 44U)) + aOrbiterA) + RotL64(aCarry, 5U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 4U) + aOrbiterH) + RotL64(aOrbiterK, 11U));
            aWandererE = aWandererE + ((RotL64(aScatter, 43U) + RotL64(aOrbiterA, 57U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + RotL64(aWandererG, 57U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 15723U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16144U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 11871U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 13585U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aPrevious, 3U)) ^ (RotL64(aIngress, 26U) + RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 35U)) + 8375305456876489425U) + aPhaseFOrbiterAssignSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterH = (aWandererC + RotL64(aCross, 27U)) + 16193562952772453047U;
            aOrbiterG = (((aWandererA + RotL64(aIngress, 11U)) + RotL64(aCarry, 41U)) + 18088652458594816223U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = ((aWandererG + RotL64(aScatter, 52U)) + RotL64(aCarry, 29U)) + 767344788620249944U;
            aOrbiterD = ((aWandererI + RotL64(aCross, 43U)) + RotL64(aCarry, 11U)) + 7705194930396368752U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 3829736891311272834U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 9881681671347640061U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14380245087931793021U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 1721196560190164264U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 3002652618388454213U;
            aOrbiterD = RotL64((aOrbiterD * 15289749311593032657U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 9811621464004005202U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 5652598941069986530U;
            aOrbiterK = RotL64((aOrbiterK * 4797973356708091621U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 6250499348327316328U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 16025054277615264530U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16446892258704281903U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 13800298546867243172U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 12256104592865905782U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16983140179497142713U), 29U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterK, 13U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 3U));
            aIngress = aIngress + RotL64(aOrbiterB, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aCross, 29U) + aOrbiterH) + RotL64(aOrbiterB, 43U)) + aPhaseFWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 43U) + aOrbiterH) + RotL64(aOrbiterK, 5U)) + RotL64(aCarry, 23U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 21U) + aOrbiterB) + RotL64(aOrbiterG, 34U));
            aWandererB = aWandererB + ((((RotL64(aScatter, 53U) + RotL64(aOrbiterK, 23U)) + aOrbiterD) + RotL64(aCarry, 35U)) + aPhaseFWandererUpdateSaltF[((aIndex + 18U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 4U) + aOrbiterD) + RotL64(aOrbiterG, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererA);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + RotL64(aWandererB, 35U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 17628U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((aIndex + 19124U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 23505U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneC[((aIndex + 19143U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 47U) ^ RotL64(aCarry, 3U)) + (RotL64(aIngress, 22U) ^ RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = (aWandererC + RotL64(aScatter, 39U)) + 4751694786009671052U;
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 21U)) + RotL64(aCarry, 43U)) + 16362725160370844224U;
            aOrbiterI = (((aWandererJ + RotL64(aIngress, 11U)) + RotL64(aCarry, 27U)) + 6360885380915941057U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterJ = ((aWandererE + RotL64(aCross, 48U)) + RotL64(aCarry, 57U)) + 5154536007972297036U;
            aOrbiterE = ((aWandererG + RotL64(aScatter, 3U)) + 9362540581874808253U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 13902493871525612934U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 10208452885367546542U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12067703239567933105U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 3117030377279160998U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 17286247690414027870U;
            aOrbiterB = RotL64((aOrbiterB * 4896931759653832095U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 3930314320040949141U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 7289525252391668404U;
            aOrbiterC = RotL64((aOrbiterC * 15452162299105112187U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 3434167955466809185U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 17852573095128575663U;
            aOrbiterJ = RotL64((aOrbiterJ * 1485660158767033425U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 6137259687928853253U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 13992510605237574698U;
            aOrbiterE = RotL64((aOrbiterE * 15346263295995333395U), 29U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 57U);
            aIngress = aIngress + (RotL64(aOrbiterE, 22U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterC, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aIngress, 37U) + RotL64(aOrbiterI, 47U)) + aOrbiterJ) + RotL64(aCarry, 53U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterB, 3U)) + aOrbiterC);
            aWandererK = aWandererK + ((((RotL64(aCross, 57U) + RotL64(aOrbiterI, 22U)) + aOrbiterE) + RotL64(aCarry, 19U)) + aPhaseFWandererUpdateSaltD[((aIndex + 8U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 4U) + RotL64(aOrbiterC, 11U)) + aOrbiterJ);
            aWandererC = aWandererC + (((RotL64(aIngress, 13U) + RotL64(aOrbiterJ, 37U)) + aOrbiterE) + aPhaseFWandererUpdateSaltA[((aIndex + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 41U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 25339U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31080U)) & S_BLOCK1], 42U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 28766U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 29707U)) & S_BLOCK1], 44U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 58U) ^ RotL64(aIngress, 27U)) + (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = (aWandererK + RotL64(aScatter, 13U)) + 2974056819475622600U;
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 3U)) + RotL64(aCarry, 5U)) + 7345051759236356098U;
            aOrbiterG = (aWandererF + RotL64(aCross, 47U)) + 12738468816846628882U;
            aOrbiterC = (((aWandererG + RotL64(aIngress, 30U)) + RotL64(aCarry, 21U)) + 7694520596043297922U) + aPhaseFOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = (((aWandererJ + RotL64(aCross, 21U)) + RotL64(aCarry, 47U)) + 5530753590015084774U) + aPhaseFOrbiterAssignSaltA[((aIndex + 10U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 3776309161718383105U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 784780304358106404U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1503119308251871519U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 8999942326995036509U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 5194986506064092779U;
            aOrbiterF = RotL64((aOrbiterF * 15070787038006135963U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 7920040007459652762U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 11311997270710107937U;
            aOrbiterC = RotL64((aOrbiterC * 6227571709361790209U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 5365231114813547251U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 8630110234623825263U;
            aOrbiterD = RotL64((aOrbiterD * 2735881715888325759U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 2358235238039571072U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 18059414891616491807U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17150786106857185467U), 53U);
            //
            aIngress = RotL64(aOrbiterG, 23U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterD, 54U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterC, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aCross, 27U) + RotL64(aOrbiterD, 42U)) + aOrbiterG) + aPhaseFWandererUpdateSaltB[((aIndex + 22U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterG, 21U)) + aOrbiterC);
            aWandererH = aWandererH + (((RotL64(aIngress, 57U) + aOrbiterK) + RotL64(aOrbiterF, 11U)) + RotL64(aCarry, 23U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 18U) + RotL64(aOrbiterK, 53U)) + aOrbiterC);
            aWandererG = aWandererG + ((((RotL64(aCross, 37U) + aOrbiterD) + RotL64(aOrbiterF, 29U)) + RotL64(aCarry, 35U)) + aPhaseFWandererUpdateSaltC[((aIndex + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererG, 11U);
            aCarry = aCarry + RotL64(aIngress, 28U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 6050U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 34U)) & S_BLOCK1], 26U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 839U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneD[((aIndex + 4268U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 3U) + RotL64(aIngress, 50U)) + (RotL64(aPrevious, 37U) ^ RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 5U)) + RotL64(aCarry, 19U)) + 5568146815535263910U;
            aOrbiterG = ((aWandererC + RotL64(aIngress, 51U)) + 7736084960873834666U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = (((aWandererH + RotL64(aCross, 29U)) + RotL64(aCarry, 5U)) + 1336413621817562093U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = ((aWandererB + RotL64(aScatter, 20U)) + RotL64(aCarry, 43U)) + 5218462026934984692U;
            aOrbiterK = (aWandererA + RotL64(aIngress, 39U)) + 7048890985969555935U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 13415955213864702118U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 5657023257021528548U;
            aOrbiterD = RotL64((aOrbiterD * 5200798937081797819U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 14338310943137497116U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 12305161641833950473U;
            aOrbiterE = RotL64((aOrbiterE * 11949964304435964395U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 14514226578370459131U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 12692904083266024340U;
            aOrbiterF = RotL64((aOrbiterF * 14800805065279908839U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 11012959130001327964U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 7106471380403489078U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 515626559384817223U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 3718101961355280891U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 13364192077222322664U;
            aOrbiterK = RotL64((aOrbiterK * 1411328915372590283U), 39U);
            //
            aIngress = RotL64(aOrbiterD, 24U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 13U));
            aIngress = aIngress + RotL64(aOrbiterK, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 58U) + RotL64(aOrbiterG, 58U)) + aOrbiterF);
            aWandererC = aWandererC + (((RotL64(aCross, 5U) + aOrbiterD) + RotL64(aOrbiterK, 11U)) + RotL64(aCarry, 39U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 29U) + aOrbiterK) + RotL64(aOrbiterE, 29U)) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aIngress, 13U) + RotL64(aOrbiterE, 41U)) + aOrbiterD) + RotL64(aCarry, 3U)) + aPhaseGWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 39U) + aOrbiterG) + RotL64(aOrbiterK, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 27U) ^ aWandererJ);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + RotL64(aWandererB, 47U);
            aCarry = aCarry + RotL64(aIngress, 36U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 8229U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 16146U)) & S_BLOCK1], 36U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 13090U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 10737U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 23U)) + (RotL64(aIngress, 53U) + RotL64(aCross, 40U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = ((aWandererH + RotL64(aScatter, 26U)) + RotL64(aCarry, 13U)) + 18180797995100240808U;
            aOrbiterJ = ((aWandererD + RotL64(aCross, 13U)) + RotL64(aCarry, 57U)) + 6585906608223552885U;
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 47U)) + 14088708930575939855U) + aPhaseGOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = ((aWandererC + RotL64(aIngress, 3U)) + RotL64(aCarry, 27U)) + 468974153311516044U;
            aOrbiterD = ((aWandererI + RotL64(aScatter, 57U)) + 12481951025619894110U) + aPhaseGOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 17227987923860711763U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 4373962756657477139U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6069068316234356267U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 2077576476565420951U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 17435011300234663764U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8910133867294004711U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 4118039398293246896U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 13724716599855216683U;
            aOrbiterC = RotL64((aOrbiterC * 17556333902751079677U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 12391461204689596339U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 9900605191533799627U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13553565332531046301U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 972946858824366125U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 17247681919694541215U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2974639094630445643U), 27U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterJ, 47U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + RotL64(aOrbiterE, 24U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aPrevious, 48U) + aOrbiterC) + RotL64(aOrbiterE, 35U)) + RotL64(aCarry, 5U)) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 37U) + aOrbiterJ) + RotL64(aOrbiterE, 51U));
            aWandererC = aWandererC + ((((RotL64(aScatter, 13U) + aOrbiterF) + RotL64(aOrbiterE, 4U)) + RotL64(aCarry, 29U)) + aPhaseGWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterD, 19U)) + aOrbiterF);
            aWandererH = aWandererH + ((RotL64(aScatter, 29U) + aOrbiterC) + RotL64(aOrbiterJ, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererD);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + RotL64(aWandererH, 48U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 20888U)) & S_BLOCK1], 52U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 21531U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 20180U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 17577U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 58U) + RotL64(aPrevious, 23U)) ^ (RotL64(aIngress, 11U) ^ RotL64(aCross, 43U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = (((aWandererD + RotL64(aScatter, 5U)) + RotL64(aCarry, 39U)) + 15920462086654025436U) + aPhaseGOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 13U)) + RotL64(aCarry, 53U)) + 487844076858004017U;
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 23U)) + RotL64(aCarry, 19U)) + 14502883786442630566U;
            aOrbiterK = ((aWandererF + RotL64(aCross, 57U)) + 3787107318658233674U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = (aWandererB + RotL64(aPrevious, 42U)) + 12548777544693755491U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 4907309444075181683U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 18342396700266492072U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14842961036061482089U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 13503051997624242670U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 17845742460521374571U;
            aOrbiterC = RotL64((aOrbiterC * 1366356786138085155U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 8640887211877858169U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 5273913123709097537U;
            aOrbiterA = RotL64((aOrbiterA * 1661149444148461791U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 17756844173695563883U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 6713055830729302951U;
            aOrbiterK = RotL64((aOrbiterK * 2832836748513174311U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 5106468334224035972U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 10228769728713526172U;
            aOrbiterH = RotL64((aOrbiterH * 9760310686414358435U), 35U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterK, 43U);
            aIngress = aIngress + (RotL64(aOrbiterF, 53U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterA, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aCross, 27U) + aOrbiterA) + RotL64(aOrbiterK, 11U)) + RotL64(aCarry, 23U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 60U) + aOrbiterC) + RotL64(aOrbiterF, 58U)) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterC, 3U)) + aOrbiterA) + RotL64(aCarry, 53U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 13U) + aOrbiterF) + RotL64(aOrbiterH, 21U)) + aPhaseGWandererUpdateSaltD[((aIndex + 24U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aPrevious, 41U) + aOrbiterC) + RotL64(aOrbiterH, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + RotL64(aWandererF, 3U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 28506U)) & S_BLOCK1], 44U) ^ RotL64(aExpandLaneA[((aIndex + 29973U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30105U)) & S_BLOCK1], 36U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 32263U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 20U) + RotL64(aCross, 5U)) ^ (RotL64(aCarry, 53U) + RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 48U)) + RotL64(aCarry, 47U)) + 10915618884692072446U;
            aOrbiterH = ((aWandererC + RotL64(aIngress, 57U)) + 12634922308499254909U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = ((aWandererK + RotL64(aCross, 39U)) + 6533934734564499389U) + aPhaseGOrbiterAssignSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterG = ((aWandererI + RotL64(aScatter, 3U)) + RotL64(aCarry, 11U)) + 6744203303756105181U;
            aOrbiterI = ((aWandererE + RotL64(aIngress, 23U)) + RotL64(aCarry, 23U)) + 13086782386652045658U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 5693840533331397822U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 1803663542535024611U;
            aOrbiterJ = RotL64((aOrbiterJ * 8511046986156781857U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 3597219300593287708U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 1429753448204448904U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10927459251773273143U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 17229017825587322715U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 1137574712801062932U;
            aOrbiterG = RotL64((aOrbiterG * 3645832160939819415U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 2401991077004083378U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 1332473247826139292U;
            aOrbiterH = RotL64((aOrbiterH * 15029831858261506447U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 11730946340796899885U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 15319163439700390962U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1349242001887975499U), 39U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterH, 3U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 13U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aCross, 19U) + aOrbiterG) + RotL64(aOrbiterI, 6U));
            aWandererI = aWandererI + (((RotL64(aScatter, 27U) + RotL64(aOrbiterJ, 27U)) + aOrbiterH) + RotL64(aCarry, 57U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 10U) + RotL64(aOrbiterF, 19U)) + aOrbiterG);
            aWandererE = aWandererE + ((((RotL64(aIngress, 43U) + RotL64(aOrbiterF, 57U)) + aOrbiterH) + RotL64(aCarry, 27U)) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 51U) + aOrbiterG) + RotL64(aOrbiterJ, 41U)) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 38U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + RotL64(aWandererC, 19U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0;

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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 717U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 7246U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 6650U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 6914U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 26U) + RotL64(aCross, 5U)) ^ (RotL64(aCarry, 41U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = ((aWandererI + RotL64(aIngress, 6U)) + 9855743441035905047U) + aPhaseHOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = ((aWandererB + RotL64(aCross, 39U)) + RotL64(aCarry, 5U)) + 8426286937143990276U;
            aOrbiterG = (aWandererF + RotL64(aScatter, 47U)) + 7146752367170267002U;
            aOrbiterF = (((aWandererC + RotL64(aPrevious, 23U)) + RotL64(aCarry, 51U)) + 12947210066678101726U) + aPhaseHOrbiterAssignSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = ((aWandererG + RotL64(aIngress, 57U)) + RotL64(aCarry, 23U)) + 15902163559925328965U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 8506649889346449469U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 8226286036430263052U;
            aOrbiterG = RotL64((aOrbiterG * 7264199281303956141U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 2703047093452420216U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 6769351326360139560U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5318104980014706265U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 9857025533281333281U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 238297452132277585U;
            aOrbiterF = RotL64((aOrbiterF * 12974709749856065985U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 7203572312072908931U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 12497027346166575632U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1703586436725662307U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 473851890609048879U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 1664484956453886047U;
            aOrbiterA = RotL64((aOrbiterA * 8566500756326590209U), 11U);
            //
            aIngress = RotL64(aOrbiterG, 29U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 14U));
            aIngress = aIngress + RotL64(aOrbiterF, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterG, 3U)) + aOrbiterA) + RotL64(aCarry, 21U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 27U) + aOrbiterF) + RotL64(aOrbiterD, 58U));
            aWandererG = aWandererG + (((RotL64(aScatter, 35U) + aOrbiterF) + RotL64(aOrbiterJ, 21U)) + aPhaseHWandererUpdateSaltF[((aIndex + 16U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterJ, 41U)) + aOrbiterA);
            aWandererB = aWandererB + (((RotL64(aScatter, 46U) + aOrbiterD) + RotL64(aOrbiterG, 29U)) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererF, 51U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 16290U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 11788U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 10084U)) & S_BLOCK1], 46U) ^ RotL64(aWorkLaneA[((aIndex + 9374U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 27U) + RotL64(aCarry, 53U)) ^ (RotL64(aCross, 39U) + RotL64(aIngress, 12U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = (((aWandererE + RotL64(aIngress, 13U)) + RotL64(aCarry, 21U)) + 6068543441070417854U) + aPhaseHOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = (aWandererA + RotL64(aCross, 43U)) + 2995980468193441856U;
            aOrbiterI = (aWandererC + RotL64(aPrevious, 30U)) + 18020277482171594003U;
            aOrbiterE = (((aWandererJ + RotL64(aScatter, 5U)) + RotL64(aCarry, 53U)) + 4293807434721230702U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = ((aWandererB + RotL64(aCross, 51U)) + RotL64(aCarry, 5U)) + 7980599111583893156U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 8593141111851052016U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 5903487523900084325U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2508618861111356699U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 15112035513447930209U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 9854037263057006439U;
            aOrbiterA = RotL64((aOrbiterA * 396276470208637283U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 16759760289688823193U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 12622628933030601390U;
            aOrbiterB = RotL64((aOrbiterB * 2151912984825538321U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 1264668857268123425U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 16302812053619101593U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 18291400055836111547U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 16087995784896123610U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 7970269262800468363U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14924752223305807461U), 5U);
            //
            aIngress = RotL64(aOrbiterE, 41U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 3U));
            aIngress = aIngress + RotL64(aOrbiterI, 30U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aScatter, 4U) + RotL64(aOrbiterD, 29U)) + aOrbiterE) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 35U) + aOrbiterB) + RotL64(aOrbiterE, 13U)) + RotL64(aCarry, 53U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 53U) + aOrbiterB) + RotL64(aOrbiterD, 60U));
            aWandererE = aWandererE + ((((RotL64(aIngress, 43U) + RotL64(aOrbiterE, 47U)) + aOrbiterI) + RotL64(aCarry, 13U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterI, 37U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 28U));
            aCarry = aCarry + (RotL64(aWandererJ, 37U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererE, 11U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 23213U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 23601U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21147U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneB[((aIndex + 19882U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 34U) + RotL64(aIngress, 19U)) ^ (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = (aWandererA + RotL64(aScatter, 23U)) + 13960289014350612206U;
            aOrbiterB = (aWandererD + RotL64(aIngress, 57U)) + 3483331015269589730U;
            aOrbiterA = (((aWandererE + RotL64(aPrevious, 37U)) + RotL64(aCarry, 39U)) + 6873299241002444518U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = ((aWandererH + RotL64(aCross, 3U)) + RotL64(aCarry, 13U)) + 3562094007125534229U;
            aOrbiterI = (((aWandererK + RotL64(aScatter, 14U)) + RotL64(aCarry, 27U)) + 11422367439932782705U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 532453428514259816U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 17810941465810193088U;
            aOrbiterA = RotL64((aOrbiterA * 2830829128884590275U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 11869759058631106331U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 8837581071876177566U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15329827515970522213U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 17185378327053837778U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 7578253375676981500U;
            aOrbiterD = RotL64((aOrbiterD * 13371647568758721729U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 17112646434432814442U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 14949096407295697881U;
            aOrbiterC = RotL64((aOrbiterC * 14770977858283051753U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 4259590620758467836U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 6534899413644542303U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7987609419215568661U), 11U);
            //
            aIngress = RotL64(aOrbiterA, 26U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 41U));
            aIngress = aIngress + RotL64(aOrbiterB, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aIngress, 5U) + aOrbiterC) + RotL64(aOrbiterI, 21U)) + aPhaseHWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 29U) + aOrbiterC) + RotL64(aOrbiterD, 44U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 58U) + RotL64(aOrbiterA, 5U)) + aOrbiterI) + RotL64(aCarry, 21U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterD, 53U)) + aOrbiterB);
            aWandererH = aWandererH + (((RotL64(aCross, 39U) + aOrbiterC) + RotL64(aOrbiterA, 29U)) + RotL64(aCarry, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererH, 28U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 26923U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((aIndex + 25580U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28499U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 29658U)) & S_BLOCK1], 40U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 3U) ^ RotL64(aPrevious, 21U)) + (RotL64(aCross, 50U) + RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 13U)) + RotL64(aCarry, 47U)) + 12131317914288566437U;
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 3U)) + 5672805657999385496U) + aPhaseHOrbiterAssignSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterH = ((aWandererF + RotL64(aIngress, 47U)) + RotL64(aCarry, 35U)) + 3581710244233124197U;
            aOrbiterF = (aWandererK + RotL64(aCross, 56U)) + 15251296040538489436U;
            aOrbiterE = (((aWandererJ + RotL64(aScatter, 27U)) + RotL64(aCarry, 19U)) + 11295008604679904153U) + aPhaseHOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 2230897493419504490U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 7109600123297458999U;
            aOrbiterH = RotL64((aOrbiterH * 8267799351136506307U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 13119156643107683803U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 14755160867807355250U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10007087518844899239U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 16829363373287496832U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 16981122946707720883U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5394974422201576627U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 8806000776958603317U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 16810923047720876014U;
            aOrbiterJ = RotL64((aOrbiterJ * 17872735050219539145U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 8129657889554436328U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 8653100378491974463U;
            aOrbiterE = RotL64((aOrbiterE * 11395283153912468661U), 23U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterJ, 47U);
            aIngress = aIngress + (RotL64(aOrbiterH, 60U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterF, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aIngress, 3U) + RotL64(aOrbiterH, 47U)) + aOrbiterJ) + RotL64(aCarry, 35U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterJ, 38U)) + aOrbiterB);
            aWandererJ = aWandererJ + (((RotL64(aCross, 21U) + aOrbiterE) + RotL64(aOrbiterJ, 27U)) + RotL64(aCarry, 51U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 30U) + RotL64(aOrbiterF, 57U)) + aOrbiterE) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 13U) + RotL64(aOrbiterH, 5U)) + aOrbiterF) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererK, 60U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererA, 27U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
