#include "TwistExpander_Karate_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_Karate_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xB4B78ADE37205715ULL + 0xF12739DA421CC21BULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xFD520E47C2519319ULL + 0xCF8DD1A72BF39ACDULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x99CC248AD69C0CB9ULL + 0xBBD5C56474955284ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xA962FA65EEDCB993ULL + 0xB50D4CD0FE8DAB60ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xA9B0C2A74BCF6CAFULL + 0x9FE9CA2694F82DB2ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x9EFEF0B6FB8B44E1ULL + 0xB77B586B8FB0D5B5ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xCE4D736C994CCDF1ULL + 0xE2BC3993D8729760ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xEF999A4736DF5C27ULL + 0xA59DA627FE9756DEULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 51U) ^ RotL64(aNonceWordD, 35U)) ^ RotL64(aNonceWordF, 4U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 4998U)) & S_BLOCK1], 43U) ^ RotL64(mSnow[((aIndex + 4601U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 13U) ^ RotL64(aNonceWordG, 4U)) ^ RotL64(aNonceWordH, 39U));
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 2462U)) & S_BLOCK1], 27U) ^ RotL64(mSnow[((S_BLOCK1 - aIndex + 16U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 51U) ^ RotL64(aCarry, 3U)) ^ (RotL64(aPrevious, 36U) + RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (aWandererI + RotL64(aScatter, 51U)) + 10404808878585437255U;
            aOrbiterK = (aWandererK + RotL64(aCross, 57U)) + 10587858736301591439U;
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 47U)) + RotL64(aCarry, 37U)) + 1430530909801644435U;
            aOrbiterF = ((aWandererE + RotL64(aIngress, 39U)) + RotL64(aCarry, 43U)) + 9090938022430118902U;
            aOrbiterE = (aWandererC + RotL64(aPrevious, 26U)) + 12936604311751121235U;
            aOrbiterA = ((aWandererJ + RotL64(aCross, 53U)) + 1000583006020232032U) + RotL64(aNonceWordC, 24U);
            aOrbiterB = (aWandererH + RotL64(aIngress, 29U)) + 12352532088997042232U;
            aOrbiterI = ((aWandererD + RotL64(aScatter, 11U)) + 16723410947058502564U) + RotL64(aNonceWordA, 7U);
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 37U)) + 16614089235313154270U) + aOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = (((aWandererF + RotL64(aCross, 14U)) + RotL64(aCarry, 3U)) + 4245553025593349277U) + aOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = (aWandererG + RotL64(aIngress, 3U)) + 3353146318549477494U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 5935727336135635196U) + aOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 10312187090293319667U;
            aOrbiterJ = RotL64((aOrbiterJ * 1395964500396711899U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 12192843181244744484U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 2542570124502586365U;
            aOrbiterA = RotL64((aOrbiterA * 17222847847573534963U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 3315472769469002444U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 17512858811783071174U) ^ aOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9070400454074283765U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 16633218007427888082U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 2502077714838858460U;
            aOrbiterF = RotL64((aOrbiterF * 970762420815997725U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 14792910273226469214U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 15739513291150783151U;
            aOrbiterB = RotL64((aOrbiterB * 11896279674116906915U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 2192903544350345992U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 844428341223009295U;
            aOrbiterG = RotL64((aOrbiterG * 4768368713974002539U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 2998511458298901402U) + RotL64(aNonceWordG, 25U);
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 7790789639864783373U;
            aOrbiterC = RotL64((aOrbiterC * 9173097618440495497U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 4540735375055164995U) + RotL64(aNonceWordD, 37U);
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 13700342877362633034U;
            aOrbiterK = RotL64((aOrbiterK * 14730797752841670505U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 16966725424259324323U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 5945539295893015935U;
            aOrbiterE = RotL64((aOrbiterE * 12226268057062268981U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 12560355243513521281U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 2104086086480258265U;
            aOrbiterI = RotL64((aOrbiterI * 17989755118752755577U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 4476697099257280568U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 10404808878585437255U) ^ aOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6245415417832089357U), 13U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterC, 11U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 51U));
            aIngress = aIngress + (RotL64(aOrbiterH, 38U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterK, 19U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterI, 13U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterE, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterA, 39U)) + aOrbiterK);
            aWandererG = aWandererG + ((RotL64(aIngress, 21U) + RotL64(aOrbiterK, 57U)) + aOrbiterD);
            aWandererB = aWandererB ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterD, 18U)) + aOrbiterB);
            aWandererK = aWandererK + (((RotL64(aScatter, 19U) + aOrbiterF) + RotL64(aOrbiterJ, 27U)) + aWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterC, 29U)) + aOrbiterI) + aWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 54U) + RotL64(aOrbiterC, 3U)) + aOrbiterH) + RotL64(aCarry, 3U)) + RotL64(aNonceWordE, 61U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 3U) + aOrbiterE) + RotL64(aOrbiterC, 23U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 5U) + aOrbiterJ) + RotL64(aOrbiterI, 13U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterA, 46U)) + aOrbiterE);
            aWandererD = aWandererD + (((RotL64(aPrevious, 14U) + aOrbiterA) + RotL64(aOrbiterJ, 43U)) + RotL64(aCarry, 23U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterG, 53U)) + aOrbiterK) + RotL64(aNonceWordF, 47U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 37U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 46U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererI, 44U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 51U) ^ RotL64(aNonceWordE, 43U)) ^ RotL64(aNonceWordH, 26U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 6778U)) & S_BLOCK1], 3U) ^ RotL64(mSnow[((aIndex + 10796U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 54U) ^ RotL64(aNonceWordF, 3U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 7379U)) & S_BLOCK1], 13U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 10808U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCross, 35U)) + (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 10U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (aWandererD + RotL64(aCross, 29U)) + 17470880031634374199U;
            aOrbiterG = ((aWandererC + RotL64(aIngress, 11U)) + RotL64(aCarry, 47U)) + 757565846006937746U;
            aOrbiterC = ((aWandererG + RotL64(aPrevious, 60U)) + 9419282475801345674U) + aOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = (aWandererJ + RotL64(aScatter, 43U)) + 2014248014107898196U;
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 53U)) + 15113928519446490441U;
            aOrbiterF = ((aWandererA + RotL64(aScatter, 41U)) + 7346126964886259935U) + aOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = (((aWandererK + RotL64(aCross, 18U)) + RotL64(aCarry, 13U)) + 5594123113093162359U) + RotL64(aNonceWordA, 17U);
            aOrbiterD = (aWandererB + RotL64(aIngress, 5U)) + 5659237263369402005U;
            aOrbiterB = (((aWandererE + RotL64(aScatter, 47U)) + RotL64(aCarry, 39U)) + 11565709683423969703U) + RotL64(aNonceWordF, 31U);
            aOrbiterH = (aWandererI + RotL64(aPrevious, 23U)) + 16782863743534856287U;
            aOrbiterI = (aWandererH + RotL64(aIngress, 21U)) + 13499100900072115907U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 11414447651044205242U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 7545993795121430538U;
            aOrbiterC = RotL64((aOrbiterC * 10758488381206257261U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 11778229237616454988U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 2544793391976514665U;
            aOrbiterG = RotL64((aOrbiterG * 4021060413798523299U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 9972156716619459164U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 17651030383827445664U) ^ aOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6742914240706775487U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 17439147296849134543U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 10021926927948343656U) ^ aOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 18139540407315440909U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 9309867875882669289U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 14951424455944346337U;
            aOrbiterB = RotL64((aOrbiterB * 10569523948169951309U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 2166343974068770659U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 11386993629011562026U;
            aOrbiterA = RotL64((aOrbiterA * 3091639433512536097U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 5747849744680120960U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 4019290369160113026U) ^ RotL64(aNonceWordB, 55U);
            aOrbiterE = RotL64((aOrbiterE * 5567515306039646735U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 3820540009554769592U) + RotL64(aNonceWordD, 39U);
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 8210747198363020939U;
            aOrbiterF = RotL64((aOrbiterF * 16215133106542452509U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 3006494852696036003U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 2736305345451919450U;
            aOrbiterD = RotL64((aOrbiterD * 11993452696344358247U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 6148431711118275178U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 6986633012691940738U;
            aOrbiterH = RotL64((aOrbiterH * 15672039482523804893U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 7837859154831245165U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 17470880031634374199U;
            aOrbiterI = RotL64((aOrbiterI * 2153299273348512243U), 41U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterK, 27U);
            aIngress = aIngress + (RotL64(aOrbiterB, 47U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 13U));
            aIngress = aIngress + (RotL64(aOrbiterE, 5U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 43U));
            aIngress = aIngress + RotL64(aOrbiterC, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 57U) + aOrbiterE) + RotL64(aOrbiterI, 3U));
            aWandererG = aWandererG + ((RotL64(aIngress, 60U) + RotL64(aOrbiterK, 19U)) + aOrbiterC);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 27U) + aOrbiterF) + RotL64(aOrbiterD, 23U));
            aWandererB = aWandererB + (((RotL64(aScatter, 51U) + RotL64(aOrbiterG, 39U)) + aOrbiterJ) + RotL64(aNonceWordG, 5U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 19U) + aOrbiterH) + RotL64(aOrbiterI, 47U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 37U) + aOrbiterI) + RotL64(aOrbiterF, 44U)) + RotL64(aCarry, 43U)) + aWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 39U) + RotL64(aOrbiterG, 27U)) + aOrbiterD) + aWandererUpdateSaltD[((aIndex + 8U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 54U) + RotL64(aOrbiterB, 57U)) + aOrbiterC) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterJ, 37U)) + aOrbiterA) + RotL64(aNonceWordH, 28U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterG, 30U)) + aOrbiterH);
            aWandererH = aWandererH ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterF, 11U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 34U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + (RotL64(aWandererK, 37U) ^ aWandererI);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 41U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + RotL64(aWandererB, 58U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 57U) ^ RotL64(aNonceWordA, 43U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 13034U)) & S_BLOCK1], 35U) ^ RotL64(mSnow[((S_BLOCK1 - aIndex + 15723U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 37U) ^ RotL64(aNonceWordB, 28U)) ^ RotL64(aNonceWordG, 19U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12746U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 16332U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCross, 29U)) ^ (RotL64(aCarry, 41U) ^ RotL64(aIngress, 14U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererH + RotL64(aScatter, 47U)) + RotL64(aCarry, 57U)) + 9888431329297626900U;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 5U)) + 2937735167534624403U) + aOrbiterAssignSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterI = (aWandererJ + RotL64(aCross, 27U)) + 17626022970343789617U;
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 3U)) + RotL64(aCarry, 47U)) + 5665660859333693743U;
            aOrbiterD = (aWandererF + RotL64(aScatter, 24U)) + 1060537034632076669U;
            aOrbiterH = (aWandererB + RotL64(aIngress, 39U)) + 743777763907175800U;
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 19U)) + 5744905970181808845U;
            aOrbiterA = ((aWandererD + RotL64(aCross, 51U)) + 3545351394494002180U) + aOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = ((aWandererA + RotL64(aIngress, 53U)) + RotL64(aCarry, 21U)) + 4877547088414106007U;
            aOrbiterG = ((aWandererC + RotL64(aScatter, 12U)) + 11669378338379598445U) + RotL64(aNonceWordD, 45U);
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 37U)) + 2961072441706158212U) + RotL64(aNonceWordB, 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 13984945589234919765U) + aOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 1433097875470903205U;
            aOrbiterI = RotL64((aOrbiterI * 451996840039906781U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 716415411025451152U) + RotL64(aNonceWordG, 23U);
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 8542286150858297810U;
            aOrbiterH = RotL64((aOrbiterH * 9139015340823332449U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 12932391786479661299U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 14005503313299177013U;
            aOrbiterK = RotL64((aOrbiterK * 802663466907819743U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 9382792812676318046U) + aOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 5138554251079724724U;
            aOrbiterD = RotL64((aOrbiterD * 6386016499265056247U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 8522380066269546172U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 11825536408101906458U;
            aOrbiterA = RotL64((aOrbiterA * 17042837108792016849U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 15504062350899452495U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 1219010998820336744U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10650635772711590803U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 6442717843380349632U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 1047843426279085117U;
            aOrbiterB = RotL64((aOrbiterB * 4074561571072878005U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 10611039527108679173U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 5092816736177358221U;
            aOrbiterC = RotL64((aOrbiterC * 14342779343820140833U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 12327496881352988530U) + aOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 6405703847824845457U) ^ RotL64(aNonceWordF, 29U);
            aOrbiterJ = RotL64((aOrbiterJ * 12094143526751620113U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 8906613392335197542U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 5962698890029858689U;
            aOrbiterF = RotL64((aOrbiterF * 9136193803330500489U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 2610083915800734277U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 9888431329297626900U;
            aOrbiterE = RotL64((aOrbiterE * 3794133356691218671U), 41U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterK, 39U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 13U));
            aIngress = aIngress + (RotL64(aOrbiterF, 11U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 23U));
            aIngress = aIngress + (RotL64(aOrbiterE, 56U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterA, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aIngress, 3U) + aOrbiterA) + RotL64(aOrbiterH, 41U));
            aWandererF = aWandererF + ((RotL64(aCross, 50U) + RotL64(aOrbiterK, 53U)) + aOrbiterE);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 47U) + aOrbiterB) + RotL64(aOrbiterC, 12U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 21U) + aOrbiterE) + RotL64(aOrbiterG, 3U)) + aWandererUpdateSaltC[((aIndex + 16U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 37U) + aOrbiterA) + RotL64(aOrbiterD, 39U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 43U) + aOrbiterI) + RotL64(aOrbiterD, 37U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 53U) + aOrbiterJ) + RotL64(aOrbiterE, 35U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 35U) + RotL64(aOrbiterK, 44U)) + aOrbiterF) + RotL64(aCarry, 43U)) + RotL64(aNonceWordH, 3U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 18U) + aOrbiterB) + RotL64(aOrbiterH, 23U));
            aWandererE = aWandererE + ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterH, 51U)) + aOrbiterI) + RotL64(aCarry, 29U)) + RotL64(aNonceWordC, 58U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 13U) + aOrbiterB) + RotL64(aOrbiterK, 19U)) + aWandererUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 30U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererD);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 51U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 53U));
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererA, 58U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordE, 40U) ^ RotL64(aNonceWordH, 27U));
            aIngress = aIngress ^ (RotL64(mSnow[((aIndex + 18079U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((aIndex + 21075U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 43U) ^ RotL64(aNonceWordG, 4U)) ^ RotL64(aNonceWordF, 13U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20230U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 20641U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 21U) + RotL64(aCross, 50U)) ^ (RotL64(aCarry, 3U) + RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (((aWandererI + RotL64(aPrevious, 35U)) + RotL64(aCarry, 57U)) + 2974056819475622600U) + aOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = (aWandererA + RotL64(aCross, 6U)) + 7345051759236356098U;
            aOrbiterE = (aWandererC + RotL64(aScatter, 47U)) + 12738468816846628882U;
            aOrbiterA = ((aWandererG + RotL64(aIngress, 57U)) + 7694520596043297922U) + RotL64(aNonceWordG, 21U);
            aOrbiterJ = (aWandererJ + RotL64(aScatter, 39U)) + 5530753590015084774U;
            aOrbiterD = (aWandererK + RotL64(aPrevious, 37U)) + 3776309161718383105U;
            aOrbiterK = (aWandererF + RotL64(aCross, 43U)) + 784780304358106404U;
            aOrbiterC = (((aWandererB + RotL64(aIngress, 3U)) + RotL64(aCarry, 43U)) + 8999942326995036509U) + RotL64(aNonceWordA, 8U);
            aOrbiterH = (((aWandererD + RotL64(aCross, 51U)) + RotL64(aCarry, 21U)) + 5194986506064092779U) + aOrbiterAssignSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterF = (aWandererH + RotL64(aPrevious, 27U)) + 7920040007459652762U;
            aOrbiterG = (aWandererE + RotL64(aIngress, 10U)) + 11311997270710107937U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 5365231114813547251U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 8630110234623825263U;
            aOrbiterE = RotL64((aOrbiterE * 2735881715888325759U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 2358235238039571072U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 18059414891616491807U;
            aOrbiterJ = RotL64((aOrbiterJ * 17150786106857185467U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 14526050556461782864U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 6937282036603272474U) ^ aOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14954512365270028029U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 10105832250694931310U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 3884223553012098137U;
            aOrbiterK = RotL64((aOrbiterK * 16340956813003906195U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 10385284339549648087U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 1257633893341505930U;
            aOrbiterC = RotL64((aOrbiterC * 2669950791270500977U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 5528890519572824318U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 15664241747527713256U;
            aOrbiterH = RotL64((aOrbiterH * 16670884497088220497U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 14264122979415331887U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 17985061405540198036U;
            aOrbiterF = RotL64((aOrbiterF * 2729487440173395133U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 1663986734997903415U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 3706166884286400587U) ^ RotL64(aNonceWordC, 29U);
            aOrbiterG = RotL64((aOrbiterG * 10549736618301955745U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 12736963182099961466U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 95411267612114381U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8011937916302325057U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 4966620136499917388U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 8478316876240452401U;
            aOrbiterI = RotL64((aOrbiterI * 13297718919105366563U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 11123814701411614557U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 2974056819475622600U) ^ RotL64(aNonceWordB, 45U);
            aOrbiterA = RotL64((aOrbiterA * 5913569942407618997U), 37U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterC, 51U);
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 37U));
            aIngress = aIngress + (RotL64(aOrbiterG, 23U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterE, 47U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterJ, 42U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aScatter, 51U) + aOrbiterB) + RotL64(aOrbiterE, 53U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 54U) + RotL64(aOrbiterC, 51U)) + aOrbiterA) + aWandererUpdateSaltB[((aIndex + 10U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterF, 58U)) + aOrbiterA) + RotL64(aCarry, 5U)) + RotL64(aNonceWordE, 11U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterI, 41U)) + aOrbiterG);
            aWandererC = aWandererC + ((RotL64(aCross, 3U) + RotL64(aOrbiterC, 5U)) + aOrbiterB);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 39U) + aOrbiterG) + RotL64(aOrbiterF, 3U));
            aWandererD = aWandererD + (((RotL64(aIngress, 5U) + aOrbiterJ) + RotL64(aOrbiterE, 47U)) + aWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 37U) + aOrbiterK) + RotL64(aOrbiterE, 22U));
            aWandererB = aWandererB + ((RotL64(aScatter, 44U) + aOrbiterB) + RotL64(aOrbiterH, 19U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 35U) + aOrbiterF) + RotL64(aOrbiterH, 43U));
            aWandererG = aWandererG + ((((RotL64(aIngress, 27U) + RotL64(aOrbiterD, 29U)) + aOrbiterI) + RotL64(aCarry, 37U)) + RotL64(aNonceWordD, 47U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 21U));
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererA, 48U) ^ aWandererF);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 41U));
            aCarry = aCarry + RotL64(aWandererD, 29U);
            aCarry = aCarry + RotL64(aIngress, 6U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 21U) ^ RotL64(aNonceWordC, 30U)) ^ RotL64(aNonceWordA, 41U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 24750U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26605U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 35U) ^ RotL64(aNonceWordH, 13U)) ^ RotL64(aNonceWordG, 56U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27288U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 24506U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 27U) ^ RotL64(aCross, 39U)) + (RotL64(aPrevious, 51U) + RotL64(aCarry, 10U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (aWandererF + RotL64(aScatter, 3U)) + 8020711767807230555U;
            aOrbiterJ = (aWandererH + RotL64(aCross, 39U)) + 15368693777246341570U;
            aOrbiterK = (((aWandererG + RotL64(aIngress, 35U)) + RotL64(aCarry, 11U)) + 5117523734225562401U) + aOrbiterAssignSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 18U)) + RotL64(aCarry, 51U)) + 13155269151097507808U;
            aOrbiterH = (aWandererA + RotL64(aIngress, 47U)) + 9879303753623578272U;
            aOrbiterC = (((aWandererC + RotL64(aScatter, 51U)) + 1165799257173794826U) + aOrbiterAssignSaltD[((aIndex + 6U)) & S_SALT1]) + RotL64(aNonceWordF, 41U);
            aOrbiterE = (((aWandererD + RotL64(aCross, 27U)) + RotL64(aCarry, 5U)) + 930641942062732091U) + RotL64(aNonceWordE, 25U);
            aOrbiterD = (aWandererB + RotL64(aPrevious, 21U)) + 11330571332221123153U;
            aOrbiterA = (aWandererE + RotL64(aCross, 57U)) + 2862963158282518899U;
            aOrbiterB = (aWandererJ + RotL64(aPrevious, 53U)) + 6019186399361476659U;
            aOrbiterG = (aWandererI + RotL64(aIngress, 10U)) + 1924419843785161958U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 12618629043591380461U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 9334176504266512405U;
            aOrbiterK = RotL64((aOrbiterK * 18239109235362925739U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 16829692481030013551U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 5604784396927022709U;
            aOrbiterC = RotL64((aOrbiterC * 2833893610883508353U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 16124030106598549644U) + aOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 16571659812830230677U;
            aOrbiterD = RotL64((aOrbiterD * 4668250364992383549U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 15171089673591843703U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 2826755560293849328U;
            aOrbiterB = RotL64((aOrbiterB * 9397017963457655287U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 9976785768283589291U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 11845100564714691809U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4935139932585319251U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 7318560453127859950U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 3039196878830506712U;
            aOrbiterI = RotL64((aOrbiterI * 3140508261330698717U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 8850992055588337843U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 4219373528176869146U) ^ aOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1310964742529956743U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 1341474458715938799U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 15937557372891732898U;
            aOrbiterA = RotL64((aOrbiterA * 11437307017920192915U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 7512741986101399499U) + RotL64(aNonceWordB, 9U);
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 4304636545688233645U;
            aOrbiterG = RotL64((aOrbiterG * 1948671766238131953U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 11460886069492094055U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 2019818350627642126U;
            aOrbiterJ = RotL64((aOrbiterJ * 9802784763505584769U), 35U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterG) + 3190374588085859096U) + aOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1]) + RotL64(aNonceWordG, 39U);
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 8020711767807230555U;
            aOrbiterH = RotL64((aOrbiterH * 12055760672321414929U), 11U);
            //
            aIngress = RotL64(aOrbiterB, 11U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 21U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 5U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 38U));
            aIngress = aIngress + RotL64(aOrbiterC, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterI, 26U)) + aOrbiterC);
            aWandererE = aWandererE + ((RotL64(aPrevious, 14U) + RotL64(aOrbiterJ, 5U)) + aOrbiterG);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterH, 23U)) + aOrbiterA) + aWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aCross, 11U) + aOrbiterG) + RotL64(aOrbiterA, 37U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterC, 21U)) + aOrbiterK);
            aWandererK = aWandererK + ((RotL64(aIngress, 39U) + aOrbiterD) + RotL64(aOrbiterE, 41U));
            aWandererF = aWandererF ^ ((((RotL64(aCross, 51U) + RotL64(aOrbiterI, 53U)) + aOrbiterE) + RotL64(aNonceWordH, 23U)) + aWandererUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 42U) + aOrbiterF) + RotL64(aOrbiterJ, 35U)) + RotL64(aCarry, 13U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterE, 3U)) + aOrbiterH);
            aWandererB = aWandererB + ((((RotL64(aIngress, 47U) + RotL64(aOrbiterH, 60U)) + aOrbiterB) + RotL64(aCarry, 39U)) + RotL64(aNonceWordC, 40U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 35U) + aOrbiterK) + RotL64(aOrbiterE, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererB, 44U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererK, 47U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordA, 11U) ^ RotL64(aNonceWordE, 35U)) ^ RotL64(aNonceWordG, 48U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 31218U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32691U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 44U) ^ RotL64(aNonceWordD, 11U)) ^ RotL64(aNonceWordB, 29U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29614U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 28403U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 20U)) ^ (RotL64(aCross, 53U) + RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 13U)) + 4384716820085860551U;
            aOrbiterB = ((aWandererI + RotL64(aCross, 27U)) + RotL64(aCarry, 23U)) + 9715780315942116888U;
            aOrbiterK = (((aWandererD + RotL64(aScatter, 52U)) + RotL64(aCarry, 37U)) + 15963520052789178632U) + RotL64(aNonceWordF, 37U);
            aOrbiterI = ((aWandererK + RotL64(aIngress, 43U)) + 14346700690686392938U) + aOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = ((aWandererE + RotL64(aScatter, 21U)) + 6005518012489966643U) + aOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = ((aWandererC + RotL64(aIngress, 37U)) + RotL64(aCarry, 3U)) + 2506732930310252119U;
            aOrbiterF = (aWandererB + RotL64(aCross, 11U)) + 16782163084851775826U;
            aOrbiterG = (aWandererH + RotL64(aPrevious, 3U)) + 823673076571076303U;
            aOrbiterA = ((aWandererF + RotL64(aIngress, 23U)) + 1634084509064077736U) + RotL64(aNonceWordA, 3U);
            aOrbiterJ = (aWandererA + RotL64(aPrevious, 30U)) + 1288134975466877686U;
            aOrbiterD = (aWandererG + RotL64(aScatter, 41U)) + 2998220403162908444U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 220430672180734911U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 10223923547068528867U;
            aOrbiterK = RotL64((aOrbiterK * 12577370238343872139U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 11696469696177647608U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 6545430420379636963U;
            aOrbiterC = RotL64((aOrbiterC * 8387163146257553773U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 79691451831797107U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 8971444023498649419U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7148919880477390009U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 5624403902454498793U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 9468064161002030997U;
            aOrbiterF = RotL64((aOrbiterF * 8243560528100864595U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 4619361544913629805U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 12682446273369750704U;
            aOrbiterG = RotL64((aOrbiterG * 10879074713156075641U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 8728730962617599223U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 9099675924074253030U;
            aOrbiterA = RotL64((aOrbiterA * 5525644236954497523U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 3298303921318288541U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 5953276499411658358U;
            aOrbiterJ = RotL64((aOrbiterJ * 10565471305001292693U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 6725769507592688539U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 1057277456510215817U;
            aOrbiterD = RotL64((aOrbiterD * 8269412198279297075U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 11317925732206917722U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 17814749417006079067U) ^ RotL64(aNonceWordC, 15U);
            aOrbiterH = RotL64((aOrbiterH * 4369209051015735925U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 9258362135343403308U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 4873837345446960113U;
            aOrbiterB = RotL64((aOrbiterB * 14223381466269503273U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 7863380865835889675U) + RotL64(aNonceWordD, 57U);
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 4384716820085860551U) ^ aOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2003891033298374621U), 57U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterF, 29U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 13U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 41U));
            aIngress = aIngress + (RotL64(aOrbiterG, 35U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 44U));
            aIngress = aIngress + RotL64(aOrbiterC, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aIngress, 5U) + aOrbiterK) + RotL64(aOrbiterF, 41U)) + RotL64(aCarry, 51U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 28U) + aOrbiterH) + RotL64(aOrbiterB, 3U));
            aWandererG = aWandererG + (((RotL64(aCross, 11U) + aOrbiterD) + RotL64(aOrbiterH, 19U)) + RotL64(aCarry, 27U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 37U) + aOrbiterC) + RotL64(aOrbiterJ, 21U));
            aWandererB = aWandererB + ((RotL64(aCross, 21U) + aOrbiterA) + RotL64(aOrbiterH, 57U));
            aWandererI = aWandererI ^ ((((RotL64(aIngress, 53U) + RotL64(aOrbiterE, 48U)) + aOrbiterD) + RotL64(aNonceWordE, 39U)) + aWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 57U) + aOrbiterH) + RotL64(aOrbiterC, 35U)) + RotL64(aNonceWordH, 40U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 23U) + aOrbiterD) + RotL64(aOrbiterJ, 29U));
            aWandererK = aWandererK + ((RotL64(aIngress, 3U) + RotL64(aOrbiterG, 23U)) + aOrbiterA);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 18U) + RotL64(aOrbiterI, 52U)) + aOrbiterD) + aWandererUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 13U) + aOrbiterD) + RotL64(aOrbiterF, 27U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 46U));
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererA);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 13U));
            aCarry = aCarry + RotL64(aWandererG, 20U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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

void TwistExpander_Karate_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xBC14096F3680B515ULL + 0x801022D3642FBE73ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xB8A4EC174752B58BULL + 0xA118C6A5AB400711ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xAA227AEDBEBCBE63ULL + 0xBB62EBEBEA32ABA1ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xB5E8DEEC0830BF61ULL + 0x990E14264001809BULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xA39AC0B4737B38ABULL + 0x97E0A35659833713ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xABCA7A422D55D241ULL + 0xFF871F721F14B90AULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xE9FA54AB05A526A1ULL + 0xB6B8030469818CB8ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xD7ED1EA607E93349ULL + 0xEBAC301CB405C947ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 37U) ^ RotL64(aNonceWordC, 23U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 7593U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 6259U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 3U) ^ RotL64(aNonceWordG, 21U)) ^ RotL64(aNonceWordA, 53U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 7699U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((aIndex + 24U)) & S_BLOCK1], 42U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 51U) + RotL64(aCarry, 38U)) ^ (RotL64(aPrevious, 11U) ^ RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = ((aWandererA + RotL64(aCross, 6U)) + 17668251151213543491U) + RotL64(aNonceWordF, 41U);
            aOrbiterD = ((aWandererC + RotL64(aScatter, 35U)) + 16101602509895104517U) + aOrbiterAssignSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 39U)) + RotL64(aCarry, 19U)) + 9083915270773304935U;
            aOrbiterK = (aWandererK + RotL64(aIngress, 43U)) + 12810720730318214811U;
            aOrbiterA = (aWandererI + RotL64(aPrevious, 53U)) + 18113428002071925621U;
            aOrbiterF = ((aWandererH + RotL64(aCross, 57U)) + RotL64(aCarry, 3U)) + 1582208899354109878U;
            aOrbiterI = ((aWandererE + RotL64(aScatter, 23U)) + 4180688104819188154U) + aOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = (((aWandererJ + RotL64(aIngress, 12U)) + RotL64(aCarry, 11U)) + 8954598189262820611U) + RotL64(aNonceWordA, 59U);
            aOrbiterG = (aWandererF + RotL64(aCross, 29U)) + 15360094153175355879U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 8383954114668216260U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 15626783326234049197U;
            aOrbiterB = RotL64((aOrbiterB * 15058420415480073793U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 10609978564404958066U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 17656516608997517984U;
            aOrbiterF = RotL64((aOrbiterF * 4590620354119899777U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 760077259110786536U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 3597338735888033063U;
            aOrbiterE = RotL64((aOrbiterE * 6548831472863517621U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 4431777844935985157U) + aOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 10710423172154671296U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16267496318491473315U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 10240882795242085185U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 7826053487019825891U;
            aOrbiterC = RotL64((aOrbiterC * 15053729937684375907U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 9418883403715727353U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 11507423614799075545U) ^ aOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16189463984557044693U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 11545217316421066655U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 617921402135485341U) ^ RotL64(aNonceWordB, 39U);
            aOrbiterI = RotL64((aOrbiterI * 8182920764965471653U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 14456933220749921009U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 7990243583564535387U) ^ RotL64(aNonceWordC, 58U);
            aOrbiterD = RotL64((aOrbiterD * 5994900368027985469U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 14023633125757654751U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 11319146808574958827U;
            aOrbiterA = RotL64((aOrbiterA * 13676159969338309307U), 53U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterC, 27U);
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 24U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 11U));
            aIngress = aIngress + RotL64(aOrbiterA, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 51U) + aOrbiterE) + RotL64(aOrbiterK, 47U));
            aWandererF = aWandererF + ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterA, 13U)) + aOrbiterE) + RotL64(aCarry, 11U)) + RotL64(aNonceWordD, 53U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 23U) + aOrbiterG) + RotL64(aOrbiterD, 23U));
            aWandererH = aWandererH + ((RotL64(aIngress, 41U) + RotL64(aOrbiterB, 35U)) + aOrbiterG);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 46U) + RotL64(aOrbiterB, 28U)) + aOrbiterI);
            aWandererE = aWandererE + ((((RotL64(aIngress, 19U) + aOrbiterC) + RotL64(aOrbiterF, 19U)) + RotL64(aCarry, 47U)) + aWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aCross, 35U) + aOrbiterB) + RotL64(aOrbiterK, 57U)) + aWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aScatter, 57U) + aOrbiterD) + RotL64(aOrbiterF, 3U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 10U) + RotL64(aOrbiterA, 40U)) + aOrbiterK) + RotL64(aNonceWordE, 31U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererI);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 51U));
            aCarry = aCarry + RotL64(aWandererB, 6U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 44U) ^ RotL64(aNonceWordG, 27U)) ^ RotL64(aNonceWordC, 13U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 14229U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 10361U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 22U) ^ RotL64(aNonceWordE, 57U)) ^ RotL64(aNonceWordH, 3U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8698U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 10640U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 43U) ^ RotL64(aIngress, 11U)) + (RotL64(aPrevious, 60U) + RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererK + RotL64(aCross, 23U)) + 3550722402315312207U) + RotL64(aNonceWordD, 25U);
            aOrbiterA = (aWandererH + RotL64(aScatter, 43U)) + 16724184551669522754U;
            aOrbiterG = (aWandererC + RotL64(aIngress, 60U)) + 981751330116773021U;
            aOrbiterH = (((aWandererD + RotL64(aPrevious, 27U)) + RotL64(aCarry, 39U)) + 7891159229704944868U) + aOrbiterAssignSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterD = ((aWandererI + RotL64(aCross, 53U)) + RotL64(aCarry, 21U)) + 13618396711464799841U;
            aOrbiterJ = (aWandererA + RotL64(aScatter, 13U)) + 5969291018449003648U;
            aOrbiterE = (aWandererE + RotL64(aPrevious, 35U)) + 14595540413313640042U;
            aOrbiterI = (((aWandererB + RotL64(aIngress, 48U)) + RotL64(aCarry, 11U)) + 3287990436916111762U) + aOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 5U)) + 12534369400200483704U) + RotL64(aNonceWordA, 61U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 2277312067930392274U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 10026320559261334353U) ^ aOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11020464940995912637U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 11258082063135659551U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 1445958517675746990U;
            aOrbiterD = RotL64((aOrbiterD * 10062265337488757971U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 1011298251290970844U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 6487834862470043744U;
            aOrbiterE = RotL64((aOrbiterE * 15477913837027179675U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 9966279022928268335U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 10285993486057704393U;
            aOrbiterI = RotL64((aOrbiterI * 15965714363201157535U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 16005362468813966136U) + RotL64(aNonceWordE, 10U);
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 223843444699390781U) ^ aOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 665392038954573081U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 18178876294968532775U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 12490136112181806806U;
            aOrbiterK = RotL64((aOrbiterK * 16380841616662993709U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 8775696166557913635U) + aOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 16464340319444310842U;
            aOrbiterH = RotL64((aOrbiterH * 18111632334728200721U), 57U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterH) + 6296039992673546227U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]) + RotL64(aNonceWordG, 59U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 7152939277656436037U;
            aOrbiterJ = RotL64((aOrbiterJ * 15183918431501487319U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 14066791413416223271U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 5026743227399908016U;
            aOrbiterA = RotL64((aOrbiterA * 5891343232759075675U), 47U);
            //
            aIngress = RotL64(aOrbiterI, 44U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 27U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 57U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + RotL64(aOrbiterE, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aCross, 35U) + aOrbiterH) + RotL64(aOrbiterC, 43U)) + aWandererUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 13U) + aOrbiterJ) + RotL64(aOrbiterD, 5U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 43U) + aOrbiterC) + RotL64(aOrbiterJ, 36U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 56U) + aOrbiterK) + RotL64(aOrbiterG, 57U)) + RotL64(aNonceWordC, 3U));
            aWandererE = aWandererE + (((RotL64(aCross, 51U) + RotL64(aOrbiterA, 21U)) + aOrbiterK) + RotL64(aNonceWordF, 31U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 3U) + aOrbiterE) + RotL64(aOrbiterI, 51U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 39U) + aOrbiterI) + RotL64(aOrbiterA, 28U)) + RotL64(aCarry, 51U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 22U) + RotL64(aOrbiterC, 11U)) + aOrbiterE) + aWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 29U) + aOrbiterH) + RotL64(aOrbiterD, 47U)) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererJ, 42U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererI);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + RotL64(aWandererH, 53U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 37U) ^ RotL64(aNonceWordF, 54U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 19827U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneA[((aIndex + 21589U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 3U) ^ RotL64(aNonceWordE, 43U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17574U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 23794U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 19U) + RotL64(aCarry, 3U)) ^ (RotL64(aIngress, 54U) ^ RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 30U)) + 12775735908960052604U) + aOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 47U)) + 11791373812080296887U) + aOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = ((aWandererF + RotL64(aCross, 51U)) + RotL64(aCarry, 39U)) + 5537362877706057303U;
            aOrbiterI = (aWandererK + RotL64(aScatter, 11U)) + 2023912048504189380U;
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 57U)) + RotL64(aCarry, 19U)) + 17668828109963766893U;
            aOrbiterD = ((aWandererI + RotL64(aScatter, 4U)) + 558908629933941224U) + RotL64(aNonceWordB, 13U);
            aOrbiterG = ((aWandererA + RotL64(aCross, 41U)) + 1479633119685446888U) + RotL64(aNonceWordG, 59U);
            aOrbiterA = ((aWandererG + RotL64(aIngress, 35U)) + RotL64(aCarry, 53U)) + 15460320397843364063U;
            aOrbiterC = (aWandererD + RotL64(aScatter, 19U)) + 10059749397555469054U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 9987633811929693924U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 10087337844580228269U;
            aOrbiterB = RotL64((aOrbiterB * 13817142288940843815U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 4446204415503364254U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 15106063243302192717U;
            aOrbiterF = RotL64((aOrbiterF * 13273756657334709803U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 9430197906134676162U) + RotL64(aNonceWordC, 45U);
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 1226048679997253363U;
            aOrbiterI = RotL64((aOrbiterI * 14247538885252664127U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 10611580584157624739U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 3137391249289641509U;
            aOrbiterK = RotL64((aOrbiterK * 5462682413239873181U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 9327201928815412810U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 7890659377013147073U;
            aOrbiterE = RotL64((aOrbiterE * 13827717178378062047U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 10675114832750356941U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 8804440385852327267U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8520671775587260601U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 12871947817782057116U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterA) ^ 11015991745792051390U) ^ aOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1]) ^ RotL64(aNonceWordH, 7U);
            aOrbiterG = RotL64((aOrbiterG * 17152451500505815031U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 6320437975845673731U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 702457937087191287U;
            aOrbiterA = RotL64((aOrbiterA * 17491257114676739589U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 16629064896250312921U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 6054107387816339103U;
            aOrbiterC = RotL64((aOrbiterC * 6983767878966747219U), 5U);
            //
            aIngress = RotL64(aOrbiterB, 43U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 39U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 11U));
            aIngress = aIngress + (RotL64(aOrbiterA, 50U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterK, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterE, 29U)) + aOrbiterA);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterB, 47U)) + aOrbiterC);
            aWandererA = aWandererA + (((RotL64(aScatter, 47U) + aOrbiterF) + RotL64(aOrbiterK, 56U)) + RotL64(aCarry, 35U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 34U) + RotL64(aOrbiterC, 51U)) + aOrbiterD);
            aWandererH = aWandererH + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterB, 21U)) + aOrbiterG) + RotL64(aCarry, 5U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 53U) + aOrbiterC) + RotL64(aOrbiterA, 35U));
            aWandererD = aWandererD + (((RotL64(aScatter, 3U) + aOrbiterK) + RotL64(aOrbiterI, 39U)) + aWandererUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((((RotL64(aCross, 18U) + RotL64(aOrbiterG, 3U)) + aOrbiterD) + RotL64(aNonceWordA, 40U)) + aWandererUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 39U) + aOrbiterF) + RotL64(aOrbiterI, 10U)) + RotL64(aNonceWordD, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 53U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererJ);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 58U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + RotL64(aWandererK, 23U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 5U) ^ RotL64(aNonceWordE, 20U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 26795U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32551U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 57U) ^ RotL64(aNonceWordB, 22U)) ^ RotL64(aNonceWordG, 35U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 29929U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 32553U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 37U) + RotL64(aCross, 11U)) + (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 60U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (((aWandererG + RotL64(aCross, 39U)) + RotL64(aCarry, 43U)) + 16016931609704150191U) + RotL64(aNonceWordC, 23U);
            aOrbiterI = ((aWandererE + RotL64(aIngress, 47U)) + RotL64(aCarry, 57U)) + 14511433515861302636U;
            aOrbiterD = ((aWandererD + RotL64(aScatter, 35U)) + RotL64(aCarry, 11U)) + 11691237442613269593U;
            aOrbiterK = (aWandererK + RotL64(aPrevious, 54U)) + 16383220587320484649U;
            aOrbiterC = (aWandererH + RotL64(aScatter, 19U)) + 14293015313458219868U;
            aOrbiterG = ((aWandererJ + RotL64(aCross, 3U)) + 4407695248205526670U) + RotL64(aNonceWordG, 53U);
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 29U)) + 1158323195324398372U;
            aOrbiterA = ((aWandererC + RotL64(aIngress, 11U)) + 6577683409653864555U) + aOrbiterAssignSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterB = ((aWandererA + RotL64(aScatter, 58U)) + 171080079472863843U) + aOrbiterAssignSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 5766333425872228205U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 16173508656917582960U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12187968015372936695U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 11781450063402219202U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 13033139686637576694U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4331137994135472025U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 4006310759400926020U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 13156817947481574467U;
            aOrbiterJ = RotL64((aOrbiterJ * 563189239835001483U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 12791290558893516411U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 989729955679243234U;
            aOrbiterH = RotL64((aOrbiterH * 8757228712495095017U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 838379839663022790U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 2830743864262313606U;
            aOrbiterK = RotL64((aOrbiterK * 10173947177104802797U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 2146646527331684652U) + RotL64(aNonceWordA, 43U);
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 4629168181742174906U;
            aOrbiterG = RotL64((aOrbiterG * 9046124907945045131U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 1150129989168501777U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 619659995945229440U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13734821008174603409U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 8120315647582116952U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 13754584116324996165U;
            aOrbiterB = RotL64((aOrbiterB * 12295486140772079747U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 6084566798869999580U) + RotL64(aNonceWordF, 9U);
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 5731665119233722504U;
            aOrbiterI = RotL64((aOrbiterI * 5921510209025133639U), 35U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterB, 13U);
            aIngress = aIngress + (RotL64(aOrbiterI, 39U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterJ, 29U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 50U));
            aIngress = aIngress + RotL64(aOrbiterG, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aCross, 10U) + RotL64(aOrbiterK, 27U)) + aOrbiterD) + aWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterG, 48U)) + aOrbiterC);
            aWandererI = aWandererI + ((((RotL64(aIngress, 23U) + aOrbiterJ) + RotL64(aOrbiterG, 13U)) + RotL64(aCarry, 53U)) + aWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 47U) + aOrbiterH) + RotL64(aOrbiterB, 41U));
            aWandererA = aWandererA + ((RotL64(aIngress, 3U) + RotL64(aOrbiterA, 3U)) + aOrbiterB);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 37U) + RotL64(aOrbiterK, 19U)) + aOrbiterI) + RotL64(aNonceWordH, 5U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 19U) + aOrbiterB) + RotL64(aOrbiterC, 23U)) + RotL64(aCarry, 41U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 14U) + RotL64(aOrbiterJ, 57U)) + aOrbiterA);
            aWandererE = aWandererE + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterB, 34U)) + aOrbiterK) + RotL64(aNonceWordD, 46U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + (RotL64(aWandererK, 39U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererA);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 50U));
            aCarry = aCarry + RotL64(aWandererH, 27U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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

void TwistExpander_Karate_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xC856B4C91B6FCEFFULL + 0xC29095E330EA995DULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x840F47CA9679F8D9ULL + 0xEA013C39FDF840DDULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xA9E679F17906DED3ULL + 0x898010C3A2F8A2E4ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x8A3CB42765C0FD91ULL + 0x8280937A220DB5AAULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x9F5A15D697CB778DULL + 0x9701DD174A421FB1ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x94E5E8A07B378A49ULL + 0xCA9FFDA0D651040DULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x81EB064AC55550B9ULL + 0xF8F2DEA6D201B88FULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xE1890FB79261751BULL + 0xEB0AC110404EA4E8ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 13U) ^ RotL64(aNonceWordE, 29U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 4365U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneC[((aIndex + 5642U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 39U) ^ RotL64(aNonceWordH, 11U)) ^ RotL64(aNonceWordB, 19U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 8115U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 7359U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 35U) + RotL64(aPrevious, 56U)) ^ (RotL64(aIngress, 5U) ^ RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = ((aWandererH + RotL64(aIngress, 3U)) + 8866844335448071821U) + RotL64(aNonceWordC, 54U);
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 11U)) + RotL64(aCarry, 47U)) + 15159698739856430085U;
            aOrbiterF = (((aWandererF + RotL64(aCross, 30U)) + RotL64(aCarry, 29U)) + 9582805772989594633U) + aOrbiterAssignSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = ((aWandererG + RotL64(aScatter, 57U)) + 1438538239931588373U) + aOrbiterAssignSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterI = (((aWandererJ + RotL64(aIngress, 21U)) + RotL64(aCarry, 5U)) + 10862044156620436139U) + RotL64(aNonceWordB, 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 13682173320058164615U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 8351013291045977592U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5722336275651615473U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 15777857431516633916U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterB) ^ 16178966745333885377U) ^ aOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1]) ^ RotL64(aNonceWordG, 55U);
            aOrbiterE = RotL64((aOrbiterE * 7545129923202147703U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 9031889187993001617U) + RotL64(aNonceWordF, 17U);
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 6308472367425865347U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17118710301967158153U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 642109145903321046U) + aOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 9186268569255318035U;
            aOrbiterG = RotL64((aOrbiterG * 10714674348507516749U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 6091345356803675860U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 13218507921880873749U;
            aOrbiterI = RotL64((aOrbiterI * 15415157927185637717U), 11U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterG, 11U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 46U));
            aIngress = aIngress + RotL64(aOrbiterI, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 48U) + RotL64(aOrbiterE, 19U)) + aOrbiterB) + aWandererUpdateSaltD[((aIndex + 14U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 11U) + aOrbiterG) + RotL64(aOrbiterB, 11U)) + RotL64(aCarry, 11U)) + RotL64(aNonceWordA, 35U));
            aWandererH = aWandererH ^ ((((RotL64(aIngress, 3U) + RotL64(aOrbiterE, 60U)) + aOrbiterI) + RotL64(aNonceWordE, 29U)) + aWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 39U) + aOrbiterF) + RotL64(aOrbiterI, 39U)) + RotL64(aCarry, 29U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterG, 27U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererI, 29U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 3U) ^ RotL64(aNonceWordC, 41U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 15354U)) & S_BLOCK1], 30U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 15993U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 5U) ^ RotL64(aNonceWordD, 43U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 8887U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 14214U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 29U) + RotL64(aPrevious, 6U)) ^ (RotL64(aCarry, 41U) + RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 57U)) + RotL64(aCarry, 23U)) + 8604208734152026945U;
            aOrbiterK = (((aWandererG + RotL64(aCross, 39U)) + RotL64(aCarry, 5U)) + 1374329953253889829U) + aOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = ((aWandererC + RotL64(aScatter, 6U)) + 5779278910548228339U) + RotL64(aNonceWordB, 45U);
            aOrbiterD = ((aWandererB + RotL64(aIngress, 27U)) + RotL64(aCarry, 39U)) + 17670451230882805140U;
            aOrbiterJ = (((aWandererD + RotL64(aCross, 47U)) + 8193848740764866860U) + aOrbiterAssignSaltB[(((31U - aIndex) + 6U)) & S_SALT1]) + RotL64(aNonceWordE, 59U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 15801168428145650104U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 2584718176087499066U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5687189872016780831U), 29U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterD) + 14950366247822737997U) + aOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1]) + RotL64(aNonceWordC, 35U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 9779293225265670135U;
            aOrbiterJ = RotL64((aOrbiterJ * 11625969538497982117U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 8688968319288372383U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 13665723186950342601U;
            aOrbiterB = RotL64((aOrbiterB * 292035540396910837U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 9395428688359973510U) + aOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 2152719218018108418U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15271961483518392671U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 1350324137411377992U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 8729317951386057921U) ^ RotL64(aNonceWordH, 20U);
            aOrbiterD = RotL64((aOrbiterD * 6008790836417785083U), 57U);
            //
            aIngress = RotL64(aOrbiterD, 3U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterK, 34U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterB, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 27U) + aOrbiterJ) + RotL64(aOrbiterG, 30U));
            aWandererF = aWandererF + ((((RotL64(aPrevious, 5U) + aOrbiterB) + RotL64(aOrbiterK, 11U)) + RotL64(aCarry, 41U)) + RotL64(aNonceWordD, 21U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 13U) + aOrbiterD) + RotL64(aOrbiterK, 53U)) + aWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterJ, 41U)) + aOrbiterB) + RotL64(aCarry, 27U)) + RotL64(aNonceWordA, 19U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 56U) + aOrbiterD) + RotL64(aOrbiterG, 19U)) + aWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 46U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererC, 27U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 53U) ^ RotL64(aNonceWordA, 39U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 21558U)) & S_BLOCK1], 18U) ^ RotL64(aWorkLaneA[((aIndex + 24560U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 10U) ^ RotL64(aNonceWordH, 35U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 18676U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 16948U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aPrevious, 14U)) + (RotL64(aCross, 39U) ^ RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((((aWandererH + RotL64(aPrevious, 37U)) + RotL64(aCarry, 5U)) + 15045917390223766480U) + aOrbiterAssignSaltA[((aIndex + 27U)) & S_SALT1]) + RotL64(aNonceWordD, 3U);
            aOrbiterH = ((aWandererB + RotL64(aScatter, 13U)) + RotL64(aCarry, 51U)) + 10763054007033668758U;
            aOrbiterG = ((aWandererC + RotL64(aCross, 5U)) + 13190170142593666607U) + aOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterK = (((aWandererA + RotL64(aIngress, 56U)) + RotL64(aCarry, 21U)) + 9657025731441167065U) + RotL64(aNonceWordG, 22U);
            aOrbiterA = (aWandererG + RotL64(aCross, 29U)) + 11433367178975954211U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 17904920143996810366U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 3244383020512113283U;
            aOrbiterG = RotL64((aOrbiterG * 552521443123433353U), 39U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterF) + 6538815775171139091U) + aOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1]) + RotL64(aNonceWordA, 45U);
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 7195368312757976343U;
            aOrbiterH = RotL64((aOrbiterH * 10515679176134176565U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 18134430713910279374U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 6571776588427107976U) ^ RotL64(aNonceWordC, 7U);
            aOrbiterF = RotL64((aOrbiterF * 11916502085252589161U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 11830778129647517758U) + aOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 9793702760907767365U;
            aOrbiterK = RotL64((aOrbiterK * 4096246227968677179U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 2287235876793192036U) + aOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 8951959188326141794U;
            aOrbiterA = RotL64((aOrbiterA * 9968356718110753845U), 5U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterF, 4U);
            aIngress = aIngress + (RotL64(aOrbiterA, 29U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterH, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterK, 29U)) + aOrbiterF) + aWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aScatter, 51U) + aOrbiterK) + RotL64(aOrbiterG, 37U)) + RotL64(aCarry, 23U)) + RotL64(aNonceWordB, 27U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 12U) + aOrbiterH) + RotL64(aOrbiterF, 11U));
            aWandererH = aWandererH + (((((RotL64(aIngress, 39U) + RotL64(aOrbiterG, 58U)) + aOrbiterA) + RotL64(aCarry, 43U)) + RotL64(aNonceWordH, 31U)) + aWandererUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterG, 3U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 34U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + RotL64(aWandererA, 5U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordE, 57U) ^ RotL64(aNonceWordB, 5U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 26762U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31412U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 43U) ^ RotL64(aNonceWordF, 27U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 31076U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 29849U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 41U) ^ RotL64(aIngress, 53U)) + (RotL64(aCross, 26U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 53U)) + RotL64(aCarry, 19U)) + 14249093584376402677U;
            aOrbiterC = (((aWandererG + RotL64(aScatter, 21U)) + RotL64(aCarry, 57U)) + 8756965951816492264U) + aOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = (((aWandererK + RotL64(aIngress, 13U)) + RotL64(aCarry, 43U)) + 11221139480258176330U) + RotL64(aNonceWordA, 43U);
            aOrbiterE = (((aWandererF + RotL64(aCross, 36U)) + 17218894445564194851U) + aOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1]) + RotL64(aNonceWordD, 4U);
            aOrbiterD = (aWandererI + RotL64(aPrevious, 3U)) + 8064642692524949490U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 5822093203710704646U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 3217799620158102238U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2806328682494910635U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 2613757677892120843U) + aOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 13647481499551657237U;
            aOrbiterA = RotL64((aOrbiterA * 5517563514031899891U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 3545714196663685016U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 9735422670576621521U;
            aOrbiterE = RotL64((aOrbiterE * 7276207208162697249U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 3911046580637583767U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 9315984027042049203U) ^ aOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12568550776487242469U), 37U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterE) + 8926367674641729058U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]) + RotL64(aNonceWordG, 51U);
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 11035347490524961446U) ^ RotL64(aNonceWordH, 59U);
            aOrbiterD = RotL64((aOrbiterD * 10948288997163592463U), 19U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterA, 53U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + RotL64(aOrbiterD, 36U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aScatter, 21U) + RotL64(aOrbiterA, 14U)) + aOrbiterC) + RotL64(aCarry, 19U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 40U) + aOrbiterE) + RotL64(aOrbiterA, 5U));
            aWandererE = aWandererE + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterE, 51U)) + aOrbiterF) + RotL64(aNonceWordB, 37U)) + aWandererUpdateSaltD[((aIndex + 18U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 13U) + aOrbiterA) + RotL64(aOrbiterD, 39U));
            aWandererF = aWandererF + (((((RotL64(aIngress, 57U) + aOrbiterC) + RotL64(aOrbiterF, 23U)) + RotL64(aCarry, 39U)) + RotL64(aNonceWordC, 39U)) + aWandererUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 51U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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

void TwistExpander_Karate_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xE1EDF5FBBFDA36C9ULL + 0xF2F237D222BCEE94ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xD1EFF52FDF0B1CFFULL + 0x9956BE3FBBAC1FC2ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xA5F82780C3F23077ULL + 0x8A046D988D656832ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x8C5E743FB050F4F3ULL + 0xA00728499570B0E9ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xFEF62B84A6188FBDULL + 0xD417A05AD420FAD0ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xBAE8ECD11B3F9A67ULL + 0xD1E8150CEEC53C1AULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xB580EBD6EDB45421ULL + 0xCE9810895720CEFFULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x9CEBE40F84830B3DULL + 0x8778530429DE610DULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordA, 57U) ^ RotL64(aNonceWordH, 4U)) ^ RotL64(aNonceWordB, 41U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 2102U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 139U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 11U) ^ RotL64(aNonceWordD, 3U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 8140U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 6523U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 13U) + RotL64(aCross, 58U)) ^ (RotL64(aCarry, 27U) + RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererD + RotL64(aIngress, 35U)) + RotL64(aCarry, 43U)) + 3650233661228036955U;
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 57U)) + RotL64(aCarry, 29U)) + 11607036400067735729U;
            aOrbiterC = ((aWandererK + RotL64(aScatter, 51U)) + 3899614406903883035U) + aOrbiterAssignSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterA = (aWandererH + RotL64(aCross, 26U)) + 8159156925629965143U;
            aOrbiterE = ((aWandererG + RotL64(aScatter, 3U)) + 7148903913967261270U) + aOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = (((aWandererB + RotL64(aCross, 19U)) + RotL64(aCarry, 3U)) + 9161665622287517848U) + RotL64(aNonceWordH, 31U);
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 41U)) + 2981535013474059469U) + RotL64(aNonceWordC, 9U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 15812469008200319549U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 14687469489893270300U;
            aOrbiterC = RotL64((aOrbiterC * 14142363399696670451U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 6025209349511417063U) + RotL64(aNonceWordB, 44U);
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 12964750392311112676U;
            aOrbiterE = RotL64((aOrbiterE * 12955480283032701843U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 6572355895765394340U) + aOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 3542300121890027981U) ^ RotL64(aNonceWordF, 25U);
            aOrbiterI = RotL64((aOrbiterI * 11201491178181273935U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 6477175684045398359U) + aOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 1081388388827929314U;
            aOrbiterJ = RotL64((aOrbiterJ * 8752188637514143529U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 13754328481584620771U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 3684673342659575917U;
            aOrbiterK = RotL64((aOrbiterK * 6139923312873039143U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 6542045150319909445U) + aOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 5352102692424060388U) ^ aOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7385758355501860261U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 9110100774657340354U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 2813273684436269057U;
            aOrbiterB = RotL64((aOrbiterB * 10468759062594022273U), 57U);
            //
            aIngress = RotL64(aOrbiterI, 3U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterE, 47U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterB, 54U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterC, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 60U) + RotL64(aOrbiterK, 20U)) + aOrbiterI);
            aWandererD = aWandererD + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterB, 41U)) + aOrbiterJ) + RotL64(aCarry, 43U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterA, 3U)) + aOrbiterC) + RotL64(aNonceWordA, 13U));
            aWandererI = aWandererI + ((RotL64(aCross, 21U) + RotL64(aOrbiterC, 51U)) + aOrbiterK);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterJ, 57U)) + aOrbiterC) + RotL64(aNonceWordG, 55U));
            aWandererG = aWandererG + ((((RotL64(aIngress, 29U) + aOrbiterB) + RotL64(aOrbiterE, 35U)) + RotL64(aCarry, 5U)) + aWandererUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 35U) + aOrbiterE) + RotL64(aOrbiterJ, 27U)) + aWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 14U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererI, 53U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 13U) ^ RotL64(aNonceWordE, 50U)) ^ RotL64(aNonceWordB, 27U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 15236U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 10576U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 36U) ^ RotL64(aNonceWordC, 27U)) ^ RotL64(aNonceWordG, 11U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 13864U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 9332U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 3U) ^ RotL64(aPrevious, 38U)) ^ (RotL64(aIngress, 53U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = ((aWandererH + RotL64(aIngress, 11U)) + 16802219662864902427U) + aOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = (aWandererI + RotL64(aPrevious, 35U)) + 14332033461409490629U;
            aOrbiterF = ((aWandererK + RotL64(aCross, 53U)) + 8781794298640286845U) + RotL64(aNonceWordA, 27U);
            aOrbiterC = (((aWandererC + RotL64(aScatter, 5U)) + RotL64(aCarry, 51U)) + 8459933908074937264U) + RotL64(aNonceWordB, 35U);
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 19U)) + 1883580287986004426U;
            aOrbiterG = (((aWandererG + RotL64(aCross, 27U)) + RotL64(aCarry, 5U)) + 17500258188004626118U) + aOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = ((aWandererA + RotL64(aIngress, 44U)) + RotL64(aCarry, 39U)) + 7934811305150872870U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 6380363892361098905U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterE) ^ 12623079132626676910U) ^ aOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1]) ^ RotL64(aNonceWordH, 48U);
            aOrbiterF = RotL64((aOrbiterF * 12406671746344127399U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 10455208121949202703U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 8805532707916767629U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 666082374369701881U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 9161544391400377699U) + RotL64(aNonceWordD, 39U);
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 3501434325829663268U;
            aOrbiterC = RotL64((aOrbiterC * 7933545151293799637U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 651783304096081996U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 441505031509930622U;
            aOrbiterK = RotL64((aOrbiterK * 8045355432310956143U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 1771159983581326424U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 15227946417377695989U) ^ aOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1563141188972797601U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 4153717524193279095U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 4404521756523902829U;
            aOrbiterG = RotL64((aOrbiterG * 1410342912973206203U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 6231945075461813285U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 3864780227164426690U;
            aOrbiterB = RotL64((aOrbiterB * 18031353247480673617U), 57U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterE, 3U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 56U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 19U));
            aIngress = aIngress + RotL64(aOrbiterK, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 20U) + aOrbiterG) + RotL64(aOrbiterF, 27U));
            aWandererC = aWandererC + ((RotL64(aIngress, 41U) + RotL64(aOrbiterB, 19U)) + aOrbiterH);
            aWandererI = aWandererI ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterF, 51U)) + aOrbiterE) + aWandererUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterG, 3U)) + aOrbiterE) + RotL64(aCarry, 57U)) + RotL64(aNonceWordG, 61U));
            aWandererJ = aWandererJ ^ ((((RotL64(aPrevious, 13U) + aOrbiterK) + RotL64(aOrbiterG, 57U)) + RotL64(aNonceWordF, 47U)) + aWandererUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 5U) + RotL64(aOrbiterB, 43U)) + aOrbiterF) + RotL64(aCarry, 39U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterK, 12U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 41U) ^ aWandererK);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 34U));
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererH, 5U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 27U) ^ RotL64(aNonceWordB, 47U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 18538U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17806U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 23U) ^ RotL64(aNonceWordH, 3U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 24040U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 19776U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 51U) + RotL64(aIngress, 4U)) + (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (((aWandererC + RotL64(aScatter, 53U)) + RotL64(aCarry, 53U)) + 16124889768301047791U) + aOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 5U)) + 11912338587186717280U) + RotL64(aNonceWordC, 5U);
            aOrbiterD = (((aWandererA + RotL64(aPrevious, 11U)) + RotL64(aCarry, 35U)) + 8594012868813114354U) + RotL64(aNonceWordE, 41U);
            aOrbiterG = (((aWandererF + RotL64(aCross, 29U)) + RotL64(aCarry, 21U)) + 18281043566156682815U) + aOrbiterAssignSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = (aWandererK + RotL64(aScatter, 35U)) + 16853106130200942302U;
            aOrbiterH = (aWandererD + RotL64(aIngress, 41U)) + 2611212958619673086U;
            aOrbiterE = (aWandererE + RotL64(aCross, 22U)) + 18039472325066855180U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 14495785571345122046U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 4556063793412832418U;
            aOrbiterD = RotL64((aOrbiterD * 13166927543135467627U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 14896419970271244358U) + aOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 880028529183500036U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14228281807461251361U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 2379557167489415783U) + aOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 11854373946064529806U) ^ RotL64(aNonceWordB, 23U);
            aOrbiterF = RotL64((aOrbiterF * 150755294320438887U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 1487252775956449964U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 12777924204511625545U;
            aOrbiterG = RotL64((aOrbiterG * 1366019527386994789U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 15998631485222477969U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 8864212892296191613U;
            aOrbiterC = RotL64((aOrbiterC * 579242788050369815U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 17069347835763226743U) + aOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 7443008171694679791U) ^ RotL64(aNonceWordF, 43U);
            aOrbiterH = RotL64((aOrbiterH * 748894368884566607U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 17334256152350782002U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 8986626119086556393U;
            aOrbiterE = RotL64((aOrbiterE * 2258172145924120235U), 43U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterD, 13U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 52U));
            aIngress = aIngress + (RotL64(aOrbiterF, 29U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterC, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 57U) + aOrbiterC) + RotL64(aOrbiterE, 35U));
            aWandererE = aWandererE + ((((RotL64(aCross, 50U) + aOrbiterG) + RotL64(aOrbiterJ, 41U)) + RotL64(aCarry, 41U)) + aWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterD, 51U)) + aOrbiterG);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 43U) + aOrbiterF) + RotL64(aOrbiterC, 29U)) + RotL64(aNonceWordG, 7U)) + aWandererUpdateSaltD[((aIndex + 14U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 35U) + aOrbiterF) + RotL64(aOrbiterD, 4U));
            aWandererI = aWandererI + (((RotL64(aScatter, 21U) + RotL64(aOrbiterG, 13U)) + aOrbiterH) + RotL64(aCarry, 29U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterE, 57U)) + aOrbiterJ) + RotL64(aNonceWordA, 26U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererE);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 56U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + RotL64(aWandererF, 51U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 56U) ^ RotL64(aNonceWordA, 43U)) ^ RotL64(aNonceWordD, 5U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 30567U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30182U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 13U) ^ RotL64(aNonceWordG, 37U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 29749U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneD[((aIndex + 31630U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 26U) + RotL64(aIngress, 39U)) ^ (RotL64(aPrevious, 51U) + RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (((aWandererD + RotL64(aPrevious, 57U)) + 17711946802293254150U) + aOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1]) + RotL64(aNonceWordH, 41U);
            aOrbiterJ = (aWandererI + RotL64(aScatter, 50U)) + 16652362590489569378U;
            aOrbiterE = (((aWandererJ + RotL64(aIngress, 11U)) + RotL64(aCarry, 41U)) + 6972810344198183097U) + aOrbiterAssignSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterK = ((aWandererH + RotL64(aCross, 3U)) + RotL64(aCarry, 57U)) + 13117100889782940546U;
            aOrbiterC = (aWandererC + RotL64(aScatter, 19U)) + 13199305696782626591U;
            aOrbiterA = ((aWandererA + RotL64(aCross, 39U)) + 992156184392760945U) + RotL64(aNonceWordF, 53U);
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 29U)) + RotL64(aCarry, 19U)) + 13791265442074543880U;
            //
            aOrbiterI = (((aOrbiterI + aOrbiterJ) + 17057087245252294859U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]) + RotL64(aNonceWordD, 5U);
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 13444195995883541046U;
            aOrbiterE = RotL64((aOrbiterE * 13067044288608808777U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 6723678233676059420U) + aOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 7913379431208430475U;
            aOrbiterA = RotL64((aOrbiterA * 2295062944289127123U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 4481887195529300665U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 11892724101424384078U;
            aOrbiterJ = RotL64((aOrbiterJ * 3468639499716604111U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 7700902083270424194U) + aOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 1888001433557140271U;
            aOrbiterC = RotL64((aOrbiterC * 8975562955027025349U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 14996753906788986929U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 939004845422123765U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2507090308972292313U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 11922230289291941807U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 15681187459741147199U;
            aOrbiterK = RotL64((aOrbiterK * 10124947739653819101U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 9119043713532718155U) + RotL64(aNonceWordE, 23U);
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 8327697433992362166U;
            aOrbiterB = RotL64((aOrbiterB * 11157657162184304567U), 41U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterK, 57U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 37U));
            aIngress = aIngress + (RotL64(aOrbiterB, 13U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterC, 30U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aScatter, 57U) + aOrbiterJ) + RotL64(aOrbiterI, 11U)) + RotL64(aCarry, 37U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 35U) + aOrbiterE) + RotL64(aOrbiterJ, 3U));
            aWandererI = aWandererI + (((RotL64(aCross, 19U) + aOrbiterI) + RotL64(aOrbiterB, 42U)) + aWandererUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterB, 35U)) + aOrbiterC) + RotL64(aNonceWordB, 36U));
            aWandererE = aWandererE + (((RotL64(aCross, 13U) + RotL64(aOrbiterA, 21U)) + aOrbiterK) + RotL64(aCarry, 3U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 6U) + RotL64(aOrbiterA, 53U)) + aOrbiterB) + RotL64(aNonceWordG, 45U));
            aWandererD = aWandererD + (((RotL64(aScatter, 27U) + RotL64(aOrbiterA, 29U)) + aOrbiterI) + aWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 58U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererI, 19U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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

void TwistExpander_Karate_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xB97BEFEBB79F9831ULL + 0xC6A257444A6B2FEEULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xD396105FF64C7F4BULL + 0xD90CC71F1DD5BC8EULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xC9F513EE9A501197ULL + 0xCAA2913584369444ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xF70A5229F36B05F9ULL + 0xC0363F911F925F0EULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x8D5E83523E2F8AB1ULL + 0x87CFCEB39CF5373AULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xFA4AD2D74C327545ULL + 0x84535FD394A35712ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xE6F7B8F5FE313813ULL + 0xCC0E08CD95218D21ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xE4BC068194BFAFABULL + 0x837FB62531AE7563ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 52U) ^ RotL64(aNonceWordG, 43U));
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 4464U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 5720U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 35U) ^ RotL64(aNonceWordF, 5U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 3563U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 2966U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 19U) + RotL64(aCross, 35U)) ^ (RotL64(aIngress, 53U) + RotL64(aCarry, 4U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (((aWandererC + RotL64(aIngress, 27U)) + RotL64(aCarry, 41U)) + 12980104182836602177U) + aOrbiterAssignSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = (aWandererI + RotL64(aCross, 19U)) + 3172622203188863995U;
            aOrbiterF = (((aWandererE + RotL64(aPrevious, 43U)) + RotL64(aCarry, 11U)) + 1170974132219980203U) + aOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = ((aWandererB + RotL64(aScatter, 37U)) + RotL64(aCarry, 23U)) + 6035201940965047490U;
            aOrbiterC = (aWandererJ + RotL64(aIngress, 13U)) + 18033907118424996722U;
            aOrbiterD = ((aWandererD + RotL64(aScatter, 50U)) + 14604813424800580304U) + RotL64(aNonceWordF, 18U);
            aOrbiterJ = ((aWandererK + RotL64(aCross, 3U)) + 13720232492851066035U) + RotL64(aNonceWordH, 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 3902659710585257448U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 8331560652661619868U;
            aOrbiterF = RotL64((aOrbiterF * 11418103770615560205U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 4485014147538689794U) + aOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 168202636924512424U) ^ RotL64(aNonceWordA, 25U);
            aOrbiterC = RotL64((aOrbiterC * 13711020666131492091U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 16227825670092707848U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterG) ^ 4792781933944671365U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]) ^ RotL64(aNonceWordE, 7U);
            aOrbiterD = RotL64((aOrbiterD * 15859849676231455283U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 12636865372722601282U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 18198291399585556632U;
            aOrbiterJ = RotL64((aOrbiterJ * 18155803890313399795U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 3650053185419807206U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 5897288963905408776U;
            aOrbiterI = RotL64((aOrbiterI * 3706949366974086151U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 9922308113622901726U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 13352279749091561510U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4025213180483632557U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 14969461950939646117U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 10231661776135056651U;
            aOrbiterG = RotL64((aOrbiterG * 11284575051455238501U), 5U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterF, 37U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 43U));
            aIngress = aIngress + (RotL64(aOrbiterG, 60U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterJ, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aIngress, 37U) + RotL64(aOrbiterC, 21U)) + aOrbiterG) + RotL64(aCarry, 5U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterB, 51U)) + aOrbiterD);
            aWandererI = aWandererI + ((RotL64(aPrevious, 50U) + RotL64(aOrbiterG, 29U)) + aOrbiterI);
            aWandererE = aWandererE ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterC, 42U)) + aOrbiterB);
            aWandererD = aWandererD + (((((RotL64(aPrevious, 5U) + aOrbiterB) + RotL64(aOrbiterF, 57U)) + RotL64(aCarry, 47U)) + RotL64(aNonceWordB, 55U)) + aWandererUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 57U) + aOrbiterF) + RotL64(aOrbiterD, 5U)) + aWandererUpdateSaltF[((aIndex + 18U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 29U) + aOrbiterI) + RotL64(aOrbiterJ, 11U)) + RotL64(aNonceWordD, 13U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 41U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 34U));
            aCarry = aCarry + RotL64(aWandererJ, 23U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 19U) ^ RotL64(aNonceWordF, 53U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 12870U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneD[((aIndex + 15155U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 37U) ^ RotL64(aNonceWordD, 5U)) ^ RotL64(aNonceWordB, 21U));
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 12396U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((aIndex + 9966U)) & S_BLOCK1], 50U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aIngress, 23U)) + (RotL64(aPrevious, 37U) ^ RotL64(aCross, 10U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (((aWandererF + RotL64(aPrevious, 39U)) + RotL64(aCarry, 27U)) + 12311607308490066301U) + aOrbiterAssignSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 3U)) + 13100864684740679846U) + RotL64(aNonceWordE, 25U);
            aOrbiterI = ((aWandererI + RotL64(aCross, 29U)) + 13697304189274329704U) + aOrbiterAssignSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = ((aWandererG + RotL64(aIngress, 13U)) + 9047976902871216732U) + RotL64(aNonceWordC, 39U);
            aOrbiterK = (aWandererD + RotL64(aCross, 51U)) + 2147897579538537888U;
            aOrbiterB = ((aWandererA + RotL64(aScatter, 22U)) + RotL64(aCarry, 3U)) + 2072444829390996142U;
            aOrbiterE = ((aWandererK + RotL64(aIngress, 57U)) + RotL64(aCarry, 43U)) + 2129307836981020908U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 10663145333751112064U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 15019844390503785459U;
            aOrbiterI = RotL64((aOrbiterI * 7442321463110790449U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 5460865577557928142U) + aOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 15806522559993224197U) ^ aOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8722932687972240099U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 6361113778657833389U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 8306013884615042570U;
            aOrbiterA = RotL64((aOrbiterA * 8234258702656728667U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 4038420580499706912U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 11908091484457158973U;
            aOrbiterD = RotL64((aOrbiterD * 3964111175645156719U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 11133912466611921250U) + RotL64(aNonceWordH, 59U);
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 2469227904206936928U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2704438771198001599U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 13234017916788297295U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 9061117693840451988U;
            aOrbiterB = RotL64((aOrbiterB * 3637440416741459419U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 12013423690843812324U) + RotL64(aNonceWordG, 45U);
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 14371779015144617412U;
            aOrbiterE = RotL64((aOrbiterE * 3359568073302062667U), 23U);
            //
            aIngress = RotL64(aOrbiterE, 13U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 19U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + RotL64(aOrbiterK, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterE, 29U)) + aOrbiterI);
            aWandererK = aWandererK + ((((RotL64(aIngress, 29U) + aOrbiterB) + RotL64(aOrbiterD, 35U)) + RotL64(aCarry, 35U)) + aWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterI, 52U)) + aOrbiterA) + aWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 40U) + RotL64(aOrbiterD, 13U)) + aOrbiterF) + RotL64(aCarry, 19U)) + RotL64(aNonceWordA, 42U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterF, 21U)) + aOrbiterA) + RotL64(aNonceWordD, 29U));
            aWandererD = aWandererD + ((RotL64(aScatter, 53U) + RotL64(aOrbiterK, 3U)) + aOrbiterD);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterB, 41U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 18U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + RotL64(aWandererA, 23U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 19U) ^ RotL64(aNonceWordF, 11U)) ^ RotL64(aNonceWordH, 27U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 23089U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneA[((aIndex + 23466U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 11U) ^ RotL64(aNonceWordE, 34U)) ^ RotL64(aNonceWordC, 43U));
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 23267U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 19556U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 19U) + RotL64(aIngress, 5U)) + (RotL64(aCarry, 37U) ^ RotL64(aPrevious, 52U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (((aWandererB + RotL64(aCross, 23U)) + RotL64(aCarry, 53U)) + 8685374557928800912U) + RotL64(aNonceWordE, 43U);
            aOrbiterF = (aWandererF + RotL64(aPrevious, 41U)) + 3482312691892161229U;
            aOrbiterH = ((aWandererA + RotL64(aScatter, 14U)) + RotL64(aCarry, 19U)) + 6948130297389161165U;
            aOrbiterK = ((aWandererC + RotL64(aIngress, 5U)) + 5506385663788942690U) + aOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 47U)) + RotL64(aCarry, 39U)) + 17859982009307397161U;
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 35U)) + 9178488809207094043U) + RotL64(aNonceWordD, 13U);
            aOrbiterC = ((aWandererD + RotL64(aScatter, 57U)) + 1835479501226057169U) + aOrbiterAssignSaltB[((aIndex + 12U)) & S_SALT1];
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 5368101733632614939U) + aOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 9050459666576835422U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10351719549990259551U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 9042186993119635078U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 17528342580198295025U) ^ RotL64(aNonceWordF, 39U);
            aOrbiterF = RotL64((aOrbiterF * 14316671546614386775U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 6495418332558436882U) + RotL64(aNonceWordC, 23U);
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 8834495762667327342U;
            aOrbiterE = RotL64((aOrbiterE * 10783141541937645995U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 4364314196965690905U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 6357485231062120459U;
            aOrbiterK = RotL64((aOrbiterK * 289429584586504995U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 3321488322626415347U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 10817330671781848737U;
            aOrbiterI = RotL64((aOrbiterI * 15875919466358823335U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 17974092279281611763U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 2871472057292789157U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16104199340711015181U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 15187929795092006849U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 13482063681546475923U;
            aOrbiterC = RotL64((aOrbiterC * 14466266308157364963U), 11U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterG, 35U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 60U));
            aIngress = aIngress + RotL64(aOrbiterF, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aScatter, 11U) + aOrbiterG) + RotL64(aOrbiterI, 47U)) + RotL64(aNonceWordB, 41U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 29U) + aOrbiterG) + RotL64(aOrbiterC, 29U)) + aWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 53U) + RotL64(aOrbiterI, 21U)) + aOrbiterK) + aWandererUpdateSaltC[((aIndex + 6U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 3U) + aOrbiterI) + RotL64(aOrbiterE, 56U));
            aWandererC = aWandererC + (((RotL64(aScatter, 20U) + RotL64(aOrbiterI, 11U)) + aOrbiterC) + RotL64(aCarry, 53U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 35U) + aOrbiterF) + RotL64(aOrbiterC, 5U));
            aWandererI = aWandererI + ((((RotL64(aIngress, 47U) + aOrbiterH) + RotL64(aOrbiterG, 35U)) + RotL64(aCarry, 5U)) + RotL64(aNonceWordA, 18U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + (RotL64(aWandererA, 18U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + RotL64(aWandererB, 35U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 47U) ^ RotL64(aNonceWordA, 29U)) ^ RotL64(aNonceWordE, 4U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 26540U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneB[((aIndex + 28350U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 4U) ^ RotL64(aNonceWordF, 51U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30639U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 31021U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCarry, 11U)) + (RotL64(aCross, 24U) ^ RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 6U)) + RotL64(aCarry, 35U)) + 10805654776556844351U;
            aOrbiterH = ((aWandererG + RotL64(aScatter, 51U)) + 582794182442795335U) + aOrbiterAssignSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = ((aWandererC + RotL64(aCross, 57U)) + 2858343650974681068U) + aOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = ((aWandererK + RotL64(aIngress, 13U)) + 8189584049022064284U) + RotL64(aNonceWordH, 20U);
            aOrbiterB = ((aWandererI + RotL64(aCross, 43U)) + RotL64(aCarry, 23U)) + 1565100751996962893U;
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 19U)) + 8062028016947611891U) + RotL64(aNonceWordC, 39U);
            aOrbiterF = ((aWandererA + RotL64(aIngress, 29U)) + RotL64(aCarry, 5U)) + 8280504280578451745U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 11326869194491655350U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 1671695656567777163U;
            aOrbiterA = RotL64((aOrbiterA * 7511554500524257921U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 2349843105293943452U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 13015545152052004254U;
            aOrbiterJ = RotL64((aOrbiterJ * 1316662811685429983U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 16703354404749291869U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 8713231044374305801U) ^ aOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9242480982197688625U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 11118401674497783533U) + RotL64(aNonceWordG, 35U);
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 14857556493734710364U;
            aOrbiterB = RotL64((aOrbiterB * 3452566050389715195U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 12953419670951660965U) + RotL64(aNonceWordF, 17U);
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 12666121730825089017U;
            aOrbiterD = RotL64((aOrbiterD * 14049925256934142519U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 11075249639473053423U) + aOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 9374217688244187867U;
            aOrbiterI = RotL64((aOrbiterI * 5261156325627117877U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 17608340953291367867U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 13159437499327086340U;
            aOrbiterF = RotL64((aOrbiterF * 4882100944453534805U), 3U);
            //
            aIngress = RotL64(aOrbiterA, 5U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterD, 21U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterJ, 11U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterF, 44U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterD, 5U)) + aOrbiterA);
            aWandererB = aWandererB + (((RotL64(aCross, 27U) + aOrbiterI) + RotL64(aOrbiterJ, 43U)) + aWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 4U) + aOrbiterF) + RotL64(aOrbiterJ, 13U));
            aWandererK = aWandererK + (((RotL64(aIngress, 43U) + RotL64(aOrbiterF, 35U)) + aOrbiterH) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterH, 29U)) + aOrbiterB) + RotL64(aNonceWordB, 45U));
            aWandererG = aWandererG + (((RotL64(aCross, 57U) + aOrbiterI) + RotL64(aOrbiterH, 19U)) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ ((((RotL64(aScatter, 35U) + RotL64(aOrbiterB, 58U)) + aOrbiterA) + RotL64(aNonceWordA, 57U)) + aWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 36U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + RotL64(aWandererC, 23U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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

void TwistExpander_Karate_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xBC0963240B389A89ULL + 0x8E7D671042091271ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xB447316555BB3ECFULL + 0xC82B069E2E0D487AULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xE62B186A3D51C709ULL + 0x9CED5615CB7432EEULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xDB3120747415D607ULL + 0x85AA6D3E64376BACULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x8279CCC9DE0FEF51ULL + 0x9E666C917E13B69CULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xAC7DE5608FEC3C7BULL + 0x94F949CDB30F3779ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xE40D8044AE651AA7ULL + 0xFD4610FE89156A8EULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xF5F61DBA41BDF637ULL + 0x92E0E592FB234997ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 20U) ^ RotL64(aNonceWordB, 51U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 4004U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4790U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 5U) ^ RotL64(aNonceWordA, 57U)) ^ RotL64(aNonceWordH, 48U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4754U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 4725U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 37U) ^ RotL64(aIngress, 19U)) + (RotL64(aCross, 6U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (aWandererA + RotL64(aCross, 47U)) + 14249093584376402677U;
            aOrbiterG = (aWandererI + RotL64(aScatter, 18U)) + 8756965951816492264U;
            aOrbiterK = (aWandererD + RotL64(aIngress, 57U)) + 11221139480258176330U;
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 27U)) + RotL64(aCarry, 29U)) + 17218894445564194851U;
            aOrbiterH = (((aWandererB + RotL64(aCross, 21U)) + RotL64(aCarry, 19U)) + 8064642692524949490U) + aOrbiterAssignSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = (aWandererK + RotL64(aScatter, 35U)) + 5822093203710704646U;
            aOrbiterE = (aWandererF + RotL64(aIngress, 51U)) + 3217799620158102238U;
            aOrbiterC = (aWandererG + RotL64(aPrevious, 41U)) + 2613757677892120843U;
            aOrbiterD = ((aWandererJ + RotL64(aIngress, 30U)) + 13647481499551657237U) + aOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = (((aWandererC + RotL64(aScatter, 11U)) + RotL64(aCarry, 5U)) + 3545714196663685016U) + RotL64(aNonceWordC, 61U);
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 3U)) + 9735422670576621521U) + RotL64(aNonceWordF, 14U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 3911046580637583767U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 9315984027042049203U;
            aOrbiterK = RotL64((aOrbiterK * 12568550776487242469U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 8926367674641729058U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 11035347490524961446U) ^ aOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10948288997163592463U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 10748158733051120339U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 2467801787989056455U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12621934274702358977U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 9244415080474351390U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 8517784887959492079U) ^ RotL64(aNonceWordG, 51U);
            aOrbiterI = RotL64((aOrbiterI * 17022899813765884147U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 8409307332803038455U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 11043806021873232950U;
            aOrbiterE = RotL64((aOrbiterE * 8294888329708842989U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 17512395828450251457U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 16849067939795823992U;
            aOrbiterD = RotL64((aOrbiterD * 9361991804481514337U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 17541946638063238056U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 11430501673960586718U;
            aOrbiterA = RotL64((aOrbiterA * 15074409630605450091U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 78307505705383302U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 4834528975263832983U;
            aOrbiterG = RotL64((aOrbiterG * 17245673681686752861U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 9647985402149698269U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 6610247710757518931U) ^ RotL64(aNonceWordE, 7U);
            aOrbiterH = RotL64((aOrbiterH * 8672486173272686859U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 2706696306041774372U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 9519896513600816252U;
            aOrbiterC = RotL64((aOrbiterC * 7468605169665549731U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 14647351223431646222U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 14249093584376402677U;
            aOrbiterJ = RotL64((aOrbiterJ * 8296105266618697281U), 35U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterC, 41U);
            aIngress = aIngress + (RotL64(aOrbiterH, 24U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterJ, 51U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 39U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 35U));
            aIngress = aIngress + RotL64(aOrbiterD, 30U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aPrevious, 27U) + aOrbiterJ) + RotL64(aOrbiterK, 47U)) + aWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 14U) + RotL64(aOrbiterB, 43U)) + aOrbiterC);
            aWandererK = aWandererK + ((((RotL64(aCross, 21U) + RotL64(aOrbiterH, 53U)) + aOrbiterC) + RotL64(aCarry, 53U)) + RotL64(aNonceWordA, 25U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterJ, 58U)) + aOrbiterI) + RotL64(aNonceWordD, 9U));
            aWandererF = aWandererF + ((RotL64(aScatter, 51U) + RotL64(aOrbiterA, 13U)) + aOrbiterG);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 5U) + aOrbiterH) + RotL64(aOrbiterF, 23U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterB, 41U)) + aOrbiterJ);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 41U) + aOrbiterD) + RotL64(aOrbiterH, 3U));
            aWandererA = aWandererA + (((RotL64(aCross, 29U) + RotL64(aOrbiterF, 27U)) + aOrbiterJ) + aWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 24U) + aOrbiterA) + RotL64(aOrbiterE, 35U));
            aWandererG = aWandererG + (((RotL64(aIngress, 47U) + aOrbiterI) + RotL64(aOrbiterA, 60U)) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererI, 46U) ^ aWandererF);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 53U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 5U));
            aCarry = aCarry + (RotL64(aWandererK, 41U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererH, 21U);
            aCarry = aCarry + RotL64(aIngress, 50U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordE, 21U) ^ RotL64(aNonceWordG, 30U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 12649U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((aIndex + 12844U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 23U) ^ RotL64(aNonceWordB, 11U)) ^ RotL64(aNonceWordC, 34U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8754U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 15203U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 26U) ^ RotL64(aIngress, 53U)) + (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (aWandererC + RotL64(aScatter, 56U)) + 8793908991006073956U;
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 21U)) + RotL64(aCarry, 47U)) + 2932916283348441943U;
            aOrbiterI = (((aWandererB + RotL64(aPrevious, 41U)) + RotL64(aCarry, 13U)) + 11069042087940968262U) + RotL64(aNonceWordG, 35U);
            aOrbiterD = (aWandererE + RotL64(aCross, 5U)) + 14369628676782894441U;
            aOrbiterG = (aWandererH + RotL64(aPrevious, 29U)) + 8602903272780978282U;
            aOrbiterE = (aWandererA + RotL64(aCross, 3U)) + 3827036107178568820U;
            aOrbiterH = (aWandererI + RotL64(aIngress, 35U)) + 8905245209036772489U;
            aOrbiterA = ((aWandererD + RotL64(aScatter, 51U)) + 13331387530760017893U) + RotL64(aNonceWordH, 45U);
            aOrbiterF = (aWandererJ + RotL64(aPrevious, 48U)) + 9880107580289737823U;
            aOrbiterK = ((aWandererK + RotL64(aScatter, 43U)) + 10199619040626900278U) + aOrbiterAssignSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = (((aWandererG + RotL64(aCross, 11U)) + RotL64(aCarry, 27U)) + 2466307560891374281U) + aOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 13973403407981259448U) + RotL64(aNonceWordD, 11U);
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 2851460278409385243U;
            aOrbiterI = RotL64((aOrbiterI * 11226902976321781743U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 10365453393815690776U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 2382382358987358791U;
            aOrbiterJ = RotL64((aOrbiterJ * 481563628980705781U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 5058198848163792422U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 10500434740387593487U;
            aOrbiterG = RotL64((aOrbiterG * 5946747708776079787U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 11289798395177667084U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 14327152153231286666U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 18155778059595245561U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 8065137263811956313U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 3865153574847924816U) ^ aOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9495741102667755161U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 18102279969722473375U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 6306428427188742325U;
            aOrbiterB = RotL64((aOrbiterB * 17826782872351406167U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 16953348204663693724U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 11950791817032898613U;
            aOrbiterD = RotL64((aOrbiterD * 1498946055469611133U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 11980823193543752994U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 17845490308799454871U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16385153013485463791U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 5566398755702887071U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 10308378271388889968U;
            aOrbiterA = RotL64((aOrbiterA * 142732084484961281U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 6717846700455219260U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 8297225372883997017U;
            aOrbiterK = RotL64((aOrbiterK * 14102812043481327907U), 53U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterI) + 12249337046267666603U) + aOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1]) + RotL64(aNonceWordF, 55U);
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 8793908991006073956U;
            aOrbiterC = RotL64((aOrbiterC * 5851229209188473467U), 21U);
            //
            aIngress = RotL64(aOrbiterC, 21U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 58U));
            aIngress = aIngress + (RotL64(aOrbiterH, 37U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterG, 43U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterF, 19U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterJ, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aPrevious, 21U) + aOrbiterB) + RotL64(aOrbiterC, 26U)) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 23U) + aOrbiterB) + RotL64(aOrbiterD, 13U));
            aWandererA = aWandererA + ((RotL64(aScatter, 41U) + aOrbiterG) + RotL64(aOrbiterI, 39U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 3U) + aOrbiterD) + RotL64(aOrbiterK, 43U)) + RotL64(aNonceWordB, 34U));
            aWandererF = aWandererF + ((RotL64(aScatter, 27U) + RotL64(aOrbiterA, 23U)) + aOrbiterJ);
            aWandererI = aWandererI ^ ((((RotL64(aIngress, 60U) + aOrbiterC) + RotL64(aOrbiterH, 51U)) + RotL64(aNonceWordA, 19U)) + aWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterE, 11U)) + aOrbiterJ);
            aWandererH = aWandererH ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterE, 36U)) + aOrbiterA);
            aWandererK = aWandererK + (((RotL64(aIngress, 13U) + RotL64(aOrbiterF, 21U)) + aOrbiterH) + RotL64(aCarry, 13U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterE, 29U)) + aOrbiterG) + aWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aScatter, 52U) + RotL64(aOrbiterC, 57U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 54U));
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 36U));
            aCarry = aCarry + RotL64(aWandererI, 21U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordE, 53U) ^ RotL64(aNonceWordH, 13U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 16549U)) & S_BLOCK1], 38U) ^ RotL64(aOperationLaneA[((aIndex + 17698U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 21U) ^ RotL64(aNonceWordG, 60U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 21249U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneC[((aIndex + 20407U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 11U) ^ RotL64(aCross, 51U)) ^ (RotL64(aCarry, 39U) + RotL64(aIngress, 24U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (((aWandererA + RotL64(aPrevious, 18U)) + RotL64(aCarry, 35U)) + 1708250618750199233U) + RotL64(aNonceWordF, 11U);
            aOrbiterJ = (aWandererI + RotL64(aCross, 13U)) + 12009147777553691142U;
            aOrbiterA = ((aWandererK + RotL64(aScatter, 53U)) + 8393982703399156592U) + aOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = (aWandererJ + RotL64(aIngress, 21U)) + 3247327098356831221U;
            aOrbiterB = (((aWandererH + RotL64(aCross, 36U)) + RotL64(aCarry, 3U)) + 3403590155376353737U) + RotL64(aNonceWordB, 18U);
            aOrbiterE = (aWandererE + RotL64(aIngress, 43U)) + 18197244558104735044U;
            aOrbiterI = ((aWandererD + RotL64(aScatter, 47U)) + 3096253642040701606U) + aOrbiterAssignSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterF = (aWandererG + RotL64(aPrevious, 27U)) + 8012692688785412179U;
            aOrbiterD = ((aWandererC + RotL64(aScatter, 5U)) + RotL64(aCarry, 43U)) + 17531946907545680745U;
            aOrbiterK = (aWandererB + RotL64(aCross, 39U)) + 17687695944270225817U;
            aOrbiterC = (aWandererF + RotL64(aIngress, 41U)) + 16147773866007628769U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 18244641303026196497U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 8839160526348897457U) ^ RotL64(aNonceWordA, 37U);
            aOrbiterA = RotL64((aOrbiterA * 14268021129087663397U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 10599266240854068246U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 2056723540756216155U;
            aOrbiterE = RotL64((aOrbiterE * 13311591601230386375U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 4629354220460621284U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 9505955649473204942U;
            aOrbiterJ = RotL64((aOrbiterJ * 17775391885312236187U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 17078153810088721310U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 9470436761716263000U;
            aOrbiterB = RotL64((aOrbiterB * 5431855497250357229U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 3305863413630104742U) + aOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 14377172434239576161U;
            aOrbiterF = RotL64((aOrbiterF * 6880176890091033423U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 415687827894226513U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 16975319836893760993U) ^ RotL64(aNonceWordC, 31U);
            aOrbiterK = RotL64((aOrbiterK * 6597144958013976445U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 12707054129431596074U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 8974182792497231239U) ^ aOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7874658957269462717U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 10826131924322955095U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 4168545139712703154U;
            aOrbiterG = RotL64((aOrbiterG * 10305904857550051705U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 4539070253658625193U) + aOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 3737870219498561326U) ^ aOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13130847633918921393U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 11563084648810555040U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 7410695535361901473U;
            aOrbiterD = RotL64((aOrbiterD * 7540855656023807389U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 6687453696858775037U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 1708250618750199233U;
            aOrbiterC = RotL64((aOrbiterC * 13104250803527718135U), 21U);
            //
            aIngress = RotL64(aOrbiterH, 19U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterF, 54U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterG, 21U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterK, 41U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterI, 35U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterA, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aScatter, 29U) + aOrbiterB) + RotL64(aOrbiterA, 23U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterH, 57U)) + aOrbiterE);
            aWandererI = aWandererI ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterF, 37U)) + aOrbiterA) + aWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aIngress, 43U) + RotL64(aOrbiterE, 54U)) + aOrbiterD) + RotL64(aCarry, 3U)) + RotL64(aNonceWordE, 9U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterA, 43U)) + aOrbiterI);
            aWandererB = aWandererB + ((RotL64(aIngress, 5U) + aOrbiterK) + RotL64(aOrbiterJ, 41U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterG, 5U)) + aOrbiterJ) + aWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterE, 51U)) + aOrbiterG) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 40U) + RotL64(aOrbiterH, 10U)) + aOrbiterD);
            aWandererC = aWandererC + (((RotL64(aPrevious, 13U) + aOrbiterC) + RotL64(aOrbiterJ, 19U)) + RotL64(aNonceWordD, 5U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 47U) + aOrbiterB) + RotL64(aOrbiterI, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 14U) ^ aWandererA);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 29U));
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererB, 5U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererI, 51U);
            aCarry = aCarry + RotL64(aIngress, 44U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 60U) ^ RotL64(aNonceWordB, 11U)) ^ RotL64(aNonceWordA, 41U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 24991U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 25576U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 35U) ^ RotL64(aNonceWordH, 13U)) ^ RotL64(aNonceWordG, 57U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 26606U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((aIndex + 31168U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aIngress, 21U)) ^ (RotL64(aCarry, 56U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (((aWandererA + RotL64(aScatter, 19U)) + RotL64(aCarry, 57U)) + 3248574644570178787U) + RotL64(aNonceWordF, 15U);
            aOrbiterD = ((aWandererJ + RotL64(aCross, 57U)) + RotL64(aCarry, 23U)) + 4506961512959200024U;
            aOrbiterH = ((aWandererB + RotL64(aIngress, 13U)) + RotL64(aCarry, 29U)) + 8423739774540738590U;
            aOrbiterE = (aWandererG + RotL64(aPrevious, 5U)) + 6593975869641735337U;
            aOrbiterG = (aWandererI + RotL64(aCross, 60U)) + 16441716090557369103U;
            aOrbiterC = ((aWandererH + RotL64(aIngress, 39U)) + 7936601450453207914U) + aOrbiterAssignSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = (aWandererD + RotL64(aPrevious, 29U)) + 13333752583560167065U;
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 43U)) + 8013703284795432973U) + RotL64(aNonceWordD, 22U);
            aOrbiterA = (aWandererK + RotL64(aPrevious, 52U)) + 2349852779887439236U;
            aOrbiterI = (aWandererC + RotL64(aScatter, 37U)) + 5318539364763284138U;
            aOrbiterK = ((aWandererE + RotL64(aCross, 23U)) + 11450957608502944376U) + aOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 9058992558327552687U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 632095686920230926U) ^ aOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12460364388358520799U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 14734218428913777098U) + RotL64(aNonceWordB, 5U);
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 16344357661370784442U;
            aOrbiterG = RotL64((aOrbiterG * 15049472842002138369U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 2981145363531184308U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 14176472085175714494U;
            aOrbiterC = RotL64((aOrbiterC * 2584623327412130939U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 11198457590069700889U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 952584436750426828U;
            aOrbiterF = RotL64((aOrbiterF * 1165713888651280355U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 4311591763498985972U) + aOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 16194341833989936369U;
            aOrbiterJ = RotL64((aOrbiterJ * 9997934560195932575U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 7560794022401107431U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 10683789740265711603U;
            aOrbiterA = RotL64((aOrbiterA * 15637823045351977883U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 11614366395125937178U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 10750771385100564416U;
            aOrbiterI = RotL64((aOrbiterI * 4987921274272444283U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 2934697034132204529U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 4646873794658020363U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10555456865641580175U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 7913681837683568905U) + RotL64(aNonceWordA, 29U);
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 17603563535330106340U;
            aOrbiterB = RotL64((aOrbiterB * 17882943067522319671U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 15375641415139193079U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 17059712718085411887U;
            aOrbiterD = RotL64((aOrbiterD * 13722089235751208215U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 14022558453716067200U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 3248574644570178787U;
            aOrbiterE = RotL64((aOrbiterE * 15249135451439374621U), 23U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterA, 29U);
            aIngress = aIngress + (RotL64(aOrbiterI, 37U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + (RotL64(aOrbiterC, 53U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterD, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aPrevious, 5U) + aOrbiterE) + RotL64(aOrbiterK, 27U)) + RotL64(aNonceWordC, 27U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterA, 12U)) + aOrbiterE);
            aWandererI = aWandererI + ((RotL64(aScatter, 57U) + aOrbiterA) + RotL64(aOrbiterD, 43U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterI, 29U)) + aOrbiterA) + RotL64(aNonceWordH, 19U));
            aWandererA = aWandererA + (((RotL64(aCross, 44U) + RotL64(aOrbiterA, 53U)) + aOrbiterJ) + aWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterK, 41U)) + aOrbiterF);
            aWandererG = aWandererG + (((RotL64(aScatter, 51U) + aOrbiterC) + RotL64(aOrbiterF, 57U)) + RotL64(aCarry, 43U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 47U) + aOrbiterB) + RotL64(aOrbiterH, 24U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterF, 21U)) + aOrbiterI) + RotL64(aCarry, 53U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterD, 47U)) + aOrbiterB) + aWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aCross, 24U) + RotL64(aOrbiterH, 35U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 29U));
            aCarry = aCarry + (RotL64(aWandererD, 26U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererJ, 58U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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

void TwistExpander_Karate_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x8FB684C2323AE1D5ULL + 0xE163EA1BC462AE73ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x9DD72B52D4A645DDULL + 0xA69BC3D1EB148212ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xFD6B99CB16155C37ULL + 0xE833B018F9C2C567ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xE4A42FDC5659F9FDULL + 0xD4F1E8CB7D30E334ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xACBBAFD4BB093B53ULL + 0xB0EE828DD1C5A9B2ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xF775D29311C765BDULL + 0x897F8B162FD16A3EULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xFF99469EAAE5111BULL + 0x85740857B498172CULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x9BC8181DE2AEEE79ULL + 0xFDB97DF3FAF9F9BDULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 3U) ^ RotL64(aNonceWordE, 53U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 3011U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 3279U)) & S_BLOCK1], 26U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 37U) ^ RotL64(aNonceWordC, 13U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 2396U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 2017U)) & S_BLOCK1], 22U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 41U) + RotL64(aIngress, 19U)) + (RotL64(aCross, 53U) ^ RotL64(aPrevious, 6U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (((aWandererE + RotL64(aCross, 43U)) + RotL64(aCarry, 19U)) + 12535417189990029950U) + RotL64(aNonceWordB, 51U);
            aOrbiterB = ((aWandererA + RotL64(aIngress, 39U)) + 6204401443676390273U) + aOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = (aWandererI + RotL64(aScatter, 58U)) + 869613505613154672U;
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 27U)) + 15053590879563855802U) + aOrbiterAssignSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 53U)) + RotL64(aCarry, 3U)) + 13338989605204591428U;
            aOrbiterG = (aWandererG + RotL64(aScatter, 47U)) + 18306470022403825392U;
            aOrbiterH = (aWandererC + RotL64(aCross, 20U)) + 1150696349434090218U;
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 35U)) + RotL64(aCarry, 27U)) + 13549541786420596437U;
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 3U)) + 14302878430259588461U) + RotL64(aNonceWordF, 7U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 4660437084477165225U) + aOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 1653628537860912069U;
            aOrbiterE = RotL64((aOrbiterE * 2624835201155303123U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 5594199757006711631U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 11008472193138708891U;
            aOrbiterG = RotL64((aOrbiterG * 13645764762027798301U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 3668516817279364310U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 128159531749679984U;
            aOrbiterI = RotL64((aOrbiterI * 4523246859249826987U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 6378674346113979108U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 11438762460659123362U) ^ aOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2733309638158283953U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 10624263004446482910U) + RotL64(aNonceWordC, 5U);
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 12546839706919241411U;
            aOrbiterD = RotL64((aOrbiterD * 11468326687628079347U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 8466639576503293921U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 5828694979857951504U) ^ aOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7835487310289634515U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 16496305151014092976U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 589464613876410567U) ^ RotL64(aNonceWordH, 47U);
            aOrbiterH = RotL64((aOrbiterH * 13190816610718051897U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 4168532743415647825U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 15944887793736489375U;
            aOrbiterB = RotL64((aOrbiterB * 17273403561158196717U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 11642456814106259483U) + aOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 1609897693632334867U;
            aOrbiterJ = RotL64((aOrbiterJ * 12912773555616819941U), 57U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterH, 57U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 11U));
            aIngress = aIngress + (RotL64(aOrbiterG, 50U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 53U));
            aIngress = aIngress + RotL64(aOrbiterD, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aIngress, 24U) + RotL64(aOrbiterI, 23U)) + aOrbiterF) + aWandererUpdateSaltD[((aIndex + 20U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aCross, 13U) + RotL64(aOrbiterC, 37U)) + aOrbiterB) + RotL64(aCarry, 27U)) + aWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 57U) + aOrbiterJ) + RotL64(aOrbiterF, 47U));
            aWandererG = aWandererG + (((RotL64(aScatter, 43U) + aOrbiterB) + RotL64(aOrbiterD, 42U)) + RotL64(aNonceWordD, 41U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 53U) + aOrbiterE) + RotL64(aOrbiterG, 57U));
            aWandererE = aWandererE + ((RotL64(aCross, 3U) + aOrbiterJ) + RotL64(aOrbiterB, 13U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 39U) + aOrbiterH) + RotL64(aOrbiterI, 3U)) + RotL64(aNonceWordG, 18U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 47U) + aOrbiterE) + RotL64(aOrbiterF, 18U)) + RotL64(aCarry, 13U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 18U) + aOrbiterF) + RotL64(aOrbiterC, 29U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 23U));
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 51U));
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererB, 47U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 19U) ^ RotL64(aNonceWordE, 41U)) ^ RotL64(aNonceWordG, 27U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 5658U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneD[((aIndex + 7294U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 27U) ^ RotL64(aNonceWordB, 39U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 5806U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneB[((aIndex + 10408U)) & S_BLOCK1], 10U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 41U) + RotL64(aCarry, 56U)) ^ (RotL64(aCross, 5U) + RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 28U)) + RotL64(aCarry, 51U)) + 77518479758428414U;
            aOrbiterE = (aWandererK + RotL64(aIngress, 47U)) + 4832061802166300011U;
            aOrbiterD = ((aWandererB + RotL64(aScatter, 43U)) + RotL64(aCarry, 23U)) + 11695291171006574112U;
            aOrbiterA = (aWandererJ + RotL64(aCross, 13U)) + 7467412817843260094U;
            aOrbiterC = ((aWandererC + RotL64(aScatter, 52U)) + 17801484124471154757U) + RotL64(aNonceWordC, 9U);
            aOrbiterJ = (((aWandererE + RotL64(aPrevious, 39U)) + 5555455638503958639U) + aOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1]) + RotL64(aNonceWordA, 53U);
            aOrbiterF = ((aWandererF + RotL64(aCross, 23U)) + 5669470540733721606U) + aOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = ((aWandererA + RotL64(aIngress, 5U)) + RotL64(aCarry, 43U)) + 3042388456327784163U;
            aOrbiterH = (aWandererI + RotL64(aScatter, 19U)) + 2236734925228156691U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 14459720401528685450U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 4814967631216658856U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 18288097536171386643U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 16950679344449075945U) + aOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 6262238639302011050U;
            aOrbiterC = RotL64((aOrbiterC * 9942659897425088183U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 3522256359074996724U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 12524717897707074242U) ^ RotL64(aNonceWordD, 4U);
            aOrbiterF = RotL64((aOrbiterF * 6787771338063891989U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 13891759914865623828U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 11910250571469028666U;
            aOrbiterI = RotL64((aOrbiterI * 12311343917878428995U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 2240189915640314069U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 5365912986308810837U;
            aOrbiterH = RotL64((aOrbiterH * 15133972552032469957U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 9323732721344489753U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 13087326560957916553U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14659491687401151733U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 16398238057564892809U) + RotL64(aNonceWordH, 29U);
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 11517870519285159224U;
            aOrbiterA = RotL64((aOrbiterA * 1501848878469712681U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 7758285512254776734U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 17475149091906684720U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6015816725428299273U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 2051631493975035243U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 11684740065349595315U;
            aOrbiterE = RotL64((aOrbiterE * 10918975496337269197U), 35U);
            //
            aIngress = RotL64(aOrbiterK, 44U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 23U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 39U));
            aIngress = aIngress + RotL64(aOrbiterJ, 30U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aCross, 23U) + aOrbiterD) + RotL64(aOrbiterK, 6U)) + RotL64(aCarry, 5U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 34U) + RotL64(aOrbiterA, 43U)) + aOrbiterC);
            aWandererB = aWandererB + (((RotL64(aIngress, 39U) + aOrbiterC) + RotL64(aOrbiterE, 23U)) + RotL64(aNonceWordE, 39U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 53U) + aOrbiterF) + RotL64(aOrbiterJ, 51U));
            aWandererI = aWandererI + ((((RotL64(aIngress, 19U) + aOrbiterE) + RotL64(aOrbiterH, 35U)) + RotL64(aCarry, 47U)) + aWandererUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterD, 30U)) + aOrbiterA);
            aWandererD = aWandererD + (((RotL64(aCross, 6U) + RotL64(aOrbiterE, 47U)) + aOrbiterI) + aWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterH, 39U)) + aOrbiterF) + RotL64(aNonceWordF, 45U));
            aWandererE = aWandererE + ((RotL64(aScatter, 47U) + RotL64(aOrbiterE, 57U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererI, 54U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererK);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererB, 23U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordE, 29U) ^ RotL64(aNonceWordH, 18U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 13660U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 15903U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 57U) ^ RotL64(aNonceWordB, 3U)) ^ RotL64(aNonceWordD, 30U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 12559U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneC[((aIndex + 13352U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 6U) ^ RotL64(aPrevious, 27U)) + (RotL64(aCross, 53U) + RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((aWandererI + RotL64(aScatter, 27U)) + RotL64(aCarry, 41U)) + 18255347001097480328U;
            aOrbiterE = (aWandererD + RotL64(aPrevious, 51U)) + 13679246790311505735U;
            aOrbiterI = ((((aWandererH + RotL64(aCross, 37U)) + RotL64(aCarry, 51U)) + 10565839529765027116U) + aOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1]) + RotL64(aNonceWordB, 11U);
            aOrbiterC = (aWandererB + RotL64(aIngress, 14U)) + 14327172566224769901U;
            aOrbiterH = ((aWandererK + RotL64(aScatter, 5U)) + 16239024612038195174U) + RotL64(aNonceWordF, 3U);
            aOrbiterG = (aWandererF + RotL64(aIngress, 47U)) + 13800012174212131890U;
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 19U)) + RotL64(aCarry, 23U)) + 13900288860157577583U;
            aOrbiterB = ((aWandererG + RotL64(aCross, 10U)) + 4144386119777112740U) + aOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = (aWandererC + RotL64(aIngress, 43U)) + 3154558262670631372U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 7456728543137614001U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 11709519851158935384U;
            aOrbiterI = RotL64((aOrbiterI * 7016689518570071587U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 15607438907832240304U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 9276575329661725624U;
            aOrbiterA = RotL64((aOrbiterA * 8879744070762412745U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 6459435969129449226U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 6442382118416542275U;
            aOrbiterC = RotL64((aOrbiterC * 2921027306686588233U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 12117432107282150865U) + RotL64(aNonceWordE, 61U);
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 6831279293184793243U;
            aOrbiterE = RotL64((aOrbiterE * 2435360641135249073U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 9520022957804572889U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 8322178689474588679U) ^ RotL64(aNonceWordC, 12U);
            aOrbiterH = RotL64((aOrbiterH * 1627707191467537115U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 4162401591586869316U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 8994015844714895961U;
            aOrbiterG = RotL64((aOrbiterG * 15421910378057951895U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 10038095909727959633U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 17756404450592957616U) ^ aOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14255952184627347295U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 3379089265413427719U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 11341713098678108441U;
            aOrbiterB = RotL64((aOrbiterB * 2500587373161411961U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 4030296130743454165U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 6332387792111212064U) ^ aOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16490982218150897861U), 39U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterB, 39U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 18U));
            aIngress = aIngress + (RotL64(aOrbiterC, 43U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterF, 3U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterA, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterF, 57U)) + aOrbiterI);
            aWandererF = aWandererF + (((RotL64(aScatter, 19U) + RotL64(aOrbiterI, 5U)) + aOrbiterA) + RotL64(aNonceWordG, 25U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 60U) + RotL64(aOrbiterG, 38U)) + aOrbiterC) + aWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 41U) + RotL64(aOrbiterI, 43U)) + aOrbiterC);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterH, 13U)) + aOrbiterC);
            aWandererE = aWandererE + (((((RotL64(aScatter, 29U) + aOrbiterA) + RotL64(aOrbiterE, 29U)) + RotL64(aCarry, 13U)) + RotL64(aNonceWordH, 49U)) + aWandererUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterD, 18U)) + aOrbiterA);
            aWandererK = aWandererK + (((RotL64(aIngress, 24U) + RotL64(aOrbiterB, 53U)) + aOrbiterD) + RotL64(aCarry, 37U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 53U) + aOrbiterI) + RotL64(aOrbiterB, 23U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererE, 38U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererB, 41U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 20U) ^ RotL64(aNonceWordC, 29U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 17580U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((aIndex + 18422U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 13U) ^ RotL64(aNonceWordD, 23U)) ^ RotL64(aNonceWordF, 3U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18918U)) & S_BLOCK1], 42U) ^ RotL64(aOperationLaneD[((aIndex + 19023U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 35U) ^ RotL64(aIngress, 23U)) + (RotL64(aPrevious, 11U) ^ RotL64(aCross, 58U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((aWandererE + RotL64(aCross, 3U)) + RotL64(aCarry, 3U)) + 1210605127156905516U;
            aOrbiterA = (((aWandererK + RotL64(aIngress, 39U)) + 11964595428173569519U) + aOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1]) + RotL64(aNonceWordA, 21U);
            aOrbiterI = (((aWandererG + RotL64(aPrevious, 18U)) + RotL64(aCarry, 13U)) + 16277319029916258482U) + aOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = (aWandererJ + RotL64(aScatter, 11U)) + 12369497463101824572U;
            aOrbiterE = ((aWandererB + RotL64(aIngress, 23U)) + RotL64(aCarry, 53U)) + 6201248574067068202U;
            aOrbiterG = ((aWandererF + RotL64(aCross, 35U)) + 1727477025667206661U) + RotL64(aNonceWordC, 52U);
            aOrbiterK = (aWandererA + RotL64(aPrevious, 53U)) + 1404510627789806851U;
            aOrbiterF = (aWandererI + RotL64(aScatter, 29U)) + 6948213591282018925U;
            aOrbiterB = (aWandererD + RotL64(aIngress, 46U)) + 6688865181284421478U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 3351130769402360855U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterD) ^ 12681032488906270823U) ^ aOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1]) ^ RotL64(aNonceWordE, 39U);
            aOrbiterI = RotL64((aOrbiterI * 3680893896579741263U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 3591412591193726763U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 16153817571210878589U;
            aOrbiterE = RotL64((aOrbiterE * 4165137036092246349U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 3808228354421006630U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 1427373776207504205U) ^ aOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4534374093769595531U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 1831554180932501132U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 1114853085120949215U;
            aOrbiterD = RotL64((aOrbiterD * 4264176108298812905U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 2080935638828366835U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 16104777999646489828U;
            aOrbiterC = RotL64((aOrbiterC * 15205199362011777473U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 9782806013673440791U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 3721620299829386454U;
            aOrbiterG = RotL64((aOrbiterG * 6286765834910272409U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 4013706412064296527U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 5751022780695158579U;
            aOrbiterF = RotL64((aOrbiterF * 13766736471646116397U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 17684546333240329338U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 1106947111128020920U) ^ aOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3158839453318658951U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 11564229705849500598U) + RotL64(aNonceWordH, 59U);
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 1585817314460274286U;
            aOrbiterA = RotL64((aOrbiterA * 12687162159791577431U), 27U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterI, 47U);
            aIngress = aIngress + (RotL64(aOrbiterB, 5U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 24U));
            aIngress = aIngress + (RotL64(aOrbiterD, 27U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterG, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aIngress, 54U) + RotL64(aOrbiterD, 18U)) + aOrbiterC);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 29U) + aOrbiterE) + RotL64(aOrbiterC, 23U)) + RotL64(aNonceWordB, 15U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 19U) + aOrbiterA) + RotL64(aOrbiterG, 57U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 5U) + aOrbiterF) + RotL64(aOrbiterB, 51U)) + RotL64(aNonceWordG, 23U));
            aWandererB = aWandererB + (((RotL64(aIngress, 13U) + RotL64(aOrbiterD, 5U)) + aOrbiterB) + RotL64(aCarry, 57U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterK, 34U)) + aOrbiterD);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 60U) + RotL64(aOrbiterI, 29U)) + aOrbiterA) + RotL64(aCarry, 47U)) + aWandererUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterD, 43U)) + aOrbiterI);
            aWandererK = aWandererK + (((RotL64(aIngress, 39U) + aOrbiterA) + RotL64(aOrbiterK, 39U)) + aWandererUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 38U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 41U));
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererK, 19U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 4U) ^ RotL64(aNonceWordC, 21U)) ^ RotL64(aNonceWordE, 13U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 23458U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneA[((aIndex + 25118U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 57U) ^ RotL64(aNonceWordD, 14U)) ^ RotL64(aNonceWordF, 3U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24640U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24060U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 60U) + RotL64(aIngress, 47U)) ^ (RotL64(aCross, 35U) ^ RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererI + RotL64(aPrevious, 12U)) + 15904465836916519864U;
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 5U)) + 17725629806317789307U) + aOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = ((aWandererK + RotL64(aCross, 43U)) + RotL64(aCarry, 27U)) + 13794170125914914828U;
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 27U)) + 2149055907476874332U) + RotL64(aNonceWordH, 35U);
            aOrbiterG = (aWandererF + RotL64(aCross, 51U)) + 5342047776745074649U;
            aOrbiterF = (aWandererB + RotL64(aIngress, 47U)) + 8268148484060546838U;
            aOrbiterA = (((aWandererH + RotL64(aScatter, 21U)) + RotL64(aCarry, 35U)) + 10821151364028563719U) + aOrbiterAssignSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = (aWandererD + RotL64(aPrevious, 37U)) + 4294213820894407378U;
            aOrbiterB = (((aWandererA + RotL64(aIngress, 56U)) + RotL64(aCarry, 13U)) + 10884726101307943090U) + RotL64(aNonceWordF, 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 16432210042202444824U) + aOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 15196602644336228055U;
            aOrbiterD = RotL64((aOrbiterD * 12680438355124070237U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 14117787670220328165U) + aOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 219833877949480215U;
            aOrbiterF = RotL64((aOrbiterF * 10736293047771972173U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 3326396981881473962U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 14918513066311426279U;
            aOrbiterE = RotL64((aOrbiterE * 14269763278564574663U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 11795234681370163206U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 3068267285352664813U) ^ RotL64(aNonceWordA, 37U);
            aOrbiterB = RotL64((aOrbiterB * 15746255933920904619U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 245233356957999496U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 709926406353796673U;
            aOrbiterI = RotL64((aOrbiterI * 13627039596842073595U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 5378105439430271038U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 10114555061122044430U;
            aOrbiterC = RotL64((aOrbiterC * 5351295043424885549U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 13233010815716769713U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 8231291294833548389U) ^ RotL64(aNonceWordB, 10U);
            aOrbiterA = RotL64((aOrbiterA * 10840516135212753869U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 7160760224172419829U) + aOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 14767926435411546785U;
            aOrbiterJ = RotL64((aOrbiterJ * 1643485739468851073U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 4464245330038080103U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 15778166658285494712U;
            aOrbiterG = RotL64((aOrbiterG * 13980891936095282989U), 19U);
            //
            aIngress = RotL64(aOrbiterE, 23U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 20U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 47U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 39U));
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterF, 5U)) + aOrbiterB);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 46U) + aOrbiterJ) + RotL64(aOrbiterI, 57U)) + RotL64(aCarry, 21U)) + aWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterA, 38U)) + aOrbiterC) + RotL64(aNonceWordG, 15U));
            aWandererF = aWandererF + ((((RotL64(aScatter, 23U) + aOrbiterG) + RotL64(aOrbiterB, 21U)) + RotL64(aCarry, 41U)) + aWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterD, 53U)) + aOrbiterJ) + RotL64(aNonceWordD, 25U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterA, 43U)) + aOrbiterJ);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 27U) + aOrbiterG) + RotL64(aOrbiterE, 47U));
            aWandererA = aWandererA + ((RotL64(aScatter, 6U) + RotL64(aOrbiterF, 26U)) + aOrbiterJ);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterB, 13U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 27U));
            aCarry = aCarry + RotL64(aWandererK, 50U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 44U) ^ RotL64(aNonceWordH, 53U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 28874U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneB[((aIndex + 31263U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 11U) ^ RotL64(aNonceWordE, 52U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30184U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31275U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 21U) ^ RotL64(aCross, 3U)) ^ (RotL64(aCarry, 37U) + RotL64(aPrevious, 50U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (aWandererK + RotL64(aPrevious, 39U)) + 12632404972795375757U;
            aOrbiterA = ((aWandererE + RotL64(aScatter, 27U)) + 5351879979055988456U) + RotL64(aNonceWordG, 5U);
            aOrbiterI = (((aWandererH + RotL64(aCross, 56U)) + RotL64(aCarry, 5U)) + 3597737727467443413U) + aOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = (aWandererD + RotL64(aIngress, 51U)) + 2830846754917852318U;
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 35U)) + RotL64(aCarry, 57U)) + 17311925960294518018U;
            aOrbiterB = ((aWandererC + RotL64(aScatter, 47U)) + RotL64(aCarry, 27U)) + 2083584640523695383U;
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 22U)) + 15049343611387010158U) + aOrbiterAssignSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterG = ((aWandererA + RotL64(aIngress, 11U)) + 6443050378205811147U) + RotL64(aNonceWordC, 42U);
            aOrbiterH = (aWandererB + RotL64(aCross, 5U)) + 6021965178697344070U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 5080289878758029976U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 576927745306972983U;
            aOrbiterI = RotL64((aOrbiterI * 16008958833683246115U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 4728489691382690859U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 6184355840165758855U;
            aOrbiterC = RotL64((aOrbiterC * 1515043910404156423U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 11220539885798595450U) + aOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 11091438724966718214U) ^ RotL64(aNonceWordF, 43U);
            aOrbiterJ = RotL64((aOrbiterJ * 8225347114759391961U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 17184210490020062419U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 2150997767099116408U;
            aOrbiterG = RotL64((aOrbiterG * 8058553821648892499U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 7021953562676903717U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 17159676348343312834U;
            aOrbiterH = RotL64((aOrbiterH * 13877284519668483549U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 10367891770525239784U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 11922478487264201233U;
            aOrbiterF = RotL64((aOrbiterF * 9195137452661956029U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 17815162358981720634U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 9582631251085100284U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11838992994130850483U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 872593750259572264U) + RotL64(aNonceWordA, 19U);
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 17832330100262167302U;
            aOrbiterB = RotL64((aOrbiterB * 1114416841510028467U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 16601139856969287418U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 14931287111691324985U;
            aOrbiterA = RotL64((aOrbiterA * 16757174577841001179U), 57U);
            //
            aIngress = RotL64(aOrbiterJ, 47U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 23U));
            aIngress = aIngress + (RotL64(aOrbiterE, 6U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 37U));
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aScatter, 40U) + aOrbiterH) + RotL64(aOrbiterC, 57U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 51U) + aOrbiterH) + RotL64(aOrbiterJ, 35U)) + RotL64(aNonceWordD, 7U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterC, 21U)) + aOrbiterI);
            aWandererA = aWandererA ^ ((RotL64(aCross, 23U) + aOrbiterB) + RotL64(aOrbiterE, 14U));
            aWandererC = aWandererC + ((RotL64(aScatter, 3U) + aOrbiterF) + RotL64(aOrbiterC, 53U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterB, 5U)) + aOrbiterA) + RotL64(aNonceWordB, 21U));
            aWandererE = aWandererE + (((RotL64(aIngress, 13U) + aOrbiterF) + RotL64(aOrbiterH, 39U)) + RotL64(aCarry, 43U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 47U) + aOrbiterE) + RotL64(aOrbiterF, 47U)) + aWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aCross, 58U) + RotL64(aOrbiterG, 28U)) + aOrbiterA) + RotL64(aCarry, 13U)) + aWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererB, 28U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 39U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererD, 53U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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

void TwistExpander_Karate_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xF4FBB50C1EC7BEF3ULL + 0x89D68911FDDFC571ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xAAE525FE41A1D95FULL + 0x81C32EF4FB396E13ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xE212D1B7F87A82C3ULL + 0xB0A9699423B61B01ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xFE4DADFF65CA20A9ULL + 0x9642F025C51733F9ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xEDB27B26FD24F2EBULL + 0xEC81F8037D364DC7ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xD0CC4884953D0ADDULL + 0xD7B452491CCDB056ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x9D50AB49CCDF54D5ULL + 0x8C38C42B9FF75A67ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xD465822A26B8C2A3ULL + 0xE754CF7368DD6449ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordA, 29U) ^ RotL64(aNonceWordF, 48U)) ^ RotL64(aNonceWordD, 21U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 3280U)) & S_BLOCK1], 39U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 2001U)) & W_KEY1], 5U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 58U) ^ RotL64(aNonceWordC, 39U)) ^ RotL64(aNonceWordG, 27U));
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 3444U)) & W_KEY1], 47U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 4559U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 52U)) ^ (RotL64(aIngress, 35U) + RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 43U)) + 15383045568644941552U) + RotL64(aNonceWordB, 61U);
            aOrbiterD = ((aWandererI + RotL64(aScatter, 35U)) + RotL64(aCarry, 23U)) + 17452811657750910067U;
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 11U)) + 15660117718455155603U;
            aOrbiterI = ((aWandererK + RotL64(aCross, 60U)) + RotL64(aCarry, 47U)) + 10396441207743665753U;
            aOrbiterB = ((aWandererD + RotL64(aIngress, 51U)) + 3708971058200841442U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = ((aWandererG + RotL64(aCross, 3U)) + 7000673057768598750U) + aPhaseAOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = (((aWandererF + RotL64(aPrevious, 23U)) + RotL64(aCarry, 11U)) + 9886354469011131596U) + RotL64(aNonceWordD, 18U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 16018065329058043467U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 5024756166109352320U;
            aOrbiterJ = RotL64((aOrbiterJ * 11660932185479046483U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 6587818720728886652U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 3652672354944162319U;
            aOrbiterB = RotL64((aOrbiterB * 10807121230791716109U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 6307315649915348048U) + RotL64(aNonceWordC, 17U);
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 16405347331742979258U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7183142442906743699U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 5427299664054601957U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 4983381733483185898U;
            aOrbiterF = RotL64((aOrbiterF * 14646556236306407673U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 10182995521328377487U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = (((aOrbiterK ^ aOrbiterB) ^ 8694282877540593550U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1]) ^ RotL64(aNonceWordF, 7U);
            aOrbiterK = RotL64((aOrbiterK * 14614602561910403893U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 4085927978153269932U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 6176195962815240877U;
            aOrbiterI = RotL64((aOrbiterI * 16792916528959579875U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 6966742100601433005U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 9920952446921247521U;
            aOrbiterD = RotL64((aOrbiterD * 1879821050131820933U), 19U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterK, 29U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 39U));
            aIngress = aIngress + (RotL64(aOrbiterF, 11U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterB, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterE, 37U)) + aOrbiterK);
            aWandererD = aWandererD + (((RotL64(aCross, 3U) + aOrbiterK) + RotL64(aOrbiterF, 18U)) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 19U) + aOrbiterB) + RotL64(aOrbiterF, 11U));
            aWandererF = aWandererF + (((RotL64(aIngress, 11U) + RotL64(aOrbiterJ, 57U)) + aOrbiterI) + RotL64(aCarry, 43U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 34U) + RotL64(aOrbiterK, 29U)) + aOrbiterD) + aPhaseAWandererUpdateSaltA[((aIndex + 22U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 53U) + RotL64(aOrbiterD, 5U)) + aOrbiterB) + RotL64(aCarry, 19U)) + RotL64(aNonceWordA, 57U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterI, 51U)) + aOrbiterF) + RotL64(aNonceWordE, 23U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 40U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 13U);
            aCarry = aCarry + RotL64(aIngress, 4U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 40U) ^ RotL64(aNonceWordD, 51U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8710U)) & S_BLOCK1], 27U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 6995U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 43U) ^ RotL64(aNonceWordH, 22U));
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 9331U)) & W_KEY1], 3U) ^ RotL64(aKeyRowReadB[((aIndex + 9127U)) & W_KEY1], 53U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aIngress, 43U)) ^ (RotL64(aCross, 28U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 3U)) + 16124889768301047791U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = ((aWandererK + RotL64(aCross, 39U)) + RotL64(aCarry, 19U)) + 11912338587186717280U;
            aOrbiterG = (aWandererI + RotL64(aIngress, 57U)) + 8594012868813114354U;
            aOrbiterA = (aWandererD + RotL64(aScatter, 13U)) + 18281043566156682815U;
            aOrbiterK = (((aWandererG + RotL64(aPrevious, 19U)) + RotL64(aCarry, 5U)) + 16853106130200942302U) + RotL64(aNonceWordA, 23U);
            aOrbiterI = (((aWandererA + RotL64(aScatter, 48U)) + RotL64(aCarry, 47U)) + 2611212958619673086U) + aPhaseAOrbiterAssignSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = ((aWandererC + RotL64(aCross, 27U)) + 18039472325066855180U) + RotL64(aNonceWordG, 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 14495785571345122046U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 4556063793412832418U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13166927543135467627U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 14896419970271244358U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterA) ^ 880028529183500036U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1]) ^ RotL64(aNonceWordF, 34U);
            aOrbiterH = RotL64((aOrbiterH * 14228281807461251361U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 2379557167489415783U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 11854373946064529806U;
            aOrbiterA = RotL64((aOrbiterA * 150755294320438887U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 1487252775956449964U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 12777924204511625545U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1366019527386994789U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 15998631485222477969U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 8864212892296191613U;
            aOrbiterK = RotL64((aOrbiterK * 579242788050369815U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 17069347835763226743U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 7443008171694679791U) ^ RotL64(aNonceWordB, 9U);
            aOrbiterI = RotL64((aOrbiterI * 748894368884566607U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 17334256152350782002U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 8986626119086556393U;
            aOrbiterJ = RotL64((aOrbiterJ * 2258172145924120235U), 19U);
            //
            aIngress = RotL64(aOrbiterF, 21U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 51U));
            aIngress = aIngress + (RotL64(aOrbiterA, 13U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterK, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aCross, 51U) + aOrbiterG) + RotL64(aOrbiterJ, 51U)) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 42U) + aOrbiterF) + RotL64(aOrbiterI, 27U)) + RotL64(aCarry, 5U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterJ, 4U)) + aOrbiterH) + RotL64(aNonceWordD, 39U));
            aWandererC = aWandererC + ((((RotL64(aIngress, 29U) + RotL64(aOrbiterH, 41U)) + aOrbiterF) + RotL64(aCarry, 41U)) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterH, 13U)) + aOrbiterA);
            aWandererG = aWandererG + ((RotL64(aScatter, 13U) + aOrbiterA) + RotL64(aOrbiterF, 57U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 3U) + aOrbiterK) + RotL64(aOrbiterJ, 19U)) + RotL64(aNonceWordE, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererB, 21U) ^ aWandererI);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 11U));
            aCarry = aCarry + RotL64(aWandererC, 36U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 23U) ^ RotL64(aNonceWordD, 34U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 16372U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16079U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 57U) ^ RotL64(aNonceWordG, 5U)) ^ RotL64(aNonceWordB, 35U));
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 13833U)) & W_KEY1], 21U) ^ RotL64(aKeyRowReadB[((aIndex + 11450U)) & W_KEY1], 44U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 34U) ^ RotL64(aCross, 3U)) + (RotL64(aIngress, 51U) + RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterB = (aWandererE + RotL64(aIngress, 60U)) + 4179952823252098240U;
            aOrbiterG = (((aWandererC + RotL64(aPrevious, 37U)) + 3745613452332101749U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 6U)) & S_SALT1]) + RotL64(aNonceWordB, 8U);
            aOrbiterE = (((aWandererG + RotL64(aCross, 43U)) + RotL64(aCarry, 21U)) + 2955689793395307176U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterK = ((aWandererA + RotL64(aScatter, 23U)) + RotL64(aCarry, 39U)) + 5639060180251322019U;
            aOrbiterI = (aWandererD + RotL64(aCross, 13U)) + 7901969163853586463U;
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 29U)) + 2242166787816318119U) + RotL64(aNonceWordG, 39U);
            aOrbiterD = ((aWandererJ + RotL64(aIngress, 53U)) + RotL64(aCarry, 51U)) + 5239936443960750064U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 13939136954732185558U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 17058884136712717463U;
            aOrbiterE = RotL64((aOrbiterE * 7222348891215482977U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 18148618660054585941U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 7022023484530327814U;
            aOrbiterG = RotL64((aOrbiterG * 650100011311048589U), 35U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterK) + 7722084537340095637U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1]) + RotL64(aNonceWordC, 9U);
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 11764151879690934182U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12264384877711365655U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 16412785901758144708U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 9666718667728274824U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10865799822751771795U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 4307127540152109364U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 2457646804702647606U;
            aOrbiterI = RotL64((aOrbiterI * 6340030928007058595U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 3179394870088602208U) + RotL64(aNonceWordE, 41U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 504977947273774249U;
            aOrbiterJ = RotL64((aOrbiterJ * 16190282058883481551U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 16182729401018310837U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 7110817020445860609U;
            aOrbiterD = RotL64((aOrbiterD * 13371352088428584087U), 57U);
            //
            aIngress = RotL64(aOrbiterJ, 47U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 40U));
            aIngress = aIngress + (RotL64(aOrbiterG, 21U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterI, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aScatter, 35U) + RotL64(aOrbiterG, 5U)) + aOrbiterB) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterD, 19U)) + aOrbiterG) + RotL64(aNonceWordA, 25U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterE, 51U)) + aOrbiterJ);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 18U) + aOrbiterK) + RotL64(aOrbiterG, 44U)) + RotL64(aNonceWordH, 59U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 27U)) + aOrbiterB) + RotL64(aCarry, 35U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterB, 37U)) + aOrbiterE) + aPhaseAWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 57U) + RotL64(aOrbiterB, 11U)) + aOrbiterK) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 56U));
            aCarry = aCarry + RotL64(aWandererJ, 43U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 57U) ^ RotL64(aNonceWordG, 5U)) ^ RotL64(aNonceWordA, 47U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 21446U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneB[((aIndex + 21409U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 12U) ^ RotL64(aNonceWordC, 51U)) ^ RotL64(aNonceWordB, 35U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20841U)) & S_BLOCK1], 27U) ^ RotL64(mSource[((aIndex + 17735U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aIngress, 37U)) + (RotL64(aCross, 22U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterH = (aWandererK + RotL64(aScatter, 43U)) + 7896237440058555694U;
            aOrbiterA = ((aWandererF + RotL64(aCross, 27U)) + RotL64(aCarry, 27U)) + 11870529476037558635U;
            aOrbiterI = (((aWandererA + RotL64(aPrevious, 37U)) + RotL64(aCarry, 39U)) + 9158983227801569448U) + RotL64(aNonceWordH, 45U);
            aOrbiterB = (((aWandererB + RotL64(aIngress, 56U)) + RotL64(aCarry, 57U)) + 4710172270996950329U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterD = (aWandererD + RotL64(aScatter, 5U)) + 14634482800356647630U;
            aOrbiterF = ((aWandererC + RotL64(aCross, 19U)) + 8822207952170610891U) + aPhaseAOrbiterAssignSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = ((aWandererH + RotL64(aPrevious, 13U)) + 13755891414028982553U) + RotL64(aNonceWordB, 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 4555293067488040719U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 2816805148093762081U) ^ RotL64(aNonceWordD, 39U);
            aOrbiterI = RotL64((aOrbiterI * 16838149138341713943U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 2122631477965135190U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 4592922416380416071U;
            aOrbiterF = RotL64((aOrbiterF * 11644507904538573165U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 7102471666524164715U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = (((aOrbiterA ^ aOrbiterJ) ^ 17274623547879474204U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1]) ^ RotL64(aNonceWordF, 53U);
            aOrbiterA = RotL64((aOrbiterA * 5443572270546181789U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 938587316977094680U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 18258015823797023523U;
            aOrbiterD = RotL64((aOrbiterD * 6068819567674605919U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 5809987756043471595U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 5083075160112581620U;
            aOrbiterH = RotL64((aOrbiterH * 3313957222154937503U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 5960021727750946496U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 5967477320950630150U;
            aOrbiterB = RotL64((aOrbiterB * 330964768256424655U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 6578428711689296132U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 5601728218197771276U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9552559022315971847U), 43U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterB, 3U);
            aIngress = aIngress + (RotL64(aOrbiterH, 11U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterA, 60U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterI, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aCross, 37U) + RotL64(aOrbiterA, 22U)) + aOrbiterJ) + RotL64(aCarry, 29U)) + RotL64(aNonceWordE, 50U));
            aWandererA = aWandererA ^ ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterD, 11U)) + aOrbiterF) + RotL64(aNonceWordA, 35U)) + aPhaseAWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aIngress, 13U) + RotL64(aOrbiterH, 57U)) + aOrbiterA) + RotL64(aCarry, 47U)) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 19U) + aOrbiterA) + RotL64(aOrbiterB, 47U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 3U) + aOrbiterB) + RotL64(aOrbiterF, 5U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 26U) + RotL64(aOrbiterF, 29U)) + aOrbiterH);
            aWandererD = aWandererD + ((RotL64(aScatter, 53U) + aOrbiterD) + RotL64(aOrbiterI, 41U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 54U));
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererF, 47U);
            aCarry = aCarry + RotL64(aIngress, 6U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 37U) ^ RotL64(aNonceWordE, 13U)) ^ RotL64(aNonceWordA, 5U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 23207U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneA[((aIndex + 22688U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 23U) ^ RotL64(aNonceWordD, 13U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26821U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26746U)) & S_BLOCK1], 44U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 27U) + RotL64(aCarry, 40U)) + (RotL64(aCross, 11U) ^ RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterG = (((aWandererC + RotL64(aScatter, 21U)) + RotL64(aCarry, 23U)) + 18144572925667544139U) + RotL64(aNonceWordG, 22U);
            aOrbiterK = (((aWandererB + RotL64(aPrevious, 57U)) + RotL64(aCarry, 47U)) + 5659758077574059728U) + RotL64(aNonceWordC, 47U);
            aOrbiterD = (aWandererI + RotL64(aIngress, 35U)) + 6343330616999166392U;
            aOrbiterF = ((aWandererF + RotL64(aCross, 5U)) + 17754639838410839447U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = ((aWandererJ + RotL64(aIngress, 48U)) + RotL64(aCarry, 11U)) + 9451843819849581729U;
            aOrbiterI = (aWandererK + RotL64(aScatter, 29U)) + 7957854457197462212U;
            aOrbiterA = ((aWandererG + RotL64(aCross, 13U)) + 1461994799722205010U) + aPhaseAOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 18002214276252170177U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 14689869073147027164U;
            aOrbiterD = RotL64((aOrbiterD * 12242482963989582191U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 3978104368003440293U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 8512135845221335386U;
            aOrbiterG = RotL64((aOrbiterG * 10506667163729414667U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 1477533446382953439U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 2166717790929947990U;
            aOrbiterF = RotL64((aOrbiterF * 6538884492418324461U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 8082437060686606995U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 4363687722464700362U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7199165810993478887U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 15782763348014924206U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 8572509150015960728U;
            aOrbiterB = RotL64((aOrbiterB * 3340528604891897779U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 12248271773316742521U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 9602078627638561949U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1860631869877427405U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 17244849374768558859U) + RotL64(aNonceWordH, 5U);
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 1030743048280579012U) ^ RotL64(aNonceWordA, 59U);
            aOrbiterA = RotL64((aOrbiterA * 10858949914285817051U), 5U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterA, 3U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + (RotL64(aOrbiterI, 41U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterF, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 53U) + aOrbiterK) + RotL64(aOrbiterI, 13U));
            aWandererC = aWandererC + (((RotL64(aScatter, 3U) + aOrbiterD) + RotL64(aOrbiterG, 43U)) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 20U) + aOrbiterF) + RotL64(aOrbiterG, 37U));
            aWandererB = aWandererB + (((((RotL64(aPrevious, 29U) + RotL64(aOrbiterB, 51U)) + aOrbiterF) + RotL64(aCarry, 29U)) + RotL64(aNonceWordB, 9U)) + aPhaseAWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterD, 3U)) + aOrbiterF) + RotL64(aNonceWordD, 61U));
            aWandererI = aWandererI + (((RotL64(aCross, 39U) + RotL64(aOrbiterK, 29U)) + aOrbiterG) + RotL64(aCarry, 47U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterB, 22U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 58U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + RotL64(aWandererC, 23U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 53U) ^ RotL64(aNonceWordH, 29U)) ^ RotL64(aNonceWordF, 5U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 27424U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((aIndex + 32297U)) & S_BLOCK1], 44U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 20U) ^ RotL64(aNonceWordB, 29U)) ^ RotL64(aNonceWordC, 37U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31388U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((aIndex + 29245U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 54U) ^ RotL64(aCross, 41U)) + (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 11U)) + 8506388683755208267U) + RotL64(aNonceWordG, 24U);
            aOrbiterB = (aWandererI + RotL64(aScatter, 41U)) + 2179323259055019735U;
            aOrbiterE = ((aWandererC + RotL64(aCross, 22U)) + RotL64(aCarry, 51U)) + 3345902531140983016U;
            aOrbiterJ = (aWandererH + RotL64(aIngress, 57U)) + 17456139311481306584U;
            aOrbiterD = ((((aWandererA + RotL64(aPrevious, 29U)) + RotL64(aCarry, 29U)) + 14587864088462311164U) + aPhaseAOrbiterAssignSaltA[((aIndex + 10U)) & S_SALT1]) + RotL64(aNonceWordE, 13U);
            aOrbiterA = ((aWandererE + RotL64(aIngress, 51U)) + 13178947246650647057U) + aPhaseAOrbiterAssignSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = ((aWandererK + RotL64(aScatter, 35U)) + RotL64(aCarry, 3U)) + 12866578138946916962U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 13098524333655118173U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 15451329483787541982U;
            aOrbiterE = RotL64((aOrbiterE * 13580376920467431451U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 9494299579678389385U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 15581954810375490643U;
            aOrbiterD = RotL64((aOrbiterD * 13670002280188424825U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 4487042505730624892U) + RotL64(aNonceWordB, 17U);
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 2774455928791636186U) ^ RotL64(aNonceWordA, 27U);
            aOrbiterA = RotL64((aOrbiterA * 15847933919136777451U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 12435319582397755819U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 10077180055177766823U;
            aOrbiterH = RotL64((aOrbiterH * 3924363471701748703U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 10391963896910956455U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 6149237416725301794U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10115917698918612823U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 15673402771629639978U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 14729117178956592426U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9070464269215820531U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 14492001279368870240U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 6278248084483259952U;
            aOrbiterB = RotL64((aOrbiterB * 16731228350971263873U), 57U);
            //
            aIngress = RotL64(aOrbiterB, 47U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterK, 4U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterE, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((((RotL64(aPrevious, 21U) + aOrbiterD) + RotL64(aOrbiterB, 3U)) + RotL64(aNonceWordF, 41U)) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 43U) + aOrbiterJ) + RotL64(aOrbiterH, 35U)) + RotL64(aCarry, 57U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 60U) + aOrbiterH) + RotL64(aOrbiterD, 21U));
            aWandererH = aWandererH + ((((RotL64(aScatter, 29U) + aOrbiterA) + RotL64(aOrbiterJ, 29U)) + RotL64(aNonceWordC, 61U)) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 37U) + aOrbiterA) + RotL64(aOrbiterB, 58U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterD, 43U)) + aOrbiterK) + RotL64(aCarry, 39U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 5U) + aOrbiterJ) + RotL64(aOrbiterE, 51U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + (RotL64(aWandererE, 6U) ^ aWandererC);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 41U));
            aCarry = aCarry + RotL64(aWandererH, 11U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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

void TwistExpander_Karate_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xD7FA429C2BB3BC1BULL + 0xB29B64D55DD8DB6EULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xA5C3728B2915858BULL + 0xECD006D39F981723ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xA29E2675D6280E71ULL + 0xB5E485E1E69A80C6ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xFD8A5447A519DB49ULL + 0xCDD009550D0E2609ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xBDDB1614CAF0E749ULL + 0x9380088DE6929419ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x85737A3861AB699FULL + 0xA6BC0FCF3AB7FE64ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xB51640F227746D3BULL + 0xCC9F9ACB7CF9ABB7ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xF950F5785F5089FBULL + 0x9ECA5C65FD6AE104ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 43U) ^ RotL64(aNonceWordH, 51U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 3643U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4276U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 3U) ^ RotL64(aNonceWordB, 21U)) ^ RotL64(aNonceWordF, 39U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 5348U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneA[((aIndex + 1838U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCross, 3U)) ^ (RotL64(aIngress, 52U) ^ RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterA = (((aWandererH + RotL64(aCross, 27U)) + RotL64(aCarry, 35U)) + 17074147006464019918U) + RotL64(aNonceWordD, 39U);
            aOrbiterB = ((((aWandererD + RotL64(aPrevious, 19U)) + RotL64(aCarry, 11U)) + 10559516626129419928U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1]) + RotL64(aNonceWordA, 59U);
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 47U)) + 13280363679503946221U) + aPhaseBOrbiterAssignSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterI = ((aWandererI + RotL64(aIngress, 4U)) + RotL64(aCarry, 53U)) + 17657115422132457413U;
            aOrbiterF = (aWandererE + RotL64(aScatter, 35U)) + 13325837013304973008U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 3059707750486106037U) + RotL64(aNonceWordC, 13U);
            aOrbiterC = (((aOrbiterC ^ aOrbiterA) ^ 4529045702503050852U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]) ^ RotL64(aNonceWordG, 3U);
            aOrbiterC = RotL64((aOrbiterC * 12889277842182219673U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 10726578475550904292U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 14832537837996659885U;
            aOrbiterA = RotL64((aOrbiterA * 808060368961520519U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 220094417441809246U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 15343130035105342194U;
            aOrbiterI = RotL64((aOrbiterI * 7984652435043810845U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 16592263353426409884U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 15649290906447931918U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8405875177836650731U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 11437410545843708269U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 5859769136073011444U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1065016088086441107U), 39U);
            //
            aIngress = RotL64(aOrbiterF, 37U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterA, 13U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterI, 50U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aIngress, 3U) + aOrbiterA) + RotL64(aOrbiterC, 37U));
            aWandererI = aWandererI + ((((RotL64(aPrevious, 58U) + RotL64(aOrbiterI, 48U)) + aOrbiterA) + RotL64(aCarry, 13U)) + aPhaseBWandererUpdateSaltB[((aIndex + 6U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterB, 3U)) + aOrbiterI);
            aWandererJ = aWandererJ + (((((RotL64(aScatter, 41U) + RotL64(aOrbiterF, 29U)) + aOrbiterB) + RotL64(aCarry, 27U)) + RotL64(aNonceWordH, 15U)) + aPhaseBWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterC, 13U)) + aOrbiterF) + RotL64(aNonceWordE, 54U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 21U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + RotL64(aWandererI, 30U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 12U) ^ RotL64(aNonceWordD, 27U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 6157U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 8194U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 29U) ^ RotL64(aNonceWordG, 43U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5759U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneB[((aIndex + 10809U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aIngress, 10U)) ^ (RotL64(aPrevious, 39U) + RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterF = (((aWandererG + RotL64(aCross, 21U)) + RotL64(aCarry, 23U)) + 1042610313571524121U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = (((aWandererF + RotL64(aPrevious, 11U)) + RotL64(aCarry, 43U)) + 3505725321008825582U) + RotL64(aNonceWordB, 5U);
            aOrbiterH = ((aWandererE + RotL64(aIngress, 38U)) + 12584654563843782991U) + RotL64(aNonceWordF, 25U);
            aOrbiterJ = (aWandererK + RotL64(aScatter, 51U)) + 6645399144515770935U;
            aOrbiterC = (((aWandererJ + RotL64(aIngress, 3U)) + RotL64(aCarry, 5U)) + 3608978423753715584U) + aPhaseBOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1];
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 8089198857670370983U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 15207251813516399879U;
            aOrbiterH = RotL64((aOrbiterH * 7596841660069752069U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 9579268660105824516U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 16055044469473802812U) ^ RotL64(aNonceWordD, 27U);
            aOrbiterC = RotL64((aOrbiterC * 2269649280637188723U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 583811872609805949U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 7027491967970873942U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12686754713465826139U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 18256061823189677508U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 12708429127816136937U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12593886633108075321U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 12169216645156306078U) + RotL64(aNonceWordA, 16U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 12694325407567795065U;
            aOrbiterJ = RotL64((aOrbiterJ * 3711789483877261899U), 47U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterH, 51U);
            aIngress = aIngress + (RotL64(aOrbiterF, 13U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterC, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aCross, 47U) + RotL64(aOrbiterH, 53U)) + aOrbiterC) + RotL64(aCarry, 27U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 5U) + aOrbiterJ) + RotL64(aOrbiterA, 42U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aScatter, 14U) + aOrbiterJ) + RotL64(aOrbiterH, 13U)) + RotL64(aCarry, 5U)) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 27U) + aOrbiterF) + RotL64(aOrbiterC, 29U)) + RotL64(aNonceWordC, 11U));
            aWandererF = aWandererF + (((RotL64(aCross, 37U) + aOrbiterJ) + RotL64(aOrbiterF, 3U)) + RotL64(aNonceWordE, 7U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererK);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 43U));
            aCarry = aCarry + RotL64(aWandererG, 54U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 29U) ^ RotL64(aNonceWordC, 42U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 14402U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11416U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 5U) ^ RotL64(aNonceWordD, 53U)) ^ RotL64(aNonceWordF, 22U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16086U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((aIndex + 16010U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCross, 19U)) ^ (RotL64(aIngress, 52U) + RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterB = ((aWandererK + RotL64(aIngress, 34U)) + RotL64(aCarry, 11U)) + 14157904117287696136U;
            aOrbiterI = ((((aWandererI + RotL64(aCross, 11U)) + RotL64(aCarry, 51U)) + 7369512677371640676U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 10U)) & S_SALT1]) + RotL64(aNonceWordD, 23U);
            aOrbiterA = (aWandererD + RotL64(aScatter, 21U)) + 8411250745902073798U;
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 53U)) + 5002041814539710275U) + RotL64(aNonceWordE, 36U);
            aOrbiterF = (((aWandererG + RotL64(aScatter, 43U)) + RotL64(aCarry, 23U)) + 9538041410816283124U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 5210700103927513061U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 7600709399101287982U;
            aOrbiterA = RotL64((aOrbiterA * 6777896926889560889U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 2366369466696580499U) + RotL64(aNonceWordG, 5U);
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 5544575244203019109U) ^ RotL64(aNonceWordH, 31U);
            aOrbiterI = RotL64((aOrbiterI * 16231219246786333057U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 8710073749110329779U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 15998211310115361630U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15275657696897688955U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 15354357553877376422U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 10657523549259276169U;
            aOrbiterJ = RotL64((aOrbiterJ * 13695239532898311073U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 10405750198355464768U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 3465819693133515142U;
            aOrbiterF = RotL64((aOrbiterF * 14678343718277562799U), 21U);
            //
            aIngress = RotL64(aOrbiterF, 53U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterJ, 34U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 11U) + aOrbiterB) + RotL64(aOrbiterI, 23U));
            aWandererD = aWandererD + ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterA, 43U)) + aOrbiterJ) + RotL64(aCarry, 5U)) + aPhaseBWandererUpdateSaltF[((aIndex + 6U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((((RotL64(aScatter, 21U) + RotL64(aOrbiterB, 58U)) + aOrbiterJ) + RotL64(aNonceWordC, 43U)) + aPhaseBWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aIngress, 60U) + RotL64(aOrbiterF, 13U)) + aOrbiterJ) + RotL64(aCarry, 23U)) + RotL64(aNonceWordB, 45U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 43U) + aOrbiterA) + RotL64(aOrbiterF, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererK);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 53U));
            aCarry = aCarry + RotL64(aWandererG, 19U);
            aCarry = aCarry + RotL64(aIngress, 36U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordA, 60U) ^ RotL64(aNonceWordH, 19U)) ^ RotL64(aNonceWordF, 51U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 18843U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 16805U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 4U) ^ RotL64(aNonceWordC, 13U)) ^ RotL64(aNonceWordB, 43U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18001U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17592U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aPrevious, 5U)) ^ (RotL64(aIngress, 37U) + RotL64(aCarry, 50U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterK = (aWandererI + RotL64(aScatter, 3U)) + 10805654776556844351U;
            aOrbiterD = (((aWandererD + RotL64(aIngress, 27U)) + RotL64(aCarry, 39U)) + 582794182442795335U) + RotL64(aNonceWordD, 37U);
            aOrbiterC = ((aWandererF + RotL64(aCross, 57U)) + 2858343650974681068U) + aPhaseBOrbiterAssignSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = (((aWandererE + RotL64(aPrevious, 44U)) + RotL64(aCarry, 11U)) + 8189584049022064284U) + RotL64(aNonceWordH, 39U);
            aOrbiterF = (((aWandererA + RotL64(aScatter, 19U)) + RotL64(aCarry, 53U)) + 1565100751996962893U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 8062028016947611891U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 8280504280578451745U;
            aOrbiterC = RotL64((aOrbiterC * 5212851648135050483U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 11326869194491655350U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 1671695656567777163U;
            aOrbiterK = RotL64((aOrbiterK * 7511554500524257921U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 2349843105293943452U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 13015545152052004254U;
            aOrbiterE = RotL64((aOrbiterE * 1316662811685429983U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 16703354404749291869U) + RotL64(aNonceWordG, 59U);
            aOrbiterD = (((aOrbiterD ^ aOrbiterF) ^ 8713231044374305801U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]) ^ RotL64(aNonceWordE, 38U);
            aOrbiterD = RotL64((aOrbiterD * 9242480982197688625U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 11118401674497783533U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 14857556493734710364U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3452566050389715195U), 47U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterF, 36U);
            aIngress = aIngress + (RotL64(aOrbiterC, 47U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aScatter, 57U) + aOrbiterF) + RotL64(aOrbiterE, 3U)) + RotL64(aNonceWordA, 3U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 13U) + aOrbiterC) + RotL64(aOrbiterE, 11U)) + RotL64(aCarry, 53U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 24U) + aOrbiterC) + RotL64(aOrbiterD, 53U)) + aPhaseBWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 47U) + aOrbiterK) + RotL64(aOrbiterE, 43U)) + RotL64(aCarry, 21U));
            aWandererF = aWandererF ^ ((((RotL64(aIngress, 3U) + aOrbiterC) + RotL64(aOrbiterF, 28U)) + RotL64(aNonceWordB, 55U)) + aPhaseBWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 52U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 37U));
            aCarry = aCarry + RotL64(aWandererF, 11U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 35U) ^ RotL64(aNonceWordD, 11U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 22296U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 24012U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 37U) ^ RotL64(aNonceWordG, 3U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26867U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27261U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aIngress, 40U)) ^ (RotL64(aPrevious, 19U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterA = ((aWandererG + RotL64(aIngress, 3U)) + RotL64(aCarry, 57U)) + 2974056819475622600U;
            aOrbiterB = (((aWandererD + RotL64(aCross, 39U)) + RotL64(aCarry, 41U)) + 7345051759236356098U) + aPhaseBOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = ((aWandererE + RotL64(aScatter, 23U)) + RotL64(aCarry, 11U)) + 12738468816846628882U;
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 58U)) + 7694520596043297922U) + RotL64(aNonceWordE, 40U);
            aOrbiterF = (((aWandererK + RotL64(aIngress, 13U)) + 5530753590015084774U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1]) + RotL64(aNonceWordB, 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 3776309161718383105U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 784780304358106404U;
            aOrbiterH = RotL64((aOrbiterH * 1503119308251871519U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 8999942326995036509U) + RotL64(aNonceWordF, 13U);
            aOrbiterF = (((aOrbiterF ^ aOrbiterB) ^ 5194986506064092779U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]) ^ RotL64(aNonceWordA, 17U);
            aOrbiterF = RotL64((aOrbiterF * 15070787038006135963U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 7920040007459652762U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 11311997270710107937U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6227571709361790209U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 5365231114813547251U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 8630110234623825263U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2735881715888325759U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 2358235238039571072U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 18059414891616491807U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17150786106857185467U), 43U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterB, 57U);
            aIngress = aIngress + (RotL64(aOrbiterF, 13U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterA, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterH, 57U)) + aOrbiterF) + RotL64(aNonceWordC, 61U));
            aWandererD = aWandererD + ((((RotL64(aPrevious, 46U) + aOrbiterB) + RotL64(aOrbiterA, 28U)) + RotL64(aCarry, 11U)) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterB, 11U)) + aOrbiterF);
            aWandererE = aWandererE + (((RotL64(aCross, 19U) + RotL64(aOrbiterB, 19U)) + aOrbiterD) + RotL64(aCarry, 53U));
            aWandererG = aWandererG ^ ((((RotL64(aPrevious, 35U) + aOrbiterF) + RotL64(aOrbiterA, 37U)) + RotL64(aNonceWordD, 43U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererD, 35U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 52U) ^ RotL64(aNonceWordH, 3U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 29668U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32236U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 13U) ^ RotL64(aNonceWordF, 5U)) ^ RotL64(aNonceWordD, 56U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 29289U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((aIndex + 27921U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 11U)) ^ (RotL64(aCross, 44U) + RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterB = ((aWandererE + RotL64(aScatter, 3U)) + 898812731947995389U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = ((((aWandererF + RotL64(aPrevious, 53U)) + RotL64(aCarry, 11U)) + 8677347622525527167U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1]) + RotL64(aNonceWordB, 15U);
            aOrbiterH = (aWandererA + RotL64(aIngress, 21U)) + 770321564027567654U;
            aOrbiterF = ((aWandererG + RotL64(aCross, 42U)) + RotL64(aCarry, 29U)) + 11020474858081526395U;
            aOrbiterE = (((aWandererK + RotL64(aScatter, 11U)) + RotL64(aCarry, 57U)) + 17289793580414993470U) + RotL64(aNonceWordD, 59U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 10111912559295118444U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 8083622125544542011U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3610772128071340341U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 7149858558922988240U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 5919683821379905699U) ^ RotL64(aNonceWordH, 41U);
            aOrbiterJ = RotL64((aOrbiterJ * 16705119888884231567U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 6860902846079238714U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 15083517836867542075U;
            aOrbiterB = RotL64((aOrbiterB * 4686657139237578325U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 14852868368708376381U) + RotL64(aNonceWordG, 13U);
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 9860233289028878323U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13418143547952204667U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 772406119079116272U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 7971141501337627589U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10168120622976358617U), 53U);
            //
            aIngress = RotL64(aOrbiterE, 20U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 35U));
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aIngress, 48U) + aOrbiterF) + RotL64(aOrbiterH, 3U)) + RotL64(aCarry, 43U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterE, 30U)) + aOrbiterJ) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererA = aWandererA + (((((RotL64(aPrevious, 3U) + aOrbiterF) + RotL64(aOrbiterJ, 57U)) + RotL64(aCarry, 23U)) + RotL64(aNonceWordE, 20U)) + aPhaseBWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterH, 11U)) + aOrbiterB);
            aWandererG = aWandererG + (((RotL64(aIngress, 57U) + aOrbiterH) + RotL64(aOrbiterJ, 21U)) + RotL64(aNonceWordA, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + RotL64(aWandererG, 19U);
            aCarry = aCarry + RotL64(aIngress, 58U);
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

void TwistExpander_Karate_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xF1BDD82EA02FE541ULL + 0xAB5C05E54349A9FFULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x903A97930FE7B0DBULL + 0xBCD2F942CC0CF58DULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x82025B6C7AA1F9D5ULL + 0xD72D7C102D61A0E2ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xC71B5C1D2FFEAE37ULL + 0xAA8B67181988CDF3ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x9A2738784E36129DULL + 0xFDD82C89F129CF70ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xE62A3C35FC3BF769ULL + 0xBBD4B80D4AC35ACCULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xF5B137EC78E20A83ULL + 0xE00B540EDEF5E1D4ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xDF39A254412421EBULL + 0x9B3036B6300C94A8ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 24U) ^ RotL64(aNonceWordF, 51U)) ^ RotL64(aNonceWordC, 5U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 2089U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneC[((aIndex + 2414U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 41U) ^ RotL64(aNonceWordA, 56U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 4726U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneA[((aIndex + 7279U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 6U) + RotL64(aIngress, 57U)) ^ (RotL64(aCross, 19U) ^ RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterC = (aWandererJ + RotL64(aScatter, 18U)) + 16016931609704150191U;
            aOrbiterJ = (((aWandererF + RotL64(aIngress, 3U)) + RotL64(aCarry, 19U)) + 14511433515861302636U) + RotL64(aNonceWordC, 3U);
            aOrbiterG = (((aWandererC + RotL64(aPrevious, 23U)) + 11691237442613269593U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1]) + RotL64(aNonceWordE, 43U);
            aOrbiterD = (((aWandererK + RotL64(aCross, 57U)) + RotL64(aCarry, 41U)) + 16383220587320484649U) + aPhaseCOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = (aWandererA + RotL64(aScatter, 12U)) + 14293015313458219868U;
            aOrbiterB = (aWandererG + RotL64(aIngress, 27U)) + 4407695248205526670U;
            aOrbiterH = (aWandererH + RotL64(aCross, 51U)) + 1158323195324398372U;
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 47U)) + RotL64(aCarry, 5U)) + 6577683409653864555U;
            aOrbiterK = (aWandererE + RotL64(aIngress, 35U)) + 171080079472863843U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 5766333425872228205U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 16173508656917582960U) ^ RotL64(aNonceWordB, 11U);
            aOrbiterG = RotL64((aOrbiterG * 12187968015372936695U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 11781450063402219202U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 13033139686637576694U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4331137994135472025U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 4006310759400926020U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 13156817947481574467U;
            aOrbiterI = RotL64((aOrbiterI * 563189239835001483U), 35U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterB) + 12791290558893516411U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1]) + RotL64(aNonceWordH, 5U);
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 989729955679243234U;
            aOrbiterK = RotL64((aOrbiterK * 8757228712495095017U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 838379839663022790U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 2830743864262313606U;
            aOrbiterC = RotL64((aOrbiterC * 10173947177104802797U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 2146646527331684652U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 4629168181742174906U;
            aOrbiterD = RotL64((aOrbiterD * 9046124907945045131U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 1150129989168501777U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 619659995945229440U;
            aOrbiterH = RotL64((aOrbiterH * 13734821008174603409U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 8120315647582116952U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 13754584116324996165U;
            aOrbiterJ = RotL64((aOrbiterJ * 12295486140772079747U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 6084566798869999580U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 5731665119233722504U;
            aOrbiterF = RotL64((aOrbiterF * 5921510209025133639U), 27U);
            //
            aIngress = RotL64(aOrbiterI, 19U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterJ, 30U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 43U));
            aIngress = aIngress + RotL64(aOrbiterF, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterG, 29U)) + aOrbiterB) + RotL64(aNonceWordF, 30U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterI, 44U)) + aOrbiterC) + RotL64(aCarry, 51U));
            aWandererJ = aWandererJ ^ ((((RotL64(aIngress, 56U) + RotL64(aOrbiterB, 13U)) + aOrbiterJ) + RotL64(aNonceWordG, 19U)) + aPhaseCWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aScatter, 35U) + aOrbiterD) + RotL64(aOrbiterG, 51U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterF, 57U)) + aOrbiterK);
            aWandererB = aWandererB + ((RotL64(aCross, 29U) + RotL64(aOrbiterJ, 35U)) + aOrbiterI);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterK, 39U)) + aOrbiterD) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 19U) + RotL64(aOrbiterC, 24U)) + aOrbiterF) + RotL64(aCarry, 3U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 10U) + aOrbiterC) + RotL64(aOrbiterH, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererA, 5U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordA, 11U) ^ RotL64(aNonceWordB, 39U)) ^ RotL64(aNonceWordE, 57U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9214U)) & S_BLOCK1], 28U) ^ RotL64(aOperationLaneD[((aIndex + 15382U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 60U) ^ RotL64(aNonceWordF, 23U)) ^ RotL64(aNonceWordD, 5U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 10842U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneB[((aIndex + 10752U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCross, 41U)) ^ (RotL64(aCarry, 29U) ^ RotL64(aPrevious, 6U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterJ = (((aWandererH + RotL64(aScatter, 21U)) + 14686411261024919129U) + aPhaseCOrbiterAssignSaltE[((aIndex + 25U)) & S_SALT1]) + RotL64(aNonceWordC, 49U);
            aOrbiterB = (aWandererK + RotL64(aIngress, 58U)) + 7514582233957632005U;
            aOrbiterH = (aWandererE + RotL64(aPrevious, 39U)) + 6520710480103365552U;
            aOrbiterK = (aWandererF + RotL64(aCross, 29U)) + 1983621978676188036U;
            aOrbiterG = ((aWandererI + RotL64(aIngress, 35U)) + RotL64(aCarry, 57U)) + 9003524602590749672U;
            aOrbiterF = (aWandererG + RotL64(aPrevious, 11U)) + 6428568234045228995U;
            aOrbiterD = ((aWandererB + RotL64(aScatter, 44U)) + 8656552687136446989U) + RotL64(aNonceWordE, 7U);
            aOrbiterE = ((aWandererC + RotL64(aCross, 5U)) + RotL64(aCarry, 39U)) + 16916248288415922490U;
            aOrbiterA = (((aWandererD + RotL64(aPrevious, 51U)) + RotL64(aCarry, 29U)) + 9740237548002535784U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 907561000814618339U) + RotL64(aNonceWordG, 43U);
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 4751108900841197631U;
            aOrbiterH = RotL64((aOrbiterH * 4545395964730641957U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 167774899400732287U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 11907484918310854962U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7213139491146402985U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 14910318613649863924U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 14882888155751455276U;
            aOrbiterD = RotL64((aOrbiterD * 11394136445442060201U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 16175942562693781908U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterB) ^ 11022373758481651102U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1]) ^ RotL64(aNonceWordA, 59U);
            aOrbiterE = RotL64((aOrbiterE * 6836331461393816027U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 12548405399045031548U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 10850926364556828443U;
            aOrbiterA = RotL64((aOrbiterA * 16231561687709867431U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 13391684887911141790U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 14648937281264822988U;
            aOrbiterJ = RotL64((aOrbiterJ * 6533299316940026059U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 8298658887198526821U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 13822977698661348891U;
            aOrbiterK = RotL64((aOrbiterK * 17769262972278410937U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 7505646847564645719U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 3238749538197209166U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15394286542600778567U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 15853506915123709257U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 8426329899401071248U;
            aOrbiterB = RotL64((aOrbiterB * 1330397096577715113U), 23U);
            //
            aIngress = RotL64(aOrbiterF, 27U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterB, 60U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 5U));
            aIngress = aIngress + (RotL64(aOrbiterG, 35U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterK, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aIngress, 51U) + aOrbiterK) + RotL64(aOrbiterH, 13U));
            aWandererF = aWandererF + (((RotL64(aCross, 24U) + RotL64(aOrbiterG, 39U)) + aOrbiterB) + RotL64(aCarry, 43U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterB, 27U)) + aOrbiterA);
            aWandererI = aWandererI + (((RotL64(aScatter, 11U) + RotL64(aOrbiterB, 44U)) + aOrbiterK) + aPhaseCWandererUpdateSaltA[((aIndex + 6U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 37U) + aOrbiterF) + RotL64(aOrbiterG, 51U));
            aWandererC = aWandererC + (((RotL64(aCross, 18U) + aOrbiterE) + RotL64(aOrbiterJ, 3U)) + RotL64(aNonceWordD, 35U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 29U) + aOrbiterE) + RotL64(aOrbiterK, 35U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 57U) + aOrbiterD) + RotL64(aOrbiterK, 23U)) + RotL64(aCarry, 13U)) + RotL64(aNonceWordH, 26U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterJ, 60U)) + aOrbiterG) + aPhaseCWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 23U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 14U));
            aCarry = aCarry + RotL64(aWandererC, 11U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 21U) ^ RotL64(aNonceWordB, 47U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 18965U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((aIndex + 18515U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 19U) ^ RotL64(aNonceWordC, 51U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 24333U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneC[((aIndex + 17279U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 4U) + RotL64(aCross, 53U)) + (RotL64(aPrevious, 21U) ^ RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterJ = ((((aWandererA + RotL64(aScatter, 10U)) + RotL64(aCarry, 41U)) + 17711946802293254150U) + aPhaseCOrbiterAssignSaltA[((aIndex + 16U)) & S_SALT1]) + RotL64(aNonceWordH, 26U);
            aOrbiterE = ((aWandererI + RotL64(aCross, 5U)) + 16652362590489569378U) + RotL64(aNonceWordB, 13U);
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 57U)) + RotL64(aCarry, 29U)) + 6972810344198183097U;
            aOrbiterC = ((aWandererC + RotL64(aIngress, 29U)) + RotL64(aCarry, 5U)) + 13117100889782940546U;
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 43U)) + 13199305696782626591U) + aPhaseCOrbiterAssignSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = (aWandererE + RotL64(aScatter, 14U)) + 992156184392760945U;
            aOrbiterA = (aWandererB + RotL64(aCross, 37U)) + 13791265442074543880U;
            aOrbiterG = (aWandererJ + RotL64(aIngress, 23U)) + 17057087245252294859U;
            aOrbiterD = (aWandererD + RotL64(aCross, 51U)) + 13444195995883541046U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 6723678233676059420U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 7913379431208430475U;
            aOrbiterH = RotL64((aOrbiterH * 2295062944289127123U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 4481887195529300665U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 11892724101424384078U) ^ RotL64(aNonceWordA, 19U);
            aOrbiterJ = RotL64((aOrbiterJ * 3468639499716604111U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 7700902083270424194U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 1888001433557140271U;
            aOrbiterC = RotL64((aOrbiterC * 8975562955027025349U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 14996753906788986929U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 939004845422123765U;
            aOrbiterE = RotL64((aOrbiterE * 2507090308972292313U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 11922230289291941807U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 15681187459741147199U;
            aOrbiterK = RotL64((aOrbiterK * 10124947739653819101U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 9119043713532718155U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 8327697433992362166U) ^ RotL64(aNonceWordF, 49U);
            aOrbiterF = RotL64((aOrbiterF * 11157657162184304567U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 13630755116592440359U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 771252613886022889U;
            aOrbiterA = RotL64((aOrbiterA * 2958918915223536519U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 8524239721467527770U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 17732617735422435572U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13992947983987668631U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 5265753270696005619U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 14456128349522985053U;
            aOrbiterD = RotL64((aOrbiterD * 5406509991740849617U), 27U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterC, 60U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 27U));
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 47U));
            aIngress = aIngress + RotL64(aOrbiterH, 30U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterF, 41U)) + aOrbiterG);
            aWandererJ = aWandererJ + ((RotL64(aCross, 60U) + RotL64(aOrbiterC, 19U)) + aOrbiterK);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 51U) + aOrbiterA) + RotL64(aOrbiterH, 6U)) + aPhaseCWandererUpdateSaltB[((aIndex + 22U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aScatter, 3U) + aOrbiterE) + RotL64(aOrbiterA, 37U)) + RotL64(aCarry, 21U)) + RotL64(aNonceWordG, 41U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 35U) + aOrbiterC) + RotL64(aOrbiterG, 13U));
            aWandererF = aWandererF + (((RotL64(aIngress, 56U) + RotL64(aOrbiterA, 23U)) + aOrbiterD) + RotL64(aCarry, 51U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 23U) + aOrbiterD) + RotL64(aOrbiterH, 51U));
            aWandererB = aWandererB + (((RotL64(aCross, 43U) + RotL64(aOrbiterC, 28U)) + aOrbiterJ) + RotL64(aNonceWordE, 9U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 29U) + aOrbiterC) + RotL64(aOrbiterE, 47U)) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 44U) ^ aWandererF);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + (RotL64(aWandererB, 21U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererG, 5U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 5U) ^ RotL64(aNonceWordA, 35U)) ^ RotL64(aNonceWordB, 43U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 31304U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32159U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 41U) ^ RotL64(aNonceWordH, 13U)) ^ RotL64(aNonceWordC, 4U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 29441U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneD[((aIndex + 27735U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCross, 22U)) + (RotL64(aCarry, 37U) ^ RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 47U)) + 12262991801139086177U) + RotL64(aNonceWordG, 31U);
            aOrbiterI = ((aWandererD + RotL64(aIngress, 24U)) + RotL64(aCarry, 43U)) + 7963038771924890197U;
            aOrbiterD = ((aWandererC + RotL64(aCross, 11U)) + RotL64(aCarry, 35U)) + 15540520327933568896U;
            aOrbiterC = ((aWandererE + RotL64(aScatter, 29U)) + RotL64(aCarry, 13U)) + 8745565892055020722U;
            aOrbiterA = (aWandererA + RotL64(aIngress, 39U)) + 16619329199683755286U;
            aOrbiterK = (aWandererF + RotL64(aCross, 53U)) + 10865705026433867260U;
            aOrbiterH = ((aWandererI + RotL64(aScatter, 43U)) + 2743368697984518059U) + aPhaseCOrbiterAssignSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 20U)) + 5556006271515473135U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = ((aWandererG + RotL64(aIngress, 3U)) + 5355833281353498588U) + RotL64(aNonceWordF, 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 8313616108963479829U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 16657121016801866434U;
            aOrbiterD = RotL64((aOrbiterD * 331533349428472477U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 16532226425013000833U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 5800465874932467232U;
            aOrbiterA = RotL64((aOrbiterA * 5966395771690704577U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 17882948163883121328U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 15029375310296563175U;
            aOrbiterH = RotL64((aOrbiterH * 17021415832288477713U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 10170682648007918739U) + RotL64(aNonceWordE, 60U);
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 11829089574189398773U;
            aOrbiterE = RotL64((aOrbiterE * 15755874363488568849U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 1746524867389196322U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 10217423427886742775U;
            aOrbiterC = RotL64((aOrbiterC * 9166162099575333519U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 1338457710729082656U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 1319981417675542556U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9518448254565489715U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 3985281993069194761U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 7281264481139915593U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13498446162967276739U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 17394503335338855566U) + RotL64(aNonceWordB, 17U);
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 1430703546991948227U;
            aOrbiterB = RotL64((aOrbiterB * 1623206122475721175U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 472559435062214929U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 8065899137826178995U;
            aOrbiterI = RotL64((aOrbiterI * 13287499768933229539U), 37U);
            //
            aIngress = RotL64(aOrbiterB, 44U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 23U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 11U));
            aIngress = aIngress + RotL64(aOrbiterH, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aPrevious, 6U) + RotL64(aOrbiterI, 13U)) + aOrbiterC) + RotL64(aCarry, 21U)) + RotL64(aNonceWordD, 15U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterD, 47U)) + aOrbiterA);
            aWandererF = aWandererF + ((RotL64(aIngress, 35U) + aOrbiterI) + RotL64(aOrbiterE, 30U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 27U) + aOrbiterA) + RotL64(aOrbiterG, 57U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterD, 43U)) + aOrbiterI);
            aWandererK = aWandererK ^ ((RotL64(aCross, 53U) + aOrbiterK) + RotL64(aOrbiterE, 37U));
            aWandererG = aWandererG + (((RotL64(aIngress, 57U) + RotL64(aOrbiterI, 24U)) + aOrbiterH) + RotL64(aCarry, 37U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 43U) + aOrbiterH) + RotL64(aOrbiterB, 19U)) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aCross, 48U) + RotL64(aOrbiterG, 53U)) + aOrbiterB) + RotL64(aNonceWordC, 11U)) + aPhaseCWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 43U));
            aCarry = aCarry + RotL64(aWandererG, 48U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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

void TwistExpander_Karate_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xBF1B88BFFE195C51ULL + 0xA21906A0B5F4D90DULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x8ADF0BDCBE8752C1ULL + 0xC2A438DCF2846F09ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x895D5991E44C2563ULL + 0x9ED87B614D7A8768ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xAF071DF575D943B3ULL + 0xFB6FC27B740135F9ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x9D5CDBB7D415CB63ULL + 0xA3A029B5B6FB2510ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xBD01775599C32897ULL + 0xF31D561FDCB853FFULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xD59CA8F1C7D5BAA1ULL + 0xB76D5B7934BA5220ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xD497792BD2D13055ULL + 0xC15675CC074E0D36ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 47U) ^ RotL64(aNonceWordH, 57U)) ^ RotL64(aNonceWordD, 23U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 1620U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((aIndex + 1276U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 39U) ^ RotL64(aNonceWordA, 11U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2704U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 2044U)) & S_BLOCK1], 24U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aPrevious, 39U)) + (RotL64(aIngress, 51U) + RotL64(aCarry, 10U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterK = ((aWandererJ + RotL64(aCross, 36U)) + RotL64(aCarry, 11U)) + 16424657151168221875U;
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 51U)) + 17150123681886380361U) + aPhaseDOrbiterAssignSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = (aWandererG + RotL64(aScatter, 43U)) + 16041993588694572757U;
            aOrbiterI = (aWandererE + RotL64(aIngress, 41U)) + 9871185846434828537U;
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 27U)) + RotL64(aCarry, 27U)) + 11227236398354430757U;
            aOrbiterG = (aWandererH + RotL64(aScatter, 11U)) + 5399325217402192631U;
            aOrbiterC = (aWandererD + RotL64(aIngress, 23U)) + 9248828789282890454U;
            aOrbiterE = ((aWandererB + RotL64(aCross, 29U)) + 9041370494203701062U) + aPhaseDOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 18U)) + RotL64(aCarry, 53U)) + 14944424084524970764U;
            aOrbiterD = ((aWandererF + RotL64(aCross, 47U)) + 5481938174456671041U) + RotL64(aNonceWordF, 35U);
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 57U)) + 14783648629543752715U) + RotL64(aNonceWordC, 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 12355573914530445723U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 9863991559011968318U;
            aOrbiterA = RotL64((aOrbiterA * 8495251211794343179U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 16149688605937250965U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 106041828692026825U;
            aOrbiterG = RotL64((aOrbiterG * 12199934305374582599U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 8076098639554567792U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 11155119311895580013U) ^ RotL64(aNonceWordB, 31U);
            aOrbiterK = RotL64((aOrbiterK * 1495180896564818647U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 6847612160595917702U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 16094377920388017367U;
            aOrbiterI = RotL64((aOrbiterI * 4875801863643206333U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 13584719866672696684U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 13446209321646234607U;
            aOrbiterC = RotL64((aOrbiterC * 9945349065094781529U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 15829806645369560988U) + RotL64(aNonceWordE, 59U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 12573767256739062550U;
            aOrbiterJ = RotL64((aOrbiterJ * 5649504278826069077U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 3850030870300393809U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 11857593987748189858U;
            aOrbiterF = RotL64((aOrbiterF * 15942863910931814193U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 5505918410521728373U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 12949653497121247860U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 90944913639560027U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 2448323375614082955U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 4386059032042654583U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11730132905525317201U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 108129028178045299U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 18292666533864994149U;
            aOrbiterE = RotL64((aOrbiterE * 2599590507178673531U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 10771402979550786312U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 16424657151168221875U;
            aOrbiterD = RotL64((aOrbiterD * 6255743082177474607U), 11U);
            //
            aIngress = RotL64(aOrbiterJ, 37U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterE, 41U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 46U));
            aIngress = aIngress + (RotL64(aOrbiterG, 53U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterI, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 21U) + aOrbiterA) + RotL64(aOrbiterI, 56U));
            aWandererD = aWandererD + (((RotL64(aCross, 38U) + RotL64(aOrbiterH, 35U)) + aOrbiterG) + RotL64(aCarry, 5U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterB, 3U)) + aOrbiterJ) + aPhaseDWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterA, 19U)) + RotL64(aCarry, 23U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 29U) + aOrbiterE) + RotL64(aOrbiterC, 50U));
            aWandererC = aWandererC + ((RotL64(aIngress, 13U) + aOrbiterF) + RotL64(aOrbiterE, 37U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterA, 39U)) + aOrbiterD);
            aWandererG = aWandererG + (((RotL64(aCross, 6U) + RotL64(aOrbiterF, 47U)) + aOrbiterG) + RotL64(aNonceWordA, 9U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 41U) + aOrbiterI) + RotL64(aOrbiterD, 21U)) + aPhaseDWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 51U) + aOrbiterG) + RotL64(aOrbiterI, 53U)) + RotL64(aNonceWordD, 6U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterK, 43U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererE, 21U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererG, 26U) ^ aWandererJ);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererH, 29U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 5U) ^ RotL64(aNonceWordH, 53U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 6225U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneD[((aIndex + 7813U)) & S_BLOCK1], 30U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 29U) ^ RotL64(aNonceWordG, 46U)) ^ RotL64(aNonceWordC, 11U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 10745U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 9798U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 51U)) + (RotL64(aCross, 6U) ^ RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterH = (aWandererK + RotL64(aCross, 3U)) + 77518479758428414U;
            aOrbiterE = (((aWandererJ + RotL64(aScatter, 57U)) + RotL64(aCarry, 11U)) + 4832061802166300011U) + RotL64(aNonceWordA, 25U);
            aOrbiterF = ((aWandererD + RotL64(aIngress, 19U)) + 11695291171006574112U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 60U)) + 7467412817843260094U) + RotL64(aNonceWordF, 7U);
            aOrbiterB = (aWandererI + RotL64(aScatter, 13U)) + 17801484124471154757U;
            aOrbiterC = (((aWandererF + RotL64(aCross, 21U)) + RotL64(aCarry, 51U)) + 5555455638503958639U) + aPhaseDOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = (aWandererA + RotL64(aPrevious, 23U)) + 5669470540733721606U;
            aOrbiterI = (aWandererB + RotL64(aIngress, 53U)) + 3042388456327784163U;
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 47U)) + RotL64(aCarry, 37U)) + 2236734925228156691U;
            aOrbiterJ = (aWandererG + RotL64(aIngress, 44U)) + 14459720401528685450U;
            aOrbiterK = (aWandererC + RotL64(aScatter, 5U)) + 4814967631216658856U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 16950679344449075945U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 6262238639302011050U;
            aOrbiterF = RotL64((aOrbiterF * 9942659897425088183U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 3522256359074996724U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 12524717897707074242U;
            aOrbiterE = RotL64((aOrbiterE * 6787771338063891989U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 13891759914865623828U) + RotL64(aNonceWordC, 54U);
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 11910250571469028666U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12311343917878428995U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 2240189915640314069U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 5365912986308810837U;
            aOrbiterG = RotL64((aOrbiterG * 15133972552032469957U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 9323732721344489753U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 13087326560957916553U;
            aOrbiterD = RotL64((aOrbiterD * 14659491687401151733U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 16398238057564892809U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 11517870519285159224U;
            aOrbiterH = RotL64((aOrbiterH * 1501848878469712681U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 7758285512254776734U) + RotL64(aNonceWordB, 39U);
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 17475149091906684720U;
            aOrbiterA = RotL64((aOrbiterA * 6015816725428299273U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 2051631493975035243U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 11684740065349595315U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10918975496337269197U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 10575473798991451167U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 8267005776169272822U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13166868678285963961U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 6249698995716039231U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 13808085811784323978U;
            aOrbiterJ = RotL64((aOrbiterJ * 3897731011582061983U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 2739364646624876985U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 77518479758428414U;
            aOrbiterK = RotL64((aOrbiterK * 6977724811175035551U), 13U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterJ, 58U);
            aIngress = aIngress + (RotL64(aOrbiterE, 21U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 11U));
            aIngress = aIngress + (RotL64(aOrbiterD, 41U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 13U));
            aIngress = aIngress + RotL64(aOrbiterA, 60U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterH, 3U)) + aOrbiterE);
            aWandererE = aWandererE + (((RotL64(aCross, 13U) + aOrbiterA) + RotL64(aOrbiterG, 10U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterB, 29U)) + aOrbiterE) + aPhaseDWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aScatter, 22U) + RotL64(aOrbiterD, 37U)) + aOrbiterF);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterD, 35U)) + aOrbiterI);
            aWandererA = aWandererA + (((RotL64(aScatter, 37U) + RotL64(aOrbiterC, 51U)) + aOrbiterK) + RotL64(aCarry, 47U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterG, 48U));
            aWandererK = aWandererK + (((RotL64(aCross, 35U) + aOrbiterG) + RotL64(aOrbiterB, 53U)) + RotL64(aCarry, 53U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterG, 19U)) + aOrbiterD) + RotL64(aNonceWordD, 19U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 20U) + RotL64(aOrbiterB, 27U)) + aOrbiterC);
            aWandererD = aWandererD ^ (((RotL64(aCross, 11U) + aOrbiterG) + RotL64(aOrbiterF, 23U)) + RotL64(aNonceWordE, 13U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererE, 24U) ^ aWandererJ);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 21U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 13U));
            aCarry = aCarry + RotL64(aWandererK, 53U);
            aCarry = aCarry + RotL64(aIngress, 48U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 13U) ^ RotL64(aNonceWordE, 27U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 11866U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneA[((aIndex + 12521U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 19U) ^ RotL64(aNonceWordC, 39U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 14954U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneC[((aIndex + 13866U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 12U) + RotL64(aCarry, 27U)) + (RotL64(aCross, 51U) ^ RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterK = (aWandererH + RotL64(aScatter, 6U)) + 10404808878585437255U;
            aOrbiterA = ((aWandererF + RotL64(aIngress, 41U)) + RotL64(aCarry, 35U)) + 10587858736301591439U;
            aOrbiterJ = (aWandererI + RotL64(aCross, 21U)) + 1430530909801644435U;
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 39U)) + 9090938022430118902U) + RotL64(aNonceWordB, 53U);
            aOrbiterG = (((aWandererJ + RotL64(aScatter, 44U)) + RotL64(aCarry, 5U)) + 12936604311751121235U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = (aWandererB + RotL64(aPrevious, 3U)) + 1000583006020232032U;
            aOrbiterH = ((aWandererA + RotL64(aCross, 37U)) + RotL64(aCarry, 23U)) + 12352532088997042232U;
            aOrbiterF = (aWandererG + RotL64(aIngress, 13U)) + 16723410947058502564U;
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 23U)) + 16614089235313154270U) + RotL64(aNonceWordH, 37U);
            aOrbiterB = (aWandererD + RotL64(aIngress, 19U)) + 4245553025593349277U;
            aOrbiterE = ((aWandererK + RotL64(aCross, 35U)) + 3353146318549477494U) + aPhaseDOrbiterAssignSaltB[((aIndex + 16U)) & S_SALT1];
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 5935727336135635196U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 10312187090293319667U;
            aOrbiterJ = RotL64((aOrbiterJ * 1395964500396711899U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 12192843181244744484U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 2542570124502586365U;
            aOrbiterC = RotL64((aOrbiterC * 17222847847573534963U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 3315472769469002444U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 17512858811783071174U;
            aOrbiterA = RotL64((aOrbiterA * 9070400454074283765U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 16633218007427888082U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 2502077714838858460U;
            aOrbiterG = RotL64((aOrbiterG * 970762420815997725U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 14792910273226469214U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 15739513291150783151U;
            aOrbiterF = RotL64((aOrbiterF * 11896279674116906915U), 3U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterD) + 2192903544350345992U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]) + RotL64(aNonceWordC, 15U);
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 844428341223009295U) ^ RotL64(aNonceWordA, 9U);
            aOrbiterB = RotL64((aOrbiterB * 4768368713974002539U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 2998511458298901402U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 7790789639864783373U;
            aOrbiterK = RotL64((aOrbiterK * 9173097618440495497U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 4540735375055164995U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 13700342877362633034U;
            aOrbiterD = RotL64((aOrbiterD * 14730797752841670505U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 16966725424259324323U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 5945539295893015935U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12226268057062268981U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 12560355243513521281U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 2104086086480258265U;
            aOrbiterI = RotL64((aOrbiterI * 17989755118752755577U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 4476697099257280568U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 10404808878585437255U;
            aOrbiterE = RotL64((aOrbiterE * 6245415417832089357U), 43U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterJ, 47U);
            aIngress = aIngress + (RotL64(aOrbiterK, 11U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 29U));
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterC, 5U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterI, 54U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aIngress, 39U) + aOrbiterK) + RotL64(aOrbiterC, 35U)) + RotL64(aNonceWordF, 38U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterK, 52U)) + aOrbiterG) + RotL64(aCarry, 23U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 50U) + aOrbiterA) + RotL64(aOrbiterG, 29U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 57U) + RotL64(aOrbiterD, 19U)) + aOrbiterG) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterA, 41U));
            aWandererE = aWandererE + ((RotL64(aCross, 35U) + RotL64(aOrbiterI, 5U)) + aOrbiterF);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterG, 43U)) + aOrbiterH) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aPrevious, 47U) + aOrbiterC) + RotL64(aOrbiterI, 23U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterF, 57U)) + aOrbiterG) + RotL64(aNonceWordD, 51U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 14U) + RotL64(aOrbiterE, 26U)) + aOrbiterD) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterJ, 37U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererE, 21U) ^ aWandererA);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 58U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + (RotL64(aWandererC, 43U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererF, 48U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 60U) ^ RotL64(aNonceWordE, 37U)) ^ RotL64(aNonceWordB, 21U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 21254U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 20128U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 35U) ^ RotL64(aNonceWordG, 47U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 19525U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 20849U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 11U) + RotL64(aCarry, 58U)) ^ (RotL64(aIngress, 23U) + RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterA = (aWandererE + RotL64(aPrevious, 57U)) + 12380376990224645149U;
            aOrbiterD = ((aWandererA + RotL64(aIngress, 29U)) + 18296928500297384014U) + aPhaseDOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = ((aWandererH + RotL64(aCross, 48U)) + 3550626816361145100U) + RotL64(aNonceWordE, 45U);
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 3U)) + RotL64(aCarry, 53U)) + 2667792936946706027U;
            aOrbiterC = (aWandererC + RotL64(aCross, 19U)) + 12020969779370926953U;
            aOrbiterF = (((aWandererI + RotL64(aPrevious, 11U)) + RotL64(aCarry, 47U)) + 737340727886903447U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = ((aWandererD + RotL64(aIngress, 27U)) + RotL64(aCarry, 39U)) + 1681797651799760502U;
            aOrbiterJ = ((aWandererB + RotL64(aScatter, 53U)) + 2956186342689489064U) + RotL64(aNonceWordG, 9U);
            aOrbiterK = (aWandererF + RotL64(aCross, 23U)) + 1876852870402977177U;
            aOrbiterG = (aWandererK + RotL64(aScatter, 14U)) + 6433205819353555071U;
            aOrbiterB = (aWandererG + RotL64(aIngress, 37U)) + 9065076854974222998U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 3254410578766789992U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 2005081975473815576U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9947701153722014085U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 15992999234834560419U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 3458344156815120948U;
            aOrbiterC = RotL64((aOrbiterC * 1668460113964608051U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 17069783053664877727U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 1260234710193913099U;
            aOrbiterF = RotL64((aOrbiterF * 4561226779897414381U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 3825186451876061335U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 2905344294992827535U;
            aOrbiterH = RotL64((aOrbiterH * 2469896090698580795U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 18141402347899180617U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 8760129857609925066U;
            aOrbiterJ = RotL64((aOrbiterJ * 2507999156108123047U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 594052473780678210U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 13216719212966128379U) ^ RotL64(aNonceWordD, 15U);
            aOrbiterK = RotL64((aOrbiterK * 10691355329696722303U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 10029948739466316169U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 11912428807431992996U;
            aOrbiterG = RotL64((aOrbiterG * 85016510811938307U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 8735634019801417287U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 12785916159063273545U;
            aOrbiterB = RotL64((aOrbiterB * 1161917531260663357U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 367752057919802452U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 3961036242431041564U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16352646009782597315U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 3858415336170090719U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 14325258358254321551U;
            aOrbiterD = RotL64((aOrbiterD * 12080431158781060059U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 16872184337970977180U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 12380376990224645149U) ^ RotL64(aNonceWordF, 37U);
            aOrbiterE = RotL64((aOrbiterE * 16559121155413059221U), 27U);
            //
            aIngress = RotL64(aOrbiterC, 27U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterA, 35U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterK, 19U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterG, 12U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + RotL64(aOrbiterH, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aCross, 39U) + aOrbiterI) + RotL64(aOrbiterE, 60U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 54U) + RotL64(aOrbiterJ, 37U)) + aOrbiterD);
            aWandererK = aWandererK + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterD, 29U)) + aOrbiterC) + RotL64(aCarry, 3U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 57U) + aOrbiterH) + RotL64(aOrbiterD, 39U)) + RotL64(aNonceWordH, 40U));
            aWandererI = aWandererI + ((RotL64(aCross, 11U) + aOrbiterA) + RotL64(aOrbiterH, 35U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 24U) + RotL64(aOrbiterC, 23U)) + aOrbiterF) + RotL64(aNonceWordA, 31U));
            aWandererE = aWandererE + (((RotL64(aScatter, 41U) + RotL64(aOrbiterJ, 13U)) + aOrbiterI) + aPhaseDWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 29U) + aOrbiterH) + RotL64(aOrbiterG, 19U));
            aWandererA = aWandererA + (((RotL64(aIngress, 21U) + RotL64(aOrbiterK, 43U)) + aOrbiterF) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterD, 6U)) + aOrbiterK);
            aWandererD = aWandererD + (((RotL64(aScatter, 5U) + RotL64(aOrbiterF, 27U)) + aOrbiterB) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererB, 58U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererF, 21U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererG);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 37U));
            aCarry = aCarry + RotL64(aWandererE, 11U);
            aCarry = aCarry + RotL64(aIngress, 44U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 27U) ^ RotL64(aNonceWordG, 48U)) ^ RotL64(aNonceWordC, 13U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 26119U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25971U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 27U) ^ RotL64(aNonceWordB, 41U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27055U)) & S_BLOCK1], 6U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 26318U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 35U) ^ RotL64(aCarry, 47U)) ^ (RotL64(aCross, 21U) + RotL64(aIngress, 60U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 5U)) + 11410829607777684449U;
            aOrbiterC = (aWandererE + RotL64(aCross, 41U)) + 7502698839700975347U;
            aOrbiterD = ((aWandererC + RotL64(aIngress, 21U)) + RotL64(aCarry, 23U)) + 13267685058252106173U;
            aOrbiterI = ((aWandererK + RotL64(aScatter, 43U)) + RotL64(aCarry, 47U)) + 238242706996630625U;
            aOrbiterA = (aWandererI + RotL64(aPrevious, 37U)) + 8184695499511454281U;
            aOrbiterH = (aWandererA + RotL64(aCross, 35U)) + 12767823220461985403U;
            aOrbiterG = (aWandererD + RotL64(aScatter, 14U)) + 12293198423143850330U;
            aOrbiterK = (((aWandererB + RotL64(aIngress, 51U)) + 11149495229952495939U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 16U)) & S_SALT1]) + RotL64(aNonceWordH, 9U);
            aOrbiterB = (((aWandererG + RotL64(aScatter, 19U)) + 7556992689338382800U) + aPhaseDOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1]) + RotL64(aNonceWordA, 47U);
            aOrbiterJ = ((aWandererF + RotL64(aCross, 27U)) + RotL64(aCarry, 37U)) + 3431338808774134649U;
            aOrbiterF = (aWandererH + RotL64(aPrevious, 56U)) + 16863099140844995099U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 17872458049880677604U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 16760153457252546974U;
            aOrbiterD = RotL64((aOrbiterD * 11225037229069712805U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 3115544493537438408U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 4359882942759752958U;
            aOrbiterH = RotL64((aOrbiterH * 561477566995575801U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 13387113067202396536U) + RotL64(aNonceWordF, 52U);
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 12955690074544490161U;
            aOrbiterK = RotL64((aOrbiterK * 12449941770827974511U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 15614054443728226807U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 1939441328066616114U;
            aOrbiterJ = RotL64((aOrbiterJ * 4484917074808974359U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 4599016263007782537U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 9962305629016158048U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1496184427500037279U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 8428467674122750557U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 3938884087806393439U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12810531094050481761U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 6018636830758044658U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 1510372000641305416U;
            aOrbiterG = RotL64((aOrbiterG * 9002834928626918247U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 17592782466215337843U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 8119921507606870360U;
            aOrbiterB = RotL64((aOrbiterB * 1299795061644535485U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 8753237702359236964U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 12389957327067768090U) ^ RotL64(aNonceWordE, 51U);
            aOrbiterF = RotL64((aOrbiterF * 4586786761936601607U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 17791633199762408683U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 11606494383812053915U;
            aOrbiterC = RotL64((aOrbiterC * 13041480602055778521U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 4418614662439151979U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 11410829607777684449U;
            aOrbiterA = RotL64((aOrbiterA * 3342270212301058781U), 21U);
            //
            aIngress = RotL64(aOrbiterD, 3U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 6U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + (RotL64(aOrbiterI, 39U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 11U));
            aIngress = aIngress + RotL64(aOrbiterB, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aIngress, 26U) + aOrbiterF) + RotL64(aOrbiterK, 19U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterK, 43U)) + aOrbiterI);
            aWandererD = aWandererD + ((RotL64(aPrevious, 53U) + aOrbiterH) + RotL64(aOrbiterF, 27U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 21U) + aOrbiterB) + RotL64(aOrbiterG, 34U)) + RotL64(aNonceWordD, 31U));
            aWandererC = aWandererC + (((RotL64(aScatter, 19U) + RotL64(aOrbiterA, 3U)) + aOrbiterI) + RotL64(aCarry, 51U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterE, 57U)) + aOrbiterA);
            aWandererB = aWandererB + (((RotL64(aIngress, 37U) + aOrbiterF) + RotL64(aOrbiterI, 11U)) + RotL64(aCarry, 19U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 3U) + aOrbiterC) + RotL64(aOrbiterI, 5U)) + aPhaseDWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aIngress, 5U) + RotL64(aOrbiterA, 13U)) + aOrbiterG);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterG, 29U)) + aOrbiterD);
            aWandererE = aWandererE + ((((RotL64(aCross, 50U) + RotL64(aOrbiterC, 46U)) + aOrbiterJ) + RotL64(aNonceWordG, 37U)) + aPhaseDWandererUpdateSaltF[((aIndex + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 4U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererC, 27U) ^ aWandererJ);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 51U));
            aCarry = aCarry + RotL64(aWandererG, 47U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 19U) ^ RotL64(aNonceWordF, 39U)) ^ RotL64(aNonceWordH, 3U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 27410U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27405U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 40U) ^ RotL64(aNonceWordA, 13U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 31352U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28472U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 35U) + RotL64(aIngress, 3U)) ^ (RotL64(aCarry, 18U) ^ RotL64(aPrevious, 47U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterI = ((aWandererD + RotL64(aCross, 53U)) + 14624277139785904404U) + RotL64(aNonceWordE, 3U);
            aOrbiterF = ((aWandererA + RotL64(aIngress, 47U)) + RotL64(aCarry, 47U)) + 6966977309498165611U;
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 5U)) + 205536824352530761U) + RotL64(aNonceWordB, 16U);
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 10U)) + RotL64(aCarry, 27U)) + 16629575265808255692U;
            aOrbiterJ = ((aWandererG + RotL64(aCross, 19U)) + 596881340147972746U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = (aWandererK + RotL64(aPrevious, 37U)) + 11944412799107412650U;
            aOrbiterC = (aWandererC + RotL64(aIngress, 51U)) + 4615021315668210206U;
            aOrbiterA = ((aWandererE + RotL64(aScatter, 42U)) + RotL64(aCarry, 51U)) + 8497630055977606216U;
            aOrbiterG = (aWandererH + RotL64(aIngress, 39U)) + 11131601107309336885U;
            aOrbiterH = (aWandererF + RotL64(aPrevious, 3U)) + 5935883479805510099U;
            aOrbiterK = ((aWandererI + RotL64(aScatter, 29U)) + 15629346719765798174U) + aPhaseDOrbiterAssignSaltF[((aIndex + 10U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 5279128339113651273U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 16778365912440331821U;
            aOrbiterE = RotL64((aOrbiterE * 705421028266789241U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 16003052937645491524U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 6723226158737614764U;
            aOrbiterJ = RotL64((aOrbiterJ * 16690657664909260573U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 9785784358981219543U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 10055457337292292710U;
            aOrbiterB = RotL64((aOrbiterB * 17919129940751761111U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 11779163108592974175U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 1177999477942202687U;
            aOrbiterC = RotL64((aOrbiterC * 13475069421684114643U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 9190694445141492214U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 15605342360346353457U;
            aOrbiterA = RotL64((aOrbiterA * 14547769706392595647U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 14877565450677523492U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 1074095623308025684U;
            aOrbiterG = RotL64((aOrbiterG * 7884068939436891093U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 12803174154216941583U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 8813356463693637033U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4898237214617563167U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 6063909634038581414U) + RotL64(aNonceWordF, 19U);
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 15112191502834052566U) ^ RotL64(aNonceWordC, 7U);
            aOrbiterK = RotL64((aOrbiterK * 6780741782103553485U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 13926459034757240311U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 4324555954703597591U;
            aOrbiterI = RotL64((aOrbiterI * 18068922072149745351U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 7183063131331255506U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 18072787091203847052U;
            aOrbiterF = RotL64((aOrbiterF * 12530396154012878153U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 10143386327707219710U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 14624277139785904404U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12100828883424264587U), 11U);
            //
            aIngress = RotL64(aOrbiterJ, 14U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterE, 27U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterD, 35U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterF, 43U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 53U));
            aIngress = aIngress + RotL64(aOrbiterH, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aScatter, 51U) + aOrbiterK) + RotL64(aOrbiterJ, 23U)) + RotL64(aNonceWordH, 57U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 21U) + aOrbiterA) + RotL64(aOrbiterD, 6U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterG, 41U)) + aOrbiterE) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 5U) + aOrbiterI) + RotL64(aOrbiterF, 37U)) + RotL64(aNonceWordD, 31U));
            aWandererH = aWandererH + ((RotL64(aScatter, 35U) + RotL64(aOrbiterC, 39U)) + aOrbiterH);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterD, 27U)) + aOrbiterH);
            aWandererE = aWandererE + ((RotL64(aPrevious, 30U) + RotL64(aOrbiterI, 57U)) + aOrbiterB);
            aWandererI = aWandererI ^ (((RotL64(aCross, 41U) + aOrbiterJ) + RotL64(aOrbiterB, 51U)) + aPhaseDWandererUpdateSaltB[((aIndex + 18U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 13U) + RotL64(aOrbiterJ, 47U)) + aOrbiterE) + RotL64(aCarry, 27U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 53U) + aOrbiterK) + RotL64(aOrbiterB, 14U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 28U) + aOrbiterE) + RotL64(aOrbiterA, 29U)) + RotL64(aCarry, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererE, 44U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 51U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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

void TwistExpander_Karate_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xD5D6377133940441ULL + 0x9485963461F04E56ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xCBBC34F858830A43ULL + 0x8D4F6107AC08F6EBULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xB7082722273F88B3ULL + 0xF295836FCF5CE9BDULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xDA657034802C0363ULL + 0xA606492847E9C4D2ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xB7519799117FE9F3ULL + 0xF6418A2DF1C7753EULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x8E3C69BA98170A71ULL + 0xC0CE0D65E3C224B5ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xA9AC7EBD63F0C4E1ULL + 0x949257E7638C7ED7ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xEC8EF6BF28B51177ULL + 0xA7281931DBB949A7ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordE, 29U) ^ RotL64(aNonceWordD, 3U));
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 2100U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneC[((aIndex + 1233U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 57U) ^ RotL64(aNonceWordB, 40U)) ^ RotL64(aNonceWordC, 21U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 5058U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 5250U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCarry, 5U)) + (RotL64(aPrevious, 24U) + RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 11U)) + RotL64(aCarry, 13U)) + 9220392006207660113U;
            aOrbiterF = (aWandererE + RotL64(aCross, 54U)) + 11305018553489132882U;
            aOrbiterC = ((aWandererG + RotL64(aIngress, 41U)) + 5860373868073513684U) + RotL64(aNonceWordF, 51U);
            aOrbiterD = (aWandererD + RotL64(aPrevious, 27U)) + 12319586170883987589U;
            aOrbiterH = ((aWandererH + RotL64(aScatter, 19U)) + 14072333614354649021U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = ((aWandererI + RotL64(aCross, 3U)) + RotL64(aCarry, 53U)) + 9332158529453194608U;
            aOrbiterK = (aWandererB + RotL64(aPrevious, 43U)) + 3860569321145958686U;
            aOrbiterE = ((aWandererC + RotL64(aIngress, 5U)) + 8119005668901240093U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 47U)) + RotL64(aCarry, 57U)) + 13918259792880333239U;
            aOrbiterG = ((aWandererK + RotL64(aCross, 14U)) + 6938856216758228704U) + RotL64(aNonceWordH, 27U);
            aOrbiterB = (aWandererJ + RotL64(aIngress, 39U)) + 3960905839118710604U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 6043879193734253929U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 15691425268831319195U;
            aOrbiterC = RotL64((aOrbiterC * 7189195135654636271U), 41U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterH) + 14912209933584715274U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1]) + RotL64(aNonceWordA, 19U);
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 16180183395910618923U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3942858974766467849U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 4966642362507707776U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 6962226782462822861U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3647802407741095419U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 12409120845092026295U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 2302946450253872465U;
            aOrbiterD = RotL64((aOrbiterD * 7099576330777297911U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 16118304388937163838U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 15968419034359049422U;
            aOrbiterK = RotL64((aOrbiterK * 11736207775827080165U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 17098982091525008231U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 10298979200690822062U;
            aOrbiterI = RotL64((aOrbiterI * 12620028874653521945U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 552826643694256437U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 11786560990790695378U) ^ RotL64(aNonceWordG, 29U);
            aOrbiterB = RotL64((aOrbiterB * 11190309640069208311U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 13730399230389329793U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 17614226859252305432U;
            aOrbiterF = RotL64((aOrbiterF * 2640019643570222977U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 1062738267846296283U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 13959480457644980835U;
            aOrbiterH = RotL64((aOrbiterH * 1194145909157002977U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 4635071137794189167U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 13374502212707796180U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 129680788767298945U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 11479902881487238033U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 9220392006207660113U;
            aOrbiterG = RotL64((aOrbiterG * 1437457810224888809U), 57U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterC, 39U);
            aIngress = aIngress + (RotL64(aOrbiterG, 35U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterD, 54U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterH, 51U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterI, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aScatter, 3U) + aOrbiterG) + RotL64(aOrbiterH, 37U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterD, 39U)) + aOrbiterG);
            aWandererA = aWandererA ^ (((RotL64(aCross, 60U) + aOrbiterB) + RotL64(aOrbiterA, 48U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aIngress, 39U) + RotL64(aOrbiterG, 41U)) + aOrbiterI) + RotL64(aNonceWordB, 43U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 43U) + aOrbiterC) + RotL64(aOrbiterA, 19U)) + RotL64(aNonceWordE, 20U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterJ, 11U)) + aOrbiterH) + RotL64(aCarry, 11U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 58U) + RotL64(aOrbiterG, 43U)) + aOrbiterA);
            aWandererF = aWandererF + ((RotL64(aIngress, 35U) + aOrbiterK) + RotL64(aOrbiterG, 57U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 13U) + aOrbiterE) + RotL64(aOrbiterK, 6U));
            aWandererG = aWandererG + (((RotL64(aIngress, 37U) + RotL64(aOrbiterA, 51U)) + aOrbiterE) + RotL64(aCarry, 23U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterF, 35U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererI, 34U) ^ aWandererD);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 27U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 51U));
            aCarry = aCarry + (RotL64(aWandererE, 6U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 57U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 58U) ^ RotL64(aNonceWordB, 39U)) ^ RotL64(aNonceWordC, 3U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 6936U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 10836U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 57U) ^ RotL64(aNonceWordA, 47U));
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 6655U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneB[((aIndex + 9440U)) & S_BLOCK1], 34U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 51U) + RotL64(aCross, 19U)) ^ (RotL64(aCarry, 35U) ^ RotL64(aPrevious, 4U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterA = (aWandererB + RotL64(aIngress, 53U)) + 11480359716598965890U;
            aOrbiterG = (aWandererD + RotL64(aCross, 39U)) + 15431182525482873419U;
            aOrbiterH = ((aWandererF + RotL64(aScatter, 11U)) + 11360504974812776707U) + RotL64(aNonceWordE, 29U);
            aOrbiterI = (aWandererC + RotL64(aPrevious, 56U)) + 9292576416573382769U;
            aOrbiterD = ((aWandererA + RotL64(aIngress, 51U)) + RotL64(aCarry, 27U)) + 1549257414531028975U;
            aOrbiterB = ((aWandererK + RotL64(aScatter, 27U)) + RotL64(aCarry, 53U)) + 5347769463033129317U;
            aOrbiterK = (aWandererE + RotL64(aCross, 43U)) + 17019199177478377234U;
            aOrbiterJ = (((aWandererG + RotL64(aPrevious, 41U)) + RotL64(aCarry, 41U)) + 16558106007323125094U) + RotL64(aNonceWordC, 46U);
            aOrbiterE = ((aWandererI + RotL64(aCross, 21U)) + 3976182233825939422U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 23U)) + 2889047161195954395U) + aPhaseEOrbiterAssignSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = (aWandererH + RotL64(aScatter, 30U)) + 2241831345026962605U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 12850802412140579294U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 13541744735436450160U;
            aOrbiterH = RotL64((aOrbiterH * 906089290000537439U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 2085863085516538212U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 2969034221711544086U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7768528124408400403U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 6482666944512391472U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 16969153556875844613U;
            aOrbiterD = RotL64((aOrbiterD * 9483462388353216219U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 5161314086757363678U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 7150282484670673211U;
            aOrbiterK = RotL64((aOrbiterK * 8522427002337918663U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 5465304381272305847U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 2344610773390354017U) ^ RotL64(aNonceWordF, 21U);
            aOrbiterE = RotL64((aOrbiterE * 17010258514288089191U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 8335906578006588582U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 13668796013474193793U;
            aOrbiterA = RotL64((aOrbiterA * 8228000547141147777U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 9663362594301419686U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 3683773739120343413U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8319320803406104749U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 2538583190438044942U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 4454069062219406996U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16329554225309389599U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 17177136683616247897U) + RotL64(aNonceWordG, 17U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 3680497519697457252U;
            aOrbiterJ = RotL64((aOrbiterJ * 6479357366957384599U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 16812938441063719463U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 4545693142067578891U;
            aOrbiterF = RotL64((aOrbiterF * 17479957806084346527U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 9232311730019478327U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 11480359716598965890U;
            aOrbiterC = RotL64((aOrbiterC * 6678546065399772697U), 29U);
            //
            aIngress = RotL64(aOrbiterH, 46U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterB, 23U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 41U));
            aIngress = aIngress + (RotL64(aOrbiterI, 43U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + RotL64(aOrbiterK, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterD, 41U)) + aOrbiterC) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 35U) + aOrbiterK) + RotL64(aOrbiterJ, 27U)) + RotL64(aNonceWordB, 49U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterD, 18U)) + aOrbiterK) + aPhaseEWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aIngress, 20U) + aOrbiterD) + RotL64(aOrbiterI, 11U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterC, 29U)) + aOrbiterF);
            aWandererD = aWandererD + (((RotL64(aIngress, 13U) + aOrbiterH) + RotL64(aOrbiterA, 57U)) + RotL64(aNonceWordA, 19U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterB, 35U)) + aOrbiterG);
            aWandererF = aWandererF + (((RotL64(aScatter, 50U) + aOrbiterA) + RotL64(aOrbiterI, 53U)) + RotL64(aCarry, 53U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 41U) + aOrbiterC) + RotL64(aOrbiterA, 13U));
            aWandererB = aWandererB + (((RotL64(aCross, 37U) + aOrbiterD) + RotL64(aOrbiterB, 44U)) + RotL64(aCarry, 13U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 23U) + aOrbiterE) + RotL64(aOrbiterG, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 41U) ^ aWandererA);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 44U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 51U));
            aCarry = aCarry + (RotL64(aWandererE, 37U) ^ aWandererC);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + RotL64(aWandererF, 13U);
            aCarry = aCarry + RotL64(aIngress, 46U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 27U) ^ RotL64(aNonceWordF, 35U)) ^ RotL64(aNonceWordA, 44U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 15862U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 11248U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 57U) ^ RotL64(aNonceWordE, 48U));
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 14097U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneC[((aIndex + 12073U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 51U) + RotL64(aPrevious, 39U)) ^ (RotL64(aIngress, 27U) + RotL64(aCross, 10U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 29U)) + 6733949564325516029U) + aPhaseEOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = ((aWandererB + RotL64(aCross, 57U)) + RotL64(aCarry, 11U)) + 7304098437143918796U;
            aOrbiterA = (aWandererC + RotL64(aScatter, 37U)) + 3923949518391777800U;
            aOrbiterB = (aWandererA + RotL64(aIngress, 50U)) + 14243591003388927124U;
            aOrbiterJ = (((aWandererD + RotL64(aScatter, 39U)) + 18329498724605410406U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1]) + RotL64(aNonceWordD, 9U);
            aOrbiterC = (aWandererK + RotL64(aCross, 41U)) + 13118172167747037249U;
            aOrbiterF = ((aWandererF + RotL64(aIngress, 13U)) + RotL64(aCarry, 39U)) + 5272025143849174212U;
            aOrbiterD = (((aWandererG + RotL64(aPrevious, 11U)) + RotL64(aCarry, 27U)) + 16075917179214318424U) + RotL64(aNonceWordG, 5U);
            aOrbiterI = (aWandererE + RotL64(aCross, 22U)) + 15263590648674658399U;
            aOrbiterG = (aWandererI + RotL64(aIngress, 5U)) + 13730046728289525921U;
            aOrbiterH = (aWandererJ + RotL64(aScatter, 19U)) + 7703141464499623408U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 1382279753822135359U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 2973369221699098292U) ^ RotL64(aNonceWordB, 59U);
            aOrbiterA = RotL64((aOrbiterA * 7440242040663550631U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 11578274119583013219U) + RotL64(aNonceWordF, 27U);
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 3419411247737896674U;
            aOrbiterC = RotL64((aOrbiterC * 17814942652262802991U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 2582783513078999303U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 3959762790273529677U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 383974377372162751U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 465795011576934604U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 17880826624185821135U;
            aOrbiterJ = RotL64((aOrbiterJ * 4445949147592860913U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 10819659185349413173U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 17298208553586835030U;
            aOrbiterD = RotL64((aOrbiterD * 1965860510614222093U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 12585880006661489402U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 16650193903267408586U;
            aOrbiterG = RotL64((aOrbiterG * 5781132589396936615U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 885882046325991589U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 869560078374809974U;
            aOrbiterE = RotL64((aOrbiterE * 13440973563438747181U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 11871305571797951851U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 12137095015607196226U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7618152256560808581U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 6044048326509186958U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 622564532811968856U;
            aOrbiterF = RotL64((aOrbiterF * 14988345089359014037U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 17133994029325040272U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 8612895899003926829U;
            aOrbiterI = RotL64((aOrbiterI * 2128664397481732179U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 2169081503433534750U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 6733949564325516029U;
            aOrbiterH = RotL64((aOrbiterH * 10062179904046311601U), 29U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterC, 5U);
            aIngress = aIngress + (RotL64(aOrbiterB, 13U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterI, 47U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 22U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 51U));
            aIngress = aIngress + RotL64(aOrbiterK, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 21U) + aOrbiterG) + RotL64(aOrbiterA, 51U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 19U) + aOrbiterJ) + RotL64(aOrbiterK, 23U)) + RotL64(aNonceWordH, 15U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 57U) + aOrbiterA) + RotL64(aOrbiterF, 56U)) + RotL64(aNonceWordA, 42U));
            aWandererA = aWandererA + ((RotL64(aIngress, 43U) + aOrbiterD) + RotL64(aOrbiterF, 29U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 54U) + aOrbiterD) + RotL64(aOrbiterH, 35U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 13U) + RotL64(aOrbiterC, 37U)) + aOrbiterB);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 3U) + aOrbiterF) + RotL64(aOrbiterI, 48U));
            aWandererK = aWandererK + (((RotL64(aScatter, 51U) + aOrbiterK) + RotL64(aOrbiterF, 43U)) + RotL64(aCarry, 41U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterE, 19U)) + aOrbiterA) + aPhaseEWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 37U) + RotL64(aOrbiterB, 11U)) + aOrbiterF) + RotL64(aCarry, 27U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 60U) + aOrbiterD) + RotL64(aOrbiterC, 3U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + (RotL64(aWandererB, 41U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 26U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererC, 53U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererG, 21U);
            aCarry = aCarry + RotL64(aIngress, 28U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordA, 21U) ^ RotL64(aNonceWordB, 29U)) ^ RotL64(aNonceWordH, 3U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 18061U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((aIndex + 18684U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 21U) ^ RotL64(aNonceWordG, 37U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 21716U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneD[((aIndex + 20702U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aIngress, 27U)) ^ (RotL64(aPrevious, 54U) + RotL64(aCarry, 13U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterK = (((aWandererG + RotL64(aIngress, 53U)) + 6318740973868639425U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 16U)) & S_SALT1]) + RotL64(aNonceWordG, 44U);
            aOrbiterC = (aWandererI + RotL64(aCross, 34U)) + 5487840061430920881U;
            aOrbiterH = (aWandererE + RotL64(aScatter, 3U)) + 10258706763248072672U;
            aOrbiterE = (aWandererF + RotL64(aPrevious, 21U)) + 18356875269730338208U;
            aOrbiterI = (aWandererA + RotL64(aCross, 41U)) + 12883160282903147010U;
            aOrbiterG = (((aWandererD + RotL64(aPrevious, 43U)) + RotL64(aCarry, 19U)) + 1010140474942697730U) + RotL64(aNonceWordH, 17U);
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 26U)) + 17733939421700898293U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = ((aWandererK + RotL64(aIngress, 29U)) + RotL64(aCarry, 57U)) + 13693055887924981201U;
            aOrbiterB = ((aWandererC + RotL64(aScatter, 39U)) + RotL64(aCarry, 13U)) + 14574732452793385269U;
            aOrbiterF = (aWandererB + RotL64(aIngress, 37U)) + 10832873941223609012U;
            aOrbiterD = (aWandererJ + RotL64(aCross, 19U)) + 8212600587135328040U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 5312744319781971178U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterK) ^ 6173741211706546923U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1]) ^ RotL64(aNonceWordD, 37U);
            aOrbiterH = RotL64((aOrbiterH * 12854414066390848249U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 3693249147883790810U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 18365859989736602556U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3348463719324104997U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 10645056678337549771U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 1175668356822251045U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6579675292775345579U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 13556844570541823717U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 4790355739411849736U;
            aOrbiterJ = RotL64((aOrbiterJ * 4083544011788850307U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 14905575502272644116U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 17047244574558476634U;
            aOrbiterA = RotL64((aOrbiterA * 2356386971503880047U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 10161614295718414869U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 13413914082651612468U;
            aOrbiterB = RotL64((aOrbiterB * 16224039093981079491U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 6072693130156927774U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 4333656233793103787U;
            aOrbiterF = RotL64((aOrbiterF * 9374745547133955709U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 17209776289202130250U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 11752001118070361543U;
            aOrbiterD = RotL64((aOrbiterD * 4416523594812872339U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 15367365111105608277U) + RotL64(aNonceWordF, 45U);
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 8650687767097460704U;
            aOrbiterK = RotL64((aOrbiterK * 11430451559660578667U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 18074648514448405693U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 10857586858462237581U;
            aOrbiterC = RotL64((aOrbiterC * 3722891011080095849U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 17219932344278345591U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 6318740973868639425U;
            aOrbiterE = RotL64((aOrbiterE * 8846295038878812229U), 53U);
            //
            aIngress = RotL64(aOrbiterA, 5U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 10U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 37U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 23U));
            aIngress = aIngress + RotL64(aOrbiterK, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aScatter, 57U) + aOrbiterF) + RotL64(aOrbiterC, 51U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterK, 21U)) + aOrbiterB);
            aWandererG = aWandererG + ((RotL64(aPrevious, 20U) + aOrbiterA) + RotL64(aOrbiterK, 23U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterD, 4U)) + aOrbiterJ);
            aWandererD = aWandererD + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterC, 37U)) + aOrbiterD) + RotL64(aCarry, 57U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterE, 29U)) + aOrbiterD);
            aWandererK = aWandererK + ((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterE, 43U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterD, 19U)) + aOrbiterG);
            aWandererA = aWandererA + ((RotL64(aIngress, 60U) + RotL64(aOrbiterF, 35U)) + aOrbiterI);
            aWandererJ = aWandererJ ^ ((((RotL64(aPrevious, 23U) + RotL64(aOrbiterE, 39U)) + aOrbiterA) + RotL64(aNonceWordE, 39U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aScatter, 47U) + aOrbiterH) + RotL64(aOrbiterF, 14U)) + RotL64(aCarry, 23U)) + RotL64(aNonceWordC, 21U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 21U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 52U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererB, 5U);
            aCarry = aCarry + RotL64(aIngress, 46U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 5U) ^ RotL64(aNonceWordA, 58U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 24055U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneA[((aIndex + 25991U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 58U) ^ RotL64(aNonceWordD, 19U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 24559U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneA[((aIndex + 24808U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 41U) + RotL64(aIngress, 53U)) + (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 26U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterB = (aWandererD + RotL64(aPrevious, 3U)) + 4751694786009671052U;
            aOrbiterK = (aWandererG + RotL64(aIngress, 53U)) + 16362725160370844224U;
            aOrbiterJ = ((aWandererI + RotL64(aCross, 13U)) + 6360885380915941057U) + RotL64(aNonceWordD, 27U);
            aOrbiterF = (aWandererA + RotL64(aScatter, 30U)) + 5154536007972297036U;
            aOrbiterC = (aWandererK + RotL64(aCross, 37U)) + 9362540581874808253U;
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 21U)) + 13902493871525612934U) + aPhaseEOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = ((aWandererF + RotL64(aIngress, 39U)) + RotL64(aCarry, 39U)) + 10208452885367546542U;
            aOrbiterE = (((aWandererE + RotL64(aScatter, 47U)) + RotL64(aCarry, 5U)) + 3117030377279160998U) + RotL64(aNonceWordA, 21U);
            aOrbiterI = (((aWandererH + RotL64(aCross, 43U)) + RotL64(aCarry, 35U)) + 17286247690414027870U) + aPhaseEOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = (aWandererJ + RotL64(aIngress, 19U)) + 3930314320040949141U;
            aOrbiterG = (aWandererB + RotL64(aPrevious, 26U)) + 7289525252391668404U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 3434167955466809185U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 17852573095128575663U;
            aOrbiterJ = RotL64((aOrbiterJ * 1485660158767033425U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 6137259687928853253U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 13992510605237574698U;
            aOrbiterH = RotL64((aOrbiterH * 15346263295995333395U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 6470556523400123474U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 4333255670390099293U;
            aOrbiterE = RotL64((aOrbiterE * 11089933812030082647U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 7700424876430257995U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 16920736951239453071U;
            aOrbiterD = RotL64((aOrbiterD * 8920407493132380497U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 1635071690430295730U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 9966700845966398620U) ^ RotL64(aNonceWordC, 25U);
            aOrbiterB = RotL64((aOrbiterB * 17210048121896546867U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 9833458070123027075U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = (((aOrbiterF ^ aOrbiterK) ^ 1990346556486746432U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1]) ^ RotL64(aNonceWordE, 59U);
            aOrbiterF = RotL64((aOrbiterF * 8704943923474148699U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 13339523466436517327U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 5018264760406215603U;
            aOrbiterA = RotL64((aOrbiterA * 2769197961801783627U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 123427497520755346U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 4535841104215792886U;
            aOrbiterI = RotL64((aOrbiterI * 1417676310539177131U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 3525925567359163763U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 3273741481392187986U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16116160744647235811U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 6230742908784102407U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 7578784912496239362U;
            aOrbiterK = RotL64((aOrbiterK * 2614448818452560369U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 14669810330213234082U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 4751694786009671052U;
            aOrbiterC = RotL64((aOrbiterC * 9583151676882991817U), 19U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterA, 14U);
            aIngress = aIngress + (RotL64(aOrbiterB, 39U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 35U));
            aIngress = aIngress + (RotL64(aOrbiterK, 23U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 60U));
            aIngress = aIngress + RotL64(aOrbiterD, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterB, 3U)) + aOrbiterH);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 10U) + RotL64(aOrbiterC, 39U)) + aOrbiterJ) + RotL64(aCarry, 5U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 37U) + aOrbiterK) + RotL64(aOrbiterH, 22U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterF, 53U)) + aOrbiterH) + RotL64(aCarry, 39U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 39U) + aOrbiterK) + RotL64(aOrbiterI, 41U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterG, 5U)) + aOrbiterE);
            aWandererF = aWandererF ^ ((((RotL64(aCross, 27U) + aOrbiterE) + RotL64(aOrbiterI, 37U)) + RotL64(aNonceWordH, 48U)) + aPhaseEWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aIngress, 42U) + aOrbiterC) + RotL64(aOrbiterA, 18U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 29U) + aOrbiterA) + RotL64(aOrbiterI, 13U));
            aWandererE = aWandererE + ((((RotL64(aIngress, 3U) + aOrbiterK) + RotL64(aOrbiterD, 11U)) + RotL64(aNonceWordF, 19U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterB, 35U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 26U));
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererI, 11U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + RotL64(aWandererA, 44U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 57U) ^ RotL64(aNonceWordC, 3U)) ^ RotL64(aNonceWordE, 21U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 29322U)) & S_BLOCK1], 46U) ^ RotL64(aOperationLaneB[((aIndex + 29795U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 35U) ^ RotL64(aNonceWordG, 19U)) ^ RotL64(aNonceWordF, 3U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 28692U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31392U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 21U) + RotL64(aCarry, 3U)) + (RotL64(aCross, 38U) ^ RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterJ = ((aWandererI + RotL64(aCross, 21U)) + 15316464782468770057U) + aPhaseEOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = ((aWandererA + RotL64(aIngress, 35U)) + 6642872057476351588U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = (aWandererH + RotL64(aScatter, 39U)) + 660732654689529192U;
            aOrbiterK = (aWandererF + RotL64(aPrevious, 51U)) + 7235418086884000655U;
            aOrbiterE = (((aWandererK + RotL64(aCross, 14U)) + RotL64(aCarry, 23U)) + 14784518476694580493U) + RotL64(aNonceWordH, 55U);
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 29U)) + RotL64(aCarry, 53U)) + 12222433977933449375U;
            aOrbiterD = (aWandererC + RotL64(aScatter, 53U)) + 8573001207708329927U;
            aOrbiterG = (((aWandererG + RotL64(aPrevious, 3U)) + RotL64(aCarry, 35U)) + 16035256260815013172U) + RotL64(aNonceWordB, 28U);
            aOrbiterB = (aWandererE + RotL64(aIngress, 27U)) + 15767726974121910203U;
            aOrbiterH = (aWandererD + RotL64(aScatter, 6U)) + 17712217935322939971U;
            aOrbiterA = (aWandererB + RotL64(aCross, 19U)) + 13488963456923357159U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 10222949131965611079U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 1495561412321657209U;
            aOrbiterC = RotL64((aOrbiterC * 9706305581868526265U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 16156530750584361434U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 7773792489045606309U;
            aOrbiterE = RotL64((aOrbiterE * 10730624207715601393U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 11544578291333360613U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 3665587867634242865U;
            aOrbiterF = RotL64((aOrbiterF * 4840528190844842595U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 15248434984650998090U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 15487979645426567581U;
            aOrbiterD = RotL64((aOrbiterD * 10868107809356766183U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 6972347795052712690U) + RotL64(aNonceWordE, 25U);
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 16074994810010431338U;
            aOrbiterG = RotL64((aOrbiterG * 1262655238856775853U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 16851139687900415292U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 14630026837021552812U;
            aOrbiterB = RotL64((aOrbiterB * 9577900853521254603U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 14236330619137368169U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 17778707026111136216U;
            aOrbiterH = RotL64((aOrbiterH * 16239561893843454747U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 9390961969105999083U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 1174881758316573228U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6602061268277529311U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 3025148570039849574U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 2813499258480831171U;
            aOrbiterJ = RotL64((aOrbiterJ * 12272555492688861861U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 15397952138592662354U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 10394648143430175275U) ^ RotL64(aNonceWordF, 27U);
            aOrbiterI = RotL64((aOrbiterI * 18195627209519212303U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 3043205345760158739U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 15316464782468770057U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8162506622688910545U), 23U);
            //
            aIngress = RotL64(aOrbiterC, 37U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 21U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 53U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + (RotL64(aOrbiterA, 40U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterF, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aCross, 28U) + aOrbiterA) + RotL64(aOrbiterE, 30U)) + RotL64(aNonceWordC, 41U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 5U) + aOrbiterB) + RotL64(aOrbiterH, 47U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 21U) + aOrbiterJ) + RotL64(aOrbiterF, 43U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterE, 11U)) + aOrbiterJ);
            aWandererA = aWandererA + ((RotL64(aScatter, 41U) + RotL64(aOrbiterI, 39U)) + aOrbiterG);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 37U) + aOrbiterC) + RotL64(aOrbiterK, 53U));
            aWandererG = aWandererG + ((((RotL64(aPrevious, 39U) + RotL64(aOrbiterF, 28U)) + aOrbiterK) + RotL64(aCarry, 5U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aCross, 24U) + RotL64(aOrbiterJ, 3U)) + aOrbiterG) + RotL64(aNonceWordA, 3U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 51U) + aOrbiterG) + RotL64(aOrbiterC, 19U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterB, 57U)) + aOrbiterD);
            aWandererE = aWandererE + (((RotL64(aScatter, 43U) + RotL64(aOrbiterD, 41U)) + aOrbiterH) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 44U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 37U));
            aCarry = aCarry + (RotL64(aWandererK, 29U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererH);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 54U));
            aCarry = aCarry + RotL64(aWandererD, 27U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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

void TwistExpander_Karate_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xDB87EFFE574904BFULL + 0xAFC8E3D79DC002A9ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xE7F5390AECB160CBULL + 0xEE6D055CBB382877ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x9756FE0CC7EFF447ULL + 0xA957F419EEB39962ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xE85DEC2D911BC5DDULL + 0xA154B13DCE200F98ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xB47A766F45387635ULL + 0xC67B33B561ED85F6ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x805999380C7DB429ULL + 0xCFC72D6A61C10CEDULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xD9CCD64C259CF677ULL + 0xA71DE1B1C8FA272AULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xBE7F8BA730ECF0FBULL + 0x9225EC64891C9DA9ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordA, 44U) ^ RotL64(aNonceWordG, 3U)) ^ RotL64(aNonceWordC, 11U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 3684U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 1385U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 27U) ^ RotL64(aNonceWordF, 35U)) ^ RotL64(aNonceWordD, 3U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 2186U)) & S_BLOCK1], 50U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 2112U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aIngress, 37U)) ^ (RotL64(aCarry, 19U) ^ RotL64(aPrevious, 4U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 47U)) + 6469584119078165548U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = (aWandererE + RotL64(aIngress, 6U)) + 14329756366517987910U;
            aOrbiterG = (aWandererB + RotL64(aScatter, 43U)) + 12890831797059772123U;
            aOrbiterE = ((aWandererC + RotL64(aCross, 19U)) + 3164503807500018990U) + RotL64(aNonceWordA, 3U);
            aOrbiterB = (aWandererF + RotL64(aIngress, 51U)) + 177531431387646836U;
            aOrbiterF = ((aWandererD + RotL64(aScatter, 27U)) + 3167421392893561015U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterK = (aWandererI + RotL64(aPrevious, 41U)) + 2813174781844753460U;
            aOrbiterC = ((aWandererJ + RotL64(aCross, 23U)) + 10953270419153249857U) + RotL64(aNonceWordG, 11U);
            aOrbiterI = ((aWandererH + RotL64(aScatter, 11U)) + RotL64(aCarry, 47U)) + 16911518309710356951U;
            aOrbiterJ = ((aWandererG + RotL64(aCross, 54U)) + RotL64(aCarry, 13U)) + 6616750447844893150U;
            aOrbiterD = ((aWandererA + RotL64(aIngress, 57U)) + RotL64(aCarry, 39U)) + 10276741398025985982U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 6206043608461213208U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 12021552904553405793U;
            aOrbiterG = RotL64((aOrbiterG * 10023362889960174909U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 15283586234744144846U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 5923238786775948571U;
            aOrbiterF = RotL64((aOrbiterF * 8200882393521882651U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 11044014510971660078U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 9351141024085076044U) ^ RotL64(aNonceWordH, 9U);
            aOrbiterH = RotL64((aOrbiterH * 13316079344614432317U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 17703395981862992420U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 10154548848376027087U;
            aOrbiterE = RotL64((aOrbiterE * 12324478347590509035U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 8836420852291617425U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 10193385413543886344U;
            aOrbiterK = RotL64((aOrbiterK * 824935982418585449U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 8248580084535685190U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 3910083671888152974U;
            aOrbiterI = RotL64((aOrbiterI * 17825311776715895927U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 12350341628569930642U) + RotL64(aNonceWordE, 4U);
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 2565977481575002842U;
            aOrbiterD = RotL64((aOrbiterD * 18233446879833776677U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 9271041067874027417U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 14289254596554201861U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7985522692852251413U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 5981802134118235214U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 14047813418129636856U;
            aOrbiterB = RotL64((aOrbiterB * 15961435325216504877U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 11808443842149398212U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 11380858372643695792U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 100198424024622179U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 10385375464069162356U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 6469584119078165548U;
            aOrbiterJ = RotL64((aOrbiterJ * 5263876933019848989U), 35U);
            //
            aIngress = RotL64(aOrbiterG, 3U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 53U));
            aIngress = aIngress + (RotL64(aOrbiterB, 5U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 41U));
            aIngress = aIngress + (RotL64(aOrbiterC, 19U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterI, 34U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterB, 3U)) + aOrbiterA);
            aWandererI = aWandererI + ((RotL64(aPrevious, 51U) + aOrbiterD) + RotL64(aOrbiterA, 19U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 56U) + RotL64(aOrbiterF, 10U)) + aOrbiterC);
            aWandererE = aWandererE + ((RotL64(aCross, 29U) + aOrbiterJ) + RotL64(aOrbiterF, 23U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterH, 57U)) + aOrbiterA);
            aWandererG = aWandererG + (((RotL64(aCross, 35U) + RotL64(aOrbiterF, 47U)) + aOrbiterB) + RotL64(aCarry, 27U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 48U) + aOrbiterH) + RotL64(aOrbiterK, 60U)) + aPhaseFWandererUpdateSaltE[((aIndex + 20U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 21U) + RotL64(aOrbiterF, 43U)) + aOrbiterE) + RotL64(aNonceWordD, 25U));
            aWandererC = aWandererC ^ ((((RotL64(aPrevious, 53U) + RotL64(aOrbiterD, 37U)) + aOrbiterB) + RotL64(aNonceWordB, 5U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 37U) + RotL64(aOrbiterD, 51U)) + aOrbiterG) + RotL64(aCarry, 21U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterK, 35U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererK, 21U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererJ, 10U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererB, 53U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 51U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererH, 13U);
            aCarry = aCarry + RotL64(aIngress, 6U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordA, 22U) ^ RotL64(aNonceWordC, 5U)) ^ RotL64(aNonceWordB, 53U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10084U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 5568U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 43U) ^ RotL64(aNonceWordF, 22U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 6772U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 6100U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aIngress, 24U)) ^ (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterI = ((aWandererC + RotL64(aIngress, 11U)) + 4634399531433127141U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = ((aWandererH + RotL64(aCross, 53U)) + 16961792729406903200U) + RotL64(aNonceWordE, 37U);
            aOrbiterD = (aWandererA + RotL64(aScatter, 41U)) + 4105280732301137738U;
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 18U)) + RotL64(aCarry, 27U)) + 15692013501147331191U;
            aOrbiterE = ((aWandererI + RotL64(aIngress, 5U)) + 1252216715968780587U) + aPhaseFOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = (aWandererE + RotL64(aScatter, 3U)) + 7958289043012473752U;
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 29U)) + 6611577301818896615U) + RotL64(aNonceWordG, 22U);
            aOrbiterF = (aWandererD + RotL64(aCross, 57U)) + 8506226754305949140U;
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 21U)) + RotL64(aCarry, 51U)) + 3648813120449403353U;
            aOrbiterK = (aWandererK + RotL64(aScatter, 43U)) + 5195245426245535735U;
            aOrbiterC = ((aWandererG + RotL64(aCross, 34U)) + RotL64(aCarry, 37U)) + 542948051600803051U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 11974253551208964789U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 10596463592332655367U) ^ RotL64(aNonceWordF, 35U);
            aOrbiterD = RotL64((aOrbiterD * 10941161258815714641U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 12015129484061440159U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 8254944355710109060U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3233697992479357615U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 2754858806943915419U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 5007802002906662779U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15613733948331639723U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 6262190752136523216U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 10528977986487821428U;
            aOrbiterG = RotL64((aOrbiterG * 1184258264034585525U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 8511097226098211854U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 12091864735686692582U;
            aOrbiterH = RotL64((aOrbiterH * 6128140528141411237U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 4970966265236842566U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 10728884018459718341U;
            aOrbiterI = RotL64((aOrbiterI * 18205183219769602827U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 13760057185629905360U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 6590269178744829056U) ^ RotL64(aNonceWordB, 13U);
            aOrbiterJ = RotL64((aOrbiterJ * 14482684769712170123U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 765826377665103262U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 9364759196106579706U;
            aOrbiterA = RotL64((aOrbiterA * 10315111163659289329U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 4629303338428087146U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 15107221579712215172U;
            aOrbiterF = RotL64((aOrbiterF * 14410837138199304663U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 9407987092859067074U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 13589362515507116096U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4544198075069052713U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 2236921538387014026U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 4634399531433127141U;
            aOrbiterC = RotL64((aOrbiterC * 13132011613143486575U), 43U);
            //
            aIngress = RotL64(aOrbiterF, 41U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 29U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 51U));
            aIngress = aIngress + (RotL64(aOrbiterE, 39U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterJ, 29U)) + aOrbiterE);
            aWandererG = aWandererG + (((RotL64(aIngress, 27U) + aOrbiterG) + RotL64(aOrbiterC, 47U)) + aPhaseFWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 43U) + aOrbiterB) + RotL64(aOrbiterK, 27U));
            aWandererB = aWandererB + ((RotL64(aScatter, 21U) + aOrbiterA) + RotL64(aOrbiterF, 20U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 53U) + aOrbiterG) + RotL64(aOrbiterK, 5U)) + RotL64(aNonceWordC, 57U));
            aWandererE = aWandererE + ((((RotL64(aCross, 46U) + aOrbiterI) + RotL64(aOrbiterH, 13U)) + RotL64(aCarry, 47U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterC, 43U)) + aOrbiterH) + RotL64(aNonceWordH, 25U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterD, 53U)) + aOrbiterC);
            aWandererK = aWandererK ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterK, 24U)) + aOrbiterH);
            aWandererI = aWandererI + (((RotL64(aIngress, 34U) + aOrbiterF) + RotL64(aOrbiterB, 57U)) + RotL64(aCarry, 29U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterK, 11U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererF, 6U) ^ aWandererD);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 51U));
            aCarry = aCarry + (RotL64(aWandererC, 37U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 21U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 42U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererE, 23U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 3U) ^ RotL64(aNonceWordG, 21U)) ^ RotL64(aNonceWordB, 30U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 12132U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14947U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 13U) ^ RotL64(aNonceWordE, 21U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 13036U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 14503U)) & S_BLOCK1], 40U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aIngress, 21U)) ^ (RotL64(aCarry, 54U) + RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterC = (aWandererE + RotL64(aScatter, 60U)) + 7270044678408187242U;
            aOrbiterB = (((aWandererC + RotL64(aIngress, 21U)) + RotL64(aCarry, 57U)) + 10192278965379756766U) + aPhaseFOrbiterAssignSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = (aWandererB + RotL64(aPrevious, 19U)) + 17568666746676060748U;
            aOrbiterK = (aWandererH + RotL64(aCross, 53U)) + 14312927531124963037U;
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 23U)) + 9825825726152087706U) + RotL64(aNonceWordH, 47U);
            aOrbiterJ = (aWandererD + RotL64(aIngress, 11U)) + 9696778570255265896U;
            aOrbiterD = (((aWandererI + RotL64(aScatter, 27U)) + RotL64(aCarry, 39U)) + 17657841352013417228U) + RotL64(aNonceWordD, 53U);
            aOrbiterE = ((aWandererF + RotL64(aCross, 47U)) + RotL64(aCarry, 47U)) + 16207815085909628439U;
            aOrbiterI = (aWandererG + RotL64(aIngress, 4U)) + 1752979206374514227U;
            aOrbiterG = (aWandererA + RotL64(aScatter, 35U)) + 10456310689643905854U;
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 29U)) + 16127830548663742550U) + aPhaseFOrbiterAssignSaltC[((aIndex + 28U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 2940917376003930842U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 7353596864777649953U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7499468723171042005U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 12725092740446150705U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 5791296650856037010U;
            aOrbiterJ = RotL64((aOrbiterJ * 760379251950502133U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 1200130368046206150U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 16689604428598558547U;
            aOrbiterB = RotL64((aOrbiterB * 13815324235939996623U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 14359561591103730856U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 3975025843599045263U) ^ RotL64(aNonceWordE, 49U);
            aOrbiterA = RotL64((aOrbiterA * 5025047888533298617U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 14017901732955607601U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 10431526786489555196U;
            aOrbiterE = RotL64((aOrbiterE * 10181915874476132407U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 7320527073559849223U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 15333411223710709907U;
            aOrbiterG = RotL64((aOrbiterG * 3488684905528068775U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 14302474063321663801U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 2104154521019935187U) ^ RotL64(aNonceWordA, 30U);
            aOrbiterC = RotL64((aOrbiterC * 12944382959742278055U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 5167600586916325228U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 4566823109447208716U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9997799807454267443U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 12475580453805083495U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 15461491763911887974U;
            aOrbiterD = RotL64((aOrbiterD * 13548865386159287481U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 11000532703581114393U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 7815822789941347770U;
            aOrbiterI = RotL64((aOrbiterI * 1476638214324946775U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 2166336159928211562U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 7270044678408187242U;
            aOrbiterH = RotL64((aOrbiterH * 10648564933168714815U), 57U);
            //
            aIngress = RotL64(aOrbiterA, 39U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterJ, 51U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 60U));
            aIngress = aIngress + (RotL64(aOrbiterC, 3U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterF, 43U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterG, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aScatter, 47U) + aOrbiterK) + RotL64(aOrbiterD, 19U)) + RotL64(aCarry, 47U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 21U) + aOrbiterD) + RotL64(aOrbiterI, 21U)) + aPhaseFWandererUpdateSaltA[((aIndex + 8U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 41U) + RotL64(aOrbiterJ, 51U)) + aOrbiterK) + RotL64(aCarry, 5U)) + RotL64(aNonceWordG, 39U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 5U) + aOrbiterJ) + RotL64(aOrbiterG, 11U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 60U) + aOrbiterH) + RotL64(aOrbiterB, 14U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterK, 43U)) + aOrbiterF);
            aWandererF = aWandererF + (((RotL64(aScatter, 11U) + aOrbiterH) + RotL64(aOrbiterF, 35U)) + RotL64(aNonceWordC, 19U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterK, 23U)) + aOrbiterA);
            aWandererG = aWandererG + (((RotL64(aCross, 58U) + aOrbiterG) + RotL64(aOrbiterE, 39U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterI, 60U)) + aOrbiterH);
            aWandererK = aWandererK + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterB, 37U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererG, 38U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererE, 21U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 26U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererI, 51U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 40U) ^ RotL64(aNonceWordG, 3U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 19299U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20128U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 19U) ^ RotL64(aNonceWordF, 27U)) ^ RotL64(aNonceWordC, 57U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16885U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 20426U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 21U) + RotL64(aCarry, 4U)) ^ (RotL64(aIngress, 47U) ^ RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterB = ((aWandererH + RotL64(aScatter, 41U)) + RotL64(aCarry, 21U)) + 6243113109470883144U;
            aOrbiterE = ((aWandererC + RotL64(aIngress, 43U)) + RotL64(aCarry, 3U)) + 3891552123999605832U;
            aOrbiterJ = (aWandererK + RotL64(aCross, 51U)) + 8758797898587019128U;
            aOrbiterH = (aWandererF + RotL64(aPrevious, 39U)) + 1005891374086408851U;
            aOrbiterI = ((aWandererG + RotL64(aIngress, 13U)) + 3713426782180050764U) + RotL64(aNonceWordH, 49U);
            aOrbiterG = ((aWandererI + RotL64(aScatter, 54U)) + 18358143862391573534U) + aPhaseFOrbiterAssignSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = ((aWandererE + RotL64(aCross, 5U)) + RotL64(aCarry, 39U)) + 17504394029693712404U;
            aOrbiterC = (aWandererD + RotL64(aPrevious, 23U)) + 5312729289027417014U;
            aOrbiterD = ((aWandererA + RotL64(aCross, 19U)) + 2560873623431186029U) + RotL64(aNonceWordF, 14U);
            aOrbiterF = (aWandererB + RotL64(aPrevious, 27U)) + 16309322822806704211U;
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 10U)) + 10195513918020652600U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 2552116263258744287U) + RotL64(aNonceWordB, 25U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 7732784879810980089U;
            aOrbiterJ = RotL64((aOrbiterJ * 15041929399477790999U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 16499127570665381507U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 10890036715535519036U;
            aOrbiterI = RotL64((aOrbiterI * 9065115450010475187U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 16288944603478791554U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 14542766121469312846U;
            aOrbiterG = RotL64((aOrbiterG * 8435383464425875209U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 5973595239494084696U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 1820492719977197097U;
            aOrbiterK = RotL64((aOrbiterK * 16164917159141304405U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 10489529555776381736U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 6392552206958240484U;
            aOrbiterC = RotL64((aOrbiterC * 11761477994533503307U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 10163241948999404556U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 16054678853554707148U;
            aOrbiterD = RotL64((aOrbiterD * 10570418210789350091U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 3606021702108590330U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 16920568417324295852U;
            aOrbiterF = RotL64((aOrbiterF * 5222656554577625385U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 13889995689147406315U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 7908387312354285092U;
            aOrbiterA = RotL64((aOrbiterA * 7995682580514280949U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 14161911472715334589U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 12386100977925313406U) ^ RotL64(aNonceWordG, 7U);
            aOrbiterB = RotL64((aOrbiterB * 17136336570895231639U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 14408470657696841139U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 7466281699619513012U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2706710684289882025U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 11125044052260579351U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 6243113109470883144U;
            aOrbiterH = RotL64((aOrbiterH * 17390954549755941181U), 41U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterE, 5U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 19U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 37U));
            aIngress = aIngress + (RotL64(aOrbiterB, 39U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterH, 58U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterK, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aIngress, 11U) + aOrbiterG) + RotL64(aOrbiterA, 13U)) + RotL64(aNonceWordA, 55U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 39U) + aOrbiterH) + RotL64(aOrbiterK, 34U));
            aWandererA = aWandererA + ((((RotL64(aCross, 21U) + RotL64(aOrbiterD, 23U)) + aOrbiterI) + RotL64(aCarry, 5U)) + aPhaseFWandererUpdateSaltE[((aIndex + 12U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterI, 39U)) + aOrbiterF);
            aWandererB = aWandererB + ((RotL64(aScatter, 52U) + RotL64(aOrbiterF, 51U)) + aOrbiterJ);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterC, 11U)) + aOrbiterI);
            aWandererD = aWandererD + ((RotL64(aCross, 41U) + RotL64(aOrbiterK, 57U)) + aOrbiterE);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterB, 29U)) + aOrbiterA);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 37U) + aOrbiterH) + RotL64(aOrbiterE, 43U)) + RotL64(aCarry, 53U)) + RotL64(aNonceWordD, 51U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 29U) + aOrbiterD) + RotL64(aOrbiterJ, 3U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aCross, 60U) + RotL64(aOrbiterC, 18U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 37U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 56U));
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererH);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 41U));
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererI, 21U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 53U) ^ RotL64(aNonceWordA, 43U)) ^ RotL64(aNonceWordF, 30U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 23860U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27020U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 3U) ^ RotL64(aNonceWordC, 35U)) ^ RotL64(aNonceWordD, 13U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24691U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23997U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 51U) + RotL64(aIngress, 27U)) + (RotL64(aPrevious, 39U) ^ RotL64(aCross, 14U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterK = (aWandererJ + RotL64(aScatter, 4U)) + 6381335981879993247U;
            aOrbiterE = (aWandererI + RotL64(aCross, 27U)) + 15595429101600023172U;
            aOrbiterA = (((aWandererC + RotL64(aPrevious, 21U)) + RotL64(aCarry, 53U)) + 5449234297249826461U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterC = (aWandererB + RotL64(aIngress, 53U)) + 11213734849329731168U;
            aOrbiterG = ((aWandererK + RotL64(aCross, 13U)) + RotL64(aCarry, 19U)) + 16438473952464514248U;
            aOrbiterF = (aWandererH + RotL64(aPrevious, 43U)) + 7357872882115186976U;
            aOrbiterI = ((aWandererA + RotL64(aScatter, 41U)) + 394402075160738643U) + RotL64(aNonceWordA, 3U);
            aOrbiterD = ((aWandererF + RotL64(aIngress, 38U)) + RotL64(aCarry, 3U)) + 11112941985410283532U;
            aOrbiterB = ((aWandererD + RotL64(aCross, 11U)) + 14955125011182736212U) + aPhaseFOrbiterAssignSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = (aWandererE + RotL64(aScatter, 51U)) + 14770727009821304070U;
            aOrbiterH = ((aWandererG + RotL64(aIngress, 35U)) + 11286366598129204910U) + RotL64(aNonceWordH, 45U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 7358400908565425780U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 15635109923749114761U;
            aOrbiterA = RotL64((aOrbiterA * 12415152149408700329U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 13826842523738623579U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 1072811298828325231U;
            aOrbiterF = RotL64((aOrbiterF * 9662800288646215083U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 4017334196009350776U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 8812213572751410831U;
            aOrbiterD = RotL64((aOrbiterD * 12744171921566782795U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 6723457786170634403U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 9785583533999417673U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7776915427605471097U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 10265132640322153964U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 8435670887514808087U;
            aOrbiterK = RotL64((aOrbiterK * 2706263045620662131U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 4303823386961718326U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 4214384238167491037U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8490707334221154005U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 8740835037840799136U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 5988815405391206280U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17838555472135715929U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 15539461383052981747U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 3743772525784217714U;
            aOrbiterB = RotL64((aOrbiterB * 6352086797545969187U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 16283379107488103386U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 2677085736169305444U;
            aOrbiterH = RotL64((aOrbiterH * 5034373635279045467U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 16961352880910247821U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 7475807604144212417U) ^ RotL64(aNonceWordE, 15U);
            aOrbiterE = RotL64((aOrbiterE * 5016987646810330727U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 10187131329357526073U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 6381335981879993247U) ^ RotL64(aNonceWordB, 58U);
            aOrbiterG = RotL64((aOrbiterG * 15277168748093112841U), 51U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterH, 48U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 19U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 5U));
            aIngress = aIngress + (RotL64(aOrbiterC, 21U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + RotL64(aOrbiterG, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterH, 19U)) + aOrbiterK) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 60U) + aOrbiterD) + RotL64(aOrbiterG, 21U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterF, 34U)) + aOrbiterK);
            aWandererG = aWandererG + (((RotL64(aCross, 35U) + aOrbiterG) + RotL64(aOrbiterI, 29U)) + RotL64(aCarry, 43U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 21U) + aOrbiterK) + RotL64(aOrbiterG, 57U));
            aWandererB = aWandererB + ((RotL64(aCross, 52U) + RotL64(aOrbiterA, 51U)) + aOrbiterC);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 39U) + aOrbiterG) + RotL64(aOrbiterA, 39U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 13U) + RotL64(aOrbiterD, 12U)) + aOrbiterJ);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterE, 23U)) + aOrbiterI);
            aWandererD = aWandererD + ((((RotL64(aIngress, 11U) + RotL64(aOrbiterA, 53U)) + aOrbiterK) + RotL64(aCarry, 11U)) + RotL64(aNonceWordD, 37U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 41U) + aOrbiterH) + RotL64(aOrbiterB, 3U)) + RotL64(aNonceWordC, 35U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 22U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererJ);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 60U));
            aCarry = aCarry + RotL64(aWandererD, 37U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 13U) ^ RotL64(aNonceWordH, 5U)) ^ RotL64(aNonceWordE, 21U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 28900U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneB[((aIndex + 31100U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 27U) ^ RotL64(aNonceWordF, 19U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27444U)) & S_BLOCK1], 40U) ^ RotL64(aWorkLaneB[((aIndex + 29754U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 6U) + RotL64(aPrevious, 23U)) + (RotL64(aIngress, 37U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterJ = (((aWandererD + RotL64(aPrevious, 47U)) + RotL64(aCarry, 39U)) + 17081642665820489793U) + aPhaseFOrbiterAssignSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = (aWandererH + RotL64(aScatter, 19U)) + 14468854040067229623U;
            aOrbiterB = ((aWandererG + RotL64(aIngress, 11U)) + RotL64(aCarry, 29U)) + 2249450222593057429U;
            aOrbiterC = (aWandererB + RotL64(aCross, 35U)) + 14964389079511378664U;
            aOrbiterA = (aWandererF + RotL64(aIngress, 6U)) + 17003491054252360650U;
            aOrbiterE = ((aWandererI + RotL64(aCross, 3U)) + RotL64(aCarry, 53U)) + 12710882240582032588U;
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 53U)) + 9887078182156755359U) + RotL64(aNonceWordB, 25U);
            aOrbiterD = (aWandererJ + RotL64(aScatter, 57U)) + 7665284531810584704U;
            aOrbiterF = ((aWandererA + RotL64(aIngress, 43U)) + 7304284015511876717U) + RotL64(aNonceWordG, 5U);
            aOrbiterI = (aWandererK + RotL64(aScatter, 30U)) + 5517927023543751734U;
            aOrbiterG = ((aWandererC + RotL64(aCross, 37U)) + 17704756310857362759U) + aPhaseFOrbiterAssignSaltC[((aIndex + 24U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 11347400363019508578U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 11696395232760991243U;
            aOrbiterB = RotL64((aOrbiterB * 9725231749679442003U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 10875780291242873583U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 7808740614343437672U;
            aOrbiterA = RotL64((aOrbiterA * 8889516201913716283U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 3145390996141902032U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 16080636485642732615U;
            aOrbiterE = RotL64((aOrbiterE * 7445756373012217305U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 3929263288176983844U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 18210228766683996806U;
            aOrbiterK = RotL64((aOrbiterK * 13178080076505449091U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 13948962323541421431U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 3037683309790156893U;
            aOrbiterD = RotL64((aOrbiterD * 13406672352222636739U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 17827265198532699474U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 7270895262023504864U;
            aOrbiterF = RotL64((aOrbiterF * 13467417362477308167U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 6431243064980879185U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 6680205390976259885U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10421386694108590789U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 15910655919164357152U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 8046213498216027383U) ^ RotL64(aNonceWordE, 61U);
            aOrbiterG = RotL64((aOrbiterG * 18061867495824063553U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 2521111689480478597U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 13892876610454681741U;
            aOrbiterJ = RotL64((aOrbiterJ * 17776392934374483875U), 21U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterG) + 16009217514890880809U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]) + RotL64(aNonceWordA, 48U);
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 1221573458193626679U;
            aOrbiterH = RotL64((aOrbiterH * 73477765605619369U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 9275704218554025797U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 17081642665820489793U;
            aOrbiterC = RotL64((aOrbiterC * 5613316790159527375U), 13U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterE, 58U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 35U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 21U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 19U));
            aIngress = aIngress + RotL64(aOrbiterH, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aCross, 37U) + RotL64(aOrbiterD, 47U)) + aOrbiterC) + RotL64(aCarry, 51U)) + RotL64(aNonceWordC, 55U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 24U) + aOrbiterD) + RotL64(aOrbiterJ, 43U));
            aWandererD = aWandererD + ((RotL64(aIngress, 21U) + aOrbiterE) + RotL64(aOrbiterF, 54U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterD, 3U)) + aOrbiterF);
            aWandererE = aWandererE + ((RotL64(aCross, 35U) + aOrbiterC) + RotL64(aOrbiterF, 37U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 51U) + aOrbiterH) + RotL64(aOrbiterE, 21U)) + aPhaseFWandererUpdateSaltA[((aIndex + 20U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterD, 5U)) + aOrbiterA) + RotL64(aCarry, 19U)) + aPhaseFWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterI, 19U)) + aOrbiterE) + RotL64(aNonceWordH, 35U));
            aWandererH = aWandererH + ((RotL64(aCross, 60U) + aOrbiterK) + RotL64(aOrbiterJ, 11U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterI, 41U)) + aOrbiterG);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 43U) + RotL64(aOrbiterB, 60U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 51U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 10U));
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererG, 19U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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

void TwistExpander_Karate_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xDCCC870905369BE5ULL + 0xDFBA9CE5B96E6EA6ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xF44ED791D1CA2179ULL + 0xCF0E13E0B616C50FULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x8E39362B9A5146AFULL + 0x8EDCF8D1529DA996ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xE58785C72B6ADD8FULL + 0x91E827F03BACD703ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xA2D8D3336586582DULL + 0xA0FD6506FB0405F1ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xEF7FDA1002AEB1D9ULL + 0x99D8FAB5D9AEDA9EULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xA4AEFDD2F7A5CADFULL + 0xABF71B44B286DA25ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xB8D7174583AF0179ULL + 0xCEF7DBA63E4ED27BULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 27U) ^ RotL64(aNonceWordE, 19U));
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 4038U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneC[((aIndex + 43U)) & S_BLOCK1], 44U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 19U) ^ RotL64(aNonceWordH, 46U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 2371U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 500U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 37U) + RotL64(aPrevious, 57U)) ^ (RotL64(aCross, 22U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterA = (aWandererH + RotL64(aScatter, 37U)) + 9133751643283278896U;
            aOrbiterF = (((aWandererF + RotL64(aIngress, 6U)) + 8971581804375380408U) + aPhaseFOrbiterAssignSaltA[((aIndex + 29U)) & S_SALT1]) + RotL64(aNonceWordD, 19U);
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 13U)) + RotL64(aCarry, 43U)) + 12559650383714566592U;
            aOrbiterB = ((aWandererA + RotL64(aCross, 27U)) + RotL64(aCarry, 11U)) + 15753206088872859163U;
            aOrbiterH = (aWandererJ + RotL64(aScatter, 47U)) + 7640756270450762350U;
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 43U)) + 7340073357551376125U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = (aWandererC + RotL64(aIngress, 11U)) + 5270256573644196046U;
            aOrbiterC = (aWandererI + RotL64(aCross, 21U)) + 3567367996479995928U;
            aOrbiterK = ((aWandererE + RotL64(aIngress, 35U)) + RotL64(aCarry, 29U)) + 11939634537492733738U;
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 58U)) + 7051817732424527120U) + RotL64(aNonceWordF, 7U);
            aOrbiterG = (aWandererD + RotL64(aCross, 53U)) + 1730487669951837941U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 18009252467909454817U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 2361024272031696442U;
            aOrbiterD = RotL64((aOrbiterD * 15215151562500226027U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 15902755877642960397U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 12243517544704116184U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2576071074148141447U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 16846181962302186187U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 636121425116506681U;
            aOrbiterA = RotL64((aOrbiterA * 17075030673338779993U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 6887385655828217318U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 3705834550934775862U;
            aOrbiterB = RotL64((aOrbiterB * 11275428284929594435U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 11165142437077969438U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 6426659930331618269U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17170640810530893705U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 12629082390899315789U) + RotL64(aNonceWordB, 58U);
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 4277510580069574724U;
            aOrbiterK = RotL64((aOrbiterK * 9829125163412708305U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 13814834144170469978U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 3698381854100295826U;
            aOrbiterG = RotL64((aOrbiterG * 5126359230872258015U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 11623170635983579937U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 7247413650388803796U;
            aOrbiterF = RotL64((aOrbiterF * 3403219499465560059U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 3129755194359521145U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 4081016725582134919U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11564414998539605389U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 15878346077922215753U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 2974440187796944059U;
            aOrbiterC = RotL64((aOrbiterC * 783253926537018373U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 3922344163443096356U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 9133751643283278896U) ^ RotL64(aNonceWordA, 35U);
            aOrbiterE = RotL64((aOrbiterE * 16887991698415418429U), 27U);
            //
            aIngress = RotL64(aOrbiterI, 44U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 29U));
            aIngress = aIngress + (RotL64(aOrbiterC, 23U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterE, 27U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterA, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aPrevious, 19U) + aOrbiterH) + RotL64(aOrbiterK, 47U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterK, 21U)) + aOrbiterE) + RotL64(aNonceWordC, 51U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 11U) + RotL64(aOrbiterD, 52U)) + aOrbiterK);
            aWandererK = aWandererK ^ ((RotL64(aCross, 56U) + RotL64(aOrbiterB, 5U)) + aOrbiterE);
            aWandererD = aWandererD + ((RotL64(aScatter, 27U) + RotL64(aOrbiterB, 57U)) + aOrbiterJ);
            aWandererG = aWandererG ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterG, 3U)) + aOrbiterI);
            aWandererF = aWandererF + (((RotL64(aPrevious, 23U) + aOrbiterH) + RotL64(aOrbiterC, 29U)) + RotL64(aCarry, 11U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterG, 39U)) + aOrbiterD);
            aWandererB = aWandererB + (((((RotL64(aScatter, 53U) + aOrbiterF) + RotL64(aOrbiterG, 10U)) + RotL64(aCarry, 39U)) + RotL64(aNonceWordG, 39U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterJ, 23U)) + aOrbiterF) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 44U) + aOrbiterA) + RotL64(aOrbiterE, 13U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 53U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 60U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 37U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 51U));
            aCarry = aCarry + (RotL64(aWandererJ, 41U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererA, 58U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 5U) ^ RotL64(aNonceWordF, 41U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 10781U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 10595U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 29U) ^ RotL64(aNonceWordH, 37U)) ^ RotL64(aNonceWordD, 20U));
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 6309U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((aIndex + 8522U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCross, 57U)) ^ (RotL64(aPrevious, 44U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = ((aWandererE + RotL64(aScatter, 41U)) + RotL64(aCarry, 21U)) + 9630214189402543339U;
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 19U)) + RotL64(aCarry, 35U)) + 4072576573737526819U;
            aOrbiterD = (aWandererK + RotL64(aPrevious, 26U)) + 15994787452709618869U;
            aOrbiterI = ((aWandererB + RotL64(aCross, 37U)) + 6403240137132259482U) + RotL64(aNonceWordG, 11U);
            aOrbiterK = (aWandererG + RotL64(aPrevious, 39U)) + 10229266900170507720U;
            aOrbiterA = (((aWandererA + RotL64(aCross, 11U)) + RotL64(aCarry, 41U)) + 5025294577989748989U) + RotL64(aNonceWordA, 45U);
            aOrbiterG = (aWandererC + RotL64(aScatter, 13U)) + 16696461238217956883U;
            aOrbiterB = (aWandererD + RotL64(aIngress, 60U)) + 9878318855341719119U;
            aOrbiterC = ((aWandererI + RotL64(aScatter, 43U)) + 16086635438116177346U) + aPhaseFOrbiterAssignSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterH = (aWandererH + RotL64(aCross, 21U)) + 12295437783084203730U;
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 51U)) + 7681150419912842402U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 2639104034287637448U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 12298170009332243573U;
            aOrbiterD = RotL64((aOrbiterD * 9397919591171238575U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 3485932317267669626U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 16569551670038752475U;
            aOrbiterJ = RotL64((aOrbiterJ * 8139802826402217631U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 4448490103784103954U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 14510534073046885941U;
            aOrbiterK = RotL64((aOrbiterK * 7777192047386438305U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 4286195398675733451U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 15790355933840266463U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13342257823027075501U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 6362891510370156055U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 15121822034579983174U;
            aOrbiterC = RotL64((aOrbiterC * 7268045994574844937U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 13817341015719915628U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 14113474087906143783U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12838910141533126059U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 9988301252236121106U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 11287477288382171758U;
            aOrbiterI = RotL64((aOrbiterI * 4979297247881426383U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 9491727010910328644U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 7961202721830514030U;
            aOrbiterA = RotL64((aOrbiterA * 16300364540313620767U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 10058066852293995222U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 541563830282750968U;
            aOrbiterB = RotL64((aOrbiterB * 1516823517052019845U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 7791201128863372861U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 8334318157449352359U;
            aOrbiterH = RotL64((aOrbiterH * 2924838607279239375U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 6861081455774799715U) + RotL64(aNonceWordC, 41U);
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 9630214189402543339U) ^ RotL64(aNonceWordB, 24U);
            aOrbiterF = RotL64((aOrbiterF * 10837610668580336781U), 21U);
            //
            aIngress = RotL64(aOrbiterF, 40U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 27U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 29U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 13U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 5U));
            aIngress = aIngress + RotL64(aOrbiterD, 56U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aPrevious, 14U) + RotL64(aOrbiterA, 43U)) + aOrbiterJ) + RotL64(aCarry, 53U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 37U) + aOrbiterD) + RotL64(aOrbiterB, 23U));
            aWandererH = aWandererH + ((((RotL64(aCross, 57U) + aOrbiterG) + RotL64(aOrbiterC, 21U)) + RotL64(aCarry, 21U)) + RotL64(aNonceWordF, 57U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 39U) + aOrbiterI) + RotL64(aOrbiterK, 13U));
            aWandererB = aWandererB + ((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 54U)) + aOrbiterK);
            aWandererK = aWandererK ^ (((RotL64(aCross, 51U) + aOrbiterF) + RotL64(aOrbiterH, 27U)) + RotL64(aNonceWordE, 39U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterD, 11U)) + aOrbiterA);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 54U) + aOrbiterD) + RotL64(aOrbiterC, 57U));
            aWandererF = aWandererF + ((RotL64(aCross, 43U) + aOrbiterK) + RotL64(aOrbiterE, 5U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 21U) + aOrbiterE) + RotL64(aOrbiterH, 41U));
            aWandererI = aWandererI + (((RotL64(aScatter, 19U) + RotL64(aOrbiterC, 34U)) + aOrbiterA) + aPhaseFWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 56U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (RotL64(aWandererI, 11U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + RotL64(aWandererE, 5U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 19U) ^ RotL64(aNonceWordB, 40U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 15909U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneA[((aIndex + 15525U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 29U) ^ RotL64(aNonceWordE, 4U));
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 12811U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 12970U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aIngress, 29U)) + (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 4U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 21U)) + RotL64(aCarry, 27U)) + 13499155707765393469U;
            aOrbiterI = (aWandererB + RotL64(aScatter, 26U)) + 3740324981823726185U;
            aOrbiterE = ((aWandererG + RotL64(aIngress, 23U)) + RotL64(aCarry, 35U)) + 5470765363949735652U;
            aOrbiterJ = ((aWandererK + RotL64(aCross, 53U)) + RotL64(aCarry, 41U)) + 3446436171274452326U;
            aOrbiterD = ((aWandererH + RotL64(aIngress, 13U)) + 1778929412631211933U) + aPhaseFOrbiterAssignSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = (aWandererC + RotL64(aScatter, 37U)) + 14666308799855220954U;
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 11U)) + 4548410236791175055U) + RotL64(aNonceWordA, 9U);
            aOrbiterG = ((aWandererF + RotL64(aCross, 35U)) + 5829739767694190372U) + aPhaseFOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = (aWandererD + RotL64(aScatter, 48U)) + 14319231414903675748U;
            aOrbiterK = ((aWandererA + RotL64(aCross, 41U)) + 1513851750246111405U) + RotL64(aNonceWordF, 51U);
            aOrbiterC = (aWandererI + RotL64(aIngress, 29U)) + 1685620217748986019U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 16284162182006054402U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 6271539598462003309U;
            aOrbiterE = RotL64((aOrbiterE * 13923286694131331137U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 12669312437565969473U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 11894755313393001665U;
            aOrbiterF = RotL64((aOrbiterF * 12556759675372354075U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 6315983824634946566U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 17106616474222892782U) ^ RotL64(aNonceWordC, 52U);
            aOrbiterI = RotL64((aOrbiterI * 167205520766791073U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 13350266700180455548U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 4608846311203767162U;
            aOrbiterD = RotL64((aOrbiterD * 2504857468837437365U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 14195866746143604365U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 7917977448256795054U;
            aOrbiterG = RotL64((aOrbiterG * 5927771378657284557U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 10707336923305131629U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 17122696159336995392U;
            aOrbiterK = RotL64((aOrbiterK * 13953518568670659191U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 5182322763573586116U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 6503754948502556246U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14749002194140663519U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 14907832047832987341U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 6258064448676621346U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4407960312705621487U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 1180234574888070795U) + RotL64(aNonceWordD, 45U);
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 801686887651085881U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 433981853631548041U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 11810494591997709554U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 9343740505955858127U;
            aOrbiterA = RotL64((aOrbiterA * 8733378485648720323U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 12816829575386720695U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 13499155707765393469U;
            aOrbiterC = RotL64((aOrbiterC * 9937924703928730369U), 23U);
            //
            aIngress = RotL64(aOrbiterD, 51U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterJ, 5U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 19U));
            aIngress = aIngress + (RotL64(aOrbiterK, 29U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 38U));
            aIngress = aIngress + RotL64(aOrbiterA, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aIngress, 23U) + RotL64(aOrbiterE, 44U)) + aOrbiterF) + RotL64(aCarry, 11U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterG, 3U)) + aOrbiterH);
            aWandererC = aWandererC + ((((RotL64(aCross, 21U) + RotL64(aOrbiterH, 21U)) + aOrbiterI) + RotL64(aCarry, 47U)) + aPhaseFWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 39U) + RotL64(aOrbiterA, 27U)) + aOrbiterK) + RotL64(aNonceWordH, 57U));
            aWandererB = aWandererB + (((RotL64(aCross, 30U) + aOrbiterC) + RotL64(aOrbiterE, 47U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterB, 53U)) + aOrbiterI);
            aWandererA = aWandererA + ((RotL64(aIngress, 57U) + aOrbiterK) + RotL64(aOrbiterF, 29U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterK, 37U)) + aOrbiterE);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 19U) + aOrbiterH) + RotL64(aOrbiterJ, 19U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterD, 58U)) + aOrbiterE) + RotL64(aNonceWordG, 3U));
            aWandererH = aWandererH + ((RotL64(aCross, 60U) + aOrbiterK) + RotL64(aOrbiterB, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererJ);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 51U));
            aCarry = aCarry + (RotL64(aWandererI, 41U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererB, 38U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererH, 11U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 58U) ^ RotL64(aNonceWordE, 13U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 21490U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 21761U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 40U) ^ RotL64(aNonceWordC, 29U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 20717U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneD[((aIndex + 20836U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aPrevious, 39U)) + (RotL64(aCross, 11U) ^ RotL64(aIngress, 24U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 43U)) + RotL64(aCarry, 39U)) + 10038936806177516123U;
            aOrbiterD = ((aWandererK + RotL64(aCross, 51U)) + 1773168435195292638U) + RotL64(aNonceWordG, 21U);
            aOrbiterJ = (((aWandererI + RotL64(aIngress, 57U)) + RotL64(aCarry, 43U)) + 10655711161526628072U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = (aWandererG + RotL64(aScatter, 47U)) + 14422295664639740437U;
            aOrbiterH = (aWandererE + RotL64(aCross, 34U)) + 4125228715513159576U;
            aOrbiterC = ((aWandererB + RotL64(aIngress, 21U)) + 3670449653158650845U) + RotL64(aNonceWordE, 41U);
            aOrbiterB = (aWandererD + RotL64(aScatter, 39U)) + 17553727567180813057U;
            aOrbiterI = (aWandererF + RotL64(aPrevious, 37U)) + 5111401772713882743U;
            aOrbiterA = ((aWandererH + RotL64(aScatter, 19U)) + RotL64(aCarry, 3U)) + 7688573124662314413U;
            aOrbiterF = ((aWandererC + RotL64(aCross, 54U)) + 9438375825507814395U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = (aWandererA + RotL64(aIngress, 23U)) + 14177477039902118886U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 16329942595859623928U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 3990536794006836672U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 579024714339065373U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 5072881436583180756U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 16789727877867289997U;
            aOrbiterH = RotL64((aOrbiterH * 8766246302636197905U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 17313956922306689438U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 11530878396329822041U;
            aOrbiterC = RotL64((aOrbiterC * 11356860047841383129U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 3612616532321160196U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 4172189825359187763U;
            aOrbiterB = RotL64((aOrbiterB * 12938945495299393177U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 8677279703778052804U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterH) ^ 1912172980909479362U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1]) ^ RotL64(aNonceWordB, 29U);
            aOrbiterI = RotL64((aOrbiterI * 10053289257955474143U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 1460085850227494500U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 12116763868122868147U;
            aOrbiterA = RotL64((aOrbiterA * 6076945628020280957U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 17571840610366424432U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 15581362592611080868U;
            aOrbiterF = RotL64((aOrbiterF * 1129054058044872003U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 14434700039977611666U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 4534294602623329152U;
            aOrbiterG = RotL64((aOrbiterG * 5860911553425182045U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 865998255725903702U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 16407778704555344108U;
            aOrbiterE = RotL64((aOrbiterE * 15571344643129797977U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 1948990288894429805U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 18218556219056835250U;
            aOrbiterD = RotL64((aOrbiterD * 16574160087642377293U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 1309229265173143398U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 10038936806177516123U) ^ RotL64(aNonceWordA, 31U);
            aOrbiterK = RotL64((aOrbiterK * 12954594462760207923U), 53U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterA, 19U);
            aIngress = aIngress + (RotL64(aOrbiterI, 37U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterG, 47U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterF, 41U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 44U));
            aIngress = aIngress + RotL64(aOrbiterC, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aIngress, 22U) + RotL64(aOrbiterH, 39U)) + aOrbiterD);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterA, 47U)) + aOrbiterH);
            aWandererB = aWandererB + ((((RotL64(aCross, 47U) + RotL64(aOrbiterK, 21U)) + aOrbiterA) + RotL64(aCarry, 47U)) + RotL64(aNonceWordF, 19U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 29U) + aOrbiterD) + RotL64(aOrbiterG, 34U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 57U) + aOrbiterK) + RotL64(aOrbiterC, 5U)) + RotL64(aCarry, 19U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 27U) + aOrbiterI) + RotL64(aOrbiterA, 23U));
            aWandererD = aWandererD + (((RotL64(aIngress, 39U) + RotL64(aOrbiterF, 3U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterJ, 37U)) + aOrbiterE);
            aWandererC = aWandererC + (((RotL64(aCross, 19U) + RotL64(aOrbiterB, 27U)) + aOrbiterD) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 6U) + RotL64(aOrbiterE, 51U)) + aOrbiterD);
            aWandererG = aWandererG + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterB, 18U)) + aOrbiterK) + RotL64(aNonceWordD, 58U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 22U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 43U));
            aCarry = aCarry + RotL64(aWandererA, 27U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 47U) ^ RotL64(aNonceWordB, 60U)) ^ RotL64(aNonceWordG, 37U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 26327U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26961U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 34U) ^ RotL64(aNonceWordA, 13U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 24110U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 26590U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 27U) + RotL64(aCarry, 53U)) ^ (RotL64(aCross, 6U) + RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 29U)) + RotL64(aCarry, 21U)) + 8604208734152026945U;
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 51U)) + 1374329953253889829U;
            aOrbiterC = (aWandererB + RotL64(aScatter, 27U)) + 5779278910548228339U;
            aOrbiterD = (((aWandererK + RotL64(aCross, 3U)) + RotL64(aCarry, 11U)) + 17670451230882805140U) + aPhaseFOrbiterAssignSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = (aWandererI + RotL64(aIngress, 23U)) + 8193848740764866860U;
            aOrbiterH = ((aWandererE + RotL64(aCross, 57U)) + 15801168428145650104U) + RotL64(aNonceWordA, 51U);
            aOrbiterA = (aWandererH + RotL64(aPrevious, 54U)) + 2584718176087499066U;
            aOrbiterG = ((aWandererG + RotL64(aScatter, 43U)) + RotL64(aCarry, 5U)) + 14950366247822737997U;
            aOrbiterE = (aWandererF + RotL64(aIngress, 47U)) + 9779293225265670135U;
            aOrbiterI = ((aWandererC + RotL64(aScatter, 11U)) + 8688968319288372383U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = ((aWandererA + RotL64(aCross, 36U)) + 13665723186950342601U) + RotL64(aNonceWordC, 45U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 9395428688359973510U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 2152719218018108418U;
            aOrbiterC = RotL64((aOrbiterC * 15271961483518392671U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 1350324137411377992U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 8729317951386057921U;
            aOrbiterH = RotL64((aOrbiterH * 6008790836417785083U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 6317310451893678411U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 10175620379041384281U;
            aOrbiterG = RotL64((aOrbiterG * 14079679617394330781U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 1203082119358827708U) + RotL64(aNonceWordB, 38U);
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 523869107818193101U;
            aOrbiterI = RotL64((aOrbiterI * 4629501113595689157U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 4028324959540432983U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 15447631947468213912U;
            aOrbiterB = RotL64((aOrbiterB * 6037306615787729185U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 14225888694733041031U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 11925000696281947629U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4337022940520411253U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 15015531024930608745U) + RotL64(aNonceWordD, 9U);
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 16752579225076943550U;
            aOrbiterA = RotL64((aOrbiterA * 15551083683579981439U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 2432733494869267901U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 10103430321388601485U;
            aOrbiterE = RotL64((aOrbiterE * 18372919379972432569U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 15943360147468638325U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 9782703760233558733U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 685056980418243879U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 18345087852012669037U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 8897505040792027675U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14333687539092412967U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 7402581293947129667U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 8604208734152026945U;
            aOrbiterK = RotL64((aOrbiterK * 9965525485538037673U), 19U);
            //
            aIngress = RotL64(aOrbiterH, 10U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterK, 53U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 39U));
            aIngress = aIngress + RotL64(aOrbiterB, 48U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 36U) + RotL64(aOrbiterB, 3U)) + aOrbiterC) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aIngress, 51U) + aOrbiterD) + RotL64(aOrbiterH, 23U)) + RotL64(aCarry, 51U)) + aPhaseFWandererUpdateSaltE[((aIndex + 8U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 53U) + aOrbiterG) + RotL64(aOrbiterD, 39U)) + RotL64(aNonceWordE, 23U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 39U) + aOrbiterA) + RotL64(aOrbiterE, 44U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterB, 51U)) + aOrbiterD) + RotL64(aNonceWordH, 5U));
            aWandererB = aWandererB + ((RotL64(aIngress, 19U) + aOrbiterE) + RotL64(aOrbiterH, 5U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterC, 11U)) + aOrbiterI);
            aWandererD = aWandererD + (((RotL64(aCross, 23U) + aOrbiterI) + RotL64(aOrbiterK, 41U)) + RotL64(aCarry, 19U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterG, 21U)) + aOrbiterK);
            aWandererF = aWandererF + ((RotL64(aCross, 14U) + aOrbiterF) + RotL64(aOrbiterI, 27U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 29U) + aOrbiterG) + RotL64(aOrbiterJ, 54U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 21U));
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 44U));
            aCarry = aCarry + (RotL64(aWandererB, 41U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererH, 57U);
            aCarry = aCarry + RotL64(aIngress, 18U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 26U) ^ RotL64(aNonceWordA, 57U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 30234U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((aIndex + 31629U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 57U) ^ RotL64(aNonceWordE, 5U)) ^ RotL64(aNonceWordG, 47U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32598U)) & S_BLOCK1], 36U) ^ RotL64(aOperationLaneB[((aIndex + 30705U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 43U) ^ RotL64(aCross, 58U)) + (RotL64(aPrevious, 11U) ^ RotL64(aCarry, 29U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = (aWandererE + RotL64(aPrevious, 41U)) + 6243113109470883144U;
            aOrbiterG = (((aWandererA + RotL64(aCross, 13U)) + RotL64(aCarry, 13U)) + 3891552123999605832U) + RotL64(aNonceWordB, 21U);
            aOrbiterD = (aWandererG + RotL64(aIngress, 57U)) + 8758797898587019128U;
            aOrbiterH = ((aWandererI + RotL64(aScatter, 27U)) + 1005891374086408851U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterC = (aWandererK + RotL64(aIngress, 6U)) + 3713426782180050764U;
            aOrbiterI = (aWandererC + RotL64(aPrevious, 53U)) + 18358143862391573534U;
            aOrbiterF = (aWandererF + RotL64(aCross, 35U)) + 17504394029693712404U;
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 23U)) + 5312729289027417014U) + RotL64(aNonceWordE, 44U);
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 39U)) + RotL64(aCarry, 41U)) + 2560873623431186029U;
            aOrbiterB = (aWandererB + RotL64(aCross, 20U)) + 16309322822806704211U;
            aOrbiterA = (((aWandererD + RotL64(aIngress, 37U)) + RotL64(aCarry, 3U)) + 10195513918020652600U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 2552116263258744287U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 7732784879810980089U;
            aOrbiterD = RotL64((aOrbiterD * 15041929399477790999U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 16499127570665381507U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 10890036715535519036U;
            aOrbiterC = RotL64((aOrbiterC * 9065115450010475187U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 16288944603478791554U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 14542766121469312846U;
            aOrbiterI = RotL64((aOrbiterI * 8435383464425875209U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 5973595239494084696U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 1820492719977197097U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16164917159141304405U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 10489529555776381736U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 6392552206958240484U;
            aOrbiterJ = RotL64((aOrbiterJ * 11761477994533503307U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 10163241948999404556U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 16054678853554707148U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10570418210789350091U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 3606021702108590330U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 16920568417324295852U;
            aOrbiterB = RotL64((aOrbiterB * 5222656554577625385U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 13889995689147406315U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 7908387312354285092U;
            aOrbiterA = RotL64((aOrbiterA * 7995682580514280949U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 14161911472715334589U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 12386100977925313406U) ^ RotL64(aNonceWordH, 9U);
            aOrbiterE = RotL64((aOrbiterE * 17136336570895231639U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 14408470657696841139U) + RotL64(aNonceWordC, 35U);
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 7466281699619513012U;
            aOrbiterG = RotL64((aOrbiterG * 2706710684289882025U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 11125044052260579351U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 6243113109470883144U;
            aOrbiterH = RotL64((aOrbiterH * 17390954549755941181U), 37U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterG, 3U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 53U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 5U));
            aIngress = aIngress + (RotL64(aOrbiterD, 23U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterC, 37U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterB, 20U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aPrevious, 29U) + aOrbiterJ) + RotL64(aOrbiterK, 21U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 39U) + aOrbiterJ) + RotL64(aOrbiterC, 41U));
            aWandererE = aWandererE + ((RotL64(aCross, 58U) + RotL64(aOrbiterI, 30U)) + aOrbiterE);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 19U) + aOrbiterH) + RotL64(aOrbiterD, 51U));
            aWandererC = aWandererC + ((((RotL64(aCross, 11U) + aOrbiterE) + RotL64(aOrbiterG, 19U)) + RotL64(aCarry, 27U)) + RotL64(aNonceWordG, 51U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 37U) + aOrbiterG) + RotL64(aOrbiterB, 39U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 52U) + RotL64(aOrbiterC, 27U)) + aOrbiterI) + RotL64(aCarry, 41U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterH, 35U)) + aOrbiterG);
            aWandererG = aWandererG + (((RotL64(aIngress, 35U) + RotL64(aOrbiterJ, 37U)) + aOrbiterF) + RotL64(aNonceWordF, 15U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterJ, 3U)) + aOrbiterD) + aPhaseFWandererUpdateSaltA[((aIndex + 4U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 3U) + aOrbiterF) + RotL64(aOrbiterA, 56U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 10U));
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererK);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererD, 26U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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

void TwistExpander_Karate_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 6724U)) & S_BLOCK1], 37U) ^ RotL64(aKeyRowReadA[((aIndex + 1926U)) & W_KEY1], 54U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 2049U)) & W_KEY1], 3U) ^ RotL64(mSource[((aIndex + 4214U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 6U) + RotL64(aCarry, 39U)) ^ (RotL64(aPrevious, 27U) ^ RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = (((aWandererK + RotL64(aPrevious, 5U)) + RotL64(aCarry, 29U)) + 8101351470141807662U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = (aWandererF + RotL64(aCross, 43U)) + 6965474099521076705U;
            aOrbiterA = (aWandererI + RotL64(aScatter, 52U)) + 6803828268885684784U;
            aOrbiterB = (aWandererC + RotL64(aIngress, 47U)) + 13454235922950972488U;
            aOrbiterJ = ((aWandererH + RotL64(aCross, 13U)) + RotL64(aCarry, 11U)) + 11678091885751244777U;
            aOrbiterF = (aWandererD + RotL64(aIngress, 23U)) + 5307134544628507141U;
            aOrbiterG = ((aWandererE + RotL64(aScatter, 19U)) + 4873703518950429353U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = (aWandererB + RotL64(aPrevious, 28U)) + 8542156221858586039U;
            aOrbiterK = ((aWandererA + RotL64(aScatter, 57U)) + RotL64(aCarry, 53U)) + 3993726182905296513U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 12113047622035464386U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 1944244448665721151U;
            aOrbiterA = RotL64((aOrbiterA * 7010050836758762003U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 12914188029425467576U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 2486762763475327024U;
            aOrbiterF = RotL64((aOrbiterF * 12319769994433811617U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 14580191602982245481U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 12093414832400135066U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12720286833215690663U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 13623906997320021065U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 9977356009806428696U;
            aOrbiterK = RotL64((aOrbiterK * 2005536391712733499U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 3694954095397810851U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 11453812627797091638U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13730420725113907161U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 542311345544726351U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 3024285045990499484U;
            aOrbiterB = RotL64((aOrbiterB * 5153745952148205645U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 15397664082460849530U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 10716856680110815056U;
            aOrbiterG = RotL64((aOrbiterG * 13947203772929252823U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 833342121331428547U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 1111339940097269219U;
            aOrbiterC = RotL64((aOrbiterC * 17991642769781175473U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 9312963978841402871U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 8225496710723213204U;
            aOrbiterJ = RotL64((aOrbiterJ * 894499195498817065U), 35U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterI, 50U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 53U));
            aIngress = aIngress + RotL64(aOrbiterB, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aScatter, 18U) + RotL64(aOrbiterJ, 22U)) + aOrbiterK);
            aWandererC = aWandererC ^ ((RotL64(aCross, 5U) + aOrbiterK) + RotL64(aOrbiterA, 35U));
            aWandererB = aWandererB + ((RotL64(aIngress, 37U) + aOrbiterG) + RotL64(aOrbiterF, 43U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterB, 29U)) + aOrbiterF) + aPhaseCWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aCross, 29U) + RotL64(aOrbiterB, 39U)) + aOrbiterJ);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 43U) + aOrbiterC) + RotL64(aOrbiterI, 47U));
            aWandererE = aWandererE + (((RotL64(aIngress, 47U) + aOrbiterK) + RotL64(aOrbiterD, 18U)) + RotL64(aCarry, 57U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 23U) + aOrbiterD) + RotL64(aOrbiterC, 11U)) + aPhaseCWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 10U) + aOrbiterA) + RotL64(aOrbiterB, 57U)) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererC, 14U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererB, 23U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 13923U)) & S_BLOCK1], 56U) ^ RotL64(mSource[((aIndex + 9745U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 14301U)) & W_KEY1], 41U) ^ RotL64(aKeyRowReadB[((aIndex + 13813U)) & W_KEY1], 4U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 26U) + RotL64(aIngress, 43U)) ^ (RotL64(aCross, 11U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = ((aWandererK + RotL64(aScatter, 43U)) + 13960289014350612206U) + aPhaseCOrbiterAssignSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 22U)) + RotL64(aCarry, 27U)) + 3483331015269589730U;
            aOrbiterC = (aWandererF + RotL64(aIngress, 39U)) + 6873299241002444518U;
            aOrbiterH = (aWandererI + RotL64(aCross, 35U)) + 3562094007125534229U;
            aOrbiterI = (aWandererA + RotL64(aPrevious, 47U)) + 11422367439932782705U;
            aOrbiterJ = (((aWandererE + RotL64(aScatter, 56U)) + RotL64(aCarry, 51U)) + 532453428514259816U) + aPhaseCOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = (aWandererB + RotL64(aIngress, 51U)) + 17810941465810193088U;
            aOrbiterG = ((aWandererD + RotL64(aCross, 11U)) + RotL64(aCarry, 19U)) + 11869759058631106331U;
            aOrbiterB = (aWandererJ + RotL64(aScatter, 29U)) + 8837581071876177566U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 17185378327053837778U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 7578253375676981500U;
            aOrbiterC = RotL64((aOrbiterC * 13371647568758721729U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 17112646434432814442U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 14949096407295697881U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14770977858283051753U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 4259590620758467836U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 6534899413644542303U;
            aOrbiterF = RotL64((aOrbiterF * 7987609419215568661U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 2637407498893694243U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 15819295597921425711U;
            aOrbiterG = RotL64((aOrbiterG * 5202015597375051399U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 6373559542002699718U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 11694562937392022505U;
            aOrbiterB = RotL64((aOrbiterB * 9311557972331218597U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 3308736483775453062U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 12749929710650475901U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 248428400724560945U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 1569528215675579656U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 1044077933631689572U;
            aOrbiterH = RotL64((aOrbiterH * 6443796233912755143U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 8393422728124537471U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 2002732612516530754U;
            aOrbiterJ = RotL64((aOrbiterJ * 13702146823622364279U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 13469191942843147943U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 7633171368709520560U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9713514012478203047U), 51U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterG, 57U);
            aIngress = aIngress + (RotL64(aOrbiterA, 41U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 3U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 23U));
            aIngress = aIngress + RotL64(aOrbiterI, 26U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aPrevious, 37U) + aOrbiterG) + RotL64(aOrbiterA, 3U)) + RotL64(aCarry, 11U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 47U) + aOrbiterG) + RotL64(aOrbiterC, 24U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 58U) + RotL64(aOrbiterH, 35U)) + aOrbiterA) + aPhaseCWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 29U) + aOrbiterF) + RotL64(aOrbiterH, 29U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 5U) + aOrbiterI) + RotL64(aOrbiterE, 19U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterB, 44U)) + aOrbiterJ) + aPhaseCWandererUpdateSaltF[((aIndex + 8U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aScatter, 53U) + aOrbiterJ) + RotL64(aOrbiterE, 53U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 19U) + aOrbiterB) + RotL64(aOrbiterF, 57U));
            aWandererK = aWandererK + (((RotL64(aScatter, 10U) + RotL64(aOrbiterB, 11U)) + aOrbiterH) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 18U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererB, 41U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 16787U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23718U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 18804U)) & W_KEY1], 39U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 17991U)) & W_KEY1], 4U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 6U) ^ RotL64(aPrevious, 27U)) + (RotL64(aIngress, 57U) + RotL64(aCarry, 43U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 29U)) + 11450949896247900941U) + aPhaseCOrbiterAssignSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterD = ((aWandererH + RotL64(aCross, 35U)) + RotL64(aCarry, 29U)) + 3905542253538116335U;
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 3U)) + RotL64(aCarry, 41U)) + 9529740545977785305U;
            aOrbiterK = ((aWandererC + RotL64(aScatter, 10U)) + 1856876631533143492U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = (aWandererD + RotL64(aPrevious, 39U)) + 84253466320181686U;
            aOrbiterE = (aWandererA + RotL64(aCross, 43U)) + 12577480918745432444U;
            aOrbiterF = (aWandererJ + RotL64(aIngress, 21U)) + 5625703170397704029U;
            aOrbiterC = (aWandererG + RotL64(aScatter, 56U)) + 694608607323629282U;
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 47U)) + RotL64(aCarry, 3U)) + 3993981243536262204U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 4119215953484892051U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 8785040118556157146U;
            aOrbiterJ = RotL64((aOrbiterJ * 17113521266125471625U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 16234403619456882890U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 10398727475672860610U;
            aOrbiterI = RotL64((aOrbiterI * 5086871400049644715U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 18327987141759096769U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 2645964788056875452U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8778681366114628045U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 2859452497983106129U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 7196557924940881076U;
            aOrbiterD = RotL64((aOrbiterD * 14415389907490256711U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 930127943984174668U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 15673596916054795749U;
            aOrbiterB = RotL64((aOrbiterB * 7505660488733199479U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 16673140529110941163U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 2258448294877833760U;
            aOrbiterE = RotL64((aOrbiterE * 1821550319748977445U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 6870209259643931219U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 12749790107942194104U;
            aOrbiterF = RotL64((aOrbiterF * 4871407285968611725U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 17131374134617173866U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 6426448390733751612U;
            aOrbiterC = RotL64((aOrbiterC * 12490559588384058417U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 15592826434339731146U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 14182944418026376183U;
            aOrbiterG = RotL64((aOrbiterG * 7218860482893476233U), 39U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterD, 54U);
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 37U));
            aIngress = aIngress + RotL64(aOrbiterE, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 30U) + aOrbiterC) + RotL64(aOrbiterG, 12U));
            aWandererF = aWandererF + (((RotL64(aCross, 19U) + aOrbiterI) + RotL64(aOrbiterK, 57U)) + RotL64(aCarry, 13U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterJ, 23U)) + aOrbiterG);
            aWandererH = aWandererH + (((RotL64(aScatter, 41U) + aOrbiterC) + RotL64(aOrbiterB, 27U)) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 57U) + aOrbiterF) + RotL64(aOrbiterC, 47U));
            aWandererK = aWandererK + ((((RotL64(aPrevious, 3U) + aOrbiterK) + RotL64(aOrbiterG, 6U)) + RotL64(aCarry, 53U)) + aPhaseCWandererUpdateSaltD[((aIndex + 15U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterB, 19U)) + aOrbiterF);
            aWandererI = aWandererI + ((RotL64(aIngress, 34U) + aOrbiterD) + RotL64(aOrbiterK, 51U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterB, 39U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererI, 12U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 29U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 23U));
            aCarry = aCarry + RotL64(aWandererA, 53U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 24815U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneB[((aIndex + 29122U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26839U)) & S_BLOCK1], 29U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 25244U)) & S_BLOCK1], 50U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 39U) + RotL64(aCross, 11U)) ^ (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 54U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = (aWandererB + RotL64(aCross, 30U)) + 3621877681473089725U;
            aOrbiterD = (aWandererA + RotL64(aIngress, 43U)) + 4451752751536414717U;
            aOrbiterF = ((aWandererK + RotL64(aScatter, 51U)) + RotL64(aCarry, 51U)) + 11371625415377772117U;
            aOrbiterA = (aWandererI + RotL64(aPrevious, 13U)) + 6046792758881150619U;
            aOrbiterI = (((aWandererH + RotL64(aCross, 19U)) + RotL64(aCarry, 13U)) + 8213166120394461682U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = (aWandererG + RotL64(aIngress, 6U)) + 4343156661140422645U;
            aOrbiterE = (((aWandererF + RotL64(aPrevious, 23U)) + RotL64(aCarry, 29U)) + 11105271483234947905U) + aPhaseCOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = (aWandererD + RotL64(aScatter, 47U)) + 348904609985341372U;
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 35U)) + 12924652822526858767U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 7461211697358520287U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 16551553555297890558U;
            aOrbiterF = RotL64((aOrbiterF * 16432952324635746293U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 11908056404140782995U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 9147367258259948715U;
            aOrbiterI = RotL64((aOrbiterI * 10777628928376261667U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 8876461054692728610U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 10546855952702525404U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10071104785895309677U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 4748636139110443794U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 783046909529525098U;
            aOrbiterB = RotL64((aOrbiterB * 8969157702460927215U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 16683965945838696665U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 12385412690177109575U;
            aOrbiterA = RotL64((aOrbiterA * 10795062772707143187U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 8210546822184469023U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 13146493623236979963U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13199947810161148155U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 13857628148804187115U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 7241297989337473475U;
            aOrbiterK = RotL64((aOrbiterK * 16223448508809614229U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 773904571213804946U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 7660676598236419707U;
            aOrbiterH = RotL64((aOrbiterH * 14467390638468925567U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 16822672435156055469U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 6514707119190640433U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7097496727567460535U), 19U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterK, 57U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 60U));
            aIngress = aIngress + (RotL64(aOrbiterD, 37U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 53U));
            aIngress = aIngress + RotL64(aOrbiterI, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 11U) + aOrbiterD) + RotL64(aOrbiterE, 3U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 46U) + RotL64(aOrbiterB, 40U)) + aOrbiterK) + RotL64(aCarry, 41U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 39U) + aOrbiterF) + RotL64(aOrbiterB, 27U));
            aWandererI = aWandererI + (((RotL64(aIngress, 23U) + aOrbiterA) + RotL64(aOrbiterJ, 35U)) + aPhaseCWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterH, 53U)) + aOrbiterA);
            aWandererA = aWandererA + ((RotL64(aScatter, 19U) + RotL64(aOrbiterA, 19U)) + aOrbiterB);
            aWandererB = aWandererB ^ (((RotL64(aCross, 29U) + aOrbiterI) + RotL64(aOrbiterA, 44U)) + aPhaseCWandererUpdateSaltE[((aIndex + 24U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 6U) + RotL64(aOrbiterK, 23U)) + aOrbiterI) + RotL64(aCarry, 21U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 35U) + aOrbiterE) + RotL64(aOrbiterK, 11U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 10U));
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererB, 57U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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

void TwistExpander_Karate_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 3463U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneC[((aIndex + 6267U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 41U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((aIndex + 7752U)) & S_BLOCK1], 36U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 27U) ^ RotL64(aIngress, 39U)) ^ (RotL64(aCross, 14U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = ((aWandererB + RotL64(aIngress, 23U)) + 12809562813316740345U) + aPhaseDOrbiterAssignSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterG = ((aWandererF + RotL64(aScatter, 35U)) + RotL64(aCarry, 21U)) + 17084212535326321199U;
            aOrbiterJ = ((aWandererA + RotL64(aCross, 12U)) + RotL64(aCarry, 57U)) + 16074921689983846769U;
            aOrbiterI = (((aWandererE + RotL64(aPrevious, 53U)) + RotL64(aCarry, 41U)) + 14027986153007120145U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterK = (aWandererC + RotL64(aScatter, 43U)) + 7633455951809250227U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 340989348513370174U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 5307820377645020116U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8402492604131262157U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 5605285015771527274U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 5293500434746182790U;
            aOrbiterC = RotL64((aOrbiterC * 17674669610895537063U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 7263156475892261811U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 10672879570907433005U;
            aOrbiterI = RotL64((aOrbiterI * 2506338667179450741U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 16659226780900986107U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 9774892622769850665U;
            aOrbiterG = RotL64((aOrbiterG * 7487477727543183211U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 10728057184108279042U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 5032485856947407217U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16651577903809154285U), 47U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterC, 47U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 58U));
            aIngress = aIngress + RotL64(aOrbiterI, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aScatter, 22U) + aOrbiterI) + RotL64(aOrbiterG, 11U)) + aPhaseDWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 57U) + aOrbiterC) + RotL64(aOrbiterI, 35U)) + RotL64(aCarry, 11U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterJ, 23U)) + aOrbiterC) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 43U) + RotL64(aOrbiterC, 60U)) + aOrbiterK) + RotL64(aCarry, 43U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterK, 43U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + RotL64(aWandererF, 21U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 10342U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 10564U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 12905U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((aIndex + 15738U)) & S_BLOCK1], 36U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 39U) ^ RotL64(aCross, 5U)) ^ (RotL64(aCarry, 56U) + RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = ((aWandererH + RotL64(aScatter, 5U)) + RotL64(aCarry, 11U)) + 7790166497945719700U;
            aOrbiterA = ((aWandererG + RotL64(aCross, 29U)) + 7136208896846119188U) + aPhaseDOrbiterAssignSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = ((aWandererB + RotL64(aIngress, 39U)) + RotL64(aCarry, 29U)) + 12123156943355100886U;
            aOrbiterH = (((aWandererE + RotL64(aPrevious, 47U)) + RotL64(aCarry, 51U)) + 5095546037880875199U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = (aWandererF + RotL64(aCross, 14U)) + 17642705393916765992U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 9918479837334416990U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 4890009823843176466U;
            aOrbiterK = RotL64((aOrbiterK * 16898633181256061239U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 17652590786213674124U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 870002527644696135U;
            aOrbiterB = RotL64((aOrbiterB * 915408393979165539U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 12545429703552643682U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 5310272867406182581U;
            aOrbiterG = RotL64((aOrbiterG * 10420003334833925011U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 3264719049050179440U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 1967241238180278937U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13004319774269457957U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 773883832927040736U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 12766817190261232485U;
            aOrbiterH = RotL64((aOrbiterH * 7448864556802318431U), 43U);
            //
            aIngress = RotL64(aOrbiterG, 29U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterB, 39U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterA, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aIngress, 60U) + aOrbiterB) + RotL64(aOrbiterK, 19U)) + aPhaseDWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 21U) + aOrbiterH) + RotL64(aOrbiterG, 56U)) + RotL64(aCarry, 11U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterH, 3U)) + aOrbiterK);
            aWandererG = aWandererG + ((((RotL64(aScatter, 47U) + aOrbiterA) + RotL64(aOrbiterH, 43U)) + RotL64(aCarry, 35U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterG, 35U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 13U));
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererG, 3U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 19233U)) & S_BLOCK1], 36U) ^ RotL64(aOperationLaneA[((aIndex + 20066U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17924U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneC[((aIndex + 19792U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCross, 4U)) + (RotL64(aPrevious, 39U) + RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = (((aWandererG + RotL64(aCross, 39U)) + RotL64(aCarry, 21U)) + 2672739400294801233U) + aPhaseDOrbiterAssignSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterB = ((aWandererK + RotL64(aIngress, 51U)) + RotL64(aCarry, 3U)) + 8475624545015101850U;
            aOrbiterA = ((aWandererA + RotL64(aScatter, 60U)) + 1252755112289831257U) + aPhaseDOrbiterAssignSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterC = (aWandererC + RotL64(aPrevious, 29U)) + 7938039507649183387U;
            aOrbiterI = ((aWandererI + RotL64(aScatter, 21U)) + RotL64(aCarry, 47U)) + 8167413146948861022U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 17712313989694374353U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 7637042279892596975U;
            aOrbiterA = RotL64((aOrbiterA * 13056020836704050293U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 15770412950033467341U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 3951812021898608685U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6623127125223204737U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 8656983621098246507U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 17943342344730687317U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16495519451034883813U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 3087677463651608668U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 16493240011924342788U;
            aOrbiterC = RotL64((aOrbiterC * 16898479041530771871U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 7750923317452683057U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 2185924841611106546U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 708072658250726381U), 3U);
            //
            aIngress = RotL64(aOrbiterC, 6U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterA, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aPrevious, 53U) + RotL64(aOrbiterC, 19U)) + aOrbiterI) + RotL64(aCarry, 39U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 19U) + aOrbiterB) + RotL64(aOrbiterA, 57U));
            aWandererA = aWandererA + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterB, 29U)) + aOrbiterG) + RotL64(aCarry, 23U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 39U) + aOrbiterI) + RotL64(aOrbiterA, 41U));
            aWandererK = aWandererK + ((RotL64(aCross, 28U) + RotL64(aOrbiterG, 10U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + RotL64(aWandererI, 58U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 31329U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 25912U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 28919U)) & S_BLOCK1], 36U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 25764U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aPrevious, 5U)) ^ (RotL64(aIngress, 27U) + RotL64(aCarry, 56U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = (((aWandererJ + RotL64(aCross, 22U)) + RotL64(aCarry, 51U)) + 7632760812370906911U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterB = ((aWandererH + RotL64(aScatter, 13U)) + RotL64(aCarry, 35U)) + 6007174525479723089U;
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 57U)) + 3362829642521821048U) + aPhaseDOrbiterAssignSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterF = ((aWandererA + RotL64(aIngress, 41U)) + RotL64(aCarry, 21U)) + 18009548556107978286U;
            aOrbiterK = (aWandererC + RotL64(aPrevious, 3U)) + 17880909432272697327U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 15961567935420752568U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 10136559064656837921U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14473810261421912849U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 17622019364405410277U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 6927494824421416306U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2686290883767829973U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 7125170407794874847U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 12342273503071032250U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 867417849555857179U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 14997696377476124836U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 14874498694181230698U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4026127545746010937U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 2549397729130885686U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 4217995818662767955U;
            aOrbiterK = RotL64((aOrbiterK * 5525525344485251063U), 5U);
            //
            aIngress = RotL64(aOrbiterJ, 47U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 37U));
            aIngress = aIngress + RotL64(aOrbiterK, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aPrevious, 23U) + aOrbiterK) + RotL64(aOrbiterD, 3U)) + RotL64(aCarry, 41U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 37U) + RotL64(aOrbiterJ, 11U)) + aOrbiterB) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aCross, 60U) + RotL64(aOrbiterD, 46U)) + aOrbiterF);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterF, 19U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 5U) + aOrbiterF) + RotL64(aOrbiterK, 27U)) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 21U) ^ aWandererK);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 29U));
            aCarry = aCarry + RotL64(aWandererA, 13U);
            aCarry = aCarry + RotL64(aIngress, 44U);
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

void TwistExpander_Karate_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 2454U)) & S_BLOCK1], 26U) ^ RotL64(aOperationLaneC[((aIndex + 154U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 5988U)) & S_BLOCK1], 46U) ^ RotL64(aOperationLaneA[((aIndex + 7781U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aPrevious, 14U)) + (RotL64(aCarry, 53U) ^ RotL64(aIngress, 29U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = (aWandererE + RotL64(aCross, 27U)) + 16189787374324972735U;
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 5U)) + RotL64(aCarry, 11U)) + 17563763730956242224U;
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 43U)) + RotL64(aCarry, 41U)) + 10572803498593789385U;
            aOrbiterD = ((aWandererH + RotL64(aIngress, 35U)) + RotL64(aCarry, 57U)) + 7713105232072974166U;
            aOrbiterF = (aWandererA + RotL64(aPrevious, 21U)) + 10760839534772718139U;
            aOrbiterA = ((aWandererK + RotL64(aCross, 11U)) + 13397069448391230253U) + aPhaseEOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = ((aWandererI + RotL64(aScatter, 52U)) + 4569255679998375682U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 9888769350817876949U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 11351796060878856300U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13356749147334008399U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 18153775071965707204U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 1282846411145853435U;
            aOrbiterF = RotL64((aOrbiterF * 12294455920906257823U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 16457743979262460660U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 173493260775251032U;
            aOrbiterA = RotL64((aOrbiterA * 4935807229040883505U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 3927345926316409630U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 5158769729850853623U;
            aOrbiterC = RotL64((aOrbiterC * 2446452358663812945U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 12331351600010165154U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 3940794200348684050U;
            aOrbiterE = RotL64((aOrbiterE * 13248997263062075043U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 11248514843822945425U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 1391497323278226522U;
            aOrbiterD = RotL64((aOrbiterD * 8376841806072565005U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 13265623528678787307U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 2802033745265647317U;
            aOrbiterJ = RotL64((aOrbiterJ * 3437626962562016147U), 5U);
            //
            aIngress = RotL64(aOrbiterF, 12U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 37U));
            aIngress = aIngress + (RotL64(aOrbiterD, 53U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterJ, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 21U) + aOrbiterA) + RotL64(aOrbiterJ, 57U));
            aWandererA = aWandererA + ((RotL64(aScatter, 5U) + aOrbiterF) + RotL64(aOrbiterD, 23U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterJ, 35U)) + aOrbiterF);
            aWandererK = aWandererK + (((RotL64(aCross, 51U) + RotL64(aOrbiterC, 29U)) + aOrbiterE) + RotL64(aCarry, 29U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterJ, 11U)) + aOrbiterC);
            aWandererH = aWandererH + ((((RotL64(aScatter, 14U) + aOrbiterD) + RotL64(aOrbiterC, 50U)) + RotL64(aCarry, 3U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterH, 3U)) + aOrbiterD) + aPhaseEWandererUpdateSaltD[((aIndex + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 60U) ^ aWandererH);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 21U));
            aCarry = aCarry + (RotL64(aWandererJ, 41U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererI, 35U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9709U)) & S_BLOCK1], 10U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 10505U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 12167U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 8365U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 37U) ^ RotL64(aCarry, 24U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = (aWandererE + RotL64(aPrevious, 20U)) + 10404808878585437255U;
            aOrbiterG = (((aWandererF + RotL64(aIngress, 37U)) + RotL64(aCarry, 23U)) + 10587858736301591439U) + aPhaseEOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = (aWandererG + RotL64(aScatter, 29U)) + 1430530909801644435U;
            aOrbiterK = (aWandererJ + RotL64(aCross, 53U)) + 9090938022430118902U;
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 3U)) + RotL64(aCarry, 35U)) + 12936604311751121235U;
            aOrbiterF = (((aWandererK + RotL64(aScatter, 43U)) + RotL64(aCarry, 3U)) + 1000583006020232032U) + aPhaseEOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = (aWandererB + RotL64(aIngress, 13U)) + 12352532088997042232U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 16723410947058502564U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 16614089235313154270U;
            aOrbiterE = RotL64((aOrbiterE * 11530998303573027827U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 4245553025593349277U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 3353146318549477494U;
            aOrbiterC = RotL64((aOrbiterC * 14246377408238318091U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 5935727336135635196U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 10312187090293319667U;
            aOrbiterK = RotL64((aOrbiterK * 1395964500396711899U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 12192843181244744484U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 2542570124502586365U;
            aOrbiterG = RotL64((aOrbiterG * 17222847847573534963U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 3315472769469002444U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 17512858811783071174U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9070400454074283765U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 16633218007427888082U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 2502077714838858460U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 970762420815997725U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 14792910273226469214U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 15739513291150783151U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11896279674116906915U), 5U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterG, 41U);
            aIngress = aIngress + (RotL64(aOrbiterA, 47U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterC, 13U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterE, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterK, 41U)) + aOrbiterE) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aIngress, 5U) + RotL64(aOrbiterG, 47U)) + aOrbiterC);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterF, 27U)) + aOrbiterH);
            aWandererE = aWandererE + (((RotL64(aCross, 41U) + aOrbiterF) + RotL64(aOrbiterE, 18U)) + RotL64(aCarry, 3U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterF, 3U)) + aOrbiterC);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 23U) + RotL64(aOrbiterF, 53U)) + aOrbiterA) + RotL64(aCarry, 47U)) + aPhaseEWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 56U) + aOrbiterK) + RotL64(aOrbiterC, 11U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 60U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererG, 19U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 19396U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19605U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 18047U)) & S_BLOCK1], 48U) ^ RotL64(aOperationLaneC[((aIndex + 23240U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 3U) + RotL64(aCarry, 53U)) ^ (RotL64(aPrevious, 34U) ^ RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 5U)) + 9751314027302668907U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = ((aWandererF + RotL64(aScatter, 47U)) + RotL64(aCarry, 5U)) + 12175450995523107056U;
            aOrbiterJ = (aWandererH + RotL64(aIngress, 41U)) + 17519694958730119552U;
            aOrbiterD = ((aWandererC + RotL64(aCross, 13U)) + 9093525527925682263U) + aPhaseEOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = ((aWandererK + RotL64(aIngress, 35U)) + RotL64(aCarry, 57U)) + 3713831321786810138U;
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 29U)) + RotL64(aCarry, 39U)) + 10108355209191835040U;
            aOrbiterF = (aWandererB + RotL64(aCross, 54U)) + 12956307447311314768U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 1904298513945877359U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 4658049993308574460U;
            aOrbiterJ = RotL64((aOrbiterJ * 10482422152074338611U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 9826333658248851902U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 12058666914724365134U;
            aOrbiterI = RotL64((aOrbiterI * 964233873188373939U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 2516574707110528099U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 13335308331049750235U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5880227828760598587U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 8230749255538495304U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 16536559486797811486U;
            aOrbiterD = RotL64((aOrbiterD * 7097036838156464969U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 12387639130570188998U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 8459259798142872020U;
            aOrbiterE = RotL64((aOrbiterE * 8001346480955847013U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 16083784052002800300U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 1957284290736468379U;
            aOrbiterB = RotL64((aOrbiterB * 5046501301740813065U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 7349538179311335863U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 16395170077006105258U;
            aOrbiterF = RotL64((aOrbiterF * 4230485452156662763U), 35U);
            //
            aIngress = RotL64(aOrbiterB, 57U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 51U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 4U));
            aIngress = aIngress + RotL64(aOrbiterJ, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aIngress, 41U) + aOrbiterB) + RotL64(aOrbiterD, 57U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterB, 51U)) + aOrbiterF) + aPhaseEWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 11U) + aOrbiterJ) + RotL64(aOrbiterD, 20U)) + RotL64(aCarry, 41U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterE, 3U)) + aOrbiterA);
            aWandererE = aWandererE + (((RotL64(aScatter, 27U) + aOrbiterI) + RotL64(aOrbiterD, 29U)) + aPhaseEWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterA, 43U)) + aOrbiterI);
            aWandererB = aWandererB + (((RotL64(aPrevious, 60U) + aOrbiterI) + RotL64(aOrbiterJ, 35U)) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererB);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 51U));
            aCarry = aCarry + (RotL64(aWandererJ, 34U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererH, 43U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 27056U)) & S_BLOCK1], 18U) ^ RotL64(aWorkLaneB[((aIndex + 26990U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26275U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 27846U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 24U) ^ RotL64(aPrevious, 3U)) ^ (RotL64(aCarry, 39U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = (aWandererF + RotL64(aCross, 58U)) + 785861751704720606U;
            aOrbiterK = ((aWandererA + RotL64(aScatter, 5U)) + RotL64(aCarry, 29U)) + 15968088718435606299U;
            aOrbiterJ = (aWandererD + RotL64(aIngress, 47U)) + 1393976526590347151U;
            aOrbiterD = (aWandererC + RotL64(aPrevious, 13U)) + 17240750947292745884U;
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 35U)) + 4921576136163183137U) + aPhaseEOrbiterAssignSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = (((aWandererB + RotL64(aPrevious, 23U)) + RotL64(aCarry, 51U)) + 3334047873553153032U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = ((aWandererG + RotL64(aIngress, 41U)) + RotL64(aCarry, 13U)) + 15086509978458408698U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 892391205397581998U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 2965686403183767521U;
            aOrbiterJ = RotL64((aOrbiterJ * 709160942482770225U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 14632215393655706170U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 15740589515342377322U;
            aOrbiterG = RotL64((aOrbiterG * 15677716942904794913U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 11131164813943086445U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 6988080581278900960U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6412189142344044255U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 16021254613117657178U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 6183615599897921154U;
            aOrbiterA = RotL64((aOrbiterA * 9976411093264211033U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 12533992547026652747U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 3104325358982904219U;
            aOrbiterB = RotL64((aOrbiterB * 14977348108778147265U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 3878525937957474644U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 2120435259884368445U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15964718652193073177U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 14928658302694194856U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 9121310461310309348U;
            aOrbiterI = RotL64((aOrbiterI * 17304439784647477491U), 21U);
            //
            aIngress = RotL64(aOrbiterK, 11U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + (RotL64(aOrbiterI, 56U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterA, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 57U) + aOrbiterG) + RotL64(aOrbiterI, 42U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 35U) + aOrbiterG) + RotL64(aOrbiterA, 13U)) + RotL64(aCarry, 5U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 19U) + aOrbiterG) + RotL64(aOrbiterD, 23U));
            aWandererG = aWandererG + (((RotL64(aScatter, 26U) + RotL64(aOrbiterK, 53U)) + aOrbiterB) + RotL64(aCarry, 53U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterJ, 29U)) + aOrbiterK);
            aWandererF = aWandererF + ((RotL64(aScatter, 43U) + aOrbiterJ) + RotL64(aOrbiterA, 5U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 3U) + aOrbiterK) + RotL64(aOrbiterD, 35U)) + aPhaseEWandererUpdateSaltD[((aIndex + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 30U));
            aCarry = aCarry + (RotL64(aWandererC, 41U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererD, 57U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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

void TwistExpander_Karate_Arx::Twist_D(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 2060U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneC[((aIndex + 7762U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 7395U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneA[((aIndex + 5403U)) & S_BLOCK1], 10U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aPrevious, 21U)) ^ (RotL64(aCarry, 40U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = (aWandererF + RotL64(aIngress, 53U)) + 15383045568644941552U;
            aOrbiterK = ((aWandererI + RotL64(aCross, 13U)) + RotL64(aCarry, 13U)) + 17452811657750910067U;
            aOrbiterJ = (((aWandererE + RotL64(aScatter, 36U)) + RotL64(aCarry, 29U)) + 15660117718455155603U) + aPhaseFOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = (((aWandererD + RotL64(aPrevious, 21U)) + RotL64(aCarry, 43U)) + 10396441207743665753U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = (aWandererC + RotL64(aCross, 3U)) + 3708971058200841442U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 7000673057768598750U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 9886354469011131596U;
            aOrbiterJ = RotL64((aOrbiterJ * 296615166652808759U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 16018065329058043467U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 5024756166109352320U;
            aOrbiterF = RotL64((aOrbiterF * 11660932185479046483U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 6587818720728886652U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 3652672354944162319U;
            aOrbiterI = RotL64((aOrbiterI * 10807121230791716109U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 6307315649915348048U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 16405347331742979258U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7183142442906743699U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 5427299664054601957U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 4983381733483185898U;
            aOrbiterB = RotL64((aOrbiterB * 14646556236306407673U), 21U);
            //
            aIngress = RotL64(aOrbiterK, 13U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + RotL64(aOrbiterJ, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aPrevious, 22U) + RotL64(aOrbiterI, 35U)) + aOrbiterK);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterF, 27U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aCross, 13U) + aOrbiterK) + RotL64(aOrbiterB, 10U)) + RotL64(aCarry, 21U)) + aPhaseFWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 51U) + aOrbiterI) + RotL64(aOrbiterF, 57U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterJ, 43U)) + aOrbiterB) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererI, 60U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 13999U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 10856U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 12844U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 13807U)) & S_BLOCK1], 40U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 21U) ^ RotL64(aCross, 5U)) + (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 40U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = ((aWandererK + RotL64(aCross, 28U)) + RotL64(aCarry, 51U)) + 6342299552323486695U;
            aOrbiterE = ((aWandererI + RotL64(aIngress, 3U)) + RotL64(aCarry, 35U)) + 12692748514781367538U;
            aOrbiterH = (aWandererC + RotL64(aScatter, 51U)) + 8202639945493229155U;
            aOrbiterG = (((aWandererF + RotL64(aPrevious, 43U)) + RotL64(aCarry, 21U)) + 4439975701793231639U) + aPhaseFOrbiterAssignSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterF = ((aWandererH + RotL64(aScatter, 19U)) + 16774235182859553759U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 8764155413335405667U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 7167848811974967685U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1052856924757654735U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 16768278912125334220U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 9090838954826296201U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5459329624017272077U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 7644075729758006298U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 17326182797908071215U;
            aOrbiterI = RotL64((aOrbiterI * 2408330168749256075U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 16158809721888137555U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 8029938783858263694U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12628072435324195483U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 8716553521415553404U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 7012599977009208840U;
            aOrbiterG = RotL64((aOrbiterG * 8775355876188948851U), 57U);
            //
            aIngress = RotL64(aOrbiterH, 21U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + RotL64(aOrbiterE, 34U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aScatter, 37U) + aOrbiterI) + RotL64(aOrbiterF, 51U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterE, 3U)) + aOrbiterI);
            aWandererI = aWandererI + (((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 34U)) + aOrbiterH) + RotL64(aCarry, 5U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterG, 11U)) + aOrbiterH) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aScatter, 18U) + aOrbiterG) + RotL64(aOrbiterE, 43U)) + RotL64(aCarry, 19U)) + aPhaseFWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 4U));
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 19U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 17491U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneA[((aIndex + 20493U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 21265U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 17602U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aIngress, 27U)) + (RotL64(aCross, 11U) ^ RotL64(aPrevious, 40U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = (((aWandererG + RotL64(aCross, 11U)) + RotL64(aCarry, 57U)) + 18255347001097480328U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = (aWandererA + RotL64(aIngress, 56U)) + 13679246790311505735U;
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 43U)) + RotL64(aCarry, 13U)) + 10565839529765027116U;
            aOrbiterI = (((aWandererD + RotL64(aScatter, 29U)) + RotL64(aCarry, 39U)) + 14327172566224769901U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = (aWandererC + RotL64(aPrevious, 3U)) + 16239024612038195174U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 13800012174212131890U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 13900288860157577583U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13177682776510523095U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 4144386119777112740U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 3154558262670631372U;
            aOrbiterD = RotL64((aOrbiterD * 13236911910092437063U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 7456728543137614001U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 11709519851158935384U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7016689518570071587U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 15607438907832240304U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 9276575329661725624U;
            aOrbiterI = RotL64((aOrbiterI * 8879744070762412745U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 6459435969129449226U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 6442382118416542275U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2921027306686588233U), 19U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterK, 39U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 51U));
            aIngress = aIngress + RotL64(aOrbiterA, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterA, 11U)) + aOrbiterD);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 20U) + RotL64(aOrbiterI, 21U)) + aOrbiterJ) + RotL64(aCarry, 47U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterK, 50U)) + aOrbiterA) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 35U) + aOrbiterI) + RotL64(aOrbiterA, 29U)) + RotL64(aCarry, 21U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 51U) + aOrbiterJ) + RotL64(aOrbiterA, 41U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 19U));
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererD, 58U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 29028U)) & S_BLOCK1], 10U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28229U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26511U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((aIndex + 29186U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 27U) ^ RotL64(aIngress, 5U)) + (RotL64(aCarry, 54U) ^ RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = ((aWandererK + RotL64(aIngress, 13U)) + RotL64(aCarry, 11U)) + 17225673071833726819U;
            aOrbiterA = (((aWandererG + RotL64(aCross, 3U)) + RotL64(aCarry, 43U)) + 10301458382103627331U) + aPhaseFOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = ((aWandererC + RotL64(aScatter, 21U)) + RotL64(aCarry, 23U)) + 3960233050857362414U;
            aOrbiterK = (aWandererF + RotL64(aPrevious, 56U)) + 17768665685046605837U;
            aOrbiterE = ((aWandererI + RotL64(aCross, 37U)) + 14471018461213959767U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 10730597892721340453U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 14863394003122760542U;
            aOrbiterH = RotL64((aOrbiterH * 17731557030589257169U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 9948587274816688296U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 3573569431435100993U;
            aOrbiterC = RotL64((aOrbiterC * 2303922230056523077U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 8153670675740450590U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 16438856577722561424U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4689247488336908827U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 15765587867581925041U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 1082039522061775213U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17023740047246402641U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 4202521649260798876U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 15877659681260461141U;
            aOrbiterE = RotL64((aOrbiterE * 11369910758551088173U), 35U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterC, 21U);
            aIngress = aIngress + (RotL64(aOrbiterK, 47U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterA, 4U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterE, 21U)) + aOrbiterC) + aPhaseFWandererUpdateSaltF[((aIndex + 20U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 21U) + RotL64(aOrbiterK, 5U)) + aOrbiterC) + RotL64(aCarry, 21U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 4U) + aOrbiterE) + RotL64(aOrbiterK, 13U));
            aWandererF = aWandererF + ((((RotL64(aScatter, 13U) + RotL64(aOrbiterA, 29U)) + aOrbiterH) + RotL64(aCarry, 43U)) + aPhaseFWandererUpdateSaltE[((aIndex + 4U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterA, 48U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + (RotL64(aWandererI, 24U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererG, 57U);
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

void TwistExpander_Karate_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 297U)) & S_BLOCK1], 10U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 6094U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 2200U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneD[((aIndex + 5553U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 21U) ^ RotL64(aCarry, 4U)) + (RotL64(aCross, 37U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = (((aWandererK + RotL64(aScatter, 5U)) + RotL64(aCarry, 53U)) + 12311607308490066301U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = (aWandererF + RotL64(aIngress, 60U)) + 13100864684740679846U;
            aOrbiterF = ((aWandererC + RotL64(aCross, 19U)) + 13697304189274329704U) + aPhaseGOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 43U)) + RotL64(aCarry, 41U)) + 9047976902871216732U;
            aOrbiterA = ((aWandererE + RotL64(aCross, 51U)) + RotL64(aCarry, 3U)) + 2147897579538537888U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 2072444829390996142U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 2129307836981020908U;
            aOrbiterF = RotL64((aOrbiterF * 8065769537670939667U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 10663145333751112064U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 15019844390503785459U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7442321463110790449U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 5460865577557928142U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 15806522559993224197U;
            aOrbiterH = RotL64((aOrbiterH * 8722932687972240099U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 6361113778657833389U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 8306013884615042570U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8234258702656728667U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 4038420580499706912U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 11908091484457158973U;
            aOrbiterA = RotL64((aOrbiterA * 3964111175645156719U), 5U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterH, 34U);
            aIngress = aIngress + (RotL64(aOrbiterI, 47U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterF, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 51U) + aOrbiterI) + RotL64(aOrbiterH, 5U)) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aCross, 43U) + RotL64(aOrbiterA, 13U)) + aOrbiterJ) + RotL64(aCarry, 43U)) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 14U) + aOrbiterF) + RotL64(aOrbiterA, 27U));
            aWandererK = aWandererK + (((RotL64(aScatter, 23U) + aOrbiterJ) + RotL64(aOrbiterF, 50U)) + RotL64(aCarry, 5U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 35U) + aOrbiterA) + RotL64(aOrbiterI, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 58U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererC, 43U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 15906U)) & S_BLOCK1], 50U) ^ RotL64(aWorkLaneC[((aIndex + 10041U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 9038U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((aIndex + 14189U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 52U) + RotL64(aCross, 5U)) + (RotL64(aCarry, 35U) ^ RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = (((aWandererJ + RotL64(aScatter, 51U)) + RotL64(aCarry, 43U)) + 3973833383430652211U) + aPhaseGOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = (((aWandererH + RotL64(aIngress, 29U)) + RotL64(aCarry, 5U)) + 5760227042747169187U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = (aWandererG + RotL64(aCross, 21U)) + 4923009065139227286U;
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 5U)) + RotL64(aCarry, 57U)) + 1477807307009107590U;
            aOrbiterB = (aWandererK + RotL64(aIngress, 40U)) + 5707194514329007301U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 5340439728375269724U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 17080457898946572387U;
            aOrbiterJ = RotL64((aOrbiterJ * 17719588880215414933U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 281559150259472813U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 16160633048230910560U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16883442583309073785U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 9003989610509592121U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 10579322462808454333U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 100832431598087235U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 15059383289528723069U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 10417647757852880956U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1457919230286043137U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 14484665027393813330U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 12344463053485837974U;
            aOrbiterG = RotL64((aOrbiterG * 5762654194001525041U), 37U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterG, 58U);
            aIngress = aIngress + (RotL64(aOrbiterB, 27U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterJ, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aPrevious, 3U) + aOrbiterK) + RotL64(aOrbiterC, 4U)) + RotL64(aCarry, 21U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterB, 13U)) + aOrbiterJ) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 13U) + RotL64(aOrbiterG, 51U)) + aOrbiterK) + RotL64(aCarry, 47U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 47U) + aOrbiterG) + RotL64(aOrbiterC, 37U));
            aWandererG = aWandererG + (((RotL64(aIngress, 56U) + RotL64(aOrbiterG, 21U)) + aOrbiterJ) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 19U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 30U));
            aCarry = aCarry + RotL64(aWandererJ, 11U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 20324U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneD[((aIndex + 16469U)) & S_BLOCK1], 30U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 19880U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneB[((aIndex + 21916U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 51U) ^ RotL64(aIngress, 19U)) ^ (RotL64(aCross, 34U) + RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = (aWandererJ + RotL64(aCross, 35U)) + 3339283916456813609U;
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 23U)) + 11339086426180649584U) + aPhaseGOrbiterAssignSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = ((aWandererH + RotL64(aIngress, 43U)) + RotL64(aCarry, 53U)) + 16819191669329316585U;
            aOrbiterC = (((aWandererE + RotL64(aScatter, 3U)) + RotL64(aCarry, 29U)) + 8361916937762630725U) + aPhaseGOrbiterAssignSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 12U)) + RotL64(aCarry, 11U)) + 18031328374429899857U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 18261756894092897276U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 4250319792907645666U;
            aOrbiterD = RotL64((aOrbiterD * 7053489184750217963U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 1492411503643460886U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 17369549067879344180U;
            aOrbiterA = RotL64((aOrbiterA * 2947354306696216579U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 7301713524358676722U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 2985193736033012535U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7473297294949338265U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 14086975808140927408U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 10390516547834639800U;
            aOrbiterC = RotL64((aOrbiterC * 11441293212275890819U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 18205555540941493267U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 16967799565443938873U;
            aOrbiterF = RotL64((aOrbiterF * 3009081009044782443U), 21U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterF, 24U);
            aIngress = aIngress + (RotL64(aOrbiterD, 53U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterA, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aCross, 47U) + RotL64(aOrbiterD, 27U)) + aOrbiterA) + RotL64(aCarry, 43U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 35U) + aOrbiterD) + RotL64(aOrbiterF, 35U));
            aWandererD = aWandererD + ((((RotL64(aScatter, 26U) + aOrbiterG) + RotL64(aOrbiterC, 53U)) + RotL64(aCarry, 13U)) + aPhaseGWandererUpdateSaltB[((aIndex + 18U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 5U) + aOrbiterG) + RotL64(aOrbiterA, 18U));
            aWandererH = aWandererH + (((RotL64(aIngress, 57U) + aOrbiterC) + RotL64(aOrbiterD, 5U)) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererH, 20U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 30250U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneA[((aIndex + 28456U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30945U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 26474U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 11U)) + (RotL64(aIngress, 26U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = ((aWandererB + RotL64(aScatter, 39U)) + RotL64(aCarry, 37U)) + 5568146815535263910U;
            aOrbiterE = ((aWandererG + RotL64(aIngress, 3U)) + RotL64(aCarry, 51U)) + 7736084960873834666U;
            aOrbiterF = (aWandererH + RotL64(aCross, 30U)) + 1336413621817562093U;
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 19U)) + 5218462026934984692U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterI = (((aWandererK + RotL64(aCross, 51U)) + RotL64(aCarry, 23U)) + 7048890985969555935U) + aPhaseGOrbiterAssignSaltE[((aIndex + 25U)) & S_SALT1];
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 13415955213864702118U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 5657023257021528548U;
            aOrbiterF = RotL64((aOrbiterF * 5200798937081797819U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 14338310943137497116U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 12305161641833950473U;
            aOrbiterB = RotL64((aOrbiterB * 11949964304435964395U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 14514226578370459131U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 12692904083266024340U;
            aOrbiterJ = RotL64((aOrbiterJ * 14800805065279908839U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 11012959130001327964U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 7106471380403489078U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 515626559384817223U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 3718101961355280891U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 13364192077222322664U;
            aOrbiterI = RotL64((aOrbiterI * 1411328915372590283U), 29U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterB, 46U);
            aIngress = aIngress + (RotL64(aOrbiterF, 35U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterJ, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aIngress, 57U) + RotL64(aOrbiterF, 54U)) + aOrbiterE) + RotL64(aCarry, 5U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 37U) + aOrbiterJ) + RotL64(aOrbiterF, 27U)) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 4U) + aOrbiterB) + RotL64(aOrbiterF, 5U)) + RotL64(aCarry, 39U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterJ, 13U)) + aOrbiterI);
            aWandererH = aWandererH + (((RotL64(aScatter, 29U) + aOrbiterE) + RotL64(aOrbiterB, 43U)) + aPhaseGWandererUpdateSaltE[((aIndex + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + (RotL64(aWandererK, 37U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererH, 19U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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

void TwistExpander_Karate_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 3165U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 6443U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4709U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 5288U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCross, 4U)) ^ (RotL64(aCarry, 39U) ^ RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = ((aWandererC + RotL64(aIngress, 27U)) + RotL64(aCarry, 57U)) + 8604208734152026945U;
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 3U)) + RotL64(aCarry, 19U)) + 1374329953253889829U;
            aOrbiterC = ((aWandererK + RotL64(aScatter, 11U)) + 5779278910548228339U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = (((aWandererA + RotL64(aCross, 40U)) + RotL64(aCarry, 5U)) + 17670451230882805140U) + aPhaseHOrbiterAssignSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = (aWandererI + RotL64(aPrevious, 57U)) + 8193848740764866860U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 15801168428145650104U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 2584718176087499066U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5687189872016780831U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 14950366247822737997U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 9779293225265670135U;
            aOrbiterF = RotL64((aOrbiterF * 11625969538497982117U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 8688968319288372383U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 13665723186950342601U;
            aOrbiterI = RotL64((aOrbiterI * 292035540396910837U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 9395428688359973510U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 2152719218018108418U;
            aOrbiterA = RotL64((aOrbiterA * 15271961483518392671U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 1350324137411377992U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 8729317951386057921U;
            aOrbiterB = RotL64((aOrbiterB * 6008790836417785083U), 39U);
            //
            aIngress = RotL64(aOrbiterF, 41U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 30U));
            aIngress = aIngress + RotL64(aOrbiterC, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 13U)) + aOrbiterA) + RotL64(aCarry, 35U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 14U) + RotL64(aOrbiterF, 51U)) + aOrbiterB);
            aWandererI = aWandererI + ((((RotL64(aScatter, 39U) + aOrbiterC) + RotL64(aOrbiterF, 36U)) + RotL64(aCarry, 19U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 51U) + aOrbiterB) + RotL64(aOrbiterA, 21U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aScatter, 23U) + RotL64(aOrbiterB, 5U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 60U));
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 8343U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneC[((aIndex + 14155U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 15447U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 9946U)) & S_BLOCK1], 10U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCross, 24U)) + (RotL64(aIngress, 5U) + RotL64(aCarry, 43U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = (aWandererK + RotL64(aCross, 57U)) + 15920462086654025436U;
            aOrbiterG = ((aWandererF + RotL64(aScatter, 35U)) + RotL64(aCarry, 51U)) + 487844076858004017U;
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 19U)) + 14502883786442630566U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterE = ((aWandererI + RotL64(aIngress, 3U)) + RotL64(aCarry, 3U)) + 3787107318658233674U;
            aOrbiterI = (((aWandererD + RotL64(aPrevious, 48U)) + RotL64(aCarry, 19U)) + 12548777544693755491U) + aPhaseHOrbiterAssignSaltE[((aIndex + 10U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 4907309444075181683U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 18342396700266492072U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14842961036061482089U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 13503051997624242670U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 17845742460521374571U;
            aOrbiterI = RotL64((aOrbiterI * 1366356786138085155U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 8640887211877858169U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 5273913123709097537U;
            aOrbiterD = RotL64((aOrbiterD * 1661149444148461791U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 17756844173695563883U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 6713055830729302951U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2832836748513174311U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 5106468334224035972U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 10228769728713526172U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9760310686414358435U), 43U);
            //
            aIngress = RotL64(aOrbiterD, 57U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 30U));
            aIngress = aIngress + RotL64(aOrbiterE, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterG, 21U)) + aOrbiterE);
            aWandererC = aWandererC + ((((RotL64(aScatter, 57U) + aOrbiterD) + RotL64(aOrbiterE, 5U)) + RotL64(aCarry, 27U)) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 27U) + aOrbiterD) + RotL64(aOrbiterI, 57U));
            aWandererK = aWandererK + ((((RotL64(aPrevious, 19U) + aOrbiterF) + RotL64(aOrbiterE, 41U)) + RotL64(aCarry, 11U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 44U) + aOrbiterD) + RotL64(aOrbiterG, 30U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + (RotL64(aWandererF, 36U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererD, 11U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 22363U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 22402U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22185U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneB[((aIndex + 17257U)) & S_BLOCK1], 24U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 34U) + RotL64(aPrevious, 3U)) ^ (RotL64(aCarry, 47U) ^ RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = ((aWandererC + RotL64(aScatter, 3U)) + RotL64(aCarry, 35U)) + 14008824488073394623U;
            aOrbiterD = (((aWandererA + RotL64(aPrevious, 36U)) + RotL64(aCarry, 51U)) + 13317978415866411468U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = ((aWandererB + RotL64(aCross, 27U)) + RotL64(aCarry, 21U)) + 13209180141897453900U;
            aOrbiterI = (aWandererJ + RotL64(aIngress, 19U)) + 11870521586865233578U;
            aOrbiterH = ((aWandererH + RotL64(aScatter, 11U)) + 8052156380448047385U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 12158131176743680605U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 14674467487607719347U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 18372548574199176503U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 18055496790566231147U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 3838105585041578784U;
            aOrbiterD = RotL64((aOrbiterD * 1075709247574580091U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 2839568255183054418U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 11933612922864258179U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7571964469321160347U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 6289849094151630580U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 2640344350528492271U;
            aOrbiterI = RotL64((aOrbiterI * 16197726750829369365U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 16306175266267657791U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 3339898380394883600U;
            aOrbiterH = RotL64((aOrbiterH * 7105436590182982373U), 27U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterI, 57U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 26U));
            aIngress = aIngress + RotL64(aOrbiterH, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 51U) + aOrbiterK) + RotL64(aOrbiterH, 48U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 60U) + aOrbiterI) + RotL64(aOrbiterH, 19U)) + RotL64(aCarry, 21U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterD, 57U)) + aOrbiterF) + aPhaseHWandererUpdateSaltC[((aIndex + 8U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 39U) + RotL64(aOrbiterF, 3U)) + aOrbiterI) + RotL64(aCarry, 37U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterK, 37U)) + aOrbiterI) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 11U));
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererJ, 29U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 32358U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25073U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25661U)) & S_BLOCK1], 50U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 25276U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 52U) ^ RotL64(aCarry, 3U)) + (RotL64(aPrevious, 39U) ^ RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = (aWandererI + RotL64(aIngress, 19U)) + 5295352595333316211U;
            aOrbiterC = ((aWandererH + RotL64(aScatter, 43U)) + 2341795367042042605U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 29U)) + RotL64(aCarry, 3U)) + 10122175780504033663U;
            aOrbiterI = ((aWandererB + RotL64(aCross, 54U)) + RotL64(aCarry, 43U)) + 10084612804696198554U;
            aOrbiterE = (((aWandererG + RotL64(aIngress, 3U)) + RotL64(aCarry, 21U)) + 16470424309851045971U) + aPhaseHOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 656016130975227994U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 15313268829659834317U;
            aOrbiterD = RotL64((aOrbiterD * 3553315008401417123U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 3795220914993923394U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 14044442220988813825U;
            aOrbiterB = RotL64((aOrbiterB * 3270650852546606835U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 3804224626734584802U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 7980006306010255693U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13958505239726088561U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 13746830564584711549U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 11852212099729274845U;
            aOrbiterC = RotL64((aOrbiterC * 2164880979318247855U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 9083223471018084847U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 13706723820703853346U;
            aOrbiterE = RotL64((aOrbiterE * 11361854103656219887U), 13U);
            //
            aIngress = RotL64(aOrbiterB, 43U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterE, 53U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterC, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aIngress, 23U) + RotL64(aOrbiterD, 13U)) + aOrbiterC) + RotL64(aCarry, 11U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 3U) + aOrbiterB) + RotL64(aOrbiterI, 5U));
            aWandererG = aWandererG + ((((RotL64(aCross, 13U) + aOrbiterI) + RotL64(aOrbiterE, 57U)) + RotL64(aCarry, 47U)) + aPhaseHWandererUpdateSaltE[((aIndex + 28U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterB, 36U)) + aOrbiterC);
            aWandererH = aWandererH + (((RotL64(aIngress, 54U) + aOrbiterD) + RotL64(aOrbiterI, 47U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererH);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + RotL64(aWandererG, 3U);
            aCarry = aCarry + RotL64(aIngress, 58U);
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
