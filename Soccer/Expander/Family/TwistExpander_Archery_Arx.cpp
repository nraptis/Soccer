#include "TwistExpander_Archery_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_Archery_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xFF2CB556559AA959ULL + 0xE9839D4E4D0E8473ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xD9B00DDA01AE340BULL + 0x8776F531ED979E0CULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xADC818C6759E16E5ULL + 0xC3611FFDB5FDB24CULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xB2C29917C1F6AAADULL + 0xC9425A9EBA0CF544ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x843EB719A5631AE9ULL + 0xB4C15FDA7436F53FULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xC17F9592D74F1BB7ULL + 0xC1912C1EF8D8F2C3ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xF0711E1D75475F4FULL + 0xD935897C15E9C45CULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xA8A1A397FFD5EBC9ULL + 0xBEA51E7E9E663369ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 21U) ^ RotL64(aNonceWordH, 30U)) ^ RotL64(aNonceWordF, 47U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 3582U)) & S_BLOCK1], 3U) ^ RotL64(mSnow[((aIndex + 2168U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 26U) ^ RotL64(aNonceWordD, 35U));
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 2609U)) & S_BLOCK1], 53U) ^ RotL64(mSnow[((S_BLOCK1 - aIndex + 2253U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCross, 36U)) + (RotL64(aIngress, 11U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (aWandererI + RotL64(aCross, 24U)) + 2617613537256538553U;
            aOrbiterE = (((aWandererB + RotL64(aScatter, 51U)) + RotL64(aCarry, 29U)) + 16642868916835132715U) + aOrbiterAssignSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterK = (aWandererA + RotL64(aPrevious, 3U)) + 10860291124337073254U;
            aOrbiterJ = (aWandererG + RotL64(aIngress, 5U)) + 6432511273906902472U;
            aOrbiterI = (aWandererK + RotL64(aPrevious, 53U)) + 7505375005848241910U;
            aOrbiterD = (((aWandererC + RotL64(aScatter, 27U)) + 11086616004678821329U) + aOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1]) + RotL64(aNonceWordA, 51U);
            aOrbiterC = (aWandererF + RotL64(aCross, 35U)) + 3298830587569881951U;
            aOrbiterB = (aWandererD + RotL64(aIngress, 43U)) + 9775143140064220979U;
            aOrbiterG = ((aWandererH + RotL64(aScatter, 22U)) + 4147601326580823120U) + RotL64(aNonceWordG, 34U);
            aOrbiterH = ((aWandererE + RotL64(aIngress, 37U)) + RotL64(aCarry, 57U)) + 12245920269898100415U;
            aOrbiterF = ((aWandererJ + RotL64(aCross, 13U)) + RotL64(aCarry, 21U)) + 8391940489176734499U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 17876893379544668477U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 18301882058180370541U;
            aOrbiterK = RotL64((aOrbiterK * 16680384667098921309U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 6869225862715140102U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 15404118372589259800U) ^ aOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5766851935950389915U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 17757381020518233814U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 17677969146092374455U;
            aOrbiterA = RotL64((aOrbiterA * 3469432916562405063U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 15783378556632870114U) + aOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 5792858258663697864U;
            aOrbiterJ = RotL64((aOrbiterJ * 12008981883482080427U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 11737803388202260296U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 16001927091970715330U;
            aOrbiterC = RotL64((aOrbiterC * 3062030309852922061U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 1749586939123286632U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 6169421068855905938U;
            aOrbiterG = RotL64((aOrbiterG * 12374789910763348695U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 10073586820719728062U) + aOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 17744171227198661555U) ^ RotL64(aNonceWordH, 41U);
            aOrbiterF = RotL64((aOrbiterF * 10658375268803957647U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 1149819647337612792U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 7725598665625892006U;
            aOrbiterE = RotL64((aOrbiterE * 15097586655234391559U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 13930096050550704122U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 3632241034947389647U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8442222389196610427U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 17933893495867517142U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 7888594392078082482U;
            aOrbiterB = RotL64((aOrbiterB * 9809847720610861237U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 10805303827043372168U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 2617613537256538553U) ^ RotL64(aNonceWordB, 7U);
            aOrbiterH = RotL64((aOrbiterH * 3940471942234248791U), 3U);
            //
            aIngress = RotL64(aOrbiterK, 46U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 27U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 41U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 53U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + RotL64(aOrbiterF, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterA, 4U)) + aOrbiterK);
            aWandererE = aWandererE + ((((RotL64(aIngress, 39U) + RotL64(aOrbiterH, 51U)) + aOrbiterG) + RotL64(aCarry, 23U)) + aWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterB, 19U)) + aOrbiterF);
            aWandererG = aWandererG + ((RotL64(aPrevious, 46U) + RotL64(aOrbiterC, 29U)) + aOrbiterA);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterD, 11U)) + aOrbiterJ);
            aWandererI = aWandererI + ((RotL64(aIngress, 21U) + RotL64(aOrbiterE, 21U)) + aOrbiterC);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 5U) + aOrbiterJ) + RotL64(aOrbiterC, 37U));
            aWandererH = aWandererH + (((RotL64(aCross, 41U) + aOrbiterK) + RotL64(aOrbiterB, 23U)) + RotL64(aCarry, 37U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterJ, 60U)) + aOrbiterG) + RotL64(aNonceWordE, 15U));
            aWandererA = aWandererA + ((((RotL64(aCross, 58U) + aOrbiterF) + RotL64(aOrbiterI, 43U)) + RotL64(aNonceWordC, 27U)) + aWandererUpdateSaltD[((aIndex + 10U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 43U) + aOrbiterK) + RotL64(aOrbiterF, 53U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + (RotL64(aWandererJ, 58U) ^ aWandererE);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (RotL64(aWandererF, 53U) ^ aWandererC);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 21U));
            aCarry = aCarry + RotL64(aWandererA, 50U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 5U) ^ RotL64(aNonceWordB, 19U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 7783U)) & S_BLOCK1], 43U) ^ RotL64(mSnow[((S_BLOCK1 - aIndex + 6075U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 38U) ^ RotL64(aNonceWordC, 11U)) ^ RotL64(aNonceWordA, 19U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 7783U)) & S_BLOCK1], 47U) ^ RotL64(mSource[((aIndex + 8119U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 35U) ^ RotL64(aIngress, 21U)) ^ (RotL64(aPrevious, 51U) + RotL64(aCross, 6U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (aWandererF + RotL64(aIngress, 35U)) + 9774364261626083532U;
            aOrbiterB = (aWandererD + RotL64(aScatter, 20U)) + 18059001521926116420U;
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 37U)) + 10615626210406381148U) + aOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = ((aWandererG + RotL64(aCross, 47U)) + 10536484278007898620U) + RotL64(aNonceWordE, 5U);
            aOrbiterE = (aWandererC + RotL64(aScatter, 27U)) + 13320663045139972700U;
            aOrbiterC = ((aWandererH + RotL64(aCross, 13U)) + RotL64(aCarry, 43U)) + 17127001787268166583U;
            aOrbiterA = ((aWandererI + RotL64(aIngress, 53U)) + RotL64(aCarry, 21U)) + 16742574590844166551U;
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 41U)) + RotL64(aCarry, 27U)) + 8347719720758228053U;
            aOrbiterI = ((aWandererE + RotL64(aIngress, 43U)) + 13502468705946051986U) + aOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 22U)) + 3512687886188904904U) + RotL64(aNonceWordF, 53U);
            aOrbiterD = (aWandererB + RotL64(aScatter, 11U)) + 495660316165795934U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 5092722552034477356U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 15641128019608284015U;
            aOrbiterG = RotL64((aOrbiterG * 3621036395703527059U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 15421873776811085458U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 17978775513204574125U;
            aOrbiterB = RotL64((aOrbiterB * 18359600395119440183U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 16617179197537669849U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 1931805387534012528U;
            aOrbiterE = RotL64((aOrbiterE * 3400139345857733775U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 9544923119559308431U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 12930999400470173353U;
            aOrbiterA = RotL64((aOrbiterA * 16791006919271490005U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 13673733276226249890U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 2032263473309124738U;
            aOrbiterI = RotL64((aOrbiterI * 3088728329261360607U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 14868502349358414206U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 10116495537187552321U;
            aOrbiterK = RotL64((aOrbiterK * 1380512121796709469U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 5341113995358179244U) + RotL64(aNonceWordG, 41U);
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 8415417980279705731U;
            aOrbiterH = RotL64((aOrbiterH * 8521501372683793821U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 2462819265072352463U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 7657062767608441931U;
            aOrbiterC = RotL64((aOrbiterC * 15554638801273540163U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 8153420530633265789U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 10990681417675210534U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1928509513380702895U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 17035995983178569271U) + RotL64(aNonceWordD, 25U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 2806563871848226777U;
            aOrbiterJ = RotL64((aOrbiterJ * 4137935663733587867U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 6570698907081812011U) + aOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 9774364261626083532U;
            aOrbiterD = RotL64((aOrbiterD * 1766375419340392741U), 51U);
            //
            aIngress = RotL64(aOrbiterD, 23U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 58U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 37U));
            aIngress = aIngress + (RotL64(aOrbiterC, 47U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterF, 13U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterH, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aScatter, 21U) + aOrbiterD) + RotL64(aOrbiterE, 51U));
            aWandererH = aWandererH + ((((RotL64(aPrevious, 51U) + aOrbiterI) + RotL64(aOrbiterB, 11U)) + RotL64(aCarry, 21U)) + RotL64(aNonceWordA, 22U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterI, 23U)) + aOrbiterK) + aWandererUpdateSaltF[((aIndex + 22U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 47U) + aOrbiterK) + RotL64(aOrbiterB, 30U)) + RotL64(aCarry, 35U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 5U) + aOrbiterJ) + RotL64(aOrbiterI, 41U)) + aWandererUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aCross, 24U) + RotL64(aOrbiterK, 19U)) + aOrbiterE);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterF, 35U)) + aOrbiterK);
            aWandererF = aWandererF + (((RotL64(aIngress, 35U) + RotL64(aOrbiterE, 57U)) + aOrbiterA) + RotL64(aNonceWordH, 15U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 13U) + aOrbiterJ) + RotL64(aOrbiterH, 13U));
            aWandererC = aWandererC + ((RotL64(aScatter, 57U) + RotL64(aOrbiterC, 3U)) + aOrbiterB);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 42U) + RotL64(aOrbiterA, 46U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 28U));
            aCarry = aCarry + (RotL64(aWandererA, 13U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 37U));
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererG);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + RotL64(aWandererE, 39U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 29U) ^ RotL64(aNonceWordE, 41U)) ^ RotL64(aNonceWordA, 3U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 13835U)) & S_BLOCK1], 57U) ^ RotL64(mSnow[((aIndex + 14462U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 27U) ^ RotL64(aNonceWordF, 41U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15786U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((aIndex + 14096U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 41U) ^ RotL64(aPrevious, 53U)) + (RotL64(aCross, 27U) ^ RotL64(aIngress, 14U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererI + RotL64(aIngress, 35U)) + 13924571355038625040U;
            aOrbiterK = (aWandererH + RotL64(aPrevious, 39U)) + 16328300979357156658U;
            aOrbiterF = (aWandererE + RotL64(aScatter, 37U)) + 3947771961206012461U;
            aOrbiterC = ((aWandererG + RotL64(aCross, 47U)) + RotL64(aCarry, 13U)) + 15428284250569311285U;
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 3U)) + RotL64(aCarry, 21U)) + 5777369485254032486U;
            aOrbiterH = ((aWandererD + RotL64(aScatter, 14U)) + 16813320300717644673U) + aOrbiterAssignSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterA = ((aWandererB + RotL64(aCross, 29U)) + 16689933050200758251U) + RotL64(aNonceWordG, 36U);
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 43U)) + RotL64(aCarry, 5U)) + 1856422419049390708U;
            aOrbiterI = (aWandererJ + RotL64(aScatter, 19U)) + 18214498743831925517U;
            aOrbiterD = (((aWandererC + RotL64(aCross, 41U)) + 18278550878494094923U) + aOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1]) + RotL64(aNonceWordB, 37U);
            aOrbiterG = (aWandererK + RotL64(aPrevious, 12U)) + 797712062039591797U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 15854849439012341347U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 996882939768167773U;
            aOrbiterF = RotL64((aOrbiterF * 14936703950807908575U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 3005829974130671692U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 8793495343509953906U;
            aOrbiterH = RotL64((aOrbiterH * 14065479348374612031U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 7710453029930631112U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 9511995836117707047U;
            aOrbiterK = RotL64((aOrbiterK * 7250766204781428201U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 670902975693341744U) + aOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 9045820304668279777U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 18373074917532639027U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 12417212387607119470U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 12816983560669985622U;
            aOrbiterB = RotL64((aOrbiterB * 8406003970221889847U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 17245432086377688540U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 6806521945548502014U;
            aOrbiterD = RotL64((aOrbiterD * 11335859481858640857U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 8947500746292365294U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 4468060468522895852U;
            aOrbiterE = RotL64((aOrbiterE * 7022481284816599797U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 9892975931958803992U) + RotL64(aNonceWordE, 15U);
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 3042599331526937836U;
            aOrbiterC = RotL64((aOrbiterC * 3308512896171443645U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 12991568221485810891U) + aOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 8551331172836260315U;
            aOrbiterA = RotL64((aOrbiterA * 4509997595920847057U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 183547209633334407U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 17275712817092769452U) ^ RotL64(aNonceWordC, 27U);
            aOrbiterI = RotL64((aOrbiterI * 15677355290000929085U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 12743863879392372723U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 13924571355038625040U;
            aOrbiterG = RotL64((aOrbiterG * 11966689345179279407U), 51U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterC, 47U);
            aIngress = aIngress + (RotL64(aOrbiterI, 56U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 51U));
            aIngress = aIngress + (RotL64(aOrbiterF, 3U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterG, 5U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterJ, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterG, 5U)) + aOrbiterK) + RotL64(aNonceWordD, 35U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 23U) + aOrbiterG) + RotL64(aOrbiterJ, 29U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 53U) + RotL64(aOrbiterK, 19U)) + aOrbiterD) + RotL64(aNonceWordH, 17U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 19U) + aOrbiterE) + RotL64(aOrbiterI, 52U)) + aWandererUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aIngress, 21U) + RotL64(aOrbiterG, 11U)) + aOrbiterC) + RotL64(aCarry, 57U)) + aWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 58U) + RotL64(aOrbiterA, 47U)) + aOrbiterF);
            aWandererB = aWandererB + ((RotL64(aScatter, 47U) + RotL64(aOrbiterJ, 27U)) + aOrbiterA);
            aWandererE = aWandererE ^ ((RotL64(aCross, 43U) + aOrbiterJ) + RotL64(aOrbiterB, 23U));
            aWandererF = aWandererF + (((RotL64(aScatter, 51U) + aOrbiterB) + RotL64(aOrbiterH, 41U)) + RotL64(aCarry, 29U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 60U) + RotL64(aOrbiterJ, 3U)) + aOrbiterI);
            aWandererG = aWandererG + ((RotL64(aIngress, 11U) + aOrbiterG) + RotL64(aOrbiterD, 58U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 54U));
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + RotL64(aWandererF, 23U);
            aCarry = aCarry + RotL64(aIngress, 36U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 19U) ^ RotL64(aNonceWordH, 11U)) ^ RotL64(aNonceWordD, 42U));
            aIngress = aIngress ^ (RotL64(mSnow[((aIndex + 19860U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((aIndex + 21098U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 5U) ^ RotL64(aNonceWordE, 19U)) ^ RotL64(aNonceWordA, 47U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20230U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneA[((aIndex + 20319U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 52U) ^ RotL64(aIngress, 21U)) ^ (RotL64(aCross, 37U) + RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (aWandererK + RotL64(aCross, 24U)) + 14499676118633326000U;
            aOrbiterD = (((aWandererE + RotL64(aScatter, 35U)) + RotL64(aCarry, 19U)) + 17191273593018552288U) + aOrbiterAssignSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterC = (aWandererA + RotL64(aPrevious, 5U)) + 4085176294948097737U;
            aOrbiterF = (aWandererI + RotL64(aIngress, 19U)) + 11112671474158908186U;
            aOrbiterH = (aWandererF + RotL64(aScatter, 11U)) + 8745787969012266485U;
            aOrbiterG = (aWandererD + RotL64(aCross, 21U)) + 18074049663777707948U;
            aOrbiterA = (aWandererC + RotL64(aIngress, 52U)) + 2543758649719164688U;
            aOrbiterJ = (aWandererH + RotL64(aPrevious, 57U)) + 4659584749412700523U;
            aOrbiterK = ((aWandererB + RotL64(aIngress, 3U)) + RotL64(aCarry, 51U)) + 974639159259871273U;
            aOrbiterE = (((aWandererJ + RotL64(aCross, 37U)) + RotL64(aCarry, 39U)) + 9211220687971081987U) + RotL64(aNonceWordC, 52U);
            aOrbiterI = (((aWandererG + RotL64(aScatter, 43U)) + 8567024626862182714U) + aOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1]) + RotL64(aNonceWordH, 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 5803002132294840900U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 11968489432878148467U) ^ RotL64(aNonceWordA, 3U);
            aOrbiterC = RotL64((aOrbiterC * 4501441062617123165U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 9470807228394903442U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterD) ^ 1692347973120388469U) ^ aOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1]) ^ RotL64(aNonceWordD, 51U);
            aOrbiterH = RotL64((aOrbiterH * 17433393164156231575U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 16510815732690193145U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 755159406833096510U;
            aOrbiterG = RotL64((aOrbiterG * 14091736464659561165U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 1518824876475937620U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 701225390867330446U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12264618860580199927U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 8425976693733003889U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 7182176375442410367U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8860605703761731859U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 4546566785167467924U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 2593340999038753749U;
            aOrbiterK = RotL64((aOrbiterK * 10152461487764567563U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 9756331608356622299U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 5511625814747641978U;
            aOrbiterE = RotL64((aOrbiterE * 4806076157539829529U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 8694400787420160733U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 12648969491371382682U;
            aOrbiterI = RotL64((aOrbiterI * 5346585704222643759U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 15261238546696118531U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 14236129054778329471U) ^ aOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11789581469516267749U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 16251500056378064213U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 790320176607605195U;
            aOrbiterD = RotL64((aOrbiterD * 15706130623435648555U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 17114773669444878655U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 14499676118633326000U;
            aOrbiterF = RotL64((aOrbiterF * 8095707555083587081U), 53U);
            //
            aIngress = RotL64(aOrbiterA, 13U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 29U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 21U));
            aIngress = aIngress + (RotL64(aOrbiterF, 19U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 56U));
            aIngress = aIngress + RotL64(aOrbiterK, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aIngress, 52U) + RotL64(aOrbiterA, 23U)) + aOrbiterI);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 57U) + aOrbiterB) + RotL64(aOrbiterG, 47U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 41U) + aOrbiterC) + RotL64(aOrbiterK, 11U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 21U) + aOrbiterB) + RotL64(aOrbiterH, 53U)) + aWandererUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aIngress, 60U) + RotL64(aOrbiterK, 42U)) + aOrbiterD);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterF, 13U)) + aOrbiterE);
            aWandererJ = aWandererJ + (((RotL64(aCross, 3U) + aOrbiterB) + RotL64(aOrbiterI, 19U)) + RotL64(aCarry, 27U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 11U) + aOrbiterE) + RotL64(aOrbiterK, 21U));
            aWandererA = aWandererA + ((((RotL64(aIngress, 13U) + RotL64(aOrbiterD, 57U)) + aOrbiterJ) + RotL64(aCarry, 43U)) + RotL64(aNonceWordF, 25U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 19U) + aOrbiterC) + RotL64(aOrbiterI, 28U)) + RotL64(aNonceWordG, 15U));
            aWandererB = aWandererB + (((RotL64(aScatter, 37U) + RotL64(aOrbiterC, 51U)) + aOrbiterB) + aWandererUpdateSaltC[((aIndex + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 56U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 37U));
            aCarry = aCarry + RotL64(aWandererD, 53U);
            aCarry = aCarry + RotL64(aIngress, 50U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 10U) ^ RotL64(aNonceWordF, 41U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 23201U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((aIndex + 23185U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 29U) ^ RotL64(aNonceWordE, 58U)) ^ RotL64(aNonceWordB, 21U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23986U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 23881U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aIngress, 51U)) + (RotL64(aCross, 19U) ^ RotL64(aPrevious, 34U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (aWandererB + RotL64(aIngress, 53U)) + 11450949896247900941U;
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 13U)) + 3905542253538116335U) + RotL64(aNonceWordC, 57U);
            aOrbiterG = (((aWandererE + RotL64(aCross, 48U)) + RotL64(aCarry, 53U)) + 9529740545977785305U) + aOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = ((aWandererF + RotL64(aScatter, 37U)) + RotL64(aCarry, 19U)) + 1856876631533143492U;
            aOrbiterE = (aWandererA + RotL64(aPrevious, 27U)) + 84253466320181686U;
            aOrbiterA = (aWandererD + RotL64(aIngress, 29U)) + 12577480918745432444U;
            aOrbiterK = (aWandererI + RotL64(aCross, 41U)) + 5625703170397704029U;
            aOrbiterI = (aWandererJ + RotL64(aScatter, 11U)) + 694608607323629282U;
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 39U)) + 3993981243536262204U) + RotL64(aNonceWordH, 31U);
            aOrbiterJ = (aWandererK + RotL64(aCross, 6U)) + 4119215953484892051U;
            aOrbiterD = (((aWandererG + RotL64(aIngress, 35U)) + RotL64(aCarry, 57U)) + 8785040118556157146U) + aOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 16234403619456882890U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 10398727475672860610U;
            aOrbiterG = RotL64((aOrbiterG * 5086871400049644715U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 18327987141759096769U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 2645964788056875452U;
            aOrbiterA = RotL64((aOrbiterA * 8778681366114628045U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 2859452497983106129U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 7196557924940881076U;
            aOrbiterI = RotL64((aOrbiterI * 14415389907490256711U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 930127943984174668U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 15673596916054795749U;
            aOrbiterJ = RotL64((aOrbiterJ * 7505660488733199479U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 16673140529110941163U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 2258448294877833760U;
            aOrbiterC = RotL64((aOrbiterC * 1821550319748977445U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 6870209259643931219U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 12749790107942194104U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4871407285968611725U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 17131374134617173866U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 6426448390733751612U;
            aOrbiterK = RotL64((aOrbiterK * 12490559588384058417U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 15592826434339731146U) + RotL64(aNonceWordG, 23U);
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 14182944418026376183U;
            aOrbiterF = RotL64((aOrbiterF * 7218860482893476233U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 17447476498234456596U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 972861017466618022U;
            aOrbiterD = RotL64((aOrbiterD * 9610670431280153921U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 13185309156950240549U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 14442284480744008537U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2907844852105175837U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 7816745313858811117U) + RotL64(aNonceWordA, 43U);
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 11450949896247900941U) ^ aOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 18317765298694454463U), 57U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterC, 35U);
            aIngress = aIngress + (RotL64(aOrbiterE, 42U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterG, 29U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 23U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 53U));
            aIngress = aIngress + RotL64(aOrbiterI, 38U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aCross, 58U) + RotL64(aOrbiterH, 43U)) + aOrbiterD);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterK, 3U)) + aOrbiterE) + aWandererUpdateSaltF[((aIndex + 22U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterA, 5U)) + aOrbiterC);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 21U) + aOrbiterH) + RotL64(aOrbiterA, 35U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 5U) + aOrbiterG) + RotL64(aOrbiterJ, 10U)) + RotL64(aCarry, 51U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 39U) + aOrbiterI) + RotL64(aOrbiterF, 27U)) + RotL64(aNonceWordD, 46U));
            aWandererD = aWandererD + ((RotL64(aCross, 29U) + aOrbiterI) + RotL64(aOrbiterD, 47U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 51U) + aOrbiterK) + RotL64(aOrbiterB, 39U)) + RotL64(aNonceWordB, 49U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 37U) + aOrbiterF) + RotL64(aOrbiterC, 37U)) + aWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 54U) + RotL64(aOrbiterF, 21U)) + aOrbiterG);
            aWandererB = aWandererB + (((RotL64(aCross, 19U) + aOrbiterB) + RotL64(aOrbiterE, 56U)) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 14U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + RotL64(aWandererB, 27U);
            aCarry = aCarry + RotL64(aIngress, 12U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 12U) ^ RotL64(aNonceWordE, 39U)) ^ RotL64(aNonceWordG, 3U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 32658U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((aIndex + 28758U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 27U) ^ RotL64(aNonceWordA, 41U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32274U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneC[((aIndex + 30879U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 3U) ^ RotL64(aIngress, 35U)) + (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 18U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (((aWandererG + RotL64(aScatter, 19U)) + RotL64(aCarry, 51U)) + 7896237440058555694U) + RotL64(aNonceWordF, 12U);
            aOrbiterD = (((aWandererK + RotL64(aIngress, 58U)) + RotL64(aCarry, 27U)) + 11870529476037558635U) + aOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 47U)) + 9158983227801569448U) + RotL64(aNonceWordH, 55U);
            aOrbiterC = ((aWandererH + RotL64(aCross, 29U)) + RotL64(aCarry, 21U)) + 4710172270996950329U;
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 39U)) + 14634482800356647630U) + aOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = (aWandererF + RotL64(aCross, 23U)) + 8822207952170610891U;
            aOrbiterF = (aWandererJ + RotL64(aIngress, 51U)) + 13755891414028982553U;
            aOrbiterI = (aWandererD + RotL64(aScatter, 3U)) + 4555293067488040719U;
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 5U)) + 2816805148093762081U;
            aOrbiterK = (aWandererE + RotL64(aIngress, 60U)) + 2122631477965135190U;
            aOrbiterH = (aWandererA + RotL64(aScatter, 41U)) + 4592922416380416071U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 7102471666524164715U) + aOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 17274623547879474204U;
            aOrbiterG = RotL64((aOrbiterG * 5443572270546181789U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 938587316977094680U) + RotL64(aNonceWordD, 61U);
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 18258015823797023523U;
            aOrbiterA = RotL64((aOrbiterA * 6068819567674605919U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 5809987756043471595U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 5083075160112581620U;
            aOrbiterE = RotL64((aOrbiterE * 3313957222154937503U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 5960021727750946496U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 5967477320950630150U;
            aOrbiterF = RotL64((aOrbiterF * 330964768256424655U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 6578428711689296132U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 5601728218197771276U;
            aOrbiterI = RotL64((aOrbiterI * 9552559022315971847U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 7923809409017855241U) + aOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 16479366540906497019U;
            aOrbiterJ = RotL64((aOrbiterJ * 7118578387798460919U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 17000467091738009736U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 6801634573655508028U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10584635770060137089U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 123668445682719574U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 14462802805503986316U;
            aOrbiterH = RotL64((aOrbiterH * 12398236364304875941U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 2433338393261685871U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 13869012262404991729U;
            aOrbiterB = RotL64((aOrbiterB * 12443261517483942937U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 4832421585086516998U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 11284414949564414958U) ^ RotL64(aNonceWordA, 9U);
            aOrbiterD = RotL64((aOrbiterD * 1586650935440790991U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 17872556812561387030U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 7896237440058555694U;
            aOrbiterC = RotL64((aOrbiterC * 16784165278693056013U), 35U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterH, 51U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 23U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 10U));
            aIngress = aIngress + (RotL64(aOrbiterG, 27U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterA, 19U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterE, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aCross, 41U) + aOrbiterD) + RotL64(aOrbiterI, 37U)) + aWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 19U) + aOrbiterG) + RotL64(aOrbiterJ, 23U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterC, 57U)) + aOrbiterG);
            aWandererF = aWandererF + ((RotL64(aPrevious, 30U) + aOrbiterA) + RotL64(aOrbiterB, 34U));
            aWandererK = aWandererK ^ ((((RotL64(aScatter, 5U) + aOrbiterC) + RotL64(aOrbiterE, 41U)) + RotL64(aNonceWordB, 3U)) + aWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 53U) + aOrbiterE) + RotL64(aOrbiterB, 53U)) + RotL64(aCarry, 27U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterC, 39U)) + aOrbiterD) + RotL64(aNonceWordE, 17U));
            aWandererC = aWandererC + (((RotL64(aCross, 28U) + aOrbiterH) + RotL64(aOrbiterA, 51U)) + RotL64(aCarry, 3U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterG, 19U)) + aOrbiterF);
            aWandererD = aWandererD + ((RotL64(aCross, 11U) + aOrbiterD) + RotL64(aOrbiterK, 28U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 21U) + aOrbiterJ) + RotL64(aOrbiterF, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererA);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + (RotL64(aWandererJ, 42U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + RotL64(aWandererF, 13U);
            aCarry = aCarry + RotL64(aIngress, 44U);
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

void TwistExpander_Archery_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xD5D6C070E57583E9ULL + 0xE49ED7A88B0B7E5AULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xF5C8F2B53146EEFFULL + 0x9E46E313A013B7DEULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xC900A8E98C32B4D1ULL + 0x8E032914C6E1EC87ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xB4B11395545706F3ULL + 0xEA84952420B72731ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xBB75D65950B4A685ULL + 0xC2A504CC79182018ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xCDA6B0619120E789ULL + 0xEAAE76E62412C4F2ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xC6E0CC601EDD096BULL + 0x843B59D338742C03ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xF471172B1E1CD4D9ULL + 0xBB78DADBBE316F69ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordA, 35U) ^ RotL64(aNonceWordH, 47U)) ^ RotL64(aNonceWordG, 13U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 407U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3863U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 30U) ^ RotL64(aNonceWordF, 5U)) ^ RotL64(aNonceWordB, 41U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 989U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 6042U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aIngress, 19U)) ^ (RotL64(aCross, 50U) + RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 19U)) + RotL64(aCarry, 53U)) + 6361545377408870615U;
            aOrbiterF = (aWandererB + RotL64(aCross, 47U)) + 2967245486744774933U;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 4U)) + RotL64(aCarry, 39U)) + 3836634268482850139U;
            aOrbiterK = ((aWandererD + RotL64(aIngress, 23U)) + 7691642115360086297U) + aOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = (aWandererG + RotL64(aScatter, 13U)) + 16479280384178279281U;
            aOrbiterI = ((aWandererA + RotL64(aCross, 53U)) + RotL64(aCarry, 3U)) + 2901468732552539249U;
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 58U)) + 2600353867755647475U) + aOrbiterAssignSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterG = ((aWandererH + RotL64(aIngress, 41U)) + 5666596904781510956U) + RotL64(aNonceWordC, 13U);
            aOrbiterB = ((aWandererJ + RotL64(aCross, 37U)) + 16108791609267427553U) + RotL64(aNonceWordG, 45U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 8389926875737312112U) + RotL64(aNonceWordB, 5U);
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 1689501721163024426U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6517194895779049139U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 11721701506949917719U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 3963842745030140473U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6692473494944919373U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 8510538243472109368U) + aOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 18281865214102080387U;
            aOrbiterG = RotL64((aOrbiterG * 1351546966368884609U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 2259725140963665123U) + aOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 11652011949557979650U;
            aOrbiterB = RotL64((aOrbiterB * 11260100762113295037U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 1116085424226174473U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 4725260319270802912U;
            aOrbiterJ = RotL64((aOrbiterJ * 4697109059565450269U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 7348945429843437036U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 1249234309180653260U;
            aOrbiterK = RotL64((aOrbiterK * 3136745255820405881U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 12463505532573389603U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 2304125977906510386U;
            aOrbiterC = RotL64((aOrbiterC * 9960816714791454421U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 2178037443783425551U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 11712110130079307683U) ^ RotL64(aNonceWordA, 43U);
            aOrbiterF = RotL64((aOrbiterF * 9797864956200779505U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 10703510612147312252U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 18155460326242413483U;
            aOrbiterH = RotL64((aOrbiterH * 6903953708987478723U), 23U);
            //
            aIngress = RotL64(aOrbiterK, 26U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + RotL64(aOrbiterJ, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterF, 3U)) + aOrbiterG);
            aWandererD = aWandererD + (((RotL64(aScatter, 47U) + aOrbiterC) + RotL64(aOrbiterB, 47U)) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterB, 10U)) + aOrbiterF) + RotL64(aNonceWordD, 57U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 29U) + aOrbiterF) + RotL64(aOrbiterC, 35U)) + aWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterD, 19U)) + aOrbiterK);
            aWandererC = aWandererC + (((RotL64(aIngress, 43U) + aOrbiterK) + RotL64(aOrbiterH, 43U)) + aWandererUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 52U) + aOrbiterB) + RotL64(aOrbiterD, 23U));
            aWandererG = aWandererG + ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterC, 53U)) + aOrbiterI) + RotL64(aCarry, 43U)) + RotL64(aNonceWordE, 6U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 39U) + aOrbiterJ) + RotL64(aOrbiterB, 28U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererC);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 30U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + RotL64(aWandererA, 19U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 57U) ^ RotL64(aNonceWordB, 41U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 9525U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 14147U)) & S_BLOCK1], 26U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 58U) ^ RotL64(aNonceWordF, 21U)) ^ RotL64(aNonceWordH, 47U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8589U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((aIndex + 15334U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aIngress, 13U)) ^ (RotL64(aPrevious, 39U) + RotL64(aCarry, 26U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (((aWandererD + RotL64(aIngress, 3U)) + RotL64(aCarry, 47U)) + 4384716820085860551U) + RotL64(aNonceWordF, 27U);
            aOrbiterD = ((aWandererE + RotL64(aScatter, 13U)) + 9715780315942116888U) + aOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = (((aWandererC + RotL64(aCross, 47U)) + RotL64(aCarry, 23U)) + 15963520052789178632U) + aOrbiterAssignSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 28U)) + RotL64(aCarry, 35U)) + 14346700690686392938U;
            aOrbiterC = (aWandererJ + RotL64(aScatter, 37U)) + 6005518012489966643U;
            aOrbiterE = (aWandererK + RotL64(aCross, 19U)) + 2506732930310252119U;
            aOrbiterB = (aWandererF + RotL64(aIngress, 57U)) + 16782163084851775826U;
            aOrbiterA = (aWandererG + RotL64(aPrevious, 41U)) + 823673076571076303U;
            aOrbiterK = ((aWandererH + RotL64(aIngress, 24U)) + 1634084509064077736U) + RotL64(aNonceWordB, 61U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 1288134975466877686U) + aOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 2998220403162908444U;
            aOrbiterF = RotL64((aOrbiterF * 4321412662318298283U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 220430672180734911U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 10223923547068528867U) ^ RotL64(aNonceWordE, 59U);
            aOrbiterC = RotL64((aOrbiterC * 12577370238343872139U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 11696469696177647608U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 6545430420379636963U;
            aOrbiterB = RotL64((aOrbiterB * 8387163146257553773U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 79691451831797107U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 8971444023498649419U;
            aOrbiterA = RotL64((aOrbiterA * 7148919880477390009U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 5624403902454498793U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 9468064161002030997U) ^ RotL64(aNonceWordD, 56U);
            aOrbiterK = RotL64((aOrbiterK * 8243560528100864595U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 4619361544913629805U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 12682446273369750704U;
            aOrbiterI = RotL64((aOrbiterI * 10879074713156075641U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 8728730962617599223U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 9099675924074253030U) ^ aOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5525644236954497523U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 3298303921318288541U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 5953276499411658358U;
            aOrbiterE = RotL64((aOrbiterE * 10565471305001292693U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 6725769507592688539U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 1057277456510215817U;
            aOrbiterD = RotL64((aOrbiterD * 8269412198279297075U), 51U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterH, 19U);
            aIngress = aIngress + (RotL64(aOrbiterC, 60U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterF, 57U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + RotL64(aOrbiterD, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aIngress, 3U) + RotL64(aOrbiterH, 48U)) + aOrbiterC);
            aWandererD = aWandererD ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterC, 5U)) + aOrbiterI) + RotL64(aNonceWordC, 11U));
            aWandererF = aWandererF + ((((RotL64(aScatter, 54U) + RotL64(aOrbiterC, 29U)) + aOrbiterA) + RotL64(aNonceWordG, 29U)) + aWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterK, 43U)) + aOrbiterB);
            aWandererG = aWandererG + ((RotL64(aIngress, 27U) + aOrbiterB) + RotL64(aOrbiterE, 53U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterF, 39U)) + aOrbiterI);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 60U) + aOrbiterD) + RotL64(aOrbiterB, 10U)) + RotL64(aCarry, 41U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 43U) + aOrbiterK) + RotL64(aOrbiterH, 21U)) + aWandererUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 23U) + RotL64(aOrbiterC, 57U)) + aOrbiterD) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererJ);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 48U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + RotL64(aWandererG, 57U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 57U) ^ RotL64(aNonceWordE, 39U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 21095U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneA[((aIndex + 22658U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 47U) ^ RotL64(aNonceWordC, 21U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18944U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((aIndex + 19922U)) & S_BLOCK1], 36U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 20U)) ^ (RotL64(aCross, 5U) + RotL64(aIngress, 43U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = ((aWandererK + RotL64(aIngress, 23U)) + 3561491146322798260U) + RotL64(aNonceWordB, 59U);
            aOrbiterG = (aWandererB + RotL64(aCross, 39U)) + 7075025056181885339U;
            aOrbiterE = (aWandererF + RotL64(aPrevious, 18U)) + 9230910887904171613U;
            aOrbiterI = (((aWandererI + RotL64(aScatter, 35U)) + RotL64(aCarry, 57U)) + 4119781172609908917U) + aOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = (aWandererH + RotL64(aCross, 57U)) + 17155609083870983149U;
            aOrbiterH = (aWandererG + RotL64(aIngress, 27U)) + 2423018561430181695U;
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 47U)) + 12957280305617615744U) + aOrbiterAssignSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 4U)) + RotL64(aCarry, 11U)) + 2461704174772065813U;
            aOrbiterD = (((aWandererA + RotL64(aCross, 51U)) + RotL64(aCarry, 37U)) + 7907123257849391997U) + RotL64(aNonceWordG, 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 7257868138318960007U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 16425903703085702285U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7996935869077231999U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 2990822664594079467U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 5654819006718953817U;
            aOrbiterC = RotL64((aOrbiterC * 4465096036756887801U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 12183676471235678779U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 15026286960542123922U;
            aOrbiterI = RotL64((aOrbiterI * 17199049329995315279U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 12169080607071830522U) + RotL64(aNonceWordD, 11U);
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 2906296852254787499U) ^ RotL64(aNonceWordF, 26U);
            aOrbiterG = RotL64((aOrbiterG * 6754514406846040163U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 3029858695410344584U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 14406410317495954566U;
            aOrbiterK = RotL64((aOrbiterK * 9663780721657983421U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 11048818178401163861U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 13622063920319445043U;
            aOrbiterH = RotL64((aOrbiterH * 2516025554421589857U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 2642646089141233277U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 12761571777929273548U;
            aOrbiterA = RotL64((aOrbiterA * 5518252696078700127U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 7753802695131502382U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 8510425459525030222U;
            aOrbiterF = RotL64((aOrbiterF * 12412361423636026483U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 13522645164493316722U) + aOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 1437430302489702713U;
            aOrbiterD = RotL64((aOrbiterD * 14019316635365783545U), 39U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterD, 11U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 19U));
            aIngress = aIngress + (RotL64(aOrbiterA, 41U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 23U));
            aIngress = aIngress + RotL64(aOrbiterE, 34U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterC, 11U)) + aOrbiterK) + RotL64(aNonceWordA, 21U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterI, 30U)) + aOrbiterG);
            aWandererH = aWandererH ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterI, 37U)) + aOrbiterE) + aWandererUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 60U) + RotL64(aOrbiterC, 23U)) + aOrbiterG);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterG, 43U)) + aOrbiterK);
            aWandererG = aWandererG + (((RotL64(aIngress, 47U) + RotL64(aOrbiterA, 50U)) + aOrbiterH) + RotL64(aCarry, 41U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 5U) + aOrbiterE) + RotL64(aOrbiterF, 3U)) + RotL64(aNonceWordH, 31U));
            aWandererA = aWandererA + (((RotL64(aCross, 35U) + aOrbiterD) + RotL64(aOrbiterI, 19U)) + RotL64(aCarry, 51U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 26U) + RotL64(aOrbiterH, 57U)) + aOrbiterG) + aWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererI);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 30U));
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererG, 41U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 51U) ^ RotL64(aNonceWordB, 5U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 32163U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneB[((aIndex + 31181U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 3U) ^ RotL64(aNonceWordG, 11U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25399U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 28885U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aIngress, 11U)) ^ (RotL64(aCarry, 28U) + RotL64(aPrevious, 43U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((aWandererD + RotL64(aScatter, 44U)) + RotL64(aCarry, 35U)) + 3105313968748067810U;
            aOrbiterB = ((aWandererA + RotL64(aCross, 23U)) + 9977249451119627064U) + aOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 29U)) + RotL64(aCarry, 21U)) + 17941392803495349366U;
            aOrbiterK = (aWandererJ + RotL64(aIngress, 39U)) + 4279533326705471133U;
            aOrbiterC = (aWandererB + RotL64(aScatter, 53U)) + 13983828966811580039U;
            aOrbiterG = (aWandererI + RotL64(aPrevious, 35U)) + 3983490984234810378U;
            aOrbiterJ = (aWandererC + RotL64(aIngress, 13U)) + 308786542215259956U;
            aOrbiterH = (((aWandererH + RotL64(aCross, 48U)) + RotL64(aCarry, 57U)) + 8443607695364427037U) + RotL64(aNonceWordA, 19U);
            aOrbiterF = (((aWandererE + RotL64(aScatter, 57U)) + 14939626441464340668U) + aOrbiterAssignSaltC[(((31U - aIndex) + 4U)) & S_SALT1]) + RotL64(aNonceWordE, 31U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 9350693577306121110U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 1717071159396961752U;
            aOrbiterA = RotL64((aOrbiterA * 11062480662625054525U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 15911765265202100610U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 14898546272333182767U;
            aOrbiterC = RotL64((aOrbiterC * 2674900543810733067U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 3560903518513465868U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 5367062725726860234U;
            aOrbiterJ = RotL64((aOrbiterJ * 8521908836601319553U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 15233321480618877327U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 9288449812290126074U;
            aOrbiterD = RotL64((aOrbiterD * 6815298520404038519U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 5504840529511585676U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 6825598386801620046U) ^ aOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11666542445846250077U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 6433024450721339470U) + aOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 97934156644929458U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8630530773006923215U), 29U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterG) + 3260053604798744515U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]) + RotL64(aNonceWordD, 56U);
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 16539416623243059076U;
            aOrbiterH = RotL64((aOrbiterH * 12199577351166064503U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 9814290051339038920U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 13280156404507444041U) ^ RotL64(aNonceWordC, 11U);
            aOrbiterF = RotL64((aOrbiterF * 15269010043398910061U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 11853942590993546833U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 13207869904312989977U;
            aOrbiterB = RotL64((aOrbiterB * 15503461937625795969U), 13U);
            //
            aIngress = RotL64(aOrbiterA, 36U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterK, 13U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 23U));
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterC, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterG, 14U)) + aOrbiterC);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 5U) + RotL64(aOrbiterJ, 39U)) + aOrbiterC) + RotL64(aCarry, 35U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterJ, 43U)) + aOrbiterH);
            aWandererA = aWandererA + ((RotL64(aCross, 18U) + RotL64(aOrbiterF, 53U)) + aOrbiterD);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterG, 29U)) + aOrbiterK) + aWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aScatter, 35U) + aOrbiterJ) + RotL64(aOrbiterB, 35U)) + RotL64(aNonceWordF, 55U)) + aWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 11U) + aOrbiterK) + RotL64(aOrbiterA, 6U));
            aWandererD = aWandererD + ((((RotL64(aPrevious, 51U) + aOrbiterD) + RotL64(aOrbiterB, 21U)) + RotL64(aCarry, 3U)) + RotL64(aNonceWordB, 5U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 60U) + aOrbiterF) + RotL64(aOrbiterB, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererC, 60U) ^ aWandererD);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererE, 11U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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

void TwistExpander_Archery_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xFF7F15A9514FF145ULL + 0xF5108A9A62663164ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xEB028948DA250F8FULL + 0xDAF8735A36459BDFULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xDF72196A80C9D795ULL + 0xEF343CDC4019E7ADULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x9504548AB0AFF16BULL + 0xA8F4A1E47745BFAEULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x940B58EE8771CC39ULL + 0xAB6B239F51BFD6EBULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x8647AA0D21DE4A79ULL + 0xFD00713069AC9144ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xC4E2098987597C17ULL + 0x9156DBF369688FCFULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xE5A694D2773FEE61ULL + 0xC3BF20B7A6DE9F73ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 20U) ^ RotL64(aNonceWordG, 51U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 4553U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 2885U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 21U) ^ RotL64(aNonceWordC, 34U)) ^ RotL64(aNonceWordD, 5U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 483U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneA[((aIndex + 4245U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 24U) ^ RotL64(aCross, 11U)) ^ (RotL64(aIngress, 37U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((((aWandererB + RotL64(aIngress, 5U)) + RotL64(aCarry, 57U)) + 3917730204724097072U) + aOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1]) + RotL64(aNonceWordB, 49U);
            aOrbiterF = (aWandererJ + RotL64(aScatter, 29U)) + 1874642340716212824U;
            aOrbiterA = (((aWandererK + RotL64(aPrevious, 57U)) + RotL64(aCarry, 11U)) + 6900165757434854160U) + aOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = (((aWandererF + RotL64(aCross, 19U)) + RotL64(aCarry, 41U)) + 12750946097023807161U) + RotL64(aNonceWordH, 53U);
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 42U)) + 6563216048479513594U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 14960240191349450795U) + aOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 16306180275951788289U;
            aOrbiterA = RotL64((aOrbiterA * 12077366095522790283U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 6502066618271045547U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterC) ^ 6219852857850888738U) ^ aOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1]) ^ RotL64(aNonceWordC, 15U);
            aOrbiterH = RotL64((aOrbiterH * 10892297250334325283U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 2272931312452845850U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 3028929882263199463U;
            aOrbiterC = RotL64((aOrbiterC * 11005324285856805069U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 6067393030073568112U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterJ) ^ 10094809900437037258U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]) ^ RotL64(aNonceWordA, 46U);
            aOrbiterF = RotL64((aOrbiterF * 18095564940730322769U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 5962414178157074575U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 15755563045799129417U;
            aOrbiterJ = RotL64((aOrbiterJ * 3692603590609922031U), 53U);
            //
            aIngress = RotL64(aOrbiterJ, 28U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 13U));
            aIngress = aIngress + RotL64(aOrbiterA, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aPrevious, 48U) + aOrbiterC) + RotL64(aOrbiterF, 35U)) + RotL64(aCarry, 19U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 11U) + aOrbiterA) + RotL64(aOrbiterH, 23U)) + RotL64(aNonceWordD, 61U));
            aWandererF = aWandererF + ((((RotL64(aScatter, 19U) + RotL64(aOrbiterH, 13U)) + aOrbiterC) + RotL64(aCarry, 41U)) + aWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterJ, 60U)) + aOrbiterA) + aWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 39U) + aOrbiterJ) + RotL64(aOrbiterF, 47U)) + RotL64(aNonceWordE, 9U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererB, 36U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 29U) ^ RotL64(aNonceWordB, 43U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 11754U)) & S_BLOCK1], 18U) ^ RotL64(aOperationLaneD[((aIndex + 12216U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 35U) ^ RotL64(aNonceWordD, 52U)) ^ RotL64(aNonceWordH, 21U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 12125U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 9144U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCross, 51U)) ^ (RotL64(aPrevious, 11U) ^ RotL64(aCarry, 36U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (aWandererK + RotL64(aIngress, 11U)) + 252059974543142812U;
            aOrbiterB = (((aWandererA + RotL64(aCross, 41U)) + RotL64(aCarry, 21U)) + 11690823093681457368U) + aOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = ((((aWandererG + RotL64(aScatter, 3U)) + RotL64(aCarry, 39U)) + 13282189752890971123U) + aOrbiterAssignSaltE[((aIndex + 4U)) & S_SALT1]) + RotL64(aNonceWordE, 13U);
            aOrbiterF = (((aWandererI + RotL64(aPrevious, 26U)) + RotL64(aCarry, 5U)) + 9507416294305708435U) + RotL64(aNonceWordA, 31U);
            aOrbiterA = (aWandererD + RotL64(aScatter, 53U)) + 14053038174390776539U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 14605253312318725009U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 18138286582677863671U;
            aOrbiterG = RotL64((aOrbiterG * 10595905899691011321U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 8530091235978489988U) + aOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 14381731677571170073U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11675896999665768253U), 13U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterG) + 13316413456378978456U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]) + RotL64(aNonceWordG, 25U);
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 3910529530149320706U;
            aOrbiterC = RotL64((aOrbiterC * 16000139333493588429U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 6302070286831566901U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 12324134652758551396U;
            aOrbiterB = RotL64((aOrbiterB * 17136438281540250165U), 51U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterC) + 4773478557638475048U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1]) + RotL64(aNonceWordB, 52U);
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 4031153435446078944U;
            aOrbiterF = RotL64((aOrbiterF * 3876928995240982769U), 21U);
            //
            aIngress = RotL64(aOrbiterG, 13U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 27U));
            aIngress = aIngress + RotL64(aOrbiterB, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aCross, 23U) + aOrbiterF) + RotL64(aOrbiterC, 21U)) + RotL64(aCarry, 3U)) + aWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 3U) + aOrbiterA) + RotL64(aOrbiterC, 37U)) + RotL64(aNonceWordF, 5U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 34U) + RotL64(aOrbiterC, 3U)) + aOrbiterB) + RotL64(aCarry, 27U)) + RotL64(aNonceWordC, 37U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterG, 12U)) + aOrbiterF);
            aWandererD = aWandererD + (((RotL64(aIngress, 11U) + RotL64(aOrbiterF, 51U)) + aOrbiterB) + aWandererUpdateSaltB[((aIndex + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 46U));
            aCarry = aCarry + RotL64(aWandererI, 13U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordE, 53U) ^ RotL64(aNonceWordD, 13U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 22035U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneA[((aIndex + 22984U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 51U) ^ RotL64(aNonceWordH, 37U)) ^ RotL64(aNonceWordB, 29U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 23489U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneC[((aIndex + 23857U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 18U) + RotL64(aIngress, 53U)) ^ (RotL64(aCross, 3U) + RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (aWandererC + RotL64(aPrevious, 19U)) + 7651355040951791298U;
            aOrbiterB = (((aWandererI + RotL64(aCross, 4U)) + RotL64(aCarry, 39U)) + 13988210277931659312U) + RotL64(aNonceWordF, 61U);
            aOrbiterI = ((aWandererK + RotL64(aScatter, 37U)) + RotL64(aCarry, 53U)) + 9846849412579537783U;
            aOrbiterC = ((aWandererB + RotL64(aIngress, 51U)) + 12746719939495876158U) + aOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = ((((aWandererE + RotL64(aPrevious, 29U)) + RotL64(aCarry, 13U)) + 11498066185182895284U) + aOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1]) + RotL64(aNonceWordC, 15U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 11101058955193080232U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 15513734459555672046U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6974281215677538561U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 15711108675349394643U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 4771231759949468556U) ^ RotL64(aNonceWordB, 45U);
            aOrbiterB = RotL64((aOrbiterB * 9806191054594333615U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 11449258010811305256U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 17036938391509986723U;
            aOrbiterG = RotL64((aOrbiterG * 7411466953205347639U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 6999245666776654250U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 2106819066263369528U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13005885810757743129U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 12716183358903477216U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterB) ^ 16752724547046059889U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]) ^ RotL64(aNonceWordD, 13U);
            aOrbiterD = RotL64((aOrbiterD * 11475905692393034141U), 47U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterC, 19U);
            aIngress = aIngress + (RotL64(aOrbiterB, 39U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterD, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aIngress, 13U) + RotL64(aOrbiterD, 27U)) + aOrbiterI) + RotL64(aNonceWordG, 51U)) + aWandererUpdateSaltE[((aIndex + 22U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterI, 43U)) + aOrbiterC);
            aWandererE = aWandererE + ((((RotL64(aCross, 27U) + aOrbiterB) + RotL64(aOrbiterG, 57U)) + RotL64(aCarry, 57U)) + RotL64(aNonceWordA, 54U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 58U) + aOrbiterG) + RotL64(aOrbiterC, 14U)) + aWandererUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 3U) + aOrbiterC) + RotL64(aOrbiterD, 35U)) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 38U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + RotL64(aWandererC, 3U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 35U) ^ RotL64(aNonceWordD, 5U)) ^ RotL64(aNonceWordH, 13U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 28374U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28837U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 27U) ^ RotL64(aNonceWordA, 47U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 31775U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneD[((aIndex + 27928U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 6U) ^ RotL64(aPrevious, 23U)) + (RotL64(aCross, 43U) + RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (((aWandererE + RotL64(aScatter, 41U)) + RotL64(aCarry, 37U)) + 12027839670755583592U) + aOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = (((aWandererH + RotL64(aIngress, 3U)) + RotL64(aCarry, 21U)) + 15380130703509859843U) + RotL64(aNonceWordB, 59U);
            aOrbiterC = (((aWandererA + RotL64(aPrevious, 52U)) + 4590907433867798074U) + aOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1]) + RotL64(aNonceWordE, 27U);
            aOrbiterG = ((aWandererC + RotL64(aCross, 19U)) + RotL64(aCarry, 53U)) + 1754574023602519724U;
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 27U)) + 9832756659564903767U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 5035088494491470403U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 14199170923323644638U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4518257134117207121U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 8325619421264440438U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 969534320779067977U;
            aOrbiterH = RotL64((aOrbiterH * 17767548306355264705U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 270575869402913847U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterJ) ^ 13344806516599578910U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1]) ^ RotL64(aNonceWordG, 49U);
            aOrbiterG = RotL64((aOrbiterG * 10193544126281901579U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 15143147951139409101U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 14425582489214169238U) ^ RotL64(aNonceWordC, 47U);
            aOrbiterJ = RotL64((aOrbiterJ * 16893787086337916355U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 13951127523239064584U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 14177925225918293579U) ^ aOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13079514031864998485U), 21U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterG, 48U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 35U));
            aIngress = aIngress + RotL64(aOrbiterC, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((((RotL64(aScatter, 35U) + aOrbiterI) + RotL64(aOrbiterG, 58U)) + RotL64(aCarry, 27U)) + RotL64(aNonceWordF, 50U)) + aWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 27U) + aOrbiterJ) + RotL64(aOrbiterC, 35U));
            aWandererE = aWandererE + ((((RotL64(aCross, 19U) + RotL64(aOrbiterH, 11U)) + aOrbiterI) + RotL64(aCarry, 39U)) + RotL64(aNonceWordD, 7U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterC, 21U)) + aOrbiterG) + aWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 6U) + RotL64(aOrbiterH, 3U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + RotL64(aWandererE, 48U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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

void TwistExpander_Archery_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xC2C1289579965A0DULL + 0xEA359782659F7334ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xA1F8BE6D9DC1B5D1ULL + 0xB6F61360ED908CF9ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x9500FC3259B74B73ULL + 0xCBD40E13526A67D8ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xA5453C1586F99D27ULL + 0xAC84E944616C54E1ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xE3D817334BD04959ULL + 0xCC5161D00922C877ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x8E4F78796BAC1DBFULL + 0xCE6715441766558AULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xA31D80E419575357ULL + 0xECA1A8684095EBCDULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x9690E175B263F31BULL + 0xC20CCFA9B0755D40ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 39U) ^ RotL64(aNonceWordA, 19U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 4360U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((aIndex + 562U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 27U) ^ RotL64(aNonceWordF, 44U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 7006U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((aIndex + 2096U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aIngress, 13U)) + (RotL64(aCross, 30U) ^ RotL64(aPrevious, 43U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((aWandererK + RotL64(aIngress, 11U)) + 11450949896247900941U) + aOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = (((aWandererA + RotL64(aPrevious, 19U)) + RotL64(aCarry, 19U)) + 3905542253538116335U) + RotL64(aNonceWordB, 16U);
            aOrbiterC = (((aWandererJ + RotL64(aScatter, 3U)) + RotL64(aCarry, 5U)) + 9529740545977785305U) + aOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = ((aWandererI + RotL64(aCross, 27U)) + 1856876631533143492U) + RotL64(aNonceWordC, 27U);
            aOrbiterG = (aWandererG + RotL64(aScatter, 41U)) + 84253466320181686U;
            aOrbiterE = ((aWandererH + RotL64(aCross, 58U)) + RotL64(aCarry, 57U)) + 12577480918745432444U;
            aOrbiterI = (aWandererC + RotL64(aPrevious, 47U)) + 5625703170397704029U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 694608607323629282U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 3993981243536262204U;
            aOrbiterC = RotL64((aOrbiterC * 2502835860198146381U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 4119215953484892051U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 8785040118556157146U) ^ RotL64(aNonceWordA, 11U);
            aOrbiterG = RotL64((aOrbiterG * 17113521266125471625U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 16234403619456882890U) + RotL64(aNonceWordG, 17U);
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 10398727475672860610U;
            aOrbiterE = RotL64((aOrbiterE * 5086871400049644715U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 18327987141759096769U) + aOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 2645964788056875452U;
            aOrbiterI = RotL64((aOrbiterI * 8778681366114628045U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 2859452497983106129U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 7196557924940881076U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14415389907490256711U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 930127943984174668U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 15673596916054795749U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7505660488733199479U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 16673140529110941163U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 2258448294877833760U) ^ aOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1821550319748977445U), 13U);
            //
            aIngress = RotL64(aOrbiterG, 27U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterA, 47U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 41U));
            aIngress = aIngress + RotL64(aOrbiterE, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aIngress, 29U) + RotL64(aOrbiterA, 3U)) + aOrbiterE) + aWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 4U) + RotL64(aOrbiterK, 29U)) + aOrbiterH);
            aWandererC = aWandererC + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterH, 13U)) + aOrbiterC) + RotL64(aCarry, 35U)) + RotL64(aNonceWordH, 59U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 19U) + aOrbiterG) + RotL64(aOrbiterI, 41U));
            aWandererI = aWandererI + (((RotL64(aCross, 35U) + aOrbiterI) + RotL64(aOrbiterK, 58U)) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ ((((RotL64(aIngress, 13U) + aOrbiterH) + RotL64(aOrbiterI, 35U)) + RotL64(aNonceWordD, 5U)) + aWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterA, 51U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererA);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + RotL64(aWandererH, 18U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 35U) ^ RotL64(aNonceWordE, 57U)) ^ RotL64(aNonceWordC, 27U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 13868U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneD[((aIndex + 8249U)) & S_BLOCK1], 10U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 13U) ^ RotL64(aNonceWordH, 34U)) ^ RotL64(aNonceWordB, 3U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15497U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 14441U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 50U) + RotL64(aCarry, 23U)) ^ (RotL64(aPrevious, 37U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (((aWandererA + RotL64(aScatter, 3U)) + RotL64(aCarry, 35U)) + 10915618884692072446U) + RotL64(aNonceWordF, 21U);
            aOrbiterE = ((aWandererE + RotL64(aIngress, 28U)) + RotL64(aCarry, 21U)) + 12634922308499254909U;
            aOrbiterJ = (aWandererC + RotL64(aCross, 13U)) + 6533934734564499389U;
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 47U)) + 6744203303756105181U) + aOrbiterAssignSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterG = (((aWandererD + RotL64(aCross, 19U)) + 13086782386652045658U) + aOrbiterAssignSaltF[(((31U - aIndex) + 12U)) & S_SALT1]) + RotL64(aNonceWordD, 49U);
            aOrbiterK = (aWandererG + RotL64(aScatter, 57U)) + 5693840533331397822U;
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 35U)) + RotL64(aCarry, 53U)) + 1803663542535024611U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 3597219300593287708U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 1429753448204448904U;
            aOrbiterJ = RotL64((aOrbiterJ * 10927459251773273143U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 17229017825587322715U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 1137574712801062932U) ^ aOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3645832160939819415U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 2401991077004083378U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 1332473247826139292U;
            aOrbiterC = RotL64((aOrbiterC * 15029831858261506447U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 11730946340796899885U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 15319163439700390962U;
            aOrbiterE = RotL64((aOrbiterE * 1349242001887975499U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 4744141870145159917U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 6067132201862688684U) ^ RotL64(aNonceWordC, 61U);
            aOrbiterG = RotL64((aOrbiterG * 6046100687757836027U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 14991509179286371800U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 4342608825699398682U) ^ aOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10240526103933275875U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 3727521409410742075U) + RotL64(aNonceWordE, 27U);
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 3302027219498304367U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12153634588200479559U), 57U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterG, 41U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + (RotL64(aOrbiterK, 21U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterE, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aIngress, 57U) + aOrbiterE) + RotL64(aOrbiterK, 13U));
            aWandererG = aWandererG + ((((RotL64(aCross, 39U) + RotL64(aOrbiterG, 21U)) + aOrbiterC) + RotL64(aCarry, 57U)) + aWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterE, 37U)) + aOrbiterC);
            aWandererD = aWandererD + (((RotL64(aScatter, 26U) + RotL64(aOrbiterJ, 57U)) + aOrbiterH) + aWandererUpdateSaltF[((aIndex + 4U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 3U) + aOrbiterG) + RotL64(aOrbiterF, 51U)) + RotL64(aNonceWordB, 35U));
            aWandererF = aWandererF + (((RotL64(aIngress, 19U) + RotL64(aOrbiterH, 6U)) + aOrbiterF) + RotL64(aCarry, 41U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterC, 27U)) + aOrbiterJ) + RotL64(aNonceWordA, 52U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 40U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + RotL64(aWandererA, 57U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 3U) ^ RotL64(aNonceWordB, 57U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 21354U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19445U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 11U) ^ RotL64(aNonceWordE, 19U)) ^ RotL64(aNonceWordG, 42U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18306U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneC[((aIndex + 22733U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aPrevious, 24U)) + (RotL64(aCross, 11U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererC + RotL64(aScatter, 35U)) + 15904465836916519864U;
            aOrbiterB = (((aWandererK + RotL64(aCross, 6U)) + RotL64(aCarry, 37U)) + 17725629806317789307U) + RotL64(aNonceWordE, 47U);
            aOrbiterH = (aWandererF + RotL64(aPrevious, 51U)) + 13794170125914914828U;
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 57U)) + RotL64(aCarry, 13U)) + 2149055907476874332U;
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 29U)) + 5342047776745074649U) + aOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = (((aWandererA + RotL64(aPrevious, 13U)) + RotL64(aCarry, 51U)) + 8268148484060546838U) + RotL64(aNonceWordD, 39U);
            aOrbiterG = ((aWandererG + RotL64(aCross, 41U)) + 10821151364028563719U) + aOrbiterAssignSaltD[((aIndex + 20U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 4294213820894407378U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 10884726101307943090U;
            aOrbiterH = RotL64((aOrbiterH * 1116128870387229159U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 16432210042202444824U) + aOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 15196602644336228055U;
            aOrbiterB = RotL64((aOrbiterB * 12680438355124070237U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 14117787670220328165U) + RotL64(aNonceWordG, 10U);
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 219833877949480215U;
            aOrbiterI = RotL64((aOrbiterI * 10736293047771972173U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 3326396981881473962U) + RotL64(aNonceWordC, 23U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 14918513066311426279U;
            aOrbiterJ = RotL64((aOrbiterJ * 14269763278564574663U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 11795234681370163206U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 3068267285352664813U) ^ aOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15746255933920904619U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 245233356957999496U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 709926406353796673U;
            aOrbiterA = RotL64((aOrbiterA * 13627039596842073595U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 5378105439430271038U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 10114555061122044430U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5351295043424885549U), 27U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterA, 19U);
            aIngress = aIngress + (RotL64(aOrbiterB, 53U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterH, 11U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterJ, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 57U) + aOrbiterG) + RotL64(aOrbiterA, 60U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 19U) + aOrbiterJ) + RotL64(aOrbiterH, 27U)) + RotL64(aCarry, 21U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterB, 47U)) + aOrbiterJ) + aWandererUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 41U) + aOrbiterI) + RotL64(aOrbiterJ, 19U)) + RotL64(aNonceWordH, 45U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 11U) + aOrbiterB) + RotL64(aOrbiterI, 5U)) + RotL64(aNonceWordF, 51U));
            aWandererI = aWandererI + ((((RotL64(aIngress, 4U) + RotL64(aOrbiterA, 39U)) + aOrbiterH) + RotL64(aCarry, 53U)) + aWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterJ, 53U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 34U));
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererC);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + RotL64(aWandererJ, 51U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 35U) ^ RotL64(aNonceWordB, 53U)) ^ RotL64(aNonceWordG, 43U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 31046U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneB[((aIndex + 29408U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 5U) ^ RotL64(aNonceWordD, 50U)) ^ RotL64(aNonceWordH, 27U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 32026U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 26487U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 43U)) + (RotL64(aCross, 57U) ^ RotL64(aIngress, 6U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 50U)) + 7948891781097675369U) + RotL64(aNonceWordF, 49U);
            aOrbiterF = ((aWandererG + RotL64(aIngress, 43U)) + RotL64(aCarry, 29U)) + 13928362874228230226U;
            aOrbiterJ = (aWandererJ + RotL64(aCross, 37U)) + 10776180542602258926U;
            aOrbiterD = ((((aWandererA + RotL64(aScatter, 27U)) + RotL64(aCarry, 43U)) + 5735115172149470447U) + aOrbiterAssignSaltA[(((31U - aIndex) + 18U)) & S_SALT1]) + RotL64(aNonceWordG, 27U);
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 11U)) + RotL64(aCarry, 11U)) + 5353591822981766987U;
            aOrbiterE = (aWandererB + RotL64(aIngress, 19U)) + 562301708107268570U;
            aOrbiterH = ((aWandererD + RotL64(aCross, 5U)) + 10467810247578364868U) + aOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 14541630141152308564U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 2350076897065139429U) ^ aOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12222554362482034393U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 17519109078651162228U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 6061035173339902910U) ^ aOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10021905773432907835U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 15654836633731000065U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 13723521735153718904U;
            aOrbiterF = RotL64((aOrbiterF * 14459516479283070563U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 2849680038315532197U) + aOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 17336102435576647923U;
            aOrbiterB = RotL64((aOrbiterB * 10984689101753586739U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 7671010488872356142U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 11485114338165600777U;
            aOrbiterI = RotL64((aOrbiterI * 4162584865462407791U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 8759060657343458985U) + RotL64(aNonceWordE, 10U);
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 11009137869375286581U;
            aOrbiterD = RotL64((aOrbiterD * 8741417343929809115U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 15792999392743144135U) + RotL64(aNonceWordD, 41U);
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 6180808423175992479U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13681230339693676907U), 47U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterB, 41U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 35U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 5U));
            aIngress = aIngress + RotL64(aOrbiterJ, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterF, 3U)) + aOrbiterH) + RotL64(aNonceWordB, 31U));
            aWandererG = aWandererG + (((RotL64(aScatter, 37U) + RotL64(aOrbiterJ, 35U)) + aOrbiterD) + RotL64(aNonceWordA, 39U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterI, 47U)) + aOrbiterH);
            aWandererB = aWandererB + (((RotL64(aPrevious, 12U) + aOrbiterE) + RotL64(aOrbiterB, 24U)) + RotL64(aCarry, 35U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterD, 53U)) + aOrbiterB);
            aWandererE = aWandererE + ((((RotL64(aIngress, 53U) + aOrbiterI) + RotL64(aOrbiterF, 41U)) + RotL64(aCarry, 47U)) + aWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 43U) + aOrbiterD) + RotL64(aOrbiterE, 13U)) + aWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 48U));
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererD, 43U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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

void TwistExpander_Archery_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xE630889918C61C17ULL + 0xB4D7BA8ECCC598DFULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x9554DD94B2D6E901ULL + 0xDBBDEF49B233521BULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xBFFB903EEB1E3DE3ULL + 0xFC00976CA2FFE6B1ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xAE43EF5F464FC8C3ULL + 0xAFEBA037047BE973ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xF2E1A8C49008A5F9ULL + 0xF0951895815CA78CULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xF2E2E7CB5A0FCD5DULL + 0x85AF239129D28B61ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xC7F0B93AFED0B7D1ULL + 0xC838BD8595DEF12BULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x848D5408FBF07143ULL + 0x831667DC87F881FAULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 19U) ^ RotL64(aNonceWordA, 51U));
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 2945U)) & S_BLOCK1], 30U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 2048U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 13U) ^ RotL64(aNonceWordD, 39U)) ^ RotL64(aNonceWordG, 21U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 7542U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 2595U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 51U) + RotL64(aPrevious, 5U)) + (RotL64(aCarry, 37U) ^ RotL64(aIngress, 22U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (aWandererD + RotL64(aCross, 5U)) + 898812731947995389U;
            aOrbiterK = (((aWandererB + RotL64(aScatter, 41U)) + RotL64(aCarry, 21U)) + 8677347622525527167U) + aOrbiterAssignSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = (((aWandererJ + RotL64(aPrevious, 48U)) + RotL64(aCarry, 5U)) + 770321564027567654U) + RotL64(aNonceWordH, 26U);
            aOrbiterG = (aWandererK + RotL64(aIngress, 35U)) + 11020474858081526395U;
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 21U)) + 17289793580414993470U) + RotL64(aNonceWordE, 45U);
            aOrbiterI = ((aWandererG + RotL64(aCross, 29U)) + RotL64(aCarry, 53U)) + 10111912559295118444U;
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 11U)) + 8083622125544542011U) + aOrbiterAssignSaltB[((aIndex + 18U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 7149858558922988240U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 5919683821379905699U;
            aOrbiterD = RotL64((aOrbiterD * 16705119888884231567U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 6860902846079238714U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 15083517836867542075U;
            aOrbiterF = RotL64((aOrbiterF * 4686657139237578325U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 14852868368708376381U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 9860233289028878323U;
            aOrbiterI = RotL64((aOrbiterI * 13418143547952204667U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 772406119079116272U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 7971141501337627589U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10168120622976358617U), 37U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 8478568022896691911U) + RotL64(aNonceWordB, 31U);
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 4027604850785607101U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4826627523578901467U), 57U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterA) + 17199331557841535430U) + aOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1]) + RotL64(aNonceWordF, 7U);
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 7515957656979776361U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5468950152869656599U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 17138249294921502391U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 16236812863923234668U;
            aOrbiterK = RotL64((aOrbiterK * 2925542836624164807U), 43U);
            //
            aIngress = RotL64(aOrbiterA, 19U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 43U));
            aIngress = aIngress + (RotL64(aOrbiterK, 4U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterJ, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterF, 29U));
            aWandererI = aWandererI + ((((RotL64(aPrevious, 53U) + RotL64(aOrbiterD, 41U)) + aOrbiterA) + RotL64(aCarry, 51U)) + aWandererUpdateSaltE[((aIndex + 26U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 37U) + aOrbiterJ) + RotL64(aOrbiterK, 11U)) + aWandererUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 5U) + RotL64(aOrbiterG, 58U)) + aOrbiterI) + RotL64(aCarry, 35U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 28U) + RotL64(aOrbiterA, 51U)) + aOrbiterJ) + RotL64(aNonceWordA, 53U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 19U) + aOrbiterF) + RotL64(aOrbiterK, 35U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 13U) + aOrbiterG) + RotL64(aOrbiterD, 19U)) + RotL64(aNonceWordD, 19U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 42U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + RotL64(aWandererC, 13U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 57U) ^ RotL64(aNonceWordE, 37U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 8325U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 15776U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 23U) ^ RotL64(aNonceWordH, 38U));
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 10678U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneB[((aIndex + 10134U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCross, 28U)) + (RotL64(aPrevious, 41U) + RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 57U)) + 16016931609704150191U) + aOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = ((aWandererD + RotL64(aIngress, 35U)) + RotL64(aCarry, 51U)) + 14511433515861302636U;
            aOrbiterA = ((aWandererH + RotL64(aCross, 3U)) + RotL64(aCarry, 23U)) + 11691237442613269593U;
            aOrbiterI = ((aWandererG + RotL64(aPrevious, 41U)) + 16383220587320484649U) + aOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = ((aWandererI + RotL64(aScatter, 47U)) + RotL64(aCarry, 5U)) + 14293015313458219868U;
            aOrbiterF = ((aWandererB + RotL64(aIngress, 20U)) + 4407695248205526670U) + RotL64(aNonceWordD, 25U);
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 13U)) + 1158323195324398372U) + RotL64(aNonceWordC, 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 6577683409653864555U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 171080079472863843U) ^ RotL64(aNonceWordF, 48U);
            aOrbiterA = RotL64((aOrbiterA * 3063978974927752653U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 5766333425872228205U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 16173508656917582960U) ^ aOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12187968015372936695U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 11781450063402219202U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 13033139686637576694U) ^ aOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4331137994135472025U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 4006310759400926020U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 13156817947481574467U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 563189239835001483U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 12791290558893516411U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 989729955679243234U;
            aOrbiterB = RotL64((aOrbiterB * 8757228712495095017U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 838379839663022790U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 2830743864262313606U) ^ RotL64(aNonceWordB, 47U);
            aOrbiterF = RotL64((aOrbiterF * 10173947177104802797U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 2146646527331684652U) + aOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 4629168181742174906U;
            aOrbiterE = RotL64((aOrbiterE * 9046124907945045131U), 11U);
            //
            aIngress = RotL64(aOrbiterI, 53U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 13U));
            aIngress = aIngress + (RotL64(aOrbiterB, 27U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterC, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aScatter, 5U) + RotL64(aOrbiterG, 47U)) + aOrbiterC) + RotL64(aCarry, 41U)) + aWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 35U) + aOrbiterG) + RotL64(aOrbiterI, 3U)) + aWandererUpdateSaltD[((aIndex + 16U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 11U) + RotL64(aOrbiterI, 56U)) + aOrbiterB) + RotL64(aNonceWordE, 23U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 58U) + RotL64(aOrbiterE, 41U)) + aOrbiterG) + RotL64(aNonceWordG, 45U));
            aWandererG = aWandererG + ((RotL64(aScatter, 43U) + RotL64(aOrbiterF, 11U)) + aOrbiterA);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterC, 21U)) + aOrbiterI);
            aWandererI = aWandererI + (((RotL64(aIngress, 27U) + RotL64(aOrbiterE, 35U)) + aOrbiterF) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 53U));
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererG, 60U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 38U) ^ RotL64(aNonceWordD, 51U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 16669U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((aIndex + 17438U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 23U) ^ RotL64(aNonceWordB, 47U));
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 16424U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneC[((aIndex + 23834U)) & S_BLOCK1], 34U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aIngress, 11U)) ^ (RotL64(aPrevious, 58U) ^ RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (((aWandererB + RotL64(aPrevious, 5U)) + RotL64(aCarry, 35U)) + 17019646486641172469U) + aOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = (((aWandererG + RotL64(aIngress, 21U)) + RotL64(aCarry, 5U)) + 12276141179299971572U) + RotL64(aNonceWordA, 39U);
            aOrbiterC = (aWandererD + RotL64(aCross, 13U)) + 3617241694029841555U;
            aOrbiterB = (((aWandererJ + RotL64(aScatter, 51U)) + RotL64(aCarry, 21U)) + 6967963401259371737U) + aOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = (aWandererK + RotL64(aIngress, 58U)) + 6340709284279891017U;
            aOrbiterK = ((aWandererA + RotL64(aCross, 27U)) + 456065368903896482U) + RotL64(aNonceWordG, 60U);
            aOrbiterE = (aWandererC + RotL64(aPrevious, 35U)) + 17686765719908116203U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 1322045955429785736U) + aOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 5163772703302372887U;
            aOrbiterC = RotL64((aOrbiterC * 3193272189179082313U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 13268431135020363252U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 6538789950366849332U) ^ RotL64(aNonceWordC, 17U);
            aOrbiterA = RotL64((aOrbiterA * 5352960308459065837U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 10390344544314544893U) + RotL64(aNonceWordH, 37U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 5087084271300584267U;
            aOrbiterJ = RotL64((aOrbiterJ * 15149302947570776165U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 13423071121590981727U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 18324443012024134729U;
            aOrbiterB = RotL64((aOrbiterB * 15814349432207734533U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 4129091815978464507U) + aOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 17024797553831962245U) ^ aOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3137753479364378175U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 6501545108779991661U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 11930037791867597447U;
            aOrbiterK = RotL64((aOrbiterK * 4904739567549702851U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 4667298703308315851U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 6315980380900062127U;
            aOrbiterE = RotL64((aOrbiterE * 12080555704907924637U), 19U);
            //
            aIngress = RotL64(aOrbiterB, 5U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterH, 19U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + RotL64(aOrbiterK, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterC, 21U)) + aOrbiterJ) + aWandererUpdateSaltB[((aIndex + 6U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterC, 13U)) + aOrbiterE) + aWandererUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 3U) + RotL64(aOrbiterB, 53U)) + aOrbiterJ) + RotL64(aNonceWordD, 57U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 60U) + RotL64(aOrbiterE, 27U)) + aOrbiterK);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterA, 60U)) + aOrbiterC) + RotL64(aCarry, 19U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 47U) + aOrbiterJ) + RotL64(aOrbiterH, 43U)) + RotL64(aNonceWordF, 23U));
            aWandererD = aWandererD + (((RotL64(aIngress, 53U) + RotL64(aOrbiterH, 35U)) + aOrbiterB) + RotL64(aCarry, 37U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 20U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 53U));
            aCarry = aCarry + RotL64(aWandererC, 13U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 43U) ^ RotL64(aNonceWordC, 19U)) ^ RotL64(aNonceWordH, 60U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 29993U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27829U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 13U) ^ RotL64(aNonceWordB, 37U)) ^ RotL64(aNonceWordA, 47U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30331U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 26845U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 11U) + RotL64(aCross, 43U)) ^ (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 24U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (aWandererK + RotL64(aPrevious, 11U)) + 17454559218352016650U;
            aOrbiterG = (aWandererE + RotL64(aScatter, 20U)) + 8005709669325164803U;
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 27U)) + 13393741948412816357U;
            aOrbiterA = ((((aWandererB + RotL64(aCross, 35U)) + RotL64(aCarry, 57U)) + 3665865624348875553U) + aOrbiterAssignSaltB[((aIndex + 22U)) & S_SALT1]) + RotL64(aNonceWordE, 9U);
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 51U)) + RotL64(aCarry, 37U)) + 8334142570031883436U;
            aOrbiterF = (aWandererI + RotL64(aScatter, 57U)) + 17226066128706139657U;
            aOrbiterH = ((((aWandererF + RotL64(aIngress, 41U)) + RotL64(aCarry, 21U)) + 3319093033121522613U) + aOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1]) + RotL64(aNonceWordD, 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 6657535603401588798U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 5469746182326331147U;
            aOrbiterJ = RotL64((aOrbiterJ * 11315450342347794329U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 17846791786050221418U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 15939541003714896288U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1400351482213119809U), 11U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterB) + 12076763190461077406U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]) + RotL64(aNonceWordA, 59U);
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 3594038213596405284U;
            aOrbiterG = RotL64((aOrbiterG * 10244002692575821495U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 8301291631324464622U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 8460406137668390582U;
            aOrbiterD = RotL64((aOrbiterD * 9117147929757711595U), 29U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterH) + 7612394867020871200U) + aOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1]) + RotL64(aNonceWordG, 50U);
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 8525076134853103975U;
            aOrbiterB = RotL64((aOrbiterB * 5790440201072204659U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 11929899088215090379U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 7119509166360685726U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1662341427992528823U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 5081078459225240607U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 17149991983909906705U;
            aOrbiterH = RotL64((aOrbiterH * 950223374568067343U), 47U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterG, 27U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 35U));
            aIngress = aIngress + (RotL64(aOrbiterD, 51U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterF, 44U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 20U) + RotL64(aOrbiterH, 51U)) + aOrbiterF);
            aWandererI = aWandererI + (((RotL64(aPrevious, 3U) + aOrbiterF) + RotL64(aOrbiterB, 27U)) + RotL64(aCarry, 27U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 11U) + aOrbiterH) + RotL64(aOrbiterB, 44U)) + RotL64(aNonceWordH, 37U));
            aWandererE = aWandererE + ((((RotL64(aScatter, 29U) + RotL64(aOrbiterJ, 21U)) + aOrbiterA) + RotL64(aCarry, 41U)) + aWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 35U) + aOrbiterB) + RotL64(aOrbiterG, 57U)) + aWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 47U) + RotL64(aOrbiterF, 5U)) + aOrbiterD);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 53U) + aOrbiterB) + RotL64(aOrbiterJ, 11U)) + RotL64(aNonceWordF, 3U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 39U));
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 21U));
            aCarry = aCarry + RotL64(aWandererF, 30U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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

void TwistExpander_Archery_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xC7F54CEF1CAA7AD1ULL + 0xEA216A10FD028EF3ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xB01DEDCD3059AE05ULL + 0xAFCAFA5FD82ACCACULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xC422E4D06857E229ULL + 0xA87D4EACE61830E1ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x94AA4E696B3FD349ULL + 0x85325586D555436BULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xE694705156B52CBBULL + 0x9CB8433250632158ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xF5B374F8A1040DFDULL + 0xCCB5CB71EBDC9AEFULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xC9C4AB5CE9103ED7ULL + 0xA19AD738D8549C00ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xE1AF8337E106E40DULL + 0x8D2D104DFD801907ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 51U) ^ RotL64(aNonceWordF, 27U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 1689U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 6260U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 4U) ^ RotL64(aNonceWordE, 47U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 3302U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((aIndex + 2609U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 11U)) + (RotL64(aCross, 57U) ^ RotL64(aIngress, 38U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (aWandererI + RotL64(aScatter, 57U)) + 11274974230580265396U;
            aOrbiterJ = (aWandererA + RotL64(aCross, 47U)) + 16658438747342741547U;
            aOrbiterC = (aWandererH + RotL64(aPrevious, 29U)) + 16612986966106053844U;
            aOrbiterD = ((aWandererD + RotL64(aIngress, 51U)) + 9329502236843231290U) + aOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = (aWandererG + RotL64(aCross, 14U)) + 14088261356708344656U;
            aOrbiterA = ((aWandererB + RotL64(aScatter, 39U)) + RotL64(aCarry, 5U)) + 13692608802007789581U;
            aOrbiterG = (aWandererE + RotL64(aPrevious, 35U)) + 6824473946645682398U;
            aOrbiterH = (((aWandererK + RotL64(aIngress, 43U)) + RotL64(aCarry, 21U)) + 2072915876348570040U) + RotL64(aNonceWordH, 56U);
            aOrbiterE = (((aWandererF + RotL64(aCross, 53U)) + 7420507753044460759U) + aOrbiterAssignSaltE[(((31U - aIndex) + 24U)) & S_SALT1]) + RotL64(aNonceWordB, 23U);
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 27U)) + RotL64(aCarry, 53U)) + 4677557318688502593U;
            aOrbiterF = (aWandererJ + RotL64(aIngress, 6U)) + 15081678577055628459U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 7026792817486507482U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 14871665922943969918U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 694073180313083145U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 6807734532159292872U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 17882797335141303280U) ^ aOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15439872930381050291U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 9233542707022629190U) + RotL64(aNonceWordF, 13U);
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 1205501586581350876U;
            aOrbiterK = RotL64((aOrbiterK * 2596053290311090589U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 10878718669747466677U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 8066049063548639241U;
            aOrbiterD = RotL64((aOrbiterD * 3031382633089381605U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 861295180226875235U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 9134969787937288583U;
            aOrbiterG = RotL64((aOrbiterG * 7565008208670843555U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 6726642007159809594U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 8061661744643240470U;
            aOrbiterE = RotL64((aOrbiterE * 6703498926835391813U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 13541412083111962884U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 8617442758729315637U;
            aOrbiterF = RotL64((aOrbiterF * 15471862889276160953U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 16884403561131293362U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 9490680911678221233U;
            aOrbiterJ = RotL64((aOrbiterJ * 15988763830018001033U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 10486145044311386738U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterB) ^ 10200001044821063684U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]) ^ RotL64(aNonceWordA, 21U);
            aOrbiterI = RotL64((aOrbiterI * 16149790736141571017U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 6997073594007878034U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 13585783612009989767U;
            aOrbiterH = RotL64((aOrbiterH * 11425303157774550449U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 3847846040256340653U) + aOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 11274974230580265396U;
            aOrbiterB = RotL64((aOrbiterB * 13970270689108369205U), 57U);
            //
            aIngress = RotL64(aOrbiterH, 41U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 22U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 47U));
            aIngress = aIngress + (RotL64(aOrbiterG, 11U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterK, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aPrevious, 60U) + RotL64(aOrbiterG, 39U)) + aOrbiterC);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 23U) + aOrbiterJ) + RotL64(aOrbiterI, 13U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 41U) + RotL64(aOrbiterC, 21U)) + aOrbiterK);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 37U) + aOrbiterJ) + RotL64(aOrbiterE, 23U)) + aWandererUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 53U) + RotL64(aOrbiterC, 27U)) + aOrbiterF) + RotL64(aCarry, 23U)) + RotL64(aNonceWordG, 17U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 11U) + aOrbiterD) + RotL64(aOrbiterA, 34U)) + aWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 48U) + RotL64(aOrbiterE, 51U)) + aOrbiterB) + RotL64(aCarry, 43U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 5U) + aOrbiterK) + RotL64(aOrbiterA, 19U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 27U) + aOrbiterA) + RotL64(aOrbiterJ, 5U)) + RotL64(aNonceWordC, 27U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 3U) + aOrbiterG) + RotL64(aOrbiterJ, 54U));
            aWandererB = aWandererB + ((RotL64(aCross, 39U) + RotL64(aOrbiterH, 57U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + (RotL64(aWandererJ, 46U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererH);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 21U));
            aCarry = aCarry + RotL64(aWandererF, 41U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 3U) ^ RotL64(aNonceWordA, 18U)) ^ RotL64(aNonceWordB, 35U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 11606U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 11863U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 21U) ^ RotL64(aNonceWordD, 13U)) ^ RotL64(aNonceWordH, 47U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 10535U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 14196U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 22U) ^ RotL64(aCross, 53U)) + (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererH + RotL64(aIngress, 13U)) + 6069475454765660321U;
            aOrbiterJ = ((((aWandererC + RotL64(aCross, 39U)) + RotL64(aCarry, 3U)) + 11483704742497268068U) + aOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1]) + RotL64(aNonceWordC, 21U);
            aOrbiterA = ((aWandererF + RotL64(aScatter, 60U)) + RotL64(aCarry, 39U)) + 11055697447388986418U;
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 47U)) + RotL64(aCarry, 21U)) + 10897095046039997004U;
            aOrbiterD = (aWandererJ + RotL64(aIngress, 11U)) + 4731637118230457840U;
            aOrbiterK = (aWandererG + RotL64(aScatter, 23U)) + 13855839187084986751U;
            aOrbiterF = (aWandererB + RotL64(aPrevious, 41U)) + 5328208115460188239U;
            aOrbiterB = ((aWandererK + RotL64(aCross, 19U)) + 12479538544291412985U) + RotL64(aNonceWordG, 17U);
            aOrbiterH = ((aWandererD + RotL64(aIngress, 26U)) + 10740165998792608231U) + aOrbiterAssignSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = (aWandererE + RotL64(aPrevious, 37U)) + 6492798157284955373U;
            aOrbiterI = (aWandererA + RotL64(aScatter, 35U)) + 13056825957483891921U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 2068184064919194657U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 5656302738780746294U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16493021179127646345U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 11193756120230763294U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 17306750816837208999U;
            aOrbiterJ = RotL64((aOrbiterJ * 7949360041241439741U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 12952818800389361804U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 15380412293642628312U;
            aOrbiterD = RotL64((aOrbiterD * 2914662289178925547U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 7706090204767242996U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 14598802276412649570U) ^ aOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4821408736292041399U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 17819762117328075515U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 6481384240915075101U) ^ aOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4836701121865783029U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 754936290510338717U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 15510875946573720154U;
            aOrbiterE = RotL64((aOrbiterE * 2994718968852184303U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 9245381722813944586U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 2629847912019726214U) ^ RotL64(aNonceWordD, 3U);
            aOrbiterC = RotL64((aOrbiterC * 6718795794951106961U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 3909987749797113773U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 9277056074757335265U) ^ RotL64(aNonceWordF, 41U);
            aOrbiterK = RotL64((aOrbiterK * 11580847505996697115U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 12577180954515966707U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 9144513680789115458U;
            aOrbiterB = RotL64((aOrbiterB * 8880777678193004979U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 1544232962956974411U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 2658275904714859636U;
            aOrbiterG = RotL64((aOrbiterG * 1926083316365175327U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 5733515391293514025U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 6069475454765660321U;
            aOrbiterI = RotL64((aOrbiterI * 9627476106108146391U), 43U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterI, 5U);
            aIngress = aIngress + (RotL64(aOrbiterG, 51U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterC, 41U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 19U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 21U));
            aIngress = aIngress + RotL64(aOrbiterJ, 14U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aPrevious, 53U) + aOrbiterF) + RotL64(aOrbiterA, 37U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterE, 21U)) + aOrbiterJ);
            aWandererC = aWandererC + ((RotL64(aIngress, 11U) + aOrbiterK) + RotL64(aOrbiterD, 35U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 56U) + RotL64(aOrbiterK, 46U)) + aOrbiterI) + aWandererUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 27U) + RotL64(aOrbiterG, 23U)) + aOrbiterK) + RotL64(aCarry, 41U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterD, 27U)) + aOrbiterC);
            aWandererH = aWandererH + (((RotL64(aScatter, 47U) + RotL64(aOrbiterB, 11U)) + aOrbiterK) + RotL64(aNonceWordA, 50U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterJ, 43U)) + aOrbiterK);
            aWandererE = aWandererE + (((((RotL64(aScatter, 6U) + aOrbiterH) + RotL64(aOrbiterI, 50U)) + RotL64(aCarry, 23U)) + RotL64(aNonceWordE, 47U)) + aWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 41U) + aOrbiterG) + RotL64(aOrbiterI, 19U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterF, 53U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 14U));
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererJ);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 41U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 51U));
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererH, 27U);
            aCarry = aCarry + RotL64(aIngress, 18U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 57U) ^ RotL64(aNonceWordB, 27U)) ^ RotL64(aNonceWordE, 5U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 22679U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 16829U)) & S_BLOCK1], 42U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 27U) ^ RotL64(aNonceWordH, 5U)) ^ RotL64(aNonceWordF, 39U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 21554U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 22679U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 4U) ^ RotL64(aCarry, 23U)) + (RotL64(aPrevious, 35U) + RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (aWandererJ + RotL64(aCross, 19U)) + 5906639480605353429U;
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 6U)) + 5293518570213287605U) + RotL64(aNonceWordE, 29U);
            aOrbiterH = (aWandererE + RotL64(aScatter, 39U)) + 15383185501428521377U;
            aOrbiterE = (aWandererD + RotL64(aIngress, 27U)) + 15364072512743978902U;
            aOrbiterA = ((aWandererI + RotL64(aScatter, 29U)) + 4525473357144014271U) + aOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = (aWandererK + RotL64(aPrevious, 53U)) + 10400911938125603074U;
            aOrbiterG = ((aWandererH + RotL64(aCross, 41U)) + 16417506293824627550U) + aOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = (aWandererF + RotL64(aIngress, 23U)) + 2419329331753341815U;
            aOrbiterD = (((aWandererG + RotL64(aCross, 60U)) + RotL64(aCarry, 43U)) + 14929222427923332069U) + RotL64(aNonceWordG, 42U);
            aOrbiterI = ((aWandererB + RotL64(aScatter, 35U)) + RotL64(aCarry, 37U)) + 16771573504983922586U;
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 13U)) + RotL64(aCarry, 5U)) + 1863466450051787622U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 12895350137096692415U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 3700979086526298327U;
            aOrbiterH = RotL64((aOrbiterH * 10279730254867618193U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 1977099106211282426U) + RotL64(aNonceWordB, 11U);
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 6144698304096915742U;
            aOrbiterF = RotL64((aOrbiterF * 5039822990560519609U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 3858895556659724975U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 1283646340363435327U;
            aOrbiterJ = RotL64((aOrbiterJ * 11622421841377018069U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 6240532051889108891U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 757364889381634634U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 943852137901972945U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 5272945693977418174U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 6850528198786172283U;
            aOrbiterC = RotL64((aOrbiterC * 1966383079897679953U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 14431587733859573714U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 16124590257870999553U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7755796211433191143U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 14912695018110241411U) + RotL64(aNonceWordC, 19U);
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 11098623474413346520U;
            aOrbiterK = RotL64((aOrbiterK * 15167688959990872051U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 3484847683376368686U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 2295388097292719800U) ^ aOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1240808318176106909U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 923199510066894111U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 311875852510926196U;
            aOrbiterG = RotL64((aOrbiterG * 9797881750305289335U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 3543141837224843684U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 12889943043568922084U;
            aOrbiterD = RotL64((aOrbiterD * 8682278766727990427U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 6105656539077757510U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 5906639480605353429U;
            aOrbiterB = RotL64((aOrbiterB * 9555916235293954383U), 13U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterE, 29U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 11U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 41U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 50U));
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterA, 43U)) + aOrbiterJ) + RotL64(aNonceWordA, 41U));
            aWandererD = aWandererD + ((RotL64(aCross, 57U) + RotL64(aOrbiterF, 20U)) + aOrbiterE);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterB, 53U)) + aOrbiterG);
            aWandererC = aWandererC + ((RotL64(aScatter, 51U) + aOrbiterK) + RotL64(aOrbiterF, 29U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 60U) + aOrbiterE) + RotL64(aOrbiterC, 3U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 21U) + aOrbiterB) + RotL64(aOrbiterJ, 37U)) + RotL64(aCarry, 43U)) + RotL64(aNonceWordH, 61U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 19U) + aOrbiterA) + RotL64(aOrbiterH, 26U));
            aWandererH = aWandererH + (((RotL64(aIngress, 35U) + aOrbiterG) + RotL64(aOrbiterI, 39U)) + aWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 6U) + aOrbiterC) + RotL64(aOrbiterD, 47U));
            aWandererA = aWandererA + (((RotL64(aIngress, 29U) + RotL64(aOrbiterK, 57U)) + aOrbiterD) + RotL64(aCarry, 23U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 13U) + aOrbiterE) + RotL64(aOrbiterJ, 23U)) + aWandererUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 12U));
            aCarry = aCarry + (RotL64(aWandererD, 21U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererE);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + (RotL64(aWandererF, 37U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererI, 10U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 11U) ^ RotL64(aNonceWordF, 53U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 31039U)) & S_BLOCK1], 26U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28351U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 60U) ^ RotL64(aNonceWordC, 5U)) ^ RotL64(aNonceWordA, 29U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 31077U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((aIndex + 30620U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 54U) + RotL64(aCross, 21U)) + (RotL64(aCarry, 39U) ^ RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 37U)) + 17668251151213543491U) + RotL64(aNonceWordC, 9U);
            aOrbiterJ = (aWandererD + RotL64(aScatter, 19U)) + 16101602509895104517U;
            aOrbiterB = (((aWandererA + RotL64(aCross, 29U)) + 9083915270773304935U) + aOrbiterAssignSaltA[(((31U - aIndex) + 28U)) & S_SALT1]) + RotL64(aNonceWordB, 43U);
            aOrbiterH = ((aWandererG + RotL64(aIngress, 54U)) + RotL64(aCarry, 37U)) + 12810720730318214811U;
            aOrbiterD = (aWandererJ + RotL64(aScatter, 57U)) + 18113428002071925621U;
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 39U)) + RotL64(aCarry, 27U)) + 1582208899354109878U;
            aOrbiterC = (aWandererH + RotL64(aIngress, 41U)) + 4180688104819188154U;
            aOrbiterI = (((aWandererF + RotL64(aCross, 47U)) + RotL64(aCarry, 41U)) + 8954598189262820611U) + aOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = (aWandererE + RotL64(aIngress, 43U)) + 15360094153175355879U;
            aOrbiterF = (aWandererB + RotL64(aCross, 26U)) + 8383954114668216260U;
            aOrbiterK = (aWandererI + RotL64(aScatter, 3U)) + 15626783326234049197U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 10609978564404958066U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 17656516608997517984U;
            aOrbiterB = RotL64((aOrbiterB * 4590620354119899777U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 760077259110786536U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 3597338735888033063U;
            aOrbiterD = RotL64((aOrbiterD * 6548831472863517621U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 4431777844935985157U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 10710423172154671296U;
            aOrbiterA = RotL64((aOrbiterA * 16267496318491473315U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 10240882795242085185U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 7826053487019825891U;
            aOrbiterC = RotL64((aOrbiterC * 15053729937684375907U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 9418883403715727353U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 11507423614799075545U;
            aOrbiterI = RotL64((aOrbiterI * 16189463984557044693U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 11545217316421066655U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 617921402135485341U;
            aOrbiterG = RotL64((aOrbiterG * 8182920764965471653U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 14456933220749921009U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 7990243583564535387U;
            aOrbiterF = RotL64((aOrbiterF * 5994900368027985469U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 14023633125757654751U) + RotL64(aNonceWordG, 17U);
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 11319146808574958827U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13676159969338309307U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 14161653180846538446U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 17993503892528842342U) ^ aOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12184170842617942651U), 3U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterK) + 10449311783872638478U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]) + RotL64(aNonceWordE, 42U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 17210495321003036773U;
            aOrbiterJ = RotL64((aOrbiterJ * 17591257107603354151U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 14586515403314763393U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 17668251151213543491U;
            aOrbiterH = RotL64((aOrbiterH * 9367185933291003363U), 35U);
            //
            aIngress = RotL64(aOrbiterH, 40U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 27U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 5U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 51U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 53U));
            aIngress = aIngress + RotL64(aOrbiterJ, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterD, 3U)) + aOrbiterG);
            aWandererH = aWandererH + ((RotL64(aIngress, 39U) + aOrbiterB) + RotL64(aOrbiterD, 41U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 3U) + aOrbiterA) + RotL64(aOrbiterK, 58U)) + aWandererUpdateSaltA[((aIndex + 20U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 43U) + aOrbiterD) + RotL64(aOrbiterI, 13U)) + RotL64(aCarry, 47U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 53U) + aOrbiterG) + RotL64(aOrbiterI, 43U));
            aWandererE = aWandererE + (((RotL64(aCross, 26U) + aOrbiterC) + RotL64(aOrbiterH, 23U)) + aWandererUpdateSaltE[((aIndex + 6U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterI, 51U)) + aOrbiterC) + RotL64(aNonceWordH, 61U));
            aWandererC = aWandererC + (((RotL64(aIngress, 35U) + aOrbiterJ) + RotL64(aOrbiterG, 20U)) + RotL64(aCarry, 23U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterA, 47U)) + aOrbiterF) + RotL64(aNonceWordD, 59U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 24U) + RotL64(aOrbiterK, 35U)) + aOrbiterF);
            aWandererG = aWandererG ^ ((RotL64(aCross, 47U) + aOrbiterB) + RotL64(aOrbiterE, 37U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 56U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + RotL64(aWandererH, 52U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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

void TwistExpander_Archery_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xC8935B48A0A78041ULL + 0x9BE4F81FD9E56866ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x8F5ACDCEB9019239ULL + 0x8DA5FAB44E77FEDBULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xA8F6D602DE01A527ULL + 0xA01E95A48A71C913ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xF2F83F3A7ECF4541ULL + 0xEACFF25861D86D63ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xD43F3C3BD4EA7C33ULL + 0xE8089755EE82682FULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xCF3D21F54E1ECD6BULL + 0xA7232053FED9CB3CULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xCD6C4C9BE8E4F661ULL + 0xB759534B637CE548ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x9AE14CAFBA184D2FULL + 0xCCADBD6F1ABE0265ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 21U) ^ RotL64(aNonceWordF, 11U)) ^ RotL64(aNonceWordC, 3U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 3086U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneC[((aIndex + 2847U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 29U) ^ RotL64(aNonceWordA, 3U)) ^ RotL64(aNonceWordE, 57U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 4355U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneA[((aIndex + 2535U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aIngress, 6U)) ^ (RotL64(aPrevious, 35U) ^ RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (((aWandererJ + RotL64(aPrevious, 35U)) + RotL64(aCarry, 27U)) + 16160838483846078448U) + aOrbiterAssignSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterD = ((aWandererC + RotL64(aScatter, 6U)) + RotL64(aCarry, 35U)) + 15404960896190227946U;
            aOrbiterC = (aWandererA + RotL64(aIngress, 47U)) + 16904160594024977199U;
            aOrbiterK = ((aWandererE + RotL64(aCross, 43U)) + 17790460246821031802U) + aOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = (aWandererI + RotL64(aPrevious, 57U)) + 16395168254086971959U;
            aOrbiterI = ((aWandererF + RotL64(aCross, 39U)) + RotL64(aCarry, 51U)) + 7484373204039901786U;
            aOrbiterH = (aWandererD + RotL64(aScatter, 19U)) + 18026814691322913510U;
            aOrbiterF = ((aWandererG + RotL64(aIngress, 53U)) + 15244817793136966450U) + RotL64(aNonceWordE, 17U);
            aOrbiterE = ((aWandererK + RotL64(aScatter, 12U)) + 5795491730356335666U) + RotL64(aNonceWordG, 14U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterD) + 3163873518027801504U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]) + RotL64(aNonceWordD, 49U);
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 2690791759507349172U;
            aOrbiterC = RotL64((aOrbiterC * 16677948635136515083U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 17898067251167087906U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 8028010015006604239U) ^ aOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5601629670521300241U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 7304739457289910555U) + aOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 6476837815096530043U) ^ aOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16380545138701113267U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 14242499233467960602U) + RotL64(aNonceWordH, 31U);
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 17305645693017634630U;
            aOrbiterE = RotL64((aOrbiterE * 14442976693206929569U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 9772864059444171908U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 7897200728282156408U;
            aOrbiterB = RotL64((aOrbiterB * 816306719390807411U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 4890999319172950996U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 8165132649356094963U;
            aOrbiterK = RotL64((aOrbiterK * 17297706071263690189U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 9342923520083533265U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 7213639583505088067U;
            aOrbiterH = RotL64((aOrbiterH * 1349251979649428909U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 4079475132684197272U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 3350998022472827283U;
            aOrbiterD = RotL64((aOrbiterD * 948841791460066265U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 2479140576609216238U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 7703147534931674972U;
            aOrbiterG = RotL64((aOrbiterG * 11419116495223970801U), 35U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterK, 46U);
            aIngress = aIngress + (RotL64(aOrbiterG, 23U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterC, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aScatter, 47U) + aOrbiterK) + RotL64(aOrbiterF, 27U)) + aWandererUpdateSaltA[((aIndex + 6U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 18U) + aOrbiterH) + RotL64(aOrbiterB, 48U)) + RotL64(aNonceWordB, 21U));
            aWandererE = aWandererE + ((((RotL64(aCross, 35U) + RotL64(aOrbiterE, 11U)) + aOrbiterH) + RotL64(aCarry, 13U)) + RotL64(aNonceWordF, 57U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterH, 41U)) + aOrbiterD);
            aWandererC = aWandererC + (((RotL64(aScatter, 11U) + aOrbiterH) + RotL64(aOrbiterF, 53U)) + aWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterD, 60U)) + aOrbiterG);
            aWandererG = aWandererG + (((RotL64(aIngress, 52U) + aOrbiterC) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 27U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterC, 35U)) + aOrbiterG);
            aWandererD = aWandererD + ((RotL64(aScatter, 39U) + RotL64(aOrbiterH, 19U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererC, 28U) ^ aWandererD);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + (RotL64(aWandererI, 39U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererF, 47U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 12U) ^ RotL64(aNonceWordB, 39U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9818U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 9019U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 35U) ^ RotL64(aNonceWordG, 52U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 7088U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneB[((aIndex + 5578U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCarry, 19U)) ^ (RotL64(aCross, 5U) + RotL64(aPrevious, 52U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = ((aWandererA + RotL64(aScatter, 60U)) + RotL64(aCarry, 13U)) + 3621877681473089725U;
            aOrbiterD = ((((aWandererD + RotL64(aIngress, 19U)) + RotL64(aCarry, 3U)) + 4451752751536414717U) + aOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1]) + RotL64(aNonceWordD, 51U);
            aOrbiterB = (aWandererF + RotL64(aPrevious, 29U)) + 11371625415377772117U;
            aOrbiterJ = (aWandererC + RotL64(aCross, 5U)) + 6046792758881150619U;
            aOrbiterG = (aWandererJ + RotL64(aIngress, 53U)) + 8213166120394461682U;
            aOrbiterC = (((aWandererG + RotL64(aCross, 23U)) + RotL64(aCarry, 35U)) + 4343156661140422645U) + RotL64(aNonceWordA, 41U);
            aOrbiterI = (aWandererK + RotL64(aPrevious, 14U)) + 11105271483234947905U;
            aOrbiterF = (aWandererH + RotL64(aScatter, 47U)) + 348904609985341372U;
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 43U)) + 12924652822526858767U) + aOrbiterAssignSaltA[((aIndex + 28U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 7461211697358520287U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 16551553555297890558U;
            aOrbiterB = RotL64((aOrbiterB * 16432952324635746293U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 11908056404140782995U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 9147367258259948715U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10777628928376261667U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 8876461054692728610U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 10546855952702525404U;
            aOrbiterI = RotL64((aOrbiterI * 10071104785895309677U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 4748636139110443794U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 783046909529525098U;
            aOrbiterF = RotL64((aOrbiterF * 8969157702460927215U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 16683965945838696665U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 12385412690177109575U;
            aOrbiterH = RotL64((aOrbiterH * 10795062772707143187U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 8210546822184469023U) + RotL64(aNonceWordF, 39U);
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 13146493623236979963U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13199947810161148155U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 13857628148804187115U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 7241297989337473475U;
            aOrbiterJ = RotL64((aOrbiterJ * 16223448508809614229U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 773904571213804946U) + RotL64(aNonceWordG, 37U);
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 7660676598236419707U;
            aOrbiterC = RotL64((aOrbiterC * 14467390638468925567U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 16822672435156055469U) + aOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 6514707119190640433U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7097496727567460535U), 43U);
            //
            aIngress = RotL64(aOrbiterG, 29U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterF, 37U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterH, 51U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 46U));
            aIngress = aIngress + RotL64(aOrbiterJ, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aIngress, 29U) + RotL64(aOrbiterE, 47U)) + aOrbiterB);
            aWandererG = aWandererG ^ ((((RotL64(aCross, 39U) + aOrbiterJ) + RotL64(aOrbiterI, 43U)) + RotL64(aNonceWordC, 17U)) + aWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 43U) + aOrbiterC) + RotL64(aOrbiterG, 34U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 22U) + aOrbiterB) + RotL64(aOrbiterC, 27U));
            aWandererA = aWandererA + (((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterD, 3U)) + RotL64(aCarry, 51U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterC, 11U)) + aOrbiterE);
            aWandererI = aWandererI + (((RotL64(aScatter, 5U) + RotL64(aOrbiterG, 51U)) + aOrbiterF) + aWandererUpdateSaltB[((aIndex + 8U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 60U) + aOrbiterH) + RotL64(aOrbiterJ, 38U));
            aWandererF = aWandererF + ((((RotL64(aScatter, 51U) + aOrbiterH) + RotL64(aOrbiterB, 19U)) + RotL64(aCarry, 27U)) + RotL64(aNonceWordH, 18U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererI);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 60U));
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererC, 43U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 39U) ^ RotL64(aNonceWordA, 29U)) ^ RotL64(aNonceWordH, 5U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 11497U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16373U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 13U) ^ RotL64(aNonceWordB, 46U)) ^ RotL64(aNonceWordE, 37U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 15589U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 12021U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 20U) + RotL64(aCross, 53U)) ^ (RotL64(aCarry, 5U) + RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 39U)) + 9774364261626083532U) + RotL64(aNonceWordB, 9U);
            aOrbiterD = ((aWandererI + RotL64(aCross, 23U)) + RotL64(aCarry, 51U)) + 18059001521926116420U;
            aOrbiterB = ((aWandererE + RotL64(aIngress, 53U)) + RotL64(aCarry, 39U)) + 10615626210406381148U;
            aOrbiterC = ((aWandererA + RotL64(aScatter, 11U)) + 10536484278007898620U) + aOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 4U)) + RotL64(aCarry, 27U)) + 13320663045139972700U;
            aOrbiterE = (aWandererF + RotL64(aCross, 43U)) + 17127001787268166583U;
            aOrbiterH = (aWandererG + RotL64(aIngress, 27U)) + 16742574590844166551U;
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 35U)) + 8347719720758228053U) + RotL64(aNonceWordF, 59U);
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 60U)) + 13502468705946051986U) + aOrbiterAssignSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 3512687886188904904U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 495660316165795934U;
            aOrbiterB = RotL64((aOrbiterB * 6724596801190194913U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 5092722552034477356U) + RotL64(aNonceWordD, 50U);
            aOrbiterF = (((aOrbiterF ^ aOrbiterC) ^ 15641128019608284015U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]) ^ RotL64(aNonceWordC, 23U);
            aOrbiterF = RotL64((aOrbiterF * 3621036395703527059U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 15421873776811085458U) + aOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 17978775513204574125U;
            aOrbiterC = RotL64((aOrbiterC * 18359600395119440183U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 16617179197537669849U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 1931805387534012528U;
            aOrbiterD = RotL64((aOrbiterD * 3400139345857733775U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 9544923119559308431U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 12930999400470173353U;
            aOrbiterJ = RotL64((aOrbiterJ * 16791006919271490005U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 13673733276226249890U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 2032263473309124738U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3088728329261360607U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 14868502349358414206U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 10116495537187552321U;
            aOrbiterH = RotL64((aOrbiterH * 1380512121796709469U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 5341113995358179244U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 8415417980279705731U;
            aOrbiterI = RotL64((aOrbiterI * 8521501372683793821U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 2462819265072352463U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 7657062767608441931U;
            aOrbiterG = RotL64((aOrbiterG * 15554638801273540163U), 57U);
            //
            aIngress = RotL64(aOrbiterF, 28U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterC, 47U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 11U));
            aIngress = aIngress + RotL64(aOrbiterI, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 11U) + aOrbiterJ) + RotL64(aOrbiterF, 53U));
            aWandererF = aWandererF + (((RotL64(aScatter, 60U) + aOrbiterC) + RotL64(aOrbiterB, 39U)) + RotL64(aCarry, 57U));
            aWandererI = aWandererI ^ ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterI, 5U)) + aOrbiterJ) + RotL64(aNonceWordG, 61U)) + aWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aIngress, 43U) + aOrbiterF) + RotL64(aOrbiterC, 35U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterD, 30U)) + aOrbiterJ);
            aWandererB = aWandererB + (((RotL64(aCross, 4U) + RotL64(aOrbiterE, 57U)) + aOrbiterH) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 53U) + aOrbiterG) + RotL64(aOrbiterH, 23U)) + aWandererUpdateSaltD[((aIndex + 8U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 19U) + RotL64(aOrbiterE, 47U)) + aOrbiterG);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 27U) + aOrbiterI) + RotL64(aOrbiterC, 18U)) + RotL64(aNonceWordA, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererK);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 22U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererI, 13U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordA, 27U) ^ RotL64(aNonceWordG, 58U)) ^ RotL64(aNonceWordF, 19U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 19457U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17387U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 57U) ^ RotL64(aNonceWordE, 21U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20450U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneD[((aIndex + 16416U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 57U)) + (RotL64(aIngress, 40U) ^ RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (aWandererJ + RotL64(aScatter, 60U)) + 18191288703716505885U;
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 37U)) + RotL64(aCarry, 57U)) + 9824014524910417136U;
            aOrbiterG = (aWandererH + RotL64(aCross, 47U)) + 11953012029254917548U;
            aOrbiterD = ((aWandererC + RotL64(aIngress, 3U)) + RotL64(aCarry, 5U)) + 6297568011027199089U;
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 21U)) + 2576999400457367975U) + aOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = (aWandererE + RotL64(aCross, 51U)) + 13176139160575558254U;
            aOrbiterH = ((aWandererG + RotL64(aIngress, 27U)) + 9978408174563621810U) + RotL64(aNonceWordH, 22U);
            aOrbiterB = (((aWandererF + RotL64(aScatter, 43U)) + RotL64(aCarry, 47U)) + 16765834875061607142U) + aOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 12U)) + 16534507305459121344U) + RotL64(aNonceWordE, 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 3114710944346151807U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 10240517868726718592U;
            aOrbiterG = RotL64((aOrbiterG * 4645691562915606463U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 10721450637990777883U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 16689590768796583952U;
            aOrbiterE = RotL64((aOrbiterE * 3046344179729901637U), 43U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterE) + 2427422768928450209U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1]) + RotL64(aNonceWordB, 49U);
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 13495584061816457831U;
            aOrbiterH = RotL64((aOrbiterH * 6670984773768885119U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 7058636403765106682U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 9897341853944713767U;
            aOrbiterC = RotL64((aOrbiterC * 14286816859999869231U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 17749559755733386064U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 12515645083926326659U;
            aOrbiterD = RotL64((aOrbiterD * 6582878478865838245U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 2625692458813609962U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 10596240255026143019U;
            aOrbiterA = RotL64((aOrbiterA * 11605800195771080135U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 12374290338067865540U) + aOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 1507386663796330249U;
            aOrbiterB = RotL64((aOrbiterB * 1210241080424446087U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 9288099549484146726U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 15159312464747000702U;
            aOrbiterF = RotL64((aOrbiterF * 500055502081347757U), 35U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterF) + 14998608679505446229U) + aOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1]) + RotL64(aNonceWordA, 45U);
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 17625038109437732009U;
            aOrbiterI = RotL64((aOrbiterI * 14785862243019841689U), 47U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterE, 5U);
            aIngress = aIngress + (RotL64(aOrbiterF, 42U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 11U));
            aIngress = aIngress + RotL64(aOrbiterG, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 58U) + aOrbiterC) + RotL64(aOrbiterF, 57U)) + RotL64(aNonceWordD, 3U));
            aWandererH = aWandererH + (((RotL64(aIngress, 41U) + aOrbiterI) + RotL64(aOrbiterD, 30U)) + aWandererUpdateSaltF[((aIndex + 6U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterC, 53U)) + aOrbiterA);
            aWandererK = aWandererK + (((((RotL64(aScatter, 13U) + RotL64(aOrbiterH, 37U)) + aOrbiterA) + RotL64(aCarry, 39U)) + RotL64(aNonceWordF, 19U)) + aWandererUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterH, 5U)) + aOrbiterB);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 47U) + RotL64(aOrbiterI, 43U)) + aOrbiterA) + RotL64(aCarry, 51U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 5U) + aOrbiterE) + RotL64(aOrbiterG, 19U));
            aWandererB = aWandererB + ((RotL64(aScatter, 53U) + aOrbiterC) + RotL64(aOrbiterG, 10U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 28U) + aOrbiterA) + RotL64(aOrbiterG, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 21U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 18U));
            aCarry = aCarry + RotL64(aWandererE, 5U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 60U) ^ RotL64(aNonceWordF, 19U)) ^ RotL64(aNonceWordE, 5U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 26729U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneA[((aIndex + 22742U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 21U) ^ RotL64(aNonceWordG, 3U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 22071U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25465U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 3U) + RotL64(aCross, 50U)) ^ (RotL64(aCarry, 23U) + RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererF + RotL64(aCross, 56U)) + 3248574644570178787U) + aOrbiterAssignSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 19U)) + RotL64(aCarry, 53U)) + 4506961512959200024U;
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 51U)) + RotL64(aCarry, 27U)) + 8423739774540738590U;
            aOrbiterG = (aWandererG + RotL64(aScatter, 27U)) + 6593975869641735337U;
            aOrbiterC = (aWandererE + RotL64(aPrevious, 3U)) + 16441716090557369103U;
            aOrbiterJ = ((aWandererK + RotL64(aCross, 13U)) + RotL64(aCarry, 11U)) + 7936601450453207914U;
            aOrbiterE = (((aWandererB + RotL64(aScatter, 34U)) + 13333752583560167065U) + aOrbiterAssignSaltF[((aIndex + 18U)) & S_SALT1]) + RotL64(aNonceWordG, 27U);
            aOrbiterF = (aWandererI + RotL64(aIngress, 47U)) + 8013703284795432973U;
            aOrbiterB = ((aWandererH + RotL64(aCross, 23U)) + 2349852779887439236U) + RotL64(aNonceWordD, 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 5318539364763284138U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 11450957608502944376U;
            aOrbiterD = RotL64((aOrbiterD * 1957880366707810635U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 9058992558327552687U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 632095686920230926U;
            aOrbiterJ = RotL64((aOrbiterJ * 12460364388358520799U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 14734218428913777098U) + aOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 16344357661370784442U;
            aOrbiterF = RotL64((aOrbiterF * 15049472842002138369U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 2981145363531184308U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 14176472085175714494U;
            aOrbiterB = RotL64((aOrbiterB * 2584623327412130939U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 11198457590069700889U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 952584436750426828U) ^ RotL64(aNonceWordH, 13U);
            aOrbiterI = RotL64((aOrbiterI * 1165713888651280355U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 4311591763498985972U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 16194341833989936369U;
            aOrbiterG = RotL64((aOrbiterG * 9997934560195932575U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 7560794022401107431U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterJ) ^ 10683789740265711603U) ^ aOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1]) ^ RotL64(aNonceWordF, 52U);
            aOrbiterE = RotL64((aOrbiterE * 15637823045351977883U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 11614366395125937178U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 10750771385100564416U;
            aOrbiterA = RotL64((aOrbiterA * 4987921274272444283U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 2934697034132204529U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 4646873794658020363U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10555456865641580175U), 43U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterA, 54U);
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterG, 37U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 11U));
            aIngress = aIngress + RotL64(aOrbiterC, 14U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 53U) + aOrbiterJ) + RotL64(aOrbiterE, 47U));
            aWandererI = aWandererI + (((RotL64(aIngress, 44U) + aOrbiterD) + RotL64(aOrbiterJ, 51U)) + RotL64(aCarry, 47U));
            aWandererJ = aWandererJ ^ ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterD, 4U)) + aOrbiterC) + RotL64(aNonceWordC, 61U)) + aWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 35U) + aOrbiterB) + RotL64(aOrbiterJ, 11U)) + RotL64(aCarry, 13U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 5U) + aOrbiterA) + RotL64(aOrbiterE, 43U)) + aWandererUpdateSaltC[((aIndex + 22U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aCross, 48U) + RotL64(aOrbiterG, 27U)) + aOrbiterE);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 13U) + aOrbiterD) + RotL64(aOrbiterI, 18U)) + RotL64(aNonceWordA, 43U));
            aWandererH = aWandererH + ((RotL64(aScatter, 57U) + RotL64(aOrbiterF, 39U)) + aOrbiterA);
            aWandererG = aWandererG ^ ((RotL64(aCross, 29U) + aOrbiterC) + RotL64(aOrbiterF, 35U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + (RotL64(aWandererF, 23U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 26U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + RotL64(aWandererD, 5U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 29U) ^ RotL64(aNonceWordC, 37U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 31286U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneB[((aIndex + 32765U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 11U) ^ RotL64(aNonceWordE, 53U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31903U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30741U)) & S_BLOCK1], 44U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 21U) ^ RotL64(aPrevious, 53U)) ^ (RotL64(aCarry, 34U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererB + RotL64(aPrevious, 35U)) + 5295352595333316211U;
            aOrbiterD = ((aWandererA + RotL64(aCross, 47U)) + 2341795367042042605U) + RotL64(aNonceWordB, 39U);
            aOrbiterA = (aWandererJ + RotL64(aIngress, 53U)) + 10122175780504033663U;
            aOrbiterK = ((aWandererE + RotL64(aScatter, 40U)) + RotL64(aCarry, 51U)) + 10084612804696198554U;
            aOrbiterC = ((aWandererF + RotL64(aIngress, 13U)) + 16470424309851045971U) + RotL64(aNonceWordD, 17U);
            aOrbiterH = ((aWandererH + RotL64(aPrevious, 19U)) + 656016130975227994U) + aOrbiterAssignSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterB = ((aWandererI + RotL64(aScatter, 29U)) + 15313268829659834317U) + aOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = ((aWandererG + RotL64(aCross, 6U)) + RotL64(aCarry, 11U)) + 3795220914993923394U;
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 57U)) + RotL64(aCarry, 43U)) + 14044442220988813825U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 3804224626734584802U) + RotL64(aNonceWordF, 50U);
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 7980006306010255693U;
            aOrbiterA = RotL64((aOrbiterA * 13958505239726088561U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 13746830564584711549U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 11852212099729274845U) ^ RotL64(aNonceWordG, 61U);
            aOrbiterC = RotL64((aOrbiterC * 2164880979318247855U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 9083223471018084847U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 13706723820703853346U;
            aOrbiterB = RotL64((aOrbiterB * 11361854103656219887U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 1713819986642275223U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 1382000168233902914U;
            aOrbiterF = RotL64((aOrbiterF * 3894160765130198157U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 4540474625764565485U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 1756168174375757220U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12739160208010092017U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 1409297070183609309U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 6082750101445444357U) ^ aOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17438740230251860935U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 1113239890859479202U) + aOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 10932192439503964363U) ^ aOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5915660289913324281U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 3732595033748508428U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 5117760372351117286U;
            aOrbiterH = RotL64((aOrbiterH * 2671510075176315761U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 7399968659654088641U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 14835608167871904147U;
            aOrbiterD = RotL64((aOrbiterD * 8312521710415756159U), 53U);
            //
            aIngress = RotL64(aOrbiterK, 57U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterC, 21U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 18U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 37U));
            aIngress = aIngress + RotL64(aOrbiterA, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aIngress, 47U) + RotL64(aOrbiterK, 6U)) + aOrbiterA) + RotL64(aCarry, 5U)) + RotL64(aNonceWordH, 57U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 39U) + aOrbiterK) + RotL64(aOrbiterC, 47U));
            aWandererI = aWandererI + ((((RotL64(aPrevious, 60U) + aOrbiterB) + RotL64(aOrbiterD, 57U)) + RotL64(aCarry, 43U)) + aWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 23U) + aOrbiterE) + RotL64(aOrbiterA, 13U));
            aWandererD = aWandererD + ((RotL64(aCross, 35U) + RotL64(aOrbiterA, 41U)) + aOrbiterD);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 11U) + aOrbiterF) + RotL64(aOrbiterD, 51U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 56U) + aOrbiterH) + RotL64(aOrbiterD, 21U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 27U) + aOrbiterD) + RotL64(aOrbiterG, 34U)) + aWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 51U) + aOrbiterG) + RotL64(aOrbiterH, 29U)) + RotL64(aNonceWordA, 49U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererE, 5U) ^ aWandererB);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 10U));
            aCarry = aCarry + RotL64(aWandererH, 21U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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

void TwistExpander_Archery_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xF7ACBC9956AC0753ULL + 0x8FE6DE79B1877989ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x94CBC01DFB9DB941ULL + 0xC9FA318E624538DAULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xB2219192FE99789FULL + 0xE571498CDFE2B8BFULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xCCD36CBC8262D609ULL + 0xB92040EE833A87E4ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xE2305398DB9F2757ULL + 0xA7CF664DB53E6344ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xCBD3B16D870CE0C1ULL + 0xC70FCDDEB3F3F833ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x8B0EB12B3B13A79DULL + 0xAAC1B29BD6920236ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x838C2CBB87CD75FFULL + 0xFF35DD17EBA81DADULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 39U) ^ RotL64(aNonceWordA, 57U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 236U)) & S_BLOCK1], 47U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 1155U)) & W_KEY1], 4U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 11U) ^ RotL64(aNonceWordE, 3U));
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 3173U)) & W_KEY1], 42U) ^ RotL64(mSource[((aIndex + 2771U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 27U) + RotL64(aIngress, 14U)) ^ (RotL64(aCross, 41U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterC = ((aWandererG + RotL64(aIngress, 35U)) + 4179952823252098240U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = (((aWandererK + RotL64(aScatter, 27U)) + RotL64(aCarry, 29U)) + 3745613452332101749U) + RotL64(aNonceWordG, 51U);
            aOrbiterA = (((aWandererF + RotL64(aCross, 21U)) + RotL64(aCarry, 13U)) + 2955689793395307176U) + aPhaseAOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = (aWandererD + RotL64(aPrevious, 11U)) + 5639060180251322019U;
            aOrbiterK = ((aWandererB + RotL64(aScatter, 54U)) + 7901969163853586463U) + RotL64(aNonceWordH, 61U);
            aOrbiterF = (aWandererH + RotL64(aPrevious, 41U)) + 2242166787816318119U;
            aOrbiterI = ((aWandererI + RotL64(aIngress, 5U)) + RotL64(aCarry, 41U)) + 5239936443960750064U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 13939136954732185558U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 17058884136712717463U) ^ RotL64(aNonceWordE, 59U);
            aOrbiterA = RotL64((aOrbiterA * 7222348891215482977U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 18148618660054585941U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 7022023484530327814U;
            aOrbiterK = RotL64((aOrbiterK * 650100011311048589U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 7722084537340095637U) + RotL64(aNonceWordC, 47U);
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 11764151879690934182U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12264384877711365655U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 16412785901758144708U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 9666718667728274824U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10865799822751771795U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 4307127540152109364U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 2457646804702647606U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6340030928007058595U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 3179394870088602208U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 504977947273774249U;
            aOrbiterE = RotL64((aOrbiterE * 16190282058883481551U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 16182729401018310837U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 7110817020445860609U;
            aOrbiterH = RotL64((aOrbiterH * 13371352088428584087U), 3U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterK, 35U);
            aIngress = aIngress + (RotL64(aOrbiterH, 41U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 28U));
            aIngress = aIngress + RotL64(aOrbiterI, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((((RotL64(aCross, 19U) + RotL64(aOrbiterF, 3U)) + aOrbiterH) + RotL64(aNonceWordB, 9U)) + aPhaseAWandererUpdateSaltC[((aIndex + 26U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 51U)) + aOrbiterK) + RotL64(aCarry, 29U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 51U) + aOrbiterE) + RotL64(aOrbiterK, 57U)) + RotL64(aNonceWordF, 60U));
            aWandererH = aWandererH + (((RotL64(aScatter, 44U) + RotL64(aOrbiterI, 42U)) + aOrbiterA) + RotL64(aCarry, 53U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterC, 11U)) + aOrbiterH);
            aWandererK = aWandererK + (((RotL64(aPrevious, 57U) + aOrbiterA) + RotL64(aOrbiterC, 19U)) + aPhaseAWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterC, 29U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 4U));
            aCarry = aCarry + (RotL64(aWandererF, 23U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererD, 43U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 58U) ^ RotL64(aNonceWordB, 11U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 7818U)) & S_BLOCK1], 19U) ^ RotL64(mSource[((aIndex + 10102U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 56U) ^ RotL64(aNonceWordD, 21U)) ^ RotL64(aNonceWordE, 3U));
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 6826U)) & W_KEY1], 47U) ^ RotL64(aKeyRowReadB[((aIndex + 7106U)) & W_KEY1], 11U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 36U)) ^ (RotL64(aCross, 11U) + RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterJ = (aWandererH + RotL64(aPrevious, 23U)) + 2974056819475622600U;
            aOrbiterA = ((aWandererG + RotL64(aCross, 47U)) + RotL64(aCarry, 39U)) + 7345051759236356098U;
            aOrbiterI = ((aWandererF + RotL64(aIngress, 39U)) + RotL64(aCarry, 51U)) + 12738468816846628882U;
            aOrbiterF = ((aWandererK + RotL64(aScatter, 3U)) + 7694520596043297922U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = (aWandererC + RotL64(aPrevious, 11U)) + 5530753590015084774U;
            aOrbiterD = ((aWandererE + RotL64(aIngress, 29U)) + 3776309161718383105U) + RotL64(aNonceWordD, 5U);
            aOrbiterH = ((((aWandererD + RotL64(aScatter, 60U)) + RotL64(aCarry, 3U)) + 784780304358106404U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1]) + RotL64(aNonceWordA, 25U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 8999942326995036509U) + RotL64(aNonceWordF, 39U);
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 5194986506064092779U;
            aOrbiterI = RotL64((aOrbiterI * 15070787038006135963U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 7920040007459652762U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterF) ^ 11311997270710107937U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]) ^ RotL64(aNonceWordH, 29U);
            aOrbiterJ = RotL64((aOrbiterJ * 6227571709361790209U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 5365231114813547251U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 8630110234623825263U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2735881715888325759U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 2358235238039571072U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 18059414891616491807U;
            aOrbiterA = RotL64((aOrbiterA * 17150786106857185467U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 14526050556461782864U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 6937282036603272474U;
            aOrbiterC = RotL64((aOrbiterC * 14954512365270028029U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 10105832250694931310U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 3884223553012098137U;
            aOrbiterD = RotL64((aOrbiterD * 16340956813003906195U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 10385284339549648087U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 1257633893341505930U;
            aOrbiterH = RotL64((aOrbiterH * 2669950791270500977U), 39U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterJ, 29U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 39U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + RotL64(aOrbiterH, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterF, 57U)) + aOrbiterC) + RotL64(aNonceWordC, 60U));
            aWandererE = aWandererE + ((((RotL64(aCross, 3U) + RotL64(aOrbiterA, 3U)) + aOrbiterC) + RotL64(aCarry, 35U)) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterJ, 21U)) + aOrbiterH);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterF, 35U)) + aOrbiterA) + RotL64(aNonceWordG, 61U)) + aPhaseAWandererUpdateSaltB[((aIndex + 6U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 24U) + RotL64(aOrbiterI, 47U)) + aOrbiterD);
            aWandererK = aWandererK + (((RotL64(aPrevious, 13U) + aOrbiterI) + RotL64(aOrbiterH, 28U)) + RotL64(aCarry, 53U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 37U) + aOrbiterF) + RotL64(aOrbiterI, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererC, 18U) ^ aWandererD);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + RotL64(aWandererE, 27U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 47U) ^ RotL64(aNonceWordG, 57U)) ^ RotL64(aNonceWordF, 14U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 11289U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((aIndex + 12044U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 50U) ^ RotL64(aNonceWordH, 39U)) ^ RotL64(aNonceWordE, 19U));
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 11346U)) & W_KEY1], 29U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 12619U)) & W_KEY1], 11U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCarry, 39U)) + (RotL64(aPrevious, 21U) + RotL64(aCross, 54U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterD = (aWandererB + RotL64(aPrevious, 13U)) + 4848316479321533394U;
            aOrbiterG = (aWandererA + RotL64(aScatter, 24U)) + 6919360256662636195U;
            aOrbiterB = (aWandererC + RotL64(aCross, 5U)) + 9897013582181108544U;
            aOrbiterE = (aWandererJ + RotL64(aIngress, 51U)) + 7319353809896158678U;
            aOrbiterC = ((((aWandererE + RotL64(aPrevious, 57U)) + RotL64(aCarry, 53U)) + 2848175435514849859U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1]) + RotL64(aNonceWordF, 11U);
            aOrbiterA = (((aWandererG + RotL64(aIngress, 35U)) + RotL64(aCarry, 35U)) + 6967780718720437934U) + aPhaseAOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = (((aWandererF + RotL64(aCross, 43U)) + RotL64(aCarry, 11U)) + 10143884766603388136U) + RotL64(aNonceWordG, 9U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 8675965006150972051U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 16350117755560994281U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15072308930382994425U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 17976597517118423760U) + RotL64(aNonceWordH, 19U);
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 1399631141355370237U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16537788276543236833U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 3590613762034716792U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 5134624314245932157U;
            aOrbiterD = RotL64((aOrbiterD * 13077589037975283371U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 10082236952942943654U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 4015535035905433450U) ^ RotL64(aNonceWordC, 35U);
            aOrbiterE = RotL64((aOrbiterE * 4961808568701908559U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 611474103801573800U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 5786708483794098001U;
            aOrbiterC = RotL64((aOrbiterC * 7694007039340089267U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 5201943497363274455U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 9282160506938328489U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5368182164239021367U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 4932320527498940158U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 11576526341731392916U;
            aOrbiterF = RotL64((aOrbiterF * 1712051774729439363U), 5U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterA, 51U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 35U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 44U));
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aCross, 53U) + aOrbiterE) + RotL64(aOrbiterC, 29U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterF, 23U)) + aOrbiterG);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterD, 5U)) + aOrbiterG) + RotL64(aCarry, 43U)) + RotL64(aNonceWordA, 15U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 38U) + RotL64(aOrbiterF, 35U)) + aOrbiterA) + RotL64(aNonceWordE, 24U));
            aWandererF = aWandererF + (((RotL64(aScatter, 3U) + RotL64(aOrbiterC, 54U)) + aOrbiterF) + RotL64(aCarry, 27U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterB, 41U)) + aOrbiterE) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 21U) + RotL64(aOrbiterE, 47U)) + aOrbiterA) + aPhaseAWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + RotL64(aWandererA, 56U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 4U) ^ RotL64(aNonceWordB, 23U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 21171U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneB[((aIndex + 20821U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 19U) ^ RotL64(aNonceWordH, 51U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16425U)) & S_BLOCK1], 27U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 17360U)) & S_BLOCK1], 40U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 47U) ^ RotL64(aPrevious, 23U)) + (RotL64(aCarry, 35U) + RotL64(aIngress, 6U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterF = (aWandererH + RotL64(aIngress, 57U)) + 12029393034357490020U;
            aOrbiterD = (((aWandererJ + RotL64(aCross, 29U)) + RotL64(aCarry, 3U)) + 4526754731580694987U) + aPhaseAOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = ((aWandererF + RotL64(aScatter, 51U)) + 17060419646421271853U) + RotL64(aNonceWordG, 27U);
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 41U)) + RotL64(aCarry, 51U)) + 4128488893837059683U;
            aOrbiterI = (aWandererI + RotL64(aScatter, 23U)) + 12706894827547160110U;
            aOrbiterH = (aWandererA + RotL64(aPrevious, 13U)) + 12506324593645825056U;
            aOrbiterE = ((((aWandererB + RotL64(aIngress, 4U)) + RotL64(aCarry, 21U)) + 12581344490649250025U) + aPhaseAOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1]) + RotL64(aNonceWordD, 25U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 14357032418199130132U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 15341977701796331249U;
            aOrbiterG = RotL64((aOrbiterG * 6332369248718076031U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 7086602307544733241U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 12398300065276832486U) ^ RotL64(aNonceWordC, 57U);
            aOrbiterH = RotL64((aOrbiterH * 18157408831225635333U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 2499745046076601988U) + RotL64(aNonceWordA, 21U);
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 7249361592814001829U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14597139848072319685U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 3254456186337366437U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 3472973415969046680U;
            aOrbiterI = RotL64((aOrbiterI * 14583566953969168353U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 7905718972111691591U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 15941413652144021522U;
            aOrbiterF = RotL64((aOrbiterF * 3473779492962783565U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 10583964125960308762U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 13659925272340853715U;
            aOrbiterK = RotL64((aOrbiterK * 16708294803316630743U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 9487054537489454887U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 13287757570441887517U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17351439045329892107U), 11U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterI, 13U);
            aIngress = aIngress + (RotL64(aOrbiterE, 35U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterH, 27U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterK, 58U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 57U) + aOrbiterI) + RotL64(aOrbiterG, 57U));
            aWandererA = aWandererA + (((RotL64(aIngress, 41U) + aOrbiterE) + RotL64(aOrbiterF, 4U)) + RotL64(aNonceWordE, 44U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterE, 35U)) + aOrbiterH) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 21U) + RotL64(aOrbiterH, 27U)) + aOrbiterI) + RotL64(aCarry, 29U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 29U) + aOrbiterK) + RotL64(aOrbiterD, 19U)) + aPhaseAWandererUpdateSaltC[((aIndex + 22U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aCross, 3U) + RotL64(aOrbiterE, 13U)) + aOrbiterD) + RotL64(aCarry, 13U)) + RotL64(aNonceWordF, 45U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 14U) + RotL64(aOrbiterD, 43U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 29U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 12U));
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererI, 53U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 53U) ^ RotL64(aNonceWordC, 41U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 26122U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneA[((aIndex + 24441U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 19U) ^ RotL64(aNonceWordG, 5U)) ^ RotL64(aNonceWordD, 39U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 22295U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneA[((aIndex + 25675U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 43U) ^ RotL64(aCross, 11U)) + (RotL64(aCarry, 60U) ^ RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterB = (((aWandererI + RotL64(aCross, 3U)) + RotL64(aCarry, 51U)) + 12980104182836602177U) + aPhaseAOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = (((aWandererG + RotL64(aPrevious, 37U)) + RotL64(aCarry, 29U)) + 3172622203188863995U) + RotL64(aNonceWordH, 7U);
            aOrbiterI = (aWandererC + RotL64(aScatter, 27U)) + 1170974132219980203U;
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 19U)) + 6035201940965047490U) + aPhaseAOrbiterAssignSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterK = ((aWandererB + RotL64(aScatter, 11U)) + RotL64(aCarry, 3U)) + 18033907118424996722U;
            aOrbiterC = ((aWandererD + RotL64(aCross, 44U)) + 14604813424800580304U) + RotL64(aNonceWordB, 13U);
            aOrbiterF = (aWandererJ + RotL64(aIngress, 51U)) + 13720232492851066035U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 3902659710585257448U) + RotL64(aNonceWordF, 41U);
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 8331560652661619868U;
            aOrbiterI = RotL64((aOrbiterI * 11418103770615560205U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 4485014147538689794U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 168202636924512424U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13711020666131492091U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 16227825670092707848U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 4792781933944671365U;
            aOrbiterJ = RotL64((aOrbiterJ * 15859849676231455283U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 12636865372722601282U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 18198291399585556632U) ^ RotL64(aNonceWordE, 61U);
            aOrbiterG = RotL64((aOrbiterG * 18155803890313399795U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 3650053185419807206U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 5897288963905408776U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3706949366974086151U), 37U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 9922308113622901726U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 13352279749091561510U;
            aOrbiterC = RotL64((aOrbiterC * 4025213180483632557U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 14969461950939646117U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 10231661776135056651U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11284575051455238501U), 13U);
            //
            aIngress = RotL64(aOrbiterF, 53U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterI, 37U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterJ, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterJ, 37U)) + aOrbiterI);
            aWandererI = aWandererI + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterG, 58U)) + aOrbiterK) + RotL64(aCarry, 51U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterC, 43U)) + aOrbiterI) + RotL64(aNonceWordA, 28U));
            aWandererB = aWandererB + (((RotL64(aCross, 5U) + RotL64(aOrbiterK, 21U)) + aOrbiterC) + RotL64(aCarry, 19U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterB, 3U)) + aOrbiterI);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 21U) + aOrbiterK) + RotL64(aOrbiterF, 13U)) + RotL64(aNonceWordC, 25U)) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 60U) + RotL64(aOrbiterF, 29U)) + aOrbiterC) + aPhaseAWandererUpdateSaltE[((aIndex + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 12U) ^ aWandererD);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + RotL64(aWandererG, 23U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 21U) ^ RotL64(aNonceWordH, 60U)) ^ RotL64(aNonceWordF, 37U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 28135U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((aIndex + 28685U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 57U) ^ RotL64(aNonceWordD, 47U)) ^ RotL64(aNonceWordC, 3U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28849U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneB[((aIndex + 32072U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 24U) + RotL64(aCross, 51U)) ^ (RotL64(aPrevious, 11U) ^ RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 20U)) + 12690502671561165478U) + RotL64(aNonceWordF, 5U);
            aOrbiterG = ((aWandererA + RotL64(aScatter, 29U)) + RotL64(aCarry, 5U)) + 17519943923428102801U;
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 51U)) + RotL64(aCarry, 53U)) + 10705515807975331385U;
            aOrbiterF = (((aWandererH + RotL64(aCross, 5U)) + RotL64(aCarry, 39U)) + 16586447272278538179U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = ((aWandererB + RotL64(aIngress, 37U)) + 8006560996840971798U) + aPhaseAOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = ((aWandererF + RotL64(aCross, 43U)) + 12928600185788857701U) + RotL64(aNonceWordB, 41U);
            aOrbiterA = (aWandererC + RotL64(aPrevious, 11U)) + 14240723153798267172U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 8636219177994872072U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 7586790235186467512U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15052686382507614169U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 1103807034179512424U) + RotL64(aNonceWordE, 61U);
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 7547526530239498693U) ^ RotL64(aNonceWordD, 60U);
            aOrbiterC = RotL64((aOrbiterC * 3360295583636013509U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 8380239679344786397U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 5690809173787433519U;
            aOrbiterE = RotL64((aOrbiterE * 5354724308093372953U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 8390902801141804609U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 3507306189192059486U;
            aOrbiterA = RotL64((aOrbiterA * 18336280496510253103U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 6190745292098482871U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 8065418693975056902U;
            aOrbiterH = RotL64((aOrbiterH * 6414621418430102589U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 12111755051718111803U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 7605877769709909297U;
            aOrbiterF = RotL64((aOrbiterF * 17525248694315944599U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 5969794501112646237U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 5127559299360591476U;
            aOrbiterG = RotL64((aOrbiterG * 4521563633438853069U), 53U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterC, 35U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 21U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 3U));
            aIngress = aIngress + RotL64(aOrbiterE, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterK, 29U)) + aOrbiterF) + RotL64(aNonceWordG, 43U));
            aWandererF = aWandererF + (((RotL64(aCross, 29U) + aOrbiterK) + RotL64(aOrbiterA, 13U)) + RotL64(aCarry, 13U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 22U) + aOrbiterG) + RotL64(aOrbiterH, 37U));
            aWandererB = aWandererB + ((RotL64(aScatter, 43U) + aOrbiterH) + RotL64(aOrbiterE, 51U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 11U) + aOrbiterG) + RotL64(aOrbiterE, 23U)) + aPhaseAWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterC, 58U)) + aOrbiterH) + RotL64(aCarry, 39U));
            aWandererH = aWandererH ^ ((((RotL64(aIngress, 51U) + RotL64(aOrbiterK, 43U)) + aOrbiterH) + RotL64(aNonceWordH, 45U)) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererA, 48U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererD, 35U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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

void TwistExpander_Archery_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xB4BC1CCB410D158DULL + 0xF894F008A12381DCULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xC7C9CE7569BE9DA5ULL + 0xE34243D85FF6AAA8ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x885FFCCCBCEA4C5DULL + 0xF2D7C28BCDE0C356ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x9E118FA3089EE9A5ULL + 0x975AAFEFF431868DULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xEDA2CB0E1853899BULL + 0x8139446C788BBF4FULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xAC9F93C8A8D5D489ULL + 0xA6ECDC640ECA5306ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xC7F6FCF6CD376059ULL + 0xDDBC5B9A32ABA614ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xC8146EF8E0E3523FULL + 0x89D90C7AF6230923ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 42U) ^ RotL64(aNonceWordG, 57U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 2006U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2601U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 18U) ^ RotL64(aNonceWordF, 47U)) ^ RotL64(aNonceWordA, 5U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 3443U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((aIndex + 2065U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aPrevious, 13U)) + (RotL64(aIngress, 57U) ^ RotL64(aCarry, 26U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterH = (((aWandererD + RotL64(aScatter, 13U)) + RotL64(aCarry, 57U)) + 4739486756133131180U) + RotL64(aNonceWordB, 43U);
            aOrbiterD = ((aWandererE + RotL64(aIngress, 21U)) + RotL64(aCarry, 13U)) + 16089707555501328184U;
            aOrbiterI = (((aWandererI + RotL64(aPrevious, 51U)) + RotL64(aCarry, 35U)) + 15310047330238536453U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = ((aWandererC + RotL64(aCross, 43U)) + 7901411596386834955U) + RotL64(aNonceWordD, 38U);
            aOrbiterE = ((aWandererK + RotL64(aScatter, 34U)) + 4357555491060982163U) + aPhaseBOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 15667085602825720102U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 8520635334382269253U;
            aOrbiterI = RotL64((aOrbiterI * 7348648918661047791U), 5U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterE) + 1772509779231068315U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]) + RotL64(aNonceWordE, 29U);
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 15336170957886025677U;
            aOrbiterH = RotL64((aOrbiterH * 10996880551392077399U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 8628770833489469980U) + RotL64(aNonceWordC, 17U);
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 15469234024247246228U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8905266995119987947U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 10796430900884288328U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 10660110397012853289U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9140007610912037461U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 11202284258711214794U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 17509491802893182994U;
            aOrbiterE = RotL64((aOrbiterE * 9329107599972703671U), 41U);
            //
            aIngress = RotL64(aOrbiterD, 47U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterH, 12U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterI, 11U)) + aOrbiterE) + RotL64(aCarry, 43U)) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 58U) + aOrbiterD) + RotL64(aOrbiterE, 21U)) + RotL64(aNonceWordF, 31U));
            aWandererK = aWandererK + ((RotL64(aCross, 47U) + RotL64(aOrbiterK, 42U)) + aOrbiterH);
            aWandererI = aWandererI ^ ((((RotL64(aScatter, 35U) + aOrbiterI) + RotL64(aOrbiterH, 3U)) + RotL64(aNonceWordH, 3U)) + aPhaseBWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 19U) + RotL64(aOrbiterD, 51U)) + aOrbiterI) + RotL64(aCarry, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 14U));
            aCarry = aCarry + RotL64(aWandererC, 27U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 51U) ^ RotL64(aNonceWordH, 43U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8346U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 8417U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 36U) ^ RotL64(aNonceWordE, 3U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 6588U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((aIndex + 8941U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 35U) + RotL64(aCross, 21U)) + (RotL64(aPrevious, 54U) ^ RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterA = (((aWandererJ + RotL64(aPrevious, 19U)) + RotL64(aCarry, 57U)) + 14179205183062705133U) + RotL64(aNonceWordD, 10U);
            aOrbiterE = ((aWandererF + RotL64(aIngress, 3U)) + 210032324058740920U) + aPhaseBOrbiterAssignSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterK = ((aWandererC + RotL64(aCross, 57U)) + RotL64(aCarry, 19U)) + 7387115089142500152U;
            aOrbiterH = (((aWandererD + RotL64(aScatter, 30U)) + 17583362781238061430U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 7U)) & S_SALT1]) + RotL64(aNonceWordA, 49U);
            aOrbiterF = ((aWandererA + RotL64(aIngress, 43U)) + RotL64(aCarry, 5U)) + 4991442849150005943U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 2891376254689854555U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 10523274382407446239U;
            aOrbiterK = RotL64((aOrbiterK * 17443994099359920915U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 3861893764676218667U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterE) ^ 3366674459852093746U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1]) ^ RotL64(aNonceWordE, 27U);
            aOrbiterF = RotL64((aOrbiterF * 14005994095369483813U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 5898492634386601145U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 7047353571244768721U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2257518291062508467U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 14374108805453186316U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 8763667021501226510U;
            aOrbiterE = RotL64((aOrbiterE * 7694695426430267863U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 18261523829316379575U) + RotL64(aNonceWordF, 53U);
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 650477532238860965U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8291758490821819851U), 37U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterE, 26U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aPrevious, 42U) + RotL64(aOrbiterH, 13U)) + aOrbiterK) + RotL64(aCarry, 5U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 57U) + aOrbiterH) + RotL64(aOrbiterA, 46U)) + RotL64(aNonceWordG, 25U));
            aWandererC = aWandererC + ((((RotL64(aScatter, 21U) + RotL64(aOrbiterF, 57U)) + aOrbiterA) + RotL64(aCarry, 23U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((((RotL64(aCross, 29U) + RotL64(aOrbiterA, 37U)) + aOrbiterE) + RotL64(aNonceWordH, 51U)) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterH, 21U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererA, 5U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 44U) ^ RotL64(aNonceWordF, 57U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 15794U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 16228U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 14U) ^ RotL64(aNonceWordA, 5U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 12164U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 11935U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 52U) + RotL64(aPrevious, 21U)) ^ (RotL64(aCross, 5U) + RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterG = (((aWandererC + RotL64(aCross, 58U)) + RotL64(aCarry, 27U)) + 8375305456876489425U) + RotL64(aNonceWordE, 39U);
            aOrbiterC = (aWandererF + RotL64(aIngress, 29U)) + 16193562952772453047U;
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 11U)) + RotL64(aCarry, 3U)) + 18088652458594816223U;
            aOrbiterH = (((aWandererI + RotL64(aPrevious, 19U)) + RotL64(aCarry, 39U)) + 767344788620249944U) + aPhaseBOrbiterAssignSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterA = (((aWandererA + RotL64(aIngress, 47U)) + 7705194930396368752U) + aPhaseBOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1]) + RotL64(aNonceWordB, 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 3829736891311272834U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 9881681671347640061U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14380245087931793021U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 1721196560190164264U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 3002652618388454213U;
            aOrbiterC = RotL64((aOrbiterC * 15289749311593032657U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 9811621464004005202U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 5652598941069986530U;
            aOrbiterG = RotL64((aOrbiterG * 4797973356708091621U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 6250499348327316328U) + RotL64(aNonceWordC, 49U);
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 16025054277615264530U;
            aOrbiterH = RotL64((aOrbiterH * 16446892258704281903U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 13800298546867243172U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = (((aOrbiterA ^ aOrbiterC) ^ 12256104592865905782U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]) ^ RotL64(aNonceWordH, 16U);
            aOrbiterA = RotL64((aOrbiterA * 16983140179497142713U), 5U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterJ, 57U);
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterG, 18U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aIngress, 29U) + aOrbiterH) + RotL64(aOrbiterA, 18U)) + aPhaseBWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 56U) + aOrbiterC) + RotL64(aOrbiterJ, 3U)) + RotL64(aCarry, 57U)) + aPhaseBWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 21U) + aOrbiterH) + RotL64(aOrbiterJ, 57U)) + RotL64(aNonceWordG, 47U));
            aWandererA = aWandererA + (((RotL64(aScatter, 37U) + aOrbiterC) + RotL64(aOrbiterG, 27U)) + RotL64(aCarry, 19U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterA, 43U)) + aOrbiterJ) + RotL64(aNonceWordD, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 56U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererA, 37U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererI, 23U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 54U) ^ RotL64(aNonceWordF, 21U)) ^ RotL64(aNonceWordA, 37U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 18347U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((aIndex + 20472U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 35U) ^ RotL64(aNonceWordH, 5U)) ^ RotL64(aNonceWordD, 46U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17786U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 20481U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 11U) + RotL64(aPrevious, 39U)) ^ (RotL64(aIngress, 27U) ^ RotL64(aCross, 56U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterC = (aWandererD + RotL64(aScatter, 29U)) + 12027839670755583592U;
            aOrbiterF = ((aWandererI + RotL64(aCross, 53U)) + RotL64(aCarry, 57U)) + 15380130703509859843U;
            aOrbiterJ = (((aWandererK + RotL64(aIngress, 41U)) + RotL64(aCarry, 27U)) + 4590907433867798074U) + RotL64(aNonceWordB, 27U);
            aOrbiterA = ((((aWandererB + RotL64(aPrevious, 14U)) + RotL64(aCarry, 43U)) + 1754574023602519724U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1]) + RotL64(aNonceWordG, 49U);
            aOrbiterH = ((aWandererH + RotL64(aIngress, 5U)) + 9832756659564903767U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 5035088494491470403U) + RotL64(aNonceWordC, 29U);
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 14199170923323644638U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4518257134117207121U), 13U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterH) + 8325619421264440438U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1]) + RotL64(aNonceWordD, 59U);
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 969534320779067977U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17767548306355264705U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 270575869402913847U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 13344806516599578910U;
            aOrbiterA = RotL64((aOrbiterA * 10193544126281901579U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 15143147951139409101U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 14425582489214169238U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16893787086337916355U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 13951127523239064584U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 14177925225918293579U;
            aOrbiterH = RotL64((aOrbiterH * 13079514031864998485U), 51U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterA, 13U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterF, 54U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aIngress, 13U) + aOrbiterA) + RotL64(aOrbiterC, 3U)) + RotL64(aCarry, 5U)) + aPhaseBWandererUpdateSaltD[((aIndex + 8U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 5U) + aOrbiterJ) + RotL64(aOrbiterA, 11U));
            aWandererB = aWandererB + (((((RotL64(aCross, 38U) + RotL64(aOrbiterA, 27U)) + aOrbiterH) + RotL64(aCarry, 43U)) + RotL64(aNonceWordF, 40U)) + aPhaseBWandererUpdateSaltE[((aIndex + 14U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 21U) + aOrbiterH) + RotL64(aOrbiterC, 19U)) + RotL64(aNonceWordA, 3U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterF, 56U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 44U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 47U) ^ RotL64(aNonceWordH, 37U)) ^ RotL64(aNonceWordD, 4U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 21878U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneA[((aIndex + 21888U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 54U) ^ RotL64(aNonceWordF, 5U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 23408U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((aIndex + 23211U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 29U) + RotL64(aIngress, 60U)) ^ (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 13U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterB = (((aWandererA + RotL64(aIngress, 11U)) + RotL64(aCarry, 19U)) + 7075016829833562104U) + RotL64(aNonceWordD, 49U);
            aOrbiterC = (aWandererB + RotL64(aCross, 53U)) + 8783765886115517036U;
            aOrbiterA = (((aWandererF + RotL64(aScatter, 19U)) + 2996723892384565829U) + aPhaseBOrbiterAssignSaltE[((aIndex + 7U)) & S_SALT1]) + RotL64(aNonceWordG, 55U);
            aOrbiterD = (((aWandererI + RotL64(aPrevious, 36U)) + RotL64(aCarry, 5U)) + 9494134707342189476U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 27U)) + RotL64(aCarry, 51U)) + 5052642981395679904U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 8766787055127962238U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 4467211954388738079U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8599295330343804047U), 19U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterD) + 8030255604633658608U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1]) + RotL64(aNonceWordA, 47U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 16962408063455702251U;
            aOrbiterJ = RotL64((aOrbiterJ * 11171737929747471631U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 3768222186567699076U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterD) ^ 14930990410207899871U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1]) ^ RotL64(aNonceWordC, 26U);
            aOrbiterB = RotL64((aOrbiterB * 10930005786146268241U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 14179761938395502502U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 1879084742719898108U;
            aOrbiterC = RotL64((aOrbiterC * 16783034788172670121U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 5535012408925981515U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 12792553516710295939U;
            aOrbiterD = RotL64((aOrbiterD * 8577530993755159329U), 57U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterJ, 57U);
            aIngress = aIngress + (RotL64(aOrbiterC, 29U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterD, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 14U) + aOrbiterC) + RotL64(aOrbiterD, 39U)) + aPhaseBWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 3U) + aOrbiterB) + RotL64(aOrbiterC, 5U)) + RotL64(aCarry, 29U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 37U) + RotL64(aOrbiterJ, 52U)) + aOrbiterA) + RotL64(aNonceWordH, 15U));
            aWandererI = aWandererI + (((RotL64(aCross, 27U) + RotL64(aOrbiterD, 13U)) + aOrbiterA) + RotL64(aCarry, 13U));
            aWandererB = aWandererB ^ ((((RotL64(aIngress, 47U) + RotL64(aOrbiterJ, 27U)) + aOrbiterD) + RotL64(aNonceWordF, 59U)) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererB);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + RotL64(aWandererG, 4U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 57U) ^ RotL64(aNonceWordB, 3U)) ^ RotL64(aNonceWordE, 44U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 27653U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneB[((aIndex + 31837U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 43U) ^ RotL64(aNonceWordH, 19U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 29913U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29359U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 10U) ^ RotL64(aCross, 23U)) ^ (RotL64(aPrevious, 39U) + RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterB = (((aWandererI + RotL64(aCross, 20U)) + RotL64(aCarry, 37U)) + 8367680518550579791U) + RotL64(aNonceWordH, 27U);
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 39U)) + RotL64(aCarry, 23U)) + 11491674725611181241U;
            aOrbiterK = ((aWandererE + RotL64(aScatter, 53U)) + 16673861720782164214U) + aPhaseBOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = (((aWandererH + RotL64(aIngress, 3U)) + RotL64(aCarry, 5U)) + 9786610124108350855U) + RotL64(aNonceWordC, 7U);
            aOrbiterE = ((aWandererB + RotL64(aScatter, 29U)) + 5745080601557577637U) + aPhaseBOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 1959402215131684684U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 6121650036079196522U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13375345606276198671U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 12016309761037342392U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 5986936646177049603U;
            aOrbiterC = RotL64((aOrbiterC * 3585650475703294895U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 1000367700904043468U) + RotL64(aNonceWordF, 48U);
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 17425288243569101032U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2174614006719048535U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 4856917474950325209U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 16312111093223166419U;
            aOrbiterI = RotL64((aOrbiterI * 11046477664487805241U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 456110002032422270U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterC) ^ 11393724374787795662U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1]) ^ RotL64(aNonceWordB, 25U);
            aOrbiterE = RotL64((aOrbiterE * 1176984359123668389U), 11U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterC, 23U);
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterI, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aCross, 37U) + RotL64(aOrbiterI, 43U)) + aOrbiterC) + RotL64(aCarry, 43U));
            aWandererB = aWandererB ^ ((((RotL64(aIngress, 11U) + RotL64(aOrbiterE, 27U)) + aOrbiterC) + RotL64(aNonceWordA, 51U)) + aPhaseBWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 50U) + aOrbiterB) + RotL64(aOrbiterE, 12U)) + RotL64(aCarry, 57U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterI, 57U)) + aOrbiterK);
            aWandererH = aWandererH + ((((RotL64(aScatter, 3U) + aOrbiterI) + RotL64(aOrbiterE, 3U)) + RotL64(aNonceWordD, 21U)) + aPhaseBWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 13U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + RotL64(aWandererI, 5U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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

void TwistExpander_Archery_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xE1F922CBB69A6365ULL + 0xBE3A2898D06DF426ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xD68F6BE4A7612171ULL + 0x91C42F464306F5F3ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xCA83C7D685E2A359ULL + 0xED6E48BEC5562877ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xB0E3694DD05993D5ULL + 0x853C2CBC1D183593ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xFBA13D653B343BEDULL + 0xE61F63BF066BB8E3ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xCB2E3CAD5C58472DULL + 0xCDE1F54B73C2039DULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xA08D0023B6DEF299ULL + 0xB9C4BB5468CE1D21ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xCF77AC0B882BC577ULL + 0xF19E344327F38692ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 43U) ^ RotL64(aNonceWordG, 24U)) ^ RotL64(aNonceWordD, 5U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 3289U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 1534U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 35U) ^ RotL64(aNonceWordH, 44U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 235U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneA[((aIndex + 6364U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 51U) ^ RotL64(aCarry, 39U)) + (RotL64(aCross, 6U) ^ RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterG = ((aWandererI + RotL64(aCross, 47U)) + 4259993311776766595U) + aPhaseCOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = (aWandererC + RotL64(aIngress, 51U)) + 2857813330021126753U;
            aOrbiterJ = (aWandererJ + RotL64(aPrevious, 43U)) + 1345396841329442896U;
            aOrbiterE = (aWandererK + RotL64(aScatter, 14U)) + 320992148982301024U;
            aOrbiterF = (aWandererF + RotL64(aPrevious, 3U)) + 5619109532065293074U;
            aOrbiterA = (((aWandererB + RotL64(aIngress, 29U)) + RotL64(aCarry, 51U)) + 10380157329426706345U) + RotL64(aNonceWordG, 60U);
            aOrbiterI = ((aWandererG + RotL64(aScatter, 57U)) + 12449831150625409695U) + aPhaseCOrbiterAssignSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = (((aWandererA + RotL64(aCross, 21U)) + RotL64(aCarry, 23U)) + 7847096607042268396U) + RotL64(aNonceWordH, 29U);
            aOrbiterB = ((aWandererD + RotL64(aScatter, 38U)) + RotL64(aCarry, 39U)) + 11707184096803214678U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 9893643746186827088U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 333687403830908774U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17911256836121454271U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 13837360705077441580U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 4367119682175710689U;
            aOrbiterA = RotL64((aOrbiterA * 10295744669174603401U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 1193493435041306784U) + RotL64(aNonceWordA, 37U);
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 15062951612027370606U;
            aOrbiterK = RotL64((aOrbiterK * 2509383510565136549U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 16000173839235429105U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 15294482444605409961U;
            aOrbiterB = RotL64((aOrbiterB * 1031800997944302665U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 5720749055549773527U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 17248674962996093668U;
            aOrbiterG = RotL64((aOrbiterG * 15730637462755795591U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 16956840483882091059U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 9637715107943515594U;
            aOrbiterE = RotL64((aOrbiterE * 8878362378343603463U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 7147495779349862274U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 7508890985889484275U;
            aOrbiterI = RotL64((aOrbiterI * 17728368447504622035U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 4407738164617959366U) + RotL64(aNonceWordF, 27U);
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 17027017782352660454U;
            aOrbiterD = RotL64((aOrbiterD * 417183060881259295U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 3174658601748235285U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 9779053567370714831U;
            aOrbiterF = RotL64((aOrbiterF * 6383245776181968033U), 23U);
            //
            aIngress = RotL64(aOrbiterG, 24U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 29U));
            aIngress = aIngress + (RotL64(aOrbiterK, 13U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 19U));
            aIngress = aIngress + RotL64(aOrbiterF, 10U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aCross, 5U) + aOrbiterI) + RotL64(aOrbiterB, 29U)) + RotL64(aNonceWordD, 41U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 52U) + RotL64(aOrbiterA, 38U)) + aOrbiterK);
            aWandererD = aWandererD + (((RotL64(aPrevious, 39U) + aOrbiterD) + RotL64(aOrbiterF, 43U)) + RotL64(aCarry, 47U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 47U) + aOrbiterK) + RotL64(aOrbiterF, 57U)) + aPhaseCWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aCross, 19U) + aOrbiterG) + RotL64(aOrbiterI, 19U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterI, 5U)) + aOrbiterD);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 11U) + RotL64(aOrbiterE, 23U)) + aOrbiterJ) + RotL64(aCarry, 5U)) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 23U) + aOrbiterE) + RotL64(aOrbiterA, 13U));
            aWandererC = aWandererC + (((RotL64(aScatter, 60U) + RotL64(aOrbiterG, 34U)) + aOrbiterJ) + RotL64(aNonceWordC, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 21U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 37U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 34U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 23U) ^ RotL64(aNonceWordE, 14U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 13093U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneD[((aIndex + 14554U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 51U) ^ RotL64(aNonceWordF, 43U)) ^ RotL64(aNonceWordA, 10U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 14606U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 12620U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCross, 35U) ^ RotL64(aIngress, 21U)) + (RotL64(aCarry, 4U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterF = (aWandererD + RotL64(aScatter, 6U)) + 12262991801139086177U;
            aOrbiterE = ((aWandererE + RotL64(aIngress, 27U)) + 7963038771924890197U) + aPhaseCOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = (((aWandererC + RotL64(aCross, 11U)) + RotL64(aCarry, 35U)) + 15540520327933568896U) + aPhaseCOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 35U)) + 8745565892055020722U) + RotL64(aNonceWordA, 53U);
            aOrbiterA = (aWandererK + RotL64(aScatter, 19U)) + 16619329199683755286U;
            aOrbiterK = (aWandererA + RotL64(aIngress, 51U)) + 10865705026433867260U;
            aOrbiterI = (aWandererB + RotL64(aCross, 57U)) + 2743368697984518059U;
            aOrbiterC = (((aWandererH + RotL64(aPrevious, 44U)) + RotL64(aCarry, 5U)) + 5556006271515473135U) + RotL64(aNonceWordF, 8U);
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 23U)) + RotL64(aCarry, 43U)) + 5355833281353498588U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 8313616108963479829U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 16657121016801866434U;
            aOrbiterH = RotL64((aOrbiterH * 331533349428472477U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 16532226425013000833U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 5800465874932467232U;
            aOrbiterA = RotL64((aOrbiterA * 5966395771690704577U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 17882948163883121328U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 15029375310296563175U;
            aOrbiterI = RotL64((aOrbiterI * 17021415832288477713U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 10170682648007918739U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 11829089574189398773U;
            aOrbiterC = RotL64((aOrbiterC * 15755874363488568849U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 1746524867389196322U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 10217423427886742775U;
            aOrbiterJ = RotL64((aOrbiterJ * 9166162099575333519U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 1338457710729082656U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 1319981417675542556U) ^ RotL64(aNonceWordD, 29U);
            aOrbiterF = RotL64((aOrbiterF * 9518448254565489715U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 3985281993069194761U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 7281264481139915593U;
            aOrbiterB = RotL64((aOrbiterB * 13498446162967276739U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 17394503335338855566U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 1430703546991948227U;
            aOrbiterK = RotL64((aOrbiterK * 1623206122475721175U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 472559435062214929U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 8065899137826178995U) ^ RotL64(aNonceWordC, 51U);
            aOrbiterE = RotL64((aOrbiterE * 13287499768933229539U), 29U);
            //
            aIngress = RotL64(aOrbiterB, 60U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterE, 41U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterA, 47U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterK, 24U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterA, 19U)) + aOrbiterC);
            aWandererC = aWandererC + ((((RotL64(aIngress, 58U) + RotL64(aOrbiterK, 58U)) + aOrbiterH) + RotL64(aCarry, 27U)) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((((RotL64(aScatter, 43U) + aOrbiterB) + RotL64(aOrbiterH, 37U)) + RotL64(aNonceWordG, 55U)) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 35U) + aOrbiterC) + RotL64(aOrbiterB, 51U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterA, 23U)) + aOrbiterK);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 11U) + aOrbiterJ) + RotL64(aOrbiterE, 4U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterJ, 27U)) + aOrbiterK) + RotL64(aNonceWordB, 45U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterB, 41U)) + aOrbiterI) + RotL64(aCarry, 13U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 52U) + aOrbiterF) + RotL64(aOrbiterC, 47U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 10U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 13U));
            aCarry = aCarry + RotL64(aWandererA, 58U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 54U) ^ RotL64(aNonceWordE, 35U)) ^ RotL64(aNonceWordC, 3U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 22733U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((aIndex + 17641U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 4U) ^ RotL64(aNonceWordG, 13U)) ^ RotL64(aNonceWordB, 57U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 21259U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneC[((aIndex + 20442U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 37U) ^ RotL64(aIngress, 3U)) + (RotL64(aCross, 18U) ^ RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 51U)) + 13854738573712660276U) + RotL64(aNonceWordB, 7U);
            aOrbiterF = ((aWandererC + RotL64(aIngress, 57U)) + 16835460633412286294U) + RotL64(aNonceWordA, 49U);
            aOrbiterA = (aWandererJ + RotL64(aCross, 34U)) + 6785859293758091931U;
            aOrbiterE = ((aWandererD + RotL64(aScatter, 29U)) + 126317283127992659U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = ((aWandererE + RotL64(aCross, 11U)) + RotL64(aCarry, 13U)) + 7568963536291415413U;
            aOrbiterD = ((aWandererA + RotL64(aScatter, 21U)) + RotL64(aCarry, 41U)) + 12294016745653004819U;
            aOrbiterC = ((aWandererI + RotL64(aIngress, 5U)) + 18269588932920281147U) + aPhaseCOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 44U)) + RotL64(aCarry, 57U)) + 5872406424994751026U;
            aOrbiterB = (aWandererK + RotL64(aCross, 39U)) + 7764434758831474129U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 4804168969415573371U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 959601763507651280U;
            aOrbiterA = RotL64((aOrbiterA * 4647396592804833217U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 9257644462479293048U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 14332699366894494579U) ^ RotL64(aNonceWordC, 5U);
            aOrbiterJ = RotL64((aOrbiterJ * 8829304078930625541U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 10487012596470786004U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 612729229562321440U;
            aOrbiterE = RotL64((aOrbiterE * 11380387280507726003U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 7845523921295625315U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 12742115479740024747U;
            aOrbiterF = RotL64((aOrbiterF * 15578543510683986421U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 10294667720904610944U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 14369711143154904567U;
            aOrbiterI = RotL64((aOrbiterI * 13753005602288309379U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 10918344717497681894U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 18136794828308636957U;
            aOrbiterD = RotL64((aOrbiterD * 17899418637978002409U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 14378638206724886404U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 7077588188450008059U;
            aOrbiterC = RotL64((aOrbiterC * 485375960462924335U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 8941870012851971932U) + RotL64(aNonceWordH, 31U);
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 15242087859620352399U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4963002810455992839U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 10395280254030875387U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 6826595516076975980U;
            aOrbiterB = RotL64((aOrbiterB * 6198886240333178001U), 13U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterF, 11U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 3U));
            aIngress = aIngress + (RotL64(aOrbiterI, 30U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 23U));
            aIngress = aIngress + RotL64(aOrbiterE, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 51U) + aOrbiterE) + RotL64(aOrbiterA, 11U)) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aCross, 27U) + RotL64(aOrbiterC, 41U)) + aOrbiterH);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 46U) + RotL64(aOrbiterF, 19U)) + aOrbiterI);
            aWandererK = aWandererK + ((RotL64(aScatter, 35U) + aOrbiterH) + RotL64(aOrbiterI, 56U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 39U) + aOrbiterD) + RotL64(aOrbiterI, 35U));
            aWandererI = aWandererI + ((((RotL64(aScatter, 3U) + aOrbiterB) + RotL64(aOrbiterD, 5U)) + RotL64(aCarry, 47U)) + RotL64(aNonceWordD, 45U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 60U) + aOrbiterJ) + RotL64(aOrbiterE, 23U)) + RotL64(aNonceWordG, 10U));
            aWandererE = aWandererE + ((((RotL64(aCross, 21U) + RotL64(aOrbiterD, 46U)) + aOrbiterH) + RotL64(aCarry, 21U)) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterA, 27U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 26U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 51U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererJ, 36U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 47U) ^ RotL64(aNonceWordC, 13U)) ^ RotL64(aNonceWordE, 38U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 25013U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26296U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 36U) ^ RotL64(aNonceWordD, 11U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 29134U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 26897U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCross, 51U) ^ RotL64(aIngress, 27U)) + (RotL64(aPrevious, 39U) + RotL64(aCarry, 14U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterK = (((aWandererE + RotL64(aIngress, 20U)) + 9133751643283278896U) + aPhaseCOrbiterAssignSaltC[((aIndex + 12U)) & S_SALT1]) + RotL64(aNonceWordC, 23U);
            aOrbiterH = ((aWandererI + RotL64(aCross, 57U)) + RotL64(aCarry, 3U)) + 8971581804375380408U;
            aOrbiterE = (aWandererK + RotL64(aScatter, 35U)) + 12559650383714566592U;
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 39U)) + 15753206088872859163U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = (aWandererJ + RotL64(aCross, 51U)) + 7640756270450762350U;
            aOrbiterA = (aWandererH + RotL64(aIngress, 5U)) + 7340073357551376125U;
            aOrbiterF = (aWandererA + RotL64(aPrevious, 43U)) + 5270256573644196046U;
            aOrbiterC = (((aWandererG + RotL64(aScatter, 10U)) + RotL64(aCarry, 27U)) + 3567367996479995928U) + RotL64(aNonceWordB, 45U);
            aOrbiterB = ((aWandererB + RotL64(aIngress, 47U)) + RotL64(aCarry, 11U)) + 11939634537492733738U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 7051817732424527120U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 1730487669951837941U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15191634337956285841U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 18009252467909454817U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 2361024272031696442U;
            aOrbiterD = RotL64((aOrbiterD * 15215151562500226027U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 15902755877642960397U) + RotL64(aNonceWordF, 39U);
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 12243517544704116184U;
            aOrbiterF = RotL64((aOrbiterF * 2576071074148141447U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 16846181962302186187U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 636121425116506681U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17075030673338779993U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 6887385655828217318U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 3705834550934775862U;
            aOrbiterJ = RotL64((aOrbiterJ * 11275428284929594435U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 11165142437077969438U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 6426659930331618269U;
            aOrbiterA = RotL64((aOrbiterA * 17170640810530893705U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 12629082390899315789U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 4277510580069574724U;
            aOrbiterC = RotL64((aOrbiterC * 9829125163412708305U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 13814834144170469978U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 3698381854100295826U;
            aOrbiterB = RotL64((aOrbiterB * 5126359230872258015U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 11623170635983579937U) + RotL64(aNonceWordH, 11U);
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 7247413650388803796U;
            aOrbiterH = RotL64((aOrbiterH * 3403219499465560059U), 43U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterH, 53U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 27U));
            aIngress = aIngress + (RotL64(aOrbiterD, 6U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + RotL64(aOrbiterF, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aPrevious, 4U) + RotL64(aOrbiterB, 27U)) + aOrbiterJ) + RotL64(aCarry, 53U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 23U) + aOrbiterA) + RotL64(aOrbiterE, 41U));
            aWandererA = aWandererA + (((RotL64(aIngress, 57U) + RotL64(aOrbiterK, 23U)) + aOrbiterF) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterA, 6U)) + aOrbiterK) + aPhaseCWandererUpdateSaltC[((aIndex + 16U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 43U) + aOrbiterE) + RotL64(aOrbiterD, 35U)) + RotL64(aNonceWordG, 31U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 19U) + aOrbiterE) + RotL64(aOrbiterH, 11U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 27U) + RotL64(aOrbiterH, 57U)) + aOrbiterJ) + RotL64(aCarry, 21U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 11U) + aOrbiterE) + RotL64(aOrbiterJ, 50U)) + RotL64(aNonceWordD, 58U));
            aWandererG = aWandererG + ((RotL64(aIngress, 36U) + aOrbiterF) + RotL64(aOrbiterC, 19U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 19U));
            aCarry = aCarry + (RotL64(aWandererD, 41U) ^ aWandererA);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 46U));
            aCarry = aCarry + RotL64(aWandererJ, 53U);
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

void TwistExpander_Archery_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x8C34FF0F803DC61FULL + 0xA280B9FFB185F72EULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xBDCEB947618F967FULL + 0xAE9579F8FB209620ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xDD15D4D9D11F67EDULL + 0xE1C8609EC9D7A756ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x9FC430D175832F11ULL + 0xD1217F4D743EAD90ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xA4610DFA88CAD813ULL + 0xE2D4F5998F53A709ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xAA84ADC0507A2C75ULL + 0xC8D4FF98D00CFAC0ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xA4AAEF493F05FEDBULL + 0xD4625F5D37FC8A71ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xACFF3068F65DB721ULL + 0xF85EAA051D8488DCULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 26U) ^ RotL64(aNonceWordG, 43U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 985U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5299U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 20U) ^ RotL64(aNonceWordD, 37U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 1037U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 3899U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 51U) ^ RotL64(aIngress, 4U)) + (RotL64(aCross, 21U) + RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterD = (aWandererA + RotL64(aPrevious, 35U)) + 3973833383430652211U;
            aOrbiterH = (aWandererD + RotL64(aScatter, 46U)) + 5760227042747169187U;
            aOrbiterI = ((aWandererH + RotL64(aIngress, 3U)) + 4923009065139227286U) + RotL64(aNonceWordE, 19U);
            aOrbiterJ = ((aWandererC + RotL64(aCross, 51U)) + RotL64(aCarry, 21U)) + 1477807307009107590U;
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 13U)) + 5707194514329007301U;
            aOrbiterC = (aWandererK + RotL64(aCross, 56U)) + 5340439728375269724U;
            aOrbiterE = (aWandererF + RotL64(aIngress, 43U)) + 17080457898946572387U;
            aOrbiterA = ((aWandererE + RotL64(aScatter, 23U)) + 281559150259472813U) + RotL64(aNonceWordF, 59U);
            aOrbiterB = ((aWandererI + RotL64(aIngress, 19U)) + 16160633048230910560U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = (((aWandererG + RotL64(aPrevious, 41U)) + RotL64(aCarry, 39U)) + 9003989610509592121U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = ((aWandererB + RotL64(aScatter, 37U)) + RotL64(aCarry, 29U)) + 10579322462808454333U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 15059383289528723069U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 10417647757852880956U;
            aOrbiterI = RotL64((aOrbiterI * 1457919230286043137U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 14484665027393813330U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 12344463053485837974U;
            aOrbiterC = RotL64((aOrbiterC * 5762654194001525041U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 5826453246659297805U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 12547902286376986223U;
            aOrbiterD = RotL64((aOrbiterD * 2982850000322672789U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 9637855144278126174U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 2132744427444501938U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5911587798564836199U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 9248933938130311231U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 13274297928717090383U;
            aOrbiterE = RotL64((aOrbiterE * 2901398809555237563U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 3690262236918560930U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 3626005326410800344U;
            aOrbiterB = RotL64((aOrbiterB * 13030443356669355355U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 10801089744186148218U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterG) ^ 5446653082176311031U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]) ^ RotL64(aNonceWordB, 26U);
            aOrbiterF = RotL64((aOrbiterF * 4594267575901248321U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 3205541585889107366U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 4532327942368884436U;
            aOrbiterH = RotL64((aOrbiterH * 16287094987689326229U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 9755333481079721632U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 722154154363571049U;
            aOrbiterG = RotL64((aOrbiterG * 11002432494248958957U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 8071668483354405205U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 8770466248803121315U;
            aOrbiterA = RotL64((aOrbiterA * 12780438190628717807U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 1999251593502332271U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 3973833383430652211U) ^ RotL64(aNonceWordA, 29U);
            aOrbiterK = RotL64((aOrbiterK * 5325244982474631559U), 27U);
            //
            aIngress = RotL64(aOrbiterD, 44U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterI, 51U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 35U));
            aIngress = aIngress + (RotL64(aOrbiterG, 27U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterK, 5U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterJ, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 23U) + aOrbiterI) + RotL64(aOrbiterB, 60U)) + RotL64(aNonceWordC, 47U));
            aWandererA = aWandererA + (((RotL64(aScatter, 4U) + aOrbiterF) + RotL64(aOrbiterG, 47U)) + RotL64(aCarry, 19U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterA, 37U)) + aOrbiterI);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 13U) + aOrbiterH) + RotL64(aOrbiterK, 23U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterA, 57U)) + aOrbiterH);
            aWandererB = aWandererB + (((RotL64(aScatter, 53U) + RotL64(aOrbiterC, 41U)) + aOrbiterG) + RotL64(aNonceWordG, 13U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterK, 21U)) + aOrbiterC);
            aWandererK = aWandererK + ((RotL64(aIngress, 41U) + RotL64(aOrbiterJ, 29U)) + aOrbiterE);
            aWandererF = aWandererF ^ ((RotL64(aCross, 60U) + aOrbiterI) + RotL64(aOrbiterJ, 10U));
            aWandererD = aWandererD + ((((RotL64(aPrevious, 27U) + aOrbiterH) + RotL64(aOrbiterD, 35U)) + RotL64(aCarry, 13U)) + aPhaseDWandererUpdateSaltF[((aIndex + 4U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 19U) + aOrbiterK) + RotL64(aOrbiterD, 13U)) + aPhaseDWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererA, 41U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererF, 6U) ^ aWandererC);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + RotL64(aWandererI, 19U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 29U) ^ RotL64(aNonceWordB, 51U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 10782U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneD[((aIndex + 7665U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 19U) ^ RotL64(aNonceWordA, 56U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7965U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 5465U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 20U) ^ RotL64(aPrevious, 5U)) ^ (RotL64(aCarry, 57U) + RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterK = (aWandererF + RotL64(aIngress, 23U)) + 16462052553719977502U;
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 51U)) + 12337064059566619581U) + aPhaseDOrbiterAssignSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterG = ((aWandererK + RotL64(aCross, 10U)) + 15801005007094515447U) + RotL64(aNonceWordA, 19U);
            aOrbiterI = ((aWandererE + RotL64(aScatter, 29U)) + RotL64(aCarry, 37U)) + 8228706742665081656U;
            aOrbiterF = ((aWandererG + RotL64(aIngress, 5U)) + RotL64(aCarry, 47U)) + 11006723027845190869U;
            aOrbiterE = (aWandererI + RotL64(aCross, 57U)) + 18173765337829177450U;
            aOrbiterD = ((aWandererC + RotL64(aScatter, 3U)) + 530215083653542558U) + aPhaseDOrbiterAssignSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 13U)) + RotL64(aCarry, 29U)) + 6608611827035564511U;
            aOrbiterA = (aWandererD + RotL64(aCross, 41U)) + 2246051826221626809U;
            aOrbiterC = ((aWandererH + RotL64(aIngress, 19U)) + 5228575308895381421U) + RotL64(aNonceWordH, 9U);
            aOrbiterB = (aWandererB + RotL64(aPrevious, 54U)) + 10999213210689606857U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 3773371037240485696U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 8887985779436152504U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 698713082830739677U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 11150566414723818350U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 8336366151003049546U;
            aOrbiterJ = RotL64((aOrbiterJ * 9033771197242493699U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 13233968794237090787U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 8172558473508478819U;
            aOrbiterF = RotL64((aOrbiterF * 17837070423649268435U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 133564480283347997U) + RotL64(aNonceWordF, 31U);
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 15104810248883567064U;
            aOrbiterD = RotL64((aOrbiterD * 706802420642303533U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 9138629520201127075U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 13993086066341664080U;
            aOrbiterA = RotL64((aOrbiterA * 4875046427147105077U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 6547273508580516932U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 9838727018769865759U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11395273371936839815U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 11685694999526122626U) + RotL64(aNonceWordD, 21U);
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 8945983172566303116U;
            aOrbiterI = RotL64((aOrbiterI * 17791527981004597623U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 17606249889617356327U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 9296903152000480008U;
            aOrbiterE = RotL64((aOrbiterE * 18066622289408024413U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 14248192861977167583U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 5467843420970464193U;
            aOrbiterH = RotL64((aOrbiterH * 10121398470914323221U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 17072313558131700643U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 7932446176598954438U;
            aOrbiterC = RotL64((aOrbiterC * 11684711939539349335U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 15377107166135929052U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 16462052553719977502U;
            aOrbiterB = RotL64((aOrbiterB * 9057188521274832217U), 51U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterB, 39U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 35U));
            aIngress = aIngress + (RotL64(aOrbiterI, 37U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 41U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 30U));
            aIngress = aIngress + RotL64(aOrbiterD, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((((RotL64(aCross, 29U) + aOrbiterI) + RotL64(aOrbiterG, 39U)) + RotL64(aNonceWordC, 18U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterG, 43U)) + aOrbiterF) + aPhaseDWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 48U) + RotL64(aOrbiterB, 41U)) + aOrbiterD);
            aWandererF = aWandererF + ((RotL64(aIngress, 11U) + RotL64(aOrbiterC, 26U)) + aOrbiterJ);
            aWandererG = aWandererG ^ ((RotL64(aCross, 41U) + aOrbiterA) + RotL64(aOrbiterD, 57U));
            aWandererA = aWandererA + ((RotL64(aScatter, 39U) + RotL64(aOrbiterI, 11U)) + aOrbiterK);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 21U) + aOrbiterE) + RotL64(aOrbiterG, 3U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 46U) + RotL64(aOrbiterJ, 21U)) + aOrbiterA) + RotL64(aCarry, 53U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 13U) + aOrbiterC) + RotL64(aOrbiterE, 46U)) + RotL64(aNonceWordG, 39U));
            aWandererK = aWandererK + (((RotL64(aIngress, 5U) + RotL64(aOrbiterC, 51U)) + aOrbiterF) + RotL64(aCarry, 11U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterH, 53U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 60U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 5U));
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 41U));
            aCarry = aCarry + RotL64(aWandererJ, 47U);
            aCarry = aCarry + RotL64(aIngress, 18U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 21U) ^ RotL64(aNonceWordH, 41U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 11048U)) & S_BLOCK1], 12U) ^ RotL64(aOperationLaneA[((aIndex + 14049U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 58U) ^ RotL64(aNonceWordC, 29U)) ^ RotL64(aNonceWordB, 21U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 10984U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneC[((aIndex + 16346U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 52U) + RotL64(aPrevious, 21U)) ^ (RotL64(aIngress, 3U) + RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterD = ((aWandererF + RotL64(aScatter, 27U)) + 9855743441035905047U) + aPhaseDOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 13U)) + 8426286937143990276U) + RotL64(aNonceWordB, 11U);
            aOrbiterE = (aWandererH + RotL64(aCross, 43U)) + 7146752367170267002U;
            aOrbiterH = (aWandererD + RotL64(aIngress, 19U)) + 12947210066678101726U;
            aOrbiterB = (aWandererK + RotL64(aPrevious, 41U)) + 15902163559925328965U;
            aOrbiterJ = ((aWandererG + RotL64(aCross, 5U)) + 8506649889346449469U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = ((aWandererB + RotL64(aIngress, 34U)) + 8226286036430263052U) + RotL64(aNonceWordG, 42U);
            aOrbiterC = ((aWandererE + RotL64(aScatter, 57U)) + RotL64(aCarry, 3U)) + 2703047093452420216U;
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 3U)) + RotL64(aCarry, 41U)) + 6769351326360139560U;
            aOrbiterG = ((aWandererC + RotL64(aCross, 51U)) + RotL64(aCarry, 51U)) + 9857025533281333281U;
            aOrbiterA = (aWandererJ + RotL64(aIngress, 60U)) + 238297452132277585U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 7203572312072908931U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 12497027346166575632U;
            aOrbiterE = RotL64((aOrbiterE * 1703586436725662307U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 473851890609048879U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 1664484956453886047U;
            aOrbiterJ = RotL64((aOrbiterJ * 8566500756326590209U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 4635095143004754116U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 17695676150967345793U) ^ RotL64(aNonceWordA, 15U);
            aOrbiterK = RotL64((aOrbiterK * 5780416541584439301U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 15628965269863402796U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 9190117464399730235U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5586437438425999715U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 17835918238346011086U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 4398005402429282682U;
            aOrbiterC = RotL64((aOrbiterC * 14828737209913317463U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 10902589938246551273U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 15124274429081385923U;
            aOrbiterG = RotL64((aOrbiterG * 13524180348258805367U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 8747233520702236018U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 5445611443463112371U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10294109295823410447U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 16296005217836151910U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 6468336224317602364U;
            aOrbiterH = RotL64((aOrbiterH * 7369779919748367133U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 3827976387089403774U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 7773383658122100111U;
            aOrbiterF = RotL64((aOrbiterF * 9784711300597525161U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 18273794621528918389U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 8401424792700263455U) ^ RotL64(aNonceWordD, 9U);
            aOrbiterI = RotL64((aOrbiterI * 13003420427441089595U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 11402828934846813949U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 9855743441035905047U;
            aOrbiterA = RotL64((aOrbiterA * 7339549576423555273U), 29U);
            //
            aIngress = RotL64(aOrbiterG, 36U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 21U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 11U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 51U));
            aIngress = aIngress + RotL64(aOrbiterC, 34U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterI, 57U)) + aOrbiterG);
            aWandererE = aWandererE + (((RotL64(aCross, 40U) + RotL64(aOrbiterI, 5U)) + aOrbiterJ) + RotL64(aNonceWordE, 57U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 57U) + aOrbiterD) + RotL64(aOrbiterI, 51U));
            aWandererF = aWandererF + ((RotL64(aScatter, 53U) + aOrbiterE) + RotL64(aOrbiterA, 48U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 21U) + aOrbiterE) + RotL64(aOrbiterF, 3U));
            aWandererI = aWandererI + (((RotL64(aScatter, 5U) + aOrbiterC) + RotL64(aOrbiterB, 19U)) + RotL64(aCarry, 37U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterD, 13U)) + aOrbiterG);
            aWandererK = aWandererK + (((((RotL64(aPrevious, 13U) + aOrbiterB) + RotL64(aOrbiterK, 35U)) + RotL64(aCarry, 53U)) + RotL64(aNonceWordF, 13U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterF, 54U)) + aOrbiterA);
            aWandererA = aWandererA + (((RotL64(aIngress, 42U) + RotL64(aOrbiterB, 29U)) + aOrbiterH) + aPhaseDWandererUpdateSaltB[((aIndex + 8U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterK, 11U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 58U));
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererA);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 5U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 19U));
            aCarry = aCarry + (RotL64(aWandererH, 41U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererI, 11U);
            aCarry = aCarry + RotL64(aIngress, 54U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 4U) ^ RotL64(aNonceWordB, 13U)) ^ RotL64(aNonceWordC, 53U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 16411U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneB[((aIndex + 18842U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 19U) ^ RotL64(aNonceWordG, 11U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 20079U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19523U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 35U) ^ RotL64(aCarry, 21U)) ^ (RotL64(aCross, 54U) + RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterB = ((aWandererC + RotL64(aScatter, 11U)) + 11480359716598965890U) + RotL64(aNonceWordA, 44U);
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 47U)) + RotL64(aCarry, 51U)) + 15431182525482873419U;
            aOrbiterF = (aWandererK + RotL64(aCross, 37U)) + 11360504974812776707U;
            aOrbiterK = ((aWandererH + RotL64(aIngress, 23U)) + RotL64(aCarry, 29U)) + 9292576416573382769U;
            aOrbiterH = ((aWandererE + RotL64(aCross, 43U)) + 1549257414531028975U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = (aWandererG + RotL64(aScatter, 30U)) + 5347769463033129317U;
            aOrbiterJ = (aWandererA + RotL64(aIngress, 19U)) + 17019199177478377234U;
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 35U)) + 16558106007323125094U) + aPhaseDOrbiterAssignSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterA = (aWandererF + RotL64(aIngress, 3U)) + 3976182233825939422U;
            aOrbiterG = (aWandererD + RotL64(aCross, 5U)) + 2889047161195954395U;
            aOrbiterE = (((aWandererI + RotL64(aScatter, 50U)) + RotL64(aCarry, 57U)) + 2241831345026962605U) + RotL64(aNonceWordD, 9U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 12850802412140579294U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 13541744735436450160U;
            aOrbiterF = RotL64((aOrbiterF * 906089290000537439U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 2085863085516538212U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 2969034221711544086U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7768528124408400403U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 6482666944512391472U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 16969153556875844613U) ^ RotL64(aNonceWordE, 11U);
            aOrbiterD = RotL64((aOrbiterD * 9483462388353216219U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 5161314086757363678U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterF) ^ 7150282484670673211U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1]) ^ RotL64(aNonceWordF, 49U);
            aOrbiterJ = RotL64((aOrbiterJ * 8522427002337918663U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 5465304381272305847U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 2344610773390354017U;
            aOrbiterC = RotL64((aOrbiterC * 17010258514288089191U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 8335906578006588582U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 13668796013474193793U;
            aOrbiterA = RotL64((aOrbiterA * 8228000547141147777U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 9663362594301419686U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 3683773739120343413U;
            aOrbiterG = RotL64((aOrbiterG * 8319320803406104749U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 2538583190438044942U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 4454069062219406996U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16329554225309389599U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 17177136683616247897U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 3680497519697457252U;
            aOrbiterB = RotL64((aOrbiterB * 6479357366957384599U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 16812938441063719463U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 4545693142067578891U;
            aOrbiterI = RotL64((aOrbiterI * 17479957806084346527U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 9232311730019478327U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 11480359716598965890U;
            aOrbiterK = RotL64((aOrbiterK * 6678546065399772697U), 19U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterF, 13U);
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 60U));
            aIngress = aIngress + (RotL64(aOrbiterH, 43U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterG, 47U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterJ, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aCross, 27U) + RotL64(aOrbiterC, 47U)) + aOrbiterF) + RotL64(aCarry, 29U)) + RotL64(aNonceWordG, 55U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 13U) + aOrbiterI) + RotL64(aOrbiterD, 39U)) + aPhaseDWandererUpdateSaltF[((aIndex + 26U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 10U) + RotL64(aOrbiterA, 30U)) + aOrbiterG);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterA, 53U)) + aOrbiterB) + RotL64(aNonceWordH, 13U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 51U) + aOrbiterI) + RotL64(aOrbiterG, 35U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterC, 21U)) + aOrbiterB) + aPhaseDWandererUpdateSaltA[((aIndex + 14U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aIngress, 43U) + aOrbiterK) + RotL64(aOrbiterD, 23U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterE, 11U)) + aOrbiterK);
            aWandererK = aWandererK + ((RotL64(aIngress, 39U) + RotL64(aOrbiterD, 43U)) + aOrbiterJ);
            aWandererH = aWandererH ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterH, 37U)) + aOrbiterA);
            aWandererG = aWandererG + (((RotL64(aPrevious, 46U) + RotL64(aOrbiterK, 58U)) + aOrbiterA) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 48U));
            aCarry = aCarry + (RotL64(aWandererK, 39U) ^ aWandererF);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererA);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 14U));
            aCarry = aCarry + RotL64(aWandererI, 5U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 34U) ^ RotL64(aNonceWordD, 13U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 26741U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((aIndex + 24405U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 27U) ^ RotL64(aNonceWordB, 37U)) ^ RotL64(aNonceWordG, 47U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 24759U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 22211U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 21U) ^ RotL64(aIngress, 35U)) ^ (RotL64(aCarry, 47U) + RotL64(aPrevious, 4U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterJ = ((aWandererH + RotL64(aPrevious, 23U)) + 6318740973868639425U) + aPhaseDOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = ((aWandererA + RotL64(aIngress, 42U)) + 5487840061430920881U) + RotL64(aNonceWordB, 13U);
            aOrbiterF = (aWandererG + RotL64(aCross, 5U)) + 10258706763248072672U;
            aOrbiterK = ((aWandererF + RotL64(aScatter, 51U)) + RotL64(aCarry, 53U)) + 18356875269730338208U;
            aOrbiterE = (aWandererJ + RotL64(aIngress, 53U)) + 12883160282903147010U;
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 39U)) + RotL64(aCarry, 11U)) + 1010140474942697730U;
            aOrbiterI = ((aWandererE + RotL64(aScatter, 19U)) + 17733939421700898293U) + aPhaseDOrbiterAssignSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = ((aWandererD + RotL64(aCross, 29U)) + RotL64(aCarry, 35U)) + 13693055887924981201U;
            aOrbiterA = (aWandererI + RotL64(aScatter, 36U)) + 14574732452793385269U;
            aOrbiterG = (aWandererB + RotL64(aPrevious, 21U)) + 10832873941223609012U;
            aOrbiterB = ((aWandererK + RotL64(aCross, 47U)) + 8212600587135328040U) + RotL64(aNonceWordH, 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 5312744319781971178U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 6173741211706546923U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12854414066390848249U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 3693249147883790810U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 18365859989736602556U;
            aOrbiterH = RotL64((aOrbiterH * 3348463719324104997U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 10645056678337549771U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 1175668356822251045U) ^ RotL64(aNonceWordC, 59U);
            aOrbiterC = RotL64((aOrbiterC * 6579675292775345579U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 13556844570541823717U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 4790355739411849736U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4083544011788850307U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 14905575502272644116U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 17047244574558476634U;
            aOrbiterJ = RotL64((aOrbiterJ * 2356386971503880047U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 10161614295718414869U) + RotL64(aNonceWordA, 41U);
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 13413914082651612468U;
            aOrbiterK = RotL64((aOrbiterK * 16224039093981079491U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 6072693130156927774U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 4333656233793103787U;
            aOrbiterI = RotL64((aOrbiterI * 9374745547133955709U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 17209776289202130250U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 11752001118070361543U;
            aOrbiterA = RotL64((aOrbiterA * 4416523594812872339U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 15367365111105608277U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 8650687767097460704U;
            aOrbiterB = RotL64((aOrbiterB * 11430451559660578667U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 18074648514448405693U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 10857586858462237581U;
            aOrbiterD = RotL64((aOrbiterD * 3722891011080095849U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 17219932344278345591U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 6318740973868639425U;
            aOrbiterE = RotL64((aOrbiterE * 8846295038878812229U), 53U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterK, 11U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 47U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 35U));
            aIngress = aIngress + (RotL64(aOrbiterA, 5U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 18U));
            aIngress = aIngress + RotL64(aOrbiterF, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aScatter, 13U) + RotL64(aOrbiterB, 57U)) + aOrbiterC) + RotL64(aCarry, 53U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 23U) + aOrbiterE) + RotL64(aOrbiterG, 53U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 21U) + aOrbiterH) + RotL64(aOrbiterF, 36U)) + RotL64(aNonceWordD, 38U)) + aPhaseDWandererUpdateSaltC[((aIndex + 26U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 50U) + aOrbiterI) + RotL64(aOrbiterH, 3U));
            aWandererE = aWandererE + ((RotL64(aScatter, 27U) + RotL64(aOrbiterH, 27U)) + aOrbiterJ);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterE, 5U)) + aOrbiterJ);
            aWandererJ = aWandererJ + ((RotL64(aCross, 41U) + aOrbiterF) + RotL64(aOrbiterA, 11U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 19U) + aOrbiterC) + RotL64(aOrbiterI, 44U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterH, 13U)) + aOrbiterD) + RotL64(aCarry, 13U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterK, 39U)) + aOrbiterD) + RotL64(aNonceWordE, 25U));
            aWandererC = aWandererC + ((RotL64(aScatter, 10U) + aOrbiterI) + RotL64(aOrbiterK, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 60U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 21U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 10U));
            aCarry = aCarry + RotL64(aWandererG, 39U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 5U) ^ RotL64(aNonceWordB, 48U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 30999U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneB[((aIndex + 29738U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 53U) ^ RotL64(aNonceWordF, 5U)) ^ RotL64(aNonceWordC, 23U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 30601U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29947U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aPrevious, 27U)) ^ (RotL64(aIngress, 39U) ^ RotL64(aCarry, 12U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterC = (aWandererD + RotL64(aScatter, 29U)) + 16160838483846078448U;
            aOrbiterK = (aWandererJ + RotL64(aIngress, 52U)) + 15404960896190227946U;
            aOrbiterG = ((aWandererG + RotL64(aPrevious, 57U)) + RotL64(aCarry, 57U)) + 16904160594024977199U;
            aOrbiterA = (aWandererI + RotL64(aCross, 27U)) + 17790460246821031802U;
            aOrbiterF = (aWandererA + RotL64(aIngress, 41U)) + 16395168254086971959U;
            aOrbiterD = (((aWandererE + RotL64(aCross, 11U)) + 7484373204039901786U) + aPhaseDOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1]) + RotL64(aNonceWordB, 45U);
            aOrbiterH = (aWandererK + RotL64(aPrevious, 37U)) + 18026814691322913510U;
            aOrbiterE = ((aWandererF + RotL64(aScatter, 21U)) + 15244817793136966450U) + aPhaseDOrbiterAssignSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 44U)) + 5795491730356335666U) + RotL64(aNonceWordF, 43U);
            aOrbiterI = ((aWandererH + RotL64(aCross, 13U)) + RotL64(aCarry, 41U)) + 3163873518027801504U;
            aOrbiterJ = ((aWandererB + RotL64(aScatter, 5U)) + RotL64(aCarry, 3U)) + 2690791759507349172U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 17898067251167087906U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 8028010015006604239U;
            aOrbiterG = RotL64((aOrbiterG * 5601629670521300241U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 7304739457289910555U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 6476837815096530043U;
            aOrbiterF = RotL64((aOrbiterF * 16380545138701113267U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 14242499233467960602U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 17305645693017634630U;
            aOrbiterD = RotL64((aOrbiterD * 14442976693206929569U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 9772864059444171908U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 7897200728282156408U;
            aOrbiterH = RotL64((aOrbiterH * 816306719390807411U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 4890999319172950996U) + RotL64(aNonceWordD, 53U);
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 8165132649356094963U;
            aOrbiterE = RotL64((aOrbiterE * 17297706071263690189U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 9342923520083533265U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 7213639583505088067U;
            aOrbiterB = RotL64((aOrbiterB * 1349251979649428909U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 4079475132684197272U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 3350998022472827283U;
            aOrbiterI = RotL64((aOrbiterI * 948841791460066265U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 2479140576609216238U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 7703147534931674972U;
            aOrbiterJ = RotL64((aOrbiterJ * 11419116495223970801U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 9050277787914448469U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 13295888852307317371U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3027097172772140975U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 15380254190549884741U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 17653690414528791774U;
            aOrbiterK = RotL64((aOrbiterK * 15923958179714368315U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 6825072759468337036U) + RotL64(aNonceWordG, 12U);
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 16160838483846078448U;
            aOrbiterA = RotL64((aOrbiterA * 11690325563580492415U), 41U);
            //
            aIngress = RotL64(aOrbiterA, 29U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 37U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 5U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 21U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterE, 51U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterK, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterC, 26U)) + aOrbiterG);
            aWandererD = aWandererD + (((RotL64(aCross, 6U) + aOrbiterE) + RotL64(aOrbiterC, 51U)) + aPhaseDWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 19U) + aOrbiterB) + RotL64(aOrbiterF, 39U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 29U) + aOrbiterK) + RotL64(aOrbiterA, 47U)) + RotL64(aCarry, 5U));
            aWandererF = aWandererF ^ ((((RotL64(aScatter, 53U) + RotL64(aOrbiterD, 10U)) + aOrbiterI) + RotL64(aNonceWordA, 35U)) + aPhaseDWandererUpdateSaltE[((aIndex + 24U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 43U) + aOrbiterG) + RotL64(aOrbiterF, 37U)) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterH, 13U)) + aOrbiterD) + RotL64(aNonceWordE, 59U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 21U) + aOrbiterA) + RotL64(aOrbiterE, 5U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterA, 43U)) + aOrbiterJ);
            aWandererE = aWandererE + ((RotL64(aPrevious, 48U) + aOrbiterJ) + RotL64(aOrbiterD, 53U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterB, 57U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 29U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 44U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + (RotL64(aWandererI, 5U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererF, 23U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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

void TwistExpander_Archery_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xF882779FA9712C1FULL + 0xA9D25077901C4CE0ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xD2B552029356D84DULL + 0x9A6F17D198A2E667ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x9D295AA17F55CBDFULL + 0xECFA141CB6C42009ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xC9C49990149D8257ULL + 0xC29B3FEBF8EB17A3ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x890A91EC292CF9DDULL + 0x88D2DDAA1A36F1CBULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xA742D5735140FD95ULL + 0xB9F7CFBC1DAB5A49ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xE13F59792C5822B3ULL + 0x8CACBE7B83C12C4AULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xB20032C0D1843E2FULL + 0xF6CF4C89603481A1ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 35U) ^ RotL64(aNonceWordE, 3U));
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 5120U)) & S_BLOCK1], 52U) ^ RotL64(aWorkLaneC[((aIndex + 3104U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 29U) ^ RotL64(aNonceWordG, 53U)) ^ RotL64(aNonceWordH, 21U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 4527U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 2066U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 19U) ^ RotL64(aPrevious, 5U)) ^ (RotL64(aCross, 43U) + RotL64(aIngress, 56U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterE = ((aWandererB + RotL64(aScatter, 23U)) + 3199575576585871314U) + RotL64(aNonceWordB, 43U);
            aOrbiterA = ((aWandererI + RotL64(aCross, 29U)) + 2533378188975571824U) + RotL64(aNonceWordE, 11U);
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 27U)) + 6819782112558312658U) + aPhaseEOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 43U)) + RotL64(aCarry, 11U)) + 12690060987724798497U;
            aOrbiterH = ((aWandererC + RotL64(aCross, 41U)) + RotL64(aCarry, 37U)) + 7088375139715629606U;
            aOrbiterK = ((aWandererH + RotL64(aScatter, 52U)) + RotL64(aCarry, 27U)) + 17785618677423695666U;
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 37U)) + 1714999280296491277U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = (aWandererG + RotL64(aIngress, 13U)) + 17611338506932491624U;
            aOrbiterG = (aWandererE + RotL64(aPrevious, 35U)) + 6475727359297421201U;
            aOrbiterF = (aWandererJ + RotL64(aCross, 3U)) + 2347744591204119530U;
            aOrbiterD = (aWandererA + RotL64(aScatter, 56U)) + 2739317903351401068U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 8663535261373274338U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 8205245127823536479U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13857005110466856439U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 8916510616749754516U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 3944805940148512932U;
            aOrbiterK = RotL64((aOrbiterK * 18082271583211389701U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 14094751253118853302U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 14094299829196076311U) ^ RotL64(aNonceWordF, 49U);
            aOrbiterE = RotL64((aOrbiterE * 6370012560657108493U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 3940673811518673802U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 3015106523254484839U;
            aOrbiterJ = RotL64((aOrbiterJ * 9655401190755573379U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 15404103131982599922U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 1828655763233900875U;
            aOrbiterC = RotL64((aOrbiterC * 13024358077740310049U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 1236981890899916502U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 18208975564570342697U;
            aOrbiterG = RotL64((aOrbiterG * 4577109989465876801U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 17882273895471449661U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 16196010765612713713U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15624856645134182005U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 14639250100311162559U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 9139027997336903273U;
            aOrbiterA = RotL64((aOrbiterA * 1853126389565574293U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 16848571995585465845U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 15901000078517800358U;
            aOrbiterH = RotL64((aOrbiterH * 11617866400577762383U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 9405166641274108606U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 6776079798531281127U) ^ RotL64(aNonceWordG, 52U);
            aOrbiterB = RotL64((aOrbiterB * 6914644957401512339U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 15056085197286596847U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 3199575576585871314U;
            aOrbiterF = RotL64((aOrbiterF * 15940936753708416817U), 47U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterH, 41U);
            aIngress = aIngress + (RotL64(aOrbiterB, 53U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + (RotL64(aOrbiterF, 37U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 46U));
            aIngress = aIngress + RotL64(aOrbiterK, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aScatter, 37U) + aOrbiterI) + RotL64(aOrbiterB, 10U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 3U) + aOrbiterD) + RotL64(aOrbiterH, 51U));
            aWandererB = aWandererB + ((RotL64(aCross, 39U) + RotL64(aOrbiterK, 41U)) + aOrbiterF);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterC, 19U)) + aOrbiterD) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 57U) + RotL64(aOrbiterA, 47U)) + aOrbiterK) + RotL64(aCarry, 53U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterD, 30U)) + aOrbiterJ) + RotL64(aNonceWordC, 15U));
            aWandererE = aWandererE + (((RotL64(aIngress, 44U) + aOrbiterG) + RotL64(aOrbiterF, 39U)) + RotL64(aCarry, 57U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterF, 21U)) + aOrbiterC);
            aWandererH = aWandererH + (((RotL64(aIngress, 47U) + aOrbiterD) + RotL64(aOrbiterG, 3U)) + aPhaseEWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 41U) + aOrbiterH) + RotL64(aOrbiterB, 35U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 18U) + aOrbiterE) + RotL64(aOrbiterD, 37U)) + RotL64(aNonceWordA, 59U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 60U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererI);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 41U));
            aCarry = aCarry + RotL64(aWandererD, 14U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 3U) ^ RotL64(aNonceWordA, 35U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 8101U)) & S_BLOCK1], 22U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 8934U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 12U) ^ RotL64(aNonceWordF, 35U));
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 9081U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneB[((aIndex + 10765U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 40U) + RotL64(aIngress, 19U)) ^ (RotL64(aPrevious, 53U) + RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterI = (aWandererG + RotL64(aScatter, 58U)) + 10336802574069791273U;
            aOrbiterE = (aWandererE + RotL64(aIngress, 3U)) + 169025388197058936U;
            aOrbiterC = ((aWandererA + RotL64(aCross, 19U)) + RotL64(aCarry, 51U)) + 6541354188379168846U;
            aOrbiterD = (aWandererJ + RotL64(aPrevious, 13U)) + 16223920526599306104U;
            aOrbiterH = ((aWandererD + RotL64(aIngress, 29U)) + RotL64(aCarry, 29U)) + 12756613707692514808U;
            aOrbiterA = (aWandererB + RotL64(aPrevious, 27U)) + 5082475548176484035U;
            aOrbiterJ = (aWandererK + RotL64(aCross, 50U)) + 4907435526952698526U;
            aOrbiterG = (((aWandererF + RotL64(aScatter, 43U)) + RotL64(aCarry, 13U)) + 14236627073831834337U) + RotL64(aNonceWordA, 43U);
            aOrbiterB = (aWandererC + RotL64(aCross, 37U)) + 11502511046130497584U;
            aOrbiterF = (((aWandererH + RotL64(aIngress, 5U)) + 3679044835550219497U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 8U)) & S_SALT1]) + RotL64(aNonceWordH, 28U);
            aOrbiterK = ((aWandererI + RotL64(aScatter, 53U)) + 11254838916686736746U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 10582608424233200966U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 10449735026385340313U;
            aOrbiterC = RotL64((aOrbiterC * 7363770199734997411U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 4628253464169957835U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 17664454668473204465U;
            aOrbiterE = RotL64((aOrbiterE * 4234720298731378527U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 3798386391743884889U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 1379331161819246587U;
            aOrbiterH = RotL64((aOrbiterH * 13086160171095077295U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 9816600392407327227U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 16781971616348376878U;
            aOrbiterJ = RotL64((aOrbiterJ * 12503867584828289879U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 4807797577690520554U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 2492057261148595922U;
            aOrbiterB = RotL64((aOrbiterB * 9453302540675483005U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 7909676419643119585U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 256053568910383007U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11965085163352053161U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 16179914439220412472U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 3968867762761955845U) ^ RotL64(aNonceWordG, 21U);
            aOrbiterD = RotL64((aOrbiterD * 7473632378251893139U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 7474832923901283742U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 4736994731050735779U;
            aOrbiterA = RotL64((aOrbiterA * 9839654409121414047U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 596484364660389193U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 13822222274464306169U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1723502278319885511U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 16307920280681985443U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 3505106171801702915U;
            aOrbiterF = RotL64((aOrbiterF * 8479675421552861243U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 4987142580981135150U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 10336802574069791273U) ^ RotL64(aNonceWordD, 19U);
            aOrbiterK = RotL64((aOrbiterK * 2670706512498539705U), 23U);
            //
            aIngress = RotL64(aOrbiterF, 3U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 21U));
            aIngress = aIngress + (RotL64(aOrbiterB, 58U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterE, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterJ, 23U)) + aOrbiterA);
            aWandererK = aWandererK + ((RotL64(aCross, 35U) + aOrbiterK) + RotL64(aOrbiterD, 27U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 51U) + aOrbiterI) + RotL64(aOrbiterE, 13U)) + RotL64(aNonceWordF, 27U));
            aWandererA = aWandererA + (((RotL64(aScatter, 11U) + aOrbiterI) + RotL64(aOrbiterC, 5U)) + RotL64(aCarry, 51U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 18U) + aOrbiterG) + RotL64(aOrbiterB, 38U)) + aPhaseEWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 29U) + RotL64(aOrbiterJ, 35U)) + aOrbiterB) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterE, 19U)) + aOrbiterC);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 21U) + RotL64(aOrbiterF, 53U)) + aOrbiterE) + RotL64(aCarry, 41U)) + RotL64(aNonceWordE, 41U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterK, 57U)) + aOrbiterJ);
            aWandererB = aWandererB + ((RotL64(aScatter, 57U) + aOrbiterF) + RotL64(aOrbiterA, 46U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 6U) + aOrbiterH) + RotL64(aOrbiterG, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 14U) ^ aWandererG);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + (RotL64(aWandererF, 18U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererA, 27U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 51U) ^ RotL64(aNonceWordF, 29U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 14652U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 12353U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 5U) ^ RotL64(aNonceWordA, 29U)) ^ RotL64(aNonceWordE, 56U));
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 15163U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 13658U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aIngress, 19U)) ^ (RotL64(aCarry, 35U) + RotL64(aPrevious, 6U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterG = ((aWandererF + RotL64(aIngress, 18U)) + 12131317914288566437U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = (aWandererG + RotL64(aCross, 5U)) + 5672805657999385496U;
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 43U)) + 3581710244233124197U) + RotL64(aNonceWordE, 5U);
            aOrbiterF = (aWandererC + RotL64(aScatter, 47U)) + 15251296040538489436U;
            aOrbiterA = (aWandererJ + RotL64(aIngress, 35U)) + 11295008604679904153U;
            aOrbiterK = (aWandererI + RotL64(aCross, 13U)) + 2230897493419504490U;
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 51U)) + RotL64(aCarry, 19U)) + 7109600123297458999U;
            aOrbiterD = (aWandererD + RotL64(aScatter, 3U)) + 13119156643107683803U;
            aOrbiterI = (aWandererH + RotL64(aCross, 57U)) + 14755160867807355250U;
            aOrbiterC = (((aWandererE + RotL64(aScatter, 53U)) + RotL64(aCarry, 3U)) + 16829363373287496832U) + RotL64(aNonceWordB, 31U);
            aOrbiterJ = (((aWandererA + RotL64(aIngress, 22U)) + RotL64(aCarry, 29U)) + 16981122946707720883U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 8806000776958603317U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 16810923047720876014U;
            aOrbiterE = RotL64((aOrbiterE * 17872735050219539145U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 8129657889554436328U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 8653100378491974463U) ^ RotL64(aNonceWordH, 29U);
            aOrbiterK = RotL64((aOrbiterK * 11395283153912468661U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 17048985838727432415U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 10892675550889823573U) ^ RotL64(aNonceWordD, 56U);
            aOrbiterH = RotL64((aOrbiterH * 976298937314081913U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 15960158965421254346U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 12290011578634850001U;
            aOrbiterA = RotL64((aOrbiterA * 9280475585104357745U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 16265047040311479093U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 10312956912303656248U;
            aOrbiterD = RotL64((aOrbiterD * 3012584393253845131U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 16706890352221352779U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 10630955894218491929U;
            aOrbiterC = RotL64((aOrbiterC * 12675937483456206355U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 4009352551041162434U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 3043810773683888556U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4328135390387997315U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 1398071019814944785U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 16689766557488135301U;
            aOrbiterF = RotL64((aOrbiterF * 8403881916549404871U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 15934647144489136524U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 13521276033614992223U;
            aOrbiterB = RotL64((aOrbiterB * 18003640895553609933U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 4281211055727414100U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 11848150507497406421U;
            aOrbiterI = RotL64((aOrbiterI * 1107789990317433481U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 12022829841608199449U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 12131317914288566437U;
            aOrbiterJ = RotL64((aOrbiterJ * 13275753083882829973U), 29U);
            //
            aIngress = RotL64(aOrbiterF, 39U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterE, 27U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 53U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 48U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + RotL64(aOrbiterA, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 5U) + aOrbiterE) + RotL64(aOrbiterC, 21U));
            aWandererA = aWandererA + ((RotL64(aScatter, 37U) + RotL64(aOrbiterG, 24U)) + aOrbiterE);
            aWandererC = aWandererC ^ (((RotL64(aCross, 24U) + RotL64(aOrbiterJ, 37U)) + aOrbiterC) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterK, 43U)) + aOrbiterI);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 21U) + aOrbiterF) + RotL64(aOrbiterB, 41U));
            aWandererD = aWandererD + (((RotL64(aCross, 29U) + aOrbiterC) + RotL64(aOrbiterK, 47U)) + RotL64(aCarry, 57U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 19U) + aOrbiterJ) + RotL64(aOrbiterG, 35U));
            aWandererE = aWandererE + ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterE, 3U)) + aOrbiterB) + RotL64(aCarry, 43U)) + RotL64(aNonceWordC, 25U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 10U) + aOrbiterJ) + RotL64(aOrbiterD, 26U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterB, 19U)) + aOrbiterH) + RotL64(aNonceWordG, 11U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterA, 57U)) + aOrbiterF) + aPhaseEWandererUpdateSaltD[((aIndex + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 60U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererF, 53U);
            aCarry = aCarry + RotL64(aIngress, 58U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 35U) ^ RotL64(aNonceWordF, 13U)) ^ RotL64(aNonceWordC, 47U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 20840U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((aIndex + 17458U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 12U) ^ RotL64(aNonceWordE, 29U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 16471U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 21244U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 50U) + RotL64(aPrevious, 5U)) ^ (RotL64(aIngress, 19U) ^ RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterK = ((aWandererF + RotL64(aCross, 13U)) + RotL64(aCarry, 29U)) + 8685374557928800912U;
            aOrbiterG = ((aWandererA + RotL64(aScatter, 34U)) + 3482312691892161229U) + RotL64(aNonceWordG, 17U);
            aOrbiterB = (aWandererH + RotL64(aIngress, 47U)) + 6948130297389161165U;
            aOrbiterH = (aWandererK + RotL64(aPrevious, 27U)) + 5506385663788942690U;
            aOrbiterC = ((aWandererE + RotL64(aScatter, 3U)) + 17859982009307397161U) + RotL64(aNonceWordD, 47U);
            aOrbiterF = (aWandererB + RotL64(aIngress, 23U)) + 9178488809207094043U;
            aOrbiterE = (aWandererJ + RotL64(aCross, 39U)) + 1835479501226057169U;
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 5U)) + RotL64(aCarry, 13U)) + 5368101733632614939U;
            aOrbiterI = ((aWandererI + RotL64(aIngress, 11U)) + RotL64(aCarry, 19U)) + 9050459666576835422U;
            aOrbiterD = ((aWandererC + RotL64(aCross, 51U)) + 9042186993119635078U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 20U)) + 17528342580198295025U) + aPhaseEOrbiterAssignSaltC[((aIndex + 20U)) & S_SALT1];
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 6495418332558436882U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 8834495762667327342U;
            aOrbiterB = RotL64((aOrbiterB * 10783141541937645995U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 4364314196965690905U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 6357485231062120459U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 289429584586504995U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 3321488322626415347U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 10817330671781848737U;
            aOrbiterF = RotL64((aOrbiterF * 15875919466358823335U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 17974092279281611763U) + RotL64(aNonceWordC, 61U);
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 2871472057292789157U;
            aOrbiterE = RotL64((aOrbiterE * 16104199340711015181U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 15187929795092006849U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 13482063681546475923U;
            aOrbiterA = RotL64((aOrbiterA * 14466266308157364963U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 6232152545071397380U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 17488906002621373262U;
            aOrbiterI = RotL64((aOrbiterI * 4719340606442742577U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 12444819880507588549U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 13808941689757772497U;
            aOrbiterD = RotL64((aOrbiterD * 6541360905282412317U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 8049361354387692374U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 7137831335606542401U;
            aOrbiterJ = RotL64((aOrbiterJ * 11022231291507235007U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 7230759462019420058U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 3923744511976096944U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9953869624243563101U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 15967667946023263856U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 8677583624693910669U;
            aOrbiterG = RotL64((aOrbiterG * 10737731876339973717U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 1604347321263511013U) + RotL64(aNonceWordH, 14U);
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 8685374557928800912U;
            aOrbiterH = RotL64((aOrbiterH * 14103365695918844461U), 29U);
            //
            aIngress = RotL64(aOrbiterG, 29U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 48U));
            aIngress = aIngress + (RotL64(aOrbiterF, 39U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterA, 21U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterE, 53U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterD, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aIngress, 35U) + RotL64(aOrbiterB, 47U)) + aOrbiterK) + RotL64(aNonceWordB, 13U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 11U) + aOrbiterA) + RotL64(aOrbiterC, 43U));
            aWandererA = aWandererA + (((RotL64(aScatter, 5U) + aOrbiterA) + RotL64(aOrbiterK, 21U)) + RotL64(aCarry, 29U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 19U) + aOrbiterF) + RotL64(aOrbiterI, 23U));
            aWandererD = aWandererD + ((RotL64(aScatter, 46U) + RotL64(aOrbiterF, 54U)) + aOrbiterJ);
            aWandererK = aWandererK ^ (((RotL64(aCross, 29U) + aOrbiterG) + RotL64(aOrbiterD, 13U)) + aPhaseEWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 21U) + aOrbiterC) + RotL64(aOrbiterF, 35U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterH, 27U)) + aOrbiterB);
            aWandererG = aWandererG + (((RotL64(aScatter, 3U) + aOrbiterG) + RotL64(aOrbiterA, 58U)) + RotL64(aNonceWordA, 53U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 41U) + aOrbiterE) + RotL64(aOrbiterK, 29U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 58U) + RotL64(aOrbiterI, 11U)) + aOrbiterD) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 48U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 37U));
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererB, 41U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererK, 12U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 26U) ^ RotL64(aNonceWordH, 35U)) ^ RotL64(aNonceWordC, 57U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 24116U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 23102U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 27U) ^ RotL64(aNonceWordD, 3U)) ^ RotL64(aNonceWordB, 41U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 24428U)) & S_BLOCK1], 18U) ^ RotL64(aExpandLaneA[((aIndex + 26225U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCross, 21U)) + (RotL64(aIngress, 39U) ^ RotL64(aCarry, 52U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterB = (aWandererD + RotL64(aPrevious, 43U)) + 9751314027302668907U;
            aOrbiterF = ((aWandererE + RotL64(aCross, 20U)) + 12175450995523107056U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterD = ((aWandererB + RotL64(aScatter, 27U)) + RotL64(aCarry, 53U)) + 17519694958730119552U;
            aOrbiterE = (aWandererG + RotL64(aIngress, 57U)) + 9093525527925682263U;
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 3U)) + 3713831321786810138U) + RotL64(aNonceWordH, 17U);
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 53U)) + RotL64(aCarry, 39U)) + 10108355209191835040U;
            aOrbiterC = (aWandererH + RotL64(aIngress, 51U)) + 12956307447311314768U;
            aOrbiterA = ((aWandererK + RotL64(aCross, 24U)) + RotL64(aCarry, 43U)) + 1904298513945877359U;
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 11U)) + 4658049993308574460U) + RotL64(aNonceWordB, 14U);
            aOrbiterI = (aWandererF + RotL64(aScatter, 47U)) + 9826333658248851902U;
            aOrbiterG = ((aWandererA + RotL64(aCross, 29U)) + 12058666914724365134U) + aPhaseEOrbiterAssignSaltF[((aIndex + 10U)) & S_SALT1];
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 2516574707110528099U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 13335308331049750235U;
            aOrbiterD = RotL64((aOrbiterD * 5880227828760598587U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 8230749255538495304U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 16536559486797811486U;
            aOrbiterH = RotL64((aOrbiterH * 7097036838156464969U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 12387639130570188998U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 8459259798142872020U;
            aOrbiterA = RotL64((aOrbiterA * 8001346480955847013U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 16083784052002800300U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 1957284290736468379U;
            aOrbiterI = RotL64((aOrbiterI * 5046501301740813065U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 7349538179311335863U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 16395170077006105258U;
            aOrbiterB = RotL64((aOrbiterB * 4230485452156662763U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 3317652065873784068U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 5517155804799120700U;
            aOrbiterE = RotL64((aOrbiterE * 9789270651974719183U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 5568525912112200094U) + RotL64(aNonceWordA, 21U);
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 9334250662962319598U;
            aOrbiterC = RotL64((aOrbiterC * 5034887614541768961U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 5641394627075994165U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 13524971148931512745U;
            aOrbiterK = RotL64((aOrbiterK * 3699457147759854357U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 15124425790244392471U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 7896294947517723306U;
            aOrbiterG = RotL64((aOrbiterG * 7526632360108129915U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 15241686066829586263U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 12099799118961857495U;
            aOrbiterF = RotL64((aOrbiterF * 10456171163074630861U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 17529688916595727188U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterI) ^ 9751314027302668907U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]) ^ RotL64(aNonceWordE, 31U);
            aOrbiterJ = RotL64((aOrbiterJ * 521888849578281715U), 35U);
            //
            aIngress = RotL64(aOrbiterH, 21U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 60U));
            aIngress = aIngress + (RotL64(aOrbiterI, 35U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 43U));
            aIngress = aIngress + (RotL64(aOrbiterF, 3U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterE, 18U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 11U) + aOrbiterI) + RotL64(aOrbiterB, 50U)) + aPhaseEWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 21U) + aOrbiterG) + RotL64(aOrbiterE, 13U)) + RotL64(aCarry, 51U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 18U) + RotL64(aOrbiterH, 53U)) + aOrbiterK) + RotL64(aNonceWordG, 13U));
            aWandererA = aWandererA + (((RotL64(aIngress, 13U) + RotL64(aOrbiterK, 37U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 41U) + aOrbiterJ) + RotL64(aOrbiterF, 29U));
            aWandererE = aWandererE + ((RotL64(aIngress, 23U) + RotL64(aOrbiterJ, 35U)) + aOrbiterC);
            aWandererB = aWandererB ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterI, 39U)) + aOrbiterK);
            aWandererD = aWandererD + ((RotL64(aScatter, 57U) + aOrbiterB) + RotL64(aOrbiterE, 57U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 35U) + aOrbiterG) + RotL64(aOrbiterF, 11U)) + RotL64(aNonceWordF, 27U));
            aWandererH = aWandererH + (((RotL64(aScatter, 44U) + aOrbiterI) + RotL64(aOrbiterD, 24U)) + RotL64(aCarry, 23U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterE, 3U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererA, 37U) ^ aWandererF);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 20U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 53U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererI, 11U);
            aCarry = aCarry + RotL64(aIngress, 14U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 57U) ^ RotL64(aNonceWordE, 3U)) ^ RotL64(aNonceWordB, 27U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 30661U)) & S_BLOCK1], 38U) ^ RotL64(aOperationLaneB[((aIndex + 31135U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 6U) ^ RotL64(aNonceWordH, 35U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 32512U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31536U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 27U)) + (RotL64(aCross, 10U) ^ RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 5U)) + 2974056819475622600U) + RotL64(aNonceWordC, 39U);
            aOrbiterK = (((aWandererJ + RotL64(aCross, 10U)) + RotL64(aCarry, 43U)) + 7345051759236356098U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = ((aWandererH + RotL64(aScatter, 51U)) + RotL64(aCarry, 23U)) + 12738468816846628882U;
            aOrbiterH = (aWandererF + RotL64(aIngress, 21U)) + 7694520596043297922U;
            aOrbiterA = (aWandererK + RotL64(aScatter, 35U)) + 5530753590015084774U;
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 37U)) + 3776309161718383105U) + RotL64(aNonceWordB, 34U);
            aOrbiterD = (aWandererA + RotL64(aCross, 57U)) + 784780304358106404U;
            aOrbiterJ = ((aWandererG + RotL64(aIngress, 19U)) + 8999942326995036509U) + aPhaseEOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = (aWandererI + RotL64(aScatter, 12U)) + 5194986506064092779U;
            aOrbiterG = (aWandererC + RotL64(aIngress, 23U)) + 7920040007459652762U;
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 39U)) + RotL64(aCarry, 35U)) + 11311997270710107937U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 5365231114813547251U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 8630110234623825263U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2735881715888325759U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 2358235238039571072U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 18059414891616491807U;
            aOrbiterA = RotL64((aOrbiterA * 17150786106857185467U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 14526050556461782864U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 6937282036603272474U;
            aOrbiterE = RotL64((aOrbiterE * 14954512365270028029U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 10105832250694931310U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 3884223553012098137U;
            aOrbiterD = RotL64((aOrbiterD * 16340956813003906195U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 10385284339549648087U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 1257633893341505930U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2669950791270500977U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 5528890519572824318U) + RotL64(aNonceWordD, 45U);
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 15664241747527713256U;
            aOrbiterI = RotL64((aOrbiterI * 16670884497088220497U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 14264122979415331887U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 17985061405540198036U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2729487440173395133U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 1663986734997903415U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 3706166884286400587U;
            aOrbiterB = RotL64((aOrbiterB * 10549736618301955745U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 12736963182099961466U) + RotL64(aNonceWordE, 17U);
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 95411267612114381U;
            aOrbiterF = RotL64((aOrbiterF * 8011937916302325057U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 4966620136499917388U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 8478316876240452401U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13297718919105366563U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 11123814701411614557U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 2974056819475622600U;
            aOrbiterH = RotL64((aOrbiterH * 5913569942407618997U), 3U);
            //
            aIngress = RotL64(aOrbiterK, 21U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 50U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 41U));
            aIngress = aIngress + (RotL64(aOrbiterI, 43U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterD, 53U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterE, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterB, 43U)) + aOrbiterE) + RotL64(aNonceWordG, 13U));
            aWandererC = aWandererC + (((RotL64(aScatter, 48U) + RotL64(aOrbiterI, 19U)) + aOrbiterH) + RotL64(aCarry, 3U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 57U) + aOrbiterJ) + RotL64(aOrbiterD, 11U)) + RotL64(aNonceWordF, 41U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 13U) + aOrbiterK) + RotL64(aOrbiterJ, 27U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterH, 3U)) + aOrbiterC);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 41U) + aOrbiterJ) + RotL64(aOrbiterF, 5U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 11U) + aOrbiterA) + RotL64(aOrbiterK, 36U));
            aWandererE = aWandererE + (((RotL64(aCross, 3U) + RotL64(aOrbiterE, 41U)) + aOrbiterF) + RotL64(aCarry, 11U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 37U) + aOrbiterI) + RotL64(aOrbiterF, 23U));
            aWandererI = aWandererI + (((RotL64(aCross, 6U) + aOrbiterA) + RotL64(aOrbiterB, 51U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterG, 34U)) + aOrbiterH) + aPhaseEWandererUpdateSaltD[((aIndex + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 10U) ^ aWandererG);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 37U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 53U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + (RotL64(aWandererK, 41U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererF, 48U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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

void TwistExpander_Archery_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xFB8C6C04A92778F7ULL + 0x89156590A5DF089EULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xF41EE2C0BB3596CDULL + 0xA7CF020432B9144FULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xC61E895B3DECF963ULL + 0x9666451ED38FD8C9ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xE5AEF6E05A5645FBULL + 0x95A62CB74A843C76ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xA2605013E1CD6937ULL + 0x904CC224172DB88FULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xF212F63911C44A85ULL + 0x85728D7FA0945417ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xEF570C4F0C7562FFULL + 0xCB2FFADBCFCB8B11ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xB09C0A73BDB34ACDULL + 0x8C1917F1DF02A711ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 47U) ^ RotL64(aNonceWordE, 24U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 4171U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 3492U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 3U) ^ RotL64(aNonceWordF, 35U)) ^ RotL64(aNonceWordG, 57U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 576U)) & S_BLOCK1], 44U) ^ RotL64(aOperationLaneA[((aIndex + 2443U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 37U) + RotL64(aPrevious, 57U)) + (RotL64(aCross, 5U) ^ RotL64(aIngress, 24U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterA = ((aWandererC + RotL64(aIngress, 57U)) + RotL64(aCarry, 29U)) + 16200278595895089008U;
            aOrbiterJ = (aWandererA + RotL64(aCross, 5U)) + 1029614154810465897U;
            aOrbiterI = (aWandererG + RotL64(aScatter, 60U)) + 7129562468705441295U;
            aOrbiterF = (aWandererD + RotL64(aPrevious, 51U)) + 14388903902433951274U;
            aOrbiterH = ((((aWandererJ + RotL64(aScatter, 35U)) + RotL64(aCarry, 23U)) + 1013568949315967455U) + aPhaseFOrbiterAssignSaltE[((aIndex + 18U)) & S_SALT1]) + RotL64(aNonceWordF, 11U);
            aOrbiterK = (((aWandererE + RotL64(aIngress, 29U)) + 3128823373497815651U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1]) + RotL64(aNonceWordC, 26U);
            aOrbiterG = (aWandererK + RotL64(aPrevious, 11U)) + 14525694606889470589U;
            aOrbiterD = ((aWandererB + RotL64(aCross, 27U)) + RotL64(aCarry, 53U)) + 14443983602196782887U;
            aOrbiterC = (aWandererF + RotL64(aPrevious, 37U)) + 12244220415328641190U;
            aOrbiterE = (aWandererH + RotL64(aCross, 22U)) + 10477159225338766614U;
            aOrbiterB = (aWandererI + RotL64(aIngress, 3U)) + 2842870123078131566U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 8621138818955849917U) + RotL64(aNonceWordH, 53U);
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 5038396344400303181U;
            aOrbiterI = RotL64((aOrbiterI * 14636756322207385447U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 2768613802894372496U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 2027754864051410015U;
            aOrbiterK = RotL64((aOrbiterK * 2461322540050569287U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 2848088309172056399U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 15017458513904884651U;
            aOrbiterA = RotL64((aOrbiterA * 9926904679902843055U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 9079797279596336139U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 15424866642305110811U;
            aOrbiterF = RotL64((aOrbiterF * 12912331089970158845U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 13751764050290602740U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 7694557131324740282U;
            aOrbiterG = RotL64((aOrbiterG * 14980807690491467023U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 3508673897305667669U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 3600868397311393233U;
            aOrbiterC = RotL64((aOrbiterC * 5165032044164139165U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 1222655844979128996U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 2257342337168905875U;
            aOrbiterB = RotL64((aOrbiterB * 6198995971182272119U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 6290990717563682725U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 15308494772443447109U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1925593111157842325U), 43U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterG) + 4065385272074155855U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]) + RotL64(aNonceWordE, 27U);
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 17216369169581934516U;
            aOrbiterH = RotL64((aOrbiterH * 16172589962950781777U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 15683161334290612079U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 4197626901960576264U;
            aOrbiterD = RotL64((aOrbiterD * 2822547214684481747U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 4400047838649306704U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 16200278595895089008U;
            aOrbiterE = RotL64((aOrbiterE * 6603195071605635697U), 11U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterB, 43U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 51U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 39U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 58U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 11U));
            aIngress = aIngress + RotL64(aOrbiterC, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aCross, 43U) + RotL64(aOrbiterC, 58U)) + aOrbiterF);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 14U) + RotL64(aOrbiterJ, 5U)) + aOrbiterD) + RotL64(aNonceWordD, 25U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 37U) + aOrbiterA) + RotL64(aOrbiterE, 21U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 41U) + aOrbiterK) + RotL64(aOrbiterB, 19U)) + aPhaseFWandererUpdateSaltB[((aIndex + 10U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 39U) + aOrbiterK) + RotL64(aOrbiterH, 35U)) + aPhaseFWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 58U) + RotL64(aOrbiterC, 39U)) + aOrbiterJ);
            aWandererC = aWandererC + ((RotL64(aIngress, 53U) + RotL64(aOrbiterA, 51U)) + aOrbiterG);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 19U) + aOrbiterA) + RotL64(aOrbiterB, 13U)) + RotL64(aNonceWordA, 35U));
            aWandererD = aWandererD + (((RotL64(aCross, 51U) + aOrbiterJ) + RotL64(aOrbiterK, 24U)) + RotL64(aCarry, 39U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterB, 29U)) + aOrbiterH);
            aWandererE = aWandererE + (((RotL64(aIngress, 11U) + RotL64(aOrbiterI, 47U)) + aOrbiterK) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 6U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererC, 43U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 21U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + RotL64(aWandererB, 11U);
            aCarry = aCarry + RotL64(aIngress, 56U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 24U) ^ RotL64(aNonceWordG, 37U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10374U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneD[((aIndex + 6633U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 13U) ^ RotL64(aNonceWordH, 21U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 7383U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 7592U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 47U) ^ RotL64(aPrevious, 13U)) ^ (RotL64(aCarry, 60U) + RotL64(aIngress, 29U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterA = (aWandererF + RotL64(aCross, 5U)) + 12583180859826261500U;
            aOrbiterB = ((aWandererA + RotL64(aScatter, 21U)) + 9067093488553721468U) + RotL64(aNonceWordG, 5U);
            aOrbiterI = (aWandererE + RotL64(aIngress, 27U)) + 12173106198862881754U;
            aOrbiterG = (aWandererH + RotL64(aPrevious, 39U)) + 11333491014394592654U;
            aOrbiterC = (((aWandererJ + RotL64(aScatter, 35U)) + RotL64(aCarry, 39U)) + 3511883526940919554U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 60U)) + 7416810692106273044U) + RotL64(aNonceWordC, 50U);
            aOrbiterF = ((aWandererC + RotL64(aCross, 53U)) + RotL64(aCarry, 13U)) + 8341174972619784110U;
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 3U)) + RotL64(aCarry, 29U)) + 2220852854836962979U;
            aOrbiterD = (aWandererB + RotL64(aPrevious, 13U)) + 8090781422229383825U;
            aOrbiterE = (aWandererK + RotL64(aScatter, 42U)) + 2338801236599102223U;
            aOrbiterK = ((aWandererG + RotL64(aCross, 19U)) + 12484514711848308104U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 13684861340589131816U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 12796636819991873058U;
            aOrbiterI = RotL64((aOrbiterI * 5533508014234835669U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 7634198650894837690U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 10240326122201201762U;
            aOrbiterB = RotL64((aOrbiterB * 8758703497719125901U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 4162814763739453934U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 2766504649149048469U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16731843453895178671U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 11051393030148769655U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 17687055068651386665U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1042927176246229537U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 3353615315436983420U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 5971640796220306310U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15804313508835034807U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 12299773092762384765U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 7435804907797063411U;
            aOrbiterA = RotL64((aOrbiterA * 9848139805288165965U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 8735783937125735699U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 11903126115475835615U;
            aOrbiterG = RotL64((aOrbiterG * 16942088822124940265U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 4427166023462475475U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 6011733469446008137U;
            aOrbiterH = RotL64((aOrbiterH * 17298067225913923517U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 18341473946127677319U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 5423774915753911947U;
            aOrbiterJ = RotL64((aOrbiterJ * 14985099502923458523U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 2384393657884193014U) + RotL64(aNonceWordB, 55U);
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 2650593524388493958U;
            aOrbiterE = RotL64((aOrbiterE * 892985816665547945U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 15991261431384033176U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 12583180859826261500U) ^ RotL64(aNonceWordE, 49U);
            aOrbiterK = RotL64((aOrbiterK * 14394838775646875599U), 39U);
            //
            aIngress = RotL64(aOrbiterI, 23U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 11U));
            aIngress = aIngress + (RotL64(aOrbiterB, 46U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 19U));
            aIngress = aIngress + RotL64(aOrbiterD, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aCross, 60U) + RotL64(aOrbiterB, 3U)) + aOrbiterH) + RotL64(aNonceWordD, 29U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 27U) + aOrbiterA) + RotL64(aOrbiterD, 5U));
            aWandererE = aWandererE + ((RotL64(aIngress, 41U) + RotL64(aOrbiterK, 19U)) + aOrbiterE);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterC, 35U)) + aOrbiterE) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aCross, 43U) + RotL64(aOrbiterG, 13U)) + aOrbiterJ);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 5U) + aOrbiterF) + RotL64(aOrbiterK, 54U));
            aWandererA = aWandererA + ((((RotL64(aIngress, 19U) + aOrbiterB) + RotL64(aOrbiterA, 23U)) + RotL64(aCarry, 51U)) + aPhaseFWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 53U) + aOrbiterJ) + RotL64(aOrbiterB, 29U));
            aWandererG = aWandererG + ((((RotL64(aPrevious, 37U) + aOrbiterA) + RotL64(aOrbiterE, 57U)) + RotL64(aCarry, 5U)) + RotL64(aNonceWordA, 35U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterD, 43U)) + aOrbiterE);
            aWandererF = aWandererF + ((RotL64(aScatter, 58U) + RotL64(aOrbiterJ, 10U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 54U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererA);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 34U));
            aCarry = aCarry + RotL64(aWandererI, 47U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 19U) ^ RotL64(aNonceWordC, 57U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 11829U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((aIndex + 13319U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 13U) ^ RotL64(aNonceWordF, 57U)) ^ RotL64(aNonceWordB, 34U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 15463U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneC[((aIndex + 11827U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCarry, 37U)) + (RotL64(aIngress, 20U) ^ RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = (aWandererI + RotL64(aIngress, 34U)) + 4980738603982643969U;
            aOrbiterD = ((aWandererF + RotL64(aCross, 53U)) + RotL64(aCarry, 35U)) + 17660278413018470020U;
            aOrbiterB = (aWandererB + RotL64(aPrevious, 37U)) + 17598114429859543466U;
            aOrbiterG = ((aWandererK + RotL64(aScatter, 43U)) + RotL64(aCarry, 57U)) + 10993929335279994739U;
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 21U)) + RotL64(aCarry, 27U)) + 17967203122976322481U;
            aOrbiterC = (aWandererA + RotL64(aIngress, 3U)) + 1872290205549034384U;
            aOrbiterA = ((aWandererC + RotL64(aCross, 27U)) + 16607778671782810797U) + aPhaseFOrbiterAssignSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = ((aWandererH + RotL64(aScatter, 5U)) + 4895226930754394376U) + RotL64(aNonceWordH, 21U);
            aOrbiterH = (aWandererJ + RotL64(aIngress, 29U)) + 14960359005982301383U;
            aOrbiterJ = (aWandererG + RotL64(aCross, 46U)) + 9921642352377700630U;
            aOrbiterI = (((aWandererE + RotL64(aPrevious, 57U)) + 893281964367208693U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 26U)) & S_SALT1]) + RotL64(aNonceWordG, 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 8232519988397858732U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 4433022122758913407U;
            aOrbiterB = RotL64((aOrbiterB * 834240393225479419U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 12689609831247168353U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 404535388957472176U;
            aOrbiterC = RotL64((aOrbiterC * 14534020545479806593U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 3349108201964013155U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 4386449511297371730U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9596273264321140229U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 14314587717949070586U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 10923886625271054985U;
            aOrbiterK = RotL64((aOrbiterK * 7838969002623486809U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 17634909585329833520U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 2021301459918350372U;
            aOrbiterF = RotL64((aOrbiterF * 1388242915918642741U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 5219599112498224367U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 10641339455385046206U;
            aOrbiterJ = RotL64((aOrbiterJ * 1022283727595400719U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 5003342156562330058U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 10951027475628404336U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17836928292555158461U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 13040991872592235460U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 11149099984302782267U;
            aOrbiterG = RotL64((aOrbiterG * 4248667283139686251U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 2202253777854402763U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 16679038924474862612U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2624443661523083597U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 1959650241410955571U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 8415989510614674816U;
            aOrbiterH = RotL64((aOrbiterH * 16340289102832732519U), 27U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterC) + 2344501711730399821U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1]) + RotL64(aNonceWordF, 10U);
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 4980738603982643969U) ^ RotL64(aNonceWordE, 23U);
            aOrbiterI = RotL64((aOrbiterI * 6419275275477478723U), 57U);
            //
            aIngress = RotL64(aOrbiterD, 35U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 44U));
            aIngress = aIngress + (RotL64(aOrbiterI, 41U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterH, 21U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterA, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aIngress, 19U) + aOrbiterJ) + RotL64(aOrbiterH, 18U)) + RotL64(aCarry, 41U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 58U) + aOrbiterJ) + RotL64(aOrbiterD, 23U)) + aPhaseFWandererUpdateSaltD[((aIndex + 15U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 21U) + aOrbiterH) + RotL64(aOrbiterA, 13U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 23U) + aOrbiterD) + RotL64(aOrbiterE, 21U));
            aWandererK = aWandererK + (((RotL64(aCross, 13U) + RotL64(aOrbiterA, 53U)) + aOrbiterG) + RotL64(aCarry, 57U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterG, 37U)) + aOrbiterK) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 37U) + aOrbiterB) + RotL64(aOrbiterE, 47U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 29U) + aOrbiterC) + RotL64(aOrbiterF, 3U));
            aWandererE = aWandererE + (((RotL64(aCross, 4U) + aOrbiterI) + RotL64(aOrbiterD, 11U)) + RotL64(aNonceWordD, 53U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterI, 28U)) + aOrbiterJ);
            aWandererG = aWandererG + (((RotL64(aIngress, 47U) + RotL64(aOrbiterC, 57U)) + aOrbiterJ) + RotL64(aNonceWordC, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 14U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 51U));
            aCarry = aCarry + (RotL64(aWandererG, 10U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererB, 5U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 21U) ^ RotL64(aNonceWordE, 37U)) ^ RotL64(aNonceWordB, 3U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 21110U)) & S_BLOCK1], 52U) ^ RotL64(aWorkLaneB[((aIndex + 19856U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 30U) ^ RotL64(aNonceWordF, 19U)) ^ RotL64(aNonceWordA, 11U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19379U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneD[((aIndex + 17781U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 11U) ^ RotL64(aIngress, 56U)) + (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 29U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterF = (aWandererI + RotL64(aCross, 5U)) + 13204735390996728477U;
            aOrbiterJ = (aWandererH + RotL64(aScatter, 3U)) + 851171359595647173U;
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 26U)) + RotL64(aCarry, 37U)) + 16745304202825290723U;
            aOrbiterD = (aWandererF + RotL64(aIngress, 43U)) + 562392736584913979U;
            aOrbiterA = (aWandererA + RotL64(aCross, 57U)) + 3244267012529053918U;
            aOrbiterB = ((aWandererG + RotL64(aIngress, 53U)) + RotL64(aCarry, 21U)) + 17282536111067869133U;
            aOrbiterI = ((aWandererD + RotL64(aScatter, 34U)) + RotL64(aCarry, 57U)) + 14851130066471729068U;
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 13U)) + 5256130407952363129U) + aPhaseFOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = (((aWandererK + RotL64(aIngress, 47U)) + 2904742485828362001U) + aPhaseFOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1]) + RotL64(aNonceWordA, 28U);
            aOrbiterK = (aWandererC + RotL64(aScatter, 23U)) + 3723346325449225387U;
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 37U)) + 5344621093694027341U) + RotL64(aNonceWordG, 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 12919263300833603026U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 17989801264160996071U;
            aOrbiterG = RotL64((aOrbiterG * 15468293047311883751U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 5022175042377172157U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 16684822380107847758U;
            aOrbiterA = RotL64((aOrbiterA * 2834049270263837537U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 2740326510600876682U) + RotL64(aNonceWordD, 47U);
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 13981423865219318820U;
            aOrbiterB = RotL64((aOrbiterB * 14593082145080056441U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 231945878229848395U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 14139797734944312580U;
            aOrbiterI = RotL64((aOrbiterI * 6492256080432266407U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 16704102101387552373U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 8506734780526852552U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4684566118627414659U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 2774630043988894695U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 12490034334296488127U;
            aOrbiterC = RotL64((aOrbiterC * 16765455396278233145U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 545238171291436006U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 1023872898002379590U;
            aOrbiterK = RotL64((aOrbiterK * 8626333831510136515U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 5065187021047872560U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 10391809965648089863U;
            aOrbiterE = RotL64((aOrbiterE * 10912471108849550469U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 5576919045471579002U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 9761904001375034639U) ^ RotL64(aNonceWordH, 5U);
            aOrbiterF = RotL64((aOrbiterF * 8612901811320541361U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 2001472279505185946U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 11576457012366242134U;
            aOrbiterJ = RotL64((aOrbiterJ * 1070815118051466731U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 17713147845216099336U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 13204735390996728477U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10889281795183444943U), 23U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterH, 37U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 23U));
            aIngress = aIngress + (RotL64(aOrbiterE, 48U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterG, 5U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 41U));
            aIngress = aIngress + RotL64(aOrbiterK, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((((RotL64(aIngress, 3U) + RotL64(aOrbiterC, 39U)) + aOrbiterJ) + RotL64(aCarry, 3U)) + RotL64(aNonceWordC, 57U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 44U) + aOrbiterC) + RotL64(aOrbiterK, 47U));
            aWandererG = aWandererG + (((RotL64(aScatter, 47U) + RotL64(aOrbiterF, 36U)) + aOrbiterE) + RotL64(aCarry, 11U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterA, 3U)) + aOrbiterG);
            aWandererH = aWandererH + (((RotL64(aCross, 21U) + aOrbiterE) + RotL64(aOrbiterH, 11U)) + RotL64(aNonceWordE, 61U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 41U) + aOrbiterA) + RotL64(aOrbiterF, 41U));
            aWandererK = aWandererK + (((RotL64(aScatter, 27U) + RotL64(aOrbiterK, 51U)) + aOrbiterI) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 58U) + RotL64(aOrbiterH, 57U)) + aOrbiterD);
            aWandererA = aWandererA + ((RotL64(aIngress, 29U) + RotL64(aOrbiterI, 23U)) + aOrbiterD);
            aWandererF = aWandererF ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterB, 5U)) + aOrbiterD);
            aWandererB = aWandererB + ((RotL64(aPrevious, 37U) + aOrbiterE) + RotL64(aOrbiterA, 54U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 6U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererD);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + RotL64(aWandererF, 3U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 13U) ^ RotL64(aNonceWordA, 27U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 24968U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22914U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 43U) ^ RotL64(aNonceWordC, 51U)) ^ RotL64(aNonceWordE, 23U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 23294U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26631U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 14U) + RotL64(aCarry, 41U)) + (RotL64(aCross, 29U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterB = ((aWandererI + RotL64(aCross, 53U)) + RotL64(aCarry, 35U)) + 15652862298542575895U;
            aOrbiterK = (aWandererK + RotL64(aScatter, 23U)) + 16925323928418184554U;
            aOrbiterH = (aWandererJ + RotL64(aIngress, 57U)) + 4413861484961668394U;
            aOrbiterA = (aWandererB + RotL64(aPrevious, 34U)) + 2215946422098155969U;
            aOrbiterG = ((aWandererG + RotL64(aScatter, 5U)) + 14975185533513111110U) + aPhaseFOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = (aWandererE + RotL64(aPrevious, 51U)) + 9711613814905834552U;
            aOrbiterJ = (((aWandererD + RotL64(aIngress, 37U)) + RotL64(aCarry, 43U)) + 13154957291850149471U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterI = (aWandererA + RotL64(aCross, 47U)) + 5058313016418534840U;
            aOrbiterF = ((aWandererC + RotL64(aScatter, 3U)) + 15011423472941211620U) + RotL64(aNonceWordE, 27U);
            aOrbiterE = ((aWandererF + RotL64(aCross, 12U)) + 2030053257469580168U) + RotL64(aNonceWordB, 3U);
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 27U)) + RotL64(aCarry, 3U)) + 150530795186791193U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 10878237472104183427U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 11724672539469573109U;
            aOrbiterH = RotL64((aOrbiterH * 16158741837357985395U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 9589700906445846956U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 1367381624958248949U;
            aOrbiterD = RotL64((aOrbiterD * 8459515089081211977U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 12003215666757518106U) + RotL64(aNonceWordD, 13U);
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 11232479330848006729U;
            aOrbiterI = RotL64((aOrbiterI * 10993290955464593033U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 13013910456628561621U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 6092509838924105265U;
            aOrbiterE = RotL64((aOrbiterE * 805601154718006061U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 11999225836250312801U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 14421271973875748413U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9529010940887430157U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 15536288285741825272U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 2071793889925436679U;
            aOrbiterA = RotL64((aOrbiterA * 1526376970151714589U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 5622386476463436967U) + RotL64(aNonceWordG, 8U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 16147972771639168516U;
            aOrbiterJ = RotL64((aOrbiterJ * 11826916832825159095U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 4519892856053952290U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 12059500374938843538U;
            aOrbiterF = RotL64((aOrbiterF * 14987533625537956299U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 4547335128847992282U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 15378473334472216418U;
            aOrbiterC = RotL64((aOrbiterC * 13907560285280544037U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 14644123269581735633U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 6434315615480805381U;
            aOrbiterK = RotL64((aOrbiterK * 4335857173941645355U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 14241680137158382296U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 15652862298542575895U;
            aOrbiterG = RotL64((aOrbiterG * 4190840063924551519U), 29U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterB, 23U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 27U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 43U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + (RotL64(aOrbiterA, 38U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterE, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterF, 30U)) + aOrbiterH) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 23U) + aOrbiterI) + RotL64(aOrbiterA, 5U)) + RotL64(aNonceWordC, 47U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 35U) + aOrbiterH) + RotL64(aOrbiterA, 23U));
            aWandererD = aWandererD + ((RotL64(aIngress, 37U) + RotL64(aOrbiterH, 47U)) + aOrbiterD);
            aWandererE = aWandererE ^ ((RotL64(aCross, 48U) + RotL64(aOrbiterE, 57U)) + aOrbiterB);
            aWandererG = aWandererG + ((RotL64(aIngress, 43U) + RotL64(aOrbiterE, 10U)) + aOrbiterC);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 39U) + aOrbiterD) + RotL64(aOrbiterF, 3U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 13U) + aOrbiterB) + RotL64(aOrbiterG, 27U)) + RotL64(aCarry, 51U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterG, 53U)) + aOrbiterK) + RotL64(aNonceWordH, 53U));
            aWandererB = aWandererB + (((RotL64(aIngress, 18U) + RotL64(aOrbiterI, 13U)) + aOrbiterC) + RotL64(aCarry, 47U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 51U) + aOrbiterJ) + RotL64(aOrbiterH, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 21U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererC, 34U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 27U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererA, 41U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + RotL64(aWandererH, 11U);
            aCarry = aCarry + RotL64(aIngress, 14U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordE, 44U) ^ RotL64(aNonceWordF, 5U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 28674U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30977U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 35U) ^ RotL64(aNonceWordC, 53U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29486U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneB[((aIndex + 27887U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 43U) ^ RotL64(aIngress, 29U)) + (RotL64(aPrevious, 13U) ^ RotL64(aCarry, 56U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = (aWandererE + RotL64(aCross, 12U)) + 5173905450211892891U;
            aOrbiterJ = (aWandererC + RotL64(aIngress, 19U)) + 3555542451908039957U;
            aOrbiterC = (((aWandererH + RotL64(aScatter, 35U)) + 11559884700283861559U) + aPhaseFOrbiterAssignSaltB[((aIndex + 18U)) & S_SALT1]) + RotL64(aNonceWordD, 12U);
            aOrbiterH = (aWandererK + RotL64(aPrevious, 23U)) + 1352524329968738673U;
            aOrbiterG = (aWandererG + RotL64(aIngress, 41U)) + 8914206450420616349U;
            aOrbiterF = (((aWandererD + RotL64(aCross, 56U)) + RotL64(aCarry, 41U)) + 2251523378498463946U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 53U)) + RotL64(aCarry, 19U)) + 9541575923299247038U;
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 47U)) + RotL64(aCarry, 13U)) + 1239854507907214595U;
            aOrbiterD = (aWandererI + RotL64(aIngress, 29U)) + 17698101462598498934U;
            aOrbiterI = (aWandererA + RotL64(aCross, 39U)) + 12305566971683256060U;
            aOrbiterB = ((aWandererB + RotL64(aScatter, 43U)) + 13804545036303215569U) + RotL64(aNonceWordC, 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 10239749097704329264U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 4212214906286320308U) ^ RotL64(aNonceWordA, 27U);
            aOrbiterC = RotL64((aOrbiterC * 3661436621615751071U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 12192418916967430783U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 4475514289326450361U;
            aOrbiterG = RotL64((aOrbiterG * 17497164630368757887U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 17376102613298827459U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 18129393209955439341U;
            aOrbiterF = RotL64((aOrbiterF * 6404089025014118979U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 4014763724300253568U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 17325007199676828814U;
            aOrbiterA = RotL64((aOrbiterA * 1420888274815627083U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 15480474849292388685U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 14357924730184375449U;
            aOrbiterK = RotL64((aOrbiterK * 16723492259068034209U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 4335731868597970070U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 8296023680394303015U;
            aOrbiterD = RotL64((aOrbiterD * 14027415401430120543U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 2807312426993262800U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 15510369660839648501U;
            aOrbiterI = RotL64((aOrbiterI * 18207954408298333959U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 12597844696606519907U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 7231012798553551535U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2841306785994479299U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 849663631945232360U) + RotL64(aNonceWordB, 19U);
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 4002310581470781194U;
            aOrbiterE = RotL64((aOrbiterE * 2148877014350721479U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 16067735571435654555U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 4607980694199923842U;
            aOrbiterJ = RotL64((aOrbiterJ * 10401780756830017477U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 5346879191913449715U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 5173905450211892891U;
            aOrbiterH = RotL64((aOrbiterH * 15360571827429301833U), 11U);
            //
            aIngress = RotL64(aOrbiterH, 43U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 53U));
            aIngress = aIngress + (RotL64(aOrbiterF, 3U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterI, 60U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 5U));
            aIngress = aIngress + RotL64(aOrbiterB, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 37U) + aOrbiterJ) + RotL64(aOrbiterK, 11U));
            aWandererD = aWandererD + ((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterA, 43U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterD, 26U)) + aOrbiterC);
            aWandererI = aWandererI + (((RotL64(aCross, 60U) + RotL64(aOrbiterD, 51U)) + aOrbiterF) + RotL64(aCarry, 37U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterF, 21U)) + aOrbiterE);
            aWandererA = aWandererA + ((RotL64(aScatter, 21U) + RotL64(aOrbiterG, 37U)) + aOrbiterJ);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterD, 13U)) + aOrbiterA) + RotL64(aNonceWordG, 17U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 23U) + aOrbiterB) + RotL64(aOrbiterG, 40U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterF, 35U)) + aOrbiterH) + RotL64(aNonceWordH, 37U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 6U) + RotL64(aOrbiterG, 3U)) + aOrbiterI) + RotL64(aCarry, 5U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterH, 57U)) + aOrbiterA) + aPhaseFWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 30U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 41U));
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 21U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererH, 11U);
            aCarry = aCarry + RotL64(aIngress, 50U);
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

void TwistExpander_Archery_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xC9628B58E72EB997ULL + 0xB946E2E9B5232040ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xA7AFAB436C08DD0FULL + 0xB6786EAC63814626ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xBDF92127314E6CB9ULL + 0x9E3712853929A0A0ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xA412FC9FA4305967ULL + 0xD04E47343366911BULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xD16DFC8FF6058151ULL + 0xCE54CB166B68BE52ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xA18A6737918BEC87ULL + 0xEC93FEA114BCAAEFULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xCCDB3B277CDFDA63ULL + 0xEFC11B98AD95756DULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xB8E22B8BE5D31799ULL + 0xA9BAC75438C35A69ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 48U) ^ RotL64(aNonceWordC, 21U));
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 5254U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneC[((aIndex + 1715U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 23U) ^ RotL64(aNonceWordA, 13U)) ^ RotL64(aNonceWordE, 3U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 1431U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 3676U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 41U) + RotL64(aPrevious, 27U)) ^ (RotL64(aIngress, 54U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterK = (((aWandererA + RotL64(aCross, 10U)) + 7651355040951791298U) + aPhaseFOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1]) + RotL64(aNonceWordH, 7U);
            aOrbiterD = ((aWandererC + RotL64(aScatter, 37U)) + 13988210277931659312U) + RotL64(aNonceWordF, 19U);
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 57U)) + 9846849412579537783U) + aPhaseFOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = ((aWandererH + RotL64(aIngress, 29U)) + RotL64(aCarry, 51U)) + 12746719939495876158U;
            aOrbiterH = (aWandererE + RotL64(aPrevious, 19U)) + 11498066185182895284U;
            aOrbiterB = (aWandererJ + RotL64(aScatter, 3U)) + 11101058955193080232U;
            aOrbiterF = (aWandererK + RotL64(aCross, 51U)) + 15513734459555672046U;
            aOrbiterA = (aWandererI + RotL64(aIngress, 39U)) + 15711108675349394643U;
            aOrbiterI = (aWandererB + RotL64(aPrevious, 23U)) + 4771231759949468556U;
            aOrbiterE = ((aWandererD + RotL64(aCross, 6U)) + RotL64(aCarry, 3U)) + 11449258010811305256U;
            aOrbiterC = ((aWandererG + RotL64(aScatter, 13U)) + RotL64(aCarry, 41U)) + 17036938391509986723U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 6999245666776654250U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 2106819066263369528U;
            aOrbiterJ = RotL64((aOrbiterJ * 13005885810757743129U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 12716183358903477216U) + RotL64(aNonceWordD, 5U);
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 16752724547046059889U;
            aOrbiterB = RotL64((aOrbiterB * 11475905692393034141U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 17623077680983093163U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 6726003022297274986U;
            aOrbiterK = RotL64((aOrbiterK * 14709385877103232653U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 2842410225096524740U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 9235178377537910514U;
            aOrbiterG = RotL64((aOrbiterG * 11813751114775673845U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 2619888019860844610U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 6295481948199619613U;
            aOrbiterF = RotL64((aOrbiterF * 15429161806953951205U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 9724921158061115570U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 4070976180958458679U;
            aOrbiterI = RotL64((aOrbiterI * 6080566609081811453U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 5864247978960125554U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 7771249710071026757U) ^ RotL64(aNonceWordB, 15U);
            aOrbiterC = RotL64((aOrbiterC * 4787660062590737657U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 15006900854988166845U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 2755659268987119046U;
            aOrbiterD = RotL64((aOrbiterD * 8043939381186802359U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 1922321482806966418U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 13910818219761929659U;
            aOrbiterH = RotL64((aOrbiterH * 8895973123729951173U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 7540972911473176026U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 5419023469522423893U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1380429266266313945U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 2349651834739320824U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 7651355040951791298U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3713776056028698433U), 29U);
            //
            aIngress = RotL64(aOrbiterD, 26U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterK, 29U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 19U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 3U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 57U));
            aIngress = aIngress + RotL64(aOrbiterG, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aCross, 39U) + RotL64(aOrbiterI, 3U)) + aOrbiterF) + aPhaseFWandererUpdateSaltC[((aIndex + 10U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 51U) + aOrbiterG) + RotL64(aOrbiterB, 23U)) + RotL64(aNonceWordC, 61U));
            aWandererA = aWandererA + ((RotL64(aScatter, 34U) + RotL64(aOrbiterC, 53U)) + aOrbiterK);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 19U) + aOrbiterA) + RotL64(aOrbiterD, 47U));
            aWandererE = aWandererE + (((RotL64(aScatter, 13U) + RotL64(aOrbiterD, 57U)) + aOrbiterB) + RotL64(aCarry, 35U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 23U) + aOrbiterE) + RotL64(aOrbiterH, 21U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterI, 60U)) + aOrbiterK);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 53U) + aOrbiterG) + RotL64(aOrbiterJ, 5U)) + RotL64(aNonceWordG, 56U));
            aWandererD = aWandererD + (((RotL64(aCross, 37U) + RotL64(aOrbiterD, 41U)) + aOrbiterF) + aPhaseFWandererUpdateSaltB[((aIndex + 18U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 21U) + aOrbiterI) + RotL64(aOrbiterE, 19U));
            aWandererC = aWandererC + (((RotL64(aIngress, 10U) + RotL64(aOrbiterG, 12U)) + aOrbiterC) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 37U));
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 6U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 41U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererK, 23U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 48U) ^ RotL64(aNonceWordH, 13U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 6052U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 9667U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 29U) ^ RotL64(aNonceWordG, 13U)) ^ RotL64(aNonceWordE, 21U));
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 5629U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 5914U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCarry, 11U)) + (RotL64(aIngress, 27U) ^ RotL64(aCross, 40U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterC = (aWandererK + RotL64(aIngress, 23U)) + 14686411261024919129U;
            aOrbiterF = (aWandererG + RotL64(aPrevious, 21U)) + 7514582233957632005U;
            aOrbiterJ = (((aWandererD + RotL64(aScatter, 6U)) + RotL64(aCarry, 29U)) + 6520710480103365552U) + RotL64(aNonceWordC, 19U);
            aOrbiterH = ((aWandererC + RotL64(aCross, 3U)) + RotL64(aCarry, 39U)) + 1983621978676188036U;
            aOrbiterD = ((aWandererI + RotL64(aScatter, 51U)) + 9003524602590749672U) + RotL64(aNonceWordH, 21U);
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 39U)) + RotL64(aCarry, 23U)) + 6428568234045228995U;
            aOrbiterG = ((aWandererA + RotL64(aCross, 27U)) + 8656552687136446989U) + aPhaseFOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = (aWandererF + RotL64(aIngress, 54U)) + 16916248288415922490U;
            aOrbiterK = ((aWandererH + RotL64(aCross, 19U)) + 9740237548002535784U) + aPhaseFOrbiterAssignSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterI = (aWandererE + RotL64(aScatter, 35U)) + 907561000814618339U;
            aOrbiterE = (aWandererJ + RotL64(aIngress, 41U)) + 4751108900841197631U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 167774899400732287U) + RotL64(aNonceWordD, 45U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 11907484918310854962U;
            aOrbiterJ = RotL64((aOrbiterJ * 7213139491146402985U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 14910318613649863924U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 14882888155751455276U;
            aOrbiterF = RotL64((aOrbiterF * 11394136445442060201U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 16175942562693781908U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 11022373758481651102U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6836331461393816027U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 12548405399045031548U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 10850926364556828443U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16231561687709867431U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 13391684887911141790U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 14648937281264822988U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6533299316940026059U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 8298658887198526821U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 13822977698661348891U;
            aOrbiterC = RotL64((aOrbiterC * 17769262972278410937U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 7505646847564645719U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 3238749538197209166U;
            aOrbiterH = RotL64((aOrbiterH * 15394286542600778567U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 15853506915123709257U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 8426329899401071248U;
            aOrbiterA = RotL64((aOrbiterA * 1330397096577715113U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 14848635392815613098U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 3549927798350175044U;
            aOrbiterB = RotL64((aOrbiterB * 1899044682313056949U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 1798973117197750802U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 13056711228618953977U;
            aOrbiterI = RotL64((aOrbiterI * 9102877396419306689U), 35U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterJ) + 1395893547965799281U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]) + RotL64(aNonceWordA, 59U);
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 14686411261024919129U;
            aOrbiterE = RotL64((aOrbiterE * 17075377081365066067U), 51U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterC, 27U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 53U));
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterH, 23U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterJ, 4U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterD, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aScatter, 39U) + aOrbiterB) + RotL64(aOrbiterF, 43U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 36U) + aOrbiterH) + RotL64(aOrbiterC, 57U)) + RotL64(aNonceWordG, 3U));
            aWandererD = aWandererD + ((((RotL64(aCross, 3U) + RotL64(aOrbiterG, 5U)) + aOrbiterI) + RotL64(aCarry, 37U)) + aPhaseFWandererUpdateSaltD[((aIndex + 18U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 57U) + aOrbiterC) + RotL64(aOrbiterD, 21U));
            aWandererF = aWandererF + ((RotL64(aScatter, 51U) + aOrbiterK) + RotL64(aOrbiterE, 29U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterD, 52U)) + aOrbiterA);
            aWandererG = aWandererG + ((((RotL64(aCross, 11U) + aOrbiterB) + RotL64(aOrbiterK, 37U)) + RotL64(aNonceWordF, 14U)) + aPhaseFWandererUpdateSaltA[((aIndex + 10U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 28U) + aOrbiterH) + RotL64(aOrbiterI, 41U));
            aWandererA = aWandererA + ((RotL64(aCross, 53U) + aOrbiterF) + RotL64(aOrbiterJ, 35U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 41U) + aOrbiterA) + RotL64(aOrbiterJ, 14U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 13U) + aOrbiterA) + RotL64(aOrbiterG, 47U)) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 14U));
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererC, 48U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererJ, 19U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 57U) ^ RotL64(aNonceWordC, 34U)) ^ RotL64(aNonceWordF, 3U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 15392U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 15880U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 13U) ^ RotL64(aNonceWordE, 3U));
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 11278U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 13076U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 6U) + RotL64(aIngress, 51U)) ^ (RotL64(aCarry, 35U) ^ RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterH = (((aWandererD + RotL64(aPrevious, 21U)) + RotL64(aCarry, 21U)) + 11698283336767769359U) + aPhaseFOrbiterAssignSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterI = (aWandererI + RotL64(aCross, 37U)) + 13297826354831483872U;
            aOrbiterE = ((aWandererF + RotL64(aIngress, 26U)) + RotL64(aCarry, 41U)) + 15254999058287530795U;
            aOrbiterF = (((aWandererG + RotL64(aScatter, 57U)) + 17474166585085346567U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1]) + RotL64(aNonceWordD, 27U);
            aOrbiterC = (aWandererA + RotL64(aPrevious, 43U)) + 15684783498452840289U;
            aOrbiterB = ((aWandererC + RotL64(aCross, 39U)) + RotL64(aCarry, 29U)) + 5061229733465216486U;
            aOrbiterK = ((aWandererE + RotL64(aIngress, 41U)) + 15370981279168377944U) + RotL64(aNonceWordE, 11U);
            aOrbiterG = (aWandererK + RotL64(aScatter, 46U)) + 17966672773619554092U;
            aOrbiterA = (aWandererJ + RotL64(aCross, 19U)) + 14685092893994491068U;
            aOrbiterD = (aWandererH + RotL64(aIngress, 51U)) + 12798804186209406389U;
            aOrbiterJ = (aWandererB + RotL64(aScatter, 53U)) + 2848444181474221574U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 8551142075919636146U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 8833198159158950723U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7650289040764974737U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 7351473160893666232U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 14204899612487622222U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6317485031956448029U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 7008985178526543258U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 13576796403863120356U;
            aOrbiterI = RotL64((aOrbiterI * 13745839827679114077U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 5769784656937900699U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 14075925808204936705U;
            aOrbiterC = RotL64((aOrbiterC * 5844894088757604713U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 17818667502858010896U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 16016922065572683130U;
            aOrbiterG = RotL64((aOrbiterG * 7525645833898085373U), 27U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterF) + 1582458237855075977U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1]) + RotL64(aNonceWordH, 19U);
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 10830440354527138227U;
            aOrbiterD = RotL64((aOrbiterD * 10499386926982228251U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 10653964151654643772U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 11218475491129483859U;
            aOrbiterH = RotL64((aOrbiterH * 3338108067044357141U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 9863649760189649255U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 13790281439048354358U;
            aOrbiterF = RotL64((aOrbiterF * 4682098083538482849U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 14846954923718136337U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 522207783972623813U;
            aOrbiterK = RotL64((aOrbiterK * 14299798934454852811U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 426829715716262697U) + RotL64(aNonceWordB, 47U);
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 7482977730216354509U;
            aOrbiterA = RotL64((aOrbiterA * 6317437989422015173U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 10736099808538972990U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 11698283336767769359U;
            aOrbiterJ = RotL64((aOrbiterJ * 17230175904095995929U), 43U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterE, 37U);
            aIngress = aIngress + (RotL64(aOrbiterD, 53U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 43U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 28U));
            aIngress = aIngress + RotL64(aOrbiterG, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((((RotL64(aPrevious, 57U) + RotL64(aOrbiterH, 21U)) + aOrbiterF) + RotL64(aCarry, 3U)) + RotL64(aNonceWordG, 28U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 30U) + RotL64(aOrbiterD, 29U)) + aOrbiterB);
            aWandererE = aWandererE + ((RotL64(aScatter, 47U) + aOrbiterI) + RotL64(aOrbiterK, 53U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterE, 50U)) + aOrbiterB);
            aWandererG = aWandererG + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterC, 39U)) + aOrbiterF);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 21U) + aOrbiterJ) + RotL64(aOrbiterI, 23U));
            aWandererC = aWandererC + (((RotL64(aScatter, 18U) + aOrbiterC) + RotL64(aOrbiterG, 19U)) + RotL64(aCarry, 29U));
            aWandererF = aWandererF ^ ((((RotL64(aCross, 37U) + aOrbiterA) + RotL64(aOrbiterK, 47U)) + RotL64(aNonceWordA, 43U)) + aPhaseFWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterF, 37U)) + aOrbiterI);
            aWandererH = aWandererH ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterD, 43U)) + aOrbiterA);
            aWandererK = aWandererK + ((RotL64(aScatter, 3U) + RotL64(aOrbiterH, 12U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 6U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererA, 53U);
            aCarry = aCarry + RotL64(aIngress, 56U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 28U) ^ RotL64(aNonceWordA, 51U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 17340U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneB[((aIndex + 18325U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 11U) ^ RotL64(aNonceWordF, 27U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 16740U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneD[((aIndex + 20190U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 11U) + RotL64(aPrevious, 35U)) + (RotL64(aCross, 52U) ^ RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterA = (aWandererK + RotL64(aPrevious, 43U)) + 2168513956284366370U;
            aOrbiterB = (aWandererJ + RotL64(aCross, 13U)) + 10290361969974613111U;
            aOrbiterF = (aWandererG + RotL64(aIngress, 37U)) + 15673836275828498050U;
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 47U)) + 16600540024145812236U) + aPhaseFOrbiterAssignSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterI = ((aWandererA + RotL64(aIngress, 54U)) + RotL64(aCarry, 51U)) + 9428052101528111892U;
            aOrbiterH = (((aWandererE + RotL64(aPrevious, 39U)) + RotL64(aCarry, 27U)) + 12763657928312763377U) + RotL64(aNonceWordE, 59U);
            aOrbiterC = ((aWandererH + RotL64(aScatter, 41U)) + 10751286982008662485U) + RotL64(aNonceWordH, 7U);
            aOrbiterK = (((aWandererC + RotL64(aCross, 21U)) + RotL64(aCarry, 35U)) + 1708230173038057979U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = (aWandererI + RotL64(aScatter, 10U)) + 4011389705422783816U;
            aOrbiterG = (aWandererF + RotL64(aCross, 35U)) + 11704428328093077714U;
            aOrbiterE = (aWandererB + RotL64(aIngress, 5U)) + 2055336619674699284U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 1870865272102705804U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 3574214263751923179U;
            aOrbiterF = RotL64((aOrbiterF * 13132083406834413563U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 984611970726966186U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 15207945449947643672U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9539470161576639981U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 4181398506373973169U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 15222345431506025949U;
            aOrbiterH = RotL64((aOrbiterH * 6925143692628659467U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 15023513452326240962U) + RotL64(aNonceWordF, 49U);
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 14965669361708810699U;
            aOrbiterC = RotL64((aOrbiterC * 587008860996713147U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 7985755518735406360U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 225592097619240187U;
            aOrbiterK = RotL64((aOrbiterK * 2313509354133400439U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 3659537916566939383U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 17043668033610689611U;
            aOrbiterD = RotL64((aOrbiterD * 10797634709118100773U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 10217321522161675848U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 8013663869536146842U;
            aOrbiterG = RotL64((aOrbiterG * 2293233079384777175U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 13762445330867496042U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 2692400019659269106U;
            aOrbiterE = RotL64((aOrbiterE * 167704184292219399U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 18232551682424867647U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 14785847596876239854U) ^ RotL64(aNonceWordB, 25U);
            aOrbiterA = RotL64((aOrbiterA * 4569180925037758487U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 5910282247522389536U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 16556038638738871204U;
            aOrbiterB = RotL64((aOrbiterB * 18356922295088260901U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 141620663839815754U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 2168513956284366370U;
            aOrbiterJ = RotL64((aOrbiterJ * 8605382725635471683U), 35U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterF, 35U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 5U));
            aIngress = aIngress + (RotL64(aOrbiterD, 42U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + (RotL64(aOrbiterC, 37U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterA, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aIngress, 3U) + aOrbiterI) + RotL64(aOrbiterB, 22U)) + RotL64(aNonceWordG, 45U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterH, 19U)) + aOrbiterA) + aPhaseFWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 5U) + RotL64(aOrbiterH, 27U)) + aOrbiterJ);
            aWandererH = aWandererH ^ ((RotL64(aCross, 47U) + aOrbiterF) + RotL64(aOrbiterE, 47U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 22U) + RotL64(aOrbiterI, 51U)) + aOrbiterF) + RotL64(aNonceWordD, 28U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterE, 11U)) + aOrbiterK) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aScatter, 53U) + RotL64(aOrbiterE, 6U)) + aOrbiterG);
            aWandererB = aWandererB ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterD, 37U)) + aOrbiterA);
            aWandererE = aWandererE + (((RotL64(aIngress, 35U) + aOrbiterD) + RotL64(aOrbiterI, 3U)) + RotL64(aCarry, 41U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 12U) + aOrbiterE) + RotL64(aOrbiterH, 29U));
            aWandererG = aWandererG + (((RotL64(aScatter, 57U) + RotL64(aOrbiterC, 35U)) + aOrbiterH) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 53U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 18U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + (RotL64(aWandererJ, 41U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererE, 37U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 56U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 30U) ^ RotL64(aNonceWordA, 11U)) ^ RotL64(aNonceWordB, 3U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 23519U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27186U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 38U) ^ RotL64(aNonceWordF, 27U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 25955U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 22384U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 18U) + RotL64(aPrevious, 5U)) ^ (RotL64(aCross, 57U) + RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterI = (aWandererA + RotL64(aCross, 47U)) + 8402620908307642697U;
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 23U)) + 11347672014525086047U) + aPhaseFOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = ((aWandererH + RotL64(aIngress, 19U)) + 2816462912503401876U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = ((aWandererB + RotL64(aScatter, 3U)) + RotL64(aCarry, 37U)) + 6940159795470696093U;
            aOrbiterK = (aWandererI + RotL64(aIngress, 10U)) + 9134692490095883851U;
            aOrbiterJ = (aWandererK + RotL64(aScatter, 43U)) + 4999455497008026526U;
            aOrbiterF = (((aWandererD + RotL64(aCross, 13U)) + RotL64(aCarry, 41U)) + 5992451460350651332U) + RotL64(aNonceWordD, 35U);
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 21U)) + RotL64(aCarry, 5U)) + 3417087346651371924U;
            aOrbiterD = ((aWandererE + RotL64(aCross, 27U)) + 3612773820086198270U) + RotL64(aNonceWordE, 46U);
            aOrbiterA = (aWandererC + RotL64(aPrevious, 37U)) + 463398077083428570U;
            aOrbiterB = (aWandererG + RotL64(aIngress, 60U)) + 11249391303705089012U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 17027535139825739501U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 568131384979596481U;
            aOrbiterG = RotL64((aOrbiterG * 5683451044852895957U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 4793712537158004047U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 10415170179135963622U;
            aOrbiterJ = RotL64((aOrbiterJ * 13729564030210361415U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 2391473979460065630U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 4240058362680064261U) ^ RotL64(aNonceWordB, 53U);
            aOrbiterH = RotL64((aOrbiterH * 12375884373396400889U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 9963957011090031698U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 3325305624067445525U;
            aOrbiterA = RotL64((aOrbiterA * 3128542681461806309U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 2094945647665114693U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 10703615640774042674U;
            aOrbiterI = RotL64((aOrbiterI * 12641986098450423751U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 3768738815518590289U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 15021301790376706827U) ^ RotL64(aNonceWordG, 25U);
            aOrbiterC = RotL64((aOrbiterC * 14445850924223550339U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 10571246886181608316U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 5130325144599151793U;
            aOrbiterF = RotL64((aOrbiterF * 3185251943547657467U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 8617523421720966373U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 16574597770835250074U;
            aOrbiterD = RotL64((aOrbiterD * 1759209403428937799U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 17474733286551120355U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 17914672092861237776U;
            aOrbiterB = RotL64((aOrbiterB * 13657291990878792267U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 12856557371623447773U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 1636296609747335898U;
            aOrbiterE = RotL64((aOrbiterE * 9286345529656087313U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 12588848560509679821U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 8402620908307642697U;
            aOrbiterK = RotL64((aOrbiterK * 2269772223506258147U), 19U);
            //
            aIngress = RotL64(aOrbiterG, 5U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterK, 29U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterB, 51U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 18U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 53U));
            aIngress = aIngress + RotL64(aOrbiterI, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aScatter, 13U) + RotL64(aOrbiterJ, 3U)) + aOrbiterD) + RotL64(aCarry, 35U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterC, 34U)) + aOrbiterG);
            aWandererK = aWandererK + (((RotL64(aIngress, 11U) + aOrbiterC) + RotL64(aOrbiterI, 5U)) + RotL64(aCarry, 51U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 28U) + aOrbiterI) + RotL64(aOrbiterK, 57U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 21U) + RotL64(aOrbiterJ, 53U)) + aOrbiterB) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterI, 13U)) + aOrbiterE);
            aWandererB = aWandererB + ((RotL64(aScatter, 3U) + RotL64(aOrbiterE, 37U)) + aOrbiterC);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterB, 50U)) + aOrbiterH) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aIngress, 54U) + RotL64(aOrbiterF, 19U)) + aOrbiterG);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterA, 21U)) + aOrbiterB) + RotL64(aNonceWordA, 43U));
            aWandererF = aWandererF + (((RotL64(aCross, 51U) + RotL64(aOrbiterG, 39U)) + aOrbiterA) + RotL64(aNonceWordC, 31U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 60U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererF);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + (RotL64(aWandererB, 37U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererA, 30U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordE, 44U) ^ RotL64(aNonceWordH, 53U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 30141U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((aIndex + 30522U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 39U) ^ RotL64(aNonceWordD, 19U)) ^ RotL64(aNonceWordC, 60U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27538U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneB[((aIndex + 32187U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 54U) ^ RotL64(aCross, 21U)) + (RotL64(aPrevious, 35U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 51U)) + 4634399531433127141U;
            aOrbiterJ = (aWandererC + RotL64(aScatter, 11U)) + 16961792729406903200U;
            aOrbiterA = (aWandererG + RotL64(aCross, 41U)) + 4105280732301137738U;
            aOrbiterI = (aWandererA + RotL64(aIngress, 5U)) + 15692013501147331191U;
            aOrbiterC = (aWandererD + RotL64(aScatter, 23U)) + 1252216715968780587U;
            aOrbiterK = (((aWandererF + RotL64(aPrevious, 27U)) + 7958289043012473752U) + aPhaseFOrbiterAssignSaltA[((aIndex + 14U)) & S_SALT1]) + RotL64(aNonceWordH, 25U);
            aOrbiterH = (aWandererH + RotL64(aIngress, 48U)) + 6611577301818896615U;
            aOrbiterF = (aWandererE + RotL64(aCross, 13U)) + 8506226754305949140U;
            aOrbiterD = ((aWandererB + RotL64(aIngress, 57U)) + RotL64(aCarry, 5U)) + 3648813120449403353U;
            aOrbiterG = (((aWandererK + RotL64(aPrevious, 29U)) + RotL64(aCarry, 57U)) + 5195245426245535735U) + aPhaseFOrbiterAssignSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = (((aWandererI + RotL64(aScatter, 20U)) + RotL64(aCarry, 27U)) + 542948051600803051U) + RotL64(aNonceWordG, 55U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 11974253551208964789U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 10596463592332655367U;
            aOrbiterA = RotL64((aOrbiterA * 10941161258815714641U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 12015129484061440159U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 8254944355710109060U;
            aOrbiterC = RotL64((aOrbiterC * 3233697992479357615U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 2754858806943915419U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 5007802002906662779U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15613733948331639723U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 6262190752136523216U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 10528977986487821428U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1184258264034585525U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 8511097226098211854U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 12091864735686692582U;
            aOrbiterF = RotL64((aOrbiterF * 6128140528141411237U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 4970966265236842566U) + RotL64(aNonceWordA, 45U);
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 10728884018459718341U;
            aOrbiterD = RotL64((aOrbiterD * 18205183219769602827U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 13760057185629905360U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 6590269178744829056U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14482684769712170123U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 765826377665103262U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 9364759196106579706U;
            aOrbiterB = RotL64((aOrbiterB * 10315111163659289329U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 4629303338428087146U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 15107221579712215172U;
            aOrbiterE = RotL64((aOrbiterE * 14410837138199304663U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 9407987092859067074U) + RotL64(aNonceWordE, 54U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 13589362515507116096U;
            aOrbiterJ = RotL64((aOrbiterJ * 4544198075069052713U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 2236921538387014026U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 4634399531433127141U;
            aOrbiterI = RotL64((aOrbiterI * 13132011613143486575U), 19U);
            //
            aIngress = RotL64(aOrbiterD, 18U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterF, 57U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 41U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 27U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 39U));
            aIngress = aIngress + RotL64(aOrbiterK, 48U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterA, 41U)) + aOrbiterH);
            aWandererI = aWandererI + ((RotL64(aScatter, 27U) + RotL64(aOrbiterG, 51U)) + aOrbiterB);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 5U) + aOrbiterI) + RotL64(aOrbiterD, 21U)) + aPhaseFWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aCross, 41U) + aOrbiterK) + RotL64(aOrbiterH, 29U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterK, 44U)) + aOrbiterI) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 12U) + RotL64(aOrbiterG, 57U)) + aOrbiterI);
            aWandererC = aWandererC ^ (((RotL64(aCross, 19U) + aOrbiterJ) + RotL64(aOrbiterC, 5U)) + RotL64(aNonceWordF, 29U));
            aWandererE = aWandererE + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterC, 3U)) + aOrbiterD) + RotL64(aCarry, 11U)) + RotL64(aNonceWordB, 3U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterE, 54U)) + aOrbiterK);
            aWandererG = aWandererG + (((RotL64(aIngress, 3U) + aOrbiterC) + RotL64(aOrbiterK, 37U)) + RotL64(aCarry, 41U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 38U) + aOrbiterE) + RotL64(aOrbiterF, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 26U));
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 29U) ^ aWandererH);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + RotL64(aWandererD, 60U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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

void TwistExpander_Archery_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 1949U)) & S_BLOCK1], 52U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 1307U)) & W_KEY1], 23U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 6460U)) & W_KEY1], 23U) ^ RotL64(mSource[((aIndex + 2641U)) & S_BLOCK1], 34U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 13U) + RotL64(aPrevious, 41U)) + (RotL64(aCarry, 27U) ^ RotL64(aIngress, 58U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = ((aWandererK + RotL64(aScatter, 10U)) + RotL64(aCarry, 27U)) + 17470880031634374199U;
            aOrbiterC = (aWandererE + RotL64(aPrevious, 23U)) + 757565846006937746U;
            aOrbiterB = (aWandererA + RotL64(aCross, 5U)) + 9419282475801345674U;
            aOrbiterA = ((aWandererD + RotL64(aIngress, 57U)) + RotL64(aCarry, 11U)) + 2014248014107898196U;
            aOrbiterF = (aWandererF + RotL64(aScatter, 44U)) + 15113928519446490441U;
            aOrbiterD = (aWandererC + RotL64(aIngress, 35U)) + 7346126964886259935U;
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 51U)) + 5594123113093162359U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = ((aWandererJ + RotL64(aCross, 29U)) + RotL64(aCarry, 53U)) + 5659237263369402005U;
            aOrbiterH = ((aWandererH + RotL64(aScatter, 19U)) + 11565709683423969703U) + aPhaseCOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 16782863743534856287U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 13499100900072115907U;
            aOrbiterB = RotL64((aOrbiterB * 5567729598873214433U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 11414447651044205242U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 7545993795121430538U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10758488381206257261U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 11778229237616454988U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 2544793391976514665U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4021060413798523299U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 9972156716619459164U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 17651030383827445664U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6742914240706775487U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 17439147296849134543U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 10021926927948343656U;
            aOrbiterI = RotL64((aOrbiterI * 18139540407315440909U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 9309867875882669289U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 14951424455944346337U;
            aOrbiterA = RotL64((aOrbiterA * 10569523948169951309U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 2166343974068770659U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 11386993629011562026U;
            aOrbiterJ = RotL64((aOrbiterJ * 3091639433512536097U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 5747849744680120960U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 4019290369160113026U;
            aOrbiterC = RotL64((aOrbiterC * 5567515306039646735U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 3820540009554769592U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 8210747198363020939U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16215133106542452509U), 51U);
            //
            aIngress = RotL64(aOrbiterF, 19U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterI, 37U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterB, 46U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterH, 5U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 5U) + aOrbiterK) + RotL64(aOrbiterI, 11U));
            aWandererF = aWandererF + (((RotL64(aIngress, 10U) + RotL64(aOrbiterI, 57U)) + aOrbiterC) + RotL64(aCarry, 13U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterF, 46U)) + aOrbiterC);
            aWandererE = aWandererE + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterH, 51U)) + aOrbiterB) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 53U) + aOrbiterD) + RotL64(aOrbiterI, 35U)) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterJ, 5U)) + aOrbiterI);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 19U) + aOrbiterA) + RotL64(aOrbiterB, 23U)) + aPhaseCWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 37U) + RotL64(aOrbiterH, 28U)) + aOrbiterC);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 28U) + aOrbiterF) + RotL64(aOrbiterI, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererD, 50U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 12176U)) & S_BLOCK1], 58U) ^ RotL64(mSource[((aIndex + 13619U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15948U)) & W_KEY1], 51U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 11636U)) & W_KEY1], 12U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aPrevious, 5U)) ^ (RotL64(aCarry, 28U) ^ RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = (aWandererF + RotL64(aIngress, 60U)) + 12311607308490066301U;
            aOrbiterF = (aWandererA + RotL64(aCross, 3U)) + 13100864684740679846U;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 43U)) + RotL64(aCarry, 19U)) + 13697304189274329704U;
            aOrbiterA = (aWandererB + RotL64(aScatter, 23U)) + 9047976902871216732U;
            aOrbiterJ = ((aWandererK + RotL64(aCross, 54U)) + RotL64(aCarry, 27U)) + 2147897579538537888U;
            aOrbiterB = (aWandererI + RotL64(aPrevious, 39U)) + 2072444829390996142U;
            aOrbiterK = (aWandererH + RotL64(aIngress, 11U)) + 2129307836981020908U;
            aOrbiterG = (((aWandererD + RotL64(aScatter, 47U)) + RotL64(aCarry, 51U)) + 10663145333751112064U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 35U)) + 15019844390503785459U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 5460865577557928142U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 15806522559993224197U;
            aOrbiterD = RotL64((aOrbiterD * 8722932687972240099U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 6361113778657833389U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 8306013884615042570U;
            aOrbiterJ = RotL64((aOrbiterJ * 8234258702656728667U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 4038420580499706912U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 11908091484457158973U;
            aOrbiterK = RotL64((aOrbiterK * 3964111175645156719U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 11133912466611921250U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 2469227904206936928U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2704438771198001599U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 13234017916788297295U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 9061117693840451988U;
            aOrbiterE = RotL64((aOrbiterE * 3637440416741459419U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 12013423690843812324U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 14371779015144617412U;
            aOrbiterC = RotL64((aOrbiterC * 3359568073302062667U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 10044883414565441442U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 14334898081890462218U;
            aOrbiterA = RotL64((aOrbiterA * 4878939077928220019U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 13788962593988366125U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 8377887372059713516U;
            aOrbiterB = RotL64((aOrbiterB * 1925913354197206851U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 4584439257847749371U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 13335592911357756498U;
            aOrbiterF = RotL64((aOrbiterF * 6515028218115896375U), 27U);
            //
            aIngress = RotL64(aOrbiterA, 60U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterE, 39U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 35U));
            aIngress = aIngress + RotL64(aOrbiterK, 28U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aScatter, 60U) + aOrbiterK) + RotL64(aOrbiterG, 13U)) + RotL64(aCarry, 43U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterG, 35U)) + aOrbiterJ) + aPhaseCWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterC, 46U)) + aOrbiterJ);
            aWandererF = aWandererF ^ ((RotL64(aCross, 43U) + aOrbiterJ) + RotL64(aOrbiterA, 41U));
            aWandererH = aWandererH + (((RotL64(aIngress, 35U) + RotL64(aOrbiterD, 5U)) + aOrbiterE) + RotL64(aCarry, 27U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterF, 29U)) + aOrbiterG) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 47U) + aOrbiterB) + RotL64(aOrbiterG, 21U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 53U) + aOrbiterD) + RotL64(aOrbiterC, 50U));
            aWandererI = aWandererI + ((RotL64(aIngress, 26U) + RotL64(aOrbiterK, 57U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererK);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + (RotL64(aWandererD, 60U) ^ aWandererI);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + RotL64(aWandererE, 23U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 23983U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 18574U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 19598U)) & W_KEY1], 20U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 16623U)) & W_KEY1], 37U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 54U) + RotL64(aCross, 35U)) ^ (RotL64(aCarry, 23U) + RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 13U)) + RotL64(aCarry, 21U)) + 1557680213571812384U;
            aOrbiterD = (((aWandererA + RotL64(aCross, 28U)) + RotL64(aCarry, 41U)) + 7387349725778021121U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = ((aWandererB + RotL64(aIngress, 23U)) + RotL64(aCarry, 51U)) + 15379264067601586976U;
            aOrbiterC = (aWandererG + RotL64(aScatter, 57U)) + 3730195724576043708U;
            aOrbiterF = ((aWandererH + RotL64(aCross, 43U)) + 9637070085323827066U) + aPhaseCOrbiterAssignSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = (aWandererE + RotL64(aScatter, 19U)) + 1170865717363676184U;
            aOrbiterE = (aWandererF + RotL64(aIngress, 53U)) + 2750833653175252030U;
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 5U)) + 15118992811225568305U;
            aOrbiterH = (aWandererI + RotL64(aCross, 36U)) + 4974092922102988451U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 10625719096296719514U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 855167122475471865U;
            aOrbiterI = RotL64((aOrbiterI * 7441090331293158773U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 11322911068958340262U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 4334591909425429835U;
            aOrbiterB = RotL64((aOrbiterB * 10059025861172038183U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 14263701737208936392U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 678723206735649084U;
            aOrbiterC = RotL64((aOrbiterC * 10823239851733632227U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 15652053114252065230U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 1705225940224061401U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3626023093533713579U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 6826394665732900206U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 11902946775066981141U;
            aOrbiterF = RotL64((aOrbiterF * 18300629262162694137U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 9802212958998591310U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 14001358545610206524U;
            aOrbiterK = RotL64((aOrbiterK * 13172645840788327099U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 4299184726135884309U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 7288757011999872416U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16806027820468277393U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 233801262480580205U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 14208660347238680268U;
            aOrbiterJ = RotL64((aOrbiterJ * 6299693448313154603U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 9217797359740446104U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 18165073197136050838U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11677479094709512887U), 23U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterI, 51U);
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterK, 36U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aScatter, 21U) + aOrbiterJ) + RotL64(aOrbiterB, 47U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterE, 60U)) + aOrbiterK);
            aWandererC = aWandererC + (((RotL64(aCross, 26U) + aOrbiterJ) + RotL64(aOrbiterE, 5U)) + RotL64(aCarry, 19U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterJ, 29U)) + aOrbiterC);
            aWandererA = aWandererA + (((RotL64(aIngress, 51U) + aOrbiterB) + RotL64(aOrbiterD, 41U)) + aPhaseCWandererUpdateSaltA[((aIndex + 16U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 39U) + aOrbiterD) + RotL64(aOrbiterI, 35U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 35U) + aOrbiterD) + RotL64(aOrbiterE, 23U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterH, 11U)) + aOrbiterI) + aPhaseCWandererUpdateSaltE[((aIndex + 10U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 44U) + RotL64(aOrbiterF, 56U)) + aOrbiterC) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererA);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + RotL64(aWandererJ, 54U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 30611U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneB[((aIndex + 26855U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29324U)) & S_BLOCK1], 60U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 32281U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aIngress, 22U)) ^ (RotL64(aPrevious, 53U) + RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = (aWandererA + RotL64(aCross, 60U)) + 3612110001869385068U;
            aOrbiterB = (aWandererK + RotL64(aPrevious, 35U)) + 16340824141280225936U;
            aOrbiterG = (aWandererH + RotL64(aIngress, 47U)) + 15222338965130765231U;
            aOrbiterI = (aWandererD + RotL64(aScatter, 43U)) + 6649270508107155041U;
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 5U)) + RotL64(aCarry, 3U)) + 768217258655426384U;
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 39U)) + RotL64(aCarry, 13U)) + 4481855259658861851U;
            aOrbiterD = (aWandererI + RotL64(aCross, 19U)) + 18318041934562434016U;
            aOrbiterH = ((aWandererG + RotL64(aScatter, 14U)) + 4212457153804401807U) + aPhaseCOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = (((aWandererF + RotL64(aCross, 27U)) + RotL64(aCarry, 51U)) + 16143621095636987628U) + aPhaseCOrbiterAssignSaltD[((aIndex + 14U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 2095664232866642086U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 4339527736737366572U;
            aOrbiterG = RotL64((aOrbiterG * 17503569508822244125U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 13679353177869884790U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 11582168502846418236U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 135539430034462861U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 10451330452898542191U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 12951448817640617841U;
            aOrbiterD = RotL64((aOrbiterD * 4141870904192742091U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 15389161934419370747U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 4754886272708253014U;
            aOrbiterC = RotL64((aOrbiterC * 16638243718191281597U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 11746389873929280688U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 12042680172517298768U;
            aOrbiterI = RotL64((aOrbiterI * 3814780289755857543U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 2648103752465009244U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 451594673632597973U;
            aOrbiterA = RotL64((aOrbiterA * 8496763663271072425U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 5696534794094099710U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 14609435045257077395U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14658408563237468407U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 11599395126850950133U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 12699598504604446664U;
            aOrbiterE = RotL64((aOrbiterE * 14313494063098111823U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 9398465148537154745U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 12139736860648011256U;
            aOrbiterB = RotL64((aOrbiterB * 15257503229375247987U), 47U);
            //
            aIngress = RotL64(aOrbiterD, 11U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterC, 60U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterA, 19U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 51U));
            aIngress = aIngress + RotL64(aOrbiterI, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aIngress, 47U) + RotL64(aOrbiterG, 28U)) + aOrbiterI) + RotL64(aCarry, 43U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 21U) + aOrbiterH) + RotL64(aOrbiterC, 47U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 52U) + RotL64(aOrbiterA, 23U)) + aOrbiterC) + RotL64(aCarry, 11U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 11U) + aOrbiterB) + RotL64(aOrbiterI, 11U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 5U) + aOrbiterE) + RotL64(aOrbiterB, 19U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 27U) + aOrbiterE) + RotL64(aOrbiterD, 51U)) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 35U) + aOrbiterA) + RotL64(aOrbiterH, 34U)) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterJ, 43U)) + aOrbiterE);
            aWandererG = aWandererG + ((RotL64(aPrevious, 42U) + RotL64(aOrbiterC, 39U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 14U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 21U));
            aCarry = aCarry + RotL64(aWandererA, 29U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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

void TwistExpander_Archery_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 6486U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneC[((aIndex + 4534U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 3017U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 2678U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aPrevious, 53U)) ^ (RotL64(aIngress, 6U) + RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = ((aWandererB + RotL64(aScatter, 41U)) + RotL64(aCarry, 41U)) + 17225673071833726819U;
            aOrbiterG = ((aWandererF + RotL64(aIngress, 3U)) + 10301458382103627331U) + aPhaseDOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = (((aWandererH + RotL64(aCross, 51U)) + RotL64(aCarry, 57U)) + 3960233050857362414U) + aPhaseDOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 21U)) + RotL64(aCarry, 29U)) + 17768665685046605837U;
            aOrbiterD = (aWandererK + RotL64(aIngress, 30U)) + 14471018461213959767U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 10730597892721340453U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 14863394003122760542U;
            aOrbiterB = RotL64((aOrbiterB * 17731557030589257169U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 9948587274816688296U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 3573569431435100993U;
            aOrbiterC = RotL64((aOrbiterC * 2303922230056523077U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 8153670675740450590U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 16438856577722561424U;
            aOrbiterH = RotL64((aOrbiterH * 4689247488336908827U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 15765587867581925041U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 1082039522061775213U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17023740047246402641U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 4202521649260798876U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 15877659681260461141U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11369910758551088173U), 53U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterG, 13U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 23U));
            aIngress = aIngress + RotL64(aOrbiterH, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aCross, 27U) + RotL64(aOrbiterB, 21U)) + aOrbiterD) + RotL64(aCarry, 37U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterD, 53U)) + aOrbiterG) + aPhaseDWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterH, 13U)) + aOrbiterG) + RotL64(aCarry, 19U)) + aPhaseDWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 36U) + RotL64(aOrbiterC, 41U)) + aOrbiterD);
            aWandererK = aWandererK + ((RotL64(aIngress, 53U) + RotL64(aOrbiterC, 30U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 5U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 14U));
            aCarry = aCarry + RotL64(aWandererK, 47U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 15256U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneD[((aIndex + 15095U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15784U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 12335U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 58U) ^ RotL64(aCarry, 11U)) + (RotL64(aCross, 27U) ^ RotL64(aPrevious, 43U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = (((aWandererK + RotL64(aScatter, 20U)) + RotL64(aCarry, 3U)) + 8988572360732005217U) + aPhaseDOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = ((aWandererI + RotL64(aCross, 3U)) + RotL64(aCarry, 53U)) + 17889613225105985335U;
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 47U)) + 15563478320513948626U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = (aWandererH + RotL64(aIngress, 35U)) + 3441351228410524816U;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 57U)) + RotL64(aCarry, 27U)) + 4425592689451435346U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 12733160231627305928U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 3574152157304607854U;
            aOrbiterG = RotL64((aOrbiterG * 3488682351509384035U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 15167631896729808783U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 15822667973915417055U;
            aOrbiterK = RotL64((aOrbiterK * 5155661648455308057U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 17181685481076577637U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 9979204751408873468U;
            aOrbiterH = RotL64((aOrbiterH * 8244434774754786565U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 1334240485667164762U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 9190066751460137016U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14585141844653660363U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 15465215829109246336U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 2305208282453624419U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10257861974108363283U), 57U);
            //
            aIngress = RotL64(aOrbiterI, 47U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 35U));
            aIngress = aIngress + RotL64(aOrbiterG, 58U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterB, 12U)) + aOrbiterI) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 18U) + aOrbiterB) + RotL64(aOrbiterH, 57U)) + RotL64(aCarry, 29U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterK, 3U)) + aOrbiterG) + aPhaseDWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterH, 27U)) + aOrbiterI) + RotL64(aCarry, 13U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterK, 43U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 21U) ^ aWandererF);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + RotL64(aWandererI, 11U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 22439U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 18407U)) & S_BLOCK1], 10U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19194U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneC[((aIndex + 20096U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCarry, 37U)) ^ (RotL64(aCross, 5U) ^ RotL64(aPrevious, 54U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = ((aWandererK + RotL64(aCross, 51U)) + RotL64(aCarry, 51U)) + 14823268998003220191U;
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 29U)) + RotL64(aCarry, 39U)) + 15295237288788213847U;
            aOrbiterA = ((aWandererH + RotL64(aIngress, 21U)) + 16434853402001133899U) + aPhaseDOrbiterAssignSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterI = ((aWandererD + RotL64(aPrevious, 6U)) + 7555911304407871631U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = ((aWandererG + RotL64(aIngress, 37U)) + RotL64(aCarry, 13U)) + 14977248264994834620U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 9707764144919392380U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 1277304385464681529U;
            aOrbiterA = RotL64((aOrbiterA * 2864691650462053463U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 3089786220465849395U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 3700503853358695085U;
            aOrbiterH = RotL64((aOrbiterH * 2079089949442685421U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 3240054112993517371U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 16897532076915366859U;
            aOrbiterC = RotL64((aOrbiterC * 4120874717534309035U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 18167359289798364307U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 8870819278575769863U;
            aOrbiterI = RotL64((aOrbiterI * 9334066154398059075U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 15363069206212330251U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 14858164441499725158U;
            aOrbiterE = RotL64((aOrbiterE * 14931933411393847915U), 53U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterI, 57U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 47U));
            aIngress = aIngress + RotL64(aOrbiterE, 20U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterI, 5U)) + aOrbiterA);
            aWandererH = aWandererH + (((RotL64(aScatter, 34U) + aOrbiterH) + RotL64(aOrbiterA, 29U)) + RotL64(aCarry, 21U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterI, 14U)) + aOrbiterE) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 13U) + RotL64(aOrbiterE, 47U)) + aOrbiterA) + RotL64(aCarry, 41U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 5U) + aOrbiterC) + RotL64(aOrbiterH, 39U)) + aPhaseDWandererUpdateSaltE[((aIndex + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererH);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + RotL64(aWandererJ, 13U);
            aCarry = aCarry + RotL64(aIngress, 24U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 29945U)) & S_BLOCK1], 44U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29599U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 30067U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneD[((aIndex + 31060U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 52U) ^ RotL64(aCross, 35U)) ^ (RotL64(aIngress, 11U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = (aWandererK + RotL64(aScatter, 47U)) + 4634399531433127141U;
            aOrbiterA = ((aWandererE + RotL64(aCross, 57U)) + 16961792729406903200U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = (((aWandererG + RotL64(aPrevious, 3U)) + RotL64(aCarry, 27U)) + 4105280732301137738U) + aPhaseDOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = ((aWandererB + RotL64(aIngress, 18U)) + RotL64(aCarry, 53U)) + 15692013501147331191U;
            aOrbiterI = ((aWandererC + RotL64(aCross, 27U)) + RotL64(aCarry, 3U)) + 1252216715968780587U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 7958289043012473752U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 6611577301818896615U;
            aOrbiterC = RotL64((aOrbiterC * 2757493607265637973U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 8506226754305949140U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 3648813120449403353U;
            aOrbiterB = RotL64((aOrbiterB * 9521367946879238849U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 5195245426245535735U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 542948051600803051U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4631106308856448475U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 11974253551208964789U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 10596463592332655367U;
            aOrbiterA = RotL64((aOrbiterA * 10941161258815714641U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 12015129484061440159U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 8254944355710109060U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3233697992479357615U), 21U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterH, 3U);
            aIngress = aIngress + (RotL64(aOrbiterI, 24U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterC, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aScatter, 43U) + RotL64(aOrbiterA, 13U)) + aOrbiterC) + RotL64(aCarry, 53U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 21U) + aOrbiterI) + RotL64(aOrbiterB, 56U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 29U) + aOrbiterH) + RotL64(aOrbiterC, 21U)) + RotL64(aCarry, 37U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 4U) + RotL64(aOrbiterH, 39U)) + aOrbiterI);
            aWandererG = aWandererG + ((RotL64(aIngress, 53U) + aOrbiterH) + RotL64(aOrbiterB, 3U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + RotL64(aWandererG, 38U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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

void TwistExpander_Archery_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 1427U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneC[((aIndex + 6553U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 5953U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneA[((aIndex + 2534U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCross, 56U)) + (RotL64(aIngress, 11U) + RotL64(aCarry, 43U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = (aWandererI + RotL64(aPrevious, 3U)) + 1087148170018530502U;
            aOrbiterF = (((aWandererA + RotL64(aScatter, 56U)) + RotL64(aCarry, 23U)) + 15530846874509311414U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = (((aWandererE + RotL64(aCross, 13U)) + RotL64(aCarry, 37U)) + 16987358651515511212U) + aPhaseEOrbiterAssignSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = ((aWandererF + RotL64(aIngress, 37U)) + RotL64(aCarry, 11U)) + 12504143181007924259U;
            aOrbiterD = (aWandererH + RotL64(aPrevious, 47U)) + 393322117322732418U;
            aOrbiterC = (aWandererC + RotL64(aScatter, 27U)) + 14325937299241887166U;
            aOrbiterK = (aWandererJ + RotL64(aIngress, 19U)) + 9395262907017475742U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 13658510441418344769U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 6410754322737005336U;
            aOrbiterI = RotL64((aOrbiterI * 6932217611373076391U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 9257290738538818434U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 7489828960857692286U;
            aOrbiterD = RotL64((aOrbiterD * 16519674788777989043U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 4118778591214588387U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 16619215231168796563U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14876884956536265157U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 11326283811003573430U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 1865401866017614604U;
            aOrbiterK = RotL64((aOrbiterK * 8378326058282460073U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 670150121105733604U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 1499331510641068749U;
            aOrbiterA = RotL64((aOrbiterA * 16623742535540383107U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 1116410848560838532U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 2696841341036281779U;
            aOrbiterG = RotL64((aOrbiterG * 9598953298074904869U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 5487352391229549881U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 12008243050943342979U;
            aOrbiterF = RotL64((aOrbiterF * 9087261224804582459U), 21U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterC, 53U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 41U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + RotL64(aOrbiterK, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterI, 27U)) + aOrbiterA);
            aWandererH = aWandererH + (((RotL64(aScatter, 35U) + RotL64(aOrbiterA, 3U)) + aOrbiterK) + aPhaseEWandererUpdateSaltA[((aIndex + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterK, 13U)) + aOrbiterG);
            aWandererI = aWandererI + ((((RotL64(aIngress, 41U) + RotL64(aOrbiterC, 21U)) + aOrbiterA) + RotL64(aCarry, 5U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 13U) + aOrbiterF) + RotL64(aOrbiterC, 53U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 54U) + aOrbiterC) + RotL64(aOrbiterG, 37U)) + RotL64(aCarry, 57U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 3U) + aOrbiterF) + RotL64(aOrbiterD, 60U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 22U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererH, 47U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 12282U)) & S_BLOCK1], 28U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 12069U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 10375U)) & S_BLOCK1], 12U) ^ RotL64(aOperationLaneB[((aIndex + 16009U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 35U) + RotL64(aCross, 51U)) ^ (RotL64(aPrevious, 4U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = (aWandererG + RotL64(aScatter, 43U)) + 14157904117287696136U;
            aOrbiterC = (((aWandererK + RotL64(aCross, 60U)) + RotL64(aCarry, 3U)) + 7369512677371640676U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 3U)) + RotL64(aCarry, 39U)) + 8411250745902073798U;
            aOrbiterF = (aWandererD + RotL64(aIngress, 23U)) + 5002041814539710275U;
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 11U)) + RotL64(aCarry, 53U)) + 9538041410816283124U;
            aOrbiterB = (aWandererA + RotL64(aPrevious, 53U)) + 5210700103927513061U;
            aOrbiterA = ((aWandererE + RotL64(aIngress, 29U)) + 7600709399101287982U) + aPhaseEOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 2366369466696580499U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 5544575244203019109U;
            aOrbiterE = RotL64((aOrbiterE * 16231219246786333057U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 8710073749110329779U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 15998211310115361630U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15275657696897688955U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 15354357553877376422U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 10657523549259276169U;
            aOrbiterF = RotL64((aOrbiterF * 13695239532898311073U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 10405750198355464768U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 3465819693133515142U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14678343718277562799U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 16724189641701408630U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 3484340153620198872U;
            aOrbiterJ = RotL64((aOrbiterJ * 17247547677520703125U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 7420442404884871126U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 11138445997256757636U;
            aOrbiterB = RotL64((aOrbiterB * 11167543379937571127U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 1428191560884663125U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 16950093140800653985U;
            aOrbiterA = RotL64((aOrbiterA * 4423012306984814805U), 5U);
            //
            aIngress = RotL64(aOrbiterB, 35U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 27U));
            aIngress = aIngress + (RotL64(aOrbiterH, 5U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterC, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 43U) + aOrbiterH) + RotL64(aOrbiterE, 58U));
            aWandererK = aWandererK + (((RotL64(aScatter, 11U) + RotL64(aOrbiterJ, 5U)) + aOrbiterF) + RotL64(aCarry, 19U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterA, 51U)) + aOrbiterJ);
            aWandererE = aWandererE + (((RotL64(aIngress, 57U) + aOrbiterE) + RotL64(aOrbiterF, 43U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 18U) + aOrbiterA) + RotL64(aOrbiterB, 27U));
            aWandererJ = aWandererJ + ((((RotL64(aCross, 37U) + aOrbiterJ) + RotL64(aOrbiterB, 13U)) + RotL64(aCarry, 51U)) + aPhaseEWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterF, 35U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 5U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 40U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 51U));
            aCarry = aCarry + RotL64(aWandererJ, 23U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 18217U)) & S_BLOCK1], 18U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17195U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 20930U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 21072U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 51U) + RotL64(aCarry, 34U)) ^ (RotL64(aCross, 3U) ^ RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = ((aWandererF + RotL64(aScatter, 57U)) + RotL64(aCarry, 47U)) + 16462052553719977502U;
            aOrbiterG = ((aWandererI + RotL64(aCross, 21U)) + 12337064059566619581U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = (aWandererH + RotL64(aPrevious, 51U)) + 15801005007094515447U;
            aOrbiterE = ((aWandererK + RotL64(aIngress, 27U)) + RotL64(aCarry, 13U)) + 8228706742665081656U;
            aOrbiterJ = (aWandererC + RotL64(aCross, 35U)) + 11006723027845190869U;
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 5U)) + RotL64(aCarry, 27U)) + 18173765337829177450U;
            aOrbiterH = ((aWandererB + RotL64(aScatter, 44U)) + 530215083653542558U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 6608611827035564511U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 2246051826221626809U;
            aOrbiterA = RotL64((aOrbiterA * 6333352641495253539U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 5228575308895381421U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 10999213210689606857U;
            aOrbiterG = RotL64((aOrbiterG * 5467601259546342925U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 3773371037240485696U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 8887985779436152504U;
            aOrbiterB = RotL64((aOrbiterB * 698713082830739677U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 11150566414723818350U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 8336366151003049546U;
            aOrbiterE = RotL64((aOrbiterE * 9033771197242493699U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 13233968794237090787U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 8172558473508478819U;
            aOrbiterJ = RotL64((aOrbiterJ * 17837070423649268435U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 133564480283347997U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 15104810248883567064U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 706802420642303533U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 9138629520201127075U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 13993086066341664080U;
            aOrbiterH = RotL64((aOrbiterH * 4875046427147105077U), 5U);
            //
            aIngress = RotL64(aOrbiterE, 51U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 27U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 4U));
            aIngress = aIngress + RotL64(aOrbiterA, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aCross, 34U) + RotL64(aOrbiterJ, 3U)) + aOrbiterD) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 41U) + RotL64(aOrbiterA, 37U)) + aOrbiterB) + RotL64(aCarry, 35U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 47U) + aOrbiterE) + RotL64(aOrbiterA, 27U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aIngress, 13U) + RotL64(aOrbiterB, 10U)) + aOrbiterJ);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 21U) + aOrbiterG) + RotL64(aOrbiterB, 43U));
            aWandererF = aWandererF + (((RotL64(aIngress, 3U) + RotL64(aOrbiterJ, 21U)) + aOrbiterE) + RotL64(aCarry, 11U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterA, 57U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 18U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 29187U)) & S_BLOCK1], 6U) ^ RotL64(aWorkLaneB[((aIndex + 32644U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 29455U)) & S_BLOCK1], 52U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 29708U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 3U) + RotL64(aPrevious, 36U)) ^ (RotL64(aIngress, 21U) + RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 12U)) + 3612110001869385068U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = (aWandererG + RotL64(aCross, 57U)) + 16340824141280225936U;
            aOrbiterD = (aWandererA + RotL64(aPrevious, 29U)) + 15222338965130765231U;
            aOrbiterC = (aWandererF + RotL64(aIngress, 3U)) + 6649270508107155041U;
            aOrbiterI = ((aWandererH + RotL64(aCross, 37U)) + RotL64(aCarry, 41U)) + 768217258655426384U;
            aOrbiterK = (((aWandererI + RotL64(aScatter, 51U)) + RotL64(aCarry, 53U)) + 4481855259658861851U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 21U)) + RotL64(aCarry, 21U)) + 18318041934562434016U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 4212457153804401807U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 16143621095636987628U;
            aOrbiterD = RotL64((aOrbiterD * 6576072860505961427U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 2095664232866642086U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 4339527736737366572U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17503569508822244125U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 13679353177869884790U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 11582168502846418236U;
            aOrbiterH = RotL64((aOrbiterH * 135539430034462861U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 10451330452898542191U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 12951448817640617841U;
            aOrbiterI = RotL64((aOrbiterI * 4141870904192742091U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 15389161934419370747U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 4754886272708253014U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16638243718191281597U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 11746389873929280688U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 12042680172517298768U;
            aOrbiterC = RotL64((aOrbiterC * 3814780289755857543U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 2648103752465009244U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 451594673632597973U;
            aOrbiterA = RotL64((aOrbiterA * 8496763663271072425U), 37U);
            //
            aIngress = RotL64(aOrbiterJ, 19U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterA, 47U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterI, 5U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterH, 54U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterA, 43U)) + aOrbiterI);
            aWandererH = aWandererH + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterK, 29U)) + aOrbiterC) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterH, 37U)) + aOrbiterJ);
            aWandererE = aWandererE + (((RotL64(aScatter, 3U) + RotL64(aOrbiterK, 5U)) + aOrbiterI) + RotL64(aCarry, 53U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterD, 20U)) + aOrbiterC);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 21U) + RotL64(aOrbiterD, 11U)) + aOrbiterH) + RotL64(aCarry, 37U)) + aPhaseEWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 60U) + aOrbiterC) + RotL64(aOrbiterI, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 54U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererE, 35U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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

void TwistExpander_Archery_Arx::Twist_D(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 7318U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4881U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 5539U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneA[((aIndex + 2981U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 41U) ^ RotL64(aCarry, 6U)) ^ (RotL64(aPrevious, 23U) + RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 53U)) + RotL64(aCarry, 39U)) + 12849591986267890852U;
            aOrbiterI = ((aWandererB + RotL64(aScatter, 5U)) + RotL64(aCarry, 21U)) + 8232614804696815750U;
            aOrbiterG = ((aWandererK + RotL64(aIngress, 18U)) + 12141567259210877281U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = (aWandererA + RotL64(aCross, 37U)) + 2928641981037885644U;
            aOrbiterK = (((aWandererI + RotL64(aIngress, 27U)) + RotL64(aCarry, 57U)) + 980733350554783938U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 2683985177993350746U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 14532148403815527355U;
            aOrbiterG = RotL64((aOrbiterG * 15985362037094864225U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 7736296629433884203U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 10428437770166310549U;
            aOrbiterE = RotL64((aOrbiterE * 326634742742373401U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 18327174144859461029U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 6810436935194432002U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2715987179577753597U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 12606153309690753435U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 17123256945895150555U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13469111258504672565U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 9057777759026189541U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 16478485918911194442U;
            aOrbiterK = RotL64((aOrbiterK * 11054247078884894131U), 3U);
            //
            aIngress = RotL64(aOrbiterK, 18U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterD, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 22U) + aOrbiterD) + RotL64(aOrbiterI, 40U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 3U) + RotL64(aOrbiterD, 53U)) + aOrbiterE) + RotL64(aCarry, 23U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterK, 21U)) + aOrbiterE);
            aWandererK = aWandererK + ((((RotL64(aIngress, 53U) + RotL64(aOrbiterK, 11U)) + aOrbiterG) + RotL64(aCarry, 39U)) + aPhaseFWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterI, 29U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererJ, 3U);
            aCarry = aCarry + RotL64(aIngress, 58U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 11063U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 13902U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 12995U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneB[((aIndex + 10200U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCarry, 34U)) + (RotL64(aCross, 21U) ^ RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = (aWandererC + RotL64(aScatter, 60U)) + 9023059520606551446U;
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 43U)) + 662441755115638133U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = ((aWandererE + RotL64(aCross, 29U)) + RotL64(aCarry, 27U)) + 16957253361196144712U;
            aOrbiterF = (((aWandererK + RotL64(aIngress, 21U)) + RotL64(aCarry, 3U)) + 7840955025765308605U) + aPhaseFOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = ((aWandererB + RotL64(aScatter, 13U)) + RotL64(aCarry, 53U)) + 346855809270395799U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 16099139781586668343U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 3706457327118322098U;
            aOrbiterI = RotL64((aOrbiterI * 7810030620470889591U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 12166825885547622870U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 7792658665720344200U;
            aOrbiterA = RotL64((aOrbiterA * 16305542632794270697U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 7128477606152986326U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 11116533962780290084U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11993485572912492297U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 10443889548568288532U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 4402387036946561017U;
            aOrbiterB = RotL64((aOrbiterB * 9032964741841833277U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 13002706161178447654U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 13929727277530310708U;
            aOrbiterF = RotL64((aOrbiterF * 7005639090871200285U), 29U);
            //
            aIngress = RotL64(aOrbiterA, 5U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 57U));
            aIngress = aIngress + RotL64(aOrbiterB, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aScatter, 43U) + aOrbiterB) + RotL64(aOrbiterJ, 20U));
            aWandererB = aWandererB + (((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 39U)) + aOrbiterB) + RotL64(aCarry, 53U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 21U) + aOrbiterI) + RotL64(aOrbiterA, 47U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aCross, 12U) + RotL64(aOrbiterI, 57U)) + aOrbiterF) + RotL64(aCarry, 41U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterI, 11U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 54U));
            aCarry = aCarry + RotL64(aWandererB, 11U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 22502U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((aIndex + 16544U)) & S_BLOCK1], 34U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17864U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 16841U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 35U) + RotL64(aPrevious, 23U)) + (RotL64(aIngress, 52U) ^ RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = (((aWandererE + RotL64(aIngress, 5U)) + RotL64(aCarry, 21U)) + 8793908991006073956U) + aPhaseFOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 27U)) + RotL64(aCarry, 47U)) + 2932916283348441943U;
            aOrbiterB = ((aWandererI + RotL64(aScatter, 19U)) + RotL64(aCarry, 3U)) + 11069042087940968262U;
            aOrbiterH = (aWandererF + RotL64(aCross, 56U)) + 14369628676782894441U;
            aOrbiterC = ((aWandererD + RotL64(aScatter, 35U)) + 8602903272780978282U) + aPhaseFOrbiterAssignSaltB[((aIndex + 24U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 3827036107178568820U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 8905245209036772489U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5744017326197157667U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 13331387530760017893U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 9880107580289737823U;
            aOrbiterA = RotL64((aOrbiterA * 10302652857542703753U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 10199619040626900278U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 2466307560891374281U;
            aOrbiterF = RotL64((aOrbiterF * 6295342978834217571U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 13973403407981259448U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 2851460278409385243U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11226902976321781743U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 10365453393815690776U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 2382382358987358791U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 481563628980705781U), 43U);
            //
            aIngress = RotL64(aOrbiterF, 11U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterB, 22U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aCross, 23U) + aOrbiterH) + RotL64(aOrbiterB, 29U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 3U) + RotL64(aOrbiterB, 43U)) + aOrbiterC) + RotL64(aCarry, 35U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 12U) + RotL64(aOrbiterB, 53U)) + aOrbiterA);
            aWandererH = aWandererH + (((RotL64(aScatter, 57U) + RotL64(aOrbiterA, 20U)) + aOrbiterF) + RotL64(aCarry, 51U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterA, 5U)) + aOrbiterC) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 4U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 21U));
            aCarry = aCarry + RotL64(aWandererD, 43U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 26093U)) & S_BLOCK1], 30U) ^ RotL64(aWorkLaneB[((aIndex + 30832U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 31432U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 27747U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 36U) ^ RotL64(aPrevious, 53U)) + (RotL64(aIngress, 3U) + RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = ((aWandererA + RotL64(aIngress, 41U)) + 1087148170018530502U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = ((aWandererI + RotL64(aScatter, 11U)) + RotL64(aCarry, 23U)) + 15530846874509311414U;
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 52U)) + RotL64(aCarry, 39U)) + 16987358651515511212U;
            aOrbiterF = ((aWandererK + RotL64(aCross, 3U)) + RotL64(aCarry, 57U)) + 12504143181007924259U;
            aOrbiterB = ((aWandererH + RotL64(aIngress, 29U)) + 393322117322732418U) + aPhaseFOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 14325937299241887166U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 9395262907017475742U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3442643798173589117U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 13658510441418344769U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 6410754322737005336U;
            aOrbiterD = RotL64((aOrbiterD * 6932217611373076391U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 9257290738538818434U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 7489828960857692286U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16519674788777989043U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 4118778591214588387U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 16619215231168796563U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14876884956536265157U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 11326283811003573430U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 1865401866017614604U;
            aOrbiterB = RotL64((aOrbiterB * 8378326058282460073U), 35U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterC, 43U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + RotL64(aOrbiterF, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 11U) + aOrbiterC) + RotL64(aOrbiterK, 30U));
            aWandererH = aWandererH + ((((RotL64(aCross, 28U) + aOrbiterB) + RotL64(aOrbiterD, 13U)) + RotL64(aCarry, 27U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterD, 57U)) + aOrbiterK) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterC, 41U)) + aOrbiterF) + RotL64(aCarry, 39U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 57U) + aOrbiterB) + RotL64(aOrbiterF, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererH);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 21U));
            aCarry = aCarry + RotL64(aWandererI, 29U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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

void TwistExpander_Archery_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 5148U)) & S_BLOCK1], 6U) ^ RotL64(aWorkLaneB[((aIndex + 6716U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 2321U)) & S_BLOCK1], 10U) ^ RotL64(aWorkLaneD[((aIndex + 2882U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 54U) ^ RotL64(aIngress, 35U)) + (RotL64(aPrevious, 11U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = ((aWandererK + RotL64(aCross, 53U)) + 77518479758428414U) + aPhaseGOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = ((aWandererI + RotL64(aScatter, 39U)) + RotL64(aCarry, 5U)) + 4832061802166300011U;
            aOrbiterI = ((aWandererG + RotL64(aIngress, 23U)) + RotL64(aCarry, 53U)) + 11695291171006574112U;
            aOrbiterB = (aWandererE + RotL64(aPrevious, 4U)) + 7467412817843260094U;
            aOrbiterJ = (((aWandererF + RotL64(aCross, 13U)) + RotL64(aCarry, 19U)) + 17801484124471154757U) + aPhaseGOrbiterAssignSaltD[((aIndex + 26U)) & S_SALT1];
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 5555455638503958639U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 5669470540733721606U;
            aOrbiterI = RotL64((aOrbiterI * 17219613748084498879U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 3042388456327784163U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 2236734925228156691U;
            aOrbiterD = RotL64((aOrbiterD * 10076582424701705531U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 14459720401528685450U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 4814967631216658856U;
            aOrbiterB = RotL64((aOrbiterB * 18288097536171386643U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 16950679344449075945U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 6262238639302011050U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9942659897425088183U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 3522256359074996724U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 12524717897707074242U;
            aOrbiterJ = RotL64((aOrbiterJ * 6787771338063891989U), 51U);
            //
            aIngress = RotL64(aOrbiterA, 37U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterJ, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aPrevious, 46U) + aOrbiterA) + RotL64(aOrbiterJ, 57U)) + RotL64(aCarry, 39U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 35U) + aOrbiterI) + RotL64(aOrbiterJ, 35U));
            aWandererG = aWandererG + ((((RotL64(aIngress, 23U) + RotL64(aOrbiterI, 5U)) + aOrbiterD) + RotL64(aCarry, 23U)) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 3U) + aOrbiterD) + RotL64(aOrbiterB, 21U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 13U) + aOrbiterJ) + RotL64(aOrbiterD, 46U)) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 37U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 50U));
            aCarry = aCarry + RotL64(aWandererG, 29U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 12079U)) & S_BLOCK1], 44U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 14435U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 9719U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 13639U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aPrevious, 5U)) ^ (RotL64(aCarry, 56U) + RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = (((aWandererH + RotL64(aCross, 3U)) + RotL64(aCarry, 27U)) + 9630214189402543339U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterE = (aWandererC + RotL64(aScatter, 27U)) + 4072576573737526819U;
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 12U)) + RotL64(aCarry, 43U)) + 15994787452709618869U;
            aOrbiterK = (((aWandererK + RotL64(aIngress, 57U)) + RotL64(aCarry, 13U)) + 6403240137132259482U) + aPhaseGOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = (aWandererB + RotL64(aCross, 47U)) + 10229266900170507720U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 5025294577989748989U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 16696461238217956883U;
            aOrbiterI = RotL64((aOrbiterI * 15993828976234917577U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 9878318855341719119U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 16086635438116177346U;
            aOrbiterA = RotL64((aOrbiterA * 5585682357395705671U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 12295437783084203730U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 7681150419912842402U;
            aOrbiterB = RotL64((aOrbiterB * 7289497379725191451U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 2639104034287637448U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 12298170009332243573U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9397919591171238575U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 3485932317267669626U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 16569551670038752475U;
            aOrbiterK = RotL64((aOrbiterK * 8139802826402217631U), 29U);
            //
            aIngress = RotL64(aOrbiterK, 13U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aScatter, 36U) + aOrbiterK) + RotL64(aOrbiterI, 13U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterB, 3U)) + aOrbiterE) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aCross, 53U) + aOrbiterA) + RotL64(aOrbiterI, 41U)) + RotL64(aCarry, 53U)) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterA, 58U)) + aOrbiterB);
            aWandererC = aWandererC + (((RotL64(aScatter, 21U) + aOrbiterE) + RotL64(aOrbiterK, 23U)) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 12U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + RotL64(aWandererK, 3U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 18044U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 19481U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 21522U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 21854U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 35U) + RotL64(aIngress, 53U)) + (RotL64(aPrevious, 18U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = (((aWandererE + RotL64(aScatter, 5U)) + RotL64(aCarry, 37U)) + 13650869943246163567U) + aPhaseGOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = ((aWandererI + RotL64(aIngress, 36U)) + RotL64(aCarry, 19U)) + 3435284932011770999U;
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 21U)) + 12388155658186776579U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = ((aWandererH + RotL64(aCross, 13U)) + RotL64(aCarry, 3U)) + 2374345913955712039U;
            aOrbiterK = (aWandererD + RotL64(aScatter, 53U)) + 6095094526980292156U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 4965147025852444174U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 3261881216269075298U;
            aOrbiterF = RotL64((aOrbiterF * 4874733445914960785U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 4939780217097329222U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 3019862009792676287U;
            aOrbiterD = RotL64((aOrbiterD * 2452316208025448747U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 901910626217143974U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 3647055146712366383U;
            aOrbiterB = RotL64((aOrbiterB * 1792602402476450009U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 7731765438957392967U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 13409819457393479741U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3345078200262410715U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 5415832109107794258U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 8876738832313114471U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1304277600444504135U), 35U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterF, 13U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 3U));
            aIngress = aIngress + RotL64(aOrbiterD, 42U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 43U) + aOrbiterD) + RotL64(aOrbiterB, 43U));
            aWandererE = aWandererE + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterG, 51U)) + aOrbiterB) + RotL64(aCarry, 47U)) + aPhaseGWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 5U) + aOrbiterG) + RotL64(aOrbiterK, 35U)) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 29U) + RotL64(aOrbiterG, 23U)) + aOrbiterF) + RotL64(aCarry, 35U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 20U) + RotL64(aOrbiterF, 6U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererC);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + RotL64(aWandererI, 39U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 30379U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25871U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31675U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 30306U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aIngress, 19U)) ^ (RotL64(aCross, 6U) + RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = ((aWandererE + RotL64(aCross, 30U)) + RotL64(aCarry, 13U)) + 9914837590440975587U;
            aOrbiterC = (((aWandererI + RotL64(aIngress, 39U)) + RotL64(aCarry, 29U)) + 6706125076401958051U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 51U)) + 16570817772679258409U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 3U)) + RotL64(aCarry, 57U)) + 6843705658115186948U;
            aOrbiterB = (aWandererH + RotL64(aScatter, 11U)) + 16099930446791572351U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 5420550009556030459U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 5729549069420177477U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7842192631021712569U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 15590601126188675834U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 13044027390998620029U;
            aOrbiterF = RotL64((aOrbiterF * 16845199115313444123U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 11068338135659636772U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 6584988841809544332U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1683336180438945439U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 8516813219883915404U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 10647314042912492785U;
            aOrbiterC = RotL64((aOrbiterC * 15559481057047148785U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 201691689889605304U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 15512161798401184003U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11473219183982564709U), 11U);
            //
            aIngress = RotL64(aOrbiterG, 3U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterJ, 13U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterC, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aScatter, 37U) + aOrbiterJ) + RotL64(aOrbiterG, 13U)) + aPhaseGWandererUpdateSaltA[((aIndex + 4U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 29U) + aOrbiterB) + RotL64(aOrbiterG, 21U));
            aWandererG = aWandererG + ((((RotL64(aCross, 57U) + aOrbiterG) + RotL64(aOrbiterF, 43U)) + RotL64(aCarry, 27U)) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterB, 35U)) + aOrbiterF);
            aWandererI = aWandererI + (((RotL64(aPrevious, 18U) + aOrbiterC) + RotL64(aOrbiterJ, 60U)) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 53U));
            aCarry = aCarry + RotL64(aWandererE, 21U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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

void TwistExpander_Archery_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterI = 0;

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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 5379U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 7259U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 854U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneD[((aIndex + 5170U)) & S_BLOCK1], 28U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 13U) ^ RotL64(aCross, 41U)) ^ (RotL64(aCarry, 57U) + RotL64(aIngress, 26U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = (((aWandererE + RotL64(aScatter, 57U)) + RotL64(aCarry, 53U)) + 8375305456876489425U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterE = ((aWandererH + RotL64(aIngress, 29U)) + RotL64(aCarry, 35U)) + 16193562952772453047U;
            aOrbiterA = (aWandererK + RotL64(aCross, 19U)) + 18088652458594816223U;
            aOrbiterD = (((aWandererA + RotL64(aPrevious, 42U)) + RotL64(aCarry, 19U)) + 767344788620249944U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = (aWandererC + RotL64(aScatter, 5U)) + 7705194930396368752U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 3829736891311272834U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 9881681671347640061U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14380245087931793021U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 1721196560190164264U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 3002652618388454213U;
            aOrbiterC = RotL64((aOrbiterC * 15289749311593032657U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 9811621464004005202U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 5652598941069986530U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4797973356708091621U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 6250499348327316328U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 16025054277615264530U;
            aOrbiterE = RotL64((aOrbiterE * 16446892258704281903U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 13800298546867243172U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 12256104592865905782U;
            aOrbiterF = RotL64((aOrbiterF * 16983140179497142713U), 29U);
            //
            aIngress = RotL64(aOrbiterA, 29U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 6U));
            aIngress = aIngress + RotL64(aOrbiterF, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterD, 36U)) + aOrbiterE);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 21U) + aOrbiterA) + RotL64(aOrbiterF, 11U)) + RotL64(aCarry, 57U)) + aPhaseHWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 29U) + aOrbiterA) + RotL64(aOrbiterC, 47U));
            aWandererE = aWandererE + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 21U)) + aOrbiterE) + RotL64(aCarry, 37U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 54U) + aOrbiterD) + RotL64(aOrbiterC, 3U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 60U));
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererK, 37U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 11800U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneC[((aIndex + 14396U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 14395U)) & S_BLOCK1], 22U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14419U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCross, 5U)) + (RotL64(aCarry, 36U) ^ RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = ((aWandererK + RotL64(aCross, 41U)) + RotL64(aCarry, 29U)) + 898812731947995389U;
            aOrbiterF = ((aWandererC + RotL64(aIngress, 11U)) + 8677347622525527167U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = ((aWandererF + RotL64(aScatter, 56U)) + RotL64(aCarry, 51U)) + 770321564027567654U;
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 21U)) + 11020474858081526395U) + aPhaseHOrbiterAssignSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterH = ((aWandererI + RotL64(aIngress, 3U)) + RotL64(aCarry, 13U)) + 17289793580414993470U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 10111912559295118444U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 8083622125544542011U;
            aOrbiterG = RotL64((aOrbiterG * 3610772128071340341U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 7149858558922988240U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 5919683821379905699U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16705119888884231567U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 6860902846079238714U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 15083517836867542075U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4686657139237578325U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 14852868368708376381U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 9860233289028878323U;
            aOrbiterF = RotL64((aOrbiterF * 13418143547952204667U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 772406119079116272U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 7971141501337627589U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10168120622976358617U), 57U);
            //
            aIngress = RotL64(aOrbiterG, 35U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterF, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aPrevious, 35U) + aOrbiterG) + RotL64(aOrbiterH, 51U)) + aPhaseHWandererUpdateSaltE[((aIndex + 28U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterF, 21U)) + aOrbiterI);
            aWandererI = aWandererI + (((RotL64(aScatter, 47U) + aOrbiterI) + RotL64(aOrbiterB, 13U)) + RotL64(aCarry, 53U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 20U) + RotL64(aOrbiterF, 60U)) + aOrbiterB) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 57U) + aOrbiterI) + RotL64(aOrbiterH, 37U)) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + RotL64(aWandererE, 3U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 18662U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneD[((aIndex + 22208U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23913U)) & S_BLOCK1], 6U) ^ RotL64(aWorkLaneB[((aIndex + 23079U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 35U) ^ RotL64(aPrevious, 23U)) + (RotL64(aCross, 3U) ^ RotL64(aIngress, 50U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 37U)) + 479672811032092393U) + aPhaseHOrbiterAssignSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = (aWandererG + RotL64(aIngress, 3U)) + 18061121631394564425U;
            aOrbiterI = (((aWandererI + RotL64(aScatter, 52U)) + RotL64(aCarry, 19U)) + 14237400452740566065U) + aPhaseHOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = ((aWandererK + RotL64(aCross, 11U)) + RotL64(aCarry, 37U)) + 6723123812257706134U;
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 21U)) + RotL64(aCarry, 57U)) + 4247997188026499248U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 1939107415066134869U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 3912640123546395979U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9779626695085572877U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 8295478436553964298U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 3218960600711526885U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15443507655470278069U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 5874096203353388890U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 10294536533673023358U;
            aOrbiterA = RotL64((aOrbiterA * 15561710414949058923U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 11268561953904130747U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 16693201256788898423U;
            aOrbiterC = RotL64((aOrbiterC * 16291987237693567209U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 7550969634681894654U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 9501647424602245869U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11265865222096866605U), 43U);
            //
            aIngress = RotL64(aOrbiterA, 13U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 26U));
            aIngress = aIngress + RotL64(aOrbiterF, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aCross, 5U) + aOrbiterC) + RotL64(aOrbiterB, 14U)) + RotL64(aCarry, 19U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 35U) + aOrbiterA) + RotL64(aOrbiterC, 5U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 13U) + aOrbiterA) + RotL64(aOrbiterF, 39U)) + RotL64(aCarry, 39U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 52U) + aOrbiterI) + RotL64(aOrbiterF, 29U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 21U) + RotL64(aOrbiterC, 51U)) + aOrbiterI) + aPhaseHWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererJ);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + RotL64(aWandererG, 47U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 32435U)) & S_BLOCK1], 30U) ^ RotL64(aWorkLaneA[((aIndex + 27876U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29582U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 28261U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 47U) + RotL64(aCross, 35U)) ^ (RotL64(aCarry, 4U) ^ RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = ((aWandererA + RotL64(aScatter, 39U)) + RotL64(aCarry, 27U)) + 5510690816044082200U;
            aOrbiterA = (((aWandererE + RotL64(aIngress, 60U)) + RotL64(aCarry, 13U)) + 15967820875033940530U) + aPhaseHOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = (((aWandererB + RotL64(aPrevious, 5U)) + RotL64(aCarry, 41U)) + 539348720848176221U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = (aWandererI + RotL64(aCross, 21U)) + 15779318183635560817U;
            aOrbiterF = (aWandererD + RotL64(aScatter, 51U)) + 14511058534424187469U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 5811130556873428391U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 1085928476499444025U;
            aOrbiterG = RotL64((aOrbiterG * 13965845678632598921U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 6973335316600768130U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 10747243745475009744U;
            aOrbiterE = RotL64((aOrbiterE * 17322489216048017061U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 1072260008981349754U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 2018772405352495753U;
            aOrbiterB = RotL64((aOrbiterB * 10840562112080574241U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 1092091597048996547U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 15103140149542167197U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 621856991658027989U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 13194619321108681542U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 16749188603268621850U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9575408950550922039U), 51U);
            //
            aIngress = RotL64(aOrbiterB, 13U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterF, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aIngress, 5U) + RotL64(aOrbiterA, 46U)) + aOrbiterG) + RotL64(aCarry, 13U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterB, 13U)) + aOrbiterG) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 50U) + RotL64(aOrbiterB, 57U)) + aOrbiterF) + RotL64(aCarry, 41U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 21U) + aOrbiterF) + RotL64(aOrbiterE, 23U));
            aWandererD = aWandererD + (((RotL64(aIngress, 29U) + aOrbiterB) + RotL64(aOrbiterE, 5U)) + aPhaseHWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + (RotL64(aWandererB, 22U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererE, 5U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
