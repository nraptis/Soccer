#include "TwistExpander_WaterPolo_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_WaterPolo_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xE51086DF89901E9BULL + 0xE00D22FF7632892DULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xA5B71D90158EEE63ULL + 0xDDB370ACC94EF59EULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xBB5811D3865E5FD5ULL + 0xCCEF6A6377DECC14ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xCA494AC8BD4D81BDULL + 0xCDFE4ECCF8BAF934ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x92F8EEA10171949BULL + 0xD3674DDE563D176AULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x8FEAD73301E269A3ULL + 0xE5D56232229FC2EFULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xD65187966D561AC7ULL + 0xF58138A9FE3B7C3DULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xA674096B4EA67323ULL + 0xE2CF63B8E4DC1CE3ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xF03420E341E56299ULL + 0x8E44B5BD8C5291D5ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x9C1BC80AB91867FDULL + 0xE0E2B99B0371A9D1ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xA3F6FF4BD76785D9ULL + 0x96043603C0704ECBULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x9D0024C2FBB2EAEFULL + 0xD6313EAA4036650DULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xAA04C04BBA76AC29ULL + 0xDA2C476DBF8DE104ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x907195ECE7665FF7ULL + 0xF67E656F6EE5D904ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x8E4D4C6D0C1706F7ULL + 0x9D5619C271AECDEBULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xCEA7665CFAAF58C1ULL + 0xD725F177B8527C30ULL);
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
            aIngress = RotL64(mSource[((aIndex + 1348U)) & S_BLOCK1], 40U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 265U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 4529U)) & S_BLOCK1], 53U) ^ RotL64(mSource[((aIndex + 2705U)) & S_BLOCK1], 10U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 41U) + RotL64(aIngress, 21U)) ^ (RotL64(aCross, 5U) ^ RotL64(aPrevious, 54U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterE = (aWandererF + RotL64(aIngress, 37U)) + 9107326720193244489U;
            aOrbiterC = (aWandererB + RotL64(aPrevious, 11U)) + 10868585484401664145U;
            aOrbiterB = (((aWandererE + RotL64(aCross, 23U)) + RotL64(aCarry, 41U)) + 13637736741437846622U) + aNonceWordK;
            aOrbiterH = ((aWandererC + RotL64(aScatter, 60U)) + RotL64(aCarry, 5U)) + 6130725216183918844U;
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 19U)) + 2063834478521338187U) + aOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = ((aWandererD + RotL64(aCross, 43U)) + 8564870627911949158U) + aNonceWordB;
            aOrbiterA = (aWandererH + RotL64(aScatter, 51U)) + 6524015751064086390U;
            aOrbiterF = (((aWandererG + RotL64(aIngress, 34U)) + 9874937766875388236U) + aOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1]) + aNonceWordF;
            aOrbiterK = (aWandererK + RotL64(aCross, 5U)) + 14723718409522680894U;
            aOrbiterD = (aWandererI + RotL64(aIngress, 29U)) + 13767059954741528279U;
            aOrbiterG = (((aWandererA + RotL64(aPrevious, 53U)) + RotL64(aCarry, 57U)) + 6387608251033722169U) + aNonceWordD;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 5391425980008431000U) + aOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 11524218415655093779U) ^ aNonceWordP;
            aOrbiterB = RotL64((aOrbiterB * 12508457981779189389U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 155510463350385905U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 10554591788433641311U;
            aOrbiterC = RotL64((aOrbiterC * 5412084824127934293U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 8662160162966241542U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 5092555636369853727U;
            aOrbiterE = RotL64((aOrbiterE * 433807340167635499U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 7163345798448796101U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 695089002178413267U) ^ aNonceWordA;
            aOrbiterF = RotL64((aOrbiterF * 17302689458565434475U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 5409173939213468972U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 15349690077393827541U) ^ aOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10984681254001609841U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 12376011890751302027U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 7809614158898158383U) ^ aOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13845113198736843629U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 13031938699536449576U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 3983178190194056516U;
            aOrbiterI = RotL64((aOrbiterI * 1341678482929213405U), 37U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterG) + 5567935037909671790U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordH;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 17137042627663349797U;
            aOrbiterH = RotL64((aOrbiterH * 13535586899620672373U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 8726085717433137208U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 13154097637429217548U) ^ aNonceWordE;
            aOrbiterJ = RotL64((aOrbiterJ * 5523758597936082363U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 4030516340575723215U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 7121696965917254968U;
            aOrbiterD = RotL64((aOrbiterD * 13569584361980228493U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 12079991626282752674U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 9107326720193244489U;
            aOrbiterG = RotL64((aOrbiterG * 7225937408665051799U), 3U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterH, 57U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 30U));
            aIngress = aIngress + (RotL64(aOrbiterE, 27U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterG, 21U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 41U));
            aIngress = aIngress + RotL64(aOrbiterF, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aScatter, 50U) + RotL64(aOrbiterA, 29U)) + aOrbiterE) + aNonceWordG) + aWandererUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterA, 11U)) + aOrbiterF);
            aWandererE = aWandererE + ((((RotL64(aCross, 21U) + RotL64(aOrbiterH, 13U)) + aOrbiterE) + RotL64(aCarry, 39U)) + aNonceWordI);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterI, 46U)) + aOrbiterJ) + aWandererUpdateSaltA[((aIndex + 11U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 23U) + RotL64(aOrbiterD, 37U)) + aOrbiterH);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 37U) + RotL64(aOrbiterC, 5U)) + aOrbiterA) + aNonceWordO);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 30U) + RotL64(aOrbiterG, 27U)) + aOrbiterI) + RotL64(aCarry, 21U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 35U) + aOrbiterH) + RotL64(aOrbiterC, 21U)) + aNonceWordN);
            aWandererB = aWandererB + ((RotL64(aCross, 39U) + aOrbiterJ) + RotL64(aOrbiterB, 56U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterG, 3U)) + aOrbiterA);
            aWandererH = aWandererH + ((RotL64(aIngress, 41U) + RotL64(aOrbiterI, 39U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 42U));
            aCarry = aCarry + (RotL64(aWandererG, 53U) ^ aWandererA);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 29U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererD, 37U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 6541U)) & S_BLOCK1], 23U) ^ RotL64(mSource[((aIndex + 10899U)) & S_BLOCK1], 12U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 7496U)) & S_BLOCK1], 47U) ^ RotL64(pSnow[((aIndex + 10068U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCross, 3U)) + (RotL64(aIngress, 54U) ^ RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterC = (aWandererK + RotL64(aScatter, 21U)) + 12692813903177772178U;
            aOrbiterI = (((aWandererE + RotL64(aCross, 29U)) + RotL64(aCarry, 35U)) + 7112496446691277899U) + aNonceWordO;
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 23U)) + 2112247138290568813U) + aOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = ((aWandererG + RotL64(aIngress, 27U)) + RotL64(aCarry, 27U)) + 3699421080882855947U;
            aOrbiterB = ((aWandererI + RotL64(aCross, 48U)) + 13761832028354380922U) + aNonceWordI;
            aOrbiterE = (aWandererB + RotL64(aScatter, 3U)) + 9243822514887600214U;
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 53U)) + RotL64(aCarry, 43U)) + 6863833516853046129U;
            aOrbiterD = (aWandererC + RotL64(aIngress, 35U)) + 8863897995943098018U;
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 19U)) + 13346785686701467520U;
            aOrbiterG = (aWandererD + RotL64(aIngress, 11U)) + 15309543066305531619U;
            aOrbiterK = ((aWandererA + RotL64(aScatter, 40U)) + 17515530938817919111U) + aOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 760493237816424254U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 7282586354117620860U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2327153408185290635U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 4129706068526969105U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 7020175432730888755U;
            aOrbiterB = RotL64((aOrbiterB * 10095158356907592239U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 9102258982216515596U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 10822031305361453690U;
            aOrbiterH = RotL64((aOrbiterH * 2036205056490578491U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 12571477440964330246U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 8436347026653095199U;
            aOrbiterJ = RotL64((aOrbiterJ * 17930734781213681573U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 14214789872073941940U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 12915911919403385001U) ^ aNonceWordC;
            aOrbiterK = RotL64((aOrbiterK * 13161681603528031511U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 15443240166233851298U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 7311369180113240915U) ^ aOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13339195007946889423U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 12976516224995960015U) + aNonceWordH;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 7823308381434556721U;
            aOrbiterD = RotL64((aOrbiterD * 502385172763861451U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 4829417661664149137U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 16306394751966719700U;
            aOrbiterA = RotL64((aOrbiterA * 5294376579588592157U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 16769868341852572677U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 7107433163189177642U) ^ aOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5279050651595743649U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 11896784111967113871U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 389626690429371003U;
            aOrbiterG = RotL64((aOrbiterG * 10665914532159182181U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 8226849597052979358U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 12692813903177772178U;
            aOrbiterE = RotL64((aOrbiterE * 17909062471564422847U), 35U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterF, 3U);
            aIngress = aIngress + (RotL64(aOrbiterE, 30U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterI, 53U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 35U));
            aIngress = aIngress + (RotL64(aOrbiterA, 37U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterH, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 27U) + aOrbiterB) + RotL64(aOrbiterE, 35U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 23U)) + aOrbiterC) + aWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 43U) + aOrbiterA) + RotL64(aOrbiterD, 47U)) + aNonceWordD);
            aWandererG = aWandererG + ((RotL64(aScatter, 24U) + RotL64(aOrbiterK, 43U)) + aOrbiterF);
            aWandererD = aWandererD ^ ((((RotL64(aCross, 53U) + RotL64(aOrbiterE, 26U)) + aOrbiterK) + aNonceWordL) + aWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 19U) + RotL64(aOrbiterE, 51U)) + aOrbiterG) + RotL64(aCarry, 51U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterB, 57U)) + aOrbiterH);
            aWandererB = aWandererB + ((RotL64(aIngress, 39U) + aOrbiterB) + RotL64(aOrbiterG, 53U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 58U) + aOrbiterA) + RotL64(aOrbiterC, 37U));
            aWandererF = aWandererF + (((RotL64(aIngress, 41U) + aOrbiterA) + RotL64(aOrbiterK, 60U)) + RotL64(aCarry, 23U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterJ, 3U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 30U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + (RotL64(aWandererA, 46U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererF, 43U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 14942U)) & S_BLOCK1], 11U) ^ RotL64(mSource[((aIndex + 15587U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 12081U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((aIndex + 15586U)) & S_BLOCK1], 30U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCross, 19U) + RotL64(aPrevious, 35U)) ^ (RotL64(aIngress, 6U) + RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterJ = (((aWandererA + RotL64(aCross, 47U)) + 11410829607777684449U) + aOrbiterAssignSaltA[((aIndex + 4U)) & S_SALT1]) + aNonceWordB;
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 52U)) + RotL64(aCarry, 29U)) + 7502698839700975347U;
            aOrbiterB = (((aWandererB + RotL64(aScatter, 35U)) + RotL64(aCarry, 21U)) + 13267685058252106173U) + aOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterK = ((aWandererK + RotL64(aIngress, 43U)) + RotL64(aCarry, 11U)) + 238242706996630625U;
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 37U)) + 8184695499511454281U;
            aOrbiterE = (aWandererG + RotL64(aScatter, 21U)) + 12767823220461985403U;
            aOrbiterG = (aWandererD + RotL64(aIngress, 10U)) + 12293198423143850330U;
            aOrbiterD = (aWandererC + RotL64(aCross, 57U)) + 11149495229952495939U;
            aOrbiterC = (aWandererE + RotL64(aPrevious, 13U)) + 7556992689338382800U;
            aOrbiterI = ((aWandererH + RotL64(aIngress, 5U)) + 3431338808774134649U) + aNonceWordH;
            aOrbiterH = (aWandererF + RotL64(aCross, 29U)) + 16863099140844995099U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 17872458049880677604U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 16760153457252546974U;
            aOrbiterB = RotL64((aOrbiterB * 11225037229069712805U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 3115544493537438408U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 4359882942759752958U;
            aOrbiterE = RotL64((aOrbiterE * 561477566995575801U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 13387113067202396536U) + aNonceWordE;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 12955690074544490161U;
            aOrbiterJ = RotL64((aOrbiterJ * 12449941770827974511U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 15614054443728226807U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 1939441328066616114U;
            aOrbiterK = RotL64((aOrbiterK * 4484917074808974359U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 4599016263007782537U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 9962305629016158048U;
            aOrbiterC = RotL64((aOrbiterC * 1496184427500037279U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 8428467674122750557U) + aNonceWordF;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 3938884087806393439U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12810531094050481761U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 6018636830758044658U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 1510372000641305416U;
            aOrbiterI = RotL64((aOrbiterI * 9002834928626918247U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 17592782466215337843U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 8119921507606870360U;
            aOrbiterH = RotL64((aOrbiterH * 1299795061644535485U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 8753237702359236964U) + aOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 12389957327067768090U;
            aOrbiterG = RotL64((aOrbiterG * 4586786761936601607U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 17791633199762408683U) + aNonceWordG;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 11606494383812053915U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13041480602055778521U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 4418614662439151979U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 11410829607777684449U) ^ aOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3342270212301058781U), 43U);
            //
            aIngress = RotL64(aOrbiterJ, 29U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterI, 48U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 21U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 3U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 5U));
            aIngress = aIngress + RotL64(aOrbiterC, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aScatter, 37U) + aOrbiterD) + RotL64(aOrbiterH, 54U)) + aWandererUpdateSaltC[((aIndex + 8U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 58U) + RotL64(aOrbiterI, 29U)) + aOrbiterC) + aNonceWordJ);
            aWandererK = aWandererK ^ ((RotL64(aCross, 29U) + aOrbiterH) + RotL64(aOrbiterA, 47U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 51U) + aOrbiterJ) + RotL64(aOrbiterE, 5U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterB, 37U)) + aOrbiterJ) + aWandererUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 42U) + RotL64(aOrbiterK, 43U)) + aOrbiterF) + RotL64(aCarry, 39U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterF, 57U)) + aOrbiterA);
            aWandererD = aWandererD + ((RotL64(aScatter, 27U) + RotL64(aOrbiterA, 21U)) + aOrbiterB);
            aWandererB = aWandererB ^ (((RotL64(aCross, 23U) + aOrbiterI) + RotL64(aOrbiterG, 23U)) + aNonceWordM);
            aWandererA = aWandererA + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterG, 52U)) + aOrbiterA) + RotL64(aCarry, 47U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterA, 35U)) + aOrbiterJ) + aNonceWordP);
            //
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererA, 36U) ^ aWandererG);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 27U);
            aCarry = aCarry + RotL64(aIngress, 44U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 20942U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((aIndex + 18291U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 19418U)) & S_BLOCK1], 5U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 20175U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21535U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCarry, 56U)) ^ (RotL64(aCross, 21U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterI = (((aWandererA + RotL64(aIngress, 23U)) + RotL64(aCarry, 53U)) + 964165145848253292U) + aOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 3U)) + RotL64(aCarry, 13U)) + 10645976767204934746U;
            aOrbiterE = (aWandererH + RotL64(aCross, 30U)) + 8241612229349212650U;
            aOrbiterG = (((aWandererD + RotL64(aScatter, 21U)) + RotL64(aCarry, 39U)) + 4159196033256913347U) + aOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 51U)) + 7194795864620233507U;
            aOrbiterD = (aWandererI + RotL64(aCross, 27U)) + 7638928444536778384U;
            aOrbiterC = ((aWandererG + RotL64(aScatter, 39U)) + 11819105916503968109U) + aNonceWordL;
            aOrbiterJ = (aWandererF + RotL64(aIngress, 47U)) + 18052213302858186237U;
            aOrbiterB = ((aWandererC + RotL64(aCross, 14U)) + 8663575313970041570U) + aNonceWordO;
            aOrbiterK = (aWandererK + RotL64(aIngress, 11U)) + 16644136720439299786U;
            aOrbiterF = (aWandererE + RotL64(aScatter, 35U)) + 16930316530442679864U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 16251107616988250593U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 7171986193609401665U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3543709971414550087U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 17885046834432626644U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 7757069274715713557U;
            aOrbiterI = RotL64((aOrbiterI * 15766885299397923879U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 2212805322061155615U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 6368539134638838822U;
            aOrbiterH = RotL64((aOrbiterH * 13383744883433594259U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 5264326094252925613U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 6126345334815012938U;
            aOrbiterA = RotL64((aOrbiterA * 17180934809764905307U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 13826731214018407061U) + aNonceWordB;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 6621261811613643620U;
            aOrbiterB = RotL64((aOrbiterB * 2823596473596114171U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 5964406317285863781U) + aNonceWordE;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 2167324450276308078U;
            aOrbiterJ = RotL64((aOrbiterJ * 1098346374733634905U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 16740710162977859724U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 8236083581048717923U;
            aOrbiterC = RotL64((aOrbiterC * 4364887787000704039U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 13967473987446124012U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 5136051802217149813U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13997246005108872883U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 5842999397215390366U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 8621394946580065499U;
            aOrbiterF = RotL64((aOrbiterF * 11658023035736362355U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 18086875424872976900U) + aOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 7429246355923896047U;
            aOrbiterK = RotL64((aOrbiterK * 5077079237334961761U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 18123753993386959014U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 964165145848253292U;
            aOrbiterG = RotL64((aOrbiterG * 3178072569980307307U), 19U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterB, 47U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 51U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 42U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 39U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + RotL64(aOrbiterK, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterI, 35U));
            aWandererA = aWandererA + ((RotL64(aScatter, 14U) + RotL64(aOrbiterG, 29U)) + aOrbiterA);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 39U) + aOrbiterI) + RotL64(aOrbiterG, 48U)) + aWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aCross, 47U) + aOrbiterH) + RotL64(aOrbiterA, 11U)) + RotL64(aCarry, 51U)) + aWandererUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 35U) + aOrbiterD) + RotL64(aOrbiterJ, 41U)) + aNonceWordG);
            aWandererF = aWandererF + (((RotL64(aPrevious, 30U) + aOrbiterE) + RotL64(aOrbiterB, 27U)) + aNonceWordF);
            aWandererI = aWandererI ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterI, 53U)) + aOrbiterK);
            aWandererK = aWandererK + ((((RotL64(aScatter, 43U) + aOrbiterC) + RotL64(aOrbiterJ, 3U)) + RotL64(aCarry, 23U)) + aNonceWordK);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 19U) + aOrbiterG) + RotL64(aOrbiterK, 37U));
            aWandererC = aWandererC + ((RotL64(aScatter, 37U) + RotL64(aOrbiterF, 51U)) + aOrbiterH);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterE, 20U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 44U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererD);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + (RotL64(aWandererB, 37U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererA, 48U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 22217U)) & S_BLOCK1], 3U) ^ RotL64(mSource[((aIndex + 27002U)) & S_BLOCK1], 52U));
            aIngress ^= (RotL64(pSnow[((aIndex + 22685U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((aIndex + 26215U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 22510U)) & S_BLOCK1], 52U) ^ RotL64(aWorkLaneB[((aIndex + 27107U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 18U) + RotL64(aCross, 5U)) + (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterH = (aWandererA + RotL64(aIngress, 35U)) + 2558105147674438050U;
            aOrbiterG = ((aWandererE + RotL64(aCross, 19U)) + 15856662514774702561U) + aOrbiterAssignSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = (((aWandererD + RotL64(aScatter, 48U)) + RotL64(aCarry, 57U)) + 13346869226246584582U) + aOrbiterAssignSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = (aWandererH + RotL64(aPrevious, 29U)) + 7632111846116243973U;
            aOrbiterA = (aWandererF + RotL64(aScatter, 41U)) + 2102101361626976279U;
            aOrbiterK = ((aWandererC + RotL64(aCross, 5U)) + RotL64(aCarry, 5U)) + 5605968705067851563U;
            aOrbiterB = (aWandererG + RotL64(aIngress, 60U)) + 6842483186584326681U;
            aOrbiterI = (aWandererI + RotL64(aPrevious, 43U)) + 5559797213819425064U;
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 51U)) + 12422313931331576759U) + aNonceWordA;
            aOrbiterE = ((aWandererK + RotL64(aIngress, 37U)) + RotL64(aCarry, 29U)) + 2751024420047872601U;
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 57U)) + 11031320239359798610U) + aNonceWordF;
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 14366375309473793217U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 11971479429768505316U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10063001532313098203U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 3947595951884469542U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 17882767922372770896U;
            aOrbiterA = RotL64((aOrbiterA * 3361906348965810211U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 513871456983509223U) + aNonceWordC;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 5951677013597794294U;
            aOrbiterI = RotL64((aOrbiterI * 8508629569649935293U), 35U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterC) + 437626309049021931U) + aOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1]) + aNonceWordL;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 466674061172005705U;
            aOrbiterF = RotL64((aOrbiterF * 1310502572084891157U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 12362602809233133718U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 10525852878882195702U;
            aOrbiterE = RotL64((aOrbiterE * 17755022180514914325U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 17927000184308583095U) + aOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 566723721423470052U) ^ aNonceWordN;
            aOrbiterH = RotL64((aOrbiterH * 17710534355278632573U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 9504585484034413577U) + aOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 4614306037721859929U) ^ aNonceWordO;
            aOrbiterD = RotL64((aOrbiterD * 170807293799483539U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 1463218357720031588U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 4036696102163560633U;
            aOrbiterB = RotL64((aOrbiterB * 15389914226155130065U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 9907678911300898726U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 11804311892289601322U;
            aOrbiterJ = RotL64((aOrbiterJ * 13986106774841242253U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 6514645538508331396U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 17246364354815744899U;
            aOrbiterK = RotL64((aOrbiterK * 12800661037742526999U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 6725706155285333764U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 2558105147674438050U;
            aOrbiterG = RotL64((aOrbiterG * 6752457079901154727U), 51U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterD, 41U);
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 53U));
            aIngress = aIngress + (RotL64(aOrbiterC, 19U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 23U));
            aIngress = aIngress + RotL64(aOrbiterB, 60U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 3U) + aOrbiterG) + RotL64(aOrbiterH, 23U));
            aWandererD = aWandererD + (((RotL64(aCross, 5U) + aOrbiterI) + RotL64(aOrbiterC, 47U)) + aWandererUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 27U) + aOrbiterH) + RotL64(aOrbiterK, 39U));
            aWandererI = aWandererI + (((RotL64(aIngress, 46U) + aOrbiterE) + RotL64(aOrbiterG, 13U)) + aNonceWordM);
            aWandererG = aWandererG ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterB, 52U)) + aOrbiterJ) + aWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 29U) + aOrbiterI) + RotL64(aOrbiterD, 41U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 21U) + aOrbiterI) + RotL64(aOrbiterA, 19U));
            aWandererF = aWandererF + (((RotL64(aScatter, 51U) + RotL64(aOrbiterE, 43U)) + aOrbiterA) + RotL64(aCarry, 11U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterA, 5U)) + aOrbiterF) + aNonceWordE);
            aWandererK = aWandererK + (((RotL64(aCross, 14U) + RotL64(aOrbiterB, 56U)) + aOrbiterC) + RotL64(aCarry, 5U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 53U) + aOrbiterE) + RotL64(aOrbiterB, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 18U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 21U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererH);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 30U));
            aCarry = aCarry + RotL64(aWandererE, 37U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 31089U)) & S_BLOCK1], 28U) ^ RotL64(pSnow[((aIndex + 29257U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 28411U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 28839U)) & S_BLOCK1], 38U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 30977U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 30414U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aIngress, 41U)) ^ (RotL64(aCross, 3U) + RotL64(aPrevious, 54U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterA = (aWandererK + RotL64(aScatter, 23U)) + 966899917801652720U;
            aOrbiterG = ((aWandererI + RotL64(aIngress, 51U)) + RotL64(aCarry, 3U)) + 10996327672320748649U;
            aOrbiterB = ((aWandererE + RotL64(aCross, 30U)) + RotL64(aCarry, 37U)) + 4188171566846621107U;
            aOrbiterK = ((aWandererA + RotL64(aPrevious, 3U)) + 5886209243097387959U) + aNonceWordC;
            aOrbiterI = ((aWandererJ + RotL64(aCross, 39U)) + 14940428957136728111U) + aOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = (aWandererC + RotL64(aIngress, 43U)) + 179187285531914832U;
            aOrbiterH = (aWandererG + RotL64(aScatter, 18U)) + 6685351948936817752U;
            aOrbiterF = (((aWandererF + RotL64(aPrevious, 47U)) + RotL64(aCarry, 21U)) + 1894506461704029700U) + aNonceWordD;
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 41U)) + 4182760368636977082U) + aOrbiterAssignSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = (aWandererB + RotL64(aCross, 35U)) + 12523318028514940790U;
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 27U)) + 5059306166973366892U) + aNonceWordB;
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 5890872367917643851U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 17747338389865221534U;
            aOrbiterB = RotL64((aOrbiterB * 5306740664798049267U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 13906227834259884100U) + aOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 7152105382899756368U;
            aOrbiterI = RotL64((aOrbiterI * 6772157117358310485U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 17868101884759619240U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 11758843266314148347U) ^ aOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5919135169337501485U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 13950566197090324859U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 17278105609930477854U;
            aOrbiterJ = RotL64((aOrbiterJ * 11431842718945107359U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 9556785965646738355U) + aNonceWordK;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 841298436857932987U;
            aOrbiterK = RotL64((aOrbiterK * 15077843186688841797U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 1951515285492133830U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 15775839819330588437U) ^ aNonceWordM;
            aOrbiterD = RotL64((aOrbiterD * 7902654031401620995U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 5585458468816495436U) + aOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 17258586689032223623U;
            aOrbiterC = RotL64((aOrbiterC * 1652050227399194271U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 5254132659445988836U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 15440741734777060925U;
            aOrbiterG = RotL64((aOrbiterG * 17445581079035134067U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 16770361602586485631U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 14902616717976301965U;
            aOrbiterF = RotL64((aOrbiterF * 7757713071544143453U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 9521517757370835715U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 18241677917767801049U;
            aOrbiterE = RotL64((aOrbiterE * 16977396965907931057U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 14307634663160859644U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 966899917801652720U;
            aOrbiterH = RotL64((aOrbiterH * 17012361848398765251U), 43U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterA, 41U);
            aIngress = aIngress + (RotL64(aOrbiterF, 27U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + (RotL64(aOrbiterE, 37U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterG, 5U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterH, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 3U) + aOrbiterC) + RotL64(aOrbiterG, 21U)) + RotL64(aCarry, 43U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 19U) + aOrbiterF) + RotL64(aOrbiterC, 39U)) + aNonceWordI);
            aWandererC = aWandererC + (((RotL64(aIngress, 29U) + RotL64(aOrbiterJ, 13U)) + aOrbiterG) + aNonceWordH);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 24U) + aOrbiterF) + RotL64(aOrbiterA, 57U));
            aWandererH = aWandererH + ((RotL64(aCross, 43U) + aOrbiterI) + RotL64(aOrbiterA, 27U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 5U) + aOrbiterF) + RotL64(aOrbiterJ, 60U)) + aNonceWordE);
            aWandererE = aWandererE + ((RotL64(aIngress, 21U) + RotL64(aOrbiterB, 47U)) + aOrbiterC);
            aWandererG = aWandererG ^ ((((RotL64(aPrevious, 13U) + aOrbiterH) + RotL64(aOrbiterB, 37U)) + aNonceWordO) + aWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 41U) + aOrbiterK) + RotL64(aOrbiterD, 5U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 50U) + aOrbiterD) + RotL64(aOrbiterF, 42U));
            aWandererD = aWandererD + ((((RotL64(aIngress, 27U) + RotL64(aOrbiterE, 29U)) + aOrbiterA) + RotL64(aCarry, 57U)) + aWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 51U) ^ aWandererA);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 21U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 56U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererF, 41U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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

void TwistExpander_WaterPolo_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x875DB56D2BA3670BULL + 0xAEEF4142F5F22441ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x9DC290D34FBE2BB3ULL + 0xDB973049F3A50123ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x83B5E8BA8184E48FULL + 0xCE57B63BCF6F908BULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x9236A430A7FD1A37ULL + 0xCEF37775B6247EDDULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x916ECA4A0ADAEFE1ULL + 0xFDA44C20FC44A62EULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x9DAEE693E76F1923ULL + 0x980677D0F8FE1ECDULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x877CC8F49348685FULL + 0xA5735DA41926246CULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xC5869017A6DD1E9BULL + 0xED0DC157591D0252ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xCC8B96D08D9D2E71ULL + 0xDE7DA6FBD5645844ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xDE0F47004ED1D76FULL + 0xACA05D254E6C38BEULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xDB2E50D218F5B715ULL + 0xCC53654FC254CC31ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xF0B51A1ED4EE6BE1ULL + 0xB895B32260291F6CULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xCB88A624397BB9CDULL + 0xEB4BB38B47A29177ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xEDFCEFA039D60EEDULL + 0xDCF8C72C5196C986ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xF038F4E6F120F8BFULL + 0xB2CA15CAD10AC586ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x8CC226483D48FEA7ULL + 0xB22BC48FD82B281FULL);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 2335U)) & S_BLOCK1], 21U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 1703U)) & S_BLOCK1], 40U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 647U)) & S_BLOCK1], 19U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 2804U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aIngress, 38U)) ^ (RotL64(aCross, 57U) ^ RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterJ = ((aWandererB + RotL64(aCross, 5U)) + RotL64(aCarry, 5U)) + 15549114274303128055U;
            aOrbiterA = ((((aWandererG + RotL64(aIngress, 11U)) + RotL64(aCarry, 35U)) + 16466750056388063241U) + aOrbiterAssignSaltB[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordM;
            aOrbiterG = ((aWandererA + RotL64(aScatter, 30U)) + RotL64(aCarry, 53U)) + 12209449840836787142U;
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 19U)) + 14551496099734294336U) + aNonceWordK;
            aOrbiterF = (aWandererF + RotL64(aIngress, 35U)) + 6266576428679808622U;
            aOrbiterE = (((aWandererK + RotL64(aCross, 53U)) + 16892841575635668152U) + aOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordL;
            aOrbiterK = (aWandererJ + RotL64(aScatter, 23U)) + 7375966221423362125U;
            aOrbiterI = (aWandererC + RotL64(aPrevious, 60U)) + 11926105302821753530U;
            aOrbiterC = ((aWandererI + RotL64(aScatter, 47U)) + 16219253791550461124U) + aNonceWordG;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 7299056065319248160U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 15234001484933728439U;
            aOrbiterG = RotL64((aOrbiterG * 8182244796017018911U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 6615802589932632120U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 5481176858895819247U) ^ aOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3604590158551984877U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 17220507586542139380U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 14137921473739415340U;
            aOrbiterK = RotL64((aOrbiterK * 10634645686035907603U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 16981960446540932787U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 10897565927079518588U;
            aOrbiterA = RotL64((aOrbiterA * 418843936329303571U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 2746889569299593263U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 4894117146736361379U) ^ aNonceWordA;
            aOrbiterI = RotL64((aOrbiterI * 2656750612042673191U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 18294823016957137777U) + aNonceWordH;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 86828501068883383U;
            aOrbiterF = RotL64((aOrbiterF * 11432686669235402365U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 6322053762209547826U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 6754524552483363820U;
            aOrbiterE = RotL64((aOrbiterE * 1746163087826694641U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 7306452650619361017U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 12717201204443785828U;
            aOrbiterH = RotL64((aOrbiterH * 6121251603905574991U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 10422327053543898585U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 14786413282036348183U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8713024293107068275U), 51U);
            //
            aIngress = RotL64(aOrbiterF, 43U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterH, 24U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterJ, 19U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterG, 47U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterA, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterK, 43U)) + RotL64(aCarry, 27U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 39U) + aOrbiterI) + RotL64(aOrbiterC, 24U)) + aNonceWordD);
            aWandererE = aWandererE + ((((RotL64(aScatter, 10U) + aOrbiterA) + RotL64(aOrbiterJ, 47U)) + RotL64(aCarry, 37U)) + aWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterH, 11U)) + aOrbiterJ);
            aWandererG = aWandererG + (((RotL64(aIngress, 5U) + aOrbiterE) + RotL64(aOrbiterH, 19U)) + aWandererUpdateSaltD[((aIndex + 14U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 53U) + aOrbiterI) + RotL64(aOrbiterF, 39U)) + aNonceWordN);
            aWandererF = aWandererF + (((RotL64(aPrevious, 43U) + aOrbiterJ) + RotL64(aOrbiterG, 60U)) + aNonceWordI);
            aWandererC = aWandererC ^ (((RotL64(aCross, 60U) + aOrbiterF) + RotL64(aOrbiterC, 35U)) + aNonceWordE);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 19U) + RotL64(aOrbiterJ, 53U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererB, 13U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererA, 30U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererJ);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + RotL64(aWandererE, 51U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 14512U)) & S_BLOCK1], 12U) ^ RotL64(aFireLaneB[((aIndex + 12115U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 12622U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 8857U)) & S_BLOCK1], 53U) ^ RotL64(aFireLaneD[((aIndex + 10387U)) & S_BLOCK1], 28U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCarry, 20U) + RotL64(aIngress, 37U)) ^ (RotL64(aPrevious, 3U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterB = (aWandererD + RotL64(aPrevious, 43U)) + 17668251151213543491U;
            aOrbiterH = (((aWandererA + RotL64(aScatter, 23U)) + RotL64(aCarry, 57U)) + 16101602509895104517U) + aNonceWordN;
            aOrbiterJ = (((aWandererH + RotL64(aIngress, 19U)) + RotL64(aCarry, 47U)) + 9083915270773304935U) + aOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = (aWandererJ + RotL64(aCross, 38U)) + 12810720730318214811U;
            aOrbiterG = ((aWandererK + RotL64(aScatter, 51U)) + 18113428002071925621U) + aNonceWordB;
            aOrbiterA = ((aWandererG + RotL64(aCross, 27U)) + 1582208899354109878U) + aOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = (((aWandererB + RotL64(aPrevious, 5U)) + RotL64(aCarry, 11U)) + 4180688104819188154U) + aNonceWordI;
            aOrbiterD = (aWandererF + RotL64(aIngress, 47U)) + 8954598189262820611U;
            aOrbiterK = (aWandererI + RotL64(aCross, 14U)) + 15360094153175355879U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 8383954114668216260U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 15626783326234049197U) ^ aNonceWordG;
            aOrbiterJ = RotL64((aOrbiterJ * 15058420415480073793U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 10609978564404958066U) + aNonceWordP;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 17656516608997517984U;
            aOrbiterG = RotL64((aOrbiterG * 4590620354119899777U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 760077259110786536U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 3597338735888033063U) ^ aNonceWordH;
            aOrbiterF = RotL64((aOrbiterF * 6548831472863517621U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 4431777844935985157U) + aOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 10710423172154671296U;
            aOrbiterD = RotL64((aOrbiterD * 16267496318491473315U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 10240882795242085185U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 7826053487019825891U;
            aOrbiterI = RotL64((aOrbiterI * 15053729937684375907U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 9418883403715727353U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 11507423614799075545U;
            aOrbiterA = RotL64((aOrbiterA * 16189463984557044693U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 11545217316421066655U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 617921402135485341U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8182920764965471653U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 14456933220749921009U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 7990243583564535387U;
            aOrbiterK = RotL64((aOrbiterK * 5994900368027985469U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 14023633125757654751U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 11319146808574958827U) ^ aNonceWordO;
            aOrbiterH = RotL64((aOrbiterH * 13676159969338309307U), 39U);
            //
            aIngress = RotL64(aOrbiterF, 5U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterJ, 56U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterH, 29U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterB, 13U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterI, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 22U) + aOrbiterJ) + RotL64(aOrbiterI, 43U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 39U) + aOrbiterH) + RotL64(aOrbiterB, 19U)) + aNonceWordK);
            aWandererH = aWandererH + (((RotL64(aCross, 43U) + aOrbiterA) + RotL64(aOrbiterD, 29U)) + RotL64(aCarry, 57U));
            aWandererG = aWandererG ^ ((((RotL64(aIngress, 3U) + aOrbiterB) + RotL64(aOrbiterD, 6U)) + aNonceWordE) + aWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 35U) + aOrbiterI) + RotL64(aOrbiterB, 23U)) + RotL64(aCarry, 29U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 51U) + aOrbiterJ) + RotL64(aOrbiterA, 13U)) + aWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 11U) + aOrbiterJ) + RotL64(aOrbiterK, 57U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 56U) + aOrbiterF) + RotL64(aOrbiterJ, 52U));
            aWandererI = aWandererI + ((RotL64(aIngress, 47U) + RotL64(aOrbiterH, 35U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererG, 41U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererH, 24U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 18822U)) & S_BLOCK1], 46U) ^ RotL64(aFireLaneD[((aIndex + 18044U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 18706U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 18151U)) & S_BLOCK1], 19U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 21232U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 16872U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCross, 11U)) ^ (RotL64(aCarry, 43U) ^ RotL64(aIngress, 56U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterH = ((aWandererK + RotL64(aScatter, 29U)) + 6973892330986118220U) + aOrbiterAssignSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = (aWandererF + RotL64(aCross, 54U)) + 9886813896272094864U;
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 3U)) + 10996306582517553173U) + aOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = (((aWandererG + RotL64(aIngress, 19U)) + RotL64(aCarry, 13U)) + 8490648283899856223U) + aNonceWordH;
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 13U)) + 105141713530704655U) + aNonceWordM;
            aOrbiterB = (aWandererA + RotL64(aIngress, 24U)) + 3114337422810562588U;
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 35U)) + RotL64(aCarry, 53U)) + 980857684690886131U;
            aOrbiterJ = (((aWandererE + RotL64(aCross, 43U)) + RotL64(aCarry, 37U)) + 6562042345807072665U) + aNonceWordC;
            aOrbiterD = (aWandererH + RotL64(aIngress, 47U)) + 15665371138706353619U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 18113013571374375028U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 17405346422601997299U;
            aOrbiterG = RotL64((aOrbiterG * 11162604605443005253U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 5130876096426182506U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 1813821672299154629U;
            aOrbiterB = RotL64((aOrbiterB * 15478100342425611875U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 15793814882743306728U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 13925299440495476399U;
            aOrbiterC = RotL64((aOrbiterC * 12049601510660117401U), 41U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterC) + 9924458846049579438U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordK;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 7810034662781768090U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10310594595026622513U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 12812586478656872854U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 5709576448057435237U;
            aOrbiterI = RotL64((aOrbiterI * 9101555233909853025U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 7839807649914541516U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 4717944526755429647U;
            aOrbiterJ = RotL64((aOrbiterJ * 8515229146471335721U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 3933911971504256022U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterD) ^ 4814079680865379831U) ^ aOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterH = RotL64((aOrbiterH * 15100740696230557391U), 11U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterI) + 18352577312212175569U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 9670612998448920742U;
            aOrbiterD = RotL64((aOrbiterD * 5743579439303300553U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 72737302703035726U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 10032869372369626210U;
            aOrbiterE = RotL64((aOrbiterE * 7449905669249993731U), 47U);
            //
            aIngress = RotL64(aOrbiterJ, 29U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 60U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterA, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aScatter, 47U) + aOrbiterE) + RotL64(aOrbiterG, 3U)) + aNonceWordP);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 29U) + aOrbiterE) + RotL64(aOrbiterI, 36U)) + RotL64(aCarry, 27U)) + aNonceWordF);
            aWandererD = aWandererD ^ (((RotL64(aCross, 23U) + aOrbiterJ) + RotL64(aOrbiterC, 53U)) + aWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aIngress, 34U) + aOrbiterA) + RotL64(aOrbiterB, 47U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterI, 41U)) + aOrbiterD) + aWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 39U) + RotL64(aOrbiterE, 19U)) + aOrbiterJ);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterB, 23U)) + aOrbiterC);
            aWandererE = aWandererE + ((((RotL64(aIngress, 53U) + aOrbiterH) + RotL64(aOrbiterG, 10U)) + RotL64(aCarry, 19U)) + aNonceWordA);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 4U) + RotL64(aOrbiterJ, 27U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 39U));
            aCarry = aCarry + (RotL64(aWandererK, 4U) ^ aWandererJ);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 23U));
            aCarry = aCarry + RotL64(aWandererH, 53U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 31049U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneC[((aIndex + 28512U)) & S_BLOCK1], 34U));
            aIngress ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 31310U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32503U)) & S_BLOCK1], 40U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 27592U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 24649U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 12U) + RotL64(aPrevious, 57U)) ^ (RotL64(aCross, 27U) + RotL64(aIngress, 43U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterE = (aWandererB + RotL64(aCross, 48U)) + 17019646486641172469U;
            aOrbiterA = ((aWandererK + RotL64(aIngress, 19U)) + RotL64(aCarry, 43U)) + 12276141179299971572U;
            aOrbiterH = ((aWandererI + RotL64(aScatter, 57U)) + 3617241694029841555U) + aNonceWordC;
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 53U)) + RotL64(aCarry, 53U)) + 6967963401259371737U;
            aOrbiterG = (((aWandererJ + RotL64(aScatter, 43U)) + RotL64(aCarry, 27U)) + 6340709284279891017U) + aNonceWordO;
            aOrbiterB = (aWandererH + RotL64(aCross, 13U)) + 456065368903896482U;
            aOrbiterF = (aWandererF + RotL64(aPrevious, 26U)) + 17686765719908116203U;
            aOrbiterD = (((aWandererD + RotL64(aIngress, 39U)) + 1322045955429785736U) + aOrbiterAssignSaltB[((aIndex + 6U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterK = (((aWandererA + RotL64(aScatter, 35U)) + 5163772703302372887U) + aOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordH;
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 13268431135020363252U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 6538789950366849332U;
            aOrbiterH = RotL64((aOrbiterH * 5352960308459065837U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 10390344544314544893U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 5087084271300584267U) ^ aOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15149302947570776165U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 13423071121590981727U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 18324443012024134729U;
            aOrbiterE = RotL64((aOrbiterE * 15814349432207734533U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 4129091815978464507U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 17024797553831962245U;
            aOrbiterC = RotL64((aOrbiterC * 3137753479364378175U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 6501545108779991661U) + aNonceWordK;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 11930037791867597447U;
            aOrbiterK = RotL64((aOrbiterK * 4904739567549702851U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 4667298703308315851U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 6315980380900062127U) ^ aOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12080555704907924637U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 12732382340390769888U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 7792095326183864547U) ^ aNonceWordL;
            aOrbiterA = RotL64((aOrbiterA * 12645556660611824631U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 17428384983571405782U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 3193205313177048443U) ^ aOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14488006565106259731U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 2813743367131107264U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 2742138679703780981U;
            aOrbiterF = RotL64((aOrbiterF * 18356569025783532225U), 53U);
            //
            aIngress = RotL64(aOrbiterA, 60U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + (RotL64(aOrbiterB, 39U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterF, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aIngress, 19U) + aOrbiterK) + RotL64(aOrbiterA, 48U)) + aNonceWordN);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 14U) + RotL64(aOrbiterD, 23U)) + aOrbiterG);
            aWandererA = aWandererA + (((RotL64(aCross, 43U) + aOrbiterD) + RotL64(aOrbiterB, 53U)) + aNonceWordP);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterD, 29U)) + aOrbiterE) + aWandererUpdateSaltE[((aIndex + 20U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 23U) + RotL64(aOrbiterC, 19U)) + aOrbiterD);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 4U) + aOrbiterA) + RotL64(aOrbiterC, 13U));
            aWandererF = aWandererF + ((((RotL64(aCross, 37U) + aOrbiterF) + RotL64(aOrbiterD, 35U)) + RotL64(aCarry, 39U)) + aNonceWordB);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 57U) + aOrbiterA) + RotL64(aOrbiterG, 39U)) + aNonceWordE);
            aWandererK = aWandererK + ((((RotL64(aIngress, 51U) + aOrbiterH) + RotL64(aOrbiterE, 60U)) + RotL64(aCarry, 51U)) + aWandererUpdateSaltD[((aIndex + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 58U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 53U));
            aCarry = aCarry + RotL64(aWandererF, 21U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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

void TwistExpander_WaterPolo_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterF = 0;
    std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x8DE9382C20D97FD7ULL + 0x8FA905129B22E530ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xC2E6D22FEB1CC99FULL + 0xB3F9DD49031BCC6CULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xE44615BC7212566DULL + 0xCE3AB9D988C256AAULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x9F1B8943568EBADFULL + 0xC7CE06E27DC0075DULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xAF055B7A9293BD7BULL + 0x9F427FADCB5F2ADBULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xFEAE152D387A664DULL + 0x97C1F4834E2DFA4FULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xCDB39B75ADC19B61ULL + 0xA98EF938EEAEF6FAULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x92718D264D35525BULL + 0xA320C8B4724FE5BEULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xBAA255269DB2BA29ULL + 0xD1CD72C52C984DDFULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xF2971567B988CA3FULL + 0xC63AFA22E0527EA9ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x921E4BEC075E6D9FULL + 0x92E9C81FFDB86E1BULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xFD156389E3FD3019ULL + 0xA64E34A2BF2F3063ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x97BBC1D90FA906C7ULL + 0xD4AB50D82A014075ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xA6D9445755FA7261ULL + 0x844EE16D57ECB3ACULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xD4CCB32B93D1B977ULL + 0xED70D7AD4FAE64BFULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xF45C2DA11FA97FFBULL + 0x8C9736B6BACD119DULL);
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
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneD, aOperationLaneC, aOperationLaneD, aWorkLaneA, aFireLaneA, aWorkLaneB, aFireLaneC, aWorkLaneC, aFireLaneB
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 7021U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneB[((aIndex + 2345U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 5517U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 7450U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 7257U)) & S_BLOCK1], 20U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aPrevious, 57U)) + (RotL64(aIngress, 26U) ^ RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 37U)) + RotL64(aCarry, 5U)) + 6243113109470883144U;
            aOrbiterF = (((aWandererK + RotL64(aCross, 28U)) + RotL64(aCarry, 23U)) + 3891552123999605832U) + aNonceWordP;
            aOrbiterD = (((aWandererF + RotL64(aScatter, 19U)) + 8758797898587019128U) + aOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordD;
            aOrbiterH = (((aWandererA + RotL64(aIngress, 53U)) + 1005891374086408851U) + aOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordM;
            aOrbiterJ = (((aWandererC + RotL64(aScatter, 5U)) + RotL64(aCarry, 43U)) + 3713426782180050764U) + aNonceWordI;
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 18358143862391573534U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterB) ^ 17504394029693712404U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterD = RotL64((aOrbiterD * 3391716204095092531U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 5312729289027417014U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 2560873623431186029U;
            aOrbiterB = RotL64((aOrbiterB * 16843728573219210173U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 16309322822806704211U) + aNonceWordB;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 10195513918020652600U) ^ aOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14569219741824123715U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 2552116263258744287U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 7732784879810980089U;
            aOrbiterH = RotL64((aOrbiterH * 15041929399477790999U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 16499127570665381507U) + aOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 10890036715535519036U) ^ aOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9065115450010475187U), 3U);
            //
            aIngress = RotL64(aOrbiterF, 23U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterH, 58U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterJ, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((((RotL64(aIngress, 57U) + aOrbiterH) + RotL64(aOrbiterF, 10U)) + aNonceWordJ) + aWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 6U) + aOrbiterJ) + RotL64(aOrbiterD, 23U)) + RotL64(aCarry, 43U)) + aNonceWordE);
            aWandererD = aWandererD ^ ((((RotL64(aScatter, 21U) + RotL64(aOrbiterD, 47U)) + aOrbiterH) + aNonceWordA) + aWandererUpdateSaltA[((aIndex + 18U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 29U) + aOrbiterB) + RotL64(aOrbiterD, 35U)) + RotL64(aCarry, 11U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterF, 57U)) + aOrbiterD) + aNonceWordH);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererD, 3U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 10044U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneC[((aIndex + 9358U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 13325U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 9521U)) & S_BLOCK1], 24U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 11153U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 12423U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCarry, 35U) + RotL64(aIngress, 6U)) + (RotL64(aPrevious, 19U) ^ RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterI = (((aWandererA + RotL64(aIngress, 23U)) + RotL64(aCarry, 57U)) + 4259993311776766595U) + aOrbiterAssignSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = ((aWandererH + RotL64(aScatter, 58U)) + 2857813330021126753U) + aNonceWordL;
            aOrbiterJ = (((aWandererK + RotL64(aCross, 5U)) + RotL64(aCarry, 39U)) + 1345396841329442896U) + aNonceWordF;
            aOrbiterK = (((aWandererE + RotL64(aPrevious, 41U)) + 320992148982301024U) + aOrbiterAssignSaltD[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordC;
            aOrbiterD = (((aWandererJ + RotL64(aScatter, 13U)) + RotL64(aCarry, 27U)) + 5619109532065293074U) + aNonceWordJ;
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 10380157329426706345U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 12449831150625409695U;
            aOrbiterJ = RotL64((aOrbiterJ * 3354095240459774437U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 7847096607042268396U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 11707184096803214678U) ^ aNonceWordD;
            aOrbiterB = RotL64((aOrbiterB * 1959476948106553973U), 5U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterJ) + 9893643746186827088U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordO;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 333687403830908774U;
            aOrbiterI = RotL64((aOrbiterI * 17911256836121454271U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 13837360705077441580U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 4367119682175710689U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10295744669174603401U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 1193493435041306784U) + aOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 15062951612027370606U;
            aOrbiterD = RotL64((aOrbiterD * 2509383510565136549U), 13U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterB, 19U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 6U));
            aIngress = aIngress + RotL64(aOrbiterK, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterD, 35U)) + aOrbiterB) + aNonceWordB);
            aWandererJ = aWandererJ + (((((RotL64(aCross, 43U) + RotL64(aOrbiterJ, 19U)) + aOrbiterI) + RotL64(aCarry, 47U)) + aNonceWordM) + aWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 34U) + RotL64(aOrbiterK, 3U)) + aOrbiterI);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 19U) + aOrbiterI) + RotL64(aOrbiterB, 58U)) + RotL64(aCarry, 23U)) + aWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterD, 43U)) + aOrbiterI) + aNonceWordA);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + (RotL64(aWandererJ, 21U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererH, 11U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_c loop 3
        // ingress from: aWorkLaneB, aOperationLaneD, aFireLaneC
        // ingress directions: aWorkLaneB forward forced, aOperationLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aWorkLaneA, aOperationLaneB, aOperationLaneC
        // cross directions: aWorkLaneA backward forced, aOperationLaneB backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 21144U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneD[((aIndex + 19423U)) & S_BLOCK1], 12U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 17411U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16573U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 21568U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aOperationLaneC[((aIndex + 20084U)) & S_BLOCK1], 18U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aIngress, 51U) + RotL64(aCarry, 22U)) ^ (RotL64(aCross, 39U) ^ RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterD = (((aWandererD + RotL64(aScatter, 37U)) + RotL64(aCarry, 37U)) + 6342299552323486695U) + aOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = ((((aWandererH + RotL64(aIngress, 27U)) + RotL64(aCarry, 3U)) + 12692748514781367538U) + aOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1]) + aNonceWordN;
            aOrbiterK = (((aWandererJ + RotL64(aPrevious, 3U)) + RotL64(aCarry, 21U)) + 8202639945493229155U) + aNonceWordF;
            aOrbiterI = ((aWandererG + RotL64(aCross, 46U)) + 4439975701793231639U) + aNonceWordL;
            aOrbiterB = ((aWandererE + RotL64(aIngress, 13U)) + 16774235182859553759U) + aNonceWordE;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 8764155413335405667U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 7167848811974967685U;
            aOrbiterK = RotL64((aOrbiterK * 1052856924757654735U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 16768278912125334220U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 9090838954826296201U;
            aOrbiterI = RotL64((aOrbiterI * 5459329624017272077U), 19U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterD) + 7644075729758006298U) + aOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1]) + aNonceWordO;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 17326182797908071215U;
            aOrbiterJ = RotL64((aOrbiterJ * 2408330168749256075U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 16158809721888137555U) + aNonceWordJ;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 8029938783858263694U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12628072435324195483U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 8716553521415553404U) + aOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 7012599977009208840U;
            aOrbiterB = RotL64((aOrbiterB * 8775355876188948851U), 57U);
            //
            aIngress = RotL64(aOrbiterJ, 47U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterB, 13U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterD, 34U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((((RotL64(aIngress, 28U) + aOrbiterJ) + RotL64(aOrbiterK, 11U)) + aNonceWordK) + aWandererUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 51U) + RotL64(aOrbiterB, 48U)) + aOrbiterI) + RotL64(aCarry, 3U)) + aNonceWordA);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 19U) + aOrbiterJ) + RotL64(aOrbiterI, 29U)) + aNonceWordC);
            aWandererH = aWandererH + ((((RotL64(aCross, 11U) + RotL64(aOrbiterD, 57U)) + aOrbiterB) + RotL64(aCarry, 39U)) + aNonceWordM);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 39U) + aOrbiterI) + RotL64(aOrbiterK, 3U)) + aWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererG, 42U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererH, 21U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 26952U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 32122U)) & S_BLOCK1], 56U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 28471U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27726U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 32638U)) & S_BLOCK1], 34U));
            aCross ^= (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 28430U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneA[((aIndex + 30234U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aIngress, 11U) + RotL64(aCarry, 53U)) + (RotL64(aPrevious, 23U) ^ RotL64(aCross, 36U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterA = (aWandererB + RotL64(aScatter, 43U)) + 12849591986267890852U;
            aOrbiterD = ((aWandererD + RotL64(aCross, 29U)) + RotL64(aCarry, 37U)) + 8232614804696815750U;
            aOrbiterI = (((aWandererJ + RotL64(aPrevious, 56U)) + RotL64(aCarry, 21U)) + 12141567259210877281U) + aOrbiterAssignSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = ((((aWandererG + RotL64(aIngress, 11U)) + RotL64(aCarry, 53U)) + 2928641981037885644U) + aOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordA;
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 19U)) + 980733350554783938U) + aNonceWordD;
            //
            aOrbiterA = (((aOrbiterA + aOrbiterD) + 2683985177993350746U) + aOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 14532148403815527355U;
            aOrbiterI = RotL64((aOrbiterI * 15985362037094864225U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 7736296629433884203U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 10428437770166310549U) ^ aNonceWordI;
            aOrbiterJ = RotL64((aOrbiterJ * 326634742742373401U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 18327174144859461029U) + aNonceWordE;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 6810436935194432002U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2715987179577753597U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 12606153309690753435U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 17123256945895150555U) ^ aOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13469111258504672565U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 9057777759026189541U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterJ) ^ 16478485918911194442U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterD = RotL64((aOrbiterD * 11054247078884894131U), 21U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterI, 47U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 57U));
            aIngress = aIngress + RotL64(aOrbiterA, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterJ, 23U)) + aOrbiterA) + RotL64(aCarry, 41U)) + aWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 12U) + aOrbiterA) + RotL64(aOrbiterI, 13U)) + aWandererUpdateSaltF[((aIndex + 20U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 27U) + aOrbiterB) + RotL64(aOrbiterI, 54U)) + RotL64(aCarry, 53U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterD, 41U)) + aOrbiterA) + aNonceWordN);
            aWandererI = aWandererI + (((RotL64(aIngress, 57U) + RotL64(aOrbiterJ, 3U)) + aOrbiterB) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererB, 60U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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

void TwistExpander_WaterPolo_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xFC1065AF5597492BULL + 0x8C9A26A1BC337D4DULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xA52A12A18B84DF63ULL + 0xFDD9621AFC4B92C1ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xB443FA71876D8F1FULL + 0xF33616B06FBAB158ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xFB77E14FB16D1D0BULL + 0xD84143F9A973E398ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x88159D2ABD2A4EFDULL + 0xE9CCE95D86096D83ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xC7D20028C38B48FBULL + 0x8B42A43A3461F2B3ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xC4F82DE8D76FD955ULL + 0xB93625D0766D74E6ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x91AD9F491BDC9A81ULL + 0xBE02A9AADA6295E1ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x979257B3C8B96697ULL + 0x93DFEFE35CCA19EDULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xEB81BE437A860B63ULL + 0x956236394DE40608ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xA21251B1A7A75D27ULL + 0xA47D02604A076777ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xB48F6253D6B0410DULL + 0xC380AE0885F78711ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xDBCBD8E3FFEBDF55ULL + 0xA5E4AB3B5788C404ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x8E14D2F50D04F057ULL + 0xCC82F2FD9657427EULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xABDF038BEEE17731ULL + 0xEF94EE9E8AD673AAULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xB7792EEF5B5C337BULL + 0xD9DEB2E5C9009F84ULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneA, aExpandLaneC, aExpandLaneD, aFireLaneD, aWorkLaneA, aFireLaneC, aFireLaneB, aWorkLaneB, aOperationLaneB, aOperationLaneC, aWorkLaneC, aOperationLaneA, aOperationLaneD
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // kdf_a_loop_d loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneA
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aFireLaneD
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aFireLaneD backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 400U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((aIndex + 4329U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 7649U)) & S_BLOCK1], 48U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5230U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 3773U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 946U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aPrevious, 6U) ^ RotL64(aCarry, 19U)) + (RotL64(aIngress, 37U) + RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterA = (aWandererG + RotL64(aPrevious, 21U)) + 6318740973868639425U;
            aOrbiterB = ((aWandererB + RotL64(aIngress, 37U)) + 5487840061430920881U) + aOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = (((aWandererK + RotL64(aScatter, 58U)) + RotL64(aCarry, 27U)) + 10258706763248072672U) + aNonceWordC;
            aOrbiterD = ((aWandererJ + RotL64(aCross, 51U)) + RotL64(aCarry, 53U)) + 18356875269730338208U;
            aOrbiterH = ((aWandererH + RotL64(aPrevious, 43U)) + 12883160282903147010U) + aNonceWordE;
            aOrbiterE = (((aWandererC + RotL64(aIngress, 5U)) + RotL64(aCarry, 41U)) + 1010140474942697730U) + aNonceWordG;
            aOrbiterJ = (((aWandererE + RotL64(aScatter, 27U)) + 17733939421700898293U) + aOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordF;
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 13693055887924981201U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterA) ^ 14574732452793385269U) ^ aOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterI = RotL64((aOrbiterI * 9373765929885750185U), 57U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterI) + 10832873941223609012U) + aOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1]) + aNonceWordH;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 8212600587135328040U;
            aOrbiterH = RotL64((aOrbiterH * 5334613996794796145U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 5312744319781971178U) + aNonceWordB;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 6173741211706546923U;
            aOrbiterE = RotL64((aOrbiterE * 12854414066390848249U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 3693249147883790810U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 18365859989736602556U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3348463719324104997U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 10645056678337549771U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 1175668356822251045U;
            aOrbiterB = RotL64((aOrbiterB * 6579675292775345579U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 13556844570541823717U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 4790355739411849736U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4083544011788850307U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 14905575502272644116U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 17047244574558476634U) ^ aNonceWordM;
            aOrbiterJ = RotL64((aOrbiterJ * 2356386971503880047U), 35U);
            //
            aIngress = RotL64(aOrbiterH, 39U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterJ, 14U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterB, 5U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterI, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 57U) + aOrbiterA) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 13U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 47U) + aOrbiterE) + RotL64(aOrbiterD, 22U)) + aWandererUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aScatter, 14U) + aOrbiterH) + RotL64(aOrbiterB, 35U)) + RotL64(aCarry, 47U)) + aNonceWordN);
            aWandererE = aWandererE ^ ((RotL64(aCross, 41U) + aOrbiterJ) + RotL64(aOrbiterI, 47U));
            aWandererC = aWandererC + ((((RotL64(aIngress, 27U) + aOrbiterI) + RotL64(aOrbiterD, 29U)) + aNonceWordD) + aWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 35U) + aOrbiterH) + RotL64(aOrbiterJ, 53U));
            aWandererB = aWandererB + (((RotL64(aCross, 3U) + aOrbiterJ) + RotL64(aOrbiterD, 41U)) + aNonceWordP);
            //
            aCarry = aCarry + (RotL64(aWandererB, 26U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 5U));
            aCarry = aCarry + RotL64(aWandererC, 43U);
            aCarry = aCarry + RotL64(aIngress, 48U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 2
        // ingress from: aWorkLaneA, aExpandLaneC, aFireLaneC
        // ingress directions: aWorkLaneA forward forced, aExpandLaneC forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD, aFireLaneB
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward forced, aFireLaneB backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 13829U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneC[((aIndex + 10319U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 12792U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 11316U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 9048U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 10946U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aIngress, 41U) ^ RotL64(aCarry, 12U)) ^ (RotL64(aCross, 27U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterH = ((aWandererH + RotL64(aPrevious, 53U)) + RotL64(aCarry, 5U)) + 9023059520606551446U;
            aOrbiterC = ((((aWandererK + RotL64(aScatter, 27U)) + RotL64(aCarry, 21U)) + 662441755115638133U) + aOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1]) + aNonceWordH;
            aOrbiterA = ((aWandererD + RotL64(aIngress, 5U)) + RotL64(aCarry, 35U)) + 16957253361196144712U;
            aOrbiterE = ((aWandererB + RotL64(aCross, 37U)) + 7840955025765308605U) + aNonceWordK;
            aOrbiterI = ((aWandererE + RotL64(aScatter, 19U)) + 346855809270395799U) + aNonceWordG;
            aOrbiterB = (aWandererF + RotL64(aPrevious, 12U)) + 16099139781586668343U;
            aOrbiterK = ((aWandererC + RotL64(aCross, 47U)) + 3706457327118322098U) + aOrbiterAssignSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 12166825885547622870U) + aNonceWordL;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 7792658665720344200U;
            aOrbiterA = RotL64((aOrbiterA * 16305542632794270697U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 7128477606152986326U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 11116533962780290084U;
            aOrbiterI = RotL64((aOrbiterI * 11993485572912492297U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 10443889548568288532U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 4402387036946561017U;
            aOrbiterE = RotL64((aOrbiterE * 9032964741841833277U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 13002706161178447654U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 13929727277530310708U;
            aOrbiterK = RotL64((aOrbiterK * 7005639090871200285U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 10949073760696935106U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 15405923432006783533U;
            aOrbiterC = RotL64((aOrbiterC * 17989565878445202495U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 18096057968822208905U) + aOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = (((aOrbiterH ^ aOrbiterB) ^ 3032155040484574973U) ^ aOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterH = RotL64((aOrbiterH * 448597307502544605U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 17462076466907467134U) + aNonceWordD;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 15471015427013701406U;
            aOrbiterB = RotL64((aOrbiterB * 6113474000571976139U), 57U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterB, 13U);
            aIngress = aIngress + (RotL64(aOrbiterK, 4U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterH, 27U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterA, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterA, 53U)) + aOrbiterI) + RotL64(aCarry, 29U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 51U) + aOrbiterC) + RotL64(aOrbiterK, 13U)) + aWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 43U) + aOrbiterH) + RotL64(aOrbiterA, 60U)) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 12U) + RotL64(aOrbiterC, 23U)) + aOrbiterI) + aWandererUpdateSaltC[((aIndex + 20U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 27U) + RotL64(aOrbiterC, 5U)) + aOrbiterB);
            aWandererE = aWandererE ^ (((RotL64(aCross, 21U) + aOrbiterB) + RotL64(aOrbiterA, 29U)) + aNonceWordB);
            aWandererK = aWandererK + (((RotL64(aPrevious, 57U) + aOrbiterK) + RotL64(aOrbiterE, 35U)) + aNonceWordJ);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererB);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + RotL64(aWandererE, 12U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 3
        // ingress from: aWorkLaneB, aExpandLaneD, aOperationLaneB
        // ingress directions: aWorkLaneB forward forced, aExpandLaneD forward forced, aOperationLaneB forward/backward random
        // cross from: aWorkLaneA, aExpandLaneB, aOperationLaneC
        // cross directions: aWorkLaneA backward forced, aExpandLaneB backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 22269U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((aIndex + 19912U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aOperationLaneB[((aIndex + 20642U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18848U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 20472U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 19273U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCarry, 27U) + RotL64(aPrevious, 5U)) ^ (RotL64(aIngress, 52U) + RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 41U)) + 3621877681473089725U) + aNonceWordD;
            aOrbiterG = (aWandererE + RotL64(aCross, 20U)) + 4451752751536414717U;
            aOrbiterA = ((aWandererF + RotL64(aIngress, 51U)) + RotL64(aCarry, 5U)) + 11371625415377772117U;
            aOrbiterF = (((aWandererD + RotL64(aScatter, 57U)) + RotL64(aCarry, 23U)) + 6046792758881150619U) + aNonceWordB;
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 11U)) + RotL64(aCarry, 37U)) + 8213166120394461682U;
            aOrbiterE = (((aWandererK + RotL64(aIngress, 29U)) + 4343156661140422645U) + aOrbiterAssignSaltE[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordG;
            aOrbiterH = ((aWandererJ + RotL64(aCross, 3U)) + 11105271483234947905U) + aOrbiterAssignSaltA[((aIndex + 26U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 348904609985341372U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 12924652822526858767U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2801892489296408735U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 7461211697358520287U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 16551553555297890558U) ^ aOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16432952324635746293U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 11908056404140782995U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 9147367258259948715U;
            aOrbiterH = RotL64((aOrbiterH * 10777628928376261667U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 8876461054692728610U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 10546855952702525404U;
            aOrbiterG = RotL64((aOrbiterG * 10071104785895309677U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 4748636139110443794U) + aNonceWordE;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 783046909529525098U) ^ aOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8969157702460927215U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 16683965945838696665U) + aNonceWordP;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 12385412690177109575U;
            aOrbiterJ = RotL64((aOrbiterJ * 10795062772707143187U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 8210546822184469023U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 13146493623236979963U;
            aOrbiterD = RotL64((aOrbiterD * 13199947810161148155U), 57U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterF, 4U);
            aIngress = aIngress + (RotL64(aOrbiterA, 47U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterJ, 11U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterD, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterA, 13U)) + aOrbiterF);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 5U) + RotL64(aOrbiterJ, 57U)) + aOrbiterD);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 13U) + aOrbiterE) + RotL64(aOrbiterF, 41U)) + aNonceWordA);
            aWandererD = aWandererD + ((((RotL64(aCross, 60U) + RotL64(aOrbiterG, 5U)) + aOrbiterJ) + RotL64(aCarry, 57U)) + aNonceWordO);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterE, 48U)) + aOrbiterG);
            aWandererK = aWandererK + (((((RotL64(aScatter, 35U) + RotL64(aOrbiterE, 35U)) + aOrbiterH) + RotL64(aCarry, 29U)) + aNonceWordH) + aWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((((RotL64(aCross, 53U) + aOrbiterF) + RotL64(aOrbiterD, 23U)) + aNonceWordC) + aWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererE, 18U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 4
        // ingress from: aWorkLaneC, aWorkLaneA, aOperationLaneA
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aOperationLaneA forward/backward random
        // cross from: aWorkLaneB, aExpandLaneC, aOperationLaneD
        // cross directions: aWorkLaneB backward forced, aExpandLaneC backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 30492U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 28819U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 29702U)) & S_BLOCK1], 30U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31279U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 32453U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 27138U)) & S_BLOCK1], 20U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aIngress, 35U)) ^ (RotL64(aPrevious, 10U) + RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterJ = (((aWandererA + RotL64(aPrevious, 53U)) + RotL64(aCarry, 23U)) + 3684295017013759987U) + aOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = (((aWandererG + RotL64(aScatter, 39U)) + 6740408842457292881U) + aOrbiterAssignSaltF[((aIndex + 22U)) & S_SALT1]) + aNonceWordI;
            aOrbiterH = (aWandererH + RotL64(aIngress, 13U)) + 4563975890702399441U;
            aOrbiterB = ((aWandererC + RotL64(aCross, 47U)) + RotL64(aCarry, 53U)) + 797804144825287940U;
            aOrbiterG = (((aWandererK + RotL64(aIngress, 4U)) + RotL64(aCarry, 37U)) + 2763779540450101303U) + aNonceWordO;
            aOrbiterE = (aWandererJ + RotL64(aCross, 19U)) + 13211846164102089685U;
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 27U)) + 15214578447281401982U) + aNonceWordB;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 13745208628754232427U) + aOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 17358621225969190747U) ^ aNonceWordA;
            aOrbiterH = RotL64((aOrbiterH * 5325024317338823061U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 779739369960480023U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 4370963533701407813U) ^ aNonceWordD;
            aOrbiterG = RotL64((aOrbiterG * 3123135216876641039U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 6061333005507739975U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 3589705340762734456U;
            aOrbiterK = RotL64((aOrbiterK * 16499293983611196967U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 10607697666369230567U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 9356757995305239271U;
            aOrbiterB = RotL64((aOrbiterB * 10945513661439954731U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 10093033335903048138U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 11037328061699834100U;
            aOrbiterE = RotL64((aOrbiterE * 11189760551792389605U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 558431161176115540U) + aNonceWordL;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 17795680919453449358U) ^ aOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3910117359996283803U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 6096779391116214109U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterB) ^ 17594243286880690775U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterF = RotL64((aOrbiterF * 12655610181937429915U), 3U);
            //
            aIngress = RotL64(aOrbiterF, 51U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterG, 28U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterE, 19U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterJ, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterB, 29U)) + aOrbiterG) + aWandererUpdateSaltE[((aIndex + 16U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aCross, 35U) + RotL64(aOrbiterJ, 11U)) + aOrbiterH) + RotL64(aCarry, 35U)) + aWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 29U) + aOrbiterH) + RotL64(aOrbiterB, 5U));
            aWandererK = aWandererK + (((RotL64(aIngress, 13U) + aOrbiterJ) + RotL64(aOrbiterK, 41U)) + aNonceWordJ);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 21U) + aOrbiterK) + RotL64(aOrbiterE, 58U)) + aNonceWordN);
            aWandererG = aWandererG + (((RotL64(aPrevious, 3U) + aOrbiterB) + RotL64(aOrbiterF, 35U)) + RotL64(aCarry, 13U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 42U) + RotL64(aOrbiterG, 19U)) + aOrbiterH) + aNonceWordC);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 52U) ^ aWandererC);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererA, 43U);
            aCarry = aCarry + RotL64(aIngress, 58U);
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

void TwistExpander_WaterPolo_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x91629F59DD28A31DULL + 0x8837E391D1E1BEB6ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xC30DE16EAB5078DFULL + 0x9BEC49C658E7651BULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xBBE79A11D1990791ULL + 0xE2D2648429AE2987ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x8A4E12100C464613ULL + 0xA23FE24534C5A9FBULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x906C1AFAA00E8FBFULL + 0x8E2F241A7D51E729ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x9CBEFE21D5B70BB9ULL + 0xCBEC094D63877B48ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xF7C4EA6EB47B44F9ULL + 0xD5CCC3D288A314E0ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xC02D32052CCA6317ULL + 0xDFACE4721D5CBA25ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xB27696E663868973ULL + 0x9CA0BDBC56C3C603ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xD9C5A16DCD2E045DULL + 0x9035BE38C74F52E5ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x8C028449820D7091ULL + 0x8712B4D297A6525AULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xEB307F454178EC59ULL + 0xC3B099BB0F0514E2ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x8642AD7CBEE9F7D5ULL + 0xA4E43A27D1759233ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xDC7E245C40DCCFDFULL + 0xC747B42E0545DAF6ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xBE6F646D81967AEBULL + 0xF8A5A258AC71348FULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x92F7492DF24BDFFBULL + 0x8FD2D4F8DB36C0CBULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aOperationLaneD, aWorkLaneC, aWorkLaneD, aOperationLaneB, aExpandLaneA, aOperationLaneA, aFireLaneC, aExpandLaneB, aFireLaneD, aOperationLaneC, aExpandLaneC, aFireLaneA, aFireLaneB
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 7503U)) & S_BLOCK1], 50U) ^ RotL64(aWorkLaneB[((aIndex + 7795U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 1548U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 3152U)) & S_BLOCK1], 36U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 192U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 754U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 13U) ^ RotL64(aPrevious, 43U)) + (RotL64(aIngress, 56U) + RotL64(aCross, 29U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterI = (aWandererH + RotL64(aIngress, 41U)) + 4739486756133131180U;
            aOrbiterD = (((aWandererA + RotL64(aScatter, 27U)) + 16089707555501328184U) + aOrbiterAssignSaltF[((aIndex + 16U)) & S_SALT1]) + aNonceWordK;
            aOrbiterH = ((aWandererK + RotL64(aCross, 13U)) + RotL64(aCarry, 53U)) + 15310047330238536453U;
            aOrbiterE = (((aWandererI + RotL64(aPrevious, 47U)) + RotL64(aCarry, 5U)) + 7901411596386834955U) + aNonceWordE;
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 35U)) + RotL64(aCarry, 23U)) + 4357555491060982163U;
            aOrbiterC = ((aWandererB + RotL64(aCross, 56U)) + 15667085602825720102U) + aNonceWordF;
            aOrbiterB = (((aWandererJ + RotL64(aPrevious, 19U)) + 8520635334382269253U) + aOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1]) + aNonceWordC;
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 1772509779231068315U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 15336170957886025677U;
            aOrbiterH = RotL64((aOrbiterH * 10996880551392077399U), 57U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterE) + 8628770833489469980U) + aOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1]) + aNonceWordI;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 15469234024247246228U;
            aOrbiterJ = RotL64((aOrbiterJ * 8905266995119987947U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 10796430900884288328U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 10660110397012853289U) ^ aNonceWordA;
            aOrbiterI = RotL64((aOrbiterI * 9140007610912037461U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 11202284258711214794U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterD) ^ 17509491802893182994U) ^ aOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterE = RotL64((aOrbiterE * 9329107599972703671U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 16212572740740103554U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 2190030203761579226U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3101886685668871045U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 12014337082293041909U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 3733531010807001506U) ^ aNonceWordH;
            aOrbiterC = RotL64((aOrbiterC * 5797362244066062299U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 7100994963061975529U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 17837541162838600258U;
            aOrbiterB = RotL64((aOrbiterB * 8745987361678166553U), 13U);
            //
            aIngress = RotL64(aOrbiterJ, 21U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + (RotL64(aOrbiterD, 13U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterB, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 29U) + aOrbiterI) + RotL64(aOrbiterH, 57U)) + aNonceWordB);
            aWandererB = aWandererB + (((RotL64(aIngress, 51U) + RotL64(aOrbiterD, 47U)) + aOrbiterE) + RotL64(aCarry, 29U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterC, 35U)) + aOrbiterI) + aNonceWordN);
            aWandererI = aWandererI + (((RotL64(aScatter, 13U) + aOrbiterI) + RotL64(aOrbiterD, 6U)) + aWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((((RotL64(aCross, 37U) + RotL64(aOrbiterJ, 41U)) + aOrbiterB) + aNonceWordO) + aWandererUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 58U) + RotL64(aOrbiterJ, 27U)) + aOrbiterC) + RotL64(aCarry, 43U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterB, 21U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererH, 53U) ^ aWandererJ);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 60U));
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererK, 43U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aOperationLaneA
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aOperationLaneA forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aFireLaneC
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aFireLaneC backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 11186U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneC[((aIndex + 13707U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 10952U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12351U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 14052U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 11429U)) & S_BLOCK1], 6U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aPrevious, 60U) + RotL64(aCross, 27U)) ^ (RotL64(aCarry, 43U) + RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterK = (aWandererA + RotL64(aCross, 5U)) + 4773124477323378268U;
            aOrbiterJ = ((((aWandererH + RotL64(aScatter, 35U)) + RotL64(aCarry, 57U)) + 16848723289435796005U) + aOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1]) + aNonceWordN;
            aOrbiterB = (aWandererD + RotL64(aIngress, 19U)) + 13846642134917107058U;
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 58U)) + RotL64(aCarry, 29U)) + 6472057872482789939U;
            aOrbiterI = ((((aWandererJ + RotL64(aCross, 41U)) + RotL64(aCarry, 41U)) + 2747019500690707226U) + aOrbiterAssignSaltD[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordC;
            aOrbiterH = (aWandererG + RotL64(aIngress, 13U)) + 9003965289739733880U;
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 29U)) + 3013390651936257377U) + aNonceWordA;
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 3331004709895625067U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 15355010435553517129U;
            aOrbiterB = RotL64((aOrbiterB * 8322759117004876831U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 7709870658004280052U) + aNonceWordJ;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 13568728443963926564U) ^ aOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6736090830113688981U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 12409548853419307131U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 969183352023661537U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5549220554838837145U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 15370309834426476775U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 3896803894396631184U;
            aOrbiterE = RotL64((aOrbiterE * 11018830202891911603U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 10848873633291935766U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 12885336509190543440U;
            aOrbiterJ = RotL64((aOrbiterJ * 1487357252619221365U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 8252290890093788010U) + aNonceWordD;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 9201553615601641350U;
            aOrbiterH = RotL64((aOrbiterH * 420321130559162915U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 14014209645503188472U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 4015071464301844550U;
            aOrbiterA = RotL64((aOrbiterA * 17444195018239904971U), 43U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterI, 3U);
            aIngress = aIngress + (RotL64(aOrbiterH, 21U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterA, 11U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterB, 36U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterI, 11U)) + aOrbiterB) + aNonceWordK) + aWandererUpdateSaltE[((aIndex + 28U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterH, 19U)) + aOrbiterB) + aNonceWordL);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 5U) + aOrbiterJ) + RotL64(aOrbiterE, 51U)) + RotL64(aCarry, 41U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterH, 3U)) + aOrbiterK);
            aWandererA = aWandererA + ((((RotL64(aCross, 11U) + RotL64(aOrbiterJ, 57U)) + aOrbiterA) + RotL64(aCarry, 29U)) + aNonceWordI);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 28U) + RotL64(aOrbiterI, 26U)) + aOrbiterJ);
            aWandererD = aWandererD + ((((RotL64(aIngress, 39U) + aOrbiterI) + RotL64(aOrbiterA, 43U)) + aNonceWordG) + aWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 41U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + (RotL64(aWandererF, 24U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererD, 13U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 3
        // ingress from: aExpandLaneB, aWorkLaneD, aFireLaneD
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aFireLaneD forward/backward random
        // cross from: aExpandLaneA, aWorkLaneB, aOperationLaneC
        // cross directions: aExpandLaneA backward forced, aWorkLaneB backward forced, aOperationLaneC backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 22240U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneD[((aIndex + 23201U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 24546U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 20339U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24566U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aOperationLaneC[((aIndex + 18322U)) & S_BLOCK1], 12U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCross, 3U)) + (RotL64(aCarry, 34U) ^ RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterH = (aWandererB + RotL64(aIngress, 37U)) + 6024062041314952357U;
            aOrbiterK = (((aWandererG + RotL64(aScatter, 50U)) + RotL64(aCarry, 47U)) + 18340757093658015585U) + aNonceWordM;
            aOrbiterD = ((aWandererE + RotL64(aCross, 27U)) + 11911120493880346751U) + aOrbiterAssignSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterJ = (((aWandererK + RotL64(aPrevious, 57U)) + RotL64(aCarry, 27U)) + 17428074353884654439U) + aNonceWordP;
            aOrbiterG = ((aWandererH + RotL64(aIngress, 21U)) + RotL64(aCarry, 3U)) + 12790849760814795936U;
            aOrbiterE = (((aWandererJ + RotL64(aPrevious, 11U)) + 12633397052172117800U) + aOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1]) + aNonceWordA;
            aOrbiterI = ((aWandererD + RotL64(aScatter, 3U)) + 11946150433665237945U) + aNonceWordF;
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 16842157900909419285U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterH) ^ 14186235783224155962U) ^ aOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterD = RotL64((aOrbiterD * 10521157787073684417U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 13284904542579767591U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 11609181965078844357U;
            aOrbiterH = RotL64((aOrbiterH * 5455780554452453513U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 9628562297095374984U) + aOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 7850281529011259759U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17611485102925470357U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 257458718073794527U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 10693404545773519306U) ^ aNonceWordK;
            aOrbiterE = RotL64((aOrbiterE * 14821443722828498323U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 3430519236533871460U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 6183054506953198055U;
            aOrbiterJ = RotL64((aOrbiterJ * 6121082743789970911U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 2905610989884221654U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 4472163910775333862U;
            aOrbiterI = RotL64((aOrbiterI * 7770678426310856745U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 16870142883133769663U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterI) ^ 1403692060594816451U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterG = RotL64((aOrbiterG * 9740854430251597879U), 13U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterH, 43U);
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 11U));
            aIngress = aIngress + RotL64(aOrbiterG, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 36U) + aOrbiterJ) + RotL64(aOrbiterI, 57U));
            aWandererE = aWandererE + ((((RotL64(aScatter, 23U) + RotL64(aOrbiterE, 18U)) + aOrbiterI) + RotL64(aCarry, 11U)) + aNonceWordE);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 3U) + aOrbiterG) + RotL64(aOrbiterH, 51U)) + aWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 53U) + RotL64(aOrbiterK, 5U)) + aOrbiterH) + aNonceWordN);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterE, 11U)) + aOrbiterJ) + aNonceWordG);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterD, 43U)) + aOrbiterH) + RotL64(aCarry, 47U)) + aWandererUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterD, 29U)) + aOrbiterE) + aNonceWordD);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 50U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + RotL64(aWandererG, 41U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aFireLaneA
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneB, aWorkLaneC, aFireLaneB
        // cross directions: aExpandLaneB backward forced, aWorkLaneC backward forced, aFireLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 31913U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((aIndex + 30233U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 32554U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 24863U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 27425U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 28737U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 18U) ^ RotL64(aCarry, 51U)) ^ (RotL64(aCross, 3U) + RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterA = (((aWandererA + RotL64(aScatter, 57U)) + RotL64(aCarry, 43U)) + 2177539223979303669U) + aOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = (aWandererI + RotL64(aPrevious, 51U)) + 3962004686551521471U;
            aOrbiterB = ((((aWandererJ + RotL64(aCross, 41U)) + RotL64(aCarry, 13U)) + 8457602312617147662U) + aOrbiterAssignSaltA[((aIndex + 28U)) & S_SALT1]) + aNonceWordE;
            aOrbiterF = ((aWandererD + RotL64(aIngress, 11U)) + RotL64(aCarry, 57U)) + 18011802451816510632U;
            aOrbiterC = (aWandererK + RotL64(aScatter, 3U)) + 9046101759168876832U;
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 18U)) + 11135620637431969597U) + aNonceWordH;
            aOrbiterJ = (aWandererB + RotL64(aCross, 35U)) + 15913029940697999701U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 16304193109948135982U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 13208892298820080981U;
            aOrbiterB = RotL64((aOrbiterB * 15093751072618884859U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 4182377898949419225U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 13970137023071326151U;
            aOrbiterA = RotL64((aOrbiterA * 9075061559681739865U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 8402396284835248583U) + aOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 8859190834060657829U;
            aOrbiterF = RotL64((aOrbiterF * 13552418608113716117U), 19U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterF) + 9760005337757990392U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordB;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 14108277760135744897U) ^ aNonceWordK;
            aOrbiterC = RotL64((aOrbiterC * 4474681104256093885U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 12226316121949012350U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterC) ^ 3456392186754113960U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterE = RotL64((aOrbiterE * 8704729827929941215U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 5004087958637038973U) + aOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 7176881295123125567U) ^ aNonceWordG;
            aOrbiterI = RotL64((aOrbiterI * 15272157962928021009U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 10889800478505074438U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 13728832441482547824U;
            aOrbiterJ = RotL64((aOrbiterJ * 17588477761978646139U), 27U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 21U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 35U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 11U));
            aIngress = aIngress + RotL64(aOrbiterC, 56U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aPrevious, 53U) + aOrbiterA) + RotL64(aOrbiterB, 29U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 5U) + aOrbiterB) + RotL64(aOrbiterJ, 50U)) + aNonceWordO);
            aWandererB = aWandererB + ((RotL64(aCross, 21U) + aOrbiterB) + RotL64(aOrbiterI, 21U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterF, 13U)) + aOrbiterC);
            aWandererI = aWandererI + (((RotL64(aPrevious, 12U) + aOrbiterE) + RotL64(aOrbiterB, 37U)) + RotL64(aCarry, 27U));
            aWandererF = aWandererF ^ ((((RotL64(aCross, 43U) + aOrbiterI) + RotL64(aOrbiterJ, 43U)) + aNonceWordN) + aWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aIngress, 29U) + RotL64(aOrbiterF, 57U)) + aOrbiterA) + RotL64(aCarry, 57U)) + aWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 14U));
            aCarry = aCarry + RotL64(aWandererI, 29U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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

void TwistExpander_WaterPolo_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xF1382B7C43F7C5F5ULL + 0xC059C94D6929DF6DULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xCDDD6F2BBF5699CDULL + 0xD5DAB15C2B5180D8ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xBFB50893622748B7ULL + 0x8EB71013ED77470FULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xD5D3AA9064D36A1FULL + 0xC18A1F2CC3F7AF63ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xC70F833259C8781DULL + 0xA14AF8EA2EB7FDFBULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xF451B8548D285A3DULL + 0x91A3FE82C250915EULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xEA7EDE06835D64B5ULL + 0x8AF35B7D66E2B2CAULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x90B58CBB02C93A5BULL + 0xF36E76AAD462FE88ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x800D9E3B3645AD0BULL + 0xD8FDBDFCC86DC3DFULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xFB00F75CD25285B9ULL + 0xA7E7AA64D9E27B57ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xB263E6E7E30D6399ULL + 0x86148AE70E7AB5F4ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xE792766C314251B9ULL + 0xA7BEC1258C66633BULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x84507A55AB3BB409ULL + 0x860DC48F21F43D87ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xBC43C59DBDFC5CC3ULL + 0xF5117C0A7649A5B8ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xF99E43B8139AAD5BULL + 0x9D991E4FFF7EC9A7ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xF86D479E4E1C8BD7ULL + 0xCD80AE53E3BB05D8ULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aWorkLaneD, aExpandLaneC, aExpandLaneD, aFireLaneB, aOperationLaneA, aFireLaneA, aFireLaneD, aOperationLaneB, aWorkLaneB, aWorkLaneA, aOperationLaneC, aWorkLaneC, aFireLaneC
        // write to: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // kdf_b_loop_b loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aWorkLaneD
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aWorkLaneD forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aFireLaneB
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aFireLaneB backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 3387U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((aIndex + 744U)) & S_BLOCK1], 44U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 2000U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5200U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 5386U)) & S_BLOCK1], 24U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 1695U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCross, 41U)) + (RotL64(aCarry, 26U) ^ RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterC = (((aWandererF + RotL64(aScatter, 41U)) + RotL64(aCarry, 41U)) + 8402620908307642697U) + aNonceWordG;
            aOrbiterK = (aWandererJ + RotL64(aPrevious, 54U)) + 11347672014525086047U;
            aOrbiterA = ((aWandererK + RotL64(aCross, 21U)) + 2816462912503401876U) + aNonceWordO;
            aOrbiterB = (((aWandererI + RotL64(aIngress, 11U)) + RotL64(aCarry, 19U)) + 6940159795470696093U) + aOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = (((aWandererA + RotL64(aCross, 57U)) + RotL64(aCarry, 47U)) + 9134692490095883851U) + aNonceWordA;
            aOrbiterH = (aWandererB + RotL64(aScatter, 50U)) + 4999455497008026526U;
            aOrbiterF = (aWandererE + RotL64(aPrevious, 23U)) + 5992451460350651332U;
            aOrbiterE = (aWandererH + RotL64(aIngress, 3U)) + 3417087346651371924U;
            aOrbiterJ = (aWandererD + RotL64(aPrevious, 29U)) + 3612773820086198270U;
            aOrbiterI = (aWandererC + RotL64(aCross, 39U)) + 463398077083428570U;
            aOrbiterD = ((aWandererG + RotL64(aScatter, 5U)) + 11249391303705089012U) + aOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 17027535139825739501U) + aNonceWordI;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 568131384979596481U;
            aOrbiterA = RotL64((aOrbiterA * 5683451044852895957U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 4793712537158004047U) + aOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 10415170179135963622U;
            aOrbiterG = RotL64((aOrbiterG * 13729564030210361415U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 2391473979460065630U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 4240058362680064261U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12375884373396400889U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 9963957011090031698U) + aNonceWordK;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 3325305624067445525U;
            aOrbiterH = RotL64((aOrbiterH * 3128542681461806309U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 2094945647665114693U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 10703615640774042674U;
            aOrbiterB = RotL64((aOrbiterB * 12641986098450423751U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 3768738815518590289U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 15021301790376706827U) ^ aNonceWordL;
            aOrbiterE = RotL64((aOrbiterE * 14445850924223550339U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 10571246886181608316U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 5130325144599151793U;
            aOrbiterI = RotL64((aOrbiterI * 3185251943547657467U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 8617523421720966373U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 16574597770835250074U;
            aOrbiterF = RotL64((aOrbiterF * 1759209403428937799U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 17474733286551120355U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 17914672092861237776U) ^ aOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13657291990878792267U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 12856557371623447773U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 1636296609747335898U;
            aOrbiterD = RotL64((aOrbiterD * 9286345529656087313U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 12588848560509679821U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 8402620908307642697U) ^ aNonceWordB;
            aOrbiterC = RotL64((aOrbiterC * 2269772223506258147U), 21U);
            //
            aIngress = RotL64(aOrbiterB, 47U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 11U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 54U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 27U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 35U));
            aIngress = aIngress + RotL64(aOrbiterA, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((((RotL64(aPrevious, 14U) + RotL64(aOrbiterG, 11U)) + aOrbiterJ) + RotL64(aCarry, 19U)) + aNonceWordJ) + aWandererUpdateSaltD[((aIndex + 12U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterJ, 50U)) + aOrbiterC);
            aWandererF = aWandererF + ((RotL64(aCross, 21U) + aOrbiterH) + RotL64(aOrbiterG, 47U));
            aWandererG = aWandererG ^ ((((RotL64(aScatter, 43U) + aOrbiterA) + RotL64(aOrbiterH, 5U)) + aNonceWordE) + aWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aPrevious, 41U) + aOrbiterB) + RotL64(aOrbiterK, 21U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterH, 13U)) + aOrbiterF);
            aWandererK = aWandererK + (((RotL64(aScatter, 3U) + RotL64(aOrbiterI, 29U)) + aOrbiterD) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 5U) + aOrbiterI) + RotL64(aOrbiterF, 27U));
            aWandererE = aWandererE + ((RotL64(aScatter, 10U) + aOrbiterB) + RotL64(aOrbiterG, 34U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 19U) + aOrbiterD) + RotL64(aOrbiterG, 43U)) + aNonceWordC);
            aWandererA = aWandererA + ((RotL64(aIngress, 39U) + RotL64(aOrbiterH, 39U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 18U));
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererG, 53U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 2
        // ingress from: aOperationLaneA, aExpandLaneC, aFireLaneA
        // ingress directions: aOperationLaneA forward forced, aExpandLaneC forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD, aFireLaneD
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward forced, aFireLaneD backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 12839U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneC[((aIndex + 11784U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 12386U)) & S_BLOCK1], 12U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 13907U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 14675U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 11909U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aIngress, 51U)) + (RotL64(aCross, 5U) ^ RotL64(aPrevious, 24U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterE = (((aWandererK + RotL64(aPrevious, 57U)) + RotL64(aCarry, 43U)) + 4622023259121087483U) + aNonceWordJ;
            aOrbiterC = ((aWandererF + RotL64(aCross, 43U)) + RotL64(aCarry, 3U)) + 10253505250223501352U;
            aOrbiterD = (aWandererC + RotL64(aIngress, 37U)) + 17133877904420462669U;
            aOrbiterH = (aWandererH + RotL64(aScatter, 35U)) + 6162827793741796700U;
            aOrbiterJ = (aWandererG + RotL64(aPrevious, 60U)) + 9610986424765907615U;
            aOrbiterG = (aWandererB + RotL64(aCross, 5U)) + 11210747154264753754U;
            aOrbiterB = (aWandererA + RotL64(aScatter, 27U)) + 16554205219580654546U;
            aOrbiterF = ((aWandererE + RotL64(aIngress, 29U)) + 10352576357413766388U) + aNonceWordB;
            aOrbiterK = (((aWandererI + RotL64(aScatter, 47U)) + RotL64(aCarry, 47U)) + 3651845783283479752U) + aOrbiterAssignSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterI = ((aWandererD + RotL64(aPrevious, 39U)) + 18145542190463500476U) + aOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = (aWandererJ + RotL64(aIngress, 18U)) + 5415609566767162857U;
            //
            aOrbiterE = (((aOrbiterE + aOrbiterC) + 2033734872464201570U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordF;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 3507213117125813345U;
            aOrbiterD = RotL64((aOrbiterD * 5453058336688881113U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 8716253393049851856U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 695984869565941856U;
            aOrbiterJ = RotL64((aOrbiterJ * 8377921610764044735U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 7661578828878284931U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 906654265099155956U;
            aOrbiterB = RotL64((aOrbiterB * 8117625377607536949U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 6050049984731254612U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 17882717590338190821U) ^ aNonceWordL;
            aOrbiterF = RotL64((aOrbiterF * 10807367411402733215U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 4996521991532815957U) + aNonceWordM;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 4246460672800604436U;
            aOrbiterC = RotL64((aOrbiterC * 12047466401960824903U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 8700148116452518842U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 10039050281847466206U;
            aOrbiterK = RotL64((aOrbiterK * 11884791271239660157U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 4513844680425845372U) + aOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 3037563127442815153U;
            aOrbiterI = RotL64((aOrbiterI * 18363509277992292407U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 1005237931570968724U) + aNonceWordK;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 1373258132025712065U;
            aOrbiterA = RotL64((aOrbiterA * 10458020799382532395U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 12759144329395682277U) + aOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 5139371668116336931U;
            aOrbiterG = RotL64((aOrbiterG * 10761543179345026943U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 3211005174890625715U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 18045286961878287418U;
            aOrbiterH = RotL64((aOrbiterH * 4536094526540761611U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 4454078771279674978U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 4622023259121087483U) ^ aOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8991756794989027019U), 57U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterA, 24U);
            aIngress = aIngress + (RotL64(aOrbiterC, 27U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 39U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterB, 12U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aScatter, 22U) + RotL64(aOrbiterH, 11U)) + aOrbiterI);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 37U) + aOrbiterH) + RotL64(aOrbiterA, 27U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 53U) + RotL64(aOrbiterD, 30U)) + aOrbiterJ) + RotL64(aCarry, 41U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 51U) + RotL64(aOrbiterA, 41U)) + aOrbiterF) + aNonceWordO);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterE, 39U)) + aOrbiterB) + RotL64(aCarry, 11U)) + aNonceWordP);
            aWandererE = aWandererE ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterD, 37U)) + aOrbiterK) + aNonceWordD);
            aWandererD = aWandererD + ((RotL64(aScatter, 42U) + RotL64(aOrbiterK, 35U)) + aOrbiterA);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterG, 3U)) + aOrbiterC);
            aWandererF = aWandererF + ((((RotL64(aScatter, 11U) + aOrbiterB) + RotL64(aOrbiterK, 54U)) + aNonceWordI) + aWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 3U) + aOrbiterH) + RotL64(aOrbiterG, 13U)) + aWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aCross, 5U) + RotL64(aOrbiterE, 5U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 44U));
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 41U) ^ aWandererB);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 3
        // ingress from: aOperationLaneB, aExpandLaneD, aWorkLaneB
        // ingress directions: aOperationLaneB forward forced, aExpandLaneD forward forced, aWorkLaneB forward/backward random
        // cross from: aOperationLaneA, aExpandLaneB, aWorkLaneA
        // cross directions: aOperationLaneA backward forced, aExpandLaneB backward forced, aWorkLaneA backward/forward random
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 19477U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneD[((aIndex + 20834U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 22702U)) & S_BLOCK1], 24U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 19920U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 21581U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 17166U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 54U) ^ RotL64(aCarry, 23U)) + (RotL64(aCross, 37U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterG = (aWandererA + RotL64(aPrevious, 5U)) + 5573188770530340913U;
            aOrbiterH = (aWandererJ + RotL64(aCross, 37U)) + 1431772230889897111U;
            aOrbiterC = (aWandererB + RotL64(aIngress, 39U)) + 4809192776429682319U;
            aOrbiterF = ((aWandererC + RotL64(aScatter, 21U)) + 5576603692574369341U) + aNonceWordB;
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 26U)) + RotL64(aCarry, 43U)) + 2720143226007220386U;
            aOrbiterD = (aWandererG + RotL64(aIngress, 41U)) + 17220328778565331629U;
            aOrbiterB = (((aWandererF + RotL64(aScatter, 19U)) + RotL64(aCarry, 37U)) + 9629485808442089423U) + aNonceWordE;
            aOrbiterA = ((aWandererE + RotL64(aCross, 53U)) + RotL64(aCarry, 57U)) + 1136998437010390983U;
            aOrbiterK = (((aWandererD + RotL64(aPrevious, 43U)) + 11893390497814523841U) + aOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordG;
            aOrbiterE = ((aWandererI + RotL64(aCross, 30U)) + 1764986431917532370U) + aOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = (aWandererK + RotL64(aScatter, 23U)) + 1741014798007010376U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 12221368453236547044U) + aNonceWordC;
            aOrbiterC = (((aOrbiterC ^ aOrbiterG) ^ 7694538641172350430U) ^ aOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterC = RotL64((aOrbiterC * 8439120733670016501U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 17472344518811560603U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 3308740700728172984U;
            aOrbiterI = RotL64((aOrbiterI * 15290400462887712083U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 9535358833412446771U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 11192312491731312451U;
            aOrbiterB = RotL64((aOrbiterB * 17405609148475445743U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 14850451970047190039U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 11932493299452443256U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7964808728820467795U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 5972619895614731870U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 17174497535809891690U;
            aOrbiterE = RotL64((aOrbiterE * 15471084511364572533U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 17412894714378898351U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 14675615208706549810U;
            aOrbiterJ = RotL64((aOrbiterJ * 7864845089606499769U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 16116792108013658523U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 9702262005960966336U;
            aOrbiterD = RotL64((aOrbiterD * 970452849653781703U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 17337264966818542841U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 7004462033775827275U;
            aOrbiterF = RotL64((aOrbiterF * 11943575980344402681U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 17499850384482055438U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 1839357713256560566U;
            aOrbiterG = RotL64((aOrbiterG * 12943750650487416281U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 8144238113917577524U) + aOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 888195876227325908U;
            aOrbiterA = RotL64((aOrbiterA * 7941506708630993709U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 5081763359501717653U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 5573188770530340913U;
            aOrbiterH = RotL64((aOrbiterH * 9699901099898698965U), 11U);
            //
            aIngress = RotL64(aOrbiterI, 43U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 53U));
            aIngress = aIngress + (RotL64(aOrbiterA, 19U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterJ, 21U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 39U));
            aIngress = aIngress + RotL64(aOrbiterD, 28U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 18U) + RotL64(aOrbiterK, 23U)) + aOrbiterD);
            aWandererI = aWandererI + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterC, 14U)) + aOrbiterK) + RotL64(aCarry, 27U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 27U) + aOrbiterE) + RotL64(aOrbiterG, 27U)) + aNonceWordP);
            aWandererE = aWandererE + (((RotL64(aScatter, 47U) + aOrbiterI) + RotL64(aOrbiterH, 5U)) + RotL64(aCarry, 37U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 52U) + aOrbiterD) + RotL64(aOrbiterG, 51U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 3U) + aOrbiterD) + RotL64(aOrbiterH, 57U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterA, 41U)) + aOrbiterC);
            aWandererA = aWandererA + (((RotL64(aCross, 5U) + RotL64(aOrbiterJ, 47U)) + aOrbiterF) + aWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 21U) + aOrbiterG) + RotL64(aOrbiterB, 3U)) + aWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 13U) + RotL64(aOrbiterI, 44U)) + aOrbiterJ);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterA, 11U)) + aOrbiterG) + aNonceWordM);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 60U));
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererF);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererJ, 19U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 4
        // ingress from: aOperationLaneC, aOperationLaneA, aWorkLaneC
        // ingress directions: aOperationLaneC forward forced, aOperationLaneA forward forced, aWorkLaneC forward/backward random
        // cross from: aOperationLaneB, aExpandLaneC, aFireLaneC
        // cross directions: aOperationLaneB backward forced, aExpandLaneC backward forced, aFireLaneC backward/forward random
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneC[((aIndex + 26712U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneA[((aIndex + 26078U)) & S_BLOCK1], 60U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 31869U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27560U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 31994U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 26177U)) & S_BLOCK1], 36U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCross, 54U)) + (RotL64(aIngress, 27U) + RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterI = (((aWandererK + RotL64(aPrevious, 13U)) + RotL64(aCarry, 29U)) + 12426357877879529292U) + aNonceWordP;
            aOrbiterC = (aWandererI + RotL64(aIngress, 60U)) + 12604900366173639176U;
            aOrbiterE = (((aWandererC + RotL64(aCross, 37U)) + RotL64(aCarry, 19U)) + 13511119007338929401U) + aOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = (aWandererB + RotL64(aScatter, 19U)) + 9878720081166788060U;
            aOrbiterB = (aWandererE + RotL64(aCross, 57U)) + 15463195409806395076U;
            aOrbiterD = (aWandererA + RotL64(aPrevious, 51U)) + 6407922778852833423U;
            aOrbiterK = ((aWandererF + RotL64(aIngress, 11U)) + 7690427254160734016U) + aNonceWordK;
            aOrbiterA = (((aWandererG + RotL64(aScatter, 43U)) + 18030974031722143619U) + aOrbiterAssignSaltB[((aIndex + 13U)) & S_SALT1]) + aNonceWordI;
            aOrbiterF = (aWandererJ + RotL64(aCross, 22U)) + 17983938038322737041U;
            aOrbiterJ = (aWandererD + RotL64(aIngress, 47U)) + 16605512170117753884U;
            aOrbiterG = ((aWandererH + RotL64(aScatter, 3U)) + RotL64(aCarry, 11U)) + 681802273302348322U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 15550312921312083819U) + aNonceWordD;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 17824154101711884508U;
            aOrbiterE = RotL64((aOrbiterE * 7358612830654795357U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 1939207786756735430U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 3132864634777826569U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13606281919426730325U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 12822929773923954849U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 16576106045887115660U;
            aOrbiterK = RotL64((aOrbiterK * 16370914370769903051U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 2398825881649235260U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 13700821892926092479U;
            aOrbiterJ = RotL64((aOrbiterJ * 10830623703416956043U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 2439833784883391606U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 15870638514107637833U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3797380922767479287U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 9165457123134229670U) + aNonceWordN;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 8736642509192659417U) ^ aNonceWordE;
            aOrbiterA = RotL64((aOrbiterA * 16219277537523484065U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 9232719746484835693U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 7826680628853322541U;
            aOrbiterH = RotL64((aOrbiterH * 12578050118133526187U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 14323652326982518782U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 2254524512851399313U;
            aOrbiterG = RotL64((aOrbiterG * 4119339547645451149U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 14459632243829356472U) + aOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 8591197056749497716U;
            aOrbiterI = RotL64((aOrbiterI * 13053836520694721881U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 17220196418897000411U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 7186579019945992185U;
            aOrbiterB = RotL64((aOrbiterB * 12406048515179065691U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 7554005180895698880U) + aOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 12426357877879529292U;
            aOrbiterF = RotL64((aOrbiterF * 5090046967147694465U), 37U);
            //
            aIngress = RotL64(aOrbiterB, 53U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 5U));
            aIngress = aIngress + (RotL64(aOrbiterK, 24U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 37U));
            aIngress = aIngress + RotL64(aOrbiterE, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterA, 34U)) + aOrbiterF) + RotL64(aCarry, 23U)) + aWandererUpdateSaltD[((aIndex + 20U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 47U) + aOrbiterH) + RotL64(aOrbiterK, 21U));
            aWandererA = aWandererA + ((RotL64(aIngress, 27U) + RotL64(aOrbiterG, 23U)) + aOrbiterB);
            aWandererG = aWandererG ^ (((RotL64(aCross, 5U) + aOrbiterI) + RotL64(aOrbiterA, 37U)) + aNonceWordC);
            aWandererI = aWandererI + (((RotL64(aIngress, 34U) + RotL64(aOrbiterF, 53U)) + aOrbiterD) + RotL64(aCarry, 43U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 51U) + aOrbiterA) + RotL64(aOrbiterH, 6U)) + aWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aCross, 21U) + RotL64(aOrbiterJ, 41U)) + aOrbiterI);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterD, 3U)) + aOrbiterB) + aNonceWordO);
            aWandererK = aWandererK + ((RotL64(aCross, 60U) + RotL64(aOrbiterD, 43U)) + aOrbiterJ);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 13U) + aOrbiterH) + RotL64(aOrbiterE, 11U)) + aNonceWordL);
            aWandererC = aWandererC + (((RotL64(aIngress, 39U) + aOrbiterC) + RotL64(aOrbiterH, 13U)) + aNonceWordG);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 51U));
            aCarry = aCarry + (RotL64(aWandererE, 48U) ^ aWandererJ);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 53U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + RotL64(aWandererC, 36U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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

void TwistExpander_WaterPolo_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xE87DC6EEB34BC05DULL + 0x996D8871C60037C6ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xC03A15E3050825BFULL + 0xDB62EFB6FE309F9DULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xE7439F390D2EAEF7ULL + 0xC0929DA1B207280EULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xEC6E4D0F0ED82EBBULL + 0xFFCC2D94BA4E43DAULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xACDDFC6007A795D5ULL + 0xAE7D70A90C1C2AF4ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x8716DECBD8ED6D4FULL + 0xE1EEEA4F0EE2A893ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xA6FB23033A65B8EDULL + 0xCBC9E1E60250B20BULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xC7AE54F3A5E9CE2FULL + 0xC4F98FEC69C779E7ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x9B16D11347185FBDULL + 0xF9F3ED113FD667C0ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xE376123F13F31DE9ULL + 0xE6FB28A46C41F3BFULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xFDE657D3F63C5A53ULL + 0xD3EF54D554908F37ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xC1677F66C8CA6B55ULL + 0xE01414042D6D14E2ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x871BDD81E31C91EFULL + 0xF535D197EE621D26ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x8B6B09E1364312C5ULL + 0x9C351A8F38C589BDULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xEC5578371C05AE4BULL + 0xEDDC45756E0DA288ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xF36A9CF2E86CD99BULL + 0xF3771DF15FEB1FCFULL);
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
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneB, aOperationLaneC, aOperationLaneD, aFireLaneD, aExpandLaneA, aWorkLaneB, aFireLaneA, aExpandLaneB, aFireLaneC, aWorkLaneD, aExpandLaneC, aWorkLaneC, aWorkLaneA
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aFireLaneB
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aFireLaneB forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aFireLaneD
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 7069U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneB[((aIndex + 6610U)) & S_BLOCK1], 30U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 2756U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 6862U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 6957U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 6622U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 37U) ^ RotL64(aCross, 5U)) + (RotL64(aIngress, 53U) ^ RotL64(aCarry, 24U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 36U)) + 15920462086654025436U) + aNonceWordO;
            aOrbiterB = ((aWandererB + RotL64(aScatter, 27U)) + 487844076858004017U) + aNonceWordN;
            aOrbiterD = (((aWandererD + RotL64(aPrevious, 11U)) + RotL64(aCarry, 35U)) + 14502883786442630566U) + aOrbiterAssignSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = ((aWandererA + RotL64(aCross, 47U)) + 3787107318658233674U) + aOrbiterAssignSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterK = (((aWandererG + RotL64(aScatter, 21U)) + RotL64(aCarry, 3U)) + 12548777544693755491U) + aNonceWordP;
            aOrbiterC = (aWandererH + RotL64(aIngress, 4U)) + 4907309444075181683U;
            aOrbiterG = (aWandererC + RotL64(aPrevious, 43U)) + 18342396700266492072U;
            aOrbiterE = (((aWandererF + RotL64(aCross, 51U)) + RotL64(aCarry, 43U)) + 13503051997624242670U) + aNonceWordE;
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 57U)) + 17845742460521374571U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 8640887211877858169U) + aNonceWordM;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 5273913123709097537U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1661149444148461791U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 17756844173695563883U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 6713055830729302951U;
            aOrbiterK = RotL64((aOrbiterK * 2832836748513174311U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 5106468334224035972U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 10228769728713526172U) ^ aOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9760310686414358435U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 7687649520668883142U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 7757480627354711605U;
            aOrbiterB = RotL64((aOrbiterB * 7222553727737349209U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 10876291698508634557U) + aNonceWordG;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 8149278085586014186U;
            aOrbiterJ = RotL64((aOrbiterJ * 8577133863470695381U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 15592893988925610485U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 8639028256640537165U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1880655276432963955U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 475660347892196219U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 1903736092401853832U) ^ aOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8486318978769094799U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 12463250192809450953U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 7253918448601703982U;
            aOrbiterE = RotL64((aOrbiterE * 3821034106528009129U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 5171661020093804486U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 11627344933828324146U;
            aOrbiterI = RotL64((aOrbiterI * 5388047063152043277U), 13U);
            //
            aIngress = RotL64(aOrbiterA, 47U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 5U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 27U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterE, 38U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterI, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aIngress, 24U) + aOrbiterK) + RotL64(aOrbiterB, 19U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 43U) + aOrbiterA) + RotL64(aOrbiterC, 6U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 57U) + aOrbiterE) + RotL64(aOrbiterI, 39U)) + aNonceWordF);
            aWandererF = aWandererF + (((RotL64(aCross, 39U) + RotL64(aOrbiterJ, 57U)) + aOrbiterB) + RotL64(aCarry, 19U));
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 47U) + RotL64(aOrbiterA, 13U)) + aOrbiterG) + aNonceWordH) + aWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 34U) + aOrbiterK) + RotL64(aOrbiterD, 27U)) + RotL64(aCarry, 5U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 13U) + aOrbiterG) + RotL64(aOrbiterE, 35U)) + aWandererUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aCross, 19U) + aOrbiterJ) + RotL64(aOrbiterK, 43U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 29U) + aOrbiterB) + RotL64(aOrbiterI, 48U)) + aNonceWordJ);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 4U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + RotL64(aWandererJ, 43U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 2
        // ingress from: aExpandLaneA, aOperationLaneC, aWorkLaneB
        // ingress directions: aExpandLaneA forward forced, aOperationLaneC forward forced, aWorkLaneB forward/backward random
        // cross from: aOperationLaneA, aOperationLaneD, aFireLaneA
        // cross directions: aOperationLaneA backward forced, aOperationLaneD backward forced, aFireLaneA backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 13436U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneC[((aIndex + 15311U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 16206U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 10287U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 15021U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 13065U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 27U) ^ RotL64(aIngress, 41U)) + (RotL64(aCarry, 13U) ^ RotL64(aPrevious, 54U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterH = ((aWandererH + RotL64(aIngress, 54U)) + 5697928251815176134U) + aOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = (((aWandererE + RotL64(aScatter, 43U)) + RotL64(aCarry, 11U)) + 337587740689259575U) + aNonceWordN;
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 39U)) + 4927686903263973950U) + aNonceWordP;
            aOrbiterA = (((aWandererG + RotL64(aCross, 13U)) + RotL64(aCarry, 57U)) + 3742409032569801033U) + aNonceWordH;
            aOrbiterE = (aWandererJ + RotL64(aScatter, 58U)) + 1608092659172197650U;
            aOrbiterG = (aWandererC + RotL64(aPrevious, 47U)) + 15848744267145717509U;
            aOrbiterK = (aWandererA + RotL64(aCross, 3U)) + 15300174177963339253U;
            aOrbiterB = (((aWandererK + RotL64(aIngress, 23U)) + RotL64(aCarry, 29U)) + 14162868453323648628U) + aOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = (aWandererD + RotL64(aScatter, 29U)) + 12020167069983729869U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 16259538291658723956U) + aOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 8516686212464112245U;
            aOrbiterI = RotL64((aOrbiterI * 4731296903548893627U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 3722184575520553132U) + aNonceWordO;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 5663609293306386784U;
            aOrbiterE = RotL64((aOrbiterE * 14364218128780764749U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 15265344442454471986U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 3050323350098829515U;
            aOrbiterG = RotL64((aOrbiterG * 5890624677162388135U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 1093356813820599238U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 15167726103772238440U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5719466863561311069U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 15170797965325981472U) + aNonceWordL;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 17826286701992981628U;
            aOrbiterA = RotL64((aOrbiterA * 11186808881726573677U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 14710892030473425181U) + aOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 397194787697553904U;
            aOrbiterC = RotL64((aOrbiterC * 14368930300818752833U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 1273724124862533034U) + aNonceWordJ;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 13018397560392545616U;
            aOrbiterF = RotL64((aOrbiterF * 4644812473262395329U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 9638716186445643730U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 7255587739807843785U;
            aOrbiterB = RotL64((aOrbiterB * 6055682981584011189U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 9272350563697399628U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 1040729335295009339U;
            aOrbiterH = RotL64((aOrbiterH * 17825687660830291443U), 53U);
            //
            aIngress = RotL64(aOrbiterF, 51U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + (RotL64(aOrbiterB, 37U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterH, 30U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterI, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 36U) + aOrbiterB) + RotL64(aOrbiterH, 5U)) + aWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 19U) + aOrbiterG) + RotL64(aOrbiterI, 10U));
            aWandererB = aWandererB + ((((RotL64(aScatter, 11U) + RotL64(aOrbiterA, 47U)) + aOrbiterC) + RotL64(aCarry, 37U)) + aNonceWordD);
            aWandererH = aWandererH ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterG, 43U)) + aOrbiterC) + aNonceWordG);
            aWandererE = aWandererE + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterB, 35U)) + aOrbiterC) + RotL64(aCarry, 13U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 24U) + aOrbiterF) + RotL64(aOrbiterH, 57U)) + aWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 47U) + aOrbiterK) + RotL64(aOrbiterI, 19U)) + aNonceWordM);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 41U) + aOrbiterI) + RotL64(aOrbiterH, 14U)) + aNonceWordF);
            aWandererA = aWandererA + ((RotL64(aPrevious, 53U) + aOrbiterA) + RotL64(aOrbiterE, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 40U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererD);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + RotL64(aWandererG, 57U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 3
        // ingress from: aExpandLaneB, aOperationLaneD, aFireLaneC
        // ingress directions: aExpandLaneB forward forced, aOperationLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneA, aOperationLaneB, aWorkLaneD
        // cross directions: aExpandLaneA backward forced, aOperationLaneB backward forced, aWorkLaneD backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 16787U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneD[((aIndex + 21015U)) & S_BLOCK1], 30U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 24352U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 17723U)) & S_BLOCK1], 12U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 17027U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 23164U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aPrevious, 58U) + RotL64(aCarry, 39U)) ^ (RotL64(aCross, 11U) ^ RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterA = (((aWandererC + RotL64(aCross, 57U)) + RotL64(aCarry, 39U)) + 5295352595333316211U) + aNonceWordN;
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 28U)) + 2341795367042042605U) + aOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = (((aWandererI + RotL64(aIngress, 3U)) + 10122175780504033663U) + aOrbiterAssignSaltB[((aIndex + 8U)) & S_SALT1]) + aNonceWordL;
            aOrbiterK = (aWandererG + RotL64(aPrevious, 47U)) + 10084612804696198554U;
            aOrbiterH = ((aWandererH + RotL64(aScatter, 51U)) + 16470424309851045971U) + aNonceWordE;
            aOrbiterD = (aWandererA + RotL64(aIngress, 19U)) + 656016130975227994U;
            aOrbiterE = (aWandererB + RotL64(aCross, 24U)) + 15313268829659834317U;
            aOrbiterC = (((aWandererK + RotL64(aPrevious, 35U)) + RotL64(aCarry, 47U)) + 3795220914993923394U) + aNonceWordB;
            aOrbiterI = ((aWandererD + RotL64(aIngress, 39U)) + RotL64(aCarry, 11U)) + 14044442220988813825U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 3804224626734584802U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 7980006306010255693U;
            aOrbiterB = RotL64((aOrbiterB * 13958505239726088561U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 13746830564584711549U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 11852212099729274845U;
            aOrbiterD = RotL64((aOrbiterD * 2164880979318247855U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 9083223471018084847U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 13706723820703853346U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11361854103656219887U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 1713819986642275223U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 1382000168233902914U;
            aOrbiterK = RotL64((aOrbiterK * 3894160765130198157U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 4540474625764565485U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 1756168174375757220U;
            aOrbiterI = RotL64((aOrbiterI * 12739160208010092017U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 1409297070183609309U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 6082750101445444357U;
            aOrbiterH = RotL64((aOrbiterH * 17438740230251860935U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 1113239890859479202U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 10932192439503964363U) ^ aNonceWordH;
            aOrbiterA = RotL64((aOrbiterA * 5915660289913324281U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 3732595033748508428U) + aOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 5117760372351117286U;
            aOrbiterE = RotL64((aOrbiterE * 2671510075176315761U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 7399968659654088641U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 14835608167871904147U) ^ aNonceWordP;
            aOrbiterJ = RotL64((aOrbiterJ * 8312521710415756159U), 47U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterE, 42U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + (RotL64(aOrbiterA, 39U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 19U));
            aIngress = aIngress + RotL64(aOrbiterB, 34U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aIngress, 53U) + RotL64(aOrbiterJ, 47U)) + aOrbiterA) + aNonceWordA);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterE, 39U)) + aOrbiterH);
            aWandererB = aWandererB + (((RotL64(aScatter, 43U) + aOrbiterH) + RotL64(aOrbiterA, 18U)) + RotL64(aCarry, 11U));
            aWandererK = aWandererK ^ ((((RotL64(aCross, 26U) + RotL64(aOrbiterB, 35U)) + aOrbiterK) + aNonceWordM) + aWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aScatter, 39U) + RotL64(aOrbiterB, 51U)) + aOrbiterI);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 5U) + aOrbiterI) + RotL64(aOrbiterD, 43U)) + aNonceWordG);
            aWandererA = aWandererA + (((RotL64(aIngress, 21U) + aOrbiterI) + RotL64(aOrbiterA, 3U)) + RotL64(aCarry, 21U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterE, 10U)) + aOrbiterC);
            aWandererC = aWandererC + (((RotL64(aScatter, 47U) + aOrbiterC) + RotL64(aOrbiterA, 57U)) + aWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + (RotL64(aWandererJ, 50U) ^ aWandererD);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + RotL64(aWandererI, 11U);
            aCarry = aCarry + RotL64(aIngress, 40U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aWorkLaneC
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aWorkLaneC forward/backward random
        // cross from: aExpandLaneB, aOperationLaneC, aWorkLaneA
        // cross directions: aExpandLaneB backward forced, aOperationLaneC backward forced, aWorkLaneA backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 29279U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((aIndex + 29885U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 31282U)) & S_BLOCK1], 52U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30923U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 29183U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 29762U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 56U) ^ RotL64(aCross, 19U)) + (RotL64(aCarry, 43U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterF = ((aWandererK + RotL64(aScatter, 34U)) + RotL64(aCarry, 41U)) + 3238389262925516513U;
            aOrbiterI = (aWandererC + RotL64(aCross, 47U)) + 12381787182611386995U;
            aOrbiterD = (aWandererD + RotL64(aIngress, 53U)) + 7883885539305181549U;
            aOrbiterK = ((((aWandererF + RotL64(aPrevious, 23U)) + RotL64(aCarry, 3U)) + 1185413044597727092U) + aOrbiterAssignSaltD[((aIndex + 12U)) & S_SALT1]) + aNonceWordE;
            aOrbiterG = (aWandererB + RotL64(aScatter, 43U)) + 15219353497204773135U;
            aOrbiterJ = (((aWandererE + RotL64(aCross, 5U)) + RotL64(aCarry, 51U)) + 7533774715626734082U) + aNonceWordI;
            aOrbiterA = (aWandererJ + RotL64(aIngress, 18U)) + 2599930450937763464U;
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 39U)) + 16074720663961214284U) + aNonceWordD;
            aOrbiterB = ((aWandererI + RotL64(aScatter, 13U)) + 15483613196360051221U) + aOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1];
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 9396557867081376268U) + aOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 9668459976852660245U;
            aOrbiterD = RotL64((aOrbiterD * 11748505665890567063U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 9037269914643207212U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 16936742640861088240U) ^ aNonceWordM;
            aOrbiterG = RotL64((aOrbiterG * 1040172193161012227U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 16481274825758546398U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 481851372837611166U;
            aOrbiterF = RotL64((aOrbiterF * 2225030139210599207U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 13608921517203544108U) + aOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 16930740723286214636U;
            aOrbiterC = RotL64((aOrbiterC * 2605108503821980865U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 902242902582149908U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 1510861213079342977U) ^ aNonceWordA;
            aOrbiterI = RotL64((aOrbiterI * 3309753895727400707U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 7116243600304980310U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 6631412278359709602U) ^ aNonceWordH;
            aOrbiterA = RotL64((aOrbiterA * 11452627691392637463U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 9246698682265275165U) + aNonceWordN;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 8594373032014031450U;
            aOrbiterJ = RotL64((aOrbiterJ * 2550138341089957033U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 15912837963877821048U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 11404583513022627609U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17715204726760125357U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 17295214920690244319U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 18315664494984189344U;
            aOrbiterK = RotL64((aOrbiterK * 17398893532076312945U), 11U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterA, 21U);
            aIngress = aIngress + (RotL64(aOrbiterK, 54U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterG, 47U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterI, 5U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterF, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aPrevious, 14U) + aOrbiterI) + RotL64(aOrbiterF, 52U)) + aWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 27U) + aOrbiterF) + RotL64(aOrbiterK, 3U));
            aWandererC = aWandererC + (((RotL64(aCross, 35U) + aOrbiterI) + RotL64(aOrbiterA, 57U)) + aWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 5U) + aOrbiterF) + RotL64(aOrbiterB, 29U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterD, 34U)) + aOrbiterF) + RotL64(aCarry, 47U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterG, 21U)) + aOrbiterI) + aNonceWordJ);
            aWandererI = aWandererI + (((RotL64(aIngress, 19U) + RotL64(aOrbiterF, 47U)) + aOrbiterJ) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 58U) + aOrbiterC) + RotL64(aOrbiterA, 13U)) + aNonceWordL);
            aWandererD = aWandererD + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterG, 39U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + (RotL64(aWandererK, 20U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererI, 37U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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

void TwistExpander_WaterPolo_Arx::KDF_B_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xC0877C5CAACEA765ULL + 0xF838934AAA571FCCULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x817C52370493541DULL + 0x8B5127065AF480A9ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x833D3626E9B659BBULL + 0xB06AC1B38F45F24AULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x94BD75314605CFB1ULL + 0x8D29C28E1510B3C7ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xD8DC1D9E1E71D953ULL + 0xB211624CE897DE2FULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xD8291E57D5565FABULL + 0xA1B2BAF81B5608E6ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xE2BE4D17F644E62FULL + 0xC6BB0BD2D15AF922ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xDC2C7AAA9ECA79E9ULL + 0xD7A3C5CA05DAD5A5ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x8065F8737AC156E3ULL + 0xF5FA2EFA92A44401ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xB080469CE7B21AB1ULL + 0xA643DD2A2F78BED4ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x9861C96FC7DAF48DULL + 0xE7D8222FD0044C2AULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xABDFD4C3977F92A1ULL + 0xED99EB3DDEA10FDAULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xD0C6EF9DDEF80A27ULL + 0xCB63E42457277AAAULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xA483226D63FF9AB3ULL + 0xCF213E0D3ABDAD1EULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xFF09EC8C4CF290CDULL + 0xFFD68FCB2A1FCCC2ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x90C3544586B89937ULL + 0xD08A5142250C0064ULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aOperationLaneC, aWorkLaneC, aWorkLaneD, aFireLaneB, aExpandLaneA, aOperationLaneB, aFireLaneD, aExpandLaneB, aFireLaneA, aFireLaneC, aExpandLaneC, aOperationLaneA, aOperationLaneD
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_d loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aOperationLaneC
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aOperationLaneC forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aFireLaneB
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aFireLaneB backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 4655U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((aIndex + 568U)) & S_BLOCK1], 26U));
            aIngress ^= RotL64(aOperationLaneC[((aIndex + 1896U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 3046U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 1312U)) & S_BLOCK1], 58U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 5530U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 5U)) ^ (RotL64(aCross, 39U) + RotL64(aIngress, 24U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterD = (aWandererE + RotL64(aPrevious, 5U)) + 14249093584376402677U;
            aOrbiterF = ((aWandererC + RotL64(aCross, 36U)) + 8756965951816492264U) + aOrbiterAssignSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = ((aWandererB + RotL64(aScatter, 29U)) + 11221139480258176330U) + aOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = (((aWandererK + RotL64(aIngress, 19U)) + RotL64(aCarry, 53U)) + 17218894445564194851U) + aNonceWordI;
            aOrbiterE = ((aWandererD + RotL64(aScatter, 13U)) + RotL64(aCarry, 35U)) + 8064642692524949490U;
            aOrbiterB = (aWandererF + RotL64(aIngress, 57U)) + 5822093203710704646U;
            aOrbiterI = (((aWandererH + RotL64(aPrevious, 47U)) + RotL64(aCarry, 19U)) + 3217799620158102238U) + aNonceWordG;
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 2613757677892120843U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 13647481499551657237U;
            aOrbiterG = RotL64((aOrbiterG * 5517563514031899891U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 3545714196663685016U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 9735422670576621521U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7276207208162697249U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 3911046580637583767U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 9315984027042049203U) ^ aNonceWordM;
            aOrbiterI = RotL64((aOrbiterI * 12568550776487242469U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 8926367674641729058U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 11035347490524961446U;
            aOrbiterD = RotL64((aOrbiterD * 10948288997163592463U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 10748158733051120339U) + aOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = (((aOrbiterB ^ aOrbiterF) ^ 2467801787989056455U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterB = RotL64((aOrbiterB * 12621934274702358977U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 9244415080474351390U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 8517784887959492079U;
            aOrbiterF = RotL64((aOrbiterF * 17022899813765884147U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 8409307332803038455U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 11043806021873232950U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8294888329708842989U), 29U);
            //
            aIngress = RotL64(aOrbiterE, 21U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterA, 44U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 5U));
            aIngress = aIngress + RotL64(aOrbiterG, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterB, 5U)) + aOrbiterE);
            aWandererC = aWandererC + ((((RotL64(aIngress, 13U) + aOrbiterE) + RotL64(aOrbiterI, 11U)) + aNonceWordK) + aWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterF, 36U)) + aOrbiterE) + aNonceWordA);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 19U) + aOrbiterE) + RotL64(aOrbiterA, 43U)) + RotL64(aCarry, 13U)) + aWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 41U) + aOrbiterI) + RotL64(aOrbiterG, 51U));
            aWandererB = aWandererB + (((RotL64(aScatter, 4U) + RotL64(aOrbiterB, 23U)) + aOrbiterD) + RotL64(aCarry, 41U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 57U) + aOrbiterB) + RotL64(aOrbiterA, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererC);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + RotL64(aWandererB, 50U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aOperationLaneB
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aOperationLaneB forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aFireLaneD
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 9571U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneC[((aIndex + 9981U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 14902U)) & S_BLOCK1], 34U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 9516U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 15714U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 12154U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCarry, 18U)) ^ (RotL64(aCross, 41U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterB = (((aWandererJ + RotL64(aCross, 37U)) + RotL64(aCarry, 57U)) + 12692813903177772178U) + aNonceWordA;
            aOrbiterH = ((aWandererH + RotL64(aPrevious, 5U)) + RotL64(aCarry, 11U)) + 7112496446691277899U;
            aOrbiterK = (((aWandererI + RotL64(aIngress, 57U)) + RotL64(aCarry, 29U)) + 2112247138290568813U) + aOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = ((aWandererB + RotL64(aScatter, 13U)) + 3699421080882855947U) + aNonceWordK;
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 20U)) + 13761832028354380922U) + aNonceWordE;
            aOrbiterD = (aWandererK + RotL64(aIngress, 27U)) + 9243822514887600214U;
            aOrbiterA = (((aWandererA + RotL64(aScatter, 47U)) + 6863833516853046129U) + aOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1]) + aNonceWordN;
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 8863897995943098018U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 13346785686701467520U) ^ aNonceWordF;
            aOrbiterK = RotL64((aOrbiterK * 18074843497158380703U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 15309543066305531619U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 17515530938817919111U) ^ aOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16625193986319048245U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 760493237816424254U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 7282586354117620860U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2327153408185290635U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 4129706068526969105U) + aOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 7020175432730888755U;
            aOrbiterC = RotL64((aOrbiterC * 10095158356907592239U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 9102258982216515596U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 10822031305361453690U;
            aOrbiterD = RotL64((aOrbiterD * 2036205056490578491U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 12571477440964330246U) + aNonceWordD;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 8436347026653095199U;
            aOrbiterI = RotL64((aOrbiterI * 17930734781213681573U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 14214789872073941940U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 12915911919403385001U;
            aOrbiterB = RotL64((aOrbiterB * 13161681603528031511U), 57U);
            //
            aIngress = RotL64(aOrbiterB, 6U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterA, 37U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + RotL64(aOrbiterH, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aCross, 29U) + aOrbiterA) + RotL64(aOrbiterH, 23U)) + RotL64(aCarry, 27U)) + aNonceWordL);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 3U) + aOrbiterK) + RotL64(aOrbiterA, 29U));
            aWandererA = aWandererA + ((((RotL64(aIngress, 35U) + RotL64(aOrbiterI, 57U)) + aOrbiterB) + RotL64(aCarry, 43U)) + aWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 11U) + aOrbiterI) + RotL64(aOrbiterD, 14U)) + aNonceWordJ);
            aWandererI = aWandererI + (((RotL64(aIngress, 43U) + RotL64(aOrbiterH, 35U)) + aOrbiterC) + aWandererUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 56U) + RotL64(aOrbiterA, 3U)) + aOrbiterI) + aNonceWordB);
            aWandererK = aWandererK + ((RotL64(aScatter, 19U) + RotL64(aOrbiterA, 43U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 4U));
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererI, 43U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 3
        // ingress from: aExpandLaneB, aWorkLaneD, aFireLaneA
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneA, aWorkLaneB, aFireLaneC
        // cross directions: aExpandLaneA backward forced, aWorkLaneB backward forced, aFireLaneC backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 20804U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneD[((aIndex + 23667U)) & S_BLOCK1], 56U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 20566U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22832U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17926U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 23551U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aIngress, 23U)) + (RotL64(aCarry, 11U) ^ RotL64(aPrevious, 54U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 43U)) + RotL64(aCarry, 41U)) + 16519040829220310189U;
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 13U)) + RotL64(aCarry, 11U)) + 6888002778416941825U;
            aOrbiterH = ((aWandererC + RotL64(aIngress, 34U)) + 1310832187746534025U) + aNonceWordH;
            aOrbiterC = (aWandererI + RotL64(aCross, 5U)) + 5890888009051281674U;
            aOrbiterI = (((aWandererK + RotL64(aScatter, 53U)) + 5143864838362464857U) + aOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1]) + aNonceWordO;
            aOrbiterA = (aWandererB + RotL64(aIngress, 21U)) + 15591534069452660003U;
            aOrbiterE = (((aWandererG + RotL64(aCross, 27U)) + RotL64(aCarry, 27U)) + 1466867671765325096U) + aOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 13931443680107902488U) + aNonceWordE;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 15400747367673245552U;
            aOrbiterH = RotL64((aOrbiterH * 7011651369456453127U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 2836975369734495759U) + aNonceWordD;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 2370720358274970117U;
            aOrbiterI = RotL64((aOrbiterI * 4615571902817575375U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 3470677184188006133U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 7175584278499266723U;
            aOrbiterC = RotL64((aOrbiterC * 10067096593682482345U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 6095078817776863055U) + aNonceWordC;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 2176637999243513070U;
            aOrbiterB = RotL64((aOrbiterB * 12215701810843975501U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 5580391239754903129U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterE) ^ 15196125567953871184U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterJ = RotL64((aOrbiterJ * 12686361960729564519U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 12787014151503209931U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 1523153207064063495U) ^ aOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3113907543551927561U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 12973289026485937829U) + aOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 9087439766232078173U) ^ aOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5817029335999350327U), 35U);
            //
            aIngress = RotL64(aOrbiterH, 29U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 36U));
            aIngress = aIngress + RotL64(aOrbiterC, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aCross, 11U) + aOrbiterJ) + RotL64(aOrbiterH, 23U)) + RotL64(aCarry, 37U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 37U) + aOrbiterJ) + RotL64(aOrbiterA, 53U));
            aWandererH = aWandererH + ((RotL64(aIngress, 23U) + aOrbiterH) + RotL64(aOrbiterB, 13U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterA, 29U)) + aOrbiterI);
            aWandererC = aWandererC + ((((RotL64(aIngress, 60U) + aOrbiterB) + RotL64(aOrbiterE, 41U)) + RotL64(aCarry, 23U)) + aNonceWordP);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterE, 35U)) + aOrbiterJ) + aWandererUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 29U) + aOrbiterC) + RotL64(aOrbiterA, 60U)) + aNonceWordN) + aWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 22U) ^ aWandererE);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererC, 57U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aOperationLaneA
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aOperationLaneA forward/backward random
        // cross from: aExpandLaneB, aWorkLaneC, aOperationLaneD
        // cross directions: aExpandLaneB backward forced, aWorkLaneC backward forced, aOperationLaneD backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 29329U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneA[((aIndex + 29140U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 32351U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29701U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 30988U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 26583U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aIngress, 24U) + RotL64(aCarry, 5U)) ^ (RotL64(aCross, 57U) + RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterH = (((aWandererI + RotL64(aPrevious, 3U)) + 2225397913940961213U) + aOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordD;
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 60U)) + 8342544893601343643U) + aOrbiterAssignSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterB = ((aWandererF + RotL64(aScatter, 21U)) + 162922186381417187U) + aNonceWordH;
            aOrbiterG = (((aWandererC + RotL64(aCross, 37U)) + RotL64(aCarry, 35U)) + 11660218373710972210U) + aNonceWordJ;
            aOrbiterK = (((aWandererA + RotL64(aPrevious, 13U)) + RotL64(aCarry, 53U)) + 14909034764605802354U) + aNonceWordN;
            aOrbiterI = (aWandererB + RotL64(aCross, 47U)) + 16776955237009701511U;
            aOrbiterE = ((aWandererK + RotL64(aIngress, 53U)) + RotL64(aCarry, 23U)) + 5834487809188925253U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 1498492772767040320U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 4161765458781579617U) ^ aOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15535994410289065281U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 10511923076962447765U) + aNonceWordB;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 8575954471692620021U;
            aOrbiterG = RotL64((aOrbiterG * 12526744988828982731U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 6536325446331340573U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 1790628986900286346U;
            aOrbiterJ = RotL64((aOrbiterJ * 5262997114200816715U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 2623814807619278590U) + aNonceWordO;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 11676970995834706612U;
            aOrbiterK = RotL64((aOrbiterK * 10057461115132434901U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 13836786354224256591U) + aNonceWordA;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 6293096163612129260U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8977954126326217153U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 4271144764978661248U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 15938494256992560202U;
            aOrbiterH = RotL64((aOrbiterH * 10004841288382726739U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 11038155227307702976U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterE = (((aOrbiterE ^ aOrbiterG) ^ 12408749795071243930U) ^ aOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterE = RotL64((aOrbiterE * 5527720475032868855U), 53U);
            //
            aIngress = RotL64(aOrbiterK, 43U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 11U));
            aIngress = aIngress + RotL64(aOrbiterB, 56U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aScatter, 29U) + RotL64(aOrbiterI, 21U)) + aOrbiterK);
            aWandererI = aWandererI ^ (((RotL64(aCross, 21U) + aOrbiterE) + RotL64(aOrbiterG, 60U)) + aNonceWordM);
            aWandererA = aWandererA + (((RotL64(aIngress, 58U) + aOrbiterB) + RotL64(aOrbiterG, 41U)) + RotL64(aCarry, 47U));
            aWandererC = aWandererC ^ ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterI, 53U)) + aOrbiterG) + aNonceWordP) + aWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aIngress, 13U) + RotL64(aOrbiterK, 11U)) + aOrbiterH);
            aWandererK = aWandererK ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterK, 3U)) + aOrbiterJ) + aWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 37U) + aOrbiterH) + RotL64(aOrbiterB, 47U)) + RotL64(aCarry, 23U)) + aNonceWordF);
            //
            aCarry = aCarry + (RotL64(aWandererD, 37U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererB, 6U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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

void TwistExpander_WaterPolo_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA;
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
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF;
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
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD;
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
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltE;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xC726730444B4F267ULL + 0x989C53B474425A70ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x9CBF23E425655539ULL + 0xDEF212EC5208BE72ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x87CF91EF87EE17DFULL + 0xC173FFBBF031635AULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xC4F17AEBB604BD79ULL + 0xCCB7D0FC2027207EULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xCAFE16360F1EB693ULL + 0x82673C90CC521889ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x89038CE9A8ECA6B5ULL + 0xA25ACA3C9D40BF9DULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xFCE177DA9EF6F3A5ULL + 0xDC121337E9338FF6ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xBDC0FC534B9CC8A1ULL + 0xBBBA6D8DCDE270D2ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xC199B7B971048381ULL + 0xCA047D061604CE80ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x926383FFA3E1BE6FULL + 0xC5720493A2501330ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xAA123D66011645C7ULL + 0x8FFE4664F804BECCULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xECE939208E214427ULL + 0xE0B9036A33DF3AE7ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xF3731F1FFC77AEE9ULL + 0xC1CDF263E6E479D2ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xDF562024544E43E9ULL + 0xC35B677B6594DBFEULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xD5F5EFF9CFABCB07ULL + 0xAEB188F4E345ACABULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x8BBFDE83FCF394C9ULL + 0xD8054B3D1F176757ULL);
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 1782U)) & W_KEY1], 43U) ^ RotL64(aKeyRowReadB[((aIndex + 291U)) & W_KEY1], 58U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 181U)) & W_KEY1], 20U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 2257U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aPrevious, 57U)) + (RotL64(aIngress, 26U) ^ RotL64(aCross, 13U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterC = (aWandererC + RotL64(aCross, 57U)) + 6521330037475130256U;
            aOrbiterK = ((aWandererH + RotL64(aScatter, 27U)) + 12611880456055428940U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 19U)) + 12061611078130934708U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = (((aWandererD + RotL64(aPrevious, 41U)) + RotL64(aCarry, 11U)) + 1558112410801116984U) + aNonceWordG;
            aOrbiterA = (((aWandererB + RotL64(aIngress, 11U)) + RotL64(aCarry, 29U)) + 10509115227850160786U) + aNonceWordN;
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 4U)) + 4045915960688792066U) + aNonceWordA;
            aOrbiterI = (((aWandererJ + RotL64(aCross, 35U)) + RotL64(aCarry, 43U)) + 1196541286513243082U) + aNonceWordO;
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 15564991032722373702U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 4897765238703641798U) ^ aNonceWordL;
            aOrbiterJ = RotL64((aOrbiterJ * 9693901276712946763U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 12327429514907752733U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 6189189797708711636U;
            aOrbiterA = RotL64((aOrbiterA * 9017615866338877651U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 6374267075282018852U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 1888758503831341439U) ^ aNonceWordH;
            aOrbiterH = RotL64((aOrbiterH * 74387714918264257U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 14956857689299491800U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 14879361107223331957U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9166712966729591953U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 16086885494838105042U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 8069724185844303923U;
            aOrbiterD = RotL64((aOrbiterD * 8878470736758734353U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 10854345917959911439U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 7078313614360332089U;
            aOrbiterK = RotL64((aOrbiterK * 9864025732292844871U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 15083669236062255011U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 594879695916679116U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9852515479152735283U), 35U);
            //
            aIngress = RotL64(aOrbiterD, 19U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 57U));
            aIngress = aIngress + RotL64(aOrbiterH, 30U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterJ, 52U)) + aOrbiterI) + aNonceWordM) + aPhaseEWandererUpdateSaltD[((aIndex + 8U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterD, 35U)) + aOrbiterA);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 39U) + RotL64(aOrbiterC, 13U)) + aOrbiterJ) + RotL64(aCarry, 43U)) + aNonceWordP);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 29U) + aOrbiterC) + RotL64(aOrbiterD, 3U));
            aWandererB = aWandererB + ((((RotL64(aPrevious, 53U) + aOrbiterH) + RotL64(aOrbiterK, 19U)) + RotL64(aCarry, 21U)) + aNonceWordJ);
            aWandererH = aWandererH ^ ((RotL64(aCross, 21U) + aOrbiterK) + RotL64(aOrbiterA, 27U));
            aWandererI = aWandererI + ((((RotL64(aIngress, 14U) + aOrbiterD) + RotL64(aOrbiterI, 41U)) + aNonceWordD) + aPhaseEWandererUpdateSaltF[((aIndex + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 52U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + RotL64(aWandererJ, 41U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 3361U)) & S_BLOCK1], 39U) ^ RotL64(aKeyRowReadA[((aIndex + 5126U)) & W_KEY1], 3U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 4283U)) & W_KEY1], 5U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 3695U)) & S_BLOCK1], 50U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aPrevious, 27U) + RotL64(aCross, 43U)) ^ (RotL64(aCarry, 5U) ^ RotL64(aIngress, 56U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterG = ((aWandererE + RotL64(aCross, 36U)) + 1210605127156905516U) + aNonceWordP;
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 43U)) + 11964595428173569519U) + aNonceWordH;
            aOrbiterK = (((aWandererK + RotL64(aIngress, 3U)) + RotL64(aCarry, 39U)) + 16277319029916258482U) + aPhaseEOrbiterAssignSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterA = ((((aWandererJ + RotL64(aScatter, 21U)) + RotL64(aCarry, 51U)) + 12369497463101824572U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordD;
            aOrbiterB = (aWandererD + RotL64(aIngress, 29U)) + 6201248574067068202U;
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 11U)) + RotL64(aCarry, 21U)) + 1727477025667206661U;
            aOrbiterD = ((aWandererI + RotL64(aCross, 57U)) + 1404510627789806851U) + aNonceWordK;
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 6948213591282018925U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 6688865181284421478U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12619122841662247279U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 3351130769402360855U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 12681032488906270823U;
            aOrbiterB = RotL64((aOrbiterB * 3680893896579741263U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 3591412591193726763U) + aNonceWordA;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 16153817571210878589U) ^ aNonceWordJ;
            aOrbiterG = RotL64((aOrbiterG * 4165137036092246349U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 3808228354421006630U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 1427373776207504205U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4534374093769595531U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 1831554180932501132U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 1114853085120949215U;
            aOrbiterE = RotL64((aOrbiterE * 4264176108298812905U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 2080935638828366835U) + aNonceWordB;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 16104777999646489828U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15205199362011777473U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 9782806013673440791U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 3721620299829386454U;
            aOrbiterA = RotL64((aOrbiterA * 6286765834910272409U), 57U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterB, 5U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 51U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 40U));
            aIngress = aIngress + RotL64(aOrbiterD, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aIngress, 58U) + aOrbiterD) + RotL64(aOrbiterA, 11U));
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterB, 19U)) + aOrbiterA) + RotL64(aCarry, 37U)) + aPhaseEWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 29U) + aOrbiterG) + RotL64(aOrbiterE, 50U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aScatter, 43U) + aOrbiterE) + RotL64(aOrbiterK, 5U)) + RotL64(aCarry, 19U)) + aNonceWordM);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 51U) + aOrbiterK) + RotL64(aOrbiterA, 35U));
            aWandererF = aWandererF + (((RotL64(aScatter, 23U) + RotL64(aOrbiterA, 41U)) + aOrbiterG) + aNonceWordC);
            aWandererE = aWandererE ^ ((RotL64(aCross, 11U) + aOrbiterG) + RotL64(aOrbiterC, 29U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 12U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererH, 43U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 7005U)) & S_BLOCK1], 28U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 5767U)) & W_KEY1], 37U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 6894U)) & W_KEY1], 57U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 7362U)) & S_BLOCK1], 22U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 7432U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aIngress, 5U)) ^ (RotL64(aCarry, 56U) + RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterF = (aWandererJ + RotL64(aCross, 60U)) + 18180797995100240808U;
            aOrbiterJ = (((aWandererI + RotL64(aScatter, 37U)) + RotL64(aCarry, 47U)) + 6585906608223552885U) + aNonceWordB;
            aOrbiterA = (aWandererD + RotL64(aIngress, 19U)) + 14088708930575939855U;
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 51U)) + 468974153311516044U) + aNonceWordP;
            aOrbiterD = (aWandererA + RotL64(aCross, 27U)) + 12481951025619894110U;
            aOrbiterG = (((aWandererF + RotL64(aPrevious, 11U)) + RotL64(aCarry, 29U)) + 17227987923860711763U) + aPhaseEOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = ((((aWandererK + RotL64(aIngress, 5U)) + RotL64(aCarry, 5U)) + 4373962756657477139U) + aPhaseEOrbiterAssignSaltC[((aIndex + 4U)) & S_SALT1]) + aNonceWordI;
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 2077576476565420951U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 17435011300234663764U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8910133867294004711U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 4118039398293246896U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 13724716599855216683U) ^ aNonceWordA;
            aOrbiterI = RotL64((aOrbiterI * 17556333902751079677U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 12391461204689596339U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 9900605191533799627U;
            aOrbiterF = RotL64((aOrbiterF * 13553565332531046301U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 972946858824366125U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 17247681919694541215U) ^ aNonceWordF;
            aOrbiterG = RotL64((aOrbiterG * 2974639094630445643U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 15442851427306771601U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 7303586227288294037U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15406402525021428799U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 12650358753454105119U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 1483710933373510492U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6531763256577221891U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 18065810162229740788U) + aNonceWordC;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 11311677121338794007U;
            aOrbiterJ = RotL64((aOrbiterJ * 15116367961682119467U), 3U);
            //
            aIngress = RotL64(aOrbiterA, 11U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 35U));
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterF, 60U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aIngress, 51U) + RotL64(aOrbiterD, 27U)) + aOrbiterI);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterA, 57U)) + aOrbiterI) + aNonceWordG);
            aWandererF = aWandererF + ((((RotL64(aCross, 58U) + aOrbiterG) + RotL64(aOrbiterF, 3U)) + aNonceWordJ) + aPhaseEWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 43U) + aOrbiterF) + RotL64(aOrbiterJ, 11U)) + aNonceWordK);
            aWandererC = aWandererC + ((((RotL64(aIngress, 13U) + RotL64(aOrbiterA, 50U)) + aOrbiterE) + RotL64(aCarry, 3U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterF, 35U)) + aOrbiterA);
            aWandererA = aWandererA + (((RotL64(aCross, 21U) + RotL64(aOrbiterJ, 43U)) + aOrbiterI) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererK);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + (RotL64(aWandererJ, 42U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererD, 11U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 9597U)) & S_BLOCK1], 37U) ^ RotL64(aKeyRowReadB[((aIndex + 9542U)) & W_KEY1], 5U));
            aIngress ^= (RotL64(mSource[((aIndex + 10743U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((aIndex + 10295U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 9676U)) & W_KEY1], 13U) ^ RotL64(aWorkLaneB[((aIndex + 9807U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 40U) ^ RotL64(aPrevious, 3U)) ^ (RotL64(aCross, 19U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterI = ((aWandererK + RotL64(aCross, 43U)) + 3448371607470865612U) + aNonceWordO;
            aOrbiterK = (((aWandererC + RotL64(aIngress, 19U)) + RotL64(aCarry, 3U)) + 3743742913651580573U) + aNonceWordL;
            aOrbiterE = (((aWandererD + RotL64(aScatter, 27U)) + RotL64(aCarry, 27U)) + 13069491287948807280U) + aNonceWordN;
            aOrbiterJ = (((aWandererA + RotL64(aPrevious, 37U)) + RotL64(aCarry, 43U)) + 16872779275586545632U) + aPhaseFOrbiterAssignSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterF = (aWandererB + RotL64(aIngress, 11U)) + 17945792656755062795U;
            aOrbiterD = (((aWandererE + RotL64(aCross, 4U)) + 18199747196793731853U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordB;
            aOrbiterG = (aWandererI + RotL64(aScatter, 51U)) + 15953311878379809513U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 941268763494588338U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 10090221530365796809U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14035236086292997613U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 8335698093307607001U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 6147498804734306100U) ^ aNonceWordJ;
            aOrbiterD = RotL64((aOrbiterD * 6904444049941211327U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 5980246079567570090U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 4152167624425912978U;
            aOrbiterI = RotL64((aOrbiterI * 10019421651535123573U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 14990418790239735916U) + aNonceWordE;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 3418668387496597219U;
            aOrbiterF = RotL64((aOrbiterF * 12814077238529863119U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 4206650904177199425U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 3905470780938996069U;
            aOrbiterK = RotL64((aOrbiterK * 16030122739273137005U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 9968672788233080924U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 602258075661864866U;
            aOrbiterG = RotL64((aOrbiterG * 2615726693066300065U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 17751667243048041383U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 2414054413585296027U;
            aOrbiterJ = RotL64((aOrbiterJ * 1049512574773201893U), 19U);
            //
            aIngress = RotL64(aOrbiterI, 57U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 3U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + RotL64(aOrbiterG, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aIngress, 47U) + RotL64(aOrbiterE, 27U)) + aOrbiterK) + RotL64(aCarry, 47U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 19U) + aOrbiterE) + RotL64(aOrbiterJ, 43U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 28U) + aOrbiterE) + RotL64(aOrbiterG, 5U)) + RotL64(aCarry, 21U)) + aNonceWordF);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterJ, 58U)) + aOrbiterD) + aNonceWordI);
            aWandererD = aWandererD + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterG, 21U)) + aOrbiterJ);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterJ, 37U)) + aOrbiterF) + aNonceWordG);
            aWandererK = aWandererK + (((RotL64(aIngress, 35U) + aOrbiterI) + RotL64(aOrbiterF, 51U)) + aPhaseFWandererUpdateSaltA[((aIndex + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 58U) ^ aWandererB);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 53U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + RotL64(aWandererC, 39U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aWorkLaneD[((aIndex + 12673U)) & S_BLOCK1], 29U) ^ RotL64(aKeyRowReadA[((aIndex + 11853U)) & W_KEY1], 58U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 11731U)) & W_KEY1], 21U) ^ RotL64(mSource[((aIndex + 13078U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 13253U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13039U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 12058U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCarry, 26U) + RotL64(aIngress, 57U)) ^ (RotL64(aPrevious, 13U) + RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterC = ((aWandererB + RotL64(aCross, 5U)) + RotL64(aCarry, 3U)) + 1142447269198373880U;
            aOrbiterJ = (aWandererA + RotL64(aScatter, 11U)) + 10581460640040336191U;
            aOrbiterK = (((aWandererH + RotL64(aIngress, 21U)) + 14703062773878202900U) + aPhaseFOrbiterAssignSaltD[((aIndex + 8U)) & S_SALT1]) + aNonceWordF;
            aOrbiterB = (((aWandererJ + RotL64(aPrevious, 47U)) + RotL64(aCarry, 39U)) + 15737525756286914746U) + aNonceWordB;
            aOrbiterD = ((aWandererC + RotL64(aCross, 57U)) + 16178774478273186999U) + aNonceWordC;
            aOrbiterA = ((aWandererG + RotL64(aIngress, 27U)) + RotL64(aCarry, 23U)) + 2514897053906809160U;
            aOrbiterI = (((aWandererK + RotL64(aScatter, 36U)) + 13702496607592508464U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordL;
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 18030885275418337965U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterC) ^ 5241783876161655984U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterK = RotL64((aOrbiterK * 10970981186787227937U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 2807052676283587925U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 8022804576763271327U;
            aOrbiterJ = RotL64((aOrbiterJ * 11727096043219370577U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 15597099852232205860U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 1538435607932096400U;
            aOrbiterB = RotL64((aOrbiterB * 7900752511710516981U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 11147868774413615365U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 9325213746830411568U;
            aOrbiterD = RotL64((aOrbiterD * 561819005818948769U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 13792300423550555634U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 3134856508983945719U;
            aOrbiterA = RotL64((aOrbiterA * 4271845067763664863U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 8654966018053784882U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 8937113935476779267U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7386875687217705855U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 4135676350355234788U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterI) ^ 11407912615743682678U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterC = RotL64((aOrbiterC * 2773506587480714695U), 35U);
            //
            aIngress = RotL64(aOrbiterA, 41U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterD, 29U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + RotL64(aOrbiterJ, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterA, 20U)) + aOrbiterK);
            aWandererK = aWandererK + ((((RotL64(aIngress, 60U) + RotL64(aOrbiterI, 3U)) + aOrbiterC) + RotL64(aCarry, 57U)) + aNonceWordD);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 11U) + aOrbiterK) + RotL64(aOrbiterD, 29U)) + aPhaseFWandererUpdateSaltA[((aIndex + 18U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterC, 11U)) + aOrbiterK) + RotL64(aCarry, 21U)) + aNonceWordA);
            aWandererH = aWandererH ^ ((((RotL64(aIngress, 43U) + aOrbiterA) + RotL64(aOrbiterB, 43U)) + aNonceWordP) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 37U) + RotL64(aOrbiterI, 57U)) + aOrbiterK);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterJ, 51U)) + aOrbiterB) + aNonceWordI);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 40U));
            aCarry = aCarry + RotL64(aWandererC, 35U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 14601U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 16325U)) & S_BLOCK1], 14U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15374U)) & W_KEY1], 11U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 14477U)) & W_KEY1], 3U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 13864U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 14509U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13902U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCarry, 35U) ^ RotL64(aIngress, 48U)) ^ (RotL64(aCross, 5U) + RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 4U)) + RotL64(aCarry, 43U)) + 6733949564325516029U;
            aOrbiterG = (aWandererE + RotL64(aScatter, 29U)) + 7304098437143918796U;
            aOrbiterK = (aWandererD + RotL64(aIngress, 51U)) + 3923949518391777800U;
            aOrbiterF = ((((aWandererA + RotL64(aCross, 11U)) + RotL64(aCarry, 21U)) + 14243591003388927124U) + aPhaseFOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1]) + aNonceWordL;
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 19U)) + 18329498724605410406U) + aNonceWordH;
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 57U)) + 13118172167747037249U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 41U)) + RotL64(aCarry, 57U)) + 5272025143849174212U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 16075917179214318424U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 15263590648674658399U;
            aOrbiterK = RotL64((aOrbiterK * 9918239923411740337U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 13730046728289525921U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 7703141464499623408U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5886009900621521987U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 1382279753822135359U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 2973369221699098292U) ^ aNonceWordN;
            aOrbiterF = RotL64((aOrbiterF * 7440242040663550631U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 11578274119583013219U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 3419411247737896674U;
            aOrbiterC = RotL64((aOrbiterC * 17814942652262802991U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 2582783513078999303U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 3959762790273529677U;
            aOrbiterE = RotL64((aOrbiterE * 383974377372162751U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 465795011576934604U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 17880826624185821135U) ^ aNonceWordE;
            aOrbiterG = RotL64((aOrbiterG * 4445949147592860913U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 10819659185349413173U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterK) ^ 17298208553586835030U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterJ = RotL64((aOrbiterJ * 1965860510614222093U), 21U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterG, 5U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 37U));
            aIngress = aIngress + (RotL64(aOrbiterF, 43U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterC, 12U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 50U) + aOrbiterC) + RotL64(aOrbiterE, 11U)) + RotL64(aCarry, 13U));
            aWandererA = aWandererA ^ ((((RotL64(aCross, 57U) + aOrbiterJ) + RotL64(aOrbiterF, 47U)) + aNonceWordC) + aPhaseFWandererUpdateSaltE[((aIndex + 20U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 11U) + aOrbiterJ) + RotL64(aOrbiterG, 27U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 37U) + aOrbiterH) + RotL64(aOrbiterE, 3U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterK, 41U)) + aOrbiterH);
            aWandererE = aWandererE ^ ((((RotL64(aCross, 29U) + RotL64(aOrbiterG, 53U)) + aOrbiterH) + aNonceWordI) + aPhaseFWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aScatter, 5U) + aOrbiterF) + RotL64(aOrbiterC, 20U)) + RotL64(aCarry, 29U)) + aNonceWordD);
            //
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererC, 56U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererE, 39U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 16591U)) & S_BLOCK1], 5U) ^ RotL64(aKeyRowReadA[((aIndex + 17191U)) & W_KEY1], 27U));
            aIngress ^= (RotL64(mSource[((aIndex + 16831U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17469U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 17430U)) & W_KEY1], 11U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 16681U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 17857U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCross, 21U)) + (RotL64(aIngress, 5U) + RotL64(aCarry, 38U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterK = ((aWandererE + RotL64(aScatter, 47U)) + 14823268998003220191U) + aNonceWordN;
            aOrbiterH = (((aWandererB + RotL64(aPrevious, 41U)) + 15295237288788213847U) + aPhaseGOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1]) + aNonceWordE;
            aOrbiterI = (aWandererA + RotL64(aCross, 12U)) + 16434853402001133899U;
            aOrbiterB = (((aWandererF + RotL64(aIngress, 21U)) + RotL64(aCarry, 3U)) + 7555911304407871631U) + aPhaseGOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 35U)) + 14977248264994834620U) + aNonceWordH;
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 27U)) + RotL64(aCarry, 43U)) + 9707764144919392380U;
            aOrbiterF = ((aWandererD + RotL64(aCross, 57U)) + RotL64(aCarry, 27U)) + 1277304385464681529U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 3089786220465849395U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 3700503853358695085U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2079089949442685421U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 3240054112993517371U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 16897532076915366859U;
            aOrbiterH = RotL64((aOrbiterH * 4120874717534309035U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 18167359289798364307U) + aNonceWordF;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 8870819278575769863U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9334066154398059075U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 15363069206212330251U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 14858164441499725158U;
            aOrbiterB = RotL64((aOrbiterB * 14931933411393847915U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 5357144808788707522U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 2910681277417754860U) ^ aNonceWordM;
            aOrbiterF = RotL64((aOrbiterF * 13170868582159347059U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 9824408699018165151U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 368370224788793300U;
            aOrbiterK = RotL64((aOrbiterK * 14358982366258729959U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 7095398304588825115U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 11418879758164313554U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5983520332639771791U), 3U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterC, 47U);
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterI, 60U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterD, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterC, 47U)) + aOrbiterD) + aNonceWordA) + aPhaseGWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((((RotL64(aCross, 27U) + aOrbiterB) + RotL64(aOrbiterF, 11U)) + aNonceWordJ) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 4U) + aOrbiterH) + RotL64(aOrbiterB, 53U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 53U) + aOrbiterI) + RotL64(aOrbiterB, 60U));
            aWandererF = aWandererF + (((RotL64(aScatter, 43U) + aOrbiterB) + RotL64(aOrbiterD, 29U)) + RotL64(aCarry, 53U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterH, 23U)) + aOrbiterC) + aNonceWordG);
            aWandererB = aWandererB + (((RotL64(aCross, 21U) + aOrbiterK) + RotL64(aOrbiterC, 5U)) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 34U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + RotL64(aWandererE, 23U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 21680U)) & S_BLOCK1], 42U) ^ RotL64(mSource[((aIndex + 20167U)) & S_BLOCK1], 23U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 21713U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((aIndex + 19205U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 20405U)) & W_KEY1], 19U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 20059U)) & W_KEY1], 35U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 19201U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((aIndex + 21574U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCross, 37U) + RotL64(aIngress, 52U)) ^ (RotL64(aPrevious, 3U) + RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterJ = (aWandererG + RotL64(aScatter, 57U)) + 9023059520606551446U;
            aOrbiterH = (((aWandererF + RotL64(aIngress, 43U)) + RotL64(aCarry, 5U)) + 662441755115638133U) + aPhaseGOrbiterAssignSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = (((aWandererI + RotL64(aPrevious, 5U)) + 16957253361196144712U) + aPhaseGOrbiterAssignSaltC[((aIndex + 8U)) & S_SALT1]) + aNonceWordM;
            aOrbiterD = (aWandererK + RotL64(aCross, 11U)) + 7840955025765308605U;
            aOrbiterC = ((aWandererE + RotL64(aScatter, 23U)) + RotL64(aCarry, 37U)) + 346855809270395799U;
            aOrbiterF = (((aWandererD + RotL64(aPrevious, 35U)) + RotL64(aCarry, 53U)) + 16099139781586668343U) + aNonceWordI;
            aOrbiterB = ((aWandererC + RotL64(aCross, 50U)) + 3706457327118322098U) + aNonceWordK;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 12166825885547622870U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 7792658665720344200U;
            aOrbiterK = RotL64((aOrbiterK * 16305542632794270697U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 7128477606152986326U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 11116533962780290084U;
            aOrbiterC = RotL64((aOrbiterC * 11993485572912492297U), 5U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterF) + 10443889548568288532U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordL;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 4402387036946561017U;
            aOrbiterD = RotL64((aOrbiterD * 9032964741841833277U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 13002706161178447654U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 13929727277530310708U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7005639090871200285U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 10949073760696935106U) + aNonceWordD;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 15405923432006783533U;
            aOrbiterF = RotL64((aOrbiterF * 17989565878445202495U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 18096057968822208905U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 3032155040484574973U;
            aOrbiterB = RotL64((aOrbiterB * 448597307502544605U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 17462076466907467134U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 15471015427013701406U;
            aOrbiterH = RotL64((aOrbiterH * 6113474000571976139U), 21U);
            //
            aIngress = RotL64(aOrbiterH, 35U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 27U));
            aIngress = aIngress + (RotL64(aOrbiterB, 20U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterD, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((((RotL64(aScatter, 47U) + aOrbiterC) + RotL64(aOrbiterK, 6U)) + aNonceWordH) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aCross, 27U) + aOrbiterD) + RotL64(aOrbiterB, 29U)) + RotL64(aCarry, 19U)) + aNonceWordG);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 13U) + aOrbiterJ) + RotL64(aOrbiterD, 47U)) + aNonceWordJ);
            aWandererI = aWandererI + ((RotL64(aIngress, 34U) + aOrbiterK) + RotL64(aOrbiterF, 21U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterH, 13U)) + aOrbiterF) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 21U) + aOrbiterF) + RotL64(aOrbiterB, 35U)) + RotL64(aCarry, 39U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterF, 57U)) + aOrbiterC) + aNonceWordO);
            //
            aCarry = aCarry + (RotL64(aWandererK, 6U) ^ aWandererE);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 37U));
            aCarry = aCarry + RotL64(aWandererF, 43U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 24195U)) & S_BLOCK1], 57U) ^ RotL64(aKeyRowReadA[((aIndex + 22061U)) & W_KEY1], 29U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 24463U)) & W_KEY1], 13U) ^ RotL64(aFireLaneC[((aIndex + 24158U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 23257U)) & S_BLOCK1], 41U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 22445U)) & S_BLOCK1], 4U));
            aCross ^= (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 23931U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneD[((aIndex + 24325U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCarry, 36U)) ^ (RotL64(aCross, 5U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterB = ((aWandererB + RotL64(aScatter, 13U)) + 13687218104610230596U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = ((aWandererK + RotL64(aCross, 47U)) + 6841550124960692709U) + aNonceWordN;
            aOrbiterD = (((aWandererH + RotL64(aPrevious, 41U)) + RotL64(aCarry, 51U)) + 17418968668458764131U) + aNonceWordC;
            aOrbiterC = ((aWandererC + RotL64(aIngress, 5U)) + RotL64(aCarry, 5U)) + 8303537912696948204U;
            aOrbiterI = ((((aWandererJ + RotL64(aScatter, 35U)) + RotL64(aCarry, 35U)) + 12376614417285936537U) + aPhaseGOrbiterAssignSaltC[((aIndex + 20U)) & S_SALT1]) + aNonceWordH;
            aOrbiterG = ((aWandererI + RotL64(aCross, 21U)) + 14215749063579232654U) + aNonceWordP;
            aOrbiterF = (aWandererA + RotL64(aPrevious, 58U)) + 4111736931433665347U;
            //
            aOrbiterB = (((aOrbiterB + aOrbiterJ) + 11250375934571631522U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1]) + aNonceWordD;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 5367367837773331275U;
            aOrbiterD = RotL64((aOrbiterD * 7262723007545807179U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 15514089192382674434U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 1475991716685034960U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17720681295551650891U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 5531622777788629748U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 8363822215908303335U;
            aOrbiterG = RotL64((aOrbiterG * 17850203366840994883U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 3741256932685720414U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 11634667238062155772U;
            aOrbiterI = RotL64((aOrbiterI * 15925089729784547403U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 18180546911210417155U) + aNonceWordO;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 5123234656838556335U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15362857462853398025U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 11215734271189250284U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 16863747802158398092U;
            aOrbiterB = RotL64((aOrbiterB * 1828035970246160023U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 9859050606636646323U) + aNonceWordE;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 9331300036643654675U) ^ aNonceWordB;
            aOrbiterC = RotL64((aOrbiterC * 2502263410556166281U), 47U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterG, 35U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 22U));
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aCross, 19U) + aOrbiterC) + RotL64(aOrbiterF, 57U)) + aNonceWordF);
            aWandererB = aWandererB + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterJ, 22U)) + aOrbiterD) + RotL64(aCarry, 41U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterI, 47U)) + aOrbiterF);
            aWandererI = aWandererI + ((((RotL64(aIngress, 10U) + RotL64(aOrbiterJ, 35U)) + aOrbiterB) + RotL64(aCarry, 29U)) + aPhaseGWandererUpdateSaltD[((aIndex + 18U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterG, 41U)) + aOrbiterF);
            aWandererH = aWandererH + ((RotL64(aScatter, 35U) + aOrbiterD) + RotL64(aOrbiterB, 11U));
            aWandererC = aWandererC ^ ((((RotL64(aIngress, 47U) + aOrbiterB) + RotL64(aOrbiterF, 29U)) + aNonceWordI) + aPhaseGWandererUpdateSaltA[((aIndex + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 56U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererA, 23U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 24643U)) & S_BLOCK1], 27U) ^ RotL64(aKeyRowReadA[((aIndex + 24849U)) & W_KEY1], 40U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 26211U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 25917U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 27052U)) & W_KEY1], 60U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 26740U)) & S_BLOCK1], 13U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 26928U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 25637U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 42U) + RotL64(aIngress, 5U)) ^ (RotL64(aPrevious, 29U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterG = (aWandererK + RotL64(aScatter, 29U)) + 8020711767807230555U;
            aOrbiterC = (((aWandererA + RotL64(aCross, 4U)) + 15368693777246341570U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordC;
            aOrbiterJ = (((aWandererB + RotL64(aPrevious, 11U)) + RotL64(aCarry, 39U)) + 5117523734225562401U) + aNonceWordK;
            aOrbiterF = (aWandererE + RotL64(aIngress, 51U)) + 13155269151097507808U;
            aOrbiterK = (((aWandererG + RotL64(aCross, 37U)) + RotL64(aCarry, 23U)) + 9879303753623578272U) + aNonceWordM;
            aOrbiterH = (aWandererH + RotL64(aIngress, 23U)) + 1165799257173794826U;
            aOrbiterA = (((aWandererC + RotL64(aScatter, 43U)) + RotL64(aCarry, 3U)) + 930641942062732091U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 11330571332221123153U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 2862963158282518899U;
            aOrbiterJ = RotL64((aOrbiterJ * 13782195862525974199U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 6019186399361476659U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 1924419843785161958U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9485557122500346869U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 12618629043591380461U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 9334176504266512405U) ^ aNonceWordD;
            aOrbiterF = RotL64((aOrbiterF * 18239109235362925739U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 16829692481030013551U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 5604784396927022709U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2833893610883508353U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 16124030106598549644U) + aNonceWordH;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 16571659812830230677U) ^ aNonceWordE;
            aOrbiterC = RotL64((aOrbiterC * 4668250364992383549U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 15171089673591843703U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 2826755560293849328U;
            aOrbiterG = RotL64((aOrbiterG * 9397017963457655287U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 9976785768283589291U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 11845100564714691809U;
            aOrbiterH = RotL64((aOrbiterH * 4935139932585319251U), 27U);
            //
            aIngress = RotL64(aOrbiterG, 43U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + (RotL64(aOrbiterF, 35U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterC, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aCross, 41U) + aOrbiterJ) + RotL64(aOrbiterC, 19U)) + aPhaseHWandererUpdateSaltB[((aIndex + 10U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aIngress, 27U) + aOrbiterG) + RotL64(aOrbiterA, 29U)) + RotL64(aCarry, 3U)) + aNonceWordB);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 60U) + RotL64(aOrbiterK, 53U)) + aOrbiterA);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterK, 5U)) + aOrbiterH) + RotL64(aCarry, 35U)) + aNonceWordL);
            aWandererG = aWandererG ^ ((RotL64(aCross, 13U) + aOrbiterG) + RotL64(aOrbiterJ, 13U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 5U) + aOrbiterA) + RotL64(aOrbiterH, 35U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 53U) + aOrbiterK) + RotL64(aOrbiterF, 46U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + (RotL64(aWandererE, 58U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererC, 5U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 28965U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneD[((aIndex + 28954U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 29803U)) & W_KEY1], 13U) ^ RotL64(aFireLaneC[((aIndex + 29628U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 29716U)) & W_KEY1], 47U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 28387U)) & S_BLOCK1], 3U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28650U)) & S_BLOCK1], 12U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 28297U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 27U) + RotL64(aCarry, 53U)) + (RotL64(aCross, 40U) ^ RotL64(aIngress, 13U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterI = ((aWandererB + RotL64(aCross, 13U)) + RotL64(aCarry, 51U)) + 4068921616130916949U;
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 58U)) + 12077715273915151726U) + aNonceWordP;
            aOrbiterG = (((aWandererD + RotL64(aPrevious, 3U)) + RotL64(aCarry, 5U)) + 16047546802670596833U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = (aWandererE + RotL64(aScatter, 27U)) + 9690277462716999763U;
            aOrbiterA = (((aWandererI + RotL64(aCross, 51U)) + 14484814700447992628U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordH;
            aOrbiterF = (((aWandererH + RotL64(aScatter, 41U)) + RotL64(aCarry, 35U)) + 17089267243053958210U) + aNonceWordB;
            aOrbiterC = ((aWandererA + RotL64(aIngress, 35U)) + 9138746214446211147U) + aNonceWordL;
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 10181001536979097045U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 6657458969093373191U) ^ aNonceWordJ;
            aOrbiterG = RotL64((aOrbiterG * 4311019792293202747U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 7515983477876590988U) + aNonceWordI;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 3039935555863947600U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12511160550780270119U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 16209389224740851136U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 725253312098083182U;
            aOrbiterI = RotL64((aOrbiterI * 17535989492095522597U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 13307041115748941383U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 7159572004825238263U;
            aOrbiterC = RotL64((aOrbiterC * 4855009895002398449U), 57U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterC) + 12027236743251643820U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordF;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 8717826175991286553U;
            aOrbiterH = RotL64((aOrbiterH * 1175614802543098451U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 4769096034227659937U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 11201226563992939616U;
            aOrbiterD = RotL64((aOrbiterD * 15595355978388159931U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 17295978531215563256U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterD) ^ 11850923890626719833U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterF = RotL64((aOrbiterF * 3854851059897397075U), 43U);
            //
            aIngress = RotL64(aOrbiterI, 3U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 19U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 26U));
            aIngress = aIngress + RotL64(aOrbiterD, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aPrevious, 12U) + RotL64(aOrbiterG, 47U)) + aOrbiterA) + aNonceWordO);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterC, 13U)) + aOrbiterI) + aPhaseHWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 5U) + RotL64(aOrbiterF, 29U)) + aOrbiterH) + RotL64(aCarry, 47U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 35U) + aOrbiterA) + RotL64(aOrbiterD, 3U)) + aNonceWordK);
            aWandererH = aWandererH + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterC, 19U)) + aOrbiterF);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterH, 37U)) + aOrbiterI);
            aWandererA = aWandererA + ((((RotL64(aIngress, 53U) + RotL64(aOrbiterF, 58U)) + aOrbiterA) + RotL64(aCarry, 27U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 56U));
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererD);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + RotL64(aWandererJ, 43U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 30239U)) & S_BLOCK1], 51U) ^ RotL64(aKeyRowReadA[((aIndex + 30410U)) & W_KEY1], 14U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 32708U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31634U)) & S_BLOCK1], 57U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32543U)) & S_BLOCK1], 13U) ^ RotL64(aKeyRowReadB[((aIndex + 30238U)) & W_KEY1], 42U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCarry, 41U)) ^ (RotL64(aCross, 57U) + RotL64(aPrevious, 20U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 27U)) + RotL64(aCarry, 11U)) + 17668251151213543491U;
            aOrbiterJ = (((aWandererF + RotL64(aIngress, 5U)) + RotL64(aCarry, 39U)) + 16101602509895104517U) + aNonceWordP;
            aOrbiterA = ((aWandererJ + RotL64(aCross, 48U)) + 9083915270773304935U) + aNonceWordD;
            aOrbiterD = (aWandererE + RotL64(aScatter, 41U)) + 12810720730318214811U;
            aOrbiterI = (((aWandererA + RotL64(aCross, 13U)) + RotL64(aCarry, 51U)) + 18113428002071925621U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = (((aWandererK + RotL64(aScatter, 35U)) + 1582208899354109878U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordL;
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 57U)) + 4180688104819188154U) + aNonceWordG;
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 8954598189262820611U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 15360094153175355879U;
            aOrbiterA = RotL64((aOrbiterA * 8177798855402983685U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 8383954114668216260U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 15626783326234049197U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15058420415480073793U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 10609978564404958066U) + aNonceWordN;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 17656516608997517984U;
            aOrbiterJ = RotL64((aOrbiterJ * 4590620354119899777U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 760077259110786536U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 3597338735888033063U) ^ aNonceWordH;
            aOrbiterK = RotL64((aOrbiterK * 6548831472863517621U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 4431777844935985157U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 10710423172154671296U;
            aOrbiterG = RotL64((aOrbiterG * 16267496318491473315U), 57U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterA) + 10240882795242085185U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordC;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 7826053487019825891U;
            aOrbiterF = RotL64((aOrbiterF * 15053729937684375907U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 9418883403715727353U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 11507423614799075545U;
            aOrbiterD = RotL64((aOrbiterD * 16189463984557044693U), 29U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterF, 43U);
            aIngress = aIngress + (RotL64(aOrbiterA, 11U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + RotL64(aOrbiterG, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 3U) + aOrbiterI) + RotL64(aOrbiterA, 57U)) + aNonceWordB);
            aWandererD = aWandererD + (((RotL64(aScatter, 53U) + RotL64(aOrbiterD, 35U)) + aOrbiterK) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ ((((RotL64(aIngress, 37U) + RotL64(aOrbiterG, 29U)) + aOrbiterI) + aNonceWordI) + aPhaseHWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 60U) + RotL64(aOrbiterA, 51U)) + aOrbiterG) + RotL64(aCarry, 29U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 47U) + aOrbiterJ) + RotL64(aOrbiterD, 12U)) + aNonceWordF);
            aWandererC = aWandererC + (((RotL64(aCross, 19U) + aOrbiterK) + RotL64(aOrbiterA, 5U)) + aNonceWordE);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 29U) + aOrbiterA) + RotL64(aOrbiterF, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererD, 36U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererE, 29U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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

void TwistExpander_WaterPolo_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x9C8643A1439CF2B3ULL + 0x880682F1198D80FDULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xA3AC04DA4A38E791ULL + 0xCF215330F104DA94ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x836A2CC2B962FA1DULL + 0xB23453BD6E5799DDULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xFC94CC9A9865FC89ULL + 0xDE9049AE7A2426EAULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xD2666BCE342BE17BULL + 0xECC749D344E01BEBULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xA6F67CD429FD6775ULL + 0x87D1A0661F6AA2E2ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xD216865EE2EE1A95ULL + 0xE70694A3C985CCB8ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x9F8E0D5038BF6089ULL + 0xE21746111E1D659CULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xA22AD9FE788BE939ULL + 0xF41E034BE2CBE02FULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xD32B0A67A7C7670DULL + 0xC7CAB1A8835A85A2ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xF97EF6841A257CCFULL + 0xC09BE5420C6471CDULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xD8564776EACBF5E9ULL + 0xB8CAD7637BBEE3C6ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xFF5FF9422B6D4D93ULL + 0xCDE05514BB97FECBULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x86D4204393229C59ULL + 0xE0CD8A342FF82815ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xF6BE1A028EB5B5EDULL + 0xA09DA1476DF84E21ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xAD6C69F648C4F9FDULL + 0x83BBCE0C4C7ED97AULL);
    // GSeedRunSeed_B seed_loop_a (start)
    {
        // GSeedRunSeed_B seed_loop_a lane group
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneA, aFireLaneC, aInvestLaneB, aFireLaneA, aOperationLaneA, aFireLaneD, aOperationLaneB, aOperationLaneC
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 5153U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneB[((aIndex + 2594U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 2713U)) & S_BLOCK1], 34U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5048U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 3367U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aPrevious, 35U)) + (RotL64(aIngress, 52U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterD = (aWandererB + RotL64(aIngress, 19U)) + 5131645209694953015U;
            aOrbiterB = ((((aWandererE + RotL64(aPrevious, 58U)) + RotL64(aCarry, 11U)) + 12070391048835379854U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordB;
            aOrbiterA = (((aWandererJ + RotL64(aCross, 43U)) + RotL64(aCarry, 37U)) + 2604295836242338724U) + aNonceWordO;
            aOrbiterE = ((aWandererG + RotL64(aScatter, 29U)) + 14042039029284001596U) + aNonceWordA;
            aOrbiterK = (((aWandererK + RotL64(aIngress, 3U)) + RotL64(aCarry, 51U)) + 8914654543854559327U) + aPhaseAOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1];
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 2185619407969359869U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 5187406295103352574U;
            aOrbiterA = RotL64((aOrbiterA * 10497064008152537837U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 8022832481290871217U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 8783061916740573472U;
            aOrbiterK = RotL64((aOrbiterK * 3309891377744201773U), 19U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterA) + 10711028365596196301U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1]) + aNonceWordH;
            aOrbiterE = (((aOrbiterE ^ aOrbiterB) ^ 13387065038269133571U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterE = RotL64((aOrbiterE * 12444578026365205255U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 11187001318931801582U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 14191473173276034019U;
            aOrbiterD = RotL64((aOrbiterD * 2491253922434756431U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 16207761776716426435U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 9677408414452078760U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5487303383095129949U), 5U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterB, 37U);
            aIngress = aIngress + (RotL64(aOrbiterK, 23U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((((RotL64(aScatter, 27U) + RotL64(aOrbiterA, 43U)) + aOrbiterD) + RotL64(aCarry, 29U)) + aNonceWordC) + aPhaseAWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aCross, 39U) + aOrbiterB) + RotL64(aOrbiterE, 3U)) + aNonceWordG);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterK, 22U)) + aOrbiterA);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 19U) + aOrbiterA) + RotL64(aOrbiterE, 13U)) + aNonceWordM);
            aWandererK = aWandererK + (((((RotL64(aPrevious, 60U) + aOrbiterB) + RotL64(aOrbiterK, 57U)) + RotL64(aCarry, 47U)) + aNonceWordL) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + (RotL64(aWandererJ, 48U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 29U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aInvestLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 2
        // ingress from: aInvestLaneA, aExpandLaneC, aFireLaneC
        // ingress directions: aInvestLaneA forward forced, aExpandLaneC forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneA[((aIndex + 8227U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((aIndex + 9241U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 8661U)) & S_BLOCK1], 22U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 8136U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 9045U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aIngress, 40U) + RotL64(aCarry, 11U)) + (RotL64(aCross, 53U) ^ RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterC = (((aWandererE + RotL64(aScatter, 27U)) + 6069475454765660321U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordK;
            aOrbiterA = (((aWandererD + RotL64(aIngress, 50U)) + RotL64(aCarry, 35U)) + 11483704742497268068U) + aNonceWordO;
            aOrbiterJ = ((aWandererB + RotL64(aCross, 13U)) + 11055697447388986418U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = (((aWandererF + RotL64(aPrevious, 3U)) + RotL64(aCarry, 51U)) + 10897095046039997004U) + aNonceWordE;
            aOrbiterD = (((aWandererC + RotL64(aScatter, 41U)) + RotL64(aCarry, 21U)) + 4731637118230457840U) + aNonceWordP;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 13855839187084986751U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 5328208115460188239U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3800417611141123383U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 12479538544291412985U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 10740165998792608231U) ^ aNonceWordI;
            aOrbiterC = RotL64((aOrbiterC * 14046827922294477379U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 6492798157284955373U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 13056825957483891921U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14882112110627751751U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 2068184064919194657U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 5656302738780746294U;
            aOrbiterA = RotL64((aOrbiterA * 16493021179127646345U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 11193756120230763294U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 17306750816837208999U) ^ aNonceWordJ;
            aOrbiterD = RotL64((aOrbiterD * 7949360041241439741U), 57U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterD, 3U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 57U));
            aIngress = aIngress + RotL64(aOrbiterC, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aCross, 21U) + RotL64(aOrbiterB, 11U)) + aOrbiterJ) + RotL64(aCarry, 57U)) + aNonceWordN);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterJ, 44U)) + aOrbiterC) + aNonceWordB);
            aWandererD = aWandererD + (((RotL64(aIngress, 35U) + aOrbiterJ) + RotL64(aOrbiterD, 35U)) + aNonceWordH);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterA, 3U)) + aOrbiterJ) + aPhaseAWandererUpdateSaltA[((aIndex + 6U)) & S_SALT1]);
            aWandererF = aWandererF + (((((RotL64(aIngress, 4U) + RotL64(aOrbiterB, 27U)) + aOrbiterA) + RotL64(aCarry, 5U)) + aNonceWordA) + aPhaseAWandererUpdateSaltF[((aIndex + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererB, 56U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererD, 35U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aInvestLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_a loop 3
        // ingress from: aInvestLaneB, aExpandLaneD, aFireLaneA
        // ingress directions: aInvestLaneB forward forced, aExpandLaneD forward forced, aFireLaneA forward/backward random
        // cross from: aInvestLaneA, aExpandLaneB, aExpandLaneA
        // cross directions: aInvestLaneA backward forced, aExpandLaneB backward forced, aExpandLaneA backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneB[((aIndex + 13754U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneD[((aIndex + 14775U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 13966U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 14502U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 11241U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aExpandLaneA[((aIndex + 14422U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aIngress, 56U) + RotL64(aCross, 5U)) ^ (RotL64(aCarry, 35U) + RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterK = ((((aWandererC + RotL64(aIngress, 54U)) + RotL64(aCarry, 13U)) + 7960325128608297381U) + aPhaseAOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1]) + aNonceWordG;
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 3U)) + 12773836012104052042U) + aNonceWordM;
            aOrbiterH = (((aWandererA + RotL64(aScatter, 11U)) + RotL64(aCarry, 39U)) + 3173972621347773016U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = ((aWandererH + RotL64(aCross, 19U)) + RotL64(aCarry, 27U)) + 3708401356314308171U;
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 39U)) + 950774285720019449U) + aNonceWordA;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 4170092315705438265U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 17000449130864980747U) ^ aNonceWordN;
            aOrbiterH = RotL64((aOrbiterH * 7710635557693533263U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 8793910540062893860U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 520277969543516469U) ^ aNonceWordH;
            aOrbiterF = RotL64((aOrbiterF * 4150613128885828229U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 12762214857389827271U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 2932451184340207695U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7513337346940091655U), 37U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 11062179998786293839U) + aNonceWordC;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 7919119215271524178U;
            aOrbiterC = RotL64((aOrbiterC * 9053677007180081359U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 1774988449597115155U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 3799792889466518953U) ^ aNonceWordD;
            aOrbiterK = RotL64((aOrbiterK * 17512791286490623455U), 21U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterC, 3U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + RotL64(aOrbiterF, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aPrevious, 39U) + RotL64(aOrbiterD, 47U)) + aOrbiterK) + RotL64(aCarry, 23U)) + aNonceWordJ);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 30U) + RotL64(aOrbiterF, 39U)) + aOrbiterK) + aNonceWordP);
            aWandererJ = aWandererJ + (((RotL64(aCross, 47U) + aOrbiterD) + RotL64(aOrbiterC, 11U)) + RotL64(aCarry, 47U));
            aWandererA = aWandererA ^ ((((RotL64(aScatter, 13U) + aOrbiterC) + RotL64(aOrbiterH, 20U)) + aNonceWordK) + aPhaseAWandererUpdateSaltD[((aIndex + 22U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterF, 3U)) + aOrbiterH) + aNonceWordO) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 34U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + RotL64(aWandererH, 5U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 17168U)) & S_BLOCK1], 6U) ^ RotL64(aInvestLaneA[((aIndex + 20681U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 20544U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 18322U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17411U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 19276U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aPrevious, 14U) ^ RotL64(aCarry, 27U)) + (RotL64(aCross, 53U) + RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterF = ((aWandererD + RotL64(aCross, 35U)) + RotL64(aCarry, 51U)) + 13880995121909552664U;
            aOrbiterH = ((((aWandererI + RotL64(aPrevious, 23U)) + RotL64(aCarry, 21U)) + 14534942818069300546U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordB;
            aOrbiterA = ((aWandererB + RotL64(aScatter, 5U)) + 17745973100886007133U) + aNonceWordF;
            aOrbiterE = (((aWandererK + RotL64(aIngress, 51U)) + RotL64(aCarry, 39U)) + 2249805580771946872U) + aNonceWordO;
            aOrbiterC = (((aWandererG + RotL64(aScatter, 14U)) + 4460116116396439410U) + aPhaseAOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1]) + aNonceWordP;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 3378683994078106878U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 3992996501048809123U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13273544260537223797U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 12057768808864451929U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 4115362079047921130U) ^ aNonceWordE;
            aOrbiterC = RotL64((aOrbiterC * 12263015903331031345U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 15297384955502206698U) + aNonceWordI;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 17623548383481905636U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7487278217901483685U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 3559213898000162417U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 12311605719074507335U) ^ aNonceWordJ;
            aOrbiterE = RotL64((aOrbiterE * 3982199462062847697U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 14807313864347885885U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 11222085523291581822U) ^ aNonceWordA;
            aOrbiterF = RotL64((aOrbiterF * 12580941911587215653U), 3U);
            //
            aIngress = RotL64(aOrbiterE, 36U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterF, 23U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aPrevious, 43U) + aOrbiterF) + RotL64(aOrbiterC, 43U)) + RotL64(aCarry, 13U)) + aNonceWordM);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 56U) + aOrbiterA) + RotL64(aOrbiterH, 57U)) + aPhaseAWandererUpdateSaltE[((aIndex + 10U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aIngress, 35U) + aOrbiterH) + RotL64(aOrbiterF, 5U)) + RotL64(aCarry, 53U)) + aNonceWordC);
            aWandererG = aWandererG ^ (((RotL64(aCross, 23U) + aOrbiterC) + RotL64(aOrbiterE, 29U)) + aNonceWordN);
            aWandererD = aWandererD + ((((RotL64(aScatter, 11U) + RotL64(aOrbiterE, 18U)) + aOrbiterH) + aNonceWordK) + aPhaseAWandererUpdateSaltC[((aIndex + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererG, 27U);
            aCarry = aCarry + RotL64(aIngress, 44U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 24043U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneA[((aIndex + 25688U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 22486U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 23478U)) & S_BLOCK1], 11U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 23178U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 22608U)) & S_BLOCK1], 38U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 4U) ^ RotL64(aCarry, 21U)) + (RotL64(aPrevious, 53U) ^ RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterK = (((aWandererF + RotL64(aScatter, 21U)) + RotL64(aCarry, 57U)) + 2558105147674438050U) + aNonceWordG;
            aOrbiterC = (((aWandererJ + RotL64(aPrevious, 11U)) + RotL64(aCarry, 27U)) + 15856662514774702561U) + aNonceWordO;
            aOrbiterI = (((aWandererB + RotL64(aIngress, 57U)) + RotL64(aCarry, 5U)) + 13346869226246584582U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = (((aWandererG + RotL64(aCross, 30U)) + 7632111846116243973U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordB;
            aOrbiterH = (aWandererK + RotL64(aScatter, 47U)) + 2102101361626976279U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 5605968705067851563U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 6842483186584326681U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11344798544990575365U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 5559797213819425064U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterF) ^ 12422313931331576759U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterK = RotL64((aOrbiterK * 7399849122565913401U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 2751024420047872601U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 11031320239359798610U) ^ aNonceWordJ;
            aOrbiterC = RotL64((aOrbiterC * 8607639453141148025U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 14366375309473793217U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 11971479429768505316U) ^ aNonceWordC;
            aOrbiterF = RotL64((aOrbiterF * 10063001532313098203U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 3947595951884469542U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 17882767922372770896U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3361906348965810211U), 41U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterH, 3U);
            aIngress = aIngress + (RotL64(aOrbiterF, 46U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterI, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterI, 43U)) + aOrbiterF);
            aWandererK = aWandererK + (((((RotL64(aPrevious, 60U) + aOrbiterK) + RotL64(aOrbiterC, 35U)) + RotL64(aCarry, 57U)) + aNonceWordA) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 51U) + aOrbiterH) + RotL64(aOrbiterI, 57U)) + aNonceWordM);
            aWandererF = aWandererF + (((((RotL64(aIngress, 35U) + aOrbiterF) + RotL64(aOrbiterK, 22U)) + RotL64(aCarry, 23U)) + aNonceWordI) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 43U) + aOrbiterC) + RotL64(aOrbiterF, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 29U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererF, 21U);
            aCarry = aCarry + RotL64(aIngress, 12U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 30412U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneA[((aIndex + 27756U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 27780U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30490U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 28599U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 27963U)) & S_BLOCK1], 34U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 37U) + RotL64(aCarry, 20U)) + (RotL64(aCross, 3U) ^ RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterK = (((aWandererJ + RotL64(aPrevious, 47U)) + RotL64(aCarry, 5U)) + 15383045568644941552U) + aNonceWordH;
            aOrbiterF = ((aWandererA + RotL64(aScatter, 21U)) + 17452811657750910067U) + aPhaseAOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = (((aWandererK + RotL64(aCross, 57U)) + RotL64(aCarry, 21U)) + 15660117718455155603U) + aPhaseAOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = ((aWandererF + RotL64(aIngress, 11U)) + RotL64(aCarry, 41U)) + 10396441207743665753U;
            aOrbiterD = ((aWandererC + RotL64(aScatter, 30U)) + 3708971058200841442U) + aNonceWordO;
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 7000673057768598750U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 9886354469011131596U;
            aOrbiterG = RotL64((aOrbiterG * 296615166652808759U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 16018065329058043467U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterA) ^ 5024756166109352320U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterF = RotL64((aOrbiterF * 11660932185479046483U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 6587818720728886652U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 3652672354944162319U;
            aOrbiterD = RotL64((aOrbiterD * 10807121230791716109U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 6307315649915348048U) + aNonceWordB;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 16405347331742979258U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7183142442906743699U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 5427299664054601957U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 4983381733483185898U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14646556236306407673U), 11U);
            //
            aIngress = RotL64(aOrbiterK, 57U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 37U));
            aIngress = aIngress + RotL64(aOrbiterD, 26U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aPrevious, 29U) + aOrbiterA) + RotL64(aOrbiterF, 58U)) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 51U) + aOrbiterD) + RotL64(aOrbiterK, 35U));
            aWandererC = aWandererC + ((((RotL64(aScatter, 20U) + RotL64(aOrbiterF, 47U)) + aOrbiterD) + RotL64(aCarry, 53U)) + aNonceWordC);
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 5U) + aOrbiterG) + RotL64(aOrbiterK, 3U)) + aNonceWordK) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 39U) + aOrbiterF) + RotL64(aOrbiterK, 13U)) + RotL64(aCarry, 5U)) + aNonceWordN);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererJ, 3U);
            aCarry = aCarry + RotL64(aIngress, 54U);
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

void TwistExpander_WaterPolo_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xAE9C09A50688DEA9ULL + 0xB10AE1C96A4E8C33ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xF9CCBBC147405259ULL + 0xA41CBB93AABAD34EULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xFAA1213640469F71ULL + 0xDB9739A96A27EF55ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xD31D5A115BF189BFULL + 0xAF9E80523617A5DBULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xFE396DFBBED0C037ULL + 0xFD9CC587C2FCCD5FULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xE5FBD3E8CE4AEFC9ULL + 0xC2259A044BC16DEDULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xA4CDBD36C010C5CFULL + 0x85CD25265DC71120ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xBABCF78560853089ULL + 0xF7D320FA4395CC83ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xE52C425D2D0E098BULL + 0xD2B339024169B945ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x8A97CF49FC7B10F9ULL + 0x864EBD2DB221BBFDULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xFA25F32AA7EC8B79ULL + 0x90D8400E263FE473ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xE92519E768CC7383ULL + 0x9E86A5C770BCA0CAULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xC75FA4B844AB0561ULL + 0xCEB795F28C2B5B2AULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xE68E9D875A3DBB27ULL + 0xDAC0AB2E722083ACULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x8DBC43A4ECE422BBULL + 0xDF5A339D9E5A25C6ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xE550F98E71BD6F25ULL + 0xEAC8913173E87CE4ULL);
    // GSeedRunSeed_C seed_loop_b (start)
    {
        // GSeedRunSeed_C seed_loop_b lane group
        // read from: aOperationLaneA, aOperationLaneB, aExpandLaneC, aOperationLaneC, aOperationLaneD, aExpandLaneD, aInvestLaneC, aExpandLaneA, aFireLaneB, aInvestLaneD, aExpandLaneB, aWorkLaneA, aFireLaneA, aWorkLaneB, aFireLaneD, aWorkLaneC, aFireLaneC
        // write to: aInvestLaneC, aInvestLaneD, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // seed_loop_b loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aExpandLaneC
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aExpandLaneC forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aExpandLaneD
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 445U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneB[((aIndex + 194U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 5379U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 2280U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 2484U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aExpandLaneD[((aIndex + 5183U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCarry, 36U)) + (RotL64(aPrevious, 53U) ^ RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterD = (aWandererJ + RotL64(aCross, 39U)) + 9751314027302668907U;
            aOrbiterK = ((aWandererB + RotL64(aIngress, 53U)) + RotL64(aCarry, 47U)) + 12175450995523107056U;
            aOrbiterI = ((aWandererG + RotL64(aPrevious, 47U)) + 17519694958730119552U) + aNonceWordC;
            aOrbiterH = ((aWandererF + RotL64(aScatter, 14U)) + 9093525527925682263U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = ((aWandererA + RotL64(aIngress, 43U)) + 3713831321786810138U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = (((aWandererC + RotL64(aPrevious, 21U)) + RotL64(aCarry, 57U)) + 10108355209191835040U) + aNonceWordK;
            aOrbiterB = ((aWandererE + RotL64(aScatter, 5U)) + 12956307447311314768U) + aNonceWordG;
            aOrbiterJ = (((aWandererD + RotL64(aCross, 26U)) + RotL64(aCarry, 37U)) + 1904298513945877359U) + aNonceWordE;
            aOrbiterE = (aWandererH + RotL64(aScatter, 57U)) + 4658049993308574460U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 9826333658248851902U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 12058666914724365134U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 964233873188373939U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 2516574707110528099U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 13335308331049750235U) ^ aNonceWordN;
            aOrbiterC = RotL64((aOrbiterC * 5880227828760598587U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 8230749255538495304U) + aNonceWordD;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 16536559486797811486U;
            aOrbiterH = RotL64((aOrbiterH * 7097036838156464969U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 12387639130570188998U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 8459259798142872020U) ^ aNonceWordO;
            aOrbiterB = RotL64((aOrbiterB * 8001346480955847013U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 16083784052002800300U) + aNonceWordP;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 1957284290736468379U;
            aOrbiterJ = RotL64((aOrbiterJ * 5046501301740813065U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 7349538179311335863U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 16395170077006105258U;
            aOrbiterG = RotL64((aOrbiterG * 4230485452156662763U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 3317652065873784068U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 5517155804799120700U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9789270651974719183U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 5568525912112200094U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 9334250662962319598U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5034887614541768961U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 5641394627075994165U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 13524971148931512745U;
            aOrbiterK = RotL64((aOrbiterK * 3699457147759854357U), 21U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterC, 58U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 5U));
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 23U));
            aIngress = aIngress + RotL64(aOrbiterJ, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 37U) + aOrbiterI) + RotL64(aOrbiterD, 60U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 53U) + aOrbiterI) + RotL64(aOrbiterH, 11U));
            aWandererJ = aWandererJ ^ ((((RotL64(aScatter, 48U) + RotL64(aOrbiterK, 43U)) + aOrbiterD) + aNonceWordL) + aPhaseBWandererUpdateSaltE[((aIndex + 14U)) & S_SALT1]);
            aWandererB = aWandererB + (((((RotL64(aIngress, 41U) + RotL64(aOrbiterJ, 37U)) + aOrbiterB) + RotL64(aCarry, 23U)) + aNonceWordI) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 19U) + aOrbiterH) + RotL64(aOrbiterE, 47U)) + aNonceWordB);
            aWandererE = aWandererE + ((RotL64(aIngress, 13U) + RotL64(aOrbiterE, 3U)) + aOrbiterG);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 29U) + aOrbiterB) + RotL64(aOrbiterD, 27U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 4U) + RotL64(aOrbiterI, 56U)) + aOrbiterG) + RotL64(aCarry, 35U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 57U) + aOrbiterD) + RotL64(aOrbiterC, 21U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + (RotL64(aWandererG, 51U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + (RotL64(aWandererA, 58U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererD, 35U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aInvestLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 2
        // ingress from: aInvestLaneC, aOperationLaneC, aOperationLaneD, aExpandLaneA
        // ingress directions: aInvestLaneC forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aExpandLaneA forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aFireLaneB
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aFireLaneB backward/forward random
        // write to: aInvestLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneC[((aIndex + 10363U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneC[((aIndex + 5882U)) & S_BLOCK1], 13U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 7870U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneA[((aIndex + 5538U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 8796U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 9101U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 7600U)) & S_BLOCK1], 46U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCross, 47U) + RotL64(aIngress, 10U)) + (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterI = ((aWandererA + RotL64(aIngress, 4U)) + 785861751704720606U) + aNonceWordO;
            aOrbiterJ = (aWandererF + RotL64(aScatter, 13U)) + 15968088718435606299U;
            aOrbiterB = (((aWandererB + RotL64(aPrevious, 19U)) + RotL64(aCarry, 3U)) + 1393976526590347151U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = ((aWandererE + RotL64(aCross, 57U)) + 17240750947292745884U) + aNonceWordB;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 48U)) + 4921576136163183137U) + aNonceWordM;
            aOrbiterA = (aWandererD + RotL64(aCross, 43U)) + 3334047873553153032U;
            aOrbiterH = (aWandererG + RotL64(aScatter, 37U)) + 15086509978458408698U;
            aOrbiterD = (((aWandererK + RotL64(aIngress, 53U)) + RotL64(aCarry, 37U)) + 892391205397581998U) + aNonceWordP;
            aOrbiterC = (((aWandererH + RotL64(aScatter, 27U)) + RotL64(aCarry, 11U)) + 2965686403183767521U) + aPhaseBOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 14632215393655706170U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 15740589515342377322U;
            aOrbiterB = RotL64((aOrbiterB * 15677716942904794913U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 11131164813943086445U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 6988080581278900960U;
            aOrbiterA = RotL64((aOrbiterA * 6412189142344044255U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 16021254613117657178U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 6183615599897921154U;
            aOrbiterJ = RotL64((aOrbiterJ * 9976411093264211033U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 12533992547026652747U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 3104325358982904219U;
            aOrbiterG = RotL64((aOrbiterG * 14977348108778147265U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 3878525937957474644U) + aNonceWordJ;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 2120435259884368445U;
            aOrbiterF = RotL64((aOrbiterF * 15964718652193073177U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 14928658302694194856U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 9121310461310309348U;
            aOrbiterD = RotL64((aOrbiterD * 17304439784647477491U), 3U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterC) + 3715693239100476493U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1]) + aNonceWordI;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 7336577492932262490U;
            aOrbiterH = RotL64((aOrbiterH * 11074754160002665253U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 2312452827448455675U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 4322756069651934618U;
            aOrbiterC = RotL64((aOrbiterC * 6908893297397073539U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 4962079617577705818U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 5072727464750706525U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4947670001221089155U), 51U);
            //
            aIngress = RotL64(aOrbiterJ, 57U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterA, 36U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterC, 47U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 53U));
            aIngress = aIngress + RotL64(aOrbiterG, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterH, 13U)) + aOrbiterA) + RotL64(aCarry, 51U)) + aNonceWordC);
            aWandererE = aWandererE ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterI, 18U)) + aOrbiterF);
            aWandererF = aWandererF + (((RotL64(aScatter, 35U) + RotL64(aOrbiterG, 5U)) + aOrbiterC) + RotL64(aCarry, 39U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 58U) + aOrbiterF) + RotL64(aOrbiterG, 23U)) + aPhaseBWandererUpdateSaltA[((aIndex + 28U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 5U) + aOrbiterJ) + RotL64(aOrbiterA, 47U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 39U) + aOrbiterH) + RotL64(aOrbiterB, 41U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aIngress, 29U) + RotL64(aOrbiterF, 34U)) + aOrbiterC);
            aWandererA = aWandererA ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterC, 27U)) + aOrbiterD) + aNonceWordE);
            aWandererH = aWandererH + (((RotL64(aScatter, 48U) + aOrbiterH) + RotL64(aOrbiterG, 57U)) + aNonceWordH);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 41U));
            aCarry = aCarry + (RotL64(aWandererG, 24U) ^ aWandererH);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + RotL64(aWandererD, 35U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aInvestLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_b loop 3
        // ingress from: aInvestLaneD, aOperationLaneA, aExpandLaneB
        // ingress directions: aInvestLaneD forward forced, aOperationLaneA forward forced, aExpandLaneB forward/backward random
        // cross from: aInvestLaneC, aOperationLaneC
        // cross directions: aInvestLaneC backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneD[((aIndex + 12940U)) & S_BLOCK1], 44U) ^ RotL64(aOperationLaneA[((aIndex + 11835U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 14819U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 13065U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneC[((aIndex + 11197U)) & S_BLOCK1], 54U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aIngress, 39U)) ^ (RotL64(aCarry, 11U) + RotL64(aPrevious, 26U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterK = (aWandererA + RotL64(aScatter, 41U)) + 6342299552323486695U;
            aOrbiterH = ((aWandererG + RotL64(aIngress, 54U)) + 12692748514781367538U) + aNonceWordG;
            aOrbiterD = ((aWandererH + RotL64(aCross, 29U)) + RotL64(aCarry, 5U)) + 8202639945493229155U;
            aOrbiterF = (((aWandererD + RotL64(aPrevious, 23U)) + RotL64(aCarry, 43U)) + 4439975701793231639U) + aPhaseBOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = (aWandererB + RotL64(aCross, 13U)) + 16774235182859553759U;
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 37U)) + 8764155413335405667U) + aNonceWordJ;
            aOrbiterG = (((aWandererK + RotL64(aScatter, 47U)) + RotL64(aCarry, 57U)) + 7167848811974967685U) + aNonceWordL;
            aOrbiterB = (aWandererF + RotL64(aIngress, 19U)) + 16768278912125334220U;
            aOrbiterA = ((aWandererI + RotL64(aCross, 60U)) + 9090838954826296201U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 7644075729758006298U) + aNonceWordF;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 17326182797908071215U;
            aOrbiterD = RotL64((aOrbiterD * 2408330168749256075U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 16158809721888137555U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 8029938783858263694U;
            aOrbiterH = RotL64((aOrbiterH * 12628072435324195483U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 8716553521415553404U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 7012599977009208840U;
            aOrbiterG = RotL64((aOrbiterG * 8775355876188948851U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 13250558696578541499U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 13705957059101025396U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16889495686487056367U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 2796775206291902461U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterB) ^ 13741676263512390669U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterK = RotL64((aOrbiterK * 10455782033465595947U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 1691908360612389252U) + aNonceWordD;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 4114939415206031540U;
            aOrbiterF = RotL64((aOrbiterF * 2797401802892718297U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 2374911514440738727U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 12377616933668803091U;
            aOrbiterI = RotL64((aOrbiterI * 2505164835116651215U), 35U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterA) + 681094033415259645U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1]) + aNonceWordC;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 13841322124900463362U;
            aOrbiterB = RotL64((aOrbiterB * 4210414203856902329U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 18082983557580381338U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 15731122225678626778U;
            aOrbiterA = RotL64((aOrbiterA * 7785999919955613789U), 53U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterC, 10U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + (RotL64(aOrbiterA, 19U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterG, 27U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterF, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aPrevious, 5U) + aOrbiterB) + RotL64(aOrbiterC, 6U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterK, 43U)) + aOrbiterC);
            aWandererK = aWandererK + ((RotL64(aCross, 44U) + RotL64(aOrbiterK, 19U)) + aOrbiterD);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterD, 47U)) + aOrbiterC) + aNonceWordK);
            aWandererB = aWandererB + ((((RotL64(aIngress, 39U) + aOrbiterG) + RotL64(aOrbiterA, 23U)) + RotL64(aCarry, 57U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 35U) + aOrbiterH) + RotL64(aOrbiterI, 37U));
            aWandererD = aWandererD + (((((RotL64(aPrevious, 53U) + aOrbiterI) + RotL64(aOrbiterG, 13U)) + RotL64(aCarry, 37U)) + aNonceWordP) + aPhaseBWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 60U) + aOrbiterF) + RotL64(aOrbiterI, 29U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterF, 58U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + (RotL64(aWandererK, 6U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererB, 57U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 20386U)) & S_BLOCK1], 51U) ^ RotL64(aInvestLaneC[((aIndex + 21755U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 20842U)) & S_BLOCK1], 38U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 16530U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 20147U)) & S_BLOCK1], 28U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCarry, 11U)) + (RotL64(aCross, 57U) ^ RotL64(aIngress, 44U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterH = (aWandererI + RotL64(aCross, 10U)) + 5568146815535263910U;
            aOrbiterE = (((aWandererK + RotL64(aPrevious, 27U)) + RotL64(aCarry, 11U)) + 7736084960873834666U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = (((aWandererG + RotL64(aScatter, 47U)) + RotL64(aCarry, 3U)) + 1336413621817562093U) + aNonceWordK;
            aOrbiterB = (aWandererE + RotL64(aIngress, 23U)) + 5218462026934984692U;
            aOrbiterC = (aWandererJ + RotL64(aPrevious, 43U)) + 7048890985969555935U;
            aOrbiterF = ((aWandererD + RotL64(aScatter, 34U)) + 13415955213864702118U) + aNonceWordC;
            aOrbiterG = (((aWandererB + RotL64(aIngress, 53U)) + RotL64(aCarry, 43U)) + 5657023257021528548U) + aPhaseBOrbiterAssignSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = (aWandererA + RotL64(aCross, 19U)) + 14338310943137497116U;
            aOrbiterJ = (aWandererH + RotL64(aPrevious, 57U)) + 12305161641833950473U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 14514226578370459131U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 12692904083266024340U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14800805065279908839U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 11012959130001327964U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 7106471380403489078U;
            aOrbiterE = RotL64((aOrbiterE * 515626559384817223U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 3718101961355280891U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 13364192077222322664U;
            aOrbiterG = RotL64((aOrbiterG * 1411328915372590283U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 6720867800318913440U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 14497243926965866546U;
            aOrbiterJ = RotL64((aOrbiterJ * 13595058589060114653U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 5789056168233262435U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 14438482587495779937U;
            aOrbiterH = RotL64((aOrbiterH * 10593535547917767263U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 313917798940179945U) + aNonceWordE;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 15241845511889502917U) ^ aNonceWordP;
            aOrbiterC = RotL64((aOrbiterC * 16483477103771326107U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 3591957424821693032U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 1559050939014453558U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17933346117866604725U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 15340590914441451383U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 5538037287390050110U) ^ aNonceWordO;
            aOrbiterA = RotL64((aOrbiterA * 4082576643144951473U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 4151270491894969214U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 263593701314144898U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10372046955804512457U), 13U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterA, 11U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 22U));
            aIngress = aIngress + (RotL64(aOrbiterC, 19U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 5U));
            aIngress = aIngress + RotL64(aOrbiterG, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aCross, 5U) + aOrbiterF) + RotL64(aOrbiterE, 54U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 12U) + RotL64(aOrbiterC, 11U)) + aOrbiterH) + aNonceWordI);
            aWandererA = aWandererA + ((RotL64(aScatter, 41U) + aOrbiterE) + RotL64(aOrbiterC, 43U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 27U) + aOrbiterC) + RotL64(aOrbiterB, 23U));
            aWandererE = aWandererE + ((((RotL64(aPrevious, 35U) + aOrbiterI) + RotL64(aOrbiterH, 39U)) + RotL64(aCarry, 39U)) + aPhaseBWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 23U) + aOrbiterA) + RotL64(aOrbiterH, 6U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 47U) + RotL64(aOrbiterA, 27U)) + aOrbiterI) + RotL64(aCarry, 19U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 19U) + aOrbiterF) + RotL64(aOrbiterJ, 47U)) + aNonceWordM);
            aWandererH = aWandererH + (((RotL64(aPrevious, 52U) + RotL64(aOrbiterB, 19U)) + aOrbiterG) + aPhaseBWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + (RotL64(aWandererJ, 37U) ^ aWandererA);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 41U));
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererB, 4U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 25918U)) & S_BLOCK1], 48U) ^ RotL64(aInvestLaneD[((aIndex + 24420U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 25048U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22467U)) & S_BLOCK1], 29U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 22855U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aPrevious, 26U) + RotL64(aCross, 39U)) + (RotL64(aCarry, 51U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterH = (((aWandererB + RotL64(aIngress, 53U)) + RotL64(aCarry, 41U)) + 966899917801652720U) + aNonceWordI;
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 57U)) + 10996327672320748649U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = (aWandererH + RotL64(aScatter, 47U)) + 4188171566846621107U;
            aOrbiterA = ((aWandererI + RotL64(aCross, 28U)) + RotL64(aCarry, 3U)) + 5886209243097387959U;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 13U)) + RotL64(aCarry, 11U)) + 14940428957136728111U;
            aOrbiterB = ((aWandererE + RotL64(aCross, 39U)) + 179187285531914832U) + aNonceWordG;
            aOrbiterC = ((aWandererK + RotL64(aIngress, 43U)) + 6685351948936817752U) + aNonceWordO;
            aOrbiterI = ((aWandererG + RotL64(aScatter, 34U)) + 1894506461704029700U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = (aWandererA + RotL64(aPrevious, 23U)) + 4182760368636977082U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 12523318028514940790U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 5059306166973366892U;
            aOrbiterD = RotL64((aOrbiterD * 2857409765717296483U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 5890872367917643851U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 17747338389865221534U;
            aOrbiterK = RotL64((aOrbiterK * 5306740664798049267U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 13906227834259884100U) + aNonceWordA;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 7152105382899756368U;
            aOrbiterH = RotL64((aOrbiterH * 6772157117358310485U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 17868101884759619240U) + aNonceWordP;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 11758843266314148347U;
            aOrbiterA = RotL64((aOrbiterA * 5919135169337501485U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 13950566197090324859U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 17278105609930477854U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11431842718945107359U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 9556785965646738355U) + aNonceWordC;
            aOrbiterF = (((aOrbiterF ^ aOrbiterC) ^ 841298436857932987U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterF = RotL64((aOrbiterF * 15077843186688841797U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 1951515285492133830U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 15775839819330588437U;
            aOrbiterC = RotL64((aOrbiterC * 7902654031401620995U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 5585458468816495436U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 17258586689032223623U;
            aOrbiterJ = RotL64((aOrbiterJ * 1652050227399194271U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 5254132659445988836U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 15440741734777060925U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17445581079035134067U), 47U);
            //
            aIngress = RotL64(aOrbiterD, 44U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 19U));
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 23U));
            aIngress = aIngress + RotL64(aOrbiterH, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterB, 5U)) + aOrbiterC);
            aWandererH = aWandererH + ((((RotL64(aScatter, 23U) + RotL64(aOrbiterI, 43U)) + aOrbiterJ) + RotL64(aCarry, 53U)) + aNonceWordN);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 4U) + RotL64(aOrbiterI, 35U)) + aOrbiterD) + aPhaseBWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 11U) + aOrbiterH) + RotL64(aOrbiterA, 19U)) + RotL64(aCarry, 39U)) + aNonceWordK);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterF, 30U)) + aOrbiterH);
            aWandererA = aWandererA + (((RotL64(aCross, 51U) + RotL64(aOrbiterB, 53U)) + aOrbiterD) + aPhaseBWandererUpdateSaltB[((aIndex + 14U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 39U) + RotL64(aOrbiterK, 57U)) + aOrbiterB) + aNonceWordM);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 60U) + aOrbiterC) + RotL64(aOrbiterK, 23U)) + aNonceWordF);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterA, 14U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 60U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererH, 10U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 6
        // ingress from: aWorkLaneC, aWorkLaneA, aFireLaneC
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aFireLaneC forward/backward random
        // cross from: aWorkLaneB, aOperationLaneB
        // cross directions: aWorkLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 29212U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((aIndex + 29376U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 27740U)) & S_BLOCK1], 28U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30159U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneB[((aIndex + 31768U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 3U) ^ RotL64(aIngress, 54U)) ^ (RotL64(aPrevious, 21U) + RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterE = (aWandererI + RotL64(aPrevious, 13U)) + 5576732410244514238U;
            aOrbiterH = ((aWandererD + RotL64(aScatter, 35U)) + 2833808925935929629U) + aNonceWordI;
            aOrbiterB = ((aWandererA + RotL64(aIngress, 24U)) + RotL64(aCarry, 13U)) + 3670188682914544792U;
            aOrbiterG = (aWandererJ + RotL64(aCross, 3U)) + 15759072378887814995U;
            aOrbiterD = (aWandererG + RotL64(aScatter, 19U)) + 13934007231137439994U;
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 53U)) + RotL64(aCarry, 37U)) + 11022225696007690512U;
            aOrbiterI = (((aWandererH + RotL64(aCross, 57U)) + RotL64(aCarry, 53U)) + 16989177104453635790U) + aPhaseBOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 47U)) + 9256930045263527091U) + aNonceWordM;
            aOrbiterK = (((aWandererB + RotL64(aPrevious, 30U)) + 17788596104417068290U) + aPhaseBOrbiterAssignSaltE[((aIndex + 20U)) & S_SALT1]) + aNonceWordD;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 17044369456673337625U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = (((aOrbiterB ^ aOrbiterE) ^ 1310908395523250343U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterB = RotL64((aOrbiterB * 16305084373037705921U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 12067065689034065422U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 15130844248737512262U) ^ aNonceWordH;
            aOrbiterD = RotL64((aOrbiterD * 9409499577465934107U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 14532689204495587494U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 8198147292120244178U;
            aOrbiterI = RotL64((aOrbiterI * 1418356389507740991U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 5485494458627163347U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 10830008207150307611U;
            aOrbiterJ = RotL64((aOrbiterJ * 6526039534042499457U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 17770065502486618029U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 6397859353395335459U;
            aOrbiterE = RotL64((aOrbiterE * 14286997752368893825U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 5128700697381508319U) + aNonceWordA;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 7103394110057060499U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5053680689949149633U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 16024401282261796979U) + aNonceWordO;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 12818445221897253410U;
            aOrbiterK = RotL64((aOrbiterK * 11450004517784155405U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 13386978409145916350U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 16740821954556699503U;
            aOrbiterA = RotL64((aOrbiterA * 5376430209628515105U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 313978038530994953U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 1355733685461795345U;
            aOrbiterH = RotL64((aOrbiterH * 15955927322082619735U), 27U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterE, 21U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 40U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 57U));
            aIngress = aIngress + (RotL64(aOrbiterH, 37U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterD, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterB, 11U)) + aOrbiterH) + aNonceWordP);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 51U) + aOrbiterA) + RotL64(aOrbiterG, 27U)) + aNonceWordE);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 5U) + aOrbiterG) + RotL64(aOrbiterD, 37U)) + aNonceWordF);
            aWandererA = aWandererA + (((RotL64(aCross, 24U) + RotL64(aOrbiterE, 54U)) + aOrbiterA) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 47U) + aOrbiterA) + RotL64(aOrbiterH, 19U));
            aWandererE = aWandererE + ((((RotL64(aIngress, 43U) + aOrbiterH) + RotL64(aOrbiterJ, 23U)) + RotL64(aCarry, 53U)) + aPhaseBWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterJ, 41U)) + aOrbiterE);
            aWandererB = aWandererB + (((RotL64(aCross, 56U) + RotL64(aOrbiterG, 47U)) + aOrbiterI) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 39U) + RotL64(aOrbiterK, 58U)) + aOrbiterI) + aNonceWordJ);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 21U));
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererJ, 26U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererH, 53U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererB, 5U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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

void TwistExpander_WaterPolo_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x9EE8A7FFEB528E99ULL + 0xC597E126A73401A1ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x998C1C2AA1716D51ULL + 0xE03FD43F48665C02ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xCD76C39396A0BE41ULL + 0xFFA729BAD74AE435ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xB770CC8A4AF28BABULL + 0xBB441B7B63C83261ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x8B0F7112167CF97BULL + 0x8806D69BA9AFCBCEULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xF9DAA49EBD947965ULL + 0xFAE95E0ABA361E95ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x9BF3D23A4BEB1AA1ULL + 0xE337073028F7684BULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xFADB42AEE195F031ULL + 0xDCC6179B537BFCF7ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x8B43B9462FE35F35ULL + 0x941E328F1FBD3A08ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x901EDA8F93FDF1E7ULL + 0xF0EC6BFE7D0E2FD2ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xEB0E64780A30259BULL + 0xA4F0C7DEEA44C540ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xF0B51D33E2429EC9ULL + 0xBF6121F32C3B2462ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x8D367C74CACD91A9ULL + 0xBA508FAB72DFD21BULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xDCC9775540F40C1DULL + 0xCAE4D8463FD12580ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xE97F5FA36D460691ULL + 0xCFE350A9A6F148A0ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xA57CC0C91367F035ULL + 0xCCF7E9A9FD0AAD9DULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 4314U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneB[((aIndex + 3375U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 5306U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1757U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 3778U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 4923U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 41U)) ^ (RotL64(aCross, 57U) + RotL64(aIngress, 20U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 21U)) + 13880995121909552664U;
            aOrbiterK = (aWandererI + RotL64(aCross, 36U)) + 14534942818069300546U;
            aOrbiterD = ((aWandererK + RotL64(aScatter, 11U)) + 17745973100886007133U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = (((aWandererB + RotL64(aIngress, 27U)) + RotL64(aCarry, 19U)) + 2249805580771946872U) + aNonceWordB;
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 47U)) + RotL64(aCarry, 5U)) + 4460116116396439410U;
            aOrbiterF = ((aWandererG + RotL64(aScatter, 57U)) + RotL64(aCarry, 53U)) + 3378683994078106878U;
            aOrbiterG = (((aWandererH + RotL64(aIngress, 5U)) + 3992996501048809123U) + aPhaseDOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1]) + aNonceWordE;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 12057768808864451929U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 4115362079047921130U;
            aOrbiterD = RotL64((aOrbiterD * 12263015903331031345U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 15297384955502206698U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 17623548383481905636U;
            aOrbiterA = RotL64((aOrbiterA * 7487278217901483685U), 51U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterD) + 3559213898000162417U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1]) + aNonceWordC;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 12311605719074507335U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3982199462062847697U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 14807313864347885885U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 11222085523291581822U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12580941911587215653U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 916681229436292462U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 2441350114032314686U;
            aOrbiterJ = RotL64((aOrbiterJ * 7336079498999018067U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 7361470539894653271U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 12153585147213579808U;
            aOrbiterK = RotL64((aOrbiterK * 3040327545467672961U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 13566300726101613579U) + aNonceWordD;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 14875254144748509128U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13699179902908972403U), 11U);
            //
            aIngress = RotL64(aOrbiterA, 51U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 13U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 37U));
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aScatter, 58U) + aOrbiterB) + RotL64(aOrbiterK, 13U)) + aNonceWordM);
            aWandererH = aWandererH + (((RotL64(aIngress, 5U) + RotL64(aOrbiterG, 57U)) + aOrbiterA) + RotL64(aCarry, 21U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterD, 20U)) + aOrbiterJ) + aNonceWordH);
            aWandererE = aWandererE + ((RotL64(aCross, 13U) + aOrbiterG) + RotL64(aOrbiterK, 43U));
            aWandererF = aWandererF ^ ((((RotL64(aPrevious, 21U) + RotL64(aOrbiterJ, 37U)) + aOrbiterK) + aNonceWordL) + aPhaseDWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aCross, 35U) + aOrbiterJ) + RotL64(aOrbiterF, 5U)) + RotL64(aCarry, 37U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterG, 27U)) + aOrbiterF) + aNonceWordJ);
            //
            aCarry = aCarry + (RotL64(aWandererI, 50U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererB, 23U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 7988U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneC[((aIndex + 9731U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 6168U)) & S_BLOCK1], 37U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 8429U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 8012U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 7268U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 9660U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCross, 38U)) ^ (RotL64(aIngress, 5U) ^ RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterB = ((aWandererA + RotL64(aCross, 21U)) + 12222235191147985484U) + aNonceWordL;
            aOrbiterE = (((aWandererI + RotL64(aIngress, 57U)) + RotL64(aCarry, 39U)) + 16367317014523328414U) + aNonceWordF;
            aOrbiterK = (aWandererG + RotL64(aPrevious, 37U)) + 3511378091284703789U;
            aOrbiterH = (aWandererC + RotL64(aScatter, 43U)) + 15247492830966725949U;
            aOrbiterD = (((aWandererB + RotL64(aIngress, 3U)) + 7745995913390407897U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordA;
            aOrbiterG = ((aWandererK + RotL64(aCross, 51U)) + RotL64(aCarry, 21U)) + 6463593307540108810U;
            aOrbiterJ = (((aWandererH + RotL64(aScatter, 28U)) + RotL64(aCarry, 53U)) + 1101669311005268630U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 12988052764067518580U) + aNonceWordO;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 17717179747434679772U;
            aOrbiterK = RotL64((aOrbiterK * 10820310705487638793U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 11662190906682400416U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 6563014073547628748U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16967910471722117761U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 13099094932059419219U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 16342730862261868847U;
            aOrbiterD = RotL64((aOrbiterD * 10988124108686164829U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 16855346813127524624U) + aNonceWordB;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 6570063128502306944U;
            aOrbiterH = RotL64((aOrbiterH * 4571570049463124831U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 11328352033809240501U) + aNonceWordD;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 11640986648833160901U;
            aOrbiterG = RotL64((aOrbiterG * 2895830492089678919U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 2675226158571501666U) + aNonceWordP;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 17700531248266458165U;
            aOrbiterJ = RotL64((aOrbiterJ * 2231403813970188657U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 7729597396731910874U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 15172374484412053756U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 149009041406406517U), 29U);
            //
            aIngress = RotL64(aOrbiterH, 27U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 5U));
            aIngress = aIngress + RotL64(aOrbiterD, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aIngress, 35U) + aOrbiterK) + RotL64(aOrbiterJ, 5U)) + RotL64(aCarry, 11U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 51U) + aOrbiterG) + RotL64(aOrbiterD, 43U)) + aPhaseDWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 19U) + RotL64(aOrbiterD, 21U)) + aOrbiterK) + RotL64(aCarry, 43U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterD, 11U)) + aOrbiterB);
            aWandererB = aWandererB + ((((RotL64(aIngress, 57U) + aOrbiterH) + RotL64(aOrbiterD, 52U)) + aNonceWordN) + aPhaseDWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 42U) + RotL64(aOrbiterE, 27U)) + aOrbiterG) + aNonceWordC);
            aWandererI = aWandererI + ((RotL64(aScatter, 3U) + RotL64(aOrbiterE, 37U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererG, 54U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 39U);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 12726U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneA[((aIndex + 12994U)) & S_BLOCK1], 42U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 14914U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 11799U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneC[((aIndex + 11020U)) & S_BLOCK1], 34U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCarry, 24U) ^ RotL64(aPrevious, 41U)) + (RotL64(aIngress, 11U) + RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterH = (((aWandererK + RotL64(aScatter, 35U)) + RotL64(aCarry, 21U)) + 5576732410244514238U) + aNonceWordK;
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 12U)) + 2833808925935929629U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterF = ((aWandererJ + RotL64(aCross, 53U)) + RotL64(aCarry, 35U)) + 3670188682914544792U;
            aOrbiterC = (aWandererA + RotL64(aIngress, 41U)) + 15759072378887814995U;
            aOrbiterG = ((aWandererD + RotL64(aCross, 29U)) + 13934007231137439994U) + aNonceWordP;
            aOrbiterE = (((aWandererE + RotL64(aIngress, 47U)) + RotL64(aCarry, 57U)) + 11022225696007690512U) + aNonceWordB;
            aOrbiterB = (((aWandererC + RotL64(aPrevious, 19U)) + 16989177104453635790U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordI;
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 9256930045263527091U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 17788596104417068290U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 675554110563253305U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 17044369456673337625U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 1310908395523250343U;
            aOrbiterJ = RotL64((aOrbiterJ * 16305084373037705921U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 12067065689034065422U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 15130844248737512262U;
            aOrbiterH = RotL64((aOrbiterH * 9409499577465934107U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 14532689204495587494U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterC = (((aOrbiterC ^ aOrbiterE) ^ 8198147292120244178U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterC = RotL64((aOrbiterC * 1418356389507740991U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 5485494458627163347U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 10830008207150307611U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6526039534042499457U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 17770065502486618029U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 6397859353395335459U) ^ aNonceWordF;
            aOrbiterG = RotL64((aOrbiterG * 14286997752368893825U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 5128700697381508319U) + aNonceWordC;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 7103394110057060499U;
            aOrbiterB = RotL64((aOrbiterB * 5053680689949149633U), 13U);
            //
            aIngress = RotL64(aOrbiterB, 42U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 5U));
            aIngress = aIngress + RotL64(aOrbiterC, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 21U) + RotL64(aOrbiterJ, 35U)) + aOrbiterH) + RotL64(aCarry, 41U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 3U) + aOrbiterH) + RotL64(aOrbiterC, 57U)) + aNonceWordJ);
            aWandererD = aWandererD + ((((RotL64(aCross, 51U) + RotL64(aOrbiterJ, 11U)) + aOrbiterF) + RotL64(aCarry, 53U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterH, 5U)) + aOrbiterG) + aNonceWordG);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterE, 28U)) + aOrbiterC) + aNonceWordO) + aPhaseDWandererUpdateSaltC[((aIndex + 8U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 58U) + aOrbiterH) + RotL64(aOrbiterF, 21U)) + aNonceWordL);
            aWandererJ = aWandererJ + ((RotL64(aCross, 37U) + RotL64(aOrbiterF, 47U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererA);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererE, 4U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 17419U)) & S_BLOCK1], 13U) ^ RotL64(aSnowLaneA[((aIndex + 16527U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 17914U)) & S_BLOCK1], 60U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 16561U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneD[((aIndex + 16546U)) & S_BLOCK1], 30U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 38U) + RotL64(aCarry, 19U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 23U)) + 4384716820085860551U) + aNonceWordO;
            aOrbiterF = ((aWandererH + RotL64(aScatter, 35U)) + RotL64(aCarry, 3U)) + 9715780315942116888U;
            aOrbiterI = (((aWandererE + RotL64(aPrevious, 29U)) + RotL64(aCarry, 47U)) + 15963520052789178632U) + aPhaseDOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = (aWandererF + RotL64(aCross, 13U)) + 14346700690686392938U;
            aOrbiterJ = (((aWandererB + RotL64(aScatter, 56U)) + 6005518012489966643U) + aPhaseDOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1]) + aNonceWordH;
            aOrbiterE = (aWandererA + RotL64(aPrevious, 5U)) + 2506732930310252119U;
            aOrbiterC = ((aWandererI + RotL64(aCross, 41U)) + RotL64(aCarry, 29U)) + 16782163084851775826U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 823673076571076303U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 1634084509064077736U;
            aOrbiterI = RotL64((aOrbiterI * 1128407326773234517U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 1288134975466877686U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 2998220403162908444U;
            aOrbiterJ = RotL64((aOrbiterJ * 4321412662318298283U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 220430672180734911U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 10223923547068528867U) ^ aNonceWordF;
            aOrbiterF = RotL64((aOrbiterF * 12577370238343872139U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 11696469696177647608U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 6545430420379636963U;
            aOrbiterC = RotL64((aOrbiterC * 8387163146257553773U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 79691451831797107U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 8971444023498649419U;
            aOrbiterD = RotL64((aOrbiterD * 7148919880477390009U), 57U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterC) + 5624403902454498793U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordK;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 9468064161002030997U;
            aOrbiterE = RotL64((aOrbiterE * 8243560528100864595U), 51U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterE) + 4619361544913629805U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordL;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 12682446273369750704U;
            aOrbiterK = RotL64((aOrbiterK * 10879074713156075641U), 11U);
            //
            aIngress = RotL64(aOrbiterC, 47U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterD, 23U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterJ, 12U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 37U) + aOrbiterE) + RotL64(aOrbiterF, 11U));
            aWandererI = aWandererI + (((RotL64(aIngress, 43U) + aOrbiterC) + RotL64(aOrbiterE, 3U)) + aNonceWordG);
            aWandererH = aWandererH ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterK, 48U)) + aOrbiterE) + aNonceWordI);
            aWandererA = aWandererA + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterI, 35U)) + aOrbiterE) + RotL64(aCarry, 41U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 3U) + aOrbiterF) + RotL64(aOrbiterI, 57U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 29U) + aOrbiterI) + RotL64(aOrbiterD, 19U)) + RotL64(aCarry, 21U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 20U) + aOrbiterJ) + RotL64(aOrbiterC, 27U)) + aNonceWordB);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 48U) ^ aWandererA);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 41U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 5U));
            aCarry = aCarry + RotL64(aWandererF, 11U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 26376U)) & S_BLOCK1], 53U) ^ RotL64(aSnowLaneB[((aIndex + 27119U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 25684U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 23231U)) & S_BLOCK1], 53U) ^ RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 22766U)) & S_BLOCK1], 12U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 35U) + RotL64(aIngress, 10U)) ^ (RotL64(aCarry, 47U) ^ RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterC = ((aWandererI + RotL64(aCross, 51U)) + 12136097566601676613U) + aPhaseDOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = (((aWandererC + RotL64(aScatter, 27U)) + RotL64(aCarry, 37U)) + 7969431322248040056U) + aNonceWordF;
            aOrbiterI = ((aWandererH + RotL64(aIngress, 3U)) + RotL64(aCarry, 53U)) + 10530676021510553889U;
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 57U)) + 8740777303075445264U) + aNonceWordN;
            aOrbiterK = (((aWandererA + RotL64(aScatter, 13U)) + 13249434169895564739U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordP;
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 21U)) + RotL64(aCarry, 19U)) + 15529577005925628472U;
            aOrbiterG = (aWandererE + RotL64(aCross, 34U)) + 344627093687331562U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 8824277416519988893U) + aNonceWordD;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 5636276438449709875U;
            aOrbiterI = RotL64((aOrbiterI * 222817930773618893U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 2079413361031851552U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 7807998179168655561U;
            aOrbiterK = RotL64((aOrbiterK * 961456853699784753U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 13589392896232029112U) + aNonceWordG;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 10733011474804473996U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 361749145931578805U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 15934162328347805968U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 7573511217796245232U;
            aOrbiterF = RotL64((aOrbiterF * 10694563909931636155U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 4828475187337891975U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 13284974329890393113U;
            aOrbiterJ = RotL64((aOrbiterJ * 10831075817642374287U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 13173869918669643112U) + aNonceWordC;
            aOrbiterC = (((aOrbiterC ^ aOrbiterE) ^ 15841507674783398167U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterC = RotL64((aOrbiterC * 15632933198136963277U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 14168272451055700516U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 11134471485501999898U;
            aOrbiterG = RotL64((aOrbiterG * 8019507184494591705U), 19U);
            //
            aIngress = RotL64(aOrbiterK, 53U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterF, 3U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 41U));
            aIngress = aIngress + RotL64(aOrbiterJ, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterK, 57U)) + aOrbiterG);
            aWandererD = aWandererD + (((((RotL64(aIngress, 29U) + RotL64(aOrbiterF, 19U)) + aOrbiterG) + RotL64(aCarry, 5U)) + aNonceWordB) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 6U) + RotL64(aOrbiterC, 43U)) + aOrbiterI);
            aWandererA = aWandererA + ((((RotL64(aCross, 21U) + aOrbiterK) + RotL64(aOrbiterF, 29U)) + RotL64(aCarry, 41U)) + aNonceWordA);
            aWandererH = aWandererH ^ ((((RotL64(aPrevious, 47U) + aOrbiterE) + RotL64(aOrbiterK, 50U)) + aNonceWordO) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 57U) + RotL64(aOrbiterE, 5U)) + aOrbiterI) + aNonceWordE);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 39U) + aOrbiterJ) + RotL64(aOrbiterG, 11U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 29U));
            aCarry = aCarry + (RotL64(aWandererE, 18U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererD, 41U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 29177U)) & S_BLOCK1], 54U) ^ RotL64(aInvestLaneA[((aIndex + 27477U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 30745U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 27691U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneB[((aIndex + 28183U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 60U) + RotL64(aCross, 35U)) ^ (RotL64(aIngress, 47U) + RotL64(aCarry, 13U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterK = (((aWandererA + RotL64(aScatter, 60U)) + RotL64(aCarry, 51U)) + 4970414922752555648U) + aNonceWordL;
            aOrbiterJ = ((((aWandererJ + RotL64(aCross, 29U)) + RotL64(aCarry, 13U)) + 9462756592787669327U) + aPhaseDOrbiterAssignSaltD[((aIndex + 28U)) & S_SALT1]) + aNonceWordN;
            aOrbiterI = ((aWandererI + RotL64(aIngress, 21U)) + RotL64(aCarry, 39U)) + 3948790686662213095U;
            aOrbiterG = (aWandererE + RotL64(aPrevious, 35U)) + 14542857212241578311U;
            aOrbiterE = (((aWandererB + RotL64(aIngress, 47U)) + 3387479009827029547U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordE;
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 53U)) + 1411421370057797877U) + aNonceWordC;
            aOrbiterF = (aWandererK + RotL64(aScatter, 13U)) + 16894451466895681236U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 12727136462290223542U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 4625389198191960525U;
            aOrbiterI = RotL64((aOrbiterI * 5726474430977810191U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 3471881403786164913U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterJ) ^ 6433115856048534831U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterE = RotL64((aOrbiterE * 9363233870194144053U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 9825592965466157982U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 1553125767261293088U;
            aOrbiterG = RotL64((aOrbiterG * 411535191177308781U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 9951616357109647617U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 11231080382787286889U) ^ aNonceWordP;
            aOrbiterF = RotL64((aOrbiterF * 14024961994986659187U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 13419663264017317947U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 4835055642466215566U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17898065852351759171U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 14558747666410946768U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 13120938960926874504U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5681766019285559739U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 11910501376797343986U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 15074100100781785300U;
            aOrbiterK = RotL64((aOrbiterK * 228976960937473851U), 51U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterJ, 35U);
            aIngress = aIngress + (RotL64(aOrbiterF, 53U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterK, 23U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterE, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aScatter, 47U) + RotL64(aOrbiterE, 39U)) + aOrbiterK);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 37U) + aOrbiterF) + RotL64(aOrbiterC, 21U)) + aNonceWordH);
            aWandererK = aWandererK + ((((RotL64(aIngress, 21U) + RotL64(aOrbiterK, 47U)) + aOrbiterJ) + RotL64(aCarry, 5U)) + aNonceWordK);
            aWandererA = aWandererA ^ ((((RotL64(aCross, 29U) + RotL64(aOrbiterC, 60U)) + aOrbiterI) + aNonceWordD) + aPhaseDWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 10U) + RotL64(aOrbiterI, 53U)) + aOrbiterE);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterJ, 27U)) + aOrbiterE);
            aWandererE = aWandererE + ((((RotL64(aCross, 3U) + RotL64(aOrbiterG, 11U)) + aOrbiterC) + RotL64(aCarry, 57U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 60U));
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererB, 19U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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

void TwistExpander_WaterPolo_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x8F80A660FCF8B871ULL + 0xC5469DD71F4431B8ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xFE1DD1F659F5FAB3ULL + 0xA3A5D895BFFF34AEULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xAFE0014B8226D401ULL + 0xF4B637073FC65762ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xDE7538638CCE15D9ULL + 0xAA58E4AED2C34AB7ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xCFD27B5E79A3498BULL + 0xB9EABF906767690BULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xC7B4831AA419DB2DULL + 0xE3BEC26F2111384CULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xFBDE5B8BEA561A89ULL + 0xCCEF2DE388C34629ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xB4EE5ED42BEDF5E1ULL + 0xFB6047F7C8DC9AA4ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xA8637965787A91D7ULL + 0xE9D9E823A6B37B98ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xA664EA41FC6F8995ULL + 0xB4DB7092F440FED0ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xC98644B785BFBBB5ULL + 0xE9FB80C754A46E8FULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x99AFCE1AB2B37EABULL + 0xB3DF9CF51544F032ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x8B29ACA1CD123D99ULL + 0xFF70BAD242D41666ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x83F028CE4A4CB733ULL + 0xCE26844EEE4359F2ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xC873880AF726E207ULL + 0xD9628BF3B2796703ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xC45F94C1D1274C3BULL + 0xF8C90C6F323F4488ULL);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 3310U)) & S_BLOCK1], 58U) ^ RotL64(aInvestLaneB[((aIndex + 1018U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 1132U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 5014U)) & S_BLOCK1], 23U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 2526U)) & S_BLOCK1], 14U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 2587U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aPrevious, 39U)) ^ (RotL64(aCross, 6U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterA = ((aWandererD + RotL64(aIngress, 47U)) + RotL64(aCarry, 47U)) + 17711946802293254150U;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 6U)) + 16652362590489569378U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterG = ((aWandererK + RotL64(aCross, 53U)) + 6972810344198183097U) + aNonceWordK;
            aOrbiterE = (aWandererB + RotL64(aScatter, 23U)) + 13117100889782940546U;
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 35U)) + RotL64(aCarry, 57U)) + 13199305696782626591U;
            aOrbiterH = (aWandererF + RotL64(aIngress, 39U)) + 992156184392760945U;
            aOrbiterJ = (aWandererI + RotL64(aCross, 10U)) + 13791265442074543880U;
            aOrbiterB = (aWandererG + RotL64(aScatter, 41U)) + 17057087245252294859U;
            aOrbiterF = (aWandererC + RotL64(aIngress, 43U)) + 13444195995883541046U;
            aOrbiterD = ((aWandererA + RotL64(aCross, 19U)) + RotL64(aCarry, 13U)) + 6723678233676059420U;
            aOrbiterI = (((aWandererH + RotL64(aScatter, 27U)) + 7913379431208430475U) + aPhaseEOrbiterAssignSaltE[((aIndex + 16U)) & S_SALT1]) + aNonceWordP;
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 4481887195529300665U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 11892724101424384078U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3468639499716604111U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 7700902083270424194U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 1888001433557140271U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8975562955027025349U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 14996753906788986929U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 939004845422123765U) ^ aNonceWordA;
            aOrbiterC = RotL64((aOrbiterC * 2507090308972292313U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 11922230289291941807U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 15681187459741147199U;
            aOrbiterB = RotL64((aOrbiterB * 10124947739653819101U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 9119043713532718155U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 8327697433992362166U;
            aOrbiterJ = RotL64((aOrbiterJ * 11157657162184304567U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 13630755116592440359U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 771252613886022889U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2958918915223536519U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 8524239721467527770U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 17732617735422435572U;
            aOrbiterD = RotL64((aOrbiterD * 13992947983987668631U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 5265753270696005619U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 14456128349522985053U;
            aOrbiterA = RotL64((aOrbiterA * 5406509991740849617U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 12909993509014176457U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 10113568710432654194U;
            aOrbiterE = RotL64((aOrbiterE * 6857806395910432831U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 14818978163348513071U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 17843349910031998923U;
            aOrbiterI = RotL64((aOrbiterI * 13608449524810499593U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 12589077818524017161U) + aNonceWordL;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 17711946802293254150U;
            aOrbiterF = RotL64((aOrbiterF * 9454569713107675231U), 51U);
            //
            aIngress = RotL64(aOrbiterA, 37U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 21U));
            aIngress = aIngress + (RotL64(aOrbiterH, 11U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterB, 18U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 27U));
            aIngress = aIngress + RotL64(aOrbiterD, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterH, 3U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 34U) + RotL64(aOrbiterF, 24U)) + aOrbiterA) + aNonceWordM);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 57U) + aOrbiterI) + RotL64(aOrbiterH, 5U)) + aPhaseEWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterJ, 43U)) + aOrbiterC);
            aWandererK = aWandererK ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterD, 53U)) + aOrbiterC);
            aWandererH = aWandererH + ((((RotL64(aScatter, 50U) + RotL64(aOrbiterK, 19U)) + aOrbiterA) + RotL64(aCarry, 13U)) + aNonceWordB);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 3U) + aOrbiterF) + RotL64(aOrbiterE, 41U));
            aWandererA = aWandererA + (((RotL64(aIngress, 19U) + aOrbiterB) + RotL64(aOrbiterD, 29U)) + RotL64(aCarry, 29U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 53U) + aOrbiterG) + RotL64(aOrbiterD, 48U));
            aWandererE = aWandererE + ((RotL64(aCross, 29U) + aOrbiterI) + RotL64(aOrbiterJ, 11U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 37U) + aOrbiterJ) + RotL64(aOrbiterK, 13U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 26U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 51U));
            aCarry = aCarry + RotL64(aWandererK, 58U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = (RotL64(aFireLaneA[((aIndex + 8577U)) & S_BLOCK1], 40U) ^ RotL64(aInvestLaneC[((aIndex + 9300U)) & S_BLOCK1], 21U));
            aIngress ^= (RotL64(aInvestLaneD[((aIndex + 5490U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((aIndex + 10887U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 9219U)) & S_BLOCK1], 24U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 7203U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 6548U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCross, 35U) ^ RotL64(aPrevious, 47U)) + (RotL64(aCarry, 60U) + RotL64(aIngress, 13U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 3U)) + 10038936806177516123U;
            aOrbiterI = ((aWandererB + RotL64(aScatter, 47U)) + RotL64(aCarry, 19U)) + 1773168435195292638U;
            aOrbiterA = ((aWandererF + RotL64(aIngress, 53U)) + 10655711161526628072U) + aNonceWordO;
            aOrbiterB = ((aWandererC + RotL64(aCross, 57U)) + 14422295664639740437U) + aNonceWordN;
            aOrbiterG = (aWandererA + RotL64(aIngress, 13U)) + 4125228715513159576U;
            aOrbiterJ = (aWandererG + RotL64(aCross, 23U)) + 3670449653158650845U;
            aOrbiterF = (aWandererE + RotL64(aPrevious, 6U)) + 17553727567180813057U;
            aOrbiterH = ((aWandererH + RotL64(aScatter, 11U)) + 5111401772713882743U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = (aWandererK + RotL64(aIngress, 39U)) + 7688573124662314413U;
            aOrbiterD = (((aWandererI + RotL64(aCross, 43U)) + RotL64(aCarry, 13U)) + 9438375825507814395U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 18U)) + RotL64(aCarry, 47U)) + 14177477039902118886U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 16329942595859623928U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 3990536794006836672U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 579024714339065373U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 5072881436583180756U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 16789727877867289997U;
            aOrbiterJ = RotL64((aOrbiterJ * 8766246302636197905U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 17313956922306689438U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 11530878396329822041U) ^ aNonceWordI;
            aOrbiterE = RotL64((aOrbiterE * 11356860047841383129U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 3612616532321160196U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 4172189825359187763U;
            aOrbiterH = RotL64((aOrbiterH * 12938945495299393177U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 8677279703778052804U) + aNonceWordH;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 1912172980909479362U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10053289257955474143U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 1460085850227494500U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 12116763868122868147U;
            aOrbiterF = RotL64((aOrbiterF * 6076945628020280957U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 17571840610366424432U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 15581362592611080868U;
            aOrbiterB = RotL64((aOrbiterB * 1129054058044872003U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 14434700039977611666U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 4534294602623329152U;
            aOrbiterG = RotL64((aOrbiterG * 5860911553425182045U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 865998255725903702U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 16407778704555344108U) ^ aNonceWordB;
            aOrbiterI = RotL64((aOrbiterI * 15571344643129797977U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 1948990288894429805U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 18218556219056835250U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16574160087642377293U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 1309229265173143398U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 10038936806177516123U) ^ aNonceWordC;
            aOrbiterD = RotL64((aOrbiterD * 12954594462760207923U), 21U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterK, 43U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 50U));
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + (RotL64(aOrbiterA, 41U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterB, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((((RotL64(aPrevious, 41U) + aOrbiterF) + RotL64(aOrbiterE, 23U)) + RotL64(aCarry, 3U)) + aNonceWordE) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 37U) + RotL64(aOrbiterH, 19U)) + aOrbiterK) + aNonceWordJ);
            aWandererH = aWandererH + (((RotL64(aIngress, 3U) + RotL64(aOrbiterB, 35U)) + aOrbiterE) + RotL64(aCarry, 57U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterB, 39U)) + aOrbiterA);
            aWandererG = aWandererG + (((RotL64(aScatter, 50U) + RotL64(aOrbiterJ, 30U)) + aOrbiterA) + aNonceWordA);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 11U) + aOrbiterA) + RotL64(aOrbiterD, 37U));
            aWandererE = aWandererE + ((RotL64(aIngress, 23U) + aOrbiterF) + RotL64(aOrbiterB, 3U));
            aWandererK = aWandererK ^ ((((RotL64(aCross, 57U) + aOrbiterH) + RotL64(aOrbiterD, 13U)) + aNonceWordL) + aPhaseEWandererUpdateSaltE[((aIndex + 14U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 29U) + RotL64(aOrbiterC, 11U)) + aOrbiterF);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 39U) + aOrbiterI) + RotL64(aOrbiterA, 52U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 14U) + RotL64(aOrbiterJ, 57U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererH, 22U) ^ aWandererB);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererG, 30U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 14035U)) & S_BLOCK1], 11U) ^ RotL64(aInvestLaneA[((aIndex + 15562U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 11249U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 14942U)) & S_BLOCK1], 21U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 15603U)) & S_BLOCK1], 40U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aPrevious, 42U) ^ RotL64(aCarry, 29U)) + (RotL64(aIngress, 13U) ^ RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterD = (aWandererF + RotL64(aPrevious, 41U)) + 10881271196314989997U;
            aOrbiterH = (((aWandererI + RotL64(aIngress, 57U)) + RotL64(aCarry, 35U)) + 6406461249988567558U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = (aWandererG + RotL64(aScatter, 53U)) + 17255067918280095959U;
            aOrbiterE = (aWandererC + RotL64(aCross, 6U)) + 16690850682497718411U;
            aOrbiterC = (aWandererH + RotL64(aPrevious, 21U)) + 5576201059361086866U;
            aOrbiterI = ((aWandererE + RotL64(aCross, 13U)) + 11991259685693687554U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = (aWandererJ + RotL64(aScatter, 37U)) + 14652535244217836909U;
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 11U)) + 1701789037170782122U) + aNonceWordI;
            aOrbiterG = (aWandererB + RotL64(aScatter, 29U)) + 953429054903473833U;
            aOrbiterB = (((aWandererA + RotL64(aPrevious, 34U)) + RotL64(aCarry, 41U)) + 12064513610469714211U) + aNonceWordP;
            aOrbiterK = ((aWandererK + RotL64(aCross, 43U)) + RotL64(aCarry, 11U)) + 7993881398822002424U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 14421313768013320050U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 11112386845630998889U;
            aOrbiterF = RotL64((aOrbiterF * 11771526352030371669U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 17069630896535699015U) + aNonceWordM;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 3308240081138623373U;
            aOrbiterI = RotL64((aOrbiterI * 10449509484417835159U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 17615529807112933619U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 11782807146851563541U;
            aOrbiterJ = RotL64((aOrbiterJ * 12992075832343669221U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 14401645829607611983U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 6736397344219993532U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1667287547938175641U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 6446974060524700550U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 7840991992443308254U;
            aOrbiterG = RotL64((aOrbiterG * 6891023544882740107U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 10362169906019794305U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 4503700997923168911U) ^ aNonceWordC;
            aOrbiterE = RotL64((aOrbiterE * 15066164494038852559U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 13492041134973259041U) + aNonceWordO;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 14337899277551397976U;
            aOrbiterH = RotL64((aOrbiterH * 5966740718899290915U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 13693100781608180748U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 16177545026405910052U;
            aOrbiterK = RotL64((aOrbiterK * 6019231448444020563U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 9641191118119415680U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 735491776764667034U;
            aOrbiterC = RotL64((aOrbiterC * 11305930862759869997U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 2225714710491247284U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 16906789796765378455U;
            aOrbiterB = RotL64((aOrbiterB * 4341667316266234469U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 9451961177946601088U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 10881271196314989997U;
            aOrbiterD = RotL64((aOrbiterD * 10929686721061541543U), 41U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterD, 10U);
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterI, 43U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 19U));
            aIngress = aIngress + RotL64(aOrbiterJ, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 47U) + aOrbiterJ) + RotL64(aOrbiterG, 47U));
            aWandererB = aWandererB + (((RotL64(aCross, 39U) + RotL64(aOrbiterD, 21U)) + aOrbiterI) + aNonceWordA);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterB, 5U)) + aOrbiterJ);
            aWandererF = aWandererF + ((RotL64(aIngress, 57U) + RotL64(aOrbiterD, 51U)) + aOrbiterC);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 14U) + aOrbiterD) + RotL64(aOrbiterB, 12U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 37U) + RotL64(aOrbiterJ, 3U)) + aOrbiterH);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 3U) + aOrbiterA) + RotL64(aOrbiterG, 53U));
            aWandererC = aWandererC + ((((RotL64(aCross, 5U) + aOrbiterK) + RotL64(aOrbiterI, 35U)) + RotL64(aCarry, 27U)) + aPhaseEWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterK, 43U)) + aOrbiterE) + aNonceWordK);
            aWandererG = aWandererG + (((RotL64(aPrevious, 24U) + RotL64(aOrbiterK, 39U)) + aOrbiterB) + RotL64(aCarry, 21U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterE, 30U)) + aOrbiterF) + aPhaseEWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 60U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererK);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 56U));
            aCarry = aCarry + RotL64(aWandererJ, 11U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 18407U)) & S_BLOCK1], 56U) ^ RotL64(aFireLaneA[((aIndex + 16697U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 21017U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 19060U)) & S_BLOCK1], 43U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 16583U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCarry, 51U)) + (RotL64(aCross, 5U) ^ RotL64(aPrevious, 36U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterA = ((aWandererE + RotL64(aIngress, 47U)) + 8375305456876489425U) + aNonceWordC;
            aOrbiterB = ((aWandererF + RotL64(aScatter, 5U)) + 16193562952772453047U) + aNonceWordM;
            aOrbiterI = (aWandererA + RotL64(aCross, 53U)) + 18088652458594816223U;
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 18U)) + 767344788620249944U;
            aOrbiterH = (aWandererK + RotL64(aIngress, 29U)) + 7705194930396368752U;
            aOrbiterD = (((aWandererB + RotL64(aCross, 35U)) + RotL64(aCarry, 3U)) + 3829736891311272834U) + aPhaseEOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = (((aWandererH + RotL64(aScatter, 41U)) + RotL64(aCarry, 41U)) + 9881681671347640061U) + aNonceWordF;
            aOrbiterF = (aWandererD + RotL64(aPrevious, 44U)) + 1721196560190164264U;
            aOrbiterC = (aWandererJ + RotL64(aCross, 23U)) + 3002652618388454213U;
            aOrbiterG = (((aWandererC + RotL64(aPrevious, 3U)) + RotL64(aCarry, 19U)) + 9811621464004005202U) + aPhaseEOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = (aWandererG + RotL64(aIngress, 51U)) + 5652598941069986530U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 6250499348327316328U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 16025054277615264530U;
            aOrbiterI = RotL64((aOrbiterI * 16446892258704281903U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 13800298546867243172U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 12256104592865905782U;
            aOrbiterD = RotL64((aOrbiterD * 16983140179497142713U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 17817225416918329229U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 17738671327352776217U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 393488251327705063U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 6816031224188400541U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 16989563985059237014U;
            aOrbiterJ = RotL64((aOrbiterJ * 8677884225771717797U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 16891524847268207549U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 1833508573940405571U;
            aOrbiterA = RotL64((aOrbiterA * 9709196587703979539U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 12729999421507068973U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 6839758643521968957U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16350557395881283975U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 8524167125469267428U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 14741523560290472617U;
            aOrbiterF = RotL64((aOrbiterF * 4367850822282205897U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 10983798459868424892U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 5649250846622078964U;
            aOrbiterE = RotL64((aOrbiterE * 7149612714806023987U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 8587302028325090061U) + aNonceWordJ;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 17457129226030333666U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 18107356450566915215U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 15600113588474915690U) + aNonceWordL;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 6595247491374683783U;
            aOrbiterC = RotL64((aOrbiterC * 1432432381540098765U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 13246325856585534283U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 8375305456876489425U;
            aOrbiterK = RotL64((aOrbiterK * 8331406038795786099U), 19U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterB, 37U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 51U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 46U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 21U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + RotL64(aOrbiterG, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 21U) + aOrbiterE) + RotL64(aOrbiterH, 43U));
            aWandererD = aWandererD + (((RotL64(aIngress, 53U) + RotL64(aOrbiterC, 41U)) + aOrbiterB) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 19U) + aOrbiterD) + RotL64(aOrbiterE, 18U)) + aNonceWordH);
            aWandererK = aWandererK + ((RotL64(aPrevious, 35U) + aOrbiterJ) + RotL64(aOrbiterF, 5U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterI, 37U)) + aOrbiterD);
            aWandererI = aWandererI + (((RotL64(aPrevious, 6U) + aOrbiterA) + RotL64(aOrbiterF, 3U)) + RotL64(aCarry, 11U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 43U) + aOrbiterC) + RotL64(aOrbiterF, 13U));
            aWandererA = aWandererA + (((RotL64(aIngress, 27U) + aOrbiterF) + RotL64(aOrbiterH, 11U)) + RotL64(aCarry, 35U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 51U) + aOrbiterD) + RotL64(aOrbiterK, 52U)) + aPhaseEWandererUpdateSaltB[((aIndex + 24U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aCross, 40U) + aOrbiterA) + RotL64(aOrbiterD, 21U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterH, 35U)) + aOrbiterG) + aNonceWordE);
            //
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererA, 60U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererE, 35U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 23312U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneB[((aIndex + 22715U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 25577U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 22989U)) & S_BLOCK1], 30U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 24868U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 26552U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 19U)) + (RotL64(aCross, 53U) ^ RotL64(aIngress, 6U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterK = ((aWandererF + RotL64(aCross, 53U)) + 12122689833405846292U) + aNonceWordN;
            aOrbiterF = (aWandererC + RotL64(aPrevious, 13U)) + 9640400270962766788U;
            aOrbiterI = ((aWandererI + RotL64(aScatter, 19U)) + 9141937998266739071U) + aPhaseEOrbiterAssignSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = ((aWandererH + RotL64(aIngress, 50U)) + RotL64(aCarry, 41U)) + 12899395770434090537U;
            aOrbiterE = (((aWandererE + RotL64(aScatter, 39U)) + 13457918115408031842U) + aPhaseEOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1]) + aNonceWordP;
            aOrbiterA = ((aWandererB + RotL64(aCross, 21U)) + RotL64(aCarry, 21U)) + 15134784483576000943U;
            aOrbiterJ = (aWandererG + RotL64(aIngress, 35U)) + 12540961268790055438U;
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 11U)) + RotL64(aCarry, 57U)) + 6306886773092764230U;
            aOrbiterG = (aWandererK + RotL64(aIngress, 29U)) + 13573343491337243121U;
            aOrbiterH = (aWandererA + RotL64(aPrevious, 3U)) + 8545588657348974413U;
            aOrbiterD = (aWandererD + RotL64(aScatter, 6U)) + 10891410570357275120U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 2877137119767060151U) + aNonceWordD;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 9178097682386595144U;
            aOrbiterI = RotL64((aOrbiterI * 3524486002084427513U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 15528007881855616978U) + aNonceWordI;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 11368419529245281435U;
            aOrbiterA = RotL64((aOrbiterA * 12433207037378339309U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 5932738914934356645U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 5551842263864055419U) ^ aNonceWordL;
            aOrbiterE = RotL64((aOrbiterE * 16093776759971522681U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 3824433359595690603U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 17184628855571662441U;
            aOrbiterC = RotL64((aOrbiterC * 691208053136187317U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 8724462245014132623U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 7481349499528092352U;
            aOrbiterB = RotL64((aOrbiterB * 8212182934509617583U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 6908362960248294718U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 5354057969992655314U;
            aOrbiterH = RotL64((aOrbiterH * 16586084885820679343U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 11138301629323903147U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 14164180536320940750U) ^ aNonceWordM;
            aOrbiterF = RotL64((aOrbiterF * 9099767681053390287U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 709942920176922902U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 17128241237359414945U;
            aOrbiterD = RotL64((aOrbiterD * 14063385518459963529U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 6760410778228957309U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 15333948259759012363U;
            aOrbiterG = RotL64((aOrbiterG * 3685416414008280787U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 6929136132517755104U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 13833415487953533365U;
            aOrbiterJ = RotL64((aOrbiterJ * 14860437994758579635U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 16143046377679975216U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 12122689833405846292U;
            aOrbiterK = RotL64((aOrbiterK * 227699085983424155U), 41U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterE, 37U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 26U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 47U));
            aIngress = aIngress + (RotL64(aOrbiterI, 23U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterD, 43U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterB, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 13U) + aOrbiterD) + RotL64(aOrbiterG, 11U));
            aWandererE = aWandererE + ((((RotL64(aScatter, 53U) + aOrbiterC) + RotL64(aOrbiterE, 43U)) + RotL64(aCarry, 13U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 57U) + aOrbiterH) + RotL64(aOrbiterG, 60U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 34U) + aOrbiterF) + RotL64(aOrbiterG, 41U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterK, 57U)) + aOrbiterJ);
            aWandererD = aWandererD + (((RotL64(aPrevious, 41U) + aOrbiterI) + RotL64(aOrbiterG, 19U)) + aNonceWordO);
            aWandererC = aWandererC ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterA, 21U)) + aOrbiterC) + aNonceWordE);
            aWandererH = aWandererH + ((RotL64(aIngress, 5U) + aOrbiterE) + RotL64(aOrbiterJ, 3U));
            aWandererF = aWandererF ^ ((((RotL64(aPrevious, 44U) + aOrbiterG) + RotL64(aOrbiterJ, 39U)) + aNonceWordK) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 23U) + RotL64(aOrbiterD, 13U)) + aOrbiterB) + RotL64(aCarry, 43U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterB, 50U)) + aOrbiterJ) + aNonceWordF);
            //
            aCarry = aCarry + (RotL64(aWandererG, 6U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererI, 53U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 26U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 28806U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneA[((aIndex + 27798U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 32340U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29646U)) & S_BLOCK1], 21U) ^ RotL64(aInvestLaneB[((aIndex + 27358U)) & S_BLOCK1], 34U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 41U) + RotL64(aPrevious, 11U)) + (RotL64(aCross, 26U) ^ RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterI = ((aWandererK + RotL64(aCross, 26U)) + RotL64(aCarry, 21U)) + 4848316479321533394U;
            aOrbiterF = ((aWandererG + RotL64(aIngress, 37U)) + 6919360256662636195U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = (((aWandererF + RotL64(aScatter, 43U)) + RotL64(aCarry, 39U)) + 9897013582181108544U) + aNonceWordH;
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 47U)) + 7319353809896158678U) + aNonceWordO;
            aOrbiterJ = (aWandererJ + RotL64(aCross, 13U)) + 2848175435514849859U;
            aOrbiterG = ((aWandererI + RotL64(aIngress, 41U)) + RotL64(aCarry, 51U)) + 6967780718720437934U;
            aOrbiterE = (((aWandererB + RotL64(aPrevious, 11U)) + 10143884766603388136U) + aPhaseEOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1]) + aNonceWordN;
            aOrbiterD = ((aWandererC + RotL64(aScatter, 39U)) + 8675965006150972051U) + aNonceWordM;
            aOrbiterB = (aWandererE + RotL64(aPrevious, 18U)) + 16350117755560994281U;
            aOrbiterC = (aWandererH + RotL64(aCross, 3U)) + 17976597517118423760U;
            aOrbiterK = (aWandererD + RotL64(aScatter, 35U)) + 1399631141355370237U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 3590613762034716792U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 5134624314245932157U;
            aOrbiterH = RotL64((aOrbiterH * 13077589037975283371U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 10082236952942943654U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 4015535035905433450U;
            aOrbiterG = RotL64((aOrbiterG * 4961808568701908559U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 611474103801573800U) + aNonceWordG;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 5786708483794098001U) ^ aNonceWordK;
            aOrbiterD = RotL64((aOrbiterD * 7694007039340089267U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 5201943497363274455U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 9282160506938328489U;
            aOrbiterB = RotL64((aOrbiterB * 5368182164239021367U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 4932320527498940158U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 11576526341731392916U;
            aOrbiterC = RotL64((aOrbiterC * 1712051774729439363U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 10790691517638887125U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 16280649213607464422U;
            aOrbiterI = RotL64((aOrbiterI * 10756733801499471873U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 9553716940667712810U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 11827518270964003341U;
            aOrbiterA = RotL64((aOrbiterA * 1322489827908132831U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 16777463701235809321U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 3375489084588454149U;
            aOrbiterE = RotL64((aOrbiterE * 3335010977457647307U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 8129898095524287632U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 14496406641486541929U;
            aOrbiterK = RotL64((aOrbiterK * 10077246205532940301U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 17968163292907132345U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 2431407778543471402U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 407105842057624537U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 18330313613898211889U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 4848316479321533394U;
            aOrbiterF = RotL64((aOrbiterF * 3462735144109152811U), 3U);
            //
            aIngress = RotL64(aOrbiterA, 57U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 5U));
            aIngress = aIngress + (RotL64(aOrbiterG, 23U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterC, 47U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterI, 13U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterK, 18U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aScatter, 53U) + aOrbiterC) + RotL64(aOrbiterF, 57U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterI, 10U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltD[((aIndex + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 35U) + RotL64(aOrbiterH, 5U)) + aOrbiterG) + aNonceWordA);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 40U) + RotL64(aOrbiterA, 43U)) + aOrbiterG);
            aWandererB = aWandererB + ((RotL64(aCross, 3U) + aOrbiterH) + RotL64(aOrbiterB, 3U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterG, 39U)) + aOrbiterC);
            aWandererF = aWandererF + (((RotL64(aIngress, 29U) + RotL64(aOrbiterG, 35U)) + aOrbiterB) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 37U) + aOrbiterA) + RotL64(aOrbiterD, 60U));
            aWandererA = aWandererA + (((RotL64(aCross, 46U) + RotL64(aOrbiterB, 37U)) + aOrbiterE) + RotL64(aCarry, 37U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 5U) + aOrbiterG) + RotL64(aOrbiterK, 21U)) + aNonceWordL);
            aWandererE = aWandererE + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterB, 23U)) + aOrbiterJ) + RotL64(aCarry, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 34U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 41U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererG, 13U);
            aCarry = aCarry + RotL64(aIngress, 24U);
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

void TwistExpander_WaterPolo_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xEAB60315925A5DEFULL + 0x821F51BC00813187ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xD3423FE5BBFAFD3DULL + 0xBD86AB9172B14445ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x93956BB0DA161E91ULL + 0xF45BD81982690717ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xC8FBDF34E6661583ULL + 0xA33E26B06B669279ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x86F97A1F311E6F6BULL + 0x985A10B345EF43BDULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xE0A62CD683F4161FULL + 0xA553B006003B58C7ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xB2A345A9AF70FFD9ULL + 0xC2B1074812FCD2C0ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xEE42E2BD9E9E3FE3ULL + 0xC3F7AD4752D24C84ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xC33E10918E3D4F5FULL + 0xC5C19BE1634B638CULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xE249EEE4AB09FE2FULL + 0xD6DC79B024824CF8ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xFD7926A96F77CAB9ULL + 0x9858519AAD326D92ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xA7913F926157AEABULL + 0xAD6FE347D9C3A513ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xDF18E200568E2CC1ULL + 0x89C56FE3A697F80EULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xE5EBEADFDDE38EE9ULL + 0xDAC6608023DF933DULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xB291F1B1A3CD97D7ULL + 0x8C6D2BC74EF9DA4BULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xF65DE200ABFC39D5ULL + 0xFD2282AA9DFF53FEULL);
    // GSeedRunSeed_F seed_loop_f (start)
    {
        // GSeedRunSeed_F seed_loop_f lane group
        // read from: aOperationLaneA, aOperationLaneB, aSnowLaneB, aOperationLaneC, aOperationLaneD, aInvestLaneC, aSnowLaneC, aInvestLaneB, aInvestLaneD, aSnowLaneD, aWorkLaneC, aExpandLaneA, aInvestLaneA, aExpandLaneB, aWorkLaneD, aExpandLaneC, aSnowLaneA
        // write to: aSnowLaneC, aSnowLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_f loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aSnowLaneB
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aSnowLaneB forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aInvestLaneC
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aInvestLaneC backward/forward random
        // write to: aSnowLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 3458U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneB[((aIndex + 2461U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aSnowLaneB[((aIndex + 2937U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 543U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 2558U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 139U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aIngress, 38U)) + (RotL64(aPrevious, 11U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 57U)) + 13924571355038625040U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = ((aWandererE + RotL64(aIngress, 19U)) + RotL64(aCarry, 29U)) + 16328300979357156658U;
            aOrbiterI = (aWandererB + RotL64(aCross, 3U)) + 3947771961206012461U;
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 23U)) + 15428284250569311285U;
            aOrbiterF = (((aWandererC + RotL64(aScatter, 12U)) + RotL64(aCarry, 51U)) + 5777369485254032486U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = (((aWandererA + RotL64(aPrevious, 43U)) + RotL64(aCarry, 5U)) + 16813320300717644673U) + aNonceWordF;
            aOrbiterE = (aWandererD + RotL64(aIngress, 27U)) + 16689933050200758251U;
            aOrbiterC = ((aWandererI + RotL64(aCross, 47U)) + 1856422419049390708U) + aNonceWordI;
            aOrbiterA = (aWandererK + RotL64(aIngress, 38U)) + 18214498743831925517U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 18278550878494094923U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 797712062039591797U;
            aOrbiterI = RotL64((aOrbiterI * 7212998747080137625U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 15854849439012341347U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 996882939768167773U;
            aOrbiterF = RotL64((aOrbiterF * 14936703950807908575U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 3005829974130671692U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 8793495343509953906U) ^ aNonceWordO;
            aOrbiterK = RotL64((aOrbiterK * 14065479348374612031U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 7710453029930631112U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 9511995836117707047U;
            aOrbiterC = RotL64((aOrbiterC * 7250766204781428201U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 670902975693341744U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 9045820304668279777U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 18373074917532639027U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 12417212387607119470U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 12816983560669985622U) ^ aNonceWordG;
            aOrbiterA = RotL64((aOrbiterA * 8406003970221889847U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 17245432086377688540U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 6806521945548502014U;
            aOrbiterJ = RotL64((aOrbiterJ * 11335859481858640857U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 8947500746292365294U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 4468060468522895852U) ^ aNonceWordE;
            aOrbiterH = RotL64((aOrbiterH * 7022481284816599797U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 9892975931958803992U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 3042599331526937836U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3308512896171443645U), 19U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterD, 10U);
            aIngress = aIngress + (RotL64(aOrbiterK, 23U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 53U));
            aIngress = aIngress + (RotL64(aOrbiterF, 39U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterC, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterA, 46U)) + aOrbiterE) + aNonceWordK);
            aWandererA = aWandererA + (((RotL64(aScatter, 3U) + RotL64(aOrbiterI, 27U)) + aOrbiterK) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterJ, 3U)) + aOrbiterH) + aNonceWordL);
            aWandererD = aWandererD + ((((RotL64(aCross, 34U) + RotL64(aOrbiterA, 41U)) + aOrbiterI) + RotL64(aCarry, 43U)) + aNonceWordP);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterI, 34U)) + aOrbiterJ);
            aWandererE = aWandererE + ((((RotL64(aIngress, 19U) + aOrbiterK) + RotL64(aOrbiterD, 57U)) + RotL64(aCarry, 29U)) + aNonceWordM);
            aWandererK = aWandererK ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterH, 19U)) + aOrbiterE);
            aWandererC = aWandererC + (((RotL64(aScatter, 14U) + RotL64(aOrbiterC, 23U)) + aOrbiterF) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 57U) + aOrbiterJ) + RotL64(aOrbiterF, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 34U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererF);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererC, 57U);
            aCarry = aCarry + RotL64(aIngress, 20U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aSnowLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 2
        // ingress from: aSnowLaneC, aOperationLaneC, aOperationLaneD, aInvestLaneB
        // ingress directions: aSnowLaneC forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aInvestLaneB forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aInvestLaneD
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aInvestLaneD backward/forward random
        // write to: aSnowLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneC[((aIndex + 7168U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneC[((aIndex + 6163U)) & S_BLOCK1], 5U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 8076U)) & S_BLOCK1], 58U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 8807U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 8770U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 8592U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 6121U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCarry, 11U) ^ RotL64(aPrevious, 23U)) + (RotL64(aCross, 60U) ^ RotL64(aIngress, 43U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterE = (((aWandererG + RotL64(aScatter, 58U)) + RotL64(aCarry, 21U)) + 15383045568644941552U) + aNonceWordH;
            aOrbiterF = (((aWandererJ + RotL64(aPrevious, 19U)) + RotL64(aCarry, 11U)) + 17452811657750910067U) + aNonceWordN;
            aOrbiterH = (aWandererI + RotL64(aCross, 37U)) + 15660117718455155603U;
            aOrbiterG = (((aWandererK + RotL64(aIngress, 23U)) + RotL64(aCarry, 51U)) + 10396441207743665753U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterA = ((aWandererC + RotL64(aScatter, 3U)) + 3708971058200841442U) + aPhaseFOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = (aWandererE + RotL64(aCross, 47U)) + 7000673057768598750U;
            aOrbiterJ = (aWandererH + RotL64(aPrevious, 52U)) + 9886354469011131596U;
            aOrbiterK = (aWandererB + RotL64(aIngress, 13U)) + 16018065329058043467U;
            aOrbiterC = (aWandererF + RotL64(aPrevious, 27U)) + 5024756166109352320U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 6587818720728886652U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 3652672354944162319U;
            aOrbiterH = RotL64((aOrbiterH * 10807121230791716109U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 6307315649915348048U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 16405347331742979258U) ^ aNonceWordK;
            aOrbiterA = RotL64((aOrbiterA * 7183142442906743699U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 5427299664054601957U) + aNonceWordO;
            aOrbiterE = (((aOrbiterE ^ aOrbiterA) ^ 4983381733483185898U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterE = RotL64((aOrbiterE * 14646556236306407673U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 10182995521328377487U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 8694282877540593550U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14614602561910403893U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 4085927978153269932U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 6176195962815240877U;
            aOrbiterJ = RotL64((aOrbiterJ * 16792916528959579875U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 6966742100601433005U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 9920952446921247521U;
            aOrbiterG = RotL64((aOrbiterG * 1879821050131820933U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 11958734477518336014U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 2058335903640404380U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6986170159285417789U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 77366119537297816U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 12072894199692855000U;
            aOrbiterD = RotL64((aOrbiterD * 9083781120514635987U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 11874297832446385377U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 13715562531763053196U;
            aOrbiterC = RotL64((aOrbiterC * 12822488258322963187U), 21U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterJ, 57U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 6U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 43U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 51U));
            aIngress = aIngress + RotL64(aOrbiterG, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aIngress, 6U) + aOrbiterA) + RotL64(aOrbiterC, 23U)) + RotL64(aCarry, 27U)) + aNonceWordD);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterK, 37U)) + aOrbiterF) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 35U) + RotL64(aOrbiterE, 46U)) + aOrbiterC);
            aWandererG = aWandererG ^ ((RotL64(aCross, 39U) + aOrbiterG) + RotL64(aOrbiterF, 41U));
            aWandererI = aWandererI + ((RotL64(aScatter, 27U) + RotL64(aOrbiterE, 57U)) + aOrbiterF);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterD, 27U)) + aOrbiterG);
            aWandererF = aWandererF + ((((RotL64(aCross, 48U) + RotL64(aOrbiterD, 5U)) + aOrbiterJ) + RotL64(aCarry, 53U)) + aPhaseFWandererUpdateSaltA[((aIndex + 26U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterH, 19U)) + aOrbiterD) + aNonceWordP);
            aWandererK = aWandererK + (((RotL64(aIngress, 13U) + aOrbiterJ) + RotL64(aOrbiterA, 10U)) + aNonceWordJ);
            //
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererF);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 60U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + RotL64(aWandererH, 57U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aSnowLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_f loop 3
        // ingress from: aSnowLaneD, aOperationLaneA, aWorkLaneC
        // ingress directions: aSnowLaneD forward forced, aOperationLaneA forward forced, aWorkLaneC forward/backward random
        // cross from: aSnowLaneC, aOperationLaneC
        // cross directions: aSnowLaneC backward forced, aOperationLaneC backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneD[((aIndex + 16048U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneA[((aIndex + 14191U)) & S_BLOCK1], 10U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 14958U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 14481U)) & S_BLOCK1], 52U) ^ RotL64(aOperationLaneC[((aIndex + 14913U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 14U)) + (RotL64(aCross, 39U) ^ RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterF = ((aWandererA + RotL64(aScatter, 6U)) + RotL64(aCarry, 27U)) + 16183871922837164759U;
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 53U)) + 7002058258090219055U) + aNonceWordI;
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 13U)) + 5650868611888303705U) + aPhaseFOrbiterAssignSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterB = ((aWandererH + RotL64(aCross, 27U)) + 11899839660943876690U) + aNonceWordD;
            aOrbiterD = (aWandererJ + RotL64(aScatter, 39U)) + 15349649504488111111U;
            aOrbiterH = ((aWandererC + RotL64(aCross, 48U)) + 14060149569086744970U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = (aWandererK + RotL64(aIngress, 19U)) + 12920917574225030112U;
            aOrbiterA = (((aWandererB + RotL64(aPrevious, 35U)) + RotL64(aCarry, 37U)) + 2831994965175330135U) + aNonceWordB;
            aOrbiterI = ((aWandererG + RotL64(aIngress, 23U)) + RotL64(aCarry, 13U)) + 18312543585028439192U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 11657562205118394239U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 10850792819281246052U;
            aOrbiterJ = RotL64((aOrbiterJ * 10663100544207879337U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 17810371216216125323U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 7963413941144223128U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 534217972450595401U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 5498715358793875584U) + aNonceWordN;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 9256727548911651373U;
            aOrbiterG = RotL64((aOrbiterG * 10498848323914000989U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 17246360111302191699U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 18309978718113983369U;
            aOrbiterB = RotL64((aOrbiterB * 18267472694666221077U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 3100998994319502921U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 8129301860291235970U;
            aOrbiterA = RotL64((aOrbiterA * 17847033539279176187U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 1889641029473279114U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 16538494307002917945U;
            aOrbiterH = RotL64((aOrbiterH * 8081488217920885783U), 23U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterA) + 5432230549146849322U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordH;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 2634437941396090817U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7612999214758935211U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 16940172599174185058U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 13151669140593952203U;
            aOrbiterI = RotL64((aOrbiterI * 16225319638131723487U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 3995064294869931681U) + aNonceWordF;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 913081077665768816U) ^ aNonceWordE;
            aOrbiterF = RotL64((aOrbiterF * 9299514648768060453U), 41U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterF, 14U);
            aIngress = aIngress + (RotL64(aOrbiterC, 35U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterA, 29U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterJ, 47U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterH, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aIngress, 5U) + aOrbiterF) + RotL64(aOrbiterD, 12U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterB, 21U)) + aOrbiterA) + aNonceWordK);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 39U) + aOrbiterJ) + RotL64(aOrbiterD, 51U)) + aPhaseFWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 35U) + RotL64(aOrbiterA, 57U)) + aOrbiterI) + aPhaseFWandererUpdateSaltF[((aIndex + 4U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 60U) + RotL64(aOrbiterC, 34U)) + aOrbiterG) + aNonceWordC);
            aWandererE = aWandererE + ((((RotL64(aScatter, 13U) + aOrbiterG) + RotL64(aOrbiterI, 43U)) + RotL64(aCarry, 53U)) + aNonceWordL);
            aWandererC = aWandererC ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterC, 3U)) + aOrbiterJ) + aNonceWordO);
            aWandererH = aWandererH + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterH, 39U)) + aOrbiterG) + RotL64(aCarry, 35U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 52U) + RotL64(aOrbiterG, 47U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererH, 60U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererD, 41U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererK);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + RotL64(aWandererG, 47U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 4
        // ingress from: aExpandLaneA, aSnowLaneC, aInvestLaneA
        // ingress directions: aExpandLaneA forward forced, aSnowLaneC forward forced, aInvestLaneA forward/backward random
        // cross from: aSnowLaneD, aOperationLaneD
        // cross directions: aSnowLaneD backward forced, aOperationLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 20911U)) & S_BLOCK1], 46U) ^ RotL64(aSnowLaneC[((aIndex + 17120U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 17319U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 18435U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 19840U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aIngress, 51U) ^ RotL64(aCross, 4U)) + (RotL64(aPrevious, 35U) + RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterD = (aWandererC + RotL64(aPrevious, 23U)) + 14624277139785904404U;
            aOrbiterC = (((aWandererH + RotL64(aIngress, 29U)) + RotL64(aCarry, 29U)) + 6966977309498165611U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = (aWandererK + RotL64(aScatter, 6U)) + 205536824352530761U;
            aOrbiterK = ((aWandererF + RotL64(aCross, 19U)) + 16629575265808255692U) + aNonceWordI;
            aOrbiterB = (((aWandererJ + RotL64(aPrevious, 41U)) + RotL64(aCarry, 37U)) + 596881340147972746U) + aNonceWordA;
            aOrbiterG = (((aWandererE + RotL64(aCross, 37U)) + RotL64(aCarry, 13U)) + 11944412799107412650U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 14U)) + 4615021315668210206U) + aNonceWordM;
            aOrbiterF = ((aWandererB + RotL64(aIngress, 53U)) + 8497630055977606216U) + aNonceWordN;
            aOrbiterI = (aWandererG + RotL64(aScatter, 57U)) + 11131601107309336885U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 5935883479805510099U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 15629346719765798174U;
            aOrbiterA = RotL64((aOrbiterA * 8535523790685945275U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 5279128339113651273U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 16778365912440331821U;
            aOrbiterD = RotL64((aOrbiterD * 705421028266789241U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 16003052937645491524U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 6723226158737614764U;
            aOrbiterC = RotL64((aOrbiterC * 16690657664909260573U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 9785784358981219543U) + aNonceWordG;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 10055457337292292710U) ^ aNonceWordC;
            aOrbiterG = RotL64((aOrbiterG * 17919129940751761111U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 11779163108592974175U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 1177999477942202687U;
            aOrbiterB = RotL64((aOrbiterB * 13475069421684114643U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 9190694445141492214U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 15605342360346353457U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14547769706392595647U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 14877565450677523492U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 1074095623308025684U;
            aOrbiterI = RotL64((aOrbiterI * 7884068939436891093U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 12803174154216941583U) + aNonceWordE;
            aOrbiterF = (((aOrbiterF ^ aOrbiterC) ^ 8813356463693637033U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterF = RotL64((aOrbiterF * 4898237214617563167U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 6063909634038581414U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 15112191502834052566U;
            aOrbiterJ = RotL64((aOrbiterJ * 6780741782103553485U), 51U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterJ, 3U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 39U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 50U));
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterF, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((((RotL64(aPrevious, 48U) + aOrbiterJ) + RotL64(aOrbiterB, 29U)) + aNonceWordB) + aPhaseFWandererUpdateSaltD[((aIndex + 4U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 57U) + RotL64(aOrbiterC, 43U)) + aOrbiterA) + RotL64(aCarry, 23U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 53U) + aOrbiterG) + RotL64(aOrbiterD, 3U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 39U) + aOrbiterC) + RotL64(aOrbiterI, 11U)) + RotL64(aCarry, 53U));
            aWandererH = aWandererH ^ ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterG, 38U)) + aOrbiterI) + aNonceWordD) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 5U) + RotL64(aOrbiterA, 57U)) + aOrbiterJ);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterF, 47U)) + aOrbiterA) + aNonceWordK);
            aWandererE = aWandererE + ((RotL64(aCross, 29U) + RotL64(aOrbiterJ, 51U)) + aOrbiterK);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 22U) + aOrbiterF) + RotL64(aOrbiterJ, 34U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + (RotL64(aWandererG, 60U) ^ aWandererA);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 39U));
            aCarry = aCarry + RotL64(aWandererF, 23U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_f loop 5
        // ingress from: aExpandLaneB, aSnowLaneD, aWorkLaneD
        // ingress directions: aExpandLaneB forward forced, aSnowLaneD forward forced, aWorkLaneD forward/backward random
        // cross from: aExpandLaneA, aSnowLaneC
        // cross directions: aExpandLaneA backward forced, aSnowLaneC backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 22524U)) & S_BLOCK1], 27U) ^ RotL64(aSnowLaneD[((aIndex + 24318U)) & S_BLOCK1], 4U));
            aIngress ^= RotL64(aWorkLaneD[((aIndex + 26708U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26488U)) & S_BLOCK1], 29U) ^ RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 21992U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 28U) ^ RotL64(aCarry, 57U)) + (RotL64(aCross, 11U) + RotL64(aPrevious, 43U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterH = (aWandererJ + RotL64(aCross, 4U)) + 7960325128608297381U;
            aOrbiterC = (aWandererI + RotL64(aScatter, 43U)) + 12773836012104052042U;
            aOrbiterE = ((aWandererE + RotL64(aIngress, 35U)) + RotL64(aCarry, 5U)) + 3173972621347773016U;
            aOrbiterD = (aWandererH + RotL64(aPrevious, 47U)) + 3708401356314308171U;
            aOrbiterF = (((aWandererC + RotL64(aCross, 57U)) + RotL64(aCarry, 19U)) + 950774285720019449U) + aNonceWordM;
            aOrbiterK = (aWandererB + RotL64(aIngress, 39U)) + 4170092315705438265U;
            aOrbiterB = ((((aWandererF + RotL64(aPrevious, 13U)) + RotL64(aCarry, 29U)) + 17000449130864980747U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordE;
            aOrbiterG = ((aWandererA + RotL64(aScatter, 19U)) + 8793910540062893860U) + aPhaseFOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = (aWandererD + RotL64(aCross, 30U)) + 520277969543516469U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 12762214857389827271U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 2932451184340207695U;
            aOrbiterE = RotL64((aOrbiterE * 7513337346940091655U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 11062179998786293839U) + aNonceWordN;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 7919119215271524178U;
            aOrbiterF = RotL64((aOrbiterF * 9053677007180081359U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 1774988449597115155U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 3799792889466518953U;
            aOrbiterH = RotL64((aOrbiterH * 17512791286490623455U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 1815062051307896589U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 15260373951371654483U;
            aOrbiterG = RotL64((aOrbiterG * 2208604434669491625U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 12867546628945676853U) + aNonceWordF;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 7772820973895846946U;
            aOrbiterC = RotL64((aOrbiterC * 7581704643538761985U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 14213957831821966834U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 16561105721170419454U;
            aOrbiterJ = RotL64((aOrbiterJ * 2540533987337175367U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 16556502948339949526U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 9706742922075498974U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8527361328901355457U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 13455756934917486016U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 9107769876332723454U;
            aOrbiterK = RotL64((aOrbiterK * 1722386100852683783U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 15793099079168487016U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 7968278803691283365U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11644765391940099387U), 43U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterD, 46U);
            aIngress = aIngress + (RotL64(aOrbiterG, 51U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 13U));
            aIngress = aIngress + (RotL64(aOrbiterH, 43U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterF, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aPrevious, 29U) + aOrbiterH) + RotL64(aOrbiterB, 19U)) + RotL64(aCarry, 43U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterE, 23U)) + aOrbiterB) + aNonceWordB);
            aWandererD = aWandererD + ((RotL64(aCross, 10U) + RotL64(aOrbiterF, 29U)) + aOrbiterC);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 21U) + aOrbiterD) + RotL64(aOrbiterF, 60U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aIngress, 5U) + aOrbiterB) + RotL64(aOrbiterJ, 35U)) + RotL64(aCarry, 13U)) + aNonceWordA);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 39U) + RotL64(aOrbiterD, 13U)) + aOrbiterB) + aNonceWordC);
            aWandererI = aWandererI + ((RotL64(aPrevious, 43U) + aOrbiterB) + RotL64(aOrbiterG, 43U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterK, 47U)) + aOrbiterG) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 14U) + RotL64(aOrbiterG, 52U)) + aOrbiterD) + aNonceWordD);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + (RotL64(aWandererF, 37U) ^ aWandererJ);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 11U));
            aCarry = aCarry + (RotL64(aWandererE, 44U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererC, 51U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 28073U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneA[((aIndex + 28520U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 32087U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28859U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneB[((aIndex + 32356U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aPrevious, 56U)) ^ (RotL64(aCarry, 5U) + RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterK = ((aWandererA + RotL64(aIngress, 39U)) + RotL64(aCarry, 53U)) + 10915618884692072446U;
            aOrbiterF = (aWandererG + RotL64(aCross, 60U)) + 12634922308499254909U;
            aOrbiterB = (((aWandererB + RotL64(aScatter, 19U)) + RotL64(aCarry, 3U)) + 6533934734564499389U) + aNonceWordH;
            aOrbiterE = (((aWandererC + RotL64(aPrevious, 3U)) + RotL64(aCarry, 43U)) + 6744203303756105181U) + aNonceWordF;
            aOrbiterI = ((aWandererE + RotL64(aIngress, 35U)) + 13086782386652045658U) + aPhaseFOrbiterAssignSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = (aWandererD + RotL64(aCross, 54U)) + 5693840533331397822U;
            aOrbiterA = ((aWandererH + RotL64(aScatter, 43U)) + 1803663542535024611U) + aNonceWordO;
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 47U)) + 3597219300593287708U) + aPhaseFOrbiterAssignSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterG = (aWandererF + RotL64(aScatter, 11U)) + 1429753448204448904U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 17229017825587322715U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 1137574712801062932U;
            aOrbiterB = RotL64((aOrbiterB * 3645832160939819415U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 2401991077004083378U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 1332473247826139292U;
            aOrbiterI = RotL64((aOrbiterI * 15029831858261506447U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 11730946340796899885U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 15319163439700390962U;
            aOrbiterK = RotL64((aOrbiterK * 1349242001887975499U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 4744141870145159917U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 6067132201862688684U;
            aOrbiterF = RotL64((aOrbiterF * 6046100687757836027U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 14991509179286371800U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 4342608825699398682U) ^ aNonceWordI;
            aOrbiterD = RotL64((aOrbiterD * 10240526103933275875U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 3727521409410742075U) + aNonceWordL;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 3302027219498304367U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12153634588200479559U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 6039539483340398858U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterG) ^ 2902581519976937051U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterH = RotL64((aOrbiterH * 2057584328877854239U), 27U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterI) + 12332784713738947242U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordB;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 13761272577223712786U;
            aOrbiterA = RotL64((aOrbiterA * 14930145045480030821U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 2947946397617043735U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 11107014023853644521U;
            aOrbiterG = RotL64((aOrbiterG * 15030903626191481831U), 37U);
            //
            aIngress = RotL64(aOrbiterD, 58U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 43U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + (RotL64(aOrbiterI, 23U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aIngress, 10U) + aOrbiterH) + RotL64(aOrbiterK, 27U));
            aWandererA = aWandererA + (((RotL64(aCross, 41U) + RotL64(aOrbiterA, 54U)) + aOrbiterI) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterB, 23U)) + aOrbiterE) + aNonceWordK);
            aWandererB = aWandererB + ((((RotL64(aScatter, 53U) + RotL64(aOrbiterD, 13U)) + aOrbiterG) + RotL64(aCarry, 13U)) + aNonceWordD);
            aWandererJ = aWandererJ ^ ((((RotL64(aIngress, 47U) + aOrbiterH) + RotL64(aOrbiterA, 37U)) + aNonceWordP) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aScatter, 57U) + aOrbiterE) + RotL64(aOrbiterD, 60U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 23U) + aOrbiterI) + RotL64(aOrbiterG, 41U));
            aWandererF = aWandererF + ((((RotL64(aCross, 27U) + aOrbiterK) + RotL64(aOrbiterG, 5U)) + RotL64(aCarry, 23U)) + aNonceWordC);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 14U) + aOrbiterK) + RotL64(aOrbiterF, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 19U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 56U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + RotL64(aWandererC, 29U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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

void TwistExpander_WaterPolo_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xB073FE6BDC46BCD5ULL + 0xAA45F9EE22E169D9ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x87A0D31EFE15699DULL + 0xD0FB29B6CC58A3FDULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x8775529BC956BF3BULL + 0xE3C8003C01875007ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x8CD6C4BE7A9800CBULL + 0xAA25219D95F9DFD5ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xE5C5D485603E902DULL + 0xD661E7474FDAAB84ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x9B20FF0041AC4CABULL + 0xD014F852522C20EEULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xDE53FF80FE199AFBULL + 0xCEBAC5E08163B51CULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xBD1AD81D47C19B45ULL + 0x9E0B8826A44D0E01ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xDC90D23705D1653DULL + 0xD93DDF8FC6AE7B1DULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xEC2D615211E5E67BULL + 0xFFB65EA9FFE61EFDULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xB92E4380DAA35751ULL + 0xC793A6A8AA73A323ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xEB5CD0F86D30209FULL + 0xA291931D1751352BULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xBCB97D1591E5DE63ULL + 0xF821E5659E8CD635ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x8FD99AE43C7E5483ULL + 0xC4BB6EA30CF317D1ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xEBEA7B20188471D9ULL + 0xA042A74AE38A4550ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xBDBD4A01CE2CFC87ULL + 0xCE0413ADDCF6DF17ULL);
    // GSeedRunSeed_G seed_loop_h (start)
    {
        // GSeedRunSeed_G seed_loop_h lane group
        // read from: aSnowLaneA, aSnowLaneB, aFireLaneB, aSnowLaneC, aSnowLaneD, aFireLaneC, aWorkLaneA, aInvestLaneC, aInvestLaneA, aWorkLaneB, aInvestLaneD, aExpandLaneA, aInvestLaneB, aExpandLaneB, aFireLaneA, aExpandLaneC, aFireLaneD
        // write to: aWorkLaneA, aWorkLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_h loop 1
        // ingress from: aSnowLaneA, aSnowLaneB, aFireLaneB
        // ingress directions: aSnowLaneA forward forced, aSnowLaneB forward forced, aFireLaneB forward/backward random
        // cross from: aSnowLaneC, aSnowLaneD, aFireLaneC
        // cross directions: aSnowLaneC backward forced, aSnowLaneD backward forced, aFireLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 3056U)) & S_BLOCK1], 48U) ^ RotL64(aSnowLaneB[((aIndex + 2572U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 1019U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 2549U)) & S_BLOCK1], 5U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 3171U)) & S_BLOCK1], 50U));
            aCross ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 3399U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 6U) + RotL64(aIngress, 37U)) ^ (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterA = ((aWandererK + RotL64(aCross, 43U)) + 15813325389431304548U) + aNonceWordH;
            aOrbiterJ = (((aWandererH + RotL64(aScatter, 50U)) + RotL64(aCarry, 23U)) + 2223874171125403602U) + aNonceWordG;
            aOrbiterI = (aWandererI + RotL64(aIngress, 57U)) + 5510483568496824130U;
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 35U)) + 15474152493495661876U) + aPhaseHOrbiterAssignSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aScatter, 19U)) + 16846339705130829195U) + aNonceWordI;
            aOrbiterH = ((aWandererD + RotL64(aIngress, 3U)) + RotL64(aCarry, 37U)) + 1289670576865739669U;
            aOrbiterK = (((aWandererG + RotL64(aCross, 11U)) + RotL64(aCarry, 11U)) + 18017354919647006944U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 8539685539928984921U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 3333721400836704048U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3745286323481400085U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 2261560416623815491U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 4377786131746816567U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9164777834392621157U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 18047393176583722719U) + aNonceWordP;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 8184724021940434631U) ^ aNonceWordC;
            aOrbiterH = RotL64((aOrbiterH * 9800116157750921119U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 10469895939183324807U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 14543391765109879223U;
            aOrbiterK = RotL64((aOrbiterK * 4817987697437667225U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 5757225781746158178U) + aNonceWordE;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 3539000495894022869U;
            aOrbiterJ = RotL64((aOrbiterJ * 1032298408884695925U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 11288971092707065923U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 2761384065186568294U;
            aOrbiterE = RotL64((aOrbiterE * 3323838837427471051U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 7120580145300417101U) + aNonceWordD;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 6977246291769372866U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15170353875184253779U), 19U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterE, 29U);
            aIngress = aIngress + (RotL64(aOrbiterF, 60U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 51U));
            aIngress = aIngress + RotL64(aOrbiterI, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aPrevious, 29U) + aOrbiterE) + RotL64(aOrbiterJ, 41U)) + RotL64(aCarry, 23U)) + aNonceWordM);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterH, 21U)) + aOrbiterJ) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 44U) + aOrbiterF) + RotL64(aOrbiterH, 51U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 3U) + aOrbiterE) + RotL64(aOrbiterI, 60U));
            aWandererK = aWandererK + (((RotL64(aIngress, 37U) + aOrbiterK) + RotL64(aOrbiterF, 3U)) + aNonceWordJ);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterK, 13U)) + aOrbiterJ) + aNonceWordK);
            aWandererD = aWandererD + (((((RotL64(aScatter, 19U) + RotL64(aOrbiterI, 29U)) + aOrbiterA) + RotL64(aCarry, 3U)) + aNonceWordL) + aPhaseHWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererF, 4U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 29U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 2
        // ingress from: aWorkLaneA, aSnowLaneC, aSnowLaneD, aInvestLaneC
        // ingress directions: aWorkLaneA forward forced, aSnowLaneC forward forced, aSnowLaneD forward forced, aInvestLaneC forward/backward random
        // cross from: aSnowLaneA, aSnowLaneB, aInvestLaneA
        // cross directions: aSnowLaneA backward forced, aSnowLaneB backward forced, aInvestLaneA backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 9370U)) & S_BLOCK1], 18U) ^ RotL64(aSnowLaneC[((aIndex + 6576U)) & S_BLOCK1], 37U));
            aIngress ^= (RotL64(aSnowLaneD[((aIndex + 10214U)) & S_BLOCK1], 57U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 6360U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 6934U)) & S_BLOCK1], 35U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 7344U)) & S_BLOCK1], 6U));
            aCross ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 6474U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 35U) ^ RotL64(aIngress, 6U)) ^ (RotL64(aCarry, 19U) + RotL64(aPrevious, 47U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterG = (aWandererK + RotL64(aScatter, 27U)) + 2915859148137000694U;
            aOrbiterH = ((aWandererH + RotL64(aIngress, 47U)) + 210680583721444425U) + aNonceWordC;
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 13U)) + 6668118118775650387U) + aNonceWordK;
            aOrbiterE = (((aWandererF + RotL64(aCross, 5U)) + RotL64(aCarry, 37U)) + 15794200818099010989U) + aPhaseHOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = (((aWandererC + RotL64(aPrevious, 35U)) + RotL64(aCarry, 13U)) + 6565076707062828369U) + aNonceWordA;
            aOrbiterJ = ((aWandererG + RotL64(aIngress, 20U)) + 16323164497808856719U) + aPhaseHOrbiterAssignSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = (((aWandererA + RotL64(aScatter, 41U)) + RotL64(aCarry, 57U)) + 7965435318816716560U) + aNonceWordI;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 7390281030573369017U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 2269738866911824875U;
            aOrbiterC = RotL64((aOrbiterC * 1198697877998135567U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 9664014216039993873U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 18284857398028357633U) ^ aNonceWordG;
            aOrbiterK = RotL64((aOrbiterK * 8402008251343393737U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 367667619795303009U) + aNonceWordF;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 7935945060956274197U;
            aOrbiterJ = RotL64((aOrbiterJ * 5481786693511955209U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 16683666162337789540U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 10655658270998102390U;
            aOrbiterG = RotL64((aOrbiterG * 15231596813382239841U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 8307037916581540297U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 3247742749860703524U;
            aOrbiterH = RotL64((aOrbiterH * 15052136713218656641U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 10446792483683818139U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 16374602929344972364U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12599903932725787599U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 2411334498322777183U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 1093701164116833765U;
            aOrbiterF = RotL64((aOrbiterF * 13129220206835381729U), 53U);
            //
            aIngress = RotL64(aOrbiterG, 3U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 29U));
            aIngress = aIngress + (RotL64(aOrbiterC, 53U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterK, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aCross, 13U) + RotL64(aOrbiterJ, 37U)) + aOrbiterG) + aNonceWordM);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterF, 19U)) + aOrbiterH) + aNonceWordH);
            aWandererH = aWandererH + (((RotL64(aIngress, 21U) + aOrbiterF) + RotL64(aOrbiterK, 47U)) + aNonceWordN);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterH, 12U)) + aOrbiterE);
            aWandererA = aWandererA + ((((RotL64(aIngress, 57U) + aOrbiterK) + RotL64(aOrbiterJ, 3U)) + RotL64(aCarry, 53U)) + aNonceWordD);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 35U) + aOrbiterK) + RotL64(aOrbiterC, 29U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aCross, 42U) + aOrbiterF) + RotL64(aOrbiterJ, 57U)) + RotL64(aCarry, 41U)) + aPhaseHWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + (RotL64(aWandererG, 53U) ^ aWandererK);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + RotL64(aWandererD, 30U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 15725U)) & S_BLOCK1], 57U) ^ RotL64(aSnowLaneA[((aIndex + 11796U)) & S_BLOCK1], 48U));
            aIngress ^= RotL64(aInvestLaneD[((aIndex + 13552U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15247U)) & S_BLOCK1], 37U) ^ RotL64(aSnowLaneC[((aIndex + 11264U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aPrevious, 43U) ^ RotL64(aCross, 27U)) + (RotL64(aCarry, 12U) ^ RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterI = (((aWandererC + RotL64(aIngress, 27U)) + RotL64(aCarry, 21U)) + 17912271996338180948U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 11U)) + 13259276608841847058U) + aPhaseHOrbiterAssignSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterG = ((aWandererB + RotL64(aCross, 5U)) + 16225936008657276089U) + aNonceWordD;
            aOrbiterE = (((aWandererH + RotL64(aScatter, 37U)) + RotL64(aCarry, 57U)) + 2243058962151834071U) + aNonceWordM;
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 53U)) + RotL64(aCarry, 37U)) + 10637439274127347861U;
            aOrbiterJ = (aWandererE + RotL64(aScatter, 46U)) + 15312219216405992627U;
            aOrbiterB = (aWandererK + RotL64(aIngress, 21U)) + 2393933972129878613U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 4327069337247976513U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 8307656353434167837U;
            aOrbiterG = RotL64((aOrbiterG * 11386588389133096705U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 17299145556933889336U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 14458100581172798164U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16543734663677070509U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 6410095654927998067U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 6168964796264687686U) ^ aNonceWordI;
            aOrbiterB = RotL64((aOrbiterB * 16218071040190475953U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 3667999465041020730U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 16021552859323602007U;
            aOrbiterE = RotL64((aOrbiterE * 6427266472526362663U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 12941668202330045095U) + aNonceWordH;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 4222032891850449934U;
            aOrbiterK = RotL64((aOrbiterK * 17292856787431308097U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 1346342592002730785U) + aNonceWordN;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 16860611785008118820U;
            aOrbiterI = RotL64((aOrbiterI * 384963420804756607U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 3193572711804730241U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 5866881282680588589U) ^ aNonceWordL;
            aOrbiterA = RotL64((aOrbiterA * 9226331800853634597U), 47U);
            //
            aIngress = RotL64(aOrbiterK, 3U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterE, 27U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 19U));
            aIngress = aIngress + RotL64(aOrbiterI, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aIngress, 58U) + aOrbiterE) + RotL64(aOrbiterK, 11U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterA, 20U)) + aOrbiterE) + aPhaseHWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 29U) + RotL64(aOrbiterB, 53U)) + aOrbiterA) + aNonceWordB);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterK, 35U)) + aOrbiterJ);
            aWandererB = aWandererB + (((RotL64(aCross, 35U) + aOrbiterA) + RotL64(aOrbiterI, 27U)) + RotL64(aCarry, 35U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterJ, 47U)) + aOrbiterI) + aNonceWordG);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 51U) + aOrbiterI) + RotL64(aOrbiterG, 41U)) + RotL64(aCarry, 51U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 5U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + RotL64(aWandererK, 52U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 4
        // ingress from: aExpandLaneA, aWorkLaneA, aInvestLaneB
        // ingress directions: aExpandLaneA forward forced, aWorkLaneA forward forced, aInvestLaneB forward/backward random
        // cross from: aWorkLaneB, aSnowLaneD
        // cross directions: aWorkLaneB backward forced, aSnowLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 21352U)) & S_BLOCK1], 14U) ^ RotL64(aWorkLaneA[((aIndex + 18446U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 17551U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20047U)) & S_BLOCK1], 35U) ^ RotL64(aSnowLaneD[((aIndex + 20364U)) & S_BLOCK1], 22U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aIngress, 24U)) ^ (RotL64(aCarry, 41U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterF = (aWandererA + RotL64(aIngress, 11U)) + 1888427424966603593U;
            aOrbiterH = ((aWandererC + RotL64(aScatter, 57U)) + 5436761445660415091U) + aNonceWordM;
            aOrbiterA = ((aWandererI + RotL64(aCross, 5U)) + RotL64(aCarry, 29U)) + 17322876217962143270U;
            aOrbiterC = (((aWandererD + RotL64(aPrevious, 23U)) + RotL64(aCarry, 5U)) + 9728299982740564979U) + aNonceWordP;
            aOrbiterD = ((aWandererF + RotL64(aCross, 34U)) + 301720335271716921U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = ((aWandererG + RotL64(aIngress, 51U)) + RotL64(aCarry, 41U)) + 8069685428854814396U;
            aOrbiterB = (((aWandererK + RotL64(aScatter, 43U)) + 1973715500949100991U) + aPhaseHOrbiterAssignSaltB[((aIndex + 8U)) & S_SALT1]) + aNonceWordH;
            //
            aOrbiterF = (((aOrbiterF + aOrbiterH) + 87666408799854155U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordK;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 12195436904339035245U;
            aOrbiterA = RotL64((aOrbiterA * 15427739165893738105U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 4578742069143400295U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 7828776048774876484U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4047964518501081039U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 17203146364542781833U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 16913369550858890466U;
            aOrbiterF = RotL64((aOrbiterF * 13534417587921978507U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 9632761514552265402U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 9106637671877341286U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9073709119482640391U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 15423680889126750876U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 6087310684583331882U;
            aOrbiterH = RotL64((aOrbiterH * 8964465129744898619U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 5420955876411796789U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 14166807419730848032U;
            aOrbiterD = RotL64((aOrbiterD * 442659738632823751U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 8118312450347026824U) + aNonceWordN;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 4253043584558403086U;
            aOrbiterB = RotL64((aOrbiterB * 5651748455190536467U), 37U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterH, 41U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 11U));
            aIngress = aIngress + (RotL64(aOrbiterB, 35U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterE, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterH, 29U)) + aOrbiterF) + aNonceWordF);
            aWandererI = aWandererI + ((RotL64(aCross, 19U) + aOrbiterA) + RotL64(aOrbiterB, 21U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 29U) + aOrbiterH) + RotL64(aOrbiterB, 43U)) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterA, 13U)) + aOrbiterF) + RotL64(aCarry, 11U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 43U) + aOrbiterF) + RotL64(aOrbiterD, 51U)) + aNonceWordB);
            aWandererA = aWandererA + (((RotL64(aCross, 53U) + aOrbiterE) + RotL64(aOrbiterH, 35U)) + RotL64(aCarry, 23U));
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 4U) + RotL64(aOrbiterC, 6U)) + aOrbiterB) + aNonceWordA) + aPhaseHWandererUpdateSaltE[((aIndex + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererI, 4U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + RotL64(aWandererA, 35U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 24001U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((aIndex + 22393U)) & S_BLOCK1], 58U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 22846U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 21884U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneA[((aIndex + 23949U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 35U)) + (RotL64(aIngress, 57U) + RotL64(aCross, 6U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 43U)) + 4259993311776766595U) + aPhaseHOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = ((aWandererD + RotL64(aCross, 27U)) + RotL64(aCarry, 19U)) + 2857813330021126753U;
            aOrbiterH = (((aWandererG + RotL64(aPrevious, 60U)) + RotL64(aCarry, 53U)) + 1345396841329442896U) + aNonceWordB;
            aOrbiterA = ((aWandererE + RotL64(aScatter, 21U)) + 320992148982301024U) + aNonceWordJ;
            aOrbiterB = ((aWandererF + RotL64(aCross, 5U)) + 5619109532065293074U) + aNonceWordK;
            aOrbiterE = ((aWandererH + RotL64(aIngress, 53U)) + RotL64(aCarry, 35U)) + 10380157329426706345U;
            aOrbiterI = (((aWandererI + RotL64(aScatter, 13U)) + 12449831150625409695U) + aPhaseHOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1]) + aNonceWordF;
            //
            aOrbiterC = (((aOrbiterC + aOrbiterJ) + 7847096607042268396U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordN;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 11707184096803214678U) ^ aNonceWordL;
            aOrbiterH = RotL64((aOrbiterH * 1959476948106553973U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 9893643746186827088U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 333687403830908774U;
            aOrbiterC = RotL64((aOrbiterC * 17911256836121454271U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 13837360705077441580U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 4367119682175710689U) ^ aNonceWordA;
            aOrbiterA = RotL64((aOrbiterA * 10295744669174603401U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 1193493435041306784U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 15062951612027370606U;
            aOrbiterB = RotL64((aOrbiterB * 2509383510565136549U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 16000173839235429105U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 15294482444605409961U) ^ aNonceWordP;
            aOrbiterE = RotL64((aOrbiterE * 1031800997944302665U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 5720749055549773527U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 17248674962996093668U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15730637462755795591U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 16956840483882091059U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 9637715107943515594U;
            aOrbiterI = RotL64((aOrbiterI * 8878362378343603463U), 57U);
            //
            aIngress = RotL64(aOrbiterI, 3U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 13U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 41U));
            aIngress = aIngress + RotL64(aOrbiterH, 34U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 3U) + aOrbiterA) + RotL64(aOrbiterB, 5U));
            aWandererI = aWandererI + ((((RotL64(aIngress, 19U) + RotL64(aOrbiterA, 57U)) + aOrbiterJ) + RotL64(aCarry, 3U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 29U) + aOrbiterC) + RotL64(aOrbiterI, 41U));
            aWandererG = aWandererG + (((RotL64(aCross, 47U) + aOrbiterC) + RotL64(aOrbiterJ, 51U)) + RotL64(aCarry, 53U));
            aWandererD = aWandererD ^ ((((RotL64(aScatter, 13U) + RotL64(aOrbiterE, 18U)) + aOrbiterJ) + aNonceWordI) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 56U) + aOrbiterH) + RotL64(aOrbiterC, 35U)) + aNonceWordH);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterE, 27U)) + aOrbiterI) + aNonceWordO);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 10U));
            aCarry = aCarry + RotL64(aWandererD, 27U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 6
        // ingress from: aExpandLaneC, aExpandLaneA, aFireLaneD
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aFireLaneD forward/backward random
        // cross from: aExpandLaneB, aSnowLaneB
        // cross directions: aExpandLaneB backward forced, aSnowLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 31079U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((aIndex + 30779U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 28766U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31768U)) & S_BLOCK1], 35U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 30045U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCross, 18U) ^ RotL64(aIngress, 57U)) + (RotL64(aCarry, 37U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterK = (((aWandererA + RotL64(aCross, 21U)) + RotL64(aCarry, 29U)) + 10881271196314989997U) + aNonceWordK;
            aOrbiterC = ((aWandererC + RotL64(aScatter, 6U)) + 6406461249988567558U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterG = (aWandererH + RotL64(aIngress, 53U)) + 17255067918280095959U;
            aOrbiterD = (((aWandererD + RotL64(aPrevious, 29U)) + RotL64(aCarry, 5U)) + 16690850682497718411U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = (aWandererB + RotL64(aScatter, 13U)) + 5576201059361086866U;
            aOrbiterE = (aWandererK + RotL64(aPrevious, 35U)) + 11991259685693687554U;
            aOrbiterF = (((aWandererI + RotL64(aIngress, 41U)) + RotL64(aCarry, 57U)) + 14652535244217836909U) + aNonceWordA;
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 1701789037170782122U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 953429054903473833U;
            aOrbiterG = RotL64((aOrbiterG * 13482379459700651427U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 12064513610469714211U) + aNonceWordG;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 7993881398822002424U;
            aOrbiterI = RotL64((aOrbiterI * 11572884842788918377U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 14421313768013320050U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 11112386845630998889U) ^ aNonceWordO;
            aOrbiterE = RotL64((aOrbiterE * 11771526352030371669U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 17069630896535699015U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 3308240081138623373U;
            aOrbiterD = RotL64((aOrbiterD * 10449509484417835159U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 17615529807112933619U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 11782807146851563541U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12992075832343669221U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 14401645829607611983U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 6736397344219993532U;
            aOrbiterK = RotL64((aOrbiterK * 1667287547938175641U), 11U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterG) + 6446974060524700550U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordN;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 7840991992443308254U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6891023544882740107U), 29U);
            //
            aIngress = RotL64(aOrbiterE, 47U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterD, 13U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterG, 28U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterI, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aIngress, 51U) + aOrbiterE) + RotL64(aOrbiterG, 26U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 19U) + aOrbiterG) + RotL64(aOrbiterD, 41U)) + aPhaseHWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 13U) + aOrbiterD) + RotL64(aOrbiterI, 47U)) + RotL64(aCarry, 57U)) + aPhaseHWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterC, 5U)) + aOrbiterF) + aNonceWordE);
            aWandererH = aWandererH + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterC, 19U)) + aOrbiterK) + RotL64(aCarry, 27U)) + aNonceWordI);
            aWandererC = aWandererC ^ ((RotL64(aCross, 3U) + aOrbiterI) + RotL64(aOrbiterE, 53U));
            aWandererA = aWandererA + (((RotL64(aIngress, 58U) + aOrbiterK) + RotL64(aOrbiterF, 13U)) + aNonceWordL);
            //
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + (RotL64(aWandererB, 56U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererH, 21U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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

void TwistExpander_WaterPolo_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltC;
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
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC;
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
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF;
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 45U)) & W_KEY1], 3U) ^ RotL64(aKeyRowReadB[((aIndex + 1930U)) & W_KEY1], 30U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 2339U)) & W_KEY1], 51U) ^ RotL64(mSource[((aIndex + 1906U)) & S_BLOCK1], 6U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 41U) ^ RotL64(aCross, 6U)) ^ (RotL64(aPrevious, 19U) + RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = (aWandererB + RotL64(aScatter, 37U)) + 3236820517816085022U;
            aOrbiterD = (aWandererA + RotL64(aIngress, 53U)) + 741288875914097926U;
            aOrbiterC = (aWandererK + RotL64(aCross, 18U)) + 8417246926007729580U;
            aOrbiterH = (aWandererD + RotL64(aPrevious, 29U)) + 9715717805774537170U;
            aOrbiterK = ((aWandererJ + RotL64(aCross, 11U)) + RotL64(aCarry, 3U)) + 14360243844821619482U;
            aOrbiterF = (((aWandererH + RotL64(aScatter, 57U)) + RotL64(aCarry, 23U)) + 10760908100206775334U) + aPhaseAOrbiterAssignSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = (aWandererG + RotL64(aIngress, 41U)) + 3434641779946167811U;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 48U)) + RotL64(aCarry, 53U)) + 7885568822756234567U;
            aOrbiterB = ((aWandererI + RotL64(aCross, 5U)) + 3041563437672051294U) + aPhaseAOrbiterAssignSaltD[((aIndex + 28U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 15761355327564963516U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 1158633562785937421U;
            aOrbiterC = RotL64((aOrbiterC * 15511324886867188235U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 9338581575871970653U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 9172038894262857354U;
            aOrbiterF = RotL64((aOrbiterF * 3110871165285625807U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 14653924713599790081U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 3854497592598563309U;
            aOrbiterH = RotL64((aOrbiterH * 11737111068815795303U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 16286980180327600557U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 5092583772591249756U;
            aOrbiterK = RotL64((aOrbiterK * 13955105624639442903U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 4288397994175567333U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 15584236478994873104U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1860480595862755379U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 5557463939827483792U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 2659814275753280856U;
            aOrbiterI = RotL64((aOrbiterI * 17702430405693184643U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 6941807963525063449U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 2040598555191211307U;
            aOrbiterA = RotL64((aOrbiterA * 14750544987531722765U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 347572666231116258U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 779304821185302523U;
            aOrbiterB = RotL64((aOrbiterB * 14180254150318109855U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 10632524582873079742U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 9761308771280517212U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13926235411726048921U), 29U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterD, 57U);
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 41U));
            aIngress = aIngress + (RotL64(aOrbiterI, 10U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterF, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aScatter, 23U) + aOrbiterA) + RotL64(aOrbiterF, 52U)) + RotL64(aCarry, 5U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 35U) + aOrbiterA) + RotL64(aOrbiterI, 11U)) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aCross, 60U) + aOrbiterD) + RotL64(aOrbiterK, 39U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 13U) + aOrbiterK) + RotL64(aOrbiterI, 47U));
            aWandererI = aWandererI + ((RotL64(aCross, 27U) + RotL64(aOrbiterC, 27U)) + aOrbiterB);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 47U) + aOrbiterK) + RotL64(aOrbiterH, 3U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterB, 43U)) + aOrbiterG) + RotL64(aCarry, 21U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 19U) + aOrbiterC) + RotL64(aOrbiterH, 18U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 6U) + aOrbiterK) + RotL64(aOrbiterB, 57U)) + aPhaseAWandererUpdateSaltA[((aIndex + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 50U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererJ);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 3532U)) & S_BLOCK1], 5U) ^ RotL64(aKeyRowReadA[((aIndex + 4020U)) & W_KEY1], 22U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 4801U)) & W_KEY1], 47U) ^ RotL64(mSource[((aIndex + 4446U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 12U) + RotL64(aCarry, 39U)) ^ (RotL64(aIngress, 27U) ^ RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = (aWandererK + RotL64(aCross, 47U)) + 7651355040951791298U;
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 19U)) + RotL64(aCarry, 13U)) + 13988210277931659312U;
            aOrbiterE = (aWandererC + RotL64(aIngress, 56U)) + 9846849412579537783U;
            aOrbiterD = (aWandererF + RotL64(aScatter, 41U)) + 12746719939495876158U;
            aOrbiterI = (aWandererD + RotL64(aPrevious, 5U)) + 11498066185182895284U;
            aOrbiterF = (aWandererA + RotL64(aIngress, 29U)) + 11101058955193080232U;
            aOrbiterK = (((aWandererG + RotL64(aCross, 23U)) + RotL64(aCarry, 29U)) + 15513734459555672046U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = (((aWandererB + RotL64(aScatter, 13U)) + RotL64(aCarry, 5U)) + 15711108675349394643U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = (aWandererI + RotL64(aIngress, 60U)) + 4771231759949468556U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 11449258010811305256U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 17036938391509986723U;
            aOrbiterE = RotL64((aOrbiterE * 7411466953205347639U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 6999245666776654250U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 2106819066263369528U;
            aOrbiterI = RotL64((aOrbiterI * 13005885810757743129U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 12716183358903477216U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 16752724547046059889U;
            aOrbiterF = RotL64((aOrbiterF * 11475905692393034141U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 17623077680983093163U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 6726003022297274986U;
            aOrbiterK = RotL64((aOrbiterK * 14709385877103232653U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 2842410225096524740U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 9235178377537910514U;
            aOrbiterB = RotL64((aOrbiterB * 11813751114775673845U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 2619888019860844610U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 6295481948199619613U;
            aOrbiterG = RotL64((aOrbiterG * 15429161806953951205U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 9724921158061115570U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 4070976180958458679U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6080566609081811453U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 5864247978960125554U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 7771249710071026757U;
            aOrbiterH = RotL64((aOrbiterH * 4787660062590737657U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 15006900854988166845U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 2755659268987119046U;
            aOrbiterA = RotL64((aOrbiterA * 8043939381186802359U), 51U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterI, 38U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 35U));
            aIngress = aIngress + (RotL64(aOrbiterB, 47U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 19U));
            aIngress = aIngress + RotL64(aOrbiterD, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aIngress, 47U) + aOrbiterD) + RotL64(aOrbiterF, 60U)) + RotL64(aCarry, 35U)) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 3U) + aOrbiterI) + RotL64(aOrbiterK, 13U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 56U) + aOrbiterG) + RotL64(aOrbiterH, 29U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterK, 47U)) + aOrbiterG);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterI, 3U)) + aOrbiterG) + RotL64(aCarry, 43U)) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 19U) + aOrbiterD) + RotL64(aOrbiterI, 51U));
            aWandererA = aWandererA + ((RotL64(aScatter, 43U) + RotL64(aOrbiterE, 43U)) + aOrbiterB);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 51U) + aOrbiterI) + RotL64(aOrbiterA, 38U));
            aWandererB = aWandererB + ((RotL64(aCross, 60U) + aOrbiterK) + RotL64(aOrbiterE, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 40U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererC);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 37U));
            aCarry = aCarry + RotL64(aWandererB, 47U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 7227U)) & S_BLOCK1], 19U) ^ RotL64(aKeyRowReadB[((aIndex + 7715U)) & W_KEY1], 34U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 7278U)) & W_KEY1], 28U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 7666U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 8120U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 43U) + RotL64(aCarry, 60U)) ^ (RotL64(aCross, 29U) + RotL64(aPrevious, 13U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = (aWandererK + RotL64(aCross, 13U)) + 14214886793361825363U;
            aOrbiterD = (aWandererJ + RotL64(aIngress, 50U)) + 17267959031078766320U;
            aOrbiterA = ((aWandererA + RotL64(aScatter, 29U)) + 16436067429484887644U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterG = (((aWandererH + RotL64(aPrevious, 39U)) + RotL64(aCarry, 21U)) + 9885951769332633820U) + aPhaseAOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = (aWandererG + RotL64(aCross, 23U)) + 12971711341813893304U;
            aOrbiterF = ((aWandererD + RotL64(aIngress, 5U)) + RotL64(aCarry, 35U)) + 199970353398450154U;
            aOrbiterC = ((aWandererI + RotL64(aScatter, 19U)) + RotL64(aCarry, 11U)) + 1237341696444162094U;
            aOrbiterK = (aWandererB + RotL64(aPrevious, 46U)) + 7991128854417613360U;
            aOrbiterB = (aWandererE + RotL64(aScatter, 35U)) + 14809029847149045833U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 2559509556915775947U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 14336829730147834160U;
            aOrbiterA = RotL64((aOrbiterA * 15103242520064900873U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 8853631886733610440U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 13346159398673246914U;
            aOrbiterI = RotL64((aOrbiterI * 13660497151446983393U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 12121095718571872976U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 16239781125815589804U;
            aOrbiterC = RotL64((aOrbiterC * 5157009090454962231U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 9051377033794324106U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 13805815136723461780U;
            aOrbiterF = RotL64((aOrbiterF * 571129481747181357U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 14849157800322754413U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 18116651528452542634U;
            aOrbiterD = RotL64((aOrbiterD * 3638480428016835537U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 4105057226952948599U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 5911714320560994391U;
            aOrbiterK = RotL64((aOrbiterK * 1796514171654961389U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 4439149331729987587U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 10278532228230163632U;
            aOrbiterB = RotL64((aOrbiterB * 17428224919864716517U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 2342456582668741750U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 2360578572554664800U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1108428466956691925U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 12132934875391401246U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 17213278726790245812U;
            aOrbiterE = RotL64((aOrbiterE * 11904899990681410419U), 3U);
            //
            aIngress = RotL64(aOrbiterK, 27U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterB, 53U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 39U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 35U));
            aIngress = aIngress + RotL64(aOrbiterD, 14U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aPrevious, 29U) + aOrbiterI) + RotL64(aOrbiterG, 38U)) + RotL64(aCarry, 21U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 18U) + aOrbiterC) + RotL64(aOrbiterB, 23U));
            aWandererE = aWandererE + (((RotL64(aIngress, 23U) + RotL64(aOrbiterC, 19U)) + aOrbiterE) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 43U) + aOrbiterD) + RotL64(aOrbiterE, 13U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 39U) + aOrbiterF) + RotL64(aOrbiterK, 57U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 57U) + aOrbiterI) + RotL64(aOrbiterA, 43U)) + aPhaseAWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 3U) + aOrbiterF) + RotL64(aOrbiterG, 51U)) + RotL64(aCarry, 47U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 14U) + aOrbiterA) + RotL64(aOrbiterK, 6U));
            aWandererK = aWandererK + ((RotL64(aCross, 35U) + aOrbiterK) + RotL64(aOrbiterD, 47U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + (RotL64(aWandererK, 60U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 53U));
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererB, 29U);
            aCarry = aCarry + RotL64(aIngress, 26U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 8644U)) & S_BLOCK1], 12U) ^ RotL64(aKeyRowReadB[((aIndex + 8261U)) & W_KEY1], 21U));
            aIngress ^= (RotL64(mSource[((aIndex + 8860U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 8700U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 10255U)) & W_KEY1], 44U) ^ RotL64(aWorkLaneB[((aIndex + 10830U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 60U) ^ RotL64(aIngress, 11U)) ^ (RotL64(aCross, 29U) + RotL64(aPrevious, 43U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = (aWandererB + RotL64(aCross, 30U)) + 1393781663398437180U;
            aOrbiterG = ((aWandererG + RotL64(aPrevious, 47U)) + RotL64(aCarry, 5U)) + 17414594746688585273U;
            aOrbiterK = (aWandererI + RotL64(aIngress, 23U)) + 2823888497053071250U;
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 19U)) + RotL64(aCarry, 39U)) + 17032631958617884859U;
            aOrbiterF = (aWandererC + RotL64(aCross, 39U)) + 15222697630461125019U;
            aOrbiterC = ((aWandererE + RotL64(aIngress, 53U)) + RotL64(aCarry, 19U)) + 15737414920751551780U;
            aOrbiterJ = (aWandererK + RotL64(aScatter, 13U)) + 1357196111055783001U;
            aOrbiterH = ((aWandererH + RotL64(aPrevious, 5U)) + 5315122321649251691U) + aPhaseBOrbiterAssignSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterA = ((aWandererF + RotL64(aCross, 58U)) + 7893744655508595974U) + aPhaseBOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 16721939414324611738U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 3444375866323610848U;
            aOrbiterK = RotL64((aOrbiterK * 10874157227815775661U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 1825716513674511632U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 15582066843912467318U;
            aOrbiterC = RotL64((aOrbiterC * 12765146555943757373U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 15673590949193923915U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 13887365046280406413U;
            aOrbiterJ = RotL64((aOrbiterJ * 3169061375011420121U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 12730414371734709356U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 4819112390640821927U;
            aOrbiterD = RotL64((aOrbiterD * 8782547948627685451U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 3089925954422937464U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 7180179304678622530U;
            aOrbiterH = RotL64((aOrbiterH * 16118051565147747413U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 17030269962085008657U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 6675917351883004046U;
            aOrbiterG = RotL64((aOrbiterG * 14134335325316949687U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 12572022803491077491U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 2801421744689267375U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 315045745990934023U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 4335148696780313055U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 12526298573395110141U;
            aOrbiterE = RotL64((aOrbiterE * 11276803410698178607U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 6984239833558496091U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 12195433952105336808U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8642600547427664495U), 23U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterA, 6U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterH, 53U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterG, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterH, 57U)) + aOrbiterA);
            aWandererK = aWandererK + (((RotL64(aCross, 43U) + aOrbiterH) + RotL64(aOrbiterD, 19U)) + aPhaseBWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 56U) + RotL64(aOrbiterG, 46U)) + aOrbiterF);
            aWandererB = aWandererB + ((RotL64(aScatter, 19U) + aOrbiterJ) + RotL64(aOrbiterE, 23U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterH, 5U)) + aOrbiterF);
            aWandererF = aWandererF + ((((RotL64(aCross, 29U) + RotL64(aOrbiterD, 51U)) + aOrbiterK) + RotL64(aCarry, 27U)) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 36U) + aOrbiterC) + RotL64(aOrbiterE, 29U));
            aWandererI = aWandererI + (((RotL64(aScatter, 5U) + aOrbiterF) + RotL64(aOrbiterE, 12U)) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 47U) + aOrbiterD) + RotL64(aOrbiterF, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 58U) ^ aWandererJ);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererC);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + RotL64(aWandererB, 3U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 11727U)) & S_BLOCK1], 47U) ^ RotL64(aKeyRowReadA[((aIndex + 11213U)) & W_KEY1], 27U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 13496U)) & W_KEY1], 39U) ^ RotL64(mSource[((aIndex + 11896U)) & S_BLOCK1], 18U));
            aIngress ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 11288U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11959U)) & S_BLOCK1], 27U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 13312U)) & S_BLOCK1], 40U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 37U) + RotL64(aCarry, 3U)) ^ (RotL64(aPrevious, 53U) + RotL64(aCross, 24U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = ((aWandererC + RotL64(aIngress, 51U)) + RotL64(aCarry, 13U)) + 964165145848253292U;
            aOrbiterH = ((aWandererD + RotL64(aCross, 34U)) + 10645976767204934746U) + aPhaseBOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 3U)) + RotL64(aCarry, 47U)) + 8241612229349212650U;
            aOrbiterA = (aWandererI + RotL64(aScatter, 43U)) + 4159196033256913347U;
            aOrbiterJ = (aWandererG + RotL64(aCross, 57U)) + 7194795864620233507U;
            aOrbiterE = ((aWandererA + RotL64(aScatter, 11U)) + RotL64(aCarry, 23U)) + 7638928444536778384U;
            aOrbiterI = ((aWandererE + RotL64(aIngress, 19U)) + 11819105916503968109U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = (aWandererK + RotL64(aPrevious, 47U)) + 18052213302858186237U;
            aOrbiterG = (aWandererJ + RotL64(aIngress, 24U)) + 8663575313970041570U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 16644136720439299786U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 16930316530442679864U;
            aOrbiterB = RotL64((aOrbiterB * 2650922074098320859U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 16251107616988250593U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 7171986193609401665U;
            aOrbiterJ = RotL64((aOrbiterJ * 3543709971414550087U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 17885046834432626644U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 7757069274715713557U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15766885299397923879U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 2212805322061155615U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 6368539134638838822U;
            aOrbiterD = RotL64((aOrbiterD * 13383744883433594259U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 5264326094252925613U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 6126345334815012938U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17180934809764905307U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 13826731214018407061U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 6621261811613643620U;
            aOrbiterH = RotL64((aOrbiterH * 2823596473596114171U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 5964406317285863781U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 2167324450276308078U;
            aOrbiterF = RotL64((aOrbiterF * 1098346374733634905U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 16740710162977859724U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 8236083581048717923U;
            aOrbiterG = RotL64((aOrbiterG * 4364887787000704039U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 13967473987446124012U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 5136051802217149813U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13997246005108872883U), 23U);
            //
            aIngress = RotL64(aOrbiterE, 10U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 19U));
            aIngress = aIngress + (RotL64(aOrbiterF, 39U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 35U));
            aIngress = aIngress + RotL64(aOrbiterA, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aIngress, 58U) + aOrbiterG) + RotL64(aOrbiterH, 51U));
            aWandererK = aWandererK + (((RotL64(aScatter, 27U) + RotL64(aOrbiterI, 11U)) + aOrbiterH) + RotL64(aCarry, 43U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterD, 30U)) + aOrbiterJ) + aPhaseBWandererUpdateSaltB[((aIndex + 4U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 51U) + RotL64(aOrbiterF, 23U)) + aOrbiterB) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 35U) + aOrbiterI) + RotL64(aOrbiterA, 47U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterJ, 5U)) + aOrbiterA);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterI, 19U)) + aOrbiterB);
            aWandererG = aWandererG + (((RotL64(aCross, 47U) + RotL64(aOrbiterI, 36U)) + aOrbiterE) + RotL64(aCarry, 3U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 10U) + aOrbiterF) + RotL64(aOrbiterJ, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererA);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 10U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 27U));
            aCarry = aCarry + RotL64(aWandererG, 47U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 16327U)) & S_BLOCK1], 36U) ^ RotL64(aInvestLaneA[((aIndex + 14364U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 16271U)) & W_KEY1], 21U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 14576U)) & W_KEY1], 13U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 16125U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 16012U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 14563U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 19U) ^ RotL64(aIngress, 44U)) + (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 60U)) + RotL64(aCarry, 11U)) + 8988572360732005217U;
            aOrbiterF = (aWandererH + RotL64(aIngress, 39U)) + 17889613225105985335U;
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 47U)) + RotL64(aCarry, 21U)) + 15563478320513948626U;
            aOrbiterA = (aWandererE + RotL64(aCross, 19U)) + 3441351228410524816U;
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 5U)) + 4425592689451435346U) + aPhaseBOrbiterAssignSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterJ = (aWandererB + RotL64(aScatter, 56U)) + 12733160231627305928U;
            aOrbiterG = (aWandererF + RotL64(aCross, 35U)) + 3574152157304607854U;
            aOrbiterD = (((aWandererK + RotL64(aIngress, 43U)) + RotL64(aCarry, 41U)) + 15167631896729808783U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = (aWandererG + RotL64(aCross, 23U)) + 15822667973915417055U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 17181685481076577637U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 9979204751408873468U;
            aOrbiterE = RotL64((aOrbiterE * 8244434774754786565U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 1334240485667164762U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 9190066751460137016U;
            aOrbiterH = RotL64((aOrbiterH * 14585141844653660363U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 15465215829109246336U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 2305208282453624419U;
            aOrbiterF = RotL64((aOrbiterF * 10257861974108363283U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 16951510027310993926U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 11117938943423526901U;
            aOrbiterJ = RotL64((aOrbiterJ * 7805486716716924787U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 12461379120662979432U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 11719697049048823897U;
            aOrbiterA = RotL64((aOrbiterA * 14880996802304818757U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 6843357278142933570U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 12727898578324702374U;
            aOrbiterC = RotL64((aOrbiterC * 9786435451654365097U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 18127999660067652233U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 11754709060558683082U;
            aOrbiterD = RotL64((aOrbiterD * 12798744012150745847U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 16940151146420516184U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 12924950783056761895U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8898170377271926745U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 14829713915929878471U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 840466047621042565U;
            aOrbiterB = RotL64((aOrbiterB * 10748511630509529489U), 43U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterD, 47U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 12U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 23U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterA, 27U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterH, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterC, 6U)) + aOrbiterF);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 34U) + RotL64(aOrbiterF, 47U)) + aOrbiterH) + RotL64(aCarry, 27U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 27U) + aOrbiterG) + RotL64(aOrbiterH, 19U));
            aWandererB = aWandererB + ((((RotL64(aCross, 19U) + RotL64(aOrbiterJ, 27U)) + aOrbiterD) + RotL64(aCarry, 47U)) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterA, 13U)) + aOrbiterH);
            aWandererH = aWandererH + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterA, 43U)) + aOrbiterJ);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 10U) + aOrbiterE) + RotL64(aOrbiterB, 51U)) + aPhaseBWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 39U) + aOrbiterF) + RotL64(aOrbiterB, 39U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterE, 60U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 34U));
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererA, 13U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererH, 53U);
            aCarry = aCarry + RotL64(aIngress, 38U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 18852U)) & S_BLOCK1], 58U) ^ RotL64(aKeyRowReadA[((aIndex + 18651U)) & W_KEY1], 39U));
            aIngress ^= (RotL64(mSource[((aIndex + 17760U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 18236U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 16899U)) & W_KEY1], 6U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 18753U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 16640U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 37U) + RotL64(aCarry, 23U)) ^ (RotL64(aCross, 4U) ^ RotL64(aPrevious, 51U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = (aWandererD + RotL64(aCross, 53U)) + 10805654776556844351U;
            aOrbiterH = (aWandererA + RotL64(aPrevious, 18U)) + 582794182442795335U;
            aOrbiterJ = (aWandererG + RotL64(aScatter, 13U)) + 2858343650974681068U;
            aOrbiterK = (aWandererJ + RotL64(aIngress, 29U)) + 8189584049022064284U;
            aOrbiterF = ((aWandererI + RotL64(aScatter, 43U)) + 1565100751996962893U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = (((aWandererC + RotL64(aPrevious, 47U)) + RotL64(aCarry, 35U)) + 8062028016947611891U) + aPhaseCOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = ((aWandererK + RotL64(aIngress, 36U)) + RotL64(aCarry, 3U)) + 8280504280578451745U;
            aOrbiterI = ((aWandererF + RotL64(aCross, 23U)) + RotL64(aCarry, 57U)) + 11326869194491655350U;
            aOrbiterE = (aWandererH + RotL64(aIngress, 3U)) + 1671695656567777163U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 2349843105293943452U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 13015545152052004254U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1316662811685429983U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 16703354404749291869U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 8713231044374305801U;
            aOrbiterD = RotL64((aOrbiterD * 9242480982197688625U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 11118401674497783533U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 14857556493734710364U;
            aOrbiterH = RotL64((aOrbiterH * 3452566050389715195U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 12953419670951660965U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 12666121730825089017U;
            aOrbiterI = RotL64((aOrbiterI * 14049925256934142519U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 11075249639473053423U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 9374217688244187867U;
            aOrbiterE = RotL64((aOrbiterE * 5261156325627117877U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 17608340953291367867U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 13159437499327086340U;
            aOrbiterA = RotL64((aOrbiterA * 4882100944453534805U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 4304700511322366815U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 10172544755256706767U;
            aOrbiterK = RotL64((aOrbiterK * 4013006212154771797U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 17340067939877432472U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 14130447570008179105U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8178075071208718915U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 2652532710498072378U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 10384945384238518296U;
            aOrbiterG = RotL64((aOrbiterG * 17137694272394304045U), 57U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterE, 21U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 27U));
            aIngress = aIngress + (RotL64(aOrbiterI, 35U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterK, 4U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 60U) + aOrbiterI) + RotL64(aOrbiterD, 35U));
            aWandererH = aWandererH + (((RotL64(aIngress, 3U) + aOrbiterG) + RotL64(aOrbiterA, 48U)) + aPhaseCWandererUpdateSaltA[((aIndex + 20U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterH, 23U)) + aOrbiterE);
            aWandererI = aWandererI + (((RotL64(aScatter, 37U) + aOrbiterE) + RotL64(aOrbiterG, 29U)) + RotL64(aCarry, 41U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 53U) + aOrbiterH) + RotL64(aOrbiterD, 41U));
            aWandererK = aWandererK + ((RotL64(aIngress, 43U) + aOrbiterJ) + RotL64(aOrbiterD, 52U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 30U) + RotL64(aOrbiterH, 57U)) + aOrbiterK);
            aWandererD = aWandererD + ((((RotL64(aCross, 19U) + RotL64(aOrbiterJ, 5U)) + aOrbiterF) + RotL64(aCarry, 51U)) + aPhaseCWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterE, 19U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + (RotL64(aWandererD, 18U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 41U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererF, 21U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 20751U)) & S_BLOCK1], 19U) ^ RotL64(mSource[((aIndex + 20099U)) & S_BLOCK1], 10U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 21382U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21049U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 20136U)) & W_KEY1], 35U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 19351U)) & W_KEY1], 58U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 20217U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19749U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 24U) + RotL64(aCarry, 41U)) ^ (RotL64(aIngress, 53U) + RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = (aWandererB + RotL64(aIngress, 47U)) + 4752759164691497960U;
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 29U)) + RotL64(aCarry, 3U)) + 12088872623537639782U;
            aOrbiterF = ((aWandererA + RotL64(aScatter, 36U)) + RotL64(aCarry, 11U)) + 3734943577379734227U;
            aOrbiterC = (((aWandererI + RotL64(aCross, 21U)) + RotL64(aCarry, 43U)) + 8854778183012444234U) + aPhaseCOrbiterAssignSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = (aWandererE + RotL64(aPrevious, 11U)) + 16948373492893967275U;
            aOrbiterH = (aWandererC + RotL64(aCross, 51U)) + 7962415690046184385U;
            aOrbiterD = (aWandererH + RotL64(aIngress, 5U)) + 1872682375669714454U;
            aOrbiterB = (aWandererG + RotL64(aScatter, 56U)) + 7776801806943853566U;
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 43U)) + 16665439117257230732U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 11088186766134265676U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 10850237991780969350U;
            aOrbiterF = RotL64((aOrbiterF * 7547414856143095121U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 6464817712131305812U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 244557182884209844U;
            aOrbiterI = RotL64((aOrbiterI * 2394270354887582889U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 13261563971157415841U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 2323811103717827362U;
            aOrbiterD = RotL64((aOrbiterD * 11483723582415081925U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 12338803568475493422U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 2811342930111104982U;
            aOrbiterH = RotL64((aOrbiterH * 5020981755203607757U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 5554497011738996057U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 12712169745460598698U;
            aOrbiterE = RotL64((aOrbiterE * 1985586486150377769U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 17415058661427002973U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 9430421222715343818U;
            aOrbiterA = RotL64((aOrbiterA * 10321140659099470811U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 3926618548181233180U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 6172453297026957838U;
            aOrbiterJ = RotL64((aOrbiterJ * 1161551082037835233U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 8633288765997226004U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 17270881130844274342U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8888559940161770791U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 12232950994807835262U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 15352600312956742750U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6140396356904933003U), 3U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterI, 20U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 23U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 53U));
            aIngress = aIngress + RotL64(aOrbiterF, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aScatter, 3U) + aOrbiterB) + RotL64(aOrbiterF, 51U));
            aWandererF = aWandererF + (((RotL64(aCross, 51U) + aOrbiterB) + RotL64(aOrbiterC, 28U)) + RotL64(aCarry, 37U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 12U) + aOrbiterH) + RotL64(aOrbiterJ, 35U));
            aWandererA = aWandererA + ((RotL64(aIngress, 57U) + aOrbiterC) + RotL64(aOrbiterF, 57U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterD, 39U)) + aOrbiterC);
            aWandererH = aWandererH + (((RotL64(aScatter, 23U) + RotL64(aOrbiterH, 47U)) + aOrbiterD) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 43U) + aOrbiterE) + RotL64(aOrbiterA, 43U)) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 19U) + aOrbiterA) + RotL64(aOrbiterH, 14U)) + RotL64(aCarry, 13U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 28U) + RotL64(aOrbiterB, 23U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + (RotL64(aWandererK, 29U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 44U));
            aCarry = aCarry + RotL64(aWandererB, 13U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 23359U)) & S_BLOCK1], 5U) ^ RotL64(aKeyRowReadA[((aIndex + 24223U)) & W_KEY1], 21U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 23773U)) & W_KEY1], 30U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 24253U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 24309U)) & S_BLOCK1], 23U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 23729U)) & S_BLOCK1], 51U));
            aCross ^= (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 23078U)) & S_BLOCK1], 5U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 23842U)) & S_BLOCK1], 36U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 35U) + RotL64(aCarry, 53U)) ^ (RotL64(aCross, 3U) ^ RotL64(aPrevious, 18U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = (aWandererB + RotL64(aScatter, 39U)) + 2786079456995203065U;
            aOrbiterI = (aWandererG + RotL64(aCross, 58U)) + 7237256119153857253U;
            aOrbiterK = (aWandererF + RotL64(aPrevious, 3U)) + 9310834010563647604U;
            aOrbiterG = ((aWandererI + RotL64(aIngress, 29U)) + 17361734905706517877U) + aPhaseCOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = ((aWandererE + RotL64(aCross, 47U)) + RotL64(aCarry, 3U)) + 15837111231884647451U;
            aOrbiterC = (((aWandererD + RotL64(aScatter, 19U)) + RotL64(aCarry, 43U)) + 18065431964418026445U) + aPhaseCOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = ((aWandererA + RotL64(aIngress, 13U)) + RotL64(aCarry, 51U)) + 3029123922999952652U;
            aOrbiterD = (aWandererC + RotL64(aPrevious, 54U)) + 5166926595573507837U;
            aOrbiterF = (aWandererH + RotL64(aCross, 23U)) + 1918425684273807598U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 4724551751012661440U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 1818014487579644390U;
            aOrbiterK = RotL64((aOrbiterK * 14904092108647864911U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 6670090372241084216U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 8485757110007268693U;
            aOrbiterH = RotL64((aOrbiterH * 11876760095108618363U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 4928130251509514742U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 2528788422725346792U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1855982047967756661U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 2860387120895147503U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 12927802338151379368U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8876144125458603029U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 18029699867733207083U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 13361836994951253312U;
            aOrbiterG = RotL64((aOrbiterG * 5349767426256597073U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 11957294454794128079U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 3755417922063414648U;
            aOrbiterI = RotL64((aOrbiterI * 13896364063651241401U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 18001157153447913032U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 16214145724690286854U;
            aOrbiterE = RotL64((aOrbiterE * 5874139687703360515U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 3860958772090975562U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 12395621524459640173U;
            aOrbiterC = RotL64((aOrbiterC * 722817135977510161U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 3402035664910754484U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 2139099117325745602U;
            aOrbiterF = RotL64((aOrbiterF * 14008983756425796029U), 57U);
            //
            aIngress = RotL64(aOrbiterG, 13U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterI, 37U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterA, 54U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 5U));
            aIngress = aIngress + RotL64(aOrbiterH, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aIngress, 53U) + aOrbiterI) + RotL64(aOrbiterE, 47U)) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterG, 23U)) + aOrbiterI);
            aWandererI = aWandererI + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterH, 6U)) + aOrbiterG);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 48U) + aOrbiterD) + RotL64(aOrbiterA, 27U));
            aWandererD = aWandererD + (((RotL64(aIngress, 23U) + aOrbiterA) + RotL64(aOrbiterE, 11U)) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 57U) + aOrbiterG) + RotL64(aOrbiterK, 39U));
            aWandererH = aWandererH + (((RotL64(aScatter, 13U) + RotL64(aOrbiterC, 43U)) + aOrbiterF) + RotL64(aCarry, 29U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 34U) + RotL64(aOrbiterK, 35U)) + aOrbiterI) + aPhaseCWandererUpdateSaltC[((aIndex + 28U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 19U) + aOrbiterG) + RotL64(aOrbiterC, 58U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 39U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 6U) ^ aWandererA);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + RotL64(aWandererI, 35U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 26240U)) & S_BLOCK1], 5U) ^ RotL64(aKeyRowReadA[((aIndex + 25071U)) & W_KEY1], 57U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 24862U)) & S_BLOCK1], 39U) ^ RotL64(aFireLaneB[((aIndex + 26989U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 24951U)) & W_KEY1], 6U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 25811U)) & S_BLOCK1], 37U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 24763U)) & S_BLOCK1], 51U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 27051U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 19U) + RotL64(aIngress, 5U)) ^ (RotL64(aPrevious, 50U) ^ RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = (aWandererB + RotL64(aPrevious, 30U)) + 2225397913940961213U;
            aOrbiterI = (aWandererA + RotL64(aScatter, 5U)) + 8342544893601343643U;
            aOrbiterG = ((aWandererF + RotL64(aIngress, 35U)) + RotL64(aCarry, 5U)) + 162922186381417187U;
            aOrbiterK = ((aWandererE + RotL64(aCross, 53U)) + RotL64(aCarry, 19U)) + 11660218373710972210U;
            aOrbiterE = (aWandererK + RotL64(aPrevious, 43U)) + 14909034764605802354U;
            aOrbiterH = (aWandererI + RotL64(aCross, 47U)) + 16776955237009701511U;
            aOrbiterA = (((aWandererD + RotL64(aScatter, 10U)) + RotL64(aCarry, 27U)) + 5834487809188925253U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = ((aWandererJ + RotL64(aIngress, 19U)) + 1498492772767040320U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = (aWandererC + RotL64(aPrevious, 39U)) + 4161765458781579617U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 10511923076962447765U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 8575954471692620021U;
            aOrbiterG = RotL64((aOrbiterG * 12526744988828982731U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 6536325446331340573U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 1790628986900286346U;
            aOrbiterI = RotL64((aOrbiterI * 5262997114200816715U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 2623814807619278590U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 11676970995834706612U;
            aOrbiterH = RotL64((aOrbiterH * 10057461115132434901U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 13836786354224256591U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 6293096163612129260U;
            aOrbiterK = RotL64((aOrbiterK * 8977954126326217153U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 4271144764978661248U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 15938494256992560202U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10004841288382726739U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 11038155227307702976U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 12408749795071243930U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5527720475032868855U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 1673665849053496882U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 12866353361497103629U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6041125499398924871U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 10673935802381580966U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 8946776538955520352U;
            aOrbiterF = RotL64((aOrbiterF * 12293084177712710021U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 16294935203370452805U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 4697759331563852212U;
            aOrbiterC = RotL64((aOrbiterC * 14407806317275373043U), 53U);
            //
            aIngress = RotL64(aOrbiterF, 13U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 10U));
            aIngress = aIngress + (RotL64(aOrbiterD, 39U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterG, 51U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterA, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterF, 58U)) + aOrbiterK);
            aWandererA = aWandererA + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterC, 29U)) + aOrbiterF) + RotL64(aCarry, 11U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 18U) + aOrbiterG) + RotL64(aOrbiterD, 41U));
            aWandererI = aWandererI + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterI, 3U)) + aOrbiterF) + RotL64(aCarry, 21U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterF, 37U)) + aOrbiterE);
            aWandererF = aWandererF + ((RotL64(aCross, 13U) + aOrbiterF) + RotL64(aOrbiterD, 46U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterA, 53U)) + aOrbiterI);
            aWandererC = aWandererC + ((RotL64(aIngress, 53U) + aOrbiterC) + RotL64(aOrbiterH, 11U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 58U) + aOrbiterF) + RotL64(aOrbiterG, 19U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererF, 44U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererA);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + RotL64(aWandererC, 19U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 27917U)) & S_BLOCK1], 43U) ^ RotL64(aFireLaneD[((aIndex + 27952U)) & S_BLOCK1], 26U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 28969U)) & W_KEY1], 5U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 28142U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 28914U)) & W_KEY1], 13U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 29619U)) & S_BLOCK1], 39U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29279U)) & S_BLOCK1], 47U) ^ RotL64(aFireLaneB[((aIndex + 28213U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aIngress, 60U)) + (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = ((aWandererA + RotL64(aIngress, 21U)) + RotL64(aCarry, 37U)) + 17074147006464019918U;
            aOrbiterH = (aWandererJ + RotL64(aCross, 54U)) + 10559516626129419928U;
            aOrbiterJ = (((aWandererH + RotL64(aPrevious, 43U)) + RotL64(aCarry, 19U)) + 13280363679503946221U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterC = ((aWandererB + RotL64(aScatter, 11U)) + 17657115422132457413U) + aPhaseDOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = (aWandererE + RotL64(aIngress, 27U)) + 13325837013304973008U;
            aOrbiterF = ((aWandererC + RotL64(aScatter, 58U)) + RotL64(aCarry, 11U)) + 3059707750486106037U;
            aOrbiterB = (aWandererI + RotL64(aPrevious, 5U)) + 4529045702503050852U;
            aOrbiterI = (aWandererG + RotL64(aCross, 47U)) + 10726578475550904292U;
            aOrbiterK = (aWandererF + RotL64(aIngress, 35U)) + 14832537837996659885U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 220094417441809246U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 15343130035105342194U;
            aOrbiterJ = RotL64((aOrbiterJ * 7984652435043810845U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 16592263353426409884U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 15649290906447931918U;
            aOrbiterH = RotL64((aOrbiterH * 8405875177836650731U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 11437410545843708269U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 5859769136073011444U;
            aOrbiterB = RotL64((aOrbiterB * 1065016088086441107U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 15188064100307340341U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 4367466521843260049U;
            aOrbiterF = RotL64((aOrbiterF * 15916715854192820923U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 8482617283860566845U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 2585745804937342972U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8267269625632139809U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 1687641344403425541U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 13667916445979421400U;
            aOrbiterA = RotL64((aOrbiterA * 8191322670355590027U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 7684258716388029228U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 14764266202380443369U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1746254773647650741U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 12685190466981675661U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 9958374400222383893U;
            aOrbiterK = RotL64((aOrbiterK * 12696606920219838929U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 1352584794098160330U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 16057453941015251708U;
            aOrbiterC = RotL64((aOrbiterC * 6051546505117202495U), 11U);
            //
            aIngress = RotL64(aOrbiterD, 60U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 35U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 13U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterA, 24U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 3U) + aOrbiterH) + RotL64(aOrbiterI, 14U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 19U) + aOrbiterC) + RotL64(aOrbiterB, 39U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterC, 21U)) + aOrbiterK);
            aWandererG = aWandererG + ((RotL64(aCross, 14U) + RotL64(aOrbiterK, 47U)) + aOrbiterB);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 27U) + aOrbiterD) + RotL64(aOrbiterA, 35U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterC, 53U)) + aOrbiterF) + RotL64(aCarry, 53U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 39U) + aOrbiterJ) + RotL64(aOrbiterI, 10U));
            aWandererI = aWandererI + (((RotL64(aCross, 10U) + aOrbiterC) + RotL64(aOrbiterI, 5U)) + RotL64(aCarry, 29U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterA, 57U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 10U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 5U));
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererC, 29U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 31421U)) & S_BLOCK1], 22U) ^ RotL64(aKeyRowReadA[((aIndex + 31184U)) & W_KEY1], 41U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 32631U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30835U)) & S_BLOCK1], 39U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31834U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadB[((aIndex + 31430U)) & W_KEY1], 56U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCarry, 5U)) + (RotL64(aCross, 44U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = ((aWandererE + RotL64(aIngress, 60U)) + 701291026547470433U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = ((aWandererA + RotL64(aCross, 39U)) + RotL64(aCarry, 21U)) + 17283292650462111643U;
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 47U)) + 9969124091931303406U;
            aOrbiterI = ((aWandererB + RotL64(aScatter, 21U)) + RotL64(aCarry, 47U)) + 889176772718046988U;
            aOrbiterA = (aWandererI + RotL64(aIngress, 3U)) + 6054541844643748084U;
            aOrbiterD = (aWandererG + RotL64(aScatter, 43U)) + 14703226235143028132U;
            aOrbiterB = (aWandererC + RotL64(aCross, 13U)) + 7977975878522921062U;
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 51U)) + RotL64(aCarry, 13U)) + 16894322614172266274U;
            aOrbiterC = ((aWandererD + RotL64(aCross, 30U)) + 12160451749345900570U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 10870847008043897470U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 8159920947172520247U;
            aOrbiterJ = RotL64((aOrbiterJ * 4833194641611011805U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 2440099120969517932U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 2428396147731468007U;
            aOrbiterD = RotL64((aOrbiterD * 9363073341539598441U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 2213226274394673479U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 7079731443427765333U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16918930776877030559U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 958896789550478970U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 10788682955708075458U;
            aOrbiterC = RotL64((aOrbiterC * 913321215613559729U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 2003386579317564870U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 8419686358774204999U;
            aOrbiterA = RotL64((aOrbiterA * 6547052526438697621U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 6989167615157578904U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 17636634003643824148U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11038576417283732937U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 13824962118933907859U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 9543912892587859646U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14736710162285997415U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 15729878041027706114U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 9542137475454825463U;
            aOrbiterG = RotL64((aOrbiterG * 11420547128115090491U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 5327302277575009955U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 2707383132257428583U;
            aOrbiterB = RotL64((aOrbiterB * 6120763309390182129U), 13U);
            //
            aIngress = RotL64(aOrbiterB, 14U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterI, 37U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterD, 29U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterF, 19U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aCross, 4U) + RotL64(aOrbiterG, 37U)) + aOrbiterF) + RotL64(aCarry, 47U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 35U) + aOrbiterC) + RotL64(aOrbiterG, 13U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterA, 47U)) + aOrbiterD) + RotL64(aCarry, 13U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterH, 52U)) + aOrbiterB);
            aWandererJ = aWandererJ + (((RotL64(aCross, 56U) + aOrbiterG) + RotL64(aOrbiterH, 5U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 19U) + aOrbiterI) + RotL64(aOrbiterC, 23U));
            aWandererC = aWandererC + ((RotL64(aIngress, 11U) + RotL64(aOrbiterI, 19U)) + aOrbiterG);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 41U) + aOrbiterA) + RotL64(aOrbiterJ, 58U));
            aWandererI = aWandererI + (((RotL64(aIngress, 47U) + RotL64(aOrbiterA, 41U)) + aOrbiterG) + aPhaseDWandererUpdateSaltB[((aIndex + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 26U));
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererI, 21U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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

void TwistExpander_WaterPolo_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneA, aExpandLaneC, aExpandLaneD, aInvestLaneC, aFireLaneD, aInvestLaneD, aFireLaneC, aOperationLaneA, aFireLaneB, aOperationLaneB, aOperationLaneC
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 1500U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneB[((aIndex + 1572U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 1496U)) & S_BLOCK1], 4U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4758U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneD[((aIndex + 4947U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 27U) + RotL64(aPrevious, 39U)) ^ (RotL64(aIngress, 51U) ^ RotL64(aCarry, 10U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = (aWandererF + RotL64(aIngress, 27U)) + 8101351470141807662U;
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 20U)) + RotL64(aCarry, 39U)) + 6965474099521076705U;
            aOrbiterH = ((aWandererJ + RotL64(aCross, 11U)) + RotL64(aCarry, 53U)) + 6803828268885684784U;
            aOrbiterA = ((aWandererH + RotL64(aScatter, 53U)) + RotL64(aCarry, 23U)) + 13454235922950972488U;
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 35U)) + 11678091885751244777U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = ((aWandererG + RotL64(aCross, 43U)) + 5307134544628507141U) + aPhaseEOrbiterAssignSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterK = (aWandererK + RotL64(aScatter, 5U)) + 4873703518950429353U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 8542156221858586039U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 3993726182905296513U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11331376012938127609U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 12113047622035464386U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 1944244448665721151U;
            aOrbiterF = RotL64((aOrbiterF * 7010050836758762003U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 12914188029425467576U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 2486762763475327024U;
            aOrbiterK = RotL64((aOrbiterK * 12319769994433811617U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 14580191602982245481U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 12093414832400135066U;
            aOrbiterA = RotL64((aOrbiterA * 12720286833215690663U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 13623906997320021065U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 9977356009806428696U;
            aOrbiterC = RotL64((aOrbiterC * 2005536391712733499U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 3694954095397810851U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 11453812627797091638U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13730420725113907161U), 37U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 542311345544726351U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 3024285045990499484U;
            aOrbiterJ = RotL64((aOrbiterJ * 5153745952148205645U), 57U);
            //
            aIngress = RotL64(aOrbiterJ, 51U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 29U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 11U));
            aIngress = aIngress + RotL64(aOrbiterA, 60U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aScatter, 60U) + aOrbiterF) + RotL64(aOrbiterK, 3U)) + RotL64(aCarry, 3U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 43U) + aOrbiterC) + RotL64(aOrbiterJ, 19U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterC, 35U)) + aOrbiterF) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterF, 27U)) + aOrbiterA);
            aWandererK = aWandererK + ((RotL64(aPrevious, 13U) + aOrbiterF) + RotL64(aOrbiterJ, 13U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterJ, 57U)) + aOrbiterI) + aPhaseEWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 53U) + aOrbiterH) + RotL64(aOrbiterI, 42U)) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + RotL64(aWandererH, 4U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aInvestLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_b loop 2
        // ingress from: aInvestLaneC, aExpandLaneC, aFireLaneD
        // ingress directions: aInvestLaneC forward forced, aExpandLaneC forward forced, aFireLaneD forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneC[((aIndex + 7855U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneC[((aIndex + 9431U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 10287U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 6956U)) & S_BLOCK1], 18U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 9401U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 53U)) ^ (RotL64(aIngress, 18U) + RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = (aWandererB + RotL64(aIngress, 47U)) + 12690502671561165478U;
            aOrbiterA = (((aWandererA + RotL64(aCross, 19U)) + RotL64(aCarry, 27U)) + 17519943923428102801U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 37U)) + RotL64(aCarry, 3U)) + 10705515807975331385U;
            aOrbiterH = ((aWandererF + RotL64(aScatter, 29U)) + RotL64(aCarry, 43U)) + 16586447272278538179U;
            aOrbiterE = (aWandererJ + RotL64(aIngress, 56U)) + 8006560996840971798U;
            aOrbiterC = (aWandererD + RotL64(aCross, 3U)) + 12928600185788857701U;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 11U)) + 14240723153798267172U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 8636219177994872072U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 7586790235186467512U;
            aOrbiterB = RotL64((aOrbiterB * 15052686382507614169U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 1103807034179512424U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 7547526530239498693U;
            aOrbiterE = RotL64((aOrbiterE * 3360295583636013509U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 8380239679344786397U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 5690809173787433519U;
            aOrbiterG = RotL64((aOrbiterG * 5354724308093372953U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 8390902801141804609U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 3507306189192059486U;
            aOrbiterC = RotL64((aOrbiterC * 18336280496510253103U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 6190745292098482871U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 8065418693975056902U;
            aOrbiterA = RotL64((aOrbiterA * 6414621418430102589U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 12111755051718111803U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 7605877769709909297U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17525248694315944599U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 5969794501112646237U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 5127559299360591476U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4521563633438853069U), 11U);
            //
            aIngress = RotL64(aOrbiterB, 12U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 43U));
            aIngress = aIngress + RotL64(aOrbiterC, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aCross, 3U) + aOrbiterD) + RotL64(aOrbiterE, 11U)) + RotL64(aCarry, 37U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterA, 43U)) + aOrbiterC);
            aWandererC = aWandererC + ((((RotL64(aIngress, 13U) + RotL64(aOrbiterE, 21U)) + aOrbiterC) + RotL64(aCarry, 5U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterH, 5U)) + aOrbiterA);
            aWandererB = aWandererB + (((RotL64(aCross, 35U) + RotL64(aOrbiterB, 27U)) + aOrbiterH) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 19U) + aOrbiterG) + RotL64(aOrbiterB, 60U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 56U) + aOrbiterB) + RotL64(aOrbiterD, 37U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 36U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + RotL64(aWandererB, 41U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = (RotL64(aInvestLaneD[((aIndex + 14405U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((aIndex + 15686U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 16384U)) & S_BLOCK1], 24U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 12578U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 15895U)) & S_BLOCK1], 24U));
            aCross ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 15714U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 38U) ^ RotL64(aCarry, 23U)) ^ (RotL64(aCross, 11U) + RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = (aWandererD + RotL64(aPrevious, 57U)) + 15813325389431304548U;
            aOrbiterI = (((aWandererC + RotL64(aScatter, 19U)) + RotL64(aCarry, 11U)) + 2223874171125403602U) + aPhaseEOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = ((aWandererH + RotL64(aCross, 39U)) + RotL64(aCarry, 43U)) + 5510483568496824130U;
            aOrbiterC = ((aWandererK + RotL64(aIngress, 11U)) + RotL64(aCarry, 29U)) + 15474152493495661876U;
            aOrbiterF = (aWandererF + RotL64(aPrevious, 27U)) + 16846339705130829195U;
            aOrbiterK = (aWandererE + RotL64(aScatter, 48U)) + 1289670576865739669U;
            aOrbiterD = ((aWandererA + RotL64(aIngress, 3U)) + 18017354919647006944U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 8539685539928984921U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 3333721400836704048U;
            aOrbiterA = RotL64((aOrbiterA * 3745286323481400085U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 2261560416623815491U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 4377786131746816567U;
            aOrbiterF = RotL64((aOrbiterF * 9164777834392621157U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 18047393176583722719U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 8184724021940434631U;
            aOrbiterC = RotL64((aOrbiterC * 9800116157750921119U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 10469895939183324807U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 14543391765109879223U;
            aOrbiterK = RotL64((aOrbiterK * 4817987697437667225U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 5757225781746158178U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 3539000495894022869U;
            aOrbiterD = RotL64((aOrbiterD * 1032298408884695925U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 11288971092707065923U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 2761384065186568294U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3323838837427471051U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 7120580145300417101U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 6977246291769372866U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15170353875184253779U), 51U);
            //
            aIngress = RotL64(aOrbiterF, 43U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 26U));
            aIngress = aIngress + RotL64(aOrbiterC, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterD, 28U)) + aOrbiterK) + RotL64(aCarry, 47U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 43U) + aOrbiterC) + RotL64(aOrbiterF, 41U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aScatter, 19U) + RotL64(aOrbiterF, 51U)) + aOrbiterA);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 27U) + aOrbiterC) + RotL64(aOrbiterK, 35U));
            aWandererH = aWandererH + ((((RotL64(aCross, 34U) + aOrbiterI) + RotL64(aOrbiterD, 21U)) + RotL64(aCarry, 3U)) + aPhaseEWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 13U) + aOrbiterJ) + RotL64(aOrbiterA, 3U));
            aWandererF = aWandererF + ((RotL64(aScatter, 51U) + RotL64(aOrbiterJ, 57U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 41U) ^ aWandererA);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 56U));
            aCarry = aCarry + RotL64(aWandererF, 11U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 20871U)) & S_BLOCK1], 3U) ^ RotL64(aInvestLaneC[((aIndex + 19937U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 17551U)) & S_BLOCK1], 52U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 21208U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 20294U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 18742U)) & S_BLOCK1], 46U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 6U) ^ RotL64(aPrevious, 41U)) + (RotL64(aIngress, 23U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 37U)) + RotL64(aCarry, 51U)) + 3550722402315312207U;
            aOrbiterK = ((aWandererC + RotL64(aCross, 43U)) + 16724184551669522754U) + aPhaseEOrbiterAssignSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = (aWandererH + RotL64(aIngress, 19U)) + 981751330116773021U;
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 53U)) + RotL64(aCarry, 5U)) + 7891159229704944868U;
            aOrbiterB = ((aWandererA + RotL64(aIngress, 29U)) + RotL64(aCarry, 29U)) + 13618396711464799841U;
            aOrbiterE = ((aWandererD + RotL64(aCross, 60U)) + 5969291018449003648U) + aPhaseEOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = (aWandererG + RotL64(aPrevious, 13U)) + 14595540413313640042U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 3287990436916111762U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 12534369400200483704U;
            aOrbiterJ = RotL64((aOrbiterJ * 2345945228434740707U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 2277312067930392274U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 10026320559261334353U;
            aOrbiterB = RotL64((aOrbiterB * 11020464940995912637U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 11258082063135659551U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 1445958517675746990U;
            aOrbiterG = RotL64((aOrbiterG * 10062265337488757971U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 1011298251290970844U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 6487834862470043744U;
            aOrbiterD = RotL64((aOrbiterD * 15477913837027179675U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 9966279022928268335U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 10285993486057704393U;
            aOrbiterE = RotL64((aOrbiterE * 15965714363201157535U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 16005362468813966136U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 223843444699390781U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 665392038954573081U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 18178876294968532775U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 12490136112181806806U;
            aOrbiterK = RotL64((aOrbiterK * 16380841616662993709U), 57U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterG, 53U);
            aIngress = aIngress + (RotL64(aOrbiterC, 39U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 5U));
            aIngress = aIngress + RotL64(aOrbiterK, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 13U) + aOrbiterB) + RotL64(aOrbiterG, 35U));
            aWandererE = aWandererE + ((RotL64(aCross, 57U) + aOrbiterG) + RotL64(aOrbiterJ, 19U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 21U) + aOrbiterJ) + RotL64(aOrbiterK, 41U));
            aWandererC = aWandererC + (((RotL64(aIngress, 5U) + aOrbiterB) + RotL64(aOrbiterE, 13U)) + RotL64(aCarry, 47U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterD, 51U)) + aOrbiterE) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aScatter, 51U) + RotL64(aOrbiterG, 58U)) + aOrbiterK) + RotL64(aCarry, 19U)) + aPhaseEWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 30U) + RotL64(aOrbiterE, 27U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 30U));
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererA, 13U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 23805U)) & S_BLOCK1], 18U) ^ RotL64(aOperationLaneA[((aIndex + 25477U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 24378U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 23162U)) & S_BLOCK1], 56U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 23200U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 23240U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aIngress, 11U)) + (RotL64(aPrevious, 27U) ^ RotL64(aCross, 58U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = ((aWandererE + RotL64(aCross, 53U)) + RotL64(aCarry, 27U)) + 964165145848253292U;
            aOrbiterA = (((aWandererK + RotL64(aPrevious, 13U)) + RotL64(aCarry, 5U)) + 10645976767204934746U) + aPhaseEOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = (aWandererJ + RotL64(aIngress, 39U)) + 8241612229349212650U;
            aOrbiterB = ((aWandererI + RotL64(aScatter, 29U)) + RotL64(aCarry, 41U)) + 4159196033256913347U;
            aOrbiterC = (aWandererF + RotL64(aCross, 19U)) + 7194795864620233507U;
            aOrbiterD = ((aWandererA + RotL64(aIngress, 5U)) + 7638928444536778384U) + aPhaseEOrbiterAssignSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = (aWandererD + RotL64(aScatter, 60U)) + 11819105916503968109U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 18052213302858186237U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 8663575313970041570U;
            aOrbiterF = RotL64((aOrbiterF * 14131073322476609161U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 16644136720439299786U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 16930316530442679864U;
            aOrbiterC = RotL64((aOrbiterC * 2650922074098320859U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 16251107616988250593U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 7171986193609401665U;
            aOrbiterD = RotL64((aOrbiterD * 3543709971414550087U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 17885046834432626644U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 7757069274715713557U;
            aOrbiterA = RotL64((aOrbiterA * 15766885299397923879U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 2212805322061155615U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 6368539134638838822U;
            aOrbiterG = RotL64((aOrbiterG * 13383744883433594259U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 5264326094252925613U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 6126345334815012938U;
            aOrbiterB = RotL64((aOrbiterB * 17180934809764905307U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 13826731214018407061U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 6621261811613643620U;
            aOrbiterE = RotL64((aOrbiterE * 2823596473596114171U), 27U);
            //
            aIngress = RotL64(aOrbiterA, 29U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterC, 53U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterE, 5U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterB, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterA, 43U)) + aOrbiterC) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 34U) + RotL64(aOrbiterC, 58U)) + aOrbiterD) + RotL64(aCarry, 13U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterB, 27U)) + aOrbiterG);
            aWandererK = aWandererK + ((RotL64(aCross, 27U) + RotL64(aOrbiterD, 19U)) + aOrbiterA);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterD, 3U)) + aOrbiterE);
            aWandererA = aWandererA + ((((RotL64(aCross, 51U) + aOrbiterF) + RotL64(aOrbiterG, 37U)) + RotL64(aCarry, 39U)) + aPhaseEWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 41U) + aOrbiterA) + RotL64(aOrbiterB, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 44U) ^ aWandererJ);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 19U));
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererD, 53U);
            aCarry = aCarry + RotL64(aIngress, 34U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 29007U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneA[((aIndex + 27323U)) & S_BLOCK1], 60U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 30483U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29101U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 30109U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 29840U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aIngress, 56U)) + (RotL64(aCarry, 37U) ^ RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 35U)) + 1210605127156905516U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = ((aWandererG + RotL64(aScatter, 27U)) + RotL64(aCarry, 51U)) + 11964595428173569519U;
            aOrbiterH = (aWandererC + RotL64(aIngress, 48U)) + 16277319029916258482U;
            aOrbiterK = ((aWandererJ + RotL64(aCross, 21U)) + RotL64(aCarry, 37U)) + 12369497463101824572U;
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 11U)) + RotL64(aCarry, 5U)) + 6201248574067068202U;
            aOrbiterJ = (aWandererA + RotL64(aIngress, 5U)) + 1727477025667206661U;
            aOrbiterE = ((aWandererF + RotL64(aScatter, 41U)) + 1404510627789806851U) + aPhaseEOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 6948213591282018925U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 6688865181284421478U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12619122841662247279U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 3351130769402360855U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 12681032488906270823U;
            aOrbiterB = RotL64((aOrbiterB * 3680893896579741263U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 3591412591193726763U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 16153817571210878589U;
            aOrbiterE = RotL64((aOrbiterE * 4165137036092246349U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 3808228354421006630U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 1427373776207504205U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4534374093769595531U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 1831554180932501132U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 1114853085120949215U;
            aOrbiterI = RotL64((aOrbiterI * 4264176108298812905U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 2080935638828366835U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 16104777999646489828U;
            aOrbiterJ = RotL64((aOrbiterJ * 15205199362011777473U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 9782806013673440791U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 3721620299829386454U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6286765834910272409U), 57U);
            //
            aIngress = RotL64(aOrbiterF, 13U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterE, 51U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterK, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 5U) + aOrbiterH) + RotL64(aOrbiterE, 47U));
            aWandererK = aWandererK + ((((RotL64(aCross, 19U) + RotL64(aOrbiterK, 19U)) + aOrbiterI) + RotL64(aCarry, 39U)) + aPhaseEWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 39U) + aOrbiterB) + RotL64(aOrbiterE, 57U));
            aWandererC = aWandererC + ((((RotL64(aScatter, 11U) + RotL64(aOrbiterK, 26U)) + aOrbiterH) + RotL64(aCarry, 3U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 57U) + aOrbiterB) + RotL64(aOrbiterF, 39U));
            aWandererG = aWandererG + ((RotL64(aScatter, 47U) + RotL64(aOrbiterF, 5U)) + aOrbiterJ);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 26U) + aOrbiterK) + RotL64(aOrbiterJ, 13U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + RotL64(aWandererJ, 36U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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

void TwistExpander_WaterPolo_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
        // read from: aOperationLaneA, aOperationLaneB, aExpandLaneD, aOperationLaneC, aOperationLaneD, aExpandLaneA, aSnowLaneA, aExpandLaneC, aInvestLaneB, aSnowLaneB, aInvestLaneD, aWorkLaneA, aInvestLaneC, aWorkLaneB, aExpandLaneB, aWorkLaneC, aInvestLaneA
        // write to: aSnowLaneA, aSnowLaneB, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // twist_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aExpandLaneD
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aExpandLaneD forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aExpandLaneA
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aExpandLaneA backward/forward random
        // write to: aSnowLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 5087U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneB[((aIndex + 664U)) & S_BLOCK1], 38U));
            aIngress ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 2007U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 5329U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 2136U)) & S_BLOCK1], 20U));
            aCross ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 1048U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 6U) ^ RotL64(aCarry, 37U)) ^ (RotL64(aCross, 23U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = (aWandererF + RotL64(aScatter, 40U)) + 17264605017518259932U;
            aOrbiterD = (aWandererE + RotL64(aCross, 13U)) + 15209184354580778643U;
            aOrbiterJ = (aWandererD + RotL64(aIngress, 57U)) + 3299527965014731384U;
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 23U)) + 16293096431816127821U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = (aWandererG + RotL64(aIngress, 19U)) + 11031983436878828337U;
            aOrbiterA = ((aWandererK + RotL64(aScatter, 27U)) + RotL64(aCarry, 47U)) + 9188018632448236358U;
            aOrbiterC = (aWandererC + RotL64(aPrevious, 37U)) + 13420816400363406556U;
            aOrbiterG = ((aWandererJ + RotL64(aCross, 34U)) + RotL64(aCarry, 13U)) + 2485063384097917101U;
            aOrbiterB = ((aWandererH + RotL64(aIngress, 11U)) + RotL64(aCarry, 29U)) + 3089135816938128264U;
            aOrbiterF = ((aWandererB + RotL64(aCross, 29U)) + 10730544971770435788U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = (aWandererA + RotL64(aPrevious, 47U)) + 10431767565618874806U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 14883796491656899074U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 13465877783538483706U;
            aOrbiterJ = RotL64((aOrbiterJ * 14311686051108108503U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 13322163435314643713U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 3307316600284371955U;
            aOrbiterK = RotL64((aOrbiterK * 12337846092069506365U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 4950101626975919939U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 2596253994220103666U;
            aOrbiterD = RotL64((aOrbiterD * 7181706961838582889U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 17961706029559914243U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 10321902557977495175U;
            aOrbiterG = RotL64((aOrbiterG * 16189559888625084711U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 18146616411403012772U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 8414050129421955787U;
            aOrbiterH = RotL64((aOrbiterH * 14879448948196182863U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 11739172334166341121U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 7936637782633487291U;
            aOrbiterF = RotL64((aOrbiterF * 14940929920543800413U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 3160044627483874242U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 16816384076887379704U;
            aOrbiterE = RotL64((aOrbiterE * 5052772186568301951U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 8101560104988710226U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 8851416379738817624U;
            aOrbiterA = RotL64((aOrbiterA * 16767420038937389027U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 9941784290055185679U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 14495651885701938495U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1540692851998143607U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 10599676325220702167U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 16092000942942971187U;
            aOrbiterC = RotL64((aOrbiterC * 2457268192247656817U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 16168470945107928109U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 17264605017518259932U;
            aOrbiterI = RotL64((aOrbiterI * 15038386057529909273U), 11U);
            //
            aIngress = RotL64(aOrbiterJ, 46U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 27U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 53U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 41U));
            aIngress = aIngress + RotL64(aOrbiterF, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 47U) + aOrbiterA) + RotL64(aOrbiterF, 27U));
            aWandererI = aWandererI + (((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterA, 11U)) + aPhaseFWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 24U) + aOrbiterD) + RotL64(aOrbiterC, 39U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 13U) + RotL64(aOrbiterH, 24U)) + aOrbiterD);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 11U) + aOrbiterG) + RotL64(aOrbiterD, 43U));
            aWandererE = aWandererE + (((RotL64(aCross, 43U) + aOrbiterF) + RotL64(aOrbiterG, 19U)) + RotL64(aCarry, 51U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 51U) + aOrbiterB) + RotL64(aOrbiterI, 13U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 37U) + aOrbiterJ) + RotL64(aOrbiterK, 47U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 57U) + aOrbiterI) + RotL64(aOrbiterK, 6U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 4U) + RotL64(aOrbiterH, 29U)) + aOrbiterK) + RotL64(aCarry, 37U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterE, 51U)) + aOrbiterA) + aPhaseFWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 26U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 39U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererK);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 21U));
            aCarry = aCarry + RotL64(aWandererC, 47U);
            aCarry = aCarry + RotL64(aIngress, 18U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aSnowLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 2
        // ingress from: aSnowLaneA, aOperationLaneC, aOperationLaneD, aExpandLaneC
        // ingress directions: aSnowLaneA forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aExpandLaneC forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aInvestLaneB
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aInvestLaneB backward/forward random
        // write to: aSnowLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 5826U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneC[((aIndex + 6551U)) & S_BLOCK1], 28U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 8355U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 6549U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 6771U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 7783U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 10500U)) & S_BLOCK1], 36U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCross, 19U)) + (RotL64(aCarry, 35U) + RotL64(aPrevious, 52U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = (aWandererK + RotL64(aScatter, 43U)) + 6521330037475130256U;
            aOrbiterC = (aWandererG + RotL64(aIngress, 11U)) + 12611880456055428940U;
            aOrbiterF = (((aWandererC + RotL64(aPrevious, 36U)) + RotL64(aCarry, 37U)) + 12061611078130934708U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = ((aWandererF + RotL64(aCross, 47U)) + 1558112410801116984U) + aPhaseFOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = (aWandererA + RotL64(aScatter, 39U)) + 10509115227850160786U;
            aOrbiterA = ((aWandererE + RotL64(aIngress, 3U)) + RotL64(aCarry, 51U)) + 4045915960688792066U;
            aOrbiterJ = (aWandererH + RotL64(aCross, 57U)) + 1196541286513243082U;
            aOrbiterG = (aWandererI + RotL64(aPrevious, 27U)) + 15564991032722373702U;
            aOrbiterK = ((aWandererJ + RotL64(aCross, 53U)) + RotL64(aCarry, 5U)) + 4897765238703641798U;
            aOrbiterD = (aWandererB + RotL64(aPrevious, 60U)) + 12327429514907752733U;
            aOrbiterB = (aWandererD + RotL64(aIngress, 13U)) + 6189189797708711636U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 6374267075282018852U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 1888758503831341439U;
            aOrbiterF = RotL64((aOrbiterF * 74387714918264257U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 14956857689299491800U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 14879361107223331957U;
            aOrbiterE = RotL64((aOrbiterE * 9166712966729591953U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 16086885494838105042U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 8069724185844303923U;
            aOrbiterG = RotL64((aOrbiterG * 8878470736758734353U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 10854345917959911439U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 7078313614360332089U;
            aOrbiterA = RotL64((aOrbiterA * 9864025732292844871U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 15083669236062255011U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 594879695916679116U;
            aOrbiterD = RotL64((aOrbiterD * 9852515479152735283U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 6721466068234534523U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 475816724162626782U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4799725182757588407U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 4341655358154605899U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 15477254302340298586U;
            aOrbiterI = RotL64((aOrbiterI * 13961520225881974201U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 10179091913200895775U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 6310490897546909571U;
            aOrbiterK = RotL64((aOrbiterK * 15080621088825477613U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 13462682513035460711U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 16739138858084100385U;
            aOrbiterC = RotL64((aOrbiterC * 16386371811268298031U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 13608837667062268989U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 12902415667552110103U;
            aOrbiterH = RotL64((aOrbiterH * 16398790854093048017U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 16596211634603915761U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 6521330037475130256U;
            aOrbiterJ = RotL64((aOrbiterJ * 631958426544321145U), 35U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterF, 36U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 41U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 39U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 13U));
            aIngress = aIngress + RotL64(aOrbiterG, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aIngress, 29U) + RotL64(aOrbiterC, 18U)) + aOrbiterK);
            aWandererI = aWandererI ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterE, 39U)) + aOrbiterF) + aPhaseFWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterI, 3U)) + aOrbiterK) + RotL64(aCarry, 21U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 3U) + aOrbiterJ) + RotL64(aOrbiterK, 5U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterE, 12U)) + aOrbiterD);
            aWandererE = aWandererE ^ ((RotL64(aCross, 34U) + RotL64(aOrbiterK, 35U)) + aOrbiterD);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 51U) + RotL64(aOrbiterC, 29U)) + aOrbiterA) + RotL64(aCarry, 57U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 39U) + aOrbiterK) + RotL64(aOrbiterE, 53U));
            aWandererF = aWandererF + ((RotL64(aIngress, 23U) + RotL64(aOrbiterB, 21U)) + aOrbiterG);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 58U) + aOrbiterH) + RotL64(aOrbiterI, 37U));
            aWandererG = aWandererG + ((RotL64(aCross, 5U) + RotL64(aOrbiterG, 43U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererF, 37U) ^ aWandererK);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 58U));
            aCarry = aCarry + (RotL64(aWandererA, 21U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererB, 13U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 13827U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneA[((aIndex + 11327U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 12223U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 12636U)) & S_BLOCK1], 22U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 11335U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 13U) ^ RotL64(aCarry, 41U)) + (RotL64(aPrevious, 27U) ^ RotL64(aCross, 54U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = (aWandererF + RotL64(aScatter, 19U)) + 5568146815535263910U;
            aOrbiterA = (aWandererA + RotL64(aPrevious, 41U)) + 7736084960873834666U;
            aOrbiterH = (aWandererG + RotL64(aCross, 43U)) + 1336413621817562093U;
            aOrbiterE = ((aWandererD + RotL64(aIngress, 21U)) + RotL64(aCarry, 43U)) + 5218462026934984692U;
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 5U)) + RotL64(aCarry, 57U)) + 7048890985969555935U;
            aOrbiterG = (aWandererI + RotL64(aScatter, 24U)) + 13415955213864702118U;
            aOrbiterD = ((aWandererK + RotL64(aCross, 3U)) + 5657023257021528548U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterF = (aWandererH + RotL64(aIngress, 53U)) + 14338310943137497116U;
            aOrbiterK = ((aWandererB + RotL64(aScatter, 35U)) + RotL64(aCarry, 3U)) + 12305161641833950473U;
            aOrbiterJ = ((aWandererC + RotL64(aCross, 14U)) + 14514226578370459131U) + aPhaseFOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = (aWandererE + RotL64(aPrevious, 27U)) + 12692904083266024340U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 11012959130001327964U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 7106471380403489078U;
            aOrbiterH = RotL64((aOrbiterH * 515626559384817223U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 3718101961355280891U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 13364192077222322664U;
            aOrbiterI = RotL64((aOrbiterI * 1411328915372590283U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 6720867800318913440U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 14497243926965866546U;
            aOrbiterD = RotL64((aOrbiterD * 13595058589060114653U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 5789056168233262435U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 14438482587495779937U;
            aOrbiterF = RotL64((aOrbiterF * 10593535547917767263U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 313917798940179945U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 15241845511889502917U;
            aOrbiterE = RotL64((aOrbiterE * 16483477103771326107U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 3591957424821693032U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 1559050939014453558U;
            aOrbiterJ = RotL64((aOrbiterJ * 17933346117866604725U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 15340590914441451383U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 5538037287390050110U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4082576643144951473U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 4151270491894969214U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 263593701314144898U;
            aOrbiterC = RotL64((aOrbiterC * 10372046955804512457U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 9025145270653080646U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 6867950904094870056U;
            aOrbiterK = RotL64((aOrbiterK * 9975247022340627751U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 3183454301841252109U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 3054904157641290615U;
            aOrbiterG = RotL64((aOrbiterG * 4092317552439599475U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 1768555574434776135U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 5568146815535263910U;
            aOrbiterB = RotL64((aOrbiterB * 12466957001078663927U), 3U);
            //
            aIngress = RotL64(aOrbiterH, 3U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterD, 23U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 43U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 58U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 53U));
            aIngress = aIngress + RotL64(aOrbiterG, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 10U) + RotL64(aOrbiterC, 41U)) + aOrbiterG);
            aWandererE = aWandererE + ((RotL64(aScatter, 19U) + RotL64(aOrbiterJ, 39U)) + aOrbiterG);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 43U) + aOrbiterG) + RotL64(aOrbiterF, 51U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterI, 30U)) + aOrbiterG);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 37U) + aOrbiterJ) + RotL64(aOrbiterI, 37U));
            aWandererG = aWandererG + (((RotL64(aIngress, 35U) + RotL64(aOrbiterC, 19U)) + aOrbiterH) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 24U) + aOrbiterG) + RotL64(aOrbiterB, 23U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 57U) + RotL64(aOrbiterG, 43U)) + aOrbiterA) + RotL64(aCarry, 29U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 21U) + aOrbiterK) + RotL64(aOrbiterG, 60U));
            aWandererH = aWandererH + (((RotL64(aScatter, 5U) + aOrbiterC) + RotL64(aOrbiterD, 35U)) + RotL64(aCarry, 13U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterC, 47U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 26U));
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererE);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 37U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 56U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 4
        // ingress from: aWorkLaneA, aSnowLaneA, aInvestLaneC
        // ingress directions: aWorkLaneA forward forced, aSnowLaneA forward forced, aInvestLaneC forward/backward random
        // cross from: aSnowLaneB, aOperationLaneD
        // cross directions: aSnowLaneB backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 16460U)) & S_BLOCK1], 26U) ^ RotL64(aSnowLaneA[((aIndex + 16894U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aInvestLaneC[((aIndex + 20638U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 19883U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 21440U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 4U) ^ RotL64(aPrevious, 51U)) ^ (RotL64(aCross, 39U) + RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = (aWandererC + RotL64(aPrevious, 11U)) + 3248574644570178787U;
            aOrbiterG = (aWandererH + RotL64(aScatter, 41U)) + 4506961512959200024U;
            aOrbiterH = ((aWandererK + RotL64(aCross, 46U)) + 8423739774540738590U) + aPhaseFOrbiterAssignSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = (aWandererA + RotL64(aIngress, 21U)) + 6593975869641735337U;
            aOrbiterA = (aWandererJ + RotL64(aCross, 43U)) + 16441716090557369103U;
            aOrbiterK = ((aWandererI + RotL64(aScatter, 5U)) + RotL64(aCarry, 23U)) + 7936601450453207914U;
            aOrbiterE = (aWandererE + RotL64(aPrevious, 14U)) + 13333752583560167065U;
            aOrbiterF = ((aWandererG + RotL64(aIngress, 35U)) + 8013703284795432973U) + aPhaseFOrbiterAssignSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterJ = ((aWandererB + RotL64(aCross, 53U)) + RotL64(aCarry, 13U)) + 2349852779887439236U;
            aOrbiterC = (aWandererF + RotL64(aScatter, 51U)) + 5318539364763284138U;
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 27U)) + RotL64(aCarry, 5U)) + 11450957608502944376U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 9058992558327552687U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 632095686920230926U;
            aOrbiterH = RotL64((aOrbiterH * 12460364388358520799U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 14734218428913777098U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 16344357661370784442U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15049472842002138369U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 2981145363531184308U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 14176472085175714494U;
            aOrbiterF = RotL64((aOrbiterF * 2584623327412130939U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 11198457590069700889U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 952584436750426828U;
            aOrbiterI = RotL64((aOrbiterI * 1165713888651280355U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 4311591763498985972U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 16194341833989936369U;
            aOrbiterC = RotL64((aOrbiterC * 9997934560195932575U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 7560794022401107431U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 10683789740265711603U;
            aOrbiterK = RotL64((aOrbiterK * 15637823045351977883U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 11614366395125937178U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 10750771385100564416U;
            aOrbiterB = RotL64((aOrbiterB * 4987921274272444283U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 2934697034132204529U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 4646873794658020363U;
            aOrbiterG = RotL64((aOrbiterG * 10555456865641580175U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 7913681837683568905U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 17603563535330106340U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17882943067522319671U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 15375641415139193079U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 17059712718085411887U;
            aOrbiterD = RotL64((aOrbiterD * 13722089235751208215U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 14022558453716067200U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 3248574644570178787U;
            aOrbiterJ = RotL64((aOrbiterJ * 15249135451439374621U), 35U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterC, 4U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 39U));
            aIngress = aIngress + (RotL64(aOrbiterK, 43U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 41U));
            aIngress = aIngress + (RotL64(aOrbiterF, 21U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterH, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterA, 51U)) + aOrbiterJ);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 28U) + RotL64(aOrbiterG, 29U)) + aOrbiterA);
            aWandererD = aWandererD + (((RotL64(aCross, 43U) + RotL64(aOrbiterD, 39U)) + aOrbiterF) + RotL64(aCarry, 53U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 3U) + aOrbiterJ) + RotL64(aOrbiterH, 19U));
            aWandererB = aWandererB + ((((RotL64(aPrevious, 11U) + aOrbiterD) + RotL64(aOrbiterC, 36U)) + RotL64(aCarry, 23U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 30U) + aOrbiterD) + RotL64(aOrbiterB, 13U)) + aPhaseFWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aCross, 57U) + aOrbiterH) + RotL64(aOrbiterE, 21U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterB, 27U)) + aOrbiterF);
            aWandererH = aWandererH + ((RotL64(aCross, 19U) + aOrbiterB) + RotL64(aOrbiterK, 10U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 47U) + aOrbiterE) + RotL64(aOrbiterK, 43U));
            aWandererI = aWandererI + ((RotL64(aScatter, 21U) + RotL64(aOrbiterH, 23U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 56U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 21U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 30U));
            aCarry = aCarry + RotL64(aWandererD, 47U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_c loop 5
        // ingress from: aWorkLaneB, aSnowLaneB, aExpandLaneB
        // ingress directions: aWorkLaneB forward forced, aSnowLaneB forward forced, aExpandLaneB forward/backward random
        // cross from: aWorkLaneA, aSnowLaneA
        // cross directions: aWorkLaneA backward forced, aSnowLaneA backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 24105U)) & S_BLOCK1], 29U) ^ RotL64(aSnowLaneB[((aIndex + 27268U)) & S_BLOCK1], 40U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27102U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24825U)) & S_BLOCK1], 19U) ^ RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 26973U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 6U) + RotL64(aPrevious, 57U)) ^ (RotL64(aCarry, 21U) ^ RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 29U)) + 3973833383430652211U) + aPhaseFOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = (aWandererD + RotL64(aPrevious, 14U)) + 5760227042747169187U;
            aOrbiterK = ((aWandererE + RotL64(aIngress, 37U)) + RotL64(aCarry, 19U)) + 4923009065139227286U;
            aOrbiterD = ((aWandererI + RotL64(aCross, 51U)) + RotL64(aCarry, 27U)) + 1477807307009107590U;
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 3U)) + RotL64(aCarry, 43U)) + 5707194514329007301U;
            aOrbiterI = (aWandererH + RotL64(aIngress, 19U)) + 5340439728375269724U;
            aOrbiterC = (aWandererK + RotL64(aScatter, 53U)) + 17080457898946572387U;
            aOrbiterA = (aWandererF + RotL64(aCross, 34U)) + 281559150259472813U;
            aOrbiterJ = (aWandererA + RotL64(aPrevious, 27U)) + 16160633048230910560U;
            aOrbiterB = ((aWandererC + RotL64(aScatter, 5U)) + 9003989610509592121U) + aPhaseFOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = (aWandererG + RotL64(aCross, 47U)) + 10579322462808454333U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 15059383289528723069U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 10417647757852880956U;
            aOrbiterK = RotL64((aOrbiterK * 1457919230286043137U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 14484665027393813330U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 12344463053485837974U;
            aOrbiterE = RotL64((aOrbiterE * 5762654194001525041U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 5826453246659297805U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 12547902286376986223U;
            aOrbiterA = RotL64((aOrbiterA * 2982850000322672789U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 9637855144278126174U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 2132744427444501938U;
            aOrbiterJ = RotL64((aOrbiterJ * 5911587798564836199U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 9248933938130311231U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 13274297928717090383U;
            aOrbiterG = RotL64((aOrbiterG * 2901398809555237563U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 3690262236918560930U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 3626005326410800344U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13030443356669355355U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 10801089744186148218U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 5446653082176311031U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4594267575901248321U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 3205541585889107366U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 4532327942368884436U;
            aOrbiterF = RotL64((aOrbiterF * 16287094987689326229U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 9755333481079721632U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 722154154363571049U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11002432494248958957U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 8071668483354405205U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 8770466248803121315U;
            aOrbiterI = RotL64((aOrbiterI * 12780438190628717807U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 1999251593502332271U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 3973833383430652211U;
            aOrbiterB = RotL64((aOrbiterB * 5325244982474631559U), 23U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterF, 53U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 28U));
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 13U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 19U));
            aIngress = aIngress + RotL64(aOrbiterE, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 23U) + aOrbiterE) + RotL64(aOrbiterB, 41U));
            aWandererF = aWandererF + ((RotL64(aIngress, 57U) + RotL64(aOrbiterC, 39U)) + aOrbiterE);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterF, 19U)) + aOrbiterB);
            aWandererI = aWandererI + (((RotL64(aScatter, 34U) + aOrbiterE) + RotL64(aOrbiterD, 4U)) + RotL64(aCarry, 29U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 53U) + aOrbiterC) + RotL64(aOrbiterI, 43U));
            aWandererG = aWandererG + ((RotL64(aScatter, 13U) + aOrbiterK) + RotL64(aOrbiterI, 13U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterH, 11U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aIngress, 5U) + RotL64(aOrbiterB, 29U)) + aOrbiterA);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 26U) + RotL64(aOrbiterG, 47U)) + aOrbiterK);
            aWandererH = aWandererH + ((((RotL64(aIngress, 11U) + aOrbiterH) + RotL64(aOrbiterF, 22U)) + RotL64(aCarry, 19U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 21U) + aOrbiterF) + RotL64(aOrbiterK, 37U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 46U));
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererK);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 37U));
            aCarry = aCarry + (RotL64(aWandererB, 21U) ^ aWandererI);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 34U));
            aCarry = aCarry + RotL64(aWandererG, 11U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 29185U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneA[((aIndex + 27649U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 31675U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30062U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneB[((aIndex + 29465U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCross, 24U)) + (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = ((aWandererD + RotL64(aScatter, 21U)) + RotL64(aCarry, 23U)) + 4970414922752555648U;
            aOrbiterJ = (aWandererC + RotL64(aIngress, 13U)) + 9462756592787669327U;
            aOrbiterH = (aWandererK + RotL64(aPrevious, 37U)) + 3948790686662213095U;
            aOrbiterG = (aWandererA + RotL64(aCross, 60U)) + 14542857212241578311U;
            aOrbiterE = ((aWandererE + RotL64(aIngress, 29U)) + RotL64(aCarry, 11U)) + 3387479009827029547U;
            aOrbiterD = (aWandererH + RotL64(aPrevious, 11U)) + 1411421370057797877U;
            aOrbiterC = (aWandererF + RotL64(aScatter, 19U)) + 16894451466895681236U;
            aOrbiterI = (((aWandererG + RotL64(aCross, 53U)) + RotL64(aCarry, 57U)) + 12727136462290223542U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = (aWandererI + RotL64(aScatter, 3U)) + 4625389198191960525U;
            aOrbiterA = ((aWandererJ + RotL64(aCross, 47U)) + 3471881403786164913U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = (aWandererB + RotL64(aPrevious, 40U)) + 6433115856048534831U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 9825592965466157982U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 1553125767261293088U;
            aOrbiterH = RotL64((aOrbiterH * 411535191177308781U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 9951616357109647617U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 11231080382787286889U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14024961994986659187U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 13419663264017317947U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 4835055642466215566U;
            aOrbiterJ = RotL64((aOrbiterJ * 17898065852351759171U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 14558747666410946768U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 13120938960926874504U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5681766019285559739U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 11910501376797343986U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 15074100100781785300U;
            aOrbiterG = RotL64((aOrbiterG * 228976960937473851U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 12415377930578091821U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 14882039078390681802U;
            aOrbiterA = RotL64((aOrbiterA * 13855446647753150713U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 8094338361713756895U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 5478280604704108822U;
            aOrbiterI = RotL64((aOrbiterI * 18062931724700600993U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 6977017654546871841U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 4131602217285988962U;
            aOrbiterD = RotL64((aOrbiterD * 11865422227883712419U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 9619228479582032318U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 13506679497441415586U;
            aOrbiterB = RotL64((aOrbiterB * 5789932662418992799U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 10180259475831448124U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 4721628773773094283U;
            aOrbiterC = RotL64((aOrbiterC * 10834196399754443771U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 7898137727558813688U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 4970414922752555648U;
            aOrbiterK = RotL64((aOrbiterK * 6651835668618579479U), 39U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterF, 36U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + (RotL64(aOrbiterE, 21U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterG, 11U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterJ, 4U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterA, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterE, 13U)) + aOrbiterI);
            aWandererK = aWandererK + (((RotL64(aPrevious, 34U) + RotL64(aOrbiterI, 6U)) + aOrbiterF) + RotL64(aCarry, 19U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterD, 57U)) + aOrbiterG);
            aWandererI = aWandererI + ((RotL64(aScatter, 19U) + RotL64(aOrbiterG, 41U)) + aOrbiterC);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterI, 47U)) + aOrbiterB);
            aWandererF = aWandererF + ((RotL64(aCross, 41U) + aOrbiterD) + RotL64(aOrbiterH, 3U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterE, 35U)) + aOrbiterK);
            aWandererH = aWandererH + ((RotL64(aPrevious, 57U) + aOrbiterJ) + RotL64(aOrbiterI, 39U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterJ, 27U)) + aOrbiterD) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aScatter, 23U) + RotL64(aOrbiterJ, 19U)) + aOrbiterB) + RotL64(aCarry, 43U)) + aPhaseFWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 54U) + aOrbiterJ) + RotL64(aOrbiterA, 54U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + (RotL64(aWandererJ, 56U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererH, 39U) ^ aWandererE);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + RotL64(aWandererA, 12U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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

void TwistExpander_WaterPolo_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterF = 0;
    std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0;
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 4294U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneB[((aIndex + 3336U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 1877U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 6829U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 1147U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 5056U)) & S_BLOCK1], 40U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCarry, 36U)) ^ (RotL64(aCross, 5U) ^ RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 39U)) + 16124889768301047791U) + aPhaseGOrbiterAssignSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterF = ((aWandererC + RotL64(aCross, 53U)) + RotL64(aCarry, 23U)) + 11912338587186717280U;
            aOrbiterJ = (aWandererJ + RotL64(aScatter, 3U)) + 8594012868813114354U;
            aOrbiterA = ((aWandererG + RotL64(aIngress, 21U)) + RotL64(aCarry, 5U)) + 18281043566156682815U;
            aOrbiterH = (((aWandererH + RotL64(aPrevious, 12U)) + RotL64(aCarry, 35U)) + 16853106130200942302U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 2611212958619673086U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 18039472325066855180U;
            aOrbiterJ = RotL64((aOrbiterJ * 10213999643376367785U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 14495785571345122046U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 4556063793412832418U;
            aOrbiterH = RotL64((aOrbiterH * 13166927543135467627U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 14896419970271244358U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 880028529183500036U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14228281807461251361U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 2379557167489415783U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 11854373946064529806U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 150755294320438887U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 1487252775956449964U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 12777924204511625545U;
            aOrbiterA = RotL64((aOrbiterA * 1366019527386994789U), 3U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterH, 19U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 29U));
            aIngress = aIngress + RotL64(aOrbiterA, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterI, 39U)) + aOrbiterJ);
            aWandererH = aWandererH + (((RotL64(aIngress, 60U) + RotL64(aOrbiterH, 14U)) + aOrbiterF) + RotL64(aCarry, 21U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterH, 29U)) + aOrbiterJ);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterI, 5U)) + aOrbiterA) + RotL64(aCarry, 51U)) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterH, 47U)) + aOrbiterI) + aPhaseGWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 48U));
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererJ, 3U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 10413U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((aIndex + 10095U)) & S_BLOCK1], 18U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 14814U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 9014U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 15088U)) & S_BLOCK1], 12U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 10644U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 35U)) ^ (RotL64(aIngress, 18U) + RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = ((aWandererH + RotL64(aIngress, 51U)) + RotL64(aCarry, 29U)) + 12775735908960052604U;
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 41U)) + RotL64(aCarry, 11U)) + 11791373812080296887U;
            aOrbiterJ = (aWandererC + RotL64(aScatter, 18U)) + 5537362877706057303U;
            aOrbiterH = (((aWandererG + RotL64(aCross, 29U)) + RotL64(aCarry, 43U)) + 2023912048504189380U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = ((aWandererB + RotL64(aIngress, 5U)) + 17668828109963766893U) + aPhaseGOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 558908629933941224U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 1479633119685446888U;
            aOrbiterJ = RotL64((aOrbiterJ * 4447153373540811385U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 15460320397843364063U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 10059749397555469054U;
            aOrbiterB = RotL64((aOrbiterB * 8671817118586065469U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 9987633811929693924U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 10087337844580228269U;
            aOrbiterK = RotL64((aOrbiterK * 13817142288940843815U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 4446204415503364254U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 15106063243302192717U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13273756657334709803U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 9430197906134676162U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 1226048679997253363U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14247538885252664127U), 57U);
            //
            aIngress = RotL64(aOrbiterB, 21U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterH, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 60U) + aOrbiterK) + RotL64(aOrbiterB, 13U)) + aPhaseGWandererUpdateSaltD[((aIndex + 18U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aScatter, 29U) + aOrbiterH) + RotL64(aOrbiterF, 48U)) + RotL64(aCarry, 29U)) + aPhaseGWandererUpdateSaltE[((aIndex + 22U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterJ, 57U)) + aOrbiterB);
            aWandererC = aWandererC + (((RotL64(aIngress, 13U) + RotL64(aOrbiterF, 21U)) + aOrbiterJ) + RotL64(aCarry, 43U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 47U) + aOrbiterF) + RotL64(aOrbiterK, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 39U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererC, 12U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererB, 3U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 17256U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneA[((aIndex + 18393U)) & S_BLOCK1], 24U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 19861U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24224U)) & S_BLOCK1], 30U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 16916U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aWorkLaneC[((aIndex + 23335U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 35U) ^ RotL64(aPrevious, 11U)) ^ (RotL64(aIngress, 48U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = (((aWandererB + RotL64(aPrevious, 5U)) + RotL64(aCarry, 5U)) + 14008824488073394623U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = (aWandererC + RotL64(aScatter, 41U)) + 13317978415866411468U;
            aOrbiterG = (((aWandererH + RotL64(aIngress, 28U)) + RotL64(aCarry, 51U)) + 13209180141897453900U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = ((aWandererI + RotL64(aCross, 13U)) + RotL64(aCarry, 39U)) + 11870521586865233578U;
            aOrbiterI = (aWandererJ + RotL64(aScatter, 57U)) + 8052156380448047385U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 12158131176743680605U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 14674467487607719347U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 18372548574199176503U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 18055496790566231147U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 3838105585041578784U;
            aOrbiterB = RotL64((aOrbiterB * 1075709247574580091U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 2839568255183054418U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 11933612922864258179U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7571964469321160347U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 6289849094151630580U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 2640344350528492271U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16197726750829369365U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 16306175266267657791U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 3339898380394883600U;
            aOrbiterI = RotL64((aOrbiterI * 7105436590182982373U), 23U);
            //
            aIngress = RotL64(aOrbiterF, 53U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterB, 18U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterI, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterG, 29U)) + aOrbiterF) + aPhaseGWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 3U) + aOrbiterI) + RotL64(aOrbiterB, 13U)) + RotL64(aCarry, 47U)) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 11U) + aOrbiterA) + RotL64(aOrbiterI, 47U));
            aWandererB = aWandererB + (((RotL64(aIngress, 40U) + RotL64(aOrbiterG, 60U)) + aOrbiterB) + RotL64(aCarry, 21U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterF, 5U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 58U));
            aCarry = aCarry + RotL64(aWandererC, 11U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 29516U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneB[((aIndex + 24631U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aExpandLaneA[((aIndex + 26782U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29233U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29020U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 28321U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 24U) ^ RotL64(aCross, 3U)) ^ (RotL64(aCarry, 41U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = (((aWandererH + RotL64(aCross, 37U)) + RotL64(aCarry, 5U)) + 5295352595333316211U) + aPhaseGOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = (((aWandererI + RotL64(aIngress, 58U)) + RotL64(aCarry, 53U)) + 2341795367042042605U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 47U)) + 10122175780504033663U;
            aOrbiterD = ((aWandererA + RotL64(aScatter, 3U)) + RotL64(aCarry, 39U)) + 10084612804696198554U;
            aOrbiterB = (aWandererJ + RotL64(aPrevious, 23U)) + 16470424309851045971U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 656016130975227994U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 15313268829659834317U;
            aOrbiterJ = RotL64((aOrbiterJ * 3553315008401417123U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 3795220914993923394U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 14044442220988813825U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3270650852546606835U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 3804224626734584802U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 7980006306010255693U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13958505239726088561U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 13746830564584711549U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 11852212099729274845U;
            aOrbiterD = RotL64((aOrbiterD * 2164880979318247855U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 9083223471018084847U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 13706723820703853346U;
            aOrbiterB = RotL64((aOrbiterB * 11361854103656219887U), 47U);
            //
            aIngress = RotL64(aOrbiterD, 47U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterB, 36U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterG, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aPrevious, 13U) + aOrbiterJ) + RotL64(aOrbiterG, 29U)) + RotL64(aCarry, 3U)) + aPhaseGWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterJ, 4U)) + aOrbiterK);
            aWandererC = aWandererC + (((RotL64(aScatter, 50U) + RotL64(aOrbiterJ, 37U)) + aOrbiterB) + RotL64(aCarry, 51U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterG, 47U)) + aOrbiterK) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 5U) + aOrbiterB) + RotL64(aOrbiterD, 21U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 54U));
            aCarry = aCarry + RotL64(aWandererI, 13U);
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

void TwistExpander_WaterPolo_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 3656U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneB[((aIndex + 2064U)) & S_BLOCK1], 28U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 6760U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 5586U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3091U)) & S_BLOCK1], 20U));
            aCross ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 7469U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aPrevious, 36U)) + (RotL64(aCarry, 23U) + RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = (((aWandererD + RotL64(aCross, 27U)) + RotL64(aCarry, 57U)) + 15045917390223766480U) + aPhaseHOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 35U)) + RotL64(aCarry, 37U)) + 10763054007033668758U;
            aOrbiterD = (((aWandererH + RotL64(aIngress, 5U)) + RotL64(aCarry, 5U)) + 13190170142593666607U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = (aWandererK + RotL64(aScatter, 57U)) + 9657025731441167065U;
            aOrbiterF = (aWandererG + RotL64(aPrevious, 44U)) + 11433367178975954211U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 17904920143996810366U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 3244383020512113283U;
            aOrbiterD = RotL64((aOrbiterD * 552521443123433353U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 6538815775171139091U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 7195368312757976343U;
            aOrbiterF = RotL64((aOrbiterF * 10515679176134176565U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 18134430713910279374U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 6571776588427107976U;
            aOrbiterK = RotL64((aOrbiterK * 11916502085252589161U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 11830778129647517758U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 9793702760907767365U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4096246227968677179U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 2287235876793192036U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 8951959188326141794U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9968356718110753845U), 11U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterK, 30U);
            aIngress = aIngress + (RotL64(aOrbiterF, 41U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterE, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aScatter, 43U) + aOrbiterI) + RotL64(aOrbiterK, 51U)) + RotL64(aCarry, 57U)) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 11U) + aOrbiterD) + RotL64(aOrbiterK, 27U));
            aWandererK = aWandererK + (((RotL64(aIngress, 35U) + aOrbiterK) + RotL64(aOrbiterF, 35U)) + RotL64(aCarry, 11U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 60U) + RotL64(aOrbiterD, 10U)) + aOrbiterF) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aIngress, 19U) + RotL64(aOrbiterE, 19U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererD, 38U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 15767U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((aIndex + 10155U)) & S_BLOCK1], 22U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 11592U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9452U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 15289U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11380U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aIngress, 41U)) + (RotL64(aCross, 26U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = ((aWandererI + RotL64(aPrevious, 19U)) + 3973833383430652211U) + aPhaseHOrbiterAssignSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterJ = (((aWandererE + RotL64(aIngress, 57U)) + RotL64(aCarry, 35U)) + 5760227042747169187U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = ((aWandererG + RotL64(aScatter, 44U)) + RotL64(aCarry, 13U)) + 4923009065139227286U;
            aOrbiterC = (aWandererK + RotL64(aCross, 5U)) + 1477807307009107590U;
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 29U)) + RotL64(aCarry, 57U)) + 5707194514329007301U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 5340439728375269724U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 17080457898946572387U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17719588880215414933U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 281559150259472813U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 16160633048230910560U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16883442583309073785U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 9003989610509592121U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 10579322462808454333U;
            aOrbiterI = RotL64((aOrbiterI * 100832431598087235U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 15059383289528723069U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 10417647757852880956U;
            aOrbiterC = RotL64((aOrbiterC * 1457919230286043137U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 14484665027393813330U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 12344463053485837974U;
            aOrbiterJ = RotL64((aOrbiterJ * 5762654194001525041U), 5U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterE, 43U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 5U));
            aIngress = aIngress + RotL64(aOrbiterI, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aScatter, 27U) + aOrbiterE) + RotL64(aOrbiterJ, 38U)) + RotL64(aCarry, 35U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 47U) + aOrbiterC) + RotL64(aOrbiterJ, 3U));
            aWandererE = aWandererE + (((RotL64(aIngress, 5U) + aOrbiterA) + RotL64(aOrbiterJ, 29U)) + RotL64(aCarry, 51U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 35U) + aOrbiterA) + RotL64(aOrbiterI, 53U)) + aPhaseHWandererUpdateSaltD[((aIndex + 6U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 56U) + RotL64(aOrbiterA, 11U)) + aOrbiterC) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 38U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 21U));
            aCarry = aCarry + RotL64(aWandererA, 29U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 19204U)) & S_BLOCK1], 34U) ^ RotL64(aWorkLaneA[((aIndex + 21453U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aExpandLaneD[((aIndex + 19332U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19033U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19234U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 21265U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 11U) ^ RotL64(aCross, 23U)) + (RotL64(aPrevious, 40U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = ((aWandererC + RotL64(aCross, 43U)) + 3199575576585871314U) + aPhaseHOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = (((aWandererA + RotL64(aPrevious, 5U)) + RotL64(aCarry, 13U)) + 2533378188975571824U) + aPhaseHOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = (aWandererK + RotL64(aIngress, 57U)) + 6819782112558312658U;
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 29U)) + RotL64(aCarry, 37U)) + 12690060987724798497U;
            aOrbiterD = ((aWandererG + RotL64(aIngress, 18U)) + RotL64(aCarry, 57U)) + 7088375139715629606U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 17785618677423695666U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 1714999280296491277U;
            aOrbiterH = RotL64((aOrbiterH * 7675674437417383741U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 17611338506932491624U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 6475727359297421201U;
            aOrbiterJ = RotL64((aOrbiterJ * 15133348244242438069U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 2347744591204119530U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 2739317903351401068U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15435029315209475631U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 8663535261373274338U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 8205245127823536479U;
            aOrbiterA = RotL64((aOrbiterA * 13857005110466856439U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 8916510616749754516U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 3944805940148512932U;
            aOrbiterG = RotL64((aOrbiterG * 18082271583211389701U), 39U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterA, 19U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 4U));
            aIngress = aIngress + RotL64(aOrbiterJ, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 19U) + aOrbiterD) + RotL64(aOrbiterJ, 19U));
            aWandererI = aWandererI + ((((RotL64(aScatter, 53U) + aOrbiterG) + RotL64(aOrbiterD, 5U)) + RotL64(aCarry, 21U)) + aPhaseHWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 41U) + aOrbiterA) + RotL64(aOrbiterG, 27U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 27U) + aOrbiterH) + RotL64(aOrbiterA, 46U)) + RotL64(aCarry, 51U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 6U) + aOrbiterD) + RotL64(aOrbiterA, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + RotL64(aWandererK, 21U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 29619U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((aIndex + 28129U)) & S_BLOCK1], 40U));
            aIngress ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27914U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 31720U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28483U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aWorkLaneC[((aIndex + 28911U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 34U) + RotL64(aCarry, 21U)) + (RotL64(aIngress, 3U) ^ RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = ((aWandererC + RotL64(aIngress, 27U)) + 5041131702736607991U) + aPhaseHOrbiterAssignSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 57U)) + 9295010428212681446U) + aPhaseHOrbiterAssignSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = ((aWandererE + RotL64(aScatter, 14U)) + RotL64(aCarry, 21U)) + 6235875895358766017U;
            aOrbiterC = ((aWandererH + RotL64(aCross, 43U)) + RotL64(aCarry, 47U)) + 2622227802531866918U;
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 5U)) + RotL64(aCarry, 35U)) + 3888894734834524972U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 241682012014701753U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 15758000422451568079U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14719166949665416221U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 2061944548396976912U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 8177144990755754531U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12702392689484397947U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 554978075608818497U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 250408260560714933U;
            aOrbiterF = RotL64((aOrbiterF * 1295379390497107727U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 8700027645880997552U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 10026130047465480902U;
            aOrbiterK = RotL64((aOrbiterK * 12417270861933696623U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 9785843014096326696U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 9998582683258411251U;
            aOrbiterC = RotL64((aOrbiterC * 7197956237569462269U), 47U);
            //
            aIngress = RotL64(aOrbiterE, 4U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 29U));
            aIngress = aIngress + RotL64(aOrbiterG, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 5U) + aOrbiterG) + RotL64(aOrbiterE, 29U));
            aWandererC = aWandererC + (((RotL64(aIngress, 39U) + aOrbiterF) + RotL64(aOrbiterE, 3U)) + RotL64(aCarry, 5U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 27U) + aOrbiterK) + RotL64(aOrbiterF, 57U));
            aWandererG = aWandererG + ((((RotL64(aPrevious, 19U) + aOrbiterC) + RotL64(aOrbiterE, 46U)) + RotL64(aCarry, 23U)) + aPhaseHWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 50U) + aOrbiterC) + RotL64(aOrbiterG, 11U)) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 38U));
            aCarry = aCarry + (RotL64(aWandererH, 27U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererG, 3U);
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
