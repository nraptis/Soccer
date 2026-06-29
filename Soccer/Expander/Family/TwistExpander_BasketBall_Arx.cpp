#include "TwistExpander_BasketBall_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_BasketBall_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x8D288E4A2A9CBF83ULL + 0x9F23889B1F88A6CAULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x87B8600351AEB9CDULL + 0x92632CB6E9AE5AB5ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xCCE84E4AB2A96FBFULL + 0xA9EDA2A5F9E83B84ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xEFADA403CF29481BULL + 0x8FD0D3904ED64DC4ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x80E5DD70314750B1ULL + 0xC49E01833901FC1DULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xE2460AB45D817D07ULL + 0xCF2698F533FA5AE8ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xE3AEB1B76B9BC471ULL + 0xECF5B11AE778FF38ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xF2189CAC8CCE1E75ULL + 0xA718D16DD3D4F318ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x9BECCB7875893AADULL + 0xEBF67A9561AD2B32ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xFCA7E4308562408FULL + 0x94AC55BAA749F1A8ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x8B232D6DC68CF171ULL + 0x997B8A014645BAB9ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xBA02CF6031DD3E53ULL + 0xE83E37BE57A2B700ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xEF656CB341B642C9ULL + 0xECD4980C2AFA603FULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xA29E944847E9D0C7ULL + 0xE986FFDFE06D1CEEULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xF86F63EA3CDDB693ULL + 0xD0AF8ECB29FC4FC4ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xBF2709D7294920CBULL + 0xAD3AE3850789C091ULL);
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
            aIngress = RotL64(mSource[((aIndex + 1287U)) & S_BLOCK1], 19U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 4554U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 5023U)) & S_BLOCK1], 3U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 4953U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 37U) + RotL64(aPrevious, 51U)) ^ (RotL64(aCross, 19U) ^ RotL64(aIngress, 6U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterJ = (aWandererD + RotL64(aPrevious, 3U)) + 9446153639709651566U;
            aOrbiterB = (aWandererE + RotL64(aIngress, 21U)) + 10550762260670758167U;
            aOrbiterD = ((aWandererA + RotL64(aCross, 47U)) + 7062634922142578383U) + aOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = (aWandererK + RotL64(aScatter, 51U)) + 9178499097812764515U;
            aOrbiterC = (aWandererH + RotL64(aCross, 38U)) + 6887103379773525538U;
            aOrbiterF = (aWandererG + RotL64(aPrevious, 29U)) + 6239750312052010257U;
            aOrbiterA = ((aWandererC + RotL64(aScatter, 35U)) + RotL64(aCarry, 43U)) + 17645022614523287959U;
            aOrbiterE = ((((aWandererJ + RotL64(aIngress, 43U)) + RotL64(aCarry, 29U)) + 3639618183259408272U) + aOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordP;
            aOrbiterK = ((aWandererB + RotL64(aCross, 23U)) + RotL64(aCarry, 39U)) + 3131737117548745095U;
            aOrbiterI = ((aWandererF + RotL64(aScatter, 12U)) + 7253994382396406554U) + aNonceWordN;
            aOrbiterH = (aWandererI + RotL64(aPrevious, 19U)) + 15217993711938379561U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 12594152227603630033U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 11250170200489647869U) ^ aNonceWordO;
            aOrbiterD = RotL64((aOrbiterD * 546800378327864723U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 12936942656624279424U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 10990736056052106149U) ^ aNonceWordL;
            aOrbiterF = RotL64((aOrbiterF * 7123916809953459187U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 12787293075893090465U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 17154990205620778151U) ^ aNonceWordB;
            aOrbiterE = RotL64((aOrbiterE * 10031369940028159521U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 1270827262969060301U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 17337623431665013136U;
            aOrbiterK = RotL64((aOrbiterK * 1517262088236356107U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 830330490987911853U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 6828309232554560547U;
            aOrbiterA = RotL64((aOrbiterA * 9742464176986145819U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 11470087853413986203U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 10470148870747884420U) ^ aNonceWordM;
            aOrbiterC = RotL64((aOrbiterC * 6766079738799967443U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 18315536891901859637U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 12264670822285914271U;
            aOrbiterG = RotL64((aOrbiterG * 5841574505408674119U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 10931842095884524879U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 11134871340959676257U;
            aOrbiterB = RotL64((aOrbiterB * 11714837622285605745U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 11484168476761306078U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 5964766416973454097U) ^ aOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14721123403032510803U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 10646362765367117994U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 8994267196877016381U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17386417559346134797U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 16797547458402042464U) + aOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 9446153639709651566U;
            aOrbiterJ = RotL64((aOrbiterJ * 567585472220695323U), 53U);
            //
            aIngress = RotL64(aOrbiterJ, 53U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 21U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 37U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 51U));
            aIngress = aIngress + RotL64(aOrbiterB, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 40U) + aOrbiterH) + RotL64(aOrbiterF, 51U));
            aWandererA = aWandererA + ((RotL64(aIngress, 5U) + aOrbiterA) + RotL64(aOrbiterF, 19U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 35U) + aOrbiterI) + RotL64(aOrbiterA, 21U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 51U) + aOrbiterA) + RotL64(aOrbiterB, 60U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 21U) + aOrbiterE) + RotL64(aOrbiterD, 41U)) + aWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aIngress, 23U) + aOrbiterD) + RotL64(aOrbiterA, 23U)) + RotL64(aCarry, 21U)) + aWandererUpdateSaltE[((aIndex + 26U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterC, 27U)) + aOrbiterK) + aNonceWordE);
            aWandererB = aWandererB + (((RotL64(aCross, 53U) + aOrbiterG) + RotL64(aOrbiterD, 13U)) + aNonceWordD);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 60U) + aOrbiterB) + RotL64(aOrbiterC, 47U));
            aWandererC = aWandererC + ((((RotL64(aCross, 37U) + RotL64(aOrbiterK, 4U)) + aOrbiterJ) + RotL64(aCarry, 5U)) + aNonceWordK);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterI, 57U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererE, 41U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 18U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + RotL64(aWandererA, 35U);
            aCarry = aCarry + RotL64(aIngress, 30U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 10111U)) & S_BLOCK1], 5U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 9289U)) & S_BLOCK1], 24U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 8838U)) & S_BLOCK1], 53U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 8690U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCross, 4U) ^ RotL64(aPrevious, 39U)) + (RotL64(aCarry, 19U) ^ RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterE = (((aWandererH + RotL64(aCross, 60U)) + RotL64(aCarry, 3U)) + 11700815697312060726U) + aNonceWordJ;
            aOrbiterH = (aWandererI + RotL64(aPrevious, 57U)) + 11808423452327465441U;
            aOrbiterG = ((aWandererD + RotL64(aScatter, 41U)) + 8670503858631730886U) + aNonceWordB;
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 27U)) + 2400061067991988544U) + aOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = (aWandererG + RotL64(aCross, 11U)) + 16163118178366229686U;
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 37U)) + RotL64(aCarry, 13U)) + 3280178595904941068U;
            aOrbiterC = ((aWandererC + RotL64(aScatter, 21U)) + RotL64(aCarry, 41U)) + 3298683600817047727U;
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 43U)) + 16321624053445183574U) + aNonceWordL;
            aOrbiterB = (aWandererF + RotL64(aPrevious, 54U)) + 6730229877611375225U;
            aOrbiterK = (aWandererA + RotL64(aScatter, 29U)) + 10162830636713641322U;
            aOrbiterI = ((aWandererK + RotL64(aCross, 35U)) + 15646771327759599256U) + aOrbiterAssignSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 14841751262270544102U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 9545541117228834895U;
            aOrbiterG = RotL64((aOrbiterG * 11529769874752969377U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 14676615635857599982U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 1231768638470558855U;
            aOrbiterA = RotL64((aOrbiterA * 2716808508509014677U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 1945905595345404833U) + aNonceWordO;
            aOrbiterE = (((aOrbiterE ^ aOrbiterD) ^ 1406171421638586846U) ^ aOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterE = RotL64((aOrbiterE * 4577864352425476233U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 1970292335806697198U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 12309719390375013297U;
            aOrbiterB = RotL64((aOrbiterB * 16540660957923687327U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 5352135521358954576U) + aNonceWordI;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 15465675376193501658U;
            aOrbiterK = RotL64((aOrbiterK * 16385761112921041387U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 2842123638916600369U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 3544764287036748668U;
            aOrbiterH = RotL64((aOrbiterH * 3360772950777850115U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 6038297172906492282U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 10249342332287140970U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16701083081566042277U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 1662076777040529446U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 1949705569959740274U;
            aOrbiterF = RotL64((aOrbiterF * 11340691546658994529U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 13934194245417822360U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 5720408806425535958U;
            aOrbiterD = RotL64((aOrbiterD * 15237561081637415383U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 2209251362417210658U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 4917447930929521699U;
            aOrbiterJ = RotL64((aOrbiterJ * 17489570156694692569U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 14817115766683623486U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterA) ^ 11700815697312060726U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterI = RotL64((aOrbiterI * 16982411053956669181U), 11U);
            //
            aIngress = RotL64(aOrbiterH, 46U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 41U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 39U));
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterJ, 27U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterB, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aPrevious, 30U) + aOrbiterC) + RotL64(aOrbiterJ, 57U)) + aNonceWordF);
            aWandererH = aWandererH ^ (((RotL64(aCross, 39U) + aOrbiterG) + RotL64(aOrbiterJ, 51U)) + aNonceWordE);
            aWandererI = aWandererI + ((RotL64(aScatter, 3U) + aOrbiterC) + RotL64(aOrbiterF, 37U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterA, 3U)) + aOrbiterH) + aWandererUpdateSaltB[((aIndex + 10U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 41U) + aOrbiterB) + RotL64(aOrbiterK, 14U)) + aNonceWordC);
            aWandererB = aWandererB ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterC, 35U)) + aOrbiterH);
            aWandererK = aWandererK + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterA, 5U)) + aOrbiterD) + aNonceWordK);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 50U) + aOrbiterE) + RotL64(aOrbiterC, 53U));
            aWandererF = aWandererF + (((RotL64(aCross, 47U) + RotL64(aOrbiterD, 23U)) + aOrbiterI) + RotL64(aCarry, 39U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterF, 43U)) + aOrbiterE) + aWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 35U) + aOrbiterF) + RotL64(aOrbiterK, 26U)) + RotL64(aCarry, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 58U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 21U));
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 60U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererE, 13U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 15329U)) & S_BLOCK1], 5U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 11472U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 14970U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13991U)) & S_BLOCK1], 24U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aPrevious, 29U) + RotL64(aCross, 13U)) + (RotL64(aIngress, 47U) ^ RotL64(aCarry, 60U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterA = ((aWandererB + RotL64(aScatter, 51U)) + 3199575576585871314U) + aNonceWordI;
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 37U)) + RotL64(aCarry, 5U)) + 2533378188975571824U;
            aOrbiterB = ((aWandererJ + RotL64(aIngress, 43U)) + RotL64(aCarry, 11U)) + 6819782112558312658U;
            aOrbiterJ = (aWandererH + RotL64(aCross, 26U)) + 12690060987724798497U;
            aOrbiterE = (((aWandererC + RotL64(aPrevious, 3U)) + 7088375139715629606U) + aOrbiterAssignSaltC[((aIndex + 8U)) & S_SALT1]) + aNonceWordK;
            aOrbiterH = (aWandererI + RotL64(aIngress, 19U)) + 17785618677423695666U;
            aOrbiterF = ((aWandererK + RotL64(aCross, 57U)) + 1714999280296491277U) + aOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = (aWandererD + RotL64(aScatter, 13U)) + 17611338506932491624U;
            aOrbiterD = ((aWandererG + RotL64(aIngress, 11U)) + 6475727359297421201U) + aNonceWordA;
            aOrbiterC = ((aWandererF + RotL64(aScatter, 47U)) + RotL64(aCarry, 57U)) + 2347744591204119530U;
            aOrbiterG = (aWandererA + RotL64(aCross, 22U)) + 2739317903351401068U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 8663535261373274338U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 8205245127823536479U;
            aOrbiterB = RotL64((aOrbiterB * 13857005110466856439U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 8916510616749754516U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 3944805940148512932U;
            aOrbiterE = RotL64((aOrbiterE * 18082271583211389701U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 14094751253118853302U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 14094299829196076311U;
            aOrbiterI = RotL64((aOrbiterI * 6370012560657108493U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 3940673811518673802U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 3015106523254484839U;
            aOrbiterJ = RotL64((aOrbiterJ * 9655401190755573379U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 15404103131982599922U) + aNonceWordE;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 1828655763233900875U;
            aOrbiterA = RotL64((aOrbiterA * 13024358077740310049U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 1236981890899916502U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 18208975564570342697U) ^ aOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4577109989465876801U), 43U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterG) + 17882273895471449661U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordD;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 16196010765612713713U;
            aOrbiterK = RotL64((aOrbiterK * 15624856645134182005U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 14639250100311162559U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 9139027997336903273U;
            aOrbiterH = RotL64((aOrbiterH * 1853126389565574293U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 16848571995585465845U) + aNonceWordP;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 15901000078517800358U;
            aOrbiterG = RotL64((aOrbiterG * 11617866400577762383U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 9405166641274108606U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 6776079798531281127U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6914644957401512339U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 15056085197286596847U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 3199575576585871314U) ^ aNonceWordM;
            aOrbiterD = RotL64((aOrbiterD * 15940936753708416817U), 35U);
            //
            aIngress = RotL64(aOrbiterB, 19U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterA, 24U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterE, 5U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterG, 41U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterC, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 4U) + aOrbiterB) + RotL64(aOrbiterG, 6U));
            aWandererI = aWandererI + (((((RotL64(aScatter, 39U) + aOrbiterK) + RotL64(aOrbiterI, 29U)) + RotL64(aCarry, 5U)) + aNonceWordJ) + aWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 43U) + aOrbiterE) + RotL64(aOrbiterC, 39U)) + aNonceWordF);
            aWandererE = aWandererE + ((RotL64(aPrevious, 53U) + aOrbiterB) + RotL64(aOrbiterA, 53U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 50U) + RotL64(aOrbiterD, 41U)) + aOrbiterF);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 35U) + aOrbiterI) + RotL64(aOrbiterD, 35U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterF, 47U)) + aOrbiterK) + aWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 27U) + aOrbiterJ) + RotL64(aOrbiterC, 11U)) + RotL64(aCarry, 41U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterI, 27U)) + aOrbiterH) + aNonceWordG);
            aWandererC = aWandererC + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterD, 21U)) + aOrbiterA);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 37U) + aOrbiterE) + RotL64(aOrbiterA, 24U)) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 21U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 26U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererJ, 11U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 21214U)) & S_BLOCK1], 40U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18869U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 17037U)) & S_BLOCK1], 23U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 18719U)) & S_BLOCK1], 58U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 19998U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 47U) ^ RotL64(aPrevious, 22U)) ^ (RotL64(aIngress, 5U) + RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterC = ((aWandererA + RotL64(aScatter, 27U)) + 5573188770530340913U) + aNonceWordN;
            aOrbiterF = (aWandererH + RotL64(aCross, 51U)) + 1431772230889897111U;
            aOrbiterI = (aWandererD + RotL64(aPrevious, 53U)) + 4809192776429682319U;
            aOrbiterB = (((aWandererG + RotL64(aIngress, 11U)) + RotL64(aCarry, 37U)) + 5576603692574369341U) + aOrbiterAssignSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterA = (aWandererB + RotL64(aPrevious, 43U)) + 2720143226007220386U;
            aOrbiterH = ((aWandererI + RotL64(aScatter, 39U)) + RotL64(aCarry, 53U)) + 17220328778565331629U;
            aOrbiterD = (aWandererK + RotL64(aIngress, 48U)) + 9629485808442089423U;
            aOrbiterE = ((aWandererJ + RotL64(aCross, 13U)) + RotL64(aCarry, 27U)) + 1136998437010390983U;
            aOrbiterK = (aWandererC + RotL64(aPrevious, 21U)) + 11893390497814523841U;
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 23U)) + 1764986431917532370U) + aOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = ((aWandererE + RotL64(aScatter, 36U)) + 1741014798007010376U) + aNonceWordH;
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 12221368453236547044U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 7694538641172350430U;
            aOrbiterI = RotL64((aOrbiterI * 8439120733670016501U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 17472344518811560603U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 3308740700728172984U;
            aOrbiterH = RotL64((aOrbiterH * 15290400462887712083U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 9535358833412446771U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 11192312491731312451U;
            aOrbiterC = RotL64((aOrbiterC * 17405609148475445743U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 14850451970047190039U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 11932493299452443256U;
            aOrbiterA = RotL64((aOrbiterA * 7964808728820467795U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 5972619895614731870U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 17174497535809891690U;
            aOrbiterF = RotL64((aOrbiterF * 15471084511364572533U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 17412894714378898351U) + aOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 14675615208706549810U;
            aOrbiterB = RotL64((aOrbiterB * 7864845089606499769U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 16116792108013658523U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 9702262005960966336U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 970452849653781703U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 17337264966818542841U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterH) ^ 7004462033775827275U) ^ aOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterJ = RotL64((aOrbiterJ * 11943575980344402681U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 17499850384482055438U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 1839357713256560566U;
            aOrbiterD = RotL64((aOrbiterD * 12943750650487416281U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 8144238113917577524U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 888195876227325908U;
            aOrbiterE = RotL64((aOrbiterE * 7941506708630993709U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 5081763359501717653U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 5573188770530340913U) ^ aNonceWordI;
            aOrbiterG = RotL64((aOrbiterG * 9699901099898698965U), 35U);
            //
            aIngress = RotL64(aOrbiterJ, 46U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 53U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 39U));
            aIngress = aIngress + (RotL64(aOrbiterD, 13U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterK, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aIngress, 11U) + RotL64(aOrbiterI, 3U)) + aOrbiterC) + RotL64(aCarry, 37U)) + aWandererUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 29U) + aOrbiterK) + RotL64(aOrbiterD, 43U));
            aWandererG = aWandererG + (((RotL64(aCross, 19U) + aOrbiterA) + RotL64(aOrbiterC, 51U)) + aNonceWordC);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 21U) + aOrbiterK) + RotL64(aOrbiterE, 37U)) + aNonceWordA);
            aWandererK = aWandererK + ((RotL64(aPrevious, 34U) + RotL64(aOrbiterJ, 46U)) + aOrbiterE);
            aWandererB = aWandererB ^ ((((RotL64(aIngress, 47U) + aOrbiterE) + RotL64(aOrbiterG, 11U)) + aNonceWordM) + aWandererUpdateSaltA[((aIndex + 11U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 3U) + RotL64(aOrbiterK, 27U)) + aOrbiterH) + RotL64(aCarry, 11U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 27U) + aOrbiterF) + RotL64(aOrbiterB, 21U)) + aNonceWordD);
            aWandererI = aWandererI + ((RotL64(aScatter, 51U) + aOrbiterC) + RotL64(aOrbiterG, 13U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 6U) + RotL64(aOrbiterJ, 18U)) + aOrbiterG);
            aWandererA = aWandererA + ((RotL64(aIngress, 43U) + RotL64(aOrbiterA, 41U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererG, 41U) ^ aWandererH);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + (RotL64(aWandererF, 14U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererB, 29U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 24825U)) & S_BLOCK1], 6U) ^ RotL64(mSource[((aIndex + 26982U)) & S_BLOCK1], 21U));
            aIngress ^= (RotL64(pSnow[((aIndex + 25910U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((aIndex + 27083U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 24479U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneB[((aIndex + 24395U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 54U)) ^ (RotL64(aCross, 29U) + RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterH = (aWandererK + RotL64(aIngress, 19U)) + 11410829607777684449U;
            aOrbiterD = (((aWandererF + RotL64(aScatter, 42U)) + RotL64(aCarry, 47U)) + 7502698839700975347U) + aNonceWordL;
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 57U)) + RotL64(aCarry, 39U)) + 13267685058252106173U;
            aOrbiterA = (aWandererI + RotL64(aCross, 3U)) + 238242706996630625U;
            aOrbiterB = (aWandererA + RotL64(aPrevious, 5U)) + 8184695499511454281U;
            aOrbiterI = (((aWandererG + RotL64(aScatter, 37U)) + 12767823220461985403U) + aOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1]) + aNonceWordO;
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 39U)) + 12293198423143850330U) + aNonceWordJ;
            aOrbiterC = ((aWandererC + RotL64(aCross, 51U)) + RotL64(aCarry, 53U)) + 11149495229952495939U;
            aOrbiterE = (aWandererJ + RotL64(aScatter, 23U)) + 7556992689338382800U;
            aOrbiterK = ((aWandererE + RotL64(aIngress, 28U)) + 3431338808774134649U) + aOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = (aWandererH + RotL64(aPrevious, 21U)) + 16863099140844995099U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 17872458049880677604U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 16760153457252546974U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11225037229069712805U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 3115544493537438408U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 4359882942759752958U) ^ aNonceWordN;
            aOrbiterB = RotL64((aOrbiterB * 561477566995575801U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 13387113067202396536U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterI) ^ 12955690074544490161U) ^ aOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterC = RotL64((aOrbiterC * 12449941770827974511U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 15614054443728226807U) + aNonceWordE;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 1939441328066616114U;
            aOrbiterE = RotL64((aOrbiterE * 4484917074808974359U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 4599016263007782537U) + aOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 9962305629016158048U;
            aOrbiterH = RotL64((aOrbiterH * 1496184427500037279U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 8428467674122750557U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 3938884087806393439U) ^ aNonceWordP;
            aOrbiterI = RotL64((aOrbiterI * 12810531094050481761U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 6018636830758044658U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 1510372000641305416U;
            aOrbiterG = RotL64((aOrbiterG * 9002834928626918247U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 17592782466215337843U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 8119921507606870360U;
            aOrbiterA = RotL64((aOrbiterA * 1299795061644535485U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 8753237702359236964U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 12389957327067768090U;
            aOrbiterD = RotL64((aOrbiterD * 4586786761936601607U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 17791633199762408683U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 11606494383812053915U;
            aOrbiterJ = RotL64((aOrbiterJ * 13041480602055778521U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 4418614662439151979U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 11410829607777684449U;
            aOrbiterK = RotL64((aOrbiterK * 3342270212301058781U), 23U);
            //
            aIngress = RotL64(aOrbiterH, 53U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 39U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 60U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + RotL64(aOrbiterB, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aScatter, 36U) + aOrbiterH) + RotL64(aOrbiterI, 56U)) + aNonceWordG);
            aWandererJ = aWandererJ + ((RotL64(aCross, 39U) + aOrbiterH) + RotL64(aOrbiterF, 11U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterB, 29U)) + aOrbiterK) + aNonceWordH);
            aWandererH = aWandererH + (((RotL64(aIngress, 13U) + aOrbiterJ) + RotL64(aOrbiterA, 13U)) + aWandererUpdateSaltF[((aIndex + 4U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterD, 23U)) + aOrbiterH) + aNonceWordM);
            aWandererC = aWandererC + (((RotL64(aIngress, 20U) + RotL64(aOrbiterA, 18U)) + aOrbiterF) + RotL64(aCarry, 13U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterE, 27U)) + aOrbiterI);
            aWandererF = aWandererF + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterK, 41U)) + aOrbiterH) + RotL64(aCarry, 57U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 29U) + aOrbiterA) + RotL64(aOrbiterC, 3U)) + aWandererUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aIngress, 53U) + aOrbiterF) + RotL64(aOrbiterI, 37U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 51U) + aOrbiterA) + RotL64(aOrbiterG, 43U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 26U));
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererK);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererJ, 48U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 32053U)) & S_BLOCK1], 28U) ^ RotL64(pSnow[((aIndex + 29567U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 30305U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 30306U)) & S_BLOCK1], 19U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 31891U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 29288U)) & S_BLOCK1], 10U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCross, 36U) ^ RotL64(aPrevious, 23U)) ^ (RotL64(aIngress, 53U) + RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterE = (aWandererJ + RotL64(aIngress, 6U)) + 6342299552323486695U;
            aOrbiterJ = (((aWandererF + RotL64(aPrevious, 11U)) + RotL64(aCarry, 11U)) + 12692748514781367538U) + aOrbiterAssignSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterD = (((aWandererE + RotL64(aCross, 21U)) + RotL64(aCarry, 5U)) + 8202639945493229155U) + aNonceWordG;
            aOrbiterA = ((aWandererB + RotL64(aScatter, 39U)) + 4439975701793231639U) + aOrbiterAssignSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterC = ((aWandererD + RotL64(aIngress, 47U)) + 16774235182859553759U) + aNonceWordD;
            aOrbiterK = (aWandererG + RotL64(aScatter, 37U)) + 8764155413335405667U;
            aOrbiterH = (aWandererA + RotL64(aPrevious, 3U)) + 7167848811974967685U;
            aOrbiterF = (aWandererC + RotL64(aCross, 41U)) + 16768278912125334220U;
            aOrbiterB = ((aWandererH + RotL64(aScatter, 53U)) + RotL64(aCarry, 47U)) + 9090838954826296201U;
            aOrbiterG = (aWandererI + RotL64(aCross, 60U)) + 7644075729758006298U;
            aOrbiterI = (aWandererK + RotL64(aIngress, 43U)) + 17326182797908071215U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 16158809721888137555U) + aOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 8029938783858263694U;
            aOrbiterD = RotL64((aOrbiterD * 12628072435324195483U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 8716553521415553404U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 7012599977009208840U;
            aOrbiterK = RotL64((aOrbiterK * 8775355876188948851U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 13250558696578541499U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 13705957059101025396U;
            aOrbiterF = RotL64((aOrbiterF * 16889495686487056367U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 2796775206291902461U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 13741676263512390669U;
            aOrbiterG = RotL64((aOrbiterG * 10455782033465595947U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 1691908360612389252U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 4114939415206031540U;
            aOrbiterI = RotL64((aOrbiterI * 2797401802892718297U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 2374911514440738727U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 12377616933668803091U;
            aOrbiterC = RotL64((aOrbiterC * 2505164835116651215U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 681094033415259645U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 13841322124900463362U) ^ aNonceWordO;
            aOrbiterA = RotL64((aOrbiterA * 4210414203856902329U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 18082983557580381338U) + aOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 15731122225678626778U;
            aOrbiterB = RotL64((aOrbiterB * 7785999919955613789U), 39U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterB) + 2084336993254383330U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordH;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 3600882019682875370U;
            aOrbiterJ = RotL64((aOrbiterJ * 2977569829649654329U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 11436602278656592334U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 5775886971784627864U;
            aOrbiterE = RotL64((aOrbiterE * 6765942246225582787U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 17120308925134658794U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 6342299552323486695U;
            aOrbiterH = RotL64((aOrbiterH * 5788669985396507227U), 27U);
            //
            aIngress = RotL64(aOrbiterI, 41U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 43U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 24U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterD, 27U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterE, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aScatter, 53U) + RotL64(aOrbiterB, 53U)) + aOrbiterG) + RotL64(aCarry, 53U)) + aNonceWordL);
            aWandererG = aWandererG ^ ((((RotL64(aPrevious, 14U) + aOrbiterG) + RotL64(aOrbiterI, 19U)) + aNonceWordI) + aWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aCross, 37U) + RotL64(aOrbiterE, 11U)) + aOrbiterF);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterG, 29U)) + aOrbiterK) + aWandererUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aCross, 19U) + aOrbiterC) + RotL64(aOrbiterH, 57U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 47U) + aOrbiterB) + RotL64(aOrbiterC, 14U));
            aWandererI = aWandererI + (((RotL64(aIngress, 35U) + aOrbiterB) + RotL64(aOrbiterD, 41U)) + RotL64(aCarry, 29U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 60U) + RotL64(aOrbiterE, 39U)) + aOrbiterC);
            aWandererC = aWandererC + ((RotL64(aIngress, 41U) + RotL64(aOrbiterF, 27U)) + aOrbiterJ);
            aWandererA = aWandererA ^ ((RotL64(aCross, 43U) + aOrbiterA) + RotL64(aOrbiterJ, 5U));
            aWandererK = aWandererK + ((RotL64(aScatter, 29U) + RotL64(aOrbiterC, 46U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererF, 41U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 48U));
            aCarry = aCarry + (RotL64(aWandererD, 51U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererH, 21U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererI, 54U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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

void TwistExpander_BasketBall_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xC1DF65EE8A419281ULL + 0xB75F947493C9608AULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xA20224717E4042B9ULL + 0x812B6AADB1A2B85CULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xE5DF1360FE07A00FULL + 0x83F7BA6BD932DD27ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xA7BFE1ED1BD5EB25ULL + 0x9F1FC2FD0A350DA2ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xD097D29CF2F30BEDULL + 0xCCBF9C7A5CAAE5C0ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xA4D83D4BDAB5A9BDULL + 0xFD386012B90B1A8FULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xC75225A31C1A8D7FULL + 0xF242F53F4E5297AEULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xCAE1FF432DE79BD9ULL + 0xCA16EBE0126FD965ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xCACFFEBF049C9E73ULL + 0xB6826A0F3807FEB3ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xED055A54FF1CF2EDULL + 0xB0C73BE41B5BFD20ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xA0F43D098C988731ULL + 0x9AB72BE900FBE9F0ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x8039ECE1B6CDEEABULL + 0xEB7F64D98CDCB6B5ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x876E74B28850F827ULL + 0xDAD4A142EC42E30FULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xDB4136043DCA35FFULL + 0xE4BC57F29C3F77A7ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xC6EF9D3786F1CC27ULL + 0x836482CAA84DBD7EULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xB3A557AAEF4AF0A3ULL + 0x837AD9188495B8E6ULL);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 8064U)) & S_BLOCK1], 34U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 4214U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 991U)) & S_BLOCK1], 44U) ^ RotL64(aFireLaneD[((aIndex + 3029U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 28U) ^ RotL64(aCross, 41U)) ^ (RotL64(aPrevious, 13U) + RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterI = (aWandererG + RotL64(aScatter, 23U)) + 15045917390223766480U;
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 14U)) + 10763054007033668758U) + aOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = (aWandererI + RotL64(aIngress, 41U)) + 13190170142593666607U;
            aOrbiterD = (aWandererB + RotL64(aCross, 37U)) + 9657025731441167065U;
            aOrbiterB = (((aWandererK + RotL64(aScatter, 47U)) + RotL64(aCarry, 57U)) + 11433367178975954211U) + aNonceWordJ;
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 57U)) + 17904920143996810366U) + aNonceWordP;
            aOrbiterK = (((aWandererE + RotL64(aCross, 4U)) + RotL64(aCarry, 27U)) + 3244383020512113283U) + aNonceWordO;
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 27U)) + RotL64(aCarry, 5U)) + 6538815775171139091U;
            aOrbiterF = (((aWandererA + RotL64(aIngress, 51U)) + 7195368312757976343U) + aOrbiterAssignSaltC[((aIndex + 14U)) & S_SALT1]) + aNonceWordK;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 18134430713910279374U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 6571776588427107976U;
            aOrbiterC = RotL64((aOrbiterC * 11916502085252589161U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 11830778129647517758U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 9793702760907767365U) ^ aNonceWordG;
            aOrbiterA = RotL64((aOrbiterA * 4096246227968677179U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 2287235876793192036U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 8951959188326141794U;
            aOrbiterK = RotL64((aOrbiterK * 9968356718110753845U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 7583061790273240157U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 3571364625022806085U) ^ aOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6238360922735480669U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 13869345563551689212U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 277480328952975002U;
            aOrbiterD = RotL64((aOrbiterD * 1057564597096163085U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 4983735092494677578U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 9490022869381030928U;
            aOrbiterF = RotL64((aOrbiterF * 12926352917961703123U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 7928039573014765566U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 6504190875809407084U;
            aOrbiterB = RotL64((aOrbiterB * 14648214826494826711U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 2787985600176307413U) + aNonceWordB;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 16308785053443116826U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17867565986311256691U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 12788128335006767824U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 1187040019537798339U) ^ aOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10834905007658184183U), 41U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterK, 19U);
            aIngress = aIngress + (RotL64(aOrbiterC, 11U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterF, 4U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterD, 51U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterJ, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aIngress, 58U) + aOrbiterK) + RotL64(aOrbiterA, 39U)) + aWandererUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 23U) + aOrbiterK) + RotL64(aOrbiterD, 47U)) + aNonceWordN);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterF, 23U)) + aOrbiterB);
            aWandererF = aWandererF + ((RotL64(aScatter, 43U) + aOrbiterC) + RotL64(aOrbiterJ, 34U));
            aWandererK = aWandererK ^ ((((RotL64(aCross, 27U) + RotL64(aOrbiterF, 5U)) + aOrbiterK) + aNonceWordF) + aWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 34U) + RotL64(aOrbiterG, 19U)) + aOrbiterI) + RotL64(aCarry, 13U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterA, 11U)) + aOrbiterD);
            aWandererE = aWandererE + (((RotL64(aScatter, 19U) + RotL64(aOrbiterI, 29U)) + aOrbiterC) + RotL64(aCarry, 51U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterB, 56U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 34U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 41U));
            aCarry = aCarry + RotL64(aWandererA, 47U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 15272U)) & S_BLOCK1], 47U) ^ RotL64(aFireLaneB[((aIndex + 8834U)) & S_BLOCK1], 56U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 8856U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 9421U)) & S_BLOCK1], 50U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 8407U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCross, 11U) ^ RotL64(aIngress, 56U)) ^ (RotL64(aPrevious, 29U) + RotL64(aCarry, 43U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterB = ((aWandererC + RotL64(aIngress, 35U)) + RotL64(aCarry, 29U)) + 7790166497945719700U;
            aOrbiterH = (aWandererG + RotL64(aPrevious, 50U)) + 7136208896846119188U;
            aOrbiterG = (((aWandererD + RotL64(aScatter, 3U)) + 12123156943355100886U) + aOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterA = (aWandererJ + RotL64(aCross, 57U)) + 5095546037880875199U;
            aOrbiterD = (((aWandererH + RotL64(aScatter, 19U)) + RotL64(aCarry, 13U)) + 17642705393916765992U) + aNonceWordF;
            aOrbiterJ = (((aWandererK + RotL64(aCross, 23U)) + RotL64(aCarry, 5U)) + 9918479837334416990U) + aNonceWordG;
            aOrbiterF = ((aWandererF + RotL64(aIngress, 39U)) + 4890009823843176466U) + aNonceWordC;
            aOrbiterC = (aWandererA + RotL64(aPrevious, 43U)) + 17652590786213674124U;
            aOrbiterK = ((aWandererB + RotL64(aCross, 30U)) + 870002527644696135U) + aOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 12545429703552643682U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 5310272867406182581U) ^ aOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10420003334833925011U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 3264719049050179440U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 1967241238180278937U;
            aOrbiterD = RotL64((aOrbiterD * 13004319774269457957U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 773883832927040736U) + aNonceWordD;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 12766817190261232485U;
            aOrbiterH = RotL64((aOrbiterH * 7448864556802318431U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 260069382395598265U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterH) ^ 15462103891287350123U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterC = RotL64((aOrbiterC * 5029268763635635753U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 4072032867513289827U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 17153061419083897076U;
            aOrbiterB = RotL64((aOrbiterB * 11934532169271718913U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 6207264270332656966U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 18048064697837314947U;
            aOrbiterF = RotL64((aOrbiterF * 13632594619404208489U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 14484617445340272026U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 16160443600497652026U;
            aOrbiterJ = RotL64((aOrbiterJ * 1988599349457831597U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 5873314228291583482U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 16418290052752166515U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 18270363452003213317U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 9158414409987627714U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 8205937960146492168U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14008398661393344261U), 19U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterB, 3U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 23U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 19U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 60U));
            aIngress = aIngress + RotL64(aOrbiterK, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aPrevious, 47U) + aOrbiterJ) + RotL64(aOrbiterF, 41U)) + RotL64(aCarry, 13U));
            aWandererF = aWandererF ^ ((((RotL64(aScatter, 29U) + aOrbiterA) + RotL64(aOrbiterF, 21U)) + aNonceWordI) + aWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 41U) + aOrbiterD) + RotL64(aOrbiterK, 30U)) + RotL64(aCarry, 5U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 60U) + aOrbiterD) + RotL64(aOrbiterG, 47U)) + aWandererUpdateSaltA[((aIndex + 11U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterH, 57U)) + aOrbiterB);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 11U) + aOrbiterH) + RotL64(aOrbiterG, 11U));
            aWandererC = aWandererC + ((RotL64(aIngress, 37U) + RotL64(aOrbiterK, 26U)) + aOrbiterF);
            aWandererB = aWandererB ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterK, 5U)) + aOrbiterC) + aNonceWordB);
            aWandererH = aWandererH + ((RotL64(aScatter, 56U) + aOrbiterD) + RotL64(aOrbiterJ, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 53U) ^ aWandererD);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 24U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + RotL64(aWandererF, 35U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 16530U)) & S_BLOCK1], 12U) ^ RotL64(aFireLaneD[((aIndex + 23413U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 20349U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 22965U)) & S_BLOCK1], 53U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 18931U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 22387U)) & S_BLOCK1], 24U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCross, 19U) + RotL64(aPrevious, 37U)) ^ (RotL64(aCarry, 52U) + RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterG = (aWandererF + RotL64(aScatter, 44U)) + 4752759164691497960U;
            aOrbiterI = ((aWandererJ + RotL64(aCross, 19U)) + RotL64(aCarry, 11U)) + 12088872623537639782U;
            aOrbiterH = (aWandererG + RotL64(aPrevious, 23U)) + 3734943577379734227U;
            aOrbiterK = (((aWandererE + RotL64(aIngress, 3U)) + RotL64(aCarry, 51U)) + 8854778183012444234U) + aNonceWordD;
            aOrbiterC = ((aWandererI + RotL64(aScatter, 39U)) + RotL64(aCarry, 21U)) + 16948373492893967275U;
            aOrbiterE = (aWandererB + RotL64(aCross, 50U)) + 7962415690046184385U;
            aOrbiterD = (((aWandererH + RotL64(aIngress, 57U)) + 1872682375669714454U) + aOrbiterAssignSaltB[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordK;
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 11U)) + 7776801806943853566U) + aOrbiterAssignSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterF = ((aWandererA + RotL64(aIngress, 27U)) + 16665439117257230732U) + aNonceWordG;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 11088186766134265676U) + aNonceWordB;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 10850237991780969350U;
            aOrbiterH = RotL64((aOrbiterH * 7547414856143095121U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 6464817712131305812U) + aNonceWordP;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 244557182884209844U;
            aOrbiterC = RotL64((aOrbiterC * 2394270354887582889U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 13261563971157415841U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 2323811103717827362U;
            aOrbiterK = RotL64((aOrbiterK * 11483723582415081925U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 12338803568475493422U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 2811342930111104982U;
            aOrbiterE = RotL64((aOrbiterE * 5020981755203607757U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 5554497011738996057U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 12712169745460598698U;
            aOrbiterI = RotL64((aOrbiterI * 1985586486150377769U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 17415058661427002973U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 9430421222715343818U;
            aOrbiterG = RotL64((aOrbiterG * 10321140659099470811U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 3926618548181233180U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 6172453297026957838U) ^ aOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1161551082037835233U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 8633288765997226004U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 17270881130844274342U) ^ aOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8888559940161770791U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 12232950994807835262U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 15352600312956742750U) ^ aOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6140396356904933003U), 5U);
            //
            aIngress = RotL64(aOrbiterK, 5U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterB, 19U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 38U));
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterE, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aIngress, 19U) + RotL64(aOrbiterG, 52U)) + aOrbiterF) + aWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 54U) + RotL64(aOrbiterG, 11U)) + aOrbiterI);
            aWandererD = aWandererD + (((RotL64(aScatter, 29U) + RotL64(aOrbiterH, 57U)) + aOrbiterI) + RotL64(aCarry, 3U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterK, 23U)) + aOrbiterB);
            aWandererI = aWandererI + (((RotL64(aScatter, 39U) + aOrbiterB) + RotL64(aOrbiterE, 47U)) + aNonceWordI);
            aWandererE = aWandererE ^ (((RotL64(aCross, 5U) + aOrbiterG) + RotL64(aOrbiterH, 5U)) + aNonceWordF);
            aWandererH = aWandererH + (((RotL64(aIngress, 50U) + RotL64(aOrbiterF, 36U)) + aOrbiterC) + RotL64(aCarry, 43U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 23U) + aOrbiterI) + RotL64(aOrbiterD, 43U)) + aWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 13U) + aOrbiterF) + RotL64(aOrbiterE, 27U)) + aNonceWordN);
            //
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererA);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + RotL64(aWandererF, 12U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 25840U)) & S_BLOCK1], 53U) ^ RotL64(aFireLaneC[((aIndex + 30248U)) & S_BLOCK1], 12U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 30066U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 25270U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 25996U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 27010U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aPrevious, 10U)) ^ (RotL64(aCarry, 41U) ^ RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterK = (((aWandererF + RotL64(aPrevious, 41U)) + RotL64(aCarry, 13U)) + 1866656689936219099U) + aOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = ((aWandererI + RotL64(aScatter, 35U)) + 2312314528139448289U) + aNonceWordO;
            aOrbiterG = ((aWandererA + RotL64(aIngress, 51U)) + 3554037526469185237U) + aNonceWordG;
            aOrbiterJ = (aWandererJ + RotL64(aCross, 3U)) + 405707755060974111U;
            aOrbiterI = (aWandererC + RotL64(aPrevious, 46U)) + 1862976326004007697U;
            aOrbiterE = (aWandererD + RotL64(aScatter, 27U)) + 12992483065443288263U;
            aOrbiterD = ((aWandererK + RotL64(aIngress, 21U)) + RotL64(aCarry, 21U)) + 3793854946371595197U;
            aOrbiterH = (((aWandererG + RotL64(aCross, 11U)) + RotL64(aCarry, 29U)) + 4244007978867369382U) + aOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = (aWandererH + RotL64(aPrevious, 58U)) + 10280867500312580308U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 472563452959164242U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 12041770406895816553U;
            aOrbiterG = RotL64((aOrbiterG * 17811798500132002631U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 6118634015704900486U) + aOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 13637107920449233307U) ^ aNonceWordM;
            aOrbiterI = RotL64((aOrbiterI * 17712028184714868053U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 16673735670669318830U) + aOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 8602681273646630496U;
            aOrbiterD = RotL64((aOrbiterD * 6995213887710749241U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 7683264695930369476U) + aOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 9146674871199188218U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7403427067419261981U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 3012935612827493084U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 1259789268731661945U;
            aOrbiterH = RotL64((aOrbiterH * 2372843620327050137U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 5623690455471160780U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 18355567776031865462U) ^ aNonceWordP;
            aOrbiterK = RotL64((aOrbiterK * 9553862670107886679U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 7705134893833304792U) + aNonceWordB;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 4435192506444773834U;
            aOrbiterB = RotL64((aOrbiterB * 5249651218395299501U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 6204683785806409075U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 17886971535016484255U;
            aOrbiterJ = RotL64((aOrbiterJ * 6047216474762933535U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 4430578901091376829U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 607557685798141547U;
            aOrbiterA = RotL64((aOrbiterA * 12342665567201483107U), 27U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterK, 3U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + (RotL64(aOrbiterD, 37U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterB, 30U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterH, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aScatter, 51U) + RotL64(aOrbiterA, 23U)) + aOrbiterJ) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 6U) + aOrbiterH) + RotL64(aOrbiterK, 19U)) + aNonceWordF);
            aWandererA = aWandererA + ((RotL64(aCross, 35U) + aOrbiterB) + RotL64(aOrbiterH, 35U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 43U) + aOrbiterJ) + RotL64(aOrbiterE, 27U));
            aWandererD = aWandererD + ((RotL64(aScatter, 29U) + RotL64(aOrbiterG, 6U)) + aOrbiterK);
            aWandererK = aWandererK ^ ((((RotL64(aCross, 47U) + aOrbiterE) + RotL64(aOrbiterB, 39U)) + aNonceWordH) + aWandererUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 21U) + RotL64(aOrbiterH, 43U)) + aOrbiterJ) + aNonceWordD);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 60U) + aOrbiterI) + RotL64(aOrbiterJ, 13U)) + aWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aIngress, 11U) + RotL64(aOrbiterI, 56U)) + aOrbiterD) + RotL64(aCarry, 51U)) + aNonceWordA);
            //
            aCarry = aCarry + (RotL64(aWandererA, 41U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererK);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 18U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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

void TwistExpander_BasketBall_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xB43050CA5A607BEBULL + 0xE7B2009E0647FA33ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xC01D0F30E82737A9ULL + 0xA609D2C76B80B2E5ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xD4B9AC5C2D35F421ULL + 0xCD5319F5156A3831ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xD9D4CC20321F6981ULL + 0xE6C214A89877C081ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x81CBBF606F725043ULL + 0xD32DD53CEFE65324ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xD1525DA4C69A839DULL + 0xD1853D9B7166CA6EULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x8BFB19004C3DE00FULL + 0x89EB609BC3143EE2ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xE2C6B33544AAED89ULL + 0xD2E24B0BBED54529ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xD260E823989A247FULL + 0xDED38D2711C41A68ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xEA8288C39CD874F1ULL + 0xB1AF6CCB0AD4B3EAULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x847D4B43D3506E69ULL + 0xC1D05BF5D510DFC0ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xEF962FAE842BF047ULL + 0xD2E882FB9EC3C34AULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xDF7A1ED1FF55E339ULL + 0xBC75154554164F39ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x84BAC04B3E5B9CB7ULL + 0xE251B16B13784CA9ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xF1B32802E299B8A3ULL + 0xA1BC981AB5600DA1ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x9C52B959B1D75391ULL + 0xF2B712F81AC89E6AULL);
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
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneC, aOperationLaneC, aOperationLaneD, aWorkLaneA, aFireLaneB, aWorkLaneB, aFireLaneD, aWorkLaneC, aFireLaneA
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 7467U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneB[((aIndex + 1706U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 3798U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 5864U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneD[((aIndex + 538U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aIngress, 52U)) + (RotL64(aPrevious, 5U) + RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterH = ((((aWandererH + RotL64(aScatter, 57U)) + RotL64(aCarry, 37U)) + 16922357079016918108U) + aOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1]) + aNonceWordE;
            aOrbiterK = (aWandererD + RotL64(aIngress, 4U)) + 11771749797137599131U;
            aOrbiterB = ((((aWandererK + RotL64(aPrevious, 19U)) + RotL64(aCarry, 19U)) + 4635668433708036077U) + aOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordD;
            aOrbiterJ = (((aWandererE + RotL64(aCross, 43U)) + RotL64(aCarry, 5U)) + 15827952719230577008U) + aNonceWordB;
            aOrbiterA = (aWandererI + RotL64(aScatter, 35U)) + 1495675306110023086U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 7294835466949728365U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 179122461212041978U) ^ aNonceWordK;
            aOrbiterB = RotL64((aOrbiterB * 14467072888722097971U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 545981421632236251U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 15338259639814630535U) ^ aOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14895421566334357871U), 57U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterH) + 12924313840290895215U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordN;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 17846785921286020610U;
            aOrbiterK = RotL64((aOrbiterK * 18309347016029917133U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 5721472794107057875U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 16359630793856870319U) ^ aOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14186771515526698907U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 10614102110239037308U) + aNonceWordC;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 16421992251278236531U;
            aOrbiterH = RotL64((aOrbiterH * 2561232904676068089U), 3U);
            //
            aIngress = RotL64(aOrbiterH, 39U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + RotL64(aOrbiterJ, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((((RotL64(aIngress, 5U) + aOrbiterH) + RotL64(aOrbiterB, 35U)) + RotL64(aCarry, 29U)) + aNonceWordO) + aWandererUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((((RotL64(aPrevious, 14U) + RotL64(aOrbiterK, 27U)) + aOrbiterJ) + aNonceWordG) + aWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 23U) + RotL64(aOrbiterA, 56U)) + aOrbiterB) + RotL64(aCarry, 51U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterJ, 43U)) + aOrbiterH) + aNonceWordI);
            aWandererE = aWandererE + (((RotL64(aIngress, 57U) + RotL64(aOrbiterA, 13U)) + aOrbiterK) + aNonceWordH);
            //
            aCarry = aCarry + (RotL64(aWandererE, 27U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + RotL64(aWandererH, 19U);
            aCarry = aCarry + RotL64(aIngress, 58U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_c loop 2
        // ingress from: aWorkLaneA, aOperationLaneC, aFireLaneB
        // ingress directions: aWorkLaneA forward forced, aOperationLaneC forward forced, aFireLaneB forward/backward random
        // cross from: aOperationLaneA, aOperationLaneD, aOperationLaneB
        // cross directions: aOperationLaneA backward forced, aOperationLaneD backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 11626U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneC[((aIndex + 11008U)) & S_BLOCK1], 12U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 12022U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 12895U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 14166U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 14848U)) & S_BLOCK1], 22U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 14U) ^ RotL64(aPrevious, 27U)) ^ (RotL64(aCarry, 39U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterE = (((aWandererA + RotL64(aIngress, 13U)) + 1210605127156905516U) + aOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordL;
            aOrbiterC = (((aWandererB + RotL64(aScatter, 35U)) + RotL64(aCarry, 43U)) + 11964595428173569519U) + aOrbiterAssignSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = ((aWandererH + RotL64(aCross, 47U)) + RotL64(aCarry, 21U)) + 16277319029916258482U;
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 57U)) + RotL64(aCarry, 57U)) + 12369497463101824572U;
            aOrbiterG = ((aWandererD + RotL64(aScatter, 24U)) + 6201248574067068202U) + aNonceWordI;
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 1727477025667206661U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 1404510627789806851U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4810039298122529021U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 6948213591282018925U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 6688865181284421478U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12619122841662247279U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 3351130769402360855U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 12681032488906270823U) ^ aOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3680893896579741263U), 3U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterG) + 3591412591193726763U) + aOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1]) + aNonceWordB;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 16153817571210878589U) ^ aNonceWordA;
            aOrbiterC = RotL64((aOrbiterC * 4165137036092246349U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 3808228354421006630U) + aNonceWordK;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 1427373776207504205U;
            aOrbiterK = RotL64((aOrbiterK * 4534374093769595531U), 57U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterC, 26U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 41U));
            aIngress = aIngress + RotL64(aOrbiterH, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aPrevious, 51U) + aOrbiterH) + RotL64(aOrbiterG, 51U)) + RotL64(aCarry, 29U)) + aNonceWordO);
            aWandererH = aWandererH ^ ((((RotL64(aCross, 38U) + aOrbiterC) + RotL64(aOrbiterK, 43U)) + aNonceWordH) + aWandererUpdateSaltE[((aIndex + 4U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aScatter, 11U) + RotL64(aOrbiterK, 26U)) + aOrbiterE) + RotL64(aCarry, 57U)) + aNonceWordC);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 3U) + aOrbiterK) + RotL64(aOrbiterH, 3U)) + aWandererUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 27U) + aOrbiterE) + RotL64(aOrbiterH, 35U)) + aNonceWordM);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 19U));
            aCarry = aCarry + RotL64(aWandererA, 47U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 17897U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneD[((aIndex + 17065U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 23380U)) & S_BLOCK1], 10U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22259U)) & S_BLOCK1], 34U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 22392U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 19280U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCarry, 37U) + RotL64(aPrevious, 3U)) + (RotL64(aIngress, 53U) ^ RotL64(aCross, 20U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterF = (aWandererI + RotL64(aScatter, 3U)) + 7825479804710770560U;
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 27U)) + RotL64(aCarry, 51U)) + 5298124167101358123U;
            aOrbiterJ = (((aWandererK + RotL64(aCross, 57U)) + 17774541024369233726U) + aOrbiterAssignSaltE[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordH;
            aOrbiterI = (((aWandererA + RotL64(aIngress, 14U)) + RotL64(aCarry, 5U)) + 7679371833537454082U) + aNonceWordM;
            aOrbiterK = (((aWandererC + RotL64(aCross, 39U)) + RotL64(aCarry, 37U)) + 5385914900748772224U) + aOrbiterAssignSaltA[((aIndex + 6U)) & S_SALT1];
            //
            aOrbiterF = (((aOrbiterF + aOrbiterD) + 3879781930908486531U) + aOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1]) + aNonceWordN;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 659110346638873236U) ^ aNonceWordO;
            aOrbiterJ = RotL64((aOrbiterJ * 17439162088869824407U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 10749021728538539749U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 3631252455767429457U;
            aOrbiterK = RotL64((aOrbiterK * 8552825360915119613U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 2271978810960685021U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 5963558780692551176U) ^ aNonceWordC;
            aOrbiterD = RotL64((aOrbiterD * 4772055335210781149U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 974909966119198104U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 9296998242911152296U;
            aOrbiterI = RotL64((aOrbiterI * 2613629915877957661U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 2245318466901521959U) + aNonceWordP;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 13391076374843288568U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 18094558036982107419U), 57U);
            //
            aIngress = RotL64(aOrbiterD, 29U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 19U));
            aIngress = aIngress + RotL64(aOrbiterJ, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((((RotL64(aIngress, 29U) + aOrbiterF) + RotL64(aOrbiterK, 19U)) + aNonceWordJ) + aWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aCross, 19U) + RotL64(aOrbiterI, 37U)) + aOrbiterF) + RotL64(aCarry, 39U)) + aNonceWordF);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterK, 5U)) + aOrbiterI) + aNonceWordK);
            aWandererC = aWandererC + (((RotL64(aScatter, 4U) + aOrbiterI) + RotL64(aOrbiterJ, 58U)) + RotL64(aCarry, 27U));
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 51U) + RotL64(aOrbiterF, 47U)) + aOrbiterD) + aNonceWordL) + aWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererI, 27U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_c loop 4
        // ingress from: aWorkLaneC, aWorkLaneA, aFireLaneA
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aFireLaneA forward/backward random
        // cross from: aWorkLaneB, aOperationLaneC, aOperationLaneD, aOperationLaneA
        // cross directions: aWorkLaneB backward forced, aOperationLaneC backward forced, aOperationLaneD backward forced, aOperationLaneA backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 31924U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((aIndex + 28629U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 28710U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32441U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 24879U)) & S_BLOCK1], 13U));
            aCross ^= (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 31980U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((aIndex + 26681U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aPrevious, 35U) + RotL64(aCarry, 53U)) ^ (RotL64(aIngress, 5U) ^ RotL64(aCross, 20U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterG = (aWandererK + RotL64(aCross, 52U)) + 7270044678408187242U;
            aOrbiterK = ((((aWandererH + RotL64(aIngress, 21U)) + RotL64(aCarry, 19U)) + 10192278965379756766U) + aOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1]) + aNonceWordD;
            aOrbiterA = (((aWandererE + RotL64(aScatter, 13U)) + RotL64(aCarry, 3U)) + 17568666746676060748U) + aOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = (((aWandererD + RotL64(aPrevious, 5U)) + RotL64(aCarry, 51U)) + 14312927531124963037U) + aNonceWordO;
            aOrbiterB = (aWandererB + RotL64(aCross, 43U)) + 9825825726152087706U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 9696778570255265896U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 17657841352013417228U;
            aOrbiterA = RotL64((aOrbiterA * 17562220176018833833U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 16207815085909628439U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 1752979206374514227U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14182667540650694199U), 47U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterA) + 10456310689643905854U) + aOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1]) + aNonceWordI;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 16127830548663742550U) ^ aNonceWordG;
            aOrbiterB = RotL64((aOrbiterB * 4355938404839045417U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 2940917376003930842U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 7353596864777649953U) ^ aOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7499468723171042005U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 12725092740446150705U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 5791296650856037010U;
            aOrbiterG = RotL64((aOrbiterG * 760379251950502133U), 23U);
            //
            aIngress = RotL64(aOrbiterB, 19U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 29U));
            aIngress = aIngress + RotL64(aOrbiterG, 56U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterB, 24U)) + aOrbiterA);
            aWandererK = aWandererK + (((((RotL64(aScatter, 56U) + aOrbiterK) + RotL64(aOrbiterA, 39U)) + RotL64(aCarry, 43U)) + aNonceWordK) + aWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 29U) + aOrbiterG) + RotL64(aOrbiterF, 13U)) + aWandererUpdateSaltC[((aIndex + 26U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aCross, 21U) + RotL64(aOrbiterK, 3U)) + aOrbiterG) + RotL64(aCarry, 5U)) + aNonceWordB);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 37U) + aOrbiterA) + RotL64(aOrbiterG, 53U)) + aNonceWordA);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 21U));
            aCarry = aCarry + (RotL64(aWandererD, 51U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererH, 29U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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

void TwistExpander_BasketBall_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xD7CA8A4D0BE9C883ULL + 0xC034CAAFA332FC3DULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xC4A1B7647E0C627BULL + 0xFFEA24A8BD522F44ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xE7672E49D21CB479ULL + 0xDD6439F19268EA44ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xED930BB1D6F9E433ULL + 0x824E4C5C148E8206ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x80B47B970F4F3B2BULL + 0xB9080C5E82D8360AULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xB8BC0ACC20CFFB1DULL + 0xE3D75CD56439731BULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x88C5CFAD0CFAA867ULL + 0xD13B65FAFF62CA37ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x8FE7864439EC1597ULL + 0xA661B8921BA52D4FULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xBFAE7BBF5E169353ULL + 0xC0B95EBAB57DA160ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xF310957FE0E2DA3BULL + 0xC8418F456ADFBF57ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x8C01A86142557FA3ULL + 0xC4A6B12DC167A970ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xB84ABE08BC5ADEADULL + 0xEBE5EAD02A27491AULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xCF52D840885A17F9ULL + 0xD7543DB0EBC2334CULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xB7AA15A9590D16DDULL + 0xEB7998EC095413E1ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x8CF036F67D6C581FULL + 0xF596BE81103208E6ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xE13E3B16D32452D3ULL + 0x9BFFF61AC8127C57ULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aOperationLaneB, aExpandLaneC, aExpandLaneD, aFireLaneB, aWorkLaneA, aFireLaneA, aOperationLaneD, aWorkLaneB, aFireLaneC, aOperationLaneA, aWorkLaneC, aFireLaneD, aOperationLaneC
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // kdf_a_loop_d loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aOperationLaneB
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aOperationLaneB forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aFireLaneB
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aFireLaneB backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 727U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneB[((aIndex + 7099U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aOperationLaneB[((aIndex + 370U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5567U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 6209U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 4923U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCarry, 20U) ^ RotL64(aPrevious, 5U)) + (RotL64(aCross, 57U) ^ RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterK = ((((aWandererI + RotL64(aCross, 60U)) + RotL64(aCarry, 51U)) + 12136097566601676613U) + aOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1]) + aNonceWordM;
            aOrbiterF = ((aWandererF + RotL64(aScatter, 19U)) + 7969431322248040056U) + aNonceWordN;
            aOrbiterC = (aWandererJ + RotL64(aPrevious, 53U)) + 10530676021510553889U;
            aOrbiterG = (((aWandererG + RotL64(aIngress, 47U)) + RotL64(aCarry, 21U)) + 8740777303075445264U) + aOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = ((aWandererC + RotL64(aCross, 29U)) + 13249434169895564739U) + aNonceWordI;
            aOrbiterA = (aWandererD + RotL64(aScatter, 41U)) + 15529577005925628472U;
            aOrbiterJ = ((aWandererH + RotL64(aPrevious, 13U)) + RotL64(aCarry, 3U)) + 344627093687331562U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 8824277416519988893U) + aNonceWordF;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 5636276438449709875U) ^ aNonceWordK;
            aOrbiterC = RotL64((aOrbiterC * 222817930773618893U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 2079413361031851552U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 7807998179168655561U;
            aOrbiterH = RotL64((aOrbiterH * 961456853699784753U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 13589392896232029112U) + aOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 10733011474804473996U) ^ aOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 361749145931578805U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 15934162328347805968U) + aNonceWordD;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 7573511217796245232U;
            aOrbiterJ = RotL64((aOrbiterJ * 10694563909931636155U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 4828475187337891975U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 13284974329890393113U;
            aOrbiterF = RotL64((aOrbiterF * 10831075817642374287U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 13173869918669643112U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 15841507674783398167U) ^ aOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15632933198136963277U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 14168272451055700516U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 11134471485501999898U;
            aOrbiterK = RotL64((aOrbiterK * 8019507184494591705U), 5U);
            //
            aIngress = RotL64(aOrbiterA, 3U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterF, 43U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 12U));
            aIngress = aIngress + RotL64(aOrbiterG, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 41U) + aOrbiterH) + RotL64(aOrbiterA, 47U)) + aNonceWordE);
            aWandererD = aWandererD + ((((RotL64(aCross, 11U) + aOrbiterJ) + RotL64(aOrbiterK, 35U)) + RotL64(aCarry, 19U)) + aNonceWordA);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 30U) + RotL64(aOrbiterF, 28U)) + aOrbiterG) + aWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 47U) + aOrbiterC) + RotL64(aOrbiterH, 5U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterF, 53U)) + aOrbiterH);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterJ, 11U)) + aOrbiterF) + RotL64(aCarry, 5U)) + aNonceWordG);
            aWandererI = aWandererI ^ ((((RotL64(aScatter, 57U) + aOrbiterK) + RotL64(aOrbiterF, 41U)) + aNonceWordJ) + aWandererUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + RotL64(aWandererJ, 14U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 2
        // ingress from: aWorkLaneA, aExpandLaneC, aFireLaneA
        // ingress directions: aWorkLaneA forward forced, aExpandLaneC forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD, aOperationLaneD
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 9307U)) & S_BLOCK1], 36U) ^ RotL64(aExpandLaneC[((aIndex + 14336U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 13214U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 9002U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 13073U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 15524U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 26U) + RotL64(aCross, 41U)) ^ (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 5U)) + 4970414922752555648U) + aNonceWordD;
            aOrbiterK = (aWandererF + RotL64(aPrevious, 13U)) + 9462756592787669327U;
            aOrbiterD = (((aWandererA + RotL64(aScatter, 58U)) + RotL64(aCarry, 53U)) + 3948790686662213095U) + aOrbiterAssignSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = (aWandererJ + RotL64(aCross, 41U)) + 14542857212241578311U;
            aOrbiterH = (((aWandererD + RotL64(aIngress, 23U)) + RotL64(aCarry, 35U)) + 3387479009827029547U) + aOrbiterAssignSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = ((aWandererE + RotL64(aCross, 35U)) + 1411421370057797877U) + aNonceWordO;
            aOrbiterE = (((aWandererG + RotL64(aPrevious, 47U)) + RotL64(aCarry, 11U)) + 16894451466895681236U) + aNonceWordH;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 12727136462290223542U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 4625389198191960525U;
            aOrbiterD = RotL64((aOrbiterD * 5726474430977810191U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 3471881403786164913U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 6433115856048534831U;
            aOrbiterH = RotL64((aOrbiterH * 9363233870194144053U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 9825592965466157982U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 1553125767261293088U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 411535191177308781U), 53U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterE) + 9951616357109647617U) + aOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1]) + aNonceWordB;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 11231080382787286889U;
            aOrbiterJ = RotL64((aOrbiterJ * 14024961994986659187U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 13419663264017317947U) + aOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 4835055642466215566U;
            aOrbiterK = RotL64((aOrbiterK * 17898065852351759171U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 14558747666410946768U) + aNonceWordN;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 13120938960926874504U;
            aOrbiterC = RotL64((aOrbiterC * 5681766019285559739U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 11910501376797343986U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 15074100100781785300U;
            aOrbiterE = RotL64((aOrbiterE * 228976960937473851U), 47U);
            //
            aIngress = RotL64(aOrbiterH, 29U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterK, 43U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 5U));
            aIngress = aIngress + RotL64(aOrbiterJ, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterJ, 28U)) + aOrbiterC) + aWandererUpdateSaltE[((aIndex + 6U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 58U) + aOrbiterK) + RotL64(aOrbiterE, 53U)) + RotL64(aCarry, 35U)) + aNonceWordP);
            aWandererF = aWandererF ^ (((RotL64(aCross, 29U) + aOrbiterH) + RotL64(aOrbiterK, 21U)) + aWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 23U) + aOrbiterC) + RotL64(aOrbiterD, 35U)) + RotL64(aCarry, 53U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 5U) + aOrbiterJ) + RotL64(aOrbiterB, 11U)) + aNonceWordE);
            aWandererE = aWandererE + (((RotL64(aScatter, 41U) + aOrbiterH) + RotL64(aOrbiterC, 3U)) + aNonceWordJ);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterE, 47U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 40U));
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererB, 51U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 3
        // ingress from: aWorkLaneB, aExpandLaneD, aFireLaneC
        // ingress directions: aWorkLaneB forward forced, aExpandLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aWorkLaneA, aExpandLaneB, aOperationLaneA
        // cross directions: aWorkLaneA backward forced, aExpandLaneB backward forced, aOperationLaneA backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 18978U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((aIndex + 19138U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 21090U)) & S_BLOCK1], 42U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17592U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 19114U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aOperationLaneA[((aIndex + 21634U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 54U)) ^ (RotL64(aIngress, 21U) + RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 29U)) + 5697928251815176134U) + aNonceWordE;
            aOrbiterA = ((aWandererB + RotL64(aCross, 37U)) + RotL64(aCarry, 21U)) + 337587740689259575U;
            aOrbiterE = (((aWandererK + RotL64(aIngress, 43U)) + RotL64(aCarry, 39U)) + 4927686903263973950U) + aNonceWordF;
            aOrbiterK = ((aWandererH + RotL64(aScatter, 3U)) + 3742409032569801033U) + aNonceWordC;
            aOrbiterF = (((aWandererJ + RotL64(aIngress, 22U)) + 1608092659172197650U) + aOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1]) + aNonceWordK;
            aOrbiterI = (((aWandererI + RotL64(aScatter, 57U)) + RotL64(aCarry, 3U)) + 15848744267145717509U) + aOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = (aWandererD + RotL64(aCross, 11U)) + 15300174177963339253U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 14162868453323648628U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 12020167069983729869U) ^ aNonceWordI;
            aOrbiterE = RotL64((aOrbiterE * 2071080217680099017U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 16259538291658723956U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterK) ^ 8516686212464112245U) ^ aOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterI = RotL64((aOrbiterI * 4731296903548893627U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 3722184575520553132U) + aNonceWordL;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 5663609293306386784U;
            aOrbiterF = RotL64((aOrbiterF * 14364218128780764749U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 15265344442454471986U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 3050323350098829515U;
            aOrbiterK = RotL64((aOrbiterK * 5890624677162388135U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 1093356813820599238U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 15167726103772238440U;
            aOrbiterD = RotL64((aOrbiterD * 5719466863561311069U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 15170797965325981472U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 17826286701992981628U;
            aOrbiterA = RotL64((aOrbiterA * 11186808881726573677U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 14710892030473425181U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 397194787697553904U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14368930300818752833U), 29U);
            //
            aIngress = RotL64(aOrbiterE, 3U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterD, 60U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterI, 13U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterF, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 57U) + RotL64(aOrbiterD, 11U)) + aOrbiterE) + aWandererUpdateSaltF[((aIndex + 28U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterK, 38U)) + aOrbiterD) + aNonceWordH);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 27U) + aOrbiterC) + RotL64(aOrbiterE, 3U)) + RotL64(aCarry, 51U)) + aNonceWordA);
            aWandererH = aWandererH ^ ((RotL64(aCross, 5U) + aOrbiterA) + RotL64(aOrbiterI, 53U));
            aWandererC = aWandererC + (((RotL64(aScatter, 50U) + RotL64(aOrbiterI, 29U)) + aOrbiterF) + aNonceWordG);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 19U) + aOrbiterF) + RotL64(aOrbiterC, 23U));
            aWandererK = aWandererK + (((((RotL64(aCross, 11U) + aOrbiterK) + RotL64(aOrbiterF, 47U)) + RotL64(aCarry, 35U)) + aNonceWordN) + aWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 6U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + RotL64(aWandererI, 19U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 4
        // ingress from: aWorkLaneC, aWorkLaneA, aFireLaneD
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aFireLaneD forward/backward random
        // cross from: aWorkLaneB, aExpandLaneC, aOperationLaneC
        // cross directions: aWorkLaneB backward forced, aExpandLaneC backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 25474U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((aIndex + 27140U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 27951U)) & S_BLOCK1], 58U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26641U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 29338U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aOperationLaneC[((aIndex + 28079U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCarry, 22U) ^ RotL64(aIngress, 51U)) + (RotL64(aCross, 39U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterE = (((aWandererK + RotL64(aScatter, 50U)) + RotL64(aCarry, 43U)) + 7075016829833562104U) + aOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = (aWandererF + RotL64(aCross, 5U)) + 8783765886115517036U;
            aOrbiterF = ((((aWandererH + RotL64(aIngress, 29U)) + RotL64(aCarry, 57U)) + 2996723892384565829U) + aOrbiterAssignSaltF[((aIndex + 26U)) & S_SALT1]) + aNonceWordL;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 19U)) + RotL64(aCarry, 21U)) + 9494134707342189476U;
            aOrbiterH = ((aWandererD + RotL64(aIngress, 11U)) + 5052642981395679904U) + aNonceWordP;
            aOrbiterC = ((aWandererA + RotL64(aScatter, 41U)) + 8766787055127962238U) + aNonceWordF;
            aOrbiterA = (aWandererB + RotL64(aCross, 57U)) + 4467211954388738079U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 8030255604633658608U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 16962408063455702251U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11171737929747471631U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 3768222186567699076U) + aNonceWordC;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 14930990410207899871U;
            aOrbiterC = RotL64((aOrbiterC * 10930005786146268241U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 14179761938395502502U) + aOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 1879084742719898108U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16783034788172670121U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 5535012408925981515U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 12792553516710295939U;
            aOrbiterH = RotL64((aOrbiterH * 8577530993755159329U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 8979253163346099252U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 5559189896063990740U) ^ aNonceWordD;
            aOrbiterG = RotL64((aOrbiterG * 8832485423727331621U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 13937564337299044079U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 2393376759689394948U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2352815657830413941U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 12647519563697356479U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 10946871249960389549U;
            aOrbiterA = RotL64((aOrbiterA * 6272580371881237173U), 47U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterC, 50U);
            aIngress = aIngress + (RotL64(aOrbiterA, 21U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterK, 43U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterF, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 37U) + aOrbiterE) + RotL64(aOrbiterA, 58U)) + RotL64(aCarry, 21U)) + aWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 44U) + aOrbiterF) + RotL64(aOrbiterE, 21U));
            aWandererB = aWandererB + (((RotL64(aCross, 57U) + RotL64(aOrbiterH, 27U)) + aOrbiterF) + RotL64(aCarry, 51U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 29U) + aOrbiterG) + RotL64(aOrbiterF, 51U));
            aWandererD = aWandererD + ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterA, 11U)) + aOrbiterG) + aNonceWordM) + aWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterC, 3U)) + aOrbiterA) + aNonceWordO);
            aWandererA = aWandererA + (((RotL64(aIngress, 3U) + aOrbiterK) + RotL64(aOrbiterC, 35U)) + aNonceWordE);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 22U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererJ, 37U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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

void TwistExpander_BasketBall_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xFD3E0CB9974C0385ULL + 0xFC0F7523FAFA6F1CULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xD613773C20225FA1ULL + 0xA13B8F15392F34A3ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xA9D7D2D5F21D4761ULL + 0xA08B21FDC078ADF8ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xE541D39F4F6D59E9ULL + 0xAA2E1F5C220D1CB0ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xA4E71F6DE95E264FULL + 0xF669CF9331CD4744ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xDB6ABCA1C3FE76C7ULL + 0xD0DD828157249DF8ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xC0BDF29DC78D8F03ULL + 0xEB4617226A6FE3B4ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xBBC8D4A8F1527643ULL + 0x9E062CEE499FBF7FULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xBCFBF5E680F9271FULL + 0xC57D8C62A0B0E119ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xF193A93B2BF574E5ULL + 0xEF87E3F0AE1CE915ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xAC175961B0A0ED93ULL + 0x81558175AEEA2E61ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xFEE3D77F83157987ULL + 0xF6EA549589DDB868ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x8826978B3945E80DULL + 0xF2CEDACBE2127D14ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xF14081260BA93781ULL + 0xA3590EC086D4F3BFULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x9223E3C631A1B98DULL + 0xE5FC0BF70BD98983ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x8C67E01DE9769777ULL + 0xD5A5DF7DCCE6F355ULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aFireLaneC, aWorkLaneC, aWorkLaneD, aFireLaneB, aExpandLaneA, aFireLaneA, aFireLaneD, aExpandLaneB, aOperationLaneD, aOperationLaneA, aExpandLaneC, aOperationLaneB, aOperationLaneC
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_a loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aFireLaneC
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aFireLaneC forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aFireLaneB
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aFireLaneB backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 2823U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((aIndex + 381U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 2092U)) & S_BLOCK1], 28U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 5728U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 1013U)) & S_BLOCK1], 56U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 3378U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aIngress, 11U)) + (RotL64(aCarry, 43U) + RotL64(aPrevious, 28U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterD = ((aWandererB + RotL64(aCross, 5U)) + RotL64(aCarry, 43U)) + 9133751643283278896U;
            aOrbiterB = ((((aWandererA + RotL64(aScatter, 58U)) + RotL64(aCarry, 11U)) + 8971581804375380408U) + aOrbiterAssignSaltA[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordN;
            aOrbiterJ = (aWandererD + RotL64(aPrevious, 43U)) + 12559650383714566592U;
            aOrbiterI = ((aWandererG + RotL64(aIngress, 19U)) + 15753206088872859163U) + aOrbiterAssignSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 37U)) + 7640756270450762350U) + aNonceWordP;
            aOrbiterA = (aWandererI + RotL64(aCross, 51U)) + 7340073357551376125U;
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 13U)) + RotL64(aCarry, 23U)) + 5270256573644196046U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 3567367996479995928U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 11939634537492733738U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5640541900117183639U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 7051817732424527120U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 1730487669951837941U;
            aOrbiterE = RotL64((aOrbiterE * 15191634337956285841U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 18009252467909454817U) + aOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 2361024272031696442U) ^ aNonceWordH;
            aOrbiterA = RotL64((aOrbiterA * 15215151562500226027U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 15902755877642960397U) + aOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 12243517544704116184U;
            aOrbiterD = RotL64((aOrbiterD * 2576071074148141447U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 16846181962302186187U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 636121425116506681U;
            aOrbiterI = RotL64((aOrbiterI * 17075030673338779993U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 6887385655828217318U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 3705834550934775862U;
            aOrbiterB = RotL64((aOrbiterB * 11275428284929594435U), 21U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterD) + 11165142437077969438U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordA;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 6426659930331618269U;
            aOrbiterF = RotL64((aOrbiterF * 17170640810530893705U), 5U);
            //
            aIngress = RotL64(aOrbiterA, 27U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterB, 41U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterE, 54U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterJ, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aIngress, 51U) + RotL64(aOrbiterD, 41U)) + aOrbiterB) + RotL64(aCarry, 21U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterD, 4U)) + aOrbiterJ);
            aWandererI = aWandererI + ((((RotL64(aCross, 13U) + RotL64(aOrbiterF, 47U)) + aOrbiterJ) + RotL64(aCarry, 37U)) + aNonceWordM);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 57U) + aOrbiterB) + RotL64(aOrbiterA, 57U)) + aWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aCross, 6U) + RotL64(aOrbiterI, 35U)) + aOrbiterA);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterE, 19U)) + aOrbiterF) + aWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 43U) + aOrbiterJ) + RotL64(aOrbiterA, 29U)) + aNonceWordB);
            //
            aCarry = aCarry + (RotL64(aWandererA, 56U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererG, 13U);
            aCarry = aCarry + RotL64(aIngress, 42U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aFireLaneA
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aFireLaneA forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aFireLaneD
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 15906U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneC[((aIndex + 13580U)) & S_BLOCK1], 46U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 15054U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 10626U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 10260U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 9542U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCarry, 35U)) ^ (RotL64(aPrevious, 23U) + RotL64(aCross, 54U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterE = (((aWandererD + RotL64(aIngress, 11U)) + RotL64(aCarry, 11U)) + 6381335981879993247U) + aNonceWordD;
            aOrbiterB = (aWandererJ + RotL64(aPrevious, 43U)) + 15595429101600023172U;
            aOrbiterA = (aWandererG + RotL64(aScatter, 19U)) + 5449234297249826461U;
            aOrbiterK = ((aWandererE + RotL64(aCross, 26U)) + RotL64(aCarry, 43U)) + 11213734849329731168U;
            aOrbiterF = ((aWandererF + RotL64(aIngress, 51U)) + 16438473952464514248U) + aOrbiterAssignSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterC = ((aWandererB + RotL64(aCross, 37U)) + 7357872882115186976U) + aNonceWordI;
            aOrbiterJ = ((((aWandererA + RotL64(aPrevious, 57U)) + RotL64(aCarry, 29U)) + 394402075160738643U) + aOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordO;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 11112941985410283532U) + aNonceWordP;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 14955125011182736212U) ^ aOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10711684773326395603U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 14770727009821304070U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 11286366598129204910U) ^ aNonceWordG;
            aOrbiterE = RotL64((aOrbiterE * 15884310771003021989U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 7358400908565425780U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 15635109923749114761U;
            aOrbiterF = RotL64((aOrbiterF * 12415152149408700329U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 13826842523738623579U) + aOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = (((aOrbiterK ^ aOrbiterB) ^ 1072811298828325231U) ^ aOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterK = RotL64((aOrbiterK * 9662800288646215083U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 4017334196009350776U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 8812213572751410831U;
            aOrbiterB = RotL64((aOrbiterB * 12744171921566782795U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 6723457786170634403U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 9785583533999417673U;
            aOrbiterC = RotL64((aOrbiterC * 7776915427605471097U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 10265132640322153964U) + aOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 8435670887514808087U;
            aOrbiterJ = RotL64((aOrbiterJ * 2706263045620662131U), 53U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterA, 11U);
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 35U));
            aIngress = aIngress + RotL64(aOrbiterB, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterF, 58U)) + aOrbiterA);
            aWandererB = aWandererB + (((RotL64(aIngress, 47U) + RotL64(aOrbiterJ, 5U)) + aOrbiterE) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 41U) + aOrbiterA) + RotL64(aOrbiterE, 37U)) + aWandererUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 3U) + RotL64(aOrbiterK, 43U)) + aOrbiterB) + aNonceWordN);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 34U) + RotL64(aOrbiterA, 27U)) + aOrbiterK);
            aWandererA = aWandererA + (((RotL64(aCross, 21U) + aOrbiterB) + RotL64(aOrbiterC, 19U)) + RotL64(aCarry, 29U));
            aWandererG = aWandererG ^ ((((RotL64(aScatter, 13U) + RotL64(aOrbiterK, 51U)) + aOrbiterE) + aNonceWordL) + aWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + RotL64(aWandererJ, 14U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 3
        // ingress from: aExpandLaneB, aWorkLaneD, aOperationLaneD
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aOperationLaneD forward/backward random
        // cross from: aExpandLaneA, aWorkLaneB, aOperationLaneA
        // cross directions: aExpandLaneA backward forced, aWorkLaneB backward forced, aOperationLaneA backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 21434U)) & S_BLOCK1], 20U) ^ RotL64(aWorkLaneD[((aIndex + 18411U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 21191U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 19170U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 22563U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aOperationLaneA[((aIndex + 21700U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 18U)) ^ (RotL64(aCross, 51U) + RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterC = ((((aWandererD + RotL64(aScatter, 5U)) + RotL64(aCarry, 47U)) + 16922357079016918108U) + aOrbiterAssignSaltB[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordF;
            aOrbiterI = (((aWandererH + RotL64(aIngress, 51U)) + RotL64(aCarry, 23U)) + 11771749797137599131U) + aNonceWordN;
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 57U)) + 4635668433708036077U) + aNonceWordH;
            aOrbiterE = ((aWandererJ + RotL64(aCross, 29U)) + 15827952719230577008U) + aOrbiterAssignSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = ((aWandererA + RotL64(aIngress, 35U)) + 1495675306110023086U) + aNonceWordC;
            aOrbiterJ = (aWandererG + RotL64(aCross, 42U)) + 7294835466949728365U;
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 13U)) + RotL64(aCarry, 11U)) + 179122461212041978U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 545981421632236251U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 15338259639814630535U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14895421566334357871U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 12924313840290895215U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 17846785921286020610U;
            aOrbiterB = RotL64((aOrbiterB * 18309347016029917133U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 5721472794107057875U) + aNonceWordO;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 16359630793856870319U) ^ aNonceWordM;
            aOrbiterA = RotL64((aOrbiterA * 14186771515526698907U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 10614102110239037308U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 16421992251278236531U) ^ aNonceWordL;
            aOrbiterC = RotL64((aOrbiterC * 2561232904676068089U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 8668149834861244963U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 12699331834360948734U) ^ aOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2249360824172616357U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 4470693178142950471U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 526000656022724741U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16688501462334673493U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 6880246132270094141U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 7126466778855297013U) ^ aOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5692237926830293205U), 5U);
            //
            aIngress = RotL64(aOrbiterI, 41U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterE, 54U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterB, 11U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterA, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aCross, 57U) + RotL64(aOrbiterI, 11U)) + aOrbiterA) + RotL64(aCarry, 23U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterE, 48U)) + aOrbiterK);
            aWandererH = aWandererH + (((RotL64(aPrevious, 35U) + aOrbiterC) + RotL64(aOrbiterJ, 39U)) + aWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterA, 23U)) + aOrbiterJ);
            aWandererK = aWandererK + (((RotL64(aPrevious, 6U) + aOrbiterB) + RotL64(aOrbiterI, 5U)) + aNonceWordE);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 29U) + aOrbiterK) + RotL64(aOrbiterC, 29U)) + aNonceWordD);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 47U) + aOrbiterC) + RotL64(aOrbiterI, 57U)) + RotL64(aCarry, 43U)) + aWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererG);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 4U));
            aCarry = aCarry + RotL64(aWandererK, 11U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aOperationLaneB
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aOperationLaneB forward/backward random
        // cross from: aExpandLaneB, aWorkLaneC, aOperationLaneC
        // cross directions: aExpandLaneB backward forced, aWorkLaneC backward forced, aOperationLaneC backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 30469U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((aIndex + 30082U)) & S_BLOCK1], 14U));
            aIngress ^= RotL64(aOperationLaneB[((aIndex + 29269U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 24729U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 31115U)) & S_BLOCK1], 4U));
            aCross ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 26632U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aIngress, 28U) + RotL64(aCross, 41U)) ^ (RotL64(aCarry, 53U) + RotL64(aPrevious, 13U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterH = (((aWandererE + RotL64(aScatter, 5U)) + RotL64(aCarry, 11U)) + 7075016829833562104U) + aNonceWordP;
            aOrbiterE = ((aWandererB + RotL64(aCross, 19U)) + 8783765886115517036U) + aNonceWordG;
            aOrbiterI = (((aWandererD + RotL64(aPrevious, 39U)) + RotL64(aCarry, 27U)) + 2996723892384565829U) + aNonceWordD;
            aOrbiterJ = (aWandererG + RotL64(aIngress, 11U)) + 9494134707342189476U;
            aOrbiterB = (((aWandererH + RotL64(aCross, 30U)) + RotL64(aCarry, 57U)) + 5052642981395679904U) + aOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 51U)) + 8766787055127962238U) + aNonceWordK;
            aOrbiterD = ((aWandererA + RotL64(aScatter, 57U)) + 4467211954388738079U) + aOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 8030255604633658608U) + aOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 16962408063455702251U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11171737929747471631U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 3768222186567699076U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 14930990410207899871U;
            aOrbiterB = RotL64((aOrbiterB * 10930005786146268241U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 14179761938395502502U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 1879084742719898108U) ^ aNonceWordH;
            aOrbiterJ = RotL64((aOrbiterJ * 16783034788172670121U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 5535012408925981515U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 12792553516710295939U;
            aOrbiterF = RotL64((aOrbiterF * 8577530993755159329U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 8979253163346099252U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 5559189896063990740U) ^ aNonceWordO;
            aOrbiterE = RotL64((aOrbiterE * 8832485423727331621U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 13937564337299044079U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 2393376759689394948U;
            aOrbiterH = RotL64((aOrbiterH * 2352815657830413941U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 12647519563697356479U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 10946871249960389549U;
            aOrbiterD = RotL64((aOrbiterD * 6272580371881237173U), 13U);
            //
            aIngress = RotL64(aOrbiterB, 43U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + RotL64(aOrbiterH, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aScatter, 53U) + aOrbiterF) + RotL64(aOrbiterB, 11U)) + aWandererUpdateSaltF[((aIndex + 8U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 35U) + aOrbiterB) + RotL64(aOrbiterD, 47U)) + aNonceWordA);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 29U) + aOrbiterE) + RotL64(aOrbiterB, 37U)) + aWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 10U) + aOrbiterJ) + RotL64(aOrbiterE, 19U)) + RotL64(aCarry, 37U)) + aNonceWordB);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 41U) + aOrbiterI) + RotL64(aOrbiterE, 27U));
            aWandererB = aWandererB + ((((RotL64(aCross, 3U) + RotL64(aOrbiterB, 56U)) + aOrbiterI) + RotL64(aCarry, 57U)) + aNonceWordL);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterE, 5U)) + aOrbiterH) + aNonceWordM);
            //
            aCarry = aCarry + (RotL64(aWandererD, 12U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + RotL64(aWandererK, 39U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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

void TwistExpander_BasketBall_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xA026DBBA3DACE6EBULL + 0xCE4C3839243CFA8FULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xF024F780B53A542BULL + 0xE8FA8CCFB22C929BULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xF38EF857B52B9287ULL + 0xA64BC7D249726F09ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xC39DB706D4BD327DULL + 0x9451721FF6DB54F4ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x919909ED8380589BULL + 0xF6F9D5DAE1011F0BULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xA484BAFB4987875BULL + 0xB6A2A7FE077BCCB0ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x9660681A295AB0E1ULL + 0xBC1A4B1D1DF00748ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xA989020938D7A96FULL + 0x8D64D86C0C105890ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xAF9C6E736529F609ULL + 0xA458604C0BBB19BDULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xB3572A64765123ABULL + 0xACB4BE971A41873BULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xE688B8A5900104F1ULL + 0xEC29B4D03DF03371ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x999D6F8585C4767BULL + 0xA904672876DD1DB3ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xCA23E6F2B5B918E7ULL + 0xD06D490A7788A99BULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xAD6275744128D78DULL + 0x9625A1AE970BAA0CULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xE7B69F41C74EDE17ULL + 0x97516C8C5C64F075ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xD14F4191F996508DULL + 0x95CED9B0DDEB7DA5ULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneA, aExpandLaneC, aExpandLaneD, aWorkLaneC, aOperationLaneA, aFireLaneC, aWorkLaneD, aOperationLaneB, aFireLaneD, aFireLaneB, aOperationLaneC, aWorkLaneB, aWorkLaneA
        // write to: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // kdf_b_loop_b loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneA
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aWorkLaneC
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aWorkLaneC backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 5794U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneB[((aIndex + 6468U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 1991U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 6729U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 3298U)) & S_BLOCK1], 48U));
            aCross ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 3665U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 6U) + RotL64(aPrevious, 57U)) ^ (RotL64(aCross, 41U) ^ RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterE = ((aWandererH + RotL64(aScatter, 19U)) + RotL64(aCarry, 29U)) + 3248574644570178787U;
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 29U)) + 4506961512959200024U) + aOrbiterAssignSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterB = (aWandererD + RotL64(aIngress, 54U)) + 8423739774540738590U;
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 41U)) + RotL64(aCarry, 53U)) + 6593975869641735337U;
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 47U)) + RotL64(aCarry, 23U)) + 16441716090557369103U;
            aOrbiterH = ((aWandererB + RotL64(aIngress, 5U)) + 7936601450453207914U) + aNonceWordG;
            aOrbiterA = ((aWandererI + RotL64(aScatter, 51U)) + 13333752583560167065U) + aNonceWordL;
            aOrbiterD = ((aWandererE + RotL64(aCross, 23U)) + 8013703284795432973U) + aOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 57U)) + 2349852779887439236U) + aNonceWordJ;
            aOrbiterK = (aWandererK + RotL64(aCross, 13U)) + 5318539364763284138U;
            aOrbiterC = ((aWandererF + RotL64(aIngress, 44U)) + 11450957608502944376U) + aNonceWordE;
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 9058992558327552687U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 632095686920230926U;
            aOrbiterB = RotL64((aOrbiterB * 12460364388358520799U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 14734218428913777098U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterJ) ^ 16344357661370784442U) ^ aOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterH = RotL64((aOrbiterH * 15049472842002138369U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 2981145363531184308U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 14176472085175714494U;
            aOrbiterJ = RotL64((aOrbiterJ * 2584623327412130939U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 11198457590069700889U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 952584436750426828U;
            aOrbiterA = RotL64((aOrbiterA * 1165713888651280355U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 4311591763498985972U) + aNonceWordI;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 16194341833989936369U;
            aOrbiterK = RotL64((aOrbiterK * 9997934560195932575U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 7560794022401107431U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 10683789740265711603U;
            aOrbiterE = RotL64((aOrbiterE * 15637823045351977883U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 11614366395125937178U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 10750771385100564416U;
            aOrbiterF = RotL64((aOrbiterF * 4987921274272444283U), 43U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterE) + 2934697034132204529U) + aOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1]) + aNonceWordK;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 4646873794658020363U;
            aOrbiterG = RotL64((aOrbiterG * 10555456865641580175U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 7913681837683568905U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 17603563535330106340U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17882943067522319671U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 15375641415139193079U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 17059712718085411887U;
            aOrbiterI = RotL64((aOrbiterI * 13722089235751208215U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 14022558453716067200U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 3248574644570178787U;
            aOrbiterD = RotL64((aOrbiterD * 15249135451439374621U), 21U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterG, 23U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 29U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 6U));
            aIngress = aIngress + (RotL64(aOrbiterF, 13U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 41U));
            aIngress = aIngress + RotL64(aOrbiterC, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aScatter, 21U) + aOrbiterB) + RotL64(aOrbiterJ, 26U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 26U) + RotL64(aOrbiterG, 21U)) + aOrbiterJ);
            aWandererC = aWandererC + (((RotL64(aIngress, 3U) + RotL64(aOrbiterH, 5U)) + aOrbiterI) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 11U) + aOrbiterJ) + RotL64(aOrbiterE, 53U));
            aWandererK = aWandererK + ((RotL64(aIngress, 51U) + aOrbiterC) + RotL64(aOrbiterD, 29U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 19U) + aOrbiterK) + RotL64(aOrbiterI, 3U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 13U) + RotL64(aOrbiterK, 36U)) + aOrbiterB);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterE, 51U)) + aOrbiterF) + aNonceWordF);
            aWandererF = aWandererF + (((((RotL64(aPrevious, 56U) + RotL64(aOrbiterF, 41U)) + aOrbiterA) + RotL64(aCarry, 37U)) + aNonceWordP) + aWandererUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 37U) + RotL64(aOrbiterG, 47U)) + aOrbiterH) + aWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 53U) + RotL64(aOrbiterG, 11U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 51U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + (RotL64(aWandererK, 30U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererE);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 37U));
            aCarry = aCarry + RotL64(aWandererC, 21U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 2
        // ingress from: aOperationLaneA, aExpandLaneC, aFireLaneC
        // ingress directions: aOperationLaneA forward forced, aExpandLaneC forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD, aWorkLaneD
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward forced, aWorkLaneD backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 15219U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneC[((aIndex + 8350U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 13706U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 9270U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 13042U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 9301U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 54U) ^ RotL64(aIngress, 5U)) ^ (RotL64(aPrevious, 21U) + RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 37U)) + RotL64(aCarry, 3U)) + 12632404972795375757U;
            aOrbiterI = ((aWandererA + RotL64(aScatter, 21U)) + 5351879979055988456U) + aNonceWordC;
            aOrbiterF = (((aWandererF + RotL64(aIngress, 53U)) + RotL64(aCarry, 29U)) + 3597737727467443413U) + aOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = (aWandererI + RotL64(aCross, 30U)) + 2830846754917852318U;
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 35U)) + 17311925960294518018U) + aOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = (aWandererD + RotL64(aIngress, 57U)) + 2083584640523695383U;
            aOrbiterD = ((aWandererH + RotL64(aCross, 13U)) + RotL64(aCarry, 51U)) + 15049343611387010158U;
            aOrbiterB = (aWandererG + RotL64(aScatter, 3U)) + 6443050378205811147U;
            aOrbiterH = (aWandererB + RotL64(aIngress, 26U)) + 6021965178697344070U;
            aOrbiterA = ((aWandererC + RotL64(aScatter, 23U)) + 5080289878758029976U) + aNonceWordB;
            aOrbiterC = (aWandererK + RotL64(aPrevious, 51U)) + 576927745306972983U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 4728489691382690859U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 6184355840165758855U) ^ aOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1515043910404156423U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 11220539885798595450U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 11091438724966718214U) ^ aNonceWordF;
            aOrbiterE = RotL64((aOrbiterE * 8225347114759391961U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 17184210490020062419U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 2150997767099116408U;
            aOrbiterB = RotL64((aOrbiterB * 8058553821648892499U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 7021953562676903717U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 17159676348343312834U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13877284519668483549U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 10367891770525239784U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 11922478487264201233U;
            aOrbiterC = RotL64((aOrbiterC * 9195137452661956029U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 17815162358981720634U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 9582631251085100284U;
            aOrbiterG = RotL64((aOrbiterG * 11838992994130850483U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 872593750259572264U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 17832330100262167302U;
            aOrbiterK = RotL64((aOrbiterK * 1114416841510028467U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 16601139856969287418U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 14931287111691324985U;
            aOrbiterH = RotL64((aOrbiterH * 16757174577841001179U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 11413072442039115924U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 15253605470589905889U;
            aOrbiterI = RotL64((aOrbiterI * 10832817442285245673U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 3653487723581514107U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 14891378240114471865U;
            aOrbiterJ = RotL64((aOrbiterJ * 1386594204573386051U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 15659724464711852035U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 12632404972795375757U) ^ aNonceWordJ;
            aOrbiterD = RotL64((aOrbiterD * 2407347385127296647U), 3U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterG, 21U);
            aIngress = aIngress + (RotL64(aOrbiterK, 18U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 39U));
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterC, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aIngress, 37U) + aOrbiterE) + RotL64(aOrbiterG, 57U)) + aNonceWordA);
            aWandererJ = aWandererJ + (((RotL64(aCross, 22U) + RotL64(aOrbiterJ, 11U)) + aOrbiterE) + aWandererUpdateSaltB[((aIndex + 16U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterB, 21U)) + aOrbiterA) + aNonceWordD) + aWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 51U) + aOrbiterG) + RotL64(aOrbiterI, 51U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 41U) + aOrbiterH) + RotL64(aOrbiterD, 34U));
            aWandererH = aWandererH + (((RotL64(aCross, 53U) + aOrbiterC) + RotL64(aOrbiterG, 13U)) + RotL64(aCarry, 39U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 19U) + aOrbiterC) + RotL64(aOrbiterK, 41U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 10U) + RotL64(aOrbiterA, 37U)) + aOrbiterC) + aNonceWordK);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 43U) + aOrbiterA) + RotL64(aOrbiterE, 23U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterG, 43U)) + aOrbiterF) + RotL64(aCarry, 51U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterD, 46U)) + aOrbiterF) + aNonceWordE);
            //
            aCarry = aCarry + (RotL64(aWandererG, 54U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererH, 39U) ^ aWandererI);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererF, 43U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 3
        // ingress from: aOperationLaneB, aExpandLaneD, aFireLaneD
        // ingress directions: aOperationLaneB forward forced, aExpandLaneD forward forced, aFireLaneD forward/backward random
        // cross from: aOperationLaneA, aExpandLaneB, aFireLaneB
        // cross directions: aOperationLaneA backward forced, aExpandLaneB backward forced, aFireLaneB backward/forward random
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 21231U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneD[((aIndex + 20626U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 19599U)) & S_BLOCK1], 54U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 19710U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 23966U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 18893U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aIngress, 39U)) ^ (RotL64(aPrevious, 23U) + RotL64(aCarry, 4U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterA = (aWandererK + RotL64(aPrevious, 57U)) + 16451272412693907816U;
            aOrbiterF = ((aWandererI + RotL64(aScatter, 39U)) + 10099485419723255462U) + aNonceWordH;
            aOrbiterE = (((aWandererD + RotL64(aIngress, 3U)) + 17668900099534923192U) + aOrbiterAssignSaltE[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordE;
            aOrbiterJ = (((aWandererG + RotL64(aCross, 11U)) + RotL64(aCarry, 57U)) + 5497093724143181753U) + aNonceWordI;
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 42U)) + RotL64(aCarry, 11U)) + 10354044773550071706U;
            aOrbiterD = ((aWandererE + RotL64(aCross, 35U)) + 12728258851198019099U) + aNonceWordM;
            aOrbiterB = ((aWandererC + RotL64(aIngress, 29U)) + RotL64(aCarry, 39U)) + 4144050505314242618U;
            aOrbiterH = (aWandererF + RotL64(aPrevious, 5U)) + 14133805325480076530U;
            aOrbiterK = (aWandererB + RotL64(aIngress, 21U)) + 308863673210602899U;
            aOrbiterI = (aWandererH + RotL64(aPrevious, 26U)) + 11741180130160569753U;
            aOrbiterG = ((aWandererA + RotL64(aScatter, 13U)) + 12926863156769180448U) + aOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1];
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 211920854786494259U) + aNonceWordP;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 13234608842479411078U;
            aOrbiterE = RotL64((aOrbiterE * 2556747209733759467U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 9164711974854618892U) + aOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 6667377062281954219U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2603737166987437649U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 4559040002406721850U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 1749875480850675109U;
            aOrbiterF = RotL64((aOrbiterF * 15822640067349481089U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 9555365165561936366U) + aNonceWordJ;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 18289733999504213574U) ^ aNonceWordA;
            aOrbiterH = RotL64((aOrbiterH * 14156217554673229429U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 8727162691639622461U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 291406782452963706U;
            aOrbiterA = RotL64((aOrbiterA * 8413500075082350243U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 8294911802626492257U) + aOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 15853578397277298548U;
            aOrbiterB = RotL64((aOrbiterB * 13256191781365357747U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 11535146194939658681U) + aNonceWordL;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 2177540476748375661U;
            aOrbiterK = RotL64((aOrbiterK * 15791341922007841029U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 2705306323728084136U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 17617871830709148043U;
            aOrbiterJ = RotL64((aOrbiterJ * 3449981219502809255U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 3699834746313613206U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 17952609181629473245U;
            aOrbiterG = RotL64((aOrbiterG * 6103160209028988839U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 8016694658897707674U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 6971251395823324489U;
            aOrbiterI = RotL64((aOrbiterI * 13483776115929040277U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 17467528888050817915U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 16451272412693907816U;
            aOrbiterD = RotL64((aOrbiterD * 13689734638238895071U), 19U);
            //
            aIngress = RotL64(aOrbiterK, 21U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 30U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 11U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 35U));
            aIngress = aIngress + RotL64(aOrbiterA, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterE, 35U)) + aOrbiterH) + RotL64(aCarry, 43U)) + aNonceWordO);
            aWandererH = aWandererH ^ (((RotL64(aCross, 43U) + aOrbiterH) + RotL64(aOrbiterF, 43U)) + aWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 30U) + aOrbiterC) + RotL64(aOrbiterG, 51U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 53U) + aOrbiterK) + RotL64(aOrbiterB, 23U));
            aWandererF = aWandererF + ((RotL64(aScatter, 37U) + aOrbiterF) + RotL64(aOrbiterK, 29U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterC, 6U)) + aOrbiterB);
            aWandererB = aWandererB + ((RotL64(aCross, 4U) + RotL64(aOrbiterI, 13U)) + aOrbiterJ);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterD, 27U)) + aOrbiterE);
            aWandererG = aWandererG + (((RotL64(aScatter, 13U) + RotL64(aOrbiterK, 39U)) + aOrbiterC) + RotL64(aCarry, 27U));
            aWandererE = aWandererE ^ ((((RotL64(aCross, 23U) + RotL64(aOrbiterG, 54U)) + aOrbiterA) + aNonceWordN) + aWandererUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 27U) + RotL64(aOrbiterB, 21U)) + aOrbiterJ) + aNonceWordB);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 48U));
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererI, 39U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 41U));
            aCarry = aCarry + RotL64(aWandererF, 52U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 4
        // ingress from: aOperationLaneC, aOperationLaneA, aWorkLaneB
        // ingress directions: aOperationLaneC forward forced, aOperationLaneA forward forced, aWorkLaneB forward/backward random
        // cross from: aOperationLaneB, aExpandLaneC, aWorkLaneA
        // cross directions: aOperationLaneB backward forced, aExpandLaneC backward forced, aWorkLaneA backward/forward random
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneC[((aIndex + 31174U)) & S_BLOCK1], 52U) ^ RotL64(aOperationLaneA[((aIndex + 32496U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 32482U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 24773U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 32326U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 27980U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCross, 37U) ^ RotL64(aIngress, 4U)) + (RotL64(aCarry, 51U) + RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterI = (aWandererB + RotL64(aIngress, 47U)) + 17711946802293254150U;
            aOrbiterF = (aWandererK + RotL64(aScatter, 41U)) + 16652362590489569378U;
            aOrbiterK = ((aWandererA + RotL64(aPrevious, 54U)) + 6972810344198183097U) + aOrbiterAssignSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterJ = ((aWandererE + RotL64(aCross, 27U)) + 13117100889782940546U) + aNonceWordI;
            aOrbiterE = (aWandererH + RotL64(aIngress, 5U)) + 13199305696782626591U;
            aOrbiterC = ((((aWandererC + RotL64(aCross, 11U)) + RotL64(aCarry, 37U)) + 992156184392760945U) + aOrbiterAssignSaltC[((aIndex + 12U)) & S_SALT1]) + aNonceWordE;
            aOrbiterG = (aWandererI + RotL64(aScatter, 37U)) + 13791265442074543880U;
            aOrbiterA = (aWandererD + RotL64(aPrevious, 58U)) + 17057087245252294859U;
            aOrbiterD = (aWandererF + RotL64(aScatter, 23U)) + 13444195995883541046U;
            aOrbiterB = ((aWandererG + RotL64(aIngress, 21U)) + RotL64(aCarry, 53U)) + 6723678233676059420U;
            aOrbiterH = (((aWandererJ + RotL64(aPrevious, 13U)) + RotL64(aCarry, 43U)) + 7913379431208430475U) + aNonceWordD;
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 4481887195529300665U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 11892724101424384078U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3468639499716604111U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 7700902083270424194U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 1888001433557140271U;
            aOrbiterC = RotL64((aOrbiterC * 8975562955027025349U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 14996753906788986929U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 939004845422123765U;
            aOrbiterA = RotL64((aOrbiterA * 2507090308972292313U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 11922230289291941807U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 15681187459741147199U) ^ aNonceWordN;
            aOrbiterJ = RotL64((aOrbiterJ * 10124947739653819101U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 9119043713532718155U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 8327697433992362166U;
            aOrbiterI = RotL64((aOrbiterI * 11157657162184304567U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 13630755116592440359U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 771252613886022889U;
            aOrbiterD = RotL64((aOrbiterD * 2958918915223536519U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 8524239721467527770U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 17732617735422435572U) ^ aNonceWordP;
            aOrbiterE = RotL64((aOrbiterE * 13992947983987668631U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 5265753270696005619U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 14456128349522985053U;
            aOrbiterB = RotL64((aOrbiterB * 5406509991740849617U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 12909993509014176457U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterD) ^ 10113568710432654194U) ^ aOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterF = RotL64((aOrbiterF * 6857806395910432831U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 14818978163348513071U) + aOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 17843349910031998923U;
            aOrbiterG = RotL64((aOrbiterG * 13608449524810499593U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 12589077818524017161U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 17711946802293254150U;
            aOrbiterH = RotL64((aOrbiterH * 9454569713107675231U), 53U);
            //
            aIngress = RotL64(aOrbiterA, 39U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 21U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 6U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 37U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 51U));
            aIngress = aIngress + RotL64(aOrbiterC, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aIngress, 5U) + RotL64(aOrbiterA, 43U)) + aOrbiterJ) + aNonceWordK);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterG, 35U)) + aOrbiterA);
            aWandererA = aWandererA + ((RotL64(aPrevious, 50U) + aOrbiterJ) + RotL64(aOrbiterC, 57U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 13U) + aOrbiterE) + RotL64(aOrbiterF, 23U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 21U) + aOrbiterI) + RotL64(aOrbiterK, 48U)) + aNonceWordL);
            aWandererE = aWandererE ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterF, 53U)) + aOrbiterB);
            aWandererF = aWandererF + (((RotL64(aIngress, 27U) + aOrbiterE) + RotL64(aOrbiterJ, 39U)) + aWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterH, 41U)) + aOrbiterJ);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 58U) + RotL64(aOrbiterI, 27U)) + aOrbiterB) + RotL64(aCarry, 47U)) + aNonceWordA);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 3U) + aOrbiterE) + RotL64(aOrbiterD, 30U)) + aWandererUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 29U) + RotL64(aOrbiterI, 51U)) + aOrbiterF) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 13U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 56U));
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + RotL64(aWandererK, 21U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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

void TwistExpander_BasketBall_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x9BD756185B27302DULL + 0xC3072F218C08C796ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xFB77BFA097C01745ULL + 0xAB29029853B5E624ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xC5CC641F99B95BCDULL + 0xDD93733D001F4EDEULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xBDC1AE13224C5507ULL + 0xC846F705069883F7ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xD20184D3326E903DULL + 0xA8DCF65A0E3BD811ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xF16755255F16CEB7ULL + 0xF20A01B14835D15FULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xCC2885E43B4BD0C3ULL + 0xD2FDAC131B3FC1F0ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xE859071585FFE999ULL + 0x8A879FDD4D73A9D6ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xD38B39171B1900EDULL + 0x988F916593ACF27CULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xA072A24BCA9A7651ULL + 0x8C6A4BC6EF434F6EULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xCC03D53D299E8E35ULL + 0xA193E99BC0BEAE7DULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xA093BDB2C4C505FBULL + 0xF26B948D2691D037ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xDEC40023D071E307ULL + 0xFD43290FAF7C99C2ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xE9A53849271A5777ULL + 0xF8C9C9B69DD57687ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x89858697AA1C6923ULL + 0x8FB798CC7434F6ADULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xEFF457E9E207EFC5ULL + 0xD3424B941A2923B5ULL);
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
        // read from: aOperationLaneA, aOperationLaneB, aWorkLaneA, aOperationLaneC, aOperationLaneD, aWorkLaneD, aExpandLaneA, aFireLaneC, aFireLaneA, aExpandLaneB, aWorkLaneC, aWorkLaneB, aExpandLaneC, aFireLaneD, aFireLaneB
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aWorkLaneA
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aWorkLaneA forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aWorkLaneD
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aWorkLaneD backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 5814U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneB[((aIndex + 5560U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aWorkLaneA[((aIndex + 1772U)) & S_BLOCK1], 58U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4718U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 2824U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 5193U)) & S_BLOCK1], 30U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aIngress, 3U) + RotL64(aCross, 19U)) ^ (RotL64(aPrevious, 35U) + RotL64(aCarry, 48U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterB = (aWandererA + RotL64(aIngress, 3U)) + 8506388683755208267U;
            aOrbiterC = (aWandererF + RotL64(aPrevious, 53U)) + 2179323259055019735U;
            aOrbiterE = ((aWandererC + RotL64(aCross, 36U)) + 3345902531140983016U) + aOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = ((aWandererH + RotL64(aScatter, 41U)) + RotL64(aCarry, 53U)) + 17456139311481306584U;
            aOrbiterI = (aWandererK + RotL64(aPrevious, 27U)) + 14587864088462311164U;
            aOrbiterK = (((aWandererE + RotL64(aCross, 11U)) + RotL64(aCarry, 3U)) + 13178947246650647057U) + aNonceWordD;
            aOrbiterD = ((aWandererB + RotL64(aScatter, 47U)) + 12866578138946916962U) + aNonceWordP;
            aOrbiterH = (((aWandererD + RotL64(aIngress, 18U)) + RotL64(aCarry, 29U)) + 13098524333655118173U) + aOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = (aWandererJ + RotL64(aPrevious, 23U)) + 15451329483787541982U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 9494299579678389385U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 15581954810375490643U;
            aOrbiterE = RotL64((aOrbiterE * 13670002280188424825U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 4487042505730624892U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 2774455928791636186U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15847933919136777451U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 12435319582397755819U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 10077180055177766823U;
            aOrbiterD = RotL64((aOrbiterD * 3924363471701748703U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 10391963896910956455U) + aNonceWordN;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 6149237416725301794U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10115917698918612823U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 15673402771629639978U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 14729117178956592426U;
            aOrbiterI = RotL64((aOrbiterI * 9070464269215820531U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 14492001279368870240U) + aNonceWordK;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 6278248084483259952U;
            aOrbiterB = RotL64((aOrbiterB * 16731228350971263873U), 3U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterK) + 15727518866499740411U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordO;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 8652631010810965473U;
            aOrbiterF = RotL64((aOrbiterF * 9508484121620912715U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 13660890300188313775U) + aNonceWordH;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 14699253534935936300U;
            aOrbiterA = RotL64((aOrbiterA * 3978135617259934869U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 1621689916308271346U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 5651399428852950385U;
            aOrbiterC = RotL64((aOrbiterC * 12220143634120124133U), 19U);
            //
            aIngress = RotL64(aOrbiterB, 53U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + (RotL64(aOrbiterE, 47U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterH, 58U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterC, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aIngress, 19U) + RotL64(aOrbiterF, 23U)) + aOrbiterE) + RotL64(aCarry, 29U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 12U) + RotL64(aOrbiterD, 6U)) + aOrbiterB);
            aWandererC = aWandererC + (((RotL64(aScatter, 5U) + RotL64(aOrbiterD, 35U)) + aOrbiterI) + aNonceWordL);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterF, 29U)) + aOrbiterD);
            aWandererD = aWandererD + ((RotL64(aScatter, 35U) + aOrbiterB) + RotL64(aOrbiterK, 43U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterK, 51U)) + aOrbiterC);
            aWandererF = aWandererF + ((((RotL64(aCross, 23U) + aOrbiterH) + RotL64(aOrbiterK, 19U)) + aNonceWordE) + aWandererUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterA, 47U)) + aOrbiterC);
            aWandererE = aWandererE + (((((RotL64(aPrevious, 52U) + aOrbiterI) + RotL64(aOrbiterE, 14U)) + RotL64(aCarry, 3U)) + aNonceWordM) + aWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 48U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererD, 35U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 2
        // ingress from: aExpandLaneA, aOperationLaneC, aFireLaneC
        // ingress directions: aExpandLaneA forward forced, aOperationLaneC forward forced, aFireLaneC forward/backward random
        // cross from: aOperationLaneA, aOperationLaneD, aFireLaneA
        // cross directions: aOperationLaneA backward forced, aOperationLaneD backward forced, aFireLaneA backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 8715U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneC[((aIndex + 11759U)) & S_BLOCK1], 56U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 10207U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 13188U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 16343U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 14285U)) & S_BLOCK1], 50U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCross, 57U)) + (RotL64(aCarry, 35U) + RotL64(aIngress, 6U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterK = (aWandererG + RotL64(aIngress, 46U)) + 6381335981879993247U;
            aOrbiterC = (aWandererI + RotL64(aCross, 53U)) + 15595429101600023172U;
            aOrbiterH = ((aWandererC + RotL64(aScatter, 13U)) + 5449234297249826461U) + aNonceWordC;
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 23U)) + RotL64(aCarry, 5U)) + 11213734849329731168U;
            aOrbiterE = ((aWandererA + RotL64(aIngress, 39U)) + 16438473952464514248U) + aOrbiterAssignSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = (aWandererJ + RotL64(aCross, 35U)) + 7357872882115186976U;
            aOrbiterG = (aWandererH + RotL64(aPrevious, 3U)) + 394402075160738643U;
            aOrbiterJ = (((aWandererD + RotL64(aScatter, 58U)) + RotL64(aCarry, 19U)) + 11112941985410283532U) + aNonceWordF;
            aOrbiterF = (((aWandererF + RotL64(aIngress, 27U)) + RotL64(aCarry, 53U)) + 14955125011182736212U) + aOrbiterAssignSaltD[((aIndex + 10U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 14770727009821304070U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 11286366598129204910U) ^ aOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15884310771003021989U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 7358400908565425780U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 15635109923749114761U;
            aOrbiterC = RotL64((aOrbiterC * 12415152149408700329U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 13826842523738623579U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 1072811298828325231U) ^ aNonceWordB;
            aOrbiterK = RotL64((aOrbiterK * 9662800288646215083U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 4017334196009350776U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterG) ^ 8812213572751410831U) ^ aOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterB = RotL64((aOrbiterB * 12744171921566782795U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 6723457786170634403U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 9785583533999417673U;
            aOrbiterG = RotL64((aOrbiterG * 7776915427605471097U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 10265132640322153964U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 8435670887514808087U;
            aOrbiterJ = RotL64((aOrbiterJ * 2706263045620662131U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 4303823386961718326U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 4214384238167491037U;
            aOrbiterI = RotL64((aOrbiterI * 8490707334221154005U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 8740835037840799136U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 5988815405391206280U;
            aOrbiterE = RotL64((aOrbiterE * 17838555472135715929U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 15539461383052981747U) + aNonceWordP;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 3743772525784217714U;
            aOrbiterF = RotL64((aOrbiterF * 6352086797545969187U), 47U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterK, 50U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 43U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 27U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + RotL64(aOrbiterE, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aIngress, 3U) + RotL64(aOrbiterI, 21U)) + aOrbiterF) + aNonceWordO);
            aWandererK = aWandererK ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterG, 42U)) + aOrbiterI) + aNonceWordL);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 14U) + RotL64(aOrbiterI, 53U)) + aOrbiterH) + RotL64(aCarry, 37U)) + aNonceWordA);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 39U) + aOrbiterJ) + RotL64(aOrbiterG, 57U));
            aWandererH = aWandererH + (((RotL64(aIngress, 57U) + RotL64(aOrbiterK, 11U)) + aOrbiterH) + RotL64(aCarry, 51U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 21U) + aOrbiterE) + RotL64(aOrbiterJ, 48U));
            aWandererD = aWandererD + (((RotL64(aScatter, 35U) + aOrbiterB) + RotL64(aOrbiterE, 37U)) + aWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 44U) + RotL64(aOrbiterC, 27U)) + aOrbiterK);
            aWandererF = aWandererF + ((((RotL64(aIngress, 51U) + aOrbiterC) + RotL64(aOrbiterB, 5U)) + aNonceWordN) + aWandererUpdateSaltA[((aIndex + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 5U));
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererD);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 38U));
            aCarry = aCarry + RotL64(aWandererF, 19U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 3
        // ingress from: aExpandLaneB, aOperationLaneD, aWorkLaneC
        // ingress directions: aExpandLaneB forward forced, aOperationLaneD forward forced, aWorkLaneC forward/backward random
        // cross from: aExpandLaneA, aOperationLaneB, aWorkLaneB
        // cross directions: aExpandLaneA backward forced, aOperationLaneB backward forced, aWorkLaneB backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 17903U)) & S_BLOCK1], 40U) ^ RotL64(aOperationLaneD[((aIndex + 18043U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 18060U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 20991U)) & S_BLOCK1], 34U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 23165U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 22240U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 47U) ^ RotL64(aCross, 35U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 22U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterE = ((aWandererD + RotL64(aScatter, 58U)) + RotL64(aCarry, 57U)) + 14157904117287696136U;
            aOrbiterF = ((aWandererF + RotL64(aCross, 27U)) + RotL64(aCarry, 27U)) + 7369512677371640676U;
            aOrbiterI = (((aWandererI + RotL64(aIngress, 37U)) + RotL64(aCarry, 43U)) + 8411250745902073798U) + aNonceWordK;
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 23U)) + 5002041814539710275U) + aOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = ((aWandererA + RotL64(aScatter, 53U)) + 9538041410816283124U) + aNonceWordM;
            aOrbiterB = (aWandererB + RotL64(aIngress, 41U)) + 5210700103927513061U;
            aOrbiterC = (aWandererE + RotL64(aCross, 13U)) + 7600709399101287982U;
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 48U)) + 2366369466696580499U;
            aOrbiterG = ((aWandererH + RotL64(aIngress, 19U)) + 5544575244203019109U) + aOrbiterAssignSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 8710073749110329779U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 15998211310115361630U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15275657696897688955U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 15354357553877376422U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 10657523549259276169U;
            aOrbiterK = RotL64((aOrbiterK * 13695239532898311073U), 13U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterB) + 10405750198355464768U) + aOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1]) + aNonceWordN;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 3465819693133515142U) ^ aOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14678343718277562799U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 16724189641701408630U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 3484340153620198872U;
            aOrbiterD = RotL64((aOrbiterD * 17247547677520703125U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 7420442404884871126U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 11138445997256757636U) ^ aNonceWordL;
            aOrbiterF = RotL64((aOrbiterF * 11167543379937571127U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 1428191560884663125U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 16950093140800653985U) ^ aNonceWordD;
            aOrbiterE = RotL64((aOrbiterE * 4423012306984814805U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 17288299075036481960U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 13793597915359681028U;
            aOrbiterG = RotL64((aOrbiterG * 9639204979982125757U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 5017972942710079726U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 12409957957614320964U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10273295741911545745U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 12487994181992095174U) + aNonceWordJ;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 1573393166996612118U;
            aOrbiterJ = RotL64((aOrbiterJ * 13364311829104520751U), 57U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterK, 6U);
            aIngress = aIngress + (RotL64(aOrbiterE, 19U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterF, 27U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterJ, 53U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterC, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterI, 13U)) + aOrbiterD);
            aWandererG = aWandererG + (((RotL64(aPrevious, 10U) + RotL64(aOrbiterB, 35U)) + aOrbiterC) + RotL64(aCarry, 3U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 53U) + aOrbiterG) + RotL64(aOrbiterF, 20U)) + aNonceWordF);
            aWandererA = aWandererA + (((RotL64(aCross, 57U) + aOrbiterI) + RotL64(aOrbiterB, 39U)) + RotL64(aCarry, 37U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterC, 3U)) + aOrbiterG) + aWandererUpdateSaltC[((aIndex + 26U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 27U) + aOrbiterK) + RotL64(aOrbiterD, 57U)) + aNonceWordG);
            aWandererD = aWandererD ^ (((RotL64(aCross, 6U) + aOrbiterJ) + RotL64(aOrbiterE, 53U)) + aNonceWordA);
            aWandererI = aWandererI + (((RotL64(aPrevious, 35U) + aOrbiterJ) + RotL64(aOrbiterK, 48U)) + aWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterK, 29U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 50U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 39U));
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererB, 13U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aFireLaneD
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aFireLaneD forward/backward random
        // cross from: aExpandLaneB, aOperationLaneC, aFireLaneB
        // cross directions: aExpandLaneB backward forced, aOperationLaneC backward forced, aFireLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 26384U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneA[((aIndex + 30233U)) & S_BLOCK1], 4U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 27028U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 24891U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 32494U)) & S_BLOCK1], 38U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 27280U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCarry, 6U) ^ RotL64(aPrevious, 57U)) ^ (RotL64(aCross, 19U) + RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterH = ((aWandererK + RotL64(aCross, 3U)) + RotL64(aCarry, 41U)) + 5160910997561396461U;
            aOrbiterA = (((aWandererA + RotL64(aScatter, 60U)) + 14920764751058512062U) + aOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterC = ((aWandererG + RotL64(aIngress, 23U)) + RotL64(aCarry, 57U)) + 6080952401749660022U;
            aOrbiterE = (aWandererF + RotL64(aPrevious, 27U)) + 17667234330526298627U;
            aOrbiterB = ((aWandererC + RotL64(aScatter, 51U)) + 760630072638686756U) + aNonceWordE;
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 13U)) + RotL64(aCarry, 19U)) + 3504157162816997476U;
            aOrbiterJ = (aWandererI + RotL64(aIngress, 34U)) + 9489022223422585882U;
            aOrbiterI = (aWandererH + RotL64(aCross, 19U)) + 1149898536879968964U;
            aOrbiterD = ((aWandererD + RotL64(aScatter, 47U)) + 10492284328940025310U) + aOrbiterAssignSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 13213275606286399312U) + aNonceWordO;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 10557118912847180413U;
            aOrbiterC = RotL64((aOrbiterC * 10077877991284587845U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 15618980209023994776U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 5268600749854045564U;
            aOrbiterA = RotL64((aOrbiterA * 3849660559223919613U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 8011552687609649990U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 3148133096349525066U) ^ aOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5245156554959620007U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 12032847944237867285U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 14999005703490824673U;
            aOrbiterB = RotL64((aOrbiterB * 6631584955208646049U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 5426735969392906710U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 3593177531650386729U;
            aOrbiterH = RotL64((aOrbiterH * 12997284886192717043U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 1701444719333347373U) + aNonceWordA;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 15928731228196894960U) ^ aOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1919318226904213433U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 5960179456039157036U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 5716434224061596483U;
            aOrbiterE = RotL64((aOrbiterE * 3731976564761202801U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 2136841536293340279U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 12969550408652728526U;
            aOrbiterD = RotL64((aOrbiterD * 7612191387451455137U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 3641997570461447114U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 4677572491523684525U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2730358077882211651U), 47U);
            //
            aIngress = RotL64(aOrbiterJ, 30U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterC, 43U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterA, 35U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterB, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aCross, 47U) + RotL64(aOrbiterD, 56U)) + aOrbiterF) + RotL64(aCarry, 47U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 58U) + RotL64(aOrbiterE, 23U)) + aOrbiterJ) + aNonceWordD);
            aWandererF = aWandererF + ((((RotL64(aScatter, 37U) + aOrbiterB) + RotL64(aOrbiterJ, 13U)) + RotL64(aCarry, 11U)) + aWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterE, 27U)) + aOrbiterA) + aNonceWordP);
            aWandererK = aWandererK + ((((RotL64(aCross, 41U) + aOrbiterD) + RotL64(aOrbiterB, 5U)) + aNonceWordN) + aWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 28U) + RotL64(aOrbiterJ, 42U)) + aOrbiterI);
            aWandererB = aWandererB + ((RotL64(aPrevious, 13U) + RotL64(aOrbiterF, 51U)) + aOrbiterI);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 23U) + aOrbiterC) + RotL64(aOrbiterH, 19U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterH, 37U)) + aOrbiterE) + aNonceWordF);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 21U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererC, 34U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererD, 47U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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

void TwistExpander_BasketBall_Arx::KDF_B_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xF96C216E6CBA34DBULL + 0xE8E8988E10B5F099ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xD264563053261103ULL + 0xA423A0B6CBD5DC30ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xBE913ADB0BBC9615ULL + 0xC20EC7572A80F0E0ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xC80E2176E45BEA25ULL + 0xFF2FDE2A674EF47DULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xDBD1C35B0ADBBAEFULL + 0xF5F7C63B6B859170ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xB23606E53A788C57ULL + 0xC5E45967EBE34EAFULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xD7DC2A49EF25342BULL + 0xA38805A2B946D46BULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xFB0CB2A7CFA98F43ULL + 0xF30114550F1EFE14ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x94AB1252B8F7B54DULL + 0xC13359E9BAC18F7CULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x8148CC20ABDA508DULL + 0xB62D384D62B8D964ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x9FA02231FAA19BD3ULL + 0xEA19F8F4AE85DECAULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xCBA1B0C72D342F99ULL + 0xD966197AEB5D604BULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x98FC02342C2B285DULL + 0xA0F42AD68F85F2C5ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x902F024B11EBE4CFULL + 0x9A06D438C1749EE3ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xBD8D50D0E95E2CA9ULL + 0xBDDE9F8183B4958BULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x8BDCF2372DEC0863ULL + 0xD2DB7D9A390DAE5AULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aOperationLaneC, aWorkLaneC, aWorkLaneD, aFireLaneA, aExpandLaneA, aFireLaneB, aOperationLaneA, aExpandLaneB, aFireLaneD, aOperationLaneB, aExpandLaneC, aFireLaneC, aOperationLaneD
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_d loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aOperationLaneC
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aOperationLaneC forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aFireLaneA
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aFireLaneA backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 6225U)) & S_BLOCK1], 14U) ^ RotL64(aWorkLaneB[((aIndex + 6873U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 3562U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 3955U)) & S_BLOCK1], 26U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 2882U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 3562U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 51U) ^ RotL64(aCross, 5U)) + (RotL64(aPrevious, 20U) ^ RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 29U)) + RotL64(aCarry, 41U)) + 15813325389431304548U;
            aOrbiterA = (((aWandererC + RotL64(aCross, 39U)) + RotL64(aCarry, 53U)) + 2223874171125403602U) + aNonceWordD;
            aOrbiterB = ((aWandererE + RotL64(aScatter, 51U)) + 5510483568496824130U) + aNonceWordC;
            aOrbiterF = (aWandererK + RotL64(aPrevious, 12U)) + 15474152493495661876U;
            aOrbiterG = ((aWandererG + RotL64(aScatter, 21U)) + 16846339705130829195U) + aOrbiterAssignSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = ((aWandererI + RotL64(aCross, 3U)) + 1289670576865739669U) + aNonceWordA;
            aOrbiterK = ((((aWandererH + RotL64(aPrevious, 57U)) + RotL64(aCarry, 21U)) + 18017354919647006944U) + aOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1]) + aNonceWordJ;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 8539685539928984921U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 3333721400836704048U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3745286323481400085U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 2261560416623815491U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 4377786131746816567U) ^ aOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9164777834392621157U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 18047393176583722719U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 8184724021940434631U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9800116157750921119U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 10469895939183324807U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 14543391765109879223U;
            aOrbiterK = RotL64((aOrbiterK * 4817987697437667225U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 5757225781746158178U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 3539000495894022869U;
            aOrbiterE = RotL64((aOrbiterE * 1032298408884695925U), 51U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterK) + 11288971092707065923U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordG;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 2761384065186568294U) ^ aNonceWordE;
            aOrbiterF = RotL64((aOrbiterF * 3323838837427471051U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 7120580145300417101U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 6977246291769372866U;
            aOrbiterG = RotL64((aOrbiterG * 15170353875184253779U), 19U);
            //
            aIngress = RotL64(aOrbiterA, 12U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + (RotL64(aOrbiterF, 35U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterJ, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterA, 19U)) + aOrbiterF) + RotL64(aCarry, 5U)) + aWandererUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 14U) + RotL64(aOrbiterK, 4U)) + aOrbiterJ) + aNonceWordF);
            aWandererC = aWandererC + (((((RotL64(aPrevious, 57U) + RotL64(aOrbiterJ, 27U)) + aOrbiterA) + RotL64(aCarry, 19U)) + aNonceWordB) + aWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 43U) + aOrbiterE) + RotL64(aOrbiterF, 41U));
            aWandererK = aWandererK + ((RotL64(aScatter, 29U) + RotL64(aOrbiterF, 57U)) + aOrbiterB);
            aWandererH = aWandererH ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterG, 13U)) + aOrbiterB);
            aWandererB = aWandererB + (((RotL64(aPrevious, 21U) + aOrbiterK) + RotL64(aOrbiterB, 47U)) + aNonceWordO);
            //
            aCarry = aCarry + (RotL64(aWandererI, 46U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 41U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + RotL64(aWandererK, 29U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aFireLaneB
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aFireLaneB forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aOperationLaneA
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aOperationLaneA backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 8400U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneC[((aIndex + 14721U)) & S_BLOCK1], 22U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 15302U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16043U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 10216U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 14878U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCarry, 41U) + RotL64(aPrevious, 29U)) + (RotL64(aIngress, 58U) ^ RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterF = (((aWandererF + RotL64(aIngress, 10U)) + RotL64(aCarry, 5U)) + 6916817163240024692U) + aNonceWordM;
            aOrbiterE = (aWandererE + RotL64(aScatter, 3U)) + 14554930751292077817U;
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 47U)) + RotL64(aCarry, 19U)) + 1098305064484336101U;
            aOrbiterC = (aWandererI + RotL64(aCross, 57U)) + 12192821172420471527U;
            aOrbiterG = (((aWandererA + RotL64(aScatter, 27U)) + RotL64(aCarry, 43U)) + 2435134991707318845U) + aNonceWordJ;
            aOrbiterK = ((aWandererK + RotL64(aCross, 21U)) + 1896745368738512624U) + aOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = (((aWandererJ + RotL64(aPrevious, 37U)) + 1114996424222923873U) + aOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordP;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 9839135798371512656U) + aOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 8037967239603177043U) ^ aNonceWordF;
            aOrbiterI = RotL64((aOrbiterI * 7848951103759663025U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 15185468738487237432U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 4912098316394854543U;
            aOrbiterG = RotL64((aOrbiterG * 3072785550384399929U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 13142688607850380888U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 4507379759608945839U;
            aOrbiterC = RotL64((aOrbiterC * 2989332387754215967U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 7299006009652289342U) + aOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 5390655277207053627U;
            aOrbiterF = RotL64((aOrbiterF * 10973744708856143715U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 6744737023577785725U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 15539737698867067285U;
            aOrbiterB = RotL64((aOrbiterB * 4686092035261336911U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 13329866734681377952U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 13284937458969166257U;
            aOrbiterE = RotL64((aOrbiterE * 3965985432462699445U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 8695002088915702168U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = (((aOrbiterK ^ aOrbiterI) ^ 3858059421620839286U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterK = RotL64((aOrbiterK * 9559783727301092937U), 35U);
            //
            aIngress = RotL64(aOrbiterB, 19U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 60U));
            aIngress = aIngress + (RotL64(aOrbiterC, 11U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterI, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterK, 43U)) + aOrbiterF) + aWandererUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 57U) + aOrbiterB) + RotL64(aOrbiterI, 14U));
            aWandererC = aWandererC + (((RotL64(aIngress, 5U) + RotL64(aOrbiterE, 51U)) + aOrbiterG) + aNonceWordD);
            aWandererA = aWandererA ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterC, 37U)) + aOrbiterK);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 41U) + RotL64(aOrbiterF, 57U)) + aOrbiterI) + RotL64(aCarry, 11U));
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 21U) + RotL64(aOrbiterK, 3U)) + aOrbiterI) + aNonceWordO) + aWandererUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 48U) + aOrbiterC) + RotL64(aOrbiterE, 27U)) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererC, 30U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererA, 39U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 3
        // ingress from: aExpandLaneB, aWorkLaneD, aFireLaneD
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aFireLaneD forward/backward random
        // cross from: aExpandLaneA, aWorkLaneB, aOperationLaneB
        // cross directions: aExpandLaneA backward forced, aWorkLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 22138U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneD[((aIndex + 19520U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 18943U)) & S_BLOCK1], 10U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24258U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 18307U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 23673U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aPrevious, 10U)) ^ (RotL64(aIngress, 47U) + RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterJ = (((aWandererD + RotL64(aCross, 47U)) + 14249093584376402677U) + aOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1]) + aNonceWordO;
            aOrbiterG = ((aWandererB + RotL64(aScatter, 53U)) + RotL64(aCarry, 53U)) + 8756965951816492264U;
            aOrbiterF = (((aWandererH + RotL64(aIngress, 3U)) + RotL64(aCarry, 37U)) + 11221139480258176330U) + aNonceWordB;
            aOrbiterE = (aWandererA + RotL64(aPrevious, 37U)) + 17218894445564194851U;
            aOrbiterH = (((aWandererI + RotL64(aIngress, 29U)) + 8064642692524949490U) + aOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1]) + aNonceWordK;
            aOrbiterI = ((aWandererE + RotL64(aCross, 10U)) + RotL64(aCarry, 3U)) + 5822093203710704646U;
            aOrbiterD = (aWandererF + RotL64(aScatter, 23U)) + 3217799620158102238U;
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterG) + 2613757677892120843U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordI;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 13647481499551657237U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5517563514031899891U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 3545714196663685016U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 9735422670576621521U;
            aOrbiterI = RotL64((aOrbiterI * 7276207208162697249U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 3911046580637583767U) + aNonceWordL;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 9315984027042049203U;
            aOrbiterH = RotL64((aOrbiterH * 12568550776487242469U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 8926367674641729058U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 11035347490524961446U;
            aOrbiterE = RotL64((aOrbiterE * 10948288997163592463U), 5U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterI) + 10748158733051120339U) + aOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1]) + aNonceWordP;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 2467801787989056455U;
            aOrbiterD = RotL64((aOrbiterD * 12621934274702358977U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 9244415080474351390U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 8517784887959492079U;
            aOrbiterJ = RotL64((aOrbiterJ * 17022899813765884147U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 8409307332803038455U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 11043806021873232950U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8294888329708842989U), 35U);
            //
            aIngress = RotL64(aOrbiterH, 35U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterG, 42U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 27U));
            aIngress = aIngress + RotL64(aOrbiterF, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aCross, 37U) + RotL64(aOrbiterH, 3U)) + aOrbiterE);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterG, 29U)) + aOrbiterJ);
            aWandererI = aWandererI + (((RotL64(aIngress, 3U) + aOrbiterE) + RotL64(aOrbiterF, 13U)) + aNonceWordE);
            aWandererF = aWandererF ^ ((((RotL64(aPrevious, 30U) + aOrbiterJ) + RotL64(aOrbiterD, 50U)) + aNonceWordJ) + aWandererUpdateSaltA[((aIndex + 22U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aIngress, 47U) + aOrbiterI) + RotL64(aOrbiterH, 21U)) + RotL64(aCarry, 37U)) + aNonceWordM);
            aWandererA = aWandererA ^ ((RotL64(aCross, 11U) + aOrbiterF) + RotL64(aOrbiterJ, 35U));
            aWandererD = aWandererD + (((((RotL64(aScatter, 19U) + aOrbiterI) + RotL64(aOrbiterE, 41U)) + RotL64(aCarry, 11U)) + aNonceWordA) + aWandererUpdateSaltD[((aIndex + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + (RotL64(aWandererF, 14U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererE, 51U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aFireLaneC
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneB, aWorkLaneC, aOperationLaneD
        // cross directions: aExpandLaneB backward forced, aWorkLaneC backward forced, aOperationLaneD backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 29734U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((aIndex + 31465U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 32572U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 24647U)) & S_BLOCK1], 36U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 28123U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 28464U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aIngress, 19U) ^ RotL64(aCarry, 5U)) + (RotL64(aCross, 40U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterK = (aWandererJ + RotL64(aIngress, 19U)) + 13915875634607599122U;
            aOrbiterI = ((aWandererF + RotL64(aCross, 13U)) + 1695770381382411673U) + aNonceWordG;
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 29U)) + RotL64(aCarry, 5U)) + 3709105579778295511U;
            aOrbiterC = ((aWandererI + RotL64(aScatter, 39U)) + RotL64(aCarry, 53U)) + 7673376335333251804U;
            aOrbiterE = ((((aWandererH + RotL64(aIngress, 54U)) + RotL64(aCarry, 35U)) + 8814147709738503518U) + aOrbiterAssignSaltF[((aIndex + 26U)) & S_SALT1]) + aNonceWordO;
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 47U)) + 13451412605350381172U) + aOrbiterAssignSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = ((aWandererD + RotL64(aScatter, 3U)) + 6447870234069609538U) + aNonceWordD;
            //
            aOrbiterK = (((aOrbiterK + aOrbiterI) + 13419487997946496825U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordF;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 5478309847615220345U;
            aOrbiterB = RotL64((aOrbiterB * 12953043149543448765U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 3635184969215610049U) + aOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 12527903812035294828U;
            aOrbiterE = RotL64((aOrbiterE * 12540800512035534967U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 1684685110885338814U) + aNonceWordM;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 12860354576326835090U;
            aOrbiterC = RotL64((aOrbiterC * 12743745087733307255U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 9081823570147481835U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 14369321778210049109U) ^ aOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17865953349448767035U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 11518132079084873250U) + aOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 11893535026126957389U;
            aOrbiterH = RotL64((aOrbiterH * 15751374986135615095U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 7084079180579206226U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 2999676609847603277U;
            aOrbiterK = RotL64((aOrbiterK * 14602698397511266403U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 17683445810614029153U) + aNonceWordC;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 11576460512964896969U;
            aOrbiterI = RotL64((aOrbiterI * 5243651036457051155U), 23U);
            //
            aIngress = RotL64(aOrbiterI, 43U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterH, 27U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterE, 21U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 37U) + aOrbiterJ) + RotL64(aOrbiterH, 58U));
            aWandererD = aWandererD + ((RotL64(aScatter, 53U) + aOrbiterC) + RotL64(aOrbiterH, 3U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 11U) + aOrbiterK) + RotL64(aOrbiterB, 47U)) + aNonceWordI);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 5U) + aOrbiterE) + RotL64(aOrbiterC, 23U)) + RotL64(aCarry, 5U)) + aNonceWordA);
            aWandererC = aWandererC ^ ((((RotL64(aScatter, 20U) + RotL64(aOrbiterI, 35U)) + aOrbiterB) + aNonceWordH) + aWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 27U) + aOrbiterJ) + RotL64(aOrbiterE, 11U)) + RotL64(aCarry, 21U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 47U) + aOrbiterC) + RotL64(aOrbiterI, 29U)) + aWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererC);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 44U));
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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

void TwistExpander_BasketBall_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltE;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xE82083BFBBCE7C49ULL + 0xA990EF5707483499ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x97D96A14036EA2C3ULL + 0xC28C6A9067F94D01ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xA0E25E58141A8CDBULL + 0xFCAD3D3018FB7540ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x9D70AC6B843E2815ULL + 0xA25B9DB6F516E113ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xD209D5364DF6F64BULL + 0xC6A8B13858791A55ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xAF95D2FA59FAEF9BULL + 0x9B58F7BF61F08E5BULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xA84384DFFF5F1B2DULL + 0xA053A7ACA6400C6BULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xDD127D3A60E17F2DULL + 0x919D58A38EF91467ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xAF95F16DC91C0585ULL + 0xBF9EB50D522DE22FULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x9B167EB7D708A375ULL + 0x839E71B7A8F49D52ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xCF4BA447A46DA62BULL + 0xF38EF11D13DD89AFULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xE25E11F8BD603987ULL + 0xE779891D048DA8D3ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xA12A048B6DC9A2DDULL + 0x9A7A37307FA0E2C2ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xA296FB540F730D2FULL + 0xF4439E7A0F173899ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xAABEE4E44EB07513ULL + 0xDF65F5F7E7061986ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xE3FEDB50C3A3075BULL + 0x97293A8CCD1E1152ULL);
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 230U)) & W_KEY1], 29U) ^ RotL64(aKeyRowReadB[((aIndex + 2325U)) & W_KEY1], 48U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 2123U)) & W_KEY1], 27U) ^ RotL64(mSource[((aIndex + 910U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aPrevious, 43U) ^ RotL64(aCross, 11U)) + (RotL64(aIngress, 57U) ^ RotL64(aCarry, 24U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 13U)) + RotL64(aCarry, 29U)) + 2672739400294801233U;
            aOrbiterB = ((aWandererC + RotL64(aScatter, 58U)) + RotL64(aCarry, 57U)) + 8475624545015101850U;
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 35U)) + 1252755112289831257U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterG = (((aWandererH + RotL64(aCross, 21U)) + RotL64(aCarry, 13U)) + 7938039507649183387U) + aNonceWordL;
            aOrbiterH = (aWandererF + RotL64(aIngress, 5U)) + 8167413146948861022U;
            aOrbiterA = ((aWandererE + RotL64(aScatter, 27U)) + 17712313989694374353U) + aNonceWordB;
            aOrbiterJ = ((aWandererI + RotL64(aCross, 51U)) + 7637042279892596975U) + aPhaseEOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 15770412950033467341U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 3951812021898608685U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6623127125223204737U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 8656983621098246507U) + aNonceWordF;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 17943342344730687317U;
            aOrbiterH = RotL64((aOrbiterH * 16495519451034883813U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 3087677463651608668U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 16493240011924342788U;
            aOrbiterA = RotL64((aOrbiterA * 16898479041530771871U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 7750923317452683057U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 2185924841611106546U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 708072658250726381U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 14676868738946722416U) + aNonceWordP;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 6849098251696302393U;
            aOrbiterG = RotL64((aOrbiterG * 2599806275837778069U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 17817755047153606419U) + aNonceWordH;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 9900465270314068757U;
            aOrbiterB = RotL64((aOrbiterB * 9267925873983176685U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 11380000891112113701U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 15930503831156546113U;
            aOrbiterD = RotL64((aOrbiterD * 14450535035065393845U), 35U);
            //
            aIngress = RotL64(aOrbiterD, 19U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + RotL64(aOrbiterB, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((((RotL64(aScatter, 53U) + aOrbiterH) + RotL64(aOrbiterG, 11U)) + aNonceWordI) + aPhaseEWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 47U) + aOrbiterB) + RotL64(aOrbiterD, 39U)) + RotL64(aCarry, 11U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterH, 5U)) + aOrbiterD) + aNonceWordA);
            aWandererF = aWandererF + ((((RotL64(aCross, 29U) + RotL64(aOrbiterJ, 54U)) + aOrbiterG) + RotL64(aCarry, 43U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterB, 29U)) + aOrbiterA);
            aWandererC = aWandererC + ((RotL64(aPrevious, 10U) + RotL64(aOrbiterJ, 47U)) + aOrbiterH);
            aWandererI = aWandererI ^ ((RotL64(aCross, 3U) + aOrbiterK) + RotL64(aOrbiterA, 21U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 22U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererK, 47U);
            aCarry = aCarry + RotL64(aIngress, 14U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 4039U)) & S_BLOCK1], 38U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 5292U)) & W_KEY1], 19U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 3953U)) & W_KEY1], 51U) ^ RotL64(mSource[((aIndex + 4407U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 52U) ^ RotL64(aPrevious, 27U)) + (RotL64(aCarry, 13U) + RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 13U)) + RotL64(aCarry, 27U)) + 17912271996338180948U;
            aOrbiterB = (((aWandererA + RotL64(aIngress, 57U)) + 13259276608841847058U) + aPhaseEOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1]) + aNonceWordP;
            aOrbiterK = ((aWandererD + RotL64(aCross, 4U)) + RotL64(aCarry, 11U)) + 16225936008657276089U;
            aOrbiterA = ((aWandererB + RotL64(aScatter, 35U)) + RotL64(aCarry, 39U)) + 2243058962151834071U;
            aOrbiterF = (((aWandererI + RotL64(aCross, 43U)) + 10637439274127347861U) + aPhaseEOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1]) + aNonceWordM;
            aOrbiterH = ((aWandererK + RotL64(aScatter, 51U)) + 15312219216405992627U) + aNonceWordG;
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 23U)) + 2393933972129878613U) + aNonceWordB;
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 4327069337247976513U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 8307656353434167837U;
            aOrbiterK = RotL64((aOrbiterK * 11386588389133096705U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 17299145556933889336U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterA) ^ 14458100581172798164U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterF = RotL64((aOrbiterF * 16543734663677070509U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 6410095654927998067U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 6168964796264687686U;
            aOrbiterH = RotL64((aOrbiterH * 16218071040190475953U), 51U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterJ) + 3667999465041020730U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordI;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 16021552859323602007U;
            aOrbiterI = RotL64((aOrbiterI * 6427266472526362663U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 12941668202330045095U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 4222032891850449934U;
            aOrbiterA = RotL64((aOrbiterA * 17292856787431308097U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 1346342592002730785U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 16860611785008118820U;
            aOrbiterJ = RotL64((aOrbiterJ * 384963420804756607U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 3193572711804730241U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 5866881282680588589U;
            aOrbiterB = RotL64((aOrbiterB * 9226331800853634597U), 37U);
            //
            aIngress = RotL64(aOrbiterH, 29U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 23U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 42U));
            aIngress = aIngress + RotL64(aOrbiterK, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aScatter, 4U) + aOrbiterA) + RotL64(aOrbiterK, 43U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 41U) + aOrbiterJ) + RotL64(aOrbiterA, 35U));
            aWandererA = aWandererA + ((((RotL64(aPrevious, 11U) + aOrbiterB) + RotL64(aOrbiterI, 60U)) + RotL64(aCarry, 39U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 51U) + aOrbiterJ) + RotL64(aOrbiterF, 29U)) + aNonceWordK);
            aWandererB = aWandererB + ((((RotL64(aIngress, 21U) + RotL64(aOrbiterF, 53U)) + aOrbiterB) + RotL64(aCarry, 57U)) + aNonceWordH);
            aWandererI = aWandererI ^ ((((RotL64(aCross, 35U) + RotL64(aOrbiterJ, 3U)) + aOrbiterB) + aNonceWordC) + aPhaseEWandererUpdateSaltD[((aIndex + 24U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 57U) + aOrbiterB) + RotL64(aOrbiterH, 19U)) + aNonceWordA);
            //
            aCarry = aCarry + (RotL64(aWandererI, 46U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererD, 41U) ^ aWandererC);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + RotL64(aWandererK, 5U);
            aCarry = aCarry + RotL64(aIngress, 52U);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 7187U)) & S_BLOCK1], 11U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 7038U)) & W_KEY1], 50U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 6204U)) & W_KEY1], 23U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 6457U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 7606U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 21U) ^ RotL64(aCross, 39U)) + (RotL64(aPrevious, 6U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterI = (((aWandererH + RotL64(aIngress, 3U)) + RotL64(aCarry, 41U)) + 15036852811491820366U) + aPhaseEOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = (((aWandererB + RotL64(aScatter, 13U)) + 305637140752898475U) + aPhaseEOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1]) + aNonceWordO;
            aOrbiterG = ((aWandererG + RotL64(aCross, 51U)) + 11948631574496129610U) + aNonceWordE;
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 35U)) + RotL64(aCarry, 5U)) + 5321623592482991426U;
            aOrbiterD = ((aWandererF + RotL64(aCross, 22U)) + RotL64(aCarry, 29U)) + 4075270159062690728U;
            aOrbiterF = (aWandererK + RotL64(aPrevious, 29U)) + 15111580500356908928U;
            aOrbiterJ = (aWandererA + RotL64(aScatter, 43U)) + 7244150695504160363U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 5131563519577488862U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 5881954992088651371U;
            aOrbiterG = RotL64((aOrbiterG * 2424421828597294607U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 12780935808751507998U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 12599159643925470226U;
            aOrbiterF = RotL64((aOrbiterF * 17690046932587062701U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 9466589929741834066U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 6093158735705189789U;
            aOrbiterH = RotL64((aOrbiterH * 7453778295800853653U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 17461243886150519249U) + aNonceWordL;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 15456408913739900718U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16093292401746174671U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 11260643903290392780U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 7870342756041882616U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2431528656086173419U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 134484990005888936U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 10626896209992890407U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12034131076645285597U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 14031164129515132292U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 1771835705730244212U) ^ aNonceWordK;
            aOrbiterJ = RotL64((aOrbiterJ * 186981668443596623U), 19U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterJ, 5U);
            aIngress = aIngress + (RotL64(aOrbiterG, 46U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterD, 29U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterH, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((((RotL64(aPrevious, 47U) + RotL64(aOrbiterF, 27U)) + aOrbiterA) + RotL64(aCarry, 43U)) + aNonceWordD) + aPhaseEWandererUpdateSaltA[((aIndex + 4U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 56U) + RotL64(aOrbiterH, 51U)) + aOrbiterJ) + aNonceWordG);
            aWandererF = aWandererF + ((RotL64(aCross, 11U) + RotL64(aOrbiterI, 11U)) + aOrbiterJ);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterF, 44U)) + aOrbiterI);
            aWandererI = aWandererI + (((RotL64(aCross, 29U) + aOrbiterI) + RotL64(aOrbiterG, 35U)) + aNonceWordH);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 21U) + aOrbiterF) + RotL64(aOrbiterD, 3U)) + aPhaseEWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aScatter, 37U) + aOrbiterD) + RotL64(aOrbiterI, 57U)) + RotL64(aCarry, 11U)) + aNonceWordA);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 37U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 41U));
            aCarry = aCarry + RotL64(aWandererA, 48U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 8319U)) & S_BLOCK1], 37U) ^ RotL64(aKeyRowReadB[((aIndex + 9759U)) & W_KEY1], 23U));
            aIngress ^= (RotL64(mSource[((aIndex + 9065U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((aIndex + 9075U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 10457U)) & W_KEY1], 43U) ^ RotL64(aWorkLaneB[((aIndex + 8274U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCross, 3U)) ^ (RotL64(aCarry, 35U) + RotL64(aPrevious, 54U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 23U)) + RotL64(aCarry, 47U)) + 13854738573712660276U;
            aOrbiterA = (aWandererH + RotL64(aIngress, 13U)) + 16835460633412286294U;
            aOrbiterG = (((aWandererF + RotL64(aScatter, 39U)) + RotL64(aCarry, 19U)) + 6785859293758091931U) + aNonceWordF;
            aOrbiterD = (aWandererG + RotL64(aCross, 30U)) + 126317283127992659U;
            aOrbiterH = (((aWandererJ + RotL64(aIngress, 3U)) + RotL64(aCarry, 5U)) + 7568963536291415413U) + aNonceWordJ;
            aOrbiterK = (((aWandererK + RotL64(aCross, 53U)) + 12294016745653004819U) + aPhaseFOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1]) + aNonceWordB;
            aOrbiterE = ((aWandererI + RotL64(aScatter, 47U)) + 18269588932920281147U) + aPhaseFOrbiterAssignSaltF[((aIndex + 16U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 5872406424994751026U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 7764434758831474129U;
            aOrbiterG = RotL64((aOrbiterG * 3772146788188420071U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 4804168969415573371U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 959601763507651280U;
            aOrbiterA = RotL64((aOrbiterA * 4647396592804833217U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 9257644462479293048U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 14332699366894494579U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8829304078930625541U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 10487012596470786004U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 612729229562321440U;
            aOrbiterD = RotL64((aOrbiterD * 11380387280507726003U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 7845523921295625315U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 12742115479740024747U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15578543510683986421U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 10294667720904610944U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterE) ^ 14369711143154904567U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterH = RotL64((aOrbiterH * 13753005602288309379U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 10918344717497681894U) + aNonceWordL;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 18136794828308636957U;
            aOrbiterE = RotL64((aOrbiterE * 17899418637978002409U), 57U);
            //
            aIngress = RotL64(aOrbiterA, 27U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 37U));
            aIngress = aIngress + (RotL64(aOrbiterK, 11U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterD, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aCross, 57U) + aOrbiterH) + RotL64(aOrbiterK, 5U));
            aWandererG = aWandererG ^ ((((RotL64(aScatter, 11U) + aOrbiterD) + RotL64(aOrbiterH, 13U)) + aNonceWordP) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 44U) + RotL64(aOrbiterA, 51U)) + aOrbiterD) + RotL64(aCarry, 37U)) + aNonceWordK);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterD, 57U)) + aOrbiterK) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aCross, 21U) + RotL64(aOrbiterG, 37U)) + aOrbiterE);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterE, 21U)) + aOrbiterH) + aNonceWordG);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 29U) + RotL64(aOrbiterB, 28U)) + aOrbiterH) + RotL64(aCarry, 13U)) + aNonceWordC);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 10U));
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererH);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = (RotL64(aWorkLaneD[((aIndex + 12680U)) & S_BLOCK1], 5U) ^ RotL64(aKeyRowReadA[((aIndex + 12675U)) & W_KEY1], 47U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 11252U)) & W_KEY1], 35U) ^ RotL64(mSource[((aIndex + 12460U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 12074U)) & S_BLOCK1], 58U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11113U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneC[((aIndex + 11990U)) & S_BLOCK1], 6U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCross, 5U)) + (RotL64(aCarry, 35U) + RotL64(aPrevious, 52U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterD = (((aWandererC + RotL64(aScatter, 29U)) + 4980738603982643969U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordL;
            aOrbiterG = (aWandererH + RotL64(aIngress, 4U)) + 17660278413018470020U;
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 57U)) + 17598114429859543466U) + aPhaseFOrbiterAssignSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterF = ((aWandererB + RotL64(aCross, 13U)) + RotL64(aCarry, 37U)) + 10993929335279994739U;
            aOrbiterB = (aWandererA + RotL64(aScatter, 51U)) + 17967203122976322481U;
            aOrbiterK = (((aWandererD + RotL64(aPrevious, 39U)) + RotL64(aCarry, 13U)) + 1872290205549034384U) + aNonceWordP;
            aOrbiterH = (((aWandererG + RotL64(aIngress, 19U)) + RotL64(aCarry, 51U)) + 16607778671782810797U) + aNonceWordE;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 4895226930754394376U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 14960359005982301383U;
            aOrbiterI = RotL64((aOrbiterI * 8546231310054433721U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 9921642352377700630U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 893281964367208693U;
            aOrbiterB = RotL64((aOrbiterB * 2345509157333444217U), 19U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterK) + 8232519988397858732U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1]) + aNonceWordH;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 4433022122758913407U;
            aOrbiterG = RotL64((aOrbiterG * 834240393225479419U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 12689609831247168353U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 404535388957472176U;
            aOrbiterD = RotL64((aOrbiterD * 14534020545479806593U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 3349108201964013155U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 4386449511297371730U;
            aOrbiterF = RotL64((aOrbiterF * 9596273264321140229U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 14314587717949070586U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 10923886625271054985U) ^ aNonceWordA;
            aOrbiterH = RotL64((aOrbiterH * 7838969002623486809U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 17634909585329833520U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 2021301459918350372U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1388242915918642741U), 57U);
            //
            aIngress = RotL64(aOrbiterK, 60U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 13U));
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterD, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((((RotL64(aPrevious, 39U) + aOrbiterH) + RotL64(aOrbiterD, 29U)) + aNonceWordC) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aCross, 21U) + RotL64(aOrbiterK, 57U)) + aOrbiterB);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 57U) + aOrbiterF) + RotL64(aOrbiterB, 35U));
            aWandererF = aWandererF + (((((RotL64(aIngress, 27U) + RotL64(aOrbiterF, 23U)) + aOrbiterI) + RotL64(aCarry, 23U)) + aNonceWordM) + aPhaseFWandererUpdateSaltB[((aIndex + 8U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 3U) + aOrbiterK) + RotL64(aOrbiterD, 44U));
            aWandererG = aWandererG + (((RotL64(aCross, 14U) + RotL64(aOrbiterD, 51U)) + aOrbiterG) + RotL64(aCarry, 3U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterF, 3U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 40U));
            aCarry = aCarry + (RotL64(aWandererB, 21U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererG, 35U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 15784U)) & S_BLOCK1], 40U) ^ RotL64(aWorkLaneC[((aIndex + 15956U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15479U)) & W_KEY1], 3U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 14587U)) & W_KEY1], 11U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 15272U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 14887U)) & S_BLOCK1], 50U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15276U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aPrevious, 29U) ^ RotL64(aCross, 5U)) + (RotL64(aCarry, 54U) ^ RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterI = (aWandererE + RotL64(aScatter, 27U)) + 11521331427196538632U;
            aOrbiterA = ((aWandererK + RotL64(aIngress, 57U)) + 16653824187682957632U) + aNonceWordD;
            aOrbiterD = (((aWandererC + RotL64(aPrevious, 40U)) + 11654676587350088289U) + aPhaseFOrbiterAssignSaltD[((aIndex + 12U)) & S_SALT1]) + aNonceWordL;
            aOrbiterH = (aWandererI + RotL64(aCross, 47U)) + 8010313317412193584U;
            aOrbiterE = ((((aWandererB + RotL64(aScatter, 3U)) + RotL64(aCarry, 5U)) + 1108775560502907471U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordF;
            aOrbiterK = ((aWandererF + RotL64(aCross, 13U)) + RotL64(aCarry, 37U)) + 243952321439823521U;
            aOrbiterJ = (((aWandererH + RotL64(aPrevious, 19U)) + RotL64(aCarry, 19U)) + 2324945800401240403U) + aNonceWordB;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 9257554497543369657U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 16701314607244592540U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8790054741039817107U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 3900445848034341782U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 7652316487347103658U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11480123491361589799U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 14980368605272070578U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 2001165460948764796U) ^ aNonceWordJ;
            aOrbiterK = RotL64((aOrbiterK * 8110980921827107649U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 1911044015666991050U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 11366207111147818339U;
            aOrbiterH = RotL64((aOrbiterH * 17234439040652553865U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 16469329744002456607U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 8062793687044950815U;
            aOrbiterI = RotL64((aOrbiterI * 5856142259851144369U), 11U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterH) + 15364721421972807872U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordI;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 8979915611483540231U;
            aOrbiterJ = RotL64((aOrbiterJ * 10899377466171153383U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 7654234623563110457U) + aNonceWordM;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 1526832460342135008U;
            aOrbiterA = RotL64((aOrbiterA * 12766083052650723051U), 37U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterK, 19U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 51U));
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterJ, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aIngress, 28U) + aOrbiterI) + RotL64(aOrbiterK, 19U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 35U) + aOrbiterA) + RotL64(aOrbiterJ, 43U));
            aWandererE = aWandererE + (((RotL64(aCross, 41U) + RotL64(aOrbiterA, 37U)) + aOrbiterH) + aNonceWordK);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterA, 26U)) + aOrbiterI);
            aWandererC = aWandererC + (((((RotL64(aPrevious, 13U) + RotL64(aOrbiterJ, 13U)) + aOrbiterE) + RotL64(aCarry, 19U)) + aNonceWordH) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 53U) + aOrbiterH) + RotL64(aOrbiterE, 51U)) + aPhaseFWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 5U) + RotL64(aOrbiterD, 57U)) + aOrbiterJ) + RotL64(aCarry, 47U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 58U));
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererF, 5U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 16551U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadA[((aIndex + 17032U)) & W_KEY1], 19U));
            aIngress ^= (RotL64(mSource[((aIndex + 16667U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((aIndex + 16835U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 19089U)) & W_KEY1], 23U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 18700U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 16719U)) & S_BLOCK1], 38U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCarry, 37U) ^ RotL64(aPrevious, 3U)) + (RotL64(aCross, 54U) + RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterB = ((aWandererH + RotL64(aScatter, 5U)) + RotL64(aCarry, 19U)) + 17470880031634374199U;
            aOrbiterC = ((aWandererG + RotL64(aCross, 53U)) + RotL64(aCarry, 39U)) + 757565846006937746U;
            aOrbiterE = (((aWandererJ + RotL64(aIngress, 29U)) + 9419282475801345674U) + aPhaseGOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1]) + aNonceWordB;
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 19U)) + 2014248014107898196U) + aNonceWordF;
            aOrbiterD = (aWandererK + RotL64(aCross, 13U)) + 15113928519446490441U;
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 43U)) + 7346126964886259935U) + aPhaseGOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = (((aWandererE + RotL64(aIngress, 60U)) + RotL64(aCarry, 3U)) + 5594123113093162359U) + aNonceWordH;
            //
            aOrbiterB = (((aOrbiterB + aOrbiterC) + 5659237263369402005U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1]) + aNonceWordC;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 11565709683423969703U;
            aOrbiterE = RotL64((aOrbiterE * 16731289017588574671U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 16782863743534856287U) + aNonceWordM;
            aOrbiterD = (((aOrbiterD ^ aOrbiterC) ^ 13499100900072115907U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterD = RotL64((aOrbiterD * 5567729598873214433U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 11414447651044205242U) + aNonceWordE;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 7545993795121430538U;
            aOrbiterI = RotL64((aOrbiterI * 10758488381206257261U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 11778229237616454988U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 2544793391976514665U;
            aOrbiterB = RotL64((aOrbiterB * 4021060413798523299U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 9972156716619459164U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 17651030383827445664U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6742914240706775487U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 17439147296849134543U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 10021926927948343656U;
            aOrbiterG = RotL64((aOrbiterG * 18139540407315440909U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 9309867875882669289U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 14951424455944346337U;
            aOrbiterC = RotL64((aOrbiterC * 10569523948169951309U), 37U);
            //
            aIngress = RotL64(aOrbiterJ, 5U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterI, 26U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterB, 51U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterE, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aScatter, 50U) + RotL64(aOrbiterJ, 23U)) + aOrbiterC) + aPhaseGWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 3U) + aOrbiterB) + RotL64(aOrbiterJ, 41U));
            aWandererA = aWandererA + ((((RotL64(aIngress, 11U) + aOrbiterI) + RotL64(aOrbiterJ, 5U)) + RotL64(aCarry, 37U)) + aNonceWordJ);
            aWandererH = aWandererH ^ ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterC, 35U)) + aOrbiterD) + aNonceWordD) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 29U) + aOrbiterB) + RotL64(aOrbiterE, 11U)) + RotL64(aCarry, 21U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 43U) + aOrbiterI) + RotL64(aOrbiterG, 47U)) + aNonceWordI);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 21U) + aOrbiterC) + RotL64(aOrbiterB, 56U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 42U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + RotL64(aWandererG, 11U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 20350U)) & S_BLOCK1], 53U) ^ RotL64(mSource[((aIndex + 21306U)) & S_BLOCK1], 18U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 20536U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((aIndex + 20177U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 19168U)) & W_KEY1], 57U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 19693U)) & W_KEY1], 47U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 21319U)) & S_BLOCK1], 26U) ^ RotL64(aWorkLaneB[((aIndex + 21429U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 24U) ^ RotL64(aCarry, 41U)) + (RotL64(aCross, 57U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterK = (aWandererB + RotL64(aIngress, 3U)) + 3621877681473089725U;
            aOrbiterI = (((aWandererD + RotL64(aPrevious, 39U)) + RotL64(aCarry, 11U)) + 4451752751536414717U) + aNonceWordJ;
            aOrbiterH = (((aWandererI + RotL64(aCross, 51U)) + RotL64(aCarry, 27U)) + 11371625415377772117U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = ((((aWandererK + RotL64(aScatter, 57U)) + RotL64(aCarry, 51U)) + 6046792758881150619U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordP;
            aOrbiterE = (aWandererA + RotL64(aIngress, 11U)) + 8213166120394461682U;
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 19U)) + 4343156661140422645U) + aNonceWordL;
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 26U)) + 11105271483234947905U) + aNonceWordF;
            //
            aOrbiterK = (((aOrbiterK + aOrbiterI) + 348904609985341372U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordO;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 12924652822526858767U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2801892489296408735U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 7461211697358520287U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 16551553555297890558U) ^ aNonceWordG;
            aOrbiterK = RotL64((aOrbiterK * 16432952324635746293U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 11908056404140782995U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 9147367258259948715U;
            aOrbiterC = RotL64((aOrbiterC * 10777628928376261667U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 8876461054692728610U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 10546855952702525404U;
            aOrbiterI = RotL64((aOrbiterI * 10071104785895309677U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 4748636139110443794U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 783046909529525098U;
            aOrbiterB = RotL64((aOrbiterB * 8969157702460927215U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 16683965945838696665U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 12385412690177109575U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10795062772707143187U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 8210546822184469023U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 13146493623236979963U) ^ aNonceWordK;
            aOrbiterE = RotL64((aOrbiterE * 13199947810161148155U), 27U);
            //
            aIngress = RotL64(aOrbiterI, 47U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 19U));
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterC, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 13U) + aOrbiterC) + RotL64(aOrbiterK, 57U));
            aWandererI = aWandererI + (((RotL64(aScatter, 37U) + RotL64(aOrbiterH, 13U)) + aOrbiterC) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterI, 35U)) + aOrbiterF);
            aWandererA = aWandererA + (((RotL64(aCross, 43U) + RotL64(aOrbiterH, 51U)) + aOrbiterF) + RotL64(aCarry, 37U));
            aWandererD = aWandererD ^ ((((RotL64(aIngress, 60U) + RotL64(aOrbiterE, 5U)) + aOrbiterF) + aNonceWordE) + aPhaseGWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 29U) + RotL64(aOrbiterB, 43U)) + aOrbiterK) + aNonceWordB);
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 5U) + aOrbiterK) + RotL64(aOrbiterI, 22U)) + aNonceWordM) + aPhaseGWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 40U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + RotL64(aWandererB, 53U);
            aCarry = aCarry + RotL64(aIngress, 6U);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 24062U)) & S_BLOCK1], 39U) ^ RotL64(aKeyRowReadA[((aIndex + 22488U)) & W_KEY1], 51U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 21908U)) & W_KEY1], 5U) ^ RotL64(aFireLaneC[((aIndex + 23445U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 24359U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 23413U)) & S_BLOCK1], 27U));
            aCross ^= (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 22196U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 22013U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aPrevious, 43U) ^ RotL64(aCarry, 27U)) ^ (RotL64(aIngress, 10U) + RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterB = (aWandererH + RotL64(aIngress, 60U)) + 12426357877879529292U;
            aOrbiterK = (((aWandererE + RotL64(aCross, 29U)) + 12604900366173639176U) + aPhaseGOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1]) + aNonceWordM;
            aOrbiterD = (((aWandererG + RotL64(aPrevious, 23U)) + RotL64(aCarry, 11U)) + 13511119007338929401U) + aNonceWordA;
            aOrbiterI = ((aWandererI + RotL64(aScatter, 11U)) + RotL64(aCarry, 57U)) + 9878720081166788060U;
            aOrbiterH = ((aWandererF + RotL64(aCross, 5U)) + RotL64(aCarry, 35U)) + 15463195409806395076U;
            aOrbiterJ = (((aWandererK + RotL64(aScatter, 51U)) + 6407922778852833423U) + aPhaseGOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1]) + aNonceWordF;
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 41U)) + 7690427254160734016U) + aNonceWordC;
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 18030974031722143619U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 17983938038322737041U;
            aOrbiterD = RotL64((aOrbiterD * 12479365337221685413U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 16605512170117753884U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterD) ^ 681802273302348322U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterH = RotL64((aOrbiterH * 14608920184802647123U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 15550312921312083819U) + aNonceWordD;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 17824154101711884508U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7358612830654795357U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 1939207786756735430U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 3132864634777826569U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13606281919426730325U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 12822929773923954849U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 16576106045887115660U;
            aOrbiterB = RotL64((aOrbiterB * 16370914370769903051U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 2398825881649235260U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 13700821892926092479U;
            aOrbiterJ = RotL64((aOrbiterJ * 10830623703416956043U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 2439833784883391606U) + aNonceWordI;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 15870638514107637833U;
            aOrbiterE = RotL64((aOrbiterE * 3797380922767479287U), 3U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterE, 57U);
            aIngress = aIngress + (RotL64(aOrbiterB, 35U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterD, 23U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterH, 12U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aScatter, 43U) + RotL64(aOrbiterB, 21U)) + aOrbiterE) + aNonceWordH) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 4U) + RotL64(aOrbiterE, 57U)) + aOrbiterJ) + aPhaseGWandererUpdateSaltC[((aIndex + 6U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 53U) + aOrbiterK) + RotL64(aOrbiterB, 37U)) + RotL64(aCarry, 41U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 11U) + aOrbiterI) + RotL64(aOrbiterH, 6U));
            aWandererG = aWandererG + (((RotL64(aScatter, 35U) + RotL64(aOrbiterI, 13U)) + aOrbiterB) + RotL64(aCarry, 3U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 27U) + aOrbiterD) + RotL64(aOrbiterI, 29U)) + aNonceWordP);
            aWandererI = aWandererI + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterJ, 47U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + RotL64(aWandererG, 54U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 25232U)) & S_BLOCK1], 35U) ^ RotL64(aKeyRowReadA[((aIndex + 26751U)) & W_KEY1], 46U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 26804U)) & S_BLOCK1], 21U) ^ RotL64(aFireLaneB[((aIndex + 26074U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 25435U)) & W_KEY1], 47U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 27257U)) & S_BLOCK1], 57U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 26200U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 24744U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCross, 21U) ^ RotL64(aIngress, 52U)) ^ (RotL64(aPrevious, 39U) + RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterB = ((((aWandererE + RotL64(aScatter, 38U)) + RotL64(aCarry, 41U)) + 10726035965553989335U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordP;
            aOrbiterF = ((aWandererH + RotL64(aIngress, 29U)) + RotL64(aCarry, 13U)) + 967354339530195662U;
            aOrbiterE = (((aWandererD + RotL64(aPrevious, 19U)) + RotL64(aCarry, 53U)) + 10834593005478605624U) + aNonceWordF;
            aOrbiterC = (aWandererK + RotL64(aCross, 13U)) + 1012888282838656933U;
            aOrbiterK = (aWandererF + RotL64(aPrevious, 51U)) + 15283530351725183253U;
            aOrbiterA = ((aWandererC + RotL64(aScatter, 57U)) + 11724495956731703750U) + aPhaseHOrbiterAssignSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = (aWandererG + RotL64(aCross, 5U)) + 4288330117317505776U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 10894778070022873473U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 15563886747621617467U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17884709931569040065U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 11182488628562891937U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 10420140066310588580U;
            aOrbiterB = RotL64((aOrbiterB * 13898299782819948719U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 11775138062167543111U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 16545391898578161683U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14588306527161321535U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 1550144656312299266U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 14903504853138279883U;
            aOrbiterF = RotL64((aOrbiterF * 8003033561266164387U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 309935535526750396U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 13991265868040011411U) ^ aNonceWordD;
            aOrbiterA = RotL64((aOrbiterA * 2887531132228588441U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 1755976294857114222U) + aNonceWordG;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 2259275858478396846U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7416165760067878161U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 4838175912944552936U) + aNonceWordJ;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 12307900457200936013U) ^ aNonceWordC;
            aOrbiterK = RotL64((aOrbiterK * 14719363144850838805U), 47U);
            //
            aIngress = RotL64(aOrbiterF, 6U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 35U));
            aIngress = aIngress + RotL64(aOrbiterB, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterA, 53U)) + aOrbiterJ);
            aWandererD = aWandererD + ((((RotL64(aScatter, 21U) + RotL64(aOrbiterA, 39U)) + aOrbiterC) + RotL64(aCarry, 47U)) + aNonceWordK);
            aWandererC = aWandererC ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterF, 11U)) + aOrbiterE) + aNonceWordA);
            aWandererE = aWandererE + (((RotL64(aPrevious, 46U) + RotL64(aOrbiterK, 27U)) + aOrbiterF) + RotL64(aCarry, 19U));
            aWandererF = aWandererF ^ ((((RotL64(aCross, 11U) + aOrbiterB) + RotL64(aOrbiterC, 47U)) + aNonceWordM) + aPhaseHWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 57U) + RotL64(aOrbiterF, 20U)) + aOrbiterJ) + aNonceWordB);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 5U) + aOrbiterB) + RotL64(aOrbiterE, 5U)) + aPhaseHWandererUpdateSaltA[((aIndex + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 24U) ^ aWandererE);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 41U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + RotL64(aWandererK, 13U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 27307U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneD[((aIndex + 27912U)) & S_BLOCK1], 20U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 29447U)) & W_KEY1], 41U) ^ RotL64(aFireLaneC[((aIndex + 28511U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 28476U)) & W_KEY1], 13U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 28121U)) & S_BLOCK1], 43U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29097U)) & S_BLOCK1], 21U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 27689U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aPrevious, 24U) + RotL64(aCross, 41U)) ^ (RotL64(aIngress, 57U) + RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterD = (((aWandererF + RotL64(aIngress, 29U)) + 12809562813316740345U) + aPhaseHOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1]) + aNonceWordE;
            aOrbiterA = (aWandererH + RotL64(aScatter, 19U)) + 17084212535326321199U;
            aOrbiterJ = ((aWandererA + RotL64(aCross, 3U)) + RotL64(aCarry, 13U)) + 16074921689983846769U;
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 54U)) + 14027986153007120145U) + aNonceWordK;
            aOrbiterG = ((aWandererD + RotL64(aIngress, 43U)) + RotL64(aCarry, 27U)) + 7633455951809250227U;
            aOrbiterH = (((aWandererB + RotL64(aCross, 35U)) + 340989348513370174U) + aPhaseHOrbiterAssignSaltE[((aIndex + 6U)) & S_SALT1]) + aNonceWordI;
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 13U)) + RotL64(aCarry, 53U)) + 5307820377645020116U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 5605285015771527274U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 5293500434746182790U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17674669610895537063U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 7263156475892261811U) + aNonceWordO;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 10672879570907433005U;
            aOrbiterG = RotL64((aOrbiterG * 2506338667179450741U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 16659226780900986107U) + aNonceWordJ;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 9774892622769850665U;
            aOrbiterH = RotL64((aOrbiterH * 7487477727543183211U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 10728057184108279042U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 5032485856947407217U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16651577903809154285U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 14642241075374862345U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 8386481273395203518U;
            aOrbiterA = RotL64((aOrbiterA * 11649977733867003445U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 2874153265304098104U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 11519900149177261000U;
            aOrbiterB = RotL64((aOrbiterB * 2010158758971864505U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 8885690878540115768U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 4482143389870987714U;
            aOrbiterC = RotL64((aOrbiterC * 7105332459437434281U), 37U);
            //
            aIngress = RotL64(aOrbiterB, 60U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 47U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterA, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 57U) + aOrbiterD) + RotL64(aOrbiterA, 27U));
            aWandererD = aWandererD + (((RotL64(aScatter, 3U) + aOrbiterC) + RotL64(aOrbiterJ, 3U)) + RotL64(aCarry, 41U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 13U) + aOrbiterA) + RotL64(aOrbiterB, 11U)) + aPhaseHWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 29U) + RotL64(aOrbiterG, 21U)) + aOrbiterH) + RotL64(aCarry, 27U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 19U) + aOrbiterB) + RotL64(aOrbiterG, 37U)) + aNonceWordN);
            aWandererK = aWandererK + (((RotL64(aIngress, 50U) + aOrbiterJ) + RotL64(aOrbiterD, 52U)) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 37U) + aOrbiterA) + RotL64(aOrbiterG, 43U)) + aNonceWordG);
            //
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererA, 42U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 32707U)) & S_BLOCK1], 23U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 32392U)) & W_KEY1], 57U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 32254U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30150U)) & S_BLOCK1], 5U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32548U)) & S_BLOCK1], 23U) ^ RotL64(aKeyRowReadB[((aIndex + 30643U)) & W_KEY1], 37U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aIngress, 24U)) + (RotL64(aPrevious, 57U) ^ RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterB = (aWandererC + RotL64(aCross, 19U)) + 11480359716598965890U;
            aOrbiterD = (((aWandererH + RotL64(aPrevious, 3U)) + RotL64(aCarry, 11U)) + 15431182525482873419U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = ((aWandererD + RotL64(aScatter, 42U)) + 11360504974812776707U) + aNonceWordB;
            aOrbiterI = (aWandererK + RotL64(aIngress, 51U)) + 9292576416573382769U;
            aOrbiterK = ((aWandererA + RotL64(aScatter, 13U)) + 1549257414531028975U) + aNonceWordE;
            aOrbiterH = (((aWandererB + RotL64(aIngress, 29U)) + RotL64(aCarry, 23U)) + 5347769463033129317U) + aPhaseHOrbiterAssignSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = ((aWandererF + RotL64(aCross, 57U)) + RotL64(aCarry, 37U)) + 17019199177478377234U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 16558106007323125094U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 3976182233825939422U) ^ aNonceWordG;
            aOrbiterF = RotL64((aOrbiterF * 4392162052317572289U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 2889047161195954395U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 2241831345026962605U;
            aOrbiterK = RotL64((aOrbiterK * 5757458560979927857U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 12850802412140579294U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 13541744735436450160U;
            aOrbiterI = RotL64((aOrbiterI * 906089290000537439U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 2085863085516538212U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 2969034221711544086U;
            aOrbiterH = RotL64((aOrbiterH * 7768528124408400403U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 6482666944512391472U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 16969153556875844613U;
            aOrbiterB = RotL64((aOrbiterB * 9483462388353216219U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 5161314086757363678U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 7150282484670673211U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8522427002337918663U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 5465304381272305847U) + aNonceWordD;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 2344610773390354017U;
            aOrbiterE = RotL64((aOrbiterE * 17010258514288089191U), 13U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterF, 47U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 41U));
            aIngress = aIngress + (RotL64(aOrbiterB, 35U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterH, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aCross, 57U) + RotL64(aOrbiterK, 27U)) + aOrbiterE) + RotL64(aCarry, 13U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 34U) + aOrbiterD) + RotL64(aOrbiterH, 47U));
            aWandererA = aWandererA + ((((RotL64(aScatter, 27U) + RotL64(aOrbiterK, 41U)) + aOrbiterD) + aNonceWordF) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 5U) + aOrbiterH) + RotL64(aOrbiterK, 53U)) + aNonceWordK);
            aWandererC = aWandererC + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterI, 34U)) + aOrbiterB) + RotL64(aCarry, 41U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 11U) + aOrbiterI) + RotL64(aOrbiterF, 21U)) + aNonceWordN);
            aWandererF = aWandererF + (((RotL64(aCross, 47U) + RotL64(aOrbiterH, 5U)) + aOrbiterB) + aPhaseHWandererUpdateSaltD[((aIndex + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererH);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 60U));
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererF, 29U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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

void TwistExpander_BasketBall_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x945C9254260EC0BFULL + 0xB481FA8E2A9E4622ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xE90A105757AB8755ULL + 0xA92DF65D5790006EULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xBFA065A835527919ULL + 0xCAB6F31C40C7586EULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xA441D917F1782437ULL + 0x987752A64B074014ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xF927B7844EBDE30BULL + 0xE75B5AE3188750C4ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xF85F27907D185359ULL + 0xF70AD19BDD12CDA4ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xD3A2AC40CB903A85ULL + 0x836744F997DB4005ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xCF0D7F130255DB15ULL + 0xE98580C24D78557EULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x96FDB175337471E9ULL + 0x8F5A199E93E1E7B4ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xDC6C2D374C797FA9ULL + 0xECC8BD71A258C147ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xBAD279280D8DEC0BULL + 0xFBC1984C4C6F9FFEULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xD4045623DFE08DD1ULL + 0xE16EB69424C8C274ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xA40C01F8C2E555B1ULL + 0xE38666920AD34495ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xFFEA625178AE2C93ULL + 0xE161BF474327D76EULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x9FB5CAAAFBBD3C8FULL + 0xED25E1AA14CC15C5ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xB62E0EF4611D17DFULL + 0xD2A551351DC65E34ULL);
    // GSeedRunSeed_B seed_loop_a (start)
    {
        // GSeedRunSeed_B seed_loop_a lane group
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneA, aFireLaneA, aInvestLaneB, aFireLaneD, aOperationLaneA, aFireLaneC, aOperationLaneB, aOperationLaneC
        // write to: aInvestLaneA, aInvestLaneB, aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // seed_loop_a loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneB
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneB forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 4831U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneB[((aIndex + 3685U)) & S_BLOCK1], 52U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 4008U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 942U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneD[((aIndex + 730U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aIngress, 56U)) + (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterK = (((aWandererJ + RotL64(aScatter, 51U)) + RotL64(aCarry, 23U)) + 17081642665820489793U) + aNonceWordA;
            aOrbiterI = (((aWandererD + RotL64(aIngress, 35U)) + RotL64(aCarry, 5U)) + 14468854040067229623U) + aPhaseAOrbiterAssignSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterC = (aWandererI + RotL64(aPrevious, 13U)) + 2249450222593057429U;
            aOrbiterF = (((aWandererF + RotL64(aCross, 60U)) + RotL64(aCarry, 51U)) + 14964389079511378664U) + aNonceWordC;
            aOrbiterJ = (((aWandererC + RotL64(aPrevious, 23U)) + 17003491054252360650U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordD;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 12710882240582032588U) + aNonceWordF;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 9887078182156755359U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8205865025853482573U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 7665284531810584704U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 7304284015511876717U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6193179739025093929U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 5517927023543751734U) + aNonceWordL;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 17704756310857362759U;
            aOrbiterJ = RotL64((aOrbiterJ * 15826832172923213591U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 11347400363019508578U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 11696395232760991243U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9725231749679442003U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 10875780291242873583U) + aNonceWordJ;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 7808740614343437672U;
            aOrbiterI = RotL64((aOrbiterI * 8889516201913716283U), 39U);
            //
            aIngress = RotL64(aOrbiterK, 27U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterI, 3U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterC, 14U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aScatter, 47U) + aOrbiterJ) + RotL64(aOrbiterI, 51U)) + aNonceWordG);
            aWandererF = aWandererF ^ ((((RotL64(aPrevious, 57U) + aOrbiterJ) + RotL64(aOrbiterC, 14U)) + aNonceWordP) + aPhaseAWandererUpdateSaltB[((aIndex + 14U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aIngress, 27U) + aOrbiterK) + RotL64(aOrbiterF, 5U)) + RotL64(aCarry, 29U)) + aNonceWordM);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 18U) + RotL64(aOrbiterK, 35U)) + aOrbiterC);
            aWandererI = aWandererI + ((((RotL64(aScatter, 37U) + RotL64(aOrbiterI, 43U)) + aOrbiterF) + RotL64(aCarry, 5U)) + aPhaseAWandererUpdateSaltF[((aIndex + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 54U));
            aCarry = aCarry + RotL64(aWandererC, 13U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 6105U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneC[((aIndex + 5719U)) & S_BLOCK1], 20U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 7503U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 10199U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneD[((aIndex + 8797U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCarry, 11U) ^ RotL64(aIngress, 39U)) ^ (RotL64(aCross, 53U) + RotL64(aPrevious, 26U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterJ = ((((aWandererB + RotL64(aCross, 43U)) + RotL64(aCarry, 5U)) + 6361545377408870615U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordO;
            aOrbiterF = (aWandererD + RotL64(aIngress, 51U)) + 2967245486744774933U;
            aOrbiterK = (((aWandererJ + RotL64(aScatter, 19U)) + 3836634268482850139U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordM;
            aOrbiterH = (((aWandererE + RotL64(aPrevious, 35U)) + RotL64(aCarry, 37U)) + 7691642115360086297U) + aNonceWordH;
            aOrbiterA = ((aWandererC + RotL64(aScatter, 4U)) + RotL64(aCarry, 51U)) + 16479280384178279281U;
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterF) + 2901468732552539249U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1]) + aNonceWordC;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 2600353867755647475U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1140827276372862433U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 5666596904781510956U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 16108791609267427553U;
            aOrbiterF = RotL64((aOrbiterF * 8904649663479834199U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 8389926875737312112U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 1689501721163024426U;
            aOrbiterH = RotL64((aOrbiterH * 6517194895779049139U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 11721701506949917719U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 3963842745030140473U) ^ aNonceWordK;
            aOrbiterA = RotL64((aOrbiterA * 6692473494944919373U), 53U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterK) + 8510538243472109368U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordI;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 18281865214102080387U) ^ aNonceWordG;
            aOrbiterJ = RotL64((aOrbiterJ * 1351546966368884609U), 11U);
            //
            aIngress = RotL64(aOrbiterF, 46U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 13U));
            aIngress = aIngress + RotL64(aOrbiterK, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterK, 47U)) + aOrbiterJ) + RotL64(aCarry, 47U)) + aNonceWordJ);
            aWandererJ = aWandererJ ^ ((((RotL64(aPrevious, 35U) + aOrbiterH) + RotL64(aOrbiterJ, 60U)) + aNonceWordB) + aPhaseAWandererUpdateSaltD[((aIndex + 16U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aCross, 57U) + RotL64(aOrbiterF, 29U)) + aOrbiterJ) + RotL64(aCarry, 19U)) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 46U) + RotL64(aOrbiterA, 39U)) + aOrbiterK) + aNonceWordD);
            aWandererB = aWandererB + (((RotL64(aScatter, 19U) + RotL64(aOrbiterF, 21U)) + aOrbiterA) + aNonceWordL);
            //
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererE, 38U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererD, 21U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aInvestLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_a loop 3
        // ingress from: aInvestLaneB, aExpandLaneD, aFireLaneD
        // ingress directions: aInvestLaneB forward forced, aExpandLaneD forward forced, aFireLaneD forward/backward random
        // cross from: aInvestLaneA, aExpandLaneB, aExpandLaneA
        // cross directions: aInvestLaneA backward forced, aExpandLaneB backward forced, aExpandLaneA backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneB[((aIndex + 13247U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneD[((aIndex + 15621U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 13333U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 11931U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 16378U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 13075U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 29U) ^ RotL64(aIngress, 58U)) + (RotL64(aCross, 11U) + RotL64(aPrevious, 43U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterG = (((aWandererK + RotL64(aIngress, 13U)) + RotL64(aCarry, 19U)) + 9041099828460168106U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = ((((aWandererG + RotL64(aScatter, 48U)) + RotL64(aCarry, 5U)) + 12883711604096848454U) + aPhaseAOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1]) + aNonceWordD;
            aOrbiterC = (aWandererI + RotL64(aPrevious, 27U)) + 17420968786226443079U;
            aOrbiterB = (((aWandererJ + RotL64(aCross, 5U)) + RotL64(aCarry, 41U)) + 3448213891716125104U) + aNonceWordP;
            aOrbiterF = ((aWandererE + RotL64(aIngress, 35U)) + 11866455977445336560U) + aNonceWordO;
            //
            aOrbiterG = (((aOrbiterG + aOrbiterI) + 4119356835384495905U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1]) + aNonceWordL;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 2186212599698637068U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6756888950976735707U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 6506144898969301620U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 12556800923644051626U) ^ aNonceWordH;
            aOrbiterF = RotL64((aOrbiterF * 15961043406612913121U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 4075551535185182945U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 17877694808492008749U;
            aOrbiterG = RotL64((aOrbiterG * 901315308379887473U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 5553428900598223316U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 14362304852277160675U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11415103199856419303U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 9174200302876075831U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 16110739511917638547U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7004356839428657949U), 37U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterI, 19U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 3U));
            aIngress = aIngress + RotL64(aOrbiterG, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 3U) + aOrbiterC) + RotL64(aOrbiterB, 39U)) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aIngress, 47U) + RotL64(aOrbiterF, 20U)) + aOrbiterG) + RotL64(aCarry, 43U)) + aNonceWordK);
            aWandererJ = aWandererJ ^ ((((RotL64(aCross, 57U) + aOrbiterC) + RotL64(aOrbiterG, 47U)) + aNonceWordN) + aPhaseAWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aScatter, 22U) + aOrbiterB) + RotL64(aOrbiterF, 3U)) + RotL64(aCarry, 13U)) + aNonceWordC);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 35U) + aOrbiterI) + RotL64(aOrbiterC, 29U)) + aNonceWordJ);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + RotL64(aWandererK, 11U);
            aCarry = aCarry + RotL64(aIngress, 34U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 20105U)) & S_BLOCK1], 14U) ^ RotL64(aInvestLaneA[((aIndex + 18909U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 21476U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 21755U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18113U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 19741U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 34U) + RotL64(aCarry, 47U)) + (RotL64(aPrevious, 19U) ^ RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterJ = (((aWandererJ + RotL64(aPrevious, 5U)) + RotL64(aCarry, 27U)) + 4204560462077827182U) + aNonceWordF;
            aOrbiterF = (((aWandererG + RotL64(aCross, 57U)) + RotL64(aCarry, 41U)) + 6572370199668594039U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = ((aWandererC + RotL64(aScatter, 37U)) + 15958999876732622825U) + aPhaseAOrbiterAssignSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterC = (((aWandererB + RotL64(aIngress, 29U)) + RotL64(aCarry, 5U)) + 9969349486879280377U) + aNonceWordP;
            aOrbiterA = ((aWandererD + RotL64(aScatter, 20U)) + 15450238998293956181U) + aNonceWordC;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 9128619863683138259U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 5691270563628979565U;
            aOrbiterB = RotL64((aOrbiterB * 2170424734274640859U), 37U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterC) + 5901029710568933106U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordO;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 10442738941988588834U) ^ aNonceWordH;
            aOrbiterA = RotL64((aOrbiterA * 7386621444831603817U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 3508116020325721993U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterC) ^ 13221917083569767259U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterJ = RotL64((aOrbiterJ * 6845108555710135357U), 21U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterB) + 11627915460377128176U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordI;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 17858261365514253433U;
            aOrbiterC = RotL64((aOrbiterC * 7535577636975884641U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 4294837988806295989U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 11242915481585070249U;
            aOrbiterF = RotL64((aOrbiterF * 17540688242763829319U), 51U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 46U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + RotL64(aOrbiterA, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((((RotL64(aScatter, 39U) + RotL64(aOrbiterC, 21U)) + aOrbiterB) + RotL64(aCarry, 29U)) + aNonceWordJ) + aPhaseAWandererUpdateSaltF[((aIndex + 6U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterC, 11U)) + aOrbiterA) + aNonceWordL);
            aWandererB = aWandererB + (((RotL64(aIngress, 30U) + RotL64(aOrbiterJ, 3U)) + aOrbiterA) + RotL64(aCarry, 13U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterC, 41U)) + aOrbiterF) + aPhaseAWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 57U) + aOrbiterF) + RotL64(aOrbiterA, 52U)) + aNonceWordN);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + RotL64(aWandererB, 27U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 24727U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneA[((aIndex + 25953U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25624U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 25420U)) & S_BLOCK1], 5U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 25670U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 24515U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aPrevious, 41U)) ^ (RotL64(aIngress, 53U) ^ RotL64(aCross, 20U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 47U)) + 16200278595895089008U) + aNonceWordC;
            aOrbiterC = (((aWandererD + RotL64(aCross, 35U)) + RotL64(aCarry, 39U)) + 1029614154810465897U) + aPhaseAOrbiterAssignSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterI = ((((aWandererK + RotL64(aScatter, 58U)) + RotL64(aCarry, 19U)) + 7129562468705441295U) + aPhaseAOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1]) + aNonceWordG;
            aOrbiterD = (((aWandererA + RotL64(aIngress, 5U)) + RotL64(aCarry, 57U)) + 14388903902433951274U) + aNonceWordI;
            aOrbiterK = (aWandererC + RotL64(aPrevious, 13U)) + 1013568949315967455U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 3128823373497815651U) + aNonceWordF;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 14525694606889470589U;
            aOrbiterI = RotL64((aOrbiterI * 12053226114431679195U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 14443983602196782887U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 12244220415328641190U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15052949098014803181U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 10477159225338766614U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 2842870123078131566U;
            aOrbiterK = RotL64((aOrbiterK * 11522265477555954071U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 8621138818955849917U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 5038396344400303181U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14636756322207385447U), 47U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterK) + 2768613802894372496U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 2027754864051410015U;
            aOrbiterC = RotL64((aOrbiterC * 2461322540050569287U), 3U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterF, 27U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + RotL64(aOrbiterD, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((((RotL64(aIngress, 51U) + aOrbiterD) + RotL64(aOrbiterI, 23U)) + aNonceWordL) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererD = aWandererD + (((((RotL64(aScatter, 29U) + RotL64(aOrbiterF, 56U)) + aOrbiterK) + RotL64(aCarry, 35U)) + aNonceWordB) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 42U) + aOrbiterF) + RotL64(aOrbiterC, 3U)) + aNonceWordD);
            aWandererH = aWandererH + (((RotL64(aCross, 3U) + aOrbiterC) + RotL64(aOrbiterI, 35U)) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 13U) + aOrbiterK) + RotL64(aOrbiterI, 13U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 21U));
            aCarry = aCarry + RotL64(aWandererD, 58U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 31568U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((aIndex + 28359U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 32710U)) & S_BLOCK1], 44U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32273U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 30109U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 29478U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCross, 41U) + RotL64(aIngress, 23U)) ^ (RotL64(aCarry, 11U) + RotL64(aPrevious, 54U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterF = (((aWandererJ + RotL64(aPrevious, 11U)) + RotL64(aCarry, 39U)) + 15910560457440369082U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = ((((aWandererC + RotL64(aScatter, 21U)) + RotL64(aCarry, 53U)) + 17953072986407436888U) + aPhaseAOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1]) + aNonceWordG;
            aOrbiterD = (((aWandererD + RotL64(aIngress, 36U)) + RotL64(aCarry, 5U)) + 15446940721193538669U) + aNonceWordJ;
            aOrbiterE = ((aWandererE + RotL64(aCross, 3U)) + 3020785262774422009U) + aNonceWordD;
            aOrbiterI = ((aWandererB + RotL64(aIngress, 51U)) + 7001288645424994404U) + aNonceWordB;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 13385250665458462689U) + aNonceWordP;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 4841895644623005949U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3898487345974386945U), 41U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterF) + 13053476783239482065U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1]) + aNonceWordE;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 641996979335975244U) ^ aNonceWordO;
            aOrbiterG = RotL64((aOrbiterG * 3697673197256549833U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 16211238020928688299U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 12715448751323279480U;
            aOrbiterF = RotL64((aOrbiterF * 2116880429675303291U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 17784406727699995290U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 16626339815786580778U;
            aOrbiterI = RotL64((aOrbiterI * 13940754474750138041U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 9035070625716345139U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 6085848172494001945U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10405728912339646693U), 3U);
            //
            aIngress = RotL64(aOrbiterD, 3U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterE, 24U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterI, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aIngress, 57U) + aOrbiterE) + RotL64(aOrbiterD, 5U)) + aNonceWordN);
            aWandererE = aWandererE + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterG, 21U)) + aOrbiterI) + RotL64(aCarry, 23U)) + aNonceWordF);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 38U) + aOrbiterF) + RotL64(aOrbiterD, 57U));
            aWandererC = aWandererC + ((((RotL64(aCross, 11U) + aOrbiterD) + RotL64(aOrbiterI, 36U)) + RotL64(aCarry, 53U)) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterG, 47U)) + aOrbiterE) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + RotL64(aWandererE, 12U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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

void TwistExpander_BasketBall_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x8296E908C7E6F091ULL + 0x890F7FBA7A78DA12ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x828608B266622DE3ULL + 0x8B4FD372E23FAAB7ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x890BD4A6E6DCB7AFULL + 0xB9EF68D0246820F1ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x9C680E88256CA8E1ULL + 0xA9E1DF11B6D404D5ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xB610A99D8F304637ULL + 0xAE74C9260A7C6AE7ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xF56DC75FAB18B5C9ULL + 0x956AD96D299580D8ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xC91C1278D0D1C9F1ULL + 0x85239F8BB9861544ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x9952904DBF5480DBULL + 0xA173128851EBE114ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xEC47D01B6338953FULL + 0xF91DEC97BCC791E6ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x9D4A519B93E38385ULL + 0x88647164A0DE4E9FULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xE80AE0F1BD695397ULL + 0xFA2F0DF9B76DF04EULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xE5B27488F86BDA33ULL + 0xACC50547D152B3B6ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xB44A772AFE29D89BULL + 0xF87713943E5E6432ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xE169D64AB706F687ULL + 0x8B5B75D7DA0F4571ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xC4C91B7AE55A2E19ULL + 0x82AF60B894FF97A1ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xA5A10674246092EDULL + 0x805DBB1811579B9DULL);
    // GSeedRunSeed_C seed_loop_b (start)
    {
        // GSeedRunSeed_C seed_loop_b lane group
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneB, aOperationLaneC, aOperationLaneD, aExpandLaneA, aInvestLaneC, aExpandLaneB, aExpandLaneC, aInvestLaneD, aExpandLaneD, aWorkLaneA, aFireLaneD, aWorkLaneB, aFireLaneC, aWorkLaneC, aFireLaneA
        // write to: aInvestLaneC, aInvestLaneD, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // seed_loop_b loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aFireLaneB
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aFireLaneB forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aExpandLaneA
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aExpandLaneA backward/forward random
        // write to: aInvestLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 3702U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneB[((aIndex + 1415U)) & S_BLOCK1], 38U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 1501U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4304U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 207U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 1611U)) & S_BLOCK1], 36U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aPrevious, 54U) + RotL64(aCross, 3U)) ^ (RotL64(aIngress, 19U) ^ RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterB = (aWandererC + RotL64(aPrevious, 39U)) + 15652862298542575895U;
            aOrbiterA = (((aWandererE + RotL64(aCross, 47U)) + RotL64(aCarry, 47U)) + 16925323928418184554U) + aNonceWordD;
            aOrbiterI = (((aWandererJ + RotL64(aScatter, 10U)) + RotL64(aCarry, 13U)) + 4413861484961668394U) + aPhaseBOrbiterAssignSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = (aWandererK + RotL64(aIngress, 57U)) + 2215946422098155969U;
            aOrbiterF = (((aWandererF + RotL64(aScatter, 23U)) + 14975185533513111110U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordB;
            aOrbiterE = (aWandererI + RotL64(aPrevious, 53U)) + 9711613814905834552U;
            aOrbiterC = (((aWandererB + RotL64(aIngress, 14U)) + RotL64(aCarry, 37U)) + 13154957291850149471U) + aNonceWordN;
            aOrbiterG = ((aWandererG + RotL64(aCross, 19U)) + 5058313016418534840U) + aNonceWordM;
            aOrbiterK = (aWandererH + RotL64(aIngress, 35U)) + 15011423472941211620U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 2030053257469580168U) + aNonceWordH;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 150530795186791193U;
            aOrbiterI = RotL64((aOrbiterI * 11106050063717096073U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 10878237472104183427U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 11724672539469573109U;
            aOrbiterF = RotL64((aOrbiterF * 16158741837357985395U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 9589700906445846956U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 1367381624958248949U;
            aOrbiterD = RotL64((aOrbiterD * 8459515089081211977U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 12003215666757518106U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 11232479330848006729U;
            aOrbiterG = RotL64((aOrbiterG * 10993290955464593033U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 13013910456628561621U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 6092509838924105265U;
            aOrbiterE = RotL64((aOrbiterE * 805601154718006061U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 11999225836250312801U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 14421271973875748413U) ^ aNonceWordE;
            aOrbiterB = RotL64((aOrbiterB * 9529010940887430157U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 15536288285741825272U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 2071793889925436679U) ^ aNonceWordO;
            aOrbiterA = RotL64((aOrbiterA * 1526376970151714589U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 5622386476463436967U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 16147972771639168516U;
            aOrbiterK = RotL64((aOrbiterK * 11826916832825159095U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 4519892856053952290U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 12059500374938843538U) ^ aNonceWordP;
            aOrbiterC = RotL64((aOrbiterC * 14987533625537956299U), 51U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterF, 29U);
            aIngress = aIngress + (RotL64(aOrbiterI, 38U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterD, 5U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterG, 23U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterK, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aIngress, 56U) + RotL64(aOrbiterK, 51U)) + aOrbiterF);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 43U) + aOrbiterC) + RotL64(aOrbiterB, 43U)) + aPhaseBWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aScatter, 29U) + aOrbiterD) + RotL64(aOrbiterF, 30U)) + RotL64(aCarry, 5U)) + aNonceWordI);
            aWandererH = aWandererH ^ (((RotL64(aCross, 5U) + aOrbiterF) + RotL64(aOrbiterG, 19U)) + aNonceWordL);
            aWandererB = aWandererB + (((RotL64(aIngress, 60U) + RotL64(aOrbiterC, 35U)) + aOrbiterA) + aNonceWordJ);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterK, 11U)) + aOrbiterB);
            aWandererJ = aWandererJ + (((RotL64(aCross, 11U) + aOrbiterG) + RotL64(aOrbiterK, 24U)) + RotL64(aCarry, 13U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterI, 47U)) + aOrbiterK);
            aWandererF = aWandererF + (((RotL64(aIngress, 35U) + RotL64(aOrbiterE, 57U)) + aOrbiterI) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 18U));
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererJ);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + RotL64(aWandererE, 39U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aInvestLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 2
        // ingress from: aInvestLaneC, aOperationLaneC, aOperationLaneD, aExpandLaneB
        // ingress directions: aInvestLaneC forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aExpandLaneB forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aExpandLaneC
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aExpandLaneC backward/forward random
        // write to: aInvestLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneC[((aIndex + 9073U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneC[((aIndex + 7388U)) & S_BLOCK1], 47U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 6844U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 7529U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 6602U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 7206U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 7577U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aIngress, 23U)) ^ (RotL64(aPrevious, 11U) + RotL64(aCross, 40U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 26U)) + 3684295017013759987U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = ((aWandererI + RotL64(aScatter, 5U)) + RotL64(aCarry, 53U)) + 6740408842457292881U;
            aOrbiterH = (aWandererJ + RotL64(aCross, 47U)) + 4563975890702399441U;
            aOrbiterG = (aWandererG + RotL64(aIngress, 43U)) + 797804144825287940U;
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 57U)) + RotL64(aCarry, 21U)) + 2763779540450101303U;
            aOrbiterE = ((aWandererB + RotL64(aCross, 21U)) + RotL64(aCarry, 35U)) + 13211846164102089685U;
            aOrbiterI = ((aWandererH + RotL64(aScatter, 51U)) + 15214578447281401982U) + aNonceWordI;
            aOrbiterC = ((aWandererD + RotL64(aIngress, 38U)) + 13745208628754232427U) + aPhaseBOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 11U)) + 17358621225969190747U) + aNonceWordB;
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 779739369960480023U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 4370963533701407813U;
            aOrbiterH = RotL64((aOrbiterH * 3123135216876641039U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 6061333005507739975U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 3589705340762734456U;
            aOrbiterF = RotL64((aOrbiterF * 16499293983611196967U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 10607697666369230567U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 9356757995305239271U;
            aOrbiterI = RotL64((aOrbiterI * 10945513661439954731U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 10093033335903048138U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 11037328061699834100U;
            aOrbiterC = RotL64((aOrbiterC * 11189760551792389605U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 558431161176115540U) + aNonceWordE;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 17795680919453449358U;
            aOrbiterG = RotL64((aOrbiterG * 3910117359996283803U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 6096779391116214109U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 17594243286880690775U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12655610181937429915U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 15414704802398002423U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = (((aOrbiterA ^ aOrbiterI) ^ 18040588240488602196U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterA = RotL64((aOrbiterA * 16344249573086571225U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 14636298592697156931U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 9677305688594936561U;
            aOrbiterE = RotL64((aOrbiterE * 8354776999961642997U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 16408025751875050713U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 10018342878801454965U;
            aOrbiterD = RotL64((aOrbiterD * 10349132962708124117U), 19U);
            //
            aIngress = RotL64(aOrbiterI, 50U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 27U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 43U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + RotL64(aOrbiterE, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aCross, 57U) + aOrbiterG) + RotL64(aOrbiterE, 51U)) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 30U) + RotL64(aOrbiterG, 35U)) + aOrbiterF);
            aWandererI = aWandererI + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterI, 40U)) + aOrbiterA) + aNonceWordJ);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterE, 27U)) + aOrbiterC);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 19U) + aOrbiterB) + RotL64(aOrbiterA, 11U)) + RotL64(aCarry, 5U)) + aNonceWordG);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 4U) + RotL64(aOrbiterA, 23U)) + aOrbiterC) + aNonceWordA);
            aWandererB = aWandererB + ((RotL64(aCross, 35U) + aOrbiterB) + RotL64(aOrbiterH, 57U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 39U) + aOrbiterI) + RotL64(aOrbiterD, 18U)) + aPhaseBWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aCross, 43U) + RotL64(aOrbiterH, 47U)) + aOrbiterG) + RotL64(aCarry, 21U)) + aNonceWordO);
            //
            aCarry = aCarry + (RotL64(aWandererH, 56U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererB, 13U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 41U));
            aCarry = aCarry + RotL64(aWandererA, 47U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aInvestLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_b loop 3
        // ingress from: aInvestLaneD, aOperationLaneA, aExpandLaneD
        // ingress directions: aInvestLaneD forward forced, aOperationLaneA forward forced, aExpandLaneD forward/backward random
        // cross from: aInvestLaneC, aOperationLaneC
        // cross directions: aInvestLaneC backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneD[((aIndex + 15153U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneA[((aIndex + 14949U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 13233U)) & S_BLOCK1], 28U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 13899U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 15006U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 56U) ^ RotL64(aCross, 5U)) ^ (RotL64(aCarry, 39U) + RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterI = ((aWandererD + RotL64(aCross, 37U)) + 11998579547770778580U) + aNonceWordK;
            aOrbiterA = (((aWandererB + RotL64(aIngress, 47U)) + RotL64(aCarry, 29U)) + 8409465187298704610U) + aNonceWordM;
            aOrbiterB = (((aWandererC + RotL64(aScatter, 3U)) + RotL64(aCarry, 11U)) + 3470222286110333500U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = (aWandererI + RotL64(aPrevious, 22U)) + 5704486785203069994U;
            aOrbiterC = (aWandererG + RotL64(aScatter, 51U)) + 10334944660253279633U;
            aOrbiterD = (((aWandererF + RotL64(aCross, 43U)) + 7626852700722567477U) + aPhaseBOrbiterAssignSaltB[((aIndex + 18U)) & S_SALT1]) + aNonceWordD;
            aOrbiterK = (aWandererK + RotL64(aPrevious, 57U)) + 14631310754943209743U;
            aOrbiterH = (aWandererA + RotL64(aIngress, 29U)) + 807160297237854120U;
            aOrbiterG = (((aWandererJ + RotL64(aPrevious, 12U)) + RotL64(aCarry, 41U)) + 5624154783624196107U) + aNonceWordJ;
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 4971444394698940423U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterI) ^ 6340057638461027062U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterB = RotL64((aOrbiterB * 12027586111086798629U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 9003019862787819481U) + aNonceWordA;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 13632057463595873033U;
            aOrbiterC = RotL64((aOrbiterC * 12575202147280216765U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 12766104026871797746U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 4062118445824915939U;
            aOrbiterK = RotL64((aOrbiterK * 13130770039048080701U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 5258212525426469978U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 9956946981015983939U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8106382657040497669U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 10837606223056473999U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 13292864885504191134U) ^ aNonceWordH;
            aOrbiterI = RotL64((aOrbiterI * 4445739587553669471U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 166087925900318658U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 6786842221885441388U;
            aOrbiterD = RotL64((aOrbiterD * 4411147600413147773U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 16888086378070246404U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 5240855484445974002U;
            aOrbiterF = RotL64((aOrbiterF * 402652898573422271U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 6874866669211571608U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 732890824978127460U;
            aOrbiterG = RotL64((aOrbiterG * 3776365957702257453U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 5541380495707308058U) + aNonceWordP;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 17947326584411475765U;
            aOrbiterH = RotL64((aOrbiterH * 10920952349981652899U), 13U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterG, 3U);
            aIngress = aIngress + (RotL64(aOrbiterH, 21U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 11U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 44U));
            aIngress = aIngress + RotL64(aOrbiterF, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterF, 13U)) + aOrbiterK);
            aWandererD = aWandererD + ((((RotL64(aScatter, 4U) + RotL64(aOrbiterB, 27U)) + aOrbiterD) + RotL64(aCarry, 47U)) + aNonceWordE);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 11U) + aOrbiterA) + RotL64(aOrbiterI, 36U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterD, 41U)) + aOrbiterG) + aNonceWordF);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterA, 19U)) + aOrbiterF);
            aWandererA = aWandererA + ((RotL64(aPrevious, 23U) + aOrbiterH) + RotL64(aOrbiterI, 47U));
            aWandererB = aWandererB ^ ((((RotL64(aCross, 19U) + RotL64(aOrbiterI, 58U)) + aOrbiterD) + aNonceWordG) + aPhaseBWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 27U) + aOrbiterF) + RotL64(aOrbiterG, 51U)) + RotL64(aCarry, 39U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 54U) + aOrbiterH) + RotL64(aOrbiterC, 3U)) + aNonceWordN);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 43U));
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererB, 14U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 4
        // ingress from: aWorkLaneA, aInvestLaneC, aFireLaneD
        // ingress directions: aWorkLaneA forward forced, aInvestLaneC forward forced, aFireLaneD forward/backward random
        // cross from: aInvestLaneD, aOperationLaneD
        // cross directions: aInvestLaneD backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 18951U)) & S_BLOCK1], 35U) ^ RotL64(aInvestLaneC[((aIndex + 17028U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 18441U)) & S_BLOCK1], 14U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 18445U)) & S_BLOCK1], 50U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 18117U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCarry, 18U) ^ RotL64(aIngress, 39U)) ^ (RotL64(aCross, 3U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterA = (aWandererC + RotL64(aScatter, 29U)) + 3612110001869385068U;
            aOrbiterH = (aWandererE + RotL64(aCross, 47U)) + 16340824141280225936U;
            aOrbiterD = (aWandererH + RotL64(aIngress, 58U)) + 15222338965130765231U;
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 51U)) + 6649270508107155041U) + aNonceWordO;
            aOrbiterE = (((aWandererD + RotL64(aIngress, 43U)) + RotL64(aCarry, 41U)) + 768217258655426384U) + aPhaseBOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 37U)) + RotL64(aCarry, 3U)) + 4481855259658861851U;
            aOrbiterB = ((aWandererF + RotL64(aScatter, 5U)) + 18318041934562434016U) + aPhaseBOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterK = ((aWandererI + RotL64(aCross, 22U)) + RotL64(aCarry, 27U)) + 4212457153804401807U;
            aOrbiterI = ((aWandererG + RotL64(aIngress, 13U)) + 16143621095636987628U) + aNonceWordK;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 2095664232866642086U) + aNonceWordD;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 4339527736737366572U;
            aOrbiterD = RotL64((aOrbiterD * 17503569508822244125U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 13679353177869884790U) + aNonceWordG;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 11582168502846418236U;
            aOrbiterF = RotL64((aOrbiterF * 135539430034462861U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 10451330452898542191U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 12951448817640617841U) ^ aNonceWordM;
            aOrbiterK = RotL64((aOrbiterK * 4141870904192742091U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 15389161934419370747U) + aNonceWordL;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 4754886272708253014U;
            aOrbiterB = RotL64((aOrbiterB * 16638243718191281597U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 11746389873929280688U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 12042680172517298768U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3814780289755857543U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 2648103752465009244U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 451594673632597973U;
            aOrbiterA = RotL64((aOrbiterA * 8496763663271072425U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 5696534794094099710U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 14609435045257077395U;
            aOrbiterE = RotL64((aOrbiterE * 14658408563237468407U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 11599395126850950133U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 12699598504604446664U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14313494063098111823U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 9398465148537154745U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 12139736860648011256U;
            aOrbiterH = RotL64((aOrbiterH * 15257503229375247987U), 3U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterI, 5U);
            aIngress = aIngress + (RotL64(aOrbiterE, 18U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 39U));
            aIngress = aIngress + (RotL64(aOrbiterF, 57U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterA, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aPrevious, 28U) + RotL64(aOrbiterJ, 43U)) + aOrbiterD);
            aWandererC = aWandererC ^ ((RotL64(aCross, 47U) + aOrbiterD) + RotL64(aOrbiterH, 58U));
            aWandererG = aWandererG + (((RotL64(aScatter, 19U) + aOrbiterE) + RotL64(aOrbiterK, 47U)) + RotL64(aCarry, 29U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 5U) + aOrbiterI) + RotL64(aOrbiterE, 37U)) + aPhaseBWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aScatter, 53U) + RotL64(aOrbiterK, 29U)) + aOrbiterB) + aNonceWordE) + aPhaseBWandererUpdateSaltA[((aIndex + 24U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 10U) + aOrbiterF) + RotL64(aOrbiterA, 10U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 23U) + aOrbiterE) + RotL64(aOrbiterF, 21U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterE, 3U)) + aOrbiterJ) + aNonceWordA);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 37U) + RotL64(aOrbiterA, 53U)) + aOrbiterD) + RotL64(aCarry, 39U)) + aNonceWordH);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + (RotL64(aWandererH, 50U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererG, 23U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_b loop 5
        // ingress from: aWorkLaneB, aInvestLaneD, aFireLaneC
        // ingress directions: aWorkLaneB forward forced, aInvestLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aWorkLaneA, aInvestLaneC
        // cross directions: aWorkLaneA backward forced, aInvestLaneC backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 25248U)) & S_BLOCK1], 3U) ^ RotL64(aInvestLaneD[((aIndex + 25699U)) & S_BLOCK1], 50U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 22252U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23393U)) & S_BLOCK1], 5U) ^ RotL64(aInvestLaneC[((aIndex + 27277U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aPrevious, 20U)) ^ (RotL64(aIngress, 5U) + RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterK = ((aWandererB + RotL64(aScatter, 10U)) + 16424657151168221875U) + aNonceWordJ;
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 53U)) + RotL64(aCarry, 3U)) + 17150123681886380361U;
            aOrbiterH = (aWandererF + RotL64(aPrevious, 23U)) + 16041993588694572757U;
            aOrbiterB = ((aWandererE + RotL64(aCross, 35U)) + 9871185846434828537U) + aPhaseBOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = ((aWandererI + RotL64(aScatter, 18U)) + RotL64(aCarry, 41U)) + 11227236398354430757U;
            aOrbiterI = ((aWandererD + RotL64(aCross, 47U)) + RotL64(aCarry, 21U)) + 5399325217402192631U;
            aOrbiterG = (aWandererA + RotL64(aIngress, 57U)) + 9248828789282890454U;
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 5U)) + 9041370494203701062U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = ((aWandererH + RotL64(aIngress, 27U)) + 14944424084524970764U) + aNonceWordB;
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 5481938174456671041U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 14783648629543752715U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7260164783191886395U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 12355573914530445723U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 9863991559011968318U;
            aOrbiterI = RotL64((aOrbiterI * 8495251211794343179U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 16149688605937250965U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 106041828692026825U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12199934305374582599U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 8076098639554567792U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 11155119311895580013U;
            aOrbiterK = RotL64((aOrbiterK * 1495180896564818647U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 6847612160595917702U) + aNonceWordD;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 16094377920388017367U) ^ aNonceWordK;
            aOrbiterC = RotL64((aOrbiterC * 4875801863643206333U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 13584719866672696684U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 13446209321646234607U) ^ aNonceWordF;
            aOrbiterB = RotL64((aOrbiterB * 9945349065094781529U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 15829806645369560988U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 12573767256739062550U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5649504278826069077U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 3850030870300393809U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 11857593987748189858U;
            aOrbiterE = RotL64((aOrbiterE * 15942863910931814193U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 5505918410521728373U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 12949653497121247860U) ^ aNonceWordL;
            aOrbiterA = RotL64((aOrbiterA * 90944913639560027U), 27U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterJ, 57U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + (RotL64(aOrbiterB, 40U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterE, 35U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterH, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aIngress, 57U) + RotL64(aOrbiterI, 60U)) + aOrbiterA);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 18U) + RotL64(aOrbiterK, 11U)) + aOrbiterJ) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 3U) + aOrbiterA) + RotL64(aOrbiterG, 37U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 11U) + aOrbiterH) + RotL64(aOrbiterE, 47U));
            aWandererB = aWandererB + ((((RotL64(aPrevious, 39U) + aOrbiterB) + RotL64(aOrbiterK, 51U)) + RotL64(aCarry, 29U)) + aNonceWordM);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 29U) + aOrbiterA) + RotL64(aOrbiterH, 41U)) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aScatter, 23U) + RotL64(aOrbiterE, 19U)) + aOrbiterC) + RotL64(aCarry, 19U)) + aNonceWordN);
            aWandererF = aWandererF ^ (((RotL64(aCross, 51U) + aOrbiterI) + RotL64(aOrbiterK, 23U)) + aNonceWordI);
            aWandererD = aWandererD + ((RotL64(aScatter, 46U) + RotL64(aOrbiterI, 28U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + (RotL64(aWandererB, 10U) ^ aWandererH);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + RotL64(aWandererA, 57U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 6
        // ingress from: aWorkLaneC, aWorkLaneA, aFireLaneA
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aFireLaneA forward/backward random
        // cross from: aWorkLaneB, aOperationLaneB
        // cross directions: aWorkLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 30344U)) & S_BLOCK1], 10U) ^ RotL64(aWorkLaneA[((aIndex + 28393U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 31841U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27953U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneB[((aIndex + 28207U)) & S_BLOCK1], 38U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCarry, 19U)) ^ (RotL64(aPrevious, 34U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 23U)) + 3621877681473089725U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterJ = (((aWandererD + RotL64(aCross, 12U)) + RotL64(aCarry, 13U)) + 4451752751536414717U) + aNonceWordD;
            aOrbiterG = (aWandererK + RotL64(aIngress, 53U)) + 11371625415377772117U;
            aOrbiterC = ((aWandererH + RotL64(aScatter, 39U)) + RotL64(aCarry, 51U)) + 6046792758881150619U;
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 47U)) + 8213166120394461682U) + aPhaseBOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = (aWandererE + RotL64(aIngress, 57U)) + 4343156661140422645U;
            aOrbiterB = ((aWandererB + RotL64(aScatter, 27U)) + 11105271483234947905U) + aNonceWordF;
            aOrbiterI = (aWandererF + RotL64(aCross, 19U)) + 348904609985341372U;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 34U)) + RotL64(aCarry, 23U)) + 12924652822526858767U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 7461211697358520287U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 16551553555297890558U;
            aOrbiterG = RotL64((aOrbiterG * 16432952324635746293U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 11908056404140782995U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 9147367258259948715U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10777628928376261667U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 8876461054692728610U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 10546855952702525404U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10071104785895309677U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 4748636139110443794U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 783046909529525098U) ^ aNonceWordB;
            aOrbiterC = RotL64((aOrbiterC * 8969157702460927215U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 16683965945838696665U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 12385412690177109575U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10795062772707143187U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 8210546822184469023U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 13146493623236979963U) ^ aNonceWordI;
            aOrbiterI = RotL64((aOrbiterI * 13199947810161148155U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 13857628148804187115U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 7241297989337473475U;
            aOrbiterK = RotL64((aOrbiterK * 16223448508809614229U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 773904571213804946U) + aNonceWordG;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 7660676598236419707U;
            aOrbiterD = RotL64((aOrbiterD * 14467390638468925567U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 16822672435156055469U) + aNonceWordP;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 6514707119190640433U;
            aOrbiterB = RotL64((aOrbiterB * 7097496727567460535U), 57U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterH, 54U);
            aIngress = aIngress + (RotL64(aOrbiterI, 37U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterK, 51U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + RotL64(aOrbiterD, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 19U) + aOrbiterB) + RotL64(aOrbiterI, 56U));
            aWandererE = aWandererE + ((RotL64(aIngress, 23U) + RotL64(aOrbiterB, 27U)) + aOrbiterD);
            aWandererB = aWandererB ^ ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterA, 47U)) + aOrbiterI) + aNonceWordA) + aPhaseBWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aCross, 58U) + aOrbiterJ) + RotL64(aOrbiterG, 51U)) + aNonceWordO) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 5U) + aOrbiterC) + RotL64(aOrbiterJ, 5U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 37U) + RotL64(aOrbiterB, 42U)) + aOrbiterK) + RotL64(aCarry, 43U)) + aNonceWordJ);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 41U) + aOrbiterH) + RotL64(aOrbiterI, 37U)) + aNonceWordH);
            aWandererF = aWandererF + (((RotL64(aCross, 29U) + aOrbiterJ) + RotL64(aOrbiterH, 11U)) + RotL64(aCarry, 19U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 54U) + RotL64(aOrbiterH, 23U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 46U));
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererF);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererJ, 53U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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

void TwistExpander_BasketBall_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xA0C4DECFB426C9BBULL + 0xDA3A8338F74062E1ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xDA01D8A9642F9CCDULL + 0xD66830692095E8C4ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xA3DEBBC792C9835BULL + 0x81571DF0666596D7ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xE6B2EEEBB62FBF01ULL + 0xADC341B46B0C45D3ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xD29CD0D69E3AFC5DULL + 0x970D057F38DC9DAFULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x81C419BAFE4C275BULL + 0xA9D5C756FE94F014ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xEE6849BB05D62F69ULL + 0xFD64086DA8146821ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xC53F2BBD6E2264F9ULL + 0xF746ADCECB78FAEDULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x95CCF385BF086FDBULL + 0xAC57F1798F4D9669ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x970FEDAADAC3E823ULL + 0xC3A3A69F8D1C55F2ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xD840452B098057B9ULL + 0xD56663E413C351A4ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xDE1040A7589780BBULL + 0x9561892AFDC956BBULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x98D2F82BF310D2F3ULL + 0xE44AAAF985A102A2ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xCADAC0E6E2A1E5E9ULL + 0xDE5AE9CDB7E03D11ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xF7E9FCDB8340A83BULL + 0xE40553DF20229839ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x9AAFF07D3E5DEE89ULL + 0xEF2C3522B9A806F6ULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 4518U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((aIndex + 3865U)) & S_BLOCK1], 42U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 3093U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 845U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 4304U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 3850U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aIngress, 39U)) ^ (RotL64(aCross, 54U) ^ RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterE = (aWandererK + RotL64(aPrevious, 29U)) + 16451272412693907816U;
            aOrbiterD = ((aWandererE + RotL64(aCross, 20U)) + RotL64(aCarry, 53U)) + 10099485419723255462U;
            aOrbiterJ = (((aWandererF + RotL64(aScatter, 57U)) + RotL64(aCarry, 27U)) + 17668900099534923192U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = (((aWandererI + RotL64(aIngress, 37U)) + RotL64(aCarry, 5U)) + 5497093724143181753U) + aNonceWordN;
            aOrbiterA = (aWandererB + RotL64(aCross, 11U)) + 10354044773550071706U;
            aOrbiterF = ((aWandererG + RotL64(aScatter, 43U)) + 12728258851198019099U) + aNonceWordO;
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 51U)) + 4144050505314242618U) + aPhaseDOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 14133805325480076530U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 308863673210602899U;
            aOrbiterJ = RotL64((aOrbiterJ * 2672613556981540433U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 11741180130160569753U) + aNonceWordM;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 12926863156769180448U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9726030996091054939U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 211920854786494259U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 13234608842479411078U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2556747209733759467U), 51U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterB) + 9164711974854618892U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordG;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 6667377062281954219U;
            aOrbiterF = RotL64((aOrbiterF * 2603737166987437649U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 4559040002406721850U) + aNonceWordK;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 1749875480850675109U;
            aOrbiterB = RotL64((aOrbiterB * 15822640067349481089U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 9555365165561936366U) + aNonceWordA;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 18289733999504213574U;
            aOrbiterC = RotL64((aOrbiterC * 14156217554673229429U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 8727162691639622461U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 291406782452963706U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8413500075082350243U), 37U);
            //
            aIngress = RotL64(aOrbiterE, 5U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterB, 39U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterJ, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterF, 42U)) + aOrbiterJ);
            aWandererK = aWandererK + (((((RotL64(aCross, 5U) + RotL64(aOrbiterB, 53U)) + aOrbiterE) + RotL64(aCarry, 53U)) + aNonceWordC) + aPhaseDWandererUpdateSaltF[((aIndex + 16U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterD, 11U)) + aOrbiterA) + aNonceWordP);
            aWandererG = aWandererG + (((RotL64(aScatter, 53U) + aOrbiterC) + RotL64(aOrbiterF, 27U)) + aNonceWordH);
            aWandererE = aWandererE ^ (((RotL64(aCross, 42U) + RotL64(aOrbiterF, 35U)) + aOrbiterA) + aPhaseDWandererUpdateSaltC[((aIndex + 14U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 35U) + RotL64(aOrbiterD, 19U)) + aOrbiterF) + RotL64(aCarry, 5U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterD, 5U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 5U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 40U));
            aCarry = aCarry + (RotL64(aWandererF, 21U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererG, 27U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 8623U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneC[((aIndex + 8033U)) & S_BLOCK1], 47U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 6917U)) & S_BLOCK1], 30U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 8615U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 5784U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 6778U)) & S_BLOCK1], 46U));
            aCross ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 6104U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aPrevious, 54U)) ^ (RotL64(aIngress, 5U) + RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterG = (((aWandererF + RotL64(aPrevious, 57U)) + 5088525177670191619U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordI;
            aOrbiterK = (((aWandererK + RotL64(aCross, 42U)) + 9966456257813932112U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordO;
            aOrbiterJ = (((aWandererB + RotL64(aScatter, 5U)) + RotL64(aCarry, 23U)) + 7707646574027146307U) + aNonceWordA;
            aOrbiterF = ((aWandererH + RotL64(aIngress, 29U)) + RotL64(aCarry, 51U)) + 75480203757681173U;
            aOrbiterA = (((aWandererC + RotL64(aCross, 23U)) + RotL64(aCarry, 35U)) + 384659134071835163U) + aNonceWordF;
            aOrbiterD = (aWandererA + RotL64(aScatter, 51U)) + 3158769775373307778U;
            aOrbiterB = (aWandererE + RotL64(aPrevious, 13U)) + 17360830943513941272U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 5317278822721604586U) + aNonceWordD;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 1371427105215954781U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10956603063464438611U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 3162710551223553423U) + aNonceWordL;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 5332921933853550756U;
            aOrbiterA = RotL64((aOrbiterA * 11709546145149357887U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 10572462410297815854U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 10234389605554817892U;
            aOrbiterF = RotL64((aOrbiterF * 2130374833440291193U), 5U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterD) + 13421365517991380605U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordG;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 10186643614984034083U;
            aOrbiterK = RotL64((aOrbiterK * 8554471709467808453U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 4742438973260817120U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 6081590345899008846U;
            aOrbiterG = RotL64((aOrbiterG * 7069396301823124931U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 15360092808493795340U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 12186413069553132646U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3815981440611914267U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 16756221656224451552U) + aNonceWordC;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 12232880965861373143U;
            aOrbiterD = RotL64((aOrbiterD * 14196910735715726471U), 35U);
            //
            aIngress = RotL64(aOrbiterD, 13U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterF, 37U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterB, 21U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterA, 44U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aIngress, 48U) + aOrbiterF) + RotL64(aOrbiterD, 21U)) + aNonceWordM);
            aWandererK = aWandererK + (((RotL64(aScatter, 57U) + aOrbiterD) + RotL64(aOrbiterB, 53U)) + RotL64(aCarry, 13U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 41U) + aOrbiterK) + RotL64(aOrbiterF, 39U));
            aWandererB = aWandererB + ((((RotL64(aCross, 35U) + aOrbiterD) + RotL64(aOrbiterG, 47U)) + RotL64(aCarry, 27U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterA, 12U)) + aOrbiterB) + aNonceWordK) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 3U) + RotL64(aOrbiterD, 5U)) + aOrbiterJ);
            aWandererC = aWandererC ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterF, 27U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 28U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + (RotL64(aWandererF, 23U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererB, 53U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 12400U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneA[((aIndex + 12623U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 12110U)) & S_BLOCK1], 4U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 12295U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneC[((aIndex + 15832U)) & S_BLOCK1], 34U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 54U) + RotL64(aCarry, 3U)) ^ (RotL64(aCross, 35U) ^ RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterD = ((aWandererA + RotL64(aIngress, 23U)) + 18144572925667544139U) + aNonceWordJ;
            aOrbiterB = (aWandererH + RotL64(aPrevious, 37U)) + 5659758077574059728U;
            aOrbiterF = ((aWandererE + RotL64(aScatter, 44U)) + RotL64(aCarry, 37U)) + 6343330616999166392U;
            aOrbiterH = (((aWandererD + RotL64(aCross, 5U)) + RotL64(aCarry, 23U)) + 17754639838410839447U) + aNonceWordF;
            aOrbiterI = ((((aWandererJ + RotL64(aIngress, 13U)) + RotL64(aCarry, 5U)) + 9451843819849581729U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordP;
            aOrbiterE = (aWandererK + RotL64(aCross, 53U)) + 7957854457197462212U;
            aOrbiterG = (((aWandererI + RotL64(aPrevious, 29U)) + 1461994799722205010U) + aPhaseDOrbiterAssignSaltE[((aIndex + 7U)) & S_SALT1]) + aNonceWordD;
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 18002214276252170177U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 14689869073147027164U) ^ aNonceWordK;
            aOrbiterF = RotL64((aOrbiterF * 12242482963989582191U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 3978104368003440293U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 8512135845221335386U;
            aOrbiterI = RotL64((aOrbiterI * 10506667163729414667U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 1477533446382953439U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterE) ^ 2166717790929947990U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterD = RotL64((aOrbiterD * 6538884492418324461U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 8082437060686606995U) + aNonceWordE;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 4363687722464700362U;
            aOrbiterE = RotL64((aOrbiterE * 7199165810993478887U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 15782763348014924206U) + aNonceWordH;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 8572509150015960728U;
            aOrbiterB = RotL64((aOrbiterB * 3340528604891897779U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 12248271773316742521U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 9602078627638561949U;
            aOrbiterG = RotL64((aOrbiterG * 1860631869877427405U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 17244849374768558859U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 1030743048280579012U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10858949914285817051U), 43U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterI, 27U);
            aIngress = aIngress + (RotL64(aOrbiterG, 43U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterB, 35U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterH, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterH, 3U)) + aOrbiterE) + aNonceWordO);
            aWandererJ = aWandererJ + (((((RotL64(aIngress, 60U) + aOrbiterD) + RotL64(aOrbiterG, 35U)) + RotL64(aCarry, 43U)) + aNonceWordI) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterB, 11U)) + aOrbiterE) + aPhaseDWandererUpdateSaltE[((aIndex + 22U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 53U) + aOrbiterI) + RotL64(aOrbiterF, 43U)) + RotL64(aCarry, 3U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 23U) + aOrbiterB) + RotL64(aOrbiterH, 51U)) + aNonceWordB);
            aWandererK = aWandererK + ((RotL64(aCross, 35U) + aOrbiterG) + RotL64(aOrbiterI, 27U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterH, 58U)) + aOrbiterI) + aNonceWordG);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 41U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererK, 54U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 18473U)) & S_BLOCK1], 27U) ^ RotL64(aSnowLaneA[((aIndex + 20591U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 19275U)) & S_BLOCK1], 36U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 17791U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17284U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aIngress, 18U)) + (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterI = ((aWandererE + RotL64(aIngress, 29U)) + 2915859148137000694U) + aNonceWordK;
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 5U)) + RotL64(aCarry, 19U)) + 210680583721444425U;
            aOrbiterA = (((aWandererF + RotL64(aPrevious, 35U)) + RotL64(aCarry, 39U)) + 6668118118775650387U) + aNonceWordO;
            aOrbiterG = (aWandererI + RotL64(aCross, 21U)) + 15794200818099010989U;
            aOrbiterF = (((aWandererJ + RotL64(aIngress, 43U)) + RotL64(aCarry, 53U)) + 6565076707062828369U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 14U)) + 16323164497808856719U) + aNonceWordA;
            aOrbiterE = ((aWandererG + RotL64(aCross, 57U)) + 7965435318816716560U) + aPhaseDOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 7390281030573369017U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 2269738866911824875U;
            aOrbiterA = RotL64((aOrbiterA * 1198697877998135567U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 9664014216039993873U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterG) ^ 18284857398028357633U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterJ = RotL64((aOrbiterJ * 8402008251343393737U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 367667619795303009U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 7935945060956274197U) ^ aNonceWordM;
            aOrbiterC = RotL64((aOrbiterC * 5481786693511955209U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 16683666162337789540U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 10655658270998102390U;
            aOrbiterI = RotL64((aOrbiterI * 15231596813382239841U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 8307037916581540297U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 3247742749860703524U) ^ aNonceWordI;
            aOrbiterF = RotL64((aOrbiterF * 15052136713218656641U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 10446792483683818139U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 16374602929344972364U;
            aOrbiterG = RotL64((aOrbiterG * 12599903932725787599U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 2411334498322777183U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 1093701164116833765U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13129220206835381729U), 19U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterA, 53U);
            aIngress = aIngress + (RotL64(aOrbiterG, 35U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 5U));
            aIngress = aIngress + RotL64(aOrbiterJ, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aScatter, 53U) + RotL64(aOrbiterF, 47U)) + aOrbiterJ) + aNonceWordD);
            aWandererF = aWandererF ^ (((RotL64(aCross, 47U) + aOrbiterG) + RotL64(aOrbiterE, 5U)) + aNonceWordF);
            aWandererI = aWandererI + (((RotL64(aIngress, 5U) + RotL64(aOrbiterI, 54U)) + aOrbiterA) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 60U) + aOrbiterC) + RotL64(aOrbiterA, 13U));
            aWandererJ = aWandererJ + (((((RotL64(aScatter, 35U) + aOrbiterC) + RotL64(aOrbiterE, 19U)) + RotL64(aCarry, 51U)) + aNonceWordE) + aPhaseDWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterC, 27U)) + aOrbiterF) + aNonceWordB);
            aWandererG = aWandererG + (((RotL64(aPrevious, 13U) + aOrbiterA) + RotL64(aOrbiterF, 35U)) + RotL64(aCarry, 13U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 4U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 43U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 21U));
            aCarry = aCarry + RotL64(aWandererG, 47U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 22455U)) & S_BLOCK1], 53U) ^ RotL64(aSnowLaneB[((aIndex + 23851U)) & S_BLOCK1], 14U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 26264U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 26973U)) & S_BLOCK1], 35U) ^ RotL64(aSnowLaneA[((aIndex + 22857U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCarry, 41U) + RotL64(aIngress, 53U)) ^ (RotL64(aCross, 28U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterE = ((aWandererG + RotL64(aIngress, 43U)) + 9107326720193244489U) + aNonceWordN;
            aOrbiterF = (((aWandererE + RotL64(aPrevious, 35U)) + RotL64(aCarry, 37U)) + 10868585484401664145U) + aNonceWordL;
            aOrbiterI = (((aWandererH + RotL64(aCross, 29U)) + 13637736741437846622U) + aPhaseDOrbiterAssignSaltA[((aIndex + 22U)) & S_SALT1]) + aNonceWordE;
            aOrbiterG = ((aWandererC + RotL64(aScatter, 5U)) + RotL64(aCarry, 57U)) + 6130725216183918844U;
            aOrbiterD = (((aWandererD + RotL64(aCross, 22U)) + RotL64(aCarry, 5U)) + 2063834478521338187U) + aNonceWordK;
            aOrbiterC = (aWandererK + RotL64(aIngress, 11U)) + 8564870627911949158U;
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 53U)) + 6524015751064086390U) + aPhaseDOrbiterAssignSaltC[((aIndex + 16U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 9874937766875388236U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 14723718409522680894U;
            aOrbiterI = RotL64((aOrbiterI * 17379140128833323431U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 13767059954741528279U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 6387608251033722169U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6601902195707980693U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 5391425980008431000U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 11524218415655093779U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12508457981779189389U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 155510463350385905U) + aNonceWordJ;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 10554591788433641311U;
            aOrbiterG = RotL64((aOrbiterG * 5412084824127934293U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 8662160162966241542U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 5092555636369853727U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 433807340167635499U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 7163345798448796101U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 695089002178413267U;
            aOrbiterE = RotL64((aOrbiterE * 17302689458565434475U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 5409173939213468972U) + aNonceWordB;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 15349690077393827541U;
            aOrbiterB = RotL64((aOrbiterB * 10984681254001609841U), 51U);
            //
            aIngress = RotL64(aOrbiterD, 35U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterF, 27U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + RotL64(aOrbiterG, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aScatter, 5U) + aOrbiterE) + RotL64(aOrbiterI, 11U)) + RotL64(aCarry, 27U)) + aNonceWordP);
            aWandererH = aWandererH ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterF, 3U)) + aOrbiterG) + aNonceWordH);
            aWandererG = aWandererG + ((RotL64(aIngress, 12U) + aOrbiterC) + RotL64(aOrbiterD, 43U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterF, 29U)) + aOrbiterB) + aNonceWordA);
            aWandererD = aWandererD + (((RotL64(aScatter, 57U) + RotL64(aOrbiterF, 19U)) + aOrbiterE) + aPhaseDWandererUpdateSaltB[((aIndex + 20U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterI, 36U)) + aOrbiterD) + aNonceWordO);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 41U) + aOrbiterG) + RotL64(aOrbiterC, 51U)) + RotL64(aCarry, 43U)) + aPhaseDWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 24U) ^ aWandererK);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererG, 43U);
            aCarry = aCarry + RotL64(aIngress, 34U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 27874U)) & S_BLOCK1], 13U) ^ RotL64(aInvestLaneA[((aIndex + 31476U)) & S_BLOCK1], 4U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 29844U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 32041U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneB[((aIndex + 29591U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aPrevious, 60U) ^ RotL64(aCarry, 23U)) ^ (RotL64(aIngress, 11U) + RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterH = (aWandererH + RotL64(aScatter, 11U)) + 17711946802293254150U;
            aOrbiterB = (((aWandererI + RotL64(aIngress, 21U)) + RotL64(aCarry, 53U)) + 16652362590489569378U) + aNonceWordM;
            aOrbiterG = (((aWandererG + RotL64(aPrevious, 5U)) + RotL64(aCarry, 21U)) + 6972810344198183097U) + aNonceWordE;
            aOrbiterI = ((((aWandererJ + RotL64(aCross, 38U)) + RotL64(aCarry, 5U)) + 13117100889782940546U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordO;
            aOrbiterC = ((aWandererE + RotL64(aScatter, 57U)) + 13199305696782626591U) + aPhaseDOrbiterAssignSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterD = (aWandererF + RotL64(aCross, 27U)) + 992156184392760945U;
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 47U)) + 13791265442074543880U) + aNonceWordH;
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 17057087245252294859U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterH) ^ 13444195995883541046U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterG = RotL64((aOrbiterG * 13067044288608808777U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 6723678233676059420U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 7913379431208430475U;
            aOrbiterC = RotL64((aOrbiterC * 2295062944289127123U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 4481887195529300665U) + aNonceWordK;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 11892724101424384078U;
            aOrbiterI = RotL64((aOrbiterI * 3468639499716604111U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 7700902083270424194U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 1888001433557140271U;
            aOrbiterF = RotL64((aOrbiterF * 8975562955027025349U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 14996753906788986929U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 939004845422123765U;
            aOrbiterH = RotL64((aOrbiterH * 2507090308972292313U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 11922230289291941807U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 15681187459741147199U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10124947739653819101U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 9119043713532718155U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 8327697433992362166U;
            aOrbiterD = RotL64((aOrbiterD * 11157657162184304567U), 35U);
            //
            aIngress = RotL64(aOrbiterF, 29U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterC, 11U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterD, 60U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterI, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aScatter, 50U) + RotL64(aOrbiterB, 12U)) + aOrbiterC);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterC, 51U)) + aOrbiterD);
            aWandererI = aWandererI + ((((RotL64(aCross, 13U) + aOrbiterH) + RotL64(aOrbiterB, 5U)) + RotL64(aCarry, 47U)) + aNonceWordD);
            aWandererG = aWandererG ^ ((((RotL64(aPrevious, 23U) + RotL64(aOrbiterB, 57U)) + aOrbiterI) + aNonceWordN) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 35U) + aOrbiterG) + RotL64(aOrbiterD, 19U)) + aNonceWordA);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 29U) + aOrbiterI) + RotL64(aOrbiterF, 43U));
            aWandererE = aWandererE + ((((RotL64(aPrevious, 41U) + aOrbiterB) + RotL64(aOrbiterF, 37U)) + RotL64(aCarry, 35U)) + aPhaseDWandererUpdateSaltE[((aIndex + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 24U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 19U));
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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

void TwistExpander_BasketBall_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xB2F4D90DD15A93D5ULL + 0xB7EFF62E788AD0B5ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xECCA972957C0B9B1ULL + 0xA575AC5C0A76F4B4ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x8CF9C9CD6F9EF655ULL + 0xA60BF4C01B4237B4ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xD815AD208135DE31ULL + 0x85A123599C4FE37EULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xB56E53AD6FC1AE3BULL + 0x9D1D78CF0B4539BDULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x96D2609D55F0BC3FULL + 0x8523F62F81B1A076ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xAF045876C31513EBULL + 0xF67AA34581135351ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x9ED85B0E8E159861ULL + 0x84BF788FC1289E12ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xB5044F49BCD9D71DULL + 0xC699F56F2A281353ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x93658C320B15C56DULL + 0xD4F66A18944F5BCFULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xE5A3FCE7327145C1ULL + 0xA9E5846E2BBEE448ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xAA607CEEF0927401ULL + 0x8A507B27C703CE22ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xE38EFC0641D0173BULL + 0xEE7EB15F5B951354ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xA0F130FE00F2339FULL + 0xDC275DFFD5D62B37ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xA80B01276AC6E193ULL + 0xD065E5955701C28DULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xCE73F1E3CD56CB09ULL + 0xC240B319090B1264ULL);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 776U)) & S_BLOCK1], 27U) ^ RotL64(aInvestLaneB[((aIndex + 3827U)) & S_BLOCK1], 38U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 1710U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 4485U)) & S_BLOCK1], 21U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 3723U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 598U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 51U) + RotL64(aPrevious, 34U)) ^ (RotL64(aIngress, 3U) + RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterA = (aWandererJ + RotL64(aCross, 27U)) + 4259993311776766595U;
            aOrbiterG = ((aWandererA + RotL64(aScatter, 24U)) + 2857813330021126753U) + aNonceWordB;
            aOrbiterJ = (aWandererI + RotL64(aIngress, 47U)) + 1345396841329442896U;
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 19U)) + 320992148982301024U) + aNonceWordO;
            aOrbiterD = (((aWandererB + RotL64(aScatter, 57U)) + 5619109532065293074U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordK;
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 39U)) + RotL64(aCarry, 53U)) + 10380157329426706345U;
            aOrbiterK = ((aWandererG + RotL64(aCross, 52U)) + RotL64(aCarry, 29U)) + 12449831150625409695U;
            aOrbiterH = ((aWandererC + RotL64(aIngress, 29U)) + RotL64(aCarry, 57U)) + 7847096607042268396U;
            aOrbiterB = (aWandererK + RotL64(aCross, 41U)) + 11707184096803214678U;
            aOrbiterI = (aWandererE + RotL64(aPrevious, 5U)) + 9893643746186827088U;
            aOrbiterE = ((aWandererH + RotL64(aScatter, 13U)) + 333687403830908774U) + aPhaseEOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 13837360705077441580U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 4367119682175710689U;
            aOrbiterJ = RotL64((aOrbiterJ * 10295744669174603401U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 1193493435041306784U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 15062951612027370606U) ^ aNonceWordE;
            aOrbiterA = RotL64((aOrbiterA * 2509383510565136549U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 16000173839235429105U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 15294482444605409961U;
            aOrbiterH = RotL64((aOrbiterH * 1031800997944302665U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 5720749055549773527U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = (((aOrbiterI ^ aOrbiterH) ^ 17248674962996093668U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterI = RotL64((aOrbiterI * 15730637462755795591U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 16956840483882091059U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 9637715107943515594U;
            aOrbiterD = RotL64((aOrbiterD * 8878362378343603463U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 7147495779349862274U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 7508890985889484275U;
            aOrbiterC = RotL64((aOrbiterC * 17728368447504622035U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 4407738164617959366U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 17027017782352660454U) ^ aNonceWordA;
            aOrbiterE = RotL64((aOrbiterE * 417183060881259295U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 3174658601748235285U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 9779053567370714831U;
            aOrbiterG = RotL64((aOrbiterG * 6383245776181968033U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 16256981360027888091U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 12778335633397105924U;
            aOrbiterB = RotL64((aOrbiterB * 10821225965811763659U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 13985909343937844583U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 14307218309393008729U) ^ aNonceWordI;
            aOrbiterK = RotL64((aOrbiterK * 12053366452617039877U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 15549857305890093491U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 4259993311776766595U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13703695714360435719U), 3U);
            //
            aIngress = RotL64(aOrbiterK, 48U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 21U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 19U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 53U));
            aIngress = aIngress + RotL64(aOrbiterB, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 42U) + RotL64(aOrbiterC, 29U)) + aOrbiterI);
            aWandererF = aWandererF + (((RotL64(aIngress, 19U) + aOrbiterH) + RotL64(aOrbiterC, 26U)) + aPhaseEWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterA, 53U)) + aOrbiterE);
            aWandererE = aWandererE + ((((RotL64(aCross, 11U) + RotL64(aOrbiterD, 43U)) + aOrbiterB) + RotL64(aCarry, 37U)) + aNonceWordD);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 37U) + aOrbiterB) + RotL64(aOrbiterE, 11U));
            aWandererB = aWandererB + ((((RotL64(aIngress, 47U) + aOrbiterD) + RotL64(aOrbiterK, 5U)) + RotL64(aCarry, 29U)) + aNonceWordP);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 21U) + aOrbiterE) + RotL64(aOrbiterF, 51U)) + aNonceWordN);
            aWandererD = aWandererD + ((RotL64(aPrevious, 29U) + aOrbiterC) + RotL64(aOrbiterJ, 38U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterK, 35U)) + aOrbiterG) + aNonceWordC);
            aWandererG = aWandererG + ((RotL64(aCross, 60U) + RotL64(aOrbiterC, 3U)) + aOrbiterG);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 39U) + aOrbiterK) + RotL64(aOrbiterB, 19U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + (RotL64(aWandererF, 24U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererB, 37U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererJ, 51U);
            aCarry = aCarry + RotL64(aIngress, 44U);
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
            aIngress = (RotL64(aFireLaneA[((aIndex + 10430U)) & S_BLOCK1], 11U) ^ RotL64(aInvestLaneC[((aIndex + 10832U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aInvestLaneD[((aIndex + 8914U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 9332U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 7828U)) & S_BLOCK1], 13U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 7908U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 6137U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aPrevious, 44U) ^ RotL64(aCross, 19U)) ^ (RotL64(aIngress, 5U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterK = (aWandererH + RotL64(aScatter, 24U)) + 12535417189990029950U;
            aOrbiterG = (aWandererK + RotL64(aCross, 11U)) + 6204401443676390273U;
            aOrbiterH = (aWandererG + RotL64(aPrevious, 35U)) + 869613505613154672U;
            aOrbiterJ = (aWandererF + RotL64(aIngress, 21U)) + 15053590879563855802U;
            aOrbiterA = (aWandererD + RotL64(aPrevious, 41U)) + 13338989605204591428U;
            aOrbiterE = ((aWandererA + RotL64(aIngress, 39U)) + RotL64(aCarry, 47U)) + 18306470022403825392U;
            aOrbiterD = (aWandererB + RotL64(aCross, 19U)) + 1150696349434090218U;
            aOrbiterB = (((aWandererJ + RotL64(aScatter, 57U)) + 13549541786420596437U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordM;
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 53U)) + RotL64(aCarry, 19U)) + 14302878430259588461U;
            aOrbiterI = (((aWandererC + RotL64(aScatter, 26U)) + RotL64(aCarry, 27U)) + 4660437084477165225U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = ((aWandererE + RotL64(aCross, 51U)) + 1653628537860912069U) + aNonceWordD;
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 5594199757006711631U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 11008472193138708891U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13645764762027798301U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 3668516817279364310U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 128159531749679984U) ^ aNonceWordC;
            aOrbiterE = RotL64((aOrbiterE * 4523246859249826987U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 6378674346113979108U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 11438762460659123362U;
            aOrbiterB = RotL64((aOrbiterB * 2733309638158283953U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 10624263004446482910U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 12546839706919241411U;
            aOrbiterD = RotL64((aOrbiterD * 11468326687628079347U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 8466639576503293921U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 5828694979857951504U;
            aOrbiterJ = RotL64((aOrbiterJ * 7835487310289634515U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 16496305151014092976U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 589464613876410567U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13190816610718051897U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 4168532743415647825U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 15944887793736489375U) ^ aNonceWordP;
            aOrbiterG = RotL64((aOrbiterG * 17273403561158196717U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 11642456814106259483U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 1609897693632334867U;
            aOrbiterI = RotL64((aOrbiterI * 12912773555616819941U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 14950238412766325479U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 11862438528287402255U;
            aOrbiterK = RotL64((aOrbiterK * 7635864312080265695U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 5900629306795222263U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 3221591991392500536U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7188525011266868855U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 16938699391746264010U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 12535417189990029950U;
            aOrbiterA = RotL64((aOrbiterA * 18212319484142613215U), 37U);
            //
            aIngress = RotL64(aOrbiterB, 11U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 13U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 39U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 37U));
            aIngress = aIngress + (RotL64(aOrbiterH, 27U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 10U) + RotL64(aOrbiterA, 3U)) + aOrbiterD);
            aWandererG = aWandererG + (((RotL64(aCross, 23U) + aOrbiterB) + RotL64(aOrbiterK, 27U)) + aNonceWordJ);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 39U) + aOrbiterD) + RotL64(aOrbiterG, 21U));
            aWandererC = aWandererC + ((RotL64(aScatter, 29U) + RotL64(aOrbiterC, 19U)) + aOrbiterJ);
            aWandererK = aWandererK ^ ((RotL64(aCross, 19U) + aOrbiterI) + RotL64(aOrbiterA, 23U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterI, 46U)) + aOrbiterE) + RotL64(aCarry, 19U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterI, 29U)) + aOrbiterK) + aNonceWordO);
            aWandererH = aWandererH + (((((RotL64(aIngress, 43U) + RotL64(aOrbiterD, 41U)) + aOrbiterC) + RotL64(aCarry, 53U)) + aNonceWordG) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 6U) + aOrbiterJ) + RotL64(aOrbiterF, 35U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aIngress, 53U) + RotL64(aOrbiterJ, 60U)) + aOrbiterH);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 13U) + aOrbiterB) + RotL64(aOrbiterI, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 48U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 23U) ^ aWandererK);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 21U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + RotL64(aWandererB, 35U);
            aCarry = aCarry + RotL64(aIngress, 14U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 13778U)) & S_BLOCK1], 60U) ^ RotL64(aInvestLaneA[((aIndex + 13742U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 12197U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 12447U)) & S_BLOCK1], 42U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 12967U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aPrevious, 13U) ^ RotL64(aCross, 39U)) + (RotL64(aCarry, 60U) ^ RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterF = (aWandererG + RotL64(aPrevious, 39U)) + 966899917801652720U;
            aOrbiterJ = (aWandererA + RotL64(aIngress, 60U)) + 10996327672320748649U;
            aOrbiterI = (((aWandererJ + RotL64(aScatter, 3U)) + RotL64(aCarry, 5U)) + 4188171566846621107U) + aPhaseEOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = (aWandererH + RotL64(aCross, 43U)) + 5886209243097387959U;
            aOrbiterB = (aWandererB + RotL64(aPrevious, 19U)) + 14940428957136728111U;
            aOrbiterA = ((aWandererD + RotL64(aIngress, 37U)) + 179187285531914832U) + aNonceWordA;
            aOrbiterG = (((aWandererF + RotL64(aCross, 5U)) + RotL64(aCarry, 37U)) + 6685351948936817752U) + aNonceWordP;
            aOrbiterK = ((aWandererI + RotL64(aScatter, 53U)) + 1894506461704029700U) + aPhaseEOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 30U)) + RotL64(aCarry, 47U)) + 4182760368636977082U;
            aOrbiterE = ((aWandererC + RotL64(aCross, 27U)) + 12523318028514940790U) + aNonceWordE;
            aOrbiterD = (aWandererE + RotL64(aScatter, 35U)) + 5059306166973366892U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 5890872367917643851U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 17747338389865221534U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5306740664798049267U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 13906227834259884100U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 7152105382899756368U;
            aOrbiterB = RotL64((aOrbiterB * 6772157117358310485U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 17868101884759619240U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 11758843266314148347U;
            aOrbiterF = RotL64((aOrbiterF * 5919135169337501485U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 13950566197090324859U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 17278105609930477854U;
            aOrbiterG = RotL64((aOrbiterG * 11431842718945107359U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 9556785965646738355U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 841298436857932987U;
            aOrbiterJ = RotL64((aOrbiterJ * 15077843186688841797U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 1951515285492133830U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 15775839819330588437U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7902654031401620995U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 5585458468816495436U) + aNonceWordG;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 17258586689032223623U;
            aOrbiterA = RotL64((aOrbiterA * 1652050227399194271U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 5254132659445988836U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 15440741734777060925U;
            aOrbiterC = RotL64((aOrbiterC * 17445581079035134067U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 16770361602586485631U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 14902616717976301965U) ^ aNonceWordH;
            aOrbiterH = RotL64((aOrbiterH * 7757713071544143453U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 9521517757370835715U) + aNonceWordM;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 18241677917767801049U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16977396965907931057U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 14307634663160859644U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 966899917801652720U;
            aOrbiterK = RotL64((aOrbiterK * 17012361848398765251U), 29U);
            //
            aIngress = RotL64(aOrbiterH, 6U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + (RotL64(aOrbiterB, 19U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterG, 35U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterD, 41U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterE, 10U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aCross, 57U) + RotL64(aOrbiterA, 29U)) + aOrbiterD) + aPhaseEWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterK, 48U)) + aOrbiterG) + aNonceWordD);
            aWandererE = aWandererE + ((RotL64(aScatter, 26U) + aOrbiterD) + RotL64(aOrbiterF, 21U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterA, 43U)) + aOrbiterE) + aNonceWordI);
            aWandererA = aWandererA + (((RotL64(aCross, 37U) + RotL64(aOrbiterK, 5U)) + aOrbiterB) + RotL64(aCarry, 29U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterJ, 41U)) + aOrbiterG);
            aWandererF = aWandererF + ((((RotL64(aScatter, 53U) + aOrbiterI) + RotL64(aOrbiterC, 3U)) + RotL64(aCarry, 47U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterE, 58U)) + aOrbiterG) + aNonceWordC);
            aWandererG = aWandererG + ((RotL64(aCross, 11U) + RotL64(aOrbiterB, 11U)) + aOrbiterH);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 47U) + aOrbiterI) + RotL64(aOrbiterH, 23U)) + aNonceWordF);
            aWandererI = aWandererI + ((RotL64(aScatter, 20U) + aOrbiterC) + RotL64(aOrbiterF, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererK);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 34U));
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + RotL64(aWandererA, 6U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 17409U)) & S_BLOCK1], 44U) ^ RotL64(aFireLaneA[((aIndex + 17124U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 19992U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 21690U)) & S_BLOCK1], 28U) ^ RotL64(aInvestLaneD[((aIndex + 16766U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aIngress, 51U) + RotL64(aCross, 37U)) ^ (RotL64(aCarry, 24U) ^ RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterI = (aWandererF + RotL64(aIngress, 21U)) + 11450949896247900941U;
            aOrbiterG = ((aWandererA + RotL64(aCross, 51U)) + 3905542253538116335U) + aNonceWordE;
            aOrbiterC = (aWandererC + RotL64(aScatter, 18U)) + 9529740545977785305U;
            aOrbiterF = (aWandererK + RotL64(aPrevious, 41U)) + 1856876631533143492U;
            aOrbiterK = ((aWandererH + RotL64(aCross, 23U)) + 84253466320181686U) + aPhaseEOrbiterAssignSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = ((aWandererE + RotL64(aScatter, 37U)) + 12577480918745432444U) + aPhaseEOrbiterAssignSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterB = (aWandererB + RotL64(aIngress, 11U)) + 5625703170397704029U;
            aOrbiterE = (((aWandererI + RotL64(aPrevious, 39U)) + RotL64(aCarry, 11U)) + 694608607323629282U) + aNonceWordK;
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 13U)) + RotL64(aCarry, 27U)) + 3993981243536262204U;
            aOrbiterD = ((aWandererG + RotL64(aIngress, 3U)) + RotL64(aCarry, 23U)) + 4119215953484892051U;
            aOrbiterA = (aWandererD + RotL64(aCross, 54U)) + 8785040118556157146U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 16234403619456882890U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 10398727475672860610U;
            aOrbiterC = RotL64((aOrbiterC * 5086871400049644715U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 18327987141759096769U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 2645964788056875452U;
            aOrbiterH = RotL64((aOrbiterH * 8778681366114628045U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 2859452497983106129U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 7196557924940881076U;
            aOrbiterF = RotL64((aOrbiterF * 14415389907490256711U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 930127943984174668U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 15673596916054795749U;
            aOrbiterK = RotL64((aOrbiterK * 7505660488733199479U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 16673140529110941163U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 2258448294877833760U;
            aOrbiterI = RotL64((aOrbiterI * 1821550319748977445U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 6870209259643931219U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 12749790107942194104U;
            aOrbiterB = RotL64((aOrbiterB * 4871407285968611725U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 17131374134617173866U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 6426448390733751612U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12490559588384058417U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 15592826434339731146U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 14182944418026376183U) ^ aNonceWordF;
            aOrbiterE = RotL64((aOrbiterE * 7218860482893476233U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 17447476498234456596U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 972861017466618022U;
            aOrbiterA = RotL64((aOrbiterA * 9610670431280153921U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 13185309156950240549U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 14442284480744008537U) ^ aNonceWordH;
            aOrbiterD = RotL64((aOrbiterD * 2907844852105175837U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 7816745313858811117U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 11450949896247900941U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 18317765298694454463U), 47U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterD, 10U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 39U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 19U));
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterC, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aCross, 48U) + aOrbiterK) + RotL64(aOrbiterI, 41U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 27U) + aOrbiterK) + RotL64(aOrbiterD, 35U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 23U) + aOrbiterE) + RotL64(aOrbiterD, 37U)) + RotL64(aCarry, 37U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 21U) + aOrbiterG) + RotL64(aOrbiterH, 53U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 13U) + aOrbiterC) + RotL64(aOrbiterJ, 20U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterC, 23U)) + aOrbiterA);
            aWandererG = aWandererG + ((((RotL64(aScatter, 39U) + RotL64(aOrbiterA, 43U)) + aOrbiterK) + RotL64(aCarry, 51U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 52U) + RotL64(aOrbiterB, 39U)) + aOrbiterC);
            aWandererB = aWandererB + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterG, 46U)) + aOrbiterK) + aNonceWordA);
            aWandererE = aWandererE ^ ((((RotL64(aIngress, 5U) + aOrbiterF) + RotL64(aOrbiterH, 3U)) + aNonceWordL) + aPhaseEWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 35U) + aOrbiterJ) + RotL64(aOrbiterE, 11U)) + aNonceWordG);
            //
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 54U) ^ aWandererB);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + RotL64(aWandererH, 3U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 26102U)) & S_BLOCK1], 39U) ^ RotL64(aFireLaneB[((aIndex + 22008U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 24822U)) & S_BLOCK1], 28U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 27188U)) & S_BLOCK1], 56U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 25956U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aInvestLaneA[((aIndex + 22581U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCross, 19U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCarry, 56U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 57U)) + 439898681482066326U) + aNonceWordG;
            aOrbiterE = ((aWandererE + RotL64(aScatter, 50U)) + 17362083676671776094U) + aNonceWordF;
            aOrbiterJ = (aWandererC + RotL64(aIngress, 41U)) + 6418499837265155024U;
            aOrbiterI = (aWandererI + RotL64(aCross, 19U)) + 17262244253027454972U;
            aOrbiterC = (aWandererK + RotL64(aScatter, 37U)) + 2382066162993139503U;
            aOrbiterB = (((aWandererH + RotL64(aCross, 5U)) + RotL64(aCarry, 57U)) + 14345808395587174135U) + aNonceWordN;
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 13U)) + 7534743166385552851U;
            aOrbiterD = (aWandererG + RotL64(aIngress, 27U)) + 16994453324688523966U;
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 35U)) + RotL64(aCarry, 51U)) + 7079553728544045092U;
            aOrbiterH = (((aWandererF + RotL64(aScatter, 21U)) + RotL64(aCarry, 47U)) + 3562822704508440641U) + aPhaseEOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = (((aWandererD + RotL64(aIngress, 60U)) + 13990892681975857821U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordH;
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 1796728922368577238U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 6605161260520067178U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8147537646591674091U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 13994083795942328918U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 6144523182899107711U;
            aOrbiterB = RotL64((aOrbiterB * 4153879991344611283U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 12247462325297436642U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 1065809332002012789U;
            aOrbiterD = RotL64((aOrbiterD * 5496601177032953251U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 10147919864511540753U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 17138553441127273354U) ^ aNonceWordC;
            aOrbiterF = RotL64((aOrbiterF * 5773875596275267871U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 2653924016109573974U) + aNonceWordJ;
            aOrbiterC = (((aOrbiterC ^ aOrbiterF) ^ 6254416952351699582U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterC = RotL64((aOrbiterC * 12756861659704947257U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 813046408080197079U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 9624466135414123483U;
            aOrbiterH = RotL64((aOrbiterH * 6960320253124395015U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 972586705850825744U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterD) ^ 155283774901960223U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterI = RotL64((aOrbiterI * 9928051687724257041U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 18200100644751360406U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 1168426822045686004U;
            aOrbiterK = RotL64((aOrbiterK * 5867027156069481313U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 2271564377169233643U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 1896317305868283986U;
            aOrbiterA = RotL64((aOrbiterA * 8080751157990019287U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 10209708407397294552U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 947585551223387294U;
            aOrbiterG = RotL64((aOrbiterG * 15339472308062247067U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 12313594490465462211U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 439898681482066326U;
            aOrbiterE = RotL64((aOrbiterE * 12336632799055203705U), 35U);
            //
            aIngress = RotL64(aOrbiterI, 13U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 41U));
            aIngress = aIngress + (RotL64(aOrbiterK, 43U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterH, 24U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterA, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aIngress, 29U) + aOrbiterK) + RotL64(aOrbiterC, 47U)) + aNonceWordD);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterD, 11U)) + aOrbiterG);
            aWandererH = aWandererH + ((RotL64(aCross, 54U) + RotL64(aOrbiterJ, 26U)) + aOrbiterB);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 35U) + aOrbiterA) + RotL64(aOrbiterJ, 19U)) + aNonceWordI);
            aWandererA = aWandererA + ((RotL64(aCross, 13U) + aOrbiterB) + RotL64(aOrbiterK, 43U));
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 37U) + aOrbiterF) + RotL64(aOrbiterD, 21U)) + aNonceWordE) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aScatter, 23U) + aOrbiterI) + RotL64(aOrbiterH, 57U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 6U) + RotL64(aOrbiterC, 5U)) + aOrbiterE);
            aWandererD = aWandererD + (((RotL64(aCross, 39U) + RotL64(aOrbiterI, 36U)) + aOrbiterD) + RotL64(aCarry, 41U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterE, 3U)) + aOrbiterG) + aPhaseEWandererUpdateSaltF[((aIndex + 10U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 21U) + aOrbiterF) + RotL64(aOrbiterH, 51U)) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 46U));
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererK);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererJ, 36U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 28889U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneA[((aIndex + 29894U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 32548U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30220U)) & S_BLOCK1], 43U) ^ RotL64(aInvestLaneB[((aIndex + 28925U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCarry, 51U)) + (RotL64(aCross, 20U) ^ RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 34U)) + 13333509828310369865U) + aPhaseEOrbiterAssignSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = (aWandererC + RotL64(aPrevious, 37U)) + 7645352517103840797U;
            aOrbiterA = ((aWandererD + RotL64(aCross, 41U)) + 5310766306660062655U) + aNonceWordM;
            aOrbiterI = ((aWandererG + RotL64(aScatter, 47U)) + RotL64(aCarry, 19U)) + 5165635069832352932U;
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 29U)) + RotL64(aCarry, 41U)) + 15684141764734281849U;
            aOrbiterE = (aWandererH + RotL64(aIngress, 19U)) + 3327963374225061738U;
            aOrbiterG = ((aWandererA + RotL64(aScatter, 5U)) + 8625811794878848871U) + aNonceWordE;
            aOrbiterB = ((aWandererI + RotL64(aCross, 44U)) + 7598657468430485291U) + aPhaseEOrbiterAssignSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = (aWandererE + RotL64(aScatter, 3U)) + 2881171216276746485U;
            aOrbiterC = ((aWandererB + RotL64(aCross, 57U)) + RotL64(aCarry, 5U)) + 10237691227222918101U;
            aOrbiterF = (aWandererK + RotL64(aIngress, 23U)) + 6419254255884834497U;
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterH) + 4238455444646479956U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 14936613353493061492U) ^ aNonceWordB;
            aOrbiterA = RotL64((aOrbiterA * 3544216916806292273U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 15324699725208372627U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 9506640480601832011U;
            aOrbiterD = RotL64((aOrbiterD * 12819564111348390227U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 3709149613660215641U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 1724290199312754307U;
            aOrbiterH = RotL64((aOrbiterH * 12597580418257897965U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 13191172833570139194U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 3686087945377837886U;
            aOrbiterK = RotL64((aOrbiterK * 10883609557429936283U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 10418330386245397022U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 5383531313632347245U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2987755379396160073U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 7414716553072652212U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterH) ^ 11301761123966206201U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterB = RotL64((aOrbiterB * 1546727321088592187U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 8570229732236388847U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 8773754460060264773U;
            aOrbiterG = RotL64((aOrbiterG * 3251360788932563495U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 13636929800504199371U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 5486599841558573720U;
            aOrbiterJ = RotL64((aOrbiterJ * 2867914211589815153U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 13277541451512422776U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 10409779509190185921U;
            aOrbiterF = RotL64((aOrbiterF * 1926650154570961573U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 7268295836403414306U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 13815969853235433830U;
            aOrbiterC = RotL64((aOrbiterC * 11603750346752441535U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 9353249174240162324U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 13333509828310369865U;
            aOrbiterE = RotL64((aOrbiterE * 10381405217943841655U), 37U);
            //
            aIngress = RotL64(aOrbiterJ, 6U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterA, 39U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 37U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + RotL64(aOrbiterG, 14U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aCross, 41U) + RotL64(aOrbiterG, 48U)) + aOrbiterD) + RotL64(aCarry, 47U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 52U) + RotL64(aOrbiterG, 5U)) + aOrbiterJ) + aNonceWordG);
            aWandererF = aWandererF + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterF, 37U)) + aOrbiterK) + RotL64(aCarry, 11U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 39U) + RotL64(aOrbiterG, 11U)) + aOrbiterA) + aNonceWordK);
            aWandererA = aWandererA + ((((RotL64(aCross, 23U) + aOrbiterJ) + RotL64(aOrbiterF, 29U)) + aNonceWordH) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterD, 3U)) + aOrbiterH);
            aWandererG = aWandererG + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterB, 35U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 18U) + RotL64(aOrbiterC, 13U)) + aOrbiterH);
            aWandererC = aWandererC + ((RotL64(aCross, 43U) + aOrbiterI) + RotL64(aOrbiterF, 54U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 57U) + aOrbiterE) + RotL64(aOrbiterF, 57U));
            aWandererK = aWandererK + ((RotL64(aScatter, 29U) + aOrbiterI) + RotL64(aOrbiterA, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 38U) ^ aWandererI);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 19U));
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererF, 41U);
            aCarry = aCarry + RotL64(aIngress, 46U);
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

void TwistExpander_BasketBall_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x912A6CD6C092C18FULL + 0xC7092985C0C9C8C9ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xB7184A06E9C3AE35ULL + 0xBF0CBEC3FD76BB11ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xC406949DE5794433ULL + 0xF95FDF941A7491BAULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x8FDEEABDE5974101ULL + 0xD12CE2369ED2806DULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x8EE7688800DA72C3ULL + 0x9F5271F294E9D522ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xE7B2E816D7A3F1F3ULL + 0xB579EAD08BAF962EULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xA3985FE5DD01C7B5ULL + 0xC2290A52676D5A14ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xC6CA6C4E4F7621F5ULL + 0x81312AADAA21B2CFULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xCE265AAAF637FE43ULL + 0xDA30A231F8F3CDADULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x84FF830B1A32DC87ULL + 0x951A9B6A38EABE43ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xD97BE657F6A695EDULL + 0xC89F09A21F3EC42EULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xAD7BCFD348FDDDEBULL + 0xB6DE7823D6BE7484ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xBDEF9A3560571EFDULL + 0xD998BC66F69E52B4ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xE9765EC568B0501BULL + 0xDCF1BAC4EF696CD0ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xEAD2685709B31E39ULL + 0xC76A7D6961BB4EE7ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x92666B3CECB2FF95ULL + 0xA94DB722F623A0A2ULL);
    // GSeedRunSeed_F seed_loop_f (start)
    {
        // GSeedRunSeed_F seed_loop_f lane group
        // read from: aOperationLaneA, aOperationLaneB, aInvestLaneC, aOperationLaneC, aOperationLaneD, aSnowLaneB, aSnowLaneC, aWorkLaneC, aInvestLaneB, aSnowLaneD, aInvestLaneA, aExpandLaneA, aWorkLaneD, aExpandLaneB, aInvestLaneD, aExpandLaneC, aSnowLaneA
        // write to: aSnowLaneC, aSnowLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_f loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aInvestLaneC
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aInvestLaneC forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aSnowLaneB
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aSnowLaneB backward/forward random
        // write to: aSnowLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 2769U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneB[((aIndex + 4116U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 2096U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4606U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 2500U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 1185U)) & S_BLOCK1], 24U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aIngress, 54U) ^ RotL64(aCross, 5U)) + (RotL64(aPrevious, 37U) + RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 47U)) + RotL64(aCarry, 35U)) + 14499676118633326000U;
            aOrbiterA = (aWandererF + RotL64(aScatter, 35U)) + 17191273593018552288U;
            aOrbiterC = (aWandererD + RotL64(aIngress, 39U)) + 4085176294948097737U;
            aOrbiterI = ((aWandererA + RotL64(aCross, 4U)) + RotL64(aCarry, 13U)) + 11112671474158908186U;
            aOrbiterG = ((aWandererG + RotL64(aScatter, 27U)) + 8745787969012266485U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 57U)) + 18074049663777707948U;
            aOrbiterE = (aWandererB + RotL64(aCross, 11U)) + 2543758649719164688U;
            aOrbiterK = (((aWandererE + RotL64(aIngress, 51U)) + RotL64(aCarry, 53U)) + 4659584749412700523U) + aNonceWordA;
            aOrbiterD = (((aWandererH + RotL64(aPrevious, 22U)) + 974639159259871273U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordK;
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 9211220687971081987U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 8567024626862182714U;
            aOrbiterC = RotL64((aOrbiterC * 7755874089832496393U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 5803002132294840900U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 11968489432878148467U;
            aOrbiterA = RotL64((aOrbiterA * 4501441062617123165U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 9470807228394903442U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 1692347973120388469U;
            aOrbiterI = RotL64((aOrbiterI * 17433393164156231575U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 16510815732690193145U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 755159406833096510U;
            aOrbiterF = RotL64((aOrbiterF * 14091736464659561165U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 1518824876475937620U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 701225390867330446U;
            aOrbiterG = RotL64((aOrbiterG * 12264618860580199927U), 3U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterE) + 8425976693733003889U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1]) + aNonceWordO;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 7182176375442410367U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8860605703761731859U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 4546566785167467924U) + aNonceWordM;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 2593340999038753749U;
            aOrbiterH = RotL64((aOrbiterH * 10152461487764567563U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 9756331608356622299U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 5511625814747641978U;
            aOrbiterE = RotL64((aOrbiterE * 4806076157539829529U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 8694400787420160733U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 12648969491371382682U;
            aOrbiterK = RotL64((aOrbiterK * 5346585704222643759U), 41U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterI, 24U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterF, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aCross, 4U) + aOrbiterK) + RotL64(aOrbiterD, 24U)) + aNonceWordH);
            aWandererD = aWandererD + (((RotL64(aIngress, 27U) + aOrbiterA) + RotL64(aOrbiterI, 29U)) + aNonceWordD);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 47U) + aOrbiterC) + RotL64(aOrbiterG, 47U)) + aNonceWordL);
            aWandererI = aWandererI + ((RotL64(aScatter, 51U) + RotL64(aOrbiterK, 3U)) + aOrbiterA);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 37U) + aOrbiterK) + RotL64(aOrbiterC, 51U)) + aPhaseFWandererUpdateSaltB[((aIndex + 26U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 21U) + RotL64(aOrbiterI, 11U)) + aOrbiterH) + RotL64(aCarry, 35U)) + aPhaseFWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 11U) + aOrbiterI) + RotL64(aOrbiterF, 41U));
            aWandererF = aWandererF + (((RotL64(aScatter, 56U) + aOrbiterE) + RotL64(aOrbiterA, 56U)) + RotL64(aCarry, 27U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterI, 19U)) + aOrbiterE) + aNonceWordB);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 54U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererD, 47U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aSnowLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 2
        // ingress from: aSnowLaneC, aOperationLaneC, aOperationLaneD, aWorkLaneC
        // ingress directions: aSnowLaneC forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aWorkLaneC forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aInvestLaneB
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aInvestLaneB backward/forward random
        // write to: aSnowLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneC[((aIndex + 6287U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneC[((aIndex + 8694U)) & S_BLOCK1], 12U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 9527U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 10560U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 8296U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 8847U)) & S_BLOCK1], 22U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 8787U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aPrevious, 39U) ^ RotL64(aCross, 27U)) ^ (RotL64(aCarry, 3U) + RotL64(aIngress, 52U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterF = ((aWandererG + RotL64(aIngress, 37U)) + RotL64(aCarry, 57U)) + 3970829908171131502U;
            aOrbiterK = (aWandererI + RotL64(aCross, 56U)) + 7040283759419531991U;
            aOrbiterH = (aWandererB + RotL64(aPrevious, 5U)) + 11856292169397052901U;
            aOrbiterG = (aWandererJ + RotL64(aScatter, 27U)) + 819598588791819022U;
            aOrbiterB = ((((aWandererH + RotL64(aCross, 47U)) + RotL64(aCarry, 39U)) + 2176451710970866848U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordL;
            aOrbiterE = (((aWandererD + RotL64(aScatter, 43U)) + RotL64(aCarry, 5U)) + 6454704928613390494U) + aNonceWordG;
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 52U)) + 11792122387218053841U) + aNonceWordM;
            aOrbiterI = (((aWandererA + RotL64(aIngress, 23U)) + 9254780213489752211U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordC;
            aOrbiterA = (aWandererE + RotL64(aPrevious, 11U)) + 16591812589999846482U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 1471246223935074832U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 1424843083106386453U;
            aOrbiterH = RotL64((aOrbiterH * 15020536982657410783U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 1856469958050891629U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 6331743690452052712U;
            aOrbiterF = RotL64((aOrbiterF * 15327924647897459645U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 10351075711345476487U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 9518585245330480185U) ^ aNonceWordF;
            aOrbiterC = RotL64((aOrbiterC * 3792179827396760391U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 17787514620244712033U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 14182328067398162557U;
            aOrbiterI = RotL64((aOrbiterI * 18107337388659070197U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 12798088948801072444U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 9563215159275202323U;
            aOrbiterK = RotL64((aOrbiterK * 7058145016617349141U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 9904919772580498232U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 16579777394992143043U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10516761340320196661U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 6344049286854588503U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 3531503618941046788U;
            aOrbiterB = RotL64((aOrbiterB * 10855385899703024105U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 11334308840132700377U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 11093833870078787770U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16105889714648555755U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 3831491136025364271U) + aNonceWordP;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 12505259454860591372U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6135450888433504093U), 37U);
            //
            aIngress = RotL64(aOrbiterK, 58U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 11U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 53U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 3U));
            aIngress = aIngress + RotL64(aOrbiterC, 22U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aCross, 28U) + aOrbiterH) + RotL64(aOrbiterA, 5U)) + aNonceWordB);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterB, 40U)) + aOrbiterA);
            aWandererI = aWandererI + ((RotL64(aScatter, 51U) + RotL64(aOrbiterI, 19U)) + aOrbiterH);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 43U) + aOrbiterC) + RotL64(aOrbiterE, 47U));
            aWandererD = aWandererD + ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterB, 27U)) + aOrbiterE) + RotL64(aCarry, 53U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 47U) + aOrbiterF) + RotL64(aOrbiterG, 11U));
            aWandererE = aWandererE + (((RotL64(aIngress, 19U) + aOrbiterK) + RotL64(aOrbiterC, 57U)) + RotL64(aCarry, 27U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 39U) + RotL64(aOrbiterK, 35U)) + aOrbiterG) + aNonceWordE);
            aWandererH = aWandererH + ((((RotL64(aCross, 14U) + RotL64(aOrbiterH, 52U)) + aOrbiterE) + aNonceWordN) + aPhaseFWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 60U) ^ aWandererJ);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererI);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + RotL64(aWandererD, 27U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aSnowLaneD[((aIndex + 12531U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneA[((aIndex + 14223U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 14203U)) & S_BLOCK1], 18U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 11201U)) & S_BLOCK1], 6U) ^ RotL64(aOperationLaneC[((aIndex + 11525U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aPrevious, 50U) ^ RotL64(aCarry, 37U)) + (RotL64(aCross, 21U) + RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 43U)) + RotL64(aCarry, 43U)) + 13854738573712660276U;
            aOrbiterJ = ((aWandererC + RotL64(aCross, 12U)) + 16835460633412286294U) + aPhaseFOrbiterAssignSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterF = (((aWandererH + RotL64(aScatter, 35U)) + RotL64(aCarry, 3U)) + 6785859293758091931U) + aNonceWordF;
            aOrbiterH = ((aWandererK + RotL64(aIngress, 39U)) + 126317283127992659U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = ((aWandererB + RotL64(aScatter, 5U)) + 7568963536291415413U) + aNonceWordI;
            aOrbiterG = ((aWandererA + RotL64(aCross, 22U)) + RotL64(aCarry, 57U)) + 12294016745653004819U;
            aOrbiterK = (aWandererF + RotL64(aIngress, 47U)) + 18269588932920281147U;
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 53U)) + 5872406424994751026U) + aNonceWordP;
            aOrbiterA = (aWandererG + RotL64(aCross, 57U)) + 7764434758831474129U;
            //
            aOrbiterB = (((aOrbiterB + aOrbiterJ) + 4804168969415573371U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1]) + aNonceWordE;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 959601763507651280U;
            aOrbiterF = RotL64((aOrbiterF * 4647396592804833217U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 9257644462479293048U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 14332699366894494579U;
            aOrbiterC = RotL64((aOrbiterC * 8829304078930625541U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 10487012596470786004U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 612729229562321440U;
            aOrbiterK = RotL64((aOrbiterK * 11380387280507726003U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 7845523921295625315U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 12742115479740024747U;
            aOrbiterA = RotL64((aOrbiterA * 15578543510683986421U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 10294667720904610944U) + aNonceWordA;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 14369711143154904567U;
            aOrbiterB = RotL64((aOrbiterB * 13753005602288309379U), 43U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterA) + 10918344717497681894U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 18136794828308636957U;
            aOrbiterG = RotL64((aOrbiterG * 17899418637978002409U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 14378638206724886404U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 7077588188450008059U;
            aOrbiterI = RotL64((aOrbiterI * 485375960462924335U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 8941870012851971932U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 15242087859620352399U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4963002810455992839U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 10395280254030875387U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 6826595516076975980U;
            aOrbiterJ = RotL64((aOrbiterJ * 6198886240333178001U), 27U);
            //
            aIngress = RotL64(aOrbiterB, 11U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 60U));
            aIngress = aIngress + (RotL64(aOrbiterA, 35U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterG, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((((RotL64(aCross, 3U) + aOrbiterI) + RotL64(aOrbiterB, 57U)) + aNonceWordK) + aPhaseFWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aIngress, 53U) + aOrbiterH) + RotL64(aOrbiterG, 3U)) + RotL64(aCarry, 39U)) + aNonceWordN);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 60U) + aOrbiterF) + RotL64(aOrbiterC, 20U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterH, 13U)) + aOrbiterK);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterA, 37U)) + aOrbiterH);
            aWandererC = aWandererC + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterK, 51U)) + aOrbiterJ) + aNonceWordD);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterA, 26U)) + aNonceWordL);
            aWandererF = aWandererF + (((RotL64(aCross, 39U) + RotL64(aOrbiterI, 47U)) + aOrbiterG) + RotL64(aCarry, 27U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 34U) + aOrbiterG) + RotL64(aOrbiterC, 41U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererG, 41U);
            aCarry = aCarry + RotL64(aIngress, 48U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 19020U)) & S_BLOCK1], 29U) ^ RotL64(aSnowLaneC[((aIndex + 16417U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 18131U)) & S_BLOCK1], 50U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 18135U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 21118U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 4U) + RotL64(aCross, 19U)) ^ (RotL64(aCarry, 37U) ^ RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterG = (aWandererJ + RotL64(aIngress, 3U)) + 13880995121909552664U;
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 30U)) + RotL64(aCarry, 47U)) + 14534942818069300546U;
            aOrbiterF = ((aWandererI + RotL64(aCross, 35U)) + 17745973100886007133U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterK = (((aWandererF + RotL64(aScatter, 43U)) + RotL64(aCarry, 57U)) + 2249805580771946872U) + aNonceWordA;
            aOrbiterC = (((aWandererA + RotL64(aCross, 39U)) + 4460116116396439410U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordN;
            aOrbiterI = ((aWandererC + RotL64(aIngress, 13U)) + RotL64(aCarry, 29U)) + 3378683994078106878U;
            aOrbiterJ = (aWandererH + RotL64(aScatter, 57U)) + 3992996501048809123U;
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 20U)) + 12057768808864451929U) + aNonceWordL;
            aOrbiterB = ((aWandererB + RotL64(aScatter, 47U)) + 4115362079047921130U) + aNonceWordP;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 15297384955502206698U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 17623548383481905636U) ^ aNonceWordF;
            aOrbiterF = RotL64((aOrbiterF * 7487278217901483685U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 3559213898000162417U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 12311605719074507335U;
            aOrbiterC = RotL64((aOrbiterC * 3982199462062847697U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 14807313864347885885U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 11222085523291581822U;
            aOrbiterJ = RotL64((aOrbiterJ * 12580941911587215653U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 916681229436292462U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 2441350114032314686U;
            aOrbiterG = RotL64((aOrbiterG * 7336079498999018067U), 43U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterF) + 7361470539894653271U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1]) + aNonceWordK;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 12153585147213579808U;
            aOrbiterI = RotL64((aOrbiterI * 3040327545467672961U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 13566300726101613579U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 14875254144748509128U;
            aOrbiterD = RotL64((aOrbiterD * 13699179902908972403U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 9268158535644002904U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterD) ^ 14144295981814993491U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterK = RotL64((aOrbiterK * 12739937231684038161U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 13861225650900541642U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 12620513474052058164U;
            aOrbiterH = RotL64((aOrbiterH * 18141974182442267181U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 14163773386433257965U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 5725700029399455855U;
            aOrbiterB = RotL64((aOrbiterB * 10446930901088908809U), 57U);
            //
            aIngress = RotL64(aOrbiterK, 47U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterJ, 44U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 41U));
            aIngress = aIngress + (RotL64(aOrbiterB, 27U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aScatter, 56U) + aOrbiterJ) + RotL64(aOrbiterK, 5U)) + aNonceWordB);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 47U) + aOrbiterG) + RotL64(aOrbiterH, 18U));
            aWandererB = aWandererB + (((RotL64(aIngress, 5U) + aOrbiterD) + RotL64(aOrbiterB, 47U)) + aNonceWordG);
            aWandererI = aWandererI ^ ((RotL64(aCross, 41U) + aOrbiterJ) + RotL64(aOrbiterI, 57U));
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterG, 35U)) + aOrbiterF) + RotL64(aCarry, 19U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 23U) + aOrbiterC) + RotL64(aOrbiterI, 30U));
            aWandererF = aWandererF + (((RotL64(aCross, 34U) + aOrbiterK) + RotL64(aOrbiterD, 43U)) + aPhaseFWandererUpdateSaltC[((aIndex + 24U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterD, 13U)) + aOrbiterH);
            aWandererG = aWandererG + (((RotL64(aIngress, 27U) + aOrbiterF) + RotL64(aOrbiterI, 51U)) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + RotL64(aWandererI, 36U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 23118U)) & S_BLOCK1], 57U) ^ RotL64(aSnowLaneD[((aIndex + 25979U)) & S_BLOCK1], 12U));
            aIngress ^= RotL64(aInvestLaneD[((aIndex + 22789U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24999U)) & S_BLOCK1], 60U) ^ RotL64(aSnowLaneC[((aIndex + 25983U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCross, 52U) + RotL64(aPrevious, 21U)) + (RotL64(aCarry, 39U) ^ RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterH = (((aWandererJ + RotL64(aIngress, 13U)) + RotL64(aCarry, 19U)) + 3236820517816085022U) + aNonceWordL;
            aOrbiterB = ((aWandererB + RotL64(aScatter, 47U)) + RotL64(aCarry, 53U)) + 741288875914097926U;
            aOrbiterD = ((aWandererF + RotL64(aCross, 30U)) + RotL64(aCarry, 29U)) + 8417246926007729580U;
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 57U)) + 9715717805774537170U) + aNonceWordC;
            aOrbiterF = ((aWandererE + RotL64(aCross, 21U)) + 14360243844821619482U) + aPhaseFOrbiterAssignSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterI = (aWandererC + RotL64(aScatter, 37U)) + 10760908100206775334U;
            aOrbiterG = (aWandererD + RotL64(aIngress, 42U)) + 3434641779946167811U;
            aOrbiterC = (aWandererH + RotL64(aPrevious, 51U)) + 7885568822756234567U;
            aOrbiterA = ((aWandererK + RotL64(aScatter, 5U)) + 3041563437672051294U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 15761355327564963516U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 1158633562785937421U;
            aOrbiterD = RotL64((aOrbiterD * 15511324886867188235U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 9338581575871970653U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 9172038894262857354U;
            aOrbiterF = RotL64((aOrbiterF * 3110871165285625807U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 14653924713599790081U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 3854497592598563309U;
            aOrbiterB = RotL64((aOrbiterB * 11737111068815795303U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 16286980180327600557U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 5092583772591249756U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13955105624639442903U), 35U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterI) + 4288397994175567333U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordO;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 15584236478994873104U) ^ aNonceWordE;
            aOrbiterH = RotL64((aOrbiterH * 1860480595862755379U), 51U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterA) + 5557463939827483792U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordF;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 2659814275753280856U;
            aOrbiterC = RotL64((aOrbiterC * 17702430405693184643U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 6941807963525063449U) + aNonceWordH;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 2040598555191211307U;
            aOrbiterA = RotL64((aOrbiterA * 14750544987531722765U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 347572666231116258U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 779304821185302523U;
            aOrbiterI = RotL64((aOrbiterI * 14180254150318109855U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 10632524582873079742U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 9761308771280517212U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13926235411726048921U), 47U);
            //
            aIngress = RotL64(aOrbiterC, 39U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterI, 46U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterF, 35U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 43U));
            aIngress = aIngress + RotL64(aOrbiterD, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aPrevious, 23U) + RotL64(aOrbiterH, 27U)) + aOrbiterD) + RotL64(aCarry, 39U)) + aNonceWordJ);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterH, 13U)) + aNonceWordB);
            aWandererK = aWandererK + ((RotL64(aCross, 57U) + RotL64(aOrbiterB, 19U)) + aOrbiterA);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 10U) + aOrbiterF) + RotL64(aOrbiterC, 37U)) + aPhaseFWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 39U) + aOrbiterG) + RotL64(aOrbiterC, 4U)) + aNonceWordP);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 43U) + aOrbiterC) + RotL64(aOrbiterD, 23U));
            aWandererB = aWandererB + (((RotL64(aCross, 19U) + aOrbiterA) + RotL64(aOrbiterJ, 43U)) + aNonceWordN);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 4U) + aOrbiterI) + RotL64(aOrbiterJ, 51U));
            aWandererG = aWandererG + ((((RotL64(aCross, 27U) + RotL64(aOrbiterF, 56U)) + aOrbiterH) + RotL64(aCarry, 13U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 13U) ^ aWandererH);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 51U));
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererG, 10U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererD, 35U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 6
        // ingress from: aExpandLaneC, aExpandLaneA, aSnowLaneA
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aSnowLaneA forward/backward random
        // cross from: aExpandLaneB, aOperationLaneB
        // cross directions: aExpandLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 27958U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneA[((aIndex + 30927U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aSnowLaneA[((aIndex + 28025U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27750U)) & S_BLOCK1], 46U) ^ RotL64(aOperationLaneB[((aIndex + 28462U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 41U) ^ RotL64(aCarry, 54U)) + (RotL64(aPrevious, 3U) ^ RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterH = (((aWandererB + RotL64(aScatter, 53U)) + RotL64(aCarry, 3U)) + 6771552164800695068U) + aNonceWordK;
            aOrbiterD = ((aWandererK + RotL64(aCross, 27U)) + RotL64(aCarry, 51U)) + 12131763371571322040U;
            aOrbiterK = (aWandererI + RotL64(aIngress, 57U)) + 3326182381395522013U;
            aOrbiterE = (aWandererE + RotL64(aPrevious, 34U)) + 12288775097697156383U;
            aOrbiterI = (((aWandererD + RotL64(aIngress, 47U)) + 5195948373449796741U) + aPhaseFOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1]) + aNonceWordC;
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 13U)) + RotL64(aCarry, 19U)) + 14404044002250137144U;
            aOrbiterB = (aWandererA + RotL64(aScatter, 19U)) + 11142382920035825426U;
            aOrbiterC = ((aWandererG + RotL64(aCross, 42U)) + 2967149520256475485U) + aPhaseFOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = (aWandererC + RotL64(aScatter, 5U)) + 1470907369577818097U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 9231668148004163910U) + aNonceWordL;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 13078929163913892386U) ^ aNonceWordA;
            aOrbiterK = RotL64((aOrbiterK * 7509829068700523627U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 9485274692075657877U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterE) ^ 12216951187543631673U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterH = RotL64((aOrbiterH * 6571066246507310805U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 6933334652581744234U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 17260276102423580920U;
            aOrbiterB = RotL64((aOrbiterB * 7796879893790990605U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 387767848169714392U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 8597538259308082638U;
            aOrbiterD = RotL64((aOrbiterD * 4888054690557707241U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 7996708724489146033U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 15357384191688149939U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9827691726832491373U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 17739222908739454637U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 1614322333281471170U;
            aOrbiterE = RotL64((aOrbiterE * 7063116837752240891U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 4531604274893197209U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 3453280714992341288U;
            aOrbiterI = RotL64((aOrbiterI * 8390029711127907805U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 116623650872661533U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 6565636510115095988U;
            aOrbiterA = RotL64((aOrbiterA * 9691897067492501177U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 10303258439817808058U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 10917642773040237611U;
            aOrbiterG = RotL64((aOrbiterG * 10232856828372963363U), 11U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterD, 27U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 39U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 11U));
            aIngress = aIngress + (RotL64(aOrbiterI, 14U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterA, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterB, 58U)) + aOrbiterD) + aNonceWordB);
            aWandererI = aWandererI + (((RotL64(aIngress, 56U) + RotL64(aOrbiterA, 53U)) + aOrbiterB) + RotL64(aCarry, 13U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterC, 39U)) + aOrbiterE) + aPhaseFWandererUpdateSaltD[((aIndex + 10U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aCross, 13U) + RotL64(aOrbiterK, 43U)) + aOrbiterI);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterA, 23U)) + aOrbiterD) + aNonceWordO);
            aWandererK = aWandererK + ((RotL64(aIngress, 29U) + RotL64(aOrbiterD, 47U)) + aOrbiterH);
            aWandererD = aWandererD ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterK, 27U)) + aOrbiterA);
            aWandererE = aWandererE + ((((RotL64(aScatter, 20U) + aOrbiterC) + RotL64(aOrbiterA, 10U)) + RotL64(aCarry, 5U)) + aPhaseFWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterC, 35U)) + aOrbiterG) + aNonceWordP);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 50U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + (RotL64(aWandererA, 41U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererG, 27U);
            aCarry = aCarry + RotL64(aIngress, 38U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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

void TwistExpander_BasketBall_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xF29E78DF18551481ULL + 0x8FE9E096ABBF07A3ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x9391E2EF97327093ULL + 0xFFF991F06BE6BDA6ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x92720A08246AE4AFULL + 0x86BABAFEB3785C56ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xDF1692CC704B88E9ULL + 0xBFE81CFB16DF5007ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x8268ECA24FF99FE3ULL + 0xA2FC4DF72CEE7136ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xBAEFD68C4252EFFBULL + 0x891F4236AF66E4E8ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x922AA43275B26E57ULL + 0xB22AD3316FAA9B49ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xEEAC5F3B0C246A21ULL + 0xD7E3DF0B1CB421B3ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xD42C40C8A3D2B43FULL + 0xC95BE7C66CB2D438ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x962921A7B9754441ULL + 0xC71D4ACF64B4823BULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xACAB0B494E6AEFBBULL + 0xEECEAB3B7ABCF9BAULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x87BDD837236A073BULL + 0x925B49E1F9CE0B4AULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xBBBD37186BDD1719ULL + 0xA9845DB1E53AFD36ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xB5DA9C89F627A4B1ULL + 0x8575DBB3213A1F08ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xFF900A9EA819BD15ULL + 0xDA75DE571315121FULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xFDEA8DC4F4C75435ULL + 0xD6F3CB115086A10FULL);
    // GSeedRunSeed_G seed_loop_h (start)
    {
        // GSeedRunSeed_G seed_loop_h lane group
        // read from: aSnowLaneA, aSnowLaneB, aInvestLaneB, aSnowLaneC, aSnowLaneD, aFireLaneC, aWorkLaneA, aFireLaneD, aFireLaneB, aWorkLaneB, aInvestLaneA, aExpandLaneA, aInvestLaneC, aExpandLaneB, aFireLaneA, aExpandLaneC, aInvestLaneD
        // write to: aWorkLaneA, aWorkLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_h loop 1
        // ingress from: aSnowLaneA, aSnowLaneB, aInvestLaneB
        // ingress directions: aSnowLaneA forward forced, aSnowLaneB forward forced, aInvestLaneB forward/backward random
        // cross from: aSnowLaneC, aSnowLaneD, aFireLaneC
        // cross directions: aSnowLaneC backward forced, aSnowLaneD backward forced, aFireLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 4145U)) & S_BLOCK1], 51U) ^ RotL64(aSnowLaneB[((aIndex + 5313U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 1476U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 2570U)) & S_BLOCK1], 18U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 1526U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 4090U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 10U) ^ RotL64(aPrevious, 53U)) + (RotL64(aIngress, 35U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterG = ((aWandererK + RotL64(aScatter, 47U)) + RotL64(aCarry, 35U)) + 16183871922837164759U;
            aOrbiterA = ((aWandererI + RotL64(aIngress, 21U)) + RotL64(aCarry, 19U)) + 7002058258090219055U;
            aOrbiterF = (aWandererA + RotL64(aPrevious, 3U)) + 5650868611888303705U;
            aOrbiterD = ((aWandererE + RotL64(aCross, 53U)) + 11899839660943876690U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = (((aWandererD + RotL64(aPrevious, 38U)) + 15349649504488111111U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordA;
            aOrbiterE = (((aWandererJ + RotL64(aCross, 11U)) + RotL64(aCarry, 3U)) + 14060149569086744970U) + aNonceWordF;
            aOrbiterC = (aWandererC + RotL64(aIngress, 27U)) + 12920917574225030112U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 2831994965175330135U) + aNonceWordE;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 18312543585028439192U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11618182708195744321U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 11657562205118394239U) + aNonceWordH;
            aOrbiterK = (((aOrbiterK ^ aOrbiterD) ^ 10850792819281246052U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterK = RotL64((aOrbiterK * 10663100544207879337U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 17810371216216125323U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 7963413941144223128U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 534217972450595401U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 5498715358793875584U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 9256727548911651373U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10498848323914000989U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 17246360111302191699U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 18309978718113983369U;
            aOrbiterD = RotL64((aOrbiterD * 18267472694666221077U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 3100998994319502921U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 8129301860291235970U;
            aOrbiterG = RotL64((aOrbiterG * 17847033539279176187U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 1889641029473279114U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 16538494307002917945U;
            aOrbiterE = RotL64((aOrbiterE * 8081488217920885783U), 41U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterF, 13U);
            aIngress = aIngress + (RotL64(aOrbiterK, 46U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterA, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aCross, 51U) + aOrbiterK) + RotL64(aOrbiterD, 37U)) + aPhaseHWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterC, 51U)) + aOrbiterK) + RotL64(aCarry, 21U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 3U) + aOrbiterK) + RotL64(aOrbiterA, 58U)) + aNonceWordP);
            aWandererA = aWandererA + ((((RotL64(aScatter, 43U) + RotL64(aOrbiterF, 29U)) + aOrbiterE) + RotL64(aCarry, 41U)) + aNonceWordC);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterC, 3U)) + aOrbiterF) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 57U) + aOrbiterC) + RotL64(aOrbiterA, 23U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 12U) + RotL64(aOrbiterG, 11U)) + aOrbiterE) + aNonceWordO);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + (RotL64(aWandererE, 48U) ^ aWandererA);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + RotL64(aWandererI, 19U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 2
        // ingress from: aWorkLaneA, aSnowLaneC, aSnowLaneD, aFireLaneD
        // ingress directions: aWorkLaneA forward forced, aSnowLaneC forward forced, aSnowLaneD forward forced, aFireLaneD forward/backward random
        // cross from: aSnowLaneA, aSnowLaneB, aFireLaneB
        // cross directions: aSnowLaneA backward forced, aSnowLaneB backward forced, aFireLaneB backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 8014U)) & S_BLOCK1], 10U) ^ RotL64(aSnowLaneC[((aIndex + 5733U)) & S_BLOCK1], 21U));
            aIngress ^= (RotL64(aSnowLaneD[((aIndex + 6171U)) & S_BLOCK1], 53U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 7366U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 9059U)) & S_BLOCK1], 30U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 6265U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 10577U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 11U) ^ RotL64(aPrevious, 56U)) + (RotL64(aCarry, 41U) + RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterE = ((aWandererC + RotL64(aCross, 57U)) + 5960680319644404115U) + aNonceWordH;
            aOrbiterD = (((aWandererE + RotL64(aPrevious, 34U)) + RotL64(aCarry, 37U)) + 16050752633567034185U) + aPhaseHOrbiterAssignSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 19U)) + 8447503223226854741U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = (((aWandererF + RotL64(aIngress, 27U)) + RotL64(aCarry, 53U)) + 14176813813397917591U) + aNonceWordI;
            aOrbiterI = ((aWandererD + RotL64(aPrevious, 51U)) + 10534915376130006644U) + aNonceWordN;
            aOrbiterC = (aWandererJ + RotL64(aIngress, 43U)) + 6866224454375302514U;
            aOrbiterG = (((aWandererH + RotL64(aScatter, 3U)) + RotL64(aCarry, 3U)) + 16506374165041008396U) + aNonceWordB;
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 7167814023968794098U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 13870852197416596664U) ^ aNonceWordL;
            aOrbiterJ = RotL64((aOrbiterJ * 17015971222069856463U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 18064038854848993105U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 9869630811507771691U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13723164383800461387U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 863613100452759380U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 16597969741225436529U) ^ aNonceWordJ;
            aOrbiterD = RotL64((aOrbiterD * 2680793528887208903U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 6575347108051310653U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 17062262265485019063U;
            aOrbiterE = RotL64((aOrbiterE * 7601045488473620019U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 7193399224636409133U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 14146747818810433849U) ^ aNonceWordG;
            aOrbiterA = RotL64((aOrbiterA * 5273185769989530041U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 9441449106442431427U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 4303295336545399503U;
            aOrbiterG = RotL64((aOrbiterG * 8829695296836242587U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 12604760768543193458U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 15779327512379787715U;
            aOrbiterC = RotL64((aOrbiterC * 14000905201441272597U), 47U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterD, 35U);
            aIngress = aIngress + (RotL64(aOrbiterA, 14U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 51U));
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aScatter, 57U) + aOrbiterC) + RotL64(aOrbiterE, 47U));
            aWandererD = aWandererD ^ ((((RotL64(aIngress, 5U) + RotL64(aOrbiterD, 5U)) + aOrbiterA) + aNonceWordC) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 35U) + RotL64(aOrbiterI, 11U)) + aOrbiterD) + aPhaseHWandererUpdateSaltF[((aIndex + 8U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 23U) + aOrbiterG) + RotL64(aOrbiterI, 54U));
            aWandererH = aWandererH + ((((RotL64(aCross, 47U) + RotL64(aOrbiterJ, 27U)) + aOrbiterC) + RotL64(aCarry, 35U)) + aNonceWordP);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 29U) + aOrbiterG) + RotL64(aOrbiterD, 35U)) + aNonceWordK);
            aWandererA = aWandererA + ((((RotL64(aScatter, 14U) + aOrbiterG) + RotL64(aOrbiterJ, 41U)) + RotL64(aCarry, 11U)) + aNonceWordM);
            //
            aCarry = aCarry + (RotL64(aWandererA, 4U) ^ aWandererF);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + RotL64(aWandererH, 23U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_h loop 3
        // ingress from: aWorkLaneB, aSnowLaneA, aInvestLaneA
        // ingress directions: aWorkLaneB forward forced, aSnowLaneA forward forced, aInvestLaneA forward/backward random
        // cross from: aWorkLaneA, aSnowLaneC
        // cross directions: aWorkLaneA backward forced, aSnowLaneC backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 14286U)) & S_BLOCK1], 47U) ^ RotL64(aSnowLaneA[((aIndex + 15734U)) & S_BLOCK1], 38U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 13469U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15253U)) & S_BLOCK1], 58U) ^ RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 11618U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aPrevious, 13U) + RotL64(aCarry, 54U)) ^ (RotL64(aCross, 27U) + RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterA = (((aWandererK + RotL64(aPrevious, 41U)) + RotL64(aCarry, 13U)) + 5721224134332887360U) + aPhaseHOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = ((aWandererJ + RotL64(aCross, 22U)) + 6892749729775049095U) + aNonceWordD;
            aOrbiterB = (aWandererF + RotL64(aIngress, 13U)) + 3884839462099556836U;
            aOrbiterG = ((aWandererA + RotL64(aScatter, 35U)) + RotL64(aCarry, 53U)) + 4365431706830216193U;
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 47U)) + 15501528746571578773U) + aNonceWordN;
            aOrbiterH = ((aWandererH + RotL64(aIngress, 29U)) + 4505911326320650606U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = ((aWandererG + RotL64(aCross, 53U)) + RotL64(aCarry, 39U)) + 1865129050927879580U;
            //
            aOrbiterA = (((aOrbiterA + aOrbiterK) + 2011737665969640369U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordK;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 611672935827062688U;
            aOrbiterB = RotL64((aOrbiterB * 12873671551304596619U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 663547038310431047U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 5468932264754299556U;
            aOrbiterH = RotL64((aOrbiterH * 11968657455484578525U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 17920294117231191705U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 486058453837528110U;
            aOrbiterK = RotL64((aOrbiterK * 8851102552244026737U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 2789178451938129313U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 420772587981211184U;
            aOrbiterG = RotL64((aOrbiterG * 17402987842294006667U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 16196774774442181825U) + aNonceWordL;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 16264169656793713547U;
            aOrbiterA = RotL64((aOrbiterA * 6900221986041638783U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 10207659833859860796U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterJ) ^ 8593749091183323678U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterE = RotL64((aOrbiterE * 10696776033512404927U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 7224922076047787384U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 15366267474865172373U;
            aOrbiterJ = RotL64((aOrbiterJ * 10134187073321814217U), 39U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterE, 13U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 51U));
            aIngress = aIngress + (RotL64(aOrbiterG, 40U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterK, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterK, 5U)) + aOrbiterH);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 57U) + aOrbiterK) + RotL64(aOrbiterG, 53U)) + RotL64(aCarry, 11U)) + aNonceWordP);
            aWandererK = aWandererK ^ (((RotL64(aCross, 21U) + aOrbiterH) + RotL64(aOrbiterA, 21U)) + aNonceWordI);
            aWandererH = aWandererH + (((((RotL64(aScatter, 35U) + RotL64(aOrbiterH, 39U)) + aOrbiterE) + RotL64(aCarry, 51U)) + aNonceWordM) + aPhaseHWandererUpdateSaltD[((aIndex + 4U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((((RotL64(aIngress, 41U) + RotL64(aOrbiterB, 29U)) + aOrbiterA) + aNonceWordA) + aPhaseHWandererUpdateSaltA[((aIndex + 6U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 51U) + aOrbiterA) + RotL64(aOrbiterE, 13U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 6U) + aOrbiterB) + RotL64(aOrbiterJ, 60U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + (RotL64(aWandererF, 12U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererH, 5U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 4
        // ingress from: aExpandLaneA, aWorkLaneA, aInvestLaneC
        // ingress directions: aExpandLaneA forward forced, aWorkLaneA forward forced, aInvestLaneC forward/backward random
        // cross from: aWorkLaneB, aSnowLaneD
        // cross directions: aWorkLaneB backward forced, aSnowLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 21710U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneA[((aIndex + 21811U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 17654U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17050U)) & S_BLOCK1], 53U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 17356U)) & S_BLOCK1], 22U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aIngress, 27U) ^ RotL64(aCross, 52U)) + (RotL64(aCarry, 39U) + RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterF = (((aWandererC + RotL64(aIngress, 3U)) + RotL64(aCarry, 35U)) + 13924571355038625040U) + aNonceWordJ;
            aOrbiterB = (aWandererF + RotL64(aPrevious, 26U)) + 16328300979357156658U;
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 57U)) + RotL64(aCarry, 23U)) + 3947771961206012461U;
            aOrbiterA = (aWandererB + RotL64(aCross, 47U)) + 15428284250569311285U;
            aOrbiterJ = (aWandererH + RotL64(aScatter, 19U)) + 5777369485254032486U;
            aOrbiterG = (((aWandererD + RotL64(aPrevious, 13U)) + 16813320300717644673U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordE;
            aOrbiterC = (((aWandererE + RotL64(aCross, 35U)) + RotL64(aCarry, 11U)) + 16689933050200758251U) + aPhaseHOrbiterAssignSaltA[((aIndex + 4U)) & S_SALT1];
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 1856422419049390708U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 18214498743831925517U;
            aOrbiterI = RotL64((aOrbiterI * 10744120577560529379U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 18278550878494094923U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 797712062039591797U;
            aOrbiterF = RotL64((aOrbiterF * 7212998747080137625U), 19U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterG) + 15854849439012341347U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordG;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 996882939768167773U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14936703950807908575U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 3005829974130671692U) + aNonceWordK;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 8793495343509953906U;
            aOrbiterA = RotL64((aOrbiterA * 14065479348374612031U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 7710453029930631112U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 9511995836117707047U;
            aOrbiterG = RotL64((aOrbiterG * 7250766204781428201U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 670902975693341744U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 9045820304668279777U) ^ aNonceWordM;
            aOrbiterJ = RotL64((aOrbiterJ * 18373074917532639027U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 12417212387607119470U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 12816983560669985622U;
            aOrbiterB = RotL64((aOrbiterB * 8406003970221889847U), 47U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterG, 51U);
            aIngress = aIngress + (RotL64(aOrbiterF, 35U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 58U));
            aIngress = aIngress + RotL64(aOrbiterI, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterF, 13U)) + aOrbiterA) + aNonceWordD);
            aWandererC = aWandererC + ((RotL64(aIngress, 21U) + RotL64(aOrbiterA, 27U)) + aOrbiterG);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 5U) + aOrbiterB) + RotL64(aOrbiterF, 21U));
            aWandererB = aWandererB + ((((RotL64(aPrevious, 11U) + aOrbiterB) + RotL64(aOrbiterG, 51U)) + RotL64(aCarry, 5U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 57U) + aOrbiterA) + RotL64(aOrbiterC, 57U)) + aNonceWordN);
            aWandererF = aWandererF + ((((RotL64(aCross, 47U) + aOrbiterA) + RotL64(aOrbiterJ, 44U)) + RotL64(aCarry, 53U)) + aNonceWordB);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 40U) + RotL64(aOrbiterG, 3U)) + aOrbiterI) + aPhaseHWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + (RotL64(aWandererB, 22U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererD, 13U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_h loop 5
        // ingress from: aExpandLaneB, aWorkLaneB, aFireLaneA
        // ingress directions: aExpandLaneB forward forced, aWorkLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneA, aWorkLaneA
        // cross directions: aExpandLaneA backward forced, aWorkLaneA backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 25317U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((aIndex + 23682U)) & S_BLOCK1], 20U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 26138U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24197U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22737U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 6U) ^ RotL64(aIngress, 35U)) ^ (RotL64(aPrevious, 51U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 11U)) + 2786079456995203065U) + aNonceWordJ;
            aOrbiterB = ((aWandererB + RotL64(aCross, 35U)) + RotL64(aCarry, 23U)) + 7237256119153857253U;
            aOrbiterC = (aWandererK + RotL64(aIngress, 29U)) + 9310834010563647604U;
            aOrbiterK = ((aWandererA + RotL64(aPrevious, 51U)) + RotL64(aCarry, 43U)) + 17361734905706517877U;
            aOrbiterA = ((((aWandererC + RotL64(aScatter, 43U)) + RotL64(aCarry, 3U)) + 15837111231884647451U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordD;
            aOrbiterG = (aWandererD + RotL64(aPrevious, 18U)) + 18065431964418026445U;
            aOrbiterJ = ((aWandererG + RotL64(aIngress, 57U)) + 3029123922999952652U) + aPhaseHOrbiterAssignSaltE[((aIndex + 10U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 5166926595573507837U) + aNonceWordM;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 1918425684273807598U;
            aOrbiterC = RotL64((aOrbiterC * 16616641579714896719U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 4724551751012661440U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 1818014487579644390U) ^ aNonceWordK;
            aOrbiterA = RotL64((aOrbiterA * 14904092108647864911U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 6670090372241084216U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 8485757110007268693U;
            aOrbiterG = RotL64((aOrbiterG * 11876760095108618363U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 4928130251509514742U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 2528788422725346792U;
            aOrbiterJ = RotL64((aOrbiterJ * 1855982047967756661U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 2860387120895147503U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 12927802338151379368U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8876144125458603029U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 18029699867733207083U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 13361836994951253312U) ^ aNonceWordA;
            aOrbiterK = RotL64((aOrbiterK * 5349767426256597073U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 11957294454794128079U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterJ) ^ 3755417922063414648U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterB = RotL64((aOrbiterB * 13896364063651241401U), 51U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterK, 3U);
            aIngress = aIngress + (RotL64(aOrbiterA, 39U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterC, 51U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterB, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterI, 11U)) + aOrbiterC) + aNonceWordI);
            aWandererG = aWandererG + ((((RotL64(aScatter, 19U) + RotL64(aOrbiterA, 29U)) + aOrbiterC) + RotL64(aCarry, 27U)) + aNonceWordO);
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 41U) + RotL64(aOrbiterJ, 3U)) + aOrbiterC) + aNonceWordC) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aCross, 60U) + RotL64(aOrbiterG, 57U)) + aOrbiterJ) + RotL64(aCarry, 51U)) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterI, 22U)) + aOrbiterB) + aNonceWordH);
            aWandererK = aWandererK + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterC, 47U)) + aOrbiterK);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterG, 41U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 22U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 51U));
            aCarry = aCarry + (RotL64(aWandererD, 41U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererC, 37U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 6
        // ingress from: aExpandLaneC, aExpandLaneA, aInvestLaneD
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aInvestLaneD forward/backward random
        // cross from: aExpandLaneB, aSnowLaneB
        // cross directions: aExpandLaneB backward forced, aSnowLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 31230U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneA[((aIndex + 28278U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 27442U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32756U)) & S_BLOCK1], 52U) ^ RotL64(aSnowLaneB[((aIndex + 29914U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aPrevious, 38U) + RotL64(aCross, 5U)) + (RotL64(aCarry, 51U) ^ RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterI = ((aWandererB + RotL64(aIngress, 53U)) + RotL64(aCarry, 37U)) + 9914837590440975587U;
            aOrbiterE = (((aWandererF + RotL64(aScatter, 29U)) + 6706125076401958051U) + aPhaseHOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1]) + aNonceWordL;
            aOrbiterB = (((aWandererK + RotL64(aCross, 43U)) + RotL64(aCarry, 3U)) + 16570817772679258409U) + aNonceWordB;
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 20U)) + 6843705658115186948U) + aPhaseHOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = (aWandererE + RotL64(aCross, 3U)) + 16099930446791572351U;
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 11U)) + 5420550009556030459U) + aNonceWordI;
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 35U)) + RotL64(aCarry, 19U)) + 5729549069420177477U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 15590601126188675834U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 13044027390998620029U;
            aOrbiterB = RotL64((aOrbiterB * 16845199115313444123U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 11068338135659636772U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 6584988841809544332U;
            aOrbiterE = RotL64((aOrbiterE * 1683336180438945439U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 8516813219883915404U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterC) ^ 10647314042912492785U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterK = RotL64((aOrbiterK * 15559481057047148785U), 41U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterI) + 201691689889605304U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1]) + aNonceWordK;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 15512161798401184003U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11473219183982564709U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 3883760518944464145U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 13861805129175491145U;
            aOrbiterD = RotL64((aOrbiterD * 17194438894492581181U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 12019138626550801486U) + aNonceWordO;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 13030350224959652248U;
            aOrbiterI = RotL64((aOrbiterI * 11724200983306280107U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 2643807255422544248U) + aNonceWordH;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 4127143302485631794U;
            aOrbiterF = RotL64((aOrbiterF * 5441038881111578487U), 13U);
            //
            aIngress = RotL64(aOrbiterF, 20U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 5U));
            aIngress = aIngress + RotL64(aOrbiterI, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 29U) + aOrbiterK) + RotL64(aOrbiterF, 6U));
            aWandererF = aWandererF + (((RotL64(aIngress, 44U) + RotL64(aOrbiterC, 43U)) + aOrbiterB) + RotL64(aCarry, 27U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 11U) + aOrbiterF) + RotL64(aOrbiterI, 19U)) + aPhaseHWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererD = aWandererD + (((((RotL64(aCross, 37U) + RotL64(aOrbiterE, 53U)) + aOrbiterF) + RotL64(aCarry, 5U)) + aNonceWordJ) + aPhaseHWandererUpdateSaltA[((aIndex + 18U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterI, 27U)) + aOrbiterK) + aNonceWordP);
            aWandererG = aWandererG + (((RotL64(aScatter, 5U) + aOrbiterE) + RotL64(aOrbiterD, 35U)) + aNonceWordG);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 23U) + aOrbiterF) + RotL64(aOrbiterC, 13U)) + aNonceWordM);
            //
            aCarry = aCarry + (RotL64(aWandererF, 21U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 34U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererK, 39U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererD, 11U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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

void TwistExpander_BasketBall_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF;
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 121U)) & W_KEY1], 47U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 2443U)) & W_KEY1], 36U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 1442U)) & W_KEY1], 3U) ^ RotL64(mSource[((aIndex + 891U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aPrevious, 10U)) + (RotL64(aCross, 27U) + RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = ((aWandererH + RotL64(aScatter, 12U)) + RotL64(aCarry, 57U)) + 13687218104610230596U;
            aOrbiterG = ((aWandererC + RotL64(aIngress, 57U)) + RotL64(aCarry, 13U)) + 6841550124960692709U;
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 23U)) + 17418968668458764131U) + aPhaseAOrbiterAssignSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterD = ((aWandererK + RotL64(aCross, 47U)) + RotL64(aCarry, 21U)) + 8303537912696948204U;
            aOrbiterH = (aWandererF + RotL64(aPrevious, 19U)) + 12376614417285936537U;
            aOrbiterA = (aWandererB + RotL64(aIngress, 28U)) + 14215749063579232654U;
            aOrbiterB = (aWandererG + RotL64(aCross, 3U)) + 4111736931433665347U;
            aOrbiterC = (aWandererJ + RotL64(aScatter, 37U)) + 11250375934571631522U;
            aOrbiterK = ((aWandererE + RotL64(aCross, 43U)) + 5367367837773331275U) + aPhaseAOrbiterAssignSaltC[((aIndex + 6U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 15514089192382674434U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 1475991716685034960U;
            aOrbiterJ = RotL64((aOrbiterJ * 17720681295551650891U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 5531622777788629748U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 8363822215908303335U;
            aOrbiterH = RotL64((aOrbiterH * 17850203366840994883U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 3741256932685720414U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 11634667238062155772U;
            aOrbiterB = RotL64((aOrbiterB * 15925089729784547403U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 18180546911210417155U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 5123234656838556335U;
            aOrbiterA = RotL64((aOrbiterA * 15362857462853398025U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 11215734271189250284U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 16863747802158398092U;
            aOrbiterD = RotL64((aOrbiterD * 1828035970246160023U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 9859050606636646323U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 9331300036643654675U;
            aOrbiterK = RotL64((aOrbiterK * 2502263410556166281U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 15028845665427209759U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 8916444839488901676U;
            aOrbiterG = RotL64((aOrbiterG * 6646561894156038791U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 8024631140949068570U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 1116378858490660031U;
            aOrbiterC = RotL64((aOrbiterC * 4247798531910227367U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 5066486214537899212U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 9346312092322423057U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13443190089768875191U), 57U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterD, 23U);
            aIngress = aIngress + (RotL64(aOrbiterC, 56U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterJ, 11U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 19U));
            aIngress = aIngress + RotL64(aOrbiterB, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 47U) + RotL64(aOrbiterB, 41U)) + aOrbiterK) + RotL64(aCarry, 3U)) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterH, 19U)) + aOrbiterB);
            aWandererB = aWandererB + (((RotL64(aIngress, 54U) + aOrbiterC) + RotL64(aOrbiterH, 52U)) + RotL64(aCarry, 51U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterC, 13U)) + aOrbiterE);
            aWandererC = aWandererC + ((RotL64(aIngress, 23U) + RotL64(aOrbiterB, 23U)) + aOrbiterE);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterA, 37U)) + aOrbiterD);
            aWandererE = aWandererE + ((RotL64(aCross, 60U) + RotL64(aOrbiterG, 47U)) + aOrbiterJ);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterJ, 4U)) + aOrbiterH);
            aWandererF = aWandererF + (((RotL64(aIngress, 27U) + RotL64(aOrbiterB, 57U)) + aOrbiterD) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererF);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + (RotL64(aWandererK, 6U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 19U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 4785U)) & S_BLOCK1], 12U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 4969U)) & W_KEY1], 43U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 3056U)) & W_KEY1], 12U) ^ RotL64(mSource[((aIndex + 4402U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aIngress, 11U)) ^ (RotL64(aPrevious, 41U) + RotL64(aCarry, 24U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = (((aWandererJ + RotL64(aIngress, 29U)) + RotL64(aCarry, 51U)) + 8988572360732005217U) + aPhaseAOrbiterAssignSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = (aWandererG + RotL64(aPrevious, 14U)) + 17889613225105985335U;
            aOrbiterJ = (aWandererD + RotL64(aScatter, 23U)) + 15563478320513948626U;
            aOrbiterE = ((aWandererA + RotL64(aCross, 5U)) + 3441351228410524816U) + aPhaseAOrbiterAssignSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterG = (aWandererB + RotL64(aIngress, 37U)) + 4425592689451435346U;
            aOrbiterK = (aWandererC + RotL64(aPrevious, 47U)) + 12733160231627305928U;
            aOrbiterD = ((aWandererF + RotL64(aCross, 43U)) + RotL64(aCarry, 35U)) + 3574152157304607854U;
            aOrbiterA = ((aWandererH + RotL64(aScatter, 10U)) + RotL64(aCarry, 27U)) + 15167631896729808783U;
            aOrbiterH = (aWandererI + RotL64(aIngress, 51U)) + 15822667973915417055U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 17181685481076577637U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 9979204751408873468U;
            aOrbiterJ = RotL64((aOrbiterJ * 8244434774754786565U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 1334240485667164762U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 9190066751460137016U;
            aOrbiterF = RotL64((aOrbiterF * 14585141844653660363U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 15465215829109246336U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 2305208282453624419U;
            aOrbiterI = RotL64((aOrbiterI * 10257861974108363283U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 16951510027310993926U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 11117938943423526901U;
            aOrbiterD = RotL64((aOrbiterD * 7805486716716924787U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 12461379120662979432U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 11719697049048823897U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14880996802304818757U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 6843357278142933570U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 12727898578324702374U;
            aOrbiterK = RotL64((aOrbiterK * 9786435451654365097U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 18127999660067652233U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 11754709060558683082U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12798744012150745847U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 16940151146420516184U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 12924950783056761895U;
            aOrbiterH = RotL64((aOrbiterH * 8898170377271926745U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 14829713915929878471U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 840466047621042565U;
            aOrbiterE = RotL64((aOrbiterE * 10748511630509529489U), 43U);
            //
            aIngress = RotL64(aOrbiterA, 53U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 43U));
            aIngress = aIngress + (RotL64(aOrbiterK, 23U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterG, 37U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterE, 58U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aIngress, 12U) + aOrbiterI) + RotL64(aOrbiterE, 58U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 47U) + aOrbiterK) + RotL64(aOrbiterE, 19U));
            aWandererI = aWandererI + ((((RotL64(aScatter, 35U) + aOrbiterE) + RotL64(aOrbiterG, 43U)) + RotL64(aCarry, 47U)) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 19U) + aOrbiterG) + RotL64(aOrbiterK, 23U));
            aWandererF = aWandererF + ((RotL64(aScatter, 28U) + RotL64(aOrbiterA, 11U)) + aOrbiterI);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 5U) + aOrbiterJ) + RotL64(aOrbiterH, 27U));
            aWandererD = aWandererD + ((((RotL64(aCross, 53U) + RotL64(aOrbiterG, 5U)) + aOrbiterJ) + RotL64(aCarry, 37U)) + aPhaseAWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 57U) + aOrbiterF) + RotL64(aOrbiterI, 39U));
            aWandererG = aWandererG + ((RotL64(aScatter, 41U) + aOrbiterD) + RotL64(aOrbiterH, 50U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + (RotL64(aWandererB, 58U) ^ aWandererJ);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererG, 19U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 7041U)) & S_BLOCK1], 40U) ^ RotL64(aKeyRowReadB[((aIndex + 5583U)) & W_KEY1], 29U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 6162U)) & W_KEY1], 3U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 7583U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 6896U)) & S_BLOCK1], 36U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 43U) + RotL64(aIngress, 19U)) ^ (RotL64(aPrevious, 6U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = ((aWandererA + RotL64(aCross, 53U)) + RotL64(aCarry, 41U)) + 9041099828460168106U;
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 11U)) + RotL64(aCarry, 3U)) + 12883711604096848454U;
            aOrbiterK = ((aWandererK + RotL64(aScatter, 48U)) + RotL64(aCarry, 19U)) + 17420968786226443079U;
            aOrbiterI = (aWandererH + RotL64(aIngress, 39U)) + 3448213891716125104U;
            aOrbiterG = ((aWandererD + RotL64(aScatter, 19U)) + 11866455977445336560U) + aPhaseAOrbiterAssignSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = (aWandererB + RotL64(aCross, 3U)) + 4119356835384495905U;
            aOrbiterB = (aWandererC + RotL64(aPrevious, 60U)) + 2186212599698637068U;
            aOrbiterD = ((aWandererE + RotL64(aIngress, 43U)) + 6506144898969301620U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = (aWandererJ + RotL64(aScatter, 29U)) + 12556800923644051626U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 4075551535185182945U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 17877694808492008749U;
            aOrbiterK = RotL64((aOrbiterK * 901315308379887473U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 5553428900598223316U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 14362304852277160675U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11415103199856419303U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 9174200302876075831U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 16110739511917638547U;
            aOrbiterC = RotL64((aOrbiterC * 7004356839428657949U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 10189881974519849402U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 2128076632642616677U;
            aOrbiterJ = RotL64((aOrbiterJ * 8860453653433114929U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 18133523799074400083U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 9916472958834153766U;
            aOrbiterA = RotL64((aOrbiterA * 3454601168808001733U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 10274457562795569227U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 14134814273275356425U;
            aOrbiterD = RotL64((aOrbiterD * 15912501063665343159U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 6394306369514735480U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 4825761192736485643U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12534544147331805643U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 5672807934779206275U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 3881953574159390421U;
            aOrbiterI = RotL64((aOrbiterI * 7448770570912161095U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 12012232712634303203U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 14176392925893052596U;
            aOrbiterE = RotL64((aOrbiterE * 11288668529893084583U), 23U);
            //
            aIngress = RotL64(aOrbiterI, 21U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterC, 56U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterJ, 27U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterA, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aIngress, 10U) + RotL64(aOrbiterI, 51U)) + aOrbiterK) + RotL64(aCarry, 53U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterA, 56U)) + aOrbiterJ);
            aWandererE = aWandererE + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterJ, 23U)) + aOrbiterK);
            aWandererI = aWandererI ^ (((RotL64(aCross, 35U) + aOrbiterK) + RotL64(aOrbiterB, 35U)) + aPhaseAWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 43U) + RotL64(aOrbiterA, 27U)) + aOrbiterB) + RotL64(aCarry, 27U)) + aPhaseAWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 23U) + aOrbiterA) + RotL64(aOrbiterE, 5U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 57U) + aOrbiterD) + RotL64(aOrbiterA, 41U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 6U) + RotL64(aOrbiterJ, 46U)) + aOrbiterC);
            aWandererC = aWandererC + ((RotL64(aIngress, 19U) + RotL64(aOrbiterD, 13U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererE, 5U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererD, 18U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererA, 53U);
            aCarry = aCarry + RotL64(aIngress, 26U);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 10014U)) & S_BLOCK1], 41U) ^ RotL64(aKeyRowReadB[((aIndex + 8972U)) & W_KEY1], 23U));
            aIngress ^= (RotL64(mSource[((aIndex + 10890U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneA[((aIndex + 8248U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 9076U)) & W_KEY1], 41U) ^ RotL64(aWorkLaneB[((aIndex + 9882U)) & S_BLOCK1], 26U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aIngress, 56U)) ^ (RotL64(aPrevious, 27U) ^ RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = (aWandererJ + RotL64(aScatter, 13U)) + 18302975933754610273U;
            aOrbiterJ = (aWandererF + RotL64(aCross, 29U)) + 16736972646771456082U;
            aOrbiterC = (((aWandererI + RotL64(aPrevious, 52U)) + RotL64(aCarry, 13U)) + 17389406266488137442U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = (aWandererC + RotL64(aIngress, 37U)) + 5252511566486165539U;
            aOrbiterD = ((aWandererE + RotL64(aCross, 5U)) + RotL64(aCarry, 23U)) + 5730715427422747640U;
            aOrbiterA = (aWandererK + RotL64(aIngress, 57U)) + 6412695646456045825U;
            aOrbiterK = ((aWandererH + RotL64(aScatter, 19U)) + 9539701605708994494U) + aPhaseBOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = (aWandererA + RotL64(aPrevious, 48U)) + 18355107116412945722U;
            aOrbiterI = ((aWandererG + RotL64(aIngress, 43U)) + RotL64(aCarry, 43U)) + 11735742491750132942U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 12363819388562658842U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 5861430292304371543U;
            aOrbiterC = RotL64((aOrbiterC * 12989055611235382695U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 15027487084595017708U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 7012850020745791926U;
            aOrbiterD = RotL64((aOrbiterD * 15952928839355613939U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 11904871669287886120U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 11199760114477343208U;
            aOrbiterE = RotL64((aOrbiterE * 7156374911847525867U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 3856004502263742700U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 3705931243173921893U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10334871178498711485U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 12305785390539209389U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 18057980996551978823U;
            aOrbiterF = RotL64((aOrbiterF * 4850564181113470859U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 3229431819292153014U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 2994716629242460094U;
            aOrbiterI = RotL64((aOrbiterI * 1029427328395257917U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 9796307843453735512U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 2957260393651252432U;
            aOrbiterA = RotL64((aOrbiterA * 7261055869794739609U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 4060469664218866340U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 17462081697889685330U;
            aOrbiterK = RotL64((aOrbiterK * 7712009170974461225U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 13638660073917821172U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 15202349592659062565U;
            aOrbiterJ = RotL64((aOrbiterJ * 4514326257446024301U), 47U);
            //
            aIngress = RotL64(aOrbiterK, 37U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + (RotL64(aOrbiterC, 13U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterA, 23U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterE, 56U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 13U) + aOrbiterF) + RotL64(aOrbiterH, 30U));
            aWandererF = aWandererF + (((RotL64(aIngress, 19U) + RotL64(aOrbiterC, 57U)) + aOrbiterE) + RotL64(aCarry, 35U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 54U) + aOrbiterI) + RotL64(aOrbiterH, 13U));
            aWandererI = aWandererI + (((RotL64(aCross, 29U) + aOrbiterC) + RotL64(aOrbiterH, 3U)) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterF, 41U)) + aOrbiterA);
            aWandererE = aWandererE + ((RotL64(aCross, 47U) + RotL64(aOrbiterH, 19U)) + aOrbiterD);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterA, 23U)) + aOrbiterD);
            aWandererH = aWandererH + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterK, 46U)) + aOrbiterD) + RotL64(aCarry, 57U)) + aPhaseBWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 24U) + aOrbiterI) + RotL64(aOrbiterJ, 37U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 36U));
            aCarry = aCarry + (RotL64(aWandererC, 43U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 5U));
            aCarry = aCarry + RotL64(aWandererH, 57U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 13185U)) & S_BLOCK1], 12U) ^ RotL64(aKeyRowReadA[((aIndex + 13441U)) & W_KEY1], 43U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 13117U)) & W_KEY1], 57U) ^ RotL64(mSource[((aIndex + 12908U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 13298U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11729U)) & S_BLOCK1], 20U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 11597U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 34U) + RotL64(aPrevious, 21U)) ^ (RotL64(aIngress, 47U) + RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = ((aWandererJ + RotL64(aCross, 10U)) + RotL64(aCarry, 51U)) + 7722279280863371124U;
            aOrbiterE = (aWandererI + RotL64(aScatter, 47U)) + 11584220561732385598U;
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 5U)) + RotL64(aCarry, 23U)) + 7834679350105534657U;
            aOrbiterC = (aWandererK + RotL64(aIngress, 43U)) + 11347994382444180879U;
            aOrbiterD = (aWandererD + RotL64(aCross, 23U)) + 9449903188047063431U;
            aOrbiterK = (aWandererE + RotL64(aIngress, 51U)) + 6516243976652795170U;
            aOrbiterF = (((aWandererH + RotL64(aScatter, 14U)) + RotL64(aCarry, 41U)) + 8420815253991184777U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = (aWandererF + RotL64(aPrevious, 39U)) + 9081386852515170937U;
            aOrbiterJ = ((aWandererG + RotL64(aIngress, 35U)) + 14375955191735286867U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 880757589768436072U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 3349856625725164229U;
            aOrbiterG = RotL64((aOrbiterG * 681514212582331781U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 7826309957607577207U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 8057435761214313635U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4718430712767038607U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 9565237500443303103U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 15893066735310588501U;
            aOrbiterB = RotL64((aOrbiterB * 8457633439171452397U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 3276844534476430842U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 6828644383891274120U;
            aOrbiterC = RotL64((aOrbiterC * 979580351653410157U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 2815676923011504251U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 5030251870850928417U;
            aOrbiterH = RotL64((aOrbiterH * 7075653570570819253U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 13464083008377887034U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 8994560761846897590U;
            aOrbiterJ = RotL64((aOrbiterJ * 9892839554658865143U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 8398813387154468736U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 8136429428340910892U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3348811490733577295U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 418587250696862341U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 4111667833838312094U;
            aOrbiterD = RotL64((aOrbiterD * 860949442143849147U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 6075478294190926371U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 2208124955874142264U;
            aOrbiterK = RotL64((aOrbiterK * 15741988616251072075U), 5U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterE, 43U);
            aIngress = aIngress + (RotL64(aOrbiterF, 6U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterB, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 10U) + RotL64(aOrbiterH, 3U)) + aOrbiterD);
            aWandererF = aWandererF + (((RotL64(aCross, 19U) + RotL64(aOrbiterC, 18U)) + aOrbiterF) + RotL64(aCarry, 21U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterC, 23U)) + aOrbiterD) + aPhaseBWandererUpdateSaltF[((aIndex + 26U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterB, 37U)) + aOrbiterG) + aPhaseBWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 29U) + aOrbiterK) + RotL64(aOrbiterC, 11U));
            aWandererK = aWandererK + ((RotL64(aIngress, 39U) + aOrbiterE) + RotL64(aOrbiterJ, 42U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 5U) + aOrbiterD) + RotL64(aOrbiterJ, 29U));
            aWandererI = aWandererI + (((RotL64(aScatter, 58U) + RotL64(aOrbiterJ, 57U)) + aOrbiterF) + RotL64(aCarry, 13U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterB, 47U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererA);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 58U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererD, 3U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 13685U)) & S_BLOCK1], 23U) ^ RotL64(aInvestLaneA[((aIndex + 13855U)) & S_BLOCK1], 40U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15607U)) & W_KEY1], 23U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 15618U)) & W_KEY1], 39U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 13708U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 15669U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 15801U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aPrevious, 41U)) ^ (RotL64(aIngress, 24U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = ((aWandererH + RotL64(aIngress, 48U)) + RotL64(aCarry, 35U)) + 3339283916456813609U;
            aOrbiterH = (aWandererA + RotL64(aPrevious, 19U)) + 11339086426180649584U;
            aOrbiterE = (aWandererI + RotL64(aCross, 39U)) + 16819191669329316585U;
            aOrbiterI = (aWandererD + RotL64(aScatter, 11U)) + 8361916937762630725U;
            aOrbiterG = (aWandererG + RotL64(aIngress, 34U)) + 18031328374429899857U;
            aOrbiterJ = (((aWandererJ + RotL64(aCross, 3U)) + RotL64(aCarry, 43U)) + 18261756894092897276U) + aPhaseBOrbiterAssignSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = (aWandererB + RotL64(aPrevious, 43U)) + 4250319792907645666U;
            aOrbiterF = ((aWandererE + RotL64(aScatter, 29U)) + RotL64(aCarry, 27U)) + 1492411503643460886U;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 23U)) + 17369549067879344180U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 7301713524358676722U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 2985193736033012535U;
            aOrbiterE = RotL64((aOrbiterE * 7473297294949338265U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 14086975808140927408U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 10390516547834639800U;
            aOrbiterG = RotL64((aOrbiterG * 11441293212275890819U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 18205555540941493267U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 16967799565443938873U;
            aOrbiterA = RotL64((aOrbiterA * 3009081009044782443U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 9209505304067579944U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 3522631966146762306U;
            aOrbiterF = RotL64((aOrbiterF * 3441982898533162599U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 8811497120829041188U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 14707301680850257294U;
            aOrbiterJ = RotL64((aOrbiterJ * 11383709499376464085U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 10080595991787801029U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 6822892187784299166U;
            aOrbiterH = RotL64((aOrbiterH * 7417016898027778287U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 1981637172055758689U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 16463077485583119324U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2876782050665869121U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 8383837717361569465U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 2788511294985017326U;
            aOrbiterK = RotL64((aOrbiterK * 2809163242875130677U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 3529607472855930041U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 8850940802020173766U;
            aOrbiterI = RotL64((aOrbiterI * 7821450253655655943U), 51U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterF, 51U);
            aIngress = aIngress + (RotL64(aOrbiterK, 19U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterI, 38U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 43U));
            aIngress = aIngress + RotL64(aOrbiterJ, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterK, 19U)) + aOrbiterJ);
            aWandererE = aWandererE + ((RotL64(aIngress, 57U) + RotL64(aOrbiterE, 13U)) + aOrbiterC);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 22U) + RotL64(aOrbiterK, 5U)) + aOrbiterG);
            aWandererA = aWandererA + ((((RotL64(aScatter, 29U) + RotL64(aOrbiterE, 39U)) + aOrbiterI) + RotL64(aCarry, 23U)) + aPhaseBWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterI, 58U)) + aOrbiterJ);
            aWandererH = aWandererH + ((RotL64(aScatter, 47U) + aOrbiterC) + RotL64(aOrbiterA, 47U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 52U) + aOrbiterF) + RotL64(aOrbiterA, 23U));
            aWandererD = aWandererD + ((((RotL64(aIngress, 5U) + RotL64(aOrbiterI, 35U)) + aOrbiterC) + RotL64(aCarry, 51U)) + aPhaseBWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 11U) + aOrbiterK) + RotL64(aOrbiterH, 28U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 5U));
            aCarry = aCarry + (RotL64(aWandererI, 39U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererG, 35U);
            aCarry = aCarry + RotL64(aIngress, 50U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 19106U)) & S_BLOCK1], 11U) ^ RotL64(aKeyRowReadA[((aIndex + 18247U)) & W_KEY1], 39U));
            aIngress ^= (RotL64(mSource[((aIndex + 17679U)) & S_BLOCK1], 52U) ^ RotL64(aWorkLaneA[((aIndex + 16627U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 16658U)) & W_KEY1], 57U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 18834U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 18325U)) & S_BLOCK1], 42U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aPrevious, 19U)) ^ (RotL64(aCarry, 56U) + RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = (aWandererE + RotL64(aCross, 39U)) + 2672739400294801233U;
            aOrbiterA = (aWandererB + RotL64(aScatter, 23U)) + 8475624545015101850U;
            aOrbiterF = (((aWandererC + RotL64(aIngress, 54U)) + RotL64(aCarry, 51U)) + 1252755112289831257U) + aPhaseCOrbiterAssignSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterB = (aWandererK + RotL64(aPrevious, 47U)) + 7938039507649183387U;
            aOrbiterD = (aWandererA + RotL64(aScatter, 13U)) + 8167413146948861022U;
            aOrbiterI = (aWandererH + RotL64(aCross, 5U)) + 17712313989694374353U;
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 35U)) + RotL64(aCarry, 43U)) + 7637042279892596975U;
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 27U)) + 15770412950033467341U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = ((aWandererG + RotL64(aScatter, 60U)) + RotL64(aCarry, 19U)) + 3951812021898608685U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 8656983621098246507U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 17943342344730687317U;
            aOrbiterF = RotL64((aOrbiterF * 16495519451034883813U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 3087677463651608668U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 16493240011924342788U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16898479041530771871U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 7750923317452683057U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 2185924841611106546U;
            aOrbiterA = RotL64((aOrbiterA * 708072658250726381U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 14676868738946722416U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 6849098251696302393U;
            aOrbiterE = RotL64((aOrbiterE * 2599806275837778069U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 17817755047153606419U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 9900465270314068757U;
            aOrbiterB = RotL64((aOrbiterB * 9267925873983176685U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 11380000891112113701U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 15930503831156546113U;
            aOrbiterG = RotL64((aOrbiterG * 14450535035065393845U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 5439183530402949780U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 3731802052051181843U;
            aOrbiterI = RotL64((aOrbiterI * 7739775058947333169U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 14432344583247783600U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 16192098795467501636U;
            aOrbiterC = RotL64((aOrbiterC * 6285466374319549047U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 1523272672673940290U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 7462092373525113574U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15067751170235540679U), 41U);
            //
            aIngress = RotL64(aOrbiterD, 50U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 13U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 5U));
            aIngress = aIngress + (RotL64(aOrbiterA, 43U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterE, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aScatter, 23U) + RotL64(aOrbiterA, 27U)) + aOrbiterD) + RotL64(aCarry, 3U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 58U) + RotL64(aOrbiterD, 14U)) + aOrbiterC);
            aWandererG = aWandererG + ((RotL64(aPrevious, 37U) + RotL64(aOrbiterJ, 43U)) + aOrbiterD);
            aWandererB = aWandererB ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterI, 47U)) + aOrbiterJ) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 53U) + RotL64(aOrbiterI, 35U)) + aOrbiterF) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterC, 23U)) + aOrbiterF);
            aWandererE = aWandererE + ((RotL64(aCross, 4U) + aOrbiterB) + RotL64(aOrbiterJ, 3U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 41U) + aOrbiterJ) + RotL64(aOrbiterE, 60U));
            aWandererC = aWandererC + (((RotL64(aCross, 19U) + aOrbiterE) + RotL64(aOrbiterG, 19U)) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 41U));
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererK, 6U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 19882U)) & S_BLOCK1], 5U) ^ RotL64(mSource[((aIndex + 21283U)) & S_BLOCK1], 60U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 21461U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((aIndex + 21397U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 21313U)) & W_KEY1], 23U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 21019U)) & W_KEY1], 13U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 21822U)) & S_BLOCK1], 36U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21477U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 41U) + RotL64(aCarry, 29U)) ^ (RotL64(aIngress, 11U) + RotL64(aCross, 60U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 27U)) + RotL64(aCarry, 23U)) + 6361545377408870615U;
            aOrbiterH = (aWandererE + RotL64(aIngress, 43U)) + 2967245486744774933U;
            aOrbiterF = (aWandererG + RotL64(aCross, 53U)) + 3836634268482850139U;
            aOrbiterB = ((aWandererA + RotL64(aScatter, 23U)) + RotL64(aCarry, 11U)) + 7691642115360086297U;
            aOrbiterA = (aWandererF + RotL64(aCross, 12U)) + 16479280384178279281U;
            aOrbiterE = ((aWandererK + RotL64(aIngress, 19U)) + 2901468732552539249U) + aPhaseCOrbiterAssignSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = (aWandererI + RotL64(aPrevious, 47U)) + 2600353867755647475U;
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 35U)) + 5666596904781510956U) + aPhaseCOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = ((aWandererB + RotL64(aIngress, 4U)) + RotL64(aCarry, 39U)) + 16108791609267427553U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 8389926875737312112U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 1689501721163024426U;
            aOrbiterF = RotL64((aOrbiterF * 6517194895779049139U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 11721701506949917719U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 3963842745030140473U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6692473494944919373U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 8510538243472109368U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 18281865214102080387U;
            aOrbiterK = RotL64((aOrbiterK * 1351546966368884609U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 2259725140963665123U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 11652011949557979650U;
            aOrbiterJ = RotL64((aOrbiterJ * 11260100762113295037U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 1116085424226174473U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 4725260319270802912U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4697109059565450269U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 7348945429843437036U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 1249234309180653260U;
            aOrbiterB = RotL64((aOrbiterB * 3136745255820405881U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 12463505532573389603U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 2304125977906510386U;
            aOrbiterC = RotL64((aOrbiterC * 9960816714791454421U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 2178037443783425551U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 11712110130079307683U;
            aOrbiterH = RotL64((aOrbiterH * 9797864956200779505U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 10703510612147312252U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 18155460326242413483U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6903953708987478723U), 47U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterF, 24U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 43U));
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterJ, 21U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterK, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aScatter, 37U) + RotL64(aOrbiterF, 50U)) + aOrbiterI);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 60U) + RotL64(aOrbiterJ, 35U)) + aOrbiterK);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 29U) + RotL64(aOrbiterI, 57U)) + aOrbiterE);
            aWandererB = aWandererB ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterE, 3U)) + aOrbiterJ) + aPhaseCWandererUpdateSaltF[((aIndex + 10U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterB, 23U)) + aOrbiterA) + RotL64(aCarry, 3U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterC, 39U)) + aOrbiterE) + aPhaseCWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 19U) + RotL64(aOrbiterJ, 29U)) + aOrbiterI) + RotL64(aCarry, 11U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 23U) + aOrbiterE) + RotL64(aOrbiterH, 19U));
            aWandererC = aWandererC + ((RotL64(aIngress, 50U) + RotL64(aOrbiterB, 10U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (RotL64(aWandererC, 26U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 39U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererB, 5U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 22032U)) & S_BLOCK1], 5U) ^ RotL64(aKeyRowReadA[((aIndex + 24391U)) & W_KEY1], 26U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 22888U)) & W_KEY1], 43U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 24097U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 23479U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 24044U)) & S_BLOCK1], 58U));
            aCross ^= (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 23850U)) & S_BLOCK1], 39U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 23432U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 3U) + RotL64(aCross, 21U)) + (RotL64(aCarry, 54U) ^ RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = (aWandererH + RotL64(aCross, 52U)) + 1898718075389870739U;
            aOrbiterJ = (aWandererI + RotL64(aScatter, 19U)) + 5631794889237247403U;
            aOrbiterI = (((aWandererC + RotL64(aPrevious, 43U)) + RotL64(aCarry, 19U)) + 18219714659484524607U) + aPhaseCOrbiterAssignSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = (aWandererA + RotL64(aIngress, 13U)) + 15419581386225732921U;
            aOrbiterE = ((aWandererB + RotL64(aCross, 39U)) + RotL64(aCarry, 11U)) + 9125575431710198210U;
            aOrbiterH = (aWandererD + RotL64(aScatter, 3U)) + 12205871520544965505U;
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 26U)) + 7617534300497343422U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = (aWandererE + RotL64(aIngress, 57U)) + 18017579105368135814U;
            aOrbiterC = ((aWandererK + RotL64(aScatter, 35U)) + RotL64(aCarry, 29U)) + 10693882161946020042U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 11669615701700895306U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 11045110212889232165U;
            aOrbiterI = RotL64((aOrbiterI * 5965171269273719849U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 18019107802806469913U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 12315940560472528716U;
            aOrbiterH = RotL64((aOrbiterH * 4505122470351404065U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 4899009736070044310U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 17412253404253730364U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10791901166391946485U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 4826286251927854181U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 4523455921321845084U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14534103906736598099U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 4132514462154182215U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 7164745605985109269U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14107325508977225261U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 6297434295807635654U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 8813887638672996646U;
            aOrbiterD = RotL64((aOrbiterD * 17495632530773158201U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 11086381278955626084U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 5660733992573928887U;
            aOrbiterA = RotL64((aOrbiterA * 11248164458720777889U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 14851044686208609882U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 12707776386060264479U;
            aOrbiterC = RotL64((aOrbiterC * 4470919091467313071U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 11508023384209716657U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 11752973809740920034U;
            aOrbiterF = RotL64((aOrbiterF * 10212754472298834769U), 3U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterC, 53U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 43U));
            aIngress = aIngress + (RotL64(aOrbiterF, 12U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 19U));
            aIngress = aIngress + RotL64(aOrbiterI, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aCross, 60U) + RotL64(aOrbiterJ, 6U)) + aOrbiterB);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 5U) + aOrbiterE) + RotL64(aOrbiterF, 43U)) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterI, 23U)) + aOrbiterJ);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 19U) + aOrbiterH) + RotL64(aOrbiterE, 19U)) + aPhaseCWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 35U) + RotL64(aOrbiterE, 57U)) + aOrbiterD) + RotL64(aCarry, 27U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 28U) + RotL64(aOrbiterJ, 37U)) + aOrbiterA);
            aWandererK = aWandererK + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterI, 47U)) + aOrbiterC) + RotL64(aCarry, 39U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterA, 11U)) + aOrbiterE);
            aWandererC = aWandererC + ((RotL64(aPrevious, 23U) + aOrbiterC) + RotL64(aOrbiterF, 28U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 6U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererH, 29U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 26253U)) & S_BLOCK1], 19U) ^ RotL64(aKeyRowReadA[((aIndex + 26055U)) & W_KEY1], 41U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 25796U)) & S_BLOCK1], 6U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 26156U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 25580U)) & W_KEY1], 3U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 26848U)) & S_BLOCK1], 29U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 24874U)) & S_BLOCK1], 38U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 26499U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 35U) ^ RotL64(aPrevious, 54U)) + (RotL64(aIngress, 21U) ^ RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = ((aWandererH + RotL64(aScatter, 46U)) + 14008824488073394623U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = (aWandererK + RotL64(aIngress, 19U)) + 13317978415866411468U;
            aOrbiterC = (aWandererJ + RotL64(aPrevious, 23U)) + 13209180141897453900U;
            aOrbiterD = ((aWandererE + RotL64(aCross, 3U)) + RotL64(aCarry, 39U)) + 11870521586865233578U;
            aOrbiterA = ((aWandererB + RotL64(aIngress, 57U)) + 8052156380448047385U) + aPhaseDOrbiterAssignSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterB = (aWandererI + RotL64(aScatter, 13U)) + 12158131176743680605U;
            aOrbiterG = (aWandererG + RotL64(aCross, 35U)) + 14674467487607719347U;
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 52U)) + RotL64(aCarry, 13U)) + 18055496790566231147U;
            aOrbiterE = ((aWandererA + RotL64(aScatter, 39U)) + RotL64(aCarry, 29U)) + 3838105585041578784U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 2839568255183054418U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 11933612922864258179U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7571964469321160347U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 6289849094151630580U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 2640344350528492271U;
            aOrbiterA = RotL64((aOrbiterA * 16197726750829369365U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 16306175266267657791U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 3339898380394883600U;
            aOrbiterJ = RotL64((aOrbiterJ * 7105436590182982373U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 15017076663742800002U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 8973064296077602496U;
            aOrbiterB = RotL64((aOrbiterB * 9309462227233615761U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 17580319233338139859U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 14063208878807603874U;
            aOrbiterG = RotL64((aOrbiterG * 16601475239075164585U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 13326130855721009942U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 12843186026737544416U;
            aOrbiterE = RotL64((aOrbiterE * 4975848122837321619U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 14102887715772847499U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 14495942314329085733U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4236795312917583565U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 11564857125101669667U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 17435970784822000464U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1472691848852381173U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 16561390130356833062U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 9952805588514363872U;
            aOrbiterI = RotL64((aOrbiterI * 3720874990001086597U), 29U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterG, 11U);
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 54U));
            aIngress = aIngress + (RotL64(aOrbiterD, 35U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterE, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterE, 57U)) + aOrbiterH);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 19U) + aOrbiterG) + RotL64(aOrbiterB, 29U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 28U) + aOrbiterA) + RotL64(aOrbiterG, 14U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterH, 53U)) + aOrbiterC);
            aWandererG = aWandererG + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterD, 19U)) + aOrbiterJ);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 5U) + aOrbiterB) + RotL64(aOrbiterD, 41U));
            aWandererB = aWandererB + ((((RotL64(aScatter, 58U) + aOrbiterI) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 13U)) + aPhaseDWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 41U) + aOrbiterA) + RotL64(aOrbiterC, 24U));
            aWandererI = aWandererI + (((RotL64(aIngress, 11U) + RotL64(aOrbiterH, 35U)) + aOrbiterJ) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererF);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 28U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererE, 43U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 27946U)) & S_BLOCK1], 39U) ^ RotL64(aFireLaneD[((aIndex + 28744U)) & S_BLOCK1], 13U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 29692U)) & W_KEY1], 27U) ^ RotL64(aFireLaneC[((aIndex + 28417U)) & S_BLOCK1], 50U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 28939U)) & W_KEY1], 57U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 27686U)) & S_BLOCK1], 41U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27486U)) & S_BLOCK1], 24U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 27884U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aIngress, 23U)) ^ (RotL64(aPrevious, 56U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = (aWandererK + RotL64(aPrevious, 10U)) + 2101601659597850213U;
            aOrbiterA = (((aWandererJ + RotL64(aIngress, 39U)) + RotL64(aCarry, 3U)) + 2759794072560720121U) + aPhaseDOrbiterAssignSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterH = (aWandererD + RotL64(aScatter, 43U)) + 9443562552411269339U;
            aOrbiterF = (aWandererB + RotL64(aCross, 47U)) + 10801360546699857975U;
            aOrbiterG = (aWandererH + RotL64(aIngress, 19U)) + 8020716394829332019U;
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 27U)) + RotL64(aCarry, 29U)) + 1021894212367773801U;
            aOrbiterJ = ((aWandererE + RotL64(aCross, 6U)) + RotL64(aCarry, 21U)) + 13346855534622490176U;
            aOrbiterC = ((aWandererG + RotL64(aScatter, 23U)) + 16359309548462953836U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = (aWandererC + RotL64(aPrevious, 51U)) + 12642446944680783519U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 8197424982767553380U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 14346334610901859094U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16982899923227935679U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 14171304260534233539U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 334531601308283605U;
            aOrbiterI = RotL64((aOrbiterI * 5012968232749075075U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 10707856298471572695U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 18364775750091914766U;
            aOrbiterJ = RotL64((aOrbiterJ * 15735143943129143265U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 8531394793118363836U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 15352876929406908882U;
            aOrbiterK = RotL64((aOrbiterK * 475199047053777179U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 567682016232278157U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 2068146551757663119U;
            aOrbiterF = RotL64((aOrbiterF * 1557877740957797555U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 7776122587613256525U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 16430938890724272256U;
            aOrbiterG = RotL64((aOrbiterG * 4540270493783593257U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 11912000645055436094U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 16800749242578741498U;
            aOrbiterA = RotL64((aOrbiterA * 17804584625034241737U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 5909199180260499150U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 5751089915336865588U;
            aOrbiterE = RotL64((aOrbiterE * 15376689503142397927U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 3478216857728853008U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 18007567146937338241U;
            aOrbiterC = RotL64((aOrbiterC * 6620498877303917855U), 43U);
            //
            aIngress = RotL64(aOrbiterI, 30U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 11U));
            aIngress = aIngress + (RotL64(aOrbiterK, 21U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterH, 51U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterF, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 48U) + aOrbiterK) + RotL64(aOrbiterE, 5U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 11U) + aOrbiterJ) + RotL64(aOrbiterF, 27U)) + RotL64(aCarry, 3U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterJ, 41U)) + aOrbiterG);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 19U) + aOrbiterI) + RotL64(aOrbiterF, 52U)) + aPhaseDWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterC, 23U)) + aOrbiterH);
            aWandererG = aWandererG + (((RotL64(aIngress, 23U) + aOrbiterG) + RotL64(aOrbiterF, 47U)) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 54U) + aOrbiterH) + RotL64(aOrbiterI, 11U));
            aWandererK = aWandererK + ((RotL64(aScatter, 37U) + aOrbiterI) + RotL64(aOrbiterA, 57U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 36U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererH);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererF, 10U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 31423U)) & S_BLOCK1], 53U) ^ RotL64(aKeyRowReadA[((aIndex + 30043U)) & W_KEY1], 24U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 32641U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32067U)) & S_BLOCK1], 57U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32109U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 31146U)) & W_KEY1], 27U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 21U) + RotL64(aIngress, 5U)) ^ (RotL64(aPrevious, 51U) + RotL64(aCross, 34U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = (aWandererE + RotL64(aIngress, 40U)) + 1087148170018530502U;
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 51U)) + 15530846874509311414U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterC = (aWandererH + RotL64(aCross, 19U)) + 16987358651515511212U;
            aOrbiterI = ((aWandererD + RotL64(aScatter, 47U)) + RotL64(aCarry, 13U)) + 12504143181007924259U;
            aOrbiterD = (aWandererB + RotL64(aIngress, 5U)) + 393322117322732418U;
            aOrbiterJ = (aWandererJ + RotL64(aScatter, 13U)) + 14325937299241887166U;
            aOrbiterE = (aWandererF + RotL64(aPrevious, 29U)) + 9395262907017475742U;
            aOrbiterK = ((aWandererI + RotL64(aCross, 56U)) + RotL64(aCarry, 21U)) + 13658510441418344769U;
            aOrbiterB = (((aWandererC + RotL64(aIngress, 23U)) + RotL64(aCarry, 35U)) + 6410754322737005336U) + aPhaseDOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 9257290738538818434U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 7489828960857692286U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16519674788777989043U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 4118778591214588387U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 16619215231168796563U;
            aOrbiterD = RotL64((aOrbiterD * 14876884956536265157U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 11326283811003573430U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 1865401866017614604U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8378326058282460073U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 670150121105733604U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 1499331510641068749U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16623742535540383107U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 1116410848560838532U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 2696841341036281779U;
            aOrbiterI = RotL64((aOrbiterI * 9598953298074904869U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 5487352391229549881U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 12008243050943342979U;
            aOrbiterJ = RotL64((aOrbiterJ * 9087261224804582459U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 552859665927882960U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 8426942688524814473U;
            aOrbiterK = RotL64((aOrbiterK * 10916963622695549105U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 1613287981244830815U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 15592897923468694288U;
            aOrbiterE = RotL64((aOrbiterE * 6600750586743893303U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 7629853970631002676U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 13778028957247561272U;
            aOrbiterB = RotL64((aOrbiterB * 4063798788229605659U), 41U);
            //
            aIngress = RotL64(aOrbiterK, 5U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 19U));
            aIngress = aIngress + (RotL64(aOrbiterE, 47U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterI, 60U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterC, 39U)) + aOrbiterD);
            aWandererF = aWandererF + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterB, 3U)) + aOrbiterI) + RotL64(aCarry, 53U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 60U) + RotL64(aOrbiterD, 47U)) + aOrbiterK) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 41U) + aOrbiterD) + RotL64(aOrbiterB, 27U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 27U) + aOrbiterJ) + RotL64(aOrbiterD, 54U)) + aPhaseDWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aCross, 23U) + aOrbiterE) + RotL64(aOrbiterF, 35U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 11U) + aOrbiterJ) + RotL64(aOrbiterE, 11U));
            aWandererE = aWandererE + (((RotL64(aScatter, 47U) + aOrbiterG) + RotL64(aOrbiterD, 23U)) + RotL64(aCarry, 35U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 56U) + aOrbiterC) + RotL64(aOrbiterJ, 60U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 46U) ^ aWandererC);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 41U));
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererI, 5U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererJ, 53U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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

void TwistExpander_BasketBall_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 2077U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneB[((aIndex + 5442U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 363U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1952U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 4480U)) & S_BLOCK1], 36U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 3U) + RotL64(aCarry, 21U)) + (RotL64(aCross, 54U) ^ RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = ((aWandererK + RotL64(aCross, 21U)) + RotL64(aCarry, 21U)) + 16200278595895089008U;
            aOrbiterD = (aWandererB + RotL64(aIngress, 35U)) + 1029614154810465897U;
            aOrbiterC = (((aWandererH + RotL64(aScatter, 27U)) + RotL64(aCarry, 39U)) + 7129562468705441295U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = (((aWandererA + RotL64(aPrevious, 11U)) + RotL64(aCarry, 57U)) + 14388903902433951274U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = (aWandererJ + RotL64(aCross, 5U)) + 1013568949315967455U;
            aOrbiterF = (aWandererF + RotL64(aPrevious, 56U)) + 3128823373497815651U;
            aOrbiterG = (aWandererD + RotL64(aScatter, 41U)) + 14525694606889470589U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 14443983602196782887U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 12244220415328641190U;
            aOrbiterC = RotL64((aOrbiterC * 15052949098014803181U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 10477159225338766614U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 2842870123078131566U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11522265477555954071U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 8621138818955849917U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 5038396344400303181U;
            aOrbiterB = RotL64((aOrbiterB * 14636756322207385447U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 2768613802894372496U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 2027754864051410015U;
            aOrbiterG = RotL64((aOrbiterG * 2461322540050569287U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 2848088309172056399U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 15017458513904884651U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9926904679902843055U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 9079797279596336139U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 15424866642305110811U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12912331089970158845U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 13751764050290602740U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 7694557131324740282U;
            aOrbiterD = RotL64((aOrbiterD * 14980807690491467023U), 51U);
            //
            aIngress = RotL64(aOrbiterD, 29U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterB, 43U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterI, 35U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterF, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterI, 30U)) + aOrbiterC);
            aWandererB = aWandererB + (((RotL64(aPrevious, 57U) + aOrbiterD) + RotL64(aOrbiterG, 37U)) + aPhaseEWandererUpdateSaltA[((aIndex + 4U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 42U) + RotL64(aOrbiterB, 5U)) + aOrbiterF);
            aWandererD = aWandererD + ((((RotL64(aScatter, 3U) + aOrbiterI) + RotL64(aOrbiterF, 57U)) + RotL64(aCarry, 5U)) + aPhaseEWandererUpdateSaltD[((aIndex + 28U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 35U) + aOrbiterA) + RotL64(aOrbiterB, 19U));
            aWandererK = aWandererK + (((RotL64(aCross, 51U) + aOrbiterB) + RotL64(aOrbiterG, 43U)) + RotL64(aCarry, 51U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 27U) + aOrbiterC) + RotL64(aOrbiterB, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererF);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 36U));
            aCarry = aCarry + RotL64(aWandererB, 27U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 9759U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneC[((aIndex + 9123U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 7932U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 6286U)) & S_BLOCK1], 44U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 8620U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 35U) + RotL64(aCarry, 54U)) ^ (RotL64(aIngress, 21U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 57U)) + RotL64(aCarry, 47U)) + 11998579547770778580U;
            aOrbiterJ = ((aWandererD + RotL64(aCross, 51U)) + RotL64(aCarry, 27U)) + 8409465187298704610U;
            aOrbiterG = (aWandererI + RotL64(aScatter, 36U)) + 3470222286110333500U;
            aOrbiterE = (((aWandererG + RotL64(aIngress, 43U)) + RotL64(aCarry, 13U)) + 5704486785203069994U) + aPhaseEOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = ((aWandererC + RotL64(aCross, 3U)) + 10334944660253279633U) + aPhaseEOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = (aWandererB + RotL64(aIngress, 27U)) + 7626852700722567477U;
            aOrbiterC = (aWandererA + RotL64(aScatter, 13U)) + 14631310754943209743U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 807160297237854120U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 5624154783624196107U;
            aOrbiterG = RotL64((aOrbiterG * 2404066593958052159U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 4971444394698940423U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 6340057638461027062U;
            aOrbiterJ = RotL64((aOrbiterJ * 12027586111086798629U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 9003019862787819481U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 13632057463595873033U;
            aOrbiterH = RotL64((aOrbiterH * 12575202147280216765U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 12766104026871797746U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 4062118445824915939U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13130770039048080701U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 5258212525426469978U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 9956946981015983939U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8106382657040497669U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 10837606223056473999U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 13292864885504191134U;
            aOrbiterA = RotL64((aOrbiterA * 4445739587553669471U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 166087925900318658U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 6786842221885441388U;
            aOrbiterC = RotL64((aOrbiterC * 4411147600413147773U), 29U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterE, 53U);
            aIngress = aIngress + (RotL64(aOrbiterA, 30U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterG, 37U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterJ, 51U)) + aOrbiterC) + aPhaseEWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterE, 44U)) + aOrbiterJ) + RotL64(aCarry, 53U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 54U) + aOrbiterJ) + RotL64(aOrbiterF, 29U));
            aWandererB = aWandererB + (((RotL64(aCross, 11U) + RotL64(aOrbiterA, 3U)) + aOrbiterF) + RotL64(aCarry, 27U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterH, 35U)) + aOrbiterG);
            aWandererI = aWandererI + (((RotL64(aScatter, 29U) + aOrbiterC) + RotL64(aOrbiterH, 21U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterF, 13U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererA, 14U) ^ aWandererG);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + RotL64(aWandererC, 51U);
            aCarry = aCarry + RotL64(aIngress, 58U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aInvestLaneD[((aIndex + 11272U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneD[((aIndex + 12614U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 12426U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 16294U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 12378U)) & S_BLOCK1], 54U));
            aCross ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 12541U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 37U) + RotL64(aCross, 52U)) ^ (RotL64(aCarry, 3U) ^ RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = (aWandererB + RotL64(aCross, 21U)) + 5960680319644404115U;
            aOrbiterI = (((aWandererI + RotL64(aScatter, 3U)) + RotL64(aCarry, 5U)) + 16050752633567034185U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = (((aWandererK + RotL64(aPrevious, 51U)) + RotL64(aCarry, 41U)) + 8447503223226854741U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = ((aWandererC + RotL64(aIngress, 13U)) + RotL64(aCarry, 19U)) + 14176813813397917591U;
            aOrbiterB = (aWandererJ + RotL64(aScatter, 57U)) + 10534915376130006644U;
            aOrbiterJ = (aWandererG + RotL64(aCross, 29U)) + 6866224454375302514U;
            aOrbiterE = (aWandererF + RotL64(aPrevious, 40U)) + 16506374165041008396U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 7167814023968794098U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 13870852197416596664U;
            aOrbiterG = RotL64((aOrbiterG * 17015971222069856463U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 18064038854848993105U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 9869630811507771691U;
            aOrbiterJ = RotL64((aOrbiterJ * 13723164383800461387U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 863613100452759380U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 16597969741225436529U;
            aOrbiterI = RotL64((aOrbiterI * 2680793528887208903U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 6575347108051310653U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 17062262265485019063U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7601045488473620019U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 7193399224636409133U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 14146747818810433849U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5273185769989530041U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 9441449106442431427U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 4303295336545399503U;
            aOrbiterE = RotL64((aOrbiterE * 8829695296836242587U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 12604760768543193458U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 15779327512379787715U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14000905201441272597U), 29U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterD, 29U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 37U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 43U));
            aIngress = aIngress + RotL64(aOrbiterG, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aCross, 13U) + aOrbiterG) + RotL64(aOrbiterD, 13U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterF, 35U)) + aOrbiterE);
            aWandererF = aWandererF + ((RotL64(aScatter, 21U) + RotL64(aOrbiterF, 21U)) + aOrbiterG);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterI, 28U)) + aOrbiterE) + aPhaseEWandererUpdateSaltC[((aIndex + 12U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 4U) + aOrbiterE) + RotL64(aOrbiterJ, 53U)) + RotL64(aCarry, 23U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterJ, 41U)) + aOrbiterF);
            aWandererB = aWandererB + ((((RotL64(aIngress, 35U) + aOrbiterE) + RotL64(aOrbiterB, 5U)) + RotL64(aCarry, 51U)) + aPhaseEWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 46U));
            aCarry = aCarry + RotL64(aWandererK, 51U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 20561U)) & S_BLOCK1], 57U) ^ RotL64(aInvestLaneC[((aIndex + 17263U)) & S_BLOCK1], 22U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 17651U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 19199U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18795U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 19209U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 24U)) + (RotL64(aCross, 41U) ^ RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = (aWandererE + RotL64(aCross, 3U)) + 6342299552323486695U;
            aOrbiterB = ((aWandererD + RotL64(aScatter, 51U)) + 12692748514781367538U) + aPhaseEOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = ((aWandererH + RotL64(aIngress, 41U)) + 8202639945493229155U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 57U)) + RotL64(aCarry, 47U)) + 4439975701793231639U;
            aOrbiterJ = ((aWandererB + RotL64(aScatter, 21U)) + RotL64(aCarry, 23U)) + 16774235182859553759U;
            aOrbiterG = (aWandererA + RotL64(aCross, 10U)) + 8764155413335405667U;
            aOrbiterA = ((aWandererC + RotL64(aIngress, 29U)) + RotL64(aCarry, 11U)) + 7167848811974967685U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 16768278912125334220U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 9090838954826296201U;
            aOrbiterE = RotL64((aOrbiterE * 5459329624017272077U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 7644075729758006298U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 17326182797908071215U;
            aOrbiterB = RotL64((aOrbiterB * 2408330168749256075U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 16158809721888137555U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 8029938783858263694U;
            aOrbiterJ = RotL64((aOrbiterJ * 12628072435324195483U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 8716553521415553404U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 7012599977009208840U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8775355876188948851U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 13250558696578541499U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 13705957059101025396U;
            aOrbiterC = RotL64((aOrbiterC * 16889495686487056367U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 2796775206291902461U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 13741676263512390669U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10455782033465595947U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 1691908360612389252U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 4114939415206031540U;
            aOrbiterA = RotL64((aOrbiterA * 2797401802892718297U), 41U);
            //
            aIngress = RotL64(aOrbiterG, 23U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterJ, 47U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 35U));
            aIngress = aIngress + RotL64(aOrbiterB, 14U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterG, 29U)) + aOrbiterD);
            aWandererH = aWandererH ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterE, 13U)) + aOrbiterC);
            aWandererA = aWandererA + ((((RotL64(aScatter, 29U) + aOrbiterE) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 23U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterD, 53U)) + aOrbiterC) + aPhaseEWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aScatter, 51U) + aOrbiterD) + RotL64(aOrbiterA, 46U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 36U) + RotL64(aOrbiterG, 37U)) + aOrbiterJ);
            aWandererD = aWandererD + (((RotL64(aIngress, 13U) + RotL64(aOrbiterA, 19U)) + aOrbiterG) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 60U));
            aCarry = aCarry + (RotL64(aWandererB, 13U) ^ aWandererH);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + RotL64(aWandererE, 19U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 25089U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneA[((aIndex + 22134U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 25948U)) & S_BLOCK1], 34U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 26336U)) & S_BLOCK1], 3U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 24762U)) & S_BLOCK1], 22U));
            aCross ^= RotL64(aInvestLaneD[((aIndex + 27241U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 40U) + RotL64(aPrevious, 19U)) ^ (RotL64(aIngress, 5U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = (aWandererE + RotL64(aScatter, 11U)) + 17936518874386450467U;
            aOrbiterB = (((aWandererC + RotL64(aIngress, 35U)) + RotL64(aCarry, 23U)) + 13722737841589910344U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 43U)) + RotL64(aCarry, 41U)) + 11774969167948715796U;
            aOrbiterI = (aWandererH + RotL64(aCross, 27U)) + 3640101505680493777U;
            aOrbiterG = (aWandererB + RotL64(aScatter, 3U)) + 1369495382725650822U;
            aOrbiterJ = ((aWandererK + RotL64(aCross, 19U)) + RotL64(aCarry, 53U)) + 11827310354654653345U;
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 58U)) + 186037671377175394U) + aPhaseEOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 11428829344234627340U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 2275016369870029068U;
            aOrbiterD = RotL64((aOrbiterD * 14936799202145280833U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 15471646673734798328U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 12172082573115640145U;
            aOrbiterG = RotL64((aOrbiterG * 9629417882787847753U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 6626736341348283154U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 12220614992483863623U;
            aOrbiterB = RotL64((aOrbiterB * 8137086205714097487U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 13157102324253760215U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 4143587482368093601U;
            aOrbiterH = RotL64((aOrbiterH * 5060677690991506895U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 11007575246013796426U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 11721585930088637162U;
            aOrbiterJ = RotL64((aOrbiterJ * 15009627907125738519U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 5720789204450196217U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 3094696226821431648U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4412033981712165541U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 14675830108100986773U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 9444071495289719645U;
            aOrbiterI = RotL64((aOrbiterI * 10983136361953366557U), 47U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterJ, 47U);
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterF, 57U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterD, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aIngress, 13U) + RotL64(aOrbiterG, 37U)) + aOrbiterF) + RotL64(aCarry, 11U)) + aPhaseEWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 29U) + aOrbiterI) + RotL64(aOrbiterH, 23U));
            aWandererC = aWandererC + ((RotL64(aScatter, 51U) + aOrbiterH) + RotL64(aOrbiterD, 13U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 57U) + aOrbiterD) + RotL64(aOrbiterB, 43U));
            aWandererH = aWandererH + (((RotL64(aCross, 23U) + RotL64(aOrbiterH, 60U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 38U) + RotL64(aOrbiterH, 5U)) + aOrbiterF);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 5U) + RotL64(aOrbiterH, 51U)) + aOrbiterG) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + RotL64(aWandererI, 56U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 31918U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneA[((aIndex + 29952U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 27947U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31765U)) & S_BLOCK1], 34U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 30076U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 32625U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 6U) ^ RotL64(aCarry, 47U)) + (RotL64(aCross, 35U) ^ RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = (((aWandererD + RotL64(aIngress, 30U)) + RotL64(aCarry, 19U)) + 9435962834163239322U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = ((aWandererE + RotL64(aScatter, 23U)) + RotL64(aCarry, 51U)) + 10524704356081318973U;
            aOrbiterI = (aWandererC + RotL64(aPrevious, 41U)) + 7403401305665208680U;
            aOrbiterG = (aWandererF + RotL64(aCross, 57U)) + 7525414805023556493U;
            aOrbiterA = (aWandererJ + RotL64(aIngress, 47U)) + 1116686470029070951U;
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 5U)) + 13257612299137802420U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = ((aWandererI + RotL64(aCross, 13U)) + RotL64(aCarry, 5U)) + 9181543003986598283U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 9739384852307501107U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 11308402900229016057U;
            aOrbiterI = RotL64((aOrbiterI * 12690186771773188967U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 14935167593705272337U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 7171824007631943535U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4839974427616194289U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 8068411284829563567U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 12350207458513447578U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 813973258659041895U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 17039236343991574134U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 18291683592714999632U;
            aOrbiterJ = RotL64((aOrbiterJ * 7771718817924840713U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 6239616841884430968U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 10604527977569876774U;
            aOrbiterK = RotL64((aOrbiterK * 6972820410084939637U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 1707724300671717658U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 3802268808625297647U;
            aOrbiterD = RotL64((aOrbiterD * 11296811630387191563U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 9423064323799920219U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 242153923313096551U;
            aOrbiterG = RotL64((aOrbiterG * 12117679073775630197U), 41U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterK, 3U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 57U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 21U));
            aIngress = aIngress + RotL64(aOrbiterD, 14U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aPrevious, 57U) + aOrbiterG) + RotL64(aOrbiterD, 19U)) + RotL64(aCarry, 29U)) + aPhaseEWandererUpdateSaltC[((aIndex + 20U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterA, 36U)) + aOrbiterD);
            aWandererF = aWandererF + ((RotL64(aScatter, 5U) + aOrbiterG) + RotL64(aOrbiterK, 13U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterJ, 27U)) + aOrbiterA);
            aWandererI = aWandererI + ((RotL64(aScatter, 50U) + RotL64(aOrbiterJ, 57U)) + aOrbiterI);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterB, 43U)) + aOrbiterG);
            aWandererD = aWandererD + ((((RotL64(aCross, 13U) + aOrbiterD) + RotL64(aOrbiterJ, 5U)) + RotL64(aCarry, 13U)) + aPhaseEWandererUpdateSaltF[((aIndex + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + (RotL64(aWandererD, 30U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererC, 5U);
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

void TwistExpander_BasketBall_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
        // read from: aOperationLaneA, aOperationLaneB, aInvestLaneA, aOperationLaneC, aOperationLaneD, aInvestLaneC, aSnowLaneA, aExpandLaneB, aExpandLaneD, aSnowLaneB, aInvestLaneD, aWorkLaneA, aInvestLaneB, aWorkLaneB, aExpandLaneC, aWorkLaneC, aExpandLaneA
        // write to: aSnowLaneA, aSnowLaneB, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // twist_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aInvestLaneA
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aInvestLaneA forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aInvestLaneC
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aInvestLaneC backward/forward random
        // write to: aSnowLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 3809U)) & S_BLOCK1], 34U) ^ RotL64(aOperationLaneB[((aIndex + 832U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 1009U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4258U)) & S_BLOCK1], 18U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 5049U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aInvestLaneC[((aIndex + 2644U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 11U) + RotL64(aCross, 41U)) + (RotL64(aCarry, 28U) ^ RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = ((aWandererF + RotL64(aCross, 37U)) + 7893287783892523139U) + aPhaseFOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = (aWandererJ + RotL64(aIngress, 27U)) + 10257331997383491153U;
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 3U)) + RotL64(aCarry, 23U)) + 14562226733652231753U;
            aOrbiterE = (aWandererE + RotL64(aScatter, 6U)) + 14320342577110737851U;
            aOrbiterC = ((aWandererI + RotL64(aCross, 35U)) + RotL64(aCarry, 47U)) + 9816717579822880756U;
            aOrbiterB = (aWandererK + RotL64(aIngress, 11U)) + 9558926960095881953U;
            aOrbiterH = ((aWandererB + RotL64(aScatter, 43U)) + RotL64(aCarry, 11U)) + 9230371862654338324U;
            aOrbiterK = (aWandererH + RotL64(aPrevious, 39U)) + 6414274291252913420U;
            aOrbiterJ = (aWandererD + RotL64(aCross, 21U)) + 13868546184398350849U;
            aOrbiterI = ((aWandererC + RotL64(aScatter, 19U)) + 16940736952569949038U) + aPhaseFOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = (aWandererA + RotL64(aIngress, 24U)) + 2866957764814864371U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 7916721976073979724U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 1602444214978842275U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11072503711308122385U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 9529061385251008037U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 8402775110887376588U;
            aOrbiterC = RotL64((aOrbiterC * 13980225144628227381U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 15003592180290390713U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 14195681406520825751U;
            aOrbiterK = RotL64((aOrbiterK * 11455000833788877217U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 3263577002367714202U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 12019422062655581928U;
            aOrbiterJ = RotL64((aOrbiterJ * 5002313835338447799U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 8508638054582582917U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 6536618106353552880U;
            aOrbiterD = RotL64((aOrbiterD * 6233964121117511885U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 9654542989321430868U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 7019594782797863244U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1234877854354279981U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 8256061220727519919U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 9232754129467036130U;
            aOrbiterB = RotL64((aOrbiterB * 17556001874302369781U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 5608829951337740378U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 12632120498473345701U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6994794653605831925U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 17313364434369677697U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 10147405701828074385U;
            aOrbiterE = RotL64((aOrbiterE * 11544579984323623009U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 16853703086012867980U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 3591438641820423822U;
            aOrbiterG = RotL64((aOrbiterG * 3570430739475340845U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 13974806289212867511U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 7893287783892523139U;
            aOrbiterA = RotL64((aOrbiterA * 6648351608953339723U), 39U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterD, 43U);
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 6U));
            aIngress = aIngress + (RotL64(aOrbiterG, 41U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterK, 37U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterA, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 3U) + aOrbiterD) + RotL64(aOrbiterK, 19U)) + RotL64(aCarry, 3U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterG, 34U)) + aOrbiterC);
            aWandererB = aWandererB + ((RotL64(aIngress, 12U) + aOrbiterF) + RotL64(aOrbiterB, 37U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterK, 43U)) + aOrbiterA);
            aWandererF = aWandererF + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterF, 11U)) + aOrbiterE) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 43U) + aOrbiterK) + RotL64(aOrbiterC, 53U)) + aPhaseFWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 37U) + aOrbiterD) + RotL64(aOrbiterJ, 39U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 57U) + aOrbiterK) + RotL64(aOrbiterE, 41U));
            aWandererD = aWandererD + ((RotL64(aCross, 10U) + aOrbiterH) + RotL64(aOrbiterD, 13U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 51U) + aOrbiterD) + RotL64(aOrbiterC, 47U));
            aWandererK = aWandererK + (((RotL64(aScatter, 23U) + RotL64(aOrbiterA, 28U)) + aOrbiterI) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererE, 6U) ^ aWandererH);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 21U));
            aCarry = aCarry + RotL64(aWandererB, 43U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aSnowLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 2
        // ingress from: aSnowLaneA, aOperationLaneC, aOperationLaneD, aExpandLaneB
        // ingress directions: aSnowLaneA forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aExpandLaneB forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aExpandLaneD
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aExpandLaneD backward/forward random
        // write to: aSnowLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 5552U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneC[((aIndex + 6191U)) & S_BLOCK1], 57U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 5866U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 6137U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 6082U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 5504U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 6028U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 11U) + RotL64(aCarry, 23U)) ^ (RotL64(aIngress, 35U) ^ RotL64(aCross, 56U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = ((aWandererB + RotL64(aCross, 23U)) + RotL64(aCarry, 37U)) + 16802219662864902427U;
            aOrbiterK = ((aWandererC + RotL64(aScatter, 21U)) + RotL64(aCarry, 29U)) + 14332033461409490629U;
            aOrbiterI = (aWandererI + RotL64(aPrevious, 37U)) + 8781794298640286845U;
            aOrbiterD = (aWandererJ + RotL64(aIngress, 12U)) + 8459933908074937264U;
            aOrbiterH = (aWandererD + RotL64(aScatter, 27U)) + 1883580287986004426U;
            aOrbiterA = ((aWandererH + RotL64(aCross, 47U)) + 17500258188004626118U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = (aWandererA + RotL64(aPrevious, 39U)) + 7934811305150872870U;
            aOrbiterF = (aWandererK + RotL64(aIngress, 29U)) + 6380363892361098905U;
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 35U)) + RotL64(aCarry, 13U)) + 12623079132626676910U;
            aOrbiterG = ((aWandererF + RotL64(aIngress, 10U)) + 10455208121949202703U) + aPhaseFOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = (aWandererE + RotL64(aScatter, 51U)) + 8805532707916767629U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 9161544391400377699U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 3501434325829663268U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7933545151293799637U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 651783304096081996U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 441505031509930622U;
            aOrbiterA = RotL64((aOrbiterA * 8045355432310956143U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 1771159983581326424U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 15227946417377695989U;
            aOrbiterC = RotL64((aOrbiterC * 1563141188972797601U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 4153717524193279095U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 4404521756523902829U;
            aOrbiterH = RotL64((aOrbiterH * 1410342912973206203U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 6231945075461813285U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 3864780227164426690U;
            aOrbiterE = RotL64((aOrbiterE * 18031353247480673617U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 1509699687948576558U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 17316114302489411191U;
            aOrbiterF = RotL64((aOrbiterF * 15490661284980281585U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 2250572827340157410U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 6403966113144372915U;
            aOrbiterK = RotL64((aOrbiterK * 726441947009132383U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 2329903609147403156U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 2486330017319455238U;
            aOrbiterG = RotL64((aOrbiterG * 17427461345935191757U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 9333421733051210144U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 14779925626161889533U;
            aOrbiterD = RotL64((aOrbiterD * 9120486933147706541U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 4343688173541745311U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 12686722305368397686U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17484250022537912537U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 3745163111502795473U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 16802219662864902427U;
            aOrbiterB = RotL64((aOrbiterB * 4343730534036919417U), 3U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterB, 27U);
            aIngress = aIngress + (RotL64(aOrbiterA, 46U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterH, 53U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterJ, 23U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 11U));
            aIngress = aIngress + RotL64(aOrbiterF, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aCross, 19U) + RotL64(aOrbiterB, 11U)) + aOrbiterC) + RotL64(aCarry, 11U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 23U) + aOrbiterG) + RotL64(aOrbiterJ, 29U)) + aPhaseFWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterG, 5U)) + aOrbiterK);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 44U) + RotL64(aOrbiterE, 53U)) + aOrbiterC);
            aWandererH = aWandererH + ((RotL64(aIngress, 41U) + RotL64(aOrbiterF, 13U)) + aOrbiterD);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterJ, 58U)) + aOrbiterI);
            aWandererG = aWandererG + ((RotL64(aScatter, 51U) + aOrbiterF) + RotL64(aOrbiterE, 41U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 29U) + aOrbiterA) + RotL64(aOrbiterJ, 27U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 53U) + aOrbiterF) + RotL64(aOrbiterK, 51U)) + RotL64(aCarry, 27U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 11U) + aOrbiterG) + RotL64(aOrbiterH, 18U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 48U) + RotL64(aOrbiterG, 35U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 18U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 41U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererC, 11U);
            aCarry = aCarry + RotL64(aIngress, 34U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aSnowLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_c loop 3
        // ingress from: aSnowLaneB, aOperationLaneA, aInvestLaneD
        // ingress directions: aSnowLaneB forward forced, aOperationLaneA forward forced, aInvestLaneD forward/backward random
        // cross from: aSnowLaneA, aOperationLaneC
        // cross directions: aSnowLaneA backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneB[((aIndex + 15040U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneA[((aIndex + 14920U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aInvestLaneD[((aIndex + 15525U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 15093U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneC[((aIndex + 12182U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 47U) + RotL64(aCross, 35U)) + (RotL64(aPrevious, 19U) ^ RotL64(aCarry, 4U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = (aWandererB + RotL64(aPrevious, 21U)) + 18087125778766689269U;
            aOrbiterH = (aWandererC + RotL64(aCross, 53U)) + 13710545066503235196U;
            aOrbiterD = (aWandererJ + RotL64(aIngress, 13U)) + 1701939704736254645U;
            aOrbiterA = (aWandererK + RotL64(aScatter, 19U)) + 8064093611384019909U;
            aOrbiterJ = (aWandererA + RotL64(aIngress, 48U)) + 16623332751533885431U;
            aOrbiterE = (aWandererF + RotL64(aCross, 39U)) + 15590129153794910109U;
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 11U)) + 7413312683079107383U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = ((aWandererH + RotL64(aScatter, 35U)) + RotL64(aCarry, 13U)) + 4186064478651458810U;
            aOrbiterK = (aWandererG + RotL64(aIngress, 60U)) + 5501191643940735954U;
            aOrbiterG = ((aWandererI + RotL64(aCross, 5U)) + RotL64(aCarry, 27U)) + 11064645242200570835U;
            aOrbiterI = (((aWandererD + RotL64(aPrevious, 57U)) + RotL64(aCarry, 23U)) + 13825922087298055833U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 5944980709887369970U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 8181136916070569646U;
            aOrbiterD = RotL64((aOrbiterD * 395183021205661827U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 15442336949157292482U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 11580554435240641337U;
            aOrbiterE = RotL64((aOrbiterE * 6654637892858767739U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 11240018128174598322U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 2027565596050777471U;
            aOrbiterJ = RotL64((aOrbiterJ * 18048186560314431815U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 16425887196883725233U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 16828683527588834095U;
            aOrbiterB = RotL64((aOrbiterB * 17746289103235902485U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 9923829146479008804U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 6669171007279929454U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 681823450939955099U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 3902430046523165149U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 6739998149289590041U;
            aOrbiterA = RotL64((aOrbiterA * 2675037435528416821U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 16014401255534234075U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 14741857638680634564U;
            aOrbiterC = RotL64((aOrbiterC * 8723611021403369393U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 5064807861673260054U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 968747317273200299U;
            aOrbiterH = RotL64((aOrbiterH * 14122304002722582329U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 5282686212362051427U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 6902253563196129760U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7682808024658992049U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 4995580401402368332U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 14949762584793646470U;
            aOrbiterF = RotL64((aOrbiterF * 3539183342072953803U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 2378815735788107402U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 18087125778766689269U;
            aOrbiterG = RotL64((aOrbiterG * 16799380528404446281U), 3U);
            //
            aIngress = RotL64(aOrbiterF, 27U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterH, 11U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterI, 35U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterA, 44U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterC, 3U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterK, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aIngress, 35U) + aOrbiterF) + RotL64(aOrbiterI, 3U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterH, 13U)) + aOrbiterD);
            aWandererC = aWandererC + ((RotL64(aPrevious, 37U) + aOrbiterH) + RotL64(aOrbiterJ, 41U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 26U) + aOrbiterE) + RotL64(aOrbiterH, 44U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 11U) + RotL64(aOrbiterB, 51U)) + aOrbiterF) + RotL64(aCarry, 51U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 51U) + aOrbiterD) + RotL64(aOrbiterG, 11U));
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 3U) + aOrbiterC) + RotL64(aOrbiterH, 53U)) + RotL64(aCarry, 37U)) + aPhaseFWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 46U) + RotL64(aOrbiterC, 37U)) + aOrbiterB);
            aWandererG = aWandererG + ((RotL64(aCross, 5U) + RotL64(aOrbiterK, 46U)) + aOrbiterJ);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 21U) + aOrbiterA) + RotL64(aOrbiterG, 57U));
            aWandererF = aWandererF + ((RotL64(aIngress, 41U) + aOrbiterJ) + RotL64(aOrbiterB, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 26U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 37U));
            aCarry = aCarry + RotL64(aWandererK, 52U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 4
        // ingress from: aWorkLaneA, aSnowLaneA, aInvestLaneB
        // ingress directions: aWorkLaneA forward forced, aSnowLaneA forward forced, aInvestLaneB forward/backward random
        // cross from: aSnowLaneB, aOperationLaneD
        // cross directions: aSnowLaneB backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 21429U)) & S_BLOCK1], 57U) ^ RotL64(aSnowLaneA[((aIndex + 20515U)) & S_BLOCK1], 28U));
            aIngress ^= RotL64(aInvestLaneB[((aIndex + 21062U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 19340U)) & S_BLOCK1], 28U) ^ RotL64(aOperationLaneD[((aIndex + 18825U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 56U) + RotL64(aPrevious, 39U)) ^ (RotL64(aIngress, 5U) + RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = (aWandererD + RotL64(aIngress, 13U)) + 13960289014350612206U;
            aOrbiterG = (aWandererE + RotL64(aCross, 21U)) + 3483331015269589730U;
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 35U)) + RotL64(aCarry, 51U)) + 6873299241002444518U;
            aOrbiterD = (aWandererC + RotL64(aPrevious, 54U)) + 3562094007125534229U;
            aOrbiterA = (aWandererJ + RotL64(aCross, 27U)) + 11422367439932782705U;
            aOrbiterK = ((aWandererG + RotL64(aIngress, 29U)) + 532453428514259816U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = (aWandererB + RotL64(aScatter, 11U)) + 17810941465810193088U;
            aOrbiterE = (aWandererI + RotL64(aPrevious, 51U)) + 11869759058631106331U;
            aOrbiterC = ((aWandererH + RotL64(aIngress, 48U)) + RotL64(aCarry, 47U)) + 8837581071876177566U;
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 3U)) + RotL64(aCarry, 35U)) + 17185378327053837778U;
            aOrbiterI = ((aWandererA + RotL64(aCross, 41U)) + 7578253375676981500U) + aPhaseFOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 17112646434432814442U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 14949096407295697881U;
            aOrbiterJ = RotL64((aOrbiterJ * 14770977858283051753U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 4259590620758467836U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 6534899413644542303U;
            aOrbiterK = RotL64((aOrbiterK * 7987609419215568661U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 2637407498893694243U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 15819295597921425711U;
            aOrbiterE = RotL64((aOrbiterE * 5202015597375051399U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 6373559542002699718U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 11694562937392022505U;
            aOrbiterC = RotL64((aOrbiterC * 9311557972331218597U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 3308736483775453062U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 12749929710650475901U;
            aOrbiterI = RotL64((aOrbiterI * 248428400724560945U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 1569528215675579656U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 1044077933631689572U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6443796233912755143U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 8393422728124537471U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 2002732612516530754U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13702146823622364279U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 13469191942843147943U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 7633171368709520560U;
            aOrbiterF = RotL64((aOrbiterF * 9713514012478203047U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 4023206337737491091U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 15990323932023596968U;
            aOrbiterG = RotL64((aOrbiterG * 4816480271959713463U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 837005729394899591U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 9692088757104339973U;
            aOrbiterD = RotL64((aOrbiterD * 17971548293495807419U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 18039464962413134616U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 13960289014350612206U;
            aOrbiterH = RotL64((aOrbiterH * 931609478642506411U), 41U);
            //
            aIngress = RotL64(aOrbiterJ, 53U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 29U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 37U));
            aIngress = aIngress + (RotL64(aOrbiterD, 44U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 13U));
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 41U) + aOrbiterI) + RotL64(aOrbiterA, 34U));
            aWandererC = aWandererC + (((RotL64(aScatter, 48U) + aOrbiterF) + RotL64(aOrbiterC, 47U)) + RotL64(aCarry, 5U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterK, 57U)) + aOrbiterE);
            aWandererA = aWandererA + ((RotL64(aPrevious, 43U) + aOrbiterJ) + RotL64(aOrbiterE, 13U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterG, 11U)) + aOrbiterI);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 53U) + aOrbiterH) + RotL64(aOrbiterD, 28U)) + RotL64(aCarry, 27U)) + aPhaseFWandererUpdateSaltF[((aIndex + 4U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 39U) + aOrbiterH) + RotL64(aOrbiterA, 3U));
            aWandererD = aWandererD + ((RotL64(aScatter, 35U) + aOrbiterD) + RotL64(aOrbiterJ, 43U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 5U) + aOrbiterD) + RotL64(aOrbiterF, 23U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 30U) + RotL64(aOrbiterJ, 53U)) + aOrbiterC);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 23U) + aOrbiterB) + RotL64(aOrbiterI, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererB, 14U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererD, 21U) ^ aWandererG);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 37U));
            aCarry = aCarry + RotL64(aWandererI, 27U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 23595U)) & S_BLOCK1], 19U) ^ RotL64(aSnowLaneB[((aIndex + 23904U)) & S_BLOCK1], 56U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 24028U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24814U)) & S_BLOCK1], 5U) ^ RotL64(aSnowLaneA[((aIndex + 24851U)) & S_BLOCK1], 48U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 27U) + RotL64(aCarry, 53U)) ^ (RotL64(aIngress, 40U) ^ RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 27U)) + 3970829908171131502U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterI = ((aWandererA + RotL64(aScatter, 43U)) + 7040283759419531991U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = (aWandererG + RotL64(aCross, 40U)) + 11856292169397052901U;
            aOrbiterJ = (aWandererK + RotL64(aIngress, 35U)) + 819598588791819022U;
            aOrbiterD = (aWandererE + RotL64(aScatter, 13U)) + 2176451710970866848U;
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 29U)) + RotL64(aCarry, 47U)) + 6454704928613390494U;
            aOrbiterG = ((aWandererF + RotL64(aIngress, 19U)) + RotL64(aCarry, 43U)) + 11792122387218053841U;
            aOrbiterK = (aWandererB + RotL64(aCross, 56U)) + 9254780213489752211U;
            aOrbiterH = ((aWandererD + RotL64(aScatter, 37U)) + RotL64(aCarry, 3U)) + 16591812589999846482U;
            aOrbiterC = (aWandererJ + RotL64(aCross, 47U)) + 1471246223935074832U;
            aOrbiterA = (aWandererI + RotL64(aPrevious, 21U)) + 1424843083106386453U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 1856469958050891629U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 6331743690452052712U;
            aOrbiterF = RotL64((aOrbiterF * 15327924647897459645U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 10351075711345476487U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 9518585245330480185U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3792179827396760391U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 17787514620244712033U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 14182328067398162557U;
            aOrbiterG = RotL64((aOrbiterG * 18107337388659070197U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 12798088948801072444U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 9563215159275202323U;
            aOrbiterH = RotL64((aOrbiterH * 7058145016617349141U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 9904919772580498232U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 16579777394992143043U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10516761340320196661U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 6344049286854588503U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 3531503618941046788U;
            aOrbiterA = RotL64((aOrbiterA * 10855385899703024105U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 11334308840132700377U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 11093833870078787770U;
            aOrbiterK = RotL64((aOrbiterK * 16105889714648555755U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 3831491136025364271U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 12505259454860591372U;
            aOrbiterD = RotL64((aOrbiterD * 6135450888433504093U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 2210290810330253363U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 10786160915224323113U;
            aOrbiterC = RotL64((aOrbiterC * 799075068398619501U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 7791474921127653867U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 1046454625851499863U;
            aOrbiterJ = RotL64((aOrbiterJ * 18040454167287729591U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 14636813124839719351U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 3970829908171131502U;
            aOrbiterI = RotL64((aOrbiterI * 2737568880005765517U), 41U);
            //
            aIngress = RotL64(aOrbiterA, 43U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + (RotL64(aOrbiterD, 13U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterK, 51U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 18U));
            aIngress = aIngress + RotL64(aOrbiterH, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterK, 19U)) + aOrbiterG) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aCross, 13U) + RotL64(aOrbiterB, 51U)) + aOrbiterE);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 34U) + RotL64(aOrbiterI, 26U)) + aOrbiterE);
            aWandererD = aWandererD + ((RotL64(aIngress, 3U) + aOrbiterD) + RotL64(aOrbiterI, 13U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 5U) + aOrbiterG) + RotL64(aOrbiterH, 23U));
            aWandererC = aWandererC + (((RotL64(aIngress, 41U) + aOrbiterJ) + RotL64(aOrbiterK, 11U)) + RotL64(aCarry, 39U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterI, 5U)) + aOrbiterK);
            aWandererI = aWandererI + (((RotL64(aPrevious, 47U) + aOrbiterG) + RotL64(aOrbiterF, 39U)) + RotL64(aCarry, 47U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 37U) + aOrbiterJ) + RotL64(aOrbiterI, 28U));
            aWandererA = aWandererA + (((RotL64(aScatter, 23U) + aOrbiterC) + RotL64(aOrbiterA, 21U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 52U) + RotL64(aOrbiterC, 47U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererC);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 37U));
            aCarry = aCarry + (RotL64(aWandererE, 46U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererG, 39U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 6
        // ingress from: aWorkLaneC, aWorkLaneA, aExpandLaneA
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aExpandLaneA forward/backward random
        // cross from: aWorkLaneB, aOperationLaneB
        // cross directions: aWorkLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 27491U)) & S_BLOCK1], 14U) ^ RotL64(aWorkLaneA[((aIndex + 32197U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29802U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30031U)) & S_BLOCK1], 18U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28982U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 6U) + RotL64(aCarry, 51U)) + (RotL64(aIngress, 21U) ^ RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = (aWandererH + RotL64(aIngress, 18U)) + 9751314027302668907U;
            aOrbiterB = ((aWandererA + RotL64(aCross, 13U)) + RotL64(aCarry, 27U)) + 12175450995523107056U;
            aOrbiterJ = (aWandererD + RotL64(aScatter, 27U)) + 17519694958730119552U;
            aOrbiterK = (aWandererE + RotL64(aPrevious, 21U)) + 9093525527925682263U;
            aOrbiterH = (aWandererB + RotL64(aScatter, 50U)) + 3713831321786810138U;
            aOrbiterA = (aWandererC + RotL64(aPrevious, 29U)) + 10108355209191835040U;
            aOrbiterC = (aWandererJ + RotL64(aCross, 11U)) + 12956307447311314768U;
            aOrbiterF = ((aWandererK + RotL64(aIngress, 35U)) + 1904298513945877359U) + aPhaseFOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 57U)) + RotL64(aCarry, 21U)) + 4658049993308574460U;
            aOrbiterE = ((aWandererG + RotL64(aScatter, 53U)) + RotL64(aCarry, 43U)) + 9826333658248851902U;
            aOrbiterI = ((aWandererF + RotL64(aCross, 47U)) + 12058666914724365134U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 2516574707110528099U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 13335308331049750235U;
            aOrbiterJ = RotL64((aOrbiterJ * 5880227828760598587U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 8230749255538495304U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 16536559486797811486U;
            aOrbiterA = RotL64((aOrbiterA * 7097036838156464969U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 12387639130570188998U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 8459259798142872020U;
            aOrbiterF = RotL64((aOrbiterF * 8001346480955847013U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 16083784052002800300U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 1957284290736468379U;
            aOrbiterH = RotL64((aOrbiterH * 5046501301740813065U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 7349538179311335863U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 16395170077006105258U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4230485452156662763U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 3317652065873784068U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 5517155804799120700U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9789270651974719183U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 5568525912112200094U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 9334250662962319598U;
            aOrbiterE = RotL64((aOrbiterE * 5034887614541768961U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 5641394627075994165U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 13524971148931512745U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3699457147759854357U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 15124425790244392471U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 7896294947517723306U;
            aOrbiterC = RotL64((aOrbiterC * 7526632360108129915U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 15241686066829586263U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 12099799118961857495U;
            aOrbiterI = RotL64((aOrbiterI * 10456171163074630861U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 17529688916595727188U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 9751314027302668907U;
            aOrbiterB = RotL64((aOrbiterB * 521888849578281715U), 29U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterC, 39U);
            aIngress = aIngress + (RotL64(aOrbiterA, 43U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 18U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 11U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 37U));
            aIngress = aIngress + RotL64(aOrbiterH, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterK, 57U)) + aOrbiterH);
            aWandererE = aWandererE + ((RotL64(aScatter, 10U) + aOrbiterK) + RotL64(aOrbiterD, 23U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterK, 44U)) + aOrbiterA);
            aWandererF = aWandererF + ((RotL64(aPrevious, 21U) + aOrbiterC) + RotL64(aOrbiterI, 13U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterF, 3U)) + aOrbiterK);
            aWandererD = aWandererD + (((RotL64(aIngress, 39U) + aOrbiterB) + RotL64(aOrbiterE, 5U)) + aPhaseFWandererUpdateSaltB[((aIndex + 24U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterI, 42U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterE, 27U)) + aOrbiterD) + RotL64(aCarry, 47U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 37U) + aOrbiterC) + RotL64(aOrbiterA, 37U));
            aWandererA = aWandererA + (((RotL64(aCross, 48U) + RotL64(aOrbiterC, 21U)) + aOrbiterJ) + RotL64(aCarry, 29U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterI, 47U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererB, 48U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererH);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + RotL64(aWandererG, 38U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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

void TwistExpander_BasketBall_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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
        // ingress from: aWorkLaneA, aWorkLaneB, aWorkLaneC
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aWorkLaneC forward/backward random
        // cross from: aWorkLaneB, aWorkLaneC, aWorkLaneD
        // cross directions: aWorkLaneB backward forced, aWorkLaneC backward forced, aWorkLaneD backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 7546U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneB[((aIndex + 1345U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 4707U)) & S_BLOCK1], 10U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 33U)) & S_BLOCK1], 20U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 1071U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 3800U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 10U) ^ RotL64(aIngress, 37U)) ^ (RotL64(aCarry, 51U) + RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = (aWandererE + RotL64(aIngress, 23U)) + 14214886793361825363U;
            aOrbiterD = ((aWandererI + RotL64(aScatter, 5U)) + RotL64(aCarry, 35U)) + 17267959031078766320U;
            aOrbiterB = (aWandererD + RotL64(aCross, 41U)) + 16436067429484887644U;
            aOrbiterH = (((aWandererK + RotL64(aPrevious, 60U)) + RotL64(aCarry, 21U)) + 9885951769332633820U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = (((aWandererC + RotL64(aCross, 51U)) + RotL64(aCarry, 51U)) + 12971711341813893304U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 199970353398450154U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 1237341696444162094U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2850125642665515751U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 7991128854417613360U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 14809029847149045833U;
            aOrbiterC = RotL64((aOrbiterC * 5940857360838299105U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 2559509556915775947U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 14336829730147834160U;
            aOrbiterE = RotL64((aOrbiterE * 15103242520064900873U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 8853631886733610440U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 13346159398673246914U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13660497151446983393U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 12121095718571872976U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 16239781125815589804U;
            aOrbiterD = RotL64((aOrbiterD * 5157009090454962231U), 43U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterB, 20U);
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aScatter, 3U) + aOrbiterC) + RotL64(aOrbiterD, 43U)) + RotL64(aCarry, 5U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 57U) + aOrbiterD) + RotL64(aOrbiterH, 52U));
            aWandererD = aWandererD + ((RotL64(aIngress, 21U) + aOrbiterB) + RotL64(aOrbiterH, 19U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 29U) + aOrbiterH) + RotL64(aOrbiterE, 29U)) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 42U) + aOrbiterB) + RotL64(aOrbiterE, 5U)) + RotL64(aCarry, 21U)) + aPhaseGWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 21U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererE, 52U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererI, 11U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 9983U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((aIndex + 8356U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 10333U)) & S_BLOCK1], 4U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 14951U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 9254U)) & S_BLOCK1], 54U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 12031U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 37U) + RotL64(aIngress, 57U)) ^ (RotL64(aPrevious, 19U) ^ RotL64(aCarry, 6U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = (aWandererK + RotL64(aCross, 60U)) + 5568146815535263910U;
            aOrbiterC = (((aWandererI + RotL64(aPrevious, 27U)) + RotL64(aCarry, 57U)) + 7736084960873834666U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = (((aWandererF + RotL64(aScatter, 11U)) + RotL64(aCarry, 37U)) + 1336413621817562093U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 19U)) + RotL64(aCarry, 23U)) + 5218462026934984692U;
            aOrbiterI = (aWandererE + RotL64(aCross, 39U)) + 7048890985969555935U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 13415955213864702118U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 5657023257021528548U;
            aOrbiterJ = RotL64((aOrbiterJ * 5200798937081797819U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 14338310943137497116U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 12305161641833950473U;
            aOrbiterI = RotL64((aOrbiterI * 11949964304435964395U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 14514226578370459131U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 12692904083266024340U;
            aOrbiterB = RotL64((aOrbiterB * 14800805065279908839U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 11012959130001327964U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 7106471380403489078U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 515626559384817223U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 3718101961355280891U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 13364192077222322664U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1411328915372590283U), 11U);
            //
            aIngress = RotL64(aOrbiterC, 56U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterB, 23U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterI, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aIngress, 35U) + RotL64(aOrbiterB, 42U)) + aOrbiterE) + RotL64(aCarry, 19U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 47U) + aOrbiterI) + RotL64(aOrbiterC, 21U)) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aCross, 5U) + aOrbiterJ) + RotL64(aOrbiterI, 51U)) + RotL64(aCarry, 43U)) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 56U) + RotL64(aOrbiterE, 29U)) + aOrbiterJ);
            aWandererE = aWandererE + ((RotL64(aIngress, 23U) + RotL64(aOrbiterE, 5U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererK, 39U) ^ aWandererE);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + RotL64(aWandererF, 19U);
            aCarry = aCarry + RotL64(aIngress, 30U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 22875U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((aIndex + 23886U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 19065U)) & S_BLOCK1], 60U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23119U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 20068U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aWorkLaneC[((aIndex + 19324U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCross, 5U)) ^ (RotL64(aIngress, 35U) + RotL64(aCarry, 52U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = ((aWandererH + RotL64(aCross, 47U)) + RotL64(aCarry, 53U)) + 3561491146322798260U;
            aOrbiterA = ((aWandererA + RotL64(aScatter, 3U)) + 7075025056181885339U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = (((aWandererG + RotL64(aPrevious, 24U)) + RotL64(aCarry, 29U)) + 9230910887904171613U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterK = ((aWandererI + RotL64(aIngress, 37U)) + RotL64(aCarry, 11U)) + 4119781172609908917U;
            aOrbiterB = (aWandererJ + RotL64(aScatter, 11U)) + 17155609083870983149U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 2423018561430181695U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 12957280305617615744U;
            aOrbiterG = RotL64((aOrbiterG * 17696410107705645631U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 2461704174772065813U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 7907123257849391997U;
            aOrbiterF = RotL64((aOrbiterF * 9416171962847312179U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 7257868138318960007U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 16425903703085702285U;
            aOrbiterB = RotL64((aOrbiterB * 7996935869077231999U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 2990822664594079467U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 5654819006718953817U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4465096036756887801U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 12183676471235678779U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 15026286960542123922U;
            aOrbiterA = RotL64((aOrbiterA * 17199049329995315279U), 13U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterA, 13U);
            aIngress = aIngress + (RotL64(aOrbiterF, 3U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterB, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterK, 39U)) + aOrbiterG);
            aWandererH = aWandererH + (((RotL64(aPrevious, 53U) + aOrbiterK) + RotL64(aOrbiterB, 51U)) + RotL64(aCarry, 23U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterA, 5U)) + aOrbiterF);
            aWandererG = aWandererG + ((((RotL64(aIngress, 39U) + RotL64(aOrbiterB, 29U)) + aOrbiterF) + RotL64(aCarry, 51U)) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 22U) + RotL64(aOrbiterG, 18U)) + aOrbiterA) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererA);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + RotL64(aWandererJ, 27U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 27073U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((aIndex + 26501U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aExpandLaneA[((aIndex + 28557U)) & S_BLOCK1], 28U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29653U)) & S_BLOCK1], 18U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28612U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 27800U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 19U) + RotL64(aCarry, 35U)) ^ (RotL64(aCross, 5U) + RotL64(aPrevious, 50U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 5U)) + RotL64(aCarry, 3U)) + 13687218104610230596U;
            aOrbiterF = ((aWandererK + RotL64(aIngress, 51U)) + 6841550124960692709U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = ((aWandererF + RotL64(aScatter, 35U)) + RotL64(aCarry, 23U)) + 17418968668458764131U;
            aOrbiterB = (((aWandererI + RotL64(aCross, 13U)) + RotL64(aCarry, 41U)) + 8303537912696948204U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = (aWandererJ + RotL64(aPrevious, 26U)) + 12376614417285936537U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 14215749063579232654U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 4111736931433665347U;
            aOrbiterA = RotL64((aOrbiterA * 8841288213954433049U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 11250375934571631522U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 5367367837773331275U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7262723007545807179U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 15514089192382674434U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 1475991716685034960U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17720681295551650891U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 5531622777788629748U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 8363822215908303335U;
            aOrbiterB = RotL64((aOrbiterB * 17850203366840994883U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 3741256932685720414U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 11634667238062155772U;
            aOrbiterC = RotL64((aOrbiterC * 15925089729784547403U), 47U);
            //
            aIngress = RotL64(aOrbiterC, 19U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterA, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aPrevious, 39U) + aOrbiterF) + RotL64(aOrbiterA, 43U)) + RotL64(aCarry, 5U)) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 3U) + aOrbiterB) + RotL64(aOrbiterJ, 58U)) + aPhaseGWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 51U) + aOrbiterA) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 39U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 11U) + aOrbiterC) + RotL64(aOrbiterA, 35U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 24U) + RotL64(aOrbiterC, 11U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + RotL64(aWandererF, 19U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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

void TwistExpander_BasketBall_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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
        // ingress from: aExpandLaneA, aExpandLaneB, aExpandLaneC
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aExpandLaneC forward/backward random
        // cross from: aExpandLaneB, aExpandLaneC, aExpandLaneD
        // cross directions: aExpandLaneB backward forced, aExpandLaneC backward forced, aExpandLaneD backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 377U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneB[((aIndex + 4605U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 1167U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 7544U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4878U)) & S_BLOCK1], 26U));
            aCross ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 1096U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 3U) + RotL64(aCarry, 34U)) + (RotL64(aIngress, 51U) ^ RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = (aWandererA + RotL64(aPrevious, 3U)) + 14179205183062705133U;
            aOrbiterE = ((aWandererC + RotL64(aScatter, 12U)) + RotL64(aCarry, 35U)) + 210032324058740920U;
            aOrbiterI = (aWandererD + RotL64(aCross, 23U)) + 7387115089142500152U;
            aOrbiterC = (((aWandererJ + RotL64(aIngress, 51U)) + RotL64(aCarry, 51U)) + 17583362781238061430U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = (((aWandererI + RotL64(aCross, 43U)) + RotL64(aCarry, 11U)) + 4991442849150005943U) + aPhaseHOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 2891376254689854555U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 10523274382407446239U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17443994099359920915U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 3861893764676218667U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 3366674459852093746U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14005994095369483813U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 5898492634386601145U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 7047353571244768721U;
            aOrbiterH = RotL64((aOrbiterH * 2257518291062508467U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 14374108805453186316U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 8763667021501226510U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7694695426430267863U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 18261523829316379575U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 650477532238860965U;
            aOrbiterC = RotL64((aOrbiterC * 8291758490821819851U), 35U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterF, 35U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 47U));
            aIngress = aIngress + RotL64(aOrbiterE, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aScatter, 43U) + RotL64(aOrbiterF, 29U)) + aOrbiterC);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterF, 51U)) + aOrbiterI);
            aWandererA = aWandererA + ((((RotL64(aCross, 13U) + RotL64(aOrbiterE, 39U)) + aOrbiterI) + RotL64(aCarry, 41U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 30U) + RotL64(aOrbiterI, 19U)) + aOrbiterH) + aPhaseHWandererUpdateSaltD[((aIndex + 24U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 51U) + aOrbiterC) + RotL64(aOrbiterE, 60U)) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 14U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererA, 5U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 16105U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneB[((aIndex + 10920U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 11536U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9156U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 12502U)) & S_BLOCK1], 30U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14961U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 6U) ^ RotL64(aPrevious, 23U)) ^ (RotL64(aIngress, 53U) + RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = ((aWandererE + RotL64(aIngress, 39U)) + RotL64(aCarry, 5U)) + 12131317914288566437U;
            aOrbiterJ = (((aWandererG + RotL64(aPrevious, 13U)) + RotL64(aCarry, 23U)) + 5672805657999385496U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = (aWandererB + RotL64(aCross, 29U)) + 3581710244233124197U;
            aOrbiterC = ((aWandererC + RotL64(aScatter, 47U)) + 15251296040538489436U) + aPhaseHOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = ((aWandererJ + RotL64(aCross, 58U)) + RotL64(aCarry, 41U)) + 11295008604679904153U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 2230897493419504490U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 7109600123297458999U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8267799351136506307U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 13119156643107683803U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 14755160867807355250U;
            aOrbiterK = RotL64((aOrbiterK * 10007087518844899239U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 16829363373287496832U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 16981122946707720883U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5394974422201576627U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 8806000776958603317U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 16810923047720876014U;
            aOrbiterJ = RotL64((aOrbiterJ * 17872735050219539145U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 8129657889554436328U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 8653100378491974463U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11395283153912468661U), 13U);
            //
            aIngress = RotL64(aOrbiterK, 37U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 47U));
            aIngress = aIngress + RotL64(aOrbiterJ, 24U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 3U) + aOrbiterD) + RotL64(aOrbiterB, 23U));
            aWandererG = aWandererG + ((((RotL64(aScatter, 37U) + RotL64(aOrbiterB, 46U)) + aOrbiterJ) + RotL64(aCarry, 21U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterC, 35U)) + aOrbiterD) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 54U) + RotL64(aOrbiterK, 3U)) + aOrbiterB) + RotL64(aCarry, 47U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 27U) + aOrbiterC) + RotL64(aOrbiterJ, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + RotL64(aWandererG, 48U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 18977U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneA[((aIndex + 19562U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aExpandLaneD[((aIndex + 23323U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17617U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 24496U)) & S_BLOCK1], 28U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 19263U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 56U) + RotL64(aCarry, 13U)) + (RotL64(aCross, 41U) ^ RotL64(aPrevious, 29U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = (((aWandererA + RotL64(aIngress, 4U)) + RotL64(aCarry, 41U)) + 13350544654542863236U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = ((aWandererD + RotL64(aScatter, 21U)) + RotL64(aCarry, 3U)) + 12364346790125404372U;
            aOrbiterE = (aWandererC + RotL64(aCross, 51U)) + 9738750172849512764U;
            aOrbiterG = (((aWandererB + RotL64(aPrevious, 29U)) + RotL64(aCarry, 29U)) + 3781373837635491421U) + aPhaseHOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = (aWandererK + RotL64(aIngress, 39U)) + 16635020317512702337U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 5383653921676231276U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 10181959815492056493U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14784636206508715141U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 10005510924273927017U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 9524687662265740565U;
            aOrbiterG = RotL64((aOrbiterG * 13687380438646756931U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 4259138552009771014U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 8973051213213726023U;
            aOrbiterK = RotL64((aOrbiterK * 12625091476068190979U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 17602611840127337490U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 8218984546932905269U;
            aOrbiterA = RotL64((aOrbiterA * 17504305273683304231U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 18102186122213487888U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 2629927500298092976U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6983280164448292723U), 5U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterE, 3U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 27U));
            aIngress = aIngress + RotL64(aOrbiterG, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterK, 21U)) + aOrbiterA) + RotL64(aCarry, 39U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 29U) + aOrbiterK) + RotL64(aOrbiterG, 58U));
            aWandererA = aWandererA + (((RotL64(aIngress, 3U) + aOrbiterB) + RotL64(aOrbiterE, 5U)) + aPhaseHWandererUpdateSaltA[((aIndex + 16U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 43U) + aOrbiterG) + RotL64(aOrbiterE, 35U));
            aWandererB = aWandererB + ((((RotL64(aIngress, 20U) + RotL64(aOrbiterG, 13U)) + aOrbiterA) + RotL64(aCarry, 23U)) + aPhaseHWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererB);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + RotL64(aWandererD, 56U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 29726U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneB[((aIndex + 27882U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aWorkLaneA[((aIndex + 24776U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25635U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26916U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 31790U)) & S_BLOCK1], 28U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aPrevious, 11U)) ^ (RotL64(aCarry, 47U) ^ RotL64(aIngress, 60U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = (((aWandererI + RotL64(aPrevious, 58U)) + RotL64(aCarry, 27U)) + 3612110001869385068U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterF = ((aWandererG + RotL64(aIngress, 47U)) + RotL64(aCarry, 13U)) + 16340824141280225936U;
            aOrbiterJ = ((aWandererA + RotL64(aCross, 27U)) + RotL64(aCarry, 47U)) + 15222338965130765231U;
            aOrbiterI = ((aWandererD + RotL64(aScatter, 13U)) + 6649270508107155041U) + aPhaseHOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = (aWandererH + RotL64(aIngress, 37U)) + 768217258655426384U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 4481855259658861851U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 18318041934562434016U;
            aOrbiterJ = RotL64((aOrbiterJ * 14913761339765234979U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 4212457153804401807U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 16143621095636987628U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6576072860505961427U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 2095664232866642086U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 4339527736737366572U;
            aOrbiterI = RotL64((aOrbiterI * 17503569508822244125U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 13679353177869884790U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 11582168502846418236U;
            aOrbiterF = RotL64((aOrbiterF * 135539430034462861U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 10451330452898542191U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 12951448817640617841U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4141870904192742091U), 5U);
            //
            aIngress = RotL64(aOrbiterF, 57U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterK, 14U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterJ, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aIngress, 13U) + aOrbiterH) + RotL64(aOrbiterK, 11U)) + RotL64(aCarry, 53U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 34U) + RotL64(aOrbiterI, 35U)) + aOrbiterF);
            aWandererD = aWandererD + ((((RotL64(aCross, 23U) + RotL64(aOrbiterJ, 26U)) + aOrbiterI) + RotL64(aCarry, 27U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterI, 51U)) + aOrbiterK);
            aWandererH = aWandererH + (((RotL64(aIngress, 5U) + aOrbiterJ) + RotL64(aOrbiterF, 3U)) + aPhaseHWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererH, 39U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
