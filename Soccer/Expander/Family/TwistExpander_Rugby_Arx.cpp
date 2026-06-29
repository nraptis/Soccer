#include "TwistExpander_Rugby_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_Rugby_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xE8E15237B34E2CE5ULL + 0xB8F454B3ACCCABFAULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xD98D34B166CF870BULL + 0xB229DCDDF6B84CAEULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xD68EDEBF6F134853ULL + 0xC4F77BF4E48720E6ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xE2CD941FBB207209ULL + 0xEF0186E3D4EF8BA3ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xB149BF2747604AC3ULL + 0xF6C5BC807053031CULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xCE36FAC09DF4563DULL + 0x9785FA9315BE8C42ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xD2CFE0D0D4C57EE1ULL + 0xAAE90C337A5563C3ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xB16B976FF44D2815ULL + 0xBC2EC93FF99FFD98ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xEA3CC7CB10565D77ULL + 0xEB768791D0346E8AULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xBCEA163FD02E89EBULL + 0xF882650994DEC1CDULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xD947127318471891ULL + 0x9B67DE8CE087A5CEULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xA1FBB5AF8754B26BULL + 0xCE38BFA1D2C411CDULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xE17F9E25DBAD7467ULL + 0xB4E9DE1FB1B79B89ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xB15A51045CD5DACBULL + 0x833B43D245204AF9ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xAA91258FBD85C927ULL + 0xDFF9F7040D7F010EULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xD531D95D680621C1ULL + 0x8E94CF9ECC2885FFULL);
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
            aIngress = RotL64(mSource[((aIndex + 4252U)) & S_BLOCK1], 23U) ^ RotL64(pSnow[((aIndex + 3841U)) & S_BLOCK1], 12U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 1781U)) & S_BLOCK1], 53U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 2781U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aIngress, 24U)) ^ (RotL64(aPrevious, 53U) + RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterD = ((aWandererD + RotL64(aIngress, 35U)) + 11700815697312060726U) + aNonceWordM;
            aOrbiterI = (aWandererA + RotL64(aPrevious, 19U)) + 11808423452327465441U;
            aOrbiterF = (aWandererG + RotL64(aCross, 38U)) + 8670503858631730886U;
            aOrbiterG = ((aWandererI + RotL64(aScatter, 3U)) + 2400061067991988544U) + aOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 57U)) + 16163118178366229686U) + aNonceWordJ;
            aOrbiterC = (aWandererB + RotL64(aCross, 27U)) + 3280178595904941068U;
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 51U)) + RotL64(aCarry, 51U)) + 3298683600817047727U;
            aOrbiterB = (aWandererH + RotL64(aScatter, 43U)) + 16321624053445183574U;
            aOrbiterK = ((aWandererE + RotL64(aCross, 6U)) + 6730229877611375225U) + aNonceWordE;
            aOrbiterH = (((aWandererC + RotL64(aIngress, 11U)) + RotL64(aCarry, 3U)) + 10162830636713641322U) + aOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = ((aWandererK + RotL64(aScatter, 47U)) + RotL64(aCarry, 19U)) + 15646771327759599256U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 14841751262270544102U) + aNonceWordI;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 9545541117228834895U;
            aOrbiterF = RotL64((aOrbiterF * 11529769874752969377U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 14676615635857599982U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 1231768638470558855U;
            aOrbiterC = RotL64((aOrbiterC * 2716808508509014677U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 1945905595345404833U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 1406171421638586846U;
            aOrbiterB = RotL64((aOrbiterB * 4577864352425476233U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 1970292335806697198U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 12309719390375013297U;
            aOrbiterE = RotL64((aOrbiterE * 16540660957923687327U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 5352135521358954576U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 15465675376193501658U;
            aOrbiterH = RotL64((aOrbiterH * 16385761112921041387U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 2842123638916600369U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 3544764287036748668U;
            aOrbiterI = RotL64((aOrbiterI * 3360772950777850115U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 6038297172906492282U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 10249342332287140970U;
            aOrbiterA = RotL64((aOrbiterA * 16701083081566042277U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 1662076777040529446U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 1949705569959740274U;
            aOrbiterJ = RotL64((aOrbiterJ * 11340691546658994529U), 53U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterD) + 13934194245417822360U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordA;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 5720408806425535958U;
            aOrbiterK = RotL64((aOrbiterK * 15237561081637415383U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 2209251362417210658U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 4917447930929521699U) ^ aOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17489570156694692569U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 14817115766683623486U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 11700815697312060726U;
            aOrbiterD = RotL64((aOrbiterD * 16982411053956669181U), 51U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterA, 3U);
            aIngress = aIngress + (RotL64(aOrbiterK, 5U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 27U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 43U));
            aIngress = aIngress + (RotL64(aOrbiterH, 30U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterG, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aIngress, 60U) + RotL64(aOrbiterH, 3U)) + aOrbiterA) + aWandererUpdateSaltD[((aIndex + 18U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 51U) + aOrbiterD) + RotL64(aOrbiterH, 23U));
            aWandererH = aWandererH + (((RotL64(aScatter, 27U) + aOrbiterJ) + RotL64(aOrbiterI, 41U)) + RotL64(aCarry, 13U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterE, 13U)) + aOrbiterA);
            aWandererB = aWandererB + (((RotL64(aScatter, 53U) + RotL64(aOrbiterB, 39U)) + aOrbiterI) + aNonceWordL);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 35U) + aOrbiterG) + RotL64(aOrbiterK, 54U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 23U) + aOrbiterJ) + RotL64(aOrbiterK, 51U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterH, 37U)) + aOrbiterC) + aNonceWordD);
            aWandererI = aWandererI + (((RotL64(aIngress, 13U) + aOrbiterI) + RotL64(aOrbiterK, 21U)) + RotL64(aCarry, 35U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 21U) + aOrbiterF) + RotL64(aOrbiterD, 19U)) + aWandererUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aPrevious, 44U) + aOrbiterJ) + RotL64(aOrbiterE, 44U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererJ, 56U) ^ aWandererF);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererH, 39U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 23U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 6184U)) & S_BLOCK1], 36U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 9776U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 9794U)) & S_BLOCK1], 5U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 6520U)) & S_BLOCK1], 42U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCarry, 35U) ^ RotL64(aIngress, 47U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCross, 20U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterI = ((aWandererF + RotL64(aIngress, 51U)) + RotL64(aCarry, 19U)) + 18087125778766689269U;
            aOrbiterJ = ((aWandererH + RotL64(aCross, 37U)) + RotL64(aCarry, 23U)) + 13710545066503235196U;
            aOrbiterF = ((aWandererG + RotL64(aScatter, 26U)) + RotL64(aCarry, 37U)) + 1701939704736254645U;
            aOrbiterK = (aWandererE + RotL64(aPrevious, 43U)) + 8064093611384019909U;
            aOrbiterE = (aWandererA + RotL64(aScatter, 21U)) + 16623332751533885431U;
            aOrbiterD = ((aWandererC + RotL64(aCross, 35U)) + 15590129153794910109U) + aNonceWordP;
            aOrbiterH = (((aWandererI + RotL64(aIngress, 11U)) + 7413312683079107383U) + aOrbiterAssignSaltB[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordL;
            aOrbiterC = (aWandererJ + RotL64(aPrevious, 13U)) + 4186064478651458810U;
            aOrbiterG = ((aWandererB + RotL64(aCross, 60U)) + 5501191643940735954U) + aOrbiterAssignSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = (aWandererK + RotL64(aIngress, 57U)) + 11064645242200570835U;
            aOrbiterB = (aWandererD + RotL64(aScatter, 19U)) + 13825922087298055833U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 5944980709887369970U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 8181136916070569646U) ^ aNonceWordN;
            aOrbiterF = RotL64((aOrbiterF * 395183021205661827U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 15442336949157292482U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 11580554435240641337U) ^ aOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6654637892858767739U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 11240018128174598322U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 2027565596050777471U;
            aOrbiterC = RotL64((aOrbiterC * 18048186560314431815U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 16425887196883725233U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 16828683527588834095U;
            aOrbiterG = RotL64((aOrbiterG * 17746289103235902485U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 9923829146479008804U) + aNonceWordD;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 6669171007279929454U;
            aOrbiterK = RotL64((aOrbiterK * 681823450939955099U), 43U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterB) + 3902430046523165149U) + aOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1]) + aNonceWordM;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 6739998149289590041U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2675037435528416821U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 16014401255534234075U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 14741857638680634564U;
            aOrbiterH = RotL64((aOrbiterH * 8723611021403369393U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 5064807861673260054U) + aNonceWordF;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 968747317273200299U;
            aOrbiterB = RotL64((aOrbiterB * 14122304002722582329U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 5282686212362051427U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 6902253563196129760U;
            aOrbiterJ = RotL64((aOrbiterJ * 7682808024658992049U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 4995580401402368332U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 14949762584793646470U;
            aOrbiterA = RotL64((aOrbiterA * 3539183342072953803U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 2378815735788107402U) + aOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 18087125778766689269U;
            aOrbiterE = RotL64((aOrbiterE * 16799380528404446281U), 47U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterA, 13U);
            aIngress = aIngress + (RotL64(aOrbiterG, 27U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterJ, 35U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterC, 11U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterH, 50U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterI, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aPrevious, 41U) + aOrbiterC) + RotL64(aOrbiterB, 23U)) + RotL64(aCarry, 37U)) + aNonceWordC);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 24U) + RotL64(aOrbiterH, 39U)) + aOrbiterC);
            aWandererA = aWandererA + (((RotL64(aScatter, 5U) + RotL64(aOrbiterI, 26U)) + aOrbiterF) + RotL64(aCarry, 57U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 27U) + aOrbiterC) + RotL64(aOrbiterA, 5U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 29U) + aOrbiterE) + RotL64(aOrbiterF, 47U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterG, 29U)) + aOrbiterC);
            aWandererC = aWandererC + ((RotL64(aCross, 43U) + RotL64(aOrbiterI, 41U)) + aOrbiterH);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterJ, 37U)) + aOrbiterH) + aWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 53U) + RotL64(aOrbiterJ, 51U)) + aOrbiterK) + aNonceWordJ) + aWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 47U) + aOrbiterA) + RotL64(aOrbiterF, 57U)) + aNonceWordH);
            aWandererB = aWandererB + (((RotL64(aCross, 34U) + aOrbiterI) + RotL64(aOrbiterD, 34U)) + aNonceWordK);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 28U));
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 5U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 44U));
            aCarry = aCarry + RotL64(aWandererG, 11U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 12177U)) & S_BLOCK1], 43U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 12845U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 13347U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((aIndex + 14977U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aPrevious, 34U)) ^ (RotL64(aIngress, 47U) + RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 60U)) + RotL64(aCarry, 11U)) + 9914837590440975587U;
            aOrbiterK = (aWandererK + RotL64(aPrevious, 5U)) + 6706125076401958051U;
            aOrbiterE = (aWandererJ + RotL64(aScatter, 13U)) + 16570817772679258409U;
            aOrbiterH = (aWandererF + RotL64(aCross, 37U)) + 6843705658115186948U;
            aOrbiterA = ((aWandererD + RotL64(aScatter, 47U)) + 16099930446791572351U) + aOrbiterAssignSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterF = (aWandererG + RotL64(aIngress, 35U)) + 5420550009556030459U;
            aOrbiterG = ((aWandererE + RotL64(aCross, 28U)) + 5729549069420177477U) + aNonceWordH;
            aOrbiterI = (((aWandererA + RotL64(aPrevious, 39U)) + 15590601126188675834U) + aOrbiterAssignSaltE[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordD;
            aOrbiterB = ((aWandererB + RotL64(aCross, 11U)) + RotL64(aCarry, 27U)) + 13044027390998620029U;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 23U)) + RotL64(aCarry, 47U)) + 11068338135659636772U;
            aOrbiterC = (aWandererI + RotL64(aScatter, 3U)) + 6584988841809544332U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 8516813219883915404U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 10647314042912492785U) ^ aNonceWordE;
            aOrbiterE = RotL64((aOrbiterE * 15559481057047148785U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 201691689889605304U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 15512161798401184003U;
            aOrbiterF = RotL64((aOrbiterF * 11473219183982564709U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 3883760518944464145U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 13861805129175491145U;
            aOrbiterA = RotL64((aOrbiterA * 17194438894492581181U), 11U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterB) + 12019138626550801486U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordP;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 13030350224959652248U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11724200983306280107U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 2643807255422544248U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 4127143302485631794U;
            aOrbiterC = RotL64((aOrbiterC * 5441038881111578487U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 14602951930809633069U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 4555737199162278494U;
            aOrbiterG = RotL64((aOrbiterG * 12415825635220991865U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 6343143902997169834U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 10404783711336491985U;
            aOrbiterB = RotL64((aOrbiterB * 6235474458879439079U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 7406959231434835393U) + aOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 6684368109277850196U;
            aOrbiterD = RotL64((aOrbiterD * 8760360417572331159U), 53U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterE) + 4835889355927954728U) + aOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1]) + aNonceWordO;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 7917682889852676712U;
            aOrbiterH = RotL64((aOrbiterH * 9045350756570117327U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 10268055422944417055U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 5563744562922937643U;
            aOrbiterI = RotL64((aOrbiterI * 12442484191329795173U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 17244672945880141679U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 9914837590440975587U;
            aOrbiterJ = RotL64((aOrbiterJ * 12269340309792850489U), 41U);
            //
            aIngress = RotL64(aOrbiterK, 18U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterD, 37U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 47U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + (RotL64(aOrbiterE, 43U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterG, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aScatter, 27U) + aOrbiterF) + RotL64(aOrbiterC, 43U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 5U) + aOrbiterG) + RotL64(aOrbiterI, 20U));
            aWandererA = aWandererA + (((RotL64(aIngress, 34U) + aOrbiterA) + RotL64(aOrbiterG, 47U)) + RotL64(aCarry, 39U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 19U) + aOrbiterH) + RotL64(aOrbiterJ, 39U)) + aNonceWordL);
            aWandererK = aWandererK + (((RotL64(aCross, 29U) + RotL64(aOrbiterF, 3U)) + aOrbiterB) + aWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 3U) + aOrbiterB) + RotL64(aOrbiterD, 18U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 13U) + RotL64(aOrbiterH, 37U)) + aOrbiterF);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 41U) + aOrbiterK) + RotL64(aOrbiterI, 13U)) + aWandererUpdateSaltA[((aIndex + 6U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 37U) + RotL64(aOrbiterG, 29U)) + aOrbiterE) + RotL64(aCarry, 57U)) + aNonceWordN);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 22U) + RotL64(aOrbiterJ, 57U)) + aOrbiterF);
            aWandererG = aWandererG + ((RotL64(aCross, 51U) + RotL64(aOrbiterG, 5U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + (RotL64(aWandererA, 14U) ^ aWandererI);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 5U));
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererC, 40U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 18816U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((aIndex + 16817U)) & S_BLOCK1], 54U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 19866U)) & S_BLOCK1], 5U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 21350U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17811U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 29U) ^ RotL64(aCarry, 43U)) + (RotL64(aCross, 6U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterC = ((aWandererK + RotL64(aCross, 47U)) + 9774364261626083532U) + aNonceWordO;
            aOrbiterA = (aWandererH + RotL64(aPrevious, 3U)) + 18059001521926116420U;
            aOrbiterI = (((aWandererI + RotL64(aIngress, 41U)) + 10615626210406381148U) + aOrbiterAssignSaltC[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordL;
            aOrbiterF = (aWandererB + RotL64(aScatter, 58U)) + 10536484278007898620U;
            aOrbiterH = ((aWandererG + RotL64(aCross, 21U)) + 13320663045139972700U) + aOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 19U)) + RotL64(aCarry, 53U)) + 17127001787268166583U;
            aOrbiterK = ((aWandererE + RotL64(aIngress, 43U)) + RotL64(aCarry, 23U)) + 16742574590844166551U;
            aOrbiterG = (aWandererF + RotL64(aScatter, 6U)) + 8347719720758228053U;
            aOrbiterD = (aWandererJ + RotL64(aPrevious, 13U)) + 13502468705946051986U;
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 51U)) + RotL64(aCarry, 41U)) + 3512687886188904904U;
            aOrbiterE = (aWandererD + RotL64(aIngress, 37U)) + 495660316165795934U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 5092722552034477356U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 15641128019608284015U;
            aOrbiterI = RotL64((aOrbiterI * 3621036395703527059U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 15421873776811085458U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 17978775513204574125U) ^ aNonceWordC;
            aOrbiterC = RotL64((aOrbiterC * 18359600395119440183U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 16617179197537669849U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 1931805387534012528U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3400139345857733775U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 9544923119559308431U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 12930999400470173353U;
            aOrbiterD = RotL64((aOrbiterD * 16791006919271490005U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 13673733276226249890U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 2032263473309124738U) ^ aOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3088728329261360607U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 14868502349358414206U) + aNonceWordD;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 10116495537187552321U) ^ aNonceWordE;
            aOrbiterF = RotL64((aOrbiterF * 1380512121796709469U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 5341113995358179244U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 8415417980279705731U;
            aOrbiterB = RotL64((aOrbiterB * 8521501372683793821U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 2462819265072352463U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 7657062767608441931U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15554638801273540163U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 8153420530633265789U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 10990681417675210534U;
            aOrbiterA = RotL64((aOrbiterA * 1928509513380702895U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 17035995983178569271U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 2806563871848226777U) ^ aOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4137935663733587867U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 6570698907081812011U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 9774364261626083532U;
            aOrbiterE = RotL64((aOrbiterE * 1766375419340392741U), 23U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterI, 51U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 27U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 37U));
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aPrevious, 53U) + RotL64(aOrbiterG, 5U)) + aOrbiterE) + RotL64(aCarry, 3U)) + aWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 60U) + RotL64(aOrbiterH, 35U)) + aOrbiterA);
            aWandererH = aWandererH + ((RotL64(aIngress, 5U) + aOrbiterA) + RotL64(aOrbiterE, 47U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterI, 23U)) + aOrbiterH);
            aWandererF = aWandererF + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterD, 11U)) + aOrbiterH);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterA, 19U)) + aOrbiterC) + aWandererUpdateSaltC[((aIndex + 4U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 36U) + RotL64(aOrbiterC, 56U)) + aOrbiterB) + RotL64(aCarry, 57U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 47U) + aOrbiterC) + RotL64(aOrbiterK, 37U)) + aNonceWordI);
            aWandererC = aWandererC + ((RotL64(aScatter, 19U) + RotL64(aOrbiterA, 21U)) + aOrbiterF);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 51U) + aOrbiterJ) + RotL64(aOrbiterH, 53U)) + aNonceWordF);
            aWandererA = aWandererA + ((RotL64(aCross, 11U) + RotL64(aOrbiterI, 30U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererH);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 51U));
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererE, 30U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererA, 57U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 24102U)) & S_BLOCK1], 29U) ^ RotL64(mSource[((aIndex + 25307U)) & S_BLOCK1], 53U));
            aIngress ^= (RotL64(pSnow[((aIndex + 21941U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((aIndex + 23639U)) & S_BLOCK1], 10U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 22002U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((aIndex + 21873U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 60U) ^ RotL64(aPrevious, 29U)) + (RotL64(aCarry, 41U) ^ RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterC = ((aWandererB + RotL64(aIngress, 5U)) + 3248574644570178787U) + aNonceWordL;
            aOrbiterI = (aWandererC + RotL64(aScatter, 41U)) + 4506961512959200024U;
            aOrbiterH = ((aWandererD + RotL64(aCross, 3U)) + RotL64(aCarry, 51U)) + 8423739774540738590U;
            aOrbiterB = (((aWandererF + RotL64(aPrevious, 19U)) + RotL64(aCarry, 47U)) + 6593975869641735337U) + aOrbiterAssignSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = ((aWandererG + RotL64(aIngress, 23U)) + RotL64(aCarry, 41U)) + 16441716090557369103U;
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 48U)) + 7936601450453207914U;
            aOrbiterD = (aWandererK + RotL64(aScatter, 21U)) + 13333752583560167065U;
            aOrbiterG = (aWandererH + RotL64(aCross, 37U)) + 8013703284795432973U;
            aOrbiterF = (((aWandererE + RotL64(aPrevious, 11U)) + 2349852779887439236U) + aOrbiterAssignSaltA[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordC;
            aOrbiterJ = (aWandererI + RotL64(aIngress, 46U)) + 5318539364763284138U;
            aOrbiterK = ((aWandererA + RotL64(aCross, 39U)) + 11450957608502944376U) + aNonceWordO;
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 9058992558327552687U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 632095686920230926U;
            aOrbiterH = RotL64((aOrbiterH * 12460364388358520799U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 14734218428913777098U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 16344357661370784442U;
            aOrbiterE = RotL64((aOrbiterE * 15049472842002138369U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 2981145363531184308U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 14176472085175714494U) ^ aOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2584623327412130939U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 11198457590069700889U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 952584436750426828U;
            aOrbiterJ = RotL64((aOrbiterJ * 1165713888651280355U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 4311591763498985972U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 16194341833989936369U) ^ aNonceWordM;
            aOrbiterB = RotL64((aOrbiterB * 9997934560195932575U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 7560794022401107431U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 10683789740265711603U) ^ aNonceWordF;
            aOrbiterF = RotL64((aOrbiterF * 15637823045351977883U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 11614366395125937178U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 10750771385100564416U;
            aOrbiterC = RotL64((aOrbiterC * 4987921274272444283U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 2934697034132204529U) + aOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 4646873794658020363U) ^ aNonceWordG;
            aOrbiterI = RotL64((aOrbiterI * 10555456865641580175U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 7913681837683568905U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 17603563535330106340U;
            aOrbiterD = RotL64((aOrbiterD * 17882943067522319671U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 15375641415139193079U) + aOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 17059712718085411887U;
            aOrbiterA = RotL64((aOrbiterA * 13722089235751208215U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 14022558453716067200U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 3248574644570178787U;
            aOrbiterK = RotL64((aOrbiterK * 15249135451439374621U), 41U);
            //
            aIngress = RotL64(aOrbiterC, 43U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 41U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 54U));
            aIngress = aIngress + (RotL64(aOrbiterB, 37U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + RotL64(aOrbiterD, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aCross, 23U) + RotL64(aOrbiterE, 10U)) + aOrbiterG) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterA, 13U)) + aOrbiterD) + aWandererUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 27U) + aOrbiterA) + RotL64(aOrbiterI, 37U)) + aNonceWordA);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 5U) + aOrbiterB) + RotL64(aOrbiterF, 27U));
            aWandererG = aWandererG + ((RotL64(aCross, 20U) + aOrbiterH) + RotL64(aOrbiterD, 41U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterF, 35U)) + aOrbiterG);
            aWandererD = aWandererD + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterI, 23U)) + aOrbiterC) + aNonceWordE);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 37U) + RotL64(aOrbiterB, 3U)) + aOrbiterG) + aWandererUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 42U) + RotL64(aOrbiterK, 54U)) + aOrbiterF) + RotL64(aCarry, 53U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterJ, 43U)) + aOrbiterG) + aNonceWordH);
            aWandererK = aWandererK + ((RotL64(aScatter, 57U) + aOrbiterE) + RotL64(aOrbiterH, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 4U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 53U));
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererA, 37U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererC, 23U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 29858U)) & S_BLOCK1], 53U) ^ RotL64(pSnow[((aIndex + 31439U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 30678U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 29136U)) & S_BLOCK1], 5U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 31679U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 28093U)) & S_BLOCK1], 20U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aPrevious, 38U)) + (RotL64(aIngress, 11U) + RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterA = (aWandererA + RotL64(aCross, 47U)) + 15549114274303128055U;
            aOrbiterB = ((aWandererB + RotL64(aIngress, 22U)) + 16466750056388063241U) + aNonceWordC;
            aOrbiterK = (((aWandererH + RotL64(aPrevious, 27U)) + RotL64(aCarry, 13U)) + 12209449840836787142U) + aNonceWordE;
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 41U)) + 14551496099734294336U) + aOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = (aWandererD + RotL64(aCross, 19U)) + 6266576428679808622U;
            aOrbiterD = (aWandererK + RotL64(aScatter, 37U)) + 16892841575635668152U;
            aOrbiterE = (aWandererG + RotL64(aPrevious, 5U)) + 7375966221423362125U;
            aOrbiterC = ((((aWandererI + RotL64(aIngress, 11U)) + RotL64(aCarry, 3U)) + 11926105302821753530U) + aOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordB;
            aOrbiterI = (aWandererE + RotL64(aScatter, 43U)) + 16219253791550461124U;
            aOrbiterF = (((aWandererJ + RotL64(aCross, 35U)) + RotL64(aCarry, 27U)) + 7299056065319248160U) + aNonceWordL;
            aOrbiterG = (aWandererC + RotL64(aPrevious, 14U)) + 15234001484933728439U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 6615802589932632120U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 5481176858895819247U;
            aOrbiterK = RotL64((aOrbiterK * 3604590158551984877U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 17220507586542139380U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 14137921473739415340U;
            aOrbiterD = RotL64((aOrbiterD * 10634645686035907603U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 16981960446540932787U) + aNonceWordN;
            aOrbiterC = (((aOrbiterC ^ aOrbiterE) ^ 10897565927079518588U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterC = RotL64((aOrbiterC * 418843936329303571U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 2746889569299593263U) + aOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 4894117146736361379U;
            aOrbiterF = RotL64((aOrbiterF * 2656750612042673191U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 18294823016957137777U) + aNonceWordM;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 86828501068883383U;
            aOrbiterJ = RotL64((aOrbiterJ * 11432686669235402365U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 6322053762209547826U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 6754524552483363820U;
            aOrbiterG = RotL64((aOrbiterG * 1746163087826694641U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 7306452650619361017U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 12717201204443785828U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6121251603905574991U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 10422327053543898585U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 14786413282036348183U;
            aOrbiterI = RotL64((aOrbiterI * 8713024293107068275U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 4599182534559908397U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 5080179685914177581U;
            aOrbiterE = RotL64((aOrbiterE * 14984675846207762951U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 6527649204956325409U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 8327234966110052920U;
            aOrbiterH = RotL64((aOrbiterH * 9343969092668123661U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 7845497893651522069U) + aOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 15549114274303128055U) ^ aNonceWordH;
            aOrbiterA = RotL64((aOrbiterA * 15263427406359082909U), 53U);
            //
            aIngress = RotL64(aOrbiterG, 11U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 51U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 19U));
            aIngress = aIngress + (RotL64(aOrbiterD, 41U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterA, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aCross, 53U) + RotL64(aOrbiterI, 39U)) + aOrbiterK);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterH, 3U)) + aOrbiterK);
            aWandererK = aWandererK + ((RotL64(aScatter, 5U) + RotL64(aOrbiterD, 56U)) + aOrbiterF);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterI, 5U)) + aOrbiterE);
            aWandererD = aWandererD + ((RotL64(aCross, 10U) + aOrbiterG) + RotL64(aOrbiterF, 47U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 41U) + aOrbiterJ) + RotL64(aOrbiterA, 53U));
            aWandererH = aWandererH + ((((RotL64(aIngress, 47U) + aOrbiterD) + RotL64(aOrbiterB, 21U)) + RotL64(aCarry, 23U)) + aNonceWordK);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 43U) + aOrbiterJ) + RotL64(aOrbiterC, 43U)) + aNonceWordJ);
            aWandererA = aWandererA + (((RotL64(aCross, 37U) + RotL64(aOrbiterB, 11U)) + aOrbiterA) + aWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 57U) + aOrbiterD) + RotL64(aOrbiterG, 14U));
            aWandererI = aWandererI + ((((RotL64(aPrevious, 26U) + RotL64(aOrbiterI, 41U)) + aOrbiterC) + RotL64(aCarry, 5U)) + aWandererUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 41U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 51U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 30U));
            aCarry = aCarry + (RotL64(aWandererK, 21U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererI, 43U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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

void TwistExpander_Rugby_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x9E3A29FA830805BDULL + 0xF5308AF3F997AD4CULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xB6CA7805ECA24829ULL + 0xF34DC01DE51F6B6BULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xC027F8249E045B61ULL + 0xA980323C93969A65ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xB3011340570E6CA9ULL + 0xFF700CD546067DC9ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xDFA7F46F0F13AA31ULL + 0x9637A10AB7F36568ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xA857666BEBB96759ULL + 0x96BB42991C21810FULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x8BABABE0D4B9B37DULL + 0xBED993D5C4B15B55ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xB3C58B0B99B01D59ULL + 0xB416AB17EB044DC6ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x90D225459F965AB3ULL + 0x895FE2D246CADC2DULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xAF26B102F1C4E52DULL + 0xE2240EE1784C531AULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xF12DB3139724BD8DULL + 0xE663AD095B2F1719ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xAAE3D164844C784DULL + 0xEE34D481678D2E35ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xD86F220542644815ULL + 0xC1CD43AF541DB928ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xF3EB0CF723181C43ULL + 0xB67ED614C1632795ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xCAA1635C7CB5A859ULL + 0xE1D35C2A84EAD416ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xC13A044E9C8C1013ULL + 0x9D1B471AF72D9006ULL);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 689U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 7181U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 7798U)) & S_BLOCK1], 27U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 4460U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 29U) ^ RotL64(aIngress, 10U)) ^ (RotL64(aPrevious, 53U) + RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 43U)) + 2783898056762489197U) + aOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = (aWandererH + RotL64(aCross, 18U)) + 7177192902873343053U;
            aOrbiterH = (((aWandererD + RotL64(aIngress, 57U)) + RotL64(aCarry, 53U)) + 12254703232691980774U) + aNonceWordJ;
            aOrbiterE = (aWandererI + RotL64(aPrevious, 23U)) + 15446547245691219559U;
            aOrbiterK = ((aWandererF + RotL64(aCross, 35U)) + RotL64(aCarry, 35U)) + 888475203006174856U;
            aOrbiterA = (((aWandererK + RotL64(aPrevious, 13U)) + RotL64(aCarry, 27U)) + 3649183529366307877U) + aOrbiterAssignSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = (aWandererB + RotL64(aIngress, 27U)) + 4642631047518805167U;
            aOrbiterC = ((aWandererE + RotL64(aScatter, 50U)) + 6108329730724782250U) + aNonceWordC;
            aOrbiterG = (aWandererG + RotL64(aPrevious, 5U)) + 8334054653023816636U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 5891895375031474350U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 3176720746238477862U) ^ aOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1869961473768307911U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 6111038696865301675U) + aOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 11914998302228682704U;
            aOrbiterF = RotL64((aOrbiterF * 11738924766359642853U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 17005063057791320948U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 18333780598768130670U;
            aOrbiterE = RotL64((aOrbiterE * 5416759844884107303U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 2056115016443263153U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 10245512728872962677U;
            aOrbiterK = RotL64((aOrbiterK * 707106795383284903U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 4810366069422162351U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 3051442983125942469U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13558537578054436423U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 9285068547223654308U) + aNonceWordF;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 13067251130180968842U;
            aOrbiterB = RotL64((aOrbiterB * 7000687697769766605U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 3203670242792002165U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 1770881716916463461U;
            aOrbiterJ = RotL64((aOrbiterJ * 13870229847371882171U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 16286823712870537410U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 13067191141829694202U;
            aOrbiterA = RotL64((aOrbiterA * 15629974528467350445U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 3414576315085336932U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterK) ^ 8979691827341555245U) ^ aOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterG = RotL64((aOrbiterG * 15971594804040295757U), 39U);
            //
            aIngress = RotL64(aOrbiterF, 43U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterA, 20U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterH, 29U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterG, 39U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterB, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aCross, 19U) + aOrbiterE) + RotL64(aOrbiterF, 40U)) + aNonceWordG);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterG, 19U)) + aOrbiterK);
            aWandererC = aWandererC + (((RotL64(aPrevious, 58U) + aOrbiterC) + RotL64(aOrbiterK, 23U)) + RotL64(aCarry, 39U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 47U) + aOrbiterJ) + RotL64(aOrbiterF, 5U)) + aNonceWordK);
            aWandererG = aWandererG + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterB, 14U)) + aOrbiterF);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterJ, 47U)) + aOrbiterC);
            aWandererE = aWandererE + ((((RotL64(aCross, 37U) + aOrbiterG) + RotL64(aOrbiterH, 51U)) + RotL64(aCarry, 47U)) + aNonceWordD);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 27U) + aOrbiterE) + RotL64(aOrbiterB, 29U)) + aWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 54U) + RotL64(aOrbiterA, 35U)) + aOrbiterC) + aWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 51U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 11U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererD, 21U);
            aCarry = aCarry + RotL64(aIngress, 54U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 8409U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneB[((aIndex + 15138U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 11383U)) & S_BLOCK1], 54U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 13837U)) & S_BLOCK1], 24U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 9188U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 58U) ^ RotL64(aCarry, 37U)) + (RotL64(aCross, 23U) + RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 27U)) + 6381335981879993247U) + aNonceWordO;
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 42U)) + 15595429101600023172U) + aOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = ((aWandererH + RotL64(aIngress, 13U)) + RotL64(aCarry, 27U)) + 5449234297249826461U;
            aOrbiterG = ((aWandererK + RotL64(aCross, 47U)) + 11213734849329731168U) + aNonceWordP;
            aOrbiterE = ((aWandererB + RotL64(aScatter, 37U)) + RotL64(aCarry, 3U)) + 16438473952464514248U;
            aOrbiterF = (((aWandererF + RotL64(aCross, 51U)) + RotL64(aCarry, 35U)) + 7357872882115186976U) + aNonceWordL;
            aOrbiterI = (aWandererI + RotL64(aPrevious, 60U)) + 394402075160738643U;
            aOrbiterB = (aWandererD + RotL64(aIngress, 21U)) + 11112941985410283532U;
            aOrbiterH = (((aWandererA + RotL64(aPrevious, 5U)) + 14955125011182736212U) + aOrbiterAssignSaltC[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordE;
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 14770727009821304070U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 11286366598129204910U;
            aOrbiterK = RotL64((aOrbiterK * 15884310771003021989U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 7358400908565425780U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 15635109923749114761U;
            aOrbiterA = RotL64((aOrbiterA * 12415152149408700329U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 13826842523738623579U) + aNonceWordJ;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 1072811298828325231U;
            aOrbiterI = RotL64((aOrbiterI * 9662800288646215083U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 4017334196009350776U) + aOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 8812213572751410831U;
            aOrbiterE = RotL64((aOrbiterE * 12744171921566782795U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 6723457786170634403U) + aOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 9785583533999417673U;
            aOrbiterF = RotL64((aOrbiterF * 7776915427605471097U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 10265132640322153964U) + aOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 8435670887514808087U;
            aOrbiterB = RotL64((aOrbiterB * 2706263045620662131U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 4303823386961718326U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 4214384238167491037U;
            aOrbiterG = RotL64((aOrbiterG * 8490707334221154005U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 8740835037840799136U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 5988815405391206280U;
            aOrbiterH = RotL64((aOrbiterH * 17838555472135715929U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 15539461383052981747U) + aNonceWordC;
            aOrbiterD = (((aOrbiterD ^ aOrbiterE) ^ 3743772525784217714U) ^ aOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterD = RotL64((aOrbiterD * 6352086797545969187U), 57U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterD, 27U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 23U));
            aIngress = aIngress + (RotL64(aOrbiterA, 35U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterB, 18U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterE, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aIngress, 30U) + aOrbiterE) + RotL64(aOrbiterD, 21U)) + aNonceWordF);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterA, 35U)) + aOrbiterF) + RotL64(aCarry, 35U)) + aNonceWordD);
            aWandererF = aWandererF ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterB, 58U)) + aOrbiterH);
            aWandererB = aWandererB + (((RotL64(aScatter, 53U) + aOrbiterK) + RotL64(aOrbiterB, 43U)) + RotL64(aCarry, 13U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterA, 11U)) + aOrbiterK);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 11U) + RotL64(aOrbiterB, 47U)) + aOrbiterD);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterA, 53U)) + aOrbiterD) + aNonceWordI);
            aWandererK = aWandererK + ((((RotL64(aCross, 34U) + RotL64(aOrbiterG, 5U)) + aOrbiterE) + aNonceWordG) + aWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 39U) + RotL64(aOrbiterF, 30U)) + aOrbiterI) + aWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 37U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 50U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererI, 21U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 17716U)) & S_BLOCK1], 54U) ^ RotL64(aFireLaneD[((aIndex + 21155U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 20030U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 24454U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 21877U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 22746U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 10U) + RotL64(aCross, 27U)) ^ (RotL64(aCarry, 39U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterK = (((aWandererE + RotL64(aIngress, 56U)) + RotL64(aCarry, 11U)) + 966899917801652720U) + aOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = (aWandererI + RotL64(aScatter, 35U)) + 10996327672320748649U;
            aOrbiterE = (((aWandererK + RotL64(aPrevious, 5U)) + RotL64(aCarry, 57U)) + 4188171566846621107U) + aNonceWordE;
            aOrbiterC = (((aWandererA + RotL64(aCross, 23U)) + 5886209243097387959U) + aOrbiterAssignSaltE[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordA;
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 48U)) + RotL64(aCarry, 41U)) + 14940428957136728111U;
            aOrbiterH = (aWandererC + RotL64(aPrevious, 11U)) + 179187285531914832U;
            aOrbiterF = ((aWandererB + RotL64(aIngress, 43U)) + 6685351948936817752U) + aNonceWordN;
            aOrbiterA = (aWandererJ + RotL64(aCross, 19U)) + 1894506461704029700U;
            aOrbiterI = ((aWandererF + RotL64(aIngress, 27U)) + 4182760368636977082U) + aNonceWordO;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 12523318028514940790U) + aNonceWordC;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 5059306166973366892U;
            aOrbiterE = RotL64((aOrbiterE * 2857409765717296483U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 5890872367917643851U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 17747338389865221534U;
            aOrbiterK = RotL64((aOrbiterK * 5306740664798049267U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 13906227834259884100U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 7152105382899756368U;
            aOrbiterD = RotL64((aOrbiterD * 6772157117358310485U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 17868101884759619240U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 11758843266314148347U;
            aOrbiterF = RotL64((aOrbiterF * 5919135169337501485U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 13950566197090324859U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 17278105609930477854U;
            aOrbiterA = RotL64((aOrbiterA * 11431842718945107359U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 9556785965646738355U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 841298436857932987U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15077843186688841797U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 1951515285492133830U) + aNonceWordI;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 15775839819330588437U;
            aOrbiterH = RotL64((aOrbiterH * 7902654031401620995U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 5585458468816495436U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 17258586689032223623U) ^ aOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1652050227399194271U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 5254132659445988836U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 15440741734777060925U;
            aOrbiterJ = RotL64((aOrbiterJ * 17445581079035134067U), 51U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterA, 60U);
            aIngress = aIngress + (RotL64(aOrbiterI, 43U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + (RotL64(aOrbiterE, 53U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterJ, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 60U) + aOrbiterH) + RotL64(aOrbiterD, 39U));
            aWandererI = aWandererI + ((RotL64(aCross, 37U) + aOrbiterI) + RotL64(aOrbiterH, 57U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 23U) + aOrbiterF) + RotL64(aOrbiterI, 35U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 13U) + aOrbiterA) + RotL64(aOrbiterJ, 43U)) + RotL64(aCarry, 43U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 28U) + RotL64(aOrbiterC, 48U)) + aOrbiterE) + aWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aCross, 41U) + aOrbiterI) + RotL64(aOrbiterA, 23U)) + RotL64(aCarry, 3U)) + aNonceWordK);
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 51U) + aOrbiterJ) + RotL64(aOrbiterK, 27U)) + aNonceWordD) + aWandererUpdateSaltF[((aIndex + 20U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 5U) + aOrbiterD) + RotL64(aOrbiterC, 53U)) + aNonceWordJ);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 47U) + aOrbiterC) + RotL64(aOrbiterF, 10U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 28U) ^ aWandererE);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + RotL64(aWandererJ, 53U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 31149U)) & S_BLOCK1], 27U) ^ RotL64(aFireLaneC[((aIndex + 27738U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 25825U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31016U)) & S_BLOCK1], 35U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 25756U)) & S_BLOCK1], 24U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 25903U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCarry, 20U)) + (RotL64(aCross, 3U) ^ RotL64(aPrevious, 51U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterB = (aWandererJ + RotL64(aPrevious, 35U)) + 12311607308490066301U;
            aOrbiterK = ((aWandererA + RotL64(aCross, 57U)) + RotL64(aCarry, 23U)) + 13100864684740679846U;
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 10U)) + RotL64(aCarry, 13U)) + 13697304189274329704U;
            aOrbiterE = (((aWandererB + RotL64(aScatter, 39U)) + RotL64(aCarry, 53U)) + 9047976902871216732U) + aOrbiterAssignSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterI = (aWandererK + RotL64(aIngress, 53U)) + 2147897579538537888U;
            aOrbiterC = ((aWandererH + RotL64(aCross, 3U)) + 2072444829390996142U) + aOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = ((aWandererC + RotL64(aScatter, 14U)) + 2129307836981020908U) + aNonceWordE;
            aOrbiterG = (aWandererG + RotL64(aPrevious, 43U)) + 10663145333751112064U;
            aOrbiterH = ((aWandererI + RotL64(aCross, 27U)) + 15019844390503785459U) + aNonceWordB;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 5460865577557928142U) + aNonceWordK;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 15806522559993224197U;
            aOrbiterJ = RotL64((aOrbiterJ * 8722932687972240099U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 6361113778657833389U) + aNonceWordN;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 8306013884615042570U) ^ aNonceWordA;
            aOrbiterI = RotL64((aOrbiterI * 8234258702656728667U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 4038420580499706912U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 11908091484457158973U;
            aOrbiterK = RotL64((aOrbiterK * 3964111175645156719U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 11133912466611921250U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 2469227904206936928U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2704438771198001599U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 13234017916788297295U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 9061117693840451988U;
            aOrbiterB = RotL64((aOrbiterB * 3637440416741459419U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 12013423690843812324U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 14371779015144617412U;
            aOrbiterH = RotL64((aOrbiterH * 3359568073302062667U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 10044883414565441442U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 14334898081890462218U;
            aOrbiterE = RotL64((aOrbiterE * 4878939077928220019U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 13788962593988366125U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 8377887372059713516U;
            aOrbiterA = RotL64((aOrbiterA * 1925913354197206851U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 4584439257847749371U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 13335592911357756498U;
            aOrbiterG = RotL64((aOrbiterG * 6515028218115896375U), 39U);
            //
            aIngress = RotL64(aOrbiterI, 57U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterE, 50U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterG, 41U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 27U));
            aIngress = aIngress + RotL64(aOrbiterJ, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aScatter, 57U) + aOrbiterJ) + RotL64(aOrbiterH, 47U)) + aWandererUpdateSaltD[((aIndex + 6U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 19U) + RotL64(aOrbiterI, 51U)) + aOrbiterJ) + RotL64(aCarry, 19U)) + aNonceWordL);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 3U) + aOrbiterK) + RotL64(aOrbiterC, 3U)) + aNonceWordM);
            aWandererI = aWandererI + ((RotL64(aPrevious, 28U) + aOrbiterJ) + RotL64(aOrbiterA, 19U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterI, 42U)) + aOrbiterG);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 39U) + RotL64(aOrbiterG, 29U)) + aOrbiterE) + RotL64(aCarry, 5U)) + aNonceWordD);
            aWandererH = aWandererH ^ ((RotL64(aCross, 47U) + aOrbiterG) + RotL64(aOrbiterC, 35U));
            aWandererA = aWandererA + ((RotL64(aScatter, 34U) + aOrbiterK) + RotL64(aOrbiterB, 23U));
            aWandererB = aWandererB ^ ((((RotL64(aCross, 11U) + RotL64(aOrbiterI, 58U)) + aOrbiterK) + aNonceWordH) + aWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererA);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 24U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 41U));
            aCarry = aCarry + RotL64(aWandererB, 21U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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

void TwistExpander_Rugby_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterE = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0;
    std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x9E0DA1B8E4F04573ULL + 0xA749A39B8C656B0AULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xAD397DE6B962DCDDULL + 0xEBA231E5BCF0D301ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xFDCC29A332D19839ULL + 0xF84897BB957E9090ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xF2E9B6BD91A569D9ULL + 0xFB69F5CE28226961ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xFB7BE38EB0E85471ULL + 0xB92C9F3868685FA0ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xC580BA997C960473ULL + 0xB3D3362D8BDFA951ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xEB6DA32495EFC971ULL + 0xA1957A3E0DF52E96ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x9F19F74442F2707FULL + 0xF9416BC0353CC33DULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xAF081874A39A3619ULL + 0xBC9E9108E6858A91ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xA642B87817208CDBULL + 0xF56E24AFCCDB2879ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x93AD0E01C3DB2301ULL + 0x8E99DC411C1BC679ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xDF9DA750583241B3ULL + 0xAC6E4DEA393C881EULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xBECAB02834DE421DULL + 0x9717D5A8B2AE2336ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xADA0683B606800D3ULL + 0xF4862C4109E406BBULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xAFA8B4FF99BD18E1ULL + 0xAFF0DAD49C8D6BD9ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xFD260D3BCC5488B7ULL + 0xFAC22E711F7E3F1FULL);
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
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneC, aOperationLaneC, aOperationLaneD, aWorkLaneA, aFireLaneA, aWorkLaneB, aFireLaneD, aWorkLaneC, aFireLaneB
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // kdf_a_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aFireLaneC
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aFireLaneC forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 419U)) & S_BLOCK1], 6U) ^ RotL64(aOperationLaneB[((aIndex + 2652U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 4260U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 5059U)) & S_BLOCK1], 44U) ^ RotL64(aOperationLaneD[((aIndex + 5342U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCross, 36U)) + (RotL64(aCarry, 51U) ^ RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterA = (((aWandererH + RotL64(aScatter, 19U)) + RotL64(aCarry, 3U)) + 15316464782468770057U) + aNonceWordA;
            aOrbiterI = (((aWandererG + RotL64(aPrevious, 37U)) + 6642872057476351588U) + aOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1]) + aNonceWordG;
            aOrbiterF = ((aWandererB + RotL64(aIngress, 57U)) + 660732654689529192U) + aNonceWordL;
            aOrbiterG = (((aWandererE + RotL64(aCross, 46U)) + RotL64(aCarry, 39U)) + 7235418086884000655U) + aOrbiterAssignSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterJ = (((aWandererJ + RotL64(aIngress, 3U)) + RotL64(aCarry, 19U)) + 14784518476694580493U) + aNonceWordH;
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 12222433977933449375U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterA) ^ 8573001207708329927U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterF = RotL64((aOrbiterF * 17771120145431297541U), 37U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 16035256260815013172U) + aNonceWordF;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 15767726974121910203U) ^ aNonceWordE;
            aOrbiterJ = RotL64((aOrbiterJ * 719060452537759331U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 17712217935322939971U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 13488963456923357159U) ^ aOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16785285630840310405U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 10222949131965611079U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 1495561412321657209U;
            aOrbiterA = RotL64((aOrbiterA * 9706305581868526265U), 3U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterA) + 16156530750584361434U) + aOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 7773792489045606309U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10730624207715601393U), 51U);
            //
            aIngress = RotL64(aOrbiterI, 26U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterA, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((((RotL64(aPrevious, 11U) + aOrbiterJ) + RotL64(aOrbiterF, 21U)) + RotL64(aCarry, 23U)) + aNonceWordN) + aWandererUpdateSaltC[((aIndex + 12U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((((RotL64(aIngress, 53U) + aOrbiterG) + RotL64(aOrbiterI, 37U)) + aNonceWordD) + aWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 43U) + RotL64(aOrbiterI, 12U)) + aOrbiterJ) + aNonceWordI);
            aWandererG = aWandererG ^ ((RotL64(aCross, 34U) + aOrbiterA) + RotL64(aOrbiterF, 47U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 21U) + RotL64(aOrbiterG, 57U)) + aOrbiterF) + RotL64(aCarry, 39U)) + aNonceWordC);
            //
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererG, 60U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_c loop 2
        // ingress from: aWorkLaneA, aOperationLaneC, aFireLaneA
        // ingress directions: aWorkLaneA forward forced, aOperationLaneC forward forced, aFireLaneA forward/backward random
        // cross from: aOperationLaneA, aOperationLaneD, aOperationLaneB
        // cross directions: aOperationLaneA backward forced, aOperationLaneD backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 11658U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneC[((aIndex + 16171U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 12167U)) & S_BLOCK1], 56U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 13185U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 8282U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 12912U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aIngress, 39U)) + (RotL64(aCross, 23U) + RotL64(aPrevious, 54U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterI = ((aWandererB + RotL64(aCross, 4U)) + 9023059520606551446U) + aOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 57U)) + 662441755115638133U) + aNonceWordM;
            aOrbiterB = (((aWandererI + RotL64(aIngress, 23U)) + RotL64(aCarry, 3U)) + 16957253361196144712U) + aNonceWordJ;
            aOrbiterC = (((aWandererF + RotL64(aScatter, 13U)) + RotL64(aCarry, 19U)) + 7840955025765308605U) + aNonceWordN;
            aOrbiterA = ((((aWandererA + RotL64(aPrevious, 41U)) + RotL64(aCarry, 35U)) + 346855809270395799U) + aOrbiterAssignSaltB[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordP;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 16099139781586668343U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 3706457327118322098U) ^ aOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7810030620470889591U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 12166825885547622870U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 7792658665720344200U) ^ aNonceWordC;
            aOrbiterI = RotL64((aOrbiterI * 16305542632794270697U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 7128477606152986326U) + aNonceWordB;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 11116533962780290084U;
            aOrbiterA = RotL64((aOrbiterA * 11993485572912492297U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 10443889548568288532U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterA) ^ 4402387036946561017U) ^ aOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterC = RotL64((aOrbiterC * 9032964741841833277U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 13002706161178447654U) + aNonceWordA;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 13929727277530310708U) ^ aOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7005639090871200285U), 13U);
            //
            aIngress = RotL64(aOrbiterB, 57U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterC, 29U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterA, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 48U) + RotL64(aOrbiterJ, 43U)) + aOrbiterI);
            aWandererI = aWandererI + (((RotL64(aIngress, 23U) + RotL64(aOrbiterC, 60U)) + aOrbiterB) + RotL64(aCarry, 47U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 35U) + aOrbiterC) + RotL64(aOrbiterA, 35U)) + aNonceWordI);
            aWandererJ = aWandererJ + (((((RotL64(aPrevious, 57U) + RotL64(aOrbiterI, 23U)) + aOrbiterA) + RotL64(aCarry, 29U)) + aNonceWordG) + aWandererUpdateSaltE[((aIndex + 10U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((((RotL64(aScatter, 5U) + RotL64(aOrbiterJ, 11U)) + aOrbiterC) + aNonceWordK) + aWandererUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + RotL64(aWandererJ, 19U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_c loop 3
        // ingress from: aWorkLaneB, aOperationLaneD, aFireLaneD
        // ingress directions: aWorkLaneB forward forced, aOperationLaneD forward forced, aFireLaneD forward/backward random
        // cross from: aWorkLaneA, aOperationLaneB, aOperationLaneC
        // cross directions: aWorkLaneA backward forced, aOperationLaneB backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 18972U)) & S_BLOCK1], 24U) ^ RotL64(aOperationLaneD[((aIndex + 22530U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 23824U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21853U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 18244U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aOperationLaneC[((aIndex + 23619U)) & S_BLOCK1], 28U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 11U) ^ RotL64(aIngress, 56U)) ^ (RotL64(aPrevious, 23U) + RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterK = ((aWandererH + RotL64(aScatter, 36U)) + 380024772508948442U) + aNonceWordJ;
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 23U)) + 7649029098162567210U) + aNonceWordG;
            aOrbiterA = (((aWandererK + RotL64(aCross, 47U)) + RotL64(aCarry, 19U)) + 5329304598870421851U) + aOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = ((((aWandererA + RotL64(aIngress, 57U)) + RotL64(aCarry, 51U)) + 12306118665045151326U) + aOrbiterAssignSaltE[((aIndex + 28U)) & S_SALT1]) + aNonceWordP;
            aOrbiterE = (((aWandererJ + RotL64(aPrevious, 3U)) + RotL64(aCarry, 3U)) + 960751560457324256U) + aNonceWordL;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 3244070254386191876U) + aNonceWordC;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 15733408571609521746U) ^ aNonceWordN;
            aOrbiterA = RotL64((aOrbiterA * 11280008313548121407U), 5U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterB) + 17623448932647018544U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordO;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 8787759896149035829U;
            aOrbiterE = RotL64((aOrbiterE * 7092515868845497573U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 14741681792348288162U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 8801731213568307302U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12127126999570616489U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 9872248187499779222U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 15407371518644528235U) ^ aOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1245102406469471673U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 4242060317152943062U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 9942784962409917541U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 888649755587764533U), 47U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterF, 57U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 5U));
            aIngress = aIngress + RotL64(aOrbiterB, 22U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aScatter, 60U) + RotL64(aOrbiterB, 21U)) + aOrbiterE) + RotL64(aCarry, 39U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 51U) + aOrbiterE) + RotL64(aOrbiterK, 11U));
            aWandererJ = aWandererJ + ((((RotL64(aCross, 35U) + aOrbiterF) + RotL64(aOrbiterA, 37U)) + RotL64(aCarry, 27U)) + aWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterA, 51U)) + aOrbiterB) + aNonceWordI);
            aWandererF = aWandererF + ((((RotL64(aCross, 13U) + RotL64(aOrbiterA, 60U)) + aOrbiterE) + aNonceWordF) + aWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 27U));
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererA, 3U);
            aCarry = aCarry + RotL64(aIngress, 36U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 32207U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((aIndex + 28582U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 25837U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31449U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 31103U)) & S_BLOCK1], 47U));
            aCross ^= (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 26882U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneA[((aIndex + 29044U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCross, 21U) + RotL64(aIngress, 35U)) ^ (RotL64(aCarry, 6U) + RotL64(aPrevious, 47U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterF = ((aWandererG + RotL64(aIngress, 47U)) + RotL64(aCarry, 5U)) + 14214886793361825363U;
            aOrbiterA = (((aWandererC + RotL64(aCross, 37U)) + 17267959031078766320U) + aOrbiterAssignSaltA[((aIndex + 18U)) & S_SALT1]) + aNonceWordC;
            aOrbiterB = (((aWandererD + RotL64(aPrevious, 57U)) + RotL64(aCarry, 21U)) + 16436067429484887644U) + aNonceWordH;
            aOrbiterC = (((aWandererH + RotL64(aScatter, 14U)) + RotL64(aCarry, 47U)) + 9885951769332633820U) + aNonceWordM;
            aOrbiterG = (((aWandererK + RotL64(aPrevious, 23U)) + 12971711341813893304U) + aOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1]) + aNonceWordJ;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 199970353398450154U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 1237341696444162094U) ^ aNonceWordF;
            aOrbiterB = RotL64((aOrbiterB * 2850125642665515751U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 7991128854417613360U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterC) ^ 14809029847149045833U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterA = RotL64((aOrbiterA * 5940857360838299105U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 2559509556915775947U) + aOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 14336829730147834160U;
            aOrbiterG = RotL64((aOrbiterG * 15103242520064900873U), 5U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterC) + 8853631886733610440U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordK;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 13346159398673246914U;
            aOrbiterF = RotL64((aOrbiterF * 13660497151446983393U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 12121095718571872976U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 16239781125815589804U;
            aOrbiterC = RotL64((aOrbiterC * 5157009090454962231U), 13U);
            //
            aIngress = RotL64(aOrbiterG, 47U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 24U));
            aIngress = aIngress + RotL64(aOrbiterB, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aIngress, 58U) + aOrbiterB) + RotL64(aOrbiterA, 37U)) + aNonceWordI);
            aWandererD = aWandererD + (((((RotL64(aPrevious, 5U) + aOrbiterA) + RotL64(aOrbiterF, 5U)) + RotL64(aCarry, 23U)) + aNonceWordN) + aWandererUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aCross, 13U) + aOrbiterG) + RotL64(aOrbiterA, 47U)) + aWandererUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 39U) + aOrbiterF) + RotL64(aOrbiterC, 56U)) + RotL64(aCarry, 57U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterC, 29U)) + aOrbiterG) + aNonceWordP);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 37U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 18U));
            aCarry = aCarry + RotL64(aWandererC, 5U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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

void TwistExpander_Rugby_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xADE8833493CC055DULL + 0x8C5D6D8CED82972CULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xC76A5A700C33F8E9ULL + 0xE1BE60D0369A0860ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xB1155F4A052BFC21ULL + 0xD8087C67572608A2ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xAB83B4BCC2B1FC1DULL + 0x8814796D49B001C7ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xC0155A7B0D75B079ULL + 0x81BDAE37B7AAE3BEULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xD98F3A99A4B9C739ULL + 0xD011EAA183950245ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xFC9F0FFFB87E7961ULL + 0xCA8D5CFCE4BED135ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xFA9FB47FE58E79E1ULL + 0xE4D412E25075A94CULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xD74BE1A9A4C48573ULL + 0xBC7569A7E12695C1ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xE8DD6F91020DA0B7ULL + 0xA71570F9947692ECULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xE8CEBEA94E30CBBFULL + 0xC79838798AC842D9ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xA3C5428F9213835FULL + 0xC3FBFB36CD2A6063ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xAC135160A6B54099ULL + 0x8E8AED84DD1554D9ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xD5BD3996EA46F657ULL + 0xF05F7EFF05BF6917ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xAEF45E96CEC608B1ULL + 0xC3835312A9CEFE9AULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x873B5726B05796BBULL + 0x835F1A06A1C63DE4ULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneA, aExpandLaneC, aExpandLaneD, aFireLaneC, aWorkLaneA, aOperationLaneC, aOperationLaneA, aWorkLaneB, aOperationLaneD, aFireLaneB, aWorkLaneC, aOperationLaneB, aFireLaneD
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // kdf_a_loop_d loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneA
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aFireLaneC
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aFireLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 2617U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneB[((aIndex + 3567U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 6978U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1240U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 7114U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 309U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aIngress, 50U) ^ RotL64(aCarry, 35U)) + (RotL64(aCross, 3U) + RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterC = (((aWandererE + RotL64(aPrevious, 13U)) + 7790166497945719700U) + aOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordA;
            aOrbiterG = ((aWandererK + RotL64(aScatter, 35U)) + RotL64(aCarry, 51U)) + 7136208896846119188U;
            aOrbiterI = (aWandererH + RotL64(aCross, 58U)) + 12123156943355100886U;
            aOrbiterE = ((aWandererC + RotL64(aIngress, 27U)) + 5095546037880875199U) + aOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 3U)) + RotL64(aCarry, 23U)) + 17642705393916765992U;
            aOrbiterF = (((aWandererA + RotL64(aCross, 43U)) + RotL64(aCarry, 35U)) + 9918479837334416990U) + aNonceWordH;
            aOrbiterB = ((aWandererB + RotL64(aIngress, 21U)) + 4890009823843176466U) + aNonceWordG;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 17652590786213674124U) + aOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 870002527644696135U;
            aOrbiterI = RotL64((aOrbiterI * 915408393979165539U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 12545429703552643682U) + aOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 5310272867406182581U;
            aOrbiterJ = RotL64((aOrbiterJ * 10420003334833925011U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 3264719049050179440U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 1967241238180278937U) ^ aNonceWordJ;
            aOrbiterC = RotL64((aOrbiterC * 13004319774269457957U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 773883832927040736U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 12766817190261232485U;
            aOrbiterE = RotL64((aOrbiterE * 7448864556802318431U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 260069382395598265U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 15462103891287350123U;
            aOrbiterB = RotL64((aOrbiterB * 5029268763635635753U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 4072032867513289827U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 17153061419083897076U;
            aOrbiterF = RotL64((aOrbiterF * 11934532169271718913U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 6207264270332656966U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterB) ^ 18048064697837314947U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterG = RotL64((aOrbiterG * 13632594619404208489U), 29U);
            //
            aIngress = RotL64(aOrbiterB, 19U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterF, 37U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterJ, 51U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterG, 10U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aScatter, 60U) + RotL64(aOrbiterJ, 11U)) + aOrbiterB) + RotL64(aCarry, 11U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 23U) + aOrbiterJ) + RotL64(aOrbiterE, 41U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 35U) + RotL64(aOrbiterI, 35U)) + aOrbiterC) + RotL64(aCarry, 41U)) + aNonceWordB);
            aWandererH = aWandererH ^ (((RotL64(aCross, 11U) + aOrbiterB) + RotL64(aOrbiterI, 47U)) + aNonceWordE);
            aWandererB = aWandererB + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterF, 27U)) + aOrbiterC);
            aWandererA = aWandererA ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterC, 19U)) + aOrbiterG) + aWandererUpdateSaltF[((aIndex + 20U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 3U) + aOrbiterJ) + RotL64(aOrbiterI, 4U)) + aWandererUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererC, 46U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 53U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 2
        // ingress from: aWorkLaneA, aExpandLaneC, aOperationLaneC
        // ingress directions: aWorkLaneA forward forced, aExpandLaneC forward forced, aOperationLaneC forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD, aOperationLaneA
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward forced, aOperationLaneA backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 8480U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneC[((aIndex + 11374U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aOperationLaneC[((aIndex + 11783U)) & S_BLOCK1], 58U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 15370U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 14242U)) & S_BLOCK1], 6U));
            aCross ^= RotL64(aOperationLaneA[((aIndex + 12622U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aPrevious, 39U)) ^ (RotL64(aCarry, 10U) + RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterH = ((aWandererI + RotL64(aScatter, 35U)) + 2558105147674438050U) + aNonceWordD;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 27U)) + RotL64(aCarry, 29U)) + 15856662514774702561U;
            aOrbiterE = (aWandererB + RotL64(aIngress, 50U)) + 13346869226246584582U;
            aOrbiterA = (((aWandererH + RotL64(aCross, 43U)) + RotL64(aCarry, 5U)) + 7632111846116243973U) + aNonceWordL;
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 5U)) + 2102101361626976279U) + aOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = ((((aWandererG + RotL64(aScatter, 11U)) + RotL64(aCarry, 47U)) + 5605968705067851563U) + aOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1]) + aNonceWordN;
            aOrbiterD = (aWandererF + RotL64(aIngress, 21U)) + 6842483186584326681U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 5559797213819425064U) + aNonceWordC;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 12422313931331576759U;
            aOrbiterE = RotL64((aOrbiterE * 7399849122565913401U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 2751024420047872601U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 11031320239359798610U;
            aOrbiterF = RotL64((aOrbiterF * 8607639453141148025U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 14366375309473793217U) + aOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = (((aOrbiterI ^ aOrbiterA) ^ 11971479429768505316U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterI = RotL64((aOrbiterI * 10063001532313098203U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 3947595951884469542U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 17882767922372770896U;
            aOrbiterD = RotL64((aOrbiterD * 3361906348965810211U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 513871456983509223U) + aNonceWordE;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 5951677013597794294U;
            aOrbiterH = RotL64((aOrbiterH * 8508629569649935293U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 437626309049021931U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 466674061172005705U) ^ aNonceWordB;
            aOrbiterA = RotL64((aOrbiterA * 1310502572084891157U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 12362602809233133718U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 10525852878882195702U;
            aOrbiterK = RotL64((aOrbiterK * 17755022180514914325U), 47U);
            //
            aIngress = RotL64(aOrbiterH, 60U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 39U));
            aIngress = aIngress + (RotL64(aOrbiterE, 53U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterD, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterK, 3U)) + aOrbiterF);
            aWandererB = aWandererB + ((((RotL64(aIngress, 41U) + RotL64(aOrbiterH, 51U)) + aOrbiterE) + RotL64(aCarry, 3U)) + aWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterI, 12U)) + aOrbiterK) + aNonceWordM);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 19U) + aOrbiterD) + RotL64(aOrbiterE, 57U)) + RotL64(aCarry, 19U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 51U) + aOrbiterE) + RotL64(aOrbiterA, 37U)) + aWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 5U) + aOrbiterE) + RotL64(aOrbiterF, 19U)) + aNonceWordJ);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 58U) + aOrbiterI) + RotL64(aOrbiterE, 43U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 26U));
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererI);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 41U));
            aCarry = aCarry + RotL64(aWandererD, 51U);
            aCarry = aCarry + RotL64(aIngress, 36U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 3
        // ingress from: aWorkLaneB, aExpandLaneD, aOperationLaneD
        // ingress directions: aWorkLaneB forward forced, aExpandLaneD forward forced, aOperationLaneD forward/backward random
        // cross from: aWorkLaneA, aExpandLaneB, aFireLaneB
        // cross directions: aWorkLaneA backward forced, aExpandLaneB backward forced, aFireLaneB backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 21090U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneD[((aIndex + 17148U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aOperationLaneD[((aIndex + 18349U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18649U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 23691U)) & S_BLOCK1], 30U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 21809U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCarry, 34U)) + (RotL64(aPrevious, 47U) + RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 37U)) + RotL64(aCarry, 57U)) + 5960680319644404115U;
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 20U)) + 16050752633567034185U) + aNonceWordF;
            aOrbiterG = (aWandererD + RotL64(aScatter, 47U)) + 8447503223226854741U;
            aOrbiterH = (((aWandererI + RotL64(aCross, 27U)) + RotL64(aCarry, 11U)) + 14176813813397917591U) + aOrbiterAssignSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 53U)) + 10534915376130006644U) + aOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = (((aWandererB + RotL64(aScatter, 5U)) + RotL64(aCarry, 39U)) + 6866224454375302514U) + aNonceWordM;
            aOrbiterF = (aWandererC + RotL64(aIngress, 13U)) + 16506374165041008396U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 7167814023968794098U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 13870852197416596664U;
            aOrbiterG = RotL64((aOrbiterG * 17015971222069856463U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 18064038854848993105U) + aOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 9869630811507771691U;
            aOrbiterH = RotL64((aOrbiterH * 13723164383800461387U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 863613100452759380U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterA) ^ 16597969741225436529U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterF = RotL64((aOrbiterF * 2680793528887208903U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 6575347108051310653U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 17062262265485019063U) ^ aNonceWordK;
            aOrbiterA = RotL64((aOrbiterA * 7601045488473620019U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 7193399224636409133U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 14146747818810433849U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5273185769989530041U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 9441449106442431427U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 4303295336545399503U) ^ aNonceWordE;
            aOrbiterC = RotL64((aOrbiterC * 8829695296836242587U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 12604760768543193458U) + aNonceWordP;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 15779327512379787715U;
            aOrbiterJ = RotL64((aOrbiterJ * 14000905201441272597U), 51U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterJ, 11U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 5U));
            aIngress = aIngress + (RotL64(aOrbiterB, 53U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterC, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aScatter, 13U) + aOrbiterC) + RotL64(aOrbiterB, 11U)) + RotL64(aCarry, 3U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 53U) + aOrbiterF) + RotL64(aOrbiterB, 35U)) + aNonceWordJ);
            aWandererC = aWandererC + ((((RotL64(aCross, 29U) + RotL64(aOrbiterA, 23U)) + aOrbiterB) + aNonceWordI) + aWandererUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 20U) + aOrbiterA) + RotL64(aOrbiterH, 51U)) + aNonceWordB);
            aWandererD = aWandererD + ((((RotL64(aIngress, 35U) + aOrbiterG) + RotL64(aOrbiterH, 29U)) + RotL64(aCarry, 23U)) + aWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterC, 43U)) + aOrbiterH);
            aWandererB = aWandererB + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterC, 60U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 46U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + (RotL64(aWandererF, 41U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererD, 19U);
            aCarry = aCarry + RotL64(aIngress, 30U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 4
        // ingress from: aWorkLaneC, aWorkLaneA, aOperationLaneB
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aOperationLaneB forward/backward random
        // cross from: aWorkLaneB, aExpandLaneC, aFireLaneD
        // cross directions: aWorkLaneB backward forced, aExpandLaneC backward forced, aFireLaneD backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 25837U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((aIndex + 29597U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aOperationLaneB[((aIndex + 32114U)) & S_BLOCK1], 10U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25432U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 29070U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 28099U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCarry, 29U)) ^ (RotL64(aPrevious, 41U) + RotL64(aCross, 12U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterG = (((aWandererE + RotL64(aScatter, 51U)) + RotL64(aCarry, 57U)) + 9888431329297626900U) + aNonceWordD;
            aOrbiterD = (((aWandererI + RotL64(aCross, 57U)) + 2937735167534624403U) + aOrbiterAssignSaltC[((aIndex + 26U)) & S_SALT1]) + aNonceWordC;
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 11U)) + 17626022970343789617U) + aNonceWordE;
            aOrbiterB = (((aWandererG + RotL64(aIngress, 19U)) + RotL64(aCarry, 43U)) + 5665660859333693743U) + aNonceWordK;
            aOrbiterF = (aWandererA + RotL64(aScatter, 44U)) + 1060537034632076669U;
            aOrbiterK = (aWandererH + RotL64(aPrevious, 29U)) + 743777763907175800U;
            aOrbiterA = (((aWandererD + RotL64(aCross, 5U)) + RotL64(aCarry, 21U)) + 5744905970181808845U) + aOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 3545351394494002180U) + aNonceWordO;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 4877547088414106007U;
            aOrbiterI = RotL64((aOrbiterI * 5416792889338547109U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 11669378338379598445U) + aNonceWordP;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 2961072441706158212U;
            aOrbiterK = RotL64((aOrbiterK * 2677988507090705371U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 13984945589234919765U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 1433097875470903205U;
            aOrbiterB = RotL64((aOrbiterB * 451996840039906781U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 716415411025451152U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 8542286150858297810U;
            aOrbiterD = RotL64((aOrbiterD * 9139015340823332449U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 12932391786479661299U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 14005503313299177013U) ^ aNonceWordH;
            aOrbiterG = RotL64((aOrbiterG * 802663466907819743U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 9382792812676318046U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 5138554251079724724U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6386016499265056247U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 8522380066269546172U) + aOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 11825536408101906458U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17042837108792016849U), 13U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterF, 12U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 41U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aPrevious, 3U) + aOrbiterA) + RotL64(aOrbiterG, 19U)) + aWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterK, 47U)) + aOrbiterB);
            aWandererH = aWandererH + ((((RotL64(aIngress, 41U) + RotL64(aOrbiterI, 13U)) + aOrbiterB) + RotL64(aCarry, 43U)) + aNonceWordM);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 18U) + aOrbiterK) + RotL64(aOrbiterA, 39U)) + aNonceWordA);
            aWandererE = aWandererE + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterF, 58U)) + aOrbiterI);
            aWandererI = aWandererI ^ (((RotL64(aCross, 27U) + aOrbiterB) + RotL64(aOrbiterF, 27U)) + aWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 35U) + aOrbiterD) + RotL64(aOrbiterA, 5U)) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 34U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererI, 29U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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

void TwistExpander_Rugby_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xF6F5B8DF746882BFULL + 0xD1E783BBD2E9C359ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xD5D0A47F53D32893ULL + 0x8C659F7E9A644024ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xED75B93DD321EB2FULL + 0xEC1009CA491F5393ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xC345B5BE4129B27FULL + 0xC2A45C404FAFDA4BULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xCEAFDD6CE02C0FE9ULL + 0xE70DAEB1B121DAEAULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xE7F83F13F80C8FA7ULL + 0xB85E09E0A5F20D57ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x99B4454612D4A3F5ULL + 0xE0767A287E0E5DA8ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x8056B572D59F2FA7ULL + 0xE16E177F15935754ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xDDDC556715BFDC75ULL + 0xC3812A171F477071ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x8BEE458ED9C9DA3DULL + 0xAFB874FE4DBC424BULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x84511A5322B65E61ULL + 0xFFFC68C0C6E68ABFULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xBAAE5A1BFF2A3E07ULL + 0xD8290A91776ED3BDULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xED3A8DBABAEDD38BULL + 0xB6A860BAC31C2353ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x8C9D742513DCCA29ULL + 0xEA17C9F45EF9F566ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xF83B16941A88E6E7ULL + 0xF2E2489BB4743C5CULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xD23646DE6388F375ULL + 0xDEC73A17BBBC73EDULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aOperationLaneC, aWorkLaneC, aWorkLaneD, aFireLaneD, aExpandLaneA, aOperationLaneD, aFireLaneA, aExpandLaneB, aFireLaneB, aFireLaneC, aExpandLaneC, aOperationLaneB, aOperationLaneA
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_a loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aOperationLaneC
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aOperationLaneC forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aFireLaneD
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 7168U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((aIndex + 788U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 3976U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 6771U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 6058U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 2938U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCross, 23U)) ^ (RotL64(aCarry, 39U) + RotL64(aPrevious, 52U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterB = ((aWandererE + RotL64(aIngress, 3U)) + 9080426856729228705U) + aNonceWordI;
            aOrbiterI = (((aWandererK + RotL64(aScatter, 27U)) + RotL64(aCarry, 43U)) + 7851218321653539276U) + aNonceWordC;
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 35U)) + 7023344692919298036U;
            aOrbiterC = ((aWandererD + RotL64(aCross, 19U)) + 9772846154227440734U) + aNonceWordL;
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 57U)) + RotL64(aCarry, 5U)) + 12008298632429608431U;
            aOrbiterD = ((((aWandererH + RotL64(aCross, 13U)) + RotL64(aCarry, 29U)) + 12201090455849562875U) + aOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1]) + aNonceWordN;
            aOrbiterF = ((aWandererA + RotL64(aIngress, 50U)) + 9498721803411445471U) + aOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1];
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 351203764023093632U) + aNonceWordF;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 4966360430644539250U;
            aOrbiterH = RotL64((aOrbiterH * 10138518378274592739U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 9194167899071345693U) + aNonceWordK;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 4922477697284269116U;
            aOrbiterK = RotL64((aOrbiterK * 8444814161720407881U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 15742625291642356429U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 7528703106518431730U;
            aOrbiterC = RotL64((aOrbiterC * 11530049278751507567U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 15279053574704935317U) + aOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 2425839793660355555U;
            aOrbiterF = RotL64((aOrbiterF * 11486964816849830667U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 13209849392400008898U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 9041500097716231309U;
            aOrbiterB = RotL64((aOrbiterB * 340661035700748739U), 47U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterK) + 7885423750878814599U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordG;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 1992993999902904603U) ^ aOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1478629826632201617U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 6120758615019314102U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 8529621625846992066U;
            aOrbiterI = RotL64((aOrbiterI * 8485991471612862467U), 41U);
            //
            aIngress = RotL64(aOrbiterD, 5U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterC, 41U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterH, 29U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterI, 50U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterH, 23U)) + aOrbiterC);
            aWandererH = aWandererH + (((RotL64(aIngress, 19U) + RotL64(aOrbiterB, 29U)) + aOrbiterK) + RotL64(aCarry, 23U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 60U) + aOrbiterH) + RotL64(aOrbiterB, 41U)) + aWandererUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 3U) + RotL64(aOrbiterC, 14U)) + aOrbiterD) + RotL64(aCarry, 41U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterI, 5U)) + aOrbiterK) + aNonceWordD);
            aWandererK = aWandererK + (((RotL64(aScatter, 51U) + aOrbiterF) + RotL64(aOrbiterC, 35U)) + aNonceWordP);
            aWandererE = aWandererE ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterF, 51U)) + aOrbiterK) + aWandererUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 12U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererD, 41U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererA, 3U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aOperationLaneD
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aOperationLaneD forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aFireLaneA
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aFireLaneA backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 8449U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneC[((aIndex + 11722U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aOperationLaneD[((aIndex + 9451U)) & S_BLOCK1], 30U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11127U)) & S_BLOCK1], 26U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 12913U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 12716U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 51U) + RotL64(aIngress, 37U)) ^ (RotL64(aCarry, 24U) ^ RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterD = (aWandererD + RotL64(aPrevious, 23U)) + 13442819395490639310U;
            aOrbiterA = ((aWandererG + RotL64(aCross, 39U)) + 8187292523194120936U) + aNonceWordL;
            aOrbiterI = (((aWandererK + RotL64(aIngress, 13U)) + RotL64(aCarry, 3U)) + 11469697159823131388U) + aNonceWordP;
            aOrbiterH = (((aWandererH + RotL64(aScatter, 57U)) + RotL64(aCarry, 41U)) + 13414083692375929653U) + aNonceWordB;
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 3U)) + RotL64(aCarry, 21U)) + 11404010733687907517U;
            aOrbiterF = ((aWandererE + RotL64(aIngress, 29U)) + 6783212827186218247U) + aOrbiterAssignSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = ((aWandererF + RotL64(aCross, 48U)) + 8561131439340372614U) + aOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            //
            aOrbiterD = (((aOrbiterD + aOrbiterA) + 6252609642004429113U) + aOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1]) + aNonceWordH;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 12804867444200448952U) ^ aOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3114688959081972615U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 2739648749603690781U) + aOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 14808861217017399752U;
            aOrbiterB = RotL64((aOrbiterB * 373911885694012101U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 17588866502571268888U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 5882260142735642980U;
            aOrbiterA = RotL64((aOrbiterA * 7688252946143263869U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 15493099088132862949U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 5175647411532429582U) ^ aNonceWordC;
            aOrbiterF = RotL64((aOrbiterF * 15226544495598541883U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 14279707376173642767U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 6826363572161275158U;
            aOrbiterH = RotL64((aOrbiterH * 5263708315440161809U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 13267185753040999992U) + aNonceWordN;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 9980987858092888720U;
            aOrbiterE = RotL64((aOrbiterE * 13210290848800728635U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 3582972937645514549U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 10140409019562890804U;
            aOrbiterD = RotL64((aOrbiterD * 6944490201647678479U), 21U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterF, 43U);
            aIngress = aIngress + (RotL64(aOrbiterH, 51U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 29U));
            aIngress = aIngress + RotL64(aOrbiterE, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((((RotL64(aPrevious, 60U) + RotL64(aOrbiterA, 51U)) + aOrbiterE) + aNonceWordD) + aWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 11U) + RotL64(aOrbiterI, 60U)) + aOrbiterB);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterH, 35U)) + aOrbiterF) + aNonceWordG);
            aWandererD = aWandererD + (((RotL64(aIngress, 39U) + aOrbiterH) + RotL64(aOrbiterI, 43U)) + RotL64(aCarry, 13U));
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 53U) + aOrbiterE) + RotL64(aOrbiterF, 3U)) + aNonceWordK) + aWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aScatter, 29U) + aOrbiterD) + RotL64(aOrbiterA, 27U)) + RotL64(aCarry, 37U)) + aNonceWordO);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterD, 11U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (RotL64(aWandererH, 6U) ^ aWandererK);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 21U));
            aCarry = aCarry + RotL64(aWandererG, 43U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 3
        // ingress from: aExpandLaneB, aWorkLaneD, aFireLaneB
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aFireLaneB forward/backward random
        // cross from: aExpandLaneA, aWorkLaneB, aFireLaneC
        // cross directions: aExpandLaneA backward forced, aWorkLaneB backward forced, aFireLaneC backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 23419U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneD[((aIndex + 18246U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 21842U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22287U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 16386U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 22719U)) & S_BLOCK1], 48U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCross, 40U)) + (RotL64(aPrevious, 11U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterF = (((aWandererE + RotL64(aScatter, 35U)) + 6069475454765660321U) + aOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordM;
            aOrbiterC = (((aWandererF + RotL64(aIngress, 3U)) + RotL64(aCarry, 53U)) + 11483704742497268068U) + aNonceWordD;
            aOrbiterH = (((aWandererA + RotL64(aPrevious, 54U)) + RotL64(aCarry, 41U)) + 11055697447388986418U) + aOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = ((aWandererK + RotL64(aCross, 27U)) + 10897095046039997004U) + aNonceWordH;
            aOrbiterJ = (aWandererI + RotL64(aScatter, 19U)) + 4731637118230457840U;
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 43U)) + 13855839187084986751U) + aNonceWordB;
            aOrbiterG = ((aWandererJ + RotL64(aCross, 13U)) + RotL64(aCarry, 21U)) + 5328208115460188239U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 12479538544291412985U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 10740165998792608231U;
            aOrbiterH = RotL64((aOrbiterH * 14046827922294477379U), 13U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterJ) + 6492798157284955373U) + aOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1]) + aNonceWordI;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 13056825957483891921U;
            aOrbiterB = RotL64((aOrbiterB * 14882112110627751751U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 2068184064919194657U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 5656302738780746294U;
            aOrbiterF = RotL64((aOrbiterF * 16493021179127646345U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 11193756120230763294U) + aOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 17306750816837208999U) ^ aOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7949360041241439741U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 12952818800389361804U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 15380412293642628312U;
            aOrbiterC = RotL64((aOrbiterC * 2914662289178925547U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 7706090204767242996U) + aNonceWordP;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 14598802276412649570U) ^ aNonceWordL;
            aOrbiterD = RotL64((aOrbiterD * 4821408736292041399U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 17819762117328075515U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 6481384240915075101U;
            aOrbiterG = RotL64((aOrbiterG * 4836701121865783029U), 3U);
            //
            aIngress = RotL64(aOrbiterG, 10U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 47U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 35U));
            aIngress = aIngress + RotL64(aOrbiterC, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aScatter, 53U) + aOrbiterD) + RotL64(aOrbiterC, 35U)) + aWandererUpdateSaltE[((aIndex + 28U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aIngress, 60U) + aOrbiterJ) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 23U)) + aWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterH, 13U)) + aOrbiterD);
            aWandererF = aWandererF + ((((RotL64(aCross, 47U) + RotL64(aOrbiterG, 57U)) + aOrbiterF) + RotL64(aCarry, 47U)) + aNonceWordJ);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterH, 48U)) + aOrbiterJ);
            aWandererK = aWandererK + (((RotL64(aIngress, 35U) + aOrbiterC) + RotL64(aOrbiterG, 19U)) + aNonceWordO);
            aWandererA = aWandererA ^ ((RotL64(aCross, 5U) + aOrbiterB) + RotL64(aOrbiterF, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 11U) ^ aWandererJ);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 44U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + RotL64(aWandererE, 51U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aOperationLaneB
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aOperationLaneB forward/backward random
        // cross from: aExpandLaneB, aWorkLaneC, aOperationLaneA
        // cross directions: aExpandLaneB backward forced, aWorkLaneC backward forced, aOperationLaneA backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 26189U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneA[((aIndex + 32525U)) & S_BLOCK1], 50U));
            aIngress ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31050U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30516U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 30643U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 27458U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aIngress, 21U) ^ RotL64(aCarry, 54U)) ^ (RotL64(aCross, 41U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterA = (aWandererK + RotL64(aPrevious, 35U)) + 16183871922837164759U;
            aOrbiterB = (((aWandererD + RotL64(aCross, 23U)) + RotL64(aCarry, 35U)) + 7002058258090219055U) + aNonceWordH;
            aOrbiterD = ((((aWandererA + RotL64(aIngress, 51U)) + RotL64(aCarry, 13U)) + 5650868611888303705U) + aOrbiterAssignSaltF[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterE = ((aWandererC + RotL64(aScatter, 12U)) + RotL64(aCarry, 51U)) + 11899839660943876690U;
            aOrbiterC = (aWandererF + RotL64(aIngress, 3U)) + 15349649504488111111U;
            aOrbiterF = (aWandererH + RotL64(aPrevious, 29U)) + 14060149569086744970U;
            aOrbiterK = ((aWandererG + RotL64(aCross, 41U)) + 12920917574225030112U) + aOrbiterAssignSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 2831994965175330135U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 18312543585028439192U;
            aOrbiterD = RotL64((aOrbiterD * 11618182708195744321U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 11657562205118394239U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 10850792819281246052U) ^ aNonceWordE;
            aOrbiterE = RotL64((aOrbiterE * 10663100544207879337U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 17810371216216125323U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 7963413941144223128U;
            aOrbiterB = RotL64((aOrbiterB * 534217972450595401U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 5498715358793875584U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 9256727548911651373U;
            aOrbiterC = RotL64((aOrbiterC * 10498848323914000989U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 17246360111302191699U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 18309978718113983369U;
            aOrbiterK = RotL64((aOrbiterK * 18267472694666221077U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 3100998994319502921U) + aOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 8129301860291235970U) ^ aNonceWordG;
            aOrbiterF = RotL64((aOrbiterF * 17847033539279176187U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 1889641029473279114U) + aOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 16538494307002917945U) ^ aNonceWordL;
            aOrbiterA = RotL64((aOrbiterA * 8081488217920885783U), 19U);
            //
            aIngress = RotL64(aOrbiterA, 29U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterC, 56U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterF, 37U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterE, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aScatter, 57U) + RotL64(aOrbiterK, 5U)) + aOrbiterA) + aNonceWordO);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterB, 20U)) + aOrbiterD);
            aWandererH = aWandererH + (((RotL64(aIngress, 13U) + RotL64(aOrbiterC, 41U)) + aOrbiterA) + aNonceWordC);
            aWandererD = aWandererD ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterK, 47U)) + aOrbiterE);
            aWandererG = aWandererG + ((((RotL64(aIngress, 44U) + RotL64(aOrbiterF, 27U)) + aOrbiterC) + RotL64(aCarry, 43U)) + aWandererUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 3U) + aOrbiterB) + RotL64(aOrbiterA, 11U));
            aWandererA = aWandererA + (((((RotL64(aScatter, 23U) + RotL64(aOrbiterE, 35U)) + aOrbiterF) + RotL64(aCarry, 13U)) + aNonceWordK) + aWandererUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererK, 52U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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

void TwistExpander_Rugby_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xEB0712707FF183CDULL + 0xD0752FE49CEE236DULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x9D87F9D5CE23317FULL + 0x810046280449EAA2ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xA212DD188EE56D4BULL + 0xB801E10FEC8810A5ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x92DFA122EA5876EFULL + 0xD830A75178E3A6C1ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x8FD65F5B9AD743B5ULL + 0xBB53A43E9C652709ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xD9DE15ED60386989ULL + 0xE6FCD877D6453A43ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xED074D07CFC89ADBULL + 0xBDC545ABDE1CE8AAULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xA532B94CCCBE4711ULL + 0xB0AF90150CE41BAAULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xBDBC7CCDB76C14CBULL + 0xD1E1A224EE373751ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x8517EBE2DC02128BULL + 0xE7866B893E2B9A1EULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xD3021548C00516EBULL + 0x8DB4D84902964FBFULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xE1FFE23CA4D01C0BULL + 0xBACECC16554A16A5ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xF5B85C197BCC4E37ULL + 0xC5081513E74F4DC6ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xD642D8DE54777207ULL + 0x88D6A4E9D63F9AD1ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xF9170BA9EAEB95B5ULL + 0xC99B92797E39E8B4ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xA5D32D81B9E6EC2FULL + 0xC725158741E9E469ULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aWorkLaneB, aExpandLaneC, aExpandLaneD, aWorkLaneA, aOperationLaneA, aWorkLaneD, aWorkLaneC, aOperationLaneB, aFireLaneA, aFireLaneD, aOperationLaneC, aFireLaneB, aFireLaneC
        // write to: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // kdf_b_loop_b loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aWorkLaneB
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aWorkLaneB forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aWorkLaneA
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aWorkLaneA backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 5508U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((aIndex + 683U)) & S_BLOCK1], 48U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 5763U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7860U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 114U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 3249U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 11U) ^ RotL64(aIngress, 23U)) + (RotL64(aCarry, 56U) + RotL64(aPrevious, 43U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterK = (aWandererH + RotL64(aScatter, 47U)) + 479672811032092393U;
            aOrbiterJ = ((aWandererK + RotL64(aIngress, 51U)) + 18061121631394564425U) + aNonceWordE;
            aOrbiterC = (((aWandererA + RotL64(aCross, 41U)) + RotL64(aCarry, 27U)) + 14237400452740566065U) + aOrbiterAssignSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterH = (aWandererC + RotL64(aPrevious, 56U)) + 6723123812257706134U;
            aOrbiterA = (aWandererD + RotL64(aIngress, 21U)) + 4247997188026499248U;
            aOrbiterF = (aWandererI + RotL64(aCross, 27U)) + 1939107415066134869U;
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 43U)) + RotL64(aCarry, 13U)) + 3912640123546395979U;
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 29U)) + 8295478436553964298U) + aNonceWordI;
            aOrbiterI = (aWandererE + RotL64(aIngress, 58U)) + 3218960600711526885U;
            aOrbiterD = (((aWandererB + RotL64(aScatter, 3U)) + RotL64(aCarry, 21U)) + 5874096203353388890U) + aNonceWordK;
            aOrbiterB = ((aWandererG + RotL64(aCross, 23U)) + 10294536533673023358U) + aOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 11268561953904130747U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 16693201256788898423U;
            aOrbiterC = RotL64((aOrbiterC * 16291987237693567209U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 7550969634681894654U) + aOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 9501647424602245869U;
            aOrbiterA = RotL64((aOrbiterA * 11265865222096866605U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 8881869255994319423U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 16770136406906800016U;
            aOrbiterG = RotL64((aOrbiterG * 1782039587385512923U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 16185384746435761363U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 13841034186650721627U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12000155593277035447U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 15229062695864608309U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 3576122704615303733U;
            aOrbiterK = RotL64((aOrbiterK * 2433987493885779279U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 13898167174453181224U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 12878032061609524049U;
            aOrbiterF = RotL64((aOrbiterF * 18104665741338251495U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 12719156051299028649U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 8640980843376950769U;
            aOrbiterE = RotL64((aOrbiterE * 10242616778390983333U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 12133332160916004365U) + aNonceWordP;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 8743563985229104484U;
            aOrbiterJ = RotL64((aOrbiterJ * 4575129690615054691U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 7362223873479167793U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 4230720394788635807U;
            aOrbiterD = RotL64((aOrbiterD * 3658720603716856293U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 5095842824285329272U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 7483469517256234638U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9782114499878763883U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 17426017004856399653U) + aNonceWordL;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 479672811032092393U;
            aOrbiterI = RotL64((aOrbiterI * 14921028515589317919U), 47U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterK, 41U);
            aIngress = aIngress + (RotL64(aOrbiterC, 43U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterF, 10U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 19U));
            aIngress = aIngress + RotL64(aOrbiterE, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterI, 57U)) + aOrbiterB) + aNonceWordN);
            aWandererI = aWandererI + ((((RotL64(aCross, 27U) + aOrbiterB) + RotL64(aOrbiterA, 39U)) + aNonceWordO) + aWandererUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 53U) + aOrbiterJ) + RotL64(aOrbiterH, 41U));
            aWandererH = aWandererH + ((((RotL64(aPrevious, 4U) + RotL64(aOrbiterC, 3U)) + aOrbiterE) + RotL64(aCarry, 23U)) + aNonceWordB);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 29U) + aOrbiterJ) + RotL64(aOrbiterG, 13U));
            aWandererD = aWandererD + (((RotL64(aScatter, 41U) + RotL64(aOrbiterF, 5U)) + aOrbiterK) + RotL64(aCarry, 39U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 43U) + aOrbiterF) + RotL64(aOrbiterI, 50U));
            aWandererB = aWandererB + ((RotL64(aCross, 35U) + RotL64(aOrbiterC, 37U)) + aOrbiterH);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 11U) + aOrbiterJ) + RotL64(aOrbiterD, 23U));
            aWandererF = aWandererF + (((RotL64(aCross, 48U) + RotL64(aOrbiterJ, 11U)) + aOrbiterE) + aWandererUpdateSaltA[((aIndex + 28U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterJ, 20U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 4U));
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererI);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 37U));
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 56U));
            aCarry = aCarry + RotL64(aWandererA, 35U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 2
        // ingress from: aOperationLaneA, aExpandLaneC, aWorkLaneD
        // ingress directions: aOperationLaneA forward forced, aExpandLaneC forward forced, aWorkLaneD forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD, aWorkLaneC
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward forced, aWorkLaneC backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 13081U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneC[((aIndex + 13192U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aWorkLaneD[((aIndex + 12982U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 13578U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 8352U)) & S_BLOCK1], 36U));
            aCross ^= RotL64(aWorkLaneC[((aIndex + 10762U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCarry, 11U)) + (RotL64(aCross, 58U) ^ RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterD = (aWandererI + RotL64(aCross, 39U)) + 18255347001097480328U;
            aOrbiterB = ((aWandererF + RotL64(aIngress, 52U)) + 13679246790311505735U) + aNonceWordA;
            aOrbiterA = (aWandererK + RotL64(aPrevious, 37U)) + 10565839529765027116U;
            aOrbiterE = (((aWandererA + RotL64(aScatter, 41U)) + RotL64(aCarry, 53U)) + 14327172566224769901U) + aNonceWordL;
            aOrbiterI = (aWandererC + RotL64(aCross, 21U)) + 16239024612038195174U;
            aOrbiterH = ((aWandererE + RotL64(aScatter, 23U)) + 13800012174212131890U) + aOrbiterAssignSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = ((aWandererB + RotL64(aIngress, 5U)) + RotL64(aCarry, 13U)) + 13900288860157577583U;
            aOrbiterG = (aWandererH + RotL64(aPrevious, 29U)) + 4144386119777112740U;
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 11U)) + 3154558262670631372U;
            aOrbiterC = ((aWandererG + RotL64(aScatter, 14U)) + 7456728543137614001U) + aOrbiterAssignSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 43U)) + RotL64(aCarry, 27U)) + 11709519851158935384U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 15607438907832240304U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 9276575329661725624U;
            aOrbiterA = RotL64((aOrbiterA * 8879744070762412745U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 6459435969129449226U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 6442382118416542275U;
            aOrbiterH = RotL64((aOrbiterH * 2921027306686588233U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 12117432107282150865U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 6831279293184793243U) ^ aNonceWordM;
            aOrbiterD = RotL64((aOrbiterD * 2435360641135249073U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 9520022957804572889U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 8322178689474588679U;
            aOrbiterE = RotL64((aOrbiterE * 1627707191467537115U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 4162401591586869316U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 8994015844714895961U;
            aOrbiterK = RotL64((aOrbiterK * 15421910378057951895U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 10038095909727959633U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 17756404450592957616U) ^ aOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14255952184627347295U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 3379089265413427719U) + aNonceWordN;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 11341713098678108441U;
            aOrbiterC = RotL64((aOrbiterC * 2500587373161411961U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 4030296130743454165U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 6332387792111212064U;
            aOrbiterG = RotL64((aOrbiterG * 16490982218150897861U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 14893209417387662133U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 9265457389326311687U;
            aOrbiterF = RotL64((aOrbiterF * 9778404505547862689U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 13496086915199406901U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 14576555328710787951U;
            aOrbiterJ = RotL64((aOrbiterJ * 13155395071667672943U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 11482324648071976743U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 18255347001097480328U) ^ aNonceWordI;
            aOrbiterI = RotL64((aOrbiterI * 10918514878283385643U), 43U);
            //
            aIngress = RotL64(aOrbiterE, 11U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 53U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 35U));
            aIngress = aIngress + (RotL64(aOrbiterC, 46U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aCross, 51U) + RotL64(aOrbiterG, 13U)) + aOrbiterF) + aNonceWordF);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 35U) + aOrbiterA) + RotL64(aOrbiterH, 3U));
            aWandererF = aWandererF + ((((RotL64(aScatter, 26U) + RotL64(aOrbiterE, 20U)) + aOrbiterB) + aNonceWordD) + aWandererUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 43U) + aOrbiterE) + RotL64(aOrbiterC, 37U));
            aWandererK = aWandererK + ((RotL64(aScatter, 47U) + RotL64(aOrbiterK, 51U)) + aOrbiterA);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 41U) + aOrbiterA) + RotL64(aOrbiterJ, 23U)) + aWandererUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterC, 39U)) + aOrbiterH) + RotL64(aCarry, 3U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterD, 26U)) + aOrbiterF);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 54U) + aOrbiterI) + RotL64(aOrbiterF, 53U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 29U) + aOrbiterK) + RotL64(aOrbiterJ, 43U));
            aWandererB = aWandererB + (((RotL64(aCross, 3U) + aOrbiterF) + RotL64(aOrbiterH, 35U)) + RotL64(aCarry, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererD);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 28U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 41U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 37U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + RotL64(aWandererJ, 56U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 3
        // ingress from: aOperationLaneB, aExpandLaneD, aFireLaneA
        // ingress directions: aOperationLaneB forward forced, aExpandLaneD forward forced, aFireLaneA forward/backward random
        // cross from: aOperationLaneA, aExpandLaneB, aFireLaneD
        // cross directions: aOperationLaneA backward forced, aExpandLaneB backward forced, aFireLaneD backward/forward random
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 18769U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((aIndex + 23222U)) & S_BLOCK1], 24U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 16977U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 23718U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 19577U)) & S_BLOCK1], 30U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 20060U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aPrevious, 35U) ^ RotL64(aCarry, 47U)) ^ (RotL64(aCross, 6U) + RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 39U)) + RotL64(aCarry, 51U)) + 12980104182836602177U;
            aOrbiterF = (aWandererB + RotL64(aCross, 37U)) + 3172622203188863995U;
            aOrbiterI = ((aWandererH + RotL64(aIngress, 24U)) + 1170974132219980203U) + aOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = (aWandererE + RotL64(aScatter, 5U)) + 6035201940965047490U;
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 43U)) + RotL64(aCarry, 57U)) + 18033907118424996722U;
            aOrbiterK = (((aWandererJ + RotL64(aPrevious, 57U)) + 14604813424800580304U) + aOrbiterAssignSaltC[((aIndex + 16U)) & S_SALT1]) + aNonceWordF;
            aOrbiterG = ((aWandererD + RotL64(aScatter, 14U)) + 13720232492851066035U) + aNonceWordB;
            aOrbiterA = ((aWandererK + RotL64(aCross, 19U)) + RotL64(aCarry, 39U)) + 3902659710585257448U;
            aOrbiterD = ((aWandererI + RotL64(aScatter, 21U)) + 8331560652661619868U) + aNonceWordO;
            aOrbiterC = (aWandererG + RotL64(aIngress, 41U)) + 4485014147538689794U;
            aOrbiterH = (aWandererA + RotL64(aPrevious, 35U)) + 168202636924512424U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 16227825670092707848U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 4792781933944671365U;
            aOrbiterI = RotL64((aOrbiterI * 15859849676231455283U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 12636865372722601282U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 18198291399585556632U;
            aOrbiterK = RotL64((aOrbiterK * 18155803890313399795U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 3650053185419807206U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 5897288963905408776U;
            aOrbiterF = RotL64((aOrbiterF * 3706949366974086151U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 9922308113622901726U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 13352279749091561510U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4025213180483632557U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 14969461950939646117U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 10231661776135056651U;
            aOrbiterB = RotL64((aOrbiterB * 11284575051455238501U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 10621934544068320859U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterI) ^ 6029116920305246887U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterE = RotL64((aOrbiterE * 6087523725059376905U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 12887482425168671195U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 8351351557123783853U;
            aOrbiterJ = RotL64((aOrbiterJ * 3839381627914762245U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 5405938210926464973U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 385145802287899406U) ^ aOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8330751480464271445U), 53U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterI) + 7907749190875916461U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordN;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 5138733192253468642U;
            aOrbiterH = RotL64((aOrbiterH * 17028325976353263843U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 14382272868178763187U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 14354777100157531233U;
            aOrbiterD = RotL64((aOrbiterD * 7095764230272037767U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 4390647647193363824U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 12980104182836602177U) ^ aNonceWordM;
            aOrbiterA = RotL64((aOrbiterA * 11124472075872147333U), 23U);
            //
            aIngress = RotL64(aOrbiterI, 13U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterE, 35U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 41U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 51U));
            aIngress = aIngress + RotL64(aOrbiterF, 48U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 27U) + aOrbiterH) + RotL64(aOrbiterK, 39U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 47U) + aOrbiterI) + RotL64(aOrbiterG, 44U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterF, 37U)) + aOrbiterE);
            aWandererF = aWandererF + (((RotL64(aScatter, 58U) + RotL64(aOrbiterJ, 47U)) + aOrbiterH) + aWandererUpdateSaltC[((aIndex + 28U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterJ, 21U)) + aOrbiterE);
            aWandererC = aWandererC + (((RotL64(aCross, 3U) + aOrbiterD) + RotL64(aOrbiterK, 30U)) + RotL64(aCarry, 23U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 13U) + aOrbiterF) + RotL64(aOrbiterC, 35U)) + aNonceWordH);
            aWandererA = aWandererA + ((RotL64(aScatter, 35U) + RotL64(aOrbiterH, 27U)) + aOrbiterG);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 42U) + RotL64(aOrbiterH, 23U)) + aOrbiterA) + aNonceWordP);
            aWandererG = aWandererG + (((RotL64(aScatter, 37U) + RotL64(aOrbiterI, 53U)) + aOrbiterB) + RotL64(aCarry, 41U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterJ, 5U)) + aOrbiterA) + aWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 46U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererI);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + RotL64(aWandererD, 60U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 4
        // ingress from: aOperationLaneC, aOperationLaneA, aFireLaneB
        // ingress directions: aOperationLaneC forward forced, aOperationLaneA forward forced, aFireLaneB forward/backward random
        // cross from: aOperationLaneB, aExpandLaneC, aFireLaneC
        // cross directions: aOperationLaneB backward forced, aExpandLaneC backward forced, aFireLaneC backward/forward random
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneC[((aIndex + 26912U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneA[((aIndex + 28699U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 30469U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31769U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 28441U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 31937U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCarry, 37U) + RotL64(aPrevious, 22U)) ^ (RotL64(aIngress, 3U) + RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterD = (aWandererJ + RotL64(aIngress, 47U)) + 16124889768301047791U;
            aOrbiterJ = (((aWandererC + RotL64(aScatter, 22U)) + 11912338587186717280U) + aOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordM;
            aOrbiterH = (aWandererB + RotL64(aCross, 41U)) + 8594012868813114354U;
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 5U)) + RotL64(aCarry, 35U)) + 18281043566156682815U;
            aOrbiterC = ((aWandererA + RotL64(aCross, 13U)) + 16853106130200942302U) + aOrbiterAssignSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = (aWandererI + RotL64(aPrevious, 39U)) + 2611212958619673086U;
            aOrbiterB = (aWandererD + RotL64(aIngress, 11U)) + 18039472325066855180U;
            aOrbiterI = ((aWandererK + RotL64(aScatter, 43U)) + RotL64(aCarry, 23U)) + 14495785571345122046U;
            aOrbiterG = (aWandererH + RotL64(aPrevious, 3U)) + 4556063793412832418U;
            aOrbiterF = ((aWandererG + RotL64(aScatter, 19U)) + 14896419970271244358U) + aNonceWordH;
            aOrbiterK = ((aWandererF + RotL64(aIngress, 28U)) + RotL64(aCarry, 11U)) + 880028529183500036U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 2379557167489415783U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 11854373946064529806U) ^ aOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 150755294320438887U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 1487252775956449964U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 12777924204511625545U;
            aOrbiterJ = RotL64((aOrbiterJ * 1366019527386994789U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 15998631485222477969U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 8864212892296191613U;
            aOrbiterB = RotL64((aOrbiterB * 579242788050369815U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 17069347835763226743U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 7443008171694679791U;
            aOrbiterG = RotL64((aOrbiterG * 748894368884566607U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 17334256152350782002U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 8986626119086556393U) ^ aNonceWordF;
            aOrbiterC = RotL64((aOrbiterC * 2258172145924120235U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 8528180968228358674U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 12702290928064582589U) ^ aNonceWordL;
            aOrbiterF = RotL64((aOrbiterF * 15673603224146737631U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 7742438100860023610U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 3729687240959702198U;
            aOrbiterE = RotL64((aOrbiterE * 3756794766163746783U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 426129097367382096U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 16782175452274911213U;
            aOrbiterK = RotL64((aOrbiterK * 1041477289638333659U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 5942016166948841079U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 5260815086125551703U) ^ aOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1603799103692438147U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 11732742583346900772U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 17182924380693084401U;
            aOrbiterI = RotL64((aOrbiterI * 14858685629471497071U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 8539335803784852017U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 16124889768301047791U;
            aOrbiterD = RotL64((aOrbiterD * 6607245691919237755U), 53U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterB, 19U);
            aIngress = aIngress + (RotL64(aOrbiterI, 51U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterA, 5U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 23U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 46U));
            aIngress = aIngress + RotL64(aOrbiterE, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aCross, 43U) + aOrbiterJ) + RotL64(aOrbiterE, 57U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterI, 53U)) + aOrbiterD);
            aWandererI = aWandererI + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterD, 43U)) + aOrbiterJ);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 34U) + RotL64(aOrbiterE, 46U)) + aOrbiterK) + aWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 57U) + RotL64(aOrbiterE, 41U)) + aOrbiterC) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterB, 51U)) + aOrbiterK);
            aWandererE = aWandererE + (((RotL64(aCross, 3U) + RotL64(aOrbiterG, 5U)) + aOrbiterD) + aNonceWordK);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterE, 23U)) + aOrbiterD);
            aWandererB = aWandererB + ((((RotL64(aCross, 60U) + aOrbiterH) + RotL64(aOrbiterA, 13U)) + RotL64(aCarry, 41U)) + aNonceWordA);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 23U) + aOrbiterD) + RotL64(aOrbiterF, 3U));
            aWandererD = aWandererD + (((RotL64(aIngress, 5U) + RotL64(aOrbiterA, 20U)) + aOrbiterK) + aWandererUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 24U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererG, 53U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 41U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererC, 37U);
            aCarry = aCarry + RotL64(aIngress, 44U);
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

void TwistExpander_Rugby_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x8A321BB64D94AF63ULL + 0x8FF091E83669A5DCULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xB68ABCCC1633C6F1ULL + 0xCEFFC60243B1DE0EULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x9786FBE3110A54F1ULL + 0xBE30FC15EA89BD60ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xDCFB9374F4111665ULL + 0xCDF6829142CD51B7ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xFB8412F0FA71B959ULL + 0xD9A6CD2CC43BB569ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xC065042EAB5323A7ULL + 0xC27A0FDFFC07C945ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xDA1D984762903F27ULL + 0xFEC62633DC722BABULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xD7CB659E1194D70DULL + 0xEB0265D7BCEB8452ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xFBA25E53D7850CD3ULL + 0xBF36402BA27C92DBULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xA515158A9366E44BULL + 0xBE2566CB45BFD22FULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xC5FFA163C786048DULL + 0x953F8E227CDA2EF3ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xA561FCEAD21A83BFULL + 0x988571CCF9E0F5BCULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xE10F1E48F2EB9BFFULL + 0xAA7D7FB3249038C1ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xCCC05414438BA2A5ULL + 0xC087F97488122127ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xD760D1D1FE2A9669ULL + 0xC0CE002EEDFF1EC6ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xF34D31D1C0B3F1AFULL + 0xD04C70A1C47647B3ULL);
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
        // read from: aOperationLaneA, aOperationLaneB, aWorkLaneC, aOperationLaneC, aOperationLaneD, aWorkLaneA, aExpandLaneA, aFireLaneC, aFireLaneB, aExpandLaneB, aWorkLaneB, aWorkLaneD, aExpandLaneC, aFireLaneD, aFireLaneA
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aWorkLaneC
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aWorkLaneC forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aWorkLaneA
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aWorkLaneA backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 6770U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneB[((aIndex + 1021U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 5712U)) & S_BLOCK1], 58U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 7147U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 2224U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 1018U)) & S_BLOCK1], 28U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCross, 6U) ^ RotL64(aPrevious, 53U)) + (RotL64(aCarry, 19U) ^ RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterK = (aWandererF + RotL64(aScatter, 5U)) + 9630214189402543339U;
            aOrbiterA = (aWandererK + RotL64(aPrevious, 14U)) + 4072576573737526819U;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 21U)) + RotL64(aCarry, 37U)) + 15994787452709618869U;
            aOrbiterB = ((aWandererG + RotL64(aCross, 29U)) + RotL64(aCarry, 53U)) + 6403240137132259482U;
            aOrbiterJ = (((aWandererA + RotL64(aIngress, 39U)) + 10229266900170507720U) + aOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1]) + aNonceWordO;
            aOrbiterE = (((aWandererE + RotL64(aPrevious, 60U)) + 5025294577989748989U) + aOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordP;
            aOrbiterH = ((aWandererH + RotL64(aScatter, 35U)) + RotL64(aCarry, 23U)) + 16696461238217956883U;
            aOrbiterD = ((aWandererC + RotL64(aCross, 43U)) + 9878318855341719119U) + aNonceWordL;
            aOrbiterG = (aWandererJ + RotL64(aIngress, 47U)) + 16086635438116177346U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 12295437783084203730U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = (((aOrbiterF ^ aOrbiterK) ^ 7681150419912842402U) ^ aOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterF = RotL64((aOrbiterF * 7289497379725191451U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 2639104034287637448U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 12298170009332243573U;
            aOrbiterJ = RotL64((aOrbiterJ * 9397919591171238575U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 3485932317267669626U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 16569551670038752475U;
            aOrbiterE = RotL64((aOrbiterE * 8139802826402217631U), 35U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterF) + 4448490103784103954U) + aOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1]) + aNonceWordN;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 14510534073046885941U;
            aOrbiterH = RotL64((aOrbiterH * 7777192047386438305U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 4286195398675733451U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 15790355933840266463U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13342257823027075501U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 6362891510370156055U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 15121822034579983174U;
            aOrbiterB = RotL64((aOrbiterB * 7268045994574844937U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 13817341015719915628U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 14113474087906143783U;
            aOrbiterA = RotL64((aOrbiterA * 12838910141533126059U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 9988301252236121106U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 11287477288382171758U;
            aOrbiterD = RotL64((aOrbiterD * 4979297247881426383U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 9491727010910328644U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 7961202721830514030U;
            aOrbiterG = RotL64((aOrbiterG * 16300364540313620767U), 43U);
            //
            aIngress = RotL64(aOrbiterK, 43U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 53U));
            aIngress = aIngress + (RotL64(aOrbiterF, 13U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterG, 27U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterD, 34U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterE, 3U)) + aOrbiterG) + RotL64(aCarry, 27U)) + aWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 19U) + aOrbiterD) + RotL64(aOrbiterH, 35U));
            aWandererA = aWandererA + ((RotL64(aScatter, 51U) + aOrbiterD) + RotL64(aOrbiterF, 23U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 10U) + RotL64(aOrbiterG, 56U)) + aOrbiterH);
            aWandererC = aWandererC + ((RotL64(aIngress, 39U) + RotL64(aOrbiterA, 27U)) + aOrbiterK);
            aWandererK = aWandererK ^ (((RotL64(aCross, 3U) + aOrbiterJ) + RotL64(aOrbiterA, 13U)) + aWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aPrevious, 27U) + aOrbiterJ) + RotL64(aOrbiterD, 47U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 23U) + aOrbiterH) + RotL64(aOrbiterE, 19U)) + aNonceWordA);
            aWandererF = aWandererF + ((((RotL64(aIngress, 46U) + RotL64(aOrbiterB, 52U)) + aOrbiterK) + RotL64(aCarry, 11U)) + aNonceWordM);
            //
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererF, 14U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 2
        // ingress from: aExpandLaneA, aOperationLaneC, aFireLaneC
        // ingress directions: aExpandLaneA forward forced, aOperationLaneC forward forced, aFireLaneC forward/backward random
        // cross from: aOperationLaneA, aOperationLaneD, aFireLaneB
        // cross directions: aOperationLaneA backward forced, aOperationLaneD backward forced, aFireLaneB backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 12796U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneC[((aIndex + 13597U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 8680U)) & S_BLOCK1], 26U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 13055U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 11784U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 9441U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aPrevious, 3U) ^ RotL64(aCross, 39U)) + (RotL64(aIngress, 18U) ^ RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterA = ((aWandererG + RotL64(aScatter, 58U)) + 15383045568644941552U) + aOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = ((aWandererC + RotL64(aCross, 47U)) + 17452811657750910067U) + aNonceWordP;
            aOrbiterK = (aWandererD + RotL64(aPrevious, 35U)) + 15660117718455155603U;
            aOrbiterD = ((aWandererK + RotL64(aIngress, 43U)) + RotL64(aCarry, 11U)) + 10396441207743665753U;
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 10U)) + RotL64(aCarry, 41U)) + 3708971058200841442U;
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 5U)) + 7000673057768598750U) + aNonceWordN;
            aOrbiterH = ((aWandererB + RotL64(aCross, 19U)) + RotL64(aCarry, 29U)) + 9886354469011131596U;
            aOrbiterC = (aWandererF + RotL64(aScatter, 39U)) + 16018065329058043467U;
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 29U)) + 5024756166109352320U) + aOrbiterAssignSaltD[((aIndex + 8U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 6587818720728886652U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 3652672354944162319U;
            aOrbiterK = RotL64((aOrbiterK * 10807121230791716109U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 6307315649915348048U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterD) ^ 16405347331742979258U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterF = RotL64((aOrbiterF * 7183142442906743699U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 5427299664054601957U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 4983381733483185898U;
            aOrbiterD = RotL64((aOrbiterD * 14646556236306407673U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 10182995521328377487U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 8694282877540593550U;
            aOrbiterJ = RotL64((aOrbiterJ * 14614602561910403893U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 4085927978153269932U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 6176195962815240877U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16792916528959579875U), 5U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterD) + 6966742100601433005U) + aOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1]) + aNonceWordC;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 9920952446921247521U;
            aOrbiterC = RotL64((aOrbiterC * 1879821050131820933U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 11958734477518336014U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 2058335903640404380U;
            aOrbiterG = RotL64((aOrbiterG * 6986170159285417789U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 77366119537297816U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 12072894199692855000U;
            aOrbiterE = RotL64((aOrbiterE * 9083781120514635987U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 11874297832446385377U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 13715562531763053196U;
            aOrbiterH = RotL64((aOrbiterH * 12822488258322963187U), 47U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterF, 29U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 51U));
            aIngress = aIngress + (RotL64(aOrbiterK, 23U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterG, 26U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterA, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aIngress, 43U) + aOrbiterJ) + RotL64(aOrbiterD, 27U)) + aWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 30U) + aOrbiterH) + RotL64(aOrbiterF, 3U)) + RotL64(aCarry, 47U)) + aNonceWordJ);
            aWandererG = aWandererG ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterD, 53U)) + aOrbiterC);
            aWandererF = aWandererF + (((RotL64(aScatter, 19U) + aOrbiterC) + RotL64(aOrbiterA, 22U)) + RotL64(aCarry, 21U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterG, 37U)) + aOrbiterJ);
            aWandererK = aWandererK + (((RotL64(aScatter, 13U) + aOrbiterK) + RotL64(aOrbiterD, 13U)) + aNonceWordL);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 23U) + aOrbiterK) + RotL64(aOrbiterE, 43U)) + aWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 50U) + aOrbiterH) + RotL64(aOrbiterA, 58U)) + aNonceWordB);
            aWandererI = aWandererI ^ (((RotL64(aCross, 5U) + aOrbiterA) + RotL64(aOrbiterK, 47U)) + aNonceWordG);
            //
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererF, 4U) ^ aWandererC);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + RotL64(aWandererG, 23U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 3
        // ingress from: aExpandLaneB, aOperationLaneD, aWorkLaneB
        // ingress directions: aExpandLaneB forward forced, aOperationLaneD forward forced, aWorkLaneB forward/backward random
        // cross from: aExpandLaneA, aOperationLaneB, aWorkLaneD
        // cross directions: aExpandLaneA backward forced, aOperationLaneB backward forced, aWorkLaneD backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 22216U)) & S_BLOCK1], 30U) ^ RotL64(aOperationLaneD[((aIndex + 23916U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 17627U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 19932U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 17556U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 18723U)) & S_BLOCK1], 36U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCross, 36U) + RotL64(aIngress, 51U)) + (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterC = ((aWandererH + RotL64(aScatter, 27U)) + RotL64(aCarry, 47U)) + 7722279280863371124U;
            aOrbiterA = (((aWandererJ + RotL64(aPrevious, 36U)) + RotL64(aCarry, 57U)) + 11584220561732385598U) + aNonceWordO;
            aOrbiterD = ((aWandererB + RotL64(aCross, 11U)) + 7834679350105534657U) + aOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = (((aWandererE + RotL64(aIngress, 47U)) + RotL64(aCarry, 39U)) + 11347994382444180879U) + aNonceWordP;
            aOrbiterG = ((aWandererF + RotL64(aScatter, 57U)) + 9449903188047063431U) + aNonceWordJ;
            aOrbiterI = (aWandererG + RotL64(aIngress, 19U)) + 6516243976652795170U;
            aOrbiterH = ((aWandererK + RotL64(aCross, 53U)) + 8420815253991184777U) + aOrbiterAssignSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = (aWandererA + RotL64(aPrevious, 40U)) + 9081386852515170937U;
            aOrbiterK = ((aWandererC + RotL64(aCross, 23U)) + 14375955191735286867U) + aNonceWordL;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 880757589768436072U) + aOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 3349856625725164229U;
            aOrbiterD = RotL64((aOrbiterD * 681514212582331781U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 7826309957607577207U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 8057435761214313635U) ^ aNonceWordG;
            aOrbiterI = RotL64((aOrbiterI * 4718430712767038607U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 9565237500443303103U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 15893066735310588501U;
            aOrbiterH = RotL64((aOrbiterH * 8457633439171452397U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 3276844534476430842U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 6828644383891274120U;
            aOrbiterF = RotL64((aOrbiterF * 979580351653410157U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 2815676923011504251U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 5030251870850928417U;
            aOrbiterC = RotL64((aOrbiterC * 7075653570570819253U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 13464083008377887034U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 8994560761846897590U) ^ aNonceWordD;
            aOrbiterA = RotL64((aOrbiterA * 9892839554658865143U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 8398813387154468736U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 8136429428340910892U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3348811490733577295U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 418587250696862341U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 4111667833838312094U;
            aOrbiterG = RotL64((aOrbiterG * 860949442143849147U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 6075478294190926371U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 2208124955874142264U;
            aOrbiterJ = RotL64((aOrbiterJ * 15741988616251072075U), 47U);
            //
            aIngress = RotL64(aOrbiterI, 41U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterF, 37U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 24U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 21U));
            aIngress = aIngress + RotL64(aOrbiterD, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aScatter, 10U) + RotL64(aOrbiterJ, 35U)) + aOrbiterK) + aWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 23U) + aOrbiterF) + RotL64(aOrbiterI, 11U)) + RotL64(aCarry, 51U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterC, 19U)) + aOrbiterG) + aNonceWordI);
            aWandererF = aWandererF + (((RotL64(aPrevious, 5U) + aOrbiterA) + RotL64(aOrbiterC, 28U)) + RotL64(aCarry, 35U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterD, 57U)) + aOrbiterG);
            aWandererK = aWandererK + (((RotL64(aPrevious, 53U) + aOrbiterC) + RotL64(aOrbiterH, 47U)) + aNonceWordC);
            aWandererA = aWandererA ^ ((((RotL64(aScatter, 19U) + RotL64(aOrbiterI, 53U)) + aOrbiterJ) + aNonceWordF) + aWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 39U) + aOrbiterC) + RotL64(aOrbiterF, 24U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 60U) + aOrbiterH) + RotL64(aOrbiterG, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererK);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + (RotL64(aWandererA, 54U) ^ aWandererE);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 41U));
            aCarry = aCarry + RotL64(aWandererB, 47U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aFireLaneD
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aFireLaneD forward/backward random
        // cross from: aExpandLaneB, aOperationLaneC, aFireLaneA
        // cross directions: aExpandLaneB backward forced, aOperationLaneC backward forced, aFireLaneA backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 30721U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneA[((aIndex + 27831U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 30116U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27711U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 29842U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 24597U)) & S_BLOCK1], 12U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 21U) ^ RotL64(aCarry, 35U)) + (RotL64(aPrevious, 4U) ^ RotL64(aCross, 47U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterA = (aWandererH + RotL64(aPrevious, 57U)) + 17668251151213543491U;
            aOrbiterK = (aWandererK + RotL64(aIngress, 30U)) + 16101602509895104517U;
            aOrbiterH = ((aWandererC + RotL64(aCross, 13U)) + 9083915270773304935U) + aOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = (aWandererF + RotL64(aScatter, 51U)) + 12810720730318214811U;
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 47U)) + RotL64(aCarry, 11U)) + 18113428002071925621U;
            aOrbiterD = ((((aWandererD + RotL64(aPrevious, 26U)) + RotL64(aCarry, 35U)) + 1582208899354109878U) + aOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordG;
            aOrbiterI = (aWandererG + RotL64(aScatter, 21U)) + 4180688104819188154U;
            aOrbiterG = ((aWandererI + RotL64(aCross, 41U)) + 8954598189262820611U) + aNonceWordP;
            aOrbiterC = ((aWandererB + RotL64(aScatter, 5U)) + RotL64(aCarry, 53U)) + 15360094153175355879U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 8383954114668216260U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 15626783326234049197U) ^ aOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15058420415480073793U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 10609978564404958066U) + aNonceWordN;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 17656516608997517984U;
            aOrbiterJ = RotL64((aOrbiterJ * 4590620354119899777U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 760077259110786536U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 3597338735888033063U) ^ aOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6548831472863517621U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 4431777844935985157U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 10710423172154671296U;
            aOrbiterG = RotL64((aOrbiterG * 16267496318491473315U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 10240882795242085185U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 7826053487019825891U;
            aOrbiterI = RotL64((aOrbiterI * 15053729937684375907U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 9418883403715727353U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 11507423614799075545U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16189463984557044693U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 11545217316421066655U) + aNonceWordL;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 617921402135485341U;
            aOrbiterC = RotL64((aOrbiterC * 8182920764965471653U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 14456933220749921009U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 7990243583564535387U) ^ aNonceWordC;
            aOrbiterK = RotL64((aOrbiterK * 5994900368027985469U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 14023633125757654751U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 11319146808574958827U;
            aOrbiterA = RotL64((aOrbiterA * 13676159969338309307U), 35U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterC, 13U);
            aIngress = aIngress + (RotL64(aOrbiterG, 46U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 53U));
            aIngress = aIngress + (RotL64(aOrbiterH, 19U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterK, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aScatter, 38U) + aOrbiterG) + RotL64(aOrbiterD, 29U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterH, 23U)) + aOrbiterK) + aWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aCross, 3U) + RotL64(aOrbiterH, 14U)) + aOrbiterB) + RotL64(aCarry, 27U)) + aNonceWordB);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 23U) + aOrbiterB) + RotL64(aOrbiterA, 35U)) + aNonceWordH);
            aWandererI = aWandererI + ((RotL64(aCross, 57U) + RotL64(aOrbiterD, 5U)) + aOrbiterA);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 42U) + aOrbiterC) + RotL64(aOrbiterH, 41U)) + aWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 13U) + RotL64(aOrbiterI, 19U)) + aOrbiterD) + RotL64(aCarry, 3U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterG, 53U)) + aOrbiterA) + aNonceWordE);
            aWandererC = aWandererC + ((RotL64(aCross, 27U) + aOrbiterB) + RotL64(aOrbiterJ, 48U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 24U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererF, 53U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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

void TwistExpander_Rugby_Arx::KDF_B_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xD7771C365A59949BULL + 0xC729BC76AAC0D5CAULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xA5235EFEADBC659DULL + 0x8D685A325C6C0BC0ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xEDEE08DB88DA2C27ULL + 0x91ED26378291FF14ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xD026071F8F7FF2D3ULL + 0xA9CC9A1130A49C02ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xB31388B6E90443D9ULL + 0xB29DECCCBECD6678ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x95AA5B95D4CB39FBULL + 0x91095DAC127F08B9ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xF8B1667267F670FDULL + 0xF54FC88A681FDF3AULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xACBF30CB760D2BE7ULL + 0x955D340C328E3C75ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xD1A3A10B72C332B7ULL + 0xA3E45D5BE9B439EBULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xF929BD1B16A24EDBULL + 0x997914F2B8337A9BULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x9C382EEA0F5BAA7DULL + 0xBB653406D8327523ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x8C103A8F52927681ULL + 0xCCEC082494DA9682ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x823EB3230E71D405ULL + 0xD6E02734F0C83D05ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x8E55D2C81EC294B3ULL + 0xF644C70F3E2F6C16ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xD226F64ACF17AECFULL + 0xD010435BA91DC3CFULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xEA2A32D5F8079241ULL + 0xF7F87ADB49CBAD63ULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aFireLaneB, aWorkLaneC, aWorkLaneD, aOperationLaneC, aExpandLaneA, aFireLaneC, aOperationLaneA, aExpandLaneB, aOperationLaneD, aFireLaneA, aExpandLaneC, aFireLaneD, aOperationLaneB
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_d loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aFireLaneB
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aFireLaneB forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aOperationLaneC
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aOperationLaneC backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 999U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((aIndex + 6626U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 2321U)) & S_BLOCK1], 18U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 1246U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 675U)) & S_BLOCK1], 28U));
            aCross ^= RotL64(aOperationLaneC[((aIndex + 2974U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 19U) + RotL64(aPrevious, 40U)) ^ (RotL64(aCarry, 5U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 29U)) + 1898718075389870739U) + aNonceWordH;
            aOrbiterA = ((aWandererI + RotL64(aIngress, 41U)) + RotL64(aCarry, 57U)) + 5631794889237247403U;
            aOrbiterI = (aWandererH + RotL64(aScatter, 3U)) + 18219714659484524607U;
            aOrbiterH = ((aWandererC + RotL64(aCross, 11U)) + RotL64(aCarry, 39U)) + 15419581386225732921U;
            aOrbiterB = (aWandererD + RotL64(aPrevious, 21U)) + 9125575431710198210U;
            aOrbiterE = ((((aWandererE + RotL64(aScatter, 35U)) + RotL64(aCarry, 5U)) + 12205871520544965505U) + aOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordC;
            aOrbiterJ = (((aWandererF + RotL64(aIngress, 48U)) + 7617534300497343422U) + aOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordN;
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 18017579105368135814U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 10693882161946020042U;
            aOrbiterI = RotL64((aOrbiterI * 2326507900303932855U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 11669615701700895306U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 11045110212889232165U;
            aOrbiterB = RotL64((aOrbiterB * 5965171269273719849U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 18019107802806469913U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 12315940560472528716U) ^ aNonceWordO;
            aOrbiterH = RotL64((aOrbiterH * 4505122470351404065U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 4899009736070044310U) + aOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 17412253404253730364U;
            aOrbiterJ = RotL64((aOrbiterJ * 10791901166391946485U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 4826286251927854181U) + aNonceWordP;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 4523455921321845084U;
            aOrbiterF = RotL64((aOrbiterF * 14534103906736598099U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 4132514462154182215U) + aOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 7164745605985109269U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14107325508977225261U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 6297434295807635654U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 8813887638672996646U;
            aOrbiterE = RotL64((aOrbiterE * 17495632530773158201U), 51U);
            //
            aIngress = RotL64(aOrbiterF, 47U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterI, 41U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterH, 14U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aIngress, 21U) + aOrbiterE) + RotL64(aOrbiterF, 3U)) + aNonceWordG);
            aWandererH = aWandererH + ((((RotL64(aCross, 13U) + RotL64(aOrbiterH, 50U)) + aOrbiterE) + aNonceWordI) + aWandererUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((((RotL64(aScatter, 5U) + aOrbiterI) + RotL64(aOrbiterE, 27U)) + aNonceWordJ) + aWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 44U) + RotL64(aOrbiterE, 37U)) + aOrbiterA) + RotL64(aCarry, 35U)) + aNonceWordE);
            aWandererF = aWandererF ^ ((RotL64(aCross, 27U) + aOrbiterA) + RotL64(aOrbiterJ, 57U));
            aWandererC = aWandererC + (((RotL64(aIngress, 35U) + aOrbiterI) + RotL64(aOrbiterH, 13U)) + RotL64(aCarry, 19U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterA, 19U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 43U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 34U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + RotL64(aWandererD, 19U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aFireLaneC
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aFireLaneC forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aOperationLaneA
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aOperationLaneA backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 11602U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneC[((aIndex + 13964U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 14966U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 10989U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 10785U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 16277U)) & S_BLOCK1], 20U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 35U) + RotL64(aPrevious, 52U)) + (RotL64(aCross, 3U) ^ RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterK = (aWandererI + RotL64(aPrevious, 37U)) + 15383045568644941552U;
            aOrbiterB = (((aWandererE + RotL64(aCross, 21U)) + RotL64(aCarry, 53U)) + 17452811657750910067U) + aNonceWordE;
            aOrbiterA = ((((aWandererA + RotL64(aIngress, 27U)) + RotL64(aCarry, 3U)) + 15660117718455155603U) + aOrbiterAssignSaltD[((aIndex + 20U)) & S_SALT1]) + aNonceWordD;
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 4U)) + RotL64(aCarry, 29U)) + 10396441207743665753U;
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 13U)) + 3708971058200841442U) + aOrbiterAssignSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = (aWandererD + RotL64(aIngress, 43U)) + 7000673057768598750U;
            aOrbiterG = (aWandererJ + RotL64(aCross, 51U)) + 9886354469011131596U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 16018065329058043467U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 5024756166109352320U;
            aOrbiterA = RotL64((aOrbiterA * 11660932185479046483U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 6587818720728886652U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 3652672354944162319U;
            aOrbiterE = RotL64((aOrbiterE * 10807121230791716109U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 6307315649915348048U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 16405347331742979258U;
            aOrbiterC = RotL64((aOrbiterC * 7183142442906743699U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 5427299664054601957U) + aOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = (((aOrbiterG ^ aOrbiterB) ^ 4983381733483185898U) ^ aOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterG = RotL64((aOrbiterG * 14646556236306407673U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 10182995521328377487U) + aNonceWordN;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 8694282877540593550U;
            aOrbiterK = RotL64((aOrbiterK * 14614602561910403893U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 4085927978153269932U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 6176195962815240877U;
            aOrbiterB = RotL64((aOrbiterB * 16792916528959579875U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 6966742100601433005U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterA) ^ 9920952446921247521U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterJ = RotL64((aOrbiterJ * 1879821050131820933U), 53U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterB, 23U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 47U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterG, 56U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterK, 48U)) + aOrbiterE);
            aWandererK = aWandererK + ((((RotL64(aCross, 28U) + aOrbiterK) + RotL64(aOrbiterA, 13U)) + RotL64(aCarry, 57U)) + aWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((((RotL64(aScatter, 19U) + RotL64(aOrbiterC, 19U)) + aOrbiterB) + aNonceWordK) + aWandererUpdateSaltC[((aIndex + 14U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterK, 27U)) + aNonceWordF);
            aWandererI = aWandererI ^ (((RotL64(aCross, 35U) + aOrbiterB) + RotL64(aOrbiterE, 41U)) + aNonceWordJ);
            aWandererD = aWandererD + ((((RotL64(aScatter, 43U) + aOrbiterB) + RotL64(aOrbiterK, 57U)) + RotL64(aCarry, 41U)) + aNonceWordA);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterG, 5U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererI);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 60U));
            aCarry = aCarry + RotL64(aWandererF, 11U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 3
        // ingress from: aExpandLaneB, aWorkLaneD, aOperationLaneD
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aOperationLaneD forward/backward random
        // cross from: aExpandLaneA, aWorkLaneB, aFireLaneA
        // cross directions: aExpandLaneA backward forced, aWorkLaneB backward forced, aFireLaneA backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 21724U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneD[((aIndex + 19619U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 21901U)) & S_BLOCK1], 36U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 18571U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 23819U)) & S_BLOCK1], 52U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 17783U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aPrevious, 54U) + RotL64(aCross, 5U)) + (RotL64(aIngress, 39U) ^ RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterF = (aWandererD + RotL64(aScatter, 47U)) + 18144572925667544139U;
            aOrbiterK = (((aWandererG + RotL64(aCross, 21U)) + RotL64(aCarry, 47U)) + 5659758077574059728U) + aNonceWordF;
            aOrbiterD = ((aWandererB + RotL64(aIngress, 3U)) + 6343330616999166392U) + aOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 41U)) + RotL64(aCarry, 29U)) + 17754639838410839447U;
            aOrbiterH = ((aWandererF + RotL64(aCross, 27U)) + 9451843819849581729U) + aNonceWordB;
            aOrbiterA = (aWandererE + RotL64(aPrevious, 53U)) + 7957854457197462212U;
            aOrbiterJ = ((((aWandererH + RotL64(aScatter, 34U)) + RotL64(aCarry, 11U)) + 1461994799722205010U) + aOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1]) + aNonceWordL;
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 18002214276252170177U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 14689869073147027164U) ^ aOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12242482963989582191U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 3978104368003440293U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 8512135845221335386U) ^ aNonceWordN;
            aOrbiterH = RotL64((aOrbiterH * 10506667163729414667U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 1477533446382953439U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 2166717790929947990U;
            aOrbiterJ = RotL64((aOrbiterJ * 6538884492418324461U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 8082437060686606995U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 4363687722464700362U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7199165810993478887U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 15782763348014924206U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 8572509150015960728U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3340528604891897779U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 12248271773316742521U) + aNonceWordO;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 9602078627638561949U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1860631869877427405U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 17244849374768558859U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 1030743048280579012U;
            aOrbiterA = RotL64((aOrbiterA * 10858949914285817051U), 29U);
            //
            aIngress = RotL64(aOrbiterK, 35U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterA, 41U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 23U));
            aIngress = aIngress + RotL64(aOrbiterD, 60U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aIngress, 5U) + aOrbiterF) + RotL64(aOrbiterD, 51U)) + aWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 57U) + aOrbiterK) + RotL64(aOrbiterJ, 57U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 13U) + RotL64(aOrbiterK, 4U)) + aOrbiterD) + aNonceWordD) + aWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 35U) + aOrbiterB) + RotL64(aOrbiterA, 35U));
            aWandererF = aWandererF + (((RotL64(aIngress, 19U) + aOrbiterA) + RotL64(aOrbiterH, 41U)) + RotL64(aCarry, 13U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterF, 27U)) + aOrbiterJ);
            aWandererD = aWandererD + ((((RotL64(aScatter, 28U) + aOrbiterH) + RotL64(aOrbiterJ, 11U)) + RotL64(aCarry, 41U)) + aNonceWordH);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 44U));
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererD, 53U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aFireLaneD
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aFireLaneD forward/backward random
        // cross from: aExpandLaneB, aWorkLaneC, aOperationLaneB
        // cross directions: aExpandLaneB backward forced, aWorkLaneC backward forced, aOperationLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 26381U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneA[((aIndex + 31708U)) & S_BLOCK1], 12U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 31946U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28369U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 27025U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 27977U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCross, 57U)) ^ (RotL64(aCarry, 42U) ^ RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterE = ((aWandererF + RotL64(aIngress, 19U)) + RotL64(aCarry, 41U)) + 3650233661228036955U;
            aOrbiterD = (((aWandererI + RotL64(aPrevious, 5U)) + RotL64(aCarry, 27U)) + 11607036400067735729U) + aNonceWordE;
            aOrbiterG = (aWandererB + RotL64(aScatter, 35U)) + 3899614406903883035U;
            aOrbiterC = (aWandererH + RotL64(aCross, 41U)) + 8159156925629965143U;
            aOrbiterA = (aWandererE + RotL64(aScatter, 47U)) + 7148903913967261270U;
            aOrbiterH = ((((aWandererC + RotL64(aCross, 28U)) + RotL64(aCarry, 11U)) + 9161665622287517848U) + aOrbiterAssignSaltA[((aIndex + 28U)) & S_SALT1]) + aNonceWordL;
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 53U)) + 2981535013474059469U) + aOrbiterAssignSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 15812469008200319549U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 14687469489893270300U) ^ aNonceWordD;
            aOrbiterG = RotL64((aOrbiterG * 14142363399696670451U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 6025209349511417063U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 12964750392311112676U;
            aOrbiterH = RotL64((aOrbiterH * 12955480283032701843U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 6572355895765394340U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 3542300121890027981U;
            aOrbiterC = RotL64((aOrbiterC * 11201491178181273935U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 6477175684045398359U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 1081388388827929314U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8752188637514143529U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 13754328481584620771U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 3684673342659575917U) ^ aNonceWordP;
            aOrbiterJ = RotL64((aOrbiterJ * 6139923312873039143U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 6542045150319909445U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 5352102692424060388U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7385758355501860261U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 9110100774657340354U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 2813273684436269057U) ^ aOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10468759062594022273U), 41U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterJ, 28U);
            aIngress = aIngress + (RotL64(aOrbiterA, 11U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + RotL64(aOrbiterC, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterG, 19U)) + aOrbiterD) + aNonceWordC);
            aWandererB = aWandererB + ((RotL64(aCross, 19U) + RotL64(aOrbiterC, 29U)) + aOrbiterA);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterJ, 3U)) + aOrbiterA) + aNonceWordN);
            aWandererC = aWandererC + (((RotL64(aScatter, 28U) + RotL64(aOrbiterH, 11U)) + aOrbiterJ) + RotL64(aCarry, 41U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 41U) + aOrbiterH) + RotL64(aOrbiterE, 44U)) + aWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            aWandererI = aWandererI + (((((RotL64(aPrevious, 13U) + aOrbiterC) + RotL64(aOrbiterH, 57U)) + RotL64(aCarry, 53U)) + aNonceWordA) + aWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterD, 35U)) + aOrbiterE) + aNonceWordJ);
            //
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 18U));
            aCarry = aCarry + (RotL64(aWandererH, 53U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererE, 11U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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

void TwistExpander_Rugby_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xA80F484DD384DDC9ULL + 0xF8C4EBD525864BE5ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x96629C2F782B1323ULL + 0xCC01DE63F8B0047FULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xFCFAE8FF74F51489ULL + 0x80F5E1607FF3AD90ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xEC9E07C004936F55ULL + 0xE1F228C42B632415ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xB732F4B2F4CB442BULL + 0xE4EC32BEE096C096ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xAFF0EB590D0FDBD7ULL + 0xC71EF3A27965F25CULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xC28DCE59E979F6A3ULL + 0xCA9BC410C7D3B408ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xC7DF276EDE6B8985ULL + 0x949F76E04D7B5F3DULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x8120BE90704C940DULL + 0xDACFAF9355D38E15ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x851A6777C9845B09ULL + 0xD3EEC471990CD0E7ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xA5BAC831AFB61BA7ULL + 0xBF739A631AC7D43DULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x994B8E9D99860FF7ULL + 0xE2387D868702518FULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xCD29E21A5A61EAF3ULL + 0x98F2187FB72578FDULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xCB283719C17A49F9ULL + 0xDD6E2B18D756D864ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xB2ACD670B417B6D5ULL + 0xF3055ECF957BBBDEULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xB66F1331E4204D8FULL + 0x81AF6A3CBDDAEAAFULL);
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 1773U)) & W_KEY1], 19U) ^ RotL64(aKeyRowReadB[((aIndex + 1249U)) & W_KEY1], 27U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 1948U)) & W_KEY1], 3U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 459U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 48U) ^ RotL64(aIngress, 3U)) + (RotL64(aCross, 23U) ^ RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterG = (((aWandererE + RotL64(aPrevious, 3U)) + RotL64(aCarry, 41U)) + 9080426856729228705U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = ((aWandererI + RotL64(aCross, 41U)) + 7851218321653539276U) + aPhaseEOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = (((aWandererK + RotL64(aScatter, 14U)) + RotL64(aCarry, 11U)) + 7023344692919298036U) + aNonceWordK;
            aOrbiterC = ((aWandererG + RotL64(aIngress, 53U)) + 9772846154227440734U) + aNonceWordO;
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 29U)) + 12008298632429608431U) + aNonceWordD;
            aOrbiterH = ((aWandererB + RotL64(aCross, 35U)) + RotL64(aCarry, 23U)) + 12201090455849562875U;
            aOrbiterI = (aWandererA + RotL64(aIngress, 23U)) + 9498721803411445471U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 351203764023093632U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 4966360430644539250U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10138518378274592739U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 9194167899071345693U) + aNonceWordE;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 4922477697284269116U;
            aOrbiterG = RotL64((aOrbiterG * 8444814161720407881U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 15742625291642356429U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 7528703106518431730U;
            aOrbiterI = RotL64((aOrbiterI * 11530049278751507567U), 35U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterB) + 15279053574704935317U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordA;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 2425839793660355555U;
            aOrbiterC = RotL64((aOrbiterC * 11486964816849830667U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 13209849392400008898U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 9041500097716231309U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 340661035700748739U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 7885423750878814599U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 1992993999902904603U;
            aOrbiterJ = RotL64((aOrbiterJ * 1478629826632201617U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 6120758615019314102U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 8529621625846992066U;
            aOrbiterH = RotL64((aOrbiterH * 8485991471612862467U), 5U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterJ, 35U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 21U));
            aIngress = aIngress + (RotL64(aOrbiterI, 51U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterB, 44U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aCross, 19U) + RotL64(aOrbiterH, 13U)) + aOrbiterD) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterJ, 35U)) + aOrbiterB);
            aWandererK = aWandererK + (((RotL64(aPrevious, 29U) + aOrbiterC) + RotL64(aOrbiterI, 41U)) + aNonceWordI);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterH, 19U)) + aOrbiterI) + aNonceWordG);
            aWandererA = aWandererA + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterD, 47U)) + aOrbiterJ) + RotL64(aCarry, 3U)) + aNonceWordF);
            aWandererD = aWandererD ^ ((RotL64(aCross, 52U) + RotL64(aOrbiterI, 57U)) + aOrbiterG);
            aWandererI = aWandererI + (((((RotL64(aPrevious, 13U) + aOrbiterD) + RotL64(aOrbiterG, 6U)) + RotL64(aCarry, 21U)) + aNonceWordP) + aPhaseEWandererUpdateSaltA[((aIndex + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 50U) ^ aWandererK);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + RotL64(aWandererI, 29U);
            aCarry = aCarry + RotL64(aIngress, 56U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 5072U)) & S_BLOCK1], 38U) ^ RotL64(aKeyRowReadA[((aIndex + 5250U)) & W_KEY1], 27U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 4355U)) & W_KEY1], 48U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 2888U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 21U) ^ RotL64(aIngress, 37U)) ^ (RotL64(aCross, 51U) + RotL64(aPrevious, 4U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterE = ((aWandererG + RotL64(aIngress, 35U)) + 17264605017518259932U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = (((aWandererC + RotL64(aPrevious, 47U)) + RotL64(aCarry, 41U)) + 15209184354580778643U) + aNonceWordL;
            aOrbiterJ = ((aWandererD + RotL64(aCross, 41U)) + 3299527965014731384U) + aPhaseEOrbiterAssignSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = (aWandererH + RotL64(aScatter, 23U)) + 16293096431816127821U;
            aOrbiterG = (((aWandererF + RotL64(aCross, 11U)) + RotL64(aCarry, 53U)) + 11031983436878828337U) + aNonceWordH;
            aOrbiterC = ((aWandererE + RotL64(aIngress, 29U)) + RotL64(aCarry, 13U)) + 9188018632448236358U;
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 58U)) + 13420816400363406556U) + aNonceWordN;
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 2485063384097917101U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 3089135816938128264U;
            aOrbiterJ = RotL64((aOrbiterJ * 8813152992957361153U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 10730544971770435788U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 10431767565618874806U) ^ aNonceWordG;
            aOrbiterG = RotL64((aOrbiterG * 4723078464590561545U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 14883796491656899074U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = (((aOrbiterK ^ aOrbiterC) ^ 13465877783538483706U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterK = RotL64((aOrbiterK * 14311686051108108503U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 13322163435314643713U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 3307316600284371955U;
            aOrbiterF = RotL64((aOrbiterF * 12337846092069506365U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 4950101626975919939U) + aNonceWordD;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 2596253994220103666U;
            aOrbiterA = RotL64((aOrbiterA * 7181706961838582889U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 17961706029559914243U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 10321902557977495175U;
            aOrbiterC = RotL64((aOrbiterC * 16189559888625084711U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 18146616411403012772U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 8414050129421955787U) ^ aNonceWordJ;
            aOrbiterE = RotL64((aOrbiterE * 14879448948196182863U), 11U);
            //
            aIngress = RotL64(aOrbiterG, 35U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 13U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 19U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterA, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aPrevious, 11U) + aOrbiterJ) + RotL64(aOrbiterA, 57U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 57U) + aOrbiterF) + RotL64(aOrbiterE, 23U));
            aWandererE = aWandererE + ((((RotL64(aScatter, 19U) + RotL64(aOrbiterA, 39U)) + aOrbiterK) + RotL64(aCarry, 23U)) + aNonceWordM);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 37U) + aOrbiterE) + RotL64(aOrbiterJ, 13U)) + aNonceWordF);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 28U) + RotL64(aOrbiterA, 48U)) + aOrbiterC) + RotL64(aCarry, 41U)) + aNonceWordP);
            aWandererD = aWandererD ^ ((((RotL64(aScatter, 43U) + RotL64(aOrbiterA, 5U)) + aOrbiterF) + aNonceWordO) + aPhaseEWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 3U) + RotL64(aOrbiterK, 29U)) + aOrbiterG) + aPhaseEWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 60U));
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererE);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + RotL64(aWandererG, 19U);
            aCarry = aCarry + RotL64(aIngress, 40U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 7852U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 7230U)) & W_KEY1], 57U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 6938U)) & W_KEY1], 19U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 7660U)) & S_BLOCK1], 58U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 7404U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 26U) + RotL64(aCross, 51U)) + (RotL64(aCarry, 11U) ^ RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterA = ((((aWandererB + RotL64(aScatter, 11U)) + RotL64(aCarry, 29U)) + 9630214189402543339U) + aPhaseEOrbiterAssignSaltE[((aIndex + 20U)) & S_SALT1]) + aNonceWordC;
            aOrbiterC = (aWandererF + RotL64(aCross, 35U)) + 4072576573737526819U;
            aOrbiterE = ((((aWandererI + RotL64(aIngress, 58U)) + RotL64(aCarry, 5U)) + 15994787452709618869U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordD;
            aOrbiterB = (aWandererK + RotL64(aPrevious, 5U)) + 6403240137132259482U;
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 51U)) + 10229266900170507720U) + aNonceWordM;
            aOrbiterJ = (aWandererE + RotL64(aPrevious, 29U)) + 5025294577989748989U;
            aOrbiterI = (((aWandererD + RotL64(aCross, 21U)) + RotL64(aCarry, 43U)) + 16696461238217956883U) + aNonceWordP;
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 9878318855341719119U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 16086635438116177346U) ^ aNonceWordO;
            aOrbiterE = RotL64((aOrbiterE * 5585682357395705671U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 12295437783084203730U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 7681150419912842402U) ^ aNonceWordF;
            aOrbiterA = RotL64((aOrbiterA * 7289497379725191451U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 2639104034287637448U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 12298170009332243573U;
            aOrbiterJ = RotL64((aOrbiterJ * 9397919591171238575U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 3485932317267669626U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 16569551670038752475U) ^ aNonceWordE;
            aOrbiterB = RotL64((aOrbiterB * 8139802826402217631U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 4448490103784103954U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 14510534073046885941U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7777192047386438305U), 19U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterA) + 4286195398675733451U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1]) + aNonceWordA;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 15790355933840266463U;
            aOrbiterC = RotL64((aOrbiterC * 13342257823027075501U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 6362891510370156055U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 15121822034579983174U;
            aOrbiterI = RotL64((aOrbiterI * 7268045994574844937U), 5U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterB, 19U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 5U));
            aIngress = aIngress + (RotL64(aOrbiterC, 29U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterI, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterC, 21U)) + aOrbiterI);
            aWandererF = aWandererF + ((((RotL64(aIngress, 35U) + RotL64(aOrbiterA, 3U)) + aOrbiterE) + RotL64(aCarry, 27U)) + aNonceWordJ);
            aWandererK = aWandererK ^ ((RotL64(aCross, 29U) + aOrbiterB) + RotL64(aOrbiterA, 29U));
            aWandererD = aWandererD + ((((RotL64(aScatter, 5U) + RotL64(aOrbiterF, 43U)) + aOrbiterI) + RotL64(aCarry, 43U)) + aNonceWordK);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 21U) + aOrbiterC) + RotL64(aOrbiterJ, 60U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aScatter, 41U) + RotL64(aOrbiterE, 53U)) + aOrbiterC) + aNonceWordN) + aPhaseEWandererUpdateSaltA[((aIndex + 12U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 48U) + aOrbiterC) + RotL64(aOrbiterA, 37U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 40U));
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 9180U)) & S_BLOCK1], 48U) ^ RotL64(aKeyRowReadB[((aIndex + 9226U)) & W_KEY1], 13U));
            aIngress ^= (RotL64(mSource[((aIndex + 9654U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 8685U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 8452U)) & W_KEY1], 21U) ^ RotL64(aWorkLaneB[((aIndex + 8879U)) & S_BLOCK1], 40U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCarry, 37U) ^ RotL64(aIngress, 57U)) + (RotL64(aPrevious, 23U) + RotL64(aCross, 6U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 19U)) + 4751694786009671052U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = ((aWandererH + RotL64(aIngress, 46U)) + RotL64(aCarry, 3U)) + 16362725160370844224U;
            aOrbiterK = (((aWandererE + RotL64(aCross, 29U)) + RotL64(aCarry, 23U)) + 6360885380915941057U) + aNonceWordD;
            aOrbiterC = ((aWandererK + RotL64(aScatter, 57U)) + RotL64(aCarry, 43U)) + 5154536007972297036U;
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 39U)) + 9362540581874808253U) + aNonceWordJ;
            aOrbiterG = (aWandererG + RotL64(aIngress, 11U)) + 13902493871525612934U;
            aOrbiterB = ((aWandererF + RotL64(aCross, 3U)) + 10208452885367546542U) + aPhaseFOrbiterAssignSaltF[((aIndex + 16U)) & S_SALT1];
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 3117030377279160998U) + aNonceWordF;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 17286247690414027870U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4896931759653832095U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 3930314320040949141U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 7289525252391668404U) ^ aNonceWordI;
            aOrbiterG = RotL64((aOrbiterG * 15452162299105112187U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 3434167955466809185U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 17852573095128575663U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1485660158767033425U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 6137259687928853253U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = (((aOrbiterB ^ aOrbiterD) ^ 13992510605237574698U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterB = RotL64((aOrbiterB * 15346263295995333395U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 6470556523400123474U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 4333255670390099293U;
            aOrbiterC = RotL64((aOrbiterC * 11089933812030082647U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 7700424876430257995U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 16920736951239453071U;
            aOrbiterA = RotL64((aOrbiterA * 8920407493132380497U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 1635071690430295730U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 9966700845966398620U;
            aOrbiterD = RotL64((aOrbiterD * 17210048121896546867U), 21U);
            //
            aIngress = RotL64(aOrbiterD, 37U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 11U));
            aIngress = aIngress + (RotL64(aOrbiterG, 30U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterB, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterD, 5U)) + aOrbiterK) + aNonceWordM);
            aWandererI = aWandererI + ((((RotL64(aIngress, 21U) + RotL64(aOrbiterA, 28U)) + aOrbiterJ) + RotL64(aCarry, 21U)) + aNonceWordK);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterB, 51U)) + aOrbiterD);
            aWandererG = aWandererG + (((((RotL64(aCross, 3U) + aOrbiterD) + RotL64(aOrbiterA, 19U)) + RotL64(aCarry, 3U)) + aNonceWordA) + aPhaseFWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterC, 35U)) + aOrbiterB) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 37U) + aOrbiterJ) + RotL64(aOrbiterB, 41U)) + aNonceWordG);
            aWandererC = aWandererC ^ ((RotL64(aCross, 14U) + RotL64(aOrbiterA, 13U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererC);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 12U));
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererF, 41U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneD[((aIndex + 12609U)) & S_BLOCK1], 30U) ^ RotL64(aKeyRowReadA[((aIndex + 11403U)) & W_KEY1], 41U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 12041U)) & W_KEY1], 53U) ^ RotL64(mSource[((aIndex + 12342U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 11270U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12757U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 12918U)) & S_BLOCK1], 10U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCross, 3U) ^ RotL64(aIngress, 19U)) + (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 34U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterI = ((aWandererE + RotL64(aCross, 47U)) + RotL64(aCarry, 21U)) + 1866656689936219099U;
            aOrbiterC = (aWandererI + RotL64(aPrevious, 18U)) + 2312314528139448289U;
            aOrbiterJ = (((aWandererJ + RotL64(aScatter, 5U)) + 3554037526469185237U) + aPhaseFOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1]) + aNonceWordH;
            aOrbiterK = (aWandererA + RotL64(aIngress, 41U)) + 405707755060974111U;
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 29U)) + RotL64(aCarry, 51U)) + 1862976326004007697U;
            aOrbiterF = ((((aWandererG + RotL64(aScatter, 35U)) + RotL64(aCarry, 39U)) + 12992483065443288263U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordI;
            aOrbiterG = ((aWandererK + RotL64(aIngress, 11U)) + 3793854946371595197U) + aNonceWordG;
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 4244007978867369382U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 10280867500312580308U;
            aOrbiterJ = RotL64((aOrbiterJ * 13729899124177931289U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 472563452959164242U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 12041770406895816553U;
            aOrbiterA = RotL64((aOrbiterA * 17811798500132002631U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 6118634015704900486U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 13637107920449233307U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17712028184714868053U), 47U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterG) + 16673735670669318830U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1]) + aNonceWordD;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 8602681273646630496U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6995213887710749241U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 7683264695930369476U) + aNonceWordC;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 9146674871199188218U;
            aOrbiterG = RotL64((aOrbiterG * 7403427067419261981U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 3012935612827493084U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 1259789268731661945U;
            aOrbiterC = RotL64((aOrbiterC * 2372843620327050137U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 5623690455471160780U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 18355567776031865462U;
            aOrbiterF = RotL64((aOrbiterF * 9553862670107886679U), 41U);
            //
            aIngress = RotL64(aOrbiterC, 57U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 19U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 47U));
            aIngress = aIngress + RotL64(aOrbiterF, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((((RotL64(aPrevious, 51U) + RotL64(aOrbiterJ, 21U)) + aOrbiterI) + aNonceWordM) + aPhaseFWandererUpdateSaltB[((aIndex + 24U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 30U) + aOrbiterG) + RotL64(aOrbiterK, 53U)) + aNonceWordN);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterC, 35U)) + aOrbiterI);
            aWandererI = aWandererI + ((((RotL64(aIngress, 41U) + RotL64(aOrbiterI, 28U)) + aOrbiterF) + RotL64(aCarry, 23U)) + aNonceWordE);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 3U) + aOrbiterC) + RotL64(aOrbiterG, 3U)) + aNonceWordP);
            aWandererK = aWandererK + ((((RotL64(aCross, 11U) + aOrbiterI) + RotL64(aOrbiterK, 47U)) + RotL64(aCarry, 41U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterA, 11U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 36U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 15527U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneC[((aIndex + 15498U)) & S_BLOCK1], 18U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15657U)) & W_KEY1], 21U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 14554U)) & W_KEY1], 3U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 14326U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 14967U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15297U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aPrevious, 51U) + RotL64(aCross, 39U)) ^ (RotL64(aCarry, 5U) + RotL64(aIngress, 20U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterK = (aWandererD + RotL64(aCross, 3U)) + 14214886793361825363U;
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 19U)) + 17267959031078766320U) + aNonceWordP;
            aOrbiterE = (((aWandererE + RotL64(aScatter, 43U)) + RotL64(aCarry, 23U)) + 16436067429484887644U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = (aWandererI + RotL64(aIngress, 60U)) + 9885951769332633820U;
            aOrbiterJ = (((aWandererJ + RotL64(aCross, 27U)) + RotL64(aCarry, 51U)) + 12971711341813893304U) + aNonceWordL;
            aOrbiterF = ((aWandererB + RotL64(aScatter, 37U)) + 199970353398450154U) + aNonceWordJ;
            aOrbiterC = ((((aWandererC + RotL64(aIngress, 51U)) + RotL64(aCarry, 37U)) + 1237341696444162094U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordO;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 7991128854417613360U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = (((aOrbiterE ^ aOrbiterK) ^ 14809029847149045833U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterE = RotL64((aOrbiterE * 5940857360838299105U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 2559509556915775947U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 14336829730147834160U;
            aOrbiterJ = RotL64((aOrbiterJ * 15103242520064900873U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 8853631886733610440U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 13346159398673246914U;
            aOrbiterF = RotL64((aOrbiterF * 13660497151446983393U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 12121095718571872976U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 16239781125815589804U;
            aOrbiterK = RotL64((aOrbiterK * 5157009090454962231U), 19U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterF) + 9051377033794324106U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1]) + aNonceWordI;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 13805815136723461780U;
            aOrbiterC = RotL64((aOrbiterC * 571129481747181357U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 14849157800322754413U) + aNonceWordG;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 18116651528452542634U;
            aOrbiterD = RotL64((aOrbiterD * 3638480428016835537U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 4105057226952948599U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 5911714320560994391U;
            aOrbiterG = RotL64((aOrbiterG * 1796514171654961389U), 41U);
            //
            aIngress = RotL64(aOrbiterJ, 21U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + RotL64(aOrbiterD, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aIngress, 27U) + aOrbiterK) + RotL64(aOrbiterJ, 13U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 20U) + aOrbiterJ) + RotL64(aOrbiterE, 57U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 53U) + aOrbiterC) + RotL64(aOrbiterD, 27U)) + aNonceWordA);
            aWandererB = aWandererB ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterG, 51U)) + aOrbiterC) + aNonceWordM);
            aWandererH = aWandererH + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterK, 35U)) + aOrbiterG) + RotL64(aCarry, 39U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 47U) + aOrbiterF) + RotL64(aOrbiterD, 43U)) + aNonceWordD);
            aWandererI = aWandererI + ((((RotL64(aIngress, 37U) + aOrbiterD) + RotL64(aOrbiterE, 20U)) + RotL64(aCarry, 5U)) + aPhaseFWandererUpdateSaltE[((aIndex + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererD);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 28U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + RotL64(aWandererI, 39U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 17838U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadA[((aIndex + 16918U)) & W_KEY1], 11U));
            aIngress ^= (RotL64(mSource[((aIndex + 18719U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((aIndex + 17971U)) & S_BLOCK1], 44U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 17188U)) & W_KEY1], 3U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 17193U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 16520U)) & S_BLOCK1], 48U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aIngress, 47U) + RotL64(aCross, 35U)) ^ (RotL64(aPrevious, 6U) ^ RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterI = (((aWandererE + RotL64(aPrevious, 3U)) + RotL64(aCarry, 43U)) + 8685374557928800912U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = ((((aWandererF + RotL64(aScatter, 35U)) + RotL64(aCarry, 29U)) + 3482312691892161229U) + aPhaseGOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1]) + aNonceWordD;
            aOrbiterB = (((aWandererB + RotL64(aIngress, 21U)) + RotL64(aCarry, 5U)) + 6948130297389161165U) + aNonceWordL;
            aOrbiterE = ((aWandererG + RotL64(aCross, 41U)) + 5506385663788942690U) + aNonceWordH;
            aOrbiterK = (aWandererH + RotL64(aScatter, 54U)) + 17859982009307397161U;
            aOrbiterA = (aWandererC + RotL64(aIngress, 27U)) + 9178488809207094043U;
            aOrbiterC = ((aWandererK + RotL64(aCross, 11U)) + 1835479501226057169U) + aNonceWordK;
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 5368101733632614939U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 9050459666576835422U;
            aOrbiterB = RotL64((aOrbiterB * 10351719549990259551U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 9042186993119635078U) + aNonceWordE;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 17528342580198295025U) ^ aNonceWordC;
            aOrbiterK = RotL64((aOrbiterK * 14316671546614386775U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 6495418332558436882U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 8834495762667327342U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10783141541937645995U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 4364314196965690905U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 6357485231062120459U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 289429584586504995U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 3321488322626415347U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 10817330671781848737U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15875919466358823335U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 17974092279281611763U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 2871472057292789157U;
            aOrbiterJ = RotL64((aOrbiterJ * 16104199340711015181U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 15187929795092006849U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 13482063681546475923U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14466266308157364963U), 11U);
            //
            aIngress = RotL64(aOrbiterE, 5U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterJ, 44U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterC, 19U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterB, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aScatter, 58U) + aOrbiterK) + RotL64(aOrbiterE, 58U)) + aNonceWordP);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 35U) + aOrbiterA) + RotL64(aOrbiterI, 19U)) + aNonceWordA);
            aWandererB = aWandererB + (((RotL64(aIngress, 13U) + RotL64(aOrbiterK, 39U)) + aOrbiterB) + aNonceWordN);
            aWandererE = aWandererE ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterI, 11U)) + aOrbiterE) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 47U) + RotL64(aOrbiterC, 3U)) + aOrbiterK) + RotL64(aCarry, 51U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterJ, 29U)) + aOrbiterC);
            aWandererK = aWandererK + (((((RotL64(aPrevious, 27U) + aOrbiterE) + RotL64(aOrbiterB, 47U)) + RotL64(aCarry, 37U)) + aNonceWordG) + aPhaseGWandererUpdateSaltD[((aIndex + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 26U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 51U));
            aCarry = aCarry + RotL64(aWandererK, 3U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 20300U)) & S_BLOCK1], 23U) ^ RotL64(mSource[((aIndex + 20052U)) & S_BLOCK1], 14U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 21401U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19909U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 19552U)) & W_KEY1], 48U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 20782U)) & W_KEY1], 19U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 20295U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((aIndex + 21624U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCarry, 5U)) ^ (RotL64(aPrevious, 23U) + RotL64(aCross, 38U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterE = (aWandererH + RotL64(aCross, 29U)) + 12311607308490066301U;
            aOrbiterG = ((aWandererI + RotL64(aIngress, 60U)) + RotL64(aCarry, 27U)) + 13100864684740679846U;
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 19U)) + 13697304189274329704U) + aNonceWordM;
            aOrbiterK = (((aWandererE + RotL64(aScatter, 47U)) + RotL64(aCarry, 5U)) + 9047976902871216732U) + aPhaseGOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 5U)) + 2147897579538537888U) + aNonceWordD;
            aOrbiterJ = (((aWandererD + RotL64(aCross, 41U)) + RotL64(aCarry, 47U)) + 2072444829390996142U) + aNonceWordO;
            aOrbiterA = ((aWandererB + RotL64(aIngress, 53U)) + 2129307836981020908U) + aPhaseGOrbiterAssignSaltD[((aIndex + 8U)) & S_SALT1];
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 10663145333751112064U) + aNonceWordF;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 15019844390503785459U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7442321463110790449U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 5460865577557928142U) + aNonceWordB;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 15806522559993224197U;
            aOrbiterE = RotL64((aOrbiterE * 8722932687972240099U), 19U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterJ) + 6361113778657833389U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1]) + aNonceWordH;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 8306013884615042570U;
            aOrbiterG = RotL64((aOrbiterG * 8234258702656728667U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 4038420580499706912U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 11908091484457158973U;
            aOrbiterA = RotL64((aOrbiterA * 3964111175645156719U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 11133912466611921250U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 2469227904206936928U;
            aOrbiterI = RotL64((aOrbiterI * 2704438771198001599U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 13234017916788297295U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 9061117693840451988U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3637440416741459419U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 12013423690843812324U) + aNonceWordC;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 14371779015144617412U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3359568073302062667U), 11U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterD, 53U);
            aIngress = aIngress + (RotL64(aOrbiterA, 5U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterI, 60U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterK, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aIngress, 19U) + aOrbiterD) + RotL64(aOrbiterJ, 5U)) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 35U) + RotL64(aOrbiterI, 58U)) + aOrbiterE) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterI, 41U)) + aOrbiterG);
            aWandererI = aWandererI + (((RotL64(aPrevious, 60U) + aOrbiterD) + RotL64(aOrbiterA, 11U)) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ ((((RotL64(aScatter, 27U) + aOrbiterI) + RotL64(aOrbiterA, 35U)) + aNonceWordA) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 13U) + aOrbiterJ) + RotL64(aOrbiterI, 21U)) + aNonceWordG);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 5U) + aOrbiterE) + RotL64(aOrbiterK, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 56U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererI);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + RotL64(aWandererB, 37U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 23700U)) & S_BLOCK1], 51U) ^ RotL64(aKeyRowReadA[((aIndex + 22044U)) & W_KEY1], 4U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 23140U)) & W_KEY1], 19U) ^ RotL64(aFireLaneC[((aIndex + 24414U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 24136U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 23962U)) & S_BLOCK1], 21U));
            aCross ^= (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 23262U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneD[((aIndex + 24258U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 35U) + RotL64(aCarry, 57U)) ^ (RotL64(aCross, 22U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterB = (aWandererH + RotL64(aScatter, 51U)) + 9220392006207660113U;
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 3U)) + 11305018553489132882U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = (((aWandererA + RotL64(aIngress, 27U)) + RotL64(aCarry, 29U)) + 5860373868073513684U) + aNonceWordO;
            aOrbiterA = ((((aWandererI + RotL64(aCross, 10U)) + RotL64(aCarry, 41U)) + 12319586170883987589U) + aPhaseGOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1]) + aNonceWordP;
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 57U)) + RotL64(aCarry, 13U)) + 14072333614354649021U;
            aOrbiterE = (aWandererD + RotL64(aCross, 21U)) + 9332158529453194608U;
            aOrbiterC = ((aWandererF + RotL64(aIngress, 39U)) + 3860569321145958686U) + aNonceWordK;
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 8119005668901240093U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 13918259792880333239U;
            aOrbiterJ = RotL64((aOrbiterJ * 5441062406822088853U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 6938856216758228704U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 3960905839118710604U) ^ aNonceWordL;
            aOrbiterK = RotL64((aOrbiterK * 16203746868670689793U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 6043879193734253929U) + aNonceWordH;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 15691425268831319195U;
            aOrbiterC = RotL64((aOrbiterC * 7189195135654636271U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 14912209933584715274U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 16180183395910618923U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3942858974766467849U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 4966642362507707776U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 6962226782462822861U;
            aOrbiterE = RotL64((aOrbiterE * 3647802407741095419U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 12409120845092026295U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 2302946450253872465U;
            aOrbiterB = RotL64((aOrbiterB * 7099576330777297911U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 16118304388937163838U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = (((aOrbiterD ^ aOrbiterK) ^ 15968419034359049422U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterD = RotL64((aOrbiterD * 11736207775827080165U), 23U);
            //
            aIngress = RotL64(aOrbiterJ, 13U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterC, 23U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 35U));
            aIngress = aIngress + RotL64(aOrbiterD, 58U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((((RotL64(aCross, 11U) + RotL64(aOrbiterJ, 13U)) + aOrbiterB) + aNonceWordA) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererH = aWandererH + (((((RotL64(aIngress, 41U) + aOrbiterK) + RotL64(aOrbiterJ, 48U)) + RotL64(aCarry, 5U)) + aNonceWordN) + aPhaseGWandererUpdateSaltE[((aIndex + 10U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterE, 5U)) + aOrbiterJ);
            aWandererF = aWandererF + ((RotL64(aScatter, 58U) + aOrbiterD) + RotL64(aOrbiterJ, 21U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 21U) + aOrbiterC) + RotL64(aOrbiterA, 27U)) + aNonceWordF);
            aWandererG = aWandererG + (((RotL64(aScatter, 3U) + RotL64(aOrbiterJ, 57U)) + aOrbiterC) + RotL64(aCarry, 37U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterB, 41U)) + aOrbiterC) + aNonceWordC);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + (RotL64(aWandererF, 21U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererG, 12U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 26203U)) & S_BLOCK1], 14U) ^ RotL64(aKeyRowReadA[((aIndex + 25921U)) & W_KEY1], 51U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 27114U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 25898U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 26916U)) & W_KEY1], 20U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 26110U)) & S_BLOCK1], 47U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 25343U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 27094U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 3U) + RotL64(aCarry, 53U)) ^ (RotL64(aIngress, 41U) + RotL64(aCross, 28U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterE = (aWandererB + RotL64(aCross, 53U)) + 1393781663398437180U;
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 46U)) + 17414594746688585273U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = (((aWandererF + RotL64(aIngress, 39U)) + RotL64(aCarry, 13U)) + 2823888497053071250U) + aNonceWordF;
            aOrbiterK = (aWandererK + RotL64(aPrevious, 29U)) + 17032631958617884859U;
            aOrbiterI = (aWandererC + RotL64(aIngress, 3U)) + 15222697630461125019U;
            aOrbiterB = ((((aWandererI + RotL64(aScatter, 21U)) + RotL64(aCarry, 47U)) + 15737414920751551780U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordE;
            aOrbiterH = ((aWandererH + RotL64(aCross, 11U)) + RotL64(aCarry, 27U)) + 1357196111055783001U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 5315122321649251691U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 7893744655508595974U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17863000246694319149U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 16721939414324611738U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 3444375866323610848U;
            aOrbiterG = RotL64((aOrbiterG * 10874157227815775661U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 1825716513674511632U) + aNonceWordN;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 15582066843912467318U;
            aOrbiterE = RotL64((aOrbiterE * 12765146555943757373U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 15673590949193923915U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 13887365046280406413U;
            aOrbiterB = RotL64((aOrbiterB * 3169061375011420121U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 12730414371734709356U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 4819112390640821927U) ^ aNonceWordA;
            aOrbiterI = RotL64((aOrbiterI * 8782547948627685451U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 3089925954422937464U) + aNonceWordJ;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 7180179304678622530U;
            aOrbiterK = RotL64((aOrbiterK * 16118051565147747413U), 57U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterB) + 17030269962085008657U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1]) + aNonceWordL;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 6675917351883004046U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14134335325316949687U), 51U);
            //
            aIngress = RotL64(aOrbiterG, 21U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterK, 41U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterE, 35U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterD, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 29U) + aOrbiterH) + RotL64(aOrbiterI, 3U));
            aWandererB = aWandererB + (((((RotL64(aCross, 60U) + RotL64(aOrbiterG, 29U)) + aOrbiterB) + RotL64(aCarry, 19U)) + aNonceWordD) + aPhaseHWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 53U) + aOrbiterG) + RotL64(aOrbiterE, 57U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 13U) + aOrbiterK) + RotL64(aOrbiterI, 35U)) + aNonceWordP);
            aWandererH = aWandererH ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterK, 23U)) + aOrbiterH);
            aWandererI = aWandererI + ((((RotL64(aIngress, 21U) + RotL64(aOrbiterD, 48U)) + aOrbiterB) + RotL64(aCarry, 35U)) + aPhaseHWandererUpdateSaltC[((aIndex + 12U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 41U) + aOrbiterG) + RotL64(aOrbiterK, 41U)) + aNonceWordM);
            //
            aCarry = aCarry + (RotL64(aWandererK, 18U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererB);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + RotL64(aWandererH, 51U);
            aCarry = aCarry + RotL64(aIngress, 34U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 29588U)) & S_BLOCK1], 29U) ^ RotL64(aFireLaneD[((aIndex + 29438U)) & S_BLOCK1], 21U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 28954U)) & W_KEY1], 10U) ^ RotL64(aFireLaneC[((aIndex + 27320U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 28141U)) & W_KEY1], 19U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 29624U)) & S_BLOCK1], 30U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28069U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 28440U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aIngress, 4U) + RotL64(aCross, 19U)) ^ (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 60U)) + RotL64(aCarry, 37U)) + 14157904117287696136U;
            aOrbiterK = (((aWandererD + RotL64(aScatter, 35U)) + 7369512677371640676U) + aPhaseHOrbiterAssignSaltF[((aIndex + 8U)) & S_SALT1]) + aNonceWordF;
            aOrbiterB = ((aWandererB + RotL64(aCross, 29U)) + RotL64(aCarry, 3U)) + 8411250745902073798U;
            aOrbiterH = (aWandererC + RotL64(aIngress, 41U)) + 5002041814539710275U;
            aOrbiterD = (((aWandererG + RotL64(aScatter, 47U)) + RotL64(aCarry, 23U)) + 9538041410816283124U) + aPhaseHOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = (aWandererF + RotL64(aIngress, 21U)) + 5210700103927513061U;
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 53U)) + 7600709399101287982U) + aNonceWordN;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 2366369466696580499U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 5544575244203019109U) ^ aNonceWordB;
            aOrbiterB = RotL64((aOrbiterB * 16231219246786333057U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 8710073749110329779U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 15998211310115361630U) ^ aNonceWordK;
            aOrbiterD = RotL64((aOrbiterD * 15275657696897688955U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 15354357553877376422U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 10657523549259276169U;
            aOrbiterH = RotL64((aOrbiterH * 13695239532898311073U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 10405750198355464768U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 3465819693133515142U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14678343718277562799U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 16724189641701408630U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 3484340153620198872U;
            aOrbiterK = RotL64((aOrbiterK * 17247547677520703125U), 23U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterD) + 7420442404884871126U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordA;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 11138445997256757636U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11167543379937571127U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 1428191560884663125U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 16950093140800653985U;
            aOrbiterI = RotL64((aOrbiterI * 4423012306984814805U), 13U);
            //
            aIngress = RotL64(aOrbiterE, 12U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterH, 41U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 27U));
            aIngress = aIngress + RotL64(aOrbiterK, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterH, 4U)) + aOrbiterK);
            aWandererG = aWandererG + ((RotL64(aCross, 60U) + aOrbiterF) + RotL64(aOrbiterH, 57U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterI, 27U)) + aOrbiterK);
            aWandererK = aWandererK + ((((RotL64(aScatter, 3U) + aOrbiterE) + RotL64(aOrbiterF, 19U)) + RotL64(aCarry, 57U)) + aNonceWordG);
            aWandererH = aWandererH ^ (((RotL64(aCross, 53U) + aOrbiterB) + RotL64(aOrbiterF, 11U)) + aPhaseHWandererUpdateSaltF[((aIndex + 10U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aIngress, 29U) + aOrbiterI) + RotL64(aOrbiterB, 41U)) + RotL64(aCarry, 21U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 13U) + aOrbiterD) + RotL64(aOrbiterF, 47U)) + aNonceWordI);
            //
            aCarry = aCarry + (RotL64(aWandererK, 6U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererG, 21U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 39U));
            aCarry = aCarry + RotL64(aWandererD, 43U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 31015U)) & S_BLOCK1], 53U) ^ RotL64(aKeyRowReadA[((aIndex + 32663U)) & W_KEY1], 5U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 32216U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31480U)) & S_BLOCK1], 5U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32329U)) & S_BLOCK1], 51U) ^ RotL64(aKeyRowReadB[((aIndex + 30177U)) & W_KEY1], 26U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 37U) ^ RotL64(aPrevious, 18U)) ^ (RotL64(aIngress, 3U) + RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterD = ((aWandererH + RotL64(aScatter, 51U)) + 5573188770530340913U) + aNonceWordC;
            aOrbiterG = (((aWandererG + RotL64(aPrevious, 19U)) + RotL64(aCarry, 29U)) + 1431772230889897111U) + aPhaseHOrbiterAssignSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = (((aWandererD + RotL64(aCross, 35U)) + 4809192776429682319U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordD;
            aOrbiterC = (((aWandererI + RotL64(aIngress, 13U)) + RotL64(aCarry, 13U)) + 5576603692574369341U) + aNonceWordO;
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 57U)) + RotL64(aCarry, 57U)) + 2720143226007220386U;
            aOrbiterE = (aWandererF + RotL64(aIngress, 42U)) + 17220328778565331629U;
            aOrbiterA = ((aWandererB + RotL64(aCross, 5U)) + 9629485808442089423U) + aNonceWordN;
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 1136998437010390983U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 11893390497814523841U;
            aOrbiterH = RotL64((aOrbiterH * 5329621622743089531U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 1764986431917532370U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 1741014798007010376U) ^ aNonceWordE;
            aOrbiterJ = RotL64((aOrbiterJ * 13414914086049500731U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 12221368453236547044U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 7694538641172350430U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8439120733670016501U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 17472344518811560603U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 3308740700728172984U;
            aOrbiterG = RotL64((aOrbiterG * 15290400462887712083U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 9535358833412446771U) + aNonceWordH;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 11192312491731312451U;
            aOrbiterA = RotL64((aOrbiterA * 17405609148475445743U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 14850451970047190039U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 11932493299452443256U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7964808728820467795U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 5972619895614731870U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 17174497535809891690U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15471084511364572533U), 19U);
            //
            aIngress = RotL64(aOrbiterG, 29U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 35U));
            aIngress = aIngress + (RotL64(aOrbiterC, 11U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterA, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aCross, 58U) + RotL64(aOrbiterC, 27U)) + aOrbiterG);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 51U) + aOrbiterA) + RotL64(aOrbiterD, 35U));
            aWandererF = aWandererF + (((RotL64(aIngress, 3U) + RotL64(aOrbiterA, 3U)) + aOrbiterE) + aNonceWordK);
            aWandererH = aWandererH ^ ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterE, 19U)) + aOrbiterG) + aNonceWordM) + aPhaseHWandererUpdateSaltC[((aIndex + 18U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aIngress, 11U) + aOrbiterA) + RotL64(aOrbiterH, 13U)) + RotL64(aCarry, 57U)) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 39U) + aOrbiterE) + RotL64(aOrbiterD, 58U));
            aWandererI = aWandererI + (((RotL64(aCross, 19U) + aOrbiterH) + RotL64(aOrbiterJ, 51U)) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 10U));
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 37U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererH, 19U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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

void TwistExpander_Rugby_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x8C62B699DB55E4F9ULL + 0xBDFE7385398EB651ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xF2F7D3983C52CEA1ULL + 0xF019A62F9A75FDD5ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xD426C1DBCDFB063FULL + 0xD28AEFEA5E390F6BULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xFFCE1B2C74EEC0CDULL + 0xE40A8E7FE45AD0BFULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x8D7F20EB6F0DD993ULL + 0xD3BD27D6CA6E9E11ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xE3CBEF81C951C47BULL + 0xE12646B4CAACC636ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xBEB59C0EC71ABCCDULL + 0xE015DDEC87206FBCULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xE7BA5A67956E92C7ULL + 0xDCC48BD465DA3552ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xFD5DBD5A19CCE6E9ULL + 0xA1DA196DAED9E3BFULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xE3659BE3DA46C5C7ULL + 0x8B8ADB30B1E26EBDULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xED780D625A58E4CFULL + 0x85F48B4B21B25C9DULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xFEC97D832FFC507DULL + 0xED742877C554E9B5ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xEA447AFD46483CB9ULL + 0xD24819890F30CC90ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xFC825AE60F8AA28DULL + 0xF960827E912C6890ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xB416ECC3E1EAF869ULL + 0xD52B2AF17231D76FULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xF75D92681B8362DFULL + 0x871B6EDD5165D4F5ULL);
    // GSeedRunSeed_B seed_loop_a (start)
    {
        // GSeedRunSeed_B seed_loop_a lane group
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneC, aExpandLaneC, aExpandLaneD, aInvestLaneA, aFireLaneA, aInvestLaneB, aFireLaneB, aOperationLaneA, aFireLaneD, aOperationLaneB, aOperationLaneC
        // write to: aInvestLaneA, aInvestLaneB, aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // seed_loop_a loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneC
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 862U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneB[((aIndex + 4867U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 3801U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2517U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 2064U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aPrevious, 57U)) ^ (RotL64(aIngress, 37U) + RotL64(aCarry, 6U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterJ = (((aWandererE + RotL64(aCross, 13U)) + RotL64(aCarry, 5U)) + 6771552164800695068U) + aNonceWordK;
            aOrbiterE = (((aWandererK + RotL64(aScatter, 21U)) + 12131763371571322040U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordN;
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 39U)) + 3326182381395522013U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = ((aWandererG + RotL64(aIngress, 47U)) + RotL64(aCarry, 41U)) + 12288775097697156383U;
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 56U)) + RotL64(aCarry, 29U)) + 5195948373449796741U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 14404044002250137144U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 11142382920035825426U;
            aOrbiterD = RotL64((aOrbiterD * 8134413822789107595U), 35U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterG) + 2967149520256475485U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 1470907369577818097U;
            aOrbiterA = RotL64((aOrbiterA * 9398653295177725883U), 11U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterD) + 9231668148004163910U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordL;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 13078929163913892386U;
            aOrbiterG = RotL64((aOrbiterG * 7509829068700523627U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 9485274692075657877U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 12216951187543631673U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6571066246507310805U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 6933334652581744234U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 17260276102423580920U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7796879893790990605U), 3U);
            //
            aIngress = RotL64(aOrbiterJ, 3U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterG, 29U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterA, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aIngress, 29U) + RotL64(aOrbiterD, 47U)) + aOrbiterE) + aNonceWordI) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterE, 5U)) + aOrbiterG) + aNonceWordB);
            aWandererH = aWandererH + ((((RotL64(aScatter, 11U) + aOrbiterA) + RotL64(aOrbiterD, 29U)) + RotL64(aCarry, 5U)) + aNonceWordE);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 54U) + RotL64(aOrbiterE, 60U)) + aOrbiterA) + aNonceWordP);
            aWandererE = aWandererE + ((((RotL64(aCross, 21U) + aOrbiterD) + RotL64(aOrbiterJ, 19U)) + RotL64(aCarry, 43U)) + aPhaseAWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererE, 29U);
            aCarry = aCarry + RotL64(aIngress, 48U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aInvestLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 2
        // ingress from: aInvestLaneA, aExpandLaneC, aFireLaneA
        // ingress directions: aInvestLaneA forward forced, aExpandLaneC forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneA[((aIndex + 10083U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneC[((aIndex + 7278U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 10321U)) & S_BLOCK1], 14U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 6950U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 10221U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 54U) + RotL64(aCarry, 39U)) ^ (RotL64(aCross, 19U) ^ RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterG = ((aWandererA + RotL64(aIngress, 52U)) + RotL64(aCarry, 51U)) + 9914837590440975587U;
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 35U)) + 6706125076401958051U) + aPhaseAOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = ((((aWandererH + RotL64(aScatter, 27U)) + RotL64(aCarry, 21U)) + 16570817772679258409U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordB;
            aOrbiterB = ((aWandererG + RotL64(aCross, 43U)) + RotL64(aCarry, 39U)) + 6843705658115186948U;
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 5U)) + 16099930446791572351U) + aNonceWordO;
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 5420550009556030459U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 5729549069420177477U;
            aOrbiterC = RotL64((aOrbiterC * 7842192631021712569U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 15590601126188675834U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterI) ^ 13044027390998620029U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterJ = RotL64((aOrbiterJ * 16845199115313444123U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 11068338135659636772U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 6584988841809544332U) ^ aNonceWordP;
            aOrbiterG = RotL64((aOrbiterG * 1683336180438945439U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 8516813219883915404U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 10647314042912492785U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15559481057047148785U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 201691689889605304U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 15512161798401184003U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11473219183982564709U), 27U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterB, 27U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 47U));
            aIngress = aIngress + RotL64(aOrbiterC, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aCross, 53U) + RotL64(aOrbiterJ, 36U)) + aOrbiterG) + aPhaseAWandererUpdateSaltE[((aIndex + 14U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 44U) + aOrbiterC) + RotL64(aOrbiterJ, 51U)) + aNonceWordD);
            aWandererB = aWandererB + (((((RotL64(aScatter, 35U) + aOrbiterI) + RotL64(aOrbiterG, 27U)) + RotL64(aCarry, 51U)) + aNonceWordL) + aPhaseAWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterB, 13U)) + aOrbiterC);
            aWandererF = aWandererF + ((((RotL64(aCross, 27U) + aOrbiterB) + RotL64(aOrbiterI, 5U)) + RotL64(aCarry, 39U)) + aNonceWordC);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + RotL64(aWandererG, 29U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 15260U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneD[((aIndex + 13826U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 11918U)) & S_BLOCK1], 28U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 15606U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 15689U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 12113U)) & S_BLOCK1], 34U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aPrevious, 19U) + RotL64(aCarry, 50U)) ^ (RotL64(aIngress, 35U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterD = ((aWandererJ + RotL64(aIngress, 58U)) + 4179952823252098240U) + aNonceWordG;
            aOrbiterG = ((aWandererE + RotL64(aScatter, 5U)) + 3745613452332101749U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = (((aWandererB + RotL64(aPrevious, 21U)) + RotL64(aCarry, 21U)) + 2955689793395307176U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = ((aWandererD + RotL64(aCross, 47U)) + RotL64(aCarry, 37U)) + 5639060180251322019U;
            aOrbiterH = (((aWandererA + RotL64(aScatter, 29U)) + RotL64(aCarry, 51U)) + 7901969163853586463U) + aNonceWordJ;
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 2242166787816318119U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 5239936443960750064U) ^ aNonceWordC;
            aOrbiterA = RotL64((aOrbiterA * 2752853245379816327U), 21U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterD) + 13939136954732185558U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1]) + aNonceWordF;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 17058884136712717463U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7222348891215482977U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 18148618660054585941U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 7022023484530327814U;
            aOrbiterH = RotL64((aOrbiterH * 650100011311048589U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 7722084537340095637U) + aNonceWordI;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 11764151879690934182U;
            aOrbiterJ = RotL64((aOrbiterJ * 12264384877711365655U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 16412785901758144708U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 9666718667728274824U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10865799822751771795U), 3U);
            //
            aIngress = RotL64(aOrbiterJ, 47U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 4U));
            aIngress = aIngress + RotL64(aOrbiterG, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterH, 13U)) + aNonceWordD) + aPhaseAWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererE = aWandererE + (((((RotL64(aIngress, 47U) + RotL64(aOrbiterA, 27U)) + aOrbiterD) + RotL64(aCarry, 5U)) + aNonceWordH) + aPhaseAWandererUpdateSaltF[((aIndex + 14U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterA, 3U)) + aOrbiterH) + aNonceWordA);
            aWandererD = aWandererD + (((RotL64(aScatter, 13U) + aOrbiterD) + RotL64(aOrbiterG, 53U)) + RotL64(aCarry, 19U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 56U) + aOrbiterJ) + RotL64(aOrbiterD, 40U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 21U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 34U));
            aCarry = aCarry + RotL64(aWandererA, 51U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 4
        // ingress from: aOperationLaneA, aInvestLaneA, aFireLaneD
        // ingress directions: aOperationLaneA forward forced, aInvestLaneA forward forced, aFireLaneD forward/backward random
        // cross from: aInvestLaneB, aExpandLaneD, aExpandLaneC
        // cross directions: aInvestLaneB backward forced, aExpandLaneD backward forced, aExpandLaneC backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 19233U)) & S_BLOCK1], 3U) ^ RotL64(aInvestLaneA[((aIndex + 20464U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 16979U)) & S_BLOCK1], 34U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 18586U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16506U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 16562U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aPrevious, 21U) ^ RotL64(aCarry, 51U)) + (RotL64(aCross, 38U) + RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterG = ((((aWandererJ + RotL64(aCross, 42U)) + RotL64(aCarry, 11U)) + 13960289014350612206U) + aPhaseAOrbiterAssignSaltE[((aIndex + 12U)) & S_SALT1]) + aNonceWordA;
            aOrbiterC = ((aWandererA + RotL64(aScatter, 5U)) + 3483331015269589730U) + aNonceWordK;
            aOrbiterB = ((((aWandererI + RotL64(aIngress, 51U)) + RotL64(aCarry, 53U)) + 6873299241002444518U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordM;
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 27U)) + RotL64(aCarry, 41U)) + 3562094007125534229U;
            aOrbiterE = ((aWandererD + RotL64(aScatter, 13U)) + 11422367439932782705U) + aNonceWordE;
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 532453428514259816U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 17810941465810193088U;
            aOrbiterB = RotL64((aOrbiterB * 2830829128884590275U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 11869759058631106331U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterC) ^ 8837581071876177566U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterA = RotL64((aOrbiterA * 15329827515970522213U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 17185378327053837778U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 7578253375676981500U;
            aOrbiterG = RotL64((aOrbiterG * 13371647568758721729U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 17112646434432814442U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 14949096407295697881U;
            aOrbiterC = RotL64((aOrbiterC * 14770977858283051753U), 21U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterA) + 4259590620758467836U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1]) + aNonceWordG;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 6534899413644542303U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7987609419215568661U), 3U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterG, 3U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 41U));
            aIngress = aIngress + RotL64(aOrbiterA, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((((RotL64(aScatter, 58U) + aOrbiterA) + RotL64(aOrbiterE, 36U)) + aNonceWordO) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 43U) + RotL64(aOrbiterC, 3U)) + aOrbiterG) + RotL64(aCarry, 35U)) + aNonceWordF);
            aWandererF = aWandererF ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterC, 13U)) + aOrbiterB) + aNonceWordH);
            aWandererJ = aWandererJ + (((((RotL64(aIngress, 3U) + aOrbiterG) + RotL64(aOrbiterE, 51U)) + RotL64(aCarry, 51U)) + aNonceWordL) + aPhaseAWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 21U) + aOrbiterB) + RotL64(aOrbiterE, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererI);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + RotL64(aWandererF, 57U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 26468U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneA[((aIndex + 25591U)) & S_BLOCK1], 54U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25966U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 22649U)) & S_BLOCK1], 21U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 24775U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 25857U)) & S_BLOCK1], 54U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCross, 6U) + RotL64(aPrevious, 21U)) ^ (RotL64(aCarry, 41U) ^ RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterH = ((aWandererJ + RotL64(aCross, 51U)) + 3550722402315312207U) + aNonceWordK;
            aOrbiterE = ((((aWandererB + RotL64(aPrevious, 3U)) + RotL64(aCarry, 35U)) + 16724184551669522754U) + aPhaseAOrbiterAssignSaltD[((aIndex + 4U)) & S_SALT1]) + aNonceWordC;
            aOrbiterI = ((((aWandererI + RotL64(aScatter, 38U)) + RotL64(aCarry, 47U)) + 981751330116773021U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordN;
            aOrbiterD = (((aWandererK + RotL64(aIngress, 11U)) + RotL64(aCarry, 19U)) + 7891159229704944868U) + aNonceWordM;
            aOrbiterF = (aWandererA + RotL64(aScatter, 19U)) + 13618396711464799841U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 5969291018449003648U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 14595540413313640042U;
            aOrbiterI = RotL64((aOrbiterI * 8151104319012840963U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 3287990436916111762U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 12534369400200483704U) ^ aNonceWordH;
            aOrbiterF = RotL64((aOrbiterF * 2345945228434740707U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 2277312067930392274U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 10026320559261334353U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11020464940995912637U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 11258082063135659551U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 1445958517675746990U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10062265337488757971U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 1011298251290970844U) + aNonceWordF;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 6487834862470043744U;
            aOrbiterE = RotL64((aOrbiterE * 15477913837027179675U), 3U);
            //
            aIngress = RotL64(aOrbiterF, 4U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + RotL64(aOrbiterD, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((((RotL64(aPrevious, 11U) + RotL64(aOrbiterE, 47U)) + aOrbiterH) + RotL64(aCarry, 51U)) + aNonceWordI) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterD, 21U)) + aOrbiterF) + aNonceWordB);
            aWandererI = aWandererI + (((RotL64(aCross, 43U) + RotL64(aOrbiterH, 56U)) + aOrbiterD) + RotL64(aCarry, 13U));
            aWandererA = aWandererA ^ ((((RotL64(aScatter, 28U) + aOrbiterD) + RotL64(aOrbiterI, 3U)) + aNonceWordP) + aPhaseAWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 57U) + aOrbiterI) + RotL64(aOrbiterF, 11U)) + aNonceWordG);
            //
            aCarry = aCarry + (RotL64(aWandererB, 5U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererI, 24U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 31524U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneA[((aIndex + 31395U)) & S_BLOCK1], 4U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28163U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28873U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 28151U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 28863U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCarry, 34U)) ^ (RotL64(aCross, 21U) + RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterG = (aWandererD + RotL64(aScatter, 19U)) + 16124889768301047791U;
            aOrbiterE = ((aWandererK + RotL64(aIngress, 38U)) + 11912338587186717280U) + aNonceWordJ;
            aOrbiterK = ((((aWandererC + RotL64(aCross, 47U)) + RotL64(aCarry, 53U)) + 8594012868813114354U) + aPhaseAOrbiterAssignSaltC[((aIndex + 26U)) & S_SALT1]) + aNonceWordN;
            aOrbiterC = ((((aWandererG + RotL64(aPrevious, 11U)) + RotL64(aCarry, 41U)) + 18281043566156682815U) + aPhaseAOrbiterAssignSaltF[((aIndex + 11U)) & S_SALT1]) + aNonceWordP;
            aOrbiterD = (((aWandererA + RotL64(aScatter, 57U)) + RotL64(aCarry, 5U)) + 16853106130200942302U) + aNonceWordD;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 2611212958619673086U) + aNonceWordA;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 18039472325066855180U) ^ aNonceWordF;
            aOrbiterK = RotL64((aOrbiterK * 10213999643376367785U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 14495785571345122046U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 4556063793412832418U) ^ aNonceWordM;
            aOrbiterG = RotL64((aOrbiterG * 13166927543135467627U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 14896419970271244358U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 880028529183500036U;
            aOrbiterE = RotL64((aOrbiterE * 14228281807461251361U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 2379557167489415783U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 11854373946064529806U;
            aOrbiterC = RotL64((aOrbiterC * 150755294320438887U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 1487252775956449964U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 12777924204511625545U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1366019527386994789U), 51U);
            //
            aIngress = RotL64(aOrbiterD, 36U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterC, 23U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aIngress, 48U) + RotL64(aOrbiterE, 41U)) + aOrbiterC) + aNonceWordE) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 19U) + aOrbiterG) + RotL64(aOrbiterK, 53U)) + aNonceWordC);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterK, 13U)) + aOrbiterD) + RotL64(aCarry, 39U)) + aPhaseAWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 39U) + aOrbiterC) + RotL64(aOrbiterG, 4U));
            aWandererA = aWandererA + ((((RotL64(aIngress, 5U) + aOrbiterC) + RotL64(aOrbiterK, 21U)) + RotL64(aCarry, 3U)) + aNonceWordB);
            //
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererG);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + RotL64(aWandererA, 54U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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

void TwistExpander_Rugby_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xF073FBFCCDE12E59ULL + 0xA86A49A682C9B63DULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xF08287DE57C61FE5ULL + 0xA41DE87716A4496CULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xF47D4B01300F3F99ULL + 0xC7CE27CB1580336FULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xC8004C961BB839ADULL + 0x94370A0E6A9E1807ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x91693E3351815E15ULL + 0xF5D20AD16DB40E62ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xB9D86A774EDADF01ULL + 0xB2FD12E24121E09CULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xCCC7D06EF7F87B8FULL + 0xB151BEA1EEBEDA2DULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xC3C55B8411716823ULL + 0x8D0A9695EBB64450ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xE1818FB61E73AF81ULL + 0xBA3933F18DB0C934ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x8665FB5FDB38799BULL + 0xEA9F54886141BA0CULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x9B545677A8C516EFULL + 0x8ABED2A09F0E89E0ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xA2321A850EC91B37ULL + 0x89E47F5D0DF89471ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xDE9E365E3A6A43CFULL + 0xAB82A4A6334B242CULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xDFC6E4AB0D344BD9ULL + 0x92AC56873E382AEDULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xC7E9C24E6555EBEDULL + 0xB684A64C4D337EFEULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x9E57E335039654ABULL + 0xB9A90ED984D8D853ULL);
    // GSeedRunSeed_C seed_loop_b (start)
    {
        // GSeedRunSeed_C seed_loop_b lane group
        // read from: aOperationLaneA, aOperationLaneB, aExpandLaneA, aOperationLaneC, aOperationLaneD, aFireLaneB, aInvestLaneC, aFireLaneC, aFireLaneD, aInvestLaneD, aExpandLaneC, aWorkLaneA, aFireLaneA, aWorkLaneB, aExpandLaneB, aWorkLaneC, aExpandLaneD
        // write to: aInvestLaneC, aInvestLaneD, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // seed_loop_b loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aExpandLaneA
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aExpandLaneA forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aFireLaneB
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aFireLaneB backward/forward random
        // write to: aInvestLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 3761U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneB[((aIndex + 2055U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 3813U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4849U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 4418U)) & S_BLOCK1], 40U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 999U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 27U) ^ RotL64(aIngress, 39U)) ^ (RotL64(aCarry, 13U) + RotL64(aPrevious, 52U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterD = (aWandererC + RotL64(aCross, 35U)) + 5573188770530340913U;
            aOrbiterI = (((aWandererJ + RotL64(aIngress, 23U)) + RotL64(aCarry, 41U)) + 1431772230889897111U) + aNonceWordI;
            aOrbiterJ = (aWandererK + RotL64(aScatter, 28U)) + 4809192776429682319U;
            aOrbiterE = (aWandererA + RotL64(aPrevious, 11U)) + 5576603692574369341U;
            aOrbiterF = (aWandererI + RotL64(aIngress, 39U)) + 2720143226007220386U;
            aOrbiterG = ((aWandererE + RotL64(aCross, 53U)) + 17220328778565331629U) + aNonceWordK;
            aOrbiterA = (((aWandererD + RotL64(aScatter, 48U)) + RotL64(aCarry, 29U)) + 9629485808442089423U) + aPhaseBOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 43U)) + RotL64(aCarry, 51U)) + 1136998437010390983U;
            aOrbiterH = ((aWandererH + RotL64(aCross, 19U)) + 11893390497814523841U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 1764986431917532370U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 1741014798007010376U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13414914086049500731U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 12221368453236547044U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 7694538641172350430U) ^ aNonceWordL;
            aOrbiterD = RotL64((aOrbiterD * 8439120733670016501U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 17472344518811560603U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 3308740700728172984U;
            aOrbiterI = RotL64((aOrbiterI * 15290400462887712083U), 19U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterE) + 9535358833412446771U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordN;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 11192312491731312451U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17405609148475445743U), 37U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterH) + 14850451970047190039U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordP;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 11932493299452443256U;
            aOrbiterE = RotL64((aOrbiterE * 7964808728820467795U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 5972619895614731870U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 17174497535809891690U) ^ aNonceWordC;
            aOrbiterH = RotL64((aOrbiterH * 15471084511364572533U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 17412894714378898351U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 14675615208706549810U;
            aOrbiterG = RotL64((aOrbiterG * 7864845089606499769U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 16116792108013658523U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 9702262005960966336U;
            aOrbiterF = RotL64((aOrbiterF * 970452849653781703U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 17337264966818542841U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 7004462033775827275U;
            aOrbiterC = RotL64((aOrbiterC * 11943575980344402681U), 41U);
            //
            aIngress = RotL64(aOrbiterE, 43U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + (RotL64(aOrbiterH, 56U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterD, 35U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterJ, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aScatter, 5U) + aOrbiterH) + RotL64(aOrbiterI, 43U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 51U) + aOrbiterE) + RotL64(aOrbiterJ, 23U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterA, 19U)) + aOrbiterI);
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 23U) + RotL64(aOrbiterG, 48U)) + aOrbiterI) + aNonceWordA) + aPhaseBWandererUpdateSaltA[((aIndex + 10U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 18U) + RotL64(aOrbiterC, 3U)) + aOrbiterE) + RotL64(aCarry, 3U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterF, 39U)) + aOrbiterI) + aNonceWordJ);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 57U) + aOrbiterH) + RotL64(aOrbiterC, 53U)) + RotL64(aCarry, 19U)) + aNonceWordF);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterG, 12U)) + aOrbiterD) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 12U) + RotL64(aOrbiterC, 29U)) + aOrbiterI) + aNonceWordD);
            //
            aCarry = aCarry + (RotL64(aWandererA, 13U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererF);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 20U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 37U));
            aCarry = aCarry + RotL64(aWandererJ, 41U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aInvestLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 2
        // ingress from: aInvestLaneC, aOperationLaneC, aOperationLaneD, aFireLaneC
        // ingress directions: aInvestLaneC forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aFireLaneD
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aFireLaneD backward/forward random
        // write to: aInvestLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneC[((aIndex + 6413U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneC[((aIndex + 6881U)) & S_BLOCK1], 57U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 6349U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneC[((aIndex + 7816U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 10770U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 10163U)) & S_BLOCK1], 20U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 6029U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 47U) ^ RotL64(aCarry, 35U)) ^ (RotL64(aCross, 6U) + RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterI = ((aWandererA + RotL64(aScatter, 51U)) + 9023059520606551446U) + aNonceWordE;
            aOrbiterB = (aWandererJ + RotL64(aIngress, 4U)) + 662441755115638133U;
            aOrbiterG = (aWandererE + RotL64(aCross, 19U)) + 16957253361196144712U;
            aOrbiterH = (aWandererC + RotL64(aPrevious, 41U)) + 7840955025765308605U;
            aOrbiterK = (((aWandererF + RotL64(aIngress, 35U)) + RotL64(aCarry, 11U)) + 346855809270395799U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterF = (aWandererK + RotL64(aPrevious, 47U)) + 16099139781586668343U;
            aOrbiterA = ((aWandererB + RotL64(aScatter, 29U)) + RotL64(aCarry, 27U)) + 3706457327118322098U;
            aOrbiterC = ((aWandererG + RotL64(aCross, 57U)) + RotL64(aCarry, 35U)) + 12166825885547622870U;
            aOrbiterJ = (((aWandererH + RotL64(aPrevious, 24U)) + 7792658665720344200U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordG;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 7128477606152986326U) + aNonceWordL;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 11116533962780290084U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11993485572912492297U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 10443889548568288532U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 4402387036946561017U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9032964741841833277U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 13002706161178447654U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 13929727277530310708U;
            aOrbiterA = RotL64((aOrbiterA * 7005639090871200285U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 10949073760696935106U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 15405923432006783533U) ^ aNonceWordM;
            aOrbiterH = RotL64((aOrbiterH * 17989565878445202495U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 18096057968822208905U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 3032155040484574973U;
            aOrbiterJ = RotL64((aOrbiterJ * 448597307502544605U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 17462076466907467134U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 15471015427013701406U;
            aOrbiterI = RotL64((aOrbiterI * 6113474000571976139U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 3549031751266594344U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 14243218483842508113U;
            aOrbiterC = RotL64((aOrbiterC * 9041601306479302047U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 5803147589312920032U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterC) ^ 5549470512227427855U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterF = RotL64((aOrbiterF * 12592362489263862879U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 10076661824293832189U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 3196799148974716550U;
            aOrbiterB = RotL64((aOrbiterB * 8183276968961467775U), 19U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterC, 29U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 51U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 60U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 23U));
            aIngress = aIngress + RotL64(aOrbiterI, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterB, 13U)) + aOrbiterI) + aNonceWordJ);
            aWandererC = aWandererC + (((RotL64(aPrevious, 53U) + aOrbiterI) + RotL64(aOrbiterK, 3U)) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 44U) + RotL64(aOrbiterF, 47U)) + aOrbiterB) + aNonceWordO);
            aWandererF = aWandererF + (((RotL64(aCross, 19U) + RotL64(aOrbiterG, 57U)) + aOrbiterK) + RotL64(aCarry, 35U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 11U) + aOrbiterC) + RotL64(aOrbiterK, 22U)) + aPhaseBWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 5U) + aOrbiterJ) + RotL64(aOrbiterA, 41U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterA, 37U)) + aOrbiterI);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 60U) + RotL64(aOrbiterH, 51U)) + aOrbiterI) + aNonceWordD) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterA, 18U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (RotL64(aWandererE, 37U) ^ aWandererH);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 41U));
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 44U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aInvestLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_b loop 3
        // ingress from: aInvestLaneD, aOperationLaneA, aExpandLaneC
        // ingress directions: aInvestLaneD forward forced, aOperationLaneA forward forced, aExpandLaneC forward/backward random
        // cross from: aInvestLaneC, aOperationLaneC
        // cross directions: aInvestLaneC backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneD[((aIndex + 15676U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneA[((aIndex + 11721U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15666U)) & S_BLOCK1], 10U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 12405U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneC[((aIndex + 14082U)) & S_BLOCK1], 42U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCross, 41U) + RotL64(aPrevious, 58U)) ^ (RotL64(aIngress, 29U) ^ RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterB = (((aWandererI + RotL64(aScatter, 51U)) + RotL64(aCarry, 41U)) + 15316464782468770057U) + aNonceWordO;
            aOrbiterI = ((aWandererA + RotL64(aIngress, 19U)) + RotL64(aCarry, 11U)) + 6642872057476351588U;
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 11U)) + RotL64(aCarry, 53U)) + 660732654689529192U;
            aOrbiterG = ((aWandererF + RotL64(aCross, 4U)) + 7235418086884000655U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterH = (aWandererJ + RotL64(aScatter, 57U)) + 14784518476694580493U;
            aOrbiterJ = (aWandererB + RotL64(aIngress, 39U)) + 12222433977933449375U;
            aOrbiterK = ((aWandererK + RotL64(aCross, 23U)) + 8573001207708329927U) + aNonceWordM;
            aOrbiterE = (((aWandererG + RotL64(aPrevious, 28U)) + 16035256260815013172U) + aPhaseBOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1]) + aNonceWordB;
            aOrbiterA = ((aWandererC + RotL64(aScatter, 47U)) + 15767726974121910203U) + aNonceWordA;
            //
            aOrbiterB = (((aOrbiterB + aOrbiterI) + 17712217935322939971U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordG;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 13488963456923357159U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16785285630840310405U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 10222949131965611079U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 1495561412321657209U;
            aOrbiterB = RotL64((aOrbiterB * 9706305581868526265U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 16156530750584361434U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 7773792489045606309U;
            aOrbiterG = RotL64((aOrbiterG * 10730624207715601393U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 11544578291333360613U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 3665587867634242865U;
            aOrbiterK = RotL64((aOrbiterK * 4840528190844842595U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 15248434984650998090U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = (((aOrbiterH ^ aOrbiterJ) ^ 15487979645426567581U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterH = RotL64((aOrbiterH * 10868107809356766183U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 6972347795052712690U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 16074994810010431338U;
            aOrbiterI = RotL64((aOrbiterI * 1262655238856775853U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 16851139687900415292U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 14630026837021552812U;
            aOrbiterJ = RotL64((aOrbiterJ * 9577900853521254603U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 14236330619137368169U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 17778707026111136216U;
            aOrbiterA = RotL64((aOrbiterA * 16239561893843454747U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 9390961969105999083U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 1174881758316573228U;
            aOrbiterE = RotL64((aOrbiterE * 6602061268277529311U), 3U);
            //
            aIngress = RotL64(aOrbiterB, 11U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 39U));
            aIngress = aIngress + (RotL64(aOrbiterI, 54U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterG, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aIngress, 51U) + aOrbiterE) + RotL64(aOrbiterB, 34U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 41U) + aOrbiterK) + RotL64(aOrbiterJ, 39U));
            aWandererF = aWandererF + ((RotL64(aCross, 14U) + RotL64(aOrbiterF, 3U)) + aOrbiterK);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 5U) + aOrbiterG) + RotL64(aOrbiterI, 11U)) + aNonceWordH);
            aWandererI = aWandererI + ((((RotL64(aScatter, 37U) + RotL64(aOrbiterF, 23U)) + aOrbiterB) + RotL64(aCarry, 43U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 57U) + aOrbiterA) + RotL64(aOrbiterH, 48U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 27U) + aOrbiterJ) + RotL64(aOrbiterA, 43U)) + RotL64(aCarry, 29U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterJ, 27U)) + aOrbiterG) + aPhaseBWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 18U) + RotL64(aOrbiterA, 57U)) + aOrbiterK) + aNonceWordK);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererK, 10U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 35U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 4
        // ingress from: aWorkLaneA, aInvestLaneC, aFireLaneA
        // ingress directions: aWorkLaneA forward forced, aInvestLaneC forward forced, aFireLaneA forward/backward random
        // cross from: aInvestLaneD, aOperationLaneD
        // cross directions: aInvestLaneD backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 18499U)) & S_BLOCK1], 21U) ^ RotL64(aInvestLaneC[((aIndex + 19688U)) & S_BLOCK1], 54U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 20645U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 18159U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 20486U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCross, 39U)) ^ (RotL64(aCarry, 19U) ^ RotL64(aIngress, 6U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterD = ((aWandererE + RotL64(aScatter, 39U)) + RotL64(aCarry, 47U)) + 4970414922752555648U;
            aOrbiterE = (aWandererJ + RotL64(aCross, 35U)) + 9462756592787669327U;
            aOrbiterC = (((aWandererB + RotL64(aIngress, 50U)) + RotL64(aCarry, 13U)) + 3948790686662213095U) + aNonceWordN;
            aOrbiterB = (aWandererC + RotL64(aPrevious, 19U)) + 14542857212241578311U;
            aOrbiterG = ((aWandererK + RotL64(aCross, 13U)) + RotL64(aCarry, 27U)) + 3387479009827029547U;
            aOrbiterA = (aWandererH + RotL64(aPrevious, 3U)) + 1411421370057797877U;
            aOrbiterK = (aWandererG + RotL64(aIngress, 43U)) + 16894451466895681236U;
            aOrbiterH = (((aWandererF + RotL64(aScatter, 58U)) + 12727136462290223542U) + aPhaseBOrbiterAssignSaltF[((aIndex + 11U)) & S_SALT1]) + aNonceWordI;
            aOrbiterI = ((aWandererD + RotL64(aIngress, 27U)) + 4625389198191960525U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 3471881403786164913U) + aNonceWordE;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 6433115856048534831U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9363233870194144053U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 9825592965466157982U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 1553125767261293088U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 411535191177308781U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 9951616357109647617U) + aNonceWordA;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 11231080382787286889U;
            aOrbiterG = RotL64((aOrbiterG * 14024961994986659187U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 13419663264017317947U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 4835055642466215566U;
            aOrbiterB = RotL64((aOrbiterB * 17898065852351759171U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 14558747666410946768U) + aNonceWordJ;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 13120938960926874504U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5681766019285559739U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 11910501376797343986U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 15074100100781785300U;
            aOrbiterI = RotL64((aOrbiterI * 228976960937473851U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 12415377930578091821U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 14882039078390681802U;
            aOrbiterH = RotL64((aOrbiterH * 13855446647753150713U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 8094338361713756895U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 5478280604704108822U;
            aOrbiterE = RotL64((aOrbiterE * 18062931724700600993U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 6977017654546871841U) + aNonceWordG;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 4131602217285988962U;
            aOrbiterK = RotL64((aOrbiterK * 11865422227883712419U), 51U);
            //
            aIngress = RotL64(aOrbiterI, 57U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterG, 19U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 46U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 27U));
            aIngress = aIngress + RotL64(aOrbiterE, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aScatter, 4U) + aOrbiterB) + RotL64(aOrbiterC, 46U)) + RotL64(aCarry, 13U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterC, 3U)) + aOrbiterI);
            aWandererK = aWandererK + (((RotL64(aCross, 47U) + aOrbiterD) + RotL64(aOrbiterE, 41U)) + aPhaseBWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterH, 21U)) + aOrbiterG) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aScatter, 10U) + RotL64(aOrbiterH, 57U)) + aOrbiterC);
            aWandererE = aWandererE ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterI, 51U)) + aOrbiterE) + aNonceWordB);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterC, 27U)) + aOrbiterG) + RotL64(aCarry, 41U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterK, 37U)) + aOrbiterE) + aNonceWordK);
            aWandererH = aWandererH + ((RotL64(aScatter, 27U) + RotL64(aOrbiterA, 12U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 50U));
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererH, 19U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_b loop 5
        // ingress from: aWorkLaneB, aInvestLaneD, aExpandLaneB
        // ingress directions: aWorkLaneB forward forced, aInvestLaneD forward forced, aExpandLaneB forward/backward random
        // cross from: aWorkLaneA, aInvestLaneC
        // cross directions: aWorkLaneA backward forced, aInvestLaneC backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 26594U)) & S_BLOCK1], 39U) ^ RotL64(aInvestLaneD[((aIndex + 26365U)) & S_BLOCK1], 4U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 24749U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22040U)) & S_BLOCK1], 23U) ^ RotL64(aInvestLaneC[((aIndex + 26253U)) & S_BLOCK1], 48U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 43U) + RotL64(aIngress, 27U)) ^ (RotL64(aPrevious, 56U) + RotL64(aCross, 13U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterA = ((aWandererK + RotL64(aIngress, 39U)) + 12980104182836602177U) + aPhaseBOrbiterAssignSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = ((aWandererG + RotL64(aScatter, 52U)) + 3172622203188863995U) + aNonceWordH;
            aOrbiterF = ((aWandererD + RotL64(aCross, 11U)) + RotL64(aCarry, 13U)) + 1170974132219980203U;
            aOrbiterI = (aWandererH + RotL64(aPrevious, 47U)) + 6035201940965047490U;
            aOrbiterG = ((aWandererC + RotL64(aScatter, 43U)) + RotL64(aCarry, 35U)) + 18033907118424996722U;
            aOrbiterH = (aWandererE + RotL64(aCross, 27U)) + 14604813424800580304U;
            aOrbiterC = (((aWandererJ + RotL64(aIngress, 56U)) + RotL64(aCarry, 23U)) + 13720232492851066035U) + aNonceWordE;
            aOrbiterB = (aWandererF + RotL64(aPrevious, 35U)) + 3902659710585257448U;
            aOrbiterE = ((aWandererI + RotL64(aScatter, 5U)) + 8331560652661619868U) + aPhaseBOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1];
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 4485014147538689794U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 168202636924512424U;
            aOrbiterF = RotL64((aOrbiterF * 13711020666131492091U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 16227825670092707848U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 4792781933944671365U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15859849676231455283U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 12636865372722601282U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 18198291399585556632U) ^ aNonceWordN;
            aOrbiterG = RotL64((aOrbiterG * 18155803890313399795U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 3650053185419807206U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 5897288963905408776U;
            aOrbiterD = RotL64((aOrbiterD * 3706949366974086151U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 9922308113622901726U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 13352279749091561510U;
            aOrbiterE = RotL64((aOrbiterE * 4025213180483632557U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 14969461950939646117U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 10231661776135056651U;
            aOrbiterB = RotL64((aOrbiterB * 11284575051455238501U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 10621934544068320859U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 6029116920305246887U;
            aOrbiterI = RotL64((aOrbiterI * 6087523725059376905U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 12887482425168671195U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterG) ^ 8351351557123783853U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterA = RotL64((aOrbiterA * 3839381627914762245U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 5405938210926464973U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 385145802287899406U) ^ aNonceWordG;
            aOrbiterC = RotL64((aOrbiterC * 8330751480464271445U), 53U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterA, 40U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 43U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 35U));
            aIngress = aIngress + RotL64(aOrbiterE, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 13U) + aOrbiterB) + RotL64(aOrbiterI, 60U));
            aWandererE = aWandererE + (((RotL64(aCross, 23U) + aOrbiterC) + RotL64(aOrbiterE, 13U)) + RotL64(aCarry, 57U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 18U) + RotL64(aOrbiterC, 5U)) + aOrbiterD) + aNonceWordK);
            aWandererK = aWandererK + ((((RotL64(aScatter, 43U) + aOrbiterH) + RotL64(aOrbiterA, 27U)) + aNonceWordB) + aPhaseBWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 5U) + aOrbiterE) + RotL64(aOrbiterB, 19U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterC, 39U)) + aOrbiterG) + RotL64(aCarry, 19U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterF, 51U)) + aOrbiterG) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 57U) + RotL64(aOrbiterH, 35U)) + aOrbiterC);
            aWandererC = aWandererC ^ (((RotL64(aCross, 34U) + RotL64(aOrbiterD, 44U)) + aOrbiterG) + aNonceWordD);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 39U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 28U));
            aCarry = aCarry + RotL64(aWandererE, 51U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 6
        // ingress from: aWorkLaneC, aWorkLaneA, aExpandLaneD
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aExpandLaneD forward/backward random
        // cross from: aWorkLaneB, aOperationLaneB
        // cross directions: aWorkLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 30827U)) & S_BLOCK1], 44U) ^ RotL64(aWorkLaneA[((aIndex + 30359U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aExpandLaneD[((aIndex + 30975U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30690U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30090U)) & S_BLOCK1], 10U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 51U) + RotL64(aPrevious, 11U)) ^ (RotL64(aIngress, 38U) + RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterF = (aWandererF + RotL64(aCross, 11U)) + 6361545377408870615U;
            aOrbiterH = (aWandererH + RotL64(aScatter, 24U)) + 2967245486744774933U;
            aOrbiterK = ((aWandererB + RotL64(aIngress, 53U)) + 3836634268482850139U) + aNonceWordF;
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 29U)) + 7691642115360086297U) + aPhaseBOrbiterAssignSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = (aWandererA + RotL64(aScatter, 43U)) + 16479280384178279281U;
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 20U)) + 2901468732552539249U) + aNonceWordB;
            aOrbiterE = ((aWandererJ + RotL64(aCross, 3U)) + RotL64(aCarry, 23U)) + 2600353867755647475U;
            aOrbiterJ = (((aWandererK + RotL64(aIngress, 57U)) + RotL64(aCarry, 35U)) + 5666596904781510956U) + aNonceWordN;
            aOrbiterC = ((((aWandererE + RotL64(aPrevious, 39U)) + RotL64(aCarry, 3U)) + 16108791609267427553U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordL;
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 8389926875737312112U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 1689501721163024426U;
            aOrbiterK = RotL64((aOrbiterK * 6517194895779049139U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 11721701506949917719U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 3963842745030140473U;
            aOrbiterB = RotL64((aOrbiterB * 6692473494944919373U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 8510538243472109368U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 18281865214102080387U) ^ aNonceWordG;
            aOrbiterE = RotL64((aOrbiterE * 1351546966368884609U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 2259725140963665123U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 11652011949557979650U;
            aOrbiterD = RotL64((aOrbiterD * 11260100762113295037U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 1116085424226174473U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 4725260319270802912U) ^ aNonceWordP;
            aOrbiterA = RotL64((aOrbiterA * 4697109059565450269U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 7348945429843437036U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 1249234309180653260U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3136745255820405881U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 12463505532573389603U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 2304125977906510386U;
            aOrbiterF = RotL64((aOrbiterF * 9960816714791454421U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 2178037443783425551U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 11712110130079307683U;
            aOrbiterC = RotL64((aOrbiterC * 9797864956200779505U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 10703510612147312252U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 18155460326242413483U;
            aOrbiterH = RotL64((aOrbiterH * 6903953708987478723U), 37U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterD, 28U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 51U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 23U));
            aIngress = aIngress + (RotL64(aOrbiterE, 41U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 27U) + RotL64(aOrbiterK, 23U)) + aOrbiterB) + aNonceWordJ);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 34U) + RotL64(aOrbiterD, 51U)) + aOrbiterJ);
            aWandererB = aWandererB + ((((RotL64(aCross, 23U) + aOrbiterA) + RotL64(aOrbiterH, 19U)) + RotL64(aCarry, 13U)) + aNonceWordE);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 13U) + aOrbiterC) + RotL64(aOrbiterE, 60U)) + aPhaseBWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 39U) + RotL64(aOrbiterC, 39U)) + aOrbiterF);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 5U) + aOrbiterD) + RotL64(aOrbiterB, 13U)) + aNonceWordA);
            aWandererE = aWandererE + (((RotL64(aCross, 56U) + RotL64(aOrbiterB, 27U)) + aOrbiterE) + aNonceWordH);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterC, 56U)) + aOrbiterB) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterA, 3U)) + aOrbiterE) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 12U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 19U));
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererD, 3U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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

void TwistExpander_Rugby_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xCC29503B1651F6F1ULL + 0xB290D96BAD121111ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xF44425F2F2AA0E07ULL + 0xAA9D2EF4D0453DFDULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xDE663DA0E0C3D44DULL + 0xA1E0FD5F8D577D17ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xA39C5BFCEA9D4C0FULL + 0xFCF04E3D4C0A4C6EULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xC5CFD58252B27C51ULL + 0xA20B79D8749D5AC3ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xB0F5EEEE20C78AF9ULL + 0x98EAD14FEF76CCB5ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xE67DBE55C296C147ULL + 0xDCFB34B04C50DC6FULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xD5E2E8E186F1C49FULL + 0xB272EAF47501D5E6ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x9E6B0E610A307F43ULL + 0xE1AE6C76B7E0BDDFULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xA0E726E5D494530BULL + 0xC0377DC7561D6627ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x884356FCC7CADC37ULL + 0x8D9888EDEEFC7B1DULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xDB26318E11C95387ULL + 0xFCFCCACCE208FC21ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xE4FC3535C71C5DD9ULL + 0xDD3025FE36E4797EULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x85391C45AECFFD4FULL + 0x8839677FAA5083C6ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x8CDBE0C727F93C77ULL + 0xEBC8F37F405C55B2ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xC9316843B92EE553ULL + 0xD8671505394E8ADEULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 3078U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneB[((aIndex + 1077U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 1331U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2871U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 4568U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 566U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 29U) ^ RotL64(aPrevious, 41U)) + (RotL64(aCarry, 56U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterJ = (((aWandererG + RotL64(aScatter, 36U)) + 1457104756581596530U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordL;
            aOrbiterC = (((aWandererE + RotL64(aPrevious, 21U)) + 6127240317844622874U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordB;
            aOrbiterD = ((aWandererD + RotL64(aCross, 3U)) + RotL64(aCarry, 3U)) + 16492290056044189421U;
            aOrbiterH = (aWandererB + RotL64(aIngress, 43U)) + 10963676850938416468U;
            aOrbiterE = (aWandererK + RotL64(aCross, 13U)) + 4872917367399752405U;
            aOrbiterI = ((aWandererA + RotL64(aScatter, 57U)) + RotL64(aCarry, 53U)) + 15218882377875616148U;
            aOrbiterA = (((aWandererJ + RotL64(aIngress, 29U)) + RotL64(aCarry, 29U)) + 5934166612122118251U) + aNonceWordK;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 14215280930872003003U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = (((aOrbiterD ^ aOrbiterJ) ^ 11428034799044600979U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterD = RotL64((aOrbiterD * 12162528943733976177U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 5453003654321728726U) + aNonceWordD;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 14273775120265649389U;
            aOrbiterC = RotL64((aOrbiterC * 5139018128323795309U), 35U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterD) + 328723770018440271U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordM;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 13032190719588211088U;
            aOrbiterI = RotL64((aOrbiterI * 13363368478932798315U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 2386881543033598494U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 1649501123340887116U;
            aOrbiterE = RotL64((aOrbiterE * 11148976582360499033U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 16462401546754210583U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 1510579201823042227U;
            aOrbiterJ = RotL64((aOrbiterJ * 16287912400104043275U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 6889066000014251983U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 11324594596597724357U;
            aOrbiterA = RotL64((aOrbiterA * 15344987814648586023U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 12237796033168436537U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 17306069670330000343U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3167451351403385259U), 11U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterE, 11U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + RotL64(aOrbiterI, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aCross, 29U) + RotL64(aOrbiterE, 58U)) + aOrbiterH);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 37U) + aOrbiterH) + RotL64(aOrbiterC, 21U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 22U) + aOrbiterI) + RotL64(aOrbiterA, 41U)) + aNonceWordF);
            aWandererD = aWandererD ^ ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterI, 35U)) + aOrbiterJ) + aNonceWordO) + aPhaseDWandererUpdateSaltB[((aIndex + 22U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 5U) + aOrbiterH) + RotL64(aOrbiterI, 3U)) + RotL64(aCarry, 27U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterD, 47U)) + aOrbiterH) + aPhaseDWandererUpdateSaltD[((aIndex + 8U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterA, 29U)) + aOrbiterC) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 6U) ^ aWandererA);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + (RotL64(aWandererB, 37U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererK, 41U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 9287U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneC[((aIndex + 7948U)) & S_BLOCK1], 27U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 6022U)) & S_BLOCK1], 3U) ^ RotL64(aInvestLaneC[((aIndex + 9544U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 6643U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 7184U)) & S_BLOCK1], 4U));
            aCross ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 8975U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 10U) + RotL64(aCross, 37U)) ^ (RotL64(aCarry, 51U) + RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 27U)) + RotL64(aCarry, 39U)) + 1952750591494698524U;
            aOrbiterB = (aWandererH + RotL64(aIngress, 3U)) + 4488270851303332830U;
            aOrbiterD = ((aWandererC + RotL64(aCross, 47U)) + 2738763375328927635U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = (((aWandererG + RotL64(aScatter, 41U)) + RotL64(aCarry, 27U)) + 6728843649480454340U) + aNonceWordB;
            aOrbiterK = ((aWandererD + RotL64(aCross, 18U)) + 10490717875258865358U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 35U)) + 1429288737812910205U) + aNonceWordJ;
            aOrbiterE = ((aWandererA + RotL64(aIngress, 53U)) + RotL64(aCarry, 57U)) + 2761375016998907636U;
            //
            aOrbiterH = (((aOrbiterH + aOrbiterB) + 1088988605204499835U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1]) + aNonceWordN;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 6829840407300289709U;
            aOrbiterD = RotL64((aOrbiterD * 13101432880030791787U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 9267240337867690471U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 8120113021183975703U;
            aOrbiterK = RotL64((aOrbiterK * 14296504593187173107U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 1340980511302566784U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 11874452169979878835U;
            aOrbiterF = RotL64((aOrbiterF * 8638486178860092537U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 1872314794140971426U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 6013952618696225751U;
            aOrbiterE = RotL64((aOrbiterE * 7994863587373565715U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 3644011378086236002U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 8501867691997891731U;
            aOrbiterH = RotL64((aOrbiterH * 7115282675461711509U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 2493546555198066143U) + aNonceWordL;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 5179240189571799179U) ^ aNonceWordK;
            aOrbiterB = RotL64((aOrbiterB * 1267579130962756135U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 11273348247858394197U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 4577476419423118925U) ^ aNonceWordP;
            aOrbiterA = RotL64((aOrbiterA * 8427261005061162673U), 53U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterE, 5U);
            aIngress = aIngress + (RotL64(aOrbiterH, 47U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 27U));
            aIngress = aIngress + RotL64(aOrbiterK, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterB, 38U)) + aOrbiterA);
            aWandererH = aWandererH + (((RotL64(aCross, 13U) + aOrbiterF) + RotL64(aOrbiterD, 11U)) + RotL64(aCarry, 51U));
            aWandererI = aWandererI ^ ((((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 27U)) + aOrbiterE) + aNonceWordO) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 35U) + RotL64(aOrbiterF, 47U)) + aOrbiterB) + RotL64(aCarry, 27U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 28U) + RotL64(aOrbiterE, 57U)) + aOrbiterA) + aNonceWordF);
            aWandererC = aWandererC + ((RotL64(aIngress, 53U) + aOrbiterH) + RotL64(aOrbiterD, 5U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterA, 19U)) + aOrbiterK) + aPhaseDWandererUpdateSaltC[((aIndex + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 51U));
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererA);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + RotL64(aWandererF, 6U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 15819U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneA[((aIndex + 13889U)) & S_BLOCK1], 30U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 14181U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 16334U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15620U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 11U) + RotL64(aCross, 41U)) ^ (RotL64(aCarry, 24U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 51U)) + RotL64(aCarry, 27U)) + 17711946802293254150U;
            aOrbiterH = (((aWandererJ + RotL64(aCross, 41U)) + RotL64(aCarry, 13U)) + 16652362590489569378U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = ((aWandererK + RotL64(aScatter, 19U)) + 6972810344198183097U) + aNonceWordM;
            aOrbiterK = ((aWandererC + RotL64(aIngress, 11U)) + 13117100889782940546U) + aNonceWordN;
            aOrbiterE = ((aWandererG + RotL64(aScatter, 3U)) + RotL64(aCarry, 51U)) + 13199305696782626591U;
            aOrbiterI = (((aWandererF + RotL64(aIngress, 28U)) + 992156184392760945U) + aPhaseDOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1]) + aNonceWordO;
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 57U)) + 13791265442074543880U) + aNonceWordI;
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 17057087245252294859U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 13444195995883541046U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13067044288608808777U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 6723678233676059420U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 7913379431208430475U;
            aOrbiterK = RotL64((aOrbiterK * 2295062944289127123U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 4481887195529300665U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 11892724101424384078U) ^ aNonceWordP;
            aOrbiterD = RotL64((aOrbiterD * 3468639499716604111U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 7700902083270424194U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterI) ^ 1888001433557140271U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterH = RotL64((aOrbiterH * 8975562955027025349U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 14996753906788986929U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 939004845422123765U;
            aOrbiterF = RotL64((aOrbiterF * 2507090308972292313U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 11922230289291941807U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 15681187459741147199U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10124947739653819101U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 9119043713532718155U) + aNonceWordG;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 8327697433992362166U;
            aOrbiterI = RotL64((aOrbiterI * 11157657162184304567U), 37U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterH, 11U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 41U));
            aIngress = aIngress + (RotL64(aOrbiterI, 60U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterF, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aCross, 58U) + RotL64(aOrbiterE, 54U)) + aOrbiterI) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 27U) + aOrbiterK) + RotL64(aOrbiterH, 11U)) + aPhaseDWandererUpdateSaltA[((aIndex + 26U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aIngress, 39U) + RotL64(aOrbiterB, 41U)) + aOrbiterF) + RotL64(aCarry, 41U)) + aNonceWordJ);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 19U) + aOrbiterD) + RotL64(aOrbiterE, 27U)) + aNonceWordD);
            aWandererG = aWandererG + (((RotL64(aIngress, 47U) + aOrbiterB) + RotL64(aOrbiterH, 35U)) + aPhaseDWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 5U) + aOrbiterF) + RotL64(aOrbiterK, 5U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 13U) + RotL64(aOrbiterI, 19U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererC, 38U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererJ, 43U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 17029U)) & S_BLOCK1], 27U) ^ RotL64(aSnowLaneA[((aIndex + 16540U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 20079U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 19847U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneD[((aIndex + 16386U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCarry, 27U) ^ RotL64(aPrevious, 6U)) + (RotL64(aIngress, 39U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterE = ((aWandererH + RotL64(aScatter, 11U)) + RotL64(aCarry, 47U)) + 1557680213571812384U;
            aOrbiterG = (((aWandererI + RotL64(aCross, 5U)) + RotL64(aCarry, 21U)) + 7387349725778021121U) + aNonceWordB;
            aOrbiterF = (((aWandererK + RotL64(aPrevious, 23U)) + 15379264067601586976U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordI;
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 60U)) + 3730195724576043708U) + aNonceWordF;
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 43U)) + 9637070085323827066U) + aNonceWordO;
            aOrbiterA = ((aWandererC + RotL64(aIngress, 37U)) + RotL64(aCarry, 3U)) + 1170865717363676184U;
            aOrbiterI = ((aWandererA + RotL64(aScatter, 51U)) + 2750833653175252030U) + aPhaseDOrbiterAssignSaltF[((aIndex + 8U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 15118992811225568305U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 4974092922102988451U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10575977398702460975U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 10625719096296719514U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 855167122475471865U;
            aOrbiterA = RotL64((aOrbiterA * 7441090331293158773U), 11U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterF) + 11322911068958340262U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordH;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 4334591909425429835U;
            aOrbiterH = RotL64((aOrbiterH * 10059025861172038183U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 14263701737208936392U) + aNonceWordN;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 678723206735649084U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10823239851733632227U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 15652053114252065230U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 1705225940224061401U;
            aOrbiterG = RotL64((aOrbiterG * 3626023093533713579U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 6826394665732900206U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 11902946775066981141U) ^ aNonceWordC;
            aOrbiterD = RotL64((aOrbiterD * 18300629262162694137U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 9802212958998591310U) + aNonceWordL;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 14001358545610206524U;
            aOrbiterE = RotL64((aOrbiterE * 13172645840788327099U), 5U);
            //
            aIngress = RotL64(aOrbiterH, 29U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + (RotL64(aOrbiterD, 18U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterG, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aIngress, 56U) + RotL64(aOrbiterH, 3U)) + aOrbiterF) + aNonceWordE);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterH, 13U)) + aOrbiterI) + aNonceWordK);
            aWandererC = aWandererC + ((RotL64(aScatter, 5U) + aOrbiterG) + RotL64(aOrbiterE, 53U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 27U) + aOrbiterE) + RotL64(aOrbiterA, 47U)) + aNonceWordD);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 19U) + aOrbiterE) + RotL64(aOrbiterI, 41U)) + RotL64(aCarry, 13U)) + aNonceWordG);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 43U) + aOrbiterH) + RotL64(aOrbiterG, 27U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aIngress, 35U) + RotL64(aOrbiterI, 60U)) + aOrbiterD) + RotL64(aCarry, 39U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 48U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererJ, 23U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 23682U)) & S_BLOCK1], 39U) ^ RotL64(aSnowLaneB[((aIndex + 23068U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 26318U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 25498U)) & S_BLOCK1], 12U) ^ RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 22361U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aIngress, 20U) + RotL64(aCross, 53U)) + (RotL64(aCarry, 3U) ^ RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterK = ((((aWandererC + RotL64(aScatter, 5U)) + RotL64(aCarry, 35U)) + 11700815697312060726U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterG = ((aWandererK + RotL64(aCross, 43U)) + 11808423452327465441U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = (aWandererB + RotL64(aIngress, 37U)) + 8670503858631730886U;
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 12U)) + 2400061067991988544U) + aNonceWordF;
            aOrbiterC = (aWandererJ + RotL64(aCross, 27U)) + 16163118178366229686U;
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 53U)) + RotL64(aCarry, 19U)) + 3280178595904941068U;
            aOrbiterA = ((aWandererF + RotL64(aIngress, 19U)) + RotL64(aCarry, 47U)) + 3298683600817047727U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 16321624053445183574U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 6730229877611375225U;
            aOrbiterH = RotL64((aOrbiterH * 2022290495153519279U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 10162830636713641322U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 15646771327759599256U) ^ aNonceWordN;
            aOrbiterK = RotL64((aOrbiterK * 15333053762177144775U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 14841751262270544102U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 9545541117228834895U;
            aOrbiterF = RotL64((aOrbiterF * 11529769874752969377U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 14676615635857599982U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterH) ^ 1231768638470558855U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterA = RotL64((aOrbiterA * 2716808508509014677U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 1945905595345404833U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 1406171421638586846U;
            aOrbiterB = RotL64((aOrbiterB * 4577864352425476233U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 1970292335806697198U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 12309719390375013297U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16540660957923687327U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 5352135521358954576U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 15465675376193501658U;
            aOrbiterC = RotL64((aOrbiterC * 16385761112921041387U), 27U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterA, 29U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 37U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 53U));
            aIngress = aIngress + RotL64(aOrbiterH, 60U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterK, 11U)) + aOrbiterF) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 3U) + RotL64(aOrbiterC, 19U)) + aOrbiterG) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 58U) + RotL64(aOrbiterA, 27U)) + aOrbiterH) + aNonceWordB);
            aWandererA = aWandererA + (((RotL64(aPrevious, 11U) + aOrbiterC) + RotL64(aOrbiterB, 41U)) + aNonceWordC);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterF, 5U)) + aOrbiterA);
            aWandererF = aWandererF + (((RotL64(aCross, 27U) + aOrbiterH) + RotL64(aOrbiterB, 58U)) + RotL64(aCarry, 21U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterK, 47U)) + aOrbiterG) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 52U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 5U));
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererJ, 23U);
            aCarry = aCarry + RotL64(aIngress, 42U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 31152U)) & S_BLOCK1], 36U) ^ RotL64(aInvestLaneA[((aIndex + 29294U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 27552U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 27849U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneB[((aIndex + 29103U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 47U) + RotL64(aIngress, 6U)) + (RotL64(aCross, 23U) ^ RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterD = ((aWandererB + RotL64(aScatter, 13U)) + 4752759164691497960U) + aNonceWordP;
            aOrbiterI = (aWandererG + RotL64(aIngress, 57U)) + 12088872623537639782U;
            aOrbiterB = ((((aWandererJ + RotL64(aCross, 41U)) + RotL64(aCarry, 19U)) + 3734943577379734227U) + aPhaseDOrbiterAssignSaltA[((aIndex + 4U)) & S_SALT1]) + aNonceWordN;
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 21U)) + 8854778183012444234U) + aNonceWordL;
            aOrbiterA = (aWandererC + RotL64(aScatter, 35U)) + 16948373492893967275U;
            aOrbiterE = (((aWandererE + RotL64(aIngress, 48U)) + RotL64(aCarry, 41U)) + 7962415690046184385U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterH = (((aWandererH + RotL64(aPrevious, 3U)) + RotL64(aCarry, 57U)) + 1872682375669714454U) + aNonceWordD;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 7776801806943853566U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 16665439117257230732U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6866375628213114965U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 11088186766134265676U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 10850237991780969350U) ^ aNonceWordA;
            aOrbiterA = RotL64((aOrbiterA * 7547414856143095121U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 6464817712131305812U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 244557182884209844U;
            aOrbiterI = RotL64((aOrbiterI * 2394270354887582889U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 13261563971157415841U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 2323811103717827362U) ^ aNonceWordE;
            aOrbiterE = RotL64((aOrbiterE * 11483723582415081925U), 57U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterB) + 12338803568475493422U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1]) + aNonceWordG;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 2811342930111104982U;
            aOrbiterJ = RotL64((aOrbiterJ * 5020981755203607757U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 5554497011738996057U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 12712169745460598698U;
            aOrbiterH = RotL64((aOrbiterH * 1985586486150377769U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 17415058661427002973U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 9430421222715343818U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10321140659099470811U), 13U);
            //
            aIngress = RotL64(aOrbiterH, 53U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterB, 47U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 5U));
            aIngress = aIngress + RotL64(aOrbiterD, 60U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 57U) + aOrbiterA) + RotL64(aOrbiterI, 53U));
            aWandererH = aWandererH + (((((RotL64(aCross, 11U) + RotL64(aOrbiterE, 13U)) + aOrbiterB) + RotL64(aCarry, 35U)) + aNonceWordI) + aPhaseDWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 37U) + aOrbiterD) + RotL64(aOrbiterB, 60U)) + aNonceWordO);
            aWandererK = aWandererK + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterH, 21U)) + aOrbiterI) + aPhaseDWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterJ, 3U)) + aOrbiterD) + aNonceWordB);
            aWandererC = aWandererC + (((RotL64(aPrevious, 4U) + RotL64(aOrbiterD, 27U)) + aOrbiterA) + RotL64(aCarry, 13U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterE, 43U)) + aOrbiterI) + aNonceWordK);
            //
            aCarry = aCarry + (RotL64(aWandererG, 34U) ^ aWandererB);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + RotL64(aWandererK, 53U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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

void TwistExpander_Rugby_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x94582AA07627A649ULL + 0xA2464272D948C1A5ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x9DCF2EC6097B187FULL + 0xDDD5CB570B0C18A1ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x85AA2F8565968F59ULL + 0xD4EBF385D7E9CD29ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xEC2B60E2D8F141CFULL + 0xDDF0356AFA55B46FULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x84AB46856525B45FULL + 0xEF6D1504638D5698ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xDF500AC8B86E57A9ULL + 0x93171BB50F1F189FULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x917D567CE24F5867ULL + 0xC59FFC9F42F1AA20ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x9301FEAE920F6F8BULL + 0xBB962473FCE45743ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xDE2217C264AAE3F9ULL + 0xBDA66DD15CAF5434ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xDD047A9BE430EF6DULL + 0xFE1C26BE84B9C061ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x9B7193B5D2ABCB63ULL + 0xAC4883D194E0F7E4ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xC184737E1C4465C3ULL + 0x885CB5A85DE554D4ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xAE53E638763D9369ULL + 0x977A6030D6EA0DC3ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xAA8F4E5D0511AD3FULL + 0xA409057560C73FDFULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xDC4063968DB08D45ULL + 0xD523F13D4BCE9A1AULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xDE64D05E45055919ULL + 0xBF713FA0CED7D176ULL);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 713U)) & S_BLOCK1], 56U) ^ RotL64(aInvestLaneB[((aIndex + 5179U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 1186U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 5455U)) & S_BLOCK1], 23U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 3519U)) & S_BLOCK1], 42U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 5204U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aIngress, 43U)) ^ (RotL64(aCross, 6U) + RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterG = (aWandererD + RotL64(aIngress, 39U)) + 9751314027302668907U;
            aOrbiterA = (aWandererI + RotL64(aCross, 19U)) + 12175450995523107056U;
            aOrbiterF = (aWandererA + RotL64(aPrevious, 57U)) + 17519694958730119552U;
            aOrbiterI = (aWandererH + RotL64(aScatter, 27U)) + 9093525527925682263U;
            aOrbiterB = ((aWandererB + RotL64(aCross, 3U)) + RotL64(aCarry, 53U)) + 3713831321786810138U;
            aOrbiterC = (aWandererK + RotL64(aIngress, 46U)) + 10108355209191835040U;
            aOrbiterH = ((((aWandererE + RotL64(aScatter, 51U)) + RotL64(aCarry, 47U)) + 12956307447311314768U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordP;
            aOrbiterD = (((aWandererG + RotL64(aPrevious, 13U)) + RotL64(aCarry, 29U)) + 1904298513945877359U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = (aWandererJ + RotL64(aCross, 29U)) + 4658049993308574460U;
            aOrbiterE = ((aWandererC + RotL64(aScatter, 60U)) + 9826333658248851902U) + aNonceWordF;
            aOrbiterK = (aWandererF + RotL64(aPrevious, 53U)) + 12058666914724365134U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 2516574707110528099U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 13335308331049750235U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5880227828760598587U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 8230749255538495304U) + aNonceWordB;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 16536559486797811486U;
            aOrbiterC = RotL64((aOrbiterC * 7097036838156464969U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 12387639130570188998U) + aNonceWordK;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 8459259798142872020U;
            aOrbiterH = RotL64((aOrbiterH * 8001346480955847013U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 16083784052002800300U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 1957284290736468379U;
            aOrbiterG = RotL64((aOrbiterG * 5046501301740813065U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 7349538179311335863U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 16395170077006105258U;
            aOrbiterD = RotL64((aOrbiterD * 4230485452156662763U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 3317652065873784068U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 5517155804799120700U;
            aOrbiterI = RotL64((aOrbiterI * 9789270651974719183U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 5568525912112200094U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 9334250662962319598U) ^ aNonceWordN;
            aOrbiterA = RotL64((aOrbiterA * 5034887614541768961U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 5641394627075994165U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 13524971148931512745U) ^ aNonceWordG;
            aOrbiterB = RotL64((aOrbiterB * 3699457147759854357U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 15124425790244392471U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 7896294947517723306U;
            aOrbiterJ = RotL64((aOrbiterJ * 7526632360108129915U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 15241686066829586263U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 12099799118961857495U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10456171163074630861U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 17529688916595727188U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 9751314027302668907U;
            aOrbiterE = RotL64((aOrbiterE * 521888849578281715U), 35U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterD, 24U);
            aIngress = aIngress + (RotL64(aOrbiterA, 5U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterB, 39U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 21U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 27U));
            aIngress = aIngress + RotL64(aOrbiterI, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterG, 13U)) + aOrbiterF) + RotL64(aCarry, 43U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 53U) + aOrbiterD) + RotL64(aOrbiterG, 37U));
            aWandererG = aWandererG + ((((RotL64(aCross, 3U) + RotL64(aOrbiterB, 54U)) + aOrbiterK) + RotL64(aCarry, 37U)) + aNonceWordL);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterD, 51U)) + aOrbiterA);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterE, 35U)) + aOrbiterH);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 60U) + RotL64(aOrbiterI, 23U)) + aOrbiterH);
            aWandererD = aWandererD + ((RotL64(aCross, 47U) + aOrbiterI) + RotL64(aOrbiterJ, 3U));
            aWandererF = aWandererF ^ ((((RotL64(aScatter, 21U) + aOrbiterE) + RotL64(aOrbiterK, 41U)) + aNonceWordJ) + aPhaseEWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aIngress, 37U) + RotL64(aOrbiterC, 21U)) + aOrbiterD);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 44U) + RotL64(aOrbiterE, 43U)) + aOrbiterA) + aPhaseEWandererUpdateSaltD[((aIndex + 10U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 19U) + aOrbiterH) + RotL64(aOrbiterC, 28U)) + aNonceWordH);
            //
            aCarry = aCarry + (RotL64(aWandererB, 24U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 21U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 37U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererH, 41U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererA, 34U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = (RotL64(aFireLaneA[((aIndex + 7251U)) & S_BLOCK1], 35U) ^ RotL64(aInvestLaneC[((aIndex + 8591U)) & S_BLOCK1], 27U));
            aIngress ^= (RotL64(aInvestLaneD[((aIndex + 7901U)) & S_BLOCK1], 18U) ^ RotL64(aWorkLaneA[((aIndex + 5547U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 6546U)) & S_BLOCK1], 4U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 9665U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 5767U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCross, 22U) ^ RotL64(aIngress, 5U)) + (RotL64(aCarry, 35U) + RotL64(aPrevious, 51U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 13U)) + 13687218104610230596U) + aNonceWordE;
            aOrbiterJ = (aWandererG + RotL64(aScatter, 3U)) + 6841550124960692709U;
            aOrbiterI = (aWandererK + RotL64(aIngress, 47U)) + 17418968668458764131U;
            aOrbiterB = (aWandererE + RotL64(aCross, 51U)) + 8303537912696948204U;
            aOrbiterH = (((aWandererF + RotL64(aPrevious, 23U)) + RotL64(aCarry, 51U)) + 12376614417285936537U) + aNonceWordG;
            aOrbiterF = ((aWandererA + RotL64(aScatter, 42U)) + RotL64(aCarry, 29U)) + 14215749063579232654U;
            aOrbiterE = ((aWandererI + RotL64(aIngress, 5U)) + 4111736931433665347U) + aPhaseEOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = (((aWandererC + RotL64(aCross, 19U)) + RotL64(aCarry, 11U)) + 11250375934571631522U) + aNonceWordP;
            aOrbiterK = (aWandererJ + RotL64(aPrevious, 57U)) + 5367367837773331275U;
            aOrbiterG = ((aWandererB + RotL64(aIngress, 27U)) + 15514089192382674434U) + aNonceWordI;
            aOrbiterC = ((aWandererD + RotL64(aScatter, 44U)) + 1475991716685034960U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 5531622777788629748U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 8363822215908303335U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17850203366840994883U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 3741256932685720414U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 11634667238062155772U;
            aOrbiterF = RotL64((aOrbiterF * 15925089729784547403U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 18180546911210417155U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 5123234656838556335U;
            aOrbiterJ = RotL64((aOrbiterJ * 15362857462853398025U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 11215734271189250284U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 16863747802158398092U;
            aOrbiterD = RotL64((aOrbiterD * 1828035970246160023U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 9859050606636646323U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 9331300036643654675U;
            aOrbiterE = RotL64((aOrbiterE * 2502263410556166281U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 15028845665427209759U) + aNonceWordM;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 8916444839488901676U) ^ aNonceWordN;
            aOrbiterB = RotL64((aOrbiterB * 6646561894156038791U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 8024631140949068570U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 1116378858490660031U;
            aOrbiterG = RotL64((aOrbiterG * 4247798531910227367U), 27U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterA) + 5066486214537899212U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 9346312092322423057U;
            aOrbiterH = RotL64((aOrbiterH * 13443190089768875191U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 11651011617027950122U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 11308862427412671711U;
            aOrbiterK = RotL64((aOrbiterK * 12167147966934334703U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 3850136281462840708U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 13461307727665667424U;
            aOrbiterA = RotL64((aOrbiterA * 10788040812090673421U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 17824744996404571928U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 13687218104610230596U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 325803029547254631U), 3U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterI, 43U);
            aIngress = aIngress + (RotL64(aOrbiterH, 41U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 19U));
            aIngress = aIngress + (RotL64(aOrbiterF, 57U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterC, 50U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterK, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aIngress, 6U) + RotL64(aOrbiterG, 4U)) + aOrbiterH) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterJ, 37U)) + aOrbiterD);
            aWandererI = aWandererI + (((RotL64(aScatter, 47U) + aOrbiterI) + RotL64(aOrbiterD, 39U)) + RotL64(aCarry, 23U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterE, 57U)) + aOrbiterB) + aNonceWordK);
            aWandererK = aWandererK + (((RotL64(aCross, 37U) + RotL64(aOrbiterC, 35U)) + aOrbiterG) + RotL64(aCarry, 41U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterK, 30U)) + aOrbiterA);
            aWandererA = aWandererA + (((RotL64(aPrevious, 21U) + aOrbiterJ) + RotL64(aOrbiterK, 19U)) + aNonceWordA);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterC, 53U)) + aOrbiterF) + aNonceWordF);
            aWandererB = aWandererB + (((RotL64(aPrevious, 56U) + aOrbiterF) + RotL64(aOrbiterJ, 23U)) + aPhaseEWandererUpdateSaltA[((aIndex + 26U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterK, 27U)) + aOrbiterI);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 29U) + RotL64(aOrbiterA, 21U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 24U));
            aCarry = aCarry + (RotL64(aWandererC, 21U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 18U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererH, 35U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 13259U)) & S_BLOCK1], 14U) ^ RotL64(aInvestLaneA[((aIndex + 12454U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 15214U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 14155U)) & S_BLOCK1], 13U) ^ RotL64(aInvestLaneC[((aIndex + 11916U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aPrevious, 21U) + RotL64(aCross, 37U)) ^ (RotL64(aIngress, 54U) + RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterF = (aWandererA + RotL64(aIngress, 11U)) + 1210605127156905516U;
            aOrbiterK = (((aWandererF + RotL64(aPrevious, 13U)) + RotL64(aCarry, 11U)) + 11964595428173569519U) + aNonceWordI;
            aOrbiterA = ((aWandererH + RotL64(aCross, 24U)) + 16277319029916258482U) + aNonceWordP;
            aOrbiterE = (aWandererB + RotL64(aScatter, 21U)) + 12369497463101824572U;
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 57U)) + 6201248574067068202U) + aPhaseEOrbiterAssignSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterJ = (aWandererJ + RotL64(aCross, 39U)) + 1727477025667206661U;
            aOrbiterC = ((aWandererE + RotL64(aIngress, 5U)) + RotL64(aCarry, 29U)) + 1404510627789806851U;
            aOrbiterG = (aWandererC + RotL64(aScatter, 43U)) + 6948213591282018925U;
            aOrbiterI = ((aWandererI + RotL64(aCross, 53U)) + RotL64(aCarry, 53U)) + 6688865181284421478U;
            aOrbiterB = ((aWandererG + RotL64(aScatter, 29U)) + 3351130769402360855U) + aNonceWordN;
            aOrbiterD = ((aWandererD + RotL64(aIngress, 36U)) + 12681032488906270823U) + aPhaseEOrbiterAssignSaltE[((aIndex + 14U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 3591412591193726763U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 16153817571210878589U) ^ aNonceWordK;
            aOrbiterA = RotL64((aOrbiterA * 4165137036092246349U), 47U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterF) + 3808228354421006630U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1]) + aNonceWordH;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 1427373776207504205U;
            aOrbiterH = RotL64((aOrbiterH * 4534374093769595531U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 1831554180932501132U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 1114853085120949215U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4264176108298812905U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 2080935638828366835U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 16104777999646489828U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15205199362011777473U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 9782806013673440791U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 3721620299829386454U;
            aOrbiterB = RotL64((aOrbiterB * 6286765834910272409U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 4013706412064296527U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 5751022780695158579U;
            aOrbiterK = RotL64((aOrbiterK * 13766736471646116397U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 17684546333240329338U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 1106947111128020920U;
            aOrbiterE = RotL64((aOrbiterE * 3158839453318658951U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 11564229705849500598U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 1585817314460274286U;
            aOrbiterC = RotL64((aOrbiterC * 12687162159791577431U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 13549147977354138518U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 5148731385622182707U) ^ aNonceWordF;
            aOrbiterG = RotL64((aOrbiterG * 11016443961557395981U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 17048442399822433365U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 13772472534194030098U;
            aOrbiterI = RotL64((aOrbiterI * 13155895389652826889U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 9982971300679888388U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 1210605127156905516U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9183351854400012949U), 21U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterG, 50U);
            aIngress = aIngress + (RotL64(aOrbiterD, 43U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterE, 23U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 11U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 5U));
            aIngress = aIngress + RotL64(aOrbiterB, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aPrevious, 11U) + aOrbiterG) + RotL64(aOrbiterC, 13U)) + RotL64(aCarry, 19U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 18U) + RotL64(aOrbiterH, 19U)) + aOrbiterB);
            aWandererA = aWandererA + ((RotL64(aCross, 23U) + RotL64(aOrbiterB, 60U)) + aOrbiterE);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 3U) + aOrbiterE) + RotL64(aOrbiterF, 47U));
            aWandererI = aWandererI + (((RotL64(aScatter, 27U) + RotL64(aOrbiterJ, 39U)) + aOrbiterG) + RotL64(aCarry, 35U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterI, 5U)) + aOrbiterE) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aPrevious, 5U) + aOrbiterG) + RotL64(aOrbiterK, 26U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterI, 51U)) + aOrbiterD) + aNonceWordM);
            aWandererF = aWandererF + ((RotL64(aPrevious, 13U) + aOrbiterG) + RotL64(aOrbiterH, 35U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 51U) + aOrbiterC) + RotL64(aOrbiterA, 29U));
            aWandererK = aWandererK + ((((RotL64(aCross, 58U) + RotL64(aOrbiterG, 37U)) + aOrbiterF) + aNonceWordB) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 44U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 41U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + RotL64(aWandererI, 36U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 19487U)) & S_BLOCK1], 19U) ^ RotL64(aFireLaneA[((aIndex + 20808U)) & S_BLOCK1], 60U));
            aIngress ^= RotL64(aWorkLaneD[((aIndex + 17926U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 17145U)) & S_BLOCK1], 35U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 17918U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aIngress, 3U) + RotL64(aCarry, 37U)) ^ (RotL64(aPrevious, 23U) + RotL64(aCross, 54U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterE = ((aWandererH + RotL64(aIngress, 22U)) + RotL64(aCarry, 11U)) + 2617613537256538553U;
            aOrbiterC = (aWandererJ + RotL64(aCross, 19U)) + 16642868916835132715U;
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 43U)) + 10860291124337073254U) + aNonceWordO;
            aOrbiterK = (aWandererC + RotL64(aScatter, 53U)) + 6432511273906902472U;
            aOrbiterI = (aWandererI + RotL64(aCross, 10U)) + 7505375005848241910U;
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 27U)) + 11086616004678821329U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = ((aWandererG + RotL64(aIngress, 57U)) + 3298830587569881951U) + aNonceWordA;
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 39U)) + RotL64(aCarry, 37U)) + 9775143140064220979U;
            aOrbiterA = (aWandererD + RotL64(aPrevious, 35U)) + 4147601326580823120U;
            aOrbiterD = (aWandererB + RotL64(aScatter, 3U)) + 12245920269898100415U;
            aOrbiterF = (((aWandererE + RotL64(aCross, 47U)) + RotL64(aCarry, 43U)) + 8391940489176734499U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 17876893379544668477U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 18301882058180370541U;
            aOrbiterB = RotL64((aOrbiterB * 16680384667098921309U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 6869225862715140102U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 15404118372589259800U;
            aOrbiterI = RotL64((aOrbiterI * 5766851935950389915U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 17757381020518233814U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 17677969146092374455U;
            aOrbiterH = RotL64((aOrbiterH * 3469432916562405063U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 15783378556632870114U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 5792858258663697864U) ^ aNonceWordM;
            aOrbiterJ = RotL64((aOrbiterJ * 12008981883482080427U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 11737803388202260296U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 16001927091970715330U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3062030309852922061U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 1749586939123286632U) + aNonceWordL;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 6169421068855905938U;
            aOrbiterE = RotL64((aOrbiterE * 12374789910763348695U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 10073586820719728062U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 17744171227198661555U;
            aOrbiterF = RotL64((aOrbiterF * 10658375268803957647U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 1149819647337612792U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 7725598665625892006U;
            aOrbiterG = RotL64((aOrbiterG * 15097586655234391559U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 13930096050550704122U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 3632241034947389647U;
            aOrbiterK = RotL64((aOrbiterK * 8442222389196610427U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 17933893495867517142U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 7888594392078082482U;
            aOrbiterA = RotL64((aOrbiterA * 9809847720610861237U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 10805303827043372168U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 2617613537256538553U;
            aOrbiterD = RotL64((aOrbiterD * 3940471942234248791U), 3U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterF, 57U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 54U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 37U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 47U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterH, 11U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterB, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aCross, 23U) + aOrbiterE) + RotL64(aOrbiterJ, 10U)) + aPhaseEWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterB, 29U)) + aOrbiterI);
            aWandererB = aWandererB + ((((RotL64(aScatter, 21U) + RotL64(aOrbiterA, 51U)) + aOrbiterD) + RotL64(aCarry, 5U)) + aNonceWordK);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 57U) + aOrbiterJ) + RotL64(aOrbiterC, 23U)) + aNonceWordJ);
            aWandererE = aWandererE + (((RotL64(aScatter, 18U) + RotL64(aOrbiterJ, 19U)) + aOrbiterH) + aPhaseEWandererUpdateSaltB[((aIndex + 28U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterE, 53U)) + aOrbiterH);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 43U) + RotL64(aOrbiterI, 43U)) + aOrbiterG) + RotL64(aCarry, 57U)) + aNonceWordE);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 3U) + aOrbiterG) + RotL64(aOrbiterA, 35U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 11U) + aOrbiterK) + RotL64(aOrbiterI, 27U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterE, 46U)) + aOrbiterF);
            aWandererF = aWandererF + (((RotL64(aCross, 40U) + aOrbiterG) + RotL64(aOrbiterK, 57U)) + aNonceWordH);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 58U));
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererJ, 54U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererD, 29U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 22368U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneB[((aIndex + 25389U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 26058U)) & S_BLOCK1], 12U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 22924U)) & S_BLOCK1], 19U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 23305U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 23108U)) & S_BLOCK1], 40U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCarry, 47U) + RotL64(aIngress, 4U)) ^ (RotL64(aPrevious, 19U) ^ RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterC = (((aWandererG + RotL64(aCross, 35U)) + RotL64(aCarry, 53U)) + 13350544654542863236U) + aNonceWordM;
            aOrbiterG = (((aWandererK + RotL64(aScatter, 5U)) + RotL64(aCarry, 57U)) + 12364346790125404372U) + aNonceWordI;
            aOrbiterD = (aWandererJ + RotL64(aIngress, 23U)) + 9738750172849512764U;
            aOrbiterA = (aWandererF + RotL64(aPrevious, 13U)) + 3781373837635491421U;
            aOrbiterE = (aWandererA + RotL64(aScatter, 10U)) + 16635020317512702337U;
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 3U)) + RotL64(aCarry, 11U)) + 5383653921676231276U;
            aOrbiterK = (aWandererE + RotL64(aIngress, 29U)) + 10181959815492056493U;
            aOrbiterH = ((aWandererI + RotL64(aCross, 53U)) + 10005510924273927017U) + aPhaseEOrbiterAssignSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = (aWandererH + RotL64(aScatter, 40U)) + 9524687662265740565U;
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 37U)) + 4259138552009771014U) + aPhaseEOrbiterAssignSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterB = ((aWandererD + RotL64(aCross, 51U)) + 8973051213213726023U) + aNonceWordL;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 17602611840127337490U) + aNonceWordC;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 8218984546932905269U;
            aOrbiterD = RotL64((aOrbiterD * 17504305273683304231U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 18102186122213487888U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 2629927500298092976U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6983280164448292723U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 2491581597835795234U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 9506602492971620955U) ^ aNonceWordP;
            aOrbiterK = RotL64((aOrbiterK * 9559829640915637163U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 13422942713680612924U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 15037354693234876601U;
            aOrbiterH = RotL64((aOrbiterH * 12692376075738621447U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 12896066842192894694U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 2202952306291905855U;
            aOrbiterI = RotL64((aOrbiterI * 6779368532763429997U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 12160313482450599313U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 10812986281270407756U;
            aOrbiterF = RotL64((aOrbiterF * 7786608700746771809U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 12474638293190144525U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 5882870951276225224U;
            aOrbiterC = RotL64((aOrbiterC * 15532427302173572457U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 3782896138051179209U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 10965680631059882311U;
            aOrbiterA = RotL64((aOrbiterA * 14060923998307082385U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 15650420683333746952U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 4110674660963676864U;
            aOrbiterJ = RotL64((aOrbiterJ * 11724979274890265275U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 694817156953099464U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 4402927404825116007U;
            aOrbiterG = RotL64((aOrbiterG * 579586789292520113U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 6849178151532923489U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 13350544654542863236U;
            aOrbiterB = RotL64((aOrbiterB * 2416097748778941523U), 47U);
            //
            aIngress = RotL64(aOrbiterF, 43U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterE, 27U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterI, 37U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterG, 10U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 5U));
            aIngress = aIngress + RotL64(aOrbiterC, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aIngress, 37U) + RotL64(aOrbiterB, 13U)) + aOrbiterA);
            aWandererC = aWandererC ^ ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterK, 23U)) + aOrbiterD) + aNonceWordH) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aCross, 50U) + RotL64(aOrbiterJ, 44U)) + aOrbiterI);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterI, 51U)) + aOrbiterC) + aNonceWordF);
            aWandererI = aWandererI + ((RotL64(aPrevious, 27U) + aOrbiterE) + RotL64(aOrbiterH, 57U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterG, 21U)) + aOrbiterE);
            aWandererE = aWandererE + ((RotL64(aScatter, 43U) + aOrbiterJ) + RotL64(aOrbiterC, 5U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 41U) + aOrbiterA) + RotL64(aOrbiterC, 19U)) + aNonceWordD);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 19U) + aOrbiterE) + RotL64(aOrbiterK, 35U)) + RotL64(aCarry, 27U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterH, 39U)) + aOrbiterF);
            aWandererH = aWandererH + (((RotL64(aCross, 52U) + RotL64(aOrbiterG, 60U)) + aOrbiterI) + RotL64(aCarry, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 46U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 29U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 41U));
            aCarry = aCarry + (RotL64(aWandererF, 37U) ^ aWandererG);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 5U));
            aCarry = aCarry + RotL64(aWandererH, 21U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 28083U)) & S_BLOCK1], 46U) ^ RotL64(aOperationLaneA[((aIndex + 28368U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 31613U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28186U)) & S_BLOCK1], 22U) ^ RotL64(aInvestLaneB[((aIndex + 32419U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aIngress, 3U)) ^ (RotL64(aCross, 21U) + RotL64(aPrevious, 54U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 43U)) + 5171470532667965920U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = ((aWandererG + RotL64(aScatter, 35U)) + RotL64(aCarry, 41U)) + 750549462358682403U;
            aOrbiterB = ((aWandererH + RotL64(aIngress, 51U)) + RotL64(aCarry, 19U)) + 3325689257577120525U;
            aOrbiterA = ((aWandererD + RotL64(aCross, 21U)) + 18031575461559790826U) + aNonceWordP;
            aOrbiterI = ((aWandererC + RotL64(aScatter, 54U)) + 13874739537012288677U) + aNonceWordM;
            aOrbiterE = ((aWandererI + RotL64(aPrevious, 39U)) + RotL64(aCarry, 47U)) + 4250029868785016865U;
            aOrbiterD = ((aWandererA + RotL64(aIngress, 27U)) + 8211158803112611161U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aCross, 29U)) + 1083939790236786027U) + aNonceWordI;
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 5U)) + 3446525462376962464U) + aNonceWordF;
            aOrbiterC = (aWandererE + RotL64(aIngress, 41U)) + 6973817815000417325U;
            aOrbiterG = (aWandererB + RotL64(aCross, 24U)) + 15230876489676945543U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 9359727659738755880U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 8775170107816327654U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6910680458261008653U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 11958941755525038545U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 16966819714283167348U;
            aOrbiterI = RotL64((aOrbiterI * 16363457661846050749U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 14556087985619763243U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 17915047508377045221U;
            aOrbiterE = RotL64((aOrbiterE * 6727635453185130109U), 29U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterF) + 8578745677485367222U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1]) + aNonceWordD;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 7002181668717618866U;
            aOrbiterK = RotL64((aOrbiterK * 12329703532414955235U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 3569939503066735457U) + aNonceWordN;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 2956247934282522184U;
            aOrbiterC = RotL64((aOrbiterC * 9946650822131152531U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 4285180013402474041U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 5976239869535619811U;
            aOrbiterG = RotL64((aOrbiterG * 3458095419039067465U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 2424524955161695463U) + aNonceWordA;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 6849595426583763537U;
            aOrbiterH = RotL64((aOrbiterH * 12727902040238318101U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 11414890686374886716U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 5668287266836153445U;
            aOrbiterD = RotL64((aOrbiterD * 8011885266143066285U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 9976985606260445887U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 9223940029500676834U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8508023992488499955U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 4480967907876921958U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 5132766654502526597U;
            aOrbiterA = RotL64((aOrbiterA * 321625389942019245U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 12921555132452983464U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 5171470532667965920U;
            aOrbiterF = RotL64((aOrbiterF * 9710487797420618879U), 21U);
            //
            aIngress = RotL64(aOrbiterG, 41U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 27U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + (RotL64(aOrbiterE, 6U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterK, 53U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aIngress, 3U) + aOrbiterF) + RotL64(aOrbiterI, 41U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 13U) + aOrbiterA) + RotL64(aOrbiterJ, 21U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 53U) + aOrbiterK) + RotL64(aOrbiterG, 57U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 43U) + aOrbiterC) + RotL64(aOrbiterK, 29U)) + aNonceWordL);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 60U) + aOrbiterF) + RotL64(aOrbiterB, 14U));
            aWandererH = aWandererH + (((RotL64(aCross, 19U) + aOrbiterK) + RotL64(aOrbiterE, 43U)) + RotL64(aCarry, 43U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 27U) + aOrbiterE) + RotL64(aOrbiterF, 3U)) + aNonceWordE);
            aWandererF = aWandererF + (((RotL64(aScatter, 21U) + aOrbiterH) + RotL64(aOrbiterJ, 5U)) + RotL64(aCarry, 13U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 10U) + RotL64(aOrbiterK, 35U)) + aOrbiterD);
            aWandererA = aWandererA + (((RotL64(aScatter, 35U) + RotL64(aOrbiterK, 26U)) + aOrbiterH) + aNonceWordO);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 23U) + aOrbiterA) + RotL64(aOrbiterF, 53U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 60U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 48U));
            aCarry = aCarry + RotL64(aWandererH, 51U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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

void TwistExpander_Rugby_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xA30B2EEDB7168833ULL + 0xF8512052700BD8C7ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x902C80FDD95C6A67ULL + 0x8707254A1DD2CC40ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xD1BA895E06297A27ULL + 0xA23E3CBCBC061939ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xCB6D4BDF8DE949E1ULL + 0x9ED0A15C113DAE6DULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xBF3AF13B91CA37E3ULL + 0xB1E77B049078B652ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xE75C29B074912297ULL + 0xBC236830508FD6FEULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xED6B6649DC5C928DULL + 0xB58E2AE25CA76055ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xE73C548D1042054FULL + 0xD98AC304477DC450ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xDEA863FA57038B61ULL + 0xB02F14B05C5BD720ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x9C354D140947FC7BULL + 0x845FC7000664A90FULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xAFC2745EE41854D1ULL + 0x9AD4A424282AD2F6ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x8C83BA4284864CE1ULL + 0xB95DD89536621FAFULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xA965D227A0364AABULL + 0xB1373FCC9F3E1095ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xF00754AAE6607E89ULL + 0xBB526D2737383531ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xC7FF31BE60A82587ULL + 0xDD263F30D938996DULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x8456AD16EF4C3563ULL + 0xD81AAD5EF6F1B82BULL);
    // GSeedRunSeed_F seed_loop_f (start)
    {
        // GSeedRunSeed_F seed_loop_f lane group
        // read from: aOperationLaneA, aOperationLaneB, aWorkLaneC, aOperationLaneC, aOperationLaneD, aInvestLaneD, aSnowLaneC, aInvestLaneA, aSnowLaneB, aSnowLaneD, aInvestLaneC, aExpandLaneA, aWorkLaneD, aExpandLaneB, aSnowLaneA, aExpandLaneC, aInvestLaneB
        // write to: aSnowLaneC, aSnowLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_f loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aWorkLaneC
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aWorkLaneC forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aInvestLaneD
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aInvestLaneD backward/forward random
        // write to: aSnowLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 3072U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneB[((aIndex + 3682U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 5227U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 767U)) & S_BLOCK1], 52U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 2288U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aInvestLaneD[((aIndex + 9U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aPrevious, 23U)) ^ (RotL64(aIngress, 57U) + RotL64(aCross, 40U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterF = ((aWandererG + RotL64(aCross, 27U)) + 8975885703279267062U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = (aWandererD + RotL64(aPrevious, 13U)) + 8664844915562660637U;
            aOrbiterH = ((aWandererK + RotL64(aScatter, 60U)) + 12281774799736296726U) + aNonceWordL;
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 23U)) + RotL64(aCarry, 21U)) + 15347461352311329726U;
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 19U)) + RotL64(aCarry, 29U)) + 12967500561828907834U;
            aOrbiterK = (((aWandererH + RotL64(aCross, 5U)) + 5002833859280402726U) + aPhaseFOrbiterAssignSaltD[((aIndex + 24U)) & S_SALT1]) + aNonceWordA;
            aOrbiterC = (aWandererE + RotL64(aScatter, 50U)) + 11908257536954668983U;
            aOrbiterB = (aWandererB + RotL64(aIngress, 39U)) + 17017174811949227162U;
            aOrbiterG = (((aWandererF + RotL64(aCross, 35U)) + RotL64(aCarry, 11U)) + 16851323125613931180U) + aNonceWordM;
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 13469326957728686706U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 5228638551056105241U) ^ aNonceWordB;
            aOrbiterH = RotL64((aOrbiterH * 13369947664646167255U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 11945166198089308564U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 16268645041872996022U;
            aOrbiterD = RotL64((aOrbiterD * 5391448793718370911U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 14781204627695095701U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 5365325354838101092U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8017284997946310807U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 563147416025715953U) + aNonceWordI;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 14660867395395625851U;
            aOrbiterB = RotL64((aOrbiterB * 4769458126865307103U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 3168989056355712105U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 16179131669773665579U;
            aOrbiterG = RotL64((aOrbiterG * 5641461617066671723U), 29U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterF) + 4160220074225527179U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordK;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 8597134686962559111U;
            aOrbiterJ = RotL64((aOrbiterJ * 639572585431474015U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 16811551552456811661U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 5827323970423386301U;
            aOrbiterI = RotL64((aOrbiterI * 9328247349730652021U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 15583234353262170227U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 2950816254621717748U;
            aOrbiterC = RotL64((aOrbiterC * 1102417597476170143U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 4426165025104306337U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 11871220132164971152U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2366168050042802207U), 35U);
            //
            aIngress = RotL64(aOrbiterD, 20U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterJ, 51U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterK, 5U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterF, 23U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterC, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 29U) + aOrbiterB) + RotL64(aOrbiterJ, 53U)) + aNonceWordF);
            aWandererD = aWandererD + ((((RotL64(aCross, 6U) + RotL64(aOrbiterI, 29U)) + aOrbiterC) + RotL64(aCarry, 43U)) + aNonceWordN);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 53U) + aOrbiterK) + RotL64(aOrbiterF, 21U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aScatter, 39U) + RotL64(aOrbiterI, 4U)) + aOrbiterK) + RotL64(aCarry, 27U)) + aPhaseFWandererUpdateSaltC[((aIndex + 4U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterH, 47U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 21U) + RotL64(aOrbiterG, 41U)) + aOrbiterC);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 13U) + aOrbiterB) + RotL64(aOrbiterG, 13U));
            aWandererK = aWandererK + ((RotL64(aIngress, 35U) + RotL64(aOrbiterC, 58U)) + aOrbiterK);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 48U) + aOrbiterD) + RotL64(aOrbiterF, 35U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 54U));
            aCarry = aCarry + (RotL64(aWandererF, 23U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererG);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + RotL64(aWandererD, 29U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aSnowLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 2
        // ingress from: aSnowLaneC, aOperationLaneC, aOperationLaneD, aInvestLaneA
        // ingress directions: aSnowLaneC forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aInvestLaneA forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aSnowLaneB
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aSnowLaneB backward/forward random
        // write to: aSnowLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneC[((aIndex + 9315U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneC[((aIndex + 5889U)) & S_BLOCK1], 19U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 9738U)) & S_BLOCK1], 37U) ^ RotL64(aInvestLaneA[((aIndex + 5655U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 10212U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 9624U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 9482U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aIngress, 29U) ^ RotL64(aCross, 41U)) + (RotL64(aPrevious, 6U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterF = (aWandererG + RotL64(aPrevious, 60U)) + 15920462086654025436U;
            aOrbiterH = ((aWandererD + RotL64(aIngress, 39U)) + 487844076858004017U) + aNonceWordM;
            aOrbiterB = (((aWandererI + RotL64(aCross, 35U)) + RotL64(aCarry, 41U)) + 14502883786442630566U) + aNonceWordK;
            aOrbiterD = (((aWandererB + RotL64(aScatter, 21U)) + 3787107318658233674U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordH;
            aOrbiterG = (aWandererK + RotL64(aIngress, 56U)) + 12548777544693755491U;
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 51U)) + RotL64(aCarry, 5U)) + 4907309444075181683U;
            aOrbiterC = ((aWandererA + RotL64(aScatter, 43U)) + RotL64(aCarry, 53U)) + 18342396700266492072U;
            aOrbiterA = ((aWandererH + RotL64(aCross, 5U)) + 13503051997624242670U) + aPhaseFOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 13U)) + 17845742460521374571U) + aNonceWordI;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 8640887211877858169U) + aNonceWordJ;
            aOrbiterB = (((aOrbiterB ^ aOrbiterF) ^ 5273913123709097537U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterB = RotL64((aOrbiterB * 1661149444148461791U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 17756844173695563883U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 6713055830729302951U;
            aOrbiterH = RotL64((aOrbiterH * 2832836748513174311U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 5106468334224035972U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 10228769728713526172U;
            aOrbiterG = RotL64((aOrbiterG * 9760310686414358435U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 7687649520668883142U) + aNonceWordN;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 7757480627354711605U;
            aOrbiterI = RotL64((aOrbiterI * 7222553727737349209U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 10876291698508634557U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 8149278085586014186U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8577133863470695381U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 15592893988925610485U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 8639028256640537165U;
            aOrbiterJ = RotL64((aOrbiterJ * 1880655276432963955U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 475660347892196219U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 1903736092401853832U) ^ aNonceWordC;
            aOrbiterF = RotL64((aOrbiterF * 8486318978769094799U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 12463250192809450953U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 7253918448601703982U;
            aOrbiterD = RotL64((aOrbiterD * 3821034106528009129U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 5171661020093804486U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 11627344933828324146U;
            aOrbiterC = RotL64((aOrbiterC * 5388047063152043277U), 57U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterF, 52U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 19U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 43U));
            aIngress = aIngress + (RotL64(aOrbiterG, 29U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterB, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aPrevious, 39U) + aOrbiterD) + RotL64(aOrbiterH, 53U)) + RotL64(aCarry, 23U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 52U) + RotL64(aOrbiterA, 47U)) + aOrbiterG);
            aWandererH = aWandererH + ((RotL64(aIngress, 29U) + aOrbiterB) + RotL64(aOrbiterI, 58U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterH, 35U)) + aOrbiterA) + aNonceWordA);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 35U) + aOrbiterJ) + RotL64(aOrbiterF, 5U)) + aNonceWordG);
            aWandererA = aWandererA ^ ((RotL64(aCross, 4U) + aOrbiterA) + RotL64(aOrbiterB, 43U));
            aWandererG = aWandererG + ((((RotL64(aIngress, 13U) + aOrbiterF) + RotL64(aOrbiterA, 12U)) + RotL64(aCarry, 53U)) + aNonceWordD);
            aWandererF = aWandererF ^ ((((RotL64(aPrevious, 57U) + aOrbiterB) + RotL64(aOrbiterF, 27U)) + aNonceWordL) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aIngress, 47U) + RotL64(aOrbiterC, 23U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererK, 39U) ^ aWandererH);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 50U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aSnowLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_f loop 3
        // ingress from: aSnowLaneD, aOperationLaneA, aInvestLaneC
        // ingress directions: aSnowLaneD forward forced, aOperationLaneA forward forced, aInvestLaneC forward/backward random
        // cross from: aSnowLaneC, aOperationLaneC
        // cross directions: aSnowLaneC backward forced, aOperationLaneC backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneD[((aIndex + 12020U)) & S_BLOCK1], 50U) ^ RotL64(aOperationLaneA[((aIndex + 15383U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aInvestLaneC[((aIndex + 14454U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 11451U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 14624U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 51U) + RotL64(aCarry, 37U)) ^ (RotL64(aPrevious, 21U) + RotL64(aCross, 6U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 23U)) + RotL64(aCarry, 47U)) + 3612110001869385068U;
            aOrbiterA = (((aWandererI + RotL64(aScatter, 27U)) + RotL64(aCarry, 21U)) + 16340824141280225936U) + aNonceWordF;
            aOrbiterE = ((aWandererD + RotL64(aIngress, 47U)) + RotL64(aCarry, 29U)) + 15222338965130765231U;
            aOrbiterD = ((aWandererB + RotL64(aCross, 56U)) + 6649270508107155041U) + aPhaseFOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = (aWandererH + RotL64(aIngress, 51U)) + 768217258655426384U;
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 19U)) + 4481855259658861851U;
            aOrbiterH = (aWandererF + RotL64(aCross, 3U)) + 18318041934562434016U;
            aOrbiterF = (((aWandererA + RotL64(aScatter, 60U)) + 4212457153804401807U) + aPhaseFOrbiterAssignSaltA[((aIndex + 14U)) & S_SALT1]) + aNonceWordD;
            aOrbiterG = (aWandererG + RotL64(aPrevious, 39U)) + 16143621095636987628U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 2095664232866642086U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 4339527736737366572U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17503569508822244125U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 13679353177869884790U) + aNonceWordJ;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 11582168502846418236U;
            aOrbiterK = RotL64((aOrbiterK * 135539430034462861U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 10451330452898542191U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 12951448817640617841U) ^ aNonceWordE;
            aOrbiterD = RotL64((aOrbiterD * 4141870904192742091U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 15389161934419370747U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 4754886272708253014U;
            aOrbiterF = RotL64((aOrbiterF * 16638243718191281597U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 11746389873929280688U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 12042680172517298768U;
            aOrbiterH = RotL64((aOrbiterH * 3814780289755857543U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 2648103752465009244U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 451594673632597973U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8496763663271072425U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 5696534794094099710U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 14609435045257077395U;
            aOrbiterG = RotL64((aOrbiterG * 14658408563237468407U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 11599395126850950133U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 12699598504604446664U;
            aOrbiterC = RotL64((aOrbiterC * 14313494063098111823U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 9398465148537154745U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 12139736860648011256U;
            aOrbiterA = RotL64((aOrbiterA * 15257503229375247987U), 53U);
            //
            aIngress = RotL64(aOrbiterD, 14U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterC, 11U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 37U));
            aIngress = aIngress + (RotL64(aOrbiterI, 51U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterF, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aIngress, 43U) + aOrbiterD) + RotL64(aOrbiterK, 47U)) + aNonceWordK) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 18U) + aOrbiterH) + RotL64(aOrbiterG, 27U)) + aNonceWordC) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 51U) + aOrbiterA) + RotL64(aOrbiterI, 19U)) + RotL64(aCarry, 27U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterC, 51U)) + aOrbiterI);
            aWandererG = aWandererG + (((RotL64(aPrevious, 23U) + aOrbiterF) + RotL64(aOrbiterG, 60U)) + aNonceWordH);
            aWandererH = aWandererH ^ ((RotL64(aCross, 57U) + aOrbiterD) + RotL64(aOrbiterA, 35U));
            aWandererB = aWandererB + ((RotL64(aIngress, 14U) + aOrbiterC) + RotL64(aOrbiterE, 43U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 29U) + aOrbiterD) + RotL64(aOrbiterF, 13U));
            aWandererF = aWandererF + (((RotL64(aCross, 47U) + RotL64(aOrbiterC, 4U)) + aOrbiterG) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + (RotL64(aWandererK, 42U) ^ aWandererF);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 39U));
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererB, 19U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 20746U)) & S_BLOCK1], 28U) ^ RotL64(aSnowLaneC[((aIndex + 21080U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 18718U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 18075U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 17696U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCarry, 53U)) ^ (RotL64(aPrevious, 28U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterG = (((aWandererI + RotL64(aScatter, 53U)) + RotL64(aCarry, 43U)) + 16183871922837164759U) + aPhaseFOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 14U)) + 7002058258090219055U) + aNonceWordK;
            aOrbiterK = (((aWandererA + RotL64(aPrevious, 39U)) + RotL64(aCarry, 53U)) + 5650868611888303705U) + aNonceWordP;
            aOrbiterF = ((aWandererD + RotL64(aCross, 57U)) + RotL64(aCarry, 35U)) + 11899839660943876690U;
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 35U)) + 15349649504488111111U) + aPhaseFOrbiterAssignSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = (aWandererK + RotL64(aIngress, 27U)) + 14060149569086744970U;
            aOrbiterE = (aWandererC + RotL64(aCross, 10U)) + 12920917574225030112U;
            aOrbiterD = (aWandererG + RotL64(aScatter, 3U)) + 2831994965175330135U;
            aOrbiterA = ((aWandererH + RotL64(aCross, 23U)) + 18312543585028439192U) + aNonceWordO;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 11657562205118394239U) + aNonceWordA;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 10850792819281246052U;
            aOrbiterK = RotL64((aOrbiterK * 10663100544207879337U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 17810371216216125323U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 7963413941144223128U;
            aOrbiterI = RotL64((aOrbiterI * 534217972450595401U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 5498715358793875584U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 9256727548911651373U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10498848323914000989U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 17246360111302191699U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 18309978718113983369U;
            aOrbiterE = RotL64((aOrbiterE * 18267472694666221077U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 3100998994319502921U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 8129301860291235970U;
            aOrbiterG = RotL64((aOrbiterG * 17847033539279176187U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 1889641029473279114U) + aNonceWordE;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 16538494307002917945U;
            aOrbiterH = RotL64((aOrbiterH * 8081488217920885783U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 5432230549146849322U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 2634437941396090817U;
            aOrbiterF = RotL64((aOrbiterF * 7612999214758935211U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 16940172599174185058U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 13151669140593952203U;
            aOrbiterJ = RotL64((aOrbiterJ * 16225319638131723487U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 3995064294869931681U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 913081077665768816U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9299514648768060453U), 47U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterF, 5U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 53U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 44U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 23U));
            aIngress = aIngress + RotL64(aOrbiterE, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aPrevious, 48U) + RotL64(aOrbiterI, 23U)) + aOrbiterA);
            aWandererC = aWandererC ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterE, 19U)) + aOrbiterA) + aNonceWordJ);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 57U) + RotL64(aOrbiterI, 52U)) + aOrbiterF) + aNonceWordG);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 27U) + aOrbiterH) + RotL64(aOrbiterF, 43U)) + aPhaseFWandererUpdateSaltC[((aIndex + 26U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aCross, 11U) + aOrbiterA) + RotL64(aOrbiterJ, 27U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 53U) + aOrbiterF) + RotL64(aOrbiterK, 3U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 22U) + aOrbiterF) + RotL64(aOrbiterJ, 39U)) + RotL64(aCarry, 43U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 5U) + aOrbiterG) + RotL64(aOrbiterE, 60U));
            aWandererG = aWandererG + (((RotL64(aScatter, 43U) + RotL64(aOrbiterA, 11U)) + aOrbiterD) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 34U));
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererC, 39U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_f loop 5
        // ingress from: aExpandLaneB, aSnowLaneD, aSnowLaneA
        // ingress directions: aExpandLaneB forward forced, aSnowLaneD forward forced, aSnowLaneA forward/backward random
        // cross from: aExpandLaneA, aSnowLaneC
        // cross directions: aExpandLaneA backward forced, aSnowLaneC backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 22228U)) & S_BLOCK1], 48U) ^ RotL64(aSnowLaneD[((aIndex + 25013U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 24931U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26508U)) & S_BLOCK1], 3U) ^ RotL64(aSnowLaneC[((aIndex + 24911U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aPrevious, 56U) + RotL64(aCarry, 41U)) + (RotL64(aCross, 5U) ^ RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterE = ((((aWandererK + RotL64(aScatter, 27U)) + RotL64(aCarry, 11U)) + 5173905450211892891U) + aPhaseFOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 58U)) + 3555542451908039957U) + aNonceWordA;
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 51U)) + RotL64(aCarry, 23U)) + 11559884700283861559U;
            aOrbiterI = (aWandererA + RotL64(aCross, 5U)) + 1352524329968738673U;
            aOrbiterK = (((aWandererF + RotL64(aScatter, 41U)) + 8914206450420616349U) + aPhaseFOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1]) + aNonceWordG;
            aOrbiterC = ((aWandererB + RotL64(aCross, 47U)) + RotL64(aCarry, 47U)) + 2251523378498463946U;
            aOrbiterG = (aWandererG + RotL64(aIngress, 34U)) + 9541575923299247038U;
            aOrbiterD = (aWandererJ + RotL64(aPrevious, 23U)) + 1239854507907214595U;
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 19U)) + 17698101462598498934U) + aNonceWordD;
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 12305566971683256060U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 13804545036303215569U;
            aOrbiterA = RotL64((aOrbiterA * 10359543704152744971U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 10239749097704329264U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 4212214906286320308U) ^ aNonceWordL;
            aOrbiterF = RotL64((aOrbiterF * 3661436621615751071U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 12192418916967430783U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 4475514289326450361U) ^ aNonceWordH;
            aOrbiterK = RotL64((aOrbiterK * 17497164630368757887U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 17376102613298827459U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 18129393209955439341U;
            aOrbiterD = RotL64((aOrbiterD * 6404089025014118979U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 4014763724300253568U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 17325007199676828814U;
            aOrbiterJ = RotL64((aOrbiterJ * 1420888274815627083U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 15480474849292388685U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 14357924730184375449U;
            aOrbiterI = RotL64((aOrbiterI * 16723492259068034209U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 4335731868597970070U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 8296023680394303015U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14027415401430120543U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 2807312426993262800U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterK) ^ 15510369660839648501U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterG = RotL64((aOrbiterG * 18207954408298333959U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 12597844696606519907U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 7231012798553551535U;
            aOrbiterC = RotL64((aOrbiterC * 2841306785994479299U), 19U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterE, 11U);
            aIngress = aIngress + (RotL64(aOrbiterI, 36U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 53U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 27U));
            aIngress = aIngress + RotL64(aOrbiterK, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aCross, 35U) + aOrbiterJ) + RotL64(aOrbiterE, 35U)) + RotL64(aCarry, 43U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 5U) + aOrbiterC) + RotL64(aOrbiterD, 30U)) + aPhaseFWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aIngress, 57U) + aOrbiterJ) + RotL64(aOrbiterI, 23U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 23U) + aOrbiterA) + RotL64(aOrbiterG, 3U));
            aWandererF = aWandererF + ((((RotL64(aCross, 12U) + aOrbiterJ) + RotL64(aOrbiterK, 51U)) + aNonceWordO) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 19U) + aOrbiterI) + RotL64(aOrbiterG, 57U)) + aNonceWordF);
            aWandererK = aWandererK + (((RotL64(aScatter, 27U) + RotL64(aOrbiterA, 39U)) + aOrbiterK) + RotL64(aCarry, 5U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 53U) + aOrbiterJ) + RotL64(aOrbiterD, 44U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 46U) + aOrbiterF) + RotL64(aOrbiterA, 11U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 18U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererJ, 34U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 6
        // ingress from: aExpandLaneC, aExpandLaneA, aInvestLaneB
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aInvestLaneB forward/backward random
        // cross from: aExpandLaneB, aOperationLaneB
        // cross directions: aExpandLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 32515U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((aIndex + 30082U)) & S_BLOCK1], 36U));
            aIngress ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 29202U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29541U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((aIndex + 31190U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCarry, 11U) ^ RotL64(aIngress, 23U)) + (RotL64(aPrevious, 58U) ^ RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterC = ((aWandererC + RotL64(aScatter, 56U)) + 439898681482066326U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = ((aWandererB + RotL64(aIngress, 5U)) + RotL64(aCarry, 41U)) + 17362083676671776094U;
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 47U)) + 6418499837265155024U) + aNonceWordM;
            aOrbiterD = (((aWandererK + RotL64(aCross, 21U)) + RotL64(aCarry, 23U)) + 17262244253027454972U) + aNonceWordD;
            aOrbiterF = (aWandererH + RotL64(aIngress, 41U)) + 2382066162993139503U;
            aOrbiterK = ((aWandererD + RotL64(aCross, 51U)) + 14345808395587174135U) + aPhaseFOrbiterAssignSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = (aWandererF + RotL64(aScatter, 35U)) + 7534743166385552851U;
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 14U)) + RotL64(aCarry, 11U)) + 16994453324688523966U;
            aOrbiterB = ((aWandererI + RotL64(aScatter, 29U)) + 7079553728544045092U) + aNonceWordB;
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 3562822704508440641U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 13990892681975857821U;
            aOrbiterH = RotL64((aOrbiterH * 8352929306654078795U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 1796728922368577238U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 6605161260520067178U;
            aOrbiterF = RotL64((aOrbiterF * 8147537646591674091U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 13994083795942328918U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 6144523182899107711U) ^ aNonceWordK;
            aOrbiterE = RotL64((aOrbiterE * 4153879991344611283U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 12247462325297436642U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 1065809332002012789U;
            aOrbiterC = RotL64((aOrbiterC * 5496601177032953251U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 10147919864511540753U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 17138553441127273354U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5773875596275267871U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 2653924016109573974U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 6254416952351699582U) ^ aNonceWordP;
            aOrbiterK = RotL64((aOrbiterK * 12756861659704947257U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 813046408080197079U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 9624466135414123483U) ^ aNonceWordJ;
            aOrbiterB = RotL64((aOrbiterB * 6960320253124395015U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 972586705850825744U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 155283774901960223U;
            aOrbiterG = RotL64((aOrbiterG * 9928051687724257041U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 18200100644751360406U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 1168426822045686004U) ^ aNonceWordN;
            aOrbiterI = RotL64((aOrbiterI * 5867027156069481313U), 23U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterE, 47U);
            aIngress = aIngress + (RotL64(aOrbiterG, 42U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterK, 37U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 23U));
            aIngress = aIngress + RotL64(aOrbiterD, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aIngress, 23U) + aOrbiterB) + RotL64(aOrbiterK, 3U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 34U) + RotL64(aOrbiterC, 56U)) + aOrbiterG) + aNonceWordL);
            aWandererF = aWandererF + (((RotL64(aCross, 43U) + aOrbiterE) + RotL64(aOrbiterK, 47U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterI, 43U)) + aOrbiterC) + aNonceWordC);
            aWandererE = aWandererE + (((((RotL64(aCross, 29U) + aOrbiterC) + RotL64(aOrbiterF, 19U)) + RotL64(aCarry, 51U)) + aNonceWordO) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 5U) + aOrbiterF) + RotL64(aOrbiterI, 52U)) + aNonceWordF);
            aWandererA = aWandererA + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterG, 35U)) + aOrbiterH) + RotL64(aCarry, 5U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 60U) + RotL64(aOrbiterD, 29U)) + aOrbiterC);
            aWandererB = aWandererB + ((RotL64(aScatter, 39U) + aOrbiterH) + RotL64(aOrbiterK, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 14U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 39U) ^ aWandererF);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + (RotL64(aWandererD, 51U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererE, 43U);
            aCarry = aCarry + RotL64(aIngress, 56U);
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

void TwistExpander_Rugby_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xC8EC69FFEC18A18DULL + 0x927983EE33DC79EEULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xB396A078E1BDDB3FULL + 0x81008E967C6347F4ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xEFD6D9ECD81A71F3ULL + 0xC5B4FC5F2CF05B1DULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xBC6E7329016D50B5ULL + 0x9A98D0752B5579C9ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x86AFDB9A5F554905ULL + 0xE3455042E51D96FCULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xBD5BB1F84B2589C9ULL + 0xE01F027F7BE9759AULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xE3458ED2EB861DC9ULL + 0x9F4D7C785AD21664ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xA07787DBDFE1A239ULL + 0xAC7DF8D6F4884420ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x8ECA453B3FADB851ULL + 0xACD38CF975F6EAC9ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x89DF3AA3E6CAD8C5ULL + 0xDD6D1A318823DB1AULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xEF67CD08AC8A6143ULL + 0xEFD65552879056E8ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xE3BC7D3EDA839D55ULL + 0xF7952E95E430B70BULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xA77BB8F6F3F6543FULL + 0x8BD011E226CF2938ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xBAFF2109F468B3EDULL + 0xA5BC843A0D0B6207ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xDCE277D46712835FULL + 0xD29FA0EEE90F4B86ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xE5AB255DAF2AA18BULL + 0x9D7D26A981888520ULL);
    // GSeedRunSeed_G seed_loop_h (start)
    {
        // GSeedRunSeed_G seed_loop_h lane group
        // read from: aSnowLaneA, aSnowLaneB, aInvestLaneC, aSnowLaneC, aSnowLaneD, aFireLaneD, aWorkLaneA, aInvestLaneD, aFireLaneC, aWorkLaneB, aFireLaneA, aExpandLaneA, aFireLaneB, aExpandLaneB, aInvestLaneA, aExpandLaneC, aInvestLaneB
        // write to: aWorkLaneA, aWorkLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_h loop 1
        // ingress from: aSnowLaneA, aSnowLaneB, aInvestLaneC
        // ingress directions: aSnowLaneA forward forced, aSnowLaneB forward forced, aInvestLaneC forward/backward random
        // cross from: aSnowLaneC, aSnowLaneD, aFireLaneD
        // cross directions: aSnowLaneC backward forced, aSnowLaneD backward forced, aFireLaneD backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 2036U)) & S_BLOCK1], 21U) ^ RotL64(aSnowLaneB[((aIndex + 775U)) & S_BLOCK1], 54U));
            aIngress ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 3561U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 2697U)) & S_BLOCK1], 11U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 1411U)) & S_BLOCK1], 34U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 584U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 24U) + RotL64(aIngress, 39U)) ^ (RotL64(aPrevious, 51U) ^ RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterI = ((aWandererE + RotL64(aScatter, 50U)) + RotL64(aCarry, 13U)) + 12980104182836602177U;
            aOrbiterD = (((aWandererF + RotL64(aIngress, 27U)) + RotL64(aCarry, 51U)) + 3172622203188863995U) + aNonceWordO;
            aOrbiterB = (((aWandererB + RotL64(aCross, 57U)) + RotL64(aCarry, 35U)) + 1170974132219980203U) + aNonceWordN;
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 35U)) + 6035201940965047490U) + aPhaseHOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = ((aWandererC + RotL64(aIngress, 3U)) + 18033907118424996722U) + aNonceWordF;
            aOrbiterA = ((aWandererK + RotL64(aScatter, 19U)) + 14604813424800580304U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 41U)) + 13720232492851066035U) + aNonceWordH;
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 3902659710585257448U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 8331560652661619868U;
            aOrbiterB = RotL64((aOrbiterB * 11418103770615560205U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 4485014147538689794U) + aNonceWordP;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 168202636924512424U;
            aOrbiterE = RotL64((aOrbiterE * 13711020666131492091U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 16227825670092707848U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 4792781933944671365U;
            aOrbiterI = RotL64((aOrbiterI * 15859849676231455283U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 12636865372722601282U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterE) ^ 18198291399585556632U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterD = RotL64((aOrbiterD * 18155803890313399795U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 3650053185419807206U) + aNonceWordA;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 5897288963905408776U;
            aOrbiterC = RotL64((aOrbiterC * 3706949366974086151U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 9922308113622901726U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 13352279749091561510U;
            aOrbiterH = RotL64((aOrbiterH * 4025213180483632557U), 57U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterB) + 14969461950939646117U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordL;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 10231661776135056651U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11284575051455238501U), 51U);
            //
            aIngress = RotL64(aOrbiterI, 57U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterA, 11U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 35U));
            aIngress = aIngress + RotL64(aOrbiterD, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterB, 13U)) + aOrbiterI);
            aWandererF = aWandererF + ((((RotL64(aScatter, 58U) + aOrbiterE) + RotL64(aOrbiterD, 29U)) + RotL64(aCarry, 3U)) + aNonceWordB);
            aWandererK = aWandererK ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterB, 19U)) + aOrbiterH) + aNonceWordE);
            aWandererG = aWandererG + ((RotL64(aIngress, 37U) + aOrbiterC) + RotL64(aOrbiterA, 4U));
            aWandererD = aWandererD ^ ((((RotL64(aScatter, 51U) + RotL64(aOrbiterI, 57U)) + aOrbiterD) + aNonceWordJ) + aPhaseHWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererC = aWandererC + (((((RotL64(aIngress, 27U) + RotL64(aOrbiterE, 47U)) + aOrbiterC) + RotL64(aCarry, 35U)) + aNonceWordI) + aPhaseHWandererUpdateSaltA[((aIndex + 16U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 3U) + aOrbiterC) + RotL64(aOrbiterI, 39U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 24U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 37U));
            aCarry = aCarry + (RotL64(aWandererB, 29U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererG, 53U);
            aCarry = aCarry + RotL64(aIngress, 48U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 2
        // ingress from: aWorkLaneA, aSnowLaneC, aSnowLaneD, aInvestLaneD
        // ingress directions: aWorkLaneA forward forced, aSnowLaneC forward forced, aSnowLaneD forward forced, aInvestLaneD forward/backward random
        // cross from: aSnowLaneA, aSnowLaneB, aFireLaneC
        // cross directions: aSnowLaneA backward forced, aSnowLaneB backward forced, aFireLaneC backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 9452U)) & S_BLOCK1], 53U) ^ RotL64(aSnowLaneC[((aIndex + 5912U)) & S_BLOCK1], 35U));
            aIngress ^= (RotL64(aSnowLaneD[((aIndex + 9523U)) & S_BLOCK1], 4U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 9687U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 8615U)) & S_BLOCK1], 21U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 7084U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 9641U)) & S_BLOCK1], 12U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 34U) + RotL64(aCross, 51U)) + (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterE = (((aWandererF + RotL64(aScatter, 13U)) + 5131645209694953015U) + aPhaseHOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1]) + aNonceWordH;
            aOrbiterJ = ((aWandererK + RotL64(aIngress, 58U)) + RotL64(aCarry, 47U)) + 12070391048835379854U;
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 43U)) + RotL64(aCarry, 35U)) + 2604295836242338724U;
            aOrbiterK = ((aWandererD + RotL64(aCross, 19U)) + 14042039029284001596U) + aNonceWordI;
            aOrbiterA = (((aWandererH + RotL64(aPrevious, 29U)) + 8914654543854559327U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordD;
            aOrbiterB = ((aWandererC + RotL64(aCross, 5U)) + 2185619407969359869U) + aNonceWordC;
            aOrbiterD = ((aWandererI + RotL64(aScatter, 35U)) + RotL64(aCarry, 5U)) + 5187406295103352574U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 8022832481290871217U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 8783061916740573472U;
            aOrbiterG = RotL64((aOrbiterG * 3309891377744201773U), 35U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterE) + 10711028365596196301U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordO;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 13387065038269133571U) ^ aNonceWordM;
            aOrbiterA = RotL64((aOrbiterA * 12444578026365205255U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 11187001318931801582U) + aNonceWordL;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 14191473173276034019U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2491253922434756431U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 16207761776716426435U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 9677408414452078760U;
            aOrbiterJ = RotL64((aOrbiterJ * 5487303383095129949U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 17812460332794370649U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 7736423148554132028U;
            aOrbiterD = RotL64((aOrbiterD * 15588733747232852555U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 17293203944059014763U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 13487243633338010243U) ^ aNonceWordN;
            aOrbiterK = RotL64((aOrbiterK * 9468688858740539095U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 15979293016815060755U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 17645215484691359547U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1449450767288733995U), 53U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterA, 23U);
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 35U));
            aIngress = aIngress + RotL64(aOrbiterJ, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterE, 57U)) + aOrbiterD);
            aWandererF = aWandererF + ((((RotL64(aCross, 11U) + aOrbiterA) + RotL64(aOrbiterG, 3U)) + RotL64(aCarry, 43U)) + aPhaseHWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 51U) + aOrbiterJ) + RotL64(aOrbiterE, 21U)) + aNonceWordJ);
            aWandererD = aWandererD + ((RotL64(aScatter, 35U) + RotL64(aOrbiterE, 50U)) + aOrbiterK);
            aWandererI = aWandererI ^ ((((RotL64(aIngress, 5U) + RotL64(aOrbiterE, 13U)) + aOrbiterG) + aNonceWordF) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aScatter, 19U) + RotL64(aOrbiterD, 27U)) + aOrbiterB) + RotL64(aCarry, 3U)) + aNonceWordE);
            aWandererK = aWandererK ^ ((RotL64(aCross, 58U) + aOrbiterG) + RotL64(aOrbiterB, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererK);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 42U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 37U));
            aCarry = aCarry + RotL64(aWandererH, 53U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_h loop 3
        // ingress from: aWorkLaneB, aSnowLaneA, aFireLaneA
        // ingress directions: aWorkLaneB forward forced, aSnowLaneA forward forced, aFireLaneA forward/backward random
        // cross from: aWorkLaneA, aSnowLaneC
        // cross directions: aWorkLaneA backward forced, aSnowLaneC backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 10984U)) & S_BLOCK1], 29U) ^ RotL64(aSnowLaneA[((aIndex + 11663U)) & S_BLOCK1], 20U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 15261U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15912U)) & S_BLOCK1], 18U) ^ RotL64(aSnowLaneC[((aIndex + 12517U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 52U) ^ RotL64(aIngress, 5U)) + (RotL64(aCross, 39U) ^ RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterI = (aWandererE + RotL64(aCross, 23U)) + 4752759164691497960U;
            aOrbiterH = (aWandererF + RotL64(aPrevious, 44U)) + 12088872623537639782U;
            aOrbiterK = (((aWandererD + RotL64(aScatter, 29U)) + RotL64(aCarry, 39U)) + 3734943577379734227U) + aNonceWordN;
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 5U)) + RotL64(aCarry, 51U)) + 8854778183012444234U;
            aOrbiterG = ((aWandererA + RotL64(aCross, 13U)) + 16948373492893967275U) + aPhaseHOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 35U)) + RotL64(aCarry, 11U)) + 7962415690046184385U;
            aOrbiterC = (((aWandererH + RotL64(aIngress, 51U)) + 1872682375669714454U) + aPhaseHOrbiterAssignSaltF[((aIndex + 4U)) & S_SALT1]) + aNonceWordM;
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 7776801806943853566U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 16665439117257230732U;
            aOrbiterK = RotL64((aOrbiterK * 6866375628213114965U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 11088186766134265676U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 10850237991780969350U;
            aOrbiterF = RotL64((aOrbiterF * 7547414856143095121U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 6464817712131305812U) + aNonceWordO;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 244557182884209844U;
            aOrbiterC = RotL64((aOrbiterC * 2394270354887582889U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 13261563971157415841U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 2323811103717827362U) ^ aNonceWordD;
            aOrbiterI = RotL64((aOrbiterI * 11483723582415081925U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 12338803568475493422U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 2811342930111104982U;
            aOrbiterG = RotL64((aOrbiterG * 5020981755203607757U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 5554497011738996057U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 12712169745460598698U;
            aOrbiterJ = RotL64((aOrbiterJ * 1985586486150377769U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 17415058661427002973U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 9430421222715343818U;
            aOrbiterH = RotL64((aOrbiterH * 10321140659099470811U), 43U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterK, 21U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 43U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 13U));
            aIngress = aIngress + RotL64(aOrbiterI, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aCross, 27U) + RotL64(aOrbiterF, 35U)) + aOrbiterH) + RotL64(aCarry, 39U)) + aNonceWordL);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterJ, 20U)) + aOrbiterK);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 43U) + aOrbiterC) + RotL64(aOrbiterG, 47U)) + RotL64(aCarry, 27U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 37U) + aOrbiterI) + RotL64(aOrbiterG, 41U)) + aNonceWordA);
            aWandererB = aWandererB + ((RotL64(aCross, 51U) + RotL64(aOrbiterK, 3U)) + aOrbiterC);
            aWandererH = aWandererH ^ ((((RotL64(aScatter, 13U) + RotL64(aOrbiterI, 57U)) + aOrbiterH) + aNonceWordF) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 60U) + RotL64(aOrbiterI, 11U)) + aOrbiterK) + aNonceWordC);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + (RotL64(aWandererC, 53U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererB, 48U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererF, 5U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 4
        // ingress from: aExpandLaneA, aWorkLaneA, aFireLaneB
        // ingress directions: aExpandLaneA forward forced, aWorkLaneA forward forced, aFireLaneB forward/backward random
        // cross from: aWorkLaneB, aSnowLaneD
        // cross directions: aWorkLaneB backward forced, aSnowLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 17935U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((aIndex + 21387U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 16737U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19092U)) & S_BLOCK1], 23U) ^ RotL64(aSnowLaneD[((aIndex + 19265U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCross, 24U)) ^ (RotL64(aIngress, 39U) + RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterC = ((aWandererI + RotL64(aCross, 11U)) + 5171470532667965920U) + aPhaseHOrbiterAssignSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterA = ((aWandererA + RotL64(aIngress, 47U)) + RotL64(aCarry, 37U)) + 750549462358682403U;
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 57U)) + 3325689257577120525U) + aNonceWordB;
            aOrbiterE = (aWandererF + RotL64(aPrevious, 41U)) + 18031575461559790826U;
            aOrbiterI = ((aWandererE + RotL64(aIngress, 5U)) + 13874739537012288677U) + aNonceWordI;
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 21U)) + RotL64(aCarry, 11U)) + 4250029868785016865U;
            aOrbiterH = (((aWandererB + RotL64(aCross, 28U)) + RotL64(aCarry, 23U)) + 8211158803112611161U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 1083939790236786027U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 3446525462376962464U) ^ aNonceWordD;
            aOrbiterG = RotL64((aOrbiterG * 13603702473750888213U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 6973817815000417325U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 15230876489676945543U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7737039082964537651U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 9359727659738755880U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 8775170107816327654U) ^ aNonceWordK;
            aOrbiterI = RotL64((aOrbiterI * 6910680458261008653U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 11958941755525038545U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 16966819714283167348U;
            aOrbiterC = RotL64((aOrbiterC * 16363457661846050749U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 14556087985619763243U) + aNonceWordM;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 17915047508377045221U;
            aOrbiterH = RotL64((aOrbiterH * 6727635453185130109U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 8578745677485367222U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 7002181668717618866U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12329703532414955235U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 3569939503066735457U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 2956247934282522184U) ^ aNonceWordL;
            aOrbiterE = RotL64((aOrbiterE * 9946650822131152531U), 13U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterH, 11U);
            aIngress = aIngress + (RotL64(aOrbiterK, 34U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aScatter, 21U) + RotL64(aOrbiterE, 12U)) + aOrbiterI) + RotL64(aCarry, 29U)) + aNonceWordP);
            aWandererE = aWandererE ^ ((((RotL64(aPrevious, 58U) + aOrbiterK) + RotL64(aOrbiterH, 57U)) + aNonceWordC) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aIngress, 35U) + aOrbiterE) + RotL64(aOrbiterA, 29U)) + RotL64(aCarry, 47U)) + aNonceWordH);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 29U) + aOrbiterE) + RotL64(aOrbiterK, 37U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterH, 21U)) + aOrbiterC) + aNonceWordA) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterG, 5U)) + aOrbiterA);
            aWandererI = aWandererI + ((RotL64(aCross, 47U) + RotL64(aOrbiterC, 43U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererE);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 46U));
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererI, 37U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 22519U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((aIndex + 27271U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 22874U)) & S_BLOCK1], 42U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27099U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneA[((aIndex + 22227U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aIngress, 13U)) + (RotL64(aCarry, 26U) + RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterH = ((aWandererK + RotL64(aScatter, 3U)) + RotL64(aCarry, 11U)) + 5721224134332887360U;
            aOrbiterE = (aWandererB + RotL64(aPrevious, 35U)) + 6892749729775049095U;
            aOrbiterC = (((aWandererJ + RotL64(aIngress, 51U)) + 3884839462099556836U) + aPhaseHOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1]) + aNonceWordO;
            aOrbiterK = (aWandererF + RotL64(aCross, 19U)) + 4365431706830216193U;
            aOrbiterB = ((aWandererG + RotL64(aIngress, 58U)) + RotL64(aCarry, 27U)) + 15501528746571578773U;
            aOrbiterA = (((aWandererI + RotL64(aPrevious, 13U)) + 4505911326320650606U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordL;
            aOrbiterF = ((aWandererA + RotL64(aCross, 27U)) + RotL64(aCarry, 39U)) + 1865129050927879580U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 2011737665969640369U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 611672935827062688U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12873671551304596619U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 663547038310431047U) + aNonceWordK;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 5468932264754299556U;
            aOrbiterH = RotL64((aOrbiterH * 11968657455484578525U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 17920294117231191705U) + aNonceWordD;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 486058453837528110U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8851102552244026737U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 2789178451938129313U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 420772587981211184U;
            aOrbiterA = RotL64((aOrbiterA * 17402987842294006667U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 16196774774442181825U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 16264169656793713547U;
            aOrbiterK = RotL64((aOrbiterK * 6900221986041638783U), 27U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterA) + 10207659833859860796U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordG;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 8593749091183323678U;
            aOrbiterE = RotL64((aOrbiterE * 10696776033512404927U), 13U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterC) + 7224922076047787384U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1]) + aNonceWordI;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 15366267474865172373U;
            aOrbiterB = RotL64((aOrbiterB * 10134187073321814217U), 57U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterB, 3U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 47U));
            aIngress = aIngress + (RotL64(aOrbiterF, 37U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterC, 60U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((((RotL64(aCross, 11U) + aOrbiterK) + RotL64(aOrbiterC, 53U)) + aNonceWordF) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 60U) + aOrbiterF) + RotL64(aOrbiterE, 11U)) + RotL64(aCarry, 35U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterC, 29U)) + aOrbiterH) + aNonceWordE);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 53U) + aOrbiterK) + RotL64(aOrbiterF, 37U)) + RotL64(aCarry, 19U)) + aNonceWordC);
            aWandererJ = aWandererJ ^ ((((RotL64(aScatter, 41U) + RotL64(aOrbiterB, 23U)) + aOrbiterE) + aNonceWordH) + aPhaseHWandererUpdateSaltB[((aIndex + 26U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterA, 43U)) + aOrbiterH);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 4U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererA, 14U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererB, 19U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 6
        // ingress from: aExpandLaneC, aExpandLaneA, aInvestLaneB
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aInvestLaneB forward/backward random
        // cross from: aExpandLaneB, aSnowLaneB
        // cross directions: aExpandLaneB backward forced, aSnowLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 28044U)) & S_BLOCK1], 44U) ^ RotL64(aExpandLaneA[((aIndex + 28824U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aInvestLaneB[((aIndex + 31416U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27725U)) & S_BLOCK1], 20U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 32425U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 35U) + RotL64(aCross, 53U)) ^ (RotL64(aPrevious, 21U) ^ RotL64(aCarry, 4U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterF = ((aWandererK + RotL64(aIngress, 35U)) + RotL64(aCarry, 5U)) + 2915859148137000694U;
            aOrbiterE = (aWandererB + RotL64(aCross, 51U)) + 210680583721444425U;
            aOrbiterA = ((aWandererC + RotL64(aScatter, 41U)) + RotL64(aCarry, 35U)) + 6668118118775650387U;
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 58U)) + 15794200818099010989U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = (aWandererG + RotL64(aCross, 29U)) + 6565076707062828369U;
            aOrbiterJ = (((aWandererA + RotL64(aPrevious, 3U)) + RotL64(aCarry, 19U)) + 16323164497808856719U) + aNonceWordI;
            aOrbiterB = (((aWandererI + RotL64(aScatter, 19U)) + 7965435318816716560U) + aPhaseHOrbiterAssignSaltF[((aIndex + 20U)) & S_SALT1]) + aNonceWordL;
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 7390281030573369017U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 2269738866911824875U;
            aOrbiterA = RotL64((aOrbiterA * 1198697877998135567U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 9664014216039993873U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 18284857398028357633U) ^ aNonceWordE;
            aOrbiterC = RotL64((aOrbiterC * 8402008251343393737U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 367667619795303009U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 7935945060956274197U;
            aOrbiterF = RotL64((aOrbiterF * 5481786693511955209U), 37U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterJ) + 16683666162337789540U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordF;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 10655658270998102390U;
            aOrbiterH = RotL64((aOrbiterH * 15231596813382239841U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 8307037916581540297U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 3247742749860703524U;
            aOrbiterE = RotL64((aOrbiterE * 15052136713218656641U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 10446792483683818139U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterB) ^ 16374602929344972364U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterJ = RotL64((aOrbiterJ * 12599903932725787599U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 2411334498322777183U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 1093701164116833765U;
            aOrbiterB = RotL64((aOrbiterB * 13129220206835381729U), 5U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterF, 29U);
            aIngress = aIngress + (RotL64(aOrbiterH, 23U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 53U));
            aIngress = aIngress + RotL64(aOrbiterJ, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aCross, 27U) + aOrbiterB) + RotL64(aOrbiterH, 37U)) + RotL64(aCarry, 39U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 11U) + aOrbiterA) + RotL64(aOrbiterB, 53U));
            aWandererK = aWandererK + (((((RotL64(aIngress, 37U) + RotL64(aOrbiterE, 47U)) + aOrbiterF) + RotL64(aCarry, 53U)) + aNonceWordO) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 53U) + aOrbiterE) + RotL64(aOrbiterJ, 3U));
            aWandererG = aWandererG + (((RotL64(aIngress, 60U) + aOrbiterJ) + RotL64(aOrbiterF, 18U)) + aPhaseHWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterC, 27U)) + aOrbiterB) + aNonceWordB);
            aWandererD = aWandererD + (((RotL64(aCross, 21U) + RotL64(aOrbiterH, 11U)) + aOrbiterE) + aNonceWordN);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 24U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererD, 39U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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

void TwistExpander_Rugby_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF;
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
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE;
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 561U)) & W_KEY1], 52U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 2566U)) & W_KEY1], 23U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 2419U)) & W_KEY1], 21U) ^ RotL64(mSource[((aIndex + 749U)) & S_BLOCK1], 40U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 58U) + RotL64(aCarry, 11U)) ^ (RotL64(aCross, 35U) ^ RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = (aWandererC + RotL64(aPrevious, 35U)) + 10404808878585437255U;
            aOrbiterC = (aWandererK + RotL64(aScatter, 46U)) + 10587858736301591439U;
            aOrbiterE = ((aWandererA + RotL64(aIngress, 19U)) + RotL64(aCarry, 47U)) + 1430530909801644435U;
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 51U)) + RotL64(aCarry, 21U)) + 9090938022430118902U;
            aOrbiterG = (aWandererF + RotL64(aIngress, 13U)) + 12936604311751121235U;
            aOrbiterH = (aWandererG + RotL64(aCross, 29U)) + 1000583006020232032U;
            aOrbiterB = ((aWandererB + RotL64(aScatter, 56U)) + 12352532088997042232U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 23U)) + RotL64(aCarry, 39U)) + 16723410947058502564U;
            aOrbiterD = ((aWandererH + RotL64(aCross, 3U)) + 16614089235313154270U) + aPhaseAOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 4245553025593349277U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 3353146318549477494U;
            aOrbiterE = RotL64((aOrbiterE * 14246377408238318091U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 5935727336135635196U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 10312187090293319667U;
            aOrbiterG = RotL64((aOrbiterG * 1395964500396711899U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 12192843181244744484U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 2542570124502586365U;
            aOrbiterB = RotL64((aOrbiterB * 17222847847573534963U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 3315472769469002444U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 17512858811783071174U;
            aOrbiterH = RotL64((aOrbiterH * 9070400454074283765U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 16633218007427888082U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 2502077714838858460U;
            aOrbiterI = RotL64((aOrbiterI * 970762420815997725U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 14792910273226469214U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 15739513291150783151U;
            aOrbiterK = RotL64((aOrbiterK * 11896279674116906915U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 2192903544350345992U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 844428341223009295U;
            aOrbiterC = RotL64((aOrbiterC * 4768368713974002539U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 2998511458298901402U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 7790789639864783373U;
            aOrbiterD = RotL64((aOrbiterD * 9173097618440495497U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 4540735375055164995U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 13700342877362633034U;
            aOrbiterJ = RotL64((aOrbiterJ * 14730797752841670505U), 57U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterG, 36U);
            aIngress = aIngress + (RotL64(aOrbiterH, 5U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterK, 27U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 41U));
            aIngress = aIngress + RotL64(aOrbiterI, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aPrevious, 27U) + aOrbiterB) + RotL64(aOrbiterC, 43U)) + RotL64(aCarry, 41U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 5U) + aOrbiterK) + RotL64(aOrbiterG, 13U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 52U) + RotL64(aOrbiterH, 54U)) + aOrbiterB) + RotL64(aCarry, 11U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterE, 27U)) + aOrbiterJ);
            aWandererH = aWandererH + (((RotL64(aCross, 35U) + RotL64(aOrbiterI, 23U)) + aOrbiterH) + aPhaseAWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 41U) + aOrbiterD) + RotL64(aOrbiterJ, 39U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterG, 47U)) + aOrbiterD) + aPhaseAWandererUpdateSaltA[((aIndex + 28U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 60U) + aOrbiterE) + RotL64(aOrbiterH, 19U));
            aWandererB = aWandererB + ((RotL64(aCross, 47U) + aOrbiterE) + RotL64(aOrbiterG, 58U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 30U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + RotL64(aWandererI, 27U);
            aCarry = aCarry + RotL64(aIngress, 18U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 4282U)) & S_BLOCK1], 37U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 4933U)) & W_KEY1], 58U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 3816U)) & W_KEY1], 10U) ^ RotL64(mSource[((aIndex + 3078U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 43U) + RotL64(aCross, 29U)) ^ (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 14U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = (aWandererF + RotL64(aIngress, 60U)) + 9023059520606551446U;
            aOrbiterB = (aWandererB + RotL64(aCross, 51U)) + 662441755115638133U;
            aOrbiterI = (aWandererD + RotL64(aPrevious, 43U)) + 16957253361196144712U;
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 35U)) + RotL64(aCarry, 23U)) + 7840955025765308605U;
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 29U)) + RotL64(aCarry, 3U)) + 346855809270395799U;
            aOrbiterK = (aWandererH + RotL64(aIngress, 56U)) + 16099139781586668343U;
            aOrbiterA = ((aWandererC + RotL64(aScatter, 3U)) + 3706457327118322098U) + aPhaseAOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = ((aWandererK + RotL64(aCross, 19U)) + RotL64(aCarry, 51U)) + 12166825885547622870U;
            aOrbiterD = ((aWandererI + RotL64(aScatter, 13U)) + 7792658665720344200U) + aPhaseAOrbiterAssignSaltE[((aIndex + 22U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 7128477606152986326U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 11116533962780290084U;
            aOrbiterI = RotL64((aOrbiterI * 11993485572912492297U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 10443889548568288532U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 4402387036946561017U;
            aOrbiterB = RotL64((aOrbiterB * 9032964741841833277U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 13002706161178447654U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 13929727277530310708U;
            aOrbiterF = RotL64((aOrbiterF * 7005639090871200285U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 10949073760696935106U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 15405923432006783533U;
            aOrbiterC = RotL64((aOrbiterC * 17989565878445202495U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 18096057968822208905U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 3032155040484574973U;
            aOrbiterJ = RotL64((aOrbiterJ * 448597307502544605U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 17462076466907467134U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 15471015427013701406U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6113474000571976139U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 3549031751266594344U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 14243218483842508113U;
            aOrbiterD = RotL64((aOrbiterD * 9041601306479302047U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 5803147589312920032U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 5549470512227427855U;
            aOrbiterK = RotL64((aOrbiterK * 12592362489263862879U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 10076661824293832189U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 3196799148974716550U;
            aOrbiterA = RotL64((aOrbiterA * 8183276968961467775U), 19U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterH, 27U);
            aIngress = aIngress + (RotL64(aOrbiterK, 23U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 43U));
            aIngress = aIngress + (RotL64(aOrbiterA, 19U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterC, 4U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterI, 39U)) + aOrbiterH);
            aWandererC = aWandererC + ((RotL64(aPrevious, 3U) + aOrbiterA) + RotL64(aOrbiterH, 60U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterJ, 11U)) + aOrbiterI);
            aWandererI = aWandererI + (((RotL64(aCross, 46U) + RotL64(aOrbiterC, 35U)) + aOrbiterD) + RotL64(aCarry, 39U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 51U) + aOrbiterI) + RotL64(aOrbiterF, 3U)) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 37U) + aOrbiterK) + RotL64(aOrbiterB, 19U)) + aPhaseAWandererUpdateSaltC[((aIndex + 6U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterJ, 47U)) + aOrbiterC);
            aWandererD = aWandererD + (((RotL64(aScatter, 11U) + aOrbiterK) + RotL64(aOrbiterH, 56U)) + RotL64(aCarry, 5U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 42U) + aOrbiterK) + RotL64(aOrbiterC, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 41U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererJ, 38U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererI, 35U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 5681U)) & S_BLOCK1], 51U) ^ RotL64(aKeyRowReadB[((aIndex + 8095U)) & W_KEY1], 10U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 5910U)) & W_KEY1], 13U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 7037U)) & S_BLOCK1], 46U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 7867U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 3U) ^ RotL64(aPrevious, 34U)) ^ (RotL64(aIngress, 51U) + RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 41U)) + RotL64(aCarry, 41U)) + 18144572925667544139U;
            aOrbiterA = (aWandererH + RotL64(aCross, 37U)) + 5659758077574059728U;
            aOrbiterD = (aWandererF + RotL64(aIngress, 60U)) + 6343330616999166392U;
            aOrbiterH = (aWandererE + RotL64(aScatter, 27U)) + 17754639838410839447U;
            aOrbiterC = (((aWandererJ + RotL64(aCross, 47U)) + RotL64(aCarry, 51U)) + 9451843819849581729U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = ((aWandererG + RotL64(aScatter, 5U)) + 7957854457197462212U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = (aWandererB + RotL64(aPrevious, 13U)) + 1461994799722205010U;
            aOrbiterG = (aWandererI + RotL64(aIngress, 23U)) + 18002214276252170177U;
            aOrbiterE = ((aWandererD + RotL64(aScatter, 54U)) + RotL64(aCarry, 23U)) + 14689869073147027164U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 3978104368003440293U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 8512135845221335386U;
            aOrbiterD = RotL64((aOrbiterD * 10506667163729414667U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 1477533446382953439U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 2166717790929947990U;
            aOrbiterF = RotL64((aOrbiterF * 6538884492418324461U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 8082437060686606995U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 4363687722464700362U;
            aOrbiterG = RotL64((aOrbiterG * 7199165810993478887U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 15782763348014924206U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 8572509150015960728U;
            aOrbiterJ = RotL64((aOrbiterJ * 3340528604891897779U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 12248271773316742521U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 9602078627638561949U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1860631869877427405U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 17244849374768558859U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 1030743048280579012U;
            aOrbiterH = RotL64((aOrbiterH * 10858949914285817051U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 17722342363541914280U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 15667504059789880034U;
            aOrbiterE = RotL64((aOrbiterE * 15872269872168533709U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 12645332941998550794U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 9938135244509986497U;
            aOrbiterC = RotL64((aOrbiterC * 16548185968987392957U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 4024609904162105979U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 6732064218696157303U;
            aOrbiterB = RotL64((aOrbiterB * 3815409766145891393U), 39U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterE, 35U);
            aIngress = aIngress + (RotL64(aOrbiterD, 5U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + RotL64(aOrbiterJ, 18U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterB, 58U)) + aOrbiterC);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 34U) + RotL64(aOrbiterB, 53U)) + aOrbiterJ);
            aWandererB = aWandererB + ((((RotL64(aCross, 11U) + aOrbiterJ) + RotL64(aOrbiterA, 29U)) + RotL64(aCarry, 19U)) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterB, 19U)) + aOrbiterD);
            aWandererA = aWandererA + (((RotL64(aPrevious, 19U) + aOrbiterE) + RotL64(aOrbiterD, 23U)) + RotL64(aCarry, 35U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterE, 13U)) + aOrbiterG) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 23U) + RotL64(aOrbiterJ, 42U)) + aOrbiterG);
            aWandererG = aWandererG ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterH, 37U)) + aOrbiterB);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 44U) + aOrbiterA) + RotL64(aOrbiterF, 5U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererH);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 26U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 21U));
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 9266U)) & S_BLOCK1], 47U) ^ RotL64(aKeyRowReadB[((aIndex + 10554U)) & W_KEY1], 39U));
            aIngress ^= (RotL64(mSource[((aIndex + 10168U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 9119U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 10664U)) & W_KEY1], 50U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 9701U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aIngress, 60U)) ^ (RotL64(aPrevious, 23U) + RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = (aWandererE + RotL64(aPrevious, 10U)) + 7893287783892523139U;
            aOrbiterI = (aWandererH + RotL64(aScatter, 57U)) + 10257331997383491153U;
            aOrbiterC = (aWandererD + RotL64(aIngress, 27U)) + 14562226733652231753U;
            aOrbiterB = (aWandererC + RotL64(aCross, 23U)) + 14320342577110737851U;
            aOrbiterF = (((aWandererJ + RotL64(aIngress, 53U)) + RotL64(aCarry, 35U)) + 9816717579822880756U) + aPhaseBOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 4U)) + RotL64(aCarry, 11U)) + 9558926960095881953U;
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 47U)) + RotL64(aCarry, 53U)) + 9230371862654338324U;
            aOrbiterG = ((aWandererK + RotL64(aCross, 19U)) + 6414274291252913420U) + aPhaseBOrbiterAssignSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterH = (aWandererB + RotL64(aPrevious, 39U)) + 13868546184398350849U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 16940736952569949038U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 2866957764814864371U;
            aOrbiterC = RotL64((aOrbiterC * 3554702178644797003U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 7916721976073979724U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 1602444214978842275U;
            aOrbiterF = RotL64((aOrbiterF * 11072503711308122385U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 9529061385251008037U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 8402775110887376588U;
            aOrbiterB = RotL64((aOrbiterB * 13980225144628227381U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 15003592180290390713U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 14195681406520825751U;
            aOrbiterD = RotL64((aOrbiterD * 11455000833788877217U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 3263577002367714202U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 12019422062655581928U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5002313835338447799U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 8508638054582582917U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 6536618106353552880U;
            aOrbiterH = RotL64((aOrbiterH * 6233964121117511885U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 9654542989321430868U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 7019594782797863244U;
            aOrbiterI = RotL64((aOrbiterI * 1234877854354279981U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 8256061220727519919U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 9232754129467036130U;
            aOrbiterA = RotL64((aOrbiterA * 17556001874302369781U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 5608829951337740378U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 12632120498473345701U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6994794653605831925U), 5U);
            //
            aIngress = RotL64(aOrbiterH, 47U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterD, 27U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 54U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 35U));
            aIngress = aIngress + RotL64(aOrbiterF, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 54U) + RotL64(aOrbiterI, 14U)) + aOrbiterA);
            aWandererA = aWandererA + ((RotL64(aCross, 43U) + aOrbiterC) + RotL64(aOrbiterA, 29U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterC, 51U)) + aOrbiterB);
            aWandererB = aWandererB + (((RotL64(aIngress, 23U) + aOrbiterH) + RotL64(aOrbiterA, 23U)) + RotL64(aCarry, 29U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterC, 35U)) + aOrbiterD);
            aWandererE = aWandererE + ((RotL64(aIngress, 35U) + aOrbiterJ) + RotL64(aOrbiterA, 41U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 50U) + RotL64(aOrbiterJ, 56U)) + aOrbiterG);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 27U) + aOrbiterH) + RotL64(aOrbiterG, 3U)) + RotL64(aCarry, 47U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterC, 47U)) + aOrbiterF) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 40U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererC, 27U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 13259U)) & S_BLOCK1], 19U) ^ RotL64(aKeyRowReadA[((aIndex + 12450U)) & W_KEY1], 38U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 13210U)) & W_KEY1], 11U) ^ RotL64(mSource[((aIndex + 10976U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 11343U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11341U)) & S_BLOCK1], 19U) ^ RotL64(aInvestLaneA[((aIndex + 13177U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 47U) + RotL64(aCross, 29U)) ^ (RotL64(aIngress, 60U) ^ RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = (aWandererH + RotL64(aScatter, 46U)) + 15920462086654025436U;
            aOrbiterG = (aWandererK + RotL64(aPrevious, 41U)) + 487844076858004017U;
            aOrbiterJ = ((aWandererD + RotL64(aCross, 11U)) + RotL64(aCarry, 57U)) + 14502883786442630566U;
            aOrbiterD = (aWandererC + RotL64(aIngress, 53U)) + 3787107318658233674U;
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 27U)) + 12548777544693755491U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = (aWandererJ + RotL64(aScatter, 3U)) + 4907309444075181683U;
            aOrbiterB = ((aWandererI + RotL64(aCross, 37U)) + 18342396700266492072U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = ((aWandererB + RotL64(aIngress, 21U)) + RotL64(aCarry, 43U)) + 13503051997624242670U;
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 58U)) + RotL64(aCarry, 19U)) + 17845742460521374571U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 8640887211877858169U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 5273913123709097537U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1661149444148461791U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 17756844173695563883U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 6713055830729302951U;
            aOrbiterH = RotL64((aOrbiterH * 2832836748513174311U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 5106468334224035972U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 10228769728713526172U;
            aOrbiterB = RotL64((aOrbiterB * 9760310686414358435U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 7687649520668883142U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 7757480627354711605U;
            aOrbiterD = RotL64((aOrbiterD * 7222553727737349209U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 10876291698508634557U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 8149278085586014186U;
            aOrbiterI = RotL64((aOrbiterI * 8577133863470695381U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 15592893988925610485U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 8639028256640537165U;
            aOrbiterC = RotL64((aOrbiterC * 1880655276432963955U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 475660347892196219U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 1903736092401853832U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8486318978769094799U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 12463250192809450953U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 7253918448601703982U;
            aOrbiterG = RotL64((aOrbiterG * 3821034106528009129U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 5171661020093804486U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 11627344933828324146U;
            aOrbiterE = RotL64((aOrbiterE * 5388047063152043277U), 3U);
            //
            aIngress = RotL64(aOrbiterB, 47U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + (RotL64(aOrbiterC, 58U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + RotL64(aOrbiterG, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterJ, 39U)) + aOrbiterD);
            aWandererD = aWandererD + ((RotL64(aCross, 3U) + aOrbiterI) + RotL64(aOrbiterK, 48U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 10U) + aOrbiterK) + RotL64(aOrbiterG, 53U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterH, 35U)) + aPhaseBWandererUpdateSaltB[((aIndex + 26U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterH, 19U)) + aOrbiterK) + aPhaseBWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 29U) + aOrbiterJ) + RotL64(aOrbiterI, 13U)) + RotL64(aCarry, 27U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterE, 5U)) + aOrbiterB);
            aWandererK = aWandererK + (((RotL64(aPrevious, 14U) + RotL64(aOrbiterB, 43U)) + aOrbiterG) + RotL64(aCarry, 37U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterD, 58U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererI);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + (RotL64(aWandererC, 24U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererA, 19U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 15366U)) & S_BLOCK1], 4U) ^ RotL64(aInvestLaneA[((aIndex + 14156U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15404U)) & W_KEY1], 21U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 15018U)) & W_KEY1], 51U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 15921U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 14219U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 14326U)) & S_BLOCK1], 6U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aIngress, 3U)) ^ (RotL64(aCarry, 23U) + RotL64(aPrevious, 38U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = (aWandererI + RotL64(aCross, 14U)) + 12692813903177772178U;
            aOrbiterI = (aWandererD + RotL64(aIngress, 35U)) + 7112496446691277899U;
            aOrbiterA = (aWandererA + RotL64(aPrevious, 3U)) + 2112247138290568813U;
            aOrbiterD = (aWandererC + RotL64(aScatter, 23U)) + 3699421080882855947U;
            aOrbiterC = (((aWandererF + RotL64(aCross, 51U)) + RotL64(aCarry, 37U)) + 13761832028354380922U) + aPhaseBOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = (((aWandererH + RotL64(aPrevious, 44U)) + RotL64(aCarry, 21U)) + 9243822514887600214U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = ((aWandererB + RotL64(aIngress, 39U)) + RotL64(aCarry, 3U)) + 6863833516853046129U;
            aOrbiterB = (aWandererK + RotL64(aScatter, 19U)) + 8863897995943098018U;
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 27U)) + 13346785686701467520U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 15309543066305531619U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 17515530938817919111U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16625193986319048245U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 760493237816424254U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 7282586354117620860U;
            aOrbiterC = RotL64((aOrbiterC * 2327153408185290635U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 4129706068526969105U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 7020175432730888755U;
            aOrbiterE = RotL64((aOrbiterE * 10095158356907592239U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 9102258982216515596U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 10822031305361453690U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2036205056490578491U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 12571477440964330246U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 8436347026653095199U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17930734781213681573U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 14214789872073941940U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 12915911919403385001U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13161681603528031511U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 15443240166233851298U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 7311369180113240915U;
            aOrbiterB = RotL64((aOrbiterB * 13339195007946889423U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 12976516224995960015U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 7823308381434556721U;
            aOrbiterG = RotL64((aOrbiterG * 502385172763861451U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 4829417661664149137U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 16306394751966719700U;
            aOrbiterD = RotL64((aOrbiterD * 5294376579588592157U), 57U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterI, 35U);
            aIngress = aIngress + (RotL64(aOrbiterK, 24U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 19U));
            aIngress = aIngress + (RotL64(aOrbiterC, 29U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterF, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterG, 10U)) + aOrbiterI);
            aWandererK = aWandererK + ((RotL64(aCross, 51U) + aOrbiterD) + RotL64(aOrbiterI, 35U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 13U) + aOrbiterB) + RotL64(aOrbiterA, 51U)) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aIngress, 58U) + RotL64(aOrbiterF, 3U)) + aOrbiterC);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 23U) + aOrbiterE) + RotL64(aOrbiterB, 23U));
            aWandererB = aWandererB + ((((RotL64(aIngress, 19U) + RotL64(aOrbiterD, 27U)) + aOrbiterG) + RotL64(aCarry, 13U)) + aPhaseBWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterD, 39U)) + aOrbiterK);
            aWandererC = aWandererC + (((RotL64(aPrevious, 42U) + RotL64(aOrbiterF, 43U)) + aOrbiterA) + RotL64(aCarry, 29U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterB, 56U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 27U));
            aCarry = aCarry + (RotL64(aWandererK, 10U) ^ aWandererF);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 16892U)) & S_BLOCK1], 57U) ^ RotL64(aKeyRowReadA[((aIndex + 17703U)) & W_KEY1], 13U));
            aIngress ^= (RotL64(mSource[((aIndex + 18404U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16735U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 18902U)) & W_KEY1], 12U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 17141U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 16588U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 21U) + RotL64(aCross, 3U)) ^ (RotL64(aPrevious, 47U) + RotL64(aCarry, 34U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = (aWandererE + RotL64(aScatter, 11U)) + 2617613537256538553U;
            aOrbiterH = ((aWandererI + RotL64(aIngress, 44U)) + 16642868916835132715U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = (aWandererJ + RotL64(aPrevious, 57U)) + 10860291124337073254U;
            aOrbiterD = (aWandererD + RotL64(aCross, 35U)) + 6432511273906902472U;
            aOrbiterI = ((aWandererF + RotL64(aIngress, 3U)) + RotL64(aCarry, 39U)) + 7505375005848241910U;
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 19U)) + 11086616004678821329U;
            aOrbiterE = (aWandererK + RotL64(aScatter, 23U)) + 3298830587569881951U;
            aOrbiterC = (((aWandererG + RotL64(aCross, 39U)) + RotL64(aCarry, 27U)) + 9775143140064220979U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = ((aWandererC + RotL64(aScatter, 48U)) + RotL64(aCarry, 11U)) + 4147601326580823120U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 12245920269898100415U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 8391940489176734499U;
            aOrbiterF = RotL64((aOrbiterF * 9119606167674098007U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 17876893379544668477U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 18301882058180370541U;
            aOrbiterJ = RotL64((aOrbiterJ * 16680384667098921309U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 6869225862715140102U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 15404118372589259800U;
            aOrbiterI = RotL64((aOrbiterI * 5766851935950389915U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 17757381020518233814U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 17677969146092374455U;
            aOrbiterD = RotL64((aOrbiterD * 3469432916562405063U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 15783378556632870114U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 5792858258663697864U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12008981883482080427U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 11737803388202260296U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 16001927091970715330U;
            aOrbiterC = RotL64((aOrbiterC * 3062030309852922061U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 1749586939123286632U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 6169421068855905938U;
            aOrbiterK = RotL64((aOrbiterK * 12374789910763348695U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 10073586820719728062U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 17744171227198661555U;
            aOrbiterH = RotL64((aOrbiterH * 10658375268803957647U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 1149819647337612792U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 7725598665625892006U;
            aOrbiterB = RotL64((aOrbiterB * 15097586655234391559U), 23U);
            //
            aIngress = RotL64(aOrbiterB, 43U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterD, 20U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 13U));
            aIngress = aIngress + RotL64(aOrbiterI, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 22U) + aOrbiterJ) + RotL64(aOrbiterI, 11U));
            aWandererD = aWandererD + (((RotL64(aCross, 37U) + RotL64(aOrbiterD, 39U)) + aOrbiterJ) + RotL64(aCarry, 37U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterE, 57U)) + aOrbiterI);
            aWandererK = aWandererK + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterF, 18U)) + aOrbiterH);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 57U) + aOrbiterB) + RotL64(aOrbiterH, 47U)) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aCross, 53U) + aOrbiterC) + RotL64(aOrbiterE, 53U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 18U) + aOrbiterI) + RotL64(aOrbiterK, 27U)) + aPhaseCWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 5U) + RotL64(aOrbiterF, 4U)) + aOrbiterB) + RotL64(aCarry, 13U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterC, 23U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 36U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererI);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + RotL64(aWandererJ, 13U);
            aCarry = aCarry + RotL64(aIngress, 26U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 20443U)) & S_BLOCK1], 51U) ^ RotL64(mSource[((aIndex + 19859U)) & S_BLOCK1], 22U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 21726U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19649U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 19139U)) & W_KEY1], 53U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 19641U)) & W_KEY1], 30U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 19544U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20938U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 21U) + RotL64(aIngress, 35U)) + (RotL64(aPrevious, 52U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = ((aWandererG + RotL64(aCross, 53U)) + 2783898056762489197U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 5U)) + RotL64(aCarry, 29U)) + 7177192902873343053U;
            aOrbiterI = (aWandererA + RotL64(aIngress, 26U)) + 12254703232691980774U;
            aOrbiterA = ((aWandererE + RotL64(aScatter, 57U)) + RotL64(aCarry, 19U)) + 15446547245691219559U;
            aOrbiterH = (aWandererC + RotL64(aPrevious, 19U)) + 888475203006174856U;
            aOrbiterK = ((aWandererK + RotL64(aCross, 35U)) + RotL64(aCarry, 43U)) + 3649183529366307877U;
            aOrbiterG = (aWandererB + RotL64(aScatter, 47U)) + 4642631047518805167U;
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 42U)) + 6108329730724782250U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterC = (aWandererH + RotL64(aCross, 13U)) + 8334054653023816636U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 5891895375031474350U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 3176720746238477862U;
            aOrbiterI = RotL64((aOrbiterI * 1869961473768307911U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 6111038696865301675U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 11914998302228682704U;
            aOrbiterH = RotL64((aOrbiterH * 11738924766359642853U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 17005063057791320948U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 18333780598768130670U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5416759844884107303U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 2056115016443263153U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 10245512728872962677U;
            aOrbiterD = RotL64((aOrbiterD * 707106795383284903U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 4810366069422162351U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 3051442983125942469U;
            aOrbiterJ = RotL64((aOrbiterJ * 13558537578054436423U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 9285068547223654308U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 13067251130180968842U;
            aOrbiterG = RotL64((aOrbiterG * 7000687697769766605U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 3203670242792002165U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 1770881716916463461U;
            aOrbiterC = RotL64((aOrbiterC * 13870229847371882171U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 16286823712870537410U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 13067191141829694202U;
            aOrbiterE = RotL64((aOrbiterE * 15629974528467350445U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 3414576315085336932U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 8979691827341555245U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15971594804040295757U), 57U);
            //
            aIngress = RotL64(aOrbiterE, 23U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 11U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 6U));
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterG, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterK, 6U)) + aOrbiterI);
            aWandererC = aWandererC + ((RotL64(aScatter, 47U) + RotL64(aOrbiterA, 43U)) + aOrbiterC);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 42U) + RotL64(aOrbiterD, 51U)) + aOrbiterE);
            aWandererJ = aWandererJ + (((RotL64(aCross, 11U) + aOrbiterI) + RotL64(aOrbiterJ, 29U)) + RotL64(aCarry, 41U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 23U) + aOrbiterH) + RotL64(aOrbiterI, 11U));
            aWandererG = aWandererG + (((RotL64(aCross, 57U) + RotL64(aOrbiterG, 24U)) + aOrbiterK) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 35U) + aOrbiterD) + RotL64(aOrbiterJ, 19U));
            aWandererE = aWandererE + ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterE, 37U)) + aOrbiterC) + RotL64(aCarry, 5U)) + aPhaseCWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 52U) + aOrbiterJ) + RotL64(aOrbiterH, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 10U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + RotL64(aWandererJ, 39U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 24260U)) & S_BLOCK1], 42U) ^ RotL64(aKeyRowReadA[((aIndex + 22776U)) & W_KEY1], 29U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 23814U)) & W_KEY1], 57U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 22868U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 22317U)) & S_BLOCK1], 24U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 22780U)) & S_BLOCK1], 13U));
            aCross ^= (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 22608U)) & S_BLOCK1], 43U) ^ RotL64(aInvestLaneB[((aIndex + 24512U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aIngress, 56U)) ^ (RotL64(aCross, 37U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = (aWandererK + RotL64(aCross, 18U)) + 4752759164691497960U;
            aOrbiterC = ((aWandererG + RotL64(aScatter, 23U)) + RotL64(aCarry, 57U)) + 12088872623537639782U;
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 29U)) + 3734943577379734227U) + aPhaseCOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = (aWandererJ + RotL64(aIngress, 57U)) + 8854778183012444234U;
            aOrbiterB = (aWandererC + RotL64(aScatter, 5U)) + 16948373492893967275U;
            aOrbiterA = ((aWandererA + RotL64(aCross, 41U)) + RotL64(aCarry, 47U)) + 7962415690046184385U;
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 47U)) + 1872682375669714454U) + aPhaseCOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = ((aWandererI + RotL64(aIngress, 52U)) + RotL64(aCarry, 11U)) + 7776801806943853566U;
            aOrbiterJ = (aWandererF + RotL64(aScatter, 37U)) + 16665439117257230732U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 11088186766134265676U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 10850237991780969350U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7547414856143095121U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 6464817712131305812U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 244557182884209844U;
            aOrbiterB = RotL64((aOrbiterB * 2394270354887582889U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 13261563971157415841U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 2323811103717827362U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11483723582415081925U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 12338803568475493422U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 2811342930111104982U;
            aOrbiterJ = RotL64((aOrbiterJ * 5020981755203607757U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 5554497011738996057U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 12712169745460598698U;
            aOrbiterG = RotL64((aOrbiterG * 1985586486150377769U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 17415058661427002973U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 9430421222715343818U;
            aOrbiterD = RotL64((aOrbiterD * 10321140659099470811U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 3926618548181233180U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 6172453297026957838U;
            aOrbiterA = RotL64((aOrbiterA * 1161551082037835233U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 8633288765997226004U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 17270881130844274342U;
            aOrbiterI = RotL64((aOrbiterI * 8888559940161770791U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 12232950994807835262U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 15352600312956742750U;
            aOrbiterC = RotL64((aOrbiterC * 6140396356904933003U), 37U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterC, 29U);
            aIngress = aIngress + (RotL64(aOrbiterD, 36U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 13U));
            aIngress = aIngress + RotL64(aOrbiterI, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterB, 53U)) + aOrbiterI);
            aWandererA = aWandererA + (((RotL64(aScatter, 46U) + aOrbiterJ) + RotL64(aOrbiterC, 14U)) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterH, 3U)) + aOrbiterC);
            aWandererD = aWandererD + ((RotL64(aCross, 29U) + aOrbiterK) + RotL64(aOrbiterD, 27U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterI, 43U)) + aOrbiterC);
            aWandererI = aWandererI + (((RotL64(aCross, 39U) + aOrbiterK) + RotL64(aOrbiterC, 39U)) + RotL64(aCarry, 41U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 5U) + aOrbiterI) + RotL64(aOrbiterA, 23U)) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 19U) + RotL64(aOrbiterC, 47U)) + aOrbiterA);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 14U) + RotL64(aOrbiterH, 18U)) + aOrbiterG) + aPhaseCWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 37U) ^ aWandererK);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 23U));
            aCarry = aCarry + (RotL64(aWandererD, 41U) ^ aWandererG);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + RotL64(aWandererC, 53U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 25295U)) & S_BLOCK1], 12U) ^ RotL64(aKeyRowReadA[((aIndex + 25250U)) & W_KEY1], 57U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 27201U)) & S_BLOCK1], 27U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 26936U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 26193U)) & W_KEY1], 51U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 24790U)) & S_BLOCK1], 5U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 26781U)) & S_BLOCK1], 43U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 26072U)) & S_BLOCK1], 28U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aIngress, 11U)) ^ (RotL64(aCross, 40U) + RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = ((aWandererH + RotL64(aScatter, 43U)) + 4179952823252098240U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = ((aWandererF + RotL64(aIngress, 18U)) + RotL64(aCarry, 53U)) + 3745613452332101749U;
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 39U)) + RotL64(aCarry, 3U)) + 2955689793395307176U;
            aOrbiterH = (aWandererG + RotL64(aCross, 23U)) + 5639060180251322019U;
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 13U)) + 7901969163853586463U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = (aWandererE + RotL64(aIngress, 57U)) + 2242166787816318119U;
            aOrbiterD = (aWandererA + RotL64(aCross, 27U)) + 5239936443960750064U;
            aOrbiterB = (aWandererB + RotL64(aPrevious, 52U)) + 13939136954732185558U;
            aOrbiterI = ((aWandererC + RotL64(aCross, 47U)) + RotL64(aCarry, 23U)) + 17058884136712717463U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 18148618660054585941U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 7022023484530327814U;
            aOrbiterE = RotL64((aOrbiterE * 650100011311048589U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 7722084537340095637U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 11764151879690934182U;
            aOrbiterF = RotL64((aOrbiterF * 12264384877711365655U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 16412785901758144708U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 9666718667728274824U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10865799822751771795U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 4307127540152109364U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 2457646804702647606U;
            aOrbiterB = RotL64((aOrbiterB * 6340030928007058595U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 3179394870088602208U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 504977947273774249U;
            aOrbiterH = RotL64((aOrbiterH * 16190282058883481551U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 16182729401018310837U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 7110817020445860609U;
            aOrbiterD = RotL64((aOrbiterD * 13371352088428584087U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 12960656706837391973U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 7103806893724395904U;
            aOrbiterC = RotL64((aOrbiterC * 14365984439655979791U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 1248300178080633527U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 7195473175424961337U;
            aOrbiterK = RotL64((aOrbiterK * 4633558992739305045U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 13007951568242991449U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 10296811247653636372U;
            aOrbiterI = RotL64((aOrbiterI * 16469682651380549395U), 47U);
            //
            aIngress = RotL64(aOrbiterE, 19U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 35U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 27U));
            aIngress = aIngress + (RotL64(aOrbiterC, 39U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterH, 24U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aIngress, 35U) + aOrbiterC) + RotL64(aOrbiterG, 41U)) + RotL64(aCarry, 21U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 22U) + RotL64(aOrbiterK, 14U)) + aOrbiterH);
            aWandererC = aWandererC + (((RotL64(aScatter, 27U) + RotL64(aOrbiterD, 29U)) + aOrbiterB) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterE, 21U)) + aOrbiterK);
            aWandererH = aWandererH + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterK, 53U)) + aOrbiterD);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterI, 3U)) + aOrbiterF);
            aWandererD = aWandererD + ((((RotL64(aScatter, 58U) + aOrbiterG) + RotL64(aOrbiterD, 47U)) + RotL64(aCarry, 29U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterB, 60U)) + aOrbiterI);
            aWandererB = aWandererB + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterF, 35U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererG);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 52U));
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererE, 57U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 28549U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneD[((aIndex + 27530U)) & S_BLOCK1], 35U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 29790U)) & W_KEY1], 19U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 27459U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 27425U)) & W_KEY1], 21U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 27544U)) & S_BLOCK1], 57U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29959U)) & S_BLOCK1], 4U) ^ RotL64(aFireLaneB[((aIndex + 28632U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 38U) ^ RotL64(aCross, 3U)) + (RotL64(aCarry, 51U) ^ RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = (aWandererA + RotL64(aPrevious, 47U)) + 11480359716598965890U;
            aOrbiterI = (aWandererJ + RotL64(aScatter, 51U)) + 15431182525482873419U;
            aOrbiterE = (aWandererI + RotL64(aCross, 5U)) + 11360504974812776707U;
            aOrbiterD = (((aWandererC + RotL64(aIngress, 30U)) + RotL64(aCarry, 35U)) + 9292576416573382769U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterH = ((aWandererF + RotL64(aScatter, 41U)) + RotL64(aCarry, 53U)) + 1549257414531028975U;
            aOrbiterJ = (aWandererK + RotL64(aIngress, 37U)) + 5347769463033129317U;
            aOrbiterB = (aWandererE + RotL64(aCross, 13U)) + 17019199177478377234U;
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 60U)) + RotL64(aCarry, 27U)) + 16558106007323125094U;
            aOrbiterG = ((aWandererG + RotL64(aCross, 19U)) + 3976182233825939422U) + aPhaseDOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1];
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 2889047161195954395U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 2241831345026962605U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5757458560979927857U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 12850802412140579294U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 13541744735436450160U;
            aOrbiterJ = RotL64((aOrbiterJ * 906089290000537439U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 2085863085516538212U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 2969034221711544086U;
            aOrbiterC = RotL64((aOrbiterC * 7768528124408400403U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 6482666944512391472U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 16969153556875844613U;
            aOrbiterH = RotL64((aOrbiterH * 9483462388353216219U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 5161314086757363678U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 7150282484670673211U;
            aOrbiterF = RotL64((aOrbiterF * 8522427002337918663U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 5465304381272305847U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 2344610773390354017U;
            aOrbiterD = RotL64((aOrbiterD * 17010258514288089191U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 8335906578006588582U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 13668796013474193793U;
            aOrbiterG = RotL64((aOrbiterG * 8228000547141147777U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 9663362594301419686U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 3683773739120343413U;
            aOrbiterB = RotL64((aOrbiterB * 8319320803406104749U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 2538583190438044942U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 4454069062219406996U;
            aOrbiterI = RotL64((aOrbiterI * 16329554225309389599U), 57U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterC, 50U);
            aIngress = aIngress + (RotL64(aOrbiterI, 5U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 41U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + RotL64(aOrbiterF, 54U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aIngress, 47U) + aOrbiterD) + RotL64(aOrbiterE, 52U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterJ, 19U)) + aOrbiterI) + aPhaseDWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 43U) + aOrbiterJ) + RotL64(aOrbiterE, 5U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 53U) + aOrbiterE) + RotL64(aOrbiterC, 11U));
            aWandererF = aWandererF + (((RotL64(aScatter, 24U) + aOrbiterH) + RotL64(aOrbiterC, 60U)) + RotL64(aCarry, 47U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 5U) + aOrbiterF) + RotL64(aOrbiterH, 47U));
            aWandererA = aWandererA + (((RotL64(aIngress, 19U) + RotL64(aOrbiterG, 23U)) + aOrbiterI) + RotL64(aCarry, 29U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterF, 39U)) + aOrbiterI);
            aWandererG = aWandererG + ((RotL64(aScatter, 30U) + RotL64(aOrbiterB, 29U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererA);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 54U));
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererJ, 13U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 30314U)) & S_BLOCK1], 14U) ^ RotL64(aKeyRowReadA[((aIndex + 31997U)) & W_KEY1], 53U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 31352U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32470U)) & S_BLOCK1], 46U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30407U)) & S_BLOCK1], 37U) ^ RotL64(aKeyRowReadB[((aIndex + 30757U)) & W_KEY1], 13U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 6U) + RotL64(aPrevious, 43U)) ^ (RotL64(aCarry, 57U) ^ RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = (aWandererC + RotL64(aCross, 50U)) + 15188686795415908074U;
            aOrbiterC = ((aWandererD + RotL64(aIngress, 39U)) + RotL64(aCarry, 11U)) + 17310049041983079779U;
            aOrbiterH = (aWandererH + RotL64(aScatter, 19U)) + 8246925977992441471U;
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 5U)) + RotL64(aCarry, 27U)) + 8644260919918112781U;
            aOrbiterG = (aWandererK + RotL64(aIngress, 35U)) + 13401663736874819483U;
            aOrbiterK = (aWandererE + RotL64(aPrevious, 57U)) + 7940358935238314973U;
            aOrbiterD = ((aWandererF + RotL64(aCross, 29U)) + 13278990328548007839U) + aPhaseDOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = (aWandererG + RotL64(aScatter, 12U)) + 11346868298353840706U;
            aOrbiterI = (((aWandererA + RotL64(aCross, 23U)) + RotL64(aCarry, 35U)) + 2374077904806833579U) + aPhaseDOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 6978903378645019166U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 11951633297870965212U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12778236598654492185U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 17398460995357409673U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 1215437945597836770U;
            aOrbiterK = RotL64((aOrbiterK * 9322970054123481621U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 1878751468043972239U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 5343002808239712390U;
            aOrbiterC = RotL64((aOrbiterC * 11878640995447558811U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 9884918450053276861U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 15894599082080422550U;
            aOrbiterJ = RotL64((aOrbiterJ * 8359936745539546131U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 13917339232771145459U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 18101134009493720683U;
            aOrbiterB = RotL64((aOrbiterB * 15835859435306756387U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 3830086372356903769U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 15894394599564584010U;
            aOrbiterI = RotL64((aOrbiterI * 9513921913446609263U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 5127590955274245812U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 9410946933309720054U;
            aOrbiterG = RotL64((aOrbiterG * 14507476989423060561U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 15544384157294987085U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 998801294460434123U;
            aOrbiterF = RotL64((aOrbiterF * 5946968142746472745U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 16442095194965452163U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 14294936349037516932U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14655345374740882581U), 5U);
            //
            aIngress = RotL64(aOrbiterH, 53U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 39U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterK, 20U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 51U) + aOrbiterH) + RotL64(aOrbiterC, 18U));
            aWandererA = aWandererA + ((RotL64(aScatter, 19U) + aOrbiterD) + RotL64(aOrbiterC, 13U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 43U) + aOrbiterI) + RotL64(aOrbiterD, 39U));
            aWandererH = aWandererH + ((RotL64(aIngress, 28U) + aOrbiterJ) + RotL64(aOrbiterK, 47U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterH, 43U)) + aOrbiterJ);
            aWandererC = aWandererC + (((RotL64(aIngress, 11U) + aOrbiterF) + RotL64(aOrbiterG, 34U)) + RotL64(aCarry, 47U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 23U) + aOrbiterD) + RotL64(aOrbiterF, 51U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 36U) + aOrbiterC) + RotL64(aOrbiterB, 23U)) + RotL64(aCarry, 21U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 5U) + aOrbiterB) + RotL64(aOrbiterF, 29U)) + aPhaseDWandererUpdateSaltE[((aIndex + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + (RotL64(aWandererD, 18U) ^ aWandererA);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 53U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + RotL64(aWandererE, 41U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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

void TwistExpander_Rugby_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneA, aExpandLaneC, aExpandLaneD, aInvestLaneC, aFireLaneB, aInvestLaneD, aFireLaneD, aOperationLaneA, aFireLaneC, aOperationLaneB, aOperationLaneC
        // write to: aInvestLaneC, aInvestLaneD, aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // twist_loop_b loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneA
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 456U)) & S_BLOCK1], 44U) ^ RotL64(aExpandLaneB[((aIndex + 2021U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 2842U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4026U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 3321U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCross, 19U)) + (RotL64(aPrevious, 52U) + RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = ((aWandererF + RotL64(aScatter, 36U)) + RotL64(aCarry, 57U)) + 13854738573712660276U;
            aOrbiterG = (aWandererD + RotL64(aCross, 51U)) + 16835460633412286294U;
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 11U)) + 6785859293758091931U) + aPhaseEOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 57U)) + RotL64(aCarry, 5U)) + 126317283127992659U;
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 27U)) + 7568963536291415413U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = (aWandererB + RotL64(aScatter, 21U)) + 12294016745653004819U;
            aOrbiterK = ((aWandererA + RotL64(aCross, 3U)) + RotL64(aCarry, 29U)) + 18269588932920281147U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 5872406424994751026U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 7764434758831474129U;
            aOrbiterA = RotL64((aOrbiterA * 3772146788188420071U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 4804168969415573371U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 959601763507651280U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4647396592804833217U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 9257644462479293048U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 14332699366894494579U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8829304078930625541U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 10487012596470786004U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 612729229562321440U;
            aOrbiterG = RotL64((aOrbiterG * 11380387280507726003U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 7845523921295625315U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 12742115479740024747U;
            aOrbiterB = RotL64((aOrbiterB * 15578543510683986421U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 10294667720904610944U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 14369711143154904567U;
            aOrbiterK = RotL64((aOrbiterK * 13753005602288309379U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 10918344717497681894U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 18136794828308636957U;
            aOrbiterC = RotL64((aOrbiterC * 17899418637978002409U), 21U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterJ, 53U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 29U));
            aIngress = aIngress + RotL64(aOrbiterK, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterG, 12U)) + aOrbiterB);
            aWandererE = aWandererE + ((RotL64(aCross, 11U) + aOrbiterI) + RotL64(aOrbiterG, 19U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 39U) + aOrbiterK) + RotL64(aOrbiterJ, 29U)) + aPhaseEWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 21U) + aOrbiterI) + RotL64(aOrbiterA, 5U)) + RotL64(aCarry, 19U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterB, 41U)) + aOrbiterK);
            aWandererA = aWandererA + (((RotL64(aIngress, 47U) + aOrbiterA) + RotL64(aOrbiterK, 47U)) + RotL64(aCarry, 51U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 60U) + RotL64(aOrbiterB, 35U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 24U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 41U));
            aCarry = aCarry + RotL64(aWandererF, 13U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aInvestLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_b loop 2
        // ingress from: aInvestLaneC, aExpandLaneC, aFireLaneB
        // ingress directions: aInvestLaneC forward forced, aExpandLaneC forward forced, aFireLaneB forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneC[((aIndex + 10821U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneC[((aIndex + 7655U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 8879U)) & S_BLOCK1], 20U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 9109U)) & S_BLOCK1], 18U) ^ RotL64(aExpandLaneD[((aIndex + 6178U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 51U) + RotL64(aPrevious, 39U)) ^ (RotL64(aCarry, 27U) + RotL64(aIngress, 6U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = ((aWandererG + RotL64(aCross, 3U)) + RotL64(aCarry, 27U)) + 8402620908307642697U;
            aOrbiterI = ((aWandererH + RotL64(aIngress, 50U)) + 11347672014525086047U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterK = (aWandererC + RotL64(aPrevious, 35U)) + 2816462912503401876U;
            aOrbiterC = ((aWandererD + RotL64(aScatter, 11U)) + 6940159795470696093U) + aPhaseEOrbiterAssignSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterG = ((aWandererE + RotL64(aIngress, 43U)) + RotL64(aCarry, 43U)) + 9134692490095883851U;
            aOrbiterF = (aWandererA + RotL64(aScatter, 57U)) + 4999455497008026526U;
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 19U)) + RotL64(aCarry, 11U)) + 5992451460350651332U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 3417087346651371924U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 3612773820086198270U;
            aOrbiterK = RotL64((aOrbiterK * 5519856345435871169U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 463398077083428570U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 11249391303705089012U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7106735772303292983U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 17027535139825739501U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 568131384979596481U;
            aOrbiterI = RotL64((aOrbiterI * 5683451044852895957U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 4793712537158004047U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 10415170179135963622U;
            aOrbiterF = RotL64((aOrbiterF * 13729564030210361415U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 2391473979460065630U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 4240058362680064261U;
            aOrbiterD = RotL64((aOrbiterD * 12375884373396400889U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 9963957011090031698U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 3325305624067445525U;
            aOrbiterA = RotL64((aOrbiterA * 3128542681461806309U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 2094945647665114693U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 10703615640774042674U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12641986098450423751U), 29U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterC, 47U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 5U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + RotL64(aOrbiterI, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aIngress, 21U) + aOrbiterF) + RotL64(aOrbiterG, 56U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterK, 5U)) + aOrbiterG);
            aWandererH = aWandererH + (((RotL64(aCross, 5U) + aOrbiterD) + RotL64(aOrbiterI, 19U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterK, 29U)) + aOrbiterC);
            aWandererG = aWandererG + (((RotL64(aIngress, 57U) + aOrbiterK) + RotL64(aOrbiterD, 39U)) + RotL64(aCarry, 13U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 35U) + aOrbiterA) + RotL64(aOrbiterI, 47U)) + aPhaseEWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 12U) + RotL64(aOrbiterA, 11U)) + aOrbiterD) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererA, 24U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererG, 11U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aInvestLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_b loop 3
        // ingress from: aInvestLaneD, aExpandLaneD, aFireLaneD
        // ingress directions: aInvestLaneD forward forced, aExpandLaneD forward forced, aFireLaneD forward/backward random
        // cross from: aInvestLaneC, aExpandLaneB, aExpandLaneA
        // cross directions: aInvestLaneC backward forced, aExpandLaneB backward forced, aExpandLaneA backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneD[((aIndex + 13114U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((aIndex + 11530U)) & S_BLOCK1], 60U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 15510U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 14970U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 12994U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aExpandLaneA[((aIndex + 14858U)) & S_BLOCK1], 18U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 19U) ^ RotL64(aIngress, 54U)) + (RotL64(aPrevious, 5U) + RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = ((aWandererG + RotL64(aCross, 19U)) + RotL64(aCarry, 19U)) + 4980738603982643969U;
            aOrbiterC = (aWandererD + RotL64(aIngress, 43U)) + 17660278413018470020U;
            aOrbiterD = (aWandererA + RotL64(aScatter, 37U)) + 17598114429859543466U;
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 27U)) + RotL64(aCarry, 53U)) + 10993929335279994739U;
            aOrbiterA = ((aWandererH + RotL64(aCross, 5U)) + 17967203122976322481U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = (aWandererJ + RotL64(aScatter, 54U)) + 1872290205549034384U;
            aOrbiterI = (((aWandererK + RotL64(aIngress, 11U)) + RotL64(aCarry, 39U)) + 16607778671782810797U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 4895226930754394376U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 14960359005982301383U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8546231310054433721U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 9921642352377700630U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 893281964367208693U;
            aOrbiterC = RotL64((aOrbiterC * 2345509157333444217U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 8232519988397858732U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 4433022122758913407U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 834240393225479419U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 12689609831247168353U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 404535388957472176U;
            aOrbiterJ = RotL64((aOrbiterJ * 14534020545479806593U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 3349108201964013155U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 4386449511297371730U;
            aOrbiterA = RotL64((aOrbiterA * 9596273264321140229U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 14314587717949070586U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 10923886625271054985U;
            aOrbiterI = RotL64((aOrbiterI * 7838969002623486809U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 17634909585329833520U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 2021301459918350372U;
            aOrbiterE = RotL64((aOrbiterE * 1388242915918642741U), 51U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterD, 13U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 43U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 37U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterC, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aCross, 29U) + aOrbiterE) + RotL64(aOrbiterJ, 6U)) + RotL64(aCarry, 19U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterC, 41U)) + aOrbiterI);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 13U) + aOrbiterE) + RotL64(aOrbiterI, 21U)) + RotL64(aCarry, 53U)) + aPhaseEWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterJ, 35U)) + aOrbiterH);
            aWandererK = aWandererK + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterA, 27U)) + aOrbiterD);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 40U) + aOrbiterD) + RotL64(aOrbiterE, 53U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aCross, 21U) + RotL64(aOrbiterH, 13U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 58U));
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererD, 43U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_b loop 4
        // ingress from: aOperationLaneA, aInvestLaneC, aFireLaneC
        // ingress directions: aOperationLaneA forward forced, aInvestLaneC forward forced, aFireLaneC forward/backward random
        // cross from: aInvestLaneD, aExpandLaneD, aExpandLaneC
        // cross directions: aInvestLaneD backward forced, aExpandLaneD backward forced, aExpandLaneC backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 16397U)) & S_BLOCK1], 20U) ^ RotL64(aInvestLaneC[((aIndex + 16839U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 16825U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 17664U)) & S_BLOCK1], 42U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17285U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 19771U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aIngress, 39U)) ^ (RotL64(aCross, 53U) + RotL64(aPrevious, 10U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 27U)) + 9855743441035905047U) + aPhaseEOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = (aWandererA + RotL64(aCross, 43U)) + 8426286937143990276U;
            aOrbiterK = (aWandererC + RotL64(aScatter, 21U)) + 7146752367170267002U;
            aOrbiterE = ((aWandererH + RotL64(aIngress, 53U)) + RotL64(aCarry, 11U)) + 12947210066678101726U;
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 60U)) + RotL64(aCarry, 39U)) + 15902163559925328965U;
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 13U)) + RotL64(aCarry, 57U)) + 8506649889346449469U;
            aOrbiterF = ((aWandererJ + RotL64(aCross, 37U)) + 8226286036430263052U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 2703047093452420216U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 6769351326360139560U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5318104980014706265U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 9857025533281333281U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 238297452132277585U;
            aOrbiterE = RotL64((aOrbiterE * 12974709749856065985U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 7203572312072908931U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 12497027346166575632U;
            aOrbiterD = RotL64((aOrbiterD * 1703586436725662307U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 473851890609048879U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 1664484956453886047U;
            aOrbiterB = RotL64((aOrbiterB * 8566500756326590209U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 4635095143004754116U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 17695676150967345793U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5780416541584439301U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 15628965269863402796U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 9190117464399730235U;
            aOrbiterH = RotL64((aOrbiterH * 5586437438425999715U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 17835918238346011086U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 4398005402429282682U;
            aOrbiterF = RotL64((aOrbiterF * 14828737209913317463U), 27U);
            //
            aIngress = RotL64(aOrbiterE, 20U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 5U));
            aIngress = aIngress + (RotL64(aOrbiterH, 27U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterJ, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterE, 57U)) + aOrbiterJ) + RotL64(aCarry, 51U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 42U) + aOrbiterF) + RotL64(aOrbiterH, 23U));
            aWandererK = aWandererK + (((RotL64(aScatter, 53U) + RotL64(aOrbiterB, 3U)) + aOrbiterH) + aPhaseEWandererUpdateSaltE[((aIndex + 6U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 29U) + aOrbiterE) + RotL64(aOrbiterD, 37U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterJ, 47U)) + aOrbiterF);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 5U) + aOrbiterB) + RotL64(aOrbiterK, 30U));
            aWandererC = aWandererC + (((RotL64(aCross, 35U) + aOrbiterD) + RotL64(aOrbiterK, 11U)) + RotL64(aCarry, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererH, 58U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 25321U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneA[((aIndex + 23718U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25530U)) & S_BLOCK1], 48U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 26863U)) & S_BLOCK1], 19U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 21944U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aInvestLaneD[((aIndex + 23908U)) & S_BLOCK1], 54U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 35U) + RotL64(aPrevious, 3U)) ^ (RotL64(aIngress, 53U) ^ RotL64(aCross, 20U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = (aWandererA + RotL64(aScatter, 5U)) + 15188686795415908074U;
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 53U)) + RotL64(aCarry, 39U)) + 17310049041983079779U;
            aOrbiterJ = (aWandererD + RotL64(aIngress, 39U)) + 8246925977992441471U;
            aOrbiterK = ((aWandererC + RotL64(aCross, 11U)) + RotL64(aCarry, 5U)) + 8644260919918112781U;
            aOrbiterI = (aWandererI + RotL64(aIngress, 60U)) + 13401663736874819483U;
            aOrbiterA = ((aWandererE + RotL64(aCross, 29U)) + 7940358935238314973U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = (((aWandererK + RotL64(aScatter, 21U)) + RotL64(aCarry, 57U)) + 13278990328548007839U) + aPhaseEOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 11346868298353840706U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 2374077904806833579U;
            aOrbiterJ = RotL64((aOrbiterJ * 1765686942154321425U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 6978903378645019166U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 11951633297870965212U;
            aOrbiterI = RotL64((aOrbiterI * 12778236598654492185U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 17398460995357409673U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 1215437945597836770U;
            aOrbiterK = RotL64((aOrbiterK * 9322970054123481621U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 1878751468043972239U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 5343002808239712390U;
            aOrbiterA = RotL64((aOrbiterA * 11878640995447558811U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 9884918450053276861U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 15894599082080422550U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8359936745539546131U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 13917339232771145459U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 18101134009493720683U;
            aOrbiterB = RotL64((aOrbiterB * 15835859435306756387U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 3830086372356903769U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 15894394599564584010U;
            aOrbiterF = RotL64((aOrbiterF * 9513921913446609263U), 35U);
            //
            aIngress = RotL64(aOrbiterK, 29U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 5U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 44U));
            aIngress = aIngress + RotL64(aOrbiterF, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterJ, 51U)) + aOrbiterI) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterF, 43U)) + aOrbiterA) + RotL64(aCarry, 5U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 29U) + aOrbiterF) + RotL64(aOrbiterH, 13U));
            aWandererC = aWandererC + (((RotL64(aCross, 60U) + aOrbiterJ) + RotL64(aOrbiterA, 35U)) + RotL64(aCarry, 37U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 13U) + aOrbiterJ) + RotL64(aOrbiterB, 58U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aIngress, 41U) + RotL64(aOrbiterH, 29U)) + aOrbiterK);
            aWandererK = aWandererK ^ ((RotL64(aCross, 23U) + aOrbiterJ) + RotL64(aOrbiterK, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 14U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererB, 39U);
            aCarry = aCarry + RotL64(aIngress, 10U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 27966U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneA[((aIndex + 30782U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32633U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29875U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 28538U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 29428U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 37U) + RotL64(aCarry, 24U)) ^ (RotL64(aIngress, 53U) ^ RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = (aWandererE + RotL64(aScatter, 57U)) + 4634399531433127141U;
            aOrbiterD = (aWandererJ + RotL64(aIngress, 27U)) + 16961792729406903200U;
            aOrbiterF = ((aWandererC + RotL64(aCross, 18U)) + 4105280732301137738U) + aPhaseEOrbiterAssignSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = (aWandererI + RotL64(aPrevious, 51U)) + 15692013501147331191U;
            aOrbiterA = ((aWandererD + RotL64(aCross, 43U)) + RotL64(aCarry, 19U)) + 1252216715968780587U;
            aOrbiterH = ((aWandererG + RotL64(aIngress, 3U)) + RotL64(aCarry, 53U)) + 7958289043012473752U;
            aOrbiterE = (((aWandererB + RotL64(aScatter, 11U)) + RotL64(aCarry, 5U)) + 6611577301818896615U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 8506226754305949140U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 3648813120449403353U;
            aOrbiterF = RotL64((aOrbiterF * 9521367946879238849U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 5195245426245535735U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 542948051600803051U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4631106308856448475U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 11974253551208964789U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 10596463592332655367U;
            aOrbiterH = RotL64((aOrbiterH * 10941161258815714641U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 12015129484061440159U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 8254944355710109060U;
            aOrbiterA = RotL64((aOrbiterA * 3233697992479357615U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 2754858806943915419U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 5007802002906662779U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15613733948331639723U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 6262190752136523216U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 10528977986487821428U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1184258264034585525U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 8511097226098211854U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 12091864735686692582U;
            aOrbiterK = RotL64((aOrbiterK * 6128140528141411237U), 11U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterK, 42U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 11U));
            aIngress = aIngress + (RotL64(aOrbiterA, 35U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterI, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aIngress, 5U) + aOrbiterH) + RotL64(aOrbiterI, 43U)) + RotL64(aCarry, 41U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 13U) + aOrbiterA) + RotL64(aOrbiterK, 29U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 41U) + aOrbiterF) + RotL64(aOrbiterK, 10U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 23U) + aOrbiterI) + RotL64(aOrbiterF, 51U));
            aWandererG = aWandererG + ((((RotL64(aScatter, 30U) + aOrbiterE) + RotL64(aOrbiterI, 35U)) + RotL64(aCarry, 19U)) + aPhaseEWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 51U) + aOrbiterK) + RotL64(aOrbiterH, 21U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aCross, 57U) + RotL64(aOrbiterK, 57U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererI);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 14U));
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererE, 3U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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

void TwistExpander_Rugby_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
        // read from: aOperationLaneA, aOperationLaneB, aExpandLaneC, aOperationLaneC, aOperationLaneD, aExpandLaneA, aSnowLaneA, aInvestLaneA, aInvestLaneB, aSnowLaneB, aExpandLaneD, aWorkLaneA, aExpandLaneB, aWorkLaneB, aInvestLaneC, aWorkLaneC, aInvestLaneD
        // write to: aSnowLaneA, aSnowLaneB, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // twist_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aExpandLaneC
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aExpandLaneC forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aExpandLaneA
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aExpandLaneA backward/forward random
        // write to: aSnowLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 1146U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneB[((aIndex + 2267U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4531U)) & S_BLOCK1], 52U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 3261U)) & S_BLOCK1], 54U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 3102U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aExpandLaneA[((aIndex + 2157U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 29U) ^ RotL64(aPrevious, 43U)) + (RotL64(aCross, 60U) ^ RotL64(aIngress, 13U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = (((aWandererE + RotL64(aPrevious, 27U)) + RotL64(aCarry, 11U)) + 3650233661228036955U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterD = (aWandererG + RotL64(aCross, 60U)) + 11607036400067735729U;
            aOrbiterF = (aWandererC + RotL64(aScatter, 57U)) + 3899614406903883035U;
            aOrbiterA = ((aWandererH + RotL64(aIngress, 11U)) + RotL64(aCarry, 23U)) + 8159156925629965143U;
            aOrbiterI = (aWandererB + RotL64(aPrevious, 5U)) + 7148903913967261270U;
            aOrbiterE = (aWandererF + RotL64(aScatter, 35U)) + 9161665622287517848U;
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 24U)) + 2981535013474059469U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = ((aWandererJ + RotL64(aCross, 3U)) + RotL64(aCarry, 53U)) + 15812469008200319549U;
            aOrbiterB = (aWandererI + RotL64(aScatter, 47U)) + 14687469489893270300U;
            aOrbiterH = (aWandererA + RotL64(aCross, 37U)) + 6025209349511417063U;
            aOrbiterK = (aWandererK + RotL64(aPrevious, 51U)) + 12964750392311112676U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 6572355895765394340U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 3542300121890027981U;
            aOrbiterF = RotL64((aOrbiterF * 11201491178181273935U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 6477175684045398359U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 1081388388827929314U;
            aOrbiterE = RotL64((aOrbiterE * 8752188637514143529U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 13754328481584620771U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 3684673342659575917U;
            aOrbiterA = RotL64((aOrbiterA * 6139923312873039143U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 6542045150319909445U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 5352102692424060388U;
            aOrbiterI = RotL64((aOrbiterI * 7385758355501860261U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 9110100774657340354U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 2813273684436269057U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10468759062594022273U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 5860425751137403755U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 1598622981888978548U;
            aOrbiterC = RotL64((aOrbiterC * 651816500461718345U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 14710305692377606725U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 16280545617802383463U;
            aOrbiterG = RotL64((aOrbiterG * 12541767206978802063U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 6849565243667718750U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 12152381961996750050U;
            aOrbiterH = RotL64((aOrbiterH * 11185935780063403807U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 1318947876257794796U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 5447559252769140391U;
            aOrbiterD = RotL64((aOrbiterD * 13683733413554766327U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 2766869582494246454U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 15757729967222729304U;
            aOrbiterB = RotL64((aOrbiterB * 1858683399257513171U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 13063432816787882618U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 3650233661228036955U;
            aOrbiterK = RotL64((aOrbiterK * 16230564672533821641U), 27U);
            //
            aIngress = RotL64(aOrbiterG, 19U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 39U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 53U));
            aIngress = aIngress + (RotL64(aOrbiterD, 24U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterK, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterB, 13U)) + aOrbiterG) + RotL64(aCarry, 57U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterA, 41U)) + aOrbiterH);
            aWandererI = aWandererI + ((RotL64(aCross, 5U) + RotL64(aOrbiterD, 26U)) + aOrbiterG);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 50U) + RotL64(aOrbiterJ, 53U)) + aOrbiterH);
            aWandererE = aWandererE + ((((RotL64(aIngress, 39U) + RotL64(aOrbiterK, 57U)) + aOrbiterB) + RotL64(aCarry, 39U)) + aPhaseFWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterJ, 3U)) + aOrbiterF);
            aWandererF = aWandererF + ((RotL64(aScatter, 57U) + RotL64(aOrbiterK, 60U)) + aOrbiterF);
            aWandererA = aWandererA ^ ((RotL64(aCross, 42U) + aOrbiterB) + RotL64(aOrbiterE, 29U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 35U) + aOrbiterD) + RotL64(aOrbiterB, 47U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 47U) + aOrbiterC) + RotL64(aOrbiterB, 37U));
            aWandererK = aWandererK + ((RotL64(aCross, 23U) + aOrbiterI) + RotL64(aOrbiterG, 39U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 50U));
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 46U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererI, 27U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aSnowLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 2
        // ingress from: aSnowLaneA, aOperationLaneC, aOperationLaneD, aInvestLaneA
        // ingress directions: aSnowLaneA forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aInvestLaneA forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aInvestLaneB
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aInvestLaneB backward/forward random
        // write to: aSnowLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 7152U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneC[((aIndex + 5958U)) & S_BLOCK1], 27U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 10901U)) & S_BLOCK1], 53U) ^ RotL64(aInvestLaneA[((aIndex + 8254U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 9791U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 9266U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 5834U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 43U) ^ RotL64(aCross, 58U)) ^ (RotL64(aCarry, 11U) + RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = (aWandererF + RotL64(aCross, 5U)) + 14008824488073394623U;
            aOrbiterD = (aWandererJ + RotL64(aScatter, 34U)) + 13317978415866411468U;
            aOrbiterH = (aWandererI + RotL64(aPrevious, 23U)) + 13209180141897453900U;
            aOrbiterI = (aWandererA + RotL64(aIngress, 39U)) + 11870521586865233578U;
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 41U)) + RotL64(aCarry, 57U)) + 8052156380448047385U;
            aOrbiterE = (aWandererK + RotL64(aIngress, 11U)) + 12158131176743680605U;
            aOrbiterA = ((aWandererD + RotL64(aCross, 57U)) + RotL64(aCarry, 35U)) + 14674467487607719347U;
            aOrbiterG = ((aWandererC + RotL64(aScatter, 37U)) + 18055496790566231147U) + aPhaseFOrbiterAssignSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterK = (aWandererH + RotL64(aPrevious, 51U)) + 3838105585041578784U;
            aOrbiterC = ((aWandererE + RotL64(aScatter, 13U)) + RotL64(aCarry, 29U)) + 2839568255183054418U;
            aOrbiterJ = ((aWandererB + RotL64(aCross, 46U)) + 11933612922864258179U) + aPhaseFOrbiterAssignSaltE[((aIndex + 18U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 6289849094151630580U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 2640344350528492271U;
            aOrbiterH = RotL64((aOrbiterH * 16197726750829369365U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 16306175266267657791U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 3339898380394883600U;
            aOrbiterD = RotL64((aOrbiterD * 7105436590182982373U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 15017076663742800002U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 8973064296077602496U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9309462227233615761U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 17580319233338139859U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 14063208878807603874U;
            aOrbiterK = RotL64((aOrbiterK * 16601475239075164585U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 13326130855721009942U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 12843186026737544416U;
            aOrbiterA = RotL64((aOrbiterA * 4975848122837321619U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 14102887715772847499U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 14495942314329085733U;
            aOrbiterE = RotL64((aOrbiterE * 4236795312917583565U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 11564857125101669667U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 17435970784822000464U;
            aOrbiterB = RotL64((aOrbiterB * 1472691848852381173U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 16561390130356833062U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 9952805588514363872U;
            aOrbiterJ = RotL64((aOrbiterJ * 3720874990001086597U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 8246822023509690545U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 305480212301772662U;
            aOrbiterI = RotL64((aOrbiterI * 4295787267516476485U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 11729872285756639125U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 9669174142543613799U;
            aOrbiterC = RotL64((aOrbiterC * 9443240779947114779U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 7653344907616923293U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 14008824488073394623U;
            aOrbiterF = RotL64((aOrbiterF * 8362849599309360823U), 21U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterJ, 19U);
            aIngress = aIngress + (RotL64(aOrbiterG, 5U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 30U));
            aIngress = aIngress + (RotL64(aOrbiterH, 23U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + RotL64(aOrbiterB, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 37U) + aOrbiterI) + RotL64(aOrbiterD, 47U));
            aWandererK = aWandererK + ((RotL64(aCross, 43U) + aOrbiterA) + RotL64(aOrbiterJ, 50U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterD, 11U)) + aOrbiterB) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 34U) + RotL64(aOrbiterA, 21U)) + aOrbiterK);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterB, 5U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 29U) + RotL64(aOrbiterA, 38U)) + aOrbiterC);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterH, 53U)) + aOrbiterK);
            aWandererI = aWandererI + (((RotL64(aCross, 46U) + aOrbiterG) + RotL64(aOrbiterK, 57U)) + RotL64(aCarry, 39U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 51U) + aOrbiterH) + RotL64(aOrbiterE, 13U));
            aWandererA = aWandererA + (((RotL64(aScatter, 19U) + aOrbiterA) + RotL64(aOrbiterF, 41U)) + RotL64(aCarry, 53U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 3U) + aOrbiterC) + RotL64(aOrbiterG, 23U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 50U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + RotL64(aWandererH, 35U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aSnowLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_c loop 3
        // ingress from: aSnowLaneB, aOperationLaneA, aExpandLaneD
        // ingress directions: aSnowLaneB forward forced, aOperationLaneA forward forced, aExpandLaneD forward/backward random
        // cross from: aSnowLaneA, aOperationLaneC
        // cross directions: aSnowLaneA backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneB[((aIndex + 13715U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneA[((aIndex + 13117U)) & S_BLOCK1], 34U));
            aIngress ^= RotL64(aExpandLaneD[((aIndex + 13293U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 11852U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 14748U)) & S_BLOCK1], 26U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 43U) ^ RotL64(aIngress, 56U)) + (RotL64(aCross, 11U) + RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = (aWandererH + RotL64(aCross, 27U)) + 10915618884692072446U;
            aOrbiterC = (aWandererF + RotL64(aIngress, 47U)) + 12634922308499254909U;
            aOrbiterD = ((aWandererG + RotL64(aScatter, 12U)) + 6533934734564499389U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 57U)) + RotL64(aCarry, 27U)) + 6744203303756105181U;
            aOrbiterK = ((aWandererD + RotL64(aCross, 21U)) + RotL64(aCarry, 39U)) + 13086782386652045658U;
            aOrbiterG = (aWandererK + RotL64(aPrevious, 39U)) + 5693840533331397822U;
            aOrbiterE = (aWandererJ + RotL64(aScatter, 3U)) + 1803663542535024611U;
            aOrbiterA = ((aWandererB + RotL64(aIngress, 35U)) + RotL64(aCarry, 47U)) + 3597219300593287708U;
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 23U)) + 1429753448204448904U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = (aWandererI + RotL64(aCross, 51U)) + 17229017825587322715U;
            aOrbiterH = (aWandererE + RotL64(aIngress, 30U)) + 1137574712801062932U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 2401991077004083378U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 1332473247826139292U;
            aOrbiterD = RotL64((aOrbiterD * 15029831858261506447U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 11730946340796899885U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 15319163439700390962U;
            aOrbiterK = RotL64((aOrbiterK * 1349242001887975499U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 4744141870145159917U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 6067132201862688684U;
            aOrbiterE = RotL64((aOrbiterE * 6046100687757836027U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 14991509179286371800U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 4342608825699398682U;
            aOrbiterB = RotL64((aOrbiterB * 10240526103933275875U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 3727521409410742075U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 3302027219498304367U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12153634588200479559U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 6039539483340398858U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 2902581519976937051U;
            aOrbiterH = RotL64((aOrbiterH * 2057584328877854239U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 12332784713738947242U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 13761272577223712786U;
            aOrbiterA = RotL64((aOrbiterA * 14930145045480030821U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 2947946397617043735U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 11107014023853644521U;
            aOrbiterG = RotL64((aOrbiterG * 15030903626191481831U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 6212403196992771516U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 16107261731677426470U;
            aOrbiterF = RotL64((aOrbiterF * 13764822942405295129U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 8414111492161335472U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 3625937496991123221U;
            aOrbiterJ = RotL64((aOrbiterJ * 1736741235159600739U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 5466667339391480293U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 10915618884692072446U;
            aOrbiterI = RotL64((aOrbiterI * 14719282928172086707U), 43U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterF, 47U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 41U));
            aIngress = aIngress + (RotL64(aOrbiterD, 43U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 26U));
            aIngress = aIngress + (RotL64(aOrbiterB, 21U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterK, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aCross, 14U) + RotL64(aOrbiterG, 35U)) + aOrbiterK);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 21U) + aOrbiterA) + RotL64(aOrbiterK, 47U)) + aPhaseFWandererUpdateSaltF[((aIndex + 8U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterB, 43U)) + aOrbiterK);
            aWandererF = aWandererF + (((RotL64(aIngress, 5U) + aOrbiterI) + RotL64(aOrbiterD, 53U)) + RotL64(aCarry, 57U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 37U) + aOrbiterC) + RotL64(aOrbiterB, 22U));
            aWandererA = aWandererA + (((RotL64(aScatter, 56U) + RotL64(aOrbiterK, 13U)) + aOrbiterD) + RotL64(aCarry, 35U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterH, 3U)) + aOrbiterB);
            aWandererC = aWandererC + ((RotL64(aIngress, 27U) + aOrbiterD) + RotL64(aOrbiterE, 5U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterF, 19U)) + aOrbiterK);
            aWandererE = aWandererE + ((RotL64(aPrevious, 41U) + aOrbiterJ) + RotL64(aOrbiterD, 57U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 19U) + aOrbiterH) + RotL64(aOrbiterF, 10U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 41U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 20U));
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 29U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 53U));
            aCarry = aCarry + RotL64(aWandererJ, 44U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 4
        // ingress from: aWorkLaneA, aSnowLaneA, aExpandLaneB
        // ingress directions: aWorkLaneA forward forced, aSnowLaneA forward forced, aExpandLaneB forward/backward random
        // cross from: aSnowLaneB, aOperationLaneD
        // cross directions: aSnowLaneB backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 19432U)) & S_BLOCK1], 52U) ^ RotL64(aSnowLaneA[((aIndex + 18727U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 16485U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 19303U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 19622U)) & S_BLOCK1], 30U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 41U) + RotL64(aIngress, 4U)) + (RotL64(aCross, 19U) ^ RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = ((aWandererK + RotL64(aIngress, 39U)) + RotL64(aCarry, 53U)) + 10812151398716051703U;
            aOrbiterG = (aWandererG + RotL64(aScatter, 27U)) + 18202551453336003710U;
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 36U)) + 9434410809101973752U;
            aOrbiterI = (aWandererI + RotL64(aCross, 11U)) + 12955829998028534045U;
            aOrbiterC = (aWandererB + RotL64(aPrevious, 3U)) + 12271740641929640181U;
            aOrbiterH = (aWandererC + RotL64(aIngress, 5U)) + 14009351527014534752U;
            aOrbiterB = (((aWandererD + RotL64(aCross, 21U)) + RotL64(aCarry, 37U)) + 4316296955679133450U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = (aWandererJ + RotL64(aScatter, 51U)) + 16473324966997442872U;
            aOrbiterK = ((aWandererA + RotL64(aCross, 18U)) + 15735123324965019802U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = ((aWandererE + RotL64(aScatter, 53U)) + RotL64(aCarry, 5U)) + 17656375090484080236U;
            aOrbiterD = (aWandererH + RotL64(aPrevious, 43U)) + 16066325053456055298U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 12908968778503516903U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 12761433987676836197U;
            aOrbiterJ = RotL64((aOrbiterJ * 1023329467480907925U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 12737513138040664509U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 14535795767570998392U;
            aOrbiterH = RotL64((aOrbiterH * 15560519667062222269U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 14370908061811284364U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 7001358781208669795U;
            aOrbiterC = RotL64((aOrbiterC * 11641248025734015835U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 7298578161120090849U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 10498302152357484629U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13144110412179037175U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 11447343228638006767U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 18284143620422655675U;
            aOrbiterG = RotL64((aOrbiterG * 572862190073605651U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 5918253208127360199U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 3910541329178205943U;
            aOrbiterD = RotL64((aOrbiterD * 4550654545328228103U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 10357053096941367910U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 5610891501128498748U;
            aOrbiterF = RotL64((aOrbiterF * 8676370811772047449U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 9049881176058575811U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 6307599924966452216U;
            aOrbiterA = RotL64((aOrbiterA * 5551444450572055895U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 17109966783467892046U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 11563095828344462249U;
            aOrbiterE = RotL64((aOrbiterE * 15463753739272001875U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 3739147427725509014U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 5324449517615050698U;
            aOrbiterK = RotL64((aOrbiterK * 5926079615575226853U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 5706251076252597592U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 10812151398716051703U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5666491216813197045U), 51U);
            //
            aIngress = RotL64(aOrbiterC, 6U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 3U));
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 23U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 53U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterK, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aIngress, 3U) + aOrbiterH) + RotL64(aOrbiterF, 29U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 35U) + aOrbiterH) + RotL64(aOrbiterA, 10U));
            aWandererC = aWandererC + ((((RotL64(aPrevious, 23U) + aOrbiterC) + RotL64(aOrbiterI, 53U)) + RotL64(aCarry, 5U)) + aPhaseFWandererUpdateSaltB[((aIndex + 28U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterI, 19U)) + aOrbiterJ);
            aWandererD = aWandererD + ((RotL64(aScatter, 19U) + aOrbiterJ) + RotL64(aOrbiterD, 5U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 27U) + aOrbiterG) + RotL64(aOrbiterI, 35U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 52U) + RotL64(aOrbiterK, 43U)) + aOrbiterH);
            aWandererK = aWandererK ^ ((RotL64(aCross, 11U) + aOrbiterK) + RotL64(aOrbiterB, 3U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 29U) + RotL64(aOrbiterJ, 51U)) + aOrbiterA) + RotL64(aCarry, 37U)) + aPhaseFWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterE, 13U)) + aOrbiterK);
            aWandererA = aWandererA + ((RotL64(aCross, 58U) + RotL64(aOrbiterI, 24U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererC);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 6U));
            aCarry = aCarry + (RotL64(aWandererG, 41U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererA, 27U);
            aCarry = aCarry + RotL64(aIngress, 4U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_c loop 5
        // ingress from: aWorkLaneB, aSnowLaneB, aInvestLaneC
        // ingress directions: aWorkLaneB forward forced, aSnowLaneB forward forced, aInvestLaneC forward/backward random
        // cross from: aWorkLaneA, aSnowLaneA
        // cross directions: aWorkLaneA backward forced, aSnowLaneA backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 26070U)) & S_BLOCK1], 51U) ^ RotL64(aSnowLaneB[((aIndex + 27240U)) & S_BLOCK1], 6U));
            aIngress ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 24224U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25223U)) & S_BLOCK1], 40U) ^ RotL64(aSnowLaneA[((aIndex + 24821U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aIngress, 26U)) ^ (RotL64(aPrevious, 39U) ^ RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = ((aWandererK + RotL64(aIngress, 3U)) + 1952750591494698524U) + aPhaseFOrbiterAssignSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = (aWandererD + RotL64(aPrevious, 6U)) + 4488270851303332830U;
            aOrbiterI = (aWandererB + RotL64(aScatter, 35U)) + 2738763375328927635U;
            aOrbiterF = (aWandererJ + RotL64(aCross, 11U)) + 6728843649480454340U;
            aOrbiterG = (aWandererA + RotL64(aPrevious, 39U)) + 10490717875258865358U;
            aOrbiterH = ((aWandererC + RotL64(aScatter, 43U)) + RotL64(aCarry, 57U)) + 1429288737812910205U;
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 47U)) + 2761375016998907636U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = (aWandererG + RotL64(aCross, 27U)) + 1088988605204499835U;
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 56U)) + RotL64(aCarry, 47U)) + 6829840407300289709U;
            aOrbiterC = ((aWandererI + RotL64(aCross, 23U)) + RotL64(aCarry, 21U)) + 9267240337867690471U;
            aOrbiterE = (aWandererF + RotL64(aIngress, 19U)) + 8120113021183975703U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 1340980511302566784U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 11874452169979878835U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8638486178860092537U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 1872314794140971426U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 6013952618696225751U;
            aOrbiterG = RotL64((aOrbiterG * 7994863587373565715U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 3644011378086236002U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 8501867691997891731U;
            aOrbiterF = RotL64((aOrbiterF * 7115282675461711509U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 2493546555198066143U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 5179240189571799179U;
            aOrbiterD = RotL64((aOrbiterD * 1267579130962756135U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 11273348247858394197U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 4577476419423118925U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8427261005061162673U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 6201955123046621919U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 3930651302557530185U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1563512534463027965U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 7571426325227856019U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 11098508505512361002U;
            aOrbiterK = RotL64((aOrbiterK * 9229352429618815089U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 6154830144380484305U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 4282054616147137364U;
            aOrbiterB = RotL64((aOrbiterB * 14984813139796280171U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 14818120999774989697U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 12174471855744785761U;
            aOrbiterJ = RotL64((aOrbiterJ * 3061488029278974095U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 3117297607579915182U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 2979217539186455309U;
            aOrbiterH = RotL64((aOrbiterH * 12235308335184626143U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 824986728082249286U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 1952750591494698524U;
            aOrbiterA = RotL64((aOrbiterA * 10162288961171400541U), 35U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterD, 60U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 51U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 35U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 43U));
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterA, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aScatter, 41U) + aOrbiterE) + RotL64(aOrbiterJ, 27U)) + aPhaseFWandererUpdateSaltD[((aIndex + 6U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aCross, 13U) + aOrbiterC) + RotL64(aOrbiterA, 35U)) + RotL64(aCarry, 11U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 56U) + aOrbiterD) + RotL64(aOrbiterJ, 14U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterK, 23U)) + aOrbiterH);
            aWandererG = aWandererG ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterI, 21U)) + aOrbiterD);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 5U) + aOrbiterF) + RotL64(aOrbiterH, 19U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 29U) + aOrbiterB) + RotL64(aOrbiterF, 43U));
            aWandererF = aWandererF + (((RotL64(aScatter, 3U) + RotL64(aOrbiterA, 48U)) + aOrbiterG) + RotL64(aCarry, 39U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 20U) + RotL64(aOrbiterJ, 3U)) + aOrbiterK);
            aWandererI = aWandererI + ((RotL64(aIngress, 47U) + RotL64(aOrbiterJ, 41U)) + aOrbiterI);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 35U) + aOrbiterH) + RotL64(aOrbiterG, 39U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 18U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + (RotL64(aWandererC, 21U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererI, 29U);
            aCarry = aCarry + RotL64(aIngress, 14U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 6
        // ingress from: aWorkLaneC, aWorkLaneA, aInvestLaneD
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aInvestLaneD forward/backward random
        // cross from: aWorkLaneB, aOperationLaneB
        // cross directions: aWorkLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 27729U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneA[((aIndex + 28533U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 28356U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29252U)) & S_BLOCK1], 40U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29373U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 21U) ^ RotL64(aCarry, 43U)) + (RotL64(aIngress, 6U) ^ RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = ((aWandererI + RotL64(aScatter, 6U)) + RotL64(aCarry, 37U)) + 12222235191147985484U;
            aOrbiterI = (aWandererK + RotL64(aIngress, 47U)) + 16367317014523328414U;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 53U)) + RotL64(aCarry, 19U)) + 3511378091284703789U;
            aOrbiterJ = ((aWandererB + RotL64(aCross, 3U)) + 15247492830966725949U) + aPhaseFOrbiterAssignSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = (aWandererA + RotL64(aScatter, 51U)) + 7745995913390407897U;
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 19U)) + 6463593307540108810U) + aPhaseFOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = (aWandererJ + RotL64(aCross, 37U)) + 1101669311005268630U;
            aOrbiterD = ((aWandererF + RotL64(aIngress, 13U)) + RotL64(aCarry, 11U)) + 12988052764067518580U;
            aOrbiterK = (aWandererD + RotL64(aPrevious, 41U)) + 17717179747434679772U;
            aOrbiterC = (aWandererH + RotL64(aIngress, 23U)) + 11662190906682400416U;
            aOrbiterH = (aWandererG + RotL64(aCross, 44U)) + 6563014073547628748U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 13099094932059419219U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 16342730862261868847U;
            aOrbiterG = RotL64((aOrbiterG * 10988124108686164829U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 16855346813127524624U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 6570063128502306944U;
            aOrbiterA = RotL64((aOrbiterA * 4571570049463124831U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 11328352033809240501U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 11640986648833160901U;
            aOrbiterI = RotL64((aOrbiterI * 2895830492089678919U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 2675226158571501666U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 17700531248266458165U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2231403813970188657U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 7729597396731910874U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 15172374484412053756U;
            aOrbiterE = RotL64((aOrbiterE * 149009041406406517U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 9178769489257842683U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 9020154972097834926U;
            aOrbiterK = RotL64((aOrbiterK * 8910504667566521429U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 1317403761217790562U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 17151528554929201571U;
            aOrbiterC = RotL64((aOrbiterC * 3735945655450625203U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 11621882033959669977U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 10289504450815075623U;
            aOrbiterJ = RotL64((aOrbiterJ * 13365982786836243195U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 16178772981106335703U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 16896130772325866910U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6993524735412868965U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 9573223644675562575U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 17552463713786507189U;
            aOrbiterH = RotL64((aOrbiterH * 16103431656424881779U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 4801852246698369631U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 12222235191147985484U;
            aOrbiterD = RotL64((aOrbiterD * 2835204872125428065U), 51U);
            //
            aIngress = RotL64(aOrbiterH, 41U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + (RotL64(aOrbiterK, 21U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterJ, 39U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterC, 13U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterF, 24U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterD, 6U)) + aOrbiterA);
            aWandererI = aWandererI + (((RotL64(aIngress, 60U) + aOrbiterB) + RotL64(aOrbiterG, 27U)) + RotL64(aCarry, 51U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterD, 37U)) + aOrbiterB);
            aWandererA = aWandererA + (((RotL64(aCross, 47U) + RotL64(aOrbiterH, 41U)) + aOrbiterD) + RotL64(aCarry, 11U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterC, 43U)) + aOrbiterH);
            aWandererF = aWandererF + ((RotL64(aIngress, 41U) + aOrbiterB) + RotL64(aOrbiterK, 57U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 19U) + aOrbiterD) + RotL64(aOrbiterE, 35U));
            aWandererG = aWandererG + ((RotL64(aCross, 13U) + aOrbiterJ) + RotL64(aOrbiterI, 47U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 36U) + RotL64(aOrbiterH, 24U)) + aOrbiterA) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 51U) + aOrbiterF) + RotL64(aOrbiterJ, 51U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterJ, 19U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + (RotL64(aWandererA, 50U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererI);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 41U));
            aCarry = aCarry + RotL64(aWandererJ, 34U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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

void TwistExpander_Rugby_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0;
    std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 7093U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((aIndex + 710U)) & S_BLOCK1], 54U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 7085U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 5013U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 5870U)) & S_BLOCK1], 50U));
            aCross ^= RotL64(aOperationLaneA[((aIndex + 4940U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 51U) + RotL64(aIngress, 5U)) ^ (RotL64(aPrevious, 21U) ^ RotL64(aCross, 38U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = (((aWandererJ + RotL64(aCross, 11U)) + RotL64(aCarry, 57U)) + 13650869943246163567U) + aPhaseGOrbiterAssignSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterJ = (aWandererH + RotL64(aScatter, 51U)) + 3435284932011770999U;
            aOrbiterF = (aWandererG + RotL64(aIngress, 27U)) + 12388155658186776579U;
            aOrbiterE = (((aWandererD + RotL64(aPrevious, 39U)) + RotL64(aCarry, 37U)) + 2374345913955712039U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterI = ((aWandererA + RotL64(aScatter, 60U)) + RotL64(aCarry, 13U)) + 6095094526980292156U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 4965147025852444174U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 3261881216269075298U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4874733445914960785U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 4939780217097329222U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 3019862009792676287U;
            aOrbiterJ = RotL64((aOrbiterJ * 2452316208025448747U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 901910626217143974U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 3647055146712366383U;
            aOrbiterI = RotL64((aOrbiterI * 1792602402476450009U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 7731765438957392967U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 13409819457393479741U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3345078200262410715U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 5415832109107794258U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 8876738832313114471U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1304277600444504135U), 13U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterE, 37U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 13U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterI, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aScatter, 48U) + aOrbiterH) + RotL64(aOrbiterF, 27U)) + aPhaseGWandererUpdateSaltE[((aIndex + 8U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterF, 57U)) + aOrbiterE);
            aWandererH = aWandererH + (((RotL64(aPrevious, 57U) + aOrbiterJ) + RotL64(aOrbiterI, 13U)) + RotL64(aCarry, 37U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterI, 48U)) + aOrbiterH) + aPhaseGWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 23U) + aOrbiterH) + RotL64(aOrbiterJ, 35U)) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 21U) ^ aWandererG);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + RotL64(aWandererD, 57U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 11273U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneC[((aIndex + 13333U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aInvestLaneB[((aIndex + 13543U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11912U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 10563U)) & S_BLOCK1], 26U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 11969U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aPrevious, 27U)) + (RotL64(aIngress, 5U) ^ RotL64(aCarry, 42U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = ((aWandererD + RotL64(aScatter, 40U)) + RotL64(aCarry, 27U)) + 13687218104610230596U;
            aOrbiterJ = (((aWandererC + RotL64(aPrevious, 3U)) + RotL64(aCarry, 13U)) + 6841550124960692709U) + aPhaseGOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = (aWandererK + RotL64(aIngress, 21U)) + 17418968668458764131U;
            aOrbiterH = (aWandererA + RotL64(aCross, 53U)) + 8303537912696948204U;
            aOrbiterK = (((aWandererF + RotL64(aIngress, 11U)) + RotL64(aCarry, 57U)) + 12376614417285936537U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 14215749063579232654U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 4111736931433665347U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8841288213954433049U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 11250375934571631522U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 5367367837773331275U;
            aOrbiterK = RotL64((aOrbiterK * 7262723007545807179U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 15514089192382674434U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 1475991716685034960U;
            aOrbiterE = RotL64((aOrbiterE * 17720681295551650891U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 5531622777788629748U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 8363822215908303335U;
            aOrbiterJ = RotL64((aOrbiterJ * 17850203366840994883U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 3741256932685720414U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 11634667238062155772U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15925089729784547403U), 19U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterJ, 53U);
            aIngress = aIngress + (RotL64(aOrbiterK, 41U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterH, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aIngress, 39U) + aOrbiterK) + RotL64(aOrbiterI, 14U)) + RotL64(aCarry, 43U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 48U) + RotL64(aOrbiterH, 5U)) + aOrbiterI) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 11U) + aOrbiterJ) + RotL64(aOrbiterH, 57U)) + RotL64(aCarry, 57U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterH, 35U)) + aOrbiterE);
            aWandererK = aWandererK + (((RotL64(aScatter, 29U) + RotL64(aOrbiterH, 27U)) + aOrbiterK) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 21U));
            aCarry = aCarry + RotL64(aWandererC, 11U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 22855U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneD[((aIndex + 16661U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aInvestLaneC[((aIndex + 19814U)) & S_BLOCK1], 24U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 19159U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17331U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 18676U)) & S_BLOCK1], 36U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aIngress, 18U)) ^ (RotL64(aPrevious, 51U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = ((aWandererE + RotL64(aIngress, 48U)) + RotL64(aCarry, 11U)) + 6069475454765660321U;
            aOrbiterH = (((aWandererB + RotL64(aPrevious, 57U)) + RotL64(aCarry, 41U)) + 11483704742497268068U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterK = (((aWandererG + RotL64(aCross, 37U)) + RotL64(aCarry, 23U)) + 11055697447388986418U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = (aWandererF + RotL64(aScatter, 23U)) + 10897095046039997004U;
            aOrbiterI = (aWandererI + RotL64(aPrevious, 11U)) + 4731637118230457840U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 13855839187084986751U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 5328208115460188239U;
            aOrbiterK = RotL64((aOrbiterK * 3800417611141123383U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 12479538544291412985U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 10740165998792608231U;
            aOrbiterF = RotL64((aOrbiterF * 14046827922294477379U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 6492798157284955373U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 13056825957483891921U;
            aOrbiterE = RotL64((aOrbiterE * 14882112110627751751U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 2068184064919194657U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 5656302738780746294U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16493021179127646345U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 11193756120230763294U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 17306750816837208999U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7949360041241439741U), 29U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterE, 19U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 4U));
            aIngress = aIngress + RotL64(aOrbiterK, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aScatter, 11U) + aOrbiterH) + RotL64(aOrbiterK, 20U)) + aPhaseGWandererUpdateSaltC[((aIndex + 20U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 29U) + aOrbiterF) + RotL64(aOrbiterK, 43U)) + RotL64(aCarry, 23U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 3U) + aOrbiterI) + RotL64(aOrbiterF, 35U));
            aWandererF = aWandererF + (((RotL64(aIngress, 41U) + RotL64(aOrbiterE, 5U)) + aOrbiterK) + RotL64(aCarry, 39U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 52U) + RotL64(aOrbiterI, 53U)) + aOrbiterE) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererI, 37U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 31853U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneA[((aIndex + 25089U)) & S_BLOCK1], 4U));
            aIngress ^= RotL64(aInvestLaneD[((aIndex + 26332U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32393U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 32450U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 31006U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 37U) ^ RotL64(aIngress, 3U)) + (RotL64(aCarry, 54U) + RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = ((aWandererB + RotL64(aIngress, 43U)) + 7651355040951791298U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = ((aWandererF + RotL64(aScatter, 34U)) + RotL64(aCarry, 53U)) + 13988210277931659312U;
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 23U)) + RotL64(aCarry, 23U)) + 9846849412579537783U;
            aOrbiterK = ((aWandererA + RotL64(aCross, 57U)) + RotL64(aCarry, 35U)) + 12746719939495876158U;
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 5U)) + 11498066185182895284U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 11101058955193080232U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 15513734459555672046U;
            aOrbiterF = RotL64((aOrbiterF * 6974281215677538561U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 15711108675349394643U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 4771231759949468556U;
            aOrbiterA = RotL64((aOrbiterA * 9806191054594333615U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 11449258010811305256U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 17036938391509986723U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7411466953205347639U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 6999245666776654250U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 2106819066263369528U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13005885810757743129U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 12716183358903477216U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 16752724547046059889U;
            aOrbiterE = RotL64((aOrbiterE * 11475905692393034141U), 5U);
            //
            aIngress = RotL64(aOrbiterA, 39U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterF, 3U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterE, 50U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 3U) + aOrbiterF) + RotL64(aOrbiterD, 29U)) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 53U) + aOrbiterK) + RotL64(aOrbiterF, 47U)) + RotL64(aCarry, 13U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 42U) + aOrbiterK) + RotL64(aOrbiterD, 57U)) + aPhaseGWandererUpdateSaltB[((aIndex + 24U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 11U) + aOrbiterA) + RotL64(aOrbiterE, 38U)) + RotL64(aCarry, 47U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 19U) + aOrbiterE) + RotL64(aOrbiterF, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererB, 37U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererF, 48U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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

void TwistExpander_Rugby_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 2704U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneB[((aIndex + 5218U)) & S_BLOCK1], 22U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 7201U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 937U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 5451U)) & S_BLOCK1], 6U));
            aCross ^= RotL64(aOperationLaneA[((aIndex + 1693U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aIngress, 37U)) ^ (RotL64(aPrevious, 24U) + RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = (aWandererH + RotL64(aScatter, 13U)) + 2101601659597850213U;
            aOrbiterF = ((aWandererB + RotL64(aIngress, 35U)) + RotL64(aCarry, 21U)) + 2759794072560720121U;
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 5U)) + 9443562552411269339U) + aPhaseHOrbiterAssignSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterD = (((aWandererE + RotL64(aCross, 60U)) + RotL64(aCarry, 5U)) + 10801360546699857975U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = ((aWandererD + RotL64(aScatter, 21U)) + RotL64(aCarry, 39U)) + 8020716394829332019U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 1021894212367773801U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 13346855534622490176U;
            aOrbiterB = RotL64((aOrbiterB * 12668950387932320985U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 16359309548462953836U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 12642446944680783519U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12197935153255283321U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 8197424982767553380U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 14346334610901859094U;
            aOrbiterA = RotL64((aOrbiterA * 16982899923227935679U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 14171304260534233539U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 334531601308283605U;
            aOrbiterK = RotL64((aOrbiterK * 5012968232749075075U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 10707856298471572695U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 18364775750091914766U;
            aOrbiterD = RotL64((aOrbiterD * 15735143943129143265U), 21U);
            //
            aIngress = RotL64(aOrbiterB, 29U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterF, 39U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterK, 56U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aCross, 21U) + aOrbiterB) + RotL64(aOrbiterD, 14U)) + RotL64(aCarry, 39U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterK, 3U)) + aOrbiterA) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 38U) + RotL64(aOrbiterD, 27U)) + aOrbiterF) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterK, 57U)) + aOrbiterB) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 57U) + aOrbiterF) + RotL64(aOrbiterA, 35U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererE, 56U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 15500U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneC[((aIndex + 15606U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 15632U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 10769U)) & S_BLOCK1], 44U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 11036U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 9964U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 37U) ^ RotL64(aCarry, 5U)) ^ (RotL64(aCross, 57U) + RotL64(aPrevious, 20U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = ((aWandererC + RotL64(aScatter, 13U)) + RotL64(aCarry, 53U)) + 6467297102954816305U;
            aOrbiterH = ((aWandererH + RotL64(aCross, 53U)) + RotL64(aCarry, 35U)) + 7921154109831114952U;
            aOrbiterK = ((aWandererI + RotL64(aIngress, 5U)) + RotL64(aCarry, 21U)) + 5701131763215638919U;
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 36U)) + 10022999076719002684U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = ((aWandererB + RotL64(aCross, 21U)) + 4367135243038982316U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 14445846824810383592U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 7683697954545773253U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4832124801510084629U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 17517006750428030899U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 2052484792684025476U;
            aOrbiterD = RotL64((aOrbiterD * 12463117571122469643U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 6279463052085808926U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 679280153651813684U;
            aOrbiterH = RotL64((aOrbiterH * 3047031560593583881U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 2939516520188460569U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 1960616434964712325U;
            aOrbiterF = RotL64((aOrbiterF * 15145998415466343039U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 12273819390719947361U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 5685033154709449397U;
            aOrbiterA = RotL64((aOrbiterA * 9845666295874714959U), 29U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterA, 57U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 35U));
            aIngress = aIngress + RotL64(aOrbiterK, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aCross, 3U) + RotL64(aOrbiterD, 3U)) + aOrbiterH) + RotL64(aCarry, 35U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterK, 51U)) + aOrbiterA);
            aWandererI = aWandererI + ((((RotL64(aScatter, 21U) + aOrbiterD) + RotL64(aOrbiterF, 35U)) + RotL64(aCarry, 51U)) + aPhaseHWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 30U) + RotL64(aOrbiterA, 22U)) + aOrbiterH);
            aWandererB = aWandererB + ((RotL64(aCross, 57U) + aOrbiterA) + RotL64(aOrbiterD, 43U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 13U));
            aCarry = aCarry + RotL64(aWandererF, 30U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 22895U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((aIndex + 21438U)) & S_BLOCK1], 36U));
            aIngress ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 22483U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19736U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 19748U)) & S_BLOCK1], 20U));
            aCross ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 21744U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 29U) + RotL64(aCross, 56U)) ^ (RotL64(aPrevious, 13U) + RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = ((aWandererG + RotL64(aScatter, 27U)) + RotL64(aCarry, 51U)) + 7270044678408187242U;
            aOrbiterJ = (aWandererI + RotL64(aCross, 14U)) + 10192278965379756766U;
            aOrbiterD = (((aWandererD + RotL64(aPrevious, 57U)) + RotL64(aCarry, 29U)) + 17568666746676060748U) + aPhaseHOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = (((aWandererH + RotL64(aIngress, 3U)) + RotL64(aCarry, 3U)) + 14312927531124963037U) + aPhaseHOrbiterAssignSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = (aWandererK + RotL64(aPrevious, 41U)) + 9825825726152087706U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 9696778570255265896U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 17657841352013417228U;
            aOrbiterD = RotL64((aOrbiterD * 17562220176018833833U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 16207815085909628439U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 1752979206374514227U;
            aOrbiterK = RotL64((aOrbiterK * 14182667540650694199U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 10456310689643905854U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 16127830548663742550U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4355938404839045417U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 2940917376003930842U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 7353596864777649953U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7499468723171042005U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 12725092740446150705U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 5791296650856037010U;
            aOrbiterJ = RotL64((aOrbiterJ * 760379251950502133U), 3U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterC, 3U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 24U));
            aIngress = aIngress + RotL64(aOrbiterK, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aCross, 43U) + RotL64(aOrbiterC, 29U)) + aOrbiterD) + RotL64(aCarry, 5U)) + aPhaseHWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 24U) + RotL64(aOrbiterJ, 5U)) + aOrbiterK) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 13U) + RotL64(aOrbiterJ, 13U)) + aOrbiterD);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterH, 37U));
            aWandererI = aWandererI + (((RotL64(aIngress, 3U) + RotL64(aOrbiterK, 46U)) + aOrbiterD) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 37U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererH, 60U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererG, 21U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 27031U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneA[((aIndex + 30432U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 24695U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30796U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 27416U)) & S_BLOCK1], 50U));
            aCross ^= RotL64(aOperationLaneD[((aIndex + 30254U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aIngress, 29U)) ^ (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 12U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = (aWandererH + RotL64(aIngress, 57U)) + 3650233661228036955U;
            aOrbiterB = (aWandererE + RotL64(aScatter, 48U)) + 11607036400067735729U;
            aOrbiterD = (((aWandererI + RotL64(aPrevious, 27U)) + RotL64(aCarry, 39U)) + 3899614406903883035U) + aPhaseHOrbiterAssignSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = ((aWandererG + RotL64(aCross, 39U)) + RotL64(aCarry, 57U)) + 8159156925629965143U;
            aOrbiterG = (((aWandererD + RotL64(aIngress, 11U)) + RotL64(aCarry, 23U)) + 7148903913967261270U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 9161665622287517848U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 2981535013474059469U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4434815231517266013U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 15812469008200319549U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 14687469489893270300U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14142363399696670451U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 6025209349511417063U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 12964750392311112676U;
            aOrbiterB = RotL64((aOrbiterB * 12955480283032701843U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 6572355895765394340U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 3542300121890027981U;
            aOrbiterG = RotL64((aOrbiterG * 11201491178181273935U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 6477175684045398359U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 1081388388827929314U;
            aOrbiterC = RotL64((aOrbiterC * 8752188637514143529U), 21U);
            //
            aIngress = RotL64(aOrbiterC, 43U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + RotL64(aOrbiterD, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterG, 27U)) + aOrbiterK);
            aWandererH = aWandererH + ((((RotL64(aScatter, 20U) + RotL64(aOrbiterG, 56U)) + aOrbiterD) + RotL64(aCarry, 29U)) + aPhaseHWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 29U) + aOrbiterK) + RotL64(aOrbiterB, 39U));
            aWandererG = aWandererG + (((RotL64(aCross, 57U) + aOrbiterK) + RotL64(aOrbiterC, 5U)) + RotL64(aCarry, 51U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 37U) + RotL64(aOrbiterG, 47U)) + aOrbiterC) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 21U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 42U));
            aCarry = aCarry + RotL64(aWandererE, 29U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
