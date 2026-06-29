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
    [[maybe_unused]] std::uint8_t *aFireLaneA = pWorkSpace->mFireLaneA;
    [[maybe_unused]] std::uint8_t *aFireLaneB = pWorkSpace->mFireLaneB;
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x996C5820F49E32B9ULL + 0xCE9C10AA8A28CD82ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xA2376CF3E3600DD5ULL + 0xB123B32B855D67B2ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xEB014184841C462BULL + 0x99C8981879584965ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xB8E2991B77BB5F9FULL + 0xE8BC91E248195E89ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xC66A9D1A1E3B7B77ULL + 0xB578A34FD07A26E8ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x84F49EBC8D725E6FULL + 0xA24C6A3074664226ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x9D56A2FA55181107ULL + 0xE8073C6CEB8DA138ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xB2715090284C3D37ULL + 0xC23627D1D7CE83CCULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xF662001CB72CDE69ULL + 0xC92DE168866CBCFBULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xA4CF524E9A37EF73ULL + 0xB42647BB7C89FABAULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xC67B1475DC699E91ULL + 0xDE71BB8767039D49ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xFBCEB451B5998BF9ULL + 0x98E39A71B98BF9F2ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x9B5F5ADE8F57186FULL + 0xC9614D91929B45D4ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xFEEEC5B0E26087EFULL + 0xCCAC1AB416FBABC8ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xA3E4B02140312B9DULL + 0x91F62DE1F77CAAC8ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xBF23AE93C498FE65ULL + 0xFBE2EEA962DE7629ULL);
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
        // read from: mSource, pSnow, aFireLaneA, aFireLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC
        // write to: aFireLaneA, aFireLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_a_loop_a loop 1
        // ingress from: mSource, pSnow
        // ingress directions: mSource forward forced, pSnow forward/backward random
        // cross from: pSnow, mSource
        // cross directions: pSnow backward forced, mSource backward/forward random
        // write to: aFireLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(mSource[((aIndex + 2398U)) & S_BLOCK1], 50U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 5344U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 3754U)) & S_BLOCK1], 51U) ^ RotL64(mSource[((aIndex + 1277U)) & S_BLOCK1], 22U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCross, 41U) + RotL64(aPrevious, 18U)) ^ (RotL64(aCarry, 5U) + RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterK = (((aWandererD + RotL64(aIngress, 41U)) + RotL64(aCarry, 21U)) + 8975885703279267062U) + aNonceWordL;
            aOrbiterC = ((aWandererJ + RotL64(aCross, 27U)) + RotL64(aCarry, 37U)) + 8664844915562660637U;
            aOrbiterF = (aWandererC + RotL64(aPrevious, 60U)) + 12281774799736296726U;
            aOrbiterJ = (aWandererG + RotL64(aScatter, 13U)) + 15347461352311329726U;
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 21U)) + RotL64(aCarry, 57U)) + 12967500561828907834U;
            aOrbiterA = ((aWandererI + RotL64(aCross, 43U)) + 5002833859280402726U) + aOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = ((aWandererH + RotL64(aScatter, 53U)) + 11908257536954668983U) + aOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = (aWandererK + RotL64(aIngress, 39U)) + 17017174811949227162U;
            aOrbiterD = (aWandererF + RotL64(aScatter, 19U)) + 16851323125613931180U;
            aOrbiterI = ((aWandererE + RotL64(aCross, 5U)) + 13469326957728686706U) + aNonceWordP;
            aOrbiterE = (aWandererB + RotL64(aIngress, 46U)) + 5228638551056105241U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 11945166198089308564U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 16268645041872996022U;
            aOrbiterF = RotL64((aOrbiterF * 5391448793718370911U), 29U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterH) + 14781204627695095701U) + aOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1]) + aNonceWordO;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 5365325354838101092U;
            aOrbiterC = RotL64((aOrbiterC * 8017284997946310807U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 563147416025715953U) + aNonceWordB;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 14660867395395625851U;
            aOrbiterG = RotL64((aOrbiterG * 4769458126865307103U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 3168989056355712105U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterH) ^ 16179131669773665579U) ^ aOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterD = RotL64((aOrbiterD * 5641461617066671723U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 4160220074225527179U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 8597134686962559111U;
            aOrbiterK = RotL64((aOrbiterK * 639572585431474015U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 16811551552456811661U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 5827323970423386301U;
            aOrbiterI = RotL64((aOrbiterI * 9328247349730652021U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 15583234353262170227U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 2950816254621717748U;
            aOrbiterE = RotL64((aOrbiterE * 1102417597476170143U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 4426165025104306337U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 11871220132164971152U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2366168050042802207U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 3832424136113939717U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 17673885217916768611U) ^ aNonceWordA;
            aOrbiterA = RotL64((aOrbiterA * 10887063696370811871U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 3479289844909914390U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 9498461576098567546U;
            aOrbiterH = RotL64((aOrbiterH * 8734492074299676555U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 10645314291190544864U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 8975885703279267062U;
            aOrbiterJ = RotL64((aOrbiterJ * 16584086014947250551U), 13U);
            //
            aIngress = RotL64(aOrbiterC, 13U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 44U));
            aIngress = aIngress + (RotL64(aOrbiterH, 5U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterK, 27U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterD, 21U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterG, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterC, 5U)) + aOrbiterE) + aNonceWordG);
            aWandererE = aWandererE + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterF, 3U)) + aOrbiterB) + aNonceWordD);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterA, 41U)) + aOrbiterG);
            aWandererF = aWandererF + (((RotL64(aScatter, 28U) + RotL64(aOrbiterA, 36U)) + aOrbiterK) + aNonceWordI);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 53U) + aOrbiterA) + RotL64(aOrbiterD, 47U)) + aWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 11U) + aOrbiterB) + RotL64(aOrbiterE, 43U)) + aWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterH, 11U)) + aOrbiterK) + aNonceWordH);
            aWandererK = aWandererK + (((RotL64(aScatter, 58U) + aOrbiterH) + RotL64(aOrbiterC, 23U)) + RotL64(aCarry, 37U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterI, 21U)) + aOrbiterB);
            aWandererB = aWandererB + (((RotL64(aCross, 37U) + aOrbiterC) + RotL64(aOrbiterJ, 51U)) + RotL64(aCarry, 21U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 5U) + aOrbiterI) + RotL64(aOrbiterJ, 28U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 41U));
            aCarry = aCarry + (RotL64(aWandererC, 36U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererK, 44U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aFireLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_a loop 2
        // ingress from: aFireLaneA, pSnow
        // ingress directions: aFireLaneA forward forced, pSnow forward/backward random
        // cross from: aFireLaneA, mSource
        // cross directions: aFireLaneA backward forced, mSource backward/forward random
        // write to: aFireLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aFireLaneA[((aIndex + 5860U)) & S_BLOCK1], 53U) ^ RotL64(pSnow[((aIndex + 9290U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 6105U)) & S_BLOCK1], 54U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 7484U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aIngress, 35U)) ^ (RotL64(aPrevious, 20U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterH = (aWandererH + RotL64(aIngress, 27U)) + 17454559218352016650U;
            aOrbiterD = (((aWandererG + RotL64(aCross, 13U)) + RotL64(aCarry, 13U)) + 8005709669325164803U) + aNonceWordP;
            aOrbiterE = (aWandererB + RotL64(aPrevious, 18U)) + 13393741948412816357U;
            aOrbiterF = (aWandererC + RotL64(aScatter, 11U)) + 3665865624348875553U;
            aOrbiterB = (aWandererD + RotL64(aPrevious, 53U)) + 8334142570031883436U;
            aOrbiterI = (aWandererE + RotL64(aCross, 37U)) + 17226066128706139657U;
            aOrbiterA = (((aWandererI + RotL64(aScatter, 51U)) + 3319093033121522613U) + aOrbiterAssignSaltC[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordD;
            aOrbiterC = (aWandererF + RotL64(aIngress, 23U)) + 6657535603401588798U;
            aOrbiterK = ((aWandererK + RotL64(aScatter, 5U)) + 5469746182326331147U) + aNonceWordE;
            aOrbiterJ = ((((aWandererA + RotL64(aIngress, 29U)) + RotL64(aCarry, 19U)) + 17846791786050221418U) + aOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordN;
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 46U)) + RotL64(aCarry, 57U)) + 15939541003714896288U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 12076763190461077406U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 3594038213596405284U;
            aOrbiterE = RotL64((aOrbiterE * 10244002692575821495U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 8301291631324464622U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 8460406137668390582U;
            aOrbiterB = RotL64((aOrbiterB * 9117147929757711595U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 7612394867020871200U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 8525076134853103975U;
            aOrbiterC = RotL64((aOrbiterC * 5790440201072204659U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 11929899088215090379U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 7119509166360685726U;
            aOrbiterD = RotL64((aOrbiterD * 1662341427992528823U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 5081078459225240607U) + aNonceWordG;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 17149991983909906705U;
            aOrbiterJ = RotL64((aOrbiterJ * 950223374568067343U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 8817303295675241994U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 7962039282652745113U;
            aOrbiterG = RotL64((aOrbiterG * 12773588587795522121U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 13596273086338032370U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 8186297702278180956U) ^ aOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6226504769888753861U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 1696277861691580263U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 17360461831507082959U;
            aOrbiterA = RotL64((aOrbiterA * 1651378456022210983U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 1384868996572650981U) + aNonceWordL;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 2039624849777183290U) ^ aOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13148024378138271937U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 14530407348595669913U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 18023931565754525034U;
            aOrbiterH = RotL64((aOrbiterH * 18025122652259338105U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 11245556671533878373U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 17454559218352016650U;
            aOrbiterK = RotL64((aOrbiterK * 15665798947106818229U), 53U);
            //
            aIngress = RotL64(aOrbiterJ, 57U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 3U));
            aIngress = aIngress + (RotL64(aOrbiterA, 47U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterD, 13U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 27U));
            aIngress = aIngress + RotL64(aOrbiterH, 44U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aScatter, 43U) + aOrbiterI) + RotL64(aOrbiterG, 18U)) + aNonceWordK);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 3U) + aOrbiterA) + RotL64(aOrbiterF, 27U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 11U) + aOrbiterJ) + RotL64(aOrbiterA, 37U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 24U) + aOrbiterB) + RotL64(aOrbiterH, 5U));
            aWandererH = aWandererH + (((RotL64(aIngress, 21U) + RotL64(aOrbiterB, 47U)) + aOrbiterC) + RotL64(aCarry, 5U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterH, 51U)) + aOrbiterC) + aNonceWordO);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 37U) + aOrbiterI) + RotL64(aOrbiterF, 20U)) + aWandererUpdateSaltC[((aIndex + 8U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 35U) + aOrbiterC) + RotL64(aOrbiterK, 13U));
            aWandererC = aWandererC + ((((RotL64(aScatter, 46U) + aOrbiterB) + RotL64(aOrbiterE, 53U)) + RotL64(aCarry, 23U)) + aNonceWordM);
            aWandererG = aWandererG ^ ((((RotL64(aPrevious, 57U) + aOrbiterD) + RotL64(aOrbiterJ, 39U)) + aNonceWordH) + aWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aIngress, 19U) + aOrbiterB) + RotL64(aOrbiterF, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 41U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 60U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 19U);
            aCarry = aCarry + RotL64(aIngress, 36U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aFireLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_a loop 3
        // ingress from: aFireLaneB, mSource
        // ingress directions: aFireLaneB forward forced, mSource forward/backward random
        // cross from: aFireLaneA, pSnow
        // cross directions: aFireLaneA backward forced, pSnow backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aFireLaneB[((aIndex + 13968U)) & S_BLOCK1], 52U) ^ RotL64(mSource[((aIndex + 13246U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 14418U)) & S_BLOCK1], 57U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 13002U)) & S_BLOCK1], 20U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 11U) + RotL64(aPrevious, 54U)) ^ (RotL64(aCarry, 23U) ^ RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterI = ((aWandererG + RotL64(aPrevious, 10U)) + 6916817163240024692U) + aOrbiterAssignSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = (aWandererB + RotL64(aIngress, 43U)) + 14554930751292077817U;
            aOrbiterB = (aWandererF + RotL64(aCross, 13U)) + 1098305064484336101U;
            aOrbiterG = (aWandererJ + RotL64(aScatter, 19U)) + 12192821172420471527U;
            aOrbiterD = (aWandererD + RotL64(aPrevious, 5U)) + 2435134991707318845U;
            aOrbiterJ = (((aWandererI + RotL64(aIngress, 57U)) + 1896745368738512624U) + aOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1]) + aNonceWordG;
            aOrbiterK = (aWandererK + RotL64(aScatter, 41U)) + 1114996424222923873U;
            aOrbiterC = ((aWandererC + RotL64(aCross, 39U)) + 9839135798371512656U) + aNonceWordL;
            aOrbiterH = (((aWandererE + RotL64(aPrevious, 47U)) + RotL64(aCarry, 27U)) + 8037967239603177043U) + aNonceWordK;
            aOrbiterE = ((aWandererH + RotL64(aIngress, 30U)) + RotL64(aCarry, 39U)) + 15185468738487237432U;
            aOrbiterF = ((aWandererA + RotL64(aCross, 51U)) + RotL64(aCarry, 19U)) + 4912098316394854543U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 13142688607850380888U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 4507379759608945839U;
            aOrbiterB = RotL64((aOrbiterB * 2989332387754215967U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 7299006009652289342U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 5390655277207053627U;
            aOrbiterJ = RotL64((aOrbiterJ * 10973744708856143715U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 6744737023577785725U) + aNonceWordN;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 15539737698867067285U;
            aOrbiterA = RotL64((aOrbiterA * 4686092035261336911U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 13329866734681377952U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 13284937458969166257U) ^ aNonceWordO;
            aOrbiterE = RotL64((aOrbiterE * 3965985432462699445U), 41U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterJ) + 8695002088915702168U) + aOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1]) + aNonceWordI;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 3858059421620839286U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9559783727301092937U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 6609163873243179836U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 9416165620556710540U;
            aOrbiterC = RotL64((aOrbiterC * 240385043740268229U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 1578449067529000433U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 14309000104419489303U) ^ aOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7599078306153684729U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 15785180680737461320U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 10099222679918382021U;
            aOrbiterF = RotL64((aOrbiterF * 2012232597046182581U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 10666287769220108179U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 13648647399222807034U;
            aOrbiterG = RotL64((aOrbiterG * 10772381733103127201U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 9292207828896796810U) + aNonceWordA;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 9155130791347443553U;
            aOrbiterI = RotL64((aOrbiterI * 16838229790655977057U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 11334395119119245556U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 6916817163240024692U;
            aOrbiterD = RotL64((aOrbiterD * 9640906826978028183U), 39U);
            //
            aIngress = RotL64(aOrbiterJ, 21U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + (RotL64(aOrbiterF, 51U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterD, 13U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterC, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aPrevious, 56U) + aOrbiterG) + RotL64(aOrbiterC, 23U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterG, 60U)) + aOrbiterJ);
            aWandererA = aWandererA + (((RotL64(aScatter, 37U) + RotL64(aOrbiterG, 27U)) + aOrbiterK) + RotL64(aCarry, 21U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 39U) + aOrbiterC) + RotL64(aOrbiterF, 53U));
            aWandererH = aWandererH + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterB, 37U)) + aOrbiterE) + aNonceWordD) + aWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 47U) + aOrbiterH) + RotL64(aOrbiterB, 44U)) + aNonceWordB);
            aWandererD = aWandererD + ((RotL64(aCross, 13U) + RotL64(aOrbiterD, 35U)) + aOrbiterI);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterA, 19U)) + aOrbiterE) + aNonceWordF);
            aWandererJ = aWandererJ + (((RotL64(aCross, 27U) + aOrbiterB) + RotL64(aOrbiterK, 57U)) + RotL64(aCarry, 37U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterH, 11U));
            aWandererI = aWandererI + (((RotL64(aScatter, 30U) + RotL64(aOrbiterD, 13U)) + aOrbiterG) + aWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 60U));
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererD);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 37U));
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererC);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + RotL64(aWandererH, 54U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_a loop 4
        // ingress from: aExpandLaneA, pSnow, aFireLaneA
        // ingress directions: aExpandLaneA forward forced, pSnow forward forced, aFireLaneA forward/backward random
        // cross from: mSource, aFireLaneB
        // cross directions: mSource backward forced, aFireLaneB backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 17420U)) & S_BLOCK1], 6U) ^ RotL64(pSnow[((aIndex + 16676U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 16437U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(mSource[((S_BLOCK1 - aIndex + 20963U)) & S_BLOCK1], 41U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 16652U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aIngress, 27U) + RotL64(aCarry, 40U)) ^ (RotL64(aCross, 13U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterA = (aWandererI + RotL64(aScatter, 3U)) + 5510690816044082200U;
            aOrbiterD = ((aWandererD + RotL64(aCross, 47U)) + 15967820875033940530U) + aNonceWordB;
            aOrbiterK = (aWandererB + RotL64(aPrevious, 42U)) + 539348720848176221U;
            aOrbiterH = ((aWandererH + RotL64(aIngress, 51U)) + RotL64(aCarry, 5U)) + 15779318183635560817U;
            aOrbiterF = ((aWandererC + RotL64(aScatter, 39U)) + 14511058534424187469U) + aNonceWordK;
            aOrbiterB = (aWandererG + RotL64(aCross, 37U)) + 5811130556873428391U;
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 23U)) + 1085928476499444025U) + aOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = (aWandererE + RotL64(aIngress, 13U)) + 6973335316600768130U;
            aOrbiterE = (((aWandererJ + RotL64(aCross, 30U)) + RotL64(aCarry, 53U)) + 10747243745475009744U) + aOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = (aWandererA + RotL64(aScatter, 11U)) + 1072260008981349754U;
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 19U)) + RotL64(aCarry, 43U)) + 2018772405352495753U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 1092091597048996547U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 15103140149542167197U;
            aOrbiterK = RotL64((aOrbiterK * 621856991658027989U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 13194619321108681542U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 16749188603268621850U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9575408950550922039U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 7427959503086895166U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 9895804051379551393U;
            aOrbiterC = RotL64((aOrbiterC * 2701997336201570715U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 4526020800679774259U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 4484850928870048176U;
            aOrbiterD = RotL64((aOrbiterD * 17556987520625677313U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 1837404844299040155U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 15213208978489570694U;
            aOrbiterE = RotL64((aOrbiterE * 7062740584650274133U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 9615231781751396800U) + aNonceWordC;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 15872192167825648096U;
            aOrbiterJ = RotL64((aOrbiterJ * 2900526493682580729U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 12530672039655918903U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 10617836782870315804U;
            aOrbiterF = RotL64((aOrbiterF * 9716778004909794973U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 550750725406860977U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 3498554352021622907U;
            aOrbiterA = RotL64((aOrbiterA * 9846933294851238495U), 41U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterJ) + 4059346317776216057U) + aOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1]) + aNonceWordG;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 14161853870874499023U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8601560894939097781U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 4088411647683253905U) + aOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 9321241420172776158U;
            aOrbiterI = RotL64((aOrbiterI * 4167888281125330225U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 8527337525861632945U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 5510690816044082200U) ^ aNonceWordM;
            aOrbiterG = RotL64((aOrbiterG * 12464836001483233379U), 51U);
            //
            aIngress = RotL64(aOrbiterA, 50U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterE, 43U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterC, 21U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterK, 41U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 24U));
            aIngress = aIngress + RotL64(aOrbiterG, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aScatter, 53U) + RotL64(aOrbiterJ, 51U)) + aOrbiterK) + aNonceWordH);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterB, 39U)) + aOrbiterG);
            aWandererA = aWandererA + ((RotL64(aCross, 35U) + aOrbiterK) + RotL64(aOrbiterC, 34U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 41U) + aOrbiterJ) + RotL64(aOrbiterA, 21U)) + aWandererUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 56U) + aOrbiterJ) + RotL64(aOrbiterI, 37U)) + RotL64(aCarry, 57U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 13U) + aOrbiterJ) + RotL64(aOrbiterF, 3U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 27U) + RotL64(aOrbiterC, 56U)) + aOrbiterD) + RotL64(aCarry, 39U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterE, 29U)) + aOrbiterB) + aWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aCross, 23U) + aOrbiterA) + RotL64(aOrbiterH, 19U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 4U) + RotL64(aOrbiterH, 53U)) + aOrbiterE);
            aWandererF = aWandererF + (((RotL64(aScatter, 43U) + RotL64(aOrbiterK, 41U)) + aOrbiterF) + aNonceWordA);
            //
            aCarry = aCarry + (RotL64(aWandererB, 14U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererC);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 60U));
            aCarry = aCarry + RotL64(aWandererI, 37U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_a loop 5
        // ingress from: aExpandLaneB, mSource, pSnow, aFireLaneA
        // ingress directions: aExpandLaneB forward forced, mSource forward forced, pSnow forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneA, aFireLaneB
        // cross directions: aExpandLaneA backward forced, aFireLaneB backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 24538U)) & S_BLOCK1], 43U) ^ RotL64(mSource[((aIndex + 24683U)) & S_BLOCK1], 11U));
            aIngress ^= (RotL64(pSnow[((aIndex + 26783U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 25105U)) & S_BLOCK1], 34U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26350U)) & S_BLOCK1], 46U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 23639U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCross, 13U) + RotL64(aIngress, 57U)) ^ (RotL64(aCarry, 29U) ^ RotL64(aPrevious, 42U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterF = (aWandererI + RotL64(aCross, 21U)) + 17074147006464019918U;
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 57U)) + 10559516626129419928U) + aNonceWordN;
            aOrbiterI = (((aWandererK + RotL64(aIngress, 46U)) + RotL64(aCarry, 57U)) + 13280363679503946221U) + aOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = (aWandererF + RotL64(aPrevious, 27U)) + 17657115422132457413U;
            aOrbiterB = (aWandererC + RotL64(aIngress, 53U)) + 13325837013304973008U;
            aOrbiterJ = ((aWandererA + RotL64(aCross, 35U)) + RotL64(aCarry, 43U)) + 3059707750486106037U;
            aOrbiterA = (aWandererD + RotL64(aScatter, 29U)) + 4529045702503050852U;
            aOrbiterD = (aWandererE + RotL64(aPrevious, 13U)) + 10726578475550904292U;
            aOrbiterK = ((((aWandererG + RotL64(aScatter, 3U)) + RotL64(aCarry, 27U)) + 14832537837996659885U) + aOrbiterAssignSaltE[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordM;
            aOrbiterC = (aWandererH + RotL64(aPrevious, 38U)) + 220094417441809246U;
            aOrbiterH = (aWandererB + RotL64(aIngress, 19U)) + 15343130035105342194U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 16592263353426409884U) + aNonceWordH;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 15649290906447931918U;
            aOrbiterI = RotL64((aOrbiterI * 8405875177836650731U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 11437410545843708269U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 5859769136073011444U;
            aOrbiterJ = RotL64((aOrbiterJ * 1065016088086441107U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 15188064100307340341U) + aOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 4367466521843260049U;
            aOrbiterE = RotL64((aOrbiterE * 15916715854192820923U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 8482617283860566845U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 2585745804937342972U;
            aOrbiterB = RotL64((aOrbiterB * 8267269625632139809U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 1687641344403425541U) + aNonceWordK;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 13667916445979421400U;
            aOrbiterG = RotL64((aOrbiterG * 8191322670355590027U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 7684258716388029228U) + aOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 14764266202380443369U;
            aOrbiterH = RotL64((aOrbiterH * 1746254773647650741U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 12685190466981675661U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 9958374400222383893U;
            aOrbiterA = RotL64((aOrbiterA * 12696606920219838929U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 1352584794098160330U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 16057453941015251708U;
            aOrbiterD = RotL64((aOrbiterD * 6051546505117202495U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 5642244742563733299U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 2946279435712646692U;
            aOrbiterF = RotL64((aOrbiterF * 3711867103848631343U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 17305358424001395035U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 1831722001182742673U;
            aOrbiterC = RotL64((aOrbiterC * 13867284970939557547U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 12354430852596737299U) + aOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 17074147006464019918U;
            aOrbiterK = RotL64((aOrbiterK * 17316050599218057961U), 29U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterE, 21U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 35U));
            aIngress = aIngress + (RotL64(aOrbiterB, 54U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 39U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 13U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterG, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterG, 13U)) + aOrbiterE) + aNonceWordJ);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 42U) + aOrbiterC) + RotL64(aOrbiterD, 35U)) + RotL64(aCarry, 23U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 37U) + aOrbiterD) + RotL64(aOrbiterB, 37U));
            aWandererC = aWandererC + ((((RotL64(aCross, 21U) + aOrbiterH) + RotL64(aOrbiterF, 56U)) + RotL64(aCarry, 3U)) + aWandererUpdateSaltC[((aIndex + 10U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterG, 19U)) + aOrbiterK) + aNonceWordC);
            aWandererE = aWandererE + (((RotL64(aCross, 35U) + RotL64(aOrbiterB, 21U)) + aOrbiterH) + aWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 10U) + aOrbiterF) + RotL64(aOrbiterJ, 5U)) + aNonceWordI);
            aWandererF = aWandererF + (((RotL64(aScatter, 13U) + aOrbiterA) + RotL64(aOrbiterI, 43U)) + aNonceWordL);
            aWandererG = aWandererG ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterG, 46U)) + aOrbiterC);
            aWandererD = aWandererD + ((RotL64(aScatter, 27U) + aOrbiterJ) + RotL64(aOrbiterI, 51U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 57U) + aOrbiterB) + RotL64(aOrbiterE, 53U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + (RotL64(aWandererD, 38U) ^ aWandererB);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + RotL64(aWandererH, 30U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_a loop 6
        // ingress from: aExpandLaneC, aExpandLaneA, aFireLaneA
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneB, mSource, pSnow, aFireLaneB
        // cross directions: aExpandLaneB backward forced, mSource backward forced, pSnow backward forced, aFireLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 28576U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneA[((aIndex + 30424U)) & S_BLOCK1], 10U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 32328U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30414U)) & S_BLOCK1], 13U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 31011U)) & S_BLOCK1], 35U));
            aCross ^= (RotL64(pSnow[((S_BLOCK1 - aIndex + 32066U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneB[((aIndex + 29801U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCarry, 39U)) + (RotL64(aCross, 51U) + RotL64(aPrevious, 22U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterA = ((aWandererE + RotL64(aScatter, 10U)) + RotL64(aCarry, 23U)) + 8685374557928800912U;
            aOrbiterF = ((aWandererK + RotL64(aCross, 23U)) + 3482312691892161229U) + aNonceWordG;
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 5U)) + 6948130297389161165U) + aNonceWordL;
            aOrbiterE = (((aWandererC + RotL64(aIngress, 21U)) + RotL64(aCarry, 13U)) + 5506385663788942690U) + aNonceWordM;
            aOrbiterG = (aWandererD + RotL64(aPrevious, 39U)) + 17859982009307397161U;
            aOrbiterD = (aWandererB + RotL64(aScatter, 27U)) + 9178488809207094043U;
            aOrbiterH = (((aWandererF + RotL64(aCross, 43U)) + 1835479501226057169U) + aOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordN;
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 57U)) + 5368101733632614939U) + aOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 37U)) + 9050459666576835422U;
            aOrbiterB = (aWandererI + RotL64(aScatter, 47U)) + 9042186993119635078U;
            aOrbiterC = ((aWandererA + RotL64(aCross, 34U)) + RotL64(aCarry, 5U)) + 17528342580198295025U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 6495418332558436882U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterA) ^ 8834495762667327342U) ^ aOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterK = RotL64((aOrbiterK * 10783141541937645995U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 4364314196965690905U) + aOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 6357485231062120459U;
            aOrbiterD = RotL64((aOrbiterD * 289429584586504995U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 3321488322626415347U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 10817330671781848737U;
            aOrbiterJ = RotL64((aOrbiterJ * 15875919466358823335U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 17974092279281611763U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 2871472057292789157U;
            aOrbiterA = RotL64((aOrbiterA * 16104199340711015181U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 15187929795092006849U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 13482063681546475923U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14466266308157364963U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 6232152545071397380U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 17488906002621373262U) ^ aNonceWordJ;
            aOrbiterH = RotL64((aOrbiterH * 4719340606442742577U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 12444819880507588549U) + aOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 13808941689757772497U;
            aOrbiterI = RotL64((aOrbiterI * 6541360905282412317U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 8049361354387692374U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 7137831335606542401U;
            aOrbiterB = RotL64((aOrbiterB * 11022231291507235007U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 7230759462019420058U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 3923744511976096944U;
            aOrbiterF = RotL64((aOrbiterF * 9953869624243563101U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 15967667946023263856U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 8677583624693910669U;
            aOrbiterG = RotL64((aOrbiterG * 10737731876339973717U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 1604347321263511013U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 8685374557928800912U;
            aOrbiterE = RotL64((aOrbiterE * 14103365695918844461U), 21U);
            //
            aIngress = RotL64(aOrbiterB, 19U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 11U));
            aIngress = aIngress + (RotL64(aOrbiterH, 54U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 23U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + RotL64(aOrbiterF, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aCross, 35U) + aOrbiterE) + RotL64(aOrbiterI, 51U)) + RotL64(aCarry, 53U));
            aWandererD = aWandererD ^ ((((RotL64(aIngress, 51U) + RotL64(aOrbiterF, 39U)) + aOrbiterI) + aNonceWordP) + aWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aScatter, 38U) + aOrbiterD) + RotL64(aOrbiterI, 14U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterH, 23U)) + aOrbiterA);
            aWandererC = aWandererC + (((RotL64(aScatter, 5U) + RotL64(aOrbiterC, 47U)) + aOrbiterK) + RotL64(aCarry, 57U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterH, 19U)) + aOrbiterJ);
            aWandererI = aWandererI + (((RotL64(aIngress, 43U) + RotL64(aOrbiterB, 3U)) + aOrbiterI) + aWandererUpdateSaltF[((aIndex + 18U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 23U) + aOrbiterG) + RotL64(aOrbiterF, 41U));
            aWandererF = aWandererF + ((RotL64(aCross, 21U) + RotL64(aOrbiterC, 27U)) + aOrbiterF);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 14U) + aOrbiterK) + RotL64(aOrbiterH, 12U)) + aNonceWordH);
            aWandererG = aWandererG + ((RotL64(aIngress, 47U) + RotL64(aOrbiterD, 43U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererB, 18U) ^ aWandererI);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + (RotL64(aWandererJ, 37U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererG);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + RotL64(aWandererC, 5U);
            aCarry = aCarry + RotL64(aIngress, 50U);
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
    [[maybe_unused]] std::uint8_t *aFireLaneC = pWorkSpace->mFireLaneC;
    [[maybe_unused]] std::uint8_t *aFireLaneD = pWorkSpace->mFireLaneD;
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xC371648BDA754429ULL + 0xFE74A90032E535A7ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xE6A0E57691944977ULL + 0x8B4606F0AEF921B4ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xA9554D706AD5E559ULL + 0xE892B724B4A518B5ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xF0E59126F825E4B5ULL + 0xDB77747CC9C7F2DCULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x84B171889EF3EA43ULL + 0xD54167BDD6861D7DULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xDB672939B49DFAA5ULL + 0x8685D7B7A435DA91ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xDA9802978F4EA97BULL + 0xB537FD782A307F08ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x8345F657A7B48033ULL + 0xB232E0178412B035ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x9B8AC342759D341DULL + 0xC36737F75EEFB37AULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x89DEC38D6EF3C3EFULL + 0xF94EEF5765A9C756ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xEB8CC905DBB741DBULL + 0x82361CCC19D1DAB8ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xFD2BF2357D68BD7DULL + 0xD117A903F88DA21AULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x84A45429623D9C43ULL + 0xD4262D46B89CC4B9ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xCCF9FB27DBFAA11BULL + 0xB6957C8CB5FF3C30ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xB242004090A788DFULL + 0xC5DC9EB80638FA30ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xA44CADF6AF6B3B57ULL + 0xB65A6E57A644A4B4ULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aFireLaneC, aFireLaneD, aOperationLaneA, aOperationLaneB, aOperationLaneC
        // write to: aFireLaneC, aFireLaneD, aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // kdf_a_loop_b loop 1
        // ingress from: aExpandLaneA, aExpandLaneB
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward/forward random
        // write to: aFireLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aExpandLaneA[((aIndex + 3686U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 293U)) & S_BLOCK1], 24U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5194U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneD[((aIndex + 1913U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 11U) + RotL64(aPrevious, 23U)) + (RotL64(aCross, 58U) ^ RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterI = (aWandererB + RotL64(aCross, 35U)) + 8506388683755208267U;
            aOrbiterD = (((aWandererI + RotL64(aPrevious, 28U)) + RotL64(aCarry, 19U)) + 2179323259055019735U) + aNonceWordA;
            aOrbiterJ = (aWandererF + RotL64(aScatter, 39U)) + 3345902531140983016U;
            aOrbiterF = ((aWandererE + RotL64(aIngress, 11U)) + 17456139311481306584U) + aOrbiterAssignSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterA = (((aWandererJ + RotL64(aCross, 43U)) + RotL64(aCarry, 57U)) + 14587864088462311164U) + aNonceWordL;
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 3U)) + 13178947246650647057U) + aOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = ((aWandererD + RotL64(aIngress, 53U)) + RotL64(aCarry, 27U)) + 12866578138946916962U;
            aOrbiterB = (aWandererK + RotL64(aScatter, 23U)) + 13098524333655118173U;
            aOrbiterC = (aWandererC + RotL64(aCross, 60U)) + 15451329483787541982U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 9494299579678389385U) + aOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 15581954810375490643U) ^ aOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13670002280188424825U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 4487042505730624892U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 2774455928791636186U;
            aOrbiterA = RotL64((aOrbiterA * 15847933919136777451U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 12435319582397755819U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 10077180055177766823U;
            aOrbiterF = RotL64((aOrbiterF * 3924363471701748703U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 10391963896910956455U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 6149237416725301794U;
            aOrbiterC = RotL64((aOrbiterC * 10115917698918612823U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 15673402771629639978U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 14729117178956592426U;
            aOrbiterD = RotL64((aOrbiterD * 9070464269215820531U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 14492001279368870240U) + aNonceWordE;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 6278248084483259952U) ^ aNonceWordK;
            aOrbiterI = RotL64((aOrbiterI * 16731228350971263873U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 15727518866499740411U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 8652631010810965473U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9508484121620912715U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 13660890300188313775U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 14699253534935936300U;
            aOrbiterG = RotL64((aOrbiterG * 3978135617259934869U), 27U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterA) + 1621689916308271346U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordF;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 5651399428852950385U;
            aOrbiterE = RotL64((aOrbiterE * 12220143634120124133U), 47U);
            //
            aIngress = RotL64(aOrbiterI, 19U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 46U));
            aIngress = aIngress + (RotL64(aOrbiterE, 11U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 27U));
            aIngress = aIngress + RotL64(aOrbiterG, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 30U) + RotL64(aOrbiterJ, 5U)) + aOrbiterA);
            aWandererB = aWandererB + (((((RotL64(aIngress, 57U) + aOrbiterG) + RotL64(aOrbiterI, 43U)) + RotL64(aCarry, 5U)) + aNonceWordJ) + aWandererUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterJ, 39U)) + aOrbiterG) + aNonceWordH);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 53U) + aOrbiterF) + RotL64(aOrbiterC, 51U)) + RotL64(aCarry, 29U)) + aNonceWordO);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 48U) + aOrbiterE) + RotL64(aOrbiterC, 60U));
            aWandererC = aWandererC + ((RotL64(aCross, 19U) + aOrbiterD) + RotL64(aOrbiterA, 27U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterB, 11U)) + aOrbiterC) + aWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 35U) + aOrbiterI) + RotL64(aOrbiterD, 35U)) + aNonceWordB);
            aWandererD = aWandererD ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterG, 18U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 40U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererD);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 37U));
            aCarry = aCarry + RotL64(aWandererE, 53U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aFireLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_b loop 2
        // ingress from: aFireLaneC, aExpandLaneB, aExpandLaneC
        // ingress directions: aFireLaneC forward forced, aExpandLaneB forward forced, aExpandLaneC forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward/forward random
        // write to: aFireLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aFireLaneC[((aIndex + 8193U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneB[((aIndex + 6517U)) & S_BLOCK1], 24U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 9823U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 8226U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((aIndex + 7438U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aPrevious, 51U) ^ RotL64(aCarry, 37U)) + (RotL64(aIngress, 4U) + RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterF = (aWandererA + RotL64(aScatter, 47U)) + 11700815697312060726U;
            aOrbiterI = (((aWandererI + RotL64(aIngress, 51U)) + RotL64(aCarry, 43U)) + 11808423452327465441U) + aNonceWordD;
            aOrbiterK = (aWandererF + RotL64(aCross, 57U)) + 8670503858631730886U;
            aOrbiterA = (((aWandererG + RotL64(aPrevious, 4U)) + 2400061067991988544U) + aOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1]) + aNonceWordP;
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 19U)) + 16163118178366229686U) + aNonceWordL;
            aOrbiterH = ((aWandererK + RotL64(aIngress, 29U)) + 3280178595904941068U) + aOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 11U)) + RotL64(aCarry, 13U)) + 3298683600817047727U;
            aOrbiterE = ((aWandererE + RotL64(aCross, 40U)) + RotL64(aCarry, 51U)) + 16321624053445183574U;
            aOrbiterD = (aWandererJ + RotL64(aScatter, 35U)) + 6730229877611375225U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 10162830636713641322U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 15646771327759599256U;
            aOrbiterK = RotL64((aOrbiterK * 15333053762177144775U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 14841751262270544102U) + aNonceWordC;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 9545541117228834895U;
            aOrbiterH = RotL64((aOrbiterH * 11529769874752969377U), 43U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterA) + 14676615635857599982U) + aOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1]) + aNonceWordA;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 1231768638470558855U;
            aOrbiterC = RotL64((aOrbiterC * 2716808508509014677U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 1945905595345404833U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 1406171421638586846U;
            aOrbiterD = RotL64((aOrbiterD * 4577864352425476233U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 1970292335806697198U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 12309719390375013297U;
            aOrbiterJ = RotL64((aOrbiterJ * 16540660957923687327U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 5352135521358954576U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 15465675376193501658U;
            aOrbiterF = RotL64((aOrbiterF * 16385761112921041387U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 2842123638916600369U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 3544764287036748668U;
            aOrbiterE = RotL64((aOrbiterE * 3360772950777850115U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 6038297172906492282U) + aOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterI = (((aOrbiterI ^ aOrbiterC) ^ 10249342332287140970U) ^ aOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterI = RotL64((aOrbiterI * 16701083081566042277U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 1662076777040529446U) + aNonceWordI;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 1949705569959740274U;
            aOrbiterA = RotL64((aOrbiterA * 11340691546658994529U), 21U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterH, 14U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 57U));
            aIngress = aIngress + (RotL64(aOrbiterE, 35U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + RotL64(aOrbiterK, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aCross, 11U) + RotL64(aOrbiterI, 51U)) + aOrbiterJ);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 60U) + aOrbiterD) + RotL64(aOrbiterH, 42U));
            aWandererF = aWandererF + ((RotL64(aScatter, 19U) + RotL64(aOrbiterA, 3U)) + aOrbiterK);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterA, 11U)) + aOrbiterE) + aWandererUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 43U) + aOrbiterI) + RotL64(aOrbiterD, 57U)) + aNonceWordN);
            aWandererG = aWandererG ^ (((RotL64(aCross, 5U) + aOrbiterK) + RotL64(aOrbiterF, 27U)) + aNonceWordH);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 37U) + RotL64(aOrbiterF, 35U)) + aOrbiterI) + RotL64(aCarry, 43U)) + aNonceWordK);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 53U) + aOrbiterJ) + RotL64(aOrbiterA, 47U)) + aWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 24U) + RotL64(aOrbiterC, 22U)) + aOrbiterD) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 28U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 5U));
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererG, 11U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aFireLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_b loop 3
        // ingress from: aFireLaneD, aExpandLaneD, aExpandLaneC
        // ingress directions: aFireLaneD forward forced, aExpandLaneD forward forced, aExpandLaneC forward/backward random
        // cross from: aExpandLaneB, aFireLaneC
        // cross directions: aExpandLaneB backward forced, aFireLaneC backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aFireLaneD[((aIndex + 14254U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneD[((aIndex + 16275U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 13982U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 15674U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneC[((aIndex + 15865U)) & S_BLOCK1], 46U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 37U) + RotL64(aCarry, 3U)) ^ (RotL64(aPrevious, 52U) ^ RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterC = ((aWandererE + RotL64(aIngress, 53U)) + 7722279280863371124U) + aOrbiterAssignSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = ((aWandererF + RotL64(aScatter, 4U)) + 11584220561732385598U) + aNonceWordA;
            aOrbiterF = (((aWandererK + RotL64(aCross, 57U)) + RotL64(aCarry, 37U)) + 7834679350105534657U) + aNonceWordE;
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 27U)) + 11347994382444180879U;
            aOrbiterD = ((aWandererC + RotL64(aCross, 41U)) + 9449903188047063431U) + aOrbiterAssignSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = ((aWandererA + RotL64(aScatter, 19U)) + RotL64(aCarry, 47U)) + 6516243976652795170U;
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 46U)) + 8420815253991184777U) + aNonceWordC;
            aOrbiterI = ((aWandererH + RotL64(aIngress, 37U)) + RotL64(aCarry, 5U)) + 9081386852515170937U;
            aOrbiterA = (aWandererG + RotL64(aPrevious, 13U)) + 14375955191735286867U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 880757589768436072U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 3349856625725164229U;
            aOrbiterF = RotL64((aOrbiterF * 681514212582331781U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 7826309957607577207U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 8057435761214313635U) ^ aOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4718430712767038607U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 9565237500443303103U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 15893066735310588501U;
            aOrbiterJ = RotL64((aOrbiterJ * 8457633439171452397U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 3276844534476430842U) + aNonceWordJ;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 6828644383891274120U;
            aOrbiterK = RotL64((aOrbiterK * 979580351653410157U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 2815676923011504251U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 5030251870850928417U;
            aOrbiterE = RotL64((aOrbiterE * 7075653570570819253U), 43U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterJ) + 13464083008377887034U) + aOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1]) + aNonceWordM;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 8994560761846897590U;
            aOrbiterA = RotL64((aOrbiterA * 9892839554658865143U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 8398813387154468736U) + aNonceWordL;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 8136429428340910892U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3348811490733577295U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 418587250696862341U) + aNonceWordG;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 4111667833838312094U) ^ aOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 860949442143849147U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 6075478294190926371U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 2208124955874142264U;
            aOrbiterI = RotL64((aOrbiterI * 15741988616251072075U), 57U);
            //
            aIngress = RotL64(aOrbiterK, 51U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterI, 24U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 5U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 39U));
            aIngress = aIngress + RotL64(aOrbiterE, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aScatter, 6U) + RotL64(aOrbiterI, 29U)) + aOrbiterE);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterG, 60U)) + aOrbiterC) + RotL64(aCarry, 57U)) + aWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterE, 13U)) + aOrbiterJ) + aNonceWordO);
            aWandererA = aWandererA + (((RotL64(aCross, 23U) + RotL64(aOrbiterD, 53U)) + aOrbiterC) + aWandererUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 43U) + aOrbiterI) + RotL64(aOrbiterA, 39U));
            aWandererE = aWandererE + ((((RotL64(aCross, 27U) + aOrbiterG) + RotL64(aOrbiterK, 5U)) + RotL64(aCarry, 43U)) + aNonceWordD);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 13U) + aOrbiterI) + RotL64(aOrbiterF, 43U));
            aWandererH = aWandererH + ((RotL64(aIngress, 36U) + aOrbiterA) + RotL64(aOrbiterF, 23U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterK, 18U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 60U));
            aCarry = aCarry + (RotL64(aWandererI, 39U) ^ aWandererK);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 53U));
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 47U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_b loop 4
        // ingress from: aOperationLaneA, aExpandLaneC, aFireLaneC
        // ingress directions: aOperationLaneA forward forced, aExpandLaneC forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneD, aFireLaneD
        // cross directions: aExpandLaneD backward forced, aFireLaneD backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 16600U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneC[((aIndex + 21103U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 21676U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17593U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneD[((aIndex + 21440U)) & S_BLOCK1], 36U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 57U)) ^ (RotL64(aCross, 24U) + RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterC = (((aWandererG + RotL64(aPrevious, 29U)) + RotL64(aCarry, 43U)) + 13481227414590594621U) + aNonceWordJ;
            aOrbiterF = (((aWandererK + RotL64(aScatter, 39U)) + RotL64(aCarry, 21U)) + 17425964381118918026U) + aOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = (aWandererA + RotL64(aIngress, 18U)) + 4792004356135956581U;
            aOrbiterA = ((aWandererB + RotL64(aCross, 13U)) + RotL64(aCarry, 53U)) + 11926849936000639098U;
            aOrbiterK = (aWandererJ + RotL64(aPrevious, 53U)) + 990697329347742142U;
            aOrbiterH = (aWandererE + RotL64(aScatter, 5U)) + 9307721505373076588U;
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 34U)) + 17605732738841908719U) + aOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = ((aWandererH + RotL64(aCross, 47U)) + 13110764518634187439U) + aNonceWordH;
            aOrbiterI = (aWandererC + RotL64(aIngress, 43U)) + 17970109897810645911U;
            //
            aOrbiterC = (((aOrbiterC + aOrbiterF) + 10273133817644703654U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordF;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 11239046688920468137U;
            aOrbiterG = RotL64((aOrbiterG * 5197802934333553327U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 8355821483275763145U) + aOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 15522151127786049345U;
            aOrbiterF = RotL64((aOrbiterF * 4844278537850520413U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 5381663179722418112U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 9551368011768104906U;
            aOrbiterK = RotL64((aOrbiterK * 14202470972121732997U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 16264476585232221270U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 7721417776432288282U) ^ aNonceWordI;
            aOrbiterC = RotL64((aOrbiterC * 10267770327791051869U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 339418090653475277U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 3247926250495935511U;
            aOrbiterH = RotL64((aOrbiterH * 16824669543765729097U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 3390560045236418590U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 3894024951542543635U;
            aOrbiterE = RotL64((aOrbiterE * 10599637790900418767U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 3878539166189668154U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 5617705593218220843U;
            aOrbiterJ = RotL64((aOrbiterJ * 82771190372750823U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 12320861089148474544U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 14943790251625519550U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13758322022902008313U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 18119213517612562775U) + aOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 1413193144229486646U;
            aOrbiterA = RotL64((aOrbiterA * 14562375280658115687U), 39U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterC, 19U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 22U));
            aIngress = aIngress + (RotL64(aOrbiterF, 37U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 51U));
            aIngress = aIngress + RotL64(aOrbiterK, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterA, 19U)) + aOrbiterH);
            aWandererF = aWandererF + (((RotL64(aCross, 34U) + aOrbiterE) + RotL64(aOrbiterH, 57U)) + aNonceWordN);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterH, 6U)) + aOrbiterC) + aWandererUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 29U) + aOrbiterG) + RotL64(aOrbiterC, 39U)) + RotL64(aCarry, 21U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterK, 29U)) + aOrbiterA) + aNonceWordL);
            aWandererG = aWandererG + (((RotL64(aScatter, 51U) + aOrbiterA) + RotL64(aOrbiterF, 51U)) + RotL64(aCarry, 41U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 5U) + aOrbiterK) + RotL64(aOrbiterE, 10U));
            aWandererK = aWandererK + ((RotL64(aCross, 11U) + RotL64(aOrbiterJ, 23U)) + aOrbiterH);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 60U) + RotL64(aOrbiterJ, 35U)) + aOrbiterI) + aWandererUpdateSaltB[((aIndex + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 60U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + RotL64(aWandererB, 29U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_b loop 5
        // ingress from: aOperationLaneB, aFireLaneD
        // ingress directions: aOperationLaneB forward forced, aFireLaneD forward/backward random
        // cross from: aOperationLaneA, aExpandLaneA
        // cross directions: aOperationLaneA backward forced, aExpandLaneA backward/forward random
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aOperationLaneB[((aIndex + 25318U)) & S_BLOCK1], 53U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 24331U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 22563U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23080U)) & S_BLOCK1], 28U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCarry, 11U) + RotL64(aPrevious, 40U)) ^ (RotL64(aCross, 27U) + RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterI = (((aWandererE + RotL64(aScatter, 18U)) + RotL64(aCarry, 13U)) + 9107326720193244489U) + aNonceWordB;
            aOrbiterH = ((aWandererF + RotL64(aIngress, 51U)) + RotL64(aCarry, 35U)) + 10868585484401664145U;
            aOrbiterB = (aWandererI + RotL64(aCross, 57U)) + 13637736741437846622U;
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 39U)) + 6130725216183918844U) + aOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = ((aWandererD + RotL64(aIngress, 23U)) + 2063834478521338187U) + aNonceWordJ;
            aOrbiterF = (aWandererH + RotL64(aScatter, 47U)) + 8564870627911949158U;
            aOrbiterK = ((aWandererJ + RotL64(aCross, 34U)) + RotL64(aCarry, 3U)) + 6524015751064086390U;
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 11U)) + 9874937766875388236U) + aOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = (aWandererB + RotL64(aScatter, 3U)) + 14723718409522680894U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 13767059954741528279U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 6387608251033722169U;
            aOrbiterB = RotL64((aOrbiterB * 6601902195707980693U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 5391425980008431000U) + aOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 11524218415655093779U) ^ aOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12508457981779189389U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 155510463350385905U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 10554591788433641311U;
            aOrbiterC = RotL64((aOrbiterC * 5412084824127934293U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 8662160162966241542U) + aNonceWordI;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 5092555636369853727U) ^ aNonceWordP;
            aOrbiterA = RotL64((aOrbiterA * 433807340167635499U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 7163345798448796101U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 695089002178413267U) ^ aOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17302689458565434475U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 5409173939213468972U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 15349690077393827541U;
            aOrbiterF = RotL64((aOrbiterF * 10984681254001609841U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 12376011890751302027U) + aNonceWordF;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 7809614158898158383U;
            aOrbiterJ = RotL64((aOrbiterJ * 13845113198736843629U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 13031938699536449576U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 3983178190194056516U;
            aOrbiterI = RotL64((aOrbiterI * 1341678482929213405U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 5567935037909671790U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 17137042627663349797U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13535586899620672373U), 47U);
            //
            aIngress = RotL64(aOrbiterA, 20U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 53U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 23U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 47U));
            aIngress = aIngress + RotL64(aOrbiterB, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterH, 36U));
            aWandererC = aWandererC + ((((RotL64(aCross, 37U) + RotL64(aOrbiterH, 47U)) + aOrbiterF) + RotL64(aCarry, 35U)) + aWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 28U) + RotL64(aOrbiterA, 19U)) + aOrbiterH) + aNonceWordD);
            aWandererI = aWandererI + ((((RotL64(aScatter, 19U) + aOrbiterI) + RotL64(aOrbiterK, 3U)) + RotL64(aCarry, 43U)) + aWandererUpdateSaltC[((aIndex + 10U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 51U) + aOrbiterA) + RotL64(aOrbiterJ, 58U));
            aWandererE = aWandererE + ((RotL64(aScatter, 3U) + aOrbiterB) + RotL64(aOrbiterJ, 41U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 23U) + aOrbiterD) + RotL64(aOrbiterK, 13U)) + aNonceWordH);
            aWandererH = aWandererH + ((RotL64(aCross, 42U) + RotL64(aOrbiterJ, 29U)) + aOrbiterH);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterK, 53U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererI);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 14U));
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererB);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + RotL64(aWandererJ, 39U);
            aCarry = aCarry + RotL64(aIngress, 6U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_b loop 6
        // ingress from: aOperationLaneC, aOperationLaneA
        // ingress directions: aOperationLaneC forward forced, aOperationLaneA forward/backward random
        // cross from: aOperationLaneB, aExpandLaneB
        // cross directions: aOperationLaneB backward forced, aExpandLaneB backward/forward random
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aOperationLaneC[((aIndex + 32028U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 29884U)) & S_BLOCK1], 30U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27827U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31351U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCarry, 35U) ^ RotL64(aIngress, 56U)) + (RotL64(aPrevious, 23U) ^ RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterK = (aWandererD + RotL64(aCross, 39U)) + 6342299552323486695U;
            aOrbiterA = ((aWandererG + RotL64(aIngress, 18U)) + 12692748514781367538U) + aNonceWordJ;
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 27U)) + 8202639945493229155U) + aNonceWordO;
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 51U)) + RotL64(aCarry, 23U)) + 4439975701793231639U;
            aOrbiterF = (((aWandererH + RotL64(aPrevious, 35U)) + RotL64(aCarry, 5U)) + 16774235182859553759U) + aOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = (aWandererB + RotL64(aScatter, 47U)) + 8764155413335405667U;
            aOrbiterG = ((aWandererE + RotL64(aIngress, 10U)) + 7167848811974967685U) + aNonceWordH;
            aOrbiterE = (((aWandererK + RotL64(aCross, 23U)) + RotL64(aCarry, 41U)) + 16768278912125334220U) + aOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = (aWandererA + RotL64(aScatter, 5U)) + 9090838954826296201U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 7644075729758006298U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 17326182797908071215U;
            aOrbiterC = RotL64((aOrbiterC * 2408330168749256075U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 16158809721888137555U) + aNonceWordM;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 8029938783858263694U;
            aOrbiterK = RotL64((aOrbiterK * 12628072435324195483U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 8716553521415553404U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 7012599977009208840U;
            aOrbiterE = RotL64((aOrbiterE * 8775355876188948851U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 13250558696578541499U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 13705957059101025396U;
            aOrbiterA = RotL64((aOrbiterA * 16889495686487056367U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 2796775206291902461U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterB) ^ 13741676263512390669U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterG = RotL64((aOrbiterG * 10455782033465595947U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 1691908360612389252U) + aOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 4114939415206031540U) ^ aOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2797401802892718297U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 2374911514440738727U) + aNonceWordN;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 12377616933668803091U;
            aOrbiterB = RotL64((aOrbiterB * 2505164835116651215U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 681094033415259645U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 13841322124900463362U;
            aOrbiterI = RotL64((aOrbiterI * 4210414203856902329U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 18082983557580381338U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 15731122225678626778U;
            aOrbiterF = RotL64((aOrbiterF * 7785999919955613789U), 19U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterF, 57U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + (RotL64(aOrbiterC, 18U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterB, 43U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterK, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((((RotL64(aIngress, 39U) + RotL64(aOrbiterA, 19U)) + aOrbiterF) + aNonceWordC) + aWandererUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 24U) + aOrbiterF) + RotL64(aOrbiterK, 58U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 13U) + aOrbiterJ) + RotL64(aOrbiterG, 23U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 47U) + aOrbiterG) + RotL64(aOrbiterF, 13U));
            aWandererD = aWandererD ^ ((((RotL64(aPrevious, 5U) + aOrbiterF) + RotL64(aOrbiterC, 51U)) + aNonceWordL) + aWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 28U) + aOrbiterK) + RotL64(aOrbiterC, 39U)) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterB, 6U)) + aOrbiterJ) + aNonceWordB);
            aWandererA = aWandererA + (((RotL64(aCross, 19U) + aOrbiterB) + RotL64(aOrbiterE, 27U)) + RotL64(aCarry, 51U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 43U) + aOrbiterI) + RotL64(aOrbiterE, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 27U) ^ aWandererA);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 41U));
            aCarry = aCarry + (RotL64(aWandererG, 58U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 5U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererJ, 23U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x97D0E9BD8B9D60F5ULL + 0xC8B03C533A2F9EC8ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xEAD92830EAA721A3ULL + 0xEF9366DD507404E8ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xB91F45660447D111ULL + 0xCEB158EB0E00DD1DULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x80B0060BADB4C51BULL + 0xC2845BC00744AD8FULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xD3A2EBDB1865320BULL + 0xFDF1F5F2C3ED7F9CULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xCF6DC4E92AE3D55DULL + 0xBA278D6A4FF45C01ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xD1FF2FCBD98107C5ULL + 0xF29C3BB8E5E08841ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xD3AF971CE022B6DBULL + 0xB9C9C7147FD7EF42ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xB92CF1EBE57DBBBDULL + 0xF3739B415AA4EBDCULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xF9F67DB187BB091BULL + 0xB051A3B3ECCC06BAULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xBE6221D07328E5EFULL + 0xE6B9E4EAC80CAB00ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xAFDB1690CFF78535ULL + 0xF0E160CA5816F57FULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xD00CF8AAD5A12D2BULL + 0x81596C73501429DEULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x8520B68A4713364BULL + 0xCCDE15E7627FF64AULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xECEB681CD9654D4FULL + 0xFED640F80D70BFF2ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xAB4BF2C1EE3EA993ULL + 0xE5A34E8F7FD12C36ULL);
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
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneA, aOperationLaneC, aOperationLaneD, aFireLaneB, aWorkLaneA, aFireLaneC, aFireLaneD, aWorkLaneB, aExpandLaneA, aExpandLaneB, aWorkLaneC, aExpandLaneC, aExpandLaneD
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // kdf_a_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aFireLaneA
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aFireLaneB
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aFireLaneB backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 7599U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneB[((aIndex + 4384U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 5150U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 3308U)) & S_BLOCK1], 48U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 7371U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 6126U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCross, 11U) ^ RotL64(aIngress, 23U)) + (RotL64(aPrevious, 60U) + RotL64(aCarry, 43U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterH = ((((aWandererH + RotL64(aIngress, 37U)) + RotL64(aCarry, 43U)) + 5041131702736607991U) + aOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1]) + aNonceWordG;
            aOrbiterA = (((aWandererA + RotL64(aCross, 24U)) + RotL64(aCarry, 11U)) + 9295010428212681446U) + aNonceWordA;
            aOrbiterD = (((aWandererE + RotL64(aScatter, 3U)) + RotL64(aCarry, 23U)) + 6235875895358766017U) + aOrbiterAssignSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 11U)) + 2622227802531866918U) + aNonceWordD;
            aOrbiterG = ((aWandererG + RotL64(aCross, 53U)) + 3888894734834524972U) + aNonceWordJ;
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 241682012014701753U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 15758000422451568079U;
            aOrbiterD = RotL64((aOrbiterD * 14719166949665416221U), 5U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterH) + 2061944548396976912U) + aOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1]) + aNonceWordN;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 8177144990755754531U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12702392689484397947U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 554978075608818497U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 250408260560714933U;
            aOrbiterJ = RotL64((aOrbiterJ * 1295379390497107727U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 8700027645880997552U) + aOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 10026130047465480902U) ^ aNonceWordI;
            aOrbiterH = RotL64((aOrbiterH * 12417270861933696623U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 9785843014096326696U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 9998582683258411251U) ^ aOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7197956237569462269U), 13U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterA, 57U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 21U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterH, 46U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aCross, 35U) + aOrbiterG) + RotL64(aOrbiterH, 60U)) + RotL64(aCarry, 13U)) + aWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 54U) + aOrbiterG) + RotL64(aOrbiterA, 35U));
            aWandererH = aWandererH + ((RotL64(aIngress, 43U) + aOrbiterJ) + RotL64(aOrbiterA, 27U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 11U) + aOrbiterD) + RotL64(aOrbiterH, 43U)) + aNonceWordF);
            aWandererE = aWandererE + (((((RotL64(aPrevious, 27U) + RotL64(aOrbiterG, 13U)) + aOrbiterJ) + RotL64(aCarry, 37U)) + aNonceWordC) + aWandererUpdateSaltB[((aIndex + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 37U));
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererH, 60U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_c loop 2
        // ingress from: aWorkLaneA, aOperationLaneC, aOperationLaneD, aFireLaneC
        // ingress directions: aWorkLaneA forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aFireLaneD
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aFireLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 10115U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneC[((aIndex + 12606U)) & S_BLOCK1], 27U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 12887U)) & S_BLOCK1], 46U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 14170U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 8550U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 9808U)) & S_BLOCK1], 40U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 15991U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 52U) + RotL64(aCarry, 23U)) ^ (RotL64(aCross, 3U) ^ RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterD = (((aWandererJ + RotL64(aCross, 11U)) + RotL64(aCarry, 35U)) + 14823268998003220191U) + aNonceWordL;
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 29U)) + RotL64(aCarry, 53U)) + 15295237288788213847U;
            aOrbiterI = (((aWandererC + RotL64(aScatter, 19U)) + 16434853402001133899U) + aOrbiterAssignSaltE[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordA;
            aOrbiterA = ((((aWandererI + RotL64(aIngress, 39U)) + RotL64(aCarry, 3U)) + 7555911304407871631U) + aOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1]) + aNonceWordI;
            aOrbiterJ = ((aWandererG + RotL64(aCross, 56U)) + 14977248264994834620U) + aNonceWordF;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 9707764144919392380U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 1277304385464681529U;
            aOrbiterI = RotL64((aOrbiterI * 2864691650462053463U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 3089786220465849395U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 3700503853358695085U;
            aOrbiterD = RotL64((aOrbiterD * 2079089949442685421U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 3240054112993517371U) + aNonceWordK;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 16897532076915366859U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4120874717534309035U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 18167359289798364307U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterK) ^ 8870819278575769863U) ^ aOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterJ = RotL64((aOrbiterJ * 9334066154398059075U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 15363069206212330251U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 14858164441499725158U) ^ aOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14931933411393847915U), 39U);
            //
            aIngress = RotL64(aOrbiterJ, 26U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 51U));
            aIngress = aIngress + RotL64(aOrbiterK, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterD, 48U)) + aOrbiterK) + aNonceWordB) + aWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererG = aWandererG + (((((RotL64(aIngress, 19U) + aOrbiterK) + RotL64(aOrbiterI, 13U)) + RotL64(aCarry, 13U)) + aNonceWordM) + aWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 4U) + RotL64(aOrbiterA, 27U)) + aOrbiterK) + aNonceWordN);
            aWandererC = aWandererC + ((((RotL64(aScatter, 51U) + aOrbiterJ) + RotL64(aOrbiterI, 3U)) + RotL64(aCarry, 51U)) + aNonceWordP);
            aWandererI = aWandererI ^ ((RotL64(aCross, 35U) + aOrbiterK) + RotL64(aOrbiterJ, 35U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 48U));
            aCarry = aCarry + RotL64(aWandererI, 5U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_c loop 3
        // ingress from: aWorkLaneB, aOperationLaneA, aOperationLaneB, aExpandLaneA
        // ingress directions: aWorkLaneB forward forced, aOperationLaneA forward forced, aOperationLaneB forward forced, aExpandLaneA forward/backward random
        // cross from: aWorkLaneA, aOperationLaneC, aExpandLaneB
        // cross directions: aWorkLaneA backward forced, aOperationLaneC backward forced, aExpandLaneB backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 22910U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneA[((aIndex + 17296U)) & S_BLOCK1], 47U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 19781U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((aIndex + 20112U)) & S_BLOCK1], 26U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22499U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 21317U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aExpandLaneB[((aIndex + 17636U)) & S_BLOCK1], 28U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCarry, 35U)) + (RotL64(aCross, 10U) ^ RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterF = (((aWandererE + RotL64(aCross, 56U)) + RotL64(aCarry, 23U)) + 13333509828310369865U) + aNonceWordN;
            aOrbiterC = ((aWandererI + RotL64(aIngress, 43U)) + 7645352517103840797U) + aOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = (((aWandererK + RotL64(aScatter, 23U)) + 5310766306660062655U) + aOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1]) + aNonceWordH;
            aOrbiterK = (((aWandererA + RotL64(aPrevious, 5U)) + RotL64(aCarry, 3U)) + 5165635069832352932U) + aNonceWordO;
            aOrbiterA = (((aWandererJ + RotL64(aScatter, 35U)) + RotL64(aCarry, 47U)) + 15684141764734281849U) + aNonceWordE;
            //
            aOrbiterF = (((aOrbiterF + aOrbiterC) + 3327963374225061738U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordD;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 8625811794878848871U) ^ aNonceWordA;
            aOrbiterH = RotL64((aOrbiterH * 16327750494894125333U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 7598657468430485291U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 2881171216276746485U) ^ aOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3331350584102843605U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 10237691227222918101U) + aOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 6419254255884834497U;
            aOrbiterF = RotL64((aOrbiterF * 3816625473642865305U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 4238455444646479956U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 14936613353493061492U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3544216916806292273U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 15324699725208372627U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 9506640480601832011U;
            aOrbiterK = RotL64((aOrbiterK * 12819564111348390227U), 29U);
            //
            aIngress = RotL64(aOrbiterK, 5U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + RotL64(aOrbiterC, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aIngress, 29U) + RotL64(aOrbiterA, 52U)) + aOrbiterK) + RotL64(aCarry, 37U)) + aWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterH, 11U)) + aOrbiterC);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 3U) + aOrbiterC) + RotL64(aOrbiterA, 3U)) + aNonceWordI);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterC, 35U)) + aOrbiterF) + aNonceWordB);
            aWandererE = aWandererE + ((((RotL64(aCross, 54U) + aOrbiterF) + RotL64(aOrbiterA, 27U)) + RotL64(aCarry, 19U)) + aWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 30U) ^ aWandererK);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + RotL64(aWandererE, 21U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_c loop 4
        // ingress from: aWorkLaneC, aWorkLaneA, aOperationLaneD, aExpandLaneC
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aOperationLaneD forward forced, aExpandLaneC forward/backward random
        // cross from: aWorkLaneB, aOperationLaneB, aExpandLaneD
        // cross directions: aWorkLaneB backward forced, aOperationLaneB backward forced, aExpandLaneD backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 29486U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((aIndex + 30530U)) & S_BLOCK1], 14U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 25216U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneC[((aIndex + 24781U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28622U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30107U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aExpandLaneD[((aIndex + 28438U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCarry, 56U) ^ RotL64(aIngress, 23U)) + (RotL64(aCross, 5U) ^ RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterF = (((aWandererK + RotL64(aIngress, 38U)) + RotL64(aCarry, 11U)) + 12262991801139086177U) + aNonceWordL;
            aOrbiterK = ((aWandererA + RotL64(aScatter, 27U)) + 7963038771924890197U) + aNonceWordE;
            aOrbiterE = (((aWandererH + RotL64(aPrevious, 3U)) + 15540520327933568896U) + aOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1]) + aNonceWordG;
            aOrbiterI = (((aWandererI + RotL64(aCross, 57U)) + RotL64(aCarry, 27U)) + 8745565892055020722U) + aOrbiterAssignSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterD = (((aWandererF + RotL64(aPrevious, 13U)) + RotL64(aCarry, 53U)) + 16619329199683755286U) + aNonceWordO;
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 10865705026433867260U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 2743368697984518059U;
            aOrbiterE = RotL64((aOrbiterE * 2989232417816919375U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 5556006271515473135U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 5355833281353498588U;
            aOrbiterF = RotL64((aOrbiterF * 4190140212757841511U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 8313616108963479829U) + aNonceWordJ;
            aOrbiterI = (((aOrbiterI ^ aOrbiterK) ^ 16657121016801866434U) ^ aOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterI = RotL64((aOrbiterI * 331533349428472477U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 16532226425013000833U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 5800465874932467232U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5966395771690704577U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 17882948163883121328U) + aNonceWordP;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 15029375310296563175U) ^ aNonceWordH;
            aOrbiterD = RotL64((aOrbiterD * 17021415832288477713U), 5U);
            //
            aIngress = RotL64(aOrbiterD, 27U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + RotL64(aOrbiterK, 38U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterE, 39U)) + aOrbiterI) + aNonceWordC);
            aWandererK = aWandererK + (((((RotL64(aPrevious, 5U) + aOrbiterE) + RotL64(aOrbiterK, 57U)) + RotL64(aCarry, 23U)) + aNonceWordB) + aWandererUpdateSaltB[((aIndex + 10U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterF, 47U)) + aOrbiterD) + aNonceWordM);
            aWandererF = aWandererF + ((((RotL64(aCross, 60U) + aOrbiterK) + RotL64(aOrbiterF, 4U)) + RotL64(aCarry, 37U)) + aWandererUpdateSaltE[((aIndex + 12U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 13U) + aOrbiterE) + RotL64(aOrbiterD, 13U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + (RotL64(aWandererA, 13U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererF, 21U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x930619E097806D6DULL + 0xBE8DDAE538E5D60FULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xB212442930BB096FULL + 0xFDC51A76A0E001A6ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xA3DE87963749D669ULL + 0xF66AB3A418EEAB24ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xEE13DA50130CCCFFULL + 0xDC995EB79610428FULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x92379BC0B0575169ULL + 0xCDE1E949CA864A72ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xB8C1768D6D3D383BULL + 0xC302F4DE1918B63BULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xADDC1AEA4889A999ULL + 0xF3522A77785B3DB3ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x82E3949C21DF04B7ULL + 0x950E2FAA7AECE099ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x8AEB6D74C6E9C56BULL + 0xD7948D2F1540DE2BULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xE0523920A96C8D49ULL + 0x98006C54CB5D8731ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x93A55B9AC8716DBFULL + 0xF992B2F2155C885DULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x9A9496AB2340F9A5ULL + 0xA89A4F7D12619B7BULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xAFE667A4F30D8E6FULL + 0x996F9142188C02B1ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xDC34A524A8B63B41ULL + 0xBEC5E31A98ED29A0ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xF0A0DC3AB3C113E5ULL + 0xE72C7CB57CCADA80ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xAC6E5281FE470131ULL + 0xAF80CE60F0EAE643ULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneA, aExpandLaneC, aExpandLaneD, aFireLaneB, aWorkLaneA, aFireLaneC, aFireLaneD, aWorkLaneB, aOperationLaneA, aOperationLaneB, aWorkLaneC, aOperationLaneC, aOperationLaneD
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // kdf_a_loop_d loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneA
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aFireLaneB
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aFireLaneB backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 3636U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((aIndex + 7299U)) & S_BLOCK1], 38U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 2060U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 6983U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 1637U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 6763U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 47U) ^ RotL64(aIngress, 4U)) + (RotL64(aPrevious, 19U) + RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 35U)) + 13278949403988203974U) + aNonceWordD;
            aOrbiterI = ((aWandererG + RotL64(aPrevious, 29U)) + RotL64(aCarry, 11U)) + 9213599924054673756U;
            aOrbiterC = (aWandererB + RotL64(aCross, 22U)) + 1255746482932381798U;
            aOrbiterF = (aWandererF + RotL64(aIngress, 53U)) + 11575321997144516122U;
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 11U)) + 15881587525529432437U) + aNonceWordE;
            aOrbiterG = (((aWandererK + RotL64(aScatter, 41U)) + RotL64(aCarry, 43U)) + 9846195809864862707U) + aOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = (((aWandererH + RotL64(aCross, 47U)) + RotL64(aCarry, 57U)) + 12319815691858217670U) + aOrbiterAssignSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 16322617427294439587U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 16332130810525887437U;
            aOrbiterC = RotL64((aOrbiterC * 7588076439690559343U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 4920951156015336794U) + aOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 16767126455124552329U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4440352337076842603U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 12553595911087945223U) + aOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 1437522202135436142U;
            aOrbiterG = RotL64((aOrbiterG * 2001992794165550905U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 12313100454852227143U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 2761983020631055729U) ^ aNonceWordA;
            aOrbiterF = RotL64((aOrbiterF * 3874839760378039509U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 17635303588421554367U) + aNonceWordN;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 788212489507463763U;
            aOrbiterB = RotL64((aOrbiterB * 17896475584538528059U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 5192552894670654434U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 6784748488807738811U;
            aOrbiterI = RotL64((aOrbiterI * 8077237651953896479U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 16113417046719114943U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 1096874945215225916U) ^ aOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17308604412622879833U), 43U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterJ, 27U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 21U));
            aIngress = aIngress + (RotL64(aOrbiterF, 39U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterC, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aIngress, 21U) + aOrbiterB) + RotL64(aOrbiterC, 57U)) + aWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aScatter, 11U) + aOrbiterI) + RotL64(aOrbiterJ, 29U)) + RotL64(aCarry, 57U)) + aNonceWordB);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterE, 3U)) + aOrbiterF) + aNonceWordG);
            aWandererJ = aWandererJ + (((RotL64(aCross, 57U) + aOrbiterC) + RotL64(aOrbiterF, 22U)) + RotL64(aCarry, 23U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterC, 13U)) + aOrbiterG);
            aWandererG = aWandererG + (((RotL64(aIngress, 37U) + aOrbiterJ) + RotL64(aOrbiterC, 47U)) + aNonceWordF);
            aWandererK = aWandererK ^ (((RotL64(aCross, 50U) + aOrbiterC) + RotL64(aOrbiterE, 37U)) + aWandererUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 58U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + RotL64(aWandererG, 29U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 2
        // ingress from: aWorkLaneA, aExpandLaneC, aExpandLaneD, aFireLaneC
        // ingress directions: aWorkLaneA forward forced, aExpandLaneC forward forced, aExpandLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneA, aExpandLaneB, aFireLaneD
        // cross directions: aExpandLaneA backward forced, aExpandLaneB backward forced, aFireLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 8972U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneC[((aIndex + 14005U)) & S_BLOCK1], 23U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 8976U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneC[((aIndex + 14459U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 12745U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 9501U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 12255U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aIngress, 18U) ^ RotL64(aCarry, 5U)) ^ (RotL64(aCross, 47U) + RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterG = (((aWandererA + RotL64(aPrevious, 11U)) + RotL64(aCarry, 51U)) + 12615321415808640429U) + aOrbiterAssignSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = (((aWandererC + RotL64(aCross, 57U)) + RotL64(aCarry, 29U)) + 15712784676459931207U) + aNonceWordB;
            aOrbiterK = (aWandererF + RotL64(aScatter, 41U)) + 11013335427004930046U;
            aOrbiterI = ((aWandererI + RotL64(aIngress, 21U)) + 8298733856304768806U) + aNonceWordE;
            aOrbiterJ = (aWandererD + RotL64(aPrevious, 35U)) + 6207732959150824216U;
            aOrbiterA = ((aWandererB + RotL64(aScatter, 5U)) + 9769864876127544038U) + aOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = ((aWandererG + RotL64(aIngress, 48U)) + RotL64(aCarry, 13U)) + 10782181918651152563U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 5790454015845620939U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 15606578025386733803U;
            aOrbiterK = RotL64((aOrbiterK * 7079287329365566355U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 5522352539991175304U) + aOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 5993355818572869649U) ^ aNonceWordG;
            aOrbiterJ = RotL64((aOrbiterJ * 15221467311057431139U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 10864534396947622047U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 12090053126235913528U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7250801471645972261U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 14191181677234981396U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 2258570108233924592U) ^ aNonceWordJ;
            aOrbiterG = RotL64((aOrbiterG * 8307541155393855209U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 8448114811381534603U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 2702389315763499817U;
            aOrbiterA = RotL64((aOrbiterA * 6710443836432274393U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 17202184076718780200U) + aNonceWordN;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 150549910056015002U) ^ aOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 195034681254956335U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 4910512055808124967U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 4783477997418403079U) ^ aOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 861977492146512865U), 51U);
            //
            aIngress = RotL64(aOrbiterI, 51U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterK, 13U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterJ, 37U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterH, 60U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aIngress, 37U) + RotL64(aOrbiterB, 41U)) + aOrbiterA) + RotL64(aCarry, 53U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 51U) + aOrbiterH) + RotL64(aOrbiterI, 47U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterH, 12U)) + aOrbiterJ) + RotL64(aCarry, 35U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 27U) + aOrbiterG) + RotL64(aOrbiterJ, 29U));
            aWandererA = aWandererA + (((RotL64(aIngress, 12U) + RotL64(aOrbiterG, 3U)) + aOrbiterI) + aWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterB, 21U)) + aOrbiterG) + aNonceWordL) + aWandererUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 5U) + aOrbiterK) + RotL64(aOrbiterJ, 53U)) + aNonceWordC);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 5U));
            aCarry = aCarry + (RotL64(aWandererB, 34U) ^ aWandererI);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + RotL64(aWandererG, 27U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 3
        // ingress from: aWorkLaneB, aExpandLaneA, aExpandLaneB, aOperationLaneA
        // ingress directions: aWorkLaneB forward forced, aExpandLaneA forward forced, aExpandLaneB forward forced, aOperationLaneA forward/backward random
        // cross from: aWorkLaneA, aExpandLaneC, aOperationLaneB
        // cross directions: aWorkLaneA backward forced, aExpandLaneC backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 19263U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneA[((aIndex + 21140U)) & S_BLOCK1], 35U));
            aIngress ^= (RotL64(aExpandLaneB[((aIndex + 20775U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 17248U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22485U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 21191U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 19240U)) & S_BLOCK1], 26U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 18U) ^ RotL64(aCarry, 35U)) + (RotL64(aPrevious, 57U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterJ = (((aWandererK + RotL64(aScatter, 19U)) + RotL64(aCarry, 23U)) + 3612110001869385068U) + aOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = (aWandererG + RotL64(aPrevious, 3U)) + 16340824141280225936U;
            aOrbiterA = ((aWandererD + RotL64(aCross, 54U)) + RotL64(aCarry, 37U)) + 15222338965130765231U;
            aOrbiterH = (((aWandererF + RotL64(aIngress, 47U)) + RotL64(aCarry, 5U)) + 6649270508107155041U) + aOrbiterAssignSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = ((aWandererJ + RotL64(aCross, 29U)) + 768217258655426384U) + aNonceWordB;
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 41U)) + 4481855259658861851U) + aNonceWordG;
            aOrbiterE = ((aWandererE + RotL64(aIngress, 13U)) + 18318041934562434016U) + aNonceWordI;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 4212457153804401807U) + aOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 16143621095636987628U;
            aOrbiterA = RotL64((aOrbiterA * 6576072860505961427U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 2095664232866642086U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 4339527736737366572U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17503569508822244125U), 29U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterI) + 13679353177869884790U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordH;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 11582168502846418236U;
            aOrbiterE = RotL64((aOrbiterE * 135539430034462861U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 10451330452898542191U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 12951448817640617841U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4141870904192742091U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 15389161934419370747U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 4754886272708253014U) ^ aNonceWordF;
            aOrbiterD = RotL64((aOrbiterD * 16638243718191281597U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 11746389873929280688U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 12042680172517298768U;
            aOrbiterH = RotL64((aOrbiterH * 3814780289755857543U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 2648103752465009244U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 451594673632597973U;
            aOrbiterJ = RotL64((aOrbiterJ * 8496763663271072425U), 19U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterD, 21U);
            aIngress = aIngress + (RotL64(aOrbiterH, 41U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterE, 47U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterJ, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterH, 19U)) + aOrbiterA) + aNonceWordM);
            aWandererG = aWandererG + (((((RotL64(aCross, 5U) + RotL64(aOrbiterD, 35U)) + aOrbiterH) + RotL64(aCarry, 41U)) + aNonceWordO) + aWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 23U) + aOrbiterE) + RotL64(aOrbiterJ, 29U));
            aWandererI = aWandererI + ((((RotL64(aScatter, 47U) + RotL64(aOrbiterI, 41U)) + aOrbiterK) + RotL64(aCarry, 27U)) + aWandererUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterE, 57U)) + aOrbiterH);
            aWandererF = aWandererF + ((RotL64(aCross, 14U) + RotL64(aOrbiterI, 47U)) + aOrbiterE);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 57U) + aOrbiterK) + RotL64(aOrbiterA, 10U)) + aNonceWordL);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererK);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 51U));
            aCarry = aCarry + (RotL64(aWandererF, 58U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererG, 5U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 4
        // ingress from: aWorkLaneC, aWorkLaneA, aExpandLaneD, aOperationLaneC
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aExpandLaneD forward forced, aOperationLaneC forward/backward random
        // cross from: aWorkLaneB, aExpandLaneB, aOperationLaneD
        // cross directions: aWorkLaneB backward forced, aExpandLaneB backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 29082U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((aIndex + 26535U)) & S_BLOCK1], 41U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 24833U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 28407U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32171U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30246U)) & S_BLOCK1], 4U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 29866U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCarry, 11U) + RotL64(aPrevious, 23U)) ^ (RotL64(aCross, 56U) + RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterA = (aWandererK + RotL64(aPrevious, 11U)) + 6467297102954816305U;
            aOrbiterG = ((aWandererF + RotL64(aCross, 3U)) + RotL64(aCarry, 5U)) + 7921154109831114952U;
            aOrbiterF = ((aWandererD + RotL64(aScatter, 39U)) + 5701131763215638919U) + aNonceWordI;
            aOrbiterJ = (((aWandererE + RotL64(aIngress, 46U)) + RotL64(aCarry, 29U)) + 10022999076719002684U) + aOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = (((aWandererC + RotL64(aScatter, 53U)) + 4367135243038982316U) + aOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1]) + aNonceWordP;
            aOrbiterB = (aWandererI + RotL64(aIngress, 21U)) + 14445846824810383592U;
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 27U)) + RotL64(aCarry, 51U)) + 7683697954545773253U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 17517006750428030899U) + aNonceWordM;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 2052484792684025476U;
            aOrbiterF = RotL64((aOrbiterF * 12463117571122469643U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 6279463052085808926U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 679280153651813684U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3047031560593583881U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 2939516520188460569U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 1960616434964712325U;
            aOrbiterG = RotL64((aOrbiterG * 15145998415466343039U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 12273819390719947361U) + aOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 5685033154709449397U;
            aOrbiterA = RotL64((aOrbiterA * 9845666295874714959U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 9314494172199500653U) + aNonceWordF;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 15757631834636427621U;
            aOrbiterD = RotL64((aOrbiterD * 15483543888965744529U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 10878078046389399574U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 3583495913766365232U;
            aOrbiterH = RotL64((aOrbiterH * 2913540984990155225U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 7385544065754622301U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 16839599460207922881U) ^ aOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 240651605910592561U), 47U);
            //
            aIngress = RotL64(aOrbiterJ, 3U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterB, 53U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterA, 22U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterD, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 51U) + aOrbiterJ) + RotL64(aOrbiterF, 35U)) + aNonceWordC);
            aWandererF = aWandererF + (((RotL64(aCross, 29U) + aOrbiterJ) + RotL64(aOrbiterD, 57U)) + aWandererUpdateSaltF[((aIndex + 24U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 11U) + aOrbiterG) + RotL64(aOrbiterA, 11U)) + aNonceWordB);
            aWandererE = aWandererE + ((((RotL64(aIngress, 21U) + RotL64(aOrbiterH, 5U)) + aOrbiterB) + RotL64(aCarry, 35U)) + aNonceWordD);
            aWandererK = aWandererK ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterJ, 29U)) + aOrbiterG);
            aWandererI = aWandererI + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterH, 19U)) + aOrbiterA) + RotL64(aCarry, 19U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 60U) + aOrbiterA) + RotL64(aOrbiterB, 48U)) + aWandererUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 22U) ^ aWandererK);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererA, 3U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
    [[maybe_unused]] std::uint8_t *aOperationLaneA = pWorkSpace->mOperationLaneA;
    [[maybe_unused]] std::uint8_t *aOperationLaneB = pWorkSpace->mOperationLaneB;
    [[maybe_unused]] std::uint8_t *aOperationLaneC = pWorkSpace->mOperationLaneC;
    [[maybe_unused]] std::uint8_t *aOperationLaneD = pWorkSpace->mOperationLaneD;
    [[maybe_unused]] std::uint8_t *aFireLaneA = pWorkSpace->mFireLaneA;
    [[maybe_unused]] std::uint8_t *aFireLaneB = pWorkSpace->mFireLaneB;
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x90A563C580AFB33FULL + 0xC18ECD1369BAE64DULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xE29BEBB7BEE39AF1ULL + 0xC448B24573BCDCE0ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xAA644A28CF208057ULL + 0x98E1E2DD58CF0D5FULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xA98CECCA45B1ADA1ULL + 0xD4C49A7B45E66689ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xF3A53F0223E2BA0BULL + 0xD5AB058E7FD3B34EULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xB1E3429EB8315A0BULL + 0xD8CD62D52B098FB5ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xEBC1466A218E619DULL + 0xF5838D8E2FFD5C9FULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x8EFC9DDC7D7CA2F5ULL + 0xF177C121A5EBC6D7ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xEA37FA8E4078D5B7ULL + 0xDDCEC933DE3E8FDAULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xE9D5B88A6C1DA9FBULL + 0x8110C702F9262D69ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xAD3D9B5CD8E4A513ULL + 0x983B890BFF615090ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xF5A7527AD27F6E13ULL + 0xD9F90512237D6553ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xD6FD851A664CCFBDULL + 0xCF0A6BC732B24B9DULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xEFDA55B6A6A93CD7ULL + 0xA8133997DBE1569DULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xD4CDB8B8C513A42DULL + 0x9417BBB448E722BAULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xE433AE1FF0C0A563ULL + 0xA4C2E338085E6D80ULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aOperationLaneA, aWorkLaneC, aWorkLaneD, aFireLaneA, aOperationLaneB, aFireLaneB, aOperationLaneC, aExpandLaneA, aOperationLaneD, aExpandLaneB, aExpandLaneC
        // write to: aFireLaneA, aFireLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_a loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aOperationLaneA
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aOperationLaneA forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward/forward random
        // write to: aFireLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 4688U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((aIndex + 1141U)) & S_BLOCK1], 20U));
            aIngress ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 1786U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 4536U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneD[((aIndex + 2088U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCarry, 51U)) + (RotL64(aCross, 35U) ^ RotL64(aIngress, 10U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterC = ((aWandererB + RotL64(aScatter, 27U)) + 8604208734152026945U) + aOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = (aWandererE + RotL64(aPrevious, 51U)) + 1374329953253889829U;
            aOrbiterK = (((aWandererC + RotL64(aCross, 57U)) + RotL64(aCarry, 21U)) + 5779278910548228339U) + aNonceWordJ;
            aOrbiterF = (((aWandererG + RotL64(aIngress, 41U)) + RotL64(aCarry, 57U)) + 17670451230882805140U) + aOrbiterAssignSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterB = (((aWandererJ + RotL64(aScatter, 3U)) + RotL64(aCarry, 5U)) + 8193848740764866860U) + aNonceWordD;
            aOrbiterG = (aWandererA + RotL64(aCross, 10U)) + 15801168428145650104U;
            aOrbiterJ = ((aWandererK + RotL64(aIngress, 21U)) + 2584718176087499066U) + aNonceWordA;
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 14950366247822737997U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 9779293225265670135U;
            aOrbiterK = RotL64((aOrbiterK * 11625969538497982117U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 8688968319288372383U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 13665723186950342601U) ^ aNonceWordP;
            aOrbiterC = RotL64((aOrbiterC * 292035540396910837U), 57U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterK) + 9395428688359973510U) + aOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1]) + aNonceWordI;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 2152719218018108418U;
            aOrbiterF = RotL64((aOrbiterF * 15271961483518392671U), 19U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterC) + 1350324137411377992U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordH;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 8729317951386057921U) ^ aOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6008790836417785083U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 6317310451893678411U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 10175620379041384281U) ^ aNonceWordM;
            aOrbiterA = RotL64((aOrbiterA * 14079679617394330781U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 1203082119358827708U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 523869107818193101U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4629501113595689157U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 4028324959540432983U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 15447631947468213912U;
            aOrbiterB = RotL64((aOrbiterB * 6037306615787729185U), 3U);
            //
            aIngress = RotL64(aOrbiterF, 50U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterB, 21U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 43U));
            aIngress = aIngress + RotL64(aOrbiterG, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterJ, 51U)) + aOrbiterG) + aNonceWordB);
            aWandererA = aWandererA + (((RotL64(aCross, 11U) + aOrbiterC) + RotL64(aOrbiterK, 58U)) + RotL64(aCarry, 37U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterB, 11U)) + aOrbiterA);
            aWandererE = aWandererE + ((((RotL64(aIngress, 34U) + RotL64(aOrbiterG, 21U)) + aOrbiterF) + aNonceWordC) + aWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterB, 27U)) + aOrbiterK) + aWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterA, 5U)) + aOrbiterC) + RotL64(aCarry, 13U)) + aNonceWordG);
            aWandererK = aWandererK ^ ((RotL64(aCross, 51U) + aOrbiterA) + RotL64(aOrbiterJ, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 28U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererA);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 37U));
            aCarry = aCarry + RotL64(aWandererB, 13U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aFireLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 2
        // ingress from: aFireLaneA, aWorkLaneC, aOperationLaneB
        // ingress directions: aFireLaneA forward forced, aWorkLaneC forward forced, aOperationLaneB forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aWorkLaneB
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aWorkLaneB backward/forward random
        // write to: aFireLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aFireLaneA[((aIndex + 8183U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneC[((aIndex + 8642U)) & S_BLOCK1], 56U));
            aIngress ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 6523U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 8098U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 8235U)) & S_BLOCK1], 40U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 6783U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aIngress, 3U) + RotL64(aCross, 35U)) ^ (RotL64(aCarry, 23U) + RotL64(aPrevious, 54U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterA = ((aWandererE + RotL64(aScatter, 21U)) + RotL64(aCarry, 53U)) + 5173905450211892891U;
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 29U)) + 3555542451908039957U) + aNonceWordC;
            aOrbiterI = (((aWandererK + RotL64(aCross, 39U)) + RotL64(aCarry, 13U)) + 11559884700283861559U) + aNonceWordF;
            aOrbiterB = (((aWandererH + RotL64(aIngress, 48U)) + RotL64(aCarry, 29U)) + 1352524329968738673U) + aOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = (aWandererA + RotL64(aScatter, 13U)) + 8914206450420616349U;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 5U)) + 2251523378498463946U) + aOrbiterAssignSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterH = ((aWandererG + RotL64(aCross, 57U)) + 9541575923299247038U) + aNonceWordI;
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 1239854507907214595U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 17698101462598498934U;
            aOrbiterI = RotL64((aOrbiterI * 2304948713665996433U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 12305566971683256060U) + aNonceWordA;
            aOrbiterF = (((aOrbiterF ^ aOrbiterG) ^ 13804545036303215569U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterF = RotL64((aOrbiterF * 10359543704152744971U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 10239749097704329264U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 4212214906286320308U;
            aOrbiterK = RotL64((aOrbiterK * 3661436621615751071U), 57U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterK) + 12192418916967430783U) + aOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1]) + aNonceWordL;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 4475514289326450361U;
            aOrbiterG = RotL64((aOrbiterG * 17497164630368757887U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 17376102613298827459U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 18129393209955439341U;
            aOrbiterH = RotL64((aOrbiterH * 6404089025014118979U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 4014763724300253568U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 17325007199676828814U;
            aOrbiterA = RotL64((aOrbiterA * 1420888274815627083U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 15480474849292388685U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterB = (((aOrbiterB ^ aOrbiterK) ^ 14357924730184375449U) ^ aOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterB = RotL64((aOrbiterB * 16723492259068034209U), 5U);
            //
            aIngress = RotL64(aOrbiterK, 11U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 43U));
            aIngress = aIngress + (RotL64(aOrbiterH, 23U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterA, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aPrevious, 29U) + aOrbiterG) + RotL64(aOrbiterB, 53U)) + aNonceWordO) + aWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aCross, 50U) + RotL64(aOrbiterB, 60U)) + aOrbiterI) + aNonceWordD);
            aWandererH = aWandererH + ((((RotL64(aIngress, 13U) + aOrbiterI) + RotL64(aOrbiterK, 11U)) + RotL64(aCarry, 5U)) + aNonceWordK);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterH, 35U)) + aOrbiterG);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 41U) + aOrbiterA) + RotL64(aOrbiterK, 29U)) + RotL64(aCarry, 23U)) + aWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 21U) + aOrbiterA) + RotL64(aOrbiterF, 43U));
            aWandererG = aWandererG + ((RotL64(aIngress, 5U) + RotL64(aOrbiterI, 19U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 11U));
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererH, 48U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aFireLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 3
        // ingress from: aFireLaneB, aWorkLaneD, aOperationLaneC
        // ingress directions: aFireLaneB forward forced, aWorkLaneD forward forced, aOperationLaneC forward/backward random
        // cross from: aWorkLaneB, aFireLaneA
        // cross directions: aWorkLaneB backward forced, aFireLaneA backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aFireLaneB[((aIndex + 16016U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneD[((aIndex + 15639U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 14301U)) & S_BLOCK1], 4U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 10961U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 13300U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCarry, 43U) + RotL64(aIngress, 6U)) + (RotL64(aPrevious, 57U) ^ RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterF = (aWandererH + RotL64(aIngress, 4U)) + 9855743441035905047U;
            aOrbiterC = (((aWandererK + RotL64(aPrevious, 11U)) + RotL64(aCarry, 27U)) + 8426286937143990276U) + aOrbiterAssignSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterK = (aWandererD + RotL64(aScatter, 47U)) + 7146752367170267002U;
            aOrbiterG = (((aWandererA + RotL64(aCross, 27U)) + RotL64(aCarry, 39U)) + 12947210066678101726U) + aNonceWordC;
            aOrbiterE = (aWandererI + RotL64(aPrevious, 57U)) + 15902163559925328965U;
            aOrbiterA = ((((aWandererC + RotL64(aScatter, 39U)) + RotL64(aCarry, 3U)) + 8506649889346449469U) + aOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1]) + aNonceWordK;
            aOrbiterD = (aWandererG + RotL64(aCross, 21U)) + 8226286036430263052U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 2703047093452420216U) + aOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 6769351326360139560U) ^ aNonceWordE;
            aOrbiterK = RotL64((aOrbiterK * 5318104980014706265U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 9857025533281333281U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 238297452132277585U;
            aOrbiterG = RotL64((aOrbiterG * 12974709749856065985U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 7203572312072908931U) + aOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 12497027346166575632U;
            aOrbiterD = RotL64((aOrbiterD * 1703586436725662307U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 473851890609048879U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 1664484956453886047U) ^ aNonceWordB;
            aOrbiterC = RotL64((aOrbiterC * 8566500756326590209U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 4635095143004754116U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 17695676150967345793U;
            aOrbiterA = RotL64((aOrbiterA * 5780416541584439301U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 15628965269863402796U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 9190117464399730235U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5586437438425999715U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 17835918238346011086U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 4398005402429282682U) ^ aOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14828737209913317463U), 29U);
            //
            aIngress = RotL64(aOrbiterG, 13U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterF, 27U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterK, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aCross, 58U) + aOrbiterA) + RotL64(aOrbiterE, 37U)) + aNonceWordP);
            aWandererD = aWandererD + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterD, 5U)) + aOrbiterF);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterF, 43U)) + aOrbiterA);
            aWandererK = aWandererK + (((RotL64(aIngress, 5U) + aOrbiterG) + RotL64(aOrbiterK, 29U)) + RotL64(aCarry, 13U));
            aWandererC = aWandererC ^ ((((RotL64(aPrevious, 11U) + aOrbiterK) + RotL64(aOrbiterF, 13U)) + aNonceWordH) + aWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aCross, 51U) + aOrbiterC) + RotL64(aOrbiterD, 53U)) + RotL64(aCarry, 57U)) + aNonceWordO);
            aWandererA = aWandererA ^ ((((RotL64(aScatter, 21U) + aOrbiterC) + RotL64(aOrbiterF, 60U)) + aNonceWordJ) + aWandererUpdateSaltB[((aIndex + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 14U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererD, 41U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 4
        // ingress from: aExpandLaneA, aWorkLaneC, aOperationLaneD
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aOperationLaneD forward/backward random
        // cross from: aFireLaneB, aWorkLaneD
        // cross directions: aFireLaneB backward forced, aWorkLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 19791U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneC[((aIndex + 19162U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aOperationLaneD[((aIndex + 20613U)) & S_BLOCK1], 28U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 18884U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 17806U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCarry, 27U) + RotL64(aPrevious, 5U)) + (RotL64(aIngress, 56U) ^ RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterA = (aWandererF + RotL64(aPrevious, 53U)) + 4773124477323378268U;
            aOrbiterD = ((aWandererB + RotL64(aCross, 21U)) + 16848723289435796005U) + aNonceWordN;
            aOrbiterK = ((aWandererD + RotL64(aIngress, 13U)) + 13846642134917107058U) + aOrbiterAssignSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 46U)) + 6472057872482789939U) + aNonceWordI;
            aOrbiterF = ((aWandererG + RotL64(aIngress, 27U)) + RotL64(aCarry, 5U)) + 2747019500690707226U;
            aOrbiterG = (((aWandererE + RotL64(aPrevious, 35U)) + RotL64(aCarry, 21U)) + 9003965289739733880U) + aOrbiterAssignSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterI = ((aWandererA + RotL64(aScatter, 5U)) + RotL64(aCarry, 47U)) + 3013390651936257377U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 3331004709895625067U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 15355010435553517129U;
            aOrbiterK = RotL64((aOrbiterK * 8322759117004876831U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 7709870658004280052U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 13568728443963926564U;
            aOrbiterJ = RotL64((aOrbiterJ * 6736090830113688981U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 12409548853419307131U) + aNonceWordC;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 969183352023661537U;
            aOrbiterD = RotL64((aOrbiterD * 5549220554838837145U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 15370309834426476775U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 3896803894396631184U;
            aOrbiterI = RotL64((aOrbiterI * 11018830202891911603U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 10848873633291935766U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 12885336509190543440U;
            aOrbiterA = RotL64((aOrbiterA * 1487357252619221365U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 8252290890093788010U) + aNonceWordL;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 9201553615601641350U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 420321130559162915U), 23U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterI) + 14014209645503188472U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordD;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 4015071464301844550U;
            aOrbiterF = RotL64((aOrbiterF * 17444195018239904971U), 47U);
            //
            aIngress = RotL64(aOrbiterD, 29U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 22U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 53U));
            aIngress = aIngress + RotL64(aOrbiterK, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aScatter, 19U) + aOrbiterJ) + RotL64(aOrbiterI, 29U)) + aNonceWordJ);
            aWandererD = aWandererD + ((((RotL64(aIngress, 43U) + RotL64(aOrbiterI, 21U)) + aOrbiterK) + aNonceWordB) + aWandererUpdateSaltF[((aIndex + 20U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterJ, 60U)) + aOrbiterG);
            aWandererE = aWandererE + ((((RotL64(aCross, 5U) + aOrbiterG) + RotL64(aOrbiterI, 53U)) + RotL64(aCarry, 5U)) + aNonceWordG);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 26U) + RotL64(aOrbiterD, 47U)) + aOrbiterJ);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 57U) + aOrbiterD) + RotL64(aOrbiterA, 11U)) + RotL64(aCarry, 57U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 51U) + RotL64(aOrbiterI, 3U)) + aOrbiterF) + aWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 28U));
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererG, 11U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 5
        // ingress from: aExpandLaneB, aFireLaneB
        // ingress directions: aExpandLaneB forward forced, aFireLaneB forward/backward random
        // cross from: aExpandLaneA, aWorkLaneA
        // cross directions: aExpandLaneA backward forced, aWorkLaneA backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aExpandLaneB[((aIndex + 22995U)) & S_BLOCK1], 29U) ^ RotL64(aFireLaneB[((aIndex + 22409U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25609U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((aIndex + 26550U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 3U) ^ RotL64(aIngress, 53U)) + (RotL64(aPrevious, 37U) ^ RotL64(aCarry, 22U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterK = (((aWandererF + RotL64(aPrevious, 3U)) + RotL64(aCarry, 47U)) + 12027839670755583592U) + aNonceWordO;
            aOrbiterI = ((aWandererJ + RotL64(aCross, 43U)) + 15380130703509859843U) + aOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = (aWandererH + RotL64(aIngress, 19U)) + 4590907433867798074U;
            aOrbiterJ = ((((aWandererI + RotL64(aScatter, 35U)) + RotL64(aCarry, 19U)) + 1754574023602519724U) + aOrbiterAssignSaltF[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordP;
            aOrbiterC = ((aWandererK + RotL64(aCross, 56U)) + 9832756659564903767U) + aNonceWordH;
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 11U)) + 5035088494491470403U) + aNonceWordC;
            aOrbiterA = ((aWandererD + RotL64(aIngress, 29U)) + RotL64(aCarry, 3U)) + 14199170923323644638U;
            //
            aOrbiterK = (((aOrbiterK + aOrbiterI) + 8325619421264440438U) + aOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1]) + aNonceWordE;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 969534320779067977U) ^ aOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17767548306355264705U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 270575869402913847U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 13344806516599578910U;
            aOrbiterC = RotL64((aOrbiterC * 10193544126281901579U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 15143147951139409101U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 14425582489214169238U;
            aOrbiterE = RotL64((aOrbiterE * 16893787086337916355U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 13951127523239064584U) + aNonceWordM;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 14177925225918293579U;
            aOrbiterK = RotL64((aOrbiterK * 13079514031864998485U), 53U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterJ) + 8258920744278218901U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordG;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 7408161179397242453U;
            aOrbiterI = RotL64((aOrbiterI * 975737128100519169U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 8581481606764773468U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 10078416198417433133U) ^ aOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1102721083915858247U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 18299772198826189580U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 18304668908084397946U) ^ aNonceWordA;
            aOrbiterJ = RotL64((aOrbiterJ * 10589455451200578687U), 19U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterJ, 43U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + (RotL64(aOrbiterC, 60U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterF, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 13U) + aOrbiterI) + RotL64(aOrbiterE, 26U)) + aNonceWordK);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterE, 5U)) + aOrbiterJ) + aNonceWordL);
            aWandererD = aWandererD + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterA, 35U)) + aOrbiterE) + aNonceWordI);
            aWandererC = aWandererC ^ ((RotL64(aCross, 19U) + aOrbiterC) + RotL64(aOrbiterI, 51U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 47U) + aOrbiterK) + RotL64(aOrbiterF, 13U)) + RotL64(aCarry, 53U)) + aWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((((RotL64(aCross, 53U) + RotL64(aOrbiterI, 19U)) + aOrbiterA) + aNonceWordF) + aWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 60U) + RotL64(aOrbiterF, 43U)) + aOrbiterC) + RotL64(aCarry, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 56U) ^ aWandererD);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 41U));
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererF, 23U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 6
        // ingress from: aExpandLaneC, aExpandLaneA
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward/backward random
        // cross from: aExpandLaneB, aWorkLaneB
        // cross directions: aExpandLaneB backward forced, aWorkLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aExpandLaneC[((aIndex + 28835U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27965U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30808U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((aIndex + 32042U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 26U) ^ RotL64(aCross, 13U)) + (RotL64(aCarry, 43U) + RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterG = (((aWandererI + RotL64(aCross, 37U)) + RotL64(aCarry, 41U)) + 3612110001869385068U) + aNonceWordP;
            aOrbiterK = (aWandererJ + RotL64(aPrevious, 21U)) + 16340824141280225936U;
            aOrbiterA = ((((aWandererC + RotL64(aIngress, 58U)) + RotL64(aCarry, 3U)) + 15222338965130765231U) + aOrbiterAssignSaltA[((aIndex + 14U)) & S_SALT1]) + aNonceWordH;
            aOrbiterC = ((aWandererE + RotL64(aScatter, 3U)) + 6649270508107155041U) + aNonceWordO;
            aOrbiterI = ((aWandererD + RotL64(aPrevious, 27U)) + 768217258655426384U) + aOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = ((aWandererH + RotL64(aScatter, 51U)) + RotL64(aCarry, 23U)) + 4481855259658861851U;
            aOrbiterD = (aWandererK + RotL64(aCross, 13U)) + 18318041934562434016U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 4212457153804401807U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 16143621095636987628U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6576072860505961427U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 2095664232866642086U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 4339527736737366572U;
            aOrbiterK = RotL64((aOrbiterK * 17503569508822244125U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 13679353177869884790U) + aOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 11582168502846418236U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 135539430034462861U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 10451330452898542191U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 12951448817640617841U) ^ aOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4141870904192742091U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 15389161934419370747U) + aNonceWordF;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 4754886272708253014U;
            aOrbiterD = RotL64((aOrbiterD * 16638243718191281597U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 11746389873929280688U) + aNonceWordA;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 12042680172517298768U;
            aOrbiterI = RotL64((aOrbiterI * 3814780289755857543U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 2648103752465009244U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 451594673632597973U) ^ aNonceWordC;
            aOrbiterC = RotL64((aOrbiterC * 8496763663271072425U), 35U);
            //
            aIngress = RotL64(aOrbiterD, 29U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterI, 5U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterC, 35U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterF, 46U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterA, 14U)) + aOrbiterG);
            aWandererD = aWandererD + (((RotL64(aScatter, 30U) + aOrbiterD) + RotL64(aOrbiterK, 3U)) + aNonceWordB);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 37U) + aOrbiterI) + RotL64(aOrbiterA, 35U)) + aWandererUpdateSaltB[((aIndex + 26U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aCross, 43U) + RotL64(aOrbiterK, 29U)) + aOrbiterC) + RotL64(aCarry, 3U)) + aNonceWordI);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 13U) + aOrbiterA) + RotL64(aOrbiterD, 21U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 3U) + aOrbiterA) + RotL64(aOrbiterC, 41U)) + RotL64(aCarry, 51U)) + aWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterF, 47U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 58U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + RotL64(aWandererC, 23U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xFFD7409F4B219049ULL + 0xD0329A7985C21510ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xA7199F6C1107CACDULL + 0xDAC0C68C9AE45933ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xC9E6F8840340DD65ULL + 0x98597950A864C71AULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xB7DFC2C0894AB917ULL + 0x9BEEFAC200CB0B7CULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xADFDAC3DB1B623ADULL + 0xC3158987F525A11AULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xBDD2C7FC41785605ULL + 0xEBB51ECA450DAD59ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xF5B330BCAE60C893ULL + 0xE65439C741AE2A74ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xDC356D9D014219B7ULL + 0x8CC1E2A1BCBB74D6ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xD2E8AAB358FF80A1ULL + 0xA1B3F3047628E860ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xC8BCDFD81129F24DULL + 0x8B4F11E06A917CECULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xD4F8CDB521FCAF27ULL + 0xE6FFE877B9F55B4BULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xC5DB1D8F8A4B07CFULL + 0xB172217B4859AF9FULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xB121273768E89A0DULL + 0xC124FB3C94B231FFULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x9523D3E36622BF81ULL + 0xBE8A8274E049545BULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x85DB8EFEE27A66AFULL + 0x89AB84D711D284D6ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xF5942C838CB3179FULL + 0xACA094B123284457ULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneA, aExpandLaneC, aExpandLaneD, aFireLaneB, aOperationLaneA, aFireLaneC, aFireLaneD, aOperationLaneB, aWorkLaneA, aWorkLaneB, aOperationLaneC, aWorkLaneC, aWorkLaneD
        // write to: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // kdf_b_loop_b loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneA
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aFireLaneB
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aFireLaneB backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 7350U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((aIndex + 4497U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 3583U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5852U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 3594U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 8192U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCarry, 56U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterB = (aWandererI + RotL64(aPrevious, 5U)) + 12046647397183218524U;
            aOrbiterD = (aWandererF + RotL64(aCross, 47U)) + 2760779375026461991U;
            aOrbiterK = (((aWandererB + RotL64(aIngress, 26U)) + RotL64(aCarry, 53U)) + 13735454443176855650U) + aOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = ((aWandererC + RotL64(aScatter, 41U)) + RotL64(aCarry, 41U)) + 4370377000586647724U;
            aOrbiterJ = ((aWandererD + RotL64(aCross, 13U)) + 14566322384189969094U) + aNonceWordN;
            aOrbiterA = (aWandererE + RotL64(aIngress, 37U)) + 5056565959818422786U;
            aOrbiterC = (aWandererG + RotL64(aPrevious, 19U)) + 8795403810686579209U;
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 23U)) + 9625947666256011567U) + aOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = ((aWandererK + RotL64(aCross, 43U)) + 1703669290934254701U) + aNonceWordH;
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 56U)) + RotL64(aCarry, 35U)) + 6664070663184147951U;
            aOrbiterG = (aWandererH + RotL64(aIngress, 11U)) + 2104148316797553431U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 1197910004222596145U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 9922977170060903197U;
            aOrbiterK = RotL64((aOrbiterK * 13047828062605568603U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 2048376210852567829U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 12568990647075931409U) ^ aNonceWordI;
            aOrbiterJ = RotL64((aOrbiterJ * 9860242601194210927U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 15026894775772902751U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 3439447160137900629U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1813754963043785165U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 6532671388552829796U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 17261098369835997661U) ^ aOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 568292591215203521U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 3171300991007459947U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 5935563269327662024U;
            aOrbiterD = RotL64((aOrbiterD * 11271790283157765003U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 14290941734320455612U) + aNonceWordM;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 12371794745736518824U;
            aOrbiterB = RotL64((aOrbiterB * 12208762336145168647U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 8782840145467637373U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 4067525421190366741U) ^ aNonceWordB;
            aOrbiterF = RotL64((aOrbiterF * 6671002797916227485U), 41U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterE) + 11854812920571789853U) + aOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1]) + aNonceWordD;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 17564890418553131451U;
            aOrbiterG = RotL64((aOrbiterG * 16657184504366731805U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 6250004085193517531U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 2362659992682660827U;
            aOrbiterH = RotL64((aOrbiterH * 4365619310373869859U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 4597159873252831182U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 13197238269207675773U;
            aOrbiterC = RotL64((aOrbiterC * 379653377172816575U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 8552479493772820372U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 12046647397183218524U;
            aOrbiterE = RotL64((aOrbiterE * 17918033655125400323U), 13U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterC, 35U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 51U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 60U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 27U));
            aIngress = aIngress + RotL64(aOrbiterG, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aIngress, 37U) + aOrbiterE) + RotL64(aOrbiterJ, 20U));
            aWandererB = aWandererB + (((RotL64(aScatter, 11U) + aOrbiterG) + RotL64(aOrbiterK, 41U)) + aNonceWordG);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 39U) + aOrbiterD) + RotL64(aOrbiterE, 11U)) + aWandererUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 23U) + aOrbiterB) + RotL64(aOrbiterI, 35U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 54U) + RotL64(aOrbiterA, 3U)) + aOrbiterI);
            aWandererI = aWandererI + (((RotL64(aCross, 21U) + aOrbiterC) + RotL64(aOrbiterG, 23U)) + RotL64(aCarry, 27U));
            aWandererJ = aWandererJ ^ ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterJ, 57U)) + aOrbiterH) + aNonceWordA) + aWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 51U) + aOrbiterA) + RotL64(aOrbiterB, 53U)) + RotL64(aCarry, 43U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 3U) + aOrbiterH) + RotL64(aOrbiterD, 18U)) + aNonceWordJ);
            aWandererD = aWandererD + ((RotL64(aCross, 27U) + aOrbiterB) + RotL64(aOrbiterF, 47U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 6U) + aOrbiterK) + RotL64(aOrbiterA, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 40U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererI);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererB);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + RotL64(aWandererA, 14U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 2
        // ingress from: aOperationLaneA, aExpandLaneC, aExpandLaneD, aFireLaneC
        // ingress directions: aOperationLaneA forward forced, aExpandLaneC forward forced, aExpandLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneA, aExpandLaneB, aFireLaneD
        // cross directions: aExpandLaneA backward forced, aExpandLaneB backward forced, aFireLaneD backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 11570U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((aIndex + 12483U)) & S_BLOCK1], 37U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 12423U)) & S_BLOCK1], 20U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 13036U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 15834U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 10610U)) & S_BLOCK1], 60U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 12823U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 3U) ^ RotL64(aCarry, 19U)) + (RotL64(aCross, 50U) ^ RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 34U)) + 12632404972795375757U) + aNonceWordN;
            aOrbiterK = ((aWandererI + RotL64(aScatter, 57U)) + RotL64(aCarry, 39U)) + 5351879979055988456U;
            aOrbiterJ = (((aWandererG + RotL64(aIngress, 41U)) + RotL64(aCarry, 19U)) + 3597737727467443413U) + aNonceWordL;
            aOrbiterB = (aWandererJ + RotL64(aCross, 13U)) + 2830846754917852318U;
            aOrbiterC = ((aWandererC + RotL64(aIngress, 29U)) + 17311925960294518018U) + aOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = (aWandererK + RotL64(aPrevious, 19U)) + 2083584640523695383U;
            aOrbiterA = (aWandererA + RotL64(aScatter, 10U)) + 15049343611387010158U;
            aOrbiterG = ((aWandererE + RotL64(aCross, 23U)) + RotL64(aCarry, 43U)) + 6443050378205811147U;
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 39U)) + 6021965178697344070U) + aNonceWordJ;
            aOrbiterI = ((aWandererF + RotL64(aIngress, 53U)) + 5080289878758029976U) + aOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = (aWandererD + RotL64(aScatter, 21U)) + 576927745306972983U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 4728489691382690859U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 6184355840165758855U;
            aOrbiterJ = RotL64((aOrbiterJ * 1515043910404156423U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 11220539885798595450U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 11091438724966718214U;
            aOrbiterC = RotL64((aOrbiterC * 8225347114759391961U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 17184210490020062419U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 2150997767099116408U;
            aOrbiterK = RotL64((aOrbiterK * 8058553821648892499U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 7021953562676903717U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 17159676348343312834U;
            aOrbiterE = RotL64((aOrbiterE * 13877284519668483549U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 10367891770525239784U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 11922478487264201233U) ^ aNonceWordH;
            aOrbiterF = RotL64((aOrbiterF * 9195137452661956029U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 17815162358981720634U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 9582631251085100284U;
            aOrbiterI = RotL64((aOrbiterI * 11838992994130850483U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 872593750259572264U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 17832330100262167302U;
            aOrbiterG = RotL64((aOrbiterG * 1114416841510028467U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 16601139856969287418U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 14931287111691324985U;
            aOrbiterH = RotL64((aOrbiterH * 16757174577841001179U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 11413072442039115924U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterK) ^ 15253605470589905889U) ^ aOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterB = RotL64((aOrbiterB * 10832817442285245673U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 3653487723581514107U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 14891378240114471865U;
            aOrbiterD = RotL64((aOrbiterD * 1386594204573386051U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 15659724464711852035U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 12632404972795375757U;
            aOrbiterA = RotL64((aOrbiterA * 2407347385127296647U), 3U);
            //
            aIngress = RotL64(aOrbiterE, 41U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterD, 18U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterG, 53U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + (RotL64(aOrbiterH, 29U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterG, 5U)) + aOrbiterF) + aWandererUpdateSaltA[((aIndex + 14U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 52U) + aOrbiterI) + RotL64(aOrbiterA, 57U)) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterG, 41U)) + aOrbiterK);
            aWandererD = aWandererD + (((RotL64(aScatter, 41U) + aOrbiterD) + RotL64(aOrbiterB, 36U)) + aNonceWordK);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 47U) + aOrbiterD) + RotL64(aOrbiterH, 11U)) + aNonceWordM);
            aWandererF = aWandererF + (((RotL64(aCross, 60U) + RotL64(aOrbiterI, 43U)) + aOrbiterC) + aNonceWordI);
            aWandererH = aWandererH ^ ((((RotL64(aIngress, 19U) + aOrbiterE) + RotL64(aOrbiterG, 29U)) + aNonceWordF) + aWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 11U) + RotL64(aOrbiterH, 27U)) + aOrbiterI) + RotL64(aCarry, 43U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterK, 21U)) + aOrbiterJ);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 29U) + aOrbiterJ) + RotL64(aOrbiterD, 23U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterE, 38U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererC, 26U) ^ aWandererK);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererB, 3U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 3
        // ingress from: aOperationLaneB, aExpandLaneA, aExpandLaneB, aWorkLaneA
        // ingress directions: aOperationLaneB forward forced, aExpandLaneA forward forced, aExpandLaneB forward forced, aWorkLaneA forward/backward random
        // cross from: aOperationLaneA, aExpandLaneC, aWorkLaneB
        // cross directions: aOperationLaneA backward forced, aExpandLaneC backward forced, aWorkLaneB backward/forward random
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 23284U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((aIndex + 20742U)) & S_BLOCK1], 11U));
            aIngress ^= (RotL64(aExpandLaneB[((aIndex + 19880U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21599U)) & S_BLOCK1], 26U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 21033U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 22627U)) & S_BLOCK1], 6U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 23458U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aPrevious, 18U) ^ RotL64(aCross, 3U)) ^ (RotL64(aIngress, 53U) + RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterD = ((aWandererG + RotL64(aScatter, 39U)) + 12690502671561165478U) + aNonceWordI;
            aOrbiterG = ((aWandererC + RotL64(aIngress, 26U)) + 17519943923428102801U) + aNonceWordG;
            aOrbiterA = (((aWandererA + RotL64(aPrevious, 3U)) + RotL64(aCarry, 5U)) + 10705515807975331385U) + aNonceWordC;
            aOrbiterE = (((aWandererF + RotL64(aCross, 29U)) + RotL64(aCarry, 57U)) + 16586447272278538179U) + aOrbiterAssignSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = (aWandererI + RotL64(aScatter, 53U)) + 8006560996840971798U;
            aOrbiterC = ((aWandererD + RotL64(aCross, 48U)) + 12928600185788857701U) + aOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = (aWandererJ + RotL64(aPrevious, 35U)) + 14240723153798267172U;
            aOrbiterI = ((aWandererK + RotL64(aIngress, 43U)) + RotL64(aCarry, 51U)) + 8636219177994872072U;
            aOrbiterK = (aWandererB + RotL64(aCross, 57U)) + 7586790235186467512U;
            aOrbiterJ = (aWandererH + RotL64(aPrevious, 21U)) + 1103807034179512424U;
            aOrbiterB = (aWandererE + RotL64(aIngress, 41U)) + 7547526530239498693U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 8380239679344786397U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 5690809173787433519U;
            aOrbiterA = RotL64((aOrbiterA * 5354724308093372953U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 8390902801141804609U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 3507306189192059486U;
            aOrbiterH = RotL64((aOrbiterH * 18336280496510253103U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 6190745292098482871U) + aOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 8065418693975056902U;
            aOrbiterF = RotL64((aOrbiterF * 6414621418430102589U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 12111755051718111803U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 7605877769709909297U) ^ aNonceWordO;
            aOrbiterD = RotL64((aOrbiterD * 17525248694315944599U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 5969794501112646237U) + aNonceWordM;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 5127559299360591476U) ^ aOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4521563633438853069U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 10593847754747739786U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 4401750688524310121U;
            aOrbiterB = RotL64((aOrbiterB * 14265829318976633707U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 6927893132508779499U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterC) ^ 4874009978647014479U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterI = RotL64((aOrbiterI * 13340466017023540755U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 13146693487138744677U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 3298472134223595298U;
            aOrbiterJ = RotL64((aOrbiterJ * 2145005258008477281U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 8729305340729268734U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 18347161842033439538U;
            aOrbiterE = RotL64((aOrbiterE * 7952715248988302017U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 166831495912855225U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 4943633045563697271U;
            aOrbiterK = RotL64((aOrbiterK * 1809857625425000137U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 2460623715340753589U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 12690502671561165478U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16421139715633515623U), 23U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterG, 51U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 11U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 28U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterE, 53U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterH, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aCross, 23U) + RotL64(aOrbiterC, 18U)) + aOrbiterD) + RotL64(aCarry, 35U)) + aNonceWordP);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 4U) + RotL64(aOrbiterC, 13U)) + aOrbiterI) + aWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aIngress, 39U) + RotL64(aOrbiterB, 3U)) + aOrbiterH) + RotL64(aCarry, 23U)) + aNonceWordN);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 37U) + aOrbiterF) + RotL64(aOrbiterB, 53U));
            aWandererG = aWandererG + (((RotL64(aScatter, 19U) + RotL64(aOrbiterG, 27U)) + aOrbiterC) + aNonceWordA);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterG, 41U)) + aOrbiterK);
            aWandererD = aWandererD + (((RotL64(aPrevious, 6U) + aOrbiterC) + RotL64(aOrbiterA, 29U)) + aWandererUpdateSaltB[((aIndex + 14U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterE, 39U)) + aOrbiterI);
            aWandererE = aWandererE + (((RotL64(aScatter, 29U) + RotL64(aOrbiterI, 20U)) + aOrbiterK) + aNonceWordH);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 27U) + aOrbiterB) + RotL64(aOrbiterJ, 57U));
            aWandererC = aWandererC + ((RotL64(aCross, 47U) + RotL64(aOrbiterE, 11U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererE, 56U) ^ aWandererC);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 41U));
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + RotL64(aWandererA, 4U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 4
        // ingress from: aOperationLaneC, aOperationLaneA, aExpandLaneD, aWorkLaneC
        // ingress directions: aOperationLaneC forward forced, aOperationLaneA forward forced, aExpandLaneD forward forced, aWorkLaneC forward/backward random
        // cross from: aOperationLaneB, aExpandLaneB, aWorkLaneD
        // cross directions: aOperationLaneB backward forced, aExpandLaneB backward forced, aWorkLaneD backward/forward random
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneC[((aIndex + 27355U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneA[((aIndex + 28596U)) & S_BLOCK1], 56U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 25224U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 27317U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28903U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29380U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 25073U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 27U) ^ RotL64(aCarry, 43U)) + (RotL64(aCross, 14U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterI = (((aWandererC + RotL64(aPrevious, 14U)) + RotL64(aCarry, 3U)) + 7632760812370906911U) + aNonceWordN;
            aOrbiterE = (aWandererH + RotL64(aIngress, 11U)) + 6007174525479723089U;
            aOrbiterD = (((aWandererI + RotL64(aScatter, 29U)) + RotL64(aCarry, 13U)) + 3362829642521821048U) + aOrbiterAssignSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterA = (((aWandererG + RotL64(aCross, 51U)) + RotL64(aCarry, 35U)) + 18009548556107978286U) + aNonceWordK;
            aOrbiterC = (aWandererE + RotL64(aScatter, 46U)) + 17880909432272697327U;
            aOrbiterF = (aWandererA + RotL64(aCross, 53U)) + 15961567935420752568U;
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 21U)) + 10136559064656837921U) + aNonceWordF;
            aOrbiterB = (aWandererD + RotL64(aIngress, 39U)) + 17622019364405410277U;
            aOrbiterK = (((aWandererB + RotL64(aCross, 5U)) + 6927494824421416306U) + aOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordM;
            aOrbiterG = (aWandererJ + RotL64(aIngress, 19U)) + 7125170407794874847U;
            aOrbiterH = (aWandererF + RotL64(aScatter, 35U)) + 12342273503071032250U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 14997696377476124836U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 14874498694181230698U;
            aOrbiterD = RotL64((aOrbiterD * 4026127545746010937U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 2549397729130885686U) + aNonceWordH;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 4217995818662767955U;
            aOrbiterC = RotL64((aOrbiterC * 5525525344485251063U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 4706089044415442525U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 17983900172670031015U;
            aOrbiterJ = RotL64((aOrbiterJ * 541552737180932879U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 1904937798143929988U) + aOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 10620877287033139483U;
            aOrbiterA = RotL64((aOrbiterA * 16711012562024287213U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 15681091173163181525U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 2655543246639000084U;
            aOrbiterB = RotL64((aOrbiterB * 16686375598149755947U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 2647895110857289213U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 5581609212017175954U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15330263616699031311U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 13609076329627787987U) + aOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 6244266279516622070U;
            aOrbiterK = RotL64((aOrbiterK * 12488345779236971095U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 5289624364508923581U) + aOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 16351476803965903112U;
            aOrbiterI = RotL64((aOrbiterI * 9012522724650442597U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 2731198704224650506U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 4177455951984414332U;
            aOrbiterG = RotL64((aOrbiterG * 2567165277406175517U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 3031687737578718714U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 4866790771642413883U) ^ aNonceWordL;
            aOrbiterE = RotL64((aOrbiterE * 1139524449666360541U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 12903299652398385014U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 7632760812370906911U;
            aOrbiterH = RotL64((aOrbiterH * 7924544687662448385U), 41U);
            //
            aIngress = RotL64(aOrbiterB, 37U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterA, 58U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + (RotL64(aOrbiterC, 21U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 41U));
            aIngress = aIngress + RotL64(aOrbiterD, 30U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterI, 18U)) + aOrbiterE);
            aWandererE = aWandererE + (((((RotL64(aScatter, 39U) + aOrbiterF) + RotL64(aOrbiterB, 37U)) + RotL64(aCarry, 43U)) + aNonceWordP) + aWandererUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterH, 35U)) + aOrbiterC);
            aWandererC = aWandererC + ((RotL64(aIngress, 46U) + RotL64(aOrbiterB, 57U)) + aOrbiterK);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 37U) + aOrbiterH) + RotL64(aOrbiterE, 51U));
            aWandererI = aWandererI + ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterF, 41U)) + aOrbiterK) + RotL64(aCarry, 39U)) + aNonceWordB);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterD, 28U)) + aWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 20U) + RotL64(aOrbiterE, 11U)) + aOrbiterA);
            aWandererD = aWandererD ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterA, 3U)) + aOrbiterD);
            aWandererB = aWandererB + ((RotL64(aPrevious, 43U) + aOrbiterG) + RotL64(aOrbiterD, 5U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterJ, 13U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 5U));
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 42U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 51U));
            aCarry = aCarry + RotL64(aWandererI, 21U);
            aCarry = aCarry + RotL64(aIngress, 44U);
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xB745CBBB9BC512F7ULL + 0xBF186A9B80797B3DULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xB9A4957AC69AB33DULL + 0xB933D3530F088CA5ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xD63058656EC38D8FULL + 0xBF349247E4206325ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xA037396262E6FBDBULL + 0xE06304C9742A1EABULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x81A1959BB2D02F43ULL + 0xBEC850D697090E2FULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xCFAA6290767019C9ULL + 0x8623536146692A06ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x8D47743B56730EBBULL + 0xAE3C53EB0D4D612AULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xBDA1CB0FC585F115ULL + 0x8063BE765FB9D18CULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xE664D87515167F2DULL + 0xE98548C9459FABA0ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xE53FDD9D69DF4E01ULL + 0xA9F1E36862404430ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xBDAD81AF67253233ULL + 0xF0650E345A8845DCULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x926D36B0F8DBD5C5ULL + 0x92E93C5316B710C1ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xE580099CFFF9EF25ULL + 0xEF001104C7FA04F1ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xA19FB9F471A7F1C7ULL + 0xB1BF35D10CF2B5A3ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xF334AEE7DB62BE65ULL + 0x8315052C26DEA9AFULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x87741464C64C0273ULL + 0x98C8F0133D89B9D9ULL);
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
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneA, aOperationLaneC, aOperationLaneD, aFireLaneB, aExpandLaneA, aFireLaneC, aFireLaneD, aExpandLaneB, aWorkLaneA, aWorkLaneB, aExpandLaneC, aWorkLaneC, aWorkLaneD
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aFireLaneA
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aFireLaneB
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aFireLaneB backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 6717U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((aIndex + 2519U)) & S_BLOCK1], 46U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 7022U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 7319U)) & S_BLOCK1], 6U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 6610U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 3373U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCross, 52U) + RotL64(aIngress, 23U)) ^ (RotL64(aPrevious, 11U) ^ RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 30U)) + RotL64(aCarry, 27U)) + 4179952823252098240U;
            aOrbiterA = (aWandererI + RotL64(aIngress, 57U)) + 3745613452332101749U;
            aOrbiterE = (aWandererA + RotL64(aScatter, 51U)) + 2955689793395307176U;
            aOrbiterI = (aWandererH + RotL64(aCross, 47U)) + 5639060180251322019U;
            aOrbiterC = (aWandererK + RotL64(aScatter, 41U)) + 7901969163853586463U;
            aOrbiterG = ((aWandererG + RotL64(aPrevious, 13U)) + 2242166787816318119U) + aNonceWordK;
            aOrbiterJ = (((aWandererJ + RotL64(aIngress, 3U)) + 5239936443960750064U) + aOrbiterAssignSaltA[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordB;
            aOrbiterH = (((aWandererC + RotL64(aCross, 20U)) + RotL64(aCarry, 43U)) + 13939136954732185558U) + aOrbiterAssignSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterK = ((aWandererB + RotL64(aIngress, 37U)) + RotL64(aCarry, 3U)) + 17058884136712717463U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 18148618660054585941U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 7022023484530327814U;
            aOrbiterE = RotL64((aOrbiterE * 650100011311048589U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 7722084537340095637U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 11764151879690934182U) ^ aNonceWordF;
            aOrbiterA = RotL64((aOrbiterA * 12264384877711365655U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 16412785901758144708U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 9666718667728274824U;
            aOrbiterJ = RotL64((aOrbiterJ * 10865799822751771795U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 4307127540152109364U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 2457646804702647606U;
            aOrbiterD = RotL64((aOrbiterD * 6340030928007058595U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 3179394870088602208U) + aNonceWordM;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 504977947273774249U;
            aOrbiterG = RotL64((aOrbiterG * 16190282058883481551U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 16182729401018310837U) + aNonceWordH;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 7110817020445860609U) ^ aOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13371352088428584087U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 12960656706837391973U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 7103806893724395904U;
            aOrbiterK = RotL64((aOrbiterK * 14365984439655979791U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 1248300178080633527U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 7195473175424961337U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4633558992739305045U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 13007951568242991449U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 10296811247653636372U) ^ aOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16469682651380549395U), 3U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterC, 35U);
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 48U));
            aIngress = aIngress + (RotL64(aOrbiterD, 5U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterA, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aScatter, 23U) + aOrbiterC) + RotL64(aOrbiterH, 3U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 50U) + aOrbiterH) + RotL64(aOrbiterE, 47U)) + aNonceWordC);
            aWandererG = aWandererG + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterI, 19U)) + aOrbiterA) + aNonceWordG) + aWandererUpdateSaltD[((aIndex + 19U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 19U) + aOrbiterJ) + RotL64(aOrbiterC, 38U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 27U) + aOrbiterD) + RotL64(aOrbiterC, 29U)) + RotL64(aCarry, 39U)) + aNonceWordA);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 37U) + aOrbiterH) + RotL64(aOrbiterA, 23U)) + aNonceWordI);
            aWandererI = aWandererI + ((RotL64(aCross, 13U) + aOrbiterG) + RotL64(aOrbiterC, 43U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterJ, 14U)) + aOrbiterD) + aWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 46U) + aOrbiterK) + RotL64(aOrbiterH, 53U)) + RotL64(aCarry, 47U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + (RotL64(aWandererC, 53U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 56U));
            aCarry = aCarry + RotL64(aWandererH, 47U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 2
        // ingress from: aExpandLaneA, aOperationLaneC, aOperationLaneD, aFireLaneC
        // ingress directions: aExpandLaneA forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aFireLaneD
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 14527U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneC[((aIndex + 8776U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 16174U)) & S_BLOCK1], 41U) ^ RotL64(aFireLaneC[((aIndex + 12960U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 11506U)) & S_BLOCK1], 20U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 14201U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 8231U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 52U) ^ RotL64(aCarry, 39U)) + (RotL64(aCross, 5U) ^ RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterK = (aWandererA + RotL64(aIngress, 39U)) + 5576732410244514238U;
            aOrbiterJ = (((aWandererJ + RotL64(aScatter, 13U)) + RotL64(aCarry, 57U)) + 2833808925935929629U) + aNonceWordF;
            aOrbiterH = (aWandererB + RotL64(aCross, 60U)) + 3670188682914544792U;
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 47U)) + 15759072378887814995U) + aNonceWordD;
            aOrbiterD = (((aWandererD + RotL64(aCross, 21U)) + RotL64(aCarry, 19U)) + 13934007231137439994U) + aNonceWordN;
            aOrbiterC = (((aWandererF + RotL64(aIngress, 43U)) + RotL64(aCarry, 47U)) + 11022225696007690512U) + aOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = ((aWandererE + RotL64(aScatter, 5U)) + 16989177104453635790U) + aOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 27U)) + 9256930045263527091U) + aNonceWordH;
            aOrbiterE = (aWandererG + RotL64(aCross, 56U)) + 17788596104417068290U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 17044369456673337625U) + aNonceWordM;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 1310908395523250343U;
            aOrbiterH = RotL64((aOrbiterH * 16305084373037705921U), 13U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterF) + 12067065689034065422U) + aOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1]) + aNonceWordK;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 15130844248737512262U;
            aOrbiterD = RotL64((aOrbiterD * 9409499577465934107U), 37U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterI) + 14532689204495587494U) + aOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1]) + aNonceWordI;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 8198147292120244178U) ^ aOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1418356389507740991U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 5485494458627163347U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 10830008207150307611U;
            aOrbiterI = RotL64((aOrbiterI * 6526039534042499457U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 17770065502486618029U) + aNonceWordC;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 6397859353395335459U;
            aOrbiterK = RotL64((aOrbiterK * 14286997752368893825U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 5128700697381508319U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 7103394110057060499U;
            aOrbiterF = RotL64((aOrbiterF * 5053680689949149633U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 16024401282261796979U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 12818445221897253410U;
            aOrbiterE = RotL64((aOrbiterE * 11450004517784155405U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 13386978409145916350U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 16740821954556699503U;
            aOrbiterC = RotL64((aOrbiterC * 5376430209628515105U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 313978038530994953U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 1355733685461795345U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15955927322082619735U), 41U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterI, 10U);
            aIngress = aIngress + (RotL64(aOrbiterK, 19U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterF, 3U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterA, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aScatter, 3U) + aOrbiterH) + RotL64(aOrbiterA, 18U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 48U) + RotL64(aOrbiterC, 3U)) + aOrbiterF);
            aWandererD = aWandererD + ((((RotL64(aCross, 43U) + RotL64(aOrbiterH, 51U)) + aOrbiterK) + RotL64(aCarry, 53U)) + aWandererUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterE, 29U)) + aOrbiterJ);
            aWandererF = aWandererF + ((((RotL64(aScatter, 23U) + aOrbiterD) + RotL64(aOrbiterJ, 22U)) + RotL64(aCarry, 37U)) + aNonceWordB);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterJ, 35U)) + aOrbiterA) + aNonceWordP);
            aWandererC = aWandererC + (((RotL64(aIngress, 57U) + aOrbiterC) + RotL64(aOrbiterI, 43U)) + aWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 29U) + aOrbiterE) + RotL64(aOrbiterI, 11U));
            aWandererH = aWandererH + ((RotL64(aScatter, 10U) + RotL64(aOrbiterJ, 39U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererA);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + (RotL64(aWandererD, 22U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 39U));
            aCarry = aCarry + RotL64(aWandererH, 47U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 3
        // ingress from: aExpandLaneB, aOperationLaneA, aOperationLaneB, aWorkLaneA
        // ingress directions: aExpandLaneB forward forced, aOperationLaneA forward forced, aOperationLaneB forward forced, aWorkLaneA forward/backward random
        // cross from: aExpandLaneA, aOperationLaneC, aWorkLaneB
        // cross directions: aExpandLaneA backward forced, aOperationLaneC backward forced, aWorkLaneB backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 18818U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((aIndex + 20824U)) & S_BLOCK1], 39U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 21637U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneA[((aIndex + 18415U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 20558U)) & S_BLOCK1], 18U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 24097U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17566U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCross, 41U)) + (RotL64(aCarry, 12U) ^ RotL64(aPrevious, 29U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterF = ((aWandererD + RotL64(aCross, 26U)) + 14624277139785904404U) + aOrbiterAssignSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterC = (aWandererJ + RotL64(aIngress, 43U)) + 6966977309498165611U;
            aOrbiterH = (((aWandererI + RotL64(aScatter, 11U)) + RotL64(aCarry, 23U)) + 205536824352530761U) + aNonceWordD;
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 57U)) + 16629575265808255692U) + aNonceWordO;
            aOrbiterI = (aWandererF + RotL64(aScatter, 47U)) + 596881340147972746U;
            aOrbiterE = (aWandererH + RotL64(aCross, 5U)) + 11944412799107412650U;
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 22U)) + RotL64(aCarry, 37U)) + 4615021315668210206U;
            aOrbiterG = (aWandererC + RotL64(aIngress, 51U)) + 8497630055977606216U;
            aOrbiterJ = (((aWandererB + RotL64(aCross, 35U)) + RotL64(aCarry, 11U)) + 11131601107309336885U) + aOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 5935883479805510099U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 15629346719765798174U;
            aOrbiterH = RotL64((aOrbiterH * 8535523790685945275U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 5279128339113651273U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 16778365912440331821U;
            aOrbiterE = RotL64((aOrbiterE * 705421028266789241U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 16003052937645491524U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 6723226158737614764U;
            aOrbiterF = RotL64((aOrbiterF * 16690657664909260573U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 9785784358981219543U) + aNonceWordL;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 10055457337292292710U) ^ aNonceWordP;
            aOrbiterC = RotL64((aOrbiterC * 17919129940751761111U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 11779163108592974175U) + aOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 1177999477942202687U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13475069421684114643U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 9190694445141492214U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 15605342360346353457U;
            aOrbiterJ = RotL64((aOrbiterJ * 14547769706392595647U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 14877565450677523492U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 1074095623308025684U) ^ aOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7884068939436891093U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 12803174154216941583U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 8813356463693637033U) ^ aNonceWordM;
            aOrbiterI = RotL64((aOrbiterI * 4898237214617563167U), 13U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterH) + 6063909634038581414U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordH;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 15112191502834052566U;
            aOrbiterD = RotL64((aOrbiterD * 6780741782103553485U), 27U);
            //
            aIngress = RotL64(aOrbiterG, 27U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 37U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 30U));
            aIngress = aIngress + (RotL64(aOrbiterK, 23U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterJ, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aScatter, 19U) + aOrbiterG) + RotL64(aOrbiterJ, 11U));
            aWandererH = aWandererH + ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterH, 60U)) + aOrbiterI) + RotL64(aCarry, 53U)) + aNonceWordE);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 5U) + aOrbiterF) + RotL64(aOrbiterK, 35U)) + aNonceWordI);
            aWandererK = aWandererK + ((RotL64(aIngress, 34U) + aOrbiterD) + RotL64(aOrbiterC, 23U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 51U) + RotL64(aOrbiterK, 19U)) + aOrbiterC) + aWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterD, 43U)) + aOrbiterG) + aWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 47U) + aOrbiterI) + RotL64(aOrbiterJ, 3U)) + aNonceWordN);
            aWandererF = aWandererF + ((((RotL64(aIngress, 23U) + aOrbiterE) + RotL64(aOrbiterG, 39U)) + RotL64(aCarry, 23U)) + aNonceWordC);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 56U) + aOrbiterK) + RotL64(aOrbiterI, 56U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 24U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererC, 6U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aOperationLaneD, aWorkLaneC
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aOperationLaneD forward forced, aWorkLaneC forward/backward random
        // cross from: aExpandLaneB, aOperationLaneB, aWorkLaneD
        // cross directions: aExpandLaneB backward forced, aOperationLaneB backward forced, aWorkLaneD backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 31744U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneA[((aIndex + 26433U)) & S_BLOCK1], 13U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 28218U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneC[((aIndex + 30955U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26211U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31397U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 27749U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 13U) ^ RotL64(aIngress, 60U)) + (RotL64(aCarry, 27U) + RotL64(aPrevious, 43U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 37U)) + 18191288703716505885U) + aOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = ((aWandererF + RotL64(aScatter, 5U)) + RotL64(aCarry, 3U)) + 9824014524910417136U;
            aOrbiterD = ((aWandererI + RotL64(aCross, 30U)) + RotL64(aCarry, 51U)) + 11953012029254917548U;
            aOrbiterA = (aWandererE + RotL64(aIngress, 47U)) + 6297568011027199089U;
            aOrbiterG = (((aWandererG + RotL64(aCross, 13U)) + 2576999400457367975U) + aOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordN;
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 23U)) + RotL64(aCarry, 13U)) + 13176139160575558254U;
            aOrbiterI = ((aWandererH + RotL64(aIngress, 51U)) + 9978408174563621810U) + aNonceWordG;
            aOrbiterF = (aWandererB + RotL64(aScatter, 18U)) + 16765834875061607142U;
            aOrbiterK = ((aWandererJ + RotL64(aCross, 57U)) + 16534507305459121344U) + aNonceWordD;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 3114710944346151807U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 10240517868726718592U;
            aOrbiterD = RotL64((aOrbiterD * 4645691562915606463U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 10721450637990777883U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 16689590768796583952U;
            aOrbiterE = RotL64((aOrbiterE * 3046344179729901637U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 2427422768928450209U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 13495584061816457831U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6670984773768885119U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 7058636403765106682U) + aNonceWordL;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 9897341853944713767U;
            aOrbiterC = RotL64((aOrbiterC * 14286816859999869231U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 17749559755733386064U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 12515645083926326659U;
            aOrbiterH = RotL64((aOrbiterH * 6582878478865838245U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 2625692458813609962U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 10596240255026143019U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11605800195771080135U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 12374290338067865540U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 1507386663796330249U) ^ aOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1210241080424446087U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 9288099549484146726U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 15159312464747000702U) ^ aNonceWordK;
            aOrbiterA = RotL64((aOrbiterA * 500055502081347757U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 14998608679505446229U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 17625038109437732009U;
            aOrbiterK = RotL64((aOrbiterK * 14785862243019841689U), 29U);
            //
            aIngress = RotL64(aOrbiterD, 23U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + (RotL64(aOrbiterC, 10U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterF, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aCross, 21U) + aOrbiterE) + RotL64(aOrbiterA, 39U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 37U) + RotL64(aOrbiterF, 23U)) + aOrbiterG) + aWandererUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 29U) + aOrbiterA) + RotL64(aOrbiterC, 57U)) + RotL64(aCarry, 41U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 42U) + RotL64(aOrbiterF, 52U)) + aOrbiterA);
            aWandererG = aWandererG + (((RotL64(aScatter, 53U) + aOrbiterK) + RotL64(aOrbiterA, 27U)) + RotL64(aCarry, 51U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterH, 5U)) + aOrbiterG) + aWandererUpdateSaltD[((aIndex + 14U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterF, 35U)) + aOrbiterD) + aNonceWordE);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 4U) + aOrbiterH) + RotL64(aOrbiterI, 19U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 47U) + aOrbiterC) + RotL64(aOrbiterH, 10U)) + aNonceWordM);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + (RotL64(aWandererE, 6U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + RotL64(aWandererJ, 11U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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

void TwistExpander_Bowling_Arx::KDF_B_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xFD6B1EA5A46B92F3ULL + 0xC7344F7E5D2BB08AULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xDC6BBDF5E0EDB72DULL + 0x9B3BECBB79ADE771ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x8E55456F6814E8CDULL + 0x81DFDD7053D1677EULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xA453E2CD70B31603ULL + 0xE78EC963302FB07EULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xDCFC501742620B63ULL + 0xAA24C75843481AAEULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x869A74AD44965E0BULL + 0x9F1C9471602FFE4FULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x90E433F64DC63AE1ULL + 0x82F1B6641CEA567AULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xF30838596D15FBD7ULL + 0xE6F482517C3C4557ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xB2F0FA72B3ED20D9ULL + 0x82A9F778CBEDC4ACULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xA957D5E93AED448DULL + 0xB7667A3FE85C772AULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xDEC23B2D840A4BC3ULL + 0x8E7172072F81A246ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xCDA677400B37B215ULL + 0xE5801721C7C51D13ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xDD3AA567C13142A3ULL + 0xAAAD545E61AF2BDEULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x8183798961A1749BULL + 0xEAC6E3984F7206D6ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x85D6AB61DED75109ULL + 0xE8ECB6A32174C3C6ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xA743419F3E5ADF7DULL + 0xCB3AACE9B912ADC5ULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aFireLaneA, aWorkLaneC, aWorkLaneD, aFireLaneB, aExpandLaneA, aFireLaneC, aFireLaneD, aExpandLaneB, aOperationLaneA, aOperationLaneB, aExpandLaneC, aOperationLaneC, aOperationLaneD
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_d loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aFireLaneA
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aFireLaneB
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aFireLaneB backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 1416U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((aIndex + 1659U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 5826U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 5006U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 4438U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 790U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aPrevious, 5U)) ^ (RotL64(aIngress, 28U) + RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterD = ((aWandererG + RotL64(aScatter, 41U)) + RotL64(aCarry, 27U)) + 380024772508948442U;
            aOrbiterG = (aWandererC + RotL64(aCross, 4U)) + 7649029098162567210U;
            aOrbiterA = ((aWandererD + RotL64(aIngress, 21U)) + RotL64(aCarry, 53U)) + 5329304598870421851U;
            aOrbiterI = (((aWandererA + RotL64(aPrevious, 27U)) + 12306118665045151326U) + aOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordN;
            aOrbiterB = (((aWandererF + RotL64(aCross, 13U)) + RotL64(aCarry, 13U)) + 960751560457324256U) + aOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 47U)) + 3244070254386191876U) + aNonceWordP;
            aOrbiterK = (aWandererK + RotL64(aPrevious, 57U)) + 15733408571609521746U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 17623448932647018544U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 8787759896149035829U;
            aOrbiterA = RotL64((aOrbiterA * 7092515868845497573U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 14741681792348288162U) + aOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 8801731213568307302U;
            aOrbiterB = RotL64((aOrbiterB * 12127126999570616489U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 9872248187499779222U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 15407371518644528235U;
            aOrbiterE = RotL64((aOrbiterE * 1245102406469471673U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 4242060317152943062U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 9942784962409917541U;
            aOrbiterK = RotL64((aOrbiterK * 888649755587764533U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 7296348796484458631U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = (((aOrbiterD ^ aOrbiterK) ^ 15061417216070157797U) ^ aOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterD = RotL64((aOrbiterD * 10349554676953256231U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 3233185810644297433U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 9241229457641024287U) ^ aNonceWordL;
            aOrbiterI = RotL64((aOrbiterI * 2728237515724597517U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 8464051359381554575U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterE) ^ 3307872165699029375U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterG = RotL64((aOrbiterG * 4859663401033023433U), 11U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterA, 19U);
            aIngress = aIngress + (RotL64(aOrbiterD, 5U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterE, 35U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterI, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aIngress, 46U) + aOrbiterI) + RotL64(aOrbiterD, 29U)) + aNonceWordM);
            aWandererK = aWandererK + ((((RotL64(aCross, 21U) + RotL64(aOrbiterD, 35U)) + aOrbiterA) + RotL64(aCarry, 13U)) + aWandererUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 53U) + aOrbiterE) + RotL64(aOrbiterD, 41U)) + aNonceWordI);
            aWandererC = aWandererC + (((RotL64(aPrevious, 13U) + aOrbiterA) + RotL64(aOrbiterB, 19U)) + RotL64(aCarry, 35U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 39U) + aOrbiterE) + RotL64(aOrbiterG, 47U));
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 29U) + aOrbiterA) + RotL64(aOrbiterI, 54U)) + aNonceWordB) + aWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterK, 11U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererG, 18U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aWorkLaneD, aFireLaneC
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aWorkLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aWorkLaneA, aWorkLaneB, aFireLaneD
        // cross directions: aWorkLaneA backward forced, aWorkLaneB backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 15139U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneC[((aIndex + 11407U)) & S_BLOCK1], 51U));
            aIngress ^= (RotL64(aWorkLaneD[((aIndex + 9760U)) & S_BLOCK1], 30U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 16221U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 8885U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 12429U)) & S_BLOCK1], 6U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 13994U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aIngress, 23U)) + (RotL64(aCarry, 11U) + RotL64(aPrevious, 58U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterJ = (((aWandererD + RotL64(aScatter, 51U)) + RotL64(aCarry, 21U)) + 6068543441070417854U) + aOrbiterAssignSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterK = (((aWandererG + RotL64(aIngress, 23U)) + 2995980468193441856U) + aOrbiterAssignSaltF[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordA;
            aOrbiterE = (aWandererI + RotL64(aPrevious, 57U)) + 18020277482171594003U;
            aOrbiterI = ((aWandererH + RotL64(aCross, 40U)) + RotL64(aCarry, 47U)) + 4293807434721230702U;
            aOrbiterD = ((aWandererK + RotL64(aIngress, 29U)) + 7980599111583893156U) + aNonceWordF;
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 11U)) + RotL64(aCarry, 35U)) + 8593141111851052016U;
            aOrbiterB = ((aWandererC + RotL64(aScatter, 3U)) + 5903487523900084325U) + aNonceWordI;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 15112035513447930209U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 9854037263057006439U;
            aOrbiterE = RotL64((aOrbiterE * 396276470208637283U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 16759760289688823193U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 12622628933030601390U;
            aOrbiterK = RotL64((aOrbiterK * 2151912984825538321U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 1264668857268123425U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 16302812053619101593U;
            aOrbiterB = RotL64((aOrbiterB * 18291400055836111547U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 16087995784896123610U) + aOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 7970269262800468363U) ^ aOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14924752223305807461U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 5331477046030959632U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 16534913204255550893U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1013433634373673565U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 11042821902537871209U) + aNonceWordL;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterB) ^ 8069677512345031660U) ^ aOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterJ = RotL64((aOrbiterJ * 13622218526054132397U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 5737130058129936372U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 1076627182956662997U;
            aOrbiterI = RotL64((aOrbiterI * 14342191224014199929U), 37U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterE, 47U);
            aIngress = aIngress + (RotL64(aOrbiterI, 3U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterK, 60U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aCross, 35U) + aOrbiterI) + RotL64(aOrbiterH, 23U)) + aNonceWordE);
            aWandererK = aWandererK + (((((RotL64(aScatter, 44U) + aOrbiterB) + RotL64(aOrbiterJ, 3U)) + RotL64(aCarry, 23U)) + aNonceWordK) + aWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 5U) + aOrbiterB) + RotL64(aOrbiterK, 11U)) + aNonceWordO);
            aWandererI = aWandererI + ((RotL64(aIngress, 57U) + RotL64(aOrbiterE, 30U)) + aOrbiterD);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 13U) + aOrbiterJ) + RotL64(aOrbiterE, 57U)) + aNonceWordD);
            aWandererG = aWandererG + (((RotL64(aPrevious, 21U) + aOrbiterK) + RotL64(aOrbiterI, 43U)) + RotL64(aCarry, 39U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 29U) + aOrbiterD) + RotL64(aOrbiterH, 37U)) + aWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + (RotL64(aWandererK, 18U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererG, 37U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 3
        // ingress from: aExpandLaneB, aWorkLaneA, aWorkLaneB, aOperationLaneA
        // ingress directions: aExpandLaneB forward forced, aWorkLaneA forward forced, aWorkLaneB forward forced, aOperationLaneA forward/backward random
        // cross from: aExpandLaneA, aWorkLaneC, aOperationLaneB
        // cross directions: aExpandLaneA backward forced, aWorkLaneC backward forced, aOperationLaneB backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 24480U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((aIndex + 18031U)) & S_BLOCK1], 52U));
            aIngress ^= (RotL64(aWorkLaneB[((aIndex + 19657U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 20022U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22669U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 22051U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 21782U)) & S_BLOCK1], 10U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 11U) + RotL64(aIngress, 37U)) ^ (RotL64(aCross, 24U) ^ RotL64(aPrevious, 51U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterA = ((((aWandererJ + RotL64(aScatter, 3U)) + RotL64(aCarry, 35U)) + 13924571355038625040U) + aOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1]) + aNonceWordP;
            aOrbiterE = (aWandererD + RotL64(aPrevious, 51U)) + 16328300979357156658U;
            aOrbiterK = (aWandererE + RotL64(aCross, 20U)) + 3947771961206012461U;
            aOrbiterI = (((aWandererF + RotL64(aIngress, 13U)) + RotL64(aCarry, 21U)) + 15428284250569311285U) + aNonceWordJ;
            aOrbiterH = ((aWandererH + RotL64(aCross, 35U)) + RotL64(aCarry, 47U)) + 5777369485254032486U;
            aOrbiterC = (((aWandererK + RotL64(aPrevious, 43U)) + 16813320300717644673U) + aOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1]) + aNonceWordL;
            aOrbiterG = (aWandererG + RotL64(aIngress, 57U)) + 16689933050200758251U;
            //
            aOrbiterA = (((aOrbiterA + aOrbiterE) + 1856422419049390708U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordB;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 18214498743831925517U) ^ aOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10744120577560529379U), 29U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterK) + 18278550878494094923U) + aOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1]) + aNonceWordG;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 797712062039591797U;
            aOrbiterI = RotL64((aOrbiterI * 7212998747080137625U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 15854849439012341347U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 996882939768167773U;
            aOrbiterE = RotL64((aOrbiterE * 14936703950807908575U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 3005829974130671692U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 8793495343509953906U;
            aOrbiterG = RotL64((aOrbiterG * 14065479348374612031U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 7710453029930631112U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 9511995836117707047U;
            aOrbiterC = RotL64((aOrbiterC * 7250766204781428201U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 670902975693341744U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 9045820304668279777U;
            aOrbiterH = RotL64((aOrbiterH * 18373074917532639027U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 12417212387607119470U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 12816983560669985622U;
            aOrbiterA = RotL64((aOrbiterA * 8406003970221889847U), 35U);
            //
            aIngress = RotL64(aOrbiterA, 35U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 41U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + RotL64(aOrbiterK, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aCross, 29U) + aOrbiterA) + RotL64(aOrbiterH, 11U)) + aNonceWordI) + aWandererUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterK, 29U)) + aOrbiterC);
            aWandererE = aWandererE + ((RotL64(aIngress, 3U) + RotL64(aOrbiterH, 37U)) + aOrbiterC);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterE, 53U)) + aOrbiterH);
            aWandererK = aWandererK + ((((RotL64(aIngress, 12U) + aOrbiterC) + RotL64(aOrbiterI, 23U)) + RotL64(aCarry, 51U)) + aWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterG, 43U)) + aOrbiterH);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 53U) + aOrbiterH) + RotL64(aOrbiterK, 4U)) + RotL64(aCarry, 13U)) + aNonceWordH);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererJ);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + RotL64(aWandererD, 6U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aWorkLaneD, aOperationLaneC
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aWorkLaneD forward forced, aOperationLaneC forward/backward random
        // cross from: aExpandLaneB, aWorkLaneB, aOperationLaneD
        // cross directions: aExpandLaneB backward forced, aWorkLaneB backward forced, aOperationLaneD backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 32459U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneA[((aIndex + 30457U)) & S_BLOCK1], 57U));
            aIngress ^= (RotL64(aWorkLaneD[((aIndex + 24802U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneC[((aIndex + 29823U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32002U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31115U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aOperationLaneD[((aIndex + 26660U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCross, 6U) + RotL64(aIngress, 39U)) + (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterG = (aWandererA + RotL64(aIngress, 51U)) + 15813325389431304548U;
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 43U)) + RotL64(aCarry, 39U)) + 2223874171125403602U;
            aOrbiterD = ((aWandererD + RotL64(aCross, 19U)) + RotL64(aCarry, 21U)) + 5510483568496824130U;
            aOrbiterE = ((aWandererI + RotL64(aScatter, 5U)) + 15474152493495661876U) + aOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = (((aWandererE + RotL64(aIngress, 11U)) + 16846339705130829195U) + aOrbiterAssignSaltE[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordO;
            aOrbiterA = ((aWandererG + RotL64(aCross, 58U)) + 1289670576865739669U) + aNonceWordK;
            aOrbiterK = (((aWandererH + RotL64(aScatter, 27U)) + RotL64(aCarry, 5U)) + 18017354919647006944U) + aNonceWordE;
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 8539685539928984921U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 3333721400836704048U) ^ aNonceWordC;
            aOrbiterD = RotL64((aOrbiterD * 3745286323481400085U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 2261560416623815491U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 4377786131746816567U) ^ aNonceWordA;
            aOrbiterA = RotL64((aOrbiterA * 9164777834392621157U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 18047393176583722719U) + aOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 8184724021940434631U;
            aOrbiterB = RotL64((aOrbiterB * 9800116157750921119U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 10469895939183324807U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 14543391765109879223U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4817987697437667225U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 5757225781746158178U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 3539000495894022869U) ^ aNonceWordP;
            aOrbiterG = RotL64((aOrbiterG * 1032298408884695925U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 11288971092707065923U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 2761384065186568294U;
            aOrbiterK = RotL64((aOrbiterK * 3323838837427471051U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 7120580145300417101U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 6977246291769372866U) ^ aOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15170353875184253779U), 21U);
            //
            aIngress = RotL64(aOrbiterH, 22U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterD, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterG, 51U)) + aOrbiterK) + RotL64(aCarry, 57U)) + aNonceWordI);
            aWandererE = aWandererE ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterH, 12U)) + aOrbiterE);
            aWandererB = aWandererB + (((RotL64(aIngress, 51U) + aOrbiterA) + RotL64(aOrbiterH, 21U)) + aNonceWordF);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 60U) + aOrbiterH) + RotL64(aOrbiterG, 43U)) + aNonceWordD);
            aWandererD = aWandererD + (((RotL64(aCross, 29U) + RotL64(aOrbiterB, 5U)) + aOrbiterD) + RotL64(aCarry, 37U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 21U) + aOrbiterA) + RotL64(aOrbiterE, 27U)) + aWandererUpdateSaltE[((aIndex + 6U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aIngress, 3U) + aOrbiterB) + RotL64(aOrbiterE, 57U)) + aNonceWordM) + aWandererUpdateSaltD[((aIndex + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 6U) ^ aWandererA);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererG, 39U);
            aCarry = aCarry + RotL64(aIngress, 28U);
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
    [[maybe_unused]] std::uint8_t *aWorkLaneC = pWorkSpace->mWorkLaneC;
    [[maybe_unused]] std::uint8_t *aWorkLaneD = pWorkSpace->mWorkLaneD;
    [[maybe_unused]] std::uint8_t *aFireLaneA = pWorkSpace->mFireLaneA;
    [[maybe_unused]] std::uint8_t *aFireLaneB = pWorkSpace->mFireLaneB;
    [[maybe_unused]] std::uint8_t *aFireLaneC = pWorkSpace->mFireLaneC;
    [[maybe_unused]] std::uint8_t *aFireLaneD = pWorkSpace->mFireLaneD;
    [[maybe_unused]] std::uint8_t *aKeyRowReadA = &(pWorkSpace->mKeyBoxA[H_KEY - 1][0]);
    [[maybe_unused]] std::uint8_t *aKeyRowReadB = &(pWorkSpace->mKeyBoxB[H_KEY - 1][0]);
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF;
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
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA;
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
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltD;
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
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltD;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xF4930E4C3CF4FD05ULL + 0xED84E3FA44C5D044ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xA17C96C4F701708DULL + 0xF1471324193E37E9ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xF7528A0B24F0FE55ULL + 0x908C770DA7FD2F59ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xD3A84C60991AA55DULL + 0x90EDA21A755769FAULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xB25D1ADBFF355EC3ULL + 0xD3A528B26D7DA674ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xC1979830FC1971BBULL + 0xD5FAD8D99C861244ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x9967D8CB05C3BDCBULL + 0xF7920115FE1B87B4ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xD809A66C6D4CF26FULL + 0xE9AC446449D777CDULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xCF2610524090C3ADULL + 0xC9803347B73EA356ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xC5179730C01CB443ULL + 0xDF7EC75393171727ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x9BB18596FEDC2F03ULL + 0xF2B560377F5555AEULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xF6732DEEF16FF0FFULL + 0xC7213C17163482D2ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xAB4C1E387159B0F5ULL + 0xFB7B91AD59B761A0ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xE35594F76DA3DDB7ULL + 0x90A5B2799F3377AEULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x83A0723F71862AFBULL + 0xFD38C2A8A717C823ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x8FD7B401CA614E2FULL + 0x96563B29EB94CA81ULL);
    // GSeedRunSeed_A seed_loop_a (start)
    {
        // GSeedRunSeed_A seed_loop_a lane group
        // read from: aKeyRowReadA, aKeyRowReadB, mSource, aFireLaneA, aFireLaneB, aFireLaneC, aFireLaneD, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC
        // write to: aFireLaneA, aFireLaneB, aFireLaneC, aFireLaneD, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_a loop 1
        // ingress from: aKeyRowReadA, aKeyRowReadB
        // ingress directions: aKeyRowReadA forward forced, aKeyRowReadB forward/backward random
        // cross from: aKeyRowReadA, mSource
        // cross directions: aKeyRowReadA backward forced, mSource backward/forward random
        // write to: aFireLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aKeyRowReadA[((aIndex + 918U)) & W_KEY1], 13U) ^ RotL64(aKeyRowReadB[((aIndex + 1550U)) & W_KEY1], 42U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 2312U)) & W_KEY1], 5U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 1779U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aPrevious, 52U)) + (RotL64(aIngress, 19U) ^ RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterC = (((aWandererF + RotL64(aCross, 13U)) + 15726877954695761686U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordH;
            aOrbiterJ = (aWandererG + RotL64(aIngress, 50U)) + 14187652171881943587U;
            aOrbiterK = (aWandererD + RotL64(aScatter, 37U)) + 8420423151313882782U;
            aOrbiterB = (((aWandererJ + RotL64(aPrevious, 5U)) + RotL64(aCarry, 27U)) + 14942322692433259283U) + aNonceWordF;
            aOrbiterA = (((aWandererH + RotL64(aIngress, 29U)) + RotL64(aCarry, 5U)) + 7272331475919796255U) + aNonceWordL;
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 43U)) + 154504365041805840U) + aPhaseEOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = ((aWandererE + RotL64(aScatter, 57U)) + RotL64(aCarry, 57U)) + 17475491222554948786U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 5759181483165339605U) + aNonceWordA;
            aOrbiterK = (((aOrbiterK ^ aOrbiterC) ^ 5993060214499322845U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterK = RotL64((aOrbiterK * 10799489831896153301U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 10901786237875941844U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 17135786595614068473U) ^ aNonceWordM;
            aOrbiterA = RotL64((aOrbiterA * 15923538730142047043U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 5208202073886811165U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 6821452921018900631U;
            aOrbiterI = RotL64((aOrbiterI * 13119330055184115669U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 13348064837402206969U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 8967943922403445136U;
            aOrbiterD = RotL64((aOrbiterD * 300168481725373093U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 8130283784171430891U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterA) ^ 6351113882502502876U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterC = RotL64((aOrbiterC * 15960622823993072903U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 6894708729226455769U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 12065058511247133944U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5432601727436935831U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 17138279326229372741U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 12987698199066890628U;
            aOrbiterB = RotL64((aOrbiterB * 12665716655177320977U), 5U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterI, 47U);
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + RotL64(aOrbiterJ, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterD, 60U)) + aOrbiterK) + aNonceWordO);
            aWandererH = aWandererH + (((RotL64(aCross, 37U) + aOrbiterD) + RotL64(aOrbiterJ, 21U)) + RotL64(aCarry, 3U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 13U) + aOrbiterJ) + RotL64(aOrbiterI, 29U));
            aWandererA = aWandererA + (((RotL64(aScatter, 21U) + aOrbiterD) + RotL64(aOrbiterB, 47U)) + aNonceWordC);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 60U) + RotL64(aOrbiterI, 11U)) + aOrbiterA) + aPhaseEWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 5U) + aOrbiterB) + RotL64(aOrbiterC, 3U)) + RotL64(aCarry, 41U));
            aWandererD = aWandererD ^ ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterJ, 39U)) + aOrbiterC) + aNonceWordN) + aPhaseEWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 44U));
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererF);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + RotL64(aWandererD, 37U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aFireLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 2
        // ingress from: aFireLaneA, aKeyRowReadA
        // ingress directions: aFireLaneA forward forced, aKeyRowReadA forward/backward random
        // cross from: aKeyRowReadB, mSource
        // cross directions: aKeyRowReadB backward forced, mSource backward/forward random
        // write to: aFireLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aFireLaneA[((aIndex + 5016U)) & S_BLOCK1], 43U) ^ RotL64(aKeyRowReadA[((aIndex + 2898U)) & W_KEY1], 30U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 5023U)) & W_KEY1], 37U) ^ RotL64(mSource[((aIndex + 4319U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aIngress, 5U)) + (RotL64(aCarry, 40U) ^ RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterJ = (aWandererH + RotL64(aScatter, 34U)) + 11698283336767769359U;
            aOrbiterA = (aWandererD + RotL64(aPrevious, 21U)) + 13297826354831483872U;
            aOrbiterE = ((aWandererI + RotL64(aIngress, 5U)) + 15254999058287530795U) + aNonceWordN;
            aOrbiterI = (((aWandererG + RotL64(aCross, 57U)) + RotL64(aCarry, 5U)) + 17474166585085346567U) + aPhaseEOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = (((aWandererA + RotL64(aIngress, 47U)) + RotL64(aCarry, 29U)) + 15684783498452840289U) + aPhaseEOrbiterAssignSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterK = (aWandererJ + RotL64(aScatter, 13U)) + 5061229733465216486U;
            aOrbiterF = (((aWandererE + RotL64(aPrevious, 41U)) + RotL64(aCarry, 57U)) + 15370981279168377944U) + aNonceWordE;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 17966672773619554092U) + aNonceWordB;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 14685092893994491068U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1627758964162892429U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 12798804186209406389U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 2848444181474221574U;
            aOrbiterA = RotL64((aOrbiterA * 13730480364920876877U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 8551142075919636146U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 8833198159158950723U;
            aOrbiterC = RotL64((aOrbiterC * 7650289040764974737U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 7351473160893666232U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 14204899612487622222U;
            aOrbiterI = RotL64((aOrbiterI * 6317485031956448029U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 7008985178526543258U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 13576796403863120356U) ^ aNonceWordC;
            aOrbiterF = RotL64((aOrbiterF * 13745839827679114077U), 53U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterI) + 5769784656937900699U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordI;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 14075925808204936705U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5844894088757604713U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 17818667502858010896U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 16016922065572683130U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7525645833898085373U), 47U);
            //
            aIngress = RotL64(aOrbiterC, 57U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 5U));
            aIngress = aIngress + (RotL64(aOrbiterK, 51U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterI, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aIngress, 29U) + RotL64(aOrbiterF, 47U)) + aOrbiterE) + aNonceWordP) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 60U) + aOrbiterA) + RotL64(aOrbiterI, 11U));
            aWandererE = aWandererE + (((RotL64(aCross, 13U) + aOrbiterJ) + RotL64(aOrbiterC, 20U)) + aPhaseEWandererUpdateSaltF[((aIndex + 20U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 47U) + aOrbiterK) + RotL64(aOrbiterJ, 5U));
            aWandererH = aWandererH + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterA, 57U)) + aOrbiterF) + RotL64(aCarry, 43U)) + aNonceWordD);
            aWandererG = aWandererG ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterK, 35U)) + aOrbiterE) + aNonceWordG);
            aWandererI = aWandererI + (((RotL64(aScatter, 5U) + aOrbiterI) + RotL64(aOrbiterF, 27U)) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 12U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 41U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + RotL64(aWandererA, 29U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aFireLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_a loop 3
        // ingress from: aFireLaneB, aKeyRowReadB
        // ingress directions: aFireLaneB forward forced, aKeyRowReadB forward/backward random
        // cross from: aKeyRowReadA, mSource, aFireLaneA
        // cross directions: aKeyRowReadA backward forced, mSource backward forced, aFireLaneA backward/forward random
        // write to: aFireLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aFireLaneB[((aIndex + 7579U)) & S_BLOCK1], 27U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 6969U)) & W_KEY1], 52U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 7265U)) & W_KEY1], 58U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 6004U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 6793U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCross, 5U)) ^ (RotL64(aCarry, 36U) + RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterG = ((aWandererI + RotL64(aCross, 27U)) + 4634399531433127141U) + aNonceWordD;
            aOrbiterK = (((aWandererF + RotL64(aIngress, 21U)) + RotL64(aCarry, 5U)) + 16961792729406903200U) + aNonceWordP;
            aOrbiterH = (aWandererD + RotL64(aPrevious, 11U)) + 4105280732301137738U;
            aOrbiterE = ((((aWandererK + RotL64(aScatter, 47U)) + RotL64(aCarry, 57U)) + 15692013501147331191U) + aPhaseEOrbiterAssignSaltD[((aIndex + 20U)) & S_SALT1]) + aNonceWordH;
            aOrbiterI = (((aWandererE + RotL64(aCross, 5U)) + RotL64(aCarry, 35U)) + 1252216715968780587U) + aPhaseEOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = ((aWandererG + RotL64(aIngress, 54U)) + 7958289043012473752U) + aNonceWordK;
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 35U)) + 6611577301818896615U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 8506226754305949140U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 3648813120449403353U;
            aOrbiterH = RotL64((aOrbiterH * 9521367946879238849U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 5195245426245535735U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 542948051600803051U;
            aOrbiterE = RotL64((aOrbiterE * 4631106308856448475U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 11974253551208964789U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 10596463592332655367U) ^ aNonceWordN;
            aOrbiterC = RotL64((aOrbiterC * 10941161258815714641U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 12015129484061440159U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 8254944355710109060U;
            aOrbiterJ = RotL64((aOrbiterJ * 3233697992479357615U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 2754858806943915419U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = (((aOrbiterK ^ aOrbiterJ) ^ 5007802002906662779U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterK = RotL64((aOrbiterK * 15613733948331639723U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 6262190752136523216U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 10528977986487821428U) ^ aNonceWordC;
            aOrbiterI = RotL64((aOrbiterI * 1184258264034585525U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 8511097226098211854U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 12091864735686692582U;
            aOrbiterG = RotL64((aOrbiterG * 6128140528141411237U), 29U);
            //
            aIngress = RotL64(aOrbiterK, 13U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 51U));
            aIngress = aIngress + RotL64(aOrbiterH, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aPrevious, 37U) + RotL64(aOrbiterE, 19U)) + aOrbiterI);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 6U) + RotL64(aOrbiterJ, 11U)) + aOrbiterK) + aNonceWordI);
            aWandererI = aWandererI + ((((RotL64(aScatter, 13U) + aOrbiterK) + RotL64(aOrbiterC, 43U)) + RotL64(aCarry, 23U)) + aNonceWordE);
            aWandererD = aWandererD ^ ((((RotL64(aCross, 43U) + aOrbiterG) + RotL64(aOrbiterJ, 29U)) + aNonceWordF) + aPhaseEWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 23U) + aOrbiterH) + RotL64(aOrbiterE, 60U)) + RotL64(aCarry, 39U)) + aNonceWordO);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterG, 51U)) + aOrbiterH);
            aWandererK = aWandererK + (((RotL64(aCross, 51U) + aOrbiterK) + RotL64(aOrbiterH, 3U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + (RotL64(aWandererD, 22U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererE, 51U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aFireLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 4
        // ingress from: aFireLaneC, aKeyRowReadB, mSource, aFireLaneA
        // ingress directions: aFireLaneC forward forced, aKeyRowReadB forward forced, mSource forward forced, aFireLaneA forward/backward random
        // cross from: aKeyRowReadA, aFireLaneB
        // cross directions: aKeyRowReadA backward forced, aFireLaneB backward/forward random
        // write to: aFireLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aFireLaneC[((aIndex + 10513U)) & S_BLOCK1], 47U) ^ RotL64(aKeyRowReadB[((aIndex + 9815U)) & W_KEY1], 27U));
            aIngress ^= (RotL64(mSource[((aIndex + 9394U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 9935U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 10519U)) & W_KEY1], 53U) ^ RotL64(aFireLaneB[((aIndex + 8922U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aPrevious, 30U) ^ RotL64(aCarry, 13U)) + (RotL64(aIngress, 43U) ^ RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterC = (((aWandererG + RotL64(aPrevious, 41U)) + RotL64(aCarry, 57U)) + 1210605127156905516U) + aNonceWordP;
            aOrbiterG = ((aWandererA + RotL64(aIngress, 13U)) + RotL64(aCarry, 13U)) + 11964595428173569519U;
            aOrbiterD = (((aWandererI + RotL64(aCross, 35U)) + 16277319029916258482U) + aPhaseFOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1]) + aNonceWordG;
            aOrbiterB = (aWandererD + RotL64(aScatter, 5U)) + 12369497463101824572U;
            aOrbiterE = (aWandererH + RotL64(aIngress, 57U)) + 6201248574067068202U;
            aOrbiterF = (((aWandererF + RotL64(aCross, 23U)) + RotL64(aCarry, 27U)) + 1727477025667206661U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = (aWandererC + RotL64(aScatter, 50U)) + 1404510627789806851U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 6948213591282018925U) + aNonceWordO;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 6688865181284421478U;
            aOrbiterD = RotL64((aOrbiterD * 12619122841662247279U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 3351130769402360855U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 12681032488906270823U;
            aOrbiterF = RotL64((aOrbiterF * 3680893896579741263U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 3591412591193726763U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 16153817571210878589U;
            aOrbiterG = RotL64((aOrbiterG * 4165137036092246349U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 3808228354421006630U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 1427373776207504205U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4534374093769595531U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 1831554180932501132U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 1114853085120949215U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4264176108298812905U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 2080935638828366835U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 16104777999646489828U) ^ aNonceWordK;
            aOrbiterE = RotL64((aOrbiterE * 15205199362011777473U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 9782806013673440791U) + aNonceWordI;
            aOrbiterK = (((aOrbiterK ^ aOrbiterE) ^ 3721620299829386454U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterK = RotL64((aOrbiterK * 6286765834910272409U), 57U);
            //
            aIngress = RotL64(aOrbiterG, 50U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterF, 57U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 43U));
            aIngress = aIngress + RotL64(aOrbiterE, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aCross, 34U) + aOrbiterG) + RotL64(aOrbiterE, 53U)) + aNonceWordN);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 19U) + aOrbiterG) + RotL64(aOrbiterB, 27U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 5U) + aOrbiterB) + RotL64(aOrbiterD, 11U)) + RotL64(aCarry, 29U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 41U) + aOrbiterK) + RotL64(aOrbiterE, 21U)) + aNonceWordE);
            aWandererF = aWandererF + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterK, 41U)) + aOrbiterC) + RotL64(aCarry, 51U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 53U) + aOrbiterD) + RotL64(aOrbiterC, 60U));
            aWandererH = aWandererH + (((RotL64(aScatter, 13U) + RotL64(aOrbiterK, 47U)) + aOrbiterF) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 37U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 4U));
            aCarry = aCarry + RotL64(aWandererA, 19U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aFireLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_a loop 5
        // ingress from: aFireLaneD, aKeyRowReadA, aKeyRowReadB, mSource, aFireLaneB
        // ingress directions: aFireLaneD forward forced, aKeyRowReadA forward forced, aKeyRowReadB forward forced, mSource forward forced, aFireLaneB forward/backward random
        // cross from: aFireLaneA, aFireLaneC
        // cross directions: aFireLaneA backward forced, aFireLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aFireLaneD[((aIndex + 10940U)) & S_BLOCK1], 37U) ^ RotL64(aKeyRowReadA[((aIndex + 11497U)) & W_KEY1], 27U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 10972U)) & W_KEY1], 57U) ^ RotL64(mSource[((aIndex + 12642U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 11860U)) & S_BLOCK1], 46U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 12462U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 11928U)) & S_BLOCK1], 18U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aIngress, 11U) + RotL64(aCarry, 39U)) + (RotL64(aCross, 51U) ^ RotL64(aPrevious, 24U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterA = ((aWandererD + RotL64(aCross, 13U)) + 6654158889644956636U) + aPhaseFOrbiterAssignSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterG = (((aWandererB + RotL64(aScatter, 3U)) + RotL64(aCarry, 43U)) + 9045779659363991870U) + aNonceWordG;
            aOrbiterB = (((aWandererA + RotL64(aPrevious, 29U)) + RotL64(aCarry, 57U)) + 3888897662136993491U) + aPhaseFOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = (((aWandererI + RotL64(aIngress, 47U)) + RotL64(aCarry, 23U)) + 6882016842864459345U) + aNonceWordB;
            aOrbiterF = ((aWandererC + RotL64(aScatter, 57U)) + 15601891715956172291U) + aNonceWordH;
            aOrbiterD = (aWandererF + RotL64(aPrevious, 41U)) + 5176811598629335350U;
            aOrbiterC = ((aWandererH + RotL64(aCross, 22U)) + 12519945150889074325U) + aNonceWordF;
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 4552583214397603278U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 14225482701804864688U;
            aOrbiterB = RotL64((aOrbiterB * 8526052833180466359U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 5485298070606280363U) + aNonceWordP;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 11237713257388094289U;
            aOrbiterF = RotL64((aOrbiterF * 11032429223099413011U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 14340345895626142788U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 16275167270553643347U;
            aOrbiterD = RotL64((aOrbiterD * 7308578867128951199U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 14041860597556520250U) + aNonceWordM;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 1436068974197066343U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3938460345031496843U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 11483155566419547004U) + aNonceWordA;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 4608508534724289325U;
            aOrbiterH = RotL64((aOrbiterH * 13461385011638899485U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 2389196334288832895U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 4062682330273866602U;
            aOrbiterG = RotL64((aOrbiterG * 8787682133271101901U), 57U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterB) + 5655656046585592034U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordE;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 7977947821249746880U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10082104644185964787U), 13U);
            //
            aIngress = RotL64(aOrbiterD, 11U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterC, 19U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterB, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((((RotL64(aScatter, 5U) + RotL64(aOrbiterD, 21U)) + aOrbiterC) + RotL64(aCarry, 5U)) + aNonceWordD) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 19U) + aOrbiterC) + RotL64(aOrbiterG, 41U));
            aWandererH = aWandererH + ((((RotL64(aCross, 51U) + RotL64(aOrbiterC, 13U)) + aOrbiterH) + RotL64(aCarry, 19U)) + aPhaseFWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterB, 5U)) + aOrbiterH) + aNonceWordO);
            aWandererF = aWandererF + (((RotL64(aPrevious, 27U) + aOrbiterF) + RotL64(aOrbiterG, 51U)) + aNonceWordJ);
            aWandererA = aWandererA ^ ((RotL64(aCross, 39U) + aOrbiterF) + RotL64(aOrbiterC, 35U));
            aWandererB = aWandererB + (((RotL64(aIngress, 12U) + RotL64(aOrbiterF, 28U)) + aOrbiterA) + aNonceWordN);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + (RotL64(aWandererD, 26U) ^ aWandererI);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + RotL64(aWandererH, 35U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 6
        // ingress from: aWorkLaneA, aFireLaneC
        // ingress directions: aWorkLaneA forward forced, aFireLaneC forward/backward random
        // cross from: aKeyRowReadA, aKeyRowReadB, mSource, aFireLaneB, aFireLaneA
        // cross directions: aKeyRowReadA backward forced, aKeyRowReadB backward forced, mSource backward forced, aFireLaneB backward forced, aFireLaneA backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aWorkLaneA[((aIndex + 15028U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneC[((aIndex + 13985U)) & S_BLOCK1], 46U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 13792U)) & W_KEY1], 39U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 15768U)) & W_KEY1], 60U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 15113U)) & S_BLOCK1], 21U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 14503U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 14515U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aPrevious, 40U) + RotL64(aCross, 53U)) + (RotL64(aIngress, 3U) ^ RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterC = (((aWandererC + RotL64(aIngress, 13U)) + RotL64(aCarry, 19U)) + 8101351470141807662U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 43U)) + RotL64(aCarry, 43U)) + 6965474099521076705U;
            aOrbiterI = (((aWandererE + RotL64(aScatter, 3U)) + 6803828268885684784U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordB;
            aOrbiterH = ((aWandererF + RotL64(aCross, 21U)) + RotL64(aCarry, 57U)) + 13454235922950972488U;
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 51U)) + 11678091885751244777U) + aNonceWordD;
            aOrbiterE = (aWandererB + RotL64(aScatter, 27U)) + 5307134544628507141U;
            aOrbiterG = ((aWandererK + RotL64(aCross, 34U)) + 4873703518950429353U) + aNonceWordK;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 8542156221858586039U) + aNonceWordA;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 3993726182905296513U;
            aOrbiterI = RotL64((aOrbiterI * 11331376012938127609U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 12113047622035464386U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 1944244448665721151U;
            aOrbiterD = RotL64((aOrbiterD * 7010050836758762003U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 12914188029425467576U) + aNonceWordJ;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 2486762763475327024U;
            aOrbiterE = RotL64((aOrbiterE * 12319769994433811617U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 14580191602982245481U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 12093414832400135066U;
            aOrbiterG = RotL64((aOrbiterG * 12720286833215690663U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 13623906997320021065U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 9977356009806428696U;
            aOrbiterC = RotL64((aOrbiterC * 2005536391712733499U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 3694954095397810851U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 11453812627797091638U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13730420725113907161U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 542311345544726351U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 3024285045990499484U) ^ aNonceWordH;
            aOrbiterB = RotL64((aOrbiterB * 5153745952148205645U), 13U);
            //
            aIngress = RotL64(aOrbiterH, 41U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 3U));
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterC, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterB, 5U)) + aOrbiterH);
            aWandererE = aWandererE ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterH, 43U)) + aOrbiterI) + aNonceWordL);
            aWandererK = aWandererK + ((((RotL64(aIngress, 56U) + aOrbiterB) + RotL64(aOrbiterG, 11U)) + RotL64(aCarry, 51U)) + aPhaseFWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterD, 35U)) + aOrbiterH) + aNonceWordG);
            aWandererC = aWandererC + ((((RotL64(aCross, 47U) + aOrbiterD) + RotL64(aOrbiterE, 51U)) + RotL64(aCarry, 13U)) + aNonceWordF);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterC, 57U)) + aOrbiterE) + aPhaseFWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 41U) + RotL64(aOrbiterH, 22U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + (RotL64(aWandererC, 12U) ^ aWandererF);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + RotL64(aWandererB, 43U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_a loop 7
        // ingress from: aWorkLaneB, aKeyRowReadA, mSource, aFireLaneA
        // ingress directions: aWorkLaneB forward forced, aKeyRowReadA forward forced, mSource forward forced, aFireLaneA forward/backward random
        // cross from: aKeyRowReadB, aFireLaneD, aWorkLaneA
        // cross directions: aKeyRowReadB backward forced, aFireLaneD backward forced, aWorkLaneA backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 18152U)) & S_BLOCK1], 56U) ^ RotL64(aKeyRowReadA[((aIndex + 16590U)) & W_KEY1], 5U));
            aIngress ^= (RotL64(mSource[((aIndex + 18587U)) & S_BLOCK1], 23U) ^ RotL64(aFireLaneA[((aIndex + 18313U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 18973U)) & W_KEY1], 37U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 17474U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 16613U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 56U) + RotL64(aCross, 27U)) ^ (RotL64(aCarry, 41U) + RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterE = (((aWandererC + RotL64(aIngress, 53U)) + RotL64(aCarry, 53U)) + 2168513956284366370U) + aNonceWordL;
            aOrbiterC = (aWandererH + RotL64(aCross, 47U)) + 10290361969974613111U;
            aOrbiterH = ((aWandererK + RotL64(aScatter, 27U)) + RotL64(aCarry, 11U)) + 15673836275828498050U;
            aOrbiterJ = (((aWandererI + RotL64(aPrevious, 19U)) + RotL64(aCarry, 37U)) + 16600540024145812236U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = ((aWandererE + RotL64(aIngress, 60U)) + 9428052101528111892U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = (aWandererB + RotL64(aScatter, 41U)) + 12763657928312763377U;
            aOrbiterG = ((aWandererF + RotL64(aCross, 35U)) + 10751286982008662485U) + aNonceWordN;
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 1708230173038057979U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 4011389705422783816U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11692237130784795961U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 11704428328093077714U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 2055336619674699284U;
            aOrbiterK = RotL64((aOrbiterK * 6374289210096410907U), 3U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterH) + 1870865272102705804U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1]) + aNonceWordM;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 3574214263751923179U;
            aOrbiterB = RotL64((aOrbiterB * 13132083406834413563U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 984611970726966186U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 15207945449947643672U;
            aOrbiterE = RotL64((aOrbiterE * 9539470161576639981U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 4181398506373973169U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 15222345431506025949U;
            aOrbiterG = RotL64((aOrbiterG * 6925143692628659467U), 47U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterK) + 15023513452326240962U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordH;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 14965669361708810699U) ^ aNonceWordK;
            aOrbiterC = RotL64((aOrbiterC * 587008860996713147U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 7985755518735406360U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterC) ^ 225592097619240187U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterJ = RotL64((aOrbiterJ * 2313509354133400439U), 29U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterE, 41U);
            aIngress = aIngress + (RotL64(aOrbiterG, 23U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 35U));
            aIngress = aIngress + RotL64(aOrbiterB, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aScatter, 60U) + aOrbiterJ) + RotL64(aOrbiterH, 11U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 41U) + aOrbiterC) + RotL64(aOrbiterE, 41U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 5U) + aOrbiterK) + RotL64(aOrbiterJ, 29U)) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aCross, 19U) + aOrbiterJ) + RotL64(aOrbiterE, 53U)) + RotL64(aCarry, 13U)) + aNonceWordP);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 13U) + aOrbiterG) + RotL64(aOrbiterK, 19U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 47U) + aOrbiterB) + RotL64(aOrbiterK, 60U)) + RotL64(aCarry, 37U));
            aWandererB = aWandererB ^ ((((RotL64(aScatter, 29U) + RotL64(aOrbiterC, 3U)) + aOrbiterG) + aNonceWordG) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + (RotL64(aWandererI, 30U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 39U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 8
        // ingress from: aWorkLaneC, mSource, aWorkLaneA, aFireLaneA
        // ingress directions: aWorkLaneC forward forced, mSource forward forced, aWorkLaneA forward forced, aFireLaneA forward/backward random
        // cross from: aKeyRowReadA, aKeyRowReadB, aWorkLaneB, aFireLaneB
        // cross directions: aKeyRowReadA backward forced, aKeyRowReadB backward forced, aWorkLaneB backward forced, aFireLaneB backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 20042U)) & S_BLOCK1], 11U) ^ RotL64(mSource[((aIndex + 21166U)) & S_BLOCK1], 51U));
            aIngress ^= (RotL64(aWorkLaneA[((aIndex + 21632U)) & S_BLOCK1], 21U) ^ RotL64(aFireLaneA[((aIndex + 20422U)) & S_BLOCK1], 30U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 19344U)) & W_KEY1], 50U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 19686U)) & W_KEY1], 23U));
            aCross ^= (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20942U)) & S_BLOCK1], 39U) ^ RotL64(aFireLaneB[((aIndex + 20506U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 37U) ^ RotL64(aCarry, 5U)) ^ (RotL64(aCross, 24U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterF = ((aWandererK + RotL64(aScatter, 41U)) + RotL64(aCarry, 21U)) + 8866844335448071821U;
            aOrbiterH = (((aWandererI + RotL64(aPrevious, 27U)) + 15159698739856430085U) + aPhaseGOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1]) + aNonceWordK;
            aOrbiterA = ((aWandererF + RotL64(aIngress, 53U)) + 9582805772989594633U) + aNonceWordI;
            aOrbiterC = (((aWandererJ + RotL64(aCross, 60U)) + RotL64(aCarry, 57U)) + 1438538239931588373U) + aPhaseGOrbiterAssignSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = ((aWandererC + RotL64(aIngress, 11U)) + RotL64(aCarry, 37U)) + 10862044156620436139U;
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 5U)) + 13682173320058164615U) + aNonceWordP;
            aOrbiterB = ((aWandererD + RotL64(aCross, 47U)) + 8351013291045977592U) + aNonceWordL;
            //
            aOrbiterF = (((aOrbiterF + aOrbiterH) + 15777857431516633916U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1]) + aNonceWordG;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 16178966745333885377U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7545129923202147703U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 9031889187993001617U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 6308472367425865347U;
            aOrbiterE = RotL64((aOrbiterE * 17118710301967158153U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 642109145903321046U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 9186268569255318035U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10714674348507516749U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 6091345356803675860U) + aNonceWordH;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 13218507921880873749U;
            aOrbiterC = RotL64((aOrbiterC * 15415157927185637717U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 4266652275234474616U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 4391422098164506195U;
            aOrbiterF = RotL64((aOrbiterF * 17634679403195085867U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 5160682323243635577U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 10351728852161347404U;
            aOrbiterB = RotL64((aOrbiterB * 11105410036471745951U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 3950932176454814023U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 9536466386833427441U;
            aOrbiterH = RotL64((aOrbiterH * 18064984243491293435U), 11U);
            //
            aIngress = RotL64(aOrbiterF, 19U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 39U));
            aIngress = aIngress + (RotL64(aOrbiterG, 46U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterE, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 60U) + aOrbiterH) + RotL64(aOrbiterG, 37U));
            aWandererF = aWandererF + ((((RotL64(aCross, 41U) + RotL64(aOrbiterF, 54U)) + aOrbiterH) + RotL64(aCarry, 57U)) + aPhaseGWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterA, 27U)) + aOrbiterC);
            aWandererD = aWandererD + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterC, 47U)) + aOrbiterE) + aNonceWordD);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterH, 5U)) + aOrbiterE) + aNonceWordA);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterB, 19U)) + aOrbiterF) + RotL64(aCarry, 41U)) + aNonceWordO);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterF, 13U)) + aOrbiterC) + aPhaseGWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 34U));
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererK);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + RotL64(aWandererJ, 41U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_a loop 9
        // ingress from: aWorkLaneD, aKeyRowReadA, aKeyRowReadB, aWorkLaneC
        // ingress directions: aWorkLaneD forward forced, aKeyRowReadA forward forced, aKeyRowReadB forward forced, aWorkLaneC forward/backward random
        // cross from: mSource, aWorkLaneA, aFireLaneC, aFireLaneD
        // cross directions: mSource backward forced, aWorkLaneA backward forced, aFireLaneC backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneD[((aIndex + 21892U)) & S_BLOCK1], 19U) ^ RotL64(aKeyRowReadA[((aIndex + 23146U)) & W_KEY1], 5U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 21973U)) & W_KEY1], 27U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 22610U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 22102U)) & S_BLOCK1], 14U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22769U)) & S_BLOCK1], 57U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 23570U)) & S_BLOCK1], 47U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 23380U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 10U) ^ RotL64(aCross, 43U)) ^ (RotL64(aCarry, 57U) + RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterA = ((aWandererH + RotL64(aScatter, 43U)) + 4980738603982643969U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = (((aWandererK + RotL64(aIngress, 13U)) + RotL64(aCarry, 51U)) + 17660278413018470020U) + aNonceWordA;
            aOrbiterH = (((aWandererB + RotL64(aCross, 57U)) + RotL64(aCarry, 23U)) + 17598114429859543466U) + aNonceWordO;
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 51U)) + 10993929335279994739U) + aPhaseGOrbiterAssignSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = ((aWandererI + RotL64(aCross, 37U)) + 17967203122976322481U) + aNonceWordE;
            aOrbiterF = (aWandererF + RotL64(aIngress, 26U)) + 1872290205549034384U;
            aOrbiterC = (((aWandererC + RotL64(aPrevious, 19U)) + RotL64(aCarry, 37U)) + 16607778671782810797U) + aNonceWordD;
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 4895226930754394376U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 14960359005982301383U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8546231310054433721U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 9921642352377700630U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 893281964367208693U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2345509157333444217U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 8232519988397858732U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 4433022122758913407U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 834240393225479419U), 51U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterC) + 12689609831247168353U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1]) + aNonceWordL;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 404535388957472176U) ^ aNonceWordG;
            aOrbiterA = RotL64((aOrbiterA * 14534020545479806593U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 3349108201964013155U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 4386449511297371730U;
            aOrbiterI = RotL64((aOrbiterI * 9596273264321140229U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 14314587717949070586U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 10923886625271054985U;
            aOrbiterK = RotL64((aOrbiterK * 7838969002623486809U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 17634909585329833520U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 2021301459918350372U;
            aOrbiterD = RotL64((aOrbiterD * 1388242915918642741U), 5U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterC, 29U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 37U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + RotL64(aOrbiterH, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((((RotL64(aScatter, 51U) + aOrbiterH) + RotL64(aOrbiterI, 57U)) + aNonceWordI) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 21U) + RotL64(aOrbiterD, 35U)) + aOrbiterH) + RotL64(aCarry, 51U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 3U) + aOrbiterH) + RotL64(aOrbiterA, 44U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 37U) + RotL64(aOrbiterF, 51U)) + aOrbiterI);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterC, 29U)) + aOrbiterA);
            aWandererC = aWandererC + (((RotL64(aPrevious, 57U) + aOrbiterA) + RotL64(aOrbiterK, 3U)) + RotL64(aCarry, 19U));
            aWandererF = aWandererF ^ ((((RotL64(aCross, 28U) + RotL64(aOrbiterF, 13U)) + aOrbiterD) + aNonceWordB) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 12U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + RotL64(aWandererC, 57U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 10
        // ingress from: aExpandLaneA, aKeyRowReadA, aWorkLaneD, aWorkLaneB
        // ingress directions: aExpandLaneA forward forced, aKeyRowReadA forward forced, aWorkLaneD forward forced, aWorkLaneB forward/backward random
        // cross from: aKeyRowReadB, mSource, aWorkLaneC, aFireLaneD
        // cross directions: aKeyRowReadB backward forced, mSource backward forced, aWorkLaneC backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 26338U)) & S_BLOCK1], 13U) ^ RotL64(aKeyRowReadA[((aIndex + 26731U)) & W_KEY1], 26U));
            aIngress ^= (RotL64(aWorkLaneD[((aIndex + 24637U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((aIndex + 25921U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 25216U)) & W_KEY1], 58U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 26668U)) & S_BLOCK1], 19U));
            aCross ^= (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 24892U)) & S_BLOCK1], 37U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 25231U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCarry, 26U) + RotL64(aPrevious, 5U)) ^ (RotL64(aIngress, 41U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterI = ((((aWandererC + RotL64(aScatter, 57U)) + RotL64(aCarry, 37U)) + 9041099828460168106U) + aPhaseHOrbiterAssignSaltA[((aIndex + 24U)) & S_SALT1]) + aNonceWordM;
            aOrbiterK = (aWandererA + RotL64(aPrevious, 47U)) + 12883711604096848454U;
            aOrbiterA = (((aWandererB + RotL64(aCross, 5U)) + RotL64(aCarry, 19U)) + 17420968786226443079U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = ((aWandererG + RotL64(aIngress, 11U)) + 3448213891716125104U) + aNonceWordA;
            aOrbiterC = (aWandererE + RotL64(aCross, 35U)) + 11866455977445336560U;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 28U)) + RotL64(aCarry, 5U)) + 4119356835384495905U;
            aOrbiterH = (aWandererD + RotL64(aPrevious, 41U)) + 2186212599698637068U;
            //
            aOrbiterI = (((aOrbiterI + aOrbiterK) + 6506144898969301620U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1]) + aNonceWordE;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 12556800923644051626U;
            aOrbiterA = RotL64((aOrbiterA * 15961043406612913121U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 4075551535185182945U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 17877694808492008749U;
            aOrbiterK = RotL64((aOrbiterK * 901315308379887473U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 5553428900598223316U) + aNonceWordO;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 14362304852277160675U;
            aOrbiterH = RotL64((aOrbiterH * 11415103199856419303U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 9174200302876075831U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 16110739511917638547U;
            aOrbiterF = RotL64((aOrbiterF * 7004356839428657949U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 10189881974519849402U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 2128076632642616677U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8860453653433114929U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 18133523799074400083U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 9916472958834153766U;
            aOrbiterD = RotL64((aOrbiterD * 3454601168808001733U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 10274457562795569227U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 14134814273275356425U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15912501063665343159U), 19U);
            //
            aIngress = RotL64(aOrbiterH, 10U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterD, 35U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterA, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterF, 57U)) + aOrbiterA);
            aWandererC = aWandererC + (((RotL64(aIngress, 11U) + RotL64(aOrbiterI, 51U)) + aOrbiterA) + aNonceWordJ);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterH, 19U)) + aOrbiterC) + aNonceWordN);
            aWandererA = aWandererA + (((RotL64(aCross, 35U) + RotL64(aOrbiterA, 30U)) + aOrbiterK) + RotL64(aCarry, 5U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterK, 13U)) + aOrbiterC) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 41U) + aOrbiterD) + RotL64(aOrbiterH, 5U)) + RotL64(aCarry, 47U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 50U) + aOrbiterH) + RotL64(aOrbiterI, 43U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 46U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererG, 41U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererB, 23U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_a loop 11
        // ingress from: aExpandLaneB, aWorkLaneD, aKeyRowReadB, aWorkLaneC
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aKeyRowReadB forward forced, aWorkLaneC forward/backward random
        // cross from: aKeyRowReadA, mSource, aExpandLaneA, aWorkLaneB
        // cross directions: aKeyRowReadA backward forced, mSource backward forced, aExpandLaneA backward forced, aWorkLaneB backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 29880U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneD[((aIndex + 29881U)) & S_BLOCK1], 13U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 27514U)) & W_KEY1], 3U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 29756U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 28034U)) & W_KEY1], 18U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 28942U)) & S_BLOCK1], 47U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28186U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29302U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aIngress, 50U) ^ RotL64(aCarry, 19U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterA = ((aWandererE + RotL64(aIngress, 53U)) + RotL64(aCarry, 29U)) + 785861751704720606U;
            aOrbiterI = ((aWandererF + RotL64(aCross, 37U)) + 15968088718435606299U) + aNonceWordK;
            aOrbiterG = (aWandererI + RotL64(aPrevious, 19U)) + 1393976526590347151U;
            aOrbiterH = (((aWandererB + RotL64(aScatter, 13U)) + 17240750947292745884U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordG;
            aOrbiterC = ((((aWandererD + RotL64(aPrevious, 4U)) + RotL64(aCarry, 57U)) + 4921576136163183137U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordM;
            aOrbiterB = (((aWandererA + RotL64(aScatter, 27U)) + RotL64(aCarry, 13U)) + 3334047873553153032U) + aNonceWordP;
            aOrbiterD = (aWandererH + RotL64(aCross, 43U)) + 15086509978458408698U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 892391205397581998U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 2965686403183767521U;
            aOrbiterG = RotL64((aOrbiterG * 709160942482770225U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 14632215393655706170U) + aNonceWordH;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 15740589515342377322U;
            aOrbiterA = RotL64((aOrbiterA * 15677716942904794913U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 11131164813943086445U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 6988080581278900960U;
            aOrbiterB = RotL64((aOrbiterB * 6412189142344044255U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 16021254613117657178U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 6183615599897921154U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9976411093264211033U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 12533992547026652747U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 3104325358982904219U) ^ aNonceWordB;
            aOrbiterC = RotL64((aOrbiterC * 14977348108778147265U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 3878525937957474644U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 2120435259884368445U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15964718652193073177U), 11U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterA) + 14928658302694194856U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordE;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 9121310461310309348U;
            aOrbiterD = RotL64((aOrbiterD * 17304439784647477491U), 21U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterA, 51U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 11U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 23U));
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aIngress, 47U) + aOrbiterC) + RotL64(aOrbiterI, 5U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterD, 57U)) + aOrbiterA) + aPhaseHWandererUpdateSaltB[((aIndex + 18U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 29U) + RotL64(aOrbiterD, 50U)) + aOrbiterC) + RotL64(aCarry, 51U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 11U) + aOrbiterG) + RotL64(aOrbiterH, 11U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 53U) + RotL64(aOrbiterB, 41U)) + aOrbiterC) + aNonceWordO);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterH, 21U)) + aOrbiterA) + aNonceWordA);
            aWandererE = aWandererE + (((RotL64(aScatter, 40U) + RotL64(aOrbiterH, 29U)) + aOrbiterC) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + (RotL64(aWandererE, 30U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererD, 23U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 12
        // ingress from: aExpandLaneC, aKeyRowReadA
        // ingress directions: aExpandLaneC forward forced, aKeyRowReadA forward/backward random
        // cross from: aWorkLaneD, aExpandLaneA, aExpandLaneB, aKeyRowReadB
        // cross directions: aWorkLaneD backward forced, aExpandLaneA backward forced, aExpandLaneB backward forced, aKeyRowReadB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aExpandLaneC[((aIndex + 30474U)) & S_BLOCK1], 60U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 30504U)) & W_KEY1], 51U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 30516U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32391U)) & S_BLOCK1], 3U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30903U)) & S_BLOCK1], 11U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 32062U)) & W_KEY1], 42U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aPrevious, 56U)) + (RotL64(aCarry, 5U) ^ RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterK = ((aWandererB + RotL64(aScatter, 11U)) + 13924571355038625040U) + aNonceWordG;
            aOrbiterI = (((aWandererK + RotL64(aIngress, 60U)) + RotL64(aCarry, 35U)) + 16328300979357156658U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = (((aWandererG + RotL64(aCross, 47U)) + RotL64(aCarry, 53U)) + 3947771961206012461U) + aNonceWordA;
            aOrbiterC = (aWandererC + RotL64(aPrevious, 21U)) + 15428284250569311285U;
            aOrbiterB = (((aWandererA + RotL64(aScatter, 35U)) + RotL64(aCarry, 13U)) + 5777369485254032486U) + aNonceWordC;
            aOrbiterG = ((aWandererF + RotL64(aIngress, 3U)) + 16813320300717644673U) + aPhaseHOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = (aWandererI + RotL64(aPrevious, 27U)) + 16689933050200758251U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 1856422419049390708U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 18214498743831925517U;
            aOrbiterD = RotL64((aOrbiterD * 10744120577560529379U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 18278550878494094923U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 797712062039591797U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7212998747080137625U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 15854849439012341347U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 996882939768167773U) ^ aNonceWordM;
            aOrbiterG = RotL64((aOrbiterG * 14936703950807908575U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 3005829974130671692U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 8793495343509953906U) ^ aNonceWordB;
            aOrbiterH = RotL64((aOrbiterH * 14065479348374612031U), 57U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterG) + 7710453029930631112U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 9511995836117707047U;
            aOrbiterI = RotL64((aOrbiterI * 7250766204781428201U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 670902975693341744U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 9045820304668279777U;
            aOrbiterK = RotL64((aOrbiterK * 18373074917532639027U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 12417212387607119470U) + aNonceWordP;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 12816983560669985622U;
            aOrbiterC = RotL64((aOrbiterC * 8406003970221889847U), 3U);
            //
            aIngress = RotL64(aOrbiterK, 21U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 27U));
            aIngress = aIngress + (RotL64(aOrbiterC, 35U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aScatter, 35U) + aOrbiterC) + RotL64(aOrbiterG, 48U)) + RotL64(aCarry, 47U));
            aWandererK = aWandererK ^ ((((RotL64(aCross, 58U) + RotL64(aOrbiterG, 23U)) + aOrbiterH) + aNonceWordO) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 51U) + RotL64(aOrbiterH, 37U)) + aOrbiterD) + aNonceWordI);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterK, 29U)) + aOrbiterC);
            aWandererA = aWandererA + ((((RotL64(aScatter, 27U) + aOrbiterI) + RotL64(aOrbiterD, 13U)) + aNonceWordK) + aPhaseHWandererUpdateSaltD[((aIndex + 24U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterC, 5U)) + aOrbiterI);
            aWandererF = aWandererF + ((((RotL64(aCross, 21U) + aOrbiterK) + RotL64(aOrbiterB, 57U)) + RotL64(aCarry, 27U)) + aNonceWordF);
            //
            aCarry = aCarry + (RotL64(aWandererI, 37U) ^ aWandererB);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 14U));
            aCarry = aCarry + RotL64(aWandererK, 47U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xFF46E2C1451E506DULL + 0xBCFC0AB66B0F5786ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xE5D82D3607A5D857ULL + 0x9B9846E08EEC6551ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x8B182A4367A97B2BULL + 0x9F1B1545EC7F7D92ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xDF4B71A8ABF745A3ULL + 0xC85CB96223106BCAULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x8204800EA2247963ULL + 0x9D13CD80C9DB5A86ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x865BF3F4FD2CC101ULL + 0xBFCFBC958B197EB3ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xC2FE4452468E6D2FULL + 0x89470FE0C40BCB11ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xF12C78FDF1CAEE93ULL + 0x926E17F04B00431CULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xC502C7E7D8FCD095ULL + 0xD9F28CD14538AC68ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xADA9DFC1BBBE8989ULL + 0xB4CE17B8A24D46DDULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xBDF64297CF09E7D7ULL + 0xA8C9D1D32DD090CDULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x948432A24ACF51F1ULL + 0x991EE0ED6905598FULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x98725F4C1D2F927DULL + 0xE4C79231F8B41DB5ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xF76278FBA8A44B63ULL + 0xB9B5E1DD80969722ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xDBFFEFEBF0425181ULL + 0xA042A64A7FC819A5ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xA4B6BC95780D6DFBULL + 0x96976F9CC431B430ULL);
    // GSeedRunSeed_B seed_loop_a (start)
    {
        // GSeedRunSeed_B seed_loop_a lane group
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneA, aExpandLaneC, aExpandLaneD, aFireLaneB, aInvestLaneA, aFireLaneC, aFireLaneD, aInvestLaneB, aWorkLaneA, aOperationLaneA, aWorkLaneB, aOperationLaneB, aWorkLaneC, aOperationLaneC, aWorkLaneD
        // write to: aInvestLaneA, aInvestLaneB, aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // seed_loop_a loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneA
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aFireLaneB
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aFireLaneB backward/forward random
        // write to: aInvestLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 199U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneB[((aIndex + 3210U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 4702U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 227U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 2688U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 1369U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aPrevious, 37U)) ^ (RotL64(aCarry, 23U) + RotL64(aIngress, 6U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterH = ((((aWandererF + RotL64(aPrevious, 19U)) + RotL64(aCarry, 53U)) + 6068543441070417854U) + aPhaseAOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1]) + aNonceWordK;
            aOrbiterC = (((aWandererE + RotL64(aScatter, 11U)) + RotL64(aCarry, 19U)) + 2995980468193441856U) + aNonceWordG;
            aOrbiterA = (aWandererI + RotL64(aIngress, 35U)) + 18020277482171594003U;
            aOrbiterF = (((aWandererA + RotL64(aCross, 3U)) + RotL64(aCarry, 37U)) + 4293807434721230702U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = (aWandererB + RotL64(aIngress, 44U)) + 7980599111583893156U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 8593141111851052016U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 5903487523900084325U) ^ aNonceWordD;
            aOrbiterA = RotL64((aOrbiterA * 2508618861111356699U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 15112035513447930209U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 9854037263057006439U;
            aOrbiterH = RotL64((aOrbiterH * 396276470208637283U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 16759760289688823193U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterC) ^ 12622628933030601390U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterF = RotL64((aOrbiterF * 2151912984825538321U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 1264668857268123425U) + aNonceWordF;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 16302812053619101593U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 18291400055836111547U), 3U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterF) + 16087995784896123610U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1]) + aNonceWordP;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 7970269262800468363U;
            aOrbiterD = RotL64((aOrbiterD * 14924752223305807461U), 53U);
            //
            aIngress = RotL64(aOrbiterH, 52U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterD, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterH, 39U)) + aOrbiterF);
            aWandererB = aWandererB ^ ((((RotL64(aScatter, 29U) + RotL64(aOrbiterC, 47U)) + aOrbiterD) + aNonceWordN) + aPhaseAWandererUpdateSaltE[((aIndex + 24U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 3U) + RotL64(aOrbiterA, 58U)) + aOrbiterD) + RotL64(aCarry, 57U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 56U) + RotL64(aOrbiterD, 29U)) + aOrbiterF);
            aWandererE = aWandererE + (((((RotL64(aPrevious, 13U) + RotL64(aOrbiterC, 21U)) + aOrbiterF) + RotL64(aCarry, 39U)) + aNonceWordE) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 21U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererE, 40U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aInvestLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 2
        // ingress from: aInvestLaneA, aExpandLaneC, aExpandLaneD, aFireLaneC
        // ingress directions: aInvestLaneA forward forced, aExpandLaneC forward forced, aExpandLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneA, aExpandLaneB, aFireLaneD
        // cross directions: aExpandLaneA backward forced, aExpandLaneB backward forced, aFireLaneD backward/forward random
        // write to: aInvestLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneA[((aIndex + 5834U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneC[((aIndex + 6650U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 8474U)) & S_BLOCK1], 43U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 10197U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 9893U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 6859U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 9781U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aIngress, 52U) + RotL64(aCross, 27U)) ^ (RotL64(aPrevious, 39U) + RotL64(aCarry, 13U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterA = (((aWandererJ + RotL64(aIngress, 27U)) + RotL64(aCarry, 57U)) + 13924571355038625040U) + aNonceWordA;
            aOrbiterC = (((aWandererH + RotL64(aPrevious, 53U)) + RotL64(aCarry, 43U)) + 16328300979357156658U) + aNonceWordB;
            aOrbiterD = (((aWandererG + RotL64(aScatter, 43U)) + RotL64(aCarry, 5U)) + 3947771961206012461U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = ((aWandererC + RotL64(aCross, 6U)) + 15428284250569311285U) + aNonceWordH;
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 35U)) + 5777369485254032486U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 16813320300717644673U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 16689933050200758251U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4832495563863469353U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 1856422419049390708U) + aNonceWordD;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 18214498743831925517U;
            aOrbiterI = RotL64((aOrbiterI * 10744120577560529379U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 18278550878494094923U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 797712062039591797U;
            aOrbiterA = RotL64((aOrbiterA * 7212998747080137625U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 15854849439012341347U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterD) ^ 996882939768167773U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterC = RotL64((aOrbiterC * 14936703950807908575U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 3005829974130671692U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 8793495343509953906U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14065479348374612031U), 11U);
            //
            aIngress = RotL64(aOrbiterA, 35U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterC, 10U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterI, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 41U) + aOrbiterA) + RotL64(aOrbiterH, 58U)) + aPhaseAWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aScatter, 53U) + RotL64(aOrbiterI, 5U)) + aOrbiterA) + RotL64(aCarry, 43U)) + aNonceWordL);
            aWandererC = aWandererC ^ ((((RotL64(aPrevious, 27U) + aOrbiterH) + RotL64(aOrbiterC, 13U)) + aNonceWordN) + aPhaseAWandererUpdateSaltF[((aIndex + 22U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 19U) + aOrbiterD) + RotL64(aOrbiterH, 29U)) + RotL64(aCarry, 27U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 6U) + RotL64(aOrbiterC, 43U)) + aOrbiterA) + aNonceWordG);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererF, 19U);
            aCarry = aCarry + RotL64(aIngress, 10U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aInvestLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_a loop 3
        // ingress from: aInvestLaneB, aExpandLaneA, aWorkLaneA
        // ingress directions: aInvestLaneB forward forced, aExpandLaneA forward forced, aWorkLaneA forward/backward random
        // cross from: aInvestLaneA, aExpandLaneC
        // cross directions: aInvestLaneA backward forced, aExpandLaneC backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneB[((aIndex + 13992U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneA[((aIndex + 13022U)) & S_BLOCK1], 18U));
            aIngress ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15080U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 13776U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((aIndex + 14750U)) & S_BLOCK1], 46U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aIngress, 6U)) ^ (RotL64(aCross, 27U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterF = ((((aWandererF + RotL64(aPrevious, 5U)) + RotL64(aCarry, 51U)) + 3612110001869385068U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordL;
            aOrbiterI = (((aWandererI + RotL64(aCross, 13U)) + RotL64(aCarry, 21U)) + 16340824141280225936U) + aNonceWordJ;
            aOrbiterC = (aWandererJ + RotL64(aIngress, 57U)) + 15222338965130765231U;
            aOrbiterJ = (((aWandererE + RotL64(aScatter, 39U)) + RotL64(aCarry, 37U)) + 6649270508107155041U) + aPhaseAOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = (aWandererH + RotL64(aIngress, 24U)) + 768217258655426384U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 4481855259658861851U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 18318041934562434016U;
            aOrbiterC = RotL64((aOrbiterC * 14913761339765234979U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 4212457153804401807U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 16143621095636987628U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6576072860505961427U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 2095664232866642086U) + aNonceWordB;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 4339527736737366572U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17503569508822244125U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 13679353177869884790U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 11582168502846418236U) ^ aNonceWordH;
            aOrbiterJ = RotL64((aOrbiterJ * 135539430034462861U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 10451330452898542191U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = (((aOrbiterK ^ aOrbiterC) ^ 12951448817640617841U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterK = RotL64((aOrbiterK * 4141870904192742091U), 29U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterF, 47U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 35U));
            aIngress = aIngress + RotL64(aOrbiterK, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aCross, 23U) + aOrbiterK) + RotL64(aOrbiterF, 35U));
            aWandererJ = aWandererJ ^ ((((RotL64(aScatter, 56U) + RotL64(aOrbiterI, 26U)) + aOrbiterF) + aNonceWordO) + aPhaseAWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 11U) + RotL64(aOrbiterC, 51U)) + aOrbiterI) + RotL64(aCarry, 13U));
            aWandererF = aWandererF ^ ((((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterC, 43U)) + aNonceWordD) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 37U) + RotL64(aOrbiterC, 13U)) + aOrbiterF) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 60U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 5U));
            aCarry = aCarry + RotL64(aWandererF, 13U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 4
        // ingress from: aOperationLaneA, aInvestLaneA, aWorkLaneB
        // ingress directions: aOperationLaneA forward forced, aInvestLaneA forward forced, aWorkLaneB forward/backward random
        // cross from: aInvestLaneB, aExpandLaneD
        // cross directions: aInvestLaneB backward forced, aExpandLaneD backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 21570U)) & S_BLOCK1], 3U) ^ RotL64(aInvestLaneA[((aIndex + 17834U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 19749U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 19276U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19755U)) & S_BLOCK1], 10U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aPrevious, 51U) + RotL64(aCarry, 10U)) + (RotL64(aCross, 23U) ^ RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterD = ((aWandererF + RotL64(aScatter, 20U)) + RotL64(aCarry, 35U)) + 13880995121909552664U;
            aOrbiterH = (aWandererE + RotL64(aIngress, 11U)) + 14534942818069300546U;
            aOrbiterC = (((aWandererK + RotL64(aPrevious, 41U)) + 17745973100886007133U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordN;
            aOrbiterB = ((aWandererJ + RotL64(aCross, 57U)) + RotL64(aCarry, 47U)) + 2249805580771946872U;
            aOrbiterA = ((((aWandererG + RotL64(aPrevious, 3U)) + RotL64(aCarry, 11U)) + 4460116116396439410U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordI;
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 3378683994078106878U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 3992996501048809123U;
            aOrbiterC = RotL64((aOrbiterC * 13273544260537223797U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 12057768808864451929U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 4115362079047921130U;
            aOrbiterA = RotL64((aOrbiterA * 12263015903331031345U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 15297384955502206698U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterA) ^ 17623548383481905636U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterH = RotL64((aOrbiterH * 7487278217901483685U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 3559213898000162417U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 12311605719074507335U;
            aOrbiterB = RotL64((aOrbiterB * 3982199462062847697U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 14807313864347885885U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = (((aOrbiterD ^ aOrbiterB) ^ 11222085523291581822U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterD = RotL64((aOrbiterD * 12580941911587215653U), 47U);
            //
            aIngress = RotL64(aOrbiterD, 34U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 21U));
            aIngress = aIngress + RotL64(aOrbiterA, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aScatter, 51U) + RotL64(aOrbiterC, 3U)) + aOrbiterH);
            aWandererE = aWandererE ^ ((((RotL64(aIngress, 5U) + aOrbiterB) + RotL64(aOrbiterC, 12U)) + aNonceWordF) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aCross, 21U) + aOrbiterA) + RotL64(aOrbiterB, 21U)) + RotL64(aCarry, 19U)) + aNonceWordO);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 42U) + RotL64(aOrbiterD, 43U)) + aOrbiterA) + aNonceWordE);
            aWandererJ = aWandererJ + (((((RotL64(aIngress, 13U) + RotL64(aOrbiterD, 29U)) + aOrbiterH) + RotL64(aCarry, 3U)) + aNonceWordA) + aPhaseAWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + (RotL64(aWandererF, 21U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererK, 35U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_a loop 5
        // ingress from: aOperationLaneB, aInvestLaneB, aWorkLaneC
        // ingress directions: aOperationLaneB forward forced, aInvestLaneB forward forced, aWorkLaneC forward/backward random
        // cross from: aOperationLaneA, aInvestLaneA
        // cross directions: aOperationLaneA backward forced, aInvestLaneA backward/forward random
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 23818U)) & S_BLOCK1], 58U) ^ RotL64(aInvestLaneB[((aIndex + 26286U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 22769U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 21919U)) & S_BLOCK1], 24U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 25621U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 19U) + RotL64(aCross, 47U)) ^ (RotL64(aIngress, 35U) ^ RotL64(aCarry, 4U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterA = (((aWandererK + RotL64(aCross, 53U)) + RotL64(aCarry, 39U)) + 9023059520606551446U) + aNonceWordH;
            aOrbiterB = (((aWandererH + RotL64(aPrevious, 37U)) + RotL64(aCarry, 19U)) + 662441755115638133U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterC = (((aWandererF + RotL64(aScatter, 29U)) + RotL64(aCarry, 53U)) + 16957253361196144712U) + aNonceWordO;
            aOrbiterH = (aWandererJ + RotL64(aIngress, 19U)) + 7840955025765308605U;
            aOrbiterE = (((aWandererD + RotL64(aScatter, 6U)) + 346855809270395799U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordJ;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 16099139781586668343U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 3706457327118322098U;
            aOrbiterC = RotL64((aOrbiterC * 7810030620470889591U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 12166825885547622870U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 7792658665720344200U) ^ aNonceWordL;
            aOrbiterE = RotL64((aOrbiterE * 16305542632794270697U), 19U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterE) + 7128477606152986326U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordP;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 11116533962780290084U;
            aOrbiterH = RotL64((aOrbiterH * 11993485572912492297U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 10443889548568288532U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 4402387036946561017U;
            aOrbiterB = RotL64((aOrbiterB * 9032964741841833277U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 13002706161178447654U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 13929727277530310708U;
            aOrbiterA = RotL64((aOrbiterA * 7005639090871200285U), 11U);
            //
            aIngress = RotL64(aOrbiterB, 18U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + RotL64(aOrbiterH, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterB, 11U)) + aOrbiterE) + aNonceWordF);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterC, 20U)) + aOrbiterA);
            aWandererF = aWandererF + (((((RotL64(aIngress, 5U) + RotL64(aOrbiterH, 29U)) + aOrbiterA) + RotL64(aCarry, 29U)) + aNonceWordN) + aPhaseAWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 29U) + aOrbiterC) + RotL64(aOrbiterE, 53U));
            aWandererK = aWandererK + (((((RotL64(aPrevious, 56U) + RotL64(aOrbiterB, 37U)) + aOrbiterA) + RotL64(aCarry, 11U)) + aNonceWordE) + aPhaseAWandererUpdateSaltC[((aIndex + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 21U) ^ aWandererK);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + RotL64(aWandererD, 3U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 6
        // ingress from: aOperationLaneC, aOperationLaneA, aWorkLaneD
        // ingress directions: aOperationLaneC forward forced, aOperationLaneA forward forced, aWorkLaneD forward/backward random
        // cross from: aOperationLaneB, aExpandLaneB
        // cross directions: aOperationLaneB backward forced, aExpandLaneB backward/forward random
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneC[((aIndex + 31026U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneA[((aIndex + 28429U)) & S_BLOCK1], 58U));
            aIngress ^= RotL64(aWorkLaneD[((aIndex + 30628U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28893U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((aIndex + 31959U)) & S_BLOCK1], 40U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCarry, 29U) + RotL64(aPrevious, 41U)) + (RotL64(aCross, 14U) ^ RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterD = (((aWandererE + RotL64(aPrevious, 13U)) + RotL64(aCarry, 47U)) + 3448371607470865612U) + aNonceWordO;
            aOrbiterK = (((aWandererH + RotL64(aCross, 57U)) + RotL64(aCarry, 11U)) + 3743742913651580573U) + aNonceWordA;
            aOrbiterG = ((((aWandererD + RotL64(aScatter, 43U)) + RotL64(aCarry, 23U)) + 13069491287948807280U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordF;
            aOrbiterC = ((aWandererG + RotL64(aIngress, 5U)) + 16872779275586545632U) + aPhaseAOrbiterAssignSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = (aWandererF + RotL64(aPrevious, 26U)) + 17945792656755062795U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 18199747196793731853U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 15953311878379809513U;
            aOrbiterG = RotL64((aOrbiterG * 5476802169152352897U), 57U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterD) + 941268763494588338U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordI;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 10090221530365796809U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14035236086292997613U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 8335698093307607001U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 6147498804734306100U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6904444049941211327U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 5980246079567570090U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 4152167624425912978U;
            aOrbiterC = RotL64((aOrbiterC * 10019421651535123573U), 47U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterC) + 14990418790239735916U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1]) + aNonceWordH;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 3418668387496597219U;
            aOrbiterD = RotL64((aOrbiterD * 12814077238529863119U), 37U);
            //
            aIngress = RotL64(aOrbiterC, 23U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterK, 37U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterF, 4U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aScatter, 51U) + aOrbiterC) + RotL64(aOrbiterG, 51U)) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 22U) + aOrbiterK) + RotL64(aOrbiterF, 11U)) + RotL64(aCarry, 51U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 41U) + aOrbiterD) + RotL64(aOrbiterF, 3U)) + aNonceWordK);
            aWandererG = aWandererG + (((RotL64(aPrevious, 5U) + aOrbiterG) + RotL64(aOrbiterD, 35U)) + RotL64(aCarry, 23U));
            aWandererF = aWandererF ^ ((((RotL64(aCross, 13U) + aOrbiterK) + RotL64(aOrbiterC, 22U)) + aNonceWordN) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererG, 50U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x8ECB6EAE0B453E01ULL + 0xCB94E1E953A0E634ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xEB41D0A9685BCEA3ULL + 0xCA38E1C0DEC3C8E7ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xDFC90D0061EB3371ULL + 0xC66A03E6F8CEDB96ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x95139795E1C29CA5ULL + 0xC5E61DDC65C94CE8ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xEF5FE1CEFE527CCFULL + 0xEA76D49992CE00C9ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x9E54B09E48385B03ULL + 0xB0BFA5AD27EE90D0ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xBC9BA2D945946797ULL + 0x83894A24A9347D4DULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xB78C3FE6F9D53F83ULL + 0xF8BB07165F96CAE2ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xF172AC13BFF06C1DULL + 0xAA4270D847328802ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xE81D525F022F2095ULL + 0xFAF354B4444074B5ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x8F5A2E1419597123ULL + 0xF59CB77F20E87424ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x8CADB82E175101B1ULL + 0xAA1E4073625FBA28ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x9196D089D692FBBBULL + 0x9AE098A5D688B872ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x8C1F3436510DADC1ULL + 0x97C42F7382FBDA9FULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xA2917FD483075121ULL + 0x8203EFFFB2F7C900ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xD03BC672E041F941ULL + 0xDEF7870D757119AAULL);
    // GSeedRunSeed_C seed_loop_b (start)
    {
        // GSeedRunSeed_C seed_loop_b lane group
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneA, aOperationLaneC, aOperationLaneD, aFireLaneB, aWorkLaneA, aFireLaneC, aFireLaneD, aWorkLaneB, aExpandLaneA, aExpandLaneB, aWorkLaneC, aExpandLaneC, aExpandLaneD
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // seed_loop_b loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aFireLaneA
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aFireLaneB
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aFireLaneB backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 5645U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneB[((aIndex + 3379U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 1927U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 3289U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 6604U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 3366U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aPrevious, 36U) ^ RotL64(aCarry, 5U)) + (RotL64(aCross, 53U) ^ RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterB = (aWandererB + RotL64(aPrevious, 42U)) + 11274974230580265396U;
            aOrbiterF = ((aWandererJ + RotL64(aCross, 47U)) + 16658438747342741547U) + aNonceWordN;
            aOrbiterA = ((aWandererI + RotL64(aIngress, 5U)) + RotL64(aCarry, 13U)) + 16612986966106053844U;
            aOrbiterK = (aWandererK + RotL64(aScatter, 57U)) + 9329502236843231290U;
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 23U)) + 14088261356708344656U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = (((aWandererE + RotL64(aIngress, 34U)) + 13692608802007789581U) + aPhaseBOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterG = ((aWandererC + RotL64(aScatter, 19U)) + 6824473946645682398U) + aNonceWordO;
            aOrbiterC = (((aWandererA + RotL64(aCross, 11U)) + RotL64(aCarry, 53U)) + 2072915876348570040U) + aNonceWordE;
            aOrbiterI = ((aWandererD + RotL64(aScatter, 27U)) + RotL64(aCarry, 41U)) + 7420507753044460759U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 4677557318688502593U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 15081678577055628459U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16659305295251177155U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 7026792817486507482U) + aNonceWordI;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 14871665922943969918U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 694073180313083145U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 6807734532159292872U) + aNonceWordG;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 17882797335141303280U;
            aOrbiterK = RotL64((aOrbiterK * 15439872930381050291U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 9233542707022629190U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 1205501586581350876U;
            aOrbiterH = RotL64((aOrbiterH * 2596053290311090589U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 10878718669747466677U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 8066049063548639241U) ^ aNonceWordA;
            aOrbiterC = RotL64((aOrbiterC * 3031382633089381605U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 861295180226875235U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 9134969787937288583U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7565008208670843555U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 6726642007159809594U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 8061661744643240470U;
            aOrbiterF = RotL64((aOrbiterF * 6703498926835391813U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 13541412083111962884U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 8617442758729315637U) ^ aNonceWordD;
            aOrbiterI = RotL64((aOrbiterI * 15471862889276160953U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 16884403561131293362U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 9490680911678221233U;
            aOrbiterD = RotL64((aOrbiterD * 15988763830018001033U), 27U);
            //
            aIngress = RotL64(aOrbiterB, 5U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterI, 46U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterC, 39U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterK, 51U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterG, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterF, 24U)) + aOrbiterH) + RotL64(aCarry, 53U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 6U) + RotL64(aOrbiterH, 41U)) + aOrbiterI) + aNonceWordL);
            aWandererE = aWandererE + (((RotL64(aCross, 35U) + aOrbiterD) + RotL64(aOrbiterB, 47U)) + aPhaseBWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterA, 53U)) + aOrbiterC);
            aWandererJ = aWandererJ + ((RotL64(aCross, 27U) + aOrbiterF) + RotL64(aOrbiterG, 57U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 23U) + aOrbiterK) + RotL64(aOrbiterD, 37U));
            aWandererD = aWandererD + (((((RotL64(aScatter, 57U) + RotL64(aOrbiterD, 29U)) + aOrbiterA) + RotL64(aCarry, 29U)) + aNonceWordP) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 50U) + aOrbiterC) + RotL64(aOrbiterB, 18U)) + aNonceWordC);
            aWandererI = aWandererI + ((RotL64(aScatter, 39U) + RotL64(aOrbiterA, 13U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererE, 40U) ^ aWandererJ);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + RotL64(aWandererK, 21U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 2
        // ingress from: aWorkLaneA, aOperationLaneC, aOperationLaneD, aFireLaneC
        // ingress directions: aWorkLaneA forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aFireLaneD
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aFireLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 15392U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneC[((aIndex + 12932U)) & S_BLOCK1], 24U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 13857U)) & S_BLOCK1], 51U) ^ RotL64(aFireLaneC[((aIndex + 16107U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 13706U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 12454U)) & S_BLOCK1], 48U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 10958U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aPrevious, 27U) + RotL64(aCross, 41U)) ^ (RotL64(aIngress, 13U) ^ RotL64(aCarry, 54U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterA = ((((aWandererD + RotL64(aIngress, 35U)) + RotL64(aCarry, 19U)) + 8685374557928800912U) + aPhaseBOrbiterAssignSaltF[((aIndex + 4U)) & S_SALT1]) + aNonceWordO;
            aOrbiterE = ((aWandererK + RotL64(aCross, 4U)) + 3482312691892161229U) + aNonceWordF;
            aOrbiterD = (aWandererI + RotL64(aScatter, 51U)) + 6948130297389161165U;
            aOrbiterK = (aWandererJ + RotL64(aPrevious, 57U)) + 5506385663788942690U;
            aOrbiterC = ((aWandererC + RotL64(aCross, 29U)) + RotL64(aCarry, 51U)) + 17859982009307397161U;
            aOrbiterF = ((aWandererE + RotL64(aScatter, 41U)) + 9178488809207094043U) + aNonceWordM;
            aOrbiterG = (((aWandererB + RotL64(aPrevious, 47U)) + RotL64(aCarry, 41U)) + 1835479501226057169U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterJ = (aWandererG + RotL64(aIngress, 13U)) + 5368101733632614939U;
            aOrbiterH = (aWandererF + RotL64(aPrevious, 24U)) + 9050459666576835422U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 9042186993119635078U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 17528342580198295025U;
            aOrbiterD = RotL64((aOrbiterD * 14316671546614386775U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 6495418332558436882U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 8834495762667327342U;
            aOrbiterC = RotL64((aOrbiterC * 10783141541937645995U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 4364314196965690905U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 6357485231062120459U) ^ aNonceWordB;
            aOrbiterG = RotL64((aOrbiterG * 289429584586504995U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 3321488322626415347U) + aNonceWordI;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 10817330671781848737U;
            aOrbiterJ = RotL64((aOrbiterJ * 15875919466358823335U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 17974092279281611763U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 2871472057292789157U;
            aOrbiterE = RotL64((aOrbiterE * 16104199340711015181U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 15187929795092006849U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 13482063681546475923U;
            aOrbiterF = RotL64((aOrbiterF * 14466266308157364963U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 6232152545071397380U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 17488906002621373262U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4719340606442742577U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 12444819880507588549U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 13808941689757772497U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6541360905282412317U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 8049361354387692374U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 7137831335606542401U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11022231291507235007U), 37U);
            //
            aIngress = RotL64(aOrbiterJ, 36U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterK, 53U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterA, 43U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 13U));
            aIngress = aIngress + RotL64(aOrbiterH, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aPrevious, 51U) + aOrbiterK) + RotL64(aOrbiterF, 5U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterH, 42U)) + aOrbiterG) + aPhaseBWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 18U) + RotL64(aOrbiterJ, 19U)) + aOrbiterF) + RotL64(aCarry, 3U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterD, 11U)) + aOrbiterK) + aNonceWordC);
            aWandererB = aWandererB + ((RotL64(aIngress, 23U) + RotL64(aOrbiterC, 57U)) + aOrbiterF);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterJ, 51U)) + aOrbiterE);
            aWandererC = aWandererC + ((RotL64(aPrevious, 37U) + RotL64(aOrbiterH, 47U)) + aOrbiterD);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 47U) + aOrbiterA) + RotL64(aOrbiterH, 27U)) + aNonceWordK);
            aWandererE = aWandererE + ((((RotL64(aIngress, 12U) + aOrbiterA) + RotL64(aOrbiterK, 38U)) + RotL64(aCarry, 43U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 21U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 51U));
            aCarry = aCarry + (RotL64(aWandererG, 60U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererF, 11U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_b loop 3
        // ingress from: aWorkLaneB, aOperationLaneA, aOperationLaneB, aExpandLaneA
        // ingress directions: aWorkLaneB forward forced, aOperationLaneA forward forced, aOperationLaneB forward forced, aExpandLaneA forward/backward random
        // cross from: aWorkLaneA, aOperationLaneC, aExpandLaneB
        // cross directions: aWorkLaneA backward forced, aOperationLaneC backward forced, aExpandLaneB backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 22087U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((aIndex + 24402U)) & S_BLOCK1], 19U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 16442U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 18102U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18113U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 17985U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aExpandLaneB[((aIndex + 18406U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aIngress, 26U)) ^ (RotL64(aPrevious, 3U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 41U)) + 9630214189402543339U) + aPhaseBOrbiterAssignSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterB = (((aWandererA + RotL64(aIngress, 29U)) + 4072576573737526819U) + aPhaseBOrbiterAssignSaltC[((aIndex + 16U)) & S_SALT1]) + aNonceWordI;
            aOrbiterJ = (aWandererB + RotL64(aScatter, 54U)) + 15994787452709618869U;
            aOrbiterG = ((aWandererI + RotL64(aCross, 13U)) + RotL64(aCarry, 27U)) + 6403240137132259482U;
            aOrbiterF = (((aWandererD + RotL64(aScatter, 5U)) + RotL64(aCarry, 57U)) + 10229266900170507720U) + aNonceWordL;
            aOrbiterC = (aWandererC + RotL64(aCross, 35U)) + 5025294577989748989U;
            aOrbiterA = (aWandererK + RotL64(aIngress, 46U)) + 16696461238217956883U;
            aOrbiterE = (((aWandererE + RotL64(aPrevious, 23U)) + RotL64(aCarry, 47U)) + 9878318855341719119U) + aNonceWordP;
            aOrbiterK = (aWandererJ + RotL64(aIngress, 19U)) + 16086635438116177346U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 12295437783084203730U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 7681150419912842402U;
            aOrbiterJ = RotL64((aOrbiterJ * 7289497379725191451U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 2639104034287637448U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 12298170009332243573U;
            aOrbiterB = RotL64((aOrbiterB * 9397919591171238575U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 3485932317267669626U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 16569551670038752475U;
            aOrbiterA = RotL64((aOrbiterA * 8139802826402217631U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 4448490103784103954U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 14510534073046885941U;
            aOrbiterK = RotL64((aOrbiterK * 7777192047386438305U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 4286195398675733451U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 15790355933840266463U;
            aOrbiterD = RotL64((aOrbiterD * 13342257823027075501U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 6362891510370156055U) + aNonceWordF;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 15121822034579983174U;
            aOrbiterF = RotL64((aOrbiterF * 7268045994574844937U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 13817341015719915628U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 14113474087906143783U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12838910141533126059U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 9988301252236121106U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 11287477288382171758U) ^ aNonceWordH;
            aOrbiterE = RotL64((aOrbiterE * 4979297247881426383U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 9491727010910328644U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 7961202721830514030U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16300364540313620767U), 43U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterF, 37U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 24U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 13U));
            aIngress = aIngress + (RotL64(aOrbiterE, 5U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterJ, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aCross, 47U) + RotL64(aOrbiterK, 3U)) + aOrbiterE) + RotL64(aCarry, 5U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterF, 57U)) + aOrbiterG) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 28U) + RotL64(aOrbiterE, 48U)) + aOrbiterF) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterJ, 35U)) + aOrbiterA);
            aWandererC = aWandererC + ((RotL64(aPrevious, 43U) + aOrbiterK) + RotL64(aOrbiterF, 39U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterD, 27U)) + aOrbiterB) + aNonceWordN);
            aWandererB = aWandererB + ((((RotL64(aScatter, 60U) + aOrbiterC) + RotL64(aOrbiterF, 14U)) + RotL64(aCarry, 27U)) + aNonceWordO);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterC, 21U)) + aOrbiterD);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterA, 53U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererI, 54U) ^ aWandererK);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererE);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + RotL64(aWandererB, 21U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 4
        // ingress from: aWorkLaneC, aWorkLaneA, aOperationLaneD, aExpandLaneC
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aOperationLaneD forward forced, aExpandLaneC forward/backward random
        // cross from: aWorkLaneB, aOperationLaneB, aExpandLaneD
        // cross directions: aWorkLaneB backward forced, aOperationLaneB backward forced, aExpandLaneD backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 26050U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((aIndex + 29576U)) & S_BLOCK1], 39U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 32467U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneC[((aIndex + 31007U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27981U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29781U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aExpandLaneD[((aIndex + 24728U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCross, 29U) + RotL64(aPrevious, 5U)) ^ (RotL64(aIngress, 57U) ^ RotL64(aCarry, 44U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterD = ((aWandererC + RotL64(aIngress, 47U)) + RotL64(aCarry, 3U)) + 2974056819475622600U;
            aOrbiterH = (aWandererH + RotL64(aCross, 58U)) + 7345051759236356098U;
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 19U)) + RotL64(aCarry, 13U)) + 12738468816846628882U;
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 27U)) + RotL64(aCarry, 35U)) + 7694520596043297922U;
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 41U)) + 5530753590015084774U) + aNonceWordD;
            aOrbiterC = (((aWandererI + RotL64(aIngress, 51U)) + 3776309161718383105U) + aPhaseBOrbiterAssignSaltB[((aIndex + 4U)) & S_SALT1]) + aNonceWordF;
            aOrbiterI = ((aWandererA + RotL64(aCross, 11U)) + 784780304358106404U) + aNonceWordO;
            aOrbiterB = (aWandererG + RotL64(aScatter, 6U)) + 8999942326995036509U;
            aOrbiterG = ((aWandererF + RotL64(aIngress, 35U)) + 5194986506064092779U) + aPhaseBOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 7920040007459652762U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 11311997270710107937U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6227571709361790209U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 5365231114813547251U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 8630110234623825263U;
            aOrbiterA = RotL64((aOrbiterA * 2735881715888325759U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 2358235238039571072U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 18059414891616491807U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 17150786106857185467U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 14526050556461782864U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 6937282036603272474U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14954512365270028029U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 10105832250694931310U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 3884223553012098137U) ^ aNonceWordB;
            aOrbiterD = RotL64((aOrbiterD * 16340956813003906195U), 47U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterG) + 10385284339549648087U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1]) + aNonceWordI;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 1257633893341505930U;
            aOrbiterE = RotL64((aOrbiterE * 2669950791270500977U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 5528890519572824318U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 15664241747527713256U;
            aOrbiterG = RotL64((aOrbiterG * 16670884497088220497U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 14264122979415331887U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 17985061405540198036U;
            aOrbiterI = RotL64((aOrbiterI * 2729487440173395133U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 1663986734997903415U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 3706166884286400587U) ^ aNonceWordJ;
            aOrbiterB = RotL64((aOrbiterB * 10549736618301955745U), 43U);
            //
            aIngress = RotL64(aOrbiterE, 13U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 34U));
            aIngress = aIngress + (RotL64(aOrbiterG, 43U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterB, 27U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterD, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 23U) + aOrbiterB) + RotL64(aOrbiterA, 11U));
            aWandererI = aWandererI + (((RotL64(aIngress, 57U) + aOrbiterH) + RotL64(aOrbiterA, 28U)) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 46U) + RotL64(aOrbiterC, 5U)) + aOrbiterB) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 51U) + aOrbiterI) + RotL64(aOrbiterG, 57U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterH, 23U)) + aOrbiterE);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterE, 47U)) + aOrbiterA) + RotL64(aCarry, 37U)) + aNonceWordM);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 41U) + aOrbiterB) + RotL64(aOrbiterG, 52U)) + aNonceWordP);
            aWandererG = aWandererG + ((RotL64(aIngress, 5U) + aOrbiterK) + RotL64(aOrbiterH, 37U));
            aWandererA = aWandererA ^ ((((RotL64(aCross, 18U) + RotL64(aOrbiterC, 41U)) + aOrbiterD) + aNonceWordA) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 6U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererK);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + RotL64(aWandererC, 27U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xF8A2BD8B18E8DAA9ULL + 0xD93167B85F44B6C8ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xD13239830573EE13ULL + 0xA7C2367183131FE7ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xB294D6DC27E155CBULL + 0xDF8D73D65CD5314DULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xFE7133B09BE19025ULL + 0xEE214B21F70A100EULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xA0A28A11CB615DB9ULL + 0xBBFD019FCE279ACDULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xC49F6D93512722E3ULL + 0x841DB33644DC69C8ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xFEDA12011E647629ULL + 0xB8E65DC5CFD93A7FULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xBBF245F4AC4B3B3BULL + 0xD74D182CA8F8D784ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x814027552FBAAB9DULL + 0x81BB95E53827EE78ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xB985CD6AF14B3A35ULL + 0x88CB4B8DD4538BB2ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xC819DAF88F1EDDFBULL + 0xB8C976BE8AFEF74CULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x80BE6D6733C84959ULL + 0xD9766CEBA7092D40ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xEDE0FAFBEB42A193ULL + 0xB5F29BEC5E403ABBULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x86D2459115FEDB17ULL + 0xEBC043DF1BEB4997ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xAAF7CA57B7E7AC0BULL + 0xE5583F556B6E1DE7ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xF8550A6CBBE42BBFULL + 0xEA90F369A580BECDULL);
    // GSeedRunSeed_D seed_loop_d (start)
    {
        // GSeedRunSeed_D seed_loop_d lane group
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneA, aExpandLaneC, aExpandLaneD, aFireLaneB, aWorkLaneA, aFireLaneC, aFireLaneD, aWorkLaneB, aOperationLaneA, aInvestLaneA, aOperationLaneB, aInvestLaneB, aOperationLaneC, aInvestLaneC, aOperationLaneD
        // write to: aWorkLaneA, aWorkLaneB, aInvestLaneA, aInvestLaneB, aInvestLaneC, aInvestLaneD
    
        // seed_loop_d loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneA
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aFireLaneB
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aFireLaneB backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 3605U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneB[((aIndex + 4123U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 1932U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2976U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 115U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 4031U)) & S_BLOCK1], 18U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aIngress, 27U)) ^ (RotL64(aPrevious, 44U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterG = (((aWandererI + RotL64(aScatter, 39U)) + RotL64(aCarry, 39U)) + 785861751704720606U) + aNonceWordE;
            aOrbiterF = (aWandererB + RotL64(aPrevious, 47U)) + 15968088718435606299U;
            aOrbiterE = (((aWandererA + RotL64(aIngress, 19U)) + RotL64(aCarry, 57U)) + 1393976526590347151U) + aNonceWordM;
            aOrbiterJ = ((aWandererH + RotL64(aCross, 60U)) + 17240750947292745884U) + aNonceWordJ;
            aOrbiterH = (aWandererE + RotL64(aPrevious, 53U)) + 4921576136163183137U;
            aOrbiterC = (((aWandererF + RotL64(aCross, 3U)) + RotL64(aCarry, 19U)) + 3334047873553153032U) + aPhaseDOrbiterAssignSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterB = (((aWandererD + RotL64(aScatter, 13U)) + 15086509978458408698U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordL;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 892391205397581998U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 2965686403183767521U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 709160942482770225U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 14632215393655706170U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 15740589515342377322U) ^ aNonceWordC;
            aOrbiterH = RotL64((aOrbiterH * 15677716942904794913U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 11131164813943086445U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 6988080581278900960U) ^ aNonceWordK;
            aOrbiterG = RotL64((aOrbiterG * 6412189142344044255U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 16021254613117657178U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 6183615599897921154U;
            aOrbiterF = RotL64((aOrbiterF * 9976411093264211033U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 12533992547026652747U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 3104325358982904219U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14977348108778147265U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 3878525937957474644U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 2120435259884368445U;
            aOrbiterC = RotL64((aOrbiterC * 15964718652193073177U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 14928658302694194856U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 9121310461310309348U;
            aOrbiterJ = RotL64((aOrbiterJ * 17304439784647477491U), 51U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterG, 3U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 35U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 21U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterF, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aPrevious, 43U) + RotL64(aOrbiterF, 3U)) + aOrbiterC) + RotL64(aCarry, 47U)) + aNonceWordF);
            aWandererH = aWandererH ^ (((RotL64(aCross, 28U) + aOrbiterH) + RotL64(aOrbiterJ, 46U)) + aNonceWordO);
            aWandererE = aWandererE + ((((RotL64(aIngress, 11U) + aOrbiterE) + RotL64(aOrbiterG, 39U)) + aNonceWordA) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterE, 19U)) + aOrbiterJ) + aPhaseDWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 57U) + RotL64(aOrbiterB, 57U)) + aOrbiterC) + RotL64(aCarry, 11U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterE, 11U)) + aOrbiterB);
            aWandererD = aWandererD + (((RotL64(aPrevious, 35U) + aOrbiterG) + RotL64(aOrbiterJ, 29U)) + aNonceWordI);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 5U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 54U));
            aCarry = aCarry + RotL64(aWandererD, 27U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_d loop 2
        // ingress from: aWorkLaneA, aExpandLaneC, aExpandLaneD, aFireLaneC
        // ingress directions: aWorkLaneA forward forced, aExpandLaneC forward forced, aExpandLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneA, aExpandLaneB, aFireLaneD
        // cross directions: aExpandLaneA backward forced, aExpandLaneB backward forced, aFireLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 6925U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneC[((aIndex + 10058U)) & S_BLOCK1], 21U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 6621U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 8214U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 9469U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 9825U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 7168U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCross, 35U) + RotL64(aPrevious, 60U)) ^ (RotL64(aIngress, 47U) ^ RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterE = (((aWandererF + RotL64(aCross, 12U)) + 15920462086654025436U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordE;
            aOrbiterA = (((aWandererA + RotL64(aPrevious, 29U)) + RotL64(aCarry, 41U)) + 487844076858004017U) + aPhaseDOrbiterAssignSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = (aWandererB + RotL64(aIngress, 37U)) + 14502883786442630566U;
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 5U)) + 3787107318658233674U) + aNonceWordH;
            aOrbiterC = ((aWandererK + RotL64(aIngress, 19U)) + RotL64(aCarry, 3U)) + 12548777544693755491U;
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 51U)) + 4907309444075181683U;
            aOrbiterD = ((aWandererG + RotL64(aCross, 43U)) + RotL64(aCarry, 23U)) + 18342396700266492072U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 13503051997624242670U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 17845742460521374571U;
            aOrbiterF = RotL64((aOrbiterF * 1366356786138085155U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 8640887211877858169U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterA) ^ 5273913123709097537U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterC = RotL64((aOrbiterC * 1661149444148461791U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 17756844173695563883U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 6713055830729302951U) ^ aNonceWordG;
            aOrbiterA = RotL64((aOrbiterA * 2832836748513174311U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 5106468334224035972U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 10228769728713526172U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9760310686414358435U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 7687649520668883142U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 7757480627354711605U;
            aOrbiterJ = RotL64((aOrbiterJ * 7222553727737349209U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 10876291698508634557U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 8149278085586014186U;
            aOrbiterE = RotL64((aOrbiterE * 8577133863470695381U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 15592893988925610485U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 8639028256640537165U;
            aOrbiterG = RotL64((aOrbiterG * 1880655276432963955U), 35U);
            //
            aIngress = RotL64(aOrbiterC, 41U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 51U));
            aIngress = aIngress + RotL64(aOrbiterG, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 29U) + aOrbiterF) + RotL64(aOrbiterD, 21U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 60U) + RotL64(aOrbiterJ, 43U)) + aOrbiterD) + aNonceWordK);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterC, 58U)) + aOrbiterF) + aNonceWordJ);
            aWandererG = aWandererG + (((((RotL64(aCross, 13U) + aOrbiterA) + RotL64(aOrbiterG, 51U)) + RotL64(aCarry, 5U)) + aNonceWordC) + aPhaseDWandererUpdateSaltF[((aIndex + 26U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 35U) + aOrbiterC) + RotL64(aOrbiterA, 13U));
            aWandererB = aWandererB + (((((RotL64(aScatter, 41U) + RotL64(aOrbiterJ, 37U)) + aOrbiterG) + RotL64(aCarry, 19U)) + aNonceWordP) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 21U) + aOrbiterE) + RotL64(aOrbiterC, 27U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 43U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 6U));
            aCarry = aCarry + RotL64(aWandererK, 13U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_d loop 3
        // ingress from: aWorkLaneB, aExpandLaneA, aOperationLaneA
        // ingress directions: aWorkLaneB forward forced, aExpandLaneA forward forced, aOperationLaneA forward/backward random
        // cross from: aWorkLaneA, aExpandLaneC
        // cross directions: aWorkLaneA backward forced, aExpandLaneC backward/forward random
        // write to: aInvestLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 11628U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneA[((aIndex + 13842U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 15887U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12423U)) & S_BLOCK1], 36U) ^ RotL64(aExpandLaneC[((aIndex + 15916U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCarry, 43U) + RotL64(aIngress, 28U)) + (RotL64(aPrevious, 11U) ^ RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterH = (((aWandererB + RotL64(aIngress, 51U)) + RotL64(aCarry, 11U)) + 7790166497945719700U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = (aWandererG + RotL64(aPrevious, 11U)) + 7136208896846119188U;
            aOrbiterE = ((aWandererD + RotL64(aCross, 35U)) + RotL64(aCarry, 51U)) + 12123156943355100886U;
            aOrbiterC = ((aWandererF + RotL64(aScatter, 43U)) + 5095546037880875199U) + aNonceWordK;
            aOrbiterB = (((aWandererE + RotL64(aIngress, 19U)) + 17642705393916765992U) + aPhaseDOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1]) + aNonceWordD;
            aOrbiterK = ((aWandererI + RotL64(aScatter, 5U)) + RotL64(aCarry, 29U)) + 9918479837334416990U;
            aOrbiterI = (aWandererK + RotL64(aPrevious, 58U)) + 4890009823843176466U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 17652590786213674124U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 870002527644696135U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 915408393979165539U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 12545429703552643682U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 5310272867406182581U) ^ aNonceWordG;
            aOrbiterH = RotL64((aOrbiterH * 10420003334833925011U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 3264719049050179440U) + aNonceWordC;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 1967241238180278937U;
            aOrbiterI = RotL64((aOrbiterI * 13004319774269457957U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 773883832927040736U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 12766817190261232485U;
            aOrbiterB = RotL64((aOrbiterB * 7448864556802318431U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 260069382395598265U) + aNonceWordB;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 15462103891287350123U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5029268763635635753U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 4072032867513289827U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 17153061419083897076U;
            aOrbiterC = RotL64((aOrbiterC * 11934532169271718913U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 6207264270332656966U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 18048064697837314947U) ^ aNonceWordO;
            aOrbiterK = RotL64((aOrbiterK * 13632594619404208489U), 19U);
            //
            aIngress = RotL64(aOrbiterF, 51U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + (RotL64(aOrbiterB, 27U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterH, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterK, 51U)) + aOrbiterC) + RotL64(aCarry, 43U)) + aNonceWordE);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 11U) + aOrbiterK) + RotL64(aOrbiterH, 28U));
            aWandererF = aWandererF + ((RotL64(aIngress, 47U) + aOrbiterK) + RotL64(aOrbiterI, 43U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 36U) + RotL64(aOrbiterI, 3U)) + aOrbiterE);
            aWandererB = aWandererB + ((((RotL64(aIngress, 23U) + RotL64(aOrbiterF, 37U)) + aOrbiterB) + RotL64(aCarry, 23U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterF, 19U)) + aOrbiterE) + aNonceWordP);
            aWandererD = aWandererD + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterH, 13U)) + aOrbiterF) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 29U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererK);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 36U));
            aCarry = aCarry + RotL64(aWandererI, 21U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aInvestLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_d loop 4
        // ingress from: aInvestLaneA, aWorkLaneA, aOperationLaneB
        // ingress directions: aInvestLaneA forward forced, aWorkLaneA forward forced, aOperationLaneB forward/backward random
        // cross from: aWorkLaneB, aExpandLaneD
        // cross directions: aWorkLaneB backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneA[((aIndex + 21467U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((aIndex + 19285U)) & S_BLOCK1], 14U));
            aIngress ^= RotL64(aOperationLaneB[((aIndex + 17228U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19682U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((aIndex + 19921U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCross, 3U) + RotL64(aIngress, 24U)) ^ (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterE = ((aWandererE + RotL64(aCross, 57U)) + RotL64(aCarry, 51U)) + 1888427424966603593U;
            aOrbiterA = ((((aWandererJ + RotL64(aIngress, 51U)) + RotL64(aCarry, 19U)) + 5436761445660415091U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordE;
            aOrbiterJ = (((aWandererF + RotL64(aScatter, 11U)) + RotL64(aCarry, 3U)) + 17322876217962143270U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 43U)) + 9728299982740564979U) + aNonceWordF;
            aOrbiterD = (aWandererB + RotL64(aIngress, 19U)) + 301720335271716921U;
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 34U)) + 8069685428854814396U) + aNonceWordJ;
            aOrbiterH = ((aWandererK + RotL64(aScatter, 3U)) + 1973715500949100991U) + aNonceWordH;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 87666408799854155U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 12195436904339035245U) ^ aNonceWordN;
            aOrbiterJ = RotL64((aOrbiterJ * 15427739165893738105U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 4578742069143400295U) + aNonceWordL;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 7828776048774876484U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4047964518501081039U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 17203146364542781833U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 16913369550858890466U) ^ aNonceWordP;
            aOrbiterE = RotL64((aOrbiterE * 13534417587921978507U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 9632761514552265402U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 9106637671877341286U;
            aOrbiterD = RotL64((aOrbiterD * 9073709119482640391U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 15423680889126750876U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 6087310684583331882U;
            aOrbiterH = RotL64((aOrbiterH * 8964465129744898619U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 5420955876411796789U) + aNonceWordB;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 14166807419730848032U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 442659738632823751U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 8118312450347026824U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 4253043584558403086U;
            aOrbiterA = RotL64((aOrbiterA * 5651748455190536467U), 21U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterF, 27U);
            aIngress = aIngress + (RotL64(aOrbiterA, 60U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 5U));
            aIngress = aIngress + RotL64(aOrbiterC, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 13U) + aOrbiterD) + RotL64(aOrbiterH, 11U)) + aNonceWordO);
            aWandererE = aWandererE + (((RotL64(aCross, 28U) + aOrbiterC) + RotL64(aOrbiterD, 29U)) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 53U) + aOrbiterC) + RotL64(aOrbiterA, 57U)) + aNonceWordD);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterC, 51U)) + aOrbiterH) + RotL64(aCarry, 37U)) + aNonceWordM);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterF, 42U)) + aOrbiterD) + aNonceWordK);
            aWandererF = aWandererF + (((RotL64(aScatter, 37U) + RotL64(aOrbiterJ, 5U)) + aOrbiterH) + aPhaseDWandererUpdateSaltB[((aIndex + 6U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 43U) + aOrbiterE) + RotL64(aOrbiterJ, 21U)) + aPhaseDWandererUpdateSaltE[((aIndex + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 41U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererF, 24U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aInvestLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_d loop 5
        // ingress from: aInvestLaneB, aWorkLaneB, aOperationLaneC
        // ingress directions: aInvestLaneB forward forced, aWorkLaneB forward forced, aOperationLaneC forward/backward random
        // cross from: aInvestLaneA, aWorkLaneA
        // cross directions: aInvestLaneA backward forced, aWorkLaneA backward/forward random
        // write to: aInvestLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneB[((aIndex + 26991U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((aIndex + 25208U)) & S_BLOCK1], 52U));
            aIngress ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 23624U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 24152U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22654U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 3U) + RotL64(aCarry, 39U)) ^ (RotL64(aIngress, 22U) + RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterI = ((aWandererC + RotL64(aCross, 29U)) + 4384716820085860551U) + aNonceWordM;
            aOrbiterB = (((aWandererG + RotL64(aPrevious, 57U)) + RotL64(aCarry, 53U)) + 9715780315942116888U) + aNonceWordO;
            aOrbiterD = (aWandererK + RotL64(aIngress, 51U)) + 15963520052789178632U;
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 5U)) + 14346700690686392938U) + aNonceWordH;
            aOrbiterF = (((aWandererA + RotL64(aIngress, 20U)) + RotL64(aCarry, 5U)) + 6005518012489966643U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = ((((aWandererB + RotL64(aCross, 35U)) + RotL64(aCarry, 29U)) + 2506732930310252119U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordK;
            aOrbiterG = (aWandererF + RotL64(aPrevious, 11U)) + 16782163084851775826U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 823673076571076303U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 1634084509064077736U;
            aOrbiterD = RotL64((aOrbiterD * 1128407326773234517U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 1288134975466877686U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 2998220403162908444U) ^ aNonceWordA;
            aOrbiterB = RotL64((aOrbiterB * 4321412662318298283U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 220430672180734911U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 10223923547068528867U) ^ aNonceWordB;
            aOrbiterF = RotL64((aOrbiterF * 12577370238343872139U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 11696469696177647608U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 6545430420379636963U;
            aOrbiterA = RotL64((aOrbiterA * 8387163146257553773U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 79691451831797107U) + aNonceWordD;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 8971444023498649419U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7148919880477390009U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 5624403902454498793U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 9468064161002030997U;
            aOrbiterI = RotL64((aOrbiterI * 8243560528100864595U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 4619361544913629805U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 12682446273369750704U;
            aOrbiterE = RotL64((aOrbiterE * 10879074713156075641U), 29U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterD, 57U);
            aIngress = aIngress + (RotL64(aOrbiterI, 37U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterB, 43U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterI, 35U)) + aOrbiterA) + RotL64(aCarry, 41U)) + aNonceWordL);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 20U) + RotL64(aOrbiterD, 58U)) + aOrbiterG);
            aWandererA = aWandererA + (((((RotL64(aCross, 35U) + RotL64(aOrbiterE, 21U)) + aOrbiterB) + RotL64(aCarry, 29U)) + aNonceWordI) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 41U) + aOrbiterE) + RotL64(aOrbiterF, 13U));
            aWandererB = aWandererB + (((RotL64(aIngress, 5U) + RotL64(aOrbiterB, 51U)) + aOrbiterG) + aPhaseDWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterF, 27U)) + aOrbiterA) + aNonceWordN);
            aWandererG = aWandererG + (((RotL64(aCross, 51U) + aOrbiterD) + RotL64(aOrbiterI, 43U)) + aNonceWordP);
            //
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererF);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 18U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 53U));
            aCarry = aCarry + RotL64(aWandererK, 35U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aInvestLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_d loop 6
        // ingress from: aInvestLaneC, aInvestLaneA, aOperationLaneD
        // ingress directions: aInvestLaneC forward forced, aInvestLaneA forward forced, aOperationLaneD forward/backward random
        // cross from: aInvestLaneB, aExpandLaneB
        // cross directions: aInvestLaneB backward forced, aExpandLaneB backward/forward random
        // write to: aInvestLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneC[((aIndex + 30328U)) & S_BLOCK1], 3U) ^ RotL64(aInvestLaneA[((aIndex + 28793U)) & S_BLOCK1], 58U));
            aIngress ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 29080U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 30684U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((aIndex + 28525U)) & S_BLOCK1], 34U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 21U) + RotL64(aCross, 5U)) ^ (RotL64(aCarry, 53U) + RotL64(aPrevious, 38U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterD = (aWandererC + RotL64(aCross, 3U)) + 2177539223979303669U;
            aOrbiterF = ((aWandererD + RotL64(aScatter, 47U)) + 3962004686551521471U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = (((aWandererA + RotL64(aPrevious, 53U)) + RotL64(aCarry, 5U)) + 8457602312617147662U) + aNonceWordD;
            aOrbiterA = (((aWandererB + RotL64(aIngress, 18U)) + RotL64(aCarry, 23U)) + 18011802451816510632U) + aNonceWordJ;
            aOrbiterK = ((aWandererK + RotL64(aCross, 29U)) + RotL64(aCarry, 53U)) + 9046101759168876832U;
            aOrbiterH = (aWandererF + RotL64(aPrevious, 39U)) + 11135620637431969597U;
            aOrbiterI = ((aWandererG + RotL64(aScatter, 11U)) + 15913029940697999701U) + aPhaseDOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 16304193109948135982U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 13208892298820080981U;
            aOrbiterG = RotL64((aOrbiterG * 15093751072618884859U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 4182377898949419225U) + aNonceWordC;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 13970137023071326151U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9075061559681739865U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 8402396284835248583U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 8859190834060657829U) ^ aNonceWordK;
            aOrbiterA = RotL64((aOrbiterA * 13552418608113716117U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 9760005337757990392U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 14108277760135744897U;
            aOrbiterF = RotL64((aOrbiterF * 4474681104256093885U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 12226316121949012350U) + aNonceWordP;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 3456392186754113960U;
            aOrbiterK = RotL64((aOrbiterK * 8704729827929941215U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 5004087958637038973U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 7176881295123125567U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15272157962928021009U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 10889800478505074438U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 13728832441482547824U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17588477761978646139U), 5U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterF, 51U);
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 43U));
            aIngress = aIngress + RotL64(aOrbiterA, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 10U) + aOrbiterF) + RotL64(aOrbiterI, 5U));
            aWandererG = aWandererG + ((RotL64(aCross, 37U) + aOrbiterG) + RotL64(aOrbiterH, 43U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 57U) + aOrbiterK) + RotL64(aOrbiterA, 11U));
            aWandererB = aWandererB + (((((RotL64(aIngress, 43U) + RotL64(aOrbiterH, 29U)) + aOrbiterK) + RotL64(aCarry, 37U)) + aNonceWordF) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 51U) + aOrbiterA) + RotL64(aOrbiterF, 21U));
            aWandererK = aWandererK + ((((RotL64(aPrevious, 27U) + aOrbiterF) + RotL64(aOrbiterD, 57U)) + RotL64(aCarry, 57U)) + aNonceWordM);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 21U) + aOrbiterK) + RotL64(aOrbiterF, 50U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 37U) ^ aWandererD);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 58U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + RotL64(aWandererG, 13U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xB8B509AE66895D5FULL + 0xCE7D70A307FA8802ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xD25D03FA65383C4DULL + 0xC56541D56DAFCF57ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xE55118AF1F17DC97ULL + 0xE135337D17E41606ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xEF8796EA6B672DDBULL + 0xAB30DD56BEC94482ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xCCDF96CAABFEC28FULL + 0xE710EDCDEE8508DCULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xFF9EFC3201D4BEEBULL + 0xB2F8BBFFBAAD4AC2ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xAE8CD24732965785ULL + 0x9422D28A07176480ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xFD0DEECC539FE7D3ULL + 0x86D4244FD6C2B2F6ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xBEC5DBF938D427ABULL + 0xA73C80BE91009D91ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xE1AF7964CA8BE1C3ULL + 0xBA40D9D1CC88ABE4ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xE6E2788614CED8FFULL + 0x82F24425E790C52CULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xC67EF97636649DDDULL + 0xB14FD1C118FB3135ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xF73883FE733CB639ULL + 0xD4F9C4C671E8CA4BULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x9EAC23E7DB576441ULL + 0xF3C51AD3EC511659ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x94B82A2A2CE92E79ULL + 0xCD1DE64974200D9BULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x9164F918199A8B77ULL + 0xCDEF82C7ADB8250DULL);
    // GSeedRunSeed_E seed_loop_e (start)
    {
        // GSeedRunSeed_E seed_loop_e lane group
        // read from: aInvestLaneA, aInvestLaneB, aFireLaneA, aInvestLaneC, aInvestLaneD, aFireLaneB, aSnowLaneA, aFireLaneC, aFireLaneD, aSnowLaneB, aWorkLaneA, aOperationLaneA, aWorkLaneB, aOperationLaneB, aWorkLaneC, aOperationLaneC, aWorkLaneD
        // write to: aSnowLaneA, aSnowLaneB, aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // seed_loop_e loop 1
        // ingress from: aInvestLaneA, aInvestLaneB, aFireLaneA
        // ingress directions: aInvestLaneA forward forced, aInvestLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aInvestLaneC, aInvestLaneD, aFireLaneB
        // cross directions: aInvestLaneC backward forced, aInvestLaneD backward forced, aFireLaneB backward/forward random
        // write to: aSnowLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneA[((aIndex + 5049U)) & S_BLOCK1], 22U) ^ RotL64(aInvestLaneB[((aIndex + 3467U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 2085U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 4770U)) & S_BLOCK1], 23U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 4675U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 3062U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aPrevious, 23U)) ^ (RotL64(aCarry, 6U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterC = (aWandererE + RotL64(aCross, 5U)) + 8975885703279267062U;
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 39U)) + RotL64(aCarry, 47U)) + 8664844915562660637U;
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 3U)) + 12281774799736296726U) + aNonceWordB;
            aOrbiterH = (((aWandererI + RotL64(aScatter, 18U)) + RotL64(aCarry, 27U)) + 15347461352311329726U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 41U)) + 12967500561828907834U) + aNonceWordK;
            aOrbiterK = ((aWandererG + RotL64(aScatter, 11U)) + 5002833859280402726U) + aPhaseEOrbiterAssignSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = (aWandererD + RotL64(aIngress, 23U)) + 11908257536954668983U;
            aOrbiterA = (aWandererK + RotL64(aCross, 13U)) + 17017174811949227162U;
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 21U)) + RotL64(aCarry, 35U)) + 16851323125613931180U;
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 34U)) + 13469326957728686706U) + aNonceWordO;
            aOrbiterB = (aWandererC + RotL64(aCross, 57U)) + 5228638551056105241U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 11945166198089308564U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 16268645041872996022U) ^ aNonceWordF;
            aOrbiterI = RotL64((aOrbiterI * 5391448793718370911U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 14781204627695095701U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 5365325354838101092U;
            aOrbiterD = RotL64((aOrbiterD * 8017284997946310807U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 563147416025715953U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 14660867395395625851U;
            aOrbiterG = RotL64((aOrbiterG * 4769458126865307103U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 3168989056355712105U) + aNonceWordE;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 16179131669773665579U;
            aOrbiterH = RotL64((aOrbiterH * 5641461617066671723U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 4160220074225527179U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 8597134686962559111U;
            aOrbiterJ = RotL64((aOrbiterJ * 639572585431474015U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 16811551552456811661U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 5827323970423386301U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9328247349730652021U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 15583234353262170227U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 2950816254621717748U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1102417597476170143U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 4426165025104306337U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 11871220132164971152U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2366168050042802207U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 3832424136113939717U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 17673885217916768611U;
            aOrbiterE = RotL64((aOrbiterE * 10887063696370811871U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 3479289844909914390U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 9498461576098567546U;
            aOrbiterB = RotL64((aOrbiterB * 8734492074299676555U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 10645314291190544864U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 8975885703279267062U;
            aOrbiterK = RotL64((aOrbiterK * 16584086014947250551U), 11U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterF, 35U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 5U));
            aIngress = aIngress + (RotL64(aOrbiterE, 43U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterJ, 56U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 23U));
            aIngress = aIngress + RotL64(aOrbiterK, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 57U) + aOrbiterC) + RotL64(aOrbiterJ, 23U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterH, 27U)) + aOrbiterE) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 14U) + aOrbiterD) + RotL64(aOrbiterE, 21U));
            aWandererH = aWandererH + ((((RotL64(aCross, 37U) + RotL64(aOrbiterJ, 51U)) + aOrbiterF) + RotL64(aCarry, 43U)) + aNonceWordC);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 39U) + RotL64(aOrbiterH, 39U)) + aOrbiterA) + aPhaseEWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 5U) + aOrbiterE) + RotL64(aOrbiterF, 37U)) + RotL64(aCarry, 5U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterG, 56U)) + aOrbiterI);
            aWandererG = aWandererG + ((RotL64(aPrevious, 26U) + RotL64(aOrbiterK, 35U)) + aOrbiterI);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterF, 43U)) + aOrbiterK);
            aWandererI = aWandererI + ((RotL64(aCross, 53U) + RotL64(aOrbiterI, 47U)) + aOrbiterB);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 11U) + aOrbiterD) + RotL64(aOrbiterI, 10U)) + aNonceWordN);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 60U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (RotL64(aWandererA, 53U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererC, 44U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aSnowLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_e loop 2
        // ingress from: aSnowLaneA, aInvestLaneC, aInvestLaneD, aFireLaneC
        // ingress directions: aSnowLaneA forward forced, aInvestLaneC forward forced, aInvestLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aInvestLaneA, aInvestLaneB, aFireLaneD
        // cross directions: aInvestLaneA backward forced, aInvestLaneB backward forced, aFireLaneD backward/forward random
        // write to: aSnowLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 10495U)) & S_BLOCK1], 13U) ^ RotL64(aInvestLaneC[((aIndex + 9019U)) & S_BLOCK1], 5U));
            aIngress ^= (RotL64(aInvestLaneD[((aIndex + 9047U)) & S_BLOCK1], 35U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 10249U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 9102U)) & S_BLOCK1], 34U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 7363U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 10305U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCross, 54U) + RotL64(aPrevious, 37U)) ^ (RotL64(aCarry, 21U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 41U)) + 5960680319644404115U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = ((aWandererD + RotL64(aCross, 43U)) + 16050752633567034185U) + aNonceWordI;
            aOrbiterH = (aWandererK + RotL64(aIngress, 11U)) + 8447503223226854741U;
            aOrbiterF = (aWandererA + RotL64(aScatter, 28U)) + 14176813813397917591U;
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 19U)) + RotL64(aCarry, 27U)) + 10534915376130006644U;
            aOrbiterA = ((aWandererE + RotL64(aScatter, 35U)) + 6866224454375302514U) + aNonceWordP;
            aOrbiterJ = (aWandererB + RotL64(aIngress, 3U)) + 16506374165041008396U;
            aOrbiterC = ((aWandererG + RotL64(aCross, 21U)) + RotL64(aCarry, 21U)) + 7167814023968794098U;
            aOrbiterB = (((aWandererH + RotL64(aIngress, 38U)) + RotL64(aCarry, 41U)) + 13870852197416596664U) + aNonceWordH;
            aOrbiterK = (((aWandererC + RotL64(aCross, 5U)) + 18064038854848993105U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordG;
            aOrbiterG = (aWandererJ + RotL64(aScatter, 13U)) + 9869630811507771691U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 863613100452759380U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 16597969741225436529U) ^ aNonceWordB;
            aOrbiterH = RotL64((aOrbiterH * 2680793528887208903U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 6575347108051310653U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 17062262265485019063U;
            aOrbiterA = RotL64((aOrbiterA * 7601045488473620019U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 7193399224636409133U) + aNonceWordD;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 14146747818810433849U;
            aOrbiterJ = RotL64((aOrbiterJ * 5273185769989530041U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 9441449106442431427U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 4303295336545399503U;
            aOrbiterC = RotL64((aOrbiterC * 8829695296836242587U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 12604760768543193458U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 15779327512379787715U) ^ aNonceWordE;
            aOrbiterE = RotL64((aOrbiterE * 14000905201441272597U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 15553000781122708728U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 17162740616060079717U;
            aOrbiterD = RotL64((aOrbiterD * 9458662233556750239U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 1032374679817715156U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 16413393156165548232U;
            aOrbiterB = RotL64((aOrbiterB * 549659738811935015U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 14056855000013992045U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 7399202019042538829U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6103508549612077695U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 2218389473339103389U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 4679497280975967770U;
            aOrbiterI = RotL64((aOrbiterI * 9228353578259815023U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 7620538119914173747U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 3118355627808424159U;
            aOrbiterF = RotL64((aOrbiterF * 12481319980496032783U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 16787092219237931175U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 5960680319644404115U;
            aOrbiterG = RotL64((aOrbiterG * 10727217147056112401U), 27U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterK, 27U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + (RotL64(aOrbiterF, 43U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterJ, 18U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterG, 23U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aIngress, 43U) + aOrbiterC) + RotL64(aOrbiterK, 27U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 24U) + aOrbiterE) + RotL64(aOrbiterD, 4U)) + aPhaseEWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aPrevious, 53U) + aOrbiterG) + RotL64(aOrbiterK, 13U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterC, 35U)) + aOrbiterG);
            aWandererF = aWandererF + ((((RotL64(aScatter, 27U) + aOrbiterD) + RotL64(aOrbiterF, 37U)) + aNonceWordC) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 37U) + aOrbiterG) + RotL64(aOrbiterI, 53U));
            aWandererH = aWandererH + ((RotL64(aIngress, 19U) + aOrbiterJ) + RotL64(aOrbiterF, 10U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 21U) + aOrbiterB) + RotL64(aOrbiterH, 29U)) + aNonceWordJ);
            aWandererE = aWandererE + (((RotL64(aCross, 47U) + aOrbiterB) + RotL64(aOrbiterC, 39U)) + RotL64(aCarry, 37U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterD, 21U)) + aOrbiterG);
            aWandererB = aWandererB + (((RotL64(aIngress, 14U) + aOrbiterA) + RotL64(aOrbiterG, 51U)) + RotL64(aCarry, 19U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 4U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererF);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + RotL64(aWandererH, 22U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aSnowLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_e loop 3
        // ingress from: aSnowLaneB, aInvestLaneA, aWorkLaneA
        // ingress directions: aSnowLaneB forward forced, aInvestLaneA forward forced, aWorkLaneA forward/backward random
        // cross from: aSnowLaneA, aInvestLaneC
        // cross directions: aSnowLaneA backward forced, aInvestLaneC backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneB[((aIndex + 15602U)) & S_BLOCK1], 27U) ^ RotL64(aInvestLaneA[((aIndex + 14754U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aWorkLaneA[((aIndex + 12434U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 15274U)) & S_BLOCK1], 56U) ^ RotL64(aInvestLaneC[((aIndex + 13961U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aIngress, 43U) + RotL64(aCarry, 26U)) + (RotL64(aPrevious, 57U) ^ RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterD = ((aWandererH + RotL64(aIngress, 51U)) + 6973892330986118220U) + aNonceWordH;
            aOrbiterG = ((aWandererD + RotL64(aScatter, 27U)) + 9886813896272094864U) + aNonceWordF;
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 30U)) + 10996306582517553173U) + aNonceWordC;
            aOrbiterI = ((aWandererF + RotL64(aCross, 21U)) + 8490648283899856223U) + aPhaseEOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 53U)) + 105141713530704655U) + aPhaseEOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = ((aWandererE + RotL64(aIngress, 39U)) + RotL64(aCarry, 19U)) + 3114337422810562588U;
            aOrbiterC = ((aWandererB + RotL64(aScatter, 11U)) + RotL64(aCarry, 37U)) + 980857684690886131U;
            aOrbiterH = ((aWandererJ + RotL64(aCross, 37U)) + RotL64(aCarry, 11U)) + 6562042345807072665U;
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 23U)) + 15665371138706353619U) + aNonceWordO;
            aOrbiterJ = (aWandererA + RotL64(aScatter, 42U)) + 18113013571374375028U;
            aOrbiterF = (aWandererC + RotL64(aCross, 57U)) + 17405346422601997299U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 5130876096426182506U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 1813821672299154629U;
            aOrbiterA = RotL64((aOrbiterA * 15478100342425611875U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 15793814882743306728U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 13925299440495476399U;
            aOrbiterG = RotL64((aOrbiterG * 12049601510660117401U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 9924458846049579438U) + aNonceWordG;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 7810034662781768090U;
            aOrbiterC = RotL64((aOrbiterC * 10310594595026622513U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 12812586478656872854U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 5709576448057435237U;
            aOrbiterH = RotL64((aOrbiterH * 9101555233909853025U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 7839807649914541516U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 4717944526755429647U;
            aOrbiterJ = RotL64((aOrbiterJ * 8515229146471335721U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 3933911971504256022U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 4814079680865379831U) ^ aNonceWordB;
            aOrbiterF = RotL64((aOrbiterF * 15100740696230557391U), 35U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterH) + 18352577312212175569U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordK;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 9670612998448920742U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5743579439303300553U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 72737302703035726U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 10032869372369626210U;
            aOrbiterK = RotL64((aOrbiterK * 7449905669249993731U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 2669999453643982386U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 2016129534922291383U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11730911201750754301U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 5108689262300895422U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 3753457479225942895U;
            aOrbiterI = RotL64((aOrbiterI * 11503304711866175497U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 859776381005289485U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 6973892330986118220U) ^ aNonceWordL;
            aOrbiterE = RotL64((aOrbiterE * 12337041087475258221U), 13U);
            //
            aIngress = RotL64(aOrbiterC, 3U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterH, 44U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterA, 13U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 39U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 11U));
            aIngress = aIngress + RotL64(aOrbiterB, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterA, 60U)) + aOrbiterI);
            aWandererK = aWandererK + ((RotL64(aIngress, 57U) + RotL64(aOrbiterH, 29U)) + aOrbiterF);
            aWandererA = aWandererA ^ ((RotL64(aCross, 36U) + aOrbiterC) + RotL64(aOrbiterK, 41U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 41U) + aOrbiterB) + RotL64(aOrbiterG, 47U)) + aNonceWordJ);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterJ, 35U)) + aOrbiterA);
            aWandererF = aWandererF + ((((RotL64(aCross, 5U) + aOrbiterF) + RotL64(aOrbiterA, 21U)) + RotL64(aCarry, 11U)) + aNonceWordE);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 47U) + aOrbiterG) + RotL64(aOrbiterK, 12U));
            aWandererC = aWandererC + ((((RotL64(aPrevious, 26U) + aOrbiterB) + RotL64(aOrbiterK, 23U)) + RotL64(aCarry, 29U)) + aNonceWordA);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 51U) + aOrbiterD) + RotL64(aOrbiterA, 37U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 29U) + aOrbiterE) + RotL64(aOrbiterI, 51U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 21U) + aOrbiterC) + RotL64(aOrbiterD, 27U)) + aNonceWordM);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 41U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 34U));
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererF);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + RotL64(aWandererB, 51U);
            aCarry = aCarry + RotL64(aIngress, 54U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_e loop 4
        // ingress from: aOperationLaneA, aSnowLaneA, aWorkLaneB
        // ingress directions: aOperationLaneA forward forced, aSnowLaneA forward forced, aWorkLaneB forward/backward random
        // cross from: aSnowLaneB, aInvestLaneD
        // cross directions: aSnowLaneB backward forced, aInvestLaneD backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 17744U)) & S_BLOCK1], 11U) ^ RotL64(aSnowLaneA[((aIndex + 21698U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 19683U)) & S_BLOCK1], 20U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 18337U)) & S_BLOCK1], 4U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 18936U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCross, 5U)) ^ (RotL64(aCarry, 42U) + RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterF = ((aWandererB + RotL64(aIngress, 43U)) + 3650233661228036955U) + aPhaseEOrbiterAssignSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 19U)) + RotL64(aCarry, 29U)) + 11607036400067735729U;
            aOrbiterG = (((aWandererA + RotL64(aScatter, 41U)) + RotL64(aCarry, 37U)) + 3899614406903883035U) + aNonceWordH;
            aOrbiterE = (((aWandererD + RotL64(aCross, 60U)) + RotL64(aCarry, 43U)) + 8159156925629965143U) + aNonceWordL;
            aOrbiterD = (aWandererC + RotL64(aPrevious, 51U)) + 7148903913967261270U;
            aOrbiterK = ((aWandererE + RotL64(aCross, 5U)) + 9161665622287517848U) + aNonceWordA;
            aOrbiterB = (aWandererF + RotL64(aScatter, 27U)) + 2981535013474059469U;
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 48U)) + 15812469008200319549U;
            aOrbiterI = (aWandererK + RotL64(aScatter, 3U)) + 14687469489893270300U;
            aOrbiterC = ((aWandererG + RotL64(aIngress, 37U)) + 6025209349511417063U) + aNonceWordP;
            aOrbiterA = ((aWandererH + RotL64(aCross, 29U)) + 12964750392311112676U) + aPhaseEOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 6572355895765394340U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 3542300121890027981U;
            aOrbiterG = RotL64((aOrbiterG * 11201491178181273935U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 6477175684045398359U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 1081388388827929314U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8752188637514143529U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 13754328481584620771U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 3684673342659575917U;
            aOrbiterJ = RotL64((aOrbiterJ * 6139923312873039143U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 6542045150319909445U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 5352102692424060388U;
            aOrbiterI = RotL64((aOrbiterI * 7385758355501860261U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 9110100774657340354U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 2813273684436269057U) ^ aNonceWordF;
            aOrbiterE = RotL64((aOrbiterE * 10468759062594022273U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 5860425751137403755U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 1598622981888978548U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 651816500461718345U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 14710305692377606725U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 16280545617802383463U;
            aOrbiterH = RotL64((aOrbiterH * 12541767206978802063U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 6849565243667718750U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 12152381961996750050U) ^ aNonceWordO;
            aOrbiterC = RotL64((aOrbiterC * 11185935780063403807U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 1318947876257794796U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 5447559252769140391U;
            aOrbiterB = RotL64((aOrbiterB * 13683733413554766327U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 2766869582494246454U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 15757729967222729304U;
            aOrbiterF = RotL64((aOrbiterF * 1858683399257513171U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 13063432816787882618U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 3650233661228036955U;
            aOrbiterA = RotL64((aOrbiterA * 16230564672533821641U), 39U);
            //
            aIngress = RotL64(aOrbiterD, 36U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterC, 53U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + RotL64(aOrbiterI, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aCross, 46U) + RotL64(aOrbiterF, 39U)) + aOrbiterA) + aNonceWordN) + aPhaseEWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterK, 51U)) + aOrbiterF);
            aWandererK = aWandererK + ((RotL64(aIngress, 5U) + RotL64(aOrbiterD, 47U)) + aOrbiterF);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 37U) + aOrbiterC) + RotL64(aOrbiterG, 35U));
            aWandererA = aWandererA + ((RotL64(aCross, 41U) + RotL64(aOrbiterH, 28U)) + aOrbiterG);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 23U) + aOrbiterB) + RotL64(aOrbiterE, 37U));
            aWandererH = aWandererH + (((RotL64(aScatter, 35U) + RotL64(aOrbiterC, 21U)) + aOrbiterI) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 56U) + RotL64(aOrbiterD, 53U)) + aOrbiterA);
            aWandererE = aWandererE + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterG, 5U)) + aOrbiterB) + RotL64(aCarry, 19U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 43U) + aOrbiterI) + RotL64(aOrbiterE, 13U)) + aNonceWordB);
            aWandererB = aWandererB + (((RotL64(aIngress, 21U) + aOrbiterC) + RotL64(aOrbiterJ, 30U)) + RotL64(aCarry, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 30U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererE, 27U) ^ aWandererH);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 46U));
            aCarry = aCarry + RotL64(aWandererI, 41U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_e loop 5
        // ingress from: aOperationLaneB, aSnowLaneB, aWorkLaneC
        // ingress directions: aOperationLaneB forward forced, aSnowLaneB forward forced, aWorkLaneC forward/backward random
        // cross from: aOperationLaneA, aSnowLaneA
        // cross directions: aOperationLaneA backward forced, aSnowLaneA backward/forward random
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 27270U)) & S_BLOCK1], 44U) ^ RotL64(aSnowLaneB[((aIndex + 23438U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 26248U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 23322U)) & S_BLOCK1], 39U) ^ RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 25403U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aIngress, 19U) + RotL64(aCarry, 36U)) ^ (RotL64(aPrevious, 5U) ^ RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterC = ((aWandererH + RotL64(aIngress, 41U)) + 9855743441035905047U) + aNonceWordL;
            aOrbiterH = (aWandererF + RotL64(aPrevious, 11U)) + 8426286937143990276U;
            aOrbiterG = (aWandererA + RotL64(aScatter, 27U)) + 7146752367170267002U;
            aOrbiterD = (aWandererJ + RotL64(aCross, 29U)) + 12947210066678101726U;
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 43U)) + RotL64(aCarry, 51U)) + 15902163559925328965U;
            aOrbiterA = (aWandererI + RotL64(aCross, 34U)) + 8506649889346449469U;
            aOrbiterI = ((aWandererK + RotL64(aScatter, 13U)) + RotL64(aCarry, 19U)) + 8226286036430263052U;
            aOrbiterE = ((aWandererD + RotL64(aIngress, 3U)) + RotL64(aCarry, 13U)) + 2703047093452420216U;
            aOrbiterJ = (((aWandererG + RotL64(aPrevious, 21U)) + 6769351326360139560U) + aPhaseEOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1]) + aNonceWordB;
            aOrbiterK = (((aWandererB + RotL64(aScatter, 54U)) + 9857025533281333281U) + aPhaseEOrbiterAssignSaltB[((aIndex + 26U)) & S_SALT1]) + aNonceWordN;
            aOrbiterB = (aWandererE + RotL64(aIngress, 37U)) + 238297452132277585U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 7203572312072908931U) + aNonceWordO;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 12497027346166575632U;
            aOrbiterG = RotL64((aOrbiterG * 1703586436725662307U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 473851890609048879U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 1664484956453886047U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8566500756326590209U), 53U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterF) + 4635095143004754116U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordD;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 17695676150967345793U;
            aOrbiterA = RotL64((aOrbiterA * 5780416541584439301U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 15628965269863402796U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 9190117464399730235U;
            aOrbiterD = RotL64((aOrbiterD * 5586437438425999715U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 17835918238346011086U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 4398005402429282682U;
            aOrbiterJ = RotL64((aOrbiterJ * 14828737209913317463U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 10902589938246551273U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 15124274429081385923U;
            aOrbiterE = RotL64((aOrbiterE * 13524180348258805367U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 8747233520702236018U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 5445611443463112371U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10294109295823410447U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 16296005217836151910U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 6468336224317602364U) ^ aNonceWordA;
            aOrbiterH = RotL64((aOrbiterH * 7369779919748367133U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 3827976387089403774U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 7773383658122100111U;
            aOrbiterB = RotL64((aOrbiterB * 9784711300597525161U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 18273794621528918389U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 8401424792700263455U;
            aOrbiterI = RotL64((aOrbiterI * 13003420427441089595U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 11402828934846813949U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 9855743441035905047U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7339549576423555273U), 5U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterJ, 53U);
            aIngress = aIngress + (RotL64(aOrbiterK, 19U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 5U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 11U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 27U));
            aIngress = aIngress + RotL64(aOrbiterF, 58U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 51U) + aOrbiterG) + RotL64(aOrbiterC, 23U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 5U) + aOrbiterE) + RotL64(aOrbiterF, 6U)) + RotL64(aCarry, 57U)) + aNonceWordM);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 26U) + aOrbiterK) + RotL64(aOrbiterF, 29U));
            aWandererI = aWandererI + ((RotL64(aCross, 29U) + aOrbiterB) + RotL64(aOrbiterJ, 3U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 23U) + aOrbiterA) + RotL64(aOrbiterJ, 43U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 39U) + RotL64(aOrbiterB, 51U)) + aOrbiterE) + aPhaseEWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterF, 53U)) + aOrbiterH);
            aWandererA = aWandererA + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterJ, 37U)) + aOrbiterI);
            aWandererG = aWandererG ^ ((((RotL64(aIngress, 44U) + aOrbiterE) + RotL64(aOrbiterD, 35U)) + aNonceWordH) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 35U) + aOrbiterC) + RotL64(aOrbiterE, 41U)) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterB, 56U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererH);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 46U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + (RotL64(aWandererC, 37U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererK, 51U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_e loop 6
        // ingress from: aOperationLaneC, aOperationLaneA, aWorkLaneD
        // ingress directions: aOperationLaneC forward forced, aOperationLaneA forward forced, aWorkLaneD forward/backward random
        // cross from: aOperationLaneB, aInvestLaneB
        // cross directions: aOperationLaneB backward forced, aInvestLaneB backward/forward random
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneC[((aIndex + 29766U)) & S_BLOCK1], 44U) ^ RotL64(aOperationLaneA[((aIndex + 29093U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 29849U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28096U)) & S_BLOCK1], 27U) ^ RotL64(aInvestLaneB[((aIndex + 30541U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCarry, 56U) + RotL64(aPrevious, 11U)) ^ (RotL64(aIngress, 41U) ^ RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterB = ((aWandererB + RotL64(aIngress, 21U)) + RotL64(aCarry, 53U)) + 4068921616130916949U;
            aOrbiterA = (aWandererG + RotL64(aCross, 47U)) + 12077715273915151726U;
            aOrbiterJ = (aWandererJ + RotL64(aScatter, 23U)) + 16047546802670596833U;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 6U)) + 9690277462716999763U) + aNonceWordG;
            aOrbiterF = (aWandererD + RotL64(aIngress, 27U)) + 14484814700447992628U;
            aOrbiterK = ((aWandererI + RotL64(aScatter, 51U)) + 17089267243053958210U) + aNonceWordL;
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 43U)) + RotL64(aCarry, 29U)) + 9138746214446211147U;
            aOrbiterD = (((aWandererE + RotL64(aCross, 60U)) + RotL64(aCarry, 37U)) + 10181001536979097045U) + aPhaseEOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = (aWandererF + RotL64(aScatter, 3U)) + 6657458969093373191U;
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 41U)) + 7515983477876590988U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = ((aWandererA + RotL64(aIngress, 37U)) + 3039935555863947600U) + aNonceWordC;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 16209389224740851136U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 725253312098083182U;
            aOrbiterJ = RotL64((aOrbiterJ * 17535989492095522597U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 13307041115748941383U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 7159572004825238263U) ^ aNonceWordM;
            aOrbiterF = RotL64((aOrbiterF * 4855009895002398449U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 12027236743251643820U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterK) ^ 8717826175991286553U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterI = RotL64((aOrbiterI * 1175614802543098451U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 4769096034227659937U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 11201226563992939616U;
            aOrbiterG = RotL64((aOrbiterG * 15595355978388159931U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 17295978531215563256U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 11850923890626719833U;
            aOrbiterB = RotL64((aOrbiterB * 3854851059897397075U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 14139441565288097706U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 988684899382304485U;
            aOrbiterA = RotL64((aOrbiterA * 11929090869999700891U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 6159251276942253175U) + aNonceWordA;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 4849529993914550651U;
            aOrbiterK = RotL64((aOrbiterK * 18240712676783671317U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 6679745455842119497U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 15838404437552215214U;
            aOrbiterD = RotL64((aOrbiterD * 17357853511591350887U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 15853153471104458948U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 12542164757451566994U;
            aOrbiterC = RotL64((aOrbiterC * 12163611303899312043U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 14304233464055838869U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 4037999346933039765U;
            aOrbiterH = RotL64((aOrbiterH * 564236202758328407U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 3582312827630995454U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 4068921616130916949U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1527829107415867363U), 47U);
            //
            aIngress = RotL64(aOrbiterJ, 23U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterI, 51U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 5U));
            aIngress = aIngress + (RotL64(aOrbiterA, 53U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 42U));
            aIngress = aIngress + RotL64(aOrbiterH, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 5U) + aOrbiterG) + RotL64(aOrbiterI, 23U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 35U) + aOrbiterI) + RotL64(aOrbiterH, 30U)) + aNonceWordK);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 29U) + aOrbiterE) + RotL64(aOrbiterD, 5U));
            aWandererD = aWandererD + (((RotL64(aIngress, 37U) + RotL64(aOrbiterF, 11U)) + aOrbiterA) + RotL64(aCarry, 47U));
            aWandererB = aWandererB ^ ((((RotL64(aScatter, 10U) + aOrbiterJ) + RotL64(aOrbiterK, 41U)) + aNonceWordD) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterD, 19U)) + aOrbiterC);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterF, 53U)) + aOrbiterB);
            aWandererF = aWandererF + (((RotL64(aCross, 53U) + aOrbiterH) + RotL64(aOrbiterG, 48U)) + RotL64(aCarry, 57U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterA, 57U)) + aOrbiterC) + aPhaseEWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 44U) + aOrbiterB) + RotL64(aOrbiterH, 3U)) + aNonceWordI);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 19U) + aOrbiterI) + RotL64(aOrbiterJ, 37U)) + aNonceWordO);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 51U));
            aCarry = aCarry + (RotL64(aWandererD, 24U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 41U));
            aCarry = aCarry + (RotL64(aWandererF, 53U) ^ aWandererK);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + RotL64(aWandererH, 60U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
    [[maybe_unused]] std::uint8_t *aOperationLaneA = pWorkSpace->mOperationLaneA;
    [[maybe_unused]] std::uint8_t *aOperationLaneB = pWorkSpace->mOperationLaneB;
    [[maybe_unused]] std::uint8_t *aOperationLaneC = pWorkSpace->mOperationLaneC;
    [[maybe_unused]] std::uint8_t *aOperationLaneD = pWorkSpace->mOperationLaneD;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x94D00852D674FB8FULL + 0x84AD87127FBB1277ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x8C2E539A1DBFD321ULL + 0x8B0266591E0FEFC5ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xA41458EAC207A2ADULL + 0x837C7E710EDFDDC8ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x905DD24EB029E3BDULL + 0xDCBF3BD890D9C78BULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xB99EA744470296C1ULL + 0xD9819002A6CD8EEBULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xDFF4AB02B4082BBBULL + 0xF05B37B9F65892DFULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xFB0519BEAA2F3731ULL + 0x971B9D8F21A1A792ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x88909501F1791749ULL + 0xC836A030804EC18BULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xB4111870DFC245A5ULL + 0x944285F52FDC2295ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xDD352F6A6E44D937ULL + 0x8FDC4FB4AA4C88FDULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xF676D0AE5A54DF5BULL + 0xCF546D833E4F567CULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xCD3D6FD45E647DA1ULL + 0xFC9C81F75B0409D4ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x93D2DAB268D48A79ULL + 0xF62532B11347FDD3ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xCB9F1A71DCBAF9D3ULL + 0xE1008296E00140E8ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x8AC11DC61443A8E7ULL + 0xF428708F872EDE92ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xC95CB0D1A9EC1807ULL + 0xF44A41C3A14D0189ULL);
    // GSeedRunSeed_F seed_loop_f (start)
    {
        // GSeedRunSeed_F seed_loop_f lane group
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneA, aOperationLaneC, aOperationLaneD, aFireLaneB, aSnowLaneA, aFireLaneC, aFireLaneD, aSnowLaneB, aInvestLaneA, aExpandLaneA, aInvestLaneB, aExpandLaneB, aInvestLaneC, aExpandLaneC, aInvestLaneD
        // write to: aSnowLaneA, aSnowLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_f loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aFireLaneA
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aFireLaneB
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aFireLaneB backward/forward random
        // write to: aSnowLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 4548U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneB[((aIndex + 4766U)) & S_BLOCK1], 4U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 1490U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 2320U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 3920U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 542U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCarry, 6U) + RotL64(aIngress, 51U)) ^ (RotL64(aPrevious, 39U) ^ RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 47U)) + RotL64(aCarry, 35U)) + 16922357079016918108U;
            aOrbiterA = (aWandererD + RotL64(aScatter, 41U)) + 11771749797137599131U;
            aOrbiterG = ((aWandererI + RotL64(aIngress, 57U)) + RotL64(aCarry, 51U)) + 4635668433708036077U;
            aOrbiterC = ((aWandererJ + RotL64(aCross, 13U)) + 15827952719230577008U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = (aWandererG + RotL64(aPrevious, 36U)) + 1495675306110023086U;
            aOrbiterI = ((aWandererH + RotL64(aIngress, 23U)) + 7294835466949728365U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = (aWandererC + RotL64(aCross, 19U)) + 179122461212041978U;
            aOrbiterJ = (((aWandererE + RotL64(aScatter, 53U)) + RotL64(aCarry, 3U)) + 545981421632236251U) + aNonceWordH;
            aOrbiterF = ((aWandererB + RotL64(aIngress, 4U)) + 15338259639814630535U) + aNonceWordL;
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 12924313840290895215U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 17846785921286020610U;
            aOrbiterG = RotL64((aOrbiterG * 18309347016029917133U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 5721472794107057875U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 16359630793856870319U;
            aOrbiterA = RotL64((aOrbiterA * 14186771515526698907U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 10614102110239037308U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 16421992251278236531U;
            aOrbiterB = RotL64((aOrbiterB * 2561232904676068089U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 8668149834861244963U) + aNonceWordO;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 12699331834360948734U;
            aOrbiterJ = RotL64((aOrbiterJ * 2249360824172616357U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 4470693178142950471U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 526000656022724741U;
            aOrbiterI = RotL64((aOrbiterI * 16688501462334673493U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 6880246132270094141U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 7126466778855297013U;
            aOrbiterC = RotL64((aOrbiterC * 5692237926830293205U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 6436404501390442054U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 1213633065612242699U;
            aOrbiterH = RotL64((aOrbiterH * 17604454985534439259U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 8186529105901185854U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 10607460957358250935U;
            aOrbiterE = RotL64((aOrbiterE * 17172191011625677861U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 9743278964993305169U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 14007577681873418075U) ^ aNonceWordN;
            aOrbiterF = RotL64((aOrbiterF * 4231122580398039133U), 19U);
            //
            aIngress = RotL64(aOrbiterA, 28U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 5U));
            aIngress = aIngress + (RotL64(aOrbiterG, 19U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterJ, 51U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterF, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aIngress, 10U) + RotL64(aOrbiterE, 11U)) + aOrbiterI) + RotL64(aCarry, 5U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterG, 43U)) + aOrbiterA);
            aWandererB = aWandererB + (((RotL64(aScatter, 19U) + RotL64(aOrbiterJ, 18U)) + aOrbiterB) + aPhaseFWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 47U) + aOrbiterB) + RotL64(aOrbiterC, 51U)) + aNonceWordG);
            aWandererF = aWandererF + ((RotL64(aIngress, 53U) + RotL64(aOrbiterI, 29U)) + aOrbiterF);
            aWandererE = aWandererE ^ ((((RotL64(aScatter, 4U) + aOrbiterF) + RotL64(aOrbiterA, 39U)) + aNonceWordC) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 41U) + aOrbiterC) + RotL64(aOrbiterI, 3U)) + RotL64(aCarry, 47U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterH, 34U)) + aOrbiterB);
            aWandererC = aWandererC + (((RotL64(aScatter, 57U) + aOrbiterE) + RotL64(aOrbiterF, 47U)) + aNonceWordA);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 50U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 11U));
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererH, 23U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aSnowLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 2
        // ingress from: aSnowLaneA, aOperationLaneC, aOperationLaneD, aFireLaneC
        // ingress directions: aSnowLaneA forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aFireLaneD
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aFireLaneD backward/forward random
        // write to: aSnowLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 8271U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneC[((aIndex + 6500U)) & S_BLOCK1], 39U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 9640U)) & S_BLOCK1], 48U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 8944U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 7578U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 6581U)) & S_BLOCK1], 46U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 9348U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCross, 4U) ^ RotL64(aIngress, 29U)) + (RotL64(aCarry, 41U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterK = (((aWandererI + RotL64(aIngress, 18U)) + RotL64(aCarry, 57U)) + 77518479758428414U) + aNonceWordF;
            aOrbiterC = ((aWandererC + RotL64(aScatter, 39U)) + 4832061802166300011U) + aPhaseFOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = (aWandererK + RotL64(aCross, 13U)) + 11695291171006574112U;
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 29U)) + 7467412817843260094U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 51U)) + 17801484124471154757U) + aNonceWordN;
            aOrbiterI = (((aWandererB + RotL64(aPrevious, 57U)) + RotL64(aCarry, 39U)) + 5555455638503958639U) + aNonceWordL;
            aOrbiterH = ((aWandererD + RotL64(aCross, 47U)) + RotL64(aCarry, 21U)) + 5669470540733721606U;
            aOrbiterG = (aWandererE + RotL64(aIngress, 43U)) + 3042388456327784163U;
            aOrbiterA = (aWandererA + RotL64(aScatter, 6U)) + 2236734925228156691U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 14459720401528685450U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 4814967631216658856U;
            aOrbiterD = RotL64((aOrbiterD * 18288097536171386643U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 16950679344449075945U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 6262238639302011050U;
            aOrbiterJ = RotL64((aOrbiterJ * 9942659897425088183U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 3522256359074996724U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 12524717897707074242U;
            aOrbiterH = RotL64((aOrbiterH * 6787771338063891989U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 13891759914865623828U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterH) ^ 11910250571469028666U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterG = RotL64((aOrbiterG * 12311343917878428995U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 2240189915640314069U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 5365912986308810837U;
            aOrbiterK = RotL64((aOrbiterK * 15133972552032469957U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 9323732721344489753U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 13087326560957916553U;
            aOrbiterI = RotL64((aOrbiterI * 14659491687401151733U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 16398238057564892809U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 11517870519285159224U;
            aOrbiterA = RotL64((aOrbiterA * 1501848878469712681U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 7758285512254776734U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 17475149091906684720U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6015816725428299273U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 2051631493975035243U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterC) ^ 11684740065349595315U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterB = RotL64((aOrbiterB * 10918975496337269197U), 35U);
            //
            aIngress = RotL64(aOrbiterH, 60U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterK, 29U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 23U));
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterD, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aIngress, 54U) + aOrbiterK) + RotL64(aOrbiterD, 13U)) + aNonceWordP);
            aWandererJ = aWandererJ + (((RotL64(aCross, 37U) + RotL64(aOrbiterD, 24U)) + aOrbiterJ) + RotL64(aCarry, 39U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 19U) + aOrbiterA) + RotL64(aOrbiterG, 47U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterH, 29U)) + aOrbiterI);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterD, 53U)) + aOrbiterI) + aNonceWordG);
            aWandererC = aWandererC + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterD, 18U)) + aOrbiterA);
            aWandererI = aWandererI ^ ((((RotL64(aCross, 41U) + RotL64(aOrbiterC, 3U)) + aOrbiterI) + aNonceWordK) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 6U) + aOrbiterB) + RotL64(aOrbiterD, 41U)) + RotL64(aCarry, 29U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 47U) + aOrbiterG) + RotL64(aOrbiterB, 35U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererI);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 44U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + RotL64(aWandererJ, 53U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aSnowLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_f loop 3
        // ingress from: aSnowLaneB, aOperationLaneA, aInvestLaneA
        // ingress directions: aSnowLaneB forward forced, aOperationLaneA forward forced, aInvestLaneA forward/backward random
        // cross from: aSnowLaneA, aOperationLaneC
        // cross directions: aSnowLaneA backward forced, aOperationLaneC backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneB[((aIndex + 15924U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneA[((aIndex + 12029U)) & S_BLOCK1], 38U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 13739U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 16122U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 15070U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aIngress, 43U)) + (RotL64(aPrevious, 57U) ^ RotL64(aCross, 28U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 6U)) + 12206125048349568300U) + aPhaseFOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = (((aWandererG + RotL64(aIngress, 27U)) + RotL64(aCarry, 13U)) + 5843520589343188818U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = (aWandererI + RotL64(aCross, 35U)) + 12195046124287121687U;
            aOrbiterJ = ((aWandererB + RotL64(aScatter, 53U)) + RotL64(aCarry, 39U)) + 16769779119214020640U;
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 23U)) + 5257603646260695833U) + aNonceWordC;
            aOrbiterE = ((aWandererH + RotL64(aCross, 39U)) + 8523523946234886745U) + aNonceWordD;
            aOrbiterA = ((aWandererA + RotL64(aScatter, 57U)) + 7316024684200084096U) + aNonceWordL;
            aOrbiterD = (aWandererE + RotL64(aIngress, 10U)) + 11996978575084115207U;
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 47U)) + RotL64(aCarry, 53U)) + 15491711479085513628U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 6036648530996821484U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 926323222234121863U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6639661141258803779U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 2700323841295743492U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 5852273765810284935U;
            aOrbiterE = RotL64((aOrbiterE * 16665696735016345215U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 11697397483133538067U) + aNonceWordN;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 17777142964957007194U;
            aOrbiterK = RotL64((aOrbiterK * 6338967222543284999U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 10892176201151170298U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 11759700374509499684U) ^ aNonceWordI;
            aOrbiterA = RotL64((aOrbiterA * 14247697264744736081U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 11343756773329590643U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 15785048929757652350U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17208103574389502597U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 7508839228498497238U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 13088508510402094665U;
            aOrbiterC = RotL64((aOrbiterC * 15730279447009669103U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 16259236641717377699U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 11228995722951003980U;
            aOrbiterG = RotL64((aOrbiterG * 4870092259515181323U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 13775851561528617086U) + aNonceWordG;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 3023564646900497080U;
            aOrbiterF = RotL64((aOrbiterF * 9936548213275464131U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 154952467284609583U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 14239675888632174461U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1370550680736926425U), 3U);
            //
            aIngress = RotL64(aOrbiterA, 51U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 54U));
            aIngress = aIngress + (RotL64(aOrbiterF, 35U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 43U));
            aIngress = aIngress + RotL64(aOrbiterK, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aCross, 43U) + aOrbiterA) + RotL64(aOrbiterF, 60U));
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 23U) + aOrbiterG) + RotL64(aOrbiterJ, 35U)) + aNonceWordO) + aPhaseFWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aScatter, 52U) + RotL64(aOrbiterD, 19U)) + aOrbiterB) + RotL64(aCarry, 39U)) + aNonceWordA);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterE, 47U)) + aOrbiterD);
            aWandererG = aWandererG + ((RotL64(aScatter, 27U) + aOrbiterD) + RotL64(aOrbiterG, 23U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 19U) + aOrbiterF) + RotL64(aOrbiterB, 3U));
            aWandererI = aWandererI + ((RotL64(aIngress, 60U) + aOrbiterC) + RotL64(aOrbiterB, 27U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 47U) + aOrbiterK) + RotL64(aOrbiterE, 12U)) + aPhaseFWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 5U) + RotL64(aOrbiterA, 41U)) + aOrbiterB) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 56U));
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererJ);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + RotL64(aWandererA, 47U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 4
        // ingress from: aExpandLaneA, aSnowLaneA, aInvestLaneB
        // ingress directions: aExpandLaneA forward forced, aSnowLaneA forward forced, aInvestLaneB forward/backward random
        // cross from: aSnowLaneB, aOperationLaneD
        // cross directions: aSnowLaneB backward forced, aOperationLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 17198U)) & S_BLOCK1], 50U) ^ RotL64(aSnowLaneA[((aIndex + 16819U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aInvestLaneB[((aIndex + 19148U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 21215U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 20882U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 27U) + RotL64(aCarry, 40U)) ^ (RotL64(aCross, 53U) ^ RotL64(aIngress, 13U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterG = ((aWandererE + RotL64(aIngress, 47U)) + 3238389262925516513U) + aNonceWordE;
            aOrbiterC = ((aWandererK + RotL64(aCross, 35U)) + RotL64(aCarry, 51U)) + 12381787182611386995U;
            aOrbiterH = (aWandererC + RotL64(aScatter, 22U)) + 7883885539305181549U;
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 57U)) + 1185413044597727092U) + aNonceWordM;
            aOrbiterI = ((aWandererD + RotL64(aCross, 29U)) + 15219353497204773135U) + aPhaseFOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 11U)) + RotL64(aCarry, 11U)) + 7533774715626734082U;
            aOrbiterE = (aWandererB + RotL64(aIngress, 6U)) + 2599930450937763464U;
            aOrbiterB = (((aWandererA + RotL64(aScatter, 53U)) + RotL64(aCarry, 37U)) + 16074720663961214284U) + aPhaseFOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = ((aWandererH + RotL64(aPrevious, 43U)) + 15483613196360051221U) + aNonceWordB;
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 9396557867081376268U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 9668459976852660245U) ^ aNonceWordI;
            aOrbiterH = RotL64((aOrbiterH * 11748505665890567063U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 9037269914643207212U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 16936742640861088240U;
            aOrbiterI = RotL64((aOrbiterI * 1040172193161012227U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 16481274825758546398U) + aNonceWordD;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 481851372837611166U;
            aOrbiterE = RotL64((aOrbiterE * 2225030139210599207U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 13608921517203544108U) + aNonceWordH;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 16930740723286214636U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2605108503821980865U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 902242902582149908U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 1510861213079342977U;
            aOrbiterJ = RotL64((aOrbiterJ * 3309753895727400707U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 7116243600304980310U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 6631412278359709602U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11452627691392637463U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 9246698682265275165U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 8594373032014031450U;
            aOrbiterB = RotL64((aOrbiterB * 2550138341089957033U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 15912837963877821048U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 11404583513022627609U;
            aOrbiterD = RotL64((aOrbiterD * 17715204726760125357U), 27U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterE) + 17295214920690244319U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1]) + aNonceWordN;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 18315664494984189344U;
            aOrbiterG = RotL64((aOrbiterG * 17398893532076312945U), 57U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterI, 54U);
            aIngress = aIngress + (RotL64(aOrbiterB, 39U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterE, 5U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterH, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterK, 34U)) + aOrbiterE);
            aWandererK = aWandererK + (((RotL64(aIngress, 35U) + RotL64(aOrbiterD, 5U)) + aOrbiterE) + aNonceWordP);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 4U) + aOrbiterG) + RotL64(aOrbiterH, 57U)) + aNonceWordC);
            aWandererA = aWandererA + (((RotL64(aScatter, 29U) + RotL64(aOrbiterC, 19U)) + aOrbiterH) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 43U) + aOrbiterD) + RotL64(aOrbiterB, 47U));
            aWandererD = aWandererD + ((((RotL64(aIngress, 53U) + aOrbiterH) + RotL64(aOrbiterK, 41U)) + RotL64(aCarry, 27U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 10U) + RotL64(aOrbiterI, 27U)) + aOrbiterD);
            aWandererE = aWandererE + (((RotL64(aScatter, 47U) + aOrbiterH) + RotL64(aOrbiterI, 23U)) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 57U) + aOrbiterJ) + RotL64(aOrbiterB, 10U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererA);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 6U));
            aCarry = aCarry + RotL64(aWandererC, 43U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_f loop 5
        // ingress from: aExpandLaneB, aSnowLaneB, aInvestLaneC
        // ingress directions: aExpandLaneB forward forced, aSnowLaneB forward forced, aInvestLaneC forward/backward random
        // cross from: aExpandLaneA, aSnowLaneA
        // cross directions: aExpandLaneA backward forced, aSnowLaneA backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 24820U)) & S_BLOCK1], 13U) ^ RotL64(aSnowLaneB[((aIndex + 26000U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 26762U)) & S_BLOCK1], 54U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23564U)) & S_BLOCK1], 24U) ^ RotL64(aSnowLaneA[((aIndex + 23450U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aPrevious, 3U) + RotL64(aCarry, 51U)) ^ (RotL64(aCross, 19U) ^ RotL64(aIngress, 36U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterE = ((aWandererE + RotL64(aIngress, 5U)) + 6342299552323486695U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = (aWandererC + RotL64(aScatter, 60U)) + 12692748514781367538U;
            aOrbiterI = (((aWandererG + RotL64(aPrevious, 19U)) + RotL64(aCarry, 57U)) + 8202639945493229155U) + aNonceWordH;
            aOrbiterH = (aWandererA + RotL64(aCross, 43U)) + 4439975701793231639U;
            aOrbiterG = (aWandererH + RotL64(aIngress, 11U)) + 16774235182859553759U;
            aOrbiterF = ((aWandererK + RotL64(aScatter, 47U)) + RotL64(aCarry, 39U)) + 8764155413335405667U;
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 26U)) + 7167848811974967685U) + aNonceWordB;
            aOrbiterJ = (((aWandererF + RotL64(aCross, 51U)) + RotL64(aCarry, 5U)) + 16768278912125334220U) + aPhaseFOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = (aWandererI + RotL64(aPrevious, 39U)) + 9090838954826296201U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 7644075729758006298U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 17326182797908071215U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2408330168749256075U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 16158809721888137555U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 8029938783858263694U;
            aOrbiterG = RotL64((aOrbiterG * 12628072435324195483U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 8716553521415553404U) + aNonceWordO;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 7012599977009208840U;
            aOrbiterC = RotL64((aOrbiterC * 8775355876188948851U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 13250558696578541499U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 13705957059101025396U;
            aOrbiterJ = RotL64((aOrbiterJ * 16889495686487056367U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 2796775206291902461U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 13741676263512390669U;
            aOrbiterE = RotL64((aOrbiterE * 10455782033465595947U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 1691908360612389252U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 4114939415206031540U;
            aOrbiterD = RotL64((aOrbiterD * 2797401802892718297U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 2374911514440738727U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 12377616933668803091U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2505164835116651215U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 681094033415259645U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 13841322124900463362U;
            aOrbiterF = RotL64((aOrbiterF * 4210414203856902329U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 18082983557580381338U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 15731122225678626778U) ^ aNonceWordM;
            aOrbiterH = RotL64((aOrbiterH * 7785999919955613789U), 27U);
            //
            aIngress = RotL64(aOrbiterF, 3U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 53U));
            aIngress = aIngress + (RotL64(aOrbiterI, 13U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 58U));
            aIngress = aIngress + RotL64(aOrbiterE, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aIngress, 43U) + aOrbiterI) + RotL64(aOrbiterF, 56U)) + aNonceWordK);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 60U) + RotL64(aOrbiterG, 29U)) + aOrbiterI);
            aWandererH = aWandererH + ((((RotL64(aCross, 35U) + RotL64(aOrbiterF, 13U)) + aOrbiterH) + aNonceWordN) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 13U) + aOrbiterD) + RotL64(aOrbiterH, 35U));
            aWandererE = aWandererE + (((RotL64(aScatter, 5U) + RotL64(aOrbiterJ, 39U)) + aOrbiterC) + RotL64(aCarry, 47U));
            aWandererA = aWandererA ^ ((((RotL64(aPrevious, 29U) + aOrbiterA) + RotL64(aOrbiterC, 60U)) + aNonceWordA) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 47U) + aOrbiterA) + RotL64(aOrbiterJ, 43U)) + RotL64(aCarry, 27U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 56U) + aOrbiterF) + RotL64(aOrbiterJ, 23U));
            aWandererI = aWandererI + (((RotL64(aScatter, 23U) + aOrbiterA) + RotL64(aOrbiterE, 51U)) + aNonceWordC);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + (RotL64(aWandererC, 50U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererB, 29U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 6
        // ingress from: aExpandLaneC, aExpandLaneA, aInvestLaneD
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aInvestLaneD forward/backward random
        // cross from: aExpandLaneB, aOperationLaneB
        // cross directions: aExpandLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 30037U)) & S_BLOCK1], 36U) ^ RotL64(aExpandLaneA[((aIndex + 29866U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aInvestLaneD[((aIndex + 31301U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30284U)) & S_BLOCK1], 44U) ^ RotL64(aOperationLaneB[((aIndex + 28190U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 21U) ^ RotL64(aCross, 34U)) + (RotL64(aCarry, 5U) + RotL64(aIngress, 47U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterI = ((aWandererA + RotL64(aIngress, 22U)) + 8101351470141807662U) + aPhaseFOrbiterAssignSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = (aWandererD + RotL64(aPrevious, 53U)) + 6965474099521076705U;
            aOrbiterH = (aWandererG + RotL64(aCross, 27U)) + 6803828268885684784U;
            aOrbiterB = ((aWandererC + RotL64(aScatter, 57U)) + RotL64(aCarry, 43U)) + 13454235922950972488U;
            aOrbiterC = (((aWandererK + RotL64(aPrevious, 47U)) + RotL64(aCarry, 13U)) + 11678091885751244777U) + aNonceWordI;
            aOrbiterK = (aWandererH + RotL64(aIngress, 43U)) + 5307134544628507141U;
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 6U)) + 4873703518950429353U) + aPhaseFOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = ((aWandererI + RotL64(aCross, 37U)) + 8542156221858586039U) + aNonceWordE;
            aOrbiterF = ((aWandererE + RotL64(aIngress, 13U)) + RotL64(aCarry, 5U)) + 3993726182905296513U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 12113047622035464386U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 1944244448665721151U;
            aOrbiterH = RotL64((aOrbiterH * 7010050836758762003U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 12914188029425467576U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 2486762763475327024U;
            aOrbiterK = RotL64((aOrbiterK * 12319769994433811617U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 14580191602982245481U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 12093414832400135066U;
            aOrbiterG = RotL64((aOrbiterG * 12720286833215690663U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 13623906997320021065U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 9977356009806428696U;
            aOrbiterI = RotL64((aOrbiterI * 2005536391712733499U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 3694954095397810851U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 11453812627797091638U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13730420725113907161U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 542311345544726351U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 3024285045990499484U) ^ aNonceWordH;
            aOrbiterA = RotL64((aOrbiterA * 5153745952148205645U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 15397664082460849530U) + aNonceWordM;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 10716856680110815056U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13947203772929252823U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 833342121331428547U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 1111339940097269219U;
            aOrbiterF = RotL64((aOrbiterF * 17991642769781175473U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 9312963978841402871U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 8225496710723213204U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 894499195498817065U), 39U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterF, 5U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 48U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 43U));
            aIngress = aIngress + (RotL64(aOrbiterC, 13U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterB, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aIngress, 10U) + RotL64(aOrbiterG, 13U)) + aOrbiterC);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 35U) + aOrbiterG) + RotL64(aOrbiterB, 53U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 47U) + RotL64(aOrbiterH, 29U)) + aOrbiterA);
            aWandererI = aWandererI ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterB, 44U)) + aOrbiterA) + aNonceWordB);
            aWandererH = aWandererH + ((((RotL64(aScatter, 41U) + RotL64(aOrbiterE, 23U)) + aOrbiterA) + RotL64(aCarry, 13U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterK, 19U)) + aOrbiterI);
            aWandererE = aWandererE + ((((RotL64(aIngress, 29U) + aOrbiterF) + RotL64(aOrbiterI, 57U)) + aNonceWordP) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterC, 3U)) + aOrbiterB);
            aWandererA = aWandererA + (((RotL64(aIngress, 52U) + aOrbiterG) + RotL64(aOrbiterF, 48U)) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 26U));
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
    [[maybe_unused]] std::uint8_t *aOperationLaneA = pWorkSpace->mOperationLaneA;
    [[maybe_unused]] std::uint8_t *aOperationLaneB = pWorkSpace->mOperationLaneB;
    [[maybe_unused]] std::uint8_t *aOperationLaneC = pWorkSpace->mOperationLaneC;
    [[maybe_unused]] std::uint8_t *aOperationLaneD = pWorkSpace->mOperationLaneD;
    [[maybe_unused]] std::uint8_t *aSnowLaneA = pWorkSpace->mSnowLaneA;
    [[maybe_unused]] std::uint8_t *aSnowLaneB = pWorkSpace->mSnowLaneB;
    [[maybe_unused]] std::uint8_t *aSnowLaneC = pWorkSpace->mSnowLaneC;
    [[maybe_unused]] std::uint8_t *aSnowLaneD = pWorkSpace->mSnowLaneD;
    [[maybe_unused]] std::uint8_t *aFireLaneA = pWorkSpace->mFireLaneA;
    [[maybe_unused]] std::uint8_t *aFireLaneB = pWorkSpace->mFireLaneB;
    [[maybe_unused]] std::uint8_t *aFireLaneC = pWorkSpace->mFireLaneC;
    [[maybe_unused]] std::uint8_t *aFireLaneD = pWorkSpace->mFireLaneD;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xF2F320B612747AD5ULL + 0xB8856C8F7DBEF404ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xD62DA0E2C3B8BC73ULL + 0xDD5A1A6615F4E335ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xCAF520197882C715ULL + 0xA8012CFDBC18F03CULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xA1808355C10642D5ULL + 0xAE87198F40798ABCULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xFC7AF43224F5928FULL + 0xA028B09C5E637D6DULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xDD1E3290836C842BULL + 0xD82826B856550CC3ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x8FCF3642C3BB645BULL + 0xD38659EF13AAF933ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xF12B35109E0B7299ULL + 0xED7DA46DC8B98C84ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xDBA4A05B5BFBF50DULL + 0x956533BAC6F530B7ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xC4D5613FE2B69C01ULL + 0x92FF92832025AB7CULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x9A8B01366EECF147ULL + 0x96538900B24AAFBAULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xB7811D592369D09BULL + 0xA8DC66307B68B6E6ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xE982FAE0DC4696B7ULL + 0xAC4D48F8625C85B8ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xBC05034A07F78105ULL + 0xE90AB72EEC8C7DB2ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x9D4B4BEAF0F2B311ULL + 0xA7290B62520CFA96ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xF4647C0336518A53ULL + 0x87C43B935D3AB4BDULL);
    // GSeedRunSeed_G seed_loop_h (start)
    {
        // GSeedRunSeed_G seed_loop_h lane group
        // read from: aSnowLaneA, aSnowLaneB, aFireLaneA, aSnowLaneC, aSnowLaneD, aFireLaneB, aWorkLaneA, aFireLaneC, aFireLaneD, aWorkLaneB, aOperationLaneA, aExpandLaneA, aOperationLaneB, aExpandLaneB, aOperationLaneC, aExpandLaneC, aOperationLaneD
        // write to: aWorkLaneA, aWorkLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_h loop 1
        // ingress from: aSnowLaneA, aSnowLaneB, aFireLaneA
        // ingress directions: aSnowLaneA forward forced, aSnowLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aSnowLaneC, aSnowLaneD, aFireLaneB
        // cross directions: aSnowLaneC backward forced, aSnowLaneD backward forced, aFireLaneB backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 4513U)) & S_BLOCK1], 23U) ^ RotL64(aSnowLaneB[((aIndex + 2381U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 712U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 488U)) & S_BLOCK1], 44U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 3472U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 4537U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCross, 51U) ^ RotL64(aIngress, 39U)) + (RotL64(aPrevious, 24U) + RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 56U)) + RotL64(aCarry, 3U)) + 2558105147674438050U;
            aOrbiterH = (((aWandererA + RotL64(aScatter, 13U)) + RotL64(aCarry, 51U)) + 15856662514774702561U) + aPhaseHOrbiterAssignSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = (aWandererF + RotL64(aCross, 27U)) + 13346869226246584582U;
            aOrbiterK = (aWandererB + RotL64(aPrevious, 19U)) + 7632111846116243973U;
            aOrbiterA = ((aWandererK + RotL64(aCross, 35U)) + 2102101361626976279U) + aNonceWordG;
            aOrbiterC = (((aWandererC + RotL64(aPrevious, 3U)) + RotL64(aCarry, 21U)) + 5605968705067851563U) + aNonceWordC;
            aOrbiterG = (((aWandererG + RotL64(aIngress, 43U)) + 6842483186584326681U) + aPhaseHOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1]) + aNonceWordP;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 5559797213819425064U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 12422313931331576759U;
            aOrbiterI = RotL64((aOrbiterI * 7399849122565913401U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 2751024420047872601U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 11031320239359798610U;
            aOrbiterA = RotL64((aOrbiterA * 8607639453141148025U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 14366375309473793217U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 11971479429768505316U) ^ aNonceWordB;
            aOrbiterC = RotL64((aOrbiterC * 10063001532313098203U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 3947595951884469542U) + aNonceWordN;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 17882767922372770896U;
            aOrbiterK = RotL64((aOrbiterK * 3361906348965810211U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 513871456983509223U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 5951677013597794294U;
            aOrbiterH = RotL64((aOrbiterH * 8508629569649935293U), 29U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterC) + 437626309049021931U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1]) + aNonceWordM;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 466674061172005705U;
            aOrbiterJ = RotL64((aOrbiterJ * 1310502572084891157U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 12362602809233133718U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 10525852878882195702U;
            aOrbiterG = RotL64((aOrbiterG * 17755022180514914325U), 11U);
            //
            aIngress = RotL64(aOrbiterK, 11U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 27U));
            aIngress = aIngress + RotL64(aOrbiterH, 34U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aCross, 43U) + RotL64(aOrbiterJ, 13U)) + aOrbiterK);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterG, 54U)) + aOrbiterA);
            aWandererC = aWandererC + ((((RotL64(aIngress, 19U) + aOrbiterI) + RotL64(aOrbiterA, 21U)) + RotL64(aCarry, 51U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 50U) + aOrbiterH) + RotL64(aOrbiterJ, 43U)) + aNonceWordO);
            aWandererB = aWandererB + ((((RotL64(aIngress, 3U) + aOrbiterA) + RotL64(aOrbiterK, 27U)) + aNonceWordJ) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterC, 5U)) + aOrbiterH);
            aWandererH = aWandererH + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterJ, 35U)) + aOrbiterG) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 37U));
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 56U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererF, 29U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 2
        // ingress from: aWorkLaneA, aSnowLaneC, aSnowLaneD, aFireLaneC
        // ingress directions: aWorkLaneA forward forced, aSnowLaneC forward forced, aSnowLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aSnowLaneA, aSnowLaneB, aFireLaneD
        // cross directions: aSnowLaneA backward forced, aSnowLaneB backward forced, aFireLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 8659U)) & S_BLOCK1], 19U) ^ RotL64(aSnowLaneC[((aIndex + 5996U)) & S_BLOCK1], 11U));
            aIngress ^= (RotL64(aSnowLaneD[((aIndex + 7592U)) & S_BLOCK1], 42U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 8941U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 5926U)) & S_BLOCK1], 56U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 9363U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 7289U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 41U) + RotL64(aCross, 24U)) ^ (RotL64(aCarry, 3U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterK = (aWandererI + RotL64(aScatter, 11U)) + 9888431329297626900U;
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 58U)) + RotL64(aCarry, 21U)) + 2937735167534624403U;
            aOrbiterE = ((aWandererB + RotL64(aIngress, 19U)) + 17626022970343789617U) + aNonceWordH;
            aOrbiterI = ((aWandererC + RotL64(aCross, 37U)) + 5665660859333693743U) + aNonceWordO;
            aOrbiterC = ((((aWandererK + RotL64(aScatter, 3U)) + RotL64(aCarry, 37U)) + 1060537034632076669U) + aPhaseHOrbiterAssignSaltC[((aIndex + 18U)) & S_SALT1]) + aNonceWordN;
            aOrbiterD = ((aWandererF + RotL64(aIngress, 43U)) + 743777763907175800U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = ((aWandererD + RotL64(aCross, 51U)) + RotL64(aCarry, 57U)) + 5744905970181808845U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 3545351394494002180U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 4877547088414106007U;
            aOrbiterE = RotL64((aOrbiterE * 5416792889338547109U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 11669378338379598445U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 2961072441706158212U;
            aOrbiterC = RotL64((aOrbiterC * 2677988507090705371U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 13984945589234919765U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 1433097875470903205U) ^ aNonceWordM;
            aOrbiterB = RotL64((aOrbiterB * 451996840039906781U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 716415411025451152U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 8542286150858297810U;
            aOrbiterD = RotL64((aOrbiterD * 9139015340823332449U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 12932391786479661299U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 14005503313299177013U) ^ aNonceWordA;
            aOrbiterK = RotL64((aOrbiterK * 802663466907819743U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 9382792812676318046U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 5138554251079724724U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6386016499265056247U), 35U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterK) + 8522380066269546172U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordE;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 11825536408101906458U;
            aOrbiterI = RotL64((aOrbiterI * 17042837108792016849U), 13U);
            //
            aIngress = RotL64(aOrbiterD, 5U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 29U));
            aIngress = aIngress + RotL64(aOrbiterE, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aScatter, 3U) + aOrbiterB) + RotL64(aOrbiterI, 57U)) + aNonceWordD);
            aWandererB = aWandererB ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterE, 35U)) + aOrbiterI) + aPhaseHWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 12U) + RotL64(aOrbiterE, 41U)) + aOrbiterK) + RotL64(aCarry, 5U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterK, 21U)) + aOrbiterJ) + aNonceWordB);
            aWandererF = aWandererF + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterJ, 51U)) + aOrbiterE) + aNonceWordF);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterD, 29U)) + aOrbiterK) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 35U) + aOrbiterC) + RotL64(aOrbiterD, 12U)) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 24U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 53U));
            aCarry = aCarry + RotL64(aWandererF, 35U);
            aCarry = aCarry + RotL64(aIngress, 48U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_h loop 3
        // ingress from: aWorkLaneB, aSnowLaneA, aOperationLaneA
        // ingress directions: aWorkLaneB forward forced, aSnowLaneA forward forced, aOperationLaneA forward/backward random
        // cross from: aWorkLaneA, aSnowLaneC
        // cross directions: aWorkLaneA backward forced, aSnowLaneC backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 15261U)) & S_BLOCK1], 27U) ^ RotL64(aSnowLaneA[((aIndex + 14620U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 14574U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13453U)) & S_BLOCK1], 11U) ^ RotL64(aSnowLaneC[((aIndex + 16337U)) & S_BLOCK1], 26U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCross, 35U) ^ RotL64(aIngress, 21U)) ^ (RotL64(aCarry, 53U) + RotL64(aPrevious, 4U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 29U)) + RotL64(aCarry, 3U)) + 8866844335448071821U;
            aOrbiterG = ((aWandererC + RotL64(aScatter, 56U)) + 15159698739856430085U) + aNonceWordP;
            aOrbiterB = (((aWandererD + RotL64(aIngress, 47U)) + RotL64(aCarry, 37U)) + 9582805772989594633U) + aNonceWordC;
            aOrbiterA = ((aWandererA + RotL64(aCross, 41U)) + RotL64(aCarry, 53U)) + 1438538239931588373U;
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 11U)) + 10862044156620436139U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = (aWandererI + RotL64(aScatter, 5U)) + 13682173320058164615U;
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 35U)) + 8351013291045977592U) + aPhaseHOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1];
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 15777857431516633916U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 16178966745333885377U) ^ aNonceWordO;
            aOrbiterB = RotL64((aOrbiterB * 7545129923202147703U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 9031889187993001617U) + aNonceWordK;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 6308472367425865347U;
            aOrbiterJ = RotL64((aOrbiterJ * 17118710301967158153U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 642109145903321046U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 9186268569255318035U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10714674348507516749U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 6091345356803675860U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 13218507921880873749U;
            aOrbiterH = RotL64((aOrbiterH * 15415157927185637717U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 4266652275234474616U) + aNonceWordB;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 4391422098164506195U;
            aOrbiterF = RotL64((aOrbiterF * 17634679403195085867U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 5160682323243635577U) + aNonceWordE;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 10351728852161347404U;
            aOrbiterA = RotL64((aOrbiterA * 11105410036471745951U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 3950932176454814023U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 9536466386833427441U;
            aOrbiterG = RotL64((aOrbiterG * 18064984243491293435U), 47U);
            //
            aIngress = RotL64(aOrbiterH, 37U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterK, 12U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 5U));
            aIngress = aIngress + RotL64(aOrbiterF, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aScatter, 5U) + RotL64(aOrbiterF, 37U)) + aOrbiterA) + aNonceWordF);
            aWandererD = aWandererD ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterA, 43U)) + aOrbiterG) + aNonceWordL);
            aWandererI = aWandererI + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterB, 56U)) + aOrbiterK) + aPhaseHWandererUpdateSaltF[((aIndex + 8U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 46U) + aOrbiterH) + RotL64(aOrbiterF, 21U));
            aWandererC = aWandererC + ((((RotL64(aScatter, 23U) + aOrbiterK) + RotL64(aOrbiterH, 3U)) + RotL64(aCarry, 27U)) + aNonceWordJ);
            aWandererG = aWandererG ^ ((((RotL64(aIngress, 57U) + aOrbiterG) + RotL64(aOrbiterF, 11U)) + aNonceWordH) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 29U) + aOrbiterA) + RotL64(aOrbiterJ, 27U)) + RotL64(aCarry, 13U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 50U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 37U));
            aCarry = aCarry + RotL64(aWandererA, 11U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 4
        // ingress from: aExpandLaneA, aWorkLaneA, aOperationLaneB
        // ingress directions: aExpandLaneA forward forced, aWorkLaneA forward forced, aOperationLaneB forward/backward random
        // cross from: aWorkLaneB, aSnowLaneD
        // cross directions: aWorkLaneB backward forced, aSnowLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 19273U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneA[((aIndex + 19377U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aOperationLaneB[((aIndex + 18302U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21347U)) & S_BLOCK1], 35U) ^ RotL64(aSnowLaneD[((aIndex + 20031U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aIngress, 21U) ^ RotL64(aCross, 5U)) ^ (RotL64(aPrevious, 38U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterG = (((aWandererF + RotL64(aScatter, 51U)) + RotL64(aCarry, 39U)) + 17936518874386450467U) + aNonceWordD;
            aOrbiterK = ((aWandererI + RotL64(aCross, 43U)) + 13722737841589910344U) + aNonceWordC;
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 19U)) + 11774969167948715796U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 13U)) + 3640101505680493777U) + aPhaseHOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = ((aWandererD + RotL64(aIngress, 37U)) + RotL64(aCarry, 57U)) + 1369495382725650822U;
            aOrbiterI = (((aWandererH + RotL64(aPrevious, 58U)) + RotL64(aCarry, 27U)) + 11827310354654653345U) + aNonceWordN;
            aOrbiterE = (aWandererB + RotL64(aScatter, 29U)) + 186037671377175394U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 11428829344234627340U) + aNonceWordF;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 2275016369870029068U;
            aOrbiterJ = RotL64((aOrbiterJ * 14936799202145280833U), 53U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterA) + 15471646673734798328U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordL;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 12172082573115640145U;
            aOrbiterI = RotL64((aOrbiterI * 9629417882787847753U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 6626736341348283154U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 12220614992483863623U;
            aOrbiterE = RotL64((aOrbiterE * 8137086205714097487U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 13157102324253760215U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 4143587482368093601U;
            aOrbiterK = RotL64((aOrbiterK * 5060677690991506895U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 11007575246013796426U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 11721585930088637162U;
            aOrbiterG = RotL64((aOrbiterG * 15009627907125738519U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 5720789204450196217U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterK) ^ 3094696226821431648U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterH = RotL64((aOrbiterH * 4412033981712165541U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 14675830108100986773U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 9444071495289719645U;
            aOrbiterA = RotL64((aOrbiterA * 10983136361953366557U), 41U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterI, 3U);
            aIngress = aIngress + (RotL64(aOrbiterG, 11U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterK, 41U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterA, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterK, 23U)) + aOrbiterG);
            aWandererI = aWandererI + (((RotL64(aScatter, 21U) + RotL64(aOrbiterA, 29U)) + aOrbiterI) + RotL64(aCarry, 3U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 37U) + RotL64(aOrbiterI, 43U)) + aOrbiterG) + aNonceWordM);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterJ, 35U)) + aOrbiterK) + RotL64(aCarry, 27U)) + aPhaseHWandererUpdateSaltB[((aIndex + 26U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 3U) + aOrbiterG) + RotL64(aOrbiterE, 51U)) + aNonceWordA);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 11U) + aOrbiterJ) + RotL64(aOrbiterA, 58U)) + aNonceWordJ) + aPhaseHWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 46U) + aOrbiterK) + RotL64(aOrbiterH, 3U)) + aNonceWordK);
            //
            aCarry = aCarry + (RotL64(aWandererG, 34U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererF, 27U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererI, 41U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_h loop 5
        // ingress from: aExpandLaneB, aWorkLaneB, aOperationLaneC
        // ingress directions: aExpandLaneB forward forced, aWorkLaneB forward forced, aOperationLaneC forward/backward random
        // cross from: aExpandLaneA, aWorkLaneA
        // cross directions: aExpandLaneA backward forced, aWorkLaneA backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 24741U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneB[((aIndex + 26538U)) & S_BLOCK1], 52U));
            aIngress ^= RotL64(aOperationLaneC[((aIndex + 26639U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27121U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((aIndex + 26701U)) & S_BLOCK1], 10U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aPrevious, 57U)) + (RotL64(aIngress, 10U) ^ RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterA = ((aWandererA + RotL64(aIngress, 47U)) + 13583136155674166402U) + aNonceWordD;
            aOrbiterE = (aWandererF + RotL64(aScatter, 35U)) + 12830472187484919497U;
            aOrbiterJ = ((aWandererH + RotL64(aPrevious, 21U)) + 18081197909484522509U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = (aWandererI + RotL64(aCross, 57U)) + 8680634051297891550U;
            aOrbiterG = ((aWandererK + RotL64(aIngress, 41U)) + RotL64(aCarry, 53U)) + 13939998767458656823U;
            aOrbiterC = ((((aWandererB + RotL64(aScatter, 14U)) + RotL64(aCarry, 29U)) + 1795730579103692594U) + aPhaseHOrbiterAssignSaltF[((aIndex + 8U)) & S_SALT1]) + aNonceWordP;
            aOrbiterD = (((aWandererJ + RotL64(aPrevious, 5U)) + RotL64(aCarry, 5U)) + 17369751719734069999U) + aNonceWordI;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 224769585901248068U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 4133547085925268180U;
            aOrbiterJ = RotL64((aOrbiterJ * 2611561365156544735U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 7022512056309567391U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 10319484359046945495U;
            aOrbiterG = RotL64((aOrbiterG * 3400140531307001933U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 10483878349412282069U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 6481381149199985736U;
            aOrbiterD = RotL64((aOrbiterD * 9701719367082506253U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 13721077228796934509U) + aNonceWordO;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 9704818014314175007U;
            aOrbiterC = RotL64((aOrbiterC * 760445624027740287U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 6253040047758584339U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 16890211690273641226U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5622534399866057841U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 6216227831265032436U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 2023609047004658739U) ^ aNonceWordF;
            aOrbiterE = RotL64((aOrbiterE * 3252332895698310147U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 9201669637050388263U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterI) ^ 5106927540934338576U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterA = RotL64((aOrbiterA * 6368134569042291431U), 51U);
            //
            aIngress = RotL64(aOrbiterE, 44U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterG, 29U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 11U));
            aIngress = aIngress + RotL64(aOrbiterJ, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aIngress, 47U) + RotL64(aOrbiterG, 50U)) + aOrbiterE) + aNonceWordE) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterC, 37U)) + aOrbiterG);
            aWandererH = aWandererH + ((RotL64(aCross, 3U) + aOrbiterJ) + RotL64(aOrbiterA, 3U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 38U) + RotL64(aOrbiterJ, 57U)) + aOrbiterG) + aNonceWordG);
            aWandererI = aWandererI + ((((RotL64(aCross, 13U) + aOrbiterJ) + RotL64(aOrbiterI, 21U)) + RotL64(aCarry, 23U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterG, 27U)) + aOrbiterA);
            aWandererB = aWandererB + (((RotL64(aScatter, 23U) + RotL64(aOrbiterI, 43U)) + aOrbiterD) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererI, 26U) ^ aWandererA);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 41U));
            aCarry = aCarry + RotL64(aWandererF, 53U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 6
        // ingress from: aExpandLaneC, aExpandLaneA, aOperationLaneD
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aOperationLaneD forward/backward random
        // cross from: aExpandLaneB, aSnowLaneB
        // cross directions: aExpandLaneB backward forced, aSnowLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 30948U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneA[((aIndex + 29603U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 30413U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29888U)) & S_BLOCK1], 57U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 27602U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aIngress, 6U)) ^ (RotL64(aCarry, 51U) + RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterF = ((aWandererK + RotL64(aCross, 11U)) + RotL64(aCarry, 39U)) + 16922357079016918108U;
            aOrbiterD = ((aWandererD + RotL64(aScatter, 48U)) + 11771749797137599131U) + aNonceWordP;
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 41U)) + RotL64(aCarry, 51U)) + 4635668433708036077U;
            aOrbiterE = ((aWandererC + RotL64(aIngress, 57U)) + 15827952719230577008U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterK = ((((aWandererJ + RotL64(aScatter, 35U)) + RotL64(aCarry, 3U)) + 1495675306110023086U) + aPhaseHOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1]) + aNonceWordB;
            aOrbiterB = (aWandererA + RotL64(aCross, 27U)) + 7294835466949728365U;
            aOrbiterC = (aWandererE + RotL64(aPrevious, 21U)) + 179122461212041978U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 545981421632236251U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 15338259639814630535U;
            aOrbiterI = RotL64((aOrbiterI * 14895421566334357871U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 12924313840290895215U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 17846785921286020610U;
            aOrbiterK = RotL64((aOrbiterK * 18309347016029917133U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 5721472794107057875U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 16359630793856870319U;
            aOrbiterB = RotL64((aOrbiterB * 14186771515526698907U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 10614102110239037308U) + aNonceWordE;
            aOrbiterC = (((aOrbiterC ^ aOrbiterB) ^ 16421992251278236531U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterC = RotL64((aOrbiterC * 2561232904676068089U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 8668149834861244963U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 12699331834360948734U;
            aOrbiterE = RotL64((aOrbiterE * 2249360824172616357U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 4470693178142950471U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 526000656022724741U) ^ aNonceWordM;
            aOrbiterD = RotL64((aOrbiterD * 16688501462334673493U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 6880246132270094141U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 7126466778855297013U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5692237926830293205U), 35U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterB, 3U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 37U));
            aIngress = aIngress + (RotL64(aOrbiterK, 11U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterF, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 57U) + aOrbiterE) + RotL64(aOrbiterB, 5U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 5U) + RotL64(aOrbiterI, 11U)) + aOrbiterF) + RotL64(aCarry, 3U)) + aNonceWordL);
            aWandererE = aWandererE ^ (((RotL64(aCross, 29U) + aOrbiterK) + RotL64(aOrbiterB, 41U)) + aNonceWordI);
            aWandererD = aWandererD + (((RotL64(aIngress, 11U) + aOrbiterF) + RotL64(aOrbiterD, 35U)) + RotL64(aCarry, 53U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterK, 19U)) + aOrbiterI) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aScatter, 47U) + RotL64(aOrbiterI, 26U)) + aOrbiterB);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 22U) + aOrbiterB) + RotL64(aOrbiterC, 51U)) + aPhaseHWandererUpdateSaltF[((aIndex + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 56U));
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererJ, 29U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD;
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
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltE;
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
        // read from: aKeyRowReadA, aKeyRowReadB, mSource, aFireLaneA, aFireLaneB, aFireLaneC, aFireLaneD, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC
        // write to: aFireLaneA, aFireLaneB, aFireLaneC, aFireLaneD, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // twist_loop_a loop 1
        // ingress from: aKeyRowReadA, aKeyRowReadB
        // ingress directions: aKeyRowReadA forward forced, aKeyRowReadB forward/backward random
        // cross from: aKeyRowReadA, mSource
        // cross directions: aKeyRowReadA backward forced, mSource backward/forward random
        // write to: aFireLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aKeyRowReadA[((aIndex + 151U)) & W_KEY1], 35U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 2600U)) & W_KEY1], 26U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 895U)) & W_KEY1], 26U) ^ RotL64(mSource[((aIndex + 826U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 11U) ^ RotL64(aCross, 41U)) + (RotL64(aCarry, 28U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = (aWandererA + RotL64(aIngress, 43U)) + 1087148170018530502U;
            aOrbiterD = ((aWandererG + RotL64(aCross, 34U)) + 15530846874509311414U) + aPhaseAOrbiterAssignSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = (((aWandererK + RotL64(aScatter, 3U)) + RotL64(aCarry, 13U)) + 16987358651515511212U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = (aWandererC + RotL64(aPrevious, 53U)) + 12504143181007924259U;
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 57U)) + RotL64(aCarry, 29U)) + 393322117322732418U;
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 27U)) + 14325937299241887166U;
            aOrbiterE = (aWandererB + RotL64(aCross, 48U)) + 9395262907017475742U;
            aOrbiterH = (aWandererD + RotL64(aScatter, 11U)) + 13658510441418344769U;
            aOrbiterF = ((aWandererF + RotL64(aCross, 19U)) + RotL64(aCarry, 57U)) + 6410754322737005336U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 9257290738538818434U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 7489828960857692286U;
            aOrbiterC = RotL64((aOrbiterC * 16519674788777989043U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 4118778591214588387U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 16619215231168796563U;
            aOrbiterK = RotL64((aOrbiterK * 14876884956536265157U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 11326283811003573430U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 1865401866017614604U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8378326058282460073U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 670150121105733604U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 1499331510641068749U;
            aOrbiterD = RotL64((aOrbiterD * 16623742535540383107U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 1116410848560838532U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 2696841341036281779U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9598953298074904869U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 5487352391229549881U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 12008243050943342979U;
            aOrbiterH = RotL64((aOrbiterH * 9087261224804582459U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 552859665927882960U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 8426942688524814473U;
            aOrbiterF = RotL64((aOrbiterF * 10916963622695549105U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 1613287981244830815U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 15592897923468694288U;
            aOrbiterI = RotL64((aOrbiterI * 6600750586743893303U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 7629853970631002676U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 13778028957247561272U;
            aOrbiterG = RotL64((aOrbiterG * 4063798788229605659U), 13U);
            //
            aIngress = RotL64(aOrbiterK, 3U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 37U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 23U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 40U));
            aIngress = aIngress + RotL64(aOrbiterH, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aCross, 4U) + aOrbiterC) + RotL64(aOrbiterE, 47U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 51U) + aOrbiterG) + RotL64(aOrbiterD, 56U));
            aWandererF = aWandererF + ((RotL64(aScatter, 57U) + RotL64(aOrbiterK, 21U)) + aOrbiterI);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterI, 3U)) + aOrbiterE);
            aWandererG = aWandererG + ((RotL64(aPrevious, 37U) + aOrbiterD) + RotL64(aOrbiterH, 13U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterF, 38U)) + aOrbiterK) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 47U) + aOrbiterG) + RotL64(aOrbiterJ, 29U)) + RotL64(aCarry, 13U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 30U) + aOrbiterD) + RotL64(aOrbiterF, 43U));
            aWandererD = aWandererD + ((((RotL64(aCross, 41U) + RotL64(aOrbiterE, 51U)) + aOrbiterF) + RotL64(aCarry, 43U)) + aPhaseAWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererA, 13U);
            aCarry = aCarry + RotL64(aIngress, 18U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aFireLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_a loop 2
        // ingress from: aFireLaneA, aKeyRowReadA
        // ingress directions: aFireLaneA forward forced, aKeyRowReadA forward/backward random
        // cross from: aKeyRowReadB, mSource
        // cross directions: aKeyRowReadB backward forced, mSource backward/forward random
        // write to: aFireLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aFireLaneA[((aIndex + 3424U)) & S_BLOCK1], 38U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 4245U)) & W_KEY1], 13U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 3237U)) & W_KEY1], 12U) ^ RotL64(mSource[((aIndex + 5213U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 37U) + RotL64(aPrevious, 5U)) + (RotL64(aCross, 23U) ^ RotL64(aIngress, 50U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = (aWandererA + RotL64(aPrevious, 51U)) + 898812731947995389U;
            aOrbiterF = ((aWandererI + RotL64(aCross, 39U)) + 8677347622525527167U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = (((aWandererG + RotL64(aScatter, 5U)) + RotL64(aCarry, 53U)) + 770321564027567654U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = (aWandererC + RotL64(aIngress, 34U)) + 11020474858081526395U;
            aOrbiterG = (aWandererD + RotL64(aCross, 47U)) + 17289793580414993470U;
            aOrbiterH = (aWandererK + RotL64(aScatter, 29U)) + 10111912559295118444U;
            aOrbiterA = (aWandererB + RotL64(aIngress, 43U)) + 8083622125544542011U;
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 58U)) + RotL64(aCarry, 39U)) + 7149858558922988240U;
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 19U)) + RotL64(aCarry, 13U)) + 5919683821379905699U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 6860902846079238714U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 15083517836867542075U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4686657139237578325U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 14852868368708376381U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 9860233289028878323U;
            aOrbiterH = RotL64((aOrbiterH * 13418143547952204667U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 772406119079116272U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 7971141501337627589U;
            aOrbiterE = RotL64((aOrbiterE * 10168120622976358617U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 8478568022896691911U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 4027604850785607101U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4826627523578901467U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 17199331557841535430U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 7515957656979776361U;
            aOrbiterC = RotL64((aOrbiterC * 5468950152869656599U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 17138249294921502391U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 16236812863923234668U;
            aOrbiterG = RotL64((aOrbiterG * 2925542836624164807U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 16941524155859123682U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 11240343728857342866U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7281012444214294659U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 15163914964139858328U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 6673576554415729652U;
            aOrbiterJ = RotL64((aOrbiterJ * 1558880328574736975U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 5399050402101642989U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 11806006719060024615U;
            aOrbiterA = RotL64((aOrbiterA * 15782156615926092159U), 37U);
            //
            aIngress = RotL64(aOrbiterG, 51U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 22U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 13U));
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterI, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aCross, 51U) + RotL64(aOrbiterI, 10U)) + aOrbiterA);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterF, 27U)) + aOrbiterE) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterC, 57U)) + aOrbiterJ) + RotL64(aCarry, 11U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterA, 23U)) + aOrbiterH);
            aWandererE = aWandererE + ((RotL64(aScatter, 14U) + aOrbiterG) + RotL64(aOrbiterI, 52U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 35U) + aOrbiterA) + RotL64(aOrbiterF, 47U));
            aWandererA = aWandererA + ((((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterA, 19U)) + RotL64(aCarry, 27U)) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterK, 37U)) + aOrbiterC);
            aWandererH = aWandererH + ((RotL64(aIngress, 60U) + aOrbiterK) + RotL64(aOrbiterI, 3U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 50U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererC, 35U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aFireLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_a loop 3
        // ingress from: aFireLaneB, aKeyRowReadB
        // ingress directions: aFireLaneB forward forced, aKeyRowReadB forward/backward random
        // cross from: aKeyRowReadA, mSource, aFireLaneA
        // cross directions: aKeyRowReadA backward forced, mSource backward forced, aFireLaneA backward/forward random
        // write to: aFireLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aFireLaneB[((aIndex + 8110U)) & S_BLOCK1], 20U) ^ RotL64(aKeyRowReadB[((aIndex + 6920U)) & W_KEY1], 57U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 6972U)) & W_KEY1], 41U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 7963U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 7969U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 11U) + RotL64(aPrevious, 57U)) ^ (RotL64(aIngress, 24U) ^ RotL64(aCarry, 43U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = ((aWandererC + RotL64(aIngress, 51U)) + RotL64(aCarry, 41U)) + 12615321415808640429U;
            aOrbiterB = ((aWandererD + RotL64(aScatter, 37U)) + 15712784676459931207U) + aPhaseAOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = ((aWandererA + RotL64(aCross, 56U)) + RotL64(aCarry, 53U)) + 11013335427004930046U;
            aOrbiterD = (aWandererI + RotL64(aPrevious, 21U)) + 8298733856304768806U;
            aOrbiterE = (aWandererE + RotL64(aCross, 11U)) + 6207732959150824216U;
            aOrbiterC = ((aWandererK + RotL64(aIngress, 41U)) + 9769864876127544038U) + aPhaseAOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = (aWandererG + RotL64(aPrevious, 29U)) + 10782181918651152563U;
            aOrbiterJ = ((aWandererB + RotL64(aScatter, 60U)) + RotL64(aCarry, 23U)) + 5790454015845620939U;
            aOrbiterA = (aWandererF + RotL64(aPrevious, 5U)) + 15606578025386733803U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 5522352539991175304U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 5993355818572869649U;
            aOrbiterF = RotL64((aOrbiterF * 15221467311057431139U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 10864534396947622047U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 12090053126235913528U;
            aOrbiterE = RotL64((aOrbiterE * 7250801471645972261U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 14191181677234981396U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 2258570108233924592U;
            aOrbiterB = RotL64((aOrbiterB * 8307541155393855209U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 8448114811381534603U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 2702389315763499817U;
            aOrbiterD = RotL64((aOrbiterD * 6710443836432274393U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 17202184076718780200U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 150549910056015002U;
            aOrbiterI = RotL64((aOrbiterI * 195034681254956335U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 4910512055808124967U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 4783477997418403079U;
            aOrbiterJ = RotL64((aOrbiterJ * 861977492146512865U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 13842899106208709771U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 7930112618036681468U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8609551859830858419U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 8790107242863198659U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 6882768826643279144U;
            aOrbiterG = RotL64((aOrbiterG * 13745521454063360763U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 12136498871759890015U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 8120456314755584336U;
            aOrbiterA = RotL64((aOrbiterA * 1830725195528043575U), 39U);
            //
            aIngress = RotL64(aOrbiterC, 12U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 3U));
            aIngress = aIngress + (RotL64(aOrbiterA, 43U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 39U));
            aIngress = aIngress + RotL64(aOrbiterF, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 10U) + aOrbiterC) + RotL64(aOrbiterF, 21U)) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 5U) + RotL64(aOrbiterB, 28U)) + aOrbiterF) + RotL64(aCarry, 3U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 51U) + aOrbiterA) + RotL64(aOrbiterD, 47U)) + aPhaseAWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 57U) + aOrbiterI) + RotL64(aOrbiterA, 3U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 44U) + aOrbiterG) + RotL64(aOrbiterE, 51U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterB, 11U)) + aOrbiterG);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 35U) + aOrbiterE) + RotL64(aOrbiterJ, 57U));
            aWandererA = aWandererA + (((RotL64(aCross, 19U) + RotL64(aOrbiterJ, 42U)) + aOrbiterI) + RotL64(aCarry, 19U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 23U) + aOrbiterG) + RotL64(aOrbiterF, 37U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 19U));
            aCarry = aCarry + (RotL64(aWandererF, 27U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + RotL64(aWandererD, 6U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aFireLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_a loop 4
        // ingress from: aFireLaneC, aKeyRowReadB, mSource, aFireLaneA
        // ingress directions: aFireLaneC forward forced, aKeyRowReadB forward forced, mSource forward forced, aFireLaneA forward/backward random
        // cross from: aKeyRowReadA, aFireLaneB
        // cross directions: aKeyRowReadA backward forced, aFireLaneB backward/forward random
        // write to: aFireLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aFireLaneC[((aIndex + 10234U)) & S_BLOCK1], 23U) ^ RotL64(aKeyRowReadB[((aIndex + 9402U)) & W_KEY1], 46U));
            aIngress ^= (RotL64(mSource[((aIndex + 8997U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneA[((aIndex + 9229U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 8416U)) & W_KEY1], 20U) ^ RotL64(aFireLaneB[((aIndex + 10106U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 51U) ^ RotL64(aCross, 37U)) + (RotL64(aCarry, 3U) + RotL64(aPrevious, 22U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = (aWandererF + RotL64(aScatter, 23U)) + 12809562813316740345U;
            aOrbiterA = (aWandererK + RotL64(aIngress, 58U)) + 17084212535326321199U;
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 43U)) + 16074921689983846769U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = ((aWandererJ + RotL64(aCross, 53U)) + RotL64(aCarry, 47U)) + 14027986153007120145U;
            aOrbiterH = ((aWandererG + RotL64(aScatter, 3U)) + RotL64(aCarry, 19U)) + 7633455951809250227U;
            aOrbiterC = (aWandererE + RotL64(aCross, 14U)) + 340989348513370174U;
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 29U)) + RotL64(aCarry, 37U)) + 5307820377645020116U;
            aOrbiterK = (aWandererC + RotL64(aIngress, 35U)) + 5605285015771527274U;
            aOrbiterG = ((aWandererD + RotL64(aCross, 47U)) + 5293500434746182790U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 7263156475892261811U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 10672879570907433005U;
            aOrbiterJ = RotL64((aOrbiterJ * 2506338667179450741U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 16659226780900986107U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 9774892622769850665U;
            aOrbiterC = RotL64((aOrbiterC * 7487477727543183211U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 10728057184108279042U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 5032485856947407217U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16651577903809154285U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 14642241075374862345U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 8386481273395203518U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11649977733867003445U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 2874153265304098104U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 11519900149177261000U;
            aOrbiterK = RotL64((aOrbiterK * 2010158758971864505U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 8885690878540115768U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 4482143389870987714U;
            aOrbiterA = RotL64((aOrbiterA * 7105332459437434281U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 17469068567801886615U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 5121422018622394837U;
            aOrbiterG = RotL64((aOrbiterG * 14823827133212643467U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 3130788210672745618U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 6139244627510113216U;
            aOrbiterH = RotL64((aOrbiterH * 2640754184921507389U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 10488511756324474710U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 1760223670304953696U;
            aOrbiterF = RotL64((aOrbiterF * 4007062295003769311U), 21U);
            //
            aIngress = RotL64(aOrbiterJ, 56U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterK, 5U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 41U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 23U));
            aIngress = aIngress + RotL64(aOrbiterG, 14U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aIngress, 20U) + aOrbiterH) + RotL64(aOrbiterB, 29U)) + RotL64(aCarry, 5U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 5U) + aOrbiterG) + RotL64(aOrbiterH, 11U));
            aWandererC = aWandererC + ((RotL64(aScatter, 13U) + RotL64(aOrbiterC, 43U)) + aOrbiterI);
            aWandererF = aWandererF ^ ((RotL64(aCross, 57U) + aOrbiterJ) + RotL64(aOrbiterB, 18U));
            aWandererB = aWandererB + (((RotL64(aIngress, 34U) + aOrbiterC) + RotL64(aOrbiterA, 51U)) + aPhaseBWandererUpdateSaltF[((aIndex + 14U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterJ, 35U)) + aOrbiterK);
            aWandererA = aWandererA + ((RotL64(aCross, 39U) + RotL64(aOrbiterI, 47U)) + aOrbiterG);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 47U) + aOrbiterB) + RotL64(aOrbiterF, 23U)) + aPhaseBWandererUpdateSaltC[((aIndex + 10U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 27U) + RotL64(aOrbiterG, 6U)) + aOrbiterF) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + (RotL64(aWandererC, 53U) ^ aWandererK);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 22U));
            aCarry = aCarry + RotL64(aWandererJ, 5U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aFireLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_a loop 5
        // ingress from: aFireLaneD, aKeyRowReadA, aKeyRowReadB, mSource, aFireLaneB
        // ingress directions: aFireLaneD forward forced, aKeyRowReadA forward forced, aKeyRowReadB forward forced, mSource forward forced, aFireLaneB forward/backward random
        // cross from: aFireLaneA, aFireLaneC
        // cross directions: aFireLaneA backward forced, aFireLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aFireLaneD[((aIndex + 11953U)) & S_BLOCK1], 19U) ^ RotL64(aKeyRowReadA[((aIndex + 11547U)) & W_KEY1], 6U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 11980U)) & W_KEY1], 51U) ^ RotL64(mSource[((aIndex + 11423U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 11039U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 11107U)) & S_BLOCK1], 29U) ^ RotL64(aFireLaneC[((aIndex + 13080U)) & S_BLOCK1], 20U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 51U) ^ RotL64(aCross, 4U)) ^ (RotL64(aCarry, 35U) + RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = (aWandererJ + RotL64(aCross, 57U)) + 13924571355038625040U;
            aOrbiterE = (((aWandererK + RotL64(aIngress, 11U)) + RotL64(aCarry, 3U)) + 16328300979357156658U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = (aWandererC + RotL64(aScatter, 22U)) + 3947771961206012461U;
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 51U)) + RotL64(aCarry, 47U)) + 15428284250569311285U;
            aOrbiterH = (((aWandererF + RotL64(aScatter, 47U)) + RotL64(aCarry, 23U)) + 5777369485254032486U) + aPhaseBOrbiterAssignSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = (aWandererE + RotL64(aCross, 35U)) + 16813320300717644673U;
            aOrbiterG = (aWandererH + RotL64(aPrevious, 27U)) + 16689933050200758251U;
            aOrbiterJ = (aWandererB + RotL64(aIngress, 18U)) + 1856422419049390708U;
            aOrbiterA = (aWandererI + RotL64(aCross, 3U)) + 18214498743831925517U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 18278550878494094923U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 797712062039591797U;
            aOrbiterD = RotL64((aOrbiterD * 7212998747080137625U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 15854849439012341347U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 996882939768167773U;
            aOrbiterB = RotL64((aOrbiterB * 14936703950807908575U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 3005829974130671692U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 8793495343509953906U;
            aOrbiterF = RotL64((aOrbiterF * 14065479348374612031U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 7710453029930631112U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 9511995836117707047U;
            aOrbiterH = RotL64((aOrbiterH * 7250766204781428201U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 670902975693341744U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 9045820304668279777U;
            aOrbiterA = RotL64((aOrbiterA * 18373074917532639027U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 12417212387607119470U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 12816983560669985622U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8406003970221889847U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 17245432086377688540U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 6806521945548502014U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11335859481858640857U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 8947500746292365294U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 4468060468522895852U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7022481284816599797U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 9892975931958803992U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 3042599331526937836U;
            aOrbiterJ = RotL64((aOrbiterJ * 3308512896171443645U), 29U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterJ, 27U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 54U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + (RotL64(aOrbiterH, 19U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterF, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aScatter, 4U) + aOrbiterF) + RotL64(aOrbiterB, 30U)) + RotL64(aCarry, 3U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterJ, 57U)) + aOrbiterH);
            aWandererA = aWandererA + (((RotL64(aIngress, 39U) + RotL64(aOrbiterB, 13U)) + aOrbiterA) + RotL64(aCarry, 47U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 19U) + aOrbiterI) + RotL64(aOrbiterE, 23U));
            aWandererF = aWandererF + ((RotL64(aIngress, 13U) + aOrbiterJ) + RotL64(aOrbiterD, 3U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 29U) + aOrbiterI) + RotL64(aOrbiterJ, 51U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 51U) + aOrbiterG) + RotL64(aOrbiterD, 19U)) + aPhaseBWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 57U) + aOrbiterI) + RotL64(aOrbiterD, 41U));
            aWandererK = aWandererK + ((RotL64(aScatter, 34U) + RotL64(aOrbiterG, 34U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + RotL64(aWandererA, 60U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_a loop 6
        // ingress from: aWorkLaneA, aFireLaneC
        // ingress directions: aWorkLaneA forward forced, aFireLaneC forward/backward random
        // cross from: aKeyRowReadA, aKeyRowReadB, mSource, aFireLaneB, aFireLaneA
        // cross directions: aKeyRowReadA backward forced, aKeyRowReadB backward forced, mSource backward forced, aFireLaneB backward forced, aFireLaneA backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aWorkLaneA[((aIndex + 14135U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 15458U)) & S_BLOCK1], 58U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 14569U)) & W_KEY1], 44U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 16200U)) & W_KEY1], 11U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 13974U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 14600U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 14739U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 51U) ^ RotL64(aPrevious, 35U)) ^ (RotL64(aIngress, 21U) + RotL64(aCarry, 6U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = (aWandererD + RotL64(aPrevious, 47U)) + 2558105147674438050U;
            aOrbiterF = (aWandererH + RotL64(aCross, 11U)) + 15856662514774702561U;
            aOrbiterG = (((aWandererK + RotL64(aIngress, 27U)) + RotL64(aCarry, 5U)) + 13346869226246584582U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = ((aWandererB + RotL64(aScatter, 23U)) + RotL64(aCarry, 19U)) + 7632111846116243973U;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 42U)) + RotL64(aCarry, 41U)) + 2102101361626976279U;
            aOrbiterE = (aWandererG + RotL64(aScatter, 3U)) + 5605968705067851563U;
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 57U)) + 6842483186584326681U) + aPhaseBOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = (aWandererI + RotL64(aCross, 53U)) + 5559797213819425064U;
            aOrbiterI = (aWandererA + RotL64(aScatter, 18U)) + 12422313931331576759U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 2751024420047872601U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 11031320239359798610U;
            aOrbiterG = RotL64((aOrbiterG * 8607639453141148025U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 14366375309473793217U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 11971479429768505316U;
            aOrbiterF = RotL64((aOrbiterF * 10063001532313098203U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 3947595951884469542U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 17882767922372770896U;
            aOrbiterK = RotL64((aOrbiterK * 3361906348965810211U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 513871456983509223U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 5951677013597794294U;
            aOrbiterE = RotL64((aOrbiterE * 8508629569649935293U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 437626309049021931U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 466674061172005705U;
            aOrbiterI = RotL64((aOrbiterI * 1310502572084891157U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 12362602809233133718U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 10525852878882195702U;
            aOrbiterA = RotL64((aOrbiterA * 17755022180514914325U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 17927000184308583095U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 566723721423470052U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17710534355278632573U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 9504585484034413577U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 4614306037721859929U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 170807293799483539U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 1463218357720031588U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 4036696102163560633U;
            aOrbiterJ = RotL64((aOrbiterJ * 15389914226155130065U), 19U);
            //
            aIngress = RotL64(aOrbiterD, 14U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterF, 53U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 11U));
            aIngress = aIngress + RotL64(aOrbiterJ, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterD, 11U)) + aOrbiterF);
            aWandererD = aWandererD + (((RotL64(aCross, 43U) + RotL64(aOrbiterB, 38U)) + aOrbiterK) + RotL64(aCarry, 13U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 56U) + aOrbiterK) + RotL64(aOrbiterA, 43U)) + aPhaseBWandererUpdateSaltF[((aIndex + 8U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 27U) + RotL64(aOrbiterA, 23U)) + aOrbiterJ);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterE, 29U)) + aOrbiterB);
            aWandererC = aWandererC + ((RotL64(aScatter, 51U) + RotL64(aOrbiterI, 5U)) + aOrbiterA);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 18U) + aOrbiterE) + RotL64(aOrbiterG, 51U));
            aWandererG = aWandererG + ((((RotL64(aIngress, 39U) + RotL64(aOrbiterB, 60U)) + aOrbiterJ) + RotL64(aCarry, 5U)) + aPhaseBWandererUpdateSaltB[((aIndex + 6U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 47U) + aOrbiterF) + RotL64(aOrbiterE, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererA);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 27U));
            aCarry = aCarry + (RotL64(aWandererC, 37U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererB, 60U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_a loop 7
        // ingress from: aWorkLaneB, aKeyRowReadA, mSource, aFireLaneA
        // ingress directions: aWorkLaneB forward forced, aKeyRowReadA forward forced, mSource forward forced, aFireLaneA forward/backward random
        // cross from: aKeyRowReadB, aFireLaneD, aWorkLaneA
        // cross directions: aKeyRowReadB backward forced, aFireLaneD backward forced, aWorkLaneA backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 16663U)) & S_BLOCK1], 41U) ^ RotL64(aKeyRowReadA[((aIndex + 16569U)) & W_KEY1], 19U));
            aIngress ^= (RotL64(mSource[((aIndex + 16945U)) & S_BLOCK1], 50U) ^ RotL64(aFireLaneA[((aIndex + 17330U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 17514U)) & W_KEY1], 22U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 19016U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18497U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aIngress, 5U)) ^ (RotL64(aCarry, 29U) + RotL64(aPrevious, 44U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = (aWandererI + RotL64(aCross, 6U)) + 14686411261024919129U;
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 35U)) + 7514582233957632005U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = (aWandererG + RotL64(aScatter, 57U)) + 6520710480103365552U;
            aOrbiterJ = (aWandererK + RotL64(aIngress, 27U)) + 1983621978676188036U;
            aOrbiterD = (aWandererA + RotL64(aPrevious, 44U)) + 9003524602590749672U;
            aOrbiterI = (((aWandererJ + RotL64(aScatter, 39U)) + RotL64(aCarry, 11U)) + 6428568234045228995U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = ((aWandererH + RotL64(aCross, 19U)) + RotL64(aCarry, 29U)) + 8656552687136446989U;
            aOrbiterH = (aWandererE + RotL64(aIngress, 13U)) + 16916248288415922490U;
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 23U)) + RotL64(aCarry, 43U)) + 9740237548002535784U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 907561000814618339U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 4751108900841197631U;
            aOrbiterA = RotL64((aOrbiterA * 4545395964730641957U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 167774899400732287U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 11907484918310854962U;
            aOrbiterD = RotL64((aOrbiterD * 7213139491146402985U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 14910318613649863924U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 14882888155751455276U;
            aOrbiterE = RotL64((aOrbiterE * 11394136445442060201U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 16175942562693781908U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 11022373758481651102U;
            aOrbiterK = RotL64((aOrbiterK * 6836331461393816027U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 12548405399045031548U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 10850926364556828443U;
            aOrbiterH = RotL64((aOrbiterH * 16231561687709867431U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 13391684887911141790U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 14648937281264822988U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6533299316940026059U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 8298658887198526821U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 13822977698661348891U;
            aOrbiterJ = RotL64((aOrbiterJ * 17769262972278410937U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 7505646847564645719U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 3238749538197209166U;
            aOrbiterF = RotL64((aOrbiterF * 15394286542600778567U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 15853506915123709257U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 8426329899401071248U;
            aOrbiterI = RotL64((aOrbiterI * 1330397096577715113U), 11U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterA, 27U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 18U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 13U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 53U));
            aIngress = aIngress + RotL64(aOrbiterB, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aCross, 51U) + RotL64(aOrbiterI, 47U)) + aOrbiterF) + aPhaseCWandererUpdateSaltC[((aIndex + 24U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 56U) + aOrbiterH) + RotL64(aOrbiterK, 39U)) + RotL64(aCarry, 29U)) + aPhaseCWandererUpdateSaltE[((aIndex + 14U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 23U) + aOrbiterB) + RotL64(aOrbiterD, 27U));
            aWandererE = aWandererE + ((RotL64(aScatter, 35U) + aOrbiterA) + RotL64(aOrbiterH, 18U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 3U) + aOrbiterE) + RotL64(aOrbiterK, 23U));
            aWandererI = aWandererI + ((RotL64(aScatter, 11U) + aOrbiterF) + RotL64(aOrbiterB, 53U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 18U) + aOrbiterK) + RotL64(aOrbiterD, 57U));
            aWandererG = aWandererG + (((RotL64(aIngress, 43U) + RotL64(aOrbiterA, 12U)) + aOrbiterJ) + RotL64(aCarry, 39U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterA, 5U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 37U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 46U));
            aCarry = aCarry + (RotL64(aWandererK, 29U) ^ aWandererJ);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + RotL64(aWandererG, 53U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_a loop 8
        // ingress from: aWorkLaneC, mSource, aWorkLaneA, aFireLaneA
        // ingress directions: aWorkLaneC forward forced, mSource forward forced, aWorkLaneA forward forced, aFireLaneA forward/backward random
        // cross from: aKeyRowReadA, aKeyRowReadB, aWorkLaneB, aFireLaneB
        // cross directions: aKeyRowReadA backward forced, aKeyRowReadB backward forced, aWorkLaneB backward forced, aFireLaneB backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 19871U)) & S_BLOCK1], 11U) ^ RotL64(mSource[((aIndex + 21451U)) & S_BLOCK1], 58U));
            aIngress ^= (RotL64(aWorkLaneA[((aIndex + 19758U)) & S_BLOCK1], 43U) ^ RotL64(aFireLaneA[((aIndex + 21501U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 20843U)) & W_KEY1], 11U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 20992U)) & W_KEY1], 46U));
            aCross ^= (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20450U)) & S_BLOCK1], 19U) ^ RotL64(aFireLaneB[((aIndex + 21375U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 35U) ^ RotL64(aPrevious, 47U)) + (RotL64(aCross, 5U) + RotL64(aIngress, 22U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 39U)) + 13278949403988203974U) + aPhaseCOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 19U)) + 9213599924054673756U) + aPhaseCOrbiterAssignSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = (aWandererH + RotL64(aCross, 53U)) + 1255746482932381798U;
            aOrbiterC = (aWandererI + RotL64(aScatter, 10U)) + 11575321997144516122U;
            aOrbiterG = ((aWandererA + RotL64(aCross, 57U)) + RotL64(aCarry, 5U)) + 15881587525529432437U;
            aOrbiterH = ((aWandererF + RotL64(aIngress, 29U)) + RotL64(aCarry, 53U)) + 9846195809864862707U;
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 23U)) + RotL64(aCarry, 35U)) + 12319815691858217670U;
            aOrbiterJ = (aWandererC + RotL64(aScatter, 4U)) + 16322617427294439587U;
            aOrbiterD = (aWandererB + RotL64(aCross, 35U)) + 16332130810525887437U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 4920951156015336794U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 16767126455124552329U;
            aOrbiterA = RotL64((aOrbiterA * 4440352337076842603U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 12553595911087945223U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 1437522202135436142U;
            aOrbiterG = RotL64((aOrbiterG * 2001992794165550905U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 12313100454852227143U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 2761983020631055729U;
            aOrbiterJ = RotL64((aOrbiterJ * 3874839760378039509U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 17635303588421554367U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 788212489507463763U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17896475584538528059U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 5192552894670654434U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 6784748488807738811U;
            aOrbiterE = RotL64((aOrbiterE * 8077237651953896479U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 16113417046719114943U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 1096874945215225916U;
            aOrbiterI = RotL64((aOrbiterI * 17308604412622879833U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 7610274704570171595U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 10466070212284342550U;
            aOrbiterD = RotL64((aOrbiterD * 6449728258497920613U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 6777845928873855221U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 5251515022021984126U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9018277343404261611U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 13849343158824111498U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 7977711210181714021U;
            aOrbiterH = RotL64((aOrbiterH * 4182053966171053577U), 53U);
            //
            aIngress = RotL64(aOrbiterA, 20U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterH, 11U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterG, 27U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterJ, 47U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterC, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterH, 19U)) + aOrbiterE);
            aWandererC = aWandererC + ((RotL64(aCross, 27U) + aOrbiterJ) + RotL64(aOrbiterH, 44U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 52U) + RotL64(aOrbiterA, 23U)) + aOrbiterD) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 19U) + aOrbiterH) + RotL64(aOrbiterG, 57U)) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterD, 13U)) + aOrbiterF) + aPhaseCWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 41U) + RotL64(aOrbiterI, 51U)) + aOrbiterC) + RotL64(aCarry, 29U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 23U) + aOrbiterC) + RotL64(aOrbiterA, 39U));
            aWandererB = aWandererB + ((RotL64(aCross, 12U) + RotL64(aOrbiterA, 34U)) + aOrbiterH);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 3U) + aOrbiterF) + RotL64(aOrbiterE, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 13U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + (RotL64(aWandererE, 26U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererF, 23U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_a loop 9
        // ingress from: aWorkLaneD, aKeyRowReadA, aKeyRowReadB, aWorkLaneC
        // ingress directions: aWorkLaneD forward forced, aKeyRowReadA forward forced, aKeyRowReadB forward forced, aWorkLaneC forward/backward random
        // cross from: mSource, aWorkLaneA, aFireLaneC, aFireLaneD
        // cross directions: mSource backward forced, aWorkLaneA backward forced, aFireLaneC backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneD[((aIndex + 22147U)) & S_BLOCK1], 4U) ^ RotL64(aKeyRowReadA[((aIndex + 23332U)) & W_KEY1], 21U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 22057U)) & W_KEY1], 39U) ^ RotL64(aWorkLaneC[((aIndex + 21937U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 23354U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22243U)) & S_BLOCK1], 40U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 21999U)) & S_BLOCK1], 29U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 22935U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aIngress, 37U)) ^ (RotL64(aCross, 51U) ^ RotL64(aPrevious, 18U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = (aWandererH + RotL64(aScatter, 3U)) + 6163290588946759209U;
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 10U)) + RotL64(aCarry, 37U)) + 7342672468560105447U;
            aOrbiterB = ((aWandererF + RotL64(aCross, 29U)) + 11574563167017282321U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterE = (aWandererI + RotL64(aIngress, 51U)) + 2254820206194758964U;
            aOrbiterG = ((aWandererK + RotL64(aScatter, 43U)) + RotL64(aCarry, 21U)) + 1469783447473099498U;
            aOrbiterF = ((aWandererJ + RotL64(aCross, 23U)) + RotL64(aCarry, 51U)) + 14174828900676165088U;
            aOrbiterH = (aWandererA + RotL64(aPrevious, 47U)) + 16277954291890598132U;
            aOrbiterD = ((aWandererB + RotL64(aIngress, 57U)) + 14845750668693136766U) + aPhaseCOrbiterAssignSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterJ = (aWandererE + RotL64(aScatter, 38U)) + 150099699692047766U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 1200784917165131703U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 9469982764806754302U;
            aOrbiterB = RotL64((aOrbiterB * 17851969334511301943U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 10956702761701710182U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 7915506894975487807U;
            aOrbiterF = RotL64((aOrbiterF * 8874108311712727983U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 17335794183733623213U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 557028996286989506U;
            aOrbiterA = RotL64((aOrbiterA * 3993359298602424281U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 1597385667771002414U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 4376417959915162639U;
            aOrbiterD = RotL64((aOrbiterD * 4626236858205178149U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 549770198518993876U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 756554555648070919U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16272320259614325355U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 7298557532533152193U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 3336802611342112013U;
            aOrbiterC = RotL64((aOrbiterC * 14679103452120080499U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 2314938232094714365U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 12215066333571149153U;
            aOrbiterE = RotL64((aOrbiterE * 10747052773052630601U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 7762752719356805046U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 6519429915769040078U;
            aOrbiterJ = RotL64((aOrbiterJ * 15548676502167938513U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 7556691736109752918U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 13731245903412646404U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15581965016668635409U), 27U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterD, 23U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 42U));
            aIngress = aIngress + (RotL64(aOrbiterA, 5U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 19U));
            aIngress = aIngress + RotL64(aOrbiterB, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aCross, 12U) + RotL64(aOrbiterA, 29U)) + aOrbiterJ);
            aWandererI = aWandererI + (((RotL64(aIngress, 39U) + aOrbiterA) + RotL64(aOrbiterC, 23U)) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 43U) + aOrbiterD) + RotL64(aOrbiterE, 35U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterB, 52U)) + aOrbiterA);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 34U) + RotL64(aOrbiterF, 47U)) + aOrbiterH);
            aWandererH = aWandererH + (((RotL64(aCross, 47U) + aOrbiterJ) + RotL64(aOrbiterD, 57U)) + RotL64(aCarry, 3U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterF, 19U)) + aOrbiterC);
            aWandererE = aWandererE + (((RotL64(aIngress, 19U) + aOrbiterJ) + RotL64(aOrbiterG, 5U)) + RotL64(aCarry, 21U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterD, 10U)) + aOrbiterF) + aPhaseCWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererG);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 50U));
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererJ, 35U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_a loop 10
        // ingress from: aExpandLaneA, aKeyRowReadA, aWorkLaneD, aWorkLaneB
        // ingress directions: aExpandLaneA forward forced, aKeyRowReadA forward forced, aWorkLaneD forward forced, aWorkLaneB forward/backward random
        // cross from: aKeyRowReadB, mSource, aWorkLaneC, aFireLaneD
        // cross directions: aKeyRowReadB backward forced, mSource backward forced, aWorkLaneC backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 25139U)) & S_BLOCK1], 11U) ^ RotL64(aKeyRowReadA[((aIndex + 25863U)) & W_KEY1], 20U));
            aIngress ^= (RotL64(aWorkLaneD[((aIndex + 26570U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26340U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 24786U)) & W_KEY1], 29U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 24774U)) & S_BLOCK1], 3U));
            aCross ^= (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 24820U)) & S_BLOCK1], 54U) ^ RotL64(aFireLaneD[((aIndex + 27239U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 19U) ^ RotL64(aCarry, 57U)) + (RotL64(aCross, 6U) ^ RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = (aWandererB + RotL64(aCross, 18U)) + 4204560462077827182U;
            aOrbiterB = (aWandererD + RotL64(aIngress, 23U)) + 6572370199668594039U;
            aOrbiterK = ((aWandererC + RotL64(aScatter, 41U)) + RotL64(aCarry, 5U)) + 15958999876732622825U;
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 47U)) + 9969349486879280377U) + aPhaseDOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = (aWandererA + RotL64(aCross, 11U)) + 15450238998293956181U;
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 51U)) + RotL64(aCarry, 41U)) + 9128619863683138259U;
            aOrbiterE = (aWandererJ + RotL64(aScatter, 57U)) + 5691270563628979565U;
            aOrbiterF = (((aWandererG + RotL64(aIngress, 36U)) + RotL64(aCarry, 57U)) + 5901029710568933106U) + aPhaseDOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = (aWandererH + RotL64(aScatter, 29U)) + 10442738941988588834U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 3508116020325721993U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 13221917083569767259U;
            aOrbiterK = RotL64((aOrbiterK * 6845108555710135357U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 11627915460377128176U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 17858261365514253433U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7535577636975884641U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 4294837988806295989U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 11242915481585070249U;
            aOrbiterI = RotL64((aOrbiterI * 17540688242763829319U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 13030663829236027109U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 7451948220723185149U;
            aOrbiterD = RotL64((aOrbiterD * 5191778587712222029U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 5575508866505031037U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 5161096033789876794U;
            aOrbiterJ = RotL64((aOrbiterJ * 16843827915802461797U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 3980482740649505122U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 11188906150207270241U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 408550837615188413U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 4435504916461645189U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 9970252853543702833U;
            aOrbiterA = RotL64((aOrbiterA * 5829143716916091997U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 3766347619186305854U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 11004616087340082895U;
            aOrbiterF = RotL64((aOrbiterF * 14469267845747063735U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 17600791542296175812U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 2556224430252009744U;
            aOrbiterG = RotL64((aOrbiterG * 14469426539907112137U), 35U);
            //
            aIngress = RotL64(aOrbiterK, 53U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterB, 19U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterG, 50U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterA, 43U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterD, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aCross, 58U) + RotL64(aOrbiterE, 19U)) + aOrbiterK) + RotL64(aCarry, 19U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterF, 51U)) + aOrbiterA);
            aWandererA = aWandererA + ((RotL64(aIngress, 11U) + aOrbiterF) + RotL64(aOrbiterG, 30U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterK, 13U)) + aOrbiterA);
            aWandererB = aWandererB + (((RotL64(aScatter, 5U) + aOrbiterD) + RotL64(aOrbiterI, 57U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 37U) + aOrbiterE) + RotL64(aOrbiterA, 39U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 23U) + aOrbiterI) + RotL64(aOrbiterF, 47U)) + RotL64(aCarry, 29U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 18U) + RotL64(aOrbiterB, 43U)) + aOrbiterD);
            aWandererI = aWandererI + (((RotL64(aPrevious, 41U) + aOrbiterJ) + RotL64(aOrbiterB, 4U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererG, 54U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererK, 5U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_a loop 11
        // ingress from: aExpandLaneB, aWorkLaneD, aKeyRowReadB, aWorkLaneC
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aKeyRowReadB forward forced, aWorkLaneC forward/backward random
        // cross from: aKeyRowReadA, mSource, aExpandLaneA, aWorkLaneB
        // cross directions: aKeyRowReadA backward forced, mSource backward forced, aExpandLaneA backward forced, aWorkLaneB backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 29177U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneD[((aIndex + 28725U)) & S_BLOCK1], 41U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 28766U)) & W_KEY1], 29U) ^ RotL64(aWorkLaneC[((aIndex + 30001U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 28772U)) & W_KEY1], 57U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 29620U)) & S_BLOCK1], 6U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28675U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((aIndex + 29443U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 11U) + RotL64(aPrevious, 27U)) + (RotL64(aCross, 41U) ^ RotL64(aIngress, 54U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 43U)) + 7948891781097675369U;
            aOrbiterG = ((aWandererB + RotL64(aCross, 5U)) + RotL64(aCarry, 53U)) + 13928362874228230226U;
            aOrbiterD = ((aWandererH + RotL64(aIngress, 60U)) + RotL64(aCarry, 41U)) + 10776180542602258926U;
            aOrbiterI = (aWandererC + RotL64(aScatter, 11U)) + 5735115172149470447U;
            aOrbiterC = ((aWandererI + RotL64(aCross, 35U)) + 5353591822981766987U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 27U)) + RotL64(aCarry, 23U)) + 562301708107268570U;
            aOrbiterF = (aWandererF + RotL64(aPrevious, 53U)) + 10467810247578364868U;
            aOrbiterA = ((aWandererE + RotL64(aIngress, 47U)) + 14541630141152308564U) + aPhaseDOrbiterAssignSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterE = (aWandererA + RotL64(aCross, 22U)) + 2350076897065139429U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 17519109078651162228U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 6061035173339902910U;
            aOrbiterD = RotL64((aOrbiterD * 10021905773432907835U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 15654836633731000065U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 13723521735153718904U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14459516479283070563U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 2849680038315532197U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 17336102435576647923U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10984689101753586739U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 7671010488872356142U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 11485114338165600777U;
            aOrbiterJ = RotL64((aOrbiterJ * 4162584865462407791U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 8759060657343458985U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 11009137869375286581U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8741417343929809115U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 15792999392743144135U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 6180808423175992479U;
            aOrbiterE = RotL64((aOrbiterE * 13681230339693676907U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 361487389591183005U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 15292753806514404853U;
            aOrbiterG = RotL64((aOrbiterG * 17478232597253311153U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 14929153438443362045U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 7904556383593914086U;
            aOrbiterH = RotL64((aOrbiterH * 2484130486635511403U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 3793180909904286848U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 10391957637467171320U;
            aOrbiterI = RotL64((aOrbiterI * 505484041943467117U), 47U);
            //
            aIngress = RotL64(aOrbiterG, 13U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterJ, 43U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterE, 35U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterI, 52U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterD, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterD, 24U)) + aOrbiterA) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 58U) + aOrbiterJ) + RotL64(aOrbiterG, 19U)) + RotL64(aCarry, 23U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterH, 3U)) + aOrbiterA);
            aWandererF = aWandererF + ((RotL64(aCross, 29U) + RotL64(aOrbiterF, 43U)) + aOrbiterE);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 19U) + aOrbiterD) + RotL64(aOrbiterI, 13U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 35U) + RotL64(aOrbiterG, 47U)) + aOrbiterD) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 54U) + RotL64(aOrbiterC, 39U)) + aOrbiterH);
            aWandererJ = aWandererJ + ((RotL64(aCross, 23U) + aOrbiterH) + RotL64(aOrbiterE, 52U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterI, 35U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 37U));
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 60U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererH, 29U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_a loop 12
        // ingress from: aExpandLaneC, aKeyRowReadA
        // ingress directions: aExpandLaneC forward forced, aKeyRowReadA forward/backward random
        // cross from: aWorkLaneD, aExpandLaneA, aExpandLaneB, aKeyRowReadB
        // cross directions: aWorkLaneD backward forced, aExpandLaneA backward forced, aExpandLaneB backward forced, aKeyRowReadB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aExpandLaneC[((aIndex + 32048U)) & S_BLOCK1], 28U) ^ RotL64(aKeyRowReadA[((aIndex + 30978U)) & W_KEY1], 57U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 32419U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32665U)) & S_BLOCK1], 41U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31122U)) & S_BLOCK1], 19U) ^ RotL64(aKeyRowReadB[((aIndex + 32004U)) & W_KEY1], 56U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 37U) ^ RotL64(aCarry, 11U)) + (RotL64(aCross, 58U) + RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = (aWandererJ + RotL64(aScatter, 10U)) + 5576732410244514238U;
            aOrbiterK = (aWandererH + RotL64(aCross, 39U)) + 2833808925935929629U;
            aOrbiterH = ((aWandererE + RotL64(aIngress, 57U)) + RotL64(aCarry, 51U)) + 3670188682914544792U;
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 27U)) + 15759072378887814995U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = ((aWandererD + RotL64(aScatter, 43U)) + RotL64(aCarry, 43U)) + 13934007231137439994U;
            aOrbiterJ = ((aWandererF + RotL64(aCross, 19U)) + RotL64(aCarry, 29U)) + 11022225696007690512U;
            aOrbiterC = ((aWandererG + RotL64(aIngress, 14U)) + 16989177104453635790U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = (aWandererK + RotL64(aPrevious, 3U)) + 9256930045263527091U;
            aOrbiterB = (aWandererA + RotL64(aCross, 47U)) + 17788596104417068290U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 17044369456673337625U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 1310908395523250343U;
            aOrbiterH = RotL64((aOrbiterH * 16305084373037705921U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 12067065689034065422U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 15130844248737512262U;
            aOrbiterJ = RotL64((aOrbiterJ * 9409499577465934107U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 14532689204495587494U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 8198147292120244178U;
            aOrbiterK = RotL64((aOrbiterK * 1418356389507740991U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 5485494458627163347U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 10830008207150307611U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6526039534042499457U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 17770065502486618029U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 6397859353395335459U;
            aOrbiterD = RotL64((aOrbiterD * 14286997752368893825U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 5128700697381508319U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 7103394110057060499U;
            aOrbiterB = RotL64((aOrbiterB * 5053680689949149633U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 16024401282261796979U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 12818445221897253410U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11450004517784155405U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 13386978409145916350U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 16740821954556699503U;
            aOrbiterA = RotL64((aOrbiterA * 5376430209628515105U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 313978038530994953U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 1355733685461795345U;
            aOrbiterE = RotL64((aOrbiterE * 15955927322082619735U), 23U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterF, 19U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 6U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 23U));
            aIngress = aIngress + RotL64(aOrbiterK, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aCross, 11U) + RotL64(aOrbiterD, 23U)) + aOrbiterK);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterD, 58U)) + aOrbiterB);
            aWandererF = aWandererF + ((RotL64(aIngress, 23U) + RotL64(aOrbiterB, 35U)) + aOrbiterE);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 60U) + RotL64(aOrbiterE, 47U)) + aOrbiterH) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterC, 19U)) + aOrbiterF) + RotL64(aCarry, 43U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterB, 13U)) + aOrbiterA);
            aWandererH = aWandererH + (((RotL64(aCross, 51U) + aOrbiterJ) + RotL64(aOrbiterA, 51U)) + aPhaseDWandererUpdateSaltA[((aIndex + 28U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 5U) + aOrbiterF) + RotL64(aOrbiterJ, 4U));
            aWandererB = aWandererB + (((RotL64(aIngress, 46U) + aOrbiterE) + RotL64(aOrbiterK, 27U)) + RotL64(aCarry, 19U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 6U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererK, 57U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneA, aExpandLaneC, aExpandLaneD, aFireLaneB, aOperationLaneA, aFireLaneC, aFireLaneD, aOperationLaneB, aWorkLaneA, aWorkLaneB, aOperationLaneC, aWorkLaneC, aWorkLaneD
        // write to: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // twist_loop_b loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneA
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aFireLaneB
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aFireLaneB backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 1799U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((aIndex + 1841U)) & S_BLOCK1], 28U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 1751U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3006U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 1681U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 3794U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 41U) ^ RotL64(aIngress, 58U)) + (RotL64(aCross, 23U) + RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = (aWandererB + RotL64(aPrevious, 40U)) + 10726035965553989335U;
            aOrbiterF = (aWandererD + RotL64(aCross, 27U)) + 967354339530195662U;
            aOrbiterI = ((aWandererC + RotL64(aIngress, 57U)) + 10834593005478605624U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = (aWandererG + RotL64(aScatter, 51U)) + 1012888282838656933U;
            aOrbiterA = ((aWandererI + RotL64(aCross, 3U)) + RotL64(aCarry, 37U)) + 15283530351725183253U;
            aOrbiterB = (((aWandererH + RotL64(aScatter, 13U)) + RotL64(aCarry, 53U)) + 11724495956731703750U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 21U)) + RotL64(aCarry, 21U)) + 4288330117317505776U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 10894778070022873473U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 15563886747621617467U;
            aOrbiterI = RotL64((aOrbiterI * 17884709931569040065U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 11182488628562891937U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 10420140066310588580U;
            aOrbiterC = RotL64((aOrbiterC * 13898299782819948719U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 11775138062167543111U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 16545391898578161683U;
            aOrbiterA = RotL64((aOrbiterA * 14588306527161321535U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 1550144656312299266U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 14903504853138279883U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8003033561266164387U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 309935535526750396U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 13991265868040011411U;
            aOrbiterB = RotL64((aOrbiterB * 2887531132228588441U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 1755976294857114222U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 2259275858478396846U;
            aOrbiterK = RotL64((aOrbiterK * 7416165760067878161U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 4838175912944552936U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 12307900457200936013U;
            aOrbiterJ = RotL64((aOrbiterJ * 14719363144850838805U), 27U);
            //
            aIngress = RotL64(aOrbiterB, 27U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterI, 35U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + RotL64(aOrbiterC, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aCross, 11U) + RotL64(aOrbiterI, 14U)) + aOrbiterJ) + RotL64(aCarry, 51U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 27U) + aOrbiterF) + RotL64(aOrbiterA, 43U));
            aWandererC = aWandererC + ((((RotL64(aPrevious, 21U) + aOrbiterC) + RotL64(aOrbiterI, 37U)) + RotL64(aCarry, 5U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterB, 57U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aIngress, 3U) + RotL64(aOrbiterK, 51U)) + aOrbiterJ);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterF, 21U)) + aOrbiterB);
            aWandererI = aWandererI + ((RotL64(aCross, 56U) + aOrbiterC) + RotL64(aOrbiterF, 27U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + (RotL64(aWandererD, 48U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererI, 5U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_b loop 2
        // ingress from: aOperationLaneA, aExpandLaneC, aExpandLaneD, aFireLaneC
        // ingress directions: aOperationLaneA forward forced, aExpandLaneC forward forced, aExpandLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneA, aExpandLaneB, aFireLaneD
        // cross directions: aExpandLaneA backward forced, aExpandLaneB backward forced, aFireLaneD backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 14250U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneC[((aIndex + 12648U)) & S_BLOCK1], 29U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 12695U)) & S_BLOCK1], 37U) ^ RotL64(aFireLaneC[((aIndex + 11992U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 16175U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 10698U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 14643U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 4U) ^ RotL64(aCross, 41U)) + (RotL64(aIngress, 53U) ^ RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = (aWandererD + RotL64(aScatter, 13U)) + 8604208734152026945U;
            aOrbiterH = (((aWandererC + RotL64(aCross, 43U)) + RotL64(aCarry, 27U)) + 1374329953253889829U) + aPhaseEOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = ((aWandererB + RotL64(aIngress, 51U)) + RotL64(aCarry, 13U)) + 5779278910548228339U;
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 57U)) + RotL64(aCarry, 51U)) + 17670451230882805140U;
            aOrbiterB = (aWandererF + RotL64(aCross, 24U)) + 8193848740764866860U;
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 37U)) + 15801168428145650104U) + aPhaseEOrbiterAssignSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterE = (aWandererH + RotL64(aScatter, 3U)) + 2584718176087499066U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 14950366247822737997U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 9779293225265670135U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11625969538497982117U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 8688968319288372383U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 13665723186950342601U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 292035540396910837U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 9395428688359973510U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 2152719218018108418U;
            aOrbiterF = RotL64((aOrbiterF * 15271961483518392671U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 1350324137411377992U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 8729317951386057921U;
            aOrbiterB = RotL64((aOrbiterB * 6008790836417785083U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 6317310451893678411U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 10175620379041384281U;
            aOrbiterI = RotL64((aOrbiterI * 14079679617394330781U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 1203082119358827708U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 523869107818193101U;
            aOrbiterH = RotL64((aOrbiterH * 4629501113595689157U), 37U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 4028324959540432983U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 15447631947468213912U;
            aOrbiterE = RotL64((aOrbiterE * 6037306615787729185U), 43U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterB, 21U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 43U));
            aIngress = aIngress + (RotL64(aOrbiterI, 3U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterA, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aIngress, 41U) + aOrbiterH) + RotL64(aOrbiterI, 5U)) + RotL64(aCarry, 57U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 28U) + aOrbiterE) + RotL64(aOrbiterF, 57U)) + aPhaseEWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 3U) + aOrbiterA) + RotL64(aOrbiterF, 43U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterH, 11U)) + aOrbiterB);
            aWandererB = aWandererB + ((RotL64(aScatter, 19U) + RotL64(aOrbiterA, 27U)) + aOrbiterI);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 13U) + aOrbiterG) + RotL64(aOrbiterF, 51U)) + aPhaseEWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 35U) + aOrbiterB) + RotL64(aOrbiterF, 36U)) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 4U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + (RotL64(aWandererH, 53U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererB, 29U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_b loop 3
        // ingress from: aOperationLaneB, aExpandLaneA, aExpandLaneB, aWorkLaneA
        // ingress directions: aOperationLaneB forward forced, aExpandLaneA forward forced, aExpandLaneB forward forced, aWorkLaneA forward/backward random
        // cross from: aOperationLaneA, aExpandLaneC, aWorkLaneB
        // cross directions: aOperationLaneA backward forced, aExpandLaneC backward forced, aWorkLaneB backward/forward random
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 18577U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneA[((aIndex + 19710U)) & S_BLOCK1], 21U));
            aIngress ^= (RotL64(aExpandLaneB[((aIndex + 18107U)) & S_BLOCK1], 10U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18224U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 17618U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 22384U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 16669U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 19U) + RotL64(aCarry, 54U)) + (RotL64(aPrevious, 41U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = (aWandererG + RotL64(aIngress, 53U)) + 11480359716598965890U;
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 19U)) + RotL64(aCarry, 3U)) + 15431182525482873419U;
            aOrbiterE = (aWandererE + RotL64(aScatter, 4U)) + 11360504974812776707U;
            aOrbiterG = ((aWandererK + RotL64(aCross, 37U)) + RotL64(aCarry, 23U)) + 9292576416573382769U;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 29U)) + 1549257414531028975U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 11U)) + RotL64(aCarry, 43U)) + 5347769463033129317U;
            aOrbiterB = ((aWandererF + RotL64(aCross, 43U)) + 17019199177478377234U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 16558106007323125094U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 3976182233825939422U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4392162052317572289U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 2889047161195954395U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 2241831345026962605U;
            aOrbiterF = RotL64((aOrbiterF * 5757458560979927857U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 12850802412140579294U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 13541744735436450160U;
            aOrbiterB = RotL64((aOrbiterB * 906089290000537439U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 2085863085516538212U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 2969034221711544086U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7768528124408400403U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 6482666944512391472U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 16969153556875844613U;
            aOrbiterG = RotL64((aOrbiterG * 9483462388353216219U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 5161314086757363678U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 7150282484670673211U;
            aOrbiterK = RotL64((aOrbiterK * 8522427002337918663U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 5465304381272305847U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 2344610773390354017U;
            aOrbiterJ = RotL64((aOrbiterJ * 17010258514288089191U), 47U);
            //
            aIngress = RotL64(aOrbiterG, 51U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterF, 27U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 19U));
            aIngress = aIngress + RotL64(aOrbiterE, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterB, 51U)) + aOrbiterF);
            aWandererE = aWandererE + (((RotL64(aCross, 47U) + aOrbiterF) + RotL64(aOrbiterK, 27U)) + RotL64(aCarry, 5U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 3U) + aOrbiterF) + RotL64(aOrbiterC, 19U)) + aPhaseEWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 41U) + RotL64(aOrbiterJ, 43U)) + aOrbiterE) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterJ, 3U)) + aOrbiterB);
            aWandererA = aWandererA + (((RotL64(aIngress, 20U) + RotL64(aOrbiterF, 57U)) + aOrbiterG) + RotL64(aCarry, 41U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterE, 10U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 12U));
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererE, 53U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_b loop 4
        // ingress from: aOperationLaneC, aOperationLaneA, aExpandLaneD, aWorkLaneC
        // ingress directions: aOperationLaneC forward forced, aOperationLaneA forward forced, aExpandLaneD forward forced, aWorkLaneC forward/backward random
        // cross from: aOperationLaneB, aExpandLaneB, aWorkLaneD
        // cross directions: aOperationLaneB backward forced, aExpandLaneB backward forced, aWorkLaneD backward/forward random
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneC[((aIndex + 26038U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneA[((aIndex + 31287U)) & S_BLOCK1], 51U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 27226U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 32601U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28854U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31235U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 32522U)) & S_BLOCK1], 54U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 5U)) ^ (RotL64(aIngress, 35U) + RotL64(aCross, 54U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = ((aWandererH + RotL64(aCross, 43U)) + RotL64(aCarry, 37U)) + 5568146815535263910U;
            aOrbiterI = (((aWandererC + RotL64(aPrevious, 57U)) + RotL64(aCarry, 57U)) + 7736084960873834666U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = (aWandererB + RotL64(aIngress, 28U)) + 1336413621817562093U;
            aOrbiterG = (aWandererI + RotL64(aScatter, 35U)) + 5218462026934984692U;
            aOrbiterF = ((aWandererD + RotL64(aIngress, 11U)) + RotL64(aCarry, 23U)) + 7048890985969555935U;
            aOrbiterK = (aWandererF + RotL64(aScatter, 5U)) + 13415955213864702118U;
            aOrbiterD = ((aWandererG + RotL64(aCross, 21U)) + 5657023257021528548U) + aPhaseEOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 14338310943137497116U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 12305161641833950473U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11949964304435964395U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 14514226578370459131U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 12692904083266024340U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14800805065279908839U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 11012959130001327964U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 7106471380403489078U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 515626559384817223U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 3718101961355280891U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 13364192077222322664U;
            aOrbiterI = RotL64((aOrbiterI * 1411328915372590283U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 6720867800318913440U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 14497243926965866546U;
            aOrbiterF = RotL64((aOrbiterF * 13595058589060114653U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 5789056168233262435U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 14438482587495779937U;
            aOrbiterD = RotL64((aOrbiterD * 10593535547917767263U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 313917798940179945U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 15241845511889502917U;
            aOrbiterK = RotL64((aOrbiterK * 16483477103771326107U), 3U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterB, 12U);
            aIngress = aIngress + (RotL64(aOrbiterK, 5U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterE, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 13U) + aOrbiterD) + RotL64(aOrbiterE, 35U));
            aWandererH = aWandererH + ((RotL64(aCross, 21U) + RotL64(aOrbiterE, 29U)) + aOrbiterI);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 35U) + aOrbiterK) + RotL64(aOrbiterG, 21U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 42U) + RotL64(aOrbiterG, 47U)) + aOrbiterE) + RotL64(aCarry, 35U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 57U) + aOrbiterD) + RotL64(aOrbiterF, 58U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 5U) + RotL64(aOrbiterB, 41U)) + aOrbiterI) + RotL64(aCarry, 47U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterK, 11U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 60U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 5U));
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererF, 19U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneA, aOperationLaneC, aOperationLaneD, aFireLaneB, aWorkLaneA, aFireLaneC, aFireLaneD, aWorkLaneB, aExpandLaneA, aExpandLaneB, aWorkLaneC, aExpandLaneC, aExpandLaneD
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // twist_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aFireLaneA
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aFireLaneB
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aFireLaneB backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 5339U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneB[((aIndex + 5431U)) & S_BLOCK1], 58U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 7788U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4010U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 1606U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 5368U)) & S_BLOCK1], 46U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCross, 27U)) + (RotL64(aIngress, 12U) ^ RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = (((aWandererC + RotL64(aCross, 23U)) + RotL64(aCarry, 5U)) + 18255347001097480328U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterG = (aWandererD + RotL64(aIngress, 21U)) + 13679246790311505735U;
            aOrbiterH = (aWandererI + RotL64(aPrevious, 3U)) + 10565839529765027116U;
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 13U)) + RotL64(aCarry, 13U)) + 14327172566224769901U;
            aOrbiterI = (aWandererK + RotL64(aIngress, 37U)) + 16239024612038195174U;
            aOrbiterF = (aWandererG + RotL64(aScatter, 10U)) + 13800012174212131890U;
            aOrbiterC = (aWandererE + RotL64(aCross, 41U)) + 13900288860157577583U;
            aOrbiterE = (aWandererB + RotL64(aPrevious, 43U)) + 4144386119777112740U;
            aOrbiterB = ((aWandererF + RotL64(aIngress, 47U)) + RotL64(aCarry, 39U)) + 3154558262670631372U;
            aOrbiterJ = (aWandererA + RotL64(aPrevious, 53U)) + 7456728543137614001U;
            aOrbiterK = ((aWandererH + RotL64(aScatter, 6U)) + 11709519851158935384U) + aPhaseFOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 15607438907832240304U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 9276575329661725624U;
            aOrbiterH = RotL64((aOrbiterH * 8879744070762412745U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 6459435969129449226U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 6442382118416542275U;
            aOrbiterG = RotL64((aOrbiterG * 2921027306686588233U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 12117432107282150865U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 6831279293184793243U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2435360641135249073U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 9520022957804572889U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 8322178689474588679U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1627707191467537115U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 4162401591586869316U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 8994015844714895961U;
            aOrbiterE = RotL64((aOrbiterE * 15421910378057951895U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 10038095909727959633U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 17756404450592957616U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14255952184627347295U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 3379089265413427719U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 11341713098678108441U;
            aOrbiterA = RotL64((aOrbiterA * 2500587373161411961U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 4030296130743454165U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 6332387792111212064U;
            aOrbiterJ = RotL64((aOrbiterJ * 16490982218150897861U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 14893209417387662133U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 9265457389326311687U;
            aOrbiterK = RotL64((aOrbiterK * 9778404505547862689U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 13496086915199406901U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 14576555328710787951U;
            aOrbiterB = RotL64((aOrbiterB * 13155395071667672943U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 11482324648071976743U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 18255347001097480328U;
            aOrbiterF = RotL64((aOrbiterF * 10918514878283385643U), 57U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterE, 58U);
            aIngress = aIngress + (RotL64(aOrbiterI, 13U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 51U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 39U));
            aIngress = aIngress + (RotL64(aOrbiterC, 47U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterB, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterC, 4U)) + aOrbiterI) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterI, 11U)) + aOrbiterE);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 36U) + RotL64(aOrbiterK, 13U)) + aOrbiterH);
            aWandererK = aWandererK + (((RotL64(aCross, 13U) + RotL64(aOrbiterB, 39U)) + aOrbiterJ) + RotL64(aCarry, 13U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterK, 50U)) + aOrbiterE) + aPhaseFWandererUpdateSaltD[((aIndex + 20U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 11U) + aOrbiterG) + RotL64(aOrbiterC, 19U)) + RotL64(aCarry, 3U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 57U) + aOrbiterC) + RotL64(aOrbiterJ, 47U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 24U) + RotL64(aOrbiterC, 35U)) + aOrbiterA);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 27U) + aOrbiterG) + RotL64(aOrbiterD, 27U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 29U) + aOrbiterC) + RotL64(aOrbiterK, 37U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterF, 29U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererF, 58U) ^ aWandererI);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererG);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 41U));
            aCarry = aCarry + RotL64(aWandererH, 56U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 2
        // ingress from: aWorkLaneA, aOperationLaneC, aOperationLaneD, aFireLaneC
        // ingress directions: aWorkLaneA forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aFireLaneD
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aFireLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 12455U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneC[((aIndex + 10679U)) & S_BLOCK1], 47U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 8888U)) & S_BLOCK1], 27U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 9236U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 13479U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 8561U)) & S_BLOCK1], 20U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 13926U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 29U) + RotL64(aPrevious, 13U)) ^ (RotL64(aCarry, 42U) ^ RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 50U)) + 6973892330986118220U;
            aOrbiterD = (aWandererG + RotL64(aCross, 57U)) + 9886813896272094864U;
            aOrbiterA = (((aWandererE + RotL64(aScatter, 23U)) + RotL64(aCarry, 35U)) + 10996306582517553173U) + aPhaseFOrbiterAssignSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aIngress, 39U)) + RotL64(aCarry, 19U)) + 8490648283899856223U;
            aOrbiterI = (aWandererD + RotL64(aCross, 19U)) + 105141713530704655U;
            aOrbiterC = (aWandererJ + RotL64(aIngress, 41U)) + 3114337422810562588U;
            aOrbiterG = (aWandererH + RotL64(aScatter, 13U)) + 980857684690886131U;
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 27U)) + RotL64(aCarry, 39U)) + 6562042345807072665U;
            aOrbiterK = (aWandererC + RotL64(aScatter, 52U)) + 15665371138706353619U;
            aOrbiterH = (aWandererK + RotL64(aIngress, 3U)) + 18113013571374375028U;
            aOrbiterE = ((aWandererA + RotL64(aCross, 5U)) + 17405346422601997299U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 5130876096426182506U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 1813821672299154629U;
            aOrbiterA = RotL64((aOrbiterA * 15478100342425611875U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 15793814882743306728U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 13925299440495476399U;
            aOrbiterI = RotL64((aOrbiterI * 12049601510660117401U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 9924458846049579438U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 7810034662781768090U;
            aOrbiterJ = RotL64((aOrbiterJ * 10310594595026622513U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 12812586478656872854U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 5709576448057435237U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9101555233909853025U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 7839807649914541516U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 4717944526755429647U;
            aOrbiterC = RotL64((aOrbiterC * 8515229146471335721U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 3933911971504256022U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 4814079680865379831U;
            aOrbiterD = RotL64((aOrbiterD * 15100740696230557391U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 18352577312212175569U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 9670612998448920742U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5743579439303300553U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 72737302703035726U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 10032869372369626210U;
            aOrbiterK = RotL64((aOrbiterK * 7449905669249993731U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 2669999453643982386U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 2016129534922291383U;
            aOrbiterB = RotL64((aOrbiterB * 11730911201750754301U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 5108689262300895422U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 3753457479225942895U;
            aOrbiterE = RotL64((aOrbiterE * 11503304711866175497U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 859776381005289485U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 6973892330986118220U;
            aOrbiterH = RotL64((aOrbiterH * 12337041087475258221U), 3U);
            //
            aIngress = RotL64(aOrbiterG, 43U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 6U));
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 11U));
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 21U) + aOrbiterJ) + RotL64(aOrbiterA, 54U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterK, 39U)) + aOrbiterH) + aPhaseFWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterJ, 11U)) + aOrbiterI);
            aWandererA = aWandererA + ((RotL64(aIngress, 57U) + aOrbiterD) + RotL64(aOrbiterE, 43U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 10U) + aOrbiterH) + RotL64(aOrbiterF, 13U)) + aPhaseFWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 27U) + RotL64(aOrbiterH, 60U)) + aOrbiterE) + RotL64(aCarry, 57U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterC, 57U)) + aOrbiterA);
            aWandererF = aWandererF + (((RotL64(aScatter, 39U) + aOrbiterG) + RotL64(aOrbiterH, 35U)) + RotL64(aCarry, 23U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 34U) + RotL64(aOrbiterI, 29U)) + aOrbiterD);
            aWandererC = aWandererC + ((RotL64(aCross, 3U) + aOrbiterG) + RotL64(aOrbiterD, 5U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterD, 19U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererB, 50U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + (RotL64(aWandererD, 41U) ^ aWandererC);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererJ, 52U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_c loop 3
        // ingress from: aWorkLaneB, aOperationLaneA, aOperationLaneB, aExpandLaneA
        // ingress directions: aWorkLaneB forward forced, aOperationLaneA forward forced, aOperationLaneB forward forced, aExpandLaneA forward/backward random
        // cross from: aWorkLaneA, aOperationLaneC, aExpandLaneB
        // cross directions: aWorkLaneA backward forced, aOperationLaneC backward forced, aExpandLaneB backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 16732U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneA[((aIndex + 17791U)) & S_BLOCK1], 12U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 16631U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 18500U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22215U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 19131U)) & S_BLOCK1], 44U));
            aCross ^= RotL64(aExpandLaneB[((aIndex + 21924U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 29U) ^ RotL64(aIngress, 57U)) ^ (RotL64(aCarry, 11U) + RotL64(aPrevious, 42U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = ((aWandererK + RotL64(aIngress, 43U)) + RotL64(aCarry, 57U)) + 12131317914288566437U;
            aOrbiterE = (aWandererB + RotL64(aPrevious, 13U)) + 5672805657999385496U;
            aOrbiterF = ((aWandererD + RotL64(aScatter, 3U)) + RotL64(aCarry, 21U)) + 3581710244233124197U;
            aOrbiterJ = (aWandererC + RotL64(aCross, 41U)) + 15251296040538489436U;
            aOrbiterH = ((aWandererE + RotL64(aIngress, 24U)) + 11295008604679904153U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = (aWandererI + RotL64(aCross, 47U)) + 2230897493419504490U;
            aOrbiterB = (aWandererF + RotL64(aPrevious, 29U)) + 7109600123297458999U;
            aOrbiterK = (aWandererH + RotL64(aScatter, 19U)) + 13119156643107683803U;
            aOrbiterD = (aWandererA + RotL64(aIngress, 37U)) + 14755160867807355250U;
            aOrbiterC = (aWandererG + RotL64(aCross, 10U)) + 16829363373287496832U;
            aOrbiterI = (((aWandererJ + RotL64(aPrevious, 57U)) + RotL64(aCarry, 3U)) + 16981122946707720883U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 8806000776958603317U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 16810923047720876014U;
            aOrbiterF = RotL64((aOrbiterF * 17872735050219539145U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 8129657889554436328U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 8653100378491974463U;
            aOrbiterA = RotL64((aOrbiterA * 11395283153912468661U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 17048985838727432415U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 10892675550889823573U;
            aOrbiterB = RotL64((aOrbiterB * 976298937314081913U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 15960158965421254346U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 12290011578634850001U;
            aOrbiterJ = RotL64((aOrbiterJ * 9280475585104357745U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 16265047040311479093U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 10312956912303656248U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3012584393253845131U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 16706890352221352779U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 10630955894218491929U;
            aOrbiterE = RotL64((aOrbiterE * 12675937483456206355U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 4009352551041162434U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 3043810773683888556U;
            aOrbiterC = RotL64((aOrbiterC * 4328135390387997315U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 1398071019814944785U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 16689766557488135301U;
            aOrbiterD = RotL64((aOrbiterD * 8403881916549404871U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 15934647144489136524U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 13521276033614992223U;
            aOrbiterI = RotL64((aOrbiterI * 18003640895553609933U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 4281211055727414100U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 11848150507497406421U;
            aOrbiterG = RotL64((aOrbiterG * 1107789990317433481U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 12022829841608199449U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 12131317914288566437U;
            aOrbiterK = RotL64((aOrbiterK * 13275753083882829973U), 29U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterK, 35U);
            aIngress = aIngress + (RotL64(aOrbiterG, 46U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 13U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 19U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 21U));
            aIngress = aIngress + RotL64(aOrbiterA, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterI, 57U)) + aOrbiterG) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 10U) + RotL64(aOrbiterJ, 26U)) + aOrbiterK);
            aWandererD = aWandererD + ((RotL64(aCross, 13U) + RotL64(aOrbiterK, 53U)) + aOrbiterB);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 51U) + aOrbiterA) + RotL64(aOrbiterK, 35U));
            aWandererE = aWandererE + (((RotL64(aScatter, 3U) + aOrbiterE) + RotL64(aOrbiterD, 19U)) + RotL64(aCarry, 19U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 35U) + aOrbiterF) + RotL64(aOrbiterD, 48U));
            aWandererK = aWandererK + ((RotL64(aIngress, 37U) + aOrbiterC) + RotL64(aOrbiterG, 3U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 48U) + RotL64(aOrbiterC, 29U)) + aOrbiterH);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 29U) + aOrbiterD) + RotL64(aOrbiterC, 13U)) + RotL64(aCarry, 13U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterJ, 5U)) + aOrbiterH) + aPhaseFWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 41U) + RotL64(aOrbiterC, 41U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 24U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererJ, 51U);
            aCarry = aCarry + RotL64(aIngress, 38U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 4
        // ingress from: aWorkLaneC, aWorkLaneA, aOperationLaneD, aExpandLaneC
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aOperationLaneD forward forced, aExpandLaneC forward/backward random
        // cross from: aWorkLaneB, aOperationLaneB, aExpandLaneD
        // cross directions: aWorkLaneB backward forced, aOperationLaneB backward forced, aExpandLaneD backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 26339U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneA[((aIndex + 29927U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 27791U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 32069U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25500U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31452U)) & S_BLOCK1], 36U));
            aCross ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 29602U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aPrevious, 27U)) + (RotL64(aIngress, 56U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = ((aWandererD + RotL64(aIngress, 41U)) + RotL64(aCarry, 19U)) + 17264605017518259932U;
            aOrbiterC = (aWandererB + RotL64(aPrevious, 11U)) + 15209184354580778643U;
            aOrbiterJ = (aWandererC + RotL64(aCross, 13U)) + 3299527965014731384U;
            aOrbiterB = ((aWandererF + RotL64(aScatter, 5U)) + RotL64(aCarry, 39U)) + 16293096431816127821U;
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 51U)) + 11031983436878828337U) + aPhaseFOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = (aWandererA + RotL64(aCross, 37U)) + 9188018632448236358U;
            aOrbiterA = (aWandererH + RotL64(aScatter, 18U)) + 13420816400363406556U;
            aOrbiterI = (aWandererE + RotL64(aPrevious, 35U)) + 2485063384097917101U;
            aOrbiterG = (aWandererG + RotL64(aIngress, 53U)) + 3089135816938128264U;
            aOrbiterH = ((aWandererK + RotL64(aCross, 57U)) + RotL64(aCarry, 47U)) + 10730544971770435788U;
            aOrbiterE = ((aWandererI + RotL64(aPrevious, 48U)) + 10431767565618874806U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 14883796491656899074U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 13465877783538483706U;
            aOrbiterJ = RotL64((aOrbiterJ * 14311686051108108503U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 13322163435314643713U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 3307316600284371955U;
            aOrbiterF = RotL64((aOrbiterF * 12337846092069506365U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 4950101626975919939U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 2596253994220103666U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7181706961838582889U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 17961706029559914243U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 10321902557977495175U;
            aOrbiterI = RotL64((aOrbiterI * 16189559888625084711U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 18146616411403012772U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 8414050129421955787U;
            aOrbiterC = RotL64((aOrbiterC * 14879448948196182863U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 11739172334166341121U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 7936637782633487291U;
            aOrbiterG = RotL64((aOrbiterG * 14940929920543800413U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 3160044627483874242U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 16816384076887379704U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5052772186568301951U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 8101560104988710226U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 8851416379738817624U;
            aOrbiterH = RotL64((aOrbiterH * 16767420038937389027U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 9941784290055185679U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 14495651885701938495U;
            aOrbiterE = RotL64((aOrbiterE * 1540692851998143607U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 10599676325220702167U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 16092000942942971187U;
            aOrbiterD = RotL64((aOrbiterD * 2457268192247656817U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 16168470945107928109U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 17264605017518259932U;
            aOrbiterA = RotL64((aOrbiterA * 15038386057529909273U), 53U);
            //
            aIngress = RotL64(aOrbiterH, 57U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 11U));
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 13U));
            aIngress = aIngress + (RotL64(aOrbiterC, 30U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterK, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 11U) + aOrbiterE) + RotL64(aOrbiterI, 29U));
            aWandererD = aWandererD + (((RotL64(aIngress, 34U) + RotL64(aOrbiterD, 23U)) + aOrbiterG) + RotL64(aCarry, 21U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterE, 21U)) + aOrbiterD) + aPhaseFWandererUpdateSaltE[((aIndex + 6U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aCross, 43U) + RotL64(aOrbiterB, 13U)) + aOrbiterJ);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 29U) + aOrbiterI) + RotL64(aOrbiterK, 11U));
            aWandererE = aWandererE + ((RotL64(aCross, 21U) + RotL64(aOrbiterA, 37U)) + aOrbiterB);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 23U) + aOrbiterG) + RotL64(aOrbiterI, 56U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterB, 41U)) + aOrbiterC) + RotL64(aCarry, 37U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterI, 39U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aCross, 4U) + aOrbiterF) + RotL64(aOrbiterH, 43U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterH, 54U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererF, 28U) ^ aWandererK);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 11U));
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 44U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererH, 5U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
        // ingress from: aWorkLaneA, aWorkLaneB, aWorkLaneC
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aWorkLaneC forward/backward random
        // cross from: aWorkLaneB, aWorkLaneC, aWorkLaneD
        // cross directions: aWorkLaneB backward forced, aWorkLaneC backward forced, aWorkLaneD backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 5052U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((aIndex + 4135U)) & S_BLOCK1], 44U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 7869U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 1083U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 5624U)) & S_BLOCK1], 22U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 6966U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 22U) ^ RotL64(aIngress, 5U)) + (RotL64(aCross, 37U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = ((aWandererA + RotL64(aCross, 3U)) + 15036852811491820366U) + aPhaseGOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = (((aWandererF + RotL64(aIngress, 20U)) + RotL64(aCarry, 53U)) + 305637140752898475U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 53U)) + RotL64(aCarry, 3U)) + 11948631574496129610U;
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 29U)) + RotL64(aCarry, 35U)) + 5321623592482991426U;
            aOrbiterC = (aWandererB + RotL64(aIngress, 43U)) + 4075270159062690728U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 15111580500356908928U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 7244150695504160363U;
            aOrbiterI = RotL64((aOrbiterI * 2445733898697939969U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 5131563519577488862U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 5881954992088651371U;
            aOrbiterC = RotL64((aOrbiterC * 2424421828597294607U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 12780935808751507998U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 12599159643925470226U;
            aOrbiterF = RotL64((aOrbiterF * 17690046932587062701U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 9466589929741834066U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 6093158735705189789U;
            aOrbiterD = RotL64((aOrbiterD * 7453778295800853653U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 17461243886150519249U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 15456408913739900718U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16093292401746174671U), 37U);
            //
            aIngress = RotL64(aOrbiterB, 13U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterD, 54U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterF, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aPrevious, 58U) + RotL64(aOrbiterB, 11U)) + aOrbiterF);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 23U) + aOrbiterC) + RotL64(aOrbiterI, 3U));
            aWandererI = aWandererI + ((((RotL64(aCross, 35U) + aOrbiterB) + RotL64(aOrbiterD, 37U)) + RotL64(aCarry, 21U)) + aPhaseGWandererUpdateSaltE[((aIndex + 6U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 3U) + aOrbiterD) + RotL64(aOrbiterI, 48U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 43U) + aOrbiterF) + RotL64(aOrbiterC, 19U)) + RotL64(aCarry, 3U)) + aPhaseGWandererUpdateSaltF[((aIndex + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + RotL64(aWandererF, 58U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // grow_key_a loop 2
        // ingress from: aExpandLaneA, aWorkLaneB, aWorkLaneC
        // ingress directions: aExpandLaneA forward forced, aWorkLaneB forward forced, aWorkLaneC forward/backward random
        // cross from: aWorkLaneB, aWorkLaneC, aWorkLaneD
        // cross directions: aWorkLaneB backward forced, aWorkLaneC backward forced, aWorkLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 12468U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((aIndex + 12152U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 12174U)) & S_BLOCK1], 54U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 14894U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 14780U)) & S_BLOCK1], 28U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 11605U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aIngress, 22U)) + (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = ((aWandererK + RotL64(aScatter, 54U)) + RotL64(aCarry, 51U)) + 13714409587461539863U;
            aOrbiterD = ((aWandererI + RotL64(aCross, 19U)) + RotL64(aCarry, 37U)) + 14101156723903265839U;
            aOrbiterB = (((aWandererG + RotL64(aIngress, 11U)) + RotL64(aCarry, 13U)) + 7063754562895369001U) + aPhaseGOrbiterAssignSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterH = (aWandererH + RotL64(aPrevious, 27U)) + 12320578575245519386U;
            aOrbiterK = ((aWandererD + RotL64(aCross, 35U)) + 11744826789631008424U) + aPhaseGOrbiterAssignSaltA[((aIndex + 6U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 8744816505096675597U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 10405435520084528645U;
            aOrbiterB = RotL64((aOrbiterB * 13279521344071568023U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 1463157688070683543U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 12379603577919617703U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14858901470015109311U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 1343439118031348146U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 16118850268070235540U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11184386483735388257U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 14116264435819277136U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 5251698273012432109U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1495818611622063967U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 14806408656041403829U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 11569345414052398227U;
            aOrbiterH = RotL64((aOrbiterH * 9913158908301414861U), 39U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterB, 42U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 29U));
            aIngress = aIngress + RotL64(aOrbiterD, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aScatter, 5U) + aOrbiterA) + RotL64(aOrbiterD, 13U)) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 13U) + aOrbiterA) + RotL64(aOrbiterH, 44U)) + RotL64(aCarry, 23U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterH, 5U)) + aOrbiterB) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 21U) + aOrbiterH) + RotL64(aOrbiterD, 21U)) + RotL64(aCarry, 51U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 34U) + aOrbiterK) + RotL64(aOrbiterD, 53U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + RotL64(aWandererK, 58U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // grow_key_a loop 3
        // ingress from: aExpandLaneB, aExpandLaneA, aWorkLaneD
        // ingress directions: aExpandLaneB forward forced, aExpandLaneA forward forced, aWorkLaneD forward/backward random
        // cross from: aExpandLaneA, aWorkLaneD, aWorkLaneC
        // cross directions: aExpandLaneA backward forced, aWorkLaneD backward forced, aWorkLaneC backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 24530U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneA[((aIndex + 22635U)) & S_BLOCK1], 14U));
            aIngress ^= RotL64(aWorkLaneD[((aIndex + 24129U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22785U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 18702U)) & S_BLOCK1], 44U));
            aCross ^= RotL64(aWorkLaneC[((aIndex + 19016U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 28U) ^ RotL64(aCarry, 3U)) + (RotL64(aPrevious, 41U) + RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = ((aWandererK + RotL64(aIngress, 57U)) + RotL64(aCarry, 39U)) + 1457104756581596530U;
            aOrbiterH = (aWandererG + RotL64(aCross, 46U)) + 6127240317844622874U;
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 35U)) + 16492290056044189421U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = (((aWandererA + RotL64(aScatter, 11U)) + RotL64(aCarry, 13U)) + 10963676850938416468U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 21U)) + RotL64(aCarry, 57U)) + 4872917367399752405U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 15218882377875616148U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 5934166612122118251U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10365045124180379919U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 14215280930872003003U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 11428034799044600979U;
            aOrbiterC = RotL64((aOrbiterC * 12162528943733976177U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 5453003654321728726U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 14273775120265649389U;
            aOrbiterB = RotL64((aOrbiterB * 5139018128323795309U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 328723770018440271U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 13032190719588211088U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13363368478932798315U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 2386881543033598494U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 1649501123340887116U;
            aOrbiterE = RotL64((aOrbiterE * 11148976582360499033U), 51U);
            //
            aIngress = RotL64(aOrbiterE, 5U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterC, 29U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterH, 52U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aScatter, 57U) + aOrbiterC) + RotL64(aOrbiterE, 27U)) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 10U) + aOrbiterA) + RotL64(aOrbiterE, 19U)) + RotL64(aCarry, 29U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 47U) + aOrbiterB) + RotL64(aOrbiterH, 5U));
            aWandererA = aWandererA + ((((RotL64(aPrevious, 37U) + aOrbiterH) + RotL64(aOrbiterA, 58U)) + RotL64(aCarry, 57U)) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 23U) + aOrbiterC) + RotL64(aOrbiterB, 37U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererK, 39U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // grow_key_a loop 4
        // ingress from: aExpandLaneC, aExpandLaneB, aExpandLaneA
        // ingress directions: aExpandLaneC forward forced, aExpandLaneB forward forced, aExpandLaneA forward/backward random
        // cross from: aExpandLaneA, aExpandLaneB, aExpandLaneC
        // cross directions: aExpandLaneA backward forced, aExpandLaneB backward forced, aExpandLaneC backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 26781U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((aIndex + 30567U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aExpandLaneA[((aIndex + 30102U)) & S_BLOCK1], 14U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25340U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25182U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 25743U)) & S_BLOCK1], 38U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 41U) + RotL64(aCarry, 13U)) ^ (RotL64(aIngress, 57U) + RotL64(aCross, 26U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = (aWandererA + RotL64(aCross, 60U)) + 13278949403988203974U;
            aOrbiterD = (aWandererH + RotL64(aIngress, 29U)) + 9213599924054673756U;
            aOrbiterI = (((aWandererK + RotL64(aScatter, 41U)) + RotL64(aCarry, 43U)) + 1255746482932381798U) + aPhaseGOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = (((aWandererC + RotL64(aPrevious, 13U)) + RotL64(aCarry, 5U)) + 11575321997144516122U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = ((aWandererE + RotL64(aCross, 5U)) + RotL64(aCarry, 57U)) + 15881587525529432437U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 9846195809864862707U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 12319815691858217670U;
            aOrbiterI = RotL64((aOrbiterI * 14271546305640811091U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 16322617427294439587U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 16332130810525887437U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7588076439690559343U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 4920951156015336794U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 16767126455124552329U;
            aOrbiterG = RotL64((aOrbiterG * 4440352337076842603U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 12553595911087945223U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 1437522202135436142U;
            aOrbiterD = RotL64((aOrbiterD * 2001992794165550905U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 12313100454852227143U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 2761983020631055729U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3874839760378039509U), 39U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterI, 3U);
            aIngress = aIngress + (RotL64(aOrbiterF, 42U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterG, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterB, 29U)) + aOrbiterF);
            aWandererE = aWandererE + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterG, 11U)) + aOrbiterD) + RotL64(aCarry, 51U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 50U) + aOrbiterF) + RotL64(aOrbiterG, 48U));
            aWandererH = aWandererH + ((((RotL64(aCross, 27U) + RotL64(aOrbiterF, 3U)) + aOrbiterI) + RotL64(aCarry, 37U)) + aPhaseGWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 13U) + aOrbiterI) + RotL64(aOrbiterD, 57U)) + aPhaseGWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererC, 47U);
            aCarry = aCarry + RotL64(aIngress, 38U);
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
        // ingress from: aExpandLaneA, aExpandLaneB, aExpandLaneC
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aExpandLaneC forward/backward random
        // cross from: aExpandLaneB, aExpandLaneC, aExpandLaneD
        // cross directions: aExpandLaneB backward forced, aExpandLaneC backward forced, aExpandLaneD backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 5396U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneB[((aIndex + 1131U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5143U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 3217U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1064U)) & S_BLOCK1], 48U));
            aCross ^= RotL64(aExpandLaneD[((aIndex + 5928U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 11U) + RotL64(aCarry, 53U)) ^ (RotL64(aPrevious, 24U) + RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 50U)) + RotL64(aCarry, 19U)) + 11450949896247900941U;
            aOrbiterK = (((aWandererE + RotL64(aCross, 3U)) + RotL64(aCarry, 41U)) + 3905542253538116335U) + aPhaseHOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = (((aWandererJ + RotL64(aIngress, 19U)) + RotL64(aCarry, 57U)) + 9529740545977785305U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = (aWandererF + RotL64(aScatter, 39U)) + 1856876631533143492U;
            aOrbiterD = (aWandererH + RotL64(aPrevious, 11U)) + 84253466320181686U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 12577480918745432444U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 5625703170397704029U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13583960724598036659U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 694608607323629282U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 3993981243536262204U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2502835860198146381U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 4119215953484892051U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 8785040118556157146U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17113521266125471625U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 16234403619456882890U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 10398727475672860610U;
            aOrbiterK = RotL64((aOrbiterK * 5086871400049644715U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 18327987141759096769U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 2645964788056875452U;
            aOrbiterG = RotL64((aOrbiterG * 8778681366114628045U), 35U);
            //
            aIngress = RotL64(aOrbiterG, 48U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 27U));
            aIngress = aIngress + RotL64(aOrbiterD, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 29U) + aOrbiterG) + RotL64(aOrbiterI, 52U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 13U) + RotL64(aOrbiterI, 11U)) + aOrbiterA) + RotL64(aCarry, 21U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 41U) + aOrbiterI) + RotL64(aOrbiterK, 19U)) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 58U) + aOrbiterK) + RotL64(aOrbiterD, 3U)) + RotL64(aCarry, 5U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterA, 27U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + RotL64(aWandererF, 27U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // grow_key_b loop 2
        // ingress from: aWorkLaneA, aExpandLaneB, aExpandLaneC
        // ingress directions: aWorkLaneA forward forced, aExpandLaneB forward forced, aExpandLaneC forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aWorkLaneA
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aWorkLaneA backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 14896U)) & S_BLOCK1], 18U) ^ RotL64(aExpandLaneB[((aIndex + 10933U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 12817U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 13827U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 8192U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 11039U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 47U) ^ RotL64(aCross, 5U)) + (RotL64(aCarry, 20U) + RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = (((aWandererG + RotL64(aCross, 22U)) + RotL64(aCarry, 29U)) + 13499155707765393469U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = (aWandererK + RotL64(aIngress, 3U)) + 3740324981823726185U;
            aOrbiterK = ((aWandererD + RotL64(aScatter, 39U)) + 5470765363949735652U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 51U)) + RotL64(aCarry, 11U)) + 3446436171274452326U;
            aOrbiterD = ((aWandererE + RotL64(aIngress, 13U)) + RotL64(aCarry, 43U)) + 1778929412631211933U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 14666308799855220954U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 4548410236791175055U;
            aOrbiterK = RotL64((aOrbiterK * 6822908616815218501U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 5829739767694190372U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 14319231414903675748U;
            aOrbiterD = RotL64((aOrbiterD * 4966501102515775601U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 1513851750246111405U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 1685620217748986019U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9286548037413609445U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 16284162182006054402U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 6271539598462003309U;
            aOrbiterG = RotL64((aOrbiterG * 13923286694131331137U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 12669312437565969473U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 11894755313393001665U;
            aOrbiterH = RotL64((aOrbiterH * 12556759675372354075U), 41U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterH, 44U);
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterG, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterG, 39U)) + aOrbiterJ);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 41U) + RotL64(aOrbiterD, 11U)) + aOrbiterH) + RotL64(aCarry, 37U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterJ, 21U)) + aOrbiterH);
            aWandererG = aWandererG + (((RotL64(aScatter, 54U) + RotL64(aOrbiterD, 56U)) + aOrbiterK) + RotL64(aCarry, 53U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterG, 3U)) + aOrbiterH) + aPhaseHWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 21U) ^ aWandererK);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 5U));
            aCarry = aCarry + RotL64(aWandererF, 13U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // grow_key_b loop 3
        // ingress from: aWorkLaneB, aWorkLaneA, aExpandLaneD
        // ingress directions: aWorkLaneB forward forced, aWorkLaneA forward forced, aExpandLaneD forward/backward random
        // cross from: aWorkLaneA, aExpandLaneD, aExpandLaneC
        // cross directions: aWorkLaneA backward forced, aExpandLaneD backward forced, aExpandLaneC backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 17601U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((aIndex + 19554U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 20363U)) & S_BLOCK1], 56U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20213U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 23452U)) & S_BLOCK1], 60U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 17445U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 21U) + RotL64(aIngress, 40U)) ^ (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 13U)) + RotL64(aCarry, 27U)) + 13880995121909552664U;
            aOrbiterA = (((aWandererB + RotL64(aIngress, 51U)) + RotL64(aCarry, 53U)) + 14534942818069300546U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = (((aWandererG + RotL64(aCross, 5U)) + RotL64(aCarry, 5U)) + 17745973100886007133U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = (aWandererA + RotL64(aScatter, 21U)) + 2249805580771946872U;
            aOrbiterD = (aWandererE + RotL64(aCross, 36U)) + 4460116116396439410U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 3378683994078106878U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 3992996501048809123U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13273544260537223797U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 12057768808864451929U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 4115362079047921130U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12263015903331031345U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 15297384955502206698U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 17623548383481905636U;
            aOrbiterA = RotL64((aOrbiterA * 7487278217901483685U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 3559213898000162417U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 12311605719074507335U;
            aOrbiterD = RotL64((aOrbiterD * 3982199462062847697U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 14807313864347885885U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 11222085523291581822U;
            aOrbiterE = RotL64((aOrbiterE * 12580941911587215653U), 29U);
            //
            aIngress = RotL64(aOrbiterE, 53U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 13U));
            aIngress = aIngress + RotL64(aOrbiterA, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aCross, 51U) + aOrbiterD) + RotL64(aOrbiterE, 41U)) + aPhaseHWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aScatter, 40U) + RotL64(aOrbiterA, 13U)) + aOrbiterE) + RotL64(aCarry, 11U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 19U) + aOrbiterB) + RotL64(aOrbiterH, 27U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterA, 3U)) + aOrbiterH) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterD, 58U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererC);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + RotL64(aWandererB, 19U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // grow_key_b loop 4
        // ingress from: aWorkLaneC, aWorkLaneB, aWorkLaneA
        // ingress directions: aWorkLaneC forward forced, aWorkLaneB forward forced, aWorkLaneA forward/backward random
        // cross from: aWorkLaneA, aWorkLaneB, aWorkLaneC
        // cross directions: aWorkLaneA backward forced, aWorkLaneB backward forced, aWorkLaneC backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 31357U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((aIndex + 27659U)) & S_BLOCK1], 6U));
            aIngress ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 29669U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26565U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32227U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aWorkLaneC[((aIndex + 24626U)) & S_BLOCK1], 30U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 21U) ^ RotL64(aCarry, 57U)) ^ (RotL64(aCross, 37U) + RotL64(aIngress, 6U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = ((aWandererG + RotL64(aCross, 11U)) + 4970414922752555648U) + aPhaseHOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = ((aWandererA + RotL64(aScatter, 21U)) + RotL64(aCarry, 5U)) + 9462756592787669327U;
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 52U)) + 3948790686662213095U) + aPhaseHOrbiterAssignSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = ((aWandererK + RotL64(aIngress, 39U)) + RotL64(aCarry, 51U)) + 14542857212241578311U;
            aOrbiterK = ((aWandererF + RotL64(aCross, 29U)) + RotL64(aCarry, 27U)) + 3387479009827029547U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 1411421370057797877U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 16894451466895681236U;
            aOrbiterG = RotL64((aOrbiterG * 13825974818858676215U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 12727136462290223542U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 4625389198191960525U;
            aOrbiterD = RotL64((aOrbiterD * 5726474430977810191U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 3471881403786164913U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 6433115856048534831U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9363233870194144053U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 9825592965466157982U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 1553125767261293088U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 411535191177308781U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 9951616357109647617U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 11231080382787286889U;
            aOrbiterC = RotL64((aOrbiterC * 14024961994986659187U), 35U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterG, 3U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + RotL64(aOrbiterD, 40U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterG, 41U)) + aOrbiterB) + RotL64(aCarry, 29U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 3U) + aOrbiterD) + RotL64(aOrbiterG, 51U)) + aPhaseHWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 56U) + RotL64(aOrbiterK, 28U)) + aOrbiterD) + RotL64(aCarry, 43U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterC, 3U)) + aOrbiterK) + aPhaseHWandererUpdateSaltE[((aIndex + 24U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aScatter, 47U) + aOrbiterC) + RotL64(aOrbiterB, 11U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 21U));
            aCarry = aCarry + RotL64(aWandererA, 57U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
