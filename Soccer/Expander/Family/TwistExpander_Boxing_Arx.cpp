#include "TwistExpander_Boxing_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_Boxing_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xBE9236DCA8DEC401ULL + 0xBF0EA0B47B5200ACULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xB58788F2A616B387ULL + 0xF4C617826D214224ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x83D6AC9464C27477ULL + 0xECA1F1ABCCB58242ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xE4DF305B3206FA2FULL + 0x89AEEC16ABDA1397ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xF54FD5DF20F9CE11ULL + 0xE0BF9FD49FA9C3EBULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xBB9277685C119A87ULL + 0x8CEC4C61963EF8B6ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xEFC2C376BF566613ULL + 0xD8C931B0CA64B66AULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xF67A0FC8382F1C59ULL + 0xB01887E337FEAF6DULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordA, 13U) ^ RotL64(aNonceWordH, 53U)) ^ RotL64(aNonceWordC, 43U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 2252U)) & S_BLOCK1], 3U) ^ RotL64(mSnow[((aIndex + 776U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 27U) ^ RotL64(aNonceWordF, 35U)) ^ RotL64(aNonceWordE, 3U));
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 2809U)) & S_BLOCK1], 14U) ^ RotL64(mSnow[((S_BLOCK1 - aIndex + 2276U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 19U) + RotL64(aCross, 3U)) ^ (RotL64(aCarry, 37U) ^ RotL64(aPrevious, 54U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (aWandererG + RotL64(aIngress, 5U)) + 17936518874386450467U;
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 19U)) + RotL64(aCarry, 47U)) + 13722737841589910344U;
            aOrbiterD = (aWandererE + RotL64(aCross, 41U)) + 11774969167948715796U;
            aOrbiterA = (aWandererF + RotL64(aScatter, 51U)) + 3640101505680493777U;
            aOrbiterB = (aWandererJ + RotL64(aPrevious, 12U)) + 1369495382725650822U;
            aOrbiterC = (aWandererK + RotL64(aCross, 37U)) + 11827310354654653345U;
            aOrbiterI = ((aWandererC + RotL64(aIngress, 27U)) + 186037671377175394U) + aOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = (((aWandererH + RotL64(aScatter, 3U)) + 11428829344234627340U) + aOrbiterAssignSaltF[((aIndex + 22U)) & S_SALT1]) + RotL64(aNonceWordB, 58U);
            aOrbiterJ = (aWandererD + RotL64(aPrevious, 53U)) + 2275016369870029068U;
            aOrbiterF = (((aWandererB + RotL64(aIngress, 14U)) + RotL64(aCarry, 35U)) + 15471646673734798328U) + RotL64(aNonceWordA, 3U);
            aOrbiterK = ((aWandererI + RotL64(aCross, 57U)) + RotL64(aCarry, 5U)) + 12172082573115640145U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 6626736341348283154U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 12220614992483863623U;
            aOrbiterD = RotL64((aOrbiterD * 8137086205714097487U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 13157102324253760215U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 4143587482368093601U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5060677690991506895U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 11007575246013796426U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterI) ^ 11721585930088637162U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]) ^ RotL64(aNonceWordG, 49U);
            aOrbiterH = RotL64((aOrbiterH * 15009627907125738519U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 5720789204450196217U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 3094696226821431648U;
            aOrbiterA = RotL64((aOrbiterA * 4412033981712165541U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 14675830108100986773U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 9444071495289719645U;
            aOrbiterI = RotL64((aOrbiterI * 10983136361953366557U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 5106753847015199956U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 7585421898593510010U;
            aOrbiterJ = RotL64((aOrbiterJ * 140996914192351011U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 11746948407655524690U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 16336323220286344483U;
            aOrbiterK = RotL64((aOrbiterK * 6590417628835864497U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 8030445186765781136U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 276034088015165891U;
            aOrbiterE = RotL64((aOrbiterE * 7626025612710225099U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 8116955322602209153U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 5704503350608834450U) ^ RotL64(aNonceWordF, 27U);
            aOrbiterB = RotL64((aOrbiterB * 7049558959583832449U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 8063875087087055875U) + aOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 1111816778196345760U;
            aOrbiterG = RotL64((aOrbiterG * 13820440198677609571U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 7702895879089714461U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 17936518874386450467U;
            aOrbiterF = RotL64((aOrbiterF * 12767279443267850009U), 5U);
            //
            aIngress = RotL64(aOrbiterK, 46U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 23U));
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 37U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 27U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterG, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 56U) + RotL64(aOrbiterJ, 57U)) + aOrbiterK);
            aWandererB = aWandererB + ((((RotL64(aCross, 13U) + RotL64(aOrbiterD, 37U)) + aOrbiterH) + RotL64(aCarry, 39U)) + RotL64(aNonceWordH, 17U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 43U) + aOrbiterK) + RotL64(aOrbiterC, 23U));
            aWandererH = aWandererH + ((RotL64(aScatter, 47U) + RotL64(aOrbiterD, 11U)) + aOrbiterG);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 27U) + aOrbiterA) + RotL64(aOrbiterD, 21U));
            aWandererK = aWandererK + (((RotL64(aScatter, 41U) + aOrbiterB) + RotL64(aOrbiterC, 60U)) + RotL64(aNonceWordC, 19U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 29U) + aOrbiterF) + RotL64(aOrbiterC, 5U)) + aWandererUpdateSaltB[((aIndex + 18U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 37U) + RotL64(aOrbiterI, 27U)) + aOrbiterE);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 22U) + RotL64(aOrbiterC, 35U)) + aOrbiterH);
            aWandererG = aWandererG + (((RotL64(aScatter, 3U) + aOrbiterD) + RotL64(aOrbiterJ, 41U)) + RotL64(aCarry, 11U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 53U) + aOrbiterE) + RotL64(aOrbiterB, 30U)) + aWandererUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 48U));
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererI);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 43U));
            aCarry = aCarry + (RotL64(aWandererC, 41U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererH, 21U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererJ, 56U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 23U) ^ RotL64(aNonceWordD, 36U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 9388U)) & S_BLOCK1], 13U) ^ RotL64(mSnow[((aIndex + 5826U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 36U) ^ RotL64(aNonceWordH, 47U)) ^ RotL64(aNonceWordC, 19U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 9992U)) & S_BLOCK1], 5U) ^ RotL64(mSource[((aIndex + 10346U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 11U) + RotL64(aPrevious, 37U)) ^ (RotL64(aIngress, 23U) ^ RotL64(aCarry, 50U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((aWandererK + RotL64(aScatter, 41U)) + RotL64(aCarry, 27U)) + 5160910997561396461U;
            aOrbiterJ = (aWandererE + RotL64(aCross, 39U)) + 14920764751058512062U;
            aOrbiterC = (aWandererG + RotL64(aIngress, 19U)) + 6080952401749660022U;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 57U)) + 17667234330526298627U) + RotL64(aNonceWordB, 21U);
            aOrbiterI = ((aWandererJ + RotL64(aCross, 30U)) + 760630072638686756U) + aOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = (((aWandererI + RotL64(aPrevious, 13U)) + 3504157162816997476U) + aOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1]) + RotL64(aNonceWordA, 37U);
            aOrbiterB = (aWandererF + RotL64(aIngress, 5U)) + 9489022223422585882U;
            aOrbiterD = (aWandererH + RotL64(aScatter, 21U)) + 1149898536879968964U;
            aOrbiterH = ((aWandererB + RotL64(aIngress, 3U)) + RotL64(aCarry, 47U)) + 10492284328940025310U;
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 23U)) + RotL64(aCarry, 23U)) + 13213275606286399312U;
            aOrbiterE = (aWandererA + RotL64(aScatter, 44U)) + 10557118912847180413U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 15618980209023994776U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 5268600749854045564U;
            aOrbiterC = RotL64((aOrbiterC * 3849660559223919613U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 8011552687609649990U) + aOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 3148133096349525066U;
            aOrbiterJ = RotL64((aOrbiterJ * 5245156554959620007U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 12032847944237867285U) + RotL64(aNonceWordF, 18U);
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 14999005703490824673U;
            aOrbiterI = RotL64((aOrbiterI * 6631584955208646049U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 5426735969392906710U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 3593177531650386729U;
            aOrbiterB = RotL64((aOrbiterB * 12997284886192717043U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 1701444719333347373U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 15928731228196894960U;
            aOrbiterH = RotL64((aOrbiterH * 1919318226904213433U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 5960179456039157036U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 5716434224061596483U;
            aOrbiterF = RotL64((aOrbiterF * 3731976564761202801U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 2136841536293340279U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 12969550408652728526U;
            aOrbiterG = RotL64((aOrbiterG * 7612191387451455137U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 3641997570461447114U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 4677572491523684525U;
            aOrbiterK = RotL64((aOrbiterK * 2730358077882211651U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 2741372094325164504U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 4998631511811832690U;
            aOrbiterD = RotL64((aOrbiterD * 10619395395977372695U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 6260464862798783617U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterB) ^ 16489087874167346533U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]) ^ RotL64(aNonceWordD, 23U);
            aOrbiterA = RotL64((aOrbiterA * 11278053967185244867U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 7043760915859224327U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 5160910997561396461U;
            aOrbiterE = RotL64((aOrbiterE * 15260149870590431675U), 37U);
            //
            aIngress = RotL64(aOrbiterF, 3U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 60U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 5U));
            aIngress = aIngress + (RotL64(aOrbiterC, 13U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 51U));
            aIngress = aIngress + RotL64(aOrbiterG, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aPrevious, 27U) + aOrbiterC) + RotL64(aOrbiterJ, 56U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterB, 35U)) + aOrbiterI) + RotL64(aNonceWordE, 41U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 41U) + RotL64(aOrbiterH, 53U)) + aOrbiterK) + RotL64(aCarry, 35U)) + aWandererUpdateSaltC[((aIndex + 8U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 51U) + aOrbiterC) + RotL64(aOrbiterG, 29U)) + aWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aIngress, 22U) + RotL64(aOrbiterH, 50U)) + aOrbiterC);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterC, 19U)) + aOrbiterB);
            aWandererF = aWandererF + ((RotL64(aPrevious, 37U) + RotL64(aOrbiterD, 43U)) + aOrbiterK);
            aWandererK = aWandererK ^ (((RotL64(aCross, 3U) + aOrbiterG) + RotL64(aOrbiterA, 39U)) + RotL64(aNonceWordG, 13U));
            aWandererD = aWandererD + ((RotL64(aIngress, 18U) + aOrbiterD) + RotL64(aOrbiterF, 3U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 43U) + aOrbiterK) + RotL64(aOrbiterA, 47U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterF, 23U)) + aOrbiterE) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererG);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 30U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 21U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 41U));
            aCarry = aCarry + (RotL64(aWandererB, 13U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererC, 51U);
            aCarry = aCarry + RotL64(aIngress, 28U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 5U) ^ RotL64(aNonceWordB, 13U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 11121U)) & S_BLOCK1], 54U) ^ RotL64(mSnow[((S_BLOCK1 - aIndex + 15818U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 13U) ^ RotL64(aNonceWordC, 29U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11953U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 16151U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aPrevious, 11U)) ^ (RotL64(aIngress, 44U) ^ RotL64(aCarry, 29U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (aWandererH + RotL64(aPrevious, 18U)) + 5510690816044082200U;
            aOrbiterJ = (aWandererJ + RotL64(aCross, 29U)) + 15967820875033940530U;
            aOrbiterH = (aWandererK + RotL64(aIngress, 23U)) + 539348720848176221U;
            aOrbiterD = (aWandererF + RotL64(aScatter, 43U)) + 15779318183635560817U;
            aOrbiterE = (((aWandererB + RotL64(aCross, 57U)) + RotL64(aCarry, 19U)) + 14511058534424187469U) + RotL64(aNonceWordE, 10U);
            aOrbiterB = (((aWandererC + RotL64(aPrevious, 53U)) + RotL64(aCarry, 43U)) + 5811130556873428391U) + aOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = (aWandererI + RotL64(aScatter, 3U)) + 1085928476499444025U;
            aOrbiterA = ((aWandererD + RotL64(aIngress, 10U)) + RotL64(aCarry, 53U)) + 6973335316600768130U;
            aOrbiterG = ((aWandererA + RotL64(aCross, 5U)) + 10747243745475009744U) + aOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = ((aWandererE + RotL64(aScatter, 37U)) + 1072260008981349754U) + RotL64(aNonceWordH, 59U);
            aOrbiterC = (aWandererG + RotL64(aIngress, 41U)) + 2018772405352495753U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 1092091597048996547U) + RotL64(aNonceWordC, 5U);
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 15103140149542167197U;
            aOrbiterH = RotL64((aOrbiterH * 621856991658027989U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 13194619321108681542U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 16749188603268621850U) ^ aOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9575408950550922039U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 7427959503086895166U) + RotL64(aNonceWordG, 47U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 9895804051379551393U;
            aOrbiterJ = RotL64((aOrbiterJ * 2701997336201570715U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 4526020800679774259U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 4484850928870048176U;
            aOrbiterE = RotL64((aOrbiterE * 17556987520625677313U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 1837404844299040155U) + aOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 15213208978489570694U;
            aOrbiterA = RotL64((aOrbiterA * 7062740584650274133U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 9615231781751396800U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 15872192167825648096U;
            aOrbiterK = RotL64((aOrbiterK * 2900526493682580729U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 12530672039655918903U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 10617836782870315804U;
            aOrbiterF = RotL64((aOrbiterF * 9716778004909794973U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 550750725406860977U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 3498554352021622907U;
            aOrbiterD = RotL64((aOrbiterD * 9846933294851238495U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 4059346317776216057U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 14161853870874499023U;
            aOrbiterI = RotL64((aOrbiterI * 8601560894939097781U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 4088411647683253905U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 9321241420172776158U;
            aOrbiterG = RotL64((aOrbiterG * 4167888281125330225U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 8527337525861632945U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 5510690816044082200U;
            aOrbiterC = RotL64((aOrbiterC * 12464836001483233379U), 23U);
            //
            aIngress = RotL64(aOrbiterA, 19U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 39U));
            aIngress = aIngress + (RotL64(aOrbiterB, 11U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterG, 29U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 56U));
            aIngress = aIngress + RotL64(aOrbiterC, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aCross, 19U) + RotL64(aOrbiterC, 47U)) + aOrbiterA) + RotL64(aCarry, 5U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterD, 27U)) + aOrbiterC);
            aWandererI = aWandererI + (((RotL64(aScatter, 5U) + aOrbiterJ) + RotL64(aOrbiterB, 39U)) + RotL64(aCarry, 11U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 34U) + RotL64(aOrbiterG, 13U)) + aOrbiterF) + RotL64(aNonceWordF, 9U));
            aWandererE = aWandererE + ((RotL64(aCross, 53U) + RotL64(aOrbiterB, 52U)) + aOrbiterG);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterK, 43U)) + aOrbiterF);
            aWandererC = aWandererC + ((((RotL64(aIngress, 3U) + aOrbiterI) + RotL64(aOrbiterJ, 37U)) + RotL64(aNonceWordD, 7U)) + aWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterC, 11U)) + aOrbiterH);
            aWandererH = aWandererH + ((RotL64(aIngress, 41U) + aOrbiterF) + RotL64(aOrbiterC, 41U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterG, 57U)) + aOrbiterI);
            aWandererG = aWandererG + (((RotL64(aScatter, 48U) + RotL64(aOrbiterE, 30U)) + aOrbiterA) + aWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererD);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 50U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + (RotL64(aWandererI, 37U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 5U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 12U) ^ RotL64(aNonceWordF, 3U)) ^ RotL64(aNonceWordH, 23U));
            aIngress = aIngress ^ (RotL64(mSnow[((aIndex + 18818U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((aIndex + 21811U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 30U) ^ RotL64(aNonceWordD, 53U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20206U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((aIndex + 21503U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 35U) + RotL64(aPrevious, 20U)) ^ (RotL64(aCarry, 47U) ^ RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (aWandererF + RotL64(aScatter, 5U)) + 6916817163240024692U;
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 51U)) + 14554930751292077817U) + aOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = (aWandererI + RotL64(aCross, 21U)) + 1098305064484336101U;
            aOrbiterK = (aWandererD + RotL64(aPrevious, 35U)) + 12192821172420471527U;
            aOrbiterF = ((aWandererH + RotL64(aScatter, 53U)) + RotL64(aCarry, 47U)) + 2435134991707318845U;
            aOrbiterH = (((aWandererK + RotL64(aIngress, 58U)) + RotL64(aCarry, 19U)) + 1896745368738512624U) + RotL64(aNonceWordF, 8U);
            aOrbiterE = (((aWandererB + RotL64(aPrevious, 23U)) + 1114996424222923873U) + aOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1]) + RotL64(aNonceWordE, 27U);
            aOrbiterJ = ((aWandererE + RotL64(aCross, 11U)) + RotL64(aCarry, 57U)) + 9839135798371512656U;
            aOrbiterA = (aWandererC + RotL64(aScatter, 41U)) + 8037967239603177043U;
            aOrbiterC = (aWandererG + RotL64(aIngress, 13U)) + 15185468738487237432U;
            aOrbiterB = (aWandererA + RotL64(aPrevious, 30U)) + 4912098316394854543U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 13142688607850380888U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 4507379759608945839U;
            aOrbiterI = RotL64((aOrbiterI * 2989332387754215967U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 7299006009652289342U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 5390655277207053627U;
            aOrbiterF = RotL64((aOrbiterF * 10973744708856143715U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 6744737023577785725U) + aOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 15539737698867067285U) ^ RotL64(aNonceWordH, 57U);
            aOrbiterH = RotL64((aOrbiterH * 4686092035261336911U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 13329866734681377952U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 13284937458969166257U;
            aOrbiterE = RotL64((aOrbiterE * 3965985432462699445U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 8695002088915702168U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 3858059421620839286U;
            aOrbiterJ = RotL64((aOrbiterJ * 9559783727301092937U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 6609163873243179836U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 9416165620556710540U;
            aOrbiterA = RotL64((aOrbiterA * 240385043740268229U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 1578449067529000433U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 14309000104419489303U;
            aOrbiterC = RotL64((aOrbiterC * 7599078306153684729U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 15785180680737461320U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 10099222679918382021U;
            aOrbiterB = RotL64((aOrbiterB * 2012232597046182581U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 10666287769220108179U) + aOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 13648647399222807034U;
            aOrbiterD = RotL64((aOrbiterD * 10772381733103127201U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 9292207828896796810U) + RotL64(aNonceWordG, 47U);
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 9155130791347443553U;
            aOrbiterG = RotL64((aOrbiterG * 16838229790655977057U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 11334395119119245556U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 6916817163240024692U;
            aOrbiterK = RotL64((aOrbiterK * 9640906826978028183U), 47U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterA, 34U);
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterH, 51U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 43U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 53U));
            aIngress = aIngress + RotL64(aOrbiterE, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aScatter, 5U) + aOrbiterH) + RotL64(aOrbiterE, 39U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 39U) + aOrbiterI) + RotL64(aOrbiterJ, 26U));
            aWandererC = aWandererC + (((RotL64(aIngress, 23U) + RotL64(aOrbiterB, 51U)) + aOrbiterE) + RotL64(aCarry, 5U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 37U) + aOrbiterK) + RotL64(aOrbiterE, 37U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 20U) + aOrbiterJ) + RotL64(aOrbiterK, 47U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterG, 13U)) + aOrbiterA) + RotL64(aNonceWordA, 13U));
            aWandererG = aWandererG + (((RotL64(aScatter, 29U) + RotL64(aOrbiterG, 11U)) + aOrbiterB) + RotL64(aNonceWordC, 39U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterF, 21U)) + aOrbiterC) + aWandererUpdateSaltF[((aIndex + 6U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aScatter, 51U) + aOrbiterD) + RotL64(aOrbiterE, 53U)) + RotL64(aCarry, 47U)) + aWandererUpdateSaltB[((aIndex + 28U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 58U) + aOrbiterC) + RotL64(aOrbiterG, 30U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 27U) + RotL64(aOrbiterA, 57U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererD, 10U) ^ aWandererK);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + RotL64(aWandererB, 41U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 44U) ^ RotL64(aNonceWordG, 35U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 23324U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 22530U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 27U) ^ RotL64(aNonceWordH, 13U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24413U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26597U)) & S_BLOCK1], 42U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCarry, 48U)) ^ (RotL64(aCross, 35U) ^ RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererE + RotL64(aCross, 54U)) + 16183871922837164759U;
            aOrbiterA = ((aWandererF + RotL64(aIngress, 3U)) + 7002058258090219055U) + RotL64(aNonceWordD, 23U);
            aOrbiterD = ((aWandererK + RotL64(aScatter, 37U)) + RotL64(aCarry, 19U)) + 5650868611888303705U;
            aOrbiterF = (aWandererA + RotL64(aPrevious, 27U)) + 11899839660943876690U;
            aOrbiterB = ((aWandererD + RotL64(aIngress, 51U)) + 15349649504488111111U) + aOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 13U)) + RotL64(aCarry, 27U)) + 14060149569086744970U;
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 41U)) + 12920917574225030112U) + aOrbiterAssignSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterI = (aWandererI + RotL64(aCross, 11U)) + 2831994965175330135U;
            aOrbiterG = (aWandererB + RotL64(aScatter, 34U)) + 18312543585028439192U;
            aOrbiterK = (((aWandererH + RotL64(aCross, 19U)) + RotL64(aCarry, 23U)) + 11657562205118394239U) + RotL64(aNonceWordE, 49U);
            aOrbiterE = (aWandererC + RotL64(aIngress, 57U)) + 10850792819281246052U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 17810371216216125323U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 7963413941144223128U;
            aOrbiterD = RotL64((aOrbiterD * 534217972450595401U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 5498715358793875584U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 9256727548911651373U;
            aOrbiterH = RotL64((aOrbiterH * 10498848323914000989U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 17246360111302191699U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 18309978718113983369U;
            aOrbiterI = RotL64((aOrbiterI * 18267472694666221077U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 3100998994319502921U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 8129301860291235970U;
            aOrbiterK = RotL64((aOrbiterK * 17847033539279176187U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 1889641029473279114U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 16538494307002917945U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8081488217920885783U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 5432230549146849322U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 2634437941396090817U;
            aOrbiterF = RotL64((aOrbiterF * 7612999214758935211U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 16940172599174185058U) + aOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 13151669140593952203U) ^ RotL64(aNonceWordB, 13U);
            aOrbiterC = RotL64((aOrbiterC * 16225319638131723487U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 3995064294869931681U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 913081077665768816U;
            aOrbiterG = RotL64((aOrbiterG * 9299514648768060453U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 2469001696075411481U) + RotL64(aNonceWordC, 34U);
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 2167390955194185443U) ^ aOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11805065572289005223U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 1574066406534010796U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 8736976961589874013U) ^ aOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5980070607180321955U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 4233621443153132083U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 16183871922837164759U;
            aOrbiterB = RotL64((aOrbiterB * 4030569514959370895U), 35U);
            //
            aIngress = RotL64(aOrbiterE, 23U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 41U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 46U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 5U));
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aPrevious, 42U) + aOrbiterA) + RotL64(aOrbiterC, 47U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 51U) + aOrbiterG) + RotL64(aOrbiterK, 10U)) + aWandererUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 13U) + aOrbiterG) + RotL64(aOrbiterC, 19U)) + RotL64(aCarry, 19U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterI, 57U)) + aOrbiterE);
            aWandererB = aWandererB + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterA, 39U)) + aOrbiterH);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 57U) + aOrbiterH) + RotL64(aOrbiterC, 35U)) + aWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 54U) + RotL64(aOrbiterE, 37U)) + aOrbiterD) + RotL64(aNonceWordF, 55U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterF, 12U)) + aOrbiterA);
            aWandererA = aWandererA + ((RotL64(aScatter, 23U) + aOrbiterI) + RotL64(aOrbiterB, 41U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterA, 5U)) + aOrbiterJ);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterB, 51U)) + aOrbiterC) + RotL64(aCarry, 47U)) + RotL64(aNonceWordH, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 54U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererD);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 12U));
            aCarry = aCarry + RotL64(aWandererE, 41U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 3U) ^ RotL64(aNonceWordE, 19U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 31168U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31598U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 43U) ^ RotL64(aNonceWordD, 14U)) ^ RotL64(aNonceWordF, 35U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28378U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 30738U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 18U) ^ RotL64(aCarry, 5U)) ^ (RotL64(aCross, 43U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((aWandererK + RotL64(aScatter, 23U)) + RotL64(aCarry, 53U)) + 77518479758428414U;
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 19U)) + 4832061802166300011U) + aOrbiterAssignSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = ((aWandererH + RotL64(aCross, 53U)) + RotL64(aCarry, 37U)) + 11695291171006574112U;
            aOrbiterG = (aWandererE + RotL64(aIngress, 39U)) + 7467412817843260094U;
            aOrbiterA = (aWandererB + RotL64(aScatter, 27U)) + 17801484124471154757U;
            aOrbiterJ = (aWandererF + RotL64(aCross, 48U)) + 5555455638503958639U;
            aOrbiterC = ((aWandererG + RotL64(aPrevious, 37U)) + RotL64(aCarry, 57U)) + 5669470540733721606U;
            aOrbiterD = ((aWandererJ + RotL64(aIngress, 57U)) + 3042388456327784163U) + RotL64(aNonceWordA, 29U);
            aOrbiterI = ((aWandererA + RotL64(aCross, 41U)) + 2236734925228156691U) + aOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = ((aWandererC + RotL64(aScatter, 4U)) + 14459720401528685450U) + RotL64(aNonceWordH, 9U);
            aOrbiterE = (aWandererD + RotL64(aIngress, 35U)) + 4814967631216658856U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 16950679344449075945U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 6262238639302011050U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9942659897425088183U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 3522256359074996724U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 12524717897707074242U;
            aOrbiterA = RotL64((aOrbiterA * 6787771338063891989U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 13891759914865623828U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 11910250571469028666U;
            aOrbiterJ = RotL64((aOrbiterJ * 12311343917878428995U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 2240189915640314069U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 5365912986308810837U;
            aOrbiterC = RotL64((aOrbiterC * 15133972552032469957U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 9323732721344489753U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 13087326560957916553U;
            aOrbiterD = RotL64((aOrbiterD * 14659491687401151733U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 16398238057564892809U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 11517870519285159224U) ^ RotL64(aNonceWordF, 43U);
            aOrbiterI = RotL64((aOrbiterI * 1501848878469712681U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 7758285512254776734U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 17475149091906684720U;
            aOrbiterK = RotL64((aOrbiterK * 6015816725428299273U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 2051631493975035243U) + aOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 11684740065349595315U;
            aOrbiterE = RotL64((aOrbiterE * 10918975496337269197U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 10575473798991451167U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 8267005776169272822U) ^ RotL64(aNonceWordC, 5U);
            aOrbiterF = RotL64((aOrbiterF * 13166868678285963961U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 6249698995716039231U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 13808085811784323978U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3897731011582061983U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 2739364646624876985U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 77518479758428414U;
            aOrbiterG = RotL64((aOrbiterG * 6977724811175035551U), 21U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterC, 23U);
            aIngress = aIngress + (RotL64(aOrbiterH, 41U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 35U));
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterK, 18U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterE, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterE, 21U)) + aOrbiterB) + RotL64(aNonceWordB, 25U));
            aWandererK = aWandererK + (((RotL64(aIngress, 10U) + aOrbiterC) + RotL64(aOrbiterI, 53U)) + RotL64(aCarry, 35U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterF, 39U)) + aOrbiterB);
            aWandererD = aWandererD + ((RotL64(aCross, 35U) + RotL64(aOrbiterE, 27U)) + aOrbiterA);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 43U) + aOrbiterG) + RotL64(aOrbiterH, 41U));
            aWandererC = aWandererC + ((RotL64(aIngress, 53U) + aOrbiterG) + RotL64(aOrbiterB, 36U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterI, 5U)) + aOrbiterG);
            aWandererI = aWandererI + ((((RotL64(aCross, 19U) + aOrbiterJ) + RotL64(aOrbiterF, 19U)) + RotL64(aNonceWordD, 20U)) + aWandererUpdateSaltD[((aIndex + 28U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterA, 29U)) + aOrbiterH);
            aWandererA = aWandererA + ((((RotL64(aScatter, 23U) + RotL64(aOrbiterA, 51U)) + aOrbiterD) + RotL64(aCarry, 27U)) + aWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 6U) + RotL64(aOrbiterK, 10U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererG, 14U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererK);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 41U));
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererI);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 39U));
            aCarry = aCarry + RotL64(aWandererA, 43U);
            aCarry = aCarry + RotL64(aIngress, 10U);
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

void TwistExpander_Boxing_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xE38F1817E9406A69ULL + 0x89693ECD239B6879ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x8656187B2789217DULL + 0xD53C6A4A0A485A65ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x83BD61F245105CBDULL + 0xC1E792C2447D449BULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xDDAA6E00D8F81B95ULL + 0xEE113D80AE369AE9ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x8848DDDE8BC35B73ULL + 0xE3D16CFF6D846474ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x9F46EBEE947E4CF3ULL + 0xE19875B995728C1AULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xBF794D19FD263971ULL + 0xCA7BD7EC77EA43D2ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xB9721FCE87EF89DBULL + 0x8F29F655842AEB3BULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 3U) ^ RotL64(aNonceWordE, 23U)) ^ RotL64(aNonceWordH, 14U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 3438U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 6729U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 27U) ^ RotL64(aNonceWordC, 53U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2017U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((aIndex + 3915U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 3U) + RotL64(aPrevious, 22U)) ^ (RotL64(aCross, 35U) + RotL64(aIngress, 47U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((aWandererF + RotL64(aScatter, 39U)) + 1297415699043177788U) + aOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = ((aWandererH + RotL64(aIngress, 43U)) + RotL64(aCarry, 3U)) + 17583786534509260153U;
            aOrbiterC = (aWandererC + RotL64(aCross, 57U)) + 643197858925708798U;
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 23U)) + RotL64(aCarry, 19U)) + 5062653766915694874U;
            aOrbiterE = (aWandererJ + RotL64(aScatter, 18U)) + 7034273638367180511U;
            aOrbiterA = (((aWandererG + RotL64(aCross, 27U)) + RotL64(aCarry, 43U)) + 2026909726972916996U) + RotL64(aNonceWordG, 52U);
            aOrbiterJ = (aWandererB + RotL64(aIngress, 3U)) + 2785690475553211646U;
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 47U)) + 2910341716302991892U) + RotL64(aNonceWordB, 55U);
            aOrbiterG = ((aWandererA + RotL64(aIngress, 52U)) + 2834181605200829791U) + aOrbiterAssignSaltE[((aIndex + 4U)) & S_SALT1];
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 13323052600571281928U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 10434901530315760460U;
            aOrbiterC = RotL64((aOrbiterC * 2042210188346767033U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 247903955625194782U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 5196515747387257163U;
            aOrbiterA = RotL64((aOrbiterA * 1799024689023272275U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 7196305682377987476U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 14777739876892587484U;
            aOrbiterK = RotL64((aOrbiterK * 95220583948241581U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 10609060796540136671U) + RotL64(aNonceWordF, 17U);
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 8386027207212484155U;
            aOrbiterG = RotL64((aOrbiterG * 4855610536246556893U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 729659744301903424U) + aOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 2350564261412606157U;
            aOrbiterD = RotL64((aOrbiterD * 16713856782349084977U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 16611987556673864177U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 1525195188708550503U) ^ RotL64(aNonceWordA, 27U);
            aOrbiterH = RotL64((aOrbiterH * 10045858602151004553U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 4654808490980989596U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 8189569777087686263U) ^ aOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17278657566389299577U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 10932857495004451792U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 1833880112534916813U;
            aOrbiterI = RotL64((aOrbiterI * 8004341577533825681U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 13100236350175516423U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 2773759534195186313U;
            aOrbiterE = RotL64((aOrbiterE * 3194954066097323161U), 43U);
            //
            aIngress = RotL64(aOrbiterD, 47U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 37U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 50U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterK, 43U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterG, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aPrevious, 14U) + RotL64(aOrbiterK, 19U)) + aOrbiterE) + RotL64(aCarry, 43U)) + RotL64(aNonceWordE, 13U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 43U) + aOrbiterI) + RotL64(aOrbiterD, 51U));
            aWandererB = aWandererB + (((RotL64(aCross, 53U) + RotL64(aOrbiterH, 43U)) + aOrbiterJ) + RotL64(aCarry, 21U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 29U) + aOrbiterE) + RotL64(aOrbiterD, 23U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 5U) + aOrbiterJ) + RotL64(aOrbiterA, 6U)) + aWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 37U) + aOrbiterH) + RotL64(aOrbiterG, 39U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterA, 11U)) + aOrbiterC) + aWandererUpdateSaltA[((aIndex + 8U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aCross, 48U) + RotL64(aOrbiterD, 47U)) + aOrbiterC) + RotL64(aNonceWordC, 45U));
            aWandererD = aWandererD + ((RotL64(aScatter, 23U) + RotL64(aOrbiterG, 34U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + (RotL64(aWandererA, 46U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 37U));
            aCarry = aCarry + RotL64(aWandererJ, 29U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 47U) ^ RotL64(aNonceWordB, 56U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 15502U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 15707U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 52U) ^ RotL64(aNonceWordE, 37U)) ^ RotL64(aNonceWordF, 21U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9316U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 13001U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 41U) + RotL64(aIngress, 3U)) + (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 54U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (aWandererC + RotL64(aIngress, 13U)) + 12583180859826261500U;
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 48U)) + RotL64(aCarry, 29U)) + 9067093488553721468U;
            aOrbiterC = ((aWandererK + RotL64(aScatter, 57U)) + 12173106198862881754U) + RotL64(aNonceWordC, 25U);
            aOrbiterD = ((aWandererH + RotL64(aCross, 29U)) + 11333491014394592654U) + RotL64(aNonceWordH, 49U);
            aOrbiterG = (aWandererD + RotL64(aScatter, 19U)) + 3511883526940919554U;
            aOrbiterA = ((aWandererI + RotL64(aIngress, 24U)) + RotL64(aCarry, 47U)) + 7416810692106273044U;
            aOrbiterK = (aWandererF + RotL64(aPrevious, 41U)) + 8341174972619784110U;
            aOrbiterJ = (((aWandererA + RotL64(aCross, 35U)) + RotL64(aCarry, 57U)) + 2220852854836962979U) + aOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 53U)) + 8090781422229383825U) + aOrbiterAssignSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 2338801236599102223U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 12484514711848308104U) ^ aOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10364216764253366067U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 13684861340589131816U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 12796636819991873058U;
            aOrbiterG = RotL64((aOrbiterG * 5533508014234835669U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 7634198650894837690U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 10240326122201201762U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8758703497719125901U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 4162814763739453934U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 2766504649149048469U) ^ RotL64(aNonceWordA, 35U);
            aOrbiterJ = RotL64((aOrbiterJ * 16731843453895178671U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 11051393030148769655U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 17687055068651386665U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1042927176246229537U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 3353615315436983420U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 5971640796220306310U;
            aOrbiterB = RotL64((aOrbiterB * 15804313508835034807U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 12299773092762384765U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 7435804907797063411U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9848139805288165965U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 8735783937125735699U) + RotL64(aNonceWordB, 55U);
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 11903126115475835615U;
            aOrbiterA = RotL64((aOrbiterA * 16942088822124940265U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 4427166023462475475U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 6011733469446008137U;
            aOrbiterF = RotL64((aOrbiterF * 17298067225913923517U), 11U);
            //
            aIngress = RotL64(aOrbiterE, 23U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + (RotL64(aOrbiterC, 6U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 11U));
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterC, 19U)) + aOrbiterB);
            aWandererG = aWandererG + ((RotL64(aScatter, 39U) + RotL64(aOrbiterD, 28U)) + aOrbiterJ);
            aWandererI = aWandererI ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterK, 53U)) + aOrbiterC) + aWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aIngress, 52U) + RotL64(aOrbiterJ, 41U)) + aOrbiterA) + RotL64(aCarry, 23U)) + RotL64(aNonceWordF, 61U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterG, 23U)) + aOrbiterF);
            aWandererK = aWandererK + (((RotL64(aCross, 43U) + aOrbiterG) + RotL64(aOrbiterE, 47U)) + RotL64(aCarry, 11U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterE, 3U)) + aOrbiterA) + RotL64(aNonceWordG, 58U));
            aWandererC = aWandererC + ((RotL64(aScatter, 30U) + RotL64(aOrbiterD, 14U)) + aOrbiterG);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 47U) + aOrbiterD) + RotL64(aOrbiterC, 57U)) + aWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + (RotL64(aWandererG, 28U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererH, 47U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 3U) ^ RotL64(aNonceWordE, 47U)) ^ RotL64(aNonceWordC, 57U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 22747U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 22669U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 57U) ^ RotL64(aNonceWordG, 19U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16384U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 18580U)) & S_BLOCK1], 40U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 34U) ^ RotL64(aCross, 5U)) ^ (RotL64(aIngress, 47U) + RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (aWandererG + RotL64(aCross, 13U)) + 5088525177670191619U;
            aOrbiterD = (aWandererF + RotL64(aPrevious, 43U)) + 9966456257813932112U;
            aOrbiterH = (aWandererK + RotL64(aIngress, 56U)) + 7707646574027146307U;
            aOrbiterC = ((((aWandererJ + RotL64(aScatter, 51U)) + RotL64(aCarry, 11U)) + 75480203757681173U) + aOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1]) + RotL64(aNonceWordH, 23U);
            aOrbiterI = ((aWandererD + RotL64(aPrevious, 19U)) + RotL64(aCarry, 43U)) + 384659134071835163U;
            aOrbiterK = ((aWandererA + RotL64(aScatter, 39U)) + 3158769775373307778U) + aOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = (aWandererH + RotL64(aIngress, 3U)) + 17360830943513941272U;
            aOrbiterJ = ((aWandererC + RotL64(aCross, 47U)) + 5317278822721604586U) + RotL64(aNonceWordG, 54U);
            aOrbiterF = ((aWandererE + RotL64(aIngress, 26U)) + RotL64(aCarry, 35U)) + 1371427105215954781U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 3162710551223553423U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 5332921933853550756U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11709546145149357887U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 10572462410297815854U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 10234389605554817892U) ^ RotL64(aNonceWordA, 51U);
            aOrbiterA = RotL64((aOrbiterA * 2130374833440291193U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 13421365517991380605U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 10186643614984034083U;
            aOrbiterC = RotL64((aOrbiterC * 8554471709467808453U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 4742438973260817120U) + RotL64(aNonceWordE, 5U);
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 6081590345899008846U;
            aOrbiterD = RotL64((aOrbiterD * 7069396301823124931U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 15360092808493795340U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 12186413069553132646U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3815981440611914267U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 16756221656224451552U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 12232880965861373143U;
            aOrbiterK = RotL64((aOrbiterK * 14196910735715726471U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 10090954323470840557U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 15615770271463853537U;
            aOrbiterB = RotL64((aOrbiterB * 13544181592829027283U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 556029032505658411U) + aOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 13311879111583579039U;
            aOrbiterJ = RotL64((aOrbiterJ * 3924744868168749003U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 8646360871497847336U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 2064833941982069154U;
            aOrbiterF = RotL64((aOrbiterF * 10016546852137913163U), 13U);
            //
            aIngress = RotL64(aOrbiterK, 50U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterD, 5U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 53U));
            aIngress = aIngress + RotL64(aOrbiterF, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterC, 47U)) + aOrbiterK) + aWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 60U) + aOrbiterK) + RotL64(aOrbiterI, 43U)) + RotL64(aCarry, 19U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 51U) + RotL64(aOrbiterD, 29U)) + aOrbiterH) + RotL64(aNonceWordC, 27U));
            aWandererH = aWandererH + (((RotL64(aIngress, 23U) + RotL64(aOrbiterK, 34U)) + aOrbiterJ) + RotL64(aCarry, 51U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 35U) + aOrbiterC) + RotL64(aOrbiterF, 23U)) + aWandererUpdateSaltE[((aIndex + 16U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 6U) + RotL64(aOrbiterJ, 19U)) + aOrbiterI) + RotL64(aNonceWordB, 13U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterK, 5U)) + aOrbiterD);
            aWandererE = aWandererE + ((RotL64(aIngress, 39U) + RotL64(aOrbiterA, 39U)) + aOrbiterI);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 11U) + aOrbiterD) + RotL64(aOrbiterB, 56U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 24U) ^ aWandererA);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererC, 53U);
            aCarry = aCarry + RotL64(aIngress, 56U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 29U) ^ RotL64(aNonceWordF, 50U)) ^ RotL64(aNonceWordH, 21U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 26891U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((aIndex + 27028U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 21U) ^ RotL64(aNonceWordA, 37U)) ^ RotL64(aNonceWordD, 13U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 30397U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneD[((aIndex + 31771U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aIngress, 53U)) ^ (RotL64(aCarry, 27U) ^ RotL64(aPrevious, 14U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (((aWandererD + RotL64(aIngress, 19U)) + 17912271996338180948U) + aOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1]) + RotL64(aNonceWordE, 19U);
            aOrbiterC = ((aWandererH + RotL64(aScatter, 37U)) + RotL64(aCarry, 53U)) + 13259276608841847058U;
            aOrbiterE = (((aWandererE + RotL64(aCross, 13U)) + 16225936008657276089U) + aOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1]) + RotL64(aNonceWordC, 22U);
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 60U)) + RotL64(aCarry, 11U)) + 2243058962151834071U;
            aOrbiterK = ((aWandererJ + RotL64(aCross, 27U)) + RotL64(aCarry, 3U)) + 10637439274127347861U;
            aOrbiterI = (aWandererI + RotL64(aPrevious, 51U)) + 15312219216405992627U;
            aOrbiterD = (aWandererK + RotL64(aIngress, 43U)) + 2393933972129878613U;
            aOrbiterG = (aWandererA + RotL64(aScatter, 6U)) + 4327069337247976513U;
            aOrbiterA = (aWandererC + RotL64(aIngress, 23U)) + 8307656353434167837U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 17299145556933889336U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 14458100581172798164U) ^ aOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16543734663677070509U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 6410095654927998067U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 6168964796264687686U;
            aOrbiterK = RotL64((aOrbiterK * 16218071040190475953U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 3667999465041020730U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 16021552859323602007U) ^ RotL64(aNonceWordA, 13U);
            aOrbiterD = RotL64((aOrbiterD * 6427266472526362663U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 12941668202330045095U) + RotL64(aNonceWordF, 57U);
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 4222032891850449934U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17292856787431308097U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 1346342592002730785U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 16860611785008118820U;
            aOrbiterH = RotL64((aOrbiterH * 384963420804756607U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 3193572711804730241U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 5866881282680588589U;
            aOrbiterI = RotL64((aOrbiterI * 9226331800853634597U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 17180332731328479126U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 10222097519535882241U) ^ aOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9422887302872778795U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 8863502179821584859U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 14872318155712512999U;
            aOrbiterA = RotL64((aOrbiterA * 11830641277356873233U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 16478790641892781150U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 8414944141232294781U;
            aOrbiterC = RotL64((aOrbiterC * 17443775794621154023U), 29U);
            //
            aIngress = RotL64(aOrbiterE, 57U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterI, 47U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterD, 5U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterA, 21U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterG, 42U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterE, 60U)) + aOrbiterH) + aWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 53U) + aOrbiterC) + RotL64(aOrbiterE, 27U)) + RotL64(aCarry, 11U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 34U) + RotL64(aOrbiterD, 53U)) + aOrbiterC);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterD, 47U)) + aOrbiterA);
            aWandererE = aWandererE ^ ((RotL64(aCross, 19U) + aOrbiterE) + RotL64(aOrbiterG, 11U));
            aWandererK = aWandererK + ((RotL64(aIngress, 29U) + aOrbiterH) + RotL64(aOrbiterB, 41U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterI, 23U)) + aOrbiterD) + RotL64(aNonceWordG, 31U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 10U) + aOrbiterE) + RotL64(aOrbiterK, 37U)) + RotL64(aCarry, 19U));
            aWandererH = aWandererH ^ ((((RotL64(aIngress, 57U) + RotL64(aOrbiterH, 6U)) + aOrbiterA) + RotL64(aNonceWordB, 41U)) + aWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 30U));
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + RotL64(aWandererA, 39U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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

void TwistExpander_Boxing_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xDB634F61587E91A1ULL + 0xDE1014C4498957A1ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xC2836F08DEAD0E0BULL + 0xF7EC4D48ED3F13BEULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x9409A738F19F3233ULL + 0x9712272CA5AEEA79ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xD2C7A606286F8929ULL + 0x81EF0C5160BCD5E3ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xDC80EF8E336BC46BULL + 0x8381E2866D16FD0CULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xF96EBEE4395262B7ULL + 0x91A37B98B7ABCC74ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xE195BF2B5E7E8411ULL + 0xC77756608A3BF766ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xEFC128D618F4953BULL + 0x8C419A89A08F792CULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 43U) ^ RotL64(aNonceWordD, 60U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 3672U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneC[((aIndex + 3822U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 39U) ^ RotL64(aNonceWordA, 56U)) ^ RotL64(aNonceWordE, 27U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 3976U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneA[((aIndex + 6259U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aPrevious, 27U)) + (RotL64(aCarry, 10U) + RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((aWandererD + RotL64(aIngress, 37U)) + RotL64(aCarry, 57U)) + 1898718075389870739U;
            aOrbiterG = ((((aWandererC + RotL64(aCross, 3U)) + RotL64(aCarry, 27U)) + 5631794889237247403U) + aOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1]) + RotL64(aNonceWordG, 19U);
            aOrbiterE = (aWandererK + RotL64(aScatter, 57U)) + 18219714659484524607U;
            aOrbiterI = (((aWandererJ + RotL64(aPrevious, 48U)) + RotL64(aCarry, 39U)) + 15419581386225732921U) + RotL64(aNonceWordD, 17U);
            aOrbiterD = ((aWandererA + RotL64(aIngress, 19U)) + 9125575431710198210U) + aOrbiterAssignSaltF[((aIndex + 28U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 12205871520544965505U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 7617534300497343422U;
            aOrbiterE = RotL64((aOrbiterE * 10052675719887595625U), 41U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterD) + 18017579105368135814U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]) + RotL64(aNonceWordC, 58U);
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 10693882161946020042U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2326507900303932855U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 11669615701700895306U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 11045110212889232165U) ^ aOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5965171269273719849U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 18019107802806469913U) + RotL64(aNonceWordA, 11U);
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 12315940560472528716U;
            aOrbiterG = RotL64((aOrbiterG * 4505122470351404065U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 4899009736070044310U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 17412253404253730364U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10791901166391946485U), 19U);
            //
            aIngress = RotL64(aOrbiterD, 3U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + RotL64(aOrbiterG, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aPrevious, 19U) + aOrbiterH) + RotL64(aOrbiterD, 21U));
            aWandererK = aWandererK ^ ((((RotL64(aScatter, 3U) + RotL64(aOrbiterD, 34U)) + aOrbiterE) + RotL64(aNonceWordF, 59U)) + aWandererUpdateSaltD[((aIndex + 14U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 57U) + aOrbiterG) + RotL64(aOrbiterI, 13U)) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterI, 43U)) + aOrbiterH);
            aWandererC = aWandererC + (((((RotL64(aScatter, 46U) + aOrbiterD) + RotL64(aOrbiterG, 3U)) + RotL64(aCarry, 21U)) + RotL64(aNonceWordB, 49U)) + aWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererJ, 30U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 6U) ^ RotL64(aNonceWordG, 57U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 11672U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneD[((aIndex + 11086U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 5U) ^ RotL64(aNonceWordE, 36U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 14185U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneB[((aIndex + 15009U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCross, 41U)) + (RotL64(aPrevious, 56U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (((aWandererG + RotL64(aCross, 60U)) + RotL64(aCarry, 39U)) + 16519040829220310189U) + RotL64(aNonceWordF, 46U);
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 51U)) + 6888002778416941825U) + aOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = ((((aWandererE + RotL64(aIngress, 41U)) + RotL64(aCarry, 27U)) + 1310832187746534025U) + aOrbiterAssignSaltE[((aIndex + 12U)) & S_SALT1]) + RotL64(aNonceWordE, 41U);
            aOrbiterE = ((aWandererC + RotL64(aScatter, 29U)) + RotL64(aCarry, 57U)) + 5890888009051281674U;
            aOrbiterH = (aWandererD + RotL64(aPrevious, 21U)) + 5143864838362464857U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 15591534069452660003U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 1466867671765325096U;
            aOrbiterF = RotL64((aOrbiterF * 1277202105237572301U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 13931443680107902488U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 15400747367673245552U) ^ aOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7011651369456453127U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 2836975369734495759U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 2370720358274970117U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4615571902817575375U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 3470677184188006133U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 7175584278499266723U) ^ RotL64(aNonceWordG, 59U);
            aOrbiterJ = RotL64((aOrbiterJ * 10067096593682482345U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 6095078817776863055U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 2176637999243513070U) ^ RotL64(aNonceWordD, 23U);
            aOrbiterE = RotL64((aOrbiterE * 12215701810843975501U), 13U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterA, 13U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 23U));
            aIngress = aIngress + RotL64(aOrbiterF, 36U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aPrevious, 53U) + aOrbiterA) + RotL64(aOrbiterH, 5U)) + RotL64(aCarry, 29U)) + RotL64(aNonceWordB, 57U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterJ, 21U)) + aOrbiterE);
            aWandererA = aWandererA + (((RotL64(aCross, 11U) + RotL64(aOrbiterH, 35U)) + aOrbiterF) + aWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((((RotL64(aIngress, 44U) + RotL64(aOrbiterA, 44U)) + aOrbiterE) + RotL64(aNonceWordH, 29U)) + aWandererUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 21U) + RotL64(aOrbiterA, 53U)) + aOrbiterJ) + RotL64(aCarry, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererD);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + RotL64(aWandererC, 3U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 35U) ^ RotL64(aNonceWordH, 43U)) ^ RotL64(aNonceWordC, 53U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 23676U)) & S_BLOCK1], 22U) ^ RotL64(aWorkLaneA[((aIndex + 21650U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 43U) ^ RotL64(aNonceWordF, 51U)) ^ RotL64(aNonceWordD, 21U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 18745U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneC[((aIndex + 21434U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 54U)) + (RotL64(aCross, 35U) + RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (aWandererD + RotL64(aPrevious, 29U)) + 9774364261626083532U;
            aOrbiterD = (((aWandererI + RotL64(aIngress, 37U)) + RotL64(aCarry, 35U)) + 18059001521926116420U) + aOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = ((((aWandererB + RotL64(aScatter, 11U)) + RotL64(aCarry, 13U)) + 10615626210406381148U) + aOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1]) + RotL64(aNonceWordE, 60U);
            aOrbiterE = ((aWandererK + RotL64(aCross, 21U)) + RotL64(aCarry, 57U)) + 10536484278007898620U;
            aOrbiterA = ((aWandererE + RotL64(aScatter, 54U)) + 13320663045139972700U) + RotL64(aNonceWordH, 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 17127001787268166583U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 16742574590844166551U) ^ aOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17828964140627204983U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 8347719720758228053U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 13502468705946051986U) ^ aOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13822952083584784695U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 3512687886188904904U) + aOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 495660316165795934U;
            aOrbiterF = RotL64((aOrbiterF * 6724596801190194913U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 5092722552034477356U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 15641128019608284015U) ^ RotL64(aNonceWordF, 7U);
            aOrbiterE = RotL64((aOrbiterE * 3621036395703527059U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 15421873776811085458U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 17978775513204574125U) ^ RotL64(aNonceWordD, 57U);
            aOrbiterA = RotL64((aOrbiterA * 18359600395119440183U), 19U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterD, 11U);
            aIngress = aIngress + (RotL64(aOrbiterE, 23U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterF, 58U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aPrevious, 29U) + aOrbiterG) + RotL64(aOrbiterA, 11U)) + RotL64(aCarry, 37U)) + RotL64(aNonceWordB, 49U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterG, 3U)) + aOrbiterE);
            aWandererK = aWandererK + (((((RotL64(aIngress, 19U) + aOrbiterD) + RotL64(aOrbiterF, 27U)) + RotL64(aCarry, 5U)) + RotL64(aNonceWordA, 15U)) + aWandererUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterF, 40U)) + aOrbiterE) + aWandererUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 56U) + RotL64(aOrbiterE, 19U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + RotL64(aWandererI, 56U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 21U) ^ RotL64(aNonceWordG, 52U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 25526U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((aIndex + 29446U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 41U) ^ RotL64(aNonceWordH, 23U)) ^ RotL64(aNonceWordE, 5U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25631U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneD[((aIndex + 26520U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 41U) + RotL64(aIngress, 54U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (aWandererK + RotL64(aPrevious, 19U)) + 7960325128608297381U;
            aOrbiterE = ((((aWandererC + RotL64(aIngress, 34U)) + RotL64(aCarry, 37U)) + 12773836012104052042U) + aOrbiterAssignSaltA[((aIndex + 10U)) & S_SALT1]) + RotL64(aNonceWordC, 15U);
            aOrbiterF = (aWandererH + RotL64(aScatter, 51U)) + 3173972621347773016U;
            aOrbiterG = (((aWandererF + RotL64(aCross, 3U)) + RotL64(aCarry, 13U)) + 3708401356314308171U) + aOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = (((aWandererJ + RotL64(aScatter, 43U)) + RotL64(aCarry, 57U)) + 950774285720019449U) + RotL64(aNonceWordB, 58U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 4170092315705438265U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 17000449130864980747U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7710635557693533263U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 8793910540062893860U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterG) ^ 520277969543516469U) ^ aOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1]) ^ RotL64(aNonceWordD, 25U);
            aOrbiterC = RotL64((aOrbiterC * 4150613128885828229U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 12762214857389827271U) + aOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 2932451184340207695U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7513337346940091655U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 11062179998786293839U) + RotL64(aNonceWordE, 11U);
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 7919119215271524178U;
            aOrbiterE = RotL64((aOrbiterE * 9053677007180081359U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 1774988449597115155U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 3799792889466518953U;
            aOrbiterK = RotL64((aOrbiterK * 17512791286490623455U), 35U);
            //
            aIngress = RotL64(aOrbiterE, 30U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 43U));
            aIngress = aIngress + RotL64(aOrbiterC, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterE, 19U)) + aOrbiterF);
            aWandererH = aWandererH + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterF, 29U)) + aOrbiterG) + RotL64(aCarry, 19U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 43U) + aOrbiterC) + RotL64(aOrbiterK, 40U)) + RotL64(aNonceWordH, 5U));
            aWandererF = aWandererF + ((((RotL64(aCross, 12U) + aOrbiterC) + RotL64(aOrbiterG, 51U)) + RotL64(aCarry, 35U)) + aWandererUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((((RotL64(aIngress, 21U) + aOrbiterK) + RotL64(aOrbiterG, 5U)) + RotL64(aNonceWordA, 9U)) + aWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + RotL64(aWandererJ, 22U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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

void TwistExpander_Boxing_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xBC6DD832F8E2F95FULL + 0xC945A85AF9A6D7CDULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xCB952A01FDE67B4DULL + 0xE28A1D24D0455644ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xC73C03A6D588D4A7ULL + 0xE68917C469989479ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xB0E6B3EBD622AAD7ULL + 0xD941DC6F82FC9E07ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x81FC9E93920A075DULL + 0xC206BF04557DA27BULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xFD6C3FB7ECC831A3ULL + 0x8DA48BA333DEFBACULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xA603E06D73042EB9ULL + 0xF2E02C36DB6928D2ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xA7F62D3DE1EE04EBULL + 0xEFC894A1A62DCCF0ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordA, 11U) ^ RotL64(aNonceWordF, 29U)) ^ RotL64(aNonceWordE, 19U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 7449U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneC[((aIndex + 7775U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 39U) ^ RotL64(aNonceWordC, 3U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 1706U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((aIndex + 4313U)) & S_BLOCK1], 50U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 41U) ^ RotL64(aCross, 54U)) ^ (RotL64(aPrevious, 29U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 23U)) + 14157904117287696136U) + RotL64(aNonceWordB, 35U);
            aOrbiterH = ((aWandererF + RotL64(aScatter, 14U)) + 7369512677371640676U) + aOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = ((aWandererE + RotL64(aCross, 41U)) + RotL64(aCarry, 29U)) + 8411250745902073798U;
            aOrbiterC = (aWandererA + RotL64(aIngress, 5U)) + 5002041814539710275U;
            aOrbiterK = (((aWandererG + RotL64(aScatter, 29U)) + RotL64(aCarry, 53U)) + 9538041410816283124U) + aOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = ((aWandererI + RotL64(aIngress, 51U)) + 5210700103927513061U) + RotL64(aNonceWordA, 51U);
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 57U)) + RotL64(aCarry, 11U)) + 7600709399101287982U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 2366369466696580499U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 5544575244203019109U;
            aOrbiterF = RotL64((aOrbiterF * 16231219246786333057U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 8710073749110329779U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterC) ^ 15998211310115361630U) ^ aOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1]) ^ RotL64(aNonceWordD, 46U);
            aOrbiterK = RotL64((aOrbiterK * 15275657696897688955U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 15354357553877376422U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 10657523549259276169U;
            aOrbiterD = RotL64((aOrbiterD * 13695239532898311073U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 10405750198355464768U) + RotL64(aNonceWordF, 43U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 3465819693133515142U;
            aOrbiterJ = RotL64((aOrbiterJ * 14678343718277562799U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 16724189641701408630U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 3484340153620198872U;
            aOrbiterG = RotL64((aOrbiterG * 17247547677520703125U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 7420442404884871126U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 11138445997256757636U;
            aOrbiterC = RotL64((aOrbiterC * 11167543379937571127U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 1428191560884663125U) + aOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 16950093140800653985U) ^ aOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4423012306984814805U), 19U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterH, 29U);
            aIngress = aIngress + (RotL64(aOrbiterD, 44U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + RotL64(aOrbiterK, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 38U) + RotL64(aOrbiterF, 3U)) + aOrbiterC);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 47U) + RotL64(aOrbiterH, 20U)) + aOrbiterG) + RotL64(aCarry, 39U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 29U) + aOrbiterC) + RotL64(aOrbiterJ, 11U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 19U) + aOrbiterK) + RotL64(aOrbiterH, 35U));
            aWandererG = aWandererG ^ ((((RotL64(aScatter, 57U) + aOrbiterJ) + RotL64(aOrbiterK, 51U)) + RotL64(aNonceWordH, 53U)) + aWandererUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aIngress, 5U) + RotL64(aOrbiterD, 41U)) + aOrbiterC) + RotL64(aCarry, 13U)) + RotL64(aNonceWordE, 47U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterJ, 29U)) + aOrbiterF) + aWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 43U));
            aCarry = aCarry + (RotL64(aWandererA, 37U) ^ aWandererE);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 58U));
            aCarry = aCarry + RotL64(aWandererC, 23U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 51U) ^ RotL64(aNonceWordF, 43U)) ^ RotL64(aNonceWordG, 26U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 14115U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16315U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 24U) ^ RotL64(aNonceWordA, 13U)) ^ RotL64(aNonceWordE, 3U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8449U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneB[((aIndex + 8698U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 3U) ^ RotL64(aCross, 54U)) ^ (RotL64(aPrevious, 39U) + RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((aWandererF + RotL64(aScatter, 11U)) + RotL64(aCarry, 11U)) + 16424657151168221875U;
            aOrbiterC = (((aWandererA + RotL64(aCross, 35U)) + RotL64(aCarry, 39U)) + 17150123681886380361U) + RotL64(aNonceWordF, 31U);
            aOrbiterB = (aWandererK + RotL64(aPrevious, 58U)) + 16041993588694572757U;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 51U)) + 9871185846434828537U) + aOrbiterAssignSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = (aWandererC + RotL64(aCross, 29U)) + 11227236398354430757U;
            aOrbiterA = (((aWandererJ + RotL64(aPrevious, 41U)) + RotL64(aCarry, 53U)) + 5399325217402192631U) + RotL64(aNonceWordA, 25U);
            aOrbiterG = ((aWandererE + RotL64(aIngress, 19U)) + 9248828789282890454U) + aOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 9041370494203701062U) + aOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 14944424084524970764U;
            aOrbiterB = RotL64((aOrbiterB * 10283363059424655079U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 5481938174456671041U) + aOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 14783648629543752715U;
            aOrbiterH = RotL64((aOrbiterH * 7260164783191886395U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 12355573914530445723U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 9863991559011968318U) ^ RotL64(aNonceWordH, 29U);
            aOrbiterF = RotL64((aOrbiterF * 8495251211794343179U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 16149688605937250965U) + aOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 106041828692026825U;
            aOrbiterC = RotL64((aOrbiterC * 12199934305374582599U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 8076098639554567792U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 11155119311895580013U;
            aOrbiterI = RotL64((aOrbiterI * 1495180896564818647U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 6847612160595917702U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 16094377920388017367U;
            aOrbiterA = RotL64((aOrbiterA * 4875801863643206333U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 13584719866672696684U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 13446209321646234607U) ^ RotL64(aNonceWordB, 39U);
            aOrbiterG = RotL64((aOrbiterG * 9945349065094781529U), 27U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterF, 51U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 57U));
            aIngress = aIngress + (RotL64(aOrbiterI, 5U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterG, 44U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 51U) + aOrbiterG) + RotL64(aOrbiterI, 57U)) + RotL64(aNonceWordG, 10U));
            aWandererC = aWandererC + (((RotL64(aCross, 29U) + RotL64(aOrbiterH, 37U)) + aOrbiterA) + aWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterF, 12U)) + aOrbiterB);
            aWandererI = aWandererI + ((((RotL64(aScatter, 19U) + aOrbiterG) + RotL64(aOrbiterB, 43U)) + RotL64(aCarry, 53U)) + RotL64(aNonceWordC, 57U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 44U) + RotL64(aOrbiterC, 5U)) + aOrbiterH);
            aWandererF = aWandererF + (((RotL64(aCross, 5U) + aOrbiterC) + RotL64(aOrbiterI, 27U)) + RotL64(aCarry, 19U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 37U) + aOrbiterA) + RotL64(aOrbiterC, 19U)) + aWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 46U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + (RotL64(aWandererA, 41U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererJ, 21U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 12U) ^ RotL64(aNonceWordA, 23U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 17257U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16995U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 57U) ^ RotL64(aNonceWordC, 28U)) ^ RotL64(aNonceWordG, 13U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 21037U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneC[((aIndex + 24140U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 38U) ^ RotL64(aCross, 23U)) + (RotL64(aCarry, 11U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 11U)) + 3255291173184001106U) + RotL64(aNonceWordD, 21U);
            aOrbiterC = ((((aWandererD + RotL64(aCross, 23U)) + RotL64(aCarry, 39U)) + 15308468160116255528U) + aOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1]) + RotL64(aNonceWordA, 35U);
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 35U)) + RotL64(aCarry, 3U)) + 18186972408589866656U;
            aOrbiterE = (aWandererA + RotL64(aIngress, 56U)) + 4439324265978331914U;
            aOrbiterG = (aWandererE + RotL64(aScatter, 3U)) + 13099263173016322486U;
            aOrbiterI = ((aWandererI + RotL64(aIngress, 47U)) + RotL64(aCarry, 27U)) + 7041561081767500660U;
            aOrbiterK = ((aWandererH + RotL64(aCross, 29U)) + 6196422612687812971U) + aOrbiterAssignSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 7664260932541281413U) + RotL64(aNonceWordG, 7U);
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 17802347823020441056U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2220679459017369255U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 4253107484061190446U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 13799496534030645312U;
            aOrbiterC = RotL64((aOrbiterC * 9167675060053848207U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 14252892847595951926U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 5663527578664291422U) ^ aOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 18314294235895182465U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 11148755959699137661U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 17036900929333594592U;
            aOrbiterE = RotL64((aOrbiterE * 16041243617369003291U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 2403828181385259549U) + aOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 17813580350434928194U;
            aOrbiterG = RotL64((aOrbiterG * 13666780980793857831U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 5623611126885414523U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 7293224381174846969U) ^ RotL64(aNonceWordE, 27U);
            aOrbiterI = RotL64((aOrbiterI * 7032561584670788117U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 10602620906929686163U) + aOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 18015916257203385982U;
            aOrbiterK = RotL64((aOrbiterK * 10684090189688871993U), 29U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterI, 29U);
            aIngress = aIngress + (RotL64(aOrbiterG, 5U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterE, 56U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterH, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aIngress, 60U) + RotL64(aOrbiterE, 47U)) + aOrbiterI);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 51U) + aOrbiterI) + RotL64(aOrbiterG, 41U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 11U) + RotL64(aOrbiterE, 21U)) + aOrbiterJ);
            aWandererD = aWandererD ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterI, 35U)) + aOrbiterH);
            aWandererG = aWandererG + (((((RotL64(aPrevious, 35U) + RotL64(aOrbiterC, 29U)) + aOrbiterJ) + RotL64(aCarry, 51U)) + RotL64(aNonceWordB, 13U)) + aWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((((RotL64(aCross, 41U) + aOrbiterG) + RotL64(aOrbiterK, 57U)) + RotL64(aNonceWordF, 60U)) + aWandererUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 3U) + RotL64(aOrbiterH, 10U)) + aOrbiterJ) + RotL64(aCarry, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 22U) ^ aWandererE);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + RotL64(aWandererH, 5U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 53U) ^ RotL64(aNonceWordH, 10U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 26741U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneB[((aIndex + 30610U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 35U) ^ RotL64(aNonceWordA, 56U)) ^ RotL64(aNonceWordE, 19U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 28526U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((aIndex + 24896U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 37U) ^ RotL64(aCarry, 24U)) + (RotL64(aCross, 51U) + RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (((aWandererA + RotL64(aScatter, 53U)) + RotL64(aCarry, 53U)) + 4068921616130916949U) + aOrbiterAssignSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = ((aWandererG + RotL64(aCross, 11U)) + 12077715273915151726U) + RotL64(aNonceWordH, 46U);
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 3U)) + RotL64(aCarry, 39U)) + 16047546802670596833U;
            aOrbiterI = ((aWandererK + RotL64(aIngress, 23U)) + RotL64(aCarry, 3U)) + 9690277462716999763U;
            aOrbiterJ = ((aWandererH + RotL64(aCross, 43U)) + 14484814700447992628U) + RotL64(aNonceWordC, 7U);
            aOrbiterB = (aWandererJ + RotL64(aPrevious, 37U)) + 17089267243053958210U;
            aOrbiterG = ((aWandererI + RotL64(aScatter, 30U)) + 9138746214446211147U) + aOrbiterAssignSaltB[((aIndex + 26U)) & S_SALT1];
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 10181001536979097045U) + RotL64(aNonceWordF, 31U);
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 6657458969093373191U) ^ RotL64(aNonceWordB, 49U);
            aOrbiterC = RotL64((aOrbiterC * 4311019792293202747U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 7515983477876590988U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 3039935555863947600U) ^ aOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12511160550780270119U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 16209389224740851136U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 725253312098083182U) ^ aOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17535989492095522597U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 13307041115748941383U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 7159572004825238263U;
            aOrbiterJ = RotL64((aOrbiterJ * 4855009895002398449U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 12027236743251643820U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 8717826175991286553U;
            aOrbiterK = RotL64((aOrbiterK * 1175614802543098451U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 4769096034227659937U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 11201226563992939616U;
            aOrbiterI = RotL64((aOrbiterI * 15595355978388159931U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 17295978531215563256U) + aOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 11850923890626719833U;
            aOrbiterG = RotL64((aOrbiterG * 3854851059897397075U), 19U);
            //
            aIngress = RotL64(aOrbiterB, 43U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 5U));
            aIngress = aIngress + RotL64(aOrbiterC, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aIngress, 57U) + RotL64(aOrbiterK, 3U)) + aOrbiterC) + RotL64(aCarry, 5U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterI, 47U)) + aOrbiterB) + RotL64(aNonceWordD, 21U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterI, 27U)) + aOrbiterJ) + RotL64(aCarry, 47U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 35U) + aOrbiterD) + RotL64(aOrbiterJ, 14U));
            aWandererA = aWandererA + ((RotL64(aCross, 11U) + RotL64(aOrbiterJ, 57U)) + aOrbiterC);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 21U) + aOrbiterK) + RotL64(aOrbiterG, 39U)) + aWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aIngress, 42U) + RotL64(aOrbiterK, 21U)) + aOrbiterD) + RotL64(aNonceWordG, 39U)) + aWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 28U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererA, 3U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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

void TwistExpander_Boxing_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xDD54C549C7DE3FAFULL + 0xAA8E54D6BAFF3415ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x80162998EDB347BDULL + 0x9925FBFBAA9C98FAULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xA32B87AC0DAD8D7DULL + 0xB148033EAD0234FAULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x9442E6C73BE544CDULL + 0xA36AD7CFFCB57F46ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xB19AC3938ED1AD61ULL + 0x9BD12FD1326651A3ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xA5D1F39ED803CE3FULL + 0xAD15B51B90A4A296ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xF0D5171472AA7BA5ULL + 0xC99A58DBAFFA8547ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xBED5C344C043715DULL + 0x86F99F09080655E4ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 54U) ^ RotL64(aNonceWordC, 43U)) ^ RotL64(aNonceWordF, 35U));
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 6185U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneC[((aIndex + 7025U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 51U) ^ RotL64(aNonceWordA, 12U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 6626U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneA[((aIndex + 3488U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 22U) + RotL64(aCross, 5U)) ^ (RotL64(aIngress, 57U) + RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererH + RotL64(aPrevious, 23U)) + 12669015908335980355U;
            aOrbiterF = (aWandererA + RotL64(aCross, 5U)) + 5438715179868613192U;
            aOrbiterA = ((aWandererB + RotL64(aIngress, 53U)) + 13172104448184536460U) + RotL64(aNonceWordA, 5U);
            aOrbiterC = ((aWandererE + RotL64(aScatter, 34U)) + 13421421503244744803U) + aOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = (((aWandererJ + RotL64(aPrevious, 13U)) + RotL64(aCarry, 39U)) + 13327113302994856582U) + RotL64(aNonceWordD, 14U);
            aOrbiterK = (((aWandererD + RotL64(aScatter, 47U)) + RotL64(aCarry, 51U)) + 4671768205922454413U) + aOrbiterAssignSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterB = ((aWandererG + RotL64(aIngress, 41U)) + RotL64(aCarry, 3U)) + 5355759962838579929U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 6691720614265406851U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 7063906424700911378U) ^ aOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17091734375516280675U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 17328616394166672263U) + RotL64(aNonceWordG, 49U);
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 1542940602574207068U;
            aOrbiterH = RotL64((aOrbiterH * 8981679306319627975U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 7203866278803132454U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 993485696233139264U;
            aOrbiterK = RotL64((aOrbiterK * 11609009908810366447U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 15659679028507488331U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 18321361454094675842U;
            aOrbiterB = RotL64((aOrbiterB * 3966860765622641843U), 19U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterB) + 9633319822696783352U) + aOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1]) + RotL64(aNonceWordB, 3U);
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 3496559332232402963U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7772060229838162977U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 1918349708324205526U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 7701088402761359134U;
            aOrbiterC = RotL64((aOrbiterC * 9649485438465644795U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 6006824348814439686U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 18088375375347012557U;
            aOrbiterF = RotL64((aOrbiterF * 12801082943086128385U), 29U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterK, 35U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 60U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 11U));
            aIngress = aIngress + RotL64(aOrbiterC, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aScatter, 10U) + aOrbiterH) + RotL64(aOrbiterJ, 41U)) + RotL64(aCarry, 21U));
            aWandererA = aWandererA ^ ((((RotL64(aPrevious, 3U) + aOrbiterC) + RotL64(aOrbiterA, 13U)) + RotL64(aNonceWordH, 61U)) + aWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 27U) + aOrbiterJ) + RotL64(aOrbiterK, 47U)) + RotL64(aCarry, 51U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 51U) + aOrbiterC) + RotL64(aOrbiterK, 56U)) + RotL64(aNonceWordC, 13U));
            aWandererB = aWandererB + ((RotL64(aScatter, 57U) + RotL64(aOrbiterJ, 35U)) + aOrbiterB);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 35U) + aOrbiterB) + RotL64(aOrbiterF, 5U)) + aWandererUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterA, 19U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 41U));
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererE);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 12U));
            aCarry = aCarry + RotL64(aWandererG, 27U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 60U) ^ RotL64(aNonceWordF, 21U)) ^ RotL64(aNonceWordG, 41U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 12948U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneD[((aIndex + 9477U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 11U) ^ RotL64(aNonceWordA, 51U)) ^ RotL64(aNonceWordD, 60U));
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 12880U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 10572U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 58U) ^ RotL64(aCarry, 23U)) + (RotL64(aIngress, 11U) + RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((aWandererD + RotL64(aIngress, 6U)) + RotL64(aCarry, 27U)) + 5573188770530340913U;
            aOrbiterB = (aWandererF + RotL64(aCross, 21U)) + 1431772230889897111U;
            aOrbiterJ = (aWandererK + RotL64(aScatter, 13U)) + 4809192776429682319U;
            aOrbiterK = (((aWandererJ + RotL64(aPrevious, 37U)) + RotL64(aCarry, 13U)) + 5576603692574369341U) + RotL64(aNonceWordC, 31U);
            aOrbiterE = (((aWandererI + RotL64(aCross, 57U)) + RotL64(aCarry, 39U)) + 2720143226007220386U) + aOrbiterAssignSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterD = ((aWandererB + RotL64(aIngress, 43U)) + 17220328778565331629U) + RotL64(aNonceWordF, 4U);
            aOrbiterG = ((aWandererH + RotL64(aScatter, 51U)) + 9629485808442089423U) + aOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 1136998437010390983U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterF) ^ 11893390497814523841U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]) ^ RotL64(aNonceWordG, 29U);
            aOrbiterJ = RotL64((aOrbiterJ * 5329621622743089531U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 1764986431917532370U) + aOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 1741014798007010376U;
            aOrbiterF = RotL64((aOrbiterF * 13414914086049500731U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 12221368453236547044U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 7694538641172350430U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8439120733670016501U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 17472344518811560603U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 3308740700728172984U;
            aOrbiterB = RotL64((aOrbiterB * 15290400462887712083U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 9535358833412446771U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 11192312491731312451U;
            aOrbiterE = RotL64((aOrbiterE * 17405609148475445743U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 14850451970047190039U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 11932493299452443256U;
            aOrbiterD = RotL64((aOrbiterD * 7964808728820467795U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 5972619895614731870U) + RotL64(aNonceWordB, 53U);
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 17174497535809891690U) ^ aOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15471084511364572533U), 3U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterF, 11U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 35U));
            aIngress = aIngress + (RotL64(aOrbiterK, 41U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterB, 58U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterB, 13U)) + aOrbiterE) + aWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 13U) + RotL64(aOrbiterJ, 5U)) + aOrbiterD) + RotL64(aCarry, 39U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterK, 20U)) + aOrbiterE);
            aWandererH = aWandererH + (((((RotL64(aCross, 3U) + aOrbiterE) + RotL64(aOrbiterG, 51U)) + RotL64(aCarry, 21U)) + RotL64(aNonceWordH, 55U)) + aWandererUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 58U) + RotL64(aOrbiterF, 27U)) + aOrbiterG);
            aWandererD = aWandererD + (((RotL64(aPrevious, 39U) + aOrbiterG) + RotL64(aOrbiterJ, 35U)) + RotL64(aNonceWordA, 3U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterF, 41U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 56U));
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererK, 41U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 21U) ^ RotL64(aNonceWordB, 29U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 18982U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 20458U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 13U) ^ RotL64(aNonceWordA, 53U));
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 21525U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 18863U)) & S_BLOCK1], 44U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCarry, 11U)) + (RotL64(aPrevious, 39U) ^ RotL64(aCross, 24U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (aWandererB + RotL64(aIngress, 27U)) + 6024062041314952357U;
            aOrbiterG = ((aWandererJ + RotL64(aCross, 21U)) + 18340757093658015585U) + RotL64(aNonceWordA, 39U);
            aOrbiterD = ((aWandererH + RotL64(aScatter, 35U)) + RotL64(aCarry, 47U)) + 11911120493880346751U;
            aOrbiterC = ((((aWandererG + RotL64(aPrevious, 43U)) + RotL64(aCarry, 29U)) + 17428074353884654439U) + aOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1]) + RotL64(aNonceWordD, 9U);
            aOrbiterI = ((aWandererK + RotL64(aScatter, 57U)) + 12790849760814795936U) + aOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = (aWandererF + RotL64(aPrevious, 5U)) + 12633397052172117800U;
            aOrbiterE = ((aWandererI + RotL64(aIngress, 12U)) + RotL64(aCarry, 13U)) + 11946150433665237945U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 16842157900909419285U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 14186235783224155962U;
            aOrbiterD = RotL64((aOrbiterD * 10521157787073684417U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 13284904542579767591U) + RotL64(aNonceWordG, 15U);
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 11609181965078844357U;
            aOrbiterG = RotL64((aOrbiterG * 5455780554452453513U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 9628562297095374984U) + aOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 7850281529011259759U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17611485102925470357U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 257458718073794527U) + RotL64(aNonceWordE, 22U);
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 10693404545773519306U;
            aOrbiterC = RotL64((aOrbiterC * 14821443722828498323U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 3430519236533871460U) + aOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 6183054506953198055U;
            aOrbiterI = RotL64((aOrbiterI * 6121082743789970911U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 2905610989884221654U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 4472163910775333862U;
            aOrbiterA = RotL64((aOrbiterA * 7770678426310856745U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 16870142883133769663U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 1403692060594816451U;
            aOrbiterE = RotL64((aOrbiterE * 9740854430251597879U), 35U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterI, 39U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 21U));
            aIngress = aIngress + (RotL64(aOrbiterC, 47U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterA, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aIngress, 51U) + aOrbiterC) + RotL64(aOrbiterD, 35U)) + RotL64(aNonceWordH, 43U));
            aWandererF = aWandererF + ((RotL64(aScatter, 60U) + RotL64(aOrbiterF, 41U)) + aOrbiterG);
            aWandererB = aWandererB ^ ((RotL64(aCross, 29U) + aOrbiterD) + RotL64(aOrbiterG, 6U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 3U) + aOrbiterC) + RotL64(aOrbiterF, 13U)) + RotL64(aCarry, 29U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 11U) + aOrbiterE) + RotL64(aOrbiterA, 51U)) + RotL64(aNonceWordF, 51U));
            aWandererI = aWandererI + ((((RotL64(aCross, 39U) + RotL64(aOrbiterC, 21U)) + aOrbiterA) + RotL64(aCarry, 3U)) + aWandererUpdateSaltE[((aIndex + 6U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterC, 57U)) + aOrbiterI) + aWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 40U));
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererK, 11U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 39U) ^ RotL64(aNonceWordH, 11U)) ^ RotL64(aNonceWordB, 21U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 32422U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneB[((aIndex + 24864U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 27U) ^ RotL64(aNonceWordC, 4U)) ^ RotL64(aNonceWordE, 53U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28718U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 24671U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 19U) ^ RotL64(aCarry, 54U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (aWandererA + RotL64(aCross, 57U)) + 15920462086654025436U;
            aOrbiterD = ((aWandererK + RotL64(aIngress, 37U)) + 487844076858004017U) + aOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = (aWandererE + RotL64(aScatter, 13U)) + 14502883786442630566U;
            aOrbiterB = (((aWandererB + RotL64(aPrevious, 47U)) + RotL64(aCarry, 53U)) + 3787107318658233674U) + RotL64(aNonceWordB, 17U);
            aOrbiterI = ((aWandererC + RotL64(aScatter, 28U)) + RotL64(aCarry, 19U)) + 12548777544693755491U;
            aOrbiterK = ((aWandererG + RotL64(aCross, 21U)) + RotL64(aCarry, 37U)) + 4907309444075181683U;
            aOrbiterA = (((aWandererJ + RotL64(aIngress, 5U)) + 18342396700266492072U) + aOrbiterAssignSaltD[((aIndex + 24U)) & S_SALT1]) + RotL64(aNonceWordA, 49U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 13503051997624242670U) + RotL64(aNonceWordD, 60U);
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 17845742460521374571U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1366356786138085155U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 8640887211877858169U) + RotL64(aNonceWordG, 41U);
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 5273913123709097537U;
            aOrbiterK = RotL64((aOrbiterK * 1661149444148461791U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 17756844173695563883U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 6713055830729302951U;
            aOrbiterD = RotL64((aOrbiterD * 2832836748513174311U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 5106468334224035972U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 10228769728713526172U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9760310686414358435U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 7687649520668883142U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 7757480627354711605U;
            aOrbiterF = RotL64((aOrbiterF * 7222553727737349209U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 10876291698508634557U) + aOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 8149278085586014186U;
            aOrbiterB = RotL64((aOrbiterB * 8577133863470695381U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 15592893988925610485U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 8639028256640537165U;
            aOrbiterA = RotL64((aOrbiterA * 1880655276432963955U), 53U);
            //
            aIngress = RotL64(aOrbiterF, 11U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 21U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 48U));
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aIngress, 3U) + aOrbiterD) + RotL64(aOrbiterG, 3U)) + RotL64(aCarry, 11U)) + RotL64(aNonceWordE, 53U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 29U) + aOrbiterI) + RotL64(aOrbiterB, 54U)) + aWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aCross, 11U) + RotL64(aOrbiterD, 27U)) + aOrbiterB);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterF, 41U)) + aOrbiterK);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 50U) + aOrbiterA) + RotL64(aOrbiterD, 13U)) + RotL64(aCarry, 23U)) + RotL64(aNonceWordC, 13U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 21U) + aOrbiterG) + RotL64(aOrbiterB, 21U)) + aWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterI, 47U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 12U));
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + RotL64(aWandererK, 53U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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

void TwistExpander_Boxing_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xA3A4786C54FA6C07ULL + 0xC7EBB0E2B3BF75BCULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xFB76FA1FE5FFC7B1ULL + 0xEDB7F253F89316DAULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xEBAE2D961A8016FBULL + 0xF84D1D98BF2F92E8ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x82953DADD59F91A3ULL + 0xF1779D3AE646D4C1ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xD14535E34F5248D9ULL + 0xD632F0EDC5EEE5C1ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xEF29BF3F025FE5B7ULL + 0xCD3F87FDD423C475ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x91CBFDD2D3284F55ULL + 0x94DFFC82A047EC25ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xCA3337C11BD79757ULL + 0x837CFA43C3771AFDULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 53U) ^ RotL64(aNonceWordF, 5U)) ^ RotL64(aNonceWordG, 13U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 6868U)) & S_BLOCK1], 40U) ^ RotL64(aExpandLaneC[((aIndex + 2093U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 29U) ^ RotL64(aNonceWordC, 6U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 1717U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 6942U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCross, 35U)) + (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 50U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererB + RotL64(aCross, 29U)) + 18302975933754610273U;
            aOrbiterC = (aWandererK + RotL64(aScatter, 57U)) + 16736972646771456082U;
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 26U)) + 17389406266488137442U;
            aOrbiterD = (aWandererE + RotL64(aIngress, 21U)) + 5252511566486165539U;
            aOrbiterG = ((aWandererI + RotL64(aCross, 37U)) + 5730715427422747640U) + aOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 23U)) + RotL64(aCarry, 53U)) + 6412695646456045825U;
            aOrbiterK = ((aWandererD + RotL64(aScatter, 5U)) + RotL64(aCarry, 13U)) + 9539701605708994494U;
            aOrbiterH = ((aWandererA + RotL64(aIngress, 48U)) + 18355107116412945722U) + RotL64(aNonceWordC, 57U);
            aOrbiterI = (((aWandererH + RotL64(aCross, 43U)) + RotL64(aCarry, 21U)) + 11735742491750132942U) + aOrbiterAssignSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aIngress, 13U)) + 12363819388562658842U) + RotL64(aNonceWordA, 3U);
            aOrbiterB = (aWandererG + RotL64(aPrevious, 41U)) + 5861430292304371543U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 15027487084595017708U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 7012850020745791926U;
            aOrbiterA = RotL64((aOrbiterA * 15952928839355613939U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 11904871669287886120U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 11199760114477343208U;
            aOrbiterJ = RotL64((aOrbiterJ * 7156374911847525867U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 3856004502263742700U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 3705931243173921893U;
            aOrbiterE = RotL64((aOrbiterE * 10334871178498711485U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 12305785390539209389U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterI) ^ 18057980996551978823U) ^ aOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1]) ^ RotL64(aNonceWordB, 7U);
            aOrbiterD = RotL64((aOrbiterD * 4850564181113470859U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 3229431819292153014U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 2994716629242460094U) ^ RotL64(aNonceWordD, 11U);
            aOrbiterK = RotL64((aOrbiterK * 1029427328395257917U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 9796307843453735512U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 2957260393651252432U;
            aOrbiterI = RotL64((aOrbiterI * 7261055869794739609U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 4060469664218866340U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 17462081697889685330U;
            aOrbiterB = RotL64((aOrbiterB * 7712009170974461225U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 13638660073917821172U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 15202349592659062565U;
            aOrbiterC = RotL64((aOrbiterC * 4514326257446024301U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 12071949111168967041U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 11930843273199806728U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16229663295689525137U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 11294220104731500296U) + aOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 440743185210586759U;
            aOrbiterH = RotL64((aOrbiterH * 14810195235168807229U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 8514240764798061804U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 18302975933754610273U;
            aOrbiterF = RotL64((aOrbiterF * 1972439346780950873U), 43U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterG, 13U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 21U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 37U));
            aIngress = aIngress + (RotL64(aOrbiterI, 56U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterK, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterH, 11U)) + aOrbiterC) + aWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 11U) + RotL64(aOrbiterA, 26U)) + aOrbiterJ) + RotL64(aNonceWordG, 56U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterC, 13U)) + aOrbiterG);
            aWandererB = aWandererB + (((RotL64(aScatter, 35U) + RotL64(aOrbiterE, 41U)) + aOrbiterK) + aWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 56U) + aOrbiterK) + RotL64(aOrbiterC, 19U)) + RotL64(aNonceWordE, 41U));
            aWandererF = aWandererF + (((RotL64(aCross, 53U) + aOrbiterG) + RotL64(aOrbiterI, 47U)) + RotL64(aCarry, 53U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterK, 3U)) + aOrbiterA);
            aWandererA = aWandererA + (((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterD, 35U)) + RotL64(aCarry, 39U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 39U) + aOrbiterK) + RotL64(aOrbiterD, 5U));
            aWandererI = aWandererI + ((RotL64(aCross, 21U) + RotL64(aOrbiterF, 21U)) + aOrbiterJ);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 4U) + aOrbiterB) + RotL64(aOrbiterA, 58U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 54U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 37U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + (RotL64(aWandererK, 12U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererB, 27U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordE, 37U) ^ RotL64(aNonceWordB, 5U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 12999U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 9023U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 48U) ^ RotL64(aNonceWordD, 11U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9631U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 10447U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aIngress, 11U)) + (RotL64(aCross, 26U) ^ RotL64(aPrevious, 51U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererJ + RotL64(aScatter, 41U)) + 16124889768301047791U;
            aOrbiterG = ((aWandererB + RotL64(aIngress, 5U)) + RotL64(aCarry, 37U)) + 11912338587186717280U;
            aOrbiterK = (aWandererA + RotL64(aCross, 47U)) + 8594012868813114354U;
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 34U)) + 18281043566156682815U) + RotL64(aNonceWordF, 49U);
            aOrbiterD = (aWandererH + RotL64(aCross, 21U)) + 16853106130200942302U;
            aOrbiterJ = (((aWandererI + RotL64(aScatter, 29U)) + RotL64(aCarry, 47U)) + 2611212958619673086U) + aOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 57U)) + RotL64(aCarry, 23U)) + 18039472325066855180U;
            aOrbiterB = (aWandererG + RotL64(aIngress, 26U)) + 14495785571345122046U;
            aOrbiterE = ((aWandererF + RotL64(aScatter, 11U)) + 4556063793412832418U) + aOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = ((aWandererE + RotL64(aCross, 13U)) + 14896419970271244358U) + RotL64(aNonceWordH, 55U);
            aOrbiterH = (aWandererK + RotL64(aIngress, 23U)) + 880028529183500036U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 2379557167489415783U) + RotL64(aNonceWordA, 21U);
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 11854373946064529806U;
            aOrbiterK = RotL64((aOrbiterK * 150755294320438887U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 1487252775956449964U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 12777924204511625545U) ^ RotL64(aNonceWordC, 5U);
            aOrbiterG = RotL64((aOrbiterG * 1366019527386994789U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 15998631485222477969U) + aOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 8864212892296191613U;
            aOrbiterD = RotL64((aOrbiterD * 579242788050369815U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 17069347835763226743U) + aOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 7443008171694679791U;
            aOrbiterC = RotL64((aOrbiterC * 748894368884566607U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 17334256152350782002U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 8986626119086556393U;
            aOrbiterE = RotL64((aOrbiterE * 2258172145924120235U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 8528180968228358674U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 12702290928064582589U) ^ aOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15673603224146737631U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 7742438100860023610U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 3729687240959702198U;
            aOrbiterF = RotL64((aOrbiterF * 3756794766163746783U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 426129097367382096U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 16782175452274911213U;
            aOrbiterJ = RotL64((aOrbiterJ * 1041477289638333659U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 5942016166948841079U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 5260815086125551703U;
            aOrbiterB = RotL64((aOrbiterB * 1603799103692438147U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 11732742583346900772U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 17182924380693084401U;
            aOrbiterA = RotL64((aOrbiterA * 14858685629471497071U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 8539335803784852017U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 16124889768301047791U;
            aOrbiterH = RotL64((aOrbiterH * 6607245691919237755U), 3U);
            //
            aIngress = RotL64(aOrbiterD, 51U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterK, 30U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 21U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 5U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + RotL64(aOrbiterG, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 6U) + aOrbiterI) + RotL64(aOrbiterK, 41U));
            aWandererA = aWandererA + ((RotL64(aIngress, 27U) + aOrbiterK) + RotL64(aOrbiterF, 56U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterB, 53U)) + aOrbiterC);
            aWandererI = aWandererI + ((RotL64(aCross, 13U) + aOrbiterI) + RotL64(aOrbiterB, 3U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterC, 51U)) + aOrbiterF);
            aWandererD = aWandererD + ((((RotL64(aIngress, 53U) + aOrbiterE) + RotL64(aOrbiterK, 47U)) + RotL64(aCarry, 51U)) + aWandererUpdateSaltD[((aIndex + 24U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterD, 35U)) + aOrbiterI) + RotL64(aNonceWordE, 25U));
            aWandererK = aWandererK + (((RotL64(aCross, 30U) + RotL64(aOrbiterH, 26U)) + aOrbiterE) + aWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 57U) + aOrbiterG) + RotL64(aOrbiterJ, 37U));
            aWandererB = aWandererB + (((RotL64(aCross, 39U) + aOrbiterD) + RotL64(aOrbiterJ, 29U)) + RotL64(aCarry, 13U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 35U) + aOrbiterI) + RotL64(aOrbiterA, 43U)) + RotL64(aNonceWordG, 44U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 11U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 36U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 57U);
            aCarry = aCarry + RotL64(aIngress, 26U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 56U) ^ RotL64(aNonceWordE, 47U)) ^ RotL64(aNonceWordA, 35U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 23567U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 22380U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 35U) ^ RotL64(aNonceWordF, 3U)) ^ RotL64(aNonceWordH, 44U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16686U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 23057U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCross, 37U)) + (RotL64(aIngress, 51U) ^ RotL64(aCarry, 10U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (aWandererD + RotL64(aPrevious, 35U)) + 5510690816044082200U;
            aOrbiterF = (aWandererH + RotL64(aCross, 37U)) + 15967820875033940530U;
            aOrbiterE = ((aWandererB + RotL64(aIngress, 57U)) + 539348720848176221U) + RotL64(aNonceWordA, 31U);
            aOrbiterH = (((aWandererI + RotL64(aScatter, 11U)) + 15779318183635560817U) + aOrbiterAssignSaltC[(((31U - aIndex) + 14U)) & S_SALT1]) + RotL64(aNonceWordF, 53U);
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 4U)) + RotL64(aCarry, 51U)) + 14511058534424187469U;
            aOrbiterK = (aWandererC + RotL64(aScatter, 43U)) + 5811130556873428391U;
            aOrbiterA = (aWandererK + RotL64(aCross, 29U)) + 1085928476499444025U;
            aOrbiterI = ((aWandererE + RotL64(aIngress, 23U)) + RotL64(aCarry, 27U)) + 6973335316600768130U;
            aOrbiterC = (((aWandererG + RotL64(aCross, 13U)) + RotL64(aCarry, 19U)) + 10747243745475009744U) + aOrbiterAssignSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterD = (aWandererA + RotL64(aScatter, 26U)) + 1072260008981349754U;
            aOrbiterJ = (aWandererJ + RotL64(aPrevious, 39U)) + 2018772405352495753U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 1092091597048996547U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 15103140149542167197U;
            aOrbiterE = RotL64((aOrbiterE * 621856991658027989U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 13194619321108681542U) + aOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 16749188603268621850U;
            aOrbiterK = RotL64((aOrbiterK * 9575408950550922039U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 7427959503086895166U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 9895804051379551393U;
            aOrbiterF = RotL64((aOrbiterF * 2701997336201570715U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 4526020800679774259U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 4484850928870048176U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17556987520625677313U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 1837404844299040155U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 15213208978489570694U;
            aOrbiterI = RotL64((aOrbiterI * 7062740584650274133U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 9615231781751396800U) + aOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 15872192167825648096U) ^ RotL64(aNonceWordD, 23U);
            aOrbiterD = RotL64((aOrbiterD * 2900526493682580729U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 12530672039655918903U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 10617836782870315804U;
            aOrbiterB = RotL64((aOrbiterB * 9716778004909794973U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 550750725406860977U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 3498554352021622907U;
            aOrbiterH = RotL64((aOrbiterH * 9846933294851238495U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 4059346317776216057U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 14161853870874499023U;
            aOrbiterA = RotL64((aOrbiterA * 8601560894939097781U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 4088411647683253905U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 9321241420172776158U) ^ RotL64(aNonceWordC, 43U);
            aOrbiterC = RotL64((aOrbiterC * 4167888281125330225U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 8527337525861632945U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 5510690816044082200U) ^ aOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12464836001483233379U), 51U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterB, 53U);
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 41U));
            aIngress = aIngress + (RotL64(aOrbiterI, 39U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterJ, 47U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterG, 20U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aIngress, 37U) + aOrbiterA) + RotL64(aOrbiterF, 51U));
            aWandererK = aWandererK + (((RotL64(aScatter, 57U) + RotL64(aOrbiterF, 30U)) + aOrbiterD) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterC, 47U)) + aOrbiterJ);
            aWandererH = aWandererH + ((RotL64(aPrevious, 12U) + aOrbiterA) + RotL64(aOrbiterG, 5U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 39U) + aOrbiterJ) + RotL64(aOrbiterE, 23U)) + RotL64(aNonceWordB, 22U));
            aWandererB = aWandererB + (((RotL64(aScatter, 23U) + aOrbiterH) + RotL64(aOrbiterK, 35U)) + aWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterJ, 11U)) + aOrbiterI) + aWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 4U) + aOrbiterK) + RotL64(aOrbiterC, 44U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterG, 37U)) + aOrbiterF);
            aWandererD = aWandererD + ((((RotL64(aCross, 53U) + aOrbiterI) + RotL64(aOrbiterC, 57U)) + RotL64(aCarry, 5U)) + RotL64(aNonceWordH, 7U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 19U) + aOrbiterB) + RotL64(aOrbiterK, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 36U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererB);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 23U));
            aCarry = aCarry + (RotL64(aWandererE, 21U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererJ, 11U);
            aCarry = aCarry + RotL64(aIngress, 26U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 23U) ^ RotL64(aNonceWordA, 57U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 29627U)) & S_BLOCK1], 48U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 25671U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 46U) ^ RotL64(aNonceWordD, 11U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 31845U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 29367U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 34U) + RotL64(aCarry, 57U)) ^ (RotL64(aCross, 21U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (((aWandererA + RotL64(aCross, 13U)) + RotL64(aCarry, 11U)) + 9107326720193244489U) + RotL64(aNonceWordH, 41U);
            aOrbiterJ = (aWandererB + RotL64(aIngress, 5U)) + 10868585484401664145U;
            aOrbiterE = ((aWandererG + RotL64(aScatter, 53U)) + 13637736741437846622U) + aOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 37U)) + 6130725216183918844U;
            aOrbiterB = ((aWandererF + RotL64(aCross, 26U)) + 2063834478521338187U) + aOrbiterAssignSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 23U)) + RotL64(aCarry, 35U)) + 8564870627911949158U;
            aOrbiterK = ((aWandererH + RotL64(aIngress, 21U)) + RotL64(aCarry, 19U)) + 6524015751064086390U;
            aOrbiterI = (aWandererC + RotL64(aScatter, 11U)) + 9874937766875388236U;
            aOrbiterF = (aWandererI + RotL64(aIngress, 29U)) + 14723718409522680894U;
            aOrbiterD = (aWandererK + RotL64(aCross, 44U)) + 13767059954741528279U;
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 41U)) + 6387608251033722169U) + RotL64(aNonceWordG, 55U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 5391425980008431000U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 11524218415655093779U;
            aOrbiterE = RotL64((aOrbiterE * 12508457981779189389U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 155510463350385905U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 10554591788433641311U;
            aOrbiterB = RotL64((aOrbiterB * 5412084824127934293U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 8662160162966241542U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 5092555636369853727U;
            aOrbiterC = RotL64((aOrbiterC * 433807340167635499U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 7163345798448796101U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 695089002178413267U;
            aOrbiterK = RotL64((aOrbiterK * 17302689458565434475U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 5409173939213468972U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 15349690077393827541U) ^ RotL64(aNonceWordD, 8U);
            aOrbiterI = RotL64((aOrbiterI * 10984681254001609841U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 12376011890751302027U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 7809614158898158383U;
            aOrbiterF = RotL64((aOrbiterF * 13845113198736843629U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 13031938699536449576U) + RotL64(aNonceWordB, 3U);
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 3983178190194056516U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1341678482929213405U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 5567935037909671790U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 17137042627663349797U;
            aOrbiterH = RotL64((aOrbiterH * 13535586899620672373U), 37U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 8726085717433137208U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 13154097637429217548U) ^ aOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5523758597936082363U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 4030516340575723215U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 7121696965917254968U;
            aOrbiterJ = RotL64((aOrbiterJ * 13569584361980228493U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 12079991626282752674U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 9107326720193244489U;
            aOrbiterA = RotL64((aOrbiterA * 7225937408665051799U), 23U);
            //
            aIngress = RotL64(aOrbiterJ, 27U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 41U));
            aIngress = aIngress + (RotL64(aOrbiterD, 34U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 43U));
            aIngress = aIngress + (RotL64(aOrbiterA, 51U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterH, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aScatter, 14U) + RotL64(aOrbiterI, 52U)) + aOrbiterB) + aWandererUpdateSaltE[((aIndex + 12U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterI, 23U)) + aOrbiterK) + aWandererUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterG, 11U)) + aOrbiterC) + RotL64(aNonceWordF, 23U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 51U) + aOrbiterF) + RotL64(aOrbiterE, 41U));
            aWandererE = aWandererE + ((RotL64(aScatter, 39U) + RotL64(aOrbiterJ, 21U)) + aOrbiterA);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterJ, 30U)) + aOrbiterB);
            aWandererD = aWandererD + ((RotL64(aIngress, 5U) + RotL64(aOrbiterD, 57U)) + aOrbiterE);
            aWandererG = aWandererG ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterB, 39U)) + aOrbiterG);
            aWandererA = aWandererA + (((RotL64(aIngress, 26U) + aOrbiterA) + RotL64(aOrbiterD, 27U)) + RotL64(aCarry, 29U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterH, 47U)) + aOrbiterI) + RotL64(aNonceWordE, 31U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 47U) + RotL64(aOrbiterG, 37U)) + aOrbiterF) + RotL64(aCarry, 19U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + (RotL64(aWandererF, 10U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererJ, 21U) ^ aWandererG);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererC, 30U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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

void TwistExpander_Boxing_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xAC21573C94D701A9ULL + 0xEED3D9C39D89E1F0ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x9885B4CE19133FF1ULL + 0x8D176789F072A8C2ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xDFD5D97AD9AC05E3ULL + 0x88BF9FAEC05FD809ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x9680903A00800A33ULL + 0xBF24C8AA47395781ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xF31195B12CFDF789ULL + 0x8F34770A99A33763ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xF277C86AC2D67543ULL + 0x9DCD540B31F2E523ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xF1D2CEE84CC3CF91ULL + 0xA269ADAF5F0DA696ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xC198C2CA1C32BE6DULL + 0xBA89A6C63FD3AF61ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 13U) ^ RotL64(aNonceWordC, 41U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 3550U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneC[((aIndex + 5281U)) & S_BLOCK1], 26U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 52U) ^ RotL64(aNonceWordE, 13U)) ^ RotL64(aNonceWordF, 41U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 2165U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((aIndex + 1362U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 41U) + RotL64(aCross, 23U)) ^ (RotL64(aIngress, 53U) + RotL64(aCarry, 4U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererA + RotL64(aCross, 57U)) + 12669015908335980355U;
            aOrbiterD = (aWandererJ + RotL64(aScatter, 4U)) + 5438715179868613192U;
            aOrbiterK = (((aWandererE + RotL64(aPrevious, 29U)) + 13172104448184536460U) + aOrbiterAssignSaltC[((aIndex + 24U)) & S_SALT1]) + RotL64(aNonceWordD, 37U);
            aOrbiterG = ((aWandererI + RotL64(aIngress, 43U)) + RotL64(aCarry, 19U)) + 13421421503244744803U;
            aOrbiterI = (((aWandererF + RotL64(aCross, 53U)) + 13327113302994856582U) + aOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1]) + RotL64(aNonceWordE, 39U);
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 48U)) + RotL64(aCarry, 41U)) + 4671768205922454413U;
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 11U)) + RotL64(aCarry, 27U)) + 5355759962838579929U;
            aOrbiterH = (aWandererG + RotL64(aIngress, 37U)) + 6691720614265406851U;
            aOrbiterF = (aWandererD + RotL64(aPrevious, 19U)) + 7063906424700911378U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 17328616394166672263U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 1542940602574207068U) ^ RotL64(aNonceWordA, 47U);
            aOrbiterK = RotL64((aOrbiterK * 8981679306319627975U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 7203866278803132454U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 993485696233139264U;
            aOrbiterA = RotL64((aOrbiterA * 11609009908810366447U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 15659679028507488331U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 18321361454094675842U;
            aOrbiterH = RotL64((aOrbiterH * 3966860765622641843U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 9633319822696783352U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 3496559332232402963U) ^ RotL64(aNonceWordB, 7U);
            aOrbiterF = RotL64((aOrbiterF * 7772060229838162977U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 1918349708324205526U) + aOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 7701088402761359134U;
            aOrbiterE = RotL64((aOrbiterE * 9649485438465644795U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 6006824348814439686U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 18088375375347012557U;
            aOrbiterG = RotL64((aOrbiterG * 12801082943086128385U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 12816533373478543584U) + aOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 17951880253818836433U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8935839101517220201U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 11311632024372748238U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 9891349164779752351U;
            aOrbiterD = RotL64((aOrbiterD * 11405973752233193209U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 711130292000437038U) + aOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 17818800917771709681U;
            aOrbiterI = RotL64((aOrbiterI * 10567029732245868263U), 5U);
            //
            aIngress = RotL64(aOrbiterA, 47U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterK, 51U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 39U));
            aIngress = aIngress + (RotL64(aOrbiterI, 43U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterG, 18U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 27U) + aOrbiterD) + RotL64(aOrbiterJ, 39U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterI, 24U)) + aOrbiterK) + aWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterE, 47U)) + aOrbiterA) + aWandererUpdateSaltD[((aIndex + 28U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 56U) + aOrbiterG) + RotL64(aOrbiterA, 5U)) + RotL64(aCarry, 43U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 35U) + aOrbiterG) + RotL64(aOrbiterJ, 35U));
            aWandererD = aWandererD + ((RotL64(aCross, 39U) + RotL64(aOrbiterE, 54U)) + aOrbiterK);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 23U) + aOrbiterH) + RotL64(aOrbiterD, 19U));
            aWandererH = aWandererH + ((((RotL64(aScatter, 52U) + aOrbiterK) + RotL64(aOrbiterA, 43U)) + RotL64(aCarry, 53U)) + RotL64(aNonceWordG, 46U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterI, 11U)) + aOrbiterF) + RotL64(aNonceWordF, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererA);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 10U));
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererE, 3U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 4U) ^ RotL64(aNonceWordA, 37U)) ^ RotL64(aNonceWordB, 27U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8271U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneD[((aIndex + 6592U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 35U) ^ RotL64(aNonceWordE, 13U)) ^ RotL64(aNonceWordH, 5U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 7401U)) & S_BLOCK1], 46U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 10850U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCross, 27U)) ^ (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 40U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (aWandererD + RotL64(aCross, 13U)) + 7893287783892523139U;
            aOrbiterB = ((aWandererJ + RotL64(aIngress, 4U)) + 10257331997383491153U) + aOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = ((aWandererG + RotL64(aScatter, 43U)) + RotL64(aCarry, 35U)) + 14562226733652231753U;
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 53U)) + 14320342577110737851U) + RotL64(aNonceWordB, 57U);
            aOrbiterF = (aWandererH + RotL64(aScatter, 21U)) + 9816717579822880756U;
            aOrbiterI = (aWandererF + RotL64(aCross, 47U)) + 9558926960095881953U;
            aOrbiterK = (((aWandererA + RotL64(aPrevious, 28U)) + RotL64(aCarry, 11U)) + 9230371862654338324U) + aOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 37U)) + RotL64(aCarry, 51U)) + 6414274291252913420U;
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 57U)) + 13868546184398350849U) + RotL64(aNonceWordG, 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 16940736952569949038U) + aOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 2866957764814864371U;
            aOrbiterD = RotL64((aOrbiterD * 3554702178644797003U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 7916721976073979724U) + RotL64(aNonceWordA, 37U);
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 1602444214978842275U;
            aOrbiterF = RotL64((aOrbiterF * 11072503711308122385U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 9529061385251008037U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 8402775110887376588U;
            aOrbiterK = RotL64((aOrbiterK * 13980225144628227381U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 15003592180290390713U) + RotL64(aNonceWordH, 15U);
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 14195681406520825751U) ^ aOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11455000833788877217U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 3263577002367714202U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 12019422062655581928U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5002313835338447799U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 8508638054582582917U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 6536618106353552880U;
            aOrbiterH = RotL64((aOrbiterH * 6233964121117511885U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 9654542989321430868U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 7019594782797863244U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1234877854354279981U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 8256061220727519919U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 9232754129467036130U;
            aOrbiterI = RotL64((aOrbiterI * 17556001874302369781U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 5608829951337740378U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 12632120498473345701U;
            aOrbiterB = RotL64((aOrbiterB * 6994794653605831925U), 37U);
            //
            aIngress = RotL64(aOrbiterF, 3U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 51U));
            aIngress = aIngress + (RotL64(aOrbiterE, 58U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterI, 39U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterJ, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aIngress, 28U) + RotL64(aOrbiterE, 47U)) + aOrbiterK);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 43U) + aOrbiterB) + RotL64(aOrbiterG, 28U));
            aWandererA = aWandererA + (((RotL64(aScatter, 11U) + RotL64(aOrbiterJ, 53U)) + aOrbiterB) + RotL64(aNonceWordD, 9U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 51U) + aOrbiterD) + RotL64(aOrbiterK, 23U));
            aWandererB = aWandererB + ((((RotL64(aScatter, 47U) + RotL64(aOrbiterH, 19U)) + aOrbiterD) + RotL64(aCarry, 23U)) + aWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 5U) + aOrbiterJ) + RotL64(aOrbiterH, 58U)) + aWandererUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 58U) + RotL64(aOrbiterE, 41U)) + aOrbiterG) + RotL64(aCarry, 39U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 19U) + aOrbiterI) + RotL64(aOrbiterK, 37U));
            aWandererH = aWandererH + (((RotL64(aIngress, 35U) + aOrbiterF) + RotL64(aOrbiterG, 5U)) + RotL64(aNonceWordF, 12U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 10U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererF, 41U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererG, 53U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererJ, 35U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 11U) ^ RotL64(aNonceWordH, 50U)) ^ RotL64(aNonceWordC, 37U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 11988U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((aIndex + 15515U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 57U) ^ RotL64(aNonceWordD, 47U)) ^ RotL64(aNonceWordG, 27U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 13061U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneC[((aIndex + 14951U)) & S_BLOCK1], 36U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 11U) + RotL64(aIngress, 57U)) ^ (RotL64(aCross, 40U) ^ RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererE + RotL64(aScatter, 3U)) + 15316464782468770057U) + aOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = (aWandererG + RotL64(aIngress, 12U)) + 6642872057476351588U;
            aOrbiterG = (aWandererA + RotL64(aPrevious, 39U)) + 660732654689529192U;
            aOrbiterE = (((aWandererJ + RotL64(aCross, 21U)) + RotL64(aCarry, 39U)) + 7235418086884000655U) + RotL64(aNonceWordH, 41U);
            aOrbiterB = ((aWandererD + RotL64(aScatter, 29U)) + 14784518476694580493U) + RotL64(aNonceWordG, 9U);
            aOrbiterD = ((aWandererF + RotL64(aIngress, 43U)) + RotL64(aCarry, 51U)) + 12222433977933449375U;
            aOrbiterK = (((aWandererC + RotL64(aPrevious, 58U)) + RotL64(aCarry, 27U)) + 8573001207708329927U) + aOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = (aWandererH + RotL64(aCross, 35U)) + 16035256260815013172U;
            aOrbiterA = (aWandererK + RotL64(aIngress, 53U)) + 15767726974121910203U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 17712217935322939971U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 13488963456923357159U;
            aOrbiterG = RotL64((aOrbiterG * 16785285630840310405U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 10222949131965611079U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 1495561412321657209U;
            aOrbiterI = RotL64((aOrbiterI * 9706305581868526265U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 16156530750584361434U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 7773792489045606309U;
            aOrbiterE = RotL64((aOrbiterE * 10730624207715601393U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 11544578291333360613U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 3665587867634242865U;
            aOrbiterJ = RotL64((aOrbiterJ * 4840528190844842595U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 15248434984650998090U) + aOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 15487979645426567581U) ^ aOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10868107809356766183U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 6972347795052712690U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 16074994810010431338U;
            aOrbiterD = RotL64((aOrbiterD * 1262655238856775853U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 16851139687900415292U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterC) ^ 14630026837021552812U) ^ aOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1]) ^ RotL64(aNonceWordA, 17U);
            aOrbiterK = RotL64((aOrbiterK * 9577900853521254603U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 14236330619137368169U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 17778707026111136216U) ^ RotL64(aNonceWordF, 25U);
            aOrbiterC = RotL64((aOrbiterC * 16239561893843454747U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 9390961969105999083U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 1174881758316573228U;
            aOrbiterA = RotL64((aOrbiterA * 6602061268277529311U), 57U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterE, 20U);
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 53U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + RotL64(aOrbiterG, 40U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aScatter, 4U) + aOrbiterJ) + RotL64(aOrbiterK, 43U)) + aWandererUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 57U) + aOrbiterE) + RotL64(aOrbiterC, 5U)) + RotL64(aNonceWordD, 36U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterA, 51U)) + aOrbiterI) + RotL64(aNonceWordB, 49U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 47U) + aOrbiterE) + RotL64(aOrbiterB, 58U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 12U) + RotL64(aOrbiterA, 13U)) + aOrbiterE);
            aWandererG = aWandererG + (((RotL64(aScatter, 27U) + RotL64(aOrbiterG, 47U)) + aOrbiterE) + RotL64(aCarry, 21U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 43U) + aOrbiterI) + RotL64(aOrbiterG, 19U));
            aWandererE = aWandererE + ((((RotL64(aPrevious, 37U) + aOrbiterK) + RotL64(aOrbiterB, 34U)) + RotL64(aCarry, 35U)) + aWandererUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterA, 39U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 20U));
            aCarry = aCarry + (RotL64(aWandererF, 53U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererD, 41U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererJ, 27U);
            aCarry = aCarry + RotL64(aIngress, 12U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 30U) ^ RotL64(aNonceWordE, 51U)) ^ RotL64(aNonceWordD, 39U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 17528U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21694U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 37U) ^ RotL64(aNonceWordA, 27U)) ^ RotL64(aNonceWordF, 19U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21403U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneD[((aIndex + 17103U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 51U) ^ RotL64(aPrevious, 19U)) ^ (RotL64(aCross, 5U) + RotL64(aIngress, 34U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererC + RotL64(aScatter, 58U)) + 13687218104610230596U;
            aOrbiterG = ((aWandererK + RotL64(aIngress, 41U)) + RotL64(aCarry, 39U)) + 6841550124960692709U;
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 5U)) + 17418968668458764131U) + aOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = ((aWandererE + RotL64(aCross, 19U)) + 8303537912696948204U) + aOrbiterAssignSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterF = (((aWandererD + RotL64(aScatter, 53U)) + RotL64(aCarry, 29U)) + 12376614417285936537U) + RotL64(aNonceWordB, 47U);
            aOrbiterJ = (aWandererA + RotL64(aIngress, 35U)) + 14215749063579232654U;
            aOrbiterA = ((aWandererF + RotL64(aCross, 23U)) + RotL64(aCarry, 13U)) + 4111736931433665347U;
            aOrbiterC = (aWandererJ + RotL64(aPrevious, 13U)) + 11250375934571631522U;
            aOrbiterI = ((aWandererG + RotL64(aIngress, 46U)) + 5367367837773331275U) + RotL64(aNonceWordG, 31U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 15514089192382674434U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 1475991716685034960U) ^ RotL64(aNonceWordA, 25U);
            aOrbiterD = RotL64((aOrbiterD * 17720681295551650891U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 5531622777788629748U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 8363822215908303335U;
            aOrbiterF = RotL64((aOrbiterF * 17850203366840994883U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 3741256932685720414U) + aOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 11634667238062155772U;
            aOrbiterA = RotL64((aOrbiterA * 15925089729784547403U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 18180546911210417155U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 5123234656838556335U;
            aOrbiterE = RotL64((aOrbiterE * 15362857462853398025U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 11215734271189250284U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 16863747802158398092U) ^ RotL64(aNonceWordF, 45U);
            aOrbiterH = RotL64((aOrbiterH * 1828035970246160023U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 9859050606636646323U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 9331300036643654675U;
            aOrbiterJ = RotL64((aOrbiterJ * 2502263410556166281U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 15028845665427209759U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 8916444839488901676U;
            aOrbiterC = RotL64((aOrbiterC * 6646561894156038791U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 8024631140949068570U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 1116378858490660031U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4247798531910227367U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 5066486214537899212U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 9346312092322423057U;
            aOrbiterG = RotL64((aOrbiterG * 13443190089768875191U), 53U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterC, 23U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 48U));
            aIngress = aIngress + (RotL64(aOrbiterI, 3U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterG, 51U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterJ, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 41U) + aOrbiterH) + RotL64(aOrbiterD, 51U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 24U) + RotL64(aOrbiterF, 47U)) + aOrbiterC) + RotL64(aCarry, 37U)) + aWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 29U) + aOrbiterE) + RotL64(aOrbiterG, 5U)) + RotL64(aNonceWordC, 21U));
            aWandererB = aWandererB + (((RotL64(aCross, 35U) + RotL64(aOrbiterC, 20U)) + aOrbiterJ) + RotL64(aCarry, 47U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterI, 57U)) + aOrbiterG);
            aWandererC = aWandererC + ((RotL64(aIngress, 11U) + aOrbiterJ) + RotL64(aOrbiterH, 41U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 51U) + aOrbiterJ) + RotL64(aOrbiterD, 11U));
            aWandererE = aWandererE + (((RotL64(aCross, 47U) + RotL64(aOrbiterE, 34U)) + aOrbiterI) + RotL64(aNonceWordH, 16U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 58U) + RotL64(aOrbiterA, 27U)) + aOrbiterE) + aWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 24U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 41U));
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererB, 53U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 5U) ^ RotL64(aNonceWordE, 26U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 24500U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneA[((aIndex + 24757U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 37U) ^ RotL64(aNonceWordA, 6U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 22524U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23323U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCross, 29U)) + (RotL64(aCarry, 57U) + RotL64(aPrevious, 42U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererJ + RotL64(aScatter, 47U)) + 9080426856729228705U;
            aOrbiterA = (((aWandererH + RotL64(aIngress, 43U)) + RotL64(aCarry, 11U)) + 7851218321653539276U) + RotL64(aNonceWordG, 11U);
            aOrbiterE = (aWandererA + RotL64(aCross, 60U)) + 7023344692919298036U;
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 29U)) + RotL64(aCarry, 27U)) + 9772846154227440734U;
            aOrbiterG = (aWandererG + RotL64(aIngress, 53U)) + 12008298632429608431U;
            aOrbiterJ = ((aWandererB + RotL64(aCross, 39U)) + 12201090455849562875U) + aOrbiterAssignSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterK = (((aWandererI + RotL64(aScatter, 34U)) + RotL64(aCarry, 53U)) + 9498721803411445471U) + RotL64(aNonceWordB, 55U);
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 23U)) + 351203764023093632U) + aOrbiterAssignSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = (aWandererK + RotL64(aScatter, 3U)) + 4966360430644539250U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 9194167899071345693U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 4922477697284269116U;
            aOrbiterE = RotL64((aOrbiterE * 8444814161720407881U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 15742625291642356429U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 7528703106518431730U) ^ RotL64(aNonceWordD, 23U);
            aOrbiterJ = RotL64((aOrbiterJ * 11530049278751507567U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 15279053574704935317U) + aOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 2425839793660355555U;
            aOrbiterD = RotL64((aOrbiterD * 11486964816849830667U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 13209849392400008898U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 9041500097716231309U;
            aOrbiterF = RotL64((aOrbiterF * 340661035700748739U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 7885423750878814599U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 1992993999902904603U;
            aOrbiterI = RotL64((aOrbiterI * 1478629826632201617U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 6120758615019314102U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 8529621625846992066U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8485991471612862467U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 9125182130757385320U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 15691232622970220043U;
            aOrbiterK = RotL64((aOrbiterK * 16517916951054758147U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 11413090085435424697U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 11563151001080914939U) ^ aOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16828196274450408201U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 1778975369262558069U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 3232132443557192010U) ^ RotL64(aNonceWordC, 25U);
            aOrbiterG = RotL64((aOrbiterG * 17132823737792200981U), 37U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterI, 41U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 30U));
            aIngress = aIngress + (RotL64(aOrbiterE, 51U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterK, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterB, 5U)) + aOrbiterG);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 30U) + RotL64(aOrbiterA, 41U)) + aOrbiterG) + RotL64(aCarry, 53U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterD, 10U)) + aOrbiterF) + RotL64(aNonceWordH, 20U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterD, 37U)) + RotL64(aCarry, 43U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterA, 29U)) + aOrbiterJ);
            aWandererA = aWandererA + (((RotL64(aCross, 35U) + aOrbiterI) + RotL64(aOrbiterG, 19U)) + aWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 57U) + aOrbiterJ) + RotL64(aOrbiterK, 51U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterJ, 23U)) + aOrbiterB);
            aWandererE = aWandererE ^ ((((RotL64(aScatter, 50U) + aOrbiterJ) + RotL64(aOrbiterE, 14U)) + RotL64(aNonceWordF, 15U)) + aWandererUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 19U));
            aCarry = aCarry + (RotL64(aWandererI, 14U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererH, 51U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 3U) ^ RotL64(aNonceWordA, 57U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 32186U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32079U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 47U) ^ RotL64(aNonceWordF, 57U)) ^ RotL64(aNonceWordE, 14U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32439U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneB[((aIndex + 30638U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 47U) ^ RotL64(aCross, 3U)) + (RotL64(aCarry, 34U) + RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((aWandererK + RotL64(aIngress, 43U)) + 16124889768301047791U) + aOrbiterAssignSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterG = ((aWandererB + RotL64(aScatter, 39U)) + 11912338587186717280U) + RotL64(aNonceWordA, 31U);
            aOrbiterE = ((aWandererC + RotL64(aCross, 13U)) + RotL64(aCarry, 29U)) + 8594012868813114354U;
            aOrbiterC = (aWandererD + RotL64(aPrevious, 27U)) + 18281043566156682815U;
            aOrbiterI = (aWandererI + RotL64(aIngress, 4U)) + 16853106130200942302U;
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 19U)) + RotL64(aCarry, 43U)) + 2611212958619673086U;
            aOrbiterH = (((aWandererA + RotL64(aScatter, 23U)) + RotL64(aCarry, 19U)) + 18039472325066855180U) + RotL64(aNonceWordC, 3U);
            aOrbiterA = ((aWandererJ + RotL64(aCross, 51U)) + 14495785571345122046U) + aOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 56U)) + 4556063793412832418U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 14896419970271244358U) + aOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 880028529183500036U) ^ RotL64(aNonceWordG, 49U);
            aOrbiterE = RotL64((aOrbiterE * 14228281807461251361U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 2379557167489415783U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 11854373946064529806U;
            aOrbiterI = RotL64((aOrbiterI * 150755294320438887U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 1487252775956449964U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 12777924204511625545U;
            aOrbiterH = RotL64((aOrbiterH * 1366019527386994789U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 15998631485222477969U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 8864212892296191613U) ^ RotL64(aNonceWordB, 12U);
            aOrbiterA = RotL64((aOrbiterA * 579242788050369815U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 17069347835763226743U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 7443008171694679791U;
            aOrbiterJ = RotL64((aOrbiterJ * 748894368884566607U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 17334256152350782002U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 8986626119086556393U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2258172145924120235U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 8528180968228358674U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 12702290928064582589U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15673603224146737631U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 7742438100860023610U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 3729687240959702198U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3756794766163746783U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 426129097367382096U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 16782175452274911213U;
            aOrbiterG = RotL64((aOrbiterG * 1041477289638333659U), 5U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterC, 51U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 30U));
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + RotL64(aOrbiterF, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 43U) + aOrbiterG) + RotL64(aOrbiterA, 4U)) + RotL64(aNonceWordE, 47U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 34U) + RotL64(aOrbiterC, 39U)) + aOrbiterJ);
            aWandererD = aWandererD ^ ((((RotL64(aScatter, 57U) + RotL64(aOrbiterF, 35U)) + aOrbiterE) + RotL64(aNonceWordH, 27U)) + aWandererUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 3U) + aOrbiterA) + RotL64(aOrbiterH, 57U)) + RotL64(aCarry, 27U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterA, 14U)) + aOrbiterB) + aWandererUpdateSaltF[((aIndex + 18U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterF, 51U)) + aOrbiterG) + RotL64(aCarry, 53U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 51U) + aOrbiterI) + RotL64(aOrbiterE, 23U));
            aWandererI = aWandererI + ((RotL64(aScatter, 23U) + RotL64(aOrbiterF, 19U)) + aOrbiterJ);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 14U) + RotL64(aOrbiterE, 27U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 6U));
            aCarry = aCarry + (RotL64(aWandererI, 11U) ^ aWandererC);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + RotL64(aWandererF, 47U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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

void TwistExpander_Boxing_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xF5A87C2DAD11020FULL + 0xF25878F635490479ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x9704D52D69B56E73ULL + 0xAE943D6932127728ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xBCB25AA081D6B83DULL + 0xB078F9AB773EC547ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xA276DC28ED4C27C5ULL + 0xACFD7B82B42B9C08ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xD991FA216AEE5C45ULL + 0x95E20BF0223AE24BULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x913D28D3CF855405ULL + 0x91A66B391B6CADD9ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xCE212260BE8F2E7BULL + 0xB56CC236FB14E25AULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xF2EE01C5E387013DULL + 0xF300C952D37E9979ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 53U) ^ RotL64(aNonceWordH, 29U)) ^ RotL64(aNonceWordF, 14U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 4627U)) & S_BLOCK1], 41U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 2786U)) & W_KEY1], 5U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 39U) ^ RotL64(aNonceWordD, 57U));
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 1390U)) & W_KEY1], 5U) ^ RotL64(mSource[((aIndex + 1877U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 40U) ^ RotL64(aCross, 3U)) ^ (RotL64(aPrevious, 21U) + RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterF = (((aWandererG + RotL64(aCross, 21U)) + RotL64(aCarry, 27U)) + 8767379393098711499U) + RotL64(aNonceWordA, 9U);
            aOrbiterH = (aWandererD + RotL64(aScatter, 43U)) + 7168159491580816433U;
            aOrbiterB = (((aWandererF + RotL64(aIngress, 5U)) + RotL64(aCarry, 47U)) + 9879279829061883406U) + aPhaseAOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 52U)) + RotL64(aCarry, 11U)) + 10537167136053399303U;
            aOrbiterG = (aWandererE + RotL64(aCross, 37U)) + 2839070018069188936U;
            aOrbiterI = (aWandererJ + RotL64(aScatter, 27U)) + 13844278063968429732U;
            aOrbiterE = (((aWandererK + RotL64(aIngress, 13U)) + 11278946626186474646U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1]) + RotL64(aNonceWordH, 40U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 11798425216660557799U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 7618446090703335192U;
            aOrbiterB = RotL64((aOrbiterB * 7168757300685156779U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 695423597006983660U) + RotL64(aNonceWordC, 57U);
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 14344728202803488813U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5168825904902285909U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 11656100506575697086U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 10384358779985773937U;
            aOrbiterI = RotL64((aOrbiterI * 247494692039140973U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 17585001605131977341U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 9964478171465522911U;
            aOrbiterE = RotL64((aOrbiterE * 13484044854790175315U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 2710943171829692624U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 17809072853457153057U) ^ RotL64(aNonceWordF, 19U);
            aOrbiterF = RotL64((aOrbiterF * 16341884203303271365U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 12814092033910687774U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 1743186323268668740U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11150822630624332557U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 10750472346626754704U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 15925901217078035356U;
            aOrbiterH = RotL64((aOrbiterH * 9276504171291801637U), 57U);
            //
            aIngress = RotL64(aOrbiterH, 29U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 3U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aIngress, 3U) + aOrbiterI) + RotL64(aOrbiterF, 51U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 53U) + aOrbiterD) + RotL64(aOrbiterE, 57U));
            aWandererD = aWandererD + ((RotL64(aScatter, 10U) + aOrbiterE) + RotL64(aOrbiterG, 3U));
            aWandererB = aWandererB ^ ((((RotL64(aCross, 27U) + RotL64(aOrbiterF, 39U)) + aOrbiterE) + RotL64(aNonceWordB, 53U)) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 39U) + RotL64(aOrbiterH, 29U)) + aOrbiterI) + RotL64(aCarry, 47U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterB, 12U)) + aOrbiterI);
            aWandererG = aWandererG + (((((RotL64(aPrevious, 47U) + RotL64(aOrbiterB, 23U)) + aOrbiterF) + RotL64(aCarry, 35U)) + RotL64(aNonceWordD, 45U)) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 37U));
            aCarry = aCarry + (RotL64(aWandererF, 6U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererG, 57U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 47U) ^ RotL64(aNonceWordA, 20U)) ^ RotL64(aNonceWordC, 39U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10102U)) & S_BLOCK1], 3U) ^ RotL64(mSource[((aIndex + 8367U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 13U) ^ RotL64(aNonceWordF, 58U));
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 9866U)) & W_KEY1], 29U) ^ RotL64(aKeyRowReadB[((aIndex + 7591U)) & W_KEY1], 41U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 26U) ^ RotL64(aPrevious, 39U)) ^ (RotL64(aCarry, 51U) + RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterB = ((aWandererA + RotL64(aScatter, 57U)) + 18144572925667544139U) + aPhaseAOrbiterAssignSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterD = ((aWandererJ + RotL64(aCross, 30U)) + RotL64(aCarry, 29U)) + 5659758077574059728U;
            aOrbiterK = ((aWandererG + RotL64(aIngress, 5U)) + RotL64(aCarry, 13U)) + 6343330616999166392U;
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 21U)) + 17754639838410839447U) + RotL64(aNonceWordE, 29U);
            aOrbiterF = (aWandererH + RotL64(aCross, 51U)) + 9451843819849581729U;
            aOrbiterE = (((aWandererI + RotL64(aScatter, 11U)) + RotL64(aCarry, 47U)) + 7957854457197462212U) + RotL64(aNonceWordF, 27U);
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 41U)) + 1461994799722205010U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 18002214276252170177U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 14689869073147027164U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12242482963989582191U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 3978104368003440293U) + RotL64(aNonceWordG, 15U);
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 8512135845221335386U) ^ RotL64(aNonceWordH, 5U);
            aOrbiterB = RotL64((aOrbiterB * 10506667163729414667U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 1477533446382953439U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 2166717790929947990U;
            aOrbiterA = RotL64((aOrbiterA * 6538884492418324461U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 8082437060686606995U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 4363687722464700362U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7199165810993478887U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 15782763348014924206U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 8572509150015960728U;
            aOrbiterF = RotL64((aOrbiterF * 3340528604891897779U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 12248271773316742521U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 9602078627638561949U;
            aOrbiterE = RotL64((aOrbiterE * 1860631869877427405U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 17244849374768558859U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 1030743048280579012U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10858949914285817051U), 13U);
            //
            aIngress = RotL64(aOrbiterE, 50U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 13U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 27U));
            aIngress = aIngress + RotL64(aOrbiterB, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aIngress, 12U) + aOrbiterK) + RotL64(aOrbiterA, 19U)) + RotL64(aCarry, 41U)) + RotL64(aNonceWordC, 56U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterD, 5U)) + aOrbiterE);
            aWandererH = aWandererH + ((RotL64(aPrevious, 29U) + aOrbiterB) + RotL64(aOrbiterA, 41U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterD, 27U)) + aOrbiterA);
            aWandererC = aWandererC + ((((RotL64(aCross, 41U) + aOrbiterG) + RotL64(aOrbiterK, 53U)) + RotL64(aNonceWordB, 3U)) + aPhaseAWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterB, 12U)) + aOrbiterD) + aPhaseAWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 5U) + aOrbiterG) + RotL64(aOrbiterF, 35U)) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 22U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 53U));
            aCarry = aCarry + (RotL64(aWandererA, 41U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererG, 35U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 34U) ^ RotL64(aNonceWordE, 23U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 13934U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((aIndex + 11526U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 57U) ^ RotL64(aNonceWordA, 3U));
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 16351U)) & W_KEY1], 19U) ^ RotL64(aKeyRowReadB[((aIndex + 12966U)) & W_KEY1], 36U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aIngress, 41U)) + (RotL64(aPrevious, 26U) ^ RotL64(aCross, 13U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 57U)) + RotL64(aCarry, 13U)) + 1364174714924216027U;
            aOrbiterB = ((aWandererC + RotL64(aScatter, 29U)) + 13561796874229506613U) + aPhaseAOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = (aWandererB + RotL64(aIngress, 47U)) + 11845572344206238305U;
            aOrbiterH = ((((aWandererF + RotL64(aCross, 21U)) + RotL64(aCarry, 29U)) + 15762708240326773763U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 20U)) & S_SALT1]) + RotL64(aNonceWordF, 61U);
            aOrbiterG = ((aWandererI + RotL64(aScatter, 12U)) + RotL64(aCarry, 51U)) + 1157119665207900473U;
            aOrbiterI = (aWandererK + RotL64(aCross, 41U)) + 6823546624372055260U;
            aOrbiterC = ((aWandererE + RotL64(aIngress, 3U)) + 14465564210523945121U) + RotL64(aNonceWordC, 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 10667464548080807531U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 13445737493224316575U) ^ RotL64(aNonceWordH, 21U);
            aOrbiterJ = RotL64((aOrbiterJ * 12137295000900795711U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 3009837893785957665U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 2886920524111083752U) ^ RotL64(aNonceWordB, 57U);
            aOrbiterB = RotL64((aOrbiterB * 15308180928967762543U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 10886177449328249656U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 15067759884678100433U;
            aOrbiterA = RotL64((aOrbiterA * 5724566815989860041U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 18307930462682331536U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 8791864377579255801U;
            aOrbiterH = RotL64((aOrbiterH * 9265158882471421767U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 805797468642992351U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 5743305867058244964U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16263000753351131717U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 17102025528234481273U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 1841579177327486899U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3841603385577825265U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 2189493507896508972U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 18209567010094914374U;
            aOrbiterC = RotL64((aOrbiterC * 3737080408976852351U), 39U);
            //
            aIngress = RotL64(aOrbiterB, 57U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 51U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterG, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aCross, 35U) + aOrbiterI) + RotL64(aOrbiterJ, 3U)) + RotL64(aCarry, 21U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 47U) + aOrbiterC) + RotL64(aOrbiterB, 35U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterI, 29U)) + aOrbiterC);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 27U) + aOrbiterA) + RotL64(aOrbiterJ, 19U)) + RotL64(aNonceWordG, 14U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 41U)) + aOrbiterG);
            aWandererK = aWandererK ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterG, 47U)) + aOrbiterH) + aPhaseAWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            aWandererE = aWandererE + (((((RotL64(aIngress, 14U) + RotL64(aOrbiterG, 10U)) + aOrbiterA) + RotL64(aCarry, 35U)) + RotL64(aNonceWordD, 7U)) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 4U) ^ aWandererC);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + RotL64(aWandererI, 19U);
            aCarry = aCarry + RotL64(aIngress, 34U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 43U) ^ RotL64(aNonceWordC, 4U)) ^ RotL64(aNonceWordG, 53U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 20017U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneB[((aIndex + 18522U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 3U) ^ RotL64(aNonceWordF, 57U)) ^ RotL64(aNonceWordA, 29U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20994U)) & S_BLOCK1], 11U) ^ RotL64(mSource[((aIndex + 19430U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aPrevious, 37U)) + (RotL64(aIngress, 18U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterG = (aWandererE + RotL64(aCross, 27U)) + 1866656689936219099U;
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 35U)) + 2312314528139448289U) + aPhaseAOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = (((aWandererB + RotL64(aScatter, 51U)) + RotL64(aCarry, 57U)) + 3554037526469185237U) + RotL64(aNonceWordG, 55U);
            aOrbiterE = (aWandererJ + RotL64(aIngress, 11U)) + 405707755060974111U;
            aOrbiterF = ((((aWandererK + RotL64(aCross, 41U)) + RotL64(aCarry, 21U)) + 1862976326004007697U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1]) + RotL64(aNonceWordF, 35U);
            aOrbiterK = (aWandererI + RotL64(aPrevious, 60U)) + 12992483065443288263U;
            aOrbiterC = ((aWandererD + RotL64(aIngress, 19U)) + RotL64(aCarry, 43U)) + 3793854946371595197U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 4244007978867369382U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 10280867500312580308U;
            aOrbiterI = RotL64((aOrbiterI * 13729899124177931289U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 472563452959164242U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 12041770406895816553U;
            aOrbiterK = RotL64((aOrbiterK * 17811798500132002631U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 6118634015704900486U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 13637107920449233307U;
            aOrbiterD = RotL64((aOrbiterD * 17712028184714868053U), 41U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterE) + 16673735670669318830U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1]) + RotL64(aNonceWordE, 17U);
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 8602681273646630496U;
            aOrbiterF = RotL64((aOrbiterF * 6995213887710749241U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 7683264695930369476U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 9146674871199188218U;
            aOrbiterG = RotL64((aOrbiterG * 7403427067419261981U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 3012935612827493084U) + RotL64(aNonceWordC, 49U);
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 1259789268731661945U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2372843620327050137U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 5623690455471160780U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 18355567776031865462U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9553862670107886679U), 35U);
            //
            aIngress = RotL64(aOrbiterE, 35U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterC, 13U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterG, 53U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterK, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aCross, 35U) + aOrbiterK) + RotL64(aOrbiterF, 29U)) + RotL64(aCarry, 21U)) + RotL64(aNonceWordD, 3U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 41U) + aOrbiterI) + RotL64(aOrbiterF, 13U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterC, 48U)) + aOrbiterG);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 13U) + aOrbiterK) + RotL64(aOrbiterC, 3U));
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterC, 23U)) + aOrbiterD) + RotL64(aCarry, 35U)) + RotL64(aNonceWordA, 8U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 6U) + RotL64(aOrbiterF, 35U)) + aOrbiterE) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 23U) + aOrbiterK) + RotL64(aOrbiterE, 41U)) + aPhaseAWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 4U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + RotL64(aWandererD, 23U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 23U) ^ RotL64(aNonceWordE, 13U)) ^ RotL64(aNonceWordA, 54U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 24289U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25186U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 3U) ^ RotL64(aNonceWordD, 57U)) ^ RotL64(aNonceWordF, 19U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 22230U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneA[((aIndex + 26764U)) & S_BLOCK1], 28U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aIngress, 12U)) + (RotL64(aCross, 57U) ^ RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 37U)) + 3973833383430652211U) + RotL64(aNonceWordH, 7U);
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 29U)) + 5760227042747169187U) + aPhaseAOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = (aWandererG + RotL64(aCross, 43U)) + 4923009065139227286U;
            aOrbiterC = ((((aWandererJ + RotL64(aIngress, 3U)) + RotL64(aCarry, 57U)) + 1477807307009107590U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1]) + RotL64(aNonceWordG, 15U);
            aOrbiterG = (aWandererD + RotL64(aScatter, 57U)) + 5707194514329007301U;
            aOrbiterA = ((aWandererB + RotL64(aCross, 12U)) + RotL64(aCarry, 35U)) + 5340439728375269724U;
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 51U)) + RotL64(aCarry, 5U)) + 17080457898946572387U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 281559150259472813U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 16160633048230910560U;
            aOrbiterD = RotL64((aOrbiterD * 16883442583309073785U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 9003989610509592121U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 10579322462808454333U;
            aOrbiterJ = RotL64((aOrbiterJ * 100832431598087235U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 15059383289528723069U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 10417647757852880956U;
            aOrbiterC = RotL64((aOrbiterC * 1457919230286043137U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 14484665027393813330U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 12344463053485837974U) ^ RotL64(aNonceWordC, 35U);
            aOrbiterE = RotL64((aOrbiterE * 5762654194001525041U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 5826453246659297805U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 12547902286376986223U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2982850000322672789U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 9637855144278126174U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 2132744427444501938U) ^ RotL64(aNonceWordB, 25U);
            aOrbiterA = RotL64((aOrbiterA * 5911587798564836199U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 9248933938130311231U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 13274297928717090383U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2901398809555237563U), 5U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterD, 41U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 47U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 18U));
            aIngress = aIngress + RotL64(aOrbiterC, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((((RotL64(aIngress, 27U) + aOrbiterA) + RotL64(aOrbiterE, 5U)) + RotL64(aNonceWordF, 13U)) + aPhaseAWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterD, 57U)) + aOrbiterF) + RotL64(aCarry, 21U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterA, 39U)) + aOrbiterF);
            aWandererA = aWandererA + ((((RotL64(aScatter, 51U) + RotL64(aOrbiterJ, 11U)) + aOrbiterD) + RotL64(aNonceWordA, 24U)) + aPhaseAWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterF, 29U)) + aOrbiterJ);
            aWandererD = aWandererD + (((RotL64(aScatter, 11U) + aOrbiterE) + RotL64(aOrbiterC, 50U)) + RotL64(aCarry, 51U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 60U) + RotL64(aOrbiterG, 19U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 51U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 18U));
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererG, 43U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordA, 21U) ^ RotL64(aNonceWordF, 43U)) ^ RotL64(aNonceWordB, 4U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 27961U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((aIndex + 27373U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 58U) ^ RotL64(aNonceWordD, 5U)) ^ RotL64(aNonceWordH, 21U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30449U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((aIndex + 31685U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 56U) + RotL64(aIngress, 5U)) ^ (RotL64(aCarry, 35U) + RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterJ = ((aWandererB + RotL64(aCross, 27U)) + RotL64(aCarry, 57U)) + 10805654776556844351U;
            aOrbiterB = ((aWandererG + RotL64(aScatter, 41U)) + 582794182442795335U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 47U)) + RotL64(aCarry, 37U)) + 2858343650974681068U;
            aOrbiterD = ((aWandererC + RotL64(aIngress, 60U)) + 8189584049022064284U) + RotL64(aNonceWordF, 25U);
            aOrbiterE = (aWandererF + RotL64(aCross, 53U)) + 1565100751996962893U;
            aOrbiterK = (aWandererI + RotL64(aScatter, 13U)) + 8062028016947611891U;
            aOrbiterG = ((((aWandererD + RotL64(aIngress, 5U)) + RotL64(aCarry, 11U)) + 8280504280578451745U) + aPhaseAOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1]) + RotL64(aNonceWordC, 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 11326869194491655350U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 1671695656567777163U;
            aOrbiterC = RotL64((aOrbiterC * 7511554500524257921U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 2349843105293943452U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 13015545152052004254U;
            aOrbiterE = RotL64((aOrbiterE * 1316662811685429983U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 16703354404749291869U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 8713231044374305801U;
            aOrbiterK = RotL64((aOrbiterK * 9242480982197688625U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 11118401674497783533U) + RotL64(aNonceWordD, 35U);
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 14857556493734710364U;
            aOrbiterG = RotL64((aOrbiterG * 3452566050389715195U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 12953419670951660965U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 12666121730825089017U) ^ RotL64(aNonceWordE, 11U);
            aOrbiterJ = RotL64((aOrbiterJ * 14049925256934142519U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 11075249639473053423U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 9374217688244187867U;
            aOrbiterD = RotL64((aOrbiterD * 5261156325627117877U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 17608340953291367867U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 13159437499327086340U;
            aOrbiterB = RotL64((aOrbiterB * 4882100944453534805U), 11U);
            //
            aIngress = RotL64(aOrbiterB, 3U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 37U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 28U));
            aIngress = aIngress + RotL64(aOrbiterJ, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aCross, 19U) + RotL64(aOrbiterC, 27U)) + aOrbiterK) + RotL64(aCarry, 37U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 50U) + RotL64(aOrbiterE, 35U)) + aOrbiterD);
            aWandererB = aWandererB + ((RotL64(aScatter, 41U) + aOrbiterC) + RotL64(aOrbiterG, 19U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 13U) + aOrbiterK) + RotL64(aOrbiterE, 57U));
            aWandererE = aWandererE + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterB, 51U)) + aOrbiterJ) + RotL64(aNonceWordA, 50U)) + aPhaseAWandererUpdateSaltC[((aIndex + 26U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 27U) + aOrbiterE) + RotL64(aOrbiterG, 5U)) + aPhaseAWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterE, 44U)) + aOrbiterB) + RotL64(aCarry, 5U)) + RotL64(aNonceWordG, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererF);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 18U));
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererI, 29U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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

void TwistExpander_Boxing_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xE48C18318A06646FULL + 0xF88E25730378193CULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xC68BFF8CD0E3D85DULL + 0xA6897799377FBE81ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xFF75226F59420103ULL + 0xC6754369947A2E19ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xFF14A3993ADC95DFULL + 0x993CEF9E6863427BULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x8E20D38688BA1C15ULL + 0x83629D9E3C54A139ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xB69673600BB97869ULL + 0xD5ABF6D8E8506FD5ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xE4D95F87A9CACA2BULL + 0x97A52385206A0171ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xAE83974F51732B23ULL + 0x9F7F2B97829AE913ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 13U) ^ RotL64(aNonceWordD, 36U)) ^ RotL64(aNonceWordB, 51U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 386U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4648U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 47U) ^ RotL64(aNonceWordA, 21U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2570U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 4816U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 60U) + RotL64(aCarry, 35U)) ^ (RotL64(aCross, 19U) ^ RotL64(aPrevious, 47U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterJ = ((aWandererD + RotL64(aCross, 57U)) + RotL64(aCarry, 21U)) + 7075016829833562104U;
            aOrbiterG = (((aWandererJ + RotL64(aPrevious, 29U)) + RotL64(aCarry, 47U)) + 8783765886115517036U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = ((aWandererG + RotL64(aScatter, 5U)) + 2996723892384565829U) + RotL64(aNonceWordB, 6U);
            aOrbiterK = ((aWandererE + RotL64(aIngress, 19U)) + RotL64(aCarry, 5U)) + 9494134707342189476U;
            aOrbiterA = (((aWandererK + RotL64(aScatter, 44U)) + 5052642981395679904U) + aPhaseBOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1]) + RotL64(aNonceWordD, 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 8766787055127962238U) + RotL64(aNonceWordE, 25U);
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 4467211954388738079U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8599295330343804047U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 8030255604633658608U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 16962408063455702251U;
            aOrbiterJ = RotL64((aOrbiterJ * 11171737929747471631U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 3768222186567699076U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 14930990410207899871U;
            aOrbiterK = RotL64((aOrbiterK * 10930005786146268241U), 21U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterJ) + 14179761938395502502U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1]) + RotL64(aNonceWordG, 35U);
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 1879084742719898108U;
            aOrbiterG = RotL64((aOrbiterG * 16783034788172670121U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 5535012408925981515U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 12792553516710295939U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8577530993755159329U), 11U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterA, 6U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + RotL64(aOrbiterD, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((((RotL64(aScatter, 57U) + RotL64(aOrbiterD, 35U)) + aOrbiterA) + RotL64(aNonceWordC, 37U)) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 3U) + aOrbiterA) + RotL64(aOrbiterJ, 51U)) + RotL64(aCarry, 53U)) + RotL64(aNonceWordH, 13U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 12U) + aOrbiterG) + RotL64(aOrbiterK, 60U));
            aWandererG = aWandererG + (((RotL64(aIngress, 43U) + RotL64(aOrbiterJ, 43U)) + aOrbiterD) + RotL64(aCarry, 19U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterJ, 5U)) + aOrbiterK) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererG);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + RotL64(aWandererK, 29U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 21U) ^ RotL64(aNonceWordD, 3U)) ^ RotL64(aNonceWordF, 34U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10750U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 9599U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 4U) ^ RotL64(aNonceWordH, 13U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7970U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneB[((aIndex + 9429U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 35U) + RotL64(aCarry, 47U)) + (RotL64(aPrevious, 60U) ^ RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 13U)) + RotL64(aCarry, 3U)) + 8866844335448071821U;
            aOrbiterC = (((aWandererI + RotL64(aIngress, 44U)) + 15159698739856430085U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 5U)) & S_SALT1]) + RotL64(aNonceWordG, 43U);
            aOrbiterI = ((aWandererE + RotL64(aScatter, 57U)) + RotL64(aCarry, 51U)) + 9582805772989594633U;
            aOrbiterG = (((aWandererB + RotL64(aCross, 21U)) + RotL64(aCarry, 19U)) + 1438538239931588373U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = ((aWandererG + RotL64(aIngress, 29U)) + 10862044156620436139U) + RotL64(aNonceWordC, 25U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 13682173320058164615U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 8351013291045977592U;
            aOrbiterI = RotL64((aOrbiterI * 5722336275651615473U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 15777857431516633916U) + RotL64(aNonceWordA, 55U);
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 16178966745333885377U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7545129923202147703U), 47U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterI) + 9031889187993001617U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]) + RotL64(aNonceWordB, 45U);
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 6308472367425865347U;
            aOrbiterH = RotL64((aOrbiterH * 17118710301967158153U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 642109145903321046U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 9186268569255318035U;
            aOrbiterC = RotL64((aOrbiterC * 10714674348507516749U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 6091345356803675860U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 13218507921880873749U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15415157927185637717U), 35U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterC, 3U);
            aIngress = aIngress + (RotL64(aOrbiterI, 23U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterH, 52U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 29U) + aOrbiterI) + RotL64(aOrbiterG, 3U));
            aWandererG = aWandererG + ((((RotL64(aIngress, 3U) + aOrbiterI) + RotL64(aOrbiterF, 43U)) + RotL64(aCarry, 51U)) + RotL64(aNonceWordD, 38U));
            aWandererI = aWandererI ^ ((((RotL64(aScatter, 13U) + RotL64(aOrbiterC, 13U)) + aOrbiterG) + RotL64(aNonceWordE, 19U)) + aPhaseBWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterC, 54U)) + aOrbiterH) + RotL64(aCarry, 37U)) + aPhaseBWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 38U) + RotL64(aOrbiterH, 21U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererI, 3U);
            aCarry = aCarry + RotL64(aIngress, 14U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 3U) ^ RotL64(aNonceWordE, 12U)) ^ RotL64(aNonceWordA, 57U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 16132U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((aIndex + 13282U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 22U) ^ RotL64(aNonceWordC, 3U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 14732U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneC[((aIndex + 11181U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 6U) + RotL64(aIngress, 41U)) + (RotL64(aCross, 53U) ^ RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterJ = ((((aWandererF + RotL64(aCross, 35U)) + RotL64(aCarry, 53U)) + 17081642665820489793U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1]) + RotL64(aNonceWordB, 9U);
            aOrbiterI = (aWandererD + RotL64(aScatter, 43U)) + 14468854040067229623U;
            aOrbiterF = ((aWandererC + RotL64(aIngress, 3U)) + RotL64(aCarry, 23U)) + 2249450222593057429U;
            aOrbiterK = ((((aWandererH + RotL64(aPrevious, 13U)) + RotL64(aCarry, 37U)) + 14964389079511378664U) + aPhaseBOrbiterAssignSaltC[((aIndex + 12U)) & S_SALT1]) + RotL64(aNonceWordH, 31U);
            aOrbiterH = (aWandererI + RotL64(aScatter, 26U)) + 17003491054252360650U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 12710882240582032588U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 9887078182156755359U;
            aOrbiterF = RotL64((aOrbiterF * 8205865025853482573U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 7665284531810584704U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 7304284015511876717U;
            aOrbiterI = RotL64((aOrbiterI * 6193179739025093929U), 11U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterK) + 5517927023543751734U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1]) + RotL64(aNonceWordD, 20U);
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 17704756310857362759U) ^ RotL64(aNonceWordF, 61U);
            aOrbiterJ = RotL64((aOrbiterJ * 15826832172923213591U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 11347400363019508578U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 11696395232760991243U;
            aOrbiterK = RotL64((aOrbiterK * 9725231749679442003U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 10875780291242873583U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 7808740614343437672U;
            aOrbiterH = RotL64((aOrbiterH * 8889516201913716283U), 57U);
            //
            aIngress = RotL64(aOrbiterI, 47U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterF, 37U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterJ, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aCross, 3U) + aOrbiterJ) + RotL64(aOrbiterK, 42U)) + RotL64(aCarry, 43U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 27U) + aOrbiterH) + RotL64(aOrbiterK, 13U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterF, 21U)) + aOrbiterK) + RotL64(aCarry, 5U));
            aWandererF = aWandererF ^ ((((RotL64(aScatter, 47U) + aOrbiterI) + RotL64(aOrbiterJ, 5U)) + RotL64(aNonceWordC, 41U)) + aPhaseBWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 36U) + RotL64(aOrbiterF, 29U)) + aOrbiterH) + RotL64(aNonceWordG, 3U)) + aPhaseBWandererUpdateSaltB[((aIndex + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 51U) ^ aWandererH);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 13U));
            aCarry = aCarry + RotL64(aWandererI, 5U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 47U) ^ RotL64(aNonceWordB, 11U)) ^ RotL64(aNonceWordH, 56U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 21294U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((aIndex + 17293U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 3U) ^ RotL64(aNonceWordA, 24U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19280U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((aIndex + 21842U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCarry, 29U)) + (RotL64(aIngress, 10U) ^ RotL64(aCross, 43U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterH = (((aWandererJ + RotL64(aPrevious, 29U)) + 9023059520606551446U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1]) + RotL64(aNonceWordF, 20U);
            aOrbiterE = ((aWandererD + RotL64(aIngress, 41U)) + RotL64(aCarry, 23U)) + 662441755115638133U;
            aOrbiterI = ((aWandererF + RotL64(aScatter, 19U)) + RotL64(aCarry, 53U)) + 16957253361196144712U;
            aOrbiterD = ((((aWandererE + RotL64(aCross, 11U)) + RotL64(aCarry, 5U)) + 7840955025765308605U) + aPhaseBOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1]) + RotL64(aNonceWordE, 49U);
            aOrbiterK = (aWandererG + RotL64(aIngress, 56U)) + 346855809270395799U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 16099139781586668343U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterH) ^ 3706457327118322098U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1]) ^ RotL64(aNonceWordC, 41U);
            aOrbiterI = RotL64((aOrbiterI * 7810030620470889591U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 12166825885547622870U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 7792658665720344200U) ^ RotL64(aNonceWordG, 31U);
            aOrbiterH = RotL64((aOrbiterH * 16305542632794270697U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 7128477606152986326U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 11116533962780290084U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11993485572912492297U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 10443889548568288532U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 4402387036946561017U;
            aOrbiterE = RotL64((aOrbiterE * 9032964741841833277U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 13002706161178447654U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 13929727277530310708U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7005639090871200285U), 3U);
            //
            aIngress = RotL64(aOrbiterI, 57U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + RotL64(aOrbiterK, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterE, 4U)) + aOrbiterI) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aIngress, 3U) + aOrbiterE) + RotL64(aOrbiterH, 47U)) + RotL64(aCarry, 5U)) + aPhaseBWandererUpdateSaltC[((aIndex + 16U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterK, 27U)) + aOrbiterD) + RotL64(aNonceWordD, 61U));
            aWandererG = aWandererG + ((((RotL64(aPrevious, 54U) + RotL64(aOrbiterD, 35U)) + aOrbiterE) + RotL64(aCarry, 53U)) + RotL64(aNonceWordB, 59U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterH, 57U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererG, 19U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 39U) ^ RotL64(aNonceWordE, 4U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 24917U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneA[((aIndex + 23963U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 43U) ^ RotL64(aNonceWordF, 51U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 22149U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24987U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCross, 40U)) ^ (RotL64(aCarry, 27U) + RotL64(aIngress, 13U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterE = (aWandererC + RotL64(aCross, 3U)) + 3255291173184001106U;
            aOrbiterD = (((aWandererB + RotL64(aScatter, 26U)) + RotL64(aCarry, 57U)) + 15308468160116255528U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterC = (aWandererA + RotL64(aPrevious, 11U)) + 18186972408589866656U;
            aOrbiterJ = ((((aWandererH + RotL64(aIngress, 57U)) + RotL64(aCarry, 19U)) + 4439324265978331914U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1]) + RotL64(aNonceWordH, 55U);
            aOrbiterK = (((aWandererJ + RotL64(aPrevious, 41U)) + RotL64(aCarry, 39U)) + 13099263173016322486U) + RotL64(aNonceWordD, 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 7041561081767500660U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 6196422612687812971U;
            aOrbiterC = RotL64((aOrbiterC * 13359900204297781063U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 7664260932541281413U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 17802347823020441056U) ^ RotL64(aNonceWordG, 57U);
            aOrbiterK = RotL64((aOrbiterK * 2220679459017369255U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 4253107484061190446U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 13799496534030645312U) ^ RotL64(aNonceWordA, 47U);
            aOrbiterE = RotL64((aOrbiterE * 9167675060053848207U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 14252892847595951926U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 5663527578664291422U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 18314294235895182465U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 11148755959699137661U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 17036900929333594592U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16041243617369003291U), 53U);
            //
            aIngress = RotL64(aOrbiterE, 47U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aScatter, 43U) + aOrbiterJ) + RotL64(aOrbiterC, 53U)) + RotL64(aNonceWordF, 38U));
            aWandererB = aWandererB + (((((RotL64(aPrevious, 53U) + aOrbiterE) + RotL64(aOrbiterK, 20U)) + RotL64(aCarry, 13U)) + RotL64(aNonceWordB, 41U)) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 12U) + RotL64(aOrbiterE, 35U)) + aOrbiterD);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 21U) + RotL64(aOrbiterJ, 3U)) + aOrbiterD) + RotL64(aCarry, 35U)) + aPhaseBWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 35U) + aOrbiterD) + RotL64(aOrbiterK, 11U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererH, 19U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 13U) ^ RotL64(aNonceWordG, 53U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 31623U)) & S_BLOCK1], 40U) ^ RotL64(aOperationLaneB[((aIndex + 28695U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 5U) ^ RotL64(aNonceWordA, 13U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 30390U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneB[((aIndex + 30992U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 47U) + RotL64(aCarry, 21U)) + (RotL64(aIngress, 3U) ^ RotL64(aCross, 34U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterE = ((aWandererK + RotL64(aScatter, 13U)) + 3448371607470865612U) + RotL64(aNonceWordF, 59U);
            aOrbiterC = (((aWandererJ + RotL64(aIngress, 47U)) + RotL64(aCarry, 13U)) + 3743742913651580573U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 37U)) + 13069491287948807280U) + RotL64(aNonceWordC, 19U);
            aOrbiterF = ((aWandererC + RotL64(aCross, 60U)) + RotL64(aCarry, 27U)) + 16872779275586545632U;
            aOrbiterG = (((aWandererE + RotL64(aScatter, 23U)) + RotL64(aCarry, 43U)) + 17945792656755062795U) + aPhaseBOrbiterAssignSaltF[((aIndex + 14U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 18199747196793731853U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 15953311878379809513U;
            aOrbiterK = RotL64((aOrbiterK * 5476802169152352897U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 941268763494588338U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 10090221530365796809U;
            aOrbiterC = RotL64((aOrbiterC * 14035236086292997613U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 8335698093307607001U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 6147498804734306100U;
            aOrbiterE = RotL64((aOrbiterE * 6904444049941211327U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 5980246079567570090U) + RotL64(aNonceWordA, 58U);
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 4152167624425912978U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10019421651535123573U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 14990418790239735916U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 3418668387496597219U) ^ RotL64(aNonceWordE, 3U);
            aOrbiterG = RotL64((aOrbiterG * 12814077238529863119U), 21U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterG, 3U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 52U));
            aIngress = aIngress + RotL64(aOrbiterC, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterF, 56U)) + aOrbiterK);
            aWandererJ = aWandererJ + (((((RotL64(aIngress, 13U) + aOrbiterE) + RotL64(aOrbiterK, 19U)) + RotL64(aCarry, 51U)) + RotL64(aNonceWordD, 7U)) + aPhaseBWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterE, 43U)) + aOrbiterC);
            aWandererC = aWandererC + (((((RotL64(aCross, 3U) + RotL64(aOrbiterG, 3U)) + aOrbiterC) + RotL64(aCarry, 27U)) + RotL64(aNonceWordH, 13U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 56U) + aOrbiterG) + RotL64(aOrbiterE, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 37U));
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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

void TwistExpander_Boxing_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x8C207FB9A640EFFBULL + 0xFC3121F7556DA88BULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x8D783FE752230171ULL + 0x9524C666E24C5CDDULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x81DDD7E24E457627ULL + 0xC3198C9809B62882ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xF3BF7CFCF89D7F3DULL + 0xDB733037F3E93057ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xF2F71B3D2A0788E1ULL + 0xFDD52BF41802D752ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x8B1F5BAE7397555FULL + 0xC2EDEA61BA4A2789ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x879C81746F198321ULL + 0xA1894D5D479B057FULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x9C0D453FD5962B67ULL + 0x9CFCD1604B2F3B25ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 27U) ^ RotL64(aNonceWordG, 43U)) ^ RotL64(aNonceWordH, 19U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 801U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 6417U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 5U) ^ RotL64(aNonceWordF, 58U)) ^ RotL64(aNonceWordA, 29U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 3984U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneA[((aIndex + 5108U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCross, 3U) + RotL64(aPrevious, 35U)) + (RotL64(aIngress, 20U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 43U)) + 9435962834163239322U) + aPhaseCOrbiterAssignSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = (aWandererI + RotL64(aIngress, 60U)) + 10524704356081318973U;
            aOrbiterH = (((aWandererA + RotL64(aCross, 21U)) + 7403401305665208680U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1]) + RotL64(aNonceWordB, 43U);
            aOrbiterD = (aWandererB + RotL64(aPrevious, 35U)) + 7525414805023556493U;
            aOrbiterB = ((aWandererK + RotL64(aCross, 5U)) + RotL64(aCarry, 27U)) + 1116686470029070951U;
            aOrbiterA = (aWandererG + RotL64(aPrevious, 53U)) + 13257612299137802420U;
            aOrbiterG = (((aWandererJ + RotL64(aScatter, 47U)) + RotL64(aCarry, 53U)) + 9181543003986598283U) + RotL64(aNonceWordD, 45U);
            aOrbiterC = ((aWandererH + RotL64(aIngress, 11U)) + RotL64(aCarry, 13U)) + 9739384852307501107U;
            aOrbiterK = (aWandererF + RotL64(aPrevious, 30U)) + 11308402900229016057U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 14935167593705272337U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 7171824007631943535U;
            aOrbiterH = RotL64((aOrbiterH * 4839974427616194289U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 8068411284829563567U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 12350207458513447578U;
            aOrbiterA = RotL64((aOrbiterA * 813973258659041895U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 17039236343991574134U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 18291683592714999632U;
            aOrbiterC = RotL64((aOrbiterC * 7771718817924840713U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 6239616841884430968U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 10604527977569876774U;
            aOrbiterK = RotL64((aOrbiterK * 6972820410084939637U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 1707724300671717658U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 3802268808625297647U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11296811630387191563U), 23U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterK) + 9423064323799920219U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1]) + RotL64(aNonceWordF, 21U);
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 242153923313096551U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12117679073775630197U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 945801070951928277U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 13094814302414492064U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14638176479878969775U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 7572219725951040117U) + RotL64(aNonceWordE, 14U);
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 16494986983782503428U;
            aOrbiterF = RotL64((aOrbiterF * 2739189408707408171U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 10949497978229234856U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 11219643352002119905U;
            aOrbiterB = RotL64((aOrbiterB * 16900635614259262873U), 13U);
            //
            aIngress = RotL64(aOrbiterG, 35U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterC, 26U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterH, 43U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterB, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterG, 5U)) + aOrbiterH);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterG, 19U)) + aOrbiterC);
            aWandererG = aWandererG + ((((RotL64(aScatter, 27U) + aOrbiterF) + RotL64(aOrbiterG, 48U)) + RotL64(aCarry, 39U)) + aPhaseCWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 60U) + RotL64(aOrbiterG, 39U)) + aOrbiterJ) + aPhaseCWandererUpdateSaltB[((aIndex + 6U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 53U) + RotL64(aOrbiterD, 13U)) + aOrbiterB) + RotL64(aNonceWordH, 25U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterB, 23U)) + aOrbiterH);
            aWandererI = aWandererI + (((RotL64(aCross, 11U) + RotL64(aOrbiterF, 43U)) + aOrbiterA) + RotL64(aCarry, 19U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterK, 56U)) + aOrbiterF) + RotL64(aNonceWordG, 59U));
            aWandererB = aWandererB + ((RotL64(aCross, 34U) + RotL64(aOrbiterJ, 29U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererG, 34U) ^ aWandererJ);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + (RotL64(aWandererI, 5U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererF, 47U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 43U) ^ RotL64(aNonceWordC, 23U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 15564U)) & S_BLOCK1], 52U) ^ RotL64(aOperationLaneD[((aIndex + 14523U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 52U) ^ RotL64(aNonceWordD, 43U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 9989U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((aIndex + 10649U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 19U) + RotL64(aCross, 37U)) ^ (RotL64(aCarry, 50U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterK = ((aWandererJ + RotL64(aCross, 28U)) + 4634399531433127141U) + RotL64(aNonceWordE, 15U);
            aOrbiterF = (aWandererG + RotL64(aIngress, 19U)) + 16961792729406903200U;
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 11U)) + 4105280732301137738U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterC = (aWandererC + RotL64(aScatter, 57U)) + 15692013501147331191U;
            aOrbiterB = (((aWandererF + RotL64(aIngress, 23U)) + RotL64(aCarry, 51U)) + 1252216715968780587U) + aPhaseCOrbiterAssignSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = (((aWandererE + RotL64(aCross, 39U)) + RotL64(aCarry, 29U)) + 7958289043012473752U) + RotL64(aNonceWordH, 39U);
            aOrbiterI = (aWandererH + RotL64(aScatter, 52U)) + 6611577301818896615U;
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 47U)) + RotL64(aCarry, 39U)) + 8506226754305949140U;
            aOrbiterG = (aWandererA + RotL64(aScatter, 5U)) + 3648813120449403353U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 5195245426245535735U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 542948051600803051U;
            aOrbiterA = RotL64((aOrbiterA * 4631106308856448475U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 11974253551208964789U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 10596463592332655367U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10941161258815714641U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 12015129484061440159U) + RotL64(aNonceWordB, 23U);
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 8254944355710109060U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3233697992479357615U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 2754858806943915419U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 5007802002906662779U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15613733948331639723U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 6262190752136523216U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 10528977986487821428U) ^ RotL64(aNonceWordG, 22U);
            aOrbiterG = RotL64((aOrbiterG * 1184258264034585525U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 8511097226098211854U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 12091864735686692582U;
            aOrbiterK = RotL64((aOrbiterK * 6128140528141411237U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 4970966265236842566U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 10728884018459718341U;
            aOrbiterC = RotL64((aOrbiterC * 18205183219769602827U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 13760057185629905360U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 6590269178744829056U;
            aOrbiterE = RotL64((aOrbiterE * 14482684769712170123U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 765826377665103262U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 9364759196106579706U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10315111163659289329U), 47U);
            //
            aIngress = RotL64(aOrbiterC, 34U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 37U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 23U));
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterI, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aCross, 42U) + aOrbiterK) + RotL64(aOrbiterB, 29U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterA, 53U)) + aOrbiterE);
            aWandererG = aWandererG + ((((RotL64(aIngress, 53U) + aOrbiterC) + RotL64(aOrbiterB, 5U)) + RotL64(aCarry, 43U)) + RotL64(aNonceWordC, 9U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 5U) + aOrbiterH) + RotL64(aOrbiterF, 48U));
            aWandererC = aWandererC + ((((RotL64(aIngress, 38U) + RotL64(aOrbiterA, 23U)) + aOrbiterG) + RotL64(aNonceWordA, 55U)) + aPhaseCWandererUpdateSaltC[((aIndex + 28U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 21U) + aOrbiterG) + RotL64(aOrbiterF, 57U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 57U) + aOrbiterI) + RotL64(aOrbiterA, 35U)) + RotL64(aCarry, 35U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 13U) + aOrbiterE) + RotL64(aOrbiterK, 19U));
            aWandererD = aWandererD + (((RotL64(aCross, 47U) + RotL64(aOrbiterI, 12U)) + aOrbiterG) + aPhaseCWandererUpdateSaltE[((aIndex + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererG, 53U);
            aCarry = aCarry + RotL64(aIngress, 24U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 42U) ^ RotL64(aNonceWordB, 27U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 19031U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16471U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 28U) ^ RotL64(aNonceWordH, 13U)) ^ RotL64(aNonceWordF, 51U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 18679U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 18618U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 37U) + RotL64(aPrevious, 52U)) ^ (RotL64(aCross, 11U) + RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterE = (aWandererD + RotL64(aScatter, 47U)) + 16183871922837164759U;
            aOrbiterD = (((aWandererJ + RotL64(aIngress, 4U)) + RotL64(aCarry, 21U)) + 7002058258090219055U) + RotL64(aNonceWordB, 25U);
            aOrbiterB = ((aWandererB + RotL64(aCross, 23U)) + RotL64(aCarry, 37U)) + 5650868611888303705U;
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 43U)) + RotL64(aCarry, 57U)) + 11899839660943876690U;
            aOrbiterA = (((aWandererH + RotL64(aScatter, 57U)) + 15349649504488111111U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 6U)) & S_SALT1]) + RotL64(aNonceWordH, 59U);
            aOrbiterH = (aWandererI + RotL64(aCross, 39U)) + 14060149569086744970U;
            aOrbiterG = (aWandererA + RotL64(aIngress, 10U)) + 12920917574225030112U;
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 19U)) + 2831994965175330135U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterJ = (aWandererG + RotL64(aIngress, 51U)) + 18312543585028439192U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 11657562205118394239U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 10850792819281246052U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10663100544207879337U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 17810371216216125323U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 7963413941144223128U) ^ RotL64(aNonceWordE, 9U);
            aOrbiterE = RotL64((aOrbiterE * 534217972450595401U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 5498715358793875584U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 9256727548911651373U;
            aOrbiterK = RotL64((aOrbiterK * 10498848323914000989U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 17246360111302191699U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 18309978718113983369U;
            aOrbiterD = RotL64((aOrbiterD * 18267472694666221077U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 3100998994319502921U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 8129301860291235970U;
            aOrbiterA = RotL64((aOrbiterA * 17847033539279176187U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 1889641029473279114U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 16538494307002917945U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8081488217920885783U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 5432230549146849322U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 2634437941396090817U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7612999214758935211U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 16940172599174185058U) + RotL64(aNonceWordD, 3U);
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 13151669140593952203U;
            aOrbiterC = RotL64((aOrbiterC * 16225319638131723487U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 3995064294869931681U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 913081077665768816U;
            aOrbiterJ = RotL64((aOrbiterJ * 9299514648768060453U), 23U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterD, 27U);
            aIngress = aIngress + (RotL64(aOrbiterG, 18U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + (RotL64(aOrbiterA, 53U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterE, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aCross, 38U) + aOrbiterC) + RotL64(aOrbiterJ, 35U)) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 13U) + RotL64(aOrbiterE, 29U)) + aOrbiterC) + RotL64(aNonceWordG, 30U));
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 43U) + RotL64(aOrbiterC, 39U)) + aOrbiterG) + RotL64(aNonceWordC, 11U)) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterH, 52U)) + aOrbiterA);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterK, 43U)) + aOrbiterH);
            aWandererF = aWandererF + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterB, 11U)) + aOrbiterJ) + RotL64(aCarry, 13U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterE, 23U)) + aOrbiterA);
            aWandererB = aWandererB + (((RotL64(aCross, 3U) + aOrbiterG) + RotL64(aOrbiterD, 56U)) + RotL64(aCarry, 53U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 58U) + aOrbiterD) + RotL64(aOrbiterA, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 54U) ^ aWandererA);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + (RotL64(aWandererC, 37U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 27U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererG, 23U);
            aCarry = aCarry + RotL64(aIngress, 34U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 53U) ^ RotL64(aNonceWordE, 41U)) ^ RotL64(aNonceWordH, 27U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 27742U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((aIndex + 28662U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 11U) ^ RotL64(aNonceWordC, 19U)) ^ RotL64(aNonceWordG, 54U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 32170U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneD[((aIndex + 32025U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 22U) + RotL64(aCarry, 39U)) + (RotL64(aIngress, 5U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterB = (aWandererD + RotL64(aIngress, 47U)) + 7075016829833562104U;
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 23U)) + RotL64(aCarry, 11U)) + 8783765886115517036U;
            aOrbiterC = (aWandererI + RotL64(aCross, 27U)) + 2996723892384565829U;
            aOrbiterI = ((aWandererH + RotL64(aScatter, 34U)) + 9494134707342189476U) + RotL64(aNonceWordA, 57U);
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 11U)) + 5052642981395679904U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 43U)) + RotL64(aCarry, 53U)) + 8766787055127962238U;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 53U)) + RotL64(aCarry, 27U)) + 4467211954388738079U;
            aOrbiterF = ((aWandererC + RotL64(aCross, 38U)) + 8030255604633658608U) + aPhaseCOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 19U)) + 16962408063455702251U) + RotL64(aNonceWordG, 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 3768222186567699076U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 14930990410207899871U;
            aOrbiterC = RotL64((aOrbiterC * 10930005786146268241U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 14179761938395502502U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 1879084742719898108U) ^ RotL64(aNonceWordH, 23U);
            aOrbiterA = RotL64((aOrbiterA * 16783034788172670121U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 5535012408925981515U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 12792553516710295939U;
            aOrbiterK = RotL64((aOrbiterK * 8577530993755159329U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 8979253163346099252U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 5559189896063990740U;
            aOrbiterB = RotL64((aOrbiterB * 8832485423727331621U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 13937564337299044079U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 2393376759689394948U;
            aOrbiterI = RotL64((aOrbiterI * 2352815657830413941U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 12647519563697356479U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 10946871249960389549U) ^ RotL64(aNonceWordF, 55U);
            aOrbiterH = RotL64((aOrbiterH * 6272580371881237173U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 13376798695582123147U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 10958115913599631271U;
            aOrbiterF = RotL64((aOrbiterF * 18233981473003345217U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 4283914227806672773U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 910842005516235816U;
            aOrbiterJ = RotL64((aOrbiterJ * 6722229871617873429U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 1509644316619370324U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 165987596716078174U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13600064054240185123U), 19U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterC, 19U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 40U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + (RotL64(aOrbiterA, 13U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterB, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 35U) + aOrbiterA) + RotL64(aOrbiterI, 29U)) + RotL64(aNonceWordC, 41U));
            aWandererD = aWandererD + (((RotL64(aCross, 57U) + aOrbiterB) + RotL64(aOrbiterH, 52U)) + RotL64(aCarry, 47U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 26U) + RotL64(aOrbiterJ, 47U)) + aOrbiterE);
            aWandererF = aWandererF + (((RotL64(aScatter, 39U) + aOrbiterH) + RotL64(aOrbiterI, 43U)) + RotL64(aCarry, 37U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 43U) + aOrbiterJ) + RotL64(aOrbiterF, 23U)) + RotL64(aNonceWordB, 54U));
            aWandererI = aWandererI + (((RotL64(aScatter, 11U) + aOrbiterA) + RotL64(aOrbiterH, 10U)) + aPhaseCWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterF, 19U)) + aOrbiterC) + aPhaseCWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aCross, 21U) + aOrbiterJ) + RotL64(aOrbiterK, 39U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 4U) + aOrbiterA) + RotL64(aOrbiterJ, 3U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 42U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 23U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 53U));
            aCarry = aCarry + RotL64(aWandererI, 29U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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

void TwistExpander_Boxing_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xD6934800786331A1ULL + 0xB2C9C53EE602564EULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xD933936B8AFCA025ULL + 0xCB57DD543D2475FFULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xD8B9F0C5298EAE87ULL + 0xCEB357AE14D8F6EBULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xF63A198B6AB34025ULL + 0x9BCB40CC4954EF6DULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x878BD26F77DBC99DULL + 0xDB70E21EB6635F97ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x8D64EAF6C0DAE841ULL + 0xAFE24F96A98AA10FULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xDD8EC5D1AB6E889DULL + 0x94227B71751769B4ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xCB921D87004C64CFULL + 0xFD2BC72575CF555EULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 19U) ^ RotL64(aNonceWordE, 27U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 5405U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((aIndex + 3674U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 28U) ^ RotL64(aNonceWordH, 11U)) ^ RotL64(aNonceWordG, 37U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2609U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 1217U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 11U) ^ RotL64(aCarry, 36U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterK = (aWandererI + RotL64(aPrevious, 26U)) + 15036852811491820366U;
            aOrbiterE = (aWandererG + RotL64(aCross, 39U)) + 305637140752898475U;
            aOrbiterF = ((aWandererE + RotL64(aScatter, 3U)) + 11948631574496129610U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = (aWandererA + RotL64(aIngress, 35U)) + 5321623592482991426U;
            aOrbiterA = ((aWandererD + RotL64(aScatter, 43U)) + 4075270159062690728U) + aPhaseDOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = (((aWandererK + RotL64(aCross, 21U)) + RotL64(aCarry, 23U)) + 15111580500356908928U) + RotL64(aNonceWordC, 24U);
            aOrbiterC = (aWandererJ + RotL64(aIngress, 53U)) + 7244150695504160363U;
            aOrbiterG = (((aWandererF + RotL64(aPrevious, 23U)) + RotL64(aCarry, 39U)) + 5131563519577488862U) + RotL64(aNonceWordD, 43U);
            aOrbiterD = ((aWandererB + RotL64(aIngress, 30U)) + RotL64(aCarry, 11U)) + 5881954992088651371U;
            aOrbiterB = (aWandererH + RotL64(aScatter, 51U)) + 12780935808751507998U;
            aOrbiterH = (aWandererC + RotL64(aCross, 47U)) + 12599159643925470226U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 9466589929741834066U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 6093158735705189789U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7453778295800853653U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 17461243886150519249U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 15456408913739900718U) ^ RotL64(aNonceWordA, 29U);
            aOrbiterJ = RotL64((aOrbiterJ * 16093292401746174671U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 11260643903290392780U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 7870342756041882616U) ^ RotL64(aNonceWordF, 35U);
            aOrbiterK = RotL64((aOrbiterK * 2431528656086173419U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 134484990005888936U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 10626896209992890407U;
            aOrbiterI = RotL64((aOrbiterI * 12034131076645285597U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 14031164129515132292U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 1771835705730244212U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 186981668443596623U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 16395472745067254664U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 1455944290845294254U;
            aOrbiterD = RotL64((aOrbiterD * 6757824754363319079U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 17866422769075350837U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 10226884082632410805U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 206035536985843815U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 14474587247775371703U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 8501763445324525303U;
            aOrbiterE = RotL64((aOrbiterE * 5298694643596784007U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 222650368553738561U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 3901452368735982094U;
            aOrbiterA = RotL64((aOrbiterA * 18347115513126660483U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 3063093906728331146U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 9026710562384443411U;
            aOrbiterG = RotL64((aOrbiterG * 8411243802199203035U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 11282041925238364080U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 15036852811491820366U;
            aOrbiterB = RotL64((aOrbiterB * 18185121326941087841U), 13U);
            //
            aIngress = RotL64(aOrbiterK, 14U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterG, 51U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 23U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 5U));
            aIngress = aIngress + (RotL64(aOrbiterB, 21U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterE, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aIngress, 51U) + RotL64(aOrbiterI, 39U)) + aOrbiterJ) + RotL64(aCarry, 11U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 19U) + aOrbiterB) + RotL64(aOrbiterI, 11U));
            aWandererC = aWandererC + ((((RotL64(aCross, 39U) + aOrbiterH) + RotL64(aOrbiterI, 30U)) + RotL64(aCarry, 35U)) + RotL64(aNonceWordH, 61U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 26U) + aOrbiterB) + RotL64(aOrbiterF, 57U));
            aWandererA = aWandererA + ((RotL64(aCross, 13U) + RotL64(aOrbiterH, 5U)) + aOrbiterD);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterA, 21U)) + aOrbiterG) + aPhaseDWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 43U) + RotL64(aOrbiterA, 48U)) + aOrbiterK) + RotL64(aNonceWordB, 45U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterF, 3U)) + aOrbiterC);
            aWandererE = aWandererE + ((RotL64(aIngress, 37U) + RotL64(aOrbiterC, 43U)) + aOrbiterK);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 10U) + aOrbiterB) + RotL64(aOrbiterD, 13U));
            aWandererK = aWandererK + (((RotL64(aScatter, 3U) + aOrbiterB) + RotL64(aOrbiterE, 51U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 26U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 21U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + (RotL64(aWandererC, 37U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 13U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererH, 19U);
            aCarry = aCarry + RotL64(aIngress, 28U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 60U) ^ RotL64(aNonceWordB, 39U)) ^ RotL64(aNonceWordG, 29U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 10143U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 6617U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 57U) ^ RotL64(aNonceWordC, 3U)) ^ RotL64(aNonceWordD, 13U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 10363U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneB[((aIndex + 6328U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCross, 54U)) + (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterI = (((aWandererF + RotL64(aIngress, 11U)) + 17264605017518259932U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1]) + RotL64(aNonceWordA, 57U);
            aOrbiterD = (aWandererK + RotL64(aScatter, 5U)) + 15209184354580778643U;
            aOrbiterH = ((aWandererH + RotL64(aCross, 26U)) + RotL64(aCarry, 21U)) + 3299527965014731384U;
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 35U)) + RotL64(aCarry, 39U)) + 16293096431816127821U;
            aOrbiterB = (aWandererJ + RotL64(aCross, 3U)) + 11031983436878828337U;
            aOrbiterG = (aWandererC + RotL64(aScatter, 57U)) + 9188018632448236358U;
            aOrbiterA = (aWandererE + RotL64(aIngress, 43U)) + 13420816400363406556U;
            aOrbiterE = (aWandererD + RotL64(aPrevious, 37U)) + 2485063384097917101U;
            aOrbiterC = (((aWandererA + RotL64(aIngress, 54U)) + RotL64(aCarry, 27U)) + 3089135816938128264U) + RotL64(aNonceWordB, 26U);
            aOrbiterJ = (aWandererB + RotL64(aScatter, 29U)) + 10730544971770435788U;
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 19U)) + 10431767565618874806U) + aPhaseDOrbiterAssignSaltA[((aIndex + 6U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 14883796491656899074U) + RotL64(aNonceWordH, 39U);
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 13465877783538483706U;
            aOrbiterH = RotL64((aOrbiterH * 14311686051108108503U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 13322163435314643713U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 3307316600284371955U;
            aOrbiterD = RotL64((aOrbiterD * 12337846092069506365U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 4950101626975919939U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 2596253994220103666U;
            aOrbiterB = RotL64((aOrbiterB * 7181706961838582889U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 17961706029559914243U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 10321902557977495175U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16189559888625084711U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 18146616411403012772U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 8414050129421955787U;
            aOrbiterC = RotL64((aOrbiterC * 14879448948196182863U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 11739172334166341121U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 7936637782633487291U;
            aOrbiterI = RotL64((aOrbiterI * 14940929920543800413U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 3160044627483874242U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 16816384076887379704U;
            aOrbiterF = RotL64((aOrbiterF * 5052772186568301951U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 8101560104988710226U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 8851416379738817624U;
            aOrbiterG = RotL64((aOrbiterG * 16767420038937389027U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 9941784290055185679U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 14495651885701938495U) ^ RotL64(aNonceWordF, 55U);
            aOrbiterE = RotL64((aOrbiterE * 1540692851998143607U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 10599676325220702167U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 16092000942942971187U;
            aOrbiterJ = RotL64((aOrbiterJ * 2457268192247656817U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 16168470945107928109U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 17264605017518259932U;
            aOrbiterK = RotL64((aOrbiterK * 15038386057529909273U), 19U);
            //
            aIngress = RotL64(aOrbiterH, 21U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 51U));
            aIngress = aIngress + (RotL64(aOrbiterC, 19U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 56U));
            aIngress = aIngress + RotL64(aOrbiterG, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 53U) + aOrbiterC) + RotL64(aOrbiterI, 35U));
            aWandererC = aWandererC + ((RotL64(aIngress, 19U) + aOrbiterH) + RotL64(aOrbiterE, 21U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterA, 60U)) + aOrbiterB);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 41U) + aOrbiterJ) + RotL64(aOrbiterF, 53U)) + RotL64(aCarry, 53U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterH, 5U)) + aOrbiterB);
            aWandererE = aWandererE + ((RotL64(aPrevious, 30U) + RotL64(aOrbiterI, 13U)) + aOrbiterD);
            aWandererA = aWandererA ^ (((RotL64(aCross, 27U) + aOrbiterK) + RotL64(aOrbiterC, 27U)) + RotL64(aNonceWordG, 41U));
            aWandererD = aWandererD + (((RotL64(aIngress, 3U) + RotL64(aOrbiterB, 30U)) + aOrbiterK) + RotL64(aCarry, 5U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 23U) + aOrbiterJ) + RotL64(aOrbiterA, 43U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterD, 39U)) + aOrbiterC) + aPhaseDWandererUpdateSaltA[((aIndex + 16U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 50U) + RotL64(aOrbiterG, 41U)) + aOrbiterA) + RotL64(aNonceWordD, 15U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 48U));
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererK);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + RotL64(aWandererH, 27U);
            aCarry = aCarry + RotL64(aIngress, 46U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 51U) ^ RotL64(aNonceWordF, 11U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 11943U)) & S_BLOCK1], 28U) ^ RotL64(aOperationLaneA[((aIndex + 12985U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 53U) ^ RotL64(aNonceWordA, 3U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16275U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneC[((aIndex + 16230U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 11U) ^ RotL64(aPrevious, 41U)) + (RotL64(aIngress, 56U) + RotL64(aCarry, 29U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 41U)) + RotL64(aCarry, 11U)) + 12669015908335980355U;
            aOrbiterB = ((aWandererG + RotL64(aCross, 11U)) + 5438715179868613192U) + aPhaseDOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = (((aWandererD + RotL64(aScatter, 20U)) + RotL64(aCarry, 41U)) + 13172104448184536460U) + RotL64(aNonceWordD, 5U);
            aOrbiterC = ((aWandererI + RotL64(aIngress, 43U)) + RotL64(aCarry, 37U)) + 13421421503244744803U;
            aOrbiterD = ((aWandererB + RotL64(aCross, 51U)) + 13327113302994856582U) + aPhaseDOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = ((aWandererA + RotL64(aIngress, 3U)) + 4671768205922454413U) + RotL64(aNonceWordC, 41U);
            aOrbiterG = (aWandererC + RotL64(aPrevious, 35U)) + 5355759962838579929U;
            aOrbiterA = (aWandererF + RotL64(aScatter, 5U)) + 6691720614265406851U;
            aOrbiterF = (aWandererH + RotL64(aPrevious, 53U)) + 7063906424700911378U;
            aOrbiterK = (aWandererK + RotL64(aScatter, 39U)) + 17328616394166672263U;
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 28U)) + 1542940602574207068U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 7203866278803132454U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 993485696233139264U;
            aOrbiterH = RotL64((aOrbiterH * 11609009908810366447U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 15659679028507488331U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterC) ^ 18321361454094675842U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1]) ^ RotL64(aNonceWordA, 9U);
            aOrbiterE = RotL64((aOrbiterE * 3966860765622641843U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 9633319822696783352U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 3496559332232402963U;
            aOrbiterB = RotL64((aOrbiterB * 7772060229838162977U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 1918349708324205526U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 7701088402761359134U;
            aOrbiterD = RotL64((aOrbiterD * 9649485438465644795U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 6006824348814439686U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 18088375375347012557U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12801082943086128385U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 12816533373478543584U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 17951880253818836433U;
            aOrbiterK = RotL64((aOrbiterK * 8935839101517220201U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 11311632024372748238U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 9891349164779752351U) ^ RotL64(aNonceWordG, 55U);
            aOrbiterI = RotL64((aOrbiterI * 11405973752233193209U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 711130292000437038U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 17818800917771709681U;
            aOrbiterC = RotL64((aOrbiterC * 10567029732245868263U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 10188714200240109442U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 9745615081760948652U;
            aOrbiterG = RotL64((aOrbiterG * 9321909462220134035U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 6508703788527163965U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 7536038073603467381U;
            aOrbiterF = RotL64((aOrbiterF * 12015514242701199813U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 2793951597846756844U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 12669015908335980355U;
            aOrbiterJ = RotL64((aOrbiterJ * 7355285540199760689U), 35U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterH, 53U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 35U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 46U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterE, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aIngress, 30U) + RotL64(aOrbiterH, 11U)) + aOrbiterD) + aPhaseDWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 27U) + aOrbiterI) + RotL64(aOrbiterD, 58U)) + RotL64(aCarry, 13U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterH, 41U)) + aOrbiterE);
            aWandererB = aWandererB + ((((RotL64(aCross, 21U) + RotL64(aOrbiterB, 51U)) + aOrbiterC) + RotL64(aCarry, 57U)) + aPhaseDWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 37U) + aOrbiterF) + RotL64(aOrbiterE, 43U));
            aWandererA = aWandererA + ((RotL64(aIngress, 57U) + RotL64(aOrbiterA, 13U)) + aOrbiterD);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterC, 37U)) + aOrbiterG) + RotL64(aNonceWordH, 8U));
            aWandererH = aWandererH + ((RotL64(aCross, 53U) + aOrbiterC) + RotL64(aOrbiterH, 35U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 19U) + aOrbiterH) + RotL64(aOrbiterA, 29U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 47U) + aOrbiterE) + RotL64(aOrbiterK, 26U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 4U) + RotL64(aOrbiterJ, 5U)) + aOrbiterG) + RotL64(aNonceWordE, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 46U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererF);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 21U));
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererK, 56U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 27U) ^ RotL64(aNonceWordA, 57U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 19925U)) & S_BLOCK1], 38U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 18829U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 27U) ^ RotL64(aNonceWordF, 4U)) ^ RotL64(aNonceWordD, 19U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 17137U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19898U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 13U) + RotL64(aPrevious, 57U)) ^ (RotL64(aIngress, 26U) ^ RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterK = (aWandererK + RotL64(aCross, 20U)) + 16124889768301047791U;
            aOrbiterF = (((aWandererE + RotL64(aIngress, 39U)) + 11912338587186717280U) + aPhaseDOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1]) + RotL64(aNonceWordG, 55U);
            aOrbiterG = (aWandererA + RotL64(aScatter, 57U)) + 8594012868813114354U;
            aOrbiterC = ((aWandererG + RotL64(aPrevious, 41U)) + 18281043566156682815U) + aPhaseDOrbiterAssignSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = (aWandererD + RotL64(aScatter, 5U)) + 16853106130200942302U;
            aOrbiterD = (aWandererI + RotL64(aIngress, 3U)) + 2611212958619673086U;
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 43U)) + RotL64(aCarry, 57U)) + 18039472325066855180U;
            aOrbiterH = (aWandererB + RotL64(aCross, 10U)) + 14495785571345122046U;
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 13U)) + 4556063793412832418U;
            aOrbiterB = (((aWandererH + RotL64(aScatter, 27U)) + RotL64(aCarry, 19U)) + 14896419970271244358U) + RotL64(aNonceWordC, 23U);
            aOrbiterA = ((aWandererF + RotL64(aCross, 29U)) + RotL64(aCarry, 51U)) + 880028529183500036U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 2379557167489415783U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 11854373946064529806U;
            aOrbiterG = RotL64((aOrbiterG * 150755294320438887U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 1487252775956449964U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 12777924204511625545U;
            aOrbiterE = RotL64((aOrbiterE * 1366019527386994789U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 15998631485222477969U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterC) ^ 8864212892296191613U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]) ^ RotL64(aNonceWordH, 41U);
            aOrbiterD = RotL64((aOrbiterD * 579242788050369815U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 17069347835763226743U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 7443008171694679791U) ^ RotL64(aNonceWordB, 49U);
            aOrbiterJ = RotL64((aOrbiterJ * 748894368884566607U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 17334256152350782002U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 8986626119086556393U;
            aOrbiterH = RotL64((aOrbiterH * 2258172145924120235U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 8528180968228358674U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 12702290928064582589U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15673603224146737631U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 7742438100860023610U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 3729687240959702198U;
            aOrbiterB = RotL64((aOrbiterB * 3756794766163746783U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 426129097367382096U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 16782175452274911213U;
            aOrbiterA = RotL64((aOrbiterA * 1041477289638333659U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 5942016166948841079U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 5260815086125551703U;
            aOrbiterK = RotL64((aOrbiterK * 1603799103692438147U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 11732742583346900772U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 17182924380693084401U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14858685629471497071U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 8539335803784852017U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 16124889768301047791U;
            aOrbiterC = RotL64((aOrbiterC * 6607245691919237755U), 29U);
            //
            aIngress = RotL64(aOrbiterF, 10U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterK, 27U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterE, 39U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterB, 34U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aIngress, 41U) + aOrbiterE) + RotL64(aOrbiterA, 13U)) + RotL64(aNonceWordE, 45U));
            aWandererH = aWandererH + ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterB, 43U)) + aOrbiterE) + RotL64(aNonceWordA, 42U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 54U) + RotL64(aOrbiterF, 60U)) + aOrbiterB);
            aWandererD = aWandererD + ((RotL64(aScatter, 39U) + RotL64(aOrbiterF, 23U)) + aOrbiterH);
            aWandererC = aWandererC ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterJ, 21U)) + aOrbiterD) + aPhaseDWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterH, 11U)) + aOrbiterG);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 36U) + RotL64(aOrbiterG, 29U)) + aOrbiterC);
            aWandererG = aWandererG + (((RotL64(aScatter, 23U) + RotL64(aOrbiterB, 57U)) + aOrbiterD) + RotL64(aCarry, 39U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 19U) + aOrbiterF) + RotL64(aOrbiterK, 5U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 3U) + RotL64(aOrbiterC, 41U)) + aOrbiterJ) + RotL64(aCarry, 51U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 29U) + aOrbiterB) + RotL64(aOrbiterI, 34U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 46U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 13U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 53U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 5U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + RotL64(aWandererA, 26U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 43U) ^ RotL64(aNonceWordG, 29U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 24766U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23265U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 21U) ^ RotL64(aNonceWordE, 36U)) ^ RotL64(aNonceWordF, 13U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 24745U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((aIndex + 26841U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 56U) ^ RotL64(aCarry, 23U)) + (RotL64(aCross, 5U) + RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterB = (aWandererF + RotL64(aCross, 27U)) + 13053031069776604052U;
            aOrbiterF = (aWandererA + RotL64(aPrevious, 23U)) + 1331396630251085122U;
            aOrbiterH = (aWandererC + RotL64(aScatter, 43U)) + 15879286043343942393U;
            aOrbiterG = (((aWandererH + RotL64(aIngress, 18U)) + 13590365633321406830U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1]) + RotL64(aNonceWordG, 19U);
            aOrbiterI = (aWandererD + RotL64(aCross, 21U)) + 14569235423040242618U;
            aOrbiterA = ((aWandererG + RotL64(aIngress, 29U)) + RotL64(aCarry, 39U)) + 11397370636618371560U;
            aOrbiterE = ((aWandererI + RotL64(aPrevious, 11U)) + 3455933494593971847U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = (aWandererK + RotL64(aScatter, 13U)) + 1307153376443784593U;
            aOrbiterK = ((aWandererE + RotL64(aCross, 3U)) + RotL64(aCarry, 47U)) + 10688618762584786871U;
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 58U)) + 17746248451153600096U) + RotL64(aNonceWordE, 7U);
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 47U)) + RotL64(aCarry, 13U)) + 8512568600755410158U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 8950230550112591092U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 17790968369472845496U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5104988920132008913U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 12583323865381967534U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 11243927099685293887U;
            aOrbiterA = RotL64((aOrbiterA * 12867003042486433971U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 9690268715525781389U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 7466066217365074653U;
            aOrbiterD = RotL64((aOrbiterD * 17565696765505320889U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 3673528673209875118U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 14079103852360952255U;
            aOrbiterJ = RotL64((aOrbiterJ * 17449228863409999629U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 6747836856132250630U) + RotL64(aNonceWordA, 25U);
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 5027692924422297153U;
            aOrbiterB = RotL64((aOrbiterB * 2492421273167124437U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 11370341866003395776U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 14013204893442579282U;
            aOrbiterG = RotL64((aOrbiterG * 6602239957997240785U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 3436953430697936790U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 6399073534839993637U;
            aOrbiterE = RotL64((aOrbiterE * 14186050072610021241U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 7054057507823631422U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 5752085719673338095U;
            aOrbiterK = RotL64((aOrbiterK * 13252660162476029593U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 10628323020010327594U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 5029617362660411790U;
            aOrbiterC = RotL64((aOrbiterC * 7230663968894173433U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 6816547880074551571U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 6683840259024813282U) ^ RotL64(aNonceWordH, 54U);
            aOrbiterF = RotL64((aOrbiterF * 13145224557159574541U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 5952768353050729617U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 13053031069776604052U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13710064584055068065U), 29U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterJ, 47U);
            aIngress = aIngress + (RotL64(aOrbiterH, 38U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 41U));
            aIngress = aIngress + (RotL64(aOrbiterC, 3U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterK, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 41U) + RotL64(aOrbiterK, 29U)) + aOrbiterE) + RotL64(aCarry, 29U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 22U) + RotL64(aOrbiterI, 21U)) + aOrbiterD);
            aWandererK = aWandererK + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterG, 27U)) + aOrbiterE);
            aWandererA = aWandererA ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterJ, 6U)) + aOrbiterC);
            aWandererG = aWandererG + (((RotL64(aPrevious, 5U) + aOrbiterK) + RotL64(aOrbiterA, 47U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 43U) + aOrbiterB) + RotL64(aOrbiterC, 51U)) + RotL64(aNonceWordD, 27U));
            aWandererE = aWandererE + ((RotL64(aScatter, 28U) + RotL64(aOrbiterD, 3U)) + aOrbiterG);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 47U) + aOrbiterG) + RotL64(aOrbiterH, 57U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 13U) + RotL64(aOrbiterG, 41U)) + aOrbiterA);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 35U) + aOrbiterF) + RotL64(aOrbiterC, 38U));
            aWandererD = aWandererD + ((((RotL64(aCross, 3U) + aOrbiterJ) + RotL64(aOrbiterB, 19U)) + RotL64(aCarry, 43U)) + RotL64(aNonceWordC, 55U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 26U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 21U));
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererI, 3U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 3U) ^ RotL64(aNonceWordE, 37U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 30757U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneB[((aIndex + 30726U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 57U) ^ RotL64(aNonceWordB, 5U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 31078U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneB[((aIndex + 32758U)) & S_BLOCK1], 42U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 19U) ^ RotL64(aCarry, 47U)) ^ (RotL64(aIngress, 34U) + RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterI = (aWandererF + RotL64(aIngress, 53U)) + 3973833383430652211U;
            aOrbiterK = (((aWandererA + RotL64(aCross, 60U)) + RotL64(aCarry, 29U)) + 5760227042747169187U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = (aWandererD + RotL64(aScatter, 41U)) + 4923009065139227286U;
            aOrbiterE = (aWandererC + RotL64(aPrevious, 21U)) + 1477807307009107590U;
            aOrbiterD = ((aWandererB + RotL64(aScatter, 3U)) + 5707194514329007301U) + RotL64(aNonceWordF, 47U);
            aOrbiterF = (aWandererG + RotL64(aCross, 51U)) + 5340439728375269724U;
            aOrbiterB = (aWandererE + RotL64(aIngress, 43U)) + 17080457898946572387U;
            aOrbiterC = (((aWandererK + RotL64(aPrevious, 27U)) + RotL64(aCarry, 5U)) + 281559150259472813U) + aPhaseDOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = (aWandererH + RotL64(aScatter, 39U)) + 16160633048230910560U;
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 19U)) + RotL64(aCarry, 47U)) + 9003989610509592121U;
            aOrbiterA = ((aWandererJ + RotL64(aCross, 30U)) + 10579322462808454333U) + RotL64(aNonceWordD, 25U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 15059383289528723069U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 10417647757852880956U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1457919230286043137U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 14484665027393813330U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 12344463053485837974U;
            aOrbiterD = RotL64((aOrbiterD * 5762654194001525041U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 5826453246659297805U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 12547902286376986223U;
            aOrbiterF = RotL64((aOrbiterF * 2982850000322672789U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 9637855144278126174U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterG) ^ 2132744427444501938U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]) ^ RotL64(aNonceWordC, 22U);
            aOrbiterB = RotL64((aOrbiterB * 5911587798564836199U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 9248933938130311231U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 13274297928717090383U;
            aOrbiterC = RotL64((aOrbiterC * 2901398809555237563U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 3690262236918560930U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 3626005326410800344U;
            aOrbiterH = RotL64((aOrbiterH * 13030443356669355355U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 10801089744186148218U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 5446653082176311031U;
            aOrbiterJ = RotL64((aOrbiterJ * 4594267575901248321U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 3205541585889107366U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 4532327942368884436U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16287094987689326229U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 9755333481079721632U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 722154154363571049U;
            aOrbiterI = RotL64((aOrbiterI * 11002432494248958957U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 8071668483354405205U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 8770466248803121315U;
            aOrbiterK = RotL64((aOrbiterK * 12780438190628717807U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 1999251593502332271U) + RotL64(aNonceWordA, 7U);
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 3973833383430652211U;
            aOrbiterE = RotL64((aOrbiterE * 5325244982474631559U), 19U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterD, 3U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 27U));
            aIngress = aIngress + (RotL64(aOrbiterK, 43U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 11U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 30U));
            aIngress = aIngress + RotL64(aOrbiterA, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterE, 30U)) + aOrbiterA) + RotL64(aNonceWordE, 19U));
            aWandererF = aWandererF + (((RotL64(aCross, 30U) + RotL64(aOrbiterK, 5U)) + aOrbiterI) + RotL64(aCarry, 57U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 41U) + aOrbiterB) + RotL64(aOrbiterC, 47U));
            aWandererE = aWandererE + (((RotL64(aScatter, 53U) + RotL64(aOrbiterG, 3U)) + aOrbiterC) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterI, 57U)) + aOrbiterF);
            aWandererD = aWandererD + ((RotL64(aCross, 56U) + aOrbiterD) + RotL64(aOrbiterJ, 27U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterC, 37U)) + aOrbiterD);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 43U) + aOrbiterE) + RotL64(aOrbiterK, 41U)) + RotL64(aCarry, 47U));
            aWandererA = aWandererA ^ ((((RotL64(aPrevious, 39U) + RotL64(aOrbiterH, 50U)) + aOrbiterE) + RotL64(aNonceWordH, 3U)) + aPhaseDWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aScatter, 37U) + aOrbiterB) + RotL64(aOrbiterF, 35U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 13U) + aOrbiterI) + RotL64(aOrbiterD, 53U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 60U));
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererJ);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererF, 18U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererI, 23U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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

void TwistExpander_Boxing_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x8C1FC0889476C39FULL + 0xADFCC6381ACA6926ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x8C41559E3636E68FULL + 0x873CE09BE82082DAULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xD6177E8384F769A7ULL + 0x8EBAC1F5EB3B6D25ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xBCD9208E04AC9DD3ULL + 0xD12043A2AF87AA89ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xBC39D279747F923DULL + 0xEA4482D0838C78F1ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xF3A088A08C5D65AFULL + 0x8E54F93046C12138ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xBB446100B8FD2F81ULL + 0xD2993ABC9EF3A36AULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xD54FA913E5DF1B0DULL + 0xA87536AADC3FC8CBULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 4U) ^ RotL64(aNonceWordA, 29U));
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 394U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneC[((aIndex + 453U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 46U) ^ RotL64(aNonceWordB, 21U)) ^ RotL64(aNonceWordF, 29U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 2780U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 3701U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aIngress, 5U)) + (RotL64(aCarry, 21U) ^ RotL64(aPrevious, 34U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 29U)) + RotL64(aCarry, 57U)) + 4773124477323378268U;
            aOrbiterH = (((aWandererB + RotL64(aCross, 44U)) + RotL64(aCarry, 19U)) + 16848723289435796005U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = (aWandererG + RotL64(aPrevious, 21U)) + 13846642134917107058U;
            aOrbiterG = (aWandererF + RotL64(aIngress, 13U)) + 6472057872482789939U;
            aOrbiterA = ((aWandererI + RotL64(aScatter, 27U)) + 2747019500690707226U) + RotL64(aNonceWordE, 55U);
            aOrbiterC = (aWandererD + RotL64(aCross, 47U)) + 9003965289739733880U;
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 19U)) + RotL64(aCarry, 23U)) + 3013390651936257377U;
            aOrbiterF = (aWandererJ + RotL64(aIngress, 51U)) + 3331004709895625067U;
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 41U)) + 15355010435553517129U) + RotL64(aNonceWordG, 36U);
            aOrbiterD = (aWandererK + RotL64(aScatter, 39U)) + 7709870658004280052U;
            aOrbiterB = ((aWandererC + RotL64(aIngress, 4U)) + 13568728443963926564U) + aPhaseEOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 12409548853419307131U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 969183352023661537U;
            aOrbiterK = RotL64((aOrbiterK * 5549220554838837145U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 15370309834426476775U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 3896803894396631184U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11018830202891911603U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 10848873633291935766U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 12885336509190543440U;
            aOrbiterJ = RotL64((aOrbiterJ * 1487357252619221365U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 8252290890093788010U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 9201553615601641350U;
            aOrbiterG = RotL64((aOrbiterG * 420321130559162915U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 14014209645503188472U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 4015071464301844550U;
            aOrbiterI = RotL64((aOrbiterI * 17444195018239904971U), 3U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterC) + 16173085647514027347U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1]) + RotL64(aNonceWordC, 5U);
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 16916627014974363360U;
            aOrbiterE = RotL64((aOrbiterE * 7699587344277490953U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 1591680303404522110U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 16499606051269327916U;
            aOrbiterB = RotL64((aOrbiterB * 814405848002794813U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 6932673635509444619U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 8745681160108707944U;
            aOrbiterH = RotL64((aOrbiterH * 14565255558668084787U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 10387263947888920455U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 2553335462317280031U;
            aOrbiterA = RotL64((aOrbiterA * 7253573275397985211U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 17449861295444216249U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 15716408844914738774U;
            aOrbiterF = RotL64((aOrbiterF * 10132631423215542589U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 16974370193820578179U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 4773124477323378268U) ^ RotL64(aNonceWordH, 47U);
            aOrbiterD = RotL64((aOrbiterD * 8982190762960590543U), 21U);
            //
            aIngress = RotL64(aOrbiterG, 35U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterA, 60U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterB, 43U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterK, 27U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterI, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aPrevious, 5U) + aOrbiterA) + RotL64(aOrbiterG, 35U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 23U) + aOrbiterI) + RotL64(aOrbiterH, 13U)) + RotL64(aNonceWordD, 45U));
            aWandererA = aWandererA + (((RotL64(aIngress, 58U) + RotL64(aOrbiterJ, 41U)) + aOrbiterK) + aPhaseEWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 37U) + aOrbiterG) + RotL64(aOrbiterE, 29U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterF, 3U)) + aOrbiterC) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 21U) + aOrbiterF) + RotL64(aOrbiterA, 60U)) + RotL64(aNonceWordA, 39U));
            aWandererB = aWandererB + (((RotL64(aIngress, 51U) + RotL64(aOrbiterA, 23U)) + aOrbiterJ) + RotL64(aCarry, 19U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 56U) + aOrbiterK) + RotL64(aOrbiterI, 19U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterB, 5U)) + aOrbiterH);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterK, 27U)) + aOrbiterE);
            aWandererK = aWandererK + (((RotL64(aCross, 41U) + aOrbiterK) + RotL64(aOrbiterD, 38U)) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 37U));
            aCarry = aCarry + (RotL64(aWandererB, 48U) ^ aWandererE);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 41U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererC, 29U);
            aCarry = aCarry + RotL64(aIngress, 20U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 13U) ^ RotL64(aNonceWordG, 60U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 6483U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 7213U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 48U) ^ RotL64(aNonceWordE, 37U)) ^ RotL64(aNonceWordA, 3U));
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 10643U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneB[((aIndex + 6457U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 38U) ^ RotL64(aCarry, 19U)) + (RotL64(aCross, 57U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterB = (((aWandererB + RotL64(aCross, 43U)) + RotL64(aCarry, 57U)) + 11039986441331892533U) + RotL64(aNonceWordA, 7U);
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 57U)) + 6256024955965426119U) + aPhaseEOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = (((aWandererI + RotL64(aPrevious, 13U)) + 9857443189988995666U) + aPhaseEOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1]) + RotL64(aNonceWordC, 43U);
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 3U)) + RotL64(aCarry, 21U)) + 11900944813380998208U;
            aOrbiterG = (aWandererA + RotL64(aCross, 11U)) + 8422577734978875541U;
            aOrbiterI = (aWandererH + RotL64(aIngress, 46U)) + 3100835100713928724U;
            aOrbiterC = (aWandererE + RotL64(aScatter, 39U)) + 11871553509810206993U;
            aOrbiterE = (aWandererG + RotL64(aPrevious, 5U)) + 17614749493763417027U;
            aOrbiterH = (aWandererK + RotL64(aScatter, 23U)) + 3638372131856199916U;
            aOrbiterA = ((aWandererF + RotL64(aIngress, 41U)) + RotL64(aCarry, 53U)) + 6582275259281025770U;
            aOrbiterD = (aWandererD + RotL64(aCross, 36U)) + 17016882418498941958U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 1747214688658984715U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 9356088987044015278U;
            aOrbiterF = RotL64((aOrbiterF * 16221733545319753695U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 4056238112133473456U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 16013150119949532998U) ^ RotL64(aNonceWordH, 19U);
            aOrbiterK = RotL64((aOrbiterK * 12913648646318115315U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 16076621211111834889U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 9940824359571581765U;
            aOrbiterG = RotL64((aOrbiterG * 11624767861336495331U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 15624084004784515753U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 7630989544834680335U;
            aOrbiterC = RotL64((aOrbiterC * 12261063237156822067U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 18003586430673313786U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 1654118743290334161U;
            aOrbiterH = RotL64((aOrbiterH * 1153250137357176071U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 3254189676528343910U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 15629083361573065165U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17024833368570949107U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 10056859810555674806U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 15976683222786846254U;
            aOrbiterJ = RotL64((aOrbiterJ * 2801754232182942635U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 11872378594829637933U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 7633773773528713489U;
            aOrbiterI = RotL64((aOrbiterI * 8218288492011593353U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 16305188578382203720U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 13293036594949754170U;
            aOrbiterE = RotL64((aOrbiterE * 1300645662609848183U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 15185013801659166674U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 11562899709899198100U;
            aOrbiterA = RotL64((aOrbiterA * 9115495024409604629U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 1525205566739385260U) + RotL64(aNonceWordD, 61U);
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 11039986441331892533U;
            aOrbiterD = RotL64((aOrbiterD * 9802284050237622047U), 47U);
            //
            aIngress = RotL64(aOrbiterC, 44U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterG, 29U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 23U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + (RotL64(aOrbiterA, 13U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterK, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aCross, 24U) + aOrbiterF) + RotL64(aOrbiterJ, 14U)) + RotL64(aNonceWordF, 51U));
            aWandererF = aWandererF + (((RotL64(aScatter, 57U) + RotL64(aOrbiterC, 41U)) + aOrbiterH) + RotL64(aNonceWordE, 22U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 5U) + aOrbiterC) + RotL64(aOrbiterI, 53U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterJ, 37U)) + aOrbiterG);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 11U) + aOrbiterK) + RotL64(aOrbiterH, 29U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 47U) + aOrbiterB) + RotL64(aOrbiterE, 19U)) + RotL64(aCarry, 11U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterA, 51U)) + aOrbiterB);
            aWandererB = aWandererB + ((((RotL64(aIngress, 60U) + RotL64(aOrbiterH, 11U)) + aOrbiterF) + RotL64(aCarry, 27U)) + aPhaseEWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 27U) + aOrbiterC) + RotL64(aOrbiterF, 23U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 43U) + aOrbiterF) + RotL64(aOrbiterD, 27U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterG, 44U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + (RotL64(aWandererK, 44U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererD, 6U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 30U) ^ RotL64(aNonceWordB, 43U)) ^ RotL64(aNonceWordE, 5U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 11136U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 14341U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 51U) ^ RotL64(aNonceWordF, 27U)) ^ RotL64(aNonceWordH, 39U));
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 14508U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneC[((aIndex + 15541U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 24U) + RotL64(aCarry, 57U)) ^ (RotL64(aIngress, 11U) ^ RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 20U)) + 11698283336767769359U) + RotL64(aNonceWordB, 29U);
            aOrbiterH = (aWandererH + RotL64(aIngress, 29U)) + 13297826354831483872U;
            aOrbiterF = (aWandererK + RotL64(aCross, 13U)) + 15254999058287530795U;
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 39U)) + 17474166585085346567U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = ((aWandererA + RotL64(aScatter, 37U)) + RotL64(aCarry, 39U)) + 15684783498452840289U;
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 27U)) + RotL64(aCarry, 57U)) + 5061229733465216486U;
            aOrbiterG = ((aWandererB + RotL64(aCross, 10U)) + RotL64(aCarry, 21U)) + 15370981279168377944U;
            aOrbiterB = (aWandererF + RotL64(aIngress, 3U)) + 17966672773619554092U;
            aOrbiterD = (((aWandererE + RotL64(aScatter, 51U)) + 14685092893994491068U) + aPhaseEOrbiterAssignSaltC[((aIndex + 20U)) & S_SALT1]) + RotL64(aNonceWordG, 27U);
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 47U)) + 12798804186209406389U;
            aOrbiterI = (aWandererC + RotL64(aCross, 43U)) + 2848444181474221574U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 8551142075919636146U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 8833198159158950723U;
            aOrbiterF = RotL64((aOrbiterF * 7650289040764974737U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 7351473160893666232U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 14204899612487622222U;
            aOrbiterA = RotL64((aOrbiterA * 6317485031956448029U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 7008985178526543258U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 13576796403863120356U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13745839827679114077U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 5769784656937900699U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 14075925808204936705U;
            aOrbiterC = RotL64((aOrbiterC * 5844894088757604713U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 17818667502858010896U) + RotL64(aNonceWordD, 15U);
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 16016922065572683130U;
            aOrbiterB = RotL64((aOrbiterB * 7525645833898085373U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 1582458237855075977U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 10830440354527138227U;
            aOrbiterJ = RotL64((aOrbiterJ * 10499386926982228251U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 10653964151654643772U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 11218475491129483859U;
            aOrbiterE = RotL64((aOrbiterE * 3338108067044357141U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 9863649760189649255U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 13790281439048354358U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4682098083538482849U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 14846954923718136337U) + RotL64(aNonceWordC, 19U);
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 522207783972623813U;
            aOrbiterG = RotL64((aOrbiterG * 14299798934454852811U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 426829715716262697U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 7482977730216354509U;
            aOrbiterD = RotL64((aOrbiterD * 6317437989422015173U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 10736099808538972990U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 11698283336767769359U;
            aOrbiterI = RotL64((aOrbiterI * 17230175904095995929U), 5U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterF, 30U);
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterH, 51U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + (RotL64(aOrbiterA, 21U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterG, 36U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aScatter, 41U) + aOrbiterK) + RotL64(aOrbiterH, 41U)) + aPhaseEWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 54U) + aOrbiterE) + RotL64(aOrbiterA, 27U));
            aWandererG = aWandererG + ((RotL64(aIngress, 43U) + RotL64(aOrbiterK, 53U)) + aOrbiterF);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterE, 29U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aScatter, 19U) + RotL64(aOrbiterK, 44U)) + aOrbiterB) + RotL64(aCarry, 35U)) + RotL64(aNonceWordE, 14U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterD, 5U)) + aOrbiterB);
            aWandererE = aWandererE + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterD, 57U)) + aOrbiterE) + RotL64(aCarry, 23U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 39U) + aOrbiterD) + RotL64(aOrbiterI, 37U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterD, 23U)) + aOrbiterJ);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 56U) + aOrbiterJ) + RotL64(aOrbiterG, 39U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 11U) + RotL64(aOrbiterB, 60U)) + aOrbiterC) + RotL64(aNonceWordA, 45U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererI);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 48U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 21U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + RotL64(aWandererB, 44U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 29U) ^ RotL64(aNonceWordE, 43U)) ^ RotL64(aNonceWordA, 3U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 19709U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneB[((aIndex + 20014U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 29U) ^ RotL64(aNonceWordB, 41U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 21625U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 17637U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 40U) ^ RotL64(aCross, 53U)) + (RotL64(aCarry, 21U) + RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterJ = (aWandererC + RotL64(aScatter, 41U)) + 2168513956284366370U;
            aOrbiterA = (((aWandererK + RotL64(aIngress, 23U)) + RotL64(aCarry, 23U)) + 10290361969974613111U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = ((aWandererI + RotL64(aCross, 43U)) + RotL64(aCarry, 37U)) + 15673836275828498050U;
            aOrbiterK = (aWandererE + RotL64(aPrevious, 29U)) + 16600540024145812236U;
            aOrbiterF = (aWandererD + RotL64(aScatter, 12U)) + 9428052101528111892U;
            aOrbiterG = (((aWandererG + RotL64(aPrevious, 19U)) + RotL64(aCarry, 3U)) + 12763657928312763377U) + RotL64(aNonceWordF, 10U);
            aOrbiterD = (aWandererA + RotL64(aCross, 3U)) + 10751286982008662485U;
            aOrbiterE = (aWandererJ + RotL64(aIngress, 5U)) + 1708230173038057979U;
            aOrbiterI = (aWandererB + RotL64(aScatter, 58U)) + 4011389705422783816U;
            aOrbiterC = (aWandererF + RotL64(aPrevious, 27U)) + 11704428328093077714U;
            aOrbiterB = (((aWandererH + RotL64(aIngress, 35U)) + 2055336619674699284U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1]) + RotL64(aNonceWordG, 15U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 1870865272102705804U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 3574214263751923179U) ^ RotL64(aNonceWordC, 5U);
            aOrbiterH = RotL64((aOrbiterH * 13132083406834413563U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 984611970726966186U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 15207945449947643672U;
            aOrbiterF = RotL64((aOrbiterF * 9539470161576639981U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 4181398506373973169U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 15222345431506025949U;
            aOrbiterG = RotL64((aOrbiterG * 6925143692628659467U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 15023513452326240962U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 14965669361708810699U;
            aOrbiterD = RotL64((aOrbiterD * 587008860996713147U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 7985755518735406360U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 225592097619240187U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2313509354133400439U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 3659537916566939383U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 17043668033610689611U;
            aOrbiterI = RotL64((aOrbiterI * 10797634709118100773U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 10217321522161675848U) + RotL64(aNonceWordH, 11U);
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 8013663869536146842U;
            aOrbiterC = RotL64((aOrbiterC * 2293233079384777175U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 13762445330867496042U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 2692400019659269106U;
            aOrbiterB = RotL64((aOrbiterB * 167704184292219399U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 18232551682424867647U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 14785847596876239854U;
            aOrbiterJ = RotL64((aOrbiterJ * 4569180925037758487U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 5910282247522389536U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 16556038638738871204U;
            aOrbiterA = RotL64((aOrbiterA * 18356922295088260901U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 141620663839815754U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 2168513956284366370U;
            aOrbiterK = RotL64((aOrbiterK * 8605382725635471683U), 43U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterK, 20U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 35U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 23U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 56U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterD, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aCross, 3U) + RotL64(aOrbiterJ, 43U)) + aOrbiterF) + RotL64(aCarry, 19U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterB, 10U)) + aOrbiterG) + RotL64(aNonceWordB, 21U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 14U) + RotL64(aOrbiterD, 57U)) + aOrbiterA) + RotL64(aCarry, 37U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterD, 21U)) + aOrbiterK) + RotL64(aNonceWordD, 49U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 43U) + aOrbiterF) + RotL64(aOrbiterH, 5U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterH, 3U)) + aOrbiterC);
            aWandererC = aWandererC + ((RotL64(aIngress, 56U) + aOrbiterB) + RotL64(aOrbiterH, 47U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterB, 35U)) + aOrbiterD);
            aWandererA = aWandererA + ((RotL64(aPrevious, 37U) + RotL64(aOrbiterB, 40U)) + aOrbiterE);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 47U) + aOrbiterI) + RotL64(aOrbiterG, 37U));
            aWandererD = aWandererD + ((RotL64(aCross, 53U) + aOrbiterH) + RotL64(aOrbiterD, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 4U) ^ aWandererD);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + (RotL64(aWandererG, 41U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 21U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererC, 10U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 11U) ^ RotL64(aNonceWordE, 19U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 27005U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 24383U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 11U) ^ RotL64(aNonceWordH, 56U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25741U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22032U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 40U) + RotL64(aCross, 23U)) + (RotL64(aIngress, 11U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterG = (aWandererA + RotL64(aCross, 21U)) + 15813325389431304548U;
            aOrbiterC = (aWandererE + RotL64(aScatter, 43U)) + 2223874171125403602U;
            aOrbiterH = (aWandererK + RotL64(aIngress, 35U)) + 5510483568496824130U;
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 11U)) + 15474152493495661876U;
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 50U)) + 16846339705130829195U) + RotL64(aNonceWordB, 56U);
            aOrbiterK = (aWandererC + RotL64(aCross, 19U)) + 1289670576865739669U;
            aOrbiterA = ((aWandererB + RotL64(aIngress, 3U)) + 18017354919647006944U) + RotL64(aNonceWordA, 47U);
            aOrbiterE = (aWandererH + RotL64(aPrevious, 13U)) + 8539685539928984921U;
            aOrbiterF = (((aWandererF + RotL64(aCross, 60U)) + RotL64(aCarry, 47U)) + 3333721400836704048U) + aPhaseEOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = ((aWandererI + RotL64(aScatter, 39U)) + RotL64(aCarry, 23U)) + 2261560416623815491U;
            aOrbiterD = (((aWandererD + RotL64(aPrevious, 41U)) + RotL64(aCarry, 37U)) + 4377786131746816567U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 18047393176583722719U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 8184724021940434631U;
            aOrbiterH = RotL64((aOrbiterH * 9800116157750921119U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 10469895939183324807U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 14543391765109879223U;
            aOrbiterK = RotL64((aOrbiterK * 4817987697437667225U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 5757225781746158178U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 3539000495894022869U;
            aOrbiterE = RotL64((aOrbiterE * 1032298408884695925U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 11288971092707065923U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 2761384065186568294U;
            aOrbiterB = RotL64((aOrbiterB * 3323838837427471051U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 7120580145300417101U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 6977246291769372866U;
            aOrbiterG = RotL64((aOrbiterG * 15170353875184253779U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 17625434527765525937U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 3299714663631376190U;
            aOrbiterI = RotL64((aOrbiterI * 6532628892760776767U), 35U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterG) + 10331889953489885250U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1]) + RotL64(aNonceWordC, 7U);
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 8550932256881727932U;
            aOrbiterA = RotL64((aOrbiterA * 13085531621192583719U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 11151195711186126257U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 2552002192824926483U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9754056316698523849U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 8038115194286715268U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 16594489591573505305U;
            aOrbiterD = RotL64((aOrbiterD * 1241387574663818247U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 13476964484361081681U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 2136330439951908303U;
            aOrbiterC = RotL64((aOrbiterC * 12728359054660550527U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 231990686776499700U) + RotL64(aNonceWordG, 19U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 15813325389431304548U;
            aOrbiterJ = RotL64((aOrbiterJ * 9155088985405261637U), 41U);
            //
            aIngress = RotL64(aOrbiterD, 46U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterH, 53U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 27U));
            aIngress = aIngress + (RotL64(aOrbiterE, 37U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 11U));
            aIngress = aIngress + RotL64(aOrbiterG, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterF, 51U)) + aOrbiterA);
            aWandererC = aWandererC + ((RotL64(aPrevious, 43U) + aOrbiterD) + RotL64(aOrbiterK, 37U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 35U) + aOrbiterC) + RotL64(aOrbiterA, 41U));
            aWandererH = aWandererH + (((RotL64(aIngress, 18U) + aOrbiterA) + RotL64(aOrbiterH, 58U)) + RotL64(aCarry, 3U));
            aWandererD = aWandererD ^ ((((RotL64(aCross, 3U) + RotL64(aOrbiterJ, 19U)) + aOrbiterG) + RotL64(aNonceWordH, 53U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 41U) + aOrbiterE) + RotL64(aOrbiterI, 27U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterG, 35U)) + aOrbiterD);
            aWandererG = aWandererG + ((RotL64(aIngress, 29U) + aOrbiterF) + RotL64(aOrbiterD, 43U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterF, 23U)) + aOrbiterK);
            aWandererK = aWandererK + ((((RotL64(aCross, 22U) + RotL64(aOrbiterH, 39U)) + aOrbiterI) + RotL64(aCarry, 43U)) + RotL64(aNonceWordF, 27U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 37U) + aOrbiterB) + RotL64(aOrbiterJ, 4U)) + aPhaseEWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 46U) ^ aWandererE);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererA);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 41U));
            aCarry = aCarry + (RotL64(aWandererB, 37U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererH, 14U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordE, 37U) ^ RotL64(aNonceWordF, 14U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 31581U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneB[((aIndex + 30642U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 57U) ^ RotL64(aNonceWordD, 12U)) ^ RotL64(aNonceWordA, 37U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 29536U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneB[((aIndex + 32633U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 13U) + RotL64(aCarry, 41U)) + (RotL64(aPrevious, 53U) ^ RotL64(aCross, 28U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 11U)) + RotL64(aCarry, 53U)) + 2617613537256538553U;
            aOrbiterC = (((aWandererA + RotL64(aIngress, 48U)) + RotL64(aCarry, 3U)) + 16642868916835132715U) + RotL64(aNonceWordD, 57U);
            aOrbiterH = ((aWandererK + RotL64(aScatter, 43U)) + 10860291124337073254U) + aPhaseEOrbiterAssignSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = (aWandererJ + RotL64(aCross, 39U)) + 6432511273906902472U;
            aOrbiterD = ((aWandererD + RotL64(aIngress, 57U)) + 7505375005848241910U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 35U)) + 11086616004678821329U;
            aOrbiterI = ((aWandererH + RotL64(aScatter, 29U)) + RotL64(aCarry, 39U)) + 3298830587569881951U;
            aOrbiterF = ((aWandererI + RotL64(aCross, 3U)) + 9775143140064220979U) + RotL64(aNonceWordF, 58U);
            aOrbiterA = (aWandererF + RotL64(aIngress, 37U)) + 4147601326580823120U;
            aOrbiterG = (aWandererB + RotL64(aCross, 14U)) + 12245920269898100415U;
            aOrbiterE = (aWandererE + RotL64(aScatter, 19U)) + 8391940489176734499U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 17876893379544668477U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 18301882058180370541U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16680384667098921309U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 6869225862715140102U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 15404118372589259800U;
            aOrbiterD = RotL64((aOrbiterD * 5766851935950389915U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 17757381020518233814U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 17677969146092374455U;
            aOrbiterJ = RotL64((aOrbiterJ * 3469432916562405063U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 15783378556632870114U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 5792858258663697864U;
            aOrbiterI = RotL64((aOrbiterI * 12008981883482080427U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 11737803388202260296U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 16001927091970715330U;
            aOrbiterF = RotL64((aOrbiterF * 3062030309852922061U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 1749586939123286632U) + RotL64(aNonceWordE, 61U);
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 6169421068855905938U;
            aOrbiterA = RotL64((aOrbiterA * 12374789910763348695U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 10073586820719728062U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 17744171227198661555U;
            aOrbiterG = RotL64((aOrbiterG * 10658375268803957647U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 1149819647337612792U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 7725598665625892006U;
            aOrbiterE = RotL64((aOrbiterE * 15097586655234391559U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 13930096050550704122U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 3632241034947389647U;
            aOrbiterK = RotL64((aOrbiterK * 8442222389196610427U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 17933893495867517142U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterG) ^ 7888594392078082482U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1]) ^ RotL64(aNonceWordH, 5U);
            aOrbiterC = RotL64((aOrbiterC * 9809847720610861237U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 10805303827043372168U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 2617613537256538553U;
            aOrbiterB = RotL64((aOrbiterB * 3940471942234248791U), 51U);
            //
            aIngress = RotL64(aOrbiterK, 13U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 11U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 35U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 24U));
            aIngress = aIngress + RotL64(aOrbiterI, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterG, 60U)) + aOrbiterD);
            aWandererA = aWandererA + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterE, 43U)) + aOrbiterD) + aPhaseEWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 37U) + RotL64(aOrbiterE, 23U)) + aOrbiterI) + RotL64(aNonceWordG, 11U));
            aWandererE = aWandererE + ((RotL64(aCross, 42U) + RotL64(aOrbiterH, 41U)) + aOrbiterI);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 23U) + aOrbiterF) + RotL64(aOrbiterC, 54U));
            aWandererF = aWandererF + (((((RotL64(aPrevious, 19U) + aOrbiterF) + RotL64(aOrbiterK, 27U)) + RotL64(aCarry, 35U)) + RotL64(aNonceWordC, 17U)) + aPhaseEWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 53U) + aOrbiterD) + RotL64(aOrbiterC, 11U));
            aWandererD = aWandererD + ((RotL64(aCross, 11U) + RotL64(aOrbiterJ, 51U)) + aOrbiterA);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 47U) + aOrbiterC) + RotL64(aOrbiterB, 57U));
            aWandererK = aWandererK + (((RotL64(aScatter, 21U) + aOrbiterA) + RotL64(aOrbiterD, 5U)) + RotL64(aCarry, 53U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 50U) + aOrbiterB) + RotL64(aOrbiterJ, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 18U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 23U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + (RotL64(aWandererB, 29U) ^ aWandererD);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 37U));
            aCarry = aCarry + RotL64(aWandererF, 58U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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

void TwistExpander_Boxing_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xE74A00F1084C68AFULL + 0xE1565DD8AA4E3500ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xBF0BB3F0397E4971ULL + 0xB5745CC35D6794B9ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x8F6143A97F194065ULL + 0xF09C5473A6E85B57ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xAF9CD14DFB5C4A8DULL + 0x973A9D7A16BCBDB2ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xF634C6EED056C365ULL + 0xB00112A4AFA25DD3ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xFA1BFC276E2484C9ULL + 0x8DA46A8EDDA64D24ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xCE0E1DE219457397ULL + 0xBA9AF5CB10101A63ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xF88A1549087A8C99ULL + 0xF051B02E4C4976E7ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 4U) ^ RotL64(aNonceWordB, 19U)) ^ RotL64(aNonceWordF, 43U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 3063U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4607U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 57U) ^ RotL64(aNonceWordG, 29U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 1789U)) & S_BLOCK1], 20U) ^ RotL64(aOperationLaneA[((aIndex + 4192U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 51U) ^ RotL64(aIngress, 37U)) + (RotL64(aPrevious, 5U) + RotL64(aCarry, 22U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterF = ((aWandererD + RotL64(aCross, 41U)) + RotL64(aCarry, 23U)) + 7075016829833562104U;
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 44U)) + 8783765886115517036U) + RotL64(aNonceWordC, 59U);
            aOrbiterH = (aWandererE + RotL64(aPrevious, 11U)) + 2996723892384565829U;
            aOrbiterA = ((((aWandererH + RotL64(aIngress, 57U)) + RotL64(aCarry, 39U)) + 9494134707342189476U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1]) + RotL64(aNonceWordF, 45U);
            aOrbiterB = (aWandererB + RotL64(aScatter, 19U)) + 5052642981395679904U;
            aOrbiterC = ((aWandererA + RotL64(aCross, 34U)) + 8766787055127962238U) + aPhaseFOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 51U)) + RotL64(aCarry, 57U)) + 4467211954388738079U;
            aOrbiterG = (aWandererJ + RotL64(aIngress, 21U)) + 8030255604633658608U;
            aOrbiterI = (aWandererG + RotL64(aPrevious, 13U)) + 16962408063455702251U;
            aOrbiterE = (aWandererK + RotL64(aScatter, 37U)) + 3768222186567699076U;
            aOrbiterD = (aWandererF + RotL64(aIngress, 5U)) + 14930990410207899871U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 14179761938395502502U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 1879084742719898108U;
            aOrbiterH = RotL64((aOrbiterH * 16783034788172670121U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 5535012408925981515U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 12792553516710295939U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8577530993755159329U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 8979253163346099252U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 5559189896063990740U;
            aOrbiterF = RotL64((aOrbiterF * 8832485423727331621U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 13937564337299044079U) + RotL64(aNonceWordE, 27U);
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 2393376759689394948U) ^ RotL64(aNonceWordD, 22U);
            aOrbiterA = RotL64((aOrbiterA * 2352815657830413941U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 12647519563697356479U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 10946871249960389549U;
            aOrbiterK = RotL64((aOrbiterK * 6272580371881237173U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 13376798695582123147U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 10958115913599631271U;
            aOrbiterI = RotL64((aOrbiterI * 18233981473003345217U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 4283914227806672773U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 910842005516235816U;
            aOrbiterD = RotL64((aOrbiterD * 6722229871617873429U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 1509644316619370324U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 165987596716078174U;
            aOrbiterJ = RotL64((aOrbiterJ * 13600064054240185123U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 12491315345199091186U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 5982431705686495125U;
            aOrbiterB = RotL64((aOrbiterB * 2547243804779022665U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 231183123382412440U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 2872632389683254396U;
            aOrbiterG = RotL64((aOrbiterG * 1972278820468847241U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 15259314110008210315U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 7075016829833562104U;
            aOrbiterE = RotL64((aOrbiterE * 8350093877370898869U), 43U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterH, 10U);
            aIngress = aIngress + (RotL64(aOrbiterK, 51U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterE, 41U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + (RotL64(aOrbiterD, 23U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterJ, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 19U) + aOrbiterB) + RotL64(aOrbiterD, 26U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterF, 19U)) + aOrbiterH);
            aWandererG = aWandererG + ((RotL64(aIngress, 37U) + RotL64(aOrbiterA, 21U)) + aOrbiterI);
            aWandererB = aWandererB ^ (((RotL64(aCross, 13U) + aOrbiterB) + RotL64(aOrbiterC, 29U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aIngress, 24U) + aOrbiterA) + RotL64(aOrbiterC, 39U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 11U) + aOrbiterE) + RotL64(aOrbiterJ, 54U));
            aWandererK = aWandererK + ((((RotL64(aCross, 5U) + RotL64(aOrbiterH, 5U)) + aOrbiterC) + RotL64(aCarry, 57U)) + RotL64(aNonceWordA, 23U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterC, 35U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 47U) + aOrbiterK) + RotL64(aOrbiterD, 57U)) + RotL64(aNonceWordH, 37U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterA, 47U)) + aOrbiterE);
            aWandererE = aWandererE + (((RotL64(aIngress, 42U) + RotL64(aOrbiterD, 3U)) + aOrbiterG) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 24U) ^ aWandererK);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 53U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 21U));
            aCarry = aCarry + RotL64(aWandererF, 11U);
            aCarry = aCarry + RotL64(aIngress, 14U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 11U) ^ RotL64(aNonceWordD, 27U)) ^ RotL64(aNonceWordB, 36U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 7209U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((aIndex + 10496U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 12U) ^ RotL64(aNonceWordC, 51U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 9136U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 5959U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aIngress, 29U)) ^ (RotL64(aCarry, 53U) + RotL64(aPrevious, 10U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterK = ((aWandererD + RotL64(aCross, 23U)) + RotL64(aCarry, 19U)) + 16160838483846078448U;
            aOrbiterC = (aWandererJ + RotL64(aScatter, 50U)) + 15404960896190227946U;
            aOrbiterI = (aWandererE + RotL64(aPrevious, 47U)) + 16904160594024977199U;
            aOrbiterE = (aWandererK + RotL64(aIngress, 57U)) + 17790460246821031802U;
            aOrbiterB = (((aWandererH + RotL64(aScatter, 53U)) + RotL64(aCarry, 41U)) + 16395168254086971959U) + RotL64(aNonceWordH, 43U);
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 3U)) + 7484373204039901786U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = (aWandererF + RotL64(aCross, 13U)) + 18026814691322913510U;
            aOrbiterG = ((aWandererG + RotL64(aIngress, 60U)) + RotL64(aCarry, 5U)) + 15244817793136966450U;
            aOrbiterD = (aWandererC + RotL64(aScatter, 41U)) + 5795491730356335666U;
            aOrbiterF = (((aWandererB + RotL64(aIngress, 21U)) + 3163873518027801504U) + aPhaseFOrbiterAssignSaltC[((aIndex + 18U)) & S_SALT1]) + RotL64(aNonceWordC, 3U);
            aOrbiterH = (aWandererA + RotL64(aCross, 11U)) + 2690791759507349172U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 17898067251167087906U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 8028010015006604239U;
            aOrbiterI = RotL64((aOrbiterI * 5601629670521300241U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 7304739457289910555U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 6476837815096530043U;
            aOrbiterC = RotL64((aOrbiterC * 16380545138701113267U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 14242499233467960602U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 17305645693017634630U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14442976693206929569U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 9772864059444171908U) + RotL64(aNonceWordG, 17U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 7897200728282156408U;
            aOrbiterJ = RotL64((aOrbiterJ * 816306719390807411U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 4890999319172950996U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 8165132649356094963U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17297706071263690189U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 9342923520083533265U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 7213639583505088067U;
            aOrbiterK = RotL64((aOrbiterK * 1349251979649428909U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 4079475132684197272U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 3350998022472827283U;
            aOrbiterE = RotL64((aOrbiterE * 948841791460066265U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 2479140576609216238U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 7703147534931674972U;
            aOrbiterA = RotL64((aOrbiterA * 11419116495223970801U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 9050277787914448469U) + RotL64(aNonceWordA, 38U);
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 13295888852307317371U;
            aOrbiterG = RotL64((aOrbiterG * 3027097172772140975U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 15380254190549884741U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 17653690414528791774U;
            aOrbiterF = RotL64((aOrbiterF * 15923958179714368315U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 6825072759468337036U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 16160838483846078448U;
            aOrbiterH = RotL64((aOrbiterH * 11690325563580492415U), 5U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterH, 3U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 18U));
            aIngress = aIngress + (RotL64(aOrbiterG, 47U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 27U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 37U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 23U) + aOrbiterI) + RotL64(aOrbiterA, 19U));
            aWandererC = aWandererC + (((RotL64(aIngress, 41U) + RotL64(aOrbiterH, 37U)) + aOrbiterI) + RotL64(aCarry, 53U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterJ, 21U)) + aOrbiterB);
            aWandererG = aWandererG + (((RotL64(aCross, 12U) + aOrbiterB) + RotL64(aOrbiterA, 13U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 35U) + aOrbiterD) + RotL64(aOrbiterI, 35U));
            aWandererK = aWandererK + (((RotL64(aScatter, 57U) + aOrbiterE) + RotL64(aOrbiterC, 3U)) + RotL64(aNonceWordF, 35U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 51U) + aOrbiterG) + RotL64(aOrbiterB, 58U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 10U) + RotL64(aOrbiterK, 23U)) + aOrbiterG);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 3U) + aOrbiterH) + RotL64(aOrbiterF, 29U)) + RotL64(aNonceWordE, 5U));
            aWandererF = aWandererF + (((RotL64(aCross, 47U) + RotL64(aOrbiterF, 5U)) + aOrbiterC) + RotL64(aCarry, 13U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterB, 54U)) + aOrbiterH) + aPhaseFWandererUpdateSaltF[((aIndex + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 24U) ^ aWandererE);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 37U));
            aCarry = aCarry + (RotL64(aWandererB, 41U) ^ aWandererF);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 34U));
            aCarry = aCarry + RotL64(aWandererG, 19U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 42U) ^ RotL64(aNonceWordF, 5U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 14635U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15138U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 21U) ^ RotL64(aNonceWordE, 13U)) ^ RotL64(aNonceWordD, 29U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 13924U)) & S_BLOCK1], 38U) ^ RotL64(aOperationLaneC[((aIndex + 10955U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 18U) ^ RotL64(aPrevious, 5U)) ^ (RotL64(aCarry, 51U) + RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterF = ((aWandererE + RotL64(aScatter, 54U)) + 16651241552253078315U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = (aWandererG + RotL64(aCross, 29U)) + 4558144676982478003U;
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 5U)) + 8814884320080367550U) + RotL64(aNonceWordA, 51U);
            aOrbiterB = (aWandererB + RotL64(aIngress, 41U)) + 16011579668555672117U;
            aOrbiterC = (aWandererI + RotL64(aCross, 19U)) + 4738918668759862438U;
            aOrbiterK = (aWandererD + RotL64(aScatter, 39U)) + 12526083125540985108U;
            aOrbiterD = ((aWandererC + RotL64(aIngress, 37U)) + RotL64(aCarry, 13U)) + 8048723561746000552U;
            aOrbiterA = (aWandererH + RotL64(aPrevious, 47U)) + 1082218464034639039U;
            aOrbiterH = (((aWandererF + RotL64(aIngress, 13U)) + 8432043246965946816U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1]) + RotL64(aNonceWordB, 29U);
            aOrbiterE = ((aWandererA + RotL64(aScatter, 60U)) + RotL64(aCarry, 29U)) + 9982080524048636852U;
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 51U)) + RotL64(aCarry, 57U)) + 6720069955755215919U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 1019035028070247757U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 7360619079463870467U;
            aOrbiterG = RotL64((aOrbiterG * 6623074813047915863U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 10893918488381348474U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 1390297670907738019U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11909657437658597735U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 12512200589031203480U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 14741471280748399540U;
            aOrbiterI = RotL64((aOrbiterI * 3012135242889901095U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 8543897248359826770U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 8545972622733791272U;
            aOrbiterC = RotL64((aOrbiterC * 11793879362775346821U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 7049384618581928664U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterJ) ^ 14730773807906925408U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]) ^ RotL64(aNonceWordD, 53U);
            aOrbiterA = RotL64((aOrbiterA * 10711566871536755073U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 11480717275652449986U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 1135397594974536859U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6347492892938856497U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 6897207625849516702U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 10920630712550287148U;
            aOrbiterF = RotL64((aOrbiterF * 4140705091806993359U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 1094056478999931332U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 6784487144549717207U;
            aOrbiterB = RotL64((aOrbiterB * 6295177724167067891U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 2224992798329560875U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 11486442570446223696U;
            aOrbiterD = RotL64((aOrbiterD * 5680065455032616591U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 14681556190496625711U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 1809388635055225841U;
            aOrbiterH = RotL64((aOrbiterH * 3449474313001177557U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 4480846057441948619U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 16651241552253078315U) ^ RotL64(aNonceWordE, 15U);
            aOrbiterJ = RotL64((aOrbiterJ * 10628778876898064085U), 41U);
            //
            aIngress = RotL64(aOrbiterC, 11U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterA, 35U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterI, 3U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 19U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 40U));
            aIngress = aIngress + RotL64(aOrbiterB, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aPrevious, 23U) + aOrbiterG) + RotL64(aOrbiterC, 3U)) + RotL64(aCarry, 39U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 19U) + aOrbiterA) + RotL64(aOrbiterE, 53U)) + RotL64(aNonceWordC, 10U));
            aWandererG = aWandererG + ((RotL64(aScatter, 14U) + aOrbiterK) + RotL64(aOrbiterD, 39U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 27U) + aOrbiterF) + RotL64(aOrbiterJ, 22U));
            aWandererI = aWandererI + (((RotL64(aScatter, 53U) + RotL64(aOrbiterC, 51U)) + aOrbiterB) + aPhaseFWandererUpdateSaltC[((aIndex + 8U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterF, 29U)) + aOrbiterC);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 57U) + aOrbiterA) + RotL64(aOrbiterH, 11U)) + aPhaseFWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 29U) + aOrbiterF) + RotL64(aOrbiterB, 27U)) + RotL64(aNonceWordG, 43U));
            aWandererB = aWandererB + (((RotL64(aScatter, 5U) + aOrbiterD) + RotL64(aOrbiterH, 47U)) + RotL64(aCarry, 53U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 60U) + aOrbiterB) + RotL64(aOrbiterI, 34U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 43U) + aOrbiterA) + RotL64(aOrbiterK, 43U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 48U));
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererB);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererK);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 21U));
            aCarry = aCarry + RotL64(aWandererA, 39U);
            aCarry = aCarry + RotL64(aIngress, 52U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 3U) ^ RotL64(aNonceWordB, 37U)) ^ RotL64(aNonceWordC, 47U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 19736U)) & S_BLOCK1], 14U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19579U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 3U) ^ RotL64(aNonceWordG, 21U)) ^ RotL64(aNonceWordH, 29U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21671U)) & S_BLOCK1], 54U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 16868U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 51U) + RotL64(aCross, 4U)) ^ (RotL64(aCarry, 23U) ^ RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterJ = (aWandererJ + RotL64(aPrevious, 24U)) + 13333509828310369865U;
            aOrbiterF = (aWandererI + RotL64(aIngress, 11U)) + 7645352517103840797U;
            aOrbiterB = (aWandererC + RotL64(aScatter, 13U)) + 5310766306660062655U;
            aOrbiterA = ((aWandererG + RotL64(aCross, 41U)) + 5165635069832352932U) + RotL64(aNonceWordF, 53U);
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 29U)) + RotL64(aCarry, 43U)) + 15684141764734281849U;
            aOrbiterH = (((aWandererB + RotL64(aIngress, 44U)) + RotL64(aCarry, 37U)) + 3327963374225061738U) + aPhaseFOrbiterAssignSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterD = (aWandererE + RotL64(aScatter, 53U)) + 8625811794878848871U;
            aOrbiterC = ((aWandererF + RotL64(aCross, 3U)) + 7598657468430485291U) + RotL64(aNonceWordG, 4U);
            aOrbiterK = (aWandererH + RotL64(aIngress, 47U)) + 2881171216276746485U;
            aOrbiterE = (((aWandererD + RotL64(aScatter, 19U)) + RotL64(aCarry, 11U)) + 10237691227222918101U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = (aWandererK + RotL64(aPrevious, 21U)) + 6419254255884834497U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 4238455444646479956U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 14936613353493061492U;
            aOrbiterB = RotL64((aOrbiterB * 3544216916806292273U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 15324699725208372627U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 9506640480601832011U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12819564111348390227U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 3709149613660215641U) + RotL64(aNonceWordH, 43U);
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 1724290199312754307U;
            aOrbiterH = RotL64((aOrbiterH * 12597580418257897965U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 13191172833570139194U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 3686087945377837886U;
            aOrbiterD = RotL64((aOrbiterD * 10883609557429936283U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 10418330386245397022U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 5383531313632347245U;
            aOrbiterC = RotL64((aOrbiterC * 2987755379396160073U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 7414716553072652212U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 11301761123966206201U) ^ RotL64(aNonceWordC, 21U);
            aOrbiterK = RotL64((aOrbiterK * 1546727321088592187U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 8570229732236388847U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 8773754460060264773U;
            aOrbiterE = RotL64((aOrbiterE * 3251360788932563495U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 13636929800504199371U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 5486599841558573720U;
            aOrbiterG = RotL64((aOrbiterG * 2867914211589815153U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 13277541451512422776U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 10409779509190185921U;
            aOrbiterJ = RotL64((aOrbiterJ * 1926650154570961573U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 7268295836403414306U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 13815969853235433830U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11603750346752441535U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 9353249174240162324U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 13333509828310369865U;
            aOrbiterA = RotL64((aOrbiterA * 10381405217943841655U), 43U);
            //
            aIngress = RotL64(aOrbiterH, 27U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + (RotL64(aOrbiterB, 53U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + (RotL64(aOrbiterF, 36U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterD, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aIngress, 53U) + aOrbiterC) + RotL64(aOrbiterG, 24U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 29U) + aOrbiterB) + RotL64(aOrbiterE, 39U)) + RotL64(aCarry, 11U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 57U) + aOrbiterA) + RotL64(aOrbiterH, 41U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 5U) + aOrbiterF) + RotL64(aOrbiterI, 21U)) + RotL64(aCarry, 23U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 3U) + aOrbiterH) + RotL64(aOrbiterK, 29U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 47U) + aOrbiterH) + RotL64(aOrbiterG, 13U)) + RotL64(aNonceWordD, 35U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 20U) + RotL64(aOrbiterI, 47U)) + aOrbiterJ);
            aWandererA = aWandererA + ((RotL64(aCross, 43U) + RotL64(aOrbiterE, 54U)) + aOrbiterK);
            aWandererB = aWandererB ^ ((((RotL64(aPrevious, 11U) + aOrbiterD) + RotL64(aOrbiterA, 57U)) + RotL64(aNonceWordE, 47U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aCross, 51U) + RotL64(aOrbiterF, 37U)) + aOrbiterA);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 14U) + RotL64(aOrbiterE, 5U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererA, 48U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 51U));
            aCarry = aCarry + (RotL64(aWandererC, 21U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererE, 26U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 35U) ^ RotL64(aNonceWordD, 47U)) ^ RotL64(aNonceWordF, 27U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22632U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((aIndex + 25694U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 47U) ^ RotL64(aNonceWordH, 5U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 22508U)) & S_BLOCK1], 34U) ^ RotL64(aWorkLaneA[((aIndex + 21934U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 35U) + RotL64(aCross, 3U)) ^ (RotL64(aIngress, 23U) ^ RotL64(aCarry, 52U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterK = ((aWandererI + RotL64(aScatter, 4U)) + 17711946802293254150U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 11U)) + 16652362590489569378U) + RotL64(aNonceWordA, 22U);
            aOrbiterI = ((aWandererE + RotL64(aIngress, 41U)) + 6972810344198183097U) + aPhaseFOrbiterAssignSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterG = (aWandererB + RotL64(aCross, 21U)) + 13117100889782940546U;
            aOrbiterH = (aWandererA + RotL64(aPrevious, 13U)) + 13199305696782626591U;
            aOrbiterJ = (aWandererF + RotL64(aIngress, 23U)) + 992156184392760945U;
            aOrbiterD = (aWandererC + RotL64(aCross, 18U)) + 13791265442074543880U;
            aOrbiterF = (aWandererJ + RotL64(aScatter, 39U)) + 17057087245252294859U;
            aOrbiterC = ((aWandererD + RotL64(aCross, 27U)) + RotL64(aCarry, 29U)) + 13444195995883541046U;
            aOrbiterB = (((aWandererK + RotL64(aScatter, 37U)) + RotL64(aCarry, 3U)) + 6723678233676059420U) + RotL64(aNonceWordD, 59U);
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 51U)) + RotL64(aCarry, 39U)) + 7913379431208430475U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 4481887195529300665U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 11892724101424384078U;
            aOrbiterI = RotL64((aOrbiterI * 3468639499716604111U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 7700902083270424194U) + RotL64(aNonceWordB, 17U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 1888001433557140271U;
            aOrbiterJ = RotL64((aOrbiterJ * 8975562955027025349U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 14996753906788986929U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 939004845422123765U;
            aOrbiterF = RotL64((aOrbiterF * 2507090308972292313U), 35U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterJ) + 11922230289291941807U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1]) + RotL64(aNonceWordG, 51U);
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 15681187459741147199U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10124947739653819101U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 9119043713532718155U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 8327697433992362166U;
            aOrbiterK = RotL64((aOrbiterK * 11157657162184304567U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 13630755116592440359U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 771252613886022889U;
            aOrbiterG = RotL64((aOrbiterG * 2958918915223536519U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 8524239721467527770U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 17732617735422435572U;
            aOrbiterD = RotL64((aOrbiterD * 13992947983987668631U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 5265753270696005619U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 14456128349522985053U;
            aOrbiterC = RotL64((aOrbiterC * 5406509991740849617U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 12909993509014176457U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 10113568710432654194U;
            aOrbiterE = RotL64((aOrbiterE * 6857806395910432831U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 14818978163348513071U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 17843349910031998923U;
            aOrbiterA = RotL64((aOrbiterA * 13608449524810499593U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 12589077818524017161U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 17711946802293254150U;
            aOrbiterH = RotL64((aOrbiterH * 9454569713107675231U), 57U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterD, 27U);
            aIngress = aIngress + (RotL64(aOrbiterA, 5U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterF, 57U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterH, 52U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 35U));
            aIngress = aIngress + RotL64(aOrbiterK, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 11U) + aOrbiterF) + RotL64(aOrbiterH, 53U));
            aWandererE = aWandererE + ((RotL64(aScatter, 27U) + RotL64(aOrbiterD, 27U)) + aOrbiterC);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 51U) + aOrbiterI) + RotL64(aOrbiterG, 3U));
            aWandererA = aWandererA + (((RotL64(aCross, 48U) + aOrbiterD) + RotL64(aOrbiterG, 10U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterH, 51U)) + aOrbiterC) + RotL64(aNonceWordC, 41U));
            aWandererK = aWandererK + (((RotL64(aIngress, 19U) + aOrbiterA) + RotL64(aOrbiterG, 21U)) + RotL64(aCarry, 41U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterF, 19U)) + aOrbiterD);
            aWandererG = aWandererG + ((RotL64(aCross, 41U) + RotL64(aOrbiterK, 57U)) + aOrbiterC);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 21U) + aOrbiterB) + RotL64(aOrbiterF, 14U));
            aWandererB = aWandererB + (((((RotL64(aPrevious, 56U) + aOrbiterI) + RotL64(aOrbiterJ, 35U)) + RotL64(aCarry, 13U)) + RotL64(aNonceWordE, 53U)) + aPhaseFWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterF, 29U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 37U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 46U));
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererD, 35U);
            aCarry = aCarry + RotL64(aIngress, 10U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 57U) ^ RotL64(aNonceWordA, 3U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 29995U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32307U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 5U) ^ RotL64(aNonceWordD, 60U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30042U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30723U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 6U) ^ RotL64(aPrevious, 41U)) + (RotL64(aCarry, 21U) ^ RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterD = (aWandererJ + RotL64(aPrevious, 48U)) + 11700815697312060726U;
            aOrbiterA = ((aWandererD + RotL64(aScatter, 57U)) + 11808423452327465441U) + RotL64(aNonceWordH, 31U);
            aOrbiterC = (aWandererA + RotL64(aCross, 39U)) + 8670503858631730886U;
            aOrbiterK = (((aWandererH + RotL64(aIngress, 53U)) + RotL64(aCarry, 13U)) + 2400061067991988544U) + aPhaseFOrbiterAssignSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = ((aWandererB + RotL64(aCross, 34U)) + RotL64(aCarry, 53U)) + 16163118178366229686U;
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 51U)) + 3280178595904941068U) + RotL64(aNonceWordC, 14U);
            aOrbiterJ = (aWandererC + RotL64(aIngress, 23U)) + 3298683600817047727U;
            aOrbiterH = (aWandererI + RotL64(aScatter, 37U)) + 16321624053445183574U;
            aOrbiterB = (aWandererG + RotL64(aIngress, 5U)) + 6730229877611375225U;
            aOrbiterG = (((aWandererF + RotL64(aPrevious, 43U)) + RotL64(aCarry, 27U)) + 10162830636713641322U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = (aWandererK + RotL64(aScatter, 3U)) + 15646771327759599256U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 14841751262270544102U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 9545541117228834895U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11529769874752969377U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 14676615635857599982U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 1231768638470558855U;
            aOrbiterE = RotL64((aOrbiterE * 2716808508509014677U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 1945905595345404833U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 1406171421638586846U;
            aOrbiterI = RotL64((aOrbiterI * 4577864352425476233U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 1970292335806697198U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 12309719390375013297U;
            aOrbiterJ = RotL64((aOrbiterJ * 16540660957923687327U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 5352135521358954576U) + RotL64(aNonceWordG, 61U);
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 15465675376193501658U;
            aOrbiterH = RotL64((aOrbiterH * 16385761112921041387U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 2842123638916600369U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 3544764287036748668U;
            aOrbiterB = RotL64((aOrbiterB * 3360772950777850115U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 6038297172906492282U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 10249342332287140970U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16701083081566042277U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 1662076777040529446U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 1949705569959740274U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11340691546658994529U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 13934194245417822360U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 5720408806425535958U;
            aOrbiterD = RotL64((aOrbiterD * 15237561081637415383U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 2209251362417210658U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 4917447930929521699U;
            aOrbiterA = RotL64((aOrbiterA * 17489570156694692569U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 14817115766683623486U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 11700815697312060726U) ^ RotL64(aNonceWordD, 19U);
            aOrbiterK = RotL64((aOrbiterK * 16982411053956669181U), 35U);
            //
            aIngress = RotL64(aOrbiterA, 48U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 41U));
            aIngress = aIngress + (RotL64(aOrbiterK, 5U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + RotL64(aOrbiterC, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aIngress, 29U) + RotL64(aOrbiterK, 34U)) + aOrbiterF) + RotL64(aCarry, 5U));
            aWandererA = aWandererA ^ ((((RotL64(aScatter, 26U) + aOrbiterG) + RotL64(aOrbiterI, 43U)) + RotL64(aNonceWordB, 15U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aCross, 11U) + aOrbiterA) + RotL64(aOrbiterI, 3U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 41U) + aOrbiterF) + RotL64(aOrbiterG, 5U));
            aWandererE = aWandererE + (((RotL64(aScatter, 39U) + aOrbiterF) + RotL64(aOrbiterJ, 39U)) + RotL64(aCarry, 11U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterJ, 23U)) + aOrbiterI);
            aWandererD = aWandererD + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterD, 53U)) + aOrbiterF) + RotL64(aNonceWordF, 21U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 13U) + aOrbiterE) + RotL64(aOrbiterB, 51U));
            aWandererI = aWandererI + ((RotL64(aIngress, 56U) + RotL64(aOrbiterH, 13U)) + aOrbiterE);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterC, 27U)) + aOrbiterH);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 51U) + aOrbiterC) + RotL64(aOrbiterF, 46U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererG);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 42U));
            aCarry = aCarry + (RotL64(aWandererI, 37U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + RotL64(aWandererB, 20U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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

void TwistExpander_Boxing_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xA3EC6600F3567E75ULL + 0xF50CF9760EBE8037ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x8A94F8636783BFB7ULL + 0xD8C1535868638306ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xF0D08B2B823ED747ULL + 0xEC34507682B1EB2FULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xC3B80B82939B3ECBULL + 0xAC2FFF7562DDD551ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xBA0BD7B5FE9CDEDFULL + 0xF9138AF05D3D8FC0ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xD5DCA273E1CEE267ULL + 0xF33B5A7AD4ACF986ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xAE70D21DBFEB9235ULL + 0x9A71810CE96E45A1ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xE19AE7D636352C95ULL + 0xE1F38CE0C3A57F3BULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 47U) ^ RotL64(aNonceWordD, 5U)) ^ RotL64(aNonceWordE, 21U));
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 2901U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 5425U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 29U) ^ RotL64(aNonceWordH, 6U)) ^ RotL64(aNonceWordC, 21U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 787U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 1782U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 35U) + RotL64(aCross, 3U)) + (RotL64(aIngress, 53U) ^ RotL64(aCarry, 22U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterG = (aWandererJ + RotL64(aIngress, 38U)) + 16160838483846078448U;
            aOrbiterA = (((aWandererF + RotL64(aScatter, 29U)) + RotL64(aCarry, 13U)) + 15404960896190227946U) + aPhaseFOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = (aWandererD + RotL64(aPrevious, 5U)) + 16904160594024977199U;
            aOrbiterB = (aWandererH + RotL64(aCross, 57U)) + 17790460246821031802U;
            aOrbiterH = (aWandererC + RotL64(aPrevious, 51U)) + 16395168254086971959U;
            aOrbiterE = ((aWandererE + RotL64(aIngress, 3U)) + 7484373204039901786U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = ((aWandererA + RotL64(aScatter, 19U)) + 18026814691322913510U) + RotL64(aNonceWordG, 25U);
            aOrbiterD = ((aWandererK + RotL64(aCross, 43U)) + RotL64(aCarry, 27U)) + 15244817793136966450U;
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 21U)) + RotL64(aCarry, 37U)) + 5795491730356335666U;
            aOrbiterK = (aWandererB + RotL64(aCross, 27U)) + 3163873518027801504U;
            aOrbiterI = ((aWandererI + RotL64(aIngress, 24U)) + 2690791759507349172U) + RotL64(aNonceWordE, 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 17898067251167087906U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 8028010015006604239U;
            aOrbiterF = RotL64((aOrbiterF * 5601629670521300241U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 7304739457289910555U) + RotL64(aNonceWordA, 37U);
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 6476837815096530043U;
            aOrbiterE = RotL64((aOrbiterE * 16380545138701113267U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 14242499233467960602U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 17305645693017634630U;
            aOrbiterG = RotL64((aOrbiterG * 14442976693206929569U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 9772864059444171908U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 7897200728282156408U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 816306719390807411U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 4890999319172950996U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterI) ^ 8165132649356094963U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]) ^ RotL64(aNonceWordD, 21U);
            aOrbiterC = RotL64((aOrbiterC * 17297706071263690189U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 9342923520083533265U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 7213639583505088067U;
            aOrbiterJ = RotL64((aOrbiterJ * 1349251979649428909U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 4079475132684197272U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 3350998022472827283U;
            aOrbiterI = RotL64((aOrbiterI * 948841791460066265U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 2479140576609216238U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 7703147534931674972U;
            aOrbiterA = RotL64((aOrbiterA * 11419116495223970801U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 9050277787914448469U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 13295888852307317371U;
            aOrbiterH = RotL64((aOrbiterH * 3027097172772140975U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 15380254190549884741U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 17653690414528791774U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15923958179714368315U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 6825072759468337036U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 16160838483846078448U;
            aOrbiterK = RotL64((aOrbiterK * 11690325563580492415U), 37U);
            //
            aIngress = RotL64(aOrbiterE, 27U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 37U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 53U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 14U));
            aIngress = aIngress + RotL64(aOrbiterC, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterG, 29U)) + aOrbiterA) + RotL64(aNonceWordB, 55U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 44U) + aOrbiterH) + RotL64(aOrbiterA, 35U));
            aWandererK = aWandererK + ((((RotL64(aCross, 23U) + aOrbiterC) + RotL64(aOrbiterI, 13U)) + RotL64(aCarry, 47U)) + aPhaseFWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 29U) + aOrbiterA) + RotL64(aOrbiterD, 43U));
            aWandererB = aWandererB + ((((RotL64(aScatter, 39U) + aOrbiterD) + RotL64(aOrbiterE, 39U)) + RotL64(aCarry, 27U)) + RotL64(aNonceWordC, 38U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterI, 56U)) + aOrbiterE);
            aWandererF = aWandererF + ((RotL64(aCross, 13U) + RotL64(aOrbiterF, 51U)) + aOrbiterJ);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterK, 11U)) + aOrbiterE);
            aWandererH = aWandererH + (((RotL64(aPrevious, 19U) + aOrbiterC) + RotL64(aOrbiterB, 53U)) + aPhaseFWandererUpdateSaltB[((aIndex + 14U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 46U) + aOrbiterD) + RotL64(aOrbiterH, 48U));
            aWandererE = aWandererE + ((RotL64(aCross, 57U) + aOrbiterH) + RotL64(aOrbiterJ, 5U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 53U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (RotL64(aWandererD, 37U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 44U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererB, 13U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 5U) ^ RotL64(aNonceWordA, 58U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 7024U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 9997U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 34U) ^ RotL64(aNonceWordE, 21U)) ^ RotL64(aNonceWordB, 51U));
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 9276U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 8126U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 14U) ^ RotL64(aPrevious, 27U)) ^ (RotL64(aCarry, 51U) + RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterG = (((aWandererD + RotL64(aCross, 29U)) + RotL64(aCarry, 29U)) + 17264605017518259932U) + RotL64(aNonceWordH, 15U);
            aOrbiterC = (aWandererE + RotL64(aScatter, 46U)) + 15209184354580778643U;
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 37U)) + RotL64(aCarry, 43U)) + 3299527965014731384U;
            aOrbiterA = ((aWandererF + RotL64(aIngress, 19U)) + 16293096431816127821U) + aPhaseFOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = (aWandererG + RotL64(aScatter, 13U)) + 11031983436878828337U;
            aOrbiterI = (aWandererH + RotL64(aIngress, 39U)) + 9188018632448236358U;
            aOrbiterE = (aWandererK + RotL64(aPrevious, 23U)) + 13420816400363406556U;
            aOrbiterD = ((aWandererA + RotL64(aCross, 52U)) + 2485063384097917101U) + RotL64(aNonceWordE, 43U);
            aOrbiterH = (aWandererI + RotL64(aPrevious, 21U)) + 3089135816938128264U;
            aOrbiterK = ((aWandererC + RotL64(aScatter, 5U)) + RotL64(aCarry, 39U)) + 10730544971770435788U;
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 35U)) + 10431767565618874806U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 14883796491656899074U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 13465877783538483706U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14311686051108108503U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 13322163435314643713U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 3307316600284371955U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12337846092069506365U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 4950101626975919939U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 2596253994220103666U;
            aOrbiterB = RotL64((aOrbiterB * 7181706961838582889U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 17961706029559914243U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 10321902557977495175U;
            aOrbiterE = RotL64((aOrbiterE * 16189559888625084711U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 18146616411403012772U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 8414050129421955787U;
            aOrbiterH = RotL64((aOrbiterH * 14879448948196182863U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 11739172334166341121U) + RotL64(aNonceWordC, 39U);
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 7936637782633487291U;
            aOrbiterG = RotL64((aOrbiterG * 14940929920543800413U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 3160044627483874242U) + RotL64(aNonceWordB, 23U);
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 16816384076887379704U;
            aOrbiterA = RotL64((aOrbiterA * 5052772186568301951U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 8101560104988710226U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 8851416379738817624U;
            aOrbiterI = RotL64((aOrbiterI * 16767420038937389027U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 9941784290055185679U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 14495651885701938495U;
            aOrbiterD = RotL64((aOrbiterD * 1540692851998143607U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 10599676325220702167U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 16092000942942971187U;
            aOrbiterK = RotL64((aOrbiterK * 2457268192247656817U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 16168470945107928109U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 17264605017518259932U;
            aOrbiterJ = RotL64((aOrbiterJ * 15038386057529909273U), 5U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterJ, 47U);
            aIngress = aIngress + (RotL64(aOrbiterE, 11U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 37U));
            aIngress = aIngress + (RotL64(aOrbiterH, 27U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 23U));
            aIngress = aIngress + RotL64(aOrbiterD, 44U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aPrevious, 28U) + RotL64(aOrbiterF, 23U)) + aOrbiterD);
            aWandererF = aWandererF ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterC, 18U)) + aOrbiterD) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 21U) + RotL64(aOrbiterD, 43U)) + aOrbiterI) + RotL64(aCarry, 21U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 57U) + aOrbiterF) + RotL64(aOrbiterE, 11U)) + aPhaseFWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aScatter, 13U) + RotL64(aOrbiterK, 21U)) + aOrbiterA);
            aWandererD = aWandererD ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterC, 54U)) + aOrbiterF);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterG, 35U)) + aOrbiterA) + RotL64(aCarry, 51U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 35U) + aOrbiterB) + RotL64(aOrbiterJ, 29U)) + RotL64(aNonceWordF, 34U));
            aWandererH = aWandererH + (((RotL64(aScatter, 50U) + RotL64(aOrbiterG, 13U)) + aOrbiterH) + RotL64(aNonceWordG, 59U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 43U) + aOrbiterJ) + RotL64(aOrbiterH, 57U));
            aWandererE = aWandererE + ((RotL64(aCross, 11U) + RotL64(aOrbiterB, 27U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 44U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 21U));
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererA, 41U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererF, 27U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 35U) ^ RotL64(aNonceWordA, 60U)) ^ RotL64(aNonceWordD, 5U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 16216U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneA[((aIndex + 12125U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 60U) ^ RotL64(aNonceWordE, 11U));
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 15287U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 13548U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 36U) + RotL64(aIngress, 51U)) + (RotL64(aCross, 19U) ^ RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterG = (aWandererC + RotL64(aPrevious, 36U)) + 1557680213571812384U;
            aOrbiterH = ((aWandererB + RotL64(aIngress, 27U)) + 7387349725778021121U) + RotL64(aNonceWordE, 39U);
            aOrbiterA = (aWandererD + RotL64(aCross, 43U)) + 15379264067601586976U;
            aOrbiterC = (aWandererF + RotL64(aScatter, 21U)) + 3730195724576043708U;
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 54U)) + RotL64(aCarry, 27U)) + 9637070085323827066U;
            aOrbiterK = (aWandererK + RotL64(aCross, 29U)) + 1170865717363676184U;
            aOrbiterF = (aWandererI + RotL64(aIngress, 11U)) + 2750833653175252030U;
            aOrbiterI = (((aWandererG + RotL64(aScatter, 41U)) + RotL64(aCarry, 43U)) + 15118992811225568305U) + RotL64(aNonceWordD, 3U);
            aOrbiterB = ((aWandererA + RotL64(aCross, 23U)) + RotL64(aCarry, 57U)) + 4974092922102988451U;
            aOrbiterD = ((aWandererE + RotL64(aIngress, 13U)) + 10625719096296719514U) + aPhaseFOrbiterAssignSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = ((aWandererH + RotL64(aScatter, 51U)) + 855167122475471865U) + aPhaseFOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 11322911068958340262U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 4334591909425429835U;
            aOrbiterA = RotL64((aOrbiterA * 10059025861172038183U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 14263701737208936392U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 678723206735649084U;
            aOrbiterK = RotL64((aOrbiterK * 10823239851733632227U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 15652053114252065230U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 1705225940224061401U;
            aOrbiterH = RotL64((aOrbiterH * 3626023093533713579U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 6826394665732900206U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 11902946775066981141U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 18300629262162694137U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 9802212958998591310U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 14001358545610206524U;
            aOrbiterI = RotL64((aOrbiterI * 13172645840788327099U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 4299184726135884309U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 7288757011999872416U;
            aOrbiterD = RotL64((aOrbiterD * 16806027820468277393U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 233801262480580205U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 14208660347238680268U;
            aOrbiterG = RotL64((aOrbiterG * 6299693448313154603U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 9217797359740446104U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 18165073197136050838U) ^ RotL64(aNonceWordC, 45U);
            aOrbiterC = RotL64((aOrbiterC * 11677479094709512887U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 9101905235436427482U) + RotL64(aNonceWordB, 9U);
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 2884224555227870272U;
            aOrbiterF = RotL64((aOrbiterF * 12085235281782370391U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 13118509728421714433U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 1385390888603164704U;
            aOrbiterB = RotL64((aOrbiterB * 6927424835779289199U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 9621084561183039538U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 1557680213571812384U;
            aOrbiterE = RotL64((aOrbiterE * 3202327770291862207U), 27U);
            //
            aIngress = RotL64(aOrbiterG, 11U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 43U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 5U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 34U));
            aIngress = aIngress + (RotL64(aOrbiterD, 51U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aIngress, 53U) + aOrbiterF) + RotL64(aOrbiterK, 19U)) + RotL64(aCarry, 23U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 35U) + aOrbiterK) + RotL64(aOrbiterD, 37U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 51U) + aOrbiterJ) + RotL64(aOrbiterH, 11U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 38U) + RotL64(aOrbiterE, 24U)) + aOrbiterF);
            aWandererF = aWandererF + ((RotL64(aIngress, 43U) + aOrbiterJ) + RotL64(aOrbiterI, 3U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterG, 43U)) + aOrbiterJ);
            aWandererI = aWandererI + (((RotL64(aPrevious, 41U) + aOrbiterA) + RotL64(aOrbiterF, 41U)) + RotL64(aCarry, 41U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterK, 21U)) + aOrbiterI);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterE, 14U)) + aOrbiterC) + RotL64(aNonceWordH, 55U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aCross, 26U) + aOrbiterC) + RotL64(aOrbiterJ, 27U)) + RotL64(aNonceWordF, 58U));
            aWandererD = aWandererD + (((RotL64(aIngress, 3U) + aOrbiterK) + RotL64(aOrbiterB, 39U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererI, 50U) ^ aWandererA);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + RotL64(aWandererF, 37U);
            aCarry = aCarry + RotL64(aIngress, 10U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 21U) ^ RotL64(aNonceWordA, 47U)) ^ RotL64(aNonceWordH, 3U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 18145U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneB[((aIndex + 16435U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 21U) ^ RotL64(aNonceWordD, 35U)) ^ RotL64(aNonceWordG, 13U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 19330U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 20540U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 47U) + RotL64(aCarry, 5U)) + (RotL64(aCross, 22U) ^ RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterI = (aWandererA + RotL64(aPrevious, 43U)) + 15188686795415908074U;
            aOrbiterH = ((aWandererK + RotL64(aScatter, 10U)) + 17310049041983079779U) + RotL64(aNonceWordB, 5U);
            aOrbiterE = (aWandererJ + RotL64(aCross, 57U)) + 8246925977992441471U;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 41U)) + RotL64(aCarry, 5U)) + 8644260919918112781U;
            aOrbiterD = ((aWandererH + RotL64(aCross, 35U)) + 13401663736874819483U) + RotL64(aNonceWordF, 53U);
            aOrbiterG = (aWandererF + RotL64(aIngress, 3U)) + 7940358935238314973U;
            aOrbiterB = ((aWandererC + RotL64(aScatter, 29U)) + RotL64(aCarry, 47U)) + 13278990328548007839U;
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 21U)) + RotL64(aCarry, 13U)) + 11346868298353840706U;
            aOrbiterJ = (aWandererD + RotL64(aIngress, 47U)) + 2374077904806833579U;
            aOrbiterA = ((aWandererG + RotL64(aCross, 14U)) + 6978903378645019166U) + aPhaseFOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = ((aWandererE + RotL64(aScatter, 27U)) + 11951633297870965212U) + aPhaseFOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 17398460995357409673U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 1215437945597836770U;
            aOrbiterE = RotL64((aOrbiterE * 9322970054123481621U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 1878751468043972239U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 5343002808239712390U;
            aOrbiterD = RotL64((aOrbiterD * 11878640995447558811U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 9884918450053276861U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 15894599082080422550U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8359936745539546131U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 13917339232771145459U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 18101134009493720683U;
            aOrbiterB = RotL64((aOrbiterB * 15835859435306756387U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 3830086372356903769U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 15894394599564584010U;
            aOrbiterC = RotL64((aOrbiterC * 9513921913446609263U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 5127590955274245812U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 9410946933309720054U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14507476989423060561U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 15544384157294987085U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 998801294460434123U;
            aOrbiterA = RotL64((aOrbiterA * 5946968142746472745U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 16442095194965452163U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 14294936349037516932U;
            aOrbiterK = RotL64((aOrbiterK * 14655345374740882581U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 16680659892463349201U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 10921918150041635666U;
            aOrbiterI = RotL64((aOrbiterI * 2908474941036821745U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 15350264522133299871U) + RotL64(aNonceWordG, 9U);
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 16413848767507968239U;
            aOrbiterH = RotL64((aOrbiterH * 10226942289998651355U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 11963105565077056299U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 15188686795415908074U) ^ RotL64(aNonceWordC, 18U);
            aOrbiterF = RotL64((aOrbiterF * 13002484121826831091U), 41U);
            //
            aIngress = RotL64(aOrbiterJ, 26U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 29U));
            aIngress = aIngress + (RotL64(aOrbiterE, 47U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterK, 21U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterD, 54U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterF, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 57U) + aOrbiterF) + RotL64(aOrbiterH, 43U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 41U) + aOrbiterE) + RotL64(aOrbiterA, 18U)) + RotL64(aCarry, 5U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 47U) + aOrbiterG) + RotL64(aOrbiterJ, 11U)) + RotL64(aNonceWordE, 23U));
            aWandererE = aWandererE + ((RotL64(aScatter, 19U) + aOrbiterF) + RotL64(aOrbiterK, 3U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 51U) + aOrbiterJ) + RotL64(aOrbiterC, 21U)) + RotL64(aNonceWordH, 13U));
            aWandererC = aWandererC + ((RotL64(aScatter, 24U) + aOrbiterK) + RotL64(aOrbiterB, 29U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 43U) + aOrbiterE) + RotL64(aOrbiterD, 27U));
            aWandererB = aWandererB + ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterI, 58U)) + aOrbiterC) + RotL64(aCarry, 53U)) + aPhaseFWandererUpdateSaltF[((aIndex + 12U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 53U) + aOrbiterB) + RotL64(aOrbiterE, 41U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterG, 53U)) + aOrbiterF) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 30U) + RotL64(aOrbiterE, 23U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererE, 37U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererC, 27U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererB, 18U) ^ aWandererI);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + RotL64(aWandererD, 3U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 3U) ^ RotL64(aNonceWordB, 11U)) ^ RotL64(aNonceWordF, 51U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 24865U)) & S_BLOCK1], 40U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26845U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 29U) ^ RotL64(aNonceWordC, 21U)) ^ RotL64(aNonceWordD, 37U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 26123U)) & S_BLOCK1], 10U) ^ RotL64(aOperationLaneA[((aIndex + 22653U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCarry, 47U)) ^ (RotL64(aPrevious, 60U) + RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterA = ((aWandererE + RotL64(aIngress, 11U)) + 8367680518550579791U) + RotL64(aNonceWordD, 29U);
            aOrbiterE = ((aWandererJ + RotL64(aCross, 19U)) + RotL64(aCarry, 47U)) + 11491674725611181241U;
            aOrbiterI = (aWandererG + RotL64(aScatter, 23U)) + 16673861720782164214U;
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 39U)) + 9786610124108350855U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = ((aWandererF + RotL64(aScatter, 5U)) + RotL64(aCarry, 29U)) + 5745080601557577637U;
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 58U)) + RotL64(aCarry, 57U)) + 1959402215131684684U;
            aOrbiterJ = (aWandererC + RotL64(aCross, 37U)) + 6121650036079196522U;
            aOrbiterB = (aWandererI + RotL64(aIngress, 29U)) + 12016309761037342392U;
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 21U)) + 5986936646177049603U) + RotL64(aNonceWordG, 5U);
            aOrbiterF = ((aWandererB + RotL64(aIngress, 34U)) + 1000367700904043468U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterC = (aWandererA + RotL64(aScatter, 53U)) + 17425288243569101032U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 4856917474950325209U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 16312111093223166419U;
            aOrbiterI = RotL64((aOrbiterI * 11046477664487805241U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 456110002032422270U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 11393724374787795662U;
            aOrbiterK = RotL64((aOrbiterK * 1176984359123668389U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 8378176867715697176U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 8086186452345234815U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8450438271765985235U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 8470349167474173245U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 2528229938740192694U;
            aOrbiterF = RotL64((aOrbiterF * 8717790851266520943U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 13247168811545753141U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 8745293957516815264U;
            aOrbiterA = RotL64((aOrbiterA * 14270617180621072619U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 6165915500564961987U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 12015407798844173213U;
            aOrbiterD = RotL64((aOrbiterD * 3913451986559154153U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 545006684939922156U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 16366753936267185001U;
            aOrbiterJ = RotL64((aOrbiterJ * 6495185976430013201U), 41U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterD) + 3097605623436091728U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1]) + RotL64(aNonceWordH, 15U);
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 15950167830259022926U;
            aOrbiterG = RotL64((aOrbiterG * 4415538963984293323U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 8356327899232213426U) + RotL64(aNonceWordB, 55U);
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 10183421678251169945U;
            aOrbiterC = RotL64((aOrbiterC * 9474380650337109299U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 16327340177970834683U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 7086901180933495535U;
            aOrbiterE = RotL64((aOrbiterE * 1276521829484494857U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 13421211370092080006U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 8367680518550579791U;
            aOrbiterH = RotL64((aOrbiterH * 12256662446176946163U), 27U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterJ, 41U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 13U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 19U));
            aIngress = aIngress + (RotL64(aOrbiterG, 29U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterA, 6U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterE, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aCross, 37U) + aOrbiterK) + RotL64(aOrbiterE, 34U)) + RotL64(aCarry, 39U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterG, 37U)) + aOrbiterI);
            aWandererH = aWandererH + (((RotL64(aIngress, 23U) + RotL64(aOrbiterC, 57U)) + aOrbiterB) + RotL64(aNonceWordE, 38U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterD, 29U)) + aOrbiterH) + RotL64(aNonceWordA, 13U));
            aWandererD = aWandererD + (((RotL64(aScatter, 44U) + RotL64(aOrbiterJ, 3U)) + aOrbiterK) + RotL64(aCarry, 53U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 19U) + aOrbiterC) + RotL64(aOrbiterF, 12U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 41U) + aOrbiterA) + RotL64(aOrbiterC, 53U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 5U) + aOrbiterA) + RotL64(aOrbiterI, 43U));
            aWandererG = aWandererG + (((RotL64(aIngress, 29U) + aOrbiterA) + RotL64(aOrbiterK, 47U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 52U) + aOrbiterA) + RotL64(aOrbiterH, 41U));
            aWandererF = aWandererF + (((RotL64(aCross, 57U) + aOrbiterD) + RotL64(aOrbiterC, 27U)) + aPhaseFWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererD, 24U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererC, 51U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 42U) ^ RotL64(aNonceWordE, 27U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 28233U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((aIndex + 30453U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 5U) ^ RotL64(aNonceWordG, 37U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31143U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneB[((aIndex + 31331U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 52U) + RotL64(aPrevious, 37U)) ^ (RotL64(aIngress, 23U) + RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 51U)) + 7825479804710770560U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterI = ((aWandererH + RotL64(aCross, 47U)) + 5298124167101358123U) + RotL64(aNonceWordC, 17U);
            aOrbiterB = ((aWandererD + RotL64(aScatter, 41U)) + RotL64(aCarry, 43U)) + 17774541024369233726U;
            aOrbiterA = (aWandererG + RotL64(aIngress, 57U)) + 7679371833537454082U;
            aOrbiterF = (aWandererF + RotL64(aScatter, 37U)) + 5385914900748772224U;
            aOrbiterE = ((aWandererE + RotL64(aCross, 6U)) + RotL64(aCarry, 35U)) + 3879781930908486531U;
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 43U)) + 659110346638873236U) + aPhaseFOrbiterAssignSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterG = (aWandererA + RotL64(aIngress, 35U)) + 10749021728538539749U;
            aOrbiterJ = (aWandererJ + RotL64(aScatter, 21U)) + 3631252455767429457U;
            aOrbiterC = ((aWandererI + RotL64(aIngress, 54U)) + 2271978810960685021U) + RotL64(aNonceWordG, 51U);
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 13U)) + RotL64(aCarry, 29U)) + 5963558780692551176U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 974909966119198104U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 9296998242911152296U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2613629915877957661U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 2245318466901521959U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 13391076374843288568U;
            aOrbiterF = RotL64((aOrbiterF * 18094558036982107419U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 6184487746594236737U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 1563385912137291418U) ^ RotL64(aNonceWordD, 60U);
            aOrbiterE = RotL64((aOrbiterE * 4805455299959232321U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 1744840092006498629U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 2100927276837188416U;
            aOrbiterH = RotL64((aOrbiterH * 3541788262067077997U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 9998911862807246338U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 12239948725635220096U;
            aOrbiterG = RotL64((aOrbiterG * 7098620484129489129U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 3307447094994950246U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 12746613971448298932U;
            aOrbiterJ = RotL64((aOrbiterJ * 9463975886346934681U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 11577488293733790649U) + RotL64(aNonceWordA, 29U);
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 191108997585598809U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9574978681405356871U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 18096145693841273722U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 10026281133603934071U;
            aOrbiterD = RotL64((aOrbiterD * 17261343107314203471U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 2346682418062064668U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 2996178204018644206U;
            aOrbiterK = RotL64((aOrbiterK * 2552965800703390909U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 15085425896818988223U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 1589593231782852588U;
            aOrbiterI = RotL64((aOrbiterI * 1535556765195388675U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 17170695588248383518U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 7825479804710770560U;
            aOrbiterA = RotL64((aOrbiterA * 7434218282170150533U), 23U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterI, 27U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 11U));
            aIngress = aIngress + (RotL64(aOrbiterB, 53U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterG, 35U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterD, 6U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterJ, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((((RotL64(aIngress, 5U) + aOrbiterH) + RotL64(aOrbiterG, 27U)) + RotL64(aNonceWordH, 59U)) + aPhaseFWandererUpdateSaltE[((aIndex + 22U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aCross, 13U) + RotL64(aOrbiterJ, 3U)) + aOrbiterE);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 26U) + RotL64(aOrbiterI, 47U)) + aOrbiterG);
            aWandererK = aWandererK + (((RotL64(aScatter, 57U) + aOrbiterF) + RotL64(aOrbiterB, 22U)) + RotL64(aCarry, 21U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterJ, 43U)) + aOrbiterA);
            aWandererI = aWandererI + ((RotL64(aCross, 37U) + aOrbiterK) + RotL64(aOrbiterF, 39U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterJ, 19U)) + aOrbiterK);
            aWandererE = aWandererE + (((RotL64(aScatter, 53U) + aOrbiterH) + RotL64(aOrbiterC, 13U)) + aPhaseFWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterJ, 41U)) + aOrbiterI) + RotL64(aNonceWordF, 25U));
            aWandererB = aWandererB + (((RotL64(aIngress, 18U) + RotL64(aOrbiterG, 35U)) + aOrbiterK) + RotL64(aCarry, 29U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 41U) + aOrbiterG) + RotL64(aOrbiterD, 10U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 30U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererH, 27U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 5U));
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererJ);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 14U));
            aCarry = aCarry + RotL64(aWandererA, 37U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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

void TwistExpander_Boxing_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 6261U)) & S_BLOCK1], 21U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 1965U)) & W_KEY1], 12U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 410U)) & W_KEY1], 48U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 7834U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 47U) + RotL64(aCross, 60U)) + (RotL64(aCarry, 35U) ^ RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = (aWandererA + RotL64(aPrevious, 27U)) + 18191288703716505885U;
            aOrbiterH = (aWandererJ + RotL64(aCross, 60U)) + 9824014524910417136U;
            aOrbiterC = (((aWandererH + RotL64(aScatter, 19U)) + RotL64(aCarry, 3U)) + 11953012029254917548U) + aPhaseCOrbiterAssignSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterE = (aWandererK + RotL64(aIngress, 5U)) + 6297568011027199089U;
            aOrbiterI = (aWandererG + RotL64(aCross, 39U)) + 2576999400457367975U;
            aOrbiterK = (aWandererE + RotL64(aScatter, 35U)) + 13176139160575558254U;
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 23U)) + RotL64(aCarry, 43U)) + 9978408174563621810U;
            aOrbiterB = ((aWandererF + RotL64(aIngress, 13U)) + RotL64(aCarry, 35U)) + 16765834875061607142U;
            aOrbiterA = ((aWandererD + RotL64(aCross, 44U)) + 16534507305459121344U) + aPhaseCOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 3114710944346151807U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 10240517868726718592U;
            aOrbiterC = RotL64((aOrbiterC * 4645691562915606463U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 10721450637990777883U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 16689590768796583952U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3046344179729901637U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 2427422768928450209U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 13495584061816457831U;
            aOrbiterB = RotL64((aOrbiterB * 6670984773768885119U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 7058636403765106682U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 9897341853944713767U;
            aOrbiterA = RotL64((aOrbiterA * 14286816859999869231U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 17749559755733386064U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 12515645083926326659U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6582878478865838245U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 2625692458813609962U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 10596240255026143019U;
            aOrbiterE = RotL64((aOrbiterE * 11605800195771080135U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 12374290338067865540U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 1507386663796330249U;
            aOrbiterG = RotL64((aOrbiterG * 1210241080424446087U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 9288099549484146726U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 15159312464747000702U;
            aOrbiterH = RotL64((aOrbiterH * 500055502081347757U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 14998608679505446229U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 17625038109437732009U;
            aOrbiterI = RotL64((aOrbiterI * 14785862243019841689U), 37U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterI, 53U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 46U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 11U));
            aIngress = aIngress + RotL64(aOrbiterG, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aCross, 19U) + RotL64(aOrbiterF, 44U)) + aOrbiterB);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 14U) + aOrbiterI) + RotL64(aOrbiterB, 3U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 51U) + aOrbiterC) + RotL64(aOrbiterF, 19U)) + RotL64(aCarry, 51U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 23U) + aOrbiterF) + RotL64(aOrbiterK, 27U)) + aPhaseCWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 57U) + RotL64(aOrbiterE, 23U)) + aOrbiterA);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 6U) + RotL64(aOrbiterB, 48U)) + aOrbiterE);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 29U) + RotL64(aOrbiterH, 39U)) + aOrbiterB) + RotL64(aCarry, 13U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterG, 11U)) + aOrbiterE) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 41U) + RotL64(aOrbiterG, 57U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 50U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + RotL64(aWandererF, 41U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 11506U)) & S_BLOCK1], 48U) ^ RotL64(mSource[((aIndex + 9679U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 10544U)) & W_KEY1], 27U) ^ RotL64(aKeyRowReadB[((aIndex + 11249U)) & W_KEY1], 54U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 29U)) + (RotL64(aCross, 41U) + RotL64(aIngress, 54U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = (aWandererK + RotL64(aScatter, 30U)) + 1898718075389870739U;
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 3U)) + RotL64(aCarry, 39U)) + 5631794889237247403U;
            aOrbiterB = (aWandererC + RotL64(aCross, 39U)) + 18219714659484524607U;
            aOrbiterH = ((aWandererF + RotL64(aIngress, 19U)) + RotL64(aCarry, 29U)) + 15419581386225732921U;
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 35U)) + 9125575431710198210U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = (aWandererE + RotL64(aCross, 57U)) + 12205871520544965505U;
            aOrbiterC = (aWandererJ + RotL64(aIngress, 11U)) + 7617534300497343422U;
            aOrbiterD = ((aWandererI + RotL64(aScatter, 26U)) + RotL64(aCarry, 13U)) + 18017579105368135814U;
            aOrbiterK = ((aWandererB + RotL64(aCross, 43U)) + 10693882161946020042U) + aPhaseCOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 11669615701700895306U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 11045110212889232165U;
            aOrbiterB = RotL64((aOrbiterB * 5965171269273719849U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 18019107802806469913U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 12315940560472528716U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4505122470351404065U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 4899009736070044310U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 17412253404253730364U;
            aOrbiterC = RotL64((aOrbiterC * 10791901166391946485U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 4826286251927854181U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 4523455921321845084U;
            aOrbiterD = RotL64((aOrbiterD * 14534103906736598099U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 4132514462154182215U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 7164745605985109269U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14107325508977225261U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 6297434295807635654U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 8813887638672996646U;
            aOrbiterG = RotL64((aOrbiterG * 17495632530773158201U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 11086381278955626084U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 5660733992573928887U;
            aOrbiterH = RotL64((aOrbiterH * 11248164458720777889U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 14851044686208609882U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 12707776386060264479U;
            aOrbiterI = RotL64((aOrbiterI * 4470919091467313071U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 11508023384209716657U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 11752973809740920034U;
            aOrbiterA = RotL64((aOrbiterA * 10212754472298834769U), 57U);
            //
            aIngress = RotL64(aOrbiterA, 28U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterC, 43U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + (RotL64(aOrbiterI, 23U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterB, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 36U) + aOrbiterB) + RotL64(aOrbiterI, 4U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterH, 53U)) + aPhaseCWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterA, 47U)) + aOrbiterK);
            aWandererF = aWandererF + ((RotL64(aIngress, 3U) + RotL64(aOrbiterK, 19U)) + aOrbiterI);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterI, 37U)) + aOrbiterD);
            aWandererI = aWandererI + ((((RotL64(aIngress, 47U) + RotL64(aOrbiterB, 23U)) + aOrbiterK) + RotL64(aCarry, 27U)) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 14U) + RotL64(aOrbiterI, 41U)) + aOrbiterE);
            aWandererE = aWandererE + (((RotL64(aCross, 41U) + aOrbiterE) + RotL64(aOrbiterH, 27U)) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterG, 12U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererI, 41U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererC, 35U);
            aCarry = aCarry + RotL64(aIngress, 22U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 20118U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 16615U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 19948U)) & W_KEY1], 39U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 18196U)) & W_KEY1], 4U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 3U) ^ RotL64(aPrevious, 18U)) ^ (RotL64(aCarry, 51U) + RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = ((aWandererE + RotL64(aIngress, 57U)) + RotL64(aCarry, 57U)) + 5510690816044082200U;
            aOrbiterK = (aWandererH + RotL64(aScatter, 53U)) + 15967820875033940530U;
            aOrbiterG = (aWandererG + RotL64(aPrevious, 14U)) + 539348720848176221U;
            aOrbiterJ = (((aWandererC + RotL64(aCross, 39U)) + RotL64(aCarry, 41U)) + 15779318183635560817U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = (aWandererB + RotL64(aPrevious, 47U)) + 14511058534424187469U;
            aOrbiterB = ((aWandererI + RotL64(aScatter, 35U)) + 5811130556873428391U) + aPhaseCOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = (aWandererF + RotL64(aIngress, 3U)) + 1085928476499444025U;
            aOrbiterH = (aWandererD + RotL64(aCross, 18U)) + 6973335316600768130U;
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 43U)) + RotL64(aCarry, 11U)) + 10747243745475009744U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 1072260008981349754U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 2018772405352495753U;
            aOrbiterG = RotL64((aOrbiterG * 10840562112080574241U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 1092091597048996547U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 15103140149542167197U;
            aOrbiterF = RotL64((aOrbiterF * 621856991658027989U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 13194619321108681542U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 16749188603268621850U;
            aOrbiterJ = RotL64((aOrbiterJ * 9575408950550922039U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 7427959503086895166U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 9895804051379551393U;
            aOrbiterK = RotL64((aOrbiterK * 2701997336201570715U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 4526020800679774259U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 4484850928870048176U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17556987520625677313U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 1837404844299040155U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 15213208978489570694U;
            aOrbiterB = RotL64((aOrbiterB * 7062740584650274133U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 9615231781751396800U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 15872192167825648096U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2900526493682580729U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 12530672039655918903U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 10617836782870315804U;
            aOrbiterH = RotL64((aOrbiterH * 9716778004909794973U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 550750725406860977U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 3498554352021622907U;
            aOrbiterD = RotL64((aOrbiterD * 9846933294851238495U), 43U);
            //
            aIngress = RotL64(aOrbiterK, 19U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 53U));
            aIngress = aIngress + (RotL64(aOrbiterF, 10U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 13U));
            aIngress = aIngress + RotL64(aOrbiterJ, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aCross, 29U) + RotL64(aOrbiterK, 19U)) + aOrbiterB) + RotL64(aCarry, 29U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterG, 4U)) + aOrbiterK) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aIngress, 53U) + aOrbiterJ) + RotL64(aOrbiterH, 57U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 60U) + aOrbiterA) + RotL64(aOrbiterK, 23U)) + aPhaseCWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterF, 53U)) + aOrbiterH);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterF, 48U)) + aOrbiterJ);
            aWandererB = aWandererB + ((RotL64(aCross, 43U) + aOrbiterD) + RotL64(aOrbiterB, 11U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 48U) + RotL64(aOrbiterC, 43U)) + aOrbiterK);
            aWandererF = aWandererF + (((RotL64(aPrevious, 13U) + aOrbiterC) + RotL64(aOrbiterJ, 37U)) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererB);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 60U));
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererD, 5U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 29913U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneB[((aIndex + 32497U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32749U)) & S_BLOCK1], 35U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 31134U)) & S_BLOCK1], 22U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 19U) ^ RotL64(aCarry, 57U)) ^ (RotL64(aCross, 38U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = (aWandererH + RotL64(aPrevious, 56U)) + 7896237440058555694U;
            aOrbiterA = (((aWandererC + RotL64(aCross, 29U)) + RotL64(aCarry, 43U)) + 11870529476037558635U) + aPhaseCOrbiterAssignSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = ((aWandererD + RotL64(aIngress, 13U)) + RotL64(aCarry, 13U)) + 9158983227801569448U;
            aOrbiterC = ((aWandererF + RotL64(aScatter, 5U)) + 4710172270996950329U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = (aWandererA + RotL64(aCross, 39U)) + 14634482800356647630U;
            aOrbiterF = (aWandererI + RotL64(aPrevious, 23U)) + 8822207952170610891U;
            aOrbiterB = ((aWandererK + RotL64(aScatter, 19U)) + RotL64(aCarry, 35U)) + 13755891414028982553U;
            aOrbiterJ = (aWandererE + RotL64(aIngress, 35U)) + 4555293067488040719U;
            aOrbiterG = (aWandererG + RotL64(aCross, 52U)) + 2816805148093762081U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 2122631477965135190U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 4592922416380416071U;
            aOrbiterI = RotL64((aOrbiterI * 11644507904538573165U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 7102471666524164715U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 17274623547879474204U;
            aOrbiterD = RotL64((aOrbiterD * 5443572270546181789U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 938587316977094680U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 18258015823797023523U;
            aOrbiterB = RotL64((aOrbiterB * 6068819567674605919U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 5809987756043471595U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 5083075160112581620U;
            aOrbiterH = RotL64((aOrbiterH * 3313957222154937503U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 5960021727750946496U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 5967477320950630150U;
            aOrbiterC = RotL64((aOrbiterC * 330964768256424655U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 6578428711689296132U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 5601728218197771276U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9552559022315971847U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 7923809409017855241U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 16479366540906497019U;
            aOrbiterJ = RotL64((aOrbiterJ * 7118578387798460919U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 17000467091738009736U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 6801634573655508028U;
            aOrbiterG = RotL64((aOrbiterG * 10584635770060137089U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 123668445682719574U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 14462802805503986316U;
            aOrbiterA = RotL64((aOrbiterA * 12398236364304875941U), 5U);
            //
            aIngress = RotL64(aOrbiterC, 6U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterF, 35U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 19U));
            aIngress = aIngress + (RotL64(aOrbiterI, 47U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterA, 14U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aCross, 23U) + RotL64(aOrbiterC, 23U)) + aOrbiterF);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 43U) + aOrbiterD) + RotL64(aOrbiterF, 39U)) + aPhaseCWandererUpdateSaltA[((aIndex + 16U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aPrevious, 12U) + aOrbiterI) + RotL64(aOrbiterJ, 57U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 39U) + aOrbiterI) + RotL64(aOrbiterF, 19U)) + aPhaseCWandererUpdateSaltD[((aIndex + 15U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterI, 10U)) + aOrbiterA) + RotL64(aCarry, 21U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 57U) + aOrbiterB) + RotL64(aOrbiterH, 3U));
            aWandererG = aWandererG + (((RotL64(aScatter, 34U) + RotL64(aOrbiterB, 53U)) + aOrbiterJ) + RotL64(aCarry, 53U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterD, 43U)) + aOrbiterG);
            aWandererH = aWandererH + ((RotL64(aPrevious, 27U) + aOrbiterG) + RotL64(aOrbiterH, 48U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 26U));
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererK, 29U);
            aCarry = aCarry + RotL64(aIngress, 10U);
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

void TwistExpander_Boxing_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 772U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneC[((aIndex + 3880U)) & S_BLOCK1], 10U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2409U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneA[((aIndex + 8070U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 10U) + RotL64(aIngress, 23U)) ^ (RotL64(aPrevious, 39U) ^ RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = (((aWandererA + RotL64(aIngress, 13U)) + RotL64(aCarry, 5U)) + 3236820517816085022U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = (aWandererE + RotL64(aCross, 23U)) + 741288875914097926U;
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 51U)) + 8417246926007729580U) + aPhaseDOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = ((aWandererH + RotL64(aScatter, 40U)) + RotL64(aCarry, 27U)) + 9715717805774537170U;
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 5U)) + RotL64(aCarry, 43U)) + 14360243844821619482U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 10760908100206775334U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 3434641779946167811U;
            aOrbiterD = RotL64((aOrbiterD * 3305698324169010803U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 7885568822756234567U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 3041563437672051294U;
            aOrbiterA = RotL64((aOrbiterA * 11440300917533482297U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 15761355327564963516U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 1158633562785937421U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15511324886867188235U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 9338581575871970653U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 9172038894262857354U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3110871165285625807U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 14653924713599790081U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 3854497592598563309U;
            aOrbiterK = RotL64((aOrbiterK * 11737111068815795303U), 21U);
            //
            aIngress = RotL64(aOrbiterK, 29U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterE, 14U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterD, 3U)) + aOrbiterK);
            aWandererE = aWandererE + ((((RotL64(aScatter, 43U) + RotL64(aOrbiterA, 14U)) + aOrbiterK) + RotL64(aCarry, 11U)) + aPhaseDWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterE, 35U)) + aOrbiterK) + aPhaseDWandererUpdateSaltC[((aIndex + 20U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 22U) + aOrbiterA) + RotL64(aOrbiterD, 43U)) + RotL64(aCarry, 41U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 13U) + aOrbiterA) + RotL64(aOrbiterG, 53U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + RotL64(aWandererC, 37U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 9246U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 13262U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 10424U)) & S_BLOCK1], 36U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 10071U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aIngress, 51U)) + (RotL64(aPrevious, 39U) ^ RotL64(aCross, 22U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 5U)) + RotL64(aCarry, 3U)) + 13053031069776604052U;
            aOrbiterB = (((aWandererE + RotL64(aCross, 54U)) + RotL64(aCarry, 51U)) + 1331396630251085122U) + aPhaseDOrbiterAssignSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterF = ((aWandererK + RotL64(aIngress, 13U)) + 15879286043343942393U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = ((aWandererD + RotL64(aScatter, 21U)) + RotL64(aCarry, 37U)) + 13590365633321406830U;
            aOrbiterA = (aWandererF + RotL64(aPrevious, 29U)) + 14569235423040242618U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 11397370636618371560U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 3455933494593971847U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13051161161405358793U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 1307153376443784593U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 10688618762584786871U;
            aOrbiterA = RotL64((aOrbiterA * 9503823896874842411U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 17746248451153600096U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 8512568600755410158U;
            aOrbiterK = RotL64((aOrbiterK * 16648320170768234063U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 8950230550112591092U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 17790968369472845496U;
            aOrbiterB = RotL64((aOrbiterB * 5104988920132008913U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 12583323865381967534U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 11243927099685293887U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12867003042486433971U), 43U);
            //
            aIngress = RotL64(aOrbiterB, 37U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterH, 54U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aIngress, 3U) + aOrbiterH) + RotL64(aOrbiterB, 21U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 21U) + aOrbiterH) + RotL64(aOrbiterK, 29U)) + aPhaseDWandererUpdateSaltD[((aIndex + 18U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 29U) + aOrbiterF) + RotL64(aOrbiterH, 3U)) + RotL64(aCarry, 43U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterA, 44U)) + aOrbiterK) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 58U) + RotL64(aOrbiterF, 11U)) + aOrbiterA) + RotL64(aCarry, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererK, 41U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererI, 5U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 23459U)) & S_BLOCK1], 28U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 22756U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 21616U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneC[((aIndex + 17227U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 40U) ^ RotL64(aIngress, 57U)) + (RotL64(aPrevious, 5U) + RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = ((aWandererF + RotL64(aCross, 39U)) + RotL64(aCarry, 41U)) + 3248574644570178787U;
            aOrbiterA = (((aWandererB + RotL64(aPrevious, 13U)) + RotL64(aCarry, 5U)) + 4506961512959200024U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterG = (aWandererH + RotL64(aIngress, 47U)) + 8423739774540738590U;
            aOrbiterE = ((aWandererI + RotL64(aScatter, 27U)) + RotL64(aCarry, 21U)) + 6593975869641735337U;
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 4U)) + 16441716090557369103U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 7936601450453207914U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 13333752583560167065U;
            aOrbiterG = RotL64((aOrbiterG * 5389149472324384311U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 8013703284795432973U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 2349852779887439236U;
            aOrbiterA = RotL64((aOrbiterA * 2422888500648100783U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 5318539364763284138U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 11450957608502944376U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1957880366707810635U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 9058992558327552687U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 632095686920230926U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12460364388358520799U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 14734218428913777098U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 16344357661370784442U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15049472842002138369U), 13U);
            //
            aIngress = RotL64(aOrbiterA, 27U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 53U));
            aIngress = aIngress + RotL64(aOrbiterG, 38U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aScatter, 11U) + aOrbiterE) + RotL64(aOrbiterD, 51U)) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterF, 29U)) + aOrbiterE);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterA, 41U)) + aOrbiterG) + RotL64(aCarry, 11U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 19U) + aOrbiterE) + RotL64(aOrbiterG, 13U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 38U) + aOrbiterF) + RotL64(aOrbiterG, 4U)) + aPhaseDWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 30U));
            aCarry = aCarry + (RotL64(aWandererB, 21U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererJ, 41U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 27853U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((aIndex + 28489U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 30250U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneD[((aIndex + 27027U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 60U) + RotL64(aIngress, 47U)) ^ (RotL64(aCarry, 13U) + RotL64(aPrevious, 29U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = (((aWandererD + RotL64(aCross, 3U)) + RotL64(aCarry, 5U)) + 4739486756133131180U) + aPhaseDOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = ((aWandererC + RotL64(aIngress, 26U)) + RotL64(aCarry, 53U)) + 16089707555501328184U;
            aOrbiterH = (aWandererE + RotL64(aPrevious, 57U)) + 15310047330238536453U;
            aOrbiterI = (((aWandererH + RotL64(aScatter, 13U)) + RotL64(aCarry, 21U)) + 7901411596386834955U) + aPhaseDOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = (aWandererI + RotL64(aPrevious, 39U)) + 4357555491060982163U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 15667085602825720102U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 8520635334382269253U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7348648918661047791U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 1772509779231068315U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 15336170957886025677U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10996880551392077399U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 8628770833489469980U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 15469234024247246228U;
            aOrbiterI = RotL64((aOrbiterI * 8905266995119987947U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 10796430900884288328U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 10660110397012853289U;
            aOrbiterF = RotL64((aOrbiterF * 9140007610912037461U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 11202284258711214794U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 17509491802893182994U;
            aOrbiterG = RotL64((aOrbiterG * 9329107599972703671U), 3U);
            //
            aIngress = RotL64(aOrbiterF, 54U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 5U));
            aIngress = aIngress + RotL64(aOrbiterI, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aPrevious, 44U) + aOrbiterI) + RotL64(aOrbiterH, 53U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterA, 42U)) + aOrbiterF);
            aWandererC = aWandererC + (((RotL64(aIngress, 53U) + aOrbiterI) + RotL64(aOrbiterA, 27U)) + RotL64(aCarry, 3U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 5U) + aOrbiterF) + RotL64(aOrbiterH, 13U)) + aPhaseDWandererUpdateSaltA[((aIndex + 18U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 23U) + RotL64(aOrbiterG, 5U)) + aOrbiterI) + RotL64(aCarry, 37U)) + aPhaseDWandererUpdateSaltC[((aIndex + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + RotL64(aWandererE, 24U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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

void TwistExpander_Boxing_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 3309U)) & S_BLOCK1], 50U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 8160U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 6041U)) & S_BLOCK1], 22U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 5731U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 21U) ^ RotL64(aIngress, 52U)) ^ (RotL64(aCross, 39U) + RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 43U)) + RotL64(aCarry, 57U)) + 6163290588946759209U;
            aOrbiterG = (aWandererC + RotL64(aIngress, 52U)) + 7342672468560105447U;
            aOrbiterB = (aWandererA + RotL64(aScatter, 35U)) + 11574563167017282321U;
            aOrbiterK = (((aWandererB + RotL64(aCross, 11U)) + RotL64(aCarry, 29U)) + 2254820206194758964U) + aPhaseEOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = (((aWandererF + RotL64(aScatter, 21U)) + RotL64(aCarry, 43U)) + 1469783447473099498U) + aPhaseEOrbiterAssignSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = (aWandererG + RotL64(aIngress, 3U)) + 14174828900676165088U;
            aOrbiterI = (aWandererD + RotL64(aCross, 27U)) + 16277954291890598132U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 14845750668693136766U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 150099699692047766U;
            aOrbiterB = RotL64((aOrbiterB * 7644895634421086357U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 1200784917165131703U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 9469982764806754302U;
            aOrbiterA = RotL64((aOrbiterA * 17851969334511301943U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 10956702761701710182U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 7915506894975487807U;
            aOrbiterJ = RotL64((aOrbiterJ * 8874108311712727983U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 17335794183733623213U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 557028996286989506U;
            aOrbiterI = RotL64((aOrbiterI * 3993359298602424281U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 1597385667771002414U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 4376417959915162639U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4626236858205178149U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 549770198518993876U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 756554555648070919U;
            aOrbiterK = RotL64((aOrbiterK * 16272320259614325355U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 7298557532533152193U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 3336802611342112013U;
            aOrbiterG = RotL64((aOrbiterG * 14679103452120080499U), 23U);
            //
            aIngress = RotL64(aOrbiterI, 5U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 58U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 29U));
            aIngress = aIngress + RotL64(aOrbiterA, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterI, 21U)) + aOrbiterE);
            aWandererD = aWandererD + (((RotL64(aPrevious, 43U) + aOrbiterE) + RotL64(aOrbiterA, 35U)) + aPhaseEWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 29U) + aOrbiterJ) + RotL64(aOrbiterE, 29U));
            aWandererA = aWandererA + (((RotL64(aIngress, 23U) + aOrbiterK) + RotL64(aOrbiterJ, 13U)) + RotL64(aCarry, 11U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 36U) + aOrbiterG) + RotL64(aOrbiterI, 43U));
            aWandererH = aWandererH + (((RotL64(aCross, 3U) + aOrbiterE) + RotL64(aOrbiterB, 50U)) + RotL64(aCarry, 27U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterB, 57U)) + aOrbiterK) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererG);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 44U));
            aCarry = aCarry + RotL64(aWandererB, 19U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 13543U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 8555U)) & S_BLOCK1], 10U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 10286U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((aIndex + 11684U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aPrevious, 41U)) ^ (RotL64(aIngress, 22U) ^ RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 29U)) + RotL64(aCarry, 27U)) + 5295352595333316211U;
            aOrbiterG = (aWandererK + RotL64(aScatter, 58U)) + 2341795367042042605U;
            aOrbiterC = (aWandererA + RotL64(aIngress, 3U)) + 10122175780504033663U;
            aOrbiterB = (aWandererE + RotL64(aCross, 21U)) + 10084612804696198554U;
            aOrbiterD = (((aWandererF + RotL64(aIngress, 35U)) + RotL64(aCarry, 39U)) + 16470424309851045971U) + aPhaseEOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = ((aWandererH + RotL64(aScatter, 47U)) + RotL64(aCarry, 51U)) + 656016130975227994U;
            aOrbiterJ = ((aWandererC + RotL64(aCross, 13U)) + 15313268829659834317U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 3795220914993923394U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 14044442220988813825U;
            aOrbiterC = RotL64((aOrbiterC * 3270650852546606835U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 3804224626734584802U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 7980006306010255693U;
            aOrbiterA = RotL64((aOrbiterA * 13958505239726088561U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 13746830564584711549U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 11852212099729274845U;
            aOrbiterB = RotL64((aOrbiterB * 2164880979318247855U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 9083223471018084847U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 13706723820703853346U;
            aOrbiterG = RotL64((aOrbiterG * 11361854103656219887U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 1713819986642275223U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 1382000168233902914U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3894160765130198157U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 4540474625764565485U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 1756168174375757220U;
            aOrbiterK = RotL64((aOrbiterK * 12739160208010092017U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 1409297070183609309U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 6082750101445444357U;
            aOrbiterJ = RotL64((aOrbiterJ * 17438740230251860935U), 11U);
            //
            aIngress = RotL64(aOrbiterD, 58U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + (RotL64(aOrbiterB, 21U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterJ, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aIngress, 11U) + aOrbiterD) + RotL64(aOrbiterK, 60U));
            aWandererE = aWandererE + ((((RotL64(aCross, 29U) + RotL64(aOrbiterG, 43U)) + aOrbiterD) + RotL64(aCarry, 21U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 20U) + RotL64(aOrbiterC, 27U)) + aOrbiterB);
            aWandererA = aWandererA + (((RotL64(aScatter, 43U) + aOrbiterD) + RotL64(aOrbiterB, 51U)) + RotL64(aCarry, 57U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterA, 35U)) + aOrbiterB);
            aWandererC = aWandererC + (((RotL64(aIngress, 35U) + RotL64(aOrbiterG, 3U)) + aOrbiterB) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterC, 13U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererC, 56U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererE);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + RotL64(aWandererF, 27U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 18221U)) & S_BLOCK1], 44U) ^ RotL64(aWorkLaneA[((aIndex + 23894U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 16666U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneC[((aIndex + 22496U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCross, 3U)) ^ (RotL64(aCarry, 40U) + RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = ((aWandererA + RotL64(aCross, 51U)) + 14624277139785904404U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterG = (((aWandererC + RotL64(aIngress, 43U)) + RotL64(aCarry, 21U)) + 6966977309498165611U) + aPhaseEOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = (aWandererE + RotL64(aScatter, 57U)) + 205536824352530761U;
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 27U)) + RotL64(aCarry, 47U)) + 16629575265808255692U;
            aOrbiterB = ((aWandererI + RotL64(aCross, 37U)) + RotL64(aCarry, 3U)) + 596881340147972746U;
            aOrbiterE = (aWandererD + RotL64(aScatter, 12U)) + 11944412799107412650U;
            aOrbiterD = (aWandererH + RotL64(aPrevious, 21U)) + 4615021315668210206U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 8497630055977606216U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 11131601107309336885U;
            aOrbiterJ = RotL64((aOrbiterJ * 18028349768453554935U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 5935883479805510099U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 15629346719765798174U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8535523790685945275U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 5279128339113651273U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 16778365912440331821U;
            aOrbiterF = RotL64((aOrbiterF * 705421028266789241U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 16003052937645491524U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 6723226158737614764U;
            aOrbiterA = RotL64((aOrbiterA * 16690657664909260573U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 9785784358981219543U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 10055457337292292710U;
            aOrbiterB = RotL64((aOrbiterB * 17919129940751761111U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 11779163108592974175U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 1177999477942202687U;
            aOrbiterE = RotL64((aOrbiterE * 13475069421684114643U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 9190694445141492214U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 15605342360346353457U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14547769706392595647U), 13U);
            //
            aIngress = RotL64(aOrbiterB, 13U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + RotL64(aOrbiterD, 34U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aPrevious, 43U) + aOrbiterG) + RotL64(aOrbiterA, 35U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterB, 19U)) + aOrbiterE) + aPhaseEWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 13U) + aOrbiterJ) + RotL64(aOrbiterF, 46U)) + aPhaseEWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 57U) + aOrbiterJ) + RotL64(aOrbiterA, 57U));
            aWandererH = aWandererH + (((RotL64(aIngress, 37U) + RotL64(aOrbiterE, 13U)) + aOrbiterJ) + RotL64(aCarry, 23U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 4U) + aOrbiterF) + RotL64(aOrbiterG, 29U));
            aWandererA = aWandererA + (((RotL64(aScatter, 27U) + aOrbiterD) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 60U) ^ aWandererF);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererC, 21U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 31918U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26133U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 32765U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneD[((aIndex + 30713U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 37U) ^ RotL64(aCross, 53U)) + (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 22U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 27U)) + 4751694786009671052U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = (aWandererE + RotL64(aIngress, 19U)) + 16362725160370844224U;
            aOrbiterD = (aWandererB + RotL64(aScatter, 48U)) + 6360885380915941057U;
            aOrbiterE = ((aWandererC + RotL64(aCross, 5U)) + RotL64(aCarry, 3U)) + 5154536007972297036U;
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 13U)) + RotL64(aCarry, 19U)) + 9362540581874808253U;
            aOrbiterG = ((aWandererK + RotL64(aScatter, 41U)) + 13902493871525612934U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = ((aWandererD + RotL64(aIngress, 57U)) + RotL64(aCarry, 43U)) + 10208452885367546542U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 3117030377279160998U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 17286247690414027870U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4896931759653832095U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 3930314320040949141U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 7289525252391668404U;
            aOrbiterG = RotL64((aOrbiterG * 15452162299105112187U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 3434167955466809185U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 17852573095128575663U;
            aOrbiterJ = RotL64((aOrbiterJ * 1485660158767033425U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 6137259687928853253U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 13992510605237574698U;
            aOrbiterH = RotL64((aOrbiterH * 15346263295995333395U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 6470556523400123474U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 4333255670390099293U;
            aOrbiterF = RotL64((aOrbiterF * 11089933812030082647U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 7700424876430257995U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 16920736951239453071U;
            aOrbiterE = RotL64((aOrbiterE * 8920407493132380497U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 1635071690430295730U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 9966700845966398620U;
            aOrbiterK = RotL64((aOrbiterK * 17210048121896546867U), 51U);
            //
            aIngress = RotL64(aOrbiterK, 51U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 28U));
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterG, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aPrevious, 40U) + RotL64(aOrbiterH, 21U)) + aOrbiterD) + RotL64(aCarry, 43U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterG, 11U)) + aOrbiterH);
            aWandererB = aWandererB + (((RotL64(aCross, 5U) + aOrbiterK) + RotL64(aOrbiterJ, 29U)) + RotL64(aCarry, 27U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterK, 39U)) + aOrbiterH);
            aWandererF = aWandererF + ((RotL64(aPrevious, 19U) + aOrbiterK) + RotL64(aOrbiterG, 3U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 27U) + aOrbiterG) + RotL64(aOrbiterF, 54U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 53U) + RotL64(aOrbiterE, 47U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + (RotL64(aWandererK, 46U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 41U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererA, 57U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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

void TwistExpander_Boxing_Arx::Twist_D(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 279U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneC[((aIndex + 543U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4790U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneA[((aIndex + 1071U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 43U) ^ RotL64(aCross, 11U)) + (RotL64(aCarry, 56U) ^ RotL64(aPrevious, 29U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 43U)) + 15904465836916519864U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = (((aWandererA + RotL64(aCross, 5U)) + RotL64(aCarry, 29U)) + 17725629806317789307U) + aPhaseFOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = ((aWandererE + RotL64(aIngress, 27U)) + RotL64(aCarry, 51U)) + 13794170125914914828U;
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 57U)) + RotL64(aCarry, 13U)) + 2149055907476874332U;
            aOrbiterK = (aWandererD + RotL64(aScatter, 14U)) + 5342047776745074649U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 8268148484060546838U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 10821151364028563719U;
            aOrbiterA = RotL64((aOrbiterA * 13626634259250509711U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 4294213820894407378U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 10884726101307943090U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1116128870387229159U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 16432210042202444824U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 15196602644336228055U;
            aOrbiterF = RotL64((aOrbiterF * 12680438355124070237U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 14117787670220328165U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 219833877949480215U;
            aOrbiterE = RotL64((aOrbiterE * 10736293047771972173U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 3326396981881473962U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 14918513066311426279U;
            aOrbiterK = RotL64((aOrbiterK * 14269763278564574663U), 39U);
            //
            aIngress = RotL64(aOrbiterF, 51U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterB, 39U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterK, 14U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aPrevious, 4U) + aOrbiterA) + RotL64(aOrbiterK, 3U)) + RotL64(aCarry, 21U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 19U) + aOrbiterE) + RotL64(aOrbiterF, 57U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 39U) + aOrbiterF) + RotL64(aOrbiterB, 21U)) + RotL64(aCarry, 37U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 27U) + aOrbiterK) + RotL64(aOrbiterE, 12U));
            aWandererD = aWandererD + (((RotL64(aIngress, 53U) + RotL64(aOrbiterA, 39U)) + aOrbiterB) + aPhaseFWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererJ);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + RotL64(aWandererA, 21U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 13982U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 8631U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 12290U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((aIndex + 13395U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 24U) + RotL64(aIngress, 57U)) + (RotL64(aCarry, 43U) ^ RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = (((aWandererA + RotL64(aPrevious, 57U)) + RotL64(aCarry, 3U)) + 13481227414590594621U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterE = ((aWandererH + RotL64(aIngress, 36U)) + RotL64(aCarry, 47U)) + 17425964381118918026U;
            aOrbiterJ = (aWandererC + RotL64(aScatter, 27U)) + 4792004356135956581U;
            aOrbiterF = ((aWandererE + RotL64(aCross, 19U)) + RotL64(aCarry, 21U)) + 11926849936000639098U;
            aOrbiterH = ((aWandererK + RotL64(aIngress, 11U)) + 990697329347742142U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 9307721505373076588U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 17605732738841908719U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13123627214143336281U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 13110764518634187439U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 17970109897810645911U;
            aOrbiterH = RotL64((aOrbiterH * 10395095143998920213U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 10273133817644703654U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 11239046688920468137U;
            aOrbiterG = RotL64((aOrbiterG * 5197802934333553327U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 8355821483275763145U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 15522151127786049345U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4844278537850520413U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 5381663179722418112U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 9551368011768104906U;
            aOrbiterF = RotL64((aOrbiterF * 14202470972121732997U), 19U);
            //
            aIngress = RotL64(aOrbiterE, 37U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterG, 27U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterJ, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterF, 54U)) + aOrbiterE) + aPhaseFWandererUpdateSaltE[((aIndex + 8U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 29U) + aOrbiterH) + RotL64(aOrbiterJ, 13U)) + RotL64(aCarry, 11U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterE, 37U)) + aOrbiterG) + aPhaseFWandererUpdateSaltA[((aIndex + 26U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 58U) + RotL64(aOrbiterH, 3U)) + aOrbiterG) + RotL64(aCarry, 43U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterJ, 29U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererC, 5U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 18295U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22573U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 20167U)) & S_BLOCK1], 42U) ^ RotL64(aExpandLaneC[((aIndex + 18610U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 54U) + RotL64(aPrevious, 11U)) ^ (RotL64(aCarry, 23U) ^ RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = (aWandererK + RotL64(aScatter, 22U)) + 6771552164800695068U;
            aOrbiterD = (aWandererH + RotL64(aPrevious, 13U)) + 12131763371571322040U;
            aOrbiterI = (((aWandererB + RotL64(aIngress, 57U)) + RotL64(aCarry, 57U)) + 3326182381395522013U) + aPhaseFOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = (((aWandererI + RotL64(aCross, 39U)) + RotL64(aCarry, 23U)) + 12288775097697156383U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 47U)) + RotL64(aCarry, 43U)) + 5195948373449796741U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 14404044002250137144U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 11142382920035825426U;
            aOrbiterI = RotL64((aOrbiterI * 8134413822789107595U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 2967149520256475485U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 1470907369577818097U;
            aOrbiterD = RotL64((aOrbiterD * 9398653295177725883U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 9231668148004163910U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 13078929163913892386U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7509829068700523627U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 9485274692075657877U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 12216951187543631673U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6571066246507310805U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 6933334652581744234U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 17260276102423580920U;
            aOrbiterH = RotL64((aOrbiterH * 7796879893790990605U), 27U);
            //
            aIngress = RotL64(aOrbiterG, 30U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterI, 5U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterH, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterH, 3U)) + aOrbiterI);
            aWandererI = aWandererI + ((((RotL64(aIngress, 11U) + RotL64(aOrbiterG, 34U)) + aOrbiterH) + RotL64(aCarry, 19U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 29U) + aOrbiterG) + RotL64(aOrbiterB, 13U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 21U) + RotL64(aOrbiterI, 21U)) + aOrbiterD) + RotL64(aCarry, 53U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 60U) + RotL64(aOrbiterG, 53U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererI, 11U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 30542U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32585U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 29300U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneD[((aIndex + 24798U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCross, 39U)) ^ (RotL64(aCarry, 24U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = (((aWandererF + RotL64(aIngress, 43U)) + RotL64(aCarry, 57U)) + 380024772508948442U) + aPhaseFOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterC = ((aWandererH + RotL64(aCross, 35U)) + 7649029098162567210U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = ((aWandererC + RotL64(aScatter, 57U)) + RotL64(aCarry, 5U)) + 5329304598870421851U;
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 3U)) + RotL64(aCarry, 43U)) + 12306118665045151326U;
            aOrbiterJ = (aWandererI + RotL64(aIngress, 26U)) + 960751560457324256U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 3244070254386191876U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 15733408571609521746U;
            aOrbiterE = RotL64((aOrbiterE * 11280008313548121407U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 17623448932647018544U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 8787759896149035829U;
            aOrbiterI = RotL64((aOrbiterI * 7092515868845497573U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 14741681792348288162U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 8801731213568307302U;
            aOrbiterH = RotL64((aOrbiterH * 12127126999570616489U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 9872248187499779222U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 15407371518644528235U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1245102406469471673U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 4242060317152943062U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 9942784962409917541U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 888649755587764533U), 3U);
            //
            aIngress = RotL64(aOrbiterJ, 57U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 34U));
            aIngress = aIngress + RotL64(aOrbiterC, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aScatter, 3U) + aOrbiterJ) + RotL64(aOrbiterH, 19U));
            aWandererH = aWandererH + ((((RotL64(aIngress, 11U) + RotL64(aOrbiterI, 47U)) + aOrbiterJ) + RotL64(aCarry, 47U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 54U) + aOrbiterC) + RotL64(aOrbiterI, 11U));
            aWandererA = aWandererA + ((((RotL64(aPrevious, 39U) + RotL64(aOrbiterC, 56U)) + aOrbiterE) + RotL64(aCarry, 29U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterI, 3U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + (RotL64(aWandererC, 46U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererF, 23U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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

void TwistExpander_Boxing_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 7407U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneB[((aIndex + 4433U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 4522U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 6978U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 3U) ^ RotL64(aPrevious, 53U)) ^ (RotL64(aIngress, 38U) + RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = ((aWandererF + RotL64(aIngress, 35U)) + RotL64(aCarry, 53U)) + 4751694786009671052U;
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 44U)) + RotL64(aCarry, 23U)) + 16362725160370844224U;
            aOrbiterC = ((aWandererC + RotL64(aScatter, 21U)) + 6360885380915941057U) + aPhaseGOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = ((aWandererB + RotL64(aCross, 11U)) + RotL64(aCarry, 39U)) + 5154536007972297036U;
            aOrbiterB = ((aWandererD + RotL64(aScatter, 57U)) + 9362540581874808253U) + aPhaseGOrbiterAssignSaltD[((aIndex + 6U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 13902493871525612934U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 10208452885367546542U;
            aOrbiterC = RotL64((aOrbiterC * 12067703239567933105U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 3117030377279160998U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 17286247690414027870U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4896931759653832095U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 3930314320040949141U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 7289525252391668404U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15452162299105112187U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 3434167955466809185U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 17852573095128575663U;
            aOrbiterK = RotL64((aOrbiterK * 1485660158767033425U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 6137259687928853253U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 13992510605237574698U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15346263295995333395U), 23U);
            //
            aIngress = RotL64(aOrbiterB, 47U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterK, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 60U) + aOrbiterK) + RotL64(aOrbiterB, 5U));
            aWandererD = aWandererD + (((RotL64(aScatter, 21U) + RotL64(aOrbiterC, 60U)) + aOrbiterB) + RotL64(aCarry, 19U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 13U) + aOrbiterE) + RotL64(aOrbiterC, 43U));
            aWandererB = aWandererB + ((((RotL64(aIngress, 51U) + RotL64(aOrbiterE, 35U)) + aOrbiterG) + RotL64(aCarry, 57U)) + aPhaseGWandererUpdateSaltC[((aIndex + 8U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 43U) + aOrbiterG) + RotL64(aOrbiterK, 23U)) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 56U));
            aCarry = aCarry + RotL64(aWandererC, 3U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 10023U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneC[((aIndex + 13498U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 16134U)) & S_BLOCK1], 18U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 13130U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCarry, 20U)) + (RotL64(aCross, 35U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = ((aWandererE + RotL64(aIngress, 58U)) + 4752759164691497960U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = ((aWandererC + RotL64(aScatter, 13U)) + RotL64(aCarry, 19U)) + 12088872623537639782U;
            aOrbiterH = ((aWandererD + RotL64(aCross, 21U)) + RotL64(aCarry, 41U)) + 3734943577379734227U;
            aOrbiterC = (((aWandererJ + RotL64(aPrevious, 37U)) + RotL64(aCarry, 53U)) + 8854778183012444234U) + aPhaseGOrbiterAssignSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = (aWandererF + RotL64(aScatter, 29U)) + 16948373492893967275U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 7962415690046184385U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 1872682375669714454U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 959061892772099785U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 7776801806943853566U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 16665439117257230732U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6866375628213114965U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 11088186766134265676U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 10850237991780969350U;
            aOrbiterD = RotL64((aOrbiterD * 7547414856143095121U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 6464817712131305812U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 244557182884209844U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2394270354887582889U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 13261563971157415841U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 2323811103717827362U;
            aOrbiterC = RotL64((aOrbiterC * 11483723582415081925U), 27U);
            //
            aIngress = RotL64(aOrbiterK, 13U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 43U));
            aIngress = aIngress + RotL64(aOrbiterH, 28U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aCross, 47U) + RotL64(aOrbiterH, 47U)) + aOrbiterK) + aPhaseGWandererUpdateSaltE[((aIndex + 28U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 11U) + aOrbiterB) + RotL64(aOrbiterD, 57U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 35U) + aOrbiterH) + RotL64(aOrbiterC, 3U)) + RotL64(aCarry, 21U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterC, 26U)) + aOrbiterD);
            aWandererC = aWandererC + ((((RotL64(aCross, 60U) + aOrbiterB) + RotL64(aOrbiterH, 11U)) + RotL64(aCarry, 53U)) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 19U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 53U));
            aCarry = aCarry + RotL64(aWandererJ, 44U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 16586U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneD[((aIndex + 23105U)) & S_BLOCK1], 42U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 20094U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneB[((aIndex + 22966U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 19U) ^ RotL64(aIngress, 3U)) + (RotL64(aCarry, 54U) ^ RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = ((aWandererB + RotL64(aIngress, 35U)) + RotL64(aCarry, 23U)) + 15652862298542575895U;
            aOrbiterI = (((aWandererD + RotL64(aScatter, 3U)) + RotL64(aCarry, 5U)) + 16925323928418184554U) + aPhaseGOrbiterAssignSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = (aWandererF + RotL64(aPrevious, 43U)) + 4413861484961668394U;
            aOrbiterF = (((aWandererJ + RotL64(aCross, 26U)) + RotL64(aCarry, 51U)) + 2215946422098155969U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = (aWandererE + RotL64(aScatter, 51U)) + 14975185533513111110U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 9711613814905834552U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 13154957291850149471U;
            aOrbiterD = RotL64((aOrbiterD * 17049677190793844477U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 5058313016418534840U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 15011423472941211620U;
            aOrbiterI = RotL64((aOrbiterI * 6125316151731105673U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 2030053257469580168U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 150530795186791193U;
            aOrbiterB = RotL64((aOrbiterB * 11106050063717096073U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 10878237472104183427U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 11724672539469573109U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16158741837357985395U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 9589700906445846956U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 1367381624958248949U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8459515089081211977U), 29U);
            //
            aIngress = RotL64(aOrbiterD, 47U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterI, 37U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterF, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aPrevious, 50U) + RotL64(aOrbiterD, 51U)) + aOrbiterI) + RotL64(aCarry, 37U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 35U) + aOrbiterB) + RotL64(aOrbiterF, 26U));
            aWandererJ = aWandererJ + ((((RotL64(aCross, 13U) + RotL64(aOrbiterC, 5U)) + aOrbiterD) + RotL64(aCarry, 51U)) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 3U) + aOrbiterI) + RotL64(aOrbiterB, 13U));
            aWandererE = aWandererE + (((RotL64(aCross, 27U) + aOrbiterF) + RotL64(aOrbiterD, 35U)) + aPhaseGWandererUpdateSaltF[((aIndex + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererD, 42U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererE, 29U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 25693U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((aIndex + 28522U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28455U)) & S_BLOCK1], 18U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 24947U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 11U) ^ RotL64(aCross, 43U)) + (RotL64(aCarry, 26U) + RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = (aWandererF + RotL64(aCross, 11U)) + 18191288703716505885U;
            aOrbiterA = (((aWandererC + RotL64(aScatter, 27U)) + RotL64(aCarry, 39U)) + 9824014524910417136U) + aPhaseGOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = (((aWandererK + RotL64(aIngress, 39U)) + RotL64(aCarry, 13U)) + 11953012029254917548U) + aPhaseGOrbiterAssignSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 19U)) + RotL64(aCarry, 27U)) + 6297568011027199089U;
            aOrbiterD = (aWandererB + RotL64(aCross, 52U)) + 2576999400457367975U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 13176139160575558254U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 9978408174563621810U;
            aOrbiterG = RotL64((aOrbiterG * 1399052522159751531U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 16765834875061607142U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 16534507305459121344U;
            aOrbiterF = RotL64((aOrbiterF * 8943988574248229067U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 3114710944346151807U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 10240517868726718592U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4645691562915606463U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 10721450637990777883U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 16689590768796583952U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3046344179729901637U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 2427422768928450209U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 13495584061816457831U;
            aOrbiterD = RotL64((aOrbiterD * 6670984773768885119U), 13U);
            //
            aIngress = RotL64(aOrbiterA, 35U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterD, 23U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterG, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 51U) + aOrbiterB) + RotL64(aOrbiterD, 13U));
            aWandererF = aWandererF + (((RotL64(aIngress, 3U) + RotL64(aOrbiterB, 54U)) + aOrbiterF) + RotL64(aCarry, 13U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 26U) + aOrbiterA) + RotL64(aOrbiterF, 3U)) + aPhaseGWandererUpdateSaltB[((aIndex + 12U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 13U) + RotL64(aOrbiterA, 21U)) + aOrbiterG) + RotL64(aCarry, 27U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterF, 29U)) + aOrbiterD) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererF, 43U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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

void TwistExpander_Boxing_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterE = 0;
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 3559U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4021U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4052U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((aIndex + 4922U)) & S_BLOCK1], 44U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 35U) ^ RotL64(aCross, 6U)) + (RotL64(aPrevious, 51U) + RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = ((aWandererA + RotL64(aCross, 29U)) + RotL64(aCarry, 41U)) + 4476099022490972343U;
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 39U)) + RotL64(aCarry, 5U)) + 16836423700375760429U;
            aOrbiterI = (((aWandererF + RotL64(aScatter, 4U)) + RotL64(aCarry, 19U)) + 8850577488928703557U) + aPhaseHOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = ((aWandererH + RotL64(aIngress, 21U)) + 7091631824560042743U) + aPhaseHOrbiterAssignSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = (aWandererK + RotL64(aPrevious, 53U)) + 12560498899956759494U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 7797973377112012161U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 6173820673874805794U;
            aOrbiterI = RotL64((aOrbiterI * 15741300047917486527U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 10805025132310245348U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 7139216143268029968U;
            aOrbiterC = RotL64((aOrbiterC * 8349754682635765573U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 8241544862261635722U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 4735527016563596150U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6621354217673598381U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 5166171126690294033U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 11117641762075368393U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4980156869201219393U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 6312932356458415421U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 1304139291184508668U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 90744653170922319U), 47U);
            //
            aIngress = RotL64(aOrbiterF, 27U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterC, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aCross, 21U) + aOrbiterB) + RotL64(aOrbiterC, 30U)) + aPhaseHWandererUpdateSaltC[((aIndex + 12U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterB, 43U)) + aOrbiterH);
            aWandererK = aWandererK + (((RotL64(aScatter, 3U) + RotL64(aOrbiterI, 57U)) + aOrbiterB) + RotL64(aCarry, 27U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 53U) + aOrbiterI) + RotL64(aOrbiterF, 13U));
            aWandererH = aWandererH + ((((RotL64(aCross, 12U) + aOrbiterF) + RotL64(aOrbiterC, 5U)) + RotL64(aCarry, 51U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererA);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + RotL64(aWandererK, 13U);
            aCarry = aCarry + RotL64(aIngress, 30U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 8899U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9573U)) & S_BLOCK1], 36U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 15958U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneA[((aIndex + 10223U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 27U) ^ RotL64(aCarry, 13U)) + (RotL64(aCross, 52U) ^ RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = ((aWandererK + RotL64(aCross, 4U)) + 4773124477323378268U) + aPhaseHOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = ((aWandererF + RotL64(aIngress, 51U)) + RotL64(aCarry, 51U)) + 16848723289435796005U;
            aOrbiterC = (aWandererA + RotL64(aScatter, 27U)) + 13846642134917107058U;
            aOrbiterI = (((aWandererG + RotL64(aPrevious, 43U)) + RotL64(aCarry, 5U)) + 6472057872482789939U) + aPhaseHOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = ((aWandererI + RotL64(aScatter, 35U)) + RotL64(aCarry, 29U)) + 2747019500690707226U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 9003965289739733880U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 3013390651936257377U;
            aOrbiterC = RotL64((aOrbiterC * 11081353600889943167U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 3331004709895625067U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 15355010435553517129U;
            aOrbiterE = RotL64((aOrbiterE * 8322759117004876831U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 7709870658004280052U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 13568728443963926564U;
            aOrbiterH = RotL64((aOrbiterH * 6736090830113688981U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 12409548853419307131U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 969183352023661537U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5549220554838837145U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 15370309834426476775U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 3896803894396631184U;
            aOrbiterI = RotL64((aOrbiterI * 11018830202891911603U), 29U);
            //
            aIngress = RotL64(aOrbiterH, 47U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 37U));
            aIngress = aIngress + RotL64(aOrbiterK, 60U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aIngress, 42U) + RotL64(aOrbiterE, 37U)) + aOrbiterC);
            aWandererI = aWandererI + ((((RotL64(aCross, 57U) + aOrbiterK) + RotL64(aOrbiterI, 3U)) + RotL64(aCarry, 13U)) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterK, 22U)) + aOrbiterH) + aPhaseHWandererUpdateSaltA[((aIndex + 12U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterE, 13U)) + aOrbiterH) + RotL64(aCarry, 27U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 19U) + aOrbiterI) + RotL64(aOrbiterC, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererG);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + RotL64(aWandererF, 14U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 19892U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneD[((aIndex + 18978U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23369U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((aIndex + 21527U)) & S_BLOCK1], 24U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 35U) + RotL64(aCross, 5U)) ^ (RotL64(aCarry, 48U) + RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = (((aWandererI + RotL64(aPrevious, 11U)) + RotL64(aCarry, 11U)) + 6973892330986118220U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = ((aWandererF + RotL64(aIngress, 26U)) + RotL64(aCarry, 41U)) + 9886813896272094864U;
            aOrbiterF = (((aWandererH + RotL64(aScatter, 57U)) + RotL64(aCarry, 29U)) + 10996306582517553173U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = (aWandererA + RotL64(aCross, 37U)) + 8490648283899856223U;
            aOrbiterI = (aWandererK + RotL64(aPrevious, 47U)) + 105141713530704655U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 3114337422810562588U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 980857684690886131U;
            aOrbiterF = RotL64((aOrbiterF * 17407927633910728721U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 6562042345807072665U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 15665371138706353619U;
            aOrbiterE = RotL64((aOrbiterE * 8086237578564620623U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 18113013571374375028U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 17405346422601997299U;
            aOrbiterK = RotL64((aOrbiterK * 11162604605443005253U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 5130876096426182506U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 1813821672299154629U;
            aOrbiterA = RotL64((aOrbiterA * 15478100342425611875U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 15793814882743306728U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 13925299440495476399U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12049601510660117401U), 35U);
            //
            aIngress = RotL64(aOrbiterI, 40U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 13U));
            aIngress = aIngress + RotL64(aOrbiterK, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 5U) + aOrbiterK) + RotL64(aOrbiterE, 47U));
            aWandererF = aWandererF + ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterI, 19U)) + aOrbiterA) + RotL64(aCarry, 21U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 60U) + aOrbiterF) + RotL64(aOrbiterI, 57U)) + aPhaseHWandererUpdateSaltD[((aIndex + 8U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 19U) + RotL64(aOrbiterE, 3U)) + aOrbiterF) + RotL64(aCarry, 43U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 35U) + aOrbiterA) + RotL64(aOrbiterE, 36U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 27U) ^ aWandererK);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + RotL64(aWandererA, 5U);
            aCarry = aCarry + RotL64(aIngress, 58U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 25762U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneA[((aIndex + 24623U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26286U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 26858U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 29U) ^ RotL64(aPrevious, 60U)) + (RotL64(aIngress, 41U) ^ RotL64(aCarry, 13U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = (((aWandererJ + RotL64(aCross, 27U)) + RotL64(aCarry, 3U)) + 12535417189990029950U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 13U)) + RotL64(aCarry, 23U)) + 6204401443676390273U;
            aOrbiterC = (aWandererB + RotL64(aIngress, 47U)) + 869613505613154672U;
            aOrbiterH = ((aWandererD + RotL64(aScatter, 4U)) + RotL64(aCarry, 43U)) + 15053590879563855802U;
            aOrbiterG = ((aWandererG + RotL64(aCross, 37U)) + 13338989605204591428U) + aPhaseHOrbiterAssignSaltB[((aIndex + 28U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 18306470022403825392U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 1150696349434090218U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1099447646821052165U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 13549541786420596437U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 14302878430259588461U;
            aOrbiterJ = RotL64((aOrbiterJ * 16813606782134305513U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 4660437084477165225U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 1653628537860912069U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2624835201155303123U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 5594199757006711631U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 11008472193138708891U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13645764762027798301U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 3668516817279364310U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 128159531749679984U;
            aOrbiterG = RotL64((aOrbiterG * 4523246859249826987U), 5U);
            //
            aIngress = RotL64(aOrbiterG, 29U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterJ, 39U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterC, 50U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aCross, 43U) + aOrbiterJ) + RotL64(aOrbiterH, 22U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aIngress, 24U) + RotL64(aOrbiterJ, 35U)) + aOrbiterG) + RotL64(aCarry, 39U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 13U) + aOrbiterH) + RotL64(aOrbiterG, 3U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 35U) + aOrbiterE) + RotL64(aOrbiterJ, 53U)) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterH, 11U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 60U));
            aCarry = aCarry + RotL64(aWandererG, 37U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
